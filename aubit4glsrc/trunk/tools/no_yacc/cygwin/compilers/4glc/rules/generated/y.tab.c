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
#line 1579 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1591 "y.tab.c"

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
#define YYLAST   8676

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  668
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  828
/* YYNRULES -- Number of rules. */
#define YYNRULES  1898
/* YYNRULES -- Number of states. */
#define YYNSTATES  3164

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
    1956,  1959,  1960,  1961,  1970,  1971,  1972,  1976,  1977,  1978,
    1986,  1992,  1995,  1998,  1999,  2005,  2010,  2012,  2016,  2020,
    2024,  2025,  2028,  2029,  2031,  2033,  2036,  2037,  2042,  2043,
    2048,  2049,  2053,  2054,  2058,  2059,  2063,  2064,  2068,  2069,
    2073,  2074,  2078,  2079,  2083,  2084,  2088,  2089,  2093,  2095,
    2099,  2101,  2105,  2108,  2113,  2115,  2117,  2119,  2120,  2125,
    2131,  2138,  2139,  2150,  2154,  2157,  2160,  2162,  2164,  2165,
    2168,  2170,  2173,  2177,  2181,  2185,  2189,  2191,  2193,  2195,
    2197,  2198,  2202,  2204,  2205,  2209,  2212,  2215,  2217,  2221,
    2223,  2227,  2229,  2231,  2233,  2235,  2237,  2239,  2241,  2243,
    2245,  2247,  2249,  2251,  2253,  2255,  2257,  2259,  2261,  2263,
    2265,  2266,  2267,  2275,  2277,  2279,  2282,  2285,  2288,  2292,
    2297,  2298,  2302,  2303,  2305,  2307,  2310,  2312,  2314,  2316,
    2318,  2319,  2321,  2323,  2326,  2329,  2331,  2333,  2335,  2337,
    2339,  2341,  2343,  2345,  2347,  2349,  2351,  2353,  2355,  2356,
    2358,  2360,  2362,  2364,  2366,  2367,  2368,  2369,  2370,  2384,
    2386,  2387,  2388,  2395,  2398,  2400,  2403,  2406,  2409,  2411,
    2413,  2416,  2418,  2420,  2422,  2423,  2427,  2430,  2432,  2433,
    2434,  2435,  2450,  2451,  2457,  2459,  2460,  2464,  2465,  2473,
    2474,  2480,  2482,  2485,  2486,  2488,  2490,  2492,  2493,  2495,
    2497,  2500,  2503,  2506,  2508,  2510,  2512,  2514,  2518,  2520,
    2522,  2523,  2524,  2532,  2534,  2537,  2538,  2542,  2543,  2548,
    2551,  2552,  2555,  2557,  2559,  2561,  2563,  2565,  2567,  2569,
    2573,  2574,  2576,  2578,  2580,  2582,  2585,  2588,  2591,  2597,
    2606,  2608,  2610,  2612,  2617,  2622,  2624,  2626,  2628,  2630,
    2633,  2636,  2640,  2647,  2649,  2653,  2655,  2657,  2659,  2663,
    2670,  2680,  2682,  2684,  2686,  2688,  2691,  2692,  2694,  2696,
    2700,  2702,  2706,  2708,  2712,  2714,  2718,  2720,  2722,  2724,
    2726,  2730,  2732,  2736,  2738,  2742,  2744,  2746,  2748,  2752,
    2755,  2756,  2758,  2760,  2765,  2767,  2771,  2773,  2777,  2785,
    2786,  2794,  2795,  2802,  2806,  2808,  2812,  2814,  2817,  2823,
    2824,  2832,  2833,  2836,  2837,  2839,  2845,  2848,  2854,  2855,
    2861,  2868,  2873,  2874,  2876,  2878,  2883,  2884,  2887,  2888,
    2894,  2899,  2902,  2904,  2908,  2911,  2914,  2917,  2920,  2923,
    2926,  2928,  2931,  2934,  2937,  2940,  2943,  2946,  2949,  2952,
    2955,  2957,  2959,  2961,  2963,  2965,  2967,  2973,  2975,  2977,
    2980,  2985,  2987,  2988,  3000,  3001,  3004,  3010,  3011,  3013,
    3014,  3017,  3019,  3022,  3023,  3027,  3029,  3030,  3035,  3036,
    3039,  3041,  3045,  3047,  3049,  3053,  3058,  3063,  3066,  3068,
    3070,  3072,  3073,  3075,  3083,  3086,  3089,  3092,  3095,  3098,
    3100,  3103,  3104,  3108,  3109,  3113,  3114,  3118,  3119,  3123,
    3124,  3128,  3129,  3134,  3135,  3140,  3142,  3144,  3146,  3148,
    3150,  3152,  3153,  3158,  3159,  3161,  3162,  3167,  3169,  3172,
    3175,  3178,  3179,  3181,  3183,  3186,  3189,  3190,  3193,  3197,
    3201,  3207,  3208,  3211,  3216,  3218,  3220,  3222,  3224,  3226,
    3227,  3229,  3231,  3235,  3238,  3244,  3247,  3253,  3259,  3265,
    3271,  3277,  3283,  3284,  3287,  3289,  3292,  3295,  3298,  3301,
    3304,  3307,  3309,  3312,  3315,  3318,  3321,  3323,  3326,  3329,
    3332,  3335,  3337,  3339,  3341,  3342,  3345,  3348,  3351,  3354,
    3357,  3360,  3363,  3366,  3369,  3371,  3373,  3375,  3377,  3379,
    3381,  3383,  3385,  3388,  3391,  3394,  3397,  3400,  3402,  3404,
    3406,  3407,  3411,  3414,  3415,  3416,  3417,  3418,  3419,  3420,
    3436,  3437,  3440,  3443,  3444,  3446,  3447,  3448,  3449,  3450,
    3451,  3452,  3468,  3471,  3472,  3473,  3474,  3485,  3486,  3488,
    3492,  3496,  3499,  3504,  3508,  3512,  3516,  3518,  3520,  3522,
    3524,  3526,  3528,  3529,  3530,  3538,  3539,  3540,  3549,  3553,
    3556,  3557,  3559,  3561,  3565,  3568,  3571,  3573,  3575,  3579,
    3581,  3583,  3586,  3588,  3592,  3594,  3598,  3600,  3602,  3604,
    3606,  3608,  3610,  3612,  3615,  3620,  3622,  3626,  3628,  3632,
    3635,  3640,  3642,  3646,  3648,  3651,  3656,  3658,  3662,  3664,
    3666,  3668,  3671,  3674,  3679,  3682,  3687,  3689,  3693,  3695,
    3697,  3699,  3702,  3704,  3706,  3708,  3710,  3712,  3715,  3722,
    3729,  3730,  3732,  3733,  3735,  3738,  3740,  3741,  3747,  3748,
    3754,  3756,  3757,  3761,  3763,  3767,  3769,  3773,  3775,  3777,
    3778,  3779,  3785,  3787,  3790,  3792,  3793,  3794,  3798,  3799,
    3800,  3804,  3806,  3808,  3810,  3812,  3814,  3816,  3819,  3822,
    3827,  3831,  3835,  3837,  3841,  3844,  3846,  3848,  3849,  3851,
    3853,  3855,  3857,  3858,  3860,  3864,  3866,  3868,  3869,  3873,
    3875,  3877,  3879,  3881,  3883,  3885,  3887,  3889,  3891,  3893,
    3895,  3897,  3905,  3906,  3908,  3910,  3912,  3914,  3918,  3920,
    3922,  3924,  3927,  3928,  3932,  3934,  3938,  3940,  3944,  3946,
    3948,  3955,  3956,  3960,  3962,  3966,  3967,  3969,  3974,  3980,
    3983,  3985,  3987,  3992,  3994,  3998,  4003,  4008,  4010,  4014,
    4016,  4018,  4020,  4023,  4025,  4030,  4031,  4033,  4034,  4036,
    4038,  4041,  4043,  4045,  4047,  4049,  4054,  4058,  4060,  4062,
    4064,  4067,  4069,  4071,  4074,  4077,  4079,  4083,  4086,  4089,
    4091,  4095,  4097,  4100,  4105,  4107,  4110,  4112,  4116,  4121,
    4122,  4124,  4125,  4127,  4128,  4130,  4132,  4136,  4138,  4142,
    4144,  4147,  4149,  4153,  4156,  4159,  4160,  4163,  4165,  4167,
    4173,  4177,  4183,  4187,  4189,  4193,  4195,  4197,  4198,  4200,
    4204,  4208,  4212,  4219,  4224,  4229,  4235,  4237,  4239,  4241,
    4243,  4245,  4247,  4249,  4251,  4253,  4255,  4257,  4258,  4260,
    4262,  4264,  4266,  4268,  4270,  4272,  4277,  4283,  4285,  4291,
    4297,  4299,  4301,  4303,  4308,  4310,  4315,  4317,  4325,  4327,
    4329,  4331,  4336,  4343,  4344,  4347,  4352,  4354,  4356,  4358,
    4360,  4362,  4364,  4366,  4370,  4372,  4374,  4378,  4380,  4381,
    4385,  4391,  4393,  4396,  4399,  4404,  4408,  4410,  4412,  4414,
    4416,  4418,  4420,  4423,  4426,  4427,  4431,  4432,  4436,  4438,
    4440,  4442,  4444,  4446,  4448,  4450,  4455,  4457,  4459,  4461,
    4463,  4465,  4467,  4469,  4474,  4476,  4478,  4480,  4482,  4484,
    4486,  4488,  4490,  4492,  4494,  4496,  4498,  4500,  4502,  4504,
    4506,  4510,  4511,  4520,  4521,  4531,  4532,  4540,  4541,  4551,
    4552,  4554,  4557,  4559,  4563,  4565,  4569,  4575,  4577,  4579,
    4581,  4583,  4586,  4587,  4588,  4597,  4603,  4605,  4607,  4614,
    4615,  4619,  4621,  4625,  4630,  4632,  4633,  4636,  4641,  4648,
    4649,  4651,  4653,  4655,  4657,  4661,  4663,  4666,  4668,  4670,
    4673,  4676,  4678,  4680,  4682,  4685,  4690,  4694,  4697,  4701,
    4705,  4709,  4711,  4713,  4715,  4717,  4719,  4721,  4727,  4733,
    4739,  4745,  4751,  4756,  4761,  4765,  4770,  4772,  4776,  4778,
    4784,  4792,  4798,  4799,  4802,  4804,  4806,  4807,  4811,  4813,
    4817,  4819,  4821,  4823,  4824,  4828,  4830,  4832,  4834,  4836,
    4841,  4848,  4850,  4852,  4855,  4859,  4861,  4863,  4865,  4867,
    4869,  4871,  4873,  4875,  4881,  4887,  4892,  4893,  4898,  4900,
    4903,  4905,  4907,  4909,  4912,  4915,  4916,  4917,  4924,  4925,
    4928,  4931,  4939,  4943,  4947,  4950,  4953,  4956,  4958,  4962,
    4964,  4968,  4970,  4974,  4976,  4980,  4982,  4984,  4986,  4989,
    4992,  4994,  4996,  4999,  5004,  5006,  5008,  5010,  5012,  5014,
    5016,  5020,  5023,  5027,  5031,  5035,  5041,  5047,  5053,  5059,
    5065,  5070,  5075,  5079,  5084,  5086,  5088,  5092,  5094,  5097,
    5099,  5101,  5103,  5107,  5113,  5115,  5117,  5119,  5121,  5125,
    5128,  5131,  5134,  5136,  5139,  5142,  5144,  5147,  5150,  5153,
    5155,  5159,  5162,  5164,  5167,  5169,  5172,  5174,  5175,  5176,
    5183,  5184,  5187,  5188,  5190,  5192,  5195,  5198,  5200,  5202,
    5207,  5211,  5213,  5217,  5219,  5222,  5228,  5231,  5234,  5240,
    5241,  5244,  5246,  5248,  5251,  5258,  5265,  5267,  5268,  5270,
    5273,  5275,  5278,  5279,  5282,  5284,  5286,  5288,  5290,  5292,
    5294,  5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,
    5314,  5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,  5332,
    5334,  5336,  5338,  5340,  5342,  5344,  5346,  5348,  5350,  5352,
    5354,  5356,  5358,  5360,  5362,  5364,  5366,  5368,  5370,  5372,
    5374,  5376,  5378,  5380,  5382,  5384,  5386,  5388,  5390,  5392,
    5394,  5396,  5398,  5400,  5402,  5404,  5406,  5408,  5410,  5412,
    5414,  5416,  5418,  5420,  5422,  5424,  5426,  5428,  5430,  5432,
    5434,  5436,  5438,  5440,  5442,  5444,  5446,  5448,  5450
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1026,     0,    -1,   200,    -1,   197,    -1,   124,   673,   426,
     595,   674,    -1,   138,    -1,  1091,    -1,    26,    -1,   675,
      -1,   674,     5,   675,    -1,   938,    -1,   430,   676,   391,
      -1,   676,   677,   676,    -1,    26,    -1,   678,    26,    -1,
    1091,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   680,    -1,    -1,
     274,   430,   681,   682,   391,    -1,   568,   430,    26,     5,
      26,   391,    -1,   683,    -1,   682,     5,   683,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   409,    -1,   604,
      -1,   527,    -1,   479,    -1,   416,    -1,   490,    -1,   345,
      -1,   531,    -1,   455,    -1,   332,    -1,   593,    -1,    98,
      -1,  1005,    -1,    -1,   685,    -1,    -1,   274,   430,   686,
     687,   391,    -1,   688,    -1,   687,     5,   688,    -1,   683,
      -1,   431,    -1,   602,    25,    -1,   203,   925,    -1,   329,
     925,    -1,   284,   925,    -1,   337,   925,    -1,   293,   925,
      -1,   259,   925,    -1,   533,   690,    -1,   869,   344,  1091,
      -1,    -1,   289,   430,  1480,   391,   344,   691,  1110,    -1,
     104,   430,   938,     5,    25,     5,    25,   391,    -1,   406,
     430,   930,   391,   344,  1091,    -1,  1229,    -1,   192,   430,
     888,   391,   344,  1091,    -1,    -1,    -1,  1091,   589,   938,
     430,   692,   706,   391,   693,   704,    -1,    -1,    -1,    -1,
     938,   430,   694,   706,   695,   391,   696,   704,    -1,    -1,
      -1,   473,  1427,   622,  1427,   430,   697,   706,   698,   391,
     704,    -1,    -1,    -1,   938,   520,   938,   430,   699,   706,
     700,   391,   704,    -1,    -1,    -1,    -1,   365,   709,   589,
     710,   458,   673,   426,   430,   701,   706,   702,   391,   703,
     705,    -1,    -1,   344,  1110,    -1,    -1,   344,  1110,    -1,
     162,    -1,    -1,   707,    -1,   708,    -1,   707,     5,   708,
      -1,   838,    -1,    25,    -1,   938,    -1,   938,    -1,   938,
     619,   938,    -1,    -1,   534,   845,   712,   715,   719,   716,
      -1,    -1,   534,   713,   714,   717,   716,    -1,   721,    -1,
     714,   721,    -1,   723,    -1,   715,   723,    -1,   360,    -1,
      -1,    -1,   339,   718,  1490,    -1,    -1,    -1,   339,   720,
    1490,    -1,    -1,   578,   845,   722,  1490,    -1,    -1,   578,
     845,   724,  1490,    -1,   278,   935,    -1,   202,   933,    -1,
      83,   933,    -1,   168,    -1,   185,  1433,    -1,   493,   932,
      -1,    30,   727,    31,    -1,   728,    -1,   730,    -1,   729,
      -1,   728,   729,    -1,    29,    -1,   731,    -1,   730,   731,
      -1,    28,    -1,   393,    -1,    -1,    -1,   320,   734,   736,
     735,   737,    -1,   384,  1091,   624,   738,   979,  1004,   679,
      -1,  1091,   624,   738,   979,   546,  1480,  1004,   679,    -1,
      -1,   740,   191,    -1,   739,    -1,   738,     5,   739,    -1,
     938,    -1,   938,   619,   938,    -1,   938,   619,    20,    -1,
     741,    -1,   740,   741,    -1,    -1,   270,   747,   742,  1490,
      -1,    -1,   273,   748,   743,  1490,    -1,    -1,  1007,   744,
    1490,    -1,    -1,   166,   745,  1490,    -1,    -1,   163,   746,
    1490,    -1,   942,    -1,   747,     5,   942,    -1,   942,    -1,
     748,     5,   942,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   430,   838,   751,   391,
      -1,    -1,     5,   792,   625,   795,    -1,   155,    -1,   279,
      -1,    -1,   754,    -1,   755,    -1,   754,   755,    -1,    -1,
      -1,   437,   756,   758,   757,  1198,    -1,   805,    -1,  1470,
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
      68,    -1,   625,  1480,    -1,   625,   508,   938,   658,  1480,
      -1,   625,   508,   938,   389,    -1,    72,   938,    -1,   156,
     863,  1110,   827,    -1,   400,   863,   843,   819,   827,    -1,
     209,   935,   827,    -1,    -1,    -1,   188,   824,  1117,   625,
     938,   619,    20,   826,   679,   825,   828,    -1,    -1,   467,
     930,    -1,   679,    -1,    -1,   829,   238,    -1,   830,    -1,
     829,   830,    -1,    -1,   351,   831,  1490,    -1,    -1,   347,
     832,  1490,    -1,    -1,  1007,   833,  1490,    -1,   497,   863,
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
    1407,   391,    -1,   294,   430,  1407,   391,    -1,   846,   944,
      -1,   846,    26,    -1,    25,    -1,   944,    -1,    26,    -1,
     851,    -1,  1091,    -1,  1091,   420,  1091,    -1,   850,    -1,
     433,   838,    -1,   392,   838,    -1,  1201,    -1,    -1,   506,
     853,  1201,    -1,     7,   838,    -1,     6,   838,    -1,   838,
      -1,   855,     5,   838,    -1,   622,   430,  1407,   391,    -1,
     428,   430,  1407,   391,    -1,   622,   430,   863,   855,   391,
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
      -1,  1387,   625,  1388,    -1,   791,    -1,   869,    -1,   289,
     430,  1480,   391,    -1,    99,   430,   930,   391,    -1,    71,
     430,   930,   391,    -1,   406,   430,  1480,   391,    -1,   192,
     430,  1480,   391,    -1,    59,   430,  1480,   391,    -1,   882,
      -1,   864,    -1,  1383,    -1,   537,    -1,   422,   430,   838,
     391,    -1,   322,   430,   838,   391,    -1,   487,   838,    -1,
     443,   750,    -1,   838,   108,    -1,   838,   109,    -1,   838,
     110,    -1,    25,    -1,   885,    -1,    19,   885,    -1,   887,
      -1,   886,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   930,    -1,   888,     5,   930,
      -1,    -1,    -1,   595,  1091,    14,   845,   625,   845,   892,
     890,  1490,   891,   241,    -1,    -1,   571,   845,    -1,    -1,
      -1,    -1,   403,   894,   932,   895,   897,  1288,   896,  1490,
     240,    -1,    -1,     8,   863,   843,    -1,    -1,    -1,   637,
     938,   899,   753,   900,  1036,   902,   901,   907,   638,    -1,
      -1,   912,    -1,    -1,   903,    -1,   904,    -1,   903,   904,
      -1,    -1,   639,   905,  1490,    -1,    -1,   640,   906,  1490,
      -1,    -1,   908,    -1,   909,    -1,   908,   909,    -1,    -1,
     641,   910,  1490,    -1,    -1,   642,   911,  1490,    -1,   913,
     917,   324,    -1,    91,    -1,    91,   914,   546,   915,    -1,
      91,   384,   916,    -1,  1091,    -1,   914,     5,  1091,    -1,
     938,    -1,   915,     5,   938,    -1,  1091,    -1,   916,     5,
    1091,    -1,   918,    -1,   917,   918,    -1,    -1,   643,   919,
    1490,    -1,    -1,   644,   920,  1490,    -1,    -1,   663,   915,
     921,  1490,    -1,    -1,   480,   915,   922,  1490,    -1,    -1,
     624,   915,   923,  1490,    -1,   545,   931,    -1,   554,    19,
      26,    -1,   554,    -1,   500,    18,    26,    -1,   500,    -1,
      26,    -1,  1091,    -1,    25,    -1,   943,    -1,   845,    -1,
     927,     5,   927,    -1,   928,    -1,   938,    -1,   666,   430,
     938,   391,    -1,   938,   619,   666,   430,   938,   391,    -1,
     938,   458,   676,   426,    -1,   938,   619,    20,    -1,   938,
     458,   676,   426,   619,    20,    -1,   938,   619,   938,    -1,
     938,   458,   676,   426,   619,   938,    -1,   939,    -1,   939,
      -1,   939,    -1,   939,    -1,   939,    -1,   939,    -1,    -1,
     550,    26,    -1,  1489,    -1,   940,    -1,  1489,    -1,   349,
     430,   941,   391,    -1,  1094,    -1,    25,    -1,   938,    -1,
     938,   458,   676,   426,    -1,   938,   619,    20,    -1,   938,
     458,   676,   426,   619,    20,    -1,   938,   619,   938,    -1,
     938,   458,   676,   426,   619,   938,    -1,  1091,    -1,    24,
      -1,   619,    26,    -1,   547,  1472,    -1,   651,   947,    -1,
     948,    -1,   947,     5,   948,    -1,   938,    -1,   662,   947,
      -1,   653,   947,    -1,   654,  1480,    -1,   652,   935,   658,
    1480,    -1,   656,   947,    -1,   657,  1480,    -1,   655,   935,
     658,  1480,    -1,    -1,   660,   953,   843,   958,   960,   962,
     954,   956,    -1,    -1,   955,    -1,   648,    -1,   649,    -1,
      -1,   957,    -1,   344,  1091,    -1,    -1,   959,    -1,   389,
     843,    -1,    -1,   961,    -1,   659,    26,    -1,    -1,   963,
      -1,   650,    26,   964,    -1,    -1,   399,    26,    -1,    -1,
      -1,   621,   845,   575,   966,  1490,   967,   968,   440,    -1,
      -1,    -1,   542,   969,  1490,    -1,    -1,    -1,    62,   970,
     845,   575,   971,  1490,   968,    -1,   106,   938,   430,    26,
     391,    -1,    55,   938,    -1,    75,   938,    -1,    -1,   290,
    1122,   975,   625,   482,    -1,   290,  1122,   556,   976,    -1,
     977,    -1,   976,     5,   977,    -1,   788,   619,  1379,    -1,
     788,   619,    20,    -1,    -1,   980,   324,    -1,    -1,   150,
      -1,   981,    -1,   980,   981,    -1,    -1,   270,   993,   982,
    1490,    -1,    -1,   273,   994,   983,  1490,    -1,    -1,   351,
     984,  1490,    -1,    -1,   347,   985,  1490,    -1,    -1,  1007,
     986,  1490,    -1,    -1,   305,   987,  1490,    -1,    -1,   275,
     988,  1490,    -1,    -1,    36,   989,  1490,    -1,    -1,    34,
     990,  1490,    -1,    -1,    38,   991,  1490,    -1,    -1,    37,
     992,  1490,    -1,   930,    -1,   993,     5,   930,    -1,   930,
      -1,   994,     5,   930,    -1,   314,   997,    -1,   315,   938,
     658,   997,    -1,   561,    -1,   374,    -1,   930,    -1,    -1,
     664,  1000,   999,   978,    -1,   384,  1110,   979,   937,   679,
      -1,  1110,   979,   546,  1480,   937,   679,    -1,    -1,   486,
    1117,   979,   546,   938,   619,    20,   937,  1001,   679,    -1,
     468,  1480,  1003,    -1,    81,    26,    -1,    82,    26,    -1,
     626,    -1,   539,    -1,    -1,   550,    26,    -1,  1006,    -1,
      43,    25,    -1,   495,    14,    26,    -1,   495,    14,  1091,
      -1,    44,    14,    26,    -1,    44,    14,  1091,    -1,    40,
      -1,    42,    -1,    39,    -1,    41,    -1,    -1,   429,  1008,
    1013,    -1,   295,    -1,    -1,   596,  1010,  1013,    -1,   303,
    1015,    -1,   596,  1013,    -1,  1015,    -1,   430,  1014,   391,
      -1,  1015,    -1,  1014,     5,  1015,    -1,  1016,    -1,   594,
      -1,   312,    -1,   330,    -1,   304,    -1,   484,    -1,   441,
      -1,   626,    -1,   550,    -1,   539,    -1,   177,    -1,   438,
      -1,   540,    -1,   555,    -1,   519,    -1,   310,    -1,   311,
      -1,    25,    -1,   509,    -1,    -1,    -1,   598,  1019,  1115,
    1020,    14,   863,  1021,    -1,   482,    -1,   844,    -1,   219,
    1091,    -1,   208,  1091,    -1,   222,  1091,    -1,   450,  1091,
     333,    -1,   450,  1091,   385,   926,    -1,    -1,  1028,  1027,
    1031,    -1,    -1,  1029,    -1,  1030,    -1,  1029,  1030,    -1,
     973,    -1,  1035,    -1,  1051,    -1,  1037,    -1,    -1,  1032,
      -1,  1034,    -1,  1032,  1034,    -1,    66,   938,    -1,  1039,
      -1,  1045,    -1,  1057,    -1,  1211,    -1,  1221,    -1,  1078,
      -1,  1470,    -1,   898,    -1,   726,    -1,   972,    -1,   732,
      -1,   726,    -1,  1470,    -1,    -1,   726,    -1,  1470,    -1,
     754,    -1,   367,    -1,    60,    -1,    -1,    -1,    -1,    -1,
    1038,  1040,   938,   430,  1041,  1108,   391,  1042,   753,  1043,
    1036,  1490,  1044,    -1,   210,    -1,    -1,    -1,   557,  1046,
     753,  1047,  1490,   361,    -1,   177,   840,    -1,   863,    -1,
     863,   843,    -1,   356,  1391,    -1,   466,  1391,    -1,  1052,
      -1,  1053,    -1,  1052,  1053,    -1,  1054,    -1,  1035,    -1,
    1050,    -1,    -1,   405,  1055,  1056,    -1,   753,   242,    -1,
     926,    -1,    -1,    -1,    -1,   113,   938,   112,   938,   430,
    1058,  1108,   391,  1059,   753,  1060,  1036,  1490,  1044,    -1,
      -1,   558,  1062,  1077,  1068,  1063,    -1,   362,    -1,    -1,
     234,  1065,  1490,    -1,    -1,    23,  1069,  1070,  1071,   937,
    1066,  1490,    -1,    -1,    23,  1069,   937,  1067,  1490,    -1,
    1064,    -1,  1068,  1064,    -1,    -1,  1009,    -1,    25,    -1,
    1091,    -1,    -1,  1091,    -1,    25,    -1,   251,  1075,    -1,
     263,  1076,    -1,   246,  1076,    -1,   585,    -1,    25,    -1,
    1091,    -1,  1075,    -1,  1076,     5,  1075,    -1,  1091,    -1,
      25,    -1,    -1,    -1,   645,   938,  1079,   753,  1080,  1081,
     646,    -1,  1082,    -1,  1081,  1082,    -1,    -1,   647,  1083,
    1490,    -1,    -1,   624,   938,  1084,  1490,    -1,  1088,  1086,
      -1,    -1,   680,  1089,    -1,  1090,    -1,  1087,    -1,   959,
      -1,   961,    -1,   963,    -1,   955,    -1,   957,    -1,   370,
     863,   843,    -1,    -1,    65,    -1,    65,    -1,  1092,    -1,
    1094,    -1,   190,  1094,    -1,  1094,   619,    -1,  1093,  1098,
      -1,  1093,   938,   458,  1102,   426,    -1,  1093,   938,   458,
    1102,   426,   458,  1102,   426,    -1,  1099,    -1,   938,    -1,
    1095,    -1,   938,   457,  1097,   425,    -1,   938,   457,  1097,
     425,    -1,  1091,    -1,    25,    -1,    20,    -1,   938,    -1,
     938,  1101,    -1,   938,  1101,    -1,   458,  1102,   426,    -1,
     458,  1102,   426,   458,  1102,   426,    -1,  1103,    -1,  1102,
       5,  1103,    -1,   676,    -1,  1105,    -1,  1107,    -1,  1105,
     619,  1106,    -1,  1105,   619,   938,   458,  1102,   426,    -1,
    1105,   619,   938,   458,  1102,   426,   458,  1102,   426,    -1,
     938,    -1,  1096,    -1,    20,    -1,   938,    -1,   938,  1101,
      -1,    -1,  1109,    -1,  1111,    -1,  1109,     5,  1111,    -1,
    1112,    -1,  1110,     5,  1112,    -1,   938,    -1,   938,   619,
     938,    -1,  1091,    -1,  1091,   420,  1091,    -1,    25,    -1,
     944,    -1,    26,    -1,  1114,    -1,  1113,     5,  1114,    -1,
    1091,    -1,  1091,   420,  1091,    -1,  1116,    -1,  1115,     5,
    1116,    -1,  1104,    -1,  1091,    -1,  1119,    -1,  1118,     5,
    1119,    -1,  1091,  1120,    -1,    -1,   587,    -1,   538,    -1,
     938,   458,  1102,   426,    -1,  1123,    -1,  1122,     5,  1123,
      -1,  1091,    -1,  1091,   420,  1091,    -1,   254,   934,   617,
     928,   579,  1482,   684,    -1,    -1,   617,   430,   845,     5,
     845,   391,  1126,    -1,    -1,   568,   430,   845,     5,   845,
     391,    -1,   255,   938,  1125,    -1,   938,    -1,   338,   936,
    1130,    -1,  1131,    -1,   546,   845,    -1,  1132,  1133,  1138,
       8,  1128,    -1,    -1,   617,  1134,   430,   845,     5,   845,
     391,    -1,    -1,   556,   939,    -1,    -1,   350,    -1,   217,
    1433,   266,  1465,  1137,    -1,   563,   931,    -1,   563,   931,
       8,   863,   843,    -1,    -1,   616,   576,  1427,   373,  1427,
      -1,   616,   576,  1427,     5,   373,  1427,    -1,   616,  1427,
       5,  1427,    -1,    -1,   648,    -1,   649,    -1,    90,  1465,
    1140,  1141,    -1,    -1,   616,  1465,    -1,    -1,   616,   576,
    1427,     8,  1427,    -1,   576,  1427,     8,  1427,    -1,   411,
    1143,    -1,  1144,    -1,  1143,     5,  1144,    -1,   203,   925,
      -1,   284,   925,    -1,   329,   925,    -1,   337,   925,    -1,
     293,   925,    -1,   259,   925,    -1,  1011,    -1,   438,  1012,
      -1,   449,  1012,    -1,   561,  1012,    -1,   374,  1012,    -1,
     550,  1012,    -1,   548,   926,    -1,   549,   926,    -1,   400,
     680,    -1,   664,   680,    -1,   291,    -1,   195,    -1,   151,
      -1,   128,    -1,   146,    -1,   137,    -1,  1432,   413,  1148,
     546,  1146,    -1,  1091,    -1,    25,    -1,   402,  1148,    -1,
     402,  1148,     8,  1110,    -1,   939,    -1,    -1,   461,  1158,
     679,   595,  1153,  1091,  1151,   937,   679,  1150,  1154,    -1,
      -1,   667,    26,    -1,   461,  1158,   679,   344,  1091,    -1,
      -1,   535,    -1,    -1,  1155,   282,    -1,  1156,    -1,  1155,
    1156,    -1,    -1,  1007,  1157,  1490,    -1,   844,    -1,    -1,
     603,   931,  1160,  1161,    -1,    -1,   546,  1162,    -1,  1163,
      -1,  1162,     5,  1163,    -1,  1419,    -1,   482,    -1,   220,
    1166,    88,    -1,   220,  1166,   625,  1165,    -1,   220,  1166,
      87,  1165,    -1,   220,  1166,    -1,    25,    -1,   943,    -1,
     938,    -1,    -1,   478,    -1,   145,  1166,  1167,   430,   863,
    1049,   391,    -1,   193,  1166,    -1,    67,  1166,    -1,  1202,
    1210,    -1,   446,    61,    -1,   446,  1173,    -1,  1174,    -1,
    1173,  1174,    -1,    -1,   133,  1175,  1490,    -1,    -1,   199,
    1176,  1490,    -1,    -1,   228,  1177,  1490,    -1,    -1,   216,
    1178,  1490,    -1,    -1,   253,  1179,  1490,    -1,    -1,   201,
    1091,  1180,  1490,    -1,    -1,   224,  1091,  1181,  1490,    -1,
    1192,    -1,  1194,    -1,  1193,    -1,  1183,    -1,  1219,    -1,
    1186,    -1,    -1,   560,   845,  1184,   481,    -1,    -1,   481,
      -1,    -1,   569,    26,  1187,  1185,    -1,   158,    -1,   628,
    1206,    -1,   161,  1206,    -1,   160,  1206,    -1,    -1,  1189,
      -1,  1190,    -1,  1189,  1190,    -1,  1199,  1191,    -1,    -1,
     617,  1206,    -1,   518,  1188,  1198,    -1,   517,  1427,  1198,
      -1,   516,  1197,  1196,  1195,  1198,    -1,    -1,   152,   838,
      -1,   152,   838,     5,   838,    -1,   612,    -1,   613,    -1,
     614,    -1,   615,    -1,  1091,    -1,    -1,   521,    -1,  1200,
      -1,  1199,     5,  1200,    -1,   845,  1233,    -1,   608,   430,
     838,   391,  1218,    -1,    64,  1218,    -1,   495,   430,    20,
     391,  1218,    -1,   412,   430,    20,   391,  1218,    -1,   387,
     430,   838,   391,  1218,    -1,   588,   430,   838,   391,  1218,
      -1,   601,   430,   838,   391,  1218,    -1,   600,   430,   838,
     391,  1218,    -1,    -1,   460,  1203,    -1,  1204,    -1,  1203,
    1204,    -1,   227,    26,    -1,   218,    26,    -1,   301,    26,
      -1,   184,    26,    -1,   256,    26,    -1,   175,    -1,   343,
      25,    -1,   343,  1091,    -1,   176,    25,    -1,   159,    25,
      -1,  1209,    -1,  1205,  1209,    -1,  1207,   108,    -1,  1207,
     110,    -1,  1207,   109,    -1,  1207,    -1,   944,    -1,    26,
      -1,    -1,   460,  1205,    -1,   227,  1206,    -1,   218,  1206,
      -1,   301,  1206,    -1,   184,  1206,    -1,   256,  1206,    -1,
     257,  1206,    -1,   627,    25,    -1,   628,  1206,    -1,   632,
      -1,   629,    -1,   630,    -1,   631,    -1,   636,    -1,   633,
      -1,   634,    -1,   635,    -1,    76,  1206,    -1,    77,  1206,
      -1,    78,  1206,    -1,   343,    25,    -1,   176,    25,    -1,
     399,    -1,    73,    -1,    74,    -1,    -1,   513,   618,  1118,
      -1,   134,  1118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     464,  1212,   938,   430,  1213,  1108,   391,  1214,   753,  1215,
    1171,  1216,  1172,  1217,   239,    -1,    -1,   525,   838,    -1,
     515,  1220,    -1,    -1,  1146,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   105,  1222,   938,   430,  1223,  1108,   391,  1224,
     753,  1225,  1228,  1226,  1172,  1227,   239,    -1,  1208,  1210,
      -1,    -1,    -1,    -1,   154,   430,    25,     5,  1230,   706,
    1231,   391,  1232,   704,    -1,    -1,   383,    -1,   383,   218,
      26,    -1,   383,   218,  1091,    -1,   606,   845,    -1,   606,
     845,   344,  1091,    -1,   606,   845,   162,    -1,   606,   845,
     577,    -1,   606,   845,   544,    -1,  1236,    -1,   172,    -1,
     323,    -1,   281,    -1,  1243,    -1,  1238,    -1,    -1,    -1,
     206,  1239,  1376,   430,  1240,  1247,   391,    -1,    -1,    -1,
     131,  1241,  1376,   430,  1242,  1247,   391,  1244,    -1,   103,
    1245,   391,    -1,    54,   939,    -1,    -1,   268,    -1,  1246,
      -1,  1245,     5,  1246,    -1,   938,   587,    -1,   938,   538,
      -1,   938,    -1,  1248,    -1,  1247,     5,  1248,    -1,  1329,
      -1,  1327,    -1,   120,   938,    -1,   179,    -1,    45,   938,
    1251,    -1,  1252,    -1,  1251,     5,  1252,    -1,  1253,    -1,
    1256,    -1,  1259,    -1,  1264,    -1,  1265,    -1,  1263,    -1,
    1262,    -1,   584,  1254,    -1,   584,   430,  1255,   391,    -1,
    1248,    -1,  1248,   663,   938,    -1,  1254,    -1,  1255,     5,
    1254,    -1,   541,  1258,    -1,   541,   430,  1257,   391,    -1,
    1258,    -1,  1257,     5,  1258,    -1,   938,    -1,   454,  1261,
      -1,   454,   430,  1260,   391,    -1,  1261,    -1,  1260,     5,
    1261,    -1,  1248,    -1,    85,    -1,    86,    -1,    84,    26,
      -1,    56,  1333,    -1,    56,   430,  1266,   391,    -1,    57,
    1267,    -1,    57,   430,  1266,   391,    -1,  1333,    -1,  1266,
       5,  1333,    -1,   938,    -1,   265,    -1,   231,    -1,   164,
    1270,    -1,   141,    -1,   129,    -1,   119,    -1,   117,    -1,
     121,    -1,   178,  1433,    -1,   230,  1269,   459,  1427,   625,
    1427,    -1,   298,   931,   459,  1427,   625,  1427,    -1,    -1,
    1433,    -1,    -1,   845,    -1,   522,   845,    -1,   229,    -1,
      -1,   248,  1274,  1376,  1277,  1275,    -1,    -1,   478,  1276,
     430,  1279,   391,    -1,  1413,    -1,    -1,   430,  1278,   391,
      -1,  1379,    -1,  1278,     5,  1379,    -1,  1280,    -1,  1279,
       5,  1280,    -1,  1419,    -1,   482,    -1,    -1,    -1,   499,
    1282,  1285,  1283,  1286,    -1,   939,    -1,  1290,   932,    -1,
     932,    -1,    -1,    -1,   553,  1287,  1113,    -1,    -1,    -1,
     553,  1289,  1113,    -1,   500,    -1,   554,    -1,   561,    -1,
     374,    -1,   341,    -1,   395,    -1,   377,   845,    -1,   350,
     845,    -1,   237,  1376,   149,   932,    -1,   237,  1376,  1349,
      -1,   513,   618,  1294,    -1,  1295,    -1,  1294,     5,  1295,
      -1,  1296,  1297,    -1,    26,    -1,  1379,    -1,    -1,   587,
      -1,   538,    -1,   276,    -1,   309,    -1,    -1,   326,    -1,
     356,  1302,  1300,    -1,  1465,    -1,    25,    -1,    -1,  1432,
    1304,  1305,    -1,  1334,    -1,  1338,    -1,  1299,    -1,  1434,
      -1,  1298,    -1,  1291,    -1,  1292,    -1,  1281,    -1,  1273,
      -1,  1272,    -1,  1403,    -1,  1449,    -1,   504,  1308,   624,
    1376,   625,  1313,  1307,    -1,    -1,   140,    -1,   167,    -1,
    1309,    -1,  1310,    -1,  1309,     5,  1310,    -1,   470,    -1,
     449,    -1,   438,    -1,   477,  1311,    -1,    -1,   430,  1312,
     391,    -1,  1379,    -1,  1312,     5,  1379,    -1,  1314,    -1,
    1313,     5,  1314,    -1,   462,    -1,  1377,    -1,   235,  1376,
    1316,   616,  1413,  1318,    -1,    -1,   430,  1317,   391,    -1,
    1379,    -1,  1317,     5,  1379,    -1,    -1,   139,    -1,   491,
     430,  1352,   391,    -1,   245,   430,  1322,   391,  1321,    -1,
     296,  1323,    -1,  1324,    -1,  1376,    -1,  1376,   430,  1324,
     391,    -1,  1379,    -1,  1324,     5,  1379,    -1,   475,   430,
    1326,   391,    -1,   258,   430,  1326,   391,    -1,  1379,    -1,
    1326,     5,  1379,    -1,  1325,    -1,  1320,    -1,  1319,    -1,
     399,  1382,    -1,   207,    -1,   938,  1368,  1330,  1331,    -1,
      -1,  1328,    -1,    -1,  1332,    -1,  1333,    -1,  1332,  1333,
      -1,   372,    -1,   157,    -1,   475,    -1,  1321,    -1,   491,
     430,  1352,   391,    -1,   118,  1335,  1337,    -1,  1336,    -1,
    1377,    -1,  1338,    -1,  1337,  1338,    -1,  1315,    -1,  1306,
      -1,   447,  1352,    -1,   368,  1341,    -1,  1418,    -1,  1341,
       5,  1418,    -1,   525,  1352,    -1,   546,  1344,    -1,  1345,
      -1,  1344,     5,  1345,    -1,  1346,    -1,   514,  1346,    -1,
     514,   430,  1347,   391,    -1,  1376,    -1,  1376,  1381,    -1,
    1345,    -1,  1347,     5,  1345,    -1,  1343,  1349,  1350,  1351,
      -1,    -1,  1342,    -1,    -1,  1340,    -1,    -1,  1339,    -1,
    1353,    -1,  1352,     6,  1353,    -1,  1354,    -1,  1353,     7,
    1354,    -1,  1355,    -1,     9,  1355,    -1,  1366,    -1,   430,
    1352,   391,    -1,   442,  1414,    -1,   294,  1414,    -1,    -1,
     441,  1359,    -1,  1420,    -1,  1423,    -1,  1419,   622,   430,
    1361,   391,    -1,  1419,   622,  1414,    -1,  1419,   428,   430,
    1361,   391,    -1,  1419,   428,  1414,    -1,  1362,    -1,  1361,
       5,  1362,    -1,  1469,    -1,  1382,    -1,    -1,     9,    -1,
    1419,  1363,   386,    -1,  1419,  1363,   249,    -1,  1419,  1365,
    1419,    -1,  1419,  1363,   388,  1419,     7,  1419,    -1,  1419,
     556,  1358,  1357,    -1,  1419,   371,  1358,  1357,    -1,  1419,
    1363,    10,  1358,  1357,    -1,    14,    -1,    17,    -1,    12,
      -1,    13,    -1,   252,    -1,    10,    -1,    16,    -1,    15,
      -1,  1364,    -1,  1360,    -1,  1356,    -1,    -1,   585,    -1,
     359,    -1,   475,    -1,  1369,    -1,  1370,    -1,  1372,    -1,
     535,    -1,   535,   430,  1373,   391,    -1,   410,   430,  1374,
    1371,   391,    -1,   471,    -1,   397,   430,  1374,  1371,   391,
      -1,   511,   430,  1374,  1371,   391,    -1,   537,    -1,   407,
      -1,   379,    -1,   357,  1389,   625,  1390,    -1,   357,    -1,
     369,  1389,   625,  1390,    -1,   369,    -1,   369,  1389,   430,
      26,   391,   625,  1390,    -1,   574,    -1,   532,    -1,   423,
      -1,   423,   430,    26,   391,    -1,   423,   430,    26,     5,
      26,   391,    -1,    -1,     5,  1375,    -1,   501,   430,  1374,
     391,    -1,   565,    -1,   299,    -1,   501,    -1,    63,    -1,
      26,    -1,    26,    -1,    26,    -1,    25,   619,   938,    -1,
      25,    -1,   938,    -1,   938,   589,   938,    -1,   938,    -1,
      -1,   458,    26,   426,    -1,   458,    26,     5,    26,   426,
      -1,  1380,    -1,   611,  1380,    -1,   938,  1378,    -1,  1376,
     619,   938,  1378,    -1,  1376,   619,    20,    -1,   938,    -1,
      25,    -1,   410,    -1,   944,    -1,    26,    -1,  1384,    -1,
     395,  1386,    -1,   395,  1385,    -1,    -1,  1389,   625,  1390,
      -1,    -1,  1387,   625,  1387,    -1,   581,    -1,   512,    -1,
     590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,    -1,
     366,   430,    26,   391,    -1,   581,    -1,   512,    -1,   590,
      -1,   552,    -1,   453,    -1,   469,    -1,   366,    -1,   366,
     430,    26,   391,    -1,   581,    -1,   512,    -1,   590,    -1,
     552,    -1,   453,    -1,   469,    -1,   366,    -1,   581,    -1,
     512,    -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,
     366,    -1,   938,    -1,    25,    -1,  1432,   502,   932,    -1,
      -1,  1432,   398,  1284,   436,   595,  1401,  1394,  1398,    -1,
      -1,  1432,   398,  1284,   436,   100,   595,  1402,  1395,  1398,
      -1,    -1,  1432,   398,  1284,   135,  1402,  1396,  1398,    -1,
      -1,  1432,   398,  1284,   136,   100,   595,  1402,  1397,  1398,
      -1,    -1,   288,    -1,   287,  1399,    -1,  1400,    -1,  1399,
       5,  1400,    -1,   938,    -1,   938,   619,   938,    -1,    25,
     619,   938,   619,   938,    -1,  1402,    -1,  1273,    -1,  1148,
      -1,  1404,    -1,  1404,  1398,    -1,    -1,    -1,   470,  1415,
    1405,  1416,  1406,  1412,  1348,  1410,    -1,   470,  1415,  1416,
    1348,  1410,    -1,  1409,    -1,  1427,    -1,   470,  1415,  1416,
    1412,  1348,  1410,    -1,    -1,   524,  1367,  1408,    -1,  1293,
      -1,   331,  1411,  1244,    -1,  1293,   331,  1411,  1244,    -1,
     938,    -1,    -1,   553,  1113,    -1,   470,  1415,  1416,  1348,
      -1,   430,   470,  1415,  1416,  1348,   391,    -1,    -1,   585,
      -1,   359,    -1,   475,    -1,  1417,    -1,  1416,     5,  1417,
      -1,  1419,    -1,  1419,   938,    -1,  1419,    -1,  1420,    -1,
      19,  1420,    -1,    18,  1420,    -1,  1421,    -1,  1469,    -1,
    1414,    -1,   611,   938,    -1,   611,   938,   619,   938,    -1,
    1420,    21,  1419,    -1,  1420,  1441,    -1,  1420,    20,  1419,
      -1,  1420,    18,  1419,    -1,  1420,    19,  1419,    -1,  1382,
      -1,   483,    -1,   427,    -1,   576,    -1,    20,    -1,    64,
      -1,   588,   430,  1367,  1419,   391,    -1,   600,   430,  1367,
    1419,   391,    -1,   601,   430,  1367,  1419,   391,    -1,   608,
     430,  1367,  1419,   391,    -1,   495,   430,  1367,  1419,   391,
      -1,   938,   430,  1422,   391,    -1,   537,   430,  1422,   391,
      -1,   430,  1419,   391,    -1,   443,   430,  1442,   391,    -1,
    1419,    -1,  1422,     5,  1419,    -1,  1382,    -1,  1432,   346,
    1431,  1426,  1408,    -1,  1432,   335,  1431,  1426,   248,  1376,
    1428,    -1,  1432,   335,  1431,  1426,  1091,    -1,    -1,   321,
    1427,    -1,    25,    -1,  1091,    -1,    -1,   430,  1429,   391,
      -1,  1430,    -1,  1429,     5,  1430,    -1,   938,    -1,    25,
      -1,  1091,    -1,    -1,   267,  1433,   595,    -1,   939,    -1,
    1439,    -1,  1438,    -1,  1435,    -1,   316,  1436,   625,  1436,
      -1,   297,  1436,   619,  1437,   625,  1437,    -1,   938,    -1,
     938,    -1,   221,   788,    -1,   292,   788,  1440,    -1,   271,
      -1,   174,    -1,    92,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,   395,     5,  1389,   625,  1390,
      -1,  1469,     5,  1389,   625,  1390,    -1,   395,  1389,   625,
    1390,    -1,    -1,   607,  1444,  1445,   189,    -1,  1446,    -1,
    1445,  1446,    -1,    33,    -1,  1447,    -1,  1448,    -1,   190,
    1469,    -1,   553,  1113,    -1,    -1,    -1,   477,  1376,  1450,
    1453,  1451,  1452,    -1,    -1,   149,   932,    -1,   525,  1352,
      -1,    52,  1457,   391,    14,   430,  1458,   391,    -1,    48,
    1458,   391,    -1,    49,  1458,   391,    -1,   583,  1454,    -1,
      51,  1458,    -1,    50,  1458,    -1,  1456,    -1,  1454,     5,
    1456,    -1,  1379,    -1,  1455,    14,  1459,    -1,  1455,    -1,
    1457,     5,  1455,    -1,  1459,    -1,  1458,     5,  1459,    -1,
     482,    -1,  1460,    -1,  1461,    -1,    19,  1461,    -1,    18,
    1461,    -1,  1463,    -1,  1414,    -1,   611,   938,    -1,   611,
     938,   619,   938,    -1,  1462,    -1,  1382,    -1,   483,    -1,
     427,    -1,   576,    -1,    64,    -1,  1461,    21,  1460,    -1,
    1461,  1441,    -1,  1461,    20,  1460,    -1,  1461,    18,  1460,
      -1,  1461,    19,  1460,    -1,   588,   430,  1367,  1460,   391,
      -1,   600,   430,  1367,  1460,   391,    -1,   601,   430,  1367,
    1460,   391,    -1,   608,   430,  1367,  1460,   391,    -1,   495,
     430,  1367,  1460,   391,    -1,   938,   430,  1464,   391,    -1,
     537,   430,  1464,   391,    -1,   430,  1460,   391,    -1,   443,
     430,  1442,   391,    -1,  1469,    -1,  1460,    -1,  1464,     5,
    1460,    -1,  1466,    -1,   190,  1467,    -1,  1467,    -1,  1100,
      -1,   938,    -1,  1467,   619,  1468,    -1,    25,   619,  1467,
     619,  1468,    -1,    20,    -1,  1121,    -1,   938,    -1,  1466,
      -1,  1466,   420,  1466,    -1,   126,  1471,    -1,   130,  1471,
      -1,   125,  1471,    -1,    46,    -1,   165,  1471,    -1,   123,
    1471,    -1,    47,    -1,   148,  1471,    -1,   147,  1471,    -1,
     122,  1471,    -1,   355,    -1,   620,   625,  1472,    -1,   547,
    1472,    -1,   572,    -1,   533,  1473,    -1,   938,    -1,   589,
     938,    -1,   938,    -1,    -1,    -1,   526,  1475,   845,  1476,
    1490,   325,    -1,    -1,   658,  1480,    -1,    -1,   661,    -1,
     181,    -1,   277,   933,    -1,    69,   933,    -1,   307,    -1,
     306,    -1,   308,   935,  1477,  1478,    -1,   492,  1480,  1478,
      -1,   930,    -1,  1480,     5,   930,    -1,   102,    -1,   132,
     933,    -1,   845,   566,     5,   845,   392,    -1,   508,   845,
      -1,   264,   933,    -1,   101,  1485,     8,  1486,  1484,    -1,
      -1,   546,   845,    -1,   938,    -1,   938,    -1,   247,   933,
      -1,   250,   933,   625,   845,     5,   845,    -1,   250,   933,
     618,   845,     5,   845,    -1,    27,    -1,    -1,  1492,    -1,
    1493,  1198,    -1,  1491,    -1,  1492,  1491,    -1,    -1,  1494,
    1495,    -1,   669,    -1,   670,    -1,   671,    -1,   672,    -1,
     689,    -1,   711,    -1,   725,    -1,   726,    -1,   732,    -1,
     733,    -1,   752,    -1,   820,    -1,   821,    -1,   822,    -1,
     823,    -1,   834,    -1,   835,    -1,   836,    -1,   837,    -1,
     889,    -1,   893,    -1,   924,    -1,   945,    -1,   946,    -1,
     949,    -1,   950,    -1,   951,    -1,   952,    -1,   965,    -1,
     974,    -1,   995,    -1,   996,    -1,   998,    -1,  1002,    -1,
    1017,    -1,  1018,    -1,  1022,    -1,  1023,    -1,  1024,    -1,
    1025,    -1,  1033,    -1,  1048,    -1,  1061,    -1,  1072,    -1,
    1073,    -1,  1074,    -1,  1085,    -1,  1124,    -1,  1127,    -1,
    1129,    -1,  1135,    -1,  1136,    -1,  1139,    -1,  1142,    -1,
    1145,    -1,  1147,    -1,  1149,    -1,  1152,    -1,  1159,    -1,
    1164,    -1,  1168,    -1,  1169,    -1,  1170,    -1,  1182,    -1,
    1234,    -1,  1235,    -1,  1237,    -1,  1249,    -1,  1250,    -1,
    1268,    -1,  1271,    -1,  1301,    -1,  1303,    -1,  1392,    -1,
    1393,    -1,  1424,    -1,  1425,    -1,  1443,    -1,  1470,    -1,
    1474,    -1,  1479,    -1,  1481,    -1,  1483,    -1,  1487,    -1,
    1488,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   931,   931,   934,   937,   943,   949,   956,   960,   960,
     966,   989,   990,   991,   992,   993,  1007,  1008,  1009,  1010,
    1011,  1016,  1017,  1028,  1031,  1034,  1034,  1038,  1041,  1042,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,  1067,  1068,  1071,
    1071,  1086,  1087,  1090,  1096,  1098,  1109,  1111,  1113,  1115,
    1119,  1121,  1183,  1187,  1191,  1191,  1201,  1205,  1208,  1209,
    1216,  1222,  1216,  1235,  1240,  1244,  1235,  1256,  1260,  1256,
    1268,  1273,  1268,  1292,  1299,  1303,  1291,  1329,  1329,  1333,
    1334,  1335,  1340,  1343,  1348,  1352,  1360,  1363,  1363,  1369,
    1373,  1388,  1386,  1404,  1404,  1419,  1419,  1422,  1422,  1426,
    1429,  1429,  1429,  1436,  1437,  1436,  1444,  1444,  1455,  1455,
    1474,  1477,  1480,  1483,  1486,  1489,  1502,  1507,  1507,  1508,
    1508,  1511,  1516,  1516,  1520,  1530,  1544,  1548,  1543,  1558,
    1564,  1572,  1573,  1576,  1576,  1579,  1583,  1588,  1595,  1595,
    1599,  1599,  1606,  1606,  1611,  1611,  1616,  1616,  1621,  1621,
    1634,  1635,  1643,  1644,  1661,  1664,  1667,  1670,  1673,  1676,
    1682,  1693,  1698,  1711,  1715,  1730,  1731,  1735,  1735,  1739,
    1739,  1739,  1740,  1741,  1746,  1746,  1749,  1749,  1758,  1759,
    1760,  1763,  1767,  1768,  1768,  1785,  1785,  1785,  1785,  1789,
    1796,  1797,  1800,  1800,  1803,  1803,  1812,  1809,  1825,  1825,
    1827,  1827,  1829,  1831,  1833,  1835,  1838,  1842,  1842,  1843,
    1843,  1847,  1847,  1859,  1859,  1864,  1868,  1870,  1871,  1874,
    1874,  1874,  1878,  1879,  1880,  1881,  1888,  1889,  1890,  1891,
    1894,  1895,  1896,  1897,  1901,  1906,  1911,  1915,  1918,  1922,
    1923,  1924,  1925,  1926,  1927,  1928,  1929,  1932,  1933,  1934,
    1966,  1970,  1972,  1974,  1974,  1981,  1985,  1985,  1989,  1990,
    1991,  1992,  1993,  1994,  1995,  2001,  2001,  2004,  2006,  2012,
    2014,  2020,  2028,  2028,  2031,  2032,  2033,  2034,  2035,  2036,
    2037,  2043,  2046,  2046,  2059,  2059,  2066,  2067,  2068,  2070,
    2071,  2073,  2075,  2076,  2077,  2078,  2083,  2089,  2095,  2096,
    2098,  2100,  2101,  2102,  2103,  2104,  2105,  2108,  2109,  2116,
    2124,  2124,  2132,  2129,  2144,  2144,  2146,  2146,  2154,  2154,
    2157,  2160,  2161,  2166,  2178,  2182,  2185,  2188,  2189,  2190,
    2191,  2192,  2197,  2204,  2210,  2215,  2219,  2215,  2230,  2232,
    2237,  2242,  2242,  2246,  2246,  2249,  2249,  2255,  2255,  2261,
    2261,  2277,  2280,  2294,  2296,  2298,  2300,  2302,  2304,  2306,
    2312,  2314,  2318,  2320,  2322,  2324,  2326,  2328,  2330,  2336,
    2351,  2354,  2367,  2368,  2369,  2370,  2371,  2375,  2376,  2377,
    2381,  2386,  2393,  2394,  2395,  2396,  2397,  2398,  2399,  2400,
    2401,  2402,  2403,  2410,  2410,  2415,  2415,  2418,  2424,  2432,
    2438,  2448,  2449,  2457,  2464,  2468,  2478,  2482,  2487,  2492,
    2494,  2504,  2517,  2525,  2538,  2543,  2549,  2554,  2559,  2560,
    2566,  2637,  2643,  2648,  2656,  2656,  2671,  2675,  2682,  2685,
    2693,  2704,  2714,  2720,  2729,  2734,  2742,  2745,  2748,  2753,
    2760,  2765,  2770,  2775,  2785,  2793,  2801,  2806,  2810,  2815,
    2819,  2823,  2830,  2833,  2836,  2840,  2844,  2848,  2852,  2860,
    2870,  2875,  2868,  2891,  2896,  2891,  2913,  2913,  2913,  2916,
    2916,  2916,  2920,  2920,  2920,  2924,  2924,  2924,  2928,  2934,
    2940,  2946,  2956,  2956,  2960,  2964,  2965,  2976,  2977,  2983,
    2993,  3003,  3013,  3014,  3017,  3022,  3028,  3032,  3036,  3039,
    3045,  3048,  3051,  3068,  3071,  3077,  3078,  3079,  3083,  3084,
    3085,  3086,  3087,  3089,  3090,  3091,  3093,  3094,  3098,  3099,
    3104,  3105,  3117,  3121,  3116,  3129,  3132,  3146,  3150,  3156,
    3145,  3169,  3170,  3182,  3188,  3182,  3202,  3202,  3204,  3205,
    3209,  3209,  3213,  3213,  3218,  3218,  3225,  3226,  3230,  3230,
    3234,  3234,  3239,  3239,  3246,  3250,  3251,  3252,  3257,  3257,
    3260,  3260,  3264,  3264,  3268,  3268,  3272,  3272,  3277,  3277,
    3282,  3282,  3287,  3287,  3292,  3292,  3308,  3325,  3326,  3327,
    3328,  3329,  3330,  3333,  3333,  3336,  3338,  3341,  3344,  3346,
    3347,  3348,  3350,  3352,  3354,  3356,  3360,  3367,  3369,  3375,
    3380,  3385,  3390,  3390,  3393,  3399,  3404,  3407,  3414,  3414,
    3416,  3417,  3419,  3421,  3423,  3425,  3429,  3438,  3438,  3500,
    3512,  3519,  3519,  3523,  3528,  3534,  3538,  3542,  3548,  3552,
    3556,  3562,  3562,  3570,  3571,  3575,  3575,  3579,  3580,  3583,
    3586,  3586,  3589,  3591,  3591,  3594,  3596,  3596,  3597,  3599,
    3599,  3608,  3612,  3606,  3634,  3634,  3634,  3637,  3639,  3637,
    3646,  3649,  3655,  3666,  3666,  3670,  3676,  3676,  3680,  3681,
    3692,  3693,  3695,  3697,  3702,  3702,  3706,  3705,  3712,  3711,
    3717,  3717,  3722,  3722,  3728,  3728,  3733,  3733,  3738,  3738,
    3743,  3743,  3746,  3746,  3749,  3749,  3752,  3752,  3794,  3795,
    3803,  3804,  3813,  3818,  3823,  3824,  3825,  3829,  3828,  3839,
    3844,  3849,  3849,  3865,  3871,  3872,  3873,  3874,  3877,  3877,
    3880,  3887,  3888,  3889,  3890,  3891,  3892,  3893,  3894,  3895,
    3900,  3900,  3902,  3905,  3905,  3907,  3911,  3914,  3915,  3918,
    3918,  3923,  3926,  3927,  3928,  3929,  3930,  3931,  3932,  3933,
    3934,  3935,  3936,  3937,  3938,  3939,  3940,  3941,  3942,  3946,
    3964,  3964,  3964,  3991,  4002,  4009,  4015,  4021,  4027,  4038,
    4061,  4060,  4077,  4077,  4081,  4082,  4090,  4091,  4092,  4093,
    4100,  4101,  4103,  4104,  4108,  4113,  4114,  4115,  4116,  4117,
    4118,  4119,  4120,  4121,  4122,  4123,  4126,  4126,  4128,  4128,
    4128,  4130,  4134,  4134,  4143,  4148,  4164,  4170,  4142,  4184,
    4198,  4208,  4197,  4221,  4228,  4228,  4233,  4239,  4247,  4252,
    4253,  4256,  4256,  4256,  4259,  4259,  4267,  4273,  4287,  4291,
    4304,  4286,  4322,  4322,  4336,  4347,  4346,  4358,  4354,  4371,
    4368,  4381,  4381,  4383,  4384,  4386,  4387,  4390,  4391,  4392,
    4394,  4399,  4404,  4410,  4412,  4413,  4416,  4417,  4420,  4422,
    4431,  4437,  4431,  4448,  4449,  4453,  4453,  4463,  4463,  4475,
    4478,  4481,  4484,  4488,  4492,  4493,  4494,  4495,  4496,  4500,
    4505,  4505,  4508,  4534,  4593,  4593,  4596,  4600,  4604,  4647,
    4689,  4690,  4691,  4694,  4708,  4720,  4720,  4725,  4726,  4732,
    4792,  4849,  4854,  4861,  4866,  4874,  4880,  4914,  4917,  4918,
    4959,  5002,  5003,  5007,  5008,  5012,  5065,  5069,  5072,  5078,
    5089,  5096,  5104,  5104,  5107,  5108,  5109,  5110,  5111,  5114,
    5117,  5123,  5126,  5130,  5134,  5141,  5146,  5153,  5156,  5162,
    5164,  5164,  5164,  5168,  5188,  5195,  5202,  5205,  5219,  5226,
    5227,  5230,  5231,  5235,  5241,  5246,  5252,  5253,  5258,  5262,
    5262,  5266,  5267,  5270,  5271,  5275,  5283,  5286,  5292,  5293,
    5295,  5297,  5301,  5301,  5302,  5307,  5315,  5316,  5321,  5322,
    5324,  5337,  5339,  5340,  5342,  5345,  5348,  5351,  5355,  5358,
    5361,  5365,  5369,  5373,  5376,  5380,  5383,  5384,  5385,  5388,
    5391,  5394,  5397,  5400,  5403,  5406,  5422,  5430,  5430,  5432,
    5439,  5446,  5461,  5459,  5478,  5479,  5483,  5488,  5489,  5493,
    5494,  5496,  5497,  5499,  5499,  5507,  5516,  5516,  5526,  5527,
    5530,  5531,  5534,  5538,  5552,  5557,  5562,  5567,  5577,  5577,
    5581,  5584,  5584,  5586,  5596,  5605,  5612,  5614,  5618,  5621,
    5621,  5625,  5624,  5631,  5630,  5637,  5636,  5643,  5642,  5646,
    5645,  5648,  5648,  5664,  5663,  5685,  5686,  5687,  5688,  5689,
    5690,  5693,  5693,  5699,  5699,  5702,  5702,  5715,  5716,  5717,
    5726,  5738,  5739,  5742,  5743,  5746,  5749,  5749,  5754,  5769,
    5774,  5780,  5781,  5782,  5786,  5787,  5788,  5789,  5793,  5803,
    5805,  5810,  5813,  5818,  5824,  5831,  5838,  5847,  5854,  5861,
    5868,  5875,  5884,  5884,  5886,  5886,  5889,  5890,  5891,  5892,
    5893,  5894,  5895,  5896,  5897,  5898,  5901,  5901,  5904,  5905,
    5906,  5907,  5910,  5910,  5913,  5913,  5916,  5917,  5918,  5919,
    5920,  5921,  5922,  5923,  5925,  5926,  5927,  5928,  5930,  5931,
    5932,  5933,  5935,  5936,  5937,  5938,  5939,  5940,  5941,  5942,
    5946,  5953,  5962,  5974,  5983,  5994,  5998,  6002,  6008,  5973,
    6021,  6024,  6032,  6044,  6046,  6051,  6059,  6069,  6072,  6076,
    6084,  6050,  6093,  6097,  6101,  6105,  6097,  6115,  6116,  6117,
    6118,  6123,  6125,  6128,  6132,  6135,  6142,  6147,  6148,  6149,
    6154,  6155,  6161,  6161,  6161,  6166,  6166,  6166,  6177,  6178,
    6184,  6185,  6197,  6198,  6203,  6204,  6205,  6209,  6212,  6218,
    6221,  6229,  6230,  6236,  6243,  6246,  6255,  6258,  6261,  6264,
    6267,  6270,  6273,  6280,  6283,  6290,  6293,  6299,  6302,  6309,
    6312,  6319,  6320,  6325,  6329,  6332,  6338,  6341,  6347,  6354,
    6355,  6359,  6365,  6368,  6375,  6376,  6383,  6386,  6391,  6402,
    6403,  6404,  6405,  6406,  6407,  6408,  6409,  6410,  6413,  6416,
    6422,  6422,  6428,  6428,  6439,  6452,  6462,  6462,  6467,  6467,
    6471,  6475,  6476,  6482,  6483,  6488,  6492,  6499,  6502,  6509,
    6513,  6508,  6522,  6526,  6530,  6537,  6541,  6541,  6554,  6558,
    6558,  6573,  6575,  6577,  6579,  6581,  6583,  6585,  6587,  6593,
    6603,  6610,  6615,  6616,  6620,  6622,  6623,  6626,  6627,  6628,
    6631,  6636,  6643,  6644,  6650,  6662,  6663,  6666,  6666,  6671,
    6676,  6681,  6682,  6685,  6686,  6691,  6696,  6700,  6705,  6706,
    6710,  6717,  6721,  6722,  6727,  6729,  6733,  6734,  6738,  6739,
    6740,  6741,  6745,  6746,  6751,  6752,  6757,  6758,  6763,  6764,
    6769,  6774,  6775,  6780,  6781,  6785,  6786,  6791,  6798,  6803,
    6808,  6812,  6813,  6818,  6819,  6825,  6827,  6832,  6833,  6839,
    6842,  6845,  6852,  6854,  6868,  6873,  6874,  6877,  6879,  6886,
    6889,  6895,  6899,  6903,  6907,  6910,  6917,  6924,  6929,  6933,
    6934,  6940,  6943,  6954,  6961,  6967,  6970,  6977,  6984,  6990,
    6991,  6997,  6998,  6999,  7002,  7003,  7008,  7008,  7012,  7020,
    7021,  7024,  7027,  7032,  7033,  7038,  7041,  7047,  7050,  7056,
    7059,  7065,  7068,  7075,  7076,  7105,  7106,  7111,  7119,  7124,
    7127,  7130,  7133,  7139,  7140,  7144,  7147,  7150,  7151,  7156,
    7159,  7162,  7165,  7168,  7171,  7174,  7180,  7181,  7182,  7183,
    7184,  7186,  7188,  7189,  7194,  7197,  7201,  7207,  7208,  7209,
    7210,  7222,  7223,  7224,  7228,  7229,  7234,  7236,  7237,  7238,
    7240,  7241,  7242,  7243,  7245,  7246,  7248,  7249,  7251,  7252,
    7253,  7254,  7256,  7260,  7261,  7267,  7269,  7270,  7271,  7272,
    7277,  7281,  7285,  7289,  7290,  7294,  7295,  7305,  7314,  7315,
    7316,  7320,  7323,  7328,  7333,  7338,  7346,  7350,  7354,  7355,
    7356,  7361,  7364,  7367,  7381,  7395,  7408,  7409,  7413,  7413,
    7413,  7413,  7413,  7413,  7414,  7417,  7422,  7422,  7422,  7422,
    7422,  7422,  7424,  7427,  7433,  7433,  7433,  7433,  7433,  7433,
    7433,  7434,  7434,  7434,  7434,  7434,  7434,  7434,  7436,  7437,
    7440,  7449,  7449,  7455,  7455,  7462,  7462,  7468,  7468,  7476,
    7477,  7478,  7481,  7481,  7484,  7485,  7486,  7491,  7494,  7500,
    7505,  7513,  7526,  7527,  7524,  7545,  7555,  7558,  7563,  7575,
    7578,  7582,  7585,  7586,  7592,  7595,  7596,  7605,  7614,  7619,
    7620,  7621,  7622,  7629,  7632,  7638,  7641,  7651,  7660,  7663,
    7666,  7672,  7678,  7681,  7684,  7687,  7693,  7695,  7697,  7699,
    7701,  7703,  7704,  7705,  7706,  7707,  7708,  7709,  7711,  7713,
    7715,  7717,  7719,  7721,  7723,  7724,  7729,  7730,  7737,  7740,
    7749,  7753,  7760,  7760,  7764,  7764,  7769,  7769,  7773,  7773,
    7777,  7783,  7783,  7786,  7786,  7792,  7799,  7800,  7801,  7805,
    7806,  7809,  7810,  7814,  7820,  7830,  7831,  7839,  7840,  7841,
    7842,  7843,  7844,  7848,  7849,  7850,  7854,  7854,  7866,  7867,
    7871,  7872,  7873,  7877,  7883,  7970,  7974,  7970,  7983,  7987,
    7993,  8001,  8011,  8021,  8033,  8036,  8055,  8081,  8084,  8090,
    8093,  8098,  8101,  8109,  8117,  8130,  8133,  8141,  8144,  8147,
    8155,  8159,  8162,  8165,  8168,  8172,  8173,  8174,  8175,  8176,
    8182,  8183,  8184,  8185,  8186,  8187,  8188,  8189,  8190,  8191,
    8192,  8193,  8194,  8195,  8199,  8205,  8206,  8218,  8239,  8239,
    8243,  8244,  8245,  8246,  8250,  8251,  8252,  8257,  8283,  8334,
    8336,  8338,  8340,  8344,  8349,  8351,  8354,  8356,  8358,  8362,
    8365,  8370,  8375,  8379,  8388,  8389,  8393,  8405,  8408,  8404,
    8427,  8427,  8431,  8432,  8435,  8436,  8437,  8438,  8439,  8440,
    8441,  8446,  8447,  8451,  8454,  8459,  8463,  8468,  8472,  8477,
    8481,  8484,  8488,  8491,  8496,  8500,  8511,  8517,  8517,  8518,
    8519,  8526,  8535,  8535,  8537,  8538,  8539,  8540,  8541,  8542,
    8543,  8544,  8545,  8546,  8547,  8548,  8549,  8550,  8551,  8552,
    8553,  8554,  8555,  8556,  8557,  8558,  8559,  8560,  8561,  8562,
    8563,  8564,  8565,  8566,  8567,  8568,  8569,  8570,  8571,  8572,
    8573,  8574,  8575,  8576,  8577,  8578,  8579,  8580,  8581,  8582,
    8583,  8584,  8585,  8586,  8587,  8588,  8589,  8590,  8591,  8592,
    8593,  8594,  8595,  8596,  8597,  8598,  8599,  8600,  8601,  8602,
    8603,  8604,  8605,  8606,  8607,  8608,  8609,  8610,  8611,  8612,
    8613,  8614,  8615,  8616,  8617,  8618,  8619,  8620,  8621
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
     964,   966,   967,   965,   968,   969,   968,   970,   971,   968,
     972,   972,   973,   975,   974,   974,   976,   976,   977,   977,
     978,   978,   979,   979,   980,   980,   982,   981,   983,   981,
     984,   981,   985,   981,   986,   981,   987,   981,   988,   981,
     989,   981,   990,   981,   991,   981,   992,   981,   993,   993,
     994,   994,   995,   996,   997,   997,   997,   999,   998,  1000,
    1000,  1001,  1000,  1002,  1003,  1003,  1003,  1003,  1004,  1004,
    1005,  1006,  1006,  1006,  1006,  1006,  1006,  1006,  1006,  1006,
    1008,  1007,  1007,  1010,  1009,  1011,  1012,  1013,  1013,  1014,
    1014,  1015,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,
    1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1016,  1017,
    1019,  1020,  1018,  1021,  1021,  1022,  1023,  1024,  1025,  1025,
    1027,  1026,  1028,  1028,  1029,  1029,  1030,  1030,  1030,  1030,
    1031,  1031,  1032,  1032,  1033,  1034,  1034,  1034,  1034,  1034,
    1034,  1034,  1034,  1034,  1034,  1034,  1035,  1035,  1036,  1036,
    1036,  1037,  1038,  1038,  1040,  1041,  1042,  1043,  1039,  1044,
    1046,  1047,  1045,  1048,  1049,  1049,  1050,  1050,  1051,  1052,
    1052,  1053,  1053,  1053,  1055,  1054,  1056,  1056,  1058,  1059,
    1060,  1057,  1062,  1061,  1063,  1065,  1064,  1066,  1064,  1067,
    1064,  1068,  1068,  1069,  1069,  1070,  1070,  1071,  1071,  1071,
    1072,  1073,  1074,  1075,  1075,  1075,  1076,  1076,  1077,  1077,
    1079,  1080,  1078,  1081,  1081,  1083,  1082,  1084,  1082,  1085,
    1086,  1086,  1086,  1086,  1087,  1087,  1087,  1087,  1087,  1088,
    1089,  1089,  1090,  1091,  1092,  1092,  1093,  1094,  1094,  1094,
    1094,  1094,  1094,  1095,  1096,  1097,  1097,  1098,  1098,  1099,
    1100,  1101,  1101,  1102,  1102,  1103,  1104,  1105,  1105,  1105,
    1105,  1105,  1105,  1106,  1106,  1107,  1108,  1108,  1109,  1109,
    1110,  1110,  1111,  1111,  1112,  1112,  1112,  1112,  1112,  1113,
    1113,  1114,  1114,  1115,  1115,  1116,  1117,  1118,  1118,  1119,
    1120,  1120,  1120,  1121,  1122,  1122,  1123,  1123,  1124,  1125,
    1125,  1126,  1126,  1127,  1128,  1129,  1130,  1130,  1131,  1132,
    1132,  1133,  1133,  1134,  1134,  1135,  1136,  1136,  1137,  1137,
    1137,  1137,  1138,  1138,  1138,  1139,  1140,  1140,  1141,  1141,
    1141,  1142,  1143,  1143,  1144,  1144,  1144,  1144,  1144,  1144,
    1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,  1144,
    1144,  1144,  1144,  1144,  1144,  1144,  1145,  1146,  1146,  1147,
    1147,  1148,  1150,  1149,  1151,  1151,  1152,  1153,  1153,  1154,
    1154,  1155,  1155,  1157,  1156,  1158,  1160,  1159,  1161,  1161,
    1162,  1162,  1163,  1163,  1164,  1164,  1164,  1164,  1165,  1165,
    1166,  1167,  1167,  1168,  1169,  1170,  1171,  1172,  1172,  1173,
    1173,  1175,  1174,  1176,  1174,  1177,  1174,  1178,  1174,  1179,
    1174,  1180,  1174,  1181,  1174,  1182,  1182,  1182,  1182,  1182,
    1182,  1184,  1183,  1185,  1185,  1187,  1186,  1186,  1186,  1186,
    1186,  1188,  1188,  1189,  1189,  1190,  1191,  1191,  1192,  1193,
    1194,  1195,  1195,  1195,  1196,  1196,  1196,  1196,  1197,  1198,
    1198,  1199,  1199,  1200,  1201,  1201,  1201,  1201,  1201,  1201,
    1201,  1201,  1202,  1202,  1203,  1203,  1204,  1204,  1204,  1204,
    1204,  1204,  1204,  1204,  1204,  1204,  1205,  1205,  1206,  1206,
    1206,  1206,  1207,  1207,  1208,  1208,  1209,  1209,  1209,  1209,
    1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,
    1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,  1209,
    1210,  1210,  1210,  1212,  1213,  1214,  1215,  1216,  1217,  1211,
    1218,  1218,  1219,  1220,  1220,  1222,  1223,  1224,  1225,  1226,
    1227,  1221,  1228,  1230,  1231,  1232,  1229,  1233,  1233,  1233,
    1233,  1234,  1234,  1234,  1234,  1234,  1235,  1236,  1236,  1236,
    1237,  1237,  1239,  1240,  1238,  1241,  1242,  1238,  1243,  1243,
    1244,  1244,  1245,  1245,  1246,  1246,  1246,  1247,  1247,  1248,
    1248,  1249,  1249,  1250,  1251,  1251,  1252,  1252,  1252,  1252,
    1252,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1255,  1256,
    1256,  1257,  1257,  1258,  1259,  1259,  1260,  1260,  1261,  1262,
    1262,  1263,  1264,  1264,  1265,  1265,  1266,  1266,  1267,  1268,
    1268,  1268,  1268,  1268,  1268,  1268,  1268,  1268,  1268,  1268,
    1269,  1269,  1270,  1270,  1271,  1272,  1274,  1273,  1276,  1275,
    1275,  1277,  1277,  1278,  1278,  1279,  1279,  1280,  1280,  1282,
    1283,  1281,  1284,  1285,  1285,  1286,  1287,  1286,  1288,  1289,
    1288,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1290,  1291,
    1292,  1293,  1294,  1294,  1295,  1296,  1296,  1297,  1297,  1297,
    1298,  1299,  1300,  1300,  1301,  1302,  1302,  1304,  1303,  1305,
    1305,  1305,  1305,  1305,  1305,  1305,  1305,  1305,  1305,  1305,
    1305,  1306,  1307,  1307,  1308,  1308,  1309,  1309,  1310,  1310,
    1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,
    1315,  1316,  1316,  1317,  1317,  1318,  1318,  1319,  1320,  1321,
    1322,  1323,  1323,  1324,  1324,  1325,  1325,  1326,  1326,  1327,
    1327,  1327,  1328,  1328,  1329,  1330,  1330,  1331,  1331,  1332,
    1332,  1333,  1333,  1333,  1333,  1333,  1334,  1335,  1336,  1337,
    1337,  1338,  1338,  1339,  1340,  1341,  1341,  1342,  1343,  1344,
    1344,  1345,  1345,  1345,  1346,  1346,  1347,  1347,  1348,  1349,
    1349,  1350,  1350,  1351,  1351,  1352,  1352,  1353,  1353,  1354,
    1354,  1355,  1355,  1356,  1356,  1357,  1357,  1358,  1359,  1360,
    1360,  1360,  1360,  1361,  1361,  1362,  1362,  1363,  1363,  1364,
    1364,  1364,  1364,  1364,  1364,  1364,  1365,  1365,  1365,  1365,
    1365,  1365,  1365,  1365,  1366,  1366,  1366,  1367,  1367,  1367,
    1367,  1368,  1368,  1368,  1369,  1369,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,
    1370,  1370,  1370,  1371,  1371,  1372,  1372,  1372,  1372,  1372,
    1373,  1374,  1375,  1376,  1376,  1376,  1376,  1377,  1378,  1378,
    1378,  1379,  1379,  1380,  1380,  1380,  1381,  1382,  1382,  1382,
    1382,  1382,  1383,  1384,  1385,  1385,  1386,  1386,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,  1388,  1388,
    1388,  1388,  1388,  1388,  1389,  1389,  1389,  1389,  1389,  1389,
    1389,  1390,  1390,  1390,  1390,  1390,  1390,  1390,  1391,  1391,
    1392,  1394,  1393,  1395,  1393,  1396,  1393,  1397,  1393,  1398,
    1398,  1398,  1399,  1399,  1400,  1400,  1400,  1401,  1401,  1402,
    1402,  1403,  1405,  1406,  1404,  1407,  1408,  1408,  1409,  1410,
    1410,  1410,  1410,  1410,  1411,  1412,  1412,  1413,  1414,  1415,
    1415,  1415,  1415,  1416,  1416,  1417,  1417,  1418,  1419,  1419,
    1419,  1420,  1420,  1420,  1420,  1420,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,  1421,
    1421,  1421,  1421,  1421,  1421,  1421,  1422,  1422,  1423,  1424,
    1425,  1425,  1426,  1426,  1427,  1427,  1428,  1428,  1429,  1429,
    1430,  1431,  1431,  1432,  1432,  1433,  1434,  1434,  1434,  1435,
    1435,  1436,  1437,  1438,  1439,  1440,  1440,  1441,  1441,  1441,
    1441,  1441,  1441,  1442,  1442,  1442,  1444,  1443,  1445,  1445,
    1446,  1446,  1446,  1447,  1448,  1450,  1451,  1449,  1452,  1452,
    1452,  1453,  1453,  1453,  1453,  1453,  1453,  1454,  1454,  1455,
    1456,  1457,  1457,  1458,  1458,  1459,  1459,  1460,  1460,  1460,
    1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,  1461,
    1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,  1462,
    1462,  1462,  1462,  1462,  1463,  1464,  1464,  1465,  1466,  1466,
    1467,  1467,  1467,  1467,  1468,  1468,  1468,  1469,  1469,  1470,
    1470,  1470,  1470,  1470,  1470,  1470,  1470,  1470,  1470,  1471,
    1471,  1471,  1471,  1471,  1472,  1472,  1473,  1475,  1476,  1474,
    1477,  1477,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1479,
    1479,  1480,  1480,  1481,  1481,  1482,  1482,  1483,  1483,  1484,
    1484,  1485,  1486,  1487,  1488,  1488,  1489,  1490,  1490,  1491,
    1492,  1492,  1494,  1493,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495
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
       2,     0,     0,     8,     0,     0,     3,     0,     0,     7,
       5,     2,     2,     0,     5,     4,     1,     3,     3,     3,
       0,     2,     0,     1,     1,     2,     0,     4,     0,     4,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     1,     3,
       1,     3,     2,     4,     1,     1,     1,     0,     4,     5,
       6,     0,    10,     3,     2,     2,     1,     1,     0,     2,
       1,     2,     3,     3,     3,     3,     1,     1,     1,     1,
       0,     3,     1,     0,     3,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     0,     7,     1,     1,     2,     2,     2,     3,     4,
       0,     3,     0,     1,     1,     2,     1,     1,     1,     1,
       0,     1,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     0,     0,     0,     0,    13,     1,
       0,     0,     6,     2,     1,     2,     2,     2,     1,     1,
       2,     1,     1,     1,     0,     3,     2,     1,     0,     0,
       0,    14,     0,     5,     1,     0,     3,     0,     7,     0,
       5,     1,     2,     0,     1,     1,     1,     0,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       0,     0,     7,     1,     2,     0,     3,     0,     4,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     2,     2,     2,     5,     8,
       1,     1,     1,     4,     4,     1,     1,     1,     1,     2,
       2,     3,     6,     1,     3,     1,     1,     1,     3,     6,
       9,     1,     1,     1,     1,     2,     0,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     2,
       0,     1,     1,     4,     1,     3,     1,     3,     7,     0,
       7,     0,     6,     3,     1,     3,     1,     2,     5,     0,
       7,     0,     2,     0,     1,     5,     2,     5,     0,     5,
       6,     4,     0,     1,     1,     4,     0,     2,     0,     5,
       4,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     2,
       4,     1,     0,    11,     0,     2,     5,     0,     1,     0,
       2,     1,     2,     0,     3,     1,     0,     4,     0,     2,
       1,     3,     1,     1,     3,     4,     4,     2,     1,     1,
       1,     0,     1,     7,     2,     2,     2,     2,     2,     1,
       2,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     1,     0,     4,     1,     2,     2,
       2,     0,     1,     1,     2,     2,     0,     2,     3,     3,
       5,     0,     2,     4,     1,     1,     1,     1,     1,     0,
       1,     1,     3,     2,     5,     2,     5,     5,     5,     5,
       5,     5,     0,     2,     1,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     1,     1,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       0,     3,     2,     0,     0,     0,     0,     0,     0,    15,
       0,     2,     2,     0,     1,     0,     0,     0,     0,     0,
       0,    15,     2,     0,     0,     0,    10,     0,     1,     3,
       3,     2,     4,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     0,     0,     8,     3,     2,
       0,     1,     1,     3,     2,     2,     1,     1,     3,     1,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     3,     1,     3,     2,
       4,     1,     3,     1,     2,     4,     1,     3,     1,     1,
       1,     2,     2,     4,     2,     4,     1,     3,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     6,     6,
       0,     1,     0,     1,     2,     1,     0,     5,     0,     5,
       1,     0,     3,     1,     3,     1,     3,     1,     1,     0,
       0,     5,     1,     2,     1,     0,     0,     3,     0,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     3,     1,     3,     2,     1,     1,     0,     1,     1,
       1,     1,     0,     1,     3,     1,     1,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     7,     0,     1,     1,     1,     1,     3,     1,     1,
       1,     2,     0,     3,     1,     3,     1,     3,     1,     1,
       6,     0,     3,     1,     3,     0,     1,     4,     5,     2,
       1,     1,     4,     1,     3,     4,     4,     1,     3,     1,
       1,     1,     2,     1,     4,     0,     1,     0,     1,     1,
       2,     1,     1,     1,     1,     4,     3,     1,     1,     1,
       2,     1,     1,     2,     2,     1,     3,     2,     2,     1,
       3,     1,     2,     4,     1,     2,     1,     3,     4,     0,
       1,     0,     1,     0,     1,     1,     3,     1,     3,     1,
       2,     1,     3,     2,     2,     0,     2,     1,     1,     5,
       3,     5,     3,     1,     3,     1,     1,     0,     1,     3,
       3,     3,     6,     4,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     1,     5,     5,
       1,     1,     1,     4,     1,     4,     1,     7,     1,     1,
       1,     4,     6,     0,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     3,     1,     0,     3,
       5,     1,     2,     2,     4,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     0,     3,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     8,     0,     9,     0,     7,     0,     9,     0,
       1,     2,     1,     3,     1,     3,     5,     1,     1,     1,
       1,     2,     0,     0,     8,     5,     1,     1,     6,     0,
       3,     1,     3,     4,     1,     0,     2,     4,     6,     0,
       1,     1,     1,     1,     3,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     2,     4,     3,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     3,     1,     5,
       7,     5,     0,     2,     1,     1,     0,     3,     1,     3,
       1,     1,     1,     0,     3,     1,     1,     1,     1,     4,
       6,     1,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     4,     0,     4,     1,     2,
       1,     1,     1,     2,     2,     0,     0,     6,     0,     2,
       2,     7,     3,     3,     2,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     2,     2,
       1,     1,     2,     4,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     1,     3,     1,     2,     1,
       1,     1,     3,     5,     1,     1,     1,     1,     3,     2,
       2,     2,     1,     2,     2,     1,     2,     2,     2,     1,
       3,     2,     1,     2,     1,     2,     1,     0,     0,     6,
       0,     2,     0,     1,     1,     2,     2,     1,     1,     4,
       3,     1,     3,     1,     2,     5,     2,     2,     5,     0,
       2,     1,     1,     2,     6,     6,     1,     0,     1,     2,
       1,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     782,     0,  1762,  1765,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   834,   179,     0,   806,   811,
     177,   182,   786,     0,   780,   783,   784,   787,   789,   833,
     788,   828,   829,   831,   183,   134,   131,     0,   127,   129,
     128,   132,  1806,   672,   614,  1769,     0,     0,  1772,     0,
    1768,  1764,  1761,  1759,  1760,  1767,  1766,  1763,   294,  1569,
    1568,   826,   175,   186,   827,   178,   183,     1,   790,   785,
     832,   830,   807,   126,   130,   133,  1776,  1773,     0,  1774,
    1771,     0,     0,   593,     0,     0,   176,   837,   901,   594,
     835,   626,   893,     0,   894,   902,   900,   186,   180,   199,
       0,   184,   200,   229,     0,   813,  1185,     0,     0,   812,
     135,  1173,   820,     0,     0,   803,   805,   802,   804,   781,
     791,   792,   814,   795,   796,   797,   800,   798,   799,   801,
    1775,  1770,     0,   895,   836,     0,     0,   909,   907,   908,
     897,   896,   292,   186,  1109,   193,   187,   186,   192,   226,
       0,   671,     0,     0,     0,     0,   175,   543,   870,   793,
       0,   326,   312,   202,   263,   282,   303,   305,   302,     0,
     324,     0,   311,   304,   308,   314,   298,   313,   186,   315,
     295,   318,   296,   297,   906,   905,     0,    21,    22,    13,
       0,   915,     0,    15,     0,   913,     0,   293,     0,   185,
    1110,   181,     0,   199,   201,   259,   253,   254,   242,   219,
     250,   202,   221,   263,   282,   240,   243,   238,     0,   217,
       0,   249,   241,   246,   252,   234,   251,   186,   255,   186,
     232,   233,   230,   258,     0,     0,     0,     0,   821,   175,
     175,     0,     0,   203,     0,   316,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,   903,
       0,    16,    17,    18,    19,    20,     0,    14,     0,   911,
       0,   627,   188,   191,     0,   189,   190,     0,   196,   195,
     194,   197,   186,     0,   186,   256,   257,     0,     0,   186,
       0,     0,     0,     0,   239,   227,  1186,     0,     0,  1174,
    1812,   544,   871,   815,     0,   208,   209,     0,   275,   277,
     272,   273,   269,   271,   268,   270,   267,     0,   277,   288,
     289,   285,   287,   284,   286,   279,     0,     0,     0,   328,
       0,   331,   333,   216,     0,   215,     0,     0,   186,    11,
      12,   914,     0,   898,   628,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   228,   231,   926,   670,
     838,   926,     0,  1810,  1812,  1109,  1663,   808,     0,   926,
       0,     0,   264,     0,     0,   274,   291,   265,   290,     0,
     283,     0,   306,     0,   300,     0,   325,     0,   330,   320,
       0,     0,   309,   299,   262,   319,     0,     0,     0,     0,
       0,     0,   244,     0,   236,   218,   204,     0,   247,   235,
     260,   932,     0,   927,   928,   926,     0,   822,  1811,  1809,
       0,     0,     0,     0,     0,     0,     0,     0,  1793,     0,
    1275,  1274,     0,  1276,     0,   376,  1273,  1215,     0,     5,
    1272,   377,   374,     0,   379,   173,   469,  1087,     0,     0,
    1282,   123,   373,   372,  1207,   367,   469,     0,  1232,  1784,
       0,   378,   345,     0,     3,     2,     0,   375,  1212,     0,
       0,   368,   365,   380,     0,     0,     0,     0,  1280,  1270,
     371,     0,     0,     0,     0,     0,     0,     0,     0,  1269,
       0,     0,     0,   174,  1209,   364,   363,     0,     0,  1788,
    1787,     0,     0,     0,   136,  1208,   370,   369,     0,     0,
     366,   469,   469,     0,   537,     0,     0,     0,     0,     0,
       0,   469,   769,  1183,     0,     0,  1091,     0,  1777,     0,
     103,     0,     0,   842,     0,     0,     0,     0,   770,     0,
       0,  1686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,     0,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,
    1860,   880,  1861,  1862,  1863,  1864,  1865,  1866,  1867,  1868,
    1869,  1870,  1871,  1872,  1873,  1874,  1875,  1876,  1877,  1078,
    1080,  1075,  1077,  1076,  1079,  1878,  1879,  1206,  1880,  1211,
    1210,  1881,  1882,  1883,  1884,  1885,  1886,  1887,  1888,  1889,
    1890,  1337,  1891,  1892,  1893,  1894,  1895,  1896,  1897,  1898,
    1813,   809,   548,   810,     0,   875,     0,   873,     0,   327,
     210,   211,     0,   276,   281,     0,     0,     0,     0,   329,
     332,     0,   214,     0,   912,     0,   220,     0,   186,     0,
       0,     0,     0,     0,  1187,     0,     0,  1175,     0,     0,
    1219,   615,   616,   794,  1050,  1055,  1786,   608,   122,     0,
       0,  1751,  1750,   986,  1747,  1749,  1801,     0,  1226,     0,
    1222,  1231,     7,     0,     6,     0,  1794,  1051,     0,  1143,
    1142,  1090,  1141,  1089,     0,     0,     0,   424,   426,     0,
    1180,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1536,     0,     0,     0,   418,     0,     0,     0,     0,
     417,     0,     0,   434,     0,   505,     0,     0,     0,     0,
       0,     0,   413,  1283,     0,   383,   382,   389,   430,   427,
     384,   503,   495,   385,   387,   502,   388,   901,   425,   428,
     433,  1271,   504,   823,   403,  1665,  1277,   124,     0,  1054,
     121,     0,   776,    23,   610,   381,     0,   775,  1047,   777,
       0,  1281,   864,   863,   866,   862,   865,  1803,     0,   860,
       0,   609,   959,   861,  1797,     0,  1785,   120,   956,   673,
     954,     0,   606,  1780,   715,   714,     0,   716,   598,   712,
       0,     0,   969,   611,  1336,  1332,  1335,     0,     0,  1021,
    1019,     0,  1013,  1015,  1014,  1012,  1011,     0,     0,     0,
    1010,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1000,   991,   992,     0,  1035,   411,
      23,  1791,     0,  1782,   125,   607,     0,  1018,  1017,  1184,
    1182,  1108,     0,  1654,  1655,  1109,  1197,  1109,  1092,  1093,
    1096,  1111,  1284,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,   901,     0,    68,     0,   101,   586,
     629,     0,  1081,   976,  1085,     0,     0,  1036,  1201,     0,
       0,  1088,   633,   630,   631,     0,   635,   636,     0,   638,
     639,     0,   634,   936,   938,     0,     0,   937,   717,   934,
     682,   930,   892,     0,     0,     0,     0,   645,   646,     0,
       0,   890,   887,   888,   884,   885,   886,   879,   883,   882,
       0,     0,     0,     0,     0,     0,   552,   554,   546,   549,
     550,   877,  1812,   872,   874,   816,     0,   278,   280,   307,
     301,     0,     0,   310,   899,     0,   225,     0,   223,   245,
     237,   229,   248,   933,   175,   929,   839,   175,     0,     0,
       0,  1259,  1260,     0,     0,     0,  1233,  1234,  1236,  1237,
    1238,  1242,  1241,  1239,  1240,     0,     0,  1748,   910,     0,
     988,     0,     0,  1225,  1224,     0,  1218,     0,  1514,  1515,
       0,  1052,     0,    23,  1138,  1140,  1139,   416,   391,   390,
       0,     0,  1115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,  1544,  1542,  1543,  1539,  1541,  1538,  1540,
    1532,     0,     0,     0,     0,     0,   431,     0,     0,   509,
     508,     0,     0,   479,   476,   485,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   510,   511,   512,   445,     0,     0,
     444,   454,     0,     0,   395,     0,     0,   396,   386,   392,
     394,   397,   398,   399,   400,   401,   393,   423,   422,   470,
       0,     0,   406,   407,   404,   405,   946,     0,     0,   350,
      24,   344,     0,     0,  1044,     0,     0,     0,     0,     0,
       0,     0,   963,  1664,     0,     0,   186,     0,     0,     0,
    1782,     0,     0,     0,     0,     0,   137,     0,     0,   973,
     965,   966,   971,  1333,  1334,   889,   409,   334,     0,   538,
     591,   590,   588,   994,   592,   999,   995,   998,   768,   761,
     755,   766,   767,   753,   754,   762,   757,   756,   765,   760,
     763,   759,   764,   752,   758,   745,   751,   996,   997,     0,
    1004,  1008,  1001,  1002,  1006,  1007,  1005,  1003,  1009,     0,
     778,     0,     0,     0,     0,     0,     0,   727,   726,   723,
    1783,  1790,    23,  1104,  1105,  1106,  1107,  1101,  1099,  1198,
    1113,  1098,  1094,     0,     0,  1095,  1778,     0,     0,     0,
       0,    97,     0,    98,     0,     0,     0,    73,     0,     0,
       0,   110,   105,     0,   869,     0,   868,     0,   469,  1083,
       0,   921,   922,   945,   916,   917,   771,   943,  1038,  1203,
       0,  1205,  1204,  1690,     0,     0,     0,  1688,  1691,  1692,
     661,     0,     0,     0,   650,   682,   682,   680,     0,     0,
     683,     0,    25,   649,   652,     0,   659,   655,   891,   881,
    1661,  1662,  1652,  1652,  1302,     0,     0,  1570,     0,   186,
    1285,     0,     0,  1286,  1330,   186,     0,  1331,     0,  1609,
       0,  1299,     0,  1348,  1347,  1346,  1344,  1345,  1343,  1341,
    1338,  1412,  1411,  1339,  1340,  1349,  1579,  1342,  1668,  1667,
    1666,  1350,  1812,  1812,   565,   556,   547,     0,   551,  1812,
     876,   175,     0,   321,   213,     0,   186,   222,   205,  1188,
     175,  1176,  1402,     0,  1401,     0,  1403,     0,  1404,  1262,
       0,  1268,  1264,  1261,     0,     0,     0,     0,     0,     0,
    1258,  1254,  1391,  1390,  1389,  1230,  1229,     0,  1253,  1249,
       0,  1245,  1243,     0,   619,     0,   618,     0,   987,     0,
       0,   985,  1754,  1756,  1755,  1752,  1802,  1799,  1223,     0,
       0,     0,  1216,   469,   342,     0,  1181,     0,     0,     0,
       0,  1609,     0,     0,     0,     0,     0,   527,   513,   518,
       0,   514,   517,   516,     0,     0,     0,     0,     0,     0,
     419,     0,   171,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,   437,   436,   455,   446,   461,   464,   465,
     462,   468,   467,   466,   456,   457,   458,   459,   460,   402,
     447,   451,   469,   463,   450,   469,    92,     0,   429,     0,
       0,  1213,   978,  1048,  1049,  1046,  1045,     0,   867,     0,
       0,   595,     0,     0,     0,   957,   955,     0,   675,   676,
       0,     0,  1781,  1789,     0,     0,   602,     0,   604,   713,
       0,   141,     0,   967,   974,     0,     0,   982,     0,   337,
       0,     0,     0,     0,    23,  1020,   541,     0,     0,     0,
     746,   747,   993,   779,   412,     0,  1027,  1792,   724,   725,
     361,     0,  1109,     0,  1112,  1097,  1812,     0,     0,     0,
     530,     0,     0,     0,     0,    63,    92,     0,     0,   116,
     111,     0,   106,     0,   113,   107,   853,   845,   851,     0,
    1082,     0,  1084,  1086,     0,     0,   925,     0,     0,     0,
       0,  1037,  1202,  1757,  1693,   941,  1694,   939,  1687,  1689,
    1812,   632,   637,   640,   653,   651,   612,     0,   702,   700,
     706,   704,     0,     0,   698,   742,   696,   692,   690,   740,
     718,     0,   684,   694,   935,   931,     0,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,  1517,     0,
    1407,  1408,  1673,  1371,  1429,     0,     0,  1671,     0,     0,
    1611,  1612,  1610,  1592,  1695,     0,  1354,  1360,  1359,  1358,
    1362,     0,  1355,  1356,     0,  1580,  1591,   553,   555,     0,
       0,   568,   560,   562,     0,   557,   558,     0,     0,   576,
     578,     0,     0,   574,   878,   817,   212,     0,     0,   224,
    1144,   840,  1122,  1379,  1381,     0,  1266,     0,     0,     0,
       0,     0,  1256,     0,     0,  1509,  1507,  1494,  1496,  1492,
       0,  1491,     0,  1500,  1487,  1508,     0,  1499,  1484,  1490,
    1506,  1498,  1395,  1481,  1482,  1483,     0,  1251,  1247,     0,
       0,  1235,   617,     0,     0,     0,     0,     0,  1798,     4,
       8,    10,  1513,  1516,     0,   469,   501,   498,   497,   500,
     496,     0,   421,   507,   492,   492,     0,   515,     0,   519,
       0,   282,  1180,     0,  1537,   499,  1180,   506,   420,   266,
       0,  1180,   480,   477,   486,  1180,   483,  1180,  1180,  1180,
       0,     0,     0,     0,     0,     0,     0,     0,   471,    93,
      94,    96,   473,   408,     0,     0,     0,   975,     0,     0,
       0,     0,     0,     0,     0,   186,   674,     0,   599,   601,
       0,     0,   158,   156,     0,     0,   138,     0,   148,   154,
     682,   143,   145,     0,   972,   983,   984,     0,   410,   336,
     341,   597,   335,     0,   338,   343,   469,  1308,   589,   587,
       0,   749,  1026,  1028,     0,   362,  1102,  1100,  1199,  1200,
       0,     0,  1193,     0,     0,     0,     0,    99,     0,     0,
      74,    80,    70,  1812,  1812,   109,   104,   118,   114,     0,
     108,   743,   854,   612,  1812,   844,   843,   852,   977,     0,
       0,   923,   924,   918,   944,   469,     0,     0,  1635,  1527,
    1530,  1636,  1534,  1528,  1633,     0,     0,  1043,  1632,     0,
       0,  1634,     0,     0,     0,     0,     0,  1751,  1529,  1039,
    1040,  1631,  1531,  1623,  1042,  1618,  1621,  1622,     0,     0,
       0,   662,   656,   654,     0,    23,     0,  1812,  1812,  1812,
    1812,   708,   686,   710,   688,  1812,  1812,  1812,  1812,     0,
     681,   685,  1812,   612,   738,   736,   739,   737,     0,     0,
      45,    43,    40,    34,    38,    42,    37,    30,    39,     0,
      33,    36,    31,    41,    32,    44,    35,     0,    28,    46,
     730,     0,   660,  1653,     0,  1651,  1609,  1649,  1596,  1597,
    1589,  1575,  1590,     0,     0,     0,  1016,  1406,  1409,     0,
       0,     0,     0,  1430,  1320,  1291,  1676,  1675,  1674,     0,
       0,     0,     0,  1315,     0,  1314,     0,  1316,  1311,  1312,
    1313,  1304,  1300,     0,     0,  1361,     0,     0,     0,  1584,
    1581,  1582,   567,   572,     0,     0,  1812,  1812,   545,   559,
     582,   570,   584,  1812,  1812,   580,   564,   575,   808,   322,
     206,     0,  1170,  1189,   808,     0,  1177,  1170,     0,     0,
    1263,     0,     0,     0,     0,     0,  1435,  1437,  1439,  1476,
    1475,  1474,  1441,  1457,  1265,     0,  1518,     0,  1380,     0,
    1383,  1521,     0,  1387,     0,  1255,     0,     0,  1560,  1558,
    1559,  1555,  1557,  1554,  1556,     0,     0,     0,     0,     0,
       0,     0,     0,  1393,     0,  1396,  1397,     0,  1250,     0,
    1244,  1246,  1753,     0,     0,     0,  1800,     0,     0,  1227,
     824,     0,     0,  1613,  1615,   489,     0,   490,     0,   529,
       0,   526,   523,   494,   488,  1118,  1545,  1117,     0,   170,
    1116,     0,     0,     0,  1119,     0,  1121,  1120,  1114,   448,
     449,   453,   438,     0,   441,   452,     0,   440,     0,     0,
      92,     0,     0,     0,     0,  1278,  1805,  1804,   596,     0,
       0,    47,     0,   679,   678,   677,  1279,     0,     0,   682,
    1812,  1812,   150,   620,   160,   152,   162,   142,   149,  1812,
       0,     0,     0,     0,     0,     0,     0,  1309,   539,     0,
     748,  1024,     0,  1779,     0,    92,   531,     0,    64,     0,
       0,     0,    77,     0,    92,    92,   117,   112,  1812,  1812,
     102,     0,   855,   849,   857,   856,   846,   535,   904,     0,
       0,  1620,  1619,  1533,     0,  1609,     0,     0,  1477,     0,
    1477,  1477,  1477,  1477,  1624,     0,     0,     0,     0,     0,
       0,  1677,  1678,  1679,  1680,  1681,  1682,  1627,  1758,   942,
     940,   664,   643,   657,   613,   719,     0,   703,   701,   707,
     705,     0,  1812,     0,  1812,   699,   697,   693,   691,   741,
     695,    23,   731,     0,     0,     0,    26,     0,  1656,     0,
    1579,     0,     0,  1588,  1571,  1587,  1410,     0,  1373,     0,
    1319,  1417,     0,     0,  1672,     0,  1669,  1593,     0,     0,
       0,     0,     0,     0,  1696,  1318,  1317,  1305,  1303,     0,
    1364,     0,  1357,     0,     0,     0,     0,   569,   566,   561,
     563,     0,  1812,  1812,   577,   579,  1812,  1812,     0,     0,
    1168,  1169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1167,     0,     0,  1155,  1156,  1157,  1154,
    1159,  1160,  1161,  1158,  1145,  1136,     0,     0,  1192,     0,
    1812,     0,  1131,     0,     0,     0,     0,     0,     0,     0,
    1123,  1124,     0,  1056,     0,  1267,  1440,     0,  1444,     0,
    1457,  1443,     0,  1405,     0,  1458,  1471,  1468,  1469,  1466,
    1473,  1472,  1467,  1470,     0,     0,     0,     0,     0,     0,
    1522,     0,  1523,     0,     0,     0,     0,  1386,  1257,  1385,
    1377,     0,     0,     0,  1511,  1503,  1503,     0,     0,  1503,
    1510,     0,  1527,  1392,  1394,  1398,  1399,  1252,  1248,   990,
       0,   953,     9,     0,  1220,   825,  1053,     0,     0,  1429,
    1599,  1616,     0,   492,   520,     0,   275,   481,   478,   487,
     484,     0,   443,   442,   472,    95,   474,   348,  1214,     0,
       0,  1796,     0,     0,   958,    48,     0,   603,   605,   600,
     728,   159,   157,     0,  1812,     0,     0,     0,  1812,   155,
     144,     0,   147,   146,     0,   964,   968,   340,     0,   542,
       0,  1812,   750,     0,   612,  1103,     0,  1194,    69,     0,
       0,   100,    67,    92,    75,    81,     0,   119,   115,   744,
    1812,   859,   612,   858,     0,   532,     0,   773,   774,   772,
       0,     0,  1644,     0,     0,     0,  1479,  1480,  1478,     0,
    1646,     0,     0,     0,     0,     0,     0,     0,  1041,  1629,
    1630,  1628,  1626,   667,   665,     0,   647,   644,     0,   709,
     687,   711,   689,   720,   734,   735,   732,   733,    29,    27,
       0,  1650,  1605,  1576,  1577,  1573,  1579,     0,  1372,  1609,
    1375,     0,  1293,  1288,  1287,  1290,     0,  1605,     0,     0,
    1729,  1727,     0,     0,  1715,  1726,     0,     0,  1728,     0,
       0,     0,     0,     0,  1751,  1725,  1721,     0,  1713,  1716,
    1717,  1724,  1720,  1744,     0,  1706,  1705,  1709,  1711,     0,
    1704,     0,  1707,  1698,  1306,  1301,     0,  1363,     0,     0,
    1585,  1583,   573,   571,   583,   585,   581,     0,     0,   229,
    1162,  1163,  1164,  1166,  1149,  1147,  1146,  1150,  1151,  1148,
    1165,  1152,  1153,  1137,   950,  1172,   947,     0,     0,  1190,
       0,  1135,  1134,  1129,  1127,  1126,  1130,  1128,  1132,  1133,
    1125,  1178,  1382,  1442,  1436,  1438,  1445,  1447,     0,  1452,
    1445,     0,  1450,     0,  1460,  1459,     0,  1461,     0,  1378,
    1384,  1525,  1518,  1388,  1567,  1565,  1566,  1562,  1564,  1561,
    1563,  1493,     0,  1495,     0,     0,     0,     0,  1501,  1505,
       0,  1485,  1400,   989,  1228,  1221,  1217,  1614,     0,  1418,
    1419,  1421,  1424,  1431,     0,     0,  1477,  1601,  1595,  1552,
    1550,  1551,  1547,  1549,  1546,  1548,   493,   491,     0,   525,
     524,   172,   439,     0,     0,    23,     0,     0,   981,     0,
      49,   961,     0,    23,   161,   151,     0,   622,   624,   163,
     153,   728,     0,   339,  1310,     0,  1025,    23,     0,     0,
      65,     0,    78,    87,     0,    71,   850,   847,   536,  1812,
     919,  1535,     0,     0,     0,  1645,     0,     0,     0,  1643,
       0,     0,     0,     0,  1625,  1642,     0,  1812,   663,   642,
     648,   612,  1660,     0,  1658,     0,     0,  1579,  1579,  1572,
    1374,     0,  1376,  1370,     0,  1292,     0,  1670,     0,  1719,
    1718,     0,     0,  1477,     0,  1477,  1477,  1477,  1477,  1722,
       0,     0,  1702,     0,     0,     0,     0,  1731,  1703,     0,
       0,     0,     0,     0,     0,  1697,     0,  1365,  1368,  1352,
    1366,  1369,     0,   819,   818,   323,   207,   952,   951,   949,
       0,  1171,  1057,  1061,  1063,     0,  1067,     0,  1065,  1069,
    1058,  1059,     0,   841,     0,     0,  1464,     0,  1453,  1456,
    1455,  1463,     0,  1445,     0,     0,  1519,  1524,     0,  1512,
    1504,  1488,  1486,     0,  1489,     0,  1422,     0,  1526,  1425,
       0,  1432,  1433,  1604,  1220,     0,     0,     0,     0,   522,
     521,   475,   349,   346,     0,   979,     0,     0,     0,   960,
     729,   139,   621,    23,   970,   540,  1022,    66,  1195,    83,
       0,     0,    76,    87,    87,  1812,   533,     0,     0,     0,
       0,     0,  1641,  1647,  1637,  1638,  1639,  1640,     0,   666,
     721,     0,  1657,  1606,  1599,  1578,  1574,     0,  1294,     0,
    1599,  1742,     0,     0,  1745,     0,     0,     0,     0,     0,
       0,     0,  1714,  1733,  1734,  1732,  1730,  1712,     0,  1708,
    1710,  1699,  1700,  1307,     0,  1353,  1351,  1586,   948,  1812,
    1812,  1071,  1812,  1073,  1812,  1812,  1060,  1191,  1179,  1446,
    1648,  1448,     0,  1451,  1449,  1465,     0,     0,     0,  1502,
    1426,     0,  1420,  1414,  1415,  1617,     0,  1434,  1428,  1602,
    1325,  1321,  1322,  1327,  1326,  1600,  1220,     0,   351,   980,
    1795,     0,     0,     0,     0,     0,     0,    54,     0,    53,
       0,    51,     0,     0,   140,  1029,    87,    92,    87,    88,
      82,    72,   848,     0,     0,  1608,     0,  1685,     0,   668,
      23,  1659,  1598,  1607,  1298,     0,  1295,  1297,  1594,  1743,
       0,     0,  1741,     0,     0,     0,     0,  1723,  1740,     0,
    1367,  1062,  1064,  1812,  1068,  1812,  1066,  1070,  1454,  1462,
    1520,  1497,     0,  1423,     0,  1413,     0,  1329,  1328,  1324,
    1603,  1553,   357,   355,   347,     0,   353,   359,    56,    61,
      58,    60,    57,    59,    55,     0,    50,     0,   623,   625,
    1033,  1023,     0,  1031,  1196,    84,    79,   534,   920,  1683,
    1684,  1812,   722,     0,  1289,  1739,  1746,  1735,  1736,  1737,
    1738,     0,  1072,  1074,  1427,  1416,  1323,  1812,  1812,   352,
     354,  1812,    52,     0,  1812,  1030,  1032,     0,   664,  1296,
    1701,   358,   356,   360,     0,  1034,    85,   669,   962,    89,
      91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   554,   555,   556,   557,   713,  1739,  1740,   191,   266,
     192,  1139,  1140,  1627,  1967,  3029,  2464,  2465,  2907,  3030,
    3031,   558,   902,  2499,  2205,  2924,  1566,  2203,  2763,  2503,
    2920,  2204,  2764,  3037,  3147,  3159,  2922,  3162,  1788,  1789,
    1790,  1252,  1856,   559,  1263,   907,  1261,  1574,  1866,  1571,
    1864,  1869,  2209,  1262,  1863,  1575,  2208,   560,    18,    37,
      38,    39,    40,    41,   116,   563,   831,  1521,  1166,  1816,
    1820,  1821,  1817,  1818,  2474,  2478,  2179,  2171,  2170,  2172,
    2175,  1117,  1069,  1770,   564,    85,    86,    20,    63,   144,
      98,   257,   100,   101,   202,   280,   102,   103,   244,   230,
     681,  2329,   307,   662,  1687,   334,   335,   231,   289,   282,
     284,   987,   988,   148,   357,   149,   150,   295,   232,   233,
    1507,   395,   245,   248,   246,   247,   316,   372,   373,   375,
     380,   665,   249,   250,   325,   377,   198,    21,    82,   180,
     181,   182,   671,  2328,   183,   253,   242,   328,   329,   330,
     331,  1534,   565,   566,   567,   568,   788,  3018,  2735,  1141,
    3094,  3095,  3096,  3138,  3137,  3141,   569,   570,   571,   572,
     762,  1118,   783,  1133,  1134,  1175,   868,  1176,   764,   765,
     766,   767,   768,   769,   770,  1072,  1119,  2143,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,   718,   771,  1486,  2148,  2150,
    2733,   772,  1456,  2132,  1455,  2131,  1459,  2135,  1457,  2133,
    2115,  2124,   773,   774,   775,   776,  1440,  1441,  1442,  1443,
    1559,   573,  2769,  3043,  2515,   574,   841,  1536,  2491,  1837,
     117,   239,   367,  1355,   968,   969,   970,  1352,  1353,  1674,
    1675,  1676,  2026,  2027,  1356,  1357,  1670,  2030,  2022,  1682,
    1683,  2033,  2034,  2326,  2322,  2323,   575,  1183,    87,  1502,
    1503,  1832,   871,   821,   874,   696,   810,   793,   832,  1925,
      88,   697,   691,  1405,  2174,    89,   778,   576,   577,   923,
     924,   578,   579,   580,   581,   931,  2546,   952,  2789,   953,
    1604,   954,  1922,   955,  2252,   956,  1630,   582,  1600,  2251,
    2545,  2787,  2786,  3121,   118,    22,   583,  1157,  1508,  1509,
    1620,  1301,  1621,  1622,  2262,  2264,  1938,  1937,  1942,  1936,
    1935,  1928,  1927,  1930,  1929,  1932,  1934,   584,   585,   829,
     586,  1297,   938,  3050,   587,  1229,  2743,  1969,  1970,  1623,
    1939,  1872,  2211,   864,  1210,  1540,  1840,  1541,  1206,   588,
     589,   916,  1589,  2519,   590,   591,   592,   593,    23,    68,
      24,    25,    26,   119,   120,   594,   121,    27,   652,    28,
     122,   123,   160,   369,  1361,  2038,  2844,   124,   156,   300,
     595,  2111,    29,    30,    31,    32,    33,    62,    90,   125,
     415,  1370,  2044,   596,   911,  1876,  1578,  1874,  2925,  2510,
    1579,  1873,  2214,  2512,   597,   598,   599,   804,   805,  1265,
     126,   240,   368,   656,   657,   972,  1359,   600,   957,   958,
     601,  1309,   959,   779,    92,    93,    94,    95,  1272,   186,
     140,    96,   702,   137,   194,   195,  1273,  1274,  1883,  1275,
     412,   413,   940,   414,   941,  1596,  1597,  1276,  1277,  1137,
    2645,  2646,  2849,  1414,   819,   820,   602,  1152,  2909,   603,
    2486,   604,  1170,  1171,  1172,  1527,  1525,   605,   606,  1797,
    1827,   607,  1020,  1411,   608,   865,   866,   609,   879,   610,
    1980,   611,  3035,  2494,   612,  1844,  3111,  3112,  3113,  3144,
     870,   613,  1278,  1591,  1909,  1910,   614,  1495,   695,  1032,
     615,   616,   617,  2046,  2649,  2860,  2861,  2979,  2980,  2984,
    2982,  2985,  3073,  3075,   618,   619,  1267,  1583,   620,  1269,
     887,   888,   889,  1245,   621,   622,   623,  1552,  1237,   882,
     201,   890,   891,   780,  2047,  2370,  2371,  2354,   721,   722,
    2042,  2355,  2358,   127,   155,   361,   997,  1692,  2372,  2864,
    1042,   624,   880,   128,   152,   358,   994,  1690,  2359,  2862,
    2043,   906,  2195,  2759,  3036,  1240,   625,   626,   627,   628,
     629,   791,  1795,   715,  1744,   630,  2706,   709,   710,  2108,
    1390,   631,   632,  1006,  1007,  1008,  1402,  1729,  1009,  1726,
    1399,  1010,  1701,  1391,  1011,  1012,  1013,  1014,  1695,  1382,
     633,   800,   781,   634,  1333,  1334,  1645,  2574,  2806,  2293,
    2571,  3055,  3056,  1335,  1655,  2307,  1315,  2012,  2615,  2836,
    2188,  2490,  2013,  1336,  1337,  2717,  3011,  3012,  3013,  3089,
    1338,  1339,  1174,   635,   835,   636,   965,  1340,  1341,  2976,
    1661,  1662,  1663,  2015,  2309,  2839,  2840,  1342,  1990,  2287,
    2803,  1392,  1393,  1378,  2067,  1693,  2068,  1394,  2072,  1395,
    2095,  1396,  2096,  2424,  2425,  1696,  1343,  1639,  1640,  1987,
    1344,  3007,  2891,  3003,  1993,  2439,  2709,  2710,  2711,  3001,
    2440,  1994,  2892,  3008,  2055,  2056,  2057,  2058,  2059,  2866,
    2666,  2989,  2060,  2867,  2868,  2398,  2061,  2399,  2062,  2529,
    1722,  1723,  1724,  2695,  1725,  2421,  2415,  2880,  2069,  2841,
    2402,  2607,  2071,  2889,  1911,   782,  1912,  2223,  1060,  2116,
    2726,  2085,  2691,    61,   637,   638,  2566,  2798,  2280,  2797,
    1666,  2020,  2021,  2284,  1981,  1345,  1982,  2001,  2577,  1432,
    1977,  1978,  2718,  2894,  2796,  2570,  1913,  1653,  2112,  2113,
    3004,  2063,  1915,  1916,  2531,  2991,   639,   640,  1632,  1979,
    2561,  2793,  2794,  1312,   641,   786,  1347,  1348,  1648,  2295,
    1349,  1350,  1998,  2247,  2524,   642,   919,  1286,  1287,  1288,
    1289,  1351,  2002,  2613,  2835,  2304,  2610,  2611,  2612,  2609,
    2597,  2598,  2599,  2600,  2601,  2602,  2955,   703,  1593,   705,
    1415,  1917,    66,    50,    80,    77,   644,   893,  1556,  1160,
    1231,   645,   872,   646,  2161,   647,  1738,   707,  1417,   648,
     649,    44,   362,   363,   364,   365,   366,   650
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2591
static const short yypact[] =
{
    4001,   665, -2591, -2591,   247,   477,   477,   477,   477,   477,
     477,   477,   477,   247,   889, -2591, -2591,   889, -2591,  1156,
   -2591, -2591, -2591,   424, -2591,  4001, -2591, -2591, -2591, -2591,
   -2591,  2208, -2591, -2591, -2591, -2591, -2591,   341,   418, -2591,
     711, -2591, -2591, -2591, -2591, -2591,   247,    88, -2591,  -158,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,  1843,   433, -2591, -2591, -2591, -2591,  2314, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,   247, -2591,
   -2591,    88,   185, -2591,   247,   594,  1156, -2591,   740, -2591,
   -2591, -2591, -2591,   564,   233, -2591, -2591, -2591,   926,   593,
     247, -2591, -2591,  1001,   247, -2591, -2591,   247,   247, -2591,
   -2591, -2591, -2591,   247,   247, -2591, -2591, -2591, -2591, -2591,
    2314, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,  3164,   233, -2591,   288,   423, -2591, -2591,   562,
   -2591, -2591,  1011,   433,   548, -2591, -2591, -2591, -2591, -2591,
    3829, -2591,   247,   608,   944,   247,  1156, -2591, -2591, -2591,
     247, -2591, -2591,   567,   858, -2591, -2591,   695, -2591,   733,
   -2591,   743, -2591, -2591,   759, -2591,   782, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,   823, -2591, -2591, -2591,
     423,  1416,  1236, -2591,   200, -2591,   423, -2591,   242, -2591,
   -2591, -2591,   133, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   567, -2591,   858, -2591, -2591,   840, -2591,   845, -2591,
     832, -2591, -2591,   872, -2591,   890, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591,   895,  1303,   247,   907, -2591,  1156,
    1156,   941,   247, -2591,  -111, -2591,   751,   991, -2591,   807,
    1024,  1432,  1439,   247,  1458,  1464,  1479, -2591,   903, -2591,
     886, -2591, -2591, -2591, -2591, -2591,   423, -2591,   423,  1022,
     210, -2591, -2591, -2591,  1482, -2591, -2591,  1505, -2591, -2591,
   -2591, -2591, -2591,  -111, -2591, -2591, -2591,  1516,  1533,   433,
    1458,  1537,  1540,   949, -2591,  1513, -2591,  1182,  1149, -2591,
    1221, -2591, -2591, -2591,   969, -2591, -2591,  1566, -2591,  1165,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,  1024,  1165, -2591,
   -2591, -2591, -2591, -2591, -2591,  1168,   167,   204,   221, -2591,
    3984, -2591, -2591, -2591,  1185,  1615,   223,  1235, -2591, -2591,
    1416, -2591,   423,  1170, -2591, -2591,  1013,  1604,  1376,   224,
     260,   280,  1210,   379,  1249, -2591, -2591, -2591,   247, -2591,
   -2591,   247,  1281, -2591,  3834,   548,  4508,  2240,   372,   247,
    1624,   509, -2591,   991,  1621, -2591, -2591, -2591, -2591,  1628,
   -2591,  1630, -2591,  1636, -2591,   247, -2591,   247, -2591, -2591,
    1458,  1643, -2591, -2591, -2591, -2591,   218,   423,  1660,   509,
    1248,  1657, -2591,  1663, -2591, -2591, -2591,  1664, -2591, -2591,
   -2591,  1079,  1311,  1698, -2591,   247,  1313, -2591, -2591, -2591,
     247,   220,   247,   247,   220,   220,   917,   247, -2591,   247,
   -2591, -2591,   247, -2591,  1035, -2591, -2591, -2591,   220, -2591,
   -2591, -2591, -2591,   247, -2591, -2591, -2591, -2591,    64,    64,
    6985, -2591, -2591, -2591, -2591, -2591, -2591,   220, -2591, -2591,
     220, -2591, -2591,   247, -2591, -2591,   220, -2591, -2591,   273,
     220, -2591, -2591,  6985,   220,   273,   247,   273,   220, -2591,
   -2591,   139,   220,   220,   139,   220,   247,   139,   220, -2591,
     220,   220,   220, -2591, -2591, -2591, -2591,   273,   220, -2591,
   -2591,   220,    41,   247, -2591, -2591, -2591, -2591,   220,   961,
   -2591, -2591, -2591,   220, -2591,  1294,   273,  6985,    37,    37,
     220, -2591, -2591,   984,   273,  1038,  6985,  6985, -2591,  1658,
    6985,   220,    88, -2591,  6985,   220,  1679,   273, -2591,   220,
    6985, -2591,  6985,    64,   247,   220,   247,    37,   220,   247,
      37, -2591,   247,   255, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   325, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   637, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,   707, -2591,   247, -2591,   649, -2591,  1317, -2591,
   -2591, -2591,  1409, -2591, -2591,  1321,  1324,  1326,  1327, -2591,
   -2591,  1096,  1716,  1331, -2591,   219, -2591,  1421, -2591,  1333,
    1334,  1107,  1336,   247, -2591,   247,  1343, -2591,   345,  1306,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  1118,
    1122,  1283, -2591,  1126, -2591,  1125, -2591,  1737,  -208,   398,
   -2591, -2591, -2591,  1320, -2591,  1341, -2591,  1275,   271, -2591,
   -2591, -2591,  1507, -2591,  6985,  6985,  6985, -2591, -2591,  1330,
    1229,  1340,  1342,  1344,  1346,  1348,  1351,  1356,  1357,  1360,
    6985,  1091,  1363,  1364,  1372, -2591,  6985,  6985,  1373,  1374,
   -2591,  6985,  1375, -2591,  1383,  1384,  1385,  1386,  1388,  1397,
    1398,  1400,  6159, -2591,    71, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,   546, -2591,  1353,
   -2591, -2591, -2591, -2591,  6593, -2591, -2591, -2591,   273, -2591,
   -2591,  1341, -2591,   -71, -2591, -2591,  1500, -2591,   109, -2591,
    1302, -2591, -2591, -2591, -2591,  1770, -2591, -2591,   430, -2591,
    1167, -2591,  1172,  1770, -2591,  1206, -2591, -2591,  1389,    73,
   -2591,  1377, -2591,  1173, -2591, -2591,  1402, -2591,  -131, -2591,
    1175,   183,  -223, -2591,  1118,  1514, -2591,  6985,  6985, -2591,
    1826,   220, -2591, -2591, -2591, -2591, -2591,   266,   266,   266,
   -2591,   266,   330,   266,   266,  1245,   -71,  1245,  1245,  1145,
    1145,  1245,  1245,   -71, -2591,  1840, -2591,    -5,  1841, -2591,
     -71, -2591,    89,    56, -2591, -2591,  6985, -2591, -2591, -2591,
   -2591, -2591,   925, -2591, -2591,   548,  1470,   548,  6985, -2591,
      67, -2591, -2591,  6985,  1417,  1422,  1424,  1426,  1354,  1427,
    1038,  1384, -2591,  1515,   930,  1269, -2591,  1282, -2591, -2591,
   -2591,  1183, -2591,  1853, -2591,  1849,   247, -2591,   250,   142,
    1289, -2591, -2591,  1860, -2591,  1208,  1860,  1862,  1213,  1860,
    1862,  6985,  1860, -2591, -2591,   271,   273, -2591, -2591,  1453,
     356, -2591, -2591,  1446,   273,  6985,  1448, -2591, -2591,  1854,
    1855,  1814, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
    1205,  1205,   220,   220,   220,  2016, -2591, -2591,  1793,   707,
   -2591, -2591,   661, -2591, -2591, -2591,  1428, -2591, -2591, -2591,
   -2591,  3164,  1458, -2591, -2591,  1430, -2591,   399, -2591, -2591,
   -2591, -2591, -2591, -2591,  1156, -2591, -2591,  1156,   756,   134,
    1866, -2591, -2591,   517,   155,   692,  1888, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  1454,  1122,  1125, -2591,   917,
    -156,   996,   247, -2591, -2591,   247, -2591,  1300,  1277,  1308,
    1468, -2591,  1476,    79, -2591, -2591, -2591,  6351,  1729,  1729,
      37,  6985, -2591,    37,    37,    37,    37,  1447,  6985,  1393,
    1359,  6985,  6159,  1488, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,  1295,    37,  1899,  6985,  4869,  6159,  1447,  6985, -2591,
    6159,  1901,   209, -2591, -2591, -2591,  6985, -2591,  6985,  6985,
    6985,  6985,  6985,  6985,  6985,  6985,  6985,  6985,  6985,  6985,
    6985,  6985,  6985,  6985,  6985,  6985,  6985,  6985, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  6985,  6985,
   -2591, -2591,  1497,  6985, -2591,  6985,  1498, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
     247,   273, -2591, -2591,  1924, -2591, -2591,  1310,  1509, -2591,
   -2591, -2591,   917,  1224, -2591,  1224,  1038,   139,  6985,  6985,
    6985,  1511, -2591, -2591,   273,   273, -2591,  1318,  1038,    37,
    1284,   247,   423,    42,    41,   273, -2591,  1314,  6985,  1596,
   -2591, -2591,  1394, -2591, -2591,  1950, -2591,   136,   271, -2591,
   -2591,  1939,  1940, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,   923,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  1294,
   -2591,  1145,  6985,   -86,    37,  1935,  1936, -2591, -2591, -2591,
   -2591, -2591,    96, -2591, -2591, -2591, -2591,  1815, -2591,  1753,
   -2591, -2591, -2591,  6985,    64, -2591, -2591,   247,  1951,    37,
      37, -2591,  1390, -2591,    37,  1355,   273, -2591,   247,   247,
    6985,    39, -2591,  1404, -2591,   301, -2591,  1494, -2591,  1502,
    6985,   967, -2591, -2591,  1365, -2591,  1981, -2591,  1441, -2591,
     273, -2591, -2591, -2591,   917,   273,   198, -2591, -2591, -2591,
   -2591,   247,    37,    37,   211,   356,  1839,  2622,   273,   271,
   -2591,  1455, -2591, -2591,  1950,  1966,  1594, -2591, -2591, -2591,
   -2591, -2591,  1678,  1678, -2591,   232,  1457, -2591,   247, -2591,
   -2591,  1341,  1341, -2591, -2591, -2591,   247, -2591,   247,   -84,
    1341, -2591,   861, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,  1268, -2591, -2591, -2591,
   -2591, -2591,   143,   143,   512,   983, -2591,   731, -2591,   661,
   -2591,  1156,  1978, -2591, -2591,  1978, -2591, -2591, -2591, -2591,
    1156, -2591, -2591,  1341, -2591,   865, -2591,  1575, -2591, -2591,
     865, -2591, -2591, -2591,  1576,  1579,   713,  1581,  1586,  1064,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,   247, -2591, -2591,
     713,  1362, -2591,   345, -2591,  1626,   233,  1399, -2591,  1038,
    1443, -2591, -2591,  1562, -2591, -2591, -2591,  1480, -2591,   247,
     247,   247, -2591, -2591, -2591,   400,  6159,  1631,  1637,   401,
     405,   -84,  1638,  5134,  1639,   -28,  1166, -2591, -2591,   100,
    1640, -2591, -2591, -2591,  5169,  2006,  1091,   409,  1644,  5295,
   -2591,  1647,  3174,  1648, -2591,  6985,  6985,  6985,  5340,  6985,
    5457,  5563,  5726,  6215,  6320,  6351,  6481,  7438,  7486,  6735,
    7599,  7606,  5901,  7631,  1729,  1729,  2593,  2593,  3400,  6159,
    5765,  6014,  1447,  6159,  6048,  1447,  6985,  1611, -2591,  6593,
     247, -2591,  1418, -2591, -2591, -2591, -2591,  1420, -2591,  2037,
    2038, -2591,  2041,  1471,  6985, -2591, -2591,  1429,  2046, -2591,
    1570,  1431,  1862, -2591,  1662,   455, -2591,  1629, -2591, -2591,
    1434,  1063,   247, -2591, -2591,  1632,   220,   997,  6985, -2591,
     247,   247,  6985,    43,   -71,  2049,  2052,  2043,  2051,   330,
   -2591, -2591, -2591, -2591, -2591,   273,  1536, -2591, -2591, -2591,
    2007,  6985,   548,  1104, -2591, -2591,  1755,  2073,  2077,   412,
   -2591,   416,   247,  1692,  1038, -2591,  6985,  1659,  1661, -2591,
   -2591,  1728, -2591,  6985,   449, -2591,  1496, -2591, -2591,   629,
   -2591,  6985, -2591, -2591,  1465,   288, -2591,  1273,   247,  2080,
    7581, -2591, -2591,  1676, -2591,  1677,  2093, -2591, -2591, -2591,
     101, -2591,  1862,  1862,  1440, -2591,  1551,  1556, -2591, -2591,
   -2591, -2591,    37,    37, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,  2084, -2591, -2591, -2591, -2591,    37,  6470,  2099,  2079,
   -2591,  1038,   746,   295,   162,  2008,    53,   984, -2591,   -68,
   -2591, -2591, -2591,  1681,   108,  1341,   186, -2591,  1490,  1487,
   -2591, -2591, -2591, -2591, -2591,   428, -2591, -2591, -2591, -2591,
    1683,  1483,  2109, -2591,  1469, -2591, -2591, -2591, -2591,   273,
     140, -2591, -2591, -2591,  1478,   983, -2591,   247,   247, -2591,
   -2591,   247,   552, -2591, -2591, -2591, -2591,  1691,  1697, -2591,
    1665, -2591,  1667, -2591,  1694,   422, -2591,  6952,   435,    80,
      80,   438, -2591,    80,  6952, -2591, -2591,  1098,  1098, -2591,
    1700, -2591,  1702,  1705, -2591,  1706,  1713, -2591,  1714, -2591,
   -2591, -2591,    38, -2591, -2591, -2591,   439, -2591, -2591,   447,
     247, -2591, -2591,   996,  2120,  1038,   423,  6985, -2591,  2148,
   -2591, -2591, -2591, -2591,   713, -2591, -2591, -2591, -2591, -2591,
   -2591,  1325, -2591, -2591,  1091,  1091,  2128, -2591,  2130,  1571,
    1495, -2591,  1229,  1768, -2591, -2591,  1229, -2591, -2591, -2591,
    1771,  1229,  6159,  6159,  6159,  1229,  6159,  1229,  1229,  1229,
    2136,  2139,  2140,  6985,  1775,  2142,  6985,  1777, -2591,  2164,
   -2591,  6159, -2591, -2591,  1552,   713,   168, -2591,  1038,  6985,
    6985,  6985,  6702,  2167,    86, -2591, -2591,  1038, -2591,  1554,
     247,   247, -2591, -2591,   247,   247, -2591,   863, -2591, -2591,
     503, -2591,  1555,  6985, -2591, -2591, -2591,  2171, -2591, -2591,
   -2591, -2591, -2591,   247,  1862, -2591, -2591,  1633, -2591, -2591,
     459, -2591, -2591, -2591,   273, -2591,  3431, -2591, -2591, -2591,
    1856,  2158, -2591,    37,  1846,  1858,  1726,  1568,  1870,  1763,
   -2591, -2591, -2591,   570,  1838, -2591, -2591, -2591, -2591,  1728,
   -2591, -2591, -2591,   149,   817, -2591, -2591, -2591,  1950,  6985,
    1779, -2591,  1757, -2591, -2591, -2591,  7879,  7879, -2591,  1118,
   -2591, -2591,  1098, -2591, -2591,  3149,  1787, -2591, -2591,  1788,
    1789, -2591,  1790,  1791,  1792,  1796,   247,   -89, -2591,  2222,
   -2591, -2591, -2591, -2591, -2591,  2055, -2591, -2591,   917,   273,
     273, -2591,  1578, -2591,  2203,   -71,   247,  2422,  2422,  2422,
    2422, -2591,  2225, -2591,  2236,  2422,  2422,  2422,  2422,   923,
   -2591, -2591,  2422,    87, -2591, -2591, -2591, -2591,  2217,  2229,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  2230,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,   460, -2591, -2591,
   -2591,  2220, -2591, -2591,  1341, -2591,   -84, -2591, -2591, -2591,
   -2591, -2591, -2591,  1652,  1654,   161, -2591,   -68, -2591,    80,
    1634,   220,  6952, -2591, -2591,  1822, -2591, -2591, -2591,   247,
     247,  1325,   259, -2591,  6985, -2591,  6985, -2591, -2591, -2591,
   -2591, -2591, -2591,   220,    80, -2591,  1341,  1142,  1641,  1649,
    2251, -2591,  2257, -2591,   273,   247,   834,   834, -2591, -2591,
    2258, -2591,  2258,   628,   628,  2258, -2591, -2591,  2240, -2591,
   -2591,  5411,   125, -2591,  2240,  2306, -2591,   125,    80,   865,
   -2591,  7491,  1828,  3708,  1828,   365,  2259, -2591, -2591, -2591,
   -2591, -2591, -2591,   335, -2591,  1341,   535,  1878,  2271,  1670,
   -2591, -2591,   463, -2591,   713, -2591,   465,   376, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  1668,  -125,  2274,  2274,  2276,
    2274,  2274,  2277, -2591,   160, -2591,   865,   247, -2591,   713,
   -2591, -2591,  1685,  1038,  2269,   246, -2591,   247,   466, -2591,
    6985,  1914,   141, -2591,   247, -2591,  1682, -2591,  1915, -2591,
    2286, -2591,  1725, -2591, -2591, -2591, -2591, -2591,  1690, -2591,
   -2591,  1925,  1927,  1928, -2591,  1930, -2591, -2591, -2591, -2591,
   -2591, -2591,  6159,   474, -2591, -2591,   476, -2591,  1931,  6985,
    6985,  2304,   482,  1038,  2321, -2591, -2591, -2591, -2591,  6985,
    1761,  2054,  6985, -2591, -2591, -2591, -2591,  1278,  1938,   503,
     880,   880,  2330,   -82, -2591,  2331, -2591, -2591, -2591,   880,
     247,  1794,  1296,  2336,   247,  -126,  6985, -2591, -2591,   330,
   -2591,  1675,  6985, -2591,  2338,  6985, -2591,   273, -2591,  1035,
     247,   273, -2591,  1961,  6985,  6985, -2591, -2591,   570,  1838,
   -2591,   923, -2591, -2591,  1233, -2591, -2591,  1782, -2591,   423,
    6829,  2045,  2045, -2591,  1733,   -84,  1973,   841,   -17,  1325,
     -17,   -17,   -17,   -17,  1748,  1325,  7581,  1325,  1325,  1325,
    1325, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   107,  1010, -2591, -2591, -2591,  1749, -2591, -2591, -2591,
   -2591,    37,  2422,    37,  2422, -2591, -2591, -2591, -2591, -2591,
   -2591,   -71, -2591,  1190,  1214,  6470, -2591,  1980,  1945,  1325,
    1268,   162,   162, -2591, -2591, -2591, -2591,   488, -2591,  1906,
   -2591,  2371,    80,   520, -2591,  1756, -2591,  2377,  3922,  3922,
    3922,  3922,    80,    80, -2591, -2591, -2591,  1830, -2591,   491,
   -2591,  1759, -2591,   247,   247,  1469,   273, -2591,  2258, -2591,
   -2591,   247,   628,   628, -2591, -2591,   628,  2175,  1773,  1774,
   -2591, -2591,    64,    64,    64,  2361,    64,    64,    64,    64,
      64,    64,  2366, -2591,  2368,    64, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591,  5411, -2591,   273,  1776, -2591,  1952,
    2175,  2374, -2591,  2378,  2380,  2381,  2383,  2384,  2386,  1240,
    2306, -2591,  1952, -2591,   497, -2591, -2591,  1934, -2591,   402,
     383, -2591,  6952, -2591,  6952, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591,  7879,  1988,  7879,  1991,   821,  1325,
   -2591,  2396, -2591,  2127,    80,  1345,    80, -2591, -2591, -2591,
   -2591,  1101,  2399,  1101, -2591,  2421,  2421,   507,  2039,  2421,
   -2591,  2050, -2591, -2591, -2591,   865, -2591, -2591, -2591, -2591,
    1038, -2591, -2591,   713,  2160,  1950, -2591,  1325,   174,  1907,
     544, -2591,  1382,  1091,  1857,  1508, -2591, -2591, -2591, -2591,
   -2591,  6985, -2591, -2591, -2591, -2591, -2591,  1975, -2591,   234,
    1038, -2591,  2438,  2018, -2591, -2591,  2060, -2591, -2591, -2591,
    1902, -2591, -2591,   247,   880,   423,  1371,   247,   880, -2591,
   -2591,    37, -2591, -2591,  6985, -2591, -2591, -2591,    37,  1950,
     273,  2213, -2591,  2428,  1551,  6159,  2430, -2591, -2591,   271,
    2031, -2591, -2591,  6985, -2591, -2591,  2072, -2591, -2591, -2591,
     817, -2591,  1551, -2591,  6985, -2591,   249, -2591,  1841, -2591,
    1101,  1325, -2591,   359,  2075,  2459, -2591, -2591, -2591,  1325,
   -2591,   511,  1325,  1325,  1325,  1325,   247,   519, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  2027,  2126, -2591,  2451, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
     247, -2591,   118, -2591, -2591, -2591,  1268,    80, -2591,   -84,
    2335,   524, -2591, -2591, -2591, -2591,   247,  1923,  2810,  2810,
   -2591, -2591,  7750,  2048, -2591, -2591,  2053,  2057, -2591,  2058,
    2059,  2061,  2062,   247,   572, -2591, -2591,   526, -2591, -2591,
    2488, -2591, -2591, -2591,   528,  2480,  2480, -2591, -2591,   542,
    2489,  2481, -2591,   137, -2591, -2591,    80, -2591,   127,  1879,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,  2287,  3164, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591,  -198,  2495, -2591,   273,  1485, -2591,
    2287, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591,  2259, -2591,  2063,  2055,   187, -2591,
    2063,   187, -2591,  7879, -2591, -2591,  1325, -2591,   256, -2591,
   -2591, -2591,  2044, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,  2110, -2591,  2477,  2121,  2123,  2485, -2591, -2591,
    2125, -2591, -2591, -2591, -2591, -2591, -2591, -2591,   228,  2513,
   -2591, -2591,   247,  2153,   247,  1904,   -17,  2192, -2591,  2096,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  1524, -2591,
   -2591, -2591,  6159,  2143,    37,   -71,  2162,  1038, -2591,  6985,
   -2591,  1968,  2511,   -71, -2591, -2591,   499, -2591, -2591, -2591,
   -2591,   123,  2147,  1862,  2093,  2299, -2591,   -71,  2150,  2151,
    2049,  2113, -2591,  2200,  2154, -2591, -2591, -2591, -2591,  2309,
    2089, -2591,   141,  1098,  1926, -2591,  1098,  2163,  1325, -2591,
    2166,  2168,  2169,  2170, -2591, -2591,  6985,  2129, -2591, -2591,
   -2591,  1551, -2591,   554, -2591,   273,  2019,  1268,  1268, -2591,
   -2591,  1325, -2591, -2591,    80, -2591,  2137, -2591,  2019,  2253,
    2253,  2179,   841,   -17,  7776,   -17,   -17,   -17,   -17,  1947,
    7776,  3922, -2591,  7776,  7776,  7776,  7776, -2591, -2591,    80,
    2539,    80,  3922,   220,  6952, -2591,   273, -2591, -2591,   313,
   -2591, -2591,   247, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
     273,  2495, -2591, -2591, -2591,   273, -2591,   273, -2591, -2591,
    1564, -2591,  2332, -2591,  2334,   160, -2591,   560, -2591, -2591,
   -2591, -2591,   568,  2063,  2569,  2551, -2591, -2591,  1954, -2591,
   -2591, -2591, -2591,  2195, -2591,   174, -2591,   174, -2591, -2591,
    1325, -2591,  2141, -2591,  2160,   153,   295,   247,  2564, -2591,
   -2591, -2591, -2591, -2591,  1038, -2591,  2199,  8072,  2172, -2591,
   -2591, -2591,  1974,   -71, -2591, -2591, -2591, -2591, -2591, -2591,
    2201,   271, -2591,  2200,  2200,   817, -2591,   423,  2206,  1976,
    1101,  1979, -2591, -2591, -2591, -2591, -2591, -2591,  2023, -2591,
   -2591,   247, -2591,  2093,   544, -2591, -2591,   141, -2591,  7729,
     544, -2591,  2212,  7776, -2591,   569,  7776,  7776,  7776,  7776,
     247,   573, -2591, -2591, -2591, -2591, -2591, -2591,  2176, -2591,
   -2591, -2591,  2371,  2093,   127, -2591, -2591, -2591, -2591,  1267,
    1267, -2591,  1267, -2591,  1267,  1267, -2591, -2591, -2591, -2591,
   -2591, -2591,   264, -2591, -2591, -2591,  1325,  2173,  1101, -2591,
   -2591,   574, -2591,  2600, -2591, -2591,  6952, -2591, -2591, -2591,
   -2591,  2604, -2591,   339, -2591, -2591,  2160,  2219,   910, -2591,
   -2591,   266,   266,   266,   266,   266,   266, -2591,  2591, -2591,
     575, -2591,  6985,  1379, -2591,     6,  2200,  6985,  2200,  2049,
   -2591, -2591, -2591,  2376,   311, -2591,  1101, -2591,  1101, -2591,
     -71, -2591, -2591, -2591, -2591,   576, -2591, -2591, -2591, -2591,
    2227,  7776, -2591,  2234,  2235,  2245,  2246, -2591, -2591,  3922,
   -2591, -2591, -2591,  1267, -2591,  1267, -2591, -2591, -2591, -2591,
   -2591, -2591,   174, -2591,  1325,  2371,   153, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,   815, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  8072, -2591,  2633, -2591, -2591,
   -2591, -2591,   686, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   101, -2591,  7729, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,   578, -2591, -2591, -2591, -2591, -2591,   968,   968, -2591,
   -2591,   968, -2591,  6985,   905, -2591, -2591,  2248,   107, -2591,
   -2591, -2591, -2591, -2591,  2249, -2591, -2591, -2591, -2591,   454,
   -2591,   271, -2591,  2049
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2591, -2591, -2591, -2591, -2591,   442, -2591,   536,  -184, -2591,
   -2591,  -858,   240, -2591, -2591, -1562, -2591, -2591, -2591, -2591,
    -478, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -1522, -2591, -1549, -2591,
     493, -2591, -2591, -2591, -2591, -2591, -2591, -2591,   775, -2591,
   -2591, -2591, -2591,  1387, -2591,  1071, -2591, -2591,   -64, -2591,
   -2591,  2608, -2591,  2607,  2284, -2591, -2591, -2591, -2591, -2591,
     842,   471, -2591,   835, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  -102,   938,   347, -2591, -2591,
    2365,   -12, -2591,  2512, -2591, -2591,  2510, -2591,  2450, -2591,
   -2591, -2591,  2379,  2264,  1301,  2375,  -315, -2591, -2591, -2591,
   -2591, -2591,  1304,  -980, -2591, -2591, -2591, -2591, -2591, -2591,
    -141,  2313,  2458,  -200,   904, -2591,  2302,   230, -2591,  2359,
   -2591, -2591, -2591, -2591,  2362, -2591, -2591, -2591, -2591,  -327,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  2293, -2591,
    2295, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  -904,
   -2591, -2591,  -415, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
    2015, -2591, -2591,  1194, -2591,  -809,  -853,  -290, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,   898, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  -291, -2591, -2591, -2591, -2591,
   -2591,  2165, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -1698, -2591, -2591, -2591, -2591, -2591, -2591,  1255, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,  1724, -2591, -2591, -2591,
   -2591,  1023, -2591, -2591, -2591, -2591, -2591, -1230, -2591, -2591,
    1014, -2591, -2591, -2591, -2591, -2591, -2591,  -813,  -668,   899,
    1174, -2591,  -494,   642,  -820,  1449, -2591,   911, -2591, -1794,
      -4,  -214, -2591, -2591, -1744,   457,  1021, -2591, -2591,   859,
    1408, -2591, -2591, -2591, -2591, -2591, -2591,   453, -2591,   163,
   -2591,  1419, -2591,  1108, -2591,   789, -2591, -2591, -2591, -2591,
    -434, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,   914,
   -2591, -1268, -2591,  1094, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  1557,
   -2591, -2591, -2591, -2591, -2591, -2591,   -35, -2591, -2591, -1505,
   -2591, -2591, -2591, -2591,   809, -1677, -2591,  -827, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,  2695, -2591, -2591, -2591,  2602,  2692, -1682, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,    74, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591,  2697, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,  1147, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,  -424,  2242, -2591,
   -2591, -2591, -2591, -2591,  2078, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591,  2071, -2591, -2591,   -60, -2591, -2591,  1146,
   -2591, -2591, -2591,  -694,  -195,  2465, -2591, -2591, -2591, -2591,
     618, -2591,  -716,  2064,  1437, -1933,   818, -2591,  1155,  1801,
      97,  -105, -2591, -2591, -2591,  1592, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591,  1529, -2591,  1113, -2591,
    -371, -2591, -2591, -2591, -2591, -2591, -2591, -2591,  -361, -2591,
   -2591, -2591, -2591, -2591, -2591,   516, -2591,  1608,   658, -2591,
   -2591, -2591, -2591, -2591,   382, -2591,  -104, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,  1869, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
    -331, -2591,  1517,  1686, -2591, -2591,   389, -2591,  -429, -2591,
   -2591,   410,   716, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
    -114, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2590, -2591,  1740,   972,
    -987, -2591, -2591, -2591,  1367, -2591, -1361, -2591, -2591, -2591,
   -1365, -2591, -2591, -1328, -2591, -2591, -2591, -2591,  1391, -2591,
   -2591, -2591, -2591, -2591, -2591,   783, -2591, -2591, -2591, -2591,
   -2591, -2591,  -348, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591,  -310, -2591, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591, -2591,   760, -2591, -2591, -2591,  -194, -2591, -2591, -2591,
   -2591, -2591, -2591,   378, -2591, -2591,   735, -2591,  1076, -2591,
   -2591, -2591, -2591, -2591, -2591,  -976, -2591, -2591, -2591, -2591,
   -1397, -2591, -2591, -2591, -2591, -2591, -2591, -1988,    76, -2591,
   -1673,   346, -2591, -2591, -1678,   404,   403,   737, -2591, -2435,
   -2178, -2591, -2591,   119,  -201, -2591, -2591, -2591, -2591, -1895,
   -2591, -2591, -2591, -1303, -2591, -2591,  -589, -2591,  -710,  1474,
     111, -1582,   729, -2591,  -542, -2591, -2591, -2591, -2591,  -711,
   -2591, -1659, -2320,  2778, -2591, -2591, -2591, -2591, -2591, -2591,
   -2039, -2591,   481, -2591, -1320, -2591,  1833, -2591, -2591,  -784,
     -97, -2591, -1602,   -96,   225,   510,  -872, -1400, -1946,   369,
    -277, -1392, -1834, -2591,   577, -2591, -2591, -2591,  1501,  -466,
   -2591, -2591,  -132,  1852, -2591,  1161, -2591, -2591, -1295,   239,
   -2591, -2591, -2591, -1796,    11, -2591, -2591, -2591,  1532, -2591,
   -2591, -2591, -2591, -2591, -2591, -2591, -2591, -2211,    -7, -2591,
   -2253, -1726, -2334,  -903, -2591, -2591,     9,  -426,  -411,  -532,
    1093,   322,    19,  2623,   144, -2591, -2591, -2591, -2591, -2591,
    1671, -2591,  -474, -2591, -2591, -2591, -2591, -2591, -2591, -2591,
   -2591,  -358,  1452,  2468, -2591, -2591, -2591, -2591
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1809
static const short yytable[] =
{
      43,   270,  1033,   388,   115,  1030,   260,  1018,   827,    58,
      60,  1368,  1223,    60,   286,   704,  1819,  1860,  1401,    34,
     723,  1179,  1379,  1232,   133,  1205,  2077,  1606,  1607,  1177,
    1061,  1751,  1727,  1649,   419,  1185,  1186,   258,  1187,  1728,
    1207,  1208,    76,    79,    34,   873,  2604,  2605,  2606,  2086,
      72,    99,  2221,  2222,   238,  2297,   115,  2117,  1702,   885,
     809,  1224,  1516,   692,    42,  1968,   692,   692,    42,    42,
      42,  2176,  1243,   927,   130,   672,   930,    79,  1155,  2213,
     692,  1138,   340,   836,  1299,   142,   293,   129,   271,   139,
     719,  2608,  1224,  2693,  1224,   271,   146,  1127,   704,   692,
     151,  1222,   692,   153,   154,  1028,  2163,    42,   692,   157,
     158,  1028,   692,    42,   921,    42,   692,  2070,  2073,  1758,
     692,  2073,  1294,  2437,   692,   692,  1759,   692,  1224,  1424,
     692,    99,   692,   692,   692,   203,  1304,   301,   302,   129,
     692,  1528,   840,   692,  1317,  2024,  2437,   396,   234,  2271,
     692,   237,   277,  1984,    42,   692,   241,   271,   278,   279,
     763,    42,   692, -1807,   802,   784,    42,  1321,  1017,  2543,
    1225,  1226,   381,   692,  2212,  1283,    42,   692,  1028,  3010,
      42,   692,    42,   795,   271,  2422,  1890,   692,    42,    42,
     692,  1214,  1215,   883,   275,    42,  1143,  1144,  1914,  1028,
    2771,    42,   675,   943,  1529,   268,  1530,   690,  1531,   383,
      42,   271,  1889,  1890,    42,   268,  1528,   294,  2670,  1295,
     837,   838,  2164,   268,   268,   131,   385,   869,   391,   401,
     876,  1283,   298,  2224, -1807,  2871,   886,   892,   304,  2736,
     908,  2563,  1988,   785,   912,  2093,   785,    42,  2811,   332,
     918,   268,   920,  1028,   268,    42,   794,  1991,  1545,  2356,
     785,  2875,  2269,  2487,   785,   403,   271,   272,   273,    42,
     346,   811,   348,   730,    42,  1650,   785,    99,   794,   271,
     933,   934,    42,  1451,   822,   143,  2833,   794,   271,  1889,
    1890,    42,  1180,    42,   833,   271,   933,   934,    42,   839,
      42,  1615,   561,   651,  3009,  2412,   875,  2298,  2299,  2300,
    2301,  2302,  1819,   184,  2291,    42,   268,   822,  2974,   305,
     883,   822,    42,  1168,  1576,   822,   394,  1162,  1220,    84,
    1023,   794,  1284,  2562,   794,  2532,  2533,  2534,  2535,    84,
    2847,  2235,  2526,   394,  2385,  2386,   306,  2387,  2388,  2389,
    2390,  2391,  2392,   943,   411,  1188,  2327,   411,    84,  2114,
    1996,  1299,  2360,  1755,  2773,   411,    65,  1634,  1635,   136,
     943,  2382,    73,    84,  1550,  2379,  2475,   700,  1570,  1024,
    1221,   332,  2382,   332,   407,   643,   653,  1598,  1284,  2848,
     942,  1651,  2385,  2386,  1169,  2387,  2388,  2389,  2390,  2391,
    2392,   998,   999,  1025,  1366,  1224,  1224,  2288,  2382,  1323,
    1224,   411,  1279,  1401,  1224,   824,   688,  1853,   693,   694,
    1409,  1224,   701,   706,    67,   708,  3090,  2049,   711,  1000,
    1001,  1002,  2310,    65,  1255,  1619,  1332,  2094,  2995,   694,
    2049,   187,   188,  2074,  2097,    84,   777,    36,  2032,   189,
      42,  2035,  2099,  2975,   700,    42,    84,  1997,  2527,   694,
    1410,    84,  1535,    84,  2189,  2275,  2070,    81,  2406,   777,
    2406,  2433,   694,   261,   262,   263,   264,   265,    84,  2451,
    2954,  2451,   812,   692,  1407,    84,  2954,  2433,  1163,  2963,
    2964,  2965,  2966,  2567,  1135,  2873,  2616,   946,   828,   830,
    2413,  1652,  2404,  2226,   386,   701,  1300,  1189,  2180,  1546,
     689,   689,  2697,   777,   828,   828,  2778,   261,   262,   263,
     264,   265,   777,   777,  2778,   904,   777,  2799,    79,  2804,
     777,  2821,  2488,  2821,  2509,  1577,   777,  2476,   777,    42,
     922, -1807,   922,   828,    42,   922,   828,  2829,   922,  1427,
    1428,  1833,  2181,  1543,  1238,  1892,  1241,  2754,   382,  2941,
    2667,  1756,  2667,   405,  1380,  2992,  1425,  1165,  2528,   689,
    1893,  1429,  1430,  2992,  3061,  2772,  2279,  1586,  3061,  3082,
    3105,  3123,  1892,  2821,   138,  1397,   869,  2393,  1447,  2838,
    2286,    42,  1316,  1408,  1280,   384,   739,  1893,   886,   943,
     945,  2456,   825,  1246,   692,   692,   692,  2737,   704,  2114,
    3047,  1643,  1644,    84,   392,   402,  3160,  1260,  2967,  3060,
    1654,   743,  3063,  3064,  3065,  3066,   269,   875,  1227,  1156,
    1835,  1329,  1329,  1992,  1190,  2393,   343,  1924,  2357,   935,
    1191,  1192,  1193, -1807,   674,   984,  2497,   946,  1985,  2544,
     971,   404,  1576,  1300,  1363,  2505,  2506,  2225,  2885,  1892,
    1194,  2380,  2834,  1694,   946,  2285,   986,  1364,  1636,   944,
     827,  2795,  2431,  2742,  1893,  2770,   910,    78,  3081,   993,
    1497,   411,  2876,   274,  1244,  1512,  2025,  2438,  2708,  1760,
     274,  2065,  1511,    35,    36,  1285,   701,  2065,  1784,  1924,
    2757,  1787,    84,   826,   752,  2296,  2394,   826,  1517,   826,
    2572,  1029,  1841,  2558,   945,  1228,  1492,  1230,  2767,    42,
     777,   777,   777,  1498,   803,  2078,  3119,  3126,  3120,  2744,
    1547,   704,  2427,  2749,  1145,  1764,   777,  3118,  2428,    35,
      42,   936,   777,   777,  2153,  2727,  2408,   777,  1314,   839,
     875,  1285,   274,  1532,  2394,  1560,  2383,  2109,  2945,  2946,
    1563,  1533,  1384,  2395,  2065,  1976,  1181,  2410,  1195,  2003,
     408,  1196,  1878,    42,  2522,  1385,  1561,   689,  2004,   274,
     777, -1807, -1807, -1807, -1807, -1807,    97,  1029,  1868,  1026,
    1367,  1746,  1749,  2663,  1281,  2318,  1750,   757,  3161,  1003,
    1765,   132,  2005,  1854,  2827,  2006,   274,  1855,  2109,   759,
     760,  2395,  2079,  2050,  1197,  1555,  3131,   761,  1602,  1603,
    1182,  2896,  2680,  2007,  2683,  2521,  2064,  1282,  2080,  2075,
    2098,  2673,    45,   777,   777,  2011,   134,  2530,  2100,  2667,
   -1807,   951,  2303,  2530,  1914,  2539,  2540,  2541,  2542,  1198,
    2190,  2276,   141,   190,  2407,  2947,  2409,  2434,  1499,  1500,
    1501,   274,  2943,  1577,  2774,  2452,   699,  2453,    42,  1199,
    1200,  2081,   777,  2458,   274,  2714,  2036,  3087,  1523,  2568,
    1201,  1809,  2617,   274,   777,  1202,  1004,  2114,  2662,   777,
     274,  2396,  1369,   946,  1253,  1371,  1669,  3000,  2698,  3002,
     660,  2470,  2779,  2973,   261,   262,   263,   264,   265, -1807,
    2785,  2082,  1271,  1372,    59,  2805,    42,  2822,  2953,  2828,
    2956,  2957,  2958,  2959,  1203,  2912,  3088,   777,  2008,  1005,
   -1807,   143,  1544,  2830,   661,  1995,    84,  1384,    19,  2396,
    2083,   777,   699,  1734,    42,  2942,   145,  1386,  1188,  2084,
    1385,  2993, -1807,   886,  2762,  1406,  1204,  2397,  1384,  2994,
    3062,  2564,  2565,    19,  3068,  3083,  3106,  3124,  3145,  3150,
    1569,  1385,   960,   947,   948,   949,  1129,  1581,  1515,   416,
    1584,  1615,  2009,   961,   950,  2800,   834,   658,    42,  2010,
    2569,  1875,  1387,  2401,  1974,  1381,   654,  2940,  2573,  1389,
    1398,  1389,  2820,   135,   136,  2397,   147,  2677,  1388,   877,
      46,    42,   701,  2827,  2827,   701,  1412,  1413,  1416,   655,
     196,   708,  1372,    42,    47,   197,  1812,  1573,  1656,  1813,
     136,   700,  1677,   686,  2837,   962,   828,   777,   235,   828,
     828,   828,   828, -1807,   777,  2114, -1807,   777,  1148,    48,
     963, -1807,  1373,  3139,  2177,  1149,   236,  2715,   828,  1834,
     777,   712,    42,   883,   777,    42,  1130,  2255,  2716,   200,
    2674, -1807,   777,  2375,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,  3134,  2962,  1211,    49,  1859,  2928,
    1189,   717,   243,  1218,   777,   777,  2970,   700, -1807,   777,
    1615,   777,  1401,  2696,  2929,  1619,  2700,  2931,  1931,  1933,
    2426,   789,  1400,  2944,  1421,   251,  1487,  1705,  1374,  2114,
    1848,    42,  1745,  1814,   798,  2950,  1815,  2777,   701,   964,
    2780,  2781,  2782,  2783,   777,   777,   777,   699, -1807,    42,
   -1807,   700,  1943, -1807, -1515,   828,  2972,  1514,  1615,  1518,
     828,  1373,  3092,   252,   777,  1973,  3093,  1387,   692,  2801,
      83,  2290,    42,   909,    84, -1807,  1678,   913,  1642, -1807,
    2378,   917,  2381,  1388,  1646,  1436,  1375, -1807,  1387,   255,
    1437,  1783,  1439,  2308,  1786,  1679,  1680,   135,   136,  1135,
   -1807,   254,     2,     3,  1388,  1615, -1807,  2675,  1264,  2676,
      42,  1677,   256,  1018,  1803,  1681,  2554,    42,   777,   276,
     828,  1847,  2948,   281,  -266,    84,  1812,  1190,    84,  1813,
    1310,  1376,    42,  1191,  1192,  1193,  2523,  1374,  1828,   777,
    2556,    42,  1501,  1557,  1619,   828,   828,  1377,   259,  1493,
     828,    42, -1807,  1194,  1567,  1568,   777,  3092,  2511,  1685,
      42,  3093,   267, -1807,  2278,  2658,   777,    42,  1691,  2104,
     287, -1807, -1807,   654,  3053,   288,   692,   339,     5,     6,
     701,     7,     8,  1867,  2874, -1807,     9,   922,   828,   828,
     290, -1807,  1619,  1881,    84,   973,   655,   692,  2467,  1657,
      42,  2435,   291,    10,    11,    42,  2311, -1807, -1807, -1807,
    1658,  -266,  1824,  3014,  1638, -1807,  2482,  1029,  1029, -1807,
     292,    12,  1647,    42,  1647,   296,  1029,  -266,  3085,   297,
    2154,  1659,  2155,  1814, -1807,    84,  1815,   299,  1660,  1619,
    1376,  2166,  3052,  1886,  1887,  1888,   966,   967,  3058,   271,
    1889,  1890,    42,  1539,   986,  1678,  1377,   309,  1615,  2196,
    1257,  1195,  2492,  1706,  1196,  2681,  1028,  2518,    42,  1029,
    -266,   303,    42,    84,  1679,  1680,   308,  2489,  1436,  1251,
      84,    42,  1389,  1437,  1438,  1439,  2933,   135,   136,  1891,
     318,  2747,    13,  1398,  1681,    84,  1389, -1807,    42,  3108,
   -1807,  3040,  3041,   817,    84,   926,    42,  1197,   929,  2114,
    -266,   932,   823,  2553,    84,  1741,  1742,  1743,  1434,  1435,
     839,  1707,   842,    84,  1585,   136,  2596,  2596,  2596,  2596,
      84,   843,   317,  1708,   261,   262,   263,   264,   265,  -266,
     844,   875,  1198,  1709,   310,   845,  2704,  2106,  -266,  2702,
    1258,   777,   777,   777,  2110,   777,   925,  1053,   326,   928,
     311,  1710,  1199,  1200,  2078,   327, -1807,  2684, -1807,   720,
     720,  1711, -1807,  1201,  1712, -1807, -1807,   319,  1202,  1404,
     342,    42,   777, -1807,   333,   777,  1794,  1713,  3115,   846,
     336, -1807,  1619,   320,  2018, -1807,    42,   847,  3005,  2416,
     777,  2418,  2419,   312,  3014,   337, -1807,  2248,   344,  2156,
    2157,  1501,  2160,  3097,  3114,   700,  3116,  1203,  1822,  2121,
   -1807,  2122,   338,  2669,   777,  2672,  1829,  1830,   777,   828,
    3110,   345,  2729,  2183,  2730,  1714,   321,  1233,  1234,  1235,
    1236,  2105,   349,   313,  1054,  2186,  2852,   777,  2899,  1204,
    2900,  2079,  2423,   848,  2685,  1664,  1665,  3057,  1857,   350,
    1055,  2123,   777,   353,   720,  1715,   354,  2080,   355,   777,
    2686,   356,   314,   359,   937,  1716,   322,   777,   849,   360,
    1657,   315, -1807,  1882,  1271,   850,  1907,   851,   370,  2217,
    3097,  1658,   371,    16,  2220,   374,  1717,   852,   379,  1718,
    1494,  1719,  1494,  1056,  3079,   323,  1594,  3110,   828,   828,
    2081,   389,  1659,  2687,   324,  1034,  1035,  1036,  2853,  1660,
     390,   787,   828,   853,  1672,  1673,   393,   692,   397,  1720,
     399,   854,   398,   692,   400,   796,   406,  2429,  1721,   801,
     409,  1029,   417,  1057,   659,  1825,  1826,   664,  2125,  2846,
    2082,   815,  2127,  2688,   666,   692,   667,  2130,   947,   948,
    2019,  2134,   668,  2136,  2137,  2138,  1212,  1213,   855,   673,
    1216,  1217,  1058,  2031,  2031,  2809,  2810,  2031,   678,  2083,
     676,  1059,  2689,   679,  2854,    42,  2855,  2459,  2084,   680,
     682,  2690,  3005,  1907,   856,  2066,  2066,  2853,   683,  2066,
    1907,  2856,   684,   685,   687,   914,  2596,  2596,   975,  2857,
    2596,   976,   977,  2858,  2305,   978,  2306,   979,   980,   981,
    1892,   982,   983,   985,   989,   990,  2101,   992,  2712,  1413,
     991,  3057,   857,   777,   996,  1893,  1015,  1016,  2859,   937,
    1389,   136,  1019,   858,  1021,  1022,  1027,  1907,  2719,  1094,
    1095,  1096,  1894,  1031,  1041,  1895,  2595,  2595,  2595,  2595,
    1040,  1146,   894,  2854,  1097,  2855,  1142,  2549,  1896,  2551,
    1043,   839,  1044,  1131,  1045,  1147,  1046,   875,  1047,   777,
    2856,  1048,   777,  2760,  1150,  1128,  1049,  1050,  2857,  1151,
    1051,  1389,  2858,  1062,  1063,   777,   777,   777,   777,   875,
    2066,  1153,  1064,  1067,  1068,  1071,  2168,  1822,  1898,  1154,
    2173,  2173,   895,  1073,  1074,  1075,  1076,  2859,  1077,   777,
    1899,  1098,  1099,  1100,  1101,  1102,  1103,  1078,  1079,  2185,
    1080,  1159,  1161,  1164,  1178,  2720,  1158,  1104,  1105,  1106,
    1173,  1209,   859,   860,   861,  1219,  1222,  1247,    84,   828,
     896,  2721,  1248,  1239,  1249,   862,  1250,  1254,  1259,  1256,
    1260,  1268,  1900,  1270,  1290,  1291,  1292,  1224,    83,  2461,
      42,  1293,  2466,  1298,   698,   777,  1302,  2903,  1305,  1308,
    1306,  1307,  1907,  1907,  1354,  2911,  1362,   716,  1365,     2,
       3,  1907,  1383,  1403,  2722,  1419,  1420,  1421,  1422,  2916,
    1018,  1901,  2234,  2630,  2631,  2632,  1423,  2634,  2635,  2636,
    2637,  2638,  2639,  1902,   701,   790,  2642,  1431,  1445,  1448,
    1446,  1453,  2256,   692,   692,  1903,  1904,  1482,  1485,  1489,
     869,   807,   808,  1905,  2723,  1490,  1906,   814,  1522,  1491,
     816,  1504,  2596,  1510,   274,  1230,  1524,   897,  2596,  2596,
    1526,  2596,  2596,  2596,  2596,  1528,   937,  1537,   863,  1538,
    2596,  1548,  1549,  2724,  2703,     5,     6,  1551,     7,     8,
    1029,  1553,  2725,     9,   651,  1580,  1558,  1564,  1107,  1562,
     651,  1108,  1573,  1582,  1587,  2066,  1588,  1590,  1907,  1300,
      10,    11,  1628,  1629,  2738,  2294,  1647,  1907,  2712,  1631,
     777,  1626,   777,  1637,  1686,  1697,  1699,  2751,    12,  1700,
    2066,  1703,  1029,  2971,  2753,   737,  1704,  1732,  1733,  1735,
    1736,  2031,  1747,   898,  2516,  1730,  1737,   738,  1748,  1752,
    1754,  1761,  1763,    84,  1796,  1766,  2595,  2595,  1768,  1771,
    2595,  1792,  1799,  1800,  2066,  1798,  1801,  1907,  1804,  1907,
    1802,  1805,  1806,  1808,  1299,  3034,  1807,   653,  1811,  1810,
    1836,  2066,  1823,   653,   899,  2239,  2240,   839,   839,  1838,
    1389,  1843,  1845,  2237,  2238,  2239,  2240,  1839,  1851,    13,
   -1807,  2596,  1852,  1858,  2596,  2596,  2596,  2596,  1865,  1861,
    1879,  1862,  1871,  1398,  1885,  1389,  1918,  1919,  1920,   950,
    1109,  1924,  1926,  1741,  1971,  1972,   777,  2016,  1983,  1999,
    2441,  1989,  2000,  2014,  2017,  1110,  2028,  2039,  1608,  1111,
    1609,  1610,  1611,  2040,  2048,  2041,  2869,  2045,  2103,  2869,
    2087,   900,  2088,    91,  1318,  2089,  2090,  2241,  2242,  2243,
    2244,  2245,  2246,  2091,  2092,   777,   777,  2241,  2242,  2243,
    2244,  2245,  2246,  2107,  2118,   777,  2119,  1112,   777,  2126,
    2120,  2139,  2129,  2468,  2140,  2141,  2144,  2145,  2147,  2149,
     754,  2151,  2162,  2167,  2182,  2712,  1822,  2712,  2483,  2184,
    2485,  2193,   777,  2194,  2199,  1113,  2187,  2200,   777,  2596,
    2197,   777,  3122,  2202,  2752,   901,  2501,  2596, -1807,   937,
     777,   777,  2198,  1114,  2218,  3039,   185,   193,  3098,  3099,
    3100,  3101,  3102,  3103,  2201,  2219,   777,  2227,  2228,  2229,
    2230,  2231,  2232,   701,  2768,  1907,  2233,  2236,   949,  2254,
    2261,  1907,  1907,  1907,  1907,  1907,  1907,  1319,     1,   756,
    2902,  2263,  2272,  2273,  2274,  1320,  2277,  2281,   758,  2282,
    2289,  1321,  2292,  1322,     2,     3,  2315,   828,  2377,   828,
    2313,   193,  2316,  2321,  1323,   720,  2384,   193,  2314,  2403,
       1,  2905,  2595,  2825,  2826,  1907,  2404,  2430,  2595,  2595,
      16,  2595,  2595,  2595,  2595,  1115,     2,     3,  2066,  2405,
    2595,  2746,  1324,  2411,  2594,  2594,  2594,  2594,  2066,  2066,
    2414,  2845,  2417,  2420, -1752,  2436,  2443,  2442,  1325,  2619,
    2620,  2019,  2444,  1326,  2445,  2446,  2447,  2623,  2448,  2449,
     937,  2450,  2454,  2990,  2457,  1327,  2460,  2462,  2463,  2469,
       5,     6,  1328,     7,     8,  2473,  2477,   193,     9,   193,
    2481,  2484,  2493,  2496,     1,  2241,  2242,  2243,  2244,  2245,
    2246,  1116,  2504,  2514,  1612,    10,    11,  1613,  2520,  1614,
       2,     3,     5,     6,  2522,     7,     8,  2536,  2548,   104,
       9,  2559,  2712,    12,   105,  2560,  2569,  2382,  1907,  1615,
    1907,  2576,  2437,  2614,  2618, -1807,  2633,    10,    11,  1616,
    1907,  2640,  1907,  2641,  2647,  1907,  2628,  2629,  2648,  2651,
    2066,  2682,  2066,  2652,  2225,    12,  2653,  2654,  1940,  2655,
    2656,  2595,  2657,   193,  2595,  2595,  2595,  2595,  2668,   106,
     107,  2671,  2678,  1373,  1360,  2692,  2694,   108,  2705,  1389,
    2699,  1617,  1992,  1907,  1029,  1618,     5,     6,  3019,     7,
       8,  2701,  2734,  2739,     9,  3163,  2728,   777,  2740,  2906,
    2869,  2741,  2742, -1807,  2756,  2758, -1807,  2761, -1807, -1807,
   -1807,    10,    11,  2765,  2776,  2361,  2775,  2788,   193,  2173,
     944,  2791,  2748,  2173,  2802,   692,  2795,   828,  2812,    12,
     777,  2362,  2363,  2813,   828,  2821,  1329,  2814,  2815,  2816,
    2364,  2817,  2818,  1330,  2831,  2832,  2938,  2843,  2842,   777,
    2850,  2878,  2401,  2879,  2865,   714,  2823,  2824,  2825,  2826,
     777,  2883,  2881,  1619,  2882,  1331,  2884,  1907,  2887,  2595,
    1332,  2890,  2895,  2897,  2365,  1907,  2898,  2595,  1907,  1907,
    1907,  1907,  2784,  2366,  2901,  2904,  2908,  2910,  2914,  2915,
     792,  2917,  2918,  2919,  2921,  2923,   797,  2927,   799,  2525,
   -1807,  2930,   806,  2968,  2932,   806,  2792,  2934,   806,  2935,
    2936,  2937,  2367,  2066,    14,  2438,  2960,  2949,   818, -1807,
    2951,  2987,  2294,  2988,  2594,  2594,  2996,  2997,  2594,  2998,
    2241,  2242,  2243,  2244,  2245,  2246,  2999,   867,  3006,  2819,
    3017,  3020,  3038,  3033,   878,   881,   884,  3045,  3049,  3080,
     905,  3046,  3032,  3059,  3048,  3084,  3069,  2368,   915,  3086,
    3091,  1908,  2066,    15,  1638,  1096,  3104,  3117,  3125,   875,
    2603,  2603,  2603,  2603,   939,  3127,  3128,  3142,  1097,    51,
      52,    53,    54,    55,    56,    57,  3129,  3130,  3143,  3156,
    3158,  2500,  2455,  2432,  2210,  1870,    74,    75,  1572,  2369,
     562,  2480,  2178,  2169,   351,   199,  1608,   204,  1609,  1610,
    1611,   283,   347,   677,   701,   352,  1688,   701,   410,  1907,
    1689,   285,  1907,  2128,    17,   663,  2731,   378,   669,   376,
    3140,   109,   670,  1793,  2146,  1098,  1099,  1100,  1101,  1102,
    1103,  1757, -1807,  1358,   903, -1807,  2037, -1807,  2029,  1601,
    2158,  1104,  1105,  1106,  1029,  2547,  1831,   110,  2888,  2790,
    2893,  2253,  1923,  1605,  3157,  1941,  2913, -1807,  1908,  2165,
      69,  1519,   159,    70,  2863,  1908,  1877, -1807,    71,   813,
     828,  1880,  3044,   341,   974,   777,  1625,  1296,  2250,  1037,
    1038,  1039,  3107,  1884,  2851,  2978, -1807,  1506,  1542,   995,
    1986,  3146,  2538,  1496,  2661,  1052,  2986,  1242,  1454,  2660,
    1554,  1065,  1066,  2373,  2643,  1418,  1070,  2152,  2283, -1807,
    1731,  1698,  1908, -1807,  1907,  3149,  3136,  2312,   111,  2076,
    3070,  2679,   777,  2374,  2886,  2713,  2664,  2665,  2376,   939,
    2872,  3078,  1641,  2877,  2400,    64,  2621,  1907,  1346,  3015,
    2066,  3016,  2808,  2575,  1667,  1668,  2707,  3135,   701,  3051,
    2594,  1684,  2537,  1313,  1633,  2807,  2594,  2594,  1599,  2594,
    2594,  2594,  2594,  2952,  2969,  2066,  2102,  2066,  2594,  2961,
    1907,  1513,   418,     0,   271,  1889,  1890,    42,  2977,     0,
       0,     0,  1107,     0,     0,  1108,     0,     0,     0,     0,
       0, -1807,     0,  3154,     0,     0,     0,     0,     0,  1136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,  2580,     0,     0,     0,     0,     0,
       0,  1029,     0,  1029,     0,     0,  1907,     0,     0,     0,
       0,  2066,  1612,  2893,     0,  1613,     0,  1614,     0,     0,
    2603,  2603,  1167,     0,  2603,     0,     0,  1908,  1908,     0,
       0,     0,     0,     0,     0,     0,  1908,  1615,  1184,  1184,
    1184,     0,  1184,     0,  1184,  1184,     0,  1616,     0,     0,
      91,    91,     0,     0,     0,     0,     0,  2792,     0,     0,
       0,     0,     0,     0,     0,  1907,     0,     0,     0,  2594,
       0,   113,  2594,  2594,  2594,  2594,  3067,     0,     0,   114,
       0,     0,     0,     0,  1109,     0,     0,     0,     0,  1617,
    1638,   884,     0,  1618,     0,     0,     0,     0,     0,  1110,
       0,     0,  1266,  1111,     0,     0,     0,     0,   701,     0,
    2870,     0,  1907,  2870,     0,     0,     0,     0,     0,     0,
     700,     0,  1907,     0,     0,     0,   939,  1136,  1850,     0,
       0,     0,     0,  1908,     0,  1303,     0,     0,     0,     0,
       0,  1112,  1908,     0,     0,     0,     0,     0,   777,  3109,
       0,  1311,  1311,   777,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1113,
       0,  1619,  1921,     0,     0,     0,  1426,  2594,     0,     0,
       0,     0,     0,  1433,     0,  2594,  1444,  1114,     0,     0,
       0,     0,  1908,     0,  1908,     0,     0,     0,  1029,  1449,
    1907,     0,  2066,  1452,     0,     0,     0,     0,     0,     0,
       0,  1458,     0,  1460,  1461,  1462,  1463,  1464,  1465,  1466,
    1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,  1476,
    1477,  1478,  1479,     0,     0,  1908,     0,     0,     0,  1907,
       0,     0,     0,  1480,  1481,     0,     0,     0,  1483,     0,
    1484,     0,     0,     0,  2525,     0,  2603,     0,     0,   777,
       0,     0,  2603,  2603,     0,  2603,  2603,  2603,  2603,  1115,
       0,     0,     0,     0,  2603,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1886,  1887,  1888,
       0,     0,     0,   271,  1889,  1890,    42,     0,     0,  1769,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
       0,     0,  1488,     0,     0,  1892,     0,     0,     0,  1097,
       0,     0,     0,  1891,    91,  1116,    91,   884,   806,     0,
    1893,     0,     0,     0,     0,  1505,   818,     0,     0,   884,
       0,     0,     0,   193,     0,     0,  1520,  2581,     0,     0,
    2582,     0,     0,     0,     0,     0,     0,     0,     0,   939,
    1908,     0,     0,  2583,     0,     0,  1908,  1908,  1908,  1908,
    1908,  1908,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,  2603,     0,     0,  2603,  2603,
    2603,  2603,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,    91,  2585,     0,     0,     0,     0,     0,     0,
    1908,     0,     0,     0,     0,  2586,     0,     0,     0,     0,
       0,     0,     0,     0,  2870,  2206,  2207,     0,     0,  1908,
    1908,  1908,  1908,     0,     0,     0,  2216,  1565,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   700,
       0,     0,     0,     0,     0,     0,     0,  2587,     0,     0,
       0,  1592,     0,   720,   720,   720,  1595,   720,   720,   720,
     720,   720,   720,     0,     0,     0,   720,     0,     0,  1624,
     939,     0,     0,     0,     0,     0,     0,     0,     0,  2257,
    2258,  2259,  2260,  2603,     0,     0,  2588,  2265,  2266,  2267,
    2268,  2603,     0,     0,  2270,     0,     0,     0,  2589,     0,
       0,     0,     0,  1908,     0,  1908,     0,     0,     0,     0,
    2590,  2591,     0,     0,     0,  1908,     0,  1908,  2592,     0,
    1908,  2593,     0,  1107,   161,  1671,  1108,     0,     0,   274,
       0,     0,     0,     0,     0,  1097,  2192,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,  1908,     0,
       0,     0,     0,   162,     0,     0,  1097,     0,     0,     0,
    1772,  1773,  1774,     0,  1776,     0,     0,     0,  2319,  2320,
     884,     0,   163,     0,     0,  2324,  2325,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,  1791,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     937,   164,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,  1104,
    1105,  1106,  1908,   166,  1892,  1109,     0,     0,     0,     0,
    1908,     0,     0,  1908,  1908,  1908,  1908,     0,     0,  1893,
    1110,   167,     0,     0,  1111,     0,  1846,     0,     0,     0,
       0,   168,     0,     0,     0,     0,  1894,     0,     0,  1895,
       0,  1791,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,  1896,     0,     0,     0,     0,     0,     0,  1908,
    1908,     0,  1112,  1908,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1842,     0,     0,  2225,
       0,     0,  2471,  2472,  1849,     0,     0,   170,     0,     0,
    1113,  2479,  1898,     0,     0,   884,     0,     0,     0,     0,
       0,     0,     0,     0,  1899,     0,     0,     0,  1114,  1107,
     171,     0,  1108,     0,     0,     0,   185,     0,     0,     0,
    2507,  2508,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,   173,     0,     0,   174,     0,     0,     0,     0,
    1107,     0,     0,  1108,     0,     0,  1900,     0,     0,  1908,
       0,     0,  1908,     0,  1908,     0,   175,  1908,     0,   176,
       0,   177,   884,  1975,   884,     0,     0,     0,   878,     0,
       0,     0,     0,     0,  2550,     0,  2552,  2051,     0,     0,
     178,     0,     0,     0,     0,  1901,  1886,  1887,  1888,     0,
    1115,     0,   271,  1889,  1890,    42,     0,  1902,   179,     0,
    2023,     0,     0,     0,     0,     0,     0,     0,     0,  1903,
    1904,     0,     0,     0,     0,     0,     0,  1905,     0,     0,
    1906,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,  1109,  1891,     0,  2624,  2625,     0,     0,  2626,  2627,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,     0,     0,     0,     0,     0,  1116,     0,  2142,  1908,
       0,  2142,  1109,     0,     0,     0,   884,   193,     0,     0,
       0,     0,  2650,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1908,     0,     0,     0,     0,     0,  1112,     0,
       0,     0,     0,     0,     0,  1908,     0,     0,     0,     0,
       0,  1908,  1908,     0,  1908,  1908,  1908,  1908,     0,     0,
       0,     0,     0,  1908,     0,  1908,  1113, -1808,     0,  1112,
       0,   205,     0,     0,     0,     0,     0,   884, -1808,   884,
   -1808, -1808, -1808,     0,  1114,     0,     0,     0,   884,     0,
       0,     0,     0,     0,     0,     0,  1908,  1113,     0,     0,
       0,     0,     0,     0,     0,     0, -1808,     0,   700,     0,
       0,     0,     0,     0,     0,  1114,     0,     0,   206,   207,
       0,  1908,     0,     0,     0,  2191,     0,     0,   208,     0,
       0,     0,     0,     0,     0, -1808,  2745,     0,     0,     0,
    2750,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2578,  2579,   937,  2755,  2215,     0,   271,  1889,  1890,    42,
       0,     0,     0,     0,     0,     0,  1115,     0,     0,     0,
       0,     0,  2766,     0,     0,     0,     0, -1808,     0,     0,
    1908,     0,     0,     0,  1908,     0,     0,  1908,  1908,  1908,
    1908,     0,     0,     0,     0,     0,  2580,  1115,     0,   387,
    2249,  1595,     0,     0,     0,     0,     0, -1808,     0,     0,
   -1808,     0,  2052,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1908,     0,     0,     0,  1908,     0,     0,
       0,     0,  1116,     0,     0, -1808,     0,  1908,     0,     0,
       0,     1,     0, -1808,     0, -1808,     0,     0,     0,     0,
       0,     0,     0,     0, -1808,     0,     0,     2,     3,     0,
   -1808,     0,     0,  1116,     0,     0,     0,     0, -1808,     0,
       0,     0, -1808,     0,     0,     0,     0,     0, -1808,     0,
       0,     0, -1808, -1808, -1808, -1808,     4,     0,     0,     0,
       0,     0,  1908,     0,     0,     0,     0, -1808,     0,   209,
    1908,     0,     0,     0,     0,  2317,     0,     0,     0,     0,
       0,     0,     0,  1892, -1808,  1908,     0, -1808,     0, -1808,
       0,     0,   700,     0,     0,     0, -1808,     0,  1893,     0,
       0,     0,     0,     5,     6,     0,     7,     8,   210, -1808,
       0,     9,     0,     0,     0,  1894,     0,     0,  2053, -1808,
       0,     0,     0,     0,  1908,     0,     0,   211,    10,    11,
    2054,  1896,     0,     0,     0,     0,     0,     0, -1808, -1808,
       0,     0,     0,   212,  1791,  1791,    12,     0,     0,     0,
       0,     0,     0, -1808,   884,     0,     0,     0,  2225,     0,
       0, -1808,   937,     0,     0, -1808,   213,     0,     0,     0,
       0,  1898,     0,     0, -1808, -1808, -1808,     0,   214,     0,
       0,     0,     0,  1899,     0,     0,     0,  2495,   215,     0,
    1791,     0,     0,     0,     0,     0,     0,     0,     0,  1791,
    1791,  2926,     0,     0,   884,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   217,    13,     0,  2939,
       0,     0,     0,     0,   161,  1900,     0,     0,     0,     0,
       0,     0,   218,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1808,     0,     0,     0,     0,  2498,     0,
     714,     0,  2502,     0, -1808,     0,     0,     0,     0,     0,
       0,     0,     0,   162,  1901,  2513,     0,     0,     0,     0,
     193,     0,   219,     0,     0,     0,  1902,     0,     0,     0,
       0,     0,   163,     0,     0,     0,     0,     0,  1903,  1904,
       0,     0,     0,     0, -1808,   220,  1905,  1892,     0,  1906,
       0,     0,     0,     0,     0,     0,     0,   274,     0,     0,
     221,     0,  1893,     0,     0,     0,     0,   222,     0,     0,
     223,   164,     0,     0,  2555,  2557,     0,     0,     0,  2581,
       0,     0,  2582,   165,     0,     0,     0,    14,     0,     0,
       0,   224,     0,   166,   225,  2583,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -1808,  3042,     0,     0,
       0,   167,     0,     0,     0,   227,     0,  2622,     0,     0,
       0,   168,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   228,  2584,  2585,    15,   169,     0,     0,
       0,     0, -1808,     0,     0,     0,     0,  2586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2644,     0,     0,
       0,  3071,  3072,     0,  3074,     0,  3076,  3077,    16,     0,
    2659,     0,     0,     0,     0,   229,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1808,  2587,
       0,     0,     0,     0,     0,     0,  2732,    17,     0,     0,
     171,     0, -1808, -1808, -1808, -1808, -1808, -1808, -1808,     0,
   -1808, -1808,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,   173,     0,     0,   174,     0, -1808,  2588,     0,
       0,   884,     0,     0,     0,     0,     0,     0,     0,     0,
    2589,     0,     0,     0,     0,     0,   175,     0,  1791,   176,
       0,   177,  2590,  2591,     0,  3132,     0,  3133,     0,     0,
    2592,   884,     0,  2593,     0,     0,     0,     0,     1,     0,
     178,   274,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,   420,     2,     3,     0,     0,   179,     0,
       0,  1595,   421,     0,     0,     0,     0,     0,     0,     0,
     939,     0,     0,  3148,   422,   423,     0,   424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3151,
    3152,   425,     0,  3153,     0,     0,  3155,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   427,
     428,   429,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   430,     0,   431,   432,   433,
       5,     6,   434,     7,     8,   435,     0,   436,     9,   437,
     438,     0,     0,     0,     0,     0,   439,     0,     0,   440,
       0,   441,   442,   443,     0,    10,    11,     0,     0,     0,
       0,   444,     0,   445,   446,     0,   447,     0,   448,   449,
       0,     0,   450,    12,     0,     0,   451,   452,   453,     0,
     454,   455,     0,     0,     0,   456,   457,   458,     0,   459,
       0,     0,     0,   460,     0,   461,   462,     0,     0,     0,
       0,   463,     0,     0,     0,   464,     0,     0,   465,     0,
     466,     0,   467,     0,   468,     0,   469,   470,  2644,   471,
     472,   473,     0,     0,     0,   474,     0,   475,   476,     0,
     477,     0,     0,     0,     0,     0,     0,     0,   478,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,   481,   482,     0,     0,   483,   484,
       0,     0,   485,   486,     0,     0,     0,     0,     0,     0,
       0,   487,   488,   489,     0,   490,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   492,   493,     0,   494,
       0,     0,     0,   495,   496,     0,     0,     0,   497,     0,
       0,     0,     0,     0,     0,     0,   498,     0,   884,     0,
       0,     0,     0,     0,   499,   500,   501,     0,     0,     0,
       0,     0,   502,   503,     0,     0,     0,     0,   504,     0,
       0,   505,     0,     0,     0,   506,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,  1595,     0,     0,     0,
       0,     0,   510,     0,     0,  1081,  1082,  1083,   511,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,  1097,     0,     0,  1595,   512,     0,
     513,   514,     0,     0,     0,     0,     0,     0,     0,   515,
       0,  2644,     0,     0,     0,     0,  2981,     0,  2983,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   516,     0,
       0,  1098,  1099,  1100,  1101,  1102,  1103,   884,     0,   517,
       0,     0,     0,     0,     0,   884,   518,  1104,  1105,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   939,     0,     0,     0,     0,     0,   193,     0,
     519,   520,     0,     0,     0,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   522,     0,     0,
       0,     0,     0,   523,   524,   525,   526,     0,     0,     0,
     527,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,   529,   530,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1791,   531,     0,   532,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   533,     0,   534,     0,
       0,   535,     0,     0,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1184,  1184,  1184,  1184,  1184,  1184,     0,     0,
       0,     0,     0,   537,     0,     0,   538,     0,     0,     0,
       0,   539,     0,     0,   540,   541,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,     0,     0,     0,     0,   542,
       0,     0,     0,     0,     0,     0,   543,     0,     0,     0,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,   544,
     545,   546,   547,   548,   549,   550,     0,     0,   551,  1097,
     552,     0,   553,     0,     0,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,   939,     0,     0,     0,     0,     0,     0,     0,
    1109,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,  1111,
    1450,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1112,     0,     0,
       0,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,     0,  1113,     0,     0,     0,     0,
    1097,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,  1108,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,  1115,     0,     0,     0,     0,
       0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1081,  1082,  1083,     0,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
       0,     0,     0,     0,  2330,  2331,     0,  2332,  2333,  2334,
       0,  1116,  1097,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,  1111,  1753,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,  1107,     0,     0,  1108,     0,  1098,
    1099,  1100,  1101,  1102,  1103,  1110,     0,     0,     0,  1111,
    1762,     0,  1112,     0,     0,  1104,  1105,  1106,     0,  1081,
    1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,     0,  2335,     0,  1107,
    1113,     0,  1108,     0,     0,  2336,     0,  1112,  1097,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1113,     0,     0,     0,  2337,
       0,     0,     0,     0,     0,     0,     0,     0,  2338,     0,
       0,     0,     0,  1114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,
    1103,     0,     0,     0,     0,     0,  1109,  2339,  2340,     0,
       0,  1104,  1105,  1106,     0,     0,     0,     0,     0,     0,
       0,  1110,     0,     0,     0,  1111,  1767,     0,     0,     0,
    1115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,     0,  1108,
       0,  1109,  2341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,  1115,  1110,     0,     0,     0,
    1111,  1775,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,  1113,     0,     0,  2342,     0,  1116,     0,     0,     0,
       0,  1097,     0,     0,     0,     0,     0,     0,  1112,  1114,
       0,  1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,  1116,     0,     0,     0,     0,  1113,     0,     0,     0,
    1097,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2343,     0,  1107,     0,  1114,  1108,     0,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,  1109,     0,
       0,     0,     0,     0,  1104,  1105,  1106,     0,     0,     0,
       0,     0,     0,  1110,     0,     0,     0,  1111,  1777,     0,
       0,  1115,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1113,     0,     0,     0,  1116,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,  1114,     0,     0,  1109,     0,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1110,
       0,     0,     0,  1111,  1778,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
    1105,  1106,     0,  1115,  1107,     0,     0,  1108,     0,  1113,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1114,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,     0,  1097,
       0,     0,     0,     0,  1081,  1082,  1083,     0,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,     0,     0,  1116,
       0,     0,     0,  1097,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,  1110,     0,     0,     0,  1111,  1779,     0,  1115,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1109,     0,     0,     0,
    1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,
    1107,  1110,     0,  1108,  1112,  1111,  1104,  1105,  1106,     0,
       0,     0,     0,     0,     0,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1113,     0,     0,  1116,     0,     0,     0,     0,
       0,     0,     0,  1112,  1097,     0,     0,     0,     0,     0,
    1114,     0,     0,     0,     0,     0,  1781,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1113,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,     0,     0,  1107,     0,     0,  1108,  1104,  1105,  1106,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1115,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,  1107,     0,     0,
    1108,     0,     0,     0,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,  1115,     0,  1104,  1105,  1106,     0,     0,  1083,  1112,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,     0,     0,  1116,     0,
       0,     0,     0,     0,     0,  1097,     0,  1113,     0,     0,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1109,  1097,  1116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,  1111,     0,     0,     0,  1107,     0,
       0,  1108,  1098,  1099,  1100,  1101,  1102,  1103,     0,  1109,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,  1110,     0,     0,     0,  1111,     0,
       0,     0,  1112,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,  1782,     0,  1115,     0,  1104,
    1105,  1106,     0,     0,  1107,     0,     0,  1108,     0,     0,
    1113,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1114,  1785,
       0,     0,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1113,     0,     0,     0,     0,  1944,
    1945,  1946,  1947,  1948,  1949,     0,  1097,     0,     0,     0,
       0,     0,  1114,  1116,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,  1111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1950,  1107,
    1115,     0,  1108,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,  1109,  1112,     0,  1104,
    1105,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,  1110,   724,  1108,  1115,  1111,     0,     0,     0,     0,
       0,   725,   726,     0,     0,  1113,     0,   271,   727,   728,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1114,     0,     0,  1116,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,     0,   729,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,     0,   731,     0,     0,     0,     0,     0,
    1116,  1113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1114,
       0,  1109,   732,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1110,     0,     0,     0,
    1111,   724,     0,     0,     0,  1115,     0,     0,     0,     0,
     725,   726,  1109,     0,     0,     0,   271,   727,   728,    42,
    1107,     0,     0,  1108,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,     0,  1112,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,   729,     0,     0,     0,     0,   730,     0,     0,     0,
    1097,  1115,     0,   731,     0,     0,  1113,     0,     0,  1112,
       0,  1116,     0,    84,     0,   733,     0,     0,     0,     0,
       0,     0,     0,     0,  1114,     0,     0,     0,     0,     0,
       0,   732,  1951,     0,     0,     0,     0,  1113,     0,     0,
       0,     0,     0,     0,     0,  1952,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,  1116,   724,     0,
       0,     0,     0,  1104,  1105,  1106,     0,   725,   726,     0,
       0,     0,  1109,   271,   727,   728,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,     0,     0,  1115,     0,     0,  1953,
       0,     0,   734,     0,     0,     0,  1954,   735,   729,     0,
       0,     0,    84,   730,   733,     0,     0,     0,     0,     0,
     731,     0,     0,     0,     0,     0,     0,  1115,     0,  1112,
       0,     0,     0,     0,     0,   736,     0,     0,     0,     0,
       0,     0,  1780,     0,     0,  1955,     0,     0,   732,     0,
       0,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,  1956,
     737,     0,     0,     0,     0,  1114,     0,     0,     0,  1957,
    1958,  2051,   738,     0,     0,  1959,     0,     0,     0,     0,
    1886,  1887,  1888,  1116,     0,  1960,   271,  1889,  1890,    42,
     739,     0,     0,     0,  1107,   740,     0,  1108,   741,     0,
       0,   734,     0,     0,   724,     0,   735,  1961,     0,   742,
    1962,  1963,     0,   725,   726,   743,  1964,     0,     0,   271,
     727,   728,    42,     0,     0,   744,  1891,     0,     0,    84,
     745,   733,     0,   746,   736,     0,   747,     0,     0,     0,
       0,     0,     0,     0,     0,   748,   749,  1115,     0,     0,
       0,     0,     0,     0,   729,     0,     0,     0,     0,   730,
       0,     0,     0,     0,     0,     0,   731,     0,     0,   737,
       0,     0,     0,  1965,     0,     0,     0,     0,     0,     0,
       0,   738,     0,     0,  1966,  1132,   750,     0,     0,     0,
     751,     0,     0,     0,   732,     0,     0,     0,   752,   739,
       0,     0,     0,     0,   740,     0,     0,   741,     0,   753,
       0,     0,     0,  1116,     0,   754,  1109,     0,   742,     0,
       0,     0,     0,     0,   743,     0,     0,     0,   734,     0,
       0,  1110,     0,   735,   744,  1111,     0,     0,     0,   745,
     755,     0,   746,     0,     0,   747,     0,     0,     0,     0,
       0,     0,   700,     0,   748,   749,     0,     0,     0,     0,
       0,   736,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   756,    84,     0,   733,     0,     0,
       0,   757,     0,   758,     0,   750,   737,     0,     0,   751,
       0,  1113,     0,   759,   760,     0,     0,   752,   738,     0,
       0,   761,     0,     0,     0,     0,     0,     0,   753,  1114,
    2159,     0,   274,     0,   754,     0,   739,     0,     0,     0,
       0,   740,     0,     0,   741,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   742,     0,     0,     0,   755,
       0,   743,     0,     0,     0,     0,  2052,     0,     0,     0,
       0,   744,     0,     0,     0,     0,   745,     0,     0,   746,
       0,     0,   747,     0,     0,     0,     0,     0,     0,     0,
       0,   748,   749,     0,   734,     0,     0,     0,     0,   735,
       0,     0,     0,   756,     0,     0,     0,     0,     0,     0,
     757,  1115,   758,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   759,   760,     0,     0,     0,   736,     0,     0,
     761,  2517,   750,     0,     0,     0,   751,     0,     0,     0,
       0,   274,     0,     0,   752,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   753,     0,     0,     0,     0,
       0,   754,   737,     0,     0,     0,     0,  1892,     0,     0,
       0,     0,     0,     0,   738,     0,     0,  1116,     0,     0,
       0,     0,  1893,     0,     0,     0,   755,     0,     0,     0,
       0,     0,   739,     0,     0,     0,     0,   740,     0,  1894,
     741,     0,  2053,     0,     0,     0,     0,     0,     0,     0,
       0,   742,     0,     0,  2054,  1896,     0,   743,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   744,     0,     0,
     756,     0,   745,     0,     0,   746,     0,   757,   747,   758,
       0,     0,     0,     0,     0,     0,     0,   748,   749,   759,
     760,     0,     0,     0,     0,  1898,     0,   761,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1899,   274,     0,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,     0,   750,     0,
       0,     0,   751,  1097,     0,     0,     0,     0,     0,     0,
     752,     0,     0,     0,     0,     0,     0,     0,     0,  1900,
       0,   753,     0,     0,     0,     0,     0,   754,     0,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1886,
    1887,  1888,     0,     0,     0,   271,  1889,  1890,    42,     0,
       0,  1097,   755,     0,     0,     0,     0,     0,  1901,     0,
    1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,     0,
    1902,     0,     0,     0,     0,     0,  1104,  1105,  1106,     0,
       0,     0,  1903,  1904,     0,  1891,     0,     0,     0,     0,
    1905,     0,     0,  1906,     0,     0,   756,     0,     0,     0,
       0,   274,     0,   757,     0,   758,     0,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,   759,   760,     0,     0,     0,
       0,     0,     0,   761,  1104,  1105,  1106,     0,     0,  1886,
    1887,  1888,     0,     0,   274,   271,  1889,  1890,    42,     0,
       0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,     0,     0,     0,  1097,     0,     0,     0,     0,     0,
       0,  1097,     0,     0,     0,  1891,     0,     0,     0,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   700,     0,     0,     0,     0,     0,  1107,     0,     0,
    1108,  1098,  1099,  1100,  1101,  1102,  1103,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,  1104,  1105,  1106,     0,     0,     0,
       0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,  1108,  1104,
    1105,  1106,     0,     0,     0,     0,     0,  1886,  1887,  1888,
       0,     0,     0,   271,  1889,  1890,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2578,  2579,
       0,   700,     0,     0,   271,  1889,  1890,    42,     0,     0,
       0,     0,     0,     0,     0,  2052,     0,     0,     0,     0,
       0,     0,     0,  1891,  2578,  2579,     0,     0,     0,     0,
     271,  1889,  1890,    42,     0,     0,     0,     0,     0,  1109,
       0,     0,     0,     0,  2580,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1110,     0,     0,     0,  1111,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2580,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,  1108,     0,     0,     0,  1107,     0,  1109,  1108,     0,
       0,     0,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,  1111,     0,     0,     0,
    1107,     0,     0,  1108,     0,     0,  1892,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,     0,     0,  1888,
       0,  1893,     0,   271,  1889,  1890,    42,     0,     0,     0,
       0,     0,  1114,     0,  1112,     0,     0,     0,  1894,   700,
       0,  2053,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2054,  1896,     0,     0,     0,     0,     0,
     700,     0,  1113,  1891,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1114,     0,     0,     0,     0,     0,   700,     0,     0,     0,
    1109,     0,     0,     0,  1898,     0,  1892,  1109,     0,     0,
       0,     0,     0,     0,     0,  1110,  1899,     0,     0,  1111,
       0,  1893,  1110,     0,  1115,     0,  1111,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,  1894,     0,
       0,  1895,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,  1896,     0,     0,  1112,  1900,     0,
       0,     0,     0,     0,  1112,     0,     0,     0,     0,     0,
       0,     0,  1115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1113,     0,     0,     0,  1112,
    1116,     0,  1113,  1897,  1898,     0,     0,  1901,     0,   700,
       0,     0,     0,  1114,     0,     0,  1899,     0,     0,  1902,
    1114,     0,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,  1903,  1904,     0,     0,     0,     0,     0,     0,  1905,
       0,     0,  1906,     0,     0,  1114,     0,     0,  1116,     0,
     274,  1944,  1945,  1946,  1947,  1948,  1949,     0,  1900,     0,
       0,     0,     0,     0,  1892,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1893,
       0,     0,     0,     0,     0,  1892,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1115,  1894,  1901,     0,  1895,
    1893,     0,  1115,     0,     0,     0,     0,     0,     0,  1902,
    1950,  1892,  1896,     0,     0,     0,     0,  2581,     0,     0,
    2582,  1903,  1904,     0,     0,     0,  1893,  1115,     0,  1905,
       0,     0,  1906,  2583,     0,     0,     0,     0,     0,     0,
     274,     0,     0,  2581,     0,     0,  2582,     0,     0,     0,
       0,  3054,  1898,     0,     0,     0,     0,     0,     0,  2583,
    2225,  1116,     0,     0,  1899,     0,     0,     0,  1116,     0,
       0,     0,     0,  2585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2586,     0,     0,     0,     0,
       0,     0,     0,  1116,     0,     0,     0,     0,     0,  2585,
       0,     0,     0,     0,     0,     0,  1900,     0,     0,     0,
       0,  2586,     0,     0,  1892,  3021,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2587,     0,  1893,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1901,  1894,     0,     0,  1895,
       0,     0,     0,  2587,     0,     0,     0,  1902,     0,     0,
       0,     0,  1896,     0,     0,     0,  2588,     0,     0,  1903,
    1904,  3022,     0,     0,     0,     0,     0,  1905,  2589,     0,
    1906,     0,     0,     0,     0,     0,     0,     0,   274,     0,
    2590,  2591,  2588,     0,     0,     0,  3023,     0,  2592,     0,
       0,  2593,  1898,     0,  2589,  3024,     0,     0,     0,   274,
       0,     0,     0,     0,  1899,     0,  2590,  2591,     0,     0,
       0,     0,     0,     0,  2592,     0,     0,  2593,     0,     0,
       0,     0,     0,     0,     0,   274,     0,     0,     0,     0,
       0,  3025,     0,     0,  1951,     0,     0,     0,     0,  3026,
       0,     0,     0,     0,     0,     0,  1900,  1952,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1901,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1902,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1903,
    1904,  1953,     0,     0,     0,     0,     0,  1905,  1954,     0,
    1906,     0,     0,     0,     0,     0,     0,     0,   274,     0,
       0,     0,     0,  3027,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1955,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1956,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1957,  1958,     0,     0,     0,     0,  1959,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1960,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1961,
       0,     0,  1962,  1963,     0,     0,     0,     0,  1964,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1965,     0,     0,     0,     0,
       0,     0,     0,     0,  3028,     0,  1966
};

static const short yycheck[] =
{
       4,   196,   718,   330,    68,   715,   190,   701,   502,    13,
      14,   991,   870,    17,   214,   426,  1521,  1566,  1005,     0,
     449,   841,   998,   876,    84,   852,  1704,  1295,  1296,   838,
     741,  1431,  1397,  1328,   365,   848,   849,   178,   851,  1400,
     853,   854,    46,    47,    25,   519,  2299,  2300,  2301,  1708,
      31,    63,  1886,  1887,   156,  2001,   120,  1755,  1386,   525,
     484,     5,    20,   421,    27,  1627,   424,   425,    27,    27,
      27,  1815,     5,   547,    78,   390,   550,    81,     5,  1873,
     438,   791,   266,   509,     5,    97,   227,    68,    24,    93,
      26,  2302,     5,  2413,     5,    24,   100,    26,   509,   457,
     104,     5,   460,   107,   108,    25,    20,    27,   466,   113,
     114,    25,   470,    27,   543,    27,   474,  1699,  1700,    19,
     478,  1703,   931,     5,   482,   483,    26,   485,     5,  1033,
     488,   143,   490,   491,   492,   147,   945,   239,   240,   120,
     498,     5,   513,   501,   964,     5,     5,   342,   152,  1943,
     508,   155,    19,   100,    27,   513,   160,    24,    25,    26,
     450,    27,   520,    62,    25,   456,    27,   235,   700,    62,
      81,    82,     5,   531,    25,    33,    27,   535,    25,    26,
      27,   539,    27,   473,    24,    25,    26,   545,    27,    27,
     548,   859,   860,    25,   198,    27,    87,    88,  1590,    25,
    2520,    27,   397,   274,    68,     5,    70,   421,    72,     5,
      27,    24,    25,    26,    27,     5,     5,   229,  2396,   935,
     511,   512,  1804,     5,     5,    81,     5,   517,     5,     5,
     521,    33,   236,  1892,    91,  2670,   526,   527,   242,     5,
     530,  2280,  1639,   457,   534,   207,   460,    27,  2582,   253,
     540,     5,   542,    25,     5,    27,   470,   149,   344,   134,
     474,     5,  1939,   389,   478,     5,    24,    25,    26,    27,
     282,   485,   284,    64,    27,   359,   490,   289,   492,    24,
      25,    26,    27,  1067,   498,     5,   149,   501,    24,    25,
      26,    27,    26,    27,   508,    24,    25,    26,    27,   513,
      27,   295,   366,   367,  2894,   430,   520,    48,    49,    50,
      51,    52,  1817,    25,  1992,    27,     5,   531,     5,   430,
      25,   535,    27,   546,    23,   539,   338,   458,   333,   190,
     538,   545,   190,  2279,   548,  2230,  2231,  2232,  2233,   190,
     538,   430,   359,   355,     9,    10,   457,    12,    13,    14,
      15,    16,    17,   274,   358,    25,  2038,   361,   190,  1751,
     174,     5,  2044,   391,     5,   369,    19,   135,   136,   458,
     274,     6,    31,   190,  1232,  2053,   458,   190,   339,   587,
     385,   385,     6,   387,     5,   366,   367,   189,   190,   587,
      65,   475,     9,    10,   617,    12,    13,    14,    15,    16,
      17,    56,    57,     5,     5,     5,     5,  1989,     6,   248,
       5,   415,   162,  1400,     5,   374,   420,     5,   422,   423,
     576,     5,   426,   427,     0,   429,  3016,     5,   432,    84,
      85,    86,  2014,    86,   900,   429,   504,   399,  2873,   443,
       5,    18,    19,     5,     5,   190,   450,    29,  1678,    26,
      27,  1681,     5,   140,   190,    27,   190,   271,   475,   463,
     616,   190,  1178,   190,     5,     5,  2048,   625,     5,   473,
       5,     5,   476,    18,    19,    20,    21,    22,   190,     5,
    2814,     5,   486,   841,  1016,   190,  2820,     5,   619,  2823,
    2824,  2825,  2826,     5,   784,  2673,     5,   568,   502,   503,
     625,   585,     5,  1895,   283,   509,   150,   177,     5,   595,
     349,   349,     5,   517,   518,   519,     5,    18,    19,    20,
      21,    22,   526,   527,     5,   529,   530,  2566,   532,     5,
     534,     5,   658,     5,  2211,   234,   540,   619,   542,    27,
     544,   440,   546,   547,    27,   549,   550,     5,   552,  1043,
    1044,   508,  1820,  1221,   885,   395,   887,  2490,   391,     5,
    2394,   589,  2396,   283,   430,     5,  1040,   384,   585,   349,
     410,  1045,  1046,     5,     5,  2521,  1976,  1271,     5,     5,
       5,     5,   395,     5,    20,   430,   876,   252,  1062,   462,
    1987,    27,   963,  1019,   344,   391,   387,   410,   888,   274,
     389,  2150,   561,   893,   962,   963,   964,   373,  1019,  2001,
    2930,  1321,  1322,   190,   391,   391,   162,   578,  2829,  2953,
    1330,   412,  2956,  2957,  2958,  2959,   426,   841,   539,   556,
    1534,   470,   470,   525,   304,   252,   426,   550,   513,   384,
     310,   311,   312,   542,   426,   426,  2195,   568,   595,   542,
     654,   391,    23,   150,   981,  2204,  2205,   470,   430,   395,
     330,  2053,   525,  1373,   568,  1985,   678,   982,   436,   344,
    1164,   553,   426,   550,   410,   426,   532,   589,  2998,   683,
    1146,   685,   426,   619,   617,  1159,   546,   546,   514,   589,
     619,   611,  1158,    28,    29,   553,   700,   611,  1482,   550,
    2494,  1485,   190,   666,   495,  2000,   371,   666,   666,   666,
    2292,   715,  1539,  2275,   389,   626,  1142,   661,  2512,    27,
     724,   725,   726,  1147,   585,   366,  3046,  3061,  3048,  2473,
    1224,  1142,  2097,  2477,   625,  1446,   740,   426,  2099,    28,
      27,   486,   746,   747,   576,  2443,  2074,   751,   962,   963,
     964,   553,   619,   617,   371,  1249,   391,  1744,  2797,  2798,
    1254,   625,   245,   428,   611,   470,   500,   391,   438,   341,
     391,   441,  1581,    27,   391,   258,  1250,   349,   350,   619,
     784,   638,   639,   640,   641,   642,   353,   791,   339,   391,
     391,   391,   391,   391,   544,  2025,   391,   588,   344,   454,
     391,   616,   374,   391,  2600,   377,   619,   391,  1795,   600,
     601,   428,   453,   391,   484,  1244,  3069,   608,  1292,  1293,
     554,  2716,  2404,   395,  2406,  2225,   391,   577,   469,   391,
     391,    10,   355,   837,   838,  1655,   242,  2229,   391,  2673,
      23,   601,   583,  2235,  2236,  2237,  2238,  2239,  2240,   519,
     391,   391,   619,   430,   391,  2801,   391,   391,  1148,  1149,
    1150,   619,  2795,   234,  2523,   391,    25,   391,    27,   539,
     540,   512,   876,   391,   619,   331,   324,   538,  1168,   391,
     550,   426,   391,   619,   888,   555,   541,  2279,   391,   893,
     619,   556,   994,   568,   898,   997,   384,  2885,   391,  2887,
     391,  2169,   391,  2836,    18,    19,    20,    21,    22,   339,
     391,   552,   916,   157,    25,   391,    27,   391,  2813,   391,
    2815,  2816,  2817,  2818,   594,   426,   587,   931,   500,   584,
     360,     5,  1222,   391,   425,  1645,   190,   245,     0,   556,
     581,   945,    25,  1409,    27,   391,   353,   430,    25,   590,
     258,   391,   324,  1243,  2503,  1015,   626,   622,   245,   391,
     391,  2281,  2282,    25,   391,   391,   391,   391,   282,   391,
    1260,   258,   335,   648,   649,   650,   430,  1268,  1162,   361,
    1270,   295,   554,   346,   659,  2567,    25,   369,    27,   561,
     470,   362,   475,   458,   248,   999,   624,  2791,   478,  1003,
    1004,  1005,   430,   457,   458,   622,     5,  2399,   491,    25,
     533,    27,  1016,  2809,  2810,  1019,    20,  1021,  1022,   647,
     458,  1025,   157,    27,   547,    14,   163,   578,   167,   166,
     458,   190,   480,   415,  2616,   398,  1040,  1041,   430,  1043,
    1044,  1045,  1046,   163,  1048,  2437,   166,  1051,   618,   572,
     413,   234,   296,   238,   191,   625,   112,   513,  1062,  1533,
    1064,    26,    27,    25,  1068,    27,   520,  1925,   524,   521,
     249,   191,  1076,  2049,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  3082,  2821,   856,   620,  1564,  2772,
     177,   443,   535,   863,  1108,  1109,  2832,   190,   480,  1113,
     295,  1115,  2099,  2416,  2773,   429,  2419,  2776,  1612,  1613,
    2096,   463,   430,  2796,   589,   430,  1130,    63,   372,  2521,
      26,    27,  1423,   270,   476,  2808,   273,  2529,  1142,   502,
    2532,  2533,  2534,  2535,  1148,  1149,  1150,    25,   578,    27,
     270,   190,  1626,   273,   619,  1159,  2834,  1161,   295,  1163,
    1164,   296,   347,   430,  1168,  1631,   351,   475,  1526,  2569,
      25,  1991,    27,   531,   190,   295,   624,   535,  1319,   362,
    2052,   539,  2054,   491,  1325,    19,   430,   282,   475,   430,
      24,  1482,    26,  2013,  1485,   643,   644,   457,   458,  1489,
     295,   458,    46,    47,   491,   295,   238,   386,    25,   388,
      27,   480,   430,  1907,  1504,   663,    26,    27,  1222,   198,
    1224,  1552,  2804,   202,   366,   190,   163,   304,   190,   166,
      25,   475,    27,   310,   311,   312,   395,   372,  1528,  1243,
      26,    27,  1532,  1247,   429,  1249,  1250,   491,   425,    25,
    1254,    27,   624,   330,  1258,  1259,  1260,   347,    25,  1361,
      27,   351,    26,   295,  1974,    25,  1270,    27,  1370,  1735,
     430,   643,   644,   624,  2947,   430,  1634,   391,   122,   123,
    1284,   125,   126,  1573,  2676,   624,   130,  1291,  1292,  1293,
     458,   663,   429,    20,   190,   646,   647,  1655,    20,   438,
      27,  2110,   430,   147,   148,    27,  2016,   646,   647,   429,
     449,   453,  1526,  2895,  1318,   347,    20,  1321,  1322,   351,
     430,   165,  1326,    27,  1328,   430,  1330,   469,  3006,    26,
    1796,   470,  1798,   270,   429,   190,   273,   430,   477,   429,
     475,  1807,  2944,    18,    19,    20,   639,   640,  2950,    24,
      25,    26,    27,   430,  1366,   624,   491,   366,   295,  1853,
     430,   438,  2189,   299,   441,    20,    25,  2220,    27,  1373,
     512,   430,    27,   190,   643,   644,   625,  2186,    19,    25,
     190,    27,  1386,    24,    25,    26,  2778,   457,   458,    64,
     366,    20,   236,  1397,   663,   190,  1400,   429,    27,    20,
     133,  2923,  2924,   492,   190,   546,    27,   484,   549,  2801,
     552,   552,   501,  2271,   190,  1419,  1420,  1421,    25,    26,
    1634,   357,   128,   190,   457,   458,  2298,  2299,  2300,  2301,
     190,   137,   625,   369,    18,    19,    20,    21,    22,   581,
     146,  1655,   519,   379,   453,   151,  2433,  1737,   590,  2425,
     520,  1455,  1456,  1457,  1745,  1459,   545,   366,    26,   548,
     469,   397,   539,   540,   366,    26,   199,   366,   201,   448,
     449,   407,   638,   550,   410,   641,   642,   453,   555,    25,
     458,    27,  1486,   216,    26,  1489,  1490,   423,  3037,   195,
      26,   224,   429,   469,    25,   228,    27,   203,  2890,  2088,
    1504,  2090,  2091,   512,  3086,    26,   239,  1918,    26,  1799,
    1800,  1801,  1802,  3018,  3036,   190,  3038,   594,  1522,    24,
     253,    26,   619,  2395,  1528,  2397,  1530,  1531,  1532,  1533,
    3035,    26,    24,  1823,    26,   471,   512,   612,   613,   614,
     615,  1736,    26,   552,   453,  1836,    61,  1551,    24,   626,
      26,   453,  2094,   259,   453,   287,   288,  2949,  1562,    26,
     469,  1761,  1566,    26,   543,   501,    26,   469,   619,  1573,
     469,    58,   581,   391,   553,   511,   552,  1581,   284,   430,
     438,   590,   361,  1587,  1588,   291,  1590,   293,   619,  1879,
    3095,   449,    26,   437,  1885,   430,   532,   303,   430,   535,
    1143,   537,  1145,   512,  2996,   581,  1284,  3112,  1612,  1613,
     512,   426,   470,   512,   590,   108,   109,   110,   133,   477,
       5,   460,  1626,   329,   641,   642,   391,  1985,   458,   565,
      26,   337,   619,  1991,   258,   474,   426,  2103,   574,   478,
     391,  1645,   361,   552,    20,   648,   649,    26,  1762,  2629,
     552,   490,  1766,   552,    26,  2013,    26,  1771,   648,   649,
    1664,  1775,    26,  1777,  1778,  1779,   857,   858,   374,    26,
     861,   862,   581,  1677,  1678,  2578,  2579,  1681,   430,   581,
      20,   590,   581,    26,   199,    27,   201,  2153,   590,    26,
      26,   590,  3084,  1697,   400,  1699,  1700,   133,   619,  1703,
    1704,   216,   391,     5,   391,    26,  2578,  2579,   391,   224,
    2582,   302,   391,   228,  2004,   391,  2006,   391,   391,   623,
     395,     5,   391,   302,   391,   391,  1730,   391,  2438,  1733,
     623,  3123,   438,  1737,   391,   410,   430,   619,   253,   718,
    1744,   458,   616,   449,   619,     8,   426,  1751,   366,    20,
      21,    22,   427,   478,   525,   430,  2298,  2299,  2300,  2301,
     430,   459,   104,   199,    35,   201,   266,  2261,   443,  2263,
     430,  1985,   430,   420,   430,     5,   430,  1991,   430,  1783,
     216,   430,  1786,  2499,   617,   764,   430,   430,   224,   617,
     430,  1795,   228,   430,   430,  1799,  1800,  1801,  1802,  2013,
    1804,   595,   430,   430,   430,   430,  1810,  1811,   483,   420,
    1814,  1815,   154,   430,   430,   430,   430,   253,   430,  1823,
     495,    92,    93,    94,    95,    96,    97,   430,   430,  1833,
     430,   658,   430,   658,     8,   453,   459,   108,   109,   110,
     326,   596,   548,   549,   550,     5,     5,   430,   190,  1853,
     192,   469,   430,   383,   430,   561,   430,   430,   589,   344,
     578,     8,   537,    14,   575,     5,   658,     5,    25,  2159,
      27,   658,  2162,   420,   425,  1879,   430,  2735,   430,    65,
      26,    26,  1886,  1887,    91,  2743,   458,   438,   458,    46,
      47,  1895,    26,     5,   512,   595,   619,   589,   430,  2757,
    2594,   576,  1906,  2332,  2333,  2334,   430,  2336,  2337,  2338,
    2339,  2340,  2341,   588,  1918,   466,  2345,   470,   430,    20,
     625,    20,  1926,  2281,  2282,   600,   601,   430,   430,     5,
    2220,   482,   483,   608,   552,   625,   611,   488,   624,   430,
     491,   430,  2814,   625,   619,   661,   350,   289,  2820,  2821,
     556,  2823,  2824,  2825,  2826,     5,   935,    18,   664,    19,
    2832,    26,    26,   581,  2430,   122,   123,   152,   125,   126,
    1974,   218,   590,   130,  2038,   481,    25,   622,   249,   589,
    2044,   252,   578,   481,   619,  1989,     5,   546,  1992,   150,
     147,   148,    26,   399,  2460,  1999,  2000,  2001,  2708,   321,
    2004,   546,  2006,   546,    26,   430,   430,  2481,   165,   430,
    2014,   430,  2016,  2833,  2488,   357,   430,   391,   619,   576,
     458,  2025,   391,   365,  2219,   663,   546,   369,   391,   391,
     391,   391,    26,   190,   616,   391,  2578,  2579,   391,   391,
    2582,   430,     5,     5,  2048,   625,     5,  2051,   619,  2053,
     579,     5,   482,   391,     5,  2913,   625,  2038,   624,   430,
       8,  2065,   430,  2044,   406,    20,    21,  2281,  2282,    26,
    2074,   535,    65,    18,    19,    20,    21,    26,     5,   236,
     325,  2953,     5,   391,  2956,  2957,  2958,  2959,   360,   430,
     625,   430,   596,  2097,    14,  2099,   420,   420,     5,   659,
     371,   550,   546,  2107,     5,    26,  2110,   624,   100,   619,
    2114,   430,   625,   430,     5,   386,   638,   426,    34,   390,
      36,    37,    38,   426,   430,   460,  2668,   460,     8,  2671,
     430,   473,   430,    62,   118,   430,   430,    92,    93,    94,
      95,    96,    97,   430,   430,  2149,  2150,    92,    93,    94,
      95,    96,    97,     5,    26,  2159,    26,   428,  2162,   391,
     589,    25,   391,  2167,    25,    25,   391,    25,   391,     5,
     512,   619,     5,   619,   619,  2885,  2180,  2887,  2182,     8,
    2184,   325,  2186,    25,   458,   456,   553,   619,  2192,  3061,
     344,  2195,  3050,   430,  2484,   537,  2200,  3069,   360,  1178,
    2204,  2205,   344,   474,   425,  2921,   135,   136,  3021,  3022,
    3023,  3024,  3025,  3026,   344,   458,  2220,   430,   430,   430,
     430,   430,   430,  2227,  2514,  2229,   430,     5,   650,    26,
       5,  2235,  2236,  2237,  2238,  2239,  2240,   221,    30,   581,
    2734,     5,    25,    14,    14,   229,    26,   595,   590,   595,
     616,   235,   430,   237,    46,    47,     5,  2261,   430,  2263,
     619,   190,     5,     5,   248,  1244,     7,   196,   619,   391,
      30,  2737,  2814,    20,    21,  2279,     5,     8,  2820,  2821,
     437,  2823,  2824,  2825,  2826,   556,    46,    47,  2292,   619,
    2832,  2475,   276,   625,  2298,  2299,  2300,  2301,  2302,  2303,
      26,  2628,    26,    26,   619,   391,   391,   625,   292,  2313,
    2314,  2315,    26,   297,   589,   625,   391,  2321,   391,   391,
    1299,   391,   391,  2865,    20,   309,     5,   566,   274,   391,
     122,   123,   316,   125,   126,     5,     5,   266,   130,   268,
     546,     5,   667,     5,    30,    92,    93,    94,    95,    96,
      97,   622,   391,   571,   270,   147,   148,   273,   625,   275,
      46,    47,   122,   123,   391,   125,   126,   619,   619,    55,
     130,   391,  3082,   165,    60,   430,   470,     6,  2382,   295,
    2384,   625,     5,   553,   625,   210,    25,   147,   148,   305,
    2394,    25,  2396,    25,   618,  2399,   623,   623,   446,    25,
    2404,  2405,  2406,    25,   470,   165,    26,    26,   324,    26,
      26,  2953,    26,   342,  2956,  2957,  2958,  2959,   430,   105,
     106,   430,    26,   296,   972,    26,     5,   113,   268,  2433,
     391,   347,   525,  2437,  2438,   351,   122,   123,  2904,   125,
     126,   391,   467,     5,   130,  3161,   589,  2451,   430,  2739,
    2992,   391,   550,   240,    26,    25,    34,   426,    36,    37,
      38,   147,   148,   391,     5,   159,   391,   440,   397,  2473,
     344,    20,  2476,  2477,   139,  2833,   553,  2481,   430,   165,
    2484,   175,   176,   430,  2488,     5,   470,   430,   430,   430,
     184,   430,   430,   477,     5,    14,  2786,   210,   619,  2503,
       5,   391,   458,    26,   441,   434,    18,    19,    20,    21,
    2514,    26,   391,   429,   391,   499,   391,  2521,     5,  3061,
     504,   368,   618,   331,   218,  2529,   430,  3069,  2532,  2533,
    2534,  2535,  2536,   227,   391,   373,   568,    26,   391,   240,
     469,   391,   391,   430,   344,   391,   475,   458,   477,  2227,
     241,   625,   481,    14,   391,   484,  2560,   391,   487,   391,
     391,   391,   256,  2567,   356,   546,   619,   430,   497,   440,
     391,   239,  2576,   239,  2578,  2579,     7,    26,  2582,   625,
      92,    93,    94,    95,    96,    97,   391,   516,   447,  2593,
      26,   392,   391,   619,   523,   524,   525,   391,   575,   426,
     529,   625,   430,   391,   625,     5,   430,   301,   537,     5,
     391,  1590,  2616,   405,  2618,    22,    25,   241,   391,  2833,
    2298,  2299,  2300,  2301,   553,   391,   391,  3105,    35,     6,
       7,     8,     9,    10,    11,    12,   391,   391,     5,   391,
     391,  2199,  2149,  2107,  1869,  1574,    38,    40,  1261,   343,
     366,  2180,  1817,  1811,   289,   143,    34,   147,    36,    37,
      38,   211,   283,   399,  2668,   290,  1365,  2671,   355,  2673,
    1366,   213,  2676,  1769,   466,   373,  2446,   318,   385,   317,
    3095,   367,   387,  1489,  1786,    92,    93,    94,    95,    96,
      97,  1436,   270,   969,   529,   273,  1682,   275,  1675,  1291,
    1801,   108,   109,   110,  2708,  2252,  1532,   393,  2712,  2546,
    2714,  1922,  1604,  1294,  3148,  1621,  2751,   295,  1697,  1805,
      25,  1164,   120,    31,  2650,  1704,  1579,   305,    31,   487,
    2734,  1585,  2927,   268,   656,  2739,  1299,   936,  1920,   724,
     725,   726,  3032,  1588,  2647,  2850,   324,  1155,  1219,   685,
    1637,  3112,  2236,  1145,  2372,   740,  2860,   888,  1072,  2370,
    1243,   746,   747,  2047,  2354,  1025,   751,  1795,  1985,   347,
    1403,  1380,  1751,   351,  2778,  3123,  3086,  2017,   464,  1703,
    2974,  2403,  2786,  2048,  2708,  2439,  2382,  2384,  2051,   718,
    2671,  2992,  1318,  2682,  2065,    17,  2315,  2801,   965,  2896,
    2804,  2897,  2577,  2293,  1352,  1353,  2437,  3084,  2812,  2941,
    2814,  1359,  2235,   961,  1313,  2576,  2820,  2821,  1286,  2823,
    2824,  2825,  2826,  2812,  2831,  2829,  1733,  2831,  2832,  2820,
    2834,  1160,   364,    -1,    24,    25,    26,    27,  2842,    -1,
      -1,    -1,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,   429,    -1,  3143,    -1,    -1,    -1,    -1,    -1,   788,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   557,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,  2885,    -1,  2887,    -1,    -1,  2890,    -1,    -1,    -1,
      -1,  2895,   270,  2897,    -1,   273,    -1,   275,    -1,    -1,
    2578,  2579,   831,    -1,  2582,    -1,    -1,  1886,  1887,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1895,   295,   847,   848,
     849,    -1,   851,    -1,   853,   854,    -1,   305,    -1,    -1,
     859,   860,    -1,    -1,    -1,    -1,    -1,  2941,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2949,    -1,    -1,    -1,  2953,
      -1,   637,  2956,  2957,  2958,  2959,  2960,    -1,    -1,   645,
      -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,   347,
    2974,   900,    -1,   351,    -1,    -1,    -1,    -1,    -1,   386,
      -1,    -1,   911,   390,    -1,    -1,    -1,    -1,  2992,    -1,
    2668,    -1,  2996,  2671,    -1,    -1,    -1,    -1,    -1,    -1,
     190,    -1,  3006,    -1,    -1,    -1,   935,   936,  1556,    -1,
      -1,    -1,    -1,  1992,    -1,   944,    -1,    -1,    -1,    -1,
      -1,   428,  2001,    -1,    -1,    -1,    -1,    -1,  3032,  3033,
      -1,   960,   961,  3037,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,
      -1,   429,  1600,    -1,    -1,    -1,  1041,  3061,    -1,    -1,
      -1,    -1,    -1,  1048,    -1,  3069,  1051,   474,    -1,    -1,
      -1,    -1,  2051,    -1,  2053,    -1,    -1,    -1,  3082,  1064,
    3084,    -1,  3086,  1068,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1076,    -1,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,    -1,    -1,  2094,    -1,    -1,    -1,  3123,
      -1,    -1,    -1,  1108,  1109,    -1,    -1,    -1,  1113,    -1,
    1115,    -1,    -1,    -1,  2812,    -1,  2814,    -1,    -1,  3143,
      -1,    -1,  2820,  2821,    -1,  2823,  2824,  2825,  2826,   556,
      -1,    -1,    -1,    -1,  2832,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,     5,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,  1131,    -1,    -1,   395,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    64,  1143,   622,  1145,  1146,  1147,    -1,
     410,    -1,    -1,    -1,    -1,  1154,  1155,    -1,    -1,  1158,
      -1,    -1,    -1,  1162,    -1,    -1,  1165,   427,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,
    2229,    -1,    -1,   443,    -1,    -1,  2235,  2236,  2237,  2238,
    2239,  2240,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,  2953,    -1,    -1,  2956,  2957,
    2958,  2959,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1221,   483,    -1,    -1,    -1,    -1,    -1,    -1,
    2279,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2992,  1863,  1864,    -1,    -1,  2298,
    2299,  2300,  2301,    -1,    -1,    -1,  1874,  1256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,  1280,    -1,  2332,  2333,  2334,  1285,  2336,  2337,  2338,
    2339,  2340,  2341,    -1,    -1,    -1,  2345,    -1,    -1,  1298,
    1299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1927,
    1928,  1929,  1930,  3061,    -1,    -1,   576,  1935,  1936,  1937,
    1938,  3069,    -1,    -1,  1942,    -1,    -1,    -1,   588,    -1,
      -1,    -1,    -1,  2382,    -1,  2384,    -1,    -1,    -1,    -1,
     600,   601,    -1,    -1,    -1,  2394,    -1,  2396,   608,    -1,
    2399,   611,    -1,   249,   260,  1354,   252,    -1,    -1,   619,
      -1,    -1,    -1,    -1,    -1,    35,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,  2437,    -1,
      -1,    -1,    -1,   299,    -1,    -1,    35,    -1,    -1,    -1,
    1455,  1456,  1457,    -1,  1459,    -1,    -1,    -1,  2026,  2027,
    1409,    -1,   318,    -1,    -1,  2033,  2034,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,  1486,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2499,   357,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,  2521,   379,   395,   371,    -1,    -1,    -1,    -1,
    2529,    -1,    -1,  2532,  2533,  2534,  2535,    -1,    -1,   410,
     386,   397,    -1,    -1,   390,    -1,  1551,    -1,    -1,    -1,
      -1,   407,    -1,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,  1566,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,    -1,  2578,
    2579,    -1,   428,  2582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1545,    -1,    -1,   470,
      -1,    -1,  2170,  2171,  1553,    -1,    -1,   463,    -1,    -1,
     456,  2179,   483,    -1,    -1,  1564,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,   474,   249,
     486,    -1,   252,    -1,    -1,    -1,  1585,    -1,    -1,    -1,
    2208,  2209,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,
      -1,    -1,   508,    -1,    -1,   511,    -1,    -1,    -1,    -1,
     249,    -1,    -1,   252,    -1,    -1,   537,    -1,    -1,  2668,
      -1,    -1,  2671,    -1,  2673,    -1,   532,  2676,    -1,   535,
      -1,   537,  1631,  1632,  1633,    -1,    -1,    -1,  1637,    -1,
      -1,    -1,    -1,    -1,  2262,    -1,  2264,     9,    -1,    -1,
     556,    -1,    -1,    -1,    -1,   576,    18,    19,    20,    -1,
     556,    -1,    24,    25,    26,    27,    -1,   588,   574,    -1,
    1669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,
     601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,
      -1,   371,    64,    -1,  2322,  2323,    -1,    -1,  2326,  2327,
      -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    -1,    -1,   622,    -1,  1783,  2778,
      -1,  1786,   371,    -1,    -1,    -1,  1735,  1736,    -1,    -1,
      -1,    -1,  2360,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,  2801,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,    -1,    -1,  2814,    -1,    -1,    -1,    -1,
      -1,  2820,  2821,    -1,  2823,  2824,  2825,  2826,    -1,    -1,
      -1,    -1,    -1,  2832,    -1,  2834,   456,    23,    -1,   428,
      -1,    32,    -1,    -1,    -1,    -1,    -1,  1796,    34,  1798,
      36,    37,    38,    -1,   474,    -1,    -1,    -1,  1807,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2865,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,   190,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    79,    80,
      -1,  2890,    -1,    -1,    -1,  1844,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    91,  2474,    -1,    -1,    -1,
    2478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      18,    19,  2921,  2491,  1873,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,  2510,    -1,    -1,    -1,    -1,   133,    -1,    -1,
    2949,    -1,    -1,    -1,  2953,    -1,    -1,  2956,  2957,  2958,
    2959,    -1,    -1,    -1,    -1,    -1,    64,   556,    -1,     5,
    1919,  1920,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
     166,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2992,    -1,    -1,    -1,  2996,    -1,    -1,
      -1,    -1,   622,    -1,    -1,   191,    -1,  3006,    -1,    -1,
      -1,    30,    -1,   199,    -1,   201,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    46,    47,    -1,
     216,    -1,    -1,   622,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,    -1,   238,   239,   240,   241,    75,    -1,    -1,    -1,
      -1,    -1,  3061,    -1,    -1,    -1,    -1,   253,    -1,   260,
    3069,    -1,    -1,    -1,    -1,  2024,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   395,   270,  3084,    -1,   273,    -1,   275,
      -1,    -1,   190,    -1,    -1,    -1,   282,    -1,   410,    -1,
      -1,    -1,    -1,   122,   123,    -1,   125,   126,   299,   295,
      -1,   130,    -1,    -1,    -1,   427,    -1,    -1,   430,   305,
      -1,    -1,    -1,    -1,  3123,    -1,    -1,   318,   147,   148,
     442,   443,    -1,    -1,    -1,    -1,    -1,    -1,   324,   325,
      -1,    -1,    -1,   334,  2149,  2150,   165,    -1,    -1,    -1,
      -1,    -1,    -1,   339,  2103,    -1,    -1,    -1,   470,    -1,
      -1,   347,  3161,    -1,    -1,   351,   357,    -1,    -1,    -1,
      -1,   483,    -1,    -1,   360,   361,   362,    -1,   369,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,  2192,   379,    -1,
    2195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2204,
    2205,  2769,    -1,    -1,  2153,    -1,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   407,   236,    -1,  2787,
      -1,    -1,    -1,    -1,   260,   537,    -1,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,  2197,    -1,
    2199,    -1,  2201,    -1,   440,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   299,   576,  2214,    -1,    -1,    -1,    -1,
    2219,    -1,   463,    -1,    -1,    -1,   588,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,    -1,    -1,    -1,   600,   601,
      -1,    -1,    -1,    -1,   480,   486,   608,   395,    -1,   611,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,
     501,    -1,   410,    -1,    -1,    -1,    -1,   508,    -1,    -1,
     511,   357,    -1,    -1,  2273,  2274,    -1,    -1,    -1,   427,
      -1,    -1,   430,   369,    -1,    -1,    -1,   356,    -1,    -1,
      -1,   532,    -1,   379,   535,   443,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,  2925,    -1,    -1,
      -1,   397,    -1,    -1,    -1,   556,    -1,  2316,    -1,    -1,
      -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   574,   482,   483,   405,   423,    -1,    -1,
      -1,    -1,   578,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2356,    -1,    -1,
      -1,  2979,  2980,    -1,  2982,    -1,  2984,  2985,   437,    -1,
    2369,    -1,    -1,    -1,    -1,   616,    -1,   463,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,   537,
      -1,    -1,    -1,    -1,    -1,    -1,  2451,   466,    -1,    -1,
     486,    -1,   638,   639,   640,   641,   642,   643,   644,    -1,
     646,   647,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,
      -1,    -1,   508,    -1,    -1,   511,    -1,   663,   576,    -1,
      -1,  2430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     588,    -1,    -1,    -1,    -1,    -1,   532,    -1,  2503,   535,
      -1,   537,   600,   601,    -1,  3073,    -1,  3075,    -1,    -1,
     608,  2460,    -1,   611,    -1,    -1,    -1,    -1,    30,    -1,
     556,   619,    -1,    -1,    -1,    -1,  2475,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    -1,    -1,   574,    -1,
      -1,  2490,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2499,    -1,    -1,  3121,    66,    67,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3137,
    3138,    83,    -1,  3141,    -1,    -1,  3144,    -1,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    -1,   129,   130,   131,
     132,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,   141,
      -1,   143,   144,   145,    -1,   147,   148,    -1,    -1,    -1,
      -1,   153,    -1,   155,   156,    -1,   158,    -1,   160,   161,
      -1,    -1,   164,   165,    -1,    -1,   168,   169,   170,    -1,
     172,   173,    -1,    -1,    -1,   177,   178,   179,    -1,   181,
      -1,    -1,    -1,   185,    -1,   187,   188,    -1,    -1,    -1,
      -1,   193,    -1,    -1,    -1,   197,    -1,    -1,   200,    -1,
     202,    -1,   204,    -1,   206,    -1,   208,   209,  2647,   211,
     212,   213,    -1,    -1,    -1,   217,    -1,   219,   220,    -1,
     222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,   246,   247,    -1,    -1,   250,   251,
      -1,    -1,   254,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   263,   264,   265,    -1,   267,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,   278,   279,    -1,   281,
      -1,    -1,    -1,   285,   286,    -1,    -1,    -1,   290,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   298,    -1,  2737,    -1,
      -1,    -1,    -1,    -1,   306,   307,   308,    -1,    -1,    -1,
      -1,    -1,   314,   315,    -1,    -1,    -1,    -1,   320,    -1,
      -1,   323,    -1,    -1,    -1,   327,   328,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   356,    -1,  2795,    -1,    -1,    -1,
      -1,    -1,   364,    -1,    -1,     6,     7,     8,   370,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   393,    -1,    -1,    35,    -1,    -1,  2836,   400,    -1,
     402,   403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,
      -1,  2850,    -1,    -1,    -1,    -1,  2855,    -1,  2857,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   450,    -1,
      -1,    92,    93,    94,    95,    96,    97,  2896,    -1,   461,
      -1,    -1,    -1,    -1,    -1,  2904,   468,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2921,    -1,    -1,    -1,    -1,    -1,  2927,    -1,
     492,   493,    -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   509,    -1,    -1,
      -1,    -1,    -1,   515,   516,   517,   518,    -1,    -1,    -1,
     522,    -1,    -1,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,   533,   534,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3037,   545,    -1,   547,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   558,    -1,   560,    -1,
      -1,   563,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3021,  3022,  3023,  3024,  3025,  3026,    -1,    -1,
      -1,    -1,    -1,   595,    -1,    -1,   598,    -1,    -1,    -1,
      -1,   603,    -1,    -1,   606,   607,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,
      -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,   651,
     652,   653,   654,   655,   656,   657,    -1,    -1,   660,    35,
     662,    -1,   664,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,  3161,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,
     391,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      -1,    -1,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    73,    74,    -1,    76,    77,    78,
      -1,   622,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   390,   391,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,   249,    -1,    -1,   252,    -1,    92,
      93,    94,    95,    96,    97,   386,    -1,    -1,    -1,   390,
     391,    -1,   428,    -1,    -1,   108,   109,   110,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   176,    -1,   249,
     456,    -1,   252,    -1,    -1,   184,    -1,   428,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,   218,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,   371,   256,   257,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   386,    -1,    -1,    -1,   390,   391,    -1,    -1,    -1,
     556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,
      -1,   371,   301,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,   556,   386,    -1,    -1,    -1,
     390,   391,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   456,    -1,    -1,   343,    -1,   622,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,   428,   474,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,   622,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     399,    -1,   249,    -1,   474,   252,    -1,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,   371,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,   386,    -1,    -1,    -1,   390,   391,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,    -1,   622,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   474,    -1,    -1,   371,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,
      -1,    -1,    -1,   390,   391,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,   556,   249,    -1,    -1,   252,    -1,   456,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   474,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,    -1,    35,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,   386,    -1,    -1,    -1,   390,   391,    -1,   556,
      -1,    -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
     249,   386,    -1,   252,   428,   390,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   456,    -1,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    35,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   456,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   474,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,    -1,    -1,   249,    -1,    -1,   252,   108,   109,   110,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,   108,   109,   110,    -1,    -1,     8,   428,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,   456,    -1,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   371,    35,   622,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   390,    -1,    -1,    -1,   249,    -1,
      -1,   252,    92,    93,    94,    95,    96,    97,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,    -1,
      -1,    -1,   428,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   441,    -1,   556,    -1,   108,
     109,   110,    -1,    -1,   249,    -1,    -1,   252,    -1,    -1,
     456,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,   441,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   456,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   474,   622,    -1,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    98,   249,
     556,    -1,   252,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   371,   428,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     249,   386,     9,   252,   556,   390,    -1,    -1,    -1,    -1,
      -1,    18,    19,    -1,    -1,   456,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,   622,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
     622,   456,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   474,
      -1,   371,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,
     390,     9,    -1,    -1,    -1,   556,    -1,    -1,    -1,    -1,
      18,    19,   371,    -1,    -1,    -1,    24,    25,    26,    27,
     249,    -1,    -1,   252,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,   428,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,
      35,   556,    -1,    71,    -1,    -1,   456,    -1,    -1,   428,
      -1,   622,    -1,   190,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,
      -1,    99,   332,    -1,    -1,    -1,    -1,   456,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   474,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,   622,     9,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    18,    19,    -1,
      -1,    -1,   371,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,   556,    -1,    -1,   409,
      -1,    -1,   289,    -1,    -1,    -1,   416,   294,    59,    -1,
      -1,    -1,   190,    64,   192,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,   428,
      -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    -1,    -1,
      -1,    -1,   441,    -1,    -1,   455,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,   479,
     357,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,   489,
     490,     9,   369,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      18,    19,    20,   622,    -1,   505,    24,    25,    26,    27,
     387,    -1,    -1,    -1,   249,   392,    -1,   252,   395,    -1,
      -1,   289,    -1,    -1,     9,    -1,   294,   527,    -1,   406,
     530,   531,    -1,    18,    19,   412,   536,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,   422,    64,    -1,    -1,   190,
     427,   192,    -1,   430,   322,    -1,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,   443,   556,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,   357,
      -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   369,    -1,    -1,   604,   482,   483,    -1,    -1,    -1,
     487,    -1,    -1,    -1,    99,    -1,    -1,    -1,   495,   387,
      -1,    -1,    -1,    -1,   392,    -1,    -1,   395,    -1,   506,
      -1,    -1,    -1,   622,    -1,   512,   371,    -1,   406,    -1,
      -1,    -1,    -1,    -1,   412,    -1,    -1,    -1,   289,    -1,
      -1,   386,    -1,   294,   422,   390,    -1,    -1,    -1,   427,
     537,    -1,   430,    -1,    -1,   433,    -1,    -1,    -1,    -1,
      -1,    -1,   190,    -1,   442,   443,    -1,    -1,    -1,    -1,
      -1,   322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,   190,    -1,   192,    -1,    -1,
      -1,   588,    -1,   590,    -1,   483,   357,    -1,    -1,   487,
      -1,   456,    -1,   600,   601,    -1,    -1,   495,   369,    -1,
      -1,   608,    -1,    -1,    -1,    -1,    -1,    -1,   506,   474,
     508,    -1,   619,    -1,   512,    -1,   387,    -1,    -1,    -1,
      -1,   392,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,    -1,    -1,   537,
      -1,   412,    -1,    -1,    -1,    -1,   294,    -1,    -1,    -1,
      -1,   422,    -1,    -1,    -1,    -1,   427,    -1,    -1,   430,
      -1,    -1,   433,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,   443,    -1,   289,    -1,    -1,    -1,    -1,   294,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     588,   556,   590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,   601,    -1,    -1,    -1,   322,    -1,    -1,
     608,   482,   483,    -1,    -1,    -1,   487,    -1,    -1,    -1,
      -1,   619,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   506,    -1,    -1,    -1,    -1,
      -1,   512,   357,    -1,    -1,    -1,    -1,   395,    -1,    -1,
      -1,    -1,    -1,    -1,   369,    -1,    -1,   622,    -1,    -1,
      -1,    -1,   410,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,   387,    -1,    -1,    -1,    -1,   392,    -1,   427,
     395,    -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   442,   443,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,
     581,    -1,   427,    -1,    -1,   430,    -1,   588,   433,   590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,   443,   600,
     601,    -1,    -1,    -1,    -1,   483,    -1,   608,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,   619,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,    -1,
      -1,    -1,   487,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,
      -1,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    35,   537,    -1,    -1,    -1,    -1,    -1,   576,    -1,
      92,    93,    94,    95,    96,    97,    -1,    -1,    -1,    -1,
     588,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,   600,   601,    -1,    64,    -1,    -1,    -1,    -1,
     608,    -1,    -1,   611,    -1,    -1,   581,    -1,    -1,    -1,
      -1,   619,    -1,   588,    -1,   590,    -1,    -1,    92,    93,
      94,    95,    96,    97,    -1,   600,   601,    -1,    -1,    -1,
      -1,    -1,    -1,   608,   108,   109,   110,    -1,    -1,    18,
      19,    20,    -1,    -1,   619,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    64,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,
     252,    92,    93,    94,    95,    96,    97,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,   190,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    64,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,   252,    -1,    -1,    -1,   249,    -1,   371,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,    -1,   390,    -1,    -1,    -1,
     249,    -1,    -1,   252,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,    20,
      -1,   410,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   474,    -1,   428,    -1,    -1,    -1,   427,   190,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,   443,    -1,    -1,    -1,    -1,    -1,
     190,    -1,   456,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
     371,    -1,    -1,    -1,   483,    -1,   395,   371,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   386,   495,    -1,    -1,   390,
      -1,   410,   386,    -1,   556,    -1,   390,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,   443,    -1,    -1,   428,   537,    -1,
      -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,   428,
     622,    -1,   456,   482,   483,    -1,    -1,   576,    -1,   190,
      -1,    -1,    -1,   474,    -1,    -1,   495,    -1,    -1,   588,
     474,    -1,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
      -1,   600,   601,    -1,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,   611,    -1,    -1,   474,    -1,    -1,   622,    -1,
     619,    39,    40,    41,    42,    43,    44,    -1,   537,    -1,
      -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   556,   427,   576,    -1,   430,
     410,    -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      98,   395,   443,    -1,    -1,    -1,    -1,   427,    -1,    -1,
     430,   600,   601,    -1,    -1,    -1,   410,   556,    -1,   608,
      -1,    -1,   611,   443,    -1,    -1,    -1,    -1,    -1,    -1,
     619,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,   482,   483,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     470,   622,    -1,    -1,   495,    -1,    -1,    -1,   622,    -1,
      -1,    -1,    -1,   483,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,   483,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,   495,    -1,    -1,   395,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   576,   427,    -1,    -1,   430,
      -1,    -1,    -1,   537,    -1,    -1,    -1,   588,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,   576,    -1,    -1,   600,
     601,   259,    -1,    -1,    -1,    -1,    -1,   608,   588,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,
     600,   601,   576,    -1,    -1,    -1,   284,    -1,   608,    -1,
      -1,   611,   483,    -1,   588,   293,    -1,    -1,    -1,   619,
      -1,    -1,    -1,    -1,   495,    -1,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,    -1,   611,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,
      -1,   329,    -1,    -1,   332,    -1,    -1,    -1,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,   537,   345,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   576,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,
     601,   409,    -1,    -1,    -1,    -1,    -1,   608,   416,    -1,
     611,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,
      -1,    -1,    -1,   431,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   479,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   489,   490,    -1,    -1,    -1,    -1,   495,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   505,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   527,
      -1,    -1,   530,   531,    -1,    -1,    -1,    -1,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   593,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   602,    -1,   604
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   236,   356,   405,   437,   466,   726,   754,
     755,   805,   973,  1026,  1028,  1029,  1030,  1035,  1037,  1050,
    1051,  1052,  1053,  1054,  1470,    28,    29,   727,   728,   729,
     730,   731,    27,   938,  1489,   355,   533,   547,   572,   620,
    1471,  1471,  1471,  1471,  1471,  1471,  1471,  1471,   938,    25,
     938,  1391,  1055,   756,  1391,   755,  1470,     0,  1027,  1030,
    1035,  1053,  1470,    31,   729,   731,   938,  1473,   589,   938,
    1472,   625,   806,    25,   190,   753,   754,   926,   938,   943,
    1056,  1091,  1092,  1093,  1094,  1095,  1099,   353,   758,   759,
     760,   761,   764,   765,    55,    60,   105,   106,   113,   367,
     393,   464,   557,   637,   645,   726,   732,   898,   972,  1031,
    1032,  1034,  1038,  1039,  1045,  1057,  1078,  1211,  1221,  1470,
     938,  1472,   616,  1094,   242,   457,   458,  1101,    20,   938,
    1098,   619,   759,     5,   757,   353,   938,     5,   781,   783,
     784,   938,  1222,   938,   938,  1212,  1046,   938,   938,  1034,
    1040,   260,   299,   318,   357,   369,   379,   397,   407,   423,
     463,   486,   501,   508,   511,   532,   535,   537,   556,   574,
     807,   808,   809,   812,    25,  1091,  1097,    18,    19,    26,
     430,   676,   678,  1091,  1102,  1103,   458,    14,   804,   761,
     521,  1198,   762,   759,   764,    32,    79,    80,    89,   260,
     299,   318,   334,   357,   369,   379,   397,   407,   423,   463,
     486,   501,   508,   511,   532,   535,   537,   556,   574,   616,
     767,   775,   786,   787,   938,   430,   112,   938,   753,   899,
    1079,   938,   814,   535,   766,   790,   792,   793,   791,   800,
     801,   430,   430,   813,   458,   430,   430,   759,   788,   425,
     676,    18,    19,    20,    21,    22,   677,    26,     5,   426,
    1102,    24,    25,    26,   619,   938,   944,    19,    25,    26,
     763,   944,   777,   766,   778,   790,   791,   430,   430,   776,
     458,   430,   430,   788,   759,   785,   430,    26,   938,   430,
    1047,   753,   753,   430,   938,   430,   457,   770,   625,   366,
     453,   469,   512,   552,   581,   590,   794,   625,   366,   453,
     469,   512,   552,   581,   590,   802,    26,    26,   815,   816,
     817,   818,   938,    26,   773,   774,    26,    26,   619,   391,
     676,  1103,   458,   426,    26,    26,   759,   770,   759,    26,
      26,   758,   773,    26,    26,   619,    58,   782,  1223,   391,
     430,  1213,  1490,  1491,  1492,  1493,  1494,   900,  1080,  1041,
     619,    26,   795,   796,   430,   797,   802,   803,   797,   430,
     798,     5,   391,     5,   391,     5,   283,     5,   807,   426,
       5,     5,   391,   391,   759,   789,  1102,   458,   619,    26,
     258,     5,   391,     5,   391,   283,   426,     5,   391,   391,
     789,   938,  1108,  1109,  1111,  1058,  1108,   361,  1491,  1198,
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
     951,   952,   965,   974,   995,   996,   998,  1002,  1017,  1018,
    1022,  1023,  1024,  1025,  1033,  1048,  1061,  1072,  1073,  1074,
    1085,  1088,  1124,  1127,  1129,  1135,  1136,  1139,  1142,  1145,
    1147,  1149,  1152,  1159,  1164,  1168,  1169,  1170,  1182,  1183,
    1186,  1192,  1193,  1194,  1219,  1234,  1235,  1236,  1237,  1238,
    1243,  1249,  1250,  1268,  1271,  1301,  1303,  1392,  1393,  1424,
    1425,  1432,  1443,  1470,  1474,  1479,  1481,  1483,  1487,  1488,
    1495,   726,  1036,  1470,   624,   647,  1081,  1082,  1108,    20,
     391,   425,   771,   794,    26,   799,    26,    26,    26,   816,
     818,   810,   774,    26,   426,  1102,    20,   771,   430,    26,
      26,   768,    26,   619,   391,     5,  1108,   391,   938,   349,
     939,   940,  1489,   938,   938,  1166,   933,   939,   933,    25,
     190,   938,  1100,  1465,  1466,  1467,   938,  1485,   938,  1245,
    1246,   938,    26,   673,  1091,  1241,   933,  1166,   863,    26,
     944,  1206,  1207,  1206,     9,    18,    19,    25,    26,    59,
      64,    71,    99,   192,   289,   294,   322,   357,   369,   387,
     392,   395,   406,   412,   422,   427,   430,   433,   442,   443,
     483,   487,   495,   506,   512,   537,   581,   588,   590,   600,
     601,   608,   838,   845,   846,   847,   848,   849,   850,   851,
     852,   864,   869,   880,   881,   882,   883,   938,   944,  1091,
    1201,  1270,  1383,   840,   863,   939,  1433,  1433,   824,  1166,
     933,  1239,  1091,   935,   939,   845,  1433,  1091,  1166,  1091,
    1269,  1433,    25,   585,  1075,  1076,  1091,   933,   933,  1075,
     934,   939,   938,  1076,   933,  1433,   933,   935,  1091,  1122,
    1123,   931,   939,   935,   374,   561,   666,   930,   938,   997,
     938,   734,   936,   939,    25,  1302,  1465,   863,   863,   939,
    1148,   894,   128,   137,   146,   151,   195,   203,   259,   284,
     291,   293,   303,   329,   337,   374,   400,   438,   449,   548,
     549,   550,   561,   664,  1011,  1143,  1144,  1091,   844,   845,
    1158,   930,  1480,  1480,   932,   939,   863,    25,  1091,  1146,
    1220,  1091,  1197,    25,  1091,  1427,   845,  1188,  1189,  1190,
    1199,  1200,   845,  1475,   104,   154,   192,   289,   365,   406,
     473,   537,   690,   869,   938,  1091,  1229,   713,   845,   931,
    1472,  1062,   845,   931,    26,  1091,  1019,   931,   845,  1444,
     845,  1206,   938,   947,   948,   935,   947,  1480,   935,   947,
    1480,   953,   947,    25,    26,   384,   486,   944,  1000,  1091,
    1110,  1112,    65,   274,   344,   389,   568,   648,   649,   650,
     659,   680,   955,   957,   959,   961,   963,  1086,  1087,  1090,
     335,   346,   398,   413,   502,  1304,   639,   640,   902,   903,
     904,   938,  1083,   646,  1082,   391,   302,   391,   391,   391,
     391,   623,     5,   391,   426,   302,   759,   779,   780,   391,
     391,   623,   391,   938,  1224,  1111,   391,  1214,    56,    57,
      84,    85,    86,   454,   541,   584,  1251,  1252,  1253,  1256,
    1259,  1262,  1263,  1264,  1265,   430,   619,  1467,  1101,   616,
    1140,   619,     8,   538,   587,     5,   391,   426,    25,   938,
    1376,   478,  1167,  1110,   108,   109,   110,   838,   838,   838,
     430,   525,  1218,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   838,   366,   453,   469,   512,   552,   581,   590,
    1386,  1387,   430,   430,   430,   838,   838,   430,   430,   750,
     838,   430,   853,   430,   430,   430,   430,   430,   430,   430,
     430,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    35,    92,    93,
      94,    95,    96,    97,   108,   109,   110,   249,   252,   371,
     386,   390,   428,   456,   474,   556,   622,   749,   839,   854,
     856,   857,   858,   859,   860,   861,   862,    26,   944,   430,
     520,   420,   482,   841,   842,   845,  1091,  1117,  1376,   679,
     680,   827,   266,    87,    88,   625,   459,     5,   618,   625,
     617,   617,  1125,   595,   420,     5,   556,   975,   459,   658,
    1477,   430,   458,   619,   658,   384,   736,  1091,   546,   617,
    1130,  1131,  1132,   326,  1300,   843,   845,   843,     8,   932,
      26,   500,   554,   925,  1091,   925,   925,   925,    25,   177,
     304,   310,   311,   312,   330,   438,   441,   484,   519,   539,
     540,   550,   555,   594,   626,  1015,  1016,   925,   925,   596,
    1012,   680,  1012,  1012,   926,   926,  1012,  1012,   680,     5,
     333,   385,     5,   679,     5,    81,    82,   539,   626,  1003,
     661,  1478,   844,   612,   613,   614,   615,  1196,  1198,   383,
    1233,  1198,  1190,     5,   617,  1191,   845,   430,   430,   430,
     430,    25,   709,   938,   430,  1427,   344,   430,   520,   589,
     578,   714,   721,   712,    25,  1077,  1091,  1184,     8,  1187,
      14,   938,  1096,  1104,  1105,  1107,  1115,  1116,  1160,   162,
     344,   544,   577,    33,   190,   553,  1445,  1446,  1447,  1448,
     575,     5,   658,   658,   843,  1110,  1117,   999,   420,     5,
     150,   979,   430,  1091,   843,   430,    26,    26,    65,  1089,
      25,  1091,  1431,  1431,   939,  1284,  1148,   932,   118,   221,
     229,   235,   237,   248,   276,   292,   297,   309,   316,   470,
     477,   499,   504,  1272,  1273,  1281,  1291,  1292,  1298,  1299,
    1305,  1306,  1315,  1334,  1338,  1403,  1404,  1434,  1435,  1438,
    1439,  1449,   905,   906,    91,   901,   912,   913,   904,  1084,
    1490,  1042,   458,   807,   774,   458,     5,   391,   781,   753,
    1059,   753,   157,   296,   372,   430,   475,   491,  1321,  1333,
     430,   938,  1267,    26,   245,   258,   430,   475,   491,   938,
    1248,  1261,  1319,  1320,  1325,  1327,  1329,   430,   938,  1258,
     430,  1248,  1254,     5,    25,   941,  1094,  1467,  1465,   576,
     616,  1141,    20,   938,  1121,  1468,   938,  1486,  1246,   595,
     619,   589,   430,   430,   827,  1480,   838,   930,   930,  1480,
    1480,   470,  1407,   838,    25,    26,    19,    24,    25,    26,
     884,   885,   886,   887,   838,   430,   625,  1480,    20,   838,
     391,  1407,   838,    20,  1201,   872,   870,   876,   838,   874,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   838,   838,   838,   838,   838,   838,   838,   838,
     838,   838,   430,   838,   838,   430,   865,   938,  1091,     5,
     625,   430,  1465,    25,   943,  1165,  1165,  1427,  1075,   845,
     845,   845,   927,   928,   430,  1091,  1123,   788,   976,   977,
     625,  1427,  1480,  1478,   938,   676,    20,   666,   938,   997,
    1091,   735,   624,   845,   350,  1134,   556,  1133,     5,    68,
      70,    72,   617,   625,   819,  1110,   895,    18,    19,   430,
    1013,  1015,  1144,   926,   845,   344,   595,   930,    26,    26,
     679,   152,  1195,   218,  1200,  1206,  1476,   938,    25,   888,
     930,  1480,   589,   930,   622,  1091,   694,   938,   938,   845,
     339,   717,   721,   578,   715,   723,    23,   234,  1064,  1068,
     481,   863,   481,  1185,   845,   457,  1101,   619,     5,  1020,
     546,  1161,  1091,  1466,  1469,  1091,  1113,  1114,   189,  1446,
     966,   948,  1480,  1480,   958,   959,   979,   979,    34,    36,
      37,    38,   270,   273,   275,   295,   305,   347,   351,   429,
     978,   980,   981,  1007,  1091,  1112,   546,   681,    26,   399,
     964,   321,  1426,  1426,   135,   136,   436,   546,   938,  1335,
    1336,  1377,   788,  1376,  1376,  1274,   788,   938,  1436,  1436,
     359,   475,   585,  1415,  1376,  1282,   167,   438,   449,   470,
     477,  1308,  1309,  1310,   287,   288,  1398,  1490,  1490,   384,
     914,  1091,   641,   642,   907,   908,   909,   480,   624,   643,
     644,   663,   917,   918,  1490,   753,    26,   772,   772,   780,
    1225,   753,  1215,  1323,  1376,  1266,  1333,   430,  1266,   430,
     430,  1260,  1261,   430,   430,    63,   299,   357,   369,   379,
     397,   407,   410,   423,   471,   501,   511,   532,   535,   537,
     565,   574,  1368,  1369,  1370,  1372,  1257,  1258,  1254,  1255,
     663,  1252,   391,   619,  1427,   576,   458,   546,  1484,   674,
     675,   938,   938,   938,  1242,   863,   391,   391,   391,   391,
     391,  1415,   391,   391,   391,   391,   589,   885,    19,    26,
     589,   391,   391,    26,  1387,   391,   391,   391,   391,     5,
     751,   391,   838,   838,   838,   391,   838,   391,   391,   391,
     441,   441,   441,   863,  1407,   441,   863,  1407,   706,   707,
     708,   838,   430,   841,   938,  1240,   616,  1137,   625,     5,
       5,     5,   579,   845,   619,     5,   482,   625,   391,   426,
     430,   624,   163,   166,   270,   273,   737,   740,   741,  1007,
     738,   739,   938,   430,   939,   648,   649,  1138,   845,   938,
     938,   928,   929,   508,  1480,   827,     8,   897,    26,    26,
    1014,  1015,  1091,   535,  1153,    65,   838,  1198,    26,  1091,
    1490,     5,     5,     5,   391,   391,   710,   938,   391,  1427,
     706,   430,   430,   722,   718,   360,   716,   845,   339,   719,
     723,   596,  1009,  1069,  1065,   362,  1063,  1064,   843,   625,
    1097,    20,   938,  1106,  1116,    14,    18,    19,    20,    25,
      26,    64,   395,   410,   427,   430,   443,   482,   483,   495,
     537,   576,   588,   600,   601,   608,   611,   938,   944,  1162,
    1163,  1382,  1384,  1414,  1419,  1420,  1421,  1469,   420,   420,
       5,  1490,   960,   961,   550,   937,   546,   990,   989,   992,
     991,   930,   993,   930,   994,   988,   987,   985,   984,  1008,
     324,   981,   986,  1480,    39,    40,    41,    42,    43,    44,
      98,   332,   345,   409,   416,   455,   479,   489,   490,   495,
     505,   527,   530,   531,   536,   593,   604,   682,   683,  1005,
    1006,     5,    26,  1427,   248,  1091,   470,  1408,  1409,  1427,
    1148,  1402,  1404,   100,   100,   595,  1146,  1337,  1338,   430,
    1316,   149,   525,  1342,  1349,  1376,   174,   271,  1440,   619,
     625,  1405,  1450,   341,   350,   374,   377,   395,   500,   554,
     561,   932,  1285,  1290,   430,  1311,   624,     5,    25,   938,
    1399,  1400,   916,  1091,     5,   546,   910,   911,   638,   909,
     915,   938,   915,   919,   920,   915,   324,   918,  1043,   426,
     426,   460,  1208,  1228,  1060,   460,  1171,  1202,   430,     5,
     391,     9,   294,   430,   442,  1352,  1353,  1354,  1355,  1356,
    1360,  1364,  1366,  1419,   391,   611,   938,  1322,  1324,  1376,
    1379,  1380,  1326,  1379,     5,   391,  1326,  1352,   366,   453,
     469,   512,   552,   581,   590,  1389,  1389,   430,   430,   430,
     430,   430,   430,   207,   399,  1328,  1330,     5,   391,     5,
     391,   938,  1468,     8,  1427,  1102,   845,     5,  1247,  1248,
     863,  1049,  1416,  1417,  1419,   878,  1387,   878,    26,    26,
     589,    24,    26,   791,   879,  1218,   391,  1218,   792,   391,
    1218,   873,   871,   877,  1218,   875,  1218,  1218,  1218,    25,
      25,    25,   838,   855,   391,    25,   855,   391,   866,     5,
     867,   619,  1247,   576,  1427,  1427,   845,   845,   927,   508,
     845,  1482,     5,    20,  1379,   977,  1427,   619,   938,   738,
     746,   745,   747,   938,   942,   748,   942,   191,   741,   744,
       5,   979,   619,   845,     8,   938,   863,   553,  1288,     5,
     391,  1091,     5,   325,    25,  1230,   930,   344,   344,   458,
     619,   344,   430,   695,   699,   692,  1490,  1490,   724,   720,
     716,  1010,    25,   937,  1070,  1091,  1490,   845,   425,   458,
     863,  1420,  1420,  1385,  1389,   470,  1419,   430,   430,   430,
     430,   430,   430,   430,   938,   430,     5,    18,    19,    20,
      21,    92,    93,    94,    95,    96,    97,  1441,  1466,  1091,
    1114,   967,   962,   963,    26,   679,   938,  1490,  1490,  1490,
    1490,     5,   982,     5,   983,  1490,  1490,  1490,  1490,  1013,
    1490,   937,    25,    14,    14,     5,   391,    26,  1376,  1415,
    1396,   595,   595,  1273,  1401,  1402,  1338,  1317,  1379,   616,
     932,  1352,   430,  1277,   938,  1437,  1436,  1416,    48,    49,
      50,    51,    52,   583,  1453,   845,   845,  1283,   932,  1312,
    1379,  1376,  1310,   619,   619,     5,     5,  1091,   915,  1490,
    1490,     5,   922,   923,  1490,  1490,   921,  1036,   811,   769,
      73,    74,    76,    77,    78,   176,   184,   218,   227,   256,
     257,   301,   343,   399,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,  1205,  1209,   134,   513,  1210,  1226,
    1036,   159,   175,   176,   184,   218,   227,   256,   301,   343,
    1203,  1204,  1216,  1210,  1324,  1333,  1355,   430,  1414,  1352,
    1419,  1414,     6,   391,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   252,   371,   428,   556,   622,  1363,  1365,
    1380,   458,  1378,   391,     5,   619,     5,   391,  1261,   391,
     391,   625,   430,   625,    26,  1374,  1374,    26,  1374,  1374,
      26,  1373,    25,  1382,  1331,  1332,  1333,  1258,  1254,  1427,
       8,   426,   675,     5,   391,   843,   391,     5,   546,  1343,
    1348,   938,   625,   391,    26,   589,   625,   391,   391,   391,
     391,     5,   391,   391,   391,   708,   706,    20,   391,  1427,
       5,   845,   566,   274,   684,   685,   845,    20,   938,   391,
     979,  1490,  1490,     5,   742,   458,   619,     5,   743,  1490,
     739,   546,    20,   938,     5,   938,  1128,   389,   658,   843,
    1289,   896,  1015,   667,  1151,   838,     5,   706,  1091,   691,
     673,   938,  1091,   697,   391,   706,   706,  1490,  1490,  1013,
    1067,    25,  1071,  1091,   571,   892,  1102,   482,   844,  1021,
     625,  1415,   391,   395,  1442,  1469,   359,   475,   585,  1367,
    1419,  1422,  1367,  1367,  1367,  1367,   619,  1422,  1163,  1419,
    1419,  1419,  1419,    62,   542,   968,   954,   955,   619,   930,
    1490,   930,  1490,   679,    26,  1091,    26,  1091,   683,   391,
     430,  1428,  1416,  1398,  1402,  1402,  1394,     5,   391,   470,
    1413,  1278,  1379,   478,  1275,  1413,   625,  1406,    18,    19,
      64,   427,   430,   443,   482,   483,   495,   537,   576,   588,
     600,   601,   608,   611,   938,  1382,  1414,  1458,  1459,  1460,
    1461,  1462,  1463,  1469,  1458,  1458,  1458,  1379,  1455,  1457,
    1454,  1455,  1456,  1451,   553,  1286,     5,   391,   625,   938,
     938,  1400,  1091,   938,  1490,  1490,  1490,  1490,   623,   623,
    1206,  1206,  1206,    25,  1206,  1206,  1206,  1206,  1206,  1206,
      25,    25,  1206,  1209,  1091,  1118,  1119,   618,   446,  1172,
    1490,    25,    25,    26,    26,    26,    26,    26,    25,  1091,
    1204,  1172,   391,   391,  1353,  1354,  1358,  1420,   430,  1414,
    1358,   430,  1414,    10,   249,   386,   388,  1419,    26,  1321,
    1379,    20,   938,  1379,   366,   453,   469,   512,   552,   581,
     590,  1390,    26,  1390,     5,  1371,  1371,     5,   391,   391,
    1371,   391,  1333,  1427,  1248,   268,  1244,  1417,   514,  1344,
    1345,  1346,  1376,  1349,   331,   513,   524,  1293,  1410,   366,
     453,   469,   512,   552,   581,   590,  1388,   878,   589,    24,
      26,   795,   838,   868,   467,   826,     5,   373,  1427,     5,
     430,   391,   550,  1004,   942,  1490,   676,    20,   938,   942,
    1490,  1480,   845,  1480,  1113,  1490,    26,   937,    25,  1231,
    1110,   426,   706,   696,   700,   391,  1490,   937,   845,   890,
     426,  1390,  1416,     5,  1389,   391,     5,  1419,     5,   391,
    1419,  1419,  1419,  1419,   938,   391,   970,   969,   440,   956,
     957,    20,   938,  1429,  1430,   553,  1412,  1397,  1395,  1398,
    1379,  1415,   139,  1318,     5,   391,  1276,  1437,  1412,  1461,
    1461,  1460,   430,   430,   430,   430,   430,   430,   430,   938,
     430,     5,   391,    18,    19,    20,    21,  1441,   391,     5,
     391,     5,    14,   149,   525,  1452,  1287,  1379,   462,  1313,
    1314,  1377,   619,   210,  1044,   807,   781,   538,   587,  1120,
       5,  1118,    61,   133,   199,   201,   216,   224,   228,   253,
    1173,  1174,  1227,  1044,  1217,   441,  1357,  1361,  1362,  1382,
    1469,  1357,  1361,  1358,  1419,     5,   426,  1378,   391,    26,
    1375,   391,   391,    26,   391,   430,  1346,     5,   938,  1381,
     368,  1340,  1350,   938,  1411,   618,  1367,   331,   430,    24,
      26,   391,   930,   679,   373,  1427,   845,   686,   568,  1126,
      26,   679,   426,  1004,   391,   240,   679,   391,   391,   430,
     698,   344,   704,   391,   693,  1066,  1490,   458,  1348,  1389,
     625,  1389,   391,  1419,   391,   391,   391,   391,   845,  1490,
     937,     5,   391,  1113,  1348,  1398,  1398,  1416,  1379,   430,
    1348,   391,  1442,  1367,  1460,  1464,  1367,  1367,  1367,  1367,
     619,  1464,  1459,  1460,  1460,  1460,  1460,  1455,    14,  1456,
    1459,   932,  1352,  1113,     5,   140,  1307,   938,  1119,  1175,
    1176,  1091,  1178,  1091,  1177,  1179,  1174,   239,   239,  1359,
    1382,  1423,     5,   391,   391,  1357,     7,    26,   625,   391,
    1345,  1347,  1345,  1341,  1418,  1419,   447,  1339,  1351,  1244,
      26,  1294,  1295,  1296,  1379,  1408,  1411,    26,   825,  1427,
     392,   203,   259,   284,   293,   329,   337,   431,   602,   683,
     687,   688,   430,   619,   679,  1150,  1232,   701,   391,  1110,
     704,   704,  1490,   891,  1102,   391,   625,  1390,   625,   575,
    1001,  1430,  1410,  1348,   482,  1279,  1280,  1419,  1410,   391,
    1460,     5,   391,  1460,  1460,  1460,  1460,   938,   391,   430,
    1314,  1490,  1490,  1180,  1490,  1181,  1490,  1490,  1362,  1419,
     426,  1390,     5,   391,     5,  1352,     5,   538,   587,  1297,
    1244,   391,   347,   351,   828,   829,   830,  1007,   925,   925,
     925,   925,   925,   925,    25,     5,   391,   845,    20,   938,
    1007,  1154,  1155,  1156,   704,   706,   704,   241,   426,  1390,
    1390,   971,   679,     5,   391,   391,  1460,   391,   391,   391,
     391,  1458,  1490,  1490,  1345,  1418,  1295,   832,   831,   238,
     830,   833,   688,     5,  1157,   282,  1156,   702,  1490,  1280,
     391,  1490,  1490,  1490,   845,  1490,   391,   968,   391,   703,
     162,   344,   705,  1110
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
#line 931 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 934 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 938 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 944 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 949 "fgl.yacc"
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
#line 961 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 966 "fgl.yacc"
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
#line 989 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 990 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 991 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 992 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 993 "fgl.yacc"
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
#line 1007 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 1008 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1009 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1010 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1011 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1016 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1017 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1028 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1031 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1034 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1034 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1041 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1042 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1048 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1049 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1050 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1051 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1052 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1053 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1055 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1056 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1057 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1058 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1059 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1060 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1062 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1063 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 46:
#line 1064 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1071 "fgl.yacc"
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
#line 1082 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1086 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1087 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1091 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1097 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1099 "fgl.yacc"
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
#line 1110 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1112 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1114 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1116 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1120 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1122 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1183 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1187 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1191 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1198 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 66:
#line 1201 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1205 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1209 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1216 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1222 "fgl.yacc"
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
#line 1231 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1235 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1240 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1244 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1252 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1256 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1260 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1262 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1268 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1273 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1276 "fgl.yacc"
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
#line 1292 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1299 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1303 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1307 "fgl.yacc"
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
#line 1329 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1329 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1333 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1334 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1335 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1340 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1343 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1349 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1352 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1364 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1370 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1373 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1388 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1398 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1404 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1413 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1426 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1429 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1431 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1437 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1439 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1444 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1449 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1455 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1459 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1474 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1477 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1480 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1483 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1486 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1489 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1511 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1520 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1530 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1544 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1548 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1551 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1559 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1565 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1580 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1584 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1589 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1599 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1602 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1606 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1608 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1611 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1613 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1616 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1618 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1621 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1624 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1634 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1635 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1643 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1644 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1661 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1664 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1667 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1670 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1673 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1676 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1685 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1693 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1698 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1711 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1715 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1730 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1731 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1739 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1739 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1749 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1749 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1758 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1759 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1760 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1763 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1768 "fgl.yacc"
    { }
    break;

  case 194:
#line 1768 "fgl.yacc"
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
#line 1785 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1789 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1803 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1812 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 207:
#line 1816 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 213:
#line 1832 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 214:
#line 1834 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 215:
#line 1835 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 217:
#line 1842 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 218:
#line 1842 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 219:
#line 1843 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 220:
#line 1844 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 221:
#line 1847 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 222:
#line 1849 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 224:
#line 1859 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 229:
#line 1874 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 230:
#line 1874 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 234:
#line 1880 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 235:
#line 1881 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 236:
#line 1888 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 237:
#line 1889 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 238:
#line 1890 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 239:
#line 1891 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 240:
#line 1894 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 241:
#line 1895 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1896 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 243:
#line 1897 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 244:
#line 1901 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1906 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 246:
#line 1911 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1915 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1918 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 249:
#line 1922 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 250:
#line 1923 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 251:
#line 1924 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 252:
#line 1925 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1926 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 254:
#line 1927 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1928 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 256:
#line 1929 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 257:
#line 1932 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 258:
#line 1933 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 259:
#line 1934 "fgl.yacc"
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
#line 1966 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 261:
#line 1970 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1972 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 263:
#line 1974 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 264:
#line 1976 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 265:
#line 1981 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 266:
#line 1985 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 267:
#line 1985 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1989 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 269:
#line 1990 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 270:
#line 1991 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 271:
#line 1992 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 272:
#line 1993 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 273:
#line 1994 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 274:
#line 1996 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 275:
#line 2001 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 276:
#line 2001 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 277:
#line 2004 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 278:
#line 2006 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 279:
#line 2012 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 280:
#line 2014 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 281:
#line 2020 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 282:
#line 2028 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 283:
#line 2028 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 284:
#line 2031 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 285:
#line 2032 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2033 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 287:
#line 2034 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 288:
#line 2035 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 289:
#line 2036 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 290:
#line 2038 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 294:
#line 2059 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 298:
#line 2068 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 299:
#line 2070 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2072 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 301:
#line 2074 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 302:
#line 2075 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 303:
#line 2076 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 304:
#line 2077 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 305:
#line 2078 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2083 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2090 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 308:
#line 2095 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2097 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2099 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 311:
#line 2100 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 312:
#line 2101 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 313:
#line 2102 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 314:
#line 2103 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 315:
#line 2104 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 316:
#line 2105 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 317:
#line 2108 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 318:
#line 2110 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 319:
#line 2116 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 320:
#line 2124 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2132 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 323:
#line 2136 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 324:
#line 2144 "fgl.yacc"
    {dim_push_record();}
    break;

  case 325:
#line 2145 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 326:
#line 2146 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 327:
#line 2147 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 333:
#line 2166 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 334:
#line 2178 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 335:
#line 2182 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 336:
#line 2185 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 337:
#line 2188 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 338:
#line 2189 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 339:
#line 2190 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 340:
#line 2191 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 341:
#line 2192 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 342:
#line 2198 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 343:
#line 2205 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 344:
#line 2210 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 345:
#line 2215 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 346:
#line 2219 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 347:
#line 2222 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 348:
#line 2230 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 349:
#line 2232 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 350:
#line 2237 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 355:
#line 2249 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 356:
#line 2252 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 357:
#line 2255 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 358:
#line 2258 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 359:
#line 2261 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 360:
#line 2264 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 361:
#line 2277 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 362:
#line 2280 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 363:
#line 2295 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 364:
#line 2297 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 365:
#line 2299 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 366:
#line 2301 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 367:
#line 2303 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 368:
#line 2305 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 369:
#line 2306 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 370:
#line 2313 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 371:
#line 2315 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 372:
#line 2319 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 373:
#line 2321 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2323 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 375:
#line 2325 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2327 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2329 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2331 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 379:
#line 2337 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 380:
#line 2351 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 381:
#line 2354 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 386:
#line 2371 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 389:
#line 2377 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 390:
#line 2381 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 391:
#line 2386 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 395:
#line 2396 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 396:
#line 2397 "fgl.yacc"
    {inc_counter();}
    break;

  case 402:
#line 2403 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 403:
#line 2410 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 404:
#line 2410 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 406:
#line 2415 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 407:
#line 2419 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2425 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2433 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 410:
#line 2439 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 411:
#line 2448 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 412:
#line 2450 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 413:
#line 2457 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 414:
#line 2465 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 415:
#line 2469 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 416:
#line 2478 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 417:
#line 2483 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 418:
#line 2488 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 419:
#line 2492 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 420:
#line 2494 "fgl.yacc"
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
#line 2504 "fgl.yacc"
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
#line 2518 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 423:
#line 2526 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2538 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 425:
#line 2544 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 426:
#line 2550 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 429:
#line 2560 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 430:
#line 2566 "fgl.yacc"
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
#line 2638 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 432:
#line 2644 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 433:
#line 2648 "fgl.yacc"
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
#line 2656 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 435:
#line 2656 "fgl.yacc"
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
#line 2672 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 437:
#line 2676 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 438:
#line 2682 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 439:
#line 2685 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 440:
#line 2693 "fgl.yacc"
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
#line 2704 "fgl.yacc"
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
#line 2714 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 443:
#line 2720 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 444:
#line 2730 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 445:
#line 2735 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 446:
#line 2742 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 447:
#line 2745 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 448:
#line 2748 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 449:
#line 2753 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 450:
#line 2760 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 451:
#line 2765 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 452:
#line 2770 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 453:
#line 2775 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 454:
#line 2786 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 455:
#line 2794 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 456:
#line 2802 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 457:
#line 2807 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 458:
#line 2811 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 459:
#line 2816 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 460:
#line 2820 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 461:
#line 2824 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 462:
#line 2830 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 463:
#line 2833 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 464:
#line 2837 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 465:
#line 2841 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 466:
#line 2845 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 467:
#line 2849 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 468:
#line 2853 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 469:
#line 2860 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 470:
#line 2870 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 471:
#line 2875 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 472:
#line 2881 "fgl.yacc"
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
#line 2891 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 474:
#line 2896 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 475:
#line 2899 "fgl.yacc"
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
#line 2913 "fgl.yacc"
    {chk4var=1;}
    break;

  case 477:
#line 2913 "fgl.yacc"
    {chk4var=0;}
    break;

  case 478:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 479:
#line 2916 "fgl.yacc"
    {chk4var=1;}
    break;

  case 480:
#line 2916 "fgl.yacc"
    {chk4var=0;}
    break;

  case 481:
#line 2916 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 482:
#line 2920 "fgl.yacc"
    {chk4var=1;}
    break;

  case 483:
#line 2920 "fgl.yacc"
    {chk4var=0;}
    break;

  case 484:
#line 2920 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 485:
#line 2924 "fgl.yacc"
    {chk4var=1;}
    break;

  case 486:
#line 2924 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2924 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 488:
#line 2928 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2934 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2940 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 491:
#line 2946 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 492:
#line 2956 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 493:
#line 2957 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 496:
#line 2965 "fgl.yacc"
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
#line 2976 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 498:
#line 2977 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 499:
#line 2983 "fgl.yacc"
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
#line 2994 "fgl.yacc"
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
#line 3004 "fgl.yacc"
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
#line 3017 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 505:
#line 3022 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 506:
#line 3029 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 507:
#line 3033 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 508:
#line 3036 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 509:
#line 3039 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 510:
#line 3045 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3048 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 512:
#line 3051 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 513:
#line 3068 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 514:
#line 3071 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 515:
#line 3077 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 516:
#line 3078 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3079 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 519:
#line 3084 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 520:
#line 3085 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3086 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3087 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3089 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3090 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3091 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 526:
#line 3093 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 527:
#line 3094 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 529:
#line 3100 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3105 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 532:
#line 3117 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 533:
#line 3121 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 534:
#line 3122 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 535:
#line 3129 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 537:
#line 3146 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 538:
#line 3150 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 539:
#line 3156 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 540:
#line 3160 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 541:
#line 3169 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 542:
#line 3170 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 543:
#line 3182 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 544:
#line 3188 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 545:
#line 3196 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 552:
#line 3213 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 553:
#line 3215 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3218 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 555:
#line 3220 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3234 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 561:
#line 3236 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 562:
#line 3239 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 563:
#line 3241 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 576:
#line 3272 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 577:
#line 3274 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3277 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 579:
#line 3279 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3282 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 581:
#line 3284 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3287 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 583:
#line 3289 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3292 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 585:
#line 3294 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 586:
#line 3309 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 587:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 588:
#line 3326 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 589:
#line 3327 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 590:
#line 3328 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 591:
#line 3329 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3330 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 596:
#line 3338 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 598:
#line 3344 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 599:
#line 3346 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 600:
#line 3347 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 601:
#line 3349 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 602:
#line 3351 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 603:
#line 3353 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3355 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 605:
#line 3357 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 606:
#line 3360 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 607:
#line 3367 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 608:
#line 3369 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3375 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3380 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 611:
#line 3385 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 612:
#line 3390 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 613:
#line 3390 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 614:
#line 3393 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 615:
#line 3399 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 616:
#line 3404 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 617:
#line 3408 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 620:
#line 3416 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 621:
#line 3418 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 622:
#line 3420 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 623:
#line 3422 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3424 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 625:
#line 3426 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 626:
#line 3429 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 628:
#line 3438 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 629:
#line 3500 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 630:
#line 3513 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 632:
#line 3520 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 633:
#line 3523 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 634:
#line 3529 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 635:
#line 3535 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3539 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 637:
#line 3543 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 638:
#line 3549 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3553 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 640:
#line 3557 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 641:
#line 3562 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 642:
#line 3567 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 661:
#line 3608 "fgl.yacc"
    {
		lines_printed_true=lines_printed;
		print_if_start();
	}
    break;

  case 662:
#line 3612 "fgl.yacc"
    {
		int a;
		a=lines_printed;
		lines_printed_true=lines_printed-lines_printed_true;

		lines_printed=lines_printed-lines_printed_true; /* reset it back.. */
		lines_printed_false=lines_printed;
	}
    break;

  case 663:
#line 3619 "fgl.yacc"
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

  case 665:
#line 3634 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 667:
#line 3637 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 668:
#line 3639 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 669:
#line 3642 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 670:
#line 3646 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 671:
#line 3649 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 672:
#line 3655 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 673:
#line 3666 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 674:
#line 3667 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 675:
#line 3670 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 677:
#line 3676 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 678:
#line 3680 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 679:
#line 3681 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 682:
#line 3695 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 683:
#line 3697 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 686:
#line 3706 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 687:
#line 3708 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 688:
#line 3712 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 689:
#line 3714 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 690:
#line 3717 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 691:
#line 3719 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 692:
#line 3722 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 693:
#line 3725 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 694:
#line 3728 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 695:
#line 3730 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 696:
#line 3733 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 697:
#line 3735 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 698:
#line 3738 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 699:
#line 3740 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 700:
#line 3743 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 701:
#line 3745 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 702:
#line 3746 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 703:
#line 3748 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 704:
#line 3749 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 705:
#line 3751 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 706:
#line 3752 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 707:
#line 3754 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 708:
#line 3794 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 709:
#line 3795 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 710:
#line 3803 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 711:
#line 3804 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 712:
#line 3813 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 713:
#line 3818 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 714:
#line 3823 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 715:
#line 3824 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 717:
#line 3829 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 718:
#line 3832 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 719:
#line 3840 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 720:
#line 3845 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 721:
#line 3849 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 722:
#line 3856 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 723:
#line 3865 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 724:
#line 3871 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 725:
#line 3872 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 726:
#line 3873 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 727:
#line 3874 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 728:
#line 3877 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 730:
#line 3880 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 731:
#line 3887 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3888 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3889 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 734:
#line 3890 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 735:
#line 3891 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 736:
#line 3892 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 737:
#line 3893 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 738:
#line 3894 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 739:
#line 3895 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 740:
#line 3900 "fgl.yacc"
    {iskey=1;}
    break;

  case 741:
#line 3900 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 742:
#line 3902 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 743:
#line 3905 "fgl.yacc"
    {iskey=1;}
    break;

  case 744:
#line 3905 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 745:
#line 3907 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 746:
#line 3911 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 747:
#line 3914 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 748:
#line 3915 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 750:
#line 3918 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 756:
#line 3930 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 757:
#line 3931 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 758:
#line 3932 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 759:
#line 3933 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 760:
#line 3934 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 761:
#line 3935 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 762:
#line 3936 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 763:
#line 3937 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 764:
#line 3938 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 765:
#line 3939 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 766:
#line 3940 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 767:
#line 3941 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 768:
#line 3942 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 769:
#line 3946 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 770:
#line 3964 "fgl.yacc"
    {chk4var=1;}
    break;

  case 771:
#line 3964 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 772:
#line 3967 "fgl.yacc"
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

  case 773:
#line 3991 "fgl.yacc"
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

  case 775:
#line 4009 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 4015 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 777:
#line 4021 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 778:
#line 4027 "fgl.yacc"
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

  case 779:
#line 4038 "fgl.yacc"
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

  case 780:
#line 4061 "fgl.yacc"
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

  case 783:
#line 4077 "fgl.yacc"
    {
	}
    break;

  case 790:
#line 4100 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 794:
#line 4108 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 812:
#line 4134 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 813:
#line 4135 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 814:
#line 4143 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 815:
#line 4148 "fgl.yacc"
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

  case 816:
#line 4164 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 817:
#line 4170 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 819:
#line 4185 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 820:
#line 4198 "fgl.yacc"
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

  case 821:
#line 4208 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 822:
#line 4215 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 823:
#line 4222 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 824:
#line 4228 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 825:
#line 4228 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 826:
#line 4233 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 827:
#line 4239 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 828:
#line 4247 "fgl.yacc"
    {
}
    break;

  case 834:
#line 4259 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 836:
#line 4267 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 837:
#line 4273 "fgl.yacc"
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

  case 838:
#line 4287 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 839:
#line 4291 "fgl.yacc"
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

  case 840:
#line 4304 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 842:
#line 4322 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 843:
#line 4330 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 844:
#line 4336 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 845:
#line 4347 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 846:
#line 4351 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 847:
#line 4358 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 848:
#line 4365 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 849:
#line 4371 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 850:
#line 4376 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 853:
#line 4383 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 854:
#line 4384 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 855:
#line 4386 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 856:
#line 4387 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 857:
#line 4390 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 858:
#line 4391 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 859:
#line 4392 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 860:
#line 4394 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 861:
#line 4399 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 862:
#line 4404 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 863:
#line 4411 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 867:
#line 4418 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 868:
#line 4420 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 869:
#line 4422 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 870:
#line 4431 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 871:
#line 4437 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 872:
#line 4441 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 875:
#line 4453 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 876:
#line 4458 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 877:
#line 4463 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 878:
#line 4466 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 880:
#line 4478 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 881:
#line 4481 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 882:
#line 4484 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 889:
#line 4500 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 890:
#line 4505 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 891:
#line 4505 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 892:
#line 4508 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 893:
#line 4535 "fgl.yacc"
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

  case 895:
#line 4593 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 897:
#line 4600 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 898:
#line 4604 "fgl.yacc"
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

  case 899:
#line 4647 "fgl.yacc"
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

  case 903:
#line 4695 "fgl.yacc"
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

  case 904:
#line 4709 "fgl.yacc"
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

  case 909:
#line 4733 "fgl.yacc"
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

  case 910:
#line 4793 "fgl.yacc"
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

  case 911:
#line 4849 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 912:
#line 4854 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 913:
#line 4862 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 914:
#line 4867 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 915:
#line 4875 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 916:
#line 4881 "fgl.yacc"
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

  case 917:
#line 4914 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 918:
#line 4917 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 919:
#line 4919 "fgl.yacc"
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

  case 920:
#line 4960 "fgl.yacc"
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

  case 925:
#line 5013 "fgl.yacc"
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

  case 926:
#line 5065 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 928:
#line 5072 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 929:
#line 5078 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 930:
#line 5089 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 931:
#line 5096 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 933:
#line 5104 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 934:
#line 5107 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 935:
#line 5108 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 937:
#line 5110 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 938:
#line 5111 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 939:
#line 5114 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 940:
#line 5117 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 941:
#line 5123 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 942:
#line 5126 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 943:
#line 5130 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 944:
#line 5134 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 945:
#line 5141 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 946:
#line 5146 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 947:
#line 5153 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 948:
#line 5156 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5169 "fgl.yacc"
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

  case 954:
#line 5188 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5195 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 956:
#line 5202 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 957:
#line 5205 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 958:
#line 5219 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 963:
#line 5236 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 964:
#line 5241 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 965:
#line 5247 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 967:
#line 5254 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 968:
#line 5259 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 969:
#line 5262 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 970:
#line 5263 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 971:
#line 5266 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 972:
#line 5267 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 973:
#line 5270 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 974:
#line 5271 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 975:
#line 5276 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 976:
#line 5283 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 977:
#line 5286 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 978:
#line 5292 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 979:
#line 5294 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 980:
#line 5296 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 981:
#line 5298 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 982:
#line 5301 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 983:
#line 5301 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 984:
#line 5302 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 985:
#line 5307 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 986:
#line 5315 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 987:
#line 5316 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 988:
#line 5321 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 989:
#line 5323 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 990:
#line 5325 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 994:
#line 5342 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 995:
#line 5345 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 996:
#line 5348 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 997:
#line 5351 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 998:
#line 5355 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 999:
#line 5358 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1000:
#line 5361 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5365 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1002:
#line 5369 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1003:
#line 5373 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1004:
#line 5376 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1005:
#line 5380 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1006:
#line 5383 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1007:
#line 5384 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1008:
#line 5385 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1009:
#line 5388 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1010:
#line 5391 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1011:
#line 5394 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1012:
#line 5397 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1013:
#line 5400 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1014:
#line 5403 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1015:
#line 5406 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1016:
#line 5423 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1019:
#line 5433 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1020:
#line 5440 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1022:
#line 5461 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1023:
#line 5466 "fgl.yacc"
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

  case 1024:
#line 5478 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1025:
#line 5479 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1026:
#line 5483 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1027:
#line 5488 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1028:
#line 5489 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1029:
#line 5493 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1033:
#line 5499 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1034:
#line 5501 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1036:
#line 5516 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1037:
#line 5520 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1038:
#line 5526 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1039:
#line 5527 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1040:
#line 5530 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1041:
#line 5531 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1042:
#line 5534 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1044:
#line 5553 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1045:
#line 5558 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1046:
#line 5563 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1047:
#line 5568 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1053:
#line 5590 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1054:
#line 5597 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1055:
#line 5606 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1056:
#line 5612 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1057:
#line 5614 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1061:
#line 5625 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1062:
#line 5626 "fgl.yacc"
    {
rep_struct.lines_in_first_header=lines_printed;
pdf_rep_struct.lines_in_first_header=lines_printed;
print_rep_ret(0);}
    break;

  case 1063:
#line 5631 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1064:
#line 5632 "fgl.yacc"
    {
rep_struct.lines_in_trailer=lines_printed;
pdf_rep_struct.lines_in_trailer=lines_printed;
print_rep_ret(0);}
    break;

  case 1065:
#line 5637 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1066:
#line 5638 "fgl.yacc"
    {
rep_struct.lines_in_header=lines_printed;
pdf_rep_struct.lines_in_header=lines_printed;
print_rep_ret(0);}
    break;

  case 1067:
#line 5643 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1068:
#line 5644 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1069:
#line 5646 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1070:
#line 5647 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1071:
#line 5648 "fgl.yacc"
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

  case 1072:
#line 5662 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1073:
#line 5664 "fgl.yacc"
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

  case 1074:
#line 5681 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1081:
#line 5693 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1082:
#line 5693 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1083:
#line 5699 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1084:
#line 5699 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1085:
#line 5702 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1086:
#line 5702 "fgl.yacc"
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

  case 1087:
#line 5715 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1088:
#line 5716 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1089:
#line 5717 "fgl.yacc"
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

  case 1090:
#line 5726 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1091:
#line 5738 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1097:
#line 5749 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1098:
#line 5754 "fgl.yacc"
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

  case 1099:
#line 5769 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1100:
#line 5774 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1101:
#line 5780 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1102:
#line 5781 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1103:
#line 5782 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1104:
#line 5786 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1105:
#line 5787 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1106:
#line 5788 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1107:
#line 5789 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1108:
#line 5793 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1109:
#line 5803 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1110:
#line 5805 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1111:
#line 5810 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1112:
#line 5813 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1113:
#line 5818 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1114:
#line 5825 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1115:
#line 5832 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1116:
#line 5839 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1117:
#line 5848 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1118:
#line 5855 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1119:
#line 5862 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1120:
#line 5869 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1121:
#line 5876 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1126:
#line 5889 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5890 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1128:
#line 5891 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1129:
#line 5892 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1130:
#line 5893 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1131:
#line 5894 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1132:
#line 5895 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1133:
#line 5896 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1134:
#line 5897 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1135:
#line 5898 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1138:
#line 5904 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1139:
#line 5905 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1140:
#line 5906 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1141:
#line 5907 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1146:
#line 5916 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1147:
#line 5917 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5918 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1149:
#line 5919 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1150:
#line 5920 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1151:
#line 5921 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1152:
#line 5922 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1153:
#line 5923 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1154:
#line 5925 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1155:
#line 5926 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1156:
#line 5927 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1157:
#line 5928 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1158:
#line 5930 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1159:
#line 5931 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1160:
#line 5932 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1161:
#line 5933 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1165:
#line 5938 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1166:
#line 5939 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1170:
#line 5946 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1171:
#line 5954 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1172:
#line 5962 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1173:
#line 5974 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1174:
#line 5983 "fgl.yacc"
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

  case 1175:
#line 5994 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1176:
#line 5998 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1177:
#line 6002 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1178:
#line 6008 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1179:
#line 6013 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1180:
#line 6021 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1181:
#line 6024 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1182:
#line 6033 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1183:
#line 6044 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1185:
#line 6051 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1186:
#line 6059 "fgl.yacc"
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

  case 1187:
#line 6069 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1188:
#line 6072 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1189:
#line 6076 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1190:
#line 6084 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1191:
#line 6087 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1192:
#line 6093 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1193:
#line 6097 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1194:
#line 6101 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1195:
#line 6105 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1196:
#line 6109 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1197:
#line 6115 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1198:
#line 6116 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1199:
#line 6117 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1200:
#line 6118 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1201:
#line 6123 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1202:
#line 6125 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1203:
#line 6128 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1204:
#line 6132 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1205:
#line 6135 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1206:
#line 6142 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1207:
#line 6147 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1208:
#line 6148 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1209:
#line 6149 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1210:
#line 6154 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1211:
#line 6155 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1212:
#line 6161 "fgl.yacc"
    {insql=1;}
    break;

  case 1213:
#line 6161 "fgl.yacc"
    {insql=0;}
    break;

  case 1214:
#line 6161 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1215:
#line 6166 "fgl.yacc"
    {insql=1;}
    break;

  case 1216:
#line 6166 "fgl.yacc"
    {insql=0;}
    break;

  case 1217:
#line 6166 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1218:
#line 6177 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1219:
#line 6178 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1220:
#line 6184 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1221:
#line 6186 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1223:
#line 6199 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1224:
#line 6203 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1225:
#line 6204 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1227:
#line 6209 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1228:
#line 6212 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1229:
#line 6218 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1230:
#line 6221 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1231:
#line 6229 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1233:
#line 6236 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1234:
#line 6243 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1235:
#line 6246 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1236:
#line 6255 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1237:
#line 6258 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6261 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6264 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1240:
#line 6267 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1241:
#line 6270 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1242:
#line 6273 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1243:
#line 6280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1244:
#line 6283 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1245:
#line 6290 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1246:
#line 6293 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1247:
#line 6299 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6302 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1249:
#line 6309 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1250:
#line 6312 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1252:
#line 6320 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1254:
#line 6329 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1255:
#line 6332 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1256:
#line 6338 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1257:
#line 6341 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1258:
#line 6347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 6354 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1260:
#line 6355 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1261:
#line 6359 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1262:
#line 6365 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1263:
#line 6368 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1265:
#line 6376 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1266:
#line 6383 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1267:
#line 6386 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1271:
#line 6404 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1277:
#line 6410 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1278:
#line 6413 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1279:
#line 6416 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1280:
#line 6422 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1282:
#line 6428 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1284:
#line 6439 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1285:
#line 6453 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1286:
#line 6462 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1287:
#line 6462 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1288:
#line 6467 "fgl.yacc"
    {insql=1;}
    break;

  case 1289:
#line 6467 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1290:
#line 6472 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1291:
#line 6475 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1292:
#line 6477 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6484 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1295:
#line 6488 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1296:
#line 6492 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1297:
#line 6499 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1298:
#line 6502 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1299:
#line 6509 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1300:
#line 6513 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1301:
#line 6517 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1302:
#line 6522 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1303:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1304:
#line 6531 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1305:
#line 6537 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1306:
#line 6541 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1307:
#line 6547 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1308:
#line 6554 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1309:
#line 6558 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1310:
#line 6563 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1311:
#line 6573 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1312:
#line 6576 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1313:
#line 6578 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6580 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1315:
#line 6582 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1316:
#line 6584 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1317:
#line 6586 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1318:
#line 6588 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1319:
#line 6594 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1320:
#line 6604 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1321:
#line 6611 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1323:
#line 6617 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1327:
#line 6626 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1330:
#line 6631 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1331:
#line 6636 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1332:
#line 6643 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1333:
#line 6644 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1334:
#line 6651 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1335:
#line 6662 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1336:
#line 6663 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1337:
#line 6666 "fgl.yacc"
    {insql=1;}
    break;

  case 1338:
#line 6666 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1339:
#line 6671 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1340:
#line 6676 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1342:
#line 6682 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1344:
#line 6686 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1345:
#line 6691 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1346:
#line 6696 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1347:
#line 6700 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1349:
#line 6706 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1350:
#line 6710 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1351:
#line 6718 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1352:
#line 6721 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1353:
#line 6723 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1354:
#line 6728 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1357:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1361:
#line 6742 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1362:
#line 6745 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1363:
#line 6747 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6753 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6759 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6769 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1371:
#line 6774 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1372:
#line 6776 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6782 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6785 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1377:
#line 6791 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1378:
#line 6799 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6804 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6814 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1384:
#line 6820 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6826 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6828 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6834 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6839 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1390:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1391:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1392:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6855 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1394:
#line 6868 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1395:
#line 6873 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1397:
#line 6877 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1398:
#line 6879 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1399:
#line 6886 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1400:
#line 6889 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1401:
#line 6895 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1402:
#line 6899 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1403:
#line 6903 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1404:
#line 6907 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1405:
#line 6910 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1406:
#line 6918 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1407:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1410:
#line 6934 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6940 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6943 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1413:
#line 6954 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6961 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1415:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1416:
#line 6970 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1417:
#line 6977 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1418:
#line 6984 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1420:
#line 6991 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1421:
#line 6997 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1422:
#line 6998 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6999 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1425:
#line 7003 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 7008 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1428:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7020 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1430:
#line 7021 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1431:
#line 7024 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1432:
#line 7027 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1433:
#line 7032 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1434:
#line 7033 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1435:
#line 7038 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 7041 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1437:
#line 7047 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1438:
#line 7050 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1439:
#line 7056 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1440:
#line 7059 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1441:
#line 7065 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1442:
#line 7068 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1443:
#line 7075 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1444:
#line 7076 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1445:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1446:
#line 7107 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1447:
#line 7111 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1449:
#line 7124 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1450:
#line 7127 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1451:
#line 7130 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1452:
#line 7133 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 7141 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 7144 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1457:
#line 7150 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1459:
#line 7156 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1460:
#line 7159 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1461:
#line 7162 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1462:
#line 7165 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1463:
#line 7168 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1464:
#line 7171 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1465:
#line 7174 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1467:
#line 7181 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1472:
#line 7188 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1473:
#line 7189 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1474:
#line 7194 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1475:
#line 7197 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1476:
#line 7201 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1477:
#line 7207 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1478:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1479:
#line 7209 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1480:
#line 7210 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1485:
#line 7230 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1486:
#line 7235 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1487:
#line 7236 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1489:
#line 7239 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1493:
#line 7244 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1495:
#line 7247 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1497:
#line 7250 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7255 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7257 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7260 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1504:
#line 7261 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1505:
#line 7268 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7273 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1513:
#line 7289 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1514:
#line 7290 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1515:
#line 7294 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1516:
#line 7295 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1518:
#line 7314 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1519:
#line 7315 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1520:
#line 7316 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1521:
#line 7320 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1522:
#line 7323 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1523:
#line 7329 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1524:
#line 7334 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1525:
#line 7339 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1527:
#line 7350 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1532:
#line 7365 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1533:
#line 7368 "fgl.yacc"
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

  case 1534:
#line 7381 "fgl.yacc"
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

  case 1535:
#line 7396 "fgl.yacc"
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

  case 1536:
#line 7408 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1537:
#line 7410 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1538:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1539:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1540:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1541:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1542:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1543:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1544:
#line 7414 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1545:
#line 7417 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1546:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1547:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1548:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1549:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1550:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1551:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1552:
#line 7424 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1553:
#line 7427 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1568:
#line 7436 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1569:
#line 7437 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1570:
#line 7441 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1571:
#line 7449 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1572:
#line 7449 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1573:
#line 7455 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1574:
#line 7455 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1575:
#line 7462 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1576:
#line 7462 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1577:
#line 7468 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1578:
#line 7468 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1579:
#line 7476 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1580:
#line 7477 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1581:
#line 7478 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1585:
#line 7485 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1586:
#line 7486 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7491 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1588:
#line 7494 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1589:
#line 7500 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1590:
#line 7505 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1591:
#line 7514 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1592:
#line 7526 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1593:
#line 7527 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1594:
#line 7530 "fgl.yacc"
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

  case 1595:
#line 7545 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1596:
#line 7555 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1597:
#line 7558 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1598:
#line 7566 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1599:
#line 7575 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1600:
#line 7578 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1601:
#line 7582 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1602:
#line 7585 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1603:
#line 7586 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1605:
#line 7595 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1606:
#line 7596 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1607:
#line 7605 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1608:
#line 7614 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1609:
#line 7619 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1610:
#line 7620 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1611:
#line 7621 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1612:
#line 7622 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1613:
#line 7629 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1614:
#line 7632 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1615:
#line 7638 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1616:
#line 7641 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1617:
#line 7651 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1618:
#line 7660 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7663 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1620:
#line 7666 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1621:
#line 7672 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1622:
#line 7678 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1623:
#line 7681 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1624:
#line 7684 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1625:
#line 7687 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1626:
#line 7694 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7696 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1628:
#line 7698 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1629:
#line 7700 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1630:
#line 7702 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1631:
#line 7703 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1632:
#line 7704 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1633:
#line 7705 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1634:
#line 7706 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1635:
#line 7707 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1636:
#line 7708 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1637:
#line 7710 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7712 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7714 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7716 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7718 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7720 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1643:
#line 7722 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1644:
#line 7723 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1645:
#line 7725 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1646:
#line 7729 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1647:
#line 7730 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1649:
#line 7740 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1650:
#line 7749 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1651:
#line 7753 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1652:
#line 7760 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1653:
#line 7760 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1655:
#line 7764 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1656:
#line 7769 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1657:
#line 7769 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1659:
#line 7773 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1660:
#line 7777 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1663:
#line 7786 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1664:
#line 7786 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1669:
#line 7805 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1670:
#line 7806 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1673:
#line 7814 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1674:
#line 7820 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1677:
#line 7839 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1678:
#line 7840 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1679:
#line 7841 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1680:
#line 7842 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1681:
#line 7843 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1682:
#line 7844 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1683:
#line 7848 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1684:
#line 7849 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1685:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1686:
#line 7854 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1687:
#line 7858 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1689:
#line 7867 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1691:
#line 7872 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1692:
#line 7873 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1693:
#line 7877 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1694:
#line 7883 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1695:
#line 7970 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1696:
#line 7974 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1697:
#line 7976 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1698:
#line 7983 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1699:
#line 7987 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1700:
#line 7993 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1701:
#line 8001 "fgl.yacc"
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

  case 1702:
#line 8011 "fgl.yacc"
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
#line 8021 "fgl.yacc"
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

  case 1704:
#line 8033 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1705:
#line 8036 "fgl.yacc"
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
#line 8055 "fgl.yacc"
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

  case 1707:
#line 8081 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1708:
#line 8084 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1710:
#line 8093 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1711:
#line 8098 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1712:
#line 8101 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1713:
#line 8109 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1714:
#line 8117 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1715:
#line 8130 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1716:
#line 8133 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1717:
#line 8141 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1718:
#line 8144 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1719:
#line 8147 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1720:
#line 8155 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1721:
#line 8159 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1722:
#line 8162 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1723:
#line 8165 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1724:
#line 8168 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1725:
#line 8172 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1726:
#line 8173 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1727:
#line 8174 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1728:
#line 8175 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1729:
#line 8176 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1730:
#line 8182 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8183 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1732:
#line 8184 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1733:
#line 8185 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1734:
#line 8186 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1735:
#line 8187 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1736:
#line 8188 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1737:
#line 8189 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1738:
#line 8190 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1739:
#line 8191 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1740:
#line 8192 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1741:
#line 8193 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1742:
#line 8194 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1743:
#line 8195 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1744:
#line 8199 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1745:
#line 8205 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1746:
#line 8206 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1747:
#line 8219 "fgl.yacc"
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

  case 1748:
#line 8239 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1752:
#line 8245 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1753:
#line 8246 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1757:
#line 8258 "fgl.yacc"
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

  case 1758:
#line 8284 "fgl.yacc"
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

  case 1759:
#line 8335 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1760:
#line 8337 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 8339 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 8340 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1763:
#line 8345 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1764:
#line 8350 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8351 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1766:
#line 8355 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1767:
#line 8357 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1768:
#line 8359 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1769:
#line 8362 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1770:
#line 8366 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1771:
#line 8371 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1772:
#line 8376 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1773:
#line 8380 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1775:
#line 8390 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1777:
#line 8405 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1778:
#line 8408 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1779:
#line 8412 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1782:
#line 8431 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1783:
#line 8432 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1784:
#line 8435 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1785:
#line 8436 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1786:
#line 8437 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1787:
#line 8438 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1788:
#line 8439 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1789:
#line 8440 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1790:
#line 8441 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1791:
#line 8446 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1792:
#line 8447 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1793:
#line 8451 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1794:
#line 8455 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1795:
#line 8459 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1796:
#line 8463 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1797:
#line 8468 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1798:
#line 8472 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1799:
#line 8477 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1801:
#line 8485 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1803:
#line 8491 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1804:
#line 8497 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1805:
#line 8501 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1810:
#line 8519 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1811:
#line 8526 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1812:
#line 8535 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1813:
#line 8535 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17245 "y.tab.c"

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


#line 8630 "fgl.yacc"

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



