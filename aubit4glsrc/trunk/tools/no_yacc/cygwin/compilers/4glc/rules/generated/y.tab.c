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
     NAME = 1666,
     UMINUS = 1667,
     COMMA = 1571,
     KW_OR = 1611,
     KW_AND = 1566,
     KW_USING = 1502,
     NOT = 1586,
     MATCHES = 1381,
     POWER = 1488,
     LESS_THAN = 1484,
     GREATER_THAN = 1399,
     EQUAL = 1561,
     GREATER_THAN_EQ = 1297,
     LESS_THAN_EQ = 1356,
     NOT_EQUAL = 1430,
     PLUS = 1597,
     MINUS = 1584,
     MULTIPLY = 1489,
     DIVIDE = 1517,
     MOD = 1585,
     COMMAND = 1363,
     NUMBER_VALUE = 1668,
     CHAR_VALUE = 1669,
     INT_VALUE = 1670,
     NAMED_GEN = 1671,
     CLINE = 1672,
     SQLLINE = 1673,
     KW_CSTART = 1674,
     KW_CEND = 1675,
     USER_DTYPE = 1676,
     SQL_TEXT = 1677,
     BEFORE_INSERT = 1000,
     CONCAT_PIPES = 1001,
     BEFORE_DELETE = 1002,
     AFTER_INSERT = 1003,
     AFTER_DELETE = 1004,
     EXECUTE_IMMEDIATE = 1005,
     DELETE_ROW_EQUAL_TRUE = 1006,
     INSERT_ROW_EQUAL_TRUE = 1007,
     DELETE_ROW_EQUAL_FALSE = 1008,
     INSERT_ROW_EQUAL_FALSE = 1009,
     CURRENT_ROW_DISPLAY_EQUAL = 1010,
     MAXCOUNT = 1011,
     ALTER_TABLE = 1012,
     WHENEVER_ERROR_CONTINUE = 1013,
     WHENEVER_WARNING_CONTINUE = 1014,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1015,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1016,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1017,
     XSET_MULTIPLY_EQUAL = 1018,
     XSET_OPEN_BRACKET = 1019,
     NEWFORMATSHARED = 1020,
     CREATE_DATABASE = 1021,
     IMPORT_LEGACY_FUNCTION = 1022,
     ADD_CONSTRAINT = 1023,
     DROP_CONSTRAINT = 1024,
     AS_STATIC = 1025,
     NOT_FIELD_TOUCHED = 1026,
     LOCAL_FUNCTION = 1027,
     EVERY_ROW = 1028,
     ELIF = 1029,
     DOUBLE_PRECISION = 1030,
     COUNT_MULTIPLY = 1031,
     WAIT_FOR_KEY = 1032,
     AT_TERMINATION_CALL = 1033,
     TERMINATE_REPORT = 1034,
     TO_MAIN_CAPTION = 1035,
     CLEARSTAT = 1036,
     TO_MENUITEM = 1037,
     ID_TO_INT = 1038,
     TO_STATUSBOX = 1039,
     ASCII_HEIGHT_ALL = 1040,
     ASCII_WIDTH_ALL = 1041,
     IMPORT_DATATYPE = 1042,
     PAGE_TRAILER_SIZE = 1043,
     PAGE_HEADER_SIZE = 1044,
     FIRST_PAGE_HEADER_SIZE = 1045,
     BYTES_USE_AS_IMAGE = 1046,
     BYTES_USE_AS_ASCII = 1047,
     KWUP_BY = 1048,
     KWDOWN_BY = 1049,
     CLOSE_STATUSBOX = 1050,
     MODIFY_NEXT_SIZE = 1051,
     LOCK_MODE_PAGE = 1052,
     LOCK_MODE_ROW = 1053,
     TO_PIPE = 1054,
     TO_PRINTER = 1055,
     STATUSBOX = 1056,
     CONNECT_TO = 1057,
     FORMHANDLER_INPUT = 1058,
     UNITS_YEAR = 1059,
     UNITS_MONTH = 1060,
     UNITS_DAY = 1061,
     UNITS_HOUR = 1062,
     UNITS_MINUTE = 1063,
     UNITS_SECOND = 1064,
     NO_NEW_LINES = 1065,
     FIELDTOWIDGET = 1066,
     WITH_HOLD = 1067,
     SHOW_MENU = 1068,
     CWIS = 1069,
     CREATE_IDX = 1070,
     FORM_IS_COMPILED = 1071,
     PDF_REPORT = 1072,
     IMPORT_FUNCTION = 1073,
     PROMPT_MANY = 1074,
     POINTS = 1075,
     MM = 1076,
     INCHES = 1077,
     PREPEND = 1078,
     MEMBER_OF = 1079,
     MEMBER_FUNCTION = 1080,
     APPEND = 1081,
     TEMPLATE = 1082,
     END_TEMPLATE = 1083,
     SQLSICS = 1084,
     CREATE_SCHEMA = 1085,
     SQLSIRR = 1086,
     UPDATESTATS_T = 1087,
     SQLSICR = 1088,
     WHENEVER_SQLSUCCESS = 1089,
     WHENEVER_SQLWARNING = 1090,
     START_EXTERN = 1091,
     WHENEVER_ANY_ERROR = 1092,
     WHENEVER_NOT_FOUND = 1093,
     CONTINUE_CONSTRUCT = 1094,
     FOUNCONSTR = 1095,
     SQLSIDR = 1096,
     WHENEVER_SQLERROR = 1097,
     CREATE_TEMP_TABLE = 1098,
     CURRENT_WINDOW_IS = 1099,
     FIRST_PAGE_HEADER = 1100,
     ORDER_EXTERNAL_BY = 1101,
     SCROLL_CURSOR_FOR = 1102,
     SCROLL_CURSOR = 1103,
     SQL_INTERRUPT_OFF = 1104,
     STOP_ALL_EXTERNAL = 1105,
     WITH_CHECK_OPTION = 1106,
     WITH_GRANT_OPTION = 1107,
     SQLSLMNW = 1108,
     ADDCONSTUNIQ = 1109,
     CONTINUE_DISPLAY = 1110,
     CONTINUE_FOREACH = 1111,
     OUTPUT_TO_REPORT = 1112,
     SQL_INTERRUPT_ON = 1113,
     WHENEVER_SUCCESS = 1114,
     WHENEVER_WARNING = 1115,
     WHERE_CURRENT_OF = 1116,
     WITHOUT_DEFAULTS = 1117,
     FOCONSTR = 1118,
     SCALED_BY = 1119,
     CONTINUE_PROMPT = 1120,
     PDF_FUNCTION = 1121,
     DEFER_INTERRUPT = 1122,
     DISPLAY_BY_NAME = 1123,
     NOT_NULL_UNIQUE = 1124,
     SKIP_TO_TOP = 1125,
     TOP_OF_PAGE = 1126,
     SKIP_TO = 1127,
     SKIP_BY = 1128,
     WITHOUT_WAITING = 1129,
     BEFCONSTRUCT = 1130,
     SQLSLMW = 1131,
     WHENEVER_ERROR = 1132,
     AFTCONSTRUCT = 1133,
     ALL_PRIVILEGES = 1134,
     CLOSE_DATABASE = 1135,
     CONTINUE_INPUT = 1136,
     CONTINUE_WHILE = 1137,
     CREATE_SYNONYM = 1138,
     DROP_TABLE = 1139,
     EXIT_CONSTRUCT = 1140,
     INEXCLUSIVE = 1141,
     REPORT_TO_PRINTER = 1142,
     REPORT_TO_PIPE = 1143,
     RETURN = 1144,
     SET_SESSION_TO = 1145,
     UPDATESTATS = 1146,
     WITHOUT_HEAD = 1147,
     CLEARSCR = 1148,
     WITH_B_LOG = 1149,
     AUTHORIZATION = 1150,
     BOTTOM_MARGIN = 1151,
     CLOSE_SESSION = 1152,
     CONTINUE_CASE = 1153,
     CONTINUE_MENU = 1154,
     DISPLAY_ARRAY = 1155,
     END_SQL = 1156,
     DOLLAR = 1157,
     END_CONSTRUCT = 1158,
     FIELD_TOUCHED = 1159,
     FINISH_REPORT = 1160,
     INFACC = 1161,
     INPUT_NO_WRAP = 1162,
     LOCKMODEPAGE = 1163,
     SETPMOFF = 1164,
     UNCONSTRAINED = 1165,
     PAGE_TRAILER = 1166,
     SETPMON = 1167,
     BEFGROUP = 1168,
     CLOSE_WINDOW = 1169,
     COMMENT_LINE = 1170,
     CONTINUE_FOR = 1171,
     CREATE_DB = 1172,
     CREATE_TABLE = 1173,
     DEFAULT_NULL = 1174,
     DELETE_USING = 1175,
     DISPLAY_FORM = 1176,
     END_FUNCTION = 1177,
     EXIT_DISPLAY = 1178,
     EXIT_FOREACH = 1179,
     EXIT_PROGRAM = 1180,
     INFCOLS = 1181,
     LOCKMODEROW = 1182,
     ON_EVERY_ROW = 1183,
     OPEN_SESSION = 1184,
     RIGHT_MARGIN = 1185,
     SELECT_USING = 1186,
     START_REPORT = 1187,
     UNLOCK_TABLE = 1188,
     UPDATE_USING = 1189,
     ACL_BUILTIN = 1190,
     AFTGROUP = 1191,
     INFIDX = 1192,
     INFSTAT = 1193,
     LEFT_MARGIN = 1194,
     PAGE_HEADER = 1195,
     ROLLBACK_W = 1196,
     SET_SESSION = 1197,
     SQLSEOFF = 1198,
     WITH_A_LOG = 1199,
     BEFDISP = 1200,
     BEFORE_MENU = 1201,
     CREATE_VIEW = 1202,
     DEFINE_TYPE = 1203,
     DELETE_FROM = 1204,
     END_DISPLAY = 1205,
     END_REPORT = 1206,
     END_FOREACH = 1207,
     END_FOR = 1208,
     END_GLOBALS = 1209,
     EXIT_PROMPT = 1210,
     EXTENT_SIZE = 1211,
     FOREIGN_KEY = 1212,
     HIDE_OPTION = 1213,
     HIDE_WINDOW = 1214,
     INSERT_INTO = 1215,
     IS_NOT_NULL = 1216,
     MOVE_WINDOW = 1217,
     NEXT_OPTION = 1218,
     NOT_MATCHES = 1219,
     ON_LAST_ROW = 1220,
     OPEN_WINDOW = 1221,
     OPEN_STATUSBOX = 1222,
     PAGE_LENGTH = 1223,
     PAGE_WIDTH = 1224,
     PRIMARY_KEY = 1225,
     PROMPT_LINE = 1226,
     RECORD_LIKE = 1227,
     ROLLFORWARD = 1228,
     SETBL = 1229,
     SHOW_OPTION = 1230,
     SHOW_WINDOW = 1231,
     SQLSEON = 1232,
     TO_DATABASE = 1233,
     USE_SESSION = 1234,
     WITH_NO_LOG = 1235,
     AFTDISP = 1236,
     BEFFIELD = 1237,
     INSHARE = 1238,
     UNLOCKTAB = 1239,
     AFTFIELD = 1240,
     ATTRIBUTES = 1241,
     BEFINP = 1242,
     BEGIN_WORK = 1243,
     CLEARWIN = 1244,
     CLOSE_FORM = 1245,
     DEFER_QUIT = 1246,
     DESCENDING = 1247,
     DROP_INDEX = 1248,
     END_PROMPT = 1249,
     END_RECORD = 1250,
     ERROR_LINE = 1251,
     EXIT_INPUT = 1252,
     EXIT_WHILE = 1253,
     FOR_UPDATE_OF = 1254,
     FOR_UPDATE = 1255,
     GET_FLDBUF = 1256,
     INITIALIZE = 1257,
     INPUT_WRAP = 1258,
     LOCK_TABLE = 1259,
     MSG_LINE = 1260,
     NOT_EXISTS = 1261,
     ON_ANY_KEY = 1262,
     REFERENCES = 1263,
     RENCOL = 1264,
     SET_CURSOR = 1265,
     SMALLFLOAT = 1266,
     SQLSUCCESS = 1267,
     TOP_MARGIN = 1268,
     WITH_ARRAY = 1269,
     ACCEPTKEY = 1270,
     ACCEPT = 1271,
     AFTINP = 1272,
     CLEARFORMTODEFAULTS = 1273,
     CLEARFORM = 1274,
     CLEAR_X_FORM = 1275,
     COMMIT_W = 1276,
     NEXTPAGE = 1277,
     PREVPAGE = 1278,
     CTRL_KEY = 1279,
     INFTABS = 1280,
     NEXTFIELD = 1281,
     NEXTFORM = 1282,
     RENTAB = 1283,
     ASCENDING = 1284,
     ASSOCIATE = 1285,
     CHARACTER = 1286,
     CONSTRUCT = 1287,
     DELIMITER = 1288,
     DOWNSHIFT = 1289,
     DROP_VIEW = 1290,
     END_INPUT = 1291,
     END_WHILE = 1292,
     EXCLUSIVE = 1293,
     EXIT_CASE = 1294,
     EXIT_MENU = 1295,
     FORM_LINE = 1296,
     INTERRUPT = 1298,
     INTO_TEMP = 1299,
     INVISIBLE = 1300,
     IN_MEMORY = 1301,
     LINKED_TO = 1302,
     LOAD_FROM = 1303,
     LOCKTAB = 1304,
     MENU_LINE = 1305,
     OPEN_FORM = 1306,
     OTHERWISE = 1307,
     PRECISION = 1308,
     PRIOR = 1309,
     PROCEDURE = 1310,
     REPORT_TO = 1311,
     RETURNING = 1312,
     UNDERLINE = 1313,
     UNLOAD_TO = 1314,
     BEFROW = 1315,
     UNLOAD_T = 1316,
     VARIABLE = 1317,
     ABSOLUTE = 1318,
     AFTROW = 1319,
     BUFFERED = 1320,
     CONSTANT = 1321,
     CONST = 1322,
     CONTINUE = 1323,
     DATABASE = 1324,
     DATETIME = 1325,
     DEFAULTS = 1326,
     DISTINCT = 1327,
     END_CASE = 1328,
     END_MAIN = 1329,
     END_MENU = 1330,
     END_TYPE = 1331,
     EXIT_FOR = 1332,
     EXTERNAL = 1333,
     FRACTION = 1334,
     FUNCTION = 1335,
     GROUP_BY = 1336,
     INTERVAL = 1337,
     KWMESSAGE = 1338,
     NOT_LIKE = 1339,
     NOT_ILIKE = 1340,
     NOT_NULL = 1341,
     PASSWORD = 1342,
     PREVIOUS = 1343,
     READONLY = 1344,
     REGISTER = 1345,
     RELATIVE = 1346,
     RESOURCE = 1347,
     SMALLINT = 1348,
     VALIDATE = 1349,
     WHENEVER = 1350,
     WITH_LOG = 1351,
     WORDWRAP = 1352,
     BY_NAME = 1353,
     IN_FILE = 1354,
     IS_NULL = 1355,
     AVERAGE = 1357,
     BETWEEN = 1358,
     CAPTION = 1359,
     CLIPPED = 1360,
     CLOSE_BRACKET = 1361,
     COLUMNS = 1362,
     COMMENT = 1364,
     CONNECT = 1365,
     CURRENT = 1366,
     DBYNAME = 1367,
     DECIMAL = 1368,
     DECLARE = 1369,
     DEFAULT = 1370,
     DISPLAY = 1371,
     ENDCODE = 1372,
     EXECUTE = 1373,
     FOREACH = 1374,
     FOREIGN = 1375,
     GLOBALS = 1376,
     INFIELD = 1377,
     INTEGER = 1378,
     KWWINDOW = 1379,
     MAGENTA = 1380,
     NUMERIC = 1382,
     OPTIONS = 1383,
     PERCENT = 1384,
     PREPARE = 1385,
     PROGRAM = 1386,
     RECOVER = 1387,
     REVERSE = 1388,
     SECTION = 1389,
     SESSION = 1390,
     SYNONYM = 1391,
     THRU = 1392,
     TRAILER = 1393,
     UPSHIFT = 1394,
     VARCHAR = 1395,
     WAITING = 1396,
     CLOSE_SHEV = 1397,
     CLOSE_SQUARE = 1398,
     KW_FALSE = 1400,
     NOT_IN = 1401,
     ONKEY = 1402,
     OPEN_BRACKET = 1403,
     BORDER = 1404,
     BOTTOM = 1405,
     COLUMN = 1406,
     COMMIT = 1407,
     CREATE = 1408,
     CURSOR = 1409,
     DEFINE = 1410,
     DELETE = 1411,
     DOUBLE = 1412,
     END_IF = 1413,
     ESCAPE = 1414,
     EXISTS = 1415,
     EXTEND = 1416,
     EXTENT = 1417,
     FINISH = 1418,
     FORMAT = 1419,
     HAVING = 1420,
     HEADER = 1421,
     INSERT = 1422,
     LOCATE = 1423,
     MARGIN = 1424,
     MEMORY = 1425,
     MINUTE = 1426,
     MODIFY = 1427,
     NORMAL = 1428,
     EQUAL_EQUAL = 1429,
     OPEN_SHEV = 1431,
     OPEN_SQUARE = 1432,
     OPTION = 1433,
     OUTPUT = 1434,
     PROMPT = 1435,
     PUBLIC = 1436,
     RECORD = 1437,
     REPORT = 1438,
     REVOKE = 1439,
     SCHEMA = 1440,
     SCROLL_USING = 1441,
     SCROLL = 1442,
     SECOND = 1443,
     SELECT = 1444,
     SERIAL = 1445,
     SETL = 1446,
     SHARED = 1447,
     SPACES = 1448,
     UNIQUE = 1449,
     UNLOCK = 1450,
     UPDATE = 1451,
     VALUES = 1452,
     YELLOW = 1453,
     AFTER = 1454,
     KWLINE = 1455,
     KW_NULL = 1456,
     KW_TRUE = 1457,
     SINGLE_KEY = 1458,
     ALTER = 1459,
     ARRAY = 1460,
     ASCII = 1461,
     AUDIT = 1462,
     BLACK = 1463,
     BLINK = 1464,
     CHECK = 1465,
     CLEAR = 1466,
     CLOSE = 1467,
     CODE_C = 1468,
     COUNT = 1469,
     DEFER = 1470,
     ERROR = 1471,
     EVERY = 1472,
     FETCH = 1473,
     FIRST = 1474,
     FLOAT = 1475,
     FLUSH = 1476,
     FOUND = 1477,
     GRANT = 1478,
     GREEN = 1479,
     GROUP = 1480,
     INDEX = 1481,
     KWFORM = 1482,
     LABEL = 1483,
     LOCAL = 1485,
     MONEY = 1486,
     MONTH = 1487,
     ORDER = 1490,
     OUTER = 1491,
     PAUSE = 1492,
     PRINT_IMAGE = 1493,
     PRINT_FILE = 1494,
     PRINT = 1495,
     RIGHT = 1496,
     DOUBLE_COLON = 1497,
     SEMICOLON = 1498,
     SLEEP = 1499,
     TUPLE = 1500,
     UNION = 1501,
     WHERE = 1503,
     WHILE = 1504,
     WHITE = 1505,
     CCODE = 1506,
     ANSI = 1507,
     BLUE = 1508,
     BOLD = 1509,
     BYTE = 1510,
     FCALL = 1511,
     CASE = 1512,
     CHAR = 1513,
     CYAN = 1514,
     DATE = 1515,
     DESC = 1516,
     KWDOWN = 1518,
     TAB = 1519,
     DROP = 1520,
     ELSE = 1521,
     EXEC = 1522,
     EXIT = 1523,
     FREE = 1524,
     FROM = 1525,
     GOTO = 1526,
     HELP_FILE = 1527,
     LANG_FILE = 1528,
     HELP = 1529,
     HIDE = 1530,
     HOUR = 1531,
     INTO = 1532,
     LAST = 1533,
     LEFT = 1534,
     LIKE = 1535,
     MAIN = 1536,
     MENU = 1537,
     MODE = 1538,
     NEED = 1539,
     NEXT = 1540,
     NOCR = 1541,
     OPEN = 1542,
     QUIT = 1543,
     REAL = 1544,
     ROWS = 1545,
     SHOW = 1546,
     SIZE = 1547,
     SKIP = 1548,
     SOME = 1549,
     STEP = 1550,
     STOP = 1551,
     TEMP = 1552,
     TEXT = 1553,
     THEN = 1554,
     USER = 1555,
     WAIT = 1556,
     WHEN = 1557,
     WITH = 1558,
     WORK = 1559,
     YEAR = 1560,
     KW_IS = 1562,
     XSET = 1563,
     ADD = 1564,
     ALL = 1565,
     ANY = 1567,
     ASC = 1568,
     AVG = 1569,
     COLON = 1570,
     DAY = 1572,
     DBA = 1573,
     DEC = 1574,
     DIM = 1575,
     FKEY = 1576,
     FOR = 1577,
     KEY = 1578,
     KWNO = 1579,
     LET = 1580,
     LOG = 1581,
     XMAX = 1582,
     XMIN = 1583,
     PAD = 1587,
     PUT = 1588,
     RED = 1589,
     ROW = 1590,
     RUN = 1591,
     SQL = 1592,
     SUM = 1593,
     TOP = 1594,
     USE = 1595,
     ATSIGN = 1596,
     AS_TIFF = 1598,
     AS_GIF = 1599,
     AS_PNG = 1600,
     AS_JPEG = 1601,
     AS = 1602,
     AT = 1603,
     BY = 1604,
     DOT = 1605,
     GO = 1606,
     IF = 1607,
     IN = 1608,
     OF = 1609,
     ON = 1610,
     TO = 1612,
     KWUP = 1613,
     FONT_NAME = 1614,
     FONT_SIZE = 1615,
     PAPER_SIZE_IS_LETTER = 1616,
     PAPER_SIZE_IS_LEGAL = 1617,
     PAPER_SIZE_IS_A5 = 1618,
     PAPER_SIZE_IS_A4 = 1619,
     PAPER_SIZE_IS_LETTER_L = 1620,
     PAPER_SIZE_IS_LEGAL_L = 1621,
     PAPER_SIZE_IS_A5_L = 1622,
     PAPER_SIZE_IS_A4_L = 1623,
     FORMHANDLER = 1624,
     END_FORMHANDLER = 1625,
     BEFORE_EVENT = 1626,
     BEFORE_OPEN_FORM = 1627,
     AFTER_EVENT = 1628,
     BEFORE_CLOSE_FORM = 1629,
     BEFORE_ANY = 1630,
     AFTER_ANY = 1631,
     MENUHANDLER = 1632,
     END_MENUHANDLER = 1633,
     BEFORE_SHOW_MENU = 1634,
     DISABLE_PROGRAM = 1635,
     DISABLE_ALL = 1636,
     BUTTONS = 1637,
     CHECK_MENUITEM = 1638,
     DISABLE_FORM = 1639,
     DISABLE_MENUITEMS = 1640,
     DISABLE = 1641,
     ENABLE_FORM = 1642,
     ENABLE_MENUITEMS = 1643,
     ENABLE = 1644,
     KWFIELD = 1645,
     ICON = 1646,
     MESSAGEBOX = 1647,
     TO_DEFAULTS = 1648,
     UNCHECK_MENUITEM = 1649,
     BEFORE = 1650,
     INPUT = 1651,
     END = 1652,
     INT_TO_ID = 1653,
     TIMEOUT = 1654,
     OFF = 1655,
     DYNAMIC_ARRAY = 1656,
     RESIZE_ARRAY = 1657,
     ALLOCATE_ARRAY = 1658,
     DEALLOCATE_ARRAY = 1659,
     WITH_1_DIMENSION = 1660,
     WITH_2_DIMENSION = 1661,
     WITH_3_DIMENSION = 1662,
     TILDE = 1663,
     ILIKE = 1664
   };
#endif
#define NAME 1666
#define UMINUS 1667
#define COMMA 1571
#define KW_OR 1611
#define KW_AND 1566
#define KW_USING 1502
#define NOT 1586
#define MATCHES 1381
#define POWER 1488
#define LESS_THAN 1484
#define GREATER_THAN 1399
#define EQUAL 1561
#define GREATER_THAN_EQ 1297
#define LESS_THAN_EQ 1356
#define NOT_EQUAL 1430
#define PLUS 1597
#define MINUS 1584
#define MULTIPLY 1489
#define DIVIDE 1517
#define MOD 1585
#define COMMAND 1363
#define NUMBER_VALUE 1668
#define CHAR_VALUE 1669
#define INT_VALUE 1670
#define NAMED_GEN 1671
#define CLINE 1672
#define SQLLINE 1673
#define KW_CSTART 1674
#define KW_CEND 1675
#define USER_DTYPE 1676
#define SQL_TEXT 1677
#define BEFORE_INSERT 1000
#define CONCAT_PIPES 1001
#define BEFORE_DELETE 1002
#define AFTER_INSERT 1003
#define AFTER_DELETE 1004
#define EXECUTE_IMMEDIATE 1005
#define DELETE_ROW_EQUAL_TRUE 1006
#define INSERT_ROW_EQUAL_TRUE 1007
#define DELETE_ROW_EQUAL_FALSE 1008
#define INSERT_ROW_EQUAL_FALSE 1009
#define CURRENT_ROW_DISPLAY_EQUAL 1010
#define MAXCOUNT 1011
#define ALTER_TABLE 1012
#define WHENEVER_ERROR_CONTINUE 1013
#define WHENEVER_WARNING_CONTINUE 1014
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1015
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1016
#define XSET_ident_DOT_MULTIPLY_EQUAL 1017
#define XSET_MULTIPLY_EQUAL 1018
#define XSET_OPEN_BRACKET 1019
#define NEWFORMATSHARED 1020
#define CREATE_DATABASE 1021
#define IMPORT_LEGACY_FUNCTION 1022
#define ADD_CONSTRAINT 1023
#define DROP_CONSTRAINT 1024
#define AS_STATIC 1025
#define NOT_FIELD_TOUCHED 1026
#define LOCAL_FUNCTION 1027
#define EVERY_ROW 1028
#define ELIF 1029
#define DOUBLE_PRECISION 1030
#define COUNT_MULTIPLY 1031
#define WAIT_FOR_KEY 1032
#define AT_TERMINATION_CALL 1033
#define TERMINATE_REPORT 1034
#define TO_MAIN_CAPTION 1035
#define CLEARSTAT 1036
#define TO_MENUITEM 1037
#define ID_TO_INT 1038
#define TO_STATUSBOX 1039
#define ASCII_HEIGHT_ALL 1040
#define ASCII_WIDTH_ALL 1041
#define IMPORT_DATATYPE 1042
#define PAGE_TRAILER_SIZE 1043
#define PAGE_HEADER_SIZE 1044
#define FIRST_PAGE_HEADER_SIZE 1045
#define BYTES_USE_AS_IMAGE 1046
#define BYTES_USE_AS_ASCII 1047
#define KWUP_BY 1048
#define KWDOWN_BY 1049
#define CLOSE_STATUSBOX 1050
#define MODIFY_NEXT_SIZE 1051
#define LOCK_MODE_PAGE 1052
#define LOCK_MODE_ROW 1053
#define TO_PIPE 1054
#define TO_PRINTER 1055
#define STATUSBOX 1056
#define CONNECT_TO 1057
#define FORMHANDLER_INPUT 1058
#define UNITS_YEAR 1059
#define UNITS_MONTH 1060
#define UNITS_DAY 1061
#define UNITS_HOUR 1062
#define UNITS_MINUTE 1063
#define UNITS_SECOND 1064
#define NO_NEW_LINES 1065
#define FIELDTOWIDGET 1066
#define WITH_HOLD 1067
#define SHOW_MENU 1068
#define CWIS 1069
#define CREATE_IDX 1070
#define FORM_IS_COMPILED 1071
#define PDF_REPORT 1072
#define IMPORT_FUNCTION 1073
#define PROMPT_MANY 1074
#define POINTS 1075
#define MM 1076
#define INCHES 1077
#define PREPEND 1078
#define MEMBER_OF 1079
#define MEMBER_FUNCTION 1080
#define APPEND 1081
#define TEMPLATE 1082
#define END_TEMPLATE 1083
#define SQLSICS 1084
#define CREATE_SCHEMA 1085
#define SQLSIRR 1086
#define UPDATESTATS_T 1087
#define SQLSICR 1088
#define WHENEVER_SQLSUCCESS 1089
#define WHENEVER_SQLWARNING 1090
#define START_EXTERN 1091
#define WHENEVER_ANY_ERROR 1092
#define WHENEVER_NOT_FOUND 1093
#define CONTINUE_CONSTRUCT 1094
#define FOUNCONSTR 1095
#define SQLSIDR 1096
#define WHENEVER_SQLERROR 1097
#define CREATE_TEMP_TABLE 1098
#define CURRENT_WINDOW_IS 1099
#define FIRST_PAGE_HEADER 1100
#define ORDER_EXTERNAL_BY 1101
#define SCROLL_CURSOR_FOR 1102
#define SCROLL_CURSOR 1103
#define SQL_INTERRUPT_OFF 1104
#define STOP_ALL_EXTERNAL 1105
#define WITH_CHECK_OPTION 1106
#define WITH_GRANT_OPTION 1107
#define SQLSLMNW 1108
#define ADDCONSTUNIQ 1109
#define CONTINUE_DISPLAY 1110
#define CONTINUE_FOREACH 1111
#define OUTPUT_TO_REPORT 1112
#define SQL_INTERRUPT_ON 1113
#define WHENEVER_SUCCESS 1114
#define WHENEVER_WARNING 1115
#define WHERE_CURRENT_OF 1116
#define WITHOUT_DEFAULTS 1117
#define FOCONSTR 1118
#define SCALED_BY 1119
#define CONTINUE_PROMPT 1120
#define PDF_FUNCTION 1121
#define DEFER_INTERRUPT 1122
#define DISPLAY_BY_NAME 1123
#define NOT_NULL_UNIQUE 1124
#define SKIP_TO_TOP 1125
#define TOP_OF_PAGE 1126
#define SKIP_TO 1127
#define SKIP_BY 1128
#define WITHOUT_WAITING 1129
#define BEFCONSTRUCT 1130
#define SQLSLMW 1131
#define WHENEVER_ERROR 1132
#define AFTCONSTRUCT 1133
#define ALL_PRIVILEGES 1134
#define CLOSE_DATABASE 1135
#define CONTINUE_INPUT 1136
#define CONTINUE_WHILE 1137
#define CREATE_SYNONYM 1138
#define DROP_TABLE 1139
#define EXIT_CONSTRUCT 1140
#define INEXCLUSIVE 1141
#define REPORT_TO_PRINTER 1142
#define REPORT_TO_PIPE 1143
#define RETURN 1144
#define SET_SESSION_TO 1145
#define UPDATESTATS 1146
#define WITHOUT_HEAD 1147
#define CLEARSCR 1148
#define WITH_B_LOG 1149
#define AUTHORIZATION 1150
#define BOTTOM_MARGIN 1151
#define CLOSE_SESSION 1152
#define CONTINUE_CASE 1153
#define CONTINUE_MENU 1154
#define DISPLAY_ARRAY 1155
#define END_SQL 1156
#define DOLLAR 1157
#define END_CONSTRUCT 1158
#define FIELD_TOUCHED 1159
#define FINISH_REPORT 1160
#define INFACC 1161
#define INPUT_NO_WRAP 1162
#define LOCKMODEPAGE 1163
#define SETPMOFF 1164
#define UNCONSTRAINED 1165
#define PAGE_TRAILER 1166
#define SETPMON 1167
#define BEFGROUP 1168
#define CLOSE_WINDOW 1169
#define COMMENT_LINE 1170
#define CONTINUE_FOR 1171
#define CREATE_DB 1172
#define CREATE_TABLE 1173
#define DEFAULT_NULL 1174
#define DELETE_USING 1175
#define DISPLAY_FORM 1176
#define END_FUNCTION 1177
#define EXIT_DISPLAY 1178
#define EXIT_FOREACH 1179
#define EXIT_PROGRAM 1180
#define INFCOLS 1181
#define LOCKMODEROW 1182
#define ON_EVERY_ROW 1183
#define OPEN_SESSION 1184
#define RIGHT_MARGIN 1185
#define SELECT_USING 1186
#define START_REPORT 1187
#define UNLOCK_TABLE 1188
#define UPDATE_USING 1189
#define ACL_BUILTIN 1190
#define AFTGROUP 1191
#define INFIDX 1192
#define INFSTAT 1193
#define LEFT_MARGIN 1194
#define PAGE_HEADER 1195
#define ROLLBACK_W 1196
#define SET_SESSION 1197
#define SQLSEOFF 1198
#define WITH_A_LOG 1199
#define BEFDISP 1200
#define BEFORE_MENU 1201
#define CREATE_VIEW 1202
#define DEFINE_TYPE 1203
#define DELETE_FROM 1204
#define END_DISPLAY 1205
#define END_REPORT 1206
#define END_FOREACH 1207
#define END_FOR 1208
#define END_GLOBALS 1209
#define EXIT_PROMPT 1210
#define EXTENT_SIZE 1211
#define FOREIGN_KEY 1212
#define HIDE_OPTION 1213
#define HIDE_WINDOW 1214
#define INSERT_INTO 1215
#define IS_NOT_NULL 1216
#define MOVE_WINDOW 1217
#define NEXT_OPTION 1218
#define NOT_MATCHES 1219
#define ON_LAST_ROW 1220
#define OPEN_WINDOW 1221
#define OPEN_STATUSBOX 1222
#define PAGE_LENGTH 1223
#define PAGE_WIDTH 1224
#define PRIMARY_KEY 1225
#define PROMPT_LINE 1226
#define RECORD_LIKE 1227
#define ROLLFORWARD 1228
#define SETBL 1229
#define SHOW_OPTION 1230
#define SHOW_WINDOW 1231
#define SQLSEON 1232
#define TO_DATABASE 1233
#define USE_SESSION 1234
#define WITH_NO_LOG 1235
#define AFTDISP 1236
#define BEFFIELD 1237
#define INSHARE 1238
#define UNLOCKTAB 1239
#define AFTFIELD 1240
#define ATTRIBUTES 1241
#define BEFINP 1242
#define BEGIN_WORK 1243
#define CLEARWIN 1244
#define CLOSE_FORM 1245
#define DEFER_QUIT 1246
#define DESCENDING 1247
#define DROP_INDEX 1248
#define END_PROMPT 1249
#define END_RECORD 1250
#define ERROR_LINE 1251
#define EXIT_INPUT 1252
#define EXIT_WHILE 1253
#define FOR_UPDATE_OF 1254
#define FOR_UPDATE 1255
#define GET_FLDBUF 1256
#define INITIALIZE 1257
#define INPUT_WRAP 1258
#define LOCK_TABLE 1259
#define MSG_LINE 1260
#define NOT_EXISTS 1261
#define ON_ANY_KEY 1262
#define REFERENCES 1263
#define RENCOL 1264
#define SET_CURSOR 1265
#define SMALLFLOAT 1266
#define SQLSUCCESS 1267
#define TOP_MARGIN 1268
#define WITH_ARRAY 1269
#define ACCEPTKEY 1270
#define ACCEPT 1271
#define AFTINP 1272
#define CLEARFORMTODEFAULTS 1273
#define CLEARFORM 1274
#define CLEAR_X_FORM 1275
#define COMMIT_W 1276
#define NEXTPAGE 1277
#define PREVPAGE 1278
#define CTRL_KEY 1279
#define INFTABS 1280
#define NEXTFIELD 1281
#define NEXTFORM 1282
#define RENTAB 1283
#define ASCENDING 1284
#define ASSOCIATE 1285
#define CHARACTER 1286
#define CONSTRUCT 1287
#define DELIMITER 1288
#define DOWNSHIFT 1289
#define DROP_VIEW 1290
#define END_INPUT 1291
#define END_WHILE 1292
#define EXCLUSIVE 1293
#define EXIT_CASE 1294
#define EXIT_MENU 1295
#define FORM_LINE 1296
#define INTERRUPT 1298
#define INTO_TEMP 1299
#define INVISIBLE 1300
#define IN_MEMORY 1301
#define LINKED_TO 1302
#define LOAD_FROM 1303
#define LOCKTAB 1304
#define MENU_LINE 1305
#define OPEN_FORM 1306
#define OTHERWISE 1307
#define PRECISION 1308
#define PRIOR 1309
#define PROCEDURE 1310
#define REPORT_TO 1311
#define RETURNING 1312
#define UNDERLINE 1313
#define UNLOAD_TO 1314
#define BEFROW 1315
#define UNLOAD_T 1316
#define VARIABLE 1317
#define ABSOLUTE 1318
#define AFTROW 1319
#define BUFFERED 1320
#define CONSTANT 1321
#define CONST 1322
#define CONTINUE 1323
#define DATABASE 1324
#define DATETIME 1325
#define DEFAULTS 1326
#define DISTINCT 1327
#define END_CASE 1328
#define END_MAIN 1329
#define END_MENU 1330
#define END_TYPE 1331
#define EXIT_FOR 1332
#define EXTERNAL 1333
#define FRACTION 1334
#define FUNCTION 1335
#define GROUP_BY 1336
#define INTERVAL 1337
#define KWMESSAGE 1338
#define NOT_LIKE 1339
#define NOT_ILIKE 1340
#define NOT_NULL 1341
#define PASSWORD 1342
#define PREVIOUS 1343
#define READONLY 1344
#define REGISTER 1345
#define RELATIVE 1346
#define RESOURCE 1347
#define SMALLINT 1348
#define VALIDATE 1349
#define WHENEVER 1350
#define WITH_LOG 1351
#define WORDWRAP 1352
#define BY_NAME 1353
#define IN_FILE 1354
#define IS_NULL 1355
#define AVERAGE 1357
#define BETWEEN 1358
#define CAPTION 1359
#define CLIPPED 1360
#define CLOSE_BRACKET 1361
#define COLUMNS 1362
#define COMMENT 1364
#define CONNECT 1365
#define CURRENT 1366
#define DBYNAME 1367
#define DECIMAL 1368
#define DECLARE 1369
#define DEFAULT 1370
#define DISPLAY 1371
#define ENDCODE 1372
#define EXECUTE 1373
#define FOREACH 1374
#define FOREIGN 1375
#define GLOBALS 1376
#define INFIELD 1377
#define INTEGER 1378
#define KWWINDOW 1379
#define MAGENTA 1380
#define NUMERIC 1382
#define OPTIONS 1383
#define PERCENT 1384
#define PREPARE 1385
#define PROGRAM 1386
#define RECOVER 1387
#define REVERSE 1388
#define SECTION 1389
#define SESSION 1390
#define SYNONYM 1391
#define THRU 1392
#define TRAILER 1393
#define UPSHIFT 1394
#define VARCHAR 1395
#define WAITING 1396
#define CLOSE_SHEV 1397
#define CLOSE_SQUARE 1398
#define KW_FALSE 1400
#define NOT_IN 1401
#define ONKEY 1402
#define OPEN_BRACKET 1403
#define BORDER 1404
#define BOTTOM 1405
#define COLUMN 1406
#define COMMIT 1407
#define CREATE 1408
#define CURSOR 1409
#define DEFINE 1410
#define DELETE 1411
#define DOUBLE 1412
#define END_IF 1413
#define ESCAPE 1414
#define EXISTS 1415
#define EXTEND 1416
#define EXTENT 1417
#define FINISH 1418
#define FORMAT 1419
#define HAVING 1420
#define HEADER 1421
#define INSERT 1422
#define LOCATE 1423
#define MARGIN 1424
#define MEMORY 1425
#define MINUTE 1426
#define MODIFY 1427
#define NORMAL 1428
#define EQUAL_EQUAL 1429
#define OPEN_SHEV 1431
#define OPEN_SQUARE 1432
#define OPTION 1433
#define OUTPUT 1434
#define PROMPT 1435
#define PUBLIC 1436
#define RECORD 1437
#define REPORT 1438
#define REVOKE 1439
#define SCHEMA 1440
#define SCROLL_USING 1441
#define SCROLL 1442
#define SECOND 1443
#define SELECT 1444
#define SERIAL 1445
#define SETL 1446
#define SHARED 1447
#define SPACES 1448
#define UNIQUE 1449
#define UNLOCK 1450
#define UPDATE 1451
#define VALUES 1452
#define YELLOW 1453
#define AFTER 1454
#define KWLINE 1455
#define KW_NULL 1456
#define KW_TRUE 1457
#define SINGLE_KEY 1458
#define ALTER 1459
#define ARRAY 1460
#define ASCII 1461
#define AUDIT 1462
#define BLACK 1463
#define BLINK 1464
#define CHECK 1465
#define CLEAR 1466
#define CLOSE 1467
#define CODE_C 1468
#define COUNT 1469
#define DEFER 1470
#define ERROR 1471
#define EVERY 1472
#define FETCH 1473
#define FIRST 1474
#define FLOAT 1475
#define FLUSH 1476
#define FOUND 1477
#define GRANT 1478
#define GREEN 1479
#define GROUP 1480
#define INDEX 1481
#define KWFORM 1482
#define LABEL 1483
#define LOCAL 1485
#define MONEY 1486
#define MONTH 1487
#define ORDER 1490
#define OUTER 1491
#define PAUSE 1492
#define PRINT_IMAGE 1493
#define PRINT_FILE 1494
#define PRINT 1495
#define RIGHT 1496
#define DOUBLE_COLON 1497
#define SEMICOLON 1498
#define SLEEP 1499
#define TUPLE 1500
#define UNION 1501
#define WHERE 1503
#define WHILE 1504
#define WHITE 1505
#define CCODE 1506
#define ANSI 1507
#define BLUE 1508
#define BOLD 1509
#define BYTE 1510
#define FCALL 1511
#define CASE 1512
#define CHAR 1513
#define CYAN 1514
#define DATE 1515
#define DESC 1516
#define KWDOWN 1518
#define TAB 1519
#define DROP 1520
#define ELSE 1521
#define EXEC 1522
#define EXIT 1523
#define FREE 1524
#define FROM 1525
#define GOTO 1526
#define HELP_FILE 1527
#define LANG_FILE 1528
#define HELP 1529
#define HIDE 1530
#define HOUR 1531
#define INTO 1532
#define LAST 1533
#define LEFT 1534
#define LIKE 1535
#define MAIN 1536
#define MENU 1537
#define MODE 1538
#define NEED 1539
#define NEXT 1540
#define NOCR 1541
#define OPEN 1542
#define QUIT 1543
#define REAL 1544
#define ROWS 1545
#define SHOW 1546
#define SIZE 1547
#define SKIP 1548
#define SOME 1549
#define STEP 1550
#define STOP 1551
#define TEMP 1552
#define TEXT 1553
#define THEN 1554
#define USER 1555
#define WAIT 1556
#define WHEN 1557
#define WITH 1558
#define WORK 1559
#define YEAR 1560
#define KW_IS 1562
#define XSET 1563
#define ADD 1564
#define ALL 1565
#define ANY 1567
#define ASC 1568
#define AVG 1569
#define COLON 1570
#define DAY 1572
#define DBA 1573
#define DEC 1574
#define DIM 1575
#define FKEY 1576
#define FOR 1577
#define KEY 1578
#define KWNO 1579
#define LET 1580
#define LOG 1581
#define XMAX 1582
#define XMIN 1583
#define PAD 1587
#define PUT 1588
#define RED 1589
#define ROW 1590
#define RUN 1591
#define SQL 1592
#define SUM 1593
#define TOP 1594
#define USE 1595
#define ATSIGN 1596
#define AS_TIFF 1598
#define AS_GIF 1599
#define AS_PNG 1600
#define AS_JPEG 1601
#define AS 1602
#define AT 1603
#define BY 1604
#define DOT 1605
#define GO 1606
#define IF 1607
#define IN 1608
#define OF 1609
#define ON 1610
#define TO 1612
#define KWUP 1613
#define FONT_NAME 1614
#define FONT_SIZE 1615
#define PAPER_SIZE_IS_LETTER 1616
#define PAPER_SIZE_IS_LEGAL 1617
#define PAPER_SIZE_IS_A5 1618
#define PAPER_SIZE_IS_A4 1619
#define PAPER_SIZE_IS_LETTER_L 1620
#define PAPER_SIZE_IS_LEGAL_L 1621
#define PAPER_SIZE_IS_A5_L 1622
#define PAPER_SIZE_IS_A4_L 1623
#define FORMHANDLER 1624
#define END_FORMHANDLER 1625
#define BEFORE_EVENT 1626
#define BEFORE_OPEN_FORM 1627
#define AFTER_EVENT 1628
#define BEFORE_CLOSE_FORM 1629
#define BEFORE_ANY 1630
#define AFTER_ANY 1631
#define MENUHANDLER 1632
#define END_MENUHANDLER 1633
#define BEFORE_SHOW_MENU 1634
#define DISABLE_PROGRAM 1635
#define DISABLE_ALL 1636
#define BUTTONS 1637
#define CHECK_MENUITEM 1638
#define DISABLE_FORM 1639
#define DISABLE_MENUITEMS 1640
#define DISABLE 1641
#define ENABLE_FORM 1642
#define ENABLE_MENUITEMS 1643
#define ENABLE 1644
#define KWFIELD 1645
#define ICON 1646
#define MESSAGEBOX 1647
#define TO_DEFAULTS 1648
#define UNCHECK_MENUITEM 1649
#define BEFORE 1650
#define INPUT 1651
#define END 1652
#define INT_TO_ID 1653
#define TIMEOUT 1654
#define OFF 1655
#define DYNAMIC_ARRAY 1656
#define RESIZE_ARRAY 1657
#define ALLOCATE_ARRAY 1658
#define DEALLOCATE_ARRAY 1659
#define WITH_1_DIMENSION 1660
#define WITH_2_DIMENSION 1661
#define WITH_3_DIMENSION 1662
#define TILDE 1663
#define ILIKE 1664




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

int if_print_stack[100][2];
int if_print_stack_cnt=0;
int if_print_section[100]={0,0,0,0};

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
#line 1603 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1615 "y.tab.c"

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
#define YYLAST   9991

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  680
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  835
/* YYNRULES -- Number of rules. */
#define YYNRULES  2239
/* YYNRULES -- Number of states. */
#define YYNSTATES  3515

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1677

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
     324,   325,   326,   327,   328,   329,   330,    15,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,    16,   389,   390,   391,
     392,   393,   394,    23,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,    10,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,    13,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
      17,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,    12,   512,   513,   514,    11,    20,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,     8,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,    21,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,    14,   584,   585,   586,   587,     7,   588,   589,   590,
     591,     5,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,    19,    22,     9,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,    18,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     626,     6,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     675,   676,   677,   678,   679,     2,     3,     4,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    13,    15,    17,    19,    21,
      25,    27,    31,    35,    37,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    58,    59,    61,    62,    68,    75,
      77,    81,    83,    85,    87,    89,    91,    93,    95,    97,
      99,   101,   103,   105,   107,   109,   111,   113,   115,   116,
     118,   119,   125,   127,   131,   133,   135,   138,   141,   144,
     147,   150,   153,   156,   159,   163,   164,   172,   181,   188,
     190,   197,   198,   199,   209,   210,   211,   212,   221,   222,
     223,   234,   235,   236,   246,   247,   248,   249,   264,   265,
     268,   269,   272,   274,   275,   277,   279,   283,   285,   287,
     289,   291,   295,   296,   303,   304,   310,   312,   315,   317,
     320,   322,   323,   324,   328,   329,   330,   334,   335,   340,
     341,   346,   349,   352,   355,   357,   360,   363,   367,   369,
     371,   373,   376,   378,   380,   383,   385,   387,   388,   389,
     395,   403,   412,   413,   416,   418,   422,   424,   428,   432,
     434,   437,   438,   443,   444,   449,   450,   454,   455,   459,
     460,   464,   466,   470,   472,   476,   478,   480,   482,   484,
     486,   488,   493,   494,   499,   501,   503,   504,   506,   508,
     511,   512,   513,   519,   521,   523,   525,   529,   530,   533,
     538,   543,   548,   553,   556,   557,   562,   564,   566,   568,
     571,   573,   575,   579,   580,   582,   583,   585,   587,   589,
     590,   598,   599,   605,   606,   619,   621,   623,   625,   627,
     629,   635,   639,   641,   643,   644,   649,   650,   656,   657,
     665,   667,   671,   673,   675,   676,   678,   679,   680,   685,
     687,   689,   691,   696,   701,   708,   710,   713,   715,   717,
     719,   721,   726,   733,   735,   740,   747,   749,   751,   753,
     755,   757,   759,   761,   764,   767,   769,   771,   776,   778,
     780,   781,   785,   789,   790,   793,   795,   797,   799,   801,
     803,   805,   808,   809,   812,   813,   817,   818,   822,   824,
     825,   829,   831,   833,   835,   837,   839,   841,   844,   846,
     847,   849,   850,   856,   858,   860,   862,   867,   872,   879,
     881,   883,   885,   887,   892,   899,   901,   906,   913,   915,
     917,   919,   921,   923,   926,   929,   931,   936,   937,   945,
     946,   959,   960,   965,   966,   972,   974,   978,   981,   983,
     987,   989,   990,   993,   996,   998,  1001,  1007,  1012,  1015,
    1020,  1026,  1030,  1031,  1032,  1044,  1045,  1048,  1050,  1051,
    1054,  1056,  1059,  1060,  1064,  1065,  1069,  1070,  1074,  1077,
    1080,  1083,  1088,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1133,  1135,  1137,  1139,  1141,  1144,  1146,  1148,
    1150,  1153,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1179,  1181,  1184,  1186,  1188,  1190,  1194,
    1196,  1200,  1202,  1206,  1208,  1210,  1212,  1215,  1217,  1219,
    1223,  1228,  1233,  1236,  1239,  1241,  1243,  1245,  1247,  1249,
    1253,  1255,  1258,  1261,  1263,  1264,  1268,  1271,  1274,  1276,
    1280,  1285,  1290,  1296,  1302,  1304,  1306,  1309,  1312,  1317,
    1322,  1325,  1328,  1333,  1338,  1340,  1343,  1346,  1349,  1352,
    1355,  1358,  1361,  1364,  1367,  1370,  1373,  1376,  1379,  1382,
    1383,  1384,  1385,  1392,  1393,  1394,  1403,  1404,  1405,  1412,
    1413,  1414,  1421,  1422,  1423,  1430,  1431,  1432,  1439,  1445,
    1451,  1457,  1465,  1466,  1470,  1472,  1474,  1479,  1484,  1489,
    1494,  1499,  1504,  1506,  1508,  1510,  1512,  1517,  1522,  1525,
    1528,  1531,  1534,  1537,  1539,  1541,  1544,  1546,  1548,  1550,
    1553,  1558,  1565,  1572,  1576,  1582,  1588,  1592,  1594,  1596,
    1600,  1602,  1606,  1607,  1608,  1620,  1621,  1624,  1625,  1626,
    1627,  1637,  1638,  1642,  1643,  1644,  1655,  1656,  1658,  1659,
    1661,  1663,  1666,  1667,  1671,  1672,  1676,  1677,  1679,  1681,
    1684,  1685,  1689,  1690,  1694,  1698,  1700,  1705,  1709,  1711,
    1715,  1717,  1721,  1723,  1727,  1729,  1732,  1733,  1737,  1738,
    1742,  1743,  1748,  1749,  1754,  1755,  1760,  1763,  1767,  1769,
    1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,  1791,  1793,
    1795,  1800,  1807,  1812,  1816,  1823,  1827,  1834,  1836,  1838,
    1840,  1842,  1844,  1846,  1847,  1850,  1852,  1854,  1856,  1861,
    1863,  1865,  1867,  1872,  1876,  1883,  1887,  1894,  1896,  1898,
    1901,  1904,  1907,  1909,  1913,  1915,  1918,  1921,  1924,  1929,
    1932,  1935,  1940,  1941,  1950,  1951,  1953,  1955,  1957,  1958,
    1960,  1963,  1964,  1966,  1969,  1970,  1972,  1975,  1976,  1978,
    1982,  1983,  1986,  1987,  1988,  1997,  1998,  1999,  2003,  2004,
    2005,  2013,  2019,  2022,  2025,  2026,  2032,  2037,  2039,  2043,
    2047,  2051,  2052,  2055,  2056,  2058,  2060,  2063,  2064,  2069,
    2070,  2075,  2076,  2080,  2081,  2085,  2086,  2090,  2091,  2095,
    2096,  2100,  2101,  2105,  2106,  2110,  2111,  2115,  2116,  2120,
    2122,  2126,  2128,  2132,  2135,  2140,  2142,  2144,  2146,  2147,
    2152,  2158,  2165,  2166,  2177,  2181,  2184,  2187,  2189,  2191,
    2192,  2195,  2197,  2200,  2204,  2208,  2212,  2216,  2218,  2220,
    2222,  2224,  2225,  2229,  2231,  2232,  2236,  2239,  2242,  2244,
    2248,  2250,  2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,
    2270,  2272,  2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,
    2290,  2292,  2294,  2295,  2296,  2304,  2306,  2308,  2311,  2314,
    2317,  2321,  2326,  2327,  2331,  2332,  2334,  2336,  2339,  2341,
    2343,  2345,  2347,  2348,  2350,  2352,  2355,  2358,  2360,  2362,
    2364,  2366,  2368,  2370,  2372,  2374,  2376,  2378,  2380,  2382,
    2384,  2385,  2387,  2389,  2391,  2393,  2395,  2396,  2397,  2398,
    2399,  2413,  2415,  2416,  2417,  2424,  2427,  2429,  2432,  2435,
    2438,  2440,  2442,  2445,  2447,  2449,  2451,  2452,  2456,  2459,
    2461,  2462,  2463,  2464,  2479,  2480,  2486,  2488,  2489,  2493,
    2494,  2502,  2503,  2509,  2511,  2514,  2515,  2517,  2519,  2521,
    2522,  2524,  2526,  2529,  2532,  2535,  2537,  2539,  2541,  2543,
    2547,  2549,  2551,  2552,  2553,  2561,  2563,  2566,  2567,  2571,
    2572,  2577,  2580,  2581,  2584,  2586,  2588,  2590,  2592,  2594,
    2596,  2598,  2602,  2603,  2605,  2607,  2609,  2611,  2614,  2617,
    2620,  2626,  2635,  2637,  2639,  2641,  2646,  2651,  2653,  2655,
    2657,  2659,  2662,  2665,  2669,  2676,  2678,  2682,  2684,  2686,
    2688,  2692,  2699,  2709,  2711,  2713,  2715,  2717,  2720,  2721,
    2723,  2725,  2729,  2731,  2735,  2737,  2741,  2743,  2747,  2749,
    2751,  2753,  2755,  2759,  2761,  2765,  2767,  2771,  2773,  2775,
    2777,  2781,  2784,  2785,  2787,  2789,  2794,  2796,  2800,  2802,
    2806,  2814,  2815,  2823,  2824,  2831,  2835,  2837,  2841,  2843,
    2846,  2852,  2853,  2861,  2862,  2865,  2866,  2868,  2874,  2877,
    2883,  2884,  2890,  2897,  2902,  2903,  2905,  2907,  2912,  2913,
    2916,  2917,  2923,  2928,  2931,  2933,  2937,  2940,  2943,  2946,
    2949,  2952,  2955,  2957,  2960,  2963,  2966,  2969,  2972,  2975,
    2978,  2981,  2984,  2986,  2988,  2990,  2992,  2994,  2996,  3002,
    3004,  3006,  3009,  3014,  3017,  3019,  3020,  3032,  3033,  3036,
    3042,  3043,  3045,  3046,  3049,  3051,  3054,  3055,  3059,  3061,
    3062,  3067,  3068,  3071,  3073,  3077,  3079,  3081,  3085,  3090,
    3095,  3098,  3100,  3102,  3104,  3105,  3107,  3115,  3118,  3121,
    3124,  3127,  3130,  3132,  3135,  3136,  3140,  3141,  3145,  3146,
    3150,  3151,  3155,  3156,  3160,  3161,  3166,  3167,  3172,  3174,
    3176,  3178,  3180,  3182,  3184,  3185,  3190,  3191,  3193,  3194,
    3199,  3201,  3204,  3207,  3210,  3211,  3213,  3215,  3218,  3221,
    3222,  3225,  3229,  3233,  3239,  3240,  3243,  3248,  3250,  3252,
    3254,  3256,  3258,  3259,  3261,  3263,  3267,  3270,  3276,  3279,
    3285,  3291,  3297,  3303,  3309,  3315,  3316,  3319,  3321,  3324,
    3327,  3330,  3333,  3336,  3339,  3341,  3344,  3347,  3350,  3353,
    3355,  3358,  3361,  3364,  3367,  3369,  3371,  3373,  3374,  3377,
    3380,  3383,  3386,  3389,  3392,  3395,  3398,  3401,  3403,  3405,
    3407,  3409,  3411,  3413,  3415,  3417,  3420,  3423,  3426,  3429,
    3432,  3434,  3436,  3438,  3439,  3443,  3446,  3447,  3448,  3449,
    3450,  3451,  3452,  3468,  3469,  3472,  3475,  3476,  3478,  3479,
    3480,  3481,  3482,  3483,  3484,  3500,  3503,  3504,  3505,  3506,
    3517,  3518,  3520,  3524,  3528,  3531,  3536,  3540,  3544,  3548,
    3550,  3552,  3554,  3556,  3558,  3560,  3561,  3562,  3570,  3571,
    3572,  3581,  3585,  3588,  3589,  3591,  3593,  3597,  3600,  3603,
    3605,  3607,  3611,  3613,  3615,  3618,  3620,  3624,  3626,  3630,
    3632,  3634,  3636,  3638,  3640,  3642,  3644,  3647,  3652,  3654,
    3658,  3660,  3664,  3667,  3672,  3674,  3678,  3680,  3683,  3688,
    3690,  3694,  3696,  3698,  3700,  3703,  3706,  3711,  3714,  3719,
    3721,  3725,  3727,  3729,  3731,  3734,  3736,  3738,  3740,  3742,
    3744,  3747,  3754,  3761,  3762,  3764,  3765,  3767,  3770,  3772,
    3773,  3779,  3780,  3786,  3788,  3789,  3793,  3795,  3799,  3801,
    3805,  3807,  3809,  3810,  3811,  3817,  3819,  3822,  3824,  3825,
    3826,  3830,  3831,  3832,  3836,  3838,  3840,  3842,  3844,  3846,
    3848,  3851,  3854,  3859,  3863,  3867,  3869,  3873,  3876,  3878,
    3880,  3881,  3883,  3885,  3887,  3889,  3890,  3892,  3896,  3898,
    3900,  3901,  3905,  3907,  3909,  3911,  3913,  3915,  3917,  3919,
    3921,  3923,  3925,  3927,  3929,  3937,  3938,  3940,  3942,  3944,
    3946,  3950,  3952,  3954,  3956,  3959,  3960,  3964,  3966,  3970,
    3972,  3976,  3978,  3980,  3987,  3988,  3992,  3994,  3998,  3999,
    4001,  4006,  4012,  4015,  4017,  4019,  4024,  4026,  4030,  4035,
    4040,  4042,  4046,  4048,  4050,  4052,  4055,  4057,  4062,  4063,
    4065,  4066,  4068,  4070,  4073,  4075,  4077,  4079,  4081,  4086,
    4090,  4092,  4094,  4096,  4099,  4101,  4103,  4106,  4109,  4111,
    4115,  4118,  4121,  4123,  4127,  4129,  4132,  4137,  4139,  4142,
    4144,  4148,  4153,  4154,  4156,  4157,  4159,  4160,  4162,  4164,
    4168,  4170,  4174,  4176,  4179,  4181,  4185,  4188,  4191,  4192,
    4195,  4197,  4199,  4205,  4209,  4215,  4219,  4221,  4225,  4227,
    4229,  4230,  4232,  4236,  4240,  4244,  4251,  4256,  4261,  4266,
    4271,  4277,  4279,  4281,  4283,  4285,  4287,  4289,  4291,  4293,
    4295,  4297,  4299,  4301,  4302,  4304,  4306,  4308,  4310,  4312,
    4314,  4316,  4321,  4327,  4329,  4335,  4341,  4343,  4345,  4347,
    4352,  4354,  4359,  4361,  4369,  4371,  4373,  4375,  4380,  4387,
    4388,  4391,  4396,  4398,  4400,  4402,  4404,  4406,  4408,  4410,
    4414,  4416,  4418,  4422,  4424,  4425,  4429,  4435,  4437,  4440,
    4443,  4448,  4452,  4454,  4456,  4458,  4460,  4462,  4464,  4467,
    4470,  4471,  4475,  4476,  4480,  4482,  4484,  4486,  4488,  4490,
    4492,  4494,  4499,  4501,  4503,  4505,  4507,  4509,  4511,  4513,
    4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,
    4538,  4540,  4542,  4544,  4546,  4548,  4550,  4554,  4555,  4564,
    4565,  4575,  4576,  4584,  4585,  4595,  4596,  4598,  4601,  4603,
    4607,  4609,  4613,  4619,  4621,  4623,  4625,  4627,  4630,  4631,
    4632,  4641,  4647,  4649,  4651,  4658,  4659,  4663,  4665,  4669,
    4674,  4676,  4677,  4680,  4685,  4692,  4693,  4695,  4697,  4699,
    4701,  4705,  4707,  4710,  4712,  4714,  4717,  4720,  4722,  4724,
    4726,  4729,  4734,  4738,  4741,  4745,  4749,  4753,  4755,  4757,
    4759,  4761,  4763,  4765,  4771,  4777,  4783,  4789,  4795,  4800,
    4805,  4809,  4814,  4816,  4820,  4822,  4828,  4836,  4842,  4843,
    4846,  4848,  4850,  4851,  4855,  4857,  4861,  4863,  4865,  4867,
    4868,  4872,  4874,  4876,  4878,  4880,  4885,  4892,  4894,  4896,
    4899,  4903,  4905,  4907,  4909,  4911,  4913,  4915,  4917,  4919,
    4925,  4931,  4936,  4937,  4942,  4944,  4947,  4949,  4951,  4953,
    4955,  4957,  4959,  4961,  4963,  4965,  4967,  4969,  4971,  4973,
    4975,  4977,  4979,  4981,  4983,  4985,  4987,  4989,  4991,  4993,
    4995,  4997,  4999,  5001,  5003,  5005,  5007,  5009,  5011,  5013,
    5015,  5017,  5019,  5021,  5023,  5025,  5027,  5029,  5031,  5033,
    5035,  5037,  5039,  5041,  5043,  5045,  5047,  5049,  5051,  5053,
    5055,  5057,  5059,  5061,  5063,  5065,  5067,  5069,  5071,  5073,
    5075,  5077,  5079,  5081,  5083,  5085,  5087,  5089,  5091,  5093,
    5095,  5097,  5099,  5101,  5103,  5105,  5107,  5109,  5111,  5113,
    5115,  5117,  5119,  5121,  5123,  5125,  5127,  5129,  5131,  5133,
    5135,  5137,  5139,  5141,  5143,  5145,  5147,  5149,  5151,  5153,
    5155,  5157,  5159,  5161,  5163,  5165,  5167,  5169,  5171,  5173,
    5175,  5177,  5179,  5181,  5183,  5185,  5187,  5189,  5191,  5193,
    5195,  5197,  5199,  5201,  5203,  5205,  5207,  5209,  5211,  5213,
    5215,  5217,  5219,  5221,  5223,  5225,  5227,  5229,  5231,  5233,
    5235,  5237,  5239,  5241,  5243,  5245,  5247,  5249,  5251,  5253,
    5255,  5257,  5259,  5261,  5263,  5265,  5267,  5269,  5271,  5273,
    5275,  5277,  5279,  5281,  5283,  5285,  5287,  5289,  5291,  5293,
    5295,  5297,  5299,  5301,  5303,  5305,  5307,  5309,  5311,  5313,
    5315,  5317,  5319,  5321,  5323,  5325,  5327,  5329,  5331,  5333,
    5335,  5337,  5339,  5341,  5343,  5345,  5347,  5349,  5351,  5353,
    5355,  5357,  5359,  5361,  5363,  5365,  5367,  5369,  5371,  5373,
    5375,  5377,  5379,  5381,  5383,  5385,  5387,  5389,  5391,  5393,
    5395,  5397,  5399,  5401,  5403,  5405,  5407,  5409,  5411,  5413,
    5415,  5417,  5419,  5421,  5423,  5425,  5427,  5429,  5431,  5433,
    5435,  5437,  5439,  5441,  5443,  5445,  5447,  5449,  5451,  5453,
    5455,  5457,  5459,  5461,  5463,  5465,  5467,  5469,  5471,  5473,
    5475,  5477,  5479,  5481,  5483,  5485,  5487,  5489,  5491,  5493,
    5495,  5497,  5499,  5501,  5503,  5505,  5507,  5509,  5511,  5513,
    5515,  5517,  5519,  5521,  5523,  5525,  5527,  5529,  5531,  5533,
    5535,  5537,  5539,  5541,  5543,  5545,  5547,  5549,  5551,  5553,
    5555,  5557,  5559,  5561,  5563,  5565,  5567,  5569,  5571,  5573,
    5575,  5577,  5579,  5581,  5583,  5585,  5587,  5589,  5591,  5593,
    5594,  5598,  5599,  5603,  5604,  5605,  5612,  5613,  5616,  5619,
    5627,  5631,  5635,  5638,  5641,  5644,  5646,  5650,  5652,  5656,
    5658,  5662,  5664,  5668,  5670,  5672,  5674,  5677,  5680,  5682,
    5684,  5687,  5692,  5694,  5696,  5698,  5700,  5702,  5704,  5708,
    5711,  5715,  5719,  5723,  5729,  5735,  5741,  5747,  5753,  5758,
    5763,  5767,  5772,  5774,  5776,  5780,  5782,  5785,  5787,  5789,
    5791,  5795,  5801,  5803,  5805,  5807,  5809,  5813,  5816,  5819,
    5822,  5824,  5827,  5830,  5832,  5835,  5838,  5841,  5843,  5847,
    5850,  5852,  5855,  5857,  5860,  5862,  5863,  5864,  5871,  5872,
    5875,  5876,  5878,  5880,  5883,  5886,  5888,  5890,  5895,  5899,
    5901,  5905,  5907,  5910,  5916,  5919,  5922,  5928,  5929,  5932,
    5934,  5936,  5939,  5946,  5953,  5955,  5956,  5958,  5961,  5963,
    5966,  5967,  5970,  5972,  5974,  5976,  5978,  5980,  5982,  5984,
    5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,  6002,  6004,
    6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,  6022,  6024,
    6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,  6044,
    6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,  6064,
    6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,  6084,
    6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,  6104,
    6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,  6124,
    6126,  6128,  6130,  6132,  6134,  6136,  6138,  6140,  6142,  6144
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1043,     0,    -1,   201,    -1,   198,    -1,   125,   685,   428,
     597,   686,    -1,   139,    -1,  1108,    -1,    26,    -1,   687,
      -1,   686,     5,   687,    -1,   955,    -1,   432,   688,   393,
      -1,   688,   689,   688,    -1,    26,    -1,   690,    26,    -1,
    1108,    -1,   897,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   692,
      -1,    -1,   275,   432,   693,   694,   393,    -1,   570,   432,
      26,     5,    26,   393,    -1,   695,    -1,   694,     5,   695,
      -1,   491,    -1,   532,    -1,   538,    -1,   507,    -1,   411,
      -1,   606,    -1,   529,    -1,   481,    -1,   418,    -1,   492,
      -1,   346,    -1,   533,    -1,   457,    -1,   333,    -1,   595,
      -1,    99,    -1,  1022,    -1,    -1,   697,    -1,    -1,   275,
     432,   698,   699,   393,    -1,   700,    -1,   699,     5,   700,
      -1,   695,    -1,   433,    -1,   604,    25,    -1,   204,   942,
      -1,   330,   942,    -1,   285,   942,    -1,   338,   942,    -1,
     294,   942,    -1,   260,   942,    -1,   535,   702,    -1,   886,
     345,  1108,    -1,    -1,   290,   432,  1499,   393,   345,   703,
    1127,    -1,   105,   432,   955,     5,    25,     5,    25,   393,
      -1,   408,   432,   947,   393,   345,  1108,    -1,  1246,    -1,
     193,   432,   905,   393,   345,  1108,    -1,    -1,    -1,  1108,
     591,   955,   432,   704,   718,   393,   705,   716,    -1,    -1,
      -1,    -1,   955,   432,   706,   718,   707,   393,   708,   716,
      -1,    -1,    -1,   475,  1444,   624,  1444,   432,   709,   718,
     710,   393,   716,    -1,    -1,    -1,   955,   522,   955,   432,
     711,   718,   712,   393,   716,    -1,    -1,    -1,    -1,   366,
     721,   591,   722,   460,   685,   428,   432,   713,   718,   714,
     393,   715,   717,    -1,    -1,   345,  1127,    -1,    -1,   345,
    1127,    -1,   163,    -1,    -1,   719,    -1,   720,    -1,   719,
       5,   720,    -1,   855,    -1,    25,    -1,   955,    -1,   955,
      -1,   955,   621,   955,    -1,    -1,   536,   862,   724,   727,
     731,   728,    -1,    -1,   536,   725,   726,   729,   728,    -1,
     733,    -1,   726,   733,    -1,   735,    -1,   727,   735,    -1,
     361,    -1,    -1,    -1,   340,   730,  1509,    -1,    -1,    -1,
     340,   732,  1509,    -1,    -1,   580,   862,   734,  1509,    -1,
      -1,   580,   862,   736,  1509,    -1,   279,   952,    -1,   203,
     950,    -1,    84,   950,    -1,   169,    -1,   186,  1450,    -1,
     495,   949,    -1,    30,   739,    31,    -1,   740,    -1,   742,
      -1,   741,    -1,   740,   741,    -1,    29,    -1,   743,    -1,
     742,   743,    -1,    28,    -1,   395,    -1,    -1,    -1,   321,
     746,   748,   747,   749,    -1,   386,  1108,   626,   750,   996,
    1021,   691,    -1,  1108,   626,   750,   996,   548,  1499,  1021,
     691,    -1,    -1,   752,   192,    -1,   751,    -1,   750,     5,
     751,    -1,   955,    -1,   955,   621,   955,    -1,   955,   621,
      20,    -1,   753,    -1,   752,   753,    -1,    -1,   271,   759,
     754,  1509,    -1,    -1,   274,   760,   755,  1509,    -1,    -1,
    1024,   756,  1509,    -1,    -1,   167,   757,  1509,    -1,    -1,
     164,   758,  1509,    -1,   959,    -1,   759,     5,   959,    -1,
     959,    -1,   760,     5,   959,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    97,    -1,    98,    -1,   432,   855,
     763,   393,    -1,    -1,     5,   806,   627,   809,    -1,   156,
      -1,   280,    -1,    -1,   766,    -1,   767,    -1,   766,   767,
      -1,    -1,    -1,   439,   768,   770,   769,  1215,    -1,   819,
      -1,  1489,    -1,   773,    -1,   770,     5,   773,    -1,    -1,
     772,   955,    -1,   354,   771,   818,    25,    -1,   354,   771,
     818,   955,    -1,   354,   771,   818,   961,    -1,   354,   771,
     818,    26,    -1,   777,   795,    -1,    -1,   771,   354,   774,
     775,    -1,    26,    -1,    25,    -1,   961,    -1,    19,    26,
      -1,   771,    -1,   776,    -1,   777,     5,   776,    -1,    -1,
     537,    -1,    -1,   675,    -1,   676,    -1,   677,    -1,    -1,
     488,   460,   787,   428,   781,   625,   795,    -1,    -1,   671,
     779,   782,   625,   795,    -1,    -1,   319,   778,   784,    26,
     785,   303,   460,   786,   428,   783,   625,   795,    -1,   432,
      -1,   459,    -1,   393,    -1,   427,    -1,    26,    -1,   788,
       5,   788,     5,   788,    -1,   788,     5,   788,    -1,   788,
      -1,    26,    -1,    -1,   465,   790,   770,   284,    -1,    -1,
     261,   791,   771,   621,    20,    -1,    -1,   335,   792,   771,
     259,   432,   793,   393,    -1,   794,    -1,   793,     5,   794,
      -1,   771,    -1,   797,    -1,    -1,    59,    -1,    -1,    -1,
     798,   800,   799,   796,    -1,   780,    -1,   789,    -1,   537,
      -1,   537,   432,    26,   393,    -1,   425,   432,    26,   393,
      -1,   425,   432,    26,     5,    26,   393,    -1,   409,    -1,
     618,   771,    -1,   381,    -1,   510,    -1,    90,    -1,   399,
      -1,   399,   432,    26,   393,    -1,   399,   432,    26,     5,
      26,   393,    -1,   513,    -1,   513,   432,    26,   393,    -1,
     513,   432,    26,     5,    26,   393,    -1,   503,    -1,   300,
      -1,   539,    -1,   534,    -1,    80,    -1,    81,    -1,   576,
      -1,   358,   804,    -1,   370,   805,    -1,   801,    -1,    32,
      -1,   558,   802,   621,   803,    -1,   771,    -1,   771,    -1,
      -1,   806,   627,   809,    -1,   814,   627,   817,    -1,    -1,
     807,   808,    -1,   583,    -1,   514,    -1,   592,    -1,   554,
      -1,   455,    -1,   471,    -1,   367,   811,    -1,    -1,   810,
     808,    -1,    -1,   432,   813,   393,    -1,    -1,   432,    26,
     393,    -1,    26,    -1,    -1,   815,   816,   812,    -1,   583,
      -1,   514,    -1,   592,    -1,   554,    -1,   455,    -1,   471,
      -1,   367,   811,    -1,   816,    -1,    -1,    14,    -1,    -1,
     237,   955,   820,   618,   821,    -1,   823,    -1,   826,    -1,
     537,    -1,   537,   432,    26,   393,    -1,   425,   432,    26,
     393,    -1,   425,   432,    26,     5,    26,   393,    -1,   409,
      -1,   381,    -1,   510,    -1,   399,    -1,   399,   432,    26,
     393,    -1,   399,   432,    26,     5,    26,   393,    -1,   513,
      -1,   513,   432,    26,   393,    -1,   513,   432,    26,     5,
      26,   393,    -1,   503,    -1,   300,    -1,   539,    -1,   534,
      -1,   576,    -1,   358,   804,    -1,   370,   805,    -1,   822,
      -1,   558,   802,   621,   803,    -1,    -1,   488,   460,   787,
     428,   824,   625,   821,    -1,    -1,   319,   778,   784,    26,
     785,   303,   460,   786,   428,   825,   625,   821,    -1,    -1,
     465,   827,   829,   284,    -1,    -1,   261,   828,   955,   621,
      20,    -1,   830,    -1,   829,     5,   830,    -1,   831,   821,
      -1,   832,    -1,   831,     5,   832,    -1,   955,    -1,    -1,
     619,   946,    -1,    71,   955,    -1,    69,    -1,   627,  1499,
      -1,   627,   510,   955,   660,  1499,    -1,   627,   510,   955,
     391,    -1,    73,   955,    -1,   157,   880,  1127,   841,    -1,
     402,   880,   860,   833,   841,    -1,   210,   952,   841,    -1,
      -1,    -1,   189,   838,  1134,   627,   955,   621,    20,   840,
     691,   839,   842,    -1,    -1,   469,   947,    -1,   691,    -1,
      -1,   843,   239,    -1,   844,    -1,   843,   844,    -1,    -1,
     352,   845,  1509,    -1,    -1,   348,   846,  1509,    -1,    -1,
    1024,   847,  1509,    -1,   673,  1108,    -1,   674,  1108,    -1,
     672,  1108,    -1,   499,   880,   861,   691,    -1,   499,   880,
     861,   691,    66,    -1,   287,    -1,   286,    -1,   213,    -1,
     365,    -1,   174,    -1,   212,    -1,   329,    -1,   328,    -1,
     244,    -1,   171,    -1,   170,    -1,   145,    -1,   205,    -1,
     128,    -1,   144,    -1,   188,    -1,   154,    -1,   214,    -1,
     214,   862,    -1,   865,    -1,   864,    -1,   869,    -1,   897,
      -1,   855,   856,    -1,   898,    -1,   900,    -1,   866,    -1,
      19,   855,    -1,    18,   855,    -1,   871,    -1,   879,    -1,
     873,    -1,   476,    -1,   761,    -1,   874,    -1,   875,    -1,
     876,    -1,   877,    -1,   878,    -1,    35,   855,    -1,   880,
      -1,   880,   859,    -1,   862,    -1,   484,    -1,   858,    -1,
     859,     5,   858,    -1,   862,    -1,   860,     5,   862,    -1,
     862,    -1,   861,     5,   862,    -1,   855,    -1,    18,    -1,
      19,    -1,     9,   855,    -1,   485,    -1,   429,    -1,   432,
     855,   393,    -1,   444,   432,  1424,   393,    -1,   295,   432,
    1424,   393,    -1,   863,   961,    -1,   863,    26,    -1,    25,
      -1,   961,    -1,    26,    -1,   868,    -1,  1108,    -1,  1108,
     422,  1108,    -1,   867,    -1,   435,   855,    -1,   394,   855,
      -1,  1218,    -1,    -1,   508,   870,  1218,    -1,     7,   855,
      -1,     6,   855,    -1,   855,    -1,   872,     5,   855,    -1,
     624,   432,  1424,   393,    -1,   430,   432,  1424,   393,    -1,
     624,   432,   880,   872,   393,    -1,   430,   432,   880,   872,
     393,    -1,   388,    -1,   250,    -1,    10,   855,    -1,   253,
     855,    -1,    10,   855,   443,    25,    -1,   253,   855,   443,
      25,    -1,   558,   855,    -1,   372,   855,    -1,   558,   855,
     443,    25,    -1,   372,   855,   443,    25,    -1,   392,    -1,
       8,   855,    -1,    18,   855,    -1,    19,   855,    -1,    20,
     855,    -1,    21,   855,    -1,    22,   855,    -1,    11,   855,
      -1,    14,   855,    -1,   458,   855,    -1,    12,   855,    -1,
      13,   855,    -1,    17,   855,    -1,    16,   855,    -1,    15,
     855,    -1,    -1,    -1,    -1,   955,   432,   882,   718,   883,
     393,    -1,    -1,    -1,   955,   522,   955,   432,   884,   718,
     885,   393,    -1,    -1,    -1,   539,   432,   887,   855,   888,
     393,    -1,    -1,    -1,   514,   432,   889,   855,   890,   393,
      -1,    -1,    -1,   592,   432,   891,   855,   892,   393,    -1,
      -1,    -1,   583,   432,   893,   855,   894,   393,    -1,   370,
     432,   901,   393,   896,    -1,   358,   432,    25,   393,   895,
      -1,   358,   432,    26,   393,   895,    -1,   358,   432,    26,
     591,    26,   393,   895,    -1,    -1,  1404,   627,  1405,    -1,
     805,    -1,   886,    -1,   290,   432,  1499,   393,    -1,   100,
     432,   947,   393,    -1,    72,   432,   947,   393,    -1,   408,
     432,  1499,   393,    -1,   193,   432,  1499,   393,    -1,    60,
     432,  1499,   393,    -1,   899,    -1,   881,    -1,  1400,    -1,
     539,    -1,   424,   432,   855,   393,    -1,   323,   432,   855,
     393,    -1,   489,   855,    -1,   445,   762,    -1,   855,   109,
      -1,   855,   110,    -1,   855,   111,    -1,    25,    -1,   902,
      -1,    19,   902,    -1,   904,    -1,   903,    -1,    26,    -1,
      26,    26,    -1,    26,    26,   591,    26,    -1,    26,    26,
     591,    26,   591,    26,    -1,    26,    26,   591,    26,   591,
      24,    -1,    26,   591,    26,    -1,    26,   591,    26,   591,
      26,    -1,    26,   591,    26,   591,    24,    -1,    26,   591,
      24,    -1,    24,    -1,    26,    -1,    26,    19,    26,    -1,
     947,    -1,   905,     5,   947,    -1,    -1,    -1,   597,  1108,
      14,   862,   627,   862,   909,   907,  1509,   908,   242,    -1,
      -1,   573,   862,    -1,    -1,    -1,    -1,   405,   911,   949,
     912,   914,  1305,   913,  1509,   241,    -1,    -1,     8,   880,
     860,    -1,    -1,    -1,   639,   955,   916,   765,   917,  1053,
     919,   918,   924,   640,    -1,    -1,   929,    -1,    -1,   920,
      -1,   921,    -1,   920,   921,    -1,    -1,   641,   922,  1509,
      -1,    -1,   642,   923,  1509,    -1,    -1,   925,    -1,   926,
      -1,   925,   926,    -1,    -1,   643,   927,  1509,    -1,    -1,
     644,   928,  1509,    -1,   930,   934,   325,    -1,    92,    -1,
      92,   931,   548,   932,    -1,    92,   386,   933,    -1,  1108,
      -1,   931,     5,  1108,    -1,   955,    -1,   932,     5,   955,
      -1,  1108,    -1,   933,     5,  1108,    -1,   935,    -1,   934,
     935,    -1,    -1,   645,   936,  1509,    -1,    -1,   646,   937,
    1509,    -1,    -1,   665,   932,   938,  1509,    -1,    -1,   482,
     932,   939,  1509,    -1,    -1,   626,   932,   940,  1509,    -1,
     547,   948,    -1,   556,    19,    26,    -1,   556,    -1,   502,
      18,    26,    -1,   502,    -1,    26,    -1,  1108,    -1,   670,
      -1,    25,    -1,   960,    -1,   862,    -1,   944,     5,   944,
      -1,   945,    -1,   955,    -1,   668,   432,   955,   393,    -1,
     955,   621,   668,   432,   955,   393,    -1,   955,   460,   688,
     428,    -1,   955,   621,    20,    -1,   955,   460,   688,   428,
     621,    20,    -1,   955,   621,   955,    -1,   955,   460,   688,
     428,   621,   955,    -1,   956,    -1,   956,    -1,   956,    -1,
     956,    -1,   956,    -1,   956,    -1,    -1,   552,    26,    -1,
    1508,    -1,   957,    -1,  1508,    -1,   350,   432,   958,   393,
      -1,  1111,    -1,    25,    -1,   955,    -1,   955,   460,   688,
     428,    -1,   955,   621,    20,    -1,   955,   460,   688,   428,
     621,    20,    -1,   955,   621,   955,    -1,   955,   460,   688,
     428,   621,   955,    -1,  1108,    -1,    24,    -1,   621,    26,
      -1,   549,  1491,    -1,   653,   964,    -1,   965,    -1,   964,
       5,   965,    -1,   955,    -1,   664,   964,    -1,   655,   964,
      -1,   656,  1499,    -1,   654,   952,   660,  1499,    -1,   658,
     964,    -1,   659,  1499,    -1,   657,   952,   660,  1499,    -1,
      -1,   662,   970,   860,   975,   977,   979,   971,   973,    -1,
      -1,   972,    -1,   650,    -1,   651,    -1,    -1,   974,    -1,
     345,  1108,    -1,    -1,   976,    -1,   391,   860,    -1,    -1,
     978,    -1,   661,    26,    -1,    -1,   980,    -1,   652,    26,
     981,    -1,    -1,   401,    26,    -1,    -1,    -1,   623,   862,
     577,   983,  1509,   984,   985,   442,    -1,    -1,    -1,   544,
     986,  1509,    -1,    -1,    -1,    63,   987,   862,   577,   988,
    1509,   985,    -1,   107,   955,   432,    26,   393,    -1,    56,
     955,    -1,    76,   955,    -1,    -1,   291,  1139,   992,   627,
     484,    -1,   291,  1139,   558,   993,    -1,   994,    -1,   993,
       5,   994,    -1,   802,   621,  1396,    -1,   802,   621,    20,
      -1,    -1,   997,   325,    -1,    -1,   151,    -1,   998,    -1,
     997,   998,    -1,    -1,   271,  1010,   999,  1509,    -1,    -1,
     274,  1011,  1000,  1509,    -1,    -1,   352,  1001,  1509,    -1,
      -1,   348,  1002,  1509,    -1,    -1,  1024,  1003,  1509,    -1,
      -1,   306,  1004,  1509,    -1,    -1,   276,  1005,  1509,    -1,
      -1,    36,  1006,  1509,    -1,    -1,    34,  1007,  1509,    -1,
      -1,    38,  1008,  1509,    -1,    -1,    37,  1009,  1509,    -1,
     947,    -1,  1010,     5,   947,    -1,   947,    -1,  1011,     5,
     947,    -1,   315,  1014,    -1,   316,   955,   660,  1014,    -1,
     563,    -1,   376,    -1,   947,    -1,    -1,   666,  1017,  1016,
     995,    -1,   386,  1127,   996,   954,   691,    -1,  1127,   996,
     548,  1499,   954,   691,    -1,    -1,   488,  1134,   996,   548,
     955,   621,    20,   954,  1018,   691,    -1,   470,  1499,  1020,
      -1,    82,    26,    -1,    83,    26,    -1,   628,    -1,   541,
      -1,    -1,   552,    26,    -1,  1023,    -1,    44,    25,    -1,
     497,    14,    26,    -1,   497,    14,  1108,    -1,    45,    14,
      26,    -1,    45,    14,  1108,    -1,    41,    -1,    43,    -1,
      40,    -1,    42,    -1,    -1,   431,  1025,  1030,    -1,   296,
      -1,    -1,   598,  1027,  1030,    -1,   304,  1032,    -1,   598,
    1030,    -1,  1032,    -1,   432,  1031,   393,    -1,  1032,    -1,
    1031,     5,  1032,    -1,  1033,    -1,   596,    -1,   313,    -1,
     331,    -1,   305,    -1,   486,    -1,   443,    -1,   628,    -1,
     552,    -1,   541,    -1,   178,    -1,   440,    -1,   451,    -1,
     542,    -1,   557,    -1,   521,    -1,   311,    -1,   312,    -1,
      25,    -1,   511,    -1,    -1,    -1,   600,  1036,  1132,  1037,
      14,   880,  1038,    -1,   484,    -1,   861,    -1,   220,  1108,
      -1,   209,  1108,    -1,   223,  1108,    -1,   452,  1108,   334,
      -1,   452,  1108,   387,   943,    -1,    -1,  1045,  1044,  1048,
      -1,    -1,  1046,    -1,  1047,    -1,  1046,  1047,    -1,   990,
      -1,  1052,    -1,  1068,    -1,  1054,    -1,    -1,  1049,    -1,
    1051,    -1,  1049,  1051,    -1,    67,   955,    -1,  1056,    -1,
    1062,    -1,  1074,    -1,  1228,    -1,  1238,    -1,  1095,    -1,
    1489,    -1,   915,    -1,   738,    -1,   989,    -1,   744,    -1,
     738,    -1,  1489,    -1,    -1,   738,    -1,  1489,    -1,   766,
      -1,   368,    -1,    61,    -1,    -1,    -1,    -1,    -1,  1055,
    1057,   955,   432,  1058,  1125,   393,  1059,   765,  1060,  1053,
    1509,  1061,    -1,   211,    -1,    -1,    -1,   559,  1063,   765,
    1064,  1509,   362,    -1,   178,   857,    -1,   880,    -1,   880,
     860,    -1,   357,  1408,    -1,   468,  1408,    -1,  1069,    -1,
    1070,    -1,  1069,  1070,    -1,  1071,    -1,  1052,    -1,  1067,
      -1,    -1,   407,  1072,  1073,    -1,   765,   243,    -1,   943,
      -1,    -1,    -1,    -1,   114,   955,   113,   955,   432,  1075,
    1125,   393,  1076,   765,  1077,  1053,  1509,  1061,    -1,    -1,
     560,  1079,  1094,  1085,  1080,    -1,   363,    -1,    -1,   235,
    1082,  1509,    -1,    -1,    23,  1086,  1087,  1088,   954,  1083,
    1509,    -1,    -1,    23,  1086,   954,  1084,  1509,    -1,  1081,
      -1,  1085,  1081,    -1,    -1,  1026,    -1,    25,    -1,  1108,
      -1,    -1,  1108,    -1,    25,    -1,   252,  1092,    -1,   264,
    1093,    -1,   247,  1093,    -1,   587,    -1,    25,    -1,  1108,
      -1,  1092,    -1,  1093,     5,  1092,    -1,  1108,    -1,    25,
      -1,    -1,    -1,   647,   955,  1096,   765,  1097,  1098,   648,
      -1,  1099,    -1,  1098,  1099,    -1,    -1,   649,  1100,  1509,
      -1,    -1,   626,   955,  1101,  1509,    -1,  1105,  1103,    -1,
      -1,   692,  1106,    -1,  1107,    -1,  1104,    -1,   976,    -1,
     978,    -1,   980,    -1,   972,    -1,   974,    -1,   371,   880,
     860,    -1,    -1,    66,    -1,    66,    -1,  1109,    -1,  1111,
      -1,   191,  1111,    -1,  1111,   621,    -1,  1110,  1115,    -1,
    1110,   955,   460,  1119,   428,    -1,  1110,   955,   460,  1119,
     428,   460,  1119,   428,    -1,  1116,    -1,   955,    -1,  1112,
      -1,   955,   459,  1114,   427,    -1,   955,   459,  1114,   427,
      -1,  1108,    -1,    25,    -1,    20,    -1,   955,    -1,   955,
    1118,    -1,   955,  1118,    -1,   460,  1119,   428,    -1,   460,
    1119,   428,   460,  1119,   428,    -1,  1120,    -1,  1119,     5,
    1120,    -1,   688,    -1,  1122,    -1,  1124,    -1,  1122,   621,
    1123,    -1,  1122,   621,   955,   460,  1119,   428,    -1,  1122,
     621,   955,   460,  1119,   428,   460,  1119,   428,    -1,   955,
      -1,  1113,    -1,    20,    -1,   955,    -1,   955,  1118,    -1,
      -1,  1126,    -1,  1128,    -1,  1126,     5,  1128,    -1,  1129,
      -1,  1127,     5,  1129,    -1,   955,    -1,   955,   621,   955,
      -1,  1108,    -1,  1108,   422,  1108,    -1,    25,    -1,   961,
      -1,    26,    -1,  1131,    -1,  1130,     5,  1131,    -1,  1108,
      -1,  1108,   422,  1108,    -1,  1133,    -1,  1132,     5,  1133,
      -1,  1121,    -1,  1108,    -1,  1136,    -1,  1135,     5,  1136,
      -1,  1108,  1137,    -1,    -1,   589,    -1,   540,    -1,   955,
     460,  1119,   428,    -1,  1140,    -1,  1139,     5,  1140,    -1,
    1108,    -1,  1108,   422,  1108,    -1,   255,   951,   619,   945,
     581,  1501,   696,    -1,    -1,   619,   432,   862,     5,   862,
     393,  1143,    -1,    -1,   570,   432,   862,     5,   862,   393,
      -1,   256,   955,  1142,    -1,   955,    -1,   339,   953,  1147,
      -1,  1148,    -1,   548,   862,    -1,  1149,  1150,  1155,     8,
    1145,    -1,    -1,   619,  1151,   432,   862,     5,   862,   393,
      -1,    -1,   558,   956,    -1,    -1,   351,    -1,   218,  1450,
     267,  1484,  1154,    -1,   565,   948,    -1,   565,   948,     8,
     880,   860,    -1,    -1,   618,   578,  1444,   375,  1444,    -1,
     618,   578,  1444,     5,   375,  1444,    -1,   618,  1444,     5,
    1444,    -1,    -1,   650,    -1,   651,    -1,    91,  1484,  1157,
    1158,    -1,    -1,   618,  1484,    -1,    -1,   618,   578,  1444,
       8,  1444,    -1,   578,  1444,     8,  1444,    -1,   413,  1160,
      -1,  1161,    -1,  1160,     5,  1161,    -1,   204,   942,    -1,
     285,   942,    -1,   330,   942,    -1,   338,   942,    -1,   294,
     942,    -1,   260,   942,    -1,  1028,    -1,   440,  1029,    -1,
     451,  1029,    -1,   563,  1029,    -1,   376,  1029,    -1,   552,
    1029,    -1,   550,   943,    -1,   551,   943,    -1,   402,   692,
      -1,   666,   692,    -1,   292,    -1,   196,    -1,   152,    -1,
     129,    -1,   147,    -1,   138,    -1,  1449,   415,  1165,   548,
    1163,    -1,  1108,    -1,    25,    -1,   404,  1165,    -1,   404,
    1165,     8,  1127,    -1,    39,  1163,    -1,   956,    -1,    -1,
     463,  1175,   691,   597,  1170,  1108,  1168,   954,   691,  1167,
    1171,    -1,    -1,   669,    26,    -1,   463,  1175,   691,   345,
    1108,    -1,    -1,   537,    -1,    -1,  1172,   283,    -1,  1173,
      -1,  1172,  1173,    -1,    -1,  1024,  1174,  1509,    -1,   861,
      -1,    -1,   605,   948,  1177,  1178,    -1,    -1,   548,  1179,
      -1,  1180,    -1,  1179,     5,  1180,    -1,  1436,    -1,   484,
      -1,   221,  1183,    89,    -1,   221,  1183,   627,  1182,    -1,
     221,  1183,    88,  1182,    -1,   221,  1183,    -1,    25,    -1,
     960,    -1,   955,    -1,    -1,   480,    -1,   146,  1183,  1184,
     432,   880,  1066,   393,    -1,   194,  1183,    -1,    68,  1183,
      -1,  1219,  1227,    -1,   448,    62,    -1,   448,  1190,    -1,
    1191,    -1,  1190,  1191,    -1,    -1,   134,  1192,  1509,    -1,
      -1,   200,  1193,  1509,    -1,    -1,   229,  1194,  1509,    -1,
      -1,   217,  1195,  1509,    -1,    -1,   254,  1196,  1509,    -1,
      -1,   202,  1108,  1197,  1509,    -1,    -1,   225,  1108,  1198,
    1509,    -1,  1209,    -1,  1211,    -1,  1210,    -1,  1200,    -1,
    1236,    -1,  1203,    -1,    -1,   562,   862,  1201,   483,    -1,
      -1,   483,    -1,    -1,   571,    26,  1204,  1202,    -1,   159,
      -1,   630,  1223,    -1,   162,  1223,    -1,   161,  1223,    -1,
      -1,  1206,    -1,  1207,    -1,  1206,  1207,    -1,  1216,  1208,
      -1,    -1,   619,  1223,    -1,   520,  1205,  1215,    -1,   519,
    1444,  1215,    -1,   518,  1214,  1213,  1212,  1215,    -1,    -1,
     153,   855,    -1,   153,   855,     5,   855,    -1,   614,    -1,
     615,    -1,   616,    -1,   617,    -1,  1108,    -1,    -1,   523,
      -1,  1217,    -1,  1216,     5,  1217,    -1,   862,  1250,    -1,
     610,   432,   855,   393,  1235,    -1,    65,  1235,    -1,   497,
     432,    20,   393,  1235,    -1,   414,   432,    20,   393,  1235,
      -1,   389,   432,   855,   393,  1235,    -1,   590,   432,   855,
     393,  1235,    -1,   603,   432,   855,   393,  1235,    -1,   602,
     432,   855,   393,  1235,    -1,    -1,   462,  1220,    -1,  1221,
      -1,  1220,  1221,    -1,   228,    26,    -1,   219,    26,    -1,
     302,    26,    -1,   185,    26,    -1,   257,    26,    -1,   176,
      -1,   344,    25,    -1,   344,  1108,    -1,   177,    25,    -1,
     160,    25,    -1,  1226,    -1,  1222,  1226,    -1,  1224,   109,
      -1,  1224,   111,    -1,  1224,   110,    -1,  1224,    -1,   961,
      -1,    26,    -1,    -1,   462,  1222,    -1,   228,  1223,    -1,
     219,  1223,    -1,   302,  1223,    -1,   185,  1223,    -1,   257,
    1223,    -1,   258,  1223,    -1,   629,    25,    -1,   630,  1223,
      -1,   634,    -1,   631,    -1,   632,    -1,   633,    -1,   638,
      -1,   635,    -1,   636,    -1,   637,    -1,    77,  1223,    -1,
      78,  1223,    -1,    79,  1223,    -1,   344,    25,    -1,   177,
      25,    -1,   401,    -1,    74,    -1,    75,    -1,    -1,   515,
     620,  1135,    -1,   135,  1135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   466,  1229,   955,   432,  1230,  1125,   393,  1231,
     765,  1232,  1188,  1233,  1189,  1234,   240,    -1,    -1,   527,
     855,    -1,   517,  1237,    -1,    -1,  1163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,  1239,   955,   432,  1240,  1125,
     393,  1241,   765,  1242,  1245,  1243,  1189,  1244,   240,    -1,
    1225,  1227,    -1,    -1,    -1,    -1,   155,   432,    25,     5,
    1247,   718,  1248,   393,  1249,   716,    -1,    -1,   385,    -1,
     385,   219,    26,    -1,   385,   219,  1108,    -1,   608,   862,
      -1,   608,   862,   345,  1108,    -1,   608,   862,   163,    -1,
     608,   862,   579,    -1,   608,   862,   546,    -1,  1253,    -1,
     173,    -1,   324,    -1,   282,    -1,  1260,    -1,  1255,    -1,
      -1,    -1,   207,  1256,  1393,   432,  1257,  1264,   393,    -1,
      -1,    -1,   132,  1258,  1393,   432,  1259,  1264,   393,  1261,
      -1,   104,  1262,   393,    -1,    55,   956,    -1,    -1,   269,
      -1,  1263,    -1,  1262,     5,  1263,    -1,   955,   589,    -1,
     955,   540,    -1,   955,    -1,  1265,    -1,  1264,     5,  1265,
      -1,  1346,    -1,  1344,    -1,   121,   955,    -1,   180,    -1,
      46,   955,  1268,    -1,  1269,    -1,  1268,     5,  1269,    -1,
    1270,    -1,  1273,    -1,  1276,    -1,  1281,    -1,  1282,    -1,
    1280,    -1,  1279,    -1,   586,  1271,    -1,   586,   432,  1272,
     393,    -1,  1265,    -1,  1265,   665,   955,    -1,  1271,    -1,
    1272,     5,  1271,    -1,   543,  1275,    -1,   543,   432,  1274,
     393,    -1,  1275,    -1,  1274,     5,  1275,    -1,   955,    -1,
     456,  1278,    -1,   456,   432,  1277,   393,    -1,  1278,    -1,
    1277,     5,  1278,    -1,  1265,    -1,    86,    -1,    87,    -1,
      85,    26,    -1,    57,  1350,    -1,    57,   432,  1283,   393,
      -1,    58,  1284,    -1,    58,   432,  1283,   393,    -1,  1350,
      -1,  1283,     5,  1350,    -1,   955,    -1,   266,    -1,   232,
      -1,   165,  1287,    -1,   142,    -1,   130,    -1,   120,    -1,
     118,    -1,   122,    -1,   179,  1450,    -1,   231,  1286,   461,
    1444,   627,  1444,    -1,   299,   948,   461,  1444,   627,  1444,
      -1,    -1,  1450,    -1,    -1,   862,    -1,   524,   862,    -1,
     230,    -1,    -1,   249,  1291,  1393,  1294,  1292,    -1,    -1,
     480,  1293,   432,  1296,   393,    -1,  1430,    -1,    -1,   432,
    1295,   393,    -1,  1396,    -1,  1295,     5,  1396,    -1,  1297,
      -1,  1296,     5,  1297,    -1,  1436,    -1,   484,    -1,    -1,
      -1,   501,  1299,  1302,  1300,  1303,    -1,   956,    -1,  1307,
     949,    -1,   949,    -1,    -1,    -1,   555,  1304,  1130,    -1,
      -1,    -1,   555,  1306,  1130,    -1,   502,    -1,   556,    -1,
     563,    -1,   376,    -1,   342,    -1,   397,    -1,   379,   862,
      -1,   351,   862,    -1,   238,  1393,   150,   949,    -1,   238,
    1393,  1366,    -1,   515,   620,  1311,    -1,  1312,    -1,  1311,
       5,  1312,    -1,  1313,  1314,    -1,    26,    -1,  1396,    -1,
      -1,   589,    -1,   540,    -1,   277,    -1,   310,    -1,    -1,
     327,    -1,   357,  1319,  1317,    -1,  1484,    -1,    25,    -1,
      -1,  1449,  1321,  1322,    -1,  1351,    -1,  1355,    -1,  1316,
      -1,  1451,    -1,  1315,    -1,  1308,    -1,  1309,    -1,  1298,
      -1,  1290,    -1,  1289,    -1,  1420,    -1,  1468,    -1,   506,
    1325,   626,  1393,   627,  1330,  1324,    -1,    -1,   141,    -1,
     168,    -1,  1326,    -1,  1327,    -1,  1326,     5,  1327,    -1,
     472,    -1,   451,    -1,   440,    -1,   479,  1328,    -1,    -1,
     432,  1329,   393,    -1,  1396,    -1,  1329,     5,  1396,    -1,
    1331,    -1,  1330,     5,  1331,    -1,   464,    -1,  1394,    -1,
     236,  1393,  1333,   618,  1430,  1335,    -1,    -1,   432,  1334,
     393,    -1,  1396,    -1,  1334,     5,  1396,    -1,    -1,   140,
      -1,   493,   432,  1369,   393,    -1,   246,   432,  1339,   393,
    1338,    -1,   297,  1340,    -1,  1341,    -1,  1393,    -1,  1393,
     432,  1341,   393,    -1,  1396,    -1,  1341,     5,  1396,    -1,
     477,   432,  1343,   393,    -1,   259,   432,  1343,   393,    -1,
    1396,    -1,  1343,     5,  1396,    -1,  1342,    -1,  1337,    -1,
    1336,    -1,   401,  1399,    -1,   208,    -1,   955,  1385,  1347,
    1348,    -1,    -1,  1345,    -1,    -1,  1349,    -1,  1350,    -1,
    1349,  1350,    -1,   374,    -1,   158,    -1,   477,    -1,  1338,
      -1,   493,   432,  1369,   393,    -1,   119,  1352,  1354,    -1,
    1353,    -1,  1394,    -1,  1355,    -1,  1354,  1355,    -1,  1332,
      -1,  1323,    -1,   449,  1369,    -1,   369,  1358,    -1,  1435,
      -1,  1358,     5,  1435,    -1,   527,  1369,    -1,   548,  1361,
      -1,  1362,    -1,  1361,     5,  1362,    -1,  1363,    -1,   516,
    1363,    -1,   516,   432,  1364,   393,    -1,  1393,    -1,  1393,
    1398,    -1,  1362,    -1,  1364,     5,  1362,    -1,  1360,  1366,
    1367,  1368,    -1,    -1,  1359,    -1,    -1,  1357,    -1,    -1,
    1356,    -1,  1370,    -1,  1369,     6,  1370,    -1,  1371,    -1,
    1370,     7,  1371,    -1,  1372,    -1,     9,  1372,    -1,  1383,
      -1,   432,  1369,   393,    -1,   444,  1431,    -1,   295,  1431,
      -1,    -1,   443,  1376,    -1,  1437,    -1,  1440,    -1,  1436,
     624,   432,  1378,   393,    -1,  1436,   624,  1431,    -1,  1436,
     430,   432,  1378,   393,    -1,  1436,   430,  1431,    -1,  1379,
      -1,  1378,     5,  1379,    -1,  1488,    -1,  1399,    -1,    -1,
       9,    -1,  1436,  1380,   388,    -1,  1436,  1380,   250,    -1,
    1436,  1382,  1436,    -1,  1436,  1380,   390,  1436,     7,  1436,
      -1,  1436,   558,  1375,  1374,    -1,  1436,   372,  1375,  1374,
      -1,  1436,   679,  1375,  1374,    -1,  1436,   373,  1375,  1374,
      -1,  1436,  1380,    10,  1375,  1374,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   253,    -1,    10,    -1,   678,
      -1,    16,    -1,    15,    -1,  1381,    -1,  1377,    -1,  1373,
      -1,    -1,   587,    -1,   360,    -1,   477,    -1,  1386,    -1,
    1387,    -1,  1389,    -1,   537,    -1,   537,   432,  1390,   393,
      -1,   412,   432,  1391,  1388,   393,    -1,   473,    -1,   399,
     432,  1391,  1388,   393,    -1,   513,   432,  1391,  1388,   393,
      -1,   539,    -1,   409,    -1,   381,    -1,   358,  1406,   627,
    1407,    -1,   358,    -1,   370,  1406,   627,  1407,    -1,   370,
      -1,   370,  1406,   432,    26,   393,   627,  1407,    -1,   576,
      -1,   534,    -1,   425,    -1,   425,   432,    26,   393,    -1,
     425,   432,    26,     5,    26,   393,    -1,    -1,     5,  1392,
      -1,   503,   432,  1391,   393,    -1,   567,    -1,   300,    -1,
     503,    -1,    64,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   621,   955,    -1,    25,    -1,   955,    -1,   955,   591,
     955,    -1,   955,    -1,    -1,   460,    26,   428,    -1,   460,
      26,     5,    26,   428,    -1,  1397,    -1,   613,  1397,    -1,
     955,  1395,    -1,  1393,   621,   955,  1395,    -1,  1393,   621,
      20,    -1,   955,    -1,    25,    -1,   412,    -1,   961,    -1,
      26,    -1,  1401,    -1,   397,  1403,    -1,   397,  1402,    -1,
      -1,  1406,   627,  1407,    -1,    -1,  1404,   627,  1404,    -1,
     583,    -1,   514,    -1,   592,    -1,   554,    -1,   455,    -1,
     471,    -1,   367,    -1,   367,   432,    26,   393,    -1,   583,
      -1,   514,    -1,   592,    -1,   554,    -1,   455,    -1,   471,
      -1,   367,    -1,   367,   432,    26,   393,    -1,   583,    -1,
     514,    -1,   592,    -1,   554,    -1,   455,    -1,   471,    -1,
     367,    -1,   583,    -1,   514,    -1,   592,    -1,   554,    -1,
     455,    -1,   471,    -1,   367,    -1,   955,    -1,    25,    -1,
    1449,   504,   949,    -1,    -1,  1449,   400,  1301,   438,   597,
    1418,  1411,  1415,    -1,    -1,  1449,   400,  1301,   438,   101,
     597,  1419,  1412,  1415,    -1,    -1,  1449,   400,  1301,   136,
    1419,  1413,  1415,    -1,    -1,  1449,   400,  1301,   137,   101,
     597,  1419,  1414,  1415,    -1,    -1,   289,    -1,   288,  1416,
      -1,  1417,    -1,  1416,     5,  1417,    -1,   955,    -1,   955,
     621,   955,    -1,    25,   621,   955,   621,   955,    -1,  1419,
      -1,  1290,    -1,  1165,    -1,  1421,    -1,  1421,  1415,    -1,
      -1,    -1,   472,  1432,  1422,  1433,  1423,  1429,  1365,  1427,
      -1,   472,  1432,  1433,  1365,  1427,    -1,  1426,    -1,  1444,
      -1,   472,  1432,  1433,  1429,  1365,  1427,    -1,    -1,   526,
    1384,  1425,    -1,  1310,    -1,   332,  1428,  1261,    -1,  1310,
     332,  1428,  1261,    -1,   955,    -1,    -1,   555,  1130,    -1,
     472,  1432,  1433,  1365,    -1,   432,   472,  1432,  1433,  1365,
     393,    -1,    -1,   587,    -1,   360,    -1,   477,    -1,  1434,
      -1,  1433,     5,  1434,    -1,  1436,    -1,  1436,   955,    -1,
    1436,    -1,  1437,    -1,    19,  1437,    -1,    18,  1437,    -1,
    1438,    -1,  1488,    -1,  1431,    -1,   613,   955,    -1,   613,
     955,   621,   955,    -1,  1437,    21,  1436,    -1,  1437,  1458,
      -1,  1437,    20,  1436,    -1,  1437,    18,  1436,    -1,  1437,
      19,  1436,    -1,  1399,    -1,   485,    -1,   429,    -1,   578,
      -1,    20,    -1,    65,    -1,   590,   432,  1384,  1436,   393,
      -1,   602,   432,  1384,  1436,   393,    -1,   603,   432,  1384,
    1436,   393,    -1,   610,   432,  1384,  1436,   393,    -1,   497,
     432,  1384,  1436,   393,    -1,   955,   432,  1439,   393,    -1,
     539,   432,  1439,   393,    -1,   432,  1436,   393,    -1,   445,
     432,  1459,   393,    -1,  1436,    -1,  1439,     5,  1436,    -1,
    1399,    -1,  1449,   347,  1448,  1443,  1425,    -1,  1449,   336,
    1448,  1443,   249,  1393,  1445,    -1,  1449,   336,  1448,  1443,
    1108,    -1,    -1,   322,  1444,    -1,    25,    -1,  1108,    -1,
      -1,   432,  1446,   393,    -1,  1447,    -1,  1446,     5,  1447,
      -1,   955,    -1,    25,    -1,  1108,    -1,    -1,   268,  1450,
     597,    -1,   956,    -1,  1456,    -1,  1455,    -1,  1452,    -1,
     317,  1453,   627,  1453,    -1,   298,  1453,   621,  1454,   627,
    1454,    -1,   955,    -1,   955,    -1,   222,   802,    -1,   293,
     802,  1457,    -1,   272,    -1,   175,    -1,    93,    -1,    94,
      -1,    95,    -1,    96,    -1,    97,    -1,    98,    -1,   397,
       5,  1406,   627,  1407,    -1,  1488,     5,  1406,   627,  1407,
      -1,   397,  1406,   627,  1407,    -1,    -1,   609,  1461,  1462,
     190,    -1,  1463,    -1,  1462,  1463,    -1,    33,    -1,  1464,
      -1,  1466,    -1,   351,    -1,   305,    -1,   224,    -1,   586,
      -1,   482,    -1,   587,    -1,   487,    -1,   531,    -1,   588,
      -1,   115,    -1,   488,    -1,   618,    -1,   589,    -1,   318,
      -1,   489,    -1,   319,    -1,   619,    -1,   613,    -1,   275,
      -1,   490,    -1,   184,    -1,   389,    -1,   590,    -1,   665,
      -1,   390,    -1,   491,    -1,   492,    -1,   532,    -1,   533,
      -1,   433,    -1,   434,    -1,   353,    -1,   652,    -1,   620,
      -1,   534,    -1,   391,    -1,   536,    -1,   530,    -1,   537,
      -1,   320,    -1,   493,    -1,   494,    -1,   392,    -1,   495,
      -1,   393,    -1,   428,    -1,   496,    -1,   591,    -1,   435,
      -1,   394,    -1,     5,    -1,    23,    -1,   395,    -1,   436,
      -1,   396,    -1,   355,    -1,   354,    -1,   321,    -1,   356,
      -1,   497,    -1,   437,    -1,   397,    -1,   438,    -1,   538,
      -1,   357,    -1,   539,    -1,   358,    -1,   592,    -1,   593,
      -1,   398,    -1,   594,    -1,   399,    -1,   400,    -1,   401,
      -1,   359,    -1,   498,    -1,   439,    -1,   440,    -1,   322,
      -1,   540,    -1,   281,    -1,   595,    -1,   656,    -1,   402,
      -1,   360,    -1,    21,    -1,   621,    -1,   441,    -1,   323,
      -1,   543,    -1,    63,    -1,   544,    -1,   659,    -1,   403,
      -1,    14,    -1,   499,    -1,   443,    -1,   500,    -1,   327,
      -1,   545,    -1,   404,    -1,   444,    -1,   546,    -1,   445,
      -1,   446,    -1,   366,    -1,   535,    -1,   501,    -1,   100,
      -1,   193,    -1,   447,    -1,   502,    -1,   596,    -1,   503,
      -1,   504,    -1,   597,    -1,   405,    -1,   406,    -1,   448,
      -1,   639,    -1,    92,    -1,   105,    -1,   505,    -1,   367,
      -1,   547,    -1,   548,    -1,   368,    -1,   290,    -1,   407,
      -1,   622,    -1,   549,    -1,   506,    -1,    13,    -1,   507,
      -1,   508,    -1,   449,    -1,   450,    -1,   552,    -1,   553,
      -1,   554,    -1,   661,    -1,    72,    -1,   623,    -1,   624,
      -1,   111,    -1,   509,    -1,   408,    -1,   291,    -1,   666,
      -1,   451,    -1,   409,    -1,   331,    -1,   370,    -1,   668,
      -1,   333,    -1,   598,    -1,   541,    -1,   660,    -1,   510,
      -1,   483,    -1,   371,    -1,   599,    -1,   628,    -1,   410,
      -1,     7,    -1,   429,    -1,   584,    -1,   484,    -1,     6,
      -1,   485,    -1,     8,    -1,   556,    -1,   557,    -1,    12,
      -1,   600,    -1,   558,    -1,   512,    -1,   452,    -1,   601,
      -1,   411,    -1,   559,    -1,   453,    -1,    10,    -1,    45,
      -1,   454,    -1,   560,    -1,   647,    -1,   662,    -1,    19,
      -1,   455,    -1,   110,    -1,    22,    -1,   561,    -1,   456,
      -1,   513,    -1,   514,    -1,    20,    -1,   562,    -1,   563,
      -1,   311,    -1,   564,    -1,   457,    -1,     9,    -1,   412,
      -1,   625,    -1,   670,    -1,   626,    -1,   565,    -1,   432,
      -1,   460,    -1,   461,    -1,   413,    -1,   515,    -1,   340,
      -1,   516,    -1,   462,    -1,   604,    -1,   375,    -1,   517,
      -1,   155,    -1,   106,    -1,   414,    -1,    18,    -1,   109,
      -1,   341,    -1,   415,    -1,   112,    -1,   376,    -1,   312,
      -1,   520,    -1,   342,    -1,   343,    -1,   416,    -1,   463,
      -1,   464,    -1,   605,    -1,   566,    -1,   377,    -1,   567,
      -1,   465,    -1,   417,    -1,   606,    -1,   297,    -1,   378,
      -1,   379,    -1,   466,    -1,   380,    -1,   178,    -1,   345,
      -1,   418,    -1,   467,    -1,   521,    -1,   262,    -1,   607,
      -1,   568,    -1,   608,    -1,   468,    -1,   470,    -1,   471,
      -1,   419,    -1,   472,    -1,   523,    -1,   473,    -1,   420,
      -1,   475,    -1,   569,    -1,   486,    -1,   570,    -1,   571,
      -1,   524,    -1,   300,    -1,   381,    -1,   572,    -1,   476,
      -1,   609,    -1,   301,    -1,    90,    -1,   573,    -1,   574,
      -1,   610,    -1,   421,    -1,   542,    -1,   575,    -1,   116,
      -1,   576,    -1,   577,    -1,   422,    -1,   669,    -1,   627,
      -1,   611,    -1,   423,    -1,   525,    -1,   199,    -1,   346,
      -1,   526,    -1,   477,    -1,   478,    -1,   479,    -1,   424,
      -1,   612,    -1,   578,    -1,   382,    -1,   480,    -1,   425,
      -1,   350,    -1,   579,    -1,   426,    -1,   580,    -1,   383,
      -1,   527,    -1,   528,    -1,   529,    -1,   581,    -1,   385,
      -1,   582,    -1,   602,    -1,   603,    -1,   585,    -1,   583,
      -1,   481,    -1,    -1,   191,  1465,  1488,    -1,    -1,   555,
    1467,  1130,    -1,    -1,    -1,   479,  1393,  1469,  1472,  1470,
    1471,    -1,    -1,   150,   949,    -1,   527,  1369,    -1,    53,
    1476,   393,    14,   432,  1477,   393,    -1,    49,  1477,   393,
      -1,    50,  1477,   393,    -1,   585,  1473,    -1,    52,  1477,
      -1,    51,  1477,    -1,  1475,    -1,  1473,     5,  1475,    -1,
    1396,    -1,  1474,    14,  1478,    -1,  1474,    -1,  1476,     5,
    1474,    -1,  1478,    -1,  1477,     5,  1478,    -1,   484,    -1,
    1479,    -1,  1480,    -1,    19,  1480,    -1,    18,  1480,    -1,
    1482,    -1,  1431,    -1,   613,   955,    -1,   613,   955,   621,
     955,    -1,  1481,    -1,  1399,    -1,   485,    -1,   429,    -1,
     578,    -1,    65,    -1,  1480,    21,  1479,    -1,  1480,  1458,
      -1,  1480,    20,  1479,    -1,  1480,    18,  1479,    -1,  1480,
      19,  1479,    -1,   590,   432,  1384,  1479,   393,    -1,   602,
     432,  1384,  1479,   393,    -1,   603,   432,  1384,  1479,   393,
      -1,   610,   432,  1384,  1479,   393,    -1,   497,   432,  1384,
    1479,   393,    -1,   955,   432,  1483,   393,    -1,   539,   432,
    1483,   393,    -1,   432,  1479,   393,    -1,   445,   432,  1459,
     393,    -1,  1488,    -1,  1479,    -1,  1483,     5,  1479,    -1,
    1485,    -1,   191,  1486,    -1,  1486,    -1,  1117,    -1,   955,
      -1,  1486,   621,  1487,    -1,    25,   621,  1486,   621,  1487,
      -1,    20,    -1,  1138,    -1,   955,    -1,  1485,    -1,  1485,
     422,  1485,    -1,   127,  1490,    -1,   131,  1490,    -1,   126,
    1490,    -1,    47,    -1,   166,  1490,    -1,   124,  1490,    -1,
      48,    -1,   149,  1490,    -1,   148,  1490,    -1,   123,  1490,
      -1,   356,    -1,   622,   627,  1491,    -1,   549,  1491,    -1,
     574,    -1,   535,  1492,    -1,   955,    -1,   591,   955,    -1,
     955,    -1,    -1,    -1,   528,  1494,   862,  1495,  1509,   326,
      -1,    -1,   660,  1499,    -1,    -1,   663,    -1,   182,    -1,
     278,   950,    -1,    70,   950,    -1,   308,    -1,   307,    -1,
     309,   952,  1496,  1497,    -1,   494,  1499,  1497,    -1,   947,
      -1,  1499,     5,   947,    -1,   103,    -1,   133,   950,    -1,
     862,   568,     5,   862,   394,    -1,   510,   862,    -1,   265,
     950,    -1,   102,  1504,     8,  1505,  1503,    -1,    -1,   548,
     862,    -1,   955,    -1,   955,    -1,   248,   950,    -1,   251,
     950,   627,   862,     5,   862,    -1,   251,   950,   620,   862,
       5,   862,    -1,    27,    -1,    -1,  1511,    -1,  1512,  1215,
      -1,  1510,    -1,  1511,  1510,    -1,    -1,  1513,  1514,    -1,
     681,    -1,   682,    -1,   683,    -1,   684,    -1,   701,    -1,
     723,    -1,   737,    -1,   738,    -1,   744,    -1,   745,    -1,
     764,    -1,   834,    -1,   835,    -1,   836,    -1,   837,    -1,
     848,    -1,   849,    -1,   850,    -1,   851,    -1,   852,    -1,
     853,    -1,   854,    -1,   906,    -1,   910,    -1,   941,    -1,
     962,    -1,   963,    -1,   966,    -1,   967,    -1,   968,    -1,
     969,    -1,   982,    -1,   991,    -1,  1012,    -1,  1013,    -1,
    1015,    -1,  1019,    -1,  1034,    -1,  1035,    -1,  1039,    -1,
    1040,    -1,  1041,    -1,  1042,    -1,  1050,    -1,  1065,    -1,
    1078,    -1,  1089,    -1,  1090,    -1,  1091,    -1,  1102,    -1,
    1141,    -1,  1144,    -1,  1146,    -1,  1152,    -1,  1153,    -1,
    1156,    -1,  1159,    -1,  1162,    -1,  1164,    -1,  1166,    -1,
    1169,    -1,  1176,    -1,  1181,    -1,  1185,    -1,  1186,    -1,
    1187,    -1,  1199,    -1,  1251,    -1,  1252,    -1,  1254,    -1,
    1266,    -1,  1267,    -1,  1285,    -1,  1288,    -1,  1318,    -1,
    1320,    -1,  1409,    -1,  1410,    -1,  1441,    -1,  1442,    -1,
    1460,    -1,  1489,    -1,  1493,    -1,  1498,    -1,  1500,    -1,
    1502,    -1,  1506,    -1,  1507,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   943,   943,   946,   949,   955,   961,   968,   972,   972,
     978,  1001,  1002,  1003,  1004,  1005,  1016,  1025,  1026,  1027,
    1028,  1029,  1034,  1035,  1046,  1049,  1052,  1052,  1056,  1059,
    1060,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1085,  1086,
    1089,  1089,  1104,  1105,  1108,  1114,  1116,  1127,  1129,  1131,
    1133,  1137,  1139,  1201,  1205,  1209,  1209,  1219,  1223,  1226,
    1227,  1234,  1240,  1234,  1253,  1258,  1262,  1253,  1274,  1278,
    1274,  1286,  1291,  1286,  1310,  1317,  1321,  1309,  1347,  1347,
    1351,  1352,  1353,  1358,  1361,  1366,  1370,  1378,  1381,  1381,
    1387,  1391,  1406,  1404,  1422,  1422,  1437,  1437,  1440,  1440,
    1444,  1447,  1447,  1447,  1454,  1455,  1454,  1462,  1462,  1473,
    1473,  1492,  1495,  1498,  1501,  1504,  1507,  1520,  1525,  1525,
    1526,  1526,  1529,  1534,  1534,  1538,  1548,  1562,  1566,  1561,
    1576,  1582,  1590,  1591,  1594,  1594,  1597,  1601,  1606,  1613,
    1613,  1617,  1617,  1624,  1624,  1629,  1629,  1634,  1634,  1639,
    1639,  1652,  1653,  1661,  1662,  1679,  1682,  1685,  1688,  1691,
    1694,  1700,  1711,  1716,  1729,  1733,  1748,  1749,  1753,  1753,
    1757,  1757,  1757,  1758,  1759,  1764,  1764,  1767,  1767,  1776,
    1777,  1778,  1781,  1785,  1786,  1786,  1803,  1803,  1803,  1803,
    1807,  1814,  1815,  1818,  1818,  1822,  1823,  1824,  1825,  1830,
    1830,  1836,  1836,  1845,  1842,  1858,  1858,  1860,  1860,  1862,
    1864,  1866,  1868,  1871,  1875,  1875,  1876,  1876,  1880,  1880,
    1892,  1892,  1897,  1901,  1903,  1904,  1907,  1907,  1907,  1911,
    1912,  1913,  1914,  1921,  1922,  1923,  1924,  1927,  1928,  1929,
    1930,  1934,  1939,  1944,  1948,  1951,  1955,  1956,  1957,  1958,
    1959,  1960,  1961,  1962,  1965,  1966,  1967,  1999,  2003,  2005,
    2007,  2007,  2014,  2018,  2018,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2034,  2034,  2037,  2039,  2045,  2047,  2053,  2061,
    2061,  2064,  2065,  2066,  2067,  2068,  2069,  2070,  2076,  2079,
    2079,  2092,  2092,  2099,  2100,  2101,  2103,  2104,  2106,  2108,
    2109,  2110,  2111,  2116,  2122,  2128,  2129,  2131,  2133,  2134,
    2135,  2136,  2137,  2138,  2141,  2142,  2149,  2157,  2157,  2165,
    2162,  2177,  2177,  2179,  2179,  2187,  2187,  2190,  2193,  2194,
    2199,  2211,  2215,  2218,  2221,  2222,  2223,  2224,  2225,  2230,
    2237,  2243,  2248,  2252,  2248,  2263,  2265,  2270,  2275,  2275,
    2279,  2279,  2282,  2282,  2288,  2288,  2294,  2294,  2304,  2323,
    2329,  2353,  2356,  2370,  2372,  2374,  2376,  2378,  2380,  2382,
    2388,  2390,  2394,  2396,  2398,  2400,  2402,  2404,  2406,  2412,
    2427,  2430,  2443,  2444,  2445,  2446,  2447,  2451,  2452,  2453,
    2457,  2462,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
    2477,  2478,  2479,  2486,  2486,  2491,  2491,  2494,  2500,  2508,
    2514,  2524,  2525,  2533,  2540,  2544,  2554,  2558,  2563,  2568,
    2570,  2580,  2593,  2601,  2614,  2619,  2625,  2630,  2635,  2636,
    2642,  2713,  2719,  2724,  2732,  2732,  2747,  2751,  2758,  2761,
    2769,  2780,  2790,  2796,  2805,  2810,  2818,  2821,  2824,  2829,
    2836,  2841,  2846,  2851,  2861,  2869,  2877,  2882,  2886,  2891,
    2895,  2899,  2906,  2909,  2912,  2916,  2920,  2924,  2928,  2936,
    2946,  2951,  2944,  2967,  2972,  2967,  2989,  2989,  2989,  2992,
    2992,  2992,  2996,  2996,  2996,  3000,  3000,  3000,  3004,  3010,
    3016,  3022,  3032,  3032,  3036,  3040,  3041,  3052,  3053,  3059,
    3069,  3079,  3089,  3090,  3093,  3098,  3104,  3108,  3112,  3115,
    3121,  3124,  3127,  3144,  3147,  3153,  3154,  3155,  3159,  3160,
    3161,  3162,  3163,  3165,  3166,  3167,  3169,  3170,  3174,  3175,
    3180,  3181,  3193,  3197,  3192,  3205,  3208,  3222,  3226,  3232,
    3221,  3245,  3246,  3258,  3264,  3258,  3278,  3278,  3280,  3281,
    3285,  3285,  3289,  3289,  3294,  3294,  3301,  3302,  3306,  3306,
    3310,  3310,  3315,  3315,  3322,  3326,  3327,  3328,  3333,  3333,
    3336,  3336,  3340,  3340,  3344,  3344,  3348,  3348,  3353,  3353,
    3358,  3358,  3363,  3363,  3368,  3368,  3384,  3401,  3402,  3403,
    3404,  3405,  3406,  3407,  3410,  3410,  3413,  3415,  3418,  3421,
    3423,  3424,  3425,  3427,  3429,  3431,  3433,  3437,  3444,  3446,
    3452,  3457,  3462,  3467,  3467,  3470,  3476,  3481,  3484,  3491,
    3491,  3493,  3494,  3496,  3498,  3500,  3502,  3506,  3515,  3515,
    3577,  3589,  3596,  3596,  3600,  3605,  3611,  3615,  3619,  3625,
    3629,  3633,  3639,  3639,  3647,  3648,  3652,  3652,  3656,  3657,
    3660,  3663,  3663,  3666,  3668,  3668,  3671,  3673,  3673,  3674,
    3676,  3676,  3685,  3692,  3683,  3714,  3714,  3714,  3717,  3719,
    3717,  3726,  3729,  3735,  3746,  3746,  3750,  3756,  3756,  3760,
    3761,  3772,  3773,  3775,  3777,  3782,  3782,  3786,  3785,  3792,
    3791,  3797,  3797,  3802,  3802,  3808,  3808,  3813,  3813,  3818,
    3818,  3823,  3823,  3826,  3826,  3829,  3829,  3832,  3832,  3874,
    3875,  3883,  3884,  3893,  3898,  3903,  3904,  3905,  3909,  3908,
    3919,  3924,  3929,  3929,  3945,  3951,  3952,  3953,  3954,  3957,
    3957,  3960,  3967,  3968,  3969,  3970,  3971,  3972,  3973,  3974,
    3975,  3980,  3980,  3982,  3985,  3985,  3987,  3991,  3994,  3995,
    3998,  3998,  4003,  4006,  4007,  4008,  4009,  4010,  4011,  4012,
    4013,  4014,  4015,  4016,  4017,  4018,  4019,  4020,  4021,  4022,
    4023,  4027,  4045,  4045,  4045,  4072,  4083,  4090,  4096,  4102,
    4108,  4119,  4142,  4141,  4158,  4158,  4162,  4163,  4171,  4172,
    4173,  4174,  4181,  4182,  4184,  4185,  4189,  4194,  4195,  4196,
    4197,  4198,  4199,  4200,  4201,  4202,  4203,  4204,  4207,  4207,
    4209,  4209,  4209,  4211,  4215,  4215,  4224,  4229,  4245,  4251,
    4223,  4265,  4279,  4289,  4278,  4302,  4309,  4309,  4314,  4320,
    4328,  4333,  4334,  4337,  4337,  4337,  4340,  4340,  4348,  4354,
    4368,  4372,  4385,  4367,  4403,  4403,  4417,  4428,  4427,  4439,
    4435,  4452,  4449,  4462,  4462,  4464,  4465,  4467,  4468,  4471,
    4472,  4473,  4475,  4480,  4485,  4491,  4493,  4494,  4497,  4498,
    4501,  4503,  4512,  4518,  4512,  4529,  4530,  4534,  4534,  4544,
    4544,  4556,  4559,  4562,  4565,  4569,  4573,  4574,  4575,  4576,
    4577,  4581,  4586,  4586,  4589,  4615,  4674,  4674,  4677,  4681,
    4685,  4728,  4770,  4771,  4772,  4775,  4789,  4801,  4801,  4806,
    4807,  4813,  4873,  4930,  4935,  4942,  4947,  4955,  4961,  4995,
    4998,  4999,  5040,  5083,  5084,  5088,  5089,  5093,  5146,  5150,
    5153,  5159,  5170,  5177,  5185,  5185,  5188,  5189,  5190,  5191,
    5192,  5195,  5198,  5204,  5207,  5211,  5215,  5222,  5227,  5234,
    5237,  5243,  5245,  5245,  5245,  5249,  5269,  5276,  5283,  5286,
    5300,  5307,  5308,  5311,  5312,  5316,  5322,  5327,  5333,  5334,
    5339,  5343,  5343,  5347,  5348,  5351,  5352,  5356,  5364,  5367,
    5373,  5374,  5376,  5378,  5382,  5382,  5383,  5388,  5396,  5397,
    5402,  5403,  5405,  5418,  5420,  5421,  5423,  5426,  5429,  5432,
    5436,  5439,  5442,  5446,  5450,  5454,  5457,  5461,  5464,  5465,
    5466,  5469,  5472,  5475,  5478,  5481,  5484,  5487,  5503,  5511,
    5511,  5513,  5520,  5524,  5529,  5544,  5542,  5561,  5562,  5566,
    5571,  5572,  5576,  5577,  5579,  5580,  5582,  5582,  5590,  5599,
    5599,  5609,  5610,  5613,  5614,  5617,  5621,  5635,  5640,  5645,
    5650,  5660,  5660,  5664,  5667,  5667,  5669,  5679,  5688,  5695,
    5697,  5701,  5704,  5704,  5708,  5707,  5715,  5714,  5725,  5724,
    5731,  5730,  5734,  5733,  5736,  5736,  5752,  5751,  5773,  5774,
    5775,  5776,  5777,  5778,  5781,  5781,  5787,  5787,  5790,  5790,
    5806,  5807,  5808,  5817,  5829,  5830,  5833,  5834,  5837,  5840,
    5840,  5845,  5865,  5870,  5876,  5877,  5878,  5882,  5883,  5884,
    5885,  5889,  5899,  5901,  5906,  5909,  5914,  5920,  5927,  5934,
    5943,  5950,  5957,  5964,  5971,  5980,  5980,  5982,  5982,  5985,
    5986,  5987,  5988,  5989,  5990,  5991,  5992,  5993,  5994,  5997,
    5997,  6000,  6001,  6002,  6003,  6006,  6006,  6009,  6009,  6012,
    6013,  6014,  6015,  6016,  6017,  6018,  6019,  6021,  6022,  6023,
    6024,  6026,  6027,  6028,  6029,  6031,  6032,  6033,  6034,  6035,
    6036,  6037,  6038,  6042,  6049,  6058,  6070,  6079,  6090,  6094,
    6098,  6104,  6069,  6117,  6120,  6128,  6140,  6142,  6147,  6155,
    6165,  6168,  6172,  6180,  6146,  6189,  6193,  6197,  6201,  6193,
    6211,  6212,  6213,  6214,  6219,  6221,  6224,  6228,  6231,  6238,
    6243,  6244,  6245,  6250,  6251,  6257,  6257,  6257,  6262,  6262,
    6262,  6273,  6274,  6280,  6281,  6293,  6294,  6299,  6300,  6301,
    6305,  6308,  6314,  6317,  6325,  6326,  6332,  6339,  6342,  6351,
    6354,  6357,  6360,  6363,  6366,  6369,  6376,  6379,  6386,  6389,
    6395,  6398,  6405,  6408,  6415,  6416,  6421,  6425,  6428,  6434,
    6437,  6443,  6450,  6451,  6455,  6461,  6464,  6471,  6472,  6479,
    6482,  6487,  6498,  6499,  6500,  6501,  6502,  6503,  6504,  6505,
    6506,  6509,  6512,  6518,  6518,  6524,  6524,  6535,  6548,  6558,
    6558,  6563,  6563,  6567,  6571,  6572,  6578,  6579,  6584,  6588,
    6595,  6598,  6605,  6609,  6604,  6618,  6622,  6626,  6633,  6637,
    6637,  6650,  6654,  6654,  6669,  6671,  6673,  6675,  6677,  6679,
    6681,  6683,  6689,  6699,  6706,  6711,  6712,  6716,  6718,  6719,
    6722,  6723,  6724,  6727,  6732,  6739,  6740,  6746,  6758,  6759,
    6762,  6762,  6767,  6772,  6777,  6778,  6781,  6782,  6787,  6792,
    6796,  6801,  6802,  6806,  6813,  6817,  6818,  6823,  6825,  6829,
    6830,  6834,  6835,  6836,  6837,  6841,  6842,  6847,  6848,  6853,
    6854,  6859,  6860,  6865,  6870,  6871,  6876,  6877,  6881,  6882,
    6887,  6894,  6899,  6904,  6908,  6909,  6914,  6915,  6921,  6923,
    6928,  6929,  6935,  6938,  6941,  6948,  6950,  6964,  6969,  6970,
    6973,  6975,  6982,  6985,  6991,  6995,  6999,  7003,  7006,  7013,
    7020,  7025,  7029,  7030,  7036,  7039,  7050,  7057,  7063,  7066,
    7073,  7080,  7086,  7087,  7093,  7094,  7095,  7098,  7099,  7104,
    7104,  7108,  7116,  7117,  7120,  7123,  7128,  7129,  7134,  7137,
    7143,  7146,  7152,  7155,  7161,  7164,  7171,  7172,  7201,  7202,
    7207,  7215,  7220,  7223,  7226,  7229,  7235,  7236,  7240,  7243,
    7246,  7247,  7252,  7255,  7258,  7261,  7264,  7267,  7270,  7273,
    7278,  7284,  7285,  7286,  7287,  7288,  7290,  7291,  7293,  7294,
    7299,  7302,  7306,  7312,  7313,  7314,  7315,  7327,  7328,  7329,
    7333,  7334,  7339,  7341,  7342,  7343,  7345,  7346,  7347,  7348,
    7350,  7351,  7353,  7354,  7356,  7357,  7358,  7359,  7361,  7365,
    7366,  7372,  7374,  7375,  7376,  7377,  7382,  7386,  7390,  7394,
    7395,  7399,  7400,  7410,  7419,  7420,  7421,  7425,  7428,  7433,
    7438,  7443,  7451,  7455,  7459,  7460,  7461,  7466,  7469,  7472,
    7486,  7500,  7513,  7514,  7518,  7518,  7518,  7518,  7518,  7518,
    7519,  7522,  7527,  7527,  7527,  7527,  7527,  7527,  7529,  7532,
    7538,  7538,  7538,  7538,  7538,  7538,  7538,  7539,  7539,  7539,
    7539,  7539,  7539,  7539,  7541,  7542,  7545,  7554,  7554,  7560,
    7560,  7567,  7567,  7573,  7573,  7581,  7582,  7583,  7586,  7586,
    7589,  7590,  7591,  7596,  7599,  7605,  7610,  7618,  7631,  7632,
    7629,  7650,  7660,  7663,  7668,  7680,  7683,  7687,  7690,  7691,
    7697,  7700,  7701,  7710,  7719,  7724,  7725,  7726,  7727,  7734,
    7737,  7743,  7746,  7756,  7765,  7768,  7771,  7777,  7783,  7786,
    7789,  7792,  7798,  7800,  7802,  7804,  7806,  7808,  7809,  7810,
    7811,  7812,  7813,  7814,  7816,  7818,  7820,  7822,  7824,  7826,
    7828,  7829,  7834,  7835,  7842,  7845,  7854,  7858,  7865,  7865,
    7869,  7869,  7874,  7874,  7878,  7878,  7882,  7888,  7888,  7891,
    7891,  7897,  7904,  7905,  7906,  7910,  7911,  7914,  7915,  7919,
    7925,  7935,  7936,  7944,  7945,  7946,  7947,  7948,  7949,  7953,
    7954,  7955,  7959,  7959,  7971,  7972,  7976,  7977,  7978,  7979,
    7980,  7981,  7982,  7983,  7984,  7985,  7986,  7987,  7988,  7989,
    7990,  7991,  7992,  7993,  7994,  7995,  7996,  7997,  7998,  7999,
    8000,  8001,  8002,  8003,  8004,  8005,  8006,  8007,  8008,  8009,
    8010,  8011,  8012,  8013,  8014,  8015,  8016,  8017,  8018,  8019,
    8020,  8021,  8022,  8023,  8024,  8025,  8026,  8027,  8028,  8029,
    8030,  8031,  8032,  8033,  8034,  8035,  8036,  8037,  8038,  8039,
    8040,  8041,  8042,  8043,  8044,  8045,  8046,  8047,  8048,  8049,
    8050,  8051,  8052,  8053,  8054,  8055,  8056,  8057,  8058,  8059,
    8060,  8061,  8062,  8063,  8064,  8065,  8066,  8067,  8068,  8069,
    8070,  8071,  8072,  8073,  8074,  8075,  8076,  8077,  8078,  8079,
    8080,  8081,  8082,  8083,  8084,  8085,  8086,  8087,  8088,  8089,
    8090,  8091,  8092,  8093,  8094,  8095,  8096,  8097,  8098,  8099,
    8100,  8101,  8102,  8103,  8104,  8105,  8106,  8107,  8108,  8109,
    8110,  8111,  8112,  8113,  8114,  8115,  8116,  8117,  8118,  8119,
    8120,  8121,  8122,  8123,  8124,  8125,  8126,  8127,  8128,  8129,
    8130,  8131,  8132,  8133,  8134,  8135,  8136,  8137,  8138,  8139,
    8140,  8141,  8142,  8143,  8144,  8145,  8146,  8147,  8148,  8149,
    8150,  8151,  8152,  8153,  8154,  8155,  8156,  8157,  8158,  8159,
    8160,  8161,  8162,  8163,  8164,  8165,  8166,  8167,  8168,  8169,
    8170,  8171,  8172,  8173,  8174,  8175,  8176,  8177,  8178,  8179,
    8180,  8181,  8182,  8183,  8184,  8185,  8186,  8187,  8188,  8189,
    8190,  8191,  8192,  8193,  8194,  8195,  8196,  8197,  8198,  8199,
    8200,  8201,  8202,  8203,  8204,  8205,  8206,  8207,  8208,  8209,
    8210,  8211,  8212,  8213,  8214,  8215,  8216,  8217,  8218,  8219,
    8220,  8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,  8229,
    8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,  8239,
    8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,  8249,
    8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,  8259,
    8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,  8269,
    8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,  8279,
    8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,  8289,
    8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,  8306,
    8306,  8313,  8313,  8401,  8405,  8401,  8414,  8418,  8424,  8432,
    8442,  8452,  8464,  8467,  8486,  8512,  8515,  8521,  8524,  8529,
    8532,  8540,  8548,  8561,  8564,  8572,  8575,  8578,  8586,  8590,
    8593,  8596,  8599,  8603,  8604,  8605,  8606,  8607,  8613,  8614,
    8615,  8616,  8617,  8618,  8619,  8620,  8621,  8622,  8623,  8624,
    8625,  8626,  8630,  8636,  8637,  8649,  8670,  8670,  8674,  8675,
    8676,  8677,  8681,  8682,  8683,  8688,  8714,  8765,  8767,  8769,
    8771,  8775,  8780,  8782,  8785,  8787,  8789,  8793,  8796,  8801,
    8806,  8810,  8819,  8820,  8824,  8836,  8839,  8835,  8858,  8858,
    8862,  8863,  8866,  8867,  8868,  8869,  8870,  8871,  8872,  8877,
    8878,  8882,  8885,  8890,  8894,  8899,  8903,  8908,  8912,  8915,
    8919,  8922,  8927,  8931,  8942,  8948,  8948,  8949,  8950,  8957,
    8966,  8966,  8968,  8969,  8970,  8971,  8972,  8973,  8974,  8975,
    8976,  8977,  8978,  8979,  8980,  8981,  8982,  8983,  8984,  8985,
    8986,  8987,  8988,  8989,  8990,  8991,  8992,  8993,  8994,  8995,
    8996,  8997,  8998,  8999,  9000,  9001,  9002,  9003,  9004,  9005,
    9006,  9007,  9008,  9009,  9010,  9011,  9012,  9013,  9014,  9015,
    9016,  9017,  9018,  9019,  9020,  9021,  9022,  9023,  9024,  9025,
    9026,  9027,  9028,  9029,  9030,  9031,  9032,  9033,  9034,  9035,
    9036,  9037,  9038,  9039,  9040,  9041,  9042,  9043,  9044,  9045,
    9046,  9047,  9048,  9049,  9050,  9051,  9052,  9053,  9054,  9055
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
  "BEFORE_DELETE", "AFTER_INSERT", "AFTER_DELETE", "EXECUTE_IMMEDIATE", 
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
  "INTERVAL", "KWMESSAGE", "NOT_LIKE", "NOT_ILIKE", "NOT_NULL", 
  "PASSWORD", "PREVIOUS", "READONLY", "REGISTER", "RELATIVE", "RESOURCE", 
  "SMALLINT", "VALIDATE", "WHENEVER", "WITH_LOG", "WORDWRAP", "BY_NAME", 
  "IN_FILE", "IS_NULL", "AVERAGE", "BETWEEN", "CAPTION", "CLIPPED", 
  "CLOSE_BRACKET", "COLUMNS", "COMMENT", "CONNECT", "CURRENT", "DBYNAME", 
  "DECIMAL", "DECLARE", "DEFAULT", "DISPLAY", "ENDCODE", "EXECUTE", 
  "FOREACH", "FOREIGN", "GLOBALS", "INFIELD", "INTEGER", "KWWINDOW", 
  "MAGENTA", "NUMERIC", "OPTIONS", "PERCENT", "PREPARE", "PROGRAM", 
  "RECOVER", "REVERSE", "SECTION", "SESSION", "SYNONYM", "THRU", 
  "TRAILER", "UPSHIFT", "VARCHAR", "WAITING", "CLOSE_SHEV", 
  "CLOSE_SQUARE", "KW_FALSE", "NOT_IN", "ONKEY", "OPEN_BRACKET", "BORDER", 
  "BOTTOM", "COLUMN", "COMMIT", "CREATE", "CURSOR", "DEFINE", "DELETE", 
  "DOUBLE", "END_IF", "ESCAPE", "EXISTS", "EXTEND", "EXTENT", "FINISH", 
  "FORMAT", "HAVING", "HEADER", "INSERT", "LOCATE", "MARGIN", "MEMORY", 
  "MINUTE", "MODIFY", "NORMAL", "EQUAL_EQUAL", "OPEN_SHEV", "OPEN_SQUARE", 
  "OPTION", "OUTPUT", "PROMPT", "PUBLIC", "RECORD", "REPORT", "REVOKE", 
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
  "INT_TO_ID", "TIMEOUT", "OFF", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "WITH_1_DIMENSION", 
  "WITH_2_DIMENSION", "WITH_3_DIMENSION", "TILDE", "ILIKE", "$accept", 
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
  "var_def_name", "var_def_list", "op_char", "ranking", "array_variable", 
  "@33", "@34", "@35", "assoc_open_bracket", "assoc_close_bracket", 
  "number_arr_assoc", "number_arr_list", "number_value_arr", 
  "record_variable", "@36", "@37", "@38", "link_to_pk_list", "link_to_pk", 
  "dtype_ident", "op_as_static", "dtype2", "@39", "@40", "dtype", 
  "like_var", "tab_name", "col_name", "datetime_qual", "interval_qual", 
  "dtime_start", "@41", "dtime_val", "dtime_end", "@42", "opt_frac", 
  "opt_unit_size", "dtfrac", "int_start", "@43", "int_start_unit", 
  "int_end", "op_equal", "dim_section", "@44", "dim_dtype", 
  "dim_like_var", "dim_array_variable", "@45", "@46", 
  "dim_record_variable", "@47", "@48", "dim_def_part", "dim_def_part2", 
  "dim_var_def_list", "dim_var_def_name", "opt_at", "display_b_n_cmd", 
  "display_cmd", "display_form_cmd", "display_array_cmd", "@49", "@50", 
  "opt_scroll", "display_attr", "disp_rest", "disp_field_commands", 
  "disp_field_command", "@51", "@52", "@53", "alloc_arr_cmd", 
  "dealloc_arr_cmd", "resize_arr_cmd", "error_cmd", "ext_cmd", 
  "continue_cmd", "exit_prog_cmd", "fgl_expr_c", "fgl_next", 
  "op_fgl_expr_ret_list", "fgl_expr_ret", "fgl_expr_ret_list", 
  "fgl_expr_list", "fgl_expr_concat", "fgl_expr", "int_sign", 
  "boolean_expr", "initial_expr", "literal_expr", "variable_entry_2", 
  "variable_entry", "report_only_expr", "@54", "and_or_expr", 
  "inexpr_list", "in_expr", "null_expr", "string_match_expr", "clip_expr", 
  "using_expr", "math_expr", "comparison_expr", "reset_cnt", 
  "function_call_expr2", "@55", "@56", "@57", "@58", "function_callb", 
  "@59", "@60", "@61", "@62", "@63", "@64", "@65", "@66", "op_extend_d", 
  "op_extend_i", "function_call_expr", "builtin_expr", "builtin_funcs", 
  "pdf_expr", "interval_func_params", "numeric_time_interval", 
  "numeric_time_unit_small", "numeric_time_unit_big", "field_name_list", 
  "for_cmd", "@67", "@68", "for_step", "foreach_cmd", "@69", "@70", "@71", 
  "opt_foreach_using_part", "formhandler_def", "@72", "@73", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@74", 
  "@75", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@76", "@77", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@78", "@79", "@80", 
  "@81", "@82", "free_cmd", "line_no", "file_name", "a_number", "coords", 
  "display_coords", "field_name", "cursor_name", "fetch_cursor_name", 
  "win_name", "open_win_name", "form_name", "open_form_name", 
  "opt_help_no", "identifier", "ident_or_var", "ident_p2", 
  "var_or_string", "field_name2", "cvariable", "real_number", "goto_cmd", 
  "check_menu_cmd", "menu_item_list", "menu_item", "uncheck_menu_cmd", 
  "disable_cmd", "enable_cmd", "msg_box_cmd", "@83", "op_disable_msg", 
  "gm_disable_msg", "op_returning_msg", "gm_returning_msg", "op_caption", 
  "gm_caption", "op_icon", "gm_icon", "op_buttons", "gm_buttons", 
  "op_def_but", "if_cmd", "@84", "@85", "op_else", "@86", "@87", "@88", 
  "import_m", "module_import", "init_cmd", "@89", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@90", "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", 
  "@100", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@101", "inp_rest", "@102", 
  "scroll_cmd", "up_or_down", "op_help", "input_array_attributes", 
  "input_array_attributes_int", "on_key_command", "@103", "key_val", 
  "@104", "accept_key", "single_key_val", "key_do", "key_value_list", 
  "key_value", "key_value_1", "label_cmd", "let_cmd", "@105", "@106", 
  "op_expr_null", "linked_cmd", "linked_del_cmd", "linked_upd_cmd", 
  "locate_cmd", "module", "@107", "op_module_header", "module_header", 
  "module_entry", "func_main_def", "func_or_main2", "at_term_cmd", 
  "func_or_main", "module_code", "op_code", "module_define_section", 
  "ldeffunction", "func_def", "@108", "@109", "@110", "@111", 
  "end_func_command", "main_def", "@112", "@113", "return_cmd", 
  "op_fgl_expr_list", "db_section", "module_globals_section", 
  "actual_globals_section", "xglobals_entry", "globals_entry", "@114", 
  "glob_section", "mem_func_def", "@115", "@116", "@117", "menu_cmd", 
  "@118", "end_menu_command", "menu_block_command", "@119", "@120", 
  "@121", "menu_commands", "opt_key", "menu_opt_name", 
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
  "opt_timeout", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@127", "prompt_title", 
  "put_cmd", "@128", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
  "term_rep_cmd", "report_section", "format_section", "format_actions", 
  "format_action", "@129", "@130", "@131", "@132", "@133", "@134", "@135", 
  "report_cmd", "need_command", "@136", "op_lines", "skip_command", 
  "@137", "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
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
  "sql_block_entry", "in_var", "@171", "sql_block_into", "@172", 
  "update_statement_ss", "@173", "@174", "where_upd_ss", 
  "set_clause_list_ss", "upd_columns_ss", "upd_column_name", "col_1_ss", 
  "upd_col_list", "upd_val_list_ss", "upd_val_ss", 
  "upd_value_expression_ss", "upd_value_expression_initial_ss", 
  "upd_value_expression_complex_ss", "upd_var_ident_ibind_ss", 
  "upd_value_expr_list_ss", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "when_do", "label_goto", 
  "function_name_when", "while_cmd", "@175", "@176", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list", "current_win_cmd", "window_type", 
  "show_cmd", "op_mnfile", "menu_name", "menu_handler", "hide_cmd", 
  "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@177", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1665,  1666,  1667,  1571,  1611,  1566,  1502,  1586,
    1381,  1488,  1484,  1399,  1561,  1297,  1356,  1430,  1597,  1584,
    1489,  1517,  1585,  1363,  1668,  1669,  1670,  1671,  1672,  1673,
    1674,  1675,  1676,  1677,  1000,  1001,  1002,  1003,  1004,  1005,
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
    1296,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1357,
    1358,  1359,  1360,  1361,  1362,  1364,  1365,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1431,
    1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1482,  1483,  1485,  1486,  1487,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1503,  1504,  1505,
    1506,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,
    1516,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1562,  1563,  1564,  1565,  1567,  1568,
    1569,  1570,  1572,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
    1580,  1581,  1582,  1583,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   680,   681,   682,   683,   684,   685,   685,   686,   686,
     687,   688,   688,   688,   688,   688,   688,   689,   689,   689,
     689,   689,   690,   690,   691,   691,   693,   692,   692,   694,
     694,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   695,   695,   695,   695,   695,   695,   695,   696,   696,
     698,   697,   699,   699,   700,   700,   700,   700,   700,   700,
     700,   700,   700,   701,   702,   703,   702,   702,   702,   702,
     702,   704,   705,   702,   706,   707,   708,   702,   709,   710,
     702,   711,   712,   702,   713,   714,   715,   702,   716,   716,
     717,   717,   717,   718,   718,   719,   719,   720,   721,   721,
     722,   722,   724,   723,   725,   723,   726,   726,   727,   727,
     728,   729,   730,   729,   731,   732,   731,   734,   733,   736,
     735,   737,   737,   737,   737,   737,   737,   738,   739,   739,
     740,   740,   741,   742,   742,   743,   744,   746,   747,   745,
     748,   748,   749,   749,   750,   750,   751,   751,   751,   752,
     752,   754,   753,   755,   753,   756,   753,   757,   753,   758,
     753,   759,   759,   760,   760,   761,   761,   761,   761,   761,
     761,   762,   763,   763,   764,   764,   765,   765,   766,   766,
     768,   769,   767,   767,   767,   770,   770,   772,   771,   773,
     773,   773,   773,   773,   774,   773,   775,   775,   775,   775,
     776,   777,   777,   778,   778,   779,   779,   779,   779,   781,
     780,   782,   780,   783,   780,   784,   784,   785,   785,   786,
     787,   787,   787,   788,   790,   789,   791,   789,   792,   789,
     793,   793,   794,   795,   796,   796,   798,   799,   797,   800,
     800,   800,   800,   800,   800,   800,   800,   800,   800,   800,
     800,   800,   800,   800,   800,   800,   800,   800,   800,   800,
     800,   800,   800,   800,   800,   800,   800,   801,   802,   803,
     804,   804,   805,   807,   806,   808,   808,   808,   808,   808,
     808,   808,   810,   809,   811,   811,   812,   812,   813,   815,
     814,   816,   816,   816,   816,   816,   816,   816,   817,   818,
     818,   820,   819,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   822,   824,   823,   825,
     823,   827,   826,   828,   826,   829,   829,   830,   831,   831,
     832,   833,   833,   833,   833,   833,   833,   833,   833,   834,
     835,   836,   838,   839,   837,   840,   840,   841,   842,   842,
     843,   843,   845,   844,   846,   844,   847,   844,   848,   849,
     850,   851,   851,   852,   852,   852,   852,   852,   852,   852,
     852,   852,   853,   853,   853,   853,   853,   853,   853,   853,
     854,   854,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   856,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   856,   857,   857,   858,   858,   859,   859,   860,
     860,   861,   861,   862,   863,   863,   864,   864,   864,   864,
     864,   864,   865,   865,   866,   866,   866,   866,   867,   867,
     868,   869,   869,   869,   870,   869,   871,   871,   872,   872,
     873,   873,   873,   873,   874,   874,   875,   875,   875,   875,
     875,   875,   875,   875,   876,   877,   878,   878,   878,   878,
     878,   878,   879,   879,   879,   879,   879,   879,   879,   880,
     882,   883,   881,   884,   885,   881,   887,   888,   886,   889,
     890,   886,   891,   892,   886,   893,   894,   886,   886,   886,
     886,   886,   895,   895,   896,   897,   897,   897,   897,   897,
     897,   897,   897,   897,   898,   898,   899,   899,   899,   899,
     900,   900,   900,   901,   901,   902,   902,   902,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   903,   904,   904,
     905,   905,   907,   908,   906,   909,   909,   911,   912,   913,
     910,   914,   914,   916,   917,   915,   918,   918,   919,   919,
     920,   920,   922,   921,   923,   921,   924,   924,   925,   925,
     927,   926,   928,   926,   929,   930,   930,   930,   931,   931,
     932,   932,   933,   933,   934,   934,   936,   935,   937,   935,
     938,   935,   939,   935,   940,   935,   941,   942,   942,   942,
     942,   942,   942,   942,   943,   943,   944,   945,   946,   947,
     947,   947,   947,   947,   947,   947,   947,   948,   949,   950,
     951,   952,   953,   954,   954,   955,   956,   957,   957,   958,
     958,   959,   959,   959,   959,   959,   959,   960,   961,   961,
     962,   963,   964,   964,   965,   966,   967,   967,   967,   968,
     968,   968,   970,   969,   971,   971,   972,   972,   973,   973,
     974,   975,   975,   976,   977,   977,   978,   979,   979,   980,
     981,   981,   983,   984,   982,   985,   986,   985,   987,   988,
     985,   989,   989,   990,   992,   991,   991,   993,   993,   994,
     994,   995,   995,   996,   996,   997,   997,   999,   998,  1000,
     998,  1001,   998,  1002,   998,  1003,   998,  1004,   998,  1005,
     998,  1006,   998,  1007,   998,  1008,   998,  1009,   998,  1010,
    1010,  1011,  1011,  1012,  1013,  1014,  1014,  1014,  1016,  1015,
    1017,  1017,  1018,  1017,  1019,  1020,  1020,  1020,  1020,  1021,
    1021,  1022,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,
    1023,  1025,  1024,  1024,  1027,  1026,  1028,  1029,  1030,  1030,
    1031,  1031,  1032,  1033,  1033,  1033,  1033,  1033,  1033,  1033,
    1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,
    1033,  1034,  1036,  1037,  1035,  1038,  1038,  1039,  1040,  1041,
    1042,  1042,  1044,  1043,  1045,  1045,  1046,  1046,  1047,  1047,
    1047,  1047,  1048,  1048,  1049,  1049,  1050,  1051,  1051,  1051,
    1051,  1051,  1051,  1051,  1051,  1051,  1051,  1051,  1052,  1052,
    1053,  1053,  1053,  1054,  1055,  1055,  1057,  1058,  1059,  1060,
    1056,  1061,  1063,  1064,  1062,  1065,  1066,  1066,  1067,  1067,
    1068,  1069,  1069,  1070,  1070,  1070,  1072,  1071,  1073,  1073,
    1075,  1076,  1077,  1074,  1079,  1078,  1080,  1082,  1081,  1083,
    1081,  1084,  1081,  1085,  1085,  1086,  1086,  1087,  1087,  1088,
    1088,  1088,  1089,  1090,  1091,  1092,  1092,  1092,  1093,  1093,
    1094,  1094,  1096,  1097,  1095,  1098,  1098,  1100,  1099,  1101,
    1099,  1102,  1103,  1103,  1103,  1103,  1104,  1104,  1104,  1104,
    1104,  1105,  1106,  1106,  1107,  1108,  1109,  1109,  1110,  1111,
    1111,  1111,  1111,  1111,  1111,  1112,  1113,  1114,  1114,  1115,
    1115,  1116,  1117,  1118,  1118,  1119,  1119,  1120,  1121,  1122,
    1122,  1122,  1122,  1122,  1122,  1123,  1123,  1124,  1125,  1125,
    1126,  1126,  1127,  1127,  1128,  1128,  1129,  1129,  1129,  1129,
    1129,  1130,  1130,  1131,  1131,  1132,  1132,  1133,  1134,  1135,
    1135,  1136,  1137,  1137,  1137,  1138,  1139,  1139,  1140,  1140,
    1141,  1142,  1142,  1143,  1143,  1144,  1145,  1146,  1147,  1147,
    1148,  1149,  1149,  1150,  1150,  1151,  1151,  1152,  1153,  1153,
    1154,  1154,  1154,  1154,  1155,  1155,  1155,  1156,  1157,  1157,
    1158,  1158,  1158,  1159,  1160,  1160,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1162,  1163,
    1163,  1164,  1164,  1164,  1165,  1167,  1166,  1168,  1168,  1169,
    1170,  1170,  1171,  1171,  1172,  1172,  1174,  1173,  1175,  1177,
    1176,  1178,  1178,  1179,  1179,  1180,  1180,  1181,  1181,  1181,
    1181,  1182,  1182,  1183,  1184,  1184,  1185,  1186,  1187,  1188,
    1189,  1189,  1190,  1190,  1192,  1191,  1193,  1191,  1194,  1191,
    1195,  1191,  1196,  1191,  1197,  1191,  1198,  1191,  1199,  1199,
    1199,  1199,  1199,  1199,  1201,  1200,  1202,  1202,  1204,  1203,
    1203,  1203,  1203,  1203,  1205,  1205,  1206,  1206,  1207,  1208,
    1208,  1209,  1210,  1211,  1212,  1212,  1212,  1213,  1213,  1213,
    1213,  1214,  1215,  1215,  1216,  1216,  1217,  1218,  1218,  1218,
    1218,  1218,  1218,  1218,  1218,  1219,  1219,  1220,  1220,  1221,
    1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1222,
    1222,  1223,  1223,  1223,  1223,  1224,  1224,  1225,  1225,  1226,
    1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1226,  1226,  1227,  1227,  1227,  1229,  1230,  1231,  1232,
    1233,  1234,  1228,  1235,  1235,  1236,  1237,  1237,  1239,  1240,
    1241,  1242,  1243,  1244,  1238,  1245,  1247,  1248,  1249,  1246,
    1250,  1250,  1250,  1250,  1251,  1251,  1251,  1251,  1251,  1252,
    1253,  1253,  1253,  1254,  1254,  1256,  1257,  1255,  1258,  1259,
    1255,  1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1263,
    1264,  1264,  1265,  1265,  1266,  1266,  1267,  1268,  1268,  1269,
    1269,  1269,  1269,  1269,  1269,  1269,  1270,  1270,  1271,  1271,
    1272,  1272,  1273,  1273,  1274,  1274,  1275,  1276,  1276,  1277,
    1277,  1278,  1279,  1279,  1280,  1281,  1281,  1282,  1282,  1283,
    1283,  1284,  1285,  1285,  1285,  1285,  1285,  1285,  1285,  1285,
    1285,  1285,  1285,  1286,  1286,  1287,  1287,  1288,  1289,  1291,
    1290,  1293,  1292,  1292,  1294,  1294,  1295,  1295,  1296,  1296,
    1297,  1297,  1299,  1300,  1298,  1301,  1302,  1302,  1303,  1304,
    1303,  1305,  1306,  1305,  1307,  1307,  1307,  1307,  1307,  1307,
    1307,  1307,  1308,  1309,  1310,  1311,  1311,  1312,  1313,  1313,
    1314,  1314,  1314,  1315,  1316,  1317,  1317,  1318,  1319,  1319,
    1321,  1320,  1322,  1322,  1322,  1322,  1322,  1322,  1322,  1322,
    1322,  1322,  1322,  1322,  1323,  1324,  1324,  1325,  1325,  1326,
    1326,  1327,  1327,  1327,  1327,  1328,  1328,  1329,  1329,  1330,
    1330,  1331,  1331,  1332,  1333,  1333,  1334,  1334,  1335,  1335,
    1336,  1337,  1338,  1339,  1340,  1340,  1341,  1341,  1342,  1342,
    1343,  1343,  1344,  1344,  1344,  1345,  1345,  1346,  1347,  1347,
    1348,  1348,  1349,  1349,  1350,  1350,  1350,  1350,  1350,  1351,
    1352,  1353,  1354,  1354,  1355,  1355,  1356,  1357,  1358,  1358,
    1359,  1360,  1361,  1361,  1362,  1362,  1362,  1363,  1363,  1364,
    1364,  1365,  1366,  1366,  1367,  1367,  1368,  1368,  1369,  1369,
    1370,  1370,  1371,  1371,  1372,  1372,  1373,  1373,  1374,  1374,
    1375,  1376,  1377,  1377,  1377,  1377,  1378,  1378,  1379,  1379,
    1380,  1380,  1381,  1381,  1381,  1381,  1381,  1381,  1381,  1381,
    1381,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,
    1383,  1383,  1383,  1384,  1384,  1384,  1384,  1385,  1385,  1385,
    1386,  1386,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1388,
    1388,  1389,  1389,  1389,  1389,  1389,  1390,  1391,  1392,  1393,
    1393,  1393,  1393,  1394,  1395,  1395,  1395,  1396,  1396,  1397,
    1397,  1397,  1398,  1399,  1399,  1399,  1399,  1399,  1400,  1401,
    1402,  1402,  1403,  1403,  1404,  1404,  1404,  1404,  1404,  1404,
    1404,  1404,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,
    1406,  1406,  1406,  1406,  1406,  1406,  1406,  1407,  1407,  1407,
    1407,  1407,  1407,  1407,  1408,  1408,  1409,  1411,  1410,  1412,
    1410,  1413,  1410,  1414,  1410,  1415,  1415,  1415,  1416,  1416,
    1417,  1417,  1417,  1418,  1418,  1419,  1419,  1420,  1422,  1423,
    1421,  1424,  1425,  1425,  1426,  1427,  1427,  1427,  1427,  1427,
    1428,  1429,  1429,  1430,  1431,  1432,  1432,  1432,  1432,  1433,
    1433,  1434,  1434,  1435,  1436,  1436,  1436,  1437,  1437,  1437,
    1437,  1437,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1438,  1439,  1439,  1440,  1441,  1442,  1442,  1443,  1443,
    1444,  1444,  1445,  1445,  1446,  1446,  1447,  1448,  1448,  1449,
    1449,  1450,  1451,  1451,  1451,  1452,  1452,  1453,  1454,  1455,
    1456,  1457,  1457,  1458,  1458,  1458,  1458,  1458,  1458,  1459,
    1459,  1459,  1461,  1460,  1462,  1462,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1465,
    1464,  1467,  1466,  1469,  1470,  1468,  1471,  1471,  1471,  1472,
    1472,  1472,  1472,  1472,  1472,  1473,  1473,  1474,  1475,  1476,
    1476,  1477,  1477,  1478,  1478,  1479,  1479,  1479,  1480,  1480,
    1480,  1480,  1480,  1480,  1480,  1480,  1480,  1480,  1481,  1481,
    1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,
    1481,  1481,  1482,  1483,  1483,  1484,  1485,  1485,  1486,  1486,
    1486,  1486,  1487,  1487,  1487,  1488,  1488,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  1489,  1490,  1490,  1490,
    1490,  1490,  1491,  1491,  1492,  1494,  1495,  1493,  1496,  1496,
    1497,  1497,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1499,
    1499,  1500,  1500,  1501,  1501,  1502,  1502,  1503,  1503,  1504,
    1505,  1506,  1507,  1507,  1508,  1509,  1509,  1510,  1511,  1511,
    1513,  1512,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     0,     5,     6,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       0,     5,     1,     3,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     3,     0,     7,     8,     6,     1,
       6,     0,     0,     9,     0,     0,     0,     8,     0,     0,
      10,     0,     0,     9,     0,     0,     0,    14,     0,     2,
       0,     2,     1,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     0,     6,     0,     5,     1,     2,     1,     2,
       1,     0,     0,     3,     0,     0,     3,     0,     4,     0,
       4,     2,     2,     2,     1,     2,     2,     3,     1,     1,
       1,     2,     1,     1,     2,     1,     1,     0,     0,     5,
       7,     8,     0,     2,     1,     3,     1,     3,     3,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     1,     1,     0,     1,     1,     2,
       0,     0,     5,     1,     1,     1,     3,     0,     2,     4,
       4,     4,     4,     2,     0,     4,     1,     1,     1,     2,
       1,     1,     3,     0,     1,     0,     1,     1,     1,     0,
       7,     0,     5,     0,    12,     1,     1,     1,     1,     1,
       5,     3,     1,     1,     0,     4,     0,     5,     0,     7,
       1,     3,     1,     1,     0,     1,     0,     0,     4,     1,
       1,     1,     4,     4,     6,     1,     2,     1,     1,     1,
       1,     4,     6,     1,     4,     6,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     1,     4,     1,     1,
       0,     3,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     2,     0,     2,     0,     3,     0,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       1,     0,     5,     1,     1,     1,     4,     4,     6,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     2,     2,     1,     4,     0,     7,     0,
      12,     0,     4,     0,     5,     1,     3,     2,     1,     3,
       1,     0,     2,     2,     1,     2,     5,     4,     2,     4,
       5,     3,     0,     0,    11,     0,     2,     1,     0,     2,
       1,     2,     0,     3,     0,     3,     0,     3,     2,     2,
       2,     4,     5,     1,     1,     1,     1,     1,     1,     1,
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
       1,     2,     4,     2,     1,     0,    11,     0,     2,     5,
       0,     1,     0,     2,     1,     2,     0,     3,     1,     0,
       4,     0,     2,     1,     3,     1,     1,     3,     4,     4,
       2,     1,     1,     1,     0,     1,     7,     2,     2,     2,
       2,     2,     1,     2,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     1,     0,     4,
       1,     2,     2,     2,     0,     1,     1,     2,     2,     0,
       2,     3,     3,     5,     0,     2,     4,     1,     1,     1,
       1,     1,     0,     1,     1,     3,     2,     5,     2,     5,
       5,     5,     5,     5,     5,     0,     2,     1,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     1,     1,     1,     0,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     2,
       1,     1,     1,     0,     3,     2,     0,     0,     0,     0,
       0,     0,    15,     0,     2,     2,     0,     1,     0,     0,
       0,     0,     0,     0,    15,     2,     0,     0,     0,    10,
       0,     1,     3,     3,     2,     4,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     0,     0,     7,     0,     0,
       8,     3,     2,     0,     1,     1,     3,     2,     2,     1,
       1,     3,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     3,
       1,     3,     2,     4,     1,     3,     1,     2,     4,     1,
       3,     1,     1,     1,     2,     2,     4,     2,     4,     1,
       3,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     6,     6,     0,     1,     0,     1,     2,     1,     0,
       5,     0,     5,     1,     0,     3,     1,     3,     1,     3,
       1,     1,     0,     0,     5,     1,     2,     1,     0,     0,
       3,     0,     0,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     4,     3,     3,     1,     3,     2,     1,     1,
       0,     1,     1,     1,     1,     0,     1,     3,     1,     1,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     0,     1,     1,     1,     1,
       3,     1,     1,     1,     2,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       1,     3,     1,     1,     1,     2,     1,     4,     0,     1,
       0,     1,     1,     2,     1,     1,     1,     1,     4,     3,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     3,
       2,     2,     1,     3,     1,     2,     4,     1,     2,     1,
       3,     4,     0,     1,     0,     1,     0,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     2,     2,     0,     2,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       0,     1,     3,     3,     3,     6,     4,     4,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       5,     4,     0,     4,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     3,     0,     0,     6,     0,     2,     2,     7,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     794,     0,  2100,  2103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,   180,     0,   818,   823,
     178,   183,   798,     0,   792,   795,   796,   799,   801,   845,
     800,   840,   841,   843,   184,   135,   132,     0,   128,   130,
     129,   133,  2144,   683,   625,  2107,     0,     0,  2110,     0,
    2106,  2102,  2099,  2097,  2098,  2105,  2104,  2101,   301,  1585,
    1584,   838,   176,   187,   839,   179,   184,     1,   802,   797,
     844,   842,   819,   127,   131,   134,  2114,  2111,     0,  2112,
    2109,     0,     0,   604,     0,     0,   177,   849,   913,   605,
     847,   637,   905,     0,   906,   914,   912,   187,   181,   200,
       0,   185,   201,   236,     0,   825,  1198,     0,     0,   824,
     136,  1186,   832,     0,     0,   815,   817,   814,   816,   793,
     803,   804,   826,   807,   808,   809,   812,   810,   811,   813,
    2113,  2108,     0,   907,   848,     0,     0,   921,   919,   920,
     909,   908,   299,   187,  1122,   194,   188,   187,   193,   233,
       0,   682,     0,     0,     0,     0,   176,   553,   882,   805,
       0,   333,   319,   203,   270,   289,   310,   312,   309,     0,
     331,     0,   318,   311,   315,   321,   305,   320,   187,   322,
     302,   325,   303,   304,   918,   917,     0,    22,    23,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   927,     0,   513,
     505,    16,   512,   913,    15,     0,   925,     0,   300,     0,
     186,  1123,   182,     0,   200,   202,   266,   260,   261,   249,
     226,   257,   203,   228,   270,   289,   247,   250,   245,     0,
     224,     0,   256,   248,   253,   259,   241,   258,   187,   262,
     187,   205,   239,   240,   237,   265,     0,     0,     0,     0,
     833,   176,   176,     0,     0,   204,     0,   323,     0,     0,
     324,     0,     0,     0,     0,     0,     0,     0,     0,   268,
       0,   915,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   519,     0,     0,     0,   638,   434,
     436,  1193,     0,     0,     0,  1552,     0,   428,     0,     0,
       0,   427,     0,   444,   515,     0,     0,     0,     0,     0,
     518,     0,   393,   392,   399,   440,   437,   394,   395,   397,
     398,   435,   438,   443,   514,   489,   486,   495,   492,    17,
      18,    19,    20,    21,     0,    14,   480,     0,     0,   923,
       0,   189,   192,   190,   191,     0,   197,   196,   195,   198,
     187,     0,   187,   263,   264,     0,     0,   187,     0,     0,
       0,     0,   246,   206,   207,   208,   211,   234,  1199,     0,
       0,  1187,  2150,   554,   883,   827,     0,   215,   216,     0,
     282,   284,   279,   280,   276,   278,   275,   277,   274,     0,
     284,   295,   296,   292,   294,   291,   293,   286,     0,     0,
       0,   335,     0,   338,   340,   223,     0,   222,     0,     0,
     187,     0,  2129,   609,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   537,   523,   528,     0,   524,   527,   526,
       0,     0,    11,   172,   426,   401,   400,     0,  1128,     0,
       0,   442,  1560,  1558,  1559,  1555,  1557,  1554,  1556,  1548,
       0,     0,     0,   441,     0,     0,     0,     0,     0,     0,
       0,   639,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   165,
     166,   167,   168,   169,   170,   520,   521,   522,   455,     0,
       0,   454,   464,     0,     0,   405,     0,     0,   406,   396,
     402,   404,   407,   408,   409,   410,   411,   403,   433,   432,
       0,     0,     0,     0,     0,    12,    93,     0,   926,     0,
     910,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   187,     0,   235,   238,   938,   681,   850,   938,     0,
    2148,  2150,  1122,  1679,   820,     0,   938,     0,     0,   271,
       0,     0,   281,   298,   272,   297,     0,   290,     0,   313,
       0,   307,     0,   332,     0,   337,   327,     0,     0,   316,
     306,   269,   326,     0,     0,     0,     0,   511,   508,   507,
     510,   506,   517,   502,   502,     0,   525,     0,   529,     0,
     289,   509,   516,   273,     0,  1194,  1625,     0,     0,     0,
       0,     0,   429,     0,     0,   445,     0,     0,     0,     0,
     447,   446,   465,   456,   471,   474,   475,   472,   478,   477,
     476,   466,   467,   468,   469,   470,   412,   457,   461,   479,
     473,   460,   479,   439,   490,   487,   496,   493,   481,    94,
      95,    97,   483,     0,     0,     0,     0,     0,     0,   251,
       0,   243,   225,   209,     0,   254,   242,   267,   236,   944,
       0,   939,   940,   938,     0,   834,  2149,  2147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2131,     0,  1288,
    1287,     0,  1289,     0,   386,  1286,  1228,     0,     5,  1285,
     387,   384,     0,   389,   174,   479,  1100,     0,     0,  1295,
     124,   383,   382,  1220,   377,   479,     0,  1245,  2122,     0,
     388,   352,     0,     3,     2,     0,   385,  1225,     0,     0,
     378,   375,   390,     0,     0,     0,     0,  1293,  1283,   381,
       0,     0,     0,     0,     0,     0,     0,     0,  1282,     0,
       0,     0,   175,  1222,   374,   373,     0,     0,  2126,  2125,
       0,     0,     0,   137,  1221,   380,   379,     0,     0,   376,
     479,   479,     0,   547,     0,     0,     0,     0,     0,     0,
     479,   781,  1196,     0,     0,  1104,     0,  2115,     0,   104,
       0,     0,   854,     0,     0,     0,     0,   782,     0,     0,
    1702,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     652,     0,     0,     0,     0,     0,  2152,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,  2175,
    2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,
    2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,
    2196,  2197,  2198,  2199,  2200,  2201,   892,  2202,  2203,  2204,
    2205,  2206,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,
    2215,  2216,  2217,  2218,  1091,  1093,  1088,  1090,  1089,  1092,
    2219,  2220,  1219,  2221,  1224,  1223,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  2231,  1350,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2239,  2151,   821,   558,   822,     0,
     887,     0,   885,     0,   334,   217,   218,     0,   283,   288,
       0,     0,     0,     0,   336,   339,     0,   221,     0,     0,
       0,   613,     0,   615,  2130,   499,     0,   500,     0,   539,
       0,   536,   533,   504,   498,     0,   171,  1627,  1628,  1626,
       0,   431,  1193,     0,  1553,  1193,   430,  1193,  1193,  1193,
    1193,  1193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    93,   924,     0,   227,
       0,   187,     0,     0,     0,     0,   212,     0,  1200,     0,
       0,  1188,  1030,  1029,  1033,     0,     0,  1232,   626,   627,
     806,  1063,  1068,  2124,   619,   123,     0,     0,  2089,  2088,
     998,  2085,  2087,  2139,     0,  1239,     0,  1235,  1244,     7,
       0,     6,     0,  2132,  1064,     0,  1156,  1155,  1103,  1154,
    1102,   423,  1296,  1284,   835,   413,  1681,  1290,   125,     0,
    1067,   122,     0,   788,    24,   621,   391,     0,   787,  1060,
     789,     0,  1294,   876,   875,   878,   874,   877,  2141,     0,
     872,     0,   620,   971,   873,  2135,     0,  2123,   121,   968,
     684,   966,     0,   617,  2118,   726,   725,   727,   723,     0,
       0,   981,   622,  1349,  1345,  1348,     0,     0,  1034,  1031,
       0,  1025,  1027,  1026,  1024,  1023,     0,     0,     0,  1022,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1012,  1003,  1004,     0,  1048,   421,    24,
       0,  2120,   126,   618,     0,  1197,  1195,  1121,     0,  1670,
    1671,  1122,  1210,  1122,  1105,  1106,  1109,  1124,  1297,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,   913,
       0,    69,     0,   102,   596,   640,     0,  1094,   988,  1098,
       0,     0,  1049,  1214,     0,     0,  1101,   644,   641,   642,
       0,   646,   647,     0,   649,   650,     0,   645,   948,   950,
       0,     0,   949,   728,   946,   693,   942,   370,   368,   369,
     904,     0,     0,     0,     0,   656,   657,     0,     0,   902,
     899,   900,   896,   897,   898,   891,   895,   894,     0,     0,
       0,     0,     0,     0,   562,   564,   556,   559,   560,   889,
    2150,   884,   886,   828,     0,   285,   287,   314,   308,     0,
       0,   317,   610,   612,     0,     0,   502,   530,     0,   282,
       0,     0,  1651,  1543,  1546,  1652,  1550,  1544,  1649,     0,
       0,  1648,     0,     0,  1650,     0,     0,     0,     0,     0,
    2089,  1545,  1647,  1547,  1639,     0,  1629,  1631,  1634,  1637,
    2095,  1638,  1131,  1561,  1130,  1129,  1132,  1134,  1133,  1127,
     458,   459,   463,   448,     0,   451,   462,     0,   450,   491,
     488,   497,   494,   482,    96,   484,   911,     0,   232,     0,
     230,   252,   244,   236,   255,   945,   176,   941,   851,   176,
       0,     0,     0,  1272,  1273,     0,     0,     0,  1246,  1247,
    1249,  1250,  1251,  1255,  1254,  1252,  1253,     0,     0,  2086,
     922,     0,  1000,     0,     0,  1238,  1237,     0,  1231,     0,
    1530,  1531,     0,  1065,     0,    24,  1151,  1153,  1152,   416,
     417,   414,   415,   958,     0,     0,   357,    25,   351,     0,
       0,  1057,     0,     0,     0,     0,     0,     0,     0,   975,
    1680,     0,     0,   187,     0,     0,     0,  2120,     0,     0,
     138,     0,     0,   985,   977,   978,   983,  1346,  1347,   901,
     419,   341,     0,   548,   601,   600,   598,   603,  1006,   602,
    1011,  1007,  1010,   780,   772,   766,   778,   779,   764,   765,
     773,   768,   774,   767,   777,   771,   775,   770,   776,   763,
     769,   756,   762,  1008,  1009,     0,  1016,  1020,  1013,  1014,
    1018,  1019,  1017,  1015,  1021,     0,   790,     0,     0,     0,
       0,     0,   738,   737,   734,  2121,  2128,    24,  1117,  1118,
    1119,  1120,  1114,  1112,  1211,  1126,  1111,  1107,     0,     0,
    1108,  2116,     0,     0,     0,     0,    98,     0,    99,     0,
       0,     0,    74,     0,     0,     0,   111,   106,     0,   881,
       0,   880,     0,   479,  1096,     0,   933,   934,   957,   928,
     929,   783,   955,  1051,  1216,     0,  1218,  1217,  1759,  1877,
    1873,  1879,  1911,  1891,  1882,  1841,  1803,  1931,  1897,  1905,
    1794,  1900,  1760,  1706,  1892,  1799,  1850,  1985,  1829,  1817,
    1830,  1929,  1932,  1899,  1853,  1935,  1718,  1992,  1928,  1956,
    1729,  2029,  1818,  2001,  1711,  1961,  1727,  1789,  1836,  1856,
    1951,  1979,  1984,  1710,  1908,  1937,  1722,  1724,  1748,  1766,
    1787,  1797,  1807,  1860,  1863,  1922,  1933,  1939,  1940,  1957,
    2002,  2013,  1709,  1740,  1765,  1764,  1767,  1773,  1775,  1783,
    1793,  1814,  1832,  1835,  1861,  1869,  1926,  1936,  1946,  1952,
    1953,  1955,  1980,  2010,  2017,  2022,  1730,  1733,  1744,  1751,
    1753,  1758,  1761,  1763,  1770,  1778,  1780,  1781,  1782,  1792,
    1802,  1809,  1825,  1826,  1837,  1855,  1859,  1872,  1888,  1912,
    1920,  1930,  1934,  1941,  1949,  1958,  1968,  1972,  1989,  1995,
    1999,  2007,  2012,  2015,  1754,  1874,  1917,  1738,  1739,  1757,
    1762,  1769,  1771,  1785,  1786,  1796,  1805,  1810,  1812,  1813,
    1819,  1827,  1844,  1845,  1858,  1886,  1890,  1893,  1898,  1902,
    1910,  1918,  1919,  1924,  1942,  1943,  1948,  1954,  1959,  1965,
    1966,  1967,  1969,  1971,  1973,  1982,  2004,  2005,  2006,  2011,
    2028,  1713,  1868,  1876,  1878,  1975,  1715,  1719,  1723,  1728,
    1734,  1735,  1749,  1750,  1752,  1755,  1768,  1784,  1804,  1806,
    1816,  1820,  1822,  1823,  1831,  1840,  1842,  1843,  1854,  1867,
    1885,  1903,  1904,  1921,  1923,  1927,  1938,  1960,  1970,  1978,
    2000,  2003,  2018,  2019,  2020,  1746,  1716,  1736,  1737,  1743,
    1815,  1745,  1747,  1772,  1774,  1788,  1865,  1990,  1798,  1800,
    1808,  1811,  1833,  1834,  1839,  1846,  1847,  1848,  2031,  1880,
    1881,  1884,  1889,  1894,  1901,  1906,  1907,  1909,  1916,  1945,
    1947,  1963,  1974,  1976,  1977,  1981,  1986,  1987,  1991,  1993,
    1994,  2009,  2014,  2016,  2021,  2023,  2027,  1875,  2026,  1712,
    1714,  1717,  1721,  1731,  1756,  1776,  1777,  1779,  1790,  1821,
    1824,  1864,  1870,  1883,  1887,  2024,  2025,  1925,  1944,  1950,
    1962,  1964,  1983,  1988,  1998,  2008,  1726,  1720,  1725,  1742,
    1795,  1838,  1851,  1852,  1913,  1915,  1997,  1871,  1828,  1895,
    1741,  1791,  1801,  1866,  1849,  1896,  1732,  1857,  1862,  1996,
    1914,     0,  1704,  1707,  1708,   672,     0,     0,     0,   661,
     693,   693,   691,     0,     0,   694,     0,    26,   660,   663,
       0,   670,   666,   903,   893,  1677,  1678,  1668,  1668,  1315,
       0,     0,  1586,     0,   187,  1298,     0,     0,  1299,  1343,
     187,     0,  1344,     0,  1625,     0,  1312,     0,  1361,  1360,
    1359,  1357,  1358,  1356,  1354,  1351,  1425,  1424,  1352,  1353,
    1362,  1595,  1355,  1684,  1683,  1682,  1363,  2150,  2150,   575,
     566,   557,     0,   561,  2150,   888,   176,     0,   328,   220,
       0,     0,  1568,  1566,  1567,  1563,  1565,  1562,  1564,   503,
     501,     0,   535,   534,   173,  1636,  1635,  1576,  1574,  1575,
    1571,  1573,  1570,  1572,  1549,     0,  1625,     0,     0,  1493,
       0,  1493,  1493,  1493,  1493,  1640,     0,     0,     0,  1442,
    1615,  1632,     0,     0,     0,     0,  1693,  1694,  1695,  1696,
    1697,  1698,  1643,     0,     0,   453,   452,     0,     0,   187,
     229,   210,  1201,   176,  1189,  1415,     0,  1414,     0,  1416,
       0,  1417,  1275,     0,  1281,  1277,  1274,     0,     0,     0,
       0,     0,     0,  1271,  1267,  1404,  1403,  1402,  1243,  1242,
       0,  1266,  1262,     0,  1258,  1256,     0,   630,     0,   629,
       0,   999,     0,     0,   997,  2092,  2094,  2093,  2090,  2140,
    2137,  1236,     0,     0,     0,  1229,   479,   349,     0,     0,
    1226,   990,  1061,  1062,  1059,  1058,     0,   879,     0,     0,
     606,     0,     0,     0,   969,   967,     0,   686,   687,     0,
       0,  2119,  2127,   724,     0,   142,     0,   979,   986,     0,
       0,   994,     0,   344,     0,     0,     0,     0,    24,  1032,
     551,     0,     0,     0,   757,   758,  1005,   791,   422,     0,
    1040,   735,   736,   371,     0,  1122,     0,  1125,  1110,  2150,
       0,     0,     0,   540,     0,     0,     0,     0,    64,    93,
       0,     0,   117,   112,     0,   107,     0,   114,   108,   865,
     857,   863,     0,  1095,     0,  1097,  1099,     0,     0,   937,
       0,     0,     0,     0,  1050,  1215,     0,     0,  1703,  1705,
    2150,   643,   648,   651,   664,   662,   623,     0,   713,   711,
     717,   715,     0,     0,   709,   753,   707,   703,   701,   751,
     729,     0,   695,   705,   947,   943,     0,     0,     0,     0,
     669,     0,     0,     0,     0,     0,     0,     0,  1533,     0,
    1420,  1421,  1689,  1384,  1442,     0,     0,  1687,     0,     0,
    1608,  2033,     0,  1367,  1373,  1372,  1371,  1375,     0,  1368,
    1369,     0,  1596,  1607,   563,   565,     0,     0,   578,   570,
     572,     0,   567,   568,     0,     0,   586,   588,     0,     0,
     584,   890,   829,   219,     0,   614,   616,   611,     0,   532,
     531,     0,     0,  1660,     0,     0,     0,  1495,  1496,  1494,
       0,  1662,     0,     0,     0,     0,     0,     0,     0,  1630,
       0,  1431,  1432,  1434,  1437,     0,  1443,  1444,     0,     0,
    1493,  1617,  1611,  1645,  1646,  1644,  1642,  2096,   449,   485,
       0,   231,  1157,   852,  1135,  1392,  1394,     0,  1279,     0,
       0,     0,     0,     0,  1269,     0,     0,  1525,  1523,  1510,
    1512,  1508,     0,  1507,     0,  1516,  1503,  1524,     0,  1515,
    1500,  1506,  1522,  1514,  1408,  1497,  1498,  1499,     0,  1264,
    1260,     0,     0,  1248,   628,     0,     0,     0,     0,     0,
    2136,     4,     8,    10,  1529,  1532,     0,   479,   418,     0,
       0,     0,   987,     0,     0,     0,     0,     0,     0,     0,
     187,   685,     0,     0,   159,   157,     0,     0,   139,     0,
     149,   155,   693,   144,   146,     0,   984,   995,   996,     0,
     420,   343,   348,   608,   342,     0,   345,   350,   479,  1321,
     599,   597,     0,   760,  1039,  1041,     0,   372,  1115,  1113,
    1212,  1213,     0,     0,  1206,     0,     0,     0,     0,   100,
       0,     0,    75,    81,    71,  2150,  2150,   110,   105,   119,
     115,     0,   109,   754,   866,   623,  2150,   856,   855,   864,
     989,     0,     0,   935,   936,   930,   956,   479,  1056,  1052,
    1053,  1055,  2030,   953,  2032,   951,   673,   667,   665,     0,
      24,     0,  2150,  2150,  2150,  2150,   719,   697,   721,   699,
    2150,  2150,  2150,  2150,     0,   692,   696,  2150,   623,   749,
     747,   750,   748,     0,     0,    46,    44,    41,    35,    39,
      43,    38,    31,    40,     0,    34,    37,    32,    42,    33,
      45,    36,     0,    29,    47,   741,     0,   671,  1669,     0,
    1667,  1625,  1665,  1612,  1613,  1605,  1591,  1606,     0,     0,
       0,  1028,  1419,  1422,     0,     0,     0,  1333,  1304,  1692,
    1691,  1690,     0,     0,     0,     0,  1328,     0,  1327,     0,
    1329,  1324,  1325,  1326,  1317,  1313,     0,     0,  1374,     0,
       0,     0,  1600,  1597,  1598,   577,   582,     0,     0,  2150,
    2150,   555,   569,   592,   580,   594,  2150,  2150,   590,   574,
     585,   820,   329,     0,  1583,  1581,  1582,  1578,  1580,  1577,
    1579,  1551,     0,     0,     0,  1661,     0,     0,     0,  1659,
       0,     0,     0,     0,  1641,  1658,     0,  1435,     0,  1542,
    1438,     0,     0,     0,     0,  1430,  1448,  1450,  1452,  1492,
    1491,  1490,  1454,  1470,     0,  1445,  1446,  1620,  1233,     0,
       0,     0,   213,     0,  1183,  1202,   820,     0,  1190,  1183,
       0,     0,  1276,     0,  1278,     0,  1534,     0,  1393,     0,
    1396,  1537,     0,  1400,     0,  1268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1406,     0,  1409,  1410,
       0,  1263,     0,  1257,  1259,  2091,     0,     0,     0,  2138,
       0,     0,  1240,   836,     0,     0,     0,     0,     0,  1291,
    2143,  2142,   607,     0,     0,    48,     0,   690,   689,   688,
    1292,   693,  2150,  2150,   151,   631,   161,   153,   163,   143,
     150,  2150,     0,     0,     0,     0,     0,     0,     0,  1322,
     549,     0,   759,  1037,     0,  2117,     0,    93,   541,     0,
      65,     0,     0,     0,    78,     0,    93,    93,   118,   113,
    2150,  2150,   103,     0,   867,   861,   869,   868,   858,   545,
     916,     0,     0,     0,     0,     0,   675,   654,   668,   624,
     730,     0,   714,   712,   718,   716,     0,  2150,     0,  2150,
     710,   708,   704,   702,   752,   706,    24,   742,     0,     0,
       0,    27,     0,  1672,     0,  1595,     0,     0,  1604,  1587,
    1603,  1423,     0,  1386,     0,  1332,     0,     0,  1688,     0,
    1685,  1609,     0,     0,     0,     0,     0,     0,  2034,  1331,
    1330,  1318,  1316,     0,  1377,     0,  1370,     0,     0,     0,
       0,   579,   576,   571,   573,     0,  2150,  2150,   587,   589,
    2150,  2150,     0,  1569,     0,     0,     0,     0,  1657,  1663,
    1653,  1654,  1655,  1656,  1439,     0,  1433,  1453,     0,  1457,
       0,  1470,  1456,     0,     0,  1471,  1486,  1483,  1484,  1481,
    1489,  1488,  1482,  1485,     0,     0,     0,     0,     0,  1487,
       0,     0,     0,  1427,  1428,  1633,     0,  1447,  1441,  1234,
    1618,  1338,  1334,  1335,  1340,  1339,  1616,  1233,     0,  1181,
    1182,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1180,     0,     0,  1168,  1169,  1170,  1167,  1172,
    1173,  1174,  1171,  1158,  1149,     0,     0,  1205,     0,  2150,
       0,  1144,     0,     0,     0,     0,     0,     0,     0,  1136,
    1137,     0,  1069,     0,  1280,  1418,  1538,     0,  1539,     0,
       0,     0,     0,  1399,  1270,  1398,  1390,     0,     0,     0,
    1527,  1519,  1519,     0,     0,  1519,  1526,     0,  1543,  1405,
    1407,  1411,  1412,  1265,  1261,  1002,     0,   965,     9,     0,
    1233,   837,  1066,   355,  1227,     0,     0,  2134,     0,     0,
     970,    49,     0,   739,   160,   158,     0,  2150,     0,     0,
       0,  2150,   156,   145,     0,   148,   147,     0,   976,   980,
     347,     0,   552,     0,  2150,   761,     0,   623,  1116,     0,
    1207,    70,     0,     0,   101,    68,    93,    76,    82,     0,
     120,   116,   755,  2150,   871,   623,   870,     0,   542,     0,
     785,   786,   784,  1054,   954,   952,   678,   676,     0,   658,
     655,     0,   720,   698,   722,   700,   731,   745,   746,   743,
     744,    30,    28,     0,  1666,  1621,  1592,  1593,  1589,  1595,
       0,  1385,  1625,  1388,     0,  1306,  1301,  1300,  1303,     0,
    1621,     0,     0,  2067,  2065,     0,     0,  2053,  2064,     0,
       0,  2066,     0,     0,     0,     0,     0,  2089,  2063,  2059,
       0,  2051,  2054,  2055,  2062,  2058,  2082,     0,  2044,  2043,
    2047,  2049,     0,  2042,     0,  2045,  2036,  1319,  1314,     0,
    1376,     0,     0,  1601,  1599,   583,   581,   593,   595,   591,
       0,     0,  1624,     0,  1701,     0,     0,  1436,  1455,  1449,
    1451,  1458,  1460,  1458,     0,  1465,  1458,     0,  1463,  1458,
       0,  1473,  1472,     0,  1474,     0,  1426,     0,  1342,  1341,
    1337,  1619,   236,  1175,  1176,  1177,  1179,  1162,  1160,  1159,
    1163,  1164,  1161,  1178,  1165,  1166,  1150,   962,  1185,   959,
       0,     0,  1203,     0,  1148,  1147,  1142,  1140,  1139,  1143,
    1141,  1145,  1146,  1138,  1191,  1395,     0,  1391,  1397,  1541,
    1534,  1401,  1509,     0,  1511,     0,     0,     0,     0,  1517,
    1521,     0,  1501,  1413,  1001,  1241,  1230,     0,    24,     0,
       0,   993,     0,    50,   973,     0,    24,   162,   152,     0,
     633,   635,   164,   154,   739,     0,   346,  1323,     0,  1038,
      24,     0,     0,    66,     0,    79,    88,     0,    72,   862,
     859,   546,  2150,   931,     0,  2150,   674,   653,   659,   623,
    1676,     0,  1674,     0,     0,  1595,  1595,  1588,  1387,     0,
    1389,  1383,     0,  1305,     0,  1686,     0,  2057,  2056,     0,
       0,  1493,     0,  1493,  1493,  1493,  1493,  2060,     0,     0,
    2040,     0,     0,     0,     0,  2069,  2041,     0,     0,     0,
       0,     0,     0,  2035,     0,  1378,  1381,  1365,  1379,  1382,
       0,   831,   830,   330,  1699,  1700,  1440,     0,  1477,  1479,
       0,  1466,  1469,  1468,  1476,     0,  1478,  1458,     0,  1429,
    1336,   214,   964,   963,   961,     0,  1184,  1070,  1074,  1076,
       0,  1080,     0,  1078,  1082,  1071,  1072,     0,   853,     0,
       0,  1535,  1540,     0,  1528,  1520,  1504,  1502,     0,  1505,
     356,   353,     0,   991,     0,     0,     0,   972,   740,   140,
     632,    24,   982,   550,  1035,    67,  1208,    84,     0,     0,
      77,    88,    88,  2150,   543,     0,     0,   677,   732,     0,
    1673,  1622,  1615,  1594,  1590,     0,  1307,     0,  1615,  2080,
       0,     0,  2083,     0,     0,     0,     0,     0,     0,     0,
    2052,  2071,  2072,  2070,  2068,  2050,     0,  2046,  2048,  2037,
    2038,  1320,     0,  1366,  1364,  1602,  1459,  1664,  1461,     0,
    1464,  1462,  1480,     0,   960,  2150,  2150,  1084,  2150,  1086,
    2150,  2150,  1073,  1204,  1192,     0,     0,  1518,   358,   992,
    2133,     0,     0,     0,     0,     0,     0,    55,     0,    54,
       0,    52,     0,     0,   141,  1042,    88,    93,    88,    89,
      83,    73,   860,     0,     0,   679,    24,  1675,  1614,  1623,
    1311,     0,  1308,  1310,  1610,  2081,     0,     0,  2079,     0,
       0,     0,     0,  2061,  2078,     0,  1380,  1467,  1475,  1075,
    1077,  2150,  1081,  2150,  1079,  1083,  1536,  1513,   364,   362,
     354,     0,   360,   366,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   634,   636,  1046,  1036,     0,  1044,
    1209,    85,    80,   544,   932,  2150,   733,     0,  1302,  2077,
    2084,  2073,  2074,  2075,  2076,     0,  1085,  1087,  2150,  2150,
     359,   361,  2150,    53,     0,  2150,  1043,  1045,     0,   675,
    1309,  2039,   365,   363,   367,     0,  1047,    86,   680,   974,
      90,    92,     0,    87,    91
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   816,   817,   818,   819,  1030,  2311,  2312,   207,   344,
     208,  1366,  1367,  2157,  2462,  3399,  2930,  2931,  3305,  3400,
    3401,   820,  1157,  2962,  2687,  3322,  2099,  2685,  3186,  2966,
    3318,  2686,  3187,  3407,  3498,  3510,  3320,  3513,   648,   649,
     650,  1477,  2378,   821,  1488,  1162,  1486,  2107,  2388,  2104,
    2386,  2391,  2691,  1487,  2385,  2108,  2690,   822,    18,    37,
      38,    39,    40,    41,   116,   825,  1090,  2055,  1390,  2338,
    2342,  2343,  2339,  2340,  2937,  2941,  2661,  2653,  2652,  2654,
    2657,   508,   294,   604,   826,    85,    86,    20,    63,   144,
      98,   279,   100,   101,   223,   358,   102,   103,   266,   376,
     252,   994,   542,  2838,   389,   927,  2214,   416,   417,   253,
     367,   360,   362,  1309,  1310,   148,   544,   149,   150,   377,
     254,   255,  2046,   582,   267,   270,   268,   269,   398,   559,
     560,   562,   567,   930,   271,   272,   407,   564,   219,    21,
      82,   180,   181,   182,   936,  2782,   183,   275,   264,   410,
     411,   412,   413,  2068,   827,   828,   829,   830,  1049,  3388,
    3158,  1368,  3450,  3451,  3452,  3489,  3488,  3492,   831,   832,
     833,   834,   835,   836,   837,  1041,   509,  1044,  1360,  1361,
    1399,  1127,  1400,   321,   322,   323,   324,   325,   326,   327,
     466,   510,  1294,   511,   512,   513,   514,   515,   516,   517,
     975,   209,   526,   984,   986,  1967,   210,   522,   981,   521,
     980,   524,   983,   523,   982,   945,   954,   328,   329,   212,
     330,   436,   437,   438,   439,  2092,   838,  3192,  3413,  2978,
     839,  1100,  2070,  2954,  2359,   117,   261,   554,  1900,  1226,
    1227,  1228,  1897,  1898,  2201,  2202,  2203,  2519,  2520,  1901,
    1902,  2197,  2523,  2515,  2209,  2210,  2526,  2527,  2780,  2776,
    2777,   840,  1408,    87,  2041,  2042,  2354,   422,  1082,  1132,
    1013,  1071,  1054,  1091,  2420,   213,  1014,  1008,  2008,  2656,
      89,   331,   841,   842,  1178,  1179,   843,   844,   845,   846,
    1186,  2989,  1210,  3197,  1211,  2134,  1212,  2417,  1213,  2707,
    1214,  2160,   847,  2130,  2706,  2988,  3195,  3194,  3475,   118,
      22,   848,  1384,  2047,  2048,  2150,  1846,  2151,  2152,  2717,
    2719,  2433,  2432,  2437,  2431,  2430,  2423,  2422,  2425,  2424,
    2427,  2429,   849,   850,  1088,   851,  1842,  1193,  3416,   852,
    1454,  3166,  2464,  2465,  2153,  2434,  2394,  2693,  1123,  1436,
    2074,  2362,  2075,  1432,   853,   854,  1171,  2122,  2982,   855,
     856,   857,   858,    23,    68,    24,    25,    26,   119,   120,
     859,   121,    27,   917,    28,   122,   123,   160,   556,  1906,
    2531,  3252,   124,   156,   382,   860,  2634,    29,    30,    31,
      32,    33,    62,    90,   125,   673,  1973,  2586,   861,  1166,
    2398,  2111,  2396,  3323,  2973,  2112,  2395,  2696,  2975,   862,
     863,   864,  1065,  1066,  1490,   126,   262,   555,   921,   922,
    1230,  1904,   865,  1215,  1216,   866,  1854,  1217,   332,    92,
      93,    94,    95,  1497,   186,   140,    96,  1019,   137,   215,
     216,  1498,  1499,  2405,  1500,   670,   671,  1195,   672,  1196,
    2414,  2415,  1501,  1502,  1364,  3118,  3119,  3274,  2017,  1080,
    1081,   867,  1379,  3307,   868,  2949,   869,  1394,  1395,  1396,
    2061,  2059,   870,   871,  2322,  2349,   872,  1342,  2014,   873,
    1124,  1125,   874,  1004,   875,  2475,   876,  3405,  2957,   877,
    2366,  3467,  3468,  3469,  3495,  1129,   878,  1503,  2124,  2409,
    2410,   879,  2034,  1012,  1354,   880,   881,   882,  2588,  3122,
    3285,  3286,  3375,  3376,  3380,  3378,  3381,  3441,  3443,   883,
     884,  1492,  2116,   885,  1494,  1143,  1144,  1145,  1470,   886,
     887,   888,  2085,  1462,  1138,   222,  1146,  1147,   333,  2589,
    2879,  2880,  2863,  1038,  1039,  2584,  2864,  2867,   127,   155,
     548,  1319,  2264,  2881,  3289,   448,   889,  1136,   128,   152,
     545,  1316,  2262,  2868,  3287,  2585,  1161,  2677,  3182,  3406,
    1465,   890,   891,   892,   893,   894,  1052,  2320,  1032,  2316,
     895,  2830,  1026,  1027,  2631,  1993,   896,   897,  1328,  1329,
    1330,  2005,  2301,  1331,  2298,  2002,  1332,  2273,  1994,  1333,
    1334,  1335,  1336,  2267,  1985,   898,  1061,  1043,   899,  1878,
    1879,  2175,  3017,  3214,  2747,  3014,  3421,  3422,  1880,  2182,
    2761,  1860,  2505,  3058,  3244,  2670,  2953,  2506,  1881,  1882,
    2251,  2832,  2833,  2834,  3100,  1883,  1884,  1398,   900,  1094,
     901,  1223,  1885,  1886,  3364,  2188,  2189,  2190,  2508,  2763,
    3247,  3248,  1887,  2485,  2742,  3211,  1995,  1996,  1981,  2597,
    2265,  2598,  1997,  2602,  1998,  2618,  1999,  2619,  2910,  2911,
    2268,  1888,  2169,  2170,  2482,  1889,  2827,  2575,  2823,  2246,
    1949,  2241,  2242,  2243,  2795,  1950,  2247,  2576,  2828,  2565,
    2566,  2567,  2568,  2569,  3258,  3081,  3366,  2570,  3260,  3261,
    2821,  2571,  2822,  2572,  2230,  2294,  2295,  2296,  3146,  2297,
    2907,  2901,  3295,  2599,  3249,  2888,  3050,  2601,  2560,  1272,
     334,  1273,  1934,   459,   946,  1919,  1935,  2541,    61,   902,
     903,  3009,  3206,  2735,  3205,  2193,  2513,  2514,  2739,  2476,
    1890,  2477,  2494,  3020,   607,  2472,  2473,  2252,  2578,  3204,
    3013,  1274,   960,  1275,  1276,  2824,  2573,  1278,  1279,  2232,
    3368,   904,   905,  2162,  2474,  3004,  3201,  3202,  1857,   906,
    1047,  1892,  1893,  2178,  2749,  1894,  1895,  2491,  1962,  2225,
     907,  1174,  1831,  1832,  1833,  2126,  1834,  2127,  1896,  2495,
    3056,  3243,  2758,  3053,  3054,  3055,  3052,  3040,  3041,  3042,
    3043,  3044,  3045,  3343,  1020,  1280,  1022,  2018,  1281,    66,
      50,    80,    77,   909,  1149,  2089,  1387,  1456,   910,   424,
     911,  2645,   912,  2310,  1024,  2020,   913,   914,    44,   549,
     550,   551,   552,   553,   915
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2707
static const short yypact[] =
{
    1664,  1025, -2707, -2707,   368,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   368,  1257, -2707, -2707,  1257, -2707,  1170,
   -2707, -2707, -2707,   426, -2707,  1664, -2707, -2707, -2707, -2707,
   -2707,  2327, -2707, -2707, -2707, -2707, -2707,   454,   506, -2707,
     402, -2707, -2707, -2707, -2707, -2707,   368,    63, -2707,   -12,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  2986,   289, -2707, -2707, -2707, -2707,  1531, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,   368, -2707,
   -2707,    63,    91, -2707,   368,   410,  1170, -2707,    33, -2707,
   -2707, -2707, -2707,   817,    46, -2707, -2707, -2707,   742,   397,
     368, -2707, -2707,   763,   368, -2707, -2707,   368,   368, -2707,
   -2707, -2707, -2707,   368,   368, -2707, -2707, -2707, -2707, -2707,
    1531, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  3693,    46, -2707,   979,  9399, -2707, -2707,   325,
   -2707, -2707,   856,   289,   380, -2707, -2707, -2707, -2707, -2707,
    1428, -2707,   368,   510,   904,   368,  1170, -2707, -2707, -2707,
     368, -2707, -2707,   490,   977, -2707, -2707,   611, -2707,   625,
   -2707,   720, -2707, -2707,   673, -2707,   753, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707,   767, -2707, -2707, -2707,
     768,   789,   803,   806,   818,   824,   837,   849,   853,   868,
    9399,   873,  8689,   882,   906,   909,   925,  1786,  1263, -2707,
   -2707, -2707, -2707,   997, -2707,   125, -2707,  9399, -2707,   135,
   -2707, -2707, -2707,   161, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,   490, -2707,   977, -2707, -2707,   935, -2707,   943,
   -2707,   851, -2707, -2707,   959, -2707,   963, -2707, -2707, -2707,
   -2707,   927, -2707, -2707, -2707, -2707,   990,  1354,   368,  1013,
   -2707,  1170,  1170,  1027,   368, -2707,   692, -2707,   639,  1051,
   -2707,   761,  1109,  1437,  1441,   368,  1448,  1456,  1479, -2707,
     912, -2707,    49,    49,    49,    49,    49,  8689,  1057,  1459,
      49,  8689,  1017,  8689, -2707,  8689,  8689,  8689, -2707, -2707,
   -2707,  1014,  1131,  1134,  8689,  1130,  1149, -2707,  8689,  8689,
    1152, -2707,  1163, -2707,   906,  1166,  1167,  1187,  1188,  1590,
    7693,    71, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  1195, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707,  9399, -2707, -2707,   368,  9399,  1161,
     148, -2707, -2707, -2707, -2707,  1598, -2707, -2707, -2707, -2707,
   -2707,   692, -2707, -2707, -2707,  1599,  1600,   289,  1448,  1607,
    1609,  1028, -2707, -2707, -2707, -2707, -2707,  1587, -2707,  1266,
    1228, -2707,  1299, -2707, -2707, -2707,  1048, -2707, -2707,  1645,
   -2707,  1241, -2707, -2707, -2707, -2707, -2707, -2707, -2707,  1109,
    1241, -2707, -2707, -2707, -2707, -2707, -2707,  1244,   217,   244,
     241, -2707,  2792, -2707, -2707, -2707,  1249,  1667,   247,  1285,
   -2707,  1255, -2707,  -156,   254,  1288,  1295,   258,   268,  4481,
    1298,  -125,   946, -2707, -2707,    79,  1302, -2707, -2707, -2707,
     270,  4526, -2707,  3847,  8038,  4727,  4727,  8689, -2707,  1226,
    8689,  7693,  1264, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
    1072,  1680,  4782,  7693,  1226,  1682,   399,  8689,  8689,  8689,
    8689, -2707,  8689,  8689,  8689,  8689,  8689,  8689,  8689,  8689,
    8689,  8689,  8689,  8689,  8689,  8689,  8689,  8689,  8689, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,  8689,
    8689, -2707, -2707,  1273,  8689, -2707,  8689,  1274, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
     261,  8689,  8689,  8689,  8689,  1786,  8689,  1283, -2707,  9399,
    1260, -2707,  1100,  1698,  1467,   279,   300,   312,  1301,   333,
    1334, -2707,  1105, -2707, -2707,   368, -2707, -2707,   368,  1369,
   -2707,  3969,   380,  6698,  1559,  -239,   368,  1714,    23, -2707,
    1051,  1709, -2707, -2707, -2707, -2707,  1712, -2707,  1716, -2707,
    1723, -2707,   368, -2707,   368, -2707, -2707,  1448,  1724, -2707,
   -2707, -2707, -2707,   368,  9399,    39,    49, -2707, -2707, -2707,
   -2707, -2707, -2707,  1130,  1130,  1725, -2707,  1727,  1179,  1282,
   -2707, -2707, -2707, -2707,  1361,  7693,   -58,  1364,  4914,  1732,
    1130,  1368, -2707,  1380,  1383, -2707,  5030,  7032,  7370,  7420,
    7758,  7871,  8038,  8007,  3421,  8292,  3443,  8777,  8799,  8970,
     834,  4727,  4727,  3533,  3533,  1344,  7693,  7531,  7557,  1226,
    7693,  7587,  1226, -2707,  7693,  7693,  7693,  7693, -2707,  1772,
   -2707,  7693, -2707,   203,  9399,  1759,    23,  1352,  1763, -2707,
    1766, -2707, -2707, -2707,  1767, -2707, -2707, -2707, -2707,  1164,
    1403,  1794, -2707,   368,  1407, -2707, -2707, -2707,  1022,   368,
     156,   368,   368,   156,   156,  1066,   368, -2707,   368, -2707,
   -2707,   368, -2707,   280, -2707, -2707, -2707,   156, -2707, -2707,
   -2707, -2707,   368, -2707, -2707, -2707, -2707,   149,   149,  8689,
   -2707, -2707, -2707, -2707, -2707, -2707,   156, -2707, -2707,   156,
   -2707, -2707,   368, -2707, -2707,   156, -2707, -2707,   261,   156,
   -2707, -2707,  8689,   156,   261,   368,   261,   156, -2707, -2707,
     151,   156,   156,   151,   156,   368,   151,   156, -2707,   156,
     156,   156, -2707, -2707, -2707, -2707,   261,   156, -2707, -2707,
     156,    48,   368, -2707, -2707, -2707, -2707,   156,  1107, -2707,
   -2707, -2707,   156, -2707,  5069,   261,  8689,    49,    49,   156,
   -2707, -2707,  1022,   261,  1122,  8689,  8689, -2707,  1154,  8689,
     156,    63, -2707,  8689,   156,  1785,   261, -2707,   156,  8689,
   -2707,  8689,   149,   368,   156,   368,    49,   156,   368,    49,
   -2707,   368,   240,   261,   261,   261, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707,   273, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707,   650, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,   784, -2707,   368,
   -2707,   605, -2707,  1422, -2707, -2707, -2707,  1513, -2707, -2707,
    1424,  1425,  1426,  1429, -2707, -2707,  1196,  1819,  1432,  1433,
     879, -2707,  1396, -2707, -2707, -2707,  1202, -2707,  1438, -2707,
    1809, -2707,  1247, -2707, -2707,  1214, -2707, -2707, -2707, -2707,
    9080, -2707,  1014,  1449, -2707,  1014, -2707,  1014,  1014,  1014,
    1014,  1014,  1820,  1822,  1826,  8689,  1451,  1830,  8689,  1463,
    1465,  1468,  1475,  1480,  1482,  8689,  8689, -2707,   207, -2707,
    1573, -2707,  1486,  1487,  1258,  1489, -2707,   368, -2707,   368,
    1491, -2707, -2707, -2707, -2707,   212,  1453, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707,  1268,  1305,  1430, -2707,
    1276, -2707,  1270, -2707,  1884,  -167,   350, -2707, -2707, -2707,
    1476, -2707,  1337, -2707,  1416,   205, -2707, -2707, -2707,  1503,
   -2707,  7693, -2707, -2707, -2707,  8149, -2707, -2707, -2707,   261,
   -2707, -2707,  1337, -2707,   -61, -2707, -2707,  1636, -2707,    76,
   -2707,  1444, -2707, -2707, -2707, -2707,  1902, -2707, -2707,   498,
   -2707,  1290, -2707,  1292,  1902, -2707,  1311, -2707, -2707,  1490,
     113, -2707,  1457, -2707,  1259, -2707, -2707, -2707, -2707,  1262,
     417,  -171, -2707,  1268,  1597, -2707,  8689,  8689, -2707,  1909,
     156, -2707, -2707, -2707, -2707, -2707,    35,    35,    35, -2707,
      35,  1470,    35,    35,  1327,   -61,  1327,  1327,  1133,  1133,
    1327,  1327,   -61, -2707,  1922, -2707,   712,  1923, -2707,   -61,
      86,    52, -2707, -2707,  8689, -2707, -2707, -2707,  1050, -2707,
   -2707,   380,  1544,   380,  8689, -2707,    82, -2707, -2707,  8689,
    1500,  1514,  1515,  1520,  1346,  1525,  1122, -2707,  1592,  1055,
    1370, -2707,  1386, -2707, -2707, -2707,  1172, -2707,  1963, -2707,
    1959,   368, -2707,   401,  6073,  1397, -2707, -2707,  1970, -2707,
    1317,  1970,  1974,  1321,  1970,  1974,  8689,  1970, -2707, -2707,
     205,   261, -2707, -2707,  1562,   535, -2707, -2707, -2707, -2707,
   -2707,  1551,   261,  8689,  1555, -2707, -2707,  1962,  1964,  1926,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,  1185,  1185,
     156,   156,   156,  2066, -2707, -2707,  1897,   784, -2707, -2707,
     654, -2707, -2707, -2707,  1535, -2707, -2707, -2707, -2707,  3693,
    1448, -2707, -2707,  1379,   368,  1156,  1130,  1410,  1440, -2707,
    9240,  9240, -2707,  1268, -2707, -2707,  1160, -2707, -2707,  8761,
    1571, -2707,  1574,  1577, -2707,  1578,  1581,  1582,  1583,   368,
     -47, -2707, -2707, -2707, -2707,   112, -2707,   368,  2574, -2707,
    1594, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707,  7693,   351, -2707, -2707,   369, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,  1545, -2707,   376,
   -2707, -2707, -2707, -2707, -2707, -2707,  1170, -2707, -2707,  1170,
     636,   145,  1991, -2707, -2707,   256,   155,   494,  2019, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,  1505,  1305,  1270,
   -2707,  1066,  -230,  1136,   368, -2707, -2707,   368, -2707,  1445,
    1405,  1452,  1603, -2707,  1612,    88, -2707, -2707, -2707, -2707,
   -2707,  2040, -2707, -2707,  1420,  1616, -2707, -2707, -2707,  1066,
    1198, -2707,  1198,  1122,   151,  8689,  8689,  8689,  1617, -2707,
   -2707,   261,   261, -2707,  1435,  1122,    49,  1388,    48,   261,
   -2707,  1431,  8689,  1704, -2707, -2707,  1498, -2707, -2707,  2054,
   -2707,   108,   205, -2707, -2707,  2046,  2048, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,   687, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  5069, -2707,  1133,  8689,   -71,
    2039,  2042, -2707, -2707, -2707, -2707, -2707,   103, -2707, -2707,
   -2707, -2707,  1917, -2707,  1854, -2707, -2707, -2707,  8689,   149,
   -2707, -2707,   368,  2049,    49,    49, -2707,  1485, -2707,    49,
    1454,   261, -2707,   368,   368,  8689,   -79, -2707,  1497, -2707,
     269, -2707,  1596, -2707,  1601,  8689,   891, -2707, -2707,  1460,
   -2707,  2075, -2707,  1537, -2707,   261, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  5407, -2707, -2707, -2707, -2707,   368,    49,    49,   242,
     535,  1936,  1812,   261,   205, -2707,  1541, -2707, -2707,  2054,
    2068,  1691, -2707, -2707, -2707, -2707, -2707,  1773,  1773, -2707,
     175,  1548, -2707,   368, -2707, -2707,  1337,  1337, -2707, -2707,
   -2707,   368, -2707,   368,   -58,  1337, -2707,   649, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  1145, -2707, -2707, -2707, -2707, -2707,   248,   248,   658,
     846, -2707,   709, -2707,   654, -2707,  1170,  2074, -2707, -2707,
    1139,  1708,  1670, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  1518, -2707, -2707, -2707,  1943,  1943, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  1477,   -58,  1713,   894,    22,
    9080,    22,    22,    22,    22,  1484,  9080,  9080,   167,  1580,
     496, -2707,  9080,  9080,  9080,  9080, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707,  1066,  8689, -2707, -2707,  1718,  2074, -2707,
   -2707, -2707, -2707,  1170, -2707, -2707,  1337, -2707,   781, -2707,
    1681, -2707, -2707,   781, -2707, -2707, -2707,  1688,  1689,   547,
    1692,  1701,  1810, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
     368, -2707, -2707,   547,  1447, -2707,   212, -2707,  1741,    46,
    1504, -2707,  1122,  1557, -2707, -2707,  1676, -2707, -2707, -2707,
    1593, -2707,   368,   368,   368, -2707, -2707, -2707,  8149,   368,
   -2707,  1524, -2707, -2707, -2707, -2707,  1517, -2707,  2145,  2146,
   -2707,  2148,  1575,  8689, -2707, -2707,  1533,  2156, -2707,  1678,
    1538,  1974, -2707, -2707,  1540,  1123,   368, -2707, -2707,  1737,
     156,   860,  8689, -2707,   368,   368,  8689,    45,   -61,  2167,
    2166,  2149,  2153,  1470, -2707, -2707, -2707, -2707, -2707,   261,
    1644, -2707, -2707,  2117,  8689,   380,   948, -2707, -2707,  1858,
    2181,  2183,   404, -2707,   422,   368,  1796,  1122, -2707,  8689,
    1758,  1761, -2707, -2707,  1833, -2707,  8689,   -50, -2707,  1608,
   -2707, -2707,   714, -2707,  8689, -2707, -2707,  1568,   979, -2707,
    1175,   368,  2182,  8901, -2707, -2707,  1066,   261, -2707, -2707,
      31, -2707,  1974,  1974,  1536, -2707,  1646,  1651, -2707, -2707,
   -2707, -2707,    49,    49, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  1140, -2707, -2707, -2707, -2707,    49,  9371,  2200,  2184,
   -2707,  1122,   839,   180,   183,  2106,    26,  1022, -2707,   -25,
   -2707, -2707, -2707,  1776,    38,  1337,   120, -2707,  1602,  1584,
   -2707, -2707,   793, -2707, -2707, -2707, -2707,  1781,  1588,  2210,
   -2707,  1561, -2707, -2707, -2707, -2707,   261,   147, -2707, -2707,
   -2707,  1576,   846, -2707,   368,   368, -2707, -2707,   368,   425,
   -2707, -2707, -2707, -2707,  1789, -2707, -2707, -2707,  2194, -2707,
   -2707,  1289,  9080, -2707,   449,  1828,  2219, -2707, -2707, -2707,
    9080, -2707,   429,  9080,  9080,  9080,  9080,   368,   430, -2707,
     230,  2220, -2707, -2707,   368,  4658, -2707,  1865,   368,  1618,
      22,  1895, -2707, -2707, -2707, -2707, -2707, -2707,  7693, -2707,
    1811, -2707,  1775, -2707,  1780, -2707,  1816,   434, -2707,  4658,
     452,   170,   170,   453, -2707,   170,  4658, -2707, -2707,  1160,
    1160, -2707,  1823, -2707,  1825,  1831, -2707,  1832,  1834, -2707,
    1837, -2707, -2707, -2707,    50, -2707, -2707, -2707,   455, -2707,
   -2707,   457,   368, -2707, -2707,  1136,  2262,  1122,  9399,  8689,
   -2707,  2268, -2707, -2707, -2707, -2707,   547, -2707, -2707,  1654,
     547,   198, -2707,  1122,  8689,  8689,  8689,  8221,  2271,   164,
   -2707, -2707,  1122,   368, -2707, -2707,   368,   368, -2707,   956,
   -2707, -2707,   857, -2707,  1656,  8689, -2707, -2707, -2707,  2270,
   -2707, -2707, -2707, -2707, -2707,   368,  1974, -2707, -2707,  1726,
   -2707, -2707,   464, -2707, -2707, -2707,   261, -2707,  4352, -2707,
   -2707, -2707,  1953,  2257, -2707,    49,  1939,  1940,  1827,  1665,
    1944,  1859, -2707, -2707, -2707,   472,  1929, -2707, -2707, -2707,
   -2707,  1833, -2707, -2707, -2707,   223,   744, -2707, -2707, -2707,
    2054,  8689,  1866, -2707,  1835, -2707, -2707, -2707, -2707,  2289,
   -2707, -2707, -2707,  1875,  2294, -2707, -2707,  1653, -2707,  2280,
     -61,   368,  2284,  2284,  2284,  2284, -2707,  2302, -2707,  2304,
    2284,  2284,  2284,  2284,   687, -2707, -2707,  2284,   124, -2707,
   -2707, -2707, -2707,  2285,  2297, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707,  2300, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,   465, -2707, -2707, -2707,  2298, -2707, -2707,  1337,
   -2707,   -58, -2707, -2707, -2707, -2707, -2707, -2707,  1730,  1733,
     249, -2707,   -25, -2707,   170,  1722,   156, -2707,  1899, -2707,
   -2707, -2707,   368,   368,  9080,   187, -2707,  8689, -2707,  8689,
   -2707, -2707, -2707, -2707, -2707, -2707,   156,   170, -2707,  1337,
     661,  1720,  1729,  2340, -2707,  2341, -2707,   261,   368,   576,
     576, -2707, -2707,  2343, -2707,  2343,   538,   538,  2343, -2707,
   -2707,  1559, -2707,  1960, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,   112,  1160,  1728, -2707,  1160,  1961,  9080, -2707,
    1965,  1967,  1968,  1972, -2707, -2707,   167, -2707,   167, -2707,
   -2707,  7907,  1920,  2629,  1920,  2350,  2356, -2707, -2707, -2707,
   -2707, -2707, -2707,   869,  9080, -2707,  1918, -2707,  2097,    89,
     180,   368, -2707,  6681,   107, -2707,  1559,  1595, -2707,   107,
     170,   781, -2707,   190, -2707,  1337,   657,  1975,  2364,  1749,
   -2707, -2707,   482, -2707,   547, -2707,   483,   245,  1745,   -68,
    2347,  2347,  2352,  2347,  2347,  2353, -2707,   209, -2707,   781,
     368, -2707,   547, -2707, -2707,  1760,  1122,  2372,   211, -2707,
     368,   500, -2707,  8689,  1989,  2365,   509,  1122,  2379, -2707,
   -2707, -2707, -2707,  8689,  1821,  2112,  8689, -2707, -2707, -2707,
   -2707,   857,  1112,  1112,  2383,   -43, -2707,  2385, -2707, -2707,
   -2707,  1112,   368,  1844,  1184,  2388,   368,  -138,  8689, -2707,
   -2707,  1470, -2707,  1734,  8689, -2707,  2389,  8689, -2707,   261,
   -2707,   280,   368,   261, -2707,  2002,  8689,  8689, -2707, -2707,
     472,  1929, -2707,   687, -2707, -2707,  1218, -2707, -2707,  1824,
   -2707,  9399,  8433,  8901,   261,   261,    72,   866, -2707, -2707,
   -2707,  1777, -2707, -2707, -2707, -2707,    49,  2284,    49,  2284,
   -2707, -2707, -2707, -2707, -2707, -2707,   -61, -2707,  1046,  1071,
    9371, -2707,  2003,  1969,  9080,  1145,   183,   183, -2707, -2707,
   -2707, -2707,   512, -2707,  1932, -2707,   170,     4, -2707,  1778,
   -2707,  2401,  9129,  9129,  9129,  9129,   170,   170, -2707, -2707,
   -2707,  1852, -2707,   513, -2707,  1782, -2707,   368,   368,  1561,
     261, -2707,  2343, -2707, -2707,   368,   538,   538, -2707, -2707,
     538,  2197,  1787, -2707,  2017,  1788,  1289,  1791, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,   515, -2707, -2707,  1941, -2707,
     341,   388, -2707,  4658,  4658, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707,  9240,  9240,  1982,  9240,  1984, -2707,
    9240,   550,  9080,  2414, -2707, -2707,  4658, -2707, -2707, -2707,
   -2707, -2707,  2415, -2707,   347, -2707, -2707,  2097,  1797, -2707,
   -2707,   149,   149,   149,  2396,   149,   149,   149,   149,   149,
     149,  2398, -2707,  2399,   149, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707,  6681, -2707,   261,  1806, -2707,  1979,  2197,
    2403, -2707,  2404,  2405,  2408,  2409,  2410,  2411,  1224,  1595,
   -2707,  1979, -2707,   529, -2707, -2707, -2707,  2416, -2707,  2133,
     170,  1240,   170, -2707, -2707, -2707, -2707,  1289,  2417,  1289,
   -2707,  2436,  2436,   542,  2051,  2436, -2707,  2052, -2707, -2707,
   -2707,   781, -2707, -2707, -2707, -2707,  1122, -2707, -2707,   547,
    2097,  2054, -2707,  1978, -2707,   188,  1122, -2707,  2443,  2020,
   -2707, -2707,  2056,  1903, -2707, -2707,   368,  1112,  9399,  1248,
     368,  1112, -2707, -2707,    49, -2707, -2707,  8689, -2707, -2707,
   -2707,    49,  2054,   261,  2215, -2707,  2431,  1646,  7693,  2434,
   -2707, -2707,   205,  2032, -2707, -2707,  8689, -2707, -2707,  2069,
   -2707, -2707, -2707,   744, -2707,  1646, -2707,  8689, -2707,   216,
   -2707,  1923, -2707, -2707, -2707, -2707, -2707, -2707,  2021,  2116,
   -2707,  2446, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707,   368, -2707,   101, -2707, -2707, -2707,  1145,
     170, -2707,   -58,  2328,   544, -2707, -2707, -2707, -2707,   368,
    1912,  2485,  2485, -2707, -2707,  9212,  2038, -2707, -2707,  2041,
    2045, -2707,  2055,  2059,  2063,  2064,   368,   435, -2707, -2707,
     557, -2707, -2707,  2609, -2707, -2707, -2707,   562,  2466,  2466,
   -2707, -2707,   564,  2467,  2469, -2707,   122, -2707, -2707,   170,
   -2707,   139,  1863, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
    2286,  3693, -2707,  1289, -2707,  1289,   167, -2707, -2707,  2356,
   -2707,  2057,  2574,  2057,   174, -2707,  2057,   174, -2707,  2057,
    9240, -2707, -2707,  9080, -2707,  9080,  2350,    89, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,   437,  2493, -2707,
     261,  1007, -2707,  2286, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707,   222, -2707, -2707, -2707,
    2044, -2707, -2707,  2109, -2707,  2480,  2122,  2123,  2491, -2707,
   -2707,  2125, -2707, -2707, -2707, -2707, -2707,    49,   -61,  2144,
    1122, -2707,  8689, -2707,  1951,  2496,   -61, -2707, -2707,   892,
   -2707, -2707, -2707, -2707,   127,  2131,  1974,  2294,  2287, -2707,
     -61,  2132,  2134,  2167,  2094, -2707,  2190,  2143, -2707, -2707,
   -2707, -2707,  2295,  2079,  8689,  2098, -2707, -2707, -2707,  1646,
   -2707,   567, -2707,   261,  1993,  1145,  1145, -2707, -2707,  9080,
   -2707, -2707,   170, -2707,  2110, -2707,  1993,  2033,  2033,  2150,
     894,    22,  9341,    22,    22,    22,    22,  1925,  9341,  9129,
   -2707,  9341,  9341,  9341,  9341, -2707, -2707,   170,  2533,   170,
    9129,   156,  4658, -2707,   261, -2707, -2707,   295, -2707, -2707,
     368, -2707, -2707, -2707, -2707, -2707, -2707,   209, -2707, -2707,
     575, -2707, -2707, -2707, -2707,   580, -2707,  2057,  2541, -2707,
   -2707, -2707, -2707, -2707, -2707,   261,  2493, -2707, -2707, -2707,
     261, -2707,   261, -2707, -2707,  1753, -2707,  2309, -2707,  2311,
    2530, -2707, -2707,  1934, -2707, -2707, -2707, -2707,  2169, -2707,
   -2707, -2707,  1122, -2707,  2170,  6916,  2136, -2707, -2707, -2707,
    1942,   -61, -2707, -2707, -2707, -2707, -2707, -2707,  2172,   205,
   -2707,  2190,  2190,   744, -2707,  9399,  1992, -2707, -2707,   368,
   -2707,  2294,   496, -2707, -2707,   112, -2707,  8976,   496, -2707,
    2178,  9341, -2707,   588,  9341,  9341,  9341,  9341,   368,   590,
   -2707, -2707, -2707, -2707, -2707, -2707,  2141, -2707, -2707, -2707,
    2350,  2294,   139, -2707, -2707, -2707, -2707, -2707, -2707,   193,
   -2707, -2707, -2707,  9080, -2707,  1296,  1296, -2707,  1296, -2707,
    1296,  1296, -2707, -2707, -2707,  2151,  1289, -2707,  1076, -2707,
   -2707,    35,    35,    35,    35,    35,    35, -2707,  2549, -2707,
     592, -2707,  8689,  1250, -2707,   -11,  2190,  8689,  2190,  2167,
   -2707, -2707, -2707,  2336,   238, -2707,   -61, -2707, -2707, -2707,
   -2707,   595, -2707, -2707, -2707, -2707,  2188,  9341, -2707,  2189,
    2191,  2192,  2195, -2707, -2707,  9129, -2707, -2707, -2707, -2707,
   -2707,  1296, -2707,  1296, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,   840, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  6916, -2707,  2578, -2707, -2707, -2707, -2707,   176, -2707,
   -2707, -2707, -2707, -2707, -2707,    31, -2707,  8976, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,   597, -2707, -2707,   841,   841,
   -2707, -2707,   841, -2707,  8689,   695, -2707, -2707,  2203,    72,
   -2707, -2707, -2707, -2707, -2707,  2204, -2707, -2707, -2707, -2707,
     146, -2707,   205, -2707,  2167
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2707, -2707, -2707, -2707, -2707,   -83, -2707,   -31,  -198, -2707,
   -2707, -1108,   -41, -2707, -2707, -2071, -2707, -2707, -2707, -2707,
    -860, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -1849, -2707,  -968, -2707,
    1619, -2707, -2707, -2707, -2707, -2707, -2707, -2707,   214, -2707,
   -2707, -2707, -2707,  1116, -2707,   499, -2707, -2707,   -57, -2707,
   -2707,  2565, -2707,  2567,  2058, -2707, -2707, -2707, -2707, -2707,
     277,   -49, -2707,   275, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  -137,   442,   322, -2707, -2707,
    2250,    -9, -2707,  2476, -2707, -2707,  2473, -2707,  2391, -2707,
   -2707, -2707, -2707, -2707,  2260,  1981,   656,  2263,  -530, -2707,
   -2707, -2707, -2707, -2707,   665,  -656, -2707, -2707, -2707, -2707,
   -2707, -2707,  -147,  2084,  2406,    42,  2036, -2707,  2081,  1393,
   -2707,  2235, -2707, -2707, -2707, -2707,  2244, -2707, -2707, -2707,
   -2707,  -405, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
    2072, -2707,  2071, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -1309, -2707, -2707,  -805, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  -154, -2707, -2707,   622, -2707,
   -1058, -1102,  1693, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  1673, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
    -613, -2707, -2707, -2707, -2707, -2707,  1864, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  -542, -2707,  -135, -2707, -2707,
   -2707, -2707,  2225, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  1434, -2707, -2707, -2707, -2707,   461, -2707, -2707, -2707,
   -2707, -2707, -1914, -2707, -2707,   450, -2707, -2707, -2707, -2707,
   -2707, -2707, -1057,  -728,   338,   599, -2707,  -278,   363, -1086,
    1173, -2707,   645, -2707, -2327,    -4,  -206, -2707, -2707, -2211,
     260,   743, -2707, -2707,   765,   844, -2707, -2707, -2707, -2707,
   -2707, -2707,   -34, -2707,  -307, -2707,   847, -2707,   551, -2707,
     271, -2707, -2707, -2707, -2707,  -812, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707,   361, -2707, -1800, -2707,   558, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707,  1320, -2707, -2707, -2707, -2707, -2707,
   -2707,  -481, -2707, -2707, -1982, -2707, -2707, -2707, -2707,   383,
   -2147, -2707, -1089, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,  2685, -2707, -2707,
   -2707,  2591,  2682, -2187, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  -407, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
    2686, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,   606, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  -674,  1973, -2707, -2707, -2707, -2707, -2707,  1799,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,  2264, -2707,
   -2707,   -51, -2707, -2707,   603, -2707, -2707, -2707, -1014,  -193,
    2374, -2707, -2707, -2707, -2707,   473, -2707, -1027,  1736,   883,
   -2458,    18, -2707,   607,  1542,  -394,  -546, -2707, -2707, -2707,
    1349, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707,  1287, -2707,  -746, -2707,  -632, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707,  -732, -2707, -2707, -2707, -2707, -2707, -2707,
      34, -2707,  1367,   759, -2707, -2707, -2707, -2707, -2707,  -140,
   -2707,  -541, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,  1610, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,  -529, -2707,  1278,  2279, -2707,
   -2707,  -132, -2707,  -596, -2707, -2707,  -108,   168, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707,   797, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2502, -2707,  1409,   438, -1297, -2707, -2707, -2707,   754,
   -2707, -1925, -2707, -2707, -2707, -1930, -2707, -2707, -1908, -2707,
   -2707, -2707, -2707,   776, -2707, -2707, -2707, -2707, -2707, -2707,
     281, -2707, -2707, -2707, -2707, -2707, -2707,  -715, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707,  -330, -2707, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707,   259, -2707, -2707,
   -2707,  -592, -2707, -2707, -2707, -2707, -2707, -2707,  -121, -2707,
   -2707,   182, -2707,   501, -2707, -2707, -2707, -2707, -2707, -2707,
   -1303, -2707, -2707, -2707, -2707, -1924, -2707, -2707, -2707, -2707,
   -2707, -2707, -2354,   533, -2707, -2493,   600, -2707, -2707, -2209,
     -28,   -27,   219, -2707, -2212, -1856, -2707, -2707,  -309,  -588,
   -2707, -2707, -2707, -2707, -1822, -2707, -2707, -2707, -2139, -2707,
   -2707, -1519, -2707, -1007,   919,  -357, -2101,   191, -2707, -2393,
   -2707, -2707, -2707, -2707,   -16, -2707, -1217, -2596,  2768, -2707,
   -2707, -2707, -2707, -2707, -2707, -2586, -2707,    19, -2707, -1661,
   -2707,  1564, -2707, -2707,   503,   210, -2707, -2167,   208,  -229,
      47,   384, -1837, -2184,   845,  -299,  -594, -1224, -2707,   852,
   -2707, -2707, -2707,   944,  -749, -2707, -2707,  -528,  1585, -2707,
     698, -2707, -2707, -1794,  -214, -2707, -2707, -2707, -2706,  -414,
   -2707, -2707, -2707,   976, -2707, -2707, -2707, -2707, -2707, -2707,
   -2707, -2707, -2707, -2707, -2612,  -431, -2707, -2670, -2235, -1085,
   -1469, -2707, -2707,  -419,  -661,  -621,  -814,   514, -1694,     3,
    2022,   -37, -2707, -2707, -2707, -2707, -2707,  1427, -2707,  -270,
   -2707, -2707, -2707, -2707, -2707, -2707, -2707, -2707,  -304,  1277,
    2266, -2707, -2707, -2707, -2707
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2147
static const short yytable[] =
{
      43,   211,   292,    34,  1340,   425,   426,   575,  1355,    58,
      60,   115,   996,    60,  1403,   427,   428,  1982,  1305,   260,
     440,  1449,  1431,   677,   350,  1352,  1925,  1926,    34,   978,
    2004,   280,  1457,   133,    72,  1141,  1135,  2180,  2542,  1401,
    2136,  2137,    76,    79,   131,  1365,  2027,   937,   320,  2784,
    1410,  1411,   947,  1412,    99,  1433,  1434,   586,    88,   941,
    2593,  1404,    42,   115,  1021,   211,    42,  2607,  2695,  1070,
    2299,   129,    42,  2341,   130,    42,    42,    79,  2300,  2179,
      88,  2274,   211,  3047,  3048,  3049,  2463,  1468,   142,   139,
      42,   586,  1035,  1844, -2145,   298,   146,   518,   597,  2222,
     151,   371,  1045,   153,   154,   598,  1947,  1095,  1448,   157,
     158,  2726,  1040,  2062,  1350,  2831,    42,  1947,  1382,  2233,
    2234,  2235,  2236,   129,   383,   384,  2658,  2479,  1839,   586,
     348,    88,   586,   429,    99,  2986,  1862,   441,   224,   443,
    1099,   444,   445,   446,  3051,  1849,   525,  1021,   256,  3006,
     451,   259,  2517,   348,   462,   463,   263,  1096,  1097,   298,
     351,   352,    42,  1840,  1370,  1371,    42,  1134,  1450,  1451,
    2600,  2603,    42,   298,  2603,  1036,  1063,  2063,    42,  2064,
     355,  2065,    42,    42,  2647,   298,   356,   357,  2486,  1350,
    3074,    42,  1350,  3159,    42,  1350,  2803,    42,   298,  1253,
    1254,    42,  2794,  1339,  2796,  1139,  1176,    42,   348,   211,
      42,  1866,   348,   211,  1201,   353,   348,   298,  1253,  1254,
      42,   348,   568,  1139,  2909,    42,    84,  3290,  2648,   298,
    1188,  1189,    42,   298,  2908,  1254,  2752,  2753,  2754,  2755,
    2756,   372,  2865,   348,  2226,  2483,   572,  2062,  2694,   570,
      42,  2803,   578,  2950,   380,  1350,  1340,    42,  2616,   586,
     386,  2103,    45,   586,   298,  1188,  1189,    42,   594,  1320,
    1321,   414,  3241,   586,  2079,   586,    42,   364,   423,   423,
     423,   423,   423,    42,   658,  2145,   423,  2724,    42,   460,
    2390,  2525,  2109,   605,  2528,  2489,   608,  1322,  1323,  1324,
    3362,  3142,   957,  3144,   584,   660,  1029,    42,   944,  3511,
    2751,  2164,  2165,   616,   617,   618,   619,   143,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,  3101,   653,  3235,   664,  1200,
   -2145,    65,    84,   527,  2781,   637,   638,  2803,  2012,  2083,
     640,   532,   641,   534,  2800,  1347,  1964,  2341,    99,  3038,
    3038,  3038,  3038,  1201,  2898,  1017,  1277,   644,   645,   646,
     647,    84,   651,  1345,  1964,  2069,  1009,  1392,  1201,  1009,
    1009,  1969,  2227,  2743,  1017,  1946,   940,   919,  2013,    84,
    1440,  1441,  2490,  1009,   211,    42,    84,  2805,  2806,  2869,
    2807,  2808,  2809,  2810,  2811,  2812,  2764,  1480,    65,  2375,
     920,   581,  1009,   136,    84,  1009,   925,  2938,  3156,   958,
    2149,  1009,  1346,  3207,  1085,  1009,    67,   586,  2580,  1009,
      35,    84,  2412,  1009,  2548,  2548,  3363,  1009,  1009,  2591,
    1009,    46,    19,  1009,    42,  1009,  1009,  1009,  1393,   211,
     926,  2617,    84,  1009,  2543,    47,  1009,  2591,  2604,  3496,
    2620,   988,  2622,  1009,   301,   585,   595,    19,  1009,  2671,
    2730,    84,  2145, -2145,  1007,  1009,  3012,  3254,  2835,  3255,
      48,  1877,  2119,  1087,  3016,    73,  1009,  2892,  2892,  2600,
    1009,  3512,   135,   136,  1009,  3177,   823,   916,  1868,  2228,
    1009,  1485,  1987,  1009,  2110,  2919,  1006,  1130,  1131,  1204,
    1046,  3235,  3235,  1046,  2919,  1988,    88,  3010,  3059,   211,
    3076,    42,  2951,  1055,  2010,   573,  2080,  1046,    49,   959,
    2106,  1046,   581,  1006,  2890,    36,  1182,  1405,  1072,  1185,
    1844,   669,  2663,  1046,   669,  1055,  2972,  3148,  1201,  3212,
    3005,  1083,   669,   349,  1055,  2355,   908,   918,  2741,  2899,
    3090,  1092,  3229,  3160,  1504,  2245,  1098,  3229,   414,  3237,
     414,  1256,  3329,  1133,    42, -2145,   530,  1983,  2939,   939,
    3369,   943,   423,  2885,  1083,  3369,  1257,  2000,  1083,  1861,
    1256,  1406,  1083,  3427,   964,  3427,   662,  3461,  1055,  1006,
    3477,  1055,  3229,  3246,  2772,  1257,  1256,  2149,    84,  2229,
     569,  1086,  1463,  2166,  1466,    81,  2987,  3096,  1202,  3333,
    3334,  1257,  2866,  2480,  2036,  3355,  1190,  1452,  3038,  3038,
    3180,   987,  3038,  1203,  2734,  1306,  2050,   571,  2896,  2917,
     579,  2813,   953,    97,  3193,  3015,  1936,   587,  3190,  3242,
    3291,   590,  2471,   134,    78,  1874,  3203,  1971,  1204,  3001,
    1948,   591,  2556,   601,  1203,  1937,  3474,   141,  1325,   669,
     599,  1383,   659,  1204,    88,  1005,  2419,  1010,  1011,  3165,
    2011,  1018,  1023,  2240,  1025,    42,  1845,  1028,  1989,    88,
    2913,  3262,   319,   661,  3262,  2518,  2894,  2914,  1011,  2750,
    2037,  1469,  2595,  1372,  1920,  1407,  2004,   942,  2031,   132,
    1909,  3332,  1413,   421,  1453,  1455,   421,   421,  1011,  2077,
    1021,  1874,  3256,  3338,    88,  3167,   665,  2066,  1191,  3172,
      88,  1011,    88,  1990,  3078,  2067,    88,  2109,  1064,    88,
    1987,  1073,    88,  1348,  1965,  3331,  1505,   143,  1021,  1991,
    2529,   145,    88,  1988,  1165,  1326,   319,   423,  1089,  2357,
    2814,  2815,  1966,  3147,  1018,  3485,  3151, -2145,   147,  1970,
     319,    88,  2757,   423,   423,  2419,  2637,  2595,    88,    88,
      88,  2223,   319,  2595,  1159,   217,  3361,    79,   303,  3138,
    3447,  3141,    88,  1987,  1975,   319,  1009,  2376,  1327,  1177,
    3091,  1177,   423,  1389,  1177,   423,  1988,  1177,    88,    88,
      88,    88, -2145,   306,   319,  2377,  1927,  2183,  2816,  2740,
      42,  1293,  2549,  2555,  1293,  1209,   319,  2592,  2248,  3038,
     319,   651,   651, -2145,  1908,  3038,  3038,   138,  3038,  3038,
    3038,  3038,  3419,  1204,    42,  2594,  2605,  3038,  2621,    84,
    2623,  2933,   483,   484,   485,   486,   487,  2672,  2731,  2173,
    2174,   319,  2662, -2145,  3367,  1414,    42,  3228,  2181,   488,
     218,  3259,  3328,  2088,  3264,  2893,  2895,  3266,  2805,  2806,
    2114,  2807,  2808,  2809,  2810,  2811,  2812,  3098, -2145, -2145,
   -2145, -2145, -2145,  2920,  1133,   136,   312,   339,   340,   341,
     342,   343,  2924,   221,  1928,  3011,  3060,  2204,  3077,  3208,
     339,   340,   341,   342,   343,  1229,  1009,  1009,  1009,  1016,
    1929,    42,  3135,  1205,  1206,  1207,  2003,   489,   490,   491,
     492,   493,   494,  1976,  1208,  3149,  3099,  3213,  3092,  1975,
    3093,  2244,   257,   495,   496,   497,  2817,  1506,  3038,  2110,
    3230,  3038,  3038,  3038,  3038,  3236,  1270,  3238,  3245,  3083,
    3330,  3086,   354,  1930,  3089,   432,   359,   613,  3370,  2266,
     433,  1990,   435,  3371,  2370,    42,  3262,  3272, -2145, -2145,
    1507,  3428,  1308,  3434,  2363,  3462,  1218,  1991,  3478,   315,
    3501, -2145,  1415,  1315,  3350,   669,  2835,  1219,  1416,  1417,
    1418,   316,   317,  1931,   184,  3358,    42,  2544,  1845,   318,
    1977,  2249,  2818,  1018,  1859,  1098,  1133,   258,  1419,  2632,
   -2145,   674,  2250,  2632,  1990,  3335,  3273,   265,  1351,   923,
      84,    88,  1932,  3360,  3038,   339,   340,   341,   342,   343,
    1991,  1933,  3038,   273,  2196,    88,  1446,  1002,  1351,    42,
    1220,  2205, -2145,    35,    36,  3372,  2400,   274,  3046,  3046,
    3046,  3046,  2608,  2609,   519,  1221,  2819,  2820,  1978,  3277,
    2206,  2207,  2997,    42,  1437,  3007,  3008,  2397,  1976,  3490,
   -2145,  1444,   430,   431,   498,  1017,    88,   499,  2469,  2184,
    2208,  1016,  2902,    42,  2904,  2905,  2504,  2999,    42,  1447,
    2185,  2184,    88,    88,    88,   277,    88, -2145,    88,    88,
    1087,  3336,  2185,  1979,    88,    88,  2051,  2887,  1375,  2073,
    2334,  2186,  2813,  2335,   387,  1376, -2145,  1420,  2187,  1980,
    1421,  2382,  1093,  2186,    42,  2496,  2145, -2145,  1422,    84,
    2187,  3278,   976,  1006,  2497,   979,  1000,  1139,  2659,    42,
    1478,   388,    88,  1164,  1222,  1977,  2015,  1168,    83,  2215,
      42,  1172,    88,    42, -2145,  3418,    42,  1496,  2488,  2498,
      84,  3424,  2499,  1423,  2138,  3209,  2139,  2140,  2141,  1972,
     276,    42,  1974, -2145, -2145,   278,    88,    88,  3448, -2145,
    2500,  2204,  3449, -2145,   281,  2403,  2093,  1489,    88,    42,
     282,  2096,    42, -2145,  2945,  2094,   500,  3279,  1424,  3280,
    1855,    42,    42,    84,    88,    88, -2145,     2,     3, -2145,
   -2145,   283,   501,  2032,  3281,    42,   502,  2336,  1425,  1426,
    2337,   919,  3282,  2244,  3267,   284,  3283,    84,   285,  1427,
    1911,  2814,  2815,  2974,  1428,    42,  1270,  1270,  2024,  3131,
     286,    42,  2145,  1231,   920,  1270,   287,  1017,  1979,  1150,
    3139,  3284,    84,  2306,   503,  1945,   390,    42,  3170,   288,
    3464,  2149, -2145,  1951,  1980,    42, -2145,    42, -1531, -2145,
   -2145,   289,    59,  1429,    42,   290,  2009,  2334,  2884,   345,
    2335,  2224,   504,     5,     6,  2501,     7,     8,  1017,  2816,
     291,     9, -2145, -2145, -2145,   293,   951,  1243,   952,  1151,
     505,   368,  2710,    84,   335,  1430,  2912,  1984,    10,    11,
    3310,  1992,  2001,  1992,    84,  2004,  2785,  3046,  3046,  2787,
    1016,  3046,    42,    88,  1018,  2205,    12,  1018,   336,  2016,
    2019,   337,  2257,  1025,  -273,    84,  2231,  1152,  2381,  2502,
    2118,   136,  2231,  1277,  2206,  2207,  2503,   338,  2253,  2254,
    2255,  2256,  1350,    84,    42,  1018,    88,   365,    88,    88,
      88,  1476,  2145,    42,  2208,   366,    84,    88,    88,   488,
     379,    88,   423, -2145,   423,    88, -2145,  2149,   399,    84,
    3263,   369,   506,  3263,  2336,   370,  1078,  2337,    88,  3341,
    2745,  3344,  3345,  3346,  3347,  1084,  3453,    13, -2145,    84,
     442,  2142,  2468,  2317,  2143,    84,  2144,  1048,   391,  2145,
    2762,  2481,   378,  3466,  3448,  1224,  1225,  2817,  3449,   346,
   -2145,  1057,  -273,  2191,  2192,  1062,  2145,   489,   490,   491,
     492,   493,   494,    88,  1153,   381,  2146,  1076,  -273,  1180,
    1037,  1037,  1183,   495,   496,   497,   135,   136,   507,   385,
     226,  1034,  2733,   408,  1922,  2435,  1923,   409,  2090,  3453,
     423,   423,  3410,  3411,   415,   423,   400,    88,   432,  2100,
    2101,  1050,   418,   433,   434,   435,  3466,  1482,  2147,  2199,
    2200,  -273,  2148,  2818,  1059,  1413, -2145,   452, -2145,  1438,
    1439,    88,  2765,  1442,  1443,   419,   392,  2149,   227,   228,
    2347,  2348,   196, -2145,   135,   136,  1205,  1206,   229,   347,
    1154, -2145,   393,  1912,   197, -2145,  2226,  1927,  3046,  2411,
    2007,  -273,    42,   420,  3046,  3046, -2145,  3046,  3046,  3046,
    3046,   447,  2219, -2145,  2220,  1037,  3046,  2819,  2820,  2244,
   -2145,  2244,  3217,  3218,  2149,  1192,  2369,  3470,  2627,  3472,
    -273,     1,  1155,   449,   401,   394,   450,  2132,  2133,  -273,
    1181,  2149,  2638,  1184,  2639,  2921,  1187,  1483,     2,     3,
     402,   461,  2955,  2650,   464,   453,  2511,   104,    42,     1,
    3082,  3082,   105,  3082,   498,   465,  3082,   499,   467,   468,
    2981,   454,   373,   374,   375,   395,     2,     3,  3153,    16,
    2952,  1913,  1356,  1357,  1358,  1928,   471,   520,  2996,   469,
     470,   529,  3155,   403,   531,   535,   536,  1914,  1277,  1156,
    2033,  1929,  2033,   539,   396,   540,  2547,   106,   107,  2550,
    2551,  2552,  2553,   397,   455,   108,   543,  3046,  1414,   541,
    3046,  3046,  3046,  3046,     5,     6,  2534,     7,     8,   546,
     547, -2145,     9,   404,  1458,  1459,  1460,  1461,   203,   557,
    1915,   558,   577,   561,  1930,  3263,   566,   576,   580,    10,
      11,   588,     5,     6,   456,     7,     8,   583,   589,   230,
       9,   593,   405,   204,     1,   600,   609,    12,   606,   610,
     611,   406,   614,  1271,  2633,   639,   642,    10,    11,  2960,
    1916,     2,     3,   457,  1931,   652,   500,  2172,  2968,  2969,
     654,   655,   458,  2176,   656,    12,   657,   666,   231,   663,
     668,   675,   501,  3046,   924,   929,   502,   205,   931,  1917,
       4,  3046,   932,  1932,  2535,  2668,   206,   232,  1918,   933,
     938,   948,  1933,   949,   956,  2870,  1009,   961,   963,  1282,
    2536,   965,  1284,   233,  1285,  1286,  1287,  1288,  1289,  2212,
     950,  2871,  2872,   966,   503,  1415,   967,   985,  1192,   989,
    2873,  1416,  1417,  1418,   991,   997,   234,     5,     6,   992,
       7,     8,   993,   995,  2702,     9,   998,  2356,   235,   999,
    1001,  1419,   504,  2537,   339,   340,   341,   342,   343,   236,
    2258,  1169,    10,    11,  2874,  1233,  1234,  1235,  1236,  1237,
     505,  1239,  1238,  2875,  1240,  1241,  1242,   237,  1244,  1245,
      12,  1246,  1177,   423,   423,  1247,  2263,   238,  1248,    88,
      88,  1249,  1283,  2538,  1295,  1290,  2138,  1291,  2139,  2140,
    2141,  1292,  2876,   239,  2346,  1296,  1298,  1015,  1299,  2168,
    1009,  1300,  1351,  1351,  2426,  2428,  3082,  2177,  1301,  2177,
    1033,  1351,  2539,  1302,  2277,  1303,  1307,  2915,  1009,  1311,
    1312,  2540,  1314,  1313,  1318,  1337,  2438,  3278,  2925,  1338,
     136,  1343,  1344,   240,  1341,    88,  1353,  2877,  1051,   109,
    1277,    13,   506,  1369,  1349,  1373,  2216,  1374,  1380,  1377,
    1420,  1378,  1381,  1421,  1068,  1069,   241,  1402,  1385,  1386,
    1075,  1422,  1388,  1077,  1397,  1435,   110,  1445,  1448,  1464,
    2368,   242,  1472,  1192,  1018,  3183,  1270,  1481,   243,  2878,
    3219,   244,  1270,  1270,  1351,   651,  1473,  1474,  1270,  1270,
    1270,  1270,  1475,  3279,  2789,  3280,  1423,  1479,  1098,  1018,
    1308,  1484,   245,  1954,  1955,   246,  1485,   247,   507,  2801,
    3281,  1493,  1351,  1495,  1835,  1836,  1133,  1837,  3282,   586,
    2825,  1838,  3283,  1847,  1843,  1992,   248,  1850,  1851,  1899,
    1852,  1424,  1853,  1271,  1271,  1907,  2001,   111,  3185,  1992,
    1910,  1921,  1271,  1938,   249,  1968,  1939,  3284,    88,  1940,
    1941,  1425,  1426,  1942,  1943,  1944,  1963,  1986,  2313,  2314,
    2315,    14,  1427,  1340,  2006,  2319,  2023,  1428,    51,    52,
      53,    54,    55,    56,    57,  2025,  1956,  1957,  1958,  1959,
    1960,  1961,  2022,  2024,  2026,  2028,   250,  2029,  2030,  2043,
    3301,  1455,  2344,  3233,  3234,  2058,  2060,  2056,  3309,  2062,
    2351,  2352,  2049,   423,  2071,  2081,  1429,  2072,  2082,  2244,
    2084,    15,  3314,  2086,  2091,    88,  2095,  2106,  2097,  2113,
    2121,  2120,    88,  2142,  2115,  2123,  2143,  1845,  2144,  2156,
     112,  2379,  2159,    88,  2158,  2161,  2167,  2678,  1430,   251,
    2213,  2217,  2218,    16,  2221,  2237,  2223,  2245,  2145,  2411,
    2278,  2259,  2302,  2269,    88,  2628,  2404,  1496,  2146,  1270,
    2271,  2272,  1018,    88,  2275,  2305,  1956,  1957,  1958,  1959,
    1960,  1961,    17,  2276,  2304,  2307,  2308,  3342,   423,   423,
    1277,  2309,  2321,  3342,  2323,  1192,  3351,  3352,  3353,  3354,
    2324,  2325,   423,  2326,  2329,  3359,  2327,    88,    88,    88,
    2147,  2330,  2331,    88,  2148,  2332,  2333,  3154,  2279,  2345,
     113,  1351,  1844,   211,  2358,  2360,  1009,  3161,   114,  2361,
    2280,  2365,  1009,  2367, -2145,  1863,  2373,  2512,  2374,  2380,
    2383,  2281,    88,  2384,  2387,  2401,  2407,  1208,  2419,  2421,
    2524,  2524,  1009,  3404,  2524,  2466,  2393,  2478,  2484,  2282,
    2467,  2493,  1037,  2507,  2509,  2510,  2521,  2532,  1270,  2283,
    2533,  2545,  2284,  2492,  2546,  2558,  1270,  2581,  3094,  1270,
    1270,  1270,  1270,  2554,  2574,  2285,  1351,  2583,  2579,  2582,
    2559,  1270,  2587,  2149,  2577,  3103,  3104,  3105,  2590,  3107,
    3108,  3109,  3110,  3111,  3112,  2610,  3426,  2611,  3115,  3429,
    3430,  3431,  3432,  2612,  2613,  1270,  2614,  2596,  2596,  2615,
    2626,  2596,  1270,  2630,  1098,  2635,  2646,  2664,  2666,  2675,
    1133,  2669,  2676,  2286,  2679,  2680,  2682,  2681,  1864,  2683,
   -2145,  2684,  3409,  2700,  2703,  2701,  1865,  2704,  2624,  2705,
    1133,  2016,  1866,    88,  1867,  1207,  2709,  2716,  3476,  2718,
    2727,  2728,  1992,  2287,  2729,  1868,  1992,    88, -2145,    88,
   -2145, -2145, -2145,  2288,  2732,  2596,    91,  2736,    88,  2344,
    2737,  2746,  2655,  2655,  3454,  3455,  3456,  3457,  3458,  3459,
    2744,  2767,  3480,  1869,  2289,  2769,  2770,  2290,  2775,  2291,
    2768,  2667,  2798,  2783,  2788,  2786,  2803,     1,  2790,  1870,
    2791,  2792,    88,  2804,  1871,  2793,  2829,  2826,  2889,  2890,
    2891,   423,  2897,  2900,     2,     3,  1872,  2292,  2903,  2906,
    2916, -2090,  2922,  1873,  2926,  2923,  2293,  2929,  2936,  2928,
    2940,    88,  2944,  2947,  2959,  2967,  3002,  2977,  2991,   185,
     214,  3003,  1042,  2956,  3012,  3019,  1947,  3057, -2145,  3061,
    3072,  3303,  3071,  1936,  3084,  3073,  3087,  2711,  3075,  3095,
    3097,  3106,  3102,  3113,  3114,  1056,  3120,  3121,  3124,  3125,
    1976,  3126,  1009,  1009,  3127,  3128,  3129,  3130,  2992,  3471,
    2994,  3145,  3136,  3143,  3150,  3152,  3271,  3157,  3162,  3164,
       5,     6,  3163,     7,     8,  3165, -2145,  3179,     9,  3181,
    3184,  1202,  3188,  3196,   214,  1351,  3199,  3203,  3210,  1128,
    3220,  3229,  3239,  3221,   916,    10,    11,  3222,  1142,  1148,
    2596,   214,  1163,  3240,  3250,  3514,  1167,  3223,  2748,  2177,
    1270,  3224,  1173,    12,  1175,  3225,  3226,  3251,  3275,  3268,
    3257,  2825,  3293,  2596,  2887,  1351,  3294,  1905,  2979,   298,
    1253,  1254,    42,    88,  2524,  3296,  3297,  3298,  3299,  3302,
    2958,  3306,  3308,   651,  3312,  3315,  3317,  3316,  3313,   916,
    1098,  1098,   651,   651,   918,  3319,  3321, -2145,  1874,  3325,
   -2145,  1948,  3337,  3339,  1270,  1875,  3348,  3356,  3373,  3383,
    3023,  3384,  1351,  3389,  1351, -2145,  3385,  1270, -2145,  1270,
   -2145,  3386,  3387,  3403,  3390,  3408,   211,  1876,  3402,  3415,
    1270,  3425,  1877,  3435,  3460,  2596,    88,  2577,  3473,  3446,
   -2145,  3479,  3481,  3494,  3482,  3483,  2596,  1192,  3484,   918,
   -2145,  2596,  1952,  1953,  1954,  1955,  3507,  3509,  2963,  2918,
    1992,  3493,  2105,    74,  1304,  2692,  2392,    75,   214, -2145,
    2651,   824,   214,  2943,  2660,  1277,  2001,   537,  1992,   220,
     225,   533,    88,   361,  2260,   667,  2313,  3231,  3232,  3233,
    3234,   538, -2145,    88,  2261,   565, -2145,   990,  2561,   955,
     363,   928,  1924,   563,   934,   935,  3491,  1250,  1251,  1252,
    2318,  1297,  1158,   298,  1253,  1254,    42,   596,  2344,  2530,
    2946,  1903,  2948,  2522,  2642,  2353,  3253,  1956,  1957,  1958,
    1959,  1960,  1961,  2990,  3174,    88,  1017,    88,  2964,    88,
    2131,  3176,  3198,  1271,    14,  2418,  2135,  3508,  2708,  1271,
    1271,  2649,    88,  3311,  1255,  1271,  1271,  1271,  1271,  1270,
      88,    88,  1956,  1957,  1958,  1959,  1960,  1961,  2053,  2436,
      69,   159,   423,    70,   423, -2145,  3288,    71,  2399,  1074,
    1232,  2402,   528,  2985,    88,    88,  3276,  2155,  2406,  3374,
    1270,  2045,  2076,  1841,    15,  1317,  3497,  2983,  1362,  2035,
    3169,  3134,  2596,  3423,  3382,   615,  2087,  3133,  3037,  3037,
    3037,  3037,  2596,  2596,  1467,  3116,  2021,  2882,  2636,  2270,
    2303,  2738,  3500,  3062,  3063,  2512,    88,  3270,  3137,  2766,
    3436,  3066,  2883,  2557,  2487,  3079,  2606,  3080,  3265,  3438,
    2797,  3437,  2171,  3292,   643,    64,  2886,  1891,  3064,  2837,
    2836,  3216,  2239,   214,  3018,    17,  3269,   574,  2238,  1270,
    1270,  3417,  2163,   211,  1858,  3215,  3340,  2129,  3357,  3349,
    1270,  1270,   651,  1270,  2052,     0,  1270,   676,  1270,  2625,
    1017,     0,  1270,     0,     0,     0,     0,  1128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1142,     0,     0,
       0,     0,  1471,     0,     0,     0,     0,     0,   214,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,  1271,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,  3300,
       0,     0,  1256,  3423,     0,     0,  2596,  3140,  2596,     0,
       0,     0,     0,     0,     0,     0,     0,  1257,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,  3024,  1992,     0,  3025,   214,     0,
       0,     0,    88,     0,  2562,     0,     0,     0,     0,     0,
    3026,     0,  2655,     0,     0,  3171,  2655,  1009,     0,     0,
     423,     0,  1003,     0,     0,     0,  2799,   423,  2802,    88,
       0,     0,     0,     0,     0,     0,     0,  1031,    88,     0,
       0,     0,     0,     0,     0,  1271,     0,     0,     0,     0,
    3028,     0,     0,  1271,     0,     0,  1271,  1271,  1271,  1271,
       0,     0,  3029,     0,     0,     0,     0,     0,  1271,     0,
       0,     0,  1053,     0,     0,     0,     0,     0,  1058,  3200,
    1060,     0,     0,     0,  1067,     0,  2596,  1067,     0,     0,
    1067,    83,  1271,    42,     0,  2748,     0,  3037,  3037,  1271,
    1079,  3037,     0,     0,  3030,     0,  1256,     0,     0,     0,
       0,     0,  3227,     2,     3,  1133,     0,     0,     0,  1126,
       0,  1257,     0,     0,     0,     0,  1003,  1137,  1140,     0,
       0,     0,  1160,   161,     0,  2596,     0,  2168,  1258,     0,
    1170,  2563,     0,  3031,     0,     0,     0,     0,  2038,  2039,
    2040,     0,  1351,  2564,  1260,  3032,  1194,  1197,  1198,  1199,
    1018,     0,     0,  1018,     0,  2057,  1270,  3033,  3034,  1270,
       0,  1270,   162,  2596,     0,  3035,     0,     0,  3036,     0,
       0,  1936,     0,     0,     0,     0,   319,     0,     0,     5,
       6,   163,     7,     8,  1261,     0,    88,     9,     0,     0,
       0,     0,     0,     0,     0,     0,  1262,     0,     0,     0,
       0,     0,  3414,     0,    10,    11,  3039,  3039,  3039,  3039,
       0,  2078,     0,     0,     0,     0,     0,     0,     0,     0,
     164,     0,    12,   423,     0,     0,    88,     0,     0,     0,
       0,  1142,   165,     0,     0,     0,     0,     0,  1263,     0,
       0,     0,     0,   166,  2194,  2195,     0,    84,  2102,     0,
       0,  2211,     0,     0,     0,     0,     0,     0,  2117,     0,
     211,   167,     0,     0,     0,     0,     0,     0,     0,    88,
    3085,   168,  3088,     0,     0,  1270,     0,  1264,  2596,     0,
       0,     0,     0,     0,     0,     0,  1018,   169,  3037,  1265,
       0,     0,     0,    13,  3037,  3037,     0,  3037,  3037,  3037,
    3037,  1266,  1267,  2596,     0,  2596,  3037,  1271,  1270,  1268,
      88,     0,  1269,     0,     0,     0,  3365,     0,     0,     0,
     319,     0,     0,   651,     0,     0,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    88,     0,     0,     0,     0,    88,     0,    88,     0,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1271,     0,     0,     0,   172,     0,     0,    88,  1194,
       0,     0,   173,     0,  1271,   174,  1271,     0,     0,     0,
       0,     0,     0,  1363,     0,    88,     0,  1271,     0,     0,
       0,     0,     0,     0,     0,  3200,   175,     0,     0,   176,
       0,   177,     0,  1270,     0,     0,     0,  3037,     0,     0,
    3037,  3037,  3037,  3037,  3433,     0,     0,     0,     0,     0,
     178,     0,     0,     0,  1391,     0,     0,     0,  2168,     0,
    1271,     0,     0,     0,     0,  1018,  2372,     0,   179,  1270,
    1409,  1409,  1409,     0,  1409,     0,  1409,  1409,     0,     0,
       0,     0,    91,    91,     0,     0,     0,    88,    88,    88,
      88,    88,    88,     0,     0,     0,     0,     0,     0,  3465,
       0,     0,     0,     0,     0,  3039,  3039,  2416,     0,  3039,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1140,     0,     0,  3037,     0,    16,     0,     0,     0,     0,
    1491,  3037,     0,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,  1271,     0,     0,     0,
       0,     0,     0,     0,  1194,  1363,   488,   479,   480,   481,
     482,   483,   484,   485,   486,   487,  1848,     0,     0,     0,
       0,     0,     0,  1270,     0,     0,     0,  1271,   488,     0,
       0,     0,  1856,  1856,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1271,  1271,  1271,  1271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,     0,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,     0,     0,     0,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,  1271,  1271,     0,     0,
       0,     0,   495,   496,   497,   487,     0,  1271,  1271,     0,
    1271,     0,     0,  1271,     0,  1271,     0,     0,   488,  1271,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1037,  1037,  1037,     0,  1037,  1037,
    1037,  1037,  1037,  1037,     0,     0,     0,  1037,     0,     0,
       0,     0,     0,     0,     0,     0,  3039,     0,     0,     0,
       0,     0,  3039,  3039,     0,  3039,  3039,  3039,  3039,     0,
       0,     0,     0,     0,  3039,     0,   489,   490,   491,   492,
     493,   494,     0,     0,    91,     0,    91,  1140,  1067,     0,
       0,     0,   495,   496,   497,  2044,  1079,     0,     0,  1140,
       0,     0,     0,  2054,     0,     0,     0,     0,     0,     0,
       0,     0,  2688,  2689,     0,     0,  1194,     0,     0,     0,
       0,   498,     0,  2698,   499,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   498,     0,     0,   499,     0,     0,  2712,
    2713,  2714,  2715,     0,     0,  1192,     0,  2720,  2721,  2722,
    2723,    91,     0,     0,  2725,     0,     0,     0,     0,     0,
       0,  1362,     0,     0,     0,  3039,     0,     0,  3039,  3039,
    3039,  3039,     0,     0,     0,     0,  2328,     0,     0,     0,
       0,     0,     0,     0,     0,  2098,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2350,     0,     0,     0,  2040,
       0,     0,     0,     0,  1271,  1271,     0,     0,  1271,  2125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   498,     0,     0,   499,     0,     0,     0,
       0,     0,     0,   500,     0,     0,  2773,  2774,     0,  2389,
       0,     0,     0,  2778,  2779,     0,     0,     0,     0,   501,
       0,  3039,     0,   502,     0,   500,     0,     0,     0,  3039,
       0,     0,     0,     0,     0,     0,     0,  1271,     0,     0,
    1271,   501,     0,  1271,     0,   502,  1271,     0,  1271,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   503,   603,   472,   473,   474,     0,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
       0,     0,     0,   503,     0,     0,     0,     0,     0,   504,
       0,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,   504,     0,     0,     0,   500,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,   501,     0,     0,     0,   502,     0,     0,     0,  2934,
    2935,     0,     0,     0,     0,     0,     0,     0,  2942,     0,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
       0,     0,  1271,     0,   161,     0,   495,   496,   497,     0,
       0,     0,     0,   503,     0,  1271,     0,  2970,  2971,     0,
       0,  1271,  1271,     0,  1271,  1271,  1271,  1271,     0,   506,
       0,     0,     0,  1271,     0,  1271,     0,     0,     0,     0,
       0,   504, -2146,   162,  2993,     0,  2995,     0,     0,     0,
    1271,   506,  2629, -2146,     0, -2146, -2146, -2146,     0,   505,
       0,     0,   163,     0,     0,     0,     0,  2640,  2641,  2040,
    2644,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2146,     0,     0,     0,     0,     0,  2665,     0,
       0,     0,     0,     0,     0,   507,     0,     0,     0,     0,
       0,   164,     0,  3067,  3068,     0,     0,  3069,  3070,     0,
       0, -2146,  1192,   165,     0,     0,     0,   507,     0,     0,
       0,     0,     0,     0,   166,     0,     0,     0,     0,     0,
    1271,     0,     0,     0,  1271,     0,     0,  1271,  1271,  1271,
    1271,   506,   167,     0,  2699,     0,     0,   498,     0,     0,
     499,     0,   168, -2146,     0,     0,     0,  2154,  1194,     0,
       0,     0,  1271,     0,     0,     0,  1271,     0,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2146,     0,     0, -2146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,   170,     0,
       0, -2146,     0,  2198,     0,     0,     0,     0,     0, -2146,
    1271, -2146,     0,     0,     0,     0,     0,     0,  1271,     0,
   -2146,   171,     0,     0,     0,     0, -2146,     0,     0,     0,
    2759,     0,  2760,     0, -2146,     0,   172,     0, -2146,     0,
       0,     0,     0,   173, -2146,     0,   174,     0, -2146, -2146,
   -2146, -2146,     0,     0,  3168,     0,     0,     0,  3173,   500,
    1271,     0,     0, -2146,     0,     0,     0,   175,     0,     0,
     176,  3178,   177,     0,     0,   501,     0,     0,     0,   502,
   -2146,     0,     0, -2146,     0, -2146,     0,     0,     0,     0,
    3189,   178, -2146,     0,     0,  1192,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2146,     0,     0,     0,   179,
       0,     0,     0,     0,     0, -2146,  1140,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2146, -2146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,     0, -2146,
       0,     0,     0,     0,     0,     0,     0, -2146,     0,     0,
       0, -2146,     0,   505,     0,     0,     0,     0,     0,     0,
   -2146, -2146, -2146,     0,     0,     0,  2927,     0,     0,  2932,
       0,     0,     0,  2364,     0,     0,     0,     0,     0,     0,
    2371,     0,     0,     0,     0,     0,     0,  2674,   472,   473,
     474,  1140,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,     0,
       0,     0,   185,     0,     0,     0,     0,   488,     0,     0,
       0,  2413,     0,     0,     0,  1128,     0,     0,     0,     0,
   -2146,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0, -2146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1140,  2470,  1140,     0,     0,
       0,  1003,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   489,   490,   491,   492,   493,
     494, -2146,     0,     0,     0,     0,     0,     0,     0,     0,
    2516,   495,   496,   497,     0,     0,     0,     0,     0,  3324,
       0,   507,  3327,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,   473,   474,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2146,     0,     0,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   473,   474,     0,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487, -2146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1140,   214,     0,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,     0,  1140,     0,  1140,     0,     0,
     495,   496,   497,     0,     0, -2146,  1140,     0,     0,     0,
    3412,     0,   498,     0,     0,   499,     0,     0,     0, -2146,
   -2146, -2146, -2146, -2146, -2146, -2146,     0, -2146, -2146,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,     0,
    2673,     0,     0,     0, -2146,   495,   496,   497,     0,     0,
    3175,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3439,  3440,     0,  3442,     0,  3444,  3445,  2697,
       0,     0,     0,     0,     0,     0,     0,  2561,     0,     0,
    3191,     0,     0,     0,     0,     0,  1250,  1251,  1252,     0,
       0,     0,   298,  1253,  1254,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3486,     0,
    3487,     0,     0,  1255,   500,     0,     0,     0,     0,     0,
       0,   498,     0,     0,   499,     0,     0,     0,     0,     0,
     501,     0,     0,     0,   502,     0,     0,   485,   486,   487,
       0,     0,  3499,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,     0,  3502,  3503,     0,     0,  3504,
       0,     0,  3506,     0,     0,     0,   498,     0,     0,   499,
       0,  2771,   503,     0,     0,     0,     0,     0,   472,   473,
     474,     0,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,   488,     0,     0,
     489,   490,   491,   492,   493,   494,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,     0,
       0,     0,     0,     0,  1140,     0,     0,     0,     0,  1017,
       0,     0,     0,   500,     0,  3304,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,   502,   592,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,  3326,     0,     0,
    1140,   495,   496,   497,     0,     0,     0,     0,   500,     0,
       0,  1140,     0,     0,     0,     0,     0,     0,     0,     0,
     506,   503,     0,     0,   501,     0,     0,     0,   502,   602,
     472,   473,   474,     0,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,     0,     0,   504,
       0,     0,     0,  2961,     0,  1031,     0,  2965,     0,   488,
       0,     0,     0,  2562,     0,     0,   503,   505,     0,     0,
    2976,     0,     0,     0,     0,   214,     0,     0,  2984,  2413,
       0,     0,     0,     0,     0,     0,   507,   498,     0,     0,
     499,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,  2998,  3000,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,     0,     0,     0,     0,
       0,     0,   498,     0,  3065,   499,   472,   473,   474,   506,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,  1256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,     0,     0,
    1257,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,  1258,     0,     0,
    2563,     0,     0,     0,     0,  3463,     0,     0,     0,   500,
       0,     0,  2564,  1260,     0,   507,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,   502,
       0,     0,     0,   489,   490,   491,   492,   493,   494,  3117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,  3132,  1261,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,   500,  1262,     0,   503,     0,     0,
       0,     0,     0,     0,   498,     0,     0,   499,     0,     0,
     501,     0,     0,     0,   502,   612,     0,     0,     0,     0,
    1140,     0,     0,     0,     0,   504,     0,  3505,     0,     0,
    1140,     0,     0,     0,     0,     0,     0,  1263,  1101,     0,
       0,     0,   214,   505,     0,     0,     0,  1102,     0,     0,
       0,     0,   503,     0,     0,     0,  1103,  2413,     0,     0,
       0,  1104,     0,     0,     0,     0,  1194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1264,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,  1265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
    1266,  1267,     0,     0,     0,  1105,     0,     0,  1268,     0,
       0,  1269,     0,  1106,     0,     0,     0,     0,     0,   319,
     498,     0,     0,   499,     0,   506,   500,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   501,     0,     0,     0,   502,   962,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,   507,     0,     0,  1108,     0,     0,     0,     0,     0,
       0,  1109,     0,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,   504,  1111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3117,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,  1112,
       0,     0,   500,     0,     0,     0,   507,  1113,     0,     0,
       0,     0,  1508,  1509,  1510,  1511,  1512,  1513,   501,  1514,
    1515,  1516,   502,   968,  1140,  1517,  1518,  1519,  1520,  1521,
    1522,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1523,     0,     0,     0,     0,  1114,     0,     0,     0,     0,
       0,     0,  1524,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,     0,     0,     0,  2413,     0,     0,
    1525,  1115,   506,     0,     0,     0,     0,     0,     0,  1526,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,  1527,     0,  1528,
       0,     0,     0,     0,     0,     0,   505,  1529,  2413,  1116,
       0,     0,  1530,  1531,     0,     0,  1532,  1533,  1534,  1535,
    1117,     0,  1536,  1537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   507,  3117,
       0,     0,     0,     0,  3377,     0,  3379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1538,     0,     0,     0,  1140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1194,     0,  1539,     0,     0,   506,   214,
       0,  1540,     0,     0,     0,     0,     0,  2128,  1541,     0,
    1542,     0,     0,     0,     0,     0,  1543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1118,
    1119,  1120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1544,  1121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   507,  1409,  1409,  1409,  1409,  1409,
    1409,     0,     0,     0,     0,     0,     0,     0,     0,  1545,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1546,     0,     0,     0,     0,     0,  1547,     0,
       0,     0,     0,     0,     0,     0,     0,  1548,  1549,     0,
       0,     0,     0,     0,  1550,     0,     0,  1551,  1552,     0,
       0,     0,  1553,     0,     0,     0,     0,     0,  1554,  1555,
       0,     0,     0,     0,     0,  1556,  1557,  1558,  1559,  1560,
    1561,     0,     0,     0,  1562,  1122,     0,     0,  1563,     0,
    1564,     0,     0,     0,     0,     0,     0,  1565,  1566,  1567,
    1568,     0,  1569,  1570,     0,     0,     0,  1571,  1572,     0,
    1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,     0,     0,
       0,     0,     0,  1581,  1582,  1583,  1194,  1584,  1585,     0,
       0,     0,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,
    1594,     0,  1595,     0,     0,     0,  1596,  1597,  1598,  1599,
    1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,  1608,  1609,
    1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1631,  1632,  1633,     0,  1634,  1635,     0,     0,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,     0,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,     0,     0,  1661,  1662,  1663,
    1664,  1665,  1666,  1667,  1668,  1669,     0,  1670,  1671,  1672,
    1673,     0,  1674,  1675,  1676,  1677,  1678,  1679,  1680,  1681,
    1682,  1683,  1684,  1685,  1686,  1687,  1688,  1689,  1690,  1691,
    1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,  1701,
    1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,     0,  1710,
    1711,  1712,  1713,  1714,  1715,     0,     0,  1716,  1717,     0,
    1718,  1719,  1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,
    1738,  1739,  1740,  1741,  1742,  1743,  1744,     0,     0,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,     0,     0,     0,     0,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1818,     0,     0,     0,
       0,     0,     0,     0,  1819,     0,     0,     0,     0,  1820,
       0,     0,     0,  1821,     0,     0,  1822,  1823,  1824,  1825,
       0,     0,  1826,  1827,     0,  1828,  1829,  1830,  1508,  1509,
    1510,  1511,  1512,  1513,     0,  1514,  1515,  1516,     0,     0,
       0,  1517,  1518,  1519,  1520,  1521,  1522,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1523,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1524,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1525,     0,     0,     0,
       0,     0,     0,     0,     0,  1526,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1527,     0,  1528,     0,     0,     0,     0,
       0,     0,     0,  1529,     0,     0,     0,     0,  1530,  1531,
       0,     0,  1532,  1533,  1534,  1535,     0,     0,  1536,  1537,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1539,     0,     0,     0,     0,     0,  1540,     0,     0,
       0,     0,     0,     0,  1541,     0,  1542,     0,     0,     0,
       0,     0,  1543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1544,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1545,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1546,     0,
       0,     0,     0,     0,  1547,     0,     0,     0,     0,     0,
       0,     0,     0,  1548,  1549,     0,     0,     0,     0,     0,
    1550,     0,     0,  1551,  1552,     0,     0,     0,  1553,     0,
       0,     0,     0,     0,  1554,  1555,     0,     0,     0,     0,
       0,  1556,  1557,  1558,  1559,  1560,  1561,     0,     0,     0,
    1562,     0,     0,     0,  1563,     0,  1564,     0,     0,     0,
       0,     0,     0,  1565,  1566,  1567,  1568,     0,  1569,  1570,
       0,     0,     0,  1571,  1572,     0,  1573,  1574,  1575,  1576,
    1577,  1578,  1579,  1580,     0,     0,     0,     0,     0,  1581,
    1582,  1583,     0,  1584,  1585,     0,     0,     0,  1586,  1587,
    1588,  1589,  1590,  1591,  1592,  1593,  1594,     0,  1595,     0,
       0,     0,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,
    1624,  1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,
       0,  1634,  1635,     0,     0,  1636,  1637,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,     0,  1646,  1647,  1648,  1649,
    1650,  1651,  1652,  1653,  1654,  1655,  1656,  1657,  1658,  1659,
    1660,     0,     0,  1661,  1662,  1663,  1664,  1665,  1666,  1667,
    1668,  1669,     0,  1670,  1671,  1672,  1673,     0,  1674,  1675,
    1676,  1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,
    1686,  1687,  1688,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,
    1706,  1707,  1708,  1709,     0,  1710,  1711,  1712,  1713,  1714,
    1715,     0,     0,  1716,  1717,     0,  1718,  1719,  1720,  1721,
    1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,     0,     0,  1745,  1746,  1747,  1748,  1749,
    1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,     0,     0,     0,
       0,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1818,     0,     0,     0,     0,     0,     0,     0,
    1819,     0,     0,     0,     0,  1820,     0,     0,     1,  1821,
       0,     0,  1822,  1823,  1824,  1825,     0,   678,  1826,  1827,
       0,  1828,  1829,  1830,   679,     2,     3,     0,     0,     0,
       0,     0,     0,   680,     0,  2839,  2840,     0,  2841,  2842,
    2843,     0,     0,     0,     0,   681,   682,     0,   683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   684,     0,     0,     0,     0,     0,     0,   685,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     686,   687,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   689,     0,   690,   691,
     692,     5,     6,   693,     7,     8,   694,     0,   695,     9,
     696,   697,     0,     0,     0,     0,     0,   698,     0,     0,
     699,     0,   700,   701,   702,     0,    10,    11,     0,     0,
       0,     0,   703,     0,   704,   705,     0,   706,  2844,   707,
     708,     0,     0,   709,    12,     0,  2845,   710,   711,   712,
       0,   713,   714,     0,     0,     0,   715,   716,   717,     0,
     718,     0,     0,     0,   719,     0,   720,   721,     0,     0,
       0,     0,   722,     0,     0,     0,   723,     0,     0,   724,
    2846,   725,     0,   726,     0,   727,     0,   728,   729,  2847,
     730,   731,   732,     0,     0,     0,   733,     0,   734,   735,
       0,   736,     0,     0,     0,     0,     0,     0,     0,   737,
     738,     0,     0,     0,     0,     0,     0,     0,  2848,  2849,
       0,     0,   739,     0,     0,   740,   741,     0,     0,   742,
     743,     0,     0,   744,   745,     0,  2439,  2440,  2441,  2442,
    2443,  2444,   746,   747,   748,     0,   749,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   750,   751,   752,     0,
     753,     0,     0,  2850,   754,   755,     0,     0,     0,   756,
       0,     0,     0,     0,     0,     0,     0,   757,     0,     0,
       0,     0,     0,     0,     0,   758,   759,   760,     0,     0,
       0,     0,     0,   761,   762,  2445,     0,     0,     0,   763,
       0,     0,   764,     0,     0,  2851,   765,   766,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   767,   472,   473,
     474,     0,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   768,     0,     0,     0,     0,
       0,     0,     0,   769,     0,     0,     0,   488,     0,   770,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2852,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     0,     0,
     771,     0,   772,   773,     0,     0,     0,     0,     0,     0,
       0,   774,     0,     0,     0,     0,     0,     0,     0,     0,
    3391,     0,     0,     0,     0,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,     0,     0,     0,     0,     0,     0,
     775,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   776,     0,     0,     0,     0,     0,     0,   777,     0,
       0,     0,     0,     0,     0,     0,  3392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   778,   779,     0,     0,     0,   780,     0,     0,
       0,  3393,     0,     0,     0,     0,     0,     0,     0,   781,
    3394,     0,     0,     0,     0,   782,   783,   784,   785,     0,
       0,     0,   786,     0,     0,     0,   787,     0,     0,     0,
       0,     0,     0,   788,   789,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   790,  3395,   791,     0,  2446,
       0,     0,     0,     0,  3396,     0,     0,     0,   792,     0,
     793,     0,  2447,   794,     0,     0,     0,     0,     0,   795,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   498,     0,     0,   499,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   796,     0,     0,   797,     0,
       0,     0,     0,   798,     0,     0,   799,   800,     0,     0,
    2853,  2854,  2855,  2856,  2857,  2858,  2859,  2860,  2861,  2862,
       0,   801,     0,     0,     0,     0,     0,  2448,   802,     0,
       0,     0,     0,     0,  2449,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3397,
       0,   803,   804,   805,   806,   807,   808,   809,     0,     0,
     810,     0,   811,     0,   812,     0,     0,     0,     0,     0,
     813,   814,   815,  2450,     0,     0,   472,   473,   474,     0,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,     0,     0,  2451,     0,     0,
       0,     0,     0,     0,   500,   488,     0,  2452,  2453,     0,
       0,     0,     0,  2454,     0,     0,     0,     0,     0,     0,
     501,     0,     0,  2455,   502,   969,   472,   473,   474,     0,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,  2456,     0,     0,  2457,  2458,
       0,     0,     0,     0,  2459,   488,     0,     0,     0,     0,
       0,     0,   503,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,     0,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   505,     0,
       0,  2460,     0,   489,   490,   491,   492,   493,   494,     0,
    3398,     0,  2461,     0,     0,     0,     0,     0,     0,   495,
     496,   497,     0,     0,     0,     0,     0,   472,   473,   474,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   472,   473,   474,   488,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,     0,   488,   472,   473,   474,     0,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,   488,   499,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,     0,     0,     0,     0,     0,     0,     0,
     489,   490,   491,   492,   493,   494,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,     0,
     498,     0,     0,   499,     0,     0,     0,     0,     0,     0,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   472,
     473,   474,     0,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   488,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   500,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,     0,
       0,     0,   502,   970,     0,   473,   474,     0,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   498,     0,     0,   499,     0,   489,   490,   491,   492,
     493,   494,   500,   488,     0,     0,     0,     0,     0,     0,
     503,     0,   495,   496,   497,     0,     0,   498,   501,     0,
     499,     0,   502,   971,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,   498,     0,     0,
     499,     0,     0,     0,     0,     0,   505,     0,     0,     0,
     503,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
       0,     0,     0,     0,     0,     0,     0,     0,   504,   474,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,   505,     0,     0,     0,
       0,     0,     0,   500,     0,     0,   488,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
       0,     0,     0,   502,     0,  1250,  1251,  1252,   506,   500,
       0,   298,  1253,  1254,    42,     0,     0,     0,     0,     0,
       0,     0,     0,   498,     0,   501,   499,     0,     0,   502,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,   503,     0,     0,   489,   490,   491,   492,   493,   494,
       0,     0,  1255,     0,   973,   501,     0,     0,   506,   502,
     495,   496,   497,     0,     0,     0,     0,   503,     0,   504,
       0,     0,     0,     0,   507,     0,     0,     0,     0,     0,
     974,     0,     0,     0,     0,     0,     0,   505,   498,     0,
       0,   499,     0,     0,     0,   504,     0,   503,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     977,     0,     0,   505,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,   507,   504,     0,     0,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,     0,     0,   505,     0,   500,     0,     0,     0,     0,
       0,     0,     0,   488,     0,     0,     0,     0,     0,     0,
       0,   501,     0,     0,     0,   502,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,  1017,     0,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   495,   496,   497,     0,
       0,   498,     0,   503,   499,     0,     0,     0,     0,     0,
     500,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   501,   495,   496,   497,
     502,   504,     0,     0,     0,   507,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   297,   505,
       0,     0,     0,   298,   299,   300,    42,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2562,     0,     0,     0,     0,     0,     0,   190,
       0,   507,     0,     0,   301,     0,   504,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,     0,     0,     0,
     295,     0,     0,     0,   505,     0,     0,     0,     0,   296,
     297,     0,     0,   500,     0,   298,   299,   300,    42,   192,
       0,   506,     0,     0,     0,     0,     0,   498,     0,   501,
     499,     0,     0,   502,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   190,     0,     0,     0,     0,   301,     0,   498,     0,
       0,   499,     0,   191,     0,     0,     0,     0,     0,     0,
       0,   503,     0,     0,  1256,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,     0,   506,   507,     0,  1257,
       0,   192,     0,     0,     0,     0,     0,   488,     0,   504,
       0,     0,     0,     0,     0,     0,  1258,     0,     0,  2563,
      84,     0,   193,     0,     0,     0,     0,   505,     0,     0,
       0,  2564,  1260,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,   507,     0,     0,   489,   490,   491,   492,   493,
     494,     0,  1261,     0,     0,   501,     0,     0,     0,   502,
       0,   495,   496,   497,  1262,     0,     0,     0,     0,     0,
     500,     0,    84,     0,   193,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,     0,     0,   506,
     502,     0,     0,     0,     0,     0,     0,   503,     0,   194,
       0,     0,   295,     0,   302,     0,  1263,     0,     0,     0,
     972,   296,   297,     0,     0,     0,     0,   298,   299,   300,
      42,     0,     0,     0,     0,   504,     0,     0,   503,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,  1264,     0,     0,     0,     0,
       0,     0,     0,   190,     0,   507,   504,  1265,   301,     0,
       0,     0,     0,     0,     0,   191,     0,   196,     0,  1266,
    1267,   194,     0,     0,   505,     0,   302,  1268,     0,   197,
    1269,     0,     0,     0,     0,     0,     0,     0,   319,     0,
       0,     0,     0,   192,     0,     0,     0,     0,   303,     0,
       0,     0,   498,   304,   195,   499,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,     0,     0,
       0,     0,     0,   306,     0,   506,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,   307,   196,
       0,   308,     0,     0,   309,     0,     0,     0,     0,     0,
       0,   197,     0,   310,   201,     0,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     303,     0,     0,     0,     0,   304,     0,     0,   305,     0,
       0,     0,     0,     0,    84,     0,   193,     0,     0,   198,
       0,   507,     0,  1359,   311,   306,     0,     0,   202,     0,
       0,     0,     0,     0,     0,   199,   312,     0,     0,     0,
     307,     0,     0,   308,     0,     0,   309,   313,     0,     0,
       0,     0,   507,   203,   500,   310,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     501,     0,     0,     0,   502,     0,     0,     0,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,     0,     0,   311,   296,   297,     0,
     202,     0,     0,   298,   299,   300,    42,     0,   312,     0,
       0,     0,   503,   194,     0,     0,     0,     0,   302,   313,
       0,  2643,   205,     0,     0,   203,     0,     0,     0,   315,
       0,   206,     0,     0,     0,     0,     0,     0,     0,   190,
     504,   316,   317,     0,   301,     0,   195,     0,     0,   318,
     314,   191,     0,     0,     0,     0,     0,     0,   505,     0,
     319,     0,     0,     0,     0,     0,     0,     0,     0,  1250,
    1251,  1252,     0,     0,     0,   298,  1253,  1254,    42,   192,
       0,   196,   480,   481,   482,   483,   484,   485,   486,   487,
       0,     0,     0,   197,   205,     0,     0,     0,     0,     0,
       0,   315,   488,   206,     0,   481,   482,   483,   484,   485,
     486,   487,   303,   316,   317,     0,  1255,   304,     0,     0,
     305,   318,     0,     0,   488,     0,     0,     0,     0,     0,
       0,   198,   319,     0,     0,     0,     0,   306,     0,     0,
     506,     0,     0,     0,     0,     0,     0,   199,     0,     0,
       0,     0,   307,     0,     0,   308,     0,     0,   309,     0,
     489,   490,   491,   492,   493,   494,     0,   310,   201,     0,
      84,     0,   193,     0,     0,     0,   495,   496,   497,     0,
       0,     0,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,     0,     0,     0,     0,     0,   507,  2980,   311,  1250,
    1251,  1252,   202,     0,     0,   298,  1253,  1254,    42,     0,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   313,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,  1017,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1255,     0,     0,     0,
       0,     0,   314,     0,     0,     0,     0,     0,     0,   194,
       0,     0,     0,     0,   302,     0,     0,   482,   483,   484,
     485,   486,   487,     0,  1250,  1251,  1252,     0,     0,     0,
     298,  1253,  1254,    42,     0,   488,     0,     0,     0,     0,
       0,     0,   195,     0,     0,     0,   205,     0,     0,     0,
       0,     0,     0,   315,     0,   206,     0,   498,     0,     0,
     499,     0,     0,     0,     0,   316,   317,     0,     0,     0,
       0,  1255,     0,   318,     0,     0,     0,   196,     0,   498,
       0,     0,   499,     0,   319,     0,     0,     0,     0,   197,
       0,     0,     0,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   495,
     496,   497,     0,   304,     0,     0,   305,     0,     0,     0,
       0,     0,  1017,     0,     0,     0,     0,   198,  1250,  1251,
    1252,     0,     0,   306,   298,  1253,  1254,    42,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,   307,     0,
       0,   308,     0,     0,   309,     0,     0,     0,     0,     0,
       0,     0,     0,   310,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1255,     0,  3021,  3022,   500,
       0,     0,     0,   298,  1253,  1254,    42,     0,  1256,     0,
       0,     0,     0,     0,     0,   501,     0,  1017,     0,   502,
       0,   500,     0,  1257,   311,     0,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,   312,   501,     0,     0,
    1258,   502,     0,  1259,  3023,     0,     0,   313,     0,     0,
       0,     0,     0,   203,     0,     0,  1260,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,     0,   499,     0,     0,     0,     0,   314,   503,
    3021,  3022,     0,  1936,     0,   504,   298,  1253,  1254,    42,
       0,     0,     0,     0,     0,     0,  1261,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,   504,  1262,     0,
    1252,     0,     0,     0,   298,  1253,  1254,    42,     0,     0,
       0,  1017,   205,     0,     0,   505,     0,  3023,     0,   315,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   316,   317,     0,     0,     0,     0,     0,  1256,   318,
    1263,     0,     0,     0,     0,  1255,     0,     0,     0,     0,
     319,     0,     0,  1257,     0,     0,     0,     0,     0,     0,
    1017,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1258,     0,     0,  1259,     0,   506,     0,     0,     0,  1264,
       0,     0,   500,     0,     0,     0,  1260,     0,     0,     0,
       0,  1265,     0,     0,     0,     0,     0,   506,   501,  3021,
    3022,     0,   502,  1266,  1267,   298,  1253,  1254,    42,     0,
       0,  1268,     0,  1256,  1269,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,  2408,  1261,     0,  1257,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1262,     0,
     503,   507,     0,  1017,     0,  1258,  3023,     0,  1259,     0,
       0,  2439,  2440,  2441,  2442,  2443,  2444,   187,   188,     0,
       0,  1260,     0,   507,     0,   189,    42,     0,   504,     0,
       0,  1017,     0,     0,     0,     0,     0,     0,     0,     0,
    1263,     0,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
    3420,  1261,     0,     0,     0,     0,     0,     0,     0,     0,
    2445,   191,     0,  1262,     0,     0,     0,  1256,     0,  1264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1265,  1257,     0,     0,     0,     0,     0,     0,   192,
       0,     0,     0,  1266,  1267,     0,     0,     0,     0,  1258,
       0,  1268,  1259,     0,  1269,  1263,     0,     0,     0,     0,
       0,     0,   319,     0,     0,  1260,  1256,     0,   506,     0,
       0,     0,  1017,     0,     0,     0,     0,     0,     0,     0,
       0,  1257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1264,     0,     0,     0,  3024,     0,
       0,  3025,     0,     0,     0,  1261,  1265,     0,     0,     0,
       0,     0,     0,     0,  3026,     0,     0,  1262,  1266,  1267,
       0,     0,     0,     0,     0,     0,  1268,     0,     0,  1269,
      84,     0,   193,     0,   507,     0,     0,   319,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1256,
       0,     0,     0,  3027,  3028,     0,     0,     0,     0,  1263,
       0,     0,     0,     0,  1257,     0,  3029,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1256,     0,     0,
       0,  3024,     0,     0,  3025,     0,     0,     0,     0,     0,
       0,     0,  1257,     0,     0,     0,     0,  3026,  1264,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3030,  1258,
    1265,     0,  1259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1266,  1267,  1936,  1260,     0,     0,     0,   194,
    1268,     0,     0,  1269,     0,     0,     0,  3028,     0,     0,
       0,   319,     0,     0,  2446,     0,     0,  3031,     0,  3029,
       0,     0,     0,     0,     0,     0,     0,  2447,     0,  3032,
       0,     0,   195,     0,     0,  1261,     0,     0,     0,     0,
       0,  3033,  3034,     0,     0,     0,     0,  1262,  1256,  3035,
       0,     0,  3036,     0,     0,     0,     0,     0,     0,     0,
     319,  3030,     0,  1257,     0,     0,     0,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   197,
    3024,     0,     0,  3025,     0,     0,     0,     0,     0,  1263,
       0,     0,  2448,     0,     0,     0,  3026,     0,     0,  2449,
    3031,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3032,     0,     0,     0,     0,   198,     0,     0,
       0,     0,     0,     0,  3033,  3034,     0,     0,  1264,     0,
       0,     0,  3035,   199,     0,  3036,  3028,     0,  2450,     0,
    1265,   200,     0,   319,     0,     0,     0,     0,  3029,     0,
       0,     0,  1266,  1267,   201,     0,     0,     0,     0,     0,
    1268,     0,  2451,  1269,     0,     0,     0,     0,     0,     0,
       0,   319,  2452,  2453,     0,     0,     0,     0,  2454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2455,     0,
    3030,     0,     0,     0,     0,     0,     0,     0,   202,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2456,     0,     0,  2457,  2458,     0,     0,     0,     0,  2459,
       0,     0,     0,   203,     0,     0,     0,     0,     0,  3031,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3032,     0,     0,     0,     0,     0,     0,   204,     0,
       0,     0,     0,  3033,  3034,     0,     0,     0,     0,     0,
       0,  3035,     0,     0,  3036,     0,     0,     0,     0,     0,
       0,     0,   319,     0,     0,     0,  2460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2461,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,     0,     0,
       0,   206
};

static const short yycheck[] =
{
       4,   136,   200,     0,  1018,   283,   284,   412,  1035,    13,
      14,    68,   668,    17,  1100,   285,   286,  1320,   986,   156,
     290,  1129,  1111,   552,   217,  1032,  1250,  1251,    25,   642,
    1327,   178,  1134,    84,    31,   784,   782,  1874,  2222,  1097,
    1840,  1841,    46,    47,    81,  1052,  1355,   577,   202,  2542,
    1107,  1108,   594,  1110,    63,  1112,  1113,     5,    62,    20,
    2269,    26,    27,   120,   685,   200,    27,  2276,  2395,   743,
    2000,    68,    27,  2055,    78,    27,    27,    81,  2003,  1873,
      84,  1989,   217,  2753,  2754,  2755,  2157,     5,    97,    93,
      27,     5,   705,     5,    63,    24,   100,    26,    19,  1936,
     104,   248,   715,   107,   108,    26,     5,   768,     5,   113,
     114,  2438,   708,     5,    25,    26,    27,     5,     5,  1941,
    1942,  1943,  1944,   120,   261,   262,  2337,   101,  1186,     5,
       5,   135,     5,   287,   143,    63,  1222,   291,   147,   293,
     772,   295,   296,   297,  2756,  1203,   344,   768,   152,  2735,
     304,   155,     5,     5,   308,   309,   160,   770,   771,    24,
      25,    26,    27,  1190,    88,    89,    27,   780,    82,    83,
    2271,  2272,    27,    24,  2275,    26,    25,    69,    27,    71,
      19,    73,    27,    27,    20,    24,    25,    26,   150,    25,
    2786,    27,    25,     5,    27,    25,     6,    27,    24,    25,
      26,    27,  2556,  1017,  2558,    25,   802,    27,     5,   344,
      27,   236,     5,   348,   275,   219,     5,    24,    25,    26,
      27,     5,     5,    25,  2617,    27,   191,     5,  2329,    24,
      25,    26,    27,    24,    25,    26,    49,    50,    51,    52,
      53,   250,   135,     5,  1938,  2169,     5,     5,    25,     5,
      27,     6,     5,   391,   258,    25,  1270,    27,   208,     5,
     264,   340,   356,     5,    24,    25,    26,    27,   393,    57,
      58,   275,   150,     5,   345,     5,    27,   235,   282,   283,
     284,   285,   286,    27,     5,   296,   290,  2434,    27,   305,
     340,  2205,    23,   447,  2208,   175,   450,    85,    86,    87,
       5,  2897,   360,  2899,   460,     5,    26,    27,   586,   163,
    2494,   136,   137,   467,   468,   469,   470,     5,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,  2837,   529,  3043,     5,    66,
      92,    19,   191,   347,  2531,   499,   500,     6,   578,  1457,
     504,   360,   506,   362,  2563,     5,     5,  2339,   367,  2752,
    2753,  2754,  2755,   275,   432,   191,   960,   521,   522,   523,
     524,   191,   526,   540,     5,  1402,   680,   548,   275,   683,
     684,     5,   360,  2484,   191,   432,   584,   626,   618,   191,
    1118,  1119,   272,   697,   529,    27,   191,     9,    10,  2586,
      12,    13,    14,    15,    16,    17,  2507,  1156,    86,     5,
     649,   420,   716,   460,   191,   719,   393,   460,  2920,   477,
     431,   725,   589,  3009,   376,   729,     0,     5,  2250,   733,
      28,   191,  2126,   737,     5,     5,   141,   741,   742,     5,
     744,   535,     0,   747,    27,   749,   750,   751,   619,   584,
     427,   401,   191,   757,     5,   549,   760,     5,     5,   283,
       5,   654,     5,   767,    65,   621,   591,    25,   772,     5,
       5,   191,   296,   442,   680,   779,   472,  3073,  2579,  3075,
     574,   506,  1496,   761,   480,    31,   790,     5,     5,  2590,
     794,   345,   459,   460,   798,  2953,   553,   554,   249,   477,
     804,   580,   246,   807,   235,     5,   350,   777,   778,   570,
     716,  3217,  3218,   719,     5,   259,   520,     5,     5,   654,
       5,    27,   660,   729,  1338,   284,   597,   733,   622,   587,
     580,   737,   541,   350,     5,    29,   806,   502,   744,   809,
       5,   545,  2342,   749,   548,   751,  2693,     5,   275,     5,
    2734,   757,   556,   428,   760,   510,   553,   554,  2482,   627,
      10,   767,     5,   375,   163,   527,   772,     5,   572,     5,
     574,   397,     5,   779,    27,   544,   428,   432,   621,   583,
       5,   585,   586,   393,   790,     5,   412,   432,   794,  1221,
     397,   556,   798,     5,   610,     5,   284,     5,   804,   350,
       5,   807,     5,   464,  2518,   412,   397,   431,   191,   587,
     393,   563,  1141,   438,  1143,   627,   544,  2826,   345,  3205,
    3206,   412,   515,   597,  1373,  3237,   386,   541,  3021,  3022,
    2957,   428,  3025,   391,  2471,   428,  1385,   393,   393,   428,
     393,   253,   600,   354,   428,  2746,   472,   393,  2975,   527,
     428,   393,   472,   243,   591,   472,   555,  1313,   570,  2730,
     548,   393,   432,   393,   391,  1259,   428,   621,   456,   673,
     591,   558,   393,   570,   678,   679,   552,   681,   682,   552,
    1341,   685,   686,   516,   688,    27,   151,   691,   432,   693,
    2620,  3084,   621,   393,  3087,   548,  2604,  2622,   702,  2493,
    1374,   619,   613,   627,  1246,   670,  2003,   668,  1369,   618,
    1240,  3204,    25,   668,   628,   663,   668,   668,   722,  1447,
    1341,   472,  3076,  3216,   728,  2936,   393,   619,   488,  2940,
     734,   735,   736,   477,   393,   627,   740,    23,   587,   743,
     246,   745,   746,   393,   393,  3203,   345,     5,  1369,   493,
     325,   354,   756,   259,   791,   543,   621,   761,   762,  2068,
     372,   373,   393,  2902,   768,  3435,  2905,    23,     5,   393,
     621,   775,   585,   777,   778,   552,   578,   613,   782,   783,
     784,   393,   621,   613,   788,   460,  3244,   791,   389,  2890,
    3386,  2892,   796,   246,   158,   621,  1100,   393,   586,   803,
     250,   805,   806,   386,   808,   809,   259,   811,   812,   813,
     814,   815,   340,   414,   621,   393,   367,   168,   430,  2480,
      27,   975,   393,   393,   978,   866,   621,   393,   332,  3222,
     621,   985,   986,   361,  1239,  3228,  3229,    20,  3231,  3232,
    3233,  3234,  3335,   570,    27,   393,   393,  3240,   393,   191,
     393,  2651,    18,    19,    20,    21,    22,   393,   393,  1866,
    1867,   621,     5,   325,  3257,   178,    27,   432,  1875,    35,
      14,  3083,  3199,  1469,  3086,   393,   393,  3089,     9,    10,
    1493,    12,    13,    14,    15,    16,    17,   540,   640,   641,
     642,   643,   644,   393,  1100,   460,   497,    18,    19,    20,
      21,    22,   393,   523,   455,   393,   393,   482,   393,  3010,
      18,    19,    20,    21,    22,   919,  1220,  1221,  1222,    25,
     471,    27,   393,   650,   651,   652,   432,    93,    94,    95,
      96,    97,    98,   297,   661,   393,   589,   393,   388,   158,
     390,  1948,   432,   109,   110,   111,   558,   546,  3341,   235,
     393,  3344,  3345,  3346,  3347,   393,   960,   393,  3059,  2815,
     393,  2817,   219,   514,  2820,    19,   223,   464,   393,  1976,
      24,   477,    26,   393,    26,    27,  3369,   540,   283,   235,
     579,   393,   991,   393,  2073,   393,   336,   493,   393,   590,
     393,   296,   305,   997,  3229,   999,  3097,   347,   311,   312,
     313,   602,   603,   554,    25,  3240,    27,  2224,   151,   610,
     374,   515,   624,  1017,  1220,  1221,  1222,   113,   331,  2316,
     482,   548,   526,  2320,   477,  3209,   589,   537,  1032,   556,
     191,  1035,   583,  3242,  3427,    18,    19,    20,    21,    22,
     493,   592,  3435,   432,   386,  1049,   334,    25,  1052,    27,
     400,   626,   580,    28,    29,  3267,  2114,   432,  2752,  2753,
    2754,  2755,  2279,  2280,   321,   415,   678,   679,   432,    62,
     645,   646,    26,    27,  1115,  2736,  2737,   363,   297,   239,
     239,  1122,    25,    26,   250,   191,  1090,   253,   249,   440,
     665,    25,  2611,    27,  2613,  2614,  2182,    26,    27,   387,
     451,   440,  1106,  1107,  1108,   432,  1110,   363,  1112,  1113,
    1388,  3212,   451,   477,  1118,  1119,  1386,   460,   620,   432,
     164,   472,   253,   167,   432,   627,   431,   440,   479,   493,
     443,  2099,    25,   472,    27,   342,   296,   296,   451,   191,
     479,   134,   639,   350,   351,   642,   673,    25,   192,    27,
    1154,   459,  1156,   790,   504,   374,    20,   794,    25,    20,
      27,   798,  1166,    27,   626,  3332,    27,  1171,  2175,   376,
     191,  3338,   379,   486,    34,  3012,    36,    37,    38,  1316,
     460,    27,  1319,   645,   646,   432,  1190,  1191,   348,   348,
     397,   482,   352,   352,   427,    20,  1474,    25,  1202,    27,
     432,  1479,    27,   665,    20,  1475,   372,   200,   521,   202,
      25,    27,    27,   191,  1218,  1219,   640,    47,    48,   643,
     644,   432,   388,    25,   217,    27,   392,   271,   541,   542,
     274,   626,   225,  2240,  3090,   432,   229,   191,   432,   552,
    1244,   372,   373,    25,   557,    27,  1250,  1251,   591,    25,
     432,    27,   296,   648,   649,  1259,   432,   191,   477,   105,
      20,   254,   191,  2012,   430,  1269,   627,    27,    20,   432,
      20,   431,   431,  1277,   493,    27,   164,    27,   621,   167,
     626,   432,    25,   596,    27,   432,  1337,   164,  2591,    26,
     167,   397,   458,   123,   124,   502,   126,   127,   191,   430,
     432,   131,   648,   649,   192,   432,    24,   428,    26,   155,
     476,   460,  2420,   191,   432,   628,  2619,  1321,   148,   149,
     428,  1325,  1326,  1327,   191,  2622,  2543,  3021,  3022,  2546,
      25,  3025,    27,  1337,  1338,   626,   166,  1341,   432,  1343,
    1344,   432,  1963,  1347,   367,   191,  1940,   193,  2097,   556,
     459,   460,  1946,  1947,   645,   646,   563,   432,  1952,  1953,
    1954,  1955,    25,   191,    27,  1369,  1370,   432,  1372,  1373,
    1374,    25,   296,    27,   665,   432,   191,  1381,  1382,    35,
      26,  1385,  1386,   271,  1388,  1389,   274,   431,   627,   191,
    3084,   432,   558,  3087,   271,   432,   751,   274,  1402,  3221,
    2486,  3223,  3224,  3225,  3226,   760,  3388,   237,   296,   191,
     393,   271,  2161,  2026,   274,   191,   276,   719,   367,   296,
    2506,  2167,   432,  3405,   348,   641,   642,   558,   352,   432,
     134,   733,   455,   288,   289,   737,   296,    93,    94,    95,
      96,    97,    98,  1447,   290,   432,   306,   749,   471,   804,
     707,   708,   807,   109,   110,   111,   459,   460,   624,   432,
      32,   702,  2469,    26,    24,   325,    26,    26,  1472,  3451,
    1474,  1475,  3321,  3322,    26,  1479,   367,  1481,    19,  1483,
    1484,   722,    26,    24,    25,    26,  3468,   432,   348,   643,
     644,   514,   352,   624,   735,    25,   200,   367,   202,  1116,
    1117,  1505,  2509,  1120,  1121,    26,   455,   431,    80,    81,
     650,   651,   358,   217,   459,   460,   650,   651,    90,   522,
     366,   225,   471,   367,   370,   229,  3220,   367,  3222,  2123,
      25,   554,    27,   621,  3228,  3229,   240,  3231,  3232,  3233,
    3234,   527,    24,   431,    26,   802,  3240,   678,   679,  2556,
     254,  2558,  3021,  3022,   431,   812,  2085,  3406,  2307,  3408,
     583,    30,   408,   432,   455,   514,   432,  1837,  1838,   592,
     805,   431,  2321,   808,  2323,  2633,   811,   522,    47,    48,
     471,   432,  2671,  2332,   432,   455,    25,    56,    27,    30,
    2814,  2815,    61,  2817,   250,   432,  2820,   253,   432,   432,
    2702,   471,   675,   676,   677,   554,    47,    48,  2911,   439,
    2668,   455,   109,   110,   111,   455,    26,   422,  2726,   432,
     432,   460,  2919,   514,    26,    26,    26,   471,  2222,   475,
    1370,   471,  1372,    26,   583,    26,  2230,   106,   107,  2233,
    2234,  2235,  2236,   592,   514,   114,    59,  3341,   178,   621,
    3344,  3345,  3346,  3347,   123,   124,   367,   126,   127,   393,
     432,   362,   131,   554,   614,   615,   616,   617,   514,   621,
     514,    26,     5,   432,   514,  3369,   432,   428,   393,   148,
     149,   393,   123,   124,   554,   126,   127,   432,   393,   261,
     131,   393,   583,   539,    30,   393,   432,   166,   472,   627,
      20,   592,    20,   960,  2317,   432,   432,   148,   149,  2677,
     554,    47,    48,   583,   554,   432,   372,  1864,  2686,  2687,
     460,   621,   592,  1870,    26,   166,   259,   393,   300,   428,
     625,   362,   388,  3427,    20,    26,   392,   583,    26,   583,
      76,  3435,    26,   583,   455,  2358,   592,   319,   592,    26,
      26,    26,   592,    26,   393,   160,  2060,   393,    26,   962,
     471,   393,   965,   335,   967,   968,   969,   970,   971,  1906,
     591,   176,   177,   393,   430,   305,   393,     5,  1035,    20,
     185,   311,   312,   313,   432,   621,   358,   123,   124,    26,
     126,   127,    26,    26,  2407,   131,   393,  2067,   370,     5,
     393,   331,   458,   514,    18,    19,    20,    21,    22,   381,
    1964,    26,   148,   149,   219,   393,   303,   393,   393,   393,
     476,   625,   393,   228,     5,   393,   393,   399,   432,   627,
     166,   393,  1836,  1837,  1838,    26,  1973,   409,   591,  1843,
    1844,   627,   393,   554,   393,    25,    34,    25,    36,    37,
      38,    25,   257,   425,  2060,    25,   393,   684,   393,  1863,
    2164,   393,  1866,  1867,  2142,  2143,  3090,  1871,   393,  1873,
     697,  1875,   583,   393,    64,   393,   303,  2626,  2182,   393,
     393,   592,   393,   625,   393,   432,  2156,   134,  2637,   621,
     460,   621,     8,   465,   618,  1899,   480,   302,   725,   368,
    2494,   237,   558,   267,   428,   461,  1910,     5,   597,   619,
     440,   619,   422,   443,   741,   742,   488,     8,   461,   660,
     747,   451,   660,   750,   327,   598,   395,     5,     5,   385,
    2084,   503,   432,  1190,  1938,  2962,  1940,   345,   510,   344,
    3025,   513,  1946,  1947,  1948,  2099,   432,   432,  1952,  1953,
    1954,  1955,   432,   200,  2548,   202,   486,   432,  2164,  1963,
    1969,   591,   534,    20,    21,   537,   580,   539,   624,  2563,
     217,     8,  1976,    14,   577,     5,  2182,   660,   225,     5,
    2574,   660,   229,   432,   422,  1989,   558,   432,    26,    92,
      26,   521,    66,  1250,  1251,   460,  2000,   466,  2966,  2003,
     621,   591,  1259,   432,   576,   460,   432,   254,  2012,   432,
     432,   541,   542,   432,   432,   432,   422,    26,  2022,  2023,
    2024,   357,   552,  3037,     5,  2029,   621,   557,     6,     7,
       8,     9,    10,    11,    12,   432,    93,    94,    95,    96,
      97,    98,   597,   591,   432,     5,   618,   627,   432,   432,
    3158,   663,  2056,    20,    21,   351,   558,   626,  3166,     5,
    2064,  2065,   627,  2067,    18,    26,   596,    19,    26,  3076,
     153,   407,  3180,   219,    25,  2079,   591,   580,   624,   483,
       5,   621,  2086,   271,   483,   548,   274,   151,   276,   548,
     559,  2095,   401,  2097,    26,   322,   548,  2375,   628,   671,
      26,   393,   432,   439,   627,   621,   393,   527,   296,  2703,
     300,   393,   665,   432,  2118,  2308,  2120,  2121,   306,  2123,
     432,   432,  2126,  2127,   432,   621,    93,    94,    95,    96,
      97,    98,   468,   432,   393,   578,   460,  3222,  2142,  2143,
    2734,   548,   618,  3228,   627,  1402,  3231,  3232,  3233,  3234,
       5,     5,  2156,     5,   621,  3241,   581,  2161,  2162,  2163,
     348,     5,   484,  2167,   352,   627,   626,  2916,   358,   432,
     639,  2175,     5,  2308,     8,    26,  2480,  2926,   647,    26,
     370,   537,  2486,    66,   326,   119,     5,  2191,     5,   393,
     432,   381,  2196,   432,   361,   627,    14,   661,   552,   548,
    2204,  2205,  2506,  3311,  2208,     5,   598,   101,   432,   399,
      26,   627,  1469,   432,   626,     5,   640,   428,  2222,   409,
      26,   393,   412,   621,     5,     5,  2230,   332,  2822,  2233,
    2234,  2235,  2236,  2237,   369,   425,  2240,   462,   620,   428,
    2244,  2245,   462,   431,  2248,  2841,  2842,  2843,   432,  2845,
    2846,  2847,  2848,  2849,  2850,   432,  3341,   432,  2854,  3344,
    3345,  3346,  3347,   432,   432,  2269,   432,  2271,  2272,   432,
       8,  2275,  2276,     5,  2480,   621,     5,   621,     8,   326,
    2486,   555,    25,   473,   345,   345,   621,   460,   222,   345,
     361,   432,  3319,   427,     5,   460,   230,   422,  2302,     5,
    2506,  2305,   236,  2307,   238,   652,    26,     5,  3416,     5,
      25,    14,  2316,   503,    14,   249,  2320,  2321,    34,  2323,
      36,    37,    38,   513,    26,  2329,    62,   597,  2332,  2333,
     597,   432,  2336,  2337,  3391,  3392,  3393,  3394,  3395,  3396,
     618,   621,  3427,   277,   534,     5,     5,   537,     5,   539,
     621,  2355,   432,   393,   393,   627,     6,    30,   393,   293,
     393,   393,  2366,     7,   298,   393,   269,   449,   393,     5,
     621,  2375,   627,    26,    47,    48,   310,   567,    26,    26,
       8,   621,   393,   317,     5,    20,   576,   275,     5,   568,
       5,  2395,   548,     5,     5,   393,   393,   573,   621,   135,
     136,   432,   709,   669,   472,   627,     5,   555,   211,   627,
     393,  3160,   625,   472,   432,   627,   432,  2421,   627,     5,
       5,    25,   625,    25,    25,   732,   620,   448,    25,    25,
     297,    26,  2736,  2737,    26,    26,    26,    26,  2716,  3407,
    2718,     5,    26,    26,   393,   393,  3102,   469,     5,   393,
     123,   124,   432,   126,   127,   552,   241,    26,   131,    25,
     428,   345,   393,   442,   200,  2469,    20,   555,   140,   776,
     432,     5,     5,   432,  2531,   148,   149,   432,   785,   786,
    2484,   217,   789,    14,   621,  3512,   793,   432,  2492,  2493,
    2494,   432,   799,   166,   801,   432,   432,   211,     5,  3093,
     443,  3095,   393,  2507,   460,  2509,    26,  1230,  2701,    24,
      25,    26,    27,  2517,  2518,   393,   393,    26,   393,   375,
    2674,   570,    26,  2677,   393,   393,   432,   393,   241,  2586,
    2736,  2737,  2686,  2687,  2531,   345,   393,   242,   472,   460,
     442,   548,   432,   393,  2548,   479,   621,    14,     7,   240,
      65,   240,  2556,  3302,  2558,   271,    26,  2561,   274,  2563,
     276,   627,   393,   621,   394,   393,  2701,   501,   432,   577,
    2574,   393,   506,   432,    25,  2579,  2580,  2581,   242,   428,
     296,   393,   393,     5,   393,   393,  2590,  1844,   393,  2586,
     306,  2595,    18,    19,    20,    21,   393,   393,  2681,  2630,
    2604,  3461,  1486,    38,   985,  2391,  2107,    40,   344,   325,
    2333,   553,   348,  2662,  2339,  3209,  2620,   367,  2622,   143,
     147,   361,  2626,   232,  1968,   541,  2630,    18,    19,    20,
      21,   368,   348,  2637,  1969,   400,   352,   656,     9,   603,
     234,   560,  1249,   399,   572,   574,  3451,    18,    19,    20,
    2028,   978,   788,    24,    25,    26,    27,   432,  2662,  2209,
    2664,  1227,  2666,  2202,  2326,  2066,  3071,    93,    94,    95,
      96,    97,    98,  2707,  2944,  2679,   191,  2681,  2682,  2683,
    1836,  2951,  2989,  1940,   357,  2134,  1839,  3499,  2417,  1946,
    1947,  2330,  2696,  3174,    65,  1952,  1953,  1954,  1955,  2703,
    2704,  2705,    93,    94,    95,    96,    97,    98,  1388,  2151,
      25,   120,  2716,    31,  2718,   431,  3123,    31,  2112,   746,
     921,  2118,   348,  2705,  2728,  2729,  3120,  1844,  2121,  3275,
    2734,  1382,  1445,  1191,   407,   999,  3468,  2703,  1045,  1372,
    2938,  2881,  2746,  3337,  3285,   466,  1468,  2879,  2752,  2753,
    2754,  2755,  2756,  2757,  1144,  2863,  1347,  2589,  2320,  1983,
    2006,  2480,  3477,  2767,  2768,  2769,  2770,  3097,  2889,  2510,
    3362,  2775,  2590,  2240,  2174,  2803,  2275,  2804,  3087,  3373,
    2561,  3369,  1863,  3140,   520,    17,  2595,  1223,  2769,  2581,
    2580,  3020,  1947,   529,  2747,   468,  3095,     5,  1946,  2803,
    2804,  3329,  1858,  2938,  1219,  3019,  3220,  1831,  3239,  3228,
    2814,  2815,  2966,  2817,  1387,    -1,  2820,   551,  2822,  2305,
     191,    -1,  2826,    -1,    -1,    -1,    -1,  1134,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1144,    -1,    -1,
      -1,    -1,  1149,    -1,    -1,    -1,    -1,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2865,    -1,    -1,    -1,    -1,  2123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2878,    -1,    -1,    -1,    -1,  3157,
      -1,    -1,   397,  3477,    -1,    -1,  2890,  2891,  2892,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2916,    -1,   429,  2919,    -1,   432,   654,    -1,
      -1,    -1,  2926,    -1,   295,    -1,    -1,    -1,    -1,    -1,
     445,    -1,  2936,    -1,    -1,  2939,  2940,  3241,    -1,    -1,
    2944,    -1,   678,    -1,    -1,    -1,  2562,  2951,  2564,  2953,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   693,  2962,    -1,
      -1,    -1,    -1,    -1,    -1,  2222,    -1,    -1,    -1,    -1,
     485,    -1,    -1,  2230,    -1,    -1,  2233,  2234,  2235,  2236,
      -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,  2245,    -1,
      -1,    -1,   728,    -1,    -1,    -1,    -1,    -1,   734,  3003,
     736,    -1,    -1,    -1,   740,    -1,  3010,   743,    -1,    -1,
     746,    25,  2269,    27,    -1,  3019,    -1,  3021,  3022,  2276,
     756,  3025,    -1,    -1,   539,    -1,   397,    -1,    -1,    -1,
      -1,    -1,  3036,    47,    48,  3241,    -1,    -1,    -1,   775,
      -1,   412,    -1,    -1,    -1,    -1,   782,   783,   784,    -1,
      -1,    -1,   788,   261,    -1,  3059,    -1,  3061,   429,    -1,
     796,   432,    -1,   578,    -1,    -1,    -1,    -1,  1375,  1376,
    1377,    -1,  3076,   444,   445,   590,   812,   813,   814,   815,
    3084,    -1,    -1,  3087,    -1,  1392,  3090,   602,   603,  3093,
      -1,  3095,   300,  3097,    -1,   610,    -1,    -1,   613,    -1,
      -1,   472,    -1,    -1,    -1,    -1,   621,    -1,    -1,   123,
     124,   319,   126,   127,   485,    -1,  3120,   131,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,
      -1,    -1,  3325,    -1,   148,   149,  2752,  2753,  2754,  2755,
      -1,  1448,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     358,    -1,   166,  3157,    -1,    -1,  3160,    -1,    -1,    -1,
      -1,  1468,   370,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,    -1,    -1,   381,  1897,  1898,    -1,   191,  1485,    -1,
      -1,  1904,    -1,    -1,    -1,    -1,    -1,    -1,  1495,    -1,
    3325,   399,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3203,
    2816,   409,  2818,    -1,    -1,  3209,    -1,   578,  3212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3220,   425,  3222,   590,
      -1,    -1,    -1,   237,  3228,  3229,    -1,  3231,  3232,  3233,
    3234,   602,   603,  3237,    -1,  3239,  3240,  2494,  3242,   610,
    3244,    -1,   613,    -1,    -1,    -1,  3250,    -1,    -1,    -1,
     621,    -1,    -1,  3407,    -1,    -1,    -1,   465,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3275,    -1,    -1,    -1,    -1,  3280,    -1,  3282,    -1,
     488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2548,    -1,    -1,    -1,   503,    -1,    -1,  3302,  1035,
      -1,    -1,   510,    -1,  2561,   513,  2563,    -1,    -1,    -1,
      -1,    -1,    -1,  1049,    -1,  3319,    -1,  2574,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3329,   534,    -1,    -1,   537,
      -1,   539,    -1,  3337,    -1,    -1,    -1,  3341,    -1,    -1,
    3344,  3345,  3346,  3347,  3348,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    -1,    -1,  1090,    -1,    -1,    -1,  3362,    -1,
    2617,    -1,    -1,    -1,    -1,  3369,  2089,    -1,   576,  3373,
    1106,  1107,  1108,    -1,  1110,    -1,  1112,  1113,    -1,    -1,
      -1,    -1,  1118,  1119,    -1,    -1,    -1,  3391,  3392,  3393,
    3394,  3395,  3396,    -1,    -1,    -1,    -1,    -1,    -1,  3403,
      -1,    -1,    -1,    -1,    -1,  3021,  3022,  2130,    -1,  3025,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1156,    -1,    -1,  3427,    -1,   439,    -1,    -1,    -1,    -1,
    1166,  3435,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,  2703,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1190,  1191,    35,    14,    15,    16,
      17,    18,    19,    20,    21,    22,  1202,    -1,    -1,    -1,
      -1,    -1,    -1,  3477,    -1,    -1,    -1,  2734,    35,    -1,
      -1,    -1,  1218,  1219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2752,  2753,  2754,  2755,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3512,    -1,
      -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,  2803,  2804,    -1,    -1,
      -1,    -1,   109,   110,   111,    22,    -1,  2814,  2815,    -1,
    2817,    -1,    -1,  2820,    -1,  2822,    -1,    -1,    35,  2826,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2841,  2842,  2843,    -1,  2845,  2846,
    2847,  2848,  2849,  2850,    -1,    -1,    -1,  2854,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3222,    -1,    -1,    -1,
      -1,    -1,  3228,  3229,    -1,  3231,  3232,  3233,  3234,    -1,
      -1,    -1,    -1,    -1,  3240,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,  1370,    -1,  1372,  1373,  1374,    -1,
      -1,    -1,   109,   110,   111,  1381,  1382,    -1,    -1,  1385,
      -1,    -1,    -1,  1389,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2385,  2386,    -1,    -1,  1402,    -1,    -1,    -1,
      -1,   250,    -1,  2396,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,   253,    -1,    -1,  2422,
    2423,  2424,  2425,    -1,    -1,  2962,    -1,  2430,  2431,  2432,
    2433,  1447,    -1,    -1,  2437,    -1,    -1,    -1,    -1,    -1,
      -1,  2028,    -1,    -1,    -1,  3341,    -1,    -1,  3344,  3345,
    3346,  3347,    -1,    -1,    -1,    -1,  2043,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1481,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2062,    -1,    -1,    -1,  2066,
      -1,    -1,    -1,    -1,  3021,  3022,    -1,    -1,  3025,  1505,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,  2519,  2520,    -1,  2106,
      -1,    -1,    -1,  2526,  2527,    -1,    -1,    -1,    -1,   388,
      -1,  3427,    -1,   392,    -1,   372,    -1,    -1,    -1,  3435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3084,    -1,    -1,
    3087,   388,    -1,  3090,    -1,   392,  3093,    -1,  3095,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   430,     5,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,   458,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,   458,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,   388,    -1,    -1,    -1,   392,    -1,    -1,    -1,  2652,
    2653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2661,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,  3209,    -1,   261,    -1,   109,   110,   111,    -1,
      -1,    -1,    -1,   430,    -1,  3222,    -1,  2690,  2691,    -1,
      -1,  3228,  3229,    -1,  3231,  3232,  3233,  3234,    -1,   558,
      -1,    -1,    -1,  3240,    -1,  3242,    -1,    -1,    -1,    -1,
      -1,   458,    23,   300,  2717,    -1,  2719,    -1,    -1,    -1,
    3257,   558,  2309,    34,    -1,    36,    37,    38,    -1,   476,
      -1,    -1,   319,    -1,    -1,    -1,    -1,  2324,  2325,  2326,
    2327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,  2345,    -1,
      -1,    -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,
      -1,   358,    -1,  2776,  2777,    -1,    -1,  2780,  2781,    -1,
      -1,    92,  3319,   370,    -1,    -1,    -1,   624,    -1,    -1,
      -1,    -1,    -1,    -1,   381,    -1,    -1,    -1,    -1,    -1,
    3337,    -1,    -1,    -1,  3341,    -1,    -1,  3344,  3345,  3346,
    3347,   558,   399,    -1,  2401,    -1,    -1,   250,    -1,    -1,
     253,    -1,   409,   134,    -1,    -1,    -1,  1843,  1844,    -1,
      -1,    -1,  3369,    -1,    -1,    -1,  3373,    -1,   425,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2869,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,   465,    -1,
      -1,   192,    -1,  1899,    -1,    -1,    -1,    -1,    -1,   200,
    3427,   202,    -1,    -1,    -1,    -1,    -1,    -1,  3435,    -1,
     211,   488,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
    2497,    -1,  2499,    -1,   225,    -1,   503,    -1,   229,    -1,
      -1,    -1,    -1,   510,   235,    -1,   513,    -1,   239,   240,
     241,   242,    -1,    -1,  2937,    -1,    -1,    -1,  2941,   372,
    3477,    -1,    -1,   254,    -1,    -1,    -1,   534,    -1,    -1,
     537,  2954,   539,    -1,    -1,   388,    -1,    -1,    -1,   392,
     271,    -1,    -1,   274,    -1,   276,    -1,    -1,    -1,    -1,
    2973,   558,   283,    -1,    -1,  3512,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,   576,
      -1,    -1,    -1,    -1,    -1,   306,  2012,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,   340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,   352,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
     361,   362,   363,    -1,    -1,    -1,  2643,    -1,    -1,  2646,
      -1,    -1,    -1,  2079,    -1,    -1,    -1,    -1,    -1,    -1,
    2086,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,  2097,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2118,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,  2127,    -1,    -1,    -1,  2702,    -1,    -1,    -1,    -1,
     431,    -1,    -1,    -1,    -1,   558,    -1,    -1,    -1,    -1,
      -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2161,  2162,  2163,    -1,    -1,
      -1,  2167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2196,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,  3192,
      -1,   624,  3195,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   544,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2307,  2308,    -1,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,  2321,    -1,  2323,    -1,    -1,
     109,   110,   111,    -1,    -1,   626,  2332,    -1,    -1,    -1,
    3323,    -1,   250,    -1,    -1,   253,    -1,    -1,    -1,   640,
     641,   642,   643,   644,   645,   646,    -1,   648,   649,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
    2366,    -1,    -1,    -1,   665,   109,   110,   111,    -1,    -1,
    2947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3375,  3376,    -1,  3378,    -1,  3380,  3381,  2395,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,
    2977,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3441,    -1,
    3443,    -1,    -1,    65,   372,    -1,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    -1,    -1,   392,    -1,    -1,    20,    21,    22,
      -1,    -1,  3475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,  3488,  3489,    -1,    -1,  3492,
      -1,    -1,  3495,    -1,    -1,    -1,   250,    -1,    -1,   253,
      -1,  2517,   430,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,  2580,    -1,    -1,    -1,    -1,   191,
      -1,    -1,    -1,   372,    -1,  3162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,
      -1,    -1,    -1,   392,   393,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,  3194,    -1,    -1,
    2626,   109,   110,   111,    -1,    -1,    -1,    -1,   372,    -1,
      -1,  2637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,   430,    -1,    -1,   388,    -1,    -1,    -1,   392,   393,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,   458,
      -1,    -1,    -1,  2679,    -1,  2681,    -1,  2683,    -1,    35,
      -1,    -1,    -1,   295,    -1,    -1,   430,   476,    -1,    -1,
    2696,    -1,    -1,    -1,    -1,  2701,    -1,    -1,  2704,  2705,
      -1,    -1,    -1,    -1,    -1,    -1,   624,   250,    -1,    -1,
     253,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2728,  2729,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,  2770,   253,     6,     7,     8,   558,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,   397,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
     412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   558,    -1,    -1,   429,    -1,    -1,
     432,    -1,    -1,    -1,    -1,  3402,    -1,    -1,    -1,   372,
      -1,    -1,   444,   445,    -1,   624,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,   392,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,  2865,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,  2878,   485,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,    -1,   372,   497,    -1,   430,    -1,    -1,
      -1,    -1,    -1,    -1,   250,    -1,    -1,   253,    -1,    -1,
     388,    -1,    -1,    -1,   392,   393,    -1,    -1,    -1,    -1,
    2916,    -1,    -1,    -1,    -1,   458,    -1,  3494,    -1,    -1,
    2926,    -1,    -1,    -1,    -1,    -1,    -1,   539,   129,    -1,
      -1,    -1,  2938,   476,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,   430,    -1,    -1,    -1,   147,  2953,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,  2962,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,    -1,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
     602,   603,    -1,    -1,    -1,   196,    -1,    -1,   610,    -1,
      -1,   613,    -1,   204,    -1,    -1,    -1,    -1,    -1,   621,
     250,    -1,    -1,   253,    -1,   558,   372,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   388,    -1,    -1,    -1,   392,   393,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,
      -1,   292,    -1,   294,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   458,   304,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3120,    -1,    -1,    -1,    -1,    -1,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   330,
      -1,    -1,   372,    -1,    -1,    -1,   624,   338,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,   388,    12,
      13,    14,   392,   393,  3160,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,  3203,    -1,    -1,
      63,   402,   558,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,   476,   100,  3244,   440,
      -1,    -1,   105,   106,    -1,    -1,   109,   110,   111,   112,
     451,    -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   624,  3275,
      -1,    -1,    -1,    -1,  3280,    -1,  3282,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,  3302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3319,    -1,   178,    -1,    -1,   558,  3325,
      -1,   184,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
     193,    -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
     551,   552,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   624,  3391,  3392,  3393,  3394,  3395,
    3396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,    -1,    -1,   281,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   290,   291,    -1,
      -1,    -1,    -1,    -1,   297,    -1,    -1,   300,   301,    -1,
      -1,    -1,   305,    -1,    -1,    -1,    -1,    -1,   311,   312,
      -1,    -1,    -1,    -1,    -1,   318,   319,   320,   321,   322,
     323,    -1,    -1,    -1,   327,   666,    -1,    -1,   331,    -1,
     333,    -1,    -1,    -1,    -1,    -1,    -1,   340,   341,   342,
     343,    -1,   345,   346,    -1,    -1,    -1,   350,   351,    -1,
     353,   354,   355,   356,   357,   358,   359,   360,    -1,    -1,
      -1,    -1,    -1,   366,   367,   368,  3512,   370,   371,    -1,
      -1,    -1,   375,   376,   377,   378,   379,   380,   381,   382,
     383,    -1,   385,    -1,    -1,    -1,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,    -1,   428,   429,    -1,    -1,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,    -1,    -1,   460,   461,   462,
     463,   464,   465,   466,   467,   468,    -1,   470,   471,   472,
     473,    -1,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,    -1,   512,
     513,   514,   515,   516,   517,    -1,    -1,   520,   521,    -1,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,    -1,    -1,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,    -1,    -1,    -1,    -1,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,   652,
      -1,    -1,    -1,   656,    -1,    -1,   659,   660,   661,   662,
      -1,    -1,   665,   666,    -1,   668,   669,   670,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    14,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   105,   106,
      -1,    -1,   109,   110,   111,   112,    -1,    -1,   115,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,
      -1,    -1,    -1,    -1,   191,    -1,   193,    -1,    -1,    -1,
      -1,    -1,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,   281,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   290,   291,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,   300,   301,    -1,    -1,    -1,   305,    -1,
      -1,    -1,    -1,    -1,   311,   312,    -1,    -1,    -1,    -1,
      -1,   318,   319,   320,   321,   322,   323,    -1,    -1,    -1,
     327,    -1,    -1,    -1,   331,    -1,   333,    -1,    -1,    -1,
      -1,    -1,    -1,   340,   341,   342,   343,    -1,   345,   346,
      -1,    -1,    -1,   350,   351,    -1,   353,   354,   355,   356,
     357,   358,   359,   360,    -1,    -1,    -1,    -1,    -1,   366,
     367,   368,    -1,   370,   371,    -1,    -1,    -1,   375,   376,
     377,   378,   379,   380,   381,   382,   383,    -1,   385,    -1,
      -1,    -1,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
      -1,   428,   429,    -1,    -1,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,    -1,    -1,   460,   461,   462,   463,   464,   465,   466,
     467,   468,    -1,   470,   471,   472,   473,    -1,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,    -1,   512,   513,   514,   515,   516,
     517,    -1,    -1,   520,   521,    -1,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,    -1,    -1,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,    -1,    -1,    -1,
      -1,   618,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     647,    -1,    -1,    -1,    -1,   652,    -1,    -1,    30,   656,
      -1,    -1,   659,   660,   661,   662,    -1,    39,   665,   666,
      -1,   668,   669,   670,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    74,    75,    -1,    77,    78,
      79,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,   104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,   120,   121,
     122,   123,   124,   125,   126,   127,   128,    -1,   130,   131,
     132,   133,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
     142,    -1,   144,   145,   146,    -1,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,   157,    -1,   159,   177,   161,
     162,    -1,    -1,   165,   166,    -1,   185,   169,   170,   171,
      -1,   173,   174,    -1,    -1,    -1,   178,   179,   180,    -1,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,   198,    -1,    -1,   201,
     219,   203,    -1,   205,    -1,   207,    -1,   209,   210,   228,
     212,   213,   214,    -1,    -1,    -1,   218,    -1,   220,   221,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,
      -1,    -1,   244,    -1,    -1,   247,   248,    -1,    -1,   251,
     252,    -1,    -1,   255,   256,    -1,    40,    41,    42,    43,
      44,    45,   264,   265,   266,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   278,   279,   280,    -1,
     282,    -1,    -1,   302,   286,   287,    -1,    -1,    -1,   291,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   307,   308,   309,    -1,    -1,
      -1,    -1,    -1,   315,   316,    99,    -1,    -1,    -1,   321,
      -1,    -1,   324,    -1,    -1,   344,   328,   329,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   357,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   365,    -1,    -1,    -1,    35,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   395,    -1,    -1,    -1,    -1,    -1,    -1,
     402,    -1,   404,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
     452,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   494,   495,    -1,    -1,    -1,   499,    -1,    -1,
      -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,
     294,    -1,    -1,    -1,    -1,   517,   518,   519,   520,    -1,
      -1,    -1,   524,    -1,    -1,    -1,   528,    -1,    -1,    -1,
      -1,    -1,    -1,   535,   536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   547,   330,   549,    -1,   333,
      -1,    -1,    -1,    -1,   338,    -1,    -1,    -1,   560,    -1,
     562,    -1,   346,   565,    -1,    -1,    -1,    -1,    -1,   571,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   597,    -1,    -1,   600,    -1,
      -1,    -1,    -1,   605,    -1,    -1,   608,   609,    -1,    -1,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
      -1,   623,    -1,    -1,    -1,    -1,    -1,   411,   630,    -1,
      -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,
      -1,   653,   654,   655,   656,   657,   658,   659,    -1,    -1,
     662,    -1,   664,    -1,   666,    -1,    -1,    -1,    -1,    -1,
     672,   673,   674,   457,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,   481,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    35,    -1,   491,   492,    -1,
      -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    -1,   507,   392,   393,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,   529,    -1,    -1,   532,   533,
      -1,    -1,    -1,    -1,   538,    35,    -1,    -1,    -1,    -1,
      -1,    -1,   430,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,   595,    -1,    93,    94,    95,    96,    97,    98,    -1,
     604,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,     7,     8,    35,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     558,    -1,    35,     6,     7,     8,    -1,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    35,   253,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,   624,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
     250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,
      -1,    -1,   392,   393,    -1,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,   250,    -1,    -1,   253,    -1,    93,    94,    95,    96,
      97,    98,   372,    35,    -1,    -1,    -1,    -1,    -1,    -1,
     430,    -1,   109,   110,   111,    -1,    -1,   250,   388,    -1,
     253,    -1,   392,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,
     430,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,   372,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,
      -1,    -1,    -1,   392,    -1,    18,    19,    20,   558,   372,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,   388,   253,    -1,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,
      -1,   430,    -1,    -1,    93,    94,    95,    96,    97,    98,
      -1,    -1,    65,    -1,   443,   388,    -1,    -1,   558,   392,
     109,   110,   111,    -1,    -1,    -1,    -1,   430,    -1,   458,
      -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,
     443,    -1,    -1,    -1,    -1,    -1,    -1,   476,   250,    -1,
      -1,   253,    -1,    -1,    -1,   458,    -1,   430,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     443,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,   624,   458,    -1,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   476,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,    -1,    -1,    -1,   392,    -1,    -1,    -1,   558,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,   109,   110,   111,    -1,
      -1,   250,    -1,   430,   253,    -1,    -1,    -1,    -1,    -1,
     372,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,   388,   109,   110,   111,
     392,   458,    -1,    -1,    -1,   624,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,   476,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,   624,    -1,    -1,    65,    -1,   458,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    18,
      19,    -1,    -1,   372,    -1,    24,    25,    26,    27,   100,
      -1,   558,    -1,    -1,    -1,    -1,    -1,   250,    -1,   388,
     253,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    65,    -1,   250,    -1,
      -1,   253,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   430,    -1,    -1,   397,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,   558,   624,    -1,   412,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    35,    -1,   458,
      -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,   432,
     191,    -1,   193,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,   444,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   624,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,   485,    -1,    -1,   388,    -1,    -1,    -1,   392,
      -1,   109,   110,   111,   497,    -1,    -1,    -1,    -1,    -1,
     372,    -1,   191,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,    -1,   558,
     392,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,   290,
      -1,    -1,     9,    -1,   295,    -1,   539,    -1,    -1,    -1,
     443,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   458,    -1,    -1,   430,    -1,
      -1,    -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,   578,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,   624,   458,   590,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,   358,    -1,   602,
     603,   290,    -1,    -1,   476,    -1,   295,   610,    -1,   370,
     613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   389,    -1,
      -1,    -1,   250,   394,   323,   253,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    -1,   414,    -1,   558,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,   429,   358,
      -1,   432,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      -1,   370,    -1,   444,   445,    -1,   558,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     389,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,    -1,
      -1,    -1,    -1,    -1,   191,    -1,   193,    -1,    -1,   408,
      -1,   624,    -1,   484,   485,   414,    -1,    -1,   489,    -1,
      -1,    -1,    -1,    -1,    -1,   424,   497,    -1,    -1,    -1,
     429,    -1,    -1,   432,    -1,    -1,   435,   508,    -1,    -1,
      -1,    -1,   624,   514,   372,   444,   445,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     388,    -1,    -1,    -1,   392,    -1,    -1,    -1,   539,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   485,    18,    19,    -1,
     489,    -1,    -1,    24,    25,    26,    27,    -1,   497,    -1,
      -1,    -1,   430,   290,    -1,    -1,    -1,    -1,   295,   508,
      -1,   510,   583,    -1,    -1,   514,    -1,    -1,    -1,   590,
      -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
     458,   602,   603,    -1,    65,    -1,   323,    -1,    -1,   610,
     539,    72,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
     621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,   100,
      -1,   358,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,   370,   583,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    35,   592,    -1,    16,    17,    18,    19,    20,
      21,    22,   389,   602,   603,    -1,    65,   394,    -1,    -1,
     397,   610,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,   408,   621,    -1,    -1,    -1,    -1,   414,    -1,    -1,
     558,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,
      -1,    -1,   429,    -1,    -1,   432,    -1,    -1,   435,    -1,
      93,    94,    95,    96,    97,    98,    -1,   444,   445,    -1,
     191,    -1,   193,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,    -1,    -1,    -1,    -1,    -1,   624,   484,   485,    18,
      19,    20,   489,    -1,    -1,    24,    25,    26,    27,    -1,
     497,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   508,    -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,    -1,   539,    -1,    -1,    -1,    -1,    -1,    -1,   290,
      -1,    -1,    -1,    -1,   295,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    18,    19,    20,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,   323,    -1,    -1,    -1,   583,    -1,    -1,    -1,
      -1,    -1,    -1,   590,    -1,   592,    -1,   250,    -1,    -1,
     253,    -1,    -1,    -1,    -1,   602,   603,    -1,    -1,    -1,
      -1,    65,    -1,   610,    -1,    -1,    -1,   358,    -1,   250,
      -1,    -1,   253,    -1,   621,    -1,    -1,    -1,    -1,   370,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   389,   109,
     110,   111,    -1,   394,    -1,    -1,   397,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,   408,    18,    19,
      20,    -1,    -1,   414,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,   424,    -1,    -1,    -1,    -1,   429,    -1,
      -1,   432,    -1,    -1,   435,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,   445,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    65,    -1,    18,    19,   372,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,   397,    -1,
      -1,    -1,    -1,    -1,    -1,   388,    -1,   191,    -1,   392,
      -1,   372,    -1,   412,   485,    -1,    -1,    -1,   489,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   497,   388,    -1,    -1,
     429,   392,    -1,   432,    65,    -1,    -1,   508,    -1,    -1,
      -1,    -1,    -1,   514,    -1,    -1,   445,   430,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,   253,    -1,    -1,    -1,    -1,   539,   430,
      18,    19,    -1,   472,    -1,   458,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    -1,   458,   497,    -1,
      20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,   191,   583,    -1,    -1,   476,    -1,    65,    -1,   590,
      -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   602,   603,    -1,    -1,    -1,    -1,    -1,   397,   610,
     539,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,
     621,    -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,    -1,    -1,   432,    -1,   558,    -1,    -1,    -1,   578,
      -1,    -1,   372,    -1,    -1,    -1,   445,    -1,    -1,    -1,
      -1,   590,    -1,    -1,    -1,    -1,    -1,   558,   388,    18,
      19,    -1,   392,   602,   603,    24,    25,    26,    27,    -1,
      -1,   610,    -1,   397,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,   484,   485,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,
     430,   624,    -1,   191,    -1,   429,    65,    -1,   432,    -1,
      -1,    40,    41,    42,    43,    44,    45,    18,    19,    -1,
      -1,   445,    -1,   624,    -1,    26,    27,    -1,   458,    -1,
      -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     539,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
     484,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    72,    -1,   497,    -1,    -1,    -1,   397,    -1,   578,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,   412,    -1,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,   602,   603,    -1,    -1,    -1,    -1,   429,
      -1,   610,   432,    -1,   613,   539,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,   445,   397,    -1,   558,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   578,    -1,    -1,    -1,   429,    -1,
      -1,   432,    -1,    -1,    -1,   485,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   445,    -1,    -1,   497,   602,   603,
      -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,   613,
     191,    -1,   193,    -1,   624,    -1,    -1,   621,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,
      -1,    -1,    -1,   484,   485,    -1,    -1,    -1,    -1,   539,
      -1,    -1,    -1,    -1,   412,    -1,   497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,
      -1,   429,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,    -1,    -1,    -1,   445,   578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   429,
     590,    -1,   432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   602,   603,   472,   445,    -1,    -1,    -1,   290,
     610,    -1,    -1,   613,    -1,    -1,    -1,   485,    -1,    -1,
      -1,   621,    -1,    -1,   333,    -1,    -1,   578,    -1,   497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,    -1,   590,
      -1,    -1,   323,    -1,    -1,   485,    -1,    -1,    -1,    -1,
      -1,   602,   603,    -1,    -1,    -1,    -1,   497,   397,   610,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621,   539,    -1,   412,    -1,    -1,    -1,   358,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   370,
     429,    -1,    -1,   432,    -1,    -1,    -1,    -1,    -1,   539,
      -1,    -1,   411,    -1,    -1,    -1,   445,    -1,    -1,   418,
     578,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   590,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    -1,    -1,   602,   603,    -1,    -1,   578,    -1,
      -1,    -1,   610,   424,    -1,   613,   485,    -1,   457,    -1,
     590,   432,    -1,   621,    -1,    -1,    -1,    -1,   497,    -1,
      -1,    -1,   602,   603,   445,    -1,    -1,    -1,    -1,    -1,
     610,    -1,   481,   613,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   621,   491,   492,    -1,    -1,    -1,    -1,   497,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   507,    -1,
     539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   489,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     529,    -1,    -1,   532,   533,    -1,    -1,    -1,    -1,   538,
      -1,    -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,   578,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,    -1,    -1,   602,   603,    -1,    -1,    -1,    -1,    -1,
      -1,   610,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,    -1,   595,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   592
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    47,    48,    76,   123,   124,   126,   127,   131,
     148,   149,   166,   237,   357,   407,   439,   468,   738,   766,
     767,   819,   990,  1043,  1045,  1046,  1047,  1052,  1054,  1067,
    1068,  1069,  1070,  1071,  1489,    28,    29,   739,   740,   741,
     742,   743,    27,   955,  1508,   356,   535,   549,   574,   622,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,   955,    25,
     955,  1408,  1072,   768,  1408,   767,  1489,     0,  1044,  1047,
    1052,  1070,  1489,    31,   741,   743,   955,  1492,   591,   955,
    1491,   627,   820,    25,   191,   765,   766,   943,   955,   960,
    1073,  1108,  1109,  1110,  1111,  1112,  1116,   354,   770,   771,
     772,   773,   776,   777,    56,    61,   106,   107,   114,   368,
     395,   466,   559,   639,   647,   738,   744,   915,   989,  1048,
    1049,  1051,  1055,  1056,  1062,  1074,  1095,  1228,  1238,  1489,
     955,  1491,   618,  1111,   243,   459,   460,  1118,    20,   955,
    1115,   621,   771,     5,   769,   354,   955,     5,   795,   797,
     798,   955,  1239,   955,   955,  1229,  1063,   955,   955,  1051,
    1057,   261,   300,   319,   358,   370,   381,   399,   409,   425,
     465,   488,   503,   510,   513,   534,   537,   539,   558,   576,
     821,   822,   823,   826,    25,  1108,  1114,    18,    19,    26,
      60,    72,   100,   193,   290,   323,   358,   370,   408,   424,
     432,   445,   489,   514,   539,   583,   592,   688,   690,   881,
     886,   897,   899,   955,  1108,  1119,  1120,   460,    14,   818,
     773,   523,  1215,   774,   771,   776,    32,    80,    81,    90,
     261,   300,   319,   335,   358,   370,   381,   399,   409,   425,
     465,   488,   503,   510,   513,   534,   537,   539,   558,   576,
     618,   671,   780,   789,   800,   801,   955,   432,   113,   955,
     765,   916,  1096,   955,   828,   537,   778,   804,   806,   807,
     805,   814,   815,   432,   432,   827,   460,   432,   432,   771,
     802,   427,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   688,   432,   762,     9,    18,    19,    24,    25,
      26,    65,   295,   389,   394,   397,   414,   429,   432,   435,
     444,   485,   497,   508,   539,   590,   602,   603,   610,   621,
     855,   863,   864,   865,   866,   867,   868,   869,   897,   898,
     900,   961,  1108,  1218,  1400,   432,   432,   432,   432,    18,
      19,    20,    21,    22,   689,    26,   432,   522,     5,   428,
    1119,    25,    26,   955,   961,    19,    25,    26,   775,   961,
     791,   778,   792,   804,   805,   432,   432,   790,   460,   432,
     432,   802,   771,   675,   676,   677,   779,   799,   432,    26,
     955,   432,  1064,   765,   765,   432,   955,   432,   459,   784,
     627,   367,   455,   471,   514,   554,   583,   592,   808,   627,
     367,   455,   471,   514,   554,   583,   592,   816,    26,    26,
     829,   830,   831,   832,   955,    26,   787,   788,    26,    26,
     621,   668,   947,   955,  1499,   947,   947,  1499,  1499,   855,
      25,    26,    19,    24,    25,    26,   901,   902,   903,   904,
    1499,   855,   393,   855,   855,   855,   855,   527,  1235,   432,
     432,   855,   367,   455,   471,   514,   554,   583,   592,  1403,
    1404,   432,   855,   855,   432,   432,   870,   432,   432,   432,
     432,    26,     6,     7,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    35,    93,
      94,    95,    96,    97,    98,   109,   110,   111,   250,   253,
     372,   388,   392,   430,   458,   476,   558,   624,   761,   856,
     871,   873,   874,   875,   876,   877,   878,   879,    26,   961,
     422,   889,   887,   893,   891,   688,   882,   955,  1120,   460,
     428,    26,   771,   784,   771,    26,    26,   770,   787,    26,
      26,   621,   782,    59,   796,  1240,   393,   432,  1230,  1509,
    1510,  1511,  1512,  1513,   917,  1097,  1058,   621,    26,   809,
     810,   432,   811,   816,   817,   811,   432,   812,     5,   393,
       5,   393,     5,   284,     5,   821,   428,     5,     5,   393,
     393,   771,   803,   432,   460,   621,     5,   393,   393,   393,
     393,   393,   393,   393,   393,   591,   902,    19,    26,   591,
     393,   393,   393,     5,   763,   855,   472,  1424,   855,   432,
     627,    20,   393,  1424,    20,  1218,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   432,
     855,   855,   432,  1108,   855,   855,   855,   855,   718,   719,
     720,   855,   432,  1119,   460,   621,    26,   259,     5,   393,
       5,   393,   284,   428,     5,   393,   393,   803,   625,   955,
    1125,  1126,  1128,  1075,  1125,   362,  1510,  1215,    39,    46,
      55,    67,    68,    70,    84,    91,   102,   103,   104,   118,
     120,   121,   122,   125,   128,   130,   132,   133,   139,   142,
     144,   145,   146,   154,   156,   157,   159,   161,   162,   165,
     169,   170,   171,   173,   174,   178,   179,   180,   182,   186,
     188,   189,   194,   198,   201,   203,   205,   207,   209,   210,
     212,   213,   214,   218,   220,   221,   223,   231,   232,   244,
     247,   248,   251,   252,   255,   256,   264,   265,   266,   268,
     278,   279,   280,   282,   286,   287,   291,   299,   307,   308,
     309,   315,   316,   321,   324,   328,   329,   339,   357,   365,
     371,   402,   404,   405,   413,   452,   463,   470,   494,   495,
     499,   511,   517,   518,   519,   520,   524,   528,   535,   536,
     547,   549,   560,   562,   565,   571,   597,   600,   605,   608,
     609,   623,   630,   653,   654,   655,   656,   657,   658,   659,
     662,   664,   666,   672,   673,   674,   681,   682,   683,   684,
     701,   723,   737,   738,   744,   745,   764,   834,   835,   836,
     837,   848,   849,   850,   851,   852,   853,   854,   906,   910,
     941,   962,   963,   966,   967,   968,   969,   982,   991,  1012,
    1013,  1015,  1019,  1034,  1035,  1039,  1040,  1041,  1042,  1050,
    1065,  1078,  1089,  1090,  1091,  1102,  1105,  1141,  1144,  1146,
    1152,  1153,  1156,  1159,  1162,  1164,  1166,  1169,  1176,  1181,
    1185,  1186,  1187,  1199,  1200,  1203,  1209,  1210,  1211,  1236,
    1251,  1252,  1253,  1254,  1255,  1260,  1266,  1267,  1285,  1288,
    1318,  1320,  1409,  1410,  1441,  1442,  1449,  1460,  1489,  1493,
    1498,  1500,  1502,  1506,  1507,  1514,   738,  1053,  1489,   626,
     649,  1098,  1099,  1125,    20,   393,   427,   785,   808,    26,
     813,    26,    26,    26,   830,   832,   824,   788,    26,   955,
     688,    20,   668,   955,   947,   895,  1404,   895,    26,    26,
     591,    24,    26,   805,   896,   806,   393,   360,   477,   587,
    1432,   393,   393,    26,  1404,   393,   393,   393,   393,   393,
     393,   393,   443,   443,   443,   880,  1424,   443,   880,  1424,
     890,   888,   894,   892,   883,     5,   884,   428,  1119,    20,
     785,   432,    26,    26,   781,    26,   795,   621,   393,     5,
    1125,   393,    25,  1108,  1163,   955,   350,   956,   957,  1508,
     955,   955,  1183,   950,   956,   950,    25,   191,   955,  1117,
    1484,  1485,  1486,   955,  1504,   955,  1262,  1263,   955,    26,
     685,  1108,  1258,   950,  1183,   880,    26,   961,  1223,  1224,
    1223,   855,   862,  1287,   857,   880,   956,  1450,  1450,   838,
    1183,   950,  1256,  1108,   952,   956,   862,  1450,  1108,  1183,
    1108,  1286,  1450,    25,   587,  1092,  1093,  1108,   950,   950,
    1092,   951,   956,   955,  1093,   950,  1450,   950,   952,  1108,
    1139,  1140,   948,   956,   952,   376,   563,   947,  1014,   955,
     746,   953,   956,    25,  1319,  1484,   880,   880,   956,  1165,
     911,   129,   138,   147,   152,   196,   204,   260,   285,   292,
     294,   304,   330,   338,   376,   402,   440,   451,   550,   551,
     552,   563,   666,  1028,  1160,  1161,  1108,   861,   862,  1175,
    1499,  1499,   949,   956,   880,  1163,  1237,  1108,  1214,    25,
    1108,  1444,   862,  1205,  1206,  1207,  1216,  1217,   862,  1494,
     105,   155,   193,   290,   366,   408,   475,   702,   886,   955,
    1108,  1246,   725,   862,   948,  1491,  1079,   862,   948,    26,
    1108,  1036,   948,   862,  1461,   862,  1223,   955,   964,   965,
     952,   964,  1499,   952,   964,  1499,   970,   964,    25,    26,
     386,   488,   961,  1017,  1108,  1127,  1129,  1108,  1108,  1108,
      66,   275,   345,   391,   570,   650,   651,   652,   661,   692,
     972,   974,   976,   978,   980,  1103,  1104,  1107,   336,   347,
     400,   415,   504,  1321,   641,   642,   919,   920,   921,   955,
    1100,   648,  1099,   393,   303,   393,   393,   393,   393,   625,
       5,   393,   393,   428,   432,   627,   393,    26,   591,   627,
      18,    19,    20,    25,    26,    65,   397,   412,   429,   432,
     445,   485,   497,   539,   578,   590,   602,   603,   610,   613,
     955,   961,  1399,  1401,  1431,  1433,  1434,  1436,  1437,  1438,
    1485,  1488,  1235,   393,  1235,  1235,  1235,  1235,  1235,  1235,
      25,    25,    25,   855,   872,   393,    25,   872,   393,   393,
     393,   393,   393,   393,   720,   718,   428,   303,   771,   793,
     794,   393,   393,   625,   393,   955,  1241,  1128,   393,  1231,
      57,    58,    85,    86,    87,   456,   543,   586,  1268,  1269,
    1270,  1273,  1276,  1279,  1280,  1281,  1282,   432,   621,  1486,
    1118,   618,  1157,   621,     8,   540,   589,     5,   393,   428,
      25,   955,  1393,   480,  1184,  1127,   109,   110,   111,   484,
     858,   859,   862,  1108,  1134,  1393,   691,   692,   841,   267,
      88,    89,   627,   461,     5,   620,   627,   619,   619,  1142,
     597,   422,     5,   558,   992,   461,   660,  1496,   660,   386,
     748,  1108,   548,   619,  1147,  1148,  1149,   327,  1317,   860,
     862,   860,     8,   949,    26,   502,   556,   670,   942,  1108,
     942,   942,   942,    25,   178,   305,   311,   312,   313,   331,
     440,   443,   451,   486,   521,   541,   542,   552,   557,   596,
     628,  1032,  1033,   942,   942,   598,  1029,   692,  1029,  1029,
     943,   943,  1029,  1029,   692,     5,   334,   387,     5,   691,
      82,    83,   541,   628,  1020,   663,  1497,   861,   614,   615,
     616,   617,  1213,  1215,   385,  1250,  1215,  1207,     5,   619,
    1208,   862,   432,   432,   432,   432,    25,   721,   955,   432,
    1444,   345,   432,   522,   591,   580,   726,   733,   724,    25,
    1094,  1108,  1201,     8,  1204,    14,   955,  1113,  1121,  1122,
    1124,  1132,  1133,  1177,   163,   345,   546,   579,     5,     6,
       7,     8,     9,    10,    12,    13,    14,    18,    19,    20,
      21,    22,    23,    33,    45,    63,    72,    90,    92,   100,
     105,   106,   109,   110,   111,   112,   115,   116,   155,   178,
     184,   191,   193,   199,   224,   262,   275,   281,   290,   291,
     297,   300,   301,   305,   311,   312,   318,   319,   320,   321,
     322,   323,   327,   331,   333,   340,   341,   342,   343,   345,
     346,   350,   351,   353,   354,   355,   356,   357,   358,   359,
     360,   366,   367,   368,   370,   371,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   385,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   428,   429,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     470,   471,   472,   473,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     512,   513,   514,   515,   516,   517,   520,   521,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   639,   647,
     652,   656,   659,   660,   661,   662,   665,   666,   668,   669,
     670,  1462,  1463,  1464,  1466,   577,     5,   660,   660,   860,
    1127,  1134,  1016,   422,     5,   151,   996,   432,  1108,   860,
     432,    26,    26,    66,  1106,    25,  1108,  1448,  1448,   956,
    1301,  1165,   949,   119,   222,   230,   236,   238,   249,   277,
     293,   298,   310,   317,   472,   479,   501,   506,  1289,  1290,
    1298,  1308,  1309,  1315,  1316,  1322,  1323,  1332,  1351,  1355,
    1420,  1421,  1451,  1452,  1455,  1456,  1468,   922,   923,    92,
     918,   929,   930,   921,  1101,  1509,  1059,   460,   821,   788,
     621,   955,   367,   455,   471,   514,   554,   583,   592,  1405,
     895,   591,    24,    26,   809,  1437,  1437,   367,   455,   471,
     514,   554,   583,   592,  1402,  1406,   472,  1436,   432,   432,
     432,   432,   432,   432,   432,   955,   432,     5,   548,  1360,
    1365,   955,    18,    19,    20,    21,    93,    94,    95,    96,
      97,    98,  1458,   422,     5,   393,   393,   885,   460,     5,
     393,   795,   765,  1076,   765,   158,   297,   374,   432,   477,
     493,  1338,  1350,   432,   955,  1284,    26,   246,   259,   432,
     477,   493,   955,  1265,  1278,  1336,  1337,  1342,  1344,  1346,
     432,   955,  1275,   432,  1265,  1271,     5,    25,   958,  1111,
    1486,  1484,   578,   618,  1158,    20,   955,  1138,  1487,   955,
    1505,  1263,   597,   621,   591,   432,   432,   841,     5,   627,
     432,  1484,    25,   960,  1182,  1182,  1444,  1092,   862,   862,
     862,   944,   945,   432,  1108,  1140,   802,   993,   994,   627,
    1444,  1499,  1497,  1014,  1108,   747,   626,   862,   351,  1151,
     558,  1150,     5,    69,    71,    73,   619,   627,   833,  1127,
     912,    18,    19,   432,  1030,  1032,  1161,   943,   862,   345,
     597,    26,    26,   691,   153,  1212,   219,  1217,  1223,  1495,
     955,    25,   905,   947,  1499,   591,   947,   624,  1108,   706,
     955,   955,   862,   340,   729,   733,   580,   727,   735,    23,
     235,  1081,  1085,   483,   880,   483,  1202,   862,   459,  1118,
     621,     5,  1037,   548,  1178,  1108,  1465,  1467,   190,  1463,
     983,   965,  1499,  1499,   975,   976,   996,   996,    34,    36,
      37,    38,   271,   274,   276,   296,   306,   348,   352,   431,
     995,   997,   998,  1024,  1108,  1129,   548,   693,    26,   401,
     981,   322,  1443,  1443,   136,   137,   438,   548,   955,  1352,
    1353,  1394,   802,  1393,  1393,  1291,   802,   955,  1453,  1453,
    1432,  1393,  1299,   168,   440,   451,   472,   479,  1325,  1326,
    1327,   288,   289,  1415,  1509,  1509,   386,   931,  1108,   643,
     644,   924,   925,   926,   482,   626,   645,   646,   665,   934,
     935,  1509,   765,    26,   786,    20,   955,   393,   432,    24,
      26,   627,  1432,   393,   397,  1459,  1488,   360,   477,   587,
    1384,  1436,  1439,  1384,  1384,  1384,  1384,   621,  1439,  1434,
     516,  1361,  1362,  1363,  1393,   527,  1359,  1366,   332,   515,
     526,  1310,  1427,  1436,  1436,  1436,  1436,  1485,   855,   393,
     786,   794,  1242,   765,  1232,  1340,  1393,  1283,  1350,   432,
    1283,   432,   432,  1277,  1278,   432,   432,    64,   300,   358,
     370,   381,   399,   409,   412,   425,   473,   503,   513,   534,
     537,   539,   567,   576,  1385,  1386,  1387,  1389,  1274,  1275,
    1271,  1272,   665,  1269,   393,   621,  1444,   578,   460,   548,
    1503,   686,   687,   955,   955,   955,  1259,   880,   858,   955,
    1257,   618,  1154,   627,     5,     5,     5,   581,   862,   621,
       5,   484,   627,   626,   164,   167,   271,   274,   749,   752,
     753,  1024,   750,   751,   955,   432,   956,   650,   651,  1155,
     862,   955,   955,   945,   946,   510,  1499,   841,     8,   914,
      26,    26,  1031,  1032,  1108,   537,  1170,    66,   855,  1215,
      26,  1108,  1509,     5,     5,     5,   393,   393,   722,   955,
     393,  1444,   718,   432,   432,   734,   730,   361,   728,   862,
     340,   731,   735,   598,  1026,  1086,  1082,   363,  1080,  1081,
     860,   627,  1114,    20,   955,  1123,  1133,    14,   484,  1179,
    1180,  1436,  1488,  1108,  1130,  1131,  1509,   977,   978,   552,
     954,   548,  1007,  1006,  1009,  1008,   947,  1010,   947,  1011,
    1005,  1004,  1002,  1001,  1025,   325,   998,  1003,  1499,    40,
      41,    42,    43,    44,    45,    99,   333,   346,   411,   418,
     457,   481,   491,   492,   497,   507,   529,   532,   533,   538,
     595,   606,   694,   695,  1022,  1023,     5,    26,  1444,   249,
    1108,   472,  1425,  1426,  1444,  1165,  1419,  1421,   101,   101,
     597,  1163,  1354,  1355,   432,  1333,   150,  1366,  1393,   175,
     272,  1457,   621,   627,  1422,  1469,   342,   351,   376,   379,
     397,   502,   556,   563,   949,  1302,  1307,   432,  1328,   626,
       5,    25,   955,  1416,  1417,   933,  1108,     5,   548,   927,
     928,   640,   926,   932,   955,   932,   936,   937,   932,   325,
     935,  1060,   428,    26,   367,   455,   471,   514,   554,   583,
     592,  1407,  1433,     5,  1406,   393,     5,  1436,     5,   393,
    1436,  1436,  1436,  1436,   955,   393,   432,  1363,     5,   955,
    1398,     9,   295,   432,   444,  1369,  1370,  1371,  1372,  1373,
    1377,  1381,  1383,  1436,   369,  1357,  1367,   955,  1428,   620,
    1384,   332,   428,   462,  1225,  1245,  1077,   462,  1188,  1219,
     432,     5,   393,  1369,   393,   613,   955,  1339,  1341,  1393,
    1396,  1397,  1343,  1396,     5,   393,  1343,  1369,  1406,  1406,
     432,   432,   432,   432,   432,   432,   208,   401,  1345,  1347,
       5,   393,     5,   393,   955,  1487,     8,  1444,  1119,   862,
       5,  1264,  1265,   880,  1066,   621,  1264,   578,  1444,  1444,
     862,   862,   944,   510,   862,  1501,     5,    20,  1396,   994,
    1444,   750,   758,   757,   759,   955,   959,   760,   959,   192,
     753,   756,     5,   996,   621,   862,     8,   955,   880,   555,
    1305,     5,   393,  1108,     5,   326,    25,  1247,   947,   345,
     345,   460,   621,   345,   432,   707,   711,   704,  1509,  1509,
     736,   732,   728,  1027,    25,   954,  1087,  1108,  1509,   862,
     427,   460,   880,     5,   422,     5,   984,   979,   980,    26,
     691,   955,  1509,  1509,  1509,  1509,     5,   999,     5,  1000,
    1509,  1509,  1509,  1509,  1030,  1509,   954,    25,    14,    14,
       5,   393,    26,  1393,  1432,  1413,   597,   597,  1290,  1418,
    1419,  1355,  1334,  1396,   618,   949,   432,  1294,   955,  1454,
    1453,  1433,    49,    50,    51,    52,    53,   585,  1472,   862,
     862,  1300,   949,  1329,  1396,  1393,  1327,   621,   621,     5,
       5,  1108,   932,  1509,  1509,     5,   939,   940,  1509,  1509,
     938,  1053,   825,   393,  1365,  1406,   627,  1406,   393,  1436,
     393,   393,   393,   393,  1362,  1364,  1362,  1372,   432,  1431,
    1369,  1436,  1431,     6,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   253,   372,   373,   430,   558,   624,   678,
     679,  1380,  1382,  1358,  1435,  1436,   449,  1356,  1368,   269,
    1261,    26,  1311,  1312,  1313,  1396,  1425,  1428,   783,    74,
      75,    77,    78,    79,   177,   185,   219,   228,   257,   258,
     302,   344,   401,   629,   630,   631,   632,   633,   634,   635,
     636,   637,   638,  1222,  1226,   135,   515,  1227,  1243,  1053,
     160,   176,   177,   185,   219,   228,   257,   302,   344,  1220,
    1221,  1233,  1227,  1341,  1350,   393,  1397,   460,  1395,   393,
       5,   621,     5,   393,  1278,   393,   393,   627,   432,   627,
      26,  1391,  1391,    26,  1391,  1391,    26,  1390,    25,  1399,
    1348,  1349,  1350,  1275,  1271,  1444,     8,   428,   687,     5,
     393,   860,   393,    20,   393,  1444,     5,   862,   568,   275,
     696,   697,   862,   996,  1509,  1509,     5,   754,   460,   621,
       5,   755,  1509,   751,   548,    20,   955,     5,   955,  1145,
     391,   660,   860,  1306,   913,  1032,   669,  1168,   855,     5,
     718,  1108,   703,   685,   955,  1108,   709,   393,   718,   718,
    1509,  1509,  1030,  1084,    25,  1088,  1108,   573,   909,  1119,
     484,   861,  1038,  1180,  1108,  1131,    63,   544,   985,   971,
     972,   621,   947,  1509,   947,  1509,   691,    26,  1108,    26,
    1108,   695,   393,   432,  1445,  1433,  1415,  1419,  1419,  1411,
       5,   393,   472,  1430,  1295,  1396,   480,  1292,  1430,   627,
    1423,    18,    19,    65,   429,   432,   445,   484,   485,   497,
     539,   578,   590,   602,   603,   610,   613,   955,  1399,  1431,
    1477,  1478,  1479,  1480,  1481,  1482,  1488,  1477,  1477,  1477,
    1396,  1474,  1476,  1473,  1474,  1475,  1470,   555,  1303,     5,
     393,   627,   955,   955,  1417,  1108,   955,  1509,  1509,  1509,
    1509,   625,   393,   627,  1407,   627,     5,   393,   393,  1370,
    1371,  1375,  1437,  1375,   432,  1431,  1375,   432,  1431,  1375,
      10,   250,   388,   390,  1436,     5,  1369,     5,   540,   589,
    1314,  1261,   625,  1223,  1223,  1223,    25,  1223,  1223,  1223,
    1223,  1223,  1223,    25,    25,  1223,  1226,  1108,  1135,  1136,
     620,   448,  1189,  1509,    25,    25,    26,    26,    26,    26,
      26,    25,  1108,  1221,  1189,   393,    26,  1338,  1396,    20,
     955,  1396,  1407,    26,  1407,     5,  1388,  1388,     5,   393,
     393,  1388,   393,  1350,  1444,  1265,  1261,   469,   840,     5,
     375,  1444,     5,   432,   393,   552,  1021,   959,  1509,   688,
      20,   955,   959,  1509,  1499,   862,  1499,  1130,  1509,    26,
     954,    25,  1248,  1127,   428,   718,   708,   712,   393,  1509,
     954,   862,   907,   428,   987,   986,   442,   973,   974,    20,
     955,  1446,  1447,   555,  1429,  1414,  1412,  1415,  1396,  1432,
     140,  1335,     5,   393,  1293,  1454,  1429,  1480,  1480,  1479,
     432,   432,   432,   432,   432,   432,   432,   955,   432,     5,
     393,    18,    19,    20,    21,  1458,   393,     5,   393,     5,
      14,   150,   527,  1471,  1304,  1396,   464,  1330,  1331,  1394,
     621,   211,  1061,   821,  1407,  1407,  1362,   443,  1374,  1374,
    1378,  1379,  1399,  1488,  1374,  1378,  1374,  1375,  1436,  1435,
    1312,   795,   540,   589,  1137,     5,  1135,    62,   134,   200,
     202,   217,   225,   229,   254,  1190,  1191,  1244,  1061,  1234,
       5,   428,  1395,   393,    26,  1392,   393,   393,    26,   393,
     947,   691,   375,  1444,   862,   698,   570,  1143,    26,   691,
     428,  1021,   393,   241,   691,   393,   393,   432,   710,   345,
     716,   393,   705,  1083,  1509,   460,   862,  1509,   954,     5,
     393,  1130,  1365,  1415,  1415,  1433,  1396,   432,  1365,   393,
    1459,  1384,  1479,  1483,  1384,  1384,  1384,  1384,   621,  1483,
    1478,  1479,  1479,  1479,  1479,  1474,    14,  1475,  1478,   949,
    1369,  1130,     5,   141,  1324,   955,  1376,  1399,  1440,     5,
     393,   393,  1374,     7,  1136,  1192,  1193,  1108,  1195,  1108,
    1194,  1196,  1191,   240,   240,    26,   627,   393,   839,  1444,
     394,   204,   260,   285,   294,   330,   338,   433,   604,   695,
     699,   700,   432,   621,   691,  1167,  1249,   713,   393,  1127,
     716,   716,  1509,   908,  1119,   577,  1018,  1447,  1427,  1365,
     484,  1296,  1297,  1436,  1427,   393,  1479,     5,   393,  1479,
    1479,  1479,  1479,   955,   393,   432,  1331,  1379,  1436,  1509,
    1509,  1197,  1509,  1198,  1509,  1509,   428,  1407,   348,   352,
     842,   843,   844,  1024,   942,   942,   942,   942,   942,   942,
      25,     5,   393,   862,    20,   955,  1024,  1171,  1172,  1173,
     716,   718,   716,   242,   428,   988,   691,     5,   393,   393,
    1479,   393,   393,   393,   393,  1477,  1509,  1509,   846,   845,
     239,   844,   847,   700,     5,  1174,   283,  1173,   714,  1509,
    1297,   393,  1509,  1509,  1509,   862,  1509,   393,   985,   393,
     715,   163,   345,   717,  1127
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
#line 943 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 946 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 950 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 956 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 961 "fgl.yacc"
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
#line 973 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 978 "fgl.yacc"
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
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1002 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1005 "fgl.yacc"
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
#line 1016 "fgl.yacc"
    {
	struct expr_str *ptr;
	char buff2[1024];
	char buff[1024];
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1025 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1026 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1029 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1034 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1035 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1046 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1049 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1052 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1052 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1059 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1060 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1066 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1067 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1070 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1072 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1073 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1074 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1075 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1076 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1077 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1078 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1079 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1080 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1081 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1082 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1089 "fgl.yacc"
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

  case 51:
#line 1100 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1104 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1105 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1109 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1115 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1117 "fgl.yacc"
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

  case 57:
#line 1128 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1130 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1132 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1134 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1138 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1140 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1201 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1205 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1209 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 66:
#line 1216 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1219 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1223 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1227 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 71:
#line 1234 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1240 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 73:
#line 1249 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1253 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1258 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1262 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1270 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1274 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1278 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1280 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1286 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1291 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1294 "fgl.yacc"
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

  case 84:
#line 1310 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1317 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1321 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1325 "fgl.yacc"
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

  case 88:
#line 1347 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1347 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1351 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1352 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1353 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1358 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1361 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1367 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1370 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1382 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1388 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1391 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1406 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1416 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1422 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1431 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1444 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1447 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1449 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1455 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1457 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1462 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1467 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1473 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1477 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1492 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1495 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1498 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1501 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1504 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1507 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1529 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1538 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1548 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1562 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 138:
#line 1566 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1569 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 140:
#line 1577 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 141:
#line 1583 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 146:
#line 1598 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1602 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1607 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1617 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1620 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 153:
#line 1624 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1626 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 155:
#line 1629 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 156:
#line 1631 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 157:
#line 1634 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 158:
#line 1636 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1639 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 160:
#line 1642 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 161:
#line 1652 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1653 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1661 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 164:
#line 1662 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 165:
#line 1679 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1682 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1685 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1688 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1691 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1694 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1703 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1711 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1716 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1729 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1733 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1748 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1749 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1757 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1757 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 187:
#line 1767 "fgl.yacc"
    {in_define=1;}
    break;

  case 188:
#line 1767 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 189:
#line 1776 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1777 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 191:
#line 1778 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1781 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 194:
#line 1786 "fgl.yacc"
    { }
    break;

  case 195:
#line 1786 "fgl.yacc"
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

  case 199:
#line 1803 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 200:
#line 1807 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 205:
#line 1822 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1823 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 207:
#line 1824 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 208:
#line 1825 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 209:
#line 1830 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 211:
#line 1836 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 213:
#line 1845 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 214:
#line 1849 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 220:
#line 1865 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 221:
#line 1867 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 222:
#line 1868 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 224:
#line 1875 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 225:
#line 1875 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 226:
#line 1876 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 227:
#line 1877 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 228:
#line 1880 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 229:
#line 1882 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 231:
#line 1892 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 236:
#line 1907 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 237:
#line 1907 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 241:
#line 1913 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1914 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 243:
#line 1921 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 244:
#line 1922 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 245:
#line 1923 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 246:
#line 1924 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 247:
#line 1927 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 248:
#line 1928 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1929 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 250:
#line 1930 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 251:
#line 1934 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1939 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 253:
#line 1944 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1948 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1951 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 256:
#line 1955 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 257:
#line 1956 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 258:
#line 1957 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 259:
#line 1958 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1959 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 261:
#line 1960 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1961 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 263:
#line 1962 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 264:
#line 1965 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 265:
#line 1966 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 266:
#line 1967 "fgl.yacc"
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

  case 267:
#line 1999 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 268:
#line 2003 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2005 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 270:
#line 2007 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 271:
#line 2009 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 272:
#line 2014 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 273:
#line 2018 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 274:
#line 2018 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 275:
#line 2022 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 276:
#line 2023 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 277:
#line 2024 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 278:
#line 2025 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 279:
#line 2026 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 280:
#line 2027 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 281:
#line 2029 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 282:
#line 2034 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2034 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2037 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 285:
#line 2039 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 286:
#line 2045 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 287:
#line 2047 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 288:
#line 2053 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 289:
#line 2061 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 290:
#line 2061 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 291:
#line 2064 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 292:
#line 2065 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 293:
#line 2066 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 294:
#line 2067 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 295:
#line 2068 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 296:
#line 2069 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 297:
#line 2071 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 301:
#line 2092 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 305:
#line 2101 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 306:
#line 2103 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2105 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 308:
#line 2107 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 309:
#line 2108 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 310:
#line 2109 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 311:
#line 2110 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 312:
#line 2111 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2116 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2123 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 315:
#line 2128 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2130 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2132 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 318:
#line 2133 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 319:
#line 2134 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 320:
#line 2135 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 321:
#line 2136 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 322:
#line 2137 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 323:
#line 2138 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 324:
#line 2141 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 325:
#line 2143 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 326:
#line 2149 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 327:
#line 2157 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2165 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 330:
#line 2169 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 331:
#line 2177 "fgl.yacc"
    {dim_push_record();}
    break;

  case 332:
#line 2178 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 333:
#line 2179 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 334:
#line 2180 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 340:
#line 2199 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 341:
#line 2211 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 342:
#line 2215 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 343:
#line 2218 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 344:
#line 2221 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 345:
#line 2222 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 346:
#line 2223 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 347:
#line 2224 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 348:
#line 2225 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 349:
#line 2231 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 350:
#line 2238 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 351:
#line 2243 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 352:
#line 2248 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 353:
#line 2252 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 354:
#line 2255 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 355:
#line 2263 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 356:
#line 2265 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 357:
#line 2270 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 362:
#line 2282 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 363:
#line 2285 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 364:
#line 2288 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 365:
#line 2291 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 366:
#line 2294 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 367:
#line 2297 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 368:
#line 2304 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		printf("Buff=%s\n",buff);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_alloc_arr(buff,s);
	}
    break;

  case 369:
#line 2323 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 370:
#line 2329 "fgl.yacc"
    {
		char buff[256];
		char *s;
		strcpy(buff,yyvsp[0].str);
		s=strchr(buff,'[');
		if (!s) {
			a4gl_yyerror("Expecting an array and size");
			YYERROR;
		}
		*s=0;
		s++;

		print_realloc_arr(buff,s);
	}
    break;

  case 371:
#line 2353 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 372:
#line 2356 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 373:
#line 2371 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 374:
#line 2373 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2375 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 376:
#line 2377 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2379 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2381 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2382 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 380:
#line 2389 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 381:
#line 2391 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 382:
#line 2395 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 383:
#line 2397 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 384:
#line 2399 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 385:
#line 2401 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 386:
#line 2403 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 387:
#line 2405 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 388:
#line 2407 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 389:
#line 2413 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2427 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 391:
#line 2430 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 396:
#line 2447 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 399:
#line 2453 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 400:
#line 2457 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 401:
#line 2462 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 405:
#line 2472 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 406:
#line 2473 "fgl.yacc"
    {inc_counter();}
    break;

  case 412:
#line 2479 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 413:
#line 2486 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 414:
#line 2486 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 416:
#line 2491 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 417:
#line 2495 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2501 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2509 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2515 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2524 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 422:
#line 2526 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 423:
#line 2533 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 424:
#line 2541 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 425:
#line 2545 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 426:
#line 2554 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 427:
#line 2559 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 428:
#line 2564 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 429:
#line 2568 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 430:
#line 2570 "fgl.yacc"
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

  case 431:
#line 2580 "fgl.yacc"
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

  case 432:
#line 2594 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 433:
#line 2602 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2614 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2620 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2626 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 439:
#line 2636 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 440:
#line 2642 "fgl.yacc"
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

  case 441:
#line 2714 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 442:
#line 2720 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2724 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 444:
#line 2732 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 445:
#line 2732 "fgl.yacc"
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

  case 446:
#line 2748 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 447:
#line 2752 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 448:
#line 2758 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 449:
#line 2761 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 450:
#line 2769 "fgl.yacc"
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

  case 451:
#line 2780 "fgl.yacc"
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

  case 452:
#line 2790 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 453:
#line 2796 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 454:
#line 2806 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2811 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2818 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 457:
#line 2821 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 458:
#line 2824 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 459:
#line 2829 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 460:
#line 2836 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2841 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2846 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2851 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2862 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 465:
#line 2870 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 466:
#line 2878 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 467:
#line 2883 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 468:
#line 2887 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 469:
#line 2892 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 470:
#line 2896 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 471:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 472:
#line 2906 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2909 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2913 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 475:
#line 2917 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 476:
#line 2921 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 477:
#line 2925 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 478:
#line 2929 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 479:
#line 2936 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 480:
#line 2946 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 481:
#line 2951 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 482:
#line 2957 "fgl.yacc"
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

  case 483:
#line 2967 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 484:
#line 2972 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 485:
#line 2975 "fgl.yacc"
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

  case 486:
#line 2989 "fgl.yacc"
    {chk4var=1;}
    break;

  case 487:
#line 2989 "fgl.yacc"
    {chk4var=0;}
    break;

  case 488:
#line 2989 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 489:
#line 2992 "fgl.yacc"
    {chk4var=1;}
    break;

  case 490:
#line 2992 "fgl.yacc"
    {chk4var=0;}
    break;

  case 491:
#line 2992 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 492:
#line 2996 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 2996 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 2996 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 495:
#line 3000 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 3000 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 3000 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 3004 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3010 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3016 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3022 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3032 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 503:
#line 3033 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 506:
#line 3041 "fgl.yacc"
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

  case 507:
#line 3052 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 508:
#line 3053 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 509:
#line 3059 "fgl.yacc"
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

  case 510:
#line 3070 "fgl.yacc"
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

  case 511:
#line 3080 "fgl.yacc"
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

  case 514:
#line 3093 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 515:
#line 3098 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 516:
#line 3105 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 517:
#line 3109 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 518:
#line 3112 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 519:
#line 3115 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 520:
#line 3121 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 521:
#line 3124 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 522:
#line 3127 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 523:
#line 3144 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 524:
#line 3147 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 525:
#line 3153 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 526:
#line 3154 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 527:
#line 3155 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 529:
#line 3160 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 530:
#line 3161 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3162 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 532:
#line 3163 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3165 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3166 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3167 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3169 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3170 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 539:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 541:
#line 3181 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 542:
#line 3193 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 543:
#line 3197 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 544:
#line 3198 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 545:
#line 3205 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 547:
#line 3222 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 548:
#line 3226 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 549:
#line 3232 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 550:
#line 3236 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 551:
#line 3245 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 552:
#line 3246 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 553:
#line 3258 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 554:
#line 3264 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 555:
#line 3272 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 562:
#line 3289 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 563:
#line 3291 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 564:
#line 3294 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 565:
#line 3296 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 570:
#line 3310 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 571:
#line 3312 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3315 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 573:
#line 3317 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 586:
#line 3348 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 587:
#line 3350 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 588:
#line 3353 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 589:
#line 3355 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3358 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 591:
#line 3360 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3363 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 593:
#line 3365 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3368 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 595:
#line 3370 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3385 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 597:
#line 3401 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 598:
#line 3402 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 599:
#line 3403 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 600:
#line 3404 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 601:
#line 3405 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 602:
#line 3406 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 603:
#line 3407 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 607:
#line 3415 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 609:
#line 3421 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 610:
#line 3423 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 611:
#line 3424 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 612:
#line 3426 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 613:
#line 3428 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 614:
#line 3430 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 615:
#line 3432 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 616:
#line 3434 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 617:
#line 3437 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 618:
#line 3444 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 619:
#line 3446 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 620:
#line 3452 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 621:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3462 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3467 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 624:
#line 3467 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 625:
#line 3470 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 626:
#line 3476 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 627:
#line 3481 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 628:
#line 3485 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 631:
#line 3493 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 632:
#line 3495 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 633:
#line 3497 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 634:
#line 3499 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 635:
#line 3501 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 636:
#line 3503 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 637:
#line 3506 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 639:
#line 3515 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 640:
#line 3577 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 641:
#line 3590 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 643:
#line 3597 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 644:
#line 3600 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 645:
#line 3606 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 646:
#line 3612 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 647:
#line 3616 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 648:
#line 3620 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 649:
#line 3626 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 650:
#line 3630 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 651:
#line 3634 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 652:
#line 3639 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 653:
#line 3644 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 672:
#line 3685 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 673:
#line 3692 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 674:
#line 3695 "fgl.yacc"
    {
		char wt;
		print_if_end();
	        wt=get_curr_report_stack_whytype();
		//if (wt=='P'||wt=='p'||wt=='T') {
		if (wt=='T') {
			if (if_print_stack[if_print_stack_cnt][0]!=if_print_stack[if_print_stack_cnt][0]) {
				a4gl_yyerror("Number of lines printed in an IF.. THEN must be the same for TRUE and FALSE");
				YYERROR;
			}
			
			if (if_print_stack_cnt>=1) {
				if_print_stack[if_print_stack_cnt-1][if_print_section[if_print_stack_cnt-1]]+=if_print_stack[if_print_stack_cnt][0];
			}
		}
		if_print_stack_cnt--;
	}
    break;

  case 676:
#line 3714 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 678:
#line 3717 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 679:
#line 3719 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 680:
#line 3722 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 681:
#line 3726 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 682:
#line 3729 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 683:
#line 3735 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 684:
#line 3746 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 685:
#line 3747 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 686:
#line 3750 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 688:
#line 3756 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 689:
#line 3760 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 690:
#line 3761 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 693:
#line 3775 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 694:
#line 3777 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 697:
#line 3786 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 698:
#line 3788 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 699:
#line 3792 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 700:
#line 3794 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 701:
#line 3797 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 702:
#line 3799 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 703:
#line 3802 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 704:
#line 3805 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 705:
#line 3808 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 706:
#line 3810 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 707:
#line 3813 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 708:
#line 3815 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 709:
#line 3818 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 710:
#line 3820 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 711:
#line 3823 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 712:
#line 3825 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 713:
#line 3826 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 714:
#line 3828 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 715:
#line 3829 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 716:
#line 3831 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 717:
#line 3832 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 718:
#line 3834 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 719:
#line 3874 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 720:
#line 3875 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 721:
#line 3883 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 722:
#line 3884 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 723:
#line 3893 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 724:
#line 3898 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 725:
#line 3903 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 726:
#line 3904 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 728:
#line 3909 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 729:
#line 3912 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 730:
#line 3920 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 731:
#line 3925 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 732:
#line 3929 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 733:
#line 3936 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 734:
#line 3945 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 735:
#line 3951 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 736:
#line 3952 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 737:
#line 3953 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 738:
#line 3954 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 739:
#line 3957 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 741:
#line 3960 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 742:
#line 3967 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 743:
#line 3968 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 744:
#line 3969 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 745:
#line 3970 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 746:
#line 3971 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 747:
#line 3972 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 748:
#line 3973 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 749:
#line 3974 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 750:
#line 3975 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 751:
#line 3980 "fgl.yacc"
    {iskey=1;}
    break;

  case 752:
#line 3980 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 753:
#line 3982 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 754:
#line 3985 "fgl.yacc"
    {iskey=1;}
    break;

  case 755:
#line 3985 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 756:
#line 3987 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3991 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 3994 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 759:
#line 3995 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 761:
#line 3998 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 767:
#line 4010 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 768:
#line 4011 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 769:
#line 4012 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 770:
#line 4013 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 771:
#line 4014 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 772:
#line 4015 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 773:
#line 4016 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 774:
#line 4017 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 775:
#line 4018 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 776:
#line 4019 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 777:
#line 4020 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 778:
#line 4021 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 779:
#line 4022 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 780:
#line 4023 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 781:
#line 4027 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 782:
#line 4045 "fgl.yacc"
    {chk4var=1;}
    break;

  case 783:
#line 4045 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 784:
#line 4048 "fgl.yacc"
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

  case 785:
#line 4072 "fgl.yacc"
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

  case 787:
#line 4090 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 788:
#line 4096 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 789:
#line 4102 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 790:
#line 4108 "fgl.yacc"
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

  case 791:
#line 4119 "fgl.yacc"
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

  case 792:
#line 4142 "fgl.yacc"
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

  case 795:
#line 4158 "fgl.yacc"
    {
	}
    break;

  case 802:
#line 4181 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 806:
#line 4189 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 824:
#line 4215 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 825:
#line 4216 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 826:
#line 4224 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 827:
#line 4229 "fgl.yacc"
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

  case 828:
#line 4245 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 829:
#line 4251 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 831:
#line 4266 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 832:
#line 4279 "fgl.yacc"
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

  case 833:
#line 4289 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 834:
#line 4296 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 835:
#line 4303 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 836:
#line 4309 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 837:
#line 4309 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 838:
#line 4314 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 839:
#line 4320 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 840:
#line 4328 "fgl.yacc"
    {
}
    break;

  case 846:
#line 4340 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 848:
#line 4348 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 849:
#line 4354 "fgl.yacc"
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

  case 850:
#line 4368 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 851:
#line 4372 "fgl.yacc"
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

  case 852:
#line 4385 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 854:
#line 4403 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 855:
#line 4411 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 856:
#line 4417 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 857:
#line 4428 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 858:
#line 4432 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 859:
#line 4439 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 860:
#line 4446 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 861:
#line 4452 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4457 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 865:
#line 4464 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 866:
#line 4465 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 867:
#line 4467 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 868:
#line 4468 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 869:
#line 4471 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 870:
#line 4472 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4473 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 872:
#line 4475 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 873:
#line 4480 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 874:
#line 4485 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 875:
#line 4492 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 879:
#line 4499 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 880:
#line 4501 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 881:
#line 4503 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 882:
#line 4512 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 883:
#line 4518 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 884:
#line 4522 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 887:
#line 4534 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 888:
#line 4539 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 889:
#line 4544 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 890:
#line 4547 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 892:
#line 4559 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 893:
#line 4562 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 894:
#line 4565 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 901:
#line 4581 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 902:
#line 4586 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 903:
#line 4586 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 904:
#line 4589 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 905:
#line 4616 "fgl.yacc"
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

  case 907:
#line 4674 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 909:
#line 4681 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 910:
#line 4685 "fgl.yacc"
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

  case 911:
#line 4728 "fgl.yacc"
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

  case 915:
#line 4776 "fgl.yacc"
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

  case 916:
#line 4790 "fgl.yacc"
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

  case 921:
#line 4814 "fgl.yacc"
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

  case 922:
#line 4874 "fgl.yacc"
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

  case 923:
#line 4930 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 924:
#line 4935 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 925:
#line 4943 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 926:
#line 4948 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 927:
#line 4956 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 928:
#line 4962 "fgl.yacc"
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

  case 929:
#line 4995 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 930:
#line 4998 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 931:
#line 5000 "fgl.yacc"
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

  case 932:
#line 5041 "fgl.yacc"
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

  case 937:
#line 5094 "fgl.yacc"
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

  case 938:
#line 5146 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 940:
#line 5153 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 941:
#line 5159 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 942:
#line 5170 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 943:
#line 5177 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 945:
#line 5185 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 946:
#line 5188 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 947:
#line 5189 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 949:
#line 5191 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 950:
#line 5192 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 951:
#line 5195 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 952:
#line 5198 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 953:
#line 5204 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 954:
#line 5207 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 955:
#line 5211 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 956:
#line 5215 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 957:
#line 5222 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 958:
#line 5227 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 959:
#line 5234 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 960:
#line 5237 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 965:
#line 5250 "fgl.yacc"
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

  case 966:
#line 5269 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5276 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 968:
#line 5283 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 969:
#line 5286 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 970:
#line 5300 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 975:
#line 5317 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 976:
#line 5322 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 977:
#line 5328 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 979:
#line 5335 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 980:
#line 5340 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 981:
#line 5343 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 982:
#line 5344 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 983:
#line 5347 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 984:
#line 5348 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 985:
#line 5351 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 986:
#line 5352 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 987:
#line 5357 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 988:
#line 5364 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 989:
#line 5367 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 990:
#line 5373 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 991:
#line 5375 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 992:
#line 5377 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 993:
#line 5379 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 994:
#line 5382 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 995:
#line 5382 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 996:
#line 5383 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 997:
#line 5388 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 998:
#line 5396 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 999:
#line 5397 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1000:
#line 5402 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1001:
#line 5404 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1002:
#line 5406 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1006:
#line 5423 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1007:
#line 5426 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1008:
#line 5429 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1009:
#line 5432 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1010:
#line 5436 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1011:
#line 5439 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1012:
#line 5442 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1013:
#line 5446 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1014:
#line 5450 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 5454 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1016:
#line 5457 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5461 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1018:
#line 5464 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1019:
#line 5465 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1020:
#line 5466 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1021:
#line 5469 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1022:
#line 5472 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1023:
#line 5475 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1024:
#line 5478 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1025:
#line 5481 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1026:
#line 5484 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1027:
#line 5487 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1028:
#line 5504 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1031:
#line 5514 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1032:
#line 5520 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1033:
#line 5524 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1035:
#line 5544 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1036:
#line 5549 "fgl.yacc"
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

  case 1037:
#line 5561 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1038:
#line 5562 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1039:
#line 5566 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1040:
#line 5571 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1041:
#line 5572 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1042:
#line 5576 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1046:
#line 5582 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1047:
#line 5584 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1049:
#line 5599 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1050:
#line 5603 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1051:
#line 5609 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1052:
#line 5610 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1053:
#line 5613 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1054:
#line 5614 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1055:
#line 5617 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1057:
#line 5636 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1058:
#line 5641 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1059:
#line 5646 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1060:
#line 5651 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1066:
#line 5673 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1067:
#line 5680 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1068:
#line 5689 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1069:
#line 5695 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1070:
#line 5697 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1074:
#line 5708 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1075:
#line 5709 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1076:
#line 5715 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1077:
#line 5719 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1078:
#line 5725 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1079:
#line 5726 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1080:
#line 5731 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1081:
#line 5732 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1082:
#line 5734 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1083:
#line 5735 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1084:
#line 5736 "fgl.yacc"
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

  case 1085:
#line 5750 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5752 "fgl.yacc"
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

  case 1087:
#line 5769 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1094:
#line 5781 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1095:
#line 5781 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1096:
#line 5787 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1097:
#line 5787 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1098:
#line 5790 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1099:
#line 5790 "fgl.yacc"
    {
double n;
char buff[256];
strcpy(buff,yyvsp[0].str);
n=atof(yyvsp[-2].str);
if (buff[0]=='1') {
	print_skip_lines(n);
	if (if_print_stack_cnt==0) if_print_section[0]=0;
	if (get_curr_report_stack_whytype()=='T') {
		if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=(int)n;
	}
} else {
	if (rep_type!=REP_TYPE_PDF) { a4gl_yyerror("SKIP BY is only in PDF reports"); YYERROR; } print_skip_by(n);
}
start_state("KWLINE",0); 
}
    break;

  case 1100:
#line 5806 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1101:
#line 5807 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1102:
#line 5808 "fgl.yacc"
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

  case 1103:
#line 5817 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1104:
#line 5829 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1110:
#line 5840 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1111:
#line 5845 "fgl.yacc"
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
	if (strcmp(yyvsp[0].str,"0")==0) {
			if (if_print_stack_cnt==0) if_print_section[0]=0;
		if (get_curr_report_stack_whytype()=='T') {
			if_print_stack[if_print_stack_cnt][if_print_section[if_print_stack_cnt]]+=1;
		}
	}
}
    break;

  case 1112:
#line 5865 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1113:
#line 5870 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1114:
#line 5876 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1115:
#line 5877 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1116:
#line 5878 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1117:
#line 5882 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1118:
#line 5883 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1119:
#line 5884 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1120:
#line 5885 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1121:
#line 5889 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1122:
#line 5899 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1123:
#line 5901 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1124:
#line 5906 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1125:
#line 5909 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1126:
#line 5914 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1127:
#line 5921 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5928 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1129:
#line 5935 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1130:
#line 5944 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1131:
#line 5951 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1132:
#line 5958 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1133:
#line 5965 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1134:
#line 5972 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1139:
#line 5985 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1140:
#line 5986 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1141:
#line 5987 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 5988 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 5989 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 5990 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1145:
#line 5991 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1146:
#line 5992 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1147:
#line 5993 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1148:
#line 5994 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1151:
#line 6000 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1152:
#line 6001 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1153:
#line 6002 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1154:
#line 6003 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1159:
#line 6012 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1160:
#line 6013 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1161:
#line 6014 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1162:
#line 6015 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6016 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6017 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6018 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1166:
#line 6019 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6021 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1168:
#line 6022 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1169:
#line 6023 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1170:
#line 6024 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1171:
#line 6026 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1172:
#line 6027 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1173:
#line 6028 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1174:
#line 6029 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1178:
#line 6034 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1179:
#line 6035 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1183:
#line 6042 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1184:
#line 6050 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1185:
#line 6058 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1186:
#line 6070 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1187:
#line 6079 "fgl.yacc"
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

  case 1188:
#line 6090 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1189:
#line 6094 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1190:
#line 6098 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1191:
#line 6104 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1192:
#line 6109 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1193:
#line 6117 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1194:
#line 6120 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1195:
#line 6129 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1196:
#line 6140 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1198:
#line 6147 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1199:
#line 6155 "fgl.yacc"
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

  case 1200:
#line 6165 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1201:
#line 6168 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1202:
#line 6172 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1203:
#line 6180 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1204:
#line 6183 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1205:
#line 6189 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1206:
#line 6193 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1207:
#line 6197 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1208:
#line 6201 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1209:
#line 6205 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1210:
#line 6211 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1211:
#line 6212 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1212:
#line 6213 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1213:
#line 6214 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1214:
#line 6219 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1215:
#line 6221 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1216:
#line 6224 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1217:
#line 6228 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1218:
#line 6231 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1219:
#line 6238 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1220:
#line 6243 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1221:
#line 6244 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1222:
#line 6245 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1223:
#line 6250 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1224:
#line 6251 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1225:
#line 6257 "fgl.yacc"
    {insql=1;}
    break;

  case 1226:
#line 6257 "fgl.yacc"
    {insql=0;}
    break;

  case 1227:
#line 6257 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1228:
#line 6262 "fgl.yacc"
    {insql=1;}
    break;

  case 1229:
#line 6262 "fgl.yacc"
    {insql=0;}
    break;

  case 1230:
#line 6262 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1231:
#line 6273 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1232:
#line 6274 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1233:
#line 6280 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1234:
#line 6282 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1236:
#line 6295 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1237:
#line 6299 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1238:
#line 6300 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1240:
#line 6305 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1241:
#line 6308 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1242:
#line 6314 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6317 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6325 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1246:
#line 6332 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1247:
#line 6339 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6342 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1249:
#line 6351 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6354 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1251:
#line 6357 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1252:
#line 6360 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1253:
#line 6363 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1254:
#line 6366 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6369 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6376 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1257:
#line 6379 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1258:
#line 6386 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1260:
#line 6395 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 6398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1262:
#line 6405 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1263:
#line 6408 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1265:
#line 6416 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1267:
#line 6425 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1268:
#line 6428 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1269:
#line 6434 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1270:
#line 6437 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1271:
#line 6443 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1272:
#line 6450 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1273:
#line 6451 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1274:
#line 6455 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1275:
#line 6461 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1276:
#line 6464 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1278:
#line 6472 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1279:
#line 6479 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1280:
#line 6482 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1284:
#line 6500 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6506 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1291:
#line 6509 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1292:
#line 6512 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1293:
#line 6518 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1295:
#line 6524 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1297:
#line 6535 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1298:
#line 6549 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1299:
#line 6558 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1300:
#line 6558 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1301:
#line 6563 "fgl.yacc"
    {insql=1;}
    break;

  case 1302:
#line 6563 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1303:
#line 6568 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1304:
#line 6571 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1305:
#line 6573 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6580 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1308:
#line 6584 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1309:
#line 6588 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1310:
#line 6595 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6598 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1312:
#line 6605 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1313:
#line 6609 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1314:
#line 6613 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1315:
#line 6618 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1316:
#line 6623 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1317:
#line 6627 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1318:
#line 6633 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1319:
#line 6637 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1320:
#line 6643 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1321:
#line 6650 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1322:
#line 6654 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1323:
#line 6659 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1324:
#line 6669 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1325:
#line 6672 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1326:
#line 6674 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1327:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1328:
#line 6678 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1329:
#line 6680 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1330:
#line 6682 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6684 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1332:
#line 6690 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1333:
#line 6700 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1334:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1336:
#line 6713 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6722 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1343:
#line 6727 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1344:
#line 6732 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1345:
#line 6739 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1346:
#line 6740 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1347:
#line 6747 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1348:
#line 6758 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1349:
#line 6759 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1350:
#line 6762 "fgl.yacc"
    {insql=1;}
    break;

  case 1351:
#line 6762 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1352:
#line 6767 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1353:
#line 6772 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1355:
#line 6778 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1357:
#line 6782 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1358:
#line 6787 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1359:
#line 6792 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1360:
#line 6796 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1362:
#line 6802 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1363:
#line 6806 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1364:
#line 6814 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6817 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1366:
#line 6819 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1367:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1370:
#line 6831 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6838 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6841 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6843 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6855 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6865 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1384:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1385:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6881 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1390:
#line 6887 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1391:
#line 6895 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6900 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6910 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1398:
#line 6922 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6924 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6930 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6935 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1403:
#line 6938 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1404:
#line 6941 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1405:
#line 6949 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1407:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1408:
#line 6969 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1410:
#line 6973 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1411:
#line 6975 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6982 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6985 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 6991 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1415:
#line 6995 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1416:
#line 6999 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1417:
#line 7003 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1418:
#line 7006 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1419:
#line 7014 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1420:
#line 7021 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1423:
#line 7030 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1424:
#line 7036 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1425:
#line 7039 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1426:
#line 7050 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1427:
#line 7057 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1428:
#line 7063 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1429:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 7073 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1431:
#line 7080 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1433:
#line 7087 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1434:
#line 7093 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1435:
#line 7094 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 7095 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1438:
#line 7099 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7104 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1441:
#line 7111 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1442:
#line 7116 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1443:
#line 7117 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1444:
#line 7120 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1445:
#line 7123 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1446:
#line 7128 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1447:
#line 7129 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1448:
#line 7134 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1449:
#line 7137 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7143 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1451:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1452:
#line 7152 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1453:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 7161 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1455:
#line 7164 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1456:
#line 7171 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1457:
#line 7172 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1458:
#line 7201 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1459:
#line 7203 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7207 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1462:
#line 7220 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1463:
#line 7223 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1464:
#line 7226 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1465:
#line 7229 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1467:
#line 7237 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7240 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1470:
#line 7246 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1472:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1473:
#line 7255 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1474:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1475:
#line 7261 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1476:
#line 7264 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1477:
#line 7267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1478:
#line 7270 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1479:
#line 7273 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1480:
#line 7278 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7285 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1488:
#line 7293 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1489:
#line 7294 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1490:
#line 7299 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1491:
#line 7302 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1492:
#line 7306 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1493:
#line 7312 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1494:
#line 7313 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1495:
#line 7314 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1496:
#line 7315 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1501:
#line 7335 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7340 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7341 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1505:
#line 7344 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7349 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7352 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1513:
#line 7355 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7360 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7362 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1519:
#line 7365 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1520:
#line 7366 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1521:
#line 7373 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1525:
#line 7378 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1529:
#line 7394 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1530:
#line 7395 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1531:
#line 7399 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1532:
#line 7400 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1534:
#line 7419 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1535:
#line 7420 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1536:
#line 7421 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1537:
#line 7425 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1538:
#line 7428 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1539:
#line 7434 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1540:
#line 7439 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1541:
#line 7444 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1543:
#line 7455 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1548:
#line 7470 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1549:
#line 7473 "fgl.yacc"
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

  case 1550:
#line 7486 "fgl.yacc"
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

  case 1551:
#line 7501 "fgl.yacc"
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

  case 1552:
#line 7513 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1553:
#line 7515 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1554:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1555:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1556:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1557:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1558:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1559:
#line 7518 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1560:
#line 7519 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1561:
#line 7522 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1562:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1563:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1564:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1565:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1566:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1567:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1568:
#line 7529 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1569:
#line 7532 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1584:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1585:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1586:
#line 7546 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1587:
#line 7554 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1588:
#line 7554 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1589:
#line 7560 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1590:
#line 7560 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1591:
#line 7567 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1592:
#line 7567 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1593:
#line 7573 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1594:
#line 7573 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1595:
#line 7581 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1596:
#line 7582 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1597:
#line 7583 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1601:
#line 7590 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7591 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7596 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1604:
#line 7599 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1605:
#line 7605 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1606:
#line 7610 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1607:
#line 7619 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1608:
#line 7631 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1609:
#line 7632 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1610:
#line 7635 "fgl.yacc"
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

  case 1611:
#line 7650 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1612:
#line 7660 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1613:
#line 7663 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1614:
#line 7671 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1615:
#line 7680 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1616:
#line 7683 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1617:
#line 7687 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1618:
#line 7690 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1619:
#line 7691 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1621:
#line 7700 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1622:
#line 7701 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1623:
#line 7710 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1624:
#line 7719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1625:
#line 7724 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1626:
#line 7725 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1627:
#line 7726 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1628:
#line 7727 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1629:
#line 7734 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1630:
#line 7737 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1631:
#line 7743 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1632:
#line 7746 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1633:
#line 7756 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1634:
#line 7765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1635:
#line 7768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1636:
#line 7771 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1637:
#line 7777 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7783 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1639:
#line 7786 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7789 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1641:
#line 7792 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1642:
#line 7799 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1643:
#line 7801 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1644:
#line 7803 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1645:
#line 7805 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1646:
#line 7807 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1647:
#line 7808 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1648:
#line 7809 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1649:
#line 7810 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1650:
#line 7811 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1651:
#line 7812 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1652:
#line 7813 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1653:
#line 7815 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1654:
#line 7817 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1655:
#line 7819 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1656:
#line 7821 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1657:
#line 7823 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1658:
#line 7825 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1659:
#line 7827 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7828 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7830 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7834 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1663:
#line 7835 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1665:
#line 7845 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1666:
#line 7854 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1667:
#line 7858 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1668:
#line 7865 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1669:
#line 7865 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1671:
#line 7869 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1672:
#line 7874 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1673:
#line 7874 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1675:
#line 7878 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1676:
#line 7882 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1679:
#line 7891 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1680:
#line 7891 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1685:
#line 7910 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1686:
#line 7911 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1689:
#line 7919 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1690:
#line 7925 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1693:
#line 7944 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1694:
#line 7945 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1695:
#line 7946 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1696:
#line 7947 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1697:
#line 7948 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1698:
#line 7949 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1699:
#line 7953 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1700:
#line 7954 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1701:
#line 7955 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1702:
#line 7959 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1703:
#line 7963 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1705:
#line 7972 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1707:
#line 7977 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1708:
#line 7978 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2029:
#line 8306 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2030:
#line 8306 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2031:
#line 8313 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2032:
#line 8313 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2033:
#line 8401 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2034:
#line 8405 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2035:
#line 8407 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2036:
#line 8414 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2037:
#line 8418 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2038:
#line 8424 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2039:
#line 8432 "fgl.yacc"
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

  case 2040:
#line 8442 "fgl.yacc"
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

  case 2041:
#line 8452 "fgl.yacc"
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

  case 2042:
#line 8464 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2043:
#line 8467 "fgl.yacc"
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

  case 2044:
#line 8486 "fgl.yacc"
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

  case 2045:
#line 8512 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2046:
#line 8515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2048:
#line 8524 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2049:
#line 8529 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2050:
#line 8532 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2051:
#line 8540 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2052:
#line 8548 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2053:
#line 8561 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2054:
#line 8564 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2055:
#line 8572 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2056:
#line 8575 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2057:
#line 8578 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2058:
#line 8586 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2059:
#line 8590 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2060:
#line 8593 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2061:
#line 8596 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2062:
#line 8599 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2063:
#line 8603 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2064:
#line 8604 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2065:
#line 8605 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2066:
#line 8606 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2067:
#line 8607 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2068:
#line 8613 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2069:
#line 8614 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2070:
#line 8615 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2071:
#line 8616 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2072:
#line 8617 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2073:
#line 8618 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2074:
#line 8619 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2075:
#line 8620 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2076:
#line 8621 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2077:
#line 8622 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2078:
#line 8623 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2079:
#line 8624 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8625 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8626 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8630 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2083:
#line 8636 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2084:
#line 8637 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2085:
#line 8650 "fgl.yacc"
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

  case 2086:
#line 8670 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2090:
#line 8676 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2091:
#line 8677 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2095:
#line 8689 "fgl.yacc"
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

  case 2096:
#line 8715 "fgl.yacc"
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

  case 2097:
#line 8766 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2098:
#line 8768 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2099:
#line 8770 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2100:
#line 8771 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2101:
#line 8776 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2102:
#line 8781 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2103:
#line 8782 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2104:
#line 8786 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2105:
#line 8788 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2106:
#line 8790 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2107:
#line 8793 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2108:
#line 8797 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2109:
#line 8802 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2110:
#line 8807 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2111:
#line 8811 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2113:
#line 8821 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2115:
#line 8836 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2116:
#line 8839 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2117:
#line 8843 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2120:
#line 8862 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2121:
#line 8863 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2122:
#line 8866 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2123:
#line 8867 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2124:
#line 8868 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2125:
#line 8869 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2126:
#line 8870 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2127:
#line 8871 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2128:
#line 8872 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2129:
#line 8877 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2130:
#line 8878 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2131:
#line 8882 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2132:
#line 8886 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2133:
#line 8890 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2134:
#line 8894 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2135:
#line 8899 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2136:
#line 8903 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2137:
#line 8908 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2139:
#line 8916 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2141:
#line 8922 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2142:
#line 8928 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2143:
#line 8932 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2148:
#line 8950 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2149:
#line 8957 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2150:
#line 8966 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2151:
#line 8966 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 17994 "y.tab.c"

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


#line 9064 "fgl.yacc"

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



