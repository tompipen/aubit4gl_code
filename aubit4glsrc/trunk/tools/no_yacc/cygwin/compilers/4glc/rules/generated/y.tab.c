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
     NAME = 1654,
     UMINUS = 1655,
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
     NUMBER_VALUE = 1656,
     CHAR_VALUE = 1657,
     INT_VALUE = 1658,
     NAMED_GEN = 1659,
     CLINE = 1660,
     SQLLINE = 1661,
     KW_CSTART = 1662,
     KW_CEND = 1663,
     USER_DTYPE = 1664,
     SQL_TEXT = 1665,
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
     TIMEOUT = 1652
   };
#endif
#define NAME 1654
#define UMINUS 1655
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
#define NUMBER_VALUE 1656
#define CHAR_VALUE 1657
#define INT_VALUE 1658
#define NAMED_GEN 1659
#define CLINE 1660
#define SQLLINE 1661
#define KW_CSTART 1662
#define KW_CEND 1663
#define USER_DTYPE 1664
#define SQL_TEXT 1665
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
#line 207 "fgl.yacc"
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
#line 1576 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1588 "y.tab.c"

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
#define YYLAST   8475

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  668
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  827
/* YYNRULES -- Number of rules. */
#define YYNRULES  1897
/* YYNRULES -- Number of states. */
#define YYNSTATES  3163

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1665

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
     665,   666,   667,     2,     3,     4,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33
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
    2385,  2386,  2393,  2396,  2398,  2401,  2404,  2407,  2409,  2411,
    2414,  2416,  2418,  2420,  2421,  2425,  2428,  2430,  2431,  2432,
    2433,  2448,  2449,  2455,  2457,  2458,  2462,  2463,  2471,  2472,
    2478,  2480,  2483,  2484,  2486,  2488,  2490,  2491,  2493,  2495,
    2498,  2501,  2504,  2506,  2508,  2510,  2512,  2516,  2518,  2520,
    2521,  2522,  2530,  2532,  2535,  2536,  2540,  2541,  2546,  2549,
    2550,  2553,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2571,
    2572,  2574,  2576,  2578,  2580,  2583,  2586,  2589,  2595,  2604,
    2606,  2608,  2610,  2615,  2620,  2622,  2624,  2626,  2628,  2631,
    2634,  2638,  2645,  2647,  2651,  2653,  2655,  2657,  2661,  2668,
    2678,  2680,  2682,  2684,  2686,  2689,  2690,  2692,  2694,  2698,
    2700,  2704,  2706,  2710,  2712,  2716,  2718,  2720,  2722,  2724,
    2728,  2730,  2734,  2736,  2740,  2742,  2744,  2746,  2750,  2753,
    2754,  2756,  2758,  2763,  2765,  2769,  2771,  2775,  2783,  2784,
    2792,  2793,  2800,  2804,  2806,  2810,  2812,  2815,  2821,  2822,
    2830,  2831,  2834,  2835,  2837,  2843,  2846,  2852,  2853,  2859,
    2866,  2871,  2872,  2874,  2876,  2881,  2882,  2885,  2886,  2892,
    2897,  2900,  2902,  2906,  2909,  2912,  2915,  2918,  2921,  2924,
    2926,  2929,  2932,  2935,  2938,  2941,  2944,  2947,  2950,  2953,
    2955,  2957,  2959,  2961,  2963,  2965,  2971,  2973,  2975,  2978,
    2983,  2985,  2986,  2998,  2999,  3002,  3008,  3009,  3011,  3012,
    3015,  3017,  3020,  3021,  3025,  3027,  3028,  3033,  3034,  3037,
    3039,  3043,  3045,  3047,  3051,  3056,  3061,  3064,  3066,  3068,
    3070,  3071,  3073,  3081,  3084,  3087,  3090,  3093,  3096,  3098,
    3101,  3102,  3106,  3107,  3111,  3112,  3116,  3117,  3121,  3122,
    3126,  3127,  3132,  3133,  3138,  3140,  3142,  3144,  3146,  3148,
    3150,  3151,  3156,  3157,  3159,  3160,  3165,  3167,  3170,  3173,
    3176,  3177,  3179,  3181,  3184,  3187,  3188,  3191,  3195,  3199,
    3205,  3206,  3209,  3214,  3216,  3218,  3220,  3222,  3224,  3225,
    3227,  3229,  3233,  3236,  3242,  3245,  3251,  3257,  3263,  3269,
    3275,  3281,  3282,  3285,  3287,  3290,  3293,  3296,  3299,  3302,
    3305,  3307,  3310,  3313,  3316,  3319,  3321,  3324,  3327,  3330,
    3333,  3335,  3337,  3339,  3340,  3343,  3346,  3349,  3352,  3355,
    3358,  3361,  3364,  3367,  3369,  3371,  3373,  3375,  3377,  3379,
    3381,  3383,  3386,  3389,  3392,  3395,  3398,  3400,  3402,  3404,
    3405,  3409,  3412,  3413,  3414,  3415,  3416,  3417,  3418,  3434,
    3435,  3438,  3441,  3442,  3444,  3445,  3446,  3447,  3448,  3449,
    3450,  3466,  3469,  3470,  3471,  3472,  3483,  3484,  3486,  3490,
    3494,  3497,  3502,  3506,  3510,  3514,  3516,  3518,  3520,  3522,
    3524,  3526,  3527,  3528,  3536,  3537,  3538,  3547,  3551,  3554,
    3555,  3557,  3559,  3563,  3566,  3569,  3571,  3573,  3577,  3579,
    3581,  3584,  3586,  3590,  3592,  3596,  3598,  3600,  3602,  3604,
    3606,  3608,  3610,  3613,  3618,  3620,  3624,  3626,  3630,  3633,
    3638,  3640,  3644,  3646,  3649,  3654,  3656,  3660,  3662,  3664,
    3666,  3669,  3672,  3677,  3680,  3685,  3687,  3691,  3693,  3695,
    3697,  3700,  3702,  3704,  3706,  3708,  3710,  3713,  3720,  3727,
    3728,  3730,  3731,  3733,  3736,  3738,  3739,  3745,  3746,  3752,
    3754,  3755,  3759,  3761,  3765,  3767,  3771,  3773,  3775,  3776,
    3777,  3783,  3785,  3788,  3790,  3791,  3792,  3796,  3797,  3798,
    3802,  3804,  3806,  3808,  3810,  3812,  3814,  3817,  3820,  3825,
    3829,  3833,  3835,  3839,  3842,  3844,  3846,  3847,  3849,  3851,
    3853,  3855,  3856,  3858,  3862,  3864,  3866,  3867,  3871,  3873,
    3875,  3877,  3879,  3881,  3883,  3885,  3887,  3889,  3891,  3893,
    3895,  3903,  3904,  3906,  3908,  3910,  3912,  3916,  3918,  3920,
    3922,  3925,  3926,  3930,  3932,  3936,  3938,  3942,  3944,  3946,
    3953,  3954,  3958,  3960,  3964,  3965,  3967,  3972,  3978,  3981,
    3983,  3985,  3990,  3992,  3996,  4001,  4006,  4008,  4012,  4014,
    4016,  4018,  4021,  4023,  4028,  4029,  4031,  4032,  4034,  4036,
    4039,  4041,  4043,  4045,  4047,  4052,  4056,  4058,  4060,  4062,
    4065,  4067,  4069,  4072,  4075,  4077,  4081,  4084,  4087,  4089,
    4093,  4095,  4098,  4103,  4105,  4108,  4110,  4114,  4119,  4120,
    4122,  4123,  4125,  4126,  4128,  4130,  4134,  4136,  4140,  4142,
    4145,  4147,  4151,  4154,  4157,  4158,  4161,  4163,  4165,  4171,
    4175,  4181,  4185,  4187,  4191,  4193,  4195,  4196,  4198,  4202,
    4206,  4210,  4217,  4222,  4227,  4233,  4235,  4237,  4239,  4241,
    4243,  4245,  4247,  4249,  4251,  4253,  4255,  4256,  4258,  4260,
    4262,  4264,  4266,  4268,  4270,  4275,  4281,  4283,  4289,  4295,
    4297,  4299,  4301,  4306,  4308,  4313,  4315,  4323,  4325,  4327,
    4329,  4334,  4341,  4342,  4345,  4350,  4352,  4354,  4356,  4358,
    4360,  4362,  4364,  4368,  4370,  4372,  4376,  4378,  4379,  4383,
    4389,  4391,  4394,  4397,  4402,  4406,  4408,  4410,  4412,  4414,
    4416,  4418,  4421,  4424,  4425,  4429,  4430,  4434,  4436,  4438,
    4440,  4442,  4444,  4446,  4448,  4453,  4455,  4457,  4459,  4461,
    4463,  4465,  4467,  4472,  4474,  4476,  4478,  4480,  4482,  4484,
    4486,  4488,  4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,
    4508,  4509,  4518,  4519,  4529,  4530,  4538,  4539,  4549,  4550,
    4552,  4555,  4557,  4561,  4563,  4567,  4573,  4575,  4577,  4579,
    4581,  4584,  4585,  4586,  4595,  4601,  4603,  4605,  4612,  4613,
    4617,  4619,  4623,  4628,  4630,  4631,  4634,  4639,  4646,  4647,
    4649,  4651,  4653,  4655,  4659,  4661,  4664,  4666,  4668,  4671,
    4674,  4676,  4678,  4680,  4683,  4688,  4692,  4695,  4699,  4703,
    4707,  4709,  4711,  4713,  4715,  4717,  4719,  4725,  4731,  4737,
    4743,  4749,  4754,  4759,  4763,  4768,  4770,  4774,  4776,  4782,
    4790,  4796,  4797,  4800,  4802,  4804,  4805,  4809,  4811,  4815,
    4817,  4819,  4821,  4822,  4826,  4828,  4830,  4832,  4834,  4839,
    4846,  4848,  4850,  4853,  4857,  4859,  4861,  4863,  4865,  4867,
    4869,  4871,  4873,  4879,  4885,  4890,  4891,  4896,  4898,  4901,
    4903,  4905,  4907,  4910,  4913,  4914,  4915,  4922,  4923,  4926,
    4929,  4937,  4941,  4945,  4948,  4951,  4954,  4956,  4960,  4962,
    4966,  4968,  4972,  4974,  4978,  4980,  4982,  4984,  4987,  4990,
    4992,  4994,  4997,  5002,  5004,  5006,  5008,  5010,  5012,  5014,
    5018,  5021,  5025,  5029,  5033,  5039,  5045,  5051,  5057,  5063,
    5068,  5073,  5077,  5082,  5084,  5086,  5090,  5092,  5095,  5097,
    5099,  5101,  5105,  5111,  5113,  5115,  5117,  5119,  5123,  5126,
    5129,  5132,  5134,  5137,  5140,  5142,  5145,  5148,  5151,  5153,
    5157,  5160,  5162,  5165,  5167,  5170,  5172,  5173,  5174,  5181,
    5182,  5185,  5186,  5188,  5190,  5193,  5196,  5198,  5200,  5205,
    5209,  5211,  5215,  5217,  5220,  5226,  5229,  5232,  5238,  5239,
    5242,  5244,  5246,  5249,  5256,  5263,  5265,  5266,  5268,  5271,
    5273,  5276,  5277,  5280,  5282,  5284,  5286,  5288,  5290,  5292,
    5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,
    5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,  5332,
    5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,  5350,  5352,
    5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,  5370,  5372,
    5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,  5392,
    5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,  5412,
    5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,  5432,
    5434,  5436,  5438,  5440,  5442,  5444,  5446,  5448
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1025,     0,    -1,   200,    -1,   197,    -1,   124,   673,   426,
     595,   674,    -1,   138,    -1,  1090,    -1,    26,    -1,   675,
      -1,   674,     5,   675,    -1,   938,    -1,   430,   676,   391,
      -1,   676,   677,   676,    -1,    26,    -1,   678,    26,    -1,
    1090,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   680,    -1,    -1,
     274,   430,   681,   682,   391,    -1,   568,   430,    26,     5,
      26,   391,    -1,   683,    -1,   682,     5,   683,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   409,    -1,   604,
      -1,   527,    -1,   479,    -1,   416,    -1,   490,    -1,   345,
      -1,   531,    -1,   455,    -1,   332,    -1,   593,    -1,    98,
      -1,  1004,    -1,    -1,   685,    -1,    -1,   274,   430,   686,
     687,   391,    -1,   688,    -1,   687,     5,   688,    -1,   683,
      -1,   431,    -1,   602,    25,    -1,   203,   925,    -1,   329,
     925,    -1,   284,   925,    -1,   337,   925,    -1,   293,   925,
      -1,   259,   925,    -1,   533,   690,    -1,   869,   344,  1090,
      -1,    -1,   289,   430,  1479,   391,   344,   691,  1109,    -1,
     104,   430,   938,     5,    25,     5,    25,   391,    -1,   406,
     430,   930,   391,   344,  1090,    -1,  1228,    -1,   192,   430,
     888,   391,   344,  1090,    -1,    -1,    -1,  1090,   589,   938,
     430,   692,   706,   391,   693,   704,    -1,    -1,    -1,    -1,
     938,   430,   694,   706,   695,   391,   696,   704,    -1,    -1,
      -1,   473,  1426,   622,  1426,   430,   697,   706,   698,   391,
     704,    -1,    -1,    -1,   938,   520,   938,   430,   699,   706,
     700,   391,   704,    -1,    -1,    -1,    -1,   365,   709,   589,
     710,   458,   673,   426,   430,   701,   706,   702,   391,   703,
     705,    -1,    -1,   344,  1109,    -1,    -1,   344,  1109,    -1,
     162,    -1,    -1,   707,    -1,   708,    -1,   707,     5,   708,
      -1,   838,    -1,    25,    -1,   938,    -1,   938,    -1,   938,
     619,   938,    -1,    -1,   534,   845,   712,   715,   719,   716,
      -1,    -1,   534,   713,   714,   717,   716,    -1,   721,    -1,
     714,   721,    -1,   723,    -1,   715,   723,    -1,   360,    -1,
      -1,    -1,   339,   718,  1489,    -1,    -1,    -1,   339,   720,
    1489,    -1,    -1,   578,   845,   722,  1489,    -1,    -1,   578,
     845,   724,  1489,    -1,   278,   935,    -1,   202,   933,    -1,
      83,   933,    -1,   168,    -1,   185,  1432,    -1,   493,   932,
      -1,    30,   727,    31,    -1,   728,    -1,   730,    -1,   729,
      -1,   728,   729,    -1,    29,    -1,   731,    -1,   730,   731,
      -1,    28,    -1,   393,    -1,    -1,    -1,   320,   734,   736,
     735,   737,    -1,   384,  1090,   624,   738,   978,  1003,   679,
      -1,  1090,   624,   738,   978,   546,  1479,  1003,   679,    -1,
      -1,   740,   191,    -1,   739,    -1,   738,     5,   739,    -1,
     938,    -1,   938,   619,   938,    -1,   938,   619,    20,    -1,
     741,    -1,   740,   741,    -1,    -1,   270,   747,   742,  1489,
      -1,    -1,   273,   748,   743,  1489,    -1,    -1,  1006,   744,
    1489,    -1,    -1,   166,   745,  1489,    -1,    -1,   163,   746,
    1489,    -1,   942,    -1,   747,     5,   942,    -1,   942,    -1,
     748,     5,   942,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   430,   838,   751,   391,
      -1,    -1,     5,   792,   625,   795,    -1,   155,    -1,   279,
      -1,    -1,   754,    -1,   755,    -1,   754,   755,    -1,    -1,
      -1,   437,   756,   758,   757,  1197,    -1,   805,    -1,  1469,
      -1,   761,    -1,   758,     5,   761,    -1,    -1,   760,   938,
      -1,   353,   759,   804,    25,    -1,   353,   759,   804,   938,
      -1,   353,   759,   804,   944,    -1,   353,   759,   804,    26,
      -1,   765,   781,    -1,    -1,   759,   353,   762,   763,    -1,
      26,    -1,    25,    -1,   944,    -1,    19,    26,    -1,   759,
      -1,   764,    -1,   765,     5,   764,    -1,    -1,   535,    -1,
      -1,   486,   458,   773,   426,   768,   623,   781,    -1,    -1,
     318,   766,   770,    26,   771,   302,   458,   772,   426,   769,
     623,   781,    -1,   430,    -1,   457,    -1,   391,    -1,   425,
      -1,    26,    -1,   774,     5,   774,     5,   774,    -1,   774,
       5,   774,    -1,   774,    -1,    26,    -1,    -1,   463,   776,
     758,   283,    -1,    -1,   260,   777,   759,   619,    20,    -1,
      -1,   334,   778,   759,   258,   430,   779,   391,    -1,   780,
      -1,   779,     5,   780,    -1,   759,    -1,   783,    -1,    -1,
      58,    -1,    -1,    -1,   784,   786,   785,   782,    -1,   767,
      -1,   775,    -1,   535,    -1,   535,   430,    26,   391,    -1,
     423,   430,    26,   391,    -1,   423,   430,    26,     5,    26,
     391,    -1,   407,    -1,   616,   759,    -1,   379,    -1,   508,
      -1,    89,    -1,   397,    -1,   397,   430,    26,   391,    -1,
     397,   430,    26,     5,    26,   391,    -1,   511,    -1,   511,
     430,    26,   391,    -1,   511,   430,    26,     5,    26,   391,
      -1,   501,    -1,   299,    -1,   537,    -1,   532,    -1,    79,
      -1,    80,    -1,   574,    -1,   357,   790,    -1,   369,   791,
      -1,   787,    -1,    32,    -1,   556,   788,   619,   789,    -1,
     759,    -1,   759,    -1,    -1,   792,   625,   795,    -1,   800,
     625,   803,    -1,    -1,   793,   794,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,
     797,    -1,    -1,   796,   794,    -1,    -1,   430,   799,   391,
      -1,    -1,   430,    26,   391,    -1,    26,    -1,    -1,   801,
     802,   798,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   453,    -1,   469,    -1,   366,   797,    -1,   802,    -1,
      -1,    14,    -1,    -1,   236,   938,   806,   616,   807,    -1,
     809,    -1,   812,    -1,   535,    -1,   535,   430,    26,   391,
      -1,   423,   430,    26,   391,    -1,   423,   430,    26,     5,
      26,   391,    -1,   407,    -1,   379,    -1,   508,    -1,   397,
      -1,   397,   430,    26,   391,    -1,   397,   430,    26,     5,
      26,   391,    -1,   511,    -1,   511,   430,    26,   391,    -1,
     511,   430,    26,     5,    26,   391,    -1,   501,    -1,   299,
      -1,   537,    -1,   532,    -1,   574,    -1,   357,   790,    -1,
     369,   791,    -1,   808,    -1,   556,   788,   619,   789,    -1,
      -1,   486,   458,   773,   426,   810,   623,   807,    -1,    -1,
     318,   766,   770,    26,   771,   302,   458,   772,   426,   811,
     623,   807,    -1,    -1,   463,   813,   815,   283,    -1,    -1,
     260,   814,   938,   619,    20,    -1,   816,    -1,   815,     5,
     816,    -1,   817,   807,    -1,   818,    -1,   817,     5,   818,
      -1,   938,    -1,    -1,   617,   929,    -1,    70,   938,    -1,
      68,    -1,   625,  1479,    -1,   625,   508,   938,   658,  1479,
      -1,   625,   508,   938,   389,    -1,    72,   938,    -1,   156,
     863,  1109,   827,    -1,   400,   863,   843,   819,   827,    -1,
     209,   935,   827,    -1,    -1,    -1,   188,   824,  1116,   625,
     938,   619,    20,   826,   679,   825,   828,    -1,    -1,   467,
     930,    -1,   679,    -1,    -1,   829,   238,    -1,   830,    -1,
     829,   830,    -1,    -1,   351,   831,  1489,    -1,    -1,   347,
     832,  1489,    -1,    -1,  1006,   833,  1489,    -1,   497,   863,
     844,   679,    -1,   497,   863,   844,   679,    65,    -1,   286,
      -1,   285,    -1,   212,    -1,   364,    -1,   173,    -1,   211,
      -1,   328,    -1,   327,    -1,   243,    -1,   170,    -1,   169,
      -1,   144,    -1,   204,    -1,   127,    -1,   143,    -1,   187,
      -1,   153,    -1,   213,    -1,   213,   845,    -1,   848,    -1,
     847,    -1,   852,    -1,   880,    -1,   838,   839,    -1,   881,
      -1,   883,    -1,   849,    -1,    19,   838,    -1,    18,   838,
      -1,   854,    -1,   862,    -1,   856,    -1,   474,    -1,   749,
      -1,   857,    -1,   858,    -1,   859,    -1,   860,    -1,   861,
      -1,    35,   838,    -1,   863,    -1,   863,   842,    -1,   845,
      -1,   482,    -1,   841,    -1,   842,     5,   841,    -1,   845,
      -1,   843,     5,   845,    -1,   845,    -1,   844,     5,   845,
      -1,   838,    -1,    18,    -1,    19,    -1,     9,   838,    -1,
     483,    -1,   427,    -1,   430,   838,   391,    -1,   442,   430,
    1406,   391,    -1,   294,   430,  1406,   391,    -1,   846,   944,
      -1,   846,    26,    -1,    25,    -1,   944,    -1,    26,    -1,
     851,    -1,  1090,    -1,  1090,   420,  1090,    -1,   850,    -1,
     433,   838,    -1,   392,   838,    -1,  1200,    -1,    -1,   506,
     853,  1200,    -1,     7,   838,    -1,     6,   838,    -1,   838,
      -1,   855,     5,   838,    -1,   622,   430,  1406,   391,    -1,
     428,   430,  1406,   391,    -1,   622,   430,   863,   855,   391,
      -1,   428,   430,   863,   855,   391,    -1,   386,    -1,   249,
      -1,    10,   838,    -1,   252,   838,    -1,    10,   838,   441,
      25,    -1,   252,   838,   441,    25,    -1,   556,   838,    -1,
     371,   838,    -1,   556,   838,   441,    25,    -1,   371,   838,
     441,    25,    -1,   390,    -1,     8,   838,    -1,    18,   838,
      -1,    19,   838,    -1,    20,   838,    -1,    21,   838,    -1,
      22,   838,    -1,    11,   838,    -1,    14,   838,    -1,   456,
     838,    -1,    12,   838,    -1,    13,   838,    -1,    17,   838,
      -1,    16,   838,    -1,    15,   838,    -1,    -1,    -1,    -1,
     938,   430,   865,   706,   866,   391,    -1,    -1,    -1,   938,
     520,   938,   430,   867,   706,   868,   391,    -1,    -1,    -1,
     537,   430,   870,   838,   871,   391,    -1,    -1,    -1,   512,
     430,   872,   838,   873,   391,    -1,    -1,    -1,   590,   430,
     874,   838,   875,   391,    -1,    -1,    -1,   581,   430,   876,
     838,   877,   391,    -1,   369,   430,   884,   391,   879,    -1,
     357,   430,    25,   391,   878,    -1,   357,   430,    26,   391,
     878,    -1,   357,   430,    26,   589,    26,   391,   878,    -1,
      -1,  1386,   625,  1387,    -1,   791,    -1,   869,    -1,   289,
     430,  1479,   391,    -1,    99,   430,   930,   391,    -1,    71,
     430,   930,   391,    -1,   406,   430,  1479,   391,    -1,   192,
     430,  1479,   391,    -1,    59,   430,  1479,   391,    -1,   882,
      -1,   864,    -1,  1382,    -1,   537,    -1,   422,   430,   838,
     391,    -1,   322,   430,   838,   391,    -1,   487,   838,    -1,
     443,   750,    -1,   838,   108,    -1,   838,   109,    -1,   838,
     110,    -1,    25,    -1,   885,    -1,    19,   885,    -1,   887,
      -1,   886,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   930,    -1,   888,     5,   930,
      -1,    -1,    -1,   595,  1090,    14,   845,   625,   845,   892,
     890,  1489,   891,   241,    -1,    -1,   571,   845,    -1,    -1,
      -1,    -1,   403,   894,   932,   895,   897,  1287,   896,  1489,
     240,    -1,    -1,     8,   863,   843,    -1,    -1,    -1,   637,
     938,   899,   753,   900,  1035,   902,   901,   907,   638,    -1,
      -1,   912,    -1,    -1,   903,    -1,   904,    -1,   903,   904,
      -1,    -1,   639,   905,  1489,    -1,    -1,   640,   906,  1489,
      -1,    -1,   908,    -1,   909,    -1,   908,   909,    -1,    -1,
     641,   910,  1489,    -1,    -1,   642,   911,  1489,    -1,   913,
     917,   324,    -1,    91,    -1,    91,   914,   546,   915,    -1,
      91,   384,   916,    -1,  1090,    -1,   914,     5,  1090,    -1,
     938,    -1,   915,     5,   938,    -1,  1090,    -1,   916,     5,
    1090,    -1,   918,    -1,   917,   918,    -1,    -1,   643,   919,
    1489,    -1,    -1,   644,   920,  1489,    -1,    -1,   663,   915,
     921,  1489,    -1,    -1,   480,   915,   922,  1489,    -1,    -1,
     624,   915,   923,  1489,    -1,   545,   931,    -1,   554,    19,
      26,    -1,   554,    -1,   500,    18,    26,    -1,   500,    -1,
      26,    -1,  1090,    -1,    25,    -1,   943,    -1,   845,    -1,
     927,     5,   927,    -1,   928,    -1,   938,    -1,   666,   430,
     938,   391,    -1,   938,   619,   666,   430,   938,   391,    -1,
     938,   458,   676,   426,    -1,   938,   619,    20,    -1,   938,
     458,   676,   426,   619,    20,    -1,   938,   619,   938,    -1,
     938,   458,   676,   426,   619,   938,    -1,   939,    -1,   939,
      -1,   939,    -1,   939,    -1,   939,    -1,   939,    -1,    -1,
     550,    26,    -1,  1488,    -1,   940,    -1,  1488,    -1,   349,
     430,   941,   391,    -1,  1093,    -1,    25,    -1,   938,    -1,
     938,   458,   676,   426,    -1,   938,   619,    20,    -1,   938,
     458,   676,   426,   619,    20,    -1,   938,   619,   938,    -1,
     938,   458,   676,   426,   619,   938,    -1,  1090,    -1,    24,
      -1,   619,    26,    -1,   547,  1471,    -1,   651,   947,    -1,
     948,    -1,   947,     5,   948,    -1,   938,    -1,   662,   947,
      -1,   653,   947,    -1,   654,  1479,    -1,   652,   935,   658,
    1479,    -1,   656,   947,    -1,   657,  1479,    -1,   655,   935,
     658,  1479,    -1,    -1,   660,   953,   843,   958,   960,   962,
     954,   956,    -1,    -1,   955,    -1,   648,    -1,   649,    -1,
      -1,   957,    -1,   344,  1090,    -1,    -1,   959,    -1,   389,
     843,    -1,    -1,   961,    -1,   659,    26,    -1,    -1,   963,
      -1,   650,    26,   964,    -1,    -1,   399,    26,    -1,    -1,
     621,   845,   575,   966,  1489,   967,   440,    -1,    -1,    -1,
     542,   968,  1489,    -1,    -1,    -1,    62,   969,   845,   575,
     970,  1489,   967,    -1,   106,   938,   430,    26,   391,    -1,
      55,   938,    -1,    75,   938,    -1,    -1,   290,  1121,   974,
     625,   482,    -1,   290,  1121,   556,   975,    -1,   976,    -1,
     975,     5,   976,    -1,   788,   619,  1378,    -1,   788,   619,
      20,    -1,    -1,   979,   324,    -1,    -1,   150,    -1,   980,
      -1,   979,   980,    -1,    -1,   270,   992,   981,  1489,    -1,
      -1,   273,   993,   982,  1489,    -1,    -1,   351,   983,  1489,
      -1,    -1,   347,   984,  1489,    -1,    -1,  1006,   985,  1489,
      -1,    -1,   305,   986,  1489,    -1,    -1,   275,   987,  1489,
      -1,    -1,    36,   988,  1489,    -1,    -1,    34,   989,  1489,
      -1,    -1,    38,   990,  1489,    -1,    -1,    37,   991,  1489,
      -1,   930,    -1,   992,     5,   930,    -1,   930,    -1,   993,
       5,   930,    -1,   314,   996,    -1,   315,   938,   658,   996,
      -1,   561,    -1,   374,    -1,   930,    -1,    -1,   664,   999,
     998,   977,    -1,   384,  1109,   978,   937,   679,    -1,  1109,
     978,   546,  1479,   937,   679,    -1,    -1,   486,  1116,   978,
     546,   938,   619,    20,   937,  1000,   679,    -1,   468,  1479,
    1002,    -1,    81,    26,    -1,    82,    26,    -1,   626,    -1,
     539,    -1,    -1,   550,    26,    -1,  1005,    -1,    43,    25,
      -1,   495,    14,    26,    -1,   495,    14,  1090,    -1,    44,
      14,    26,    -1,    44,    14,  1090,    -1,    40,    -1,    42,
      -1,    39,    -1,    41,    -1,    -1,   429,  1007,  1012,    -1,
     295,    -1,    -1,   596,  1009,  1012,    -1,   303,  1014,    -1,
     596,  1012,    -1,  1014,    -1,   430,  1013,   391,    -1,  1014,
      -1,  1013,     5,  1014,    -1,  1015,    -1,   594,    -1,   312,
      -1,   330,    -1,   304,    -1,   484,    -1,   441,    -1,   626,
      -1,   550,    -1,   539,    -1,   177,    -1,   438,    -1,   540,
      -1,   555,    -1,   519,    -1,   310,    -1,   311,    -1,    25,
      -1,   509,    -1,    -1,    -1,   598,  1018,  1114,  1019,    14,
     863,  1020,    -1,   482,    -1,   844,    -1,   219,  1090,    -1,
     208,  1090,    -1,   222,  1090,    -1,   450,  1090,   333,    -1,
     450,  1090,   385,   926,    -1,    -1,  1027,  1026,  1030,    -1,
      -1,  1028,    -1,  1029,    -1,  1028,  1029,    -1,   972,    -1,
    1034,    -1,  1050,    -1,  1036,    -1,    -1,  1031,    -1,  1033,
      -1,  1031,  1033,    -1,    66,   938,    -1,  1038,    -1,  1044,
      -1,  1056,    -1,  1210,    -1,  1220,    -1,  1077,    -1,  1469,
      -1,   898,    -1,   726,    -1,   971,    -1,   732,    -1,   726,
      -1,  1469,    -1,    -1,   726,    -1,  1469,    -1,   754,    -1,
     367,    -1,    60,    -1,    -1,    -1,    -1,    -1,  1037,  1039,
     938,   430,  1040,  1107,   391,  1041,   753,  1042,  1035,  1489,
    1043,    -1,   210,    -1,    -1,    -1,   557,  1045,   753,  1046,
    1489,   361,    -1,   177,   840,    -1,   863,    -1,   863,   843,
      -1,   356,  1390,    -1,   466,  1390,    -1,  1051,    -1,  1052,
      -1,  1051,  1052,    -1,  1053,    -1,  1034,    -1,  1049,    -1,
      -1,   405,  1054,  1055,    -1,   753,   242,    -1,   926,    -1,
      -1,    -1,    -1,   113,   938,   112,   938,   430,  1057,  1107,
     391,  1058,   753,  1059,  1035,  1489,  1043,    -1,    -1,   558,
    1061,  1076,  1067,  1062,    -1,   362,    -1,    -1,   234,  1064,
    1489,    -1,    -1,    23,  1068,  1069,  1070,   937,  1065,  1489,
      -1,    -1,    23,  1068,   937,  1066,  1489,    -1,  1063,    -1,
    1067,  1063,    -1,    -1,  1008,    -1,    25,    -1,  1090,    -1,
      -1,  1090,    -1,    25,    -1,   251,  1074,    -1,   263,  1075,
      -1,   246,  1075,    -1,   585,    -1,    25,    -1,  1090,    -1,
    1074,    -1,  1075,     5,  1074,    -1,  1090,    -1,    25,    -1,
      -1,    -1,   645,   938,  1078,   753,  1079,  1080,   646,    -1,
    1081,    -1,  1080,  1081,    -1,    -1,   647,  1082,  1489,    -1,
      -1,   624,   938,  1083,  1489,    -1,  1087,  1085,    -1,    -1,
     680,  1088,    -1,  1089,    -1,  1086,    -1,   959,    -1,   961,
      -1,   963,    -1,   955,    -1,   957,    -1,   370,   863,   843,
      -1,    -1,    65,    -1,    65,    -1,  1091,    -1,  1093,    -1,
     190,  1093,    -1,  1093,   619,    -1,  1092,  1097,    -1,  1092,
     938,   458,  1101,   426,    -1,  1092,   938,   458,  1101,   426,
     458,  1101,   426,    -1,  1098,    -1,   938,    -1,  1094,    -1,
     938,   457,  1096,   425,    -1,   938,   457,  1096,   425,    -1,
    1090,    -1,    25,    -1,    20,    -1,   938,    -1,   938,  1100,
      -1,   938,  1100,    -1,   458,  1101,   426,    -1,   458,  1101,
     426,   458,  1101,   426,    -1,  1102,    -1,  1101,     5,  1102,
      -1,   676,    -1,  1104,    -1,  1106,    -1,  1104,   619,  1105,
      -1,  1104,   619,   938,   458,  1101,   426,    -1,  1104,   619,
     938,   458,  1101,   426,   458,  1101,   426,    -1,   938,    -1,
    1095,    -1,    20,    -1,   938,    -1,   938,  1100,    -1,    -1,
    1108,    -1,  1110,    -1,  1108,     5,  1110,    -1,  1111,    -1,
    1109,     5,  1111,    -1,   938,    -1,   938,   619,   938,    -1,
    1090,    -1,  1090,   420,  1090,    -1,    25,    -1,   944,    -1,
      26,    -1,  1113,    -1,  1112,     5,  1113,    -1,  1090,    -1,
    1090,   420,  1090,    -1,  1115,    -1,  1114,     5,  1115,    -1,
    1103,    -1,  1090,    -1,  1118,    -1,  1117,     5,  1118,    -1,
    1090,  1119,    -1,    -1,   587,    -1,   538,    -1,   938,   458,
    1101,   426,    -1,  1122,    -1,  1121,     5,  1122,    -1,  1090,
      -1,  1090,   420,  1090,    -1,   254,   934,   617,   928,   579,
    1481,   684,    -1,    -1,   617,   430,   845,     5,   845,   391,
    1125,    -1,    -1,   568,   430,   845,     5,   845,   391,    -1,
     255,   938,  1124,    -1,   938,    -1,   338,   936,  1129,    -1,
    1130,    -1,   546,   845,    -1,  1131,  1132,  1137,     8,  1127,
      -1,    -1,   617,  1133,   430,   845,     5,   845,   391,    -1,
      -1,   556,   939,    -1,    -1,   350,    -1,   217,  1432,   266,
    1464,  1136,    -1,   563,   931,    -1,   563,   931,     8,   863,
     843,    -1,    -1,   616,   576,  1426,   373,  1426,    -1,   616,
     576,  1426,     5,   373,  1426,    -1,   616,  1426,     5,  1426,
      -1,    -1,   648,    -1,   649,    -1,    90,  1464,  1139,  1140,
      -1,    -1,   616,  1464,    -1,    -1,   616,   576,  1426,     8,
    1426,    -1,   576,  1426,     8,  1426,    -1,   411,  1142,    -1,
    1143,    -1,  1142,     5,  1143,    -1,   203,   925,    -1,   284,
     925,    -1,   329,   925,    -1,   337,   925,    -1,   293,   925,
      -1,   259,   925,    -1,  1010,    -1,   438,  1011,    -1,   449,
    1011,    -1,   561,  1011,    -1,   374,  1011,    -1,   550,  1011,
      -1,   548,   926,    -1,   549,   926,    -1,   400,   680,    -1,
     664,   680,    -1,   291,    -1,   195,    -1,   151,    -1,   128,
      -1,   146,    -1,   137,    -1,  1431,   413,  1147,   546,  1145,
      -1,  1090,    -1,    25,    -1,   402,  1147,    -1,   402,  1147,
       8,  1109,    -1,   939,    -1,    -1,   461,  1157,   679,   595,
    1152,  1090,  1150,   937,   679,  1149,  1153,    -1,    -1,   667,
      26,    -1,   461,  1157,   679,   344,  1090,    -1,    -1,   535,
      -1,    -1,  1154,   282,    -1,  1155,    -1,  1154,  1155,    -1,
      -1,  1006,  1156,  1489,    -1,   844,    -1,    -1,   603,   931,
    1159,  1160,    -1,    -1,   546,  1161,    -1,  1162,    -1,  1161,
       5,  1162,    -1,  1418,    -1,   482,    -1,   220,  1165,    88,
      -1,   220,  1165,   625,  1164,    -1,   220,  1165,    87,  1164,
      -1,   220,  1165,    -1,    25,    -1,   943,    -1,   938,    -1,
      -1,   478,    -1,   145,  1165,  1166,   430,   863,  1048,   391,
      -1,   193,  1165,    -1,    67,  1165,    -1,  1201,  1209,    -1,
     446,    61,    -1,   446,  1172,    -1,  1173,    -1,  1172,  1173,
      -1,    -1,   133,  1174,  1489,    -1,    -1,   199,  1175,  1489,
      -1,    -1,   228,  1176,  1489,    -1,    -1,   216,  1177,  1489,
      -1,    -1,   253,  1178,  1489,    -1,    -1,   201,  1090,  1179,
    1489,    -1,    -1,   224,  1090,  1180,  1489,    -1,  1191,    -1,
    1193,    -1,  1192,    -1,  1182,    -1,  1218,    -1,  1185,    -1,
      -1,   560,   845,  1183,   481,    -1,    -1,   481,    -1,    -1,
     569,   845,  1186,  1184,    -1,   158,    -1,   628,  1205,    -1,
     161,  1205,    -1,   160,  1205,    -1,    -1,  1188,    -1,  1189,
      -1,  1188,  1189,    -1,  1198,  1190,    -1,    -1,   617,  1205,
      -1,   518,  1187,  1197,    -1,   517,  1426,  1197,    -1,   516,
    1196,  1195,  1194,  1197,    -1,    -1,   152,   838,    -1,   152,
     838,     5,   838,    -1,   612,    -1,   613,    -1,   614,    -1,
     615,    -1,  1090,    -1,    -1,   521,    -1,  1199,    -1,  1198,
       5,  1199,    -1,   845,  1232,    -1,   608,   430,   838,   391,
    1217,    -1,    64,  1217,    -1,   495,   430,    20,   391,  1217,
      -1,   412,   430,    20,   391,  1217,    -1,   387,   430,   838,
     391,  1217,    -1,   588,   430,   838,   391,  1217,    -1,   601,
     430,   838,   391,  1217,    -1,   600,   430,   838,   391,  1217,
      -1,    -1,   460,  1202,    -1,  1203,    -1,  1202,  1203,    -1,
     227,    26,    -1,   218,    26,    -1,   301,    26,    -1,   184,
      26,    -1,   256,    26,    -1,   175,    -1,   343,    25,    -1,
     343,  1090,    -1,   176,    25,    -1,   159,    25,    -1,  1208,
      -1,  1204,  1208,    -1,  1206,   108,    -1,  1206,   110,    -1,
    1206,   109,    -1,  1206,    -1,   944,    -1,    26,    -1,    -1,
     460,  1204,    -1,   227,  1205,    -1,   218,  1205,    -1,   301,
    1205,    -1,   184,  1205,    -1,   256,  1205,    -1,   257,  1205,
      -1,   627,    25,    -1,   628,  1205,    -1,   632,    -1,   629,
      -1,   630,    -1,   631,    -1,   636,    -1,   633,    -1,   634,
      -1,   635,    -1,    76,  1205,    -1,    77,  1205,    -1,    78,
    1205,    -1,   343,    25,    -1,   176,    25,    -1,   399,    -1,
      73,    -1,    74,    -1,    -1,   513,   618,  1117,    -1,   134,
    1117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   464,  1211,
     938,   430,  1212,  1107,   391,  1213,   753,  1214,  1170,  1215,
    1171,  1216,   239,    -1,    -1,   525,   838,    -1,   515,  1219,
      -1,    -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     105,  1221,   938,   430,  1222,  1107,   391,  1223,   753,  1224,
    1227,  1225,  1171,  1226,   239,    -1,  1207,  1209,    -1,    -1,
      -1,    -1,   154,   430,    25,     5,  1229,   706,  1230,   391,
    1231,   704,    -1,    -1,   383,    -1,   383,   218,    26,    -1,
     383,   218,  1090,    -1,   606,   845,    -1,   606,   845,   344,
    1090,    -1,   606,   845,   162,    -1,   606,   845,   577,    -1,
     606,   845,   544,    -1,  1235,    -1,   172,    -1,   323,    -1,
     281,    -1,  1242,    -1,  1237,    -1,    -1,    -1,   206,  1238,
    1375,   430,  1239,  1246,   391,    -1,    -1,    -1,   131,  1240,
    1375,   430,  1241,  1246,   391,  1243,    -1,   103,  1244,   391,
      -1,    54,   939,    -1,    -1,   268,    -1,  1245,    -1,  1244,
       5,  1245,    -1,   938,   587,    -1,   938,   538,    -1,   938,
      -1,  1247,    -1,  1246,     5,  1247,    -1,  1328,    -1,  1326,
      -1,   120,   938,    -1,   179,    -1,    45,   938,  1250,    -1,
    1251,    -1,  1250,     5,  1251,    -1,  1252,    -1,  1255,    -1,
    1258,    -1,  1263,    -1,  1264,    -1,  1262,    -1,  1261,    -1,
     584,  1253,    -1,   584,   430,  1254,   391,    -1,  1247,    -1,
    1247,   663,   938,    -1,  1253,    -1,  1254,     5,  1253,    -1,
     541,  1257,    -1,   541,   430,  1256,   391,    -1,  1257,    -1,
    1256,     5,  1257,    -1,   938,    -1,   454,  1260,    -1,   454,
     430,  1259,   391,    -1,  1260,    -1,  1259,     5,  1260,    -1,
    1247,    -1,    85,    -1,    86,    -1,    84,    26,    -1,    56,
    1332,    -1,    56,   430,  1265,   391,    -1,    57,  1266,    -1,
      57,   430,  1265,   391,    -1,  1332,    -1,  1265,     5,  1332,
      -1,   938,    -1,   265,    -1,   231,    -1,   164,  1269,    -1,
     141,    -1,   129,    -1,   119,    -1,   117,    -1,   121,    -1,
     178,  1432,    -1,   230,  1268,   459,  1426,   625,  1426,    -1,
     298,   931,   459,  1426,   625,  1426,    -1,    -1,  1432,    -1,
      -1,   845,    -1,   522,   845,    -1,   229,    -1,    -1,   248,
    1273,  1375,  1276,  1274,    -1,    -1,   478,  1275,   430,  1278,
     391,    -1,  1412,    -1,    -1,   430,  1277,   391,    -1,  1378,
      -1,  1277,     5,  1378,    -1,  1279,    -1,  1278,     5,  1279,
      -1,  1418,    -1,   482,    -1,    -1,    -1,   499,  1281,  1284,
    1282,  1285,    -1,   939,    -1,  1289,   932,    -1,   932,    -1,
      -1,    -1,   553,  1286,  1112,    -1,    -1,    -1,   553,  1288,
    1112,    -1,   500,    -1,   554,    -1,   561,    -1,   374,    -1,
     341,    -1,   395,    -1,   377,   845,    -1,   350,   845,    -1,
     237,  1375,   149,   932,    -1,   237,  1375,  1348,    -1,   513,
     618,  1293,    -1,  1294,    -1,  1293,     5,  1294,    -1,  1295,
    1296,    -1,    26,    -1,  1378,    -1,    -1,   587,    -1,   538,
      -1,   276,    -1,   309,    -1,    -1,   326,    -1,   356,  1301,
    1299,    -1,  1464,    -1,    25,    -1,    -1,  1431,  1303,  1304,
      -1,  1333,    -1,  1337,    -1,  1298,    -1,  1433,    -1,  1297,
      -1,  1290,    -1,  1291,    -1,  1280,    -1,  1272,    -1,  1271,
      -1,  1402,    -1,  1448,    -1,   504,  1307,   624,  1375,   625,
    1312,  1306,    -1,    -1,   140,    -1,   167,    -1,  1308,    -1,
    1309,    -1,  1308,     5,  1309,    -1,   470,    -1,   449,    -1,
     438,    -1,   477,  1310,    -1,    -1,   430,  1311,   391,    -1,
    1378,    -1,  1311,     5,  1378,    -1,  1313,    -1,  1312,     5,
    1313,    -1,   462,    -1,  1376,    -1,   235,  1375,  1315,   616,
    1412,  1317,    -1,    -1,   430,  1316,   391,    -1,  1378,    -1,
    1316,     5,  1378,    -1,    -1,   139,    -1,   491,   430,  1351,
     391,    -1,   245,   430,  1321,   391,  1320,    -1,   296,  1322,
      -1,  1323,    -1,  1375,    -1,  1375,   430,  1323,   391,    -1,
    1378,    -1,  1323,     5,  1378,    -1,   475,   430,  1325,   391,
      -1,   258,   430,  1325,   391,    -1,  1378,    -1,  1325,     5,
    1378,    -1,  1324,    -1,  1319,    -1,  1318,    -1,   399,  1381,
      -1,   207,    -1,   938,  1367,  1329,  1330,    -1,    -1,  1327,
      -1,    -1,  1331,    -1,  1332,    -1,  1331,  1332,    -1,   372,
      -1,   157,    -1,   475,    -1,  1320,    -1,   491,   430,  1351,
     391,    -1,   118,  1334,  1336,    -1,  1335,    -1,  1376,    -1,
    1337,    -1,  1336,  1337,    -1,  1314,    -1,  1305,    -1,   447,
    1351,    -1,   368,  1340,    -1,  1417,    -1,  1340,     5,  1417,
      -1,   525,  1351,    -1,   546,  1343,    -1,  1344,    -1,  1343,
       5,  1344,    -1,  1345,    -1,   514,  1345,    -1,   514,   430,
    1346,   391,    -1,  1375,    -1,  1375,  1380,    -1,  1344,    -1,
    1346,     5,  1344,    -1,  1342,  1348,  1349,  1350,    -1,    -1,
    1341,    -1,    -1,  1339,    -1,    -1,  1338,    -1,  1352,    -1,
    1351,     6,  1352,    -1,  1353,    -1,  1352,     7,  1353,    -1,
    1354,    -1,     9,  1354,    -1,  1365,    -1,   430,  1351,   391,
      -1,   442,  1413,    -1,   294,  1413,    -1,    -1,   441,  1358,
      -1,  1419,    -1,  1422,    -1,  1418,   622,   430,  1360,   391,
      -1,  1418,   622,  1413,    -1,  1418,   428,   430,  1360,   391,
      -1,  1418,   428,  1413,    -1,  1361,    -1,  1360,     5,  1361,
      -1,  1468,    -1,  1381,    -1,    -1,     9,    -1,  1418,  1362,
     386,    -1,  1418,  1362,   249,    -1,  1418,  1364,  1418,    -1,
    1418,  1362,   388,  1418,     7,  1418,    -1,  1418,   556,  1357,
    1356,    -1,  1418,   371,  1357,  1356,    -1,  1418,  1362,    10,
    1357,  1356,    -1,    14,    -1,    17,    -1,    12,    -1,    13,
      -1,   252,    -1,    10,    -1,    16,    -1,    15,    -1,  1363,
      -1,  1359,    -1,  1355,    -1,    -1,   585,    -1,   359,    -1,
     475,    -1,  1368,    -1,  1369,    -1,  1371,    -1,   535,    -1,
     535,   430,  1372,   391,    -1,   410,   430,  1373,  1370,   391,
      -1,   471,    -1,   397,   430,  1373,  1370,   391,    -1,   511,
     430,  1373,  1370,   391,    -1,   537,    -1,   407,    -1,   379,
      -1,   357,  1388,   625,  1389,    -1,   357,    -1,   369,  1388,
     625,  1389,    -1,   369,    -1,   369,  1388,   430,    26,   391,
     625,  1389,    -1,   574,    -1,   532,    -1,   423,    -1,   423,
     430,    26,   391,    -1,   423,   430,    26,     5,    26,   391,
      -1,    -1,     5,  1374,    -1,   501,   430,  1373,   391,    -1,
     565,    -1,   299,    -1,   501,    -1,    63,    -1,    26,    -1,
      26,    -1,    26,    -1,    25,   619,   938,    -1,    25,    -1,
     938,    -1,   938,   589,   938,    -1,   938,    -1,    -1,   458,
      26,   426,    -1,   458,    26,     5,    26,   426,    -1,  1379,
      -1,   611,  1379,    -1,   938,  1377,    -1,  1375,   619,   938,
    1377,    -1,  1375,   619,    20,    -1,   938,    -1,    25,    -1,
     410,    -1,   944,    -1,    26,    -1,  1383,    -1,   395,  1385,
      -1,   395,  1384,    -1,    -1,  1388,   625,  1389,    -1,    -1,
    1386,   625,  1386,    -1,   581,    -1,   512,    -1,   590,    -1,
     552,    -1,   453,    -1,   469,    -1,   366,    -1,   366,   430,
      26,   391,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   453,    -1,   469,    -1,   366,    -1,   366,   430,    26,
     391,    -1,   581,    -1,   512,    -1,   590,    -1,   552,    -1,
     453,    -1,   469,    -1,   366,    -1,   581,    -1,   512,    -1,
     590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,    -1,
     938,    -1,    25,    -1,  1431,   502,   932,    -1,    -1,  1431,
     398,  1283,   436,   595,  1400,  1393,  1397,    -1,    -1,  1431,
     398,  1283,   436,   100,   595,  1401,  1394,  1397,    -1,    -1,
    1431,   398,  1283,   135,  1401,  1395,  1397,    -1,    -1,  1431,
     398,  1283,   136,   100,   595,  1401,  1396,  1397,    -1,    -1,
     288,    -1,   287,  1398,    -1,  1399,    -1,  1398,     5,  1399,
      -1,   938,    -1,   938,   619,   938,    -1,    25,   619,   938,
     619,   938,    -1,  1401,    -1,  1272,    -1,  1147,    -1,  1403,
      -1,  1403,  1397,    -1,    -1,    -1,   470,  1414,  1404,  1415,
    1405,  1411,  1347,  1409,    -1,   470,  1414,  1415,  1347,  1409,
      -1,  1408,    -1,  1426,    -1,   470,  1414,  1415,  1411,  1347,
    1409,    -1,    -1,   524,  1366,  1407,    -1,  1292,    -1,   331,
    1410,  1243,    -1,  1292,   331,  1410,  1243,    -1,   938,    -1,
      -1,   553,  1112,    -1,   470,  1414,  1415,  1347,    -1,   430,
     470,  1414,  1415,  1347,   391,    -1,    -1,   585,    -1,   359,
      -1,   475,    -1,  1416,    -1,  1415,     5,  1416,    -1,  1418,
      -1,  1418,   938,    -1,  1418,    -1,  1419,    -1,    19,  1419,
      -1,    18,  1419,    -1,  1420,    -1,  1468,    -1,  1413,    -1,
     611,   938,    -1,   611,   938,   619,   938,    -1,  1419,    21,
    1418,    -1,  1419,  1440,    -1,  1419,    20,  1418,    -1,  1419,
      18,  1418,    -1,  1419,    19,  1418,    -1,  1381,    -1,   483,
      -1,   427,    -1,   576,    -1,    20,    -1,    64,    -1,   588,
     430,  1366,  1418,   391,    -1,   600,   430,  1366,  1418,   391,
      -1,   601,   430,  1366,  1418,   391,    -1,   608,   430,  1366,
    1418,   391,    -1,   495,   430,  1366,  1418,   391,    -1,   938,
     430,  1421,   391,    -1,   537,   430,  1421,   391,    -1,   430,
    1418,   391,    -1,   443,   430,  1441,   391,    -1,  1418,    -1,
    1421,     5,  1418,    -1,  1381,    -1,  1431,   346,  1430,  1425,
    1407,    -1,  1431,   335,  1430,  1425,   248,  1375,  1427,    -1,
    1431,   335,  1430,  1425,  1090,    -1,    -1,   321,  1426,    -1,
      25,    -1,  1090,    -1,    -1,   430,  1428,   391,    -1,  1429,
      -1,  1428,     5,  1429,    -1,   938,    -1,    25,    -1,  1090,
      -1,    -1,   267,  1432,   595,    -1,   939,    -1,  1438,    -1,
    1437,    -1,  1434,    -1,   316,  1435,   625,  1435,    -1,   297,
    1435,   619,  1436,   625,  1436,    -1,   938,    -1,   938,    -1,
     221,   788,    -1,   292,   788,  1439,    -1,   271,    -1,   174,
      -1,    92,    -1,    93,    -1,    94,    -1,    95,    -1,    96,
      -1,    97,    -1,   395,     5,  1388,   625,  1389,    -1,  1468,
       5,  1388,   625,  1389,    -1,   395,  1388,   625,  1389,    -1,
      -1,   607,  1443,  1444,   189,    -1,  1445,    -1,  1444,  1445,
      -1,    33,    -1,  1446,    -1,  1447,    -1,   190,  1468,    -1,
     553,  1112,    -1,    -1,    -1,   477,  1375,  1449,  1452,  1450,
    1451,    -1,    -1,   149,   932,    -1,   525,  1351,    -1,    52,
    1456,   391,    14,   430,  1457,   391,    -1,    48,  1457,   391,
      -1,    49,  1457,   391,    -1,   583,  1453,    -1,    51,  1457,
      -1,    50,  1457,    -1,  1455,    -1,  1453,     5,  1455,    -1,
    1378,    -1,  1454,    14,  1458,    -1,  1454,    -1,  1456,     5,
    1454,    -1,  1458,    -1,  1457,     5,  1458,    -1,   482,    -1,
    1459,    -1,  1460,    -1,    19,  1460,    -1,    18,  1460,    -1,
    1462,    -1,  1413,    -1,   611,   938,    -1,   611,   938,   619,
     938,    -1,  1461,    -1,  1381,    -1,   483,    -1,   427,    -1,
     576,    -1,    64,    -1,  1460,    21,  1459,    -1,  1460,  1440,
      -1,  1460,    20,  1459,    -1,  1460,    18,  1459,    -1,  1460,
      19,  1459,    -1,   588,   430,  1366,  1459,   391,    -1,   600,
     430,  1366,  1459,   391,    -1,   601,   430,  1366,  1459,   391,
      -1,   608,   430,  1366,  1459,   391,    -1,   495,   430,  1366,
    1459,   391,    -1,   938,   430,  1463,   391,    -1,   537,   430,
    1463,   391,    -1,   430,  1459,   391,    -1,   443,   430,  1441,
     391,    -1,  1468,    -1,  1459,    -1,  1463,     5,  1459,    -1,
    1465,    -1,   190,  1466,    -1,  1466,    -1,  1099,    -1,   938,
      -1,  1466,   619,  1467,    -1,    25,   619,  1466,   619,  1467,
      -1,    20,    -1,  1120,    -1,   938,    -1,  1465,    -1,  1465,
     420,  1465,    -1,   126,  1470,    -1,   130,  1470,    -1,   125,
    1470,    -1,    46,    -1,   165,  1470,    -1,   123,  1470,    -1,
      47,    -1,   148,  1470,    -1,   147,  1470,    -1,   122,  1470,
      -1,   355,    -1,   620,   625,  1471,    -1,   547,  1471,    -1,
     572,    -1,   533,  1472,    -1,   938,    -1,   589,   938,    -1,
     938,    -1,    -1,    -1,   526,  1474,   845,  1475,  1489,   325,
      -1,    -1,   658,  1479,    -1,    -1,   661,    -1,   181,    -1,
     277,   933,    -1,    69,   933,    -1,   307,    -1,   306,    -1,
     308,   935,  1476,  1477,    -1,   492,  1479,  1477,    -1,   930,
      -1,  1479,     5,   930,    -1,   102,    -1,   132,   933,    -1,
     845,   566,     5,   845,   392,    -1,   508,   845,    -1,   264,
     933,    -1,   101,  1484,     8,  1485,  1483,    -1,    -1,   546,
     845,    -1,   938,    -1,   938,    -1,   247,   933,    -1,   250,
     933,   625,   845,     5,   845,    -1,   250,   933,   618,   845,
       5,   845,    -1,    27,    -1,    -1,  1491,    -1,  1492,  1197,
      -1,  1490,    -1,  1491,  1490,    -1,    -1,  1493,  1494,    -1,
     669,    -1,   670,    -1,   671,    -1,   672,    -1,   689,    -1,
     711,    -1,   725,    -1,   726,    -1,   732,    -1,   733,    -1,
     752,    -1,   820,    -1,   821,    -1,   822,    -1,   823,    -1,
     834,    -1,   835,    -1,   836,    -1,   837,    -1,   889,    -1,
     893,    -1,   924,    -1,   945,    -1,   946,    -1,   949,    -1,
     950,    -1,   951,    -1,   952,    -1,   965,    -1,   973,    -1,
     994,    -1,   995,    -1,   997,    -1,  1001,    -1,  1016,    -1,
    1017,    -1,  1021,    -1,  1022,    -1,  1023,    -1,  1024,    -1,
    1032,    -1,  1047,    -1,  1060,    -1,  1071,    -1,  1072,    -1,
    1073,    -1,  1084,    -1,  1123,    -1,  1126,    -1,  1128,    -1,
    1134,    -1,  1135,    -1,  1138,    -1,  1141,    -1,  1144,    -1,
    1146,    -1,  1148,    -1,  1151,    -1,  1158,    -1,  1163,    -1,
    1167,    -1,  1168,    -1,  1169,    -1,  1181,    -1,  1233,    -1,
    1234,    -1,  1236,    -1,  1248,    -1,  1249,    -1,  1267,    -1,
    1270,    -1,  1300,    -1,  1302,    -1,  1391,    -1,  1392,    -1,
    1423,    -1,  1424,    -1,  1442,    -1,  1469,    -1,  1473,    -1,
    1478,    -1,  1480,    -1,  1482,    -1,  1486,    -1,  1487,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   928,   928,   931,   934,   940,   946,   953,   957,   957,
     963,   986,   987,   988,   989,   990,  1004,  1005,  1006,  1007,
    1008,  1013,  1014,  1025,  1028,  1031,  1031,  1035,  1038,  1039,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,
    1055,  1056,  1057,  1058,  1059,  1060,  1061,  1064,  1065,  1068,
    1068,  1083,  1084,  1087,  1093,  1095,  1106,  1108,  1110,  1112,
    1116,  1118,  1180,  1184,  1188,  1188,  1198,  1202,  1205,  1206,
    1213,  1219,  1213,  1232,  1237,  1241,  1232,  1253,  1257,  1253,
    1265,  1270,  1265,  1289,  1296,  1300,  1288,  1326,  1326,  1330,
    1331,  1332,  1337,  1340,  1345,  1349,  1357,  1360,  1360,  1366,
    1370,  1385,  1383,  1401,  1401,  1416,  1416,  1419,  1419,  1423,
    1426,  1426,  1426,  1433,  1434,  1433,  1441,  1441,  1452,  1452,
    1471,  1474,  1477,  1480,  1483,  1486,  1499,  1504,  1504,  1505,
    1505,  1508,  1513,  1513,  1517,  1527,  1541,  1545,  1540,  1555,
    1561,  1569,  1570,  1573,  1573,  1576,  1580,  1585,  1592,  1592,
    1596,  1596,  1603,  1603,  1608,  1608,  1613,  1613,  1618,  1618,
    1631,  1632,  1640,  1641,  1658,  1661,  1664,  1667,  1670,  1673,
    1679,  1690,  1695,  1708,  1712,  1727,  1728,  1732,  1732,  1736,
    1736,  1736,  1737,  1738,  1743,  1743,  1746,  1746,  1755,  1756,
    1757,  1760,  1764,  1765,  1765,  1782,  1782,  1782,  1782,  1786,
    1793,  1794,  1797,  1797,  1800,  1800,  1809,  1806,  1822,  1822,
    1824,  1824,  1826,  1828,  1830,  1832,  1835,  1839,  1839,  1840,
    1840,  1844,  1844,  1856,  1856,  1861,  1865,  1867,  1868,  1871,
    1871,  1871,  1875,  1876,  1877,  1878,  1885,  1886,  1887,  1888,
    1891,  1892,  1893,  1894,  1898,  1903,  1908,  1912,  1915,  1919,
    1920,  1921,  1922,  1923,  1924,  1925,  1926,  1929,  1930,  1931,
    1963,  1967,  1969,  1971,  1971,  1978,  1982,  1982,  1986,  1987,
    1988,  1989,  1990,  1991,  1992,  1998,  1998,  2001,  2003,  2009,
    2011,  2017,  2025,  2025,  2028,  2029,  2030,  2031,  2032,  2033,
    2034,  2040,  2043,  2043,  2056,  2056,  2063,  2064,  2065,  2067,
    2068,  2070,  2072,  2073,  2074,  2075,  2080,  2086,  2092,  2093,
    2095,  2097,  2098,  2099,  2100,  2101,  2102,  2105,  2106,  2113,
    2121,  2121,  2129,  2126,  2141,  2141,  2143,  2143,  2151,  2151,
    2154,  2157,  2158,  2163,  2175,  2179,  2182,  2185,  2186,  2187,
    2188,  2189,  2194,  2201,  2207,  2212,  2216,  2212,  2227,  2229,
    2234,  2239,  2239,  2243,  2243,  2246,  2246,  2252,  2252,  2258,
    2258,  2274,  2277,  2291,  2293,  2295,  2297,  2299,  2301,  2303,
    2309,  2311,  2315,  2317,  2319,  2321,  2323,  2325,  2327,  2333,
    2348,  2351,  2364,  2365,  2366,  2367,  2368,  2372,  2373,  2374,
    2378,  2383,  2390,  2391,  2392,  2393,  2394,  2395,  2396,  2397,
    2398,  2399,  2400,  2407,  2407,  2412,  2412,  2415,  2421,  2429,
    2435,  2445,  2446,  2454,  2461,  2465,  2475,  2479,  2484,  2489,
    2491,  2501,  2514,  2522,  2535,  2540,  2546,  2551,  2556,  2557,
    2563,  2634,  2640,  2645,  2653,  2653,  2668,  2672,  2679,  2682,
    2690,  2701,  2711,  2717,  2726,  2731,  2739,  2742,  2745,  2750,
    2757,  2762,  2767,  2772,  2782,  2790,  2798,  2803,  2807,  2812,
    2816,  2820,  2827,  2830,  2833,  2837,  2841,  2845,  2849,  2857,
    2867,  2872,  2865,  2888,  2893,  2888,  2910,  2910,  2910,  2913,
    2913,  2913,  2917,  2917,  2917,  2921,  2921,  2921,  2925,  2931,
    2937,  2943,  2953,  2953,  2957,  2961,  2962,  2973,  2974,  2980,
    2990,  3000,  3010,  3011,  3014,  3019,  3025,  3029,  3033,  3036,
    3042,  3045,  3048,  3065,  3068,  3074,  3075,  3076,  3080,  3081,
    3082,  3083,  3084,  3086,  3087,  3088,  3090,  3091,  3095,  3096,
    3101,  3102,  3114,  3118,  3113,  3126,  3129,  3143,  3147,  3153,
    3142,  3166,  3167,  3179,  3185,  3179,  3199,  3199,  3201,  3202,
    3206,  3206,  3210,  3210,  3215,  3215,  3222,  3223,  3227,  3227,
    3231,  3231,  3236,  3236,  3243,  3247,  3248,  3249,  3254,  3254,
    3257,  3257,  3261,  3261,  3265,  3265,  3269,  3269,  3274,  3274,
    3279,  3279,  3284,  3284,  3289,  3289,  3305,  3322,  3323,  3324,
    3325,  3326,  3327,  3330,  3330,  3333,  3335,  3338,  3341,  3343,
    3344,  3345,  3347,  3349,  3351,  3353,  3357,  3364,  3366,  3372,
    3377,  3382,  3387,  3387,  3390,  3396,  3401,  3404,  3411,  3411,
    3413,  3414,  3416,  3418,  3420,  3422,  3426,  3435,  3435,  3497,
    3509,  3516,  3516,  3520,  3525,  3531,  3535,  3539,  3545,  3549,
    3553,  3559,  3559,  3567,  3568,  3572,  3572,  3576,  3577,  3580,
    3583,  3583,  3586,  3588,  3588,  3591,  3593,  3593,  3594,  3596,
    3596,  3605,  3603,  3615,  3615,  3615,  3618,  3620,  3618,  3627,
    3630,  3636,  3647,  3647,  3651,  3657,  3657,  3661,  3662,  3673,
    3674,  3676,  3678,  3683,  3683,  3687,  3686,  3693,  3692,  3698,
    3698,  3703,  3703,  3709,  3709,  3714,  3714,  3719,  3719,  3724,
    3724,  3727,  3727,  3730,  3730,  3733,  3733,  3775,  3776,  3784,
    3785,  3794,  3799,  3804,  3805,  3806,  3810,  3809,  3820,  3825,
    3830,  3830,  3846,  3852,  3853,  3854,  3855,  3858,  3858,  3861,
    3868,  3869,  3870,  3871,  3872,  3873,  3874,  3875,  3876,  3881,
    3881,  3883,  3886,  3886,  3888,  3892,  3895,  3896,  3899,  3899,
    3904,  3907,  3908,  3909,  3910,  3911,  3912,  3913,  3914,  3915,
    3916,  3917,  3918,  3919,  3920,  3921,  3922,  3923,  3927,  3945,
    3945,  3945,  3972,  3983,  3990,  3996,  4002,  4008,  4019,  4042,
    4041,  4058,  4058,  4062,  4063,  4071,  4072,  4073,  4074,  4081,
    4082,  4084,  4085,  4089,  4094,  4095,  4096,  4097,  4098,  4099,
    4100,  4101,  4102,  4103,  4104,  4107,  4107,  4109,  4109,  4109,
    4111,  4115,  4115,  4124,  4129,  4145,  4151,  4123,  4165,  4179,
    4189,  4178,  4202,  4209,  4209,  4214,  4220,  4228,  4233,  4234,
    4237,  4237,  4237,  4240,  4240,  4248,  4254,  4268,  4272,  4285,
    4267,  4303,  4303,  4317,  4328,  4327,  4339,  4335,  4352,  4349,
    4362,  4362,  4364,  4365,  4367,  4368,  4371,  4372,  4373,  4375,
    4380,  4385,  4391,  4393,  4394,  4397,  4398,  4401,  4403,  4412,
    4418,  4412,  4429,  4430,  4434,  4434,  4444,  4444,  4456,  4459,
    4462,  4465,  4469,  4473,  4474,  4475,  4476,  4477,  4481,  4486,
    4486,  4489,  4515,  4574,  4574,  4577,  4581,  4585,  4628,  4670,
    4671,  4672,  4675,  4689,  4701,  4701,  4706,  4707,  4713,  4773,
    4830,  4835,  4842,  4847,  4855,  4861,  4895,  4898,  4899,  4940,
    4983,  4984,  4988,  4989,  4993,  5046,  5050,  5053,  5059,  5070,
    5077,  5085,  5085,  5088,  5089,  5090,  5091,  5092,  5095,  5098,
    5104,  5107,  5111,  5115,  5122,  5127,  5134,  5137,  5143,  5145,
    5145,  5145,  5149,  5169,  5176,  5183,  5186,  5200,  5207,  5208,
    5211,  5212,  5216,  5222,  5227,  5233,  5234,  5239,  5243,  5243,
    5247,  5248,  5251,  5252,  5256,  5264,  5267,  5273,  5274,  5276,
    5278,  5282,  5282,  5283,  5288,  5296,  5297,  5302,  5303,  5305,
    5318,  5320,  5321,  5323,  5326,  5329,  5332,  5336,  5339,  5342,
    5346,  5350,  5354,  5357,  5361,  5364,  5365,  5366,  5369,  5372,
    5375,  5378,  5381,  5384,  5387,  5403,  5411,  5411,  5413,  5420,
    5427,  5442,  5440,  5459,  5460,  5464,  5469,  5470,  5474,  5475,
    5477,  5478,  5480,  5480,  5488,  5497,  5497,  5507,  5508,  5511,
    5512,  5515,  5519,  5533,  5538,  5543,  5548,  5558,  5558,  5562,
    5565,  5565,  5567,  5577,  5586,  5593,  5595,  5599,  5602,  5602,
    5606,  5605,  5609,  5608,  5612,  5611,  5615,  5614,  5618,  5617,
    5620,  5620,  5636,  5635,  5657,  5658,  5659,  5660,  5661,  5662,
    5665,  5665,  5671,  5671,  5674,  5674,  5684,  5685,  5686,  5693,
    5705,  5706,  5709,  5710,  5713,  5716,  5716,  5721,  5725,  5730,
    5736,  5737,  5738,  5742,  5743,  5744,  5745,  5749,  5759,  5761,
    5766,  5769,  5774,  5780,  5787,  5794,  5803,  5810,  5817,  5824,
    5831,  5840,  5840,  5842,  5842,  5845,  5846,  5847,  5848,  5849,
    5850,  5851,  5852,  5853,  5854,  5857,  5857,  5860,  5861,  5862,
    5863,  5866,  5866,  5869,  5869,  5872,  5873,  5874,  5875,  5876,
    5877,  5878,  5879,  5881,  5882,  5883,  5884,  5886,  5887,  5888,
    5889,  5891,  5892,  5893,  5894,  5895,  5896,  5897,  5898,  5902,
    5908,  5916,  5927,  5936,  5947,  5951,  5955,  5961,  5926,  5974,
    5977,  5985,  5997,  5999,  6004,  6012,  6022,  6025,  6029,  6037,
    6003,  6046,  6050,  6054,  6058,  6050,  6068,  6069,  6070,  6071,
    6076,  6078,  6081,  6085,  6088,  6095,  6100,  6101,  6102,  6107,
    6108,  6114,  6114,  6114,  6119,  6119,  6119,  6130,  6131,  6137,
    6138,  6150,  6151,  6156,  6157,  6158,  6162,  6165,  6171,  6174,
    6182,  6183,  6189,  6196,  6199,  6208,  6211,  6214,  6217,  6220,
    6223,  6226,  6233,  6236,  6243,  6246,  6252,  6255,  6262,  6265,
    6272,  6273,  6278,  6282,  6285,  6291,  6294,  6300,  6307,  6308,
    6312,  6318,  6321,  6328,  6329,  6336,  6339,  6344,  6355,  6356,
    6357,  6358,  6359,  6360,  6361,  6362,  6363,  6366,  6369,  6375,
    6375,  6381,  6381,  6392,  6405,  6415,  6415,  6420,  6420,  6424,
    6428,  6429,  6435,  6436,  6441,  6445,  6452,  6455,  6462,  6466,
    6461,  6475,  6479,  6483,  6490,  6494,  6494,  6507,  6511,  6511,
    6526,  6528,  6530,  6532,  6534,  6536,  6538,  6540,  6546,  6556,
    6563,  6568,  6569,  6573,  6575,  6576,  6579,  6580,  6581,  6584,
    6589,  6596,  6597,  6603,  6615,  6616,  6619,  6619,  6624,  6629,
    6634,  6635,  6638,  6639,  6644,  6649,  6653,  6658,  6659,  6663,
    6670,  6674,  6675,  6680,  6682,  6686,  6687,  6691,  6692,  6693,
    6694,  6698,  6699,  6704,  6705,  6710,  6711,  6716,  6717,  6722,
    6727,  6728,  6733,  6734,  6738,  6739,  6744,  6751,  6756,  6761,
    6765,  6766,  6771,  6772,  6778,  6780,  6785,  6786,  6792,  6795,
    6798,  6805,  6807,  6821,  6826,  6827,  6830,  6832,  6839,  6842,
    6848,  6852,  6856,  6860,  6863,  6870,  6877,  6882,  6886,  6887,
    6893,  6896,  6907,  6914,  6920,  6923,  6930,  6937,  6943,  6944,
    6950,  6951,  6952,  6955,  6956,  6961,  6961,  6965,  6973,  6974,
    6977,  6980,  6985,  6986,  6991,  6994,  7000,  7003,  7009,  7012,
    7018,  7021,  7028,  7029,  7058,  7059,  7064,  7072,  7077,  7080,
    7083,  7086,  7092,  7093,  7097,  7100,  7103,  7104,  7109,  7112,
    7115,  7118,  7121,  7124,  7127,  7133,  7134,  7135,  7136,  7137,
    7139,  7141,  7142,  7147,  7150,  7154,  7160,  7161,  7162,  7163,
    7175,  7176,  7177,  7181,  7182,  7187,  7189,  7190,  7191,  7193,
    7194,  7195,  7196,  7198,  7199,  7201,  7202,  7204,  7205,  7206,
    7207,  7209,  7213,  7214,  7220,  7222,  7223,  7224,  7225,  7230,
    7234,  7238,  7242,  7243,  7247,  7248,  7258,  7267,  7268,  7269,
    7273,  7276,  7281,  7286,  7291,  7299,  7303,  7307,  7308,  7309,
    7314,  7317,  7320,  7334,  7348,  7361,  7362,  7366,  7366,  7366,
    7366,  7366,  7366,  7367,  7370,  7375,  7375,  7375,  7375,  7375,
    7375,  7377,  7380,  7386,  7386,  7386,  7386,  7386,  7386,  7386,
    7387,  7387,  7387,  7387,  7387,  7387,  7387,  7389,  7390,  7393,
    7402,  7402,  7408,  7408,  7415,  7415,  7421,  7421,  7429,  7430,
    7431,  7434,  7434,  7437,  7438,  7439,  7444,  7447,  7453,  7458,
    7466,  7479,  7480,  7477,  7498,  7508,  7511,  7516,  7528,  7531,
    7535,  7538,  7539,  7545,  7548,  7549,  7558,  7567,  7572,  7573,
    7574,  7575,  7582,  7585,  7591,  7594,  7604,  7613,  7616,  7619,
    7625,  7631,  7634,  7637,  7640,  7646,  7648,  7650,  7652,  7654,
    7656,  7657,  7658,  7659,  7660,  7661,  7662,  7664,  7666,  7668,
    7670,  7672,  7674,  7676,  7677,  7682,  7683,  7690,  7693,  7702,
    7706,  7713,  7713,  7717,  7717,  7722,  7722,  7726,  7726,  7730,
    7736,  7736,  7739,  7739,  7745,  7752,  7753,  7754,  7758,  7759,
    7762,  7763,  7767,  7773,  7783,  7784,  7792,  7793,  7794,  7795,
    7796,  7797,  7801,  7802,  7803,  7807,  7807,  7819,  7820,  7824,
    7825,  7826,  7830,  7836,  7923,  7927,  7923,  7936,  7940,  7946,
    7954,  7964,  7974,  7986,  7989,  8008,  8034,  8037,  8043,  8046,
    8051,  8054,  8062,  8070,  8083,  8086,  8094,  8097,  8100,  8108,
    8112,  8115,  8118,  8121,  8125,  8126,  8127,  8128,  8129,  8135,
    8136,  8137,  8138,  8139,  8140,  8141,  8142,  8143,  8144,  8145,
    8146,  8147,  8148,  8152,  8158,  8159,  8171,  8192,  8192,  8196,
    8197,  8198,  8199,  8203,  8204,  8205,  8210,  8236,  8287,  8289,
    8291,  8293,  8297,  8302,  8304,  8307,  8309,  8311,  8315,  8318,
    8323,  8328,  8332,  8341,  8342,  8346,  8358,  8361,  8357,  8380,
    8380,  8384,  8385,  8388,  8389,  8390,  8391,  8392,  8393,  8394,
    8399,  8400,  8404,  8407,  8412,  8416,  8421,  8425,  8430,  8434,
    8437,  8441,  8444,  8449,  8453,  8464,  8470,  8470,  8471,  8472,
    8479,  8488,  8488,  8490,  8491,  8492,  8493,  8494,  8495,  8496,
    8497,  8498,  8499,  8500,  8501,  8502,  8503,  8504,  8505,  8506,
    8507,  8508,  8509,  8510,  8511,  8512,  8513,  8514,  8515,  8516,
    8517,  8518,  8519,  8520,  8521,  8522,  8523,  8524,  8525,  8526,
    8527,  8528,  8529,  8530,  8531,  8532,  8533,  8534,  8535,  8536,
    8537,  8538,  8539,  8540,  8541,  8542,  8543,  8544,  8545,  8546,
    8547,  8548,  8549,  8550,  8551,  8552,  8553,  8554,  8555,  8556,
    8557,  8558,  8559,  8560,  8561,  8562,  8563,  8564,  8565,  8566,
    8567,  8568,  8569,  8570,  8571,  8572,  8573,  8574
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
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@125", "prompt_title", 
  "put_cmd", "@126", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@127", "@128", "@129", "@130", "@131", "@132", "@133", 
  "report_cmd", "need_command", "@134", "op_lines", "skip_command", 
  "@135", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
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
       0,   256,  1653,  1654,  1655,  1569,  1609,  1564,  1500,  1584,
    1379,  1486,  1482,  1397,  1559,  1296,  1354,  1428,  1595,  1582,
    1487,  1515,  1583,  1361,  1656,  1657,  1658,  1659,  1660,  1661,
    1662,  1663,  1664,  1665,  1000,  1001,  1002,  1003,  1004,  1005,
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
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   668,   669,   670,   671,   672,   673,   673,   674,   674,
     675,   676,   676,   676,   676,   676,   677,   677,   677,   677,
     677,   678,   678,   679,   679,   681,   680,   680,   682,   682,
     683,   683,   683,   683,   683,   683,   683,   683,   683,   683,
     683,   683,   683,   683,   683,   683,   683,   684,   684,   686,
     685,   687,   687,   688,   688,   688,   688,   688,   688,   688,
     688,   688,   689,   690,   691,   690,   690,   690,   690,   690,
     692,   693,   690,   694,   695,   696,   690,   697,   698,   690,
     699,   700,   690,   701,   702,   703,   690,   704,   704,   705,
     705,   705,   706,   706,   707,   707,   708,   709,   709,   710,
     710,   712,   711,   713,   711,   714,   714,   715,   715,   716,
     717,   718,   717,   719,   720,   719,   722,   721,   724,   723,
     725,   725,   725,   725,   725,   725,   726,   727,   727,   728,
     728,   729,   730,   730,   731,   732,   734,   735,   733,   736,
     736,   737,   737,   738,   738,   739,   739,   739,   740,   740,
     742,   741,   743,   741,   744,   741,   745,   741,   746,   741,
     747,   747,   748,   748,   749,   749,   749,   749,   749,   749,
     750,   751,   751,   752,   752,   753,   753,   754,   754,   756,
     757,   755,   755,   755,   758,   758,   760,   759,   761,   761,
     761,   761,   761,   762,   761,   763,   763,   763,   763,   764,
     765,   765,   766,   766,   768,   767,   769,   767,   770,   770,
     771,   771,   772,   773,   773,   773,   774,   776,   775,   777,
     775,   778,   775,   779,   779,   780,   781,   782,   782,   784,
     785,   783,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     787,   788,   789,   790,   790,   791,   793,   792,   794,   794,
     794,   794,   794,   794,   794,   796,   795,   797,   797,   798,
     798,   799,   801,   800,   802,   802,   802,   802,   802,   802,
     802,   803,   804,   804,   806,   805,   807,   807,   807,   807,
     807,   807,   807,   807,   807,   807,   807,   807,   807,   807,
     807,   807,   807,   807,   807,   807,   807,   807,   807,   808,
     810,   809,   811,   809,   813,   812,   814,   812,   815,   815,
     816,   817,   817,   818,   819,   819,   819,   819,   819,   819,
     819,   819,   820,   821,   822,   824,   825,   823,   826,   826,
     827,   828,   828,   829,   829,   831,   830,   832,   830,   833,
     830,   834,   834,   835,   835,   835,   835,   835,   835,   835,
     835,   835,   836,   836,   836,   836,   836,   836,   836,   836,
     837,   837,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   839,   839,   839,   839,   839,   839,   839,   839,
     839,   839,   839,   840,   840,   841,   841,   842,   842,   843,
     843,   844,   844,   845,   846,   846,   847,   847,   847,   847,
     847,   847,   848,   848,   849,   849,   849,   849,   850,   850,
     851,   852,   852,   852,   853,   852,   854,   854,   855,   855,
     856,   856,   856,   856,   857,   857,   858,   858,   858,   858,
     858,   858,   858,   858,   859,   860,   861,   861,   861,   861,
     861,   861,   862,   862,   862,   862,   862,   862,   862,   863,
     865,   866,   864,   867,   868,   864,   870,   871,   869,   872,
     873,   869,   874,   875,   869,   876,   877,   869,   869,   869,
     869,   869,   878,   878,   879,   880,   880,   880,   880,   880,
     880,   880,   880,   880,   881,   881,   882,   882,   882,   882,
     883,   883,   883,   884,   884,   885,   885,   885,   886,   886,
     886,   886,   886,   886,   886,   886,   886,   886,   887,   887,
     888,   888,   890,   891,   889,   892,   892,   894,   895,   896,
     893,   897,   897,   899,   900,   898,   901,   901,   902,   902,
     903,   903,   905,   904,   906,   904,   907,   907,   908,   908,
     910,   909,   911,   909,   912,   913,   913,   913,   914,   914,
     915,   915,   916,   916,   917,   917,   919,   918,   920,   918,
     921,   918,   922,   918,   923,   918,   924,   925,   925,   925,
     925,   925,   925,   926,   926,   927,   928,   929,   930,   930,
     930,   930,   930,   930,   930,   930,   931,   932,   933,   934,
     935,   936,   937,   937,   938,   939,   940,   940,   941,   941,
     942,   942,   942,   942,   942,   942,   943,   944,   944,   945,
     946,   947,   947,   948,   949,   950,   950,   950,   951,   951,
     951,   953,   952,   954,   954,   955,   955,   956,   956,   957,
     958,   958,   959,   960,   960,   961,   962,   962,   963,   964,
     964,   966,   965,   967,   968,   967,   969,   970,   967,   971,
     971,   972,   974,   973,   973,   975,   975,   976,   976,   977,
     977,   978,   978,   979,   979,   981,   980,   982,   980,   983,
     980,   984,   980,   985,   980,   986,   980,   987,   980,   988,
     980,   989,   980,   990,   980,   991,   980,   992,   992,   993,
     993,   994,   995,   996,   996,   996,   998,   997,   999,   999,
    1000,   999,  1001,  1002,  1002,  1002,  1002,  1003,  1003,  1004,
    1005,  1005,  1005,  1005,  1005,  1005,  1005,  1005,  1005,  1007,
    1006,  1006,  1009,  1008,  1010,  1011,  1012,  1012,  1013,  1013,
    1014,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1016,  1018,
    1019,  1017,  1020,  1020,  1021,  1022,  1023,  1024,  1024,  1026,
    1025,  1027,  1027,  1028,  1028,  1029,  1029,  1029,  1029,  1030,
    1030,  1031,  1031,  1032,  1033,  1033,  1033,  1033,  1033,  1033,
    1033,  1033,  1033,  1033,  1033,  1034,  1034,  1035,  1035,  1035,
    1036,  1037,  1037,  1039,  1040,  1041,  1042,  1038,  1043,  1045,
    1046,  1044,  1047,  1048,  1048,  1049,  1049,  1050,  1051,  1051,
    1052,  1052,  1052,  1054,  1053,  1055,  1055,  1057,  1058,  1059,
    1056,  1061,  1060,  1062,  1064,  1063,  1065,  1063,  1066,  1063,
    1067,  1067,  1068,  1068,  1069,  1069,  1070,  1070,  1070,  1071,
    1072,  1073,  1074,  1074,  1074,  1075,  1075,  1076,  1076,  1078,
    1079,  1077,  1080,  1080,  1082,  1081,  1083,  1081,  1084,  1085,
    1085,  1085,  1085,  1086,  1086,  1086,  1086,  1086,  1087,  1088,
    1088,  1089,  1090,  1091,  1091,  1092,  1093,  1093,  1093,  1093,
    1093,  1093,  1094,  1095,  1096,  1096,  1097,  1097,  1098,  1099,
    1100,  1100,  1101,  1101,  1102,  1103,  1104,  1104,  1104,  1104,
    1104,  1104,  1105,  1105,  1106,  1107,  1107,  1108,  1108,  1109,
    1109,  1110,  1110,  1111,  1111,  1111,  1111,  1111,  1112,  1112,
    1113,  1113,  1114,  1114,  1115,  1116,  1117,  1117,  1118,  1119,
    1119,  1119,  1120,  1121,  1121,  1122,  1122,  1123,  1124,  1124,
    1125,  1125,  1126,  1127,  1128,  1129,  1129,  1130,  1131,  1131,
    1132,  1132,  1133,  1133,  1134,  1135,  1135,  1136,  1136,  1136,
    1136,  1137,  1137,  1137,  1138,  1139,  1139,  1140,  1140,  1140,
    1141,  1142,  1142,  1143,  1143,  1143,  1143,  1143,  1143,  1143,
    1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,  1143,
    1143,  1143,  1143,  1143,  1143,  1144,  1145,  1145,  1146,  1146,
    1147,  1149,  1148,  1150,  1150,  1151,  1152,  1152,  1153,  1153,
    1154,  1154,  1156,  1155,  1157,  1159,  1158,  1160,  1160,  1161,
    1161,  1162,  1162,  1163,  1163,  1163,  1163,  1164,  1164,  1165,
    1166,  1166,  1167,  1168,  1169,  1170,  1171,  1171,  1172,  1172,
    1174,  1173,  1175,  1173,  1176,  1173,  1177,  1173,  1178,  1173,
    1179,  1173,  1180,  1173,  1181,  1181,  1181,  1181,  1181,  1181,
    1183,  1182,  1184,  1184,  1186,  1185,  1185,  1185,  1185,  1185,
    1187,  1187,  1188,  1188,  1189,  1190,  1190,  1191,  1192,  1193,
    1194,  1194,  1194,  1195,  1195,  1195,  1195,  1196,  1197,  1197,
    1198,  1198,  1199,  1200,  1200,  1200,  1200,  1200,  1200,  1200,
    1200,  1201,  1201,  1202,  1202,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1204,  1204,  1205,  1205,  1205,
    1205,  1206,  1206,  1207,  1207,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,
    1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1208,  1209,
    1209,  1209,  1211,  1212,  1213,  1214,  1215,  1216,  1210,  1217,
    1217,  1218,  1219,  1219,  1221,  1222,  1223,  1224,  1225,  1226,
    1220,  1227,  1229,  1230,  1231,  1228,  1232,  1232,  1232,  1232,
    1233,  1233,  1233,  1233,  1233,  1234,  1235,  1235,  1235,  1236,
    1236,  1238,  1239,  1237,  1240,  1241,  1237,  1242,  1242,  1243,
    1243,  1244,  1244,  1245,  1245,  1245,  1246,  1246,  1247,  1247,
    1248,  1248,  1249,  1250,  1250,  1251,  1251,  1251,  1251,  1251,
    1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,
    1256,  1256,  1257,  1258,  1258,  1259,  1259,  1260,  1261,  1261,
    1262,  1263,  1263,  1264,  1264,  1265,  1265,  1266,  1267,  1267,
    1267,  1267,  1267,  1267,  1267,  1267,  1267,  1267,  1267,  1268,
    1268,  1269,  1269,  1270,  1271,  1273,  1272,  1275,  1274,  1274,
    1276,  1276,  1277,  1277,  1278,  1278,  1279,  1279,  1281,  1282,
    1280,  1283,  1284,  1284,  1285,  1286,  1285,  1287,  1288,  1287,
    1289,  1289,  1289,  1289,  1289,  1289,  1289,  1289,  1290,  1291,
    1292,  1293,  1293,  1294,  1295,  1295,  1296,  1296,  1296,  1297,
    1298,  1299,  1299,  1300,  1301,  1301,  1303,  1302,  1304,  1304,
    1304,  1304,  1304,  1304,  1304,  1304,  1304,  1304,  1304,  1304,
    1305,  1306,  1306,  1307,  1307,  1308,  1308,  1309,  1309,  1309,
    1309,  1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,
    1315,  1315,  1316,  1316,  1317,  1317,  1318,  1319,  1320,  1321,
    1322,  1322,  1323,  1323,  1324,  1324,  1325,  1325,  1326,  1326,
    1326,  1327,  1327,  1328,  1329,  1329,  1330,  1330,  1331,  1331,
    1332,  1332,  1332,  1332,  1332,  1333,  1334,  1335,  1336,  1336,
    1337,  1337,  1338,  1339,  1340,  1340,  1341,  1342,  1343,  1343,
    1344,  1344,  1344,  1345,  1345,  1346,  1346,  1347,  1348,  1348,
    1349,  1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,  1353,
    1354,  1354,  1355,  1355,  1356,  1356,  1357,  1358,  1359,  1359,
    1359,  1359,  1360,  1360,  1361,  1361,  1362,  1362,  1363,  1363,
    1363,  1363,  1363,  1363,  1363,  1364,  1364,  1364,  1364,  1364,
    1364,  1364,  1364,  1365,  1365,  1365,  1366,  1366,  1366,  1366,
    1367,  1367,  1367,  1368,  1368,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1369,  1369,  1369,  1369,  1369,  1369,  1369,  1369,
    1369,  1369,  1370,  1370,  1371,  1371,  1371,  1371,  1371,  1372,
    1373,  1374,  1375,  1375,  1375,  1375,  1376,  1377,  1377,  1377,
    1378,  1378,  1379,  1379,  1379,  1380,  1381,  1381,  1381,  1381,
    1381,  1382,  1383,  1384,  1384,  1385,  1385,  1386,  1386,  1386,
    1386,  1386,  1386,  1386,  1386,  1387,  1387,  1387,  1387,  1387,
    1387,  1387,  1387,  1388,  1388,  1388,  1388,  1388,  1388,  1388,
    1389,  1389,  1389,  1389,  1389,  1389,  1389,  1390,  1390,  1391,
    1393,  1392,  1394,  1392,  1395,  1392,  1396,  1392,  1397,  1397,
    1397,  1398,  1398,  1399,  1399,  1399,  1400,  1400,  1401,  1401,
    1402,  1404,  1405,  1403,  1406,  1407,  1407,  1408,  1409,  1409,
    1409,  1409,  1409,  1410,  1411,  1411,  1412,  1413,  1414,  1414,
    1414,  1414,  1415,  1415,  1416,  1416,  1417,  1418,  1418,  1418,
    1419,  1419,  1419,  1419,  1419,  1420,  1420,  1420,  1420,  1420,
    1420,  1420,  1420,  1420,  1420,  1420,  1420,  1420,  1420,  1420,
    1420,  1420,  1420,  1420,  1420,  1421,  1421,  1422,  1423,  1424,
    1424,  1425,  1425,  1426,  1426,  1427,  1427,  1428,  1428,  1429,
    1430,  1430,  1431,  1431,  1432,  1433,  1433,  1433,  1434,  1434,
    1435,  1436,  1437,  1438,  1439,  1439,  1440,  1440,  1440,  1440,
    1440,  1440,  1441,  1441,  1441,  1443,  1442,  1444,  1444,  1445,
    1445,  1445,  1446,  1447,  1449,  1450,  1448,  1451,  1451,  1451,
    1452,  1452,  1452,  1452,  1452,  1452,  1453,  1453,  1454,  1455,
    1456,  1456,  1457,  1457,  1458,  1458,  1459,  1459,  1459,  1460,
    1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1460,  1461,
    1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,
    1461,  1461,  1461,  1462,  1463,  1463,  1464,  1465,  1465,  1466,
    1466,  1466,  1466,  1467,  1467,  1467,  1468,  1468,  1469,  1469,
    1469,  1469,  1469,  1469,  1469,  1469,  1469,  1469,  1470,  1470,
    1470,  1470,  1470,  1471,  1471,  1472,  1474,  1475,  1473,  1476,
    1476,  1477,  1477,  1478,  1478,  1478,  1478,  1478,  1478,  1478,
    1479,  1479,  1480,  1480,  1481,  1481,  1482,  1482,  1483,  1483,
    1484,  1485,  1486,  1487,  1487,  1488,  1489,  1489,  1490,  1491,
    1491,  1493,  1492,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494,
    1494,  1494,  1494,  1494,  1494,  1494,  1494,  1494
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
       0,     6,     2,     1,     2,     2,     2,     1,     1,     2,
       1,     1,     1,     0,     3,     2,     1,     0,     0,     0,
      14,     0,     5,     1,     0,     3,     0,     7,     0,     5,
       1,     2,     0,     1,     1,     1,     0,     1,     1,     2,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     0,
       0,     7,     1,     2,     0,     3,     0,     4,     2,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     0,
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
       1,     0,     0,     7,     0,     0,     8,     3,     2,     0,
       1,     1,     3,     2,     2,     1,     1,     3,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     1,     3,     1,     3,     2,     4,
       1,     3,     1,     2,     4,     1,     3,     1,     1,     1,
       2,     2,     4,     2,     4,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     6,     6,     0,
       1,     0,     1,     2,     1,     0,     5,     0,     5,     1,
       0,     3,     1,     3,     1,     3,     1,     1,     0,     0,
       5,     1,     2,     1,     0,     0,     3,     0,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       3,     1,     3,     2,     1,     1,     0,     1,     1,     1,
       1,     0,     1,     3,     1,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     0,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     0,     3,     1,     3,     1,     3,     1,     1,     6,
       0,     3,     1,     3,     0,     1,     4,     5,     2,     1,
       1,     4,     1,     3,     4,     4,     1,     3,     1,     1,
       1,     2,     1,     4,     0,     1,     0,     1,     1,     2,
       1,     1,     1,     1,     4,     3,     1,     1,     1,     2,
       1,     1,     2,     2,     1,     3,     2,     2,     1,     3,
       1,     2,     4,     1,     2,     1,     3,     4,     0,     1,
       0,     1,     0,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     2,     2,     0,     2,     1,     1,     5,     3,
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
       1,     1,     1,     3,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     2,     4,     3,     2,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     3,     1,     5,     7,
       5,     0,     2,     1,     1,     0,     3,     1,     3,     1,
       1,     1,     0,     3,     1,     1,     1,     1,     4,     6,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     4,     0,     4,     1,     2,     1,
       1,     1,     2,     2,     0,     0,     6,     0,     2,     2,
       7,     3,     3,     2,     2,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     2,     1,
       1,     2,     4,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     3,     3,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     1,     3,     1,     2,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     3,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     2,     1,     3,
       2,     1,     2,     1,     2,     1,     0,     0,     6,     0,
       2,     0,     1,     1,     2,     2,     1,     1,     4,     3,
       1,     3,     1,     2,     5,     2,     2,     5,     0,     2,
       1,     1,     2,     6,     6,     1,     0,     1,     2,     1,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     781,     0,  1761,  1764,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   833,   179,     0,   805,   810,
     177,   182,   785,     0,   779,   782,   783,   786,   788,   832,
     787,   827,   828,   830,   183,   134,   131,     0,   127,   129,
     128,   132,  1805,   671,   614,  1768,     0,     0,  1771,     0,
    1767,  1763,  1760,  1758,  1759,  1766,  1765,  1762,   294,  1568,
    1567,   825,   175,   186,   826,   178,   183,     1,   789,   784,
     831,   829,   806,   126,   130,   133,  1775,  1772,     0,  1773,
    1770,     0,     0,   593,     0,     0,   176,   836,   900,   594,
     834,   626,   892,     0,   893,   901,   899,   186,   180,   199,
       0,   184,   200,   229,     0,   812,  1184,     0,     0,   811,
     135,  1172,   819,     0,     0,   802,   804,   801,   803,   780,
     790,   791,   813,   794,   795,   796,   799,   797,   798,   800,
    1774,  1769,     0,   894,   835,     0,     0,   908,   906,   907,
     896,   895,   292,   186,  1108,   193,   187,   186,   192,   226,
       0,   670,     0,     0,     0,     0,   175,   543,   869,   792,
       0,   326,   312,   202,   263,   282,   303,   305,   302,     0,
     324,     0,   311,   304,   308,   314,   298,   313,   186,   315,
     295,   318,   296,   297,   905,   904,     0,    21,    22,    13,
       0,   914,     0,    15,     0,   912,     0,   293,     0,   185,
    1109,   181,     0,   199,   201,   259,   253,   254,   242,   219,
     250,   202,   221,   263,   282,   240,   243,   238,     0,   217,
       0,   249,   241,   246,   252,   234,   251,   186,   255,   186,
     232,   233,   230,   258,     0,     0,     0,     0,   820,   175,
     175,     0,     0,   203,     0,   316,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,   902,
       0,    16,    17,    18,    19,    20,     0,    14,     0,   910,
       0,   627,   188,   191,     0,   189,   190,     0,   196,   195,
     194,   197,   186,     0,   186,   256,   257,     0,     0,   186,
       0,     0,     0,     0,   239,   227,  1185,     0,     0,  1173,
    1811,   544,   870,   814,     0,   208,   209,     0,   275,   277,
     272,   273,   269,   271,   268,   270,   267,     0,   277,   288,
     289,   285,   287,   284,   286,   279,     0,     0,     0,   328,
       0,   331,   333,   216,     0,   215,     0,     0,   186,    11,
      12,   913,     0,   897,   628,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   228,   231,   925,   669,
     837,   925,     0,  1809,  1811,  1108,  1662,   807,     0,   925,
       0,     0,   264,     0,     0,   274,   291,   265,   290,     0,
     283,     0,   306,     0,   300,     0,   325,     0,   330,   320,
       0,     0,   309,   299,   262,   319,     0,     0,     0,     0,
       0,     0,   244,     0,   236,   218,   204,     0,   247,   235,
     260,   931,     0,   926,   927,   925,     0,   821,  1810,  1808,
       0,     0,     0,     0,     0,     0,     0,     0,  1792,     0,
    1274,  1273,     0,  1275,     0,   376,  1272,  1214,     0,     5,
    1271,   377,   374,     0,   379,   173,   469,  1086,     0,     0,
    1281,   123,   373,   372,  1206,   367,   469,     0,  1231,  1783,
       0,   378,   345,     0,     3,     2,     0,   375,  1211,     0,
       0,   368,   365,   380,     0,     0,     0,     0,  1279,  1269,
     371,     0,     0,     0,     0,     0,     0,     0,     0,  1268,
       0,     0,     0,   174,  1208,   364,   363,     0,     0,  1787,
    1786,     0,     0,     0,   136,  1207,   370,   369,     0,     0,
     366,   469,   469,     0,   537,     0,     0,     0,     0,     0,
       0,   469,   768,  1182,     0,     0,  1090,     0,  1776,     0,
     103,     0,     0,   841,     0,     0,     0,     0,   769,     0,
       0,  1685,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,     0,  1813,  1814,  1815,  1816,  1817,  1818,
    1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,
    1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,
    1859,   879,  1860,  1861,  1862,  1863,  1864,  1865,  1866,  1867,
    1868,  1869,  1870,  1871,  1872,  1873,  1874,  1875,  1876,  1077,
    1079,  1074,  1076,  1075,  1078,  1877,  1878,  1205,  1879,  1210,
    1209,  1880,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,
    1889,  1336,  1890,  1891,  1892,  1893,  1894,  1895,  1896,  1897,
    1812,   808,   548,   809,     0,   874,     0,   872,     0,   327,
     210,   211,     0,   276,   281,     0,     0,     0,     0,   329,
     332,     0,   214,     0,   911,     0,   220,     0,   186,     0,
       0,     0,     0,     0,  1186,     0,     0,  1174,     0,     0,
    1218,   615,   616,   793,  1049,  1054,  1785,   608,   122,     0,
       0,  1750,  1749,   985,  1746,  1748,  1800,     0,  1225,     0,
    1221,  1230,     7,     0,     6,     0,  1793,  1050,     0,  1142,
    1141,  1089,  1140,  1088,     0,     0,     0,   424,   426,     0,
    1179,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1535,     0,     0,     0,   418,     0,     0,     0,     0,
     417,     0,     0,   434,     0,   505,     0,     0,     0,     0,
       0,     0,   413,  1282,     0,   383,   382,   389,   430,   427,
     384,   503,   495,   385,   387,   502,   388,   900,   425,   428,
     433,  1270,   504,   822,   403,  1664,  1276,   124,     0,  1053,
     121,     0,   775,    23,   610,   381,     0,   774,  1046,   776,
       0,  1280,   863,   862,   865,   861,   864,  1802,     0,   859,
       0,   609,   958,   860,  1796,     0,  1784,   120,   955,   672,
     953,     0,   606,  1779,   714,   713,     0,   715,   598,   711,
       0,     0,   968,   611,  1335,  1331,  1334,     0,     0,  1020,
    1018,     0,  1012,  1014,  1013,  1011,  1010,     0,     0,     0,
    1009,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   999,   990,   991,     0,  1034,   411,
      23,  1790,     0,  1781,   125,   607,     0,  1017,  1016,  1183,
    1181,  1107,     0,  1653,  1654,  1108,  1196,  1108,  1091,  1092,
    1095,  1110,  1283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,   900,     0,    68,     0,   101,   586,
     629,     0,  1080,   975,  1084,     0,     0,  1035,  1200,     0,
       0,  1087,   633,   630,   631,     0,   635,   636,     0,   638,
     639,     0,   634,   935,   937,     0,     0,   936,   716,   933,
     681,   929,   891,     0,     0,     0,     0,   645,   646,     0,
       0,   889,   886,   887,   883,   884,   885,   878,   882,   881,
       0,     0,     0,     0,     0,     0,   552,   554,   546,   549,
     550,   876,  1811,   871,   873,   815,     0,   278,   280,   307,
     301,     0,     0,   310,   898,     0,   225,     0,   223,   245,
     237,   229,   248,   932,   175,   928,   838,   175,     0,     0,
       0,  1258,  1259,     0,     0,     0,  1232,  1233,  1235,  1236,
    1237,  1241,  1240,  1238,  1239,     0,     0,  1747,   909,     0,
     987,     0,     0,  1224,  1223,     0,  1217,     0,  1513,  1514,
       0,  1051,     0,    23,  1137,  1139,  1138,   416,   391,   390,
       0,     0,  1114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,  1543,  1541,  1542,  1538,  1540,  1537,  1539,
    1531,     0,     0,     0,     0,     0,   431,     0,     0,   509,
     508,     0,     0,   479,   476,   485,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   510,   511,   512,   445,     0,     0,
     444,   454,     0,     0,   395,     0,     0,   396,   386,   392,
     394,   397,   398,   399,   400,   401,   393,   423,   422,   470,
       0,     0,   406,   407,   404,   405,   945,     0,     0,   350,
      24,   344,     0,     0,  1043,     0,     0,     0,     0,     0,
       0,     0,   962,  1663,     0,     0,   186,     0,     0,     0,
    1781,     0,     0,     0,     0,     0,   137,     0,     0,   972,
     964,   965,   970,  1332,  1333,   888,   409,   334,     0,   538,
     591,   590,   588,   993,   592,   998,   994,   997,   767,   760,
     754,   765,   766,   752,   753,   761,   756,   755,   764,   759,
     762,   758,   763,   751,   757,   744,   750,   995,   996,     0,
    1003,  1007,  1000,  1001,  1005,  1006,  1004,  1002,  1008,     0,
     777,     0,     0,     0,     0,     0,     0,   726,   725,   722,
    1782,  1789,    23,  1103,  1104,  1105,  1106,  1100,  1098,  1197,
    1112,  1097,  1093,     0,     0,  1094,  1777,     0,     0,     0,
       0,    97,     0,    98,     0,     0,     0,    73,     0,     0,
       0,   110,   105,     0,   868,     0,   867,     0,   469,  1082,
       0,   920,   921,   944,   915,   916,   770,   942,  1037,  1202,
       0,  1204,  1203,  1689,     0,     0,     0,  1687,  1690,  1691,
     661,     0,     0,     0,   650,   681,   681,   679,     0,     0,
     682,     0,    25,   649,   652,     0,   659,   655,   890,   880,
    1660,  1661,  1651,  1651,  1301,     0,     0,  1569,     0,   186,
    1284,     0,     0,  1285,  1329,   186,     0,  1330,     0,  1608,
       0,  1298,     0,  1347,  1346,  1345,  1343,  1344,  1342,  1340,
    1337,  1411,  1410,  1338,  1339,  1348,  1578,  1341,  1667,  1666,
    1665,  1349,  1811,  1811,   565,   556,   547,     0,   551,  1811,
     875,   175,     0,   321,   213,     0,   186,   222,   205,  1187,
     175,  1175,  1401,     0,  1400,     0,  1402,     0,  1403,  1261,
       0,  1267,  1263,  1260,     0,     0,     0,     0,     0,     0,
    1257,  1253,  1390,  1389,  1388,  1229,  1228,     0,  1252,  1248,
       0,  1244,  1242,     0,   619,     0,   618,     0,   986,     0,
       0,   984,  1753,  1755,  1754,  1751,  1801,  1798,  1222,     0,
       0,     0,  1215,   469,   342,     0,  1180,     0,     0,     0,
       0,  1608,     0,     0,     0,     0,     0,   527,   513,   518,
       0,   514,   517,   516,     0,     0,     0,     0,     0,     0,
     419,     0,   171,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,   437,   436,   455,   446,   461,   464,   465,
     462,   468,   467,   466,   456,   457,   458,   459,   460,   402,
     447,   451,   469,   463,   450,   469,    92,     0,   429,     0,
       0,  1212,   977,  1047,  1048,  1045,  1044,     0,   866,     0,
       0,   595,     0,     0,     0,   956,   954,     0,   674,   675,
       0,     0,  1780,  1788,     0,     0,   602,     0,   604,   712,
       0,   141,     0,   966,   973,     0,     0,   981,     0,   337,
       0,     0,     0,     0,    23,  1019,   541,     0,     0,     0,
     745,   746,   992,   778,   412,     0,  1026,  1791,   723,   724,
     361,     0,  1108,     0,  1111,  1096,  1811,     0,     0,     0,
     530,     0,     0,     0,     0,    63,    92,     0,     0,   116,
     111,     0,   106,     0,   113,   107,   852,   844,   850,     0,
    1081,     0,  1083,  1085,     0,     0,   924,     0,     0,     0,
       0,  1036,  1201,  1756,  1692,   940,  1693,   938,  1686,  1688,
    1811,   632,   637,   640,   653,   651,   612,     0,   701,   699,
     705,   703,     0,     0,   697,   741,   695,   691,   689,   739,
     717,     0,   683,   693,   934,   930,     0,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,  1516,     0,
    1406,  1407,  1672,  1370,  1428,     0,     0,  1670,     0,     0,
    1610,  1611,  1609,  1591,  1694,     0,  1353,  1359,  1358,  1357,
    1361,     0,  1354,  1355,     0,  1579,  1590,   553,   555,     0,
       0,   568,   560,   562,     0,   557,   558,     0,     0,   576,
     578,     0,     0,   574,   877,   816,   212,     0,     0,   224,
    1143,   839,  1121,  1378,  1380,     0,  1265,     0,     0,     0,
       0,     0,  1255,     0,     0,  1508,  1506,  1493,  1495,  1491,
       0,  1490,     0,  1499,  1486,  1507,     0,  1498,  1483,  1489,
    1505,  1497,  1394,  1480,  1481,  1482,     0,  1250,  1246,     0,
       0,  1234,   617,     0,     0,     0,     0,     0,  1797,     4,
       8,    10,  1512,  1515,     0,   469,   501,   498,   497,   500,
     496,     0,   421,   507,   492,   492,     0,   515,     0,   519,
       0,   282,  1179,     0,  1536,   499,  1179,   506,   420,   266,
       0,  1179,   480,   477,   486,  1179,   483,  1179,  1179,  1179,
       0,     0,     0,     0,     0,     0,     0,     0,   471,    93,
      94,    96,   473,   408,     0,     0,     0,   974,     0,     0,
       0,     0,     0,     0,     0,   186,   673,     0,   599,   601,
       0,     0,   158,   156,     0,     0,   138,     0,   148,   154,
     681,   143,   145,     0,   971,   982,   983,     0,   410,   336,
     341,   597,   335,     0,   338,   343,   469,  1307,   589,   587,
       0,   748,  1025,  1027,     0,   362,  1101,  1099,  1198,  1199,
       0,     0,  1192,     0,     0,     0,     0,    99,     0,     0,
      74,    80,    70,  1811,  1811,   109,   104,   118,   114,     0,
     108,   742,   853,   612,  1811,   843,   842,   851,   976,     0,
       0,   922,   923,   917,   943,   469,     0,     0,  1634,  1526,
    1529,  1635,  1533,  1527,  1632,     0,     0,  1042,  1631,     0,
       0,  1633,     0,     0,     0,     0,     0,  1750,  1528,  1038,
    1039,  1630,  1530,  1622,  1041,  1617,  1620,  1621,     0,     0,
       0,   663,   656,   654,     0,    23,     0,  1811,  1811,  1811,
    1811,   707,   685,   709,   687,  1811,  1811,  1811,  1811,     0,
     680,   684,  1811,   612,   737,   735,   738,   736,     0,     0,
      45,    43,    40,    34,    38,    42,    37,    30,    39,     0,
      33,    36,    31,    41,    32,    44,    35,     0,    28,    46,
     729,     0,   660,  1652,     0,  1650,  1608,  1648,  1595,  1596,
    1588,  1574,  1589,     0,     0,     0,  1015,  1405,  1408,     0,
       0,     0,     0,  1429,  1319,  1290,  1675,  1674,  1673,     0,
       0,     0,     0,  1314,     0,  1313,     0,  1315,  1310,  1311,
    1312,  1303,  1299,     0,     0,  1360,     0,     0,     0,  1583,
    1580,  1581,   567,   572,     0,     0,  1811,  1811,   545,   559,
     582,   570,   584,  1811,  1811,   580,   564,   575,   807,   322,
     206,     0,  1169,  1188,   807,     0,  1176,  1169,     0,     0,
    1262,     0,     0,     0,     0,     0,  1434,  1436,  1438,  1475,
    1474,  1473,  1440,  1456,  1264,     0,  1517,     0,  1379,     0,
    1382,  1520,     0,  1386,     0,  1254,     0,     0,  1559,  1557,
    1558,  1554,  1556,  1553,  1555,     0,     0,     0,     0,     0,
       0,     0,     0,  1392,     0,  1395,  1396,     0,  1249,     0,
    1243,  1245,  1752,     0,     0,     0,  1799,     0,     0,  1226,
     823,     0,     0,  1612,  1614,   489,     0,   490,     0,   529,
       0,   526,   523,   494,   488,  1117,  1544,  1116,     0,   170,
    1115,     0,     0,     0,  1118,     0,  1120,  1119,  1113,   448,
     449,   453,   438,     0,   441,   452,     0,   440,     0,     0,
      92,     0,     0,     0,     0,  1277,  1804,  1803,   596,     0,
       0,    47,     0,   678,   677,   676,  1278,     0,     0,   681,
    1811,  1811,   150,   620,   160,   152,   162,   142,   149,  1811,
       0,     0,     0,     0,     0,     0,     0,  1308,   539,     0,
     747,  1023,     0,  1778,     0,    92,   531,     0,    64,     0,
       0,     0,    77,     0,    92,    92,   117,   112,  1811,  1811,
     102,     0,   854,   848,   856,   855,   845,   535,   903,     0,
       0,  1619,  1618,  1532,     0,  1608,     0,     0,  1476,     0,
    1476,  1476,  1476,  1476,  1623,     0,     0,     0,     0,     0,
       0,  1676,  1677,  1678,  1679,  1680,  1681,  1626,  1757,   941,
     939,   666,   664,     0,   643,   657,   613,   718,     0,   702,
     700,   706,   704,     0,  1811,     0,  1811,   698,   696,   692,
     690,   740,   694,    23,   730,     0,     0,     0,    26,     0,
    1655,     0,  1578,     0,     0,  1587,  1570,  1586,  1409,     0,
    1372,     0,  1318,  1416,     0,     0,  1671,     0,  1668,  1592,
       0,     0,     0,     0,     0,     0,  1695,  1317,  1316,  1304,
    1302,     0,  1363,     0,  1356,     0,     0,     0,     0,   569,
     566,   561,   563,     0,  1811,  1811,   577,   579,  1811,  1811,
       0,     0,  1167,  1168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1166,     0,     0,  1154,  1155,
    1156,  1153,  1158,  1159,  1160,  1157,  1144,  1135,     0,     0,
    1191,     0,  1811,     0,  1130,     0,     0,     0,     0,     0,
       0,     0,  1122,  1123,     0,  1055,     0,  1266,  1439,     0,
    1443,     0,  1456,  1442,     0,  1404,     0,  1457,  1470,  1467,
    1468,  1465,  1472,  1471,  1466,  1469,     0,     0,     0,     0,
       0,     0,  1521,     0,  1522,     0,     0,     0,     0,  1385,
    1256,  1384,  1376,     0,     0,     0,  1510,  1502,  1502,     0,
       0,  1502,  1509,     0,  1526,  1391,  1393,  1397,  1398,  1251,
    1247,   989,     0,   952,     9,     0,  1219,   824,  1052,     0,
       0,  1428,  1598,  1615,     0,   492,   520,     0,   275,   481,
     478,   487,   484,     0,   443,   442,   472,    95,   474,   348,
    1213,     0,     0,  1795,     0,     0,   957,    48,     0,   603,
     605,   600,   727,   159,   157,     0,  1811,     0,     0,     0,
    1811,   155,   144,     0,   147,   146,     0,   963,   967,   340,
       0,   542,     0,  1811,   749,     0,   612,  1102,     0,  1193,
      69,     0,     0,   100,    67,    92,    75,    81,     0,   119,
     115,   743,  1811,   858,   612,   857,     0,   532,     0,   772,
     773,   771,     0,     0,  1643,     0,     0,     0,  1478,  1479,
    1477,     0,  1645,     0,     0,     0,     0,     0,     0,     0,
    1040,  1628,  1629,  1627,  1625,     0,  1811,   662,   647,   644,
       0,   708,   686,   710,   688,   719,   733,   734,   731,   732,
      29,    27,     0,  1649,  1604,  1575,  1576,  1572,  1578,     0,
    1371,  1608,  1374,     0,  1292,  1287,  1286,  1289,     0,  1604,
       0,     0,  1728,  1726,     0,     0,  1714,  1725,     0,     0,
    1727,     0,     0,     0,     0,     0,  1750,  1724,  1720,     0,
    1712,  1715,  1716,  1723,  1719,  1743,     0,  1705,  1704,  1708,
    1710,     0,  1703,     0,  1706,  1697,  1305,  1300,     0,  1362,
       0,     0,  1584,  1582,   573,   571,   583,   585,   581,     0,
       0,   229,  1161,  1162,  1163,  1165,  1148,  1146,  1145,  1149,
    1150,  1147,  1164,  1151,  1152,  1136,   949,  1171,   946,     0,
       0,  1189,     0,  1134,  1133,  1128,  1126,  1125,  1129,  1127,
    1131,  1132,  1124,  1177,  1381,  1441,  1435,  1437,  1444,  1446,
       0,  1451,  1444,     0,  1449,     0,  1459,  1458,     0,  1460,
       0,  1377,  1383,  1524,  1517,  1387,  1566,  1564,  1565,  1561,
    1563,  1560,  1562,  1492,     0,  1494,     0,     0,     0,     0,
    1500,  1504,     0,  1484,  1399,   988,  1227,  1220,  1216,  1613,
       0,  1417,  1418,  1420,  1423,  1430,     0,     0,  1476,  1600,
    1594,  1551,  1549,  1550,  1546,  1548,  1545,  1547,   493,   491,
       0,   525,   524,   172,   439,     0,     0,    23,     0,     0,
     980,     0,    49,   960,     0,    23,   161,   151,     0,   622,
     624,   163,   153,   727,     0,   339,  1309,     0,  1024,    23,
       0,     0,    65,     0,    78,    87,     0,    71,   849,   846,
     536,  1811,   918,  1534,     0,     0,     0,  1644,     0,     0,
       0,  1642,     0,     0,     0,     0,  1624,  1641,     0,   665,
     642,   648,   612,  1659,     0,  1657,     0,     0,  1578,  1578,
    1571,  1373,     0,  1375,  1369,     0,  1291,     0,  1669,     0,
    1718,  1717,     0,     0,  1476,     0,  1476,  1476,  1476,  1476,
    1721,     0,     0,  1701,     0,     0,     0,     0,  1730,  1702,
       0,     0,     0,     0,     0,     0,  1696,     0,  1364,  1367,
    1351,  1365,  1368,     0,   818,   817,   323,   207,   951,   950,
     948,     0,  1170,  1056,  1060,  1062,     0,  1066,     0,  1064,
    1068,  1057,  1058,     0,   840,     0,     0,  1463,     0,  1452,
    1455,  1454,  1462,     0,  1444,     0,     0,  1518,  1523,     0,
    1511,  1503,  1487,  1485,     0,  1488,     0,  1421,     0,  1525,
    1424,     0,  1431,  1432,  1603,  1219,     0,     0,     0,     0,
     522,   521,   475,   349,   346,     0,   978,     0,     0,     0,
     959,   728,   139,   621,    23,   969,   540,  1021,    66,  1194,
      83,     0,     0,    76,    87,    87,  1811,   533,     0,     0,
       0,     0,     0,  1640,  1646,  1636,  1637,  1638,  1639,   667,
     720,     0,  1656,  1605,  1598,  1577,  1573,     0,  1293,     0,
    1598,  1741,     0,     0,  1744,     0,     0,     0,     0,     0,
       0,     0,  1713,  1732,  1733,  1731,  1729,  1711,     0,  1707,
    1709,  1698,  1699,  1306,     0,  1352,  1350,  1585,   947,  1811,
    1811,  1070,  1811,  1072,  1811,  1811,  1059,  1190,  1178,  1445,
    1647,  1447,     0,  1450,  1448,  1464,     0,     0,     0,  1501,
    1425,     0,  1419,  1413,  1414,  1616,     0,  1433,  1427,  1601,
    1324,  1320,  1321,  1326,  1325,  1599,  1219,     0,   351,   979,
    1794,     0,     0,     0,     0,     0,     0,    54,     0,    53,
       0,    51,     0,     0,   140,  1028,    87,    92,    87,    88,
      82,    72,   847,     0,     0,  1607,     0,  1684,     0,  1811,
      23,  1658,  1597,  1606,  1297,     0,  1294,  1296,  1593,  1742,
       0,     0,  1740,     0,     0,     0,     0,  1722,  1739,     0,
    1366,  1061,  1063,  1811,  1067,  1811,  1065,  1069,  1453,  1461,
    1519,  1496,     0,  1422,     0,  1412,     0,  1328,  1327,  1323,
    1602,  1552,   357,   355,   347,     0,   353,   359,    56,    61,
      58,    60,    57,    59,    55,     0,    50,     0,   623,   625,
    1032,  1022,     0,  1030,  1195,    84,    79,   534,   919,  1682,
    1683,   663,   721,     0,  1288,  1738,  1745,  1734,  1735,  1736,
    1737,     0,  1071,  1073,  1426,  1415,  1322,  1811,  1811,   352,
     354,  1811,    52,     0,  1811,  1029,  1031,     0,   668,  1295,
    1700,   358,   356,   360,     0,  1033,    85,   961,    89,    91,
       0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   554,   555,   556,   557,   713,  1739,  1740,   191,   266,
     192,  1139,  1140,  1627,  1967,  3029,  2466,  2467,  2908,  3030,
    3031,   558,   902,  2501,  2205,  2925,  1566,  2203,  2765,  2505,
    2921,  2204,  2766,  3037,  3147,  3158,  2923,  3161,  1788,  1789,
    1790,  1252,  1856,   559,  1263,   907,  1261,  1574,  1866,  1571,
    1864,  1869,  2209,  1262,  1863,  1575,  2208,   560,    18,    37,
      38,    39,    40,    41,   116,   563,   831,  1521,  1166,  1816,
    1820,  1821,  1817,  1818,  2476,  2480,  2179,  2171,  2170,  2172,
    2175,  1117,  1069,  1770,   564,    85,    86,    20,    63,   144,
      98,   257,   100,   101,   202,   280,   102,   103,   244,   230,
     681,  2331,   307,   662,  1687,   334,   335,   231,   289,   282,
     284,   987,   988,   148,   357,   149,   150,   295,   232,   233,
    1507,   395,   245,   248,   246,   247,   316,   372,   373,   375,
     380,   665,   249,   250,   325,   377,   198,    21,    82,   180,
     181,   182,   671,  2330,   183,   253,   242,   328,   329,   330,
     331,  1534,   565,   566,   567,   568,   788,  3018,  2737,  1141,
    3094,  3095,  3096,  3138,  3137,  3141,   569,   570,   571,   572,
     762,  1118,   783,  1133,  1134,  1175,   868,  1176,   764,   765,
     766,   767,   768,   769,   770,  1072,  1119,  2143,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,   718,   771,  1486,  2148,  2150,
    2735,   772,  1456,  2132,  1455,  2131,  1459,  2135,  1457,  2133,
    2115,  2124,   773,   774,   775,   776,  1440,  1441,  1442,  1443,
    1559,   573,  2771,  3043,  2517,   574,   841,  1536,  2493,  1837,
     117,   239,   367,  1355,   968,   969,   970,  1352,  1353,  1674,
    1675,  1676,  2026,  2027,  1356,  1357,  1670,  2030,  2022,  1682,
    1683,  2033,  2034,  2328,  2324,  2325,   575,  1183,    87,  1502,
    1503,  1832,   871,   821,   874,   696,   810,   793,   832,  1925,
      88,   697,   691,  1405,  2174,    89,   778,   576,   577,   923,
     924,   578,   579,   580,   581,   931,  2548,   952,  2790,   953,
    1604,   954,  1922,   955,  2254,   956,  1630,   582,  1600,  2253,
    2546,  2545,  3049,   118,    22,   583,  1157,  1508,  1509,  1620,
    1301,  1621,  1622,  2264,  2266,  1938,  1937,  1942,  1936,  1935,
    1928,  1927,  1930,  1929,  1932,  1934,   584,   585,   829,   586,
    1297,   938,  3050,   587,  1229,  2745,  1969,  1970,  1623,  1939,
    1872,  2211,   864,  1210,  1540,  1840,  1541,  1206,   588,   589,
     916,  1589,  2521,   590,   591,   592,   593,    23,    68,    24,
      25,    26,   119,   120,   594,   121,    27,   652,    28,   122,
     123,   160,   369,  1361,  2038,  2845,   124,   156,   300,   595,
    2111,    29,    30,    31,    32,    33,    62,    90,   125,   415,
    1370,  2044,   596,   911,  1876,  1578,  1874,  2926,  2512,  1579,
    1873,  2214,  2514,   597,   598,   599,   804,   805,  1265,   126,
     240,   368,   656,   657,   972,  1359,   600,   957,   958,   601,
    1309,   959,   779,    92,    93,    94,    95,  1272,   186,   140,
      96,   702,   137,   194,   195,  1273,  1274,  1883,  1275,   412,
     413,   940,   414,   941,  1596,  1597,  1276,  1277,  1137,  2647,
    2648,  2850,  1414,   819,   820,   602,  1152,  2910,   603,  2488,
     604,  1170,  1171,  1172,  1527,  1525,   605,   606,  1797,  1827,
     607,  1020,  1411,   608,   865,   866,   609,   879,   610,  1980,
     611,  3035,  2496,   612,  1844,  3111,  3112,  3113,  3144,   870,
     613,  1278,  1591,  1909,  1910,   614,  1495,   695,  1032,   615,
     616,   617,  2046,  2651,  2861,  2862,  2979,  2980,  2984,  2982,
    2985,  3073,  3075,   618,   619,  1267,  1583,   620,  1269,   887,
     888,   889,  1245,   621,   622,   623,  1552,  1237,   882,   201,
     890,   891,   780,  2047,  2372,  2373,  2356,   721,   722,  2042,
    2357,  2360,   127,   155,   361,   997,  1692,  2374,  2865,  1042,
     624,   880,   128,   152,   358,   994,  1690,  2361,  2863,  2043,
     906,  2195,  2761,  3036,  1240,   625,   626,   627,   628,   629,
     791,  1795,   715,  1744,   630,  2708,   709,   710,  2108,  1390,
     631,   632,  1006,  1007,  1008,  1402,  1729,  1009,  1726,  1399,
    1010,  1701,  1391,  1011,  1012,  1013,  1014,  1695,  1382,   633,
     800,   781,   634,  1333,  1334,  1645,  2576,  2807,  2295,  2573,
    3055,  3056,  1335,  1655,  2309,  1315,  2012,  2617,  2837,  2188,
    2492,  2013,  1336,  1337,  2719,  3011,  3012,  3013,  3089,  1338,
    1339,  1174,   635,   835,   636,   965,  1340,  1341,  2976,  1661,
    1662,  1663,  2015,  2311,  2840,  2841,  1342,  1990,  2289,  2804,
    1392,  1393,  1378,  2067,  1693,  2068,  1394,  2072,  1395,  2095,
    1396,  2096,  2426,  2427,  1696,  1343,  1639,  1640,  1987,  1344,
    3007,  2892,  3003,  1993,  2441,  2711,  2712,  2713,  3001,  2442,
    1994,  2893,  3008,  2055,  2056,  2057,  2058,  2059,  2867,  2668,
    2989,  2060,  2868,  2869,  2400,  2061,  2401,  2062,  2531,  1722,
    1723,  1724,  2697,  1725,  2423,  2417,  2881,  2069,  2842,  2404,
    2609,  2071,  2890,  1911,   782,  1912,  2223,  1060,  2116,  2728,
    2085,  2693,    61,   637,   638,  2568,  2799,  2282,  2798,  1666,
    2020,  2021,  2286,  1981,  1345,  1982,  2001,  2579,  1432,  1977,
    1978,  2720,  2895,  2797,  2572,  1913,  1653,  2112,  2113,  3004,
    2063,  1915,  1916,  2533,  2991,   639,   640,  1632,  1979,  2563,
    2794,  2795,  1312,   641,   786,  1347,  1348,  1648,  2297,  1349,
    1350,  1998,  2247,  2526,   642,   919,  1286,  1287,  1288,  1289,
    1351,  2002,  2615,  2836,  2306,  2612,  2613,  2614,  2611,  2599,
    2600,  2601,  2602,  2603,  2604,  2955,   703,  1593,   705,  1415,
    1917,    66,    50,    80,    77,   644,   893,  1556,  1160,  1231,
     645,   872,   646,  2161,   647,  1738,   707,  1417,   648,   649,
      44,   362,   363,   364,   365,   366,   650
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2574
static const short yypact[] =
{
    1083,   419, -2574, -2574,   307,   649,   649,   649,   649,   649,
     649,   649,   649,   307,  1138, -2574, -2574,  1138, -2574,  2431,
   -2574, -2574, -2574,   366, -2574,  1083, -2574, -2574, -2574, -2574,
   -2574,  1265, -2574, -2574, -2574, -2574, -2574,   316,   358, -2574,
     375, -2574, -2574, -2574, -2574, -2574,   307,    86, -2574,  -187,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574,  1281,   221, -2574, -2574, -2574, -2574,   903, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,   307, -2574,
   -2574,    86,  -113, -2574,   307,   367,  2431, -2574,   477, -2574,
   -2574, -2574, -2574,   983,   -65, -2574, -2574, -2574,   634,   407,
     307, -2574, -2574,   794,   307, -2574, -2574,   307,   307, -2574,
   -2574, -2574, -2574,   307,   307, -2574, -2574, -2574, -2574, -2574,
     903, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574,  6973,   -65, -2574,   904,   388, -2574, -2574,   353,
   -2574, -2574,   651,   221,   310, -2574, -2574, -2574, -2574, -2574,
    7833, -2574,   307,   406,   733,   307,  2431, -2574, -2574, -2574,
     307, -2574, -2574,   338,   980, -2574, -2574,   518, -2574,   523,
   -2574,   498, -2574, -2574,   549, -2574,   564, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,   573, -2574, -2574, -2574,
     388,  1794,  1009, -2574,   215, -2574,   388, -2574,   154, -2574,
   -2574, -2574,   143, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   338, -2574,   980, -2574, -2574,   615, -2574,   623, -2574,
     604, -2574, -2574,   669, -2574,   678, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574,   686,  1105,   307,   706, -2574,  2431,
    2431,   711,   307, -2574,   -79, -2574,   527,  1202, -2574,   541,
    1315,  1157,  1171,   307,  1284,  1295,  1317, -2574,   639, -2574,
     925, -2574, -2574, -2574, -2574, -2574,   388, -2574,   388,   891,
     237, -2574, -2574, -2574,  1335, -2574, -2574,  1344, -2574, -2574,
   -2574, -2574, -2574,   -79, -2574, -2574, -2574,  1358,  1371,   221,
    1284,  1379,  1388,   800, -2574,  1373, -2574,  1093,  1038, -2574,
    1114, -2574, -2574, -2574,   870, -2574, -2574,  1477, -2574,  1078,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,  1315,  1078, -2574,
   -2574, -2574, -2574, -2574, -2574,  1100,   243,   252,   308, -2574,
    3533, -2574, -2574, -2574,  1110,  1533,   327,  1160, -2574, -2574,
    1794, -2574,   388,  1099, -2574, -2574,   945,  1539,  1313,   365,
     370,   325,  1147,   385,  1187, -2574, -2574, -2574,   307, -2574,
   -2574,   307,  1220, -2574,  4020,   310,  4831,  2476,  -275,   307,
    1556,   -72, -2574,  1202,  1554, -2574, -2574, -2574, -2574,  1564,
   -2574,  1566, -2574,  1570, -2574,   307, -2574,   307, -2574, -2574,
    1284,  1585, -2574, -2574, -2574, -2574,   251,   388,  1592,   -72,
    1183,  1589, -2574,  1590, -2574, -2574, -2574,  1594, -2574, -2574,
   -2574,  1005,  1236,  1623, -2574,   307,  1239, -2574, -2574, -2574,
     307,   258,   307,   307,   258,   258,   949,   307, -2574,   307,
   -2574, -2574,   307, -2574,   815, -2574, -2574, -2574,   258, -2574,
   -2574, -2574, -2574,   307, -2574, -2574, -2574, -2574,    59,    59,
    7260, -2574, -2574, -2574, -2574, -2574, -2574,   258, -2574, -2574,
     258, -2574, -2574,   307, -2574, -2574,   258, -2574, -2574,   301,
     258, -2574, -2574,  7260,   258,   301,   307,   301,   258, -2574,
   -2574,    99,   258,   258,    99,   258,   307,    99,   258, -2574,
     258,   258,   258, -2574, -2574, -2574, -2574,   301,   258, -2574,
   -2574,   258,    71,   307, -2574, -2574, -2574, -2574,   258,   960,
   -2574, -2574, -2574,   258, -2574,  7726,   301,  7260,    44,    44,
     258, -2574, -2574,  1027,   301,  1044,  7260,  7260, -2574,   778,
    7260,   258,    86, -2574,  7260,   258,  7260,   301, -2574,   258,
    7260, -2574,  7260,    59,   307,   258,   307,    44,   258,   307,
      44, -2574,   307,   165, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   227, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   772, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574,   281, -2574,   307, -2574,   569, -2574,  1240, -2574,
   -2574, -2574,  1332, -2574, -2574,  1244,  1249,  1251,  1253, -2574,
   -2574,  1023,  1645,  1260, -2574,   261, -2574,  1351, -2574,  1266,
    1267,  1036,  1273,   307, -2574,   307,  1275, -2574,   312,  1233,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  1056,
    1280,  1218, -2574,  1062, -2574,  1060, -2574,  1675,  -175,   387,
   -2574, -2574, -2574,  1259, -2574,  1304, -2574,  1213,   146, -2574,
   -2574, -2574,  1435, -2574,  7260,  7260,  7260, -2574, -2574,  1264,
    1172,  1268,  1276,  1279,  1285,  1286,  1287,  1291,  1292,  1293,
    7260,  1318,  1305,  1306,  1308, -2574,  7260,  7260,  1309,  1314,
   -2574,  7260,  1316, -2574,  1320,  1321,  1325,  1327,  1329,  1337,
    1345,  1346,  6359, -2574,    67, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,   890, -2574,  1283,
   -2574, -2574, -2574, -2574,  6713, -2574, -2574, -2574,   301, -2574,
   -2574,  1304, -2574,    16, -2574, -2574,  1459, -2574,   110, -2574,
    1245, -2574, -2574, -2574, -2574,  1729, -2574, -2574,   582, -2574,
    1126, -2574,  1128,  1729, -2574,  1153, -2574, -2574,  1349,    82,
   -2574,  1319, -2574,  1119, -2574, -2574,  1350, -2574,  -152, -2574,
    1123,   399,  -215, -2574,  1056,  1462, -2574,  7260,  7260, -2574,
    1781,   258, -2574, -2574, -2574, -2574, -2574,   270,   270,   270,
   -2574,   270,  2636,   270,   270,  1194,    16,  1194,  1194,  1107,
    1107,  1194,  1194,    16, -2574,  1788, -2574,     0,  1789, -2574,
      16, -2574,    73,    65, -2574, -2574,  7260, -2574, -2574, -2574,
   -2574, -2574,   884, -2574, -2574,   310,  1416,   310,  7260, -2574,
      77, -2574, -2574,  7260,  1375,  1378,  1401,  1403,  1339,  1405,
    1044,  1321, -2574,  1465,   921,  1231, -2574,  1250, -2574, -2574,
   -2574,  1150, -2574,  1828, -2574,  1826,   307, -2574,   246,   108,
    1277, -2574, -2574,  1836, -2574,  1189,  1836,  1843,  1198,  1836,
    1843,  7260,  1836, -2574, -2574,   146,   301, -2574, -2574,  1439,
     283, -2574, -2574,  1428,   301,  7260,  1436, -2574, -2574,  1834,
    1839,  1797, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
    1154,  1154,   258,   258,   258,  3020, -2574, -2574,  1777,   281,
   -2574, -2574,   708, -2574, -2574, -2574,  1411, -2574, -2574, -2574,
   -2574,  6973,  1284, -2574, -2574,  1413, -2574,   415, -2574, -2574,
   -2574, -2574, -2574, -2574,  2431, -2574, -2574,  2431,   761,   206,
    1846, -2574, -2574,   259,   212,   334,  1871, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  1398,  1280,  1060, -2574,   949,
    -239,  1029,   307, -2574, -2574,   307, -2574,  1297,  1269,  1290,
    1460, -2574,  1464,    85, -2574, -2574, -2574,  6609,  2034,  2034,
      44,  7260, -2574,    44,    44,    44,    44,  1427,  7260,  1215,
    1455,  7260,  6359,  1471, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,  1288,    44,  1884,  7260,  4771,  6359,  1427,  7260, -2574,
    6359,  1890,   303, -2574, -2574, -2574,  7260, -2574,  7260,  7260,
    7260,  7260,  7260,  7260,  7260,  7260,  7260,  7260,  7260,  7260,
    7260,  7260,  7260,  7260,  7260,  7260,  7260,  7260, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  7260,  7260,
   -2574, -2574,  1485,  7260, -2574,  7260,  1489, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
     307,   301, -2574, -2574,  1915, -2574, -2574,  1296,  1493, -2574,
   -2574, -2574,   949,  1185, -2574,  1185,  1044,    99,  7260,  7260,
    7260,  1499, -2574, -2574,   301,   301, -2574,  1307,  1044,    44,
    1270,   307,   388,    46,    71,   301, -2574,  1330,  7260,  1606,
   -2574, -2574,  1383, -2574, -2574,  1938, -2574,    89,   146, -2574,
   -2574,  1942,  1945, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  2188,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  7726,
   -2574,  1107,  7260,   -32,    44,  1935,  1940, -2574, -2574, -2574,
   -2574, -2574,   139, -2574, -2574, -2574, -2574,  1821, -2574,  1751,
   -2574, -2574, -2574,  7260,    59, -2574, -2574,   307,  1950,    44,
      44, -2574,  1389, -2574,    44,  1359,   301, -2574,   307,   307,
    7260,    32, -2574,  1402, -2574,   284, -2574,  1502, -2574,  1503,
    7260,   943, -2574, -2574,  1367, -2574,  1985, -2574,  1447, -2574,
     301, -2574, -2574, -2574,   949,   301,   119, -2574, -2574, -2574,
   -2574,   307,    44,    44,   263,   283,  1848,  1817,   301,   146,
   -2574,  1448, -2574, -2574,  1938,  1973,  1602, -2574, -2574, -2574,
   -2574, -2574,  1682,  1682, -2574,   166,  1458, -2574,   307, -2574,
   -2574,  1304,  1304, -2574, -2574, -2574,   307, -2574,   307,   -38,
    1304, -2574,   679, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  1149, -2574, -2574, -2574,
   -2574, -2574,   162,   162,   555,   631, -2574,  -163, -2574,   708,
   -2574,  2431,  1983, -2574, -2574,  1983, -2574, -2574, -2574, -2574,
    2431, -2574, -2574,  1304, -2574,   818, -2574,  1581, -2574, -2574,
     818, -2574, -2574, -2574,  1587,  1588,   131,  1596,  1598,  1363,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,   307, -2574, -2574,
     131,  1366, -2574,   312, -2574,  1639,   -65,  1412, -2574,  1044,
    1457, -2574, -2574,  1574, -2574, -2574, -2574,  1488, -2574,   307,
     307,   307, -2574, -2574, -2574,   422,  6359,  1644,  1647,   426,
     429,   -38,  1648,  5201,  1651,  -118,  1077, -2574, -2574,    96,
    1657, -2574, -2574, -2574,  5454,  2024,  1318,   431,  1661,  5501,
   -2574,  1666,  3002,  1667, -2574,  7260,  7260,  7260,  5625,  7260,
    5670,  5841,  5970,  6396,  6545,  6609,  6787,  4385,  4174,  7480,
    6224,  2659,  7604,  7641,  2034,  2034,  2157,  2157,  3399,  6359,
    6094,  6141,  1427,  6359,  6292,  1427,  7260,  1629, -2574,  6713,
     307, -2574,  1444, -2574, -2574, -2574, -2574,  1446, -2574,  2067,
    2068, -2574,  2070,  1497,  7260, -2574, -2574,  1461,  2072, -2574,
    1601,  1453,  1843, -2574,  1695,   467, -2574,  1658, -2574, -2574,
    1467,  1113,   307, -2574, -2574,  1659,   258,   796,  7260, -2574,
     307,   307,  7260,    42,    16,  2089,  2088,  2071,  2073,  2636,
   -2574, -2574, -2574, -2574, -2574,   301,  1563, -2574, -2574, -2574,
    2035,  7260,   310,   964, -2574, -2574,  1776,  2097,  2099,   435,
   -2574,   436,   307,  1714,  1044, -2574,  7260,  1677,  1678, -2574,
   -2574,  1749, -2574,  7260,   433, -2574,  1515, -2574, -2574,   552,
   -2574,  7260, -2574, -2574,  1491,   904, -2574,  1217,   307,  2100,
    2739, -2574, -2574,  1693, -2574,  1697,  2110, -2574, -2574, -2574,
     104, -2574,  1843,  1843,  1466, -2574,  1568,  1575, -2574, -2574,
   -2574, -2574,    44,    44, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,  1188, -2574, -2574, -2574, -2574,    44,  2815,  2115,  2106,
   -2574,  1044,   783,   198,   161,  2023,    49,  1027, -2574,    37,
   -2574, -2574, -2574,  1703,    92,  1304,   150, -2574,  1516,  1509,
   -2574, -2574, -2574, -2574, -2574,   466, -2574, -2574, -2574, -2574,
    1706,  1513,  2133, -2574,  1423, -2574, -2574, -2574, -2574,   301,
     123, -2574, -2574, -2574,  1501,   631, -2574,   307,   307, -2574,
   -2574,   307,   660, -2574, -2574, -2574, -2574,  1715,  1721, -2574,
    1680, -2574,  1689, -2574,  1720,   439, -2574,  7349,   458,   113,
     113,   459, -2574,   113,  7349, -2574, -2574,  1456,  1456, -2574,
    1722, -2574,  1724,  1726, -2574,  1730,  1731, -2574,  1735, -2574,
   -2574, -2574,    76, -2574, -2574, -2574,   460, -2574, -2574,   465,
     307, -2574, -2574,  1029,  2143,  1044,   388,  7260, -2574,  2154,
   -2574, -2574, -2574, -2574,   131, -2574, -2574, -2574, -2574, -2574,
   -2574,  7776, -2574, -2574,  1318,  1318,  2140, -2574,  2141,  1580,
    1430, -2574,  1172,  1779, -2574, -2574,  1172, -2574, -2574, -2574,
    1782,  1172,  6359,  6359,  6359,  1172,  6359,  1172,  1172,  1172,
    2147,  2150,  2152,  7260,  1790,  2161,  7260,  1796, -2574,  2184,
   -2574,  6359, -2574, -2574,  1571,   131,   168, -2574,  1044,  7260,
    7260,  7260,  6923,  2190,    81, -2574, -2574,  1044, -2574,  1578,
     307,   307, -2574, -2574,   307,   307, -2574,  1324, -2574, -2574,
     318, -2574,  1583,  7260, -2574, -2574, -2574,  2185, -2574, -2574,
   -2574, -2574, -2574,   307,  1843, -2574, -2574,  1646, -2574, -2574,
     468, -2574, -2574, -2574,   301, -2574,  3729, -2574, -2574, -2574,
    1878,  2179, -2574,    44,  1861,  1863,  1752,  1600,  1867,  1785,
   -2574, -2574, -2574,    45,  1852, -2574, -2574, -2574, -2574,  1749,
   -2574, -2574, -2574,   201,   605, -2574, -2574, -2574,  1938,  7260,
    1792, -2574,  1762, -2574, -2574, -2574,  7856,  7856, -2574,  1056,
   -2574, -2574,  1456, -2574, -2574,  7581,  1791, -2574, -2574,  1798,
    1800, -2574,  1807,  1808,  1809,  1810,   307,   -48, -2574,  2217,
   -2574, -2574, -2574, -2574, -2574,  1669, -2574, -2574,   949,   301,
     301,   120,  1577, -2574,  2198,    16,   307,  1611,  1611,  1611,
    1611, -2574,  2236, -2574,  2238,  1611,  1611,  1611,  1611,  2188,
   -2574, -2574,  1611,   107, -2574, -2574, -2574, -2574,  2219,  2233,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  2234,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,   469, -2574, -2574,
   -2574,  2229, -2574, -2574,  1304, -2574,   -38, -2574, -2574, -2574,
   -2574, -2574, -2574,  1663,  1665,   228, -2574,    37, -2574,   113,
    1640,   258,  7349, -2574, -2574,  1827, -2574, -2574, -2574,   307,
     307,  7776,   213, -2574,  7260, -2574,  7260, -2574, -2574, -2574,
   -2574, -2574, -2574,   258,   113, -2574,  1304,   699,  1643,  1649,
    2258, -2574,  2264, -2574,   301,   307,   640,   640, -2574, -2574,
    2265, -2574,  2265,   714,   714,  2265, -2574, -2574,  2476, -2574,
   -2574,  4627,   182, -2574,  2476,  1662, -2574,   182,   113,   818,
   -2574,  7363,  1841,  4140,  1841,   197,  2257, -2574, -2574, -2574,
   -2574, -2574, -2574,   329, -2574,  1304,   404,  1881,  2268,  1655,
   -2574, -2574,   473, -2574,   131, -2574,   479,   209, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  1650,   347,  2261,  2261,  2263,
    2261,  2261,  2269, -2574,   210, -2574,   818,   307, -2574,   131,
   -2574, -2574,  1672,  1044,  2276,   271, -2574,   307,   487, -2574,
    7260,  1894,   202, -2574,   307, -2574,  1685, -2574,  1911, -2574,
    2289, -2574,  1740, -2574, -2574, -2574, -2574, -2574,  1699, -2574,
   -2574,  1927,  1929,  1939, -2574,  1941, -2574, -2574, -2574, -2574,
   -2574, -2574,  6359,   489, -2574, -2574,   490, -2574,  1944,  7260,
    7260,  2311,   492,  1044,  2328, -2574, -2574, -2574, -2574,  7260,
    1774,  2074,  7260, -2574, -2574, -2574, -2574,  1271,  1951,   318,
    1432,  1432,  2340,  -140, -2574,  2341, -2574, -2574, -2574,  1432,
     307,  1801,  1272,  2352,   307,    88,  7260, -2574, -2574,  2636,
   -2574,  1692,  7260, -2574,  2355,  7260, -2574,   301, -2574,   815,
     307,   301, -2574,  1970,  7260,  7260, -2574, -2574,    45,  1852,
   -2574,  2188, -2574, -2574,  1208, -2574, -2574,  1793, -2574,   388,
    7050,  1971,  1971, -2574,  1737,   -38,  1972,   374,   449,  7776,
     449,   449,   449,   449,  1747,  7776,  2739,  7776,  7776,  7776,
    7776, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574,  1928,   862, -2574, -2574, -2574,  1748, -2574,
   -2574, -2574, -2574,    44,  1611,    44,  1611, -2574, -2574, -2574,
   -2574, -2574, -2574,    16, -2574,  1039,  1135,  2815, -2574,  1978,
    1943,  7776,  1149,   161,   161, -2574, -2574, -2574, -2574,   501,
   -2574,  1900, -2574,  2365,   113,  -122, -2574,  1753, -2574,  2367,
    1799,  1799,  1799,  1799,   113,   113, -2574, -2574, -2574,  1823,
   -2574,   504, -2574,  1756, -2574,   307,   307,  1423,   301, -2574,
    2265, -2574, -2574,   307,   714,   714, -2574, -2574,   714,  2164,
    1754,  1763, -2574, -2574,    59,    59,    59,  2360,    59,    59,
      59,    59,    59,    59,  2363, -2574,  2364,    59, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  4627, -2574,   301,  1773,
   -2574,  1947,  2164,  2370, -2574,  2371,  2372,  2382,  2385,  2386,
    2387,  1232,  1662, -2574,  1947, -2574,   506, -2574, -2574,  1946,
   -2574,   254,   441, -2574,  7349, -2574,  7349, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  7856,  1984,  7856,  1987,
     673,  7776, -2574,  2389, -2574,  2123,   113,  1274,   113, -2574,
   -2574, -2574, -2574,  1567,  2395,  1567, -2574,  2417,  2417,   507,
    2032,  2417, -2574,  2036, -2574, -2574, -2574,   818, -2574, -2574,
   -2574, -2574,  1044, -2574, -2574,   131,  2162,  1938, -2574,  7776,
     191,  1904,   483, -2574,  1572,  1318,  1850,  1438, -2574, -2574,
   -2574, -2574, -2574,  7260, -2574, -2574, -2574, -2574, -2574,  1965,
   -2574,   262,  1044, -2574,  2428,  2007, -2574, -2574,  2049, -2574,
   -2574, -2574,  1891, -2574, -2574,   307,  1432,   388,  1372,   307,
    1432, -2574, -2574,    44, -2574, -2574,  7260, -2574, -2574, -2574,
      44,  1938,   301,  2202, -2574,  2419,  1568,  6359,  2418, -2574,
   -2574,   146,  2020, -2574, -2574,  7260, -2574, -2574,  2056, -2574,
   -2574, -2574,   605, -2574,  1568, -2574,  7260, -2574,   305, -2574,
    1789, -2574,  1567,  7776, -2574,   207,  2057,  2447, -2574, -2574,
   -2574,  7776, -2574,   511,  7776,  7776,  7776,  7776,   307,   514,
   -2574, -2574, -2574, -2574, -2574,  7260,  2013, -2574,  2111, -2574,
    2436, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574,   307, -2574,   118, -2574, -2574, -2574,  1149,   113,
   -2574,   -38,  2322,   515, -2574, -2574, -2574, -2574,   307,  1910,
    3505,  3505, -2574, -2574,  5344,  2037, -2574, -2574,  2038,  2039,
   -2574,  2040,  2042,  2043,  2046,   307,   -26, -2574, -2574,   516,
   -2574, -2574,  2590, -2574, -2574, -2574,   519,  2460,  2460, -2574,
   -2574,   522,  2461,  2466, -2574,   142, -2574, -2574,   113, -2574,
     149,  1862, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  2273,
    6973, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,   314,  2479, -2574,   301,
    1241, -2574,  2273, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  2257, -2574,  2044,  1669,
     160, -2574,  2044,   160, -2574,  7856, -2574, -2574,  7776, -2574,
     306, -2574, -2574, -2574,  2029, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574,  2098, -2574,  2462,  2103,  2104,  2465,
   -2574, -2574,  2105, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
     244,  2492, -2574, -2574,   307,  2134,   307,  1885,   449,  2173,
   -2574,  2075, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
    1452, -2574, -2574, -2574,  6359,  2116,    44,    16,  2136,  1044,
   -2574,  7260, -2574,  1949,  2484,    16, -2574, -2574,   576, -2574,
   -2574, -2574, -2574,   138,  2120,  1843,  2110,  2274, -2574,    16,
    2122,  2124,  2089,  2090, -2574,  2177,  2135, -2574, -2574, -2574,
   -2574,  2283,  2077, -2574,   202,  1456,  1912, -2574,  1456,  2138,
    7776, -2574,  2145,  2148,  2149,  2151, -2574, -2574,  1963, -2574,
   -2574, -2574,  1568, -2574,   526, -2574,   301,  1979,  1149,  1149,
   -2574, -2574,  7776, -2574, -2574,   113, -2574,  2114, -2574,  1979,
    2259,  2259,  2155,   374,   449,  7798,   449,   449,   449,   449,
    1926,  7798,  1799, -2574,  7798,  7798,  7798,  7798, -2574, -2574,
     113,  2537,   113,  1799,   258,  7349, -2574,   301, -2574, -2574,
     290, -2574, -2574,   307, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   301,  2479, -2574, -2574, -2574,   301, -2574,   301, -2574,
   -2574,  1219, -2574,  2313, -2574,  2316,   210, -2574,   528, -2574,
   -2574, -2574, -2574,   532,  2044,  2552,  2534, -2574, -2574,  1956,
   -2574, -2574, -2574, -2574,  2172, -2574,   191, -2574,   191, -2574,
   -2574,  7776, -2574,  2117, -2574,  2162,    93,   198,   307,  2540,
   -2574, -2574, -2574, -2574, -2574,  1044, -2574,  2175,  6671,  2139,
   -2574, -2574, -2574,  1952,    16, -2574, -2574, -2574, -2574, -2574,
   -2574,  2181,   146, -2574,  2177,  2177,   605, -2574,   388,  2191,
    1958,  1567,  1959, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   307, -2574,  2110,   483, -2574, -2574,   202, -2574,  7701,
     483, -2574,  2195,  7798, -2574,   534,  7798,  7798,  7798,  7798,
     307,   561, -2574, -2574, -2574, -2574, -2574, -2574,  2158, -2574,
   -2574, -2574,  2365,  2110,   149, -2574, -2574, -2574, -2574,  1390,
    1390, -2574,  1390, -2574,  1390,  1390, -2574, -2574, -2574, -2574,
   -2574, -2574,   219, -2574, -2574, -2574,  7776,  2163,  1567, -2574,
   -2574,   563, -2574,  2570, -2574, -2574,  7349, -2574, -2574, -2574,
   -2574,  2582, -2574,   378, -2574, -2574,  2162,  2201,   916, -2574,
   -2574,   270,   270,   270,   270,   270,   270, -2574,  2568, -2574,
     571, -2574,  7260,  1382, -2574,   480,  2177,  7260,  2177,  2089,
   -2574, -2574, -2574,  2353,   315, -2574,  1567, -2574,  1567,   104,
      16, -2574, -2574, -2574, -2574,   578, -2574, -2574, -2574, -2574,
    2204,  7798, -2574,  2206,  2209,  2212,  2213, -2574, -2574,  1799,
   -2574, -2574, -2574,  1390, -2574,  1390, -2574, -2574, -2574, -2574,
   -2574, -2574,   191, -2574,  7776,  2365,    93, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,   641, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  6671, -2574,  2600, -2574, -2574,
   -2574, -2574,   724, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   120, -2574,  7701, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   580, -2574, -2574, -2574, -2574, -2574,   751,   751, -2574,
   -2574,   751, -2574,  7260,   824, -2574, -2574,  2216, -2574, -2574,
   -2574, -2574, -2574, -2574,  2221, -2574, -2574, -2574,   152, -2574,
     146, -2574,  2089
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2574, -2574, -2574, -2574, -2574,   416, -2574,   510,  -185, -2574,
   -2574,  -852,   192, -2574, -2574, -1560, -2574, -2574, -2574, -2574,
    -486, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -1911, -2574, -1546, -2574,
     471, -2574, -2574, -2574, -2574, -2574, -2574, -2574,   758, -2574,
   -2574, -2574, -2574,  1364, -2574,  1054, -2574, -2574,   -62, -2574,
   -2574,  2592, -2574,  2594,  2266, -2574, -2574, -2574, -2574, -2574,
     827,   462, -2574,   822, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  -123,   417,   343, -2574, -2574,
    2351,   111, -2574,  2503, -2574, -2574,  2500, -2574,  2438, -2574,
   -2574, -2574,  2368,  2251,  1289,  2369,  -291, -2574, -2574, -2574,
   -2574, -2574,  1298,  -977, -2574, -2574, -2574, -2574, -2574, -2574,
    -147,  2298,  2444,  -198,   889, -2574,  2290,   214, -2574,  2347,
   -2574, -2574, -2574, -2574,  2356, -2574, -2574, -2574, -2574,  -327,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  2303, -2574,
    2302, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  -868,
   -2574, -2574,  -405, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
    2520, -2574, -2574,  1204, -2574,  -810,  -855,  1400, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,   905, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  -311, -2574, -2574, -2574, -2574,
   -2574,  2166, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -1690, -2574, -2574, -2574, -2574, -2574, -2574,  1261, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  1727, -2574, -2574, -2574,
   -2574,  1030, -2574, -2574, -2574, -2574, -2574, -1378, -2574, -2574,
    1022, -2574, -2574, -2574, -2574, -2574, -2574,  -717,  -566,   907,
    1177, -2574,  -491,   850,  -818,  1084, -2574,   879, -2574, -1832,
      -4,  -406, -2574, -2574, -1752,   376,  1139, -2574, -2574,   985,
    1424, -2574, -2574, -2574, -2574, -2574, -2574,   464, -2574,   169,
   -2574,  1420, -2574,  1112, -2574,   797, -2574, -2574, -2574,  -401,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,   917, -2574,
   -1261, -2574,  1102, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  1557, -2574,
   -2574, -2574, -2574, -2574, -2574,   -29, -2574, -2574, -1502, -2574,
   -2574, -2574, -2574,   698, -1728, -2574,  -826, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,  2700, -2574, -2574, -2574,  2606,  2699, -1014, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,    79, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574,  2703, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  1156, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  -431,  2249, -2574, -2574,
   -2574, -2574, -2574,  2083, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574,  1490, -2574, -2574,   -60, -2574, -2574,  1155, -2574,
   -2574, -2574,  -684,  -195,  2473, -2574, -2574, -2574, -2574,   617,
   -2574,  -716,  2060,  1443, -2002,   828, -2574,  1159,  1813,   101,
     -91, -2574, -2574, -2574,  1607, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574,  1542, -2574,  1134, -2574,  -330,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574,  -340, -2574, -2574,
   -2574, -2574, -2574, -2574,   537, -2574,  1632,   756, -2574, -2574,
   -2574, -2574, -2574,   400, -2574,   -83, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,  1892, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  -325,
   -2574,  1538,  1711, -2574, -2574,   412, -2574,  -390, -2574, -2574,
     430,   738, -2574, -2574, -2574, -2574, -2574, -2574, -2574,  -110,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2573, -2574,  1765,   992,  -976,
   -2574, -2574, -2574,  1391, -2574, -1350, -2574, -2574, -2574, -1372,
   -2574, -2574, -1334, -2574, -2574, -2574, -2574,  1415, -2574, -2574,
   -2574, -2574, -2574, -2574,   806, -2574, -2574, -2574, -2574, -2574,
   -2574,  -331, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574,  -293, -2574, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
   -2574,   779, -2574, -2574, -2574,  -177, -2574, -2574, -2574, -2574,
   -2574, -2574,   394, -2574, -2574,   752, -2574,  1101, -2574, -2574,
   -2574, -2574, -2574, -2574,  -954, -2574, -2574, -2574, -2574, -1388,
   -2574, -2574, -2574, -2574, -2574, -2574, -1958,    95, -2574, -2445,
     361, -2574, -2574, -1667,   423,   420,   757, -2574, -2422, -2072,
   -2574, -2574,   137,  -180, -2574, -2574, -2574, -2574, -1951, -2574,
   -2574, -2574, -1531, -2574, -2574, -1233, -2574,  -703,  1506,   135,
   -1654,   750, -2574, -1320, -2574, -2574, -2574, -2574,  -693, -2574,
   -1678, -2318,  2808, -2574, -2574, -2574, -2574, -2574, -2574, -2007,
   -2574,   513, -2574, -1384, -2574,  1868, -2574, -2574,  -861,   -70,
   -2574, -1682,   -66,   255,   540, -1114, -1404, -1954,   398,  -246,
     463, -1831, -2574,   606, -2574, -2574, -2574,  1527,  -521, -2574,
   -2574,   -99,  1886, -2574,   882, -2574, -2574, -1271,   267, -2574,
   -2574, -2574, -2303,    33, -2574, -2574, -2574,  1562, -2574, -2574,
   -2574, -2574, -2574, -2574, -2574, -2574, -2174,    17, -2574, -2241,
   -1896, -1623, -1027, -2574, -2574,    29,  -433,  -404,  -423,  1118,
    -499,     7,  1593,    94, -2574, -2574, -2574, -2574, -2574,  1700,
   -2574,  -511, -2574, -2574, -2574, -2574, -2574, -2574, -2574, -2574,
    -261,  1844,  2488, -2574, -2574, -2574, -2574
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1808
static const short yytable[] =
{
      43,   270,  1033,   388,   885,   260,   115,    34,   873,    58,
      60,   827,  1030,    60,  1368,   690,   286,  1018,  1223,  1819,
    1860,  1232,   704,  1179,   133,  1727,  1205,  1751,  1177,  1401,
    2086,   258,    34,   238,  1606,  1607,   927,  2077,    72,   930,
     419,  2213,    76,    79,  1379,  2070,  2073,  2299,  1061,  2073,
    1728,   785,  1702,   809,   785,  2221,  2222,  1649,   115,   723,
    2606,  2607,  2608,  2176,   794,  2117,  1516,  1968,   785,    42,
    1224,    42,   785,    42,   130,   129,   836,    79,  1224,   811,
     293,   340,  1243,   271,   785,   719,   794,  1155,  1138,   139,
    1299,   271,   822,  1127,  1528,   794,   146,  2695,    42,   672,
     151,  2163,   833,   153,   154,   704,  1028,   839,    42,   157,
     158,  2273,  1224,    42,   875,  1758,   301,   302,  1028,  3010,
      42,  1294,  1759,  2439,   802,   822,    42,   129,  2024,   822,
    2610,  1185,  1186,   822,  1187,  1304,  1207,  1208,  1028,   794,
      42,  1283,   794,  1224,  1222,   784,  1317,   396,   234,  1984,
    2164,   237,  1283,   921,  1225,  1226,   241,  1529,    42,  1530,
     692,  1531,   277,   692,   692,  1424, -1806,   271,   278,   279,
     271,   933,   934,    42,    99,   131,    42,   692,   271,   272,
     273,    42,  2251,   840,   271,  1889,  1890,    42,    42,   271,
     933,   934,    42,   883,   275,    42,   692,  1143,  1144,   692,
     837,   838,   675,  2384,  2773,   692,  1451,  2439,   142,   692,
     876,  2271,  2775,   692,  2224,  2384,  1028,   692,    42,  1295,
     268,   692,   692,   883,   692,    42,  2212,   692,    42,   692,
     692,   692,   298,    42,   271,  2424,  1890,   692,   304,    42,
     692,  1991,   268,   271,  1889,  1890,    42,   692,   381,   332,
    2872,  1988,   692, -1806,    99,    42,   268,   383,   203,   692,
    2384,  2300,  2301,  2302,  2303,  2304,   268,  2738,  1528,  1028,
     692,    42,  1321,  1755,   692,  2565,   268,  1017,   692,  2534,
    2535,  2536,  2537,  2093,   692,    42,    42,   692,  1299,    84,
     943,  2834,   942,  1214,  1215,  2974,  1180,    42,  1284,  2828,
    2032,  1634,  1635,  2035,   561,   651,  1162,  1576,  1598,  1284,
     268,  2876,  1545,   385,  3159,  1819,  2358,  1677,  2477,   660,
     268,  1650,  3009,  2180,  1996,  2293,  2672,  2564,    42,  2929,
     143,  1168,   391,  1220,    42,  2290,    84,  1409,  2387,  2388,
     294,  2389,  2390,  2391,  2392,  2393,  2394,    73,  2571,   654,
     700,   305,  2944,   661,   411,    84,  2575,   411,    84,   943,
    2312,    42,    65,  1023,  2950,   411,    67,   730,   998,   999,
     401,  1570,   655,   643,   653,   403,  1384,  1410,   306,  1255,
    1550,   332,  2235,   332, -1806,  1221,  2381,    36,    84,  1385,
     407,    84,  1025,   346,  2070,   348,  1000,  1001,  1002,   699,
      99,    42,  1169,    35,  2821, -1806,   187,   188,  1279,   700,
     136,   411,  1024,   943,   189,    42,   688,    19,   693,   694,
    1366,  1997,   701,   706,  1401,   708,    42,  1224,   711,    65,
    2975,  1224,   136,  1300,  1224,   875,  1224,  1651,    81,   694,
    1853,  1224,    19,  3090,  2049,   824,   777,    35,    36,   394,
    2387,  2388,  2995,  2389,  2390,  2391,  2392,  2393,  2394,   694,
      84,  1678,  1535,  2049,  2074,  2097,   394,  1163,  1300,   777,
    2099,  1756,   694,  2189,  2277,  2094,  1323,  2489,  2408,  2478,
    1679,  1680,   812,  2511,  2408,   261,   262,   263,   264,   265,
    2756,    84,  2435,    42,  2453,  2453,  3160,  2435,   828,   830,
    1681,   943,  3053,   132,  1384,   701,  2569,  2828,  2828,  2618,
     689,  2406,  2699,   777,   828,   828,  2780,  1385,  1577,  2780,
    2805,  2822,   777,   777,  2822,   904,   777,  2830,    79,  1425,
     777,  2941,   777,  2992,  1429,  1430,   777,  2992,   777,  3061,
     922,  1332,   922,   828, -1806,   922,   828,  1652,   922,   935,
    1833,  1447,  1427,  1428,   141,  1892,  1314,   839,   875,  2181,
    1238,  2800,  1241,  1546,   700,  2669,  3061,  2669,  3082,  2774,
    1893,   944,  2281,  2078,    97,  1576,  3105,   689,    84,  1384,
     692,  2395,    42,  3123,   946,  2822,  1408,  1586,  2385,    84,
    1280,   386,  1385,  1407,   261,   262,   263,   264,   265,  2288,
    2412,  2287,  1636,  2874,  2458,  1892,  1387,   689,   405,   134,
    1260,  2839,  1227,  3047,  1892,   704,   945,  1992,  1643,  1644,
    1893,  1784,  1388, -1806,  1787,  1497,   910,  1654, -1806,  1893,
    2225,  1329,   825,  1316,   382,  2739,  1380,  1511,  1156,   143,
    2574,   269,  1397,   384,  1985,  2665, -1806,  2320,  1512,  2499,
     971,   936,   945,   946,  1363,  1543,  2967,  1924,  2507,  2508,
    2079,  1285,  2252,   343,  2759,   197,  1835,  2835,  1976,  2025,
    1694,  2796,  1285,   827,  2886,    78,  2080,   674,   274,   993,
    3081,   411,  2769,  2675,   803,  1760,   274,   984,  2744,  1386,
     739,  1364,  2065,  2395,  1244,  2359,   701,  2433,  1329,  1228,
    2396,   692,   692,   692,  2065,  2710,  1532,   946,   826,  1492,
     826,  1029,  1517,  1841,  1533,   743,  1498,  2560,   392,  2081,
     777,   777,   777,  2746,  2065,  2429,  1230,  2751,  3119,  2298,
    3120,  2772,  2877,  1547,  1387,  1145,   777,   826,   704,  1561,
    2410,  3118,   777,   777,  2153,    84,  2490,   777,  2440,  2430,
    1388,  1924,  2682,  1764,  2685,  2729,   402,  2397,  1560,  2082,
     145,   404,   274,  1563,  1400,   274,  1003,  2897,  2109,  2525,
    1181,  1878,  1868,   274,  2425,  1615,   408,  2414,  1026,   274,
     777,  1602,  1603,  1165,   274,  1594,  1577,  1029,  2083,   986,
    1281,  2945,  2946,   951,  2943,   946,  2305,  2084,   752,   147,
   -1806, -1806, -1806, -1806, -1806,    42,  1367,  2003,  2528,  1387,
      42,   196,  2396,  1746,  2716,   689,  2004,  1749,   190,  2109,
    1750,  2523,  1765,  1282,  1182,  1388,  1854,  1855,  3131,   274,
    2050,   200,  2524,   777,   777,  2973,   235,  2011,   274, -1806,
    2005,   712,    42,  2006,  2669,   236,  1656,  2776,  2947,  2064,
    2075,  2098,  2848,  1004,  1555,  2418,  2100,  2420,  2421,  2190,
    2278,  2007,  2403,  2953,  2409,  2956,  2957,  2958,  2959,  2397,
    2411,  1369,   777,   243,  1371,   947,   948,   949,  2436,  3139,
    2454,  2455,   894,  2460,   777,  2398,   950,  2698,  1734,   777,
    2702,   757,  2570,  1809,  1253,  2619,  1005,  2664,  2700,  2566,
    2567,  2849,  2781,   759,   760,  2787,  2806,  2823,  2472,  1619,
    2829,   761,  1271,  2831,  1875,  2801,  3087,  2942,  1372,  2993,
     966,   967,  2676,  2994,  2529,  3062,  2962,   777,  3000,   184,
    3002,    42,   895,     1,   135,   136,  1615,  2970,  2380,  1669,
    2383,   777,  1995,   261,   262,   263,   264,   265,   251,     2,
       3,  2399,  3068,   252,  3083,  1406,   254,  1581,   104,  2764,
    2940,  2812,  3106,   105,  2838,  3088,  2008, -1806,    84,  3124,
     896,  3150,  2415,    84,   699,  1372,    42,  1515,   416,   255,
    2597,  2597,  2597,  2597,  2036,   834,   658,    42,  3092, -1806,
    1848,    42,  3093,  1421,   256,  1381,  2717,  2398,   259,  1389,
    1398,  1389,  2913,   138,    45,    84,  3145,  2718,   106,   107,
      42,  1573,   701,  3040,  3041,   701,   108,  1413,  1416,  1615,
    2009,   708,  1834, -1514,  2329,     5,     6,  2010,     7,     8,
    2362,  1974,   686,     9,  2530,   267,   828,   777, -1806,   828,
     828,   828,   828,  1859,   777,   287, -1806,   777,  1211,  1412,
      10,    11,   877,   288,    42,  1218,    42,  1373,   828,  2677,
     777,  2678,   290,  2399,   777,  2556,    42,   897,    12,   883,
    1619,    42,   777,  2257,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,    84,  2377,  1436,  2930, -1806,   291,
    2932,  1437, -1806,  1439,   777,   777, -1806,   960,   292,   777,
    1973,   777,  1745,     1,  1373,  1943,   296,  1657,   961, -1806,
    1824,  1931,  1933,  1401,  3134,  3114,  1487,  3116,  1658,     2,
       3,   297,    83,  1374,    42,   737,   299,  1657,   701,   700,
    1677,   303,  2428,   898,   777,   777,   777,   738,  1658,  1659,
     700,  2948,   308,  1619,    84,   828,  1660,  1514,     4,  1518,
     828,  2558,    42,    59,   777,    42,   317,  2802,  2972,  1659,
     962,  1783,  1642,  2292,  1786,  1264,  1660,    42,  1646,  1310,
   -1806,    42,    46,   326,   899,   963,  2598,  2598,  2598,  2598,
    1374,  1375,  2954,   654, -1806,  2310,    47,   327,  2954,   717,
    1148,  2963,  2964,  2965,  2966,     5,     6,  1149,     7,     8,
    1493,  1615,    42,     9,  2104,   973,   655,    84,   777,   789,
     828,    48,  1608,  1018,  1609,  1610,  1611,  1847,   839,    84,
      10,    11,   798,  2513,    84,    42,  1376,  1881,  1685,   777,
    1434,  1435,  3014,  1557,    42,   828,   828,  1691,    12,   875,
     828,   900,  1377, -1806,  1567,  1568,   777,  2660,   338,    42,
    2597,  2597,  3052,  3092,  2597,   692,   777,  3093,  3058,    49,
     109,  2280,  1672,  1673,   964,  2154,  1812,  2155, -1806,  1813,
     701, -1806, -1806,  2671,  1678,  2674,  2166,   922,   828,   828,
     754,  2469,  2484,  1376,  2683,     1,   110,    84,    42,    42,
    2437,    42,  2853,  1679,  1680,   699,    83,    42,    42,  1377,
     333,     2,     3,  2313,  1638,   901,   339,  1029,  1029,    13,
    1129,   336,  1647,  1681,  1647,    84,  1029,     2,     3,  1028,
    3060,    42, -1806,  3063,  3064,  3065,  3066,   276, -1806,  3085,
      84,   281,   787,   337,    84,  1619,  -266,   135,   136,   342,
    2870,  1257,  2854,  2870, -1806, -1806,   796, -1806, -1806,   756,
     801,   344,  2196,  2494,  1251,  2520,    42,   111,   758,  1029,
     345,   817,   815,   692,  2854,    84,  2491, -1806,   135,   136,
     823,   909,  1389,  1814,   349,   913,  1815,     5,     6,   917,
       7,     8,  2749,  1398,   692,     9,  1389,   350,    84,    42,
    1585,   136,  3108,     5,     6,   353,     7,     8,  1615,    42,
    1130,     9,    10,    11,   354,  1741,  1742,  1743,  2855,   355,
    2856,  2555,    84,  1404,   925,    42,  1705,   928,    10,    11,
      12,   356,  3014,  -266,  2110,  2857,  1664,  1665,  3126,    14,
    2855,  1258,  2856,  2858,  1825,  1826,    12,  2859,  2018,  -266,
      42,   777,   777,   777,  2121,   777,  2122,  2857,  1612,  2706,
     112,  1613,  2731,  1614,  2732,  2858,  2598,  2598,   360,  2859,
    2598,    84,  2860,  2704,  1436, -1806,  2900,   986,  2901,  1437,
    1438,  1439,   777,  1615,   359,   777,  1794,  1812,    15,   370,
    1813,  3115,  -266,  1616,  2860,  2597,  1233,  1234,  1235,  1236,
     777,  2597,  2597,   371,  2597,  2597,  2597,  2597,   374,   698,
     947,   948,  1940,  2597,  2248,  2177,  3097,    13,  1822,  1494,
      16,  1494,   716, -1806,   777,  2186,  1829,  1830,   777,   828,
     379,   926,  -266,  3110,   929,  1617,   389,   932,   390,  1618,
     113,  2105,  1619,  1034,  1035,  1036,  2990,   777,   114,    17,
     790,   393,    91,  2810,  2811,  1212,  1213,   397,  1857,  1216,
    1217,  -266,   777,  2123,   398,   399,   807,   808,   309,   777,
    -266,   400,   814,   406,  2220,   816,   659,   777,   409,   839,
     664,   417,  2431,  1882,  1271,   875,  1907,   720,   720, -1806,
     666, -1806,   667,  3097,  1814, -1806,   668,  1815, -1806,    51,
      52,    53,    54,    55,    56,    57, -1806,   875,   828,   828,
    3110,   673,   676,   678, -1806,   679,   680,  1619, -1806,  1615,
     682,    14,   828, -1806,   683,   185,   193,   684,   685, -1806,
     687,   975,  2461,  2597,   976,   977,  2597,  2597,  2597,  2597,
     978,  1029,   979, -1806,   980, -1806,   981, -1806, -1806, -1806,
     982,   983,  2125,   985,  2847,   310,  2127,   989,   990,   991,
    2019,  2130,  1706,  1015,   992,  2134,   996,  2136,  2137,  2138,
      15,   311,  2870,  2031,  2031,  1016,   136,  2031,  1019,  1021,
     193,   318,   720,  1022,  1053,  1027,   193,  2237,  2238,  2239,
    2240,  1031,   937,  1907,  1040,  2066,  2066,  1041,  1043,  2066,
    1907,  2598, -1806,  1131,  1146, -1806,  1044,  2598,  2598,  1045,
    2598,  2598,  2598,  2598,   312,  1046,  1047,  1048,    16,  2598,
    1707,  1049,  1050,  1051,   692,  1142,  2101, -1806,  2527,  1413,
     692,    17,  1708,   777,  1147,  1062,  1063,  2714,  1064,  1067,
    1389,  2597,  1709,  1150,  1068,  1151,  1071,  1907,  1153,  2597,
    1073,  1074,   692,  1619,   313,  1075,   193,  1076,   193,  1077,
    1710,  2241,  2242,  2243,  2244,  2245,  2246,  1078,   319,  1154,
    1711,  1054,  2551,  1712,  2553,  1079,  1080,  1159,  1158,   777,
    1161,  1164,   777,   314,   320,  2762,  1713,  1055,  1173,  1178,
    1209,  1389,   315,  1219,  1222,   777,   777,   777,   777,  1239,
    2066,  2605,  2605,  2605,  2605,  1247,  2168,  1822,  1248,  1256,
    2173,  2173,   261,   262,   263,   264,   265,  2580,  2581,   777,
    1259,  2363,  2078,   271,  1889,  1890,    42,   321,  1260,  2185,
    1056,  1249,   193,  1250,  1714,  1254,  1268,  2364,  2365,  2598,
    1270,  1291,  2598,  2598,  2598,  2598,  2366,  1292,  1224,   828,
     763,  1608,  1290,  1609,  1610,  1611,  1293,   937,  1302,  1298,
    1306, -1806,  1308,  2582,  1715,  1307,  1305,   322,  1354,  1362,
    1057,  1365,  1383,   795,  1716,   777,  1403,   839,   839,  1421,
    2367, -1806,  1907,  1907, -1806,  2904, -1806,   193,  1420,  2368,
    1422,  1907,  1419,  2912,  1423,  1717,   323,  1431,  1718,  1058,
    1719,  1445,  2234,  1128,  1448,   324, -1806,  2917,  1059,  2079,
    1453,  2705,  1018,  1446,   701,  1482, -1806,   869,  2369,  1485,
    1489,  1490,  2258,  1491,   714,  2080,   886,   892,  1720,  1504,
     908,  1230,  1510,  2686,   912, -1806,   914,  1721,  2721,  1526,
     918,  2740,   920,  1528,  2632,  2633,  2634,  2598,  2636,  2637,
    2638,  2639,  2640,  2641,  1522,  2598,  1524,  2644, -1806,   792,
    1537,  1548, -1806,  2370,  1538,   797,  1549,   799,  2081,  1553,
    1029,   806,  2753,  1551,   806,  1558,   651,   806,  1562,  2755,
    1573,  1564,   651,  1580,  1582,  2066,  1587,   818,  1907,   700,
    1588,  2239,  2240,  1590,  1626,  2296,  1647,  1907,  1300,  1628,
     777,  1629,   777,  1631,  1637,  2371,   867,  2714,  2082,  1686,
    2066,  1697,  1029,   878,   881,   884,  2971,  1699,  1700,   905,
    2687,  2031,   692,   692,  2518,  2722,  1703,   915,  1704,  1730,
    1732,  1733,  1736,  1735,  1737,  1747,  2688,  2083,  1748,  1752,
   -1806,  2723,  1754,   939,  2066,   653,  2084,  1907,  1761,  1907,
    1763,   653,  1766,  1914,  1094,  1095,  1096,  1768,  1771,  1792,
    1796,  2066,  3034,  2241,  2242,  2243,  2244,  2245,  2246,  1097,
    1389,  1798,  1799,  1800,   937,  1801,  1802,  1805,  1807,  2689,
    1804,  2605,  2605,  1806,  2724,  2605,  1808,  1612,  1810,  1823,
    1613,  1811,  1614,  1398,  1299,  1389,  1836,  1838,  1843,  1839,
    1845, -1806,  1851,  1741,  1852,  1858,   777,  1861,  1862,  1865,
    2443,  1871,  1615,  1918,  1885,  1920,  1879,  1919,  1924,  2690,
    1971,  1926,  1616,  1983,  2725,   950,  1098,  1099,  1100,  1101,
    1102,  1103,  1972,  1989,  2000,  1999,  2014,  2016,  2017,  2028,
    2041,  2039,  1104,  1105,  1106,   777,   777,  2040,  2691,  2045,
    2048,  2103,  2087,  2726,  2088,   777,  2089,  2692,   777,  2107,
    2090,  2091,  2727,  2470,  1617,  2092,  2118,  2119,  1618,  2120,
    2126,  2871,  2139,  2129,  2871,  2140,  1822,  2141,  2485,  1096,
    2487,  2144,   777,  2714,  1135,  2714,  2145,  2147,   777,  2149,
    2151,   777,  1097,  2184,  1892,  2162,  2503,  2167,  3122,  2187,
     777,   777,  2182,  2193,  2194,  2197,  3039,  2198,   939,  1893,
    2199,  2201, -1806,  1188,  2114,  2202,   777,  2218,  2906,  2200,
    2219,  2227,  2236,   701,  2256,  1907,  2583,   949,  2228,  2584,
    2229,  1907,  1907,  1907,  1907,  1907,  1907,  2230,  2231,  2232,
    2233,  2263,  2585,  2265,  2274,  2903,  1619,  2275,  2276,  1098,
    1099,  1100,  1101,  1102,  1103,  2279,  2291,  2294,  2283,   828,
    2284,   828,  2315,  2317,  2386,  1104,  1105,  1106,  2316,  2318,
    2323,  2379,  2405,  2406,  2407,  2413,   869,  1907,  1136,  2826,
    2827,  2586,  2587,  1107,  2432,  2438,  1108,  2416,   886,  2419,
    2066, -1751,  2748,  1246,  2588,  2422,  2596,  2596,  2596,  2596,
    2066,  2066,  2445,  2846,  3098,  3099,  3100,  3101,  3102,  3103,
    2444,  2621,  2622,  2019,  2527,  2446,  2605,   937,  2449,  2625,
    2450,  1167,  2605,  2605,  2448,  2605,  2605,  2605,  2605,  2447,
    2451,  2459,  2452,  2462,  2605,  2456,  2589,  1184,  1184,  1184,
    2464,  1184,  2471,  1184,  1184,  2475,  2479,  2483,  2465,    91,
      91,  2241,  2242,  2243,  2244,  2245,  2246,  2486,  2226,  2495,
    2498,  2506,  2522,  2524,  2516,  1189,  2538,  2550,  2547,  2561,
    2571,  2384,  2439,  2562, -1806,  2590,  2616,  2630,  2578,  2714,
    1907,  2620,  1907,   720,  3019,  2635,  2631,  2591,  2642,  2643,
     884,  2649,  1907,  2650,  1907,  2653,  2654,  1907,  2655,  2592,
    2593,  1266,  2066,  2684,  2066,  1109,  1107,  2594,  2656,  1108,
    2595,  2657,  2658,  2659,  2670,  2680,  2225,  2673,   274,  1373,
    1110,  2694,  2696,  2701,  1111,   939,  1136,  2703,   875,  1992,
    2707,  1389,  2736,  2741,  1303,  1907,  1029,  2742,   937,  2730,
    2743,  2744, -1806,  2760,  3162,  2758,  2763,  2767,  2777,   777,
    1311,  1311,  2778, -1806,  2605,   944,  2792,  2605,  2605,  2605,
    2605,  2803,  1112,  2796,  2114,  2822,  2832,  2813,  2814,  2815,
    2816,  2173,  2817,  2818,  2750,  2173,  2819,     2,     3,   828,
    2833,  2843,   777,  2844,  2851,  2866,   828,  2403,  2880,  2879,
    1113,  2884,  1190,  2871,  2882,  2883,  2885,  2888,  1191,  1192,
    1193,   777,  2891,  2896,  2898,  2899,     1,  2902,  1114,  2905,
    2911,  2915,   777,  2918,  2916,  2919,  2382,  2909,  1194,  1907,
    2920,  2922,     2,     3, -1806,  2440,  2924,  1907,  1109,  2933,
    1907,  1907,  1907,  1907,  2786,  2928,  2935,  2931,  2939,  2936,
    2937,   777,  2938,  1110,  2949,  2960,  2951,  1111,  1499,  1500,
    1501,  2968,  2987,     5,     6,  2988,     7,     8,  2793,  2996,
    2997,     9,  2605,  2999,  3006,  2066,  3017,  3020,  1523,  3032,
    2605,  3033,  3038,   692,  2296,  3084,  2596,  2596,    10,    11,
    2596,  2998,  3045,  3046,  3048,  1112,  3059,  3086,  3069,  3080,
    1115,  2820,  3091,  3104,  3117,  3125,    12,  3127,     5,     6,
    3128,     7,     8,  3129,  3130,  3143,     9,  3156,  2824,  2825,
    2826,  2827,  3157,  1113,  2066,  2502,  1638,  2434,  1539,  3142,
    2457,  1488,  1544,    10,    11,  1572,  1195,  2210,  1870,  1196,
      74,  1114,   562,    91,    75,    91,   884,   806,  2169,  2178,
     351,    12,  2482,   886,  1505,   818,   199,   204,   884,   283,
     677,   347,   193,   410,  1688,  1520,  1116,   285,  2128,   352,
    1569,  1188,  2733,   663,  1689,   378,   701,    13,   939,   701,
    1584,  1907,  1197,   376,  1907,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  2241,  2242,  2243,  2244,  2245,  2246,   669,   670,
    3140,  2146,  2532,  1793,  1097,   903,  1358,  1757,  2532,  1914,
    2541,  2542,  2543,  2544,  2037,  2029,  1029,  1198,  2158,  1831,
    2889,    91,  2894,  1115,  1605,  1601,  1923,  2791,  2549,  2255,
    3148,  1519,  2165,  1941,  2914,    69,   159,  1199,  1200,  1908,
      70,  2864,   828,  3044,    71,  1877,   813,   777,  1201,   974,
    1880,   341,  1625,  1202,  2114,   995,  1565,  1884,  2250,  1296,
    2852,  1098,  1099,  1100,  1101,  1102,  1103,  1886,  1887,  1888,
    2978,  1542,  1506,   271,  1889,  1890,    42,  1104,  1105,  1106,
    1592,  1986,  3146,  2540,  2663,  1595,  1907,  1496,  2986,  1116,
    1242,  1554,  1203,  1454,  2662,  2375,  2645,  2152,  1624,   939,
    1418,  2285,  3149,  3136,  1731,  1698,  2314,  3070,  1907,  2681,
    2376,  2066,  2715,  1891,  2076,  2887,  2667,  2666,  2378,   701,
    2873,  2596,  3078,  1189,  1204,  2402,  1360,  2596,  2596,  2878,
    2596,  2596,  2596,  2596,  1641,    64,  2066,  3015,  2066,  2596,
    2623,  1907,  3016,  1346,  2809,  2577,  1908,  2709,  3135,  2977,
    1633,  2539,  3051,  1908,  1671,  2808,  2952,  1313,  1599,  2969,
    2961,  2102,   418,     0,  1944,  1945,  1946,  1947,  1948,  1949,
    1513,     0,     0,     0,  2679,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1029,     0,  1029,     0,     0,  1907,     0,  1135,
    1908,     0,  2066,     0,  2894,     0,     0,     0,     0,   884,
       0,     0,  2114,     0,  1803,     0,     0,     0,  1107,     0,
       0,  1108,     0,  1950,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1828,   700,
       0,     0,  1501,     0,     0,     0,     0,  2793,     0,     0,
    1190,     0,     0,     0,     0,  1907,  1191,  1192,  1193,  2596,
       0,     0,  2596,  2596,  2596,  2596,  3067,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1194,     0,     0,     0,
    1638,     0,     0,  1867,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2114,     0,   701,     0,
       0,     0,  1907,     0,  2779,     0,     0,  2782,  2783,  2784,
    2785,     0,  1907,     0,     0,     0,     0,  1769,  1081,  1082,
    1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1908,  1908,     0,   777,  3109,
    1109,     0,     0,   777,  1908,  1842,     0,  1097,     0,     0,
       0,     0,     0,  1849,     0,  1110,     0,     0,     0,  1111,
       0,     0,     0,     0,   884,     0,     0,  2596,     0,     0,
       0,     0,     0,     0,     0,  2596,     0,     0,     0,     0,
       0,     0,     0,     0,  1195,   185,     0,  1196,  1029,     0,
    1907,     0,  2066,     0,     0,     0,     0,  1112,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,  1105,  1106,     0,     0,  1113,     0,     0,     0,  1907,
    1197,   884,  1975,   884,     0,     0,     0,   878,     0,     0,
       0,  1908,     0,  1114,  1892,     0,     0,  2106,  1318,   777,
    1908,  2875,     0,     0,     0,     0,     0,  1951,     0,  1893,
       0,     0,     0,     0,     0,  1198,     0,     0,     0,  2023,
    1952,     0,     0,     0,     0,     0,  1894,     0,     0,  1895,
       0,     0,     0,     0,     0,  1199,  1200,     0,     0,     0,
       0,     0,  1896,     0,     0,     0,  1201,     0,     0,     0,
    1908,  1202,  1908,     0,     0,     0,  1667,  1668,     0,  2156,
    2157,  1501,  2160,  1684,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1115,     0,     0,     0,     0,
       0,  1897,  1898,  2183,  1953,   884,   193,     0,     0,     0,
    1203,  1954,     0,  1908,  1899,     0,     0,     0,     0,     0,
       0,  1319,     0,  2934,  1037,  1038,  1039,     0,     0,  1320,
       0,  1107,     0,     0,  1108,  1321,     0,  1322,     0,     0,
    1052,     0,  1204,     0,     0,  2114,  1065,  1066,  1323,     0,
    1955,  1070,     0,     0,     0,     0,  1900,     0,     0,  2217,
       0,  1116,     0,     0,     0,     0,   884,     0,   884,     0,
       0,     0,     0,     0,  1956,     0,  1324,   884,     0,     0,
       0,     0,     0,     0,  1957,  1958,     0,     0,     0,     0,
    1959,     0,  1325,     0,     0,  1901,     0,  1326,     0,     0,
    1960,     0,     0,     0,     0,     0,     0,  1902,     0,  1327,
       0,     0,     0,     0,  2191,     0,  1328,     0,     0,  1903,
    1904,     0,  1961,     0,     0,  1962,  1963,  1905,     0,     0,
    1906,  1964,     0,     0,  3005,     0,     0,     0,   274,     0,
       0,     0,     0,  2215,     0,     0,     0,     0,  1908,     0,
       0,     0,     0,  1109,  1908,  1908,  1908,  1908,  1908,  1908,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
       0,     0,  1111,     0,     0,     0,     0,     0,     0,     0,
    1850,     0,     0,     0,  2307,     0,  2308,     0,  1965,  2249,
    1595,     0,  3057,     0,     0,     0,     0,     0,     0,  1966,
    1908,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,     0,  1097,     0,     0,     0,     0,  1908,
    1908,  1908,  1908,     0,  1921,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,  3079,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   720,   720,   720,  1114,   720,   720,   720,
     720,   720,   720,     0,     0,     0,   720,     0,     0,     0,
    1329,  1098,  1099,  1100,  1101,  1102,  1103,  1330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,  2319,     0,     0,     0,     0,  1331,
       0,     0,     0,  1908,  1332,  1908,     0,     0,     0,   271,
    1889,  1890,    42,     0,     0,  1908,     0,  1908,   387,     0,
    1908,     0,     0,     0,     0,     0,     0,  3005,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1115,  2463,
       0,  1426,  2468,     0,     0,     0,     0,     0,  1433,  2582,
       0,  1444,     0,     0,     0,     0,     0,     0,  1908,     0,
       0,     0,     0,     0,  1449,     0,  3057,     0,  1452,     0,
       0,     0,     0,   884,     0,     0,  1458,     0,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,     0,     0,
     869,     0,     0,     0,  1116,     0,     0,     0,  1480,  1481,
       0,     0,     0,  1483,     0,  1484,     0,     0,     0,     0,
     937,     0,     0,   884,     0,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1908,     0,     0,     0,     0,     0,     0,     0,
    1908,     0,     0,  1908,  1908,  1908,  1908,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2500,     0,   714,
       0,  2504,     0,     0,     0,   700,     0,     0,     0,     0,
       0,     0,     0,     0,  2515,     0,     0,  2206,  2207,   193,
       0,     0,     0,     0,     0,     0,     0,     0,  2216,  1908,
    1908,     0,     0,  1908,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2192,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1097,  2557,  2559,     0,     0,     0,
    1109,  2259,  2260,  2261,  2262,     0,     0,     0,     0,  2267,
    2268,  2269,  2270,     0,     0,  1110,  2272,     0,     0,  1111,
       0,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2624,  1908,
       0,     0,  1908,     0,  1908,     0,     0,  1908,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,  1112,     0,     0,
       0,     0,   162,     0,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,  2646,     0,
       0,   163,     0,     0,     0,  1113,     0,     0,     0,     0,
       0,  2661,     0,     0,     0,     0,     0,     0,     0,     0,
    2321,  2322,     0,  1114,     0,     0,     0,  2326,  2327,     0,
       0,     0,     0,     0,     0,     0,  2754,     0,     0,     0,
     164,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1892,     0,   165,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,     0,     0,  1893,  2770,     0,     0,  1908,
       0,     0,   884,     0,     0,     0,     0,     0,     0,     0,
     167,     0,  2583,     0,     0,  2584,     0,     0,     0,     0,
     168,  1908,     0,     0,     0,  2788,     0,     0,  2585,     0,
       0,     0,   884,     0,  1908,  1115,   169,     0,     0,     0,
    1908,  1908,     0,  1908,  1908,  1908,  1908,   193,     0,     0,
       0,     0,  1908,     0,  1908,  1772,  1773,  1774,  1107,  1776,
       0,  1108,  1595,     0,     0,     0,     0,     0,  2587,     0,
       0,   939,     0,     0,     0,     0,   170,     0,     0,     0,
    2588,     0,     0,     0,     0,  1908,  1791,     0,     0,     0,
       0,     0,     0,     0,  2473,  2474,     0,     0,     0,   171,
       0,  1116,     0,  2481,     0,     0,     0,     0,     0,     0,
    1908,     0,     0,     0,   172,     0,     0,     0,     0,     0,
       0,   173,  2589, -1807,   174,     0,     0,     0,     0,     0,
       0,     0,  2509,  2510, -1807,     0, -1807, -1807, -1807,     0,
       0,   937,     0,     0,     0,   175,     0,     0,   176,     0,
     177,  1846,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2590, -1807,     0,     0,     0,  1791,     0,  1908,   178,
       0,     0,  1908,  2591,     0,  1908,  1908,  1908,  1908,     0,
    1109,     0,     0,     0,     0,  2592,  2593,   179,  2552,     0,
    2554, -1807,     0,  2594,     0,  1110,  2595,     0,     0,  1111,
       0,     0,     0,     0,   274,     0,     0,     0,     0,     0,
       0,  1908,     0,     0,     0,  1908,     0,     0,     0,  2646,
       0,  2907,     0,     0,     0,  1908,     0,     0,     0,  2051,
       0,     0,     0, -1807,     0,     0,     0,  1112,  1886,  1887,
    1888,     0,     0,     0,   271,  1889,  1890,    42,  2626,  2627,
       0,     0,  2628,  2629,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1807,     0,  1113, -1807,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
    1908,     0,     0,  1114,  1891,     0,  2652,     0,  1908,  1097,
       0, -1807,     0,     0,     0,     0,     0,     0,     0, -1807,
       0, -1807,     0,  1908,     0,     0,     0,     0,     0,   884,
   -1807,     0,     0,     0,     0,     0, -1807,     0,     0,     0,
       0,     0,     0,     0, -1807,     0,     0,     0, -1807,     0,
       0,     0,     0,     0, -1807,     0,     0,     0, -1807, -1807,
   -1807, -1807,  1908,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0, -1807,     0,     0,     0,     0,     0,     0,
       0,     0,  1104,  1105,  1106,  1115,  1595,     0,     0,     0,
   -1807,     0,     0, -1807,     0, -1807,     0,     0,     0,   937,
       0,     0, -1807,  2142,     0,     0,  2142,     0,     0,     0,
       0,     0,     0,     0,     0, -1807,     0,     0,     0,     0,
    2747,     0,     0,     0,  2752, -1807,     0,  1595,     0,     0,
     700,     0,     0,     0,     0,     0,     0,  2757,     0,     0,
       0,  2646,     0,     0, -1807, -1807,  2981,     0,  2983,     0,
       0,  1116,     0,     0,     0,     0,  2768,     0,     0, -1807,
       0,     0,     0,     0,     0,     0,     0, -1807,     0,     0,
       0, -1807,     0,     0,     0,     0,     0,     0,     0,     0,
   -1807, -1807, -1807,     0,     0,     0,     0,   884,     0,     0,
    2789,     0,     0,     0,     0,   884,     0,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,     0,   939,     0,     0,     0,     0,     0,   193,     0,
    1097,     0,     0,  1107,     0,     0,  1108,     0,     0,     0,
       0,     0,  3107,     0,  2052,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1807,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1807,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,     0,     0,
   -1807,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1184,  1184,  1184,  1184,  1184,  1184,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1892,     0,     0,     0,     0,
       0,     0,     0,  3154,     0,  1109,     0,     0,     0,     0,
    1893,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1110,     0, -1807,     0,  1111,     0,     0,  1894,     0,     0,
    2053,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2054,  1896,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1807,     0,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
    2225,     0,     0,     0,     0,  2927,     0,     0,     0,     0,
       0,     0,     0,  1898,     0,     0,     0,     0,     0,     0,
    1113,     0,     0,     0,  1107,  1899,     0,  1108,     0,     0,
       0,     0,     0,     0, -1807,     0,     0,     0,  1114,     0,
     939,     0,     0,     0,     0,     0,     0,     0, -1807, -1807,
   -1807, -1807, -1807, -1807, -1807,     0, -1807, -1807,     0,  1791,
    1791,     0,     0,     0,     0,     0,     0,  1900,     0,     0,
       0,     0,     0, -1807,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2332,  2333,     0,  2334,  2335,  2336,     0,     0,     0,     0,
       0,     0,  2497,     0,     0,  1791,  1901,     0,     0,     0,
       0,     0,     0,     0,  1791,  1791,     0,     0,  1902,     0,
    1115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1903,  1904,     0,     0,     0,     0,     0,     0,  1905,     0,
       0,  1906,     0,     0,     0,     0,  1109,     0,     0,   274,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3042,  1110,     0,     0,     0,  1111,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,  1116,     0,     0,     0,
       0,     0,     0,  2337,     0,     0,  1097,     0,     0,     0,
       0,  2338,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3071,  3072,     0,  3074,     0,  3076,  3077,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1113,     0,     0,     0,  2339,     0,     0,     0,     0,
       0,     0,     0,     0,  2340,     0,     0,     0,     0,  1114,
       0,     1,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,   420,     2,     3,  1104,
    1105,  1106,     0,  2341,  2342,   421,     0,     0,     0,     0,
       0,     0,     0,  3121,     0,     0,     0,   422,   423,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,     0,     0,  3132,     0,  3133,
       0,   426,     0,     0,     0,     0,     0,     0,  2343,     0,
       0,     0,   427,   428,   429,     0,     0,     0,     0,     0,
       0,  1115,     0,     0,     0,     0,     0,     0,   430,     0,
     431,   432,   433,     5,     6,   434,     7,     8,   435,     0,
     436,     9,   437,   438,     0,     0,     0,     0,     0,   439,
    2344,     0,   440,  2734,   441,   442,   443,     0,    10,    11,
       0,  3151,  3152,     0,   444,  3153,   445,   446,  3155,   447,
       0,   448,   449,     0,     0,   450,    12,     0,     0,   451,
     452,   453,     0,   454,   455,     0,     0,  1116,   456,   457,
     458,     0,   459,     0,     0,     0,   460,     0,   461,   462,
    1107,     0,     0,  1108,   463,  1791,  2345,     0,   464,     0,
       0,   465,     0,   466,     0,   467,     0,   468,     0,   469,
     470,     0,   471,   472,   473,     0,     0,     0,   474,     0,
     475,   476,     0,   477,     0,     0,     0,     0,     0,     0,
       0,   478,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,   481,   482,     0,
       0,   483,   484,     0,     0,   485,   486,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,     0,   490,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,     0,   494,     0,     0,     0,   495,   496,     0,     0,
       0,   497,     0,     0,     0,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,  1109,     0,     0,   502,   503,     0,     0,     0,
       0,   504,     0,     0,   505,     0,     0,  1110,   506,   507,
       0,  1111,  1450,     0,     0,     0,     0,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,   510,     0,     0,     0,  1112,
       0,   511,     0,     0,     0,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,   110,     0,     0,  1113,     0,     0,
       0,   512,     0,   513,   514,     0,  1097,     0,     0,     0,
       0,     0,   515,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2354,  2355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   516,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   517,  1098,  1099,  1100,  1101,  1102,  1103,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
    1105,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   520,     0,     0,  1115,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,   523,   524,   525,   526,
       0,     0,     0,   527,     0,     0,     0,   528,     0,     0,
       0,     0,  2580,  2581,   529,   530,     0,     0,   271,  1889,
    1890,    42,     0,     0,     0,     0,   531,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   533,
       0,   534,     0,  1116,   535,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,  2582,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   537,     0,     0,   538,
       0,     0,     0,     0,   539,     0,     0,   540,   541,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,   542,  1108,     0,     0,     0,     0,     0,   543,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
       0,     0,   544,   545,   546,   547,   548,   549,   550,  1097,
       0,   551,     0,   552,     0,   553,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   700,     0,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,  1791,     0,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1753,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
    1105,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
    1097,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,  1097,  1108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,     0,  1892,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,  1108,  1893,     0,     0,  1115,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,  2583,     0,     0,  2584,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,  2585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2225,     0,     0,     0,     0,     0,
       0,     0,     0,  1116,     0,  1109,     0,  2587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2588,
    1110,     0,     0,     0,  1111,  1762,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,  1107,     0,  1097,  1108,     0,     0,
       0,  2589,  1112,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1767,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1113,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
    2590,     0,  1108,     0,     0,     0,     0,     0,  1114,  1112,
       0,     0,  2591,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,  2592,  2593,     0,     0,     0,  1104,
    1105,  1106,  2594,     0,     0,  2595,     0,  1113,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,     0,     0,     0,
    1115,  1110,     0,     0,     0,  1111,  1775,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,  1110,  1115,     0,     0,
    1111,  1777,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,  1104,  1105,
    1106,  1113,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,  1112,  1114,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
       0,     0,     0,  1116,     0,     0,  1113,     0,     0,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
       0,  1115,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,  1108,     0,     0,     0,  1115,  1110,     0,     0,
       0,  1111,  1778,  1098,  1099,  1100,  1101,  1102,  1103,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1116,     0,  1104,
    1105,  1106,     0,     0,     0,     0,     0,     0,     0,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,  1113,  1081,  1082,
    1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1114,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,  1097,     0,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,  1109,     0,  1107,     0,     0,  1108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,  1779,     0,     0,     0,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
    1107,     0,     0,  1108,  1097,     0,     0,  1115,  1112,     0,
    1104,  1105,  1106,  1082,  1083,     0,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,     0,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,  1116,     0,  1109,     0,  1104,  1105,  1106,
       0,     0,     0,  1107,     0,     0,  1108,     0,     0,     0,
    1110,     0,     0,     0,  1111,     0,     0,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1104,  1105,  1106,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,     0,     0,     0,  1115,  1110,     0,     0,
       0,  1111,     0,     0,     0,  1781,     0,     0,     0,     0,
       0,  1107,     0,     0,  1108,     0,     0,     0,     0,     0,
    1113,     0,     0,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1114,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1097,     0,  1782,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,  1109,     0,  1113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
    1110,  1108,     0,     0,  1111,  1114,     0,     0,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,  1097,  1107,     0,     0,  1108,     0,
    1115,     0,  1112,  1104,  1105,  1106,     0,     0,     0,     0,
       0,     0,     0,  1109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,     0,
    1113,     0,  1111,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1115,  1114,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
    1944,  1945,  1946,  1947,  1948,  1949,  1116,  1104,  1105,  1106,
    1112,     0,   724,     0,     0,     0,     0,     0,     0,     0,
    1109,   725,   726,  1785,     0,     0,     0,   271,   727,   728,
      42,     0,     0,     0,     0,  1110,     0,     0,  1113,  1111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1116,     0,     0,  1114,  1109,     0,  1950,
       0,     0,   729,     0,     0,     0,     0,   730,     0,     0,
    1115,     0,  1110,     0,   731,     0,  1111,  1112,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,  1108,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
       0,     0,   732,     0,     0,  1113,     0,     0,     0,     0,
       0,     0,  1097,     0,  1112,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,  1115,     0,
       0,     0,  1113,     0,     0,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,     0,     0,  3021,     0,     0,     0,     0,  1098,
    1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,  1105,  1106,     0,     0,
       0,     0,     0,    84,     0,   733,     0,     0,     0,     0,
       0,     0,     0,     0,  1116,  1115,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3022,  1110,   724,     0,     0,  1111,     0,     0,     0,     0,
       0,   725,   726,     0,     0,     0,     0,   271,   727,   728,
      42,     0,  1115,     0,     0,  3023,     0,     0,     0,     0,
       0,     0,     0,     0,  3024,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
    1109,  1116,   729,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,   731,  1110,     0,     0,     0,  1111,
    3025,  1113,   734,  1951,     0,     0,     0,   735,  3026,     0,
       0,     0,     0,     0,     0,     0,  1952,     0,  1116,  1114,
       0,     0,   732,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   736,  1107,  1112,     0,  1108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   724,
       0,     0,     0,     0,     0,  1113,     0,     0,   725,   726,
     737,     0,     0,     0,   271,   727,   728,    42,     0,     0,
    1953,     0,   738,  1114,     0,     0,     0,  1954,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     739,  1115,  3027,     0,     0,   740,     0,     0,   741,   729,
       0,     0,     0,    84,   730,   733,     0,     0,     0,   742,
       0,   731,     0,     0,     0,   743,  1955,     0,     0,     0,
       0,     0,     0,     0,     0,   744,     0,     0,     0,     0,
     745,     0,     0,   746,     0,     0,   747,     0,     0,   732,
    1956,     0,     0,     0,     0,   748,   749,     0,  1109,     0,
    1957,  1958,     0,     0,     0,  1115,  1959,  1116,     0,     0,
       0,     0,     0,  1110,     0,     0,  1960,  1111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1132,   750,     0,  1961,     0,
     751,  1962,  1963,     0,     0,     0,     0,  1964,   752,     0,
       0,     0,   734,     0,     0,  1112,     0,   735,     0,   753,
       0,     0,     0,     0,     0,   754,     0,     0,  1780,     0,
       0,  1116,     0,   161,     0,     0,     0,     0,     0,     0,
      84,     0,   733,  1113,     0,   736,     0,     0,     0,     0,
     755,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1114,     0,     0,  1965,     0,     0,     0,     0,   724,
       0,     0,   162,  3028,     0,  1966,     0,     0,   725,   726,
     737,     0,     0,     0,   271,   727,   728,    42,     0,     0,
       0,   163,   738,     0,   756,     0,     0,     0,     0,     0,
       0,   757,     0,   758,     0,     0,     0,     0,     0,     0,
     739,     0,     0,   759,   760,   740,     0,     0,   741,   729,
       0,   761,     0,     0,   730,     0,     0,     0,     0,   742,
     164,   731,   274,     0,     0,   743,     0,     0,     0,   734,
       0,     0,   165,  1115,   735,   744,     0,     0,     0,     0,
     745,     0,   166,   746,     0,     0,   747,     0,  2051,   732,
       0,     0,     0,     0,     0,   748,   749,  1886,  1887,  1888,
     167,     0,   736,   271,  1889,  1890,    42,     0,     0,     0,
     168,  1886,  1887,  1888,     0,     0,     0,   271,  1889,  1890,
      42,     0,     0,     0,     0,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   750,   737,     0,  1116,
     751,     0,     0,  1891,     0,     0,     0,     0,   752,   738,
       0,     0,     0,     0,     0,     0,     0,  1891,     0,   753,
       0,  2159,     0,     0,     0,   754,   170,   739,     0,     0,
       0,     0,   740,     0,     0,   741,     0,     0,     0,     0,
      84,     0,   733,     0,     0,     0,   742,     0,     0,   171,
     755,     0,   743,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   744,     0,   172,     0,     0,   745,     0,     0,
     746,   173,     0,   747,   174,     0,     0,     0,     0,     0,
       0,     0,   748,   749,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,   756,   175,     0,     0,   176,     0,
     177,   757,     0,   758,     0,  1097,     0,     0,     0,     0,
       0,     0,     0,   759,   760,     0,     0,     0,     0,   178,
       0,   761,  2519,   750,     0,     0,     0,   751,     0,   700,
       0,     0,   274,     0,     0,   752,     0,   179,     0,   734,
       0,     0,     0,   700,   735,     0,   753,     0,     0,     0,
       0,     0,   754,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,   736,     0,     0,     0,     0,   755,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,  1886,
    1887,  1888,     0,     0,     0,   271,  1889,  1890,    42,     0,
       0,     0,     0,     0,     0,     0,     0,   737,     0,     0,
       0,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,   738,
       0,   756,     0,     0,     0,     0,     0,     0,   757,  1097,
     758,     0,     0,  2052,     0,  1891,     0,   739,     0,     0,
     759,   760,   740,     0,     0,   741,     0,  2052,   761,  1092,
    1093,  1094,  1095,  1096,     0,     0,   742,     0,     0,   274,
       0,     0,   743,     0,     0,     0,  1097,     0,     0,     0,
       0,     0,   744,     0,     0,     0,     0,   745,     0,     0,
     746,     0,     0,   747,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,   748,   749,     0,     0,     0,     0,     0,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,  1886,
    1887,  1888,     0,     0,     0,   271,  1889,  1890,    42,  1107,
       0,     0,  1108,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,   750,  1892,     0,     0,   751,     0,  1104,
    1105,  1106,     0,     0,     0,   752,     0,     0,  1892,  1893,
       0,     0,     0,     0,     0,  1891,   753,     0,     0,     0,
       0,   700,   754,  1893,     0,     0,  1894,     0,     0,  2053,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1894,  2054,  1896,  2053,  1886,  1887,  1888,   755,     0,     0,
     271,  1889,  1890,    42,     0,  2054,  1896,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2580,  2581,     0,     0,
       0,     0,   271,  1889,  1890,    42,     0,     0,     0,     0,
       0,     0,  1898,     0,     0,     0,     0,     0,     0,     0,
    1891,   756,     0,     0,  1899,     0,  1898,     0,   757,     0,
     758,  1109,     0,  1107,   842,     0,  1108,     0,  1899,     0,
     759,   760,  2582,   843,     0,   205,  1110,     0,   761,     0,
    1111,     0,   844,     0,     0,     0,  1888,   845,     0,   274,
     271,  1889,  1890,    42,     0,     0,  1900,     0,     0,     0,
    1107,   700,     0,  1108,     0,     0,     0,     0,     0,     0,
    1900,     0,     0,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,   206,   207,     0,     0,     0,     0,     0,     0,
    1891,   846,   208,     0,     0,  1901,     0,     0,     0,   847,
       0,     0,     0,     0,     0,     0,  1113,  1902,     0,  1901,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1903,
    1904,  1902,     0,     0,  1114,     0,     0,  1905,     0,     0,
    1906,     0,     0,  1903,  1904,     0,   700,     0,   274,     0,
       0,  1905,     0,     0,  1906,  1109,  1892,     0,     0,     0,
       0,     0,   274,     0,     0,   848,     0,     0,   700,     0,
    1110,  1893,     0,     0,  1111,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1894,     0,
     849,  1895,  1109,     0,     0,     0,     0,   850,     0,   851,
       0,     0,     0,     0,  1896,     0,     0,  1110,     0,   852,
       0,  1111,  1112,     0,     0,     0,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   700,     0,     0,     0,
       0,  2225,     0,     0,     0,   853,     0,     0,     0,     0,
    1113,     0,     0,   854,  1898,     0,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,  1899,     0,  1114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,  1892,  1113,     0,     0,
     855,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,  1893,     0,     0,     0,  1114,     0,     0,  1900,     0,
       0,     0,     0,     0,     0,     0,   856,     0,  1894,     0,
       0,  1895,   210,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1896,     0,     0,     0,     0,     0,
       0,   211,     0,     0,     0,     0,     0,  1901,     0,     0,
    1115,     0,     0,     0,   857,     0,     0,   212,     0,  1902,
       0,  1892,     0,     0,     0,   858,     0,     0,     0,     0,
       0,  1903,  1904,  3054,  1898,     0,  1893,     0,     0,  1905,
     213,     0,  1906,  1892,     0,     0,  1899,  1115,     0,     0,
     274,     0,   214,  1894,     0,     0,  1895,     0,  1893,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,  1896,
       0,     0,     0,     0,     0,  2583,  1116,     0,  2584,     0,
     216,     0,     0,     0,     0,     0,     0,     0,  1900,     0,
     217,  2585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1892,     0,     0,     0,     0,   218,     0,     0,  1898,
       0,     0,     0,  1116,     0,     0,  1893,     0,     0,     0,
       0,  1899,     0,     0,   859,   860,   861,  1901,     0,     0,
       0,  2587,     0,  1894,     0,     0,  1895,   862,     0,  1902,
       0,     0,     0,  2588,     0,     0,   219,     0,     0,  1896,
       0,  1903,  1904,     0,     0,     0,     0,     0,     0,  1905,
       0,     0,  1906,  1900,     0,     0,     0,     0,     0,   220,
     274,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   221,  2589,     0,     0,     0,  1898,
       0,   222,     0,     0,   223,     0,     0,     0,     0,     0,
       0,  1899,  1901,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1902,   224,     0,     0,   225,     0,
     226,     0,     0,     0,  2590,     0,  1903,  1904,     0,     0,
       0,     0,     0,     0,  1905,     0,  2591,  1906,     0,   227,
     863,     0,     0,  1900,     0,   274,     0,     0,  2592,  2593,
       0,     0,     0,     0,     0,     0,  2594,   228,     0,  2595,
       0,     0,     0,     0,     0,     0,     0,   274,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1901,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1902,     0,     0,     0,     0,   229,
       0,     0,     0,     0,     0,     0,  1903,  1904,     0,     0,
       0,     0,     0,     0,  1905,     0,     0,  1906,     0,     0,
       0,     0,     0,     0,     0,   274
};

static const short yycheck[] =
{
       4,   196,   718,   330,   525,   190,    68,     0,   519,    13,
      14,   502,   715,    17,   991,   421,   214,   701,   870,  1521,
    1566,   876,   426,   841,    84,  1397,   852,  1431,   838,  1005,
    1708,   178,    25,   156,  1295,  1296,   547,  1704,    31,   550,
     365,  1873,    46,    47,   998,  1699,  1700,  2001,   741,  1703,
    1400,   457,  1386,   484,   460,  1886,  1887,  1328,   120,   449,
    2301,  2302,  2303,  1815,   470,  1755,    20,  1627,   474,    27,
       5,    27,   478,    27,    78,    68,   509,    81,     5,   485,
     227,   266,     5,    24,   490,    26,   492,     5,   791,    93,
       5,    24,   498,    26,     5,   501,   100,  2415,    27,   390,
     104,    20,   508,   107,   108,   509,    25,   513,    27,   113,
     114,  1943,     5,    27,   520,    19,   239,   240,    25,    26,
      27,   931,    26,     5,    25,   531,    27,   120,     5,   535,
    2304,   848,   849,   539,   851,   945,   853,   854,    25,   545,
      27,    33,   548,     5,     5,   456,   964,   342,   152,   100,
    1804,   155,    33,   543,    81,    82,   160,    68,    27,    70,
     421,    72,    19,   424,   425,  1033,    62,    24,    25,    26,
      24,    25,    26,    27,    63,    81,    27,   438,    24,    25,
      26,    27,    62,   513,    24,    25,    26,    27,    27,    24,
      25,    26,    27,    25,   198,    27,   457,    87,    88,   460,
     511,   512,   397,     6,  2522,   466,  1067,     5,    97,   470,
     521,  1939,     5,   474,  1892,     6,    25,   478,    27,   935,
       5,   482,   483,    25,   485,    27,    25,   488,    27,   490,
     491,   492,   236,    27,    24,    25,    26,   498,   242,    27,
     501,   149,     5,    24,    25,    26,    27,   508,     5,   253,
    2672,  1639,   513,    91,   143,    27,     5,     5,   147,   520,
       6,    48,    49,    50,    51,    52,     5,     5,     5,    25,
     531,    27,   235,   391,   535,  2282,     5,   700,   539,  2230,
    2231,  2232,  2233,   207,   545,    27,    27,   548,     5,   190,
     274,   149,    65,   859,   860,     5,    26,    27,   190,  2602,
    1678,   135,   136,  1681,   366,   367,   458,    23,   189,   190,
       5,     5,   344,     5,   162,  1817,   134,   480,   458,   391,
       5,   359,  2895,     5,   174,  1992,  2398,  2281,    27,  2774,
       5,   546,     5,   333,    27,  1989,   190,   576,     9,    10,
     229,    12,    13,    14,    15,    16,    17,    31,   470,   624,
     190,   430,  2797,   425,   358,   190,   478,   361,   190,   274,
    2014,    27,    19,   538,  2809,   369,     0,    64,    56,    57,
       5,   339,   647,   366,   367,     5,   245,   616,   457,   900,
    1232,   385,   430,   387,   339,   385,  2053,    29,   190,   258,
       5,   190,     5,   282,  2048,   284,    84,    85,    86,    25,
     289,    27,   617,    28,   430,   360,    18,    19,   162,   190,
     458,   415,   587,   274,    26,    27,   420,     0,   422,   423,
       5,   271,   426,   427,  1400,   429,    27,     5,   432,    86,
     140,     5,   458,   150,     5,   841,     5,   475,   625,   443,
       5,     5,    25,  3016,     5,   374,   450,    28,    29,   338,
       9,    10,  2874,    12,    13,    14,    15,    16,    17,   463,
     190,   624,  1178,     5,     5,     5,   355,   619,   150,   473,
       5,   589,   476,     5,     5,   399,   248,   389,     5,   619,
     643,   644,   486,  2211,     5,    18,    19,    20,    21,    22,
    2492,   190,     5,    27,     5,     5,   344,     5,   502,   503,
     663,   274,  2947,   616,   245,   509,     5,  2810,  2811,     5,
     349,     5,     5,   517,   518,   519,     5,   258,   234,     5,
       5,     5,   526,   527,     5,   529,   530,     5,   532,  1040,
     534,     5,   536,     5,  1045,  1046,   540,     5,   542,     5,
     544,   504,   546,   547,   440,   549,   550,   585,   552,   384,
     508,  1062,  1043,  1044,   619,   395,   962,   963,   964,  1820,
     885,  2568,   887,   595,   190,  2396,     5,  2398,     5,  2523,
     410,   344,  1976,   366,   353,    23,     5,   349,   190,   245,
     841,   252,    27,     5,   568,     5,  1019,  1271,   391,   190,
     344,   283,   258,  1016,    18,    19,    20,    21,    22,  1987,
     391,  1985,   436,  2675,  2150,   395,   475,   349,   283,   242,
     578,   462,   539,  2931,   395,  1019,   389,   525,  1321,  1322,
     410,  1482,   491,   578,  1485,  1146,   532,  1330,    23,   410,
     470,   470,   561,   963,   391,   373,   430,  1158,   556,     5,
    2294,   426,   430,   391,   595,   391,   542,  2025,  1159,  2195,
     654,   486,   389,   568,   981,  1221,  2830,   550,  2204,  2205,
     453,   553,   542,   426,  2496,    14,  1534,   525,   470,   546,
    1373,   553,   553,  1164,   430,   589,   469,   426,   619,   683,
    2998,   685,  2514,    10,   585,   589,   619,   426,   550,   430,
     387,   982,   611,   252,   617,   513,   700,   426,   470,   626,
     371,   962,   963,   964,   611,   514,   617,   568,   666,  1142,
     666,   715,   666,  1539,   625,   412,  1147,  2277,   391,   512,
     724,   725,   726,  2475,   611,  2097,   661,  2479,  3046,  2000,
    3048,   426,   426,  1224,   475,   625,   740,   666,  1142,  1250,
    2074,   426,   746,   747,   576,   190,   658,   751,   546,  2099,
     491,   550,  2406,  1446,  2408,  2445,   391,   428,  1249,   552,
     353,   391,   619,  1254,   430,   619,   454,  2718,  1744,   395,
     500,  1581,   339,   619,  2094,   295,   391,   430,   391,   619,
     784,  1292,  1293,   384,   619,  1284,   234,   791,   581,   678,
     544,  2798,  2799,   601,  2796,   568,   583,   590,   495,     5,
     638,   639,   640,   641,   642,    27,   391,   341,   359,   475,
      27,   458,   371,   391,   331,   349,   350,   391,   430,  1795,
     391,  2225,   391,   577,   554,   491,   391,   391,  3069,   619,
     391,   521,   391,   837,   838,  2837,   430,  1655,   619,   234,
     374,    26,    27,   377,  2675,   112,   167,  2525,  2802,   391,
     391,   391,   538,   541,  1244,  2088,   391,  2090,  2091,   391,
     391,   395,   458,  2814,   391,  2816,  2817,  2818,  2819,   428,
     391,   994,   876,   535,   997,   648,   649,   650,   391,   238,
     391,   391,   104,   391,   888,   556,   659,  2418,  1409,   893,
    2421,   588,   391,   426,   898,   391,   584,   391,   391,  2283,
    2284,   587,   391,   600,   601,   391,   391,   391,  2169,   429,
     391,   608,   916,   391,   362,  2569,   538,   391,   157,   391,
     639,   640,   249,   391,   475,   391,  2822,   931,  2886,    25,
    2888,    27,   154,    30,   457,   458,   295,  2833,  2052,   384,
    2054,   945,  1645,    18,    19,    20,    21,    22,   430,    46,
      47,   622,   391,   430,   391,  1015,   458,  1268,    55,  2505,
    2792,  2584,   391,    60,  2618,   587,   500,   362,   190,   391,
     192,   391,   625,   190,    25,   157,    27,  1162,   361,   430,
    2300,  2301,  2302,  2303,   324,    25,   369,    27,   347,   238,
      26,    27,   351,   589,   430,   999,   513,   556,   425,  1003,
    1004,  1005,   426,    20,   355,   190,   282,   524,   105,   106,
      27,   578,  1016,  2924,  2925,  1019,   113,  1021,  1022,   295,
     554,  1025,  1533,   619,  2038,   122,   123,   561,   125,   126,
    2044,   248,   415,   130,   585,    26,  1040,  1041,   324,  1043,
    1044,  1045,  1046,  1564,  1048,   430,   295,  1051,   856,    20,
     147,   148,    25,   430,    27,   863,    27,   296,  1062,   386,
    1064,   388,   458,   622,  1068,    26,    27,   289,   165,    25,
     429,    27,  1076,  1925,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,   190,  2049,    19,  2775,   347,   430,
    2778,    24,   351,    26,  1108,  1109,   282,   335,   430,  1113,
    1631,  1115,  1423,    30,   296,  1626,   430,   438,   346,   295,
    1526,  1612,  1613,  2099,  3082,  3036,  1130,  3038,   449,    46,
      47,    26,    25,   372,    27,   357,   430,   438,  1142,   190,
     480,   430,  2096,   365,  1148,  1149,  1150,   369,   449,   470,
     190,  2805,   625,   429,   190,  1159,   477,  1161,    75,  1163,
    1164,    26,    27,    25,  1168,    27,   625,  2571,  2835,   470,
     398,  1482,  1319,  1991,  1485,    25,   477,    27,  1325,    25,
     429,    27,   533,    26,   406,   413,  2300,  2301,  2302,  2303,
     372,   430,  2815,   624,   480,  2013,   547,    26,  2821,   443,
     618,  2824,  2825,  2826,  2827,   122,   123,   625,   125,   126,
      25,   295,    27,   130,  1735,   646,   647,   190,  1222,   463,
    1224,   572,    34,  1907,    36,    37,    38,  1552,  1634,   190,
     147,   148,   476,    25,   190,    27,   475,    20,  1361,  1243,
      25,    26,  2896,  1247,    27,  1249,  1250,  1370,   165,  1655,
    1254,   473,   491,   429,  1258,  1259,  1260,    25,   619,    27,
    2580,  2581,  2944,   347,  2584,  1526,  1270,   351,  2950,   620,
     367,  1974,   641,   642,   502,  1796,   163,  1798,   638,   166,
    1284,   641,   642,  2397,   624,  2399,  1807,  1291,  1292,  1293,
     512,    20,    20,   475,    20,    30,   393,   190,    27,    27,
    2110,    27,    61,   643,   644,    25,    25,    27,    27,   491,
      26,    46,    47,  2016,  1318,   537,   391,  1321,  1322,   236,
     430,    26,  1326,   663,  1328,   190,  1330,    46,    47,    25,
    2953,    27,   624,  2956,  2957,  2958,  2959,   198,   624,  3006,
     190,   202,   460,    26,   190,   429,   366,   457,   458,   458,
    2670,   430,   133,  2673,   646,   647,   474,   643,   644,   581,
     478,    26,  1853,  2189,    25,  2220,    27,   464,   590,  1373,
      26,   492,   490,  1634,   133,   190,  2186,   663,   457,   458,
     501,   531,  1386,   270,    26,   535,   273,   122,   123,   539,
     125,   126,    20,  1397,  1655,   130,  1400,    26,   190,    27,
     457,   458,    20,   122,   123,    26,   125,   126,   295,    27,
     520,   130,   147,   148,    26,  1419,  1420,  1421,   199,   619,
     201,  2273,   190,    25,   545,    27,    63,   548,   147,   148,
     165,    58,  3086,   453,  1745,   216,   287,   288,  3061,   356,
     199,   520,   201,   224,   648,   649,   165,   228,    25,   469,
      27,  1455,  1456,  1457,    24,  1459,    26,   216,   270,  2435,
     557,   273,    24,   275,    26,   224,  2580,  2581,   430,   228,
    2584,   190,   253,  2427,    19,   361,    24,  1366,    26,    24,
      25,    26,  1486,   295,   391,  1489,  1490,   163,   405,   619,
     166,  3037,   512,   305,   253,  2815,   612,   613,   614,   615,
    1504,  2821,  2822,    26,  2824,  2825,  2826,  2827,   430,   425,
     648,   649,   324,  2833,  1918,   191,  3018,   236,  1522,  1143,
     437,  1145,   438,   133,  1528,  1836,  1530,  1531,  1532,  1533,
     430,   546,   552,  3035,   549,   347,   426,   552,     5,   351,
     637,  1736,   429,   108,   109,   110,  2866,  1551,   645,   466,
     466,   391,    62,  2580,  2581,   857,   858,   458,  1562,   861,
     862,   581,  1566,  1761,   619,    26,   482,   483,   366,  1573,
     590,   258,   488,   426,  1885,   491,    20,  1581,   391,  1985,
      26,   361,  2103,  1587,  1588,  1991,  1590,   448,   449,   199,
      26,   201,    26,  3095,   270,   163,    26,   273,   166,     6,
       7,     8,     9,    10,    11,    12,   216,  2013,  1612,  1613,
    3112,    26,    20,   430,   224,    26,    26,   429,   228,   295,
      26,   356,  1626,   191,   619,   135,   136,   391,     5,   239,
     391,   391,  2153,  2953,   302,   391,  2956,  2957,  2958,  2959,
     391,  1645,   391,   253,   391,    34,   623,    36,    37,    38,
       5,   391,  1762,   302,  2631,   453,  1766,   391,   391,   623,
    1664,  1771,   299,   430,   391,  1775,   391,  1777,  1778,  1779,
     405,   469,  2992,  1677,  1678,   619,   458,  1681,   616,   619,
     190,   366,   543,     8,   366,   426,   196,    18,    19,    20,
      21,   478,   553,  1697,   430,  1699,  1700,   525,   430,  1703,
    1704,  2815,   270,   420,   459,   273,   430,  2821,  2822,   430,
    2824,  2825,  2826,  2827,   512,   430,   430,   430,   437,  2833,
     357,   430,   430,   430,  1985,   266,  1730,   295,  2227,  1733,
    1991,   466,   369,  1737,     5,   430,   430,  2440,   430,   430,
    1744,  3061,   379,   617,   430,   617,   430,  1751,   595,  3069,
     430,   430,  2013,   429,   552,   430,   266,   430,   268,   430,
     397,    92,    93,    94,    95,    96,    97,   430,   453,   420,
     407,   453,  2263,   410,  2265,   430,   430,   658,   459,  1783,
     430,   658,  1786,   581,   469,  2501,   423,   469,   326,     8,
     596,  1795,   590,     5,     5,  1799,  1800,  1801,  1802,   383,
    1804,  2300,  2301,  2302,  2303,   430,  1810,  1811,   430,   344,
    1814,  1815,    18,    19,    20,    21,    22,    18,    19,  1823,
     589,   159,   366,    24,    25,    26,    27,   512,   578,  1833,
     512,   430,   342,   430,   471,   430,     8,   175,   176,  2953,
      14,     5,  2956,  2957,  2958,  2959,   184,   658,     5,  1853,
     450,    34,   575,    36,    37,    38,   658,   718,   430,   420,
      26,   429,    65,    64,   501,    26,   430,   552,    91,   458,
     552,   458,    26,   473,   511,  1879,     5,  2283,  2284,   589,
     218,   270,  1886,  1887,   273,  2737,   275,   397,   619,   227,
     430,  1895,   595,  2745,   430,   532,   581,   470,   535,   581,
     537,   430,  1906,   764,    20,   590,   295,  2759,   590,   453,
      20,  2432,  2596,   625,  1918,   430,   305,   517,   256,   430,
       5,   625,  1926,   430,   434,   469,   526,   527,   565,   430,
     530,   661,   625,   366,   534,   324,   536,   574,   366,   556,
     540,  2462,   542,     5,  2334,  2335,  2336,  3061,  2338,  2339,
    2340,  2341,  2342,  2343,   624,  3069,   350,  2347,   347,   469,
      18,    26,   351,   301,    19,   475,    26,   477,   512,   218,
    1974,   481,  2483,   152,   484,    25,  2038,   487,   589,  2490,
     578,   622,  2044,   481,   481,  1989,   619,   497,  1992,   190,
       5,    20,    21,   546,   546,  1999,  2000,  2001,   150,    26,
    2004,   399,  2006,   321,   546,   343,   516,  2710,   552,    26,
    2014,   430,  2016,   523,   524,   525,  2834,   430,   430,   529,
     453,  2025,  2283,  2284,  2219,   453,   430,   537,   430,   663,
     391,   619,   458,   576,   546,   391,   469,   581,   391,   391,
     429,   469,   391,   553,  2048,  2038,   590,  2051,   391,  2053,
      26,  2044,   391,  1590,    20,    21,    22,   391,   391,   430,
     616,  2065,  2914,    92,    93,    94,    95,    96,    97,    35,
    2074,   625,     5,     5,   935,     5,   579,     5,   625,   512,
     619,  2580,  2581,   482,   512,  2584,   391,   270,   430,   430,
     273,   624,   275,  2097,     5,  2099,     8,    26,   535,    26,
      65,   325,     5,  2107,     5,   391,  2110,   430,   430,   360,
    2114,   596,   295,   420,    14,     5,   625,   420,   550,   552,
       5,   546,   305,   100,   552,   659,    92,    93,    94,    95,
      96,    97,    26,   430,   625,   619,   430,   624,     5,   638,
     460,   426,   108,   109,   110,  2149,  2150,   426,   581,   460,
     430,     8,   430,   581,   430,  2159,   430,   590,  2162,     5,
     430,   430,   590,  2167,   347,   430,    26,    26,   351,   589,
     391,  2670,    25,   391,  2673,    25,  2180,    25,  2182,    22,
    2184,   391,  2186,  2886,   784,  2888,    25,   391,  2192,     5,
     619,  2195,    35,     8,   395,     5,  2200,   619,  3050,   553,
    2204,  2205,   619,   325,    25,   344,  2922,   344,   718,   410,
     458,   344,   360,    25,  1751,   430,  2220,   425,  2739,   619,
     458,   430,     5,  2227,    26,  2229,   427,   650,   430,   430,
     430,  2235,  2236,  2237,  2238,  2239,  2240,   430,   430,   430,
     430,     5,   443,     5,    25,  2736,   429,    14,    14,    92,
      93,    94,    95,    96,    97,    26,   616,   430,   595,  2263,
     595,  2265,   619,     5,     7,   108,   109,   110,   619,     5,
       5,   430,   391,     5,   619,   625,   876,  2281,   788,    20,
      21,   482,   483,   249,     8,   391,   252,    26,   888,    26,
    2294,   619,  2477,   893,   495,    26,  2300,  2301,  2302,  2303,
    2304,  2305,   391,  2630,  3021,  3022,  3023,  3024,  3025,  3026,
     625,  2315,  2316,  2317,  2813,    26,  2815,  1178,   391,  2323,
     391,   831,  2821,  2822,   625,  2824,  2825,  2826,  2827,   589,
     391,    20,   391,     5,  2833,   391,   537,   847,   848,   849,
     566,   851,   391,   853,   854,     5,     5,   546,   274,   859,
     860,    92,    93,    94,    95,    96,    97,     5,  1895,   667,
       5,   391,   625,   391,   571,   177,   619,   619,   440,   391,
     470,     6,     5,   430,   210,   576,   553,   623,   625,  3082,
    2384,   625,  2386,  1244,  2905,    25,   623,   588,    25,    25,
     900,   618,  2396,   446,  2398,    25,    25,  2401,    26,   600,
     601,   911,  2406,  2407,  2408,   371,   249,   608,    26,   252,
     611,    26,    26,    26,   430,    26,   470,   430,   619,   296,
     386,    26,     5,   391,   390,   935,   936,   391,  2834,   525,
     268,  2435,   467,     5,   944,  2439,  2440,   430,  1299,   589,
     391,   550,   240,    25,  3160,    26,   426,   391,   391,  2453,
     960,   961,     5,   440,  2953,   344,    20,  2956,  2957,  2958,
    2959,   139,   428,   553,  2001,     5,     5,   430,   430,   430,
     430,  2475,   430,   430,  2478,  2479,   430,    46,    47,  2483,
      14,   619,  2486,   210,     5,   441,  2490,   458,    26,   391,
     456,    26,   304,  2992,   391,   391,   391,     5,   310,   311,
     312,  2505,   368,   618,   331,   430,    30,   391,   474,   373,
      26,   391,  2516,   391,   240,   391,  2053,   568,   330,  2523,
     430,   344,    46,    47,   241,   546,   391,  2531,   371,   391,
    2534,  2535,  2536,  2537,  2538,   458,   391,   625,   575,   391,
     391,  2545,   391,   386,   430,   619,   391,   390,  1148,  1149,
    1150,    14,   239,   122,   123,   239,   125,   126,  2562,     7,
      26,   130,  3061,   391,   447,  2569,    26,   392,  1168,   430,
    3069,   619,   391,  2834,  2578,     5,  2580,  2581,   147,   148,
    2584,   625,   391,   625,   625,   428,   391,     5,   430,   426,
     556,  2595,   391,    25,   241,   391,   165,   391,   122,   123,
     391,   125,   126,   391,   391,     5,   130,   391,    18,    19,
      20,    21,   391,   456,  2618,  2199,  2620,  2107,   430,  3105,
    2149,  1131,  1222,   147,   148,  1261,   438,  1869,  1574,   441,
      38,   474,   366,  1143,    40,  1145,  1146,  1147,  1811,  1817,
     289,   165,  2180,  1243,  1154,  1155,   143,   147,  1158,   211,
     399,   283,  1162,   355,  1365,  1165,   622,   213,  1769,   290,
    1260,    25,  2448,   373,  1366,   318,  2670,   236,  1178,  2673,
    1270,  2675,   484,   317,  2678,    16,    17,    18,    19,    20,
      21,    22,    92,    93,    94,    95,    96,    97,   385,   387,
    3095,  1786,  2229,  1489,    35,   529,   969,  1436,  2235,  2236,
    2237,  2238,  2239,  2240,  1682,  1675,  2710,   519,  1801,  1532,
    2714,  1221,  2716,   556,  1294,  1291,  1604,  2548,  2254,  1922,
    3121,  1164,  1805,  1621,  2753,    25,   120,   539,   540,  1590,
      31,  2652,  2736,  2928,    31,  1579,   487,  2741,   550,   656,
    1585,   268,  1299,   555,  2281,   685,  1256,  1588,  1920,   936,
    2649,    92,    93,    94,    95,    96,    97,    18,    19,    20,
    2851,  1219,  1155,    24,    25,    26,    27,   108,   109,   110,
    1280,  1637,  3112,  2236,  2374,  1285,  2780,  1145,  2861,   622,
     888,  1243,   594,  1072,  2372,  2047,  2356,  1795,  1298,  1299,
    1025,  1985,  3123,  3086,  1403,  1380,  2017,  2974,  2802,  2405,
    2048,  2805,  2441,    64,  1703,  2710,  2386,  2384,  2051,  2813,
    2673,  2815,  2992,   177,   626,  2065,   972,  2821,  2822,  2684,
    2824,  2825,  2826,  2827,  1318,    17,  2830,  2897,  2832,  2833,
    2317,  2835,  2898,   965,  2579,  2295,  1697,  2439,  3084,  2843,
    1313,  2235,  2941,  1704,  1354,  2578,  2813,   961,  1286,  2832,
    2821,  1733,   364,    -1,    39,    40,    41,    42,    43,    44,
    1160,    -1,    -1,    -1,  2401,    -1,    -1,    -1,   437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2886,    -1,  2888,    -1,    -1,  2891,    -1,  1489,
    1751,    -1,  2896,    -1,  2898,    -1,    -1,    -1,    -1,  1409,
      -1,    -1,  2439,    -1,  1504,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1528,   190,
      -1,    -1,  1532,    -1,    -1,    -1,    -1,  2941,    -1,    -1,
     304,    -1,    -1,    -1,    -1,  2949,   310,   311,   312,  2953,
      -1,    -1,  2956,  2957,  2958,  2959,  2960,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   330,    -1,    -1,    -1,
    2974,    -1,    -1,  1573,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2523,    -1,  2992,    -1,
      -1,    -1,  2996,    -1,  2531,    -1,    -1,  2534,  2535,  2536,
    2537,    -1,  3006,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,  1886,  1887,    -1,  3032,  3033,
     371,    -1,    -1,  3037,  1895,  1545,    -1,    35,    -1,    -1,
      -1,    -1,    -1,  1553,    -1,   386,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,  1564,    -1,    -1,  3061,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3069,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   438,  1585,    -1,   441,  3082,    -1,
    3084,    -1,  3086,    -1,    -1,    -1,    -1,   428,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,    -1,    -1,   456,    -1,    -1,    -1,  3123,
     484,  1631,  1632,  1633,    -1,    -1,    -1,  1637,    -1,    -1,
      -1,  1992,    -1,   474,   395,    -1,    -1,  1737,   118,  3143,
    2001,  2678,    -1,    -1,    -1,    -1,    -1,   332,    -1,   410,
      -1,    -1,    -1,    -1,    -1,   519,    -1,    -1,    -1,  1669,
     345,    -1,    -1,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,   539,   540,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   550,    -1,    -1,    -1,
    2051,   555,  2053,    -1,    -1,    -1,  1352,  1353,    -1,  1799,
    1800,  1801,  1802,  1359,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,   482,   483,  1823,   409,  1735,  1736,    -1,    -1,    -1,
     594,   416,    -1,  2094,   495,    -1,    -1,    -1,    -1,    -1,
      -1,   221,    -1,  2780,   724,   725,   726,    -1,    -1,   229,
      -1,   249,    -1,    -1,   252,   235,    -1,   237,    -1,    -1,
     740,    -1,   626,    -1,    -1,  2802,   746,   747,   248,    -1,
     455,   751,    -1,    -1,    -1,    -1,   537,    -1,    -1,  1879,
      -1,   622,    -1,    -1,    -1,    -1,  1796,    -1,  1798,    -1,
      -1,    -1,    -1,    -1,   479,    -1,   276,  1807,    -1,    -1,
      -1,    -1,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,
     495,    -1,   292,    -1,    -1,   576,    -1,   297,    -1,    -1,
     505,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,   309,
      -1,    -1,    -1,    -1,  1844,    -1,   316,    -1,    -1,   600,
     601,    -1,   527,    -1,    -1,   530,   531,   608,    -1,    -1,
     611,   536,    -1,    -1,  2891,    -1,    -1,    -1,   619,    -1,
      -1,    -1,    -1,  1873,    -1,    -1,    -1,    -1,  2229,    -1,
      -1,    -1,    -1,   371,  2235,  2236,  2237,  2238,  2239,  2240,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1556,    -1,    -1,    -1,  2004,    -1,  2006,    -1,   593,  1919,
    1920,    -1,  2949,    -1,    -1,    -1,    -1,    -1,    -1,   604,
    2281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,  2300,
    2301,  2302,  2303,    -1,  1600,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,  2996,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2334,  2335,  2336,   474,  2338,  2339,  2340,
    2341,  2342,  2343,    -1,    -1,    -1,  2347,    -1,    -1,    -1,
     470,    92,    93,    94,    95,    96,    97,   477,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,  2024,    -1,    -1,    -1,    -1,   499,
      -1,    -1,    -1,  2384,   504,  2386,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,  2396,    -1,  2398,     5,    -1,
    2401,    -1,    -1,    -1,    -1,    -1,    -1,  3084,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,  2159,
      -1,  1041,  2162,    -1,    -1,    -1,    -1,    -1,  1048,    64,
      -1,  1051,    -1,    -1,    -1,    -1,    -1,    -1,  2439,    -1,
      -1,    -1,    -1,    -1,  1064,    -1,  3123,    -1,  1068,    -1,
      -1,    -1,    -1,  2103,    -1,    -1,  1076,    -1,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,    -1,    -1,
    2220,    -1,    -1,    -1,   622,    -1,    -1,    -1,  1108,  1109,
      -1,    -1,    -1,  1113,    -1,  1115,    -1,    -1,    -1,    -1,
    2501,    -1,    -1,  2153,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2523,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2531,    -1,    -1,  2534,  2535,  2536,  2537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2197,    -1,  2199,
      -1,  2201,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2214,    -1,    -1,  1863,  1864,  2219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1874,  2580,
    2581,    -1,    -1,  2584,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,  2275,  2276,    -1,    -1,    -1,
     371,  1927,  1928,  1929,  1930,    -1,    -1,    -1,    -1,  1935,
    1936,  1937,  1938,    -1,    -1,   386,  1942,    -1,    -1,   390,
      -1,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2318,  2670,
      -1,    -1,  2673,    -1,  2675,    -1,    -1,  2678,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,   428,    -1,    -1,
      -1,    -1,   299,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2358,    -1,
      -1,   318,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,  2371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2026,  2027,    -1,   474,    -1,    -1,    -1,  2033,  2034,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2486,    -1,    -1,    -1,
     357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     395,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,    -1,    -1,   410,  2516,    -1,    -1,  2780,
      -1,    -1,  2432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,    -1,
     407,  2802,    -1,    -1,    -1,  2545,    -1,    -1,   443,    -1,
      -1,    -1,  2462,    -1,  2815,   556,   423,    -1,    -1,    -1,
    2821,  2822,    -1,  2824,  2825,  2826,  2827,  2477,    -1,    -1,
      -1,    -1,  2833,    -1,  2835,  1455,  1456,  1457,   249,  1459,
      -1,   252,  2492,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,  2501,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,  2866,  1486,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2170,  2171,    -1,    -1,    -1,   486,
      -1,   622,    -1,  2179,    -1,    -1,    -1,    -1,    -1,    -1,
    2891,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,
      -1,   508,   537,    23,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2208,  2209,    34,    -1,    36,    37,    38,    -1,
      -1,  2922,    -1,    -1,    -1,   532,    -1,    -1,   535,    -1,
     537,  1551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   576,    62,    -1,    -1,    -1,  1566,    -1,  2949,   556,
      -1,    -1,  2953,   588,    -1,  2956,  2957,  2958,  2959,    -1,
     371,    -1,    -1,    -1,    -1,   600,   601,   574,  2264,    -1,
    2266,    91,    -1,   608,    -1,   386,   611,    -1,    -1,   390,
      -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,    -1,
      -1,  2992,    -1,    -1,    -1,  2996,    -1,    -1,    -1,  2649,
      -1,  2741,    -1,    -1,    -1,  3006,    -1,    -1,    -1,     9,
      -1,    -1,    -1,   133,    -1,    -1,    -1,   428,    18,    19,
      20,    -1,    -1,    -1,    24,    25,    26,    27,  2324,  2325,
      -1,    -1,  2328,  2329,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,   456,   166,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
    3061,    -1,    -1,   474,    64,    -1,  2362,    -1,  3069,    35,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,    -1,  3084,    -1,    -1,    -1,    -1,    -1,  2739,
     210,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,   234,    -1,    -1,    -1,   238,   239,
     240,   241,  3123,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   556,  2796,    -1,    -1,    -1,
     270,    -1,    -1,   273,    -1,   275,    -1,    -1,    -1,  3160,
      -1,    -1,   282,  1783,    -1,    -1,  1786,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,
    2476,    -1,    -1,    -1,  2480,   305,    -1,  2837,    -1,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,  2493,    -1,    -1,
      -1,  2851,    -1,    -1,   324,   325,  2856,    -1,  2858,    -1,
      -1,   622,    -1,    -1,    -1,    -1,  2512,    -1,    -1,   339,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,
      -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     360,   361,   362,    -1,    -1,    -1,    -1,  2897,    -1,    -1,
    2546,    -1,    -1,    -1,    -1,  2905,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,  2922,    -1,    -1,    -1,    -1,    -1,  2928,    -1,
      35,    -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,  3032,    -1,   294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   429,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     440,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3021,  3022,  3023,  3024,  3025,  3026,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3143,    -1,   371,    -1,    -1,    -1,    -1,
     410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,   542,    -1,   390,    -1,    -1,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   442,   443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,
      -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,    -1,    -1,    -1,    -1,  2771,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,    -1,   249,   495,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,   474,    -1,
    3160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   638,   639,
     640,   641,   642,   643,   644,    -1,   646,   647,    -1,  2149,
    2150,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    74,    -1,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,  2192,    -1,    -1,  2195,   576,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2204,  2205,    -1,    -1,   588,    -1,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,
      -1,   611,    -1,    -1,    -1,    -1,   371,    -1,    -1,   619,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2926,   386,    -1,    -1,    -1,   390,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    35,    -1,    -1,    -1,
      -1,   184,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2979,  2980,    -1,  2982,    -1,  2984,  2985,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   456,    -1,    -1,    -1,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,   474,
      -1,    30,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,   108,
     109,   110,    -1,   256,   257,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3049,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,  3073,    -1,  3075,
      -1,    90,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,
      -1,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,   138,
     343,    -1,   141,  2453,   143,   144,   145,    -1,   147,   148,
      -1,  3137,  3138,    -1,   153,  3141,   155,   156,  3144,   158,
      -1,   160,   161,    -1,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,   172,   173,    -1,    -1,   622,   177,   178,
     179,    -1,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
     249,    -1,    -1,   252,   193,  2505,   399,    -1,   197,    -1,
      -1,   200,    -1,   202,    -1,   204,    -1,   206,    -1,   208,
     209,    -1,   211,   212,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,   246,   247,    -1,
      -1,   250,   251,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   264,   265,    -1,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,
     279,    -1,   281,    -1,    -1,    -1,   285,   286,    -1,    -1,
      -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,   307,   308,
      -1,    -1,   371,    -1,    -1,   314,   315,    -1,    -1,    -1,
      -1,   320,    -1,    -1,   323,    -1,    -1,   386,   327,   328,
      -1,   390,   391,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,   428,
      -1,   370,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   393,    -1,    -1,   456,    -1,    -1,
      -1,   400,    -1,   402,   403,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   411,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,    92,    93,    94,    95,    96,    97,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,   493,    -1,    -1,   556,   497,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,   515,   516,   517,   518,
      -1,    -1,    -1,   522,    -1,    -1,    -1,   526,    -1,    -1,
      -1,    -1,    18,    19,   533,   534,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,   545,    -1,   547,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   558,
      -1,   560,    -1,   622,   563,    -1,    -1,    -1,    -1,    -1,
     569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   595,    -1,    -1,   598,
      -1,    -1,    -1,    -1,   603,    -1,    -1,   606,   607,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,   621,   252,    -1,    -1,    -1,    -1,    -1,   628,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,   651,   652,   653,   654,   655,   656,   657,    35,
      -1,   660,    -1,   662,    -1,   664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,  3037,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,   391,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    35,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,   395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,   252,   410,    -1,    -1,   556,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,   427,    -1,    -1,   430,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,   371,    -1,   483,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     386,    -1,    -1,    -1,   390,   391,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,   249,    -1,    35,   252,    -1,    -1,
      -1,   537,   428,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     576,    -1,   252,    -1,    -1,    -1,    -1,    -1,   474,   428,
      -1,    -1,   588,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,   600,   601,    -1,    -1,    -1,   108,
     109,   110,   608,    -1,    -1,   611,    -1,   456,    -1,    -1,
      -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,   371,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
     556,   386,    -1,    -1,    -1,   390,   391,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,   386,   556,    -1,    -1,
     390,   391,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,   108,   109,
     110,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,   428,   474,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,   456,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,    -1,    -1,    -1,   556,   386,    -1,    -1,
      -1,   390,   391,    92,    93,    94,    95,    96,    97,    15,
      16,    17,    18,    19,    20,    21,    22,   622,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,   456,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   474,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,   371,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
     390,   391,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    92,    93,    94,    95,    96,    97,
     249,    -1,    -1,   252,    35,    -1,    -1,   556,   428,    -1,
     108,   109,   110,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,   371,    -1,   108,   109,   110,
      -1,    -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   390,    -1,    -1,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,    -1,    -1,    -1,   556,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
     456,    -1,    -1,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   474,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,   371,    -1,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
     386,   252,    -1,    -1,   390,   474,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    35,   249,    -1,    -1,   252,    -1,
     556,    -1,   428,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,
     456,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,   474,    -1,
      -1,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,   622,   108,   109,   110,
     428,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    18,    19,   441,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   386,    -1,    -1,   456,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,   474,   371,    -1,    98,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
     556,    -1,   386,    -1,    71,    -1,   390,   428,    -1,    -1,
      -1,    -1,    -1,    -1,   249,    -1,    -1,   252,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    99,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,   556,    -1,
      -1,    -1,   456,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    92,
      93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   622,   556,   371,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     259,   386,     9,    -1,    -1,   390,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,   556,    -1,    -1,   284,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
     371,   622,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,   386,    -1,    -1,    -1,   390,
     329,   456,   289,   332,    -1,    -1,    -1,   294,   337,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,   622,   474,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   322,   249,   428,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    18,    19,
     357,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
     409,    -1,   369,   474,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     387,   556,   431,    -1,    -1,   392,    -1,    -1,   395,    59,
      -1,    -1,    -1,   190,    64,   192,    -1,    -1,    -1,   406,
      -1,    71,    -1,    -1,    -1,   412,   455,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,
     427,    -1,    -1,   430,    -1,    -1,   433,    -1,    -1,    99,
     479,    -1,    -1,    -1,    -1,   442,   443,    -1,   371,    -1,
     489,   490,    -1,    -1,    -1,   556,   495,   622,    -1,    -1,
      -1,    -1,    -1,   386,    -1,    -1,   505,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   482,   483,    -1,   527,    -1,
     487,   530,   531,    -1,    -1,    -1,    -1,   536,   495,    -1,
      -1,    -1,   289,    -1,    -1,   428,    -1,   294,    -1,   506,
      -1,    -1,    -1,    -1,    -1,   512,    -1,    -1,   441,    -1,
      -1,   622,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   192,   456,    -1,   322,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,   593,    -1,    -1,    -1,    -1,     9,
      -1,    -1,   299,   602,    -1,   604,    -1,    -1,    18,    19,
     357,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,   318,   369,    -1,   581,    -1,    -1,    -1,    -1,    -1,
      -1,   588,    -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,
     387,    -1,    -1,   600,   601,   392,    -1,    -1,   395,    59,
      -1,   608,    -1,    -1,    64,    -1,    -1,    -1,    -1,   406,
     357,    71,   619,    -1,    -1,   412,    -1,    -1,    -1,   289,
      -1,    -1,   369,   556,   294,   422,    -1,    -1,    -1,    -1,
     427,    -1,   379,   430,    -1,    -1,   433,    -1,     9,    99,
      -1,    -1,    -1,    -1,    -1,   442,   443,    18,    19,    20,
     397,    -1,   322,    24,    25,    26,    27,    -1,    -1,    -1,
     407,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   483,   357,    -1,   622,
     487,    -1,    -1,    64,    -1,    -1,    -1,    -1,   495,   369,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,    -1,   506,
      -1,   508,    -1,    -1,    -1,   512,   463,   387,    -1,    -1,
      -1,    -1,   392,    -1,    -1,   395,    -1,    -1,    -1,    -1,
     190,    -1,   192,    -1,    -1,    -1,   406,    -1,    -1,   486,
     537,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   422,    -1,   501,    -1,    -1,   427,    -1,    -1,
     430,   508,    -1,   433,   511,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   442,   443,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,   581,   532,    -1,    -1,   535,    -1,
     537,   588,    -1,   590,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   600,   601,    -1,    -1,    -1,    -1,   556,
      -1,   608,   482,   483,    -1,    -1,    -1,   487,    -1,   190,
      -1,    -1,   619,    -1,    -1,   495,    -1,   574,    -1,   289,
      -1,    -1,    -1,   190,   294,    -1,   506,    -1,    -1,    -1,
      -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,   322,    -1,    -1,    -1,    -1,   537,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    17,    18,    19,    20,    21,    22,    -1,    -1,   369,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,    35,
     590,    -1,    -1,   294,    -1,    64,    -1,   387,    -1,    -1,
     600,   601,   392,    -1,    -1,   395,    -1,   294,   608,    18,
      19,    20,    21,    22,    -1,    -1,   406,    -1,    -1,   619,
      -1,    -1,   412,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   422,    -1,    -1,    -1,    -1,   427,    -1,    -1,
     430,    -1,    -1,   433,    -1,    -1,    92,    93,    94,    95,
      96,    97,   442,   443,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,   249,
      -1,    -1,   252,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,   483,   395,    -1,    -1,   487,    -1,   108,
     109,   110,    -1,    -1,    -1,   495,    -1,    -1,   395,   410,
      -1,    -1,    -1,    -1,    -1,    64,   506,    -1,    -1,    -1,
      -1,   190,   512,   410,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     427,   442,   443,   430,    18,    19,    20,   537,    -1,    -1,
      24,    25,    26,    27,    -1,   442,   443,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,   581,    -1,    -1,   495,    -1,   483,    -1,   588,    -1,
     590,   371,    -1,   249,   128,    -1,   252,    -1,   495,    -1,
     600,   601,    64,   137,    -1,    32,   386,    -1,   608,    -1,
     390,    -1,   146,    -1,    -1,    -1,    20,   151,    -1,   619,
      24,    25,    26,    27,    -1,    -1,   537,    -1,    -1,    -1,
     249,   190,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    79,    80,    -1,    -1,    -1,    -1,    -1,    -1,
      64,   195,    89,    -1,    -1,   576,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,   456,   588,    -1,   576,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,
     601,   588,    -1,    -1,   474,    -1,    -1,   608,    -1,    -1,
     611,    -1,    -1,   600,   601,    -1,   190,    -1,   619,    -1,
      -1,   608,    -1,    -1,   611,   371,   395,    -1,    -1,    -1,
      -1,    -1,   619,    -1,    -1,   259,    -1,    -1,   190,    -1,
     386,   410,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
     284,   430,   371,    -1,    -1,    -1,    -1,   291,    -1,   293,
      -1,    -1,    -1,    -1,   443,    -1,    -1,   386,    -1,   303,
      -1,   390,   428,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,   329,    -1,    -1,    -1,    -1,
     456,    -1,    -1,   337,   483,    -1,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,   495,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,    -1,   395,   456,    -1,    -1,
     374,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   410,    -1,    -1,    -1,   474,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   400,    -1,   427,    -1,
      -1,   430,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,
      -1,   318,    -1,    -1,    -1,    -1,    -1,   576,    -1,    -1,
     556,    -1,    -1,    -1,   438,    -1,    -1,   334,    -1,   588,
      -1,   395,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,
      -1,   600,   601,   482,   483,    -1,   410,    -1,    -1,   608,
     357,    -1,   611,   395,    -1,    -1,   495,   556,    -1,    -1,
     619,    -1,   369,   427,    -1,    -1,   430,    -1,   410,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,    -1,   443,
      -1,    -1,    -1,    -1,    -1,   427,   622,    -1,   430,    -1,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
     407,   443,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,    -1,    -1,    -1,    -1,   423,    -1,    -1,   483,
      -1,    -1,    -1,   622,    -1,    -1,   410,    -1,    -1,    -1,
      -1,   495,    -1,    -1,   548,   549,   550,   576,    -1,    -1,
      -1,   483,    -1,   427,    -1,    -1,   430,   561,    -1,   588,
      -1,    -1,    -1,   495,    -1,    -1,   463,    -1,    -1,   443,
      -1,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,   611,   537,    -1,    -1,    -1,    -1,    -1,   486,
     619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   501,   537,    -1,    -1,    -1,   483,
      -1,   508,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   588,   532,    -1,    -1,   535,    -1,
     537,    -1,    -1,    -1,   576,    -1,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,   588,   611,    -1,   556,
     664,    -1,    -1,   537,    -1,   619,    -1,    -1,   600,   601,
      -1,    -1,    -1,    -1,    -1,    -1,   608,   574,    -1,   611,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,    -1,    -1,    -1,   616,
      -1,    -1,    -1,    -1,    -1,    -1,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,    -1,   611,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   619
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   236,   356,   405,   437,   466,   726,   754,
     755,   805,   972,  1025,  1027,  1028,  1029,  1034,  1036,  1049,
    1050,  1051,  1052,  1053,  1469,    28,    29,   727,   728,   729,
     730,   731,    27,   938,  1488,   355,   533,   547,   572,   620,
    1470,  1470,  1470,  1470,  1470,  1470,  1470,  1470,   938,    25,
     938,  1390,  1054,   756,  1390,   755,  1469,     0,  1026,  1029,
    1034,  1052,  1469,    31,   729,   731,   938,  1472,   589,   938,
    1471,   625,   806,    25,   190,   753,   754,   926,   938,   943,
    1055,  1090,  1091,  1092,  1093,  1094,  1098,   353,   758,   759,
     760,   761,   764,   765,    55,    60,   105,   106,   113,   367,
     393,   464,   557,   637,   645,   726,   732,   898,   971,  1030,
    1031,  1033,  1037,  1038,  1044,  1056,  1077,  1210,  1220,  1469,
     938,  1471,   616,  1093,   242,   457,   458,  1100,    20,   938,
    1097,   619,   759,     5,   757,   353,   938,     5,   781,   783,
     784,   938,  1221,   938,   938,  1211,  1045,   938,   938,  1033,
    1039,   260,   299,   318,   357,   369,   379,   397,   407,   423,
     463,   486,   501,   508,   511,   532,   535,   537,   556,   574,
     807,   808,   809,   812,    25,  1090,  1096,    18,    19,    26,
     430,   676,   678,  1090,  1101,  1102,   458,    14,   804,   761,
     521,  1197,   762,   759,   764,    32,    79,    80,    89,   260,
     299,   318,   334,   357,   369,   379,   397,   407,   423,   463,
     486,   501,   508,   511,   532,   535,   537,   556,   574,   616,
     767,   775,   786,   787,   938,   430,   112,   938,   753,   899,
    1078,   938,   814,   535,   766,   790,   792,   793,   791,   800,
     801,   430,   430,   813,   458,   430,   430,   759,   788,   425,
     676,    18,    19,    20,    21,    22,   677,    26,     5,   426,
    1101,    24,    25,    26,   619,   938,   944,    19,    25,    26,
     763,   944,   777,   766,   778,   790,   791,   430,   430,   776,
     458,   430,   430,   788,   759,   785,   430,    26,   938,   430,
    1046,   753,   753,   430,   938,   430,   457,   770,   625,   366,
     453,   469,   512,   552,   581,   590,   794,   625,   366,   453,
     469,   512,   552,   581,   590,   802,    26,    26,   815,   816,
     817,   818,   938,    26,   773,   774,    26,    26,   619,   391,
     676,  1102,   458,   426,    26,    26,   759,   770,   759,    26,
      26,   758,   773,    26,    26,   619,    58,   782,  1222,   391,
     430,  1212,  1489,  1490,  1491,  1492,  1493,   900,  1079,  1040,
     619,    26,   795,   796,   430,   797,   802,   803,   797,   430,
     798,     5,   391,     5,   391,     5,   283,     5,   807,   426,
       5,     5,   391,   391,   759,   789,  1101,   458,   619,    26,
     258,     5,   391,     5,   391,   283,   426,     5,   391,   391,
     789,   938,  1107,  1108,  1110,  1057,  1107,   361,  1490,  1197,
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
     657,   660,   662,   664,   669,   670,   671,   672,   689,   711,
     725,   726,   732,   733,   752,   820,   821,   822,   823,   834,
     835,   836,   837,   889,   893,   924,   945,   946,   949,   950,
     951,   952,   965,   973,   994,   995,   997,  1001,  1016,  1017,
    1021,  1022,  1023,  1024,  1032,  1047,  1060,  1071,  1072,  1073,
    1084,  1087,  1123,  1126,  1128,  1134,  1135,  1138,  1141,  1144,
    1146,  1148,  1151,  1158,  1163,  1167,  1168,  1169,  1181,  1182,
    1185,  1191,  1192,  1193,  1218,  1233,  1234,  1235,  1236,  1237,
    1242,  1248,  1249,  1267,  1270,  1300,  1302,  1391,  1392,  1423,
    1424,  1431,  1442,  1469,  1473,  1478,  1480,  1482,  1486,  1487,
    1494,   726,  1035,  1469,   624,   647,  1080,  1081,  1107,    20,
     391,   425,   771,   794,    26,   799,    26,    26,    26,   816,
     818,   810,   774,    26,   426,  1101,    20,   771,   430,    26,
      26,   768,    26,   619,   391,     5,  1107,   391,   938,   349,
     939,   940,  1488,   938,   938,  1165,   933,   939,   933,    25,
     190,   938,  1099,  1464,  1465,  1466,   938,  1484,   938,  1244,
    1245,   938,    26,   673,  1090,  1240,   933,  1165,   863,    26,
     944,  1205,  1206,  1205,     9,    18,    19,    25,    26,    59,
      64,    71,    99,   192,   289,   294,   322,   357,   369,   387,
     392,   395,   406,   412,   422,   427,   430,   433,   442,   443,
     483,   487,   495,   506,   512,   537,   581,   588,   590,   600,
     601,   608,   838,   845,   846,   847,   848,   849,   850,   851,
     852,   864,   869,   880,   881,   882,   883,   938,   944,  1090,
    1200,  1269,  1382,   840,   863,   939,  1432,  1432,   824,  1165,
     933,  1238,  1090,   935,   939,   845,  1432,  1090,  1165,  1090,
    1268,  1432,    25,   585,  1074,  1075,  1090,   933,   933,  1074,
     934,   939,   938,  1075,   933,  1432,   933,   935,  1090,  1121,
    1122,   931,   939,   935,   374,   561,   666,   930,   938,   996,
     938,   734,   936,   939,    25,  1301,  1464,   863,   863,   939,
    1147,   894,   128,   137,   146,   151,   195,   203,   259,   284,
     291,   293,   303,   329,   337,   374,   400,   438,   449,   548,
     549,   550,   561,   664,  1010,  1142,  1143,  1090,   844,   845,
    1157,   930,  1479,  1479,   932,   939,   863,    25,  1090,  1145,
    1219,  1090,  1196,    25,  1090,  1426,   845,  1187,  1188,  1189,
    1198,  1199,   845,  1474,   104,   154,   192,   289,   365,   406,
     473,   537,   690,   869,   938,  1090,  1228,   713,   845,   931,
    1471,  1061,   845,   931,   845,  1090,  1018,   931,   845,  1443,
     845,  1205,   938,   947,   948,   935,   947,  1479,   935,   947,
    1479,   953,   947,    25,    26,   384,   486,   944,   999,  1090,
    1109,  1111,    65,   274,   344,   389,   568,   648,   649,   650,
     659,   680,   955,   957,   959,   961,   963,  1085,  1086,  1089,
     335,   346,   398,   413,   502,  1303,   639,   640,   902,   903,
     904,   938,  1082,   646,  1081,   391,   302,   391,   391,   391,
     391,   623,     5,   391,   426,   302,   759,   779,   780,   391,
     391,   623,   391,   938,  1223,  1110,   391,  1213,    56,    57,
      84,    85,    86,   454,   541,   584,  1250,  1251,  1252,  1255,
    1258,  1261,  1262,  1263,  1264,   430,   619,  1466,  1100,   616,
    1139,   619,     8,   538,   587,     5,   391,   426,    25,   938,
    1375,   478,  1166,  1109,   108,   109,   110,   838,   838,   838,
     430,   525,  1217,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   838,   366,   453,   469,   512,   552,   581,   590,
    1385,  1386,   430,   430,   430,   838,   838,   430,   430,   750,
     838,   430,   853,   430,   430,   430,   430,   430,   430,   430,
     430,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    35,    92,    93,
      94,    95,    96,    97,   108,   109,   110,   249,   252,   371,
     386,   390,   428,   456,   474,   556,   622,   749,   839,   854,
     856,   857,   858,   859,   860,   861,   862,    26,   944,   430,
     520,   420,   482,   841,   842,   845,  1090,  1116,  1375,   679,
     680,   827,   266,    87,    88,   625,   459,     5,   618,   625,
     617,   617,  1124,   595,   420,     5,   556,   974,   459,   658,
    1476,   430,   458,   619,   658,   384,   736,  1090,   546,   617,
    1129,  1130,  1131,   326,  1299,   843,   845,   843,     8,   932,
      26,   500,   554,   925,  1090,   925,   925,   925,    25,   177,
     304,   310,   311,   312,   330,   438,   441,   484,   519,   539,
     540,   550,   555,   594,   626,  1014,  1015,   925,   925,   596,
    1011,   680,  1011,  1011,   926,   926,  1011,  1011,   680,     5,
     333,   385,     5,   679,     5,    81,    82,   539,   626,  1002,
     661,  1477,   844,   612,   613,   614,   615,  1195,  1197,   383,
    1232,  1197,  1189,     5,   617,  1190,   845,   430,   430,   430,
     430,    25,   709,   938,   430,  1426,   344,   430,   520,   589,
     578,   714,   721,   712,    25,  1076,  1090,  1183,     8,  1186,
      14,   938,  1095,  1103,  1104,  1106,  1114,  1115,  1159,   162,
     344,   544,   577,    33,   190,   553,  1444,  1445,  1446,  1447,
     575,     5,   658,   658,   843,  1109,  1116,   998,   420,     5,
     150,   978,   430,  1090,   843,   430,    26,    26,    65,  1088,
      25,  1090,  1430,  1430,   939,  1283,  1147,   932,   118,   221,
     229,   235,   237,   248,   276,   292,   297,   309,   316,   470,
     477,   499,   504,  1271,  1272,  1280,  1290,  1291,  1297,  1298,
    1304,  1305,  1314,  1333,  1337,  1402,  1403,  1433,  1434,  1437,
    1438,  1448,   905,   906,    91,   901,   912,   913,   904,  1083,
    1489,  1041,   458,   807,   774,   458,     5,   391,   781,   753,
    1058,   753,   157,   296,   372,   430,   475,   491,  1320,  1332,
     430,   938,  1266,    26,   245,   258,   430,   475,   491,   938,
    1247,  1260,  1318,  1319,  1324,  1326,  1328,   430,   938,  1257,
     430,  1247,  1253,     5,    25,   941,  1093,  1466,  1464,   576,
     616,  1140,    20,   938,  1120,  1467,   938,  1485,  1245,   595,
     619,   589,   430,   430,   827,  1479,   838,   930,   930,  1479,
    1479,   470,  1406,   838,    25,    26,    19,    24,    25,    26,
     884,   885,   886,   887,   838,   430,   625,  1479,    20,   838,
     391,  1406,   838,    20,  1200,   872,   870,   876,   838,   874,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   430,   838,   838,   430,   865,   938,  1090,     5,
     625,   430,  1464,    25,   943,  1164,  1164,  1426,  1074,   845,
     845,   845,   927,   928,   430,  1090,  1122,   788,   975,   976,
     625,  1426,  1479,  1477,   938,   676,    20,   666,   938,   996,
    1090,   735,   624,   845,   350,  1133,   556,  1132,     5,    68,
      70,    72,   617,   625,   819,  1109,   895,    18,    19,   430,
    1012,  1014,  1143,   926,   845,   344,   595,   930,    26,    26,
     679,   152,  1194,   218,  1199,  1205,  1475,   938,    25,   888,
     930,  1479,   589,   930,   622,  1090,   694,   938,   938,   845,
     339,   717,   721,   578,   715,   723,    23,   234,  1063,  1067,
     481,   863,   481,  1184,   845,   457,  1100,   619,     5,  1019,
     546,  1160,  1090,  1465,  1468,  1090,  1112,  1113,   189,  1445,
     966,   948,  1479,  1479,   958,   959,   978,   978,    34,    36,
      37,    38,   270,   273,   275,   295,   305,   347,   351,   429,
     977,   979,   980,  1006,  1090,  1111,   546,   681,    26,   399,
     964,   321,  1425,  1425,   135,   136,   436,   546,   938,  1334,
    1335,  1376,   788,  1375,  1375,  1273,   788,   938,  1435,  1435,
     359,   475,   585,  1414,  1375,  1281,   167,   438,   449,   470,
     477,  1307,  1308,  1309,   287,   288,  1397,  1489,  1489,   384,
     914,  1090,   641,   642,   907,   908,   909,   480,   624,   643,
     644,   663,   917,   918,  1489,   753,    26,   772,   772,   780,
    1224,   753,  1214,  1322,  1375,  1265,  1332,   430,  1265,   430,
     430,  1259,  1260,   430,   430,    63,   299,   357,   369,   379,
     397,   407,   410,   423,   471,   501,   511,   532,   535,   537,
     565,   574,  1367,  1368,  1369,  1371,  1256,  1257,  1253,  1254,
     663,  1251,   391,   619,  1426,   576,   458,   546,  1483,   674,
     675,   938,   938,   938,  1241,   863,   391,   391,   391,   391,
     391,  1414,   391,   391,   391,   391,   589,   885,    19,    26,
     589,   391,   391,    26,  1386,   391,   391,   391,   391,     5,
     751,   391,   838,   838,   838,   391,   838,   391,   391,   391,
     441,   441,   441,   863,  1406,   441,   863,  1406,   706,   707,
     708,   838,   430,   841,   938,  1239,   616,  1136,   625,     5,
       5,     5,   579,   845,   619,     5,   482,   625,   391,   426,
     430,   624,   163,   166,   270,   273,   737,   740,   741,  1006,
     738,   739,   938,   430,   939,   648,   649,  1137,   845,   938,
     938,   928,   929,   508,  1479,   827,     8,   897,    26,    26,
    1013,  1014,  1090,   535,  1152,    65,   838,  1197,    26,  1090,
    1489,     5,     5,     5,   391,   391,   710,   938,   391,  1426,
     706,   430,   430,   722,   718,   360,   716,   845,   339,   719,
     723,   596,  1008,  1068,  1064,   362,  1062,  1063,   843,   625,
    1096,    20,   938,  1105,  1115,    14,    18,    19,    20,    25,
      26,    64,   395,   410,   427,   430,   443,   482,   483,   495,
     537,   576,   588,   600,   601,   608,   611,   938,   944,  1161,
    1162,  1381,  1383,  1413,  1418,  1419,  1420,  1468,   420,   420,
       5,  1489,   960,   961,   550,   937,   546,   989,   988,   991,
     990,   930,   992,   930,   993,   987,   986,   984,   983,  1007,
     324,   980,   985,  1479,    39,    40,    41,    42,    43,    44,
      98,   332,   345,   409,   416,   455,   479,   489,   490,   495,
     505,   527,   530,   531,   536,   593,   604,   682,   683,  1004,
    1005,     5,    26,  1426,   248,  1090,   470,  1407,  1408,  1426,
    1147,  1401,  1403,   100,   100,   595,  1145,  1336,  1337,   430,
    1315,   149,   525,  1341,  1348,  1375,   174,   271,  1439,   619,
     625,  1404,  1449,   341,   350,   374,   377,   395,   500,   554,
     561,   932,  1284,  1289,   430,  1310,   624,     5,    25,   938,
    1398,  1399,   916,  1090,     5,   546,   910,   911,   638,   909,
     915,   938,   915,   919,   920,   915,   324,   918,  1042,   426,
     426,   460,  1207,  1227,  1059,   460,  1170,  1201,   430,     5,
     391,     9,   294,   430,   442,  1351,  1352,  1353,  1354,  1355,
    1359,  1363,  1365,  1418,   391,   611,   938,  1321,  1323,  1375,
    1378,  1379,  1325,  1378,     5,   391,  1325,  1351,   366,   453,
     469,   512,   552,   581,   590,  1388,  1388,   430,   430,   430,
     430,   430,   430,   207,   399,  1327,  1329,     5,   391,     5,
     391,   938,  1467,     8,  1426,  1101,   845,     5,  1246,  1247,
     863,  1048,  1415,  1416,  1418,   878,  1386,   878,    26,    26,
     589,    24,    26,   791,   879,  1217,   391,  1217,   792,   391,
    1217,   873,   871,   877,  1217,   875,  1217,  1217,  1217,    25,
      25,    25,   838,   855,   391,    25,   855,   391,   866,     5,
     867,   619,  1246,   576,  1426,  1426,   845,   845,   927,   508,
     845,  1481,     5,    20,  1378,   976,  1426,   619,   938,   738,
     746,   745,   747,   938,   942,   748,   942,   191,   741,   744,
       5,   978,   619,   845,     8,   938,   863,   553,  1287,     5,
     391,  1090,     5,   325,    25,  1229,   930,   344,   344,   458,
     619,   344,   430,   695,   699,   692,  1489,  1489,   724,   720,
     716,  1009,    25,   937,  1069,  1090,  1489,   845,   425,   458,
     863,  1419,  1419,  1384,  1388,   470,  1418,   430,   430,   430,
     430,   430,   430,   430,   938,   430,     5,    18,    19,    20,
      21,    92,    93,    94,    95,    96,    97,  1440,  1465,  1090,
    1113,    62,   542,   967,   962,   963,    26,   679,   938,  1489,
    1489,  1489,  1489,     5,   981,     5,   982,  1489,  1489,  1489,
    1489,  1012,  1489,   937,    25,    14,    14,     5,   391,    26,
    1375,  1414,  1395,   595,   595,  1272,  1400,  1401,  1337,  1316,
    1378,   616,   932,  1351,   430,  1276,   938,  1436,  1435,  1415,
      48,    49,    50,    51,    52,   583,  1452,   845,   845,  1282,
     932,  1311,  1378,  1375,  1309,   619,   619,     5,     5,  1090,
     915,  1489,  1489,     5,   922,   923,  1489,  1489,   921,  1035,
     811,   769,    73,    74,    76,    77,    78,   176,   184,   218,
     227,   256,   257,   301,   343,   399,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,  1204,  1208,   134,   513,
    1209,  1225,  1035,   159,   175,   176,   184,   218,   227,   256,
     301,   343,  1202,  1203,  1215,  1209,  1323,  1332,  1354,   430,
    1413,  1351,  1418,  1413,     6,   391,     7,     9,    10,    12,
      13,    14,    15,    16,    17,   252,   371,   428,   556,   622,
    1362,  1364,  1379,   458,  1377,   391,     5,   619,     5,   391,
    1260,   391,   391,   625,   430,   625,    26,  1373,  1373,    26,
    1373,  1373,    26,  1372,    25,  1381,  1330,  1331,  1332,  1257,
    1253,  1426,     8,   426,   675,     5,   391,   843,   391,     5,
     546,  1342,  1347,   938,   625,   391,    26,   589,   625,   391,
     391,   391,   391,     5,   391,   391,   391,   708,   706,    20,
     391,  1426,     5,   845,   566,   274,   684,   685,   845,    20,
     938,   391,   978,  1489,  1489,     5,   742,   458,   619,     5,
     743,  1489,   739,   546,    20,   938,     5,   938,  1127,   389,
     658,   843,  1288,   896,  1014,   667,  1150,   838,     5,   706,
    1090,   691,   673,   938,  1090,   697,   391,   706,   706,  1489,
    1489,  1012,  1066,    25,  1070,  1090,   571,   892,  1101,   482,
     844,  1020,   625,  1414,   391,   395,  1441,  1468,   359,   475,
     585,  1366,  1418,  1421,  1366,  1366,  1366,  1366,   619,  1421,
    1162,  1418,  1418,  1418,  1418,   969,   968,   440,   954,   955,
     619,   930,  1489,   930,  1489,   679,    26,  1090,    26,  1090,
     683,   391,   430,  1427,  1415,  1397,  1401,  1401,  1393,     5,
     391,   470,  1412,  1277,  1378,   478,  1274,  1412,   625,  1405,
      18,    19,    64,   427,   430,   443,   482,   483,   495,   537,
     576,   588,   600,   601,   608,   611,   938,  1381,  1413,  1457,
    1458,  1459,  1460,  1461,  1462,  1468,  1457,  1457,  1457,  1378,
    1454,  1456,  1453,  1454,  1455,  1450,   553,  1285,     5,   391,
     625,   938,   938,  1399,  1090,   938,  1489,  1489,  1489,  1489,
     623,   623,  1205,  1205,  1205,    25,  1205,  1205,  1205,  1205,
    1205,  1205,    25,    25,  1205,  1208,  1090,  1117,  1118,   618,
     446,  1171,  1489,    25,    25,    26,    26,    26,    26,    26,
      25,  1090,  1203,  1171,   391,   391,  1352,  1353,  1357,  1419,
     430,  1413,  1357,   430,  1413,    10,   249,   386,   388,  1418,
      26,  1320,  1378,    20,   938,  1378,   366,   453,   469,   512,
     552,   581,   590,  1389,    26,  1389,     5,  1370,  1370,     5,
     391,   391,  1370,   391,  1332,  1426,  1247,   268,  1243,  1416,
     514,  1343,  1344,  1345,  1375,  1348,   331,   513,   524,  1292,
    1409,   366,   453,   469,   512,   552,   581,   590,  1387,   878,
     589,    24,    26,   795,   838,   868,   467,   826,     5,   373,
    1426,     5,   430,   391,   550,  1003,   942,  1489,   676,    20,
     938,   942,  1489,  1479,   845,  1479,  1112,  1489,    26,   937,
      25,  1230,  1109,   426,   706,   696,   700,   391,  1489,   937,
     845,   890,   426,  1389,  1415,     5,  1388,   391,     5,  1418,
       5,   391,  1418,  1418,  1418,  1418,   938,   391,   845,  1489,
     956,   957,    20,   938,  1428,  1429,   553,  1411,  1396,  1394,
    1397,  1378,  1414,   139,  1317,     5,   391,  1275,  1436,  1411,
    1460,  1460,  1459,   430,   430,   430,   430,   430,   430,   430,
     938,   430,     5,   391,    18,    19,    20,    21,  1440,   391,
       5,   391,     5,    14,   149,   525,  1451,  1286,  1378,   462,
    1312,  1313,  1376,   619,   210,  1043,   807,   781,   538,   587,
    1119,     5,  1117,    61,   133,   199,   201,   216,   224,   228,
     253,  1172,  1173,  1226,  1043,  1216,   441,  1356,  1360,  1361,
    1381,  1468,  1356,  1360,  1357,  1418,     5,   426,  1377,   391,
      26,  1374,   391,   391,    26,   391,   430,  1345,     5,   938,
    1380,   368,  1339,  1349,   938,  1410,   618,  1366,   331,   430,
      24,    26,   391,   930,   679,   373,  1426,   845,   686,   568,
    1125,    26,   679,   426,  1003,   391,   240,   679,   391,   391,
     430,   698,   344,   704,   391,   693,  1065,  1489,   458,  1347,
    1388,   625,  1388,   391,  1418,   391,   391,   391,   391,   575,
     937,     5,   391,  1112,  1347,  1397,  1397,  1415,  1378,   430,
    1347,   391,  1441,  1366,  1459,  1463,  1366,  1366,  1366,  1366,
     619,  1463,  1458,  1459,  1459,  1459,  1459,  1454,    14,  1455,
    1458,   932,  1351,  1112,     5,   140,  1306,   938,  1118,  1174,
    1175,  1090,  1177,  1090,  1176,  1178,  1173,   239,   239,  1358,
    1381,  1422,     5,   391,   391,  1356,     7,    26,   625,   391,
    1344,  1346,  1344,  1340,  1417,  1418,   447,  1338,  1350,  1243,
      26,  1293,  1294,  1295,  1378,  1407,  1410,    26,   825,  1426,
     392,   203,   259,   284,   293,   329,   337,   431,   602,   683,
     687,   688,   430,   619,   679,  1149,  1231,   701,   391,  1109,
     704,   704,  1489,   891,  1101,   391,   625,  1389,   625,   970,
    1000,  1429,  1409,  1347,   482,  1278,  1279,  1418,  1409,   391,
    1459,     5,   391,  1459,  1459,  1459,  1459,   938,   391,   430,
    1313,  1489,  1489,  1179,  1489,  1180,  1489,  1489,  1361,  1418,
     426,  1389,     5,   391,     5,  1351,     5,   538,   587,  1296,
    1243,   391,   347,   351,   828,   829,   830,  1006,   925,   925,
     925,   925,   925,   925,    25,     5,   391,   845,    20,   938,
    1006,  1153,  1154,  1155,   704,   706,   704,   241,   426,  1389,
    1389,  1489,   679,     5,   391,   391,  1459,   391,   391,   391,
     391,  1457,  1489,  1489,  1344,  1417,  1294,   832,   831,   238,
     830,   833,   688,     5,  1156,   282,  1155,   702,   967,  1279,
     391,  1489,  1489,  1489,   845,  1489,   391,   391,   703,   162,
     344,   705,  1109
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
#line 928 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 931 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 935 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 941 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 946 "fgl.yacc"
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
#line 958 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 963 "fgl.yacc"
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
#line 986 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 987 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 988 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 989 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 990 "fgl.yacc"
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
#line 1004 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 1005 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1006 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1007 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1008 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1013 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1014 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1025 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1031 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1031 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1038 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1039 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1045 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1046 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1047 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1049 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1055 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1059 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1060 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 46:
#line 1061 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1068 "fgl.yacc"
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
#line 1079 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1083 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1084 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1088 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1094 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1096 "fgl.yacc"
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
#line 1107 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1109 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1111 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1113 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1117 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1119 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1180 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1184 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1188 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1195 "fgl.yacc"
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
#line 1202 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1206 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1213 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1219 "fgl.yacc"
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
#line 1228 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1232 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1237 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1241 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1249 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1253 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1257 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1259 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1265 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1270 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1273 "fgl.yacc"
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
#line 1289 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1296 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1300 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1304 "fgl.yacc"
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
#line 1326 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1326 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1330 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1331 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1332 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1337 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1340 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1346 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1349 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1361 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1367 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1370 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1385 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1395 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1401 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1410 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1423 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1426 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1428 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1434 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1436 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1441 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1446 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1452 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1456 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1471 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1474 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1477 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1480 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1483 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1486 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1508 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1517 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1527 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1541 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1545 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1548 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1556 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1562 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1577 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1581 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1586 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1596 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1599 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1603 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1605 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1608 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1610 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1613 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1615 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1618 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1621 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1631 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1632 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1640 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1641 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1658 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1661 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1664 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1667 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1670 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1673 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1682 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1690 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1695 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1708 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1712 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1727 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1728 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1736 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1736 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1746 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1746 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1755 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1756 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1757 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1760 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1765 "fgl.yacc"
    { }
    break;

  case 194:
#line 1765 "fgl.yacc"
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
#line 1782 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1786 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1800 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1809 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1813 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1829 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1831 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1832 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1839 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1839 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1840 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1841 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1844 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1846 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1856 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1871 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1871 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1877 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1878 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1885 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1886 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1887 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1888 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1891 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1892 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1893 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1894 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1898 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1903 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1908 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1912 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1915 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1919 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1920 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1921 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1922 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1923 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1924 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1925 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1926 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1929 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1930 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1931 "fgl.yacc"
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
#line 1963 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1967 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1969 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1971 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1973 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1978 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1982 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1982 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1986 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1987 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1988 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1989 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1990 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1991 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1993 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 1998 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 1998 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 2001 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 2003 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2009 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2011 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2017 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2025 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2025 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2028 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2029 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2030 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2031 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2032 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2033 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2035 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2056 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2065 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2067 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2069 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2071 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2072 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2073 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2074 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2075 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2080 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2087 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2092 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2094 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2096 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2097 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2098 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2099 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2100 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2101 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2102 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2105 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2107 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2113 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2121 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2129 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2133 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2141 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2142 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2143 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2144 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2163 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2175 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2179 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2182 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2185 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2186 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2187 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2188 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2189 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2195 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2202 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2207 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2212 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2216 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2219 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2227 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2229 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2234 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2246 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2249 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2252 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2255 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2258 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2261 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2274 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2277 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2292 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2294 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2296 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2298 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2300 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2302 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2303 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2310 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2312 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2316 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2318 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2320 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2322 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2324 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2326 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2328 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2334 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2348 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2351 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2368 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2374 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2378 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2383 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2393 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 396:
#line 2394 "fgl.yacc"
    {inc_counter();}
    break;

  case 402:
#line 2400 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2407 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2407 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2412 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2416 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2422 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2430 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2436 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2445 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2447 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2454 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2462 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2466 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2475 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2480 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2485 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2489 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2491 "fgl.yacc"
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
#line 2501 "fgl.yacc"
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
#line 2515 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2523 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2535 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2541 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2547 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2557 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2563 "fgl.yacc"
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
#line 2635 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2641 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2645 "fgl.yacc"
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
#line 2653 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2653 "fgl.yacc"
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
#line 2669 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2673 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2679 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2682 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2690 "fgl.yacc"
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
#line 2701 "fgl.yacc"
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
#line 2711 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2717 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2727 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2732 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2739 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2742 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2745 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2750 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2757 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2762 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2767 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2772 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2783 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2791 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2799 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2804 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2808 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2813 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2817 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2821 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2827 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2830 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2834 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2838 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2842 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2846 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2850 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2857 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2867 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2872 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2878 "fgl.yacc"
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
#line 2888 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2893 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2896 "fgl.yacc"
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
#line 2910 "fgl.yacc"
    {chk4var=1;}
    break;

  case 477:
#line 2910 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 479:
#line 2913 "fgl.yacc"
    {chk4var=1;}
    break;

  case 480:
#line 2913 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 482:
#line 2917 "fgl.yacc"
    {chk4var=1;}
    break;

  case 483:
#line 2917 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 485:
#line 2921 "fgl.yacc"
    {chk4var=1;}
    break;

  case 486:
#line 2921 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 488:
#line 2925 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2931 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2937 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2943 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2953 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2954 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2962 "fgl.yacc"
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
#line 2973 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2974 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 499:
#line 2980 "fgl.yacc"
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
#line 2991 "fgl.yacc"
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
#line 3001 "fgl.yacc"
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
#line 3014 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 3019 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3026 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3030 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3033 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3036 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3042 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3045 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3048 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3065 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3068 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3074 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3075 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3076 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3081 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3082 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3083 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3084 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3086 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3087 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3088 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3090 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3091 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3097 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3102 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3114 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3118 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3119 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3126 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3143 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3147 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3153 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3157 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 541:
#line 3166 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 542:
#line 3167 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 543:
#line 3179 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 544:
#line 3185 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 545:
#line 3193 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 552:
#line 3210 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 553:
#line 3212 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3215 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 555:
#line 3217 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3231 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 561:
#line 3233 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 562:
#line 3236 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 563:
#line 3238 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 576:
#line 3269 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 577:
#line 3271 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3274 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 579:
#line 3276 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3279 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 581:
#line 3281 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3284 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 583:
#line 3286 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3289 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 585:
#line 3291 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 586:
#line 3306 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 587:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 588:
#line 3323 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 589:
#line 3324 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 590:
#line 3325 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 591:
#line 3326 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3327 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 596:
#line 3335 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 598:
#line 3341 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 599:
#line 3343 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 600:
#line 3344 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 601:
#line 3346 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 602:
#line 3348 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 603:
#line 3350 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3352 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 605:
#line 3354 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 606:
#line 3357 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 607:
#line 3364 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 608:
#line 3366 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3372 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3377 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 611:
#line 3382 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 612:
#line 3387 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 613:
#line 3387 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 614:
#line 3390 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 615:
#line 3396 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 616:
#line 3401 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 617:
#line 3405 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 620:
#line 3413 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 621:
#line 3415 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 622:
#line 3417 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 623:
#line 3419 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3421 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 625:
#line 3423 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 626:
#line 3426 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 628:
#line 3435 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 629:
#line 3497 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 630:
#line 3510 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 632:
#line 3517 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 633:
#line 3520 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 634:
#line 3526 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 635:
#line 3532 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3536 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 637:
#line 3540 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 638:
#line 3546 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3550 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 640:
#line 3554 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 641:
#line 3559 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 642:
#line 3564 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 661:
#line 3605 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 662:
#line 3610 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 664:
#line 3615 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 666:
#line 3618 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 667:
#line 3620 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 668:
#line 3623 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 669:
#line 3627 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 670:
#line 3630 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 671:
#line 3636 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 672:
#line 3647 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 673:
#line 3648 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 674:
#line 3651 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 676:
#line 3657 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 677:
#line 3661 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 678:
#line 3662 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 681:
#line 3676 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 682:
#line 3678 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 685:
#line 3687 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3689 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3693 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 688:
#line 3695 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3698 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 690:
#line 3700 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 691:
#line 3703 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 692:
#line 3706 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 693:
#line 3709 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 694:
#line 3711 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 695:
#line 3714 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 696:
#line 3716 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3719 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 698:
#line 3721 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 699:
#line 3724 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 700:
#line 3726 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3727 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 702:
#line 3729 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3730 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 704:
#line 3732 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3733 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 706:
#line 3735 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 707:
#line 3775 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3776 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3784 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 710:
#line 3785 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 711:
#line 3794 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 712:
#line 3799 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 713:
#line 3804 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 714:
#line 3805 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 716:
#line 3810 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 717:
#line 3813 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 718:
#line 3821 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 719:
#line 3826 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 720:
#line 3830 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 721:
#line 3837 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 722:
#line 3846 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 723:
#line 3852 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3853 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3854 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 726:
#line 3855 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 727:
#line 3858 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 729:
#line 3861 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 730:
#line 3868 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 731:
#line 3869 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3870 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3871 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 734:
#line 3872 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 735:
#line 3873 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 736:
#line 3874 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 737:
#line 3875 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 738:
#line 3876 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 739:
#line 3881 "fgl.yacc"
    {iskey=1;}
    break;

  case 740:
#line 3881 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 741:
#line 3883 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 742:
#line 3886 "fgl.yacc"
    {iskey=1;}
    break;

  case 743:
#line 3886 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 744:
#line 3888 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 745:
#line 3892 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 746:
#line 3895 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 747:
#line 3896 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 749:
#line 3899 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 755:
#line 3911 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3912 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3913 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3914 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3915 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3916 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3917 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3918 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3919 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3920 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3921 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3922 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3923 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3927 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3945 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3945 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3948 "fgl.yacc"
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
#line 3972 "fgl.yacc"
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
#line 3990 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3996 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 4002 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 4008 "fgl.yacc"
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
#line 4019 "fgl.yacc"
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
#line 4042 "fgl.yacc"
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
#line 4058 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4081 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4089 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4115 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4116 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4124 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4129 "fgl.yacc"
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
#line 4145 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4151 "fgl.yacc"
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
#line 4166 "fgl.yacc"
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
#line 4179 "fgl.yacc"
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
#line 4189 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4196 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4203 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4209 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4209 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4214 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 826:
#line 4220 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 827:
#line 4228 "fgl.yacc"
    {
}
    break;

  case 833:
#line 4240 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 835:
#line 4248 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 836:
#line 4254 "fgl.yacc"
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

  case 837:
#line 4268 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 838:
#line 4272 "fgl.yacc"
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

  case 839:
#line 4285 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 841:
#line 4303 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 842:
#line 4311 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 843:
#line 4317 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 844:
#line 4328 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 845:
#line 4332 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 846:
#line 4339 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 847:
#line 4346 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 848:
#line 4352 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 849:
#line 4357 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 852:
#line 4364 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 853:
#line 4365 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 854:
#line 4367 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 855:
#line 4368 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 856:
#line 4371 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 857:
#line 4372 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 858:
#line 4373 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 859:
#line 4375 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 860:
#line 4380 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 861:
#line 4385 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 862:
#line 4392 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 866:
#line 4399 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 867:
#line 4401 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 868:
#line 4403 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 869:
#line 4412 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 870:
#line 4418 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 871:
#line 4422 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 874:
#line 4434 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 875:
#line 4439 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 876:
#line 4444 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 877:
#line 4447 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 879:
#line 4459 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 880:
#line 4462 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 881:
#line 4465 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 888:
#line 4481 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 889:
#line 4486 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 890:
#line 4486 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4489 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 892:
#line 4516 "fgl.yacc"
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

  case 894:
#line 4574 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4581 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 897:
#line 4585 "fgl.yacc"
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

  case 898:
#line 4628 "fgl.yacc"
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

  case 902:
#line 4676 "fgl.yacc"
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
#line 4690 "fgl.yacc"
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
#line 4714 "fgl.yacc"
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

  case 909:
#line 4774 "fgl.yacc"
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

  case 910:
#line 4830 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4835 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 912:
#line 4843 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 913:
#line 4848 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 914:
#line 4856 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 915:
#line 4862 "fgl.yacc"
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

  case 916:
#line 4895 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 917:
#line 4898 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 918:
#line 4900 "fgl.yacc"
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

  case 919:
#line 4941 "fgl.yacc"
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

  case 924:
#line 4994 "fgl.yacc"
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

  case 925:
#line 5046 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 927:
#line 5053 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 928:
#line 5059 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 929:
#line 5070 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 930:
#line 5077 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 932:
#line 5085 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 933:
#line 5088 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 934:
#line 5089 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 936:
#line 5091 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 5092 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 938:
#line 5095 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 939:
#line 5098 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 940:
#line 5104 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 941:
#line 5107 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 942:
#line 5111 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 943:
#line 5115 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 944:
#line 5122 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 945:
#line 5127 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 946:
#line 5134 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 947:
#line 5137 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 952:
#line 5150 "fgl.yacc"
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

  case 953:
#line 5169 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5176 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5183 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 956:
#line 5186 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 957:
#line 5200 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 962:
#line 5217 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 963:
#line 5222 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 964:
#line 5228 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 966:
#line 5235 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 967:
#line 5240 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 968:
#line 5243 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 969:
#line 5244 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 970:
#line 5247 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 971:
#line 5248 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 972:
#line 5251 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 973:
#line 5252 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 974:
#line 5257 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 975:
#line 5264 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 976:
#line 5267 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 977:
#line 5273 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 978:
#line 5275 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 979:
#line 5277 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 980:
#line 5279 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 981:
#line 5282 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 982:
#line 5282 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 983:
#line 5283 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 984:
#line 5288 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 985:
#line 5296 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 986:
#line 5297 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5302 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 988:
#line 5304 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 989:
#line 5306 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 993:
#line 5323 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 994:
#line 5326 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 995:
#line 5329 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 996:
#line 5332 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 997:
#line 5336 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 998:
#line 5339 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 999:
#line 5342 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5346 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5350 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1002:
#line 5354 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1003:
#line 5357 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1004:
#line 5361 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1005:
#line 5364 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5365 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1007:
#line 5366 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1008:
#line 5369 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1009:
#line 5372 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1010:
#line 5375 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1011:
#line 5378 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1012:
#line 5381 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1013:
#line 5384 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1014:
#line 5387 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1015:
#line 5404 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1018:
#line 5414 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1019:
#line 5421 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1021:
#line 5442 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1022:
#line 5447 "fgl.yacc"
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

  case 1023:
#line 5459 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1024:
#line 5460 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1025:
#line 5464 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1026:
#line 5469 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1027:
#line 5470 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1028:
#line 5474 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1032:
#line 5480 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1033:
#line 5482 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1035:
#line 5497 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1036:
#line 5501 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1037:
#line 5507 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1038:
#line 5508 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5511 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1040:
#line 5512 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1041:
#line 5515 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1043:
#line 5534 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1044:
#line 5539 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1045:
#line 5544 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1046:
#line 5549 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1052:
#line 5571 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1053:
#line 5578 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1054:
#line 5587 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1055:
#line 5593 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1056:
#line 5595 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1060:
#line 5606 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1061:
#line 5607 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1062:
#line 5609 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1063:
#line 5610 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1064:
#line 5612 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1065:
#line 5613 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1066:
#line 5615 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1067:
#line 5616 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1068:
#line 5618 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1069:
#line 5619 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1070:
#line 5620 "fgl.yacc"
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

  case 1071:
#line 5634 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1072:
#line 5636 "fgl.yacc"
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

  case 1073:
#line 5653 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1080:
#line 5665 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1081:
#line 5665 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1082:
#line 5671 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1083:
#line 5671 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1084:
#line 5674 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1085:
#line 5674 "fgl.yacc"
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

  case 1086:
#line 5684 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1087:
#line 5685 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1088:
#line 5686 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1089:
#line 5693 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1090:
#line 5705 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1096:
#line 5716 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1097:
#line 5721 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1098:
#line 5725 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1099:
#line 5730 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1100:
#line 5736 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1101:
#line 5737 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1102:
#line 5738 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1103:
#line 5742 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1104:
#line 5743 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1105:
#line 5744 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1106:
#line 5745 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1107:
#line 5749 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1108:
#line 5759 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1109:
#line 5761 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1110:
#line 5766 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1111:
#line 5769 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1112:
#line 5774 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1113:
#line 5781 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1114:
#line 5788 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1115:
#line 5795 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1116:
#line 5804 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1117:
#line 5811 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1118:
#line 5818 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1119:
#line 5825 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1120:
#line 5832 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1125:
#line 5845 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5846 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5847 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1128:
#line 5848 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1129:
#line 5849 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1130:
#line 5850 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1131:
#line 5851 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1132:
#line 5852 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1133:
#line 5853 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1134:
#line 5854 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1137:
#line 5860 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1138:
#line 5861 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1139:
#line 5862 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1140:
#line 5863 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1145:
#line 5872 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1146:
#line 5873 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5874 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5875 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1149:
#line 5876 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5877 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1151:
#line 5878 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1152:
#line 5879 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1153:
#line 5881 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1154:
#line 5882 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1155:
#line 5883 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1156:
#line 5884 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1157:
#line 5886 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1158:
#line 5887 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1159:
#line 5888 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1160:
#line 5889 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1164:
#line 5894 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1165:
#line 5895 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1169:
#line 5902 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1170:
#line 5909 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1171:
#line 5916 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1172:
#line 5927 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1173:
#line 5936 "fgl.yacc"
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

  case 1174:
#line 5947 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1175:
#line 5951 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1176:
#line 5955 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1177:
#line 5961 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1178:
#line 5966 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1179:
#line 5974 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1180:
#line 5977 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1181:
#line 5986 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1182:
#line 5997 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1184:
#line 6004 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1185:
#line 6012 "fgl.yacc"
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

  case 1186:
#line 6022 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1187:
#line 6025 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1188:
#line 6029 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1189:
#line 6037 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1190:
#line 6040 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1191:
#line 6046 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1192:
#line 6050 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1193:
#line 6054 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1194:
#line 6058 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1195:
#line 6062 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1196:
#line 6068 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1197:
#line 6069 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1198:
#line 6070 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1199:
#line 6071 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1200:
#line 6076 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1201:
#line 6078 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1202:
#line 6081 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1203:
#line 6085 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1204:
#line 6088 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1205:
#line 6095 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1206:
#line 6100 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1207:
#line 6101 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1208:
#line 6102 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1209:
#line 6107 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1210:
#line 6108 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1211:
#line 6114 "fgl.yacc"
    {insql=1;}
    break;

  case 1212:
#line 6114 "fgl.yacc"
    {insql=0;}
    break;

  case 1213:
#line 6114 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1214:
#line 6119 "fgl.yacc"
    {insql=1;}
    break;

  case 1215:
#line 6119 "fgl.yacc"
    {insql=0;}
    break;

  case 1216:
#line 6119 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1217:
#line 6130 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1218:
#line 6131 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1219:
#line 6137 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1220:
#line 6139 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1222:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1223:
#line 6156 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1224:
#line 6157 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1226:
#line 6162 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6165 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1228:
#line 6171 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1229:
#line 6174 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1230:
#line 6182 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1232:
#line 6189 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1233:
#line 6196 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1234:
#line 6199 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1235:
#line 6208 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1236:
#line 6211 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6214 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6217 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6220 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1240:
#line 6223 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1241:
#line 6226 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1242:
#line 6233 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1243:
#line 6236 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1244:
#line 6243 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6246 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1246:
#line 6252 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1247:
#line 6255 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1248:
#line 6262 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1249:
#line 6265 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1251:
#line 6273 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1253:
#line 6282 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1254:
#line 6285 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1255:
#line 6291 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 6294 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1257:
#line 6300 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 6307 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1259:
#line 6308 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1260:
#line 6312 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1261:
#line 6318 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1262:
#line 6321 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1264:
#line 6329 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1265:
#line 6336 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1266:
#line 6339 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1270:
#line 6357 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1276:
#line 6363 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1277:
#line 6366 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1278:
#line 6369 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1279:
#line 6375 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1281:
#line 6381 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1283:
#line 6392 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1284:
#line 6406 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1285:
#line 6415 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1286:
#line 6415 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1287:
#line 6420 "fgl.yacc"
    {insql=1;}
    break;

  case 1288:
#line 6420 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1289:
#line 6425 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1290:
#line 6428 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1291:
#line 6430 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1293:
#line 6437 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6441 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1295:
#line 6445 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1296:
#line 6452 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1297:
#line 6455 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1298:
#line 6462 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1299:
#line 6466 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1300:
#line 6470 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1301:
#line 6475 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1302:
#line 6480 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1303:
#line 6484 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1304:
#line 6490 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1305:
#line 6494 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1306:
#line 6500 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1307:
#line 6507 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1308:
#line 6511 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1309:
#line 6516 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1310:
#line 6526 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1311:
#line 6529 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1312:
#line 6531 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6533 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6535 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1315:
#line 6537 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1316:
#line 6539 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1317:
#line 6541 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1318:
#line 6547 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1319:
#line 6557 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1320:
#line 6564 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1322:
#line 6570 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1326:
#line 6579 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1329:
#line 6584 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1330:
#line 6589 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1331:
#line 6596 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1332:
#line 6597 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1333:
#line 6604 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1334:
#line 6615 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1335:
#line 6616 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1336:
#line 6619 "fgl.yacc"
    {insql=1;}
    break;

  case 1337:
#line 6619 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1338:
#line 6624 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1339:
#line 6629 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1341:
#line 6635 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1343:
#line 6639 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1344:
#line 6644 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1345:
#line 6649 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1346:
#line 6653 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1348:
#line 6659 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1349:
#line 6663 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1350:
#line 6671 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1351:
#line 6674 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1352:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1353:
#line 6681 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1356:
#line 6688 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1360:
#line 6695 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6698 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1362:
#line 6700 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6706 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1366:
#line 6712 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6722 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1370:
#line 6727 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1371:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1373:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6738 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6744 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1377:
#line 6752 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6757 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6767 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6773 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6779 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6781 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6787 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6792 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1389:
#line 6795 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1390:
#line 6798 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1391:
#line 6806 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6808 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1393:
#line 6821 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1394:
#line 6826 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1396:
#line 6830 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1397:
#line 6832 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1398:
#line 6839 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1399:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1400:
#line 6848 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1401:
#line 6852 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1402:
#line 6856 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1403:
#line 6860 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1404:
#line 6863 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1405:
#line 6871 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1406:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1409:
#line 6887 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6893 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1411:
#line 6896 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1412:
#line 6907 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6914 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6920 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1415:
#line 6923 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1416:
#line 6930 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1417:
#line 6937 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1419:
#line 6944 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1420:
#line 6950 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1421:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6952 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1424:
#line 6956 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6961 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1427:
#line 6968 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1428:
#line 6973 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1429:
#line 6974 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1430:
#line 6977 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1431:
#line 6980 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1432:
#line 6985 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1433:
#line 6986 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1434:
#line 6991 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1435:
#line 6994 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7000 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1437:
#line 7003 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1438:
#line 7009 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1439:
#line 7012 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1440:
#line 7018 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1441:
#line 7021 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1442:
#line 7028 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1443:
#line 7029 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1444:
#line 7058 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1445:
#line 7060 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1446:
#line 7064 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1448:
#line 7077 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1449:
#line 7080 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7083 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1451:
#line 7086 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 7094 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1454:
#line 7097 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1456:
#line 7103 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1458:
#line 7109 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1459:
#line 7112 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1460:
#line 7115 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1461:
#line 7118 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1462:
#line 7121 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1463:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1464:
#line 7127 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1466:
#line 7134 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1471:
#line 7141 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1472:
#line 7142 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1473:
#line 7147 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1474:
#line 7150 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1475:
#line 7154 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1476:
#line 7160 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1477:
#line 7161 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1478:
#line 7162 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1479:
#line 7163 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1484:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1485:
#line 7188 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 7189 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1488:
#line 7192 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7197 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 7200 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1496:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7208 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7210 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7213 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1503:
#line 7214 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1504:
#line 7221 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7226 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1512:
#line 7242 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1513:
#line 7243 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1514:
#line 7247 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1515:
#line 7248 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1517:
#line 7267 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1518:
#line 7268 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1519:
#line 7269 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1520:
#line 7273 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1521:
#line 7276 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1522:
#line 7282 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1523:
#line 7287 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1524:
#line 7292 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1526:
#line 7303 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1531:
#line 7318 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1532:
#line 7321 "fgl.yacc"
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

  case 1533:
#line 7334 "fgl.yacc"
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

  case 1534:
#line 7349 "fgl.yacc"
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

  case 1535:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1536:
#line 7363 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1537:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1538:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1539:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1540:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1541:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1542:
#line 7366 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1543:
#line 7367 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1544:
#line 7370 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1545:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1546:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1547:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1548:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1549:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1550:
#line 7375 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1551:
#line 7377 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1552:
#line 7380 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1567:
#line 7389 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1568:
#line 7390 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1569:
#line 7394 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1570:
#line 7402 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1571:
#line 7402 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1572:
#line 7408 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1573:
#line 7408 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1574:
#line 7415 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1575:
#line 7415 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1576:
#line 7421 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1577:
#line 7421 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1578:
#line 7429 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1579:
#line 7430 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1580:
#line 7431 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1584:
#line 7438 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1585:
#line 7439 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1586:
#line 7444 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1587:
#line 7447 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1588:
#line 7453 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1589:
#line 7458 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1590:
#line 7467 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1591:
#line 7479 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1592:
#line 7480 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1593:
#line 7483 "fgl.yacc"
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

  case 1594:
#line 7498 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1595:
#line 7508 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1596:
#line 7511 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1597:
#line 7519 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1598:
#line 7528 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1599:
#line 7531 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1600:
#line 7535 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1601:
#line 7538 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1602:
#line 7539 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1604:
#line 7548 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1605:
#line 7549 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1606:
#line 7558 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1607:
#line 7567 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1608:
#line 7572 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1609:
#line 7573 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1610:
#line 7574 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1611:
#line 7575 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1612:
#line 7582 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1613:
#line 7585 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1614:
#line 7591 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1615:
#line 7594 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1616:
#line 7604 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1617:
#line 7613 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1618:
#line 7616 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1619:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1620:
#line 7625 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1621:
#line 7631 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1622:
#line 7634 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1623:
#line 7637 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1624:
#line 7640 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1625:
#line 7647 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7649 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1627:
#line 7651 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1628:
#line 7653 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1629:
#line 7655 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1630:
#line 7656 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1631:
#line 7657 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1632:
#line 7658 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1633:
#line 7659 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1634:
#line 7660 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1635:
#line 7661 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1636:
#line 7663 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7665 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7667 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7669 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7671 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7673 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7675 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1643:
#line 7676 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1644:
#line 7678 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1645:
#line 7682 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1646:
#line 7683 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1648:
#line 7693 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1649:
#line 7702 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1650:
#line 7706 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1651:
#line 7713 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1652:
#line 7713 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1654:
#line 7717 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1655:
#line 7722 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1656:
#line 7722 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1658:
#line 7726 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1659:
#line 7730 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1662:
#line 7739 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1663:
#line 7739 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1668:
#line 7758 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1669:
#line 7759 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1672:
#line 7767 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1673:
#line 7773 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1676:
#line 7792 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1677:
#line 7793 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1678:
#line 7794 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1679:
#line 7795 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1680:
#line 7796 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1681:
#line 7797 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1682:
#line 7801 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1683:
#line 7802 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1684:
#line 7803 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1685:
#line 7807 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1686:
#line 7811 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1688:
#line 7820 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1690:
#line 7825 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1691:
#line 7826 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1692:
#line 7830 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1693:
#line 7836 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1694:
#line 7923 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1695:
#line 7927 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1696:
#line 7929 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1697:
#line 7936 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1698:
#line 7940 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1699:
#line 7946 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1700:
#line 7954 "fgl.yacc"
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

  case 1701:
#line 7964 "fgl.yacc"
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
#line 7974 "fgl.yacc"
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

  case 1703:
#line 7986 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1704:
#line 7989 "fgl.yacc"
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
#line 8008 "fgl.yacc"
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

  case 1706:
#line 8034 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1707:
#line 8037 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1709:
#line 8046 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1710:
#line 8051 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1711:
#line 8054 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1712:
#line 8062 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1713:
#line 8070 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1714:
#line 8083 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1715:
#line 8086 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1716:
#line 8094 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1717:
#line 8097 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1718:
#line 8100 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1719:
#line 8108 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1720:
#line 8112 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1721:
#line 8115 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1722:
#line 8118 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1723:
#line 8121 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1724:
#line 8125 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1725:
#line 8126 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1726:
#line 8127 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1727:
#line 8128 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1728:
#line 8129 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1729:
#line 8135 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 8136 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1731:
#line 8137 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1732:
#line 8138 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1733:
#line 8139 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1734:
#line 8140 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1735:
#line 8141 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1736:
#line 8142 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1737:
#line 8143 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1738:
#line 8144 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1739:
#line 8145 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1740:
#line 8146 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1741:
#line 8147 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1742:
#line 8148 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1743:
#line 8152 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1744:
#line 8158 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1745:
#line 8159 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1746:
#line 8172 "fgl.yacc"
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

  case 1747:
#line 8192 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1751:
#line 8198 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1752:
#line 8199 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1756:
#line 8211 "fgl.yacc"
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

  case 1757:
#line 8237 "fgl.yacc"
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

  case 1758:
#line 8288 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1759:
#line 8290 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1760:
#line 8292 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 8293 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1762:
#line 8298 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1763:
#line 8303 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8304 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1765:
#line 8308 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1766:
#line 8310 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1767:
#line 8312 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1768:
#line 8315 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1769:
#line 8319 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1770:
#line 8324 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1771:
#line 8329 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1772:
#line 8333 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1774:
#line 8343 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1776:
#line 8358 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1777:
#line 8361 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1778:
#line 8365 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1781:
#line 8384 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1782:
#line 8385 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1783:
#line 8388 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1784:
#line 8389 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1785:
#line 8390 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1786:
#line 8391 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1787:
#line 8392 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1788:
#line 8393 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1789:
#line 8394 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1790:
#line 8399 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1791:
#line 8400 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1792:
#line 8404 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1793:
#line 8408 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1794:
#line 8412 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1795:
#line 8416 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1796:
#line 8421 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1797:
#line 8425 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1798:
#line 8430 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1800:
#line 8438 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1802:
#line 8444 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1803:
#line 8450 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1804:
#line 8454 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1809:
#line 8472 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1810:
#line 8479 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1811:
#line 8488 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1812:
#line 8488 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17150 "y.tab.c"

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


#line 8583 "fgl.yacc"

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



