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
#line 1574 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1586 "y.tab.c"

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
#define YYLAST   8379

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  667
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  826
/* YYNRULES -- Number of rules. */
#define YYNRULES  1895
/* YYNRULES -- Number of states. */
#define YYNSTATES  3160

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
    2983,  2985,  2986,  2997,  3003,  3004,  3006,  3007,  3010,  3012,
    3015,  3016,  3020,  3022,  3023,  3028,  3029,  3032,  3034,  3038,
    3040,  3042,  3046,  3051,  3056,  3059,  3061,  3063,  3065,  3066,
    3068,  3076,  3079,  3082,  3085,  3088,  3091,  3093,  3096,  3097,
    3101,  3102,  3106,  3107,  3111,  3112,  3116,  3117,  3121,  3122,
    3127,  3128,  3133,  3135,  3137,  3139,  3141,  3143,  3145,  3146,
    3151,  3152,  3154,  3155,  3160,  3162,  3165,  3168,  3171,  3172,
    3174,  3176,  3179,  3182,  3183,  3186,  3190,  3194,  3200,  3201,
    3204,  3209,  3211,  3213,  3215,  3217,  3219,  3220,  3222,  3224,
    3228,  3231,  3237,  3240,  3246,  3252,  3258,  3264,  3270,  3276,
    3277,  3280,  3282,  3285,  3288,  3291,  3294,  3297,  3300,  3302,
    3305,  3308,  3311,  3314,  3316,  3319,  3322,  3325,  3328,  3330,
    3332,  3334,  3335,  3338,  3341,  3344,  3347,  3350,  3353,  3356,
    3359,  3362,  3364,  3366,  3368,  3370,  3372,  3374,  3376,  3378,
    3381,  3384,  3387,  3390,  3393,  3395,  3397,  3399,  3400,  3404,
    3407,  3408,  3409,  3410,  3411,  3412,  3413,  3429,  3430,  3433,
    3436,  3437,  3439,  3440,  3441,  3442,  3443,  3444,  3445,  3461,
    3464,  3465,  3466,  3467,  3478,  3479,  3481,  3485,  3489,  3492,
    3497,  3501,  3505,  3509,  3511,  3513,  3515,  3517,  3519,  3521,
    3522,  3523,  3531,  3532,  3533,  3542,  3546,  3549,  3550,  3552,
    3554,  3558,  3561,  3564,  3566,  3568,  3572,  3574,  3576,  3579,
    3581,  3585,  3587,  3591,  3593,  3595,  3597,  3599,  3601,  3603,
    3605,  3608,  3613,  3615,  3619,  3621,  3625,  3628,  3633,  3635,
    3639,  3641,  3644,  3649,  3651,  3655,  3657,  3659,  3661,  3664,
    3667,  3672,  3675,  3680,  3682,  3686,  3688,  3690,  3692,  3695,
    3697,  3699,  3701,  3703,  3705,  3708,  3715,  3722,  3723,  3725,
    3726,  3728,  3731,  3733,  3734,  3740,  3741,  3747,  3749,  3750,
    3754,  3756,  3760,  3762,  3766,  3768,  3770,  3771,  3772,  3778,
    3780,  3783,  3785,  3786,  3787,  3791,  3792,  3793,  3797,  3799,
    3801,  3803,  3805,  3807,  3809,  3812,  3815,  3820,  3824,  3828,
    3830,  3834,  3837,  3839,  3841,  3842,  3844,  3846,  3848,  3850,
    3851,  3853,  3857,  3859,  3861,  3862,  3866,  3868,  3870,  3872,
    3874,  3876,  3878,  3880,  3882,  3884,  3886,  3888,  3890,  3898,
    3899,  3901,  3903,  3905,  3907,  3911,  3913,  3915,  3917,  3920,
    3921,  3925,  3927,  3931,  3933,  3937,  3939,  3941,  3948,  3949,
    3953,  3955,  3959,  3960,  3962,  3967,  3973,  3976,  3978,  3980,
    3985,  3987,  3991,  3996,  4001,  4003,  4007,  4009,  4011,  4013,
    4016,  4018,  4023,  4024,  4026,  4027,  4029,  4031,  4034,  4036,
    4038,  4040,  4042,  4047,  4051,  4053,  4055,  4057,  4060,  4062,
    4064,  4067,  4070,  4072,  4076,  4079,  4082,  4084,  4088,  4090,
    4093,  4098,  4100,  4103,  4105,  4109,  4114,  4115,  4117,  4118,
    4120,  4121,  4123,  4125,  4129,  4131,  4135,  4137,  4140,  4142,
    4146,  4149,  4152,  4153,  4156,  4158,  4160,  4166,  4170,  4176,
    4180,  4182,  4186,  4188,  4190,  4191,  4193,  4197,  4201,  4205,
    4212,  4217,  4222,  4228,  4230,  4232,  4234,  4236,  4238,  4240,
    4242,  4244,  4246,  4248,  4250,  4251,  4253,  4255,  4257,  4259,
    4261,  4263,  4265,  4270,  4276,  4278,  4284,  4290,  4292,  4294,
    4296,  4301,  4303,  4308,  4310,  4318,  4320,  4322,  4324,  4329,
    4336,  4337,  4340,  4345,  4347,  4349,  4351,  4353,  4355,  4357,
    4359,  4363,  4365,  4367,  4371,  4373,  4374,  4378,  4384,  4386,
    4389,  4392,  4397,  4401,  4403,  4405,  4407,  4409,  4411,  4413,
    4416,  4419,  4420,  4424,  4425,  4429,  4431,  4433,  4435,  4437,
    4439,  4441,  4443,  4448,  4450,  4452,  4454,  4456,  4458,  4460,
    4462,  4467,  4469,  4471,  4473,  4475,  4477,  4479,  4481,  4483,
    4485,  4487,  4489,  4491,  4493,  4495,  4497,  4499,  4503,  4504,
    4513,  4514,  4524,  4525,  4533,  4534,  4544,  4545,  4547,  4550,
    4552,  4556,  4558,  4562,  4568,  4570,  4572,  4574,  4576,  4579,
    4580,  4581,  4590,  4596,  4598,  4600,  4607,  4608,  4612,  4614,
    4618,  4623,  4625,  4626,  4629,  4634,  4641,  4642,  4644,  4646,
    4648,  4650,  4654,  4656,  4659,  4661,  4663,  4666,  4669,  4671,
    4673,  4675,  4678,  4683,  4687,  4690,  4694,  4698,  4702,  4704,
    4706,  4708,  4710,  4712,  4714,  4720,  4726,  4732,  4738,  4744,
    4749,  4754,  4758,  4763,  4765,  4769,  4771,  4777,  4785,  4791,
    4792,  4795,  4797,  4799,  4800,  4804,  4806,  4810,  4812,  4814,
    4816,  4817,  4821,  4823,  4825,  4827,  4829,  4834,  4841,  4843,
    4845,  4848,  4852,  4854,  4856,  4858,  4860,  4862,  4864,  4866,
    4868,  4874,  4880,  4885,  4886,  4891,  4893,  4896,  4898,  4900,
    4902,  4905,  4908,  4909,  4910,  4917,  4918,  4921,  4924,  4932,
    4936,  4940,  4943,  4946,  4949,  4951,  4955,  4957,  4961,  4963,
    4967,  4969,  4973,  4975,  4977,  4979,  4982,  4985,  4987,  4989,
    4992,  4997,  4999,  5001,  5003,  5005,  5007,  5009,  5013,  5016,
    5020,  5024,  5028,  5034,  5040,  5046,  5052,  5058,  5063,  5068,
    5072,  5077,  5079,  5081,  5085,  5087,  5090,  5092,  5094,  5096,
    5100,  5106,  5108,  5110,  5112,  5114,  5118,  5121,  5124,  5127,
    5129,  5132,  5135,  5137,  5140,  5143,  5146,  5148,  5152,  5155,
    5157,  5160,  5162,  5165,  5167,  5168,  5169,  5176,  5177,  5180,
    5181,  5183,  5185,  5188,  5191,  5193,  5195,  5200,  5204,  5206,
    5210,  5212,  5215,  5221,  5224,  5227,  5233,  5234,  5237,  5239,
    5241,  5244,  5251,  5258,  5260,  5261,  5263,  5266,  5268,  5271,
    5272,  5275,  5277,  5279,  5281,  5283,  5285,  5287,  5289,  5291,
    5293,  5295,  5297,  5299,  5301,  5303,  5305,  5307,  5309,  5311,
    5313,  5315,  5317,  5319,  5321,  5323,  5325,  5327,  5329,  5331,
    5333,  5335,  5337,  5339,  5341,  5343,  5345,  5347,  5349,  5351,
    5353,  5355,  5357,  5359,  5361,  5363,  5365,  5367,  5369,  5371,
    5373,  5375,  5377,  5379,  5381,  5383,  5385,  5387,  5389,  5391,
    5393,  5395,  5397,  5399,  5401,  5403,  5405,  5407,  5409,  5411,
    5413,  5415,  5417,  5419,  5421,  5423,  5425,  5427,  5429,  5431,
    5433,  5435,  5437,  5439,  5441,  5443
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1024,     0,    -1,   200,    -1,   197,    -1,   124,   672,   426,
     595,   673,    -1,   138,    -1,  1089,    -1,    26,    -1,   674,
      -1,   673,     5,   674,    -1,   937,    -1,   430,   675,   391,
      -1,   675,   676,   675,    -1,    26,    -1,   677,    26,    -1,
    1089,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   679,    -1,    -1,
     274,   430,   680,   681,   391,    -1,   568,   430,    26,     5,
      26,   391,    -1,   682,    -1,   681,     5,   682,    -1,   489,
      -1,   530,    -1,   536,    -1,   505,    -1,   409,    -1,   604,
      -1,   527,    -1,   479,    -1,   416,    -1,   490,    -1,   345,
      -1,   531,    -1,   455,    -1,   332,    -1,   593,    -1,    98,
      -1,  1003,    -1,    -1,   684,    -1,    -1,   274,   430,   685,
     686,   391,    -1,   687,    -1,   686,     5,   687,    -1,   682,
      -1,   431,    -1,   602,    25,    -1,   203,   924,    -1,   329,
     924,    -1,   284,   924,    -1,   337,   924,    -1,   293,   924,
      -1,   259,   924,    -1,   533,   689,    -1,   868,   344,  1089,
      -1,    -1,   289,   430,  1477,   391,   344,   690,  1108,    -1,
     104,   430,   937,     5,    25,     5,    25,   391,    -1,   406,
     430,   929,   391,   344,  1089,    -1,  1226,    -1,   192,   430,
     887,   391,   344,  1089,    -1,    -1,    -1,  1089,   589,   937,
     430,   691,   705,   391,   692,   703,    -1,    -1,    -1,    -1,
     937,   430,   693,   705,   694,   391,   695,   703,    -1,    -1,
      -1,   473,  1424,   622,  1424,   430,   696,   705,   697,   391,
     703,    -1,    -1,    -1,   937,   520,   937,   430,   698,   705,
     699,   391,   703,    -1,    -1,    -1,    -1,   365,   708,   589,
     709,   458,   672,   426,   430,   700,   705,   701,   391,   702,
     704,    -1,    -1,   344,  1108,    -1,    -1,   344,  1108,    -1,
     162,    -1,    -1,   706,    -1,   707,    -1,   706,     5,   707,
      -1,   837,    -1,    25,    -1,   937,    -1,   937,    -1,   937,
     619,   937,    -1,    -1,   534,   844,   711,   714,   718,   715,
      -1,    -1,   534,   712,   713,   716,   715,    -1,   720,    -1,
     713,   720,    -1,   722,    -1,   714,   722,    -1,   360,    -1,
      -1,    -1,   339,   717,  1487,    -1,    -1,    -1,   339,   719,
    1487,    -1,    -1,   578,   844,   721,  1487,    -1,    -1,   578,
     844,   723,  1487,    -1,   278,   934,    -1,   202,   932,    -1,
      83,   932,    -1,   168,    -1,   185,  1430,    -1,   493,   931,
      -1,    30,   726,    31,    -1,   727,    -1,   729,    -1,   728,
      -1,   727,   728,    -1,    29,    -1,   730,    -1,   729,   730,
      -1,    28,    -1,   393,    -1,    -1,    -1,   320,   733,   735,
     734,   736,    -1,   384,  1089,   624,   737,   977,  1002,   678,
      -1,  1089,   624,   737,   977,   546,  1477,  1002,   678,    -1,
      -1,   739,   191,    -1,   738,    -1,   737,     5,   738,    -1,
     937,    -1,   937,   619,   937,    -1,   937,   619,    20,    -1,
     740,    -1,   739,   740,    -1,    -1,   270,   746,   741,  1487,
      -1,    -1,   273,   747,   742,  1487,    -1,    -1,  1005,   743,
    1487,    -1,    -1,   166,   744,  1487,    -1,    -1,   163,   745,
    1487,    -1,   941,    -1,   746,     5,   941,    -1,   941,    -1,
     747,     5,   941,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,   430,   837,   750,   391,
      -1,    -1,     5,   791,   625,   794,    -1,   155,    -1,   279,
      -1,    -1,   753,    -1,   754,    -1,   753,   754,    -1,    -1,
      -1,   437,   755,   757,   756,  1195,    -1,   804,    -1,  1467,
      -1,   760,    -1,   757,     5,   760,    -1,    -1,   759,   937,
      -1,   353,   758,   803,    25,    -1,   353,   758,   803,   937,
      -1,   353,   758,   803,   943,    -1,   353,   758,   803,    26,
      -1,   764,   780,    -1,    -1,   758,   353,   761,   762,    -1,
      26,    -1,    25,    -1,   943,    -1,    19,    26,    -1,   758,
      -1,   763,    -1,   764,     5,   763,    -1,    -1,   535,    -1,
      -1,   486,   458,   772,   426,   767,   623,   780,    -1,    -1,
     318,   765,   769,    26,   770,   302,   458,   771,   426,   768,
     623,   780,    -1,   430,    -1,   457,    -1,   391,    -1,   425,
      -1,    26,    -1,   773,     5,   773,     5,   773,    -1,   773,
       5,   773,    -1,   773,    -1,    26,    -1,    -1,   463,   775,
     757,   283,    -1,    -1,   260,   776,   758,   619,    20,    -1,
      -1,   334,   777,   758,   258,   430,   778,   391,    -1,   779,
      -1,   778,     5,   779,    -1,   758,    -1,   782,    -1,    -1,
      58,    -1,    -1,    -1,   783,   785,   784,   781,    -1,   766,
      -1,   774,    -1,   535,    -1,   535,   430,    26,   391,    -1,
     423,   430,    26,   391,    -1,   423,   430,    26,     5,    26,
     391,    -1,   407,    -1,   616,   758,    -1,   379,    -1,   508,
      -1,    89,    -1,   397,    -1,   397,   430,    26,   391,    -1,
     397,   430,    26,     5,    26,   391,    -1,   511,    -1,   511,
     430,    26,   391,    -1,   511,   430,    26,     5,    26,   391,
      -1,   501,    -1,   299,    -1,   537,    -1,   532,    -1,    79,
      -1,    80,    -1,   574,    -1,   357,   789,    -1,   369,   790,
      -1,   786,    -1,    32,    -1,   556,   787,   619,   788,    -1,
     758,    -1,   758,    -1,    -1,   791,   625,   794,    -1,   799,
     625,   802,    -1,    -1,   792,   793,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,
     796,    -1,    -1,   795,   793,    -1,    -1,   430,   798,   391,
      -1,    -1,   430,    26,   391,    -1,    26,    -1,    -1,   800,
     801,   797,    -1,   581,    -1,   512,    -1,   590,    -1,   552,
      -1,   453,    -1,   469,    -1,   366,   796,    -1,   801,    -1,
      -1,    14,    -1,    -1,   236,   937,   805,   616,   806,    -1,
     808,    -1,   811,    -1,   535,    -1,   535,   430,    26,   391,
      -1,   423,   430,    26,   391,    -1,   423,   430,    26,     5,
      26,   391,    -1,   407,    -1,   379,    -1,   508,    -1,   397,
      -1,   397,   430,    26,   391,    -1,   397,   430,    26,     5,
      26,   391,    -1,   511,    -1,   511,   430,    26,   391,    -1,
     511,   430,    26,     5,    26,   391,    -1,   501,    -1,   299,
      -1,   537,    -1,   532,    -1,   574,    -1,   357,   789,    -1,
     369,   790,    -1,   807,    -1,   556,   787,   619,   788,    -1,
      -1,   486,   458,   772,   426,   809,   623,   806,    -1,    -1,
     318,   765,   769,    26,   770,   302,   458,   771,   426,   810,
     623,   806,    -1,    -1,   463,   812,   814,   283,    -1,    -1,
     260,   813,   937,   619,    20,    -1,   815,    -1,   814,     5,
     815,    -1,   816,   806,    -1,   817,    -1,   816,     5,   817,
      -1,   937,    -1,    -1,   617,   928,    -1,    70,   937,    -1,
      68,    -1,   625,  1477,    -1,   625,   508,   937,   658,  1477,
      -1,   625,   508,   937,   389,    -1,    72,   937,    -1,   156,
     862,  1108,   826,    -1,   400,   862,   842,   818,   826,    -1,
     209,   934,   826,    -1,    -1,    -1,   188,   823,  1115,   625,
     937,   619,    20,   825,   678,   824,   827,    -1,    -1,   467,
     929,    -1,   678,    -1,    -1,   828,   238,    -1,   829,    -1,
     828,   829,    -1,    -1,   351,   830,  1487,    -1,    -1,   347,
     831,  1487,    -1,    -1,  1005,   832,  1487,    -1,   497,   862,
     843,   678,    -1,   497,   862,   843,   678,    65,    -1,   286,
      -1,   285,    -1,   212,    -1,   364,    -1,   173,    -1,   211,
      -1,   328,    -1,   327,    -1,   243,    -1,   170,    -1,   169,
      -1,   144,    -1,   204,    -1,   127,    -1,   143,    -1,   187,
      -1,   153,    -1,   213,    -1,   213,   844,    -1,   847,    -1,
     846,    -1,   851,    -1,   879,    -1,   837,   838,    -1,   880,
      -1,   882,    -1,   848,    -1,    19,   837,    -1,    18,   837,
      -1,   853,    -1,   861,    -1,   855,    -1,   474,    -1,   748,
      -1,   856,    -1,   857,    -1,   858,    -1,   859,    -1,   860,
      -1,    35,   837,    -1,   862,    -1,   862,   841,    -1,   844,
      -1,   482,    -1,   840,    -1,   841,     5,   840,    -1,   844,
      -1,   842,     5,   844,    -1,   844,    -1,   843,     5,   844,
      -1,   837,    -1,    18,    -1,    19,    -1,     9,   837,    -1,
     483,    -1,   427,    -1,   430,   837,   391,    -1,   442,   430,
    1404,   391,    -1,   294,   430,  1404,   391,    -1,   845,   943,
      -1,   845,    26,    -1,    25,    -1,   943,    -1,    26,    -1,
     850,    -1,  1089,    -1,  1089,   420,  1089,    -1,   849,    -1,
     433,   837,    -1,   392,   837,    -1,  1198,    -1,    -1,   506,
     852,  1198,    -1,     7,   837,    -1,     6,   837,    -1,   837,
      -1,   854,     5,   837,    -1,   622,   430,  1404,   391,    -1,
     428,   430,  1404,   391,    -1,   622,   430,   862,   854,   391,
      -1,   428,   430,   862,   854,   391,    -1,   386,    -1,   249,
      -1,    10,   837,    -1,   252,   837,    -1,    10,   837,   441,
      25,    -1,   252,   837,   441,    25,    -1,   556,   837,    -1,
     371,   837,    -1,   556,   837,   441,    25,    -1,   371,   837,
     441,    25,    -1,   390,    -1,     8,   837,    -1,    18,   837,
      -1,    19,   837,    -1,    20,   837,    -1,    21,   837,    -1,
      22,   837,    -1,    11,   837,    -1,    14,   837,    -1,   456,
     837,    -1,    12,   837,    -1,    13,   837,    -1,    17,   837,
      -1,    16,   837,    -1,    15,   837,    -1,    -1,    -1,    -1,
     937,   430,   864,   705,   865,   391,    -1,    -1,    -1,   937,
     520,   937,   430,   866,   705,   867,   391,    -1,    -1,    -1,
     537,   430,   869,   837,   870,   391,    -1,    -1,    -1,   512,
     430,   871,   837,   872,   391,    -1,    -1,    -1,   590,   430,
     873,   837,   874,   391,    -1,    -1,    -1,   581,   430,   875,
     837,   876,   391,    -1,   369,   430,   883,   391,   878,    -1,
     357,   430,    25,   391,   877,    -1,   357,   430,    26,   391,
     877,    -1,   357,   430,    26,   589,    26,   391,   877,    -1,
      -1,  1384,   625,  1385,    -1,   790,    -1,   868,    -1,   289,
     430,  1477,   391,    -1,    99,   430,   929,   391,    -1,    71,
     430,   929,   391,    -1,   406,   430,  1477,   391,    -1,   192,
     430,  1477,   391,    -1,    59,   430,  1477,   391,    -1,   881,
      -1,   863,    -1,  1380,    -1,   537,    -1,   422,   430,   837,
     391,    -1,   322,   430,   837,   391,    -1,   487,   837,    -1,
     443,   749,    -1,   837,   108,    -1,   837,   109,    -1,   837,
     110,    -1,    25,    -1,   884,    -1,    19,   884,    -1,   886,
      -1,   885,    -1,    26,    -1,    26,    26,    -1,    26,    26,
     589,    26,    -1,    26,    26,   589,    26,   589,    26,    -1,
      26,    26,   589,    26,   589,    24,    -1,    26,   589,    26,
      -1,    26,   589,    26,   589,    26,    -1,    26,   589,    26,
     589,    24,    -1,    26,   589,    24,    -1,    24,    -1,    26,
      -1,    26,    19,    26,    -1,   929,    -1,   887,     5,   929,
      -1,    -1,    -1,   595,  1089,    14,   844,   625,   844,   891,
     889,  1487,   890,   241,    -1,    -1,   571,   844,    -1,    -1,
      -1,    -1,   403,   893,   931,   894,   896,  1285,   895,  1487,
     240,    -1,    -1,     8,   862,   842,    -1,    -1,    -1,   637,
     937,   898,   752,   899,  1034,   901,   900,   906,   638,    -1,
      -1,   911,    -1,    -1,   902,    -1,   903,    -1,   902,   903,
      -1,    -1,   639,   904,  1487,    -1,    -1,   640,   905,  1487,
      -1,    -1,   907,    -1,   908,    -1,   907,   908,    -1,    -1,
     641,   909,  1487,    -1,    -1,   642,   910,  1487,    -1,   912,
     916,   324,    -1,    91,    -1,    91,   913,   546,   914,    -1,
      91,   384,   915,    -1,  1089,    -1,   913,     5,  1089,    -1,
     937,    -1,   914,     5,   937,    -1,  1089,    -1,   915,     5,
    1089,    -1,   917,    -1,   916,   917,    -1,    -1,   643,   918,
    1487,    -1,    -1,   644,   919,  1487,    -1,    -1,   663,   914,
     920,  1487,    -1,    -1,   480,   914,   921,  1487,    -1,    -1,
     624,   914,   922,  1487,    -1,   545,   930,    -1,   554,    19,
      26,    -1,   554,    -1,   500,    18,    26,    -1,   500,    -1,
      26,    -1,  1089,    -1,    25,    -1,   942,    -1,   844,    -1,
     926,     5,   926,    -1,   927,    -1,   937,    -1,   666,   430,
     937,   391,    -1,   937,   619,   666,   430,   937,   391,    -1,
     937,   458,   675,   426,    -1,   937,   619,    20,    -1,   937,
     458,   675,   426,   619,    20,    -1,   937,   619,   937,    -1,
     937,   458,   675,   426,   619,   937,    -1,   938,    -1,   938,
      -1,   938,    -1,   938,    -1,   938,    -1,   938,    -1,    -1,
     550,    26,    -1,  1486,    -1,   939,    -1,  1486,    -1,   349,
     430,   940,   391,    -1,  1092,    -1,    25,    -1,   937,    -1,
     937,   458,   675,   426,    -1,   937,   619,    20,    -1,   937,
     458,   675,   426,   619,    20,    -1,   937,   619,   937,    -1,
     937,   458,   675,   426,   619,   937,    -1,  1089,    -1,    24,
      -1,   619,    26,    -1,   547,  1469,    -1,   651,   946,    -1,
     947,    -1,   946,     5,   947,    -1,   937,    -1,   662,   946,
      -1,   653,   946,    -1,   654,  1477,    -1,   652,   934,   658,
    1477,    -1,   656,   946,    -1,   657,  1477,    -1,   655,   934,
     658,  1477,    -1,    -1,   660,   952,   842,   957,   959,   961,
     953,   955,    -1,    -1,   954,    -1,   648,    -1,   649,    -1,
      -1,   956,    -1,   344,  1089,    -1,    -1,   958,    -1,   389,
     842,    -1,    -1,   960,    -1,   659,    26,    -1,    -1,   962,
      -1,   650,    26,   963,    -1,    -1,   399,    26,    -1,    -1,
     621,   844,   575,   965,  1487,   966,   440,    -1,    -1,    -1,
     542,   967,  1487,    -1,    -1,    -1,    62,   968,   844,   575,
     969,  1487,   966,    -1,   106,   937,   430,    26,   391,    -1,
      55,   937,    -1,    75,   937,    -1,    -1,   290,  1120,   973,
     625,   482,    -1,   290,  1120,   556,   974,    -1,   975,    -1,
     974,     5,   975,    -1,   787,   619,  1376,    -1,   787,   619,
      20,    -1,    -1,   978,   324,    -1,    -1,   150,    -1,   979,
      -1,   978,   979,    -1,    -1,   270,   991,   980,  1487,    -1,
      -1,   273,   992,   981,  1487,    -1,    -1,   351,   982,  1487,
      -1,    -1,   347,   983,  1487,    -1,    -1,  1005,   984,  1487,
      -1,    -1,   305,   985,  1487,    -1,    -1,   275,   986,  1487,
      -1,    -1,    36,   987,  1487,    -1,    -1,    34,   988,  1487,
      -1,    -1,    38,   989,  1487,    -1,    -1,    37,   990,  1487,
      -1,   929,    -1,   991,     5,   929,    -1,   929,    -1,   992,
       5,   929,    -1,   314,   995,    -1,   315,   937,   658,   995,
      -1,   561,    -1,   374,    -1,   929,    -1,    -1,   664,   998,
     997,   976,    -1,   384,  1108,   977,   936,   678,    -1,  1108,
     977,   546,  1477,   936,   678,    -1,    -1,   486,  1115,   977,
     546,   937,   619,    20,   936,   999,   678,    -1,   468,  1477,
    1001,    -1,    81,    26,    -1,    82,    26,    -1,   626,    -1,
     539,    -1,    -1,   550,    26,    -1,  1004,    -1,    43,    25,
      -1,   495,    14,    26,    -1,   495,    14,  1089,    -1,    44,
      14,    26,    -1,    44,    14,  1089,    -1,    40,    -1,    42,
      -1,    39,    -1,    41,    -1,    -1,   429,  1006,  1011,    -1,
     295,    -1,    -1,   596,  1008,  1011,    -1,   303,  1013,    -1,
     596,  1011,    -1,  1013,    -1,   430,  1012,   391,    -1,  1013,
      -1,  1012,     5,  1013,    -1,  1014,    -1,   594,    -1,   312,
      -1,   330,    -1,   304,    -1,   484,    -1,   441,    -1,   626,
      -1,   550,    -1,   539,    -1,   177,    -1,   438,    -1,   540,
      -1,   555,    -1,   519,    -1,   310,    -1,   311,    -1,    25,
      -1,   509,    -1,    -1,    -1,   598,  1017,  1113,  1018,    14,
     862,  1019,    -1,   482,    -1,   843,    -1,   219,  1089,    -1,
     208,  1089,    -1,   222,  1089,    -1,   450,  1089,   333,    -1,
     450,  1089,   385,   925,    -1,    -1,  1026,  1025,  1029,    -1,
      -1,  1027,    -1,  1028,    -1,  1027,  1028,    -1,   971,    -1,
    1033,    -1,  1049,    -1,  1035,    -1,    -1,  1030,    -1,  1032,
      -1,  1030,  1032,    -1,    66,   937,    -1,  1037,    -1,  1043,
      -1,  1055,    -1,  1208,    -1,  1218,    -1,  1076,    -1,  1467,
      -1,   897,    -1,   725,    -1,   970,    -1,   731,    -1,   725,
      -1,  1467,    -1,    -1,   725,    -1,  1467,    -1,   753,    -1,
     367,    -1,    60,    -1,    -1,    -1,    -1,    -1,  1036,  1038,
     937,   430,  1039,  1106,   391,  1040,   752,  1041,  1034,  1487,
    1042,    -1,   210,    -1,    -1,    -1,   557,  1044,   752,  1045,
    1487,   361,    -1,   177,   839,    -1,   862,    -1,   862,   842,
      -1,   356,  1388,    -1,   466,  1388,    -1,  1050,    -1,  1051,
      -1,  1050,  1051,    -1,  1052,    -1,  1033,    -1,  1048,    -1,
      -1,   405,  1053,  1054,    -1,   752,   242,    -1,   925,    -1,
      -1,    -1,    -1,   113,   937,   112,   937,   430,  1056,  1106,
     391,  1057,   752,  1058,  1034,  1487,  1042,    -1,    -1,   558,
    1060,  1075,  1066,  1061,    -1,   362,    -1,    -1,   234,  1063,
    1487,    -1,    -1,    23,  1067,  1068,  1069,   936,  1064,  1487,
      -1,    -1,    23,  1067,   936,  1065,  1487,    -1,  1062,    -1,
    1066,  1062,    -1,    -1,  1007,    -1,    25,    -1,  1089,    -1,
      -1,  1089,    -1,    25,    -1,   251,  1073,    -1,   263,  1074,
      -1,   246,  1074,    -1,   585,    -1,    25,    -1,  1089,    -1,
    1073,    -1,  1074,     5,  1073,    -1,  1089,    -1,    25,    -1,
      -1,    -1,   645,   937,  1077,   752,  1078,  1079,   646,    -1,
    1080,    -1,  1079,  1080,    -1,    -1,   647,  1081,  1487,    -1,
      -1,   624,   937,  1082,  1487,    -1,  1086,  1084,    -1,    -1,
     679,  1087,    -1,  1088,    -1,  1085,    -1,   958,    -1,   960,
      -1,   962,    -1,   954,    -1,   956,    -1,   370,   862,   842,
      -1,    -1,    65,    -1,    65,    -1,  1090,    -1,  1092,    -1,
     190,  1092,    -1,  1092,   619,    -1,  1091,  1096,    -1,  1091,
     937,   458,  1100,   426,    -1,  1091,   937,   458,  1100,   426,
     458,  1100,   426,    -1,  1097,    -1,   937,    -1,  1093,    -1,
     937,   457,  1095,   425,    -1,   937,   457,  1095,   425,    -1,
    1089,    -1,    25,    -1,    20,    -1,   937,    -1,   937,  1099,
      -1,   937,  1099,    -1,   458,  1100,   426,    -1,   458,  1100,
     426,   458,  1100,   426,    -1,  1101,    -1,  1100,     5,  1101,
      -1,   675,    -1,  1103,    -1,  1105,    -1,  1103,   619,  1104,
      -1,  1103,   619,   937,   458,  1100,   426,    -1,  1103,   619,
     937,   458,  1100,   426,   458,  1100,   426,    -1,   937,    -1,
    1094,    -1,    20,    -1,   937,    -1,   937,  1099,    -1,    -1,
    1107,    -1,  1109,    -1,  1107,     5,  1109,    -1,  1110,    -1,
    1108,     5,  1110,    -1,   937,    -1,   937,   619,   937,    -1,
    1089,    -1,  1089,   420,  1089,    -1,    25,    -1,   943,    -1,
      26,    -1,  1112,    -1,  1111,     5,  1112,    -1,  1089,    -1,
    1089,   420,  1089,    -1,  1114,    -1,  1113,     5,  1114,    -1,
    1102,    -1,  1089,    -1,  1117,    -1,  1116,     5,  1117,    -1,
    1089,  1118,    -1,    -1,   587,    -1,   538,    -1,   937,   458,
    1100,   426,    -1,  1121,    -1,  1120,     5,  1121,    -1,  1089,
      -1,  1089,   420,  1089,    -1,   254,   933,   617,   927,   579,
    1479,   683,    -1,    -1,   617,   430,   844,     5,   844,   391,
    1124,    -1,    -1,   568,   430,   844,     5,   844,   391,    -1,
     255,   937,  1123,    -1,   937,    -1,   338,   935,  1128,    -1,
    1129,    -1,   546,   844,    -1,  1130,  1131,  1136,     8,  1126,
      -1,    -1,   617,  1132,   430,   844,     5,   844,   391,    -1,
      -1,   556,   938,    -1,    -1,   350,    -1,   217,  1430,   266,
    1462,  1135,    -1,   563,   930,    -1,   563,   930,     8,   862,
     842,    -1,    -1,   616,   576,  1424,   373,  1424,    -1,   616,
     576,  1424,     5,   373,  1424,    -1,   616,  1424,     5,  1424,
      -1,    -1,   648,    -1,   649,    -1,    90,  1462,  1138,  1139,
      -1,    -1,   616,  1462,    -1,    -1,   616,   576,  1424,     8,
    1424,    -1,   576,  1424,     8,  1424,    -1,   411,  1141,    -1,
    1142,    -1,  1141,     5,  1142,    -1,   203,   924,    -1,   284,
     924,    -1,   329,   924,    -1,   337,   924,    -1,   293,   924,
      -1,   259,   924,    -1,  1009,    -1,   438,  1010,    -1,   449,
    1010,    -1,   561,  1010,    -1,   374,  1010,    -1,   550,  1010,
      -1,   548,   925,    -1,   549,   925,    -1,   400,   679,    -1,
     664,   679,    -1,   291,    -1,   195,    -1,   151,    -1,   128,
      -1,   146,    -1,   137,    -1,  1429,   413,  1146,   546,  1144,
      -1,  1089,    -1,    25,    -1,   402,  1146,    -1,   402,  1146,
       8,  1108,    -1,   938,    -1,    -1,   461,  1155,   678,   595,
    1150,  1089,   936,   678,  1148,  1151,    -1,   461,  1155,   678,
     344,  1089,    -1,    -1,   535,    -1,    -1,  1152,   282,    -1,
    1153,    -1,  1152,  1153,    -1,    -1,  1005,  1154,  1487,    -1,
     843,    -1,    -1,   603,   930,  1157,  1158,    -1,    -1,   546,
    1159,    -1,  1160,    -1,  1159,     5,  1160,    -1,  1416,    -1,
     482,    -1,   220,  1163,    88,    -1,   220,  1163,   625,  1162,
      -1,   220,  1163,    87,  1162,    -1,   220,  1163,    -1,    25,
      -1,   942,    -1,   937,    -1,    -1,   478,    -1,   145,  1163,
    1164,   430,   862,  1047,   391,    -1,   193,  1163,    -1,    67,
    1163,    -1,  1199,  1207,    -1,   446,    61,    -1,   446,  1170,
      -1,  1171,    -1,  1170,  1171,    -1,    -1,   133,  1172,  1487,
      -1,    -1,   199,  1173,  1487,    -1,    -1,   228,  1174,  1487,
      -1,    -1,   216,  1175,  1487,    -1,    -1,   253,  1176,  1487,
      -1,    -1,   201,  1089,  1177,  1487,    -1,    -1,   224,  1089,
    1178,  1487,    -1,  1189,    -1,  1191,    -1,  1190,    -1,  1180,
      -1,  1216,    -1,  1183,    -1,    -1,   560,   844,  1181,   481,
      -1,    -1,   481,    -1,    -1,   569,   844,  1184,  1182,    -1,
     158,    -1,   628,  1203,    -1,   161,  1203,    -1,   160,  1203,
      -1,    -1,  1186,    -1,  1187,    -1,  1186,  1187,    -1,  1196,
    1188,    -1,    -1,   617,  1203,    -1,   518,  1185,  1195,    -1,
     517,  1424,  1195,    -1,   516,  1194,  1193,  1192,  1195,    -1,
      -1,   152,   837,    -1,   152,   837,     5,   837,    -1,   612,
      -1,   613,    -1,   614,    -1,   615,    -1,  1089,    -1,    -1,
     521,    -1,  1197,    -1,  1196,     5,  1197,    -1,   844,  1230,
      -1,   608,   430,   837,   391,  1215,    -1,    64,  1215,    -1,
     495,   430,    20,   391,  1215,    -1,   412,   430,    20,   391,
    1215,    -1,   387,   430,   837,   391,  1215,    -1,   588,   430,
     837,   391,  1215,    -1,   601,   430,   837,   391,  1215,    -1,
     600,   430,   837,   391,  1215,    -1,    -1,   460,  1200,    -1,
    1201,    -1,  1200,  1201,    -1,   227,    26,    -1,   218,    26,
      -1,   301,    26,    -1,   184,    26,    -1,   256,    26,    -1,
     175,    -1,   343,    25,    -1,   343,  1089,    -1,   176,    25,
      -1,   159,    25,    -1,  1206,    -1,  1202,  1206,    -1,  1204,
     108,    -1,  1204,   110,    -1,  1204,   109,    -1,  1204,    -1,
     943,    -1,    26,    -1,    -1,   460,  1202,    -1,   227,  1203,
      -1,   218,  1203,    -1,   301,  1203,    -1,   184,  1203,    -1,
     256,  1203,    -1,   257,  1203,    -1,   627,    25,    -1,   628,
    1203,    -1,   632,    -1,   629,    -1,   630,    -1,   631,    -1,
     636,    -1,   633,    -1,   634,    -1,   635,    -1,    76,  1203,
      -1,    77,  1203,    -1,    78,  1203,    -1,   343,    25,    -1,
     176,    25,    -1,   399,    -1,    73,    -1,    74,    -1,    -1,
     513,   618,  1116,    -1,   134,  1116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   464,  1209,   937,   430,  1210,  1106,   391,
    1211,   752,  1212,  1168,  1213,  1169,  1214,   239,    -1,    -1,
     525,   837,    -1,   515,  1217,    -1,    -1,  1144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,  1219,   937,   430,  1220,
    1106,   391,  1221,   752,  1222,  1225,  1223,  1169,  1224,   239,
      -1,  1205,  1207,    -1,    -1,    -1,    -1,   154,   430,    25,
       5,  1227,   705,  1228,   391,  1229,   703,    -1,    -1,   383,
      -1,   383,   218,    26,    -1,   383,   218,  1089,    -1,   606,
     844,    -1,   606,   844,   344,  1089,    -1,   606,   844,   162,
      -1,   606,   844,   577,    -1,   606,   844,   544,    -1,  1233,
      -1,   172,    -1,   323,    -1,   281,    -1,  1240,    -1,  1235,
      -1,    -1,    -1,   206,  1236,  1373,   430,  1237,  1244,   391,
      -1,    -1,    -1,   131,  1238,  1373,   430,  1239,  1244,   391,
    1241,    -1,   103,  1242,   391,    -1,    54,   938,    -1,    -1,
     268,    -1,  1243,    -1,  1242,     5,  1243,    -1,   937,   587,
      -1,   937,   538,    -1,   937,    -1,  1245,    -1,  1244,     5,
    1245,    -1,  1326,    -1,  1324,    -1,   120,   937,    -1,   179,
      -1,    45,   937,  1248,    -1,  1249,    -1,  1248,     5,  1249,
      -1,  1250,    -1,  1253,    -1,  1256,    -1,  1261,    -1,  1262,
      -1,  1260,    -1,  1259,    -1,   584,  1251,    -1,   584,   430,
    1252,   391,    -1,  1245,    -1,  1245,   663,   937,    -1,  1251,
      -1,  1252,     5,  1251,    -1,   541,  1255,    -1,   541,   430,
    1254,   391,    -1,  1255,    -1,  1254,     5,  1255,    -1,   937,
      -1,   454,  1258,    -1,   454,   430,  1257,   391,    -1,  1258,
      -1,  1257,     5,  1258,    -1,  1245,    -1,    85,    -1,    86,
      -1,    84,    26,    -1,    56,  1330,    -1,    56,   430,  1263,
     391,    -1,    57,  1264,    -1,    57,   430,  1263,   391,    -1,
    1330,    -1,  1263,     5,  1330,    -1,   937,    -1,   265,    -1,
     231,    -1,   164,  1267,    -1,   141,    -1,   129,    -1,   119,
      -1,   117,    -1,   121,    -1,   178,  1430,    -1,   230,  1266,
     459,  1424,   625,  1424,    -1,   298,   930,   459,  1424,   625,
    1424,    -1,    -1,  1430,    -1,    -1,   844,    -1,   522,   844,
      -1,   229,    -1,    -1,   248,  1271,  1373,  1274,  1272,    -1,
      -1,   478,  1273,   430,  1276,   391,    -1,  1410,    -1,    -1,
     430,  1275,   391,    -1,  1376,    -1,  1275,     5,  1376,    -1,
    1277,    -1,  1276,     5,  1277,    -1,  1416,    -1,   482,    -1,
      -1,    -1,   499,  1279,  1282,  1280,  1283,    -1,   938,    -1,
    1287,   931,    -1,   931,    -1,    -1,    -1,   553,  1284,  1111,
      -1,    -1,    -1,   553,  1286,  1111,    -1,   500,    -1,   554,
      -1,   561,    -1,   374,    -1,   341,    -1,   395,    -1,   377,
     844,    -1,   350,   844,    -1,   237,  1373,   149,   931,    -1,
     237,  1373,  1346,    -1,   513,   618,  1291,    -1,  1292,    -1,
    1291,     5,  1292,    -1,  1293,  1294,    -1,    26,    -1,  1376,
      -1,    -1,   587,    -1,   538,    -1,   276,    -1,   309,    -1,
      -1,   326,    -1,   356,  1299,  1297,    -1,  1462,    -1,    25,
      -1,    -1,  1429,  1301,  1302,    -1,  1331,    -1,  1335,    -1,
    1296,    -1,  1431,    -1,  1295,    -1,  1288,    -1,  1289,    -1,
    1278,    -1,  1270,    -1,  1269,    -1,  1400,    -1,  1446,    -1,
     504,  1305,   624,  1373,   625,  1310,  1304,    -1,    -1,   140,
      -1,   167,    -1,  1306,    -1,  1307,    -1,  1306,     5,  1307,
      -1,   470,    -1,   449,    -1,   438,    -1,   477,  1308,    -1,
      -1,   430,  1309,   391,    -1,  1376,    -1,  1309,     5,  1376,
      -1,  1311,    -1,  1310,     5,  1311,    -1,   462,    -1,  1374,
      -1,   235,  1373,  1313,   616,  1410,  1315,    -1,    -1,   430,
    1314,   391,    -1,  1376,    -1,  1314,     5,  1376,    -1,    -1,
     139,    -1,   491,   430,  1349,   391,    -1,   245,   430,  1319,
     391,  1318,    -1,   296,  1320,    -1,  1321,    -1,  1373,    -1,
    1373,   430,  1321,   391,    -1,  1376,    -1,  1321,     5,  1376,
      -1,   475,   430,  1323,   391,    -1,   258,   430,  1323,   391,
      -1,  1376,    -1,  1323,     5,  1376,    -1,  1322,    -1,  1317,
      -1,  1316,    -1,   399,  1379,    -1,   207,    -1,   937,  1365,
    1327,  1328,    -1,    -1,  1325,    -1,    -1,  1329,    -1,  1330,
      -1,  1329,  1330,    -1,   372,    -1,   157,    -1,   475,    -1,
    1318,    -1,   491,   430,  1349,   391,    -1,   118,  1332,  1334,
      -1,  1333,    -1,  1374,    -1,  1335,    -1,  1334,  1335,    -1,
    1312,    -1,  1303,    -1,   447,  1349,    -1,   368,  1338,    -1,
    1415,    -1,  1338,     5,  1415,    -1,   525,  1349,    -1,   546,
    1341,    -1,  1342,    -1,  1341,     5,  1342,    -1,  1343,    -1,
     514,  1343,    -1,   514,   430,  1344,   391,    -1,  1373,    -1,
    1373,  1378,    -1,  1342,    -1,  1344,     5,  1342,    -1,  1340,
    1346,  1347,  1348,    -1,    -1,  1339,    -1,    -1,  1337,    -1,
      -1,  1336,    -1,  1350,    -1,  1349,     6,  1350,    -1,  1351,
      -1,  1350,     7,  1351,    -1,  1352,    -1,     9,  1352,    -1,
    1363,    -1,   430,  1349,   391,    -1,   442,  1411,    -1,   294,
    1411,    -1,    -1,   441,  1356,    -1,  1417,    -1,  1420,    -1,
    1416,   622,   430,  1358,   391,    -1,  1416,   622,  1411,    -1,
    1416,   428,   430,  1358,   391,    -1,  1416,   428,  1411,    -1,
    1359,    -1,  1358,     5,  1359,    -1,  1466,    -1,  1379,    -1,
      -1,     9,    -1,  1416,  1360,   386,    -1,  1416,  1360,   249,
      -1,  1416,  1362,  1416,    -1,  1416,  1360,   388,  1416,     7,
    1416,    -1,  1416,   556,  1355,  1354,    -1,  1416,   371,  1355,
    1354,    -1,  1416,  1360,    10,  1355,  1354,    -1,    14,    -1,
      17,    -1,    12,    -1,    13,    -1,   252,    -1,    10,    -1,
      16,    -1,    15,    -1,  1361,    -1,  1357,    -1,  1353,    -1,
      -1,   585,    -1,   359,    -1,   475,    -1,  1366,    -1,  1367,
      -1,  1369,    -1,   535,    -1,   535,   430,  1370,   391,    -1,
     410,   430,  1371,  1368,   391,    -1,   471,    -1,   397,   430,
    1371,  1368,   391,    -1,   511,   430,  1371,  1368,   391,    -1,
     537,    -1,   407,    -1,   379,    -1,   357,  1386,   625,  1387,
      -1,   357,    -1,   369,  1386,   625,  1387,    -1,   369,    -1,
     369,  1386,   430,    26,   391,   625,  1387,    -1,   574,    -1,
     532,    -1,   423,    -1,   423,   430,    26,   391,    -1,   423,
     430,    26,     5,    26,   391,    -1,    -1,     5,  1372,    -1,
     501,   430,  1371,   391,    -1,   565,    -1,   299,    -1,   501,
      -1,    63,    -1,    26,    -1,    26,    -1,    26,    -1,    25,
     619,   937,    -1,    25,    -1,   937,    -1,   937,   589,   937,
      -1,   937,    -1,    -1,   458,    26,   426,    -1,   458,    26,
       5,    26,   426,    -1,  1377,    -1,   611,  1377,    -1,   937,
    1375,    -1,  1373,   619,   937,  1375,    -1,  1373,   619,    20,
      -1,   937,    -1,    25,    -1,   410,    -1,   943,    -1,    26,
      -1,  1381,    -1,   395,  1383,    -1,   395,  1382,    -1,    -1,
    1386,   625,  1387,    -1,    -1,  1384,   625,  1384,    -1,   581,
      -1,   512,    -1,   590,    -1,   552,    -1,   453,    -1,   469,
      -1,   366,    -1,   366,   430,    26,   391,    -1,   581,    -1,
     512,    -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,
     366,    -1,   366,   430,    26,   391,    -1,   581,    -1,   512,
      -1,   590,    -1,   552,    -1,   453,    -1,   469,    -1,   366,
      -1,   581,    -1,   512,    -1,   590,    -1,   552,    -1,   453,
      -1,   469,    -1,   366,    -1,   937,    -1,    25,    -1,  1429,
     502,   931,    -1,    -1,  1429,   398,  1281,   436,   595,  1398,
    1391,  1395,    -1,    -1,  1429,   398,  1281,   436,   100,   595,
    1399,  1392,  1395,    -1,    -1,  1429,   398,  1281,   135,  1399,
    1393,  1395,    -1,    -1,  1429,   398,  1281,   136,   100,   595,
    1399,  1394,  1395,    -1,    -1,   288,    -1,   287,  1396,    -1,
    1397,    -1,  1396,     5,  1397,    -1,   937,    -1,   937,   619,
     937,    -1,    25,   619,   937,   619,   937,    -1,  1399,    -1,
    1270,    -1,  1146,    -1,  1401,    -1,  1401,  1395,    -1,    -1,
      -1,   470,  1412,  1402,  1413,  1403,  1409,  1345,  1407,    -1,
     470,  1412,  1413,  1345,  1407,    -1,  1406,    -1,  1424,    -1,
     470,  1412,  1413,  1409,  1345,  1407,    -1,    -1,   524,  1364,
    1405,    -1,  1290,    -1,   331,  1408,  1241,    -1,  1290,   331,
    1408,  1241,    -1,   937,    -1,    -1,   553,  1111,    -1,   470,
    1412,  1413,  1345,    -1,   430,   470,  1412,  1413,  1345,   391,
      -1,    -1,   585,    -1,   359,    -1,   475,    -1,  1414,    -1,
    1413,     5,  1414,    -1,  1416,    -1,  1416,   937,    -1,  1416,
      -1,  1417,    -1,    19,  1417,    -1,    18,  1417,    -1,  1418,
      -1,  1466,    -1,  1411,    -1,   611,   937,    -1,   611,   937,
     619,   937,    -1,  1417,    21,  1416,    -1,  1417,  1438,    -1,
    1417,    20,  1416,    -1,  1417,    18,  1416,    -1,  1417,    19,
    1416,    -1,  1379,    -1,   483,    -1,   427,    -1,   576,    -1,
      20,    -1,    64,    -1,   588,   430,  1364,  1416,   391,    -1,
     600,   430,  1364,  1416,   391,    -1,   601,   430,  1364,  1416,
     391,    -1,   608,   430,  1364,  1416,   391,    -1,   495,   430,
    1364,  1416,   391,    -1,   937,   430,  1419,   391,    -1,   537,
     430,  1419,   391,    -1,   430,  1416,   391,    -1,   443,   430,
    1439,   391,    -1,  1416,    -1,  1419,     5,  1416,    -1,  1379,
      -1,  1429,   346,  1428,  1423,  1405,    -1,  1429,   335,  1428,
    1423,   248,  1373,  1425,    -1,  1429,   335,  1428,  1423,  1089,
      -1,    -1,   321,  1424,    -1,    25,    -1,  1089,    -1,    -1,
     430,  1426,   391,    -1,  1427,    -1,  1426,     5,  1427,    -1,
     937,    -1,    25,    -1,  1089,    -1,    -1,   267,  1430,   595,
      -1,   938,    -1,  1436,    -1,  1435,    -1,  1432,    -1,   316,
    1433,   625,  1433,    -1,   297,  1433,   619,  1434,   625,  1434,
      -1,   937,    -1,   937,    -1,   221,   787,    -1,   292,   787,
    1437,    -1,   271,    -1,   174,    -1,    92,    -1,    93,    -1,
      94,    -1,    95,    -1,    96,    -1,    97,    -1,   395,     5,
    1386,   625,  1387,    -1,  1466,     5,  1386,   625,  1387,    -1,
     395,  1386,   625,  1387,    -1,    -1,   607,  1441,  1442,   189,
      -1,  1443,    -1,  1442,  1443,    -1,    33,    -1,  1444,    -1,
    1445,    -1,   190,  1466,    -1,   553,  1111,    -1,    -1,    -1,
     477,  1373,  1447,  1450,  1448,  1449,    -1,    -1,   149,   931,
      -1,   525,  1349,    -1,    52,  1454,   391,    14,   430,  1455,
     391,    -1,    48,  1455,   391,    -1,    49,  1455,   391,    -1,
     583,  1451,    -1,    51,  1455,    -1,    50,  1455,    -1,  1453,
      -1,  1451,     5,  1453,    -1,  1376,    -1,  1452,    14,  1456,
      -1,  1452,    -1,  1454,     5,  1452,    -1,  1456,    -1,  1455,
       5,  1456,    -1,   482,    -1,  1457,    -1,  1458,    -1,    19,
    1458,    -1,    18,  1458,    -1,  1460,    -1,  1411,    -1,   611,
     937,    -1,   611,   937,   619,   937,    -1,  1459,    -1,  1379,
      -1,   483,    -1,   427,    -1,   576,    -1,    64,    -1,  1458,
      21,  1457,    -1,  1458,  1438,    -1,  1458,    20,  1457,    -1,
    1458,    18,  1457,    -1,  1458,    19,  1457,    -1,   588,   430,
    1364,  1457,   391,    -1,   600,   430,  1364,  1457,   391,    -1,
     601,   430,  1364,  1457,   391,    -1,   608,   430,  1364,  1457,
     391,    -1,   495,   430,  1364,  1457,   391,    -1,   937,   430,
    1461,   391,    -1,   537,   430,  1461,   391,    -1,   430,  1457,
     391,    -1,   443,   430,  1439,   391,    -1,  1466,    -1,  1457,
      -1,  1461,     5,  1457,    -1,  1463,    -1,   190,  1464,    -1,
    1464,    -1,  1098,    -1,   937,    -1,  1464,   619,  1465,    -1,
      25,   619,  1464,   619,  1465,    -1,    20,    -1,  1119,    -1,
     937,    -1,  1463,    -1,  1463,   420,  1463,    -1,   126,  1468,
      -1,   130,  1468,    -1,   125,  1468,    -1,    46,    -1,   165,
    1468,    -1,   123,  1468,    -1,    47,    -1,   148,  1468,    -1,
     147,  1468,    -1,   122,  1468,    -1,   355,    -1,   620,   625,
    1469,    -1,   547,  1469,    -1,   572,    -1,   533,  1470,    -1,
     937,    -1,   589,   937,    -1,   937,    -1,    -1,    -1,   526,
    1472,   844,  1473,  1487,   325,    -1,    -1,   658,  1477,    -1,
      -1,   661,    -1,   181,    -1,   277,   932,    -1,    69,   932,
      -1,   307,    -1,   306,    -1,   308,   934,  1474,  1475,    -1,
     492,  1477,  1475,    -1,   929,    -1,  1477,     5,   929,    -1,
     102,    -1,   132,   932,    -1,   844,   566,     5,   844,   392,
      -1,   508,   844,    -1,   264,   932,    -1,   101,  1482,     8,
    1483,  1481,    -1,    -1,   546,   844,    -1,   937,    -1,   937,
      -1,   247,   932,    -1,   250,   932,   625,   844,     5,   844,
      -1,   250,   932,   618,   844,     5,   844,    -1,    27,    -1,
      -1,  1489,    -1,  1490,  1195,    -1,  1488,    -1,  1489,  1488,
      -1,    -1,  1491,  1492,    -1,   668,    -1,   669,    -1,   670,
      -1,   671,    -1,   688,    -1,   710,    -1,   724,    -1,   725,
      -1,   731,    -1,   732,    -1,   751,    -1,   819,    -1,   820,
      -1,   821,    -1,   822,    -1,   833,    -1,   834,    -1,   835,
      -1,   836,    -1,   888,    -1,   892,    -1,   923,    -1,   944,
      -1,   945,    -1,   948,    -1,   949,    -1,   950,    -1,   951,
      -1,   964,    -1,   972,    -1,   993,    -1,   994,    -1,   996,
      -1,  1000,    -1,  1015,    -1,  1016,    -1,  1020,    -1,  1021,
      -1,  1022,    -1,  1023,    -1,  1031,    -1,  1046,    -1,  1059,
      -1,  1070,    -1,  1071,    -1,  1072,    -1,  1083,    -1,  1122,
      -1,  1125,    -1,  1127,    -1,  1133,    -1,  1134,    -1,  1137,
      -1,  1140,    -1,  1143,    -1,  1145,    -1,  1147,    -1,  1149,
      -1,  1156,    -1,  1161,    -1,  1165,    -1,  1166,    -1,  1167,
      -1,  1179,    -1,  1231,    -1,  1232,    -1,  1234,    -1,  1246,
      -1,  1247,    -1,  1265,    -1,  1268,    -1,  1298,    -1,  1300,
      -1,  1389,    -1,  1390,    -1,  1421,    -1,  1422,    -1,  1440,
      -1,  1467,    -1,  1471,    -1,  1476,    -1,  1478,    -1,  1480,
      -1,  1484,    -1,  1485,    -1
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
    3141,  3165,  3166,  3178,  3184,  3178,  3198,  3198,  3200,  3201,
    3205,  3205,  3209,  3209,  3214,  3214,  3221,  3222,  3226,  3226,
    3230,  3230,  3235,  3235,  3242,  3246,  3247,  3248,  3253,  3253,
    3256,  3256,  3260,  3260,  3264,  3264,  3268,  3268,  3273,  3273,
    3278,  3278,  3283,  3283,  3288,  3288,  3304,  3321,  3322,  3323,
    3324,  3325,  3326,  3329,  3329,  3332,  3334,  3337,  3340,  3342,
    3343,  3344,  3346,  3348,  3350,  3352,  3356,  3363,  3365,  3371,
    3376,  3381,  3386,  3386,  3389,  3395,  3400,  3403,  3410,  3410,
    3412,  3413,  3415,  3417,  3419,  3421,  3425,  3434,  3434,  3496,
    3508,  3515,  3515,  3519,  3524,  3530,  3534,  3538,  3544,  3548,
    3552,  3558,  3558,  3566,  3567,  3571,  3571,  3575,  3576,  3579,
    3582,  3582,  3585,  3587,  3587,  3590,  3592,  3592,  3593,  3595,
    3595,  3604,  3602,  3614,  3614,  3614,  3617,  3619,  3617,  3626,
    3629,  3635,  3646,  3646,  3650,  3656,  3656,  3660,  3661,  3672,
    3673,  3675,  3677,  3682,  3682,  3686,  3685,  3692,  3691,  3697,
    3697,  3702,  3702,  3708,  3708,  3713,  3713,  3718,  3718,  3723,
    3723,  3726,  3726,  3729,  3729,  3732,  3732,  3774,  3775,  3783,
    3784,  3793,  3798,  3803,  3804,  3805,  3809,  3808,  3819,  3824,
    3829,  3829,  3845,  3851,  3852,  3853,  3854,  3857,  3857,  3860,
    3867,  3868,  3869,  3870,  3871,  3872,  3873,  3874,  3875,  3880,
    3880,  3882,  3885,  3885,  3887,  3891,  3894,  3895,  3898,  3898,
    3903,  3906,  3907,  3908,  3909,  3910,  3911,  3912,  3913,  3914,
    3915,  3916,  3917,  3918,  3919,  3920,  3921,  3922,  3926,  3944,
    3944,  3944,  3971,  3982,  3989,  3995,  4001,  4007,  4018,  4041,
    4040,  4057,  4057,  4061,  4062,  4070,  4071,  4072,  4073,  4080,
    4081,  4083,  4084,  4088,  4093,  4094,  4095,  4096,  4097,  4098,
    4099,  4100,  4101,  4102,  4103,  4106,  4106,  4108,  4108,  4108,
    4110,  4114,  4114,  4123,  4128,  4144,  4150,  4122,  4164,  4178,
    4188,  4177,  4201,  4208,  4208,  4213,  4219,  4227,  4232,  4233,
    4236,  4236,  4236,  4239,  4239,  4247,  4253,  4267,  4271,  4284,
    4266,  4302,  4302,  4316,  4327,  4326,  4338,  4334,  4351,  4348,
    4361,  4361,  4363,  4364,  4366,  4367,  4370,  4371,  4372,  4374,
    4379,  4384,  4390,  4392,  4393,  4396,  4397,  4400,  4402,  4411,
    4417,  4411,  4428,  4429,  4433,  4433,  4443,  4443,  4455,  4458,
    4461,  4464,  4468,  4472,  4473,  4474,  4475,  4476,  4480,  4485,
    4485,  4488,  4514,  4573,  4573,  4576,  4580,  4584,  4627,  4669,
    4670,  4671,  4674,  4688,  4700,  4700,  4705,  4706,  4712,  4772,
    4829,  4834,  4841,  4846,  4854,  4860,  4894,  4897,  4898,  4939,
    4982,  4983,  4987,  4988,  4992,  5045,  5049,  5052,  5058,  5069,
    5076,  5084,  5084,  5087,  5088,  5089,  5090,  5091,  5094,  5097,
    5103,  5106,  5110,  5114,  5121,  5126,  5133,  5136,  5142,  5144,
    5144,  5144,  5148,  5168,  5175,  5182,  5185,  5199,  5206,  5207,
    5210,  5211,  5215,  5221,  5226,  5232,  5233,  5238,  5242,  5242,
    5246,  5247,  5250,  5251,  5255,  5263,  5266,  5272,  5273,  5275,
    5277,  5281,  5281,  5282,  5287,  5295,  5296,  5301,  5302,  5304,
    5317,  5319,  5320,  5322,  5325,  5328,  5331,  5335,  5338,  5341,
    5345,  5349,  5353,  5356,  5360,  5363,  5364,  5365,  5368,  5371,
    5374,  5377,  5380,  5383,  5386,  5402,  5410,  5410,  5412,  5419,
    5426,  5441,  5439,  5459,  5464,  5465,  5469,  5470,  5472,  5473,
    5475,  5475,  5483,  5492,  5492,  5502,  5503,  5506,  5507,  5510,
    5514,  5528,  5533,  5538,  5543,  5553,  5553,  5557,  5560,  5560,
    5562,  5572,  5581,  5588,  5590,  5594,  5597,  5597,  5601,  5600,
    5604,  5603,  5607,  5606,  5610,  5609,  5613,  5612,  5615,  5615,
    5631,  5630,  5652,  5653,  5654,  5655,  5656,  5657,  5660,  5660,
    5666,  5666,  5669,  5669,  5679,  5680,  5681,  5688,  5700,  5701,
    5704,  5705,  5708,  5711,  5711,  5716,  5720,  5725,  5731,  5732,
    5733,  5737,  5738,  5739,  5740,  5744,  5754,  5756,  5761,  5764,
    5769,  5775,  5782,  5789,  5798,  5805,  5812,  5819,  5826,  5835,
    5835,  5837,  5837,  5840,  5841,  5842,  5843,  5844,  5845,  5846,
    5847,  5848,  5849,  5852,  5852,  5855,  5856,  5857,  5858,  5861,
    5861,  5864,  5864,  5867,  5868,  5869,  5870,  5871,  5872,  5873,
    5874,  5876,  5877,  5878,  5879,  5881,  5882,  5883,  5884,  5886,
    5887,  5888,  5889,  5890,  5891,  5892,  5893,  5897,  5903,  5911,
    5922,  5931,  5942,  5946,  5950,  5956,  5921,  5969,  5972,  5980,
    5992,  5994,  5999,  6007,  6017,  6020,  6024,  6032,  5998,  6041,
    6045,  6049,  6053,  6045,  6063,  6064,  6065,  6066,  6071,  6073,
    6076,  6080,  6083,  6090,  6095,  6096,  6097,  6102,  6103,  6109,
    6109,  6109,  6114,  6114,  6114,  6125,  6126,  6132,  6133,  6145,
    6146,  6151,  6152,  6153,  6157,  6160,  6166,  6169,  6177,  6178,
    6184,  6191,  6194,  6203,  6206,  6209,  6212,  6215,  6218,  6221,
    6228,  6231,  6238,  6241,  6247,  6250,  6257,  6260,  6267,  6268,
    6273,  6277,  6280,  6286,  6289,  6295,  6302,  6303,  6307,  6313,
    6316,  6323,  6324,  6331,  6334,  6339,  6350,  6351,  6352,  6353,
    6354,  6355,  6356,  6357,  6358,  6361,  6364,  6370,  6370,  6376,
    6376,  6387,  6400,  6410,  6410,  6415,  6415,  6419,  6423,  6424,
    6430,  6431,  6436,  6440,  6447,  6450,  6457,  6461,  6456,  6470,
    6474,  6478,  6485,  6489,  6489,  6502,  6506,  6506,  6521,  6523,
    6525,  6527,  6529,  6531,  6533,  6535,  6541,  6551,  6558,  6563,
    6564,  6568,  6570,  6571,  6574,  6575,  6576,  6579,  6584,  6591,
    6592,  6598,  6610,  6611,  6614,  6614,  6619,  6624,  6629,  6630,
    6633,  6634,  6639,  6644,  6648,  6653,  6654,  6658,  6665,  6669,
    6670,  6675,  6677,  6681,  6682,  6686,  6687,  6688,  6689,  6693,
    6694,  6699,  6700,  6705,  6706,  6711,  6712,  6717,  6722,  6723,
    6728,  6729,  6733,  6734,  6739,  6746,  6751,  6756,  6760,  6761,
    6766,  6767,  6773,  6775,  6780,  6781,  6787,  6790,  6793,  6800,
    6802,  6816,  6821,  6822,  6825,  6827,  6834,  6837,  6843,  6847,
    6851,  6855,  6858,  6865,  6872,  6877,  6881,  6882,  6888,  6891,
    6902,  6909,  6915,  6918,  6925,  6932,  6938,  6939,  6945,  6946,
    6947,  6950,  6951,  6956,  6956,  6960,  6968,  6969,  6972,  6975,
    6980,  6981,  6986,  6989,  6995,  6998,  7004,  7007,  7013,  7016,
    7023,  7024,  7053,  7054,  7059,  7067,  7072,  7075,  7078,  7081,
    7087,  7088,  7092,  7095,  7098,  7099,  7104,  7107,  7110,  7113,
    7116,  7119,  7122,  7128,  7129,  7130,  7131,  7132,  7134,  7136,
    7137,  7142,  7145,  7149,  7155,  7156,  7157,  7158,  7170,  7171,
    7172,  7176,  7177,  7182,  7184,  7185,  7186,  7188,  7189,  7190,
    7191,  7193,  7194,  7196,  7197,  7199,  7200,  7201,  7202,  7204,
    7208,  7209,  7215,  7217,  7218,  7219,  7220,  7225,  7229,  7233,
    7237,  7238,  7242,  7243,  7253,  7262,  7263,  7264,  7268,  7271,
    7276,  7281,  7286,  7294,  7298,  7302,  7303,  7304,  7309,  7312,
    7315,  7329,  7343,  7356,  7357,  7361,  7361,  7361,  7361,  7361,
    7361,  7362,  7365,  7370,  7370,  7370,  7370,  7370,  7370,  7372,
    7375,  7381,  7381,  7381,  7381,  7381,  7381,  7381,  7382,  7382,
    7382,  7382,  7382,  7382,  7382,  7384,  7385,  7388,  7397,  7397,
    7403,  7403,  7410,  7410,  7416,  7416,  7424,  7425,  7426,  7429,
    7429,  7432,  7433,  7434,  7439,  7442,  7448,  7453,  7461,  7474,
    7475,  7472,  7493,  7503,  7506,  7511,  7523,  7526,  7530,  7533,
    7534,  7540,  7543,  7544,  7553,  7562,  7567,  7568,  7569,  7570,
    7577,  7580,  7586,  7589,  7599,  7608,  7611,  7614,  7620,  7626,
    7629,  7632,  7635,  7641,  7643,  7645,  7647,  7649,  7651,  7652,
    7653,  7654,  7655,  7656,  7657,  7659,  7661,  7663,  7665,  7667,
    7669,  7671,  7672,  7677,  7678,  7685,  7688,  7697,  7701,  7708,
    7708,  7712,  7712,  7717,  7717,  7721,  7721,  7725,  7731,  7731,
    7734,  7734,  7740,  7747,  7748,  7749,  7753,  7754,  7757,  7758,
    7762,  7768,  7778,  7779,  7787,  7788,  7789,  7790,  7791,  7792,
    7796,  7797,  7798,  7802,  7802,  7814,  7815,  7819,  7820,  7821,
    7825,  7831,  7918,  7922,  7918,  7931,  7935,  7941,  7949,  7959,
    7969,  7981,  7984,  8003,  8029,  8032,  8038,  8041,  8046,  8049,
    8057,  8065,  8078,  8081,  8089,  8092,  8095,  8103,  8107,  8110,
    8113,  8116,  8120,  8121,  8122,  8123,  8124,  8130,  8131,  8132,
    8133,  8134,  8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,
    8143,  8147,  8153,  8154,  8166,  8187,  8187,  8191,  8192,  8193,
    8194,  8198,  8199,  8200,  8205,  8231,  8282,  8284,  8286,  8288,
    8292,  8297,  8299,  8302,  8304,  8306,  8310,  8313,  8318,  8323,
    8327,  8336,  8337,  8341,  8353,  8356,  8352,  8375,  8375,  8379,
    8380,  8383,  8384,  8385,  8386,  8387,  8388,  8389,  8394,  8395,
    8399,  8402,  8407,  8411,  8416,  8420,  8425,  8429,  8432,  8436,
    8439,  8444,  8448,  8459,  8465,  8465,  8466,  8467,  8474,  8483,
    8483,  8485,  8486,  8487,  8488,  8489,  8490,  8491,  8492,  8493,
    8494,  8495,  8496,  8497,  8498,  8499,  8500,  8501,  8502,  8503,
    8504,  8505,  8506,  8507,  8508,  8509,  8510,  8511,  8512,  8513,
    8514,  8515,  8516,  8517,  8518,  8519,  8520,  8521,  8522,  8523,
    8524,  8525,  8526,  8527,  8528,  8529,  8530,  8531,  8532,  8533,
    8534,  8535,  8536,  8537,  8538,  8539,  8540,  8541,  8542,  8543,
    8544,  8545,  8546,  8547,  8548,  8549,  8550,  8551,  8552,  8553,
    8554,  8555,  8556,  8557,  8558,  8559,  8560,  8561,  8562,  8563,
    8564,  8565,  8566,  8567,  8568,  8569
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
  "UNCHECK_MENUITEM", "BEFORE", "INPUT", "END", "INT_TO_ID", "$accept", 
  "pause_screen_on_cmd", "pause_screen_off_cmd", "start_rpc_cmd", 
  "stop_rpc_cmd", "valid_port", "remote_func_list", "remote_func", 
  "arr_expr", "arr_next_math", "arr_int_sign", "opt_attributes", 
  "attributes_def", "@1", "attribs_sec", "attribute", "win_attributes", 
  "win_attributes_def", "@2", "wattribs_sec", "wattribute", "call_cmd", 
  "call_ext", "@3", "@4", "@5", "@6", "@7", "@8", "@9", "@10", "@11", 
  "@12", "@13", "@14", "@15", "opt_return", "opt_return_remote", 
  "opt_func_call_args", "func_call_args", "func_arg", "remote_host_name", 
  "remote_func_name", "case_cmd", "@16", "@17", "when_unit", 
  "when_unit_expr", "end_case_command", "op_otherwise_command", "@18", 
  "op_otherwise_command_expr", "@19", "when_command", "@20", 
  "when_command_expr", "@21", "close_cmd", "code_cmd", "emb_code", 
  "sql_code", "sql_code_part", "c_code", "c_code_part", "comment_cmd", 
  "construct_cmd", "@22", "@23", "constr_rest", "end_constr", 
  "constr_col_list", "constr_col", "constr_extra_commands", 
  "constr_extra_command", "@24", "@25", "@26", "@27", "@28", 
  "bef_c_field_list", "aft_c_field_list", "interval_expr", 
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
    1379,  1486,  1482,  1397,  1559,  1296,  1354,  1428,  1595,  1582,
    1487,  1515,  1583,  1361,  1655,  1656,  1657,  1658,  1659,  1660,
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
    1045,  1043,  1046,  1047,  1047,  1048,  1048,  1049,  1050,  1050,
    1051,  1051,  1051,  1053,  1052,  1054,  1054,  1056,  1057,  1058,
    1055,  1060,  1059,  1061,  1063,  1062,  1064,  1062,  1065,  1062,
    1066,  1066,  1067,  1067,  1068,  1068,  1069,  1069,  1069,  1070,
    1071,  1072,  1073,  1073,  1073,  1074,  1074,  1075,  1075,  1077,
    1078,  1076,  1079,  1079,  1081,  1080,  1082,  1080,  1083,  1084,
    1084,  1084,  1084,  1085,  1085,  1085,  1085,  1085,  1086,  1087,
    1087,  1088,  1089,  1090,  1090,  1091,  1092,  1092,  1092,  1092,
    1092,  1092,  1093,  1094,  1095,  1095,  1096,  1096,  1097,  1098,
    1099,  1099,  1100,  1100,  1101,  1102,  1103,  1103,  1103,  1103,
    1103,  1103,  1104,  1104,  1105,  1106,  1106,  1107,  1107,  1108,
    1108,  1109,  1109,  1110,  1110,  1110,  1110,  1110,  1111,  1111,
    1112,  1112,  1113,  1113,  1114,  1115,  1116,  1116,  1117,  1118,
    1118,  1118,  1119,  1120,  1120,  1121,  1121,  1122,  1123,  1123,
    1124,  1124,  1125,  1126,  1127,  1128,  1128,  1129,  1130,  1130,
    1131,  1131,  1132,  1132,  1133,  1134,  1134,  1135,  1135,  1135,
    1135,  1136,  1136,  1136,  1137,  1138,  1138,  1139,  1139,  1139,
    1140,  1141,  1141,  1142,  1142,  1142,  1142,  1142,  1142,  1142,
    1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,  1142,
    1142,  1142,  1142,  1142,  1142,  1143,  1144,  1144,  1145,  1145,
    1146,  1148,  1147,  1149,  1150,  1150,  1151,  1151,  1152,  1152,
    1154,  1153,  1155,  1157,  1156,  1158,  1158,  1159,  1159,  1160,
    1160,  1161,  1161,  1161,  1161,  1162,  1162,  1163,  1164,  1164,
    1165,  1166,  1167,  1168,  1169,  1169,  1170,  1170,  1172,  1171,
    1173,  1171,  1174,  1171,  1175,  1171,  1176,  1171,  1177,  1171,
    1178,  1171,  1179,  1179,  1179,  1179,  1179,  1179,  1181,  1180,
    1182,  1182,  1184,  1183,  1183,  1183,  1183,  1183,  1185,  1185,
    1186,  1186,  1187,  1188,  1188,  1189,  1190,  1191,  1192,  1192,
    1192,  1193,  1193,  1193,  1193,  1194,  1195,  1195,  1196,  1196,
    1197,  1198,  1198,  1198,  1198,  1198,  1198,  1198,  1198,  1199,
    1199,  1200,  1200,  1201,  1201,  1201,  1201,  1201,  1201,  1201,
    1201,  1201,  1201,  1202,  1202,  1203,  1203,  1203,  1203,  1204,
    1204,  1205,  1205,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,  1206,
    1206,  1206,  1206,  1206,  1206,  1206,  1206,  1207,  1207,  1207,
    1209,  1210,  1211,  1212,  1213,  1214,  1208,  1215,  1215,  1216,
    1217,  1217,  1219,  1220,  1221,  1222,  1223,  1224,  1218,  1225,
    1227,  1228,  1229,  1226,  1230,  1230,  1230,  1230,  1231,  1231,
    1231,  1231,  1231,  1232,  1233,  1233,  1233,  1234,  1234,  1236,
    1237,  1235,  1238,  1239,  1235,  1240,  1240,  1241,  1241,  1242,
    1242,  1243,  1243,  1243,  1244,  1244,  1245,  1245,  1246,  1246,
    1247,  1248,  1248,  1249,  1249,  1249,  1249,  1249,  1249,  1249,
    1250,  1250,  1251,  1251,  1252,  1252,  1253,  1253,  1254,  1254,
    1255,  1256,  1256,  1257,  1257,  1258,  1259,  1259,  1260,  1261,
    1261,  1262,  1262,  1263,  1263,  1264,  1265,  1265,  1265,  1265,
    1265,  1265,  1265,  1265,  1265,  1265,  1265,  1266,  1266,  1267,
    1267,  1268,  1269,  1271,  1270,  1273,  1272,  1272,  1274,  1274,
    1275,  1275,  1276,  1276,  1277,  1277,  1279,  1280,  1278,  1281,
    1282,  1282,  1283,  1284,  1283,  1285,  1286,  1285,  1287,  1287,
    1287,  1287,  1287,  1287,  1287,  1287,  1288,  1289,  1290,  1291,
    1291,  1292,  1293,  1293,  1294,  1294,  1294,  1295,  1296,  1297,
    1297,  1298,  1299,  1299,  1301,  1300,  1302,  1302,  1302,  1302,
    1302,  1302,  1302,  1302,  1302,  1302,  1302,  1302,  1303,  1304,
    1304,  1305,  1305,  1306,  1306,  1307,  1307,  1307,  1307,  1308,
    1308,  1309,  1309,  1310,  1310,  1311,  1311,  1312,  1313,  1313,
    1314,  1314,  1315,  1315,  1316,  1317,  1318,  1319,  1320,  1320,
    1321,  1321,  1322,  1322,  1323,  1323,  1324,  1324,  1324,  1325,
    1325,  1326,  1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,
    1330,  1330,  1330,  1331,  1332,  1333,  1334,  1334,  1335,  1335,
    1336,  1337,  1338,  1338,  1339,  1340,  1341,  1341,  1342,  1342,
    1342,  1343,  1343,  1344,  1344,  1345,  1346,  1346,  1347,  1347,
    1348,  1348,  1349,  1349,  1350,  1350,  1351,  1351,  1352,  1352,
    1353,  1353,  1354,  1354,  1355,  1356,  1357,  1357,  1357,  1357,
    1358,  1358,  1359,  1359,  1360,  1360,  1361,  1361,  1361,  1361,
    1361,  1361,  1361,  1362,  1362,  1362,  1362,  1362,  1362,  1362,
    1362,  1363,  1363,  1363,  1364,  1364,  1364,  1364,  1365,  1365,
    1365,  1366,  1366,  1367,  1367,  1367,  1367,  1367,  1367,  1367,
    1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,  1367,
    1368,  1368,  1369,  1369,  1369,  1369,  1369,  1370,  1371,  1372,
    1373,  1373,  1373,  1373,  1374,  1375,  1375,  1375,  1376,  1376,
    1377,  1377,  1377,  1378,  1379,  1379,  1379,  1379,  1379,  1380,
    1381,  1382,  1382,  1383,  1383,  1384,  1384,  1384,  1384,  1384,
    1384,  1384,  1384,  1385,  1385,  1385,  1385,  1385,  1385,  1385,
    1385,  1386,  1386,  1386,  1386,  1386,  1386,  1386,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1388,  1388,  1389,  1391,  1390,
    1392,  1390,  1393,  1390,  1394,  1390,  1395,  1395,  1395,  1396,
    1396,  1397,  1397,  1397,  1398,  1398,  1399,  1399,  1400,  1402,
    1403,  1401,  1404,  1405,  1405,  1406,  1407,  1407,  1407,  1407,
    1407,  1408,  1409,  1409,  1410,  1411,  1412,  1412,  1412,  1412,
    1413,  1413,  1414,  1414,  1415,  1416,  1416,  1416,  1417,  1417,
    1417,  1417,  1417,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,  1418,
    1418,  1418,  1418,  1419,  1419,  1420,  1421,  1422,  1422,  1423,
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
       1,     3,     1,     3,     1,     1,     0,     0,     5,     1,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     1,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     7,     0,
       1,     1,     1,     1,     3,     1,     1,     1,     2,     0,
       3,     1,     3,     1,     3,     1,     1,     6,     0,     3,
       1,     3,     0,     1,     4,     5,     2,     1,     1,     4,
       1,     3,     4,     4,     1,     3,     1,     1,     1,     2,
       1,     4,     0,     1,     0,     1,     1,     2,     1,     1,
       1,     1,     4,     3,     1,     1,     1,     2,     1,     1,
       2,     2,     1,     3,     2,     2,     1,     3,     1,     2,
       4,     1,     2,     1,     3,     4,     0,     1,     0,     1,
       0,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       2,     2,     0,     2,     1,     1,     5,     3,     5,     3,
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
       4,     3,     4,     1,     3,     1,     5,     7,     5,     0,
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
     781,     0,  1759,  1762,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   833,   179,     0,   805,   810,
     177,   182,   785,     0,   779,   782,   783,   786,   788,   832,
     787,   827,   828,   830,   183,   134,   131,     0,   127,   129,
     128,   132,  1803,   671,   614,  1766,     0,     0,  1769,     0,
    1765,  1761,  1758,  1756,  1757,  1764,  1763,  1760,   294,  1566,
    1565,   825,   175,   186,   826,   178,   183,     1,   789,   784,
     831,   829,   806,   126,   130,   133,  1773,  1770,     0,  1771,
    1768,     0,     0,   593,     0,     0,   176,   836,   900,   594,
     834,   626,   892,     0,   893,   901,   899,   186,   180,   199,
       0,   184,   200,   229,     0,   812,  1182,     0,     0,   811,
     135,  1170,   819,     0,     0,   802,   804,   801,   803,   780,
     790,   791,   813,   794,   795,   796,   799,   797,   798,   800,
    1772,  1767,     0,   894,   835,     0,     0,   908,   906,   907,
     896,   895,   292,   186,  1106,   193,   187,   186,   192,   226,
       0,   670,     0,     0,     0,     0,   175,   543,   869,   792,
       0,   326,   312,   202,   263,   282,   303,   305,   302,     0,
     324,     0,   311,   304,   308,   314,   298,   313,   186,   315,
     295,   318,   296,   297,   905,   904,     0,    21,    22,    13,
       0,   914,     0,    15,     0,   912,     0,   293,     0,   185,
    1107,   181,     0,   199,   201,   259,   253,   254,   242,   219,
     250,   202,   221,   263,   282,   240,   243,   238,     0,   217,
       0,   249,   241,   246,   252,   234,   251,   186,   255,   186,
     232,   233,   230,   258,     0,     0,     0,     0,   820,   175,
     175,     0,     0,   203,     0,   316,     0,     0,   317,     0,
       0,     0,     0,     0,     0,     0,     0,   261,     0,   902,
       0,    16,    17,    18,    19,    20,     0,    14,     0,   910,
       0,   627,   188,   191,     0,   189,   190,     0,   196,   195,
     194,   197,   186,     0,   186,   256,   257,     0,     0,   186,
       0,     0,     0,     0,   239,   227,  1183,     0,     0,  1171,
    1809,   544,   870,   814,     0,   208,   209,     0,   275,   277,
     272,   273,   269,   271,   268,   270,   267,     0,   277,   288,
     289,   285,   287,   284,   286,   279,     0,     0,     0,   328,
       0,   331,   333,   216,     0,   215,     0,     0,   186,    11,
      12,   913,     0,   897,   628,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   186,   228,   231,   925,   669,
     837,   925,     0,  1807,  1809,  1106,  1660,   807,     0,   925,
       0,     0,   264,     0,     0,   274,   291,   265,   290,     0,
     283,     0,   306,     0,   300,     0,   325,     0,   330,   320,
       0,     0,   309,   299,   262,   319,     0,     0,     0,     0,
       0,     0,   244,     0,   236,   218,   204,     0,   247,   235,
     260,   931,     0,   926,   927,   925,     0,   821,  1808,  1806,
       0,     0,     0,     0,     0,     0,     0,     0,  1790,     0,
    1272,  1271,     0,  1273,     0,   376,  1270,  1212,     0,     5,
    1269,   377,   374,     0,   379,   173,   469,  1084,     0,     0,
    1279,   123,   373,   372,  1204,   367,   469,     0,  1229,  1781,
       0,   378,   345,     0,     3,     2,     0,   375,  1209,     0,
       0,   368,   365,   380,     0,     0,     0,     0,  1277,  1267,
     371,     0,     0,     0,     0,     0,     0,     0,     0,  1266,
       0,     0,     0,   174,  1206,   364,   363,     0,     0,  1785,
    1784,     0,     0,     0,   136,  1205,   370,   369,     0,     0,
     366,   469,   469,     0,   537,     0,     0,     0,     0,     0,
       0,   469,   768,  1180,     0,     0,  1088,     0,  1774,     0,
     103,     0,     0,   841,     0,     0,     0,     0,   769,     0,
       0,  1683,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   641,     0,     0,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,  1856,
    1857,   879,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,  1874,  1075,
    1077,  1072,  1074,  1073,  1076,  1875,  1876,  1203,  1877,  1208,
    1207,  1878,  1879,  1880,  1881,  1882,  1883,  1884,  1885,  1886,
    1887,  1334,  1888,  1889,  1890,  1891,  1892,  1893,  1894,  1895,
    1810,   808,   548,   809,     0,   874,     0,   872,     0,   327,
     210,   211,     0,   276,   281,     0,     0,     0,     0,   329,
     332,     0,   214,     0,   911,     0,   220,     0,   186,     0,
       0,     0,     0,     0,  1184,     0,     0,  1172,     0,     0,
    1216,   615,   616,   793,  1047,  1052,  1783,   608,   122,     0,
       0,  1748,  1747,   985,  1744,  1746,  1798,     0,  1223,     0,
    1219,  1228,     7,     0,     6,     0,  1791,  1048,     0,  1140,
    1139,  1087,  1138,  1086,     0,     0,     0,   424,   426,     0,
    1177,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1533,     0,     0,     0,   418,     0,     0,     0,     0,
     417,     0,     0,   434,     0,   505,     0,     0,     0,     0,
       0,     0,   413,  1280,     0,   383,   382,   389,   430,   427,
     384,   503,   495,   385,   387,   502,   388,   900,   425,   428,
     433,  1268,   504,   822,   403,  1662,  1274,   124,     0,  1051,
     121,     0,   775,    23,   610,   381,     0,   774,  1044,   776,
       0,  1278,   863,   862,   865,   861,   864,  1800,     0,   859,
       0,   609,   958,   860,  1794,     0,  1782,   120,   955,   672,
     953,     0,   606,  1777,   714,   713,     0,   715,   598,   711,
       0,     0,   968,   611,  1333,  1329,  1332,     0,     0,  1020,
    1018,     0,  1012,  1014,  1013,  1011,  1010,     0,     0,     0,
    1009,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   999,   990,   991,     0,  1032,   411,
      23,  1788,     0,  1779,   125,   607,     0,  1017,  1016,  1181,
    1179,  1105,     0,  1651,  1652,  1106,  1194,  1106,  1089,  1090,
    1093,  1108,  1281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    62,     0,   900,     0,    68,     0,   101,   586,
     629,     0,  1078,   975,  1082,     0,     0,  1033,  1198,     0,
       0,  1085,   633,   630,   631,     0,   635,   636,     0,   638,
     639,     0,   634,   935,   937,     0,     0,   936,   716,   933,
     681,   929,   891,     0,     0,     0,     0,   645,   646,     0,
       0,   889,   886,   887,   883,   884,   885,   878,   882,   881,
       0,     0,     0,     0,     0,     0,   552,   554,   546,   549,
     550,   876,  1809,   871,   873,   815,     0,   278,   280,   307,
     301,     0,     0,   310,   898,     0,   225,     0,   223,   245,
     237,   229,   248,   932,   175,   928,   838,   175,     0,     0,
       0,  1256,  1257,     0,     0,     0,  1230,  1231,  1233,  1234,
    1235,  1239,  1238,  1236,  1237,     0,     0,  1745,   909,     0,
     987,     0,     0,  1222,  1221,     0,  1215,     0,  1511,  1512,
       0,  1049,     0,    23,  1135,  1137,  1136,   416,   391,   390,
       0,     0,  1112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,  1541,  1539,  1540,  1536,  1538,  1535,  1537,
    1529,     0,     0,     0,     0,     0,   431,     0,     0,   509,
     508,     0,     0,   479,   476,   485,     0,   482,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   510,   511,   512,   445,     0,     0,
     444,   454,     0,     0,   395,     0,     0,   396,   386,   392,
     394,   397,   398,   399,   400,   401,   393,   423,   422,   470,
       0,     0,   406,   407,   404,   405,   945,     0,     0,   350,
      24,   344,     0,     0,  1041,     0,     0,     0,     0,     0,
       0,     0,   962,  1661,     0,     0,   186,     0,     0,     0,
    1779,     0,     0,     0,     0,     0,   137,     0,     0,   972,
     964,   965,   970,  1330,  1331,   888,   409,   334,     0,   538,
     591,   590,   588,   993,   592,   998,   994,   997,   767,   760,
     754,   765,   766,   752,   753,   761,   756,   755,   764,   759,
     762,   758,   763,   751,   757,   744,   750,   995,   996,     0,
    1003,  1007,  1000,  1001,  1005,  1006,  1004,  1002,  1008,     0,
     777,     0,     0,     0,     0,     0,     0,   726,   725,   722,
    1780,  1787,    23,  1101,  1102,  1103,  1104,  1098,  1096,  1195,
    1110,  1095,  1091,     0,     0,  1092,  1775,     0,     0,     0,
       0,    97,     0,    98,     0,     0,     0,    73,     0,     0,
       0,   110,   105,     0,   868,     0,   867,     0,   469,  1080,
       0,   920,   921,   944,   915,   916,   770,   942,  1035,  1200,
       0,  1202,  1201,  1687,     0,     0,     0,  1685,  1688,  1689,
     661,     0,     0,     0,   650,   681,   681,   679,     0,     0,
     682,     0,    25,   649,   652,     0,   659,   655,   890,   880,
    1658,  1659,  1649,  1649,  1299,     0,     0,  1567,     0,   186,
    1282,     0,     0,  1283,  1327,   186,     0,  1328,     0,  1606,
       0,  1296,     0,  1345,  1344,  1343,  1341,  1342,  1340,  1338,
    1335,  1409,  1408,  1336,  1337,  1346,  1576,  1339,  1665,  1664,
    1663,  1347,  1809,  1809,   565,   556,   547,     0,   551,  1809,
     875,   175,     0,   321,   213,     0,   186,   222,   205,  1185,
     175,  1173,  1399,     0,  1398,     0,  1400,     0,  1401,  1259,
       0,  1265,  1261,  1258,     0,     0,     0,     0,     0,     0,
    1255,  1251,  1388,  1387,  1386,  1227,  1226,     0,  1250,  1246,
       0,  1242,  1240,     0,   619,     0,   618,     0,   986,     0,
       0,   984,  1751,  1753,  1752,  1749,  1799,  1796,  1220,     0,
       0,     0,  1213,   469,   342,     0,  1178,     0,     0,     0,
       0,  1606,     0,     0,     0,     0,     0,   527,   513,   518,
       0,   514,   517,   516,     0,     0,     0,     0,     0,     0,
     419,     0,   171,     0,   435,     0,     0,     0,     0,     0,
       0,     0,     0,   437,   436,   455,   446,   461,   464,   465,
     462,   468,   467,   466,   456,   457,   458,   459,   460,   402,
     447,   451,   469,   463,   450,   469,    92,     0,   429,     0,
       0,  1210,   977,  1045,  1046,  1043,  1042,     0,   866,     0,
       0,   595,     0,     0,     0,   956,   954,     0,   674,   675,
       0,     0,  1778,  1786,     0,     0,   602,     0,   604,   712,
       0,   141,     0,   966,   973,     0,     0,   981,     0,   337,
       0,     0,     0,     0,    23,  1019,   541,     0,     0,     0,
     745,   746,   992,   778,   412,     0,  1024,  1789,   723,   724,
     361,     0,  1106,     0,  1109,  1094,  1809,     0,     0,     0,
     530,     0,     0,     0,     0,    63,    92,     0,     0,   116,
     111,     0,   106,     0,   113,   107,   852,   844,   850,     0,
    1079,     0,  1081,  1083,     0,     0,   924,     0,     0,     0,
       0,  1034,  1199,  1754,  1690,   940,  1691,   938,  1684,  1686,
    1809,   632,   637,   640,   653,   651,   612,     0,   701,   699,
     705,   703,     0,     0,   697,   741,   695,   691,   689,   739,
     717,     0,   683,   693,   934,   930,     0,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,  1514,     0,
    1404,  1405,  1670,  1368,  1426,     0,     0,  1668,     0,     0,
    1608,  1609,  1607,  1589,  1692,     0,  1351,  1357,  1356,  1355,
    1359,     0,  1352,  1353,     0,  1577,  1588,   553,   555,     0,
       0,   568,   560,   562,     0,   557,   558,     0,     0,   576,
     578,     0,     0,   574,   877,   816,   212,     0,     0,   224,
    1141,   839,  1119,  1376,  1378,     0,  1263,     0,     0,     0,
       0,     0,  1253,     0,     0,  1506,  1504,  1491,  1493,  1489,
       0,  1488,     0,  1497,  1484,  1505,     0,  1496,  1481,  1487,
    1503,  1495,  1392,  1478,  1479,  1480,     0,  1248,  1244,     0,
       0,  1232,   617,     0,     0,     0,     0,     0,  1795,     4,
       8,    10,  1510,  1513,     0,   469,   501,   498,   497,   500,
     496,     0,   421,   507,   492,   492,     0,   515,     0,   519,
       0,   282,  1177,     0,  1534,   499,  1177,   506,   420,   266,
       0,  1177,   480,   477,   486,  1177,   483,  1177,  1177,  1177,
       0,     0,     0,     0,     0,     0,     0,     0,   471,    93,
      94,    96,   473,   408,     0,     0,     0,   974,     0,     0,
       0,     0,     0,     0,     0,   186,   673,     0,   599,   601,
       0,     0,   158,   156,     0,     0,   138,     0,   148,   154,
     681,   143,   145,     0,   971,   982,   983,     0,   410,   336,
     341,   597,   335,     0,   338,   343,   469,  1305,   589,   587,
       0,   748,  1023,  1025,     0,   362,  1099,  1097,  1196,  1197,
       0,     0,  1190,     0,     0,     0,     0,    99,     0,     0,
      74,    80,    70,  1809,  1809,   109,   104,   118,   114,     0,
     108,   742,   853,   612,  1809,   843,   842,   851,   976,     0,
       0,   922,   923,   917,   943,   469,     0,     0,  1632,  1524,
    1527,  1633,  1531,  1525,  1630,     0,     0,  1040,  1629,     0,
       0,  1631,     0,     0,     0,     0,     0,  1748,  1526,  1036,
    1037,  1628,  1528,  1620,  1039,  1615,  1618,  1619,     0,     0,
       0,   663,   656,   654,     0,    23,     0,  1809,  1809,  1809,
    1809,   707,   685,   709,   687,  1809,  1809,  1809,  1809,     0,
     680,   684,  1809,   612,   737,   735,   738,   736,     0,     0,
      45,    43,    40,    34,    38,    42,    37,    30,    39,     0,
      33,    36,    31,    41,    32,    44,    35,     0,    28,    46,
     729,     0,   660,  1650,     0,  1648,  1606,  1646,  1593,  1594,
    1586,  1572,  1587,     0,     0,     0,  1015,  1403,  1406,     0,
       0,     0,     0,  1427,  1317,  1288,  1673,  1672,  1671,     0,
       0,     0,     0,  1312,     0,  1311,     0,  1313,  1308,  1309,
    1310,  1301,  1297,     0,     0,  1358,     0,     0,     0,  1581,
    1578,  1579,   567,   572,     0,     0,  1809,  1809,   545,   559,
     582,   570,   584,  1809,  1809,   580,   564,   575,   807,   322,
     206,     0,  1167,  1186,   807,     0,  1174,  1167,     0,     0,
    1260,     0,     0,     0,     0,     0,  1432,  1434,  1436,  1473,
    1472,  1471,  1438,  1454,  1262,     0,  1515,     0,  1377,     0,
    1380,  1518,     0,  1384,     0,  1252,     0,     0,  1557,  1555,
    1556,  1552,  1554,  1551,  1553,     0,     0,     0,     0,     0,
       0,     0,     0,  1390,     0,  1393,  1394,     0,  1247,     0,
    1241,  1243,  1750,     0,     0,     0,  1797,     0,     0,  1224,
     823,     0,     0,  1610,  1612,   489,     0,   490,     0,   529,
       0,   526,   523,   494,   488,  1115,  1542,  1114,     0,   170,
    1113,     0,     0,     0,  1116,     0,  1118,  1117,  1111,   448,
     449,   453,   438,     0,   441,   452,     0,   440,     0,     0,
      92,     0,     0,     0,     0,  1275,  1802,  1801,   596,     0,
       0,    47,     0,   678,   677,   676,  1276,     0,     0,   681,
    1809,  1809,   150,   620,   160,   152,   162,   142,   149,  1809,
       0,     0,     0,     0,     0,     0,     0,  1306,   539,     0,
     747,   612,     0,  1776,     0,    92,   531,     0,    64,     0,
       0,     0,    77,     0,    92,    92,   117,   112,  1809,  1809,
     102,     0,   854,   848,   856,   855,   845,   535,   903,     0,
       0,  1617,  1616,  1530,     0,  1606,     0,     0,  1474,     0,
    1474,  1474,  1474,  1474,  1621,     0,     0,     0,     0,     0,
       0,  1674,  1675,  1676,  1677,  1678,  1679,  1624,  1755,   941,
     939,   666,   664,     0,   643,   657,   613,   718,     0,   702,
     700,   706,   704,     0,  1809,     0,  1809,   698,   696,   692,
     690,   740,   694,    23,   730,     0,     0,     0,    26,     0,
    1653,     0,  1576,     0,     0,  1585,  1568,  1584,  1407,     0,
    1370,     0,  1316,  1414,     0,     0,  1669,     0,  1666,  1590,
       0,     0,     0,     0,     0,     0,  1693,  1315,  1314,  1302,
    1300,     0,  1361,     0,  1354,     0,     0,     0,     0,   569,
     566,   561,   563,     0,  1809,  1809,   577,   579,  1809,  1809,
       0,     0,  1165,  1166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1164,     0,     0,  1152,  1153,
    1154,  1151,  1156,  1157,  1158,  1155,  1142,  1133,     0,     0,
    1189,     0,  1809,     0,  1128,     0,     0,     0,     0,     0,
       0,     0,  1120,  1121,     0,  1053,     0,  1264,  1437,     0,
    1441,     0,  1454,  1440,     0,  1402,     0,  1455,  1468,  1465,
    1466,  1463,  1470,  1469,  1464,  1467,     0,     0,     0,     0,
       0,     0,  1519,     0,  1520,     0,     0,     0,     0,  1383,
    1254,  1382,  1374,     0,     0,     0,  1508,  1500,  1500,     0,
       0,  1500,  1507,     0,  1524,  1389,  1391,  1395,  1396,  1249,
    1245,   989,     0,   952,     9,     0,  1217,   824,  1050,     0,
       0,  1426,  1596,  1613,     0,   492,   520,     0,   275,   481,
     478,   487,   484,     0,   443,   442,   472,    95,   474,   348,
    1211,     0,     0,  1793,     0,     0,   957,    48,     0,   603,
     605,   600,   727,   159,   157,     0,  1809,     0,     0,     0,
    1809,   155,   144,     0,   147,   146,     0,   963,   967,   340,
       0,   542,     0,  1809,   749,    23,  1100,     0,  1191,    69,
       0,     0,   100,    67,    92,    75,    81,     0,   119,   115,
     743,  1809,   858,   612,   857,     0,   532,     0,   772,   773,
     771,     0,     0,  1641,     0,     0,     0,  1476,  1477,  1475,
       0,  1643,     0,     0,     0,     0,     0,     0,     0,  1038,
    1626,  1627,  1625,  1623,     0,  1809,   662,   647,   644,     0,
     708,   686,   710,   688,   719,   733,   734,   731,   732,    29,
      27,     0,  1647,  1602,  1573,  1574,  1570,  1576,     0,  1369,
    1606,  1372,     0,  1290,  1285,  1284,  1287,     0,  1602,     0,
       0,  1726,  1724,     0,     0,  1712,  1723,     0,     0,  1725,
       0,     0,     0,     0,     0,  1748,  1722,  1718,     0,  1710,
    1713,  1714,  1721,  1717,  1741,     0,  1703,  1702,  1706,  1708,
       0,  1701,     0,  1704,  1695,  1303,  1298,     0,  1360,     0,
       0,  1582,  1580,   573,   571,   583,   585,   581,     0,     0,
     229,  1159,  1160,  1161,  1163,  1146,  1144,  1143,  1147,  1148,
    1145,  1162,  1149,  1150,  1134,   949,  1169,   946,     0,     0,
    1187,     0,  1132,  1131,  1126,  1124,  1123,  1127,  1125,  1129,
    1130,  1122,  1175,  1379,  1439,  1433,  1435,  1442,  1444,     0,
    1449,  1442,     0,  1447,     0,  1457,  1456,     0,  1458,     0,
    1375,  1381,  1522,  1515,  1385,  1564,  1562,  1563,  1559,  1561,
    1558,  1560,  1490,     0,  1492,     0,     0,     0,     0,  1498,
    1502,     0,  1482,  1397,   988,  1225,  1218,  1214,  1611,     0,
    1415,  1416,  1418,  1421,  1428,     0,     0,  1474,  1598,  1592,
    1549,  1547,  1548,  1544,  1546,  1543,  1545,   493,   491,     0,
     525,   524,   172,   439,     0,     0,    23,     0,     0,   980,
       0,    49,   960,     0,    23,   161,   151,     0,   622,   624,
     163,   153,   727,     0,   339,  1307,     0,  1021,     0,     0,
      65,     0,    78,    87,     0,    71,   849,   846,   536,  1809,
     918,  1532,     0,     0,     0,  1642,     0,     0,     0,  1640,
       0,     0,     0,     0,  1622,  1639,     0,   665,   642,   648,
     612,  1657,     0,  1655,     0,     0,  1576,  1576,  1569,  1371,
       0,  1373,  1367,     0,  1289,     0,  1667,     0,  1716,  1715,
       0,     0,  1474,     0,  1474,  1474,  1474,  1474,  1719,     0,
       0,  1699,     0,     0,     0,     0,  1728,  1700,     0,     0,
       0,     0,     0,     0,  1694,     0,  1362,  1365,  1349,  1363,
    1366,     0,   818,   817,   323,   207,   951,   950,   948,     0,
    1168,  1054,  1058,  1060,     0,  1064,     0,  1062,  1066,  1055,
    1056,     0,   840,     0,     0,  1461,     0,  1450,  1453,  1452,
    1460,     0,  1442,     0,     0,  1516,  1521,     0,  1509,  1501,
    1485,  1483,     0,  1486,     0,  1419,     0,  1523,  1422,     0,
    1429,  1430,  1601,  1217,     0,     0,     0,     0,   522,   521,
     475,   349,   346,     0,   978,     0,     0,     0,   959,   728,
     139,   621,    23,   969,   540,  1026,    66,  1192,    83,     0,
       0,    76,    87,    87,  1809,   533,     0,     0,     0,     0,
       0,  1638,  1644,  1634,  1635,  1636,  1637,   667,   720,     0,
    1654,  1603,  1596,  1575,  1571,     0,  1291,     0,  1596,  1739,
       0,     0,  1742,     0,     0,     0,     0,     0,     0,     0,
    1711,  1730,  1731,  1729,  1727,  1709,     0,  1705,  1707,  1696,
    1697,  1304,     0,  1350,  1348,  1583,   947,  1809,  1809,  1068,
    1809,  1070,  1809,  1809,  1057,  1188,  1176,  1443,  1645,  1445,
       0,  1448,  1446,  1462,     0,     0,     0,  1499,  1423,     0,
    1417,  1411,  1412,  1614,     0,  1431,  1425,  1599,  1322,  1318,
    1319,  1324,  1323,  1597,  1217,     0,   351,   979,  1792,     0,
       0,     0,     0,     0,     0,    54,     0,    53,     0,    51,
       0,     0,   140,  1030,  1022,     0,  1028,    87,    92,    87,
      88,    82,    72,   847,     0,     0,  1605,     0,  1682,     0,
    1809,    23,  1656,  1595,  1604,  1295,     0,  1292,  1294,  1591,
    1740,     0,     0,  1738,     0,     0,     0,     0,  1720,  1737,
       0,  1364,  1059,  1061,  1809,  1065,  1809,  1063,  1067,  1451,
    1459,  1517,  1494,     0,  1420,     0,  1410,     0,  1326,  1325,
    1321,  1600,  1550,   357,   355,   347,     0,   353,   359,    56,
      61,    58,    60,    57,    59,    55,     0,    50,     0,   623,
     625,  1809,  1027,  1029,  1193,    84,    79,   534,   919,  1680,
    1681,   663,   721,     0,  1286,  1736,  1743,  1732,  1733,  1734,
    1735,     0,  1069,  1071,  1424,  1413,  1320,  1809,  1809,   352,
     354,  1809,    52,     0,  1031,     0,   668,  1293,  1698,   358,
     356,   360,     0,    85,   961,    89,    91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   554,   555,   556,   557,   713,  1739,  1740,   191,   266,
     192,  1139,  1140,  1627,  1967,  3027,  2466,  2467,  2906,  3028,
    3029,   558,   902,  2500,  2205,  2923,  1566,  2203,  2763,  2504,
    2919,  2204,  2764,  3038,  3145,  3155,  2921,  3158,  1788,  1789,
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
     331,  1534,   565,   566,   567,   568,   788,  3016,  2736,  1141,
    3095,  3096,  3097,  3138,  3137,  3141,   569,   570,   571,   572,
     762,  1118,   783,  1133,  1134,  1175,   868,  1176,   764,   765,
     766,   767,   768,   769,   770,  1072,  1119,  2143,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,   718,   771,  1486,  2148,  2150,
    2734,   772,  1456,  2132,  1455,  2131,  1459,  2135,  1457,  2133,
    2115,  2124,   773,   774,   775,   776,  1440,  1441,  1442,  1443,
    1559,   573,  2769,  3044,  2516,   574,   841,  1536,  2493,  1837,
     117,   239,   367,  1355,   968,   969,   970,  1352,  1353,  1674,
    1675,  1676,  2026,  2027,  1356,  1357,  1670,  2030,  2022,  1682,
    1683,  2033,  2034,  2328,  2324,  2325,   575,  1183,    87,  1502,
    1503,  1832,   871,   821,   874,   696,   810,   793,   832,  1925,
      88,   697,   691,  1405,  2174,    89,   778,   576,   577,   923,
     924,   578,   579,   580,   581,   931,  2547,   952,  2788,   953,
    1604,   954,  1922,   955,  2254,   956,  1630,   582,  1600,  2253,
    2545,  2544,  3050,   118,    22,   583,  1157,  1508,  1509,  1620,
    1301,  1621,  1622,  2264,  2266,  1938,  1937,  1942,  1936,  1935,
    1928,  1927,  1930,  1929,  1932,  1934,   584,   585,   829,   586,
    1297,   938,  3051,   587,  1229,  2744,  1969,  1970,  1623,  1939,
    1872,  2211,   864,  1210,  1540,  1840,  1541,  1206,   588,   589,
     916,  1589,  2520,   590,   591,   592,   593,    23,    68,    24,
      25,    26,   119,   120,   594,   121,    27,   652,    28,   122,
     123,   160,   369,  1361,  2038,  2843,   124,   156,   300,   595,
    2111,    29,    30,    31,    32,    33,    62,    90,   125,   415,
    1370,  2044,   596,   911,  1876,  1578,  1874,  2924,  2511,  1579,
    1873,  2214,  2513,   597,   598,   599,   804,   805,  1265,   126,
     240,   368,   656,   657,   972,  1359,   600,   957,   958,   601,
    1309,   959,   779,    92,    93,    94,    95,  1272,   186,   140,
      96,   702,   137,   194,   195,  1273,  1274,  1883,  1275,   412,
     413,   940,   414,   941,  1596,  1597,  1276,  1277,  1137,  2646,
    2647,  2848,  1414,   819,   820,   602,  1152,  2908,   603,  2488,
     604,  1170,  1171,  1172,  1527,  1525,   605,   606,  1797,  1827,
     607,  1020,  1411,   608,   865,   866,   609,   879,   610,  1980,
     611,  2915,   612,  1844,  3034,  3035,  3036,  3111,   870,   613,
    1278,  1591,  1909,  1910,   614,  1495,   695,  1032,   615,   616,
     617,  2046,  2650,  2859,  2860,  2977,  2978,  2982,  2980,  2983,
    3074,  3076,   618,   619,  1267,  1583,   620,  1269,   887,   888,
     889,  1245,   621,   622,   623,  1552,  1237,   882,   201,   890,
     891,   780,  2047,  2372,  2373,  2356,   721,   722,  2042,  2357,
    2360,   127,   155,   361,   997,  1692,  2374,  2863,  1042,   624,
     880,   128,   152,   358,   994,  1690,  2361,  2861,  2043,   906,
    2195,  2759,  3037,  1240,   625,   626,   627,   628,   629,   791,
    1795,   715,  1744,   630,  2707,   709,   710,  2108,  1390,   631,
     632,  1006,  1007,  1008,  1402,  1729,  1009,  1726,  1399,  1010,
    1701,  1391,  1011,  1012,  1013,  1014,  1695,  1382,   633,   800,
     781,   634,  1333,  1334,  1645,  2575,  2805,  2295,  2572,  3056,
    3057,  1335,  1655,  2309,  1315,  2012,  2616,  2835,  2188,  2492,
    2013,  1336,  1337,  2718,  3009,  3010,  3011,  3090,  1338,  1339,
    1174,   635,   835,   636,   965,  1340,  1341,  2974,  1661,  1662,
    1663,  2015,  2311,  2838,  2839,  1342,  1990,  2289,  2802,  1392,
    1393,  1378,  2067,  1693,  2068,  1394,  2072,  1395,  2095,  1396,
    2096,  2426,  2427,  1696,  1343,  1639,  1640,  1987,  1344,  3005,
    2890,  3001,  1993,  2441,  2710,  2711,  2712,  2999,  2442,  1994,
    2891,  3006,  2055,  2056,  2057,  2058,  2059,  2865,  2667,  2987,
    2060,  2866,  2867,  2400,  2061,  2401,  2062,  2530,  1722,  1723,
    1724,  2696,  1725,  2423,  2417,  2879,  2069,  2840,  2404,  2608,
    2071,  2888,  1911,   782,  1912,  2223,  1060,  2116,  2727,  2085,
    2692,    61,   637,   638,  2567,  2797,  2282,  2796,  1666,  2020,
    2021,  2286,  1981,  1345,  1982,  2001,  2578,  1432,  1977,  1978,
    2719,  2893,  2795,  2571,  1913,  1653,  2112,  2113,  3002,  2063,
    1915,  1916,  2532,  2989,   639,   640,  1632,  1979,  2562,  2792,
    2793,  1312,   641,   786,  1347,  1348,  1648,  2297,  1349,  1350,
    1998,  2247,  2525,   642,   919,  1286,  1287,  1288,  1289,  1351,
    2002,  2614,  2834,  2306,  2611,  2612,  2613,  2610,  2598,  2599,
    2600,  2601,  2602,  2603,  2953,   703,  1593,   705,  1415,  1917,
      66,    50,    80,    77,   644,   893,  1556,  1160,  1231,   645,
     872,   646,  2161,   647,  1738,   707,  1417,   648,   649,    44,
     362,   363,   364,   365,   366,   650
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2399
static const short yypact[] =
{
    1619,  1041, -2399, -2399,   291,   643,   643,   643,   643,   643,
     643,   643,   643,   291,  1296, -2399, -2399,  1296, -2399,  1705,
   -2399, -2399, -2399,   331, -2399,  1619, -2399, -2399, -2399, -2399,
   -2399,  1298, -2399, -2399, -2399, -2399, -2399,   317,   333, -2399,
     351, -2399, -2399, -2399, -2399, -2399,   291,    48, -2399,  -208,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399,  2397,   109, -2399, -2399, -2399, -2399,  1520, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   291, -2399,
   -2399,    48,  -173, -2399,   291,   393,  1705, -2399,   907, -2399,
   -2399, -2399, -2399,   999,  -142, -2399, -2399, -2399,   579,   251,
     291, -2399, -2399,   675,   291, -2399, -2399,   291,   291, -2399,
   -2399, -2399, -2399,   291,   291, -2399, -2399, -2399, -2399, -2399,
    1520, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399,  7785,  -142, -2399,   931,   423, -2399, -2399,   240,
   -2399, -2399,   746,   109,   263, -2399, -2399, -2399, -2399, -2399,
    7672, -2399,   291,   420,   680,   291,  1705, -2399, -2399, -2399,
     291, -2399, -2399,   330,   696, -2399, -2399,   471, -2399,   501,
   -2399,   485, -2399, -2399,   629, -2399,   670, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,   454, -2399, -2399, -2399,
     423,  1736,   953, -2399,   129, -2399,   423, -2399,   269, -2399,
   -2399, -2399,    68, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,   330, -2399,   696, -2399, -2399,   700, -2399,   721, -2399,
     615, -2399, -2399,   724, -2399,   751, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399,   789,  1197,   291,   814, -2399,  1705,
    1705,   842,   291, -2399,   563, -2399,   627,   837, -2399,   656,
     887,  1289,  1309,   291,  1315,  1331,  1334, -2399,   691, -2399,
     917, -2399, -2399, -2399, -2399, -2399,   423, -2399,   423,   926,
     170, -2399, -2399, -2399,  1369, -2399, -2399,  1378, -2399, -2399,
   -2399, -2399, -2399,   563, -2399, -2399, -2399,  1384,  1393,   109,
    1315,  1396,  1400,   816, -2399,  1382, -2399,  1059,  1024, -2399,
    1122, -2399, -2399, -2399,   874, -2399, -2399,  1475, -2399,  1084,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399,   887,  1084, -2399,
   -2399, -2399, -2399, -2399, -2399,  1089,   226,   230,   285, -2399,
    1353, -2399, -2399, -2399,  1099,  1541,   235,  1161, -2399, -2399,
    1736, -2399,   423,  1098, -2399, -2399,   946,  1542,  1314,   247,
     256,   341,  1144,   271,  1191, -2399, -2399, -2399,   291, -2399,
   -2399,   291,  1217, -2399,  3805,   263,  4741,  2304,   316,   291,
    1565,   520, -2399,   837,  1568, -2399, -2399, -2399, -2399,  1573,
   -2399,  1588, -2399,  1589, -2399,   291, -2399,   291, -2399, -2399,
    1315,  1592, -2399, -2399, -2399, -2399,   172,   423,  1604,   520,
    1199,  1608, -2399,  1612, -2399, -2399, -2399,  1614, -2399, -2399,
   -2399,  1025,  1262,  1650, -2399,   291,  1270, -2399, -2399, -2399,
     291,   207,   291,   291,   207,   207,  1160,   291, -2399,   291,
   -2399, -2399,   291, -2399,   979, -2399, -2399, -2399,   207, -2399,
   -2399, -2399, -2399,   291, -2399, -2399, -2399, -2399,   136,   136,
    6755, -2399, -2399, -2399, -2399, -2399, -2399,   207, -2399, -2399,
     207, -2399, -2399,   291, -2399, -2399,   207, -2399, -2399,   628,
     207, -2399, -2399,  6755,   207,   628,   291,   628,   207, -2399,
   -2399,   171,   207,   207,   171,   207,   291,   171,   207, -2399,
     207,   207,   207, -2399, -2399, -2399, -2399,   628,   207, -2399,
   -2399,   207,    40,   291, -2399, -2399, -2399, -2399,   207,  1187,
   -2399, -2399, -2399,   207, -2399,  3453,   628,  6755,    61,    61,
     207, -2399, -2399,  1215,   628,  1248,  6755,  6755, -2399,   762,
    6755,   207,    48, -2399,  6755,   207,  6755,   628, -2399,   207,
    6755, -2399,  6755,   136,   291,   207,   291,    61,   207,   291,
      61, -2399,   291,   313, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,   233, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,   699, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399,   822, -2399,   291, -2399,   683, -2399,  1272, -2399,
   -2399, -2399,  1357, -2399, -2399,  1279,  1281,  1285,  1290, -2399,
   -2399,  1063,  1677,  1297, -2399,   176, -2399,  1387, -2399,  1301,
    1310,  1082,  1316,   291, -2399,   291,  1317, -2399,   321,  1288,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  1092,
    1321,  1257, -2399,  1104, -2399,  1102, -2399,  1715,  -174,   281,
   -2399, -2399, -2399,  1302, -2399,  1405, -2399,  1246,   283, -2399,
   -2399, -2399,  1413, -2399,  6755,  6755,  6755, -2399, -2399,  1300,
    1202,  1304,  1306,  1308,  1318,  1329,  1332,  1333,  1338,  1340,
    6755,  1067,  1342,  1347,  1350, -2399,  6755,  6755,  1351,  1355,
   -2399,  6755,  1358, -2399,  1359,  1360,  1362,  1364,  1373,  1375,
    1379,  1383,  6051, -2399,   143, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399,  1170, -2399,  1311,
   -2399, -2399, -2399, -2399,  6256, -2399, -2399, -2399,   628, -2399,
   -2399,  1405, -2399,   -35, -2399, -2399,  1473, -2399,    53, -2399,
    1328, -2399, -2399, -2399, -2399,  1756, -2399, -2399,  -282, -2399,
    1154, -2399,  1182,  1756, -2399,  1213, -2399, -2399,  1392,    77,
   -2399,  1385, -2399,  1156, -2399, -2399,  1402, -2399,  -111, -2399,
    1159,   258,  -180, -2399,  1092,  1508, -2399,  6755,  6755, -2399,
    1829,   207, -2399, -2399, -2399, -2399, -2399,   286,   286,   286,
   -2399,   286,  2797,   286,   286,  1242,   -35,  1242,  1242,  1312,
    1312,  1242,  1242,   -35, -2399,  1836, -2399,    19,  1837, -2399,
     -35, -2399,   165,    46, -2399, -2399,  6755, -2399, -2399, -2399,
   -2399, -2399,   892, -2399, -2399,   263,  1462,   263,  6755, -2399,
      67, -2399, -2399,  6755,  1416,  1418,  1420,  1421,  1469,  1427,
    1248,  1360, -2399,  1514,  1226,  1277, -2399,  1293, -2399, -2399,
   -2399,  1341, -2399,  1865, -2399,  1860,   291, -2399,   228,   111,
    1303, -2399, -2399,  1871, -2399,  1219,  1871,  1874,  1223,  1871,
    1874,  6755,  1871, -2399, -2399,   283,   628, -2399, -2399,  1466,
     320, -2399, -2399,  1459,   628,  6755,  1467, -2399, -2399,  1867,
    1872,  1846, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
    1345,  1345,   207,   207,   207,  1477, -2399, -2399,  1824,   822,
   -2399, -2399,   790, -2399, -2399, -2399,  1458, -2399, -2399, -2399,
   -2399,  7785,  1315, -2399, -2399,  1465, -2399,   284, -2399, -2399,
   -2399, -2399, -2399, -2399,  1705, -2399, -2399,  1705,   742,   139,
    1891, -2399, -2399,   418,   152,   532,  1915, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  1485,  1321,  1102, -2399,  1160,
     252,  1086,   291, -2399, -2399,   291, -2399,  1330,  1307,  1335,
    1500, -2399,  1502,    71, -2399, -2399, -2399,  4681,  7131,  7131,
      61,  6755, -2399,    61,    61,    61,    61,  1470,  6755,  1454,
    1586,  6755,  6051,  1503, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,  1319,    61,  1922,  6755,  4162,  6051,  1470,  6755, -2399,
    6051,  1923,   396, -2399, -2399, -2399,  6755, -2399,  6755,  6755,
    6755,  6755,  6755,  6755,  6755,  6755,  6755,  6755,  6755,  6755,
    6755,  6755,  6755,  6755,  6755,  6755,  6755,  6755, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  6755,  6755,
   -2399, -2399,  1516,  6755, -2399,  6755,  1543, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
     291,   628, -2399, -2399,  1940, -2399, -2399,  1324,  1544, -2399,
   -2399, -2399,  1160,  1349, -2399,  1349,  1248,   171,  6755,  6755,
    6755,  1548, -2399, -2399,   628,   628, -2399,  1346,  1248,    61,
    1325,   291,   423,    37,    40,   628, -2399,  1348,  6755,  1629,
   -2399, -2399,  1426, -2399, -2399,  1982, -2399,   187,   283, -2399,
   -2399,  1972,  1970, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  2187,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  3453,
   -2399,  1312,  6755,    -3,    61,  1965,  1966, -2399, -2399, -2399,
   -2399, -2399,    86, -2399, -2399, -2399, -2399,  1841, -2399,  1780,
   -2399, -2399, -2399,  6755,   136, -2399, -2399,   291,  1974,    61,
      61, -2399,  1412, -2399,    61,  1389,   628, -2399,   291,   291,
    6755,   -47, -2399,  1439, -2399,   276, -2399,  1523, -2399,  1537,
    6755,  1076, -2399, -2399,  1401, -2399,  2014, -2399,  1479, -2399,
     628, -2399, -2399, -2399,  1160,   628,   166, -2399, -2399, -2399,
   -2399,   291,    61,    61,   202,   320,  1876,  2425,   628,   283,
   -2399,  1482, -2399, -2399,  1982,  2004,  1632, -2399, -2399, -2399,
   -2399, -2399,  1711,  1711, -2399,   361,  1487, -2399,   291, -2399,
   -2399,  1405,  1405, -2399, -2399, -2399,   291, -2399,   291,   292,
    1405, -2399,   755, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  1273, -2399, -2399, -2399,
   -2399, -2399,   112,   112,   373,   932, -2399,   718, -2399,   790,
   -2399,  1705,  2008, -2399, -2399,  2008, -2399, -2399, -2399, -2399,
    1705, -2399, -2399,  1405, -2399,   650, -2399,  1613, -2399, -2399,
     650, -2399, -2399, -2399,  1615,  1616,   336,  1620,  1621,  6196,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399,   291, -2399, -2399,
     336,  1395, -2399,   321, -2399,  1661,  -142,  1443, -2399,  1248,
    1488, -2399, -2399,  1609, -2399, -2399, -2399,  1532, -2399,   291,
     291,   291, -2399, -2399, -2399,   318,  6051,  1688,  1689,   353,
     354,   292,  1690,  4211,  1691,  -133,  1210, -2399, -2399,   119,
    1693, -2399, -2399, -2399,  4638,  2070,  1067,   380,  1706,  5111,
   -2399,  1709,  1945,  1713, -2399,  6755,  6755,  6755,  5364,  6755,
    5411,  5535,  5580,  6201,  3002,  4681,  6153,  6883,  7303,  6905,
    7332,  3163,  3566,  7309,  7131,  7131,  7540,  7540,  2022,  6051,
    5751,  5880,  1470,  6051,  6004,  1470,  6755,  1672, -2399,  6256,
     291, -2399,  1491, -2399, -2399, -2399, -2399,  1483, -2399,  2104,
    2106, -2399,  2107,  1534,  6755, -2399, -2399,  1501,  2116, -2399,
    1642,  1504,  1874, -2399,  1734,   445, -2399,  1696, -2399, -2399,
    1509,   867,   291, -2399, -2399,  1697,   207,   939,  6755, -2399,
     291,   291,  6755,    44,   -35,  2123,  2127,  2110,  2111,  2797,
   -2399, -2399, -2399, -2399, -2399,   628,  1605, -2399, -2399, -2399,
    2076,  6755,   263,  1005, -2399, -2399,  1819,  2143,  2145,   394,
   -2399,   397,   291,  1760,  1248, -2399,  6755,  1722,  1723, -2399,
   -2399,  1794, -2399,  6755,    10, -2399,  1560, -2399, -2399,   496,
   -2399,  6755, -2399, -2399,  1539,   931, -2399,  1112,   291,  2148,
    2319, -2399, -2399,  1739, -2399,  1746,  2162, -2399, -2399, -2399,
      55, -2399,  1874,  1874,  1510, -2399,  1622,  1624, -2399, -2399,
   -2399, -2399,    61,    61, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,  1971, -2399, -2399, -2399, -2399,    61,  5954,  2166,  2147,
   -2399,  1248,   804,   161,   130,  2074,    25,  1215, -2399,    16,
   -2399, -2399, -2399,  1747,    62,  1405,   711, -2399,  1564,  1554,
   -2399, -2399, -2399, -2399, -2399,   833, -2399, -2399, -2399, -2399,
    1754,  1561,  2181, -2399,  1515, -2399, -2399, -2399, -2399,   628,
     107, -2399, -2399, -2399,  1555,   932, -2399,   291,   291, -2399,
   -2399,   291,   523, -2399, -2399, -2399, -2399,  1766,  1769, -2399,
    1738, -2399,  1742, -2399,  1781,   404, -2399,  3921,   405,   147,
     147,   407, -2399,   147,  3921, -2399, -2399,  1123,  1123, -2399,
    1783, -2399,  1784,  1785, -2399,  1787,  1790, -2399,  1791, -2399,
   -2399, -2399,   117, -2399, -2399, -2399,   415, -2399, -2399,   422,
     291, -2399, -2399,  1086,  2191,  1248,   423,  6755, -2399,  2217,
   -2399, -2399, -2399, -2399,   336, -2399, -2399, -2399, -2399, -2399,
   -2399,  7439, -2399, -2399,  1067,  1067,  2200, -2399,  2201,  1639,
    1464, -2399,  1202,  1838, -2399, -2399,  1202, -2399, -2399, -2399,
    1847,  1202,  6051,  6051,  6051,  1202,  6051,  1202,  1202,  1202,
    2212,  2214,  2215,  6755,  1851,  2218,  6755,  1856, -2399,  2244,
   -2399,  6051, -2399, -2399,  1634,   336,   194, -2399,  1248,  6755,
    6755,  6755,  6447,  2249,   158, -2399, -2399,  1248, -2399,  1636,
     291,   291, -2399, -2399,   291,   291, -2399,  1222, -2399, -2399,
     449, -2399,  1638,  6755, -2399, -2399, -2399,  2250, -2399, -2399,
   -2399, -2399, -2399,   291,  1874, -2399, -2399,  1707, -2399, -2399,
     428, -2399, -2399, -2399,   628, -2399,  3679, -2399, -2399, -2399,
    1937,  2238, -2399,    61,  1921,  1924,  1811,  1651,  1928,  1843,
   -2399, -2399, -2399,   564,  1918, -2399, -2399, -2399, -2399,  1794,
   -2399, -2399, -2399,   127,   666, -2399, -2399, -2399,  1982,  6755,
    1850, -2399,  1822, -2399, -2399, -2399,  7577,  7577, -2399,  1092,
   -2399, -2399,  1123, -2399, -2399,  3935,  1852, -2399, -2399,  1853,
    1854, -2399,  1855,  1857,  1858,  1861,   291,   638, -2399,  2276,
   -2399, -2399, -2399, -2399, -2399,  1995, -2399, -2399,  1160,   628,
     628,    87,  1643, -2399,  2260,   -35,   291,  2563,  2563,  2563,
    2563, -2399,  2287, -2399,  2289,  2563,  2563,  2563,  2563,  2187,
   -2399, -2399,  2563,    96, -2399, -2399, -2399, -2399,  2278,  2291,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  2293,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399,   429, -2399, -2399,
   -2399,  2283, -2399, -2399,  1405, -2399,   292, -2399, -2399, -2399,
   -2399, -2399, -2399,  1720,  1726,   160, -2399,    16, -2399,   147,
    1716,   207,  3921, -2399, -2399,  1899, -2399, -2399, -2399,   291,
     291,  7439,   323, -2399,  6755, -2399,  6755, -2399, -2399, -2399,
   -2399, -2399, -2399,   207,   147, -2399,  1405,  1060,  1714,  1717,
    2335, -2399,  2336, -2399,   628,   291,   620,   620, -2399, -2399,
    2337, -2399,  2337,   668,   668,  2337, -2399, -2399,  2304, -2399,
   -2399,  6156,   128, -2399,  2304,  1963, -2399,   128,   147,   650,
   -2399,  7425,  1917,  3899,  1917,   322,  2341, -2399, -2399, -2399,
   -2399, -2399, -2399,   265, -2399,  1405,   510,  1968,  2355,  1744,
   -2399, -2399,   435, -2399,   336, -2399,   439,   409, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  1740,   -88,  2340,  2340,  2342,
    2340,  2340,  2343, -2399,   278, -2399,   650,   291, -2399,   336,
   -2399, -2399,  1748,  1248,  2353,   184, -2399,   291,   447, -2399,
    6755,  1980,   115, -2399,   291, -2399,  1749, -2399,  1981, -2399,
    2349, -2399,  1788, -2399, -2399, -2399, -2399, -2399,  1751, -2399,
   -2399,  1987,  1988,  1990, -2399,  1993, -2399, -2399, -2399, -2399,
   -2399, -2399,  6051,   452, -2399, -2399,   470, -2399,  1994,  6755,
    6755,  2367,   476,  1248,  2383, -2399, -2399, -2399, -2399,  6755,
    1825,  2121,  6755, -2399, -2399, -2399, -2399,  1116,  1999,   449,
    1268,  1268,  2391,  -108, -2399,  2393, -2399, -2399, -2399,  1268,
     291,  1859,  1240,  2394,   291,   -78,  6755, -2399, -2399,  2797,
   -2399,  1622,  6755, -2399,  2401,  6755, -2399,   628, -2399,   979,
     291,   628, -2399,  2016,  6755,  6755, -2399, -2399,   564,  1918,
   -2399,  2187, -2399, -2399,  1365, -2399, -2399,  1839, -2399,   423,
    6696,  1842,  1842, -2399,  1786,   292,  2018,   399,   549,  7439,
     549,   549,   549,   549,  1796,  7439,  2319,  7439,  7439,  7439,
    7439, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399,  1973,   958, -2399, -2399, -2399,  1797, -2399,
   -2399, -2399, -2399,    61,  2563,    61,  2563, -2399, -2399, -2399,
   -2399, -2399, -2399,   -35, -2399,  1165,  1275,  5954, -2399,  2026,
    1991,  7439,  1273,   130,   130, -2399, -2399, -2399, -2399,   478,
   -2399,  1948, -2399,  2414,   147,   -23, -2399,  1798, -2399,  2420,
    5254,  5254,  5254,  5254,   147,   147, -2399, -2399, -2399,  1875,
   -2399,   482, -2399,  1807, -2399,   291,   291,  1515,   628, -2399,
    2337, -2399, -2399,   291,   668,   668, -2399, -2399,   668,  2223,
    1815,  1816, -2399, -2399,   136,   136,   136,  2412,   136,   136,
     136,   136,   136,   136,  2416, -2399,  2417,   136, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  6156, -2399,   628,  1827,
   -2399,  2000,  2223,  2423, -2399,  2428,  2429,  2430,  2431,  2432,
    2434,  1381,  1963, -2399,  2000, -2399,   483, -2399, -2399,  1984,
   -2399,   424,   254, -2399,  3921, -2399,  3921, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  7577,  2034,  7577,  2035,
     764,  7439, -2399,  2440, -2399,  2171,   147,  1256,   147, -2399,
   -2399, -2399, -2399,  1266,  2442,  1266, -2399,  2465,  2465,   484,
    2081,  2465, -2399,  2082, -2399, -2399, -2399,   650, -2399, -2399,
   -2399, -2399,  1248, -2399, -2399,   336,  2208,  1982, -2399,  7439,
     104,  1955,   533, -2399,  1553,  1067,  1892,  1519, -2399, -2399,
   -2399, -2399, -2399,  6755, -2399, -2399, -2399, -2399, -2399,  2017,
   -2399,   210,  1248, -2399,  2478,  2055, -2399, -2399,  2096, -2399,
   -2399, -2399,  1938, -2399, -2399,   291,  1268,   423,  1271,   291,
    1268, -2399, -2399,    61, -2399, -2399,  6755, -2399, -2399, -2399,
      61,  1982,   628,  2252, -2399,   -35,  6051,  2464, -2399, -2399,
     283,  2064, -2399, -2399,  6755, -2399, -2399,  2102, -2399, -2399,
   -2399,   666, -2399,  1622, -2399,  6755, -2399,   197, -2399,  1837,
   -2399,  1266,  7439, -2399,   473,  2103,  2497, -2399, -2399, -2399,
    7439, -2399,   495,  7439,  7439,  7439,  7439,   291,   499, -2399,
   -2399, -2399, -2399, -2399,  6755,  2063, -2399,  2160, -2399,  2485,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,   291, -2399,    90, -2399, -2399, -2399,  1273,   147, -2399,
     292,  2368,   513, -2399, -2399, -2399, -2399,   291,  1953,  7147,
    7147, -2399, -2399,  7168,  2078, -2399, -2399,  2080,  2083, -2399,
    2084,  2085,  2086,  2091,   291,   783, -2399, -2399,   516, -2399,
   -2399,  2658, -2399, -2399, -2399,   519,  2507,  2507, -2399, -2399,
     522,  2519,  2511, -2399,    94, -2399, -2399,   147, -2399,   144,
    1909, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  2324,  7785,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,   342,  2530, -2399,   628,  1870,
   -2399,  2324, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  2341, -2399,  2095,  1995,   371,
   -2399,  2095,   371, -2399,  7577, -2399, -2399,  7439, -2399,   201,
   -2399, -2399, -2399,  2079, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399,  2150, -2399,  2512,  2151,  2152,  2513, -2399,
   -2399,  2155, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   229,
    2542, -2399, -2399,   291,  2180,   291,  1931,   549,  2219, -2399,
    2122, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  1525,
   -2399, -2399, -2399,  6051,  2163,    61,   -35,  2182,  1248, -2399,
    6755, -2399,  1985,  2532,   -35, -2399, -2399,   472, -2399, -2399,
   -2399, -2399,   102,  2165,  1874,  2162,  2320, -2399,  2168,  2170,
    2123,  2133, -2399,  2221,  2175, -2399, -2399, -2399, -2399,  2327,
    2112, -2399,   115,  1123,  1944, -2399,  1123,  2183,  7439, -2399,
    2186,  2189,  2190,  2192, -2399, -2399,  1996, -2399, -2399, -2399,
    1622, -2399,   524, -2399,   628,  2036,  1273,  1273, -2399, -2399,
    7439, -2399, -2399,   147, -2399,  2142, -2399,  2036,  2231,  2231,
    2194,   399,   549,  7466,   549,   549,   549,   549,  1967,  7466,
    5254, -2399,  7466,  7466,  7466,  7466, -2399, -2399,   147,  2574,
     147,  5254,   207,  3921, -2399,   628, -2399, -2399,   362, -2399,
   -2399,   291, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   628,
    2530, -2399, -2399, -2399,   628, -2399,   628, -2399, -2399,  1668,
   -2399,  2350, -2399,  2352,   278, -2399,   529, -2399, -2399, -2399,
   -2399,   534,  2095,  2585,  2567, -2399, -2399,  1969, -2399, -2399,
   -2399, -2399,  2204, -2399,   104, -2399,   104, -2399, -2399,  7439,
   -2399,  2149, -2399,  2208,    72,   161,   291,  2572, -2399, -2399,
   -2399, -2399, -2399,  1248, -2399,  2211,  7775,  2174, -2399, -2399,
   -2399,  1986,   -35, -2399, -2399,   156, -2399, -2399, -2399,  2216,
     283, -2399,  2221,  2221,   666, -2399,   423,  2220,  1983,  1266,
    1989, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   291,
   -2399,  2162,   533, -2399, -2399,   115, -2399,  5921,   533, -2399,
    2225,  7466, -2399,   539,  7466,  7466,  7466,  7466,   291,   542,
   -2399, -2399, -2399, -2399, -2399, -2399,  2176, -2399, -2399, -2399,
    2414,  2162,   144, -2399, -2399, -2399, -2399,  1463,  1463, -2399,
    1463, -2399,  1463,  1463, -2399, -2399, -2399, -2399, -2399, -2399,
     295, -2399, -2399, -2399,  7439,  2184,  1266, -2399, -2399,   560,
   -2399,  2607, -2399, -2399,  3921, -2399, -2399, -2399, -2399,  2613,
   -2399,   421, -2399, -2399,  2208,  2228,  1152, -2399, -2399,   286,
     286,   286,   286,   286,   286, -2399,  2595, -2399,   569, -2399,
    6755,  1305, -2399, -2399, -2399,   942, -2399,  2221,  6755,  2221,
    2123, -2399, -2399, -2399,  2381,   208, -2399,  1266, -2399,  1266,
      55,   -35, -2399, -2399, -2399, -2399,   590, -2399, -2399, -2399,
   -2399,  2232,  7466, -2399,  2233,  2235,  2236,  2239, -2399, -2399,
    5254, -2399, -2399, -2399,  1463, -2399,  1463, -2399, -2399, -2399,
   -2399, -2399, -2399,   104, -2399,  7439,  2414,    72, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,   962, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  7775, -2399,  2624, -2399,
   -2399,   969, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,    87, -2399,  5921, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,   600, -2399, -2399, -2399, -2399, -2399,  1000,  1000, -2399,
   -2399,  1000, -2399,  6755, -2399,  2243, -2399, -2399, -2399, -2399,
   -2399, -2399,  2247, -2399, -2399,   191, -2399,   283, -2399,  2123
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2399, -2399, -2399, -2399, -2399,   440, -2399,   535,  -188, -2399,
   -2399,  -864,   192, -2399, -2399, -1542, -2399, -2399, -2399, -2399,
    -466, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -1734, -2399, -1547, -2399,
     492, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   776, -2399,
   -2399, -2399, -2399,  1386, -2399,  1072, -2399, -2399,   -61, -2399,
   -2399,  2610, -2399,  2609,  2284, -2399, -2399, -2399, -2399, -2399,
     840,   474, -2399,   835, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,   -76,   541,   382, -2399, -2399,
    2364,    98, -2399,  2514, -2399, -2399,  2508, -2399,  2447, -2399,
   -2399, -2399,  2376,  2261,  1320,  2371,  -317, -2399, -2399, -2399,
   -2399, -2399,  1322,  -983, -2399, -2399, -2399, -2399, -2399, -2399,
    -146,  2307,  2450,  -197,   897, -2399,  2294,   221, -2399,  2354,
   -2399, -2399, -2399, -2399,  2357, -2399, -2399, -2399, -2399,  -325,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  2290, -2399,
    2296, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  -920,
   -2399, -2399,  -407, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
    2427, -2399, -2399,  1201, -2399,  -813,  -861,  -326, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399,   908, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  -288, -2399, -2399, -2399, -2399,
   -2399,  2167, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -1714, -2399, -2399, -2399, -2399, -2399, -2399,  1255, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  1728, -2399, -2399, -2399,
   -2399,  1026, -2399, -2399, -2399, -2399, -2399, -1243, -2399, -2399,
    1017, -2399, -2399, -2399, -2399, -2399, -2399,  -814,  -530,   901,
    1171, -2399,  -490,   844,  -838,  1377, -2399,   632, -2399, -1821,
      -4,  -248, -2399, -2399, -1750,   414,   905, -2399, -2399,   935,
    1417, -2399, -2399, -2399, -2399, -2399, -2399,   453, -2399,   163,
   -2399,  1419, -2399,  1108, -2399,   793, -2399, -2399, -2399,  -405,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   912, -2399,
   -1250, -2399,  1097, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  1558, -2399,
   -2399, -2399, -2399, -2399, -2399,   -33, -2399, -2399, -1503, -2399,
   -2399, -2399, -2399,   759, -1710, -2399,  -822, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399,  2698, -2399, -2399, -2399,  2605,  2697,  -928, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,    81, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399,  2704, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  1162, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399,  -421,  2251, -2399, -2399,
   -2399, -2399, -2399,  2087, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399,  1833, -2399, -2399,   -60, -2399, -2399,  1155, -2399,
   -2399, -2399,  -685,  -192,  2471, -2399, -2399, -2399, -2399,   641,
   -2399,  -717,  2060,  1448, -2021,   828, -2399,  1168,  1821,   110,
     -90, -2399, -2399, -2399,  1606, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  1545, -2399,  1126, -2399,  -392,
   -2399, -2399, -2399, -2399, -2399, -2399,  -275, -2399, -2399, -2399,
   -2399, -2399, -2399,   530, -2399,  1625,   652, -2399, -2399, -2399,
   -2399, -2399,   391, -2399,   -92, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
    1883, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  -336, -2399,
    1530,  1703, -2399, -2399,   406, -2399,  -435, -2399, -2399,   426,
     732, -2399, -2399, -2399, -2399, -2399, -2399, -2399,   297, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2314, -2399,  1755,   988,  -979, -2399,
   -2399, -2399,  1394, -2399, -1350, -2399, -2399, -2399, -1359, -2399,
   -2399, -1342, -2399, -2399, -2399, -2399,  1404, -2399, -2399, -2399,
   -2399, -2399, -2399,   800, -2399, -2399, -2399, -2399, -2399, -2399,
    -337, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399,  -300, -2399, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,
     771, -2399, -2399, -2399,  -183, -2399, -2399, -2399, -2399, -2399,
   -2399,   385, -2399, -2399,   747, -2399,  1095, -2399, -2399, -2399,
   -2399, -2399, -2399,  -978, -2399, -2399, -2399, -2399, -1412, -2399,
   -2399, -2399, -2399, -2399, -2399, -2040,    95, -2399, -1611,   364,
   -2399, -2399, -1677,   419,   425,   757, -2399, -2398, -2162, -2399,
   -2399,   134,  -178, -2399, -2399, -2399, -2399, -1839, -2399, -2399,
   -2399, -1407, -2399, -2399,  -647, -2399,  -636,  1492,   140, -1645,
     760, -2399, -1353, -2399, -2399, -2399, -2399,  -713, -2399, -1675,
   -2301,  2811, -2399, -2399, -2399, -2399, -2399, -2399, -1994, -2399,
     514, -2399, -1505, -2399,  1877, -2399, -2399,  -783,   -65, -2399,
   -1743,   -64,   257,   544, -1968, -1400, -1965,   402,  -242, -1569,
   -1838, -2399,   609, -2399, -2399, -2399,  1533,  -514, -2399, -2399,
     -94,  1886, -2399,   575, -2399, -2399, -1272,   272, -2399, -2399,
   -2399, -1742,    39, -2399, -2399, -2399,  1562, -2399, -2399, -2399,
   -2399, -2399, -2399, -2399, -2399, -2188,    21, -2399, -2241, -1804,
   -1554,  -989, -2399, -2399,    33,  -441,  -403,  -452,  1120,    52,
      22,  1814,    58, -2399, -2399, -2399, -2399, -2399,  1695, -2399,
    -322, -2399, -2399, -2399, -2399, -2399, -2399, -2399, -2399,  -355,
    1284,  2493, -2399, -2399, -2399, -2399
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1806
static const short yytable[] =
{
      43,  1033,   260,  1179,   270,   388,  1223,   115,  1368,    58,
      60,   885,   827,    60,   723,  1232,  1018,   286,  1819,  1860,
    1379,  1914,    34,   704,   133,  1177,  1401,  2077,  1061,   419,
    1205,  1751,   258,  2086,  1185,  1186,  2299,  1187,  1727,  1207,
    1208,  2117,    76,    79,  1702,  1606,  1607,    34,  2221,  2222,
    1728,  1224,  2213,    72,  2070,  2073,  1649,  1516,  2073,   115,
    2605,  2606,  2607,   809,    42,  2176,   692,    42,   836,   692,
     692,    42,  1243,   672,   130,    42,  1299,    79,   340,  1030,
     238,   293,  1155,   692,  2380,  1968,  2383,   277,    42,   139,
     129,  1222,   271,   278,   279,  2439,   146,  1028,  3008,    42,
     151,  1224,   692,   153,   154,   692,   704,  1224,   921,   157,
     158,   692,  2024,  1424,  2694,   692,  2609, -1804,  1294,   692,
    2439,   840,  2273,   692,   763,  1984,  1317,   692,   692,  1028,
     692,    42,  1304,   692,   268,   692,   692,   692,  1758,   131,
    1143,  1144,   129,   692,  1283,  1759,   692,   795,   234,  2251,
     396,   237,  2212,   692,    42,  1138,   241,    42,   692,  2164,
     271,    99,   719,   301,   302,   692,    42,   271,   784,  1127,
    1224,    42,  1028,   690,    42,   268,   692,   268,  2163,    42,
     692,   268,  2114,  1028,   692,    42,   883,    42,    42,   268,
     692,   869,  1528,   692,   275,   142,   802,   873,    42,  1283,
     886,   892,   268, -1804,   908,   675,  2874,  1528,   912,   785,
     914,  1991,   785,   268,   918,  2737,   920,  2224,  1295,   883,
    2771,    42,   794,   837,   838,   927,   785,  1988,   930,  2271,
     785,   381,   298,   876,    42,   383,  2671,   811,   304,   943,
     391,    99,   785,  2832,   794,   203,  1225,  1226,  1017,   332,
     822,  1321,   401,   794,  1028,  1529,    42,  1530,  1755,  1531,
     833,   403,  2358,  2387,  2388,   839,  2389,  2390,  2391,  2392,
    2393,  2394,   875,  2870,  2387,  2388,   407,  2389,  2390,  2391,
    2392,  2393,  2394,   822,  1451,    42,  1025,   822,  2564,  1366,
     385,   822,  1570,   271,   272,   273,    42,   794,   942,  1576,
     794,  1284,   271,  2424,  1890,   561,   651,   271,   933,   934,
      42,  2489,  1180,    42,  1819,  2293,  2563,    84,    42,   271,
    1889,  1890,    42,  1224,  2093,  1299,  2226,   294,  2384,  1214,
    1215,    67,  2597,  2597,  2597,  2597,  1148,   271,   933,   934,
      42,  1545,  2414,  1149,  2290,   943,   143,  1162,    73,  1868,
    2477,    84,  1220,  3156,   411,  1598,  1284,   411,  1224,  1224,
     943,    84,    36,    42,  1023,   411,  1168,  2972,  1550,  2312,
    2495,  2300,  2301,  2302,  2303,  2304,  2381,   998,   999,    35,
     346,   332,   348,   332,    84,  1224,  1255,    99,   643,   653,
    1279,  2533,  2534,  2535,  2536,   271,  1889,  1890,    42,  1853,
      42,    65,  1224,  2070,  1221,  1000,  1001,  1002,  1323,  2049,
    2049,   411,  2074,  1024,   824,  2384,   688,    81,   693,   694,
    2097,  1401,   701,   706,   699,   708,    42,  2099,   711,  2670,
    2384,  2673,  2114,  2189,  2277,  2032,   394,  1169,  2035,   694,
    2408,   187,   188,   132,  2408,    42,   777,  2570,    84,   189,
      42,  1615,  2435,   394,  2180,  2574,  1756,  2453,  1135,   694,
     730,  1535,    97,   261,   262,   263,   264,   265,    65,   777,
    1300,  2755,   694,    84,  2993,  2453,    84,   141,  2773,   689,
    2287,  2435,   812,  2568,  2382,   700,   692,  2617,  2406,  2698,
     261,   262,   263,   264,   265, -1804,  1634,  1635,   828,   830,
    2778,  2510,  2973,    84,  2778,   701,  2395,   943,  1163,   689,
    1577,  2478,  2872,   777,   828,   828,  2094,  2395,  2803,  1576,
    1332,  2820,   777,   777,  2820,   904,   777,  2828,    79,  2939,
     777,  1260,   777,   946,  2990,  3157,   777,  2415,   777,  2990,
     922,    19,   922,   828,  3062,   922,   828,  3062,   922,  1238,
     869,  1241,  1833,  1427,  1428,   269,   689,  2772,  2668,    42,
    2668,   700,   886,    84,  1407,  3083,    19,  1246,   386,  1380,
    2181,  1316,  1280,  2798,  3106,  2288,  2281,   944,  1408,  3007,
    2490,  1384,  1397,  2738,   143,  1619,  1586,  1992,  1573,   700,
     910,   945,  1546,   875,  1385,  3123,   343, -1804,   674,  1300,
    1329,   825,   984,  2458,   145,  2820,  2837,   692,   692,   692,
    2433,  2597,  2597,    84,  1835,  2597,   704,   382,  2709,  2833,
    1985,   384,   945,  2770,   405,  2396,   392,  2875,  3048,  2252,
    1329,  1976,  1497,  1156,  3118,   134,  2396,    78,   402,   946,
    2965,  2359,  1165,  2794,  1511,  2523,  1924,   404,  2498,  2573,
     971,  1650,  2743,  2025,   946,    42,  1363,  2506,  2507,  2884,
    2531,  2440,   408,  1384,  1285,  1364,  2531,  1914,  2540,  2541,
    2542,  2543,  1026,  1892,   827,  1367,  1385,  1924,  1145,   993,
     147,   411,  2397,  2065,  1244,  1643,  1644,   274,  1893, -1804,
    1892,  1543,  2767,  2397,  1654,  3082,   701,   935,   196,  1784,
    3091,  1492,  1787,  1517,  1227,  1893,   826,  1230,  1760,  1746,
     826,  1029,  2114,  2385,  1314,   839,   875,  1841,  1425,  1285,
     777,   777,   777,  1429,  1430,  2745,  1498,   826,  2298,  2750,
    1577,  2728,  2410,  1764,  1547,  2559,   777,  1694,  2429,   704,
    1447,  2425,   777,   777,  1749,  1750,  3119,   777,  3120,  2430,
   -1804, -1804, -1804, -1804, -1804,   274,   803,  1669,  2065,  1560,
     197,  2681,   274,  2684,  1563,  2109,  1892,  1651,  1878,  2065,
    2153,  1765,  1281,  2941,  2674,  1003,   986,  1384,  2565,  2566,
     777,  1893,  2320,   739,   200,  1854,  1181,  1029,  1855,    42,
    1385,  1228,   236,   951,  2524,  2050,  2064,  1636,  2075,   936,
    2412,   946,  2943,  2944,  1532,  1282,  2098,  1372,   743,  1555,
    2398,  1387,  1533,  2100,  2971,  2664,  2109,  2011,    84,  2190,
    2278,  2398,  1499,  1500,  1501,  2522,  2409,  1388,  1409,  3131,
    2411,    42,  2678,   777,   777,  2945,  2668,  1512,  2436,  2078,
    1182,  2225,  1523,  2454,  2998,  2597,  3000,  2036,  1386,  2774,
     235,  2597,  2597,   190,  2597,  2597,  2597,  2597,  1875,  2826,
      42,  2455,  1004,  2597,  2715,   243,   894,  2460,  1410,  2569,
    2114,  1809,   777,  2618,  2663,  2699,  2399,  1652,  2895,   259,
    2846,   947,   948,   949,   777,  1996,  2779,  2399,   274,   777,
    2785,   752,   950,  1387,  1253,  1734,  1544,   274,  2911,  1372,
   -1804,   251,   274, -1804,  2804,  1005,  2305,  2821,  2527,  1388,
    2827,   660,  1271,  2829,   274,  2940,   895,   886,  1369,  2472,
    2991,  1371,  1656,  2799, -1804,  2992,  2079,   777,  1561,  2847,
    3063,   252,   274,  3069,  1569,   261,   262,   263,   264,   265,
     654,   777,  2080,   254,  1584,   661,  1373,  2596,  2596,  2596,
    2596,  3084,    84,  2114,   896,  1406,   184,  2762,    42,  3088,
    3107,  2777,  1400,   655,  2780,  2781,  2782,  2783,  2403,  2938,
    1602,  1603,  2836,  2951,  1515,  2954,  2955,  2956,  2957,   267,
    1581,  3124,  1997,  2597,   757,  2081,  2597,  2597,  2597,  2597,
     274,  3148, -1804,   305,    84,  1381,   759,   760,    45,  1389,
    1398,  1389,   416,  1677,   761,   712,    42,  1387,  3089,  1995,
     658,  2697,   701,  2675,  2701,   701,  2960,  1413,  1416,   138,
     306,   708,  1374,  1388,  2528,  2082,    42,  2968, -1804,  2810,
    1812,  1848,    42,  1813,   960,   787,   828,   777,  1373,   828,
     828,   828,   828,  3134,   777,   961,  2716,   777,  1211,   796,
    1859,   897,  1974,   801,  2083,  1218,   686,  2717,   828,   255,
     777,  2257,  -266,  2084,   777,   815,  2826,  2826,  2235,    35,
      36,  2377,   777,   290,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,   777,   777,   777,   777,   777,   777,
     777,   777,   777,   777,  2597,   717,   136,   962,  2928,  1421,
     256,  2930,  2597,   276,   777,   777,  1412,   281,  2873,   777,
    2329,   777,   963,    42,  1374,   789,  2362,  1973,  2428,   737,
    1401,    84,  1931,  1933,   817,  1376,  1487,   898,   798, -1512,
     287,   738,  1881,   823,  2529,  1745,  2469,  1814,   701,    42,
    1815,  1377, -1804,    42,   777,   777,   777,  1678, -1804,  -266,
    2676,   288,  2677,  2292,   291,   828,  2970,  1514,  2946,  1518,
     828,  2927,  1615,  1135,   777,  -266,  1679,  1680,   899,    84,
    2800,   692,  1375,  1642,  2003,  2310,    46,   925,  1803,  1646,
     928,   292,   689,  2004,  2942,   699,  1681,    42,  3041,  3042,
      47,  2555,    42,  1657,  1783,    84,  2948,  1786,  1677,  3053,
    3139,   964,  1828,   309,  1658,  3059,  1501,  2005,  -266,  2932,
    2006,  1834,   834,  2819,    42,    48,  1847,  1376,   777,   296,
     828,  2104,  1018,   297,  3112,  1659,  2596,  2596,  2007,  1436,
    2596,  2114,  1660,  1377,  1437,   900,  1439,  1615, -1804,   777,
     877,   136,    42,  1557,   299,   828,   828,  1867,  -266,  3012,
     828, -1804,   308,   318,  1567,  1568,   777,  1615, -1804,  2952,
    2484, -1804, -1804,    49, -1804,  2952,   777,    42,  2961,  2962,
    2963,  2964,   303,   883,   754,    42,  2682,  -266,  1824,   692,
     701,   317,  2154,    42,  2155,  1685,  -266,   922,   828,   828,
     310,  2748, -1804,  2166,  1691, -1804,  1619,  2437,    42,   901,
     692,  2557,    42,  3114,  1943,  3116,   311,   654,   339,  3093,
     338, -1804, -1804,  3094,  1638,   326,  2868,  1029,  1029,  2868,
    3003,    59,  1647,    42,  1647,  3109,  1029,  3086,     1,   973,
     655, -1804,    42,  2008,  3054,   327,  1594,    83,  2280,    42,
     319,   333,  1678,   756,     2,     3,   699, -1804,    42,   312,
     700, -1804,   758,   720,   720,    84,   320,   336,   387,  2519,
     337,  1679,  1680,  2196,   135,   136,  1264,  2494,    42,  1029,
    1310,  1619,    42,  2491,  1493,   909,    42,   700,  3058,   913,
    2313,  1681,  1389,   917,   342,  1812,   839,  2009,  1813,   313,
    2512,  1619,    42,  1398,  2010,   344,  1389,  3061, -1804,   321,
    3064,  3065,  3066,  3067,   345,    84,  2659,   875,    42,  2554,
     349,  2106,  3033,  2177, -1804,  1741,  1742,  1743,   314,   350,
       5,     6,   353,     7,     8,  3080,   354,   315,     9, -1804,
    1028, -1804,    42,  1053, -1804,   355, -1804, -1804,    84,   322,
     356,  2418,  3012,  2420,  2421,    10,    11,  1615,   720,  2703,
     359,   777,   777,   777,   360,   777,  2705,  2110,   937, -1804,
    2596,   966,   967,    12,   986,    84,  2596,  2596,   323,  2596,
    2596,  2596,  2596,  2156,  2157,  1501,  2160,   324,  2596,  1434,
    1435,   926,   777, -1804,   929,   777,  1794,   932,  2121,  2078,
    2122,  3115,  1814,   370,  1251,  1815,    42,  2183,  1657,  3093,
     777,   371,    84,  3094,  1233,  1234,  1235,  1236,  3126,  1658,
    1404,  2988,    42,  3098,   374,  2248,  3003,  1615,  1822,   379,
    1054,  1034,  1035,  1036,   777,   389,  1829,  1830,   777,   828,
    1659,    84,  3033,  1585,   136,    84,  1055,  1660, -1804,    84,
    2018, -1804,    42,  2730,  2105,  2731,   390,   777,  2186,  2898,
       1,  2899,   393,  2217,  3058,    84,   397,  1494,  1857,  1494,
    1664,  1665,   777, -1804,  2123,   398,     2,     3,   399,   777,
     406,    84,   400,  1672,  1673,   104,  2079,   777,   417,  1056,
     105,  1619,   409,  1882,  1271,   659,  1907,  1825,  1826,  2431,
    2808,  2809,  2080,  3098,   664,  1318, -1804,  2220,  2596,   666,
    1129,  2596,  2596,  2596,  2596,  1436,   947,   948,   828,   828,
    1437,  1438,  1439,   161,   667,   668,  1212,  1213,   673,  1057,
    1216,  1217,   828,   937,   676,   106,   107,   135,   136,   678,
     692,  2757,  2685,   108,   679,  2081,   692,  2868,   680,  2461,
     682,  1029,     5,     6,   683,     7,     8,  2845,  1058,     1,
       9,  1619,   162,   684,    14,   685,  1257,  1059,   692,   976,
    2019,   687, -1804,   975, -1804,     2,     3,    10,    11,  1128,
     977,   163,   978,  2031,  2031,  2082,   979,  2031,  2307, -1804,
    2308,   980,   982,   135,   136,    12,   981, -1804,   983,   985,
    1130, -1804,   989,  1907,     4,  2066,  2066, -1804,  1319,  2066,
    1907,   990, -1804,    15,  2083,   991,  1320,   992,   996,  2596,
     164,  1016,  1321,  2084,  1322,   136, -1804,  2596,  1015,  2686,
    1019,  1021,   165,  1022,  1031,  1323,  2101,  1041,  1027,  1413,
    1040,  1131,   166,   777,  1043,  2687,  1044,   839,  1045,  1142,
    1389,     5,     6,   875,     7,     8,  1258,  1907,  1046,     9,
     167,     2,     3,  1324,   261,   262,   263,   264,   265,  1047,
     168,  1147,  1048,  1049,    17,   875,    10,    11,  1050,  1325,
    1051,  1150,  1062,  2550,  1326,  2552,   169,  1063,  2688,   777,
    1064,  1067,   777,  2760,    12,  1068,  1327,  1146,  1071,  1073,
    1074,  1389,  1075,  1328,  1076,   777,   777,   777,   777,  1151,
    2066,  2852,   698,  1077,  2713,  1078,  2168,  1822,  1153,  1079,
    2173,  2173,  1154,  1080,  1159,   716,   170,  1164,  2689,   777,
      51,    52,    53,    54,    55,    56,    57,     5,     6,  2185,
       7,     8,  1161,  2463,  1173,     9,  2468,  1178,  1209,   171,
     937,  1219,  1222,   790,  1158,  1239,  1247,  2690,  1248,   828,
    1249,  1250,    10,    11,   172,    13,  2691,  1254,  1256,   807,
     808,   173,  2239,  2240,   174,   814,  1259,  2853,   816,  2854,
      12,  1260,  2902,  1268,  1270,   777,  1291,  1292,  1290,  1224,
    2910,  1293,  1907,  1907,  2855,   175,  1298,   109,   176,  1302,
     177,  1907,  2856,  1306,   869,    91,  2857,  1305,  1307,  2631,
    2632,  2633,  2234,  2635,  2636,  2637,  2638,  2639,  2640,   178,
    1018,  1308,  2643,   110,   701,  1354,  1362,  1383,  2704,  2720,
    1403,  2858,  2258,  1365,  1421,  1419,  1420,   179,   692,   692,
    1422,  2851,  1423,  1445,  2241,  2242,  2243,  2244,  2245,  2246,
    1431,    13,  1448,  1453,  1446,  1489,  1482,  1329,  2739,  1490,
    1769,  1081,  1082,  1083,  1330,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,   185,   193,
    1029,  1510,  1522,  1485,  1491,    14,  1331,   651,  1504,  1524,
    1097,  1332,  1526,   651,   111,  2066,  1230,  1528,  1907,  1538,
    1537,  1548,  1549,  1551,  2969,  2296,  1647,  1907,  1553,  1558,
     777,  1562,   777,  2852,  1580,  1608,  2721,  1609,  1610,  1611,
    2066,  1564,  1029,  2237,  2238,  2239,  2240,  1573,  1582,  1588,
    1587,  2031,  2722,   193,    15,  1590,  1300,  2517,  1626,   193,
    1628,  1629,  1631,  1637,  1686,   839,   839,  1098,  1099,  1100,
    1101,  1102,  1103,  1697,  2066,  1699,  1700,  1907,  3032,  1907,
    1703,  1704,  1732,  1104,  1105,  1106,    16,  1097,  1730,  2125,
     653,  2066,  1733,  2127,  1735,  2723,   653,  1736,  2130,  2853,
    1389,  2854,  2134,  2713,  2136,  2137,  2138,   112,  1737,  1747,
    1748,  1752,  1754,   937,  1761,    17,  2855,  2241,  2242,  2243,
    2244,  2245,  2246,  1398,  2856,  1389,  1763,  1766,  2857,   193,
    1768,   193,  1792,  1741,  1771,  2724,   777,  1796,  1798,  1799,
    2443,  1800,  1801,  1802,  1098,  1099,  1100,  1101,  1102,  1103,
    1804,  1805,  2363,  2858,  1806,  1808,  1810,  1823,  1299,  1807,
    1104,  1105,  1106,  1811,  2725,  1836,  1838,  1839,  2364,  2365,
    1843,  1845,    16,  2726, -1804,   777,   777,  2366,  1851,   720,
    1852,  1858,  1861,  1862,  1865,   777,  1871,   113,   777,  1918,
    2753,  2752,  1885,  2470,  1879,   114,  1919,  1920,  2754,   950,
    1926,  1971,  1924,  1972,  1983,   193,  1822,  1989,  2485,  2000,
    2487,  2367,   777,  1999,  2014,  2016,  2017,  3122,   777,  2768,
    2368,   777,  2039,  2028,  1107,  2040,  2502,  1108,  2041,  2103,
     777,   777,  2045,  3040,   937,  3099,  3100,  3101,  3102,  3103,
    3104,  2048,  1188,  2087,  2088,  2089,   777,  2090,  2786,  2369,
    2091,  2092,  2107,   701,  2904,  1907,  2118,  2119,  2120,  2126,
     193,  1907,  1907,  1907,  1907,  1907,  1907,  2139,  2129,  2140,
    2141,  1612,  2144,  2145,  1613,  2901,  1614,  2147,  2713,  2149,
    2713,  2824,  2825,  2151,  2162,  2167,  1360,  2182,  2184,   828,
    2187,   828,  2193,  2194,  2370,  2197,  1615,   714,  2198,  2199,
    2200,  1107,  2201,  2202,  1108,  2218,  1616,  1907, -1804,  2526,
    2219,  2236,  2227,  2228,  2229,  2230,  2256,  2231,  2232,  2747,
    2066,  2233,  2263,   949,  2265,  1940,  2595,  2595,  2595,  2595,
    2066,  2066,   792,  2274,  2844,  2275,  2371,  2276,   797,  2279,
     799,  2620,  2621,  2019,   806,  2283,  1109,   806,  1617,  2624,
     806,  2284,  1618,  2241,  2242,  2243,  2244,  2245,  2246,  2294,
     818,  1110,  2291,  2315,     1,  1111,  2316,  1886,  1887,  1888,
    2317,  2318,  2323,   271,  1889,  1890,    42,  2379,  2386,   867,
       2,     3,  2604,  2604,  2604,  2604,   878,   881,   884,  2405,
    2406,  2432,   905,  2407,  1189,  2413,  2416, -1749,  2419,  2422,
     915,  2438,  2445,  1112,  2444,  2446,  2448,  2447,  2449,  2450,
    1907,  2451,  1907,  1891,  2452,  2456,   939,  2459,  2462,  3017,
    2471,  2464,  1907,  1109,  1907,  2465,  2475,  1907,  2479,  2486,
    1619,  1113,  2066,  2683,  2066,  2483,  2497,  2505,  1110,  2523,
    2515,  2521,  1111,  2546,  2905,  2537,  2549,  2560,  2570,  1114,
    2384,  2561,    83,  2577,    42,  2439,     5,     6,  2615,     7,
       8,  1389,  2619, -1804,     9,  1907,  1029,  2634,  2629,  2630,
    3159,  2641,  2642,     2,     3,  2648,  2649,  2713,  2652,   777,
    1112,    10,    11,  2653,  2225,  2654,  2655,  2656,  2657,  1608,
    2658,  1609,  1610,  1611,  2669,  2672,  2679,  1373,  2693,    12,
    2695,  2173,  2700,  2702,  2749,  2173,  2706,   692,  1113,   828,
    1992,  2729,   777,  2740,  2735,  2741,   828,  2742,  2743,  2758,
    2761,  1190, -1804,  2765,  2775,  1908,  1114,  1191,  1192,  1193,
     777,  1115,  2776, -1804,   944,  2790,  2794,  2801,  2811,   700,
    2812,   777,  2820,  2813,  2814,  2815,  2816,  1194,  1907,     5,
       6,  2817,     7,     8,  2830,  2831,  1907,     9,  2841,  1907,
    1907,  1907,  1907,  2784,  2842,  2849,  2864,  2403,  2878,  2882,
     777,  2877,  2880,  2881,    10,    11,  2883,  2886,  2889,  2894,
    2896,   939,  2897,  2907,  2900,  2903,  2913,  2791,  2909,  2916,
    2914,  2917,    12,  2918,  2066,  2920,  2922,  1116, -1804,  2929,
    2926,  2937,  2947,  2296,  2931,  2595,  2595,  2933,  1115,  2595,
    2934,  2935,  2440,  2936,   875,  2949,  2958,    84,  2966,  2985,
    2818,  2986,  2994,  2995,  2996,  2997,  3004, -1804,  3015, -1804,
   -1804, -1804,  1908,  3018,  3030,  3031,  3070,  3039,  3047,  1908,
    3081,  3046,  3085,  2066,  3049,  1638,  3060,  1539,  3087,  3092,
    3105,  1136,  3117,  3125,  3127,  1195,  3128,  3129,  1196,  3143,
    3130,  2604,  2604,    13,  3153,  2604,  1667,  1668,  3154,  2501,
    3142,  2457,  2434,  1684,  1116,  2210,  1870,  1572,    74,    75,
     562,  2169,  2178,   351,  2482,   204,  1908,   199,   283,   347,
     677,   352,   410,   285,  1167,   701,  2128,   663,   701,  2732,
    1907,  1197,   378,  1907,   376,   669,  2822,  2823,  2824,  2825,
    1184,  1184,  1184,   670,  1184,  1688,  1184,  1184,  1689,  3140,
    1793,  1757,    91,    91,  2146,  1612,   903,  1358,  1613,  2037,
    1614,  2029,  2158,  1831,  3108,  1029,  1198,  2548,  1601,  2887,
    2789,  2892,  1923,  1605,  1892,  2255,  3146,  2165,  1941,  2912,
    1615,  2869,  1519,    69,  2869,   159,  1199,  1200,    70,  1893,
    1616,   828,  2862,   884,  3045,    71,   777,  1201,   813,   341,
    1880,  1877,  1202,   974,  1266,   995,  1894,  1625,  2250,  1895,
    2241,  2242,  2243,  2244,  2245,  2246,  1884,  1296,  2850,  2976,
    3113,  1506,  1896,  1986,  1542,  2662,  2539,  2984,   939,  1136,
    1496,  1242,  1617,  1554,  1907,  1454,  1618,  1303,  2661,  2375,
    1418,  1203,  2644,  2152,  1698,  2285,  3147,  3136,  2314,  3071,
    2680,  1908,  1908,  1311,  1311,  2376,  1907,  1731,  2076,  2066,
    1908,  1897,  1898,  2665,  2885,  2714,  2871,   701,  2378,  2595,
    1641,  2666,  3079,  1204,  1899,  2595,  2595,  3152,  2595,  2595,
    2595,  2595,  1188,  2876,  2066,  2402,  2066,  2595,    64,  1907,
    3013,  2622,  3014, -1804,    16,  2807, -1804,  2975, -1804,  2576,
    1850,  2708,  1346,  3135,  2538,  3052,  1633,  1313,  1599,  2806,
    2950,  2967,  2959,  2102,  1619,  1513,  1900,   418, -1804,     0,
       0,     0,     0,  2526,     0,  2604,     0,     0, -1804,     0,
       0,  2604,  2604,     0,  2604,  2604,  2604,  2604,     0,     0,
    1029,     0,  1029,  2604,  1921,  1907,     0, -1804,     0,     0,
    2066,     0,  2892,     0,     0,  1901,     0,  1908,     0,     0,
       0,     0,     0,     0,     0,     0,  1908,  1902,     0,     0,
   -1804,     0,     0,     0, -1804,     0,     0,     0,     0,  1903,
    1904,     0,     0,     0,     0,     0,     0,  1905,     0,     0,
    1906,     0,     0,     0,     0,  2791,     0,     0,   274,     0,
       0,     0,     0,  1907,     0,     0,     0,  2595,     0,     0,
    2595,  2595,  2595,  2595,  3068,     0,  1908,     0,  1908,     0,
       0,     0,     0,     0,  1488,     0,     0,     0,  1638,     0,
       0,     0,     0,     0,  1189,     0,    91,     0,    91,   884,
     806,     0,     0,     0,     0,     0,   701,  1505,   818,     0,
    1907,   884, -1804,     0,     0,   193,     0,     0,  1520,  1908,
    1907,     0,     0,  2604,     0,     0,  2604,  2604,  2604,  2604,
    1083,   939,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,     0,   777,  3110,     0,     0,
       0,     0,     0,     0,   777,     0,     0,  1097,     0,     0,
       0,     0,  2869,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,  2595,     0,
       0,     0,     0,     0,     0,     0,  2595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1029,
       0,  1907,     0,  2066,     0,     0,     0,     0,     0,  1565,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,  1190,     0,     0,     0,     0,     0,  1191,  1192,  1193,
    1104,  1105,  1106,  1592,  2604,     0,     0,     0,  1595,  1907,
       0,     0,  2604,     0,     0,     0,     0,  1194,     0,     0,
       0,  1624,   939,     0,  1908,     0,     0,     0,     0,   777,
    1908,  1908,  1908,  1908,  1908,  1908,     0,  2206,  2207,     0,
       0,  1037,  1038,  1039,     0,     0,     0,     0,  2216,     0,
       0,     0,     0,     0,     0,     0,     0,  1052,     0,     0,
       0,     0,     0,  1065,  1066,     0,     0,     0,  1070,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,  1908,  1671,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1097,     0,
       0,     0,     0,     0,     0,  1908,  1908,  1908,  1908,     0,
       0,  2259,  2260,  2261,  2262,     0,     0,     0,     0,  2267,
    2268,  2269,  2270,     0,     0,     0,  2272,     0,     0,     0,
       0,     0,     0,     0,     0,  1195,     0,     0,  1196,   720,
     720,   720,   884,   720,   720,   720,   720,   720,   720,     0,
       0,  1107,   720,     0,  1108,  1098,  1099,  1100,  1101,  1102,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,  1105,  1106,     0,     0,     0,     0,     0,     0,
       0,  1197,     0,     0,     0,     0,     0,     0,     0,  1908,
       0,  1908,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1908,     0,  1908,     0,     0,  1908,     0,     0,     0,
    2321,  2322,     0,     0,     0,     0,  1198,  2326,  2327,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1199,  1200,     0,     0,
       0,     0,     0,     0,  1908,     0,     0,  1201,     0,     0,
       0,     0,  1202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1109,     0,     0,     0,     0,  1842,     0,
       0,     0,     0,     0,     0,     0,  1849,     0,  1110,     0,
       0,  1203,  1111,     0,     0,     0,     0,   884,     0,     0,
       0,     0,     0,     0,     0,   937,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,  1108,     0,     0,   185,     0,
       0,     0,     0,  1204,     0,     0,     0,  1908,     0,     0,
    1112,     0,     0,     0,     0,  1908,     0,     0,  1908,  1908,
    1908,  1908,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2473,  2474,     0,     0,  1113,     0,
       0,     0,     0,  2481,   884,  1975,   884,     0,  1426,     0,
     878,     0,     0,     0,     0,  1433,  1114,     0,  1444,     0,
       0,     0,     0,     0,  1908,  1908,     0,     0,  1908,     0,
       0,  1449,  2508,  2509,     0,  1452,     0,     0,     0,     0,
       0,     0,  2023,  1458,     0,  1460,  1461,  1462,  1463,  1464,
    1465,  1466,  1467,  1468,  1469,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1109,  1480,  1481,     0,     0,     0,
    1483,     0,  1484,     0,     0,     0,     0,     0,  2551,  1110,
    2553,     0,     0,  1111,     0,     0,     0,     0,  1115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   884,   193,
       0,     0,     0,     0,  1908,     0,     0,  1908,     0,  1908,
       0,   842,  1908,  1091,  1092,  1093,  1094,  1095,  1096,     0,
     843,  1112,     0,     0,     0,     0,     0,     0,     0,   844,
       0,  1097,     0,     0,   845,     0,     0,     0,  2625,  2626,
       0,     0,  2627,  2628,     0,     0,     0,     0,     0,  1113,
       0,     0,     0,     0,  1116,     0,     0,     0,     0,   884,
       0,   884,     0,     0,     0,     0,     0,  1114,     0,     0,
     884,     0,     0,     0,     0,     0,  2651,     0,   846,     0,
       0,     0,     0,     0,     0,     0,   847,     0,  1098,  1099,
    1100,  1101,  1102,  1103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1104,  1105,  1106,  2191,     0,     0,
       0,     0,     0,  1908,  2192,  1081,  1082,  1083,     0,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,     0,     0,     0,  1908,  2215,     0,     0,     0,
       0,     0,   848,     0,  1097,     0,     0,     0,  1908,  1115,
       0,     0,     0,     0,  1908,  1908,     0,  1908,  1908,  1908,
    1908,     0,     0,     0,     0,     0,  1908,   849,  1908,     0,
       0,     0,     0,     0,   850,     0,   851,     0,     0,     0,
       0,     0,  2249,  1595,     0,     0,   852,     0,     0,     0,
    2746,     0,     0,     0,  2751,     0,     0,     0,     0,  1908,
       0,  1098,  1099,  1100,  1101,  1102,  1103,  2756,     0,     0,
       0,     0,   853,     0,     0,  1116,     0,  1104,  1105,  1106,
     854,     0,     0,     0,  1908,  2766,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,  1108,     0,
       0,     0,     0,     0,     0,   937,     0,   855, -1805,  2787,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1805,
       0, -1805, -1805, -1805,     0,     0,     0,     0,     0,     0,
       0,     0,  1908,   856,     0,     0,  1908,  2319,     0,  1908,
    1908,  1908,  1908,     0,     0,     0,     0, -1805,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1772,  1773,  1774,     0,  1776,     0,     0,     0,
       0,   857,     0,     0,     0,  1908, -1805,     0,     0,  1908,
       0,     0,   858,     0,     0,     0,     0,     0,  2051,  1908,
       0,     0,     0,  1791,     0,     0,     0,  1886,  1887,  1888,
       0,     0,     0,   271,  1889,  1890,    42,     0,  1107,     0,
    2051,  1108,     0,     0,     0,     0,   884,  1109, -1805,  1886,
    1887,  1888,     0,     0,     0,   271,  1889,  1890,    42,     0,
       0,     0,  1110,  1886,  1887,  1888,  1111,     0,     0,   271,
    1889,  1890,    42,  1891,     0,     0,     0,  1908, -1805,     0,
       0, -1805,     0,     0,     0,  1908,     0,     0,  1846,     0,
       0,     0,     0,     0,     0,  1891,   884,     0,     0,     0,
    1908,     0,     0,  1791,  1112,     0, -1805,     0,     0,  1891,
       0,   859,   860,   861, -1805,     0, -1805,     0,     0,     0,
       0,     0,     0,     0,   862, -1805,     0,     0,     0,     0,
       0, -1805,  1113,     0,     0,     0,     0,     0,  1908, -1805,
    2499,     0,   714, -1805,  2503,     0,     0,     0,     0, -1805,
    1114,     0,     0, -1805, -1805, -1805, -1805,  2514,     0,     0,
    1109,     0,   193,  2925,     0,     0,     0,     0, -1805,     0,
       0,     0,   937,     0,     0,  1110,     0,     0,     0,  1111,
       0,     0,     0,     0,     0, -1805,     0,     0, -1805,     0,
   -1805,     0,     0,     0,     0,     0,     0, -1805,     0,   700,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1805,     0,     0,     0,     0,     0,     0,  1112,  2556,  2558,
   -1805,   700,     0,     0,     0,     0,     0,   863,     0,     0,
       0,     0,  1115,     0,     0,   700,     0,     0,     0, -1805,
   -1805,     0,     0,     0,     0,  1113,     0,     0,     0,     0,
       0,     0,     0,     0, -1805,     0,     0,     0,     0,     0,
       0,  2623, -1805,  1114,     0,     0, -1805,     0,     0,     0,
       0,     0,     0,     0,     0, -1805, -1805, -1805,  1081,  1082,
    1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,     0,     0,     0,  1116,     0,
       0,  2645,     0,  2052,     0,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,  2660,     0,     0,     0,  3043,     0,
    2142,     0,     0,  2142,     0,  2052,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096, -1805,  1115,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1805,  1097,     0,     0,     0,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,  3072,  3073,     0,  3075,   884,  3077,  3078,     0,     0,
    1104,  1105,  1106,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1805,     0,     0,     0,     0,
       0,     0,     0,     0,  1892,   884,     0,     0,     0,     0,
       0,  1116,     0,  1098,  1099,  1100,  1101,  1102,  1103,  1893,
     193,     0,     0,     0,     0,     0,  1892,     0,     0,  1104,
    1105,  1106,     0,     0,     0,  1595,  1894,     0,     0,  2053,
    1892,  1893,     0,   939,  3121,     0,     0,     0,     0,     0,
       0,  2054,  1896,     0,     0,  1893,     0, -1805,  1894,     0,
       0,  2053,     0,     0,     0,     0,     0,     0,  3132,     0,
    3133,     0,  1894,  2054,  1896,  1895,     0,     0,     0,  2225,
       0,     0,     0,     0,     0,     0,     0,     0,  1896,     0,
       0,     0,  1898, -1805,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1899,  3144,     0,     0,     0,     0,
       0,     0,     0,     0,  1898,  2225,     0,     0,     0,     0,
       0,  1107,     0,     0,  1108,     0,  1899,     0,  1898,     0,
       0,  3149,  3150,     0,     0,  3151,     0,     0,     0, -1805,
    1899,     0,     0,     0,     0,     0,  1900,     0,     0,     0,
       0,     0,     0, -1805, -1805, -1805, -1805, -1805, -1805, -1805,
       0, -1805, -1805,     0,     0,     0,     0,     0,  1900,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0, -1805,     0,
       0,     0,  1900,     0,     0,  1901,     0,     0,     0,     0,
       0,  2645,     0,     0,     0,     0,     0,  1902,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1901,     0,  1903,
    1904,     0,     0,     0,     0,     0,     0,  1905,     0,  1902,
    1906,  1901,     0,     0,     0,     0,     0,     0,   274,     0,
       0,  1903,  1904,  1902,     0,     0,     0,     0,     0,  1905,
       0,     0,  1906,  1109,     0,  1903,  1904,     0,     0,     0,
     274,     0,     0,  1905,     0,     0,  1906,     0,  1110,     0,
       0,     0,  1111,  1450,   274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   884,     0,     0,     0,     0,  1791,  1791,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
    1112,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1753,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1113,  2496,
       0,     0,  1791,     0,     0,     0,     0,  1595,     0,     0,
       0,  1791,  1791,     0,     0,     0,  1114,     0,     0,  1112,
       0,     0,     0,     0,  1081,  1082,  1083,     0,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,  1113,  1595,     0,
       0,     0,     0,  1097,     0,     0,     0,     0,     0,     0,
       0,     0,  2645,     0,     0,  1114,     0,  2979,     0,  2981,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,  1115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   884,     0,
    1098,  1099,  1100,  1101,  1102,  1103,   884,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1104,  1105,  1106,     0,
       0,     0,     0,   939,     0,     0,     0,     0,     0,   193,
       0,     0,     0,     0,     0,     0,     0,  1115,     0,     0,
       0,     1,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,  1116,     0,   420,     2,     3,  1104,
    1105,  1106,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   422,   423,     0,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,     0,     0,     0,     0,     0,
       0,   426,     0,  1116,     0,     0,     0,     0,     0,     0,
       0,     0,   427,   428,   429,     0,     0,     0,     0,     0,
       0,     0,  1184,  1184,  1184,  1184,  1184,  1184,   430,     0,
     431,   432,   433,     5,     6,   434,     7,     8,   435,     0,
     436,     9,   437,   438,     0,     0,     0,     0,     0,   439,
    2733,     0,   440,     0,   441,   442,   443,  1107,    10,    11,
    1108,     0,     0,     0,   444,     0,   445,   446,     0,   447,
       0,   448,   449,     0,     0,   450,    12,     0,     0,   451,
     452,   453,     0,   454,   455,     0,     0,     0,   456,   457,
     458,     0,   459,     0,     0,     0,   460,     0,   461,   462,
    1107,  1791,     0,  1108,   463,     0,     0,     0,   464,     0,
       0,   465,     0,   466,     0,   467,     0,   468,     0,   469,
     470,     0,   471,   472,   473,     0,     0,     0,   474,     0,
     475,   476,     0,   477,     0,     0,     0,     0,     0,     0,
       0,   478,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,     0,     0,   481,   482,     0,
     939,   483,   484,     0,     0,   485,   486,     0,     0,     0,
       0,     0,     0,     0,   487,   488,   489,     0,   490,  1109,
       0,     0,     0,     0,     0,     0,     0,     0,   491,   492,
     493,     0,   494,     0,  1110,     0,   495,   496,  1111,  1762,
       0,   497,     0,     0,     0,     0,     0,     0,     0,   498,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,  1109,     0,     0,   502,   503,     0,     0,     0,
       0,   504,     0,     0,   505,     0,  1112,  1110,   506,   507,
       0,  1111,     0,     0,     0,     0,     0,     0,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1113,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,   510,     0,     0,     0,  1112,
       0,   511,  1114,     0,     0,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,   110,     0,     0,  1113,     0,     0,
       0,   512,     0,   513,   514,     0,  1097,     0,     0,     0,
       0,     0,   515,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   516,     0,     0,  1115,     0,     0,     0,     0,     0,
       0,     0,   517,  1098,  1099,  1100,  1101,  1102,  1103,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
    1105,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   519,   520,     0,     0,  1115,   521,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,   523,   524,   525,   526,
    1116,     0,     0,   527,     0,     0,     0,   528,     0,     0,
       0,     0,  2579,  2580,   529,   530,     0,     0,   271,  1889,
    1890,    42,     0,     0,     0,     0,   531,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   533,
       0,   534,     0,  1116,   535,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,  2581,     0,
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
    1102,  1103,     0,     0,     0,  1791,     0,     0,     0,     0,
       0,     0,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1767,  1098,  1099,  1100,  1101,  1102,  1103,     0,
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
       0,  2582,     0,     0,  2583,     0,     0,     0,  1104,  1105,
    1106,     0,     0,     0,     0,     0,     0,  2584,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1116,     0,  1109,  2585,  2586,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2587,
    1110,     0,     0,     0,  1111,  1775,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,  1107,     0,  1097,  1108,     0,     0,
       0,  2588,  1112,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,  1777,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1113,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
    2589,     0,  1108,     0,     0,     0,     0,     0,  1114,  1112,
       0,     0,  2590,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,  2591,  2592,     0,     0,     0,  1104,
    1105,  1106,  2593,     0,     0,  2594,     0,  1113,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1114,  1081,  1082,  1083,     0,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,  1109,     0,     0,     0,
       0,     0,     0,     0,     0,  1097,     0,     0,     0,     0,
    1115,  1110,     0,     0,     0,  1111,  1778,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1886,
    1887,  1888,     0,     0,     0,   271,  1889,  1890,    42,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1112,     0,     0,  1110,  1115,     0,     0,
    1111,  1779,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,
       0,     0,     0,     0,     0,  1891,  1116,     0,  1104,  1105,
    1106,  1113,     0,  1944,  1945,  1946,  1947,  1948,  1949,     0,
    1107,     0,     0,  1108,     0,     0,     0,     0,  1112,  1114,
    1081,  1082,  1083,     0,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,
       0,     0,     0,  1116,     0,     0,  1113,     0,     0,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1950,     0,  1114,     0,     0,  1081,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
       0,  1115,     0,     0,     0,     0,  1098,  1099,  1100,  1101,
    1102,  1103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   700,  1104,  1105,  1106,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,  1108,     0,     0,     0,  1115,  1110,     0,     0,
       0,  1111,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,  1116,     0,  1104,
    1105,  1106,     0,     0,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,     0,  1097,     0,
       0,     0,  1781,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,  1113,  1082,  1083,
       0,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,     0,  1114,     0,     0,     0,  2332,
    2333,     0,  2334,  2335,  2336,     0,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,
    1103,  1109,     0,  1107,     0,     0,  1108,     0,     0,  1705,
       0,  1104,  1105,  1106,     0,   724,  1110,     0,     0,     0,
    1111,     0,     0,     0,   725,   726,     0,     0,     0,     0,
     271,   727,   728,    42,     0,     0,  1951,     0,     0,     0,
       0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,  1952,
    1107,     0,     0,  1108,     0,     0,     0,  1115,  1112,  1104,
    1105,  1106,     0,     0,     0,   729,  1892,     0,     0,     0,
     730,  1782,     0,     0,     0,     0,     0,   731,     0,     0,
       0,  1893,  2337,     0,     0,     0,  1113,     0,     0,     0,
    2338,     0,     0,     0,     0,     0,     0,     0,  1894,     0,
       0,  1895,     0,     0,  1114,   732,     0,     0,     0,     0,
       0,     0,     0,  1953,  1896,     0,     0,     0,     0,     0,
    1954,     0,     0,  1116,  2339,  1109,     0,     0,     0,     0,
       0,     0,     0,  2340,     0,     0,     0,     0,     0,     0,
    1110,     0,     0,     0,  1111,     0,     0,     0,     0,     0,
       0,     0,  1107,  3055,  1898,  1108,     0,     0,     0,  1955,
       0,     0,  2341,  2342,     0,     0,  1899,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1112,  1956,     0,     0,  1115,  1110,     0,     0,
       0,  1111,     0,  1957,  1958,  1785,    84,     0,   733,  1959,
    1107,     0,     0,  1108,     0,     0,   724,  2343,  1900,  1960,
    1113,     0,     0,     0,     0,   725,   726,     0,     0,     0,
       0,   271,   727,   728,    42,     0,     0,     0,  1114,  1112,
       0,  1961,     0,     0,  1962,  1963,     0,     0,     0,     0,
    1964,     0,     0,     0,     0,  1706,     0,  1901,     0,  2344,
       0,     0,  1116,     0,     0,     0,   729,  1113,     0,  1902,
       0,   730,     0,     0,     0,     0,     0,     0,   731,     0,
       0,  1903,  1904,     0,  1109,  1114,     0,     0,     0,  1905,
       0,     0,  1906,     0,     0,     0,     0,     0,     0,  1110,
     274,     0,     0,  1111,     0,   734,   732,  1965,     0,     0,
     735,     0,     0,  1707,     0,  2345,     0,     0,  1966,     0,
    1115,     0,     0,     0,     0,  1708,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,  1709,     0,     0,   736,     0,
       0,  1112,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,  1710,  1780,     0,     0,     0,     0,     0,
       0,     0,     0,  1711,     0,     0,  1712,  1115,     0,  1113,
       0,     0,     0,   737,     0,     0,     0,     0,     0,  1713,
       0,     0,     0,     0,     0,   738,  1116,  1114,     0,  1112,
       0,     0,     0,     0,     0,     0,     0,    84,     0,   733,
       0,     0,     0,   739,     0,     0,     0,     0,   740,     0,
       0,   741,     0,     0,     0,     0,     0,  1113,     0,     0,
       0,     0,   742,     0,     0,     0,     0,  1714,   743,     0,
       0,     0,     0,  1116,     0,  1114,     0,     0,   744,     0,
       0,     0,     0,   745,     0,     0,   746,     0,     0,   747,
       0,     0,     0,     0,     0,     0,     0,  1715,   748,   749,
       0,     0,     0,     0,     0,   724,     0,  1716,     0,  1115,
       0,     0,     0,     0,   725,   726,     0,     0,     0,     0,
     271,   727,   728,    42,     0,     0,     0,     0,  1717,     0,
       0,  1718,     0,  1719,     0,     0,   734,     0,  1132,   750,
       0,   735,     0,   751,     0,     0,     0,     0,     0,     0,
       0,   752,     0,     0,     0,   729,     0,  1115,     0,     0,
     730,  1720,   753,     0,   724,     0,     0,   731,   754,   736,
    1721,     0,     0,   725,   726,  1116,     0,     0,     0,   271,
     727,   728,    42,  2346,  2347,  2348,  2349,  2350,  2351,  2352,
    2353,  2354,  2355,   755,     0,   732,     0,     0,     0,     0,
       0,     0,     0,     0,   737,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   729,     0,   738,     0,     0,   730,
       0,     0,     0,  1116,     0,     0,   731,     0,     0,     0,
       0,     0,     0,     0,   739,     0,     0,   756,     0,   740,
       0,     0,   741,     0,   757,     0,   758,     0,     0,     0,
       0,     0,     0,   742,   732,     0,   759,   760,     0,   743,
       0,     0,     0,     0,   761,     0,     0,     0,     0,   744,
       0,     0,     0,     0,   745,   274,     0,   746,     0,     0,
     747,     0,     0,     0,     0,     0,    84,     0,   733,   748,
     749,     0,     0,     0,     0,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1097,  1088,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
     750,     0,     0,     0,   751,     0,     0,     0,     0,     0,
    1097,     0,   752,     0,     0,    84,     0,   733,     0,     0,
       0,     0,     0,   753,     0,  2159,     0,     0,     0,   754,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,
    1103,     0,     0,     0,   755,   734,     0,     0,     0,     0,
     735,  1104,  1105,  1106,     0,     0,     0,  1098,  1099,  1100,
    1101,  1102,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,  1105,  1106,     0,     0,   736,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   756,     0,
       0,     0,     0,     0,     0,   757,     0,   758,     0,     0,
       0,     0,     0,     0,   734,     0,     0,   759,   760,   735,
       0,     0,     0,   737,     0,   761,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   738,   274,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   736,     0,     0,
       0,     0,     0,   739,     0,     0,     0,     0,   740,     0,
       0,   741,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   742,     0,     0,     0,     0,     0,   743,     0,
       0,     0,   737,     0,     0,     0,     0,     0,   744,     0,
       0,     0,     0,   745,   738,     0,   746,     0,     0,   747,
       0,     0,  1107,     0,     0,  1108,     0,     0,   748,   749,
       0,     0,   739,     0,     0,     0,     0,   740,     0,     0,
     741,  1094,  1095,  1096,  1107,     0,     0,  1108,     0,     0,
       0,   742,     0,     0,     0,     0,  1097,   743,     0,     0,
       0,   271,  1889,  1890,    42,     0,     0,   744,  2518,   750,
       0,     0,   745,   751,     0,   746,  2579,  2580,   747,     0,
       0,   752,   271,  1889,  1890,    42,     0,   748,   749,     0,
       0,     0,   753,     0,     0,     0,     0,     0,   754,     0,
       0,  2581,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,     0,
       0,     0,  2581,   755,     0,     0,     0,     0,   750,  1104,
    1105,  1106,   751,     0,     0,     0,     0,     0,     0,     0,
     752,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
       0,   753,     0,     0,     0,     0,     0,   754,     0,  1110,
       0,     0,     0,  1111,     0,     0,  1109,   756,     0,     0,
       0,     0,     0,     0,   757,     0,   758,     0,     0,     0,
       0,  1110,   755,     0,     0,  1111,   759,   760,     0,     0,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,   274,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1095,  1096,     0,  1092,  1093,  1094,
    1095,  1096,     0,  1112,     0,     0,   756,   700,  1097,  1113,
       0,     0,     0,   757,  1097,   758,     0,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,   759,   760,  1114,   700,     0,
       0,  1113,     0,   761,     0,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,   274,     0,     0,     0,     0,  1114,
    1107,     0,     0,  1108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,
    1103,  1098,  1099,  1100,  1101,  1102,  1103,     0,     0,     0,
       0,  1104,  1105,  1106,     0,     0,     0,  1104,  1105,  1106,
       0,     0,     0,     0,  1098,  1099,  1100,  1101,  1102,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1115,
    1104,  1105,  1106,  1886,  1887,  1888,     0,     0,     0,   271,
    1889,  1890,    42,     0,     0,     0,     0,  1886,  1887,  1888,
       0,  1115,     0,   271,  1889,  1890,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2579,  2580,     0,     0,     0,  1891,
     271,  1889,  1890,    42,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,  1891,     0,  1116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1110,     0,     0,
       0,  1111,     0,     0,     0,     0,     0,  1116,     0,     0,
    2581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1892,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,  1108,     0,  1893,  1107,  1112,
       0,  1108,  1096,  1892,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2582,  1097,     0,  2583,  1893,     0,
       0,  1107,     0,     0,  1108,     0,     0,  1113,     0,     0,
    2584,     0,     0,     0,     0,  2582,     0,  1888,  2583,     0,
       0,   271,  1889,  1890,    42,  1114,     0,     0,     0,     0,
       0,  2584,     0,     0,     0,   700,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   700,
    2586,     0,  1098,  1099,  1100,  1101,  1102,  1103,  2225,     0,
       0,  1891,  2587,     0,     0,     0,     0,     0,  1104,  1105,
    1106,  2586,     0,     0,     0,     0,   700,     0,     0,     0,
       0,     0,     0,  2587,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,  2588,     0,     0,  1115,     0,  1110,
       0,     0,     0,  1111,     0,  1110,     0,     0,     0,  1111,
       0,     0,     0,  1109,   205,  2588,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1110,  2052,
       0,     0,  1111,  2589,     0,     0,     0,     0,     0,     0,
       0,  1112,     0,     0,     0,  2590,     0,  1112,     0,     0,
       0,     0,     0,     0,  2589,     0,     0,  2591,  2592,     0,
       0,   206,   207,  1116,     0,  2593,  2590,     0,  2594,  1113,
    1112,   208,     0,     0,     0,  1113,   274,   700,  2591,  2592,
       0,     0,     0,     0,     0,     0,  2593,  1114,     0,  2594,
       0,     0,     0,  1114,     0,     0,     0,   274,  1113,  1107,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1114,     0,     0,     0,
       0,     0,     0,     0,  1944,  1945,  1946,  1947,  1948,  1949,
    1892,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1892,  1893,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1893,
       0,     0,  1894,     0,     0,  2053,     0,     0,     0,  1115,
       0,  1892,     0,     0,     0,  1115,  1894,  2054,  1896,  1895,
       0,     0,     0,  1950,     0,     0,  1893,     0,     0,     0,
       0,     0,  1896,     0,     0,     0,     0,     0,  1115,     0,
       0,     0,     0,  2582,     0,     0,  2583,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1898,  2584,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
    1899,     0,  1898,     0,     0,  1116,  1110,     0,     0,     0,
    1111,  1116,   209,     0,  1899,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2586,
       0,     0,     0,     0,  1116,     0,     0,     0,     0,     0,
       0,  2587,  1900,     0,     0,     0,     0,     0,  1112,     0,
       0,   210,  1892,     0,     0,     0,  1900,     0,  3019,     0,
       0,     0,     0,     0,     0,     0,     0,  1893,     0,     0,
     211,     0,     0,     0,     0,     0,  1113,     0,     0,     0,
       0,  1901,     0,  2588,  1894,     0,   212,  1895,     0,     0,
       0,     0,     0,  1902,  1114,  1901,     0,     0,     0,     0,
    1896,     0,     0,     0,     0,  1903,  1904,  1902,     0,   213,
       0,     0,     0,  1905,  3020,     0,  1906,     0,     0,  1903,
    1904,   214,  2589,     0,   274,   161,     0,  1905,     0,     0,
    1906,   215,     0,     0,  2590,     0,     0,     0,   274,  3021,
    1898,     0,     0,     0,     0,     0,  2591,  2592,  3022,   216,
       0,     0,  1899,     0,  2593,     0,     0,  2594,     0,   217,
       0,     0,     0,     0,   162,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,  1115,     0,     0,     0,
       0,     0,     0,   163,  3023,     0,     0,  1951,     0,     0,
       0,     0,  3024,     0,  1900,     0,     0,     0,     0,     0,
    1952,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   219,     0,     0,     0,     0,
       0,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1901,   165,     0,     0,     0,   220,     0,
       0,     0,  1116,     0,   166,  1902,     0,     0,     0,     0,
       0,     0,     0,   221,     0,     0,     0,  1903,  1904,     0,
     222,     0,   167,   223,  1953,  1905,     0,     0,  1906,     0,
       0,  1954,   168,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,     0,   224,     0,  3025,   225,   169,   226,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   227,     0,
    1955,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,     0,   170,     0,
       0,     0,     0,     0,  1956,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1957,  1958,     0,     0,     0,     0,
    1959,   171,     0,     0,     0,     0,     0,     0,     0,     0,
    1960,     0,     0,     0,     0,     0,   172,     0,   229,     0,
       0,     0,     0,   173,     0,     0,   174,     0,     0,     0,
       0,     0,  1961,     0,     0,  1962,  1963,     0,     0,     0,
       0,  1964,     0,     0,     0,     0,     0,   175,     0,     0,
     176,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   179,
       0,     0,     0,     0,     0,     0,     0,     0,  1965,     0,
       0,     0,     0,     0,     0,     0,     0,  3026,     0,  1966
};

static const short yycheck[] =
{
       4,   718,   190,   841,   196,   330,   870,    68,   991,    13,
      14,   525,   502,    17,   449,   876,   701,   214,  1521,  1566,
     998,  1590,     0,   426,    84,   838,  1005,  1704,   741,   365,
     852,  1431,   178,  1708,   848,   849,  2001,   851,  1397,   853,
     854,  1755,    46,    47,  1386,  1295,  1296,    25,  1886,  1887,
    1400,     5,  1873,    31,  1699,  1700,  1328,    20,  1703,   120,
    2301,  2302,  2303,   484,    27,  1815,   421,    27,   509,   424,
     425,    27,     5,   390,    78,    27,     5,    81,   266,   715,
     156,   227,     5,   438,  2052,  1627,  2054,    19,    27,    93,
      68,     5,    24,    25,    26,     5,   100,    25,    26,    27,
     104,     5,   457,   107,   108,   460,   509,     5,   543,   113,
     114,   466,     5,  1033,  2415,   470,  2304,    62,   931,   474,
       5,   513,  1943,   478,   450,   100,   964,   482,   483,    25,
     485,    27,   945,   488,     5,   490,   491,   492,    19,    81,
      87,    88,   120,   498,    33,    26,   501,   473,   152,    62,
     342,   155,    25,   508,    27,   791,   160,    27,   513,  1804,
      24,    63,    26,   239,   240,   520,    27,    24,   456,    26,
       5,    27,    25,   421,    27,     5,   531,     5,    20,    27,
     535,     5,  1751,    25,   539,    27,    25,    27,    27,     5,
     545,   517,     5,   548,   198,    97,    25,   519,    27,    33,
     526,   527,     5,    91,   530,   397,     5,     5,   534,   457,
     536,   149,   460,     5,   540,     5,   542,  1892,   935,    25,
    2521,    27,   470,   511,   512,   547,   474,  1639,   550,  1939,
     478,     5,   236,   521,    27,     5,  2398,   485,   242,   274,
       5,   143,   490,   149,   492,   147,    81,    82,   700,   253,
     498,   235,     5,   501,    25,    68,    27,    70,   391,    72,
     508,     5,   134,     9,    10,   513,    12,    13,    14,    15,
      16,    17,   520,  2671,     9,    10,     5,    12,    13,    14,
      15,    16,    17,   531,  1067,    27,     5,   535,  2282,     5,
       5,   539,   339,    24,    25,    26,    27,   545,    65,    23,
     548,   190,    24,    25,    26,   366,   367,    24,    25,    26,
      27,   389,    26,    27,  1817,  1992,  2281,   190,    27,    24,
      25,    26,    27,     5,   207,     5,  1895,   229,     6,   859,
     860,     0,  2300,  2301,  2302,  2303,   618,    24,    25,    26,
      27,   344,   430,   625,  1989,   274,     5,   458,    31,   339,
     458,   190,   333,   162,   358,   189,   190,   361,     5,     5,
     274,   190,    29,    27,   538,   369,   546,     5,  1232,  2014,
    2191,    48,    49,    50,    51,    52,  2053,    56,    57,    28,
     282,   385,   284,   387,   190,     5,   900,   289,   366,   367,
     162,  2230,  2231,  2232,  2233,    24,    25,    26,    27,     5,
      27,    19,     5,  2048,   385,    84,    85,    86,   248,     5,
       5,   415,     5,   587,   374,     6,   420,   625,   422,   423,
       5,  1400,   426,   427,    25,   429,    27,     5,   432,  2397,
       6,  2399,  2001,     5,     5,  1678,   338,   617,  1681,   443,
       5,    18,    19,   616,     5,    27,   450,   470,   190,    26,
      27,   295,     5,   355,     5,   478,   589,     5,   784,   463,
      64,  1178,   353,    18,    19,    20,    21,    22,    86,   473,
     150,  2492,   476,   190,  2872,     5,   190,   619,     5,   349,
    1985,     5,   486,     5,  2053,   190,   841,     5,     5,     5,
      18,    19,    20,    21,    22,   440,   135,   136,   502,   503,
       5,  2211,   140,   190,     5,   509,   252,   274,   619,   349,
     234,   619,  2674,   517,   518,   519,   399,   252,     5,    23,
     504,     5,   526,   527,     5,   529,   530,     5,   532,     5,
     534,   578,   536,   568,     5,   344,   540,   625,   542,     5,
     544,     0,   546,   547,     5,   549,   550,     5,   552,   885,
     876,   887,   508,  1043,  1044,   426,   349,  2522,  2396,    27,
    2398,   190,   888,   190,  1016,     5,    25,   893,   283,   430,
    1820,   963,   344,  2567,     5,  1987,  1976,   344,  1019,  2893,
     658,   245,   430,   373,     5,   429,  1271,   525,   578,   190,
     532,   389,   595,   841,   258,     5,   426,   542,   426,   150,
     470,   561,   426,  2150,   353,     5,   462,   962,   963,   964,
     426,  2579,  2580,   190,  1534,  2583,  1019,   391,   514,   525,
     595,   391,   389,   426,   283,   371,   391,   426,  2929,   542,
     470,   470,  1146,   556,   426,   242,   371,   589,   391,   568,
    2828,   513,   384,   553,  1158,   391,   550,   391,  2195,  2294,
     654,   359,   550,   546,   568,    27,   981,  2204,  2205,   430,
    2229,   546,   391,   245,   553,   982,  2235,  2236,  2237,  2238,
    2239,  2240,   391,   395,  1164,   391,   258,   550,   625,   683,
       5,   685,   428,   611,   617,  1321,  1322,   619,   410,    23,
     395,  1221,  2513,   428,  1330,  2996,   700,   384,   458,  1482,
    3014,  1142,  1485,   666,   539,   410,   666,   661,   589,   391,
     666,   715,  2281,   391,   962,   963,   964,  1539,  1040,   553,
     724,   725,   726,  1045,  1046,  2475,  1147,   666,  2000,  2479,
     234,  2445,  2074,  1446,  1224,  2277,   740,  1373,  2097,  1142,
    1062,  2094,   746,   747,   391,   391,  3047,   751,  3049,  2099,
     638,   639,   640,   641,   642,   619,   585,   384,   611,  1249,
      14,  2406,   619,  2408,  1254,  1744,   395,   475,  1581,   611,
     576,   391,   544,  2794,    10,   454,   678,   245,  2283,  2284,
     784,   410,  2025,   387,   521,   391,   500,   791,   391,    27,
     258,   626,   112,   601,   395,   391,   391,   436,   391,   486,
     391,   568,  2796,  2797,   617,   577,   391,   157,   412,  1244,
     556,   475,   625,   391,  2835,   391,  1795,  1655,   190,   391,
     391,   556,  1148,  1149,  1150,  2225,   391,   491,   576,  3070,
     391,    27,  2401,   837,   838,  2800,  2674,  1159,   391,   366,
     554,   470,  1168,   391,  2884,  2813,  2886,   324,   430,  2524,
     430,  2819,  2820,   430,  2822,  2823,  2824,  2825,   362,  2601,
      27,   391,   541,  2831,   331,   535,   104,   391,   616,   391,
    2439,   426,   876,   391,   391,   391,   622,   585,  2717,   425,
     538,   648,   649,   650,   888,   174,   391,   622,   619,   893,
     391,   495,   659,   475,   898,  1409,  1222,   619,   426,   157,
     234,   430,   619,   339,   391,   584,   583,   391,   359,   491,
     391,   391,   916,   391,   619,   391,   154,  1243,   994,  2169,
     391,   997,   167,  2568,   360,   391,   453,   931,  1250,   587,
     391,   430,   619,   391,  1260,    18,    19,    20,    21,    22,
     624,   945,   469,   458,  1270,   425,   296,  2300,  2301,  2302,
    2303,   391,   190,  2522,   192,  1015,    25,  2504,    27,   538,
     391,  2530,   430,   647,  2533,  2534,  2535,  2536,   458,  2790,
    1292,  1293,  2617,  2812,  1162,  2814,  2815,  2816,  2817,    26,
    1268,   391,   271,  2951,   588,   512,  2954,  2955,  2956,  2957,
     619,   391,   324,   430,   190,   999,   600,   601,   355,  1003,
    1004,  1005,   361,   480,   608,    26,    27,   475,   587,  1645,
     369,  2418,  1016,   249,  2421,  1019,  2820,  1021,  1022,    20,
     457,  1025,   372,   491,   475,   552,    27,  2831,   362,  2583,
     163,    26,    27,   166,   335,   460,  1040,  1041,   296,  1043,
    1044,  1045,  1046,  3083,  1048,   346,   513,  1051,   856,   474,
    1564,   289,   248,   478,   581,   863,   415,   524,  1062,   430,
    1064,  1925,   366,   590,  1068,   490,  2808,  2809,   430,    28,
      29,  2049,  1076,   458,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  3062,   443,   458,   398,  2773,   589,
     430,  2776,  3070,   198,  1108,  1109,    20,   202,  2677,  1113,
    2038,  1115,   413,    27,   372,   463,  2044,  1631,  2096,   357,
    2099,   190,  1612,  1613,   492,   475,  1130,   365,   476,   619,
     430,   369,    20,   501,   585,  1423,    20,   270,  1142,    27,
     273,   491,   578,    27,  1148,  1149,  1150,   624,   480,   453,
     386,   430,   388,  1991,   430,  1159,  2833,  1161,  2803,  1163,
    1164,  2772,   295,  1489,  1168,   469,   643,   644,   406,   190,
    2570,  1526,   430,  1319,   341,  2013,   533,   545,  1504,  1325,
     548,   430,   349,   350,  2795,    25,   663,    27,  2922,  2923,
     547,    26,    27,   438,  1482,   190,  2807,  1485,   480,  2942,
     238,   502,  1528,   366,   449,  2948,  1532,   374,   512,  2778,
     377,  1533,    25,   430,    27,   572,  1552,   475,  1222,   430,
    1224,  1735,  1907,    26,   282,   470,  2579,  2580,   395,    19,
    2583,  2800,   477,   491,    24,   473,    26,   295,   238,  1243,
      25,   458,    27,  1247,   430,  1249,  1250,  1573,   552,  2894,
    1254,   282,   625,   366,  1258,  1259,  1260,   295,   638,  2813,
      20,   641,   642,   620,   295,  2819,  1270,    27,  2822,  2823,
    2824,  2825,   430,    25,   512,    27,    20,   581,  1526,  1634,
    1284,   625,  1796,    27,  1798,  1361,   590,  1291,  1292,  1293,
     453,    20,   624,  1807,  1370,   295,   429,  2110,    27,   537,
    1655,    26,    27,  3037,  1626,  3039,   469,   624,   391,   347,
     619,   643,   644,   351,  1318,    26,  2669,  1321,  1322,  2672,
    2889,    25,  1326,    27,  1328,    20,  1330,  3004,    30,   646,
     647,   663,    27,   500,  2945,    26,  1284,    25,  1974,    27,
     453,    26,   624,   581,    46,    47,    25,   347,    27,   512,
     190,   351,   590,   448,   449,   190,   469,    26,     5,  2220,
      26,   643,   644,  1853,   457,   458,    25,  2189,    27,  1373,
      25,   429,    27,  2186,    25,   531,    27,   190,  2947,   535,
    2016,   663,  1386,   539,   458,   163,  1634,   554,   166,   552,
      25,   429,    27,  1397,   561,    26,  1400,  2951,   429,   512,
    2954,  2955,  2956,  2957,    26,   190,    25,  1655,    27,  2273,
      26,  1737,  2915,   191,   624,  1419,  1420,  1421,   581,    26,
     122,   123,    26,   125,   126,  2994,    26,   590,   130,   429,
      25,   163,    27,   366,   166,   619,   646,   647,   190,   552,
      58,  2088,  3087,  2090,  2091,   147,   148,   295,   543,  2427,
     391,  1455,  1456,  1457,   430,  1459,  2435,  1745,   553,   191,
    2813,   639,   640,   165,  1366,   190,  2819,  2820,   581,  2822,
    2823,  2824,  2825,  1799,  1800,  1801,  1802,   590,  2831,    25,
      26,   546,  1486,   361,   549,  1489,  1490,   552,    24,   366,
      26,  3038,   270,   619,    25,   273,    27,  1823,   438,   347,
    1504,    26,   190,   351,   612,   613,   614,   615,  3062,   449,
      25,  2864,    27,  3016,   430,  1918,  3085,   295,  1522,   430,
     453,   108,   109,   110,  1528,   426,  1530,  1531,  1532,  1533,
     470,   190,  3035,   457,   458,   190,   469,   477,   270,   190,
      25,   273,    27,    24,  1736,    26,     5,  1551,  1836,    24,
      30,    26,   391,  1879,  3123,   190,   458,  1143,  1562,  1145,
     287,   288,  1566,   295,  1761,   619,    46,    47,    26,  1573,
     426,   190,   258,   641,   642,    55,   453,  1581,   361,   512,
      60,   429,   391,  1587,  1588,    20,  1590,   648,   649,  2103,
    2579,  2580,   469,  3096,    26,   118,   133,  1885,  2951,    26,
     430,  2954,  2955,  2956,  2957,    19,   648,   649,  1612,  1613,
      24,    25,    26,   260,    26,    26,   857,   858,    26,   552,
     861,   862,  1626,   718,    20,   105,   106,   457,   458,   430,
    1985,  2495,   366,   113,    26,   512,  1991,  2990,    26,  2153,
      26,  1645,   122,   123,   619,   125,   126,  2630,   581,    30,
     130,   429,   299,   391,   356,     5,   430,   590,  2013,   302,
    1664,   391,   199,   391,   201,    46,    47,   147,   148,   764,
     391,   318,   391,  1677,  1678,   552,   391,  1681,  2004,   216,
    2006,   391,     5,   457,   458,   165,   623,   224,   391,   302,
     520,   228,   391,  1697,    75,  1699,  1700,   429,   221,  1703,
    1704,   391,   239,   405,   581,   623,   229,   391,   391,  3062,
     357,   619,   235,   590,   237,   458,   253,  3070,   430,   453,
     616,   619,   369,     8,   478,   248,  1730,   525,   426,  1733,
     430,   420,   379,  1737,   430,   469,   430,  1985,   430,   266,
    1744,   122,   123,  1991,   125,   126,   520,  1751,   430,   130,
     397,    46,    47,   276,    18,    19,    20,    21,    22,   430,
     407,     5,   430,   430,   466,  2013,   147,   148,   430,   292,
     430,   617,   430,  2263,   297,  2265,   423,   430,   512,  1783,
     430,   430,  1786,  2500,   165,   430,   309,   459,   430,   430,
     430,  1795,   430,   316,   430,  1799,  1800,  1801,  1802,   617,
    1804,   133,   425,   430,  2440,   430,  1810,  1811,   595,   430,
    1814,  1815,   420,   430,   658,   438,   463,   658,   552,  1823,
       6,     7,     8,     9,    10,    11,    12,   122,   123,  1833,
     125,   126,   430,  2159,   326,   130,  2162,     8,   596,   486,
     935,     5,     5,   466,   459,   383,   430,   581,   430,  1853,
     430,   430,   147,   148,   501,   236,   590,   430,   344,   482,
     483,   508,    20,    21,   511,   488,   589,   199,   491,   201,
     165,   578,  2736,     8,    14,  1879,     5,   658,   575,     5,
    2744,   658,  1886,  1887,   216,   532,   420,   367,   535,   430,
     537,  1895,   224,    26,  2220,    62,   228,   430,    26,  2334,
    2335,  2336,  1906,  2338,  2339,  2340,  2341,  2342,  2343,   556,
    2595,    65,  2347,   393,  1918,    91,   458,    26,  2432,   366,
       5,   253,  1926,   458,   589,   595,   619,   574,  2283,  2284,
     430,    61,   430,   430,    92,    93,    94,    95,    96,    97,
     470,   236,    20,    20,   625,     5,   430,   470,  2462,   625,
       5,     6,     7,     8,   477,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   135,   136,
    1974,   625,   624,   430,   430,   356,   499,  2038,   430,   350,
      35,   504,   556,  2044,   464,  1989,   661,     5,  1992,    19,
      18,    26,    26,   152,  2832,  1999,  2000,  2001,   218,    25,
    2004,   589,  2006,   133,   481,    34,   453,    36,    37,    38,
    2014,   622,  2016,    18,    19,    20,    21,   578,   481,     5,
     619,  2025,   469,   190,   405,   546,   150,  2219,   546,   196,
      26,   399,   321,   546,    26,  2283,  2284,    92,    93,    94,
      95,    96,    97,   430,  2048,   430,   430,  2051,  2912,  2053,
     430,   430,   391,   108,   109,   110,   437,    35,   663,  1762,
    2038,  2065,   619,  1766,   576,   512,  2044,   458,  1771,   199,
    2074,   201,  1775,  2709,  1777,  1778,  1779,   557,   546,   391,
     391,   391,   391,  1178,   391,   466,   216,    92,    93,    94,
      95,    96,    97,  2097,   224,  2099,    26,   391,   228,   266,
     391,   268,   430,  2107,   391,   552,  2110,   616,   625,     5,
    2114,     5,     5,   579,    92,    93,    94,    95,    96,    97,
     619,     5,   159,   253,   482,   391,   430,   430,     5,   625,
     108,   109,   110,   624,   581,     8,    26,    26,   175,   176,
     535,    65,   437,   590,   325,  2149,  2150,   184,     5,  1244,
       5,   391,   430,   430,   360,  2159,   596,   637,  2162,   420,
    2486,  2483,    14,  2167,   625,   645,   420,     5,  2490,   659,
     546,     5,   550,    26,   100,   342,  2180,   430,  2182,   625,
    2184,   218,  2186,   619,   430,   624,     5,  3051,  2192,  2515,
     227,  2195,   426,   638,   249,   426,  2200,   252,   460,     8,
    2204,  2205,   460,  2920,  1299,  3019,  3020,  3021,  3022,  3023,
    3024,   430,    25,   430,   430,   430,  2220,   430,  2544,   256,
     430,   430,     5,  2227,  2738,  2229,    26,    26,   589,   391,
     397,  2235,  2236,  2237,  2238,  2239,  2240,    25,   391,    25,
      25,   270,   391,    25,   273,  2735,   275,   391,  2884,     5,
    2886,    20,    21,   619,     5,   619,   972,   619,     8,  2263,
     553,  2265,   325,    25,   301,   344,   295,   434,   344,   458,
     619,   249,   344,   430,   252,   425,   305,  2281,   360,  2227,
     458,     5,   430,   430,   430,   430,    26,   430,   430,  2477,
    2294,   430,     5,   650,     5,   324,  2300,  2301,  2302,  2303,
    2304,  2305,   469,    25,  2629,    14,   343,    14,   475,    26,
     477,  2315,  2316,  2317,   481,   595,   371,   484,   347,  2323,
     487,   595,   351,    92,    93,    94,    95,    96,    97,   430,
     497,   386,   616,   619,    30,   390,   619,    18,    19,    20,
       5,     5,     5,    24,    25,    26,    27,   430,     7,   516,
      46,    47,  2300,  2301,  2302,  2303,   523,   524,   525,   391,
       5,     8,   529,   619,   177,   625,    26,   619,    26,    26,
     537,   391,   391,   428,   625,    26,   625,   589,   391,   391,
    2384,   391,  2386,    64,   391,   391,   553,    20,     5,  2903,
     391,   566,  2396,   371,  2398,   274,     5,  2401,     5,     5,
     429,   456,  2406,  2407,  2408,   546,     5,   391,   386,   391,
     571,   625,   390,   440,  2740,   619,   619,   391,   470,   474,
       6,   430,    25,   625,    27,     5,   122,   123,   553,   125,
     126,  2435,   625,   210,   130,  2439,  2440,    25,   623,   623,
    3157,    25,    25,    46,    47,   618,   446,  3083,    25,  2453,
     428,   147,   148,    25,   470,    26,    26,    26,    26,    34,
      26,    36,    37,    38,   430,   430,    26,   296,    26,   165,
       5,  2475,   391,   391,  2478,  2479,   268,  2832,   456,  2483,
     525,   589,  2486,     5,   467,   430,  2490,   391,   550,    25,
     426,   304,   240,   391,   391,  1590,   474,   310,   311,   312,
    2504,   556,     5,   440,   344,    20,   553,   139,   430,   190,
     430,  2515,     5,   430,   430,   430,   430,   330,  2522,   122,
     123,   430,   125,   126,     5,    14,  2530,   130,   619,  2533,
    2534,  2535,  2536,  2537,   210,     5,   441,   458,    26,    26,
    2544,   391,   391,   391,   147,   148,   391,     5,   368,   618,
     331,   718,   430,   568,   391,   373,   391,  2561,    26,   391,
     240,   391,   165,   430,  2568,   344,   391,   622,   241,   625,
     458,   575,   430,  2577,   391,  2579,  2580,   391,   556,  2583,
     391,   391,   546,   391,  2832,   391,   619,   190,    14,   239,
    2594,   239,     7,    26,   625,   391,   447,    34,    26,    36,
      37,    38,  1697,   392,   430,   619,   430,   391,   625,  1704,
     426,   391,     5,  2617,   625,  2619,   391,   430,     5,   391,
      25,   788,   241,   391,   391,   438,   391,   391,   441,     5,
     391,  2579,  2580,   236,   391,  2583,  1352,  1353,   391,  2199,
    3106,  2149,  2107,  1359,   622,  1869,  1574,  1261,    38,    40,
     366,  1811,  1817,   289,  2180,   147,  1751,   143,   211,   283,
     399,   290,   355,   213,   831,  2669,  1769,   373,  2672,  2448,
    2674,   484,   318,  2677,   317,   385,    18,    19,    20,    21,
     847,   848,   849,   387,   851,  1365,   853,   854,  1366,  3096,
    1489,  1436,   859,   860,  1786,   270,   529,   969,   273,  1682,
     275,  1675,  1801,  1532,  3030,  2709,   519,  2254,  1291,  2713,
    2547,  2715,  1604,  1294,   395,  1922,  3121,  1805,  1621,  2752,
     295,  2669,  1164,    25,  2672,   120,   539,   540,    31,   410,
     305,  2735,  2651,   900,  2926,    31,  2740,   550,   487,   268,
    1585,  1579,   555,   656,   911,   685,   427,  1299,  1920,   430,
      92,    93,    94,    95,    96,    97,  1588,   936,  2648,  2849,
    3035,  1155,   443,  1637,  1219,  2374,  2236,  2859,   935,   936,
    1145,   888,   347,  1243,  2778,  1072,   351,   944,  2372,  2047,
    1025,   594,  2356,  1795,  1380,  1985,  3123,  3087,  2017,  2972,
    2405,  1886,  1887,   960,   961,  2048,  2800,  1403,  1703,  2803,
    1895,   482,   483,  2384,  2709,  2441,  2672,  2811,  2051,  2813,
    1318,  2386,  2990,   626,   495,  2819,  2820,  3143,  2822,  2823,
    2824,  2825,    25,  2683,  2828,  2065,  2830,  2831,    17,  2833,
    2895,  2317,  2896,   270,   437,  2578,   273,  2841,   275,  2295,
    1556,  2439,   965,  3085,  2235,  2939,  1313,   961,  1286,  2577,
    2811,  2830,  2819,  1733,   429,  1160,   537,   364,   295,    -1,
      -1,    -1,    -1,  2811,    -1,  2813,    -1,    -1,   305,    -1,
      -1,  2819,  2820,    -1,  2822,  2823,  2824,  2825,    -1,    -1,
    2884,    -1,  2886,  2831,  1600,  2889,    -1,   324,    -1,    -1,
    2894,    -1,  2896,    -1,    -1,   576,    -1,  1992,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2001,   588,    -1,    -1,
     347,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,   600,
     601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,
     611,    -1,    -1,    -1,    -1,  2939,    -1,    -1,   619,    -1,
      -1,    -1,    -1,  2947,    -1,    -1,    -1,  2951,    -1,    -1,
    2954,  2955,  2956,  2957,  2958,    -1,  2051,    -1,  2053,    -1,
      -1,    -1,    -1,    -1,  1131,    -1,    -1,    -1,  2972,    -1,
      -1,    -1,    -1,    -1,   177,    -1,  1143,    -1,  1145,  1146,
    1147,    -1,    -1,    -1,    -1,    -1,  2990,  1154,  1155,    -1,
    2994,  1158,   429,    -1,    -1,  1162,    -1,    -1,  1165,  2094,
    3004,    -1,    -1,  2951,    -1,    -1,  2954,  2955,  2956,  2957,
       8,  1178,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,  3030,  3031,    -1,    -1,
      -1,    -1,    -1,    -1,  3038,    -1,    -1,    35,    -1,    -1,
      -1,    -1,  2990,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1221,    -1,    -1,    -1,  3062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3070,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3083,
      -1,  3085,    -1,  3087,    -1,    -1,    -1,    -1,    -1,  1256,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,   304,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,
     108,   109,   110,  1280,  3062,    -1,    -1,    -1,  1285,  3123,
      -1,    -1,  3070,    -1,    -1,    -1,    -1,   330,    -1,    -1,
      -1,  1298,  1299,    -1,  2229,    -1,    -1,    -1,    -1,  3143,
    2235,  2236,  2237,  2238,  2239,  2240,    -1,  1863,  1864,    -1,
      -1,   724,   725,   726,    -1,    -1,    -1,    -1,  1874,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,    -1,    -1,
      -1,    -1,    -1,   746,   747,    -1,    -1,    -1,   751,    16,
      17,    18,    19,    20,    21,    22,  2281,  1354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,  2300,  2301,  2302,  2303,    -1,
      -1,  1927,  1928,  1929,  1930,    -1,    -1,    -1,    -1,  1935,
    1936,  1937,  1938,    -1,    -1,    -1,  1942,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   438,    -1,    -1,   441,  2334,
    2335,  2336,  1409,  2338,  2339,  2340,  2341,  2342,  2343,    -1,
      -1,   249,  2347,    -1,   252,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2384,
      -1,  2386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2396,    -1,  2398,    -1,    -1,  2401,    -1,    -1,    -1,
    2026,  2027,    -1,    -1,    -1,    -1,   519,  2033,  2034,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    -1,    -1,
      -1,    -1,    -1,    -1,  2439,    -1,    -1,   550,    -1,    -1,
      -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,  1545,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1553,    -1,   386,    -1,
      -1,   594,   390,    -1,    -1,    -1,    -1,  1564,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2500,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,   252,    -1,    -1,  1585,    -1,
      -1,    -1,    -1,   626,    -1,    -1,    -1,  2522,    -1,    -1,
     428,    -1,    -1,    -1,    -1,  2530,    -1,    -1,  2533,  2534,
    2535,  2536,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2170,  2171,    -1,    -1,   456,    -1,
      -1,    -1,    -1,  2179,  1631,  1632,  1633,    -1,  1041,    -1,
    1637,    -1,    -1,    -1,    -1,  1048,   474,    -1,  1051,    -1,
      -1,    -1,    -1,    -1,  2579,  2580,    -1,    -1,  2583,    -1,
      -1,  1064,  2208,  2209,    -1,  1068,    -1,    -1,    -1,    -1,
      -1,    -1,  1669,  1076,    -1,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   371,  1108,  1109,    -1,    -1,    -1,
    1113,    -1,  1115,    -1,    -1,    -1,    -1,    -1,  2264,   386,
    2266,    -1,    -1,   390,    -1,    -1,    -1,    -1,   556,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,  1736,
      -1,    -1,    -1,    -1,  2669,    -1,    -1,  2672,    -1,  2674,
      -1,   128,  2677,    17,    18,    19,    20,    21,    22,    -1,
     137,   428,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,
      -1,    35,    -1,    -1,   151,    -1,    -1,    -1,  2324,  2325,
      -1,    -1,  2328,  2329,    -1,    -1,    -1,    -1,    -1,   456,
      -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,  1796,
      -1,  1798,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,  2362,    -1,   195,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   203,    -1,    92,    93,
      94,    95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,  1844,    -1,    -1,
      -1,    -1,    -1,  2778,     5,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,  2800,  1873,    -1,    -1,    -1,
      -1,    -1,   259,    -1,    35,    -1,    -1,    -1,  2813,   556,
      -1,    -1,    -1,    -1,  2819,  2820,    -1,  2822,  2823,  2824,
    2825,    -1,    -1,    -1,    -1,    -1,  2831,   284,  2833,    -1,
      -1,    -1,    -1,    -1,   291,    -1,   293,    -1,    -1,    -1,
      -1,    -1,  1919,  1920,    -1,    -1,   303,    -1,    -1,    -1,
    2476,    -1,    -1,    -1,  2480,    -1,    -1,    -1,    -1,  2864,
      -1,    92,    93,    94,    95,    96,    97,  2493,    -1,    -1,
      -1,    -1,   329,    -1,    -1,   622,    -1,   108,   109,   110,
     337,    -1,    -1,    -1,  2889,  2511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,  2920,    -1,   374,    23,  2545,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      -1,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2947,   400,    -1,    -1,  2951,  2024,    -1,  2954,
    2955,  2956,  2957,    -1,    -1,    -1,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1455,  1456,  1457,    -1,  1459,    -1,    -1,    -1,
      -1,   438,    -1,    -1,    -1,  2990,    91,    -1,    -1,  2994,
      -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,     9,  3004,
      -1,    -1,    -1,  1486,    -1,    -1,    -1,    18,    19,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,   249,    -1,
       9,   252,    -1,    -1,    -1,    -1,  2103,   371,   133,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,    -1,   386,    18,    19,    20,   390,    -1,    -1,    24,
      25,    26,    27,    64,    -1,    -1,    -1,  3062,   163,    -1,
      -1,   166,    -1,    -1,    -1,  3070,    -1,    -1,  1551,    -1,
      -1,    -1,    -1,    -1,    -1,    64,  2153,    -1,    -1,    -1,
    3085,    -1,    -1,  1566,   428,    -1,   191,    -1,    -1,    64,
      -1,   548,   549,   550,   199,    -1,   201,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   561,   210,    -1,    -1,    -1,    -1,
      -1,   216,   456,    -1,    -1,    -1,    -1,    -1,  3123,   224,
    2197,    -1,  2199,   228,  2201,    -1,    -1,    -1,    -1,   234,
     474,    -1,    -1,   238,   239,   240,   241,  2214,    -1,    -1,
     371,    -1,  2219,  2769,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,  3157,    -1,    -1,   386,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,   270,    -1,    -1,   273,    -1,
     275,    -1,    -1,    -1,    -1,    -1,    -1,   282,    -1,   190,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     295,    -1,    -1,    -1,    -1,    -1,    -1,   428,  2275,  2276,
     305,   190,    -1,    -1,    -1,    -1,    -1,   664,    -1,    -1,
      -1,    -1,   556,    -1,    -1,   190,    -1,    -1,    -1,   324,
     325,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   339,    -1,    -1,    -1,    -1,    -1,
      -1,  2318,   347,   474,    -1,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,   361,   362,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   622,    -1,
      -1,  2358,    -1,   294,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,  2371,    -1,    -1,    -1,  2924,    -1,
    1783,    -1,    -1,  1786,    -1,   294,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   429,   556,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   440,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,  2977,  2978,    -1,  2980,  2432,  2982,  2983,    -1,    -1,
     108,   109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,  2462,    -1,    -1,    -1,    -1,
      -1,   622,    -1,    92,    93,    94,    95,    96,    97,   410,
    2477,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,  2492,   427,    -1,    -1,   430,
     395,   410,    -1,  2500,  3050,    -1,    -1,    -1,    -1,    -1,
      -1,   442,   443,    -1,    -1,   410,    -1,   542,   427,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,  3074,    -1,
    3076,    -1,   427,   442,   443,   430,    -1,    -1,    -1,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,    -1,
      -1,    -1,   483,   578,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,  3111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   483,   470,    -1,    -1,    -1,    -1,
      -1,   249,    -1,    -1,   252,    -1,   495,    -1,   483,    -1,
      -1,  3137,  3138,    -1,    -1,  3141,    -1,    -1,    -1,   624,
     495,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,   638,   639,   640,   641,   642,   643,   644,
      -1,   646,   647,    -1,    -1,    -1,    -1,    -1,   537,    -1,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,   663,    -1,
      -1,    -1,   537,    -1,    -1,   576,    -1,    -1,    -1,    -1,
      -1,  2648,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   576,    -1,   600,
     601,    -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,   588,
     611,   576,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,
      -1,   600,   601,   588,    -1,    -1,    -1,    -1,    -1,   608,
      -1,    -1,   611,   371,    -1,   600,   601,    -1,    -1,    -1,
     619,    -1,    -1,   608,    -1,    -1,   611,    -1,   386,    -1,
      -1,    -1,   390,   391,   619,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2738,    -1,    -1,    -1,    -1,  2149,  2150,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     428,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,   391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   456,  2192,
      -1,    -1,  2195,    -1,    -1,    -1,    -1,  2794,    -1,    -1,
      -1,  2204,  2205,    -1,    -1,    -1,   474,    -1,    -1,   428,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,   456,  2835,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2849,    -1,    -1,   474,    -1,  2854,    -1,  2856,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,   556,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2895,    -1,
      92,    93,    94,    95,    96,    97,  2903,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,    -1,
      -1,    -1,    -1,  2920,    -1,    -1,    -1,    -1,    -1,  2926,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,    -1,
      -1,    30,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,   622,    -1,    45,    46,    47,   108,
     109,   110,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3019,  3020,  3021,  3022,  3023,  3024,   117,    -1,
     119,   120,   121,   122,   123,   124,   125,   126,   127,    -1,
     129,   130,   131,   132,    -1,    -1,    -1,    -1,    -1,   138,
    2453,    -1,   141,    -1,   143,   144,   145,   249,   147,   148,
     252,    -1,    -1,    -1,   153,    -1,   155,   156,    -1,   158,
      -1,   160,   161,    -1,    -1,   164,   165,    -1,    -1,   168,
     169,   170,    -1,   172,   173,    -1,    -1,    -1,   177,   178,
     179,    -1,   181,    -1,    -1,    -1,   185,    -1,   187,   188,
     249,  2504,    -1,   252,   193,    -1,    -1,    -1,   197,    -1,
      -1,   200,    -1,   202,    -1,   204,    -1,   206,    -1,   208,
     209,    -1,   211,   212,   213,    -1,    -1,    -1,   217,    -1,
     219,   220,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,    -1,    -1,   246,   247,    -1,
    3157,   250,   251,    -1,    -1,   254,   255,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   264,   265,    -1,   267,   371,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   277,   278,
     279,    -1,   281,    -1,   386,    -1,   285,   286,   390,   391,
      -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   298,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   306,   307,   308,
      -1,    -1,   371,    -1,    -1,   314,   315,    -1,    -1,    -1,
      -1,   320,    -1,    -1,   323,    -1,   428,   386,   327,   328,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   338,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   456,    -1,    -1,   356,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,   428,
      -1,   370,   474,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   393,    -1,    -1,   456,    -1,    -1,
      -1,   400,    -1,   402,   403,    -1,    35,    -1,    -1,    -1,
      -1,    -1,   411,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   450,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,    92,    93,    94,    95,    96,    97,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   492,   493,    -1,    -1,   556,   497,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     509,    -1,    -1,    -1,    -1,    -1,   515,   516,   517,   518,
     622,    -1,    -1,   522,    -1,    -1,    -1,   526,    -1,    -1,
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
      96,    97,    -1,    -1,    -1,  3038,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,   371,   482,   483,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,   386,   556,    -1,    -1,
     390,   391,    92,    93,    94,    95,    96,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    64,   622,    -1,   108,   109,
     110,   456,    -1,    39,    40,    41,    42,    43,    44,    -1,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,   428,   474,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,   622,    -1,    -1,   456,    -1,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,   474,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    92,    93,    94,    95,
      96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   108,   109,   110,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,   249,
      -1,    -1,   252,    -1,    -1,    -1,   556,   386,    -1,    -1,
      -1,   390,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,   108,
     109,   110,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   622,    -1,    -1,    -1,    -1,   456,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,   474,    -1,    -1,    -1,    73,
      74,    -1,    76,    77,    78,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,   371,    -1,   249,    -1,    -1,   252,    -1,    -1,    63,
      -1,   108,   109,   110,    -1,     9,   386,    -1,    -1,    -1,
     390,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,   332,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,   345,
     249,    -1,    -1,   252,    -1,    -1,    -1,   556,   428,   108,
     109,   110,    -1,    -1,    -1,    59,   395,    -1,    -1,    -1,
      64,   441,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
      -1,   410,   176,    -1,    -1,    -1,   456,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,    -1,
      -1,   430,    -1,    -1,   474,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   409,   443,    -1,    -1,    -1,    -1,    -1,
     416,    -1,    -1,   622,   218,   371,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     386,    -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   482,   483,   252,    -1,    -1,    -1,   455,
      -1,    -1,   256,   257,    -1,    -1,   495,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   428,   479,    -1,    -1,   556,   386,    -1,    -1,
      -1,   390,    -1,   489,   490,   441,   190,    -1,   192,   495,
     249,    -1,    -1,   252,    -1,    -1,     9,   301,   537,   505,
     456,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,   474,   428,
      -1,   527,    -1,    -1,   530,   531,    -1,    -1,    -1,    -1,
     536,    -1,    -1,    -1,    -1,   299,    -1,   576,    -1,   343,
      -1,    -1,   622,    -1,    -1,    -1,    59,   456,    -1,   588,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,   600,   601,    -1,   371,   474,    -1,    -1,    -1,   608,
      -1,    -1,   611,    -1,    -1,    -1,    -1,    -1,    -1,   386,
     619,    -1,    -1,   390,    -1,   289,    99,   593,    -1,    -1,
     294,    -1,    -1,   357,    -1,   399,    -1,    -1,   604,    -1,
     556,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    -1,    -1,   379,    -1,    -1,   322,    -1,
      -1,   428,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,   397,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   407,    -1,    -1,   410,   556,    -1,   456,
      -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,   423,
      -1,    -1,    -1,    -1,    -1,   369,   622,   474,    -1,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,
      -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,   392,    -1,
      -1,   395,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,
      -1,    -1,   406,    -1,    -1,    -1,    -1,   471,   412,    -1,
      -1,    -1,    -1,   622,    -1,   474,    -1,    -1,   422,    -1,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,   433,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,   442,   443,
      -1,    -1,    -1,    -1,    -1,     9,    -1,   511,    -1,   556,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,   532,    -1,
      -1,   535,    -1,   537,    -1,    -1,   289,    -1,   482,   483,
      -1,   294,    -1,   487,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   495,    -1,    -1,    -1,    59,    -1,   556,    -1,    -1,
      64,   565,   506,    -1,     9,    -1,    -1,    71,   512,   322,
     574,    -1,    -1,    18,    19,   622,    -1,    -1,    -1,    24,
      25,    26,    27,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   537,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    59,    -1,   369,    -1,    -1,    64,
      -1,    -1,    -1,   622,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   387,    -1,    -1,   581,    -1,   392,
      -1,    -1,   395,    -1,   588,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    99,    -1,   600,   601,    -1,   412,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,   422,
      -1,    -1,    -1,    -1,   427,   619,    -1,   430,    -1,    -1,
     433,    -1,    -1,    -1,    -1,    -1,   190,    -1,   192,   442,
     443,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     483,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,
      35,    -1,   495,    -1,    -1,   190,    -1,   192,    -1,    -1,
      -1,    -1,    -1,   506,    -1,   508,    -1,    -1,    -1,   512,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    -1,    -1,    -1,   537,   289,    -1,    -1,    -1,    -1,
     294,   108,   109,   110,    -1,    -1,    -1,    92,    93,    94,
      95,    96,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   588,    -1,   590,    -1,    -1,
      -1,    -1,    -1,    -1,   289,    -1,    -1,   600,   601,   294,
      -1,    -1,    -1,   357,    -1,   608,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   369,   619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,
      -1,    -1,    -1,   387,    -1,    -1,    -1,    -1,   392,    -1,
      -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,   412,    -1,
      -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    -1,   427,   369,    -1,   430,    -1,    -1,   433,
      -1,    -1,   249,    -1,    -1,   252,    -1,    -1,   442,   443,
      -1,    -1,   387,    -1,    -1,    -1,    -1,   392,    -1,    -1,
     395,    20,    21,    22,   249,    -1,    -1,   252,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    35,   412,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,   422,   482,   483,
      -1,    -1,   427,   487,    -1,   430,    18,    19,   433,    -1,
      -1,   495,    24,    25,    26,    27,    -1,   442,   443,    -1,
      -1,    -1,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    -1,
      -1,    -1,    64,   537,    -1,    -1,    -1,    -1,   483,   108,
     109,   110,   487,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,
      -1,   506,    -1,    -1,    -1,    -1,    -1,   512,    -1,   386,
      -1,    -1,    -1,   390,    -1,    -1,   371,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   588,    -1,   590,    -1,    -1,    -1,
      -1,   386,   537,    -1,    -1,   390,   600,   601,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,    -1,    -1,   619,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    18,    19,    20,
      21,    22,    -1,   428,    -1,    -1,   581,   190,    35,   456,
      -1,    -1,    -1,   588,    35,   590,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,   600,   601,   474,   190,    -1,
      -1,   456,    -1,   608,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,   619,    -1,    -1,    -1,    -1,   474,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,
      97,    92,    93,    94,    95,    96,    97,    -1,    -1,    -1,
      -1,   108,   109,   110,    -1,    -1,    -1,   108,   109,   110,
      -1,    -1,    -1,    -1,    92,    93,    94,    95,    96,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,
     108,   109,   110,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    18,    19,    20,
      -1,   556,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    64,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   371,    64,    -1,   622,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,   252,    -1,   410,   249,   428,
      -1,   252,    22,   395,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   427,    35,    -1,   430,   410,    -1,
      -1,   249,    -1,    -1,   252,    -1,    -1,   456,    -1,    -1,
     443,    -1,    -1,    -1,    -1,   427,    -1,    20,   430,    -1,
      -1,    24,    25,    26,    27,   474,    -1,    -1,    -1,    -1,
      -1,   443,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     483,    -1,    92,    93,    94,    95,    96,    97,   470,    -1,
      -1,    64,   495,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   483,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,
      -1,    -1,    -1,   495,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,
     371,    -1,    -1,    -1,   537,    -1,    -1,   556,    -1,   386,
      -1,    -1,    -1,   390,    -1,   386,    -1,    -1,    -1,   390,
      -1,    -1,    -1,   371,    32,   537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,   294,
      -1,    -1,   390,   576,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,    -1,    -1,   588,    -1,   428,    -1,    -1,
      -1,    -1,    -1,    -1,   576,    -1,    -1,   600,   601,    -1,
      -1,    79,    80,   622,    -1,   608,   588,    -1,   611,   456,
     428,    89,    -1,    -1,    -1,   456,   619,   190,   600,   601,
      -1,    -1,    -1,    -1,    -1,    -1,   608,   474,    -1,   611,
      -1,    -1,    -1,   474,    -1,    -1,    -1,   619,   456,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
     395,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   395,   410,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,
      -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,   556,
      -1,   395,    -1,    -1,    -1,   556,   427,   442,   443,   430,
      -1,    -1,    -1,    98,    -1,    -1,   410,    -1,    -1,    -1,
      -1,    -1,   443,    -1,    -1,    -1,    -1,    -1,   556,    -1,
      -1,    -1,    -1,   427,    -1,    -1,   430,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,   443,
      -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     495,    -1,   483,    -1,    -1,   622,   386,    -1,    -1,    -1,
     390,   622,   260,    -1,   495,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   483,
      -1,    -1,    -1,    -1,   622,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   537,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,   299,   395,    -1,    -1,    -1,   537,    -1,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,    -1,
     318,    -1,    -1,    -1,    -1,    -1,   456,    -1,    -1,    -1,
      -1,   576,    -1,   537,   427,    -1,   334,   430,    -1,    -1,
      -1,    -1,    -1,   588,   474,   576,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,   600,   601,   588,    -1,   357,
      -1,    -1,    -1,   608,   259,    -1,   611,    -1,    -1,   600,
     601,   369,   576,    -1,   619,   260,    -1,   608,    -1,    -1,
     611,   379,    -1,    -1,   588,    -1,    -1,    -1,   619,   284,
     483,    -1,    -1,    -1,    -1,    -1,   600,   601,   293,   397,
      -1,    -1,   495,    -1,   608,    -1,    -1,   611,    -1,   407,
      -1,    -1,    -1,    -1,   299,   619,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   423,   556,    -1,    -1,    -1,
      -1,    -1,    -1,   318,   329,    -1,    -1,   332,    -1,    -1,
      -1,    -1,   337,    -1,   537,    -1,    -1,    -1,    -1,    -1,
     345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,
      -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   576,   369,    -1,    -1,    -1,   486,    -1,
      -1,    -1,   622,    -1,   379,   588,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   501,    -1,    -1,    -1,   600,   601,    -1,
     508,    -1,   397,   511,   409,   608,    -1,    -1,   611,    -1,
      -1,   416,   407,    -1,    -1,    -1,   619,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   532,    -1,   431,   535,   423,   537,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,   463,    -1,
      -1,    -1,    -1,    -1,   479,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   489,   490,    -1,    -1,    -1,    -1,
     495,   486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     505,    -1,    -1,    -1,    -1,    -1,   501,    -1,   616,    -1,
      -1,    -1,    -1,   508,    -1,    -1,   511,    -1,    -1,    -1,
      -1,    -1,   527,    -1,    -1,   530,   531,    -1,    -1,    -1,
      -1,   536,    -1,    -1,    -1,    -1,    -1,   532,    -1,    -1,
     535,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   556,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   593,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,    -1,   604
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    46,    47,    75,   122,   123,   125,   126,   130,
     147,   148,   165,   236,   356,   405,   437,   466,   725,   753,
     754,   804,   971,  1024,  1026,  1027,  1028,  1033,  1035,  1048,
    1049,  1050,  1051,  1052,  1467,    28,    29,   726,   727,   728,
     729,   730,    27,   937,  1486,   355,   533,   547,   572,   620,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,   937,    25,
     937,  1388,  1053,   755,  1388,   754,  1467,     0,  1025,  1028,
    1033,  1051,  1467,    31,   728,   730,   937,  1470,   589,   937,
    1469,   625,   805,    25,   190,   752,   753,   925,   937,   942,
    1054,  1089,  1090,  1091,  1092,  1093,  1097,   353,   757,   758,
     759,   760,   763,   764,    55,    60,   105,   106,   113,   367,
     393,   464,   557,   637,   645,   725,   731,   897,   970,  1029,
    1030,  1032,  1036,  1037,  1043,  1055,  1076,  1208,  1218,  1467,
     937,  1469,   616,  1092,   242,   457,   458,  1099,    20,   937,
    1096,   619,   758,     5,   756,   353,   937,     5,   780,   782,
     783,   937,  1219,   937,   937,  1209,  1044,   937,   937,  1032,
    1038,   260,   299,   318,   357,   369,   379,   397,   407,   423,
     463,   486,   501,   508,   511,   532,   535,   537,   556,   574,
     806,   807,   808,   811,    25,  1089,  1095,    18,    19,    26,
     430,   675,   677,  1089,  1100,  1101,   458,    14,   803,   760,
     521,  1195,   761,   758,   763,    32,    79,    80,    89,   260,
     299,   318,   334,   357,   369,   379,   397,   407,   423,   463,
     486,   501,   508,   511,   532,   535,   537,   556,   574,   616,
     766,   774,   785,   786,   937,   430,   112,   937,   752,   898,
    1077,   937,   813,   535,   765,   789,   791,   792,   790,   799,
     800,   430,   430,   812,   458,   430,   430,   758,   787,   425,
     675,    18,    19,    20,    21,    22,   676,    26,     5,   426,
    1100,    24,    25,    26,   619,   937,   943,    19,    25,    26,
     762,   943,   776,   765,   777,   789,   790,   430,   430,   775,
     458,   430,   430,   787,   758,   784,   430,    26,   937,   430,
    1045,   752,   752,   430,   937,   430,   457,   769,   625,   366,
     453,   469,   512,   552,   581,   590,   793,   625,   366,   453,
     469,   512,   552,   581,   590,   801,    26,    26,   814,   815,
     816,   817,   937,    26,   772,   773,    26,    26,   619,   391,
     675,  1101,   458,   426,    26,    26,   758,   769,   758,    26,
      26,   757,   772,    26,    26,   619,    58,   781,  1220,   391,
     430,  1210,  1487,  1488,  1489,  1490,  1491,   899,  1078,  1039,
     619,    26,   794,   795,   430,   796,   801,   802,   796,   430,
     797,     5,   391,     5,   391,     5,   283,     5,   806,   426,
       5,     5,   391,   391,   758,   788,  1100,   458,   619,    26,
     258,     5,   391,     5,   391,   283,   426,     5,   391,   391,
     788,   937,  1106,  1107,  1109,  1056,  1106,   361,  1488,  1195,
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
     657,   660,   662,   664,   668,   669,   670,   671,   688,   710,
     724,   725,   731,   732,   751,   819,   820,   821,   822,   833,
     834,   835,   836,   888,   892,   923,   944,   945,   948,   949,
     950,   951,   964,   972,   993,   994,   996,  1000,  1015,  1016,
    1020,  1021,  1022,  1023,  1031,  1046,  1059,  1070,  1071,  1072,
    1083,  1086,  1122,  1125,  1127,  1133,  1134,  1137,  1140,  1143,
    1145,  1147,  1149,  1156,  1161,  1165,  1166,  1167,  1179,  1180,
    1183,  1189,  1190,  1191,  1216,  1231,  1232,  1233,  1234,  1235,
    1240,  1246,  1247,  1265,  1268,  1298,  1300,  1389,  1390,  1421,
    1422,  1429,  1440,  1467,  1471,  1476,  1478,  1480,  1484,  1485,
    1492,   725,  1034,  1467,   624,   647,  1079,  1080,  1106,    20,
     391,   425,   770,   793,    26,   798,    26,    26,    26,   815,
     817,   809,   773,    26,   426,  1100,    20,   770,   430,    26,
      26,   767,    26,   619,   391,     5,  1106,   391,   937,   349,
     938,   939,  1486,   937,   937,  1163,   932,   938,   932,    25,
     190,   937,  1098,  1462,  1463,  1464,   937,  1482,   937,  1242,
    1243,   937,    26,   672,  1089,  1238,   932,  1163,   862,    26,
     943,  1203,  1204,  1203,     9,    18,    19,    25,    26,    59,
      64,    71,    99,   192,   289,   294,   322,   357,   369,   387,
     392,   395,   406,   412,   422,   427,   430,   433,   442,   443,
     483,   487,   495,   506,   512,   537,   581,   588,   590,   600,
     601,   608,   837,   844,   845,   846,   847,   848,   849,   850,
     851,   863,   868,   879,   880,   881,   882,   937,   943,  1089,
    1198,  1267,  1380,   839,   862,   938,  1430,  1430,   823,  1163,
     932,  1236,  1089,   934,   938,   844,  1430,  1089,  1163,  1089,
    1266,  1430,    25,   585,  1073,  1074,  1089,   932,   932,  1073,
     933,   938,   937,  1074,   932,  1430,   932,   934,  1089,  1120,
    1121,   930,   938,   934,   374,   561,   666,   929,   937,   995,
     937,   733,   935,   938,    25,  1299,  1462,   862,   862,   938,
    1146,   893,   128,   137,   146,   151,   195,   203,   259,   284,
     291,   293,   303,   329,   337,   374,   400,   438,   449,   548,
     549,   550,   561,   664,  1009,  1141,  1142,  1089,   843,   844,
    1155,   929,  1477,  1477,   931,   938,   862,    25,  1089,  1144,
    1217,  1089,  1194,    25,  1089,  1424,   844,  1185,  1186,  1187,
    1196,  1197,   844,  1472,   104,   154,   192,   289,   365,   406,
     473,   537,   689,   868,   937,  1089,  1226,   712,   844,   930,
    1469,  1060,   844,   930,   844,  1089,  1017,   930,   844,  1441,
     844,  1203,   937,   946,   947,   934,   946,  1477,   934,   946,
    1477,   952,   946,    25,    26,   384,   486,   943,   998,  1089,
    1108,  1110,    65,   274,   344,   389,   568,   648,   649,   650,
     659,   679,   954,   956,   958,   960,   962,  1084,  1085,  1088,
     335,   346,   398,   413,   502,  1301,   639,   640,   901,   902,
     903,   937,  1081,   646,  1080,   391,   302,   391,   391,   391,
     391,   623,     5,   391,   426,   302,   758,   778,   779,   391,
     391,   623,   391,   937,  1221,  1109,   391,  1211,    56,    57,
      84,    85,    86,   454,   541,   584,  1248,  1249,  1250,  1253,
    1256,  1259,  1260,  1261,  1262,   430,   619,  1464,  1099,   616,
    1138,   619,     8,   538,   587,     5,   391,   426,    25,   937,
    1373,   478,  1164,  1108,   108,   109,   110,   837,   837,   837,
     430,   525,  1215,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   837,   366,   453,   469,   512,   552,   581,   590,
    1383,  1384,   430,   430,   430,   837,   837,   430,   430,   749,
     837,   430,   852,   430,   430,   430,   430,   430,   430,   430,
     430,     6,     7,     8,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    35,    92,    93,
      94,    95,    96,    97,   108,   109,   110,   249,   252,   371,
     386,   390,   428,   456,   474,   556,   622,   748,   838,   853,
     855,   856,   857,   858,   859,   860,   861,    26,   943,   430,
     520,   420,   482,   840,   841,   844,  1089,  1115,  1373,   678,
     679,   826,   266,    87,    88,   625,   459,     5,   618,   625,
     617,   617,  1123,   595,   420,     5,   556,   973,   459,   658,
    1474,   430,   458,   619,   658,   384,   735,  1089,   546,   617,
    1128,  1129,  1130,   326,  1297,   842,   844,   842,     8,   931,
      26,   500,   554,   924,  1089,   924,   924,   924,    25,   177,
     304,   310,   311,   312,   330,   438,   441,   484,   519,   539,
     540,   550,   555,   594,   626,  1013,  1014,   924,   924,   596,
    1010,   679,  1010,  1010,   925,   925,  1010,  1010,   679,     5,
     333,   385,     5,   678,     5,    81,    82,   539,   626,  1001,
     661,  1475,   843,   612,   613,   614,   615,  1193,  1195,   383,
    1230,  1195,  1187,     5,   617,  1188,   844,   430,   430,   430,
     430,    25,   708,   937,   430,  1424,   344,   430,   520,   589,
     578,   713,   720,   711,    25,  1075,  1089,  1181,     8,  1184,
      14,   937,  1094,  1102,  1103,  1105,  1113,  1114,  1157,   162,
     344,   544,   577,    33,   190,   553,  1442,  1443,  1444,  1445,
     575,     5,   658,   658,   842,  1108,  1115,   997,   420,     5,
     150,   977,   430,  1089,   842,   430,    26,    26,    65,  1087,
      25,  1089,  1428,  1428,   938,  1281,  1146,   931,   118,   221,
     229,   235,   237,   248,   276,   292,   297,   309,   316,   470,
     477,   499,   504,  1269,  1270,  1278,  1288,  1289,  1295,  1296,
    1302,  1303,  1312,  1331,  1335,  1400,  1401,  1431,  1432,  1435,
    1436,  1446,   904,   905,    91,   900,   911,   912,   903,  1082,
    1487,  1040,   458,   806,   773,   458,     5,   391,   780,   752,
    1057,   752,   157,   296,   372,   430,   475,   491,  1318,  1330,
     430,   937,  1264,    26,   245,   258,   430,   475,   491,   937,
    1245,  1258,  1316,  1317,  1322,  1324,  1326,   430,   937,  1255,
     430,  1245,  1251,     5,    25,   940,  1092,  1464,  1462,   576,
     616,  1139,    20,   937,  1119,  1465,   937,  1483,  1243,   595,
     619,   589,   430,   430,   826,  1477,   837,   929,   929,  1477,
    1477,   470,  1404,   837,    25,    26,    19,    24,    25,    26,
     883,   884,   885,   886,   837,   430,   625,  1477,    20,   837,
     391,  1404,   837,    20,  1198,   871,   869,   875,   837,   873,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   837,   837,   837,   837,   837,   837,   837,   837,
     837,   837,   430,   837,   837,   430,   864,   937,  1089,     5,
     625,   430,  1462,    25,   942,  1162,  1162,  1424,  1073,   844,
     844,   844,   926,   927,   430,  1089,  1121,   787,   974,   975,
     625,  1424,  1477,  1475,   937,   675,    20,   666,   937,   995,
    1089,   734,   624,   844,   350,  1132,   556,  1131,     5,    68,
      70,    72,   617,   625,   818,  1108,   894,    18,    19,   430,
    1011,  1013,  1142,   925,   844,   344,   595,   929,    26,    26,
     678,   152,  1192,   218,  1197,  1203,  1473,   937,    25,   887,
     929,  1477,   589,   929,   622,  1089,   693,   937,   937,   844,
     339,   716,   720,   578,   714,   722,    23,   234,  1062,  1066,
     481,   862,   481,  1182,   844,   457,  1099,   619,     5,  1018,
     546,  1158,  1089,  1463,  1466,  1089,  1111,  1112,   189,  1443,
     965,   947,  1477,  1477,   957,   958,   977,   977,    34,    36,
      37,    38,   270,   273,   275,   295,   305,   347,   351,   429,
     976,   978,   979,  1005,  1089,  1110,   546,   680,    26,   399,
     963,   321,  1423,  1423,   135,   136,   436,   546,   937,  1332,
    1333,  1374,   787,  1373,  1373,  1271,   787,   937,  1433,  1433,
     359,   475,   585,  1412,  1373,  1279,   167,   438,   449,   470,
     477,  1305,  1306,  1307,   287,   288,  1395,  1487,  1487,   384,
     913,  1089,   641,   642,   906,   907,   908,   480,   624,   643,
     644,   663,   916,   917,  1487,   752,    26,   771,   771,   779,
    1222,   752,  1212,  1320,  1373,  1263,  1330,   430,  1263,   430,
     430,  1257,  1258,   430,   430,    63,   299,   357,   369,   379,
     397,   407,   410,   423,   471,   501,   511,   532,   535,   537,
     565,   574,  1365,  1366,  1367,  1369,  1254,  1255,  1251,  1252,
     663,  1249,   391,   619,  1424,   576,   458,   546,  1481,   673,
     674,   937,   937,   937,  1239,   862,   391,   391,   391,   391,
     391,  1412,   391,   391,   391,   391,   589,   884,    19,    26,
     589,   391,   391,    26,  1384,   391,   391,   391,   391,     5,
     750,   391,   837,   837,   837,   391,   837,   391,   391,   391,
     441,   441,   441,   862,  1404,   441,   862,  1404,   705,   706,
     707,   837,   430,   840,   937,  1237,   616,  1135,   625,     5,
       5,     5,   579,   844,   619,     5,   482,   625,   391,   426,
     430,   624,   163,   166,   270,   273,   736,   739,   740,  1005,
     737,   738,   937,   430,   938,   648,   649,  1136,   844,   937,
     937,   927,   928,   508,  1477,   826,     8,   896,    26,    26,
    1012,  1013,  1089,   535,  1150,    65,   837,  1195,    26,  1089,
    1487,     5,     5,     5,   391,   391,   709,   937,   391,  1424,
     705,   430,   430,   721,   717,   360,   715,   844,   339,   718,
     722,   596,  1007,  1067,  1063,   362,  1061,  1062,   842,   625,
    1095,    20,   937,  1104,  1114,    14,    18,    19,    20,    25,
      26,    64,   395,   410,   427,   430,   443,   482,   483,   495,
     537,   576,   588,   600,   601,   608,   611,   937,   943,  1159,
    1160,  1379,  1381,  1411,  1416,  1417,  1418,  1466,   420,   420,
       5,  1487,   959,   960,   550,   936,   546,   988,   987,   990,
     989,   929,   991,   929,   992,   986,   985,   983,   982,  1006,
     324,   979,   984,  1477,    39,    40,    41,    42,    43,    44,
      98,   332,   345,   409,   416,   455,   479,   489,   490,   495,
     505,   527,   530,   531,   536,   593,   604,   681,   682,  1003,
    1004,     5,    26,  1424,   248,  1089,   470,  1405,  1406,  1424,
    1146,  1399,  1401,   100,   100,   595,  1144,  1334,  1335,   430,
    1313,   149,   525,  1339,  1346,  1373,   174,   271,  1437,   619,
     625,  1402,  1447,   341,   350,   374,   377,   395,   500,   554,
     561,   931,  1282,  1287,   430,  1308,   624,     5,    25,   937,
    1396,  1397,   915,  1089,     5,   546,   909,   910,   638,   908,
     914,   937,   914,   918,   919,   914,   324,   917,  1041,   426,
     426,   460,  1205,  1225,  1058,   460,  1168,  1199,   430,     5,
     391,     9,   294,   430,   442,  1349,  1350,  1351,  1352,  1353,
    1357,  1361,  1363,  1416,   391,   611,   937,  1319,  1321,  1373,
    1376,  1377,  1323,  1376,     5,   391,  1323,  1349,   366,   453,
     469,   512,   552,   581,   590,  1386,  1386,   430,   430,   430,
     430,   430,   430,   207,   399,  1325,  1327,     5,   391,     5,
     391,   937,  1465,     8,  1424,  1100,   844,     5,  1244,  1245,
     862,  1047,  1413,  1414,  1416,   877,  1384,   877,    26,    26,
     589,    24,    26,   790,   878,  1215,   391,  1215,   791,   391,
    1215,   872,   870,   876,  1215,   874,  1215,  1215,  1215,    25,
      25,    25,   837,   854,   391,    25,   854,   391,   865,     5,
     866,   619,  1244,   576,  1424,  1424,   844,   844,   926,   508,
     844,  1479,     5,    20,  1376,   975,  1424,   619,   937,   737,
     745,   744,   746,   937,   941,   747,   941,   191,   740,   743,
       5,   977,   619,   844,     8,   937,   862,   553,  1285,     5,
     391,  1089,     5,   325,    25,  1227,   929,   344,   344,   458,
     619,   344,   430,   694,   698,   691,  1487,  1487,   723,   719,
     715,  1008,    25,   936,  1068,  1089,  1487,   844,   425,   458,
     862,  1417,  1417,  1382,  1386,   470,  1416,   430,   430,   430,
     430,   430,   430,   430,   937,   430,     5,    18,    19,    20,
      21,    92,    93,    94,    95,    96,    97,  1438,  1463,  1089,
    1112,    62,   542,   966,   961,   962,    26,   678,   937,  1487,
    1487,  1487,  1487,     5,   980,     5,   981,  1487,  1487,  1487,
    1487,  1011,  1487,   936,    25,    14,    14,     5,   391,    26,
    1373,  1412,  1393,   595,   595,  1270,  1398,  1399,  1335,  1314,
    1376,   616,   931,  1349,   430,  1274,   937,  1434,  1433,  1413,
      48,    49,    50,    51,    52,   583,  1450,   844,   844,  1280,
     931,  1309,  1376,  1373,  1307,   619,   619,     5,     5,  1089,
     914,  1487,  1487,     5,   921,   922,  1487,  1487,   920,  1034,
     810,   768,    73,    74,    76,    77,    78,   176,   184,   218,
     227,   256,   257,   301,   343,   399,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,  1202,  1206,   134,   513,
    1207,  1223,  1034,   159,   175,   176,   184,   218,   227,   256,
     301,   343,  1200,  1201,  1213,  1207,  1321,  1330,  1352,   430,
    1411,  1349,  1416,  1411,     6,   391,     7,     9,    10,    12,
      13,    14,    15,    16,    17,   252,   371,   428,   556,   622,
    1360,  1362,  1377,   458,  1375,   391,     5,   619,     5,   391,
    1258,   391,   391,   625,   430,   625,    26,  1371,  1371,    26,
    1371,  1371,    26,  1370,    25,  1379,  1328,  1329,  1330,  1255,
    1251,  1424,     8,   426,   674,     5,   391,   842,   391,     5,
     546,  1340,  1345,   937,   625,   391,    26,   589,   625,   391,
     391,   391,   391,     5,   391,   391,   391,   707,   705,    20,
     391,  1424,     5,   844,   566,   274,   683,   684,   844,    20,
     937,   391,   977,  1487,  1487,     5,   741,   458,   619,     5,
     742,  1487,   738,   546,    20,   937,     5,   937,  1126,   389,
     658,   842,  1286,   895,  1013,   936,   837,     5,   705,  1089,
     690,   672,   937,  1089,   696,   391,   705,   705,  1487,  1487,
    1011,  1065,    25,  1069,  1089,   571,   891,  1100,   482,   843,
    1019,   625,  1412,   391,   395,  1439,  1466,   359,   475,   585,
    1364,  1416,  1419,  1364,  1364,  1364,  1364,   619,  1419,  1160,
    1416,  1416,  1416,  1416,   968,   967,   440,   953,   954,   619,
     929,  1487,   929,  1487,   678,    26,  1089,    26,  1089,   682,
     391,   430,  1425,  1413,  1395,  1399,  1399,  1391,     5,   391,
     470,  1410,  1275,  1376,   478,  1272,  1410,   625,  1403,    18,
      19,    64,   427,   430,   443,   482,   483,   495,   537,   576,
     588,   600,   601,   608,   611,   937,  1379,  1411,  1455,  1456,
    1457,  1458,  1459,  1460,  1466,  1455,  1455,  1455,  1376,  1452,
    1454,  1451,  1452,  1453,  1448,   553,  1283,     5,   391,   625,
     937,   937,  1397,  1089,   937,  1487,  1487,  1487,  1487,   623,
     623,  1203,  1203,  1203,    25,  1203,  1203,  1203,  1203,  1203,
    1203,    25,    25,  1203,  1206,  1089,  1116,  1117,   618,   446,
    1169,  1487,    25,    25,    26,    26,    26,    26,    26,    25,
    1089,  1201,  1169,   391,   391,  1350,  1351,  1355,  1417,   430,
    1411,  1355,   430,  1411,    10,   249,   386,   388,  1416,    26,
    1318,  1376,    20,   937,  1376,   366,   453,   469,   512,   552,
     581,   590,  1387,    26,  1387,     5,  1368,  1368,     5,   391,
     391,  1368,   391,  1330,  1424,  1245,   268,  1241,  1414,   514,
    1341,  1342,  1343,  1373,  1346,   331,   513,   524,  1290,  1407,
     366,   453,   469,   512,   552,   581,   590,  1385,   877,   589,
      24,    26,   794,   837,   867,   467,   825,     5,   373,  1424,
       5,   430,   391,   550,  1002,   941,  1487,   675,    20,   937,
     941,  1487,  1477,   844,  1477,  1111,  1487,   678,    25,  1228,
    1108,   426,   705,   695,   699,   391,  1487,   936,   844,   889,
     426,  1387,  1413,     5,  1386,   391,     5,  1416,     5,   391,
    1416,  1416,  1416,  1416,   937,   391,   844,  1487,   955,   956,
      20,   937,  1426,  1427,   553,  1409,  1394,  1392,  1395,  1376,
    1412,   139,  1315,     5,   391,  1273,  1434,  1409,  1458,  1458,
    1457,   430,   430,   430,   430,   430,   430,   430,   937,   430,
       5,   391,    18,    19,    20,    21,  1438,   391,     5,   391,
       5,    14,   149,   525,  1449,  1284,  1376,   462,  1310,  1311,
    1374,   619,   210,  1042,   806,   780,   538,   587,  1118,     5,
    1116,    61,   133,   199,   201,   216,   224,   228,   253,  1170,
    1171,  1224,  1042,  1214,   441,  1354,  1358,  1359,  1379,  1466,
    1354,  1358,  1355,  1416,     5,   426,  1375,   391,    26,  1372,
     391,   391,    26,   391,   430,  1343,     5,   937,  1378,   368,
    1337,  1347,   937,  1408,   618,  1364,   331,   430,    24,    26,
     391,   929,   678,   373,  1424,   844,   685,   568,  1124,    26,
     678,   426,  1002,   391,   240,  1148,   391,   391,   430,   697,
     344,   703,   391,   692,  1064,  1487,   458,  1345,  1386,   625,
    1386,   391,  1416,   391,   391,   391,   391,   575,   936,     5,
     391,  1111,  1345,  1395,  1395,  1413,  1376,   430,  1345,   391,
    1439,  1364,  1457,  1461,  1364,  1364,  1364,  1364,   619,  1461,
    1456,  1457,  1457,  1457,  1457,  1452,    14,  1453,  1456,   931,
    1349,  1111,     5,   140,  1304,   937,  1117,  1172,  1173,  1089,
    1175,  1089,  1174,  1176,  1171,   239,   239,  1356,  1379,  1420,
       5,   391,   391,  1354,     7,    26,   625,   391,  1342,  1344,
    1342,  1338,  1415,  1416,   447,  1336,  1348,  1241,    26,  1291,
    1292,  1293,  1376,  1405,  1408,    26,   824,  1424,   392,   203,
     259,   284,   293,   329,   337,   431,   602,   682,   686,   687,
     430,   619,   678,  1005,  1151,  1152,  1153,  1229,   700,   391,
    1108,   703,   703,  1487,   890,  1100,   391,   625,  1387,   625,
     969,   999,  1427,  1407,  1345,   482,  1276,  1277,  1416,  1407,
     391,  1457,     5,   391,  1457,  1457,  1457,  1457,   937,   391,
     430,  1311,  1487,  1487,  1177,  1487,  1178,  1487,  1487,  1359,
    1416,   426,  1387,     5,   391,     5,  1349,     5,   538,   587,
    1294,  1241,   391,   347,   351,   827,   828,   829,  1005,   924,
     924,   924,   924,   924,   924,    25,     5,   391,   844,    20,
     937,  1154,   282,  1153,   703,   705,   703,   241,   426,  1387,
    1387,  1487,   678,     5,   391,   391,  1457,   391,   391,   391,
     391,  1455,  1487,  1487,  1342,  1415,  1292,   831,   830,   238,
     829,   832,   687,     5,  1487,   701,   966,  1277,   391,  1487,
    1487,  1487,   844,   391,   391,   702,   162,   344,   704,  1108
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

  case 396:
#line 2393 "fgl.yacc"
    {inc_counter();}
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
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 541:
#line 3165 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 542:
#line 3166 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 543:
#line 3178 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 544:
#line 3184 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 545:
#line 3192 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 552:
#line 3209 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 553:
#line 3211 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3214 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 555:
#line 3216 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 560:
#line 3230 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 561:
#line 3232 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 562:
#line 3235 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 563:
#line 3237 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 576:
#line 3268 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 577:
#line 3270 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3273 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 579:
#line 3275 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3278 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 581:
#line 3280 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3283 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 583:
#line 3285 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 584:
#line 3288 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 585:
#line 3290 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 586:
#line 3305 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 587:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 588:
#line 3322 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 589:
#line 3323 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 590:
#line 3324 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 591:
#line 3325 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3326 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 596:
#line 3334 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 598:
#line 3340 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 599:
#line 3342 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 600:
#line 3343 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 601:
#line 3345 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 602:
#line 3347 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 603:
#line 3349 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 604:
#line 3351 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 605:
#line 3353 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 606:
#line 3356 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 607:
#line 3363 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 608:
#line 3365 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 609:
#line 3371 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 610:
#line 3376 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 611:
#line 3381 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 612:
#line 3386 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 613:
#line 3386 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 614:
#line 3389 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 615:
#line 3395 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 616:
#line 3400 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 617:
#line 3404 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 620:
#line 3412 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 621:
#line 3414 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 622:
#line 3416 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 623:
#line 3418 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 624:
#line 3420 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 625:
#line 3422 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 626:
#line 3425 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 628:
#line 3434 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 629:
#line 3496 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 630:
#line 3509 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 632:
#line 3516 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 633:
#line 3519 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 634:
#line 3525 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 635:
#line 3531 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 636:
#line 3535 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 637:
#line 3539 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 638:
#line 3545 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 639:
#line 3549 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 640:
#line 3553 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 641:
#line 3558 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 642:
#line 3563 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 661:
#line 3604 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 662:
#line 3609 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 664:
#line 3614 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 666:
#line 3617 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 667:
#line 3619 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 668:
#line 3622 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 669:
#line 3626 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 670:
#line 3629 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 671:
#line 3635 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 672:
#line 3646 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 673:
#line 3647 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 674:
#line 3650 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 676:
#line 3656 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 677:
#line 3660 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 678:
#line 3661 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 681:
#line 3675 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 682:
#line 3677 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 685:
#line 3686 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 686:
#line 3688 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 687:
#line 3692 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 688:
#line 3694 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 689:
#line 3697 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 690:
#line 3699 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 691:
#line 3702 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 692:
#line 3705 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 693:
#line 3708 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 694:
#line 3710 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 695:
#line 3713 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 696:
#line 3715 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 697:
#line 3718 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 698:
#line 3720 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 699:
#line 3723 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 700:
#line 3725 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 701:
#line 3726 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 702:
#line 3728 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 703:
#line 3729 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 704:
#line 3731 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 705:
#line 3732 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 706:
#line 3734 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 707:
#line 3774 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 708:
#line 3775 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 709:
#line 3783 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 710:
#line 3784 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 711:
#line 3793 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 712:
#line 3798 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 713:
#line 3803 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 714:
#line 3804 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 716:
#line 3809 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 717:
#line 3812 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 718:
#line 3820 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 719:
#line 3825 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 720:
#line 3829 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 721:
#line 3836 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 722:
#line 3845 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 723:
#line 3851 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 724:
#line 3852 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 725:
#line 3853 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 726:
#line 3854 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 727:
#line 3857 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 729:
#line 3860 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 730:
#line 3867 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 731:
#line 3868 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 732:
#line 3869 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 733:
#line 3870 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 734:
#line 3871 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 735:
#line 3872 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 736:
#line 3873 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 737:
#line 3874 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 738:
#line 3875 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 739:
#line 3880 "fgl.yacc"
    {iskey=1;}
    break;

  case 740:
#line 3880 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 741:
#line 3882 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 742:
#line 3885 "fgl.yacc"
    {iskey=1;}
    break;

  case 743:
#line 3885 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 744:
#line 3887 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 745:
#line 3891 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 746:
#line 3894 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 747:
#line 3895 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 749:
#line 3898 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 755:
#line 3910 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 756:
#line 3911 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 757:
#line 3912 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 758:
#line 3913 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 759:
#line 3914 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 760:
#line 3915 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 761:
#line 3916 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 762:
#line 3917 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 763:
#line 3918 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 764:
#line 3919 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 765:
#line 3920 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 766:
#line 3921 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 767:
#line 3922 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 768:
#line 3926 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 769:
#line 3944 "fgl.yacc"
    {chk4var=1;}
    break;

  case 770:
#line 3944 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 771:
#line 3947 "fgl.yacc"
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
#line 3971 "fgl.yacc"
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
#line 3989 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 775:
#line 3995 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 776:
#line 4001 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 777:
#line 4007 "fgl.yacc"
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
#line 4018 "fgl.yacc"
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
#line 4041 "fgl.yacc"
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
#line 4057 "fgl.yacc"
    {
	}
    break;

  case 789:
#line 4080 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 793:
#line 4088 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 811:
#line 4114 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 812:
#line 4115 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 813:
#line 4123 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 814:
#line 4128 "fgl.yacc"
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
#line 4144 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 816:
#line 4150 "fgl.yacc"
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
#line 4165 "fgl.yacc"
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
#line 4178 "fgl.yacc"
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
#line 4188 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 821:
#line 4195 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 822:
#line 4202 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 823:
#line 4208 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 824:
#line 4208 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 825:
#line 4213 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 826:
#line 4219 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 827:
#line 4227 "fgl.yacc"
    {
}
    break;

  case 833:
#line 4239 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 835:
#line 4247 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 836:
#line 4253 "fgl.yacc"
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
#line 4267 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 838:
#line 4271 "fgl.yacc"
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
#line 4284 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 841:
#line 4302 "fgl.yacc"
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
#line 4310 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 843:
#line 4316 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 844:
#line 4327 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 845:
#line 4331 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 846:
#line 4338 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 847:
#line 4345 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 848:
#line 4351 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 849:
#line 4356 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 852:
#line 4363 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 853:
#line 4364 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 854:
#line 4366 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 855:
#line 4367 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 856:
#line 4370 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 857:
#line 4371 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 858:
#line 4372 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 859:
#line 4374 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 860:
#line 4379 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 861:
#line 4384 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 862:
#line 4391 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 866:
#line 4398 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 867:
#line 4400 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 868:
#line 4402 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 869:
#line 4411 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 870:
#line 4417 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 871:
#line 4421 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 874:
#line 4433 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 875:
#line 4438 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 876:
#line 4443 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 877:
#line 4446 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 879:
#line 4458 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 880:
#line 4461 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 881:
#line 4464 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 888:
#line 4480 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 889:
#line 4485 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 890:
#line 4485 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 891:
#line 4488 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 892:
#line 4515 "fgl.yacc"
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
#line 4573 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 896:
#line 4580 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 897:
#line 4584 "fgl.yacc"
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
#line 4627 "fgl.yacc"
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
#line 4675 "fgl.yacc"
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
#line 4689 "fgl.yacc"
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
#line 4713 "fgl.yacc"
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
#line 4773 "fgl.yacc"
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
#line 4829 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 911:
#line 4834 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 912:
#line 4842 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 913:
#line 4847 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 914:
#line 4855 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 915:
#line 4861 "fgl.yacc"
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
#line 4894 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 917:
#line 4897 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 918:
#line 4899 "fgl.yacc"
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
#line 4940 "fgl.yacc"
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
#line 4993 "fgl.yacc"
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
#line 5045 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 927:
#line 5052 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 928:
#line 5058 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 929:
#line 5069 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 930:
#line 5076 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 932:
#line 5084 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 933:
#line 5087 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 934:
#line 5088 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 936:
#line 5090 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 937:
#line 5091 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 938:
#line 5094 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 939:
#line 5097 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 940:
#line 5103 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 941:
#line 5106 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 942:
#line 5110 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 943:
#line 5114 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 944:
#line 5121 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 945:
#line 5126 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 946:
#line 5133 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 947:
#line 5136 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 952:
#line 5149 "fgl.yacc"
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
#line 5168 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 954:
#line 5175 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5182 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 956:
#line 5185 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 957:
#line 5199 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 962:
#line 5216 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 963:
#line 5221 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 964:
#line 5227 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 966:
#line 5234 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 967:
#line 5239 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 968:
#line 5242 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 969:
#line 5243 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 970:
#line 5246 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 971:
#line 5247 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 972:
#line 5250 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 973:
#line 5251 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 974:
#line 5256 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 975:
#line 5263 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 976:
#line 5266 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 977:
#line 5272 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 978:
#line 5274 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 979:
#line 5276 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 980:
#line 5278 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 981:
#line 5281 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 982:
#line 5281 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 983:
#line 5282 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 984:
#line 5287 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 985:
#line 5295 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 986:
#line 5296 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5301 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 988:
#line 5303 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 989:
#line 5305 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 993:
#line 5322 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 994:
#line 5325 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 995:
#line 5328 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 996:
#line 5331 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 997:
#line 5335 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 998:
#line 5338 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 999:
#line 5341 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1000:
#line 5345 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1001:
#line 5349 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1002:
#line 5353 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1003:
#line 5356 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1004:
#line 5360 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1005:
#line 5363 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1006:
#line 5364 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1007:
#line 5365 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1008:
#line 5368 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1009:
#line 5371 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1010:
#line 5374 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1011:
#line 5377 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1012:
#line 5380 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1013:
#line 5383 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1014:
#line 5386 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1015:
#line 5403 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1018:
#line 5413 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1019:
#line 5420 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1021:
#line 5441 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1022:
#line 5446 "fgl.yacc"
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
#line 5459 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1024:
#line 5464 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1025:
#line 5465 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1026:
#line 5469 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1030:
#line 5475 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1031:
#line 5477 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1033:
#line 5492 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1034:
#line 5496 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1035:
#line 5502 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1036:
#line 5503 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1037:
#line 5506 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1038:
#line 5507 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1039:
#line 5510 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1041:
#line 5529 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1042:
#line 5534 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1043:
#line 5539 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1044:
#line 5544 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1050:
#line 5566 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1051:
#line 5573 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1052:
#line 5582 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1053:
#line 5588 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1054:
#line 5590 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1058:
#line 5601 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1059:
#line 5602 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1060:
#line 5604 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1061:
#line 5605 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1062:
#line 5607 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1063:
#line 5608 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1064:
#line 5610 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1065:
#line 5611 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1066:
#line 5613 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1067:
#line 5614 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1068:
#line 5615 "fgl.yacc"
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
#line 5629 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1070:
#line 5631 "fgl.yacc"
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
#line 5648 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1078:
#line 5660 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1079:
#line 5660 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1080:
#line 5666 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1081:
#line 5666 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1082:
#line 5669 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1083:
#line 5669 "fgl.yacc"
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
#line 5679 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1085:
#line 5680 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1086:
#line 5681 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1087:
#line 5688 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1088:
#line 5700 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1094:
#line 5711 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1095:
#line 5716 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1096:
#line 5720 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1097:
#line 5725 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1098:
#line 5731 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1099:
#line 5732 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1100:
#line 5733 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1101:
#line 5737 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1102:
#line 5738 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1103:
#line 5739 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1104:
#line 5740 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1105:
#line 5744 "fgl.yacc"
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
#line 5754 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1107:
#line 5756 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1108:
#line 5761 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1109:
#line 5764 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1110:
#line 5769 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1111:
#line 5776 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1112:
#line 5783 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1113:
#line 5790 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1114:
#line 5799 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1115:
#line 5806 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1116:
#line 5813 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1117:
#line 5820 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1118:
#line 5827 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1123:
#line 5840 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1124:
#line 5841 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1125:
#line 5842 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1126:
#line 5843 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1127:
#line 5844 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1128:
#line 5845 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1129:
#line 5846 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1130:
#line 5847 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1131:
#line 5848 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1132:
#line 5849 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1135:
#line 5855 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1136:
#line 5856 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1137:
#line 5857 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1138:
#line 5858 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1143:
#line 5867 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1144:
#line 5868 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1145:
#line 5869 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1146:
#line 5870 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1147:
#line 5871 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1148:
#line 5872 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1149:
#line 5873 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1150:
#line 5874 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1151:
#line 5876 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1152:
#line 5877 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1153:
#line 5878 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1154:
#line 5879 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1155:
#line 5881 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1156:
#line 5882 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1157:
#line 5883 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1158:
#line 5884 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1162:
#line 5889 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1163:
#line 5890 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1167:
#line 5897 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1168:
#line 5904 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1169:
#line 5911 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1170:
#line 5922 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1171:
#line 5931 "fgl.yacc"
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
#line 5942 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1173:
#line 5946 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1174:
#line 5950 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1175:
#line 5956 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1176:
#line 5961 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1177:
#line 5969 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1178:
#line 5972 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1179:
#line 5981 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1180:
#line 5992 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1182:
#line 5999 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1183:
#line 6007 "fgl.yacc"
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
#line 6017 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1185:
#line 6020 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1186:
#line 6024 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1187:
#line 6032 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1188:
#line 6035 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1189:
#line 6041 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1190:
#line 6045 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1191:
#line 6049 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1192:
#line 6053 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1193:
#line 6057 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1194:
#line 6063 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1195:
#line 6064 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1196:
#line 6065 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1197:
#line 6066 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1198:
#line 6071 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1199:
#line 6073 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1200:
#line 6076 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1201:
#line 6080 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1202:
#line 6083 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1203:
#line 6090 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1204:
#line 6095 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1205:
#line 6096 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1206:
#line 6097 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1207:
#line 6102 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1208:
#line 6103 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1209:
#line 6109 "fgl.yacc"
    {insql=1;}
    break;

  case 1210:
#line 6109 "fgl.yacc"
    {insql=0;}
    break;

  case 1211:
#line 6109 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1212:
#line 6114 "fgl.yacc"
    {insql=1;}
    break;

  case 1213:
#line 6114 "fgl.yacc"
    {insql=0;}
    break;

  case 1214:
#line 6114 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1215:
#line 6125 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1216:
#line 6126 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1217:
#line 6132 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1218:
#line 6134 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1220:
#line 6147 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1221:
#line 6151 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1222:
#line 6152 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1224:
#line 6157 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1225:
#line 6160 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1226:
#line 6166 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1227:
#line 6169 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1228:
#line 6177 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1230:
#line 6184 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1231:
#line 6191 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1232:
#line 6194 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1233:
#line 6203 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1234:
#line 6206 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1235:
#line 6209 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1236:
#line 6212 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1237:
#line 6215 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1238:
#line 6218 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1239:
#line 6221 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1240:
#line 6228 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1241:
#line 6231 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1242:
#line 6238 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6241 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1244:
#line 6247 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6250 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1246:
#line 6257 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1247:
#line 6260 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1249:
#line 6268 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1251:
#line 6277 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1252:
#line 6280 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1253:
#line 6286 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 6289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1255:
#line 6295 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 6302 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1257:
#line 6303 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1258:
#line 6307 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1259:
#line 6313 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1260:
#line 6316 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1262:
#line 6324 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1263:
#line 6331 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1264:
#line 6334 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1268:
#line 6352 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1274:
#line 6358 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1275:
#line 6361 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1276:
#line 6364 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1277:
#line 6370 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1279:
#line 6376 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1281:
#line 6387 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1282:
#line 6401 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1283:
#line 6410 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1284:
#line 6410 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1285:
#line 6415 "fgl.yacc"
    {insql=1;}
    break;

  case 1286:
#line 6415 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1287:
#line 6420 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1288:
#line 6423 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1289:
#line 6425 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1291:
#line 6432 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6436 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1293:
#line 6440 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1294:
#line 6447 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 6450 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1296:
#line 6457 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1297:
#line 6461 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1298:
#line 6465 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1299:
#line 6470 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1300:
#line 6475 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1301:
#line 6479 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1302:
#line 6485 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1303:
#line 6489 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1304:
#line 6495 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1305:
#line 6502 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1306:
#line 6506 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1307:
#line 6511 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1308:
#line 6521 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1309:
#line 6524 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1310:
#line 6526 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1311:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1312:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1313:
#line 6532 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1314:
#line 6534 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1315:
#line 6536 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1316:
#line 6542 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1317:
#line 6552 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1318:
#line 6559 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1320:
#line 6565 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1324:
#line 6574 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1327:
#line 6579 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1328:
#line 6584 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1329:
#line 6591 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1330:
#line 6592 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1331:
#line 6599 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1332:
#line 6610 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1333:
#line 6611 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1334:
#line 6614 "fgl.yacc"
    {insql=1;}
    break;

  case 1335:
#line 6614 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1336:
#line 6619 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1337:
#line 6624 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1339:
#line 6630 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1341:
#line 6634 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1342:
#line 6639 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1343:
#line 6644 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1344:
#line 6648 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1346:
#line 6654 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1347:
#line 6658 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1348:
#line 6666 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1349:
#line 6669 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1350:
#line 6671 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1351:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1354:
#line 6683 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1358:
#line 6690 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1359:
#line 6693 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1360:
#line 6695 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1362:
#line 6701 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6717 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1368:
#line 6722 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1369:
#line 6724 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1371:
#line 6730 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1372:
#line 6733 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1374:
#line 6739 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1375:
#line 6747 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1376:
#line 6752 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6762 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6768 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6774 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6776 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6782 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6787 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1387:
#line 6790 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1388:
#line 6793 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1389:
#line 6801 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6803 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1391:
#line 6816 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1392:
#line 6821 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1394:
#line 6825 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1395:
#line 6827 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1396:
#line 6834 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1397:
#line 6837 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1398:
#line 6843 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1399:
#line 6847 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1400:
#line 6851 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1401:
#line 6855 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1402:
#line 6858 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1403:
#line 6866 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1404:
#line 6873 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1407:
#line 6882 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1408:
#line 6888 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1409:
#line 6891 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1410:
#line 6902 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1411:
#line 6909 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1412:
#line 6915 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6918 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6925 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1415:
#line 6932 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1417:
#line 6939 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1418:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1419:
#line 6946 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1420:
#line 6947 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1422:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6956 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1425:
#line 6963 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1426:
#line 6968 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1427:
#line 6969 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1428:
#line 6972 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1429:
#line 6975 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1430:
#line 6980 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1431:
#line 6981 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1432:
#line 6986 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1433:
#line 6989 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1434:
#line 6995 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1435:
#line 6998 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7004 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1437:
#line 7007 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1438:
#line 7013 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1439:
#line 7016 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1440:
#line 7023 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1441:
#line 7024 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1442:
#line 7053 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1443:
#line 7055 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1444:
#line 7059 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1446:
#line 7072 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1447:
#line 7075 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1448:
#line 7078 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1449:
#line 7081 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1451:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1452:
#line 7092 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1454:
#line 7098 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1456:
#line 7104 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1457:
#line 7107 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1458:
#line 7110 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7113 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1460:
#line 7116 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7119 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1462:
#line 7122 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1464:
#line 7129 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1469:
#line 7136 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1470:
#line 7137 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1471:
#line 7142 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1472:
#line 7145 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1473:
#line 7149 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1474:
#line 7155 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1475:
#line 7156 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1476:
#line 7157 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1477:
#line 7158 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1482:
#line 7178 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1483:
#line 7183 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 7184 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1486:
#line 7187 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1490:
#line 7192 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 7195 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 7198 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1499:
#line 7205 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 7208 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1501:
#line 7209 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1502:
#line 7216 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1506:
#line 7221 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1510:
#line 7237 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1511:
#line 7238 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1512:
#line 7242 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1513:
#line 7243 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1515:
#line 7262 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1516:
#line 7263 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1517:
#line 7264 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1518:
#line 7268 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1519:
#line 7271 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1520:
#line 7277 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1521:
#line 7282 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1522:
#line 7287 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1524:
#line 7298 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1529:
#line 7313 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1530:
#line 7316 "fgl.yacc"
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

  case 1531:
#line 7329 "fgl.yacc"
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

  case 1532:
#line 7344 "fgl.yacc"
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

  case 1533:
#line 7356 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1534:
#line 7358 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1535:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1536:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1537:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1538:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1539:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1540:
#line 7361 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1541:
#line 7362 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1542:
#line 7365 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1543:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1544:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1545:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1546:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1547:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1548:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1549:
#line 7372 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1550:
#line 7375 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1565:
#line 7384 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1566:
#line 7385 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1567:
#line 7389 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1568:
#line 7397 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1569:
#line 7397 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1570:
#line 7403 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1571:
#line 7403 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1572:
#line 7410 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1573:
#line 7410 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1574:
#line 7416 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1575:
#line 7416 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1576:
#line 7424 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1577:
#line 7425 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1578:
#line 7426 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1582:
#line 7433 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7434 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1584:
#line 7439 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1585:
#line 7442 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1586:
#line 7448 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1587:
#line 7453 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1588:
#line 7462 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1589:
#line 7474 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1590:
#line 7475 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1591:
#line 7478 "fgl.yacc"
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
#line 7493 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1593:
#line 7503 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1594:
#line 7506 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1595:
#line 7514 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1596:
#line 7523 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1597:
#line 7526 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1598:
#line 7530 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1599:
#line 7533 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1600:
#line 7534 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1602:
#line 7543 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1603:
#line 7544 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1604:
#line 7553 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1605:
#line 7562 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1606:
#line 7567 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1607:
#line 7568 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1608:
#line 7569 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1609:
#line 7570 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1610:
#line 7577 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1611:
#line 7580 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1612:
#line 7586 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1613:
#line 7589 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1614:
#line 7599 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1615:
#line 7608 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1616:
#line 7611 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1617:
#line 7614 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1618:
#line 7620 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1619:
#line 7626 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7629 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1621:
#line 7632 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1622:
#line 7635 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1623:
#line 7642 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1624:
#line 7644 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1625:
#line 7646 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1626:
#line 7648 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1627:
#line 7650 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1628:
#line 7651 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1629:
#line 7652 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1630:
#line 7653 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1631:
#line 7654 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1632:
#line 7655 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1633:
#line 7656 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1634:
#line 7658 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1635:
#line 7660 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1636:
#line 7662 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1637:
#line 7664 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1638:
#line 7666 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1639:
#line 7668 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1640:
#line 7670 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1641:
#line 7671 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1642:
#line 7673 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1643:
#line 7677 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1644:
#line 7678 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1646:
#line 7688 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1647:
#line 7697 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1648:
#line 7701 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1649:
#line 7708 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1650:
#line 7708 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1652:
#line 7712 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1653:
#line 7717 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1654:
#line 7717 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1656:
#line 7721 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1657:
#line 7725 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1660:
#line 7734 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1661:
#line 7734 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1666:
#line 7753 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1667:
#line 7754 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1670:
#line 7762 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1671:
#line 7768 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1674:
#line 7787 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1675:
#line 7788 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1676:
#line 7789 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1677:
#line 7790 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1678:
#line 7791 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1679:
#line 7792 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1680:
#line 7796 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1681:
#line 7797 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1682:
#line 7798 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1683:
#line 7802 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1684:
#line 7806 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1686:
#line 7815 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1688:
#line 7820 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1689:
#line 7821 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1690:
#line 7825 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1691:
#line 7831 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
	}
    break;

  case 1692:
#line 7918 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1693:
#line 7922 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1694:
#line 7924 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1695:
#line 7931 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1696:
#line 7935 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1697:
#line 7941 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1698:
#line 7949 "fgl.yacc"
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
#line 7969 "fgl.yacc"
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
#line 7981 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1702:
#line 7984 "fgl.yacc"
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
#line 8003 "fgl.yacc"
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
#line 8029 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1705:
#line 8032 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1707:
#line 8041 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1708:
#line 8046 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1709:
#line 8049 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1710:
#line 8057 "fgl.yacc"
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
#line 8065 "fgl.yacc"
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
#line 8078 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1713:
#line 8081 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1714:
#line 8089 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1715:
#line 8092 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1716:
#line 8095 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1717:
#line 8103 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1718:
#line 8107 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1719:
#line 8110 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1720:
#line 8113 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1721:
#line 8116 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1722:
#line 8120 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1723:
#line 8121 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1724:
#line 8122 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1725:
#line 8123 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1726:
#line 8124 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1727:
#line 8130 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1728:
#line 8131 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1729:
#line 8132 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1730:
#line 8133 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1731:
#line 8134 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1732:
#line 8135 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1733:
#line 8136 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1734:
#line 8137 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1735:
#line 8138 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1736:
#line 8139 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1737:
#line 8140 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1738:
#line 8141 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1739:
#line 8142 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1740:
#line 8143 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1741:
#line 8147 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1742:
#line 8153 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1743:
#line 8154 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1744:
#line 8167 "fgl.yacc"
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

  case 1745:
#line 8187 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1749:
#line 8193 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1750:
#line 8194 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1754:
#line 8206 "fgl.yacc"
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

  case 1755:
#line 8232 "fgl.yacc"
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

  case 1756:
#line 8283 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 8285 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 8287 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1759:
#line 8288 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1760:
#line 8293 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1761:
#line 8298 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 8299 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 1763:
#line 8303 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 8305 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1765:
#line 8307 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1766:
#line 8310 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1767:
#line 8314 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1768:
#line 8319 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1769:
#line 8324 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1770:
#line 8328 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1772:
#line 8338 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1774:
#line 8353 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1775:
#line 8356 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1776:
#line 8360 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1779:
#line 8379 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1780:
#line 8380 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1781:
#line 8383 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1782:
#line 8384 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1783:
#line 8385 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1784:
#line 8386 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1785:
#line 8387 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1786:
#line 8388 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1787:
#line 8389 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1788:
#line 8394 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1789:
#line 8395 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1790:
#line 8399 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1791:
#line 8403 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1792:
#line 8407 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1793:
#line 8411 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1794:
#line 8416 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1795:
#line 8420 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1796:
#line 8425 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1798:
#line 8433 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1800:
#line 8439 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1801:
#line 8445 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1802:
#line 8449 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1807:
#line 8467 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1808:
#line 8474 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1809:
#line 8483 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1810:
#line 8483 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17115 "y.tab.c"

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


#line 8578 "fgl.yacc"

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



