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
     COMMA = 1575,
     KW_OR = 1615,
     KW_AND = 1570,
     KW_USING = 1506,
     NOT = 1590,
     MATCHES = 1385,
     POWER = 1492,
     LESS_THAN = 1488,
     GREATER_THAN = 1403,
     EQUAL = 1565,
     GREATER_THAN_EQ = 1301,
     LESS_THAN_EQ = 1360,
     NOT_EQUAL = 1434,
     PLUS = 1601,
     MINUS = 1588,
     MULTIPLY = 1493,
     DIVIDE = 1521,
     MOD = 1589,
     COMMAND = 1367,
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
     DYNAMIC_ARRAY = 1000,
     RESIZE_ARRAY = 1001,
     ALLOCATE_ARRAY = 1002,
     DEALLOCATE_ARRAY = 1003,
     BEFORE_INSERT = 1004,
     CONCAT_PIPES = 1005,
     BEFORE_DELETE = 1006,
     AFTER_INSERT = 1007,
     AFTER_DELETE = 1008,
     EXECUTE_IMMEDIATE = 1009,
     DELETE_ROW_EQUAL_TRUE = 1010,
     INSERT_ROW_EQUAL_TRUE = 1011,
     DELETE_ROW_EQUAL_FALSE = 1012,
     INSERT_ROW_EQUAL_FALSE = 1013,
     CURRENT_ROW_DISPLAY_EQUAL = 1014,
     MAXCOUNT = 1015,
     ALTER_TABLE = 1016,
     WHENEVER_ERROR_CONTINUE = 1017,
     WHENEVER_WARNING_CONTINUE = 1018,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1019,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1020,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1021,
     XSET_MULTIPLY_EQUAL = 1022,
     XSET_OPEN_BRACKET = 1023,
     NEWFORMATSHARED = 1024,
     CREATE_DATABASE = 1025,
     IMPORT_LEGACY_FUNCTION = 1026,
     ADD_CONSTRAINT = 1027,
     DROP_CONSTRAINT = 1028,
     AS_STATIC = 1029,
     NOT_FIELD_TOUCHED = 1030,
     LOCAL_FUNCTION = 1031,
     EVERY_ROW = 1032,
     ELIF = 1033,
     DOUBLE_PRECISION = 1034,
     COUNT_MULTIPLY = 1035,
     WAIT_FOR_KEY = 1036,
     AT_TERMINATION_CALL = 1037,
     TERMINATE_REPORT = 1038,
     TO_MAIN_CAPTION = 1039,
     CLEARSTAT = 1040,
     TO_MENUITEM = 1041,
     ID_TO_INT = 1042,
     TO_STATUSBOX = 1043,
     ASCII_HEIGHT_ALL = 1044,
     ASCII_WIDTH_ALL = 1045,
     IMPORT_DATATYPE = 1046,
     PAGE_TRAILER_SIZE = 1047,
     PAGE_HEADER_SIZE = 1048,
     FIRST_PAGE_HEADER_SIZE = 1049,
     BYTES_USE_AS_IMAGE = 1050,
     BYTES_USE_AS_ASCII = 1051,
     KWUP_BY = 1052,
     KWDOWN_BY = 1053,
     CLOSE_STATUSBOX = 1054,
     MODIFY_NEXT_SIZE = 1055,
     LOCK_MODE_PAGE = 1056,
     LOCK_MODE_ROW = 1057,
     TO_PIPE = 1058,
     TO_PRINTER = 1059,
     STATUSBOX = 1060,
     CONNECT_TO = 1061,
     FORMHANDLER_INPUT = 1062,
     UNITS_YEAR = 1063,
     UNITS_MONTH = 1064,
     UNITS_DAY = 1065,
     UNITS_HOUR = 1066,
     UNITS_MINUTE = 1067,
     UNITS_SECOND = 1068,
     NO_NEW_LINES = 1069,
     FIELDTOWIDGET = 1070,
     WITH_HOLD = 1071,
     SHOW_MENU = 1072,
     CWIS = 1073,
     CREATE_IDX = 1074,
     FORM_IS_COMPILED = 1075,
     PDF_REPORT = 1076,
     IMPORT_FUNCTION = 1077,
     PROMPT_MANY = 1078,
     POINTS = 1079,
     MM = 1080,
     INCHES = 1081,
     PREPEND = 1082,
     MEMBER_OF = 1083,
     MEMBER_FUNCTION = 1084,
     APPEND = 1085,
     TEMPLATE = 1086,
     END_TEMPLATE = 1087,
     SQLSICS = 1088,
     CREATE_SCHEMA = 1089,
     SQLSIRR = 1090,
     UPDATESTATS_T = 1091,
     SQLSICR = 1092,
     WHENEVER_SQLSUCCESS = 1093,
     WHENEVER_SQLWARNING = 1094,
     START_EXTERN = 1095,
     WHENEVER_ANY_ERROR = 1096,
     WHENEVER_NOT_FOUND = 1097,
     CONTINUE_CONSTRUCT = 1098,
     FOUNCONSTR = 1099,
     SQLSIDR = 1100,
     WHENEVER_SQLERROR = 1101,
     CREATE_TEMP_TABLE = 1102,
     CURRENT_WINDOW_IS = 1103,
     FIRST_PAGE_HEADER = 1104,
     ORDER_EXTERNAL_BY = 1105,
     SCROLL_CURSOR_FOR = 1106,
     SCROLL_CURSOR = 1107,
     SQL_INTERRUPT_OFF = 1108,
     STOP_ALL_EXTERNAL = 1109,
     WITH_CHECK_OPTION = 1110,
     WITH_GRANT_OPTION = 1111,
     SQLSLMNW = 1112,
     ADDCONSTUNIQ = 1113,
     CONTINUE_DISPLAY = 1114,
     CONTINUE_FOREACH = 1115,
     OUTPUT_TO_REPORT = 1116,
     SQL_INTERRUPT_ON = 1117,
     WHENEVER_SUCCESS = 1118,
     WHENEVER_WARNING = 1119,
     WHERE_CURRENT_OF = 1120,
     WITHOUT_DEFAULTS = 1121,
     FOCONSTR = 1122,
     SCALED_BY = 1123,
     CONTINUE_PROMPT = 1124,
     PDF_FUNCTION = 1125,
     DEFER_INTERRUPT = 1126,
     DISPLAY_BY_NAME = 1127,
     NOT_NULL_UNIQUE = 1128,
     SKIP_TO_TOP = 1129,
     TOP_OF_PAGE = 1130,
     SKIP_TO = 1131,
     SKIP_BY = 1132,
     WITHOUT_WAITING = 1133,
     BEFCONSTRUCT = 1134,
     SQLSLMW = 1135,
     WHENEVER_ERROR = 1136,
     AFTCONSTRUCT = 1137,
     ALL_PRIVILEGES = 1138,
     CLOSE_DATABASE = 1139,
     CONTINUE_INPUT = 1140,
     CONTINUE_WHILE = 1141,
     CREATE_SYNONYM = 1142,
     DROP_TABLE = 1143,
     EXIT_CONSTRUCT = 1144,
     INEXCLUSIVE = 1145,
     REPORT_TO_PRINTER = 1146,
     REPORT_TO_PIPE = 1147,
     RETURN = 1148,
     SET_SESSION_TO = 1149,
     UPDATESTATS = 1150,
     WITHOUT_HEAD = 1151,
     CLEARSCR = 1152,
     WITH_B_LOG = 1153,
     AUTHORIZATION = 1154,
     BOTTOM_MARGIN = 1155,
     CLOSE_SESSION = 1156,
     CONTINUE_CASE = 1157,
     CONTINUE_MENU = 1158,
     DISPLAY_ARRAY = 1159,
     END_SQL = 1160,
     DOLLAR = 1161,
     END_CONSTRUCT = 1162,
     FIELD_TOUCHED = 1163,
     FINISH_REPORT = 1164,
     INFACC = 1165,
     INPUT_NO_WRAP = 1166,
     LOCKMODEPAGE = 1167,
     SETPMOFF = 1168,
     UNCONSTRAINED = 1169,
     PAGE_TRAILER = 1170,
     SETPMON = 1171,
     BEFGROUP = 1172,
     CLOSE_WINDOW = 1173,
     COMMENT_LINE = 1174,
     CONTINUE_FOR = 1175,
     CREATE_DB = 1176,
     CREATE_TABLE = 1177,
     DEFAULT_NULL = 1178,
     DELETE_USING = 1179,
     DISPLAY_FORM = 1180,
     END_FUNCTION = 1181,
     EXIT_DISPLAY = 1182,
     EXIT_FOREACH = 1183,
     EXIT_PROGRAM = 1184,
     INFCOLS = 1185,
     LOCKMODEROW = 1186,
     ON_EVERY_ROW = 1187,
     OPEN_SESSION = 1188,
     RIGHT_MARGIN = 1189,
     SELECT_USING = 1190,
     START_REPORT = 1191,
     UNLOCK_TABLE = 1192,
     UPDATE_USING = 1193,
     ACL_BUILTIN = 1194,
     AFTGROUP = 1195,
     INFIDX = 1196,
     INFSTAT = 1197,
     LEFT_MARGIN = 1198,
     PAGE_HEADER = 1199,
     ROLLBACK_W = 1200,
     SET_SESSION = 1201,
     SQLSEOFF = 1202,
     WITH_A_LOG = 1203,
     BEFDISP = 1204,
     BEFORE_MENU = 1205,
     CREATE_VIEW = 1206,
     DEFINE_TYPE = 1207,
     DELETE_FROM = 1208,
     END_DISPLAY = 1209,
     END_REPORT = 1210,
     END_FOREACH = 1211,
     END_FOR = 1212,
     END_GLOBALS = 1213,
     EXIT_PROMPT = 1214,
     EXTENT_SIZE = 1215,
     FOREIGN_KEY = 1216,
     HIDE_OPTION = 1217,
     HIDE_WINDOW = 1218,
     INSERT_INTO = 1219,
     IS_NOT_NULL = 1220,
     MOVE_WINDOW = 1221,
     NEXT_OPTION = 1222,
     NOT_MATCHES = 1223,
     ON_LAST_ROW = 1224,
     OPEN_WINDOW = 1225,
     OPEN_STATUSBOX = 1226,
     PAGE_LENGTH = 1227,
     PAGE_WIDTH = 1228,
     PRIMARY_KEY = 1229,
     PROMPT_LINE = 1230,
     RECORD_LIKE = 1231,
     ROLLFORWARD = 1232,
     SETBL = 1233,
     SHOW_OPTION = 1234,
     SHOW_WINDOW = 1235,
     SQLSEON = 1236,
     TO_DATABASE = 1237,
     USE_SESSION = 1238,
     WITH_NO_LOG = 1239,
     AFTDISP = 1240,
     BEFFIELD = 1241,
     INSHARE = 1242,
     UNLOCKTAB = 1243,
     AFTFIELD = 1244,
     ATTRIBUTES = 1245,
     BEFINP = 1246,
     BEGIN_WORK = 1247,
     CLEARWIN = 1248,
     CLOSE_FORM = 1249,
     DEFER_QUIT = 1250,
     DESCENDING = 1251,
     DROP_INDEX = 1252,
     END_PROMPT = 1253,
     END_RECORD = 1254,
     ERROR_LINE = 1255,
     EXIT_INPUT = 1256,
     EXIT_WHILE = 1257,
     FOR_UPDATE_OF = 1258,
     FOR_UPDATE = 1259,
     GET_FLDBUF = 1260,
     INITIALIZE = 1261,
     INPUT_WRAP = 1262,
     LOCK_TABLE = 1263,
     MSG_LINE = 1264,
     NOT_EXISTS = 1265,
     ON_ANY_KEY = 1266,
     REFERENCES = 1267,
     RENCOL = 1268,
     SET_CURSOR = 1269,
     SMALLFLOAT = 1270,
     SQLSUCCESS = 1271,
     TOP_MARGIN = 1272,
     WITH_ARRAY = 1273,
     ACCEPTKEY = 1274,
     ACCEPT = 1275,
     AFTINP = 1276,
     CLEARFORMTODEFAULTS = 1277,
     CLEARFORM = 1278,
     CLEAR_X_FORM = 1279,
     COMMIT_W = 1280,
     NEXTPAGE = 1281,
     PREVPAGE = 1282,
     CTRL_KEY = 1283,
     INFTABS = 1284,
     NEXTFIELD = 1285,
     NEXTFORM = 1286,
     RENTAB = 1287,
     ASCENDING = 1288,
     ASSOCIATE = 1289,
     CHARACTER = 1290,
     CONSTRUCT = 1291,
     DELIMITER = 1292,
     DOWNSHIFT = 1293,
     DROP_VIEW = 1294,
     END_INPUT = 1295,
     END_WHILE = 1296,
     EXCLUSIVE = 1297,
     EXIT_CASE = 1298,
     EXIT_MENU = 1299,
     FORM_LINE = 1300,
     INTERRUPT = 1302,
     INTO_TEMP = 1303,
     INVISIBLE = 1304,
     IN_MEMORY = 1305,
     LINKED_TO = 1306,
     LOAD_FROM = 1307,
     LOCKTAB = 1308,
     MENU_LINE = 1309,
     OPEN_FORM = 1310,
     OTHERWISE = 1311,
     PRECISION = 1312,
     PRIOR = 1313,
     PROCEDURE = 1314,
     REPORT_TO = 1315,
     RETURNING = 1316,
     UNDERLINE = 1317,
     UNLOAD_TO = 1318,
     BEFROW = 1319,
     UNLOAD_T = 1320,
     VARIABLE = 1321,
     ABSOLUTE = 1322,
     AFTROW = 1323,
     BUFFERED = 1324,
     CONSTANT = 1325,
     CONST = 1326,
     CONTINUE = 1327,
     DATABASE = 1328,
     DATETIME = 1329,
     DEFAULTS = 1330,
     DISTINCT = 1331,
     END_CASE = 1332,
     END_MAIN = 1333,
     END_MENU = 1334,
     END_TYPE = 1335,
     EXIT_FOR = 1336,
     EXTERNAL = 1337,
     FRACTION = 1338,
     FUNCTION = 1339,
     GROUP_BY = 1340,
     INTERVAL = 1341,
     KWMESSAGE = 1342,
     NOT_LIKE = 1343,
     NOT_ILIKE = 1344,
     NOT_NULL = 1345,
     PASSWORD = 1346,
     PREVIOUS = 1347,
     READONLY = 1348,
     REGISTER = 1349,
     RELATIVE = 1350,
     RESOURCE = 1351,
     SMALLINT = 1352,
     VALIDATE = 1353,
     WHENEVER = 1354,
     WITH_LOG = 1355,
     WORDWRAP = 1356,
     BY_NAME = 1357,
     IN_FILE = 1358,
     IS_NULL = 1359,
     AVERAGE = 1361,
     BETWEEN = 1362,
     CAPTION = 1363,
     CLIPPED = 1364,
     CLOSE_BRACKET = 1365,
     COLUMNS = 1366,
     COMMENT = 1368,
     CONNECT = 1369,
     CURRENT = 1370,
     DBYNAME = 1371,
     DECIMAL = 1372,
     DECLARE = 1373,
     DEFAULT = 1374,
     DISPLAY = 1375,
     ENDCODE = 1376,
     EXECUTE = 1377,
     FOREACH = 1378,
     FOREIGN = 1379,
     GLOBALS = 1380,
     INFIELD = 1381,
     INTEGER = 1382,
     KWWINDOW = 1383,
     MAGENTA = 1384,
     NUMERIC = 1386,
     OPTIONS = 1387,
     PERCENT = 1388,
     PREPARE = 1389,
     PROGRAM = 1390,
     RECOVER = 1391,
     REVERSE = 1392,
     SECTION = 1393,
     SESSION = 1394,
     SYNONYM = 1395,
     THRU = 1396,
     TRAILER = 1397,
     UPSHIFT = 1398,
     VARCHAR = 1399,
     WAITING = 1400,
     CLOSE_SHEV = 1401,
     CLOSE_SQUARE = 1402,
     KW_FALSE = 1404,
     NOT_IN = 1405,
     ONKEY = 1406,
     OPEN_BRACKET = 1407,
     BORDER = 1408,
     BOTTOM = 1409,
     COLUMN = 1410,
     COMMIT = 1411,
     CREATE = 1412,
     CURSOR = 1413,
     DEFINE = 1414,
     DELETE = 1415,
     DOUBLE = 1416,
     END_IF = 1417,
     ESCAPE = 1418,
     EXISTS = 1419,
     EXTEND = 1420,
     EXTENT = 1421,
     FINISH = 1422,
     FORMAT = 1423,
     HAVING = 1424,
     HEADER = 1425,
     INSERT = 1426,
     LOCATE = 1427,
     MARGIN = 1428,
     MEMORY = 1429,
     MINUTE = 1430,
     MODIFY = 1431,
     NORMAL = 1432,
     EQUAL_EQUAL = 1433,
     OPEN_SHEV = 1435,
     OPEN_SQUARE = 1436,
     OPTION = 1437,
     OUTPUT = 1438,
     PROMPT = 1439,
     PUBLIC = 1440,
     RECORD = 1441,
     REPORT = 1442,
     REVOKE = 1443,
     SCHEMA = 1444,
     SCROLL_USING = 1445,
     SCROLL = 1446,
     SECOND = 1447,
     SELECT = 1448,
     SERIAL = 1449,
     SETL = 1450,
     SHARED = 1451,
     SPACES = 1452,
     UNIQUE = 1453,
     UNLOCK = 1454,
     UPDATE = 1455,
     VALUES = 1456,
     YELLOW = 1457,
     AFTER = 1458,
     KWLINE = 1459,
     KW_NULL = 1460,
     KW_TRUE = 1461,
     SINGLE_KEY = 1462,
     ALTER = 1463,
     ARRAY = 1464,
     ASCII = 1465,
     AUDIT = 1466,
     BLACK = 1467,
     BLINK = 1468,
     CHECK = 1469,
     CLEAR = 1470,
     CLOSE = 1471,
     CODE_C = 1472,
     COUNT = 1473,
     DEFER = 1474,
     ERROR = 1475,
     EVERY = 1476,
     FETCH = 1477,
     FIRST = 1478,
     FLOAT = 1479,
     FLUSH = 1480,
     FOUND = 1481,
     GRANT = 1482,
     GREEN = 1483,
     GROUP = 1484,
     INDEX = 1485,
     KWFORM = 1486,
     LABEL = 1487,
     LOCAL = 1489,
     MONEY = 1490,
     MONTH = 1491,
     ORDER = 1494,
     OUTER = 1495,
     PAUSE = 1496,
     PRINT_IMAGE = 1497,
     PRINT_FILE = 1498,
     PRINT = 1499,
     RIGHT = 1500,
     DOUBLE_COLON = 1501,
     SEMICOLON = 1502,
     SLEEP = 1503,
     TUPLE = 1504,
     UNION = 1505,
     WHERE = 1507,
     WHILE = 1508,
     WHITE = 1509,
     CCODE = 1510,
     ANSI = 1511,
     BLUE = 1512,
     BOLD = 1513,
     BYTE = 1514,
     FCALL = 1515,
     CASE = 1516,
     CHAR = 1517,
     CYAN = 1518,
     DATE = 1519,
     DESC = 1520,
     KWDOWN = 1522,
     TAB = 1523,
     DROP = 1524,
     ELSE = 1525,
     EXEC = 1526,
     EXIT = 1527,
     FREE = 1528,
     FROM = 1529,
     GOTO = 1530,
     HELP_FILE = 1531,
     LANG_FILE = 1532,
     HELP = 1533,
     HIDE = 1534,
     HOUR = 1535,
     INTO = 1536,
     LAST = 1537,
     LEFT = 1538,
     LIKE = 1539,
     MAIN = 1540,
     MENU = 1541,
     MODE = 1542,
     NEED = 1543,
     NEXT = 1544,
     NOCR = 1545,
     OPEN = 1546,
     QUIT = 1547,
     REAL = 1548,
     ROWS = 1549,
     SHOW = 1550,
     SIZE = 1551,
     SKIP = 1552,
     SOME = 1553,
     STEP = 1554,
     STOP = 1555,
     TEMP = 1556,
     TEXT = 1557,
     THEN = 1558,
     USER = 1559,
     WAIT = 1560,
     WHEN = 1561,
     WITH = 1562,
     WORK = 1563,
     YEAR = 1564,
     KW_IS = 1566,
     XSET = 1567,
     ADD = 1568,
     ALL = 1569,
     ANY = 1571,
     ASC = 1572,
     AVG = 1573,
     COLON = 1574,
     DAY = 1576,
     DBA = 1577,
     DEC = 1578,
     DIM = 1579,
     FKEY = 1580,
     FOR = 1581,
     KEY = 1582,
     KWNO = 1583,
     LET = 1584,
     LOG = 1585,
     XMAX = 1586,
     XMIN = 1587,
     PAD = 1591,
     PUT = 1592,
     RED = 1593,
     ROW = 1594,
     RUN = 1595,
     SQL = 1596,
     SUM = 1597,
     TOP = 1598,
     USE = 1599,
     ATSIGN = 1600,
     AS_TIFF = 1602,
     AS_GIF = 1603,
     AS_PNG = 1604,
     AS_JPEG = 1605,
     AS = 1606,
     AT = 1607,
     BY = 1608,
     DOT = 1609,
     GO = 1610,
     IF = 1611,
     IN = 1612,
     OF = 1613,
     ON = 1614,
     TO = 1616,
     KWUP = 1617,
     FONT_NAME = 1618,
     FONT_SIZE = 1619,
     PAPER_SIZE_IS_LETTER = 1620,
     PAPER_SIZE_IS_LEGAL = 1621,
     PAPER_SIZE_IS_A5 = 1622,
     PAPER_SIZE_IS_A4 = 1623,
     PAPER_SIZE_IS_LETTER_L = 1624,
     PAPER_SIZE_IS_LEGAL_L = 1625,
     PAPER_SIZE_IS_A5_L = 1626,
     PAPER_SIZE_IS_A4_L = 1627,
     FORMHANDLER = 1628,
     END_FORMHANDLER = 1629,
     BEFORE_EVENT = 1630,
     BEFORE_OPEN_FORM = 1631,
     AFTER_EVENT = 1632,
     BEFORE_CLOSE_FORM = 1633,
     BEFORE_ANY = 1634,
     AFTER_ANY = 1635,
     MENUHANDLER = 1636,
     END_MENUHANDLER = 1637,
     BEFORE_SHOW_MENU = 1638,
     DISABLE_PROGRAM = 1639,
     DISABLE_ALL = 1640,
     BUTTONS = 1641,
     CHECK_MENUITEM = 1642,
     DISABLE_FORM = 1643,
     DISABLE_MENUITEMS = 1644,
     DISABLE = 1645,
     ENABLE_FORM = 1646,
     ENABLE_MENUITEMS = 1647,
     ENABLE = 1648,
     KWFIELD = 1649,
     ICON = 1650,
     MESSAGEBOX = 1651,
     TO_DEFAULTS = 1652,
     UNCHECK_MENUITEM = 1653,
     BEFORE = 1654,
     INPUT = 1655,
     END = 1656,
     INT_TO_ID = 1657,
     TIMEOUT = 1658,
     OFF = 1659,
     WITH_1_DIMENSION = 1660,
     WITH_2_DIMENSION = 1661,
     WITH_3_DIMENSION = 1662,
     TILDE = 1663,
     ILIKE = 1664
   };
#endif
#define NAME 1666
#define UMINUS 1667
#define COMMA 1575
#define KW_OR 1615
#define KW_AND 1570
#define KW_USING 1506
#define NOT 1590
#define MATCHES 1385
#define POWER 1492
#define LESS_THAN 1488
#define GREATER_THAN 1403
#define EQUAL 1565
#define GREATER_THAN_EQ 1301
#define LESS_THAN_EQ 1360
#define NOT_EQUAL 1434
#define PLUS 1601
#define MINUS 1588
#define MULTIPLY 1493
#define DIVIDE 1521
#define MOD 1589
#define COMMAND 1367
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
#define DYNAMIC_ARRAY 1000
#define RESIZE_ARRAY 1001
#define ALLOCATE_ARRAY 1002
#define DEALLOCATE_ARRAY 1003
#define BEFORE_INSERT 1004
#define CONCAT_PIPES 1005
#define BEFORE_DELETE 1006
#define AFTER_INSERT 1007
#define AFTER_DELETE 1008
#define EXECUTE_IMMEDIATE 1009
#define DELETE_ROW_EQUAL_TRUE 1010
#define INSERT_ROW_EQUAL_TRUE 1011
#define DELETE_ROW_EQUAL_FALSE 1012
#define INSERT_ROW_EQUAL_FALSE 1013
#define CURRENT_ROW_DISPLAY_EQUAL 1014
#define MAXCOUNT 1015
#define ALTER_TABLE 1016
#define WHENEVER_ERROR_CONTINUE 1017
#define WHENEVER_WARNING_CONTINUE 1018
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1019
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1020
#define XSET_ident_DOT_MULTIPLY_EQUAL 1021
#define XSET_MULTIPLY_EQUAL 1022
#define XSET_OPEN_BRACKET 1023
#define NEWFORMATSHARED 1024
#define CREATE_DATABASE 1025
#define IMPORT_LEGACY_FUNCTION 1026
#define ADD_CONSTRAINT 1027
#define DROP_CONSTRAINT 1028
#define AS_STATIC 1029
#define NOT_FIELD_TOUCHED 1030
#define LOCAL_FUNCTION 1031
#define EVERY_ROW 1032
#define ELIF 1033
#define DOUBLE_PRECISION 1034
#define COUNT_MULTIPLY 1035
#define WAIT_FOR_KEY 1036
#define AT_TERMINATION_CALL 1037
#define TERMINATE_REPORT 1038
#define TO_MAIN_CAPTION 1039
#define CLEARSTAT 1040
#define TO_MENUITEM 1041
#define ID_TO_INT 1042
#define TO_STATUSBOX 1043
#define ASCII_HEIGHT_ALL 1044
#define ASCII_WIDTH_ALL 1045
#define IMPORT_DATATYPE 1046
#define PAGE_TRAILER_SIZE 1047
#define PAGE_HEADER_SIZE 1048
#define FIRST_PAGE_HEADER_SIZE 1049
#define BYTES_USE_AS_IMAGE 1050
#define BYTES_USE_AS_ASCII 1051
#define KWUP_BY 1052
#define KWDOWN_BY 1053
#define CLOSE_STATUSBOX 1054
#define MODIFY_NEXT_SIZE 1055
#define LOCK_MODE_PAGE 1056
#define LOCK_MODE_ROW 1057
#define TO_PIPE 1058
#define TO_PRINTER 1059
#define STATUSBOX 1060
#define CONNECT_TO 1061
#define FORMHANDLER_INPUT 1062
#define UNITS_YEAR 1063
#define UNITS_MONTH 1064
#define UNITS_DAY 1065
#define UNITS_HOUR 1066
#define UNITS_MINUTE 1067
#define UNITS_SECOND 1068
#define NO_NEW_LINES 1069
#define FIELDTOWIDGET 1070
#define WITH_HOLD 1071
#define SHOW_MENU 1072
#define CWIS 1073
#define CREATE_IDX 1074
#define FORM_IS_COMPILED 1075
#define PDF_REPORT 1076
#define IMPORT_FUNCTION 1077
#define PROMPT_MANY 1078
#define POINTS 1079
#define MM 1080
#define INCHES 1081
#define PREPEND 1082
#define MEMBER_OF 1083
#define MEMBER_FUNCTION 1084
#define APPEND 1085
#define TEMPLATE 1086
#define END_TEMPLATE 1087
#define SQLSICS 1088
#define CREATE_SCHEMA 1089
#define SQLSIRR 1090
#define UPDATESTATS_T 1091
#define SQLSICR 1092
#define WHENEVER_SQLSUCCESS 1093
#define WHENEVER_SQLWARNING 1094
#define START_EXTERN 1095
#define WHENEVER_ANY_ERROR 1096
#define WHENEVER_NOT_FOUND 1097
#define CONTINUE_CONSTRUCT 1098
#define FOUNCONSTR 1099
#define SQLSIDR 1100
#define WHENEVER_SQLERROR 1101
#define CREATE_TEMP_TABLE 1102
#define CURRENT_WINDOW_IS 1103
#define FIRST_PAGE_HEADER 1104
#define ORDER_EXTERNAL_BY 1105
#define SCROLL_CURSOR_FOR 1106
#define SCROLL_CURSOR 1107
#define SQL_INTERRUPT_OFF 1108
#define STOP_ALL_EXTERNAL 1109
#define WITH_CHECK_OPTION 1110
#define WITH_GRANT_OPTION 1111
#define SQLSLMNW 1112
#define ADDCONSTUNIQ 1113
#define CONTINUE_DISPLAY 1114
#define CONTINUE_FOREACH 1115
#define OUTPUT_TO_REPORT 1116
#define SQL_INTERRUPT_ON 1117
#define WHENEVER_SUCCESS 1118
#define WHENEVER_WARNING 1119
#define WHERE_CURRENT_OF 1120
#define WITHOUT_DEFAULTS 1121
#define FOCONSTR 1122
#define SCALED_BY 1123
#define CONTINUE_PROMPT 1124
#define PDF_FUNCTION 1125
#define DEFER_INTERRUPT 1126
#define DISPLAY_BY_NAME 1127
#define NOT_NULL_UNIQUE 1128
#define SKIP_TO_TOP 1129
#define TOP_OF_PAGE 1130
#define SKIP_TO 1131
#define SKIP_BY 1132
#define WITHOUT_WAITING 1133
#define BEFCONSTRUCT 1134
#define SQLSLMW 1135
#define WHENEVER_ERROR 1136
#define AFTCONSTRUCT 1137
#define ALL_PRIVILEGES 1138
#define CLOSE_DATABASE 1139
#define CONTINUE_INPUT 1140
#define CONTINUE_WHILE 1141
#define CREATE_SYNONYM 1142
#define DROP_TABLE 1143
#define EXIT_CONSTRUCT 1144
#define INEXCLUSIVE 1145
#define REPORT_TO_PRINTER 1146
#define REPORT_TO_PIPE 1147
#define RETURN 1148
#define SET_SESSION_TO 1149
#define UPDATESTATS 1150
#define WITHOUT_HEAD 1151
#define CLEARSCR 1152
#define WITH_B_LOG 1153
#define AUTHORIZATION 1154
#define BOTTOM_MARGIN 1155
#define CLOSE_SESSION 1156
#define CONTINUE_CASE 1157
#define CONTINUE_MENU 1158
#define DISPLAY_ARRAY 1159
#define END_SQL 1160
#define DOLLAR 1161
#define END_CONSTRUCT 1162
#define FIELD_TOUCHED 1163
#define FINISH_REPORT 1164
#define INFACC 1165
#define INPUT_NO_WRAP 1166
#define LOCKMODEPAGE 1167
#define SETPMOFF 1168
#define UNCONSTRAINED 1169
#define PAGE_TRAILER 1170
#define SETPMON 1171
#define BEFGROUP 1172
#define CLOSE_WINDOW 1173
#define COMMENT_LINE 1174
#define CONTINUE_FOR 1175
#define CREATE_DB 1176
#define CREATE_TABLE 1177
#define DEFAULT_NULL 1178
#define DELETE_USING 1179
#define DISPLAY_FORM 1180
#define END_FUNCTION 1181
#define EXIT_DISPLAY 1182
#define EXIT_FOREACH 1183
#define EXIT_PROGRAM 1184
#define INFCOLS 1185
#define LOCKMODEROW 1186
#define ON_EVERY_ROW 1187
#define OPEN_SESSION 1188
#define RIGHT_MARGIN 1189
#define SELECT_USING 1190
#define START_REPORT 1191
#define UNLOCK_TABLE 1192
#define UPDATE_USING 1193
#define ACL_BUILTIN 1194
#define AFTGROUP 1195
#define INFIDX 1196
#define INFSTAT 1197
#define LEFT_MARGIN 1198
#define PAGE_HEADER 1199
#define ROLLBACK_W 1200
#define SET_SESSION 1201
#define SQLSEOFF 1202
#define WITH_A_LOG 1203
#define BEFDISP 1204
#define BEFORE_MENU 1205
#define CREATE_VIEW 1206
#define DEFINE_TYPE 1207
#define DELETE_FROM 1208
#define END_DISPLAY 1209
#define END_REPORT 1210
#define END_FOREACH 1211
#define END_FOR 1212
#define END_GLOBALS 1213
#define EXIT_PROMPT 1214
#define EXTENT_SIZE 1215
#define FOREIGN_KEY 1216
#define HIDE_OPTION 1217
#define HIDE_WINDOW 1218
#define INSERT_INTO 1219
#define IS_NOT_NULL 1220
#define MOVE_WINDOW 1221
#define NEXT_OPTION 1222
#define NOT_MATCHES 1223
#define ON_LAST_ROW 1224
#define OPEN_WINDOW 1225
#define OPEN_STATUSBOX 1226
#define PAGE_LENGTH 1227
#define PAGE_WIDTH 1228
#define PRIMARY_KEY 1229
#define PROMPT_LINE 1230
#define RECORD_LIKE 1231
#define ROLLFORWARD 1232
#define SETBL 1233
#define SHOW_OPTION 1234
#define SHOW_WINDOW 1235
#define SQLSEON 1236
#define TO_DATABASE 1237
#define USE_SESSION 1238
#define WITH_NO_LOG 1239
#define AFTDISP 1240
#define BEFFIELD 1241
#define INSHARE 1242
#define UNLOCKTAB 1243
#define AFTFIELD 1244
#define ATTRIBUTES 1245
#define BEFINP 1246
#define BEGIN_WORK 1247
#define CLEARWIN 1248
#define CLOSE_FORM 1249
#define DEFER_QUIT 1250
#define DESCENDING 1251
#define DROP_INDEX 1252
#define END_PROMPT 1253
#define END_RECORD 1254
#define ERROR_LINE 1255
#define EXIT_INPUT 1256
#define EXIT_WHILE 1257
#define FOR_UPDATE_OF 1258
#define FOR_UPDATE 1259
#define GET_FLDBUF 1260
#define INITIALIZE 1261
#define INPUT_WRAP 1262
#define LOCK_TABLE 1263
#define MSG_LINE 1264
#define NOT_EXISTS 1265
#define ON_ANY_KEY 1266
#define REFERENCES 1267
#define RENCOL 1268
#define SET_CURSOR 1269
#define SMALLFLOAT 1270
#define SQLSUCCESS 1271
#define TOP_MARGIN 1272
#define WITH_ARRAY 1273
#define ACCEPTKEY 1274
#define ACCEPT 1275
#define AFTINP 1276
#define CLEARFORMTODEFAULTS 1277
#define CLEARFORM 1278
#define CLEAR_X_FORM 1279
#define COMMIT_W 1280
#define NEXTPAGE 1281
#define PREVPAGE 1282
#define CTRL_KEY 1283
#define INFTABS 1284
#define NEXTFIELD 1285
#define NEXTFORM 1286
#define RENTAB 1287
#define ASCENDING 1288
#define ASSOCIATE 1289
#define CHARACTER 1290
#define CONSTRUCT 1291
#define DELIMITER 1292
#define DOWNSHIFT 1293
#define DROP_VIEW 1294
#define END_INPUT 1295
#define END_WHILE 1296
#define EXCLUSIVE 1297
#define EXIT_CASE 1298
#define EXIT_MENU 1299
#define FORM_LINE 1300
#define INTERRUPT 1302
#define INTO_TEMP 1303
#define INVISIBLE 1304
#define IN_MEMORY 1305
#define LINKED_TO 1306
#define LOAD_FROM 1307
#define LOCKTAB 1308
#define MENU_LINE 1309
#define OPEN_FORM 1310
#define OTHERWISE 1311
#define PRECISION 1312
#define PRIOR 1313
#define PROCEDURE 1314
#define REPORT_TO 1315
#define RETURNING 1316
#define UNDERLINE 1317
#define UNLOAD_TO 1318
#define BEFROW 1319
#define UNLOAD_T 1320
#define VARIABLE 1321
#define ABSOLUTE 1322
#define AFTROW 1323
#define BUFFERED 1324
#define CONSTANT 1325
#define CONST 1326
#define CONTINUE 1327
#define DATABASE 1328
#define DATETIME 1329
#define DEFAULTS 1330
#define DISTINCT 1331
#define END_CASE 1332
#define END_MAIN 1333
#define END_MENU 1334
#define END_TYPE 1335
#define EXIT_FOR 1336
#define EXTERNAL 1337
#define FRACTION 1338
#define FUNCTION 1339
#define GROUP_BY 1340
#define INTERVAL 1341
#define KWMESSAGE 1342
#define NOT_LIKE 1343
#define NOT_ILIKE 1344
#define NOT_NULL 1345
#define PASSWORD 1346
#define PREVIOUS 1347
#define READONLY 1348
#define REGISTER 1349
#define RELATIVE 1350
#define RESOURCE 1351
#define SMALLINT 1352
#define VALIDATE 1353
#define WHENEVER 1354
#define WITH_LOG 1355
#define WORDWRAP 1356
#define BY_NAME 1357
#define IN_FILE 1358
#define IS_NULL 1359
#define AVERAGE 1361
#define BETWEEN 1362
#define CAPTION 1363
#define CLIPPED 1364
#define CLOSE_BRACKET 1365
#define COLUMNS 1366
#define COMMENT 1368
#define CONNECT 1369
#define CURRENT 1370
#define DBYNAME 1371
#define DECIMAL 1372
#define DECLARE 1373
#define DEFAULT 1374
#define DISPLAY 1375
#define ENDCODE 1376
#define EXECUTE 1377
#define FOREACH 1378
#define FOREIGN 1379
#define GLOBALS 1380
#define INFIELD 1381
#define INTEGER 1382
#define KWWINDOW 1383
#define MAGENTA 1384
#define NUMERIC 1386
#define OPTIONS 1387
#define PERCENT 1388
#define PREPARE 1389
#define PROGRAM 1390
#define RECOVER 1391
#define REVERSE 1392
#define SECTION 1393
#define SESSION 1394
#define SYNONYM 1395
#define THRU 1396
#define TRAILER 1397
#define UPSHIFT 1398
#define VARCHAR 1399
#define WAITING 1400
#define CLOSE_SHEV 1401
#define CLOSE_SQUARE 1402
#define KW_FALSE 1404
#define NOT_IN 1405
#define ONKEY 1406
#define OPEN_BRACKET 1407
#define BORDER 1408
#define BOTTOM 1409
#define COLUMN 1410
#define COMMIT 1411
#define CREATE 1412
#define CURSOR 1413
#define DEFINE 1414
#define DELETE 1415
#define DOUBLE 1416
#define END_IF 1417
#define ESCAPE 1418
#define EXISTS 1419
#define EXTEND 1420
#define EXTENT 1421
#define FINISH 1422
#define FORMAT 1423
#define HAVING 1424
#define HEADER 1425
#define INSERT 1426
#define LOCATE 1427
#define MARGIN 1428
#define MEMORY 1429
#define MINUTE 1430
#define MODIFY 1431
#define NORMAL 1432
#define EQUAL_EQUAL 1433
#define OPEN_SHEV 1435
#define OPEN_SQUARE 1436
#define OPTION 1437
#define OUTPUT 1438
#define PROMPT 1439
#define PUBLIC 1440
#define RECORD 1441
#define REPORT 1442
#define REVOKE 1443
#define SCHEMA 1444
#define SCROLL_USING 1445
#define SCROLL 1446
#define SECOND 1447
#define SELECT 1448
#define SERIAL 1449
#define SETL 1450
#define SHARED 1451
#define SPACES 1452
#define UNIQUE 1453
#define UNLOCK 1454
#define UPDATE 1455
#define VALUES 1456
#define YELLOW 1457
#define AFTER 1458
#define KWLINE 1459
#define KW_NULL 1460
#define KW_TRUE 1461
#define SINGLE_KEY 1462
#define ALTER 1463
#define ARRAY 1464
#define ASCII 1465
#define AUDIT 1466
#define BLACK 1467
#define BLINK 1468
#define CHECK 1469
#define CLEAR 1470
#define CLOSE 1471
#define CODE_C 1472
#define COUNT 1473
#define DEFER 1474
#define ERROR 1475
#define EVERY 1476
#define FETCH 1477
#define FIRST 1478
#define FLOAT 1479
#define FLUSH 1480
#define FOUND 1481
#define GRANT 1482
#define GREEN 1483
#define GROUP 1484
#define INDEX 1485
#define KWFORM 1486
#define LABEL 1487
#define LOCAL 1489
#define MONEY 1490
#define MONTH 1491
#define ORDER 1494
#define OUTER 1495
#define PAUSE 1496
#define PRINT_IMAGE 1497
#define PRINT_FILE 1498
#define PRINT 1499
#define RIGHT 1500
#define DOUBLE_COLON 1501
#define SEMICOLON 1502
#define SLEEP 1503
#define TUPLE 1504
#define UNION 1505
#define WHERE 1507
#define WHILE 1508
#define WHITE 1509
#define CCODE 1510
#define ANSI 1511
#define BLUE 1512
#define BOLD 1513
#define BYTE 1514
#define FCALL 1515
#define CASE 1516
#define CHAR 1517
#define CYAN 1518
#define DATE 1519
#define DESC 1520
#define KWDOWN 1522
#define TAB 1523
#define DROP 1524
#define ELSE 1525
#define EXEC 1526
#define EXIT 1527
#define FREE 1528
#define FROM 1529
#define GOTO 1530
#define HELP_FILE 1531
#define LANG_FILE 1532
#define HELP 1533
#define HIDE 1534
#define HOUR 1535
#define INTO 1536
#define LAST 1537
#define LEFT 1538
#define LIKE 1539
#define MAIN 1540
#define MENU 1541
#define MODE 1542
#define NEED 1543
#define NEXT 1544
#define NOCR 1545
#define OPEN 1546
#define QUIT 1547
#define REAL 1548
#define ROWS 1549
#define SHOW 1550
#define SIZE 1551
#define SKIP 1552
#define SOME 1553
#define STEP 1554
#define STOP 1555
#define TEMP 1556
#define TEXT 1557
#define THEN 1558
#define USER 1559
#define WAIT 1560
#define WHEN 1561
#define WITH 1562
#define WORK 1563
#define YEAR 1564
#define KW_IS 1566
#define XSET 1567
#define ADD 1568
#define ALL 1569
#define ANY 1571
#define ASC 1572
#define AVG 1573
#define COLON 1574
#define DAY 1576
#define DBA 1577
#define DEC 1578
#define DIM 1579
#define FKEY 1580
#define FOR 1581
#define KEY 1582
#define KWNO 1583
#define LET 1584
#define LOG 1585
#define XMAX 1586
#define XMIN 1587
#define PAD 1591
#define PUT 1592
#define RED 1593
#define ROW 1594
#define RUN 1595
#define SQL 1596
#define SUM 1597
#define TOP 1598
#define USE 1599
#define ATSIGN 1600
#define AS_TIFF 1602
#define AS_GIF 1603
#define AS_PNG 1604
#define AS_JPEG 1605
#define AS 1606
#define AT 1607
#define BY 1608
#define DOT 1609
#define GO 1610
#define IF 1611
#define IN 1612
#define OF 1613
#define ON 1614
#define TO 1616
#define KWUP 1617
#define FONT_NAME 1618
#define FONT_SIZE 1619
#define PAPER_SIZE_IS_LETTER 1620
#define PAPER_SIZE_IS_LEGAL 1621
#define PAPER_SIZE_IS_A5 1622
#define PAPER_SIZE_IS_A4 1623
#define PAPER_SIZE_IS_LETTER_L 1624
#define PAPER_SIZE_IS_LEGAL_L 1625
#define PAPER_SIZE_IS_A5_L 1626
#define PAPER_SIZE_IS_A4_L 1627
#define FORMHANDLER 1628
#define END_FORMHANDLER 1629
#define BEFORE_EVENT 1630
#define BEFORE_OPEN_FORM 1631
#define AFTER_EVENT 1632
#define BEFORE_CLOSE_FORM 1633
#define BEFORE_ANY 1634
#define AFTER_ANY 1635
#define MENUHANDLER 1636
#define END_MENUHANDLER 1637
#define BEFORE_SHOW_MENU 1638
#define DISABLE_PROGRAM 1639
#define DISABLE_ALL 1640
#define BUTTONS 1641
#define CHECK_MENUITEM 1642
#define DISABLE_FORM 1643
#define DISABLE_MENUITEMS 1644
#define DISABLE 1645
#define ENABLE_FORM 1646
#define ENABLE_MENUITEMS 1647
#define ENABLE 1648
#define KWFIELD 1649
#define ICON 1650
#define MESSAGEBOX 1651
#define TO_DEFAULTS 1652
#define UNCHECK_MENUITEM 1653
#define BEFORE 1654
#define INPUT 1655
#define END 1656
#define INT_TO_ID 1657
#define TIMEOUT 1658
#define OFF 1659
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
#define YYLAST   10147

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
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    15,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
      16,   393,   394,   395,   396,   397,   398,    23,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,    10,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,    13,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,    17,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,    12,   516,
     517,   518,    11,    20,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,     8,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,    21,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,    14,   588,   589,   590,   591,
       7,   592,   593,   594,   595,     5,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,    19,    22,
       9,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     617,    18,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,   630,     6,   631,   632,   633,   634,
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
    1043,     0,    -1,   205,    -1,   202,    -1,   129,   685,   432,
     601,   686,    -1,   143,    -1,  1108,    -1,    26,    -1,   687,
      -1,   686,     5,   687,    -1,   955,    -1,   436,   688,   397,
      -1,   688,   689,   688,    -1,    26,    -1,   690,    26,    -1,
    1108,    -1,   897,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   692,
      -1,    -1,   279,   436,   693,   694,   397,    -1,   574,   436,
      26,     5,    26,   397,    -1,   695,    -1,   694,     5,   695,
      -1,   495,    -1,   536,    -1,   542,    -1,   511,    -1,   415,
      -1,   610,    -1,   533,    -1,   485,    -1,   422,    -1,   496,
      -1,   350,    -1,   537,    -1,   461,    -1,   337,    -1,   599,
      -1,   103,    -1,  1022,    -1,    -1,   697,    -1,    -1,   279,
     436,   698,   699,   397,    -1,   700,    -1,   699,     5,   700,
      -1,   695,    -1,   437,    -1,   608,    25,    -1,   208,   942,
      -1,   334,   942,    -1,   289,   942,    -1,   342,   942,    -1,
     298,   942,    -1,   264,   942,    -1,   539,   702,    -1,   886,
     349,  1108,    -1,    -1,   294,   436,  1499,   397,   349,   703,
    1127,    -1,   109,   436,   955,     5,    25,     5,    25,   397,
      -1,   412,   436,   947,   397,   349,  1108,    -1,  1246,    -1,
     197,   436,   905,   397,   349,  1108,    -1,    -1,    -1,  1108,
     595,   955,   436,   704,   718,   397,   705,   716,    -1,    -1,
      -1,    -1,   955,   436,   706,   718,   707,   397,   708,   716,
      -1,    -1,    -1,   479,  1444,   628,  1444,   436,   709,   718,
     710,   397,   716,    -1,    -1,    -1,   955,   526,   955,   436,
     711,   718,   712,   397,   716,    -1,    -1,    -1,    -1,   370,
     721,   595,   722,   464,   685,   432,   436,   713,   718,   714,
     397,   715,   717,    -1,    -1,   349,  1127,    -1,    -1,   349,
    1127,    -1,   167,    -1,    -1,   719,    -1,   720,    -1,   719,
       5,   720,    -1,   855,    -1,    25,    -1,   955,    -1,   955,
      -1,   955,   625,   955,    -1,    -1,   540,   862,   724,   727,
     731,   728,    -1,    -1,   540,   725,   726,   729,   728,    -1,
     733,    -1,   726,   733,    -1,   735,    -1,   727,   735,    -1,
     365,    -1,    -1,    -1,   344,   730,  1509,    -1,    -1,    -1,
     344,   732,  1509,    -1,    -1,   584,   862,   734,  1509,    -1,
      -1,   584,   862,   736,  1509,    -1,   283,   952,    -1,   207,
     950,    -1,    88,   950,    -1,   173,    -1,   190,  1450,    -1,
     499,   949,    -1,    30,   739,    31,    -1,   740,    -1,   742,
      -1,   741,    -1,   740,   741,    -1,    29,    -1,   743,    -1,
     742,   743,    -1,    28,    -1,   399,    -1,    -1,    -1,   325,
     746,   748,   747,   749,    -1,   390,  1108,   630,   750,   996,
    1021,   691,    -1,  1108,   630,   750,   996,   552,  1499,  1021,
     691,    -1,    -1,   752,   196,    -1,   751,    -1,   750,     5,
     751,    -1,   955,    -1,   955,   625,   955,    -1,   955,   625,
      20,    -1,   753,    -1,   752,   753,    -1,    -1,   275,   759,
     754,  1509,    -1,    -1,   278,   760,   755,  1509,    -1,    -1,
    1024,   756,  1509,    -1,    -1,   171,   757,  1509,    -1,    -1,
     168,   758,  1509,    -1,   959,    -1,   759,     5,   959,    -1,
     959,    -1,   760,     5,   959,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   436,   855,
     763,   397,    -1,    -1,     5,   806,   631,   809,    -1,   160,
      -1,   284,    -1,    -1,   766,    -1,   767,    -1,   766,   767,
      -1,    -1,    -1,   443,   768,   770,   769,  1215,    -1,   819,
      -1,  1489,    -1,   773,    -1,   770,     5,   773,    -1,    -1,
     772,   955,    -1,   358,   771,   818,    25,    -1,   358,   771,
     818,   955,    -1,   358,   771,   818,   961,    -1,   358,   771,
     818,    26,    -1,   777,   795,    -1,    -1,   771,   358,   774,
     775,    -1,    26,    -1,    25,    -1,   961,    -1,    19,    26,
      -1,   771,    -1,   776,    -1,   777,     5,   776,    -1,    -1,
     541,    -1,    -1,   675,    -1,   676,    -1,   677,    -1,    -1,
     492,   464,   787,   432,   781,   629,   795,    -1,    -1,    34,
     779,   782,   629,   795,    -1,    -1,   323,   778,   784,    26,
     785,   307,   464,   786,   432,   783,   629,   795,    -1,   436,
      -1,   463,    -1,   397,    -1,   431,    -1,    26,    -1,   788,
       5,   788,     5,   788,    -1,   788,     5,   788,    -1,   788,
      -1,    26,    -1,    -1,   469,   790,   770,   288,    -1,    -1,
     265,   791,   771,   625,    20,    -1,    -1,   339,   792,   771,
     263,   436,   793,   397,    -1,   794,    -1,   793,     5,   794,
      -1,   771,    -1,   797,    -1,    -1,    63,    -1,    -1,    -1,
     798,   800,   799,   796,    -1,   780,    -1,   789,    -1,   541,
      -1,   541,   436,    26,   397,    -1,   429,   436,    26,   397,
      -1,   429,   436,    26,     5,    26,   397,    -1,   413,    -1,
     622,   771,    -1,   385,    -1,   514,    -1,    94,    -1,   403,
      -1,   403,   436,    26,   397,    -1,   403,   436,    26,     5,
      26,   397,    -1,   517,    -1,   517,   436,    26,   397,    -1,
     517,   436,    26,     5,    26,   397,    -1,   507,    -1,   304,
      -1,   543,    -1,   538,    -1,    84,    -1,    85,    -1,   580,
      -1,   362,   804,    -1,   374,   805,    -1,   801,    -1,    32,
      -1,   562,   802,   625,   803,    -1,   771,    -1,   771,    -1,
      -1,   806,   631,   809,    -1,   814,   631,   817,    -1,    -1,
     807,   808,    -1,   587,    -1,   518,    -1,   596,    -1,   558,
      -1,   459,    -1,   475,    -1,   371,   811,    -1,    -1,   810,
     808,    -1,    -1,   436,   813,   397,    -1,    -1,   436,    26,
     397,    -1,    26,    -1,    -1,   815,   816,   812,    -1,   587,
      -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,
      -1,   371,   811,    -1,   816,    -1,    -1,    14,    -1,    -1,
     241,   955,   820,   622,   821,    -1,   823,    -1,   826,    -1,
     541,    -1,   541,   436,    26,   397,    -1,   429,   436,    26,
     397,    -1,   429,   436,    26,     5,    26,   397,    -1,   413,
      -1,   385,    -1,   514,    -1,   403,    -1,   403,   436,    26,
     397,    -1,   403,   436,    26,     5,    26,   397,    -1,   517,
      -1,   517,   436,    26,   397,    -1,   517,   436,    26,     5,
      26,   397,    -1,   507,    -1,   304,    -1,   543,    -1,   538,
      -1,   580,    -1,   362,   804,    -1,   374,   805,    -1,   822,
      -1,   562,   802,   625,   803,    -1,    -1,   492,   464,   787,
     432,   824,   629,   821,    -1,    -1,   323,   778,   784,    26,
     785,   307,   464,   786,   432,   825,   629,   821,    -1,    -1,
     469,   827,   829,   288,    -1,    -1,   265,   828,   955,   625,
      20,    -1,   830,    -1,   829,     5,   830,    -1,   831,   821,
      -1,   832,    -1,   831,     5,   832,    -1,   955,    -1,    -1,
     623,   946,    -1,    75,   955,    -1,    73,    -1,   631,  1499,
      -1,   631,   514,   955,   664,  1499,    -1,   631,   514,   955,
     395,    -1,    77,   955,    -1,   161,   880,  1127,   841,    -1,
     406,   880,   860,   833,   841,    -1,   214,   952,   841,    -1,
      -1,    -1,   193,   838,  1134,   631,   955,   625,    20,   840,
     691,   839,   842,    -1,    -1,   473,   947,    -1,   691,    -1,
      -1,   843,   243,    -1,   844,    -1,   843,   844,    -1,    -1,
     356,   845,  1509,    -1,    -1,   352,   846,  1509,    -1,    -1,
    1024,   847,  1509,    -1,    36,  1108,    -1,    37,  1108,    -1,
      35,  1108,    -1,   503,   880,   861,   691,    -1,   503,   880,
     861,   691,    70,    -1,   291,    -1,   290,    -1,   217,    -1,
     369,    -1,   178,    -1,   216,    -1,   333,    -1,   332,    -1,
     248,    -1,   175,    -1,   174,    -1,   149,    -1,   209,    -1,
     132,    -1,   148,    -1,   192,    -1,   158,    -1,   218,    -1,
     218,   862,    -1,   865,    -1,   864,    -1,   869,    -1,   897,
      -1,   855,   856,    -1,   898,    -1,   900,    -1,   866,    -1,
      19,   855,    -1,    18,   855,    -1,   871,    -1,   879,    -1,
     873,    -1,   480,    -1,   761,    -1,   874,    -1,   875,    -1,
     876,    -1,   877,    -1,   878,    -1,    39,   855,    -1,   880,
      -1,   880,   859,    -1,   862,    -1,   488,    -1,   858,    -1,
     859,     5,   858,    -1,   862,    -1,   860,     5,   862,    -1,
     862,    -1,   861,     5,   862,    -1,   855,    -1,    18,    -1,
      19,    -1,     9,   855,    -1,   489,    -1,   433,    -1,   436,
     855,   397,    -1,   448,   436,  1424,   397,    -1,   299,   436,
    1424,   397,    -1,   863,   961,    -1,   863,    26,    -1,    25,
      -1,   961,    -1,    26,    -1,   868,    -1,  1108,    -1,  1108,
     426,  1108,    -1,   867,    -1,   439,   855,    -1,   398,   855,
      -1,  1218,    -1,    -1,   512,   870,  1218,    -1,     7,   855,
      -1,     6,   855,    -1,   855,    -1,   872,     5,   855,    -1,
     628,   436,  1424,   397,    -1,   434,   436,  1424,   397,    -1,
     628,   436,   880,   872,   397,    -1,   434,   436,   880,   872,
     397,    -1,   392,    -1,   254,    -1,    10,   855,    -1,   257,
     855,    -1,    10,   855,   447,    25,    -1,   257,   855,   447,
      25,    -1,   562,   855,    -1,   376,   855,    -1,   562,   855,
     447,    25,    -1,   376,   855,   447,    25,    -1,   396,    -1,
       8,   855,    -1,    18,   855,    -1,    19,   855,    -1,    20,
     855,    -1,    21,   855,    -1,    22,   855,    -1,    11,   855,
      -1,    14,   855,    -1,   462,   855,    -1,    12,   855,    -1,
      13,   855,    -1,    17,   855,    -1,    16,   855,    -1,    15,
     855,    -1,    -1,    -1,    -1,   955,   436,   882,   718,   883,
     397,    -1,    -1,    -1,   955,   526,   955,   436,   884,   718,
     885,   397,    -1,    -1,    -1,   543,   436,   887,   855,   888,
     397,    -1,    -1,    -1,   518,   436,   889,   855,   890,   397,
      -1,    -1,    -1,   596,   436,   891,   855,   892,   397,    -1,
      -1,    -1,   587,   436,   893,   855,   894,   397,    -1,   374,
     436,   901,   397,   896,    -1,   362,   436,    25,   397,   895,
      -1,   362,   436,    26,   397,   895,    -1,   362,   436,    26,
     595,    26,   397,   895,    -1,    -1,  1404,   631,  1405,    -1,
     805,    -1,   886,    -1,   294,   436,  1499,   397,    -1,   104,
     436,   947,   397,    -1,    76,   436,   947,   397,    -1,   412,
     436,  1499,   397,    -1,   197,   436,  1499,   397,    -1,    64,
     436,  1499,   397,    -1,   899,    -1,   881,    -1,  1400,    -1,
     543,    -1,   428,   436,   855,   397,    -1,   327,   436,   855,
     397,    -1,   493,   855,    -1,   449,   762,    -1,   855,   113,
      -1,   855,   114,    -1,   855,   115,    -1,    25,    -1,   902,
      -1,    19,   902,    -1,   904,    -1,   903,    -1,    26,    -1,
      26,    26,    -1,    26,    26,   595,    26,    -1,    26,    26,
     595,    26,   595,    26,    -1,    26,    26,   595,    26,   595,
      24,    -1,    26,   595,    26,    -1,    26,   595,    26,   595,
      26,    -1,    26,   595,    26,   595,    24,    -1,    26,   595,
      24,    -1,    24,    -1,    26,    -1,    26,    19,    26,    -1,
     947,    -1,   905,     5,   947,    -1,    -1,    -1,   601,  1108,
      14,   862,   631,   862,   909,   907,  1509,   908,   246,    -1,
      -1,   577,   862,    -1,    -1,    -1,    -1,   409,   911,   949,
     912,   914,  1305,   913,  1509,   245,    -1,    -1,     8,   880,
     860,    -1,    -1,    -1,   643,   955,   916,   765,   917,  1053,
     919,   918,   924,   644,    -1,    -1,   929,    -1,    -1,   920,
      -1,   921,    -1,   920,   921,    -1,    -1,   645,   922,  1509,
      -1,    -1,   646,   923,  1509,    -1,    -1,   925,    -1,   926,
      -1,   925,   926,    -1,    -1,   647,   927,  1509,    -1,    -1,
     648,   928,  1509,    -1,   930,   934,   329,    -1,    96,    -1,
      96,   931,   552,   932,    -1,    96,   390,   933,    -1,  1108,
      -1,   931,     5,  1108,    -1,   955,    -1,   932,     5,   955,
      -1,  1108,    -1,   933,     5,  1108,    -1,   935,    -1,   934,
     935,    -1,    -1,   649,   936,  1509,    -1,    -1,   650,   937,
    1509,    -1,    -1,   669,   932,   938,  1509,    -1,    -1,   486,
     932,   939,  1509,    -1,    -1,   630,   932,   940,  1509,    -1,
     551,   948,    -1,   560,    19,    26,    -1,   560,    -1,   506,
      18,    26,    -1,   506,    -1,    26,    -1,  1108,    -1,   674,
      -1,    25,    -1,   960,    -1,   862,    -1,   944,     5,   944,
      -1,   945,    -1,   955,    -1,   672,   436,   955,   397,    -1,
     955,   625,   672,   436,   955,   397,    -1,   955,   464,   688,
     432,    -1,   955,   625,    20,    -1,   955,   464,   688,   432,
     625,    20,    -1,   955,   625,   955,    -1,   955,   464,   688,
     432,   625,   955,    -1,   956,    -1,   956,    -1,   956,    -1,
     956,    -1,   956,    -1,   956,    -1,    -1,   556,    26,    -1,
    1508,    -1,   957,    -1,  1508,    -1,   354,   436,   958,   397,
      -1,  1111,    -1,    25,    -1,   955,    -1,   955,   464,   688,
     432,    -1,   955,   625,    20,    -1,   955,   464,   688,   432,
     625,    20,    -1,   955,   625,   955,    -1,   955,   464,   688,
     432,   625,   955,    -1,  1108,    -1,    24,    -1,   625,    26,
      -1,   553,  1491,    -1,   657,   964,    -1,   965,    -1,   964,
       5,   965,    -1,   955,    -1,   668,   964,    -1,   659,   964,
      -1,   660,  1499,    -1,   658,   952,   664,  1499,    -1,   662,
     964,    -1,   663,  1499,    -1,   661,   952,   664,  1499,    -1,
      -1,   666,   970,   860,   975,   977,   979,   971,   973,    -1,
      -1,   972,    -1,   654,    -1,   655,    -1,    -1,   974,    -1,
     349,  1108,    -1,    -1,   976,    -1,   395,   860,    -1,    -1,
     978,    -1,   665,    26,    -1,    -1,   980,    -1,   656,    26,
     981,    -1,    -1,   405,    26,    -1,    -1,    -1,   627,   862,
     581,   983,  1509,   984,   985,   446,    -1,    -1,    -1,   548,
     986,  1509,    -1,    -1,    -1,    67,   987,   862,   581,   988,
    1509,   985,    -1,   111,   955,   436,    26,   397,    -1,    60,
     955,    -1,    80,   955,    -1,    -1,   295,  1139,   992,   631,
     488,    -1,   295,  1139,   562,   993,    -1,   994,    -1,   993,
       5,   994,    -1,   802,   625,  1396,    -1,   802,   625,    20,
      -1,    -1,   997,   329,    -1,    -1,   155,    -1,   998,    -1,
     997,   998,    -1,    -1,   275,  1010,   999,  1509,    -1,    -1,
     278,  1011,  1000,  1509,    -1,    -1,   356,  1001,  1509,    -1,
      -1,   352,  1002,  1509,    -1,    -1,  1024,  1003,  1509,    -1,
      -1,   310,  1004,  1509,    -1,    -1,   280,  1005,  1509,    -1,
      -1,    40,  1006,  1509,    -1,    -1,    38,  1007,  1509,    -1,
      -1,    42,  1008,  1509,    -1,    -1,    41,  1009,  1509,    -1,
     947,    -1,  1010,     5,   947,    -1,   947,    -1,  1011,     5,
     947,    -1,   319,  1014,    -1,   320,   955,   664,  1014,    -1,
     567,    -1,   380,    -1,   947,    -1,    -1,   670,  1017,  1016,
     995,    -1,   390,  1127,   996,   954,   691,    -1,  1127,   996,
     552,  1499,   954,   691,    -1,    -1,   492,  1134,   996,   552,
     955,   625,    20,   954,  1018,   691,    -1,   474,  1499,  1020,
      -1,    86,    26,    -1,    87,    26,    -1,   632,    -1,   545,
      -1,    -1,   556,    26,    -1,  1023,    -1,    48,    25,    -1,
     501,    14,    26,    -1,   501,    14,  1108,    -1,    49,    14,
      26,    -1,    49,    14,  1108,    -1,    45,    -1,    47,    -1,
      44,    -1,    46,    -1,    -1,   435,  1025,  1030,    -1,   300,
      -1,    -1,   602,  1027,  1030,    -1,   308,  1032,    -1,   602,
    1030,    -1,  1032,    -1,   436,  1031,   397,    -1,  1032,    -1,
    1031,     5,  1032,    -1,  1033,    -1,   600,    -1,   317,    -1,
     335,    -1,   309,    -1,   490,    -1,   447,    -1,   632,    -1,
     556,    -1,   545,    -1,   182,    -1,   444,    -1,   455,    -1,
     546,    -1,   561,    -1,   525,    -1,   315,    -1,   316,    -1,
      25,    -1,   515,    -1,    -1,    -1,   604,  1036,  1132,  1037,
      14,   880,  1038,    -1,   488,    -1,   861,    -1,   224,  1108,
      -1,   213,  1108,    -1,   227,  1108,    -1,   456,  1108,   338,
      -1,   456,  1108,   391,   943,    -1,    -1,  1045,  1044,  1048,
      -1,    -1,  1046,    -1,  1047,    -1,  1046,  1047,    -1,   990,
      -1,  1052,    -1,  1068,    -1,  1054,    -1,    -1,  1049,    -1,
    1051,    -1,  1049,  1051,    -1,    71,   955,    -1,  1056,    -1,
    1062,    -1,  1074,    -1,  1228,    -1,  1238,    -1,  1095,    -1,
    1489,    -1,   915,    -1,   738,    -1,   989,    -1,   744,    -1,
     738,    -1,  1489,    -1,    -1,   738,    -1,  1489,    -1,   766,
      -1,   372,    -1,    65,    -1,    -1,    -1,    -1,    -1,  1055,
    1057,   955,   436,  1058,  1125,   397,  1059,   765,  1060,  1053,
    1509,  1061,    -1,   215,    -1,    -1,    -1,   563,  1063,   765,
    1064,  1509,   366,    -1,   182,   857,    -1,   880,    -1,   880,
     860,    -1,   361,  1408,    -1,   472,  1408,    -1,  1069,    -1,
    1070,    -1,  1069,  1070,    -1,  1071,    -1,  1052,    -1,  1067,
      -1,    -1,   411,  1072,  1073,    -1,   765,   247,    -1,   943,
      -1,    -1,    -1,    -1,   118,   955,   117,   955,   436,  1075,
    1125,   397,  1076,   765,  1077,  1053,  1509,  1061,    -1,    -1,
     564,  1079,  1094,  1085,  1080,    -1,   367,    -1,    -1,   239,
    1082,  1509,    -1,    -1,    23,  1086,  1087,  1088,   954,  1083,
    1509,    -1,    -1,    23,  1086,   954,  1084,  1509,    -1,  1081,
      -1,  1085,  1081,    -1,    -1,  1026,    -1,    25,    -1,  1108,
      -1,    -1,  1108,    -1,    25,    -1,   256,  1092,    -1,   268,
    1093,    -1,   251,  1093,    -1,   591,    -1,    25,    -1,  1108,
      -1,  1092,    -1,  1093,     5,  1092,    -1,  1108,    -1,    25,
      -1,    -1,    -1,   651,   955,  1096,   765,  1097,  1098,   652,
      -1,  1099,    -1,  1098,  1099,    -1,    -1,   653,  1100,  1509,
      -1,    -1,   630,   955,  1101,  1509,    -1,  1105,  1103,    -1,
      -1,   692,  1106,    -1,  1107,    -1,  1104,    -1,   976,    -1,
     978,    -1,   980,    -1,   972,    -1,   974,    -1,   375,   880,
     860,    -1,    -1,    70,    -1,    70,    -1,  1109,    -1,  1111,
      -1,   195,  1111,    -1,  1111,   625,    -1,  1110,  1115,    -1,
    1110,   955,   464,  1119,   432,    -1,  1110,   955,   464,  1119,
     432,   464,  1119,   432,    -1,  1116,    -1,   955,    -1,  1112,
      -1,   955,   463,  1114,   431,    -1,   955,   463,  1114,   431,
      -1,  1108,    -1,    25,    -1,    20,    -1,   955,    -1,   955,
    1118,    -1,   955,  1118,    -1,   464,  1119,   432,    -1,   464,
    1119,   432,   464,  1119,   432,    -1,  1120,    -1,  1119,     5,
    1120,    -1,   688,    -1,  1122,    -1,  1124,    -1,  1122,   625,
    1123,    -1,  1122,   625,   955,   464,  1119,   432,    -1,  1122,
     625,   955,   464,  1119,   432,   464,  1119,   432,    -1,   955,
      -1,  1113,    -1,    20,    -1,   955,    -1,   955,  1118,    -1,
      -1,  1126,    -1,  1128,    -1,  1126,     5,  1128,    -1,  1129,
      -1,  1127,     5,  1129,    -1,   955,    -1,   955,   625,   955,
      -1,  1108,    -1,  1108,   426,  1108,    -1,    25,    -1,   961,
      -1,    26,    -1,  1131,    -1,  1130,     5,  1131,    -1,  1108,
      -1,  1108,   426,  1108,    -1,  1133,    -1,  1132,     5,  1133,
      -1,  1121,    -1,  1108,    -1,  1136,    -1,  1135,     5,  1136,
      -1,  1108,  1137,    -1,    -1,   593,    -1,   544,    -1,   955,
     464,  1119,   432,    -1,  1140,    -1,  1139,     5,  1140,    -1,
    1108,    -1,  1108,   426,  1108,    -1,   259,   951,   623,   945,
     585,  1501,   696,    -1,    -1,   623,   436,   862,     5,   862,
     397,  1143,    -1,    -1,   574,   436,   862,     5,   862,   397,
      -1,   260,   955,  1142,    -1,   955,    -1,   343,   953,  1147,
      -1,  1148,    -1,   552,   862,    -1,  1149,  1150,  1155,     8,
    1145,    -1,    -1,   623,  1151,   436,   862,     5,   862,   397,
      -1,    -1,   562,   956,    -1,    -1,   355,    -1,   222,  1450,
     271,  1484,  1154,    -1,   569,   948,    -1,   569,   948,     8,
     880,   860,    -1,    -1,   622,   582,  1444,   379,  1444,    -1,
     622,   582,  1444,     5,   379,  1444,    -1,   622,  1444,     5,
    1444,    -1,    -1,   654,    -1,   655,    -1,    95,  1484,  1157,
    1158,    -1,    -1,   622,  1484,    -1,    -1,   622,   582,  1444,
       8,  1444,    -1,   582,  1444,     8,  1444,    -1,   417,  1160,
      -1,  1161,    -1,  1160,     5,  1161,    -1,   208,   942,    -1,
     289,   942,    -1,   334,   942,    -1,   342,   942,    -1,   298,
     942,    -1,   264,   942,    -1,  1028,    -1,   444,  1029,    -1,
     455,  1029,    -1,   567,  1029,    -1,   380,  1029,    -1,   556,
    1029,    -1,   554,   943,    -1,   555,   943,    -1,   406,   692,
      -1,   670,   692,    -1,   296,    -1,   200,    -1,   156,    -1,
     133,    -1,   151,    -1,   142,    -1,  1449,   419,  1165,   552,
    1163,    -1,  1108,    -1,    25,    -1,   408,  1165,    -1,   408,
    1165,     8,  1127,    -1,    43,  1163,    -1,   956,    -1,    -1,
     467,  1175,   691,   601,  1170,  1108,  1168,   954,   691,  1167,
    1171,    -1,    -1,   673,    26,    -1,   467,  1175,   691,   349,
    1108,    -1,    -1,   541,    -1,    -1,  1172,   287,    -1,  1173,
      -1,  1172,  1173,    -1,    -1,  1024,  1174,  1509,    -1,   861,
      -1,    -1,   609,   948,  1177,  1178,    -1,    -1,   552,  1179,
      -1,  1180,    -1,  1179,     5,  1180,    -1,  1436,    -1,   488,
      -1,   225,  1183,    93,    -1,   225,  1183,   631,  1182,    -1,
     225,  1183,    92,  1182,    -1,   225,  1183,    -1,    25,    -1,
     960,    -1,   955,    -1,    -1,   484,    -1,   150,  1183,  1184,
     436,   880,  1066,   397,    -1,   198,  1183,    -1,    72,  1183,
      -1,  1219,  1227,    -1,   452,    66,    -1,   452,  1190,    -1,
    1191,    -1,  1190,  1191,    -1,    -1,   138,  1192,  1509,    -1,
      -1,   204,  1193,  1509,    -1,    -1,   233,  1194,  1509,    -1,
      -1,   221,  1195,  1509,    -1,    -1,   258,  1196,  1509,    -1,
      -1,   206,  1108,  1197,  1509,    -1,    -1,   229,  1108,  1198,
    1509,    -1,  1209,    -1,  1211,    -1,  1210,    -1,  1200,    -1,
    1236,    -1,  1203,    -1,    -1,   566,   862,  1201,   487,    -1,
      -1,   487,    -1,    -1,   575,    26,  1204,  1202,    -1,   163,
      -1,   634,  1223,    -1,   166,  1223,    -1,   165,  1223,    -1,
      -1,  1206,    -1,  1207,    -1,  1206,  1207,    -1,  1216,  1208,
      -1,    -1,   623,  1223,    -1,   524,  1205,  1215,    -1,   523,
    1444,  1215,    -1,   522,  1214,  1213,  1212,  1215,    -1,    -1,
     157,   855,    -1,   157,   855,     5,   855,    -1,   618,    -1,
     619,    -1,   620,    -1,   621,    -1,  1108,    -1,    -1,   527,
      -1,  1217,    -1,  1216,     5,  1217,    -1,   862,  1250,    -1,
     614,   436,   855,   397,  1235,    -1,    69,  1235,    -1,   501,
     436,    20,   397,  1235,    -1,   418,   436,    20,   397,  1235,
      -1,   393,   436,   855,   397,  1235,    -1,   594,   436,   855,
     397,  1235,    -1,   607,   436,   855,   397,  1235,    -1,   606,
     436,   855,   397,  1235,    -1,    -1,   466,  1220,    -1,  1221,
      -1,  1220,  1221,    -1,   232,    26,    -1,   223,    26,    -1,
     306,    26,    -1,   189,    26,    -1,   261,    26,    -1,   180,
      -1,   348,    25,    -1,   348,  1108,    -1,   181,    25,    -1,
     164,    25,    -1,  1226,    -1,  1222,  1226,    -1,  1224,   113,
      -1,  1224,   115,    -1,  1224,   114,    -1,  1224,    -1,   961,
      -1,    26,    -1,    -1,   466,  1222,    -1,   232,  1223,    -1,
     223,  1223,    -1,   306,  1223,    -1,   189,  1223,    -1,   261,
    1223,    -1,   262,  1223,    -1,   633,    25,    -1,   634,  1223,
      -1,   638,    -1,   635,    -1,   636,    -1,   637,    -1,   642,
      -1,   639,    -1,   640,    -1,   641,    -1,    81,  1223,    -1,
      82,  1223,    -1,    83,  1223,    -1,   348,    25,    -1,   181,
      25,    -1,   405,    -1,    78,    -1,    79,    -1,    -1,   519,
     624,  1135,    -1,   139,  1135,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   470,  1229,   955,   436,  1230,  1125,   397,  1231,
     765,  1232,  1188,  1233,  1189,  1234,   244,    -1,    -1,   531,
     855,    -1,   521,  1237,    -1,    -1,  1163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   110,  1239,   955,   436,  1240,  1125,
     397,  1241,   765,  1242,  1245,  1243,  1189,  1244,   244,    -1,
    1225,  1227,    -1,    -1,    -1,    -1,   159,   436,    25,     5,
    1247,   718,  1248,   397,  1249,   716,    -1,    -1,   389,    -1,
     389,   223,    26,    -1,   389,   223,  1108,    -1,   612,   862,
      -1,   612,   862,   349,  1108,    -1,   612,   862,   167,    -1,
     612,   862,   583,    -1,   612,   862,   550,    -1,  1253,    -1,
     177,    -1,   328,    -1,   286,    -1,  1260,    -1,  1255,    -1,
      -1,    -1,   211,  1256,  1393,   436,  1257,  1264,   397,    -1,
      -1,    -1,   136,  1258,  1393,   436,  1259,  1264,   397,  1261,
      -1,   108,  1262,   397,    -1,    59,   956,    -1,    -1,   273,
      -1,  1263,    -1,  1262,     5,  1263,    -1,   955,   593,    -1,
     955,   544,    -1,   955,    -1,  1265,    -1,  1264,     5,  1265,
      -1,  1346,    -1,  1344,    -1,   125,   955,    -1,   184,    -1,
      50,   955,  1268,    -1,  1269,    -1,  1268,     5,  1269,    -1,
    1270,    -1,  1273,    -1,  1276,    -1,  1281,    -1,  1282,    -1,
    1280,    -1,  1279,    -1,   590,  1271,    -1,   590,   436,  1272,
     397,    -1,  1265,    -1,  1265,   669,   955,    -1,  1271,    -1,
    1272,     5,  1271,    -1,   547,  1275,    -1,   547,   436,  1274,
     397,    -1,  1275,    -1,  1274,     5,  1275,    -1,   955,    -1,
     460,  1278,    -1,   460,   436,  1277,   397,    -1,  1278,    -1,
    1277,     5,  1278,    -1,  1265,    -1,    90,    -1,    91,    -1,
      89,    26,    -1,    61,  1350,    -1,    61,   436,  1283,   397,
      -1,    62,  1284,    -1,    62,   436,  1283,   397,    -1,  1350,
      -1,  1283,     5,  1350,    -1,   955,    -1,   270,    -1,   236,
      -1,   169,  1287,    -1,   146,    -1,   134,    -1,   124,    -1,
     122,    -1,   126,    -1,   183,  1450,    -1,   235,  1286,   465,
    1444,   631,  1444,    -1,   303,   948,   465,  1444,   631,  1444,
      -1,    -1,  1450,    -1,    -1,   862,    -1,   528,   862,    -1,
     234,    -1,    -1,   253,  1291,  1393,  1294,  1292,    -1,    -1,
     484,  1293,   436,  1296,   397,    -1,  1430,    -1,    -1,   436,
    1295,   397,    -1,  1396,    -1,  1295,     5,  1396,    -1,  1297,
      -1,  1296,     5,  1297,    -1,  1436,    -1,   488,    -1,    -1,
      -1,   505,  1299,  1302,  1300,  1303,    -1,   956,    -1,  1307,
     949,    -1,   949,    -1,    -1,    -1,   559,  1304,  1130,    -1,
      -1,    -1,   559,  1306,  1130,    -1,   506,    -1,   560,    -1,
     567,    -1,   380,    -1,   346,    -1,   401,    -1,   383,   862,
      -1,   355,   862,    -1,   242,  1393,   154,   949,    -1,   242,
    1393,  1366,    -1,   519,   624,  1311,    -1,  1312,    -1,  1311,
       5,  1312,    -1,  1313,  1314,    -1,    26,    -1,  1396,    -1,
      -1,   593,    -1,   544,    -1,   281,    -1,   314,    -1,    -1,
     331,    -1,   361,  1319,  1317,    -1,  1484,    -1,    25,    -1,
      -1,  1449,  1321,  1322,    -1,  1351,    -1,  1355,    -1,  1316,
      -1,  1451,    -1,  1315,    -1,  1308,    -1,  1309,    -1,  1298,
      -1,  1290,    -1,  1289,    -1,  1420,    -1,  1468,    -1,   510,
    1325,   630,  1393,   631,  1330,  1324,    -1,    -1,   145,    -1,
     172,    -1,  1326,    -1,  1327,    -1,  1326,     5,  1327,    -1,
     476,    -1,   455,    -1,   444,    -1,   483,  1328,    -1,    -1,
     436,  1329,   397,    -1,  1396,    -1,  1329,     5,  1396,    -1,
    1331,    -1,  1330,     5,  1331,    -1,   468,    -1,  1394,    -1,
     240,  1393,  1333,   622,  1430,  1335,    -1,    -1,   436,  1334,
     397,    -1,  1396,    -1,  1334,     5,  1396,    -1,    -1,   144,
      -1,   497,   436,  1369,   397,    -1,   250,   436,  1339,   397,
    1338,    -1,   301,  1340,    -1,  1341,    -1,  1393,    -1,  1393,
     436,  1341,   397,    -1,  1396,    -1,  1341,     5,  1396,    -1,
     481,   436,  1343,   397,    -1,   263,   436,  1343,   397,    -1,
    1396,    -1,  1343,     5,  1396,    -1,  1342,    -1,  1337,    -1,
    1336,    -1,   405,  1399,    -1,   212,    -1,   955,  1385,  1347,
    1348,    -1,    -1,  1345,    -1,    -1,  1349,    -1,  1350,    -1,
    1349,  1350,    -1,   378,    -1,   162,    -1,   481,    -1,  1338,
      -1,   497,   436,  1369,   397,    -1,   123,  1352,  1354,    -1,
    1353,    -1,  1394,    -1,  1355,    -1,  1354,  1355,    -1,  1332,
      -1,  1323,    -1,   453,  1369,    -1,   373,  1358,    -1,  1435,
      -1,  1358,     5,  1435,    -1,   531,  1369,    -1,   552,  1361,
      -1,  1362,    -1,  1361,     5,  1362,    -1,  1363,    -1,   520,
    1363,    -1,   520,   436,  1364,   397,    -1,  1393,    -1,  1393,
    1398,    -1,  1362,    -1,  1364,     5,  1362,    -1,  1360,  1366,
    1367,  1368,    -1,    -1,  1359,    -1,    -1,  1357,    -1,    -1,
    1356,    -1,  1370,    -1,  1369,     6,  1370,    -1,  1371,    -1,
    1370,     7,  1371,    -1,  1372,    -1,     9,  1372,    -1,  1383,
      -1,   436,  1369,   397,    -1,   448,  1431,    -1,   299,  1431,
      -1,    -1,   447,  1376,    -1,  1437,    -1,  1440,    -1,  1436,
     628,   436,  1378,   397,    -1,  1436,   628,  1431,    -1,  1436,
     434,   436,  1378,   397,    -1,  1436,   434,  1431,    -1,  1379,
      -1,  1378,     5,  1379,    -1,  1488,    -1,  1399,    -1,    -1,
       9,    -1,  1436,  1380,   392,    -1,  1436,  1380,   254,    -1,
    1436,  1382,  1436,    -1,  1436,  1380,   394,  1436,     7,  1436,
      -1,  1436,   562,  1375,  1374,    -1,  1436,   376,  1375,  1374,
      -1,  1436,   679,  1375,  1374,    -1,  1436,   377,  1375,  1374,
      -1,  1436,  1380,    10,  1375,  1374,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   257,    -1,    10,    -1,   678,
      -1,    16,    -1,    15,    -1,  1381,    -1,  1377,    -1,  1373,
      -1,    -1,   591,    -1,   364,    -1,   481,    -1,  1386,    -1,
    1387,    -1,  1389,    -1,   541,    -1,   541,   436,  1390,   397,
      -1,   416,   436,  1391,  1388,   397,    -1,   477,    -1,   403,
     436,  1391,  1388,   397,    -1,   517,   436,  1391,  1388,   397,
      -1,   543,    -1,   413,    -1,   385,    -1,   362,  1406,   631,
    1407,    -1,   362,    -1,   374,  1406,   631,  1407,    -1,   374,
      -1,   374,  1406,   436,    26,   397,   631,  1407,    -1,   580,
      -1,   538,    -1,   429,    -1,   429,   436,    26,   397,    -1,
     429,   436,    26,     5,    26,   397,    -1,    -1,     5,  1392,
      -1,   507,   436,  1391,   397,    -1,   571,    -1,   304,    -1,
     507,    -1,    68,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   625,   955,    -1,    25,    -1,   955,    -1,   955,   595,
     955,    -1,   955,    -1,    -1,   464,    26,   432,    -1,   464,
      26,     5,    26,   432,    -1,  1397,    -1,   617,  1397,    -1,
     955,  1395,    -1,  1393,   625,   955,  1395,    -1,  1393,   625,
      20,    -1,   955,    -1,    25,    -1,   416,    -1,   961,    -1,
      26,    -1,  1401,    -1,   401,  1403,    -1,   401,  1402,    -1,
      -1,  1406,   631,  1407,    -1,    -1,  1404,   631,  1404,    -1,
     587,    -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,
     475,    -1,   371,    -1,   371,   436,    26,   397,    -1,   587,
      -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,
      -1,   371,    -1,   371,   436,    26,   397,    -1,   587,    -1,
     518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,    -1,
     371,    -1,   587,    -1,   518,    -1,   596,    -1,   558,    -1,
     459,    -1,   475,    -1,   371,    -1,   955,    -1,    25,    -1,
    1449,   508,   949,    -1,    -1,  1449,   404,  1301,   442,   601,
    1418,  1411,  1415,    -1,    -1,  1449,   404,  1301,   442,   105,
     601,  1419,  1412,  1415,    -1,    -1,  1449,   404,  1301,   140,
    1419,  1413,  1415,    -1,    -1,  1449,   404,  1301,   141,   105,
     601,  1419,  1414,  1415,    -1,    -1,   293,    -1,   292,  1416,
      -1,  1417,    -1,  1416,     5,  1417,    -1,   955,    -1,   955,
     625,   955,    -1,    25,   625,   955,   625,   955,    -1,  1419,
      -1,  1290,    -1,  1165,    -1,  1421,    -1,  1421,  1415,    -1,
      -1,    -1,   476,  1432,  1422,  1433,  1423,  1429,  1365,  1427,
      -1,   476,  1432,  1433,  1365,  1427,    -1,  1426,    -1,  1444,
      -1,   476,  1432,  1433,  1429,  1365,  1427,    -1,    -1,   530,
    1384,  1425,    -1,  1310,    -1,   336,  1428,  1261,    -1,  1310,
     336,  1428,  1261,    -1,   955,    -1,    -1,   559,  1130,    -1,
     476,  1432,  1433,  1365,    -1,   436,   476,  1432,  1433,  1365,
     397,    -1,    -1,   591,    -1,   364,    -1,   481,    -1,  1434,
      -1,  1433,     5,  1434,    -1,  1436,    -1,  1436,   955,    -1,
    1436,    -1,  1437,    -1,    19,  1437,    -1,    18,  1437,    -1,
    1438,    -1,  1488,    -1,  1431,    -1,   617,   955,    -1,   617,
     955,   625,   955,    -1,  1437,    21,  1436,    -1,  1437,  1458,
      -1,  1437,    20,  1436,    -1,  1437,    18,  1436,    -1,  1437,
      19,  1436,    -1,  1399,    -1,   489,    -1,   433,    -1,   582,
      -1,    20,    -1,    69,    -1,   594,   436,  1384,  1436,   397,
      -1,   606,   436,  1384,  1436,   397,    -1,   607,   436,  1384,
    1436,   397,    -1,   614,   436,  1384,  1436,   397,    -1,   501,
     436,  1384,  1436,   397,    -1,   955,   436,  1439,   397,    -1,
     543,   436,  1439,   397,    -1,   436,  1436,   397,    -1,   449,
     436,  1459,   397,    -1,  1436,    -1,  1439,     5,  1436,    -1,
    1399,    -1,  1449,   351,  1448,  1443,  1425,    -1,  1449,   340,
    1448,  1443,   253,  1393,  1445,    -1,  1449,   340,  1448,  1443,
    1108,    -1,    -1,   326,  1444,    -1,    25,    -1,  1108,    -1,
      -1,   436,  1446,   397,    -1,  1447,    -1,  1446,     5,  1447,
      -1,   955,    -1,    25,    -1,  1108,    -1,    -1,   272,  1450,
     601,    -1,   956,    -1,  1456,    -1,  1455,    -1,  1452,    -1,
     321,  1453,   631,  1453,    -1,   302,  1453,   625,  1454,   631,
    1454,    -1,   955,    -1,   955,    -1,   226,   802,    -1,   297,
     802,  1457,    -1,   276,    -1,   179,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   401,
       5,  1406,   631,  1407,    -1,  1488,     5,  1406,   631,  1407,
      -1,   401,  1406,   631,  1407,    -1,    -1,   613,  1461,  1462,
     194,    -1,  1463,    -1,  1462,  1463,    -1,    33,    -1,  1464,
      -1,  1466,    -1,   355,    -1,   309,    -1,   228,    -1,   590,
      -1,   486,    -1,   591,    -1,   491,    -1,   535,    -1,   592,
      -1,   119,    -1,   492,    -1,   622,    -1,   593,    -1,   322,
      -1,   493,    -1,   323,    -1,   623,    -1,   617,    -1,   279,
      -1,   494,    -1,   188,    -1,   393,    -1,   594,    -1,   669,
      -1,   394,    -1,   495,    -1,   496,    -1,   536,    -1,   537,
      -1,   437,    -1,   438,    -1,   357,    -1,   656,    -1,   624,
      -1,   538,    -1,   395,    -1,   540,    -1,   534,    -1,   541,
      -1,   324,    -1,   497,    -1,   498,    -1,   396,    -1,   499,
      -1,   397,    -1,   432,    -1,   500,    -1,   595,    -1,   439,
      -1,   398,    -1,     5,    -1,    23,    -1,   399,    -1,   440,
      -1,   400,    -1,   359,    -1,   358,    -1,   325,    -1,   360,
      -1,   501,    -1,   441,    -1,   401,    -1,   442,    -1,   542,
      -1,   361,    -1,   543,    -1,   362,    -1,   596,    -1,   597,
      -1,   402,    -1,   598,    -1,   403,    -1,   404,    -1,   405,
      -1,   363,    -1,   502,    -1,   443,    -1,   444,    -1,   326,
      -1,   544,    -1,   285,    -1,   599,    -1,   660,    -1,   406,
      -1,   364,    -1,    21,    -1,   625,    -1,   445,    -1,   327,
      -1,   547,    -1,    67,    -1,   548,    -1,   663,    -1,   407,
      -1,    14,    -1,   503,    -1,   447,    -1,   504,    -1,   331,
      -1,   549,    -1,   408,    -1,   448,    -1,   550,    -1,   449,
      -1,   450,    -1,   370,    -1,   539,    -1,   505,    -1,   104,
      -1,   197,    -1,   451,    -1,   506,    -1,   600,    -1,   507,
      -1,   508,    -1,   601,    -1,   409,    -1,   410,    -1,   452,
      -1,   643,    -1,    96,    -1,   109,    -1,   509,    -1,   371,
      -1,   551,    -1,   552,    -1,   372,    -1,   294,    -1,   411,
      -1,   626,    -1,   553,    -1,   510,    -1,    13,    -1,   511,
      -1,   512,    -1,   453,    -1,   454,    -1,   556,    -1,   557,
      -1,   558,    -1,   665,    -1,    76,    -1,   627,    -1,   628,
      -1,   115,    -1,   513,    -1,   412,    -1,   295,    -1,   670,
      -1,   455,    -1,   413,    -1,   335,    -1,   374,    -1,   672,
      -1,   337,    -1,   602,    -1,   545,    -1,   664,    -1,   514,
      -1,   487,    -1,   375,    -1,   603,    -1,   632,    -1,   414,
      -1,     7,    -1,   433,    -1,   588,    -1,   488,    -1,     6,
      -1,   489,    -1,     8,    -1,   560,    -1,   561,    -1,    12,
      -1,   604,    -1,   562,    -1,   516,    -1,   456,    -1,   605,
      -1,   415,    -1,   563,    -1,   457,    -1,    10,    -1,    49,
      -1,   458,    -1,   564,    -1,   651,    -1,   666,    -1,    19,
      -1,   459,    -1,   114,    -1,    22,    -1,   565,    -1,   460,
      -1,   517,    -1,   518,    -1,    20,    -1,   566,    -1,   567,
      -1,   315,    -1,   568,    -1,   461,    -1,     9,    -1,   416,
      -1,   629,    -1,   674,    -1,   630,    -1,   569,    -1,   436,
      -1,   464,    -1,   465,    -1,   417,    -1,   519,    -1,   344,
      -1,   520,    -1,   466,    -1,   608,    -1,   379,    -1,   521,
      -1,   159,    -1,   110,    -1,   418,    -1,    18,    -1,   113,
      -1,   345,    -1,   419,    -1,   116,    -1,   380,    -1,   316,
      -1,   524,    -1,   346,    -1,   347,    -1,   420,    -1,   467,
      -1,   468,    -1,   609,    -1,   570,    -1,   381,    -1,   571,
      -1,   469,    -1,   421,    -1,   610,    -1,   301,    -1,   382,
      -1,   383,    -1,   470,    -1,   384,    -1,   182,    -1,   349,
      -1,   422,    -1,   471,    -1,   525,    -1,   266,    -1,   611,
      -1,   572,    -1,   612,    -1,   472,    -1,   474,    -1,   475,
      -1,   423,    -1,   476,    -1,   527,    -1,   477,    -1,   424,
      -1,   479,    -1,   573,    -1,   490,    -1,   574,    -1,   575,
      -1,   528,    -1,   304,    -1,   385,    -1,   576,    -1,   480,
      -1,   613,    -1,   305,    -1,    94,    -1,   577,    -1,   578,
      -1,   614,    -1,   425,    -1,   546,    -1,   579,    -1,   120,
      -1,   580,    -1,   581,    -1,   426,    -1,   673,    -1,   631,
      -1,   615,    -1,   427,    -1,   529,    -1,   203,    -1,   350,
      -1,   530,    -1,   481,    -1,   482,    -1,   483,    -1,   428,
      -1,   616,    -1,   582,    -1,   386,    -1,   484,    -1,   429,
      -1,   354,    -1,   583,    -1,   430,    -1,   584,    -1,   387,
      -1,   531,    -1,   532,    -1,   533,    -1,   585,    -1,   389,
      -1,   586,    -1,   606,    -1,   607,    -1,   589,    -1,   587,
      -1,   485,    -1,    -1,   195,  1465,  1488,    -1,    -1,   559,
    1467,  1130,    -1,    -1,    -1,   483,  1393,  1469,  1472,  1470,
    1471,    -1,    -1,   154,   949,    -1,   531,  1369,    -1,    57,
    1476,   397,    14,   436,  1477,   397,    -1,    53,  1477,   397,
      -1,    54,  1477,   397,    -1,   589,  1473,    -1,    56,  1477,
      -1,    55,  1477,    -1,  1475,    -1,  1473,     5,  1475,    -1,
    1396,    -1,  1474,    14,  1478,    -1,  1474,    -1,  1476,     5,
    1474,    -1,  1478,    -1,  1477,     5,  1478,    -1,   488,    -1,
    1479,    -1,  1480,    -1,    19,  1480,    -1,    18,  1480,    -1,
    1482,    -1,  1431,    -1,   617,   955,    -1,   617,   955,   625,
     955,    -1,  1481,    -1,  1399,    -1,   489,    -1,   433,    -1,
     582,    -1,    69,    -1,  1480,    21,  1479,    -1,  1480,  1458,
      -1,  1480,    20,  1479,    -1,  1480,    18,  1479,    -1,  1480,
      19,  1479,    -1,   594,   436,  1384,  1479,   397,    -1,   606,
     436,  1384,  1479,   397,    -1,   607,   436,  1384,  1479,   397,
      -1,   614,   436,  1384,  1479,   397,    -1,   501,   436,  1384,
    1479,   397,    -1,   955,   436,  1483,   397,    -1,   543,   436,
    1483,   397,    -1,   436,  1479,   397,    -1,   449,   436,  1459,
     397,    -1,  1488,    -1,  1479,    -1,  1483,     5,  1479,    -1,
    1485,    -1,   195,  1486,    -1,  1486,    -1,  1117,    -1,   955,
      -1,  1486,   625,  1487,    -1,    25,   625,  1486,   625,  1487,
      -1,    20,    -1,  1138,    -1,   955,    -1,  1485,    -1,  1485,
     426,  1485,    -1,   131,  1490,    -1,   135,  1490,    -1,   130,
    1490,    -1,    51,    -1,   170,  1490,    -1,   128,  1490,    -1,
      52,    -1,   153,  1490,    -1,   152,  1490,    -1,   127,  1490,
      -1,   360,    -1,   626,   631,  1491,    -1,   553,  1491,    -1,
     578,    -1,   539,  1492,    -1,   955,    -1,   595,   955,    -1,
     955,    -1,    -1,    -1,   532,  1494,   862,  1495,  1509,   330,
      -1,    -1,   664,  1499,    -1,    -1,   667,    -1,   186,    -1,
     282,   950,    -1,    74,   950,    -1,   312,    -1,   311,    -1,
     313,   952,  1496,  1497,    -1,   498,  1499,  1497,    -1,   947,
      -1,  1499,     5,   947,    -1,   107,    -1,   137,   950,    -1,
     862,   572,     5,   862,   398,    -1,   514,   862,    -1,   269,
     950,    -1,   106,  1504,     8,  1505,  1503,    -1,    -1,   552,
     862,    -1,   955,    -1,   955,    -1,   252,   950,    -1,   255,
     950,   631,   862,     5,   862,    -1,   255,   950,   624,   862,
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
    5599,  5609,  5610,  5615,  5616,  5619,  5630,  5644,  5649,  5654,
    5659,  5669,  5669,  5673,  5676,  5676,  5678,  5688,  5697,  5704,
    5706,  5710,  5713,  5713,  5717,  5716,  5724,  5723,  5734,  5733,
    5740,  5739,  5743,  5742,  5745,  5745,  5761,  5760,  5782,  5783,
    5784,  5785,  5786,  5787,  5790,  5790,  5796,  5796,  5799,  5799,
    5815,  5816,  5817,  5826,  5838,  5839,  5842,  5843,  5846,  5849,
    5849,  5854,  5874,  5879,  5885,  5886,  5887,  5891,  5892,  5893,
    5894,  5898,  5908,  5910,  5915,  5918,  5923,  5929,  5936,  5943,
    5952,  5959,  5966,  5973,  5980,  5989,  5989,  5991,  5991,  5994,
    5995,  5996,  5997,  5998,  5999,  6000,  6001,  6002,  6003,  6006,
    6006,  6009,  6010,  6011,  6012,  6015,  6015,  6018,  6018,  6021,
    6022,  6023,  6024,  6025,  6026,  6027,  6028,  6030,  6031,  6032,
    6033,  6035,  6036,  6037,  6038,  6040,  6041,  6042,  6043,  6044,
    6045,  6046,  6047,  6051,  6058,  6067,  6079,  6088,  6099,  6103,
    6107,  6113,  6078,  6126,  6129,  6137,  6149,  6151,  6156,  6164,
    6174,  6177,  6181,  6189,  6155,  6198,  6202,  6206,  6210,  6202,
    6220,  6221,  6222,  6223,  6228,  6230,  6233,  6237,  6240,  6247,
    6252,  6253,  6254,  6259,  6260,  6266,  6266,  6266,  6271,  6271,
    6271,  6282,  6283,  6289,  6290,  6302,  6303,  6308,  6309,  6310,
    6314,  6317,  6323,  6326,  6334,  6335,  6341,  6348,  6351,  6360,
    6363,  6366,  6369,  6372,  6375,  6378,  6385,  6388,  6395,  6398,
    6404,  6407,  6414,  6417,  6424,  6425,  6430,  6434,  6437,  6443,
    6446,  6452,  6459,  6460,  6464,  6470,  6473,  6480,  6481,  6488,
    6491,  6496,  6507,  6508,  6509,  6510,  6511,  6512,  6513,  6514,
    6515,  6518,  6521,  6527,  6527,  6533,  6533,  6544,  6557,  6567,
    6567,  6572,  6572,  6576,  6580,  6581,  6587,  6588,  6593,  6597,
    6604,  6607,  6614,  6618,  6613,  6627,  6631,  6635,  6642,  6646,
    6646,  6659,  6663,  6663,  6678,  6680,  6682,  6684,  6686,  6688,
    6690,  6692,  6698,  6708,  6715,  6720,  6721,  6725,  6727,  6728,
    6731,  6732,  6733,  6736,  6741,  6748,  6749,  6755,  6767,  6768,
    6771,  6771,  6776,  6781,  6786,  6787,  6790,  6791,  6796,  6801,
    6805,  6810,  6811,  6815,  6822,  6826,  6827,  6832,  6834,  6838,
    6839,  6843,  6844,  6845,  6846,  6850,  6851,  6856,  6857,  6862,
    6863,  6868,  6869,  6874,  6879,  6880,  6885,  6886,  6890,  6891,
    6896,  6903,  6908,  6913,  6917,  6918,  6923,  6924,  6930,  6932,
    6937,  6938,  6944,  6947,  6950,  6957,  6959,  6973,  6978,  6979,
    6982,  6984,  6991,  6994,  7000,  7004,  7008,  7012,  7015,  7022,
    7029,  7034,  7038,  7039,  7045,  7048,  7059,  7066,  7072,  7075,
    7082,  7089,  7095,  7096,  7102,  7103,  7104,  7107,  7108,  7113,
    7113,  7117,  7125,  7126,  7129,  7132,  7137,  7138,  7143,  7146,
    7152,  7155,  7161,  7164,  7170,  7173,  7180,  7181,  7210,  7211,
    7216,  7224,  7229,  7232,  7235,  7238,  7244,  7245,  7249,  7252,
    7255,  7256,  7261,  7264,  7267,  7270,  7273,  7276,  7279,  7282,
    7287,  7293,  7294,  7295,  7296,  7297,  7299,  7300,  7302,  7303,
    7308,  7311,  7315,  7321,  7322,  7323,  7324,  7336,  7337,  7338,
    7342,  7343,  7348,  7350,  7351,  7352,  7354,  7355,  7356,  7357,
    7359,  7360,  7362,  7363,  7365,  7366,  7367,  7368,  7370,  7374,
    7375,  7381,  7383,  7384,  7385,  7386,  7391,  7395,  7399,  7403,
    7404,  7408,  7409,  7419,  7428,  7429,  7430,  7434,  7437,  7442,
    7447,  7452,  7460,  7464,  7468,  7469,  7470,  7475,  7478,  7481,
    7495,  7509,  7522,  7523,  7527,  7527,  7527,  7527,  7527,  7527,
    7528,  7531,  7536,  7536,  7536,  7536,  7536,  7536,  7538,  7541,
    7547,  7547,  7547,  7547,  7547,  7547,  7547,  7548,  7548,  7548,
    7548,  7548,  7548,  7548,  7550,  7551,  7554,  7563,  7563,  7569,
    7569,  7576,  7576,  7582,  7582,  7590,  7591,  7592,  7595,  7595,
    7598,  7599,  7600,  7605,  7608,  7614,  7619,  7627,  7640,  7641,
    7638,  7659,  7669,  7672,  7677,  7689,  7692,  7696,  7699,  7700,
    7706,  7709,  7710,  7719,  7728,  7733,  7734,  7735,  7736,  7743,
    7746,  7752,  7755,  7765,  7774,  7777,  7780,  7786,  7792,  7795,
    7798,  7801,  7807,  7809,  7811,  7813,  7815,  7817,  7818,  7819,
    7820,  7821,  7822,  7823,  7825,  7827,  7829,  7831,  7833,  7835,
    7837,  7838,  7843,  7844,  7851,  7854,  7863,  7867,  7874,  7874,
    7878,  7878,  7883,  7883,  7887,  7887,  7891,  7897,  7897,  7900,
    7900,  7906,  7913,  7914,  7915,  7919,  7920,  7923,  7924,  7928,
    7934,  7944,  7945,  7953,  7954,  7955,  7956,  7957,  7958,  7962,
    7963,  7964,  7968,  7968,  7980,  7981,  7985,  7986,  7987,  7988,
    7989,  7990,  7991,  7992,  7993,  7994,  7995,  7996,  7997,  7998,
    7999,  8000,  8001,  8002,  8003,  8004,  8005,  8006,  8007,  8008,
    8009,  8010,  8011,  8012,  8013,  8014,  8015,  8016,  8017,  8018,
    8019,  8020,  8021,  8022,  8023,  8024,  8025,  8026,  8027,  8028,
    8029,  8030,  8031,  8032,  8033,  8034,  8035,  8036,  8037,  8038,
    8039,  8040,  8041,  8042,  8043,  8044,  8045,  8046,  8047,  8048,
    8049,  8050,  8051,  8052,  8053,  8054,  8055,  8056,  8057,  8058,
    8059,  8060,  8061,  8062,  8063,  8064,  8065,  8066,  8067,  8068,
    8069,  8070,  8071,  8072,  8073,  8074,  8075,  8076,  8077,  8078,
    8079,  8080,  8081,  8082,  8083,  8084,  8085,  8086,  8087,  8088,
    8089,  8090,  8091,  8092,  8093,  8094,  8095,  8096,  8097,  8098,
    8099,  8100,  8101,  8102,  8103,  8104,  8105,  8106,  8107,  8108,
    8109,  8110,  8111,  8112,  8113,  8114,  8115,  8116,  8117,  8118,
    8119,  8120,  8121,  8122,  8123,  8124,  8125,  8126,  8127,  8128,
    8129,  8130,  8131,  8132,  8133,  8134,  8135,  8136,  8137,  8138,
    8139,  8140,  8141,  8142,  8143,  8144,  8145,  8146,  8147,  8148,
    8149,  8150,  8151,  8152,  8153,  8154,  8155,  8156,  8157,  8158,
    8159,  8160,  8161,  8162,  8163,  8164,  8165,  8166,  8167,  8168,
    8169,  8170,  8171,  8172,  8173,  8174,  8175,  8176,  8177,  8178,
    8179,  8180,  8181,  8182,  8183,  8184,  8185,  8186,  8187,  8188,
    8189,  8190,  8191,  8192,  8193,  8194,  8195,  8196,  8197,  8198,
    8199,  8200,  8201,  8202,  8203,  8204,  8205,  8206,  8207,  8208,
    8209,  8210,  8211,  8212,  8213,  8214,  8215,  8216,  8217,  8218,
    8219,  8220,  8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,
    8229,  8230,  8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,
    8239,  8240,  8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,
    8249,  8250,  8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,
    8259,  8260,  8261,  8262,  8263,  8264,  8265,  8266,  8267,  8268,
    8269,  8270,  8271,  8272,  8273,  8274,  8275,  8276,  8277,  8278,
    8279,  8280,  8281,  8282,  8283,  8284,  8285,  8286,  8287,  8288,
    8289,  8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,
    8299,  8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8315,
    8315,  8322,  8322,  8410,  8414,  8410,  8423,  8427,  8433,  8441,
    8451,  8461,  8473,  8476,  8495,  8521,  8524,  8530,  8533,  8538,
    8541,  8549,  8557,  8570,  8573,  8581,  8584,  8587,  8595,  8599,
    8602,  8605,  8608,  8612,  8613,  8614,  8615,  8616,  8622,  8623,
    8624,  8625,  8626,  8627,  8628,  8629,  8630,  8631,  8632,  8633,
    8634,  8635,  8639,  8645,  8646,  8658,  8679,  8679,  8683,  8684,
    8685,  8686,  8690,  8691,  8692,  8697,  8723,  8788,  8790,  8792,
    8794,  8798,  8803,  8805,  8808,  8810,  8812,  8816,  8819,  8824,
    8829,  8833,  8842,  8843,  8847,  8859,  8862,  8858,  8881,  8881,
    8885,  8886,  8889,  8890,  8891,  8892,  8893,  8894,  8895,  8900,
    8901,  8905,  8908,  8913,  8917,  8922,  8926,  8931,  8935,  8938,
    8942,  8945,  8950,  8954,  8965,  8971,  8971,  8972,  8973,  8980,
    8989,  8989,  8991,  8992,  8993,  8994,  8995,  8996,  8997,  8998,
    8999,  9000,  9001,  9002,  9003,  9004,  9005,  9006,  9007,  9008,
    9009,  9010,  9011,  9012,  9013,  9014,  9015,  9016,  9017,  9018,
    9019,  9020,  9021,  9022,  9023,  9024,  9025,  9026,  9027,  9028,
    9029,  9030,  9031,  9032,  9033,  9034,  9035,  9036,  9037,  9038,
    9039,  9040,  9041,  9042,  9043,  9044,  9045,  9046,  9047,  9048,
    9049,  9050,  9051,  9052,  9053,  9054,  9055,  9056,  9057,  9058,
    9059,  9060,  9061,  9062,  9063,  9064,  9065,  9066,  9067,  9068,
    9069,  9070,  9071,  9072,  9073,  9074,  9075,  9076,  9077,  9078
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "DYNAMIC_ARRAY", "RESIZE_ARRAY", 
  "ALLOCATE_ARRAY", "DEALLOCATE_ARRAY", "BEFORE_INSERT", "CONCAT_PIPES", 
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
  "INT_TO_ID", "TIMEOUT", "OFF", "WITH_1_DIMENSION", "WITH_2_DIMENSION", 
  "WITH_3_DIMENSION", "TILDE", "ILIKE", "$accept", "pause_screen_on_cmd", 
  "pause_screen_off_cmd", "start_rpc_cmd", "stop_rpc_cmd", "valid_port", 
  "remote_func_list", "remote_func", "arr_expr", "arr_next_math", 
  "arr_int_sign", "opt_attributes", "attributes_def", "@1", "attribs_sec", 
  "attribute", "win_attributes", "win_attributes_def", "@2", 
  "wattribs_sec", "wattribute", "call_cmd", "call_ext", "@3", "@4", "@5", 
  "@6", "@7", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15", 
  "opt_return", "opt_return_remote", "opt_func_call_args", 
  "func_call_args", "func_arg", "remote_host_name", "remote_func_name", 
  "case_cmd", "@16", "@17", "when_unit", "when_unit_expr", 
  "end_case_command", "op_otherwise_command", "@18", 
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
       0,   256,  1665,  1666,  1667,  1575,  1615,  1570,  1506,  1590,
    1385,  1492,  1488,  1403,  1565,  1301,  1360,  1434,  1601,  1588,
    1493,  1521,  1589,  1367,  1668,  1669,  1670,  1671,  1672,  1673,
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
    1296,  1297,  1298,  1299,  1300,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,
    1347,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1361,  1362,  1363,  1364,  1365,  1366,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1382,  1383,  1384,  1386,  1387,  1388,  1389,
    1390,  1391,  1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,
    1400,  1401,  1402,  1404,  1405,  1406,  1407,  1408,  1409,  1410,
    1411,  1412,  1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,
    1421,  1422,  1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,
    1431,  1432,  1433,  1435,  1436,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,
    1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,  1469,  1470,  1471,
    1472,  1473,  1474,  1475,  1476,  1477,  1478,  1479,  1480,  1481,
    1482,  1483,  1484,  1485,  1486,  1487,  1489,  1490,  1491,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1505,  1507,  1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,
    1516,  1517,  1518,  1519,  1520,  1522,  1523,  1524,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,
    1547,  1548,  1549,  1550,  1551,  1552,  1553,  1554,  1555,  1556,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1566,  1567,
    1568,  1569,  1571,  1572,  1573,  1574,  1576,  1577,  1578,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1591,  1592,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1602,  1603,
    1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,
    1614,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
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
     186,  1123,   182,     0,   200,   202,   266,   205,   260,   261,
     249,   226,   257,   203,   228,   270,   289,   247,   250,   245,
       0,   224,     0,   256,   248,   253,   259,   241,   258,   187,
     262,   187,   239,   240,   237,   265,     0,     0,     0,     0,
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
     206,   207,   208,   211,   187,     0,   187,   263,   264,     0,
       0,   187,     0,     0,     0,     0,   246,   234,  1199,     0,
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
       0,     0,   187,   235,   238,   938,   681,   850,   938,     0,
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
      95,    97,   483,     0,     0,   236,     0,     0,     0,     0,
     251,     0,   243,   225,   209,     0,   254,   242,   267,   944,
       0,   939,   940,   938,     0,   834,  2149,  2147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2131,     0,  1288,  1287,     0,  1289,     0,   386,  1286,  1228,
       0,     5,  1285,   387,   384,     0,   389,   174,   479,  1100,
       0,     0,  1295,   124,   383,   382,  1220,   377,   479,     0,
    1245,  2122,     0,   388,   352,     0,     3,     2,     0,   385,
    1225,     0,     0,   378,   375,   390,     0,     0,     0,     0,
    1293,  1283,   381,     0,     0,     0,     0,     0,     0,     0,
       0,  1282,     0,     0,     0,   175,  1222,   374,   373,     0,
       0,  2126,  2125,     0,     0,     0,   137,  1221,   380,   379,
       0,     0,   376,   479,   479,     0,   547,     0,     0,     0,
       0,     0,     0,   479,   781,  1196,     0,     0,  1104,     0,
    2115,     0,   104,     0,     0,   854,     0,     0,     0,     0,
     782,     0,     0,  1702,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   652,     0,     0,  2152,  2153,  2154,  2155,
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
       0,     0,     0,     0,     0,     0,    93,   924,     0,   212,
     227,     0,   187,     0,     0,     0,     0,     0,  1200,     0,
       0,  1188,   370,   368,   369,  1030,  1029,  1033,     0,     0,
    1232,   626,   627,   806,  1063,  1068,  2124,   619,   123,     0,
       0,  2089,  2088,   998,  2085,  2087,  2139,     0,  1239,     0,
    1235,  1244,     7,     0,     6,     0,  2132,  1064,     0,  1156,
    1155,  1103,  1154,  1102,   423,  1296,  1284,   835,   413,  1681,
    1290,   125,     0,  1067,   122,     0,   788,    24,   621,   391,
       0,   787,  1060,   789,     0,  1294,   876,   875,   878,   874,
     877,  2141,     0,   872,     0,   620,   971,   873,  2135,     0,
    2123,   121,   968,   684,   966,     0,   617,  2118,   726,   725,
     727,   723,     0,     0,   981,   622,  1349,  1345,  1348,     0,
       0,  1034,  1031,     0,  1025,  1027,  1026,  1024,  1023,     0,
       0,     0,  1022,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1012,  1003,  1004,     0,
    1048,   421,    24,     0,  2120,   126,   618,     0,  1197,  1195,
    1121,     0,  1670,  1671,  1122,  1210,  1122,  1105,  1106,  1109,
    1124,  1297,     0,     0,     0,     0,     0,     0,     0,     0,
      63,     0,   913,     0,    69,     0,   102,   596,   640,     0,
    1094,   988,  1098,     0,     0,  1049,  1214,     0,     0,  1101,
     644,   641,   642,     0,   646,   647,     0,   649,   650,     0,
     645,   948,   950,     0,     0,   949,   728,   946,   693,   942,
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
      -1,   816,   817,   818,   819,  1033,  2311,  2312,   207,   344,
     208,  1366,  1367,  2157,  2462,  3399,  2930,  2931,  3305,  3400,
    3401,   820,  1160,  2962,  2687,  3322,  2099,  2685,  3186,  2966,
    3318,  2686,  3187,  3407,  3498,  3510,  3320,  3513,   648,   649,
     650,  1477,  2378,   821,  1488,  1165,  1486,  2107,  2388,  2104,
    2386,  2391,  2691,  1487,  2385,  2108,  2690,   822,    18,    37,
      38,    39,    40,    41,   116,   825,  1093,  2055,  1390,  2338,
    2342,  2343,  2339,  2340,  2937,  2941,  2661,  2653,  2652,  2654,
    2657,   508,   294,   604,   826,    85,    86,    20,    63,   144,
      98,   279,   100,   101,   223,   358,   102,   103,   266,   363,
     252,   995,   532,  2838,   389,   927,  2214,   416,   417,   253,
     371,   364,   366,  1309,  1310,   148,   544,   149,   150,   377,
     254,   255,  2046,   582,   267,   270,   268,   269,   398,   559,
     560,   562,   567,   930,   271,   272,   407,   564,   219,    21,
      82,   180,   181,   182,   936,  2782,   183,   275,   264,   410,
     411,   412,   413,  2068,   827,   828,   829,   830,  1052,  3388,
    3158,  1368,  3450,  3451,  3452,  3489,  3488,  3492,   831,   832,
     833,   834,   835,   836,   837,  1044,   509,  1047,  1360,  1361,
    1399,  1130,  1400,   321,   322,   323,   324,   325,   326,   327,
     466,   510,  1294,   511,   512,   513,   514,   515,   516,   517,
     975,   209,   526,   984,   986,  1967,   210,   522,   981,   521,
     980,   524,   983,   523,   982,   945,   954,   328,   329,   212,
     330,   436,   437,   438,   439,  2092,   838,  3192,  3413,  2978,
     839,  1103,  2070,  2954,  2359,   117,   261,   554,  1900,  1226,
    1227,  1228,  1897,  1898,  2201,  2202,  2203,  2519,  2520,  1901,
    1902,  2197,  2523,  2515,  2209,  2210,  2526,  2527,  2780,  2776,
    2777,   840,  1408,    87,  2041,  2042,  2354,   422,  1085,  1135,
    1016,  1074,  1057,  1094,  2420,   213,  1017,  1011,  2008,  2656,
      89,   331,   841,   842,  1181,  1182,   843,   844,   845,   846,
    1189,  2989,  1210,  3197,  1211,  2134,  1212,  2417,  1213,  2707,
    1214,  2160,   847,  2130,  2706,  2988,  3195,  3194,  3475,   118,
      22,   848,  1384,  2047,  2048,  2150,  1846,  2151,  2152,  2717,
    2719,  2433,  2432,  2437,  2431,  2430,  2423,  2422,  2425,  2424,
    2427,  2429,   849,   850,  1091,   851,  1842,  1196,  3416,   852,
    1454,  3166,  2464,  2465,  2153,  2434,  2394,  2693,  1126,  1436,
    2074,  2362,  2075,  1432,   853,   854,  1174,  2122,  2982,   855,
     856,   857,   858,    23,    68,    24,    25,    26,   119,   120,
     859,   121,    27,   917,    28,   122,   123,   160,   556,  1906,
    2531,  3252,   124,   156,   382,   860,  2634,    29,    30,    31,
      32,    33,    62,    90,   125,   673,  1973,  2586,   861,  1169,
    2398,  2111,  2396,  3323,  2973,  2112,  2395,  2696,  2975,   862,
     863,   864,  1068,  1069,  1490,   126,   262,   555,   921,   922,
    1230,  1904,   865,  1215,  1216,   866,  1854,  1217,   332,    92,
      93,    94,    95,  1497,   186,   140,    96,  1022,   137,   215,
     216,  1498,  1499,  2405,  1500,   670,   671,  1198,   672,  1199,
    2414,  2415,  1501,  1502,  1364,  3118,  3119,  3274,  2017,  1083,
    1084,   867,  1379,  3307,   868,  2949,   869,  1394,  1395,  1396,
    2061,  2059,   870,   871,  2322,  2349,   872,  1342,  2014,   873,
    1127,  1128,   874,  1007,   875,  2475,   876,  3405,  2957,   877,
    2366,  3467,  3468,  3469,  3495,  1132,   878,  1503,  2124,  2409,
    2410,   879,  2034,  1015,  1354,   880,   881,   882,  2588,  3122,
    3285,  3286,  3375,  3376,  3380,  3378,  3381,  3441,  3443,   883,
     884,  1492,  2116,   885,  1494,  1146,  1147,  1148,  1470,   886,
     887,   888,  2085,  1462,  1141,   222,  1149,  1150,   333,  2589,
    2879,  2880,  2863,  1041,  1042,  2584,  2864,  2867,   127,   155,
     548,  1319,  2264,  2881,  3289,   448,   889,  1139,   128,   152,
     545,  1316,  2262,  2868,  3287,  2585,  1164,  2677,  3182,  3406,
    1465,   890,   891,   892,   893,   894,  1055,  2320,  1035,  2316,
     895,  2830,  1029,  1030,  2631,  1993,   896,   897,  1328,  1329,
    1330,  2005,  2301,  1331,  2298,  2002,  1332,  2273,  1994,  1333,
    1334,  1335,  1336,  2267,  1985,   898,  1064,  1046,   899,  1878,
    1879,  2175,  3017,  3214,  2747,  3014,  3421,  3422,  1880,  2182,
    2761,  1860,  2505,  3058,  3244,  2670,  2953,  2506,  1881,  1882,
    2251,  2832,  2833,  2834,  3100,  1883,  1884,  1398,   900,  1097,
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
    1050,  1892,  1893,  2178,  2749,  1894,  1895,  2491,  1962,  2225,
     907,  1177,  1831,  1832,  1833,  2126,  1834,  2127,  1896,  2495,
    3056,  3243,  2758,  3053,  3054,  3055,  3052,  3040,  3041,  3042,
    3043,  3044,  3045,  3343,  1023,  1280,  1025,  2018,  1281,    66,
      50,    80,    77,   909,  1152,  2089,  1387,  1456,   910,   424,
     911,  2645,   912,  2310,  1027,  2020,   913,   914,    44,   549,
     550,   551,   552,   553,   915
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2734
static const short yypact[] =
{
    5037,  1057, -2734, -2734,   348,   449,   449,   449,   449,   449,
     449,   449,   449,   348,   437, -2734, -2734,   437, -2734,  1064,
   -2734, -2734, -2734,   324, -2734,  5037, -2734, -2734, -2734, -2734,
   -2734,   931, -2734, -2734, -2734, -2734, -2734,   396,   461, -2734,
     507, -2734, -2734, -2734, -2734, -2734,   348,    78, -2734,  -199,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  1302,   303, -2734, -2734, -2734, -2734,  2724, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,   348, -2734,
   -2734,    78,   -58, -2734,   348,   628,  1064, -2734,   700, -2734,
   -2734, -2734, -2734,   511,   271, -2734, -2734, -2734,   913,   585,
     348, -2734, -2734,   954,   348, -2734, -2734,   348,   348, -2734,
   -2734, -2734, -2734,   348,   348, -2734, -2734, -2734, -2734, -2734,
    2724, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  5693,   271, -2734,   992,  4700, -2734, -2734,   528,
   -2734, -2734,   957,   303,   448, -2734, -2734, -2734, -2734, -2734,
    4718, -2734,   348,   605,   920,   348,  1064, -2734, -2734, -2734,
     348, -2734, -2734,   572,  1115, -2734, -2734,   694, -2734,   713,
   -2734,   716, -2734, -2734,   722, -2734,   750, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734,   766, -2734, -2734, -2734,
     764,   792,   803,   807,   813,   816,   835,   851,   854,   879,
    4700,   905,  8720,   908,   916,   927,   951,  1670,  1294, -2734,
   -2734, -2734, -2734,   850, -2734,   128, -2734,  4700, -2734,   178,
   -2734, -2734, -2734,    94, -2734, -2734, -2734,   880, -2734, -2734,
   -2734, -2734, -2734,   572, -2734,  1115, -2734, -2734,   955, -2734,
     980, -2734,   963, -2734, -2734,  1002, -2734,  1008, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734,  1042,  1455,   348,  1049,
   -2734,  1064,  1064,  1056,   348, -2734,   562, -2734,   864,  1169,
   -2734,   892,  1221,  1485,  1512,   348,  1518,  1539,  1547, -2734,
     956, -2734,    33,    33,    33,    33,    33,  8720,  1273,  1496,
      33,  8720,   274,  8720, -2734,  8720,  8720,  8720, -2734, -2734,
   -2734,  1060,  1159,  1162,  8720,  1335,  1166, -2734,  8720,  8720,
    1172, -2734,  1174, -2734,   916,  1178,  1180,  1181,  1187,  1598,
    8003,    71, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  1199, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734,  4700, -2734, -2734,   348,  4700,  1163,
     160, -2734, -2734, -2734, -2734,  1604, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,   562, -2734, -2734, -2734,  1605,
    1608,   303,  1518,  1609,  1611,  1013, -2734,  1596, -2734,  1264,
    1227, -2734,  1296, -2734, -2734, -2734,  1040, -2734, -2734,  1640,
   -2734,  1231, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1221,
    1231, -2734, -2734, -2734, -2734, -2734, -2734,  1232,   186,   212,
     298, -2734,  6663, -2734, -2734, -2734,  1243,  1676,   226,  1285,
   -2734,  1250, -2734,   279,   230,  1288,  1301,   237,   252,  4513,
    1307,    13,  1259, -2734, -2734,   175,  1310, -2734, -2734, -2734,
     259,  4723, -2734,  3915,  8164,  3335,  3335,  8720, -2734,  1217,
    8720,  8003,  1263, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
    1078,  1688,  4945,  8003,  1217,  1694,   429,  8720,  8720,  8720,
    8720, -2734,  8720,  8720,  8720,  8720,  8720,  8720,  8720,  8720,
    8720,  8720,  8720,  8720,  8720,  8720,  8720,  8720,  8720, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  8720,
    8720, -2734, -2734,  1279,  8720, -2734,  8720,  1281, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
     447,  8720,  8720,  8720,  8720,  1670,  8720,  1284, -2734,  4700,
    1261, -2734,  1094,  1101,  1703,  1467,   269,   297,   300,  1304,
     328,  1343, -2734, -2734, -2734,   348, -2734, -2734,   348,  1375,
   -2734,  3614,   448,  6607,  2272,   435,   348,  1722,   642, -2734,
    1169,  1718, -2734, -2734, -2734, -2734,  1721, -2734,  1725, -2734,
    1727, -2734,   348, -2734,   348, -2734, -2734,  1518,  1731, -2734,
   -2734, -2734, -2734,   348,  4700,    59,    33, -2734, -2734, -2734,
   -2734, -2734, -2734,  1335,  1335,  1740, -2734,  1741,  1177,  1151,
   -2734, -2734, -2734, -2734,  1380,  8003,   472,  1386,  6941,  1754,
    1335,  1391, -2734,  1392,  1394, -2734,  7272,  7339,  7450,  7500,
    7773,   866,  8164,  8325,  8595,  4898,  9089,  9145,  9154,  4951,
    9176,  3335,  3335,  4243,  4243,  1107,  8003,  7611,  7664,  1217,
    8003,  7842,  1217, -2734,  8003,  8003,  8003,  8003, -2734,  1780,
   -2734,  8003, -2734,   183,  4700, -2734,  1773,   642,  1359,  1770,
   -2734,  1772, -2734, -2734, -2734,  1774, -2734, -2734, -2734,  1179,
    1402,  1797, -2734,   348,  1406, -2734, -2734, -2734,   447,   447,
     447,  1072,   348,   240,   348,   348,   240,   240,  1112,   348,
   -2734,   348, -2734, -2734,   348, -2734,  1023, -2734, -2734, -2734,
     240, -2734, -2734, -2734, -2734,   348, -2734, -2734, -2734, -2734,
      82,    82,  8720, -2734, -2734, -2734, -2734, -2734, -2734,   240,
   -2734, -2734,   240, -2734, -2734,   348, -2734, -2734,   240, -2734,
   -2734,   447,   240, -2734, -2734,  8720,   240,   447,   348,   447,
     240, -2734, -2734,   157,   240,   240,   157,   240,   348,   157,
     240, -2734,   240,   240,   240, -2734, -2734, -2734, -2734,   447,
     240, -2734, -2734,   240,    36,   348, -2734, -2734, -2734, -2734,
     240,  1113, -2734, -2734, -2734,   240, -2734,  2317,   447,  8720,
      33,    33,   240, -2734, -2734,  1072,   447,  1135,  8720,  8720,
   -2734,   814,  8720,   240,    78, -2734,  8720,   240,  1785,   447,
   -2734,   240,  8720, -2734,  8720,    82,   348,   240,   348,    33,
     240,   348,    33, -2734,   348,   187, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734,   244, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734,  1022, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,   679, -2734,   348,
   -2734,   427, -2734,  1409, -2734, -2734, -2734,  1505, -2734, -2734,
    1419,  1421,  1424,  1428, -2734, -2734,  1193,  1818,  1430,  1431,
     457, -2734,  1395, -2734, -2734, -2734,  1204, -2734,  1433, -2734,
    1811, -2734,  1248, -2734, -2734,  1215, -2734, -2734, -2734, -2734,
    9275, -2734,  1060,  1451, -2734,  1060, -2734,  1060,  1060,  1060,
    1060,  1060,  1825,  1826,  1827,  8720,  1459,  1832,  8720,  1463,
    1464,  1471,  1473,  1476,  1478,  8720,  8720, -2734,   201, -2734,
   -2734,  1570, -2734,  1481,  1482,  1251,  1484,   348, -2734,   348,
    1487, -2734, -2734, -2734, -2734, -2734, -2734, -2734,   555,  1446,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1260,
    1206,  1427, -2734,  1274, -2734,  1272, -2734,  1890,  -123,   332,
   -2734, -2734, -2734,  1470, -2734,  1241, -2734,  1415,   219, -2734,
   -2734, -2734,  1457, -2734,  8003, -2734, -2734, -2734,  8136, -2734,
   -2734, -2734,   447, -2734, -2734,  1241, -2734,    22, -2734, -2734,
    1629, -2734,   131, -2734,  1439, -2734, -2734, -2734, -2734,  1900,
   -2734, -2734,  -230, -2734,  1289, -2734,  1290,  1900, -2734,  1313,
   -2734, -2734,  1490,   121, -2734,  1453, -2734,  1255, -2734, -2734,
   -2734, -2734,  1256,   272,  -103, -2734,  1260,  1590, -2734,  8720,
    8720, -2734,  1916,   240, -2734, -2734, -2734, -2734, -2734,    66,
      66,    66, -2734,    66,  1149,    66,    66,  1323,    22,  1323,
    1323,  1156,  1156,  1323,  1323,    22, -2734,  1921, -2734,   616,
    1922, -2734,    22,   106,    47, -2734, -2734,  8720, -2734, -2734,
   -2734,   841, -2734, -2734,   448,  1540,   448,  8720, -2734,    79,
   -2734, -2734,  8720,  1492,  1499,  1501,  1502,  1377,  1503,  1135,
   -2734,  1583,  1027,  1345, -2734,  1361, -2734, -2734, -2734,  1185,
   -2734,  1938, -2734,  1933,   348, -2734,    80,  5966,  1371, -2734,
   -2734,  1948, -2734,  1303,  1948,  1949,  1309,  1948,  1949,  8720,
    1948, -2734, -2734,   219,   447, -2734, -2734,  1531,   366, -2734,
   -2734,  1530,   447,  8720,  1532, -2734, -2734,  1945,  1956,  1904,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1223,  1223,
     240,   240,   240,  2674, -2734, -2734,  1879,   679, -2734, -2734,
     629, -2734, -2734, -2734,  1520, -2734, -2734, -2734, -2734,  5693,
    1518, -2734, -2734,  1368,   348,  1383,  1335,  1400,  1381, -2734,
    9341,  9341, -2734,  1260, -2734, -2734,  1458, -2734, -2734,  1652,
    1561, -2734,  1564,  1565, -2734,  1566,  1567,  1568,  1569,   348,
      35, -2734, -2734, -2734, -2734,   118, -2734,   348,  1889, -2734,
    1581, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734,  8003,   335, -2734, -2734,   374, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1545, -2734,   378,
   -2734, -2734, -2734, -2734, -2734, -2734,  1064, -2734, -2734,  1064,
     902,   133,  1986, -2734, -2734,   506,   205,   516,  2008, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1425,  1206,  1272,
   -2734,  1112,   438,  1209,   348, -2734, -2734,   348, -2734,  1413,
    1390,  1436,  1588, -2734,  1600,   112, -2734, -2734, -2734, -2734,
   -2734,  2021, -2734, -2734,  1403,  1602, -2734, -2734, -2734,  1112,
    1226, -2734,  1226,  1135,   157,  8720,  8720,  8720,  1603, -2734,
   -2734,   447,   447, -2734,  1410,  1135,    33,  1373,    36,   447,
   -2734,  1412,  8720,  1689, -2734, -2734,  1486, -2734, -2734,  2041,
   -2734,    89,   219, -2734, -2734,  2033,  2037, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  4148, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  2317, -2734,  1156,  8720,   146,
    2031,  2032, -2734, -2734, -2734, -2734, -2734,   176, -2734, -2734,
   -2734, -2734,  1902, -2734,  1839, -2734, -2734, -2734,  8720,    82,
   -2734, -2734,   348,  2040,    33,    33, -2734,  1474, -2734,    33,
    1438,   447, -2734,   348,   348,  8720,    26, -2734,  1489, -2734,
     286, -2734,  1584, -2734,  1587,  8720,   872, -2734, -2734,  1456,
   -2734,  2071, -2734,  1526, -2734,   447, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  5296, -2734, -2734, -2734, -2734,   348,    33,    33,   204,
     366,  1928,  2370,   447,   219, -2734,  1534, -2734, -2734,  2041,
    2058,  1682, -2734, -2734, -2734, -2734, -2734,  1763,  1763, -2734,
     180,  1538, -2734,   348, -2734, -2734,  1241,  1241, -2734, -2734,
   -2734,   348, -2734,   348,   472,  1241, -2734,   643, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  1212, -2734, -2734, -2734, -2734, -2734,   179,   179,   601,
     899, -2734,   422, -2734,   629, -2734,  1064,  2068, -2734, -2734,
    1282,  1698,  1662, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  1443, -2734, -2734, -2734,  2109,  2109, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  1469,   472,  1702,   604,   505,
    9275,   505,   505,   505,   505,  1477,  9275,  9275,   245,  1572,
     480, -2734,  9275,  9275,  9275,  9275, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734,  1112,  8720, -2734, -2734,  1708,  2068, -2734,
   -2734, -2734, -2734,  1064, -2734, -2734,  1241, -2734,   773, -2734,
    1672, -2734, -2734,   773, -2734, -2734, -2734,  1673,  1674,   409,
    1675,  1677,  2002, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
     348, -2734, -2734,   409,  1452, -2734,   555, -2734,  1715,   271,
    1500, -2734,  1135,  1542, -2734, -2734,  1663, -2734, -2734, -2734,
    1574, -2734,   348,   348,   348, -2734, -2734, -2734,  8136,   348,
   -2734,  1509, -2734, -2734, -2734, -2734,  1504, -2734,  2128,  2129,
   -2734,  2131,  1552,  8720, -2734, -2734,  1515,  2137, -2734,  1655,
    1516,  1949, -2734, -2734,  1521,  1218,   348, -2734, -2734,  1710,
     240,   923,  8720, -2734,   348,   348,  8720,    37,    22,  2143,
    2142,  2130,  2134,  1149, -2734, -2734, -2734, -2734, -2734,   447,
    1620, -2734, -2734,  2092,  8720,   448,  1077, -2734, -2734,  1834,
    2161,  2162,   388, -2734,   394,   348,  1771,  1135, -2734,  8720,
    1733,  1736, -2734, -2734,  1808, -2734,  8720,    28, -2734,  1573,
   -2734, -2734,   206, -2734,  8720, -2734, -2734,  1546,   992, -2734,
    1291,   348,  2164,  8882, -2734, -2734,  1112,   447, -2734, -2734,
      88, -2734,  1949,  1949,  1514, -2734,  1625,  1630, -2734, -2734,
   -2734, -2734,    33,    33, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  1468, -2734, -2734, -2734, -2734,    33,  3129,  2178,  2158,
   -2734,  1135,   794,   228,   159,  2080,    17,  1072, -2734,    87,
   -2734, -2734, -2734,  1750,    73,  1241,   139, -2734,  1563,  1558,
   -2734, -2734,   434, -2734, -2734, -2734, -2734,  1755,  1575,  2188,
   -2734,  1475, -2734, -2734, -2734, -2734,   447,   202, -2734, -2734,
   -2734,  1550,   899, -2734,   348,   348, -2734, -2734,   348,   595,
   -2734, -2734, -2734, -2734,  1765, -2734, -2734, -2734,  2176, -2734,
   -2734,  1519,  9275, -2734,   442,  1815,  2222, -2734, -2734, -2734,
    9275, -2734,   395,  9275,  9275,  9275,  9275,   348,   403, -2734,
     148,  2230, -2734, -2734,   348,  3463, -2734,  1866,   348,  1618,
     505,  1911, -2734, -2734, -2734, -2734, -2734, -2734,  8003, -2734,
    1819, -2734,  1784, -2734,  1786, -2734,  1817,   423, -2734,  3463,
     441,   120,   120,   454, -2734,   120,  3463, -2734, -2734,  1458,
    1458, -2734,  1821, -2734,  1824,  1828, -2734,  1840,  1844, -2734,
    1845, -2734, -2734, -2734,   208, -2734, -2734, -2734,   458, -2734,
   -2734,   463,   348, -2734, -2734,  1209,  2246,  1135,  4700,  8720,
   -2734,  2250, -2734, -2734, -2734, -2734,   409, -2734, -2734,  1636,
     409,   144, -2734,  1135,  8720,  8720,  8720,  8455,  2257,   107,
   -2734, -2734,  1135,   348, -2734, -2734,   348,   348, -2734,   960,
   -2734, -2734,   408, -2734,  1638,  8720, -2734, -2734, -2734,  2262,
   -2734, -2734, -2734, -2734, -2734,   348,  1949, -2734, -2734,  1716,
   -2734, -2734,   496, -2734, -2734, -2734,   447, -2734,  4392, -2734,
   -2734, -2734,  1953,  2260, -2734,    33,  1937,  1947,  1833,  1679,
    1951,  1869, -2734, -2734, -2734,   -19,  1942, -2734, -2734, -2734,
   -2734,  1808, -2734, -2734, -2734,   263,   491, -2734, -2734, -2734,
    2041,  8720,  1877, -2734,  1846, -2734, -2734, -2734, -2734,  2304,
   -2734, -2734, -2734,  1885,  2309, -2734, -2734,  1659, -2734,  2292,
      22,   348,  2429,  2429,  2429,  2429, -2734,  2315, -2734,  2316,
    2429,  2429,  2429,  2429,  4148, -2734, -2734,  2429,   162, -2734,
   -2734, -2734, -2734,  2297,  2312, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734,  2313, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,   497, -2734, -2734, -2734,  2305, -2734, -2734,  1241,
   -2734,   472, -2734, -2734, -2734, -2734, -2734, -2734,  1729,  1734,
     296, -2734,    87, -2734,   120,  1712,   240, -2734,  1907, -2734,
   -2734, -2734,   348,   348,  9275,   195, -2734,  8720, -2734,  8720,
   -2734, -2734, -2734, -2734, -2734, -2734,   240,   120, -2734,  1241,
    1043,  1711,  1719,  2340, -2734,  2341, -2734,   447,   348,   884,
     884, -2734, -2734,  2342, -2734,  2342,   607,   607,  2342, -2734,
   -2734,  2272, -2734,  1952, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,   118,  1458,  1717, -2734,  1458,  1964,  9275, -2734,
    1966,  1968,  1969,  1970, -2734, -2734,   245, -2734,   245, -2734,
   -2734,  3231,  1914,  1631,  1914,  2347,  2361, -2734, -2734, -2734,
   -2734, -2734, -2734,   224,  9275, -2734,  1917, -2734,  2099,   132,
     228,   348, -2734,  3058,   119, -2734,  2272,  1293, -2734,   119,
     120,   773, -2734,   174, -2734,  1241,   532,  1976,  2369,  1753,
   -2734, -2734,   500, -2734,   409, -2734,   510,   292,  1744,  -107,
    2353,  2353,  2354,  2353,  2353,  2355, -2734,   173, -2734,   773,
     348, -2734,   409, -2734, -2734,  1757,  1135,  2375,   211, -2734,
     348,   517, -2734,  8720,  1987,  2365,   523,  1135,  2381, -2734,
   -2734, -2734, -2734,  8720,  1816,  2111,  8720, -2734, -2734, -2734,
   -2734,   408,  1249,  1249,  2387,   337, -2734,  2388, -2734, -2734,
   -2734,  1249,   348,  1842,  1340,  2390,   348,   -17,  8720, -2734,
   -2734,  1149, -2734,  1723,  8720, -2734,  2392,  8720, -2734,   447,
   -2734,  1023,   348,   447, -2734,  2004,  8720,  8720, -2734, -2734,
     -19,  1942, -2734,  4148, -2734, -2734,  1236, -2734, -2734,  1829,
   -2734,  4700,  8477,  8882,   447,   447,    72,   934, -2734, -2734,
   -2734,  1788, -2734, -2734, -2734, -2734,    33,  2429,    33,  2429,
   -2734, -2734, -2734, -2734, -2734, -2734,    22, -2734,  1106,  1121,
    3129, -2734,  2012,  1978,  9275,  1212,   159,   159, -2734, -2734,
   -2734, -2734,   524, -2734,  1940, -2734,   120,   593, -2734,  1789,
   -2734,  2416,  3711,  3711,  3711,  3711,   120,   120, -2734, -2734,
   -2734,  1863, -2734,   525, -2734,  1792, -2734,   348,   348,  1475,
     447, -2734,  2342, -2734, -2734,   348,   607,   607, -2734, -2734,
     607,  2213,  1800, -2734,  2035,  1799,  1519,  1803, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,   534, -2734, -2734,  1959, -2734,
     400,   494, -2734,  3463,  3463, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734,  9341,  9341,  2001,  9341,  2005, -2734,
    9341,   758,  9275,  2438, -2734, -2734,  3463, -2734, -2734, -2734,
   -2734, -2734,  2439, -2734,  -111, -2734, -2734,  2099,  1820, -2734,
   -2734,    82,    82,    82,  2420,    82,    82,    82,    82,    82,
      82,  2422, -2734,  2423,    82, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734,  3058, -2734,   447,  1831, -2734,  1999,  2213,
    2428, -2734,  2431,  2432,  2434,  2446,  2448,  2449,  1252,  1293,
   -2734,  1999, -2734,   535, -2734, -2734, -2734,  2450, -2734,  2156,
     120,  1388,   120, -2734, -2734, -2734, -2734,  1519,  2451,  1519,
   -2734,  2473,  2473,   537,  2084,  2473, -2734,  2086, -2734, -2734,
   -2734,   773, -2734, -2734, -2734, -2734,  1135, -2734, -2734,   409,
    2099,  2041, -2734,  2011, -2734,   278,  1135, -2734,  2481,  2051,
   -2734, -2734,  2094,  1939, -2734, -2734,   348,  1249,  4700,  1426,
     348,  1249, -2734, -2734,    33, -2734, -2734,  8720, -2734, -2734,
   -2734,    33,  2041,   447,  2248, -2734,  2468,  1625,  8003,  2472,
   -2734, -2734,   219,  2066, -2734, -2734,  8720, -2734, -2734,  2102,
   -2734, -2734, -2734,   491, -2734,  1625, -2734,  8720, -2734,   216,
   -2734,  1922, -2734, -2734, -2734, -2734, -2734, -2734,  2055,  2153,
   -2734,  2487, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734,   348, -2734,   156, -2734, -2734, -2734,  1212,
     120, -2734,   472,  2364,   540, -2734, -2734, -2734, -2734,   348,
    1957,  2003,  2003, -2734, -2734,  9311,  2074, -2734, -2734,  2075,
    2076, -2734,  2079,  2082,  2087,  2088,   348,   404, -2734, -2734,
     541, -2734, -2734,  2619, -2734, -2734, -2734,   548,  2515,  2515,
   -2734, -2734,   549,  2517,  2513, -2734,   172, -2734, -2734,   120,
   -2734,   143,  1903, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
    2314,  5693, -2734,  1519, -2734,  1519,   245, -2734, -2734,  2361,
   -2734,  2083,  1889,  2083,   111, -2734,  2083,   111, -2734,  2083,
    9341, -2734, -2734,  9275, -2734,  9275,  2347,   132, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,   351,  2528, -2734,
     447,  1586, -2734,  2314, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734,   220, -2734, -2734, -2734,
    2070, -2734, -2734,  2138, -2734,  2510,  2140,  2150,  2523, -2734,
   -2734,  2154, -2734, -2734, -2734, -2734, -2734,    33,    22,  2171,
    1135, -2734,  8720, -2734,  1979,  2530,    22, -2734, -2734,   843,
   -2734, -2734, -2734, -2734,   190,  2163,  1949,  2309,  2318, -2734,
      22,  2167,  2168,  2143,  2125, -2734,  2217,  2172, -2734, -2734,
   -2734, -2734,  2325,  2108,  8720,  2132, -2734, -2734, -2734,  1625,
   -2734,   550, -2734,   447,  2022,  1212,  1212, -2734, -2734,  9275,
   -2734, -2734,   120, -2734,  2144, -2734,  2022,  2258,  2258,  2182,
     604,   505,  9332,   505,   505,   505,   505,  1962,  9332,  3711,
   -2734,  9332,  9332,  9332,  9332, -2734, -2734,   120,  2570,   120,
    3711,   240,  3463, -2734,   447, -2734, -2734,   311, -2734, -2734,
     348, -2734, -2734, -2734, -2734, -2734, -2734,   173, -2734, -2734,
     551, -2734, -2734, -2734, -2734,   553, -2734,  2083,  2581, -2734,
   -2734, -2734, -2734, -2734, -2734,   447,  2528, -2734, -2734, -2734,
     447, -2734,   447, -2734, -2734,  1580, -2734,  2348, -2734,  2349,
    2569, -2734, -2734,  1965, -2734, -2734, -2734, -2734,  2202, -2734,
   -2734, -2734,  1135, -2734,  2203,  9537,  2166, -2734, -2734, -2734,
    1980,    22, -2734, -2734, -2734, -2734, -2734, -2734,  2206,   219,
   -2734,  2217,  2217,   491, -2734,  4700,  2023, -2734, -2734,   348,
   -2734,  2309,   480, -2734, -2734,   118, -2734,  9012,   480, -2734,
    2210,  9332, -2734,   554,  9332,  9332,  9332,  9332,   348,   561,
   -2734, -2734, -2734, -2734, -2734, -2734,  2175, -2734, -2734, -2734,
    2347,  2309,   143, -2734, -2734, -2734, -2734, -2734, -2734,   116,
   -2734, -2734, -2734,  9275, -2734,  1777,  1777, -2734,  1777, -2734,
    1777,  1777, -2734, -2734, -2734,  2180,  1519, -2734,   478, -2734,
   -2734,    66,    66,    66,    66,    66,    66, -2734,  2583, -2734,
     573, -2734,  8720,  1429, -2734,   619,  2217,  8720,  2217,  2143,
   -2734, -2734, -2734,  2368,   223, -2734,    22, -2734, -2734, -2734,
   -2734,   575, -2734, -2734, -2734, -2734,  2224,  9332, -2734,  2226,
    2227,  2232,  2233, -2734, -2734,  3711, -2734, -2734, -2734, -2734,
   -2734,  1777, -2734,  1777, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,   726, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  9537, -2734,  2614, -2734, -2734, -2734, -2734,   834, -2734,
   -2734, -2734, -2734, -2734, -2734,    88, -2734,  9012, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,   580, -2734, -2734,   871,   871,
   -2734, -2734,   871, -2734,  8720,   924, -2734, -2734,  2234,    72,
   -2734, -2734, -2734, -2734, -2734,  2235, -2734, -2734, -2734, -2734,
     258, -2734,   219, -2734,  2143
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2734, -2734, -2734, -2734, -2734,   -54, -2734,     5,  -198, -2734,
   -2734, -1062,   -72, -2734, -2734, -2066, -2734, -2734, -2734, -2734,
    -820, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -1966, -2734,  -974, -2734,
    1657, -2734, -2734, -2734, -2734, -2734, -2734, -2734,   253, -2734,
   -2734, -2734, -2734,  1157, -2734,   539, -2734, -2734,   -65, -2734,
   -2734,  2609, -2734,  2612,  2096, -2734, -2734, -2734, -2734, -2734,
     320,    -8, -2734,   316, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  -137,   469,   365, -2734, -2734,
    2285,    53, -2734,  2514, -2734, -2734,  2518, -2734,  2435, -2734,
   -2734, -2734, -2734, -2734,  2296,  2007,   699,  2299,  -524, -2734,
   -2734, -2734, -2734, -2734,   704,  -648, -2734, -2734, -2734, -2734,
   -2734, -2734,  -148,  2127,  2441,    32,  2081, -2734,  2114,  1434,
   -2734,  2286, -2734, -2734, -2734, -2734,  2288, -2734, -2734, -2734,
   -2734,  -408, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
    2113, -2734,  2116, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -1305, -2734, -2734,  -763, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  -119, -2734, -2734,   663, -2734,
   -1074, -1116,   137, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  1720, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
    -620, -2734, -2734, -2734, -2734, -2734,  1905, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  -540, -2734,  -118, -2734, -2734,
   -2734, -2734,  2261, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  1479, -2734, -2734, -2734, -2734,   492, -2734, -2734, -2734,
   -2734, -2734, -1712, -2734, -2734,   486, -2734, -2734, -2734, -2734,
   -2734, -2734, -1054,  -780,   376,   637, -2734,  -278,   599, -1092,
     789, -2734,  -418, -2734, -2351,    -4,  -463, -2734, -2734, -2223,
     196,  1339, -2734, -2734,   737,   869, -2734, -2734, -2734, -2734,
   -2734, -2734,     1, -2734,  -279, -2734,   874, -2734,   577, -2734,
     310, -2734, -2734, -2734, -2734,  -784, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734,   398, -2734, -1794, -2734,   581, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734,  1346, -2734, -2734, -2734, -2734, -2734,
   -2734,  -443, -2734, -2734, -2017, -2734, -2734, -2734, -2734,   460,
   -2102, -2734, -1089, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,  2710, -2734, -2734,
   -2734,  2617,  2707, -2134, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  -380, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
    2713, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,   633, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  -677,  1997, -2734, -2734, -2734, -2734, -2734,  1835,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  2152, -2734,
   -2734,   -49, -2734, -2734,   639, -2734, -2734, -2734, -1004,  -216,
    2399, -2734, -2734, -2734, -2734,   520, -2734, -1006,  1756,   915,
   -2254,    55, -2734,   641,  1576,  -353,  -507, -2734, -2734, -2734,
    1387, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734,  1328, -2734,  -754, -2734,  -654, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734,  -691, -2734, -2734, -2734, -2734, -2734, -2734,
      76, -2734,  1414,   317, -2734, -2734, -2734, -2734, -2734,   -99,
   -2734,  -498, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,  1641, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,  -525, -2734,  1322,  2326, -2734,
   -2734,   -88, -2734,  -626, -2734, -2734,   -70,   207, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734,   993, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2522, -2734,  1447,   475, -1312, -2734, -2734, -2734,   795,
   -2734, -1922, -2734, -2734, -2734, -1925, -2734, -2734, -1882, -2734,
   -2734, -2734, -2734,   815, -2734, -2734, -2734, -2734, -2734, -2734,
     322, -2734, -2734, -2734, -2734, -2734, -2734,  -674, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734,  -293, -2734, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734,   299, -2734, -2734,
   -2734,  -555, -2734, -2734, -2734, -2734, -2734, -2734,   -77, -2734,
   -2734,   225, -2734,   542, -2734, -2734, -2734, -2734, -2734, -2734,
   -1300, -2734, -2734, -2734, -2734, -1907, -2734, -2734, -2734, -2734,
   -2734, -2734, -2348,   574, -2734, -2493,   645, -2734, -2734, -2228,
      18,    19,   264, -2734, -2065, -1787, -2734, -2734,  -263,  -543,
   -2734, -2734, -2734, -2734, -1876, -2734, -2734, -2734, -2052, -2734,
   -2734, -1239, -2734, -1021,   964,  -312, -2053,   234, -2734,   372,
   -2734, -2734, -2734, -2734,   -20, -2734, -1451, -2634,  2819, -2734,
   -2734, -2734, -2734, -2734, -2734, -2552, -2734,    68, -2734, -1904,
   -2734,  1615, -2734, -2734,   428,   260, -2734, -2238,   262,  -179,
      97, -1586, -1834, -2177,   898,  -249,  -811, -1214, -2734,   903,
   -2734, -2734, -2734,   995,  -771, -2734, -2734,  -479,  1637, -2734,
     657, -2734, -2734, -1795,  -162, -2734, -2734, -2734, -2733,  -362,
   -2734, -2734, -2734,  1029, -2734, -2734, -2734, -2734, -2734, -2734,
   -2734, -2734, -2734, -2734, -2612,  -377, -2734, -2682, -2255, -1613,
   -1409, -2734, -2734,  -365,  -681,  -659,  -733,   560, -1458,     8,
    2283,   -30, -2734, -2734, -2734, -2734, -2734,  1480, -2734,  -262,
   -2734, -2734, -2734, -2734, -2734, -2734, -2734, -2734,  -310,   644,
    2319, -2734, -2734, -2734, -2734
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2147
static const short yytable[] =
{
      43,   350,   292,   115,   575,   425,   426,   989,    34,    58,
      60,  1403,  1305,    60,  1352,  2004,  1144,  1340,   211,   260,
    1982,  1457,   978,   427,   428,  1431,  1401,   677,   440,  1024,
     280,  1138,  1355,    34,  1365,   133,  1925,  1926,  2341,    72,
    2180,  2593,    76,    79,  2695,  2542,  2136,  2137,  2607,  2784,
    2027,   131,   586,   937,   947,   115,  1410,  1411,    88,  1412,
      42,  1433,  1434,    42,    42,  2233,  2234,  2235,  2236,  1073,
    1449,  3047,  3048,  3049,   130,  2299,   129,    79,  2179,   941,
      88,  2300,   211,   320,  1468,  1043,    42,  2726,  1038,   139,
    1098,  2463,  1404,    42,  2062,   298,   146,   518,  1048,   211,
     151,   375,  2222,   153,   154,    42,   298,  2274,  1039,   157,
     158,   586,  1024,   355,  2658,  1839,    99,  1844,   298,   356,
     357,  1102,  2479,  1947,   383,   384,  1382,  2647,   129,  1849,
    1862,    88,  1350,   348,    42,   298,  1253,  1254,    42,  2986,
     298,  1253,  1254,    42,  3051,  1350,   525,    42,   256,  1277,
     142,   259,  3074,  1099,  1100, -2145,   263,  1350,  2831,    42,
      42,  1947,  2063,  1137,  2064,   348,  2065,   586,   429,  1142,
      42,    42,   441,  1350,   443,    42,   444,   445,   446,  1179,
    2803,  1448,  1066,  3006,    42,   451,    42,  1840,   348,   462,
     463,   568,  1450,  1451,   597,   586,    99,   298,  2908,  1254,
     224,   598,   298,   351,   352,    42,   348,  2517,  2794,  2062,
    2796,   298,  1191,  1192,    42,   353,   348,   570,  2600,  2603,
    1010,   348,  2603,  1370,  1371,  3290,   211,  2486,   348,  2109,
     211,   578,    42,  2805,  2806,   586,  2807,  2808,  2809,  2810,
    2811,  2812,   586,   298,  1191,  1192,    42,  1504,  2752,  2753,
    2754,  2755,  2756,  1142,   380,    42,  1049,   586,  2865,  1049,
     386,    84,  2483,  3142,   586,  3144,  1340,    42,   368,  1058,
    1350,   414,    42,  1049,   659, -2145,  2648,  1049,   423,   423,
     423,   423,   423,  3159,  1075,   460,   423,  1339,  2694,  1049,
      42,  1058,   339,   340,   341,   342,   343,  1086,  2803,    42,
    1058,  1201,   661,   572,   376,   143,  1020,  1095,   944,  2109,
    3235,  1020,  1101,   653,  1200,  3101,  3362,  2751,  2489,  1136,
    2164,  2165,  2341,    42,    67, -2145,  3241,  1866,   605,  2898,
    1086,   608,  2724,   665,  1086,  2800,  1081,  1347,  1086,    84,
    1964,  1440,  1441,   527,  1058,  1087, -2145,  1058,   616,   617,
     618,   619,    84,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,   630,   631,   632,   633,   634,   635,   636,
    2103,  1844,  2390,  1012,  2580,    42,  1012,  1012,  2950,  1964,
     637,   638,    84,  1969,    65,   640,   940,   641,  1480,  1183,
    1012,  1201,  1186,  2375,  1375,  2083,  2069,  2781,  3156,   586,
    2548,  1376,   644,   645,   646,   647,  2803,   651,  2548,  1012,
     594,   211,  1012,  2662,    84,  2490,  1088,   533,  1012,   535,
    2616,  1345,  1012,    84,    99,  3511,  1012,    73,  2591,  1505,
    1012,  2743,    81,  3098,  1012,  1012,    42,  1012,   988,  3254,
    1012,  3255,  1012,  1012,  1012,  2110,  2591,  2543,  1937,  1392,
    1012,    65,  2869,  1012,  2764,  1201,  3363,  3207,    84,  2604,
    1012,    42,    59,  2620,    42,  1012,   211,    84,  2622,    19,
    1346,  1946,  1012,   581,    42,   339,   340,   341,   342,   343,
    2226,  2813,  3099,  1012,  3235,  3235,  1090,  1012,   823,   916,
      36,  1012,  2119,  2525,    19,  2079,  2528,  1012,   301,   136,
    1012,  2671,  2730,  2805,  2806,  2892,  2807,  2808,  2809,  2810,
    2811,  2812,  1256,  1009, -2145,  2892,    88,  1256,  1133,  1134,
    1393,  1845,  2919,  1201,  2899,  2110,  2835,  1257,  2919,  3010,
    3059,   138,  1257,    42, -2145,    35,   211,  2600,    42,  3076,
    2890,   669,  3148,    42,   669,  3212,  3229,  1185,  2663,  1868,
    1188,  2355,   669,  3229,  3237,  3329,  3369,  3005,  3369,  3427,
     349,   908,   918,  1845,   132, -2145,  3427,  1861,   414,  1983,
     414,  2885,  1405,  2397,  1256,  2741,  2740,  1193,  3461,   939,
    3477,   943,   423,   569,  2556,  3229,   573,  1936,   663,  1257,
     964,  2972,   530,  1202,  1009,   581,  1204,  1877,  3096,  1203,
    2814,  2815,  2036,  1089,  2245,  2010,  3180,  3512,   595,   571,
    1485,  3246,  2106,  2617,  2050,   987,  1320,  1321,  2480,  1463,
    2987,  1466,  2166,   579,  3190,  3355,  1406,   587,    42,  1019,
    1506,    42,   953,  1306,   590,  1874, -2145,  2734,  2866,  1203,
    1136,  2000,    84,  2917,  1322,  1323,  1324,  2951,  3193,   591,
    1009,  1452,  3291,  3333,  3334,  3474,   601,  3160,  2816,  1987,
    2011,    97,  1389,  1507,  3001,  1971,   660,  2077,  2412,   669,
    1948,   442,  1988,    78,    88,    88,    88,    88,  1008,  1194,
    1013,  1014,  1024,  1383,  1021,  1026,  1204,  1028,  2031,  2896,
    1031,  2004,    88,  3015,   662,  2913,   319,  2037,  2750,  3177,
    2914,  1014,  1469,  3242,  2471,   421,  1920,   319,   421,   421,
    1024,  3332,  2066,  3167,  1455,  3203,  1909,  3172,  2419,   319,
    2067,  1014,  2894,  3338,  2595,   666,  2637,    88,  3256,  1348,
   -2145,   942,  1965,    88,  1014,    88,   319,  2595,  1453,    88,
    1407,   319,    88,   584,  1076,    88,  3165,  2080,  1067,  2595,
    1204,  2813,  3447,  3485,  2518,    88,  1987,  1859,  1101,  1136,
     423,  1092,  1372,  2357,  1168,  2240,  1987,  1021,  3090,  1988,
     599,  1966,  1874,  2544,    88,  1970,   423,   423,  2145,  1988,
    2496,    88,    88,    88,  2757,  2376,  2817,  1162,  1009,  2497,
      79,  2377,  2549,  1012,  1209,    88,    84,  3078,   319,  1020,
    2555,  2938,  1180,   319,  1180,   423,  2772,  1180,   423,    45,
    1180,    88,   319,  1927,  2498,  2183,  2248,  2499,  1204,  2419,
    2592,    42,   303, -2145, -2145, -2145, -2145, -2145,  2608,  2609,
    3448,  1908,  3007,  3008,  3449,  2500,   957,  3138,  2594,  3141,
    3228,    42,  3419,  2088,   319,  2173,  2174,   306,  3328,  1045,
    3147,  2605,  2818,  3151,  2181,  2621,  1293,  2933, -2145,  1293,
    2623,   339,   340,   341,   342,   343,   651,   651,   136,  2227,
    2814,  2815,  1059,  2114,   474,   134,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,  1243,
    1990,  2223,   613,  2672,  2731,  3272,   141,  2893,  1205,  1206,
    1207,  1928,  2819,  2820,   585,   488,  1991,  2895,  2204,  1208,
    1012,  1012,  1012,  2149,  2920,  1229,  1131,  1929,   143,  2145,
    2924,  3011,  3060,  1153,  2529,  1145,  1151,  2244,  2816,  1166,
     312,  3077,  3135,  1170,  3149,  1975, -2145,  3213,  3230,  1176,
    2501,  1178,  1989,   145,  3273,  3236,  3238,  3330,  3370,  3331,
    3371,  3428,  2003,   958,  1446,  2266,  1270,  3208,  3434,   147,
    1930,     1,  2939,   489,   490,   491,   492,   493,   494,  3490,
    3462,   218,  3478,  1154,  3350,   221,  2799,  3501,  2802,   495,
     496,   497,     2,     3,  2363,  3358,  2228,  1990,    46,    84,
    3361,  2196,   217,  1315,  2502,   669,  2887,  1990,   387,  2249,
    1931,  2503,    47,  1991,  2632,  2224,  3245,  1447,  2632,    84,
    2250,  1155,  3091,  1991,  3360,  1325,  1021,   184,  3259,    42,
    2012,  3264,  1037,   315,  3266,   388,  2145,    48,  3083,  1932,
    3086,  1351,  3335,  3089,    88,   316,   317,   258,  1933,   925,
    2400,   257,  1053,   318,  2835,  1308,  1437,  2469,    88,  1032,
      42,  1351,  2205,  1444,  2149,  1062,  2817,   919,     5,     6,
    2013,     7,     8,   959,  1975,   919,     9,   976,   674,  3012,
     979,  2206,  2207,   926,  1976,    49,   923,  3016,  3448,  1231,
     920,  2204,  3449,    10,    11,    35,    36,  2184,   920,    88,
    2504,  2208,  2785, -2145,  3418,  2787,  2229,  1005,  2185,    42,
    3424,    12,  1326,  2370,    42,    88,    88,    88,  1156,    88,
    1090,    88,    88,   265, -2145,     2,     3,    88,    88,  2186,
     498,  3496,  2818,   499,  2051,  2382,  2187,  2024,  2334,  2231,
     273,  2335,  2997,    42,  2145,  2231,  1277,  1019,  1096,    42,
      42,  2253,  2254,  2255,  2256,  1327,   488,  2999,    42,   274,
    3092,  1977,  3093,  1478,  2488,    88,  2659, -1531,   277,  3336,
    1142,  2149,    42,   135,   136,    88,  3039,  3039,  3039,  3039,
    1496, -2145,  2819,  2820,  1413,   951,   196,   952,  3209,  1972,
     276,    83,  1974,    42,  1157,  1362,   278,    84,   197,    88,
      88,     5,     6,  1000,     7,     8,  2093,   281,    88,     9,
     282,  2096,  3372,  1976,   489,   490,   491,   492,   493,   494,
    1489, -2145,    42,  2094,    88,    88,    10,    11,    84,  2244,
     495,   496,   497, -2145, -2145,  2205,  1158, -2145,   283,  2015,
    3085,  1019,  3088,    42,    12,  2336,    42, -2145,  2337,   284,
    1911,  2306,   500,   285,  2206,  2207,  1270,  1270,  1855,   286,
      42,  2032,   287,    42,  1979,  1270, -2145, -2145,   501, -2145,
    2145,  2974,   502,    42,  2208,  1945,  1350,    84,    42,  2149,
    1980,   288,    84,  1951,  1131,  3310, -2145,  3131,   432,    42,
    1977, -2145, -2145,   433,  1145,   435,   346,   289,  2009,  1471,
     290,  2884,    14,  1159,  3046,  3046,  3046,  3046,   430,   431,
     503,    84,  2215,  3267,  2257,    13, -2145,  1020,  1020,    42,
    2004,  2403,  2411,   135,   136,   291,    84,  1984,    42,  2912,
     345,  1992,  2001,  1992,  1224,  1225,  2381,    83,   504,    42,
      84,  1414,   203,    88,  1021,  2118,   136,  1021,  1978,  2016,
    2019,   293,    15,  1028,   335,  3341,   505,  3344,  3345,  3346,
    3347,    84,   336,     2,     3,  3410,  3411,   204,  2710, -2145,
    2945,   498,  1218,   337,   499,  1021,    88,    42,    88,    88,
      88,  3453,  2902,  1219,  2904,  2905,   347,    88,    88,  1051,
      84,    88,   423,  1979,   423,    88,  2334,   338,  3466,  2335,
    2468,   369,  1167,  1060,  2745,  2149,  1171,  1065,    88,  1980,
    1175,   205,  1476,    17,    42,  1922,  2317,  1923,  3139,  1079,
     206,  1277,  3219,  2481,  2762,    42,   370, -2145,    84,  2547,
   -2145,    84,  2550,  2551,  2552,  2553,  1220,   372,   506,     5,
       6,    84,     7,     8,  3453,  3039,  3039,     9,   373,  3039,
    3470,  1221,  3472,    88,   374, -2145,  3170,    84,  2733,  3464,
    2007,  3466,    42,    42,    10,    11,    42,  2870,  1415,  1458,
    1459,  1460,  1461,  1482,  1416,  1417,  1418,  2219,  2090,  2220,
     423,   423,    12,  2871,  2872,   423,  1018,    88,   378,  2100,
    2101,   379,  2873,   500,  1419,   381,  -273,  2184,  2765,  1036,
     135,   136,   385,  2336,   507,   390,  2337,    84,  2185,   501,
    2511,    88,    42,   502,  2191,  2192,  2138,    16,  2139,  2140,
    2141,   408,  2038,  2039,  2040,   432,  2874,  1054,  2145,  2186,
     433,   434,   435,   399, -2145,  2875,  2187, -2145, -2145,  2057,
    1222, -2145, -2145,  1071,  1072,  2244,  2627,  2244,   409,  1078,
     391,   503,  1080,    13,   415,  1184,  2199,  2200,  1187, -2145,
    2638,  1190,  2639,  1483,  2876,   360,   361,   362,   354,  2921,
    2369,  2650,   359,  3046,  3046,   418,  2033,  3046,  2033,   504,
    1356,  1357,  1358,   419,  -273,  2132,  2133,  2347,  2348,  1438,
    1439,   420,  2955,  1442,  1443,  2078,  2981,   505,  1205,  1206,
    -273,   447,   400,  1420,  2952,   449,  1421,  2346,   450,  2877,
    3082,  3082,   461,  3082,  1422,  1145,  3082,  3155,   464,  3342,
     465,  3153,  3217,  3218,   467,  3342,   468,   469,  3351,  3352,
    3353,  3354,  2102,   470,   471,   520,  3263,   529,   392,  3263,
     531,   536,  2117,  -273,   537,   540,  3039,   541,   542,  1423,
    2561,  2878,  3039,  3039,   393,  3039,  3039,  3039,  3039,  1250,
    1251,  1252,  3277,  2149,  3039,   298,  1253,  1254,    42,   543,
     519,   546, -2145,   547,  2996,   557,   558,   561,   566,   506,
    1250,  1251,  1252,  -273,  1424,   576,   298,  1253,  1254,    42,
     401,   577,   580,  1277, -2145,   588,   583,   394,   339,   340,
     341,   342,   343,   606,  1425,  1426,   402,  2633,   589,   609,
    1255,  1101,  -273,  2960,   593,  1427,   452,   600,   611,   610,
    1428,  -273,  2968,  2969,   614,   639,  2172,   642,  3278,  1136,
     652,  1255,  2176,   655,  3278,   654,   656,   395,  3426,   657,
     658,  3429,  3430,  3431,  3432,   507,   664,  2789,  2668,   403,
     667,   675,   924,  2142,   929,    16,  2143,   931,  2144,  1429,
    1012,   932,  2801,   933,  1912,  3039,   396,   938,  3039,  3039,
    3039,  3039,  2226,  2825,  3046,   397,   948,   949,  2145,  2212,
    3046,  3046,   950,  3046,  3046,  3046,  3046,   956,  2146,   404,
     963,  1430,  3046,   961,  3279,   985,  3280,  2702,   965,   966,
    3279,   967,  3280,   990,   453,   992,   993,  2435,   994,   998,
     996,  3281,   999,  1001,   997,  2356,  1233,  3281,   405,  3282,
     454,  1172,  1234,  3283,  3480,  3282,  1235,   406,  1236,  3283,
    2147,  1237,  1239,  1240,  2148,  1238,  1020,  1241,  1242,  1927,
    1246,  1244,  1180,   423,   423,  1245,  2263,  1247,  3284,    88,
      88,  3039,  1913,  1248,  3284,  2258,  1249,  1020,  1283,  3039,
    1290,  1291,  1292,   455,  1012,  2915,  1295,  1296,  1914,  2168,
    1298,  1299,  1351,  1351,  2426,  2428,  2925,  2177,  1300,  2177,
    1301,  1351,  1012,  1302,  1905,  1303,  3082,  1307,  1311,  1312,
    1313,  1314,  1337,  3046,  1318,  1338,  3046,  3046,  3046,  3046,
    2534,   136,  2411,   456,  2438,    88,  1341,  1343,  1344,  1353,
    1369,  1915,  1349,  2149,  1373,  1374,  2216,  1952,  1953,  1954,
    1955,  3263,  1377,  1378,  1380, -2145,  1381,  1928,  1385,  1386,
    1388,  1397,   457,  1277,  1402,  1435,  1445,  1448,  1472,  1464,
    2562,   458,  1481,  1929,  1021,  1473,  1270,  1474,  1475,  1479,
    1484,  1916,  1270,  1270,  1351,  1485,  1493,  1495,  1270,  1270,
    1270,  1270,  1835,  1836,   586,  1282,  3183,  1843,  1284,  1021,
    1285,  1286,  1287,  1288,  1289,  2368,  1847,  1837,  1850,  3046,
    1917,  1851,  1351,  1838,  1853,  1899,  1930,  3046,  2535,  1918,
     651, -2145,  1852, -2145,  1907,  1992,  1956,  1957,  1958,  1959,
    1960,  1961,  3185,  1910,  2536,  1921,  2001,  1938, -2145,  1992,
    1939,  1940,  1941,  1942,  1943,  1944, -2145,  1963,    88,  1968,
   -2145,  3094,  1986,  2006,  2022,  2023,  1931,  1101,  2313,  2314,
    2315, -2145,  1308,  1136,  2025,  2319,  2028,   298,  1253,  1254,
      42,  2024,  1256,  1340,  2029, -2145,  2026,  2537,  2030,  2043,
    1455,  2049,  2056,  1136,  2058,  1932,  2062,  1257,  2060,  1040,
    1040,  2071,  2344,  1256,  1933,  2244,  2072,  2081,  2082,  2084,
    2351,  2352,  2086,   423,  1258,  2091,  2097,  2563,  1257,  2095,
    2277,  2113,  3023,  2106,  2115,    88,  2121,  2538,  2123,  2564,
    1260,  2120,    88,  1845,  2158,  1258,  2156,  2159,  1259,  2161,
    2167,  2379,  2628,    88,  2213,  2217,  3301,  2678,  2218,  2223,
    2221,  1260,  2237,  2245,  3309,  2259,  2539,  1936,  2269,  2271,
    2272,  2275,  2304,  2276,    88,  2540,  2404,  1496,  3314,  1270,
    1261,  2302,  1021,    88,  2307,  2305,  2309,  2308,  1936,  1954,
    1955,  2321,  1262,  2324,  2325,  2323,  2326,  2327,   423,   423,
    2329,  1261,  2330,  2331,  1040,  3154,  2345,  2332,  1844,  3359,
    2358,  2333,   423,  1262,  1195,  3161,  2360,    88,    88,    88,
    2361,  2365,  2367,    88, -2145,  1362,  2373,  2374,  2380,  2383,
    1012,  1351,  2384,  2387,  1263,  2393,  1012,  2401,  2407,  1208,
    2328,  2419,  2421,  2466,  2467,  2478,  2484,  2512,  2492,  2493,
     211,  2507,    88,  2510,  2521,  1263,  1012,  2532,  1020,  2350,
    2524,  2524,  2533,  2040,  2524,  2509,  1956,  1957,  1958,  1959,
    1960,  1961,  2545,  1264,    91,  3103,  3104,  3105,  1270,  3107,
    3108,  3109,  3110,  3111,  3112,  1265,  1270,  2546,  3115,  1270,
    1270,  1270,  1270,  2554,  1264,  2558,  1351,  1266,  1267,  2574,
    2559,  1270,  2579,  2389,  2577,  1268,  1265,  2581,  1269,  3404,
    2583,  2582,  2587,  2590,  2626,  2630,   319,  2610,  1266,  1267,
    2611,  2635,  2646,  2664,  2612,  1270,  1268,  2596,  2596,  1269,
    2666,  2596,  1270,  1101,  1101,  2669,  2613,   319,  3233,  3234,
    2614,  2615,  3268,  2675,  2825,  2676,  2679,   185,   214,    51,
      52,    53,    54,    55,    56,    57,  2680,  2681,  2624,  1271,
    2683,  2016,     1,    88,  2682,  2684,  2278, -2145,  2700,  2703,
    2701,  2704,  1992,  3409,  2705,  1207,  1992,    88,  2709,    88,
    2716,  2718,  2727,     2,     3,  2596,  2728,  2729,    88,  2344,
    2736,  2732,  2655,  2655,  2744,  2737,  2767,  3454,  3455,  3456,
    3457,  3458,  3459,  2746,  2768,  2769,  2770,  2775,  2786,  2783,
    2798,  2667,   214,  2803,  3476,  1956,  1957,  1958,  1959,  1960,
    1961,  2788,    88,  2790,  2279,  2791,  2792,  2793,  2804,   214,
    2826,   423,  2829,  2889,  2890,  2897,  2280,  1195,  2891,  2900,
    2903,  2906, -2090,  2916,  2922,  2923,  2926,  2281,  2928,  3303,
    2929,    88,  2936,  2940,  2944,  2947,  2956,  2959,  1277,     5,
       6,  2967,     7,     8,  1256,  2282,  2977,     9,  2138,  3002,
    2139,  2140,  2141,  2991,  3003,  2283,  3012,  2711,  2284,  1257,
    3019,  1947,  3057,  3061,    10,    11,  1012,  1012, -2145,  3071,
    3073,  2285,  3072,  3471,  3075,  1936,  3024,  3084,  2992,  3025,
    2994,  3087,    12,  3095,  3097,  3106,  2629,  3113,  3114,  3102,
    1104,  3121,  3026,  3124,  3271,  3120,  3125,  1976,  3126,  1105,
    3127,  2640,  2641,  2040,  2644,  1351,   916, -2145,  1106, -2145,
   -2145, -2145,  3128,  1107,  3129,  3130,  3136,  3143,  3145,  2286,
    2596,  3150,  2665,  3152,  3157,  2979,  3162,  3163,  2748,  2177,
    1270,  3164,  3028, -2145,  3179,  3165,   214,  3181,  3184,  3188,
     214,  3196,  1202,  2596,  3029,  1351,  3514,  3199,  3210,  2287,
    3220,  3221,  3222,    88,  2524,  3223,  3203,  1108,  3224,  2288,
    3229,   916,  3239,  3225,  3226,  1109,  3423,  3240,  3250,  3251,
    3257,  3389,  1195,  3275,  2887,  3293,  3294,  3296,  2699,   918,
    2289,  2194,  2195,  2290,  1270,  2291,  3030,  3297,  2211,  3298,
    3302,  3299,  1351,  3306,  1351,  2958,  3308,  1270,   651,  1270,
    3312,  3317,  3438,  3313,  3315,  3316,  3319,   651,   651,  3321,
    1270, -2145,  3325,  2292,  1948,  2596,    88,  2577, -2145,  3339,
    3337,  1110,  2293,   211,  3356,  3031,  2596,  3348,  3373,  1271,
    1271,  2596,  3383,  3384,   918,  3385,  3386,  3032,  1271,  3387,
    1992,  3390,  3402,  3408,  3415,  3403,  1111,  3425,  3460,  3033,
    3034,  3435,  3446,  1112,  3473,  1113,  2001,  3035,  1992,  3494,
    3036,  3479,    88,  3481,  3482,  1114,  2313,  2963,   319,  3483,
    3484,  3507,  3509,    88,  2759,  2918,  2760,  3231,  3232,  3233,
    3234,  3493,  1304,  2105,  2692,  2142,  2392,    74,  2143,   824,
    2144,  1115,    75,  2651,  2943,  2660,   538,   220,  2344,  1116,
    2946,   534,  2948,  3253,   991,   225,  3423,  2260,   365,   668,
    2145,   539,   643,  2261,   928,    88,   367,    88,  2964,    88,
    2146,   214,  3174,  1924,   955,   934,   565,   563,  3491,  3176,
     935,  2318,    88,   596,  2522,  2530,  1161,  1117,  1297,  1270,
      88,    88,  2642,  2353, -2145,  2131,  1903, -2145,  2990, -2145,
    3198,  2418,   423,  2135,   423,  3508,  1956,  1957,  1958,  1959,
    1960,  1961,  2147,  1118,    88,    88,  2148,  2708,  2649, -2145,
    1270,  3311,  2436,  2372,  2053,    69,   214,   159,    70, -2145,
    3169,  1195,  2596,  3288,    71,  2399,  1077,   528,  3037,  3037,
    3037,  3037,  2596,  2596,     1,  1317,  1232,  2402, -2145,  2155,
    2985,  1119,  2406,  3062,  3063,  2512,    88,  3276,  3374,  2045,
    1841,  3066,  1120,  2076,  2416,     2,     3,  3497,  1136,  2983,
    2927, -2145,  3134,  2932,   104, -2145,  2035,  3382,  1467,   105,
    2087,  3133,   615,  3116,  2021,  2636,  2882,  1863,  2270,  1270,
    1270,  2303,  2738,  3500,  3270,  2149,   214,  3436,  1040,  2766,
    1270,  1270,  3137,  1270,  2557,  2883,  1270,  2606,  1270,  2487,
     211,  3079,  1270,  3080,  3265,  2797,  3437,  2171,  3292,  2886,
    1002,  1003,  1004,  1006,   106,   107,    64,  3064,  1891,  1131,
    2836,  3216,   108,  2837,  3018,  2239,  3269,   651,  1034,  2238,
    3417,     5,     6,  2163,     7,     8,  1858,  3215,  3340,     9,
    2129,    88,  3357,  3349, -2145,  2625,     0,  2052,     0,     0,
     676,  1121,  1122,  1123,    88,     0,    10,    11,     0,  3300,
       0,     0,     0,  1056,  1124,     0,  2596,  3140,  2596,  1061,
       0,  1063,     0,     0,    12,  1070,     0,     0,  1070,     0,
    1864,  1070,     0,     0,     0,     0,     0,     0,  1865,     0,
       0,  1082,    88,     0,  1866,  1992,  1867,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,  1868,     0,     0,
    1129,  1012,  2655,     0,     0,  3171,  2655,  1006,  1140,  1143,
     423,     0,     0,  1163,     0,     0,     0,   423,     0,    88,
       0,  1173,     0,     0,     0,  1869,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,  1197,     0,     0,
       0,  1870,     0,     0,     0,     0,  1871,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1125,  1872,  2909,
       0,     0,     0,     0,     0,  1873,     0,     0,     0,  3200,
       0,     0,     0,     0,     0,     0,  2596,     0,     0,     0,
       0,     0,     0,     0,     0,  2748,     0,  3037,  3037,     0,
       0,  3037,     0,     0,     0,     0,     0,     0,     0,  2688,
    2689,     0,  3227,     0,     0,     0,     0,     0,     0,     0,
    2698,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2596,     0,  2168,     0,     0,
       0,     0,     0,     0,     0,     0,  2712,  2713,  2714,  2715,
       0,     0,  1351,     0,  2720,  2721,  2722,  2723,     0,     0,
    1021,  2725,     0,  1021,  3175,     0,  1270,     0,     0,  1270,
       0,  1270,     0,  2596,     0,     0,   109,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3414,
       0,     0,     0,     0,  3191,     0,    88,     0,     0,     0,
       0,     0,     0,   110,  3038,  3038,  3038,  3038,     0,     0,
       0,     0,     0,     0,     0,     0,  2839,  2840,     0,  2841,
    2842,  2843,     0,     0,     0,     0,     0,     0,     0,     0,
    1874,     0,     0,   423,     0,     0,    88,  1875,     0,     0,
       0,     0,     0,  2773,  2774,     0,     0,     0,     0,     0,
    2778,  2779,     0,  2439,  2440,  2441,  2442,  2443,  2444,  1876,
       0,     0,     0,  1195,  1877,     0,     0,     0,     0,     0,
    1197,     0,     0,     0,   111,     0,     0,     0,     0,    88,
       0,     0,     0,     0,  1363,  1270,     0,   211,  2596,     0,
       0,     0,     0,     0,     0,     0,  1021,     0,  3037,     0,
       0,     0,     0,     0,  3037,  3037,     0,  3037,  3037,  3037,
    3037,     0,  2445,  2596,     0,  2596,  3037,     0,  1270,  2844,
      88,     0,     0,     0,     0,  1391,  3365,  2845,     0,  1250,
    1251,  1252,     0,     0,     0,   298,  1253,  1254,    42,     0,
       0,  1409,  1409,  1409,     0,  1409,     0,  1409,  1409,     0,
       0,    88,     0,    91,    91,     0,    88,     0,    88,  1271,
       0,  2846,     0,     0,     0,  1271,  1271,   112,   651,     0,
    2847,  1271,  1271,  1271,  1271,     0,  2934,  2935,    88,  3304,
    1255,     0,     0,     0,     0,  2942,     0,     0,     0,     0,
       0,  1143,     0,     0,     0,    88,     0,     0,     0,  2848,
    2849,  1491,     0,     0,     0,  3200,     0,     0,     0,     0,
       0,  3326,     0,  1270,  2970,  2971,     0,  3037,     0,     0,
    3037,  3037,  3037,  3037,  3433,  1197,  1363,     0,     0,     0,
       0,     0,     0,     0,  1848,   485,   486,   487,  2168,     0,
       0,  2993,     0,  2995,  2850,  1021,     0,   113,     0,  1270,
    1856,  1856,     0,     0,   488,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    88,    88,    88,
      88,    88,    88,  3038,  3038,     0,     0,  3038,     0,  3465,
       0,     0,     0,     0,     0,     0,  2851,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3067,  3068,     0,  3037,  3069,  3070,  1020,     0,     0,     0,
       0,  3037,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,     0,     0,     0,     0,     0,  3262,     0,     0,  3262,
       0,     0,  1271,  2852,     0,     0,  2446,     0,     0,     0,
       0,     0,  2561,  1270,     0,     0,     0,     0,     0,  2447,
       0,  1250,  1251,  1252,     0,     0,     0,   298,  1253,  1254,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,     0,
       0,     0,     0,  3123,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,    91,  1143,  1070,     0,     0,     0,
    2562,     0,  1255,  2044,  1082,     0,     0,  1143,     0,  3463,
       0,  2054,     0,     0,  2448,     0,     0,     0,     0,     0,
       0,  2449,     0,     0,  1197,     0,     0,     0,     0,     0,
       0,  1271,     0,     0,     0,     0,     0,     0,     0,  1271,
       0,     0,  1271,  1271,  1271,  1271,     0,     0,     0,     0,
       0,  3168,     0,     0,  1271,  3173,     0,     0,     0,   498,
    2450,     0,   499,     0,  3038,     0,     0,     0,  3178,    91,
    3038,  3038,     0,  3038,  3038,  3038,  3038,     0,  1271,     0,
       0,     0,  3038,     0,  2451,  1271,     0,  3189,     0,     0,
       0,     0,     0,     0,  2452,  2453,     0,     0,     0,  3367,
    2454,  3505,  1256,  2098,     0,     0,     0, -2146,     0,     0,
    2455,     0,     0,     0,     0,     0,     0,  1257,     0,     0,
       0,     0, -2146,     0, -2146, -2146, -2146,  2125,  1020,     0,
       0,     0,  2456,     0,  1258,  2457,  2458,  2563,     0,     0,
       0,  2459,     0,     0,     0,     0,     0,     0,     0,  2564,
    1260, -2146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2853,  2854,  2855,  2856,  2857,  2858,  2859,  2860,  2861,
    2862,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2146,   500,     0,  3038,     0,     0,  3038,  3038,  3038,  3038,
    1261,     0,     0,     0,     0,     0,     0,   501,  2460,  3021,
    3022,   502,  1262,     0,     0,   298,  1253,  1254,    42,  2461,
       0,  3262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2562,     0,     0,     0,     0,     0,     0,   503,
       0,     0,     0,     0,  1263,     0,     0,     0,     0,     0,
    3023,     0, -2146,     0,     0, -2146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,  3038,
       0,     0,     0,     0,     0,     0,     0,  3038,     0,     0,
   -2146,     0,     0,  1264,     0,   505,     0,     0, -2146,     0,
   -2146,     0,     0,     0,     0,  1265,     0,     0,     0, -2146,
       0,     0,     0,  1271,     0, -2146,  3324,  1266,  1267,  3327,
       0,     0,     0, -2146,     0,  1268,     0, -2146,  1269,     0,
       0,     0,     0, -2146,     0,     0,   319, -2146, -2146, -2146,
   -2146,     0,     0,     0,  1256,     0,     0,     0,     0,     0,
       0,     0, -2146,     0,     0,     0,     0,     0,     0,  1257,
       0,     0,     0,     0,     0,     0,     0,  1271,     0, -2146,
       0,     0, -2146,     0, -2146,     0,  1258,   506,     0,  2563,
    1271, -2146,  1271,     0,     0,     0,  1020,     0,     0,     0,
       0,  2564,  1260,  1271, -2146,     0,     0,     0,     0,     0,
     603,   472,   473,   474, -2146,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,     0,     0,
       0,     0,     0, -2146, -2146,     0,     0,     0,     0,     0,
       0,     0,  1261,     0,   488,     0,  1271,     0, -2146,     0,
       0,     0,     0,   507,  1262,     0, -2146,  3412,     0,     0,
   -2146,     0,     0,     0,     0,     0,     0,     0,     0, -2146,
   -2146, -2146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2154,  1197,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1263,     0,     0,     0,
       0,     0,   489,   490,   491,   492,   493,   494,     0,  3439,
    3440,     0,  3442,     0,  3444,  3445,     0,     0,   495,   496,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1271,     0,     0,  1264,     0,     0,     0, -2146,
       0,  2198,     0,     0,     0,     0,     0,  1265,     0,     0,
   -2146,     0,     0,     0,     0,     0,     0,     0,     0,  1266,
    1267,     0,     0,  1271,     0,     0,     0,  1268,     0,     0,
    1269,     0,     0,     0,     0,  3486,     0,  3487,   319,     0,
       0,  1271,  1271,  1271,  1271,     0,     0,     0,     0,     0,
   -2146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1256,     0,     0,     0,     0,     0,     0,  3499,
       0,     0,     0,     0,     0,     0,     0,  1257,     0,     0,
       0,     0,  3502,  3503,     0,     0,  3504,     0,     0,  3506,
       0,     0,  1271,  1271,  3024,     0,     0,  3025,     0,     0,
       0,     0,     0,  1271,  1271,     0,  1271,     0,     0,  1271,
    3026,  1271, -2146,     0,  1143,  1271,     0,     0,     0,   498,
       0,     0,   499,  1413,     0,     0,     0,     0,     0,     0,
    1040,  1040,  1040,     0,  1040,  1040,  1040,  1040,  1040,  1040,
       0,     0,     0,  1040,     0,     0,     0,     0, -2146,  3027,
    3028,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3029,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2364,     0,     0,     0,     0,     0,     0,  2371,     0,
       0,     0,     0,     0, -2146,     0,     0,     0,     0,  1143,
       0,     0,     0,     0,  3030,     0,     0,     0, -2146, -2146,
   -2146, -2146, -2146, -2146, -2146,   487, -2146, -2146,     0,     0,
     185,     0,     0,     0,     0,     0,     0,     0,     0,  2413,
       0,     0,   488, -2146,     0,     0,     0,     0,     0,     0,
       0,   500,     0,  3031,     0,     0,     0,     0,     0,     0,
       0,  1195,     0,     0,     0,  3032,     0,   501,     0,     0,
       0,   502,     0,  1143,  2470,  1143,     0,  3033,  3034,  1006,
       0,     0,     0,     0,     0,  3035,     0,     0,  3036,     0,
    1414,     0,     0,     0,     0,     0,   319,     0,     0,     0,
     489,   490,   491,   492,   493,   494,     0,     0,  2516,   503,
       0,     0,     0,     0,     0,     0,   495,   496,   497,     0,
    1271,  1271,     0,     0,  1271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,  2674,   472,   473,
     474,     0,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,     0,
       0,     0,     0,  1271,     0,     0,  1271,     0,     0,  1271,
       0,   488,  1271,     0,  1271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1415,     0,  1143,
     214,     0,     0,  1416,  1417,  1418,     0,     0,     0,     0,
       0,     0,     0,  1143,     0,  1143,     0,   506,     0,     0,
       0,     0,     0,  1419,  1143,     0,     0,     0,     0,   489,
     490,   491,   492,   493,   494,     0,     0,   498,     0,     0,
     499,     0,     0,     0,     0,   495,   496,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2673,   472,
     473,   474,     0,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,  2697,  1271,     0,
       0,     0,   488,     0,     0,     0,     0,     0,     0,     0,
       0,  1271,     0,     0,     0,     0,     0,  1271,  1271,     0,
    1271,  1271,  1271,  1271,     0,     0,     0,     0,     0,  1271,
       0,  1271,     0,     0,  2073,     0,     0,     0,     0,     0,
       0,     0,  1420,     0,     0,  1421,  1271,     0,     0,     0,
       0,     0,     0,  1422,     0,     0,     0,     0,     0,     0,
     489,   490,   491,   492,   493,   494,     0,     0,     0,   500,
       0,     0,     0,     0,     0,     0,   495,   496,   497,     0,
       0,     0,     0,     0,     0,   501,     0,     0,  1423,   502,
       0,     0,     0,     0,     0,     0,   498,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,     0,  1195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2771,
       0,     0,     0,  1424,     0,     0,  1271,   503,     0,     0,
    1271,     0,     0,  1271,  1271,  1271,  1271,     0,     0,     0,
       0,     0,     0,  1425,  1426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1427,   504,     0,     0,  1271,  1428,
       0,     0,  1271,     0,     0,     0,     0,     0,   187,   188,
       0,     0,     0,   505,     0,     0,   189,    42,     0,   472,
     473,   474,  1143,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,     0,  1429,     0,
     226,     0,   227,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,   190,     0,  1271,   498,   500,     0,
     499,     0,     0,     0,  1271,     0,   191,     0,  1143,     0,
    1430,     0,     0,     0,   501,     0,     0,     0,   502,  1143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   229,   192,   506,     0,     0,     0,     0,
       0,     0,   230,     0,     0,     0,  1271,     0,     0,     0,
     489,   490,   491,   492,   493,   494,   503,     0,     0,     0,
       0,  2961,     0,  1034,     0,  2965,   495,   496,   497,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2976,     0,
       0,  1195,     0,   214,   504,     0,  2984,  2413,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,   505,     0,     0,     0,     0,     0,     0,     0,
    2998,  3000,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,     0,     0,    84,     0,   193,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,   502,
     592,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,     0,  3065,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   488,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
       0,   472,   473,   474,   506,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   482,   483,
     484,   485,   486,   487,     0,   504,     0,   498,     0,     0,
     499,     0,     0,   231,   488,     0,     0,     0,     0,     0,
     488,     0,     0,   505,   194,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,     0,     0,     0,  3117,     0,     0,
     507,     0,   232,     0,     0,     0,     0,   195,     0,     0,
    3132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   489,   490,   491,   492,   493,   494,   489,   490,
     491,   492,   493,   494,     0,     0,     0,   234,   495,   496,
     497,     0,   196,     0,   495,   496,   497,     1,  1143,     0,
       0,     0,     0,     0,   197,   506,     0,     0,  1143,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     2,     3,
     214,     0,   236,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,   237,     0,  2413,     0,     0,     0,     0,
       0,     0,   198,     0,  1197,   501,     0,     4,     0,   502,
     602,   238,     0,     0,     0,     0,     0,     0,   199,     0,
       0,   239,     0,     0,     0,     0,   200,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,   240,     0,   201,
       0,     0,   498,     0,     0,   499,     0,   503,     0,     0,
       0,     0,     0,     0,     5,     6,     0,     7,     8,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   241,     0,    10,
      11,     0,     0,   202,     0,     0,     0,     0,     0,   498,
       0,     0,   499,   505,     0,   498,     0,    12,   499,     0,
     242,     0,     0,     0,     0,     0,     0,     0,   203,     0,
       0,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,   244,     0,     0,   245,     0,     0,     0,     0,
       0,     0,     0,   204,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,     0,   247,
       0,   248,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3117,     0,   500,     0,     0,     0,    13,     0,
     249,     0,     0,     0,     0,   506,     0,   205,     0,     0,
     501,     0,     0,     0,   502,     0,   206,     0,   250,     0,
       0,  1508,  1509,  1510,  1511,  1512,  1513,     0,  1514,  1515,
    1516,     0,  1143,     0,  1517,  1518,  1519,  1520,  1521,  1522,
       0,   500,     0,     0,     0,     0,     0,   500,     0,  1523,
       0,     0,   503,     0,     0,     0,     0,   501,     0,     0,
     251,   502,   612,   501,     0,  1524,     0,   502,     0,     0,
       0,   507,     0,     0,     0,  2413,     0,     0,     0,     0,
     504,     0,     0,  1525,     0,     0,     0,     0,     0,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,   505,   503,
       0,     0,     0,     0,     0,   503,     0,     0,     0,     0,
    1527,     0,  1528,     0,     0,     0,  2413,     0,    14,     0,
    1529,     0,     0,     0,     0,  1530,  1531,   504,     0,  1532,
    1533,  1534,  1535,   504,     0,  1536,  1537,     0,     0,     0,
       0,     0,     0,     0,     0,   505,     0,  3117,     0,     0,
       0,   505,  3377,     0,  3379,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,     0,  1143,  1538,     0,     0,     0,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1197,     0,     0,     0,     0,     0,   214,  1539,     0,
      16,     0,     0,     0,  1540,     0,     0,     0,     0,     0,
    2128,  1541,     0,  1542,     0,     0,     0,     0,     0,  1543,
       0,     0,     0,     0,     0,     0,     0,   506,     0,    17,
       0,     0,     0,   506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1544,     0,   507,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1409,  1409,  1409,  1409,  1409,  1409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,  1546,     0,     0,     0,   507,
       0,  1547,     0,     0,     0,     0,     0,     0,     0,     0,
    1548,  1549,     0,     0,     0,     0,     0,  1550,     0,     0,
    1551,  1552,     0,     0,     0,  1553,     0,     0,     0,     0,
       0,  1554,  1555,     0,     0,     0,     0,     0,  1556,  1557,
    1558,  1559,  1560,  1561,     0,     0,     0,  1562,     0,     0,
       0,  1563,     0,  1564,     0,     0,     0,     0,     0,     0,
    1565,  1566,  1567,  1568,     0,  1569,  1570,     0,     0,     0,
    1571,  1572,     0,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
    1580,     0,     0,     0,  1197,     0,  1581,  1582,  1583,     0,
    1584,  1585,     0,     0,     0,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,     0,  1595,     0,     0,     0,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,
    1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,     0,  1634,  1635,
       0,     0,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,     0,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,     0,     0,
    1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,     0,
    1670,  1671,  1672,  1673,     0,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1709,     0,  1710,  1711,  1712,  1713,  1714,  1715,     0,     0,
    1716,  1717,     0,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,
       0,     0,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,     0,     0,     0,     0,  1807,  1808,
    1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1818,
       0,     0,     0,     0,     0,     0,     0,  1819,     0,     0,
       0,     0,  1820,     0,     0,     0,  1821,     0,   161,  1822,
    1823,  1824,  1825,     0,     0,  1826,  1827,     0,  1828,  1829,
    1830,  1508,  1509,  1510,  1511,  1512,  1513,     0,  1514,  1515,
    1516,     0,     0,     0,  1517,  1518,  1519,  1520,  1521,  1522,
       0,     0,     0,     0,     0,     0,     0,   162,     0,  1523,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1524,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1525,     0,     0,     0,     0,     0,     0,
       0,     0,  1526,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,     0,     0,
    1527,     0,  1528,     0,     0,     0,     0,   165,     0,     0,
    1529,     0,     0,     0,     0,  1530,  1531,     0,   166,  1532,
    1533,  1534,  1535,     0,     0,  1536,  1537,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,  1538,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,     0,  1540,     0,     0,     0,     0,     0,
       0,  1541,   170,  1542,     0,     0,     0,     0,     0,  1543,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,     0,     0,  1544,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,   173,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   175,  1545,     0,   176,     0,   177,     0,     0,     0,
       0,     0,     0,     0,     0,  1546,     0,     0,     0,     0,
       0,  1547,     0,     0,     0,   178,     0,     0,     0,     0,
    1548,  1549,     0,     0,     0,     0,     0,  1550,     0,     0,
    1551,  1552,     0,   179,     0,  1553,     0,     0,     0,     0,
       0,  1554,  1555,     0,     0,     0,     0,     0,  1556,  1557,
    1558,  1559,  1560,  1561,     0,     0,     0,  1562,     0,     0,
       0,  1563,     0,  1564,     0,     0,     0,     0,     0,     0,
    1565,  1566,  1567,  1568,     0,  1569,  1570,     0,     0,     0,
    1571,  1572,     0,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
    1580,     0,     0,     0,     0,     0,  1581,  1582,  1583,     0,
    1584,  1585,     0,     0,     0,  1586,  1587,  1588,  1589,  1590,
    1591,  1592,  1593,  1594,     0,  1595,     0,     0,     0,  1596,
    1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,  1605,  1606,
    1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,
    1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,
    1627,  1628,  1629,  1630,  1631,  1632,  1633,     0,  1634,  1635,
       0,     0,  1636,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,     0,  1646,  1647,  1648,  1649,  1650,  1651,  1652,
    1653,  1654,  1655,  1656,  1657,  1658,  1659,  1660,     0,     0,
    1661,  1662,  1663,  1664,  1665,  1666,  1667,  1668,  1669,     0,
    1670,  1671,  1672,  1673,     0,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1687,  1688,
    1689,  1690,  1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,
    1699,  1700,  1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,
    1709,     0,  1710,  1711,  1712,  1713,  1714,  1715,     0,     0,
    1716,  1717,     0,  1718,  1719,  1720,  1721,  1722,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  1733,  1734,
    1735,  1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,
       0,     0,  1745,  1746,  1747,  1748,  1749,  1750,  1751,  1752,
    1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,
    1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,
    1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,
    1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,     0,     0,     0,     0,  1807,  1808,
    1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1818,
       0,     0,     0,     0,     0,     0,     0,  1819,     0,     0,
       0,     0,  1820,     0,     0,     0,  1821,     0,     0,  1822,
    1823,  1824,  1825,     0,     0,  1826,  1827,     1,  1828,  1829,
    1830,     0,   678,   679,   680,     0,     0,     0,     0,     0,
     681,     0,     0,     0,     0,     0,     0,   682,     2,     3,
       0,     0,     0,     0,     0,     0,   683,     0,   574,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   684,   685,
       0,   686,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   687,     0,     0,     0,     0,
       0,     0,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   689,   690,   691,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   692,
       0,   693,   694,   695,     5,     6,   696,     7,     8,   697,
       0,   698,     9,   699,   700,     0,     0,     0,     0,     0,
     701,     0,     0,   702,     0,   703,   704,   705,     0,    10,
      11,     0,     0,     0,     0,   706,     0,   707,   708,     0,
     709,     0,   710,   711,     0,     0,   712,    12,     0,     0,
     713,   714,   715,     0,   716,   717,     0,     0,     0,   718,
     719,   720,     0,   721,     0,     0,     0,   722,     0,   723,
     724,     0,     0,     0,     0,   725,     0,     0,     0,   726,
       0,     0,   727,     0,   728,     0,   729,     0,   730,     0,
     731,   732,     0,   733,   734,   735,     0,     0,     0,   736,
       0,   737,   738,     0,   739,     0,     0,     0,     0,     0,
       0,     0,   740,   741,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   742,     0,     0,   743,   744,
       0,     0,   745,   746,     0,     0,   747,   748,     0,     0,
       0,     0,     0,     0,     0,   749,   750,   751,     0,   752,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   753,
     754,   755,     0,   756,     0,     0,     0,   757,   758,     0,
       0,     0,   759,     0,     0,     0,     0,     0,     0,     0,
     760,     0,     0,     0,     0,     0,     0,     0,   761,   762,
     763,     0,     0,     0,     0,     0,   764,   765,   161,     0,
       0,     0,   766,     0,     0,   767,     0,     0,     0,   768,
     769,     0,     0,     0,     0,     0,     0,   472,   473,   474,
     770,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,     0,   162,   771,     0,
       0,     0,     0,     0,     0,     0,   772,     0,     0,     0,
     488,     0,   773,     0,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,   774,     0,   775,   776,     0,     0,     0,
       0,     0,     0,     0,   777,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,   166,     0,
       0,     0,     0,     0,   495,   496,   497,     0,     0,     0,
       0,     0,     0,   778,     0,     0,   167,     0,     0,     0,
       0,     0,     0,     0,   779,     0,   168,     0,     0,     0,
       0,   780,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   781,   782,     0,     0,     0,
     783,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   784,     0,     0,     0,     0,     0,   785,   786,
     787,   788,   170,     0,     0,   789,     0,     0,     0,   790,
       0,     0,     0,     0,     0,     0,   791,   792,     0,     0,
       0,     0,     0,     0,     0,   171,     0,     0,   793,     0,
     794,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,   795,     0,   796,     0,     0,   797,   173,     0,     0,
     174,     0,   798,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   498,     0,     0,   499,     0,
       0,   175,     0,     0,   176,     0,   177,     0,   799,     0,
       0,   800,     0,     0,     0,     0,   801,     0,     0,   802,
     803,     0,     0,     0,     0,   178,     0,     0,     0,     0,
       0,     0,     0,     0,   804,     0,     0,     0,     0,     0,
       0,   805,     0,   179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   806,   807,   808,   809,   810,   811,
     812,     0,     0,   813,     0,   814,     0,   815,   472,   473,
     474,     0,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   488,     0,     0,     0,     0,     0,   500,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,     0,     0,     0,   502,   962,     0,
       0,     0,     0,     0,     0,   472,   473,   474,     0,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,     0,     0,     0,     0,     0,     0,     0,   489,
     490,   491,   492,   493,   494,   503,     0,     0,   488,     0,
       0,     0,     0,     0,     0,   495,   496,   497,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,     0,   472,   473,   474,     0,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   506,     0,     0,   472,   473,   474,     0,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,     0,     0,     0,   498,     0,     0,   499,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   488,
       0,     0,     0,     0,     0,     0,     0,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,     0,     0,     0,   507,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   498,     0,     0,   499,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,     0,   472,   473,   474,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   500,     0,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,     0,     0,     0,   502,   968,
     472,   473,   474,     0,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   488,   498,     0,   503,   499,   489,   490,
     491,   492,   493,   494,     0,   500,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,     0,     0,     0,
       0,   501,     0,     0,   504,   502,   969,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,   498,     0,     0,   499,     0,     0,
       0,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,     0,     0,   503,     0,     0,     0,   495,   496,   497,
     473,   474,     0,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,     0,     0,     0,
       0,   504,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,   501,     0,     0,     0,   502,   970,   472,   473,
     474,     0,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   498,     0,     0,   499,     0,
     489,   490,   491,   492,   493,   494,   500,     0,     0,     0,
       0,   488,     0,     0,   503,     0,   495,   496,   497,     0,
       0,     0,   501,     0,     0,     0,   502,   971,     0,     0,
     507,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,     0,     0,     0,   498,     0,
       0,   499,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,   503,     0,     0,     0,     0,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,     0,     0,
       0,     0,   504,     0,     0,     0,     0,   507,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,     0,   500,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   501,     0,     0,     0,   502,     0,   472,
     473,   474,   506,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,   498,     0,     0,
     499,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     500,     0,   488,     0,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   501,     0,   973,     0,
     502,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,     0,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,     0,     0,     0,   498,     0,   503,   499,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
       0,   974,     0,     0,     0,     0,   495,   496,   497,     0,
       0,     0,     0,     0,     0,     0,   504,     0,   507,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   505,   295,     0,     0,     0,   500,
       0,     0,     0,     0,   296,   297,     0,     0,     0,     0,
     298,   299,   300,    42,     0,   501,     0,     0,     0,   502,
       0,     0,     0,   506,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     190,     0,     0,   488,     0,   301,     0,   503,     0,     0,
       0,     0,   191,     0,     0,     0,     0,     0,   500,     0,
       0,     0,     0,     0,     0,     0,   506,     0,     0,     0,
       0,     0,     0,     0,   501,   504,     0,     0,   502,   507,
     192,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   505,     0,     0,     0,   498,     0,     0,
     499,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   503,   495,   496,   497,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   977,
       0,     0,   507,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   505,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,   193,     0,   506,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   500,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,     0,     0,     0,   502,
       0,   507,     0,     0,   506,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   498,     0,
       0,   499,   489,   490,   491,   492,   493,   494,     0,     0,
     194,     0,     0,     0,     0,   302,     0,   503,   495,   496,
     497,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   195,   295,   504,     0,     0,     0,     0,
     507,     0,     0,   296,   297,     0,     0,     0,     0,   298,
     299,   300,    42,   505,     0,     0,   295,     0,     0,     0,
       0,     0,     0,     0,     0,   296,   297,     0,   196,     0,
       0,   298,   299,   300,    42,     0,     0,     0,     0,     0,
     197,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,   301,     0,     0,     0,     0,   303,
       0,   191,     0,     0,   304,     0,     0,   305,     0,     0,
     500,   190,     0,     0,     0,     0,   301,     0,   198,     0,
       0,     0,     0,   191,   306,     0,   501,     0,     0,   192,
     502,     0,     0,     0,   199,   506,     0,     0,     0,   307,
       0,     0,   308,     0,     0,   309,     0,     0,     0,   498,
       0,   192,   499,     0,   310,   201,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,     0,     0,
       0,     0,     0,     0,  1359,   311,   504,     0,     0,   202,
       0,   507,     0,     0,   488,     0,     0,   312,     0,     0,
       0,     0,     0,     0,   505,     0,     0,     0,   313,     0,
      84,     0,   193,     0,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,     0,   193,     0,     0,     0,     0,   314,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   491,   492,   493,   494,     0,     0,
       0,   500,     0,     0,     0,     0,     0,     0,   495,   496,
     497,     0,     0,     0,     0,     0,     0,   501,     0,     0,
       0,   502,     0,   205,     0,     0,   506,     0,     0,   295,
     315,     0,   206,     0,     0,     0,     0,     0,   296,   297,
       0,     0,   316,   317,   298,   299,   300,    42,     0,   194,
     318,     0,     0,     0,   302,     0,     0,     0,     0,   503,
       0,   319,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   972,     0,     0,     0,   302,     0,     0,     0,
       0,     0,   195,     0,   190,     0,     0,   504,     0,   301,
       0,     0,   507,     0,     0,     0,   191,     0,     0,     0,
       0,     0,     0,     0,   195,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,     0,   197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,   303,   498,
       0,   197,   499,   304,     0,     0,   305,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,     0,     0,
     303,     0,     0,   306,     0,   304,     0,     0,   305,     0,
       0,     0,     0,   199,     0,     0,     0,   506,   307,   198,
       0,   308,     0,     0,   309,   306,     0,     0,     0,     0,
    1250,  1251,  1252,   310,   201,   199,   298,  1253,  1254,    42,
     307,     0,     0,   308,     0,    84,   309,   193,     0,     0,
       0,     0,     0,     0,     0,   310,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   311,     0,     0,     0,   202,     0,
       0,  1255,     0,   507,     0,     0,   312,     0,     0,     0,
       0,     0,     0,     0,     0,  2980,   311,   313,     0,  2643,
     202,   500,     0,   203,     0,     0,     0,     0,   312,     0,
       0,     0,     0,     0,     0,     0,     0,   501,     0,   313,
       0,   502,     0,     0,     0,   203,     0,     0,   314,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,     0,     0,     0,     0,   302,
     314,     0,     0,     0,     0,     0,     0,     0,     0,   503,
    1250,  1251,  1252,     0,     0,     0,   298,  1253,  1254,    42,
       0,     0,   205,     0,     0,     0,     0,   195,     0,   315,
       0,   206,     0,     0,     0,     0,     0,   504,     0,     0,
       0,   316,   317,     0,   205,     0,     0,     0,     0,   318,
       0,   315,     0,   206,     0,   505,     0,  1020,     0,     0,
     319,  1255,   196,   316,   317,     0,     0,     0,     0,     0,
       0,   318,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,   319,   479,   480,   481,   482,   483,   484,   485,
     486,   487,     0,   303,     0,     0,     0,     0,   304,     0,
       0,   305,     0,     0,     0,     0,     0,     0,   488,     0,
       0,     0,   198,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
       0,     0,     0,   307,     0,     0,   308,   506,     0,   309,
     480,   481,   482,   483,   484,   485,   486,   487,   310,   201,
     481,   482,   483,   484,   485,   486,   487,     0,     0,     0,
       0,     0,     0,     0,   488,     0,   489,   490,   491,   492,
     493,   494,     0,   488,   483,   484,   485,   486,   487,     0,
       0,     0,   495,   496,   497,     0,     0,  1020,     0,   311,
       0,     0,     0,   202,     0,   488,     0,     0,     0,     0,
       0,   312,     0,   507,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     0,   203,     0,
       0,     0,   489,   490,   491,   492,   493,   494,     0,     0,
       0,   489,   490,   491,   492,   493,   494,     0,   495,   496,
     497,     0,     0,   314,     0,     0,     0,   495,   496,   497,
       0,     0,     0,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,  1256,     0,     0,     0,     0,     0,   495,
     496,   497,     0,  1250,  1251,  1252,     0,     0,  1257,   298,
    1253,  1254,    42,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,   315,  1258,   206,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,   316,   317,     0,  3021,
    3022,  1260,     0,     0,   318,   298,  1253,  1254,    42,     0,
       0,     0,     0,   498,  1255,   319,   499,     0,     0,     0,
    3021,  3022,     0,     0,     0,     0,   298,  1253,  1254,    42,
       0,  1252,     0,     0,     0,   298,  1253,  1254,    42,     0,
    2408,  1261,     0,     0,     0,     0,     0,     0,     0,     0,
    3023,     0,     0,  1262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   498,
       0,  3023,   499,     0,     0,     0,     0,     0,   498,     0,
    1255,   499,     0,  1256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1263,     0,     0,  1257,     0,
     498,     0,     0,   499,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1258,     0,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1260,     0,     0,  1264,   500,     0,     0,     0,     0,
    1020,     0,     0,     0,     0,     0,  1265,     0,     0,     0,
       0,   501,     0,     0,     0,   502,     0,     0,  1266,  1267,
       0,     0,     0,     0,     0,     0,  1268,     0,     0,  1269,
    3420,  1261,     0,     0,     0,     0,  1020,   319,     0,     0,
       0,     0,     0,  1262,     0,     0,     0,     0,     0,     0,
       0,   500,     0,   503,     0,     0,     0,  1020,     0,     0,
     500,     0,     0,     0,     0,     0,  1020,   501,     0,     0,
       0,   502,     0,     0,     0,     0,   501,     0,     0,     0,
     502,   504,   500,     0,     0,  1263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,   505,
       0,     0,   502,     0,     0,     0,     0,     0,     0,   503,
       0,  2439,  2440,  2441,  2442,  2443,  2444,     0,   503,     0,
       0,     0,     0,     0,  1264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1265,   504,     0,     0,
     503,     0,     0,     0,     0,     0,   504,     0,  1266,  1267,
       0,     0,     0,     0,     0,   505,  1268,     0,     0,  1269,
       0,     0,     0,     0,   505,     0,     0,   319,   504,     0,
    2445,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   506,  1258,     0,
       0,  1259,  1256,     0,     0,     0,   506,   507,     0,     0,
       0,     0,     0,     0,  1260,     0,     0,  1257,     0,     0,
       0,     0,     0,  1256,     0,     0,     0,     0,   506,     0,
       0,     0,  1256,     0,  3024,  3391,     0,  3025,  1257,     0,
       0,     0,     0,     0,     0,     0,     0,  1257,     0,     0,
    3026,     0,     0,     0,  1261,  3024,     0,     0,  3025,     0,
       0,     0,     0,   507,  1258,     0,  1262,  1259,     0,     0,
       0,  3026,   507,     0,     0,     0,     0,  1936,     0,     0,
    1260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3028,  3392,     0,     0,   507,     0,     0,     0,     0,     0,
       0,     0,  3029,     0,     0,     0,     0,     0,  1263,     0,
       0,  3028,     0,     0,     0,     0,  3393,     0,     0,     0,
    1261,     0,     0,  3029,     0,  3394,     0,     0,     0,     0,
       0,     0,  1262,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3030,     0,     0,  1264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1265,
       0,  3395,     0,     0,  2446,  3030,     0,     0,     0,  3396,
       0,  1266,  1267,     0,  1263,     0,     0,  2447,     0,  1268,
       0,     0,  1269,  3031,     0,     0,     0,     0,     0,     0,
     319,     0,     0,     0,     0,  3032,     0,     0,     0,     0,
       0,     0,     0,     0,  3031,     0,     0,  3033,  3034,     0,
       0,     0,     0,  1264,     0,  3035,  3032,     0,  3036,     0,
       0,     0,     0,     0,     0,  1265,   319,     0,  3033,  3034,
       0,     0,     0,     0,     0,     0,  3035,  1266,  1267,  3036,
       0,     0,  2448,     0,     0,  1268,     0,   319,  1269,  2449,
       0,     0,     0,     0,     0,     0,   319,     0,     0,     0,
       0,     0,     0,     0,  3397,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2450,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2451,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2452,  2453,     0,     0,     0,     0,  2454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2456,     0,     0,  2457,  2458,     0,     0,     0,     0,  2459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2460,     0,     0,     0,
       0,     0,     0,     0,     0,  3398,     0,  2461
};

static const short yycheck[] =
{
       4,   217,   200,    68,   412,   283,   284,   655,     0,    13,
      14,  1103,   986,    17,  1035,  1327,   787,  1021,   136,   156,
    1320,  1137,   642,   285,   286,  1114,  1100,   552,   290,   688,
     178,   785,  1038,    25,  1055,    84,  1250,  1251,  2055,    31,
    1874,  2269,    46,    47,  2395,  2222,  1840,  1841,  2276,  2542,
    1355,    81,     5,   577,   594,   120,  1110,  1111,    62,  1113,
      27,  1115,  1116,    27,    27,  1941,  1942,  1943,  1944,   746,
    1132,  2753,  2754,  2755,    78,  2000,    68,    81,  1873,    20,
      84,  2003,   200,   202,     5,   711,    27,  2438,   708,    93,
     771,  2157,    26,    27,     5,    24,   100,    26,   718,   217,
     104,   249,  1936,   107,   108,    27,    24,  1989,    26,   113,
     114,     5,   771,    19,  2337,  1189,    63,     5,    24,    25,
      26,   775,   105,     5,   261,   262,     5,    20,   120,  1203,
    1222,   135,    25,     5,    27,    24,    25,    26,    27,    67,
      24,    25,    26,    27,  2756,    25,   344,    27,   152,   960,
      97,   155,  2786,   773,   774,    67,   160,    25,    26,    27,
      27,     5,    73,   783,    75,     5,    77,     5,   287,    25,
      27,    27,   291,    25,   293,    27,   295,   296,   297,   805,
       6,     5,    25,  2735,    27,   304,    27,  1193,     5,   308,
     309,     5,    86,    87,    19,     5,   143,    24,    25,    26,
     147,    26,    24,    25,    26,    27,     5,     5,  2556,     5,
    2558,    24,    25,    26,    27,   219,     5,     5,  2271,  2272,
     683,     5,  2275,    92,    93,     5,   344,   154,     5,    23,
     348,     5,    27,     9,    10,     5,    12,    13,    14,    15,
      16,    17,     5,    24,    25,    26,    27,   167,    53,    54,
      55,    56,    57,    25,   258,    27,   719,     5,   139,   722,
     264,   195,  2169,  2897,     5,  2899,  1270,    27,   236,   732,
      25,   275,    27,   736,     5,    96,  2329,   740,   282,   283,
     284,   285,   286,     5,   747,   305,   290,  1020,    25,   752,
      27,   754,    18,    19,    20,    21,    22,   760,     6,    27,
     763,   279,     5,     5,   251,     5,   195,   770,   586,    23,
    3043,   195,   775,   529,    70,  2837,     5,  2494,   179,   782,
     140,   141,  2339,    27,     0,   344,   154,   240,   447,   436,
     793,   450,  2434,     5,   797,  2563,   754,     5,   801,   195,
       5,  1121,  1122,   347,   807,   763,   365,   810,   467,   468,
     469,   470,   195,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     344,     5,   344,   683,  2250,    27,   686,   687,   395,     5,
     499,   500,   195,     5,    19,   504,   584,   506,  1159,   807,
     700,   279,   810,     5,   624,  1457,  1402,  2531,  2920,     5,
       5,   631,   521,   522,   523,   524,     6,   526,     5,   719,
     397,   529,   722,     5,   195,   276,   380,   364,   728,   366,
     212,   544,   732,   195,   371,   167,   736,    31,     5,   349,
     740,  2484,   631,   544,   744,   745,    27,   747,   654,  3073,
     750,  3075,   752,   753,   754,   239,     5,     5,  1259,   552,
     760,    86,  2586,   763,  2507,   279,   145,  3009,   195,     5,
     770,    27,    25,     5,    27,   775,   584,   195,     5,     0,
     593,   436,   782,   420,    27,    18,    19,    20,    21,    22,
    1938,   257,   593,   793,  3217,  3218,   764,   797,   553,   554,
      29,   801,  1496,  2205,    25,   349,  2208,   807,    69,   464,
     810,     5,     5,     9,    10,     5,    12,    13,    14,    15,
      16,    17,   401,   354,    23,     5,   520,   401,   780,   781,
     623,   155,     5,   279,   631,   239,  2579,   416,     5,     5,
       5,    20,   416,    27,   446,    28,   654,  2590,    27,     5,
       5,   545,     5,    27,   548,     5,     5,   809,  2342,   253,
     812,   514,   556,     5,     5,     5,     5,  2734,     5,     5,
     432,   553,   554,   155,   622,   584,     5,  1221,   572,   436,
     574,   397,   506,   367,   401,  2482,  2480,   390,     5,   583,
       5,   585,   586,   397,   436,     5,   288,   476,   288,   416,
     610,  2693,   432,   349,   354,   542,   574,   510,  2826,   395,
     376,   377,  1373,   567,   531,  1338,  2957,   349,   595,   397,
     584,   468,   584,   405,  1385,   432,    61,    62,   601,  1144,
     548,  1146,   442,   397,  2975,  3237,   560,   397,    27,    25,
     550,    27,   600,   432,   397,   476,   548,  2471,   519,   395,
    1103,   436,   195,   432,    89,    90,    91,   664,   432,   397,
     354,   545,   432,  3205,  3206,   432,   397,   379,   434,   250,
    1341,   358,   390,   583,  2730,  1313,   397,  1447,  2126,   673,
     552,   397,   263,   595,   678,   679,   680,   681,   682,   492,
     684,   685,  1341,   562,   688,   689,   574,   691,  1369,   397,
     694,  2003,   696,  2746,   397,  2620,   625,  1374,  2493,  2953,
    2622,   705,   623,   531,   476,   672,  1246,   625,   672,   672,
    1369,  3204,   623,  2936,   667,   559,  1240,  2940,   556,   625,
     631,   725,  2604,  3216,   617,   397,   582,   731,  3076,   397,
     239,   672,   397,   737,   738,   739,   625,   617,   632,   743,
     674,   625,   746,   464,   748,   749,   556,   601,   591,   617,
     574,   257,  3386,  3435,   552,   759,   250,  1220,  1221,  1222,
     764,   765,   631,  2068,   794,   520,   250,   771,    10,   263,
     595,   397,   476,  2224,   778,   397,   780,   781,   300,   263,
     346,   785,   786,   787,   589,   397,   562,   791,   354,   355,
     794,   397,   397,  1103,   866,   799,   195,   397,   625,   195,
     397,   464,   806,   625,   808,   809,  2518,   811,   812,   360,
     814,   815,   625,   371,   380,   172,   336,   383,   574,   556,
     397,    27,   393,   644,   645,   646,   647,   648,  2279,  2280,
     352,  1239,  2736,  2737,   356,   401,   364,  2890,   397,  2892,
     436,    27,  3335,  1469,   625,  1866,  1867,   418,  3199,   712,
    2902,   397,   628,  2905,  1875,   397,   975,  2651,   367,   978,
     397,    18,    19,    20,    21,    22,   985,   986,   464,   364,
     376,   377,   735,  1493,     8,   247,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,   432,
     481,   397,   464,   397,   397,   544,   625,   397,   654,   655,
     656,   459,   678,   679,   625,    39,   497,   397,   486,   665,
    1220,  1221,  1222,   435,   397,   919,   779,   475,     5,   300,
     397,   397,   397,   109,   329,   788,   789,  1948,   434,   792,
     501,   397,   397,   796,   397,   162,   329,   397,   397,   802,
     506,   804,   436,   358,   593,   397,   397,   397,   397,  3203,
     397,   397,   436,   481,   338,  1976,   960,  3010,   397,     5,
     518,    30,   625,    97,    98,    99,   100,   101,   102,   243,
     397,    14,   397,   159,  3229,   527,  2562,   397,  2564,   113,
     114,   115,    51,    52,  2073,  3240,   481,   481,   539,   195,
    3244,   390,   464,   997,   560,   999,   464,   481,   436,   519,
     558,   567,   553,   497,  2316,   401,  3059,   391,  2320,   195,
     530,   197,   254,   497,  3242,   460,  1020,    25,  3083,    27,
     582,  3086,   705,   594,  3089,   463,   300,   578,  2815,   587,
    2817,  1035,  3209,  2820,  1038,   606,   607,   117,   596,   397,
    2114,   436,   725,   614,  3097,   992,  1118,   253,  1052,    26,
      27,  1055,   630,  1125,   435,   738,   562,   630,   127,   128,
     622,   130,   131,   591,   162,   630,   135,   639,   548,   476,
     642,   649,   650,   431,   301,   626,   556,   484,   352,   652,
     653,   486,   356,   152,   153,    28,    29,   444,   653,  1093,
    2182,   669,  2543,   486,  3332,  2546,   591,    25,   455,    27,
    3338,   170,   547,    26,    27,  1109,  1110,  1111,   294,  1113,
    1388,  1115,  1116,   541,   243,    51,    52,  1121,  1122,   476,
     254,   287,   628,   257,  1386,  2099,   483,   595,   168,  1940,
     436,   171,    26,    27,   300,  1946,  1947,    25,    25,    27,
      27,  1952,  1953,  1954,  1955,   590,    39,    26,    27,   436,
     392,   378,   394,  1157,  2175,  1159,   196,   625,   436,  3212,
      25,   435,    27,   463,   464,  1169,  2752,  2753,  2754,  2755,
    1174,   300,   678,   679,    25,    24,   362,    26,  3012,  1316,
     464,    25,  1319,    27,   370,  1048,   436,   195,   374,  1193,
    1194,   127,   128,   673,   130,   131,  1474,   431,  1202,   135,
     436,  1479,  3267,   301,    97,    98,    99,   100,   101,   102,
      25,   287,    27,  1475,  1218,  1219,   152,   153,   195,  2240,
     113,   114,   115,   352,   300,   630,   412,   356,   436,    20,
    2816,    25,  2818,    27,   170,   275,    27,   630,   278,   436,
    1244,  2012,   376,   436,   649,   650,  1250,  1251,    25,   436,
      27,    25,   436,    27,   481,  1259,   649,   650,   392,   630,
     300,    25,   396,    27,   669,  1269,    25,   195,    27,   435,
     497,   436,   195,  1277,  1137,   432,   669,    25,    19,    27,
     378,   652,   653,    24,  1147,    26,   436,   436,  1337,  1152,
     436,  2591,   361,   479,  2752,  2753,  2754,  2755,    25,    26,
     434,   195,    20,  3090,  1963,   241,   435,   195,   195,    27,
    2622,    20,  2123,   463,   464,   436,   195,  1321,    27,  2619,
      26,  1325,  1326,  1327,   645,   646,  2097,    25,   462,    27,
     195,   182,   518,  1337,  1338,   463,   464,  1341,   436,  1343,
    1344,   436,   411,  1347,   436,  3221,   480,  3223,  3224,  3225,
    3226,   195,   436,    51,    52,  3321,  3322,   543,  2420,   435,
      20,   254,   340,   436,   257,  1369,  1370,    27,  1372,  1373,
    1374,  3388,  2611,   351,  2613,  2614,   526,  1381,  1382,   722,
     195,  1385,  1386,   481,  1388,  1389,   168,   436,  3405,   171,
    2161,   436,   793,   736,  2486,   435,   797,   740,  1402,   497,
     801,   587,    25,   472,    27,    24,  2026,    26,    20,   752,
     596,  2222,  3025,  2167,  2506,    27,   436,   168,   195,  2230,
     171,   195,  2233,  2234,  2235,  2236,   404,   464,   562,   127,
     128,   195,   130,   131,  3451,  3021,  3022,   135,   436,  3025,
    3406,   419,  3408,  1447,   436,   196,    20,   195,  2469,    20,
      25,  3468,    27,    27,   152,   153,    27,   164,   309,   618,
     619,   620,   621,   436,   315,   316,   317,    24,  1472,    26,
    1474,  1475,   170,   180,   181,  1479,   687,  1481,   436,  1483,
    1484,    26,   189,   376,   335,   436,   371,   444,  2509,   700,
     463,   464,   436,   275,   628,   631,   278,   195,   455,   392,
      25,  1505,    27,   396,   292,   293,    38,   443,    40,    41,
      42,    26,  1375,  1376,  1377,    19,   223,   728,   300,   476,
      24,    25,    26,   631,   275,   232,   483,   278,   644,  1392,
     508,   647,   648,   744,   745,  2556,  2307,  2558,    26,   750,
     371,   434,   753,   241,    26,   808,   647,   648,   811,   300,
    2321,   814,  2323,   526,   261,   675,   676,   677,   219,  2633,
    2085,  2332,   223,  3021,  3022,    26,  1370,  3025,  1372,   462,
     113,   114,   115,    26,   459,  1837,  1838,   654,   655,  1119,
    1120,   625,  2671,  1123,  1124,  1448,  2702,   480,   654,   655,
     475,   531,   371,   444,  2668,   436,   447,  2060,   436,   306,
    2814,  2815,   436,  2817,   455,  1468,  2820,  2919,   436,  3222,
     436,  2911,  3021,  3022,   436,  3228,   436,   436,  3231,  3232,
    3233,  3234,  1485,   436,    26,   426,  3084,   464,   459,  3087,
      26,    26,  1495,   518,    26,    26,  3222,    26,   625,   490,
       9,   348,  3228,  3229,   475,  3231,  3232,  3233,  3234,    18,
      19,    20,    66,   435,  3240,    24,    25,    26,    27,    63,
     321,   397,   366,   436,  2726,   625,    26,   436,   436,   562,
      18,    19,    20,   558,   525,   432,    24,    25,    26,    27,
     459,     5,   397,  2494,   435,   397,   436,   518,    18,    19,
      20,    21,    22,   476,   545,   546,   475,  2317,   397,   436,
      69,  2164,   587,  2677,   397,   556,   371,   397,    20,   631,
     561,   596,  2686,  2687,    20,   436,  1864,   436,   138,  2182,
     436,    69,  1870,   629,   138,   464,   625,   558,  3341,    26,
     263,  3344,  3345,  3346,  3347,   628,   432,  2548,  2358,   518,
     397,   366,    20,   275,    26,   443,   278,    26,   280,   600,
    2060,    26,  2563,    26,   371,  3341,   587,    26,  3344,  3345,
    3346,  3347,  3220,  2574,  3222,   596,    26,    26,   300,  1906,
    3228,  3229,   595,  3231,  3232,  3233,  3234,   397,   310,   558,
      26,   632,  3240,   397,   204,     5,   206,  2407,   397,   397,
     204,   397,   206,    20,   459,   436,    26,   329,    26,   397,
      26,   221,     5,   397,   625,  2067,   397,   221,   587,   229,
     475,    26,   307,   233,  3427,   229,   397,   596,   397,   233,
     352,   397,   629,     5,   356,   397,   195,   397,   397,   371,
     397,   436,  1836,  1837,  1838,   631,  1973,    26,   258,  1843,
    1844,  3427,   459,   595,   258,  1964,   631,   195,   397,  3435,
      25,    25,    25,   518,  2164,  2626,   397,    25,   475,  1863,
     397,   397,  1866,  1867,  2142,  2143,  2637,  1871,   397,  1873,
     397,  1875,  2182,   397,  1230,   397,  3090,   307,   397,   397,
     629,   397,   436,  3341,   397,   625,  3344,  3345,  3346,  3347,
     371,   464,  2703,   558,  2156,  1899,   622,   625,     8,   484,
     271,   518,   432,   435,   465,     5,  1910,    18,    19,    20,
      21,  3369,   623,   623,   601,   138,   426,   459,   465,   664,
     664,   331,   587,  2734,     8,   602,     5,     5,   436,   389,
     299,   596,   349,   475,  1938,   436,  1940,   436,   436,   436,
     595,   558,  1946,  1947,  1948,   584,     8,    14,  1952,  1953,
    1954,  1955,   581,     5,     5,   962,  2962,   426,   965,  1963,
     967,   968,   969,   970,   971,  2084,   436,   664,   436,  3427,
     587,    26,  1976,   664,    70,    96,   518,  3435,   459,   596,
    2099,   204,    26,   206,   464,  1989,    97,    98,    99,   100,
     101,   102,  2966,   625,   475,   595,  2000,   436,   221,  2003,
     436,   436,   436,   436,   436,   436,   229,   426,  2012,   464,
     233,  2822,    26,     5,   601,   625,   558,  2480,  2022,  2023,
    2024,   244,  1969,  2486,   436,  2029,     5,    24,    25,    26,
      27,   595,   401,  3037,   631,   258,   436,   518,   436,   436,
     667,   631,   630,  2506,   355,   587,     5,   416,   562,   710,
     711,    18,  2056,   401,   596,  3076,    19,    26,    26,   157,
    2064,  2065,   223,  2067,   433,    25,   628,   436,   416,   595,
      68,   487,    69,   584,   487,  2079,     5,   558,   552,   448,
     449,   625,  2086,   155,    26,   433,   552,   405,   436,   326,
     552,  2095,  2308,  2097,    26,   397,  3158,  2375,   436,   397,
     631,   449,   625,   531,  3166,   397,   587,   476,   436,   436,
     436,   436,   397,   436,  2118,   596,  2120,  2121,  3180,  2123,
     489,   669,  2126,  2127,   582,   625,   552,   464,   476,    20,
      21,   622,   501,     5,     5,   631,     5,   585,  2142,  2143,
     625,   489,     5,   488,   805,  2916,   436,   631,     5,  3241,
       8,   630,  2156,   501,   815,  2926,    26,  2161,  2162,  2163,
      26,   541,    70,  2167,   330,  2028,     5,     5,   397,   436,
    2480,  2175,   436,   365,   543,   602,  2486,   631,    14,   665,
    2043,   556,   552,     5,    26,   105,   436,  2191,   625,   631,
    2308,   436,  2196,     5,   644,   543,  2506,   432,   195,  2062,
    2204,  2205,    26,  2066,  2208,   630,    97,    98,    99,   100,
     101,   102,   397,   582,    62,  2841,  2842,  2843,  2222,  2845,
    2846,  2847,  2848,  2849,  2850,   594,  2230,     5,  2854,  2233,
    2234,  2235,  2236,  2237,   582,     5,  2240,   606,   607,   373,
    2244,  2245,   624,  2106,  2248,   614,   594,   336,   617,  3311,
     466,   432,   466,   436,     8,     5,   625,   436,   606,   607,
     436,   625,     5,   625,   436,  2269,   614,  2271,  2272,   617,
       8,  2275,  2276,  2736,  2737,   559,   436,   625,    20,    21,
     436,   436,  3093,   330,  3095,    25,   349,   135,   136,     6,
       7,     8,     9,    10,    11,    12,   349,   464,  2302,   960,
     349,  2305,    30,  2307,   625,   436,   304,   365,   431,     5,
     464,   426,  2316,  3319,     5,   656,  2320,  2321,    26,  2323,
       5,     5,    25,    51,    52,  2329,    14,    14,  2332,  2333,
     601,    26,  2336,  2337,   622,   601,   625,  3391,  3392,  3393,
    3394,  3395,  3396,   436,   625,     5,     5,     5,   631,   397,
     436,  2355,   200,     6,  3416,    97,    98,    99,   100,   101,
     102,   397,  2366,   397,   362,   397,   397,   397,     7,   217,
     453,  2375,   273,   397,     5,   631,   374,  1038,   625,    26,
      26,    26,   625,     8,   397,    20,     5,   385,   572,  3160,
     279,  2395,     5,     5,   552,     5,   673,     5,  3209,   127,
     128,   397,   130,   131,   401,   403,   577,   135,    38,   397,
      40,    41,    42,   625,   436,   413,   476,  2421,   416,   416,
     631,     5,   559,   631,   152,   153,  2736,  2737,   215,   629,
     631,   429,   397,  3407,   631,   476,   433,   436,  2716,   436,
    2718,   436,   170,     5,     5,    25,  2309,    25,    25,   629,
     133,   452,   449,    25,  3102,   624,    25,   301,    26,   142,
      26,  2324,  2325,  2326,  2327,  2469,  2531,    38,   151,    40,
      41,    42,    26,   156,    26,    26,    26,    26,     5,   477,
    2484,   397,  2345,   397,   473,  2701,     5,   436,  2492,  2493,
    2494,   397,   489,   245,    26,   556,   344,    25,   432,   397,
     348,   446,   349,  2507,   501,  2509,  3512,    20,   144,   507,
     436,   436,   436,  2517,  2518,   436,   559,   200,   436,   517,
       5,  2586,     5,   436,   436,   208,  3337,    14,   625,   215,
     447,  3302,  1193,     5,   464,   397,    26,   397,  2401,  2531,
     538,  1897,  1898,   541,  2548,   543,   543,   397,  1904,    26,
     379,   397,  2556,   574,  2558,  2674,    26,  2561,  2677,  2563,
     397,   436,  3373,   245,   397,   397,   349,  2686,  2687,   397,
    2574,   246,   464,   571,   552,  2579,  2580,  2581,   446,   397,
     436,   264,   580,  2701,    14,   582,  2590,   625,     7,  1250,
    1251,  2595,   244,   244,  2586,    26,   631,   594,  1259,   397,
    2604,   398,   436,   397,   581,   625,   289,   397,    25,   606,
     607,   436,   432,   296,   246,   298,  2620,   614,  2622,     5,
     617,   397,  2626,   397,   397,   308,  2630,  2681,   625,   397,
     397,   397,   397,  2637,  2497,  2630,  2499,    18,    19,    20,
      21,  3461,   985,  1486,  2391,   275,  2107,    38,   278,   553,
     280,   334,    40,  2333,  2662,  2339,   371,   143,  2662,   342,
    2664,   365,  2666,  3071,   657,   147,  3477,  1968,   233,   542,
     300,   372,   520,  1969,   560,  2679,   235,  2681,  2682,  2683,
     310,   529,  2944,  1249,   603,   572,   400,   399,  3451,  2951,
     574,  2028,  2696,   432,  2202,  2209,   791,   380,   978,  2703,
    2704,  2705,  2326,  2066,   275,  1836,  1227,   278,  2707,   280,
    2989,  2134,  2716,  1839,  2718,  3499,    97,    98,    99,   100,
     101,   102,   352,   406,  2728,  2729,   356,  2417,  2330,   300,
    2734,  3174,  2151,  2089,  1388,    25,   584,   120,    31,   310,
    2938,  1402,  2746,  3123,    31,  2112,   749,   348,  2752,  2753,
    2754,  2755,  2756,  2757,    30,   999,   921,  2118,   329,  1844,
    2705,   444,  2121,  2767,  2768,  2769,  2770,  3120,  3275,  1382,
    1194,  2775,   455,  1445,  2130,    51,    52,  3468,  3241,  2703,
    2643,   352,  2881,  2646,    60,   356,  1372,  3285,  1147,    65,
    1468,  2879,   466,  2863,  1347,  2320,  2589,   123,  1983,  2803,
    2804,  2006,  2480,  3477,  3097,   435,   654,  3362,  1469,  2510,
    2814,  2815,  2889,  2817,  2240,  2590,  2820,  2275,  2822,  2174,
    2938,  2803,  2826,  2804,  3087,  2561,  3369,  1863,  3140,  2595,
     678,   679,   680,   681,   110,   111,    17,  2769,  1223,  2702,
    2580,  3020,   118,  2581,  2747,  1947,  3095,  2966,   696,  1946,
    3329,   127,   128,  1858,   130,   131,  1219,  3019,  3220,   135,
    1831,  2865,  3239,  3228,   435,  2305,    -1,  1387,    -1,    -1,
     551,   554,   555,   556,  2878,    -1,   152,   153,    -1,  3157,
      -1,    -1,    -1,   731,   567,    -1,  2890,  2891,  2892,   737,
      -1,   739,    -1,    -1,   170,   743,    -1,    -1,   746,    -1,
     226,   749,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,
      -1,   759,  2916,    -1,   240,  2919,   242,    -1,    -1,    -1,
      -1,    -1,  2926,    -1,    -1,    -1,    -1,   253,    -1,    -1,
     778,  3241,  2936,    -1,    -1,  2939,  2940,   785,   786,   787,
    2944,    -1,    -1,   791,    -1,    -1,    -1,  2951,    -1,  2953,
      -1,   799,    -1,    -1,    -1,   281,    -1,    -1,  2962,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   815,    -1,    -1,
      -1,   297,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,   314,  2617,
      -1,    -1,    -1,    -1,    -1,   321,    -1,    -1,    -1,  3003,
      -1,    -1,    -1,    -1,    -1,    -1,  3010,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3019,    -1,  3021,  3022,    -1,
      -1,  3025,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2385,
    2386,    -1,  3036,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3059,    -1,  3061,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2422,  2423,  2424,  2425,
      -1,    -1,  3076,    -1,  2430,  2431,  2432,  2433,    -1,    -1,
    3084,  2437,    -1,  3087,  2947,    -1,  3090,    -1,    -1,  3093,
      -1,  3095,    -1,  3097,    -1,    -1,   372,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3325,
      -1,    -1,    -1,    -1,  2977,    -1,  3120,    -1,    -1,    -1,
      -1,    -1,    -1,   399,  2752,  2753,  2754,  2755,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     476,    -1,    -1,  3157,    -1,    -1,  3160,   483,    -1,    -1,
      -1,    -1,    -1,  2519,  2520,    -1,    -1,    -1,    -1,    -1,
    2526,  2527,    -1,    44,    45,    46,    47,    48,    49,   505,
      -1,    -1,    -1,  1844,   510,    -1,    -1,    -1,    -1,    -1,
    1038,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,  3203,
      -1,    -1,    -1,    -1,  1052,  3209,    -1,  3325,  3212,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3220,    -1,  3222,    -1,
      -1,    -1,    -1,    -1,  3228,  3229,    -1,  3231,  3232,  3233,
    3234,    -1,   103,  3237,    -1,  3239,  3240,    -1,  3242,   181,
    3244,    -1,    -1,    -1,    -1,  1093,  3250,   189,    -1,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      -1,  1109,  1110,  1111,    -1,  1113,    -1,  1115,  1116,    -1,
      -1,  3275,    -1,  1121,  1122,    -1,  3280,    -1,  3282,  1940,
      -1,   223,    -1,    -1,    -1,  1946,  1947,   563,  3407,    -1,
     232,  1952,  1953,  1954,  1955,    -1,  2652,  2653,  3302,  3162,
      69,    -1,    -1,    -1,    -1,  2661,    -1,    -1,    -1,    -1,
      -1,  1159,    -1,    -1,    -1,  3319,    -1,    -1,    -1,   261,
     262,  1169,    -1,    -1,    -1,  3329,    -1,    -1,    -1,    -1,
      -1,  3194,    -1,  3337,  2690,  2691,    -1,  3341,    -1,    -1,
    3344,  3345,  3346,  3347,  3348,  1193,  1194,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1202,    20,    21,    22,  3362,    -1,
      -1,  2717,    -1,  2719,   306,  3369,    -1,   643,    -1,  3373,
    1218,  1219,    -1,    -1,    39,   651,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3391,  3392,  3393,
    3394,  3395,  3396,  3021,  3022,    -1,    -1,  3025,    -1,  3403,
      -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2776,  2777,    -1,  3427,  2780,  2781,   195,    -1,    -1,    -1,
      -1,  3435,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,  3084,    -1,    -1,  3087,
      -1,    -1,  2123,   405,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,     9,  3477,    -1,    -1,    -1,    -1,    -1,   350,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3512,    -1,
      -1,    -1,    -1,  2869,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1370,    -1,  1372,  1373,  1374,    -1,    -1,    -1,
     299,    -1,    69,  1381,  1382,    -1,    -1,  1385,    -1,  3402,
      -1,  1389,    -1,    -1,   415,    -1,    -1,    -1,    -1,    -1,
      -1,   422,    -1,    -1,  1402,    -1,    -1,    -1,    -1,    -1,
      -1,  2222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2230,
      -1,    -1,  2233,  2234,  2235,  2236,    -1,    -1,    -1,    -1,
      -1,  2937,    -1,    -1,  2245,  2941,    -1,    -1,    -1,   254,
     461,    -1,   257,    -1,  3222,    -1,    -1,    -1,  2954,  1447,
    3228,  3229,    -1,  3231,  3232,  3233,  3234,    -1,  2269,    -1,
      -1,    -1,  3240,    -1,   485,  2276,    -1,  2973,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,    -1,    -1,    -1,  3257,
     501,  3494,   401,  1481,    -1,    -1,    -1,    23,    -1,    -1,
     511,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,  1505,   195,    -1,
      -1,    -1,   533,    -1,   433,   536,   537,   436,    -1,    -1,
      -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,
     449,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,   376,    -1,  3341,    -1,    -1,  3344,  3345,  3346,  3347,
     489,    -1,    -1,    -1,    -1,    -1,    -1,   392,   599,    18,
      19,   396,   501,    -1,    -1,    24,    25,    26,    27,   610,
      -1,  3369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   299,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      69,    -1,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,  3427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3435,    -1,    -1,
     196,    -1,    -1,   582,    -1,   480,    -1,    -1,   204,    -1,
     206,    -1,    -1,    -1,    -1,   594,    -1,    -1,    -1,   215,
      -1,    -1,    -1,  2494,    -1,   221,  3192,   606,   607,  3195,
      -1,    -1,    -1,   229,    -1,   614,    -1,   233,   617,    -1,
      -1,    -1,    -1,   239,    -1,    -1,   625,   243,   244,   245,
     246,    -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2548,    -1,   275,
      -1,    -1,   278,    -1,   280,    -1,   433,   562,    -1,   436,
    2561,   287,  2563,    -1,    -1,    -1,   195,    -1,    -1,    -1,
      -1,   448,   449,  2574,   300,    -1,    -1,    -1,    -1,    -1,
       5,     6,     7,     8,   310,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,   329,   330,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   489,    -1,    39,    -1,  2617,    -1,   344,    -1,
      -1,    -1,    -1,   628,   501,    -1,   352,  3323,    -1,    -1,
     356,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   365,
     366,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1843,  1844,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,  3375,
    3376,    -1,  3378,    -1,  3380,  3381,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2703,    -1,    -1,   582,    -1,    -1,    -1,   435,
      -1,  1899,    -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,
     446,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,
     607,    -1,    -1,  2734,    -1,    -1,    -1,   614,    -1,    -1,
     617,    -1,    -1,    -1,    -1,  3441,    -1,  3443,   625,    -1,
      -1,  2752,  2753,  2754,  2755,    -1,    -1,    -1,    -1,    -1,
     486,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,  3475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
      -1,    -1,  3488,  3489,    -1,    -1,  3492,    -1,    -1,  3495,
      -1,    -1,  2803,  2804,   433,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,  2814,  2815,    -1,  2817,    -1,    -1,  2820,
     449,  2822,   548,    -1,  2012,  2826,    -1,    -1,    -1,   254,
      -1,    -1,   257,    25,    -1,    -1,    -1,    -1,    -1,    -1,
    2841,  2842,  2843,    -1,  2845,  2846,  2847,  2848,  2849,  2850,
      -1,    -1,    -1,  2854,    -1,    -1,    -1,    -1,   584,   488,
     489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2079,    -1,    -1,    -1,    -1,    -1,    -1,  2086,    -1,
      -1,    -1,    -1,    -1,   630,    -1,    -1,    -1,    -1,  2097,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,   644,   645,
     646,   647,   648,   649,   650,    22,   652,   653,    -1,    -1,
    2118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2127,
      -1,    -1,    39,   669,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,   582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2962,    -1,    -1,    -1,   594,    -1,   392,    -1,    -1,
      -1,   396,    -1,  2161,  2162,  2163,    -1,   606,   607,  2167,
      -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,   617,    -1,
     182,    -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,  2196,   434,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
    3021,  3022,    -1,    -1,  3025,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,     5,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3084,    -1,    -1,  3087,    -1,    -1,  3090,
      -1,    39,  3093,    -1,  3095,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   309,    -1,  2307,
    2308,    -1,    -1,   315,   316,   317,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2321,    -1,  2323,    -1,   562,    -1,    -1,
      -1,    -1,    -1,   335,  2332,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,   254,    -1,    -1,
     257,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2366,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,    -1,  2395,  3209,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3222,    -1,    -1,    -1,    -1,    -1,  3228,  3229,    -1,
    3231,  3232,  3233,  3234,    -1,    -1,    -1,    -1,    -1,  3240,
      -1,  3242,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   444,    -1,    -1,   447,  3257,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,   490,   396,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2517,
      -1,    -1,    -1,   525,    -1,    -1,  3337,   434,    -1,    -1,
    3341,    -1,    -1,  3344,  3345,  3346,  3347,    -1,    -1,    -1,
      -1,    -1,    -1,   545,   546,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   556,   462,    -1,    -1,  3369,   561,
      -1,    -1,  3373,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,   480,    -1,    -1,    26,    27,    -1,     6,
       7,     8,  2580,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,   600,    -1,
      32,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    64,    -1,  3427,   254,   376,    -1,
     257,    -1,    -1,    -1,  3435,    -1,    76,    -1,  2626,    -1,
     632,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,  2637,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,   104,   562,    -1,    -1,    -1,    -1,
      -1,    -1,    94,    -1,    -1,    -1,  3477,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,   434,    -1,    -1,    -1,
      -1,  2679,    -1,  2681,    -1,  2683,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2696,    -1,
      -1,  3512,    -1,  2701,   462,    -1,  2704,  2705,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   628,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2728,  2729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,
     397,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,  2770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,
      -1,     6,     7,     8,   562,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    17,    18,
      19,    20,    21,    22,    -1,   462,    -1,   254,    -1,    -1,
     257,    -1,    -1,   265,    39,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,   480,   294,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,  2865,    -1,    -1,
     628,    -1,   304,    -1,    -1,    -1,    -1,   327,    -1,    -1,
    2878,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   323,    97,    98,    99,   100,   101,   102,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   339,   113,   114,
     115,    -1,   362,    -1,   113,   114,   115,    30,  2916,    -1,
      -1,    -1,    -1,    -1,   374,   562,    -1,    -1,  2926,    -1,
     362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
    2938,    -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    -1,    -1,   385,    -1,  2953,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,  2962,   392,    -1,    80,    -1,   396,
     397,   403,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,   413,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
      -1,   628,    -1,    -1,    -1,    -1,    -1,   429,    -1,   449,
      -1,    -1,   254,    -1,    -1,   257,    -1,   434,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,   469,    -1,   152,
     153,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   257,   480,    -1,   254,    -1,   170,   257,    -1,
     492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,
      -1,    -1,   514,    -1,    -1,   517,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,   541,
      -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3120,    -1,   376,    -1,    -1,    -1,   241,    -1,
     562,    -1,    -1,    -1,    -1,   562,    -1,   587,    -1,    -1,
     392,    -1,    -1,    -1,   396,    -1,   596,    -1,   580,    -1,
      -1,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,  3160,    -1,    18,    19,    20,    21,    22,    23,
      -1,   376,    -1,    -1,    -1,    -1,    -1,   376,    -1,    33,
      -1,    -1,   434,    -1,    -1,    -1,    -1,   392,    -1,    -1,
     622,   396,   397,   392,    -1,    49,    -1,   396,    -1,    -1,
      -1,   628,    -1,    -1,    -1,  3203,    -1,    -1,    -1,    -1,
     462,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   480,   434,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      94,    -1,    96,    -1,    -1,    -1,  3244,    -1,   361,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,   462,    -1,   113,
     114,   115,   116,   462,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,  3275,    -1,    -1,
      -1,   480,  3280,    -1,  3282,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   411,    -1,
      -1,    -1,    -1,    -1,  3302,   159,    -1,    -1,    -1,    -1,
     562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3319,    -1,    -1,    -1,    -1,    -1,  3325,   182,    -1,
     443,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,   197,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,   472,
      -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,   628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3391,  3392,  3393,  3394,  3395,  3396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   628,    -1,   279,    -1,    -1,    -1,   628,
      -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     294,   295,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
     304,   305,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,   315,   316,    -1,    -1,    -1,    -1,    -1,   322,   323,
     324,   325,   326,   327,    -1,    -1,    -1,   331,    -1,    -1,
      -1,   335,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
     344,   345,   346,   347,    -1,   349,   350,    -1,    -1,    -1,
     354,   355,    -1,   357,   358,   359,   360,   361,   362,   363,
     364,    -1,    -1,    -1,  3512,    -1,   370,   371,   372,    -1,
     374,   375,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,   387,    -1,   389,    -1,    -1,    -1,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,    -1,   432,   433,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,   472,    -1,
     474,   475,   476,   477,    -1,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,    -1,   516,   517,   518,   519,   520,   521,    -1,    -1,
     524,   525,    -1,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
      -1,    -1,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,    -1,    -1,    -1,    -1,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,    -1,
      -1,    -1,   656,    -1,    -1,    -1,   660,    -1,   265,   663,
     664,   665,   666,    -1,    -1,   669,   670,    -1,   672,   673,
     674,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,    -1,
      94,    -1,    96,    -1,    -1,    -1,    -1,   374,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   109,   110,    -1,   385,   113,
     114,   115,   116,    -1,    -1,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   413,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   469,   197,    -1,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
     507,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,
     517,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   538,   266,    -1,   541,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,    -1,
      -1,   285,    -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,
     294,   295,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
     304,   305,    -1,   580,    -1,   309,    -1,    -1,    -1,    -1,
      -1,   315,   316,    -1,    -1,    -1,    -1,    -1,   322,   323,
     324,   325,   326,   327,    -1,    -1,    -1,   331,    -1,    -1,
      -1,   335,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
     344,   345,   346,   347,    -1,   349,   350,    -1,    -1,    -1,
     354,   355,    -1,   357,   358,   359,   360,   361,   362,   363,
     364,    -1,    -1,    -1,    -1,    -1,   370,   371,   372,    -1,
     374,   375,    -1,    -1,    -1,   379,   380,   381,   382,   383,
     384,   385,   386,   387,    -1,   389,    -1,    -1,    -1,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,    -1,   432,   433,
      -1,    -1,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,    -1,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
     464,   465,   466,   467,   468,   469,   470,   471,   472,    -1,
     474,   475,   476,   477,    -1,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,    -1,   516,   517,   518,   519,   520,   521,    -1,    -1,
     524,   525,    -1,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   542,   543,
     544,   545,   546,   547,   548,   549,   550,   551,   552,   553,
      -1,    -1,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,    -1,    -1,    -1,    -1,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   651,    -1,    -1,
      -1,    -1,   656,    -1,    -1,    -1,   660,    -1,    -1,   663,
     664,   665,   666,    -1,    -1,   669,   670,    30,   672,   673,
     674,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,   124,   125,   126,   127,   128,   129,   130,   131,   132,
      -1,   134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,   146,    -1,   148,   149,   150,    -1,   152,
     153,    -1,    -1,    -1,    -1,   158,    -1,   160,   161,    -1,
     163,    -1,   165,   166,    -1,    -1,   169,   170,    -1,    -1,
     173,   174,   175,    -1,   177,   178,    -1,    -1,    -1,   182,
     183,   184,    -1,   186,    -1,    -1,    -1,   190,    -1,   192,
     193,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   202,
      -1,    -1,   205,    -1,   207,    -1,   209,    -1,   211,    -1,
     213,   214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,
      -1,   224,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,   236,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,   251,   252,
      -1,    -1,   255,   256,    -1,    -1,   259,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   268,   269,   270,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,
     283,   284,    -1,   286,    -1,    -1,    -1,   290,   291,    -1,
      -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,
     313,    -1,    -1,    -1,    -1,    -1,   319,   320,   265,    -1,
      -1,    -1,   325,    -1,    -1,   328,    -1,    -1,    -1,   332,
     333,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
     343,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   304,   361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,
      39,    -1,   375,    -1,    -1,    -1,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,    -1,
      -1,    -1,    -1,   406,    -1,   408,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   417,   362,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,   385,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   456,    -1,    -1,   403,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   467,    -1,   413,    -1,    -1,    -1,
      -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   498,   499,    -1,    -1,    -1,
     503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,   521,   522,
     523,   524,   469,    -1,    -1,   528,    -1,    -1,    -1,   532,
      -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,   551,    -1,
     553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     507,   564,    -1,   566,    -1,    -1,   569,   514,    -1,    -1,
     517,    -1,   575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,
      -1,   538,    -1,    -1,   541,    -1,   543,    -1,   601,    -1,
      -1,   604,    -1,    -1,    -1,    -1,   609,    -1,    -1,   612,
     613,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,    -1,    -1,
      -1,   634,    -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   657,   658,   659,   660,   661,   662,
     663,    -1,    -1,   666,    -1,   668,    -1,   670,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,   396,   397,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   434,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   562,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,   254,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,   628,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,   257,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,   397,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,   254,    -1,   434,   257,    97,    98,
      99,   100,   101,   102,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,   392,    -1,    -1,   462,   396,   397,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,   254,    -1,    -1,   257,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   434,    -1,    -1,    -1,   113,   114,   115,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,   396,   397,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,   254,    -1,    -1,   257,    -1,
      97,    98,    99,   100,   101,   102,   376,    -1,    -1,    -1,
      -1,    39,    -1,    -1,   434,    -1,   113,   114,   115,    -1,
      -1,    -1,   392,    -1,    -1,    -1,   396,   397,    -1,    -1,
     628,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,   628,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     480,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,   396,    -1,     6,
       7,     8,   562,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,   254,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,    -1,    39,    -1,    -1,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,   447,    -1,
     396,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,   254,    -1,   434,   257,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,   628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,     9,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,   392,    -1,    -1,    -1,   396,
      -1,    -1,    -1,   562,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    39,    -1,    69,    -1,   434,    -1,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   392,   462,    -1,    -1,   396,   628,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   480,    -1,    -1,    -1,   254,    -1,    -1,
     257,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   434,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,    -1,   197,    -1,   562,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,
      -1,   628,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    97,    98,    99,   100,   101,   102,    -1,    -1,
     294,    -1,    -1,    -1,    -1,   299,    -1,   434,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   327,     9,   462,    -1,    -1,    -1,    -1,
     628,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,   480,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    -1,   362,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,   393,
      -1,    76,    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,
     376,    64,    -1,    -1,    -1,    -1,    69,    -1,   412,    -1,
      -1,    -1,    -1,    76,   418,    -1,   392,    -1,    -1,   104,
     396,    -1,    -1,    -1,   428,   562,    -1,    -1,    -1,   433,
      -1,    -1,   436,    -1,    -1,   439,    -1,    -1,    -1,   254,
      -1,   104,   257,    -1,   448,   449,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,   488,   489,   462,    -1,    -1,   493,
      -1,   628,    -1,    -1,    39,    -1,    -1,   501,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,   512,    -1,
     195,    -1,   197,    -1,   518,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,    -1,    -1,    -1,    -1,   543,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,    -1,   587,    -1,    -1,   562,    -1,    -1,     9,
     594,    -1,   596,    -1,    -1,    -1,    -1,    -1,    18,    19,
      -1,    -1,   606,   607,    24,    25,    26,    27,    -1,   294,
     614,    -1,    -1,    -1,   299,    -1,    -1,    -1,    -1,   434,
      -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   294,   447,    -1,    -1,    -1,   299,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    64,    -1,    -1,   462,    -1,    69,
      -1,    -1,   628,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   327,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,   374,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   362,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   254,
      -1,   374,   257,   398,    -1,    -1,   401,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,    -1,    -1,
     393,    -1,    -1,   418,    -1,   398,    -1,    -1,   401,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,   562,   433,   412,
      -1,   436,    -1,    -1,   439,   418,    -1,    -1,    -1,    -1,
      18,    19,    20,   448,   449,   428,    24,    25,    26,    27,
     433,    -1,    -1,   436,    -1,   195,   439,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,   493,    -1,
      -1,    69,    -1,   628,    -1,    -1,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   488,   489,   512,    -1,   514,
     493,   376,    -1,   518,    -1,    -1,    -1,    -1,   501,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,   512,
      -1,   396,    -1,    -1,    -1,   518,    -1,    -1,   543,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   294,    -1,    -1,    -1,    -1,   299,
     543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    -1,   587,    -1,    -1,    -1,    -1,   327,    -1,   594,
      -1,   596,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,
      -1,   606,   607,    -1,   587,    -1,    -1,    -1,    -1,   614,
      -1,   594,    -1,   596,    -1,   480,    -1,   195,    -1,    -1,
     625,    69,   362,   606,   607,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   625,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,   393,    -1,    -1,    -1,    -1,   398,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,   412,    -1,    -1,    -1,    -1,    -1,   418,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,   433,    -1,    -1,   436,   562,    -1,   439,
      15,    16,    17,    18,    19,    20,    21,    22,   448,   449,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    97,    98,    99,   100,
     101,   102,    -1,    39,    18,    19,    20,    21,    22,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,   195,    -1,   489,
      -1,    -1,    -1,   493,    -1,    39,    -1,    -1,    -1,    -1,
      -1,   501,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   512,    -1,    -1,    -1,    -1,    -1,   518,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    -1,   113,   114,
     115,    -1,    -1,   543,    -1,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    18,    19,    20,    -1,    -1,   416,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,   587,    -1,    -1,
      -1,    -1,    -1,    -1,   594,   433,   596,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   606,   607,    -1,    18,
      19,   449,    -1,    -1,   614,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,   254,    69,   625,   257,    -1,    -1,    -1,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     488,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      69,    -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    69,   257,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      69,   257,    -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,   416,    -1,
     254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,   582,   376,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,   396,    -1,    -1,   606,   607,
      -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,   617,
     488,   489,    -1,    -1,    -1,    -1,   195,   625,    -1,    -1,
      -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,   434,    -1,    -1,    -1,   195,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,   195,   392,    -1,    -1,
      -1,   396,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
     396,   462,   376,    -1,    -1,   543,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,   480,
      -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      -1,    44,    45,    46,    47,    48,    49,    -1,   434,    -1,
      -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   594,   462,    -1,    -1,
     434,    -1,    -1,    -1,    -1,    -1,   462,    -1,   606,   607,
      -1,    -1,    -1,    -1,    -1,   480,   614,    -1,    -1,   617,
      -1,    -1,    -1,    -1,   480,    -1,    -1,   625,   462,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   562,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,   433,    -1,
      -1,   436,   401,    -1,    -1,    -1,   562,   628,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,   416,    -1,    -1,
      -1,    -1,    -1,   401,    -1,    -1,    -1,    -1,   562,    -1,
      -1,    -1,   401,    -1,   433,   208,    -1,   436,   416,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,
     449,    -1,    -1,    -1,   489,   433,    -1,    -1,   436,    -1,
      -1,    -1,    -1,   628,   433,    -1,   501,   436,    -1,    -1,
      -1,   449,   628,    -1,    -1,    -1,    -1,   476,    -1,    -1,
     449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     489,   264,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,   543,    -1,
      -1,   489,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
     489,    -1,    -1,   501,    -1,   298,    -1,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,    -1,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,
      -1,   334,    -1,    -1,   337,   543,    -1,    -1,    -1,   342,
      -1,   606,   607,    -1,   543,    -1,    -1,   350,    -1,   614,
      -1,    -1,   617,   582,    -1,    -1,    -1,    -1,    -1,    -1,
     625,    -1,    -1,    -1,    -1,   594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   582,    -1,    -1,   606,   607,    -1,
      -1,    -1,    -1,   582,    -1,   614,   594,    -1,   617,    -1,
      -1,    -1,    -1,    -1,    -1,   594,   625,    -1,   606,   607,
      -1,    -1,    -1,    -1,    -1,    -1,   614,   606,   607,   617,
      -1,    -1,   415,    -1,    -1,   614,    -1,   625,   617,   422,
      -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   437,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   495,   496,    -1,    -1,    -1,    -1,   501,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     533,    -1,    -1,   536,   537,    -1,    -1,    -1,    -1,   542,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   608,    -1,   610
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    51,    52,    80,   127,   128,   130,   131,   135,
     152,   153,   170,   241,   361,   411,   443,   472,   738,   766,
     767,   819,   990,  1043,  1045,  1046,  1047,  1052,  1054,  1067,
    1068,  1069,  1070,  1071,  1489,    28,    29,   739,   740,   741,
     742,   743,    27,   955,  1508,   360,   539,   553,   578,   626,
    1490,  1490,  1490,  1490,  1490,  1490,  1490,  1490,   955,    25,
     955,  1408,  1072,   768,  1408,   767,  1489,     0,  1044,  1047,
    1052,  1070,  1489,    31,   741,   743,   955,  1492,   595,   955,
    1491,   631,   820,    25,   195,   765,   766,   943,   955,   960,
    1073,  1108,  1109,  1110,  1111,  1112,  1116,   358,   770,   771,
     772,   773,   776,   777,    60,    65,   110,   111,   118,   372,
     399,   470,   563,   643,   651,   738,   744,   915,   989,  1048,
    1049,  1051,  1055,  1056,  1062,  1074,  1095,  1228,  1238,  1489,
     955,  1491,   622,  1111,   247,   463,   464,  1118,    20,   955,
    1115,   625,   771,     5,   769,   358,   955,     5,   795,   797,
     798,   955,  1239,   955,   955,  1229,  1063,   955,   955,  1051,
    1057,   265,   304,   323,   362,   374,   385,   403,   413,   429,
     469,   492,   507,   514,   517,   538,   541,   543,   562,   580,
     821,   822,   823,   826,    25,  1108,  1114,    18,    19,    26,
      64,    76,   104,   197,   294,   327,   362,   374,   412,   428,
     436,   449,   493,   518,   543,   587,   596,   688,   690,   881,
     886,   897,   899,   955,  1108,  1119,  1120,   464,    14,   818,
     773,   527,  1215,   774,   771,   776,    32,    34,    84,    85,
      94,   265,   304,   323,   339,   362,   374,   385,   403,   413,
     429,   469,   492,   507,   514,   517,   538,   541,   543,   562,
     580,   622,   780,   789,   800,   801,   955,   436,   117,   955,
     765,   916,  1096,   955,   828,   541,   778,   804,   806,   807,
     805,   814,   815,   436,   436,   827,   464,   436,   436,   771,
     802,   431,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   688,   436,   762,     9,    18,    19,    24,    25,
      26,    69,   299,   393,   398,   401,   418,   433,   436,   439,
     448,   489,   501,   512,   543,   594,   606,   607,   614,   625,
     855,   863,   864,   865,   866,   867,   868,   869,   897,   898,
     900,   961,  1108,  1218,  1400,   436,   436,   436,   436,    18,
      19,    20,    21,    22,   689,    26,   436,   526,     5,   432,
    1119,    25,    26,   955,   961,    19,    25,    26,   775,   961,
     675,   676,   677,   779,   791,   778,   792,   804,   805,   436,
     436,   790,   464,   436,   436,   802,   771,   799,   436,    26,
     955,   436,  1064,   765,   765,   436,   955,   436,   463,   784,
     631,   371,   459,   475,   518,   558,   587,   596,   808,   631,
     371,   459,   475,   518,   558,   587,   596,   816,    26,    26,
     829,   830,   831,   832,   955,    26,   787,   788,    26,    26,
     625,   672,   947,   955,  1499,   947,   947,  1499,  1499,   855,
      25,    26,    19,    24,    25,    26,   901,   902,   903,   904,
    1499,   855,   397,   855,   855,   855,   855,   531,  1235,   436,
     436,   855,   371,   459,   475,   518,   558,   587,   596,  1403,
    1404,   436,   855,   855,   436,   436,   870,   436,   436,   436,
     436,    26,     6,     7,     8,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    39,    97,
      98,    99,   100,   101,   102,   113,   114,   115,   254,   257,
     376,   392,   396,   434,   462,   480,   562,   628,   761,   856,
     871,   873,   874,   875,   876,   877,   878,   879,    26,   961,
     426,   889,   887,   893,   891,   688,   882,   955,  1120,   464,
     432,    26,   782,   771,   784,   771,    26,    26,   770,   787,
      26,    26,   625,    63,   796,  1240,   397,   436,  1230,  1509,
    1510,  1511,  1512,  1513,   917,  1097,  1058,   625,    26,   809,
     810,   436,   811,   816,   817,   811,   436,   812,     5,   397,
       5,   397,     5,   288,     5,   821,   432,     5,     5,   397,
     397,   771,   803,   436,   464,   625,     5,   397,   397,   397,
     397,   397,   397,   397,   397,   595,   902,    19,    26,   595,
     397,   397,   397,     5,   763,   855,   476,  1424,   855,   436,
     631,    20,   397,  1424,    20,  1218,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   855,
     855,   855,   855,   855,   855,   855,   855,   855,   855,   436,
     855,   855,   436,  1108,   855,   855,   855,   855,   718,   719,
     720,   855,   436,  1119,   464,   629,   625,    26,   263,     5,
     397,     5,   397,   288,   432,     5,   397,   397,   803,   955,
    1125,  1126,  1128,  1075,  1125,   366,  1510,  1215,    35,    36,
      37,    43,    50,    59,    71,    72,    74,    88,    95,   106,
     107,   108,   122,   124,   125,   126,   129,   132,   134,   136,
     137,   143,   146,   148,   149,   150,   158,   160,   161,   163,
     165,   166,   169,   173,   174,   175,   177,   178,   182,   183,
     184,   186,   190,   192,   193,   198,   202,   205,   207,   209,
     211,   213,   214,   216,   217,   218,   222,   224,   225,   227,
     235,   236,   248,   251,   252,   255,   256,   259,   260,   268,
     269,   270,   272,   282,   283,   284,   286,   290,   291,   295,
     303,   311,   312,   313,   319,   320,   325,   328,   332,   333,
     343,   361,   369,   375,   406,   408,   409,   417,   456,   467,
     474,   498,   499,   503,   515,   521,   522,   523,   524,   528,
     532,   539,   540,   551,   553,   564,   566,   569,   575,   601,
     604,   609,   612,   613,   627,   634,   657,   658,   659,   660,
     661,   662,   663,   666,   668,   670,   681,   682,   683,   684,
     701,   723,   737,   738,   744,   745,   764,   834,   835,   836,
     837,   848,   849,   850,   851,   852,   853,   854,   906,   910,
     941,   962,   963,   966,   967,   968,   969,   982,   991,  1012,
    1013,  1015,  1019,  1034,  1035,  1039,  1040,  1041,  1042,  1050,
    1065,  1078,  1089,  1090,  1091,  1102,  1105,  1141,  1144,  1146,
    1152,  1153,  1156,  1159,  1162,  1164,  1166,  1169,  1176,  1181,
    1185,  1186,  1187,  1199,  1200,  1203,  1209,  1210,  1211,  1236,
    1251,  1252,  1253,  1254,  1255,  1260,  1266,  1267,  1285,  1288,
    1318,  1320,  1409,  1410,  1441,  1442,  1449,  1460,  1489,  1493,
    1498,  1500,  1502,  1506,  1507,  1514,   738,  1053,  1489,   630,
     653,  1098,  1099,  1125,    20,   397,   431,   785,   808,    26,
     813,    26,    26,    26,   830,   832,   824,   788,    26,   955,
     688,    20,   672,   955,   947,   895,  1404,   895,    26,    26,
     595,    24,    26,   805,   896,   806,   397,   364,   481,   591,
    1432,   397,   397,    26,  1404,   397,   397,   397,   397,   397,
     397,   397,   447,   447,   447,   880,  1424,   447,   880,  1424,
     890,   888,   894,   892,   883,     5,   884,   432,  1119,   795,
      20,   785,   436,    26,    26,   781,    26,   625,   397,     5,
    1125,   397,  1108,  1108,  1108,    25,  1108,  1163,   955,   354,
     956,   957,  1508,   955,   955,  1183,   950,   956,   950,    25,
     195,   955,  1117,  1484,  1485,  1486,   955,  1504,   955,  1262,
    1263,   955,    26,   685,  1108,  1258,   950,  1183,   880,    26,
     961,  1223,  1224,  1223,   855,   862,  1287,   857,   880,   956,
    1450,  1450,   838,  1183,   950,  1256,  1108,   952,   956,   862,
    1450,  1108,  1183,  1108,  1286,  1450,    25,   591,  1092,  1093,
    1108,   950,   950,  1092,   951,   956,   955,  1093,   950,  1450,
     950,   952,  1108,  1139,  1140,   948,   956,   952,   380,   567,
     947,  1014,   955,   746,   953,   956,    25,  1319,  1484,   880,
     880,   956,  1165,   911,   133,   142,   151,   156,   200,   208,
     264,   289,   296,   298,   308,   334,   342,   380,   406,   444,
     455,   554,   555,   556,   567,   670,  1028,  1160,  1161,  1108,
     861,   862,  1175,  1499,  1499,   949,   956,   880,  1163,  1237,
    1108,  1214,    25,  1108,  1444,   862,  1205,  1206,  1207,  1216,
    1217,   862,  1494,   109,   159,   197,   294,   370,   412,   479,
     702,   886,   955,  1108,  1246,   725,   862,   948,  1491,  1079,
     862,   948,    26,  1108,  1036,   948,   862,  1461,   862,  1223,
     955,   964,   965,   952,   964,  1499,   952,   964,  1499,   970,
     964,    25,    26,   390,   492,   961,  1017,  1108,  1127,  1129,
      70,   279,   349,   395,   574,   654,   655,   656,   665,   692,
     972,   974,   976,   978,   980,  1103,  1104,  1107,   340,   351,
     404,   419,   508,  1321,   645,   646,   919,   920,   921,   955,
    1100,   652,  1099,   397,   307,   397,   397,   397,   397,   629,
       5,   397,   397,   432,   436,   631,   397,    26,   595,   631,
      18,    19,    20,    25,    26,    69,   401,   416,   433,   436,
     449,   489,   501,   543,   582,   594,   606,   607,   614,   617,
     955,   961,  1399,  1401,  1431,  1433,  1434,  1436,  1437,  1438,
    1485,  1488,  1235,   397,  1235,  1235,  1235,  1235,  1235,  1235,
      25,    25,    25,   855,   872,   397,    25,   872,   397,   397,
     397,   397,   397,   397,   720,   718,   432,   307,   771,   793,
     794,   397,   397,   629,   397,   955,  1241,  1128,   397,  1231,
      61,    62,    89,    90,    91,   460,   547,   590,  1268,  1269,
    1270,  1273,  1276,  1279,  1280,  1281,  1282,   436,   625,  1486,
    1118,   622,  1157,   625,     8,   544,   593,     5,   397,   432,
      25,   955,  1393,   484,  1184,  1127,   113,   114,   115,   488,
     858,   859,   862,  1108,  1134,  1393,   691,   692,   841,   271,
      92,    93,   631,   465,     5,   624,   631,   623,   623,  1142,
     601,   426,     5,   562,   992,   465,   664,  1496,   664,   390,
     748,  1108,   552,   623,  1147,  1148,  1149,   331,  1317,   860,
     862,   860,     8,   949,    26,   506,   560,   674,   942,  1108,
     942,   942,   942,    25,   182,   309,   315,   316,   317,   335,
     444,   447,   455,   490,   525,   545,   546,   556,   561,   600,
     632,  1032,  1033,   942,   942,   602,  1029,   692,  1029,  1029,
     943,   943,  1029,  1029,   692,     5,   338,   391,     5,   691,
      86,    87,   545,   632,  1020,   667,  1497,   861,   618,   619,
     620,   621,  1213,  1215,   389,  1250,  1215,  1207,     5,   623,
    1208,   862,   436,   436,   436,   436,    25,   721,   955,   436,
    1444,   349,   436,   526,   595,   584,   726,   733,   724,    25,
    1094,  1108,  1201,     8,  1204,    14,   955,  1113,  1121,  1122,
    1124,  1132,  1133,  1177,   167,   349,   550,   583,     5,     6,
       7,     8,     9,    10,    12,    13,    14,    18,    19,    20,
      21,    22,    23,    33,    49,    67,    76,    94,    96,   104,
     109,   110,   113,   114,   115,   116,   119,   120,   159,   182,
     188,   195,   197,   203,   228,   266,   279,   285,   294,   295,
     301,   304,   305,   309,   315,   316,   322,   323,   324,   325,
     326,   327,   331,   335,   337,   344,   345,   346,   347,   349,
     350,   354,   355,   357,   358,   359,   360,   361,   362,   363,
     364,   370,   371,   372,   374,   375,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   389,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   432,   433,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     474,   475,   476,   477,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     516,   517,   518,   519,   520,   521,   524,   525,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   643,   651,
     656,   660,   663,   664,   665,   666,   669,   670,   672,   673,
     674,  1462,  1463,  1464,  1466,   581,     5,   664,   664,   860,
    1127,  1134,  1016,   426,     5,   155,   996,   436,  1108,   860,
     436,    26,    26,    70,  1106,    25,  1108,  1448,  1448,   956,
    1301,  1165,   949,   123,   226,   234,   240,   242,   253,   281,
     297,   302,   314,   321,   476,   483,   505,   510,  1289,  1290,
    1298,  1308,  1309,  1315,  1316,  1322,  1323,  1332,  1351,  1355,
    1420,  1421,  1451,  1452,  1455,  1456,  1468,   922,   923,    96,
     918,   929,   930,   921,  1101,  1509,  1059,   464,   821,   788,
     625,   955,   371,   459,   475,   518,   558,   587,   596,  1405,
     895,   595,    24,    26,   809,  1437,  1437,   371,   459,   475,
     518,   558,   587,   596,  1402,  1406,   476,  1436,   436,   436,
     436,   436,   436,   436,   436,   955,   436,     5,   552,  1360,
    1365,   955,    18,    19,    20,    21,    97,    98,    99,   100,
     101,   102,  1458,   426,     5,   397,   397,   885,   464,     5,
     397,   795,   765,  1076,   765,   162,   301,   378,   436,   481,
     497,  1338,  1350,   436,   955,  1284,    26,   250,   263,   436,
     481,   497,   955,  1265,  1278,  1336,  1337,  1342,  1344,  1346,
     436,   955,  1275,   436,  1265,  1271,     5,    25,   958,  1111,
    1486,  1484,   582,   622,  1158,    20,   955,  1138,  1487,   955,
    1505,  1263,   601,   625,   595,   436,   436,   841,     5,   631,
     436,  1484,    25,   960,  1182,  1182,  1444,  1092,   862,   862,
     862,   944,   945,   436,  1108,  1140,   802,   993,   994,   631,
    1444,  1499,  1497,  1014,  1108,   747,   630,   862,   355,  1151,
     562,  1150,     5,    73,    75,    77,   623,   631,   833,  1127,
     912,    18,    19,   436,  1030,  1032,  1161,   943,   862,   349,
     601,    26,    26,   691,   157,  1212,   223,  1217,  1223,  1495,
     955,    25,   905,   947,  1499,   595,   947,   628,  1108,   706,
     955,   955,   862,   344,   729,   733,   584,   727,   735,    23,
     239,  1081,  1085,   487,   880,   487,  1202,   862,   463,  1118,
     625,     5,  1037,   552,  1178,  1108,  1465,  1467,   194,  1463,
     983,   965,  1499,  1499,   975,   976,   996,   996,    38,    40,
      41,    42,   275,   278,   280,   300,   310,   352,   356,   435,
     995,   997,   998,  1024,  1108,  1129,   552,   693,    26,   405,
     981,   326,  1443,  1443,   140,   141,   442,   552,   955,  1352,
    1353,  1394,   802,  1393,  1393,  1291,   802,   955,  1453,  1453,
    1432,  1393,  1299,   172,   444,   455,   476,   483,  1325,  1326,
    1327,   292,   293,  1415,  1509,  1509,   390,   931,  1108,   647,
     648,   924,   925,   926,   486,   630,   649,   650,   669,   934,
     935,  1509,   765,    26,   786,    20,   955,   397,   436,    24,
      26,   631,  1432,   397,   401,  1459,  1488,   364,   481,   591,
    1384,  1436,  1439,  1384,  1384,  1384,  1384,   625,  1439,  1434,
     520,  1361,  1362,  1363,  1393,   531,  1359,  1366,   336,   519,
     530,  1310,  1427,  1436,  1436,  1436,  1436,  1485,   855,   397,
     786,   794,  1242,   765,  1232,  1340,  1393,  1283,  1350,   436,
    1283,   436,   436,  1277,  1278,   436,   436,    68,   304,   362,
     374,   385,   403,   413,   416,   429,   477,   507,   517,   538,
     541,   543,   571,   580,  1385,  1386,  1387,  1389,  1274,  1275,
    1271,  1272,   669,  1269,   397,   625,  1444,   582,   464,   552,
    1503,   686,   687,   955,   955,   955,  1259,   880,   858,   955,
    1257,   622,  1154,   631,     5,     5,     5,   585,   862,   625,
       5,   488,   631,   630,   168,   171,   275,   278,   749,   752,
     753,  1024,   750,   751,   955,   436,   956,   654,   655,  1155,
     862,   955,   955,   945,   946,   514,  1499,   841,     8,   914,
      26,    26,  1031,  1032,  1108,   541,  1170,    70,   855,  1215,
      26,  1108,  1509,     5,     5,     5,   397,   397,   722,   955,
     397,  1444,   718,   436,   436,   734,   730,   365,   728,   862,
     344,   731,   735,   602,  1026,  1086,  1082,   367,  1080,  1081,
     860,   631,  1114,    20,   955,  1123,  1133,    14,   488,  1179,
    1180,  1436,  1488,  1108,  1130,  1131,  1509,   977,   978,   556,
     954,   552,  1007,  1006,  1009,  1008,   947,  1010,   947,  1011,
    1005,  1004,  1002,  1001,  1025,   329,   998,  1003,  1499,    44,
      45,    46,    47,    48,    49,   103,   337,   350,   415,   422,
     461,   485,   495,   496,   501,   511,   533,   536,   537,   542,
     599,   610,   694,   695,  1022,  1023,     5,    26,  1444,   253,
    1108,   476,  1425,  1426,  1444,  1165,  1419,  1421,   105,   105,
     601,  1163,  1354,  1355,   436,  1333,   154,  1366,  1393,   179,
     276,  1457,   625,   631,  1422,  1469,   346,   355,   380,   383,
     401,   506,   560,   567,   949,  1302,  1307,   436,  1328,   630,
       5,    25,   955,  1416,  1417,   933,  1108,     5,   552,   927,
     928,   644,   926,   932,   955,   932,   936,   937,   932,   329,
     935,  1060,   432,    26,   371,   459,   475,   518,   558,   587,
     596,  1407,  1433,     5,  1406,   397,     5,  1436,     5,   397,
    1436,  1436,  1436,  1436,   955,   397,   436,  1363,     5,   955,
    1398,     9,   299,   436,   448,  1369,  1370,  1371,  1372,  1373,
    1377,  1381,  1383,  1436,   373,  1357,  1367,   955,  1428,   624,
    1384,   336,   432,   466,  1225,  1245,  1077,   466,  1188,  1219,
     436,     5,   397,  1369,   397,   617,   955,  1339,  1341,  1393,
    1396,  1397,  1343,  1396,     5,   397,  1343,  1369,  1406,  1406,
     436,   436,   436,   436,   436,   436,   212,   405,  1345,  1347,
       5,   397,     5,   397,   955,  1487,     8,  1444,  1119,   862,
       5,  1264,  1265,   880,  1066,   625,  1264,   582,  1444,  1444,
     862,   862,   944,   514,   862,  1501,     5,    20,  1396,   994,
    1444,   750,   758,   757,   759,   955,   959,   760,   959,   196,
     753,   756,     5,   996,   625,   862,     8,   955,   880,   559,
    1305,     5,   397,  1108,     5,   330,    25,  1247,   947,   349,
     349,   464,   625,   349,   436,   707,   711,   704,  1509,  1509,
     736,   732,   728,  1027,    25,   954,  1087,  1108,  1509,   862,
     431,   464,   880,     5,   426,     5,   984,   979,   980,    26,
     691,   955,  1509,  1509,  1509,  1509,     5,   999,     5,  1000,
    1509,  1509,  1509,  1509,  1030,  1509,   954,    25,    14,    14,
       5,   397,    26,  1393,  1432,  1413,   601,   601,  1290,  1418,
    1419,  1355,  1334,  1396,   622,   949,   436,  1294,   955,  1454,
    1453,  1433,    53,    54,    55,    56,    57,   589,  1472,   862,
     862,  1300,   949,  1329,  1396,  1393,  1327,   625,   625,     5,
       5,  1108,   932,  1509,  1509,     5,   939,   940,  1509,  1509,
     938,  1053,   825,   397,  1365,  1406,   631,  1406,   397,  1436,
     397,   397,   397,   397,  1362,  1364,  1362,  1372,   436,  1431,
    1369,  1436,  1431,     6,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   257,   376,   377,   434,   562,   628,   678,
     679,  1380,  1382,  1358,  1435,  1436,   453,  1356,  1368,   273,
    1261,    26,  1311,  1312,  1313,  1396,  1425,  1428,   783,    78,
      79,    81,    82,    83,   181,   189,   223,   232,   261,   262,
     306,   348,   405,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,  1222,  1226,   139,   519,  1227,  1243,  1053,
     164,   180,   181,   189,   223,   232,   261,   306,   348,  1220,
    1221,  1233,  1227,  1341,  1350,   397,  1397,   464,  1395,   397,
       5,   625,     5,   397,  1278,   397,   397,   631,   436,   631,
      26,  1391,  1391,    26,  1391,  1391,    26,  1390,    25,  1399,
    1348,  1349,  1350,  1275,  1271,  1444,     8,   432,   687,     5,
     397,   860,   397,    20,   397,  1444,     5,   862,   572,   279,
     696,   697,   862,   996,  1509,  1509,     5,   754,   464,   625,
       5,   755,  1509,   751,   552,    20,   955,     5,   955,  1145,
     395,   664,   860,  1306,   913,  1032,   673,  1168,   855,     5,
     718,  1108,   703,   685,   955,  1108,   709,   397,   718,   718,
    1509,  1509,  1030,  1084,    25,  1088,  1108,   577,   909,  1119,
     488,   861,  1038,  1180,  1108,  1131,    67,   548,   985,   971,
     972,   625,   947,  1509,   947,  1509,   691,    26,  1108,    26,
    1108,   695,   397,   436,  1445,  1433,  1415,  1419,  1419,  1411,
       5,   397,   476,  1430,  1295,  1396,   484,  1292,  1430,   631,
    1423,    18,    19,    69,   433,   436,   449,   488,   489,   501,
     543,   582,   594,   606,   607,   614,   617,   955,  1399,  1431,
    1477,  1478,  1479,  1480,  1481,  1482,  1488,  1477,  1477,  1477,
    1396,  1474,  1476,  1473,  1474,  1475,  1470,   559,  1303,     5,
     397,   631,   955,   955,  1417,  1108,   955,  1509,  1509,  1509,
    1509,   629,   397,   631,  1407,   631,     5,   397,   397,  1370,
    1371,  1375,  1437,  1375,   436,  1431,  1375,   436,  1431,  1375,
      10,   254,   392,   394,  1436,     5,  1369,     5,   544,   593,
    1314,  1261,   629,  1223,  1223,  1223,    25,  1223,  1223,  1223,
    1223,  1223,  1223,    25,    25,  1223,  1226,  1108,  1135,  1136,
     624,   452,  1189,  1509,    25,    25,    26,    26,    26,    26,
      26,    25,  1108,  1221,  1189,   397,    26,  1338,  1396,    20,
     955,  1396,  1407,    26,  1407,     5,  1388,  1388,     5,   397,
     397,  1388,   397,  1350,  1444,  1265,  1261,   473,   840,     5,
     379,  1444,     5,   436,   397,   556,  1021,   959,  1509,   688,
      20,   955,   959,  1509,  1499,   862,  1499,  1130,  1509,    26,
     954,    25,  1248,  1127,   432,   718,   708,   712,   397,  1509,
     954,   862,   907,   432,   987,   986,   446,   973,   974,    20,
     955,  1446,  1447,   559,  1429,  1414,  1412,  1415,  1396,  1432,
     144,  1335,     5,   397,  1293,  1454,  1429,  1480,  1480,  1479,
     436,   436,   436,   436,   436,   436,   436,   955,   436,     5,
     397,    18,    19,    20,    21,  1458,   397,     5,   397,     5,
      14,   154,   531,  1471,  1304,  1396,   468,  1330,  1331,  1394,
     625,   215,  1061,   821,  1407,  1407,  1362,   447,  1374,  1374,
    1378,  1379,  1399,  1488,  1374,  1378,  1374,  1375,  1436,  1435,
    1312,   795,   544,   593,  1137,     5,  1135,    66,   138,   204,
     206,   221,   229,   233,   258,  1190,  1191,  1244,  1061,  1234,
       5,   432,  1395,   397,    26,  1392,   397,   397,    26,   397,
     947,   691,   379,  1444,   862,   698,   574,  1143,    26,   691,
     432,  1021,   397,   245,   691,   397,   397,   436,   710,   349,
     716,   397,   705,  1083,  1509,   464,   862,  1509,   954,     5,
     397,  1130,  1365,  1415,  1415,  1433,  1396,   436,  1365,   397,
    1459,  1384,  1479,  1483,  1384,  1384,  1384,  1384,   625,  1483,
    1478,  1479,  1479,  1479,  1479,  1474,    14,  1475,  1478,   949,
    1369,  1130,     5,   145,  1324,   955,  1376,  1399,  1440,     5,
     397,   397,  1374,     7,  1136,  1192,  1193,  1108,  1195,  1108,
    1194,  1196,  1191,   244,   244,    26,   631,   397,   839,  1444,
     398,   208,   264,   289,   298,   334,   342,   437,   608,   695,
     699,   700,   436,   625,   691,  1167,  1249,   713,   397,  1127,
     716,   716,  1509,   908,  1119,   581,  1018,  1447,  1427,  1365,
     488,  1296,  1297,  1436,  1427,   397,  1479,     5,   397,  1479,
    1479,  1479,  1479,   955,   397,   436,  1331,  1379,  1436,  1509,
    1509,  1197,  1509,  1198,  1509,  1509,   432,  1407,   352,   356,
     842,   843,   844,  1024,   942,   942,   942,   942,   942,   942,
      25,     5,   397,   862,    20,   955,  1024,  1171,  1172,  1173,
     716,   718,   716,   246,   432,   988,   691,     5,   397,   397,
    1479,   397,   397,   397,   397,  1477,  1509,  1509,   846,   845,
     243,   844,   847,   700,     5,  1174,   287,  1173,   714,  1509,
    1297,   397,  1509,  1509,  1509,   862,  1509,   397,   985,   397,
     715,   167,   349,   717,  1127
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
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1051:
#line 5609 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1052:
#line 5610 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1053:
#line 5615 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1054:
#line 5616 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1055:
#line 5619 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
	A4GL_debug("put buff=%s\n",buff);
	if (buff[0]!='\''&&strncmp(buff,"?",1)!=0&&strncmp(buff," :",2)!=0) {
		A4GL_debug("Got : %s - expecting '..', : or ?",buff);
 		a4gl_yyerror("Put values must be variables, strings or 'NULL'");
		YYERROR;
	}
	
}
    break;

  case 1057:
#line 5645 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1058:
#line 5650 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1059:
#line 5655 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1060:
#line 5660 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1066:
#line 5682 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1067:
#line 5689 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1068:
#line 5698 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1069:
#line 5704 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1070:
#line 5706 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1074:
#line 5717 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1075:
#line 5718 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1076:
#line 5724 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1077:
#line 5728 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1078:
#line 5734 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1079:
#line 5735 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1080:
#line 5740 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1081:
#line 5741 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1082:
#line 5743 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1083:
#line 5744 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1084:
#line 5745 "fgl.yacc"
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
#line 5759 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5761 "fgl.yacc"
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
#line 5778 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1094:
#line 5790 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1095:
#line 5790 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1096:
#line 5796 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1097:
#line 5796 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1098:
#line 5799 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1099:
#line 5799 "fgl.yacc"
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
#line 5815 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1101:
#line 5816 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1102:
#line 5817 "fgl.yacc"
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
#line 5826 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1104:
#line 5838 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1110:
#line 5849 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1111:
#line 5854 "fgl.yacc"
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
#line 5874 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1113:
#line 5879 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1114:
#line 5885 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1115:
#line 5886 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1116:
#line 5887 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1117:
#line 5891 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1118:
#line 5892 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1119:
#line 5893 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1120:
#line 5894 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1121:
#line 5898 "fgl.yacc"
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
#line 5908 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1123:
#line 5910 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1124:
#line 5915 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1125:
#line 5918 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1126:
#line 5923 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1127:
#line 5930 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1128:
#line 5937 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1129:
#line 5944 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1130:
#line 5953 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1131:
#line 5960 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1132:
#line 5967 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1133:
#line 5974 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1134:
#line 5981 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1139:
#line 5994 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1140:
#line 5995 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1141:
#line 5996 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 5997 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 5998 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 5999 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1145:
#line 6000 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1146:
#line 6001 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1147:
#line 6002 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1148:
#line 6003 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1151:
#line 6009 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1152:
#line 6010 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1153:
#line 6011 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1154:
#line 6012 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1159:
#line 6021 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1160:
#line 6022 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1161:
#line 6023 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1162:
#line 6024 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6025 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6026 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6027 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1166:
#line 6028 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6030 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1168:
#line 6031 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1169:
#line 6032 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1170:
#line 6033 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1171:
#line 6035 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1172:
#line 6036 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1173:
#line 6037 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1174:
#line 6038 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1178:
#line 6043 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1179:
#line 6044 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1183:
#line 6051 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1184:
#line 6059 "fgl.yacc"
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
#line 6067 "fgl.yacc"
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
#line 6079 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1187:
#line 6088 "fgl.yacc"
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
#line 6099 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1189:
#line 6103 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1190:
#line 6107 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1191:
#line 6113 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1192:
#line 6118 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1193:
#line 6126 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1194:
#line 6129 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1195:
#line 6138 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1196:
#line 6149 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1198:
#line 6156 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1199:
#line 6164 "fgl.yacc"
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
#line 6174 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1201:
#line 6177 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1202:
#line 6181 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1203:
#line 6189 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1204:
#line 6192 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1205:
#line 6198 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1206:
#line 6202 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1207:
#line 6206 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1208:
#line 6210 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1209:
#line 6214 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1210:
#line 6220 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1211:
#line 6221 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1212:
#line 6222 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1213:
#line 6223 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1214:
#line 6228 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1215:
#line 6230 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1216:
#line 6233 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1217:
#line 6237 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1218:
#line 6240 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1219:
#line 6247 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1220:
#line 6252 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1221:
#line 6253 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1222:
#line 6254 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1223:
#line 6259 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1224:
#line 6260 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1225:
#line 6266 "fgl.yacc"
    {insql=1;}
    break;

  case 1226:
#line 6266 "fgl.yacc"
    {insql=0;}
    break;

  case 1227:
#line 6266 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1228:
#line 6271 "fgl.yacc"
    {insql=1;}
    break;

  case 1229:
#line 6271 "fgl.yacc"
    {insql=0;}
    break;

  case 1230:
#line 6271 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1231:
#line 6282 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1232:
#line 6283 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1233:
#line 6289 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1234:
#line 6291 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1236:
#line 6304 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1237:
#line 6308 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1238:
#line 6309 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1240:
#line 6314 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1241:
#line 6317 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1242:
#line 6323 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6326 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1244:
#line 6334 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1246:
#line 6341 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1247:
#line 6348 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6351 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1249:
#line 6360 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6363 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1251:
#line 6366 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1252:
#line 6369 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1253:
#line 6372 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1254:
#line 6375 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6378 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6385 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1257:
#line 6388 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1258:
#line 6395 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 6398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1260:
#line 6404 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 6407 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1262:
#line 6414 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1263:
#line 6417 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1265:
#line 6425 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1267:
#line 6434 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1268:
#line 6437 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1269:
#line 6443 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1270:
#line 6446 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1271:
#line 6452 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1272:
#line 6459 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1273:
#line 6460 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1274:
#line 6464 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1275:
#line 6470 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1276:
#line 6473 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1278:
#line 6481 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1279:
#line 6488 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1280:
#line 6491 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1284:
#line 6509 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1290:
#line 6515 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1291:
#line 6518 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1292:
#line 6521 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1293:
#line 6527 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1295:
#line 6533 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1297:
#line 6544 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1298:
#line 6558 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1299:
#line 6567 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1300:
#line 6567 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1301:
#line 6572 "fgl.yacc"
    {insql=1;}
    break;

  case 1302:
#line 6572 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1303:
#line 6577 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1304:
#line 6580 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1305:
#line 6582 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6589 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1308:
#line 6593 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1309:
#line 6597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1310:
#line 6604 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1311:
#line 6607 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1312:
#line 6614 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1313:
#line 6618 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1314:
#line 6622 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1315:
#line 6627 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1316:
#line 6632 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1317:
#line 6636 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1318:
#line 6642 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1319:
#line 6646 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1320:
#line 6652 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1321:
#line 6659 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1322:
#line 6663 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1323:
#line 6668 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1324:
#line 6678 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1325:
#line 6681 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1326:
#line 6683 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1327:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1328:
#line 6687 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1329:
#line 6689 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1330:
#line 6691 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6693 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1332:
#line 6699 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1333:
#line 6709 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1334:
#line 6716 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1336:
#line 6722 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6731 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1343:
#line 6736 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1344:
#line 6741 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1345:
#line 6748 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1346:
#line 6749 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1347:
#line 6756 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1348:
#line 6767 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1349:
#line 6768 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1350:
#line 6771 "fgl.yacc"
    {insql=1;}
    break;

  case 1351:
#line 6771 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1352:
#line 6776 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1353:
#line 6781 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1355:
#line 6787 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1357:
#line 6791 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1358:
#line 6796 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1359:
#line 6801 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1360:
#line 6805 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1362:
#line 6811 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1363:
#line 6815 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1364:
#line 6823 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1365:
#line 6826 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1366:
#line 6828 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1367:
#line 6833 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1370:
#line 6840 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6847 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1375:
#line 6850 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6852 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1378:
#line 6858 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6864 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6874 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1384:
#line 6879 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1385:
#line 6881 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1387:
#line 6887 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6890 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1390:
#line 6896 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1391:
#line 6904 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6909 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6919 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6925 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1398:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6933 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6939 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6944 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1403:
#line 6947 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1404:
#line 6950 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1405:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6960 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1407:
#line 6973 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1408:
#line 6978 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1410:
#line 6982 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1411:
#line 6984 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1412:
#line 6991 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1413:
#line 6994 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1414:
#line 7000 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1415:
#line 7004 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1416:
#line 7008 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1417:
#line 7012 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1418:
#line 7015 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1419:
#line 7023 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1420:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1423:
#line 7039 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1424:
#line 7045 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1425:
#line 7048 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1426:
#line 7059 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1427:
#line 7066 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1428:
#line 7072 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1429:
#line 7075 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 7082 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1431:
#line 7089 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1433:
#line 7096 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1434:
#line 7102 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1435:
#line 7103 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 7104 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1438:
#line 7108 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1440:
#line 7113 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1441:
#line 7120 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1442:
#line 7125 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1443:
#line 7126 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1444:
#line 7129 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1445:
#line 7132 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1446:
#line 7137 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1447:
#line 7138 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1448:
#line 7143 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1449:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1450:
#line 7152 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1451:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1452:
#line 7161 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1453:
#line 7164 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 7170 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1455:
#line 7173 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1456:
#line 7180 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1457:
#line 7181 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1458:
#line 7210 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1459:
#line 7212 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1460:
#line 7216 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1462:
#line 7229 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1463:
#line 7232 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1464:
#line 7235 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1465:
#line 7238 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1467:
#line 7246 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1468:
#line 7249 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1470:
#line 7255 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1472:
#line 7261 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1473:
#line 7264 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1474:
#line 7267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1475:
#line 7270 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1476:
#line 7273 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1477:
#line 7276 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1478:
#line 7279 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1479:
#line 7282 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1480:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7294 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1488:
#line 7302 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1489:
#line 7303 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1490:
#line 7308 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1491:
#line 7311 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1492:
#line 7315 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1493:
#line 7321 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1494:
#line 7322 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1495:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1496:
#line 7324 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1501:
#line 7344 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1502:
#line 7349 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1503:
#line 7350 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1505:
#line 7353 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1509:
#line 7358 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7361 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1513:
#line 7364 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1517:
#line 7369 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7371 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1519:
#line 7374 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1520:
#line 7375 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1521:
#line 7382 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1525:
#line 7387 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1529:
#line 7403 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1530:
#line 7404 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1531:
#line 7408 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1532:
#line 7409 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1534:
#line 7428 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1535:
#line 7429 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1536:
#line 7430 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1537:
#line 7434 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1538:
#line 7437 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1539:
#line 7443 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1540:
#line 7448 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1541:
#line 7453 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1543:
#line 7464 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1548:
#line 7479 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1549:
#line 7482 "fgl.yacc"
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
#line 7495 "fgl.yacc"
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
#line 7510 "fgl.yacc"
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
#line 7522 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1553:
#line 7524 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1554:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1555:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1556:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1557:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1558:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1559:
#line 7527 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1560:
#line 7528 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1561:
#line 7531 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1562:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1563:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1564:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1565:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1566:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1567:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1568:
#line 7538 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1569:
#line 7541 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1584:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1585:
#line 7551 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1586:
#line 7555 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1587:
#line 7563 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1588:
#line 7563 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1589:
#line 7569 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1590:
#line 7569 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1591:
#line 7576 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1592:
#line 7576 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1593:
#line 7582 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1594:
#line 7582 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
		doing_declare=0;
	}
    break;

  case 1595:
#line 7590 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1596:
#line 7591 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1597:
#line 7592 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1601:
#line 7599 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1602:
#line 7600 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7605 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1604:
#line 7608 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1605:
#line 7614 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1606:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1607:
#line 7628 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1608:
#line 7640 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1609:
#line 7641 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1610:
#line 7644 "fgl.yacc"
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
#line 7659 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1612:
#line 7669 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1613:
#line 7672 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1614:
#line 7680 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1615:
#line 7689 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1616:
#line 7692 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1617:
#line 7696 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1618:
#line 7699 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1619:
#line 7700 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1621:
#line 7709 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1622:
#line 7710 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1623:
#line 7719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1624:
#line 7728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1625:
#line 7733 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1626:
#line 7734 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1627:
#line 7735 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1628:
#line 7736 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1629:
#line 7743 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1630:
#line 7746 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1631:
#line 7752 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1632:
#line 7755 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1633:
#line 7765 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1634:
#line 7774 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1635:
#line 7777 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1636:
#line 7780 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1637:
#line 7786 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7792 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1639:
#line 7795 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7798 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1641:
#line 7801 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1642:
#line 7808 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1643:
#line 7810 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1644:
#line 7812 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1645:
#line 7814 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1646:
#line 7816 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1647:
#line 7817 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1648:
#line 7818 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1649:
#line 7819 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1650:
#line 7820 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1651:
#line 7821 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1652:
#line 7822 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1653:
#line 7824 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1654:
#line 7826 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1655:
#line 7828 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1656:
#line 7830 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1657:
#line 7832 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1658:
#line 7834 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1659:
#line 7836 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7837 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7839 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7843 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1663:
#line 7844 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1665:
#line 7854 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1666:
#line 7863 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1667:
#line 7867 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1668:
#line 7874 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1669:
#line 7874 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1671:
#line 7878 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1672:
#line 7883 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1673:
#line 7883 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1675:
#line 7887 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1676:
#line 7891 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1679:
#line 7900 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1680:
#line 7900 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1685:
#line 7919 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1686:
#line 7920 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1689:
#line 7928 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1690:
#line 7934 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1693:
#line 7953 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1694:
#line 7954 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1695:
#line 7955 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1696:
#line 7956 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1697:
#line 7957 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1698:
#line 7958 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1699:
#line 7962 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1700:
#line 7963 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1701:
#line 7964 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1702:
#line 7968 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1703:
#line 7972 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1705:
#line 7981 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1707:
#line 7986 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1708:
#line 7987 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2029:
#line 8315 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2030:
#line 8315 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2031:
#line 8322 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2032:
#line 8322 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2033:
#line 8410 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2034:
#line 8414 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2035:
#line 8416 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2036:
#line 8423 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2037:
#line 8427 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2038:
#line 8433 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2039:
#line 8441 "fgl.yacc"
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
#line 8451 "fgl.yacc"
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
#line 8461 "fgl.yacc"
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
#line 8473 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2043:
#line 8476 "fgl.yacc"
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
#line 8495 "fgl.yacc"
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
#line 8521 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2046:
#line 8524 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2048:
#line 8533 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2049:
#line 8538 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2050:
#line 8541 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2051:
#line 8549 "fgl.yacc"
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
#line 8557 "fgl.yacc"
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
#line 8570 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2054:
#line 8573 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2055:
#line 8581 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2056:
#line 8584 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2057:
#line 8587 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2058:
#line 8595 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2059:
#line 8599 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2060:
#line 8602 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2061:
#line 8605 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2062:
#line 8608 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2063:
#line 8612 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2064:
#line 8613 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2065:
#line 8614 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2066:
#line 8615 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2067:
#line 8616 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2068:
#line 8622 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2069:
#line 8623 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2070:
#line 8624 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2071:
#line 8625 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2072:
#line 8626 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2073:
#line 8627 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2074:
#line 8628 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2075:
#line 8629 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2076:
#line 8630 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2077:
#line 8631 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2078:
#line 8632 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2079:
#line 8633 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8634 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8635 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8639 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2083:
#line 8645 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2084:
#line 8646 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2085:
#line 8659 "fgl.yacc"
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
#line 8679 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2090:
#line 8685 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2091:
#line 8686 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2095:
#line 8698 "fgl.yacc"
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
#line 8724 "fgl.yacc"
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
printf("THRU : %s %s\n",yyvsp[-2].str,yyvsp[0].str);

A4GL_debug("Starting THRU");

sprintf(buff,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
a=get_bind_cnt('i');
printf("get_bind_cnt=%d\n",a);
z=add_bind('i',buff);
z-=a;
for (a=0;a<z;a++)  {
         if (strlen(was_str)) {strcat(was_str,",");}
         strcat(was_str,"?");
}


	/* split_record(buff,&v_r,&v_1,&v_2);

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
*/
	yyval.sql_string=strdup(was_str);
}
    break;

  case 2097:
#line 8789 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2098:
#line 8791 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2099:
#line 8793 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2100:
#line 8794 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2101:
#line 8799 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2102:
#line 8804 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2103:
#line 8805 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2104:
#line 8809 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2105:
#line 8811 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2106:
#line 8813 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2107:
#line 8816 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2108:
#line 8820 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2109:
#line 8825 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2110:
#line 8830 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2111:
#line 8834 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2113:
#line 8844 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2115:
#line 8859 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2116:
#line 8862 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2117:
#line 8866 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2120:
#line 8885 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2121:
#line 8886 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2122:
#line 8889 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2123:
#line 8890 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2124:
#line 8891 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2125:
#line 8892 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2126:
#line 8893 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2127:
#line 8894 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2128:
#line 8895 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2129:
#line 8900 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2130:
#line 8901 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2131:
#line 8905 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2132:
#line 8909 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2133:
#line 8913 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2134:
#line 8917 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2135:
#line 8922 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2136:
#line 8926 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2137:
#line 8931 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2139:
#line 8939 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2141:
#line 8945 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2142:
#line 8951 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2143:
#line 8955 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2148:
#line 8973 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2149:
#line 8980 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2150:
#line 8989 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2151:
#line 8989 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18047 "y.tab.c"

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


#line 9087 "fgl.yacc"

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



