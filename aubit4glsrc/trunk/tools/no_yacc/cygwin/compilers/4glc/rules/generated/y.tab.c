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
#define YYLAST   10280

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  680
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  835
/* YYNRULES -- Number of rules. */
#define YYNRULES  2238
/* YYNRULES -- Number of states. */
#define YYNSTATES  3514

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
     571,   573,   577,   578,   580,   581,   583,   585,   587,   588,
     596,   597,   603,   604,   617,   619,   621,   623,   625,   627,
     633,   637,   639,   641,   642,   647,   648,   654,   655,   663,
     665,   669,   671,   673,   674,   676,   677,   678,   683,   685,
     687,   689,   694,   699,   706,   708,   711,   713,   715,   717,
     719,   724,   731,   733,   738,   745,   747,   749,   751,   753,
     755,   757,   759,   762,   765,   767,   769,   774,   776,   778,
     779,   783,   787,   788,   791,   793,   795,   797,   799,   801,
     803,   806,   807,   810,   811,   815,   816,   820,   822,   823,
     827,   829,   831,   833,   835,   837,   839,   842,   844,   845,
     847,   848,   854,   856,   858,   860,   865,   870,   877,   879,
     881,   883,   885,   890,   897,   899,   904,   911,   913,   915,
     917,   919,   921,   924,   927,   929,   934,   935,   943,   944,
     957,   958,   963,   964,   970,   972,   976,   979,   981,   985,
     987,   988,   991,   994,   996,   999,  1005,  1010,  1013,  1018,
    1024,  1028,  1029,  1030,  1042,  1043,  1046,  1048,  1049,  1052,
    1054,  1057,  1058,  1062,  1063,  1067,  1068,  1072,  1075,  1078,
    1081,  1086,  1092,  1094,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1131,  1133,  1135,  1137,  1139,  1142,  1144,  1146,  1148,
    1151,  1154,  1156,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1177,  1179,  1182,  1184,  1186,  1188,  1192,  1194,
    1198,  1200,  1204,  1206,  1208,  1210,  1213,  1215,  1217,  1221,
    1226,  1231,  1234,  1237,  1239,  1241,  1243,  1245,  1247,  1251,
    1253,  1256,  1259,  1261,  1262,  1266,  1269,  1272,  1274,  1278,
    1283,  1288,  1294,  1300,  1302,  1304,  1307,  1310,  1315,  1320,
    1323,  1326,  1331,  1336,  1338,  1341,  1344,  1347,  1350,  1353,
    1356,  1359,  1362,  1365,  1368,  1371,  1374,  1377,  1380,  1381,
    1382,  1383,  1390,  1391,  1392,  1401,  1402,  1403,  1410,  1411,
    1412,  1419,  1420,  1421,  1428,  1429,  1430,  1437,  1443,  1449,
    1455,  1463,  1464,  1468,  1470,  1472,  1477,  1482,  1487,  1492,
    1497,  1502,  1504,  1506,  1508,  1510,  1515,  1520,  1523,  1526,
    1529,  1532,  1535,  1537,  1539,  1542,  1544,  1546,  1548,  1551,
    1556,  1563,  1570,  1574,  1580,  1586,  1590,  1592,  1594,  1598,
    1600,  1604,  1605,  1606,  1618,  1619,  1622,  1623,  1624,  1625,
    1635,  1636,  1640,  1641,  1642,  1653,  1654,  1656,  1657,  1659,
    1661,  1664,  1665,  1669,  1670,  1674,  1675,  1677,  1679,  1682,
    1683,  1687,  1688,  1692,  1696,  1698,  1703,  1707,  1709,  1713,
    1715,  1719,  1721,  1725,  1727,  1730,  1731,  1735,  1736,  1740,
    1741,  1746,  1747,  1752,  1753,  1758,  1761,  1765,  1767,  1771,
    1773,  1775,  1777,  1779,  1781,  1783,  1785,  1789,  1791,  1793,
    1798,  1805,  1810,  1814,  1821,  1825,  1832,  1834,  1836,  1838,
    1840,  1842,  1844,  1845,  1848,  1850,  1852,  1854,  1859,  1861,
    1863,  1865,  1870,  1874,  1881,  1885,  1892,  1894,  1896,  1899,
    1902,  1905,  1907,  1911,  1913,  1916,  1919,  1922,  1927,  1930,
    1933,  1938,  1939,  1948,  1949,  1951,  1953,  1955,  1956,  1958,
    1961,  1962,  1964,  1967,  1968,  1970,  1973,  1974,  1976,  1980,
    1981,  1984,  1985,  1986,  1995,  1996,  1997,  2001,  2002,  2003,
    2011,  2017,  2020,  2023,  2024,  2030,  2035,  2037,  2041,  2045,
    2049,  2050,  2053,  2054,  2056,  2058,  2061,  2062,  2067,  2068,
    2073,  2074,  2078,  2079,  2083,  2084,  2088,  2089,  2093,  2094,
    2098,  2099,  2103,  2104,  2108,  2109,  2113,  2114,  2118,  2120,
    2124,  2126,  2130,  2133,  2138,  2140,  2142,  2144,  2145,  2150,
    2156,  2163,  2164,  2175,  2179,  2182,  2185,  2187,  2189,  2190,
    2193,  2195,  2198,  2202,  2206,  2210,  2214,  2216,  2218,  2220,
    2222,  2223,  2227,  2229,  2230,  2234,  2237,  2240,  2242,  2246,
    2248,  2252,  2254,  2256,  2258,  2260,  2262,  2264,  2266,  2268,
    2270,  2272,  2274,  2276,  2278,  2280,  2282,  2284,  2286,  2288,
    2290,  2292,  2293,  2294,  2302,  2304,  2306,  2309,  2312,  2315,
    2319,  2324,  2325,  2329,  2330,  2332,  2334,  2337,  2339,  2341,
    2343,  2345,  2346,  2348,  2350,  2353,  2356,  2358,  2360,  2362,
    2364,  2366,  2368,  2370,  2372,  2374,  2376,  2378,  2380,  2382,
    2383,  2385,  2387,  2389,  2391,  2393,  2394,  2395,  2396,  2397,
    2411,  2413,  2414,  2415,  2422,  2425,  2427,  2430,  2433,  2436,
    2438,  2440,  2443,  2445,  2447,  2449,  2450,  2454,  2457,  2459,
    2460,  2461,  2462,  2477,  2478,  2484,  2486,  2487,  2491,  2492,
    2500,  2501,  2507,  2509,  2512,  2513,  2515,  2517,  2519,  2520,
    2522,  2524,  2527,  2530,  2533,  2535,  2537,  2539,  2541,  2545,
    2547,  2549,  2550,  2551,  2559,  2561,  2564,  2565,  2569,  2570,
    2575,  2578,  2579,  2582,  2584,  2586,  2588,  2590,  2592,  2594,
    2596,  2600,  2601,  2603,  2605,  2607,  2609,  2612,  2615,  2618,
    2624,  2633,  2635,  2637,  2639,  2644,  2649,  2651,  2653,  2655,
    2657,  2660,  2663,  2667,  2674,  2676,  2680,  2682,  2684,  2686,
    2690,  2697,  2707,  2709,  2711,  2713,  2715,  2718,  2719,  2721,
    2723,  2727,  2729,  2733,  2735,  2739,  2741,  2745,  2747,  2749,
    2751,  2753,  2757,  2759,  2763,  2765,  2769,  2771,  2773,  2775,
    2779,  2782,  2783,  2785,  2787,  2792,  2794,  2798,  2800,  2804,
    2812,  2813,  2821,  2822,  2829,  2833,  2835,  2839,  2841,  2844,
    2850,  2851,  2859,  2860,  2863,  2864,  2866,  2872,  2875,  2881,
    2882,  2888,  2895,  2900,  2901,  2903,  2905,  2910,  2911,  2914,
    2915,  2921,  2926,  2929,  2931,  2935,  2938,  2941,  2944,  2947,
    2950,  2953,  2955,  2958,  2961,  2964,  2967,  2970,  2973,  2976,
    2979,  2982,  2984,  2986,  2988,  2990,  2992,  2994,  3000,  3002,
    3004,  3007,  3012,  3015,  3017,  3018,  3030,  3031,  3034,  3040,
    3041,  3043,  3044,  3047,  3049,  3052,  3053,  3057,  3059,  3060,
    3065,  3066,  3069,  3071,  3075,  3077,  3079,  3083,  3088,  3093,
    3096,  3098,  3100,  3102,  3103,  3105,  3113,  3116,  3119,  3122,
    3125,  3128,  3130,  3133,  3134,  3138,  3139,  3143,  3144,  3148,
    3149,  3153,  3154,  3158,  3159,  3164,  3165,  3170,  3172,  3174,
    3176,  3178,  3180,  3182,  3183,  3188,  3189,  3191,  3192,  3197,
    3199,  3202,  3205,  3208,  3209,  3211,  3213,  3216,  3219,  3220,
    3223,  3227,  3231,  3237,  3238,  3241,  3246,  3248,  3250,  3252,
    3254,  3256,  3257,  3259,  3261,  3265,  3268,  3274,  3277,  3283,
    3289,  3295,  3301,  3307,  3313,  3314,  3317,  3319,  3322,  3325,
    3328,  3331,  3334,  3337,  3339,  3342,  3345,  3348,  3351,  3353,
    3356,  3359,  3362,  3365,  3367,  3369,  3371,  3372,  3375,  3378,
    3381,  3384,  3387,  3390,  3393,  3396,  3399,  3401,  3403,  3405,
    3407,  3409,  3411,  3413,  3415,  3418,  3421,  3424,  3427,  3430,
    3432,  3434,  3436,  3437,  3441,  3444,  3445,  3446,  3447,  3448,
    3449,  3450,  3466,  3467,  3470,  3473,  3474,  3476,  3477,  3478,
    3479,  3480,  3481,  3482,  3498,  3501,  3502,  3503,  3504,  3515,
    3516,  3518,  3522,  3526,  3529,  3534,  3538,  3542,  3546,  3548,
    3550,  3552,  3554,  3556,  3558,  3559,  3560,  3568,  3569,  3570,
    3579,  3583,  3586,  3587,  3589,  3591,  3595,  3598,  3601,  3603,
    3605,  3609,  3611,  3613,  3616,  3618,  3622,  3624,  3628,  3630,
    3632,  3634,  3636,  3638,  3640,  3642,  3645,  3650,  3652,  3656,
    3658,  3662,  3665,  3670,  3672,  3676,  3678,  3681,  3686,  3688,
    3692,  3694,  3696,  3698,  3701,  3704,  3709,  3712,  3717,  3719,
    3723,  3725,  3727,  3729,  3732,  3734,  3736,  3738,  3740,  3742,
    3745,  3752,  3759,  3760,  3762,  3763,  3765,  3768,  3770,  3771,
    3777,  3778,  3784,  3786,  3787,  3791,  3793,  3797,  3799,  3803,
    3805,  3807,  3808,  3809,  3815,  3817,  3820,  3822,  3823,  3824,
    3828,  3829,  3830,  3834,  3836,  3838,  3840,  3842,  3844,  3846,
    3849,  3852,  3857,  3861,  3865,  3867,  3871,  3874,  3876,  3878,
    3879,  3881,  3883,  3885,  3887,  3888,  3890,  3894,  3896,  3898,
    3899,  3903,  3905,  3907,  3909,  3911,  3913,  3915,  3917,  3919,
    3921,  3923,  3925,  3927,  3935,  3936,  3938,  3940,  3942,  3944,
    3948,  3950,  3952,  3954,  3957,  3958,  3962,  3964,  3968,  3970,
    3974,  3976,  3978,  3985,  3986,  3990,  3992,  3996,  3997,  3999,
    4004,  4010,  4013,  4015,  4017,  4022,  4024,  4028,  4033,  4038,
    4040,  4044,  4046,  4048,  4050,  4053,  4055,  4060,  4061,  4063,
    4064,  4066,  4068,  4071,  4073,  4075,  4077,  4079,  4084,  4088,
    4090,  4092,  4094,  4097,  4099,  4101,  4104,  4107,  4109,  4113,
    4116,  4119,  4121,  4125,  4127,  4130,  4135,  4137,  4140,  4142,
    4146,  4151,  4152,  4154,  4155,  4157,  4158,  4160,  4162,  4166,
    4168,  4172,  4174,  4177,  4179,  4183,  4186,  4189,  4190,  4193,
    4195,  4197,  4203,  4207,  4213,  4217,  4219,  4223,  4225,  4227,
    4228,  4230,  4234,  4238,  4242,  4249,  4254,  4259,  4264,  4269,
    4275,  4277,  4279,  4281,  4283,  4285,  4287,  4289,  4291,  4293,
    4295,  4297,  4299,  4300,  4302,  4304,  4306,  4308,  4310,  4312,
    4314,  4319,  4325,  4327,  4333,  4339,  4341,  4343,  4345,  4350,
    4352,  4357,  4359,  4367,  4369,  4371,  4373,  4378,  4385,  4386,
    4389,  4394,  4396,  4398,  4400,  4402,  4404,  4406,  4408,  4412,
    4414,  4416,  4420,  4422,  4423,  4427,  4433,  4435,  4438,  4441,
    4446,  4450,  4452,  4454,  4456,  4458,  4460,  4462,  4465,  4468,
    4469,  4473,  4474,  4478,  4480,  4482,  4484,  4486,  4488,  4490,
    4492,  4497,  4499,  4501,  4503,  4505,  4507,  4509,  4511,  4516,
    4518,  4520,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,
    4538,  4540,  4542,  4544,  4546,  4548,  4552,  4553,  4562,  4563,
    4573,  4574,  4582,  4583,  4593,  4594,  4596,  4599,  4601,  4605,
    4607,  4611,  4617,  4619,  4621,  4623,  4625,  4628,  4629,  4630,
    4639,  4645,  4647,  4649,  4656,  4657,  4661,  4663,  4667,  4672,
    4674,  4675,  4678,  4683,  4690,  4691,  4693,  4695,  4697,  4699,
    4703,  4705,  4708,  4710,  4712,  4715,  4718,  4720,  4722,  4724,
    4727,  4732,  4736,  4739,  4743,  4747,  4751,  4753,  4755,  4757,
    4759,  4761,  4763,  4769,  4775,  4781,  4787,  4793,  4798,  4803,
    4807,  4812,  4814,  4818,  4820,  4826,  4834,  4840,  4841,  4844,
    4846,  4848,  4849,  4853,  4855,  4859,  4861,  4863,  4865,  4866,
    4870,  4872,  4874,  4876,  4878,  4883,  4890,  4892,  4894,  4897,
    4901,  4903,  4905,  4907,  4909,  4911,  4913,  4915,  4917,  4923,
    4929,  4934,  4935,  4940,  4942,  4945,  4947,  4949,  4951,  4953,
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
    5575,  5577,  5579,  5581,  5583,  5585,  5587,  5589,  5591,  5592,
    5596,  5597,  5601,  5602,  5603,  5610,  5611,  5614,  5617,  5625,
    5629,  5633,  5636,  5639,  5642,  5644,  5648,  5650,  5654,  5656,
    5660,  5662,  5666,  5668,  5670,  5672,  5675,  5678,  5680,  5682,
    5685,  5690,  5692,  5694,  5696,  5698,  5700,  5702,  5706,  5709,
    5713,  5717,  5721,  5727,  5733,  5739,  5745,  5751,  5756,  5761,
    5765,  5770,  5772,  5774,  5778,  5780,  5783,  5785,  5787,  5789,
    5793,  5799,  5801,  5803,  5805,  5807,  5811,  5814,  5817,  5820,
    5822,  5825,  5828,  5830,  5833,  5836,  5839,  5841,  5845,  5848,
    5850,  5853,  5855,  5858,  5860,  5861,  5862,  5869,  5870,  5873,
    5874,  5876,  5878,  5881,  5884,  5886,  5888,  5893,  5897,  5899,
    5903,  5905,  5908,  5914,  5917,  5920,  5926,  5927,  5930,  5932,
    5934,  5937,  5944,  5951,  5953,  5954,  5956,  5959,  5961,  5964,
    5965,  5968,  5970,  5972,  5974,  5976,  5978,  5980,  5982,  5984,
    5986,  5988,  5990,  5992,  5994,  5996,  5998,  6000,  6002,  6004,
    6006,  6008,  6010,  6012,  6014,  6016,  6018,  6020,  6022,  6024,
    6026,  6028,  6030,  6032,  6034,  6036,  6038,  6040,  6042,  6044,
    6046,  6048,  6050,  6052,  6054,  6056,  6058,  6060,  6062,  6064,
    6066,  6068,  6070,  6072,  6074,  6076,  6078,  6080,  6082,  6084,
    6086,  6088,  6090,  6092,  6094,  6096,  6098,  6100,  6102,  6104,
    6106,  6108,  6110,  6112,  6114,  6116,  6118,  6120,  6122,  6124,
    6126,  6128,  6130,  6132,  6134,  6136,  6138,  6140,  6142
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1043,     0,    -1,   201,    -1,   198,    -1,   125,   685,   428,
     597,   686,    -1,   139,    -1,  1108,    -1,    26,    -1,   687,
      -1,   686,     5,   687,    -1,   955,    -1,   432,   688,   393,
      -1,   688,   689,   688,    -1,    26,    -1,   690,    26,    -1,
    1108,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      22,    -1,    18,    -1,    19,    -1,    -1,   692,    -1,    -1,
     275,   432,   693,   694,   393,    -1,   570,   432,    26,     5,
      26,   393,    -1,   695,    -1,   694,     5,   695,    -1,   491,
      -1,   532,    -1,   538,    -1,   507,    -1,   411,    -1,   606,
      -1,   529,    -1,   481,    -1,   418,    -1,   492,    -1,   346,
      -1,   533,    -1,   457,    -1,   333,    -1,   595,    -1,    99,
      -1,  1022,    -1,    -1,   697,    -1,    -1,   275,   432,   698,
     699,   393,    -1,   700,    -1,   699,     5,   700,    -1,   695,
      -1,   433,    -1,   604,    25,    -1,   204,   942,    -1,   330,
     942,    -1,   285,   942,    -1,   338,   942,    -1,   294,   942,
      -1,   260,   942,    -1,   535,   702,    -1,   886,   345,  1108,
      -1,    -1,   290,   432,  1499,   393,   345,   703,  1127,    -1,
     105,   432,   955,     5,    25,     5,    25,   393,    -1,   408,
     432,   947,   393,   345,  1108,    -1,  1246,    -1,   193,   432,
     905,   393,   345,  1108,    -1,    -1,    -1,  1108,   591,   955,
     432,   704,   718,   393,   705,   716,    -1,    -1,    -1,    -1,
     955,   432,   706,   718,   707,   393,   708,   716,    -1,    -1,
      -1,   475,  1444,   624,  1444,   432,   709,   718,   710,   393,
     716,    -1,    -1,    -1,   955,   522,   955,   432,   711,   718,
     712,   393,   716,    -1,    -1,    -1,    -1,   366,   721,   591,
     722,   460,   685,   428,   432,   713,   718,   714,   393,   715,
     717,    -1,    -1,   345,  1127,    -1,    -1,   345,  1127,    -1,
     163,    -1,    -1,   719,    -1,   720,    -1,   719,     5,   720,
      -1,   855,    -1,    25,    -1,   955,    -1,   955,    -1,   955,
     621,   955,    -1,    -1,   536,   862,   724,   727,   731,   728,
      -1,    -1,   536,   725,   726,   729,   728,    -1,   733,    -1,
     726,   733,    -1,   735,    -1,   727,   735,    -1,   361,    -1,
      -1,    -1,   340,   730,  1509,    -1,    -1,    -1,   340,   732,
    1509,    -1,    -1,   580,   862,   734,  1509,    -1,    -1,   580,
     862,   736,  1509,    -1,   279,   952,    -1,   203,   950,    -1,
      84,   950,    -1,   169,    -1,   186,  1450,    -1,   495,   949,
      -1,    30,   739,    31,    -1,   740,    -1,   742,    -1,   741,
      -1,   740,   741,    -1,    29,    -1,   743,    -1,   742,   743,
      -1,    28,    -1,   395,    -1,    -1,    -1,   321,   746,   748,
     747,   749,    -1,   386,  1108,   626,   750,   996,  1021,   691,
      -1,  1108,   626,   750,   996,   548,  1499,  1021,   691,    -1,
      -1,   752,   192,    -1,   751,    -1,   750,     5,   751,    -1,
     955,    -1,   955,   621,   955,    -1,   955,   621,    20,    -1,
     753,    -1,   752,   753,    -1,    -1,   271,   759,   754,  1509,
      -1,    -1,   274,   760,   755,  1509,    -1,    -1,  1024,   756,
    1509,    -1,    -1,   167,   757,  1509,    -1,    -1,   164,   758,
    1509,    -1,   959,    -1,   759,     5,   959,    -1,   959,    -1,
     760,     5,   959,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    97,    -1,    98,    -1,   432,   855,   763,   393,
      -1,    -1,     5,   806,   627,   809,    -1,   156,    -1,   280,
      -1,    -1,   766,    -1,   767,    -1,   766,   767,    -1,    -1,
      -1,   439,   768,   770,   769,  1215,    -1,   819,    -1,  1489,
      -1,   773,    -1,   770,     5,   773,    -1,    -1,   772,   955,
      -1,   354,   771,   818,    25,    -1,   354,   771,   818,   955,
      -1,   354,   771,   818,   961,    -1,   354,   771,   818,    26,
      -1,   777,   795,    -1,    -1,   771,   354,   774,   775,    -1,
      26,    -1,    25,    -1,   961,    -1,    19,    26,    -1,   771,
      -1,   776,    -1,   777,     5,   776,    -1,    -1,   537,    -1,
      -1,   675,    -1,   676,    -1,   677,    -1,    -1,   488,   460,
     787,   428,   781,   625,   795,    -1,    -1,   671,   779,   782,
     625,   795,    -1,    -1,   319,   778,   784,    26,   785,   303,
     460,   786,   428,   783,   625,   795,    -1,   432,    -1,   459,
      -1,   393,    -1,   427,    -1,    26,    -1,   788,     5,   788,
       5,   788,    -1,   788,     5,   788,    -1,   788,    -1,    26,
      -1,    -1,   465,   790,   770,   284,    -1,    -1,   261,   791,
     771,   621,    20,    -1,    -1,   335,   792,   771,   259,   432,
     793,   393,    -1,   794,    -1,   793,     5,   794,    -1,   771,
      -1,   797,    -1,    -1,    59,    -1,    -1,    -1,   798,   800,
     799,   796,    -1,   780,    -1,   789,    -1,   537,    -1,   537,
     432,    26,   393,    -1,   425,   432,    26,   393,    -1,   425,
     432,    26,     5,    26,   393,    -1,   409,    -1,   618,   771,
      -1,   381,    -1,   510,    -1,    90,    -1,   399,    -1,   399,
     432,    26,   393,    -1,   399,   432,    26,     5,    26,   393,
      -1,   513,    -1,   513,   432,    26,   393,    -1,   513,   432,
      26,     5,    26,   393,    -1,   503,    -1,   300,    -1,   539,
      -1,   534,    -1,    80,    -1,    81,    -1,   576,    -1,   358,
     804,    -1,   370,   805,    -1,   801,    -1,    32,    -1,   558,
     802,   621,   803,    -1,   771,    -1,   771,    -1,    -1,   806,
     627,   809,    -1,   814,   627,   817,    -1,    -1,   807,   808,
      -1,   583,    -1,   514,    -1,   592,    -1,   554,    -1,   455,
      -1,   471,    -1,   367,   811,    -1,    -1,   810,   808,    -1,
      -1,   432,   813,   393,    -1,    -1,   432,    26,   393,    -1,
      26,    -1,    -1,   815,   816,   812,    -1,   583,    -1,   514,
      -1,   592,    -1,   554,    -1,   455,    -1,   471,    -1,   367,
     811,    -1,   816,    -1,    -1,    14,    -1,    -1,   237,   955,
     820,   618,   821,    -1,   823,    -1,   826,    -1,   537,    -1,
     537,   432,    26,   393,    -1,   425,   432,    26,   393,    -1,
     425,   432,    26,     5,    26,   393,    -1,   409,    -1,   381,
      -1,   510,    -1,   399,    -1,   399,   432,    26,   393,    -1,
     399,   432,    26,     5,    26,   393,    -1,   513,    -1,   513,
     432,    26,   393,    -1,   513,   432,    26,     5,    26,   393,
      -1,   503,    -1,   300,    -1,   539,    -1,   534,    -1,   576,
      -1,   358,   804,    -1,   370,   805,    -1,   822,    -1,   558,
     802,   621,   803,    -1,    -1,   488,   460,   787,   428,   824,
     625,   821,    -1,    -1,   319,   778,   784,    26,   785,   303,
     460,   786,   428,   825,   625,   821,    -1,    -1,   465,   827,
     829,   284,    -1,    -1,   261,   828,   955,   621,    20,    -1,
     830,    -1,   829,     5,   830,    -1,   831,   821,    -1,   832,
      -1,   831,     5,   832,    -1,   955,    -1,    -1,   619,   946,
      -1,    71,   955,    -1,    69,    -1,   627,  1499,    -1,   627,
     510,   955,   660,  1499,    -1,   627,   510,   955,   391,    -1,
      73,   955,    -1,   157,   880,  1127,   841,    -1,   402,   880,
     860,   833,   841,    -1,   210,   952,   841,    -1,    -1,    -1,
     189,   838,  1134,   627,   955,   621,    20,   840,   691,   839,
     842,    -1,    -1,   469,   947,    -1,   691,    -1,    -1,   843,
     239,    -1,   844,    -1,   843,   844,    -1,    -1,   352,   845,
    1509,    -1,    -1,   348,   846,  1509,    -1,    -1,  1024,   847,
    1509,    -1,   673,  1108,    -1,   674,  1108,    -1,   672,  1108,
      -1,   499,   880,   861,   691,    -1,   499,   880,   861,   691,
      66,    -1,   287,    -1,   286,    -1,   213,    -1,   365,    -1,
     174,    -1,   212,    -1,   329,    -1,   328,    -1,   244,    -1,
     171,    -1,   170,    -1,   145,    -1,   205,    -1,   128,    -1,
     144,    -1,   188,    -1,   154,    -1,   214,    -1,   214,   862,
      -1,   865,    -1,   864,    -1,   869,    -1,   897,    -1,   855,
     856,    -1,   898,    -1,   900,    -1,   866,    -1,    19,   855,
      -1,    18,   855,    -1,   871,    -1,   879,    -1,   873,    -1,
     476,    -1,   761,    -1,   874,    -1,   875,    -1,   876,    -1,
     877,    -1,   878,    -1,    35,   855,    -1,   880,    -1,   880,
     859,    -1,   862,    -1,   484,    -1,   858,    -1,   859,     5,
     858,    -1,   862,    -1,   860,     5,   862,    -1,   862,    -1,
     861,     5,   862,    -1,   855,    -1,    18,    -1,    19,    -1,
       9,   855,    -1,   485,    -1,   429,    -1,   432,   855,   393,
      -1,   444,   432,  1424,   393,    -1,   295,   432,  1424,   393,
      -1,   863,   961,    -1,   863,    26,    -1,    25,    -1,   961,
      -1,    26,    -1,   868,    -1,  1108,    -1,  1108,   422,  1108,
      -1,   867,    -1,   435,   855,    -1,   394,   855,    -1,  1218,
      -1,    -1,   508,   870,  1218,    -1,     7,   855,    -1,     6,
     855,    -1,   855,    -1,   872,     5,   855,    -1,   624,   432,
    1424,   393,    -1,   430,   432,  1424,   393,    -1,   624,   432,
     880,   872,   393,    -1,   430,   432,   880,   872,   393,    -1,
     388,    -1,   250,    -1,    10,   855,    -1,   253,   855,    -1,
      10,   855,   443,    25,    -1,   253,   855,   443,    25,    -1,
     558,   855,    -1,   372,   855,    -1,   558,   855,   443,    25,
      -1,   372,   855,   443,    25,    -1,   392,    -1,     8,   855,
      -1,    18,   855,    -1,    19,   855,    -1,    20,   855,    -1,
      21,   855,    -1,    22,   855,    -1,    11,   855,    -1,    14,
     855,    -1,   458,   855,    -1,    12,   855,    -1,    13,   855,
      -1,    17,   855,    -1,    16,   855,    -1,    15,   855,    -1,
      -1,    -1,    -1,   955,   432,   882,   718,   883,   393,    -1,
      -1,    -1,   955,   522,   955,   432,   884,   718,   885,   393,
      -1,    -1,    -1,   539,   432,   887,   855,   888,   393,    -1,
      -1,    -1,   514,   432,   889,   855,   890,   393,    -1,    -1,
      -1,   592,   432,   891,   855,   892,   393,    -1,    -1,    -1,
     583,   432,   893,   855,   894,   393,    -1,   370,   432,   901,
     393,   896,    -1,   358,   432,    25,   393,   895,    -1,   358,
     432,    26,   393,   895,    -1,   358,   432,    26,   591,    26,
     393,   895,    -1,    -1,  1404,   627,  1405,    -1,   805,    -1,
     886,    -1,   290,   432,  1499,   393,    -1,   100,   432,   947,
     393,    -1,    72,   432,   947,   393,    -1,   408,   432,  1499,
     393,    -1,   193,   432,  1499,   393,    -1,    60,   432,  1499,
     393,    -1,   899,    -1,   881,    -1,  1400,    -1,   539,    -1,
     424,   432,   855,   393,    -1,   323,   432,   855,   393,    -1,
     489,   855,    -1,   445,   762,    -1,   855,   109,    -1,   855,
     110,    -1,   855,   111,    -1,    25,    -1,   902,    -1,    19,
     902,    -1,   904,    -1,   903,    -1,    26,    -1,    26,    26,
      -1,    26,    26,   591,    26,    -1,    26,    26,   591,    26,
     591,    26,    -1,    26,    26,   591,    26,   591,    24,    -1,
      26,   591,    26,    -1,    26,   591,    26,   591,    26,    -1,
      26,   591,    26,   591,    24,    -1,    26,   591,    24,    -1,
      24,    -1,    26,    -1,    26,    19,    26,    -1,   947,    -1,
     905,     5,   947,    -1,    -1,    -1,   597,  1108,    14,   862,
     627,   862,   909,   907,  1509,   908,   242,    -1,    -1,   573,
     862,    -1,    -1,    -1,    -1,   405,   911,   949,   912,   914,
    1305,   913,  1509,   241,    -1,    -1,     8,   880,   860,    -1,
      -1,    -1,   639,   955,   916,   765,   917,  1053,   919,   918,
     924,   640,    -1,    -1,   929,    -1,    -1,   920,    -1,   921,
      -1,   920,   921,    -1,    -1,   641,   922,  1509,    -1,    -1,
     642,   923,  1509,    -1,    -1,   925,    -1,   926,    -1,   925,
     926,    -1,    -1,   643,   927,  1509,    -1,    -1,   644,   928,
    1509,    -1,   930,   934,   325,    -1,    92,    -1,    92,   931,
     548,   932,    -1,    92,   386,   933,    -1,  1108,    -1,   931,
       5,  1108,    -1,   955,    -1,   932,     5,   955,    -1,  1108,
      -1,   933,     5,  1108,    -1,   935,    -1,   934,   935,    -1,
      -1,   645,   936,  1509,    -1,    -1,   646,   937,  1509,    -1,
      -1,   665,   932,   938,  1509,    -1,    -1,   482,   932,   939,
    1509,    -1,    -1,   626,   932,   940,  1509,    -1,   547,   948,
      -1,   556,    19,    26,    -1,   556,    -1,   502,    18,    26,
      -1,   502,    -1,    26,    -1,  1108,    -1,   670,    -1,    25,
      -1,   960,    -1,   862,    -1,   944,     5,   944,    -1,   945,
      -1,   955,    -1,   668,   432,   955,   393,    -1,   955,   621,
     668,   432,   955,   393,    -1,   955,   460,   688,   428,    -1,
     955,   621,    20,    -1,   955,   460,   688,   428,   621,    20,
      -1,   955,   621,   955,    -1,   955,   460,   688,   428,   621,
     955,    -1,   956,    -1,   956,    -1,   956,    -1,   956,    -1,
     956,    -1,   956,    -1,    -1,   552,    26,    -1,  1508,    -1,
     957,    -1,  1508,    -1,   350,   432,   958,   393,    -1,  1111,
      -1,    25,    -1,   955,    -1,   955,   460,   688,   428,    -1,
     955,   621,    20,    -1,   955,   460,   688,   428,   621,    20,
      -1,   955,   621,   955,    -1,   955,   460,   688,   428,   621,
     955,    -1,  1108,    -1,    24,    -1,   621,    26,    -1,   549,
    1491,    -1,   653,   964,    -1,   965,    -1,   964,     5,   965,
      -1,   955,    -1,   664,   964,    -1,   655,   964,    -1,   656,
    1499,    -1,   654,   952,   660,  1499,    -1,   658,   964,    -1,
     659,  1499,    -1,   657,   952,   660,  1499,    -1,    -1,   662,
     970,   860,   975,   977,   979,   971,   973,    -1,    -1,   972,
      -1,   650,    -1,   651,    -1,    -1,   974,    -1,   345,  1108,
      -1,    -1,   976,    -1,   391,   860,    -1,    -1,   978,    -1,
     661,    26,    -1,    -1,   980,    -1,   652,    26,   981,    -1,
      -1,   401,    26,    -1,    -1,    -1,   623,   862,   577,   983,
    1509,   984,   985,   442,    -1,    -1,    -1,   544,   986,  1509,
      -1,    -1,    -1,    63,   987,   862,   577,   988,  1509,   985,
      -1,   107,   955,   432,    26,   393,    -1,    56,   955,    -1,
      76,   955,    -1,    -1,   291,  1139,   992,   627,   484,    -1,
     291,  1139,   558,   993,    -1,   994,    -1,   993,     5,   994,
      -1,   802,   621,  1396,    -1,   802,   621,    20,    -1,    -1,
     997,   325,    -1,    -1,   151,    -1,   998,    -1,   997,   998,
      -1,    -1,   271,  1010,   999,  1509,    -1,    -1,   274,  1011,
    1000,  1509,    -1,    -1,   352,  1001,  1509,    -1,    -1,   348,
    1002,  1509,    -1,    -1,  1024,  1003,  1509,    -1,    -1,   306,
    1004,  1509,    -1,    -1,   276,  1005,  1509,    -1,    -1,    36,
    1006,  1509,    -1,    -1,    34,  1007,  1509,    -1,    -1,    38,
    1008,  1509,    -1,    -1,    37,  1009,  1509,    -1,   947,    -1,
    1010,     5,   947,    -1,   947,    -1,  1011,     5,   947,    -1,
     315,  1014,    -1,   316,   955,   660,  1014,    -1,   563,    -1,
     376,    -1,   947,    -1,    -1,   666,  1017,  1016,   995,    -1,
     386,  1127,   996,   954,   691,    -1,  1127,   996,   548,  1499,
     954,   691,    -1,    -1,   488,  1134,   996,   548,   955,   621,
      20,   954,  1018,   691,    -1,   470,  1499,  1020,    -1,    82,
      26,    -1,    83,    26,    -1,   628,    -1,   541,    -1,    -1,
     552,    26,    -1,  1023,    -1,    44,    25,    -1,   497,    14,
      26,    -1,   497,    14,  1108,    -1,    45,    14,    26,    -1,
      45,    14,  1108,    -1,    41,    -1,    43,    -1,    40,    -1,
      42,    -1,    -1,   431,  1025,  1030,    -1,   296,    -1,    -1,
     598,  1027,  1030,    -1,   304,  1032,    -1,   598,  1030,    -1,
    1032,    -1,   432,  1031,   393,    -1,  1032,    -1,  1031,     5,
    1032,    -1,  1033,    -1,   596,    -1,   313,    -1,   331,    -1,
     305,    -1,   486,    -1,   443,    -1,   628,    -1,   552,    -1,
     541,    -1,   178,    -1,   440,    -1,   451,    -1,   542,    -1,
     557,    -1,   521,    -1,   311,    -1,   312,    -1,    25,    -1,
     511,    -1,    -1,    -1,   600,  1036,  1132,  1037,    14,   880,
    1038,    -1,   484,    -1,   861,    -1,   220,  1108,    -1,   209,
    1108,    -1,   223,  1108,    -1,   452,  1108,   334,    -1,   452,
    1108,   387,   943,    -1,    -1,  1045,  1044,  1048,    -1,    -1,
    1046,    -1,  1047,    -1,  1046,  1047,    -1,   990,    -1,  1052,
      -1,  1068,    -1,  1054,    -1,    -1,  1049,    -1,  1051,    -1,
    1049,  1051,    -1,    67,   955,    -1,  1056,    -1,  1062,    -1,
    1074,    -1,  1228,    -1,  1238,    -1,  1095,    -1,  1489,    -1,
     915,    -1,   738,    -1,   989,    -1,   744,    -1,   738,    -1,
    1489,    -1,    -1,   738,    -1,  1489,    -1,   766,    -1,   368,
      -1,    61,    -1,    -1,    -1,    -1,    -1,  1055,  1057,   955,
     432,  1058,  1125,   393,  1059,   765,  1060,  1053,  1509,  1061,
      -1,   211,    -1,    -1,    -1,   559,  1063,   765,  1064,  1509,
     362,    -1,   178,   857,    -1,   880,    -1,   880,   860,    -1,
     357,  1408,    -1,   468,  1408,    -1,  1069,    -1,  1070,    -1,
    1069,  1070,    -1,  1071,    -1,  1052,    -1,  1067,    -1,    -1,
     407,  1072,  1073,    -1,   765,   243,    -1,   943,    -1,    -1,
      -1,    -1,   114,   955,   113,   955,   432,  1075,  1125,   393,
    1076,   765,  1077,  1053,  1509,  1061,    -1,    -1,   560,  1079,
    1094,  1085,  1080,    -1,   363,    -1,    -1,   235,  1082,  1509,
      -1,    -1,    23,  1086,  1087,  1088,   954,  1083,  1509,    -1,
      -1,    23,  1086,   954,  1084,  1509,    -1,  1081,    -1,  1085,
    1081,    -1,    -1,  1026,    -1,    25,    -1,  1108,    -1,    -1,
    1108,    -1,    25,    -1,   252,  1092,    -1,   264,  1093,    -1,
     247,  1093,    -1,   587,    -1,    25,    -1,  1108,    -1,  1092,
      -1,  1093,     5,  1092,    -1,  1108,    -1,    25,    -1,    -1,
      -1,   647,   955,  1096,   765,  1097,  1098,   648,    -1,  1099,
      -1,  1098,  1099,    -1,    -1,   649,  1100,  1509,    -1,    -1,
     626,   955,  1101,  1509,    -1,  1105,  1103,    -1,    -1,   692,
    1106,    -1,  1107,    -1,  1104,    -1,   976,    -1,   978,    -1,
     980,    -1,   972,    -1,   974,    -1,   371,   880,   860,    -1,
      -1,    66,    -1,    66,    -1,  1109,    -1,  1111,    -1,   191,
    1111,    -1,  1111,   621,    -1,  1110,  1115,    -1,  1110,   955,
     460,  1119,   428,    -1,  1110,   955,   460,  1119,   428,   460,
    1119,   428,    -1,  1116,    -1,   955,    -1,  1112,    -1,   955,
     459,  1114,   427,    -1,   955,   459,  1114,   427,    -1,  1108,
      -1,    25,    -1,    20,    -1,   955,    -1,   955,  1118,    -1,
     955,  1118,    -1,   460,  1119,   428,    -1,   460,  1119,   428,
     460,  1119,   428,    -1,  1120,    -1,  1119,     5,  1120,    -1,
     688,    -1,  1122,    -1,  1124,    -1,  1122,   621,  1123,    -1,
    1122,   621,   955,   460,  1119,   428,    -1,  1122,   621,   955,
     460,  1119,   428,   460,  1119,   428,    -1,   955,    -1,  1113,
      -1,    20,    -1,   955,    -1,   955,  1118,    -1,    -1,  1126,
      -1,  1128,    -1,  1126,     5,  1128,    -1,  1129,    -1,  1127,
       5,  1129,    -1,   955,    -1,   955,   621,   955,    -1,  1108,
      -1,  1108,   422,  1108,    -1,    25,    -1,   961,    -1,    26,
      -1,  1131,    -1,  1130,     5,  1131,    -1,  1108,    -1,  1108,
     422,  1108,    -1,  1133,    -1,  1132,     5,  1133,    -1,  1121,
      -1,  1108,    -1,  1136,    -1,  1135,     5,  1136,    -1,  1108,
    1137,    -1,    -1,   589,    -1,   540,    -1,   955,   460,  1119,
     428,    -1,  1140,    -1,  1139,     5,  1140,    -1,  1108,    -1,
    1108,   422,  1108,    -1,   255,   951,   619,   945,   581,  1501,
     696,    -1,    -1,   619,   432,   862,     5,   862,   393,  1143,
      -1,    -1,   570,   432,   862,     5,   862,   393,    -1,   256,
     955,  1142,    -1,   955,    -1,   339,   953,  1147,    -1,  1148,
      -1,   548,   862,    -1,  1149,  1150,  1155,     8,  1145,    -1,
      -1,   619,  1151,   432,   862,     5,   862,   393,    -1,    -1,
     558,   956,    -1,    -1,   351,    -1,   218,  1450,   267,  1484,
    1154,    -1,   565,   948,    -1,   565,   948,     8,   880,   860,
      -1,    -1,   618,   578,  1444,   375,  1444,    -1,   618,   578,
    1444,     5,   375,  1444,    -1,   618,  1444,     5,  1444,    -1,
      -1,   650,    -1,   651,    -1,    91,  1484,  1157,  1158,    -1,
      -1,   618,  1484,    -1,    -1,   618,   578,  1444,     8,  1444,
      -1,   578,  1444,     8,  1444,    -1,   413,  1160,    -1,  1161,
      -1,  1160,     5,  1161,    -1,   204,   942,    -1,   285,   942,
      -1,   330,   942,    -1,   338,   942,    -1,   294,   942,    -1,
     260,   942,    -1,  1028,    -1,   440,  1029,    -1,   451,  1029,
      -1,   563,  1029,    -1,   376,  1029,    -1,   552,  1029,    -1,
     550,   943,    -1,   551,   943,    -1,   402,   692,    -1,   666,
     692,    -1,   292,    -1,   196,    -1,   152,    -1,   129,    -1,
     147,    -1,   138,    -1,  1449,   415,  1165,   548,  1163,    -1,
    1108,    -1,    25,    -1,   404,  1165,    -1,   404,  1165,     8,
    1127,    -1,    39,  1163,    -1,   956,    -1,    -1,   463,  1175,
     691,   597,  1170,  1108,  1168,   954,   691,  1167,  1171,    -1,
      -1,   669,    26,    -1,   463,  1175,   691,   345,  1108,    -1,
      -1,   537,    -1,    -1,  1172,   283,    -1,  1173,    -1,  1172,
    1173,    -1,    -1,  1024,  1174,  1509,    -1,   861,    -1,    -1,
     605,   948,  1177,  1178,    -1,    -1,   548,  1179,    -1,  1180,
      -1,  1179,     5,  1180,    -1,  1436,    -1,   484,    -1,   221,
    1183,    89,    -1,   221,  1183,   627,  1182,    -1,   221,  1183,
      88,  1182,    -1,   221,  1183,    -1,    25,    -1,   960,    -1,
     955,    -1,    -1,   480,    -1,   146,  1183,  1184,   432,   880,
    1066,   393,    -1,   194,  1183,    -1,    68,  1183,    -1,  1219,
    1227,    -1,   448,    62,    -1,   448,  1190,    -1,  1191,    -1,
    1190,  1191,    -1,    -1,   134,  1192,  1509,    -1,    -1,   200,
    1193,  1509,    -1,    -1,   229,  1194,  1509,    -1,    -1,   217,
    1195,  1509,    -1,    -1,   254,  1196,  1509,    -1,    -1,   202,
    1108,  1197,  1509,    -1,    -1,   225,  1108,  1198,  1509,    -1,
    1209,    -1,  1211,    -1,  1210,    -1,  1200,    -1,  1236,    -1,
    1203,    -1,    -1,   562,   862,  1201,   483,    -1,    -1,   483,
      -1,    -1,   571,    26,  1204,  1202,    -1,   159,    -1,   630,
    1223,    -1,   162,  1223,    -1,   161,  1223,    -1,    -1,  1206,
      -1,  1207,    -1,  1206,  1207,    -1,  1216,  1208,    -1,    -1,
     619,  1223,    -1,   520,  1205,  1215,    -1,   519,  1444,  1215,
      -1,   518,  1214,  1213,  1212,  1215,    -1,    -1,   153,   855,
      -1,   153,   855,     5,   855,    -1,   614,    -1,   615,    -1,
     616,    -1,   617,    -1,  1108,    -1,    -1,   523,    -1,  1217,
      -1,  1216,     5,  1217,    -1,   862,  1250,    -1,   610,   432,
     855,   393,  1235,    -1,    65,  1235,    -1,   497,   432,    20,
     393,  1235,    -1,   414,   432,    20,   393,  1235,    -1,   389,
     432,   855,   393,  1235,    -1,   590,   432,   855,   393,  1235,
      -1,   603,   432,   855,   393,  1235,    -1,   602,   432,   855,
     393,  1235,    -1,    -1,   462,  1220,    -1,  1221,    -1,  1220,
    1221,    -1,   228,    26,    -1,   219,    26,    -1,   302,    26,
      -1,   185,    26,    -1,   257,    26,    -1,   176,    -1,   344,
      25,    -1,   344,  1108,    -1,   177,    25,    -1,   160,    25,
      -1,  1226,    -1,  1222,  1226,    -1,  1224,   109,    -1,  1224,
     111,    -1,  1224,   110,    -1,  1224,    -1,   961,    -1,    26,
      -1,    -1,   462,  1222,    -1,   228,  1223,    -1,   219,  1223,
      -1,   302,  1223,    -1,   185,  1223,    -1,   257,  1223,    -1,
     258,  1223,    -1,   629,    25,    -1,   630,  1223,    -1,   634,
      -1,   631,    -1,   632,    -1,   633,    -1,   638,    -1,   635,
      -1,   636,    -1,   637,    -1,    77,  1223,    -1,    78,  1223,
      -1,    79,  1223,    -1,   344,    25,    -1,   177,    25,    -1,
     401,    -1,    74,    -1,    75,    -1,    -1,   515,   620,  1135,
      -1,   135,  1135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     466,  1229,   955,   432,  1230,  1125,   393,  1231,   765,  1232,
    1188,  1233,  1189,  1234,   240,    -1,    -1,   527,   855,    -1,
     517,  1237,    -1,    -1,  1163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,  1239,   955,   432,  1240,  1125,   393,  1241,
     765,  1242,  1245,  1243,  1189,  1244,   240,    -1,  1225,  1227,
      -1,    -1,    -1,    -1,   155,   432,    25,     5,  1247,   718,
    1248,   393,  1249,   716,    -1,    -1,   385,    -1,   385,   219,
      26,    -1,   385,   219,  1108,    -1,   608,   862,    -1,   608,
     862,   345,  1108,    -1,   608,   862,   163,    -1,   608,   862,
     579,    -1,   608,   862,   546,    -1,  1253,    -1,   173,    -1,
     324,    -1,   282,    -1,  1260,    -1,  1255,    -1,    -1,    -1,
     207,  1256,  1393,   432,  1257,  1264,   393,    -1,    -1,    -1,
     132,  1258,  1393,   432,  1259,  1264,   393,  1261,    -1,   104,
    1262,   393,    -1,    55,   956,    -1,    -1,   269,    -1,  1263,
      -1,  1262,     5,  1263,    -1,   955,   589,    -1,   955,   540,
      -1,   955,    -1,  1265,    -1,  1264,     5,  1265,    -1,  1346,
      -1,  1344,    -1,   121,   955,    -1,   180,    -1,    46,   955,
    1268,    -1,  1269,    -1,  1268,     5,  1269,    -1,  1270,    -1,
    1273,    -1,  1276,    -1,  1281,    -1,  1282,    -1,  1280,    -1,
    1279,    -1,   586,  1271,    -1,   586,   432,  1272,   393,    -1,
    1265,    -1,  1265,   665,   955,    -1,  1271,    -1,  1272,     5,
    1271,    -1,   543,  1275,    -1,   543,   432,  1274,   393,    -1,
    1275,    -1,  1274,     5,  1275,    -1,   955,    -1,   456,  1278,
      -1,   456,   432,  1277,   393,    -1,  1278,    -1,  1277,     5,
    1278,    -1,  1265,    -1,    86,    -1,    87,    -1,    85,    26,
      -1,    57,  1350,    -1,    57,   432,  1283,   393,    -1,    58,
    1284,    -1,    58,   432,  1283,   393,    -1,  1350,    -1,  1283,
       5,  1350,    -1,   955,    -1,   266,    -1,   232,    -1,   165,
    1287,    -1,   142,    -1,   130,    -1,   120,    -1,   118,    -1,
     122,    -1,   179,  1450,    -1,   231,  1286,   461,  1444,   627,
    1444,    -1,   299,   948,   461,  1444,   627,  1444,    -1,    -1,
    1450,    -1,    -1,   862,    -1,   524,   862,    -1,   230,    -1,
      -1,   249,  1291,  1393,  1294,  1292,    -1,    -1,   480,  1293,
     432,  1296,   393,    -1,  1430,    -1,    -1,   432,  1295,   393,
      -1,  1396,    -1,  1295,     5,  1396,    -1,  1297,    -1,  1296,
       5,  1297,    -1,  1436,    -1,   484,    -1,    -1,    -1,   501,
    1299,  1302,  1300,  1303,    -1,   956,    -1,  1307,   949,    -1,
     949,    -1,    -1,    -1,   555,  1304,  1130,    -1,    -1,    -1,
     555,  1306,  1130,    -1,   502,    -1,   556,    -1,   563,    -1,
     376,    -1,   342,    -1,   397,    -1,   379,   862,    -1,   351,
     862,    -1,   238,  1393,   150,   949,    -1,   238,  1393,  1366,
      -1,   515,   620,  1311,    -1,  1312,    -1,  1311,     5,  1312,
      -1,  1313,  1314,    -1,    26,    -1,  1396,    -1,    -1,   589,
      -1,   540,    -1,   277,    -1,   310,    -1,    -1,   327,    -1,
     357,  1319,  1317,    -1,  1484,    -1,    25,    -1,    -1,  1449,
    1321,  1322,    -1,  1351,    -1,  1355,    -1,  1316,    -1,  1451,
      -1,  1315,    -1,  1308,    -1,  1309,    -1,  1298,    -1,  1290,
      -1,  1289,    -1,  1420,    -1,  1468,    -1,   506,  1325,   626,
    1393,   627,  1330,  1324,    -1,    -1,   141,    -1,   168,    -1,
    1326,    -1,  1327,    -1,  1326,     5,  1327,    -1,   472,    -1,
     451,    -1,   440,    -1,   479,  1328,    -1,    -1,   432,  1329,
     393,    -1,  1396,    -1,  1329,     5,  1396,    -1,  1331,    -1,
    1330,     5,  1331,    -1,   464,    -1,  1394,    -1,   236,  1393,
    1333,   618,  1430,  1335,    -1,    -1,   432,  1334,   393,    -1,
    1396,    -1,  1334,     5,  1396,    -1,    -1,   140,    -1,   493,
     432,  1369,   393,    -1,   246,   432,  1339,   393,  1338,    -1,
     297,  1340,    -1,  1341,    -1,  1393,    -1,  1393,   432,  1341,
     393,    -1,  1396,    -1,  1341,     5,  1396,    -1,   477,   432,
    1343,   393,    -1,   259,   432,  1343,   393,    -1,  1396,    -1,
    1343,     5,  1396,    -1,  1342,    -1,  1337,    -1,  1336,    -1,
     401,  1399,    -1,   208,    -1,   955,  1385,  1347,  1348,    -1,
      -1,  1345,    -1,    -1,  1349,    -1,  1350,    -1,  1349,  1350,
      -1,   374,    -1,   158,    -1,   477,    -1,  1338,    -1,   493,
     432,  1369,   393,    -1,   119,  1352,  1354,    -1,  1353,    -1,
    1394,    -1,  1355,    -1,  1354,  1355,    -1,  1332,    -1,  1323,
      -1,   449,  1369,    -1,   369,  1358,    -1,  1435,    -1,  1358,
       5,  1435,    -1,   527,  1369,    -1,   548,  1361,    -1,  1362,
      -1,  1361,     5,  1362,    -1,  1363,    -1,   516,  1363,    -1,
     516,   432,  1364,   393,    -1,  1393,    -1,  1393,  1398,    -1,
    1362,    -1,  1364,     5,  1362,    -1,  1360,  1366,  1367,  1368,
      -1,    -1,  1359,    -1,    -1,  1357,    -1,    -1,  1356,    -1,
    1370,    -1,  1369,     6,  1370,    -1,  1371,    -1,  1370,     7,
    1371,    -1,  1372,    -1,     9,  1372,    -1,  1383,    -1,   432,
    1369,   393,    -1,   444,  1431,    -1,   295,  1431,    -1,    -1,
     443,  1376,    -1,  1437,    -1,  1440,    -1,  1436,   624,   432,
    1378,   393,    -1,  1436,   624,  1431,    -1,  1436,   430,   432,
    1378,   393,    -1,  1436,   430,  1431,    -1,  1379,    -1,  1378,
       5,  1379,    -1,  1488,    -1,  1399,    -1,    -1,     9,    -1,
    1436,  1380,   388,    -1,  1436,  1380,   250,    -1,  1436,  1382,
    1436,    -1,  1436,  1380,   390,  1436,     7,  1436,    -1,  1436,
     558,  1375,  1374,    -1,  1436,   372,  1375,  1374,    -1,  1436,
     679,  1375,  1374,    -1,  1436,   373,  1375,  1374,    -1,  1436,
    1380,    10,  1375,  1374,    -1,    14,    -1,    17,    -1,    12,
      -1,    13,    -1,   253,    -1,    10,    -1,   678,    -1,    16,
      -1,    15,    -1,  1381,    -1,  1377,    -1,  1373,    -1,    -1,
     587,    -1,   360,    -1,   477,    -1,  1386,    -1,  1387,    -1,
    1389,    -1,   537,    -1,   537,   432,  1390,   393,    -1,   412,
     432,  1391,  1388,   393,    -1,   473,    -1,   399,   432,  1391,
    1388,   393,    -1,   513,   432,  1391,  1388,   393,    -1,   539,
      -1,   409,    -1,   381,    -1,   358,  1406,   627,  1407,    -1,
     358,    -1,   370,  1406,   627,  1407,    -1,   370,    -1,   370,
    1406,   432,    26,   393,   627,  1407,    -1,   576,    -1,   534,
      -1,   425,    -1,   425,   432,    26,   393,    -1,   425,   432,
      26,     5,    26,   393,    -1,    -1,     5,  1392,    -1,   503,
     432,  1391,   393,    -1,   567,    -1,   300,    -1,   503,    -1,
      64,    -1,    26,    -1,    26,    -1,    26,    -1,    25,   621,
     955,    -1,    25,    -1,   955,    -1,   955,   591,   955,    -1,
     955,    -1,    -1,   460,    26,   428,    -1,   460,    26,     5,
      26,   428,    -1,  1397,    -1,   613,  1397,    -1,   955,  1395,
      -1,  1393,   621,   955,  1395,    -1,  1393,   621,    20,    -1,
     955,    -1,    25,    -1,   412,    -1,   961,    -1,    26,    -1,
    1401,    -1,   397,  1403,    -1,   397,  1402,    -1,    -1,  1406,
     627,  1407,    -1,    -1,  1404,   627,  1404,    -1,   583,    -1,
     514,    -1,   592,    -1,   554,    -1,   455,    -1,   471,    -1,
     367,    -1,   367,   432,    26,   393,    -1,   583,    -1,   514,
      -1,   592,    -1,   554,    -1,   455,    -1,   471,    -1,   367,
      -1,   367,   432,    26,   393,    -1,   583,    -1,   514,    -1,
     592,    -1,   554,    -1,   455,    -1,   471,    -1,   367,    -1,
     583,    -1,   514,    -1,   592,    -1,   554,    -1,   455,    -1,
     471,    -1,   367,    -1,   955,    -1,    25,    -1,  1449,   504,
     949,    -1,    -1,  1449,   400,  1301,   438,   597,  1418,  1411,
    1415,    -1,    -1,  1449,   400,  1301,   438,   101,   597,  1419,
    1412,  1415,    -1,    -1,  1449,   400,  1301,   136,  1419,  1413,
    1415,    -1,    -1,  1449,   400,  1301,   137,   101,   597,  1419,
    1414,  1415,    -1,    -1,   289,    -1,   288,  1416,    -1,  1417,
      -1,  1416,     5,  1417,    -1,   955,    -1,   955,   621,   955,
      -1,    25,   621,   955,   621,   955,    -1,  1419,    -1,  1290,
      -1,  1165,    -1,  1421,    -1,  1421,  1415,    -1,    -1,    -1,
     472,  1432,  1422,  1433,  1423,  1429,  1365,  1427,    -1,   472,
    1432,  1433,  1365,  1427,    -1,  1426,    -1,  1444,    -1,   472,
    1432,  1433,  1429,  1365,  1427,    -1,    -1,   526,  1384,  1425,
      -1,  1310,    -1,   332,  1428,  1261,    -1,  1310,   332,  1428,
    1261,    -1,   955,    -1,    -1,   555,  1130,    -1,   472,  1432,
    1433,  1365,    -1,   432,   472,  1432,  1433,  1365,   393,    -1,
      -1,   587,    -1,   360,    -1,   477,    -1,  1434,    -1,  1433,
       5,  1434,    -1,  1436,    -1,  1436,   955,    -1,  1436,    -1,
    1437,    -1,    19,  1437,    -1,    18,  1437,    -1,  1438,    -1,
    1488,    -1,  1431,    -1,   613,   955,    -1,   613,   955,   621,
     955,    -1,  1437,    21,  1436,    -1,  1437,  1458,    -1,  1437,
      20,  1436,    -1,  1437,    18,  1436,    -1,  1437,    19,  1436,
      -1,  1399,    -1,   485,    -1,   429,    -1,   578,    -1,    20,
      -1,    65,    -1,   590,   432,  1384,  1436,   393,    -1,   602,
     432,  1384,  1436,   393,    -1,   603,   432,  1384,  1436,   393,
      -1,   610,   432,  1384,  1436,   393,    -1,   497,   432,  1384,
    1436,   393,    -1,   955,   432,  1439,   393,    -1,   539,   432,
    1439,   393,    -1,   432,  1436,   393,    -1,   445,   432,  1459,
     393,    -1,  1436,    -1,  1439,     5,  1436,    -1,  1399,    -1,
    1449,   347,  1448,  1443,  1425,    -1,  1449,   336,  1448,  1443,
     249,  1393,  1445,    -1,  1449,   336,  1448,  1443,  1108,    -1,
      -1,   322,  1444,    -1,    25,    -1,  1108,    -1,    -1,   432,
    1446,   393,    -1,  1447,    -1,  1446,     5,  1447,    -1,   955,
      -1,    25,    -1,  1108,    -1,    -1,   268,  1450,   597,    -1,
     956,    -1,  1456,    -1,  1455,    -1,  1452,    -1,   317,  1453,
     627,  1453,    -1,   298,  1453,   621,  1454,   627,  1454,    -1,
     955,    -1,   955,    -1,   222,   802,    -1,   293,   802,  1457,
      -1,   272,    -1,   175,    -1,    93,    -1,    94,    -1,    95,
      -1,    96,    -1,    97,    -1,    98,    -1,   397,     5,  1406,
     627,  1407,    -1,  1488,     5,  1406,   627,  1407,    -1,   397,
    1406,   627,  1407,    -1,    -1,   609,  1461,  1462,   190,    -1,
    1463,    -1,  1462,  1463,    -1,    33,    -1,  1464,    -1,  1466,
      -1,   351,    -1,   305,    -1,   224,    -1,   586,    -1,   482,
      -1,   587,    -1,   487,    -1,   531,    -1,   588,    -1,   115,
      -1,   488,    -1,   618,    -1,   589,    -1,   318,    -1,   489,
      -1,   319,    -1,   619,    -1,   613,    -1,   275,    -1,   490,
      -1,   184,    -1,   389,    -1,   590,    -1,   665,    -1,   390,
      -1,   491,    -1,   492,    -1,   532,    -1,   533,    -1,   433,
      -1,   434,    -1,   353,    -1,   652,    -1,   620,    -1,   534,
      -1,   391,    -1,   536,    -1,   530,    -1,   537,    -1,   320,
      -1,   493,    -1,   494,    -1,   392,    -1,   495,    -1,   393,
      -1,   428,    -1,   496,    -1,   591,    -1,   435,    -1,   394,
      -1,     5,    -1,    23,    -1,   395,    -1,   436,    -1,   396,
      -1,   355,    -1,   354,    -1,   321,    -1,   356,    -1,   497,
      -1,   437,    -1,   397,    -1,   438,    -1,   538,    -1,   357,
      -1,   539,    -1,   358,    -1,   592,    -1,   593,    -1,   398,
      -1,   594,    -1,   399,    -1,   400,    -1,   401,    -1,   359,
      -1,   498,    -1,   439,    -1,   440,    -1,   322,    -1,   540,
      -1,   281,    -1,   595,    -1,   656,    -1,   402,    -1,   360,
      -1,    21,    -1,   621,    -1,   441,    -1,   323,    -1,   543,
      -1,    63,    -1,   544,    -1,   659,    -1,   403,    -1,    14,
      -1,   499,    -1,   443,    -1,   500,    -1,   327,    -1,   545,
      -1,   404,    -1,   444,    -1,   546,    -1,   445,    -1,   446,
      -1,   366,    -1,   535,    -1,   501,    -1,   100,    -1,   193,
      -1,   447,    -1,   502,    -1,   596,    -1,   503,    -1,   504,
      -1,   597,    -1,   405,    -1,   406,    -1,   448,    -1,   639,
      -1,    92,    -1,   105,    -1,   505,    -1,   367,    -1,   547,
      -1,   548,    -1,   368,    -1,   290,    -1,   407,    -1,   622,
      -1,   549,    -1,   506,    -1,    13,    -1,   507,    -1,   508,
      -1,   449,    -1,   450,    -1,   552,    -1,   553,    -1,   554,
      -1,   661,    -1,    72,    -1,   623,    -1,   624,    -1,   111,
      -1,   509,    -1,   408,    -1,   291,    -1,   666,    -1,   451,
      -1,   409,    -1,   331,    -1,   370,    -1,   668,    -1,   333,
      -1,   598,    -1,   541,    -1,   660,    -1,   510,    -1,   483,
      -1,   371,    -1,   599,    -1,   628,    -1,   410,    -1,     7,
      -1,   429,    -1,   584,    -1,   484,    -1,     6,    -1,   485,
      -1,     8,    -1,   556,    -1,   557,    -1,    12,    -1,   600,
      -1,   558,    -1,   512,    -1,   452,    -1,   601,    -1,   411,
      -1,   559,    -1,   453,    -1,    10,    -1,    45,    -1,   454,
      -1,   560,    -1,   647,    -1,   662,    -1,    19,    -1,   455,
      -1,   110,    -1,    22,    -1,   561,    -1,   456,    -1,   513,
      -1,   514,    -1,    20,    -1,   562,    -1,   563,    -1,   311,
      -1,   564,    -1,   457,    -1,     9,    -1,   412,    -1,   625,
      -1,   670,    -1,   626,    -1,   565,    -1,   432,    -1,   460,
      -1,   461,    -1,   413,    -1,   515,    -1,   340,    -1,   516,
      -1,   462,    -1,   604,    -1,   375,    -1,   517,    -1,   155,
      -1,   106,    -1,   414,    -1,    18,    -1,   109,    -1,   341,
      -1,   415,    -1,   112,    -1,   376,    -1,   312,    -1,   520,
      -1,   342,    -1,   343,    -1,   416,    -1,   463,    -1,   464,
      -1,   605,    -1,   566,    -1,   377,    -1,   567,    -1,   465,
      -1,   417,    -1,   606,    -1,   297,    -1,   378,    -1,   379,
      -1,   466,    -1,   380,    -1,   178,    -1,   345,    -1,   418,
      -1,   467,    -1,   521,    -1,   262,    -1,   607,    -1,   568,
      -1,   608,    -1,   468,    -1,   470,    -1,   471,    -1,   419,
      -1,   472,    -1,   523,    -1,   473,    -1,   420,    -1,   475,
      -1,   569,    -1,   486,    -1,   570,    -1,   571,    -1,   524,
      -1,   300,    -1,   381,    -1,   572,    -1,   476,    -1,   609,
      -1,   301,    -1,    90,    -1,   573,    -1,   574,    -1,   610,
      -1,   421,    -1,   542,    -1,   575,    -1,   116,    -1,   576,
      -1,   577,    -1,   422,    -1,   669,    -1,   627,    -1,   611,
      -1,   423,    -1,   525,    -1,   199,    -1,   346,    -1,   526,
      -1,   477,    -1,   478,    -1,   479,    -1,   424,    -1,   612,
      -1,   578,    -1,   382,    -1,   480,    -1,   425,    -1,   350,
      -1,   579,    -1,   426,    -1,   580,    -1,   383,    -1,   527,
      -1,   528,    -1,   529,    -1,   581,    -1,   385,    -1,   582,
      -1,   602,    -1,   603,    -1,   585,    -1,   583,    -1,   481,
      -1,    -1,   191,  1465,  1488,    -1,    -1,   555,  1467,  1130,
      -1,    -1,    -1,   479,  1393,  1469,  1472,  1470,  1471,    -1,
      -1,   150,   949,    -1,   527,  1369,    -1,    53,  1476,   393,
      14,   432,  1477,   393,    -1,    49,  1477,   393,    -1,    50,
    1477,   393,    -1,   585,  1473,    -1,    52,  1477,    -1,    51,
    1477,    -1,  1475,    -1,  1473,     5,  1475,    -1,  1396,    -1,
    1474,    14,  1478,    -1,  1474,    -1,  1476,     5,  1474,    -1,
    1478,    -1,  1477,     5,  1478,    -1,   484,    -1,  1479,    -1,
    1480,    -1,    19,  1480,    -1,    18,  1480,    -1,  1482,    -1,
    1431,    -1,   613,   955,    -1,   613,   955,   621,   955,    -1,
    1481,    -1,  1399,    -1,   485,    -1,   429,    -1,   578,    -1,
      65,    -1,  1480,    21,  1479,    -1,  1480,  1458,    -1,  1480,
      20,  1479,    -1,  1480,    18,  1479,    -1,  1480,    19,  1479,
      -1,   590,   432,  1384,  1479,   393,    -1,   602,   432,  1384,
    1479,   393,    -1,   603,   432,  1384,  1479,   393,    -1,   610,
     432,  1384,  1479,   393,    -1,   497,   432,  1384,  1479,   393,
      -1,   955,   432,  1483,   393,    -1,   539,   432,  1483,   393,
      -1,   432,  1479,   393,    -1,   445,   432,  1459,   393,    -1,
    1488,    -1,  1479,    -1,  1483,     5,  1479,    -1,  1485,    -1,
     191,  1486,    -1,  1486,    -1,  1117,    -1,   955,    -1,  1486,
     621,  1487,    -1,    25,   621,  1486,   621,  1487,    -1,    20,
      -1,  1138,    -1,   955,    -1,  1485,    -1,  1485,   422,  1485,
      -1,   127,  1490,    -1,   131,  1490,    -1,   126,  1490,    -1,
      47,    -1,   166,  1490,    -1,   124,  1490,    -1,    48,    -1,
     149,  1490,    -1,   148,  1490,    -1,   123,  1490,    -1,   356,
      -1,   622,   627,  1491,    -1,   549,  1491,    -1,   574,    -1,
     535,  1492,    -1,   955,    -1,   591,   955,    -1,   955,    -1,
      -1,    -1,   528,  1494,   862,  1495,  1509,   326,    -1,    -1,
     660,  1499,    -1,    -1,   663,    -1,   182,    -1,   278,   950,
      -1,    70,   950,    -1,   308,    -1,   307,    -1,   309,   952,
    1496,  1497,    -1,   494,  1499,  1497,    -1,   947,    -1,  1499,
       5,   947,    -1,   103,    -1,   133,   950,    -1,   862,   568,
       5,   862,   394,    -1,   510,   862,    -1,   265,   950,    -1,
     102,  1504,     8,  1505,  1503,    -1,    -1,   548,   862,    -1,
     955,    -1,   955,    -1,   248,   950,    -1,   251,   950,   627,
     862,     5,   862,    -1,   251,   950,   620,   862,     5,   862,
      -1,    27,    -1,    -1,  1511,    -1,  1512,  1215,    -1,  1510,
      -1,  1511,  1510,    -1,    -1,  1513,  1514,    -1,   681,    -1,
     682,    -1,   683,    -1,   684,    -1,   701,    -1,   723,    -1,
     737,    -1,   738,    -1,   744,    -1,   745,    -1,   764,    -1,
     834,    -1,   835,    -1,   836,    -1,   837,    -1,   848,    -1,
     849,    -1,   850,    -1,   851,    -1,   852,    -1,   853,    -1,
     854,    -1,   906,    -1,   910,    -1,   941,    -1,   962,    -1,
     963,    -1,   966,    -1,   967,    -1,   968,    -1,   969,    -1,
     982,    -1,   991,    -1,  1012,    -1,  1013,    -1,  1015,    -1,
    1019,    -1,  1034,    -1,  1035,    -1,  1039,    -1,  1040,    -1,
    1041,    -1,  1042,    -1,  1050,    -1,  1065,    -1,  1078,    -1,
    1089,    -1,  1090,    -1,  1091,    -1,  1102,    -1,  1141,    -1,
    1144,    -1,  1146,    -1,  1152,    -1,  1153,    -1,  1156,    -1,
    1159,    -1,  1162,    -1,  1164,    -1,  1166,    -1,  1169,    -1,
    1176,    -1,  1181,    -1,  1185,    -1,  1186,    -1,  1187,    -1,
    1199,    -1,  1251,    -1,  1252,    -1,  1254,    -1,  1266,    -1,
    1267,    -1,  1285,    -1,  1288,    -1,  1318,    -1,  1320,    -1,
    1409,    -1,  1410,    -1,  1441,    -1,  1442,    -1,  1460,    -1,
    1489,    -1,  1493,    -1,  1498,    -1,  1500,    -1,  1502,    -1,
    1506,    -1,  1507,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   943,   943,   946,   949,   955,   961,   968,   972,   972,
     978,  1001,  1002,  1003,  1004,  1005,  1019,  1020,  1021,  1022,
    1023,  1028,  1029,  1040,  1043,  1046,  1046,  1050,  1053,  1054,
    1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1079,  1080,  1083,
    1083,  1098,  1099,  1102,  1108,  1110,  1121,  1123,  1125,  1127,
    1131,  1133,  1195,  1199,  1203,  1203,  1213,  1217,  1220,  1221,
    1228,  1234,  1228,  1247,  1252,  1256,  1247,  1268,  1272,  1268,
    1280,  1285,  1280,  1304,  1311,  1315,  1303,  1341,  1341,  1345,
    1346,  1347,  1352,  1355,  1360,  1364,  1372,  1375,  1375,  1381,
    1385,  1400,  1398,  1416,  1416,  1431,  1431,  1434,  1434,  1438,
    1441,  1441,  1441,  1448,  1449,  1448,  1456,  1456,  1467,  1467,
    1486,  1489,  1492,  1495,  1498,  1501,  1514,  1519,  1519,  1520,
    1520,  1523,  1528,  1528,  1532,  1542,  1556,  1560,  1555,  1570,
    1576,  1584,  1585,  1588,  1588,  1591,  1595,  1600,  1607,  1607,
    1611,  1611,  1618,  1618,  1623,  1623,  1628,  1628,  1633,  1633,
    1646,  1647,  1655,  1656,  1673,  1676,  1679,  1682,  1685,  1688,
    1694,  1705,  1710,  1723,  1727,  1742,  1743,  1747,  1747,  1751,
    1751,  1751,  1752,  1753,  1758,  1758,  1761,  1761,  1770,  1771,
    1772,  1775,  1779,  1780,  1780,  1797,  1797,  1797,  1797,  1801,
    1808,  1809,  1812,  1812,  1816,  1817,  1818,  1819,  1824,  1824,
    1830,  1830,  1839,  1836,  1852,  1852,  1854,  1854,  1856,  1858,
    1860,  1862,  1865,  1869,  1869,  1870,  1870,  1874,  1874,  1886,
    1886,  1891,  1895,  1897,  1898,  1901,  1901,  1901,  1905,  1906,
    1907,  1908,  1915,  1916,  1917,  1918,  1921,  1922,  1923,  1924,
    1928,  1933,  1938,  1942,  1945,  1949,  1950,  1951,  1952,  1953,
    1954,  1955,  1956,  1959,  1960,  1961,  1993,  1997,  1999,  2001,
    2001,  2008,  2012,  2012,  2016,  2017,  2018,  2019,  2020,  2021,
    2022,  2028,  2028,  2031,  2033,  2039,  2041,  2047,  2055,  2055,
    2058,  2059,  2060,  2061,  2062,  2063,  2064,  2070,  2073,  2073,
    2086,  2086,  2093,  2094,  2095,  2097,  2098,  2100,  2102,  2103,
    2104,  2105,  2110,  2116,  2122,  2123,  2125,  2127,  2128,  2129,
    2130,  2131,  2132,  2135,  2136,  2143,  2151,  2151,  2159,  2156,
    2171,  2171,  2173,  2173,  2181,  2181,  2184,  2187,  2188,  2193,
    2205,  2209,  2212,  2215,  2216,  2217,  2218,  2219,  2224,  2231,
    2237,  2242,  2246,  2242,  2257,  2259,  2264,  2269,  2269,  2273,
    2273,  2276,  2276,  2282,  2282,  2288,  2288,  2298,  2317,  2323,
    2347,  2350,  2364,  2366,  2368,  2370,  2372,  2374,  2376,  2382,
    2384,  2388,  2390,  2392,  2394,  2396,  2398,  2400,  2406,  2421,
    2424,  2437,  2438,  2439,  2440,  2441,  2445,  2446,  2447,  2451,
    2456,  2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,
    2472,  2473,  2480,  2480,  2485,  2485,  2488,  2494,  2502,  2508,
    2518,  2519,  2527,  2534,  2538,  2548,  2552,  2557,  2562,  2564,
    2574,  2587,  2595,  2608,  2613,  2619,  2624,  2629,  2630,  2636,
    2707,  2713,  2718,  2726,  2726,  2741,  2745,  2752,  2755,  2763,
    2774,  2784,  2790,  2799,  2804,  2812,  2815,  2818,  2823,  2830,
    2835,  2840,  2845,  2855,  2863,  2871,  2876,  2880,  2885,  2889,
    2893,  2900,  2903,  2906,  2910,  2914,  2918,  2922,  2930,  2940,
    2945,  2938,  2961,  2966,  2961,  2983,  2983,  2983,  2986,  2986,
    2986,  2990,  2990,  2990,  2994,  2994,  2994,  2998,  3004,  3010,
    3016,  3026,  3026,  3030,  3034,  3035,  3046,  3047,  3053,  3063,
    3073,  3083,  3084,  3087,  3092,  3098,  3102,  3106,  3109,  3115,
    3118,  3121,  3138,  3141,  3147,  3148,  3149,  3153,  3154,  3155,
    3156,  3157,  3159,  3160,  3161,  3163,  3164,  3168,  3169,  3174,
    3175,  3187,  3191,  3186,  3199,  3202,  3216,  3220,  3226,  3215,
    3239,  3240,  3252,  3258,  3252,  3272,  3272,  3274,  3275,  3279,
    3279,  3283,  3283,  3288,  3288,  3295,  3296,  3300,  3300,  3304,
    3304,  3309,  3309,  3316,  3320,  3321,  3322,  3327,  3327,  3330,
    3330,  3334,  3334,  3338,  3338,  3342,  3342,  3347,  3347,  3352,
    3352,  3357,  3357,  3362,  3362,  3378,  3395,  3396,  3397,  3398,
    3399,  3400,  3401,  3404,  3404,  3407,  3409,  3412,  3415,  3417,
    3418,  3419,  3421,  3423,  3425,  3427,  3431,  3438,  3440,  3446,
    3451,  3456,  3461,  3461,  3464,  3470,  3475,  3478,  3485,  3485,
    3487,  3488,  3490,  3492,  3494,  3496,  3500,  3509,  3509,  3571,
    3583,  3590,  3590,  3594,  3599,  3605,  3609,  3613,  3619,  3623,
    3627,  3633,  3633,  3641,  3642,  3646,  3646,  3650,  3651,  3654,
    3657,  3657,  3660,  3662,  3662,  3665,  3667,  3667,  3668,  3670,
    3670,  3679,  3686,  3677,  3708,  3708,  3708,  3711,  3713,  3711,
    3720,  3723,  3729,  3740,  3740,  3744,  3750,  3750,  3754,  3755,
    3766,  3767,  3769,  3771,  3776,  3776,  3780,  3779,  3786,  3785,
    3791,  3791,  3796,  3796,  3802,  3802,  3807,  3807,  3812,  3812,
    3817,  3817,  3820,  3820,  3823,  3823,  3826,  3826,  3868,  3869,
    3877,  3878,  3887,  3892,  3897,  3898,  3899,  3903,  3902,  3913,
    3918,  3923,  3923,  3939,  3945,  3946,  3947,  3948,  3951,  3951,
    3954,  3961,  3962,  3963,  3964,  3965,  3966,  3967,  3968,  3969,
    3974,  3974,  3976,  3979,  3979,  3981,  3985,  3988,  3989,  3992,
    3992,  3997,  4000,  4001,  4002,  4003,  4004,  4005,  4006,  4007,
    4008,  4009,  4010,  4011,  4012,  4013,  4014,  4015,  4016,  4017,
    4021,  4039,  4039,  4039,  4066,  4077,  4084,  4090,  4096,  4102,
    4113,  4136,  4135,  4152,  4152,  4156,  4157,  4165,  4166,  4167,
    4168,  4175,  4176,  4178,  4179,  4183,  4188,  4189,  4190,  4191,
    4192,  4193,  4194,  4195,  4196,  4197,  4198,  4201,  4201,  4203,
    4203,  4203,  4205,  4209,  4209,  4218,  4223,  4239,  4245,  4217,
    4259,  4273,  4283,  4272,  4296,  4303,  4303,  4308,  4314,  4322,
    4327,  4328,  4331,  4331,  4331,  4334,  4334,  4342,  4348,  4362,
    4366,  4379,  4361,  4397,  4397,  4411,  4422,  4421,  4433,  4429,
    4446,  4443,  4456,  4456,  4458,  4459,  4461,  4462,  4465,  4466,
    4467,  4469,  4474,  4479,  4485,  4487,  4488,  4491,  4492,  4495,
    4497,  4506,  4512,  4506,  4523,  4524,  4528,  4528,  4538,  4538,
    4550,  4553,  4556,  4559,  4563,  4567,  4568,  4569,  4570,  4571,
    4575,  4580,  4580,  4583,  4609,  4668,  4668,  4671,  4675,  4679,
    4722,  4764,  4765,  4766,  4769,  4783,  4795,  4795,  4800,  4801,
    4807,  4867,  4924,  4929,  4936,  4941,  4949,  4955,  4989,  4992,
    4993,  5034,  5077,  5078,  5082,  5083,  5087,  5140,  5144,  5147,
    5153,  5164,  5171,  5179,  5179,  5182,  5183,  5184,  5185,  5186,
    5189,  5192,  5198,  5201,  5205,  5209,  5216,  5221,  5228,  5231,
    5237,  5239,  5239,  5239,  5243,  5263,  5270,  5277,  5280,  5294,
    5301,  5302,  5305,  5306,  5310,  5316,  5321,  5327,  5328,  5333,
    5337,  5337,  5341,  5342,  5345,  5346,  5350,  5358,  5361,  5367,
    5368,  5370,  5372,  5376,  5376,  5377,  5382,  5390,  5391,  5396,
    5397,  5399,  5412,  5414,  5415,  5417,  5420,  5423,  5426,  5430,
    5433,  5436,  5440,  5444,  5448,  5451,  5455,  5458,  5459,  5460,
    5463,  5466,  5469,  5472,  5475,  5478,  5481,  5497,  5505,  5505,
    5507,  5514,  5518,  5523,  5538,  5536,  5555,  5556,  5560,  5565,
    5566,  5570,  5571,  5573,  5574,  5576,  5576,  5584,  5593,  5593,
    5603,  5604,  5607,  5608,  5611,  5615,  5629,  5634,  5639,  5644,
    5654,  5654,  5658,  5661,  5661,  5663,  5673,  5682,  5689,  5691,
    5695,  5698,  5698,  5702,  5701,  5709,  5708,  5719,  5718,  5725,
    5724,  5728,  5727,  5730,  5730,  5746,  5745,  5767,  5768,  5769,
    5770,  5771,  5772,  5775,  5775,  5781,  5781,  5784,  5784,  5800,
    5801,  5802,  5811,  5823,  5824,  5827,  5828,  5831,  5834,  5834,
    5839,  5859,  5864,  5870,  5871,  5872,  5876,  5877,  5878,  5879,
    5883,  5893,  5895,  5900,  5903,  5908,  5914,  5921,  5928,  5937,
    5944,  5951,  5958,  5965,  5974,  5974,  5976,  5976,  5979,  5980,
    5981,  5982,  5983,  5984,  5985,  5986,  5987,  5988,  5991,  5991,
    5994,  5995,  5996,  5997,  6000,  6000,  6003,  6003,  6006,  6007,
    6008,  6009,  6010,  6011,  6012,  6013,  6015,  6016,  6017,  6018,
    6020,  6021,  6022,  6023,  6025,  6026,  6027,  6028,  6029,  6030,
    6031,  6032,  6036,  6043,  6052,  6064,  6073,  6084,  6088,  6092,
    6098,  6063,  6111,  6114,  6122,  6134,  6136,  6141,  6149,  6159,
    6162,  6166,  6174,  6140,  6183,  6187,  6191,  6195,  6187,  6205,
    6206,  6207,  6208,  6213,  6215,  6218,  6222,  6225,  6232,  6237,
    6238,  6239,  6244,  6245,  6251,  6251,  6251,  6256,  6256,  6256,
    6267,  6268,  6274,  6275,  6287,  6288,  6293,  6294,  6295,  6299,
    6302,  6308,  6311,  6319,  6320,  6326,  6333,  6336,  6345,  6348,
    6351,  6354,  6357,  6360,  6363,  6370,  6373,  6380,  6383,  6389,
    6392,  6399,  6402,  6409,  6410,  6415,  6419,  6422,  6428,  6431,
    6437,  6444,  6445,  6449,  6455,  6458,  6465,  6466,  6473,  6476,
    6481,  6492,  6493,  6494,  6495,  6496,  6497,  6498,  6499,  6500,
    6503,  6506,  6512,  6512,  6518,  6518,  6529,  6542,  6552,  6552,
    6557,  6557,  6561,  6565,  6566,  6572,  6573,  6578,  6582,  6589,
    6592,  6599,  6603,  6598,  6612,  6616,  6620,  6627,  6631,  6631,
    6644,  6648,  6648,  6663,  6665,  6667,  6669,  6671,  6673,  6675,
    6677,  6683,  6693,  6700,  6705,  6706,  6710,  6712,  6713,  6716,
    6717,  6718,  6721,  6726,  6733,  6734,  6740,  6752,  6753,  6756,
    6756,  6761,  6766,  6771,  6772,  6775,  6776,  6781,  6786,  6790,
    6795,  6796,  6800,  6807,  6811,  6812,  6817,  6819,  6823,  6824,
    6828,  6829,  6830,  6831,  6835,  6836,  6841,  6842,  6847,  6848,
    6853,  6854,  6859,  6864,  6865,  6870,  6871,  6875,  6876,  6881,
    6888,  6893,  6898,  6902,  6903,  6908,  6909,  6915,  6917,  6922,
    6923,  6929,  6932,  6935,  6942,  6944,  6958,  6963,  6964,  6967,
    6969,  6976,  6979,  6985,  6989,  6993,  6997,  7000,  7007,  7014,
    7019,  7023,  7024,  7030,  7033,  7044,  7051,  7057,  7060,  7067,
    7074,  7080,  7081,  7087,  7088,  7089,  7092,  7093,  7098,  7098,
    7102,  7110,  7111,  7114,  7117,  7122,  7123,  7128,  7131,  7137,
    7140,  7146,  7149,  7155,  7158,  7165,  7166,  7195,  7196,  7201,
    7209,  7214,  7217,  7220,  7223,  7229,  7230,  7234,  7237,  7240,
    7241,  7246,  7249,  7252,  7255,  7258,  7261,  7264,  7267,  7272,
    7278,  7279,  7280,  7281,  7282,  7284,  7285,  7287,  7288,  7293,
    7296,  7300,  7306,  7307,  7308,  7309,  7321,  7322,  7323,  7327,
    7328,  7333,  7335,  7336,  7337,  7339,  7340,  7341,  7342,  7344,
    7345,  7347,  7348,  7350,  7351,  7352,  7353,  7355,  7359,  7360,
    7366,  7368,  7369,  7370,  7371,  7376,  7380,  7384,  7388,  7389,
    7393,  7394,  7404,  7413,  7414,  7415,  7419,  7422,  7427,  7432,
    7437,  7445,  7449,  7453,  7454,  7455,  7460,  7463,  7466,  7480,
    7494,  7507,  7508,  7512,  7512,  7512,  7512,  7512,  7512,  7513,
    7516,  7521,  7521,  7521,  7521,  7521,  7521,  7523,  7526,  7532,
    7532,  7532,  7532,  7532,  7532,  7532,  7533,  7533,  7533,  7533,
    7533,  7533,  7533,  7535,  7536,  7539,  7548,  7548,  7554,  7554,
    7561,  7561,  7567,  7567,  7575,  7576,  7577,  7580,  7580,  7583,
    7584,  7585,  7590,  7593,  7599,  7604,  7612,  7625,  7626,  7623,
    7644,  7654,  7657,  7662,  7674,  7677,  7681,  7684,  7685,  7691,
    7694,  7695,  7704,  7713,  7718,  7719,  7720,  7721,  7728,  7731,
    7737,  7740,  7750,  7759,  7762,  7765,  7771,  7777,  7780,  7783,
    7786,  7792,  7794,  7796,  7798,  7800,  7802,  7803,  7804,  7805,
    7806,  7807,  7808,  7810,  7812,  7814,  7816,  7818,  7820,  7822,
    7823,  7828,  7829,  7836,  7839,  7848,  7852,  7859,  7859,  7863,
    7863,  7868,  7868,  7872,  7872,  7876,  7882,  7882,  7885,  7885,
    7891,  7898,  7899,  7900,  7904,  7905,  7908,  7909,  7913,  7919,
    7929,  7930,  7938,  7939,  7940,  7941,  7942,  7943,  7947,  7948,
    7949,  7953,  7953,  7965,  7966,  7970,  7971,  7972,  7973,  7974,
    7975,  7976,  7977,  7978,  7979,  7980,  7981,  7982,  7983,  7984,
    7985,  7986,  7987,  7988,  7989,  7990,  7991,  7992,  7993,  7994,
    7995,  7996,  7997,  7998,  7999,  8000,  8001,  8002,  8003,  8004,
    8005,  8006,  8007,  8008,  8009,  8010,  8011,  8012,  8013,  8014,
    8015,  8016,  8017,  8018,  8019,  8020,  8021,  8022,  8023,  8024,
    8025,  8026,  8027,  8028,  8029,  8030,  8031,  8032,  8033,  8034,
    8035,  8036,  8037,  8038,  8039,  8040,  8041,  8042,  8043,  8044,
    8045,  8046,  8047,  8048,  8049,  8050,  8051,  8052,  8053,  8054,
    8055,  8056,  8057,  8058,  8059,  8060,  8061,  8062,  8063,  8064,
    8065,  8066,  8067,  8068,  8069,  8070,  8071,  8072,  8073,  8074,
    8075,  8076,  8077,  8078,  8079,  8080,  8081,  8082,  8083,  8084,
    8085,  8086,  8087,  8088,  8089,  8090,  8091,  8092,  8093,  8094,
    8095,  8096,  8097,  8098,  8099,  8100,  8101,  8102,  8103,  8104,
    8105,  8106,  8107,  8108,  8109,  8110,  8111,  8112,  8113,  8114,
    8115,  8116,  8117,  8118,  8119,  8120,  8121,  8122,  8123,  8124,
    8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,  8133,  8134,
    8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,  8143,  8144,
    8145,  8146,  8147,  8148,  8149,  8150,  8151,  8152,  8153,  8154,
    8155,  8156,  8157,  8158,  8159,  8160,  8161,  8162,  8163,  8164,
    8165,  8166,  8167,  8168,  8169,  8170,  8171,  8172,  8173,  8174,
    8175,  8176,  8177,  8178,  8179,  8180,  8181,  8182,  8183,  8184,
    8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,  8193,  8194,
    8195,  8196,  8197,  8198,  8199,  8200,  8201,  8202,  8203,  8204,
    8205,  8206,  8207,  8208,  8209,  8210,  8211,  8212,  8213,  8214,
    8215,  8216,  8217,  8218,  8219,  8220,  8221,  8222,  8223,  8224,
    8225,  8226,  8227,  8228,  8229,  8230,  8231,  8232,  8233,  8234,
    8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,  8243,  8244,
    8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,  8253,  8254,
    8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,  8263,  8264,
    8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,  8273,  8274,
    8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,  8283,  8284,
    8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,  8300,  8300,
    8307,  8307,  8395,  8399,  8395,  8408,  8412,  8418,  8426,  8436,
    8446,  8458,  8461,  8480,  8506,  8509,  8515,  8518,  8523,  8526,
    8534,  8542,  8555,  8558,  8566,  8569,  8572,  8580,  8584,  8587,
    8590,  8593,  8597,  8598,  8599,  8600,  8601,  8607,  8608,  8609,
    8610,  8611,  8612,  8613,  8614,  8615,  8616,  8617,  8618,  8619,
    8620,  8624,  8630,  8631,  8643,  8664,  8664,  8668,  8669,  8670,
    8671,  8675,  8676,  8677,  8682,  8708,  8759,  8761,  8763,  8765,
    8769,  8774,  8776,  8779,  8781,  8783,  8787,  8790,  8795,  8800,
    8804,  8813,  8814,  8818,  8830,  8833,  8829,  8852,  8852,  8856,
    8857,  8860,  8861,  8862,  8863,  8864,  8865,  8866,  8871,  8872,
    8876,  8879,  8884,  8888,  8893,  8897,  8902,  8906,  8909,  8913,
    8916,  8921,  8925,  8936,  8942,  8942,  8943,  8944,  8951,  8960,
    8960,  8962,  8963,  8964,  8965,  8966,  8967,  8968,  8969,  8970,
    8971,  8972,  8973,  8974,  8975,  8976,  8977,  8978,  8979,  8980,
    8981,  8982,  8983,  8984,  8985,  8986,  8987,  8988,  8989,  8990,
    8991,  8992,  8993,  8994,  8995,  8996,  8997,  8998,  8999,  9000,
    9001,  9002,  9003,  9004,  9005,  9006,  9007,  9008,  9009,  9010,
    9011,  9012,  9013,  9014,  9015,  9016,  9017,  9018,  9019,  9020,
    9021,  9022,  9023,  9024,  9025,  9026,  9027,  9028,  9029,  9030,
    9031,  9032,  9033,  9034,  9035,  9036,  9037,  9038,  9039,  9040,
    9041,  9042,  9043,  9044,  9045,  9046,  9047,  9048,  9049
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
     687,   688,   688,   688,   688,   688,   689,   689,   689,   689,
     689,   690,   690,   691,   691,   693,   692,   692,   694,   694,
     695,   695,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   695,   695,   695,   695,   695,   695,   696,   696,   698,
     697,   699,   699,   700,   700,   700,   700,   700,   700,   700,
     700,   700,   701,   702,   703,   702,   702,   702,   702,   702,
     704,   705,   702,   706,   707,   708,   702,   709,   710,   702,
     711,   712,   702,   713,   714,   715,   702,   716,   716,   717,
     717,   717,   718,   718,   719,   719,   720,   721,   721,   722,
     722,   724,   723,   725,   723,   726,   726,   727,   727,   728,
     729,   730,   729,   731,   732,   731,   734,   733,   736,   735,
     737,   737,   737,   737,   737,   737,   738,   739,   739,   740,
     740,   741,   742,   742,   743,   744,   746,   747,   745,   748,
     748,   749,   749,   750,   750,   751,   751,   751,   752,   752,
     754,   753,   755,   753,   756,   753,   757,   753,   758,   753,
     759,   759,   760,   760,   761,   761,   761,   761,   761,   761,
     762,   763,   763,   764,   764,   765,   765,   766,   766,   768,
     769,   767,   767,   767,   770,   770,   772,   771,   773,   773,
     773,   773,   773,   774,   773,   775,   775,   775,   775,   776,
     777,   777,   778,   778,   779,   779,   779,   779,   781,   780,
     782,   780,   783,   780,   784,   784,   785,   785,   786,   787,
     787,   787,   788,   790,   789,   791,   789,   792,   789,   793,
     793,   794,   795,   796,   796,   798,   799,   797,   800,   800,
     800,   800,   800,   800,   800,   800,   800,   800,   800,   800,
     800,   800,   800,   800,   800,   800,   800,   800,   800,   800,
     800,   800,   800,   800,   800,   800,   801,   802,   803,   804,
     804,   805,   807,   806,   808,   808,   808,   808,   808,   808,
     808,   810,   809,   811,   811,   812,   812,   813,   815,   814,
     816,   816,   816,   816,   816,   816,   816,   817,   818,   818,
     820,   819,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   822,   824,   823,   825,   823,
     827,   826,   828,   826,   829,   829,   830,   831,   831,   832,
     833,   833,   833,   833,   833,   833,   833,   833,   834,   835,
     836,   838,   839,   837,   840,   840,   841,   842,   842,   843,
     843,   845,   844,   846,   844,   847,   844,   848,   849,   850,
     851,   851,   852,   852,   852,   852,   852,   852,   852,   852,
     852,   853,   853,   853,   853,   853,   853,   853,   853,   854,
     854,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   856,   856,   856,   856,   856,   856,   856,   856,   856,
     856,   856,   857,   857,   858,   858,   859,   859,   860,   860,
     861,   861,   862,   863,   863,   864,   864,   864,   864,   864,
     864,   865,   865,   866,   866,   866,   866,   867,   867,   868,
     869,   869,   869,   870,   869,   871,   871,   872,   872,   873,
     873,   873,   873,   874,   874,   875,   875,   875,   875,   875,
     875,   875,   875,   876,   877,   878,   878,   878,   878,   878,
     878,   879,   879,   879,   879,   879,   879,   879,   880,   882,
     883,   881,   884,   885,   881,   887,   888,   886,   889,   890,
     886,   891,   892,   886,   893,   894,   886,   886,   886,   886,
     886,   895,   895,   896,   897,   897,   897,   897,   897,   897,
     897,   897,   897,   898,   898,   899,   899,   899,   899,   900,
     900,   900,   901,   901,   902,   902,   902,   903,   903,   903,
     903,   903,   903,   903,   903,   903,   903,   904,   904,   905,
     905,   907,   908,   906,   909,   909,   911,   912,   913,   910,
     914,   914,   916,   917,   915,   918,   918,   919,   919,   920,
     920,   922,   921,   923,   921,   924,   924,   925,   925,   927,
     926,   928,   926,   929,   930,   930,   930,   931,   931,   932,
     932,   933,   933,   934,   934,   936,   935,   937,   935,   938,
     935,   939,   935,   940,   935,   941,   942,   942,   942,   942,
     942,   942,   942,   943,   943,   944,   945,   946,   947,   947,
     947,   947,   947,   947,   947,   947,   948,   949,   950,   951,
     952,   953,   954,   954,   955,   956,   957,   957,   958,   958,
     959,   959,   959,   959,   959,   959,   960,   961,   961,   962,
     963,   964,   964,   965,   966,   967,   967,   967,   968,   968,
     968,   970,   969,   971,   971,   972,   972,   973,   973,   974,
     975,   975,   976,   977,   977,   978,   979,   979,   980,   981,
     981,   983,   984,   982,   985,   986,   985,   987,   988,   985,
     989,   989,   990,   992,   991,   991,   993,   993,   994,   994,
     995,   995,   996,   996,   997,   997,   999,   998,  1000,   998,
    1001,   998,  1002,   998,  1003,   998,  1004,   998,  1005,   998,
    1006,   998,  1007,   998,  1008,   998,  1009,   998,  1010,  1010,
    1011,  1011,  1012,  1013,  1014,  1014,  1014,  1016,  1015,  1017,
    1017,  1018,  1017,  1019,  1020,  1020,  1020,  1020,  1021,  1021,
    1022,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,  1023,
    1025,  1024,  1024,  1027,  1026,  1028,  1029,  1030,  1030,  1031,
    1031,  1032,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,
    1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,  1033,
    1034,  1036,  1037,  1035,  1038,  1038,  1039,  1040,  1041,  1042,
    1042,  1044,  1043,  1045,  1045,  1046,  1046,  1047,  1047,  1047,
    1047,  1048,  1048,  1049,  1049,  1050,  1051,  1051,  1051,  1051,
    1051,  1051,  1051,  1051,  1051,  1051,  1051,  1052,  1052,  1053,
    1053,  1053,  1054,  1055,  1055,  1057,  1058,  1059,  1060,  1056,
    1061,  1063,  1064,  1062,  1065,  1066,  1066,  1067,  1067,  1068,
    1069,  1069,  1070,  1070,  1070,  1072,  1071,  1073,  1073,  1075,
    1076,  1077,  1074,  1079,  1078,  1080,  1082,  1081,  1083,  1081,
    1084,  1081,  1085,  1085,  1086,  1086,  1087,  1087,  1088,  1088,
    1088,  1089,  1090,  1091,  1092,  1092,  1092,  1093,  1093,  1094,
    1094,  1096,  1097,  1095,  1098,  1098,  1100,  1099,  1101,  1099,
    1102,  1103,  1103,  1103,  1103,  1104,  1104,  1104,  1104,  1104,
    1105,  1106,  1106,  1107,  1108,  1109,  1109,  1110,  1111,  1111,
    1111,  1111,  1111,  1111,  1112,  1113,  1114,  1114,  1115,  1115,
    1116,  1117,  1118,  1118,  1119,  1119,  1120,  1121,  1122,  1122,
    1122,  1122,  1122,  1122,  1123,  1123,  1124,  1125,  1125,  1126,
    1126,  1127,  1127,  1128,  1128,  1129,  1129,  1129,  1129,  1129,
    1130,  1130,  1131,  1131,  1132,  1132,  1133,  1134,  1135,  1135,
    1136,  1137,  1137,  1137,  1138,  1139,  1139,  1140,  1140,  1141,
    1142,  1142,  1143,  1143,  1144,  1145,  1146,  1147,  1147,  1148,
    1149,  1149,  1150,  1150,  1151,  1151,  1152,  1153,  1153,  1154,
    1154,  1154,  1154,  1155,  1155,  1155,  1156,  1157,  1157,  1158,
    1158,  1158,  1159,  1160,  1160,  1161,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,  1161,
    1161,  1161,  1161,  1161,  1161,  1161,  1161,  1162,  1163,  1163,
    1164,  1164,  1164,  1165,  1167,  1166,  1168,  1168,  1169,  1170,
    1170,  1171,  1171,  1172,  1172,  1174,  1173,  1175,  1177,  1176,
    1178,  1178,  1179,  1179,  1180,  1180,  1181,  1181,  1181,  1181,
    1182,  1182,  1183,  1184,  1184,  1185,  1186,  1187,  1188,  1189,
    1189,  1190,  1190,  1192,  1191,  1193,  1191,  1194,  1191,  1195,
    1191,  1196,  1191,  1197,  1191,  1198,  1191,  1199,  1199,  1199,
    1199,  1199,  1199,  1201,  1200,  1202,  1202,  1204,  1203,  1203,
    1203,  1203,  1203,  1205,  1205,  1206,  1206,  1207,  1208,  1208,
    1209,  1210,  1211,  1212,  1212,  1212,  1213,  1213,  1213,  1213,
    1214,  1215,  1215,  1216,  1216,  1217,  1218,  1218,  1218,  1218,
    1218,  1218,  1218,  1218,  1219,  1219,  1220,  1220,  1221,  1221,
    1221,  1221,  1221,  1221,  1221,  1221,  1221,  1221,  1222,  1222,
    1223,  1223,  1223,  1223,  1224,  1224,  1225,  1225,  1226,  1226,
    1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,  1226,
    1226,  1226,  1227,  1227,  1227,  1229,  1230,  1231,  1232,  1233,
    1234,  1228,  1235,  1235,  1236,  1237,  1237,  1239,  1240,  1241,
    1242,  1243,  1244,  1238,  1245,  1247,  1248,  1249,  1246,  1250,
    1250,  1250,  1250,  1251,  1251,  1251,  1251,  1251,  1252,  1253,
    1253,  1253,  1254,  1254,  1256,  1257,  1255,  1258,  1259,  1255,
    1260,  1260,  1261,  1261,  1262,  1262,  1263,  1263,  1263,  1264,
    1264,  1265,  1265,  1266,  1266,  1267,  1268,  1268,  1269,  1269,
    1269,  1269,  1269,  1269,  1269,  1270,  1270,  1271,  1271,  1272,
    1272,  1273,  1273,  1274,  1274,  1275,  1276,  1276,  1277,  1277,
    1278,  1279,  1279,  1280,  1281,  1281,  1282,  1282,  1283,  1283,
    1284,  1285,  1285,  1285,  1285,  1285,  1285,  1285,  1285,  1285,
    1285,  1285,  1286,  1286,  1287,  1287,  1288,  1289,  1291,  1290,
    1293,  1292,  1292,  1294,  1294,  1295,  1295,  1296,  1296,  1297,
    1297,  1299,  1300,  1298,  1301,  1302,  1302,  1303,  1304,  1303,
    1305,  1306,  1305,  1307,  1307,  1307,  1307,  1307,  1307,  1307,
    1307,  1308,  1309,  1310,  1311,  1311,  1312,  1313,  1313,  1314,
    1314,  1314,  1315,  1316,  1317,  1317,  1318,  1319,  1319,  1321,
    1320,  1322,  1322,  1322,  1322,  1322,  1322,  1322,  1322,  1322,
    1322,  1322,  1322,  1323,  1324,  1324,  1325,  1325,  1326,  1326,
    1327,  1327,  1327,  1327,  1328,  1328,  1329,  1329,  1330,  1330,
    1331,  1331,  1332,  1333,  1333,  1334,  1334,  1335,  1335,  1336,
    1337,  1338,  1339,  1340,  1340,  1341,  1341,  1342,  1342,  1343,
    1343,  1344,  1344,  1344,  1345,  1345,  1346,  1347,  1347,  1348,
    1348,  1349,  1349,  1350,  1350,  1350,  1350,  1350,  1351,  1352,
    1353,  1354,  1354,  1355,  1355,  1356,  1357,  1358,  1358,  1359,
    1360,  1361,  1361,  1362,  1362,  1362,  1363,  1363,  1364,  1364,
    1365,  1366,  1366,  1367,  1367,  1368,  1368,  1369,  1369,  1370,
    1370,  1371,  1371,  1372,  1372,  1373,  1373,  1374,  1374,  1375,
    1376,  1377,  1377,  1377,  1377,  1378,  1378,  1379,  1379,  1380,
    1380,  1381,  1381,  1381,  1381,  1381,  1381,  1381,  1381,  1381,
    1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1382,  1383,
    1383,  1383,  1384,  1384,  1384,  1384,  1385,  1385,  1385,  1386,
    1386,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,
    1387,  1387,  1387,  1387,  1387,  1387,  1387,  1387,  1388,  1388,
    1389,  1389,  1389,  1389,  1389,  1390,  1391,  1392,  1393,  1393,
    1393,  1393,  1394,  1395,  1395,  1395,  1396,  1396,  1397,  1397,
    1397,  1398,  1399,  1399,  1399,  1399,  1399,  1400,  1401,  1402,
    1402,  1403,  1403,  1404,  1404,  1404,  1404,  1404,  1404,  1404,
    1404,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1405,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  1407,  1407,  1407,  1407,
    1407,  1407,  1407,  1408,  1408,  1409,  1411,  1410,  1412,  1410,
    1413,  1410,  1414,  1410,  1415,  1415,  1415,  1416,  1416,  1417,
    1417,  1417,  1418,  1418,  1419,  1419,  1420,  1422,  1423,  1421,
    1424,  1425,  1425,  1426,  1427,  1427,  1427,  1427,  1427,  1428,
    1429,  1429,  1430,  1431,  1432,  1432,  1432,  1432,  1433,  1433,
    1434,  1434,  1435,  1436,  1436,  1436,  1437,  1437,  1437,  1437,
    1437,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,  1438,
    1438,  1439,  1439,  1440,  1441,  1442,  1442,  1443,  1443,  1444,
    1444,  1445,  1445,  1446,  1446,  1447,  1448,  1448,  1449,  1449,
    1450,  1451,  1451,  1451,  1452,  1452,  1453,  1454,  1455,  1456,
    1457,  1457,  1458,  1458,  1458,  1458,  1458,  1458,  1459,  1459,
    1459,  1461,  1460,  1462,  1462,  1463,  1463,  1463,  1463,  1463,
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
    1463,  1463,  1463,  1463,  1463,  1463,  1463,  1463,  1465,  1464,
    1467,  1466,  1469,  1470,  1468,  1471,  1471,  1471,  1472,  1472,
    1472,  1472,  1472,  1472,  1473,  1473,  1474,  1475,  1476,  1476,
    1477,  1477,  1478,  1478,  1479,  1479,  1479,  1480,  1480,  1480,
    1480,  1480,  1480,  1480,  1480,  1480,  1480,  1481,  1481,  1481,
    1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,  1481,
    1481,  1482,  1483,  1483,  1484,  1485,  1485,  1486,  1486,  1486,
    1486,  1487,  1487,  1487,  1488,  1488,  1489,  1489,  1489,  1489,
    1489,  1489,  1489,  1489,  1489,  1489,  1490,  1490,  1490,  1490,
    1490,  1491,  1491,  1492,  1494,  1495,  1493,  1496,  1496,  1497,
    1497,  1498,  1498,  1498,  1498,  1498,  1498,  1498,  1499,  1499,
    1500,  1500,  1501,  1501,  1502,  1502,  1503,  1503,  1504,  1505,
    1506,  1507,  1507,  1508,  1509,  1509,  1510,  1511,  1511,  1513,
    1512,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,
    1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514,  1514
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
       1,     3,     0,     1,     0,     1,     1,     1,     0,     7,
       0,     5,     0,    12,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     0,     4,     0,     5,     0,     7,     1,
       3,     1,     1,     0,     1,     0,     0,     4,     1,     1,
       1,     4,     4,     6,     1,     2,     1,     1,     1,     1,
       4,     6,     1,     4,     6,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     4,     1,     1,     0,
       3,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     0,     3,     0,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     1,     0,     1,
       0,     5,     1,     1,     1,     4,     4,     6,     1,     1,
       1,     1,     4,     6,     1,     4,     6,     1,     1,     1,
       1,     1,     2,     2,     1,     4,     0,     7,     0,    12,
       0,     4,     0,     5,     1,     3,     2,     1,     3,     1,
       0,     2,     2,     1,     2,     5,     4,     2,     4,     5,
       3,     0,     0,    11,     0,     2,     1,     0,     2,     1,
       2,     0,     3,     0,     3,     0,     3,     2,     2,     2,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     3,     1,     3,
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
       3,     0,     0,    11,     0,     2,     0,     0,     0,     9,
       0,     3,     0,     0,    10,     0,     1,     0,     1,     1,
       2,     0,     3,     0,     3,     0,     1,     1,     2,     0,
       3,     0,     3,     3,     1,     4,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     0,     3,     0,     3,     0,
       4,     0,     4,     0,     4,     2,     3,     1,     3,     1,
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
       1,     0,     0,     7,     1,     1,     2,     2,     2,     3,
       4,     0,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     0,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     0,     0,     0,     0,    13,
       1,     0,     0,     6,     2,     1,     2,     2,     2,     1,
       1,     2,     1,     1,     1,     0,     3,     2,     1,     0,
       0,     0,    14,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     2,     2,     2,     5,
       8,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       2,     2,     3,     6,     1,     3,     1,     1,     1,     3,
       6,     9,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       2,     0,     1,     1,     4,     1,     3,     1,     3,     7,
       0,     7,     0,     6,     3,     1,     3,     1,     2,     5,
       0,     7,     0,     2,     0,     1,     5,     2,     5,     0,
       5,     6,     4,     0,     1,     1,     4,     0,     2,     0,
       5,     4,     2,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       2,     4,     2,     1,     0,    11,     0,     2,     5,     0,
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
       1,     3,     3,     3,     6,     4,     4,     4,     4,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     1,     5,     5,     1,     1,     1,     4,     1,
       4,     1,     7,     1,     1,     1,     4,     6,     0,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     0,     3,     5,     1,     2,     2,     4,
       3,     1,     1,     1,     1,     1,     1,     2,     2,     0,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     8,     0,     9,
       0,     7,     0,     9,     0,     1,     2,     1,     3,     1,
       3,     5,     1,     1,     1,     1,     2,     0,     0,     8,
       5,     1,     1,     6,     0,     3,     1,     3,     4,     1,
       0,     2,     4,     6,     0,     1,     1,     1,     1,     3,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     2,
       4,     3,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     5,     4,     4,     3,
       4,     1,     3,     1,     5,     7,     5,     0,     2,     1,
       1,     0,     3,     1,     3,     1,     1,     1,     0,     3,
       1,     1,     1,     1,     4,     6,     1,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       4,     0,     4,     1,     2,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     3,     0,     0,     6,     0,     2,     2,     7,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     793,     0,  2099,  2102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   845,   179,     0,   817,   822,
     177,   182,   797,     0,   791,   794,   795,   798,   800,   844,
     799,   839,   840,   842,   183,   134,   131,     0,   127,   129,
     128,   132,  2143,   682,   624,  2106,     0,     0,  2109,     0,
    2105,  2101,  2098,  2096,  2097,  2104,  2103,  2100,   300,  1584,
    1583,   837,   175,   186,   838,   178,   183,     1,   801,   796,
     843,   841,   818,   126,   130,   133,  2113,  2110,     0,  2111,
    2108,     0,     0,   603,     0,     0,   176,   848,   912,   604,
     846,   636,   904,     0,   905,   913,   911,   186,   180,   199,
       0,   184,   200,   235,     0,   824,  1197,     0,     0,   823,
     135,  1185,   831,     0,     0,   814,   816,   813,   815,   792,
     802,   803,   825,   806,   807,   808,   811,   809,   810,   812,
    2112,  2107,     0,   906,   847,     0,     0,   920,   918,   919,
     908,   907,   298,   186,  1121,   193,   187,   186,   192,   232,
       0,   681,     0,     0,     0,     0,   175,   552,   881,   804,
       0,   332,   318,   202,   269,   288,   309,   311,   308,     0,
     330,     0,   317,   310,   314,   320,   304,   319,   186,   321,
     301,   324,   302,   303,   917,   916,     0,    21,    22,    13,
       0,   926,     0,    15,     0,   924,     0,   299,     0,   185,
    1122,   181,     0,   199,   201,   265,   259,   260,   248,   225,
     256,   202,   227,   269,   288,   246,   249,   244,     0,   223,
       0,   255,   247,   252,   258,   240,   257,   186,   261,   186,
     204,   238,   239,   236,   264,     0,     0,     0,     0,   832,
     175,   175,     0,     0,   203,     0,   322,     0,     0,   323,
       0,     0,     0,     0,     0,     0,     0,     0,   267,     0,
     914,     0,    16,    17,    18,    19,    20,     0,    14,     0,
     922,     0,   637,   188,   191,     0,   189,   190,     0,   196,
     195,   194,   197,   186,     0,   186,   262,   263,     0,     0,
     186,     0,     0,     0,     0,   245,   205,   206,   207,   210,
     233,  1198,     0,     0,  1186,  2149,   553,   882,   826,     0,
     214,   215,     0,   281,   283,   278,   279,   275,   277,   274,
     276,   273,     0,   283,   294,   295,   291,   293,   290,   292,
     285,     0,     0,     0,   334,     0,   337,   339,   222,     0,
     221,     0,     0,   186,    11,    12,   925,     0,   909,   638,
     198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,     0,   234,   237,   937,   680,   849,   937,     0,  2147,
    2149,  1121,  1678,   819,     0,   937,     0,     0,   270,     0,
       0,   280,   297,   271,   296,     0,   289,     0,   312,     0,
     306,     0,   331,     0,   336,   326,     0,     0,   315,   305,
     268,   325,     0,     0,     0,     0,     0,     0,   250,     0,
     242,   224,   208,     0,   253,   241,   266,   235,   943,     0,
     938,   939,   937,     0,   833,  2148,  2146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2130,     0,  1287,  1286,
       0,  1288,     0,   385,  1285,  1227,     0,     5,  1284,   386,
     383,     0,   388,   173,   478,  1099,     0,     0,  1294,   123,
     382,   381,  1219,   376,   478,     0,  1244,  2121,     0,   387,
     351,     0,     3,     2,     0,   384,  1224,     0,     0,   377,
     374,   389,     0,     0,     0,     0,  1292,  1282,   380,     0,
       0,     0,     0,     0,     0,     0,     0,  1281,     0,     0,
       0,   174,  1221,   373,   372,     0,     0,  2125,  2124,     0,
       0,     0,   136,  1220,   379,   378,     0,     0,   375,   478,
     478,     0,   546,     0,     0,     0,     0,     0,     0,   478,
     780,  1195,     0,     0,  1103,     0,  2114,     0,   103,     0,
       0,   853,     0,     0,     0,     0,   781,     0,     0,  1701,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   651,
       0,     0,     0,     0,     0,  2151,  2152,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,  2175,
    2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,
    2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,
    2196,  2197,  2198,  2199,  2200,   891,  2201,  2202,  2203,  2204,
    2205,  2206,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2214,
    2215,  2216,  2217,  1090,  1092,  1087,  1089,  1088,  1091,  2218,
    2219,  1218,  2220,  1223,  1222,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  1349,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2150,   820,   557,   821,     0,   886,
       0,   884,     0,   333,   216,   217,     0,   282,   287,     0,
       0,     0,     0,   335,   338,     0,   220,     0,   923,     0,
     226,     0,   186,     0,     0,     0,     0,   211,     0,  1199,
       0,     0,  1187,  1029,  1028,  1032,     0,     0,  1231,   625,
     626,   805,  1062,  1067,  2123,   618,   122,     0,     0,  2088,
    2087,   997,  2084,  2086,  2138,     0,  1238,     0,  1234,  1243,
       7,     0,     6,     0,  2131,  1063,     0,  1155,  1154,  1102,
    1153,  1101,     0,     0,     0,   433,   435,     0,  1192,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1551,
       0,     0,     0,   427,     0,     0,     0,     0,   426,     0,
       0,   443,     0,   514,     0,     0,     0,     0,     0,     0,
     422,  1295,     0,   392,   391,   398,   439,   436,   393,   512,
     504,   394,   396,   511,   397,   912,   434,   437,   442,  1283,
     513,   834,   412,  1680,  1289,   124,     0,  1066,   121,     0,
     787,    23,   620,   390,     0,   786,  1059,   788,     0,  1293,
     875,   874,   877,   873,   876,  2140,     0,   871,     0,   619,
     970,   872,  2134,     0,  2122,   120,   967,   683,   965,     0,
     616,  2117,   725,   724,     0,   726,   608,   722,     0,     0,
     980,   621,  1348,  1344,  1347,     0,     0,  1033,  1030,     0,
    1024,  1026,  1025,  1023,  1022,     0,     0,     0,  1021,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1011,  1002,  1003,     0,  1047,   420,    23,  2128,
       0,  2119,   125,   617,     0,  1196,  1194,  1120,     0,  1669,
    1670,  1121,  1209,  1121,  1104,  1105,  1108,  1123,  1296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    62,     0,
     912,     0,    68,     0,   101,   595,   639,     0,  1093,   987,
    1097,     0,     0,  1048,  1213,     0,     0,  1100,   643,   640,
     641,     0,   645,   646,     0,   648,   649,     0,   644,   947,
     949,     0,     0,   948,   727,   945,   692,   941,   369,   367,
     368,   903,     0,     0,     0,     0,   655,   656,     0,     0,
     901,   898,   899,   895,   896,   897,   890,   894,   893,     0,
       0,     0,     0,     0,     0,   561,   563,   555,   558,   559,
     888,  2149,   883,   885,   827,     0,   284,   286,   313,   307,
       0,     0,   316,   910,     0,   231,     0,   229,   251,   243,
     235,   254,   944,   175,   940,   850,   175,     0,     0,     0,
    1271,  1272,     0,     0,     0,  1245,  1246,  1248,  1249,  1250,
    1254,  1253,  1251,  1252,     0,     0,  2085,   921,     0,   999,
       0,     0,  1237,  1236,     0,  1230,     0,  1529,  1530,     0,
    1064,     0,    23,  1150,  1152,  1151,   425,   400,   399,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,  1559,  1557,  1558,  1554,  1556,  1553,  1555,  1547,
       0,     0,     0,     0,     0,   440,     0,     0,   518,   517,
       0,     0,   488,   485,   494,     0,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,   169,   519,   520,   521,   454,     0,     0,   453,
     463,     0,     0,   404,     0,     0,   405,   395,   401,   403,
     406,   407,   408,   409,   410,   402,   432,   431,   479,     0,
       0,   415,   416,   413,   414,   957,     0,     0,   356,    24,
     350,     0,     0,  1056,     0,     0,     0,     0,     0,     0,
       0,   974,  1679,     0,     0,   186,     0,     0,     0,  2119,
       0,     0,     0,     0,     0,   137,     0,     0,   984,   976,
     977,   982,  1345,  1346,   900,   418,   340,     0,   547,   600,
     599,   597,   602,  1005,   601,  1010,  1006,  1009,   779,   771,
     765,   777,   778,   763,   764,   772,   767,   773,   766,   776,
     770,   774,   769,   775,   762,   768,   755,   761,  1007,  1008,
       0,  1015,  1019,  1012,  1013,  1017,  1018,  1016,  1014,  1020,
       0,   789,     0,     0,     0,     0,     0,     0,   737,   736,
     733,  2120,  2127,    23,  1116,  1117,  1118,  1119,  1113,  1111,
    1210,  1125,  1110,  1106,     0,     0,  1107,  2115,     0,     0,
       0,     0,    97,     0,    98,     0,     0,     0,    73,     0,
       0,     0,   110,   105,     0,   880,     0,   879,     0,   478,
    1095,     0,   932,   933,   956,   927,   928,   782,   954,  1050,
    1215,     0,  1217,  1216,  1758,  1876,  1872,  1878,  1910,  1890,
    1881,  1840,  1802,  1930,  1896,  1904,  1793,  1899,  1759,  1705,
    1891,  1798,  1849,  1984,  1828,  1816,  1829,  1928,  1931,  1898,
    1852,  1934,  1717,  1991,  1927,  1955,  1728,  2028,  1817,  2000,
    1710,  1960,  1726,  1788,  1835,  1855,  1950,  1978,  1983,  1709,
    1907,  1936,  1721,  1723,  1747,  1765,  1786,  1796,  1806,  1859,
    1862,  1921,  1932,  1938,  1939,  1956,  2001,  2012,  1708,  1739,
    1764,  1763,  1766,  1772,  1774,  1782,  1792,  1813,  1831,  1834,
    1860,  1868,  1925,  1935,  1945,  1951,  1952,  1954,  1979,  2009,
    2016,  2021,  1729,  1732,  1743,  1750,  1752,  1757,  1760,  1762,
    1769,  1777,  1779,  1780,  1781,  1791,  1801,  1808,  1824,  1825,
    1836,  1854,  1858,  1871,  1887,  1911,  1919,  1929,  1933,  1940,
    1948,  1957,  1967,  1971,  1988,  1994,  1998,  2006,  2011,  2014,
    1753,  1873,  1916,  1737,  1738,  1756,  1761,  1768,  1770,  1784,
    1785,  1795,  1804,  1809,  1811,  1812,  1818,  1826,  1843,  1844,
    1857,  1885,  1889,  1892,  1897,  1901,  1909,  1917,  1918,  1923,
    1941,  1942,  1947,  1953,  1958,  1964,  1965,  1966,  1968,  1970,
    1972,  1981,  2003,  2004,  2005,  2010,  2027,  1712,  1867,  1875,
    1877,  1974,  1714,  1718,  1722,  1727,  1733,  1734,  1748,  1749,
    1751,  1754,  1767,  1783,  1803,  1805,  1815,  1819,  1821,  1822,
    1830,  1839,  1841,  1842,  1853,  1866,  1884,  1902,  1903,  1920,
    1922,  1926,  1937,  1959,  1969,  1977,  1999,  2002,  2017,  2018,
    2019,  1745,  1715,  1735,  1736,  1742,  1814,  1744,  1746,  1771,
    1773,  1787,  1864,  1989,  1797,  1799,  1807,  1810,  1832,  1833,
    1838,  1845,  1846,  1847,  2030,  1879,  1880,  1883,  1888,  1893,
    1900,  1905,  1906,  1908,  1915,  1944,  1946,  1962,  1973,  1975,
    1976,  1980,  1985,  1986,  1990,  1992,  1993,  2008,  2013,  2015,
    2020,  2022,  2026,  1874,  2025,  1711,  1713,  1716,  1720,  1730,
    1755,  1775,  1776,  1778,  1789,  1820,  1823,  1863,  1869,  1882,
    1886,  2023,  2024,  1924,  1943,  1949,  1961,  1963,  1982,  1987,
    1997,  2007,  1725,  1719,  1724,  1741,  1794,  1837,  1850,  1851,
    1912,  1914,  1996,  1870,  1827,  1894,  1740,  1790,  1800,  1865,
    1848,  1895,  1731,  1856,  1861,  1995,  1913,     0,  1703,  1706,
    1707,   671,     0,     0,     0,   660,   692,   692,   690,     0,
       0,   693,     0,    25,   659,   662,     0,   669,   665,   902,
     892,  1676,  1677,  1667,  1667,  1314,     0,     0,  1585,     0,
     186,  1297,     0,     0,  1298,  1342,   186,     0,  1343,     0,
    1624,     0,  1311,     0,  1360,  1359,  1358,  1356,  1357,  1355,
    1353,  1350,  1424,  1423,  1351,  1352,  1361,  1594,  1354,  1683,
    1682,  1681,  1362,  2149,  2149,   574,   565,   556,     0,   560,
    2149,   887,   175,     0,   327,   219,     0,   186,   228,   209,
    1200,   175,  1188,  1414,     0,  1413,     0,  1415,     0,  1416,
    1274,     0,  1280,  1276,  1273,     0,     0,     0,     0,     0,
       0,  1270,  1266,  1403,  1402,  1401,  1242,  1241,     0,  1265,
    1261,     0,  1257,  1255,     0,   629,     0,   628,     0,   998,
       0,     0,   996,  2091,  2093,  2092,  2089,  2139,  2136,  1235,
       0,     0,     0,  1228,   478,   348,     0,  1193,     0,     0,
       0,     0,  1624,     0,     0,     0,     0,     0,   536,   522,
     527,     0,   523,   526,   525,     0,     0,     0,     0,     0,
       0,   428,     0,   171,     0,   444,     0,     0,     0,     0,
       0,     0,     0,     0,   446,   445,   464,   455,   470,   473,
     474,   471,   477,   476,   475,   465,   466,   467,   468,   469,
     411,   456,   460,   478,   472,   459,   478,    92,     0,   438,
       0,     0,  1225,   989,  1060,  1061,  1058,  1057,     0,   878,
       0,     0,   605,     0,     0,     0,   968,   966,     0,   685,
     686,     0,     0,  2118,  2126,     0,     0,   612,     0,   614,
     723,     0,   141,     0,   978,   985,     0,     0,   993,     0,
     343,     0,     0,     0,     0,    23,  1031,   550,     0,     0,
       0,   756,   757,  1004,   790,   421,     0,  1039,  2129,   734,
     735,   370,     0,  1121,     0,  1124,  1109,  2149,     0,     0,
       0,   539,     0,     0,     0,     0,    63,    92,     0,     0,
     116,   111,     0,   106,     0,   113,   107,   864,   856,   862,
       0,  1094,     0,  1096,  1098,     0,     0,   936,     0,     0,
       0,     0,  1049,  1214,     0,     0,  1702,  1704,  2149,   642,
     647,   650,   663,   661,   622,     0,   712,   710,   716,   714,
       0,     0,   708,   752,   706,   702,   700,   750,   728,     0,
     694,   704,   946,   942,     0,     0,     0,     0,   668,     0,
       0,     0,     0,     0,     0,     0,  1532,     0,  1419,  1420,
    1688,  1383,  1441,     0,     0,  1686,     0,     0,  1626,  1627,
    1625,  1607,  2032,     0,  1366,  1372,  1371,  1370,  1374,     0,
    1367,  1368,     0,  1595,  1606,   562,   564,     0,     0,   577,
     569,   571,     0,   566,   567,     0,     0,   585,   587,     0,
       0,   583,   889,   828,   218,     0,     0,   230,  1156,   851,
    1134,  1391,  1393,     0,  1278,     0,     0,     0,     0,     0,
    1268,     0,     0,  1524,  1522,  1509,  1511,  1507,     0,  1506,
       0,  1515,  1502,  1523,     0,  1514,  1499,  1505,  1521,  1513,
    1407,  1496,  1497,  1498,     0,  1263,  1259,     0,     0,  1247,
     627,     0,     0,     0,     0,     0,  2135,     4,     8,    10,
    1528,  1531,     0,   478,   510,   507,   506,   509,   505,     0,
     430,   516,   501,   501,     0,   524,     0,   528,     0,   288,
    1192,     0,  1552,   508,  1192,   515,   429,   272,     0,  1192,
     489,   486,   495,  1192,   492,  1192,  1192,  1192,     0,     0,
       0,     0,     0,     0,     0,     0,   480,    93,    94,    96,
     482,   417,     0,     0,     0,   986,     0,     0,     0,     0,
       0,     0,     0,   186,   684,     0,   609,   611,     0,     0,
     158,   156,     0,     0,   138,     0,   148,   154,   692,   143,
     145,     0,   983,   994,   995,     0,   419,   342,   347,   607,
     341,     0,   344,   349,   478,  1320,   598,   596,     0,   759,
    1038,  1040,     0,   371,  1114,  1112,  1211,  1212,     0,     0,
    1205,     0,     0,     0,     0,    99,     0,     0,    74,    80,
      70,  2149,  2149,   109,   104,   118,   114,     0,   108,   753,
     865,   622,  2149,   855,   854,   863,   988,     0,     0,   934,
     935,   929,   955,   478,     0,     0,  1650,  1542,  1545,  1651,
    1549,  1543,  1648,     0,     0,  1055,  1647,     0,     0,  1649,
       0,     0,     0,     0,     0,  2088,  1544,  1051,  1052,  1646,
    1546,  1638,  1054,  1633,  1636,  2094,  1637,  2029,   952,  2031,
     950,   672,   666,   664,     0,    23,     0,  2149,  2149,  2149,
    2149,   718,   696,   720,   698,  2149,  2149,  2149,  2149,     0,
     691,   695,  2149,   622,   748,   746,   749,   747,     0,     0,
      45,    43,    40,    34,    38,    42,    37,    30,    39,     0,
      33,    36,    31,    41,    32,    44,    35,     0,    28,    46,
     740,     0,   670,  1668,     0,  1666,  1624,  1664,  1611,  1612,
    1604,  1590,  1605,     0,     0,     0,  1027,  1418,  1421,     0,
       0,     0,     0,  1442,  1332,  1303,  1691,  1690,  1689,     0,
       0,     0,     0,  1327,     0,  1326,     0,  1328,  1323,  1324,
    1325,  1316,  1312,     0,     0,  1373,     0,     0,     0,  1599,
    1596,  1597,   576,   581,     0,     0,  2149,  2149,   554,   568,
     591,   579,   593,  2149,  2149,   589,   573,   584,   819,   328,
     212,     0,  1182,  1201,   819,     0,  1189,  1182,     0,     0,
    1275,     0,     0,     0,     0,     0,  1447,  1449,  1451,  1491,
    1490,  1489,  1453,  1469,  1277,     0,  1533,     0,  1392,     0,
    1395,  1536,     0,  1399,     0,  1267,     0,     0,  1575,  1573,
    1574,  1570,  1572,  1569,  1571,     0,     0,     0,     0,     0,
       0,     0,     0,  1405,     0,  1408,  1409,     0,  1262,     0,
    1256,  1258,  2090,     0,     0,     0,  2137,     0,     0,  1239,
     835,     0,     0,  1628,  1630,   498,     0,   499,     0,   538,
       0,   535,   532,   503,   497,  1130,  1560,  1129,     0,   170,
    1128,     0,     0,     0,  1131,     0,  1133,  1132,  1126,   457,
     458,   462,   447,     0,   450,   461,     0,   449,     0,     0,
      92,     0,     0,     0,     0,  1290,  2142,  2141,   606,     0,
       0,    47,     0,   689,   688,   687,  1291,     0,     0,   692,
    2149,  2149,   150,   630,   160,   152,   162,   142,   149,  2149,
       0,     0,     0,     0,     0,     0,     0,  1321,   548,     0,
     758,  1036,     0,  2116,     0,    92,   540,     0,    64,     0,
       0,     0,    77,     0,    92,    92,   117,   112,  2149,  2149,
     102,     0,   866,   860,   868,   867,   857,   544,   915,     0,
       0,  1635,  1634,  1548,     0,  1624,     0,     0,  1492,     0,
    1492,  1492,  1492,  1492,  1639,     0,     0,     0,     0,     0,
       0,  1692,  1693,  1694,  1695,  1696,  1697,  1642,     0,     0,
       0,   674,   653,   667,   623,   729,     0,   713,   711,   717,
     715,     0,  2149,     0,  2149,   709,   707,   703,   701,   751,
     705,    23,   741,     0,     0,     0,    26,     0,  1671,     0,
    1594,     0,     0,  1603,  1586,  1602,  1422,     0,  1385,     0,
    1331,  1429,     0,     0,  1687,     0,  1684,  1608,     0,     0,
       0,     0,     0,     0,  2033,  1330,  1329,  1317,  1315,     0,
    1376,     0,  1369,     0,     0,     0,     0,   578,   575,   570,
     572,     0,  2149,  2149,   586,   588,  2149,  2149,     0,     0,
    1180,  1181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1179,     0,     0,  1167,  1168,  1169,  1166,
    1171,  1172,  1173,  1170,  1157,  1148,     0,     0,  1204,     0,
    2149,     0,  1143,     0,     0,     0,     0,     0,     0,     0,
    1135,  1136,     0,  1068,     0,  1279,  1452,     0,  1456,     0,
    1469,  1455,     0,  1417,     0,  1470,  1485,  1482,  1483,  1480,
    1488,  1487,  1481,  1484,     0,     0,     0,     0,     0,  1486,
       0,     0,     0,  1537,     0,  1538,     0,     0,     0,     0,
    1398,  1269,  1397,  1389,     0,     0,     0,  1526,  1518,  1518,
       0,     0,  1518,  1525,     0,  1542,  1404,  1406,  1410,  1411,
    1264,  1260,  1001,     0,   964,     9,     0,  1232,   836,  1065,
       0,     0,  1441,  1614,  1631,     0,   501,   529,     0,   281,
     490,   487,   496,   493,     0,   452,   451,   481,    95,   483,
     354,  1226,     0,     0,  2133,     0,     0,   969,    48,     0,
     613,   615,   610,   738,   159,   157,     0,  2149,     0,     0,
       0,  2149,   155,   144,     0,   147,   146,     0,   975,   979,
     346,     0,   551,     0,  2149,   760,     0,   622,  1115,     0,
    1206,    69,     0,     0,   100,    67,    92,    75,    81,     0,
     119,   115,   754,  2149,   870,   622,   869,     0,   541,     0,
     784,   785,   783,     0,     0,  1659,     0,     0,     0,  1494,
    1495,  1493,     0,  1661,     0,     0,     0,     0,     0,     0,
       0,  1053,  1644,  1645,  1643,  1641,  2095,   953,   951,   677,
     675,     0,   657,   654,     0,   719,   697,   721,   699,   730,
     744,   745,   742,   743,    29,    27,     0,  1665,  1620,  1591,
    1592,  1588,  1594,     0,  1384,  1624,  1387,     0,  1305,  1300,
    1299,  1302,     0,  1620,     0,     0,  2066,  2064,     0,     0,
    2052,  2063,     0,     0,  2065,     0,     0,     0,     0,     0,
    2088,  2062,  2058,     0,  2050,  2053,  2054,  2061,  2057,  2081,
       0,  2043,  2042,  2046,  2048,     0,  2041,     0,  2044,  2035,
    1318,  1313,     0,  1375,     0,     0,  1600,  1598,   582,   580,
     592,   594,   590,     0,     0,   235,  1174,  1175,  1176,  1178,
    1161,  1159,  1158,  1162,  1163,  1160,  1177,  1164,  1165,  1149,
     961,  1184,   958,     0,     0,  1202,     0,  1147,  1146,  1141,
    1139,  1138,  1142,  1140,  1144,  1145,  1137,  1190,  1394,  1454,
    1448,  1450,  1457,  1459,  1457,     0,  1464,  1457,     0,  1462,
    1457,     0,  1472,  1471,     0,  1473,     0,  1390,  1396,  1540,
    1533,  1400,  1582,  1580,  1581,  1577,  1579,  1576,  1578,  1508,
       0,  1510,     0,     0,     0,     0,  1516,  1520,     0,  1500,
    1412,  1000,  1240,  1233,  1229,  1629,     0,  1430,  1431,  1433,
    1436,  1443,     0,     0,  1492,  1616,  1610,  1567,  1565,  1566,
    1562,  1564,  1561,  1563,   502,   500,     0,   534,   533,   172,
     448,     0,     0,    23,     0,     0,   992,     0,    49,   972,
       0,    23,   161,   151,     0,   632,   634,   163,   153,   738,
       0,   345,  1322,     0,  1037,    23,     0,     0,    65,     0,
      78,    87,     0,    71,   861,   858,   545,  2149,   930,  1550,
       0,     0,     0,  1660,     0,     0,     0,  1658,     0,     0,
       0,     0,  1640,  1657,     0,  2149,   673,   652,   658,   622,
    1675,     0,  1673,     0,     0,  1594,  1594,  1587,  1386,     0,
    1388,  1382,     0,  1304,     0,  1685,     0,  2056,  2055,     0,
       0,  1492,     0,  1492,  1492,  1492,  1492,  2059,     0,     0,
    2039,     0,     0,     0,     0,  2068,  2040,     0,     0,     0,
       0,     0,     0,  2034,     0,  1377,  1380,  1364,  1378,  1381,
       0,   830,   829,   329,   213,   963,   962,   960,     0,  1183,
    1069,  1073,  1075,     0,  1079,     0,  1077,  1081,  1070,  1071,
       0,   852,     0,     0,  1476,  1478,     0,  1465,  1468,  1467,
    1475,     0,  1477,  1457,     0,     0,  1534,  1539,     0,  1527,
    1519,  1503,  1501,     0,  1504,     0,  1434,     0,  1541,  1437,
       0,  1444,  1445,  1619,  1232,     0,     0,     0,     0,   531,
     530,   484,   355,   352,     0,   990,     0,     0,     0,   971,
     739,   139,   631,    23,   981,   549,  1034,    66,  1207,    83,
       0,     0,    76,    87,    87,  2149,   542,     0,     0,     0,
       0,     0,  1656,  1662,  1652,  1653,  1654,  1655,     0,   676,
     731,     0,  1672,  1621,  1614,  1593,  1589,     0,  1306,     0,
    1614,  2079,     0,     0,  2082,     0,     0,     0,     0,     0,
       0,     0,  2051,  2070,  2071,  2069,  2067,  2049,     0,  2045,
    2047,  2036,  2037,  1319,     0,  1365,  1363,  1601,   959,  2149,
    2149,  1083,  2149,  1085,  2149,  2149,  1072,  1203,  1191,  1458,
    1663,  1460,     0,  1463,  1461,  1479,     0,     0,     0,  1517,
    1438,     0,  1432,  1426,  1427,  1632,     0,  1446,  1440,  1617,
    1337,  1333,  1334,  1339,  1338,  1615,  1232,     0,   357,   991,
    2132,     0,     0,     0,     0,     0,     0,    54,     0,    53,
       0,    51,     0,     0,   140,  1041,    87,    92,    87,    88,
      82,    72,   859,     0,     0,  1623,     0,  1700,     0,   678,
      23,  1674,  1613,  1622,  1310,     0,  1307,  1309,  1609,  2080,
       0,     0,  2078,     0,     0,     0,     0,  2060,  2077,     0,
    1379,  1074,  1076,  2149,  1080,  2149,  1078,  1082,  1466,  1474,
    1535,  1512,     0,  1435,     0,  1425,     0,  1341,  1340,  1336,
    1618,  1568,   363,   361,   353,     0,   359,   365,    56,    61,
      58,    60,    57,    59,    55,     0,    50,     0,   633,   635,
    1045,  1035,     0,  1043,  1208,    84,    79,   543,   931,  1698,
    1699,  2149,   732,     0,  1301,  2076,  2083,  2072,  2073,  2074,
    2075,     0,  1084,  1086,  1439,  1428,  1335,  2149,  2149,   358,
     360,  2149,    52,     0,  2149,  1042,  1044,     0,   674,  1308,
    2038,   364,   362,   366,     0,  1046,    85,   679,   973,    89,
      91,     0,    86,    90
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   565,   566,   567,   568,   731,  2077,  2078,   191,   267,
     192,  1158,  1159,  1965,  2307,  3379,  2807,  2808,  3257,  3380,
    3381,   569,   918,  2842,  2545,  3274,  1907,  2543,  3111,  2846,
    3270,  2544,  3112,  3387,  3497,  3509,  3272,  3512,  2126,  2127,
    2128,  1273,  2194,   570,  1284,   923,  1282,  1915,  2204,  1912,
    2202,  2207,  2549,  1283,  2201,  1916,  2548,   571,    18,    37,
      38,    39,    40,    41,   116,   574,   849,  1862,  1185,  2154,
    2158,  2159,  2155,  2156,  2817,  2821,  2519,  2511,  2510,  2512,
    2515,  1136,  1088,  2108,   575,    85,    86,    20,    63,   144,
      98,   258,   100,   101,   202,   281,   102,   103,   245,   299,
     231,   695,   361,  2669,   312,   676,  2025,   339,   340,   232,
     290,   283,   285,  1006,  1007,   148,   363,   149,   150,   300,
     233,   234,  1848,   401,   246,   249,   247,   248,   321,   378,
     379,   381,   386,   679,   250,   251,   330,   383,   198,    21,
      82,   180,   181,   182,   685,  2668,   183,   254,   243,   333,
     334,   335,   336,  1875,   576,   577,   578,   579,   806,  3368,
    3083,  1160,  3444,  3445,  3446,  3488,  3487,  3491,   580,   581,
     582,   583,   584,   585,   586,   780,  1137,   801,  1152,  1153,
    1194,   886,  1195,   782,   783,   784,   785,   786,   787,   788,
    1091,  1138,  2483,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
     736,   789,  1827,  2488,  2490,  3081,   790,  1797,  2472,  1796,
    2471,  1800,  2475,  1798,  2473,  2455,  2464,   791,   792,   793,
     794,  1781,  1782,  1783,  1784,  1900,   587,  3117,  3393,  2858,
     588,   859,  1877,  2834,  2175,   117,   240,   373,  1696,   987,
     988,   989,  1693,  1694,  2012,  2013,  2014,  2366,  2367,  1697,
    1698,  2008,  2370,  2362,  2020,  2021,  2373,  2374,  2666,  2662,
    2663,   589,  1203,    87,  1843,  1844,  2170,   889,   839,   892,
     714,   828,   811,   850,  2265,    88,   715,   709,  1746,  2514,
      89,   796,   590,   591,   939,   940,   592,   593,   594,   595,
     947,  2892,   971,  3137,   972,  1942,   973,  2262,   974,  2592,
     975,  1968,   596,  1938,  2591,  2891,  3135,  3134,  3471,   118,
      22,   597,  1176,  1849,  1850,  1958,  1642,  1959,  1960,  2602,
    2604,  2278,  2277,  2282,  2276,  2275,  2268,  2267,  2270,  2269,
    2272,  2274,   598,   599,   847,   600,  1638,   954,  3400,   601,
    1250,  3091,  2309,  2310,  1961,  2279,  2210,  2551,   882,  1231,
    1881,  2178,  1882,  1227,   602,   603,   932,  1930,  2862,   604,
     605,   606,   607,    23,    68,    24,    25,    26,   119,   120,
     608,   121,    27,   666,    28,   122,   123,   160,   375,  1702,
    2378,  3192,   124,   156,   305,   609,  2451,    29,    30,    31,
      32,    33,    62,    90,   125,   422,  1711,  2384,   610,   927,
    2214,  1919,  2212,  3275,  2853,  1920,  2211,  2554,  2855,   611,
     612,   613,   822,   823,  1286,   126,   241,   374,   670,   671,
     991,  1700,   614,   976,   977,   615,  1650,   978,   797,    92,
      93,    94,    95,  1293,   186,   140,    96,   720,   137,   194,
     195,  1294,  1295,  2221,  1296,   419,   420,   956,   421,   957,
    2259,  2260,  1297,  1298,  1156,  2991,  2992,  3197,  1755,   837,
     838,   616,  1171,  3259,   617,  2829,   618,  1189,  1190,  1191,
    1868,  1866,   619,   620,  2135,  2165,   621,  1039,  1752,   622,
     883,   884,   623,   705,   624,  2320,   625,  3385,  2837,   626,
    2182,  3461,  3462,  3463,  3494,   888,   627,  1299,  1932,  2247,
    2248,   628,  1836,   713,  1051,   629,   630,   631,  2386,  2995,
    3208,  3209,  3329,  3330,  3334,  3332,  3335,  3423,  3425,   632,
     633,  1288,  1924,   634,  1290,   903,   904,   905,  1266,   635,
     636,   637,  1893,  1258,   898,   201,   906,   907,   798,  2387,
    2710,  2711,  2694,   739,   740,  2382,  2695,  2698,   127,   155,
     367,  1016,  2030,  2712,  3212,  1061,   638,   896,   128,   152,
     364,  1013,  2028,  2699,  3210,  2383,   922,  2535,  3107,  3386,
    1261,   639,   640,   641,   642,   643,   809,  2133,   733,  2082,
     644,  3054,   727,   728,  2448,  1731,   645,   646,  1025,  1026,
    1027,  1743,  2067,  1028,  2064,  1740,  1029,  2039,  1732,  1030,
    1031,  1032,  1033,  2033,  1723,   647,   818,   799,   648,  1674,
    1675,  1983,  2920,  3154,  2633,  2917,  3405,  3406,  1676,  1993,
    2647,  1656,  2352,  2961,  3184,  2528,  2833,  2353,  1677,  1678,
    3065,  3361,  3362,  3363,  3439,  1679,  1680,  1193,   649,   853,
     650,   984,  1681,  1682,  3326,  1999,  2000,  2001,  2355,  2649,
    3187,  3188,  1683,  2330,  2627,  3151,  1733,  1734,  1719,  2407,
    2031,  2408,  1735,  2412,  1736,  2435,  1737,  2436,  2767,  2768,
    2034,  1684,  1977,  1978,  2327,  1685,  3357,  3241,  3353,  2333,
    2782,  3057,  3058,  3059,  3351,  2783,  2334,  3242,  3358,  2395,
    2396,  2397,  2398,  2399,  3214,  3012,  3339,  2400,  3216,  3217,
    2741,  2401,  2742,  2402,  2872,  2060,  2061,  2062,  3043,  2063,
    2764,  2758,  3230,  2409,  3189,  2745,  2953,  2411,  3239,  2249,
     800,  2250,  2563,  1079,  2456,  3074,  2425,  3039,    61,   651,
     652,  2912,  3146,  2620,  3145,  2004,  2360,  2361,  2624,  2321,
    1686,  2322,  2341,  2923,  1773,  2317,  2318,  3066,  3244,  3144,
    2916,  2251,  1991,  2452,  2453,  3354,  2403,  2253,  2254,  2874,
    3341,   653,   654,  1970,  2319,  2907,  3141,  3142,  1653,   655,
     804,  1688,  1689,  1986,  2635,  1690,  1691,  2338,  2587,  2867,
     656,   935,  1627,  1628,  1629,  1934,  1630,  1935,  1692,  2342,
    2959,  3183,  2644,  2956,  2957,  2958,  2955,  2943,  2944,  2945,
    2946,  2947,  2948,  3305,   721,  2255,   723,  1756,  2256,    66,
      50,    80,    77,   658,   909,  1897,  1179,  1252,   659,   890,
     660,  2501,   661,  2076,   725,  1758,   662,   663,    44,   368,
     369,   370,   371,   372,   664
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2879
static const short yypact[] =
{
    1238,   936, -2879, -2879,   328,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   328,  1217, -2879, -2879,  1217, -2879,  1810,
   -2879, -2879, -2879,   341, -2879,  1238, -2879, -2879, -2879, -2879,
   -2879,  1712, -2879, -2879, -2879, -2879, -2879,   419,   367, -2879,
     512, -2879, -2879, -2879, -2879, -2879,   328,    67, -2879,   145,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,  1826,   423, -2879, -2879, -2879, -2879,  1723, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,   328, -2879,
   -2879,    67,   247, -2879,   328,   592,  1810, -2879,   962, -2879,
   -2879, -2879, -2879,   408,   253, -2879, -2879, -2879,   892,   623,
     328, -2879, -2879,   896,   328, -2879, -2879,   328,   328, -2879,
   -2879, -2879, -2879,   328,   328, -2879, -2879, -2879, -2879, -2879,
    1723, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,  4715,   253, -2879,   787,   267, -2879, -2879,   530,
   -2879, -2879,   932,   423,   458, -2879, -2879, -2879, -2879, -2879,
    3411, -2879,   328,   572,   904,   328,  1810, -2879, -2879, -2879,
     328, -2879, -2879,   509,   578, -2879, -2879,   625, -2879,   633,
   -2879,   615, -2879, -2879,   652, -2879,   658, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879,   690, -2879, -2879, -2879,
     267,  1670,  1099, -2879,   164, -2879,   267, -2879,   180, -2879,
   -2879, -2879,   147, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,   509, -2879,   578, -2879, -2879,   717, -2879,   728, -2879,
     661, -2879, -2879,   736, -2879,   749, -2879, -2879, -2879, -2879,
     801, -2879, -2879, -2879, -2879,   759,  1182,   328,   785, -2879,
    1810,  1810,   790,   328, -2879,    76, -2879,   604,  1330, -2879,
     621,  1362,  1266,  1278,   328,  1287,  1294,  1324, -2879,   668,
   -2879,   977, -2879, -2879, -2879, -2879, -2879,   267, -2879,   267,
     900,   191, -2879, -2879, -2879,  1341, -2879, -2879,  1346, -2879,
   -2879, -2879, -2879, -2879,    76, -2879, -2879, -2879,  1349,  1359,
     423,  1287,  1363,  1366,   782, -2879, -2879, -2879, -2879, -2879,
    1347, -2879,  1017,   994, -2879,  1077, -2879, -2879, -2879,   821,
   -2879, -2879,  1419, -2879,  1021, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,  1362,  1021, -2879, -2879, -2879, -2879, -2879, -2879,
    1025,   184,   255,   277, -2879,  3535, -2879, -2879, -2879,  1033,
    1462,   258,  1078, -2879, -2879,  1670, -2879,   267,  1026, -2879,
   -2879,   880,  1487,  1270,   259,   273,   357,  1111,   282,  1150,
   -2879,   923, -2879, -2879,   328, -2879, -2879,   328,  1227, -2879,
    4168,   458,  6581,  2249,   201,   328,  1531,    41, -2879,  1330,
    1567, -2879, -2879, -2879, -2879,  1574, -2879,  1578, -2879,  1585,
   -2879,   328, -2879,   328, -2879, -2879,  1287,  1599, -2879, -2879,
   -2879, -2879,   197,   267,  1555,    41,  1194,  1607, -2879,  1608,
   -2879, -2879, -2879,  1617, -2879, -2879, -2879, -2879,  1030,  1255,
    1651, -2879,   328,  1267, -2879, -2879, -2879,   803,   328,   283,
     328,   328,   283,   283,  1002,   328, -2879,   328, -2879, -2879,
     328, -2879,   833, -2879, -2879, -2879,   283, -2879, -2879, -2879,
   -2879,   328, -2879, -2879, -2879, -2879,    66,    66,  8851, -2879,
   -2879, -2879, -2879, -2879, -2879,   283, -2879, -2879,   283, -2879,
   -2879,   328, -2879, -2879,   283, -2879, -2879,   679,   283, -2879,
   -2879,  8851,   283,   679,   328,   679,   283, -2879, -2879,   116,
     283,   283,   116,   283,   328,   116,   283, -2879,   283,   283,
     283, -2879, -2879, -2879, -2879,   679,   283, -2879, -2879,   283,
      43,   328, -2879, -2879, -2879, -2879,   283,  1027, -2879, -2879,
   -2879,   283, -2879,  1861,   679,  8851,    44,    44,   283, -2879,
   -2879,   803,   679,  1180,  8851,  8851, -2879,  1417,  8851,   283,
      67, -2879,  8851,   283,  1635,   679, -2879,   283,  8851, -2879,
    8851,    66,   328,   283,   328,    44,   283,   328,    44, -2879,
     328,   161,   679,   679,   679, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,   187, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,   795, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879,   701, -2879,   328, -2879,
     314, -2879,  1273, -2879, -2879, -2879,  1379, -2879, -2879,  1290,
    1293,  1301,  1302, -2879, -2879,  1074,  1700,  1316, -2879,   217,
   -2879,  1408, -2879,  1319,  1320,  1089,  1323, -2879,   328, -2879,
     328,  1331, -2879, -2879, -2879, -2879,   353,  1299, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1104,  1321,  1272,
   -2879,  1110, -2879,  1114, -2879,  1728,  -148,   315, -2879, -2879,
   -2879,  1311, -2879,  1355, -2879,  1260,   190, -2879, -2879, -2879,
    1477, -2879,  8851,  8851,  8851, -2879, -2879,  1313,  1219,  1315,
    1318,  1322,  1329,  1332,  1333,  1336,  1342,  1345,  8851,  1449,
    1348,  1350,  1354, -2879,  8851,  8851,  1356,  1357, -2879,  8851,
    1365, -2879,  1368,  1370,  1372,  1373,  1378,  1380,  1381,  1382,
    8134, -2879,   102, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,   612, -2879,  1326, -2879, -2879,
   -2879, -2879,  8230, -2879, -2879, -2879,   679, -2879, -2879,  1355,
   -2879,   -74, -2879, -2879,  1484, -2879,    58, -2879,  1291, -2879,
   -2879, -2879, -2879,  1757, -2879, -2879,   169, -2879,  1144, -2879,
    1148,  1757, -2879,  1181, -2879, -2879,  1369,    92, -2879,  1337,
   -2879,  1121, -2879, -2879,  1383, -2879,   -92, -2879,  1151,   269,
    -187, -2879,  1104,  1491, -2879,  8851,  8851, -2879,  1812,   283,
   -2879, -2879, -2879, -2879, -2879,   118,   118,   118, -2879,   118,
    1042,   118,   118,  1223,   -74,  1223,  1223,  1187,  1187,  1223,
    1223,   -74, -2879,  1817, -2879,    33,  1819, -2879,   -74, -2879,
      82,    61, -2879, -2879,  8851, -2879, -2879, -2879,   909, -2879,
   -2879,   458,  1443,   458,  8851, -2879,    81, -2879, -2879,  8851,
    1399,  1400,  1402,  1410,  1433,  1413,  1180,  1370, -2879,  1495,
     973,  1257, -2879,  1275, -2879, -2879, -2879,  1228, -2879,  1844,
   -2879,  1842,   328, -2879,    49,  5956,  1285, -2879, -2879,  1858,
   -2879,  1204,  1858,  1870,  1206,  1858,  1870,  8851,  1858, -2879,
   -2879,   190,   679, -2879, -2879,  1455,   334, -2879, -2879, -2879,
   -2879, -2879,  1448,   679,  8851,  1450, -2879, -2879,  1855,  1857,
    1820, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1232,
    1232,   283,   283,   283,  1973, -2879, -2879,  1793,   701, -2879,
   -2879,   488, -2879, -2879, -2879,  1427, -2879, -2879, -2879, -2879,
    4715,  1287, -2879, -2879,  1430, -2879,   338, -2879, -2879, -2879,
   -2879, -2879, -2879,  1810, -2879, -2879,  1810,   975,   194,  1865,
   -2879, -2879,   327,   221,   330,  1889, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879,  1473,  1321,  1114, -2879,  1002,  -181,
     928,   328, -2879, -2879,   328, -2879,  1298,  1276,  1305,  1466,
   -2879,  1468,   120, -2879, -2879, -2879,  7921,  2066,  2066,    44,
    8851, -2879,    44,    44,    44,    44,  1429,  8851,  1404,  1597,
    8851,  8134,  1470, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    1279,    44,  1885,  8851,  5035,  8134,  1429,  8851, -2879,  8134,
    1888,    28, -2879, -2879, -2879,  8851, -2879,  8851,  8851,  8851,
    8851,  8851,  8851,  8851,  8851,  8851,  8851,  8851,  8851,  8851,
    8851,  8851,  8851,  8851,  8851,  8851,  8851, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  8851,  8851, -2879,
   -2879,  1482,  8851, -2879,  8851,  1485, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,   328,
     679, -2879, -2879,  1904, -2879, -2879,  1308,  1489, -2879, -2879,
   -2879,  1002,  1263, -2879,  1263,  1180,   116,  8851,  8851,  8851,
    1497, -2879, -2879,   679,   679, -2879,  1312,  1180,    44,  1252,
     328,   267,    88,    43,   679, -2879,  1306,  8851,  1587, -2879,
   -2879,  1384, -2879, -2879,  1935, -2879,    90,   190, -2879, -2879,
    1925,  1929, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    2289, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    1861, -2879,  1187,  8851,   -56,    44,  1918,  1939, -2879, -2879,
   -2879, -2879, -2879,   134, -2879, -2879, -2879, -2879,  1798, -2879,
    1736, -2879, -2879, -2879,  8851,    66, -2879, -2879,   328,  1936,
      44,    44, -2879,  1386, -2879,    44,  1360,   679, -2879,   328,
     328,  8851,     2, -2879,  1398, -2879,   365, -2879,  1498, -2879,
    1500,  8851,   990, -2879, -2879,  1364, -2879,  1975, -2879,  1438,
   -2879,   679, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  5290, -2879, -2879,
   -2879, -2879,   328,    44,    44,   272,   334,  1836,  1160,   679,
     190, -2879,  1440, -2879, -2879,  1935,  1963,  1590, -2879, -2879,
   -2879, -2879, -2879,  1671,  1671, -2879,   471,  1446, -2879,   328,
   -2879, -2879,  1355,  1355, -2879, -2879, -2879,   328, -2879,   328,
      23,  1355, -2879,   602, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1202, -2879, -2879,
   -2879, -2879, -2879,   235,   235,   296,   862, -2879,   580, -2879,
     488, -2879,  1810,  1970, -2879, -2879,  1970, -2879, -2879, -2879,
   -2879,  1810, -2879, -2879,  1355, -2879,   744, -2879,  1565, -2879,
   -2879,   744, -2879, -2879, -2879,  1569,  1570,   322,  1572,  1573,
    2470, -2879, -2879, -2879, -2879, -2879, -2879, -2879,   328, -2879,
   -2879,   322,  1351, -2879,   353, -2879,  1614,   253,  1389, -2879,
    1180,  1436, -2879, -2879,  1558, -2879, -2879, -2879,  1471, -2879,
     328,   328,   328, -2879, -2879, -2879,   351,  8134,  1632,  1633,
     394,   407,    23,  1634,  6915,  1636,   -46,  1284, -2879, -2879,
      87,  1637, -2879, -2879, -2879,  7253,  2002,  1449,   420,  1649,
    7303, -2879,  1650,  4542,  1653, -2879,  8851,  8851,  8851,  7414,
    8851,  7440,  7470,  7576,  3609,  4230,  7921,  8175,  8915,  9097,
    9215,  9300,  9104,  9407,  9488,  2066,  2066,  1091,  1091,  2856,
    8134,  7641,  7972,  1429,  8134,  8108,  1429,  8851,  1618, -2879,
    8230,   328, -2879,  1431, -2879, -2879, -2879, -2879,  1426, -2879,
    2049,  2050, -2879,  2051,  1478,  8851, -2879, -2879,  1437,  2055,
   -2879,  1577,  1435,  1870, -2879,  1673,   249, -2879,  1640, -2879,
   -2879,  1442,   987,   328, -2879, -2879,  1641,   283,   882,  8851,
   -2879,   328,   328,  8851,    54,   -74,  2069,  2067,  2053,  2054,
    1042, -2879, -2879, -2879, -2879, -2879,   679,  1540, -2879, -2879,
   -2879,  2016,  8851,   458,   976, -2879, -2879,  1763,  2078,  2085,
     424, -2879,   438,   328,  1701,  1180, -2879,  8851,  1661,  1663,
   -2879, -2879,  1735, -2879,  8851,   162, -2879,  1502, -2879, -2879,
     557, -2879,  8851, -2879, -2879,  1475,   787, -2879,  1053,   328,
    2089,  7849, -2879, -2879,  1002,   679, -2879, -2879,    72, -2879,
    1870,  1870,  1444, -2879,  1554,  1559, -2879, -2879, -2879, -2879,
      44,    44, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1213,
   -2879, -2879, -2879, -2879,    44,  2448,  2103,  2084, -2879,  1180,
     720,   168,   149,  2010,    35,   803, -2879,    36, -2879, -2879,
   -2879,  1680,   154,  1355,   689, -2879,  1492,  1488, -2879, -2879,
   -2879, -2879, -2879,   671, -2879, -2879, -2879, -2879,  1682,  1499,
    2118, -2879,  1519, -2879, -2879, -2879, -2879,   679,   132, -2879,
   -2879, -2879,  1486,   862, -2879,   328,   328, -2879, -2879,   328,
     380, -2879, -2879, -2879, -2879,  1699,  1702, -2879,  1675, -2879,
    1677, -2879,  1709,   440, -2879,  4666,   441,   133,   133,   443,
   -2879,   133,  4666, -2879, -2879,  1452,  1452, -2879,  1711, -2879,
    1715,  1719, -2879,  1720,  1722, -2879,  1724, -2879, -2879, -2879,
     111, -2879, -2879, -2879,   447, -2879, -2879,   448,   328, -2879,
   -2879,   928,  2124,  1180,   267,  8851, -2879,  2153, -2879, -2879,
   -2879, -2879,   322, -2879, -2879, -2879, -2879, -2879, -2879,  3497,
   -2879, -2879,  1449,  1449,  2140, -2879,  2147,  1583,  1542, -2879,
    1219,  1785, -2879, -2879,  1219, -2879, -2879, -2879,  1786,  1219,
    8134,  8134,  8134,  1219,  8134,  1219,  1219,  1219,  2156,  2157,
    2159,  8851,  1792,  2161,  8851,  1795, -2879,  2185, -2879,  8134,
   -2879, -2879,  1575,   322,   207, -2879,  1180,  8851,  8851,  8851,
    8382,  2188,   130, -2879, -2879,  1180, -2879,  1576,   328,   328,
   -2879, -2879,   328,   328, -2879,   884, -2879, -2879,   819, -2879,
    1579,  8851, -2879, -2879, -2879,  2186, -2879, -2879, -2879, -2879,
   -2879,   328,  1870, -2879, -2879,  1643, -2879, -2879,   450, -2879,
   -2879, -2879,   679, -2879,  4568, -2879, -2879, -2879,  1875,  2177,
   -2879,    44,  1859,  1860,  1746,  1586,  1867,  1782, -2879, -2879,
   -2879,   275,  1854, -2879, -2879, -2879, -2879,  1735, -2879, -2879,
   -2879,   222,   567, -2879, -2879, -2879,  1935,  8851,  1790, -2879,
    1758, -2879, -2879, -2879,  7895,  7895, -2879,  1104, -2879, -2879,
    1452, -2879, -2879,  9357,  1787, -2879, -2879,  1809,  1821, -2879,
    1822,  1823,  1824,  1825,   328,   -67, -2879,  2253, -2879, -2879,
   -2879, -2879, -2879,  2150, -2879,  1837, -2879, -2879,  1838,  2259,
   -2879, -2879,  1615, -2879,  2242,   -74,   328,  1244,  1244,  1244,
    1244, -2879,  2264, -2879,  2265,  1244,  1244,  1244,  1244,  2289,
   -2879, -2879,  1244,   124, -2879, -2879, -2879, -2879,  2248,  2260,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  2261,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,   451, -2879, -2879,
   -2879,  2250, -2879, -2879,  1355, -2879,    23, -2879, -2879, -2879,
   -2879, -2879, -2879,  1683,  1684,   165, -2879,    36, -2879,   133,
    1659,   283,  4666, -2879, -2879,  1852, -2879, -2879, -2879,   328,
     328,  3497,   206, -2879,  8851, -2879,  8851, -2879, -2879, -2879,
   -2879, -2879, -2879,   283,   133, -2879,  1355,   784,  1664,  1665,
    2283, -2879,  2284, -2879,   679,   328,   630,   630, -2879, -2879,
    2287, -2879,  2287,   501,   501,  2287, -2879, -2879,  2249, -2879,
   -2879,  2586,    48, -2879,  2249,  1288, -2879,    48,   133,   744,
   -2879,  4738,  1862,  3236,  1862,   205,  2286, -2879, -2879, -2879,
   -2879, -2879, -2879,   391, -2879,  1355,   688,  1902,  2295,  1681,
   -2879, -2879,   452, -2879,   322, -2879,   454,   246, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,  1676,   -84,  2278,  2278,  2279,
    2278,  2278,  2280, -2879,    97, -2879,   744,   328, -2879,   322,
   -2879, -2879,  1686,  1180,  2300,   219, -2879,   328,   456, -2879,
    8851,  1916,   144, -2879,   328, -2879,  1688, -2879,  1920, -2879,
    2285, -2879,  1726, -2879, -2879, -2879, -2879, -2879,  1691, -2879,
   -2879,  1928,  1930,  1931, -2879,  1933, -2879, -2879, -2879, -2879,
   -2879, -2879,  8134,   460, -2879, -2879,   461, -2879,  1937,  8851,
    8851,  2302,   464,  1180,  2326, -2879, -2879, -2879, -2879,  8851,
    1764,  2058,  8851, -2879, -2879, -2879, -2879,  1095,  1946,   819,
    1335,  1335,  2339,     3, -2879,  2341, -2879, -2879, -2879,  1335,
     328,  1799,  1172,  2346,   328,   -76,  8851, -2879, -2879,  1042,
   -2879,  1685,  8851, -2879,  2350,  8851, -2879,   679, -2879,   833,
     328,   679, -2879,  1964,  8851,  8851, -2879, -2879,   275,  1854,
   -2879,  2289, -2879, -2879,  1268, -2879, -2879,  1783, -2879,   267,
    8664,  1460,  1460, -2879,  1731,    23,  1967,   396,   326,  3497,
     326,   326,   326,   326,  1742,  3497,  7849,  3497,  3497,  3497,
    3497, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1002,   679,
     679,    91,   969, -2879, -2879, -2879,  1744, -2879, -2879, -2879,
   -2879,    44,  1244,    44,  1244, -2879, -2879, -2879, -2879, -2879,
   -2879,   -74, -2879,   981,   984,  2448, -2879,  1976,  1942,  3497,
    1202,   149,   149, -2879, -2879, -2879, -2879,   478, -2879,  1896,
   -2879,  2365,   133,     9, -2879,  1750, -2879,  2373,  9540,  9540,
    9540,  9540,   133,   133, -2879, -2879, -2879,  1827, -2879,   490,
   -2879,  1752, -2879,   328,   328,  1519,   679, -2879,  2287, -2879,
   -2879,   328,   501,   501, -2879, -2879,   501,  2170,  1761,  1765,
   -2879, -2879,    66,    66,    66,  2358,    66,    66,    66,    66,
      66,    66,  2363, -2879,  2367,    66, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879,  2586, -2879,   679,  1773, -2879,  1947,
    2170,  2369, -2879,  2374,  2376,  2377,  2378,  2379,  2380,  1271,
    1288, -2879,  1947, -2879,   492, -2879, -2879,  1944, -2879,   274,
     360, -2879,  4666, -2879,  4666, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879,  7895,  7895,  1968,  7895,  1982, -2879,
    7895,   547,  3497, -2879,  2381, -2879,  2111,   133,  1189,   133,
   -2879, -2879, -2879, -2879,  1669,  2391,  1669, -2879,  2415,  2415,
     493,  2028,  2415, -2879,  2029, -2879, -2879, -2879,   744, -2879,
   -2879, -2879, -2879,  1180, -2879, -2879,   322,  2154,  1935, -2879,
    3497,   143,  1898,   486, -2879,  1737,  1449,  1835,  1616, -2879,
   -2879, -2879, -2879, -2879,  8851, -2879, -2879, -2879, -2879, -2879,
    1958, -2879,   204,  1180, -2879,  2423,  1997, -2879, -2879,  2038,
   -2879, -2879, -2879,  1882, -2879, -2879,   328,  1335,   267,  1203,
     328,  1335, -2879, -2879,    44, -2879, -2879,  8851, -2879, -2879,
   -2879,    44,  1935,   679,  2195, -2879,  2411,  1554,  8134,  2416,
   -2879, -2879,   190,  2012, -2879, -2879,  8851, -2879, -2879,  2056,
   -2879, -2879, -2879,   567, -2879,  1554, -2879,  8851, -2879,   232,
   -2879,  1819, -2879,  1669,  3497, -2879,   417,  2060,  2437, -2879,
   -2879, -2879,  3497, -2879,   496,  3497,  3497,  3497,  3497,   328,
     498, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,  2005,  2099, -2879,  2431, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879,   328, -2879,   113, -2879,
   -2879, -2879,  1202,   133, -2879,    23,  2315,   500, -2879, -2879,
   -2879, -2879,   328,  1901,  8861,  8861, -2879, -2879,  9600,  2025,
   -2879, -2879,  2027,  2030, -2879,  2031,  2032,  2033,  2034,   328,
     -16, -2879, -2879,   505, -2879, -2879,  2691, -2879, -2879, -2879,
     506,  2455,  2455, -2879, -2879,   511,  2456,  2454, -2879,   174,
   -2879, -2879,   133, -2879,   148,  1848, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879,  2262,  4715, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    -138,  2465, -2879,   679,  1166, -2879,  2262, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    2286, -2879,  2035,  2150,  2035,   155, -2879,  2035,   155, -2879,
    2035,  7895, -2879, -2879,  3497, -2879,   237, -2879, -2879, -2879,
    2011, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    2079, -2879,  2449,  2083,  2087,  2451, -2879, -2879,  2088, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879,   289,  2477, -2879, -2879,
     328,  2114,   328,  1864,   326,  2155, -2879,  2062, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879,  1652, -2879, -2879, -2879,
    8134,  2104,    44,   -74,  2125,  1180, -2879,  8851, -2879,  1932,
    2473,   -74, -2879, -2879,   453, -2879, -2879, -2879, -2879,   137,
    2108,  1870,  2259,  2263, -2879,   -74,  2112,  2116,  2069,  2075,
   -2879,  2166,  2119, -2879, -2879, -2879, -2879,  2271,  2057, -2879,
     144,  1452,  1887, -2879,  1452,  2122,  3497, -2879,  2126,  2128,
    2130,  2132, -2879, -2879,  8851,  2090, -2879, -2879, -2879,  1554,
   -2879,   513, -2879,   679,  1978,  1202,  1202, -2879, -2879,  3497,
   -2879, -2879,   133, -2879,  2097, -2879,  1978,  1483,  1483,  2137,
     396,   326,  9659,   326,   326,   326,   326,  1914,  9659,  9540,
   -2879,  9659,  9659,  9659,  9659, -2879, -2879,   133,  2523,   133,
    9540,   283,  4666, -2879,   679, -2879, -2879,   762, -2879, -2879,
     328, -2879, -2879, -2879, -2879, -2879, -2879, -2879,   679,  2465,
   -2879, -2879, -2879,   679, -2879,   679, -2879, -2879,  1479, -2879,
    2299, -2879,  2303,    97, -2879, -2879,   514, -2879, -2879, -2879,
   -2879,   515, -2879,  2035,  2537,  2519, -2879, -2879,  1919, -2879,
   -2879, -2879, -2879,  2158, -2879,   143, -2879,   143, -2879, -2879,
    3497, -2879,  2100, -2879,  2154,   203,   168,   328,  2522, -2879,
   -2879, -2879, -2879, -2879,  1180, -2879,  2173,  4413,  2120, -2879,
   -2879, -2879,  1934,   -74, -2879, -2879, -2879, -2879, -2879, -2879,
    2160,   190, -2879,  2166,  2166,   567, -2879,   267,  2171,  1923,
    1669,  1941, -2879, -2879, -2879, -2879, -2879, -2879,  1992, -2879,
   -2879,   328, -2879,  2259,   486, -2879, -2879,   144, -2879,  9511,
     486, -2879,  2184,  9659, -2879,   519,  9659,  9659,  9659,  9659,
     328,   521, -2879, -2879, -2879, -2879, -2879, -2879,  2148, -2879,
   -2879, -2879,  2365,  2259,   148, -2879, -2879, -2879, -2879,  1501,
    1501, -2879,  1501, -2879,  1501,  1501, -2879, -2879, -2879, -2879,
   -2879, -2879,   173, -2879, -2879, -2879,  3497,  2151,  1669, -2879,
   -2879,   522, -2879,  2576, -2879, -2879,  4666, -2879, -2879, -2879,
   -2879,  2577, -2879,   398, -2879, -2879,  2154,  2190,  1061, -2879,
   -2879,   118,   118,   118,   118,   118,   118, -2879,  2560, -2879,
     523, -2879,  8851,  1242, -2879,    62,  2166,  8851,  2166,  2069,
   -2879, -2879, -2879,  2344,   241, -2879,  1669, -2879,  1669, -2879,
     -74, -2879, -2879, -2879, -2879,   532, -2879, -2879, -2879, -2879,
    2194,  9659, -2879,  2196,  2198,  2199,  2200, -2879, -2879,  9540,
   -2879, -2879, -2879,  1501, -2879,  1501, -2879, -2879, -2879, -2879,
   -2879, -2879,   143, -2879,  3497,  2365,   203, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,   881, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,  4413, -2879,  2583, -2879, -2879,
   -2879, -2879,    39, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,    72, -2879,  9511, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,   534, -2879, -2879, -2879, -2879, -2879,  1063,  1063, -2879,
   -2879,  1063, -2879,  8851,   599, -2879, -2879,  2202,    91, -2879,
   -2879, -2879, -2879, -2879,  2203, -2879, -2879, -2879, -2879,   139,
   -2879,   190, -2879,  2069
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2879, -2879, -2879, -2879, -2879,    59, -2879,   156,  -176, -2879,
   -2879,  -867,    98, -2879, -2879, -1896, -2879, -2879, -2879, -2879,
    -851, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2070, -2879, -1873, -2879,
     119, -2879, -2879, -2879, -2879, -2879, -2879, -2879,   400, -2879,
   -2879, -2879, -2879,  1327, -2879,   695, -2879, -2879,   -35, -2879,
   -2879,  2573, -2879,  2572,  2241, -2879, -2879, -2879, -2879, -2879,
     465,    96, -2879,   462, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,  -129,   479,   292, -2879, -2879,
    2328,    -9, -2879,  2476, -2879, -2879,  2474, -2879,  2412, -2879,
   -2879, -2879, -2879, -2879,  2338,  2220,   920,  2336,  -317, -2879,
   -2879, -2879, -2879, -2879,   922,  -405, -2879, -2879, -2879, -2879,
   -2879, -2879,  -149,  2272,  2418,  -206,   526, -2879,  2266,  -146,
   -2879,  2318, -2879, -2879, -2879, -2879,  2325, -2879, -2879, -2879,
   -2879,  -330, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    2268, -2879,  2269, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -1017, -2879, -2879,  -791, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,   224, -2879, -2879,   826, -2879,
    -833,  -875,  -418, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,   542, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    -447, -2879, -2879, -2879, -2879, -2879,  2133, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2034, -2879, -2879, -2879, -2879,
   -2879, -2879,   890, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,  1687, -2879, -2879, -2879, -2879,   659, -2879, -2879, -2879,
   -2879, -2879, -1711, -2879, -2879,   651, -2879, -2879, -2879, -2879,
   -2879, -2879,  -814,  -545,   535,   800, -2879,  -504,   758,  -843,
    1549, -2879,  1062, -2879, -2164,    -4,  -203, -2879, -2879, -2086,
     538,  1013, -2879, -2879,   883,  1044, -2879, -2879, -2879, -2879,
   -2879, -2879,    85, -2879,  -214, -2879,  1045, -2879,   737, -2879,
     421, -2879, -2879, -2879, -2879,  -817, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879,   539, -2879, -1592, -2879,   725, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879,  1503, -2879, -2879, -2879, -2879, -2879,
   -2879,  -414, -2879, -2879, -1838, -2879, -2879, -2879, -2879,   722,
   -1979, -2879,  -845, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  2663, -2879, -2879,
   -2879,  2569,  2660, -1829, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,  -304, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
    2662, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,   777, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,  -430,  2204, -2879, -2879, -2879, -2879, -2879,  2036,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  2163, -2879,
   -2879,   -58, -2879, -2879,   772, -2879, -2879, -2879,  -704,  -195,
    2432, -2879, -2879, -2879, -2879,   569, -2879,  -733,  2004,  1065,
   -2542,   112, -2879,   778,  1767,  -278,  -481, -2879, -2879, -2879,
    1548, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879,  1494, -2879,  -503, -2879,  -368, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879,  -734, -2879, -2879, -2879, -2879, -2879, -2879,
     159, -2879,  1582,   781, -2879, -2879, -2879, -2879, -2879,    25,
   -2879,  -469, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,  1843, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,  -341, -2879,  1490,  1657, -2879,
   -2879,    31, -2879,  -446, -2879, -2879,    55,   355, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879,  -463, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2878, -2879,  1707,   619, -1004, -2879, -2879, -2879,  1009,
   -2879, -1681, -2879, -2879, -2879, -1682, -2879, -2879, -1666, -2879,
   -2879, -2879, -2879,  1034, -2879, -2879, -2879, -2879, -2879, -2879,
     432, -2879, -2879, -2879, -2879, -2879, -2879,  -715, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879,  -676, -2879, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879,   404, -2879, -2879,
   -2879,  -562, -2879, -2879, -2879, -2879, -2879, -2879,    18, -2879,
   -2879,   377, -2879,   726, -2879, -2879, -2879, -2879, -2879, -2879,
    -995, -2879, -2879, -2879, -2879, -1632, -2879, -2879, -2879, -2879,
   -2879, -2879, -2626,  -290, -2879, -2128,    -8, -2879, -2879, -2011,
      51,    56,   388, -2879, -2088, -1781, -2879, -2879,  -236,  -559,
   -2879, -2879, -2879, -2879, -2242, -2879, -2879, -2879, -1600, -2879,
   -2879, -1014, -2879,  -729,  1132,  -238, -1939,   390, -2879,   196,
   -2879, -2879, -2879, -2879,  -723, -2879, -2005, -2623,  2776, -2879,
   -2879, -2879, -2879, -2879, -2879, -2430, -2879,   141, -2879, -1664,
   -2879,  1813, -2879, -2879, -1040,  -448, -2879, -2314,  -445,  -124,
     167, -1500, -1733, -2293,    21,  -631,   517, -2141, -2879,   229,
   -2879, -2879, -2879,  1152,  -531, -2879, -2879,  -484,  1828, -2879,
     895, -2879, -2879, -1605,  -113, -2879, -2879, -2879, -2555,  -349,
   -2879, -2879, -2879,  1186, -2879, -2879, -2879, -2879, -2879, -2879,
   -2879, -2879, -2879, -2879, -2475,  -362, -2879, -2590, -2137, -2221,
   -1365, -2879, -2879,  -350,  -441,  -416,  -406,   748, -1772,     7,
    1961,   103, -2879, -2879, -2879, -2879, -2879,  1642, -2879,  -490,
   -2879, -2879, -2879, -2879, -2879, -2879, -2879, -2879,  -255,  1296,
    2452, -2879, -2879, -2879, -2879
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2146
static const short yytable[] =
{
      43,   271,   901,  1052,  1049,   394,   845,    34,   287,    58,
      60,   741,   697,    60,   261,  1037,  1198,   802,   722,  1253,
    1742,  1244,  1720,  1196,  2157,  1226,   133,   239,   895,   259,
     426,  2417,    34,   115,  2198,  1765,  1080,   891,    72,  2089,
     781,  2426,    76,    79,  1944,  1945,  1792,  2553,  2637,  2950,
    2951,  2952,  1205,  1206,    99,  1207,  2065,  1228,  1229,  2457,
    2066,  2040,   827,   813,  1987,   943,  1245,  2516,   946,  2308,
      42,    42,   855,   856,   130,   129,   854,    79,   294,   686,
    1157,    42,   894,  2561,  2562,   115,  1264,  1245,   142,   139,
     272,   345,   737,   748,    42,  1869,   146,  1174,  2410,  2413,
     151,   722,  2413,   153,   154,   937,  2096,   887,  1857,   157,
     158,   306,   307,  2097,  1635,    42,   902,   908,  2780,  2611,
     924,   272,  2765,  2228,   928,  1640,   272,   129,  1146,  1245,
     934,  1645,   936,  3041,    99, -2144,  2324,  2364,   203,  1243,
    1658,   820,  1245,    42,  1199,    42,  1162,  1163,   235,  2780,
    2503,   238,   402,   858,  2889,  1047,   242,    42,  1047,  1870,
      42,  1871,  2257,  1872,  1246,  1247,   278,  2954,  1047,   269,
      42,   272,   279,   280,   710,    42,    42,   710,   710,   272,
    2227,  2228,    42,  2696,   131,   272,   949,   950,    42,   387,
    2909,   710,    42,   899,   276,    42,   269,   272,  2227,  2228,
      42,   962,   269,  2504,   272,   273,   274,    42,   689,  3084,
     710,  2722,  1300,   710,   272,   949,   950,    42,  1636,   710,
     295,    42,   269,   710,   269,  2564,   708,   710,  1047,  3360,
      42,   710,   899,   303,    42,   710,   710,   269,   710,   309,
    3119,   710,  3225,   710,   710,   710,   269,  2552,    42,    42,
     337,   710,  2722,   961,   710,  2638,  2639,  2640,  2641,  2642,
     389,   710,   803,   397,   407,   803,   710,   262,   263,   264,
     265,   266,  1662,   710,   351,   812,   353,  1869,   409,   803,
    2722,    99,   391,   803,   710,   187,   188,   413,   710,  1886,
     829,  3102,   710,   189,    42,   803,    42,   812,   710,    45,
    2609,   710,  3510,   840,  2331,  2372,   812,    84,  2375,    84,
      42,    65,  1036,   851,  1047,  2830,    42,  2157,   857,  2433,
    1044,  2631,  3495,    42,  3181,   893,  2908, -2144,  2875,  2876,
    2877,  2878,  1235,  1236,   400,  1953,   840,   572,   665,  1640,
     840,    67,  1911,  1707,   840,  2328,   718,  2093,  2755,    42,
     812,   400,    84,   812,    42,    42,  1245,    42,  1953,    84,
     418,  1187,   143,   418,   718,  2575,  3359,  1241,  1181,  2725,
    2726,   418,  2727,  2728,  2729,  2730,  2731,  2732,    65,   657,
     667,    84,  2719,  1988,  1154,  1276,  1891,   337,  1917,   337,
    2628,  3175,  1042,   136,  1301,   962,    36,  1750,    84,  1245,
    2725,  2726,  3195,  2727,  2728,  2729,  2730,  2731,  2732,   962,
    1017,  1018,  1245,    84,  1664,  2650,  3168,   757,   418,   842,
    1242,   717,  3121,    42,   706,  1245,   711,   712,   138,  2191,
     719,   724,  1188,   726,   674,    42,   729,  1751,  1019,  1020,
    1021,  1043,   761,  1245,   136,  2389,  2389,   712,  2414,  2410,
      73,  3196,  2437,  2439,   795,  2529,  2615,  2749,    84,  2749,
      84,  2776,   962,  2818,  1876,  2794,  2794,   712,   675,  2776,
    1957,   262,   263,   264,   265,   266,   887,   795,    46,    19,
     712,  2915,  3147,  2913,  3511,  1641,   902,    84,  3440,  2919,
     830,  1267,    47,  1957,  2230,  2962,   965,  2747,  3045,   707,
    1989,  3126,  2206,  3126,    19,  3152,   846,   848,   310,  2231,
    3169,  3169,  2434,   719, -2144,   707,  3177,    48,  3291,  3342,
    3342,   795,   846,   846,  3411,   770,  3411,  3432,  3455,  1182,
     795,   795,   963,   920,   795,   311,    79,  3473,   795,  3169,
      35,  1887,  1673,  2756,   795,  2094,   795,   951,   938,  2667,
     938,   846,  2230,   938,   846,  2700,   938,  3021,  1768,  1769,
    1259,   392,  1262,  2697,  2171,    49,  2521,  2231,  1725,  1766,
    2230,  3120,  2852,  1725,  1770,  1771,  1725,   388,   964,  3085,
    1917,  1726,  1281,  2619,  2831,  2231,  1726,   718,  1927,  1726,
   -2144,  1788,   270,  3013,  3013,  1302,  3013,  1749,  2723,  3013,
    1918,  3293,  3175,  3175,   710,  1709,   843,  1972,  1973,  3350,
    1990,  3352,  3186,  2733,  1657, -2144, -2144,  2799,   775,   348,
    1200,  1670,   722,  1248,  2819,   688,  1721,  2565,  1303,  1748,
     777,   778,  2325,   707,  1838,  2890, -2144,  1670,   779,  2753,
    2316,   411,  3323,   926,  2733,  1003,  1852,  2774,   390,   952,
    1175,   398,   408,  1738,  2658,  1184,   893,  3397,    78,  3056,
    3118,  2625,  2840,   964,   990,  3226,   410,  3009,  3143,  3468,
    1704,  2848,  2849,  3105,  1201,   414,  2264,  2147,  2098,   845,
    2365,  2332,  2007,  1005,  1705,  1164,  2869,   275,  1853,  3090,
     965,  3115,  2781,  2918,  1012,  2626,   418,  1884,    42,   190,
    1265,  3182,  3317,   821,   965,  2376,    42,  3159,  1045,  1873,
    1249,   844,   844,   970,   719,  3295,  3296,  1874,   275,  2904,
    1833,  3235,   844,   275,  1251,  3431,   710,   710,   710,  1048,
    3092,  1708,  2734,  2735,  3097,  2636,  1839,  1742,   795,   795,
     795,  1888,  1914,  2405,  2084,   722,  2405,    42,  2751,  1840,
    1841,  1842,  3075,  2865,   795,  2770,  1858,   965,  2771,  1727,
     795,   795,  1741,  2734,  2735,   795,  1901,  3324,   275,  1864,
    1994,  1904,    81,  3469,  2264,  3470,   275,    97,  1655,   857,
     893,  1902,   275,  2122,  2418,  2493,  2125,  2087,  1202,  1167,
    2736,  2643,  1918,  2866,   275,  2868,  1168,  3022,   795,  1728,
    2088,   275, -2144,  2870,  1728,  1048,  3484,  1728,  3028,  1022,
    3031,   275,   184,  2103,    42,  1729,  2405,  2192,  3062,  1896,
    1729,  2736,  3246,  1729,  2520,  1885, -2144,   668,   703,  3481,
      42,  2193,  2864,  2390,  2404,   134,  2415,   966,   967,   968,
    2438,  2440,  1922,  2530,  2616,  2750,   902,  2752,   969,  2777,
     669,   795,   795,  2795,  2796, -2144,  3297,  2801,  2173,   730,
      42,  3122,  2015,  1910,  2336,   132,  2949,  2949,  2949,  2949,
      84,  2914,  2419,  1925,   141, -2144, -2144, -2144, -2144, -2144,
    3013,  3262, -2144,  2963,  1710,  3008,  3046,  1712,  2420,  3127,
     795,  3133,  2718,  3153,  2721, -2144,  1023,   143,  3170,  3176,
     795,   147,  1713,  3325,  3178,   795,  3292,  3343,  3344,  1974,
    1274,    84,  3412,  2871,  3418,  3433,  3456,  2813,  2737,  3303,
    2213,  3306,  3307,  3308,  3309,  3474,  3215,  3500,  1292,  3220,
   -2144,  2421,  3222,  1981,  1982,  3023,   423,  3024,  3437,  1024,
     668,  3304,  1992,   795,   672,  -272,   197,  3304,  1753,  2737,
    3313,  3314,  3315,  3316,  3014,    42,  3017,  2910,  2911,  3020,
     795,  2337,   992,   669,    35,    36,  1056,  1057,  1058,  2314,
    1641,  2422,  1232,  3110,  3148,  3290,  1747,   145,    84,  1239,
    3402,   200,  1071, -2144,  2738,  2032,  3408,  3438,  1084,  1085,
     196,   701,  3278,  1089,    84,   262,   263,   264,   265,   266,
    2423,  3063,  2186,    42,   236,  1856,  2016,  2900,    42,  2424,
    2902,    42,  3064,  2343,  1722,  2738,  3294,   237,  1730,  1739,
    1730,   707,  2344,  3185,    84,  2017,  2018,   717,  3300,    42,
   -2144,   719,  3312,  -272,   719,  2179,  1754,  1757,  2739,  2740,
     726,  1714,  1995,  3320,  1148,  2019,   244,  2345,  2150,  -272,
    2346,  2151,   852,  1996,    42,   846,   795,   252,   846,   846,
     846,   846,  2015,   795,  2102,   253,   795,  1208,  2347,  2739,
    2740,   135,   136,  2219,  1997,   255,  2517,   846,  2449,   795,
      42,  1998,  3410,   795,   256,  3413,  3414,  3415,  3416,  2216,
     257,   795,  -272,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,   795,   795,   795,   795,   795,   795,   795,
     795,   795,   795,  1115, -2144,  2810,  3279,   260,  1715,  3281,
    3489,   291,    42,   795,   795,   268,  1116, -2144,   795,  2449,
     795,   979,  -272,  1713,  1149,  3345, -2144, -2144,  2942,  2942,
    2942,  2942,   980,  1940,  1941,  1828, -2144, -2144,  2744,   288,
    2351,  2150,  2949,  2949,  2151,  2152,  2949,   719,  2153,  3044,
     289,  -272,  3048,   795,   795,   795, -2144,    84,   292,  3403,
    -272,  3322,    84,  2348,   846,    84,  1855,  1953,  1859,   846,
    1953,   293,  3149,   795,  1117,  1118,  1119,  1120,  1121,  1122,
    3476,   301,  2825,   718,  1946,   981,  1947,  1948,  1949,    42,
    1123,  1124,  1125,  3390,  3391,   899,  2016,    42,   302,  3029,
     982,   277,    83,  3298,    42,   282,    42,   304,   718,  2072,
    1209,  1717,   308,  3095,  1995,  2017,  2018,  2349,  3200,  3442,
      42,   313,   735,  3443,  2350,  1996,  3016,  1718,  3019,   795,
    3223,   846,    59,  3219,    42,  2019,  3219,  1946,   322,  1947,
    1948,  1949,   807,  1285,  2335,    42,  1997,  1651,  2152,    42,
     795,  2153,  3458,  1998,  1898,   816,   846,   846,     1,    42,
   -2144,   846,  1714, -2144, -2144,  1908,  1909,   795, -2144,  1762,
   -2144, -2144, -2144,  1953,  1767,     2,     3,   795,  1834,   343,
      42,  1774,   331,  2854,  1785,    42,  3004,   925,    42,   983,
    3201,   929, -2144,  1777,   332,   933,  3364,  1790,  1778, -1530,
    1780,  1793,  1957,   338,     4,  1957,  3464,  2083,  3466,  1799,
     341,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1126,   985,   986,  1127,  3435,   717,  1210,    42,  1715,
     342,  1821,  1822,  1211,  1212,  1213,  1824,  1953,  1825, -2144,
     347,     5,     6,   805,     7,     8,  3202,   349,  3203,     9,
     344,    84,   350,  1214,  2197,   354,  2121,   814,    84,  2124,
    1047,   819,    42,  3204,  2172,   355,    10,    11,  2868,   358,
    2949,  3205,   359,   833,  2715,  3206,  2949,  2949,  2595,  2949,
    2949,  2949,  2949,   360,    12,  1278,   362,  1716,  2949,  3442,
     365, -2144,  1154,  3443,  2759, -2144,  2761,  2762,  1957,    84,
    3207,   135,   136,    84,  2942,  2942,   366,  2141,  2942,  1775,
    1776,  1950,   135,   136,  1951,  1742,  1952,   942,  2313, -2144,
     945,  2769,   376,   948,    42,   377,  2271,  2273,  2701,  1926,
     136,  2166,  1717,   380,    84,  1842,  1953,   385,  1272,    84,
      42,   395,    84,  1128,  2702,  2703,  1954,   396,  1718,   738,
     738,   399,  2326,  2704,  2283,    13,   296,   297,   298,  1129,
    2579,  2580,  1215,  1130,  1950,  1216,   403,  1951,  2630,  1952,
    2002,  2003,  1957,  1217, -2144,  1279,  2205,  3364,  1745, -2144,
      42,   404, -2144,  3173,  3174,  2010,  2011,  2705,  1955,  1953,
    2648,  1980,  1956,   405,  3465, -2144,  2706,  1984, -2144,  1954,
   -2144,  1131,   910,  1254,  1255,  1256,  1257, -2144,  1218,   406,
    3447,  2949,  2163,  2164,  2949,  2949,  2949,  2949,  2280,   412,
   -2144,  1037,  2444,   415,  2358,  2707,    42,  3460,   417,  1132,
   -2144,   673,  2185,  2581,  2582,  2583,  2584,  2585,  2586,  3157,
    3158,  1955,   835,  1219,   738,  1956,  2461,  1133,  2462, -2144,
    3219,   841,   911,  2023,   953,   690,  2581,  2582,  2583,  2584,
    2585,  2586,  2029,  1220,  1221,  2618,  1053,  1054,  1055,   424,
    2708,  1957, -2144,   678,  1222,    14, -2144,  1233,  1234,  1223,
     680,  1237,  1238,  2494,   681,  2495, -2144,  3447,    84, -2144,
     912,   682,   710,  3201,  2506,   941,  1777,  2778,   944,   966,
     967,  1778,  1779,  1780,  3460,   687,   692,  2651,   938,   846,
     846, -2144,  2709,   693,   694, -2144,  2450,  2465,  1224,  2949,
    3077,  2467,  3078,   696,  1957,    15,  2470,  2949,   699,  1134,
    2474,   698,  2476,  2477,  2478,  1976,   700,  2446,  1048,  1048,
     702,   930,  2942,  1985,  2162,  1985,   994,  1048,  2942,  2942,
    1225,  2942,  2942,  2942,  2942, -2144,  3249,    16,  3250,  3202,
    2942,  3203,   995,   996,  2835,  2861,   997,  2536,   262,   263,
     264,   265,   266,  2832,   998,   999,  3204,   314,  1005,  1000,
    1835, -2144,  1835, -2144,  3205,  1001,    17,   913,  3206,  1002,
    1048,  1004,  1008,  1009,  1010,  1135,  1011,   710, -2144,  2496,
    2497,  1842,  2500,  1730,  1015,  1035, -2144,  2526,  1038,   323,
   -2144,  1034,   136,  3207,  1739,  1040,  1041,  1730,   710,  1046,
    1050, -2144,     1,  2523,  2899,  1059,  1060,  1062,  1150,   953,
    1063,  1161,  1165,     1,  1064, -2144,  2079,  2080,  2081,     2,
       3,  1065,  1166,  1169,  1066,  1067, -2144,  1170,  1068,   857,
       2,     3,  3052,  3050,  1069,   755,  2560,  1070,  1172,   104,
    1081,  1178,  1082,   914,   105,   315,  1083,   756,  1086,  1087,
     893,  1173,   795,   795,   795,  1147,   795,  1090,  1177,  2557,
    1092,   316,  1093,  2942,  1094,  1095,  2942,  2942,  2942,  2942,
    1096,  1183,  1097,  1098,  1099,  1180,  1072,   324,  1192,  2418,
    1197,  1230,  1240,   795,  1243,   915,   795,  2132,  1260,   106,
     107,  1268,  1269,   325,  1270,     5,     6,   108,     7,     8,
    1277,   795,  1271,     9,   317,  1275,     5,     6,  1280,     7,
       8,    83,  1289,    42,     9,  1281,  1291,     2,     3,  2160,
      10,    11,  1631,  1632,  1633,   795,  1634,  2167,  2168,   795,
     846,    10,    11,     2,     3,  1245,   326,  1639,    12,  2445,
    1643,  1647,  1646,  1648,   318,  1695,  1649,  1703,   795,    12,
    1706,  1724,   916,  2463,  1744,  1760,  1762,  1761,  1763,  2195,
    1764,  1772,  1786,   795,  1073,  1789,  1787,  2419,  1794,  1830,
     795,  2942,  2772,   319,  1823,  1251,   327,  1826,   795,  2942,
    1074,  1832,   320,  2420,  2220,  1292,  2645,  2245,  2646,  1845,
     719,   772,  1863,     5,     6,  1831,     7,     8,  1865,  1851,
    1869,     9,  1867,  1878,  1889,   328,   846,   846,  1879,     5,
       6,  1892,     7,     8,   329,  1894,   917,     9,    10,    11,
     846,  1899,  2802,  1075,   953,  1890,  2421,    51,    52,    53,
      54,    55,    56,    57,    10,    11,    12,  1903,  1914,  1048,
    1929,  1921,   716,  1923,  1905,  1928,  1931,  1641,  1964,  1966,
     860,  1967,    12,  1969,  1975,   734,  2024,  2035,  2359,   861,
     774,  2037,  2038,  1076,  2041,  2042,  2422,  2070,   862,   776,
    2071,  2371,  2371,   863,  2073,  2371,  2068,    84,  2074,  2075,
    2110,  2111,  2112,   808,  2114,  2085,  2086,  2090,  2101,  2092,
    2099,  2245,  1077,  2406,  2406,  2423,  3032,  2406,  2245,   825,
     826,  1078,  2104,  2106,  2424,   832,  2109,    13,   834,  2134,
    2130,  2129,  3060,  2136,  2137,  2138,  2139,   864,  2142,  2140,
    2143,  2144,  2145,    13,  2441,   865,  2146,  1754,  2149,    14,
     710,   795,  2148,  2161,  1640,  2174,   710,  2181,  1730,  2176,
    2177,  2804,  2183,  2189,  2809,  2245,  1113,  1114,  1115, -2144,
    2190,   109,  1659,  2199,  2196,  2200,  2203,  2895,   710,  2897,
    2209,  1116,  2217,  2223,  3067,   969,  2264,  2266,  2311,  3108,
    2312,  2323,  2329,  2339,  2354,  2340,  2184,   795,   110,    15,
     795,   866,   857,  2357,  3033,  2356,  2368,  2379,   893,  1730,
    2380,  2129,  2443,   795,   795,   795,   795,  2381,  2406,  2385,
    3034,  2388,   887,  2427,  2508,  2160,   867,  2428,  2513,  2513,
     893,  2429,  2430,   868,  2431,   869,  2432,   795,  2447,  1117,
    1118,  1119,  1120,  1121,  1122,   870,  2458,  2525,  2577,  2578,
    2579,  2580,  2886,  2459,  2460,  1123,  1124,  1125,  2466,  2469,
      17,  2479,  2480,  3035,  2481,  2484,  2485,   846,  2487,   111,
    2489,   871,  3068,  2502,  2524,  1660,  2491,  2507,  2527,   872,
    2522,  2533,  2534,  1661,  2537,  2538,  2539,  2540,  3069,  1662,
     953,  1663,  2541,   795,  2542, -2144,  3253,  2558,  2559,  2567,
    2245,  2245,  1664,  3036,  3261,    91,  2976,  2977,  2978,  2245,
    2980,  2981,  2982,  2983,  2984,  2985,  1037,   873,  3266,  2988,
    2574,  2568,  3051,  2581,  2582,  2583,  2584,  2585,  2586,    16,
    1665,  3070,  3037,  2569,  2570,  2571,  2572,  2573,  2576,  2588,
    2589,  3038,  2596,   874,  2590,    16,  1666,   968,  2594,  2601,
    2603,  1667,  3086,  2612,  2613,  2614,  2617,  2629,   738,     1,
    2621,  2622,   112,  1668,  2632,  2653,  2654,  1701,  2655,  2656,
    1669,  3071,  2661,  2724,  2717,  2746,     2,     3,   185,   193,
    2747,   875,  2748,  2754,  2757,  2760,  2763, -2089,  2773,  2779,
    1048,  2787,   876,  2786,  1208,  2785,  1126,  2788,  2789,  1127,
    3072,  2790,  2800,  2791,  2792,  2406,  2793,  3060,  2245,  3073,
    2797,  2803,  2805,  2806,  3099,  2634,  1985,  2245,  3321,  2812,
     795,  3101,   795,   665,  2816,  2482,  2820,  2824,  2482,   665,
    2406,  2827,  1048,   193,  2836,  2839,  2857,  2847,  2863,   193,
    2865,  2371,   113,  2879,  2859,  2894,   710,   710,  2915,  2905,
     114,  2722,     5,     6,  2906,     7,     8,  2922,  2780,  2964,
       9, -2144,  2960,  2979,  2406,   667,  2974,  2245,  2986,  2245,
    2975,   667,  2987,  2993,  2997,  2994,  3384,    10,    11,  2998,
    3015,  2406,  2999,  3000,  3001,  3002,  3003,  3026,  1714,  3100,
    1730,   877,   878,   879,  3018,    12,  2565,  3040,   857,   857,
    3042,  3047,  3049,  3053,   880,  2332,  3076,  3082,  3087,  3088,
     193,  3089,   193,  1739,  3090,  1730, -2144,  3104,  1128,  3116,
    3109,  3106,  3124,  2079,   963,  1670,   795,  3136,  2252,  3113,
    2784,  3139,  1671,  3123,  1129,  3150,  3143,  3160,  1130,  3161,
    3169,  3179,  3162,  3163,  3164,  3165,  3166,  1209,  3180,  3190,
    3198,  2744,  3228,  3191,  1672,  3229,  3231,  3233,  3213,  1673,
    3232,  3234,  3237,  3240,  3245,   795,   795,  3247,  2284,  2285,
    2286,  2287,  2288,  2289,  3248,   795,  1131,  3251,   795,  3260,
    3254,  3264,  3258,  2811,  3265,  3267,  3060,  3269,  3060,  3268,
     193,  3271,  3273, -2144,  3280,  3282,  2160,  3277,  2826,  3284,
    2828,  3285,   795,  3286,  1132,  3287,  2781,   881,   795,  3299,
    3301,   795, -2144,  3472,  2043,  3310,  2844,  3318,  3389,  3337,
     795,   795,  1133,  3338,  3346,  3347,  3348,  2290,  3367,  3356,
    3396,  3349,  3382,  3388,  3255,  3383,   795,  3448,  3449,  3450,
    3451,  3452,  3453,   719,  3395,  2245,   193,  3370,  3398,  3399,
    3194,  2245,  2245,  2245,  2245,  2245,  2245,  3409,  3252,  3430,
    3419,  3434,  3436,  3441,   719,  3454,  3467,  3475,  3493,  3477,
     704,  3478,  3479,  3480,  1210,  3506,  3508,   846,  2843,   846,
    1211,  1212,  1213,  2775,  3492,   732,  2454,  2550,  2798,  1913,
    2208,    74,    75,   573,  2509,  2245,  2823,  2518,   356,   199,
    1214,   204,   352,   284,  1134,   691,  2026,   357,  2406,  2027,
    2766,   286,   416,  2468,  2940,  2940,  2940,  2940,  2406,  2406,
     810,   384,  3094,  3079,  3193,   677,   815,   382,   817,  2965,
    2966,  2359,   824,   953,  3490,   824,  2131,  2969,   824,   683,
    2670,  2671,   684,  2672,  2673,  2674,  2486,  2095,   836,  3256,
     919,  2377,  2369,  2169,  2498,  1699,  1939,  2893,  3138,  2263,
    1943,  3507,  2505,  2593,  2281,  3263,  1860,   885,    69,   159,
    1135,    70,  3211,    71,   704,   897,   900,  2215,  2218,   831,
     921,   346,  2888,  3060,  1014,  1963,   993,  2222,   931,  3171,
    3172,  3173,  3174,  2129,  2129,  3199,  3288,  3328,  2245,  1637,
    2245,  1880,  1847,  3369,   955,   958,   959,   960,  3496,  1215,
    2245,  2245,  1216,  2245,  1883,  2881,  2245,  3007,  2245,  3336,
    1217,  3006,  2713,  2406,  3030,  2406,  1837,  1263,  1795,  2989,
    2566,  1759,  2492,  2069,  1895,  2036,  2838,  2623,  3499,  2129,
    3486,  2652,  3420,  2675,  3027,  2714,  3236,  2416,  2129,  2129,
    2044,  2676,  1730,  3010,  3061,  1218,  2245,  1048,  3513,  2716,
    3011,  2291,  3221,  3428,  2581,  2582,  2583,  2584,  2585,  2586,
     795,  1979,  3227,    64,  2292,  2743,  2967,  1687,  3365,  3156,
    2921,  3055,  3366,  3485,  2880,  2677,  1971,  3401,  1654,  3155,
    1219,  3302,  2513,  1937,  2678,  3096,  2513,  3319,  3311,  2442,
     846,  1854,   425,   795,     0,     0,     0,   846,  2045,     0,
    1220,  1221,     0,     0,  2941,  2941,  2941,  2941,     0,     0,
    2046,  1222,   795,  2679,  2680,     0,  1223,     0,     0,     0,
       0,  2047,     0,   795,     0,     0,     0,     0,  2454,  2293,
    2245,     0,     0,     0,     0,     0,  2294,     0,  2245,  2048,
       0,  2245,  2245,  2245,  2245,  3132,     0,     0,     0,  2049,
       0,     0,  2050,     0,     0,  1224,     0,     0,  2681,     0,
       0,  1116,     0,     0,     0,  2051,     0,     0,     0,   955,
       0,     0,  3140,     0,     0,  2295,     0,     0,     0,  2406,
    2720,     0,     0,     0,     0,     0,     0,  1225,  2634,     0,
    2940,  2940,     0,     0,  2940,     0,   710,     0,     0,  2296,
    2682,     0,     0,     0,     0,  3167,     0,     0,     0,  2297,
    2298,     0,     0,  2052,  2246,  2299,     0,     0,     0,  1117,
    1118,  1119,  1120,  1121,  1122,  2300,     0,     0,  2406,     0,
    1976,     0,     0,     0,  3457,  1123,  1124,  1125,     0,  1155,
       0,     0,     0,  2053,     0,     0,     0,  2301,   893,     0,
    2302,  2303,     0,  2054,     0,     0,  2304,  2683,     0,  2005,
    2006,     0,     0,     0,     0,     0,  2022,     0,     0,     0,
       0,     0,     0,     0,  2055,     0,     0,  2056,     0,  2057,
       0,   719,  1186,     0,   719,     0,     0,  2245,  3080,     0,
    2245,     0,     0,     0,     0,     0,     0,     0,  1204,  1204,
    1204,     0,  1204,     0,  1204,  1204,     0,  2058,     0,     0,
      91,    91,     0,  2305,     0,     0,  2059,     0,  2246,     0,
       0,     0,  1048,     0,  2306,  2246,  3238,     0,  3243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2129,     0,     0,     0,     0,  3504,     0,     0,   846,   900,
       0,     0,  3394,   795,     0,     0,  2873,     0,     0,     0,
    1287,     0,  2873,  2252,  2882,  2883,  2884,  2885,     0,     0,
       0,     0,  2246,     0,     0,     0,  1126,     0,     0,  1127,
       0,     0,     0,     0,   955,  1155,     0,     0,     0,     0,
    2941,  2941,  2245,     0,  2941,     0,  1644,     0,     0,     0,
     795,     0,     0,     0,     0,     0,  2454,     0,     0,     0,
       0,     0,  1652,  1652,     0,  2245,     0,     0,  2406,     0,
       0,     0,     0,     0,     0,     0,   719,     0,  2940,     0,
       0,     0,     0,     0,  2940,  2940,     0,  2940,  2940,  2940,
    2940,     0,     0,  2406,     0,  2406,  2940,     0,  2245,     0,
       0,     0,     0,     0,     0,     0,  3327,     0,     0,     0,
       0,     0,     0,  2188,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3218,     0,     0,  3218,  2684,  2685,  2686,  2687,  2688,
    2689,  2690,  2691,  2692,  2693,     0,     0,     0,  1128,     0,
       0,  1048,     0,  1048,  2261,     0,  2245,  2246,  2246,     0,
       0,  2406,     0,  3243,  1129,  2391,  2246,     0,  1130,     0,
       0,     0,     0,     0,  2224,  2225,  2226,     0,     0,  3025,
     272,  2227,  2228,    42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1131,  3140,     0,     0,
       0,     0,     0,     0,     0,  2245,     0,  2454,     0,  2940,
       0,  2229,  2940,  2940,  2940,  2940,  3417,     0,     0,     0,
       0,     0,     0,  1829,  1132,     0,     0,     0,     0,     0,
    1976,     0,     0,     0,     0,    91,     0,    91,   900,   824,
       0,     0,  1133,     0,     0,     0,  1846,   836,   719,     0,
     900,     0,  2245,     0,   193,  2246,     0,  1861,     0,     0,
       0,     0,  2245,     0,  2246,     0,     0,     0,  2941,     0,
     955,     0,     0,     0,  2941,  2941,     0,  2941,  2941,  2941,
    2941,     0,     0,     0,     0,     0,  2941,     0,   795,  3459,
       0,  2454,     0,   795,     0,     0,     0,     0,     0,  3125,
       0,     0,  3128,  3129,  3130,  3131,     0,     0,     0,     0,
       0,     0,     0,     0,  2246,    91,  2246,  2940,     0,  3340,
       0,     0,     0,     0,  1134,  2940,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   718,  1048,     0,
    2245,     0,  2406,     0,     0,     0,     0,     0,     0,     0,
    1906,     0,     0,   205,     0,     0,     0,  2246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1933,     0,     0,     0,     0,  2245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1135,     0,     0,     0,     0,     0,     0,     0,     0,   795,
       0,   206,   207,     0,     0,     0,     0,  2546,  2547,  2941,
       0,   208,  2941,  2941,  2941,  2941,     0,     0,  2556,     0,
       0,     0,     0,     0,     0,  2224,  2225,  2226,     0,     0,
       0,   272,  2227,  2228,    42,     0,     0,     0,     0,     0,
       0,  2392,     0,     0,     0,     0,     0,     0,  3218,     0,
     393,  3224,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2229,  2597,  2598,  2599,  2600,     0,     0,     0,
       0,  2605,  2606,  2607,  2608,     0,     0,     0,  2610,     0,
       0,     0,  2246,     0,     0,     0,     0,     0,  2246,  2246,
    2246,  2246,  2246,  2246,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2941,     0,     0,
       0,  2129,     0,     0,     0,  2941,  1101,  1102,     0,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  2246,  2230,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3283,  1116,     0,     0,     0,  2231,     0,
       0,  2246,  2246,  2246,  2246,     0,     0,     0,     0,     0,
       0,     0,  2659,  2660,     0,  2232,  2454,     0,  2393,  2664,
    2665,     0,   209,     0,     0,     0,     0,     0,     0,     0,
    2394,  2234,     0,     0,     0,   738,   738,   738,   718,   738,
     738,   738,   738,   738,   738,     0,     0,     0,   738,     0,
       0,     0,  1117,  1118,  1119,  1120,  1121,  1122,  2565,     0,
       0,   210,     0,     0,     0,     0,     0,     0,  1123,  1124,
    1125,  2236,     0,     0,     0,     0,     0,     0,     0,     0,
     211,     0,     0,  2237,     0,  2246,     0,  2246,     0,     0,
       0,     0,     0,     0,     0,     0,   212,  2246,  2246,     0,
    2246,     0,     0,  2246,     0,  2246,     0,  3355,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   213,
       0,     0,     0,     0,     0,  2238,     0,     0,     0,     0,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,  2246,     0,     0,   161,     0,     0,     0,
       0,     0,  1962,   955,     0,     0,  2814,  2815,     0,     0,
     216,     0,     0,     0,  2239,  2822,  3407,     0,     0,     0,
     217,     0,     0,     0,     0,     0,  2240,     0,     0,     0,
       0,     0,     0,     0,     0,   162,   218,     0,  2241,  2242,
       0,     0,     0,     0,  2850,  2851,  2243,     0,     0,  2244,
       0,     0,     0,     0,   163,   953,     0,   275,  2009,  1126,
       0,     0,  1127,  3429,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   219,  2246,     0,     0,
       0,     0,     0,     0,     0,  2246,     0,     0,  2246,  2246,
    2246,  2246,     0,   164,  2230,     0,     0,     0,  2896,   220,
    2898,     0,     0,     0,     0,   165,     0,     0,     0,  2231,
       0,     0,     0,   900,   221,     0,   166,     0,     0,     0,
       0,   222,     0,     0,   223,     0,  2232,     0,     0,  2233,
       0,     0,     0,     0,   167,     0,     0,  2246,  2246,     0,
       0,  2246,  2234,     0,   168,   224,     0,     0,   225,     0,
     226,  3355,     0,     0,     0,     0,     0,     0,  2970,  2971,
     169,     0,  2972,  2973,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1128,  2236,     0,     0,     0,     0,   228,     0,     0,
    3407,     0,     0,     0,  2237,     0,  2996,  1129,     0,     0,
     170,  1130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,     0,     0,  2246,   229,
       0,  2246,     0,     0,  2246,     0,  2238,  2246,   172,  1131,
       0,     0,     0,     0,     0,   173,     0,     0,   174,  2180,
       0,     0,     0,     0,     0,     0,     0,  2187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1132,   900,   175,
       0,     0,   176,     0,   177,  2239,     0,     0,     0,     0,
       0,     0,   230,     0,     0,  1133,     0,  2240,     0,   185,
       0,     0,     0,   178,     0,     0,     0,     0,  2258,  2241,
    2242,     0,     0,     0,     0,     0,     0,  2243,     0,     0,
    2244,   179,     0,  3093,     0,     0,     0,  3098,   275,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3103,     0,   900,  2315,   900,     0,     0,     0,   704,  2246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2246,     0,     0,     0,     0,  1134,     0,     0,
    2363,     0,     0,     0,     0,  2246,     0,     0,     0,     0,
       0,  2246,  2246,     0,  2246,  2246,  2246,  2246,     0,     0,
       0, -2145,     0,  2246,     0,  2246,     0,     0,     0,     0,
       0,     0, -2145,     0, -2145, -2145, -2145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2246,     0,     0,     0,
       0, -2145,     0,  1135,     0,     0,   900,   193,  1102,     0,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  2246,     0,     0,     0,     0,     0,     0,
   -2145,     0,     0,     0,     0,  1116,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   900,     0,   900,
       0,     0, -2145,     0,     0,     0,     0,     0,   900,     0,
       0,     0,  2246,     0,     0,     0,  2246,     0,     0,  2246,
    2246,  2246,  2246,  1117,  1118,  1119,  1120,  1121,  1122,     0,
       0,     0, -2145,     0,     0, -2145,     0,     0,     0,  1123,
    1124,  1125,     0,     0,     0,  2531,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2246,     0,     0,     0,  2246,
   -2145,     0,     0,     0,     0,     0,     0,     0, -2145,  2246,
   -2145,     0,     0,     0,  2555,     0,     0,     0,     0, -2145,
       0,     0,     0,     0,     0, -2145,     0,     0,     0,     0,
       0,     0,     0, -2145,     0,     0,     0, -2145,     0,     0,
       0,     0,     0, -2145,     0,     0,     0, -2145, -2145, -2145,
   -2145,     0,     0,  3276,     0,     0,     0,     0,     0,     0,
       0,     0, -2145,     0,  2246,     0,     0,     0,     0,     0,
       0,  3289,  2246,     0,     0,     0,     0,     0,     0, -2145,
       0,     0, -2145,     0, -2145,     0,     0,  2246,     0,     0,
       0, -2145,     0,  2284,  2285,  2286,  2287,  2288,  2289,     0,
       0,     0,     0,     0, -2145,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2145,     0,     0,     0,     0,     0,
    1126,     0,     0,  1127,     0,     0,  2246,     0,     0,     0,
       0,     0,     0, -2145, -2145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -2145,     0,
       0,     0,  2290,     0,     0,     0, -2145,     0,     0,     0,
   -2145,     0,     0,     0,   953,     0,     0,  2657,     0, -2145,
   -2145, -2145,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2107,  1100,  1101,
    1102,     0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,     0,     0,     0,     0,     0,
       0,  3392,     0,  2532,  1100,  1101,  1102,  1116,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,     0,     0,     0,     0,     0,     0,     0,     0, -2145,
       0,     0,  1128,  1116,     0,     0,   900,     0,     0,     0,
   -2145,     0,     0,     0,     0,     0,     0,  3371,  1129,     0,
       0,     0,  1130,     0,     0,  3421,  3422,     0,  3424,     0,
    3426,  3427,     0,     0,     0,  1117,  1118,  1119,  1120,  1121,
    1122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2145,  1123,  1124,  1125,     0,     0,   900,     0,     0,     0,
    1131,  1117,  1118,  1119,  1120,  1121,  1122,     0,     0,     0,
       0,     0,     0,  3372,     0,  2391,     0,  1123,  1124,  1125,
       0,     0,     0,     0,  2224,  2225,  2226,     0,  1132,     0,
     272,  2227,  2228,    42,     0,     0,     0,     0,  3373,     0,
    2841,     0,   732,     0,  2845,     0,  1133,  3374,     0,     0,
       0,     0, -2145,     0,     0,     0,     0,  2856,     0,  3482,
       0,  3483,   193,     0,     0,     0,     0,     0,     0,     0,
       0,  2229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3375,     0,     0,  2291,     0, -2145,     0,
       0,  3376,  2887,  2258,     0,     0,  2224,  2225,  2226,  2292,
       0,     0,   272,  2227,  2228,    42,     0,  3498,     0,     0,
       0,     0,     0,     0,     0,     0,  2901,  2903,     0,     0,
       0,     0,     0,  3501,  3502,     0,     0,  3503,  1134,     0,
    3505,     0,  1126,     0, -2145,  1127,     0,     0,     0,     0,
       0,     0,     0,  2229,     0,     0,     0,     0, -2145, -2145,
   -2145, -2145, -2145, -2145, -2145,     0, -2145, -2145,  1126,  2968,
       0,  1127,     0,     0,  2293,     0,     0,     0,     0,     0,
       0,  2294,     0, -2145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3377,     0,     0,     0,
       0,     0,     0,     0,  1135,     0,     0,   718,     0,  2990,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2295,     0,  3005,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2297,  2298,     0,     0,     0,     0,
    2299,     0,     0,     0,  1128,     0,     0,     0,     0,     0,
    2300,     0,     0,     0,     0,     0,     0,     0,     0,   718,
    1129,     0,     0,     0,  1130,     0,   900,     0,     0,     0,
    1128,     0,  2301,     0,     0,  2302,  2303,     0,     0,     0,
       0,  2304,     0,     0,     0,     0,  1129,     0,     0,     0,
    1130,  2392,     0,     0,     0,     0,   900,     0,     0,     0,
       0,     0,  1131,     0,     0,     0,   161,     0,     0,     0,
       0,   193,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2258,     0,  1131,     0,
    1132,     0,     0,     0,     0,   955,     0,     0,  2305,     0,
       0,     0,     0,     0,     0,   162,     0,  3378,  1133,  2306,
       0,     0,     0,     0,     0,     0,  1132,     0,     0,     0,
       0,     0,     0,  2392,   163,     0,     0,     0,     0,     0,
       0,  1100,  1101,  1102,  1133,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,
       0,     0,     0,  2230,     0,     0,     0,     0,     0,     0,
    1116,     0,     0,   164,     0,     0,     0,     0,  2231,     0,
       0,     0,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2232,   166,     0,  2393,     0,
    1134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2394,  2234,     0,     0,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   168,     0,  1134,     0,  1117,  1118,
    1119,  1120,  1121,  1122,     0,  2230,     0,     0,     0,     0,
     169,     0,     0,     0,  1123,  1124,  1125,     0,     0,     0,
    2231,  2236,     0,     0,     0,     0,  2990,     0,     0,     0,
       0,     0,     0,  2237,     0,     0,  1135,  2232,     0,     0,
    2393,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     170,     0,  2394,  2234,     0,     0,     0,     0,     0,     0,
       0,     0,  1135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,  2238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,  2236,     0,   173,     0,     0,   174,     0,
       0,     0,     0,     0,     0,  2237,     0,     0,     0,     0,
       0,     0,     0,     0,  2239,     0,     0,     0,   900,   175,
       0,     0,   176,     0,   177,     0,  2240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2241,  2242,
       0,     0,     0,   178,     0,     0,  2243,  2238,     0,  2244,
       0,     0,     0,     0,     0,  1126,     0,   275,  1127,     0,
       0,   179,     0,     0,     0,  1304,  1305,  1306,  1307,  1308,
    1309,     0,  1310,  1311,  1312,     0,  2258,     0,  1313,  1314,
    1315,  1316,  1317,  1318,     0,     0,  2239,     0,     0,     0,
       0,     0,     0,  1319,     0,     0,     0,     0,  2240,     0,
       0,     0,     0,     0,     0,  1320,     0,     0,     0,     0,
    2241,  2242,     0,     0,     0,     0,     0,  2258,  2243,     0,
       0,  2244,     0,  1321,     0,     0,     0,     0,     0,   275,
       0,  2990,  1322,     0,     0,     0,  3331,     0,  3333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1323,     0,  1324,     0,     0,     0,     0,     0,     0,     0,
    1325,     0,     0,     0,     0,  1326,  1327,     0,     0,  1328,
    1329,  1330,  1331,     0,     0,  1332,  1333,  1128,     0,   900,
       0,     0,     0,     0,     0,     0,     0,   900,     0,     0,
       0,     0,     0,  1129,     0,     0,     0,  1130,  1791,     0,
       0,     0,     0,     0,   955,     0,     0,     0,     0,     0,
     193,     0,     0,     0,     0,  1334,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1131,     0,     0,  1335,     0,
       0,     0,     0,     0,  1336,     0,     0,     0,     0,     0,
    1936,  1337,     0,  1338,     0,     0,     0,     0,     0,  1339,
       0,     0,     0,  1132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1133,     0,     0,  1340,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1204,  1204,  1204,  1204,  1204,  1204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1341,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1342,     0,     0,     0,     0,
       0,  1343,     0,     0,     0,     0,     0,     0,     0,     0,
    1344,  1345,     0,     0,     0,     0,     0,  1346,     0,     0,
    1347,  1348,     0,  1134,     0,  1349,     0,     0,     0,     0,
       0,  1350,  1351,     0,     0,     0,     0,     0,  1352,  1353,
    1354,  1355,  1356,  1357,     0,     0,     0,  1358,     0,     0,
       0,  1359,     0,  1360,     0,     0,     0,     0,     0,     0,
    1361,  1362,  1363,  1364,     0,  1365,  1366,     0,     0,     0,
    1367,  1368,     0,  1369,  1370,  1371,  1372,  1373,  1374,  1375,
    1376,     0,     0,     0,     0,     0,  1377,  1378,  1379,  1135,
    1380,  1381,     0,     0,     0,  1382,  1383,  1384,  1385,  1386,
    1387,  1388,  1389,  1390,   955,  1391,     0,     0,     0,  1392,
    1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,  1402,
    1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,     0,  1430,  1431,
       0,     0,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,     0,  1442,  1443,  1444,  1445,  1446,  1447,  1448,
    1449,  1450,  1451,  1452,  1453,  1454,  1455,  1456,     0,     0,
    1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,     0,
    1466,  1467,  1468,  1469,     0,  1470,  1471,  1472,  1473,  1474,
    1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,
    1485,  1486,  1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,     0,  1506,  1507,  1508,  1509,  1510,  1511,     0,     0,
    1512,  1513,     0,  1514,  1515,  1516,  1517,  1518,  1519,  1520,
    1521,  1522,  1523,  1524,  1525,  1526,  1527,  1528,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,  1540,
       0,     0,  1541,  1542,  1543,  1544,  1545,  1546,  1547,  1548,
    1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1578,
    1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,
    1589,  1590,  1591,  1592,  1593,  1594,  1595,  1596,  1597,  1598,
    1599,  1600,  1601,  1602,     0,     0,     0,     0,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1614,
       0,     0,     0,     0,     0,     0,     0,  1615,     0,     0,
       0,     0,  1616,     0,     0,     0,  1617,     0,     0,  1618,
    1619,  1620,  1621,     0,     0,  1622,  1623,     0,  1624,  1625,
    1626,  1304,  1305,  1306,  1307,  1308,  1309,     0,  1310,  1311,
    1312,     0,     0,     0,  1313,  1314,  1315,  1316,  1317,  1318,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1319,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1321,
       0,     0,     0,     0,     0,     0,     0,     0,  1322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1323,     0,  1324,     0,
       0,     0,     0,     0,     0,     0,  1325,     0,     0,     0,
       0,  1326,  1327,     0,     0,  1328,  1329,  1330,  1331,     0,
       0,  1332,  1333,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1335,     0,     0,     0,     0,     0,
    1336,     0,     0,     0,     0,     0,     0,  1337,     0,  1338,
       0,     0,     0,     0,     0,  1339,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1340,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1341,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1342,     0,     0,     0,     0,     0,  1343,     0,     0,
       0,     0,     0,     0,     0,     0,  1344,  1345,     0,     0,
       0,     0,     0,  1346,     0,     0,  1347,  1348,     0,     0,
       0,  1349,     0,     0,     0,     0,     0,  1350,  1351,     0,
       0,     0,     0,     0,  1352,  1353,  1354,  1355,  1356,  1357,
       0,     0,     0,  1358,     0,     0,     0,  1359,     0,  1360,
       0,     0,     0,     0,     0,     0,  1361,  1362,  1363,  1364,
       0,  1365,  1366,     0,     0,     0,  1367,  1368,     0,  1369,
    1370,  1371,  1372,  1373,  1374,  1375,  1376,     0,     0,     0,
       0,     0,  1377,  1378,  1379,     0,  1380,  1381,     0,     0,
       0,  1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,
       0,  1391,     0,     0,     0,  1392,  1393,  1394,  1395,  1396,
    1397,  1398,  1399,  1400,  1401,  1402,  1403,  1404,  1405,  1406,
    1407,  1408,  1409,  1410,  1411,  1412,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1423,  1424,  1425,  1426,
    1427,  1428,  1429,     0,  1430,  1431,     0,     0,  1432,  1433,
    1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,     0,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,     0,     0,  1457,  1458,  1459,  1460,
    1461,  1462,  1463,  1464,  1465,     0,  1466,  1467,  1468,  1469,
       0,  1470,  1471,  1472,  1473,  1474,  1475,  1476,  1477,  1478,
    1479,  1480,  1481,  1482,  1483,  1484,  1485,  1486,  1487,  1488,
    1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,  1497,  1498,
    1499,  1500,  1501,  1502,  1503,  1504,  1505,     0,  1506,  1507,
    1508,  1509,  1510,  1511,     0,     0,  1512,  1513,     0,  1514,
    1515,  1516,  1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1540,     0,     0,  1541,  1542,
    1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1551,  1552,
    1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,
    1563,  1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,
    1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,
    1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
       0,     0,     0,     0,  1603,  1604,  1605,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1614,     0,     0,     0,     0,
       0,     0,     0,  1615,     0,     0,     0,     0,  1616,     0,
       0,     1,  1617,     0,     0,  1618,  1619,  1620,  1621,     0,
     427,  1622,  1623,     0,  1624,  1625,  1626,   428,     2,     3,
       0,     0,     0,     0,     0,     0,   429,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   430,   431,
       0,   432,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,     0,     0,     0,
       0,     0,   434,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   436,   437,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   438,
       0,   439,   440,   441,     5,     6,   442,     7,     8,   443,
       0,   444,     9,   445,   446,     0,     0,     0,     0,     0,
     447,     0,     0,   448,     0,   449,   450,   451,     0,    10,
      11,     0,     0,     0,     0,   452,     0,   453,   454,     0,
     455,     0,   456,   457,     0,     0,   458,    12,     0,     0,
     459,   460,   461,     0,   462,   463,     0,     0,     0,   464,
     465,   466,     0,   467,     0,     0,     0,   468,     0,   469,
     470,     0,     0,     0,     0,   471,     0,     0,     0,   472,
       0,     0,   473,     0,   474,     0,   475,     0,   476,     0,
     477,   478,     0,   479,   480,   481,     0,     0,     0,   482,
       0,   483,   484,     0,   485,     0,     0,     0,     0,     0,
       0,     0,   486,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   488,     0,     0,   489,   490,
       0,     0,   491,   492,     0,     0,   493,   494,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,     0,   498,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   499,
     500,   501,     0,   502,     0,     0,     0,   503,   504,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,   507,   508,
     509,     0,     0,     0,     0,     0,   510,   511,     0,     0,
       0,     0,   512,     0,     0,   513,     0,     0,     0,   514,
     515,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     516,  1100,  1101,  1102,     0,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,   517,     0,
       0,     0,     0,     0,     0,     0,   518,     0,     0,     0,
    1116,     0,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,   520,     0,   521,   522,     0,     0,     0,
       0,     0,     0,     0,   523,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1117,  1118,
    1119,  1120,  1121,  1122,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1123,  1124,  1125,     0,     0,     0,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   525,     0,     0,     0,     0,     0,
       0,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,   528,     0,     0,     0,
     529,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   530,     0,     0,     0,     0,     0,   531,   532,
     533,   534,     0,     0,     0,   535,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,   537,   538,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   539,     0,
     540,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   541,     0,   542,     0,     0,   543,     0,     0,     0,
       0,     0,   544,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1126,     0,     0,  1127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,     0,
       0,   546,     0,     0,     0,     0,   547,     0,     0,   548,
     549,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   550,     0,     0,     0,     0,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,     0,     0,   559,     0,   560,     0,   561,     0,     0,
       0,     0,     0,   562,   563,   564,     0,     0,     0,  1100,
    1101,  1102,     0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1128,  1116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1129,     0,     0,     0,  1130,  2091,  1100,
    1101,  1102,     0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1116,     0,
       0,     0,     0,     0,     0,  1131,  1117,  1118,  1119,  1120,
    1121,  1122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1123,  1124,  1125,     0,     0,     0,     0,     0,
       0,     0,     0,  1132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1133,     0,     0,     0,     0,  1117,  1118,  1119,  1120,
    1121,  1122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1123,  1124,  1125,     0,     0,     0,     0,     0,
    1100,  1101,  1102,     0,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1100,  1101,  1102,  1116,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1134,     0,  1116,  1100,  1101,  1102,     0,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1126,     0,  1116,  1127,  1117,  1118,  1119,
    1120,  1121,  1122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1123,  1124,  1125,     0,     0,     0,     0,
       0,     0,     0,  1117,  1118,  1119,  1120,  1121,  1122,  1135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1123,
    1124,  1125,     0,  1126,     0,     0,  1127,     0,     0,     0,
       0,     0,     0,  1117,  1118,  1119,  1120,  1121,  1122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1123,
    1124,  1125,  1100,  1101,  1102,     0,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1129,     0,     0,     0,  1130,  2100,  1100,  1101,  1102,
       0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,  1126,     0,     0,  1127,     0,  1117,
    1118,  1119,  1120,  1121,  1122,  1128,  1116,     0,     0,     0,
       0,     0,     0,  1131,     0,  1123,  1124,  1125,     0,     0,
    1126,  1129,     0,  1127,     0,  1130,  2105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1132,     0,     0,     0,     0,     0,     0,     0,     0,
    1126,     0,     0,  1127,     0,     0,     0,     0,     0,  1133,
       0,     0,     0,  1131,  1117,  1118,  1119,  1120,  1121,  1122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1123,  1124,  1125,     0,     0,     0,     0,     0,     0,     0,
       0,  1132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1133,
       0,     0,     0,     0,     0,     0,  1128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1129,     0,     0,     0,  1130,  2113,     0,     0,
       0,  1134,  1128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1126,     0,  1129,  1127,
       0,     0,  1130,  2115,     0,     0,     0,     0,     0,     0,
       0,     0,  1128,     0,  1131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1129,     0,
       0,  1134,  1130,  2116,     0,     0,     0,  2224,  2225,  2226,
    1131,     0,  1132,   272,  2227,  2228,    42,  1135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1133,  1126,     0,     0,  1127,     0,     0,     0,  1132,     0,
    1131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2229,  2226,  1133,     0,     0,   272,
    2227,  2228,    42,     0,     0,     0,     0,  1135,  1132,     0,
       0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1115,     0,     0,  1133,     0,  1128,     0,
       0,     0,     0,     0,     0,     0,  1116,     0,     0,     0,
    2229,     0,     0,     0,  1129,     0,     0,     0,  1130,  2117,
       0,     0,  1134,     0,     0,     0,     0,     0,  1100,  1101,
    1102,     0,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,     0,     0,     0,  1134,     0,
       0,     0,     0,     0,     0,     0,  1131,  1116,     0,     0,
       0,     0,     0,  1128,  1117,  1118,  1119,  1120,  1121,  1122,
       0,     0,     0,     0,     0,     0,     0,     0,  1134,  1129,
    1123,  1124,  1125,  1130,  1132,     0,     0,     0,  1135,     0,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1135,  1117,  1118,  1119,  1120,  1121,
    1122,  1131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1123,  1124,  1125,  2119,     0,   718,     0,     0,     0,
       0,     0,     0,     0,  1135,     0,     0,     0,     0,  1132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,  1101,  1102,  1133,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,     0,     0,     0,  1134,     0,     0,     0,     0,     0,
    1100,  1101,  1102,  1116,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1116,
       0,  1126,     0,     0,  1127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,  1134,
    1135,  1117,  1118,  1119,  1120,  1121,  1122,     0,     0,     0,
    1116,     0,     0,     0,     0,     0,     0,  1123,  1124,  1125,
       0,     0,  1126,     0,     0,  1127,     0,  1117,  1118,  1119,
    1120,  1121,  1122,     0,     0,     0,     0,     0,     0,   742,
       0,     0,     0,  1123,  1124,  1125,  2230,     0,   743,   744,
       0,     0,     0,     0,   272,   745,   746,    42,     0,     0,
       0,  2231,     0,     0,     0,  1135,     0,     0,  1117,  1118,
    1119,  1120,  1121,  1122,     0,     0,     0,     0,  2232,     0,
       0,  2233,     0,     0,  1123,  1124,  1125,     0,     0,     0,
     747,     0,  2230,  1128,  2234,   748,     0,     0,     0,     0,
       0,     0,   749,     0,     0,     0,     0,  2231,     0,  1129,
       0,     0,     0,  1130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2232,     0,     0,  2233,     0,     0,
     750,     0,     0,  2235,  2236,     0,     0,     0,     0,     0,
    2234,     0,     0,     0,  1128,     0,  2237,     0,     0,     0,
       0,  1131,     0,     0,     0,     0,     0,     0,  1126,     0,
    1129,  1127,     0,     0,  1130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1132,
    2236,     0,     0,     0,  1126,     0,     0,  1127,  2238,     0,
       0,   742,  2237,     0,     0,     0,     0,  1133,     0,     0,
     743,   744,  1131,     0,     0,     0,   272,   745,   746,    42,
       0,     0,     0,     0,     0,  2120,     0,     0,     0,     0,
       0,    84,     0,   751,     0,  1126,     0,  2239,  1127,     0,
    1132,     0,     0,     0,  2238,     0,     0,     0,     0,  2240,
       0,     0,   747,     0,     0,     0,     0,   748,  1133,     0,
       0,  2241,  2242,     0,   749,     0,     0,     0,     0,  2243,
       0,     0,  2244,     0,     0,     0,     0,     0,     0,     0,
     275,     0,     0,  2239,     0,     0,     0,     0,     0,  1134,
    1128,     0,   750,     0,     0,  2240,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1129,  2241,  2242,     0,
    1130,     0,     0,     0,     0,  2243,  1128,     0,  2244,     0,
       0,     0,     0,     0,     0,     0,   275,     0,     0,     0,
     752,     0,  1129,     0,     0,   753,  1130,     0,     0,     0,
    1134,     0,     0,     0,     0,     0,     0,     0,  1131,     0,
       0,     0,     0,     0,     0,  1135,     0,  1128,     0,     0,
       0,  2123,     0,   754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1129,  1131,     0,  1132,  1130,     0,     0,
       0,     0,     0,    84,     0,   751,     0,     0,     0,     0,
       0,     0,     0,     0,  1133,     0,     0,     0,   755,     0,
       0,     0,  1132,     0,     0,     0,  1135,     0,     0,     0,
     756,     0,     0,     0,     0,  1131,     0,     0,     0,     0,
    1133,     0,     0,     0,     0,     0,     0,     0,  2118,   757,
       0,     0,     0,     0,   758,     0,     0,   759,     0,     0,
       0,     0,     0,  1132,     0,     0,     0,     0,   760,     0,
       0,     0,     0,     0,   761,     0,     0,     0,     0,     0,
       0,  1133,     0,     0,   762,     0,     0,     0,     0,   763,
       0,     0,   764,     0,     0,   765,  1134,     0,     0,     0,
       0,     0,   752,   742,   766,   767,     0,   753,     0,     0,
       0,     0,   743,   744,     0,     0,     0,     0,   272,   745,
     746,    42,  1134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   754,     0,     0,     0,     0,
       0,     0,     0,     0,  1151,   768,     0,     0,     0,   769,
       0,     0,     0,     0,   747,     0,     0,   770,     0,   748,
       0,     0,  1135,  1134,     0,     0,   749,     0,   771,     0,
     755,     0,     0,     0,   772,     0,     0,     0,     0,     0,
       0,     0,   756,     0,     0,     0,     0,     0,  1135,     0,
       0,     0,     0,     0,   750,     0,     0,     0,     0,   773,
       0,   757,     0,     0,     0,     0,   758,     0,     0,   759,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,   761,     0,     0,  1135,
       0,     0,     0,     0,     0,     0,   762,     0,     0,     0,
       0,   763,     0,   774,   764,     0,     0,   765,     0,     0,
     775,     0,   776,     0,     0,     0,   766,   767,     0,     0,
       0,     0,   777,   778,     0,     0,     0,     0,     0,     0,
     779,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,    84,     0,   751,     0,     0,
     742,     0,     0,     0,     0,     0,     0,   768,     0,   743,
     744,   769,     0,     0,     0,   272,   745,   746,    42,   770,
       0,     0,     0,     0,     0,   272,  2227,  2228,    42,     0,
     771,     0,  2499,     0,     0,     0,   772,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   747,     0,     0,     0,     0,   748,     0,     0,     0,
       0,   773,     0,   749,     0,     0,  2926,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1116,   750,     0,     0,   752,     0,     0,     0,     0,   753,
       0,     0,     0,     0,     0,   774,     0,     0,     0,     0,
       0,     0,   775,     0,   776,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   777,   778,     0,   754,     0,     0,
       0,     0,   779,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,     0,     0,     0,  1117,  1118,
    1119,  1120,  1121,  1122,     0,     0,     0,     0,     0,     0,
       0,     0,   755,     0,  1123,  1124,  1125,     0,     0,     0,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
       0,     0,    84,     0,   751,     0,     0,     0,     0,     0,
       0,     0,   718,   757,     0,     0,     0,     0,   758,     0,
       0,   759,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   760,     0,     0,     0,     0,     0,   761,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   762,     0,
       0,     0,     0,   763,     0,     0,   764,     0,     0,   765,
       0,     0,     0,     0,     0,     0,     0,     0,   766,   767,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,  1116,
       0,   752,     0,     0,     0,     0,   753,     0,  2860,   768,
       0,     0,     0,   769,     0,     0,     0,     0,     0,     0,
       0,   770,     0,     0,     0,  1126,     0,     0,  1127,     0,
       0,     0,   771,     0,   754,     0,     0,     0,   772,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1117,  1118,  1119,  1120,  1121,  1122,     0,  1117,  1118,  1119,
    1120,  1121,  1122,   773,     0,     0,  1123,  1124,  1125,   755,
       0,     0,     0,  1123,  1124,  1125,     0,     0,     0,     0,
       0,   756,     0,     0,     0,     0,     0,     0,     0,  1107,
    1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,     0,     0,
     757,     0,     0,     0,     0,   758,     0,   774,   759,     0,
    1116,     0,     0,     0,   775,     0,   776,     0,  2230,   760,
       0,     0,     0,     0,     0,   761,   777,   778,     0,     0,
       0,     0,     0,  2231,   779,   762,     0,     0,     0,     0,
     763,     0,     0,   764,     0,   275,   765,  1128,     0,     0,
    2927,     0,     0,  2928,     0,   766,   767,     0,     0,     0,
       0,     0,     0,  1129,     0,     0,  2929,  1130,  1117,  1118,
    1119,  1120,  1121,  1122,     0,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,     0,  1123,  1124,  1125,     0,     0,     0,
       0,     0,     0,     0,     0,  1116,   768,     0,     0,     0,
     769,     0,     0,     0,     0,  1131,  2931,  1126,   770,     0,
    1127,     0,     0,     0,  1126,     0,     0,  1127,  2932,   771,
       0,     0,     0,     0,     0,   772,     0,     0,     0,     0,
       0,     0,     0,  1132,     0,  2224,  2225,  2226,     0,     0,
       0,   272,  2227,  2228,    42,     0,     0,     0,     0,     0,
     773,  1133,     0,  1117,  1118,  1119,  1120,  1121,  1122,     0,
    2933,     0,     0,     0,     0,     0,     0,     0,     0,  1123,
    1124,  1125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2229,     0,  1110,  1111,  1112,  1113,  1114,  1115,
       0,     0,     0,     0,   774,     0,     0,     0,     0,  2934,
       0,   775,  1116,   776,     0,     0,     0,     0,     0,     0,
       0,  2935,     0,   777,   778,     0,     0,     0,     0,     0,
       0,   779,     0,  2936,  2937,  1126,     0,     0,  1127,  1128,
       0,  2938,   275,  1134,  2939,     0,  1128,     0,     0,     0,
       0,     0,   275,     0,     0,  1129,     0,     0,     0,  1130,
       0,     0,  1129,     0,     0,     0,  1130,     0,     0,     0,
    1117,  1118,  1119,  1120,  1121,  1122,  1111,  1112,  1113,  1114,
    1115,     0,     0,     0,     0,     0,  1123,  1124,  1125,     0,
       0,     0,     0,  1116,     0,     0,     0,  1131,     0,  2224,
    2225,  2226,     0,     0,  1131,   272,  2227,  2228,    42,  1135,
       0,     0,     0,     0,     0,     0,     0,     0,   718,     0,
    1126,     0,     0,  1127,     0,  1132,     0,     0,  2924,  2925,
       0,     0,  1132,     0,   272,  2227,  2228,    42,     0,     0,
       0,     0,     0,  1133,     0,     0,  2229,     0,     0,     0,
    1133,  1117,  1118,  1119,  1120,  1121,  1122,  1128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1123,  1124,  1125,
       0,     0,     0,  1129,     0,  2926,     0,  1130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2924,  2925,
       0,     0,     0,     0,   272,  2227,  2228,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1134,     0,  1126,     0,     0,
    1127,     0,  1134,     0,     0,  2926,     0,     0,     0,     0,
       0,     0,  1128,  1132,     0,     0,     0,  2924,  2925,     0,
       0,     0,     0,   272,  2227,  2228,    42,     0,  1129,     0,
       0,  1133,  1130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   718,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1135,     0,     0,  2926,     0,     0,     0,  1135,     0,
    1131,   718,     0,     0,     0,     0,     0,     0,  1126,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2230,     0,     0,     0,  1132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2231,
       0,     0,     0,  1134,     0,     0,  1133,     0,     0,  1128,
       0,     0,     0,     0,     0,     0,  2232,     0,     0,  2233,
       0,   718,     0,     0,     0,  1129,     0,     0,     0,  1130,
       0,     0,  2234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2565,
       0,     0,     0,     0,     0,     0,     0,  1131,     0,  1135,
       0,     0,  2236,     0,     0,     0,     0,     0,     0,     0,
     718,     0,     0,     0,  2237,     0,     0,     0,  1134,     0,
    1128,     0,     0,     0,     0,  1132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1129,     0,     0,     0,
    1130,     0,     0,  1133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2238,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1131,     0,
       0,     0,     0,  2231,  1135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2239,     0,  2230,     0,     0,
    2232,     0,     0,  2233,     0,     0,  1132,  2240,     0,     0,
       0,     0,  2231,     0,     0,     0,  2234,     0,     0,  2241,
    2242,     0,     0,     0,  1133,  1134,     0,  2243,     0,  2927,
    2244,     0,  2928,     0,     0,     0,     0,     0,   275,     0,
       0,     0,     0,     0,     0,  2929,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3404,  2236,  2230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2237,     0,
       0,     0,  2231,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2930,  2931,     0,     0,     0,  2927,
       0,  1135,  2928,     0,     0,     0,     0,  2932,     0,     0,
       0,     0,     0,     0,     0,  2929,  1134,     0,     0,     0,
    2238,     0,     0,     0,     0,     0,  2230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2231,  2565,     0,     0,     0,     0,     0,     0,  2933,
       0,     0,     0,     0,     0,  2931,     0,     0,  2927,  2239,
       0,  2928,     0,     0,     0,     0,     0,  2932,     0,     0,
       0,  2240,     0,     0,  2929,     0,     0,     0,     0,     0,
       0,     0,  1135,  2241,  2242,     0,     0,     0,  2934,     0,
       0,  2243,     0,     0,  2244,     0,     0,     0,     0,     0,
    2935,     0,   275,     0,     0,     0,     0,     0,     0,  2933,
       0,     0,  2936,  2937,  2931,     0,     0,     0,     0,     0,
    2938,     0,     0,  2939,     0,     0,  2932,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2934,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2935,     0,     0,     0,     0,     0,     0,     0,  2933,     0,
       0,     0,  2936,  2937,     0,     0,     0,     0,     0,     0,
    2938,     0,     0,  2939,     0,     0,     0,     0,     0,     0,
       0,   275,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2934,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2935,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2936,  2937,     0,     0,     0,     0,     0,     0,  2938,
       0,     0,  2939,     0,     0,     0,     0,     0,     0,     0,
     275
};

static const short yycheck[] =
{
       4,   196,   533,   736,   733,   335,   510,     0,   214,    13,
      14,   457,   417,    17,   190,   719,   859,   464,   434,   894,
    1024,   888,  1017,   856,  1862,   870,    84,   156,   531,   178,
     371,  2042,    25,    68,  1907,  1052,   759,   527,    31,  1772,
     458,  2046,    46,    47,  1636,  1637,  1086,  2211,  2341,  2639,
    2640,  2641,   866,   867,    63,   869,  1738,   871,   872,  2093,
    1741,  1727,   492,   481,  1669,   555,     5,  2153,   558,  1965,
      27,    27,   519,   520,    78,    68,   517,    81,   227,   396,
     809,    27,   529,  2224,  2225,   120,     5,     5,    97,    93,
      24,   267,    26,    65,    27,     5,   100,     5,  2037,  2038,
     104,   517,  2041,   107,   108,   551,    19,   525,    20,   113,
     114,   240,   241,    26,   947,    27,   534,   535,     5,  2283,
     538,    24,    25,    26,   542,     5,    24,   120,    26,     5,
     548,   964,   550,  2756,   143,    63,   101,     5,   147,     5,
     983,    25,     5,    27,    26,    27,    88,    89,   152,     5,
      20,   155,   347,   521,    63,    25,   160,    27,    25,    69,
      27,    71,  1934,    73,    82,    83,    19,  2642,    25,     5,
      27,    24,    25,    26,   429,    27,    27,   432,   433,    24,
      25,    26,    27,   135,    81,    24,    25,    26,    27,     5,
    2620,   446,    27,    25,   198,    27,     5,    24,    25,    26,
      27,   275,     5,  2142,    24,    25,    26,    27,   403,     5,
     465,     6,   163,   468,    24,    25,    26,    27,   951,   474,
     229,    27,     5,   478,     5,  2230,   429,   482,    25,    26,
      27,   486,    25,   237,    27,   490,   491,     5,   493,   243,
    2863,   496,     5,   498,   499,   500,     5,    25,    27,    27,
     254,   506,     6,    66,   509,    49,    50,    51,    52,    53,
       5,   516,   465,     5,     5,   468,   521,    18,    19,    20,
      21,    22,   236,   528,   283,   478,   285,     5,     5,   482,
       6,   290,     5,   486,   539,    18,    19,     5,   543,   345,
     493,  2833,   547,    26,    27,   498,    27,   500,   553,   356,
    2279,   556,   163,   506,   150,  2016,   509,   191,  2019,   191,
      27,    19,   718,   516,    25,   391,    27,  2155,   521,   208,
       5,  2332,   283,    27,   150,   528,  2619,    92,  2570,  2571,
    2572,  2573,   877,   878,   343,   296,   539,   372,   373,     5,
     543,     0,   340,     5,   547,  1977,   191,   393,   432,    27,
     553,   360,   191,   556,    27,    27,     5,    27,   296,   191,
     364,   548,     5,   367,   191,   432,  3244,   334,   460,     9,
      10,   375,    12,    13,    14,    15,    16,    17,    86,   372,
     373,   191,  2393,   360,   802,   916,  1253,   391,    23,   393,
    2329,  2946,   540,   460,   345,   275,    29,   578,   191,     5,
       9,    10,   540,    12,    13,    14,    15,    16,    17,   275,
      57,    58,     5,   191,   249,  2354,   432,   389,   422,   376,
     387,    25,     5,    27,   428,     5,   430,   431,    20,     5,
     434,   435,   619,   437,   393,    27,   440,   618,    85,    86,
      87,   589,   414,     5,   460,     5,     5,   451,     5,  2388,
      31,   589,     5,     5,   458,     5,     5,     5,   191,     5,
     191,     5,   275,   460,  1197,     5,     5,   471,   427,     5,
     431,    18,    19,    20,    21,    22,   894,   481,   535,     0,
     484,   472,  2912,     5,   345,   151,   904,   191,  3366,   480,
     494,   909,   549,   431,   397,     5,   570,     5,     5,   350,
     477,     5,   340,     5,    25,     5,   510,   511,   432,   412,
       5,     5,   401,   517,   442,   350,     5,   574,     5,     5,
       5,   525,   526,   527,     5,   497,     5,     5,     5,   621,
     534,   535,   345,   537,   538,   459,   540,     5,   542,     5,
      28,   597,   506,   627,   548,   591,   550,   386,   552,  2378,
     554,   555,   397,   557,   558,  2384,   560,    10,  1062,  1063,
     901,   284,   903,   515,   510,   622,  2158,   412,   246,  1059,
     397,  2864,  2551,   246,  1064,  1065,   246,   393,   391,   375,
      23,   259,   580,  2316,   660,   412,   259,   191,  1292,   259,
      23,  1081,   428,  2734,  2735,   546,  2737,  1038,   393,  2740,
     235,  3143,  3157,  3158,   859,  1010,   563,   136,   137,  3235,
     587,  3237,   464,   253,   982,   340,   544,  2490,   590,   428,
     502,   472,  1038,   541,   621,   428,   432,   472,   579,  1035,
     602,   603,   597,   350,  1165,   544,   361,   472,   610,   393,
     472,   284,  3184,   540,   253,   428,  1177,   428,   393,   488,
     558,   393,   393,   432,  2365,   386,   859,  3280,   591,   516,
     428,  2325,  2535,   391,   668,   428,   393,   393,   555,   428,
    1000,  2544,  2545,  2837,   556,   393,   552,   428,   591,  1183,
     548,   527,   386,   692,  1001,   627,   360,   621,  1178,   552,
     570,  2855,   548,  2632,   698,  2327,   700,  1242,    27,   432,
     619,   527,  3177,   587,   570,   325,    27,  2928,   393,   619,
     628,   668,   668,   615,   718,  3145,  3146,   627,   621,  2615,
    1161,   432,   668,   621,   663,  3348,   981,   982,   983,   733,
    2816,   393,   372,   373,  2820,  2340,  1166,  1741,   742,   743,
     744,  1245,   580,   613,   393,  1161,   613,    27,  2414,  1167,
    1168,  1169,  2786,   393,   758,  2437,   668,   570,  2439,   432,
     764,   765,   432,   372,   373,   769,  1270,     5,   621,  1187,
     168,  1275,   627,  3396,   552,  3398,   621,   354,   981,   982,
     983,  1271,   621,  1823,   367,   578,  1826,   393,   670,   620,
     430,   585,   235,   397,   621,  2567,   627,   250,   802,   477,
     393,   621,   235,   477,   477,   809,  3432,   477,  2747,   456,
    2749,   621,    25,   393,    27,   493,   613,   393,   332,  1265,
     493,   430,  3064,   493,     5,  1243,   325,   626,    25,  3419,
      27,   393,  2565,   393,   393,   243,   393,   650,   651,   652,
     393,   393,  1289,   393,   393,   393,  1264,   393,   661,   393,
     649,   855,   856,   393,   393,   580,  3149,   393,  1875,    26,
      27,  2866,   482,  1281,   175,   618,  2638,  2639,  2640,  2641,
     191,   393,   455,  1291,   621,   640,   641,   642,   643,   644,
    3021,   428,   283,   393,  1013,   393,   393,  1016,   471,   393,
     894,   393,  2392,   393,  2394,   296,   543,     5,   393,   393,
     904,     5,   158,   141,   393,   909,   393,   393,   393,   438,
     914,   191,   393,   587,   393,   393,   393,  2509,   558,  3161,
     363,  3163,  3164,  3165,  3166,   393,  3014,   393,   932,  3017,
     363,   514,  3020,  1662,  1663,   388,   367,   390,   540,   586,
     626,  3162,  1671,   947,   375,   367,    14,  3168,    20,   558,
    3171,  3172,  3173,  3174,  2735,    27,  2737,  2621,  2622,  2740,
     964,   272,   648,   649,    28,    29,   742,   743,   744,   249,
     151,   554,   874,  2846,  2913,  3139,  1034,   354,   191,   881,
    3294,   523,   758,   482,   624,  1714,  3300,   589,   764,   765,
     460,   422,  3120,   769,   191,    18,    19,    20,    21,    22,
     583,   515,    26,    27,   432,  1181,   626,    26,    27,   592,
      26,    27,   526,   342,  1018,   624,  3144,   113,  1022,  1023,
    1024,   350,   351,  2962,   191,   645,   646,    25,  3156,    27,
     431,  1035,  3169,   455,  1038,  1880,  1040,  1041,   678,   679,
    1044,   297,   440,  3180,   432,   665,   537,   376,   164,   471,
     379,   167,    25,   451,    27,  1059,  1060,   432,  1062,  1063,
    1064,  1065,   482,  1067,  1787,   432,  1070,    25,   397,   678,
     679,   459,   460,    20,   472,   460,   192,  1081,  2082,  1083,
      27,   479,  3303,  1087,   432,  3306,  3307,  3308,  3309,  1922,
     432,  1095,   514,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1116,    22,   626,    20,  3121,   427,   374,  3124,
     239,   460,    27,  1127,  1128,    26,    35,   626,  1132,  2133,
    1134,   336,   554,   158,   522,  3223,   648,   649,  2638,  2639,
    2640,  2641,   347,  1633,  1634,  1149,   645,   646,   460,   432,
    1993,   164,  2924,  2925,   167,   271,  2928,  1161,   274,  2759,
     432,   583,  2762,  1167,  1168,  1169,   665,   191,   432,  3297,
     592,  3182,   191,   502,  1178,   191,  1180,   296,  1182,  1183,
     296,   432,  2915,  1187,    93,    94,    95,    96,    97,    98,
    3411,   432,    20,   191,    34,   400,    36,    37,    38,    27,
     109,   110,   111,  3273,  3274,    25,   626,    27,    26,    20,
     415,   198,    25,  3152,    27,   202,    27,   432,   191,  1750,
     178,   477,   432,    20,   440,   645,   646,   556,    62,   348,
      27,   627,   451,   352,   563,   451,  2736,   493,  2738,  1243,
    3021,  1245,    25,  3015,    27,   665,  3018,    34,   627,    36,
      37,    38,   471,    25,  1983,    27,   472,    25,   271,    27,
    1264,   274,    20,   479,  1268,   484,  1270,  1271,    30,    27,
     640,  1275,   297,   643,   644,  1279,  1280,  1281,    34,   591,
      36,    37,    38,   296,  1060,    47,    48,  1291,    25,   621,
      27,  1067,    26,    25,  1070,    27,    25,   539,    27,   504,
     134,   543,   239,    19,    26,   547,  3245,  1083,    24,   621,
      26,  1087,   431,    26,    76,   431,  3386,  1764,  3388,  1095,
      26,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,
    1116,   250,   641,   642,   253,  3356,    25,   305,    27,   374,
      26,  1127,  1128,   311,   312,   313,  1132,   296,  1134,   296,
     460,   123,   124,   468,   126,   127,   200,    26,   202,   131,
     393,   191,    26,   331,  1905,    26,  1823,   482,   191,  1826,
      25,   486,    27,   217,  1874,    26,   148,   149,  3160,    26,
    3162,   225,    26,   498,  2389,   229,  3168,  3169,  2265,  3171,
    3172,  3173,  3174,   621,   166,   432,    59,   432,  3180,   348,
     393,   348,  1830,   352,  2428,   352,  2430,  2431,   431,   191,
     254,   459,   460,   191,  2924,  2925,   432,  1845,  2928,    25,
      26,   271,   459,   460,   274,  2439,   276,   554,  1969,   362,
     557,  2436,   621,   560,    27,    26,  1950,  1951,   160,   459,
     460,  1869,   477,   432,   191,  1873,   296,   432,    25,   191,
      27,   428,   191,   372,   176,   177,   306,     5,   493,   456,
     457,   393,  1975,   185,  1964,   237,   675,   676,   677,   388,
      20,    21,   440,   392,   271,   443,   460,   274,  2331,   276,
     288,   289,   431,   451,   431,   522,  1914,  3436,    25,   164,
      27,   621,   167,    20,    21,   643,   644,   219,   348,   296,
    2353,  1660,   352,    26,  3387,   271,   228,  1666,   274,   306,
     276,   430,   105,   614,   615,   616,   617,   192,   486,   259,
    3368,  3303,   650,   651,  3306,  3307,  3308,  3309,   325,   428,
     296,  2245,  2073,   393,    25,   257,    27,  3385,   625,   458,
     306,    20,  1893,    93,    94,    95,    96,    97,    98,  2924,
    2925,   348,   500,   521,   551,   352,    24,   476,    26,   325,
    3342,   509,   155,  1702,   561,    20,    93,    94,    95,    96,
      97,    98,  1711,   541,   542,  2314,   109,   110,   111,   362,
     302,   431,   348,    26,   552,   357,   352,   875,   876,   557,
      26,   879,   880,  2134,    26,  2136,   271,  3445,   191,   274,
     193,    26,  1867,   134,  2145,   553,    19,  2450,   556,   650,
     651,    24,    25,    26,  3462,    26,   432,  2356,  1632,  1633,
    1634,   296,   344,    26,    26,   134,  2083,  2100,   596,  3411,
      24,  2104,    26,    26,   431,   407,  2109,  3419,   393,   558,
    2113,   621,  2115,  2116,  2117,  1659,     5,  2075,  1662,  1663,
     393,    26,  3162,  1667,  1867,  1669,   393,  1671,  3168,  3169,
     628,  3171,  3172,  3173,  3174,   431,    24,   439,    26,   200,
    3180,   202,   303,   393,  2529,  2560,   393,  2191,    18,    19,
      20,    21,    22,  2526,   393,   393,   217,   367,  1707,   625,
    1162,   200,  1164,   202,   225,     5,   468,   290,   229,   393,
    1714,   303,   393,   393,   625,   624,   393,  1972,   217,  2137,
    2138,  2139,  2140,  1727,   393,   621,   225,  2174,   618,   367,
     229,   432,   460,   254,  1738,   621,     8,  1741,  1993,   428,
     480,   240,    30,  2161,  2611,   432,   527,   432,   422,   736,
     432,   267,   461,    30,   432,   254,  1760,  1761,  1762,    47,
      48,   432,     5,   619,   432,   432,   431,   619,   432,  1972,
      47,    48,  2776,  2768,   432,   358,  2223,   432,   597,    56,
     432,   660,   432,   366,    61,   455,   432,   370,   432,   432,
    1993,   422,  1796,  1797,  1798,   782,  1800,   432,   461,  2217,
     432,   471,   432,  3303,   432,   432,  3306,  3307,  3308,  3309,
     432,   660,   432,   432,   432,   432,   367,   455,   327,   367,
       8,   598,     5,  1827,     5,   408,  1830,  1831,   385,   106,
     107,   432,   432,   471,   432,   123,   124,   114,   126,   127,
     345,  1845,   432,   131,   514,   432,   123,   124,   591,   126,
     127,    25,     8,    27,   131,   580,    14,    47,    48,  1863,
     148,   149,   577,     5,   660,  1869,   660,  1871,  1872,  1873,
    1874,   148,   149,    47,    48,     5,   514,   422,   166,  2074,
     432,    26,   432,    26,   554,    92,    66,   460,  1892,   166,
     460,    26,   475,  2099,     5,   597,   591,   621,   432,  1903,
     432,   472,   432,  1907,   455,    20,   627,   455,    20,     5,
    1914,  3411,  2443,   583,   432,   663,   554,   432,  1922,  3419,
     471,   432,   592,   471,  1928,  1929,  2344,  1931,  2346,   432,
    1934,   514,   626,   123,   124,   627,   126,   127,   351,   627,
       5,   131,   558,    18,    26,   583,  1950,  1951,    19,   123,
     124,   153,   126,   127,   592,   219,   539,   131,   148,   149,
    1964,    25,  2493,   514,   951,    26,   514,     6,     7,     8,
       9,    10,    11,    12,   148,   149,   166,   591,   580,  1983,
       5,   483,   433,   483,   624,   621,   548,   151,   548,    26,
     129,   401,   166,   322,   548,   446,    26,   432,  2002,   138,
     583,   432,   432,   554,   432,   432,   554,   393,   147,   592,
     621,  2015,  2016,   152,   578,  2019,   665,   191,   460,   548,
    1796,  1797,  1798,   474,  1800,   393,   393,   393,    26,   393,
     393,  2035,   583,  2037,  2038,   583,   367,  2041,  2042,   490,
     491,   592,   393,   393,   592,   496,   393,   237,   499,   618,
     432,  1827,  2781,   627,     5,     5,     5,   196,   621,   581,
       5,   484,   627,   237,  2068,   204,   393,  2071,   626,   357,
    2325,  2075,   432,   432,     5,     8,  2331,   537,  2082,    26,
      26,  2499,    66,     5,  2502,  2089,    20,    21,    22,   326,
       5,   368,   119,   432,   393,   432,   361,  2601,  2353,  2603,
     598,    35,   627,    14,   367,   661,   552,   548,     5,  2842,
      26,   101,   432,   621,   432,   627,  1892,  2121,   395,   407,
    2124,   260,  2325,     5,   455,   626,   640,   428,  2331,  2133,
     428,  1907,     8,  2137,  2138,  2139,  2140,   462,  2142,   462,
     471,   432,  2560,   432,  2148,  2149,   285,   432,  2152,  2153,
    2353,   432,   432,   292,   432,   294,   432,  2161,     5,    93,
      94,    95,    96,    97,    98,   304,    26,  2171,    18,    19,
      20,    21,  2588,    26,   591,   109,   110,   111,   393,   393,
     468,    25,    25,   514,    25,   393,    25,  2191,   393,   466,
       5,   330,   455,     5,     8,   222,   621,   621,   555,   338,
     621,   326,    25,   230,   345,   345,   460,   621,   471,   236,
    1197,   238,   345,  2217,   432,   361,  3083,   427,   460,   432,
    2224,  2225,   249,   554,  3091,    62,  2672,  2673,  2674,  2233,
    2676,  2677,  2678,  2679,  2680,  2681,  2940,   376,  3105,  2685,
    2244,   432,  2773,    93,    94,    95,    96,    97,    98,   439,
     277,   514,   583,   432,   432,   432,   432,   432,     5,   422,
     422,   592,  2266,   402,     5,   439,   293,   652,    26,     5,
       5,   298,  2803,    25,    14,    14,    26,   618,  1265,    30,
     597,   597,   559,   310,   432,   621,   621,   991,     5,     5,
     317,   554,     5,     7,   432,   393,    47,    48,   135,   136,
       5,   440,   621,   627,    26,    26,    26,   621,     8,   393,
    2314,    26,   451,   393,    25,   627,   250,   591,   627,   253,
     583,   393,    20,   393,   393,  2329,   393,  3056,  2332,   592,
     393,     5,   568,   275,  2824,  2339,  2340,  2341,  3181,   393,
    2344,  2831,  2346,  2378,     5,  2121,     5,   548,  2124,  2384,
    2354,     5,  2356,   190,   669,     5,   573,   393,   627,   196,
     393,  2365,   639,   621,  2559,   621,  2621,  2622,   472,   393,
     647,     6,   123,   124,   432,   126,   127,   627,     5,   627,
     131,   211,   555,    25,  2388,  2378,   625,  2391,    25,  2393,
     625,  2384,    25,   620,    25,   448,  3263,   148,   149,    25,
     432,  2405,    26,    26,    26,    26,    26,    26,   297,  2827,
    2414,   550,   551,   552,   432,   166,   472,    26,  2621,  2622,
       5,   393,   393,   269,   563,   527,   591,   469,     5,   432,
     267,   393,   269,  2437,   552,  2439,   241,    26,   372,  2857,
     428,    25,     5,  2447,   345,   472,  2450,   442,  1931,   393,
    2454,    20,   479,   393,   388,   140,   555,   432,   392,   432,
       5,     5,   432,   432,   432,   432,   432,   178,    14,   621,
       5,   460,   393,   211,   501,    26,   393,    26,   443,   506,
     393,   393,     5,   369,   620,  2489,  2490,   332,    40,    41,
      42,    43,    44,    45,   432,  2499,   430,   393,  2502,    26,
     375,   393,   570,  2507,   241,   393,  3235,   432,  3237,   393,
     347,   345,   393,   242,   627,   393,  2520,   460,  2522,   393,
    2524,   393,  2526,   393,   458,   393,   548,   666,  2532,   432,
     393,  2535,   442,  3400,    64,   621,  2540,    14,  3271,   240,
    2544,  2545,   476,   240,     7,    26,   627,    99,    26,   449,
     627,   393,   432,   393,  3085,   621,  2560,  3371,  3372,  3373,
    3374,  3375,  3376,  2567,   393,  2569,   403,   394,   627,   577,
    2975,  2575,  2576,  2577,  2578,  2579,  2580,   393,  3082,   428,
     432,     5,     5,   393,  2588,    25,   242,   393,     5,   393,
     427,   393,   393,   393,   305,   393,   393,  2601,  2539,  2603,
     311,   312,   313,  2447,  3455,   442,  2089,  2207,  2489,  1282,
    1915,    38,    40,   372,  2149,  2619,  2520,  2155,   290,   143,
     331,   147,   284,   211,   558,   405,  1706,   291,  2632,  1707,
    2434,   213,   360,  2107,  2638,  2639,  2640,  2641,  2642,  2643,
     477,   323,  2818,  2789,  2974,   379,   483,   322,   485,  2653,
    2654,  2655,   489,  1640,  3445,   492,  1830,  2661,   495,   391,
      74,    75,   393,    77,    78,    79,  2124,  1777,   505,  3087,
     537,  2020,  2013,  1873,  2139,   988,  1632,  2592,  2892,  1942,
    1635,  3498,  2143,  2262,  1959,  3099,  1183,   524,    25,   120,
     624,    31,  2996,    31,   531,   532,   533,  1920,  1926,   495,
     537,   269,  2590,  3432,   700,  1640,   670,  1929,   545,    18,
      19,    20,    21,  2489,  2490,  2993,  3134,  3198,  2722,   952,
    2724,   432,  1174,  3254,   561,   562,   563,   564,  3462,   440,
    2734,  2735,   443,  2737,  1240,  2576,  2740,  2712,  2742,  3208,
     451,  2710,  2387,  2747,  2748,  2749,  1164,   904,  1091,  2694,
    2233,  1044,  2133,  1744,  1264,  1721,  2532,  2325,  3473,  2535,
    3436,  2357,  3324,   177,  2746,  2388,  3056,  2041,  2544,  2545,
     300,   185,  2776,  2722,  2782,   486,  2780,  2781,  3511,  2391,
    2724,   333,  3018,  3342,    93,    94,    95,    96,    97,    98,
    2794,  1659,  3030,    17,   346,  2405,  2655,   984,  3246,  2923,
    2633,  2780,  3247,  3434,  2575,   219,  1654,  3291,   980,  2922,
     521,  3160,  2816,  1627,   228,  2819,  2820,  3179,  3168,  2071,
    2824,  1179,   370,  2827,    -1,    -1,    -1,  2831,   358,    -1,
     541,   542,    -1,    -1,  2638,  2639,  2640,  2641,    -1,    -1,
     370,   552,  2846,   257,   258,    -1,   557,    -1,    -1,    -1,
      -1,   381,    -1,  2857,    -1,    -1,    -1,    -1,  2341,   411,
    2864,    -1,    -1,    -1,    -1,    -1,   418,    -1,  2872,   399,
      -1,  2875,  2876,  2877,  2878,  2879,    -1,    -1,    -1,   409,
      -1,    -1,   412,    -1,    -1,   596,    -1,    -1,   302,    -1,
      -1,    35,    -1,    -1,    -1,   425,    -1,    -1,    -1,   736,
      -1,    -1,  2906,    -1,    -1,   457,    -1,    -1,    -1,  2913,
    2393,    -1,    -1,    -1,    -1,    -1,    -1,   628,  2922,    -1,
    2924,  2925,    -1,    -1,  2928,    -1,  3181,    -1,    -1,   481,
     344,    -1,    -1,    -1,    -1,  2939,    -1,    -1,    -1,   491,
     492,    -1,    -1,   473,  1931,   497,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,   507,    -1,    -1,  2962,    -1,
    2964,    -1,    -1,    -1,  3382,   109,   110,   111,    -1,   806,
      -1,    -1,    -1,   503,    -1,    -1,    -1,   529,  3181,    -1,
     532,   533,    -1,   513,    -1,    -1,   538,   401,    -1,  1693,
    1694,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   534,    -1,    -1,   537,    -1,   539,
      -1,  3015,   849,    -1,  3018,    -1,    -1,  3021,  2794,    -1,
    3024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,   866,
     867,    -1,   869,    -1,   871,   872,    -1,   567,    -1,    -1,
     877,   878,    -1,   595,    -1,    -1,   576,    -1,  2035,    -1,
      -1,    -1,  3056,    -1,   606,  2042,  3060,    -1,  3062,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2846,    -1,    -1,    -1,    -1,  3493,    -1,    -1,  3082,   916,
      -1,    -1,  3277,  3087,    -1,    -1,  2569,    -1,    -1,    -1,
     927,    -1,  2575,  2576,  2577,  2578,  2579,  2580,    -1,    -1,
      -1,    -1,  2089,    -1,    -1,    -1,   250,    -1,    -1,   253,
      -1,    -1,    -1,    -1,   951,   952,    -1,    -1,    -1,    -1,
    2924,  2925,  3126,    -1,  2928,    -1,   963,    -1,    -1,    -1,
    3134,    -1,    -1,    -1,    -1,    -1,  2619,    -1,    -1,    -1,
      -1,    -1,   979,   980,    -1,  3149,    -1,    -1,  3152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3160,    -1,  3162,    -1,
      -1,    -1,    -1,    -1,  3168,  3169,    -1,  3171,  3172,  3173,
    3174,    -1,    -1,  3177,    -1,  3179,  3180,    -1,  3182,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3190,    -1,    -1,    -1,
      -1,    -1,    -1,  1897,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3015,    -1,    -1,  3018,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,    -1,    -1,    -1,   372,    -1,
      -1,  3235,    -1,  3237,  1938,    -1,  3240,  2224,  2225,    -1,
      -1,  3245,    -1,  3247,   388,     9,  2233,    -1,   392,    -1,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,  2742,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   430,  3291,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3299,    -1,  2780,    -1,  3303,
      -1,    65,  3306,  3307,  3308,  3309,  3310,    -1,    -1,    -1,
      -1,    -1,    -1,  1150,   458,    -1,    -1,    -1,    -1,    -1,
    3324,    -1,    -1,    -1,    -1,  1162,    -1,  1164,  1165,  1166,
      -1,    -1,   476,    -1,    -1,    -1,  1173,  1174,  3342,    -1,
    1177,    -1,  3346,    -1,  1181,  2332,    -1,  1184,    -1,    -1,
      -1,    -1,  3356,    -1,  2341,    -1,    -1,    -1,  3162,    -1,
    1197,    -1,    -1,    -1,  3168,  3169,    -1,  3171,  3172,  3173,
    3174,    -1,    -1,    -1,    -1,    -1,  3180,    -1,  3382,  3383,
      -1,  2864,    -1,  3387,    -1,    -1,    -1,    -1,    -1,  2872,
      -1,    -1,  2875,  2876,  2877,  2878,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2391,  1242,  2393,  3411,    -1,  3213,
      -1,    -1,    -1,    -1,   558,  3419,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,  3432,    -1,
    3434,    -1,  3436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1277,    -1,    -1,    32,    -1,    -1,    -1,  2434,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,  3473,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3493,
      -1,    80,    81,    -1,    -1,    -1,    -1,  2201,  2202,  3303,
      -1,    90,  3306,  3307,  3308,  3309,    -1,    -1,  2212,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,  3342,    -1,
       5,  3024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,  2267,  2268,  2269,  2270,    -1,    -1,    -1,
      -1,  2275,  2276,  2277,  2278,    -1,    -1,    -1,  2282,    -1,
      -1,    -1,  2569,    -1,    -1,    -1,    -1,    -1,  2575,  2576,
    2577,  2578,  2579,  2580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3411,    -1,    -1,
      -1,  3387,    -1,    -1,    -1,  3419,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,  2619,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3126,    35,    -1,    -1,    -1,   412,    -1,
      -1,  2638,  2639,  2640,  2641,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2366,  2367,    -1,   429,  3149,    -1,   432,  2373,
    2374,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,    -1,    -1,    -1,  2672,  2673,  2674,   191,  2676,
    2677,  2678,  2679,  2680,  2681,    -1,    -1,    -1,  2685,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,   472,    -1,
      -1,   300,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
     111,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     319,    -1,    -1,   497,    -1,  2722,    -1,  2724,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,  2734,  2735,    -1,
    2737,    -1,    -1,  2740,    -1,  2742,    -1,  3240,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   358,
      -1,    -1,    -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   381,  2780,    -1,    -1,   261,    -1,    -1,    -1,
      -1,    -1,  1639,  1640,    -1,    -1,  2510,  2511,    -1,    -1,
     399,    -1,    -1,    -1,   578,  2519,  3299,    -1,    -1,    -1,
     409,    -1,    -1,    -1,    -1,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   300,   425,    -1,   602,   603,
      -1,    -1,    -1,    -1,  2548,  2549,   610,    -1,    -1,   613,
      -1,    -1,    -1,    -1,   319,  2842,    -1,   621,  1695,   250,
      -1,    -1,   253,  3346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,  2864,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2872,    -1,    -1,  2875,  2876,
    2877,  2878,    -1,   358,   397,    -1,    -1,    -1,  2602,   488,
    2604,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,   412,
      -1,    -1,    -1,  1750,   503,    -1,   381,    -1,    -1,    -1,
      -1,   510,    -1,    -1,   513,    -1,   429,    -1,    -1,   432,
      -1,    -1,    -1,    -1,   399,    -1,    -1,  2924,  2925,    -1,
      -1,  2928,   445,    -1,   409,   534,    -1,    -1,   537,    -1,
     539,  3434,    -1,    -1,    -1,    -1,    -1,    -1,  2662,  2663,
     425,    -1,  2666,  2667,    -1,    -1,    -1,    -1,    -1,   558,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   372,   485,    -1,    -1,    -1,    -1,   576,    -1,    -1,
    3473,    -1,    -1,    -1,   497,    -1,  2700,   388,    -1,    -1,
     465,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   488,    -1,    -1,    -1,    -1,  3015,   618,
      -1,  3018,    -1,    -1,  3021,    -1,   539,  3024,   503,   430,
      -1,    -1,    -1,    -1,    -1,   510,    -1,    -1,   513,  1886,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1894,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,  1905,   534,
      -1,    -1,   537,    -1,   539,   578,    -1,    -1,    -1,    -1,
      -1,    -1,   671,    -1,    -1,   476,    -1,   590,    -1,  1926,
      -1,    -1,    -1,   558,    -1,    -1,    -1,    -1,  1935,   602,
     603,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,
     613,   576,    -1,  2817,    -1,    -1,    -1,  2821,   621,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2834,    -1,  1969,  1970,  1971,    -1,    -1,    -1,  1975,  3126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2853,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3149,    -1,    -1,    -1,    -1,   558,    -1,    -1,
    2007,    -1,    -1,    -1,    -1,  3162,    -1,    -1,    -1,    -1,
      -1,  3168,  3169,    -1,  3171,  3172,  3173,  3174,    -1,    -1,
      -1,    23,    -1,  3180,    -1,  3182,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3213,    -1,    -1,    -1,
      -1,    63,    -1,   624,    -1,    -1,  2073,  2074,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,  3240,    -1,    -1,    -1,    -1,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2134,    -1,  2136,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,  2145,    -1,
      -1,    -1,  3299,    -1,    -1,    -1,  3303,    -1,    -1,  3306,
    3307,  3308,  3309,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,   164,    -1,    -1,   167,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,    -1,  2182,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3342,    -1,    -1,    -1,  3346,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,  3356,
     202,    -1,    -1,    -1,  2211,    -1,    -1,    -1,    -1,   211,
      -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,   235,    -1,    -1,    -1,   239,   240,   241,
     242,    -1,    -1,  3117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,    -1,  3411,    -1,    -1,    -1,    -1,    -1,
      -1,  3135,  3419,    -1,    -1,    -1,    -1,    -1,    -1,   271,
      -1,    -1,   274,    -1,   276,    -1,    -1,  3434,    -1,    -1,
      -1,   283,    -1,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   306,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,   253,    -1,    -1,  3473,    -1,    -1,    -1,
      -1,    -1,    -1,   325,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,    -1,
      -1,    -1,    99,    -1,    -1,    -1,   348,    -1,    -1,    -1,
     352,    -1,    -1,    -1,  3511,    -1,    -1,  2364,    -1,   361,
     362,   363,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,  3275,    -1,     5,     6,     7,     8,    35,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   431,
      -1,    -1,   372,    35,    -1,    -1,  2443,    -1,    -1,    -1,
     442,    -1,    -1,    -1,    -1,    -1,    -1,   204,   388,    -1,
      -1,    -1,   392,    -1,    -1,  3329,  3330,    -1,  3332,    -1,
    3334,  3335,    -1,    -1,    -1,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     482,   109,   110,   111,    -1,    -1,  2493,    -1,    -1,    -1,
     430,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   260,    -1,     9,    -1,   109,   110,   111,
      -1,    -1,    -1,    -1,    18,    19,    20,    -1,   458,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,   285,    -1,
    2537,    -1,  2539,    -1,  2541,    -1,   476,   294,    -1,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,  2554,    -1,  3423,
      -1,  3425,  2559,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   330,    -1,    -1,   333,    -1,   580,    -1,
      -1,   338,  2589,  2590,    -1,    -1,    18,    19,    20,   346,
      -1,    -1,    24,    25,    26,    27,    -1,  3471,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2613,  2614,    -1,    -1,
      -1,    -1,    -1,  3487,  3488,    -1,    -1,  3491,   558,    -1,
    3494,    -1,   250,    -1,   626,   253,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    -1,   640,   641,
     642,   643,   644,   645,   646,    -1,   648,   649,   250,  2656,
      -1,   253,    -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,   665,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   624,    -1,    -1,   191,    -1,  2696,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     457,    -1,  2709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   481,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   491,   492,    -1,    -1,    -1,    -1,
     497,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
     388,    -1,    -1,    -1,   392,    -1,  2773,    -1,    -1,    -1,
     372,    -1,   529,    -1,    -1,   532,   533,    -1,    -1,    -1,
      -1,   538,    -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,
     392,   295,    -1,    -1,    -1,    -1,  2803,    -1,    -1,    -1,
      -1,    -1,   430,    -1,    -1,    -1,   261,    -1,    -1,    -1,
      -1,  2818,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2833,    -1,   430,    -1,
     458,    -1,    -1,    -1,    -1,  2842,    -1,    -1,   595,    -1,
      -1,    -1,    -1,    -1,    -1,   300,    -1,   604,   476,   606,
      -1,    -1,    -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,
      -1,    -1,    -1,   295,   319,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,   476,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,   358,    -1,    -1,    -1,    -1,   412,    -1,
      -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   429,   381,    -1,   432,    -1,
     558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,    -1,    -1,   399,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   409,    -1,   558,    -1,    93,    94,
      95,    96,    97,    98,    -1,   397,    -1,    -1,    -1,    -1,
     425,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
     412,   485,    -1,    -1,    -1,    -1,  2993,    -1,    -1,    -1,
      -1,    -1,    -1,   497,    -1,    -1,   624,   429,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     465,    -1,   444,   445,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   488,    -1,   539,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   503,    -1,
      -1,    -1,    -1,   485,    -1,   510,    -1,    -1,   513,    -1,
      -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   578,    -1,    -1,    -1,  3085,   534,
      -1,    -1,   537,    -1,   539,    -1,   590,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   602,   603,
      -1,    -1,    -1,   558,    -1,    -1,   610,   539,    -1,   613,
      -1,    -1,    -1,    -1,    -1,   250,    -1,   621,   253,    -1,
      -1,   576,    -1,    -1,    -1,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    14,    -1,  3143,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,   578,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,   590,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
     602,   603,    -1,    -1,    -1,    -1,    -1,  3184,   610,    -1,
      -1,   613,    -1,    63,    -1,    -1,    -1,    -1,    -1,   621,
      -1,  3198,    72,    -1,    -1,    -1,  3203,    -1,  3205,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      90,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,   109,
     110,   111,   112,    -1,    -1,   115,   116,   372,    -1,  3246,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3254,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,   392,   393,    -1,
      -1,    -1,    -1,    -1,  3271,    -1,    -1,    -1,    -1,    -1,
    3277,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,   178,    -1,
      -1,    -1,    -1,    -1,   184,    -1,    -1,    -1,    -1,    -1,
     190,   191,    -1,   193,    -1,    -1,    -1,    -1,    -1,   199,
      -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3371,  3372,  3373,  3374,  3375,  3376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   275,    -1,    -1,    -1,    -1,
      -1,   281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     290,   291,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,
     300,   301,    -1,   558,    -1,   305,    -1,    -1,    -1,    -1,
      -1,   311,   312,    -1,    -1,    -1,    -1,    -1,   318,   319,
     320,   321,   322,   323,    -1,    -1,    -1,   327,    -1,    -1,
      -1,   331,    -1,   333,    -1,    -1,    -1,    -1,    -1,    -1,
     340,   341,   342,   343,    -1,   345,   346,    -1,    -1,    -1,
     350,   351,    -1,   353,   354,   355,   356,   357,   358,   359,
     360,    -1,    -1,    -1,    -1,    -1,   366,   367,   368,   624,
     370,   371,    -1,    -1,    -1,   375,   376,   377,   378,   379,
     380,   381,   382,   383,  3511,   385,    -1,    -1,    -1,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,    -1,   428,   429,
      -1,    -1,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,    -1,    -1,
     460,   461,   462,   463,   464,   465,   466,   467,   468,    -1,
     470,   471,   472,   473,    -1,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,    -1,   512,   513,   514,   515,   516,   517,    -1,    -1,
     520,   521,    -1,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
      -1,    -1,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,    -1,    -1,    -1,    -1,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   639,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,    -1,    -1,
      -1,    -1,   652,    -1,    -1,    -1,   656,    -1,    -1,   659,
     660,   661,   662,    -1,    -1,   665,   666,    -1,   668,   669,
     670,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,
      -1,   105,   106,    -1,    -1,   109,   110,   111,   112,    -1,
      -1,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
     184,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   275,    -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   290,   291,    -1,    -1,
      -1,    -1,    -1,   297,    -1,    -1,   300,   301,    -1,    -1,
      -1,   305,    -1,    -1,    -1,    -1,    -1,   311,   312,    -1,
      -1,    -1,    -1,    -1,   318,   319,   320,   321,   322,   323,
      -1,    -1,    -1,   327,    -1,    -1,    -1,   331,    -1,   333,
      -1,    -1,    -1,    -1,    -1,    -1,   340,   341,   342,   343,
      -1,   345,   346,    -1,    -1,    -1,   350,   351,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,    -1,    -1,    -1,
      -1,    -1,   366,   367,   368,    -1,   370,   371,    -1,    -1,
      -1,   375,   376,   377,   378,   379,   380,   381,   382,   383,
      -1,   385,    -1,    -1,    -1,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,    -1,   428,   429,    -1,    -1,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,    -1,    -1,   460,   461,   462,   463,
     464,   465,   466,   467,   468,    -1,   470,   471,   472,   473,
      -1,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,    -1,   512,   513,
     514,   515,   516,   517,    -1,    -1,   520,   521,    -1,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,    -1,    -1,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
      -1,    -1,    -1,    -1,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   639,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   647,    -1,    -1,    -1,    -1,   652,    -1,
      -1,    30,   656,    -1,    -1,   659,   660,   661,   662,    -1,
      39,   665,   666,    -1,   668,   669,   670,    46,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,   104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   118,
      -1,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      -1,   130,   131,   132,   133,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,   142,    -1,   144,   145,   146,    -1,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,   157,    -1,
     159,    -1,   161,   162,    -1,    -1,   165,   166,    -1,    -1,
     169,   170,   171,    -1,   173,   174,    -1,    -1,    -1,   178,
     179,   180,    -1,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,   198,
      -1,    -1,   201,    -1,   203,    -1,   205,    -1,   207,    -1,
     209,   210,    -1,   212,   213,   214,    -1,    -1,    -1,   218,
      -1,   220,   221,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,    -1,    -1,   247,   248,
      -1,    -1,   251,   252,    -1,    -1,   255,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,   266,    -1,   268,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   278,
     279,   280,    -1,   282,    -1,    -1,    -1,   286,   287,    -1,
      -1,    -1,   291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   307,   308,
     309,    -1,    -1,    -1,    -1,    -1,   315,   316,    -1,    -1,
      -1,    -1,   321,    -1,    -1,   324,    -1,    -1,    -1,   328,
     329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     339,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   357,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,
      35,    -1,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   395,    -1,    -1,    -1,
      -1,    -1,    -1,   402,    -1,   404,   405,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   452,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,    -1,    -1,
      -1,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   494,   495,    -1,    -1,    -1,
     499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,   517,   518,
     519,   520,    -1,    -1,    -1,   524,    -1,    -1,    -1,   528,
      -1,    -1,    -1,    -1,    -1,    -1,   535,   536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,    -1,
     549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,   562,    -1,    -1,   565,    -1,    -1,    -1,
      -1,    -1,   571,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   597,    -1,
      -1,   600,    -1,    -1,    -1,    -1,   605,    -1,    -1,   608,
     609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,
      -1,   630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   653,   654,   655,   656,   657,   658,
     659,    -1,    -1,   662,    -1,   664,    -1,   666,    -1,    -1,
      -1,    -1,    -1,   672,   673,   674,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,    -1,   392,   393,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,   430,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,    35,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   558,    -1,    35,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,    35,   253,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,   624,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,   250,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   388,    -1,    -1,    -1,   392,   393,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,   250,    -1,    -1,   253,    -1,    93,
      94,    95,    96,    97,    98,   372,    35,    -1,    -1,    -1,
      -1,    -1,    -1,   430,    -1,   109,   110,   111,    -1,    -1,
     250,   388,    -1,   253,    -1,   392,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,   430,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
      -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   388,    -1,    -1,    -1,   392,   393,    -1,    -1,
      -1,   558,   372,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,   388,   253,
      -1,    -1,   392,   393,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,
      -1,   558,   392,   393,    -1,    -1,    -1,    18,    19,    20,
     430,    -1,   458,    24,    25,    26,    27,   624,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     476,   250,    -1,    -1,   253,    -1,    -1,    -1,   458,    -1,
     430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    20,   476,    -1,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   624,   458,    -1,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,   476,    -1,   372,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      65,    -1,    -1,    -1,   388,    -1,    -1,    -1,   392,   393,
      -1,    -1,   558,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,   558,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   430,    35,    -1,    -1,
      -1,    -1,    -1,   372,    93,    94,    95,    96,    97,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   558,   388,
     109,   110,   111,   392,   458,    -1,    -1,    -1,   624,    -1,
     191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   624,    93,    94,    95,    96,    97,
      98,   430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   443,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   624,    -1,    -1,    -1,    -1,   458,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,   476,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,   558,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    35,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,   250,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   558,
     624,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,   250,    -1,    -1,   253,    -1,    93,    94,    95,
      96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,    -1,    -1,   109,   110,   111,   397,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,   412,    -1,    -1,    -1,   624,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,   429,    -1,
      -1,   432,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,
      60,    -1,   397,   372,   445,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    -1,   412,    -1,   388,
      -1,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   429,    -1,    -1,   432,    -1,    -1,
     100,    -1,    -1,   484,   485,    -1,    -1,    -1,    -1,    -1,
     445,    -1,    -1,    -1,   372,    -1,   497,    -1,    -1,    -1,
      -1,   430,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,
     388,   253,    -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   458,
     485,    -1,    -1,    -1,   250,    -1,    -1,   253,   539,    -1,
      -1,     9,   497,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      18,    19,   430,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,   443,    -1,    -1,    -1,    -1,
      -1,   191,    -1,   193,    -1,   250,    -1,   578,   253,    -1,
     458,    -1,    -1,    -1,   539,    -1,    -1,    -1,    -1,   590,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    65,   476,    -1,
      -1,   602,   603,    -1,    72,    -1,    -1,    -1,    -1,   610,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621,    -1,    -1,   578,    -1,    -1,    -1,    -1,    -1,   558,
     372,    -1,   100,    -1,    -1,   590,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   388,   602,   603,    -1,
     392,    -1,    -1,    -1,    -1,   610,   372,    -1,   613,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   621,    -1,    -1,    -1,
     290,    -1,   388,    -1,    -1,   295,   392,    -1,    -1,    -1,
     558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,    -1,    -1,    -1,    -1,   624,    -1,   372,    -1,    -1,
      -1,   443,    -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   388,   430,    -1,   458,   392,    -1,    -1,
      -1,    -1,    -1,   191,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   476,    -1,    -1,    -1,   358,    -1,
      -1,    -1,   458,    -1,    -1,    -1,   624,    -1,    -1,    -1,
     370,    -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   389,
      -1,    -1,    -1,    -1,   394,    -1,    -1,   397,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,   408,    -1,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,   424,    -1,    -1,    -1,    -1,   429,
      -1,    -1,   432,    -1,    -1,   435,   558,    -1,    -1,    -1,
      -1,    -1,   290,     9,   444,   445,    -1,   295,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,   558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   484,   485,    -1,    -1,    -1,   489,
      -1,    -1,    -1,    -1,    60,    -1,    -1,   497,    -1,    65,
      -1,    -1,   624,   558,    -1,    -1,    72,    -1,   508,    -1,
     358,    -1,    -1,    -1,   514,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,   624,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,   539,
      -1,   389,    -1,    -1,    -1,    -1,   394,    -1,    -1,   397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     408,    -1,    -1,    -1,    -1,    -1,   414,    -1,    -1,   624,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,   429,    -1,   583,   432,    -1,    -1,   435,    -1,    -1,
     590,    -1,   592,    -1,    -1,    -1,   444,   445,    -1,    -1,
      -1,    -1,   602,   603,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   621,    -1,    -1,    -1,   191,    -1,   193,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,    18,
      19,   489,    -1,    -1,    -1,    24,    25,    26,    27,   497,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     508,    -1,   510,    -1,    -1,    -1,   514,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    -1,    65,    -1,    -1,    -1,
      -1,   539,    -1,    72,    -1,    -1,    65,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,   100,    -1,    -1,   290,    -1,    -1,    -1,    -1,   295,
      -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,
      -1,    -1,   590,    -1,   592,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   602,   603,    -1,   323,    -1,    -1,
      -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   621,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   358,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   389,    -1,    -1,    -1,    -1,   394,    -1,
      -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,   414,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,
      -1,    -1,    -1,   429,    -1,    -1,   432,    -1,    -1,   435,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,   290,    -1,    -1,    -1,    -1,   295,    -1,   484,   485,
      -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   497,    -1,    -1,    -1,   250,    -1,    -1,   253,    -1,
      -1,    -1,   508,    -1,   323,    -1,    -1,    -1,   514,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    93,    94,    95,
      96,    97,    98,   539,    -1,    -1,   109,   110,   111,   358,
      -1,    -1,    -1,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     389,    -1,    -1,    -1,    -1,   394,    -1,   583,   397,    -1,
      35,    -1,    -1,    -1,   590,    -1,   592,    -1,   397,   408,
      -1,    -1,    -1,    -1,    -1,   414,   602,   603,    -1,    -1,
      -1,    -1,    -1,   412,   610,   424,    -1,    -1,    -1,    -1,
     429,    -1,    -1,   432,    -1,   621,   435,   372,    -1,    -1,
     429,    -1,    -1,   432,    -1,   444,   445,    -1,    -1,    -1,
      -1,    -1,    -1,   388,    -1,    -1,   445,   392,    93,    94,
      95,    96,    97,    98,    -1,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,   485,    -1,    -1,    -1,
     489,    -1,    -1,    -1,    -1,   430,   485,   250,   497,    -1,
     253,    -1,    -1,    -1,   250,    -1,    -1,   253,   497,   508,
      -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
     539,   476,    -1,    93,    94,    95,    96,    97,    98,    -1,
     539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,   578,
      -1,   590,    35,   592,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    -1,   602,   603,    -1,    -1,    -1,    -1,    -1,
      -1,   610,    -1,   602,   603,   250,    -1,    -1,   253,   372,
      -1,   610,   621,   558,   613,    -1,   372,    -1,    -1,    -1,
      -1,    -1,   621,    -1,    -1,   388,    -1,    -1,    -1,   392,
      -1,    -1,   388,    -1,    -1,    -1,   392,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,   430,    -1,    18,
      19,    20,    -1,    -1,   430,    24,    25,    26,    27,   624,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,
     250,    -1,    -1,   253,    -1,   458,    -1,    -1,    18,    19,
      -1,    -1,   458,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,   476,    -1,    -1,    65,    -1,    -1,    -1,
     476,    93,    94,    95,    96,    97,    98,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,
      -1,    -1,    -1,   388,    -1,    65,    -1,   392,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   558,    -1,   250,    -1,    -1,
     253,    -1,   558,    -1,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   458,    -1,    -1,    -1,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,   388,    -1,
      -1,   476,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   624,    -1,    -1,    65,    -1,    -1,    -1,   624,    -1,
     430,   191,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,   458,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,    -1,    -1,   558,    -1,    -1,   476,    -1,    -1,   372,
      -1,    -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,   432,
      -1,   191,    -1,    -1,    -1,   388,    -1,    -1,    -1,   392,
      -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,   624,
      -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     191,    -1,    -1,    -1,   497,    -1,    -1,    -1,   558,    -1,
     372,    -1,    -1,    -1,    -1,   458,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,
     392,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,
      -1,    -1,    -1,   412,   624,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   578,    -1,   397,    -1,    -1,
     429,    -1,    -1,   432,    -1,    -1,   458,   590,    -1,    -1,
      -1,    -1,   412,    -1,    -1,    -1,   445,    -1,    -1,   602,
     603,    -1,    -1,    -1,   476,   558,    -1,   610,    -1,   429,
     613,    -1,   432,    -1,    -1,    -1,    -1,    -1,   621,    -1,
      -1,    -1,    -1,    -1,    -1,   445,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   484,   485,   397,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   484,   485,    -1,    -1,    -1,   429,
      -1,   624,   432,    -1,    -1,    -1,    -1,   497,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   445,   558,    -1,    -1,    -1,
     539,    -1,    -1,    -1,    -1,    -1,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   412,   472,    -1,    -1,    -1,    -1,    -1,    -1,   539,
      -1,    -1,    -1,    -1,    -1,   485,    -1,    -1,   429,   578,
      -1,   432,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,
      -1,   590,    -1,    -1,   445,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   624,   602,   603,    -1,    -1,    -1,   578,    -1,
      -1,   610,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,
     590,    -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,   539,
      -1,    -1,   602,   603,   485,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,   613,    -1,    -1,   497,    -1,    -1,    -1,
      -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,
      -1,    -1,   602,   603,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   578,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   602,   603,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,    -1,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     621
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
     432,   688,   690,  1108,  1119,  1120,   460,    14,   818,   773,
     523,  1215,   774,   771,   776,    32,    80,    81,    90,   261,
     300,   319,   335,   358,   370,   381,   399,   409,   425,   465,
     488,   503,   510,   513,   534,   537,   539,   558,   576,   618,
     671,   780,   789,   800,   801,   955,   432,   113,   955,   765,
     916,  1096,   955,   828,   537,   778,   804,   806,   807,   805,
     814,   815,   432,   432,   827,   460,   432,   432,   771,   802,
     427,   688,    18,    19,    20,    21,    22,   689,    26,     5,
     428,  1119,    24,    25,    26,   621,   955,   961,    19,    25,
      26,   775,   961,   791,   778,   792,   804,   805,   432,   432,
     790,   460,   432,   432,   802,   771,   675,   676,   677,   779,
     799,   432,    26,   955,   432,  1064,   765,   765,   432,   955,
     432,   459,   784,   627,   367,   455,   471,   514,   554,   583,
     592,   808,   627,   367,   455,   471,   514,   554,   583,   592,
     816,    26,    26,   829,   830,   831,   832,   955,    26,   787,
     788,    26,    26,   621,   393,   688,  1120,   460,   428,    26,
      26,   771,   784,   771,    26,    26,   770,   787,    26,    26,
     621,   782,    59,   796,  1240,   393,   432,  1230,  1509,  1510,
    1511,  1512,  1513,   917,  1097,  1058,   621,    26,   809,   810,
     432,   811,   816,   817,   811,   432,   812,     5,   393,     5,
     393,     5,   284,     5,   821,   428,     5,     5,   393,   393,
     771,   803,  1119,   460,   621,    26,   259,     5,   393,     5,
     393,   284,   428,     5,   393,   393,   803,   625,   955,  1125,
    1126,  1128,  1075,  1125,   362,  1510,  1215,    39,    46,    55,
      67,    68,    70,    84,    91,   102,   103,   104,   118,   120,
     121,   122,   125,   128,   130,   132,   133,   139,   142,   144,
     145,   146,   154,   156,   157,   159,   161,   162,   165,   169,
     170,   171,   173,   174,   178,   179,   180,   182,   186,   188,
     189,   194,   198,   201,   203,   205,   207,   209,   210,   212,
     213,   214,   218,   220,   221,   223,   231,   232,   244,   247,
     248,   251,   252,   255,   256,   264,   265,   266,   268,   278,
     279,   280,   282,   286,   287,   291,   299,   307,   308,   309,
     315,   316,   321,   324,   328,   329,   339,   357,   365,   371,
     402,   404,   405,   413,   452,   463,   470,   494,   495,   499,
     511,   517,   518,   519,   520,   524,   528,   535,   536,   547,
     549,   560,   562,   565,   571,   597,   600,   605,   608,   609,
     623,   630,   653,   654,   655,   656,   657,   658,   659,   662,
     664,   666,   672,   673,   674,   681,   682,   683,   684,   701,
     723,   737,   738,   744,   745,   764,   834,   835,   836,   837,
     848,   849,   850,   851,   852,   853,   854,   906,   910,   941,
     962,   963,   966,   967,   968,   969,   982,   991,  1012,  1013,
    1015,  1019,  1034,  1035,  1039,  1040,  1041,  1042,  1050,  1065,
    1078,  1089,  1090,  1091,  1102,  1105,  1141,  1144,  1146,  1152,
    1153,  1156,  1159,  1162,  1164,  1166,  1169,  1176,  1181,  1185,
    1186,  1187,  1199,  1200,  1203,  1209,  1210,  1211,  1236,  1251,
    1252,  1253,  1254,  1255,  1260,  1266,  1267,  1285,  1288,  1318,
    1320,  1409,  1410,  1441,  1442,  1449,  1460,  1489,  1493,  1498,
    1500,  1502,  1506,  1507,  1514,   738,  1053,  1489,   626,   649,
    1098,  1099,  1125,    20,   393,   427,   785,   808,    26,   813,
      26,    26,    26,   830,   832,   824,   788,    26,   428,  1119,
      20,   785,   432,    26,    26,   781,    26,   795,   621,   393,
       5,  1125,   393,    25,  1108,  1163,   955,   350,   956,   957,
    1508,   955,   955,  1183,   950,   956,   950,    25,   191,   955,
    1117,  1484,  1485,  1486,   955,  1504,   955,  1262,  1263,   955,
      26,   685,  1108,  1258,   950,  1183,   880,    26,   961,  1223,
    1224,  1223,     9,    18,    19,    25,    26,    60,    65,    72,
     100,   193,   290,   295,   323,   358,   370,   389,   394,   397,
     408,   414,   424,   429,   432,   435,   444,   445,   485,   489,
     497,   508,   514,   539,   583,   590,   592,   602,   603,   610,
     855,   862,   863,   864,   865,   866,   867,   868,   869,   881,
     886,   897,   898,   899,   900,   955,   961,  1108,  1218,  1287,
    1400,   857,   880,   956,  1450,  1450,   838,  1183,   950,  1256,
    1108,   952,   956,   862,  1450,  1108,  1183,  1108,  1286,  1450,
      25,   587,  1092,  1093,  1108,   950,   950,  1092,   951,   956,
     955,  1093,   950,  1450,   950,   952,  1108,  1139,  1140,   948,
     956,   952,   376,   563,   668,   947,   955,  1014,   955,   746,
     953,   956,    25,  1319,  1484,   880,   880,   956,  1165,   911,
     129,   138,   147,   152,   196,   204,   260,   285,   292,   294,
     304,   330,   338,   376,   402,   440,   451,   550,   551,   552,
     563,   666,  1028,  1160,  1161,  1108,   861,   862,  1175,   947,
    1499,  1499,   949,   956,   880,  1163,  1237,  1108,  1214,    25,
    1108,  1444,   862,  1205,  1206,  1207,  1216,  1217,   862,  1494,
     105,   155,   193,   290,   366,   408,   475,   539,   702,   886,
     955,  1108,  1246,   725,   862,   948,  1491,  1079,   862,   948,
      26,  1108,  1036,   948,   862,  1461,   862,  1223,   955,   964,
     965,   952,   964,  1499,   952,   964,  1499,   970,   964,    25,
      26,   386,   488,   961,  1017,  1108,  1127,  1129,  1108,  1108,
    1108,    66,   275,   345,   391,   570,   650,   651,   652,   661,
     692,   972,   974,   976,   978,   980,  1103,  1104,  1107,   336,
     347,   400,   415,   504,  1321,   641,   642,   919,   920,   921,
     955,  1100,   648,  1099,   393,   303,   393,   393,   393,   393,
     625,     5,   393,   428,   303,   771,   793,   794,   393,   393,
     625,   393,   955,  1241,  1128,   393,  1231,    57,    58,    85,
      86,    87,   456,   543,   586,  1268,  1269,  1270,  1273,  1276,
    1279,  1280,  1281,  1282,   432,   621,  1486,  1118,   618,  1157,
     621,     8,   540,   589,     5,   393,   428,    25,   955,  1393,
     480,  1184,  1127,   109,   110,   111,   855,   855,   855,   432,
     527,  1235,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   855,   367,   455,   471,   514,   554,   583,   592,  1403,
    1404,   432,   432,   432,   855,   855,   432,   432,   762,   855,
     432,   870,   432,   432,   432,   432,   432,   432,   432,   432,
       6,     7,     8,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    35,    93,    94,    95,
      96,    97,    98,   109,   110,   111,   250,   253,   372,   388,
     392,   430,   458,   476,   558,   624,   761,   856,   871,   873,
     874,   875,   876,   877,   878,   879,    26,   961,   432,   522,
     422,   484,   858,   859,   862,  1108,  1134,  1393,   691,   692,
     841,   267,    88,    89,   627,   461,     5,   620,   627,   619,
     619,  1142,   597,   422,     5,   558,   992,   461,   660,  1496,
     432,   460,   621,   660,   386,   748,  1108,   548,   619,  1147,
    1148,  1149,   327,  1317,   860,   862,   860,     8,   949,    26,
     502,   556,   670,   942,  1108,   942,   942,   942,    25,   178,
     305,   311,   312,   313,   331,   440,   443,   451,   486,   521,
     541,   542,   552,   557,   596,   628,  1032,  1033,   942,   942,
     598,  1029,   692,  1029,  1029,   943,   943,  1029,  1029,   692,
       5,   334,   387,     5,   691,     5,    82,    83,   541,   628,
    1020,   663,  1497,   861,   614,   615,   616,   617,  1213,  1215,
     385,  1250,  1215,  1207,     5,   619,  1208,   862,   432,   432,
     432,   432,    25,   721,   955,   432,  1444,   345,   432,   522,
     591,   580,   726,   733,   724,    25,  1094,  1108,  1201,     8,
    1204,    14,   955,  1113,  1121,  1122,  1124,  1132,  1133,  1177,
     163,   345,   546,   579,     5,     6,     7,     8,     9,    10,
      12,    13,    14,    18,    19,    20,    21,    22,    23,    33,
      45,    63,    72,    90,    92,   100,   105,   106,   109,   110,
     111,   112,   115,   116,   155,   178,   184,   191,   193,   199,
     224,   262,   275,   281,   290,   291,   297,   300,   301,   305,
     311,   312,   318,   319,   320,   321,   322,   323,   327,   331,
     333,   340,   341,   342,   343,   345,   346,   350,   351,   353,
     354,   355,   356,   357,   358,   359,   360,   366,   367,   368,
     370,   371,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   385,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     428,   429,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   470,   471,   472,   473,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   512,   513,   514,   515,
     516,   517,   520,   521,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   639,   647,   652,   656,   659,   660,
     661,   662,   665,   666,   668,   669,   670,  1462,  1463,  1464,
    1466,   577,     5,   660,   660,   860,  1127,  1134,  1016,   422,
       5,   151,   996,   432,  1108,   860,   432,    26,    26,    66,
    1106,    25,  1108,  1448,  1448,   956,  1301,  1165,   949,   119,
     222,   230,   236,   238,   249,   277,   293,   298,   310,   317,
     472,   479,   501,   506,  1289,  1290,  1298,  1308,  1309,  1315,
    1316,  1322,  1323,  1332,  1351,  1355,  1420,  1421,  1451,  1452,
    1455,  1456,  1468,   922,   923,    92,   918,   929,   930,   921,
    1101,  1509,  1059,   460,   821,   788,   460,     5,   393,   795,
     765,  1076,   765,   158,   297,   374,   432,   477,   493,  1338,
    1350,   432,   955,  1284,    26,   246,   259,   432,   477,   493,
     955,  1265,  1278,  1336,  1337,  1342,  1344,  1346,   432,   955,
    1275,   432,  1265,  1271,     5,    25,   958,  1111,  1486,  1484,
     578,   618,  1158,    20,   955,  1138,  1487,   955,  1505,  1263,
     597,   621,   591,   432,   432,   841,  1499,   855,   947,   947,
    1499,  1499,   472,  1424,   855,    25,    26,    19,    24,    25,
      26,   901,   902,   903,   904,   855,   432,   627,  1499,    20,
     855,   393,  1424,   855,    20,  1218,   889,   887,   893,   855,
     891,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   432,   855,   855,   432,   882,   955,  1108,
       5,   627,   432,  1484,    25,   960,  1182,  1182,  1444,  1092,
     862,   862,   862,   944,   945,   432,  1108,  1140,   802,   993,
     994,   627,  1444,  1499,  1497,   955,   688,    20,   668,   955,
    1014,  1108,   747,   626,   862,   351,  1151,   558,  1150,     5,
      69,    71,    73,   619,   627,   833,  1127,   912,    18,    19,
     432,  1030,  1032,  1161,   943,   862,   345,   597,   947,    26,
      26,   691,   153,  1212,   219,  1217,  1223,  1495,   955,    25,
     905,   947,  1499,   591,   947,   624,  1108,   706,   955,   955,
     862,   340,   729,   733,   580,   727,   735,    23,   235,  1081,
    1085,   483,   880,   483,  1202,   862,   459,  1118,   621,     5,
    1037,   548,  1178,  1108,  1465,  1467,   190,  1463,   983,   965,
    1499,  1499,   975,   976,   996,   996,    34,    36,    37,    38,
     271,   274,   276,   296,   306,   348,   352,   431,   995,   997,
     998,  1024,  1108,  1129,   548,   693,    26,   401,   981,   322,
    1443,  1443,   136,   137,   438,   548,   955,  1352,  1353,  1394,
     802,  1393,  1393,  1291,   802,   955,  1453,  1453,   360,   477,
     587,  1432,  1393,  1299,   168,   440,   451,   472,   479,  1325,
    1326,  1327,   288,   289,  1415,  1509,  1509,   386,   931,  1108,
     643,   644,   924,   925,   926,   482,   626,   645,   646,   665,
     934,   935,  1509,   765,    26,   786,   786,   794,  1242,   765,
    1232,  1340,  1393,  1283,  1350,   432,  1283,   432,   432,  1277,
    1278,   432,   432,    64,   300,   358,   370,   381,   399,   409,
     412,   425,   473,   503,   513,   534,   537,   539,   567,   576,
    1385,  1386,  1387,  1389,  1274,  1275,  1271,  1272,   665,  1269,
     393,   621,  1444,   578,   460,   548,  1503,   686,   687,   955,
     955,   955,  1259,   880,   393,   393,   393,   393,   393,  1432,
     393,   393,   393,   393,   591,   902,    19,    26,   591,   393,
     393,    26,  1404,   393,   393,   393,   393,     5,   763,   393,
     855,   855,   855,   393,   855,   393,   393,   393,   443,   443,
     443,   880,  1424,   443,   880,  1424,   718,   719,   720,   855,
     432,   858,   955,  1257,   618,  1154,   627,     5,     5,     5,
     581,   862,   621,     5,   484,   627,   393,   428,   432,   626,
     164,   167,   271,   274,   749,   752,   753,  1024,   750,   751,
     955,   432,   956,   650,   651,  1155,   862,   955,   955,   945,
     946,   510,  1499,   841,     8,   914,    26,    26,  1031,  1032,
    1108,   537,  1170,    66,   855,  1215,    26,  1108,  1509,     5,
       5,     5,   393,   393,   722,   955,   393,  1444,   718,   432,
     432,   734,   730,   361,   728,   862,   340,   731,   735,   598,
    1026,  1086,  1082,   363,  1080,  1081,   860,   627,  1114,    20,
     955,  1123,  1133,    14,    18,    19,    20,    25,    26,    65,
     397,   412,   429,   432,   445,   484,   485,   497,   539,   578,
     590,   602,   603,   610,   613,   955,   961,  1179,  1180,  1399,
    1401,  1431,  1436,  1437,  1438,  1485,  1488,  1488,  1108,  1130,
    1131,  1509,   977,   978,   552,   954,   548,  1007,  1006,  1009,
    1008,   947,  1010,   947,  1011,  1005,  1004,  1002,  1001,  1025,
     325,   998,  1003,  1499,    40,    41,    42,    43,    44,    45,
      99,   333,   346,   411,   418,   457,   481,   491,   492,   497,
     507,   529,   532,   533,   538,   595,   606,   694,   695,  1022,
    1023,     5,    26,  1444,   249,  1108,   472,  1425,  1426,  1444,
    1165,  1419,  1421,   101,   101,   597,  1163,  1354,  1355,   432,
    1333,   150,   527,  1359,  1366,  1393,   175,   272,  1457,   621,
     627,  1422,  1469,   342,   351,   376,   379,   397,   502,   556,
     563,   949,  1302,  1307,   432,  1328,   626,     5,    25,   955,
    1416,  1417,   933,  1108,     5,   548,   927,   928,   640,   926,
     932,   955,   932,   936,   937,   932,   325,   935,  1060,   428,
     428,   462,  1225,  1245,  1077,   462,  1188,  1219,   432,     5,
     393,     9,   295,   432,   444,  1369,  1370,  1371,  1372,  1373,
    1377,  1381,  1383,  1436,   393,   613,   955,  1339,  1341,  1393,
    1396,  1397,  1343,  1396,     5,   393,  1343,  1369,   367,   455,
     471,   514,   554,   583,   592,  1406,  1406,   432,   432,   432,
     432,   432,   432,   208,   401,  1345,  1347,     5,   393,     5,
     393,   955,  1487,     8,  1444,  1119,   862,     5,  1264,  1265,
     880,  1066,  1433,  1434,  1436,   895,  1404,   895,    26,    26,
     591,    24,    26,   805,   896,  1235,   393,  1235,   806,   393,
    1235,   890,   888,   894,  1235,   892,  1235,  1235,  1235,    25,
      25,    25,   855,   872,   393,    25,   872,   393,   883,     5,
     884,   621,  1264,   578,  1444,  1444,   862,   862,   944,   510,
     862,  1501,     5,    20,  1396,   994,  1444,   621,   955,   750,
     758,   757,   759,   955,   959,   760,   959,   192,   753,   756,
       5,   996,   621,   862,     8,   955,   880,   555,  1305,     5,
     393,  1108,     5,   326,    25,  1247,   947,   345,   345,   460,
     621,   345,   432,   707,   711,   704,  1509,  1509,   736,   732,
     728,  1027,    25,   954,  1087,  1108,  1509,   862,   427,   460,
     880,  1437,  1437,  1402,  1406,   472,  1436,   432,   432,   432,
     432,   432,   432,   432,   955,   432,     5,    18,    19,    20,
      21,    93,    94,    95,    96,    97,    98,  1458,   422,   422,
       5,   984,   979,   980,    26,   691,   955,  1509,  1509,  1509,
    1509,     5,   999,     5,  1000,  1509,  1509,  1509,  1509,  1030,
    1509,   954,    25,    14,    14,     5,   393,    26,  1393,  1432,
    1413,   597,   597,  1290,  1418,  1419,  1355,  1334,  1396,   618,
     949,  1369,   432,  1294,   955,  1454,  1453,  1433,    49,    50,
      51,    52,    53,   585,  1472,   862,   862,  1300,   949,  1329,
    1396,  1393,  1327,   621,   621,     5,     5,  1108,   932,  1509,
    1509,     5,   939,   940,  1509,  1509,   938,  1053,   825,   783,
      74,    75,    77,    78,    79,   177,   185,   219,   228,   257,
     258,   302,   344,   401,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,  1222,  1226,   135,   515,  1227,  1243,
    1053,   160,   176,   177,   185,   219,   228,   257,   302,   344,
    1220,  1221,  1233,  1227,  1341,  1350,  1372,   432,  1431,  1369,
    1436,  1431,     6,   393,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   253,   372,   373,   430,   558,   624,   678,
     679,  1380,  1382,  1397,   460,  1395,   393,     5,   621,     5,
     393,  1278,   393,   393,   627,   432,   627,    26,  1391,  1391,
      26,  1391,  1391,    26,  1390,    25,  1399,  1348,  1349,  1350,
    1275,  1271,  1444,     8,   428,   687,     5,   393,   860,   393,
       5,   548,  1360,  1365,   955,   627,   393,    26,   591,   627,
     393,   393,   393,   393,     5,   393,   393,   393,   720,   718,
      20,   393,  1444,     5,   862,   568,   275,   696,   697,   862,
      20,   955,   393,   996,  1509,  1509,     5,   754,   460,   621,
       5,   755,  1509,   751,   548,    20,   955,     5,   955,  1145,
     391,   660,   860,  1306,   913,  1032,   669,  1168,   855,     5,
     718,  1108,   703,   685,   955,  1108,   709,   393,   718,   718,
    1509,  1509,  1030,  1084,    25,  1088,  1108,   573,   909,  1119,
     484,   861,  1038,   627,  1432,   393,   397,  1459,  1488,   360,
     477,   587,  1384,  1436,  1439,  1384,  1384,  1384,  1384,   621,
    1439,  1180,  1436,  1436,  1436,  1436,  1485,  1108,  1131,    63,
     544,   985,   971,   972,   621,   947,  1509,   947,  1509,   691,
      26,  1108,    26,  1108,   695,   393,   432,  1445,  1433,  1415,
    1419,  1419,  1411,     5,   393,   472,  1430,  1295,  1396,   480,
    1292,  1430,   627,  1423,    18,    19,    65,   429,   432,   445,
     484,   485,   497,   539,   578,   590,   602,   603,   610,   613,
     955,  1399,  1431,  1477,  1478,  1479,  1480,  1481,  1482,  1488,
    1477,  1477,  1477,  1396,  1474,  1476,  1473,  1474,  1475,  1470,
     555,  1303,     5,   393,   627,   955,   955,  1417,  1108,   955,
    1509,  1509,  1509,  1509,   625,   625,  1223,  1223,  1223,    25,
    1223,  1223,  1223,  1223,  1223,  1223,    25,    25,  1223,  1226,
    1108,  1135,  1136,   620,   448,  1189,  1509,    25,    25,    26,
      26,    26,    26,    26,    25,  1108,  1221,  1189,   393,   393,
    1370,  1371,  1375,  1437,  1375,   432,  1431,  1375,   432,  1431,
    1375,    10,   250,   388,   390,  1436,    26,  1338,  1396,    20,
     955,  1396,   367,   455,   471,   514,   554,   583,   592,  1407,
      26,  1407,     5,  1388,  1388,     5,   393,   393,  1388,   393,
    1350,  1444,  1265,   269,  1261,  1434,   516,  1361,  1362,  1363,
    1393,  1366,   332,   515,   526,  1310,  1427,   367,   455,   471,
     514,   554,   583,   592,  1405,   895,   591,    24,    26,   809,
     855,   885,   469,   840,     5,   375,  1444,     5,   432,   393,
     552,  1021,   959,  1509,   688,    20,   955,   959,  1509,  1499,
     862,  1499,  1130,  1509,    26,   954,    25,  1248,  1127,   428,
     718,   708,   712,   393,  1509,   954,   862,   907,   428,  1407,
    1433,     5,  1406,   393,     5,  1436,     5,   393,  1436,  1436,
    1436,  1436,   955,   393,   987,   986,   442,   973,   974,    20,
     955,  1446,  1447,   555,  1429,  1414,  1412,  1415,  1396,  1432,
     140,  1335,     5,   393,  1293,  1454,  1429,  1480,  1480,  1479,
     432,   432,   432,   432,   432,   432,   432,   955,   432,     5,
     393,    18,    19,    20,    21,  1458,   393,     5,   393,     5,
      14,   150,   527,  1471,  1304,  1396,   464,  1330,  1331,  1394,
     621,   211,  1061,   821,   795,   540,   589,  1137,     5,  1135,
      62,   134,   200,   202,   217,   225,   229,   254,  1190,  1191,
    1244,  1061,  1234,   443,  1374,  1374,  1378,  1379,  1399,  1488,
    1374,  1378,  1374,  1375,  1436,     5,   428,  1395,   393,    26,
    1392,   393,   393,    26,   393,   432,  1363,     5,   955,  1398,
     369,  1357,  1367,   955,  1428,   620,  1384,   332,   432,    24,
      26,   393,   947,   691,   375,  1444,   862,   698,   570,  1143,
      26,   691,   428,  1021,   393,   241,   691,   393,   393,   432,
     710,   345,   716,   393,   705,  1083,  1509,   460,  1365,  1406,
     627,  1406,   393,  1436,   393,   393,   393,   393,   862,  1509,
     954,     5,   393,  1130,  1365,  1415,  1415,  1433,  1396,   432,
    1365,   393,  1459,  1384,  1479,  1483,  1384,  1384,  1384,  1384,
     621,  1483,  1478,  1479,  1479,  1479,  1479,  1474,    14,  1475,
    1478,   949,  1369,  1130,     5,   141,  1324,   955,  1136,  1192,
    1193,  1108,  1195,  1108,  1194,  1196,  1191,   240,   240,  1376,
    1399,  1440,     5,   393,   393,  1374,     7,    26,   627,   393,
    1362,  1364,  1362,  1358,  1435,  1436,   449,  1356,  1368,  1261,
      26,  1311,  1312,  1313,  1396,  1425,  1428,    26,   839,  1444,
     394,   204,   260,   285,   294,   330,   338,   433,   604,   695,
     699,   700,   432,   621,   691,  1167,  1249,   713,   393,  1127,
     716,   716,  1509,   908,  1119,   393,   627,  1407,   627,   577,
    1018,  1447,  1427,  1365,   484,  1296,  1297,  1436,  1427,   393,
    1479,     5,   393,  1479,  1479,  1479,  1479,   955,   393,   432,
    1331,  1509,  1509,  1197,  1509,  1198,  1509,  1509,  1379,  1436,
     428,  1407,     5,   393,     5,  1369,     5,   540,   589,  1314,
    1261,   393,   348,   352,   842,   843,   844,  1024,   942,   942,
     942,   942,   942,   942,    25,     5,   393,   862,    20,   955,
    1024,  1171,  1172,  1173,   716,   718,   716,   242,   428,  1407,
    1407,   988,   691,     5,   393,   393,  1479,   393,   393,   393,
     393,  1477,  1509,  1509,  1362,  1435,  1312,   846,   845,   239,
     844,   847,   700,     5,  1174,   283,  1173,   714,  1509,  1297,
     393,  1509,  1509,  1509,   862,  1509,   393,   985,   393,   715,
     163,   345,   717,  1127
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
#line 1019 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 1020 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 1021 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 1022 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 1023 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 1029 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1040 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1043 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1046 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1046 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1053 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1054 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1060 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1061 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1062 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1063 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1064 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1065 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1066 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1067 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1070 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1072 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1073 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1074 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1075 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 46:
#line 1076 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 49:
#line 1083 "fgl.yacc"
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
#line 1094 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 51:
#line 1098 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 52:
#line 1099 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 53:
#line 1103 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 54:
#line 1109 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 55:
#line 1111 "fgl.yacc"
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
#line 1122 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1124 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1126 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1128 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 60:
#line 1132 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1134 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1195 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 63:
#line 1199 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 64:
#line 1203 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 65:
#line 1210 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 66:
#line 1213 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 67:
#line 1217 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 69:
#line 1221 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1228 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 71:
#line 1234 "fgl.yacc"
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
#line 1243 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 73:
#line 1247 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 74:
#line 1252 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 75:
#line 1256 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 76:
#line 1264 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 77:
#line 1268 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 78:
#line 1272 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 79:
#line 1274 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 80:
#line 1280 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 81:
#line 1285 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 82:
#line 1288 "fgl.yacc"
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
#line 1304 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 84:
#line 1311 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 85:
#line 1315 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 86:
#line 1319 "fgl.yacc"
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
#line 1341 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 88:
#line 1341 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 89:
#line 1345 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 90:
#line 1346 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 91:
#line 1347 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 92:
#line 1352 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 93:
#line 1355 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 94:
#line 1361 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 95:
#line 1364 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 98:
#line 1376 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1382 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1385 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 101:
#line 1400 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 102:
#line 1410 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 103:
#line 1416 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 104:
#line 1425 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 109:
#line 1438 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 111:
#line 1441 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 112:
#line 1443 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 114:
#line 1449 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 115:
#line 1451 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 116:
#line 1456 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 117:
#line 1461 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 118:
#line 1467 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 119:
#line 1471 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 120:
#line 1486 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 121:
#line 1489 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1492 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1495 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 124:
#line 1498 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 125:
#line 1501 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 131:
#line 1523 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 134:
#line 1532 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 135:
#line 1542 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 136:
#line 1556 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 137:
#line 1560 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 138:
#line 1563 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 139:
#line 1571 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 140:
#line 1577 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 145:
#line 1592 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 146:
#line 1596 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 147:
#line 1601 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 150:
#line 1611 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 151:
#line 1614 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 152:
#line 1618 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 153:
#line 1620 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 154:
#line 1623 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 155:
#line 1625 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 156:
#line 1628 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 157:
#line 1630 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 158:
#line 1633 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 159:
#line 1636 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 160:
#line 1646 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 161:
#line 1647 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 162:
#line 1655 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 163:
#line 1656 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 164:
#line 1673 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 165:
#line 1676 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 166:
#line 1679 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 167:
#line 1682 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 168:
#line 1685 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 169:
#line 1688 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 170:
#line 1697 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 171:
#line 1705 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1710 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1723 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 174:
#line 1727 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 175:
#line 1742 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 176:
#line 1743 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 179:
#line 1751 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 180:
#line 1751 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 186:
#line 1761 "fgl.yacc"
    {in_define=1;}
    break;

  case 187:
#line 1761 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 188:
#line 1770 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1771 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1772 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 191:
#line 1775 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 193:
#line 1780 "fgl.yacc"
    { }
    break;

  case 194:
#line 1780 "fgl.yacc"
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
#line 1797 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 199:
#line 1801 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 204:
#line 1816 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 205:
#line 1817 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1818 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 207:
#line 1819 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 208:
#line 1824 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 210:
#line 1830 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 212:
#line 1839 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 213:
#line 1843 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 219:
#line 1859 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 220:
#line 1861 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 221:
#line 1862 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 223:
#line 1869 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 224:
#line 1869 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 225:
#line 1870 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 226:
#line 1871 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 227:
#line 1874 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 228:
#line 1876 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 230:
#line 1886 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 235:
#line 1901 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 236:
#line 1901 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 240:
#line 1907 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 241:
#line 1908 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 242:
#line 1915 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 243:
#line 1916 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 244:
#line 1917 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 245:
#line 1918 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 246:
#line 1921 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 247:
#line 1922 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 248:
#line 1923 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1924 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 250:
#line 1928 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 251:
#line 1933 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1938 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 253:
#line 1942 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1945 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1949 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 256:
#line 1950 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 257:
#line 1951 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 258:
#line 1952 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 259:
#line 1953 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1954 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 261:
#line 1955 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1956 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 263:
#line 1959 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 264:
#line 1960 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 265:
#line 1961 "fgl.yacc"
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

  case 266:
#line 1993 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 267:
#line 1997 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 268:
#line 1999 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2001 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 270:
#line 2003 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 271:
#line 2008 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 272:
#line 2012 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 273:
#line 2012 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 274:
#line 2016 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 275:
#line 2017 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 276:
#line 2018 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 277:
#line 2019 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 278:
#line 2020 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 279:
#line 2021 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 280:
#line 2023 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 281:
#line 2028 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 282:
#line 2028 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 283:
#line 2031 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 284:
#line 2033 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 285:
#line 2039 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 286:
#line 2041 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 287:
#line 2047 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 288:
#line 2055 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 289:
#line 2055 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 290:
#line 2058 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 291:
#line 2059 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 292:
#line 2060 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 293:
#line 2061 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 294:
#line 2062 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 295:
#line 2063 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 296:
#line 2065 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 300:
#line 2086 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 304:
#line 2095 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 305:
#line 2097 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 306:
#line 2099 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2101 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 308:
#line 2102 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 309:
#line 2103 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 310:
#line 2104 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 311:
#line 2105 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 312:
#line 2110 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2117 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2122 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 315:
#line 2124 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2126 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2127 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 318:
#line 2128 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 319:
#line 2129 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 320:
#line 2130 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 321:
#line 2131 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 322:
#line 2132 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 323:
#line 2135 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 324:
#line 2137 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 325:
#line 2143 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 326:
#line 2151 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 328:
#line 2159 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2163 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 330:
#line 2171 "fgl.yacc"
    {dim_push_record();}
    break;

  case 331:
#line 2172 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 332:
#line 2173 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 333:
#line 2174 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 339:
#line 2193 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 340:
#line 2205 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 341:
#line 2209 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 342:
#line 2212 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 343:
#line 2215 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 344:
#line 2216 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 345:
#line 2217 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 346:
#line 2218 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 347:
#line 2219 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 348:
#line 2225 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 349:
#line 2232 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 350:
#line 2237 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 351:
#line 2242 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 352:
#line 2246 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 353:
#line 2249 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 354:
#line 2257 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 355:
#line 2259 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 356:
#line 2264 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 361:
#line 2276 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 362:
#line 2279 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 363:
#line 2282 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 364:
#line 2285 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 365:
#line 2288 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 366:
#line 2291 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 367:
#line 2298 "fgl.yacc"
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

  case 368:
#line 2317 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 369:
#line 2323 "fgl.yacc"
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

  case 370:
#line 2347 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 371:
#line 2350 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 372:
#line 2365 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 373:
#line 2367 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 374:
#line 2369 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 375:
#line 2371 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 376:
#line 2373 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 377:
#line 2375 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 378:
#line 2376 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 379:
#line 2383 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 380:
#line 2385 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 381:
#line 2389 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 382:
#line 2391 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 383:
#line 2393 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 384:
#line 2395 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 385:
#line 2397 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 386:
#line 2399 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 387:
#line 2401 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 388:
#line 2407 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 389:
#line 2421 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 390:
#line 2424 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 395:
#line 2441 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 398:
#line 2447 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 399:
#line 2451 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 400:
#line 2456 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 404:
#line 2466 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 405:
#line 2467 "fgl.yacc"
    {inc_counter();}
    break;

  case 411:
#line 2473 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 412:
#line 2480 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 413:
#line 2480 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 415:
#line 2485 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 416:
#line 2489 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 417:
#line 2495 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2503 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2509 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2518 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 421:
#line 2520 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 422:
#line 2527 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 423:
#line 2535 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 424:
#line 2539 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 425:
#line 2548 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 426:
#line 2553 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 427:
#line 2558 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 428:
#line 2562 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 429:
#line 2564 "fgl.yacc"
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

  case 430:
#line 2574 "fgl.yacc"
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

  case 431:
#line 2588 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 432:
#line 2596 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 433:
#line 2608 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2614 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2620 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 438:
#line 2630 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 439:
#line 2636 "fgl.yacc"
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

  case 440:
#line 2708 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
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
#line 2718 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 443:
#line 2726 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 444:
#line 2726 "fgl.yacc"
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

  case 445:
#line 2742 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 446:
#line 2746 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 447:
#line 2752 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 448:
#line 2755 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 449:
#line 2763 "fgl.yacc"
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

  case 450:
#line 2774 "fgl.yacc"
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

  case 451:
#line 2784 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 452:
#line 2790 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 453:
#line 2800 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 454:
#line 2805 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2812 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 456:
#line 2815 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 457:
#line 2818 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 458:
#line 2823 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 459:
#line 2830 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 460:
#line 2835 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2840 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 462:
#line 2845 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2856 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 464:
#line 2864 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 465:
#line 2872 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 466:
#line 2877 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 467:
#line 2881 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 468:
#line 2886 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 469:
#line 2890 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 470:
#line 2894 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 471:
#line 2900 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 472:
#line 2903 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 474:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 475:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 476:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 477:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 478:
#line 2930 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 479:
#line 2940 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 480:
#line 2945 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 481:
#line 2951 "fgl.yacc"
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

  case 482:
#line 2961 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 483:
#line 2966 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 484:
#line 2969 "fgl.yacc"
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

  case 485:
#line 2983 "fgl.yacc"
    {chk4var=1;}
    break;

  case 486:
#line 2983 "fgl.yacc"
    {chk4var=0;}
    break;

  case 487:
#line 2983 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 488:
#line 2986 "fgl.yacc"
    {chk4var=1;}
    break;

  case 489:
#line 2986 "fgl.yacc"
    {chk4var=0;}
    break;

  case 490:
#line 2986 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 491:
#line 2990 "fgl.yacc"
    {chk4var=1;}
    break;

  case 492:
#line 2990 "fgl.yacc"
    {chk4var=0;}
    break;

  case 493:
#line 2990 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 494:
#line 2994 "fgl.yacc"
    {chk4var=1;}
    break;

  case 495:
#line 2994 "fgl.yacc"
    {chk4var=0;}
    break;

  case 496:
#line 2994 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 497:
#line 2998 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 498:
#line 3004 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3010 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3016 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3026 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 502:
#line 3027 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 505:
#line 3035 "fgl.yacc"
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

  case 506:
#line 3046 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 507:
#line 3047 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 508:
#line 3053 "fgl.yacc"
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

  case 509:
#line 3064 "fgl.yacc"
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

  case 510:
#line 3074 "fgl.yacc"
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

  case 513:
#line 3087 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 514:
#line 3092 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 515:
#line 3099 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 516:
#line 3103 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 517:
#line 3106 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 518:
#line 3109 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 519:
#line 3115 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 520:
#line 3118 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 521:
#line 3121 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 522:
#line 3138 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 523:
#line 3141 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 524:
#line 3147 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 525:
#line 3148 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 526:
#line 3149 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 528:
#line 3154 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 529:
#line 3155 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 530:
#line 3156 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 531:
#line 3157 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 532:
#line 3159 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3160 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3161 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3163 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3164 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 538:
#line 3170 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 540:
#line 3175 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 541:
#line 3187 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 542:
#line 3191 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 543:
#line 3192 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 544:
#line 3199 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 546:
#line 3216 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 547:
#line 3220 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 548:
#line 3226 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 549:
#line 3230 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 550:
#line 3239 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 551:
#line 3240 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 552:
#line 3252 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 553:
#line 3258 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 554:
#line 3266 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 561:
#line 3283 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 562:
#line 3285 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 563:
#line 3288 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 564:
#line 3290 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 569:
#line 3304 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 570:
#line 3306 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 571:
#line 3309 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 572:
#line 3311 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 585:
#line 3342 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 586:
#line 3344 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 587:
#line 3347 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 588:
#line 3349 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 589:
#line 3352 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 590:
#line 3354 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 591:
#line 3357 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 592:
#line 3359 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 593:
#line 3362 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 594:
#line 3364 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 595:
#line 3379 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 596:
#line 3395 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 597:
#line 3396 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 598:
#line 3397 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 599:
#line 3398 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 600:
#line 3399 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 601:
#line 3400 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 602:
#line 3401 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 606:
#line 3409 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 608:
#line 3415 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 609:
#line 3417 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 610:
#line 3418 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 611:
#line 3420 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 612:
#line 3422 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 613:
#line 3424 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 614:
#line 3426 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 615:
#line 3428 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 616:
#line 3431 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 617:
#line 3438 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 618:
#line 3440 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 619:
#line 3446 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 620:
#line 3451 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 621:
#line 3456 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3461 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 623:
#line 3461 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 624:
#line 3464 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 625:
#line 3470 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 626:
#line 3475 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 627:
#line 3479 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 630:
#line 3487 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 631:
#line 3489 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 632:
#line 3491 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 633:
#line 3493 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 634:
#line 3495 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 635:
#line 3497 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 636:
#line 3500 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 638:
#line 3509 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 639:
#line 3571 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 640:
#line 3584 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 642:
#line 3591 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 643:
#line 3594 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 644:
#line 3600 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 645:
#line 3606 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 646:
#line 3610 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 647:
#line 3614 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 648:
#line 3620 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 649:
#line 3624 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 650:
#line 3628 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 651:
#line 3633 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 652:
#line 3638 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 671:
#line 3679 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 672:
#line 3686 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 673:
#line 3689 "fgl.yacc"
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

  case 675:
#line 3708 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 677:
#line 3711 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 678:
#line 3713 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 679:
#line 3716 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 680:
#line 3720 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 681:
#line 3723 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 682:
#line 3729 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 683:
#line 3740 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 684:
#line 3741 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 685:
#line 3744 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 687:
#line 3750 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 688:
#line 3754 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 689:
#line 3755 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 692:
#line 3769 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 693:
#line 3771 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 696:
#line 3780 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 697:
#line 3782 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 698:
#line 3786 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 699:
#line 3788 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 700:
#line 3791 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 701:
#line 3793 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 702:
#line 3796 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 703:
#line 3799 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 704:
#line 3802 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 705:
#line 3804 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 706:
#line 3807 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 707:
#line 3809 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 708:
#line 3812 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 709:
#line 3814 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 710:
#line 3817 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 711:
#line 3819 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 712:
#line 3820 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 713:
#line 3822 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 714:
#line 3823 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 715:
#line 3825 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 716:
#line 3826 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 717:
#line 3828 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 718:
#line 3868 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 719:
#line 3869 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 720:
#line 3877 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 721:
#line 3878 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 722:
#line 3887 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 723:
#line 3892 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 724:
#line 3897 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 725:
#line 3898 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 727:
#line 3903 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 728:
#line 3906 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 729:
#line 3914 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 730:
#line 3919 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 731:
#line 3923 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 732:
#line 3930 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 733:
#line 3939 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 734:
#line 3945 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 735:
#line 3946 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 736:
#line 3947 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 737:
#line 3948 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 738:
#line 3951 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 740:
#line 3954 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 741:
#line 3961 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 742:
#line 3962 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 743:
#line 3963 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 744:
#line 3964 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 745:
#line 3965 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 746:
#line 3966 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 747:
#line 3967 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 748:
#line 3968 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 749:
#line 3969 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 750:
#line 3974 "fgl.yacc"
    {iskey=1;}
    break;

  case 751:
#line 3974 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 752:
#line 3976 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 753:
#line 3979 "fgl.yacc"
    {iskey=1;}
    break;

  case 754:
#line 3979 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 755:
#line 3981 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 756:
#line 3985 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3988 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 758:
#line 3989 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 760:
#line 3992 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 766:
#line 4004 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 767:
#line 4005 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 768:
#line 4006 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 769:
#line 4007 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 770:
#line 4008 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 771:
#line 4009 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 772:
#line 4010 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 773:
#line 4011 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 774:
#line 4012 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 775:
#line 4013 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 776:
#line 4014 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 777:
#line 4015 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 778:
#line 4016 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 779:
#line 4017 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 780:
#line 4021 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 781:
#line 4039 "fgl.yacc"
    {chk4var=1;}
    break;

  case 782:
#line 4039 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 783:
#line 4042 "fgl.yacc"
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

  case 784:
#line 4066 "fgl.yacc"
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

  case 786:
#line 4084 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 787:
#line 4090 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 788:
#line 4096 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 789:
#line 4102 "fgl.yacc"
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

  case 790:
#line 4113 "fgl.yacc"
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

  case 791:
#line 4136 "fgl.yacc"
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

  case 794:
#line 4152 "fgl.yacc"
    {
	}
    break;

  case 801:
#line 4175 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 805:
#line 4183 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 823:
#line 4209 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 824:
#line 4210 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 825:
#line 4218 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 826:
#line 4223 "fgl.yacc"
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

  case 827:
#line 4239 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 828:
#line 4245 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 830:
#line 4260 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 831:
#line 4273 "fgl.yacc"
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

  case 832:
#line 4283 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 833:
#line 4290 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 834:
#line 4297 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 835:
#line 4303 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 836:
#line 4303 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 837:
#line 4308 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 838:
#line 4314 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 839:
#line 4322 "fgl.yacc"
    {
}
    break;

  case 845:
#line 4334 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 847:
#line 4342 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 848:
#line 4348 "fgl.yacc"
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

  case 849:
#line 4362 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 850:
#line 4366 "fgl.yacc"
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

  case 851:
#line 4379 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 853:
#line 4397 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 854:
#line 4405 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 855:
#line 4411 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 856:
#line 4422 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 857:
#line 4426 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 858:
#line 4433 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 859:
#line 4440 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 860:
#line 4446 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 861:
#line 4451 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 864:
#line 4458 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 865:
#line 4459 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 866:
#line 4461 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 867:
#line 4462 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 868:
#line 4465 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 869:
#line 4466 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 870:
#line 4467 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4469 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 872:
#line 4474 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 873:
#line 4479 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 874:
#line 4486 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 878:
#line 4493 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 879:
#line 4495 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 880:
#line 4497 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 881:
#line 4506 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 882:
#line 4512 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 883:
#line 4516 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 886:
#line 4528 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 887:
#line 4533 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 888:
#line 4538 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 889:
#line 4541 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 891:
#line 4553 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 892:
#line 4556 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 893:
#line 4559 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 900:
#line 4575 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 901:
#line 4580 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 902:
#line 4580 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 903:
#line 4583 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 904:
#line 4610 "fgl.yacc"
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

  case 906:
#line 4668 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 908:
#line 4675 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 909:
#line 4679 "fgl.yacc"
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

  case 910:
#line 4722 "fgl.yacc"
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

  case 914:
#line 4770 "fgl.yacc"
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

  case 915:
#line 4784 "fgl.yacc"
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

  case 920:
#line 4808 "fgl.yacc"
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

  case 921:
#line 4868 "fgl.yacc"
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

  case 922:
#line 4924 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 923:
#line 4929 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 924:
#line 4937 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 925:
#line 4942 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 926:
#line 4950 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 927:
#line 4956 "fgl.yacc"
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

  case 928:
#line 4989 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 929:
#line 4992 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 930:
#line 4994 "fgl.yacc"
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

  case 931:
#line 5035 "fgl.yacc"
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

  case 936:
#line 5088 "fgl.yacc"
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

  case 937:
#line 5140 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 939:
#line 5147 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 940:
#line 5153 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 941:
#line 5164 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 942:
#line 5171 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 944:
#line 5179 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 945:
#line 5182 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 946:
#line 5183 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 948:
#line 5185 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 949:
#line 5186 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 950:
#line 5189 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 951:
#line 5192 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 952:
#line 5198 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 953:
#line 5201 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 954:
#line 5205 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 955:
#line 5209 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 956:
#line 5216 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 957:
#line 5221 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 958:
#line 5228 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 959:
#line 5231 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 964:
#line 5244 "fgl.yacc"
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

  case 965:
#line 5263 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 966:
#line 5270 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5277 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 968:
#line 5280 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 969:
#line 5294 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 974:
#line 5311 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 975:
#line 5316 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 976:
#line 5322 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 978:
#line 5329 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 979:
#line 5334 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 980:
#line 5337 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 981:
#line 5338 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 982:
#line 5341 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 983:
#line 5342 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 984:
#line 5345 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 985:
#line 5346 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 986:
#line 5351 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 987:
#line 5358 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 988:
#line 5361 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 989:
#line 5367 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 990:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 991:
#line 5371 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 992:
#line 5373 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 993:
#line 5376 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 994:
#line 5376 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 995:
#line 5377 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 996:
#line 5382 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 997:
#line 5390 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 998:
#line 5391 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 999:
#line 5396 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1000:
#line 5398 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1001:
#line 5400 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1005:
#line 5417 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1006:
#line 5420 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1007:
#line 5423 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1008:
#line 5426 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1009:
#line 5430 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1010:
#line 5433 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1011:
#line 5436 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1012:
#line 5440 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1013:
#line 5444 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1014:
#line 5448 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1015:
#line 5451 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1016:
#line 5455 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1017:
#line 5458 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1018:
#line 5459 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1019:
#line 5460 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1020:
#line 5463 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1021:
#line 5466 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1022:
#line 5469 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1023:
#line 5472 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1024:
#line 5475 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1025:
#line 5478 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1026:
#line 5481 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1027:
#line 5498 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1030:
#line 5508 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1031:
#line 5514 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1032:
#line 5518 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1034:
#line 5538 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1035:
#line 5543 "fgl.yacc"
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

  case 1036:
#line 5555 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1037:
#line 5556 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1038:
#line 5560 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1039:
#line 5565 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1040:
#line 5566 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1041:
#line 5570 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1045:
#line 5576 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1046:
#line 5578 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1048:
#line 5593 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1049:
#line 5597 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1050:
#line 5603 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1051:
#line 5604 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1052:
#line 5607 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1053:
#line 5608 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1054:
#line 5611 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1056:
#line 5630 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1057:
#line 5635 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1058:
#line 5640 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1059:
#line 5645 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1065:
#line 5667 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1066:
#line 5674 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1067:
#line 5683 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1068:
#line 5689 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1069:
#line 5691 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1073:
#line 5702 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1074:
#line 5703 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1075:
#line 5709 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1076:
#line 5713 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1077:
#line 5719 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1078:
#line 5720 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1079:
#line 5725 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1080:
#line 5726 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1081:
#line 5728 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1082:
#line 5729 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1083:
#line 5730 "fgl.yacc"
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

  case 1084:
#line 5744 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1085:
#line 5746 "fgl.yacc"
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

  case 1086:
#line 5763 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5775 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1094:
#line 5775 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1095:
#line 5781 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1096:
#line 5781 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1097:
#line 5784 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1098:
#line 5784 "fgl.yacc"
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

  case 1099:
#line 5800 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1100:
#line 5801 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1101:
#line 5802 "fgl.yacc"
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

  case 1102:
#line 5811 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1103:
#line 5823 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1109:
#line 5834 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1110:
#line 5839 "fgl.yacc"
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

  case 1111:
#line 5859 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1112:
#line 5864 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1113:
#line 5870 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1114:
#line 5871 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1115:
#line 5872 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1116:
#line 5876 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1117:
#line 5877 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1118:
#line 5878 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1119:
#line 5879 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1120:
#line 5883 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1121:
#line 5893 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1122:
#line 5895 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1123:
#line 5900 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1124:
#line 5903 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1125:
#line 5908 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1126:
#line 5915 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1127:
#line 5922 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5929 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1129:
#line 5938 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1130:
#line 5945 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1131:
#line 5952 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1132:
#line 5959 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1133:
#line 5966 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1138:
#line 5979 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1139:
#line 5980 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1140:
#line 5981 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1141:
#line 5982 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 5983 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 5984 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1144:
#line 5985 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1145:
#line 5986 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1146:
#line 5987 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1147:
#line 5988 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1150:
#line 5994 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1151:
#line 5995 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1152:
#line 5996 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1153:
#line 5997 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1158:
#line 6006 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1159:
#line 6007 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1160:
#line 6008 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1161:
#line 6009 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1162:
#line 6010 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6011 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6012 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1165:
#line 6013 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6015 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1167:
#line 6016 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1168:
#line 6017 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1169:
#line 6018 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1170:
#line 6020 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1171:
#line 6021 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1172:
#line 6022 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1173:
#line 6023 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1177:
#line 6028 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1178:
#line 6029 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1182:
#line 6036 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1183:
#line 6044 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1184:
#line 6052 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1185:
#line 6064 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1186:
#line 6073 "fgl.yacc"
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

  case 1187:
#line 6084 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1188:
#line 6088 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1189:
#line 6092 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1190:
#line 6098 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1191:
#line 6103 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1192:
#line 6111 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1193:
#line 6114 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1194:
#line 6123 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1195:
#line 6134 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1197:
#line 6141 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1198:
#line 6149 "fgl.yacc"
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

  case 1199:
#line 6159 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1200:
#line 6162 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1201:
#line 6166 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1202:
#line 6174 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1203:
#line 6177 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1204:
#line 6183 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1205:
#line 6187 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1206:
#line 6191 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1207:
#line 6195 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1208:
#line 6199 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1209:
#line 6205 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1210:
#line 6206 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1211:
#line 6207 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1212:
#line 6208 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1213:
#line 6213 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1214:
#line 6215 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1215:
#line 6218 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1216:
#line 6222 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1217:
#line 6225 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1218:
#line 6232 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1219:
#line 6237 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1220:
#line 6238 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1221:
#line 6239 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1222:
#line 6244 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1223:
#line 6245 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1224:
#line 6251 "fgl.yacc"
    {insql=1;}
    break;

  case 1225:
#line 6251 "fgl.yacc"
    {insql=0;}
    break;

  case 1226:
#line 6251 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1227:
#line 6256 "fgl.yacc"
    {insql=1;}
    break;

  case 1228:
#line 6256 "fgl.yacc"
    {insql=0;}
    break;

  case 1229:
#line 6256 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1230:
#line 6267 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1231:
#line 6268 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1232:
#line 6274 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1233:
#line 6276 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1235:
#line 6289 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1236:
#line 6293 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1237:
#line 6294 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1239:
#line 6299 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1240:
#line 6302 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1241:
#line 6308 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1242:
#line 6311 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6319 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1245:
#line 6326 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1246:
#line 6333 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1247:
#line 6336 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1248:
#line 6345 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1249:
#line 6348 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1250:
#line 6351 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1251:
#line 6354 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1252:
#line 6357 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1253:
#line 6360 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1254:
#line 6363 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6370 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1256:
#line 6373 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1257:
#line 6380 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 6383 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1259:
#line 6389 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1260:
#line 6392 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1261:
#line 6399 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1262:
#line 6402 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1264:
#line 6410 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1266:
#line 6419 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1267:
#line 6422 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1268:
#line 6428 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1269:
#line 6431 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1270:
#line 6437 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1271:
#line 6444 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1272:
#line 6445 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1273:
#line 6449 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1274:
#line 6455 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1275:
#line 6458 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1277:
#line 6466 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1278:
#line 6473 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1279:
#line 6476 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1283:
#line 6494 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1289:
#line 6500 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1290:
#line 6503 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1291:
#line 6506 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1292:
#line 6512 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1294:
#line 6518 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1296:
#line 6529 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1297:
#line 6543 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1298:
#line 6552 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1299:
#line 6552 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1300:
#line 6557 "fgl.yacc"
    {insql=1;}
    break;

  case 1301:
#line 6557 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1302:
#line 6562 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1303:
#line 6565 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1304:
#line 6567 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1306:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6578 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1308:
#line 6582 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1309:
#line 6589 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1310:
#line 6592 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1311:
#line 6599 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1312:
#line 6603 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1313:
#line 6607 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1314:
#line 6612 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1315:
#line 6617 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1316:
#line 6621 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1317:
#line 6627 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1318:
#line 6631 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1319:
#line 6637 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1320:
#line 6644 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1321:
#line 6648 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1322:
#line 6653 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1323:
#line 6663 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1324:
#line 6666 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1325:
#line 6668 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1326:
#line 6670 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1327:
#line 6672 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1328:
#line 6674 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1329:
#line 6676 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1330:
#line 6678 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1331:
#line 6684 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1332:
#line 6694 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1333:
#line 6701 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1335:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1339:
#line 6716 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1342:
#line 6721 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1343:
#line 6726 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1344:
#line 6733 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1345:
#line 6734 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1346:
#line 6741 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1347:
#line 6752 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1348:
#line 6753 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1349:
#line 6756 "fgl.yacc"
    {insql=1;}
    break;

  case 1350:
#line 6756 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1351:
#line 6761 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1352:
#line 6766 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1354:
#line 6772 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1356:
#line 6776 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1357:
#line 6781 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1358:
#line 6786 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1359:
#line 6790 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1361:
#line 6796 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1362:
#line 6800 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1363:
#line 6808 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1364:
#line 6811 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1365:
#line 6813 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1366:
#line 6818 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1369:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1373:
#line 6832 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6835 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 6837 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6843 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6849 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6859 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1383:
#line 6864 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1384:
#line 6866 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1386:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6875 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1389:
#line 6881 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1390:
#line 6889 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6894 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6904 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6910 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1398:
#line 6918 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6924 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6929 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1402:
#line 6932 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1403:
#line 6935 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1404:
#line 6943 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1406:
#line 6958 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1407:
#line 6963 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1409:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1410:
#line 6969 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1411:
#line 6976 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6979 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6985 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1414:
#line 6989 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1415:
#line 6993 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1416:
#line 6997 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1417:
#line 7000 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1418:
#line 7008 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1419:
#line 7015 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1422:
#line 7024 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1423:
#line 7030 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1424:
#line 7033 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1425:
#line 7044 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1426:
#line 7051 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1427:
#line 7057 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1428:
#line 7060 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7067 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 7074 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1432:
#line 7081 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1433:
#line 7087 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1434:
#line 7088 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1435:
#line 7089 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1437:
#line 7093 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1439:
#line 7098 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1440:
#line 7105 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1441:
#line 7110 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1442:
#line 7111 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1443:
#line 7114 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1444:
#line 7117 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1445:
#line 7122 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1446:
#line 7123 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1447:
#line 7128 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1448:
#line 7131 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1449:
#line 7137 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1450:
#line 7140 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1451:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1452:
#line 7149 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 7158 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1455:
#line 7165 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1456:
#line 7166 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1457:
#line 7195 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1458:
#line 7197 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1459:
#line 7201 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1461:
#line 7214 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1462:
#line 7217 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1463:
#line 7220 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1464:
#line 7223 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1466:
#line 7231 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 7234 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1469:
#line 7240 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1471:
#line 7246 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1472:
#line 7249 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1473:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1474:
#line 7255 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1475:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1476:
#line 7261 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1477:
#line 7264 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1478:
#line 7267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1479:
#line 7272 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1481:
#line 7279 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1487:
#line 7287 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1488:
#line 7288 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1489:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1490:
#line 7296 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1491:
#line 7300 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1492:
#line 7306 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1493:
#line 7307 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1494:
#line 7308 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1495:
#line 7309 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1500:
#line 7329 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1501:
#line 7334 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7335 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1504:
#line 7338 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7343 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1510:
#line 7346 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1512:
#line 7349 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7354 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7356 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7359 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1519:
#line 7360 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1520:
#line 7367 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 7372 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1528:
#line 7388 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1529:
#line 7389 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1530:
#line 7393 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1531:
#line 7394 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1533:
#line 7413 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1534:
#line 7414 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1535:
#line 7415 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1536:
#line 7419 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1537:
#line 7422 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1538:
#line 7428 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1539:
#line 7433 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1540:
#line 7438 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1542:
#line 7449 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1547:
#line 7464 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1548:
#line 7467 "fgl.yacc"
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

  case 1549:
#line 7480 "fgl.yacc"
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

  case 1550:
#line 7495 "fgl.yacc"
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

  case 1551:
#line 7507 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1552:
#line 7509 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1553:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1554:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1555:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1556:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1557:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1558:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1559:
#line 7513 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1560:
#line 7516 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1561:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1562:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1563:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1564:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1565:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1566:
#line 7521 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1567:
#line 7523 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1568:
#line 7526 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1583:
#line 7535 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1584:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1585:
#line 7540 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1586:
#line 7548 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1587:
#line 7548 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1588:
#line 7554 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1589:
#line 7554 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1590:
#line 7561 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1591:
#line 7561 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1592:
#line 7567 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1593:
#line 7567 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1594:
#line 7575 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1595:
#line 7576 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1596:
#line 7577 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1600:
#line 7584 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1601:
#line 7585 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7590 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1603:
#line 7593 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1604:
#line 7599 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1605:
#line 7604 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1606:
#line 7613 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1607:
#line 7625 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1608:
#line 7626 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1609:
#line 7629 "fgl.yacc"
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

  case 1610:
#line 7644 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1611:
#line 7654 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1612:
#line 7657 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1613:
#line 7665 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1614:
#line 7674 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1615:
#line 7677 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1616:
#line 7681 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1617:
#line 7684 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1618:
#line 7685 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1620:
#line 7694 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1621:
#line 7695 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1622:
#line 7704 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1623:
#line 7713 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1624:
#line 7718 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1625:
#line 7719 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1626:
#line 7720 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1627:
#line 7721 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1628:
#line 7728 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1629:
#line 7731 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1630:
#line 7737 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1631:
#line 7740 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1632:
#line 7750 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1633:
#line 7759 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1634:
#line 7762 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1635:
#line 7765 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1636:
#line 7771 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7777 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7780 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1639:
#line 7783 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1640:
#line 7786 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1641:
#line 7793 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1642:
#line 7795 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1643:
#line 7797 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1644:
#line 7799 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1645:
#line 7801 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1646:
#line 7802 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1647:
#line 7803 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1648:
#line 7804 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1649:
#line 7805 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1650:
#line 7806 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1651:
#line 7807 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1652:
#line 7809 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1653:
#line 7811 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1654:
#line 7813 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1655:
#line 7815 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1656:
#line 7817 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1657:
#line 7819 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1658:
#line 7821 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1659:
#line 7822 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7824 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7828 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1662:
#line 7829 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1664:
#line 7839 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1665:
#line 7848 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1666:
#line 7852 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1667:
#line 7859 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1668:
#line 7859 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1670:
#line 7863 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1671:
#line 7868 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1672:
#line 7868 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1674:
#line 7872 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1675:
#line 7876 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1678:
#line 7885 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1679:
#line 7885 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1684:
#line 7904 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1685:
#line 7905 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1688:
#line 7913 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1689:
#line 7919 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1692:
#line 7938 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1693:
#line 7939 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1694:
#line 7940 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1695:
#line 7941 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1696:
#line 7942 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1697:
#line 7943 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1698:
#line 7947 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1699:
#line 7948 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1700:
#line 7949 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1701:
#line 7953 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1702:
#line 7957 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1704:
#line 7966 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1706:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1707:
#line 7972 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2028:
#line 8300 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2029:
#line 8300 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2030:
#line 8307 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2031:
#line 8307 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2032:
#line 8395 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2033:
#line 8399 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2034:
#line 8401 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2035:
#line 8408 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2036:
#line 8412 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2037:
#line 8418 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2038:
#line 8426 "fgl.yacc"
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

  case 2039:
#line 8436 "fgl.yacc"
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

  case 2040:
#line 8446 "fgl.yacc"
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
#line 8458 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2042:
#line 8461 "fgl.yacc"
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

  case 2043:
#line 8480 "fgl.yacc"
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
#line 8506 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2045:
#line 8509 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2047:
#line 8518 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2048:
#line 8523 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2049:
#line 8526 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2050:
#line 8534 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2051:
#line 8542 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2052:
#line 8555 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2053:
#line 8558 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2054:
#line 8566 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2055:
#line 8569 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2056:
#line 8572 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2057:
#line 8580 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2058:
#line 8584 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2059:
#line 8587 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2060:
#line 8590 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2061:
#line 8593 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2062:
#line 8597 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2063:
#line 8598 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2064:
#line 8599 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2065:
#line 8600 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2066:
#line 8601 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2067:
#line 8607 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2068:
#line 8608 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2069:
#line 8609 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2070:
#line 8610 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2071:
#line 8611 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2072:
#line 8612 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2073:
#line 8613 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2074:
#line 8614 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2075:
#line 8615 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2076:
#line 8616 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2077:
#line 8617 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2078:
#line 8618 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2079:
#line 8619 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8620 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8624 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2082:
#line 8630 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2083:
#line 8631 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2084:
#line 8644 "fgl.yacc"
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

  case 2085:
#line 8664 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2089:
#line 8670 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2090:
#line 8671 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2094:
#line 8683 "fgl.yacc"
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

  case 2095:
#line 8709 "fgl.yacc"
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

  case 2096:
#line 8760 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2097:
#line 8762 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2098:
#line 8764 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2099:
#line 8765 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2100:
#line 8770 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2101:
#line 8775 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2102:
#line 8776 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2103:
#line 8780 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2104:
#line 8782 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2105:
#line 8784 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2106:
#line 8787 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2107:
#line 8791 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2108:
#line 8796 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2109:
#line 8801 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2110:
#line 8805 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2112:
#line 8815 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2114:
#line 8830 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2115:
#line 8833 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2116:
#line 8837 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2119:
#line 8856 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2120:
#line 8857 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2121:
#line 8860 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2122:
#line 8861 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2123:
#line 8862 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2124:
#line 8863 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2125:
#line 8864 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2126:
#line 8865 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2127:
#line 8866 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2128:
#line 8871 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2129:
#line 8872 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2130:
#line 8876 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2131:
#line 8880 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2132:
#line 8884 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2133:
#line 8888 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2134:
#line 8893 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2135:
#line 8897 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2136:
#line 8902 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2138:
#line 8910 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2140:
#line 8916 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2141:
#line 8922 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2142:
#line 8926 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2147:
#line 8944 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2148:
#line 8951 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2149:
#line 8960 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2150:
#line 8960 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18042 "y.tab.c"

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


#line 9058 "fgl.yacc"

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



