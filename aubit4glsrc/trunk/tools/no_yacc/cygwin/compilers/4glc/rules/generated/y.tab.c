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
     NAME = 1655,
     UMINUS = 1656,
     COMMA = 1569,
     KW_OR = 1609,
     KW_AND = 1564,
     KW_USING = 1500,
     NOT = 1584,
     MATCHES = 1379,
     POWER = 1486,
     LESS_THAN = 1482,
     GREATER_THAN = 1397,
     EQUAL = 1559,
     GREATER_THAN_EQ = 1296,
     LESS_THAN_EQ = 1354,
     NOT_EQUAL = 1428,
     PLUS = 1595,
     MINUS = 1582,
     MULTIPLY = 1487,
     DIVIDE = 1515,
     MOD = 1583,
     COMMAND = 1361,
     NUMBER_VALUE = 1657,
     CHAR_VALUE = 1658,
     INT_VALUE = 1659,
     NAMED_GEN = 1660,
     CLINE = 1661,
     SQLLINE = 1662,
     KW_CSTART = 1663,
     KW_CEND = 1664,
     USER_DTYPE = 1665,
     SQL_TEXT = 1666,
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
     RETURN = 1143,
     SET_SESSION_TO = 1144,
     UPDATESTATS = 1145,
     WITHOUT_HEAD = 1146,
     CLEARSCR = 1147,
     WITH_B_LOG = 1148,
     AUTHORIZATION = 1149,
     BOTTOM_MARGIN = 1150,
     CLOSE_SESSION = 1151,
     CONTINUE_CASE = 1152,
     CONTINUE_MENU = 1153,
     DISPLAY_ARRAY = 1154,
     END_SQL = 1155,
     DOLLAR = 1156,
     END_CONSTRUCT = 1157,
     FIELD_TOUCHED = 1158,
     FINISH_REPORT = 1159,
     INFACC = 1160,
     INPUT_NO_WRAP = 1161,
     LOCKMODEPAGE = 1162,
     SETPMOFF = 1163,
     UNCONSTRAINED = 1164,
     PAGE_TRAILER = 1165,
     SETPMON = 1166,
     BEFGROUP = 1167,
     CLOSE_WINDOW = 1168,
     COMMENT_LINE = 1169,
     CONTINUE_FOR = 1170,
     CREATE_DB = 1171,
     CREATE_TABLE = 1172,
     DEFAULT_NULL = 1173,
     DELETE_USING = 1174,
     DISPLAY_FORM = 1175,
     END_FUNCTION = 1176,
     EXIT_DISPLAY = 1177,
     EXIT_FOREACH = 1178,
     EXIT_PROGRAM = 1179,
     INFCOLS = 1180,
     LOCKMODEROW = 1181,
     ON_EVERY_ROW = 1182,
     OPEN_SESSION = 1183,
     RIGHT_MARGIN = 1184,
     SELECT_USING = 1185,
     START_REPORT = 1186,
     UNLOCK_TABLE = 1187,
     UPDATE_USING = 1188,
     ACL_BUILTIN = 1189,
     AFTGROUP = 1190,
     INFIDX = 1191,
     INFSTAT = 1192,
     LEFT_MARGIN = 1193,
     PAGE_HEADER = 1194,
     ROLLBACK_W = 1195,
     SET_SESSION = 1196,
     SQLSEOFF = 1197,
     WITH_A_LOG = 1198,
     BEFDISP = 1199,
     BEFORE_MENU = 1200,
     CREATE_VIEW = 1201,
     DEFINE_TYPE = 1202,
     DELETE_FROM = 1203,
     END_DISPLAY = 1204,
     END_REPORT = 1205,
     END_FOREACH = 1206,
     END_FOR = 1207,
     END_GLOBALS = 1208,
     EXIT_PROMPT = 1209,
     EXTENT_SIZE = 1210,
     FOREIGN_KEY = 1211,
     HIDE_OPTION = 1212,
     HIDE_WINDOW = 1213,
     INSERT_INTO = 1214,
     IS_NOT_NULL = 1215,
     MOVE_WINDOW = 1216,
     NEXT_OPTION = 1217,
     NOT_MATCHES = 1218,
     ON_LAST_ROW = 1219,
     OPEN_WINDOW = 1220,
     OPEN_STATUSBOX = 1221,
     PAGE_LENGTH = 1222,
     PAGE_WIDTH = 1223,
     PRIMARY_KEY = 1224,
     PROMPT_LINE = 1225,
     RECORD_LIKE = 1226,
     ROLLFORWARD = 1227,
     SETBL = 1228,
     SHOW_OPTION = 1229,
     SHOW_WINDOW = 1230,
     SQLSEON = 1231,
     TO_DATABASE = 1232,
     USE_SESSION = 1233,
     WITH_NO_LOG = 1234,
     AFTDISP = 1235,
     BEFFIELD = 1236,
     INSHARE = 1237,
     UNLOCKTAB = 1238,
     AFTFIELD = 1239,
     ATTRIBUTES = 1240,
     BEFINP = 1241,
     BEGIN_WORK = 1242,
     CLEARWIN = 1243,
     CLOSE_FORM = 1244,
     DEFER_QUIT = 1245,
     DESCENDING = 1246,
     DROP_INDEX = 1247,
     END_PROMPT = 1248,
     END_RECORD = 1249,
     ERROR_LINE = 1250,
     EXIT_INPUT = 1251,
     EXIT_WHILE = 1252,
     FOR_UPDATE_OF = 1253,
     FOR_UPDATE = 1254,
     GET_FLDBUF = 1255,
     INITIALIZE = 1256,
     INPUT_WRAP = 1257,
     LOCK_TABLE = 1258,
     MSG_LINE = 1259,
     NOT_EXISTS = 1260,
     ON_ANY_KEY = 1261,
     REFERENCES = 1262,
     RENCOL = 1263,
     SET_CURSOR = 1264,
     SMALLFLOAT = 1265,
     SQLSUCCESS = 1266,
     TOP_MARGIN = 1267,
     WITH_ARRAY = 1268,
     ACCEPTKEY = 1269,
     ACCEPT = 1270,
     AFTINP = 1271,
     CLEARFORMTODEFAULTS = 1272,
     CLEARFORM = 1273,
     CLEAR_X_FORM = 1274,
     COMMIT_W = 1275,
     NEXTPAGE = 1276,
     PREVPAGE = 1277,
     CTRL_KEY = 1278,
     INFTABS = 1279,
     NEXTFIELD = 1280,
     NEXTFORM = 1281,
     RENTAB = 1282,
     ASCENDING = 1283,
     ASSOCIATE = 1284,
     CHARACTER = 1285,
     CONSTRUCT = 1286,
     DELIMITER = 1287,
     DOWNSHIFT = 1288,
     DROP_VIEW = 1289,
     END_INPUT = 1290,
     END_WHILE = 1291,
     EXCLUSIVE = 1292,
     EXIT_CASE = 1293,
     EXIT_MENU = 1294,
     FORM_LINE = 1295,
     INTERRUPT = 1297,
     INTO_TEMP = 1298,
     INVISIBLE = 1299,
     IN_MEMORY = 1300,
     LINKED_TO = 1301,
     LOAD_FROM = 1302,
     LOCKTAB = 1303,
     MENU_LINE = 1304,
     OPEN_FORM = 1305,
     OTHERWISE = 1306,
     PRECISION = 1307,
     PRIOR = 1308,
     PROCEDURE = 1309,
     REPORT_TO = 1310,
     RETURNING = 1311,
     UNDERLINE = 1312,
     UNLOAD_TO = 1313,
     BEFROW = 1314,
     UNLOAD_T = 1315,
     VARIABLE = 1316,
     ABSOLUTE = 1317,
     AFTROW = 1318,
     BUFFERED = 1319,
     CONSTANT = 1320,
     CONST = 1321,
     CONTINUE = 1322,
     DATABASE = 1323,
     DATETIME = 1324,
     DEFAULTS = 1325,
     DISTINCT = 1326,
     END_CASE = 1327,
     END_MAIN = 1328,
     END_MENU = 1329,
     END_TYPE = 1330,
     EXIT_FOR = 1331,
     EXTERNAL = 1332,
     FRACTION = 1333,
     FUNCTION = 1334,
     GROUP_BY = 1335,
     INTERVAL = 1336,
     KWMESSAGE = 1337,
     NOT_LIKE = 1338,
     NOT_NULL = 1339,
     PASSWORD = 1340,
     PREVIOUS = 1341,
     READONLY = 1342,
     REGISTER = 1343,
     RELATIVE = 1344,
     RESOURCE = 1345,
     SMALLINT = 1346,
     VALIDATE = 1347,
     WHENEVER = 1348,
     WITH_LOG = 1349,
     WORDWRAP = 1350,
     BY_NAME = 1351,
     IN_FILE = 1352,
     IS_NULL = 1353,
     AVERAGE = 1355,
     BETWEEN = 1356,
     CAPTION = 1357,
     CLIPPED = 1358,
     CLOSE_BRACKET = 1359,
     COLUMNS = 1360,
     COMMENT = 1362,
     CONNECT = 1363,
     CURRENT = 1364,
     DBYNAME = 1365,
     DECIMAL = 1366,
     DECLARE = 1367,
     DEFAULT = 1368,
     DISPLAY = 1369,
     ENDCODE = 1370,
     EXECUTE = 1371,
     FOREACH = 1372,
     FOREIGN = 1373,
     GLOBALS = 1374,
     INFIELD = 1375,
     INTEGER = 1376,
     KWWINDOW = 1377,
     MAGENTA = 1378,
     NUMERIC = 1380,
     OPTIONS = 1381,
     PERCENT = 1382,
     PREPARE = 1383,
     PROGRAM = 1384,
     RECOVER = 1385,
     REVERSE = 1386,
     SECTION = 1387,
     SESSION = 1388,
     SYNONYM = 1389,
     THRU = 1390,
     TRAILER = 1391,
     UPSHIFT = 1392,
     VARCHAR = 1393,
     WAITING = 1394,
     CLOSE_SHEV = 1395,
     CLOSE_SQUARE = 1396,
     KW_FALSE = 1398,
     NOT_IN = 1399,
     ONKEY = 1400,
     OPEN_BRACKET = 1401,
     BORDER = 1402,
     BOTTOM = 1403,
     COLUMN = 1404,
     COMMIT = 1405,
     CREATE = 1406,
     CURSOR = 1407,
     DEFINE = 1408,
     DELETE = 1409,
     DOUBLE = 1410,
     END_IF = 1411,
     ESCAPE = 1412,
     EXISTS = 1413,
     EXTEND = 1414,
     EXTENT = 1415,
     FINISH = 1416,
     FORMAT = 1417,
     HAVING = 1418,
     HEADER = 1419,
     INSERT = 1420,
     LOCATE = 1421,
     MARGIN = 1422,
     MEMORY = 1423,
     MINUTE = 1424,
     MODIFY = 1425,
     NORMAL = 1426,
     EQUAL_EQUAL = 1427,
     OPEN_SHEV = 1429,
     OPEN_SQUARE = 1430,
     OPTION = 1431,
     OUTPUT = 1432,
     PROMPT = 1433,
     PUBLIC = 1434,
     RECORD = 1435,
     REPORT = 1436,
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
     INT_TO_ID = 1651,
     TIMEOUT = 1652,
     OFF = 1653
   };
#endif
#define NAME 1655
#define UMINUS 1656
#define COMMA 1569
#define KW_OR 1609
#define KW_AND 1564
#define KW_USING 1500
#define NOT 1584
#define MATCHES 1379
#define POWER 1486
#define LESS_THAN 1482
#define GREATER_THAN 1397
#define EQUAL 1559
#define GREATER_THAN_EQ 1296
#define LESS_THAN_EQ 1354
#define NOT_EQUAL 1428
#define PLUS 1595
#define MINUS 1582
#define MULTIPLY 1487
#define DIVIDE 1515
#define MOD 1583
#define COMMAND 1361
#define NUMBER_VALUE 1657
#define CHAR_VALUE 1658
#define INT_VALUE 1659
#define NAMED_GEN 1660
#define CLINE 1661
#define SQLLINE 1662
#define KW_CSTART 1663
#define KW_CEND 1664
#define USER_DTYPE 1665
#define SQL_TEXT 1666
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
#define RETURN 1143
#define SET_SESSION_TO 1144
#define UPDATESTATS 1145
#define WITHOUT_HEAD 1146
#define CLEARSCR 1147
#define WITH_B_LOG 1148
#define AUTHORIZATION 1149
#define BOTTOM_MARGIN 1150
#define CLOSE_SESSION 1151
#define CONTINUE_CASE 1152
#define CONTINUE_MENU 1153
#define DISPLAY_ARRAY 1154
#define END_SQL 1155
#define DOLLAR 1156
#define END_CONSTRUCT 1157
#define FIELD_TOUCHED 1158
#define FINISH_REPORT 1159
#define INFACC 1160
#define INPUT_NO_WRAP 1161
#define LOCKMODEPAGE 1162
#define SETPMOFF 1163
#define UNCONSTRAINED 1164
#define PAGE_TRAILER 1165
#define SETPMON 1166
#define BEFGROUP 1167
#define CLOSE_WINDOW 1168
#define COMMENT_LINE 1169
#define CONTINUE_FOR 1170
#define CREATE_DB 1171
#define CREATE_TABLE 1172
#define DEFAULT_NULL 1173
#define DELETE_USING 1174
#define DISPLAY_FORM 1175
#define END_FUNCTION 1176
#define EXIT_DISPLAY 1177
#define EXIT_FOREACH 1178
#define EXIT_PROGRAM 1179
#define INFCOLS 1180
#define LOCKMODEROW 1181
#define ON_EVERY_ROW 1182
#define OPEN_SESSION 1183
#define RIGHT_MARGIN 1184
#define SELECT_USING 1185
#define START_REPORT 1186
#define UNLOCK_TABLE 1187
#define UPDATE_USING 1188
#define ACL_BUILTIN 1189
#define AFTGROUP 1190
#define INFIDX 1191
#define INFSTAT 1192
#define LEFT_MARGIN 1193
#define PAGE_HEADER 1194
#define ROLLBACK_W 1195
#define SET_SESSION 1196
#define SQLSEOFF 1197
#define WITH_A_LOG 1198
#define BEFDISP 1199
#define BEFORE_MENU 1200
#define CREATE_VIEW 1201
#define DEFINE_TYPE 1202
#define DELETE_FROM 1203
#define END_DISPLAY 1204
#define END_REPORT 1205
#define END_FOREACH 1206
#define END_FOR 1207
#define END_GLOBALS 1208
#define EXIT_PROMPT 1209
#define EXTENT_SIZE 1210
#define FOREIGN_KEY 1211
#define HIDE_OPTION 1212
#define HIDE_WINDOW 1213
#define INSERT_INTO 1214
#define IS_NOT_NULL 1215
#define MOVE_WINDOW 1216
#define NEXT_OPTION 1217
#define NOT_MATCHES 1218
#define ON_LAST_ROW 1219
#define OPEN_WINDOW 1220
#define OPEN_STATUSBOX 1221
#define PAGE_LENGTH 1222
#define PAGE_WIDTH 1223
#define PRIMARY_KEY 1224
#define PROMPT_LINE 1225
#define RECORD_LIKE 1226
#define ROLLFORWARD 1227
#define SETBL 1228
#define SHOW_OPTION 1229
#define SHOW_WINDOW 1230
#define SQLSEON 1231
#define TO_DATABASE 1232
#define USE_SESSION 1233
#define WITH_NO_LOG 1234
#define AFTDISP 1235
#define BEFFIELD 1236
#define INSHARE 1237
#define UNLOCKTAB 1238
#define AFTFIELD 1239
#define ATTRIBUTES 1240
#define BEFINP 1241
#define BEGIN_WORK 1242
#define CLEARWIN 1243
#define CLOSE_FORM 1244
#define DEFER_QUIT 1245
#define DESCENDING 1246
#define DROP_INDEX 1247
#define END_PROMPT 1248
#define END_RECORD 1249
#define ERROR_LINE 1250
#define EXIT_INPUT 1251
#define EXIT_WHILE 1252
#define FOR_UPDATE_OF 1253
#define FOR_UPDATE 1254
#define GET_FLDBUF 1255
#define INITIALIZE 1256
#define INPUT_WRAP 1257
#define LOCK_TABLE 1258
#define MSG_LINE 1259
#define NOT_EXISTS 1260
#define ON_ANY_KEY 1261
#define REFERENCES 1262
#define RENCOL 1263
#define SET_CURSOR 1264
#define SMALLFLOAT 1265
#define SQLSUCCESS 1266
#define TOP_MARGIN 1267
#define WITH_ARRAY 1268
#define ACCEPTKEY 1269
#define ACCEPT 1270
#define AFTINP 1271
#define CLEARFORMTODEFAULTS 1272
#define CLEARFORM 1273
#define CLEAR_X_FORM 1274
#define COMMIT_W 1275
#define NEXTPAGE 1276
#define PREVPAGE 1277
#define CTRL_KEY 1278
#define INFTABS 1279
#define NEXTFIELD 1280
#define NEXTFORM 1281
#define RENTAB 1282
#define ASCENDING 1283
#define ASSOCIATE 1284
#define CHARACTER 1285
#define CONSTRUCT 1286
#define DELIMITER 1287
#define DOWNSHIFT 1288
#define DROP_VIEW 1289
#define END_INPUT 1290
#define END_WHILE 1291
#define EXCLUSIVE 1292
#define EXIT_CASE 1293
#define EXIT_MENU 1294
#define FORM_LINE 1295
#define INTERRUPT 1297
#define INTO_TEMP 1298
#define INVISIBLE 1299
#define IN_MEMORY 1300
#define LINKED_TO 1301
#define LOAD_FROM 1302
#define LOCKTAB 1303
#define MENU_LINE 1304
#define OPEN_FORM 1305
#define OTHERWISE 1306
#define PRECISION 1307
#define PRIOR 1308
#define PROCEDURE 1309
#define REPORT_TO 1310
#define RETURNING 1311
#define UNDERLINE 1312
#define UNLOAD_TO 1313
#define BEFROW 1314
#define UNLOAD_T 1315
#define VARIABLE 1316
#define ABSOLUTE 1317
#define AFTROW 1318
#define BUFFERED 1319
#define CONSTANT 1320
#define CONST 1321
#define CONTINUE 1322
#define DATABASE 1323
#define DATETIME 1324
#define DEFAULTS 1325
#define DISTINCT 1326
#define END_CASE 1327
#define END_MAIN 1328
#define END_MENU 1329
#define END_TYPE 1330
#define EXIT_FOR 1331
#define EXTERNAL 1332
#define FRACTION 1333
#define FUNCTION 1334
#define GROUP_BY 1335
#define INTERVAL 1336
#define KWMESSAGE 1337
#define NOT_LIKE 1338
#define NOT_NULL 1339
#define PASSWORD 1340
#define PREVIOUS 1341
#define READONLY 1342
#define REGISTER 1343
#define RELATIVE 1344
#define RESOURCE 1345
#define SMALLINT 1346
#define VALIDATE 1347
#define WHENEVER 1348
#define WITH_LOG 1349
#define WORDWRAP 1350
#define BY_NAME 1351
#define IN_FILE 1352
#define IS_NULL 1353
#define AVERAGE 1355
#define BETWEEN 1356
#define CAPTION 1357
#define CLIPPED 1358
#define CLOSE_BRACKET 1359
#define COLUMNS 1360
#define COMMENT 1362
#define CONNECT 1363
#define CURRENT 1364
#define DBYNAME 1365
#define DECIMAL 1366
#define DECLARE 1367
#define DEFAULT 1368
#define DISPLAY 1369
#define ENDCODE 1370
#define EXECUTE 1371
#define FOREACH 1372
#define FOREIGN 1373
#define GLOBALS 1374
#define INFIELD 1375
#define INTEGER 1376
#define KWWINDOW 1377
#define MAGENTA 1378
#define NUMERIC 1380
#define OPTIONS 1381
#define PERCENT 1382
#define PREPARE 1383
#define PROGRAM 1384
#define RECOVER 1385
#define REVERSE 1386
#define SECTION 1387
#define SESSION 1388
#define SYNONYM 1389
#define THRU 1390
#define TRAILER 1391
#define UPSHIFT 1392
#define VARCHAR 1393
#define WAITING 1394
#define CLOSE_SHEV 1395
#define CLOSE_SQUARE 1396
#define KW_FALSE 1398
#define NOT_IN 1399
#define ONKEY 1400
#define OPEN_BRACKET 1401
#define BORDER 1402
#define BOTTOM 1403
#define COLUMN 1404
#define COMMIT 1405
#define CREATE 1406
#define CURSOR 1407
#define DEFINE 1408
#define DELETE 1409
#define DOUBLE 1410
#define END_IF 1411
#define ESCAPE 1412
#define EXISTS 1413
#define EXTEND 1414
#define EXTENT 1415
#define FINISH 1416
#define FORMAT 1417
#define HAVING 1418
#define HEADER 1419
#define INSERT 1420
#define LOCATE 1421
#define MARGIN 1422
#define MEMORY 1423
#define MINUTE 1424
#define MODIFY 1425
#define NORMAL 1426
#define EQUAL_EQUAL 1427
#define OPEN_SHEV 1429
#define OPEN_SQUARE 1430
#define OPTION 1431
#define OUTPUT 1432
#define PROMPT 1433
#define PUBLIC 1434
#define RECORD 1435
#define REPORT 1436
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
#define TIMEOUT 1652
#define OFF 1653




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
extern int lines_printed;
extern int lines_printed_true;
extern int lines_printed_false;

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
#line 1581 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1593 "y.tab.c"

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
#define YYFINAL  67
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8368

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  669
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  828
/* YYNRULES -- Number of rules. */
#define YYNRULES  1900
/* YYNRULES -- Number of states. */
#define YYNSTATES  3166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1666

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
     324,   325,   326,   327,   328,   329,    15,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,    16,   387,   388,   389,   390,   391,
     392,    23,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,    10,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,    13,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,    17,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,    12,   510,   511,   512,    11,    20,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
       8,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,    21,   539,   540,   541,   542,
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
     665,   666,   667,   668,     2,     3,     4,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33
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
    1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,  1766,  1768,
    1770,  1775,  1782,  1787,  1791,  1798,  1802,  1809,  1811,  1813,
    1815,  1817,  1819,  1821,  1822,  1825,  1827,  1829,  1831,  1836,
    1838,  1840,  1842,  1847,  1851,  1858,  1862,  1869,  1871,  1873,
    1876,  1879,  1882,  1884,  1888,  1890,  1893,  1896,  1899,  1904,
    1907,  1910,  1915,  1916,  1925,  1926,  1928,  1930,  1932,  1933,
    1935,  1938,  1939,  1941,  1944,  1945,  1947,  1950,  1951,  1953,
    1957,  1958,  1961,  1962,  1963,  1972,  1973,  1974,  1978,  1979,
    1980,  1988,  1994,  1997,  2000,  2001,  2007,  2012,  2014,  2018,
    2022,  2026,  2027,  2030,  2031,  2033,  2035,  2038,  2039,  2044,
    2045,  2050,  2051,  2055,  2056,  2060,  2061,  2065,  2066,  2070,
    2071,  2075,  2076,  2080,  2081,  2085,  2086,  2090,  2091,  2095,
    2097,  2101,  2103,  2107,  2110,  2115,  2117,  2119,  2121,  2122,
    2127,  2133,  2140,  2141,  2152,  2156,  2159,  2162,  2164,  2166,
    2167,  2170,  2172,  2175,  2179,  2183,  2187,  2191,  2193,  2195,
    2197,  2199,  2200,  2204,  2206,  2207,  2211,  2214,  2217,  2219,
    2223,  2225,  2229,  2231,  2233,  2235,  2237,  2239,  2241,  2243,
    2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,
    2265,  2267,  2269,  2270,  2271,  2279,  2281,  2283,  2286,  2289,
    2292,  2296,  2301,  2302,  2306,  2307,  2309,  2311,  2314,  2316,
    2318,  2320,  2322,  2323,  2325,  2327,  2330,  2333,  2335,  2337,
    2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,  2355,  2357,
    2359,  2360,  2362,  2364,  2366,  2368,  2370,  2371,  2372,  2373,
    2374,  2388,  2390,  2391,  2392,  2399,  2402,  2404,  2407,  2410,
    2413,  2415,  2417,  2420,  2422,  2424,  2426,  2427,  2431,  2434,
    2436,  2437,  2438,  2439,  2454,  2455,  2461,  2463,  2464,  2468,
    2469,  2477,  2478,  2484,  2486,  2489,  2490,  2492,  2494,  2496,
    2497,  2499,  2501,  2504,  2507,  2510,  2512,  2514,  2516,  2518,
    2522,  2524,  2526,  2527,  2528,  2536,  2538,  2541,  2542,  2546,
    2547,  2552,  2555,  2556,  2559,  2561,  2563,  2565,  2567,  2569,
    2571,  2573,  2577,  2578,  2580,  2582,  2584,  2586,  2589,  2592,
    2595,  2601,  2610,  2612,  2614,  2616,  2621,  2626,  2628,  2630,
    2632,  2634,  2637,  2640,  2644,  2651,  2653,  2657,  2659,  2661,
    2663,  2667,  2674,  2684,  2686,  2688,  2690,  2692,  2695,  2696,
    2698,  2700,  2704,  2706,  2710,  2712,  2716,  2718,  2722,  2724,
    2726,  2728,  2730,  2734,  2736,  2740,  2742,  2746,  2748,  2750,
    2752,  2756,  2759,  2760,  2762,  2764,  2769,  2771,  2775,  2777,
    2781,  2789,  2790,  2798,  2799,  2806,  2810,  2812,  2816,  2818,
    2821,  2827,  2828,  2836,  2837,  2840,  2841,  2843,  2849,  2852,
    2858,  2859,  2865,  2872,  2877,  2878,  2880,  2882,  2887,  2888,
    2891,  2892,  2898,  2903,  2906,  2908,  2912,  2915,  2918,  2921,
    2924,  2927,  2930,  2932,  2935,  2938,  2941,  2944,  2947,  2950,
    2953,  2956,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2977,
    2979,  2981,  2984,  2989,  2991,  2992,  3004,  3005,  3008,  3014,
    3015,  3017,  3018,  3021,  3023,  3026,  3027,  3031,  3033,  3034,
    3039,  3040,  3043,  3045,  3049,  3051,  3053,  3057,  3062,  3067,
    3070,  3072,  3074,  3076,  3077,  3079,  3087,  3090,  3093,  3096,
    3099,  3102,  3104,  3107,  3108,  3112,  3113,  3117,  3118,  3122,
    3123,  3127,  3128,  3132,  3133,  3138,  3139,  3144,  3146,  3148,
    3150,  3152,  3154,  3156,  3157,  3162,  3163,  3165,  3166,  3171,
    3173,  3176,  3179,  3182,  3183,  3185,  3187,  3190,  3193,  3194,
    3197,  3201,  3205,  3211,  3212,  3215,  3220,  3222,  3224,  3226,
    3228,  3230,  3231,  3233,  3235,  3239,  3242,  3248,  3251,  3257,
    3263,  3269,  3275,  3281,  3287,  3288,  3291,  3293,  3296,  3299,
    3302,  3305,  3308,  3311,  3313,  3316,  3319,  3322,  3325,  3327,
    3330,  3333,  3336,  3339,  3341,  3343,  3345,  3346,  3349,  3352,
    3355,  3358,  3361,  3364,  3367,  3370,  3373,  3375,  3377,  3379,
    3381,  3383,  3385,  3387,  3389,  3392,  3395,  3398,  3401,  3404,
    3406,  3408,  3410,  3411,  3415,  3418,  3419,  3420,  3421,  3422,
    3423,  3424,  3440,  3441,  3444,  3447,  3448,  3450,  3451,  3452,
    3453,  3454,  3455,  3456,  3472,  3475,  3476,  3477,  3478,  3489,
    3490,  3492,  3496,  3500,  3503,  3508,  3512,  3516,  3520,  3522,
    3524,  3526,  3528,  3530,  3532,  3533,  3534,  3542,  3543,  3544,
    3553,  3557,  3560,  3561,  3563,  3565,  3569,  3572,  3575,  3577,
    3579,  3583,  3585,  3587,  3590,  3592,  3596,  3598,  3602,  3604,
    3606,  3608,  3610,  3612,  3614,  3616,  3619,  3624,  3626,  3630,
    3632,  3636,  3639,  3644,  3646,  3650,  3652,  3655,  3660,  3662,
    3666,  3668,  3670,  3672,  3675,  3678,  3683,  3686,  3691,  3693,
    3697,  3699,  3701,  3703,  3706,  3708,  3710,  3712,  3714,  3716,
    3719,  3726,  3733,  3734,  3736,  3737,  3739,  3742,  3744,  3745,
    3751,  3752,  3758,  3760,  3761,  3765,  3767,  3771,  3773,  3777,
    3779,  3781,  3782,  3783,  3789,  3791,  3794,  3796,  3797,  3798,
    3802,  3803,  3804,  3808,  3810,  3812,  3814,  3816,  3818,  3820,
    3823,  3826,  3831,  3835,  3839,  3841,  3845,  3848,  3850,  3852,
    3853,  3855,  3857,  3859,  3861,  3862,  3864,  3868,  3870,  3872,
    3873,  3877,  3879,  3881,  3883,  3885,  3887,  3889,  3891,  3893,
    3895,  3897,  3899,  3901,  3909,  3910,  3912,  3914,  3916,  3918,
    3922,  3924,  3926,  3928,  3931,  3932,  3936,  3938,  3942,  3944,
    3948,  3950,  3952,  3959,  3960,  3964,  3966,  3970,  3971,  3973,
    3978,  3984,  3987,  3989,  3991,  3996,  3998,  4002,  4007,  4012,
    4014,  4018,  4020,  4022,  4024,  4027,  4029,  4034,  4035,  4037,
    4038,  4040,  4042,  4045,  4047,  4049,  4051,  4053,  4058,  4062,
    4064,  4066,  4068,  4071,  4073,  4075,  4078,  4081,  4083,  4087,
    4090,  4093,  4095,  4099,  4101,  4104,  4109,  4111,  4114,  4116,
    4120,  4125,  4126,  4128,  4129,  4131,  4132,  4134,  4136,  4140,
    4142,  4146,  4148,  4151,  4153,  4157,  4160,  4163,  4164,  4167,
    4169,  4171,  4177,  4181,  4187,  4191,  4193,  4197,  4199,  4201,
    4202,  4204,  4208,  4212,  4216,  4223,  4228,  4233,  4239,  4241,
    4243,  4245,  4247,  4249,  4251,  4253,  4255,  4257,  4259,  4261,
    4262,  4264,  4266,  4268,  4270,  4272,  4274,  4276,  4281,  4287,
    4289,  4295,  4301,  4303,  4305,  4307,  4312,  4314,  4319,  4321,
    4329,  4331,  4333,  4335,  4340,  4347,  4348,  4351,  4356,  4358,
    4360,  4362,  4364,  4366,  4368,  4370,  4374,  4376,  4378,  4382,
    4384,  4385,  4389,  4395,  4397,  4400,  4403,  4408,  4412,  4414,
    4416,  4418,  4420,  4422,  4424,  4427,  4430,  4431,  4435,  4436,
    4440,  4442,  4444,  4446,  4448,  4450,  4452,  4454,  4459,  4461,
    4463,  4465,  4467,  4469,  4471,  4473,  4478,  4480,  4482,  4484,
    4486,  4488,  4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,
    4506,  4508,  4510,  4514,  4515,  4524,  4525,  4535,  4536,  4544,
    4545,  4555,  4556,  4558,  4561,  4563,  4567,  4569,  4573,  4579,
    4581,  4583,  4585,  4587,  4590,  4591,  4592,  4601,  4607,  4609,
    4611,  4618,  4619,  4623,  4625,  4629,  4634,  4636,  4637,  4640,
    4645,  4652,  4653,  4655,  4657,  4659,  4661,  4665,  4667,  4670,
    4672,  4674,  4677,  4680,  4682,  4684,  4686,  4689,  4694,  4698,
    4701,  4705,  4709,  4713,  4715,  4717,  4719,  4721,  4723,  4725,
    4731,  4737,  4743,  4749,  4755,  4760,  4765,  4769,  4774,  4776,
    4780,  4782,  4788,  4796,  4802,  4803,  4806,  4808,  4810,  4811,
    4815,  4817,  4821,  4823,  4825,  4827,  4828,  4832,  4834,  4836,
    4838,  4840,  4845,  4852,  4854,  4856,  4859,  4863,  4865,  4867,
    4869,  4871,  4873,  4875,  4877,  4879,  4885,  4891,  4896,  4897,
    4902,  4904,  4907,  4909,  4911,  4913,  4916,  4919,  4920,  4921,
    4928,  4929,  4932,  4935,  4943,  4947,  4951,  4954,  4957,  4960,
    4962,  4966,  4968,  4972,  4974,  4978,  4980,  4984,  4986,  4988,
    4990,  4993,  4996,  4998,  5000,  5003,  5008,  5010,  5012,  5014,
    5016,  5018,  5020,  5024,  5027,  5031,  5035,  5039,  5045,  5051,
    5057,  5063,  5069,  5074,  5079,  5083,  5088,  5090,  5092,  5096,
    5098,  5101,  5103,  5105,  5107,  5111,  5117,  5119,  5121,  5123,
    5125,  5129,  5132,  5135,  5138,  5140,  5143,  5146,  5148,  5151,
    5154,  5157,  5159,  5163,  5166,  5168,  5171,  5173,  5176,  5178,
    5179,  5180,  5187,  5188,  5191,  5192,  5194,  5196,  5199,  5202,
    5204,  5206,  5211,  5215,  5217,  5221,  5223,  5226,  5232,  5235,
    5238,  5244,  5245,  5248,  5250,  5252,  5255,  5262,  5269,  5271,
    5272,  5274,  5277,  5279,  5282,  5283,  5286,  5288,  5290,  5292,
    5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,
    5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,  5332,
    5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,  5350,  5352,
    5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,  5370,  5372,
    5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,  5392,
    5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,  5412,
    5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,  5432,
    5434,  5436,  5438,  5440,  5442,  5444,  5446,  5448,  5450,  5452,
    5454
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1027,     0,    -1,   200,    -1,   197,    -1,   124,   674,   426,
     595,   675,    -1,   138,    -1,  1092,    -1,    26,    -1,   676,
      -1,   675,     5,   676,    -1,   939,    -1,   430,   677,   391,
      -1,   677,   678,   677,    -1,    26,    -1,   679,    26,    -1,
    1092,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   681,    -1,    -1,
     274,   430,   682,   683,   391,    -1,   568,   430,    26,     5,
      26,   391,    -1,   684,    -1,   683,     5,   684,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   409,    -1,   604,
      -1,   527,    -1,   479,    -1,   416,    -1,   490,    -1,   345,
      -1,   531,    -1,   455,    -1,   332,    -1,   593,    -1,    98,
      -1,  1006,    -1,    -1,   686,    -1,    -1,   274,   430,   687,
     688,   391,    -1,   689,    -1,   688,     5,   689,    -1,   684,
      -1,   431,    -1,   602,    25,    -1,   203,   926,    -1,   329,
     926,    -1,   284,   926,    -1,   337,   926,    -1,   293,   926,
      -1,   259,   926,    -1,   533,   691,    -1,   870,   344,  1092,
      -1,    -1,   289,   430,  1481,   391,   344,   692,  1111,    -1,
     104,   430,   939,     5,    25,     5,    25,   391,    -1,   406,
     430,   931,   391,   344,  1092,    -1,  1230,    -1,   192,   430,
     889,   391,   344,  1092,    -1,    -1,    -1,  1092,   589,   939,
     430,   693,   707,   391,   694,   705,    -1,    -1,    -1,    -1,
     939,   430,   695,   707,   696,   391,   697,   705,    -1,    -1,
      -1,   473,  1428,   622,  1428,   430,   698,   707,   699,   391,
     705,    -1,    -1,    -1,   939,   520,   939,   430,   700,   707,
     701,   391,   705,    -1,    -1,    -1,    -1,   365,   710,   589,
     711,   458,   674,   426,   430,   702,   707,   703,   391,   704,
     706,    -1,    -1,   344,  1111,    -1,    -1,   344,  1111,    -1,
     162,    -1,    -1,   708,    -1,   709,    -1,   708,     5,   709,
      -1,   839,    -1,    25,    -1,   939,    -1,   939,    -1,   939,
     619,   939,    -1,    -1,   534,   846,   713,   716,   720,   717,
      -1,    -1,   534,   714,   715,   718,   717,    -1,   722,    -1,
     715,   722,    -1,   724,    -1,   716,   724,    -1,   360,    -1,
      -1,    -1,   339,   719,  1491,    -1,    -1,    -1,   339,   721,
    1491,    -1,    -1,   578,   846,   723,  1491,    -1,    -1,   578,
     846,   725,  1491,    -1,   278,   936,    -1,   202,   934,    -1,
      83,   934,    -1,   168,    -1,   185,  1434,    -1,   493,   933,
      -1,    30,   728,    31,    -1,   729,    -1,   731,    -1,   730,
      -1,   729,   730,    -1,    29,    -1,   732,    -1,   731,   732,
      -1,    28,    -1,   393,    -1,    -1,    -1,   320,   735,   737,
     736,   738,    -1,   384,  1092,   624,   739,   980,  1005,   680,
      -1,  1092,   624,   739,   980,   546,  1481,  1005,   680,    -1,
      -1,   741,   191,    -1,   740,    -1,   739,     5,   740,    -1,
     939,    -1,   939,   619,   939,    -1,   939,   619,    20,    -1,
     742,    -1,   741,   742,    -1,    -1,   270,   748,   743,  1491,
      -1,    -1,   273,   749,   744,  1491,    -1,    -1,  1008,   745,
    1491,    -1,    -1,   166,   746,  1491,    -1,    -1,   163,   747,
    1491,    -1,   943,    -1,   748,     5,   943,    -1,   943,    -1,
     749,     5,   943,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   430,   839,   752,   391,
      -1,    -1,     5,   793,   625,   796,    -1,   155,    -1,   279,
      -1,    -1,   755,    -1,   756,    -1,   755,   756,    -1,    -1,
      -1,   437,   757,   759,   758,  1199,    -1,   806,    -1,  1471,
      -1,   762,    -1,   759,     5,   762,    -1,    -1,   761,   939,
      -1,   353,   760,   805,    25,    -1,   353,   760,   805,   939,
      -1,   353,   760,   805,   945,    -1,   353,   760,   805,    26,
      -1,   766,   782,    -1,    -1,   760,   353,   763,   764,    -1,
      26,    -1,    25,    -1,   945,    -1,    19,    26,    -1,   760,
      -1,   765,    -1,   766,     5,   765,    -1,    -1,   535,    -1,
      -1,   486,   458,   774,   426,   769,   623,   782,    -1,    -1,
     318,   767,   771,    26,   772,   302,   458,   773,   426,   770,
     623,   782,    -1,   430,    -1,   457,    -1,   391,    -1,   425,
      -1,    26,    -1,   775,     5,   775,     5,   775,    -1,   775,
       5,   775,    -1,   775,    -1,    26,    -1,    -1,   463,   777,
     759,   283,    -1,    -1,   260,   778,   760,   619,    20,    -1,
      -1,   334,   779,   760,   258,   430,   780,   391,    -1,   781,
      -1,   780,     5,   781,    -1,   760,    -1,   784,    -1,    -1,
      58,    -1,    -1,    -1,   785,   787,   786,   783,    -1,   768,
      -1,   776,    -1,   535,    -1,   535,   430,    26,   391,    -1,
     423,   430,    26,   391,    -1,   423,   430,    26,     5,    26,
     391,    -1,   407,    -1,   616,   760,    -1,   379,    -1,   508,
      -1,    89,    -1,   397,    -1,   397,   430,    26,   391,    -1,
     397,   430,    26,     5,    26,   391,    -1,   511,    -1,   511,
     430,    26,   391,    -1,   511,   430,    26,     5,    26,   391,
      -1,   501,    -1,   299,    -1,   537,    -1,   532,    -1,    79,
      -1,    80,    -1,   574,    -1,   357,   791,    -1,   369,   792,
      -1,   788,    -1,    32,    -1,   556,   789,   619,   790,    -1,
     760,    -1,   760,    -1,    -1,   793,   625,   796,    -1,   801,
     625,   804,    -1,    -1,   794,   795,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,
     798,    -1,    -1,   797,   795,    -1,    -1,   430,   800,   391,
      -1,    -1,   430,    26,   391,    -1,    26,    -1,    -1,   802,
     803,   799,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   453,    -1,   469,    -1,   366,   798,    -1,   803,    -1,
      -1,    14,    -1,    -1,   236,   939,   807,   616,   808,    -1,
     810,    -1,   813,    -1,   535,    -1,   535,   430,    26,   391,
      -1,   423,   430,    26,   391,    -1,   423,   430,    26,     5,
      26,   391,    -1,   407,    -1,   379,    -1,   508,    -1,   397,
      -1,   397,   430,    26,   391,    -1,   397,   430,    26,     5,
      26,   391,    -1,   511,    -1,   511,   430,    26,   391,    -1,
     511,   430,    26,     5,    26,   391,    -1,   501,    -1,   299,
      -1,   537,    -1,   532,    -1,   574,    -1,   357,   791,    -1,
     369,   792,    -1,   809,    -1,   556,   789,   619,   790,    -1,
      -1,   486,   458,   774,   426,   811,   623,   808,    -1,    -1,
     318,   767,   771,    26,   772,   302,   458,   773,   426,   812,
     623,   808,    -1,    -1,   463,   814,   816,   283,    -1,    -1,
     260,   815,   939,   619,    20,    -1,   817,    -1,   816,     5,
     817,    -1,   818,   808,    -1,   819,    -1,   818,     5,   819,
      -1,   939,    -1,    -1,   617,   930,    -1,    70,   939,    -1,
      68,    -1,   625,  1481,    -1,   625,   508,   939,   658,  1481,
      -1,   625,   508,   939,   389,    -1,    72,   939,    -1,   156,
     864,  1111,   828,    -1,   400,   864,   844,   820,   828,    -1,
     209,   936,   828,    -1,    -1,    -1,   188,   825,  1118,   625,
     939,   619,    20,   827,   680,   826,   829,    -1,    -1,   467,
     931,    -1,   680,    -1,    -1,   830,   238,    -1,   831,    -1,
     830,   831,    -1,    -1,   351,   832,  1491,    -1,    -1,   347,
     833,  1491,    -1,    -1,  1008,   834,  1491,    -1,   497,   864,
     845,   680,    -1,   497,   864,   845,   680,    65,    -1,   286,
      -1,   285,    -1,   212,    -1,   364,    -1,   173,    -1,   211,
      -1,   328,    -1,   327,    -1,   243,    -1,   170,    -1,   169,
      -1,   144,    -1,   204,    -1,   127,    -1,   143,    -1,   187,
      -1,   153,    -1,   213,    -1,   213,   846,    -1,   849,    -1,
     848,    -1,   853,    -1,   881,    -1,   839,   840,    -1,   882,
      -1,   884,    -1,   850,    -1,    19,   839,    -1,    18,   839,
      -1,   855,    -1,   863,    -1,   857,    -1,   474,    -1,   750,
      -1,   858,    -1,   859,    -1,   860,    -1,   861,    -1,   862,
      -1,    35,   839,    -1,   864,    -1,   864,   843,    -1,   846,
      -1,   482,    -1,   842,    -1,   843,     5,   842,    -1,   846,
      -1,   844,     5,   846,    -1,   846,    -1,   845,     5,   846,
      -1,   839,    -1,    18,    -1,    19,    -1,     9,   839,    -1,
     483,    -1,   427,    -1,   430,   839,   391,    -1,   442,   430,
    1408,   391,    -1,   294,   430,  1408,   391,    -1,   847,   945,
      -1,   847,    26,    -1,    25,    -1,   945,    -1,    26,    -1,
     852,    -1,  1092,    -1,  1092,   420,  1092,    -1,   851,    -1,
     433,   839,    -1,   392,   839,    -1,  1202,    -1,    -1,   506,
     854,  1202,    -1,     7,   839,    -1,     6,   839,    -1,   839,
      -1,   856,     5,   839,    -1,   622,   430,  1408,   391,    -1,
     428,   430,  1408,   391,    -1,   622,   430,   864,   856,   391,
      -1,   428,   430,   864,   856,   391,    -1,   386,    -1,   249,
      -1,    10,   839,    -1,   252,   839,    -1,    10,   839,   441,
      25,    -1,   252,   839,   441,    25,    -1,   556,   839,    -1,
     371,   839,    -1,   556,   839,   441,    25,    -1,   371,   839,
     441,    25,    -1,   390,    -1,     8,   839,    -1,    18,   839,
      -1,    19,   839,    -1,    20,   839,    -1,    21,   839,    -1,
      22,   839,    -1,    11,   839,    -1,    14,   839,    -1,   456,
     839,    -1,    12,   839,    -1,    13,   839,    -1,    17,   839,
      -1,    16,   839,    -1,    15,   839,    -1,    -1,    -1,    -1,
     939,   430,   866,   707,   867,   391,    -1,    -1,    -1,   939,
     520,   939,   430,   868,   707,   869,   391,    -1,    -1,    -1,
     537,   430,   871,   839,   872,   391,    -1,    -1,    -1,   512,
     430,   873,   839,   874,   391,    -1,    -1,    -1,   590,   430,
     875,   839,   876,   391,    -1,    -1,    -1,   581,   430,   877,
     839,   878,   391,    -1,   369,   430,   885,   391,   880,    -1,
     357,   430,    25,   391,   879,    -1,   357,   430,    26,   391,
     879,    -1,   357,   430,    26,   589,    26,   391,   879,    -1,
      -1,  1388,   625,  1389,    -1,   792,    -1,   870,    -1,   289,
     430,  1481,   391,    -1,    99,   430,   931,   391,    -1,    71,
     430,   931,   391,    -1,   406,   430,  1481,   391,    -1,   192,
     430,  1481,   391,    -1,    59,   430,  1481,   391,    -1,   883,
      -1,   865,    -1,  1384,    -1,   537,    -1,   422,   430,   839,
     391,    -1,   322,   430,   839,   391,    -1,   487,   839,    -1,
     443,   751,    -1,   839,   108,    -1,   839,   109,    -1,   839,
     110,    -1,    25,    -1,   886,    -1,    19,   886,    -1,   888,
      -1,   887,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   931,    -1,   889,     5,   931,
      -1,    -1,    -1,   595,  1092,    14,   846,   625,   846,   893,
     891,  1491,   892,   241,    -1,    -1,   571,   846,    -1,    -1,
      -1,    -1,   403,   895,   933,   896,   898,  1289,   897,  1491,
     240,    -1,    -1,     8,   864,   844,    -1,    -1,    -1,   637,
     939,   900,   754,   901,  1037,   903,   902,   908,   638,    -1,
      -1,   913,    -1,    -1,   904,    -1,   905,    -1,   904,   905,
      -1,    -1,   639,   906,  1491,    -1,    -1,   640,   907,  1491,
      -1,    -1,   909,    -1,   910,    -1,   909,   910,    -1,    -1,
     641,   911,  1491,    -1,    -1,   642,   912,  1491,    -1,   914,
     918,   324,    -1,    91,    -1,    91,   915,   546,   916,    -1,
      91,   384,   917,    -1,  1092,    -1,   915,     5,  1092,    -1,
     939,    -1,   916,     5,   939,    -1,  1092,    -1,   917,     5,
    1092,    -1,   919,    -1,   918,   919,    -1,    -1,   643,   920,
    1491,    -1,    -1,   644,   921,  1491,    -1,    -1,   663,   916,
     922,  1491,    -1,    -1,   480,   916,   923,  1491,    -1,    -1,
     624,   916,   924,  1491,    -1,   545,   932,    -1,   554,    19,
      26,    -1,   554,    -1,   500,    18,    26,    -1,   500,    -1,
      26,    -1,  1092,    -1,   668,    -1,    25,    -1,   944,    -1,
     846,    -1,   928,     5,   928,    -1,   929,    -1,   939,    -1,
     666,   430,   939,   391,    -1,   939,   619,   666,   430,   939,
     391,    -1,   939,   458,   677,   426,    -1,   939,   619,    20,
      -1,   939,   458,   677,   426,   619,    20,    -1,   939,   619,
     939,    -1,   939,   458,   677,   426,   619,   939,    -1,   940,
      -1,   940,    -1,   940,    -1,   940,    -1,   940,    -1,   940,
      -1,    -1,   550,    26,    -1,  1490,    -1,   941,    -1,  1490,
      -1,   349,   430,   942,   391,    -1,  1095,    -1,    25,    -1,
     939,    -1,   939,   458,   677,   426,    -1,   939,   619,    20,
      -1,   939,   458,   677,   426,   619,    20,    -1,   939,   619,
     939,    -1,   939,   458,   677,   426,   619,   939,    -1,  1092,
      -1,    24,    -1,   619,    26,    -1,   547,  1473,    -1,   651,
     948,    -1,   949,    -1,   948,     5,   949,    -1,   939,    -1,
     662,   948,    -1,   653,   948,    -1,   654,  1481,    -1,   652,
     936,   658,  1481,    -1,   656,   948,    -1,   657,  1481,    -1,
     655,   936,   658,  1481,    -1,    -1,   660,   954,   844,   959,
     961,   963,   955,   957,    -1,    -1,   956,    -1,   648,    -1,
     649,    -1,    -1,   958,    -1,   344,  1092,    -1,    -1,   960,
      -1,   389,   844,    -1,    -1,   962,    -1,   659,    26,    -1,
      -1,   964,    -1,   650,    26,   965,    -1,    -1,   399,    26,
      -1,    -1,    -1,   621,   846,   575,   967,  1491,   968,   969,
     440,    -1,    -1,    -1,   542,   970,  1491,    -1,    -1,    -1,
      62,   971,   846,   575,   972,  1491,   969,    -1,   106,   939,
     430,    26,   391,    -1,    55,   939,    -1,    75,   939,    -1,
      -1,   290,  1123,   976,   625,   482,    -1,   290,  1123,   556,
     977,    -1,   978,    -1,   977,     5,   978,    -1,   789,   619,
    1380,    -1,   789,   619,    20,    -1,    -1,   981,   324,    -1,
      -1,   150,    -1,   982,    -1,   981,   982,    -1,    -1,   270,
     994,   983,  1491,    -1,    -1,   273,   995,   984,  1491,    -1,
      -1,   351,   985,  1491,    -1,    -1,   347,   986,  1491,    -1,
      -1,  1008,   987,  1491,    -1,    -1,   305,   988,  1491,    -1,
      -1,   275,   989,  1491,    -1,    -1,    36,   990,  1491,    -1,
      -1,    34,   991,  1491,    -1,    -1,    38,   992,  1491,    -1,
      -1,    37,   993,  1491,    -1,   931,    -1,   994,     5,   931,
      -1,   931,    -1,   995,     5,   931,    -1,   314,   998,    -1,
     315,   939,   658,   998,    -1,   561,    -1,   374,    -1,   931,
      -1,    -1,   664,  1001,  1000,   979,    -1,   384,  1111,   980,
     938,   680,    -1,  1111,   980,   546,  1481,   938,   680,    -1,
      -1,   486,  1118,   980,   546,   939,   619,    20,   938,  1002,
     680,    -1,   468,  1481,  1004,    -1,    81,    26,    -1,    82,
      26,    -1,   626,    -1,   539,    -1,    -1,   550,    26,    -1,
    1007,    -1,    43,    25,    -1,   495,    14,    26,    -1,   495,
      14,  1092,    -1,    44,    14,    26,    -1,    44,    14,  1092,
      -1,    40,    -1,    42,    -1,    39,    -1,    41,    -1,    -1,
     429,  1009,  1014,    -1,   295,    -1,    -1,   596,  1011,  1014,
      -1,   303,  1016,    -1,   596,  1014,    -1,  1016,    -1,   430,
    1015,   391,    -1,  1016,    -1,  1015,     5,  1016,    -1,  1017,
      -1,   594,    -1,   312,    -1,   330,    -1,   304,    -1,   484,
      -1,   441,    -1,   626,    -1,   550,    -1,   539,    -1,   177,
      -1,   438,    -1,   449,    -1,   540,    -1,   555,    -1,   519,
      -1,   310,    -1,   311,    -1,    25,    -1,   509,    -1,    -1,
      -1,   598,  1020,  1116,  1021,    14,   864,  1022,    -1,   482,
      -1,   845,    -1,   219,  1092,    -1,   208,  1092,    -1,   222,
    1092,    -1,   450,  1092,   333,    -1,   450,  1092,   385,   927,
      -1,    -1,  1029,  1028,  1032,    -1,    -1,  1030,    -1,  1031,
      -1,  1030,  1031,    -1,   974,    -1,  1036,    -1,  1052,    -1,
    1038,    -1,    -1,  1033,    -1,  1035,    -1,  1033,  1035,    -1,
      66,   939,    -1,  1040,    -1,  1046,    -1,  1058,    -1,  1212,
      -1,  1222,    -1,  1079,    -1,  1471,    -1,   899,    -1,   727,
      -1,   973,    -1,   733,    -1,   727,    -1,  1471,    -1,    -1,
     727,    -1,  1471,    -1,   755,    -1,   367,    -1,    60,    -1,
      -1,    -1,    -1,    -1,  1039,  1041,   939,   430,  1042,  1109,
     391,  1043,   754,  1044,  1037,  1491,  1045,    -1,   210,    -1,
      -1,    -1,   557,  1047,   754,  1048,  1491,   361,    -1,   177,
     841,    -1,   864,    -1,   864,   844,    -1,   356,  1392,    -1,
     466,  1392,    -1,  1053,    -1,  1054,    -1,  1053,  1054,    -1,
    1055,    -1,  1036,    -1,  1051,    -1,    -1,   405,  1056,  1057,
      -1,   754,   242,    -1,   927,    -1,    -1,    -1,    -1,   113,
     939,   112,   939,   430,  1059,  1109,   391,  1060,   754,  1061,
    1037,  1491,  1045,    -1,    -1,   558,  1063,  1078,  1069,  1064,
      -1,   362,    -1,    -1,   234,  1066,  1491,    -1,    -1,    23,
    1070,  1071,  1072,   938,  1067,  1491,    -1,    -1,    23,  1070,
     938,  1068,  1491,    -1,  1065,    -1,  1069,  1065,    -1,    -1,
    1010,    -1,    25,    -1,  1092,    -1,    -1,  1092,    -1,    25,
      -1,   251,  1076,    -1,   263,  1077,    -1,   246,  1077,    -1,
     585,    -1,    25,    -1,  1092,    -1,  1076,    -1,  1077,     5,
    1076,    -1,  1092,    -1,    25,    -1,    -1,    -1,   645,   939,
    1080,   754,  1081,  1082,   646,    -1,  1083,    -1,  1082,  1083,
      -1,    -1,   647,  1084,  1491,    -1,    -1,   624,   939,  1085,
    1491,    -1,  1089,  1087,    -1,    -1,   681,  1090,    -1,  1091,
      -1,  1088,    -1,   960,    -1,   962,    -1,   964,    -1,   956,
      -1,   958,    -1,   370,   864,   844,    -1,    -1,    65,    -1,
      65,    -1,  1093,    -1,  1095,    -1,   190,  1095,    -1,  1095,
     619,    -1,  1094,  1099,    -1,  1094,   939,   458,  1103,   426,
      -1,  1094,   939,   458,  1103,   426,   458,  1103,   426,    -1,
    1100,    -1,   939,    -1,  1096,    -1,   939,   457,  1098,   425,
      -1,   939,   457,  1098,   425,    -1,  1092,    -1,    25,    -1,
      20,    -1,   939,    -1,   939,  1102,    -1,   939,  1102,    -1,
     458,  1103,   426,    -1,   458,  1103,   426,   458,  1103,   426,
      -1,  1104,    -1,  1103,     5,  1104,    -1,   677,    -1,  1106,
      -1,  1108,    -1,  1106,   619,  1107,    -1,  1106,   619,   939,
     458,  1103,   426,    -1,  1106,   619,   939,   458,  1103,   426,
     458,  1103,   426,    -1,   939,    -1,  1097,    -1,    20,    -1,
     939,    -1,   939,  1102,    -1,    -1,  1110,    -1,  1112,    -1,
    1110,     5,  1112,    -1,  1113,    -1,  1111,     5,  1113,    -1,
     939,    -1,   939,   619,   939,    -1,  1092,    -1,  1092,   420,
    1092,    -1,    25,    -1,   945,    -1,    26,    -1,  1115,    -1,
    1114,     5,  1115,    -1,  1092,    -1,  1092,   420,  1092,    -1,
    1117,    -1,  1116,     5,  1117,    -1,  1105,    -1,  1092,    -1,
    1120,    -1,  1119,     5,  1120,    -1,  1092,  1121,    -1,    -1,
     587,    -1,   538,    -1,   939,   458,  1103,   426,    -1,  1124,
      -1,  1123,     5,  1124,    -1,  1092,    -1,  1092,   420,  1092,
      -1,   254,   935,   617,   929,   579,  1483,   685,    -1,    -1,
     617,   430,   846,     5,   846,   391,  1127,    -1,    -1,   568,
     430,   846,     5,   846,   391,    -1,   255,   939,  1126,    -1,
     939,    -1,   338,   937,  1131,    -1,  1132,    -1,   546,   846,
      -1,  1133,  1134,  1139,     8,  1129,    -1,    -1,   617,  1135,
     430,   846,     5,   846,   391,    -1,    -1,   556,   940,    -1,
      -1,   350,    -1,   217,  1434,   266,  1466,  1138,    -1,   563,
     932,    -1,   563,   932,     8,   864,   844,    -1,    -1,   616,
     576,  1428,   373,  1428,    -1,   616,   576,  1428,     5,   373,
    1428,    -1,   616,  1428,     5,  1428,    -1,    -1,   648,    -1,
     649,    -1,    90,  1466,  1141,  1142,    -1,    -1,   616,  1466,
      -1,    -1,   616,   576,  1428,     8,  1428,    -1,   576,  1428,
       8,  1428,    -1,   411,  1144,    -1,  1145,    -1,  1144,     5,
    1145,    -1,   203,   926,    -1,   284,   926,    -1,   329,   926,
      -1,   337,   926,    -1,   293,   926,    -1,   259,   926,    -1,
    1012,    -1,   438,  1013,    -1,   449,  1013,    -1,   561,  1013,
      -1,   374,  1013,    -1,   550,  1013,    -1,   548,   927,    -1,
     549,   927,    -1,   400,   681,    -1,   664,   681,    -1,   291,
      -1,   195,    -1,   151,    -1,   128,    -1,   146,    -1,   137,
      -1,  1433,   413,  1149,   546,  1147,    -1,  1092,    -1,    25,
      -1,   402,  1149,    -1,   402,  1149,     8,  1111,    -1,   940,
      -1,    -1,   461,  1159,   680,   595,  1154,  1092,  1152,   938,
     680,  1151,  1155,    -1,    -1,   667,    26,    -1,   461,  1159,
     680,   344,  1092,    -1,    -1,   535,    -1,    -1,  1156,   282,
      -1,  1157,    -1,  1156,  1157,    -1,    -1,  1008,  1158,  1491,
      -1,   845,    -1,    -1,   603,   932,  1161,  1162,    -1,    -1,
     546,  1163,    -1,  1164,    -1,  1163,     5,  1164,    -1,  1420,
      -1,   482,    -1,   220,  1167,    88,    -1,   220,  1167,   625,
    1166,    -1,   220,  1167,    87,  1166,    -1,   220,  1167,    -1,
      25,    -1,   944,    -1,   939,    -1,    -1,   478,    -1,   145,
    1167,  1168,   430,   864,  1050,   391,    -1,   193,  1167,    -1,
      67,  1167,    -1,  1203,  1211,    -1,   446,    61,    -1,   446,
    1174,    -1,  1175,    -1,  1174,  1175,    -1,    -1,   133,  1176,
    1491,    -1,    -1,   199,  1177,  1491,    -1,    -1,   228,  1178,
    1491,    -1,    -1,   216,  1179,  1491,    -1,    -1,   253,  1180,
    1491,    -1,    -1,   201,  1092,  1181,  1491,    -1,    -1,   224,
    1092,  1182,  1491,    -1,  1193,    -1,  1195,    -1,  1194,    -1,
    1184,    -1,  1220,    -1,  1187,    -1,    -1,   560,   846,  1185,
     481,    -1,    -1,   481,    -1,    -1,   569,    26,  1188,  1186,
      -1,   158,    -1,   628,  1207,    -1,   161,  1207,    -1,   160,
    1207,    -1,    -1,  1190,    -1,  1191,    -1,  1190,  1191,    -1,
    1200,  1192,    -1,    -1,   617,  1207,    -1,   518,  1189,  1199,
      -1,   517,  1428,  1199,    -1,   516,  1198,  1197,  1196,  1199,
      -1,    -1,   152,   839,    -1,   152,   839,     5,   839,    -1,
     612,    -1,   613,    -1,   614,    -1,   615,    -1,  1092,    -1,
      -1,   521,    -1,  1201,    -1,  1200,     5,  1201,    -1,   846,
    1234,    -1,   608,   430,   839,   391,  1219,    -1,    64,  1219,
      -1,   495,   430,    20,   391,  1219,    -1,   412,   430,    20,
     391,  1219,    -1,   387,   430,   839,   391,  1219,    -1,   588,
     430,   839,   391,  1219,    -1,   601,   430,   839,   391,  1219,
      -1,   600,   430,   839,   391,  1219,    -1,    -1,   460,  1204,
      -1,  1205,    -1,  1204,  1205,    -1,   227,    26,    -1,   218,
      26,    -1,   301,    26,    -1,   184,    26,    -1,   256,    26,
      -1,   175,    -1,   343,    25,    -1,   343,  1092,    -1,   176,
      25,    -1,   159,    25,    -1,  1210,    -1,  1206,  1210,    -1,
    1208,   108,    -1,  1208,   110,    -1,  1208,   109,    -1,  1208,
      -1,   945,    -1,    26,    -1,    -1,   460,  1206,    -1,   227,
    1207,    -1,   218,  1207,    -1,   301,  1207,    -1,   184,  1207,
      -1,   256,  1207,    -1,   257,  1207,    -1,   627,    25,    -1,
     628,  1207,    -1,   632,    -1,   629,    -1,   630,    -1,   631,
      -1,   636,    -1,   633,    -1,   634,    -1,   635,    -1,    76,
    1207,    -1,    77,  1207,    -1,    78,  1207,    -1,   343,    25,
      -1,   176,    25,    -1,   399,    -1,    73,    -1,    74,    -1,
      -1,   513,   618,  1119,    -1,   134,  1119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   464,  1213,   939,   430,  1214,  1109,
     391,  1215,   754,  1216,  1172,  1217,  1173,  1218,   239,    -1,
      -1,   525,   839,    -1,   515,  1221,    -1,    -1,  1147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   105,  1223,   939,   430,
    1224,  1109,   391,  1225,   754,  1226,  1229,  1227,  1173,  1228,
     239,    -1,  1209,  1211,    -1,    -1,    -1,    -1,   154,   430,
      25,     5,  1231,   707,  1232,   391,  1233,   705,    -1,    -1,
     383,    -1,   383,   218,    26,    -1,   383,   218,  1092,    -1,
     606,   846,    -1,   606,   846,   344,  1092,    -1,   606,   846,
     162,    -1,   606,   846,   577,    -1,   606,   846,   544,    -1,
    1237,    -1,   172,    -1,   323,    -1,   281,    -1,  1244,    -1,
    1239,    -1,    -1,    -1,   206,  1240,  1377,   430,  1241,  1248,
     391,    -1,    -1,    -1,   131,  1242,  1377,   430,  1243,  1248,
     391,  1245,    -1,   103,  1246,   391,    -1,    54,   940,    -1,
      -1,   268,    -1,  1247,    -1,  1246,     5,  1247,    -1,   939,
     587,    -1,   939,   538,    -1,   939,    -1,  1249,    -1,  1248,
       5,  1249,    -1,  1330,    -1,  1328,    -1,   120,   939,    -1,
     179,    -1,    45,   939,  1252,    -1,  1253,    -1,  1252,     5,
    1253,    -1,  1254,    -1,  1257,    -1,  1260,    -1,  1265,    -1,
    1266,    -1,  1264,    -1,  1263,    -1,   584,  1255,    -1,   584,
     430,  1256,   391,    -1,  1249,    -1,  1249,   663,   939,    -1,
    1255,    -1,  1256,     5,  1255,    -1,   541,  1259,    -1,   541,
     430,  1258,   391,    -1,  1259,    -1,  1258,     5,  1259,    -1,
     939,    -1,   454,  1262,    -1,   454,   430,  1261,   391,    -1,
    1262,    -1,  1261,     5,  1262,    -1,  1249,    -1,    85,    -1,
      86,    -1,    84,    26,    -1,    56,  1334,    -1,    56,   430,
    1267,   391,    -1,    57,  1268,    -1,    57,   430,  1267,   391,
      -1,  1334,    -1,  1267,     5,  1334,    -1,   939,    -1,   265,
      -1,   231,    -1,   164,  1271,    -1,   141,    -1,   129,    -1,
     119,    -1,   117,    -1,   121,    -1,   178,  1434,    -1,   230,
    1270,   459,  1428,   625,  1428,    -1,   298,   932,   459,  1428,
     625,  1428,    -1,    -1,  1434,    -1,    -1,   846,    -1,   522,
     846,    -1,   229,    -1,    -1,   248,  1275,  1377,  1278,  1276,
      -1,    -1,   478,  1277,   430,  1280,   391,    -1,  1414,    -1,
      -1,   430,  1279,   391,    -1,  1380,    -1,  1279,     5,  1380,
      -1,  1281,    -1,  1280,     5,  1281,    -1,  1420,    -1,   482,
      -1,    -1,    -1,   499,  1283,  1286,  1284,  1287,    -1,   940,
      -1,  1291,   933,    -1,   933,    -1,    -1,    -1,   553,  1288,
    1114,    -1,    -1,    -1,   553,  1290,  1114,    -1,   500,    -1,
     554,    -1,   561,    -1,   374,    -1,   341,    -1,   395,    -1,
     377,   846,    -1,   350,   846,    -1,   237,  1377,   149,   933,
      -1,   237,  1377,  1350,    -1,   513,   618,  1295,    -1,  1296,
      -1,  1295,     5,  1296,    -1,  1297,  1298,    -1,    26,    -1,
    1380,    -1,    -1,   587,    -1,   538,    -1,   276,    -1,   309,
      -1,    -1,   326,    -1,   356,  1303,  1301,    -1,  1466,    -1,
      25,    -1,    -1,  1433,  1305,  1306,    -1,  1335,    -1,  1339,
      -1,  1300,    -1,  1435,    -1,  1299,    -1,  1292,    -1,  1293,
      -1,  1282,    -1,  1274,    -1,  1273,    -1,  1404,    -1,  1450,
      -1,   504,  1309,   624,  1377,   625,  1314,  1308,    -1,    -1,
     140,    -1,   167,    -1,  1310,    -1,  1311,    -1,  1310,     5,
    1311,    -1,   470,    -1,   449,    -1,   438,    -1,   477,  1312,
      -1,    -1,   430,  1313,   391,    -1,  1380,    -1,  1313,     5,
    1380,    -1,  1315,    -1,  1314,     5,  1315,    -1,   462,    -1,
    1378,    -1,   235,  1377,  1317,   616,  1414,  1319,    -1,    -1,
     430,  1318,   391,    -1,  1380,    -1,  1318,     5,  1380,    -1,
      -1,   139,    -1,   491,   430,  1353,   391,    -1,   245,   430,
    1323,   391,  1322,    -1,   296,  1324,    -1,  1325,    -1,  1377,
      -1,  1377,   430,  1325,   391,    -1,  1380,    -1,  1325,     5,
    1380,    -1,   475,   430,  1327,   391,    -1,   258,   430,  1327,
     391,    -1,  1380,    -1,  1327,     5,  1380,    -1,  1326,    -1,
    1321,    -1,  1320,    -1,   399,  1383,    -1,   207,    -1,   939,
    1369,  1331,  1332,    -1,    -1,  1329,    -1,    -1,  1333,    -1,
    1334,    -1,  1333,  1334,    -1,   372,    -1,   157,    -1,   475,
      -1,  1322,    -1,   491,   430,  1353,   391,    -1,   118,  1336,
    1338,    -1,  1337,    -1,  1378,    -1,  1339,    -1,  1338,  1339,
      -1,  1316,    -1,  1307,    -1,   447,  1353,    -1,   368,  1342,
      -1,  1419,    -1,  1342,     5,  1419,    -1,   525,  1353,    -1,
     546,  1345,    -1,  1346,    -1,  1345,     5,  1346,    -1,  1347,
      -1,   514,  1347,    -1,   514,   430,  1348,   391,    -1,  1377,
      -1,  1377,  1382,    -1,  1346,    -1,  1348,     5,  1346,    -1,
    1344,  1350,  1351,  1352,    -1,    -1,  1343,    -1,    -1,  1341,
      -1,    -1,  1340,    -1,  1354,    -1,  1353,     6,  1354,    -1,
    1355,    -1,  1354,     7,  1355,    -1,  1356,    -1,     9,  1356,
      -1,  1367,    -1,   430,  1353,   391,    -1,   442,  1415,    -1,
     294,  1415,    -1,    -1,   441,  1360,    -1,  1421,    -1,  1424,
      -1,  1420,   622,   430,  1362,   391,    -1,  1420,   622,  1415,
      -1,  1420,   428,   430,  1362,   391,    -1,  1420,   428,  1415,
      -1,  1363,    -1,  1362,     5,  1363,    -1,  1470,    -1,  1383,
      -1,    -1,     9,    -1,  1420,  1364,   386,    -1,  1420,  1364,
     249,    -1,  1420,  1366,  1420,    -1,  1420,  1364,   388,  1420,
       7,  1420,    -1,  1420,   556,  1359,  1358,    -1,  1420,   371,
    1359,  1358,    -1,  1420,  1364,    10,  1359,  1358,    -1,    14,
      -1,    17,    -1,    12,    -1,    13,    -1,   252,    -1,    10,
      -1,    16,    -1,    15,    -1,  1365,    -1,  1361,    -1,  1357,
      -1,    -1,   585,    -1,   359,    -1,   475,    -1,  1370,    -1,
    1371,    -1,  1373,    -1,   535,    -1,   535,   430,  1374,   391,
      -1,   410,   430,  1375,  1372,   391,    -1,   471,    -1,   397,
     430,  1375,  1372,   391,    -1,   511,   430,  1375,  1372,   391,
      -1,   537,    -1,   407,    -1,   379,    -1,   357,  1390,   625,
    1391,    -1,   357,    -1,   369,  1390,   625,  1391,    -1,   369,
      -1,   369,  1390,   430,    26,   391,   625,  1391,    -1,   574,
      -1,   532,    -1,   423,    -1,   423,   430,    26,   391,    -1,
     423,   430,    26,     5,    26,   391,    -1,    -1,     5,  1376,
      -1,   501,   430,  1375,   391,    -1,   565,    -1,   299,    -1,
     501,    -1,    63,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   619,   939,    -1,    25,    -1,   939,    -1,   939,   589,
     939,    -1,   939,    -1,    -1,   458,    26,   426,    -1,   458,
      26,     5,    26,   426,    -1,  1381,    -1,   611,  1381,    -1,
     939,  1379,    -1,  1377,   619,   939,  1379,    -1,  1377,   619,
      20,    -1,   939,    -1,    25,    -1,   410,    -1,   945,    -1,
      26,    -1,  1385,    -1,   395,  1387,    -1,   395,  1386,    -1,
      -1,  1390,   625,  1391,    -1,    -1,  1388,   625,  1388,    -1,
     581,    -1,   512,    -1,   590,    -1,   552,    -1,   453,    -1,
     469,    -1,   366,    -1,   366,   430,    26,   391,    -1,   581,
      -1,   512,    -1,   590,    -1,   552,    -1,   453,    -1,   469,
      -1,   366,    -1,   366,   430,    26,   391,    -1,   581,    -1,
     512,    -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,
     366,    -1,   581,    -1,   512,    -1,   590,    -1,   552,    -1,
     453,    -1,   469,    -1,   366,    -1,   939,    -1,    25,    -1,
    1433,   502,   933,    -1,    -1,  1433,   398,  1285,   436,   595,
    1402,  1395,  1399,    -1,    -1,  1433,   398,  1285,   436,   100,
     595,  1403,  1396,  1399,    -1,    -1,  1433,   398,  1285,   135,
    1403,  1397,  1399,    -1,    -1,  1433,   398,  1285,   136,   100,
     595,  1403,  1398,  1399,    -1,    -1,   288,    -1,   287,  1400,
      -1,  1401,    -1,  1400,     5,  1401,    -1,   939,    -1,   939,
     619,   939,    -1,    25,   619,   939,   619,   939,    -1,  1403,
      -1,  1274,    -1,  1149,    -1,  1405,    -1,  1405,  1399,    -1,
      -1,    -1,   470,  1416,  1406,  1417,  1407,  1413,  1349,  1411,
      -1,   470,  1416,  1417,  1349,  1411,    -1,  1410,    -1,  1428,
      -1,   470,  1416,  1417,  1413,  1349,  1411,    -1,    -1,   524,
    1368,  1409,    -1,  1294,    -1,   331,  1412,  1245,    -1,  1294,
     331,  1412,  1245,    -1,   939,    -1,    -1,   553,  1114,    -1,
     470,  1416,  1417,  1349,    -1,   430,   470,  1416,  1417,  1349,
     391,    -1,    -1,   585,    -1,   359,    -1,   475,    -1,  1418,
      -1,  1417,     5,  1418,    -1,  1420,    -1,  1420,   939,    -1,
    1420,    -1,  1421,    -1,    19,  1421,    -1,    18,  1421,    -1,
    1422,    -1,  1470,    -1,  1415,    -1,   611,   939,    -1,   611,
     939,   619,   939,    -1,  1421,    21,  1420,    -1,  1421,  1442,
      -1,  1421,    20,  1420,    -1,  1421,    18,  1420,    -1,  1421,
      19,  1420,    -1,  1383,    -1,   483,    -1,   427,    -1,   576,
      -1,    20,    -1,    64,    -1,   588,   430,  1368,  1420,   391,
      -1,   600,   430,  1368,  1420,   391,    -1,   601,   430,  1368,
    1420,   391,    -1,   608,   430,  1368,  1420,   391,    -1,   495,
     430,  1368,  1420,   391,    -1,   939,   430,  1423,   391,    -1,
     537,   430,  1423,   391,    -1,   430,  1420,   391,    -1,   443,
     430,  1443,   391,    -1,  1420,    -1,  1423,     5,  1420,    -1,
    1383,    -1,  1433,   346,  1432,  1427,  1409,    -1,  1433,   335,
    1432,  1427,   248,  1377,  1429,    -1,  1433,   335,  1432,  1427,
    1092,    -1,    -1,   321,  1428,    -1,    25,    -1,  1092,    -1,
      -1,   430,  1430,   391,    -1,  1431,    -1,  1430,     5,  1431,
      -1,   939,    -1,    25,    -1,  1092,    -1,    -1,   267,  1434,
     595,    -1,   940,    -1,  1440,    -1,  1439,    -1,  1436,    -1,
     316,  1437,   625,  1437,    -1,   297,  1437,   619,  1438,   625,
    1438,    -1,   939,    -1,   939,    -1,   221,   789,    -1,   292,
     789,  1441,    -1,   271,    -1,   174,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,   395,
       5,  1390,   625,  1391,    -1,  1470,     5,  1390,   625,  1391,
      -1,   395,  1390,   625,  1391,    -1,    -1,   607,  1445,  1446,
     189,    -1,  1447,    -1,  1446,  1447,    -1,    33,    -1,  1448,
      -1,  1449,    -1,   190,  1470,    -1,   553,  1114,    -1,    -1,
      -1,   477,  1377,  1451,  1454,  1452,  1453,    -1,    -1,   149,
     933,    -1,   525,  1353,    -1,    52,  1458,   391,    14,   430,
    1459,   391,    -1,    48,  1459,   391,    -1,    49,  1459,   391,
      -1,   583,  1455,    -1,    51,  1459,    -1,    50,  1459,    -1,
    1457,    -1,  1455,     5,  1457,    -1,  1380,    -1,  1456,    14,
    1460,    -1,  1456,    -1,  1458,     5,  1456,    -1,  1460,    -1,
    1459,     5,  1460,    -1,   482,    -1,  1461,    -1,  1462,    -1,
      19,  1462,    -1,    18,  1462,    -1,  1464,    -1,  1415,    -1,
     611,   939,    -1,   611,   939,   619,   939,    -1,  1463,    -1,
    1383,    -1,   483,    -1,   427,    -1,   576,    -1,    64,    -1,
    1462,    21,  1461,    -1,  1462,  1442,    -1,  1462,    20,  1461,
      -1,  1462,    18,  1461,    -1,  1462,    19,  1461,    -1,   588,
     430,  1368,  1461,   391,    -1,   600,   430,  1368,  1461,   391,
      -1,   601,   430,  1368,  1461,   391,    -1,   608,   430,  1368,
    1461,   391,    -1,   495,   430,  1368,  1461,   391,    -1,   939,
     430,  1465,   391,    -1,   537,   430,  1465,   391,    -1,   430,
    1461,   391,    -1,   443,   430,  1443,   391,    -1,  1470,    -1,
    1461,    -1,  1465,     5,  1461,    -1,  1467,    -1,   190,  1468,
      -1,  1468,    -1,  1101,    -1,   939,    -1,  1468,   619,  1469,
      -1,    25,   619,  1468,   619,  1469,    -1,    20,    -1,  1122,
      -1,   939,    -1,  1467,    -1,  1467,   420,  1467,    -1,   126,
    1472,    -1,   130,  1472,    -1,   125,  1472,    -1,    46,    -1,
     165,  1472,    -1,   123,  1472,    -1,    47,    -1,   148,  1472,
      -1,   147,  1472,    -1,   122,  1472,    -1,   355,    -1,   620,
     625,  1473,    -1,   547,  1473,    -1,   572,    -1,   533,  1474,
      -1,   939,    -1,   589,   939,    -1,   939,    -1,    -1,    -1,
     526,  1476,   846,  1477,  1491,   325,    -1,    -1,   658,  1481,
      -1,    -1,   661,    -1,   181,    -1,   277,   934,    -1,    69,
     934,    -1,   307,    -1,   306,    -1,   308,   936,  1478,  1479,
      -1,   492,  1481,  1479,    -1,   931,    -1,  1481,     5,   931,
      -1,   102,    -1,   132,   934,    -1,   846,   566,     5,   846,
     392,    -1,   508,   846,    -1,   264,   934,    -1,   101,  1486,
       8,  1487,  1485,    -1,    -1,   546,   846,    -1,   939,    -1,
     939,    -1,   247,   934,    -1,   250,   934,   625,   846,     5,
     846,    -1,   250,   934,   618,   846,     5,   846,    -1,    27,
      -1,    -1,  1493,    -1,  1494,  1199,    -1,  1492,    -1,  1493,
    1492,    -1,    -1,  1495,  1496,    -1,   670,    -1,   671,    -1,
     672,    -1,   673,    -1,   690,    -1,   712,    -1,   726,    -1,
     727,    -1,   733,    -1,   734,    -1,   753,    -1,   821,    -1,
     822,    -1,   823,    -1,   824,    -1,   835,    -1,   836,    -1,
     837,    -1,   838,    -1,   890,    -1,   894,    -1,   925,    -1,
     946,    -1,   947,    -1,   950,    -1,   951,    -1,   952,    -1,
     953,    -1,   966,    -1,   975,    -1,   996,    -1,   997,    -1,
     999,    -1,  1003,    -1,  1018,    -1,  1019,    -1,  1023,    -1,
    1024,    -1,  1025,    -1,  1026,    -1,  1034,    -1,  1049,    -1,
    1062,    -1,  1073,    -1,  1074,    -1,  1075,    -1,  1086,    -1,
    1125,    -1,  1128,    -1,  1130,    -1,  1136,    -1,  1137,    -1,
    1140,    -1,  1143,    -1,  1146,    -1,  1148,    -1,  1150,    -1,
    1153,    -1,  1160,    -1,  1165,    -1,  1169,    -1,  1170,    -1,
    1171,    -1,  1183,    -1,  1235,    -1,  1236,    -1,  1238,    -1,
    1250,    -1,  1251,    -1,  1269,    -1,  1272,    -1,  1302,    -1,
    1304,    -1,  1393,    -1,  1394,    -1,  1425,    -1,  1426,    -1,
    1444,    -1,  1471,    -1,  1475,    -1,  1480,    -1,  1482,    -1,
    1484,    -1,  1488,    -1,  1489,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   932,   932,   935,   938,   944,   950,   957,   961,   961,
     967,   990,   991,   992,   993,   994,  1008,  1009,  1010,  1011,
    1012,  1017,  1018,  1029,  1032,  1035,  1035,  1039,  1042,  1043,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1068,  1069,  1072,
    1072,  1087,  1088,  1091,  1097,  1099,  1110,  1112,  1114,  1116,
    1120,  1122,  1184,  1188,  1192,  1192,  1202,  1206,  1209,  1210,
    1217,  1223,  1217,  1236,  1241,  1245,  1236,  1257,  1261,  1257,
    1269,  1274,  1269,  1293,  1300,  1304,  1292,  1330,  1330,  1334,
    1335,  1336,  1341,  1344,  1349,  1353,  1361,  1364,  1364,  1370,
    1374,  1389,  1387,  1405,  1405,  1420,  1420,  1423,  1423,  1427,
    1430,  1430,  1430,  1437,  1438,  1437,  1445,  1445,  1456,  1456,
    1475,  1478,  1481,  1484,  1487,  1490,  1503,  1508,  1508,  1509,
    1509,  1512,  1517,  1517,  1521,  1531,  1545,  1549,  1544,  1559,
    1565,  1573,  1574,  1577,  1577,  1580,  1584,  1589,  1596,  1596,
    1600,  1600,  1607,  1607,  1612,  1612,  1617,  1617,  1622,  1622,
    1635,  1636,  1644,  1645,  1662,  1665,  1668,  1671,  1674,  1677,
    1683,  1694,  1699,  1712,  1716,  1731,  1732,  1736,  1736,  1740,
    1740,  1740,  1741,  1742,  1747,  1747,  1750,  1750,  1759,  1760,
    1761,  1764,  1768,  1769,  1769,  1786,  1786,  1786,  1786,  1790,
    1797,  1798,  1801,  1801,  1804,  1804,  1813,  1810,  1826,  1826,
    1828,  1828,  1830,  1832,  1834,  1836,  1839,  1843,  1843,  1844,
    1844,  1848,  1848,  1860,  1860,  1865,  1869,  1871,  1872,  1875,
    1875,  1875,  1879,  1880,  1881,  1882,  1889,  1890,  1891,  1892,
    1895,  1896,  1897,  1898,  1902,  1907,  1912,  1916,  1919,  1923,
    1924,  1925,  1926,  1927,  1928,  1929,  1930,  1933,  1934,  1935,
    1967,  1971,  1973,  1975,  1975,  1982,  1986,  1986,  1990,  1991,
    1992,  1993,  1994,  1995,  1996,  2002,  2002,  2005,  2007,  2013,
    2015,  2021,  2029,  2029,  2032,  2033,  2034,  2035,  2036,  2037,
    2038,  2044,  2047,  2047,  2060,  2060,  2067,  2068,  2069,  2071,
    2072,  2074,  2076,  2077,  2078,  2079,  2084,  2090,  2096,  2097,
    2099,  2101,  2102,  2103,  2104,  2105,  2106,  2109,  2110,  2117,
    2125,  2125,  2133,  2130,  2145,  2145,  2147,  2147,  2155,  2155,
    2158,  2161,  2162,  2167,  2179,  2183,  2186,  2189,  2190,  2191,
    2192,  2193,  2198,  2205,  2211,  2216,  2220,  2216,  2231,  2233,
    2238,  2243,  2243,  2247,  2247,  2250,  2250,  2256,  2256,  2262,
    2262,  2278,  2281,  2295,  2297,  2299,  2301,  2303,  2305,  2307,
    2313,  2315,  2319,  2321,  2323,  2325,  2327,  2329,  2331,  2337,
    2352,  2355,  2368,  2369,  2370,  2371,  2372,  2376,  2377,  2378,
    2382,  2387,  2394,  2395,  2396,  2397,  2398,  2399,  2400,  2401,
    2402,  2403,  2404,  2411,  2411,  2416,  2416,  2419,  2425,  2433,
    2439,  2449,  2450,  2458,  2465,  2469,  2479,  2483,  2488,  2493,
    2495,  2505,  2518,  2526,  2539,  2544,  2550,  2555,  2560,  2561,
    2567,  2638,  2644,  2649,  2657,  2657,  2672,  2676,  2683,  2686,
    2694,  2705,  2715,  2721,  2730,  2735,  2743,  2746,  2749,  2754,
    2761,  2766,  2771,  2776,  2786,  2794,  2802,  2807,  2811,  2816,
    2820,  2824,  2831,  2834,  2837,  2841,  2845,  2849,  2853,  2861,
    2871,  2876,  2869,  2892,  2897,  2892,  2914,  2914,  2914,  2917,
    2917,  2917,  2921,  2921,  2921,  2925,  2925,  2925,  2929,  2935,
    2941,  2947,  2957,  2957,  2961,  2965,  2966,  2977,  2978,  2984,
    2994,  3004,  3014,  3015,  3018,  3023,  3029,  3033,  3037,  3040,
    3046,  3049,  3052,  3069,  3072,  3078,  3079,  3080,  3084,  3085,
    3086,  3087,  3088,  3090,  3091,  3092,  3094,  3095,  3099,  3100,
    3105,  3106,  3118,  3122,  3117,  3130,  3133,  3147,  3151,  3157,
    3146,  3170,  3171,  3183,  3189,  3183,  3203,  3203,  3205,  3206,
    3210,  3210,  3214,  3214,  3219,  3219,  3226,  3227,  3231,  3231,
    3235,  3235,  3240,  3240,  3247,  3251,  3252,  3253,  3258,  3258,
    3261,  3261,  3265,  3265,  3269,  3269,  3273,  3273,  3278,  3278,
    3283,  3283,  3288,  3288,  3293,  3293,  3309,  3326,  3327,  3328,
    3329,  3330,  3331,  3332,  3335,  3335,  3338,  3340,  3343,  3346,
    3348,  3349,  3350,  3352,  3354,  3356,  3358,  3362,  3369,  3371,
    3377,  3382,  3387,  3392,  3392,  3395,  3401,  3406,  3409,  3416,
    3416,  3418,  3419,  3421,  3423,  3425,  3427,  3431,  3440,  3440,
    3502,  3514,  3521,  3521,  3525,  3530,  3536,  3540,  3544,  3550,
    3554,  3558,  3564,  3564,  3572,  3573,  3577,  3577,  3581,  3582,
    3585,  3588,  3588,  3591,  3593,  3593,  3596,  3598,  3598,  3599,
    3601,  3601,  3610,  3614,  3608,  3636,  3636,  3636,  3639,  3641,
    3639,  3648,  3651,  3657,  3668,  3668,  3672,  3678,  3678,  3682,
    3683,  3694,  3695,  3697,  3699,  3704,  3704,  3708,  3707,  3714,
    3713,  3719,  3719,  3724,  3724,  3730,  3730,  3735,  3735,  3740,
    3740,  3745,  3745,  3748,  3748,  3751,  3751,  3754,  3754,  3796,
    3797,  3805,  3806,  3815,  3820,  3825,  3826,  3827,  3831,  3830,
    3841,  3846,  3851,  3851,  3867,  3873,  3874,  3875,  3876,  3879,
    3879,  3882,  3889,  3890,  3891,  3892,  3893,  3894,  3895,  3896,
    3897,  3902,  3902,  3904,  3907,  3907,  3909,  3913,  3916,  3917,
    3920,  3920,  3925,  3928,  3929,  3930,  3931,  3932,  3933,  3934,
    3935,  3936,  3937,  3938,  3939,  3940,  3941,  3942,  3943,  3944,
    3945,  3949,  3967,  3967,  3967,  3994,  4005,  4012,  4018,  4024,
    4030,  4041,  4064,  4063,  4080,  4080,  4084,  4085,  4093,  4094,
    4095,  4096,  4103,  4104,  4106,  4107,  4111,  4116,  4117,  4118,
    4119,  4120,  4121,  4122,  4123,  4124,  4125,  4126,  4129,  4129,
    4131,  4131,  4131,  4133,  4137,  4137,  4146,  4151,  4167,  4173,
    4145,  4187,  4201,  4211,  4200,  4224,  4231,  4231,  4236,  4242,
    4250,  4255,  4256,  4259,  4259,  4259,  4262,  4262,  4270,  4276,
    4290,  4294,  4307,  4289,  4325,  4325,  4339,  4350,  4349,  4361,
    4357,  4374,  4371,  4384,  4384,  4386,  4387,  4389,  4390,  4393,
    4394,  4395,  4397,  4402,  4407,  4413,  4415,  4416,  4419,  4420,
    4423,  4425,  4434,  4440,  4434,  4451,  4452,  4456,  4456,  4466,
    4466,  4478,  4481,  4484,  4487,  4491,  4495,  4496,  4497,  4498,
    4499,  4503,  4508,  4508,  4511,  4537,  4596,  4596,  4599,  4603,
    4607,  4650,  4692,  4693,  4694,  4697,  4711,  4723,  4723,  4728,
    4729,  4735,  4795,  4852,  4857,  4864,  4869,  4877,  4883,  4917,
    4920,  4921,  4962,  5005,  5006,  5010,  5011,  5015,  5068,  5072,
    5075,  5081,  5092,  5099,  5107,  5107,  5110,  5111,  5112,  5113,
    5114,  5117,  5120,  5126,  5129,  5133,  5137,  5144,  5149,  5156,
    5159,  5165,  5167,  5167,  5167,  5171,  5191,  5198,  5205,  5208,
    5222,  5229,  5230,  5233,  5234,  5238,  5244,  5249,  5255,  5256,
    5261,  5265,  5265,  5269,  5270,  5273,  5274,  5278,  5286,  5289,
    5295,  5296,  5298,  5300,  5304,  5304,  5305,  5310,  5318,  5319,
    5324,  5325,  5327,  5340,  5342,  5343,  5345,  5348,  5351,  5354,
    5358,  5361,  5364,  5368,  5372,  5376,  5379,  5383,  5386,  5387,
    5388,  5391,  5394,  5397,  5400,  5403,  5406,  5409,  5425,  5433,
    5433,  5435,  5442,  5449,  5464,  5462,  5481,  5482,  5486,  5491,
    5492,  5496,  5497,  5499,  5500,  5502,  5502,  5510,  5519,  5519,
    5529,  5530,  5533,  5534,  5537,  5541,  5555,  5560,  5565,  5570,
    5580,  5580,  5584,  5587,  5587,  5589,  5599,  5608,  5615,  5617,
    5621,  5624,  5624,  5628,  5627,  5634,  5633,  5640,  5639,  5646,
    5645,  5649,  5648,  5651,  5651,  5667,  5666,  5688,  5689,  5690,
    5691,  5692,  5693,  5696,  5696,  5702,  5702,  5705,  5705,  5718,
    5719,  5720,  5729,  5741,  5742,  5745,  5746,  5749,  5752,  5752,
    5757,  5772,  5777,  5783,  5784,  5785,  5789,  5790,  5791,  5792,
    5796,  5806,  5808,  5813,  5816,  5821,  5827,  5834,  5841,  5850,
    5857,  5864,  5871,  5878,  5887,  5887,  5889,  5889,  5892,  5893,
    5894,  5895,  5896,  5897,  5898,  5899,  5900,  5901,  5904,  5904,
    5907,  5908,  5909,  5910,  5913,  5913,  5916,  5916,  5919,  5920,
    5921,  5922,  5923,  5924,  5925,  5926,  5928,  5929,  5930,  5931,
    5933,  5934,  5935,  5936,  5938,  5939,  5940,  5941,  5942,  5943,
    5944,  5945,  5949,  5956,  5965,  5977,  5986,  5997,  6001,  6005,
    6011,  5976,  6024,  6027,  6035,  6047,  6049,  6054,  6062,  6072,
    6075,  6079,  6087,  6053,  6096,  6100,  6104,  6108,  6100,  6118,
    6119,  6120,  6121,  6126,  6128,  6131,  6135,  6138,  6145,  6150,
    6151,  6152,  6157,  6158,  6164,  6164,  6164,  6169,  6169,  6169,
    6180,  6181,  6187,  6188,  6200,  6201,  6206,  6207,  6208,  6212,
    6215,  6221,  6224,  6232,  6233,  6239,  6246,  6249,  6258,  6261,
    6264,  6267,  6270,  6273,  6276,  6283,  6286,  6293,  6296,  6302,
    6305,  6312,  6315,  6322,  6323,  6328,  6332,  6335,  6341,  6344,
    6350,  6357,  6358,  6362,  6368,  6371,  6378,  6379,  6386,  6389,
    6394,  6405,  6406,  6407,  6408,  6409,  6410,  6411,  6412,  6413,
    6416,  6419,  6425,  6425,  6431,  6431,  6442,  6455,  6465,  6465,
    6470,  6470,  6474,  6478,  6479,  6485,  6486,  6491,  6495,  6502,
    6505,  6512,  6516,  6511,  6525,  6529,  6533,  6540,  6544,  6544,
    6557,  6561,  6561,  6576,  6578,  6580,  6582,  6584,  6586,  6588,
    6590,  6596,  6606,  6613,  6618,  6619,  6623,  6625,  6626,  6629,
    6630,  6631,  6634,  6639,  6646,  6647,  6653,  6665,  6666,  6669,
    6669,  6674,  6679,  6684,  6685,  6688,  6689,  6694,  6699,  6703,
    6708,  6709,  6713,  6720,  6724,  6725,  6730,  6732,  6736,  6737,
    6741,  6742,  6743,  6744,  6748,  6749,  6754,  6755,  6760,  6761,
    6766,  6767,  6772,  6777,  6778,  6783,  6784,  6788,  6789,  6794,
    6801,  6806,  6811,  6815,  6816,  6821,  6822,  6828,  6830,  6835,
    6836,  6842,  6845,  6848,  6855,  6857,  6871,  6876,  6877,  6880,
    6882,  6889,  6892,  6898,  6902,  6906,  6910,  6913,  6920,  6927,
    6932,  6936,  6937,  6943,  6946,  6957,  6964,  6970,  6973,  6980,
    6987,  6993,  6994,  7000,  7001,  7002,  7005,  7006,  7011,  7011,
    7015,  7023,  7024,  7027,  7030,  7035,  7036,  7041,  7044,  7050,
    7053,  7059,  7062,  7068,  7071,  7078,  7079,  7108,  7109,  7114,
    7122,  7127,  7130,  7133,  7136,  7142,  7143,  7147,  7150,  7153,
    7154,  7159,  7162,  7165,  7168,  7171,  7174,  7177,  7183,  7184,
    7185,  7186,  7187,  7189,  7191,  7192,  7197,  7200,  7204,  7210,
    7211,  7212,  7213,  7225,  7226,  7227,  7231,  7232,  7237,  7239,
    7240,  7241,  7243,  7244,  7245,  7246,  7248,  7249,  7251,  7252,
    7254,  7255,  7256,  7257,  7259,  7263,  7264,  7270,  7272,  7273,
    7274,  7275,  7280,  7284,  7288,  7292,  7293,  7297,  7298,  7308,
    7317,  7318,  7319,  7323,  7326,  7331,  7336,  7341,  7349,  7353,
    7357,  7358,  7359,  7364,  7367,  7370,  7384,  7398,  7411,  7412,
    7416,  7416,  7416,  7416,  7416,  7416,  7417,  7420,  7425,  7425,
    7425,  7425,  7425,  7425,  7427,  7430,  7436,  7436,  7436,  7436,
    7436,  7436,  7436,  7437,  7437,  7437,  7437,  7437,  7437,  7437,
    7439,  7440,  7443,  7452,  7452,  7458,  7458,  7465,  7465,  7471,
    7471,  7479,  7480,  7481,  7484,  7484,  7487,  7488,  7489,  7494,
    7497,  7503,  7508,  7516,  7529,  7530,  7527,  7548,  7558,  7561,
    7566,  7578,  7581,  7585,  7588,  7589,  7595,  7598,  7599,  7608,
    7617,  7622,  7623,  7624,  7625,  7632,  7635,  7641,  7644,  7654,
    7663,  7666,  7669,  7675,  7681,  7684,  7687,  7690,  7696,  7698,
    7700,  7702,  7704,  7706,  7707,  7708,  7709,  7710,  7711,  7712,
    7714,  7716,  7718,  7720,  7722,  7724,  7726,  7727,  7732,  7733,
    7740,  7743,  7752,  7756,  7763,  7763,  7767,  7767,  7772,  7772,
    7776,  7776,  7780,  7786,  7786,  7789,  7789,  7795,  7802,  7803,
    7804,  7808,  7809,  7812,  7813,  7817,  7823,  7833,  7834,  7842,
    7843,  7844,  7845,  7846,  7847,  7851,  7852,  7853,  7857,  7857,
    7869,  7870,  7874,  7875,  7876,  7880,  7886,  7973,  7977,  7973,
    7986,  7990,  7996,  8004,  8014,  8024,  8036,  8039,  8058,  8084,
    8087,  8093,  8096,  8101,  8104,  8112,  8120,  8133,  8136,  8144,
    8147,  8150,  8158,  8162,  8165,  8168,  8171,  8175,  8176,  8177,
    8178,  8179,  8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,
    8193,  8194,  8195,  8196,  8197,  8198,  8202,  8208,  8209,  8221,
    8242,  8242,  8246,  8247,  8248,  8249,  8253,  8254,  8255,  8260,
    8286,  8337,  8339,  8341,  8343,  8347,  8352,  8354,  8357,  8359,
    8361,  8365,  8368,  8373,  8378,  8382,  8391,  8392,  8396,  8408,
    8411,  8407,  8430,  8430,  8434,  8435,  8438,  8439,  8440,  8441,
    8442,  8443,  8444,  8449,  8450,  8454,  8457,  8462,  8466,  8471,
    8475,  8480,  8484,  8487,  8491,  8494,  8499,  8503,  8514,  8520,
    8520,  8521,  8522,  8529,  8538,  8538,  8540,  8541,  8542,  8543,
    8544,  8545,  8546,  8547,  8548,  8549,  8550,  8551,  8552,  8553,
    8554,  8555,  8556,  8557,  8558,  8559,  8560,  8561,  8562,  8563,
    8564,  8565,  8566,  8567,  8568,  8569,  8570,  8571,  8572,  8573,
    8574,  8575,  8576,  8577,  8578,  8579,  8580,  8581,  8582,  8583,
    8584,  8585,  8586,  8587,  8588,  8589,  8590,  8591,  8592,  8593,
    8594,  8595,  8596,  8597,  8598,  8599,  8600,  8601,  8602,  8603,
    8604,  8605,  8606,  8607,  8608,  8609,  8610,  8611,  8612,  8613,
    8614,  8615,  8616,  8617,  8618,  8619,  8620,  8621,  8622,  8623,
    8624
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
  "NEXTFORM", "RENTAB", "ASCENDING", "ASSOCIATE", "CHARACTER", 
  "CONSTRUCT", "DELIMITER", "DOWNSHIFT", "DROP_VIEW", "END_INPUT", 
  "END_WHILE", "EXCLUSIVE", "EXIT_CASE", "EXIT_MENU", "FORM_LINE", 
  "INTERRUPT", "INTO_TEMP", "INVISIBLE", "IN_MEMORY", "LINKED_TO", 
  "LOAD_FROM", "LOCKTAB", "MENU_LINE", "OPEN_FORM", "OTHERWISE", 
  "PRECISION", "PRIOR", "PROCEDURE", "REPORT_TO", "RETURNING", 
  "UNDERLINE", "UNLOAD_TO", "BEFROW", "UNLOAD_T", "VARIABLE", "ABSOLUTE", 
  "AFTROW", "BUFFERED", "CONSTANT", "CONST", "CONTINUE", "DATABASE", 
  "DATETIME", "DEFAULTS", "DISTINCT", "END_CASE", "END_MAIN", "END_MENU", 
  "END_TYPE", "EXIT_FOR", "EXTERNAL", "FRACTION", "FUNCTION", "GROUP_BY", 
  "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_NULL", "PASSWORD", "PREVIOUS", 
  "READONLY", "REGISTER", "RELATIVE", "RESOURCE", "SMALLINT", "VALIDATE", 
  "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", "IN_FILE", "IS_NULL", 
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
  "BOLD", "BYTE", "FCALL", "CASE", "CHAR", "CYAN", "DATE", "DESC", 
  "KWDOWN", "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
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
  "OFF", "$accept", "pause_screen_on_cmd", "pause_screen_off_cmd", 
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
  "op_def_but", "if_cmd", "@83", "@84", "op_else", "@85", "@86", "@87", 
  "import_m", "module_import", "init_cmd", "@88", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", 
  "@99", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@100", "inp_rest", "@101", 
  "scroll_cmd", "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@102", "key_val", 
  "@103", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@104", "@105", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@106", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@107", "@108", "@109", "@110", 
  "end_func_command", "main_def", "@111", "@112", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@113", 
  "glob_section", "mem_func_def", "@114", "@115", "@116", "menu_cmd", 
  "@117", "end_menu_command", "menu_block_command", "@118", "@119", 
  "@120", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@121", "@122", "menu_handler_elements", 
  "menu_handler_element", "@123", "@124", "message_cmd", "msg_next", 
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
  "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", "@125", 
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@126", "prompt_title", 
  "put_cmd", "@127", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@128", "@129", "@130", "@131", "@132", "@133", "@134", 
  "report_cmd", "need_command", "@135", "op_lines", "skip_command", 
  "@136", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
  "opt_print_at", "print_command", "print_file_command", 
  "print_img_command", "opt_scaling", "img_types", "blob_var", "opt_semi", 
  "rep_expr_list", "rep_expr", "rep_agg", "op_output_section", 
  "output_commands", "output_command", "pdf_output_commands", "nval", 
  "nval_number", "pdf_op_output_section", "pdf_output_command", 
  "op_rep_order_by", "report_def", "@137", "@138", "@139", "@140", "@141", 
  "@142", "rep_where", "pause_command", "pause_msg", "pdf_report_def", 
  "@143", "@144", "@145", "@146", "@147", "@148", "pdf_report_section", 
  "pdf_functions", "@149", "@150", "@151", "op_wordwrap", "run_cmd", 
  "drops_cmd", "drops_c", "create_cmd", "create_c_2_ss", "@152", "@153", 
  "@154", "@155", "create_c_1", "op_no_log", "idx_column_list", 
  "idx_column", "table_element_list_ss", "table_element_ss", 
  "upd_stats_cmd", "alter_cmd", "alter_clauses_ss", "alter_clause_ss", 
  "alter_add_clause_ss", "add_column_clause_ss", "add_column_clauses_ss", 
  "alter_drop_clause", "drop_column_list", "drop_column", 
  "alter_modify_clause", "modify_column_clauses_ss", 
  "modify_column_clause_ss", "alter_lock_mode", "alter_modify_next", 
  "alter_add_constraint_clause", "alter_drop_contraint_clause", 
  "column_constraints_ss", "constraint_name", "set_cmd", "op_conn_id", 
  "op_fgl_expr", "sleep_cmd", "rollback_statement", "insert_statement_ss", 
  "@156", "ins_2_ss", "@157", "op_insert_column_list", 
  "insert_column_list", "insert_value_list_ss", "insert_value_ss", 
  "fetch_statement", "@158", "@159", "declare_cursor_name", "fetch_part", 
  "opt_into_fetch_part", "@160", "opt_foreach_into_fetch_part", "@161", 
  "fetch_place", "delete_statement_position", 
  "delete_statement_search_ss", "order_by_clause", 
  "sort_specification_list", "sort_specification", "sort_spec", 
  "op_asc_desc", "begin_statement", "commit_statement", "op_exclusive", 
  "set_database_cmd", "var_ident_qchar", "sql_cmd", "@162", 
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
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@163", 
  "@164", "@165", "@166", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@167", "@168", 
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
  "units_qual", "extend_qual_ss", "sql_block_cmd", "@169", "sql_block", 
  "sql_block_entry", "in_var", "sql_block_into", "update_statement_ss", 
  "@170", "@171", "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "upd_value_expression_ss", 
  "upd_value_expression_initial_ss", "upd_value_expression_complex_ss", 
  "upd_var_ident_ibind_ss", "upd_value_expr_list_ss", "var_ident", "var2", 
  "var3", "aft_dot", "var_ident_ibind_ss", "whenever_cmd", "when_do", 
  "label_goto", "function_name_when", "while_cmd", "@172", "@173", 
  "op_clr_fields", "op_to_defs", "clear_cmd", "fld_list", 
  "current_win_cmd", "window_type", "show_cmd", "op_mnfile", "menu_name", 
  "menu_handler", "hide_cmd", "move_cmd", "NAMED", "commands", 
  "all_commands", "command1", "commands_all", "@174", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1654,  1655,  1656,  1569,  1609,  1564,  1500,  1584,
    1379,  1486,  1482,  1397,  1559,  1296,  1354,  1428,  1595,  1582,
    1487,  1515,  1583,  1361,  1657,  1658,  1659,  1660,  1661,  1662,
    1663,  1664,  1665,  1666,  1000,  1001,  1002,  1003,  1004,  1005,
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
    1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1355,  1356,  1357,
    1358,  1359,  1360,  1362,  1363,  1364,  1365,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1380,  1381,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1429,  1430,  1431,
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
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   669,   670,   671,   672,   673,   674,   674,   675,   675,
     676,   677,   677,   677,   677,   677,   678,   678,   678,   678,
     678,   679,   679,   680,   680,   682,   681,   681,   683,   683,
     684,   684,   684,   684,   684,   684,   684,   684,   684,   684,
     684,   684,   684,   684,   684,   684,   684,   685,   685,   687,
     686,   688,   688,   689,   689,   689,   689,   689,   689,   689,
     689,   689,   690,   691,   692,   691,   691,   691,   691,   691,
     693,   694,   691,   695,   696,   697,   691,   698,   699,   691,
     700,   701,   691,   702,   703,   704,   691,   705,   705,   706,
     706,   706,   707,   707,   708,   708,   709,   710,   710,   711,
     711,   713,   712,   714,   712,   715,   715,   716,   716,   717,
     718,   719,   718,   720,   721,   720,   723,   722,   725,   724,
     726,   726,   726,   726,   726,   726,   727,   728,   728,   729,
     729,   730,   731,   731,   732,   733,   735,   736,   734,   737,
     737,   738,   738,   739,   739,   740,   740,   740,   741,   741,
     743,   742,   744,   742,   745,   742,   746,   742,   747,   742,
     748,   748,   749,   749,   750,   750,   750,   750,   750,   750,
     751,   752,   752,   753,   753,   754,   754,   755,   755,   757,
     758,   756,   756,   756,   759,   759,   761,   760,   762,   762,
     762,   762,   762,   763,   762,   764,   764,   764,   764,   765,
     766,   766,   767,   767,   769,   768,   770,   768,   771,   771,
     772,   772,   773,   774,   774,   774,   775,   777,   776,   778,
     776,   779,   776,   780,   780,   781,   782,   783,   783,   785,
     786,   784,   787,   787,   787,   787,   787,   787,   787,   787,
     787,   787,   787,   787,   787,   787,   787,   787,   787,   787,
     787,   787,   787,   787,   787,   787,   787,   787,   787,   787,
     788,   789,   790,   791,   791,   792,   794,   793,   795,   795,
     795,   795,   795,   795,   795,   797,   796,   798,   798,   799,
     799,   800,   802,   801,   803,   803,   803,   803,   803,   803,
     803,   804,   805,   805,   807,   806,   808,   808,   808,   808,
     808,   808,   808,   808,   808,   808,   808,   808,   808,   808,
     808,   808,   808,   808,   808,   808,   808,   808,   808,   809,
     811,   810,   812,   810,   814,   813,   815,   813,   816,   816,
     817,   818,   818,   819,   820,   820,   820,   820,   820,   820,
     820,   820,   821,   822,   823,   825,   826,   824,   827,   827,
     828,   829,   829,   830,   830,   832,   831,   833,   831,   834,
     831,   835,   835,   836,   836,   836,   836,   836,   836,   836,
     836,   836,   837,   837,   837,   837,   837,   837,   837,   837,
     838,   838,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   840,   840,   840,   840,   840,   840,   840,   840,
     840,   840,   840,   841,   841,   842,   842,   843,   843,   844,
     844,   845,   845,   846,   847,   847,   848,   848,   848,   848,
     848,   848,   849,   849,   850,   850,   850,   850,   851,   851,
     852,   853,   853,   853,   854,   853,   855,   855,   856,   856,
     857,   857,   857,   857,   858,   858,   859,   859,   859,   859,
     859,   859,   859,   859,   860,   861,   862,   862,   862,   862,
     862,   862,   863,   863,   863,   863,   863,   863,   863,   864,
     866,   867,   865,   868,   869,   865,   871,   872,   870,   873,
     874,   870,   875,   876,   870,   877,   878,   870,   870,   870,
     870,   870,   879,   879,   880,   881,   881,   881,   881,   881,
     881,   881,   881,   881,   882,   882,   883,   883,   883,   883,
     884,   884,   884,   885,   885,   886,   886,   886,   887,   887,
     887,   887,   887,   887,   887,   887,   887,   887,   888,   888,
     889,   889,   891,   892,   890,   893,   893,   895,   896,   897,
     894,   898,   898,   900,   901,   899,   902,   902,   903,   903,
     904,   904,   906,   905,   907,   905,   908,   908,   909,   909,
     911,   910,   912,   910,   913,   914,   914,   914,   915,   915,
     916,   916,   917,   917,   918,   918,   920,   919,   921,   919,
     922,   919,   923,   919,   924,   919,   925,   926,   926,   926,
     926,   926,   926,   926,   927,   927,   928,   929,   930,   931,
     931,   931,   931,   931,   931,   931,   931,   932,   933,   934,
     935,   936,   937,   938,   938,   939,   940,   941,   941,   942,
     942,   943,   943,   943,   943,   943,   943,   944,   945,   945,
     946,   947,   948,   948,   949,   950,   951,   951,   951,   952,
     952,   952,   954,   953,   955,   955,   956,   956,   957,   957,
     958,   959,   959,   960,   961,   961,   962,   963,   963,   964,
     965,   965,   967,   968,   966,   969,   970,   969,   971,   972,
     969,   973,   973,   974,   976,   975,   975,   977,   977,   978,
     978,   979,   979,   980,   980,   981,   981,   983,   982,   984,
     982,   985,   982,   986,   982,   987,   982,   988,   982,   989,
     982,   990,   982,   991,   982,   992,   982,   993,   982,   994,
     994,   995,   995,   996,   997,   998,   998,   998,  1000,   999,
    1001,  1001,  1002,  1001,  1003,  1004,  1004,  1004,  1004,  1005,
    1005,  1006,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,
    1007,  1009,  1008,  1008,  1011,  1010,  1012,  1013,  1014,  1014,
    1015,  1015,  1016,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1017,  1018,  1020,  1021,  1019,  1022,  1022,  1023,  1024,  1025,
    1026,  1026,  1028,  1027,  1029,  1029,  1030,  1030,  1031,  1031,
    1031,  1031,  1032,  1032,  1033,  1033,  1034,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1036,  1036,
    1037,  1037,  1037,  1038,  1039,  1039,  1041,  1042,  1043,  1044,
    1040,  1045,  1047,  1048,  1046,  1049,  1050,  1050,  1051,  1051,
    1052,  1053,  1053,  1054,  1054,  1054,  1056,  1055,  1057,  1057,
    1059,  1060,  1061,  1058,  1063,  1062,  1064,  1066,  1065,  1067,
    1065,  1068,  1065,  1069,  1069,  1070,  1070,  1071,  1071,  1072,
    1072,  1072,  1073,  1074,  1075,  1076,  1076,  1076,  1077,  1077,
    1078,  1078,  1080,  1081,  1079,  1082,  1082,  1084,  1083,  1085,
    1083,  1086,  1087,  1087,  1087,  1087,  1088,  1088,  1088,  1088,
    1088,  1089,  1090,  1090,  1091,  1092,  1093,  1093,  1094,  1095,
    1095,  1095,  1095,  1095,  1095,  1096,  1097,  1098,  1098,  1099,
    1099,  1100,  1101,  1102,  1102,  1103,  1103,  1104,  1105,  1106,
    1106,  1106,  1106,  1106,  1106,  1107,  1107,  1108,  1109,  1109,
    1110,  1110,  1111,  1111,  1112,  1112,  1113,  1113,  1113,  1113,
    1113,  1114,  1114,  1115,  1115,  1116,  1116,  1117,  1118,  1119,
    1119,  1120,  1121,  1121,  1121,  1122,  1123,  1123,  1124,  1124,
    1125,  1126,  1126,  1127,  1127,  1128,  1129,  1130,  1131,  1131,
    1132,  1133,  1133,  1134,  1134,  1135,  1135,  1136,  1137,  1137,
    1138,  1138,  1138,  1138,  1139,  1139,  1139,  1140,  1141,  1141,
    1142,  1142,  1142,  1143,  1144,  1144,  1145,  1145,  1145,  1145,
    1145,  1145,  1145,  1145,  1145,  1145,  1145,  1145,  1145,  1145,
    1145,  1145,  1145,  1145,  1145,  1145,  1145,  1145,  1146,  1147,
    1147,  1148,  1148,  1149,  1151,  1150,  1152,  1152,  1153,  1154,
    1154,  1155,  1155,  1156,  1156,  1158,  1157,  1159,  1161,  1160,
    1162,  1162,  1163,  1163,  1164,  1164,  1165,  1165,  1165,  1165,
    1166,  1166,  1167,  1168,  1168,  1169,  1170,  1171,  1172,  1173,
    1173,  1174,  1174,  1176,  1175,  1177,  1175,  1178,  1175,  1179,
    1175,  1180,  1175,  1181,  1175,  1182,  1175,  1183,  1183,  1183,
    1183,  1183,  1183,  1185,  1184,  1186,  1186,  1188,  1187,  1187,
    1187,  1187,  1187,  1189,  1189,  1190,  1190,  1191,  1192,  1192,
    1193,  1194,  1195,  1196,  1196,  1196,  1197,  1197,  1197,  1197,
    1198,  1199,  1199,  1200,  1200,  1201,  1202,  1202,  1202,  1202,
    1202,  1202,  1202,  1202,  1203,  1203,  1204,  1204,  1205,  1205,
    1205,  1205,  1205,  1205,  1205,  1205,  1205,  1205,  1206,  1206,
    1207,  1207,  1207,  1207,  1208,  1208,  1209,  1209,  1210,  1210,
    1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,
    1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,  1210,
    1210,  1210,  1211,  1211,  1211,  1213,  1214,  1215,  1216,  1217,
    1218,  1212,  1219,  1219,  1220,  1221,  1221,  1223,  1224,  1225,
    1226,  1227,  1228,  1222,  1229,  1231,  1232,  1233,  1230,  1234,
    1234,  1234,  1234,  1235,  1235,  1235,  1235,  1235,  1236,  1237,
    1237,  1237,  1238,  1238,  1240,  1241,  1239,  1242,  1243,  1239,
    1244,  1244,  1245,  1245,  1246,  1246,  1247,  1247,  1247,  1248,
    1248,  1249,  1249,  1250,  1250,  1251,  1252,  1252,  1253,  1253,
    1253,  1253,  1253,  1253,  1253,  1254,  1254,  1255,  1255,  1256,
    1256,  1257,  1257,  1258,  1258,  1259,  1260,  1260,  1261,  1261,
    1262,  1263,  1263,  1264,  1265,  1265,  1266,  1266,  1267,  1267,
    1268,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,
    1269,  1269,  1270,  1270,  1271,  1271,  1272,  1273,  1275,  1274,
    1277,  1276,  1276,  1278,  1278,  1279,  1279,  1280,  1280,  1281,
    1281,  1283,  1284,  1282,  1285,  1286,  1286,  1287,  1288,  1287,
    1289,  1290,  1289,  1291,  1291,  1291,  1291,  1291,  1291,  1291,
    1291,  1292,  1293,  1294,  1295,  1295,  1296,  1297,  1297,  1298,
    1298,  1298,  1299,  1300,  1301,  1301,  1302,  1303,  1303,  1305,
    1304,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,  1306,
    1306,  1306,  1306,  1307,  1308,  1308,  1309,  1309,  1310,  1310,
    1311,  1311,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,
    1315,  1315,  1316,  1317,  1317,  1318,  1318,  1319,  1319,  1320,
    1321,  1322,  1323,  1324,  1324,  1325,  1325,  1326,  1326,  1327,
    1327,  1328,  1328,  1328,  1329,  1329,  1330,  1331,  1331,  1332,
    1332,  1333,  1333,  1334,  1334,  1334,  1334,  1334,  1335,  1336,
    1337,  1338,  1338,  1339,  1339,  1340,  1341,  1342,  1342,  1343,
    1344,  1345,  1345,  1346,  1346,  1346,  1347,  1347,  1348,  1348,
    1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,  1353,  1354,
    1354,  1355,  1355,  1356,  1356,  1357,  1357,  1358,  1358,  1359,
    1360,  1361,  1361,  1361,  1361,  1362,  1362,  1363,  1363,  1364,
    1364,  1365,  1365,  1365,  1365,  1365,  1365,  1365,  1366,  1366,
    1366,  1366,  1366,  1366,  1366,  1366,  1367,  1367,  1367,  1368,
    1368,  1368,  1368,  1369,  1369,  1369,  1370,  1370,  1371,  1371,
    1371,  1371,  1371,  1371,  1371,  1371,  1371,  1371,  1371,  1371,
    1371,  1371,  1371,  1371,  1371,  1372,  1372,  1373,  1373,  1373,
    1373,  1373,  1374,  1375,  1376,  1377,  1377,  1377,  1377,  1378,
    1379,  1379,  1379,  1380,  1380,  1381,  1381,  1381,  1382,  1383,
    1383,  1383,  1383,  1383,  1384,  1385,  1386,  1386,  1387,  1387,
    1388,  1388,  1388,  1388,  1388,  1388,  1388,  1388,  1389,  1389,
    1389,  1389,  1389,  1389,  1389,  1389,  1390,  1390,  1390,  1390,
    1390,  1390,  1390,  1391,  1391,  1391,  1391,  1391,  1391,  1391,
    1392,  1392,  1393,  1395,  1394,  1396,  1394,  1397,  1394,  1398,
    1394,  1399,  1399,  1399,  1400,  1400,  1401,  1401,  1401,  1402,
    1402,  1403,  1403,  1404,  1406,  1407,  1405,  1408,  1409,  1409,
    1410,  1411,  1411,  1411,  1411,  1411,  1412,  1413,  1413,  1414,
    1415,  1416,  1416,  1416,  1416,  1417,  1417,  1418,  1418,  1419,
    1420,  1420,  1420,  1421,  1421,  1421,  1421,  1421,  1422,  1422,
    1422,  1422,  1422,  1422,  1422,  1422,  1422,  1422,  1422,  1422,
    1422,  1422,  1422,  1422,  1422,  1422,  1422,  1422,  1423,  1423,
    1424,  1425,  1426,  1426,  1427,  1427,  1428,  1428,  1429,  1429,
    1430,  1430,  1431,  1432,  1432,  1433,  1433,  1434,  1435,  1435,
    1435,  1436,  1436,  1437,  1438,  1439,  1440,  1441,  1441,  1442,
    1442,  1442,  1442,  1442,  1442,  1443,  1443,  1443,  1445,  1444,
    1446,  1446,  1447,  1447,  1447,  1448,  1449,  1451,  1452,  1450,
    1453,  1453,  1453,  1454,  1454,  1454,  1454,  1454,  1454,  1455,
    1455,  1456,  1457,  1458,  1458,  1459,  1459,  1460,  1460,  1461,
    1461,  1461,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1464,  1465,  1465,  1466,
    1467,  1467,  1468,  1468,  1468,  1468,  1469,  1469,  1469,  1470,
    1470,  1471,  1471,  1471,  1471,  1471,  1471,  1471,  1471,  1471,
    1471,  1472,  1472,  1472,  1472,  1472,  1473,  1473,  1474,  1476,
    1477,  1475,  1478,  1478,  1479,  1479,  1480,  1480,  1480,  1480,
    1480,  1480,  1480,  1481,  1481,  1482,  1482,  1483,  1483,  1484,
    1484,  1485,  1485,  1486,  1487,  1488,  1489,  1489,  1490,  1491,
    1491,  1492,  1493,  1493,  1495,  1494,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,
    1496
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
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       4,     6,     4,     3,     6,     3,     6,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     4,     1,
       1,     1,     4,     3,     6,     3,     6,     1,     1,     2,
       2,     2,     1,     3,     1,     2,     2,     2,     4,     2,
       2,     4,     0,     8,     0,     1,     1,     1,     0,     1,
       2,     0,     1,     2,     0,     1,     2,     0,     1,     3,
       0,     2,     0,     0,     8,     0,     0,     3,     0,     0,
       7,     5,     2,     2,     0,     5,     4,     1,     3,     3,
       3,     0,     2,     0,     1,     1,     2,     0,     4,     0,
       4,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     1,
       3,     1,     3,     2,     4,     1,     1,     1,     0,     4,
       5,     6,     0,    10,     3,     2,     2,     1,     1,     0,
       2,     1,     2,     3,     3,     3,     3,     1,     1,     1,
       1,     0,     3,     1,     0,     3,     2,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     1,     1,     2,     2,     2,
       3,     4,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     0,     0,     0,     0,
      13,     1,     0,     0,     6,     2,     1,     2,     2,     2,
       1,     1,     2,     1,     1,     1,     0,     3,     2,     1,
       0,     0,     0,    14,     0,     5,     1,     0,     3,     0,
       7,     0,     5,     1,     2,     0,     1,     1,     1,     0,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     0,     0,     7,     1,     2,     0,     3,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     2,     2,     2,
       5,     8,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     2,     3,     6,     1,     3,     1,     1,     1,
       3,     6,     9,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     4,     1,     3,     1,     3,
       7,     0,     7,     0,     6,     3,     1,     3,     1,     2,
       5,     0,     7,     0,     2,     0,     1,     5,     2,     5,
       0,     5,     6,     4,     0,     1,     1,     4,     0,     2,
       0,     5,     4,     2,     1,     3,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     2,     4,     1,     0,    11,     0,     2,     5,     0,
       1,     0,     2,     1,     2,     0,     3,     1,     0,     4,
       0,     2,     1,     3,     1,     1,     3,     4,     4,     2,
       1,     1,     1,     0,     1,     7,     2,     2,     2,     2,
       2,     1,     2,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     4,     0,     1,     0,     4,     1,
       2,     2,     2,     0,     1,     1,     2,     2,     0,     2,
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
       1,     3,     3,     2,     4,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     0,     0,     7,     0,     0,     8,
       3,     2,     0,     1,     1,     3,     2,     2,     1,     1,
       3,     1,     1,     2,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     3,     1,
       3,     2,     4,     1,     3,     1,     2,     4,     1,     3,
       1,     1,     1,     2,     2,     4,     2,     4,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       6,     6,     0,     1,     0,     1,     2,     1,     0,     5,
       0,     5,     1,     0,     3,     1,     3,     1,     3,     1,
       1,     0,     0,     5,     1,     2,     1,     0,     0,     3,
       0,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     3,     3,     1,     3,     2,     1,     1,     0,
       1,     1,     1,     1,     0,     1,     3,     1,     1,     0,
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
       1,     3,     3,     3,     6,     4,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     1,
       5,     5,     1,     1,     1,     4,     1,     4,     1,     7,
       1,     1,     1,     4,     6,     0,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       0,     3,     5,     1,     2,     2,     4,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     8,     0,     9,     0,     7,     0,
       9,     0,     1,     2,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     2,     0,     0,     8,     5,     1,     1,
       6,     0,     3,     1,     3,     4,     1,     0,     2,     4,
       6,     0,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     2,     4,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     3,
       1,     5,     7,     5,     0,     2,     1,     1,     0,     3,
       1,     3,     1,     1,     1,     0,     3,     1,     1,     1,
       1,     4,     6,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     0,     4,
       1,     2,     1,     1,     1,     2,     2,     0,     0,     6,
       0,     2,     2,     7,     3,     3,     2,     2,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       2,     2,     1,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     3,     2,     3,     3,     3,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     1,     3,     1,
       2,     1,     1,     1,     3,     5,     1,     1,     1,     1,
       3,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     1,     3,     2,     1,     2,     1,     2,     1,     0,
       0,     6,     0,     2,     0,     1,     1,     2,     2,     1,
       1,     4,     3,     1,     3,     1,     2,     5,     2,     2,
       5,     0,     2,     1,     1,     2,     6,     6,     1,     0,
       1,     2,     1,     2,     0,     2,     1,     1,     1,     1,
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
     784,     0,  1764,  1767,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   836,   179,     0,   808,   813,
     177,   182,   788,     0,   782,   785,   786,   789,   791,   835,
     790,   830,   831,   833,   183,   134,   131,     0,   127,   129,
     128,   132,  1808,   673,   615,  1771,     0,     0,  1774,     0,
    1770,  1766,  1763,  1761,  1762,  1769,  1768,  1765,   294,  1571,
    1570,   828,   175,   186,   829,   178,   183,     1,   792,   787,
     834,   832,   809,   126,   130,   133,  1778,  1775,     0,  1776,
    1773,     0,     0,   594,     0,     0,   176,   839,   903,   595,
     837,   627,   895,     0,   896,   904,   902,   186,   180,   199,
       0,   184,   200,   229,     0,   815,  1187,     0,     0,   814,
     135,  1175,   822,     0,     0,   805,   807,   804,   806,   783,
     793,   794,   816,   797,   798,   799,   802,   800,   801,   803,
    1777,  1772,     0,   897,   838,     0,     0,   911,   909,   910,
     899,   898,   292,   186,  1111,   193,   187,   186,   192,   226,
       0,   672,     0,     0,     0,     0,   175,   543,   872,   795,
       0,   326,   312,   202,   263,   282,   303,   305,   302,     0,
     324,     0,   311,   304,   308,   314,   298,   313,   186,   315,
     295,   318,   296,   297,   908,   907,     0,    21,    22,    13,
       0,   917,     0,    15,     0,   915,     0,   293,     0,   185,
    1112,   181,     0,   199,   201,   259,   253,   254,   242,   219,
     250,   202,   221,   263,   282,   240,   243,   238,     0,   217,
       0,   249,   241,   246,   252,   234,   251,   186,   255,   186,
     232,   233,   230,   258,     0,     0,     0,     0,   823,   175,
     175,     0,     0,   203,     0,   316,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,   905,
       0,    16,    17,    18,    19,    20,     0,    14,     0,   913,
       0,   628,   188,   191,     0,   189,   190,     0,   196,   195,
     194,   197,   186,     0,   186,   256,   257,     0,     0,   186,
       0,     0,     0,     0,   239,   227,  1188,     0,     0,  1176,
    1814,   544,   873,   817,     0,   208,   209,     0,   275,   277,
     272,   273,   269,   271,   268,   270,   267,     0,   277,   288,
     289,   285,   287,   284,   286,   279,     0,     0,     0,   328,
       0,   331,   333,   216,     0,   215,     0,     0,   186,    11,
      12,   916,     0,   900,   629,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   228,   231,   928,   671,
     840,   928,     0,  1812,  1814,  1111,  1665,   810,     0,   928,
       0,     0,   264,     0,     0,   274,   291,   265,   290,     0,
     283,     0,   306,     0,   300,     0,   325,     0,   330,   320,
       0,     0,   309,   299,   262,   319,     0,     0,     0,     0,
       0,     0,   244,     0,   236,   218,   204,     0,   247,   235,
     260,   934,     0,   929,   930,   928,     0,   824,  1813,  1811,
       0,     0,     0,     0,     0,     0,     0,     0,  1795,     0,
    1277,  1276,     0,  1278,     0,   376,  1275,  1217,     0,     5,
    1274,   377,   374,     0,   379,   173,   469,  1089,     0,     0,
    1284,   123,   373,   372,  1209,   367,   469,     0,  1234,  1786,
       0,   378,   345,     0,     3,     2,     0,   375,  1214,     0,
       0,   368,   365,   380,     0,     0,     0,     0,  1282,  1272,
     371,     0,     0,     0,     0,     0,     0,     0,     0,  1271,
       0,     0,     0,   174,  1211,   364,   363,     0,     0,  1790,
    1789,     0,     0,     0,   136,  1210,   370,   369,     0,     0,
     366,   469,   469,     0,   537,     0,     0,     0,     0,     0,
       0,   469,   771,  1185,     0,     0,  1093,     0,  1779,     0,
     103,     0,     0,   844,     0,     0,     0,     0,   772,     0,
       0,  1688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   642,     0,     0,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,
    1862,   882,  1863,  1864,  1865,  1866,  1867,  1868,  1869,  1870,
    1871,  1872,  1873,  1874,  1875,  1876,  1877,  1878,  1879,  1080,
    1082,  1077,  1079,  1078,  1081,  1880,  1881,  1208,  1882,  1213,
    1212,  1883,  1884,  1885,  1886,  1887,  1888,  1889,  1890,  1891,
    1892,  1339,  1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,
    1815,   811,   548,   812,     0,   877,     0,   875,     0,   327,
     210,   211,     0,   276,   281,     0,     0,     0,     0,   329,
     332,     0,   214,     0,   914,     0,   220,     0,   186,     0,
       0,     0,     0,     0,  1189,     0,     0,  1177,     0,     0,
    1221,   616,   617,   796,  1052,  1057,  1788,   609,   122,     0,
       0,  1753,  1752,   988,  1749,  1751,  1803,     0,  1228,     0,
    1224,  1233,     7,     0,     6,     0,  1796,  1053,     0,  1145,
    1144,  1092,  1143,  1091,     0,     0,     0,   424,   426,     0,
    1182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1538,     0,     0,     0,   418,     0,     0,     0,     0,
     417,     0,     0,   434,     0,   505,     0,     0,     0,     0,
       0,     0,   413,  1285,     0,   383,   382,   389,   430,   427,
     384,   503,   495,   385,   387,   502,   388,   903,   425,   428,
     433,  1273,   504,   825,   403,  1667,  1279,   124,     0,  1056,
     121,     0,   778,    23,   611,   381,     0,   777,  1049,   779,
       0,  1283,   866,   865,   868,   864,   867,  1805,     0,   862,
       0,   610,   961,   863,  1799,     0,  1787,   120,   958,   674,
     956,     0,   607,  1782,   716,   715,     0,   717,   599,   713,
       0,     0,   971,   612,  1338,  1334,  1337,     0,     0,  1023,
    1021,     0,  1015,  1017,  1016,  1014,  1013,     0,     0,     0,
    1012,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1002,   993,   994,     0,  1037,   411,
      23,  1793,     0,  1784,   125,   608,     0,  1020,  1019,  1186,
    1184,  1110,     0,  1656,  1657,  1111,  1199,  1111,  1094,  1095,
    1098,  1113,  1286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,   903,     0,    68,     0,   101,   586,
     630,     0,  1083,   978,  1087,     0,     0,  1038,  1203,     0,
       0,  1090,   634,   631,   632,     0,   636,   637,     0,   639,
     640,     0,   635,   938,   940,     0,     0,   939,   718,   936,
     683,   932,   894,     0,     0,     0,     0,   646,   647,     0,
       0,   892,   889,   890,   886,   887,   888,   881,   885,   884,
       0,     0,     0,     0,     0,     0,   552,   554,   546,   549,
     550,   879,  1814,   874,   876,   818,     0,   278,   280,   307,
     301,     0,     0,   310,   901,     0,   225,     0,   223,   245,
     237,   229,   248,   935,   175,   931,   841,   175,     0,     0,
       0,  1261,  1262,     0,     0,     0,  1235,  1236,  1238,  1239,
    1240,  1244,  1243,  1241,  1242,     0,     0,  1750,   912,     0,
     990,     0,     0,  1227,  1226,     0,  1220,     0,  1516,  1517,
       0,  1054,     0,    23,  1140,  1142,  1141,   416,   391,   390,
       0,     0,  1117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,  1546,  1544,  1545,  1541,  1543,  1540,  1542,
    1534,     0,     0,     0,     0,     0,   431,     0,     0,   509,
     508,     0,     0,   479,   476,   485,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   510,   511,   512,   445,     0,     0,
     444,   454,     0,     0,   395,     0,     0,   396,   386,   392,
     394,   397,   398,   399,   400,   401,   393,   423,   422,   470,
       0,     0,   406,   407,   404,   405,   948,     0,     0,   350,
      24,   344,     0,     0,  1046,     0,     0,     0,     0,     0,
       0,     0,   965,  1666,     0,     0,   186,     0,     0,     0,
    1784,     0,     0,     0,     0,     0,   137,     0,     0,   975,
     967,   968,   973,  1335,  1336,   891,   409,   334,     0,   538,
     591,   590,   588,   593,   996,   592,  1001,   997,  1000,   770,
     762,   756,   768,   769,   754,   755,   763,   758,   764,   757,
     767,   761,   765,   760,   766,   753,   759,   746,   752,   998,
     999,     0,  1006,  1010,  1003,  1004,  1008,  1009,  1007,  1005,
    1011,     0,   780,     0,     0,     0,     0,     0,     0,   728,
     727,   724,  1785,  1792,    23,  1106,  1107,  1108,  1109,  1103,
    1101,  1200,  1115,  1100,  1096,     0,     0,  1097,  1780,     0,
       0,     0,     0,    97,     0,    98,     0,     0,     0,    73,
       0,     0,     0,   110,   105,     0,   871,     0,   870,     0,
     469,  1085,     0,   923,   924,   947,   918,   919,   773,   945,
    1040,  1205,     0,  1207,  1206,  1692,     0,     0,     0,  1690,
    1693,  1694,   662,     0,     0,     0,   651,   683,   683,   681,
       0,     0,   684,     0,    25,   650,   653,     0,   660,   656,
     893,   883,  1663,  1664,  1654,  1654,  1304,     0,     0,  1572,
       0,   186,  1287,     0,     0,  1288,  1332,   186,     0,  1333,
       0,  1611,     0,  1301,     0,  1350,  1349,  1348,  1346,  1347,
    1345,  1343,  1340,  1414,  1413,  1341,  1342,  1351,  1581,  1344,
    1670,  1669,  1668,  1352,  1814,  1814,   565,   556,   547,     0,
     551,  1814,   878,   175,     0,   321,   213,     0,   186,   222,
     205,  1190,   175,  1178,  1404,     0,  1403,     0,  1405,     0,
    1406,  1264,     0,  1270,  1266,  1263,     0,     0,     0,     0,
       0,     0,  1260,  1256,  1393,  1392,  1391,  1232,  1231,     0,
    1255,  1251,     0,  1247,  1245,     0,   620,     0,   619,     0,
     989,     0,     0,   987,  1756,  1758,  1757,  1754,  1804,  1801,
    1225,     0,     0,     0,  1218,   469,   342,     0,  1183,     0,
       0,     0,     0,  1611,     0,     0,     0,     0,     0,   527,
     513,   518,     0,   514,   517,   516,     0,     0,     0,     0,
       0,     0,   419,     0,   171,     0,   435,     0,     0,     0,
       0,     0,     0,     0,     0,   437,   436,   455,   446,   461,
     464,   465,   462,   468,   467,   466,   456,   457,   458,   459,
     460,   402,   447,   451,   469,   463,   450,   469,    92,     0,
     429,     0,     0,  1215,   980,  1050,  1051,  1048,  1047,     0,
     869,     0,     0,   596,     0,     0,     0,   959,   957,     0,
     676,   677,     0,     0,  1783,  1791,     0,     0,   603,     0,
     605,   714,     0,   141,     0,   969,   976,     0,     0,   984,
       0,   337,     0,     0,     0,     0,    23,  1022,   541,     0,
       0,     0,   747,   748,   995,   781,   412,     0,  1029,  1794,
     725,   726,   361,     0,  1111,     0,  1114,  1099,  1814,     0,
       0,     0,   530,     0,     0,     0,     0,    63,    92,     0,
       0,   116,   111,     0,   106,     0,   113,   107,   855,   847,
     853,     0,  1084,     0,  1086,  1088,     0,     0,   927,     0,
       0,     0,     0,  1039,  1204,  1759,  1695,   943,  1696,   941,
    1689,  1691,  1814,   633,   638,   641,   654,   652,   613,     0,
     703,   701,   707,   705,     0,     0,   699,   743,   697,   693,
     691,   741,   719,     0,   685,   695,   937,   933,     0,     0,
       0,     0,   659,     0,     0,     0,     0,     0,     0,     0,
    1519,     0,  1409,  1410,  1675,  1373,  1431,     0,     0,  1673,
       0,     0,  1613,  1614,  1612,  1594,  1697,     0,  1356,  1362,
    1361,  1360,  1364,     0,  1357,  1358,     0,  1582,  1593,   553,
     555,     0,     0,   568,   560,   562,     0,   557,   558,     0,
       0,   576,   578,     0,     0,   574,   880,   819,   212,     0,
       0,   224,  1146,   842,  1124,  1381,  1383,     0,  1268,     0,
       0,     0,     0,     0,  1258,     0,     0,  1511,  1509,  1496,
    1498,  1494,     0,  1493,     0,  1502,  1489,  1510,     0,  1501,
    1486,  1492,  1508,  1500,  1397,  1483,  1484,  1485,     0,  1253,
    1249,     0,     0,  1237,   618,     0,     0,     0,     0,     0,
    1800,     4,     8,    10,  1515,  1518,     0,   469,   501,   498,
     497,   500,   496,     0,   421,   507,   492,   492,     0,   515,
       0,   519,     0,   282,  1182,     0,  1539,   499,  1182,   506,
     420,   266,     0,  1182,   480,   477,   486,  1182,   483,  1182,
    1182,  1182,     0,     0,     0,     0,     0,     0,     0,     0,
     471,    93,    94,    96,   473,   408,     0,     0,     0,   977,
       0,     0,     0,     0,     0,     0,     0,   186,   675,     0,
     600,   602,     0,     0,   158,   156,     0,     0,   138,     0,
     148,   154,   683,   143,   145,     0,   974,   985,   986,     0,
     410,   336,   341,   598,   335,     0,   338,   343,   469,  1310,
     589,   587,     0,   750,  1028,  1030,     0,   362,  1104,  1102,
    1201,  1202,     0,     0,  1195,     0,     0,     0,     0,    99,
       0,     0,    74,    80,    70,  1814,  1814,   109,   104,   118,
     114,     0,   108,   744,   856,   613,  1814,   846,   845,   854,
     979,     0,     0,   925,   926,   920,   946,   469,     0,     0,
    1637,  1529,  1532,  1638,  1536,  1530,  1635,     0,     0,  1045,
    1634,     0,     0,  1636,     0,     0,     0,     0,     0,  1753,
    1531,  1041,  1042,  1633,  1533,  1625,  1044,  1620,  1623,  1624,
       0,     0,     0,   663,   657,   655,     0,    23,     0,  1814,
    1814,  1814,  1814,   709,   687,   711,   689,  1814,  1814,  1814,
    1814,     0,   682,   686,  1814,   613,   739,   737,   740,   738,
       0,     0,    45,    43,    40,    34,    38,    42,    37,    30,
      39,     0,    33,    36,    31,    41,    32,    44,    35,     0,
      28,    46,   731,     0,   661,  1655,     0,  1653,  1611,  1651,
    1598,  1599,  1591,  1577,  1592,     0,     0,     0,  1018,  1408,
    1411,     0,     0,     0,     0,  1432,  1322,  1293,  1678,  1677,
    1676,     0,     0,     0,     0,  1317,     0,  1316,     0,  1318,
    1313,  1314,  1315,  1306,  1302,     0,     0,  1363,     0,     0,
       0,  1586,  1583,  1584,   567,   572,     0,     0,  1814,  1814,
     545,   559,   582,   570,   584,  1814,  1814,   580,   564,   575,
     810,   322,   206,     0,  1172,  1191,   810,     0,  1179,  1172,
       0,     0,  1265,     0,     0,     0,     0,     0,  1437,  1439,
    1441,  1478,  1477,  1476,  1443,  1459,  1267,     0,  1520,     0,
    1382,     0,  1385,  1523,     0,  1389,     0,  1257,     0,     0,
    1562,  1560,  1561,  1557,  1559,  1556,  1558,     0,     0,     0,
       0,     0,     0,     0,     0,  1395,     0,  1398,  1399,     0,
    1252,     0,  1246,  1248,  1755,     0,     0,     0,  1802,     0,
       0,  1229,   826,     0,     0,  1615,  1617,   489,     0,   490,
       0,   529,     0,   526,   523,   494,   488,  1120,  1547,  1119,
       0,   170,  1118,     0,     0,     0,  1121,     0,  1123,  1122,
    1116,   448,   449,   453,   438,     0,   441,   452,     0,   440,
       0,     0,    92,     0,     0,     0,     0,  1280,  1807,  1806,
     597,     0,     0,    47,     0,   680,   679,   678,  1281,     0,
       0,   683,  1814,  1814,   150,   621,   160,   152,   162,   142,
     149,  1814,     0,     0,     0,     0,     0,     0,     0,  1311,
     539,     0,   749,  1026,     0,  1781,     0,    92,   531,     0,
      64,     0,     0,     0,    77,     0,    92,    92,   117,   112,
    1814,  1814,   102,     0,   857,   851,   859,   858,   848,   535,
     906,     0,     0,  1622,  1621,  1535,     0,  1611,     0,     0,
    1479,     0,  1479,  1479,  1479,  1479,  1626,     0,     0,     0,
       0,     0,     0,  1679,  1680,  1681,  1682,  1683,  1684,  1629,
    1760,   944,   942,   665,   644,   658,   614,   720,     0,   704,
     702,   708,   706,     0,  1814,     0,  1814,   700,   698,   694,
     692,   742,   696,    23,   732,     0,     0,     0,    26,     0,
    1658,     0,  1581,     0,     0,  1590,  1573,  1589,  1412,     0,
    1375,     0,  1321,  1419,     0,     0,  1674,     0,  1671,  1595,
       0,     0,     0,     0,     0,     0,  1698,  1320,  1319,  1307,
    1305,     0,  1366,     0,  1359,     0,     0,     0,     0,   569,
     566,   561,   563,     0,  1814,  1814,   577,   579,  1814,  1814,
       0,     0,  1170,  1171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1169,     0,     0,  1157,  1158,
    1159,  1156,  1161,  1162,  1163,  1160,  1147,  1138,     0,     0,
    1194,     0,  1814,     0,  1133,     0,     0,     0,     0,     0,
       0,     0,  1125,  1126,     0,  1058,     0,  1269,  1442,     0,
    1446,     0,  1459,  1445,     0,  1407,     0,  1460,  1473,  1470,
    1471,  1468,  1475,  1474,  1469,  1472,     0,     0,     0,     0,
       0,     0,  1524,     0,  1525,     0,     0,     0,     0,  1388,
    1259,  1387,  1379,     0,     0,     0,  1513,  1505,  1505,     0,
       0,  1505,  1512,     0,  1529,  1394,  1396,  1400,  1401,  1254,
    1250,   992,     0,   955,     9,     0,  1222,   827,  1055,     0,
       0,  1431,  1601,  1618,     0,   492,   520,     0,   275,   481,
     478,   487,   484,     0,   443,   442,   472,    95,   474,   348,
    1216,     0,     0,  1798,     0,     0,   960,    48,     0,   604,
     606,   601,   729,   159,   157,     0,  1814,     0,     0,     0,
    1814,   155,   144,     0,   147,   146,     0,   966,   970,   340,
       0,   542,     0,  1814,   751,     0,   613,  1105,     0,  1196,
      69,     0,     0,   100,    67,    92,    75,    81,     0,   119,
     115,   745,  1814,   861,   613,   860,     0,   532,     0,   775,
     776,   774,     0,     0,  1646,     0,     0,     0,  1481,  1482,
    1480,     0,  1648,     0,     0,     0,     0,     0,     0,     0,
    1043,  1631,  1632,  1630,  1628,   668,   666,     0,   648,   645,
       0,   710,   688,   712,   690,   721,   735,   736,   733,   734,
      29,    27,     0,  1652,  1607,  1578,  1579,  1575,  1581,     0,
    1374,  1611,  1377,     0,  1295,  1290,  1289,  1292,     0,  1607,
       0,     0,  1731,  1729,     0,     0,  1717,  1728,     0,     0,
    1730,     0,     0,     0,     0,     0,  1753,  1727,  1723,     0,
    1715,  1718,  1719,  1726,  1722,  1746,     0,  1708,  1707,  1711,
    1713,     0,  1706,     0,  1709,  1700,  1308,  1303,     0,  1365,
       0,     0,  1587,  1585,   573,   571,   583,   585,   581,     0,
       0,   229,  1164,  1165,  1166,  1168,  1151,  1149,  1148,  1152,
    1153,  1150,  1167,  1154,  1155,  1139,   952,  1174,   949,     0,
       0,  1192,     0,  1137,  1136,  1131,  1129,  1128,  1132,  1130,
    1134,  1135,  1127,  1180,  1384,  1444,  1438,  1440,  1447,  1449,
       0,  1454,  1447,     0,  1452,     0,  1462,  1461,     0,  1463,
       0,  1380,  1386,  1527,  1520,  1390,  1569,  1567,  1568,  1564,
    1566,  1563,  1565,  1495,     0,  1497,     0,     0,     0,     0,
    1503,  1507,     0,  1487,  1402,   991,  1230,  1223,  1219,  1616,
       0,  1420,  1421,  1423,  1426,  1433,     0,     0,  1479,  1603,
    1597,  1554,  1552,  1553,  1549,  1551,  1548,  1550,   493,   491,
       0,   525,   524,   172,   439,     0,     0,    23,     0,     0,
     983,     0,    49,   963,     0,    23,   161,   151,     0,   623,
     625,   163,   153,   729,     0,   339,  1312,     0,  1027,    23,
       0,     0,    65,     0,    78,    87,     0,    71,   852,   849,
     536,  1814,   921,  1537,     0,     0,     0,  1647,     0,     0,
       0,  1645,     0,     0,     0,     0,  1627,  1644,     0,  1814,
     664,   643,   649,   613,  1662,     0,  1660,     0,     0,  1581,
    1581,  1574,  1376,     0,  1378,  1372,     0,  1294,     0,  1672,
       0,  1721,  1720,     0,     0,  1479,     0,  1479,  1479,  1479,
    1479,  1724,     0,     0,  1704,     0,     0,     0,     0,  1733,
    1705,     0,     0,     0,     0,     0,     0,  1699,     0,  1367,
    1370,  1354,  1368,  1371,     0,   821,   820,   323,   207,   954,
     953,   951,     0,  1173,  1059,  1063,  1065,     0,  1069,     0,
    1067,  1071,  1060,  1061,     0,   843,     0,     0,  1466,     0,
    1455,  1458,  1457,  1465,     0,  1447,     0,     0,  1521,  1526,
       0,  1514,  1506,  1490,  1488,     0,  1491,     0,  1424,     0,
    1528,  1427,     0,  1434,  1435,  1606,  1222,     0,     0,     0,
       0,   522,   521,   475,   349,   346,     0,   981,     0,     0,
       0,   962,   730,   139,   622,    23,   972,   540,  1024,    66,
    1197,    83,     0,     0,    76,    87,    87,  1814,   533,     0,
       0,     0,     0,     0,  1643,  1649,  1639,  1640,  1641,  1642,
       0,   667,   722,     0,  1659,  1608,  1601,  1580,  1576,     0,
    1296,     0,  1601,  1744,     0,     0,  1747,     0,     0,     0,
       0,     0,     0,     0,  1716,  1735,  1736,  1734,  1732,  1714,
       0,  1710,  1712,  1701,  1702,  1309,     0,  1355,  1353,  1588,
     950,  1814,  1814,  1073,  1814,  1075,  1814,  1814,  1062,  1193,
    1181,  1448,  1650,  1450,     0,  1453,  1451,  1467,     0,     0,
       0,  1504,  1428,     0,  1422,  1416,  1417,  1619,     0,  1436,
    1430,  1604,  1327,  1323,  1324,  1329,  1328,  1602,  1222,     0,
     351,   982,  1797,     0,     0,     0,     0,     0,     0,    54,
       0,    53,     0,    51,     0,     0,   140,  1031,    87,    92,
      87,    88,    82,    72,   850,     0,     0,  1610,     0,  1687,
       0,   669,    23,  1661,  1600,  1609,  1300,     0,  1297,  1299,
    1596,  1745,     0,     0,  1743,     0,     0,     0,     0,  1725,
    1742,     0,  1369,  1064,  1066,  1814,  1070,  1814,  1068,  1072,
    1456,  1464,  1522,  1499,     0,  1425,     0,  1415,     0,  1331,
    1330,  1326,  1605,  1555,   357,   355,   347,     0,   353,   359,
      56,    61,    58,    60,    57,    59,    55,     0,    50,     0,
     624,   626,  1035,  1025,     0,  1033,  1198,    84,    79,   534,
     922,  1685,  1686,  1814,   723,     0,  1291,  1741,  1748,  1737,
    1738,  1739,  1740,     0,  1074,  1076,  1429,  1418,  1325,  1814,
    1814,   352,   354,  1814,    52,     0,  1814,  1032,  1034,     0,
     665,  1298,  1703,   358,   356,   360,     0,  1036,    85,   670,
     964,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   554,   555,   556,   557,   713,  1741,  1742,   191,   266,
     192,  1139,  1140,  1629,  1969,  3031,  2466,  2467,  2909,  3032,
    3033,   558,   902,  2501,  2207,  2926,  1568,  2205,  2765,  2505,
    2922,  2206,  2766,  3039,  3149,  3161,  2924,  3164,  1790,  1791,
    1792,  1254,  1858,   559,  1265,   907,  1263,  1576,  1868,  1573,
    1866,  1871,  2211,  1264,  1865,  1577,  2210,   560,    18,    37,
      38,    39,    40,    41,   116,   563,   831,  1523,  1166,  1818,
    1822,  1823,  1819,  1820,  2476,  2480,  2181,  2173,  2172,  2174,
    2177,  1117,  1069,  1772,   564,    85,    86,    20,    63,   144,
      98,   257,   100,   101,   202,   280,   102,   103,   244,   230,
     681,  2331,   307,   662,  1689,   334,   335,   231,   289,   282,
     284,   987,   988,   148,   357,   149,   150,   295,   232,   233,
    1509,   395,   245,   248,   246,   247,   316,   372,   373,   375,
     380,   665,   249,   250,   325,   377,   198,    21,    82,   180,
     181,   182,   671,  2330,   183,   253,   242,   328,   329,   330,
     331,  1536,   565,   566,   567,   568,   788,  3020,  2737,  1141,
    3096,  3097,  3098,  3140,  3139,  3143,   569,   570,   571,   572,
     762,  1118,   783,  1133,  1134,  1175,   868,  1176,   764,   765,
     766,   767,   768,   769,   770,  1072,  1119,  2145,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,   718,   771,  1488,  2150,  2152,
    2735,   772,  1458,  2134,  1457,  2133,  1461,  2137,  1459,  2135,
    2117,  2126,   773,   774,   775,   776,  1442,  1443,  1444,  1445,
    1561,   573,  2771,  3045,  2517,   574,   841,  1538,  2493,  1839,
     117,   239,   367,  1357,   968,   969,   970,  1354,  1355,  1676,
    1677,  1678,  2028,  2029,  1358,  1359,  1672,  2032,  2024,  1684,
    1685,  2035,  2036,  2328,  2324,  2325,   575,  1184,    87,  1504,
    1505,  1834,   871,   821,   874,   696,   810,   793,   832,  1927,
      88,   697,   691,  1407,  2176,    89,   778,   576,   577,   923,
     924,   578,   579,   580,   581,   931,  2548,   952,  2791,   953,
    1606,   954,  1924,   955,  2254,   956,  1632,   582,  1602,  2253,
    2547,  2789,  2788,  3123,   118,    22,   583,  1157,  1510,  1511,
    1622,  1303,  1623,  1624,  2264,  2266,  1940,  1939,  1944,  1938,
    1937,  1930,  1929,  1932,  1931,  1934,  1936,   584,   585,   829,
     586,  1299,   938,  3052,   587,  1231,  2745,  1971,  1972,  1625,
    1941,  1874,  2213,   864,  1212,  1542,  1842,  1543,  1208,   588,
     589,   916,  1591,  2521,   590,   591,   592,   593,    23,    68,
      24,    25,    26,   119,   120,   594,   121,    27,   652,    28,
     122,   123,   160,   369,  1363,  2040,  2846,   124,   156,   300,
     595,  2113,    29,    30,    31,    32,    33,    62,    90,   125,
     415,  1372,  2046,   596,   911,  1878,  1580,  1876,  2927,  2512,
    1581,  1875,  2216,  2514,   597,   598,   599,   804,   805,  1267,
     126,   240,   368,   656,   657,   972,  1361,   600,   957,   958,
     601,  1311,   959,   779,    92,    93,    94,    95,  1274,   186,
     140,    96,   702,   137,   194,   195,  1275,  1276,  1885,  1277,
     412,   413,   940,   414,   941,  1598,  1599,  1278,  1279,  1137,
    2647,  2648,  2851,  1416,   819,   820,   602,  1152,  2911,   603,
    2488,   604,  1170,  1171,  1172,  1529,  1527,   605,   606,  1799,
    1829,   607,  1020,  1413,   608,   865,   866,   609,   879,   610,
    1982,   611,  3037,  2496,   612,  1846,  3113,  3114,  3115,  3146,
     870,   613,  1280,  1593,  1911,  1912,   614,  1497,   695,  1032,
     615,   616,   617,  2048,  2651,  2862,  2863,  2981,  2982,  2986,
    2984,  2987,  3075,  3077,   618,   619,  1269,  1585,   620,  1271,
     887,   888,   889,  1247,   621,   622,   623,  1554,  1239,   882,
     201,   890,   891,   780,  2049,  2372,  2373,  2356,   721,   722,
    2044,  2357,  2360,   127,   155,   361,   997,  1694,  2374,  2866,
    1042,   624,   880,   128,   152,   358,   994,  1692,  2361,  2864,
    2045,   906,  2197,  2761,  3038,  1242,   625,   626,   627,   628,
     629,   791,  1797,   715,  1746,   630,  2708,   709,   710,  2110,
    1392,   631,   632,  1006,  1007,  1008,  1404,  1731,  1009,  1728,
    1401,  1010,  1703,  1393,  1011,  1012,  1013,  1014,  1697,  1384,
     633,   800,   781,   634,  1335,  1336,  1647,  2576,  2808,  2295,
    2573,  3057,  3058,  1337,  1657,  2309,  1317,  2014,  2617,  2838,
    2190,  2492,  2015,  1338,  1339,  2719,  3013,  3014,  3015,  3091,
    1340,  1341,  1174,   635,   835,   636,   965,  1342,  1343,  2978,
    1663,  1664,  1665,  2017,  2311,  2841,  2842,  1344,  1992,  2289,
    2805,  1394,  1395,  1380,  2069,  1695,  2070,  1396,  2074,  1397,
    2097,  1398,  2098,  2426,  2427,  1698,  1345,  1641,  1642,  1989,
    1346,  3009,  2893,  3005,  1995,  2441,  2711,  2712,  2713,  3003,
    2442,  1996,  2894,  3010,  2057,  2058,  2059,  2060,  2061,  2868,
    2668,  2991,  2062,  2869,  2870,  2400,  2063,  2401,  2064,  2531,
    1724,  1725,  1726,  2697,  1727,  2423,  2417,  2882,  2071,  2843,
    2404,  2609,  2073,  2891,  1913,   782,  1914,  2225,  1060,  2118,
    2728,  2087,  2693,    61,   637,   638,  2568,  2800,  2282,  2799,
    1668,  2022,  2023,  2286,  1983,  1347,  1984,  2003,  2579,  1434,
    1979,  1980,  2720,  2896,  2798,  2572,  1915,  1655,  2114,  2115,
    3006,  2065,  1917,  1918,  2533,  2993,   639,   640,  1634,  1981,
    2563,  2795,  2796,  1314,   641,   786,  1349,  1350,  1650,  2297,
    1351,  1352,  2000,  2249,  2526,   642,   919,  1288,  1289,  1290,
    1291,  1353,  2004,  2615,  2837,  2306,  2612,  2613,  2614,  2611,
    2599,  2600,  2601,  2602,  2603,  2604,  2957,   703,  1595,   705,
    1417,  1919,    66,    50,    80,    77,   644,   893,  1558,  1160,
    1233,   645,   872,   646,  2163,   647,  1740,   707,  1419,   648,
     649,    44,   362,   363,   364,   365,   366,   650
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2571
static const short yypact[] =
{
    2916,  1037, -2571, -2571,   283,   947,   947,   947,   947,   947,
     947,   947,   947,   283,  1147, -2571, -2571,  1147, -2571,  1422,
   -2571, -2571, -2571,   339, -2571,  2916, -2571, -2571, -2571, -2571,
   -2571,  1285, -2571, -2571, -2571, -2571, -2571,   320,   364, -2571,
     327, -2571, -2571, -2571, -2571, -2571,   283,   152, -2571,  -265,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,  2812,    98, -2571, -2571, -2571, -2571,   331, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,   283, -2571,
   -2571,   152,  -203, -2571,   283,   365,  1422, -2571,   865, -2571,
   -2571, -2571, -2571,   809,   250, -2571, -2571, -2571,   924,   414,
     283, -2571, -2571,   938,   283, -2571, -2571,   283,   283, -2571,
   -2571, -2571, -2571,   283,   283, -2571, -2571, -2571, -2571, -2571,
     331, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,  7128,   250, -2571,   950,   789, -2571, -2571,   531,
   -2571, -2571,   907,    98,   427, -2571, -2571, -2571, -2571, -2571,
    7554, -2571,   283,   572,   886,   283,  1422, -2571, -2571, -2571,
     283, -2571, -2571,   499,  1069, -2571, -2571,   640, -2571,   667,
   -2571,   693, -2571, -2571,   756, -2571,   760, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,   636, -2571, -2571, -2571,
     789,  1326,  1184, -2571,   148, -2571,   789, -2571,    59, -2571,
   -2571, -2571,   179, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,   499, -2571,  1069, -2571, -2571,   800, -2571,   820, -2571,
     797, -2571, -2571,   839, -2571,   854, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571,   874,  1291,   283,   897, -2571,  1422,
    1422,   900,   283, -2571,   -62, -2571,   708,  1082, -2571,   725,
    1115,  1344,  1351,   283,  1357,  1366,  1378, -2571,   790, -2571,
    1162, -2571, -2571, -2571, -2571, -2571,   789, -2571,   789,   962,
     149, -2571, -2571, -2571,  1402, -2571, -2571,  1411, -2571, -2571,
   -2571, -2571, -2571,   -62, -2571, -2571, -2571,  1420,  1423,    98,
    1357,  1430,  1439,   855, -2571,  1428, -2571,  1087,  1059, -2571,
    1138, -2571, -2571, -2571,   884, -2571, -2571,  1488, -2571,  1104,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1115,  1104, -2571,
   -2571, -2571, -2571, -2571, -2571,  1133,   144,   187,   246, -2571,
    2650, -2571, -2571, -2571,  1140,  1569,   228,  1187, -2571, -2571,
    1326, -2571,   789,  1131, -2571, -2571,   972,  1567,  1341,   234,
     256,   579,  1183,   275,  1227, -2571, -2571, -2571,   283, -2571,
   -2571,   283,  1254, -2571,  4017,   427,  4987,  1713,   509,   283,
    1600,   -25, -2571,  1082,  1602, -2571, -2571, -2571, -2571,  1618,
   -2571,  1621, -2571,  1622, -2571,   283, -2571,   283, -2571, -2571,
    1357,  1625, -2571, -2571, -2571, -2571,   175,   789,  1632,   -25,
    1226,  1628, -2571,  1634, -2571, -2571, -2571,  1635, -2571, -2571,
   -2571,  1045,  1277,  1665, -2571,   283,  1283, -2571, -2571, -2571,
     283,   433,   283,   283,   433,   433,  1027,   283, -2571,   283,
   -2571, -2571,   283, -2571,   297, -2571, -2571, -2571,   433, -2571,
   -2571, -2571, -2571,   283, -2571, -2571, -2571, -2571,    67,    67,
    6922, -2571, -2571, -2571, -2571, -2571, -2571,   433, -2571, -2571,
     433, -2571, -2571,   283, -2571, -2571,   433, -2571, -2571,   231,
     433, -2571, -2571,  6922,   433,   231,   283,   231,   433, -2571,
   -2571,   181,   433,   433,   181,   433,   283,   181,   433, -2571,
     433,   433,   433, -2571, -2571, -2571, -2571,   231,   433, -2571,
   -2571,   433,    38,   283, -2571, -2571, -2571, -2571,   433,  1175,
   -2571, -2571, -2571,   433, -2571,  3576,   231,  6922,    43,    43,
     433, -2571, -2571,  1201,   231,  1213,  6922,  6922, -2571,   326,
    6922,   433,   152, -2571,  6922,   433,  1645,   231, -2571,   433,
    6922, -2571,  6922,    67,   283,   433,   283,    43,   433,   283,
      43, -2571,   283,   242, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,   176, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,   983, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,   832, -2571,   283, -2571,  -172, -2571,  1289, -2571,
   -2571, -2571,  1381, -2571, -2571,  1298,  1301,  1308,  1309, -2571,
   -2571,  1080,  1699,  1317, -2571,   191, -2571,  1407, -2571,  1329,
    1331,  1090,  1332,   283, -2571,   283,  1333, -2571,   349,  1287,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1106,
    1196,  1268, -2571,  1111, -2571,  1113, -2571,  1732,  -252,   280,
   -2571, -2571, -2571,  1313, -2571,  1261, -2571,  1267,   198, -2571,
   -2571, -2571,  1504, -2571,  6922,  6922,  6922, -2571, -2571,  1324,
    1230,  1328,  1348,  1350,  1352,  1353,  1356,  1358,  1359,  1364,
    6922,  1224,  1373,  1374,  1376, -2571,  6922,  6922,  1377,  1380,
   -2571,  6922,  1386, -2571,  1388,  1390,  1392,  1394,  1395,  1396,
    1399,  1400,  6284, -2571,    71, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,   853, -2571,  1336,
   -2571, -2571, -2571, -2571,  6607, -2571, -2571, -2571,   231, -2571,
   -2571,  1261, -2571,  -100, -2571, -2571,  1495, -2571,   160, -2571,
    1303, -2571, -2571, -2571, -2571,  1758, -2571, -2571,   252, -2571,
    1148, -2571,  1170,  1758, -2571,  1216, -2571, -2571,  1412,    74,
   -2571,  1305, -2571,  1179, -2571, -2571,  1403, -2571,  -117, -2571,
    1182,   793,  -241, -2571,  1106,  1470, -2571,  6922,  6922, -2571,
    1819,   433, -2571, -2571, -2571, -2571, -2571,    87,    87,    87,
   -2571,    87,  3564,    87,    87,  1246,  -100,  1246,  1246,  1234,
    1234,  1246,  1246,  -100, -2571,  1839, -2571,    -3,  1840, -2571,
    -100, -2571,   130,    54, -2571, -2571,  6922, -2571, -2571, -2571,
   -2571, -2571,   993, -2571, -2571,   427,  1464,   427,  6922, -2571,
      68, -2571, -2571,  6922,  1419,  1424,  1426,  1432,  1270,  1433,
    1213,  1390, -2571,  1506,  1145,  1263, -2571,  1275, -2571, -2571,
   -2571,  1235, -2571,  1850, -2571,  1858,   283, -2571,   120,   204,
    1307, -2571, -2571,  1868, -2571,  1222,  1868,  1878,  1229,  1868,
    1878,  6922,  1868, -2571, -2571,   198,   231, -2571, -2571,  1468,
     270, -2571, -2571,  1459,   231,  6922,  1460, -2571, -2571,  1865,
    1866,  1829, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
    1250,  1250,   433,   433,   433,  2269, -2571, -2571,  1804,   832,
   -2571, -2571,   625, -2571, -2571, -2571,  1438, -2571, -2571, -2571,
   -2571,  7128,  1357, -2571, -2571,  1440, -2571,   296, -2571, -2571,
   -2571, -2571, -2571, -2571,  1422, -2571, -2571,  1422,   846,   109,
    1871, -2571, -2571,   539,   190,   762,  1894, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571,  1280,  1196,  1113, -2571,  1027,
    -227,   877,   283, -2571, -2571,   283, -2571,  1311,  1281,  1318,
    1478, -2571,  1479,   124, -2571, -2571, -2571,  6449,  1259,  1259,
      43,  6922, -2571,    43,    43,    43,    43,  1441,  6922,  1467,
    1481,  6922,  6284,  1480, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,  1290,    43,  1897,  6922,  3637,  6284,  1441,  6922, -2571,
    6284,  1900,   425, -2571, -2571, -2571,  6922, -2571,  6922,  6922,
    6922,  6922,  6922,  6922,  6922,  6922,  6922,  6922,  6922,  6922,
    6922,  6922,  6922,  6922,  6922,  6922,  6922,  6922, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  6922,  6922,
   -2571, -2571,  1484,  6922, -2571,  6922,  1492, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
     283,   231, -2571, -2571,  1923, -2571, -2571,  1304,  1501, -2571,
   -2571, -2571,  1027,  1276, -2571,  1276,  1213,   181,  6922,  6922,
    6922,  1503, -2571, -2571,   231,   231, -2571,  1320,  1213,    43,
    1292,   283,   789,    42,    38,   231, -2571,  1327,  6922,  1596,
   -2571, -2571,  1398, -2571, -2571,  1945, -2571,   121,   198, -2571,
   -2571,  1934,  1937, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,  4453, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,  3576, -2571,  1234,  6922,   -92,    43,  1931,  1932, -2571,
   -2571, -2571, -2571, -2571,   133, -2571, -2571, -2571, -2571,  1808,
   -2571,  1744, -2571, -2571, -2571,  6922,    67, -2571, -2571,   283,
    1938,    43,    43, -2571,  1375, -2571,    43,  1345,   231, -2571,
     283,   283,  6922,   -66, -2571,  1391, -2571,   247, -2571,  1485,
   -2571,  1489,  6922,  1100, -2571, -2571,  1360, -2571,  1966, -2571,
    1431, -2571,   231, -2571, -2571, -2571,  1027,   231,   153, -2571,
   -2571, -2571, -2571,   283,    43,    43,   324,   270,  1828,  2484,
     231,   198, -2571,  1435, -2571, -2571,  1945,  1962,  1592, -2571,
   -2571, -2571, -2571, -2571,  1671,  1671, -2571,   127,  1447, -2571,
     283, -2571, -2571,  1261,  1261, -2571, -2571, -2571,   283, -2571,
     283,   536,  1261, -2571,   755, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1335, -2571,
   -2571, -2571, -2571, -2571,   261,   261,   795,   984, -2571,   630,
   -2571,   625, -2571,  1422,  1969, -2571, -2571,  1969, -2571, -2571,
   -2571, -2571,  1422, -2571, -2571,  1261, -2571,   736, -2571,  1566,
   -2571, -2571,   736, -2571, -2571, -2571,  1573,  1576,   313,  1577,
    1579,  1794, -2571, -2571, -2571, -2571, -2571, -2571, -2571,   283,
   -2571, -2571,   313,  1347, -2571,   349, -2571,  1620,   250,  1401,
   -2571,  1213,  1437, -2571, -2571,  1558, -2571, -2571, -2571,  1471,
   -2571,   283,   283,   283, -2571, -2571, -2571,   303,  6284,  1627,
    1630,   311,   323,   536,  1633,  3925,  1636,  -112,  1535, -2571,
   -2571,   194,  1638, -2571, -2571, -2571,  4390,  1993,  1224,   328,
    1639,  4507, -2571,  1640,  2632,  1641, -2571,  6922,  6922,  6922,
    5320,  6922,  5646,  5709,  5752,  6347,  6410,  6449,  6479,  2330,
     757,  4399,  4444,  3666,  4590,  1367,  1259,  1259,  3329,  3329,
    5854,  6284,  5815,  5961,  1441,  6284,  6138,  1441,  6922,  1595,
   -2571,  6607,   283, -2571,  1417, -2571, -2571, -2571, -2571,  1410,
   -2571,  2031,  2032, -2571,  2035,  1462,  6922, -2571, -2571,  1425,
    2037, -2571,  1561,  1427,  1878, -2571,  1654,   931, -2571,  1623,
   -2571, -2571,  1434,  1172,   283, -2571, -2571,  1626,   433,   988,
    6922, -2571,   283,   283,  6922,    51,  -100,  2045,  2047,  2033,
    2034,  3564, -2571, -2571, -2571, -2571, -2571,   231,  1527, -2571,
   -2571, -2571,  1999,  6922,   427,   908, -2571, -2571,  1740,  2061,
    2063,   354, -2571,   399,   283,  1680,  1213, -2571,  6922,  1643,
    1647, -2571, -2571,  1715, -2571,  6922,   -46, -2571,  1482, -2571,
   -2571,   788, -2571,  6922, -2571, -2571,  1455,   950, -2571,   970,
     283,  2068,  7107, -2571, -2571,  1664, -2571,  1666,  2080, -2571,
   -2571, -2571,   104, -2571,  1878,  1878,  1429, -2571,  1537,  1543,
   -2571, -2571, -2571, -2571,    43,    43, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571,  1710, -2571, -2571, -2571, -2571,    43,  6274,
    2089,  2070, -2571,  1213,   815,   189,   182,  1998,    60,  1201,
   -2571,    37, -2571, -2571, -2571,  1670,   293,  1261,   737, -2571,
    1487,  1476, -2571, -2571, -2571, -2571, -2571,   568, -2571, -2571,
   -2571, -2571,  1673,  1483,  2099, -2571,  1334, -2571, -2571, -2571,
   -2571,   231,    82, -2571, -2571, -2571,  1475,   984, -2571,   283,
     283, -2571, -2571,   283,   551, -2571, -2571, -2571, -2571,  1688,
    1689, -2571,  1656, -2571,  1667, -2571,  1694,   403, -2571,  4784,
     405,    96,    96,   410, -2571,    96,  4784, -2571, -2571,  1238,
    1238, -2571,  1695, -2571,  1696,  1700, -2571,  1702,  1703, -2571,
    1704, -2571, -2571, -2571,    48, -2571, -2571, -2571,   419, -2571,
   -2571,   422,   283, -2571, -2571,   877,  2128,  1213,   789,  6922,
   -2571,  2132, -2571, -2571, -2571, -2571,   313, -2571, -2571, -2571,
   -2571, -2571, -2571,  7354, -2571, -2571,  1224,  1224,  2112, -2571,
    2114,  1552,   441, -2571,  1230,  1751, -2571, -2571,  1230, -2571,
   -2571, -2571,  1752,  1230,  6284,  6284,  6284,  1230,  6284,  1230,
    1230,  1230,  2119,  2120,  2121,  6922,  1759,  2124,  6922,  1761,
   -2571,  2148, -2571,  6284, -2571, -2571,  1536,   313,   142, -2571,
    1213,  6922,  6922,  6922,  6723,  2149,   151, -2571, -2571,  1213,
   -2571,  1540,   283,   283, -2571, -2571,   283,   283, -2571,  1143,
   -2571, -2571,   276, -2571,  1542,  6922, -2571, -2571, -2571,  2154,
   -2571, -2571, -2571, -2571, -2571,   283,  1878, -2571, -2571,  1603,
   -2571, -2571,   436, -2571, -2571, -2571,   231, -2571,  3450, -2571,
   -2571, -2571,  1841,  2144, -2571,    43,  1826,  1827,  1725,  1568,
    1842,  1755, -2571, -2571, -2571,   -86,  1832, -2571, -2571, -2571,
   -2571,  1715, -2571, -2571, -2571,   209,   825, -2571, -2571, -2571,
    1945,  6922,  1763, -2571,  1736, -2571, -2571, -2571,  7548,  7548,
   -2571,  1106, -2571, -2571,  1238, -2571, -2571,  7157,  1765, -2571,
   -2571,  1766,  1767, -2571,  1775,  1780,  1781,  1782,   283,   -29,
   -2571,  2208, -2571, -2571, -2571, -2571, -2571,  2587, -2571, -2571,
    1027,   231,   231, -2571,  1564, -2571,  2189,  -100,   283,  2138,
    2138,  2138,  2138, -2571,  2211, -2571,  2214,  2138,  2138,  2138,
    2138,  4453, -2571, -2571,  2138,   106, -2571, -2571, -2571, -2571,
    2196,  2210, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,  2215, -2571, -2571, -2571, -2571, -2571, -2571, -2571,   440,
   -2571, -2571, -2571,  2202, -2571, -2571,  1261, -2571,   536, -2571,
   -2571, -2571, -2571, -2571, -2571,  1637,  1651,   218, -2571,    37,
   -2571,    96,  1606,   433,  4784, -2571, -2571,  1800, -2571, -2571,
   -2571,   283,   283,  7354,   240, -2571,  6922, -2571,  6922, -2571,
   -2571, -2571, -2571, -2571, -2571,   433,    96, -2571,  1261,   -80,
    1612,  1629,  2242, -2571,  2246, -2571,   231,   283,   489,   489,
   -2571, -2571,  2247, -2571,  2247,   719,   719,  2247, -2571, -2571,
    1713, -2571, -2571,  7732,    41, -2571,  1713,  1863, -2571,    41,
      96,   736, -2571,  6873,  1830,  5011,  1830,   164,  2250, -2571,
   -2571, -2571, -2571, -2571, -2571,   622, -2571,  1261,   342,  1867,
    2257,  1648, -2571, -2571,   453, -2571,   313, -2571,   465,   238,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1653,  -130,  2238,
    2238,  2240,  2238,  2238,  2244, -2571,    81, -2571,   736,   283,
   -2571,   313, -2571, -2571,  1649,  1213,  2271,   216, -2571,   283,
     466, -2571,  6922,  1889,   134, -2571,   283, -2571,  1657, -2571,
    1890, -2571,  2258, -2571,  1697, -2571, -2571, -2571, -2571, -2571,
    1658, -2571, -2571,  1896,  1901,  1903, -2571,  1911, -2571, -2571,
   -2571, -2571, -2571, -2571,  6284,   468, -2571, -2571,   480, -2571,
    1915,  6922,  6922,  2265,   495,  1213,  2283, -2571, -2571, -2571,
   -2571,  6922,  1741,  2017,  6922, -2571, -2571, -2571, -2571,  1028,
    1917,   276,  1209,  1209,  2304,  -102, -2571,  2305, -2571, -2571,
   -2571,  1209,   283,  1768,  1029,  2310,   283,   404,  6922, -2571,
   -2571,  3564, -2571,  1650,  6922, -2571,  2311,  6922, -2571,   231,
   -2571,   297,   283,   231, -2571,  1927,  6922,  6922, -2571, -2571,
     -86,  1832, -2571,  4453, -2571, -2571,  1372, -2571, -2571,  1753,
   -2571,   789,  6863,  2147,  2147, -2571,  1705,   536,  1936,   463,
     549,  7354,   549,   549,   549,   549,  1706,  7354,  7107,  7354,
    7354,  7354,  7354, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571,   126,   991, -2571, -2571, -2571,  1709, -2571,
   -2571, -2571, -2571,    43,  2138,    43,  2138, -2571, -2571, -2571,
   -2571, -2571, -2571,  -100, -2571,  1110,  1122,  6274, -2571,  1941,
    1910,  7354,  1335,   182,   182, -2571, -2571, -2571, -2571,   501,
   -2571,  1883, -2571,  2348,    96,   409, -2571,  1730, -2571,  2351,
    7368,  7368,  7368,  7368,    96,    96, -2571, -2571, -2571,  1807,
   -2571,   505, -2571,  1737, -2571,   283,   283,  1334,   231, -2571,
    2247, -2571, -2571,   283,   719,   719, -2571, -2571,   719,  2151,
    1734,  1746, -2571, -2571,    67,    67,    67,  2338,    67,    67,
      67,    67,    67,    67,  2339, -2571,  2342,    67, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  7732, -2571,   231,  1754,
   -2571,  1924,  2151,  2346, -2571,  2350,  2347,  2352,  2353,  2355,
    2357,  1387,  1863, -2571,  1924, -2571,   514, -2571, -2571,  1906,
   -2571,   298,   576, -2571,  4784, -2571,  4784, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  7548,  1947,  7548,  1955,
     683,  7354, -2571,  2360, -2571,  2092,    96,  1092,    96, -2571,
   -2571, -2571, -2571,  1265,  2363,  1265, -2571,  2385,  2385,   522,
    2000,  2385, -2571,  2004, -2571, -2571, -2571,   736, -2571, -2571,
   -2571, -2571,  1213, -2571, -2571,   313,  2130,  1945, -2571,  7354,
     170,  1874,   594, -2571,  1322,  1224,  1811,  1239, -2571, -2571,
   -2571, -2571, -2571,  6922, -2571, -2571, -2571, -2571, -2571,  1929,
   -2571,   245,  1213, -2571,  2396,  1975, -2571, -2571,  2015, -2571,
   -2571, -2571,  1857, -2571, -2571,   283,  1209,   789,  1142,   283,
    1209, -2571, -2571,    43, -2571, -2571,  6922, -2571, -2571, -2571,
      43,  1945,   231,  2169, -2571,  2384,  1537,  6284,  2387, -2571,
   -2571,   198,  1988, -2571, -2571,  6922, -2571, -2571,  2025, -2571,
   -2571, -2571,   825, -2571,  1537, -2571,  6922, -2571,   225, -2571,
    1840, -2571,  1265,  7354, -2571,   333,  2029,  2416, -2571, -2571,
   -2571,  7354, -2571,   528,  7354,  7354,  7354,  7354,   283,   545,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1989,  2084, -2571,
    2410, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,   283, -2571,    70, -2571, -2571, -2571,  1335,    96,
   -2571,   536,  2293,   563, -2571, -2571, -2571, -2571,   283,  1881,
    7553,  7553, -2571, -2571,  1491,  2007, -2571, -2571,  2011,  2012,
   -2571,  2014,  2016,  2018,  2020,   283,   -27, -2571, -2571,   564,
   -2571, -2571,  2599, -2571, -2571, -2571,   567,  2440,  2440, -2571,
   -2571,   571,  2446,  2438, -2571,   314, -2571, -2571,    96, -2571,
     115,  1835, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  2245,
    7128, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  -223,  2451, -2571,   231,
    1297, -2571,  2245, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  2250, -2571,  2019,  2587,
     202, -2571,  2019,   202, -2571,  7548, -2571, -2571,  7354, -2571,
     235, -2571, -2571, -2571,  2001, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571,  2066, -2571,  2432,  2072,  2074,  2435,
   -2571, -2571,  2075, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
     232,  2459, -2571, -2571,   283,  2100,   283,  1849,   549,  2141,
   -2571,  2039, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
    1397, -2571, -2571, -2571,  6284,  2082,    43,  -100,  2103,  1213,
   -2571,  6922, -2571,  1912,  2452,  -100, -2571, -2571,   952, -2571,
   -2571, -2571, -2571,   110,  2090,  1878,  2080,  2248, -2571,  -100,
    2093,  2096,  2045,  2062, -2571,  2150,  2102, -2571, -2571, -2571,
   -2571,  2254,  2038, -2571,   134,  1238,  1872, -2571,  1238,  2108,
    7354, -2571,  2109,  2111,  2117,  2118, -2571, -2571,  6922,  2051,
   -2571, -2571, -2571,  1537, -2571,   575, -2571,   231,  1957,  1335,
    1335, -2571, -2571,  7354, -2571, -2571,    96, -2571,  2081, -2571,
    1957,  2179,  2179,  2122,   463,   549,  7469,   549,   549,   549,
     549,  1886,  7469,  7368, -2571,  7469,  7469,  7469,  7469, -2571,
   -2571,    96,  2496,    96,  7368,   433,  4784, -2571,   231, -2571,
   -2571,   315, -2571, -2571,   283, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,   231,  2451, -2571, -2571, -2571,   231, -2571,   231,
   -2571, -2571,  1731, -2571,  2275, -2571,  2276,    81, -2571,   589,
   -2571, -2571, -2571, -2571,   593,  2019,  2509,  2497, -2571, -2571,
    1899, -2571, -2571, -2571, -2571,  2134, -2571,   170, -2571,   170,
   -2571, -2571,  7354, -2571,  2079, -2571,  2130,   157,   189,   283,
    2503, -2571, -2571, -2571, -2571, -2571,  1213, -2571,  2143,  7731,
    2106, -2571, -2571, -2571,  1918,  -100, -2571, -2571, -2571, -2571,
   -2571, -2571,  2152,   198, -2571,  2150,  2150,   825, -2571,   789,
    2153,  1913,  1265,  1914, -2571, -2571, -2571, -2571, -2571, -2571,
    1971, -2571, -2571,   283, -2571,  2080,   594, -2571, -2571,   134,
   -2571,  7246,   594, -2571,  2158,  7469, -2571,   595,  7469,  7469,
    7469,  7469,   283,   597, -2571, -2571, -2571, -2571, -2571, -2571,
    2123, -2571, -2571, -2571,  2348,  2080,   115, -2571, -2571, -2571,
   -2571,  1513,  1513, -2571,  1513, -2571,  1513,  1513, -2571, -2571,
   -2571, -2571, -2571, -2571,   321, -2571, -2571, -2571,  7354,  2125,
    1265, -2571, -2571,   603, -2571,  2547, -2571, -2571,  4784, -2571,
   -2571, -2571, -2571,  2550, -2571,  -202, -2571, -2571,  2130,  2165,
    1144, -2571, -2571,    87,    87,    87,    87,    87,    87, -2571,
    2534, -2571,   605, -2571,  6922,  1169, -2571,    75,  2150,  6922,
    2150,  2045, -2571, -2571, -2571,  2321,   237, -2571,  1265, -2571,
    1265, -2571,  -100, -2571, -2571, -2571, -2571,   619, -2571, -2571,
   -2571, -2571,  2172,  7469, -2571,  2173,  2177,  2178,  2180, -2571,
   -2571,  7368, -2571, -2571, -2571,  1513, -2571,  1513, -2571, -2571,
   -2571, -2571, -2571, -2571,   170, -2571,  7354,  2348,   157, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,   807, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  7731, -2571,  2567,
   -2571, -2571, -2571, -2571,   644, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571,   104, -2571,  7246, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571,   638, -2571, -2571, -2571, -2571, -2571,  1054,
    1054, -2571, -2571,  1054, -2571,  6922,   951, -2571, -2571,  2182,
     126, -2571, -2571, -2571, -2571, -2571,  2184, -2571, -2571, -2571,
   -2571,    23, -2571,   198, -2571,  2045
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2571, -2571, -2571, -2571, -2571,   380, -2571,   474,  -184, -2571,
   -2571,  -832,   305, -2571, -2571, -1565, -2571, -2571, -2571, -2571,
    -523, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -1499, -2571, -1549, -2571,
     435, -2571, -2571, -2571, -2571, -2571, -2571, -2571,   716, -2571,
   -2571, -2571, -2571,  1325, -2571,  1014, -2571, -2571,   -64, -2571,
   -2571,  2554, -2571,  2553,  2228, -2571, -2571, -2571, -2571, -2571,
     786,   421, -2571,   792, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571,  -121,   384,   264, -2571, -2571,
    2320,    25, -2571,  2469, -2571, -2571,  2466, -2571,  2404, -2571,
   -2571, -2571,  2344,  2229,  1262,  2340,  -300, -2571, -2571, -2571,
   -2571, -2571,  1264,  -976, -2571, -2571, -2571, -2571, -2571, -2571,
    -156,  2278,  2418,  -198,   864, -2571,  2263,   193, -2571,  2341,
   -2571, -2571, -2571, -2571,  2343, -2571, -2571, -2571, -2571,  -327,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  2272, -2571,
    2274, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  -892,
   -2571, -2571,  -441, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
    2522, -2571, -2571,  1167, -2571,  -814,  -856,   -33, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,   875, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571,  -311, -2571, -2571, -2571, -2571,
   -2571,  2133, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -1708, -2571, -2571, -2571, -2571, -2571, -2571,  1232, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  1707, -2571, -2571, -2571,
   -2571,   987, -2571, -2571, -2571, -2571, -2571, -1159, -2571, -2571,
     981, -2571, -2571, -2571, -2571, -2571, -2571,  -690,  -547,   869,
    1134, -2571,  -491,   488,  -827,  1228, -2571,   490, -2571, -1847,
      -4,  -214, -2571, -2571, -1749,   286,  1003, -2571, -2571,   718,
    1382, -2571, -2571, -2571, -2571, -2571, -2571,   423, -2571,   125,
   -2571,  1389, -2571,  1072, -2571,   763, -2571, -2571, -2571, -2571,
    -462, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,   882,
   -2571, -1261, -2571,  1067, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  1533,
   -2571, -2571, -2571, -2571, -2571, -2571,   -54, -2571, -2571, -1497,
   -2571, -2571, -2571, -2571,   675, -1676, -2571,  -831, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,  2673, -2571, -2571, -2571,  2580,  2672, -1059, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,    52, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571,  2674, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  1126, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  -424,  2224, -2571,
   -2571, -2571, -2571, -2571,  2057, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571,  2073, -2571, -2571,   -55, -2571, -2571,  1127,
   -2571, -2571, -2571,  -694,  -195,  2447, -2571, -2571, -2571, -2571,
     -42, -2571,  -716,  2036,  1416, -2006,   796, -2571,  1129,  1786,
      86,  -129, -2571, -2571, -2571,  1575, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571,  1510, -2571,  1094, -2571,
    -367, -2571, -2571, -2571, -2571, -2571, -2571, -2571,  -378, -2571,
   -2571, -2571, -2571, -2571, -2571,   500, -2571,  1598,   481, -2571,
   -2571, -2571, -2571, -2571,   371, -2571,  -115, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,  1860, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
    -338, -2571,  1505,  1677, -2571, -2571,   379, -2571,  -399, -2571,
   -2571,   396,   704, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
     -95, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2570, -2571,  1735,   964,
    -988, -2571, -2571, -2571,  1361, -2571, -1368, -2571, -2571, -2571,
   -1346, -2571, -2571, -1336, -2571, -2571, -2571, -2571,  1383, -2571,
   -2571, -2571, -2571, -2571, -2571,   775, -2571, -2571, -2571, -2571,
   -2571, -2571,  -362, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571,  -324, -2571, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571, -2571,   748, -2571, -2571, -2571,  -207, -2571, -2571, -2571,
   -2571, -2571, -2571,   366, -2571, -2571,   720, -2571,  1070, -2571,
   -2571, -2571, -2571, -2571, -2571,  -957, -2571, -2571, -2571, -2571,
   -1406, -2571, -2571, -2571, -2571, -2571, -2571, -1959,    62, -2571,
   -1782,   336, -2571, -2571, -1683,   390,   392,   727, -2571, -1808,
   -2167, -2571, -2571,   108,  -212, -2571, -2571, -2571, -2571, -1937,
   -2571, -2571, -2571, -1315, -2571, -2571,  -510, -2571,  -710,  1463,
     101, -1654,   723, -2571,   322, -2571, -2571, -2571, -2571,  -709,
   -2571, -1679, -2323,  2770, -2571, -2571, -2571, -2571, -2571, -2571,
   -2125, -2571,   475, -2571, -1049, -2571,  1831, -2571, -2571,  -723,
    -105, -2571, -1895,  -104,   215,   502,    20, -1408, -1963,   359,
    -286,   631, -1834, -2571,   566, -2571, -2571, -2571,  1486,  -513,
   -2571, -2571,  -138,  1845, -2571,   916, -2571, -2571, -1273,   229,
   -2571, -2571, -2571, -1711,    -6, -2571, -2571, -2571,  1521, -2571,
   -2571, -2571, -2571, -2571, -2571, -2571, -2571, -2210,   -22, -2571,
   -2257, -2385, -1619,  -948, -2571, -2571,    -9,  -437,  -408,  -482,
    1079,  -705,     8,  1859,    84, -2571, -2571, -2571, -2571, -2571,
    1655, -2571,  -489, -2571, -2571, -2571, -2571, -2571, -2571, -2571,
   -2571,  -358,  1186,  2453, -2571, -2571, -2571, -2571
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1811
static const short yytable[] =
{
      43,   270,  1033,   388,   115,  1030,   260,  1018,    34,    58,
      60,   827,   885,    60,  1179,  1370,   286,  1403,   704,  1862,
    1234,  1207,   258,  2079,  1177,  1753,  1821,   419,  2215,   133,
     873,  2088,  1061,    34,  1730,   238,  1608,  1609,  1225,    72,
    2299,  1381,    76,    79,  2606,  2607,  2608,  2072,  2075,  2119,
     723,  2075,  1704,  1729,  2223,  2224,   115,  1651,   927,  1226,
     809,   930,  1518,   692,  1970,    42,   692,   692,  2178,    42,
      42,   293,   836,  1245,   130,  2439,   129,    79,    42,  1155,
     692,  1138,   340,   271,   272,   273,    42,  2026,    99,   139,
     672,   271,  2695,   719,  2610,   271,   146,  1127,  2273,   692,
     151,   704,   692,   153,   154,   271,  2424,  1892,   692,   157,
     158,  1226,   692,  1180,    42,  1226,   692,  1296,   301,   302,
     692,  1028,   142,    42,   692,   692,  1530,   692,   129,  1301,
     692,  1306,   692,   692,   692,  1226,    42,  1319,  1224,  2439,
     692,  1426,    42,   692,   921,   784,   840,   396,   234,   381,
     692,   237,  2166,   268,   268,   692,   241,  2565,  1186,  1187,
    1986,  1188,   692,  1209,  1210,   131, -1809,   883,    99,    42,
    2384,  2165,   203,   692,   943,  2358,  1028,   692,    42,    42,
     268,   692,  1028,  3012,    42,  3162,  1285,   692,  2545,  1531,
     692,  1532,   383,  1533,   275,  1028,   268,    42,   277,  2773,
     837,   838,   675,   271,   278,   279,   802,   690,    42,    42,
     876,  1227,  1228,  1760,   883,  2226,    42,    42,  1017,  1297,
    1761,   268,   271,   933,   934,    42,   271,  1891,  1892,    42,
     268,  2672,   298,   391,  2214,  1990,    42,  1285,   304,   401,
    2877,   942,   268,   785,  2384,    42,   785,  1143,  1144,   332,
    2738,   385,  1547, -1809,   294,  2095,   794,  1028,    42,    42,
     785,   403,  1636,  1637,   785,  2271,   271,   933,   934,    42,
    1578,   811,  1323,  1572, -1809,  1301,   785,    84,   794,  1757,
     407,  2182,  1281,    65,   822,  1025,  1023,   794,  2300,  2301,
    2302,  2303,  2304,  1870,   833,  2534,  2535,  2536,  2537,   839,
    2414,  1368,   561,   651,  2384,  1168,   875,   346,  1226,   348,
      42,  2293,  1216,  1217,    99,  2849,  1226,   822,  2564,   416,
    2976,   822,  1821,   712,    42,   822,  3011,   658,  1226,  1530,
    1222,   794,    84,  1226,   794,  1024,  3089,  2290,  2775,    67,
      42,  1162,  1600,  1286,  1453,   271,  1891,  1892,    42,  1411,
      65,    73, -1809,    42,   411,    35,  2477,   411,  1659,  1855,
      81,     1,  2312,   394,  2850,   411,   660,  3163,   305,  1660,
    1617,    84,  2381,   686,   643,   653,  1169,     2,     3,    84,
     394,   332,  1223,   332,    19,  3090,   104,  1257,    84,  1412,
    1661,   105,   700,    36,  1286,   306,  2072,  1662,   943,    84,
     661,  2237,  1552,  2822,  1226,   998,   999,   943,  2051,    19,
    2051,   411,   824,   132,  1403,  2076,   688,   763,   693,   694,
    1302,    84,   701,   706,  2099,   708,  1302,  2101,   711,   136,
     894,   136,    84,  1000,  1001,  1002,   106,   107,  2964,   694,
     795,  2191,  1993,  2801,   108,  2277,   777,  2096,  3092,  2972,
     943,    97,   654,     5,     6,  2977,     7,     8,  2408,   694,
      42,     9,  1537,  2835,  1282,  2123,  1325,  2124,   946,   777,
    2408,  2435,   694,  2453,   973,   655,  1894,  1758,    10,    11,
     895,  1579,   812,   692,   869,  2453,  2756,    84,   699,   730,
      42,  1895, -1809,   886,   892,  2415,    12,   908,   828,   830,
    2435,   912,  1163,  1548,  1621,   701,  2569,   918,  2875,   920,
    2618,   700,  1262,   777,   828,   828,    84,  2478,   896,  2406,
     944,  2034,   777,   777,  2037,   904,   777,  2699,    79,   386,
     777,   689,  1575,  2780,  1409,   382,   777,  2511,   777,  1382,
     922,  1334,   922,   828, -1809,   922,   828,  1240,   922,  1243,
    2780,  1427,  1429,  1430,  2359,  2385,  1431,  1432,  1386,  1835,
    2774,  2183,  2669,  1638,  2669,   945,    42,   689,  2806,  2823,
    2281,  1387,  2823,  1449,   269,   343,  2831,  2840,   384,  1588,
    2943,  1596,  1410,  2288,   143,  2387,  2388,  1181,  2389,  2390,
    2391,  2392,  2393,  2394,  2994,    42,  1318,  1894,  2994,   825,
    3063,   674,  3063,  2458,   692,   692,   692,   134,  3084,  3049,
    3107,   704,  1895,  1645,  1646,   897,   910,   984,  2739,   392,
    1399,  2969,  1656,  2797,  3125,   402,   935,   875,  2027,  2412,
    1156,  2387,  2388,  1499,  2389,  2390,  2391,  2392,  2393,  2394,
    2574,  1182,  2433,  2823,  1837,  1513, -1809,   404,  2499,  2759,
     971,  2772,  1331,   700,  1365,  1987,  1926,  2507,  2508,  1978,
    2744,  2878,  2887,  3120,  1283,  1696,   408,  2769,  2546,  1229,
    1514,  1026,  2227,   827,  2947,  2948,  1545,  3083,   274,   993,
    2440,   411,  1366,   737,  2710,  1246,   274,  1369,  1331,  2665,
     274,   898,   946,  2675,  1748,   738,   701,  1284,   109,  2080,
     274,   946,  1751,   986,   826,  1494,  1287,  2067,  1519,   826,
    1843,  1029,  2560,   945,  1752,  1232,  1894,   826,  2155,  1767,
     777,   777,   777,  1500,   110,  3121,  2746,  3122,   936,  2298,
    2751,  1895,   899,  2430,   704,  1549,   777,  2729,  1534,  1766,
    2410,    78,   777,   777,   946,  1856,  1535,   777,  1316,   839,
     875,  1135,  2682,  2429,  2685,  1183,  1230,  1287,  2111,  1926,
    1562,  1786,  2067,  1563,  1789,  1565,   803,   145,  2067,  1880,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
     777,  2898,   689,  1762,  1386,  1145,  2081,  1029,  1389,    42,
    1857,  2945,  1097,  2489,  2052,   111,  2066,  1387,   274,   900,
    2403,  2077,  2082,  1003,  1390,  1604,  1605,   187,   188,  2111,
    2100,  1578,   739,  2102,  3133,   189,    42,   274,  1994,  2523,
      42,   274,    42,  2305,   947,   948,   949,  2192,  2395,   138,
    2013,  2278,  2975,   777,   777,   950,    42,   743,   754,  2836,
    2949,  2669,    42,   869,  2409,  2083,  2776,  1557, -1809,  1098,
    1099,  1100,  1101,  1102,  1103,   886,  2411,  2436,  2525,  2454,
    1248,   274,   405,   901,  2873,  1104,  1105,  1106,  2320,   141,
    1148,  2455,   777,  1371,  2395,  2038,  1373,  1149,  2955,  2571,
    2958,  2959,  2960,  2961,   777,  2084,  2460,  2575,   112,   777,
    1004,  2829,  2570,  1374,  1255,  1652,  2619,  1414,  1736, -1809,
   -1809, -1809, -1809, -1809,    42,  2664,   951,   756,  2528,  2005,
    2472,  1998,  1273,  2700,  2085,  2802,   758,   689,  2006,  2781,
     752,   197,  1658,  2086,   717,  2716,  3147,   777,  3002,   143,
    3004,  1423,  2676,  1005,  1850,    42,  2787,  1997,  2287,  1617,
     274,   777,  2007,   147,   789,  2008,  2942,  2396,   200,   261,
     262,   263,   264,   265,  2807,  2824,  2764,   798,  2830,  1583,
    1408, -1517,  2832,  2009,  2839,  2813,  2944,  2524,   113,  1388,
     261,   262,   263,   264,   265,   184,   114,    42,  1517,    84,
    2995,  2329,   817,    84,  2996,    84,  3064,  2362,  3070,   196,
    1883,   823,  2930,  2396,  3085,  1383,  3108,    42,   236,  1391,
    1400,  1391,   235,  1374,  2397,    84,  1107,  1386,  1999,  1108,
    3126,  1653,   701,   757,  1389,   701,  2946,  1415,  1418,   909,
    1387,   708,  1579,   913,  2529,   759,   760,   917,  2952,  3152,
    1390,  1679,  1375,   761,   243,   925,   828,   777,   928,   828,
     828,   828,   828, -1809,   777,  3141,  1836,   777,  2469,  2484,
    2397,  3054,   699,  1861,    42,    42,    42,  3060,   828, -1809,
     777,   259,  2490,  1976,   777,    35,    36,  2997,  2010,  2677,
     251,  2678,   777,  1621,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,  2377,  2257,  2931,   252,    84,  2933,
    2829,  2829,  1617,  2698,   777,   777,  2702,  2717,  1376,   777,
    1679,   777,  2683,  1403,  1747,  1501,  1502,  1503,  2718,    42,
    1975,  1654,  2011,  1933,  1935,  3136,  1489, -1809,  1109,  2012,
   -1809, -1809,  2398,   654,  2530,  1525,  2556,    42,   701,  1945,
      84,  2428,  1375,  1110,   777,   777,   777,  1111,  2558,    42,
    1877,   254,  2950,  2974,  3094,   828,   655,  1516,  3095,  1520,
     828,  1213,  2749,  2803,   777,  1644,  2292,  3055,  1220,    42,
     692,  1648,    59,  1785,    42,  1680,  1788,  1165,  2398,  1671,
     261,   262,   263,   264,   265,  1112,   255, -1809,  2310,  3110,
     256,  1546,  1402,  1659,  1681,  1682,    42,  2956,  2399, -1809,
     834,   276,    42,  2956,  1660,   281,  2965,  2966,  2967,  2968,
     267,  1378,   886,  1113,  1683,  1018,  1849,   700,  1376,   190,
     777,   699,   828,    42,  2106,  1661,   877,  1379,    42,  1571,
     287,  1114,  1662, -1809,  2566,  2567,  1621,  1389,   883,  1586,
      42,   777,  1687,  3016,  2399,  1559, -1809,   828,   828, -1809,
     288,  1693,   828,  1390,  1680,   290,  1569,  1570,   777,    83,
    1266,    42,    42,  2731,   926,  2732,  2280,   929,   777,   291,
     932, -1809, -1809,  1681,  1682,  1312,  1377,    42,   692,  1094,
    1095,  1096,   701,  1129,   292,  2156,  1028,  2157,    42,   922,
     828,   828, -1809,  1683,  1097,  1253,  2168,    42,  2437,   692,
      84,  1495,    45,    42,   296,  1406,  1814,    42,  2313,  1815,
     135,   136,    84,  1115,  1826,     1,  1640,   297,   960,  1029,
    1029,  1378,   135,   136,  1649,  3087,  1649,   299,  1029,   961,
     303,     2,     3,   308,  2179,  1814,  3062,  1379,  1815,  3065,
    3066,  3067,  3068, -1809,   261,   262,   263,   264,   265, -1809,
     317,  1098,  1099,  1100,  1101,  1102,  1103,  1811,  2854,  2020,
    2494,    42, -1809, -1809,  2198,   700,  2520,  1104,  1105,  1106,
     326,  1029, -1809,  1130,  2491, -1809,   787,   327,  2914,  1116,
   -1809,   962, -1809,   333,  1391,  1092,  1093,  1094,  1095,  1096,
     796,    84,   336,   986,   801,  1400,   963,  2513,  1391,    42,
   -1809, -1809,  1097,    84,   337, -1809,   815,     5,     6,   338,
       7,     8,  2660,  1816,    42,     9,  1817,  1743,  1744,  1745,
     342,  2901,   839,  2902,    84,    84,  3042,  3043,   344,  1496,
    2855,  1496,    10,    11,  3016,  -266,  2112,   345,  1617,  1617,
      84,  2555,  1816,   875,  3128,  1817,   349,  2706,   309,   350,
      12,   720,   720,   777,   777,   777,   353,   777,  1135,  1098,
    1099,  1100,  1101,  1102,  1103,   354,    84,  1617,     2,     3,
    2704,   966,   967,  1805,   355,  1104,  1105,  1106,   359, -1809,
      46,   318, -1809, -1809,   777,   964,   356,   777,  1796,   360,
    3117,  3094,  1436,  1437,    47,  3095,  2856,  1830,  2857, -1809,
    1438,  1503,   777,   370, -1809,  1439,  1440,  1441,  1107,  2580,
    2581,  1108,  2250,  2858,   371,   271,  1891,  1892,    42,    48,
    1824,  2859,  -266,  3099,  2527,  2860,   777,  2188,  1831,  1832,
     777,   828,  1214,  1215,   374,   310,  1218,  1219,  -266,  3116,
    3112,  3118,  1869,  2107,     5,     6,   720,     7,     8,   777,
    2861,   311,     9,   339,  1438,  2582,   937,  1587,   136,  1439,
    1859,  1441,    84,   379,   777,  2125,   389,    49,   319,    10,
      11,   777,  1621,  1621,   390,  1259,  2222,    84,   393,   777,
    2418,  -266,  2420,  2421,   320,  1884,  1273,    12,  1909,   397,
    1053,   398,  2431,   399,   312,  2605,  2605,  2605,  2605,   400,
    3099,  1621,   135,   136,  2080,  1235,  1236,  1237,  1238,   406,
     828,   828,  1034,  1035,  1036,   417,  1107,  3112,   409,  1108,
     659,  -266,  1666,  1667,   828,  1674,  1675,   321,   664,   692,
    1109,  2686,  2811,  2812,   313,   692,  1827,  1828, -1809,   947,
     948,    14,  2461,  1029,   666,  1110, -1809,   667,   668,  1111,
    -266,   673,   676,   698,   679,  2848,   678,   692,    13,  -266,
     680,   682,  2021,   314,   683,  1260,   716,   322,   684,  2127,
     685,   914,   315,  2129,   687,  2033,  2033,  1054,  2132,  2033,
     975,   700,  2136,   976,  2138,  2139,  2140,  1112,  2721,   977,
      15,  2081,   978,  1055,   790,  1909,   323,  2068,  2068,   979,
     980,  2068,  1909,   981,   982,   324,  2108,  2082,   983,   985,
     807,   808, -1809,   991, -1809,  1113,   814,  1015,  2687,   816,
     989,   937,   990,   992,   996,  1016,   136,  1019,  2103, -1809,
    2714,  1415,  1021,  1114,  2688,   777,  1056, -1809,  1109,  1027,
    1022, -1809,  1391,     1,  1610,  1031,  1611,  1612,  1613,  1909,
    2083,    17, -1809,  1110,  1040,  1041,  1131,  1111,  1043,     2,
       3,  1142,  1146,  1147,  1158,  1150, -1809,  1128,  2158,  2159,
    1503,  2162,  2551,   839,  2553,  2722,  1057,  2689,  1044,   875,
    1045,   777,  1046,  1047,   777,  2762,  1048,  1151,  1049,  1050,
    2084,  2723,  2185,  1391,  1051,  1112,  1173,   777,   777,   777,
     777,   875,  2068,  1062,  1063,  1058,  1064,  1067,  2170,  1824,
    1068,  1153,  2175,  2175,  1059,  1115,  1071,  2690,  1073,  2085,
    1074,   777,  1075,  1113,  1076,  1077,  1078,  1178,  2086,  1079,
    1080,  2187,  1154,  1161,  2724,     5,     6,  1159,     7,     8,
    1164,  1114,  1211,     9,  1221,  1224,  2691,  1241,  2219,  1249,
    1258,   828,  1261,  1262,  1250,  2692,  1251,  1707,  1270,    16,
      10,    11,  1252,  1256,  2855,    51,    52,    53,    54,    55,
      56,    57,  1272,  1293,  2725,  2605,  2605,   777,    12,  2605,
    1294,  1116,  1292,  1226,  1909,  1909,  1894,  1295,  1300,  1304,
    1307,  1308,  1309,  1909,  1310,  1356,  1364,  1385,  1367,  1405,
    1422,  1895,  1018,  2726,  2236,  2905,  1421,  1423,  1424,  1425,
    1447,  1433,  2727,  2913,  1484,  1448,   701,  1450,  2583,  2705,
    1455,  2584,  1487,  1115,  2258,   692,   692,  2918,  1491,  1492,
    2856,  1493,  2857,  1506,  2585,  2632,  2633,  2634,   937,  2636,
    2637,  2638,  2639,  2640,  2641,  1512,  1526,  2858,  2644,  2740,
    1530,  1524,  1539,  1232,  1528,  2859,  1540,  1550,  1551,  2860,
    1553,  2227,  1555,  1560,  1564,  2872,  1582,  1566,  2872,  1575,
    1584,  1590,  1029,  2307,  2587,  2308,   651,  1592,  1302,  1589,
    1614,  1628,   651,  1615,  2861,  1616,  2588,  2068,  1630,  1116,
    1909,  1631,  1633,  1639,  2753,  1688,  1699,  2296,  1649,  1909,
    2714,  2755,   777,  1701,   777,  1617,  1702,  1705,  2973,  1706,
    1732,  1734,  2068,  1737,  1029,  1618,  1738,  1739,  1749,  1765,
    1735,  1750,  2363,  2033,  1754,  1794,  2518,  1756,  2589,  1763,
    1768,  1770,  1773,  1798,  1942,  1800,  1801,  1802,  2364,  2365,
    1803,  1804,  1807,  1808,  1806,  1810,  2068,  2366,   653,  1909,
    1301,  1909,  1809,  1812,   653,  1838,  1825,  1619,  1813,  1840,
    1841,  1620,  1845,  2068,  1847, -1809,  1853,  2590,  1854,   839,
     839,  1860,  1391,  1863,  2380,  1867,  2383,  1864,  1873,  2591,
    1881,  2367,  1887,  3036,  1920,  1922,  1921,  1926,   950,  1928,
    2368,  2592,  2593,  1708,  1973,  1400,  1974,  1391,  1985,  2594,
    1991,  2002,  2595,  2016,  2019,  1743,  2001,  2018,   777,  2527,
     274,  2605,  2443,  2030,  2041,  2042,  2043,  2605,  2605,  2369,
    2605,  2605,  2605,  2605,  2050,  2089,  2090,  2047,  2463,  2605,
    2091,  2468,  2092,  2093,  2094,    91,  2105,  2109,  2120,  1621,
    2121,  2122,  2128,  2131,  2141,  2142,  2143,   777,   777,  2147,
    2146,  1709,  2149,  2151,  2164,  2153,  2189,   777,  1362,  2169,
     777,  2184,  2186,  1710,  2370,  2470,  2195,  2241,  2242,  2196,
    2199,  2200, -1809,  1711, -1809, -1809, -1809,  2714,  1824,  2714,
    2485,   937,  2487,  2201,   777,  2204,  2203,  2202,  2220,   869,
     777,  1712, -1809,   777,  2221,  2229,  2230,  2231,  2503,  2827,
    2828,  1713,   777,   777,  1714,  2232,  2371,  3041,   185,   193,
    2233,  2234,  2235,  2238,   949,  2256,  2263,  1715,   777,  2265,
    3124,  2274,  2291,  1916,  2275,   701,  2907,  1909,  2279,  2276,
    2294,  2315,  2283,  1909,  1909,  1909,  1909,  1909,  1909,  2243,
    2244,  2245,  2246,  2247,  2248,  2904,  2284,  2317,  2316,   720,
    2605,  2318,  2323,  2605,  2605,  2605,  2605,  2386,  2405,   828,
    2379,   828,  2406,   193,  2416,  1716,  2419,  2407, -1754,   193,
    2422,  2243,  2244,  2245,  2246,  2247,  2248,  1909,  2413,  2432,
    2438,  2445,  2444,  2448,  2446,  2459,  2447,  2449,  2462,  2872,
    2068,  2465,  2450,  2748,  2451,  1717,  2596,  2596,  2596,  2596,
    2068,  2068,  2452,  2847,   937,  1718,  2456,  2464,  2471,  2475,
    2479,  2621,  2622,  2021,  2483,  2486,  2498,  2495,  2506,  2625,
    2598,  2598,  2598,  2598,  2516,  2538,  1719,  2524,  2550,  1720,
    2522,  1721,  2561,  3100,  3101,  3102,  3103,  3104,  3105,   193,
    2562,   193,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  2571,  2384,  2578,  2439,  2630,  2605,  1722,
    2616, -1809,  2620,  2635,  2642,  1097,  2605,  2643,  1723,  2631,
    2650,  2653,  2649,  2655,  2714,  2654,  2227,  2670,  2656,  2657,
    1909,  2658,  1909,  2659,  2116,  2673,  2680,  1320,  1375,  2694,
    2696,  2701,  1909,  3021,  1909,  2703,  2736,  1909,  2707,  1994,
    2730,  2741,  2068,  2684,  2068,  2742,  2743,  2744, -1809, -1809,
    2758, -1809,  2760, -1809,  2763,   193,  2767,  2671,  2425,  2674,
    2777,  2778,  1098,  1099,  1100,  1101,  1102,  1103,   944,  2790,
    2793,  1391,  2804, -1809,  2797,  1909,  1029,  2814,  1104,  1105,
    1106,  2815,  2816, -1809,  2817,  2823,  2818,  3165,  2819,   777,
    2820,  2833,  2834,  2754,  2844,  2845,  2852,  2880,  2881,  2403,
    2867,  2885, -1809,  2883,  2889,  2884,  2886,  2897,  2892,  2900,
     193,  2175,  2899,  2903,  2750,  2175,  2906,   692,  2912,   828,
    2910,  2916,   777,  2770,  2919, -1809,   828,  2920,  2917, -1809,
    1321, -1809,  2921,  2925,  2923, -1809,  2929,  2932,  1322,  2934,
    2936,   777,  2937,  2440,  1323,  2962,  1324,   714,  2938,  2939,
    2970,  2951,   777,  2953,  2989,  2990,  2998,  1325,  1610,  1909,
    1611,  1612,  1613,  2999,  3000,  3001,  3008,  1909,  2228,  3019,
    1909,  1909,  1909,  1909,  2786,  3022,  3034,  3035,  3048,  3050,
    1669,  1670,   792,  3040,  3047,  1326,  3051,  1686,   797,  3061,
     799,  3082,  3086,  3071,   806,  3088,  3093,   806,  2794,  3106,
     806,  1327,  3119,  3127,  3129,  2068,  1328, -1809,  3130,  3131,
     818,  3132,  3145,  3158,  2296,  3160,  2596,  2596,  1329,  1107,
    2596,  2502,  1108,  2434,  3144,  1330,  2457,  2212,  1574,   867,
    1872,  2821,    74,    75,   562,  1910,   878,   881,   884,  2171,
    2598,  2598,   905,  2482,  2598,  2239,  2240,  2241,  2242,   351,
     915,  2180,   199,   204,  2068,   283,  1640,  2825,  2826,  2827,
    2828,   875,  2597,  2597,  2597,  2597,   939,   347,   677,  1690,
     352,   285,  1691,   410,  2116,  2130,   663,  1771,  1081,  1082,
    1083,  2733,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,   387,  3142,   669,  1795,   378,
     376,   670,   903,  2148,  2031,  2039,   701,  1097,  1833,   701,
    1759,  1909,  2160,  2792,  1909,  1603,  1360,  2549,  1925,  2243,
    2244,  2245,  2246,  2247,  2248,  1607,  2382,  2255,  3159,  2167,
    1943,  2243,  2244,  2245,  2246,  2247,  2248,  1521,    69,  2915,
     159,  1109,  1910,    70,  2865,    71,  1029,  1879,  2908,  1910,
    2890,   813,  2895,   974,  1882,   341,  1110,  1627,  2252,  1886,
    1111,   995,  1298,  2980,  1098,  1099,  1100,  1101,  1102,  1103,
    1508,  1544,   828,  1988,  3046,  2853,  3148,   777,  2540,  1331,
    1104,  1105,  1106,  1498,  1852,  2663,  1332,  2988,  1244,  1456,
    1556,  2662,  2645,  2375,  1614,  2940,  1910,  1615,  1112,  1616,
    1420,  2154,  2285,  3151,  3138,  1700,  1733,  2314,  1333,  3072,
    2376,  2681,  2888,  1334,  2666,  2078,  1909,  2715,  2667,  1617,
    2378,  2874,  3080,  1643,   777,  2879,  1113,    64,  1923,  1618,
    2402,   939,  2623,  3017,  2810,  3018,  1348,  2577,  2709,  1909,
    3137,  1635,  2068,  2539,  1114,  3053,  1315,  2809,  2954,  1601,
     701,  2971,  2596,  2963,  2104,  1515,     0,   418,  2596,  2596,
       0,  2596,  2596,  2596,  2596,     0,     0,  2068,     0,  2068,
    2596,  1619,  1909,     0,     0,  1620,  2598,    83,     0,    42,
    2979,     0,  2598,  2598,     0,  2598,  2598,  2598,  2598,     0,
       0,     0,     0,     0,  2598,     0,     0,     0,     2,     3,
       0,  1136,  2532,     0,     0,     0,     0,     0,  2532,  1916,
    2541,  2542,  2543,  2544,     0,     0,     0,     0,     0,     0,
       0,  1107,     0,  1029,  1108,  1029,  1115,     0,  1909,     0,
       0,  1910,  1910,  2068,     0,  2895,     0,     0,     0,     0,
    1910,     0,  2597,  2597,  1167,     0,  2597,     0,     0,     0,
     161,     0,  2116,  1621,     0,     0,     0,     0,     0,     0,
    1185,  1185,  1185,     0,  1185,     0,  1185,  1185,     0,     0,
       0,     0,    91,    91,     5,     6,     0,     7,     8,  2794,
       0,     0,     9,     0,     0,     0,     1,  1909,     0,   162,
       0,  2596,  1116,     0,  2596,  2596,  2596,  2596,  3069,    10,
      11,     0,     2,     3,     0,     0,     0,     0,   163,     0,
       0,     0,  1640,   884,     0,  2598,     0,    12,  2598,  2598,
    2598,  2598,     0,     0,  1268,     0,     0,     0,     0,     0,
     701,     4,  2871,     0,  1909,  2871,     0,  1910,     0,     0,
       0,  3109,    84,  1109,  1909,     0,  1910,   164,   939,  1136,
       0,     0,     0,     0,     0,     0,     0,  1305,  1110,   165,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,   166,
     777,  3111,  2679,  1313,  1313,   777,     0,     0,     5,     6,
       0,     7,     8,     0,     0,     0,     9,   167,    13,     0,
       0,  2208,  2209,     0,     0,     0,  1910,   168,  1910,  2596,
    1112,     0,  2218,    10,    11,     0,     0,  2596,     0,     0,
    2116,     0,     0,   169,     0,     0,     0,     0,     0,     0,
    1029,    12,  1909,  2598,  2068,     0,     0,     0,  1113,     0,
       0,  2598,     0,     0,     0,     0,     0,     0,     0,  1910,
       0,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,  3156,   170,     0,  2259,  2260,  2261,  2262,     0,
       0,  1909,     0,  2267,  2268,  2269,  2270,     0,     0,     0,
    2272,     0,     0,     0,     0,     0,   171,     0,  2597,     0,
       0,   777,     0,     0,  2597,  2597,     0,  2597,  2597,  2597,
    2597,   172,    13,     0,  2116,     0,  2597,     0,   173,     0,
       0,   174,  2779,     0,     0,  2782,  2783,  2784,  2785,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   175,     0,     0,   176,     0,   177,  1115,  2992,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1490,     0,   178,     0,     0,     0,
       0,     0,     0,     0,  2321,  2322,    91,     0,    91,   884,
     806,  2326,  2327,     0,   179,     0,     0,  1507,   818,     0,
       0,   884,     0,     0,  1910,   193,     0,     0,  1522,     0,
    1910,  1910,  1910,  1910,  1910,  1910,  1037,  1038,  1039,    16,
       0,   939,     0,     0,  1116,     0,     0,     0,     0,     0,
       0,     0,  1052,     0,     0,     0,     0,     0,  1065,  1066,
       0,     0,    14,  1070,     0,     0,     0,  2597,     0,     0,
    2597,  2597,  2597,  2597,  1910,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,  1910,  1910,  1910,  1910,     0,     0,  2876,
       0,     0,     0,     0,     0,     0,  2871,     0,     0,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1567,     0,     0,     0,     0,     0,   720,   720,   720,
       0,   720,   720,   720,   720,   720,   720,     0,     0,     0,
     720,  1096,     0,    16,     0,  1594,     0,     0,  2473,  2474,
    1597,     0,     0,     0,  1097,     0,     0,  2481,     0,     0,
       0,     0,     0,  1626,   939,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,  2597,     0,  1910,     0,  1910,
       0,     0,     0,  2597,     0,     0,  2509,  2510,     0,  1910,
       0,  1910,     0,     0,  1910,     0,     0,     0,     0,     0,
       0,  2935,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,  1673,
       0,     0,     0,     0,  2116,     0,     0,  1104,  1105,  1106,
       0,     0,  1910,     0,     0,     0,     0,     0,     0,     0,
    2552,     0,  2554,     0,     0,  2194,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   884,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   937,     0,     0,     0,     0,     0,
    2626,  2627,     0,     0,  2628,  2629,     0,     0,     0,     0,
       0,     0,     0,  3007,     0,     0,  1910,     0,     0,     0,
       0,     0,     0,     0,  1910,     0,     0,  1910,  1910,  1910,
    1910,     0,  1098,  1099,  1100,  1101,  1102,  1103,  2652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,  1428,     0,     0,     0,     0,     0,     0,
    1435,     0,     0,  1446,     0,     0,     0,     0,  1107,     0,
       0,  1108,  3059,  1910,  1910,     0,  1451,  1910,     0,  1189,
    1454,     0,     0,     0,     0,     0,     0,     0,  1460,     0,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1844,     0,     0,     0,     0,     0,     0,     0,  1851,  3081,
    1482,  1483,     0,     0,     0,  1485,     0,  1486,     0,   884,
       0,     0,     0,  1081,  1082,  1083,     0,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
     185,     0,  2747,     0,     0,     0,  2752,     0,     0,     0,
       0,     0,  1097,  1910,     0,     0,  1910,     0,  1910,  2757,
       0,  1910,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2768,  1107,
    1109,  1097,  1108,     0,   842,     0,   884,  1977,   884,     0,
       0,     0,   878,   843,     0,  1110,     0,  3007,     0,  1111,
       0,     0,   844,     0,     0,     0,     0,   845,     0,  1098,
    1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,
       0,  1190,     0,     0,  2025,  1104,  1105,  1106,     0,     0,
       0,     0,     0,     0,     0,     0,  3059,  1112,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,   846,     0,     0,  1104,  1105,  1106,     0,     0,   847,
       0,     0,     0,  1910,     0,  1113,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,  1910,     0,     0,     0,
     884,   193,     0,     0,     0,     0,     0,     0,     0,  1910,
       0,  1109,     0,     0,     0,  1910,  1910,     0,  1910,  1910,
    1910,  1910,     0,     0,     0,   848,  1110,  1910,     0,  1910,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     849,     0,     0,     0,     0,     0,     0,   850,  1191,   851,
    1910,   884,     0,   884,  1192,  1193,  1194,     0,  1112,   852,
       0,     0,   884,     0,     0,  1115,  1107,     0,     0,  1108,
       0,     0,     0,     0,  1195,  1910,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   853,  1113,     0,     0,     0,
       0,     0,     0,   854,     0,  1107,     0,     0,  1108,  2193,
       0,     0,     0,     0,  1114,     0,   937,     0,     0,     0,
       0,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  2217,     0,
     855,  1116,     0,     0,  1910,     0,     0,  2928,  1910,     0,
    1097,  1910,  1910,  1910,  1910,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2941,   856,     0,     0,  1774,
    1775,  1776,     0,  1778,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2251,  1597,     0,  1910,     0,     0,
       0,  1910,  1196,     0,     0,  1197,  1115,     0,  1109,     0,
    1793,  1910,     0,  1198,   857,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,  1110,     0,   858,     0,  1111,  1452,     0,
       0,     0,     0,  1104,  1105,  1106,     0,  1109,     0,     0,
   -1810,     0,     0,     0,     0,     0,     0,     0,  1199,     0,
       0, -1810,  1110, -1810, -1810, -1810,  1111,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,  1910,     0,     0,     0,
       0,     0,  1116,     0,  1910,  1848,     0,     0,     0, -1810,
       0,     0,     0,  1200,     0,     0,     0,     0,     0,  1910,
    1793,     0,     0,  1113,  1112,     0,     0,     0,     0,  2319,
       0,     0,     0,  1201,  1202,     0,     0,     0, -1810,     0,
       0,  1114,     0,  3044,  1203,     0,     0,     0,     0,  1204,
       0,     0,  1113,     0,   859,   860,   861,     0,  1910,     0,
       0,     0,     0,     0,     0,     0,     0,   862,     0,     0,
    1114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1810,     0,     0,     0,     0,     0,     0,     0,  1205,     0,
       0,     0,     0,     0,     0,     0,   937,  3073,  3074,     0,
    3076,     0,  3078,  3079,  1107,     0,     0,  1108,   884,     0,
   -1810,     0,     0, -1810,     0,     0,     0,     0,     0,     0,
    1206,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1810,     0,
       0,     0,     0,     0,     0,     0, -1810,     0, -1810,     0,
       0,     0,  1115,     0,     0,     0,     0, -1810,   884,     0,
       0,     0,     0, -1810,     0,     0,     0,     0,     0,     0,
     863, -1810,     0,     0,     0, -1810,     0,     0,     0,     0,
       0, -1810,     0,     0,     0, -1810, -1810, -1810, -1810,  1116,
       0,  3134,     0,  3135,     0,     0,     0,     0,     0,     0,
   -1810,     0,  2500,     0,   714,     0,  2504,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1810,  1116,  2515,
   -1810,     0, -1810,     0,   193,     0,  1109,     0,     0, -1810,
       0,     0,     0,     0,     0,     0,     0,  2144,     0,  3150,
    2144,  1110, -1810,     0,     0,  1111,  1755,     0,     0,     0,
       0,     0, -1810,     0,     0,  3153,  3154,     0,     0,  3155,
       0,     0,  3157,     0,     0,     0,     0,     0,     0,     0,
       0, -1810, -1810,     0,     0,     0,     0,     0,  2557,  2559,
       0,     0,     0,  1112,     0,     0, -1810,     0,     0,     0,
       0,     0,     0,     0, -1810,     0,     0,     0, -1810,     0,
       0,     0,     0,     0,     0,     0,     0, -1810, -1810, -1810,
       0,  1113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2624,     0,     0,     0,     0,  1081,  1082,  1083,  1114,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,  1097,     0,     0,     0,     0,
       0,  2646,     0,     0,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2661,     0, -1810,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1810,     0,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1189,  1097,
       0,  1115,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103, -1810,  1104,  1105,
    1106,     0,     0,     0,     0,   884,     0,  1104,  1105,  1106,
       0,     0,     0,  1081,  1082,  1083,     0,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
       0,     0,     0,     0,     0,   884,  1098,  1099,  1100,  1101,
    1102,  1103,  1097,     0,     0,     0,     0,  1116,     0,     0,
     193,     0,  1104,  1105,  1106,     0,     0,     0,     0, -1810,
       0,     0,     0,     0,     0,  1597,     0,     0,     0,     0,
       0,     0,     0,     0,   939,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1810,     0,     0,     0,  1098,
    1099,  1100,  1101,  1102,  1103,     0,     0,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,  1104,  1105,  1106,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,     0,     0,     0,
    1190,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0, -1810,  1108,     0,     0,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0, -1810, -1810, -1810, -1810, -1810,
   -1810, -1810,     0, -1810, -1810,     0,     0,     0,     0,     0,
       0,     0,     0,  1793,  1793,     0,     0,     0,     0,     0,
   -1810,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,  1107,     0,     0,  1108,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2497,     0,     0,  1793,
       0,     0,  2646,     0,     0,     0,     0,     0,  1793,  1793,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,  1191,     0,  1108,
       0,  1109,     0,  1192,  1193,  1194,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,  1764,     0,  1195,     0,  1110,     0,     0,     0,  1111,
       0,     0,     0,  2053,     0,     0,     0,     0,     0,     0,
       0,     0,  1888,  1889,  1890,     0,     0,     0,   271,  1891,
    1892,    42,   884,     0,     0,  1109,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
    1110,     0,     0,     0,  1111,     0,     0,     0,     0,  1107,
       0,     0,  1108,     0,     0,     0,  1113,     0,  1893,     0,
       0,     0,     0,     0,     0,  1113,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
    1597,     0,  1112,  1114,     0,     0,     0,     0,  1109,     0,
       0,     0,     0,  1541,     0,     0,     0,     0,     0,     0,
       0,  1196,     0,  1110,  1197,     0,     0,  1111,  1769,     0,
    1113,     0,  1198,     0,     0,     0,     0,     0,     0,     0,
       0,  1597,     0,     0,     0,     0,     0,     0,  1114,     0,
       0,     0,     0,     0,     0,  2646,     0,     0,     0,     0,
    2983,     0,  2985,     0,     0,  1112,     0,  1199,     0,     0,
       0,     0,     0,     0,     0,     0,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,  1115,     0,     0,     0,     0,
       0,  1109,     0,  1113,     0,     0,     0,     0,     0,     0,
       0,   884,  1200,     0,   700,  2734,  1110,     0,     0,   884,
    1111,  1114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1201,  1202,     0,     0,   939,     0,     0,     0,
    1115,     0,   193,  1203,     0,     0,     0,     0,  1204,     0,
       0,     0,  1116,     0,     0,     0,     0,     1,  1112,     0,
    2053,  1116,     0,     0,     0,     0,     0,  1793,     0,  1888,
    1889,  1890,   420,     2,     3,   271,  1891,  1892,    42,     0,
       0,   421,     0,     0,     0,     0,  1113,  1205,     0,     0,
       0,     0,     0,   422,   423,     0,   424,     0,     0,     0,
       0,     0,     0,  1115,  1114,     0,  1116,     0,     0,     0,
     425,     0,     0,     0,     0,  1893,     0,   426,  2054,  1206,
       0,     0,     0,     0,     0,     0,     0,     0,   427,   428,
     429,     0,     0,     0,     0,     0,  1185,  1185,  1185,  1185,
    1185,  1185,     0,     0,   430,     0,   431,   432,   433,     5,
       6,   434,     7,     8,   435,     0,   436,     9,   437,   438,
       0,     0,     0,     0,     0,   439,     0,     0,   440,  1116,
     441,   442,   443,     0,    10,    11,     0,     0,     0,     0,
     444,     0,   445,   446,     0,   447,  1115,   448,   449,     0,
       0,   450,    12,     0,     0,   451,   452,   453,     0,   454,
     455,     0,     0,     0,   456,   457,   458,     0,   459,     0,
       0,     0,   460,     0,   461,   462,     0,     0,     0,  1894,
     463,     0,     0,     0,   464,     0,     0,   465,     0,   466,
       0,   467,     0,   468,  1895,   469,   470,     0,   471,   472,
     473,   700,     0,     0,   474,     0,   475,   476,     0,   477,
       0,  1896,  1116,     0,  2055,     0,     0,   478,   479,     0,
       0,     0,     0,     0,     0,     0,  2056,  1898,     0,     0,
     480,     0,     0,   481,   482,     0,   939,   483,   484,     0,
       0,   485,   486,     0,     0,     0,     0,     0,     0,     0,
     487,   488,   489,     0,   490,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   491,   492,   493,  1900,   494,     0,
       0,     0,   495,   496,     0,     0,     0,   497,     0,  1901,
       0,     0,     0,     0,     0,   498,     0,     0,     0,     0,
       0,     0,     0,   499,   500,   501,     0,     0,     0,     0,
       0,   502,   503,     0,     0,  2054,     0,   504,     0,     0,
     505,     0,     0,     0,   506,   507,     0,     0,     0,     0,
       0,  1902,     0,     0,     0,   508,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,   509,     0,     0,     0,     0,     0,     0,
       0,   510,     0,     0,     0,  1097,     0,   511,     0,     0,
    1903,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1904,     0,     0,     0,     0,     0,     0,     0,
     110,     0,     0,     0,  1905,  1906,     0,   512,     0,   513,
     514,     0,  1907,     0,     0,  1908,     0,     0,   515,     0,
       0,     0,     0,   274,     0,     0,  1894,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,  1895,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,   516,  1896,     0,
       0,  2055,     0,     0,     0,     0,     0,     0,   517,     0,
       0,     0,     0,  2056,  1898,   518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   519,
     520,  2227,     0,     0,   521,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1900,     0,   522,     0,     0,     0,
       0,     0,   523,   524,   525,   526,  1901,     0,     0,   527,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
     529,   530,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   531,     0,   532,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,   534,  1902,     0,
     535,     0,     0,     0,     0,     0,   536,     0,     0,     0,
       0,  1793,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   537,     0,     0,   538,     0,  1903,     0,     0,
     539,     0,     0,   540,   541,     0,     0,     0,     0,  1904,
       0,     0,     0,     0,     0,     0,     0,     0,   542,     0,
       0,  1905,  1906,     0,     0,   543,     0,     0,     0,  1907,
       0,     0,  1908,     0,     0,     0,     0,     0,     0,     0,
     274,     0,     0,     0,     0,     0,     0,     0,   544,   545,
     546,   547,   548,   549,   550,     0,     0,   551,     0,   552,
       0,   553,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,  1777,     0,     0,     0,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,     0,     0,  1098,  1099,
    1100,  1101,  1102,  1103,  1097,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,  1104,  1105,  1106,     0,  1081,  1082,
    1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,     0,  1113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1105,  1106,
       0,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
    1097,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1097,
       0,     0,     0,     0,     0,  1107,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,  1108,  1104,  1105,  1106,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
       0,  1107,     0,     0,  1108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,  1111,  1779,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,  1107,     0,     0,  1108,     0,  1104,
    1105,  1106,     0,     0,  1112,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,  1111,
    1780,     0,  1113,  1107,     0,     0,  1108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,  1110,     0,
       0,     0,  1111,  1781,  1081,  1082,  1083,     0,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,  1113,     0,     0,     0,     0,
       0,     0,     0,  1097,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,  1114,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1110,  1115,     0,     0,  1111,     0,     0,  1113,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1109,  1114,     0,     0,     0,
    1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,
    1110,     0,     0,  1112,  1111,     0,  1104,  1105,  1106,     0,
       0,     0,     0,     0,     0,     0,  1783,     0,     0,     0,
       0,     0,     0,     0,     0,  1115,     0,     0,  1116,     0,
       0,  1113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,  1114,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1115,     0,
    1113,     0,     0,  1946,  1947,  1948,  1949,  1950,  1951,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,     0,
       0,  1116,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,  1082,  1083,     0,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
       0,  1115,  1952,     0,  1116,     0,  1098,  1099,  1100,  1101,
    1102,  1103,  1097,     0,     0,     0,     0,  1107,     0,  1112,
    1108,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,  1784,     0,     0,     0,     0,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,  1113,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,  1114,     0,  1116,     0,  1098,
    1099,  1100,  1101,  1102,  1103,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,  1105,  1106,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,  1116,     0,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,     0,     0,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1098,  1099,  1100,  1101,  1102,  1103,     0,  1109,
       0,     0,     0,     0,  1097,     0,     0,  1115,  1104,  1105,
    1106,     0,     0,     0,  1110,     0,     0,     0,  1111,     0,
       0,     0,     0,  1107,     0,     0,  1108,     0,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,  1787,
       0,     0,     0,  1116,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,  1113,     0,  1107,     0,     0,  1108,
       0,     0,     0,     0,     0,     0,  1953,     0,     0,     0,
       0,     0,  1114,     0,     0,     0,   724,     0,     0,  1954,
       0,     0,     0,     0,     0,   725,   726,     0,     0,     0,
       0,   271,   727,   728,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1109,     0,     0,     0,  1107,
       0,     0,  1108,     0,     0,     0,   729,     0,     0,     0,
    1110,   730,     0,     0,  1111,     0,     0,     0,   731,     0,
       0,     0,     0,  1955,     0,     0,     0,     0,     0,     0,
    1956,     0,     0,     0,  1115,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,     0,   732,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,  1109,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,  1957,
       0,  1108,   724,  1110,     0,     0,     0,  1111,     0,     0,
    1113,   725,   726,     0,     0,     0,     0,   271,   727,   728,
      42,     0,     0,  1958,     0,     0,     0,     0,  1114,     0,
    1116,     0,     0,  1959,  1960,     0,     0,     0,     0,  1961,
       0,     0,     0,     0,     0,  1112,     0,     0,     0,  1962,
       0,  1109,   729,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,   731,     0,  1110,    84,     0,   733,
    1111,  1963,     0,  1113,  1964,  1965,     0,     0,     0,     0,
    1966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,  1114,   732,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,  1112,  1111,
    1115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,  1113,  1967,     0,  1111,
       0,     0,   724,     0,     0,     0,     0,  1112,  1968,     0,
       0,   725,   726,     0,  1114,     0,     0,   271,   727,   728,
      42,  1888,  1889,  1890,     0,     0,   734,   271,  1891,  1892,
      42,   735,     0,  1115,     0,  1113,  1116,  1112,     0,     0,
       0,     0,     0,    84,     0,   733,     0,     0,     0,     0,
    1782,     0,   729,  1114,     0,     0,     0,   730,     0,   736,
       0,   724,     0,     0,   731,  1113,     0,  1893,     0,     0,
     725,   726,     0,     0,     0,     0,   271,   727,   728,    42,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,   732,     0,   737,     0,  1115,     0,     0,  1116,
       0,     0,     0,     0,     0,     0,   738,     0,     0,     0,
       0,   729,     0,     0,     0,     0,   730,     0,     0,     0,
       0,     0,     0,   731,   739,     0,     0,     0,     0,   740,
       0,     0,   741,     0,     0,  1115,     0,     0,     0,     0,
       0,     0,   734,   742,     0,     0,     0,   735,     0,   743,
       0,   732,     0,     0,     0,     0,     0,     0,     0,   744,
       0,     0,  1116,     0,   745,  1115,     0,   746,     0,     0,
     747,     0,     0,     0,     0,   736,     0,     0,     0,   748,
     749,     0,     0,    84,     0,   733,     0,     0,     0,     0,
       0,     0,     0,   700,     0,     0,     0,     0,     0,     0,
       0,  1116,     0,     0,     0,     0,     0,     0,     0,     0,
     737,     0,     0,     0,     0,     0,     0,     0,     0,  1132,
     750,     0,   738,     0,   751,     0,     0,     0,     0,     0,
       0,  1116,   752,     0,     0,     0,     0,     0,     0,     0,
     739,     0,    84,   753,   733,   740,     0,     0,   741,   754,
       0,     0,     0,     0,     0,  1888,  1889,  1890,     0,   742,
       0,   271,  1891,  1892,    42,   743,     0,     0,     0,     0,
       0,     0,     0,     0,   755,   744,     0,     0,     0,     0,
     745,     0,   734,   746,     0,     0,   747,   735,     0,     0,
       0,     0,     0,     0,     0,   748,   749,  2054,     0,     0,
       0,  1893,     0,     0,     0,  1888,  1889,  1890,     0,     0,
       0,   271,  1891,  1892,    42,   736,     0,     0,   756,     0,
       0,     0,     0,     0,     0,   757,     0,   758,     0,     0,
       0,     0,     0,     0,     0,     0,   750,   759,   760,     0,
     751,   734,     0,     0,     0,   761,   735,     0,   752,     0,
     737,  1893,     0,     0,     0,     0,   274,     0,     0,   753,
       0,  2161,   738,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,   736,     0,     0,     0,     0,     0,
     739,     0,     0,     0,     0,   740,     0,     0,   741,     0,
     755,     0,     0,     0,  1888,  1889,  1890,     0,  1894,   742,
     271,  1891,  1892,    42,     0,   743,     0,     0,     0,   737,
       0,     0,     0,  1895,     0,   744,     0,     0,     0,     0,
     745,   738,     0,   746,     0,     0,   747,   700,     0,     0,
    1896,     0,     0,  2055,   756,   748,   749,     0,     0,   739,
    1893,   757,     0,   758,   740,  2056,  1898,   741,     0,     0,
       0,     0,     0,   759,   760,     0,     0,     0,   742,     0,
       0,   761,     0,     0,   743,     0,     0,     0,     0,     0,
       0,     0,   274,     0,   744,  2519,   750,   700,     0,   745,
     751,     0,   746,     0,     0,   747,  1900,     0,   752,     0,
       0,     0,     0,     0,   748,   749,     0,     0,  1901,   753,
       0,     0,  1888,  1889,  1890,   754,     0,     0,   271,  1891,
    1892,    42,     0,     0,     0,     0,  2580,  2581,   161,     0,
       0,     0,   271,  1891,  1892,    42,     0,     0,     0,     0,
     755,     0,     0,     0,     0,   750,     0,     0,     0,   751,
    1902,     0,     0,     0,     0,     0,     0,   752,  1893,     0,
       0,     0,     0,     0,     0,     0,     0,   162,   753,     0,
       0,     0,  2582,     0,   754,     0,   700,     0,     0,     0,
       0,     0,     0,     0,   756,     0,   163,     0,     0,  1903,
       0,   757,     0,   758,     0,     0,     0,     0,     0,   755,
       0,  1904,     0,   759,   760,     0,     0,     0,     0,     0,
       0,   761,     0,  1905,  1906,     0,     0,     0,     0,     0,
       0,  1907,   274,     0,  1908,   164,     0,  2580,  2581,     0,
       0,     0,   274,   271,  1891,  1892,    42,   165,     0,     0,
       0,     0,  1894,   756,     0,     0,     0,   166,     0,     0,
     757,     0,   758,     0,     0,     0,     0,  1895,     0,     0,
       0,     0,   759,   760,     0,   167,     0,     0,     0,     0,
     761,     0,     0,  2582,  1896,   168,     0,  1897,     0,     0,
       0,   274,     0,     0,   700,     0,     0,     0,     0,     0,
    1898,   169,  1894,     0,     0,     0,     0,     0,   700,     0,
       0,     0,     0,     0,     0,     0,     0,  1895,  1890,     0,
       0,     0,   271,  1891,  1892,    42,     0,   271,  1891,  1892,
      42,     0,     0,     0,  1896,     0,   205,  1897,     0,  1899,
    1900,   170,     0,     0,     0,     0,     0,     0,     0,     0,
    1898,     0,  1901,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1893,     0,   171,     0,     0,  2582,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2227,     0,   172,
       0,     0,     0,   206,   207,     0,   173,     0,     0,   174,
    1900,  1894,     0,   208,  1902,     0,     0,     0,     0,     0,
       0,     0,  1901,     0,     0,     0,  1895,     0,     0,   700,
     175,     0,     0,   176,     0,   177,     0,     0,     0,     0,
       0,     0,     0,  1896,     0,     0,  1897,     0,     0,     0,
       0,     0,     0,  1903,   178,     0,     0,     0,     0,  1898,
       0,     0,     0,     0,  1902,  1904,     0,     0,     0,     0,
       0,     0,   179,     0,     0,     0,     0,  1905,  1906,     0,
       0,     0,     0,     0,     0,  1907,     0,     0,  1908,     0,
       0,     0,     0,     0,     0,     0,   274,     0,  3056,  1900,
       0,     0,     0,  1903,     0,     0,     0,     0,   700,     0,
       0,  1901,     0,   700,     0,  1904,     0,     0,     0,  1894,
       0,     0,     0,     0,     0,     0,     0,  1905,  1906,     0,
       0,     0,     0,  1894,  1895,  1907,     0,     0,  1908,     0,
    1946,  1947,  1948,  1949,  1950,  1951,   274,     0,  1895,     0,
       0,  1896,     0,  1902,  1897,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2583,     0,  1898,  2584,     0,
       0,     0,     0,     0,     0,  2332,  2333,     0,  2334,  2335,
    2336,  2585,     0,     0,   209,     0,     0,     0,     0,     0,
       0,     0,  1903,     0,     0,     0,     0,     0,     0,  1952,
       0,     0,     0,     0,  1904,     0,     0,  1900,     0,     0,
       0,     0,     0,     0,     0,     0,  1905,  1906,     0,  1901,
    2586,  2587,     0,   210,  1907,     0,     0,  1908,     0,     0,
       0,     0,     0,  2588,  1894,   274,     0,     0,     0,     0,
       0,     0,   211,     0,     0,     0,     0,     0,     0,  1895,
       0,     0,     0,     0,     0,     0,     0,     0,   212,     0,
       0,  1902,     0,     0,     0,     0,  2583,     0,     0,  2584,
       0,     0,     0,     0,     0,  2589,     0,     0,  2337,     0,
       0,   213,  2585,     0,     0,     0,  2338,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
    1903,     0,     0,   215,  3023,     0,     0,     0,     0,     0,
       0,     0,  1904,  1894,  2590,     0,     0,     0,  1894,     0,
    2339,   216,  2587,     0,  1905,  1906,  2591,     0,  1895,  2340,
       0,   217,  1907,  1895,  2588,  1908,     0,     0,  2592,  2593,
       0,     0,     0,   274,     0,  1896,  2594,   218,  1897,  2595,
    2583,     0,     0,  2584,     0,     0,     0,   274,  2341,  2342,
    3024,  1898,     0,     0,     0,     0,  2585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2589,     0,     0,     0,
       0,     0,     0,     0,     0,  3025,     0,   219,     0,     0,
       0,     0,     0,     0,  3026,     0,     0,     0,     0,     0,
       0,  1900,     0,  2343,     0,     0,  2587,     0,     0,     0,
     220,     0,     0,  1901,     0,  2590,     0,     0,  2588,     0,
       0,     0,     0,     0,     0,   221,     0,  2591,     0,     0,
    3027,     0,   222,  1953,     0,   223,     0,     0,  3028,  2592,
    2593,     0,     0,     0,     0,  2344,  1954,  2594,     0,     0,
    2595,     0,     0,     0,     0,  1902,   224,     0,   274,   225,
    2589,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     227,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1903,     0,     0,     0,   228,  2590,
       0,  2345,     0,     0,     0,     0,  1904,     0,     0,     0,
    1955,  2591,     0,     0,     0,     0,     0,  1956,  1905,  1906,
       0,     0,     0,  2592,  2593,     0,  1907,     0,     0,  1908,
       0,  2594,  3029,     0,  2595,     0,     0,   274,     0,     0,
     229,     0,   274,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1957,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1958,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1959,  1960,     0,     0,     0,     0,  1961,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1962,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1963,     0,
       0,  1964,  1965,     0,     0,     0,     0,  1966,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1967,     0,     0,     0,     0,     0,
       0,     0,     0,  3030,     0,  1968,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2346,
    2347,  2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355
};

static const short yycheck[] =
{
       4,   196,   718,   330,    68,   715,   190,   701,     0,    13,
      14,   502,   525,    17,   841,   991,   214,  1005,   426,  1568,
     876,   852,   178,  1706,   838,  1433,  1523,   365,  1875,    84,
     519,  1710,   741,    25,  1402,   156,  1297,  1298,   870,    31,
    2003,   998,    46,    47,  2301,  2302,  2303,  1701,  1702,  1757,
     449,  1705,  1388,  1399,  1888,  1889,   120,  1330,   547,     5,
     484,   550,    20,   421,  1629,    27,   424,   425,  1817,    27,
      27,   227,   509,     5,    78,     5,    68,    81,    27,     5,
     438,   791,   266,    24,    25,    26,    27,     5,    63,    93,
     390,    24,  2415,    26,  2304,    24,   100,    26,  1945,   457,
     104,   509,   460,   107,   108,    24,    25,    26,   466,   113,
     114,     5,   470,    26,    27,     5,   474,   931,   239,   240,
     478,    25,    97,    27,   482,   483,     5,   485,   120,     5,
     488,   945,   490,   491,   492,     5,    27,   964,     5,     5,
     498,  1033,    27,   501,   543,   456,   513,   342,   152,     5,
     508,   155,  1806,     5,     5,   513,   160,  2282,   848,   849,
     100,   851,   520,   853,   854,    81,    62,    25,   143,    27,
       6,    20,   147,   531,   274,   134,    25,   535,    27,    27,
       5,   539,    25,    26,    27,   162,    33,   545,    62,    68,
     548,    70,     5,    72,   198,    25,     5,    27,    19,  2522,
     511,   512,   397,    24,    25,    26,    25,   421,    27,    27,
     521,    81,    82,    19,    25,  1894,    27,    27,   700,   935,
      26,     5,    24,    25,    26,    27,    24,    25,    26,    27,
       5,  2398,   236,     5,    25,  1641,    27,    33,   242,     5,
       5,    65,     5,   457,     6,    27,   460,    87,    88,   253,
       5,     5,   344,   339,   229,   207,   470,    25,    27,    27,
     474,     5,   135,   136,   478,  1941,    24,    25,    26,    27,
      23,   485,   235,   339,   360,     5,   490,   190,   492,   391,
       5,     5,   162,    19,   498,     5,   538,   501,    48,    49,
      50,    51,    52,   339,   508,  2232,  2233,  2234,  2235,   513,
     430,     5,   366,   367,     6,   546,   520,   282,     5,   284,
      27,  1994,   859,   860,   289,   538,     5,   531,  2281,   361,
       5,   535,  1819,    26,    27,   539,  2896,   369,     5,     5,
     333,   545,   190,     5,   548,   587,   538,  1991,     5,     0,
      27,   458,   189,   190,  1067,    24,    25,    26,    27,   576,
      86,    31,    91,    27,   358,    28,   458,   361,   438,     5,
     625,    30,  2016,   338,   587,   369,   391,   344,   430,   449,
     295,   190,  2055,   415,   366,   367,   617,    46,    47,   190,
     355,   385,   385,   387,     0,   587,    55,   900,   190,   616,
     470,    60,   190,    29,   190,   457,  2050,   477,   274,   190,
     425,   430,  1234,   430,     5,    56,    57,   274,     5,    25,
       5,   415,   374,   616,  1402,     5,   420,   450,   422,   423,
     150,   190,   426,   427,     5,   429,   150,     5,   432,   458,
     104,   458,   190,    84,    85,    86,   105,   106,  2823,   443,
     473,     5,   149,  2568,   113,     5,   450,   399,  3018,  2834,
     274,   353,   624,   122,   123,   140,   125,   126,     5,   463,
      27,   130,  1178,   149,   344,    24,   248,    26,   568,   473,
       5,     5,   476,     5,   646,   647,   395,   589,   147,   148,
     154,   234,   486,   841,   517,     5,  2492,   190,    25,    64,
      27,   410,   578,   526,   527,   625,   165,   530,   502,   503,
       5,   534,   619,   595,   429,   509,     5,   540,  2675,   542,
       5,   190,   578,   517,   518,   519,   190,   619,   192,     5,
     344,  1680,   526,   527,  1683,   529,   530,     5,   532,   283,
     534,   349,   578,     5,  1016,   391,   540,  2213,   542,   430,
     544,   504,   546,   547,   440,   549,   550,   885,   552,   887,
       5,  1040,  1043,  1044,   513,   391,  1045,  1046,   245,   508,
    2523,  1822,  2396,   436,  2398,   389,    27,   349,     5,     5,
    1978,   258,     5,  1062,   426,   426,     5,   462,   391,  1273,
       5,  1286,  1019,  1989,     5,     9,    10,   500,    12,    13,
      14,    15,    16,    17,     5,    27,   963,   395,     5,   561,
       5,   426,     5,  2152,   962,   963,   964,   242,     5,  2932,
       5,  1019,   410,  1323,  1324,   289,   532,   426,   373,   391,
     430,  2831,  1332,   553,     5,   391,   384,   841,   546,   391,
     556,     9,    10,  1146,    12,    13,    14,    15,    16,    17,
    2294,   554,   426,     5,  1536,  1158,   542,   391,  2197,  2496,
     654,   426,   470,   190,   981,   595,   550,  2206,  2207,   470,
     550,   426,   430,   426,   544,  1375,   391,  2514,   542,   539,
    1159,   391,   470,  1164,  2799,  2800,  1223,  3000,   619,   683,
     546,   685,   982,   357,   514,   617,   619,   391,   470,   391,
     619,   365,   568,    10,   391,   369,   700,   577,   367,   366,
     619,   568,   391,   678,   666,  1142,   553,   611,   666,   666,
    1541,   715,  2277,   389,   391,   661,   395,   666,   576,   391,
     724,   725,   726,  1147,   393,  3048,  2475,  3050,   486,  2002,
    2479,   410,   406,  2101,  1142,  1226,   740,  2445,   617,  1448,
    2076,   589,   746,   747,   568,   391,   625,   751,   962,   963,
     964,   784,  2406,  2099,  2408,   668,   626,   553,  1746,   550,
    1251,  1484,   611,  1252,  1487,  1256,   585,   353,   611,  1583,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     784,  2718,   349,   589,   245,   625,   453,   791,   475,    27,
     391,  2797,    35,   389,   391,   464,   391,   258,   619,   473,
     458,   391,   469,   454,   491,  1294,  1295,    18,    19,  1797,
     391,    23,   387,   391,  3071,    26,    27,   619,   525,  2227,
      27,   619,    27,   583,   648,   649,   650,   391,   252,    20,
    1657,   391,  2838,   837,   838,   659,    27,   412,   512,   525,
    2803,  2675,    27,   876,   391,   512,  2525,  1246,    23,    92,
      93,    94,    95,    96,    97,   888,   391,   391,   395,   391,
     893,   619,   283,   537,  2672,   108,   109,   110,  2027,   619,
     618,   391,   876,   994,   252,   324,   997,   625,  2815,   470,
    2817,  2818,  2819,  2820,   888,   552,   391,   478,   557,   893,
     541,  2602,   391,   157,   898,   359,   391,    20,  1411,   638,
     639,   640,   641,   642,    27,   391,   601,   581,   359,   341,
    2171,   174,   916,   391,   581,  2569,   590,   349,   350,   391,
     495,    14,   167,   590,   443,   331,   282,   931,  2887,     5,
    2889,   589,   249,   584,    26,    27,   391,  1647,  1987,   295,
     619,   945,   374,     5,   463,   377,  2793,   371,   521,    18,
      19,    20,    21,    22,   391,   391,  2505,   476,   391,  1270,
    1015,   619,   391,   395,  2618,  2584,   391,   391,   637,   430,
      18,    19,    20,    21,    22,    25,   645,    27,  1162,   190,
     391,  2040,   492,   190,   391,   190,   391,  2046,   391,   458,
      20,   501,  2774,   371,   391,   999,   391,    27,   112,  1003,
    1004,  1005,   430,   157,   428,   190,   249,   245,   271,   252,
     391,   475,  1016,   588,   475,  1019,  2798,  1021,  1022,   531,
     258,  1025,   234,   535,   475,   600,   601,   539,  2810,   391,
     491,   480,   296,   608,   535,   545,  1040,  1041,   548,  1043,
    1044,  1045,  1046,   324,  1048,   238,  1535,  1051,    20,    20,
     428,  2946,    25,  1566,    27,    27,    27,  2952,  1062,   234,
    1064,   425,   658,   248,  1068,    28,    29,  2875,   500,   386,
     430,   388,  1076,   429,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  2051,  1927,  2775,   430,   190,  2778,
    2811,  2812,   295,  2418,  1108,  1109,  2421,   513,   372,  1113,
     480,  1115,    20,  2101,  1425,  1148,  1149,  1150,   524,    27,
    1633,   585,   554,  1614,  1615,  3084,  1130,   638,   371,   561,
     641,   642,   556,   624,   585,  1168,    26,    27,  1142,  1628,
     190,  2098,   296,   386,  1148,  1149,  1150,   390,    26,    27,
     362,   458,  2806,  2836,   347,  1159,   647,  1161,   351,  1163,
    1164,   856,    20,  2571,  1168,  1321,  1993,  2949,   863,    27,
    1528,  1327,    25,  1484,    27,   624,  1487,   384,   556,   384,
      18,    19,    20,    21,    22,   428,   430,   362,  2015,    20,
     430,  1224,   430,   438,   643,   644,    27,  2816,   622,   480,
      25,   198,    27,  2822,   449,   202,  2825,  2826,  2827,  2828,
      26,   475,  1245,   456,   663,  1909,  1554,   190,   372,   430,
    1224,    25,  1226,    27,  1737,   470,    25,   491,    27,  1262,
     430,   474,   477,   282,  2283,  2284,   429,   475,    25,  1272,
      27,  1245,  1363,  2897,   622,  1249,   295,  1251,  1252,   624,
     430,  1372,  1256,   491,   624,   458,  1260,  1261,  1262,    25,
      25,    27,    27,    24,   546,    26,  1976,   549,  1272,   430,
     552,   646,   647,   643,   644,    25,   430,    27,  1636,    20,
      21,    22,  1286,   430,   430,  1798,    25,  1800,    27,  1293,
    1294,  1295,   238,   663,    35,    25,  1809,    27,  2112,  1657,
     190,    25,   355,    27,   430,    25,   163,    27,  2018,   166,
     457,   458,   190,   556,  1528,    30,  1320,    26,   335,  1323,
    1324,   475,   457,   458,  1328,  3008,  1330,   430,  1332,   346,
     430,    46,    47,   625,   191,   163,  2955,   491,   166,  2958,
    2959,  2960,  2961,   624,    18,    19,    20,    21,    22,   295,
     625,    92,    93,    94,    95,    96,    97,   426,    61,    25,
    2191,    27,   643,   644,  1855,   190,  2222,   108,   109,   110,
      26,  1375,   163,   520,  2188,   166,   460,    26,   426,   622,
     429,   398,   663,    26,  1388,    18,    19,    20,    21,    22,
     474,   190,    26,  1368,   478,  1399,   413,    25,  1402,    27,
     191,   347,    35,   190,    26,   351,   490,   122,   123,   619,
     125,   126,    25,   270,    27,   130,   273,  1421,  1422,  1423,
     458,    24,  1636,    26,   190,   190,  2925,  2926,    26,  1143,
     133,  1145,   147,   148,  3088,   366,  1747,    26,   295,   295,
     190,  2273,   270,  1657,  3063,   273,    26,  2435,   366,    26,
     165,   448,   449,  1457,  1458,  1459,    26,  1461,  1491,    92,
      93,    94,    95,    96,    97,    26,   190,   295,    46,    47,
    2427,   639,   640,  1506,   619,   108,   109,   110,   391,   270,
     533,   366,   273,   429,  1488,   502,    58,  1491,  1492,   430,
    3039,   347,    25,    26,   547,   351,   199,  1530,   201,   361,
      19,  1534,  1506,   619,   295,    24,    25,    26,   249,    18,
      19,   252,  1920,   216,    26,    24,    25,    26,    27,   572,
    1524,   224,   453,  3020,  2229,   228,  1530,  1838,  1532,  1533,
    1534,  1535,   857,   858,   430,   453,   861,   862,   469,  3038,
    3037,  3040,  1575,  1738,   122,   123,   543,   125,   126,  1553,
     253,   469,   130,   391,    19,    64,   553,   457,   458,    24,
    1564,    26,   190,   430,  1568,  1763,   426,   620,   453,   147,
     148,  1575,   429,   429,     5,   430,  1887,   190,   391,  1583,
    2090,   512,  2092,  2093,   469,  1589,  1590,   165,  1592,   458,
     366,   619,  2105,    26,   512,  2300,  2301,  2302,  2303,   258,
    3097,   429,   457,   458,   366,   612,   613,   614,   615,   426,
    1614,  1615,   108,   109,   110,   361,   249,  3114,   391,   252,
      20,   552,   287,   288,  1628,   641,   642,   512,    26,  1987,
     371,   366,  2580,  2581,   552,  1993,   648,   649,   429,   648,
     649,   356,  2155,  1647,    26,   386,   133,    26,    26,   390,
     581,    26,    20,   425,    26,  2631,   430,  2015,   236,   590,
      26,    26,  1666,   581,   619,   520,   438,   552,   391,  1764,
       5,    26,   590,  1768,   391,  1679,  1680,   453,  1773,  1683,
     391,   190,  1777,   302,  1779,  1780,  1781,   428,   366,   391,
     405,   453,   391,   469,   466,  1699,   581,  1701,  1702,   391,
     391,  1705,  1706,   623,     5,   590,  1739,   469,   391,   302,
     482,   483,   199,   623,   201,   456,   488,   430,   453,   491,
     391,   718,   391,   391,   391,   619,   458,   616,  1732,   216,
    2440,  1735,   619,   474,   469,  1739,   512,   224,   371,   426,
       8,   228,  1746,    30,    34,   478,    36,    37,    38,  1753,
     512,   466,   239,   386,   430,   525,   420,   390,   430,    46,
      47,   266,   459,     5,   459,   617,   253,   764,  1801,  1802,
    1803,  1804,  2263,  1987,  2265,   453,   552,   512,   430,  1993,
     430,  1785,   430,   430,  1788,  2501,   430,   617,   430,   430,
     552,   469,  1825,  1797,   430,   428,   326,  1801,  1802,  1803,
    1804,  2015,  1806,   430,   430,   581,   430,   430,  1812,  1813,
     430,   595,  1816,  1817,   590,   556,   430,   552,   430,   581,
     430,  1825,   430,   456,   430,   430,   430,     8,   590,   430,
     430,  1835,   420,   430,   512,   122,   123,   658,   125,   126,
     658,   474,   596,   130,     5,     5,   581,   383,  1881,   430,
     344,  1855,   589,   578,   430,   590,   430,    63,     8,   437,
     147,   148,   430,   430,   133,     6,     7,     8,     9,    10,
      11,    12,    14,     5,   552,  2580,  2581,  1881,   165,  2584,
     658,   622,   575,     5,  1888,  1889,   395,   658,   420,   430,
     430,    26,    26,  1897,    65,    91,   458,    26,   458,     5,
     619,   410,  2596,   581,  1908,  2737,   595,   589,   430,   430,
     430,   470,   590,  2745,   430,   625,  1920,    20,   427,  2432,
      20,   430,   430,   556,  1928,  2283,  2284,  2759,     5,   625,
     199,   430,   201,   430,   443,  2334,  2335,  2336,   935,  2338,
    2339,  2340,  2341,  2342,  2343,   625,   350,   216,  2347,  2462,
       5,   624,    18,   661,   556,   224,    19,    26,    26,   228,
     152,   470,   218,    25,   589,  2670,   481,   622,  2673,   578,
     481,     5,  1976,  2006,   483,  2008,  2040,   546,   150,   619,
     270,   546,  2046,   273,   253,   275,   495,  1991,    26,   622,
    1994,   399,   321,   546,  2483,    26,   430,  2001,  2002,  2003,
    2710,  2490,  2006,   430,  2008,   295,   430,   430,  2835,   430,
     663,   391,  2016,   576,  2018,   305,   458,   546,   391,    26,
     619,   391,   159,  2027,   391,   430,  2221,   391,   537,   391,
     391,   391,   391,   616,   324,   625,     5,     5,   175,   176,
       5,   579,     5,   482,   619,   391,  2050,   184,  2040,  2053,
       5,  2055,   625,   430,  2046,     8,   430,   347,   624,    26,
      26,   351,   535,  2067,    65,   325,     5,   576,     5,  2283,
    2284,   391,  2076,   430,  2054,   360,  2056,   430,   596,   588,
     625,   218,    14,  2915,   420,     5,   420,   550,   659,   546,
     227,   600,   601,   299,     5,  2099,    26,  2101,   100,   608,
     430,   625,   611,   430,     5,  2109,   619,   624,  2112,  2814,
     619,  2816,  2116,   638,   426,   426,   460,  2822,  2823,   256,
    2825,  2826,  2827,  2828,   430,   430,   430,   460,  2161,  2834,
     430,  2164,   430,   430,   430,    62,     8,     5,    26,   429,
      26,   589,   391,   391,    25,    25,    25,  2151,  2152,    25,
     391,   357,   391,     5,     5,   619,   553,  2161,   972,   619,
    2164,   619,     8,   369,   301,  2169,   325,    20,    21,    25,
     344,   344,    34,   379,    36,    37,    38,  2887,  2182,  2889,
    2184,  1178,  2186,   458,  2188,   430,   344,   619,   425,  2222,
    2194,   397,   360,  2197,   458,   430,   430,   430,  2202,    20,
      21,   407,  2206,  2207,   410,   430,   343,  2923,   135,   136,
     430,   430,   430,     5,   650,    26,     5,   423,  2222,     5,
    3052,    25,   616,  1592,    14,  2229,  2739,  2231,    26,    14,
     430,   619,   595,  2237,  2238,  2239,  2240,  2241,  2242,    92,
      93,    94,    95,    96,    97,  2736,   595,     5,   619,  1246,
    2955,     5,     5,  2958,  2959,  2960,  2961,     7,   391,  2263,
     430,  2265,     5,   190,    26,   471,    26,   619,   619,   196,
      26,    92,    93,    94,    95,    96,    97,  2281,   625,     8,
     391,   391,   625,   625,    26,    20,   589,   391,     5,  2994,
    2294,   274,   391,  2477,   391,   501,  2300,  2301,  2302,  2303,
    2304,  2305,   391,  2630,  1301,   511,   391,   566,   391,     5,
       5,  2315,  2316,  2317,   546,     5,     5,   667,   391,  2323,
    2300,  2301,  2302,  2303,   571,   619,   532,   391,   619,   535,
     625,   537,   391,  3023,  3024,  3025,  3026,  3027,  3028,   266,
     430,   268,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   470,     6,   625,     5,   623,  3063,   565,
     553,   210,   625,    25,    25,    35,  3071,    25,   574,   623,
     446,    25,   618,    26,  3084,    25,   470,   430,    26,    26,
    2384,    26,  2386,    26,  1753,   430,    26,   118,   296,    26,
       5,   391,  2396,  2906,  2398,   391,   467,  2401,   268,   525,
     589,     5,  2406,  2407,  2408,   430,   391,   550,   270,   240,
      26,   273,    25,   275,   426,   342,   391,  2397,  2096,  2399,
     391,     5,    92,    93,    94,    95,    96,    97,   344,   440,
      20,  2435,   139,   295,   553,  2439,  2440,   430,   108,   109,
     110,   430,   430,   305,   430,     5,   430,  3163,   430,  2453,
     430,     5,    14,  2486,   619,   210,     5,   391,    26,   458,
     441,    26,   324,   391,     5,   391,   391,   618,   368,   430,
     397,  2475,   331,   391,  2478,  2479,   373,  2835,    26,  2483,
     568,   391,  2486,  2516,   391,   347,  2490,   391,   240,   351,
     221,   440,   430,   391,   344,   241,   458,   625,   229,   391,
     391,  2505,   391,   546,   235,   619,   237,   434,   391,   391,
      14,   430,  2516,   391,   239,   239,     7,   248,    34,  2523,
      36,    37,    38,    26,   625,   391,   447,  2531,  1897,    26,
    2534,  2535,  2536,  2537,  2538,   392,   430,   619,   625,   625,
    1354,  1355,   469,   391,   391,   276,   575,  1361,   475,   391,
     477,   426,     5,   430,   481,     5,   391,   484,  2562,    25,
     487,   292,   241,   391,   391,  2569,   297,   429,   391,   391,
     497,   391,     5,   391,  2578,   391,  2580,  2581,   309,   249,
    2584,  2201,   252,  2109,  3107,   316,  2151,  1871,  1263,   516,
    1576,  2595,    38,    40,   366,  1592,   523,   524,   525,  1813,
    2580,  2581,   529,  2182,  2584,    18,    19,    20,    21,   289,
     537,  1819,   143,   147,  2618,   211,  2620,    18,    19,    20,
      21,  2835,  2300,  2301,  2302,  2303,   553,   283,   399,  1367,
     290,   213,  1368,   355,  2003,  1771,   373,     5,     6,     7,
       8,  2448,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,     5,  3097,   385,  1491,   318,
     317,   387,   529,  1788,  1677,  1684,  2670,    35,  1534,  2673,
    1438,  2675,  1803,  2548,  2678,  1293,   969,  2254,  1606,    92,
      93,    94,    95,    96,    97,  1296,  2055,  1924,  3150,  1807,
    1623,    92,    93,    94,    95,    96,    97,  1164,    25,  2753,
     120,   371,  1699,    31,  2652,    31,  2710,  1581,  2741,  1706,
    2714,   487,  2716,   656,  1587,   268,   386,  1301,  1922,  1590,
     390,   685,   936,  2852,    92,    93,    94,    95,    96,    97,
    1155,  1221,  2736,  1639,  2929,  2649,  3114,  2741,  2238,   470,
     108,   109,   110,  1145,  1558,  2374,   477,  2862,   888,  1072,
    1245,  2372,  2356,  2049,   270,  2788,  1753,   273,   428,   275,
    1025,  1797,  1987,  3125,  3088,  1382,  1405,  2019,   499,  2976,
    2050,  2405,  2710,   504,  2384,  1705,  2780,  2441,  2386,   295,
    2053,  2673,  2994,  1320,  2788,  2684,   456,    17,  1602,   305,
    2067,   718,  2317,  2898,  2579,  2899,   965,  2295,  2439,  2803,
    3086,  1315,  2806,  2237,   474,  2943,   961,  2578,  2814,  1288,
    2814,  2833,  2816,  2822,  1735,  1160,    -1,   364,  2822,  2823,
      -1,  2825,  2826,  2827,  2828,    -1,    -1,  2831,    -1,  2833,
    2834,   347,  2836,    -1,    -1,   351,  2816,    25,    -1,    27,
    2844,    -1,  2822,  2823,    -1,  2825,  2826,  2827,  2828,    -1,
      -1,    -1,    -1,    -1,  2834,    -1,    -1,    -1,    46,    47,
      -1,   788,  2231,    -1,    -1,    -1,    -1,    -1,  2237,  2238,
    2239,  2240,  2241,  2242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   249,    -1,  2887,   252,  2889,   556,    -1,  2892,    -1,
      -1,  1888,  1889,  2897,    -1,  2899,    -1,    -1,    -1,    -1,
    1897,    -1,  2580,  2581,   831,    -1,  2584,    -1,    -1,    -1,
     260,    -1,  2281,   429,    -1,    -1,    -1,    -1,    -1,    -1,
     847,   848,   849,    -1,   851,    -1,   853,   854,    -1,    -1,
      -1,    -1,   859,   860,   122,   123,    -1,   125,   126,  2943,
      -1,    -1,   130,    -1,    -1,    -1,    30,  2951,    -1,   299,
      -1,  2955,   622,    -1,  2958,  2959,  2960,  2961,  2962,   147,
     148,    -1,    46,    47,    -1,    -1,    -1,    -1,   318,    -1,
      -1,    -1,  2976,   900,    -1,  2955,    -1,   165,  2958,  2959,
    2960,  2961,    -1,    -1,   911,    -1,    -1,    -1,    -1,    -1,
    2994,    75,  2670,    -1,  2998,  2673,    -1,  1994,    -1,    -1,
      -1,  3034,   190,   371,  3008,    -1,  2003,   357,   935,   936,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   944,   386,   369,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,   379,
    3034,  3035,  2401,   960,   961,  3039,    -1,    -1,   122,   123,
      -1,   125,   126,    -1,    -1,    -1,   130,   397,   236,    -1,
      -1,  1865,  1866,    -1,    -1,    -1,  2053,   407,  2055,  3063,
     428,    -1,  1876,   147,   148,    -1,    -1,  3071,    -1,    -1,
    2439,    -1,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,
    3084,   165,  3086,  3063,  3088,    -1,    -1,    -1,   456,    -1,
      -1,  3071,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2096,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,  3145,   463,    -1,  1929,  1930,  1931,  1932,    -1,
      -1,  3125,    -1,  1937,  1938,  1939,  1940,    -1,    -1,    -1,
    1944,    -1,    -1,    -1,    -1,    -1,   486,    -1,  2816,    -1,
      -1,  3145,    -1,    -1,  2822,  2823,    -1,  2825,  2826,  2827,
    2828,   501,   236,    -1,  2523,    -1,  2834,    -1,   508,    -1,
      -1,   511,  2531,    -1,    -1,  2534,  2535,  2536,  2537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   532,    -1,    -1,   535,    -1,   537,   556,  2867,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1131,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2028,  2029,  1143,    -1,  1145,  1146,
    1147,  2035,  2036,    -1,   574,    -1,    -1,  1154,  1155,    -1,
      -1,  1158,    -1,    -1,  2231,  1162,    -1,    -1,  1165,    -1,
    2237,  2238,  2239,  2240,  2241,  2242,   724,   725,   726,   437,
      -1,  1178,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   740,    -1,    -1,    -1,    -1,    -1,   746,   747,
      -1,    -1,   356,   751,    -1,    -1,    -1,  2955,    -1,    -1,
    2958,  2959,  2960,  2961,  2281,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1223,    -1,    -1,    -1,
      -1,    -1,    -1,  2300,  2301,  2302,  2303,    -1,    -1,  2678,
      -1,    -1,    -1,    -1,    -1,    -1,  2994,    -1,    -1,    -1,
      -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1258,    -1,    -1,    -1,    -1,    -1,  2334,  2335,  2336,
      -1,  2338,  2339,  2340,  2341,  2342,  2343,    -1,    -1,    -1,
    2347,    22,    -1,   437,    -1,  1282,    -1,    -1,  2172,  2173,
    1287,    -1,    -1,    -1,    35,    -1,    -1,  2181,    -1,    -1,
      -1,    -1,    -1,  1300,  1301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,    -1,    -1,  3063,    -1,  2384,    -1,  2386,
      -1,    -1,    -1,  3071,    -1,    -1,  2210,  2211,    -1,  2396,
      -1,  2398,    -1,    -1,  2401,    -1,    -1,    -1,    -1,    -1,
      -1,  2780,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,  1356,
      -1,    -1,    -1,    -1,  2803,    -1,    -1,   108,   109,   110,
      -1,    -1,  2439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2264,    -1,  2266,    -1,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1411,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2501,    -1,    -1,    -1,    -1,    -1,
    2324,  2325,    -1,    -1,  2328,  2329,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2892,    -1,    -1,  2523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2531,    -1,    -1,  2534,  2535,  2536,
    2537,    -1,    92,    93,    94,    95,    96,    97,  2362,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,  1041,    -1,    -1,    -1,    -1,    -1,    -1,
    1048,    -1,    -1,  1051,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,  2951,  2580,  2581,    -1,  1064,  2584,    -1,    25,
    1068,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1076,    -1,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1547,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1555,  2998,
    1108,  1109,    -1,    -1,    -1,  1113,    -1,  1115,    -1,  1566,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
    1587,    -1,  2476,    -1,    -1,    -1,  2480,    -1,    -1,    -1,
      -1,    -1,    35,  2670,    -1,    -1,  2673,    -1,  2675,  2493,
      -1,  2678,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2512,   249,
     371,    35,   252,    -1,   128,    -1,  1633,  1634,  1635,    -1,
      -1,    -1,  1639,   137,    -1,   386,    -1,  3086,    -1,   390,
      -1,    -1,   146,    -1,    -1,    -1,    -1,   151,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,   177,    -1,    -1,  1671,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3125,   428,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,    -1,   108,   109,   110,    -1,    -1,   203,
      -1,    -1,    -1,  2780,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,  2803,    -1,    -1,    -1,
    1737,  1738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2816,
      -1,   371,    -1,    -1,    -1,  2822,  2823,    -1,  2825,  2826,
    2827,  2828,    -1,    -1,    -1,   259,   386,  2834,    -1,  2836,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     284,    -1,    -1,    -1,    -1,    -1,    -1,   291,   304,   293,
    2867,  1798,    -1,  1800,   310,   311,   312,    -1,   428,   303,
      -1,    -1,  1809,    -1,    -1,   556,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,   330,  2892,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   329,   456,    -1,    -1,    -1,
      -1,    -1,    -1,   337,    -1,   249,    -1,    -1,   252,  1846,
      -1,    -1,    -1,    -1,   474,    -1,  2923,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,  1875,    -1,
     374,   622,    -1,    -1,  2951,    -1,    -1,  2771,  2955,    -1,
      35,  2958,  2959,  2960,  2961,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2789,   400,    -1,    -1,  1457,
    1458,  1459,    -1,  1461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1921,  1922,    -1,  2994,    -1,    -1,
      -1,  2998,   438,    -1,    -1,   441,   556,    -1,   371,    -1,
    1488,  3008,    -1,   449,   438,    -1,    -1,    92,    93,    94,
      95,    96,    97,   386,    -1,   449,    -1,   390,   391,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,   371,    -1,    -1,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,    -1,
      -1,    34,   386,    36,    37,    38,   390,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,  3063,    -1,    -1,    -1,
      -1,    -1,   622,    -1,  3071,  1553,    -1,    -1,    -1,    62,
      -1,    -1,    -1,   519,    -1,    -1,    -1,    -1,    -1,  3086,
    1568,    -1,    -1,   456,   428,    -1,    -1,    -1,    -1,  2026,
      -1,    -1,    -1,   539,   540,    -1,    -1,    -1,    91,    -1,
      -1,   474,    -1,  2927,   550,    -1,    -1,    -1,    -1,   555,
      -1,    -1,   456,    -1,   548,   549,   550,    -1,  3125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   561,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3163,  2981,  2982,    -1,
    2984,    -1,  2986,  2987,   249,    -1,    -1,   252,  2105,    -1,
     163,    -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,
     626,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,   210,  2155,    -1,
      -1,    -1,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,
     664,   224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,
      -1,   234,    -1,    -1,    -1,   238,   239,   240,   241,   622,
      -1,  3075,    -1,  3077,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,  2199,    -1,  2201,    -1,  2203,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   270,   622,  2216,
     273,    -1,   275,    -1,  2221,    -1,   371,    -1,    -1,   282,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1785,    -1,  3123,
    1788,   386,   295,    -1,    -1,   390,   391,    -1,    -1,    -1,
      -1,    -1,   305,    -1,    -1,  3139,  3140,    -1,    -1,  3143,
      -1,    -1,  3146,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,   325,    -1,    -1,    -1,    -1,    -1,  2275,  2276,
      -1,    -1,    -1,   428,    -1,    -1,   339,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,   362,
      -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2318,    -1,    -1,    -1,    -1,     6,     7,     8,   474,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,  2358,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2371,    -1,   429,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   440,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    35,
      -1,   556,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,   480,   108,   109,
     110,    -1,    -1,    -1,    -1,  2432,    -1,   108,   109,   110,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,  2462,    92,    93,    94,    95,
      96,    97,    35,    -1,    -1,    -1,    -1,   622,    -1,    -1,
    2477,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,  2492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2501,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,   624,   252,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,   638,   639,   640,   641,   642,
     643,   644,    -1,   646,   647,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2151,  2152,    -1,    -1,    -1,    -1,    -1,
     663,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2194,    -1,    -1,  2197,
      -1,    -1,  2649,    -1,    -1,    -1,    -1,    -1,  2206,  2207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,   304,    -1,   252,
      -1,   371,    -1,   310,   311,   312,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
     390,   391,    -1,   330,    -1,   386,    -1,    -1,    -1,   390,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,  2739,    -1,    -1,   371,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,
     386,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,    -1,    -1,    -1,   456,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
    2797,    -1,   428,   474,    -1,    -1,    -1,    -1,   371,    -1,
      -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   438,    -1,   386,   441,    -1,    -1,   390,   391,    -1,
     456,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2838,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,  2852,    -1,    -1,    -1,    -1,
    2857,    -1,  2859,    -1,    -1,   428,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,   371,    -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2898,   519,    -1,   190,  2453,   386,    -1,    -1,  2906,
     390,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   539,   540,    -1,    -1,  2923,    -1,    -1,    -1,
     556,    -1,  2929,   550,    -1,    -1,    -1,    -1,   555,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    30,   428,    -1,
       9,   622,    -1,    -1,    -1,    -1,    -1,  2505,    -1,    18,
      19,    20,    45,    46,    47,    24,    25,    26,    27,    -1,
      -1,    54,    -1,    -1,    -1,    -1,   456,   594,    -1,    -1,
      -1,    -1,    -1,    66,    67,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    -1,   556,   474,    -1,   622,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    64,    -1,    90,   294,   626,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,  3023,  3024,  3025,  3026,
    3027,  3028,    -1,    -1,   117,    -1,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,   130,   131,   132,
      -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,   141,   622,
     143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,    -1,
     153,    -1,   155,   156,    -1,   158,   556,   160,   161,    -1,
      -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,   172,
     173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,    -1,
      -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,   395,
     193,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,   202,
      -1,   204,    -1,   206,   410,   208,   209,    -1,   211,   212,
     213,   190,    -1,    -1,   217,    -1,   219,   220,    -1,   222,
      -1,   427,   622,    -1,   430,    -1,    -1,   230,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,   443,    -1,    -1,
     243,    -1,    -1,   246,   247,    -1,  3163,   250,   251,    -1,
      -1,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     263,   264,   265,    -1,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   277,   278,   279,   483,   281,    -1,
      -1,    -1,   285,   286,    -1,    -1,    -1,   290,    -1,   495,
      -1,    -1,    -1,    -1,    -1,   298,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   306,   307,   308,    -1,    -1,    -1,    -1,
      -1,   314,   315,    -1,    -1,   294,    -1,   320,    -1,    -1,
     323,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,    -1,
      -1,   537,    -1,    -1,    -1,   338,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,   356,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   364,    -1,    -1,    -1,    35,    -1,   370,    -1,    -1,
     576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     393,    -1,    -1,    -1,   600,   601,    -1,   400,    -1,   402,
     403,    -1,   608,    -1,    -1,   611,    -1,    -1,   411,    -1,
      -1,    -1,    -1,   619,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   450,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,
      -1,    -1,    -1,   442,   443,   468,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,
     493,   470,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,    -1,   509,    -1,    -1,    -1,
      -1,    -1,   515,   516,   517,   518,   495,    -1,    -1,   522,
      -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,    -1,
     533,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   545,    -1,   547,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,    -1,   560,   537,    -1,
     563,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,    -1,
      -1,  3039,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   595,    -1,    -1,   598,    -1,   576,    -1,    -1,
     603,    -1,    -1,   606,   607,    -1,    -1,    -1,    -1,   588,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,   600,   601,    -1,    -1,   628,    -1,    -1,    -1,   608,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,   652,
     653,   654,   655,   656,   657,    -1,    -1,   660,    -1,   662,
      -1,   664,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
     390,   391,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    35,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   456,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,   108,   109,   110,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,    -1,   390,   391,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,   252,    -1,   108,
     109,   110,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,
     391,    -1,   456,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,   386,    -1,
      -1,    -1,   390,   391,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,   474,    -1,    -1,   371,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,   556,    -1,    -1,   390,    -1,    -1,   456,    -1,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,   474,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
     386,    -1,    -1,   428,   390,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,   622,    -1,
      -1,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,   474,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,   556,    -1,
     456,    -1,    -1,    39,    40,    41,    42,    43,    44,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,   622,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,   556,    98,    -1,   622,    -1,    92,    93,    94,    95,
      96,    97,    35,    -1,    -1,    -1,    -1,   249,    -1,   428,
     252,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     556,    -1,    -1,    -1,    -1,    -1,    -1,   456,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,   474,    -1,   622,    -1,    92,
      93,    94,    95,    96,    97,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    92,    93,    94,    95,    96,    97,    -1,   371,
      -1,    -1,    -1,    -1,    35,    -1,    -1,   556,   108,   109,
     110,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,   441,
      -1,    -1,    -1,   622,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,   456,    -1,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,   332,    -1,    -1,    -1,
      -1,    -1,   474,    -1,    -1,    -1,     9,    -1,    -1,   345,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,   249,
      -1,    -1,   252,    -1,    -1,    -1,    59,    -1,    -1,    -1,
     386,    64,    -1,    -1,   390,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,   556,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,   371,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   455,
      -1,   252,     9,   386,    -1,    -1,    -1,   390,    -1,    -1,
     456,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,   479,    -1,    -1,    -1,    -1,   474,    -1,
     622,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,   495,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,   505,
      -1,   371,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,   386,   190,    -1,   192,
     390,   527,    -1,   456,   530,   531,    -1,    -1,    -1,    -1,
     536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,   474,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,   428,   390,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,   456,   593,    -1,   390,
      -1,    -1,     9,    -1,    -1,    -1,    -1,   428,   604,    -1,
      -1,    18,    19,    -1,   474,    -1,    -1,    24,    25,    26,
      27,    18,    19,    20,    -1,    -1,   289,    24,    25,    26,
      27,   294,    -1,   556,    -1,   456,   622,   428,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,    -1,    -1,    -1,    -1,
     441,    -1,    59,   474,    -1,    -1,    -1,    64,    -1,   322,
      -1,     9,    -1,    -1,    71,   456,    -1,    64,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,   357,    -1,   556,    -1,    -1,   622,
      -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,   387,    -1,    -1,    -1,    -1,   392,
      -1,    -1,   395,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,    -1,   289,   406,    -1,    -1,    -1,   294,    -1,   412,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,
      -1,    -1,   622,    -1,   427,   556,    -1,   430,    -1,    -1,
     433,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,   442,
     443,    -1,    -1,   190,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   482,
     483,    -1,   369,    -1,   487,    -1,    -1,    -1,    -1,    -1,
      -1,   622,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,   190,   506,   192,   392,    -1,    -1,   395,   512,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,   406,
      -1,    24,    25,    26,    27,   412,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   537,   422,    -1,    -1,    -1,    -1,
     427,    -1,   289,   430,    -1,    -1,   433,   294,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,   443,   294,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,   322,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,   590,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,   600,   601,    -1,
     487,   289,    -1,    -1,    -1,   608,   294,    -1,   495,    -1,
     357,    64,    -1,    -1,    -1,    -1,   619,    -1,    -1,   506,
      -1,   508,   369,    -1,    -1,   512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,    -1,
     387,    -1,    -1,    -1,    -1,   392,    -1,    -1,   395,    -1,
     537,    -1,    -1,    -1,    18,    19,    20,    -1,   395,   406,
      24,    25,    26,    27,    -1,   412,    -1,    -1,    -1,   357,
      -1,    -1,    -1,   410,    -1,   422,    -1,    -1,    -1,    -1,
     427,   369,    -1,   430,    -1,    -1,   433,   190,    -1,    -1,
     427,    -1,    -1,   430,   581,   442,   443,    -1,    -1,   387,
      64,   588,    -1,   590,   392,   442,   443,   395,    -1,    -1,
      -1,    -1,    -1,   600,   601,    -1,    -1,    -1,   406,    -1,
      -1,   608,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   619,    -1,   422,   482,   483,   190,    -1,   427,
     487,    -1,   430,    -1,    -1,   433,   483,    -1,   495,    -1,
      -1,    -1,    -1,    -1,   442,   443,    -1,    -1,   495,   506,
      -1,    -1,    18,    19,    20,   512,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    18,    19,   260,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,   483,    -1,    -1,    -1,   487,
     537,    -1,    -1,    -1,    -1,    -1,    -1,   495,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,   506,    -1,
      -1,    -1,    64,    -1,   512,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,   318,    -1,    -1,   576,
      -1,   588,    -1,   590,    -1,    -1,    -1,    -1,    -1,   537,
      -1,   588,    -1,   600,   601,    -1,    -1,    -1,    -1,    -1,
      -1,   608,    -1,   600,   601,    -1,    -1,    -1,    -1,    -1,
      -1,   608,   619,    -1,   611,   357,    -1,    18,    19,    -1,
      -1,    -1,   619,    24,    25,    26,    27,   369,    -1,    -1,
      -1,    -1,   395,   581,    -1,    -1,    -1,   379,    -1,    -1,
     588,    -1,   590,    -1,    -1,    -1,    -1,   410,    -1,    -1,
      -1,    -1,   600,   601,    -1,   397,    -1,    -1,    -1,    -1,
     608,    -1,    -1,    64,   427,   407,    -1,   430,    -1,    -1,
      -1,   619,    -1,    -1,   190,    -1,    -1,    -1,    -1,    -1,
     443,   423,   395,    -1,    -1,    -1,    -1,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   427,    -1,    32,   430,    -1,   482,
     483,   463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     443,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    -1,   486,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,   501,
      -1,    -1,    -1,    79,    80,    -1,   508,    -1,    -1,   511,
     483,   395,    -1,    89,   537,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   495,    -1,    -1,    -1,   410,    -1,    -1,   190,
     532,    -1,    -1,   535,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,   576,   556,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,    -1,   537,   588,    -1,    -1,    -1,    -1,
      -1,    -1,   574,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,   611,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,   482,   483,
      -1,    -1,    -1,   576,    -1,    -1,    -1,    -1,   190,    -1,
      -1,   495,    -1,   190,    -1,   588,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,    -1,
      -1,    -1,    -1,   395,   410,   608,    -1,    -1,   611,    -1,
      39,    40,    41,    42,    43,    44,   619,    -1,   410,    -1,
      -1,   427,    -1,   537,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   427,    -1,   443,   430,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,
      78,   443,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   588,    -1,    -1,   483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   600,   601,    -1,   495,
     482,   483,    -1,   299,   608,    -1,    -1,   611,    -1,    -1,
      -1,    -1,    -1,   495,   395,   619,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   334,    -1,
      -1,   537,    -1,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,   176,    -1,
      -1,   357,   443,    -1,    -1,    -1,   184,    -1,    -1,    -1,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,
     576,    -1,    -1,   379,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   588,   395,   576,    -1,    -1,    -1,   395,    -1,
     218,   397,   483,    -1,   600,   601,   588,    -1,   410,   227,
      -1,   407,   608,   410,   495,   611,    -1,    -1,   600,   601,
      -1,    -1,    -1,   619,    -1,   427,   608,   423,   430,   611,
     427,    -1,    -1,   430,    -1,    -1,    -1,   619,   256,   257,
     259,   443,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   284,    -1,   463,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,   483,    -1,   301,    -1,    -1,   483,    -1,    -1,    -1,
     486,    -1,    -1,   495,    -1,   576,    -1,    -1,   495,    -1,
      -1,    -1,    -1,    -1,    -1,   501,    -1,   588,    -1,    -1,
     329,    -1,   508,   332,    -1,   511,    -1,    -1,   337,   600,
     601,    -1,    -1,    -1,    -1,   343,   345,   608,    -1,    -1,
     611,    -1,    -1,    -1,    -1,   537,   532,    -1,   619,   535,
     537,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,   574,   576,
      -1,   399,    -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,
     409,   588,    -1,    -1,    -1,    -1,    -1,   416,   600,   601,
      -1,    -1,    -1,   600,   601,    -1,   608,    -1,    -1,   611,
      -1,   608,   431,    -1,   611,    -1,    -1,   619,    -1,    -1,
     616,    -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     489,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,    -1,
      -1,   530,   531,    -1,    -1,    -1,    -1,   536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,    -1,   604,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   236,   356,   405,   437,   466,   727,   755,
     756,   806,   974,  1027,  1029,  1030,  1031,  1036,  1038,  1051,
    1052,  1053,  1054,  1055,  1471,    28,    29,   728,   729,   730,
     731,   732,    27,   939,  1490,   355,   533,   547,   572,   620,
    1472,  1472,  1472,  1472,  1472,  1472,  1472,  1472,   939,    25,
     939,  1392,  1056,   757,  1392,   756,  1471,     0,  1028,  1031,
    1036,  1054,  1471,    31,   730,   732,   939,  1474,   589,   939,
    1473,   625,   807,    25,   190,   754,   755,   927,   939,   944,
    1057,  1092,  1093,  1094,  1095,  1096,  1100,   353,   759,   760,
     761,   762,   765,   766,    55,    60,   105,   106,   113,   367,
     393,   464,   557,   637,   645,   727,   733,   899,   973,  1032,
    1033,  1035,  1039,  1040,  1046,  1058,  1079,  1212,  1222,  1471,
     939,  1473,   616,  1095,   242,   457,   458,  1102,    20,   939,
    1099,   619,   760,     5,   758,   353,   939,     5,   782,   784,
     785,   939,  1223,   939,   939,  1213,  1047,   939,   939,  1035,
    1041,   260,   299,   318,   357,   369,   379,   397,   407,   423,
     463,   486,   501,   508,   511,   532,   535,   537,   556,   574,
     808,   809,   810,   813,    25,  1092,  1098,    18,    19,    26,
     430,   677,   679,  1092,  1103,  1104,   458,    14,   805,   762,
     521,  1199,   763,   760,   765,    32,    79,    80,    89,   260,
     299,   318,   334,   357,   369,   379,   397,   407,   423,   463,
     486,   501,   508,   511,   532,   535,   537,   556,   574,   616,
     768,   776,   787,   788,   939,   430,   112,   939,   754,   900,
    1080,   939,   815,   535,   767,   791,   793,   794,   792,   801,
     802,   430,   430,   814,   458,   430,   430,   760,   789,   425,
     677,    18,    19,    20,    21,    22,   678,    26,     5,   426,
    1103,    24,    25,    26,   619,   939,   945,    19,    25,    26,
     764,   945,   778,   767,   779,   791,   792,   430,   430,   777,
     458,   430,   430,   789,   760,   786,   430,    26,   939,   430,
    1048,   754,   754,   430,   939,   430,   457,   771,   625,   366,
     453,   469,   512,   552,   581,   590,   795,   625,   366,   453,
     469,   512,   552,   581,   590,   803,    26,    26,   816,   817,
     818,   819,   939,    26,   774,   775,    26,    26,   619,   391,
     677,  1104,   458,   426,    26,    26,   760,   771,   760,    26,
      26,   759,   774,    26,    26,   619,    58,   783,  1224,   391,
     430,  1214,  1491,  1492,  1493,  1494,  1495,   901,  1081,  1042,
     619,    26,   796,   797,   430,   798,   803,   804,   798,   430,
     799,     5,   391,     5,   391,     5,   283,     5,   808,   426,
       5,     5,   391,   391,   760,   790,  1103,   458,   619,    26,
     258,     5,   391,     5,   391,   283,   426,     5,   391,   391,
     790,   939,  1109,  1110,  1112,  1059,  1109,   361,  1492,  1199,
      45,    54,    66,    67,    69,    83,    90,   101,   102,   103,
     117,   119,   120,   121,   124,   127,   129,   131,   132,   138,
     141,   143,   144,   145,   153,   155,   156,   158,   160,   161,
     164,   168,   169,   170,   172,   173,   177,   178,   179,   181,
     185,   187,   188,   193,   197,   200,   202,   204,   206,   208,
     209,   211,   212,   213,   217,   219,   220,   222,   230,   231,
     243,   246,   247,   250,   251,   254,   255,   263,   264,   265,
     267,   277,   278,   279,   281,   285,   286,   290,   298,   306,
     307,   308,   314,   315,   320,   323,   327,   328,   338,   356,
     364,   370,   400,   402,   403,   411,   450,   461,   468,   492,
     493,   497,   509,   515,   516,   517,   518,   522,   526,   533,
     534,   545,   547,   558,   560,   563,   569,   595,   598,   603,
     606,   607,   621,   628,   651,   652,   653,   654,   655,   656,
     657,   660,   662,   664,   670,   671,   672,   673,   690,   712,
     726,   727,   733,   734,   753,   821,   822,   823,   824,   835,
     836,   837,   838,   890,   894,   925,   946,   947,   950,   951,
     952,   953,   966,   975,   996,   997,   999,  1003,  1018,  1019,
    1023,  1024,  1025,  1026,  1034,  1049,  1062,  1073,  1074,  1075,
    1086,  1089,  1125,  1128,  1130,  1136,  1137,  1140,  1143,  1146,
    1148,  1150,  1153,  1160,  1165,  1169,  1170,  1171,  1183,  1184,
    1187,  1193,  1194,  1195,  1220,  1235,  1236,  1237,  1238,  1239,
    1244,  1250,  1251,  1269,  1272,  1302,  1304,  1393,  1394,  1425,
    1426,  1433,  1444,  1471,  1475,  1480,  1482,  1484,  1488,  1489,
    1496,   727,  1037,  1471,   624,   647,  1082,  1083,  1109,    20,
     391,   425,   772,   795,    26,   800,    26,    26,    26,   817,
     819,   811,   775,    26,   426,  1103,    20,   772,   430,    26,
      26,   769,    26,   619,   391,     5,  1109,   391,   939,   349,
     940,   941,  1490,   939,   939,  1167,   934,   940,   934,    25,
     190,   939,  1101,  1466,  1467,  1468,   939,  1486,   939,  1246,
    1247,   939,    26,   674,  1092,  1242,   934,  1167,   864,    26,
     945,  1207,  1208,  1207,     9,    18,    19,    25,    26,    59,
      64,    71,    99,   192,   289,   294,   322,   357,   369,   387,
     392,   395,   406,   412,   422,   427,   430,   433,   442,   443,
     483,   487,   495,   506,   512,   537,   581,   588,   590,   600,
     601,   608,   839,   846,   847,   848,   849,   850,   851,   852,
     853,   865,   870,   881,   882,   883,   884,   939,   945,  1092,
    1202,  1271,  1384,   841,   864,   940,  1434,  1434,   825,  1167,
     934,  1240,  1092,   936,   940,   846,  1434,  1092,  1167,  1092,
    1270,  1434,    25,   585,  1076,  1077,  1092,   934,   934,  1076,
     935,   940,   939,  1077,   934,  1434,   934,   936,  1092,  1123,
    1124,   932,   940,   936,   374,   561,   666,   931,   939,   998,
     939,   735,   937,   940,    25,  1303,  1466,   864,   864,   940,
    1149,   895,   128,   137,   146,   151,   195,   203,   259,   284,
     291,   293,   303,   329,   337,   374,   400,   438,   449,   548,
     549,   550,   561,   664,  1012,  1144,  1145,  1092,   845,   846,
    1159,   931,  1481,  1481,   933,   940,   864,    25,  1092,  1147,
    1221,  1092,  1198,    25,  1092,  1428,   846,  1189,  1190,  1191,
    1200,  1201,   846,  1476,   104,   154,   192,   289,   365,   406,
     473,   537,   691,   870,   939,  1092,  1230,   714,   846,   932,
    1473,  1063,   846,   932,    26,  1092,  1020,   932,   846,  1445,
     846,  1207,   939,   948,   949,   936,   948,  1481,   936,   948,
    1481,   954,   948,    25,    26,   384,   486,   945,  1001,  1092,
    1111,  1113,    65,   274,   344,   389,   568,   648,   649,   650,
     659,   681,   956,   958,   960,   962,   964,  1087,  1088,  1091,
     335,   346,   398,   413,   502,  1305,   639,   640,   903,   904,
     905,   939,  1084,   646,  1083,   391,   302,   391,   391,   391,
     391,   623,     5,   391,   426,   302,   760,   780,   781,   391,
     391,   623,   391,   939,  1225,  1112,   391,  1215,    56,    57,
      84,    85,    86,   454,   541,   584,  1252,  1253,  1254,  1257,
    1260,  1263,  1264,  1265,  1266,   430,   619,  1468,  1102,   616,
    1141,   619,     8,   538,   587,     5,   391,   426,    25,   939,
    1377,   478,  1168,  1111,   108,   109,   110,   839,   839,   839,
     430,   525,  1219,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   839,   366,   453,   469,   512,   552,   581,   590,
    1387,  1388,   430,   430,   430,   839,   839,   430,   430,   751,
     839,   430,   854,   430,   430,   430,   430,   430,   430,   430,
     430,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    35,    92,    93,
      94,    95,    96,    97,   108,   109,   110,   249,   252,   371,
     386,   390,   428,   456,   474,   556,   622,   750,   840,   855,
     857,   858,   859,   860,   861,   862,   863,    26,   945,   430,
     520,   420,   482,   842,   843,   846,  1092,  1118,  1377,   680,
     681,   828,   266,    87,    88,   625,   459,     5,   618,   625,
     617,   617,  1126,   595,   420,     5,   556,   976,   459,   658,
    1478,   430,   458,   619,   658,   384,   737,  1092,   546,   617,
    1131,  1132,  1133,   326,  1301,   844,   846,   844,     8,   933,
      26,   500,   554,   668,   926,  1092,   926,   926,   926,    25,
     177,   304,   310,   311,   312,   330,   438,   441,   449,   484,
     519,   539,   540,   550,   555,   594,   626,  1016,  1017,   926,
     926,   596,  1013,   681,  1013,  1013,   927,   927,  1013,  1013,
     681,     5,   333,   385,     5,   680,     5,    81,    82,   539,
     626,  1004,   661,  1479,   845,   612,   613,   614,   615,  1197,
    1199,   383,  1234,  1199,  1191,     5,   617,  1192,   846,   430,
     430,   430,   430,    25,   710,   939,   430,  1428,   344,   430,
     520,   589,   578,   715,   722,   713,    25,  1078,  1092,  1185,
       8,  1188,    14,   939,  1097,  1105,  1106,  1108,  1116,  1117,
    1161,   162,   344,   544,   577,    33,   190,   553,  1446,  1447,
    1448,  1449,   575,     5,   658,   658,   844,  1111,  1118,  1000,
     420,     5,   150,   980,   430,  1092,   844,   430,    26,    26,
      65,  1090,    25,  1092,  1432,  1432,   940,  1285,  1149,   933,
     118,   221,   229,   235,   237,   248,   276,   292,   297,   309,
     316,   470,   477,   499,   504,  1273,  1274,  1282,  1292,  1293,
    1299,  1300,  1306,  1307,  1316,  1335,  1339,  1404,  1405,  1435,
    1436,  1439,  1440,  1450,   906,   907,    91,   902,   913,   914,
     905,  1085,  1491,  1043,   458,   808,   775,   458,     5,   391,
     782,   754,  1060,   754,   157,   296,   372,   430,   475,   491,
    1322,  1334,   430,   939,  1268,    26,   245,   258,   430,   475,
     491,   939,  1249,  1262,  1320,  1321,  1326,  1328,  1330,   430,
     939,  1259,   430,  1249,  1255,     5,    25,   942,  1095,  1468,
    1466,   576,   616,  1142,    20,   939,  1122,  1469,   939,  1487,
    1247,   595,   619,   589,   430,   430,   828,  1481,   839,   931,
     931,  1481,  1481,   470,  1408,   839,    25,    26,    19,    24,
      25,    26,   885,   886,   887,   888,   839,   430,   625,  1481,
      20,   839,   391,  1408,   839,    20,  1202,   873,   871,   877,
     839,   875,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   839,   430,   839,   839,   430,   866,   939,
    1092,     5,   625,   430,  1466,    25,   944,  1166,  1166,  1428,
    1076,   846,   846,   846,   928,   929,   430,  1092,  1124,   789,
     977,   978,   625,  1428,  1481,  1479,   939,   677,    20,   666,
     939,   998,  1092,   736,   624,   846,   350,  1135,   556,  1134,
       5,    68,    70,    72,   617,   625,   820,  1111,   896,    18,
      19,   430,  1014,  1016,  1145,   927,   846,   344,   595,   931,
      26,    26,   680,   152,  1196,   218,  1201,  1207,  1477,   939,
      25,   889,   931,  1481,   589,   931,   622,  1092,   695,   939,
     939,   846,   339,   718,   722,   578,   716,   724,    23,   234,
    1065,  1069,   481,   864,   481,  1186,   846,   457,  1102,   619,
       5,  1021,   546,  1162,  1092,  1467,  1470,  1092,  1114,  1115,
     189,  1447,   967,   949,  1481,  1481,   959,   960,   980,   980,
      34,    36,    37,    38,   270,   273,   275,   295,   305,   347,
     351,   429,   979,   981,   982,  1008,  1092,  1113,   546,   682,
      26,   399,   965,   321,  1427,  1427,   135,   136,   436,   546,
     939,  1336,  1337,  1378,   789,  1377,  1377,  1275,   789,   939,
    1437,  1437,   359,   475,   585,  1416,  1377,  1283,   167,   438,
     449,   470,   477,  1309,  1310,  1311,   287,   288,  1399,  1491,
    1491,   384,   915,  1092,   641,   642,   908,   909,   910,   480,
     624,   643,   644,   663,   918,   919,  1491,   754,    26,   773,
     773,   781,  1226,   754,  1216,  1324,  1377,  1267,  1334,   430,
    1267,   430,   430,  1261,  1262,   430,   430,    63,   299,   357,
     369,   379,   397,   407,   410,   423,   471,   501,   511,   532,
     535,   537,   565,   574,  1369,  1370,  1371,  1373,  1258,  1259,
    1255,  1256,   663,  1253,   391,   619,  1428,   576,   458,   546,
    1485,   675,   676,   939,   939,   939,  1243,   864,   391,   391,
     391,   391,   391,  1416,   391,   391,   391,   391,   589,   886,
      19,    26,   589,   391,   391,    26,  1388,   391,   391,   391,
     391,     5,   752,   391,   839,   839,   839,   391,   839,   391,
     391,   391,   441,   441,   441,   864,  1408,   441,   864,  1408,
     707,   708,   709,   839,   430,   842,   939,  1241,   616,  1138,
     625,     5,     5,     5,   579,   846,   619,     5,   482,   625,
     391,   426,   430,   624,   163,   166,   270,   273,   738,   741,
     742,  1008,   739,   740,   939,   430,   940,   648,   649,  1139,
     846,   939,   939,   929,   930,   508,  1481,   828,     8,   898,
      26,    26,  1015,  1016,  1092,   535,  1154,    65,   839,  1199,
      26,  1092,  1491,     5,     5,     5,   391,   391,   711,   939,
     391,  1428,   707,   430,   430,   723,   719,   360,   717,   846,
     339,   720,   724,   596,  1010,  1070,  1066,   362,  1064,  1065,
     844,   625,  1098,    20,   939,  1107,  1117,    14,    18,    19,
      20,    25,    26,    64,   395,   410,   427,   430,   443,   482,
     483,   495,   537,   576,   588,   600,   601,   608,   611,   939,
     945,  1163,  1164,  1383,  1385,  1415,  1420,  1421,  1422,  1470,
     420,   420,     5,  1491,   961,   962,   550,   938,   546,   991,
     990,   993,   992,   931,   994,   931,   995,   989,   988,   986,
     985,  1009,   324,   982,   987,  1481,    39,    40,    41,    42,
      43,    44,    98,   332,   345,   409,   416,   455,   479,   489,
     490,   495,   505,   527,   530,   531,   536,   593,   604,   683,
     684,  1006,  1007,     5,    26,  1428,   248,  1092,   470,  1409,
    1410,  1428,  1149,  1403,  1405,   100,   100,   595,  1147,  1338,
    1339,   430,  1317,   149,   525,  1343,  1350,  1377,   174,   271,
    1441,   619,   625,  1406,  1451,   341,   350,   374,   377,   395,
     500,   554,   561,   933,  1286,  1291,   430,  1312,   624,     5,
      25,   939,  1400,  1401,   917,  1092,     5,   546,   911,   912,
     638,   910,   916,   939,   916,   920,   921,   916,   324,   919,
    1044,   426,   426,   460,  1209,  1229,  1061,   460,  1172,  1203,
     430,     5,   391,     9,   294,   430,   442,  1353,  1354,  1355,
    1356,  1357,  1361,  1365,  1367,  1420,   391,   611,   939,  1323,
    1325,  1377,  1380,  1381,  1327,  1380,     5,   391,  1327,  1353,
     366,   453,   469,   512,   552,   581,   590,  1390,  1390,   430,
     430,   430,   430,   430,   430,   207,   399,  1329,  1331,     5,
     391,     5,   391,   939,  1469,     8,  1428,  1103,   846,     5,
    1248,  1249,   864,  1050,  1417,  1418,  1420,   879,  1388,   879,
      26,    26,   589,    24,    26,   792,   880,  1219,   391,  1219,
     793,   391,  1219,   874,   872,   878,  1219,   876,  1219,  1219,
    1219,    25,    25,    25,   839,   856,   391,    25,   856,   391,
     867,     5,   868,   619,  1248,   576,  1428,  1428,   846,   846,
     928,   508,   846,  1483,     5,    20,  1380,   978,  1428,   619,
     939,   739,   747,   746,   748,   939,   943,   749,   943,   191,
     742,   745,     5,   980,   619,   846,     8,   939,   864,   553,
    1289,     5,   391,  1092,     5,   325,    25,  1231,   931,   344,
     344,   458,   619,   344,   430,   696,   700,   693,  1491,  1491,
     725,   721,   717,  1011,    25,   938,  1071,  1092,  1491,   846,
     425,   458,   864,  1421,  1421,  1386,  1390,   470,  1420,   430,
     430,   430,   430,   430,   430,   430,   939,   430,     5,    18,
      19,    20,    21,    92,    93,    94,    95,    96,    97,  1442,
    1467,  1092,  1115,   968,   963,   964,    26,   680,   939,  1491,
    1491,  1491,  1491,     5,   983,     5,   984,  1491,  1491,  1491,
    1491,  1014,  1491,   938,    25,    14,    14,     5,   391,    26,
    1377,  1416,  1397,   595,   595,  1274,  1402,  1403,  1339,  1318,
    1380,   616,   933,  1353,   430,  1278,   939,  1438,  1437,  1417,
      48,    49,    50,    51,    52,   583,  1454,   846,   846,  1284,
     933,  1313,  1380,  1377,  1311,   619,   619,     5,     5,  1092,
     916,  1491,  1491,     5,   923,   924,  1491,  1491,   922,  1037,
     812,   770,    73,    74,    76,    77,    78,   176,   184,   218,
     227,   256,   257,   301,   343,   399,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,  1206,  1210,   134,   513,
    1211,  1227,  1037,   159,   175,   176,   184,   218,   227,   256,
     301,   343,  1204,  1205,  1217,  1211,  1325,  1334,  1356,   430,
    1415,  1353,  1420,  1415,     6,   391,     7,     9,    10,    12,
      13,    14,    15,    16,    17,   252,   371,   428,   556,   622,
    1364,  1366,  1381,   458,  1379,   391,     5,   619,     5,   391,
    1262,   391,   391,   625,   430,   625,    26,  1375,  1375,    26,
    1375,  1375,    26,  1374,    25,  1383,  1332,  1333,  1334,  1259,
    1255,  1428,     8,   426,   676,     5,   391,   844,   391,     5,
     546,  1344,  1349,   939,   625,   391,    26,   589,   625,   391,
     391,   391,   391,     5,   391,   391,   391,   709,   707,    20,
     391,  1428,     5,   846,   566,   274,   685,   686,   846,    20,
     939,   391,   980,  1491,  1491,     5,   743,   458,   619,     5,
     744,  1491,   740,   546,    20,   939,     5,   939,  1129,   389,
     658,   844,  1290,   897,  1016,   667,  1152,   839,     5,   707,
    1092,   692,   674,   939,  1092,   698,   391,   707,   707,  1491,
    1491,  1014,  1068,    25,  1072,  1092,   571,   893,  1103,   482,
     845,  1022,   625,  1416,   391,   395,  1443,  1470,   359,   475,
     585,  1368,  1420,  1423,  1368,  1368,  1368,  1368,   619,  1423,
    1164,  1420,  1420,  1420,  1420,    62,   542,   969,   955,   956,
     619,   931,  1491,   931,  1491,   680,    26,  1092,    26,  1092,
     684,   391,   430,  1429,  1417,  1399,  1403,  1403,  1395,     5,
     391,   470,  1414,  1279,  1380,   478,  1276,  1414,   625,  1407,
      18,    19,    64,   427,   430,   443,   482,   483,   495,   537,
     576,   588,   600,   601,   608,   611,   939,  1383,  1415,  1459,
    1460,  1461,  1462,  1463,  1464,  1470,  1459,  1459,  1459,  1380,
    1456,  1458,  1455,  1456,  1457,  1452,   553,  1287,     5,   391,
     625,   939,   939,  1401,  1092,   939,  1491,  1491,  1491,  1491,
     623,   623,  1207,  1207,  1207,    25,  1207,  1207,  1207,  1207,
    1207,  1207,    25,    25,  1207,  1210,  1092,  1119,  1120,   618,
     446,  1173,  1491,    25,    25,    26,    26,    26,    26,    26,
      25,  1092,  1205,  1173,   391,   391,  1354,  1355,  1359,  1421,
     430,  1415,  1359,   430,  1415,    10,   249,   386,   388,  1420,
      26,  1322,  1380,    20,   939,  1380,   366,   453,   469,   512,
     552,   581,   590,  1391,    26,  1391,     5,  1372,  1372,     5,
     391,   391,  1372,   391,  1334,  1428,  1249,   268,  1245,  1418,
     514,  1345,  1346,  1347,  1377,  1350,   331,   513,   524,  1294,
    1411,   366,   453,   469,   512,   552,   581,   590,  1389,   879,
     589,    24,    26,   796,   839,   869,   467,   827,     5,   373,
    1428,     5,   430,   391,   550,  1005,   943,  1491,   677,    20,
     939,   943,  1491,  1481,   846,  1481,  1114,  1491,    26,   938,
      25,  1232,  1111,   426,   707,   697,   701,   391,  1491,   938,
     846,   891,   426,  1391,  1417,     5,  1390,   391,     5,  1420,
       5,   391,  1420,  1420,  1420,  1420,   939,   391,   971,   970,
     440,   957,   958,    20,   939,  1430,  1431,   553,  1413,  1398,
    1396,  1399,  1380,  1416,   139,  1319,     5,   391,  1277,  1438,
    1413,  1462,  1462,  1461,   430,   430,   430,   430,   430,   430,
     430,   939,   430,     5,   391,    18,    19,    20,    21,  1442,
     391,     5,   391,     5,    14,   149,   525,  1453,  1288,  1380,
     462,  1314,  1315,  1378,   619,   210,  1045,   808,   782,   538,
     587,  1121,     5,  1119,    61,   133,   199,   201,   216,   224,
     228,   253,  1174,  1175,  1228,  1045,  1218,   441,  1358,  1362,
    1363,  1383,  1470,  1358,  1362,  1359,  1420,     5,   426,  1379,
     391,    26,  1376,   391,   391,    26,   391,   430,  1347,     5,
     939,  1382,   368,  1341,  1351,   939,  1412,   618,  1368,   331,
     430,    24,    26,   391,   931,   680,   373,  1428,   846,   687,
     568,  1127,    26,   680,   426,  1005,   391,   240,   680,   391,
     391,   430,   699,   344,   705,   391,   694,  1067,  1491,   458,
    1349,  1390,   625,  1390,   391,  1420,   391,   391,   391,   391,
     846,  1491,   938,     5,   391,  1114,  1349,  1399,  1399,  1417,
    1380,   430,  1349,   391,  1443,  1368,  1461,  1465,  1368,  1368,
    1368,  1368,   619,  1465,  1460,  1461,  1461,  1461,  1461,  1456,
      14,  1457,  1460,   933,  1353,  1114,     5,   140,  1308,   939,
    1120,  1176,  1177,  1092,  1179,  1092,  1178,  1180,  1175,   239,
     239,  1360,  1383,  1424,     5,   391,   391,  1358,     7,    26,
     625,   391,  1346,  1348,  1346,  1342,  1419,  1420,   447,  1340,
    1352,  1245,    26,  1295,  1296,  1297,  1380,  1409,  1412,    26,
     826,  1428,   392,   203,   259,   284,   293,   329,   337,   431,
     602,   684,   688,   689,   430,   619,   680,  1151,  1233,   702,
     391,  1111,   705,   705,  1491,   892,  1103,   391,   625,  1391,
     625,   575,  1002,  1431,  1411,  1349,   482,  1280,  1281,  1420,
    1411,   391,  1461,     5,   391,  1461,  1461,  1461,  1461,   939,
     391,   430,  1315,  1491,  1491,  1181,  1491,  1182,  1491,  1491,
    1363,  1420,   426,  1391,     5,   391,     5,  1353,     5,   538,
     587,  1298,  1245,   391,   347,   351,   829,   830,   831,  1008,
     926,   926,   926,   926,   926,   926,    25,     5,   391,   846,
      20,   939,  1008,  1155,  1156,  1157,   705,   707,   705,   241,
     426,  1391,  1391,   972,   680,     5,   391,   391,  1461,   391,
     391,   391,   391,  1459,  1491,  1491,  1346,  1419,  1296,   833,
     832,   238,   831,   834,   689,     5,  1158,   282,  1157,   703,
    1491,  1281,   391,  1491,  1491,  1491,   846,  1491,   391,   969,
     391,   704,   162,   344,   706,  1111
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
#line 932 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 935 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 939 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 945 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 950 "fgl.yacc"
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
#line 962 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 967 "fgl.yacc"
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
#line 990 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 991 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 992 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 993 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 994 "fgl.yacc"
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
#line 1008 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 1009 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1010 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1011 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1012 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1017 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1018 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1029 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1032 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1035 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1035 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1042 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1043 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1049 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1055 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1059 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1060 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1062 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1063 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1064 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 46:
#line 1065 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1072 "fgl.yacc"
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
#line 1083 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1087 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1088 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1092 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1098 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1100 "fgl.yacc"
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
#line 1111 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1113 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1115 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1117 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1121 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1123 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1184 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1188 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1192 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1199 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 66:
#line 1202 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1206 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1210 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1217 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1223 "fgl.yacc"
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
#line 1232 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1236 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1241 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1245 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1253 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1257 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1261 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1263 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1269 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1274 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1277 "fgl.yacc"
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
#line 1293 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1300 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1304 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1308 "fgl.yacc"
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
#line 1330 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1330 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1334 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1335 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1336 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1341 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1344 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1350 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1353 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1365 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1371 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1374 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1389 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1399 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1405 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1414 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1427 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1430 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1432 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1438 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1440 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1445 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1450 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1456 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1460 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1475 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1478 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1481 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1484 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1487 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1490 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1512 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1521 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1531 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1545 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1549 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1552 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1560 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1566 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1581 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1585 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1590 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1600 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1603 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1607 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1609 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1612 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1614 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1617 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1619 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1622 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1625 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1635 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1636 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1644 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1645 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1662 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1665 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1668 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1671 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1674 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1677 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1686 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1694 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1699 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1712 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1716 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1731 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1732 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1740 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1740 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1750 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1750 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1759 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1760 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1761 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1764 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1769 "fgl.yacc"
    { }
    break;

  case 194:
#line 1769 "fgl.yacc"
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
#line 1786 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1790 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1804 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1813 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1817 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1833 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1835 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1836 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1843 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1843 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1844 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1845 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1848 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1850 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1860 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1875 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1875 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1881 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1882 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1889 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1890 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1891 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1892 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1895 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1896 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1897 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1898 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1902 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1907 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1912 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1916 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1919 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1923 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1924 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1925 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1926 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1927 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1928 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1929 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1930 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1933 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1934 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1935 "fgl.yacc"
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
#line 1967 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1971 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1973 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1975 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1977 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1982 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1986 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1986 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1990 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1991 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1992 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1993 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1994 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1995 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1997 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 2002 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 2002 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 2005 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 2007 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2013 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2015 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2021 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2029 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2029 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2032 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2033 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2034 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2035 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2037 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2039 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2060 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2069 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2071 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2073 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2075 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2076 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2077 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2078 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2079 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2084 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2091 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2096 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2098 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2100 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2101 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2102 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2103 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2104 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2105 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2106 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2109 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2111 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2117 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2125 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2133 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2137 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2145 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2146 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2147 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2148 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2167 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2179 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2183 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2186 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2189 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2190 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2191 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2192 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2193 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2199 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2206 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2211 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2216 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2220 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2223 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2231 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2233 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2238 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2250 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2253 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2256 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2259 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2262 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2265 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2278 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2281 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2296 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2298 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2300 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2302 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2304 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2306 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2307 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2314 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2316 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2320 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2322 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2324 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2326 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2328 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2330 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2332 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2338 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2352 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2355 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2372 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2378 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2382 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2387 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2397 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 396:
#line 2398 "fgl.yacc"
    {inc_counter();}
    break;

  case 402:
#line 2404 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2411 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2411 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2416 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2420 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2426 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2434 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2440 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2449 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2451 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2458 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2466 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2470 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2479 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2484 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2489 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2493 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2495 "fgl.yacc"
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
#line 2505 "fgl.yacc"
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
#line 2519 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2527 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2539 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2545 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2551 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2561 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2567 "fgl.yacc"
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
#line 2639 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2645 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2649 "fgl.yacc"
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
#line 2657 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2657 "fgl.yacc"
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
#line 2673 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2677 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2683 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2686 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2694 "fgl.yacc"
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
#line 2705 "fgl.yacc"
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
#line 2715 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2721 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2731 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2736 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2743 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2746 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2749 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2754 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2761 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2766 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2771 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2776 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2787 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2795 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2803 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2808 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2812 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2817 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2821 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2825 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2831 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2834 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2838 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2842 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2846 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2850 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2854 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2861 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2871 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2876 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2882 "fgl.yacc"
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
#line 2892 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2897 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2900 "fgl.yacc"
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
#line 2914 "fgl.yacc"
    {chk4var=1;}
    break;

  case 477:
#line 2914 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 479:
#line 2917 "fgl.yacc"
    {chk4var=1;}
    break;

  case 480:
#line 2917 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 482:
#line 2921 "fgl.yacc"
    {chk4var=1;}
    break;

  case 483:
#line 2921 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 485:
#line 2925 "fgl.yacc"
    {chk4var=1;}
    break;

  case 486:
#line 2925 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2925 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 488:
#line 2929 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2935 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2941 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2947 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2957 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2958 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2966 "fgl.yacc"
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
#line 2977 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2978 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 499:
#line 2984 "fgl.yacc"
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
#line 2995 "fgl.yacc"
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
#line 3005 "fgl.yacc"
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
#line 3018 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 3023 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3030 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3034 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3037 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3040 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3046 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3049 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3052 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3069 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3072 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3078 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3079 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3080 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3085 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3086 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3087 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3088 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3090 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3091 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3092 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3094 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3095 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3101 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3106 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3118 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3122 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3123 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3130 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3147 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3151 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3157 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3161 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 541:
#line 3170 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 542:
#line 3171 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 543:
#line 3183 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 544:
#line 3189 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 545:
#line 3197 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 552:
#line 3214 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 553:
#line 3216 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3219 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 555:
#line 3221 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3235 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 561:
#line 3237 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 562:
#line 3240 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 563:
#line 3242 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 576:
#line 3273 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 577:
#line 3275 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3278 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 579:
#line 3280 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3283 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 581:
#line 3285 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3288 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 583:
#line 3290 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3293 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 585:
#line 3295 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 586:
#line 3310 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 587:
#line 3326 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 588:
#line 3327 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 589:
#line 3328 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 590:
#line 3329 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 591:
#line 3330 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3331 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 593:
#line 3332 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 597:
#line 3340 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 599:
#line 3346 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 600:
#line 3348 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 601:
#line 3349 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 602:
#line 3351 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 603:
#line 3353 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 604:
#line 3355 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 605:
#line 3357 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 606:
#line 3359 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 607:
#line 3362 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 608:
#line 3369 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 609:
#line 3371 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3377 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 611:
#line 3382 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 612:
#line 3387 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 613:
#line 3392 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 614:
#line 3392 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 615:
#line 3395 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 616:
#line 3401 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 617:
#line 3406 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 618:
#line 3410 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 621:
#line 3418 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 622:
#line 3420 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 623:
#line 3422 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 624:
#line 3424 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 625:
#line 3426 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 626:
#line 3428 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 627:
#line 3431 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 629:
#line 3440 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 630:
#line 3502 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 631:
#line 3515 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 633:
#line 3522 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 634:
#line 3525 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 635:
#line 3531 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 636:
#line 3537 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 637:
#line 3541 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 638:
#line 3545 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 639:
#line 3551 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 640:
#line 3555 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 641:
#line 3559 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 642:
#line 3564 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 643:
#line 3569 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 662:
#line 3610 "fgl.yacc"
    {
		lines_printed_true=lines_printed;
		print_if_start();
	}
    break;

  case 663:
#line 3614 "fgl.yacc"
    {
		int a;
		a=lines_printed;
		lines_printed_true=lines_printed-lines_printed_true;

		lines_printed=lines_printed-lines_printed_true; /* reset it back.. */
		lines_printed_false=lines_printed;
	}
    break;

  case 664:
#line 3621 "fgl.yacc"
    {
		char wt;
		print_if_end();
		lines_printed_false=lines_printed-lines_printed_false;
	        wt=get_curr_report_stack_whytype();
		//if (wt=='P'||wt=='p'||wt=='T') {
		if (wt=='T') {
			if (lines_printed_true!=lines_printed_false) {
				a4gl_yyerror("Number of lines printed in an IF.. THEN must be the same for TRUE and FALSE");
				YYERROR;
			}
		}
	}
    break;

  case 666:
#line 3636 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 668:
#line 3639 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 669:
#line 3641 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 670:
#line 3644 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 671:
#line 3648 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 672:
#line 3651 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 673:
#line 3657 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 674:
#line 3668 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 675:
#line 3669 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 676:
#line 3672 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 678:
#line 3678 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 679:
#line 3682 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 680:
#line 3683 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 683:
#line 3697 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 684:
#line 3699 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 687:
#line 3708 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 688:
#line 3710 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3714 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 690:
#line 3716 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 691:
#line 3719 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 692:
#line 3721 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 693:
#line 3724 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 694:
#line 3727 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 695:
#line 3730 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 696:
#line 3732 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 697:
#line 3735 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 698:
#line 3737 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 699:
#line 3740 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 700:
#line 3742 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 701:
#line 3745 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 702:
#line 3747 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3748 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 704:
#line 3750 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3751 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 706:
#line 3753 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 707:
#line 3754 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 708:
#line 3756 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 709:
#line 3796 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 710:
#line 3797 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 711:
#line 3805 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 712:
#line 3806 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 713:
#line 3815 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 714:
#line 3820 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 715:
#line 3825 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 716:
#line 3826 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 718:
#line 3831 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 719:
#line 3834 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 720:
#line 3842 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 721:
#line 3847 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 722:
#line 3851 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 723:
#line 3858 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 724:
#line 3867 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 725:
#line 3873 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 726:
#line 3874 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 727:
#line 3875 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 728:
#line 3876 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 729:
#line 3879 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 731:
#line 3882 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 732:
#line 3889 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3890 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 734:
#line 3891 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 735:
#line 3892 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 736:
#line 3893 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 737:
#line 3894 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 738:
#line 3895 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 739:
#line 3896 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 740:
#line 3897 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 741:
#line 3902 "fgl.yacc"
    {iskey=1;}
    break;

  case 742:
#line 3902 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 743:
#line 3904 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 744:
#line 3907 "fgl.yacc"
    {iskey=1;}
    break;

  case 745:
#line 3907 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 746:
#line 3909 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 747:
#line 3913 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 748:
#line 3916 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 749:
#line 3917 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 751:
#line 3920 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 757:
#line 3932 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 758:
#line 3933 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 759:
#line 3934 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 760:
#line 3935 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 761:
#line 3936 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 762:
#line 3937 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 763:
#line 3938 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 764:
#line 3939 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 765:
#line 3940 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 766:
#line 3941 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 767:
#line 3942 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 768:
#line 3943 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 769:
#line 3944 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 770:
#line 3945 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 771:
#line 3949 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 772:
#line 3967 "fgl.yacc"
    {chk4var=1;}
    break;

  case 773:
#line 3967 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 774:
#line 3970 "fgl.yacc"
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

  case 775:
#line 3994 "fgl.yacc"
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

  case 777:
#line 4012 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 778:
#line 4018 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 779:
#line 4024 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 780:
#line 4030 "fgl.yacc"
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

  case 781:
#line 4041 "fgl.yacc"
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

  case 782:
#line 4064 "fgl.yacc"
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

  case 785:
#line 4080 "fgl.yacc"
    {
	}
    break;

  case 792:
#line 4103 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 796:
#line 4111 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 814:
#line 4137 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 815:
#line 4138 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 816:
#line 4146 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 817:
#line 4151 "fgl.yacc"
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

  case 818:
#line 4167 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 819:
#line 4173 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 821:
#line 4188 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 822:
#line 4201 "fgl.yacc"
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

  case 823:
#line 4211 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 824:
#line 4218 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 825:
#line 4225 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 826:
#line 4231 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 827:
#line 4231 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 828:
#line 4236 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 829:
#line 4242 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 830:
#line 4250 "fgl.yacc"
    {
}
    break;

  case 836:
#line 4262 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 838:
#line 4270 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 839:
#line 4276 "fgl.yacc"
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

  case 840:
#line 4290 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 841:
#line 4294 "fgl.yacc"
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

  case 842:
#line 4307 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 844:
#line 4325 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 845:
#line 4333 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 846:
#line 4339 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 847:
#line 4350 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 848:
#line 4354 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 849:
#line 4361 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 850:
#line 4368 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 851:
#line 4374 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 852:
#line 4379 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 855:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 856:
#line 4387 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 857:
#line 4389 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 858:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 859:
#line 4393 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 860:
#line 4394 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 861:
#line 4395 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 862:
#line 4397 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 863:
#line 4402 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 864:
#line 4407 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 865:
#line 4414 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 869:
#line 4421 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 870:
#line 4423 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 871:
#line 4425 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 872:
#line 4434 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 873:
#line 4440 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 874:
#line 4444 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 877:
#line 4456 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 878:
#line 4461 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 879:
#line 4466 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 880:
#line 4469 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 882:
#line 4481 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 883:
#line 4484 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 884:
#line 4487 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 891:
#line 4503 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 892:
#line 4508 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 893:
#line 4508 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 894:
#line 4511 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 895:
#line 4538 "fgl.yacc"
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

  case 897:
#line 4596 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 899:
#line 4603 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 900:
#line 4607 "fgl.yacc"
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

  case 901:
#line 4650 "fgl.yacc"
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

  case 905:
#line 4698 "fgl.yacc"
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

  case 906:
#line 4712 "fgl.yacc"
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

  case 911:
#line 4736 "fgl.yacc"
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

  case 912:
#line 4796 "fgl.yacc"
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

  case 913:
#line 4852 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 914:
#line 4857 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 915:
#line 4865 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 916:
#line 4870 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 917:
#line 4878 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 918:
#line 4884 "fgl.yacc"
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

  case 919:
#line 4917 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 920:
#line 4920 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 921:
#line 4922 "fgl.yacc"
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

  case 922:
#line 4963 "fgl.yacc"
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

  case 927:
#line 5016 "fgl.yacc"
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

  case 928:
#line 5068 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 930:
#line 5075 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 931:
#line 5081 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 932:
#line 5092 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 933:
#line 5099 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 935:
#line 5107 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 936:
#line 5110 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 937:
#line 5111 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 939:
#line 5113 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 940:
#line 5114 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 941:
#line 5117 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 942:
#line 5120 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5126 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 944:
#line 5129 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 945:
#line 5133 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 946:
#line 5137 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5144 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 948:
#line 5149 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 949:
#line 5156 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 950:
#line 5159 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5172 "fgl.yacc"
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

  case 956:
#line 5191 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 957:
#line 5198 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 958:
#line 5205 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 959:
#line 5208 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 960:
#line 5222 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 965:
#line 5239 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 966:
#line 5244 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 967:
#line 5250 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 969:
#line 5257 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 970:
#line 5262 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 971:
#line 5265 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 972:
#line 5266 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 973:
#line 5269 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 974:
#line 5270 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 975:
#line 5273 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 976:
#line 5274 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 977:
#line 5279 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 978:
#line 5286 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 979:
#line 5289 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 980:
#line 5295 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 981:
#line 5297 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 982:
#line 5299 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 983:
#line 5301 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 984:
#line 5304 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 985:
#line 5304 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 986:
#line 5305 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 987:
#line 5310 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 988:
#line 5318 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 989:
#line 5319 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 990:
#line 5324 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 991:
#line 5326 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5328 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5345 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 997:
#line 5348 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 998:
#line 5351 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 999:
#line 5354 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1000:
#line 5358 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1001:
#line 5361 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1002:
#line 5364 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5368 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1004:
#line 5372 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1005:
#line 5376 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1006:
#line 5379 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1007:
#line 5383 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1008:
#line 5386 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1009:
#line 5387 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1010:
#line 5388 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1011:
#line 5391 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1012:
#line 5394 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1013:
#line 5397 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1014:
#line 5400 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1015:
#line 5403 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1016:
#line 5406 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1017:
#line 5409 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1018:
#line 5426 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1021:
#line 5436 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1022:
#line 5443 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1024:
#line 5464 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1025:
#line 5469 "fgl.yacc"
    {
		if (strcmp(yyvsp[-6].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-5].str);
                pop_blockcommand("PROMPT");
                A4GL_lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1026:
#line 5481 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1027:
#line 5482 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1028:
#line 5486 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1029:
#line 5491 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1030:
#line 5492 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1031:
#line 5496 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1035:
#line 5502 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1036:
#line 5504 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1038:
#line 5519 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1039:
#line 5523 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1040:
#line 5529 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1041:
#line 5530 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1042:
#line 5533 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1043:
#line 5534 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1044:
#line 5537 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1046:
#line 5556 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1047:
#line 5561 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1048:
#line 5566 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1049:
#line 5571 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1055:
#line 5593 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1056:
#line 5600 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1057:
#line 5609 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1058:
#line 5615 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1059:
#line 5617 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1063:
#line 5628 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1064:
#line 5629 "fgl.yacc"
    {
rep_struct.lines_in_first_header=lines_printed;
pdf_rep_struct.lines_in_first_header=lines_printed;
print_rep_ret(0);}
    break;

  case 1065:
#line 5634 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1066:
#line 5635 "fgl.yacc"
    {
rep_struct.lines_in_trailer=lines_printed;
pdf_rep_struct.lines_in_trailer=lines_printed;
print_rep_ret(0);}
    break;

  case 1067:
#line 5640 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1068:
#line 5641 "fgl.yacc"
    {
rep_struct.lines_in_header=lines_printed;
pdf_rep_struct.lines_in_header=lines_printed;
print_rep_ret(0);}
    break;

  case 1069:
#line 5646 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1070:
#line 5647 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1071:
#line 5649 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1072:
#line 5650 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1073:
#line 5651 "fgl.yacc"
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

  case 1074:
#line 5665 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1075:
#line 5667 "fgl.yacc"
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

  case 1076:
#line 5684 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1083:
#line 5696 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1084:
#line 5696 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1085:
#line 5702 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1086:
#line 5702 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1087:
#line 5705 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1088:
#line 5705 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	lines_printed+=(int)n;
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1089:
#line 5718 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1090:
#line 5719 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1091:
#line 5720 "fgl.yacc"
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

  case 1092:
#line 5729 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1093:
#line 5741 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1099:
#line 5752 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1100:
#line 5757 "fgl.yacc"
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
	if (strcmp(yyvsp[0].str,"0")==0) lines_printed++;
}
    break;

  case 1101:
#line 5772 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1102:
#line 5777 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1103:
#line 5783 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1104:
#line 5784 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1105:
#line 5785 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1106:
#line 5789 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1107:
#line 5790 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1108:
#line 5791 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1109:
#line 5792 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1110:
#line 5796 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1111:
#line 5806 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1112:
#line 5808 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1113:
#line 5813 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1114:
#line 5816 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1115:
#line 5821 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1116:
#line 5828 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5835 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1118:
#line 5842 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1119:
#line 5851 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1120:
#line 5858 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1121:
#line 5865 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1122:
#line 5872 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1123:
#line 5879 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5892 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1129:
#line 5893 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1130:
#line 5894 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1131:
#line 5895 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1132:
#line 5896 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1133:
#line 5897 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1134:
#line 5898 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1135:
#line 5899 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1136:
#line 5900 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1137:
#line 5901 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1140:
#line 5907 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1141:
#line 5908 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1142:
#line 5909 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1143:
#line 5910 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1148:
#line 5919 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1149:
#line 5920 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5921 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1151:
#line 5922 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1152:
#line 5923 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1153:
#line 5924 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1154:
#line 5925 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1155:
#line 5926 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1156:
#line 5928 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1157:
#line 5929 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1158:
#line 5930 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1159:
#line 5931 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1160:
#line 5933 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1161:
#line 5934 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1162:
#line 5935 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1163:
#line 5936 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1167:
#line 5941 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1168:
#line 5942 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1172:
#line 5949 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1173:
#line 5957 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1174:
#line 5965 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1175:
#line 5977 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1176:
#line 5986 "fgl.yacc"
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

  case 1177:
#line 5997 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1178:
#line 6001 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1179:
#line 6005 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1180:
#line 6011 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1181:
#line 6016 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1182:
#line 6024 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1183:
#line 6027 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1184:
#line 6036 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1185:
#line 6047 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1187:
#line 6054 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1188:
#line 6062 "fgl.yacc"
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

  case 1189:
#line 6072 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1190:
#line 6075 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1191:
#line 6079 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1192:
#line 6087 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1193:
#line 6090 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1194:
#line 6096 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1195:
#line 6100 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1196:
#line 6104 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1197:
#line 6108 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1198:
#line 6112 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1199:
#line 6118 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1200:
#line 6119 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1201:
#line 6120 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1202:
#line 6121 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1203:
#line 6126 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1204:
#line 6128 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1205:
#line 6131 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1206:
#line 6135 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1207:
#line 6138 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1208:
#line 6145 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1209:
#line 6150 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1210:
#line 6151 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1211:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1212:
#line 6157 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1213:
#line 6158 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1214:
#line 6164 "fgl.yacc"
    {insql=1;}
    break;

  case 1215:
#line 6164 "fgl.yacc"
    {insql=0;}
    break;

  case 1216:
#line 6164 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1217:
#line 6169 "fgl.yacc"
    {insql=1;}
    break;

  case 1218:
#line 6169 "fgl.yacc"
    {insql=0;}
    break;

  case 1219:
#line 6169 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1220:
#line 6180 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1221:
#line 6181 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1222:
#line 6187 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1223:
#line 6189 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1225:
#line 6202 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1226:
#line 6206 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1227:
#line 6207 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1229:
#line 6212 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1230:
#line 6215 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1231:
#line 6221 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1232:
#line 6224 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1233:
#line 6232 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1235:
#line 6239 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1236:
#line 6246 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1237:
#line 6249 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1238:
#line 6258 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1239:
#line 6261 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1240:
#line 6264 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1241:
#line 6267 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1242:
#line 6270 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1243:
#line 6273 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1244:
#line 6276 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1245:
#line 6283 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1246:
#line 6286 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1247:
#line 6293 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1249:
#line 6302 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6305 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1251:
#line 6312 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1252:
#line 6315 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1254:
#line 6323 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1256:
#line 6332 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1257:
#line 6335 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1258:
#line 6341 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 6344 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1260:
#line 6350 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 6357 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1262:
#line 6358 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1263:
#line 6362 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1264:
#line 6368 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1265:
#line 6371 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1267:
#line 6379 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1268:
#line 6386 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1269:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1273:
#line 6407 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1279:
#line 6413 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1280:
#line 6416 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1281:
#line 6419 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1282:
#line 6425 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1284:
#line 6431 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1286:
#line 6442 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1287:
#line 6456 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1288:
#line 6465 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1289:
#line 6465 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1290:
#line 6470 "fgl.yacc"
    {insql=1;}
    break;

  case 1291:
#line 6470 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1292:
#line 6475 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1293:
#line 6478 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1294:
#line 6480 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1296:
#line 6487 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1297:
#line 6491 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1298:
#line 6495 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1299:
#line 6502 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1300:
#line 6505 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1301:
#line 6512 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1302:
#line 6516 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1303:
#line 6520 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1304:
#line 6525 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1305:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1306:
#line 6534 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1307:
#line 6540 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1308:
#line 6544 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1309:
#line 6550 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1310:
#line 6557 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1311:
#line 6561 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1312:
#line 6566 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1313:
#line 6576 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1314:
#line 6579 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1315:
#line 6581 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1316:
#line 6583 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1317:
#line 6585 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1318:
#line 6587 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1319:
#line 6589 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1320:
#line 6591 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1321:
#line 6597 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1322:
#line 6607 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1323:
#line 6614 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6620 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1329:
#line 6629 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1332:
#line 6634 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1333:
#line 6639 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1334:
#line 6646 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1335:
#line 6647 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1336:
#line 6654 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1337:
#line 6665 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1338:
#line 6666 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1339:
#line 6669 "fgl.yacc"
    {insql=1;}
    break;

  case 1340:
#line 6669 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1341:
#line 6674 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1342:
#line 6679 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1344:
#line 6685 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1346:
#line 6689 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1347:
#line 6694 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1348:
#line 6699 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1349:
#line 6703 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1351:
#line 6709 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1352:
#line 6713 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1353:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1354:
#line 6724 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1355:
#line 6726 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1356:
#line 6731 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1359:
#line 6738 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1363:
#line 6745 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1365:
#line 6750 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6756 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1372:
#line 6772 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1373:
#line 6777 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1374:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1376:
#line 6785 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6788 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1379:
#line 6794 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1380:
#line 6802 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6807 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6817 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6823 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6829 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6831 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6837 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1392:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1393:
#line 6848 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1394:
#line 6856 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6858 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1396:
#line 6871 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1397:
#line 6876 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1399:
#line 6880 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1400:
#line 6882 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1401:
#line 6889 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1402:
#line 6892 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1403:
#line 6898 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1404:
#line 6902 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1405:
#line 6906 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1406:
#line 6910 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1407:
#line 6913 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1408:
#line 6921 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1409:
#line 6928 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1412:
#line 6937 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6943 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1414:
#line 6946 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1415:
#line 6957 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1416:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1417:
#line 6970 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1418:
#line 6973 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1419:
#line 6980 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1420:
#line 6987 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1422:
#line 6994 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1423:
#line 7000 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1424:
#line 7001 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 7002 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1427:
#line 7006 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 7011 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1430:
#line 7018 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1431:
#line 7023 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1432:
#line 7024 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1433:
#line 7027 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1434:
#line 7030 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1435:
#line 7035 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1436:
#line 7036 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1437:
#line 7041 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 7044 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1439:
#line 7050 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1440:
#line 7053 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1441:
#line 7059 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1442:
#line 7062 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1443:
#line 7068 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1444:
#line 7071 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1445:
#line 7078 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1446:
#line 7079 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1447:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1448:
#line 7110 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1449:
#line 7114 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1451:
#line 7127 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1452:
#line 7130 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 7133 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1454:
#line 7136 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1456:
#line 7144 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1457:
#line 7147 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1459:
#line 7153 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1461:
#line 7159 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1462:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1463:
#line 7165 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1464:
#line 7168 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1465:
#line 7171 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1466:
#line 7174 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1467:
#line 7177 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1469:
#line 7184 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1474:
#line 7191 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1475:
#line 7192 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1476:
#line 7197 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1477:
#line 7200 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1478:
#line 7204 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1479:
#line 7210 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1480:
#line 7211 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1481:
#line 7212 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1482:
#line 7213 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1487:
#line 7233 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1488:
#line 7238 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1489:
#line 7239 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1491:
#line 7242 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 7247 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7250 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7253 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7258 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 7260 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7263 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1506:
#line 7264 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1507:
#line 7271 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7276 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1515:
#line 7292 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1516:
#line 7293 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1517:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1518:
#line 7298 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1520:
#line 7317 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1521:
#line 7318 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1522:
#line 7319 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1523:
#line 7323 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1524:
#line 7326 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1525:
#line 7332 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1526:
#line 7337 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1527:
#line 7342 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1529:
#line 7353 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1534:
#line 7368 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1535:
#line 7371 "fgl.yacc"
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

  case 1536:
#line 7384 "fgl.yacc"
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

  case 1537:
#line 7399 "fgl.yacc"
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

  case 1538:
#line 7411 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1539:
#line 7413 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1540:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1541:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1542:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1543:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1544:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1545:
#line 7416 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1546:
#line 7417 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1547:
#line 7420 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1548:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1549:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1550:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1551:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1552:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1553:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1554:
#line 7427 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1555:
#line 7430 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1570:
#line 7439 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1571:
#line 7440 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1572:
#line 7444 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1573:
#line 7452 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7452 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1575:
#line 7458 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1576:
#line 7458 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1577:
#line 7465 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1578:
#line 7465 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1579:
#line 7471 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1580:
#line 7471 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1581:
#line 7479 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1582:
#line 7480 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1583:
#line 7481 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1587:
#line 7488 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1588:
#line 7489 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1589:
#line 7494 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1590:
#line 7497 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1591:
#line 7503 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1592:
#line 7508 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1593:
#line 7517 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1594:
#line 7529 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1595:
#line 7530 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1596:
#line 7533 "fgl.yacc"
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

  case 1597:
#line 7548 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1598:
#line 7558 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1599:
#line 7561 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1600:
#line 7569 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1601:
#line 7578 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1602:
#line 7581 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1603:
#line 7585 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1604:
#line 7588 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1605:
#line 7589 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1607:
#line 7598 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1608:
#line 7599 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1609:
#line 7608 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1610:
#line 7617 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1611:
#line 7622 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1612:
#line 7623 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1613:
#line 7624 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1614:
#line 7625 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1615:
#line 7632 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1616:
#line 7635 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7641 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7644 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1619:
#line 7654 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1620:
#line 7663 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1621:
#line 7666 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1622:
#line 7669 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1623:
#line 7675 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1624:
#line 7681 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1625:
#line 7684 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1626:
#line 7687 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1627:
#line 7690 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1628:
#line 7697 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1629:
#line 7699 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1630:
#line 7701 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1631:
#line 7703 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1632:
#line 7705 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1633:
#line 7706 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1634:
#line 7707 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1635:
#line 7708 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1636:
#line 7709 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1637:
#line 7710 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1638:
#line 7711 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1639:
#line 7713 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7715 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7717 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7719 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1643:
#line 7721 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1644:
#line 7723 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1645:
#line 7725 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1646:
#line 7726 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1647:
#line 7728 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1648:
#line 7732 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1649:
#line 7733 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1651:
#line 7743 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1652:
#line 7752 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1653:
#line 7756 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1654:
#line 7763 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1655:
#line 7763 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1657:
#line 7767 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1658:
#line 7772 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1659:
#line 7772 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1661:
#line 7776 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1662:
#line 7780 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1665:
#line 7789 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1666:
#line 7789 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1671:
#line 7808 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1672:
#line 7809 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1675:
#line 7817 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1676:
#line 7823 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1679:
#line 7842 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1680:
#line 7843 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1681:
#line 7844 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1682:
#line 7845 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1683:
#line 7846 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1684:
#line 7847 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1685:
#line 7851 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1686:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1687:
#line 7853 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1688:
#line 7857 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1689:
#line 7861 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1691:
#line 7870 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1693:
#line 7875 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1694:
#line 7876 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1695:
#line 7880 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1696:
#line 7886 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1697:
#line 7973 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1698:
#line 7977 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1699:
#line 7979 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1700:
#line 7986 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1701:
#line 7990 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1702:
#line 7996 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1703:
#line 8004 "fgl.yacc"
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

  case 1704:
#line 8014 "fgl.yacc"
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

  case 1705:
#line 8024 "fgl.yacc"
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

  case 1706:
#line 8036 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1707:
#line 8039 "fgl.yacc"
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

  case 1708:
#line 8058 "fgl.yacc"
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

  case 1709:
#line 8084 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1710:
#line 8087 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1712:
#line 8096 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1713:
#line 8101 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1714:
#line 8104 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1715:
#line 8112 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1716:
#line 8120 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1717:
#line 8133 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1718:
#line 8136 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1719:
#line 8144 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1720:
#line 8147 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1721:
#line 8150 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1722:
#line 8158 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1723:
#line 8162 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1724:
#line 8165 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1725:
#line 8168 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1726:
#line 8171 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1727:
#line 8175 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1728:
#line 8176 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1729:
#line 8177 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1730:
#line 8178 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1731:
#line 8179 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1732:
#line 8185 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1733:
#line 8186 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1734:
#line 8187 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1735:
#line 8188 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1736:
#line 8189 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1737:
#line 8190 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1738:
#line 8191 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1739:
#line 8192 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1740:
#line 8193 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1741:
#line 8194 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1742:
#line 8195 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1743:
#line 8196 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1744:
#line 8197 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1745:
#line 8198 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1746:
#line 8202 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1747:
#line 8208 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1748:
#line 8209 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1749:
#line 8222 "fgl.yacc"
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

  case 1750:
#line 8242 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1754:
#line 8248 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1755:
#line 8249 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1759:
#line 8261 "fgl.yacc"
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

  case 1760:
#line 8287 "fgl.yacc"
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

  case 1761:
#line 8338 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 8340 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 8342 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8343 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1765:
#line 8348 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1766:
#line 8353 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1767:
#line 8354 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1768:
#line 8358 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1769:
#line 8360 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1770:
#line 8362 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1771:
#line 8365 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1772:
#line 8369 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1773:
#line 8374 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1774:
#line 8379 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1775:
#line 8383 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1777:
#line 8393 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1779:
#line 8408 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1780:
#line 8411 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1781:
#line 8415 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1784:
#line 8434 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1785:
#line 8435 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1786:
#line 8438 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1787:
#line 8439 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1788:
#line 8440 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1789:
#line 8441 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1790:
#line 8442 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1791:
#line 8443 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1792:
#line 8444 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1793:
#line 8449 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1794:
#line 8450 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1795:
#line 8454 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1796:
#line 8458 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1797:
#line 8462 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1798:
#line 8466 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1799:
#line 8471 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1800:
#line 8475 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1801:
#line 8480 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1803:
#line 8488 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1805:
#line 8494 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1806:
#line 8500 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1807:
#line 8504 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1812:
#line 8522 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1813:
#line 8529 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1814:
#line 8538 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1815:
#line 8538 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17199 "y.tab.c"

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


#line 8633 "fgl.yacc"

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



