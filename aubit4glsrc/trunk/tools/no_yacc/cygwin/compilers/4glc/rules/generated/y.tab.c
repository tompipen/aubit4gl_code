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
     NAME = 1668,
     UMINUS = 1669,
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
     NUMBER_VALUE = 1670,
     CHAR_VALUE = 1671,
     INT_VALUE = 1672,
     NAMED_GEN = 1673,
     CLINE = 1674,
     SQLLINE = 1675,
     KW_CSTART = 1676,
     KW_CEND = 1677,
     USER_DTYPE = 1678,
     SQL_TEXT = 1679,
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
     ILIKE = 1664,
     FGL_ISDYNARR_ALLOCATED = 1665,
     FGL_DYNARR_EXTENTSIZE = 1666
   };
#endif
#define NAME 1668
#define UMINUS 1669
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
#define NUMBER_VALUE 1670
#define CHAR_VALUE 1671
#define INT_VALUE 1672
#define NAMED_GEN 1673
#define CLINE 1674
#define SQLLINE 1675
#define KW_CSTART 1676
#define KW_CEND 1677
#define USER_DTYPE 1678
#define SQL_TEXT 1679
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
#define FGL_ISDYNARR_ALLOCATED 1665
#define FGL_DYNARR_EXTENTSIZE 1666




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
#line 1607 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1619 "y.tab.c"

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
#define YYLAST   10084

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  682
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  839
/* YYNRULES -- Number of rules. */
#define YYNRULES  2252
/* YYNRULES -- Number of states. */
#define YYNSTATES  3540

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1679

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
     675,   676,   677,   678,   679,   680,   681,     2,     3,     4,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33
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
    1054,  1056,  1058,  1061,  1062,  1066,  1067,  1071,  1072,  1076,
    1079,  1082,  1085,  1090,  1096,  1098,  1100,  1102,  1104,  1106,
    1108,  1110,  1112,  1114,  1116,  1118,  1120,  1122,  1124,  1126,
    1128,  1130,  1132,  1135,  1137,  1139,  1141,  1143,  1146,  1148,
    1150,  1152,  1155,  1158,  1160,  1162,  1164,  1166,  1168,  1170,
    1172,  1174,  1176,  1178,  1181,  1183,  1186,  1188,  1190,  1192,
    1196,  1198,  1202,  1204,  1208,  1210,  1212,  1214,  1217,  1219,
    1221,  1225,  1230,  1235,  1238,  1241,  1243,  1245,  1247,  1249,
    1251,  1255,  1257,  1260,  1263,  1265,  1266,  1270,  1273,  1276,
    1278,  1282,  1287,  1292,  1298,  1304,  1306,  1308,  1311,  1314,
    1319,  1324,  1327,  1330,  1335,  1340,  1342,  1345,  1348,  1351,
    1354,  1357,  1360,  1363,  1366,  1369,  1372,  1375,  1378,  1381,
    1384,  1385,  1386,  1387,  1394,  1395,  1396,  1405,  1406,  1407,
    1414,  1415,  1416,  1423,  1424,  1425,  1432,  1433,  1434,  1441,
    1447,  1453,  1459,  1467,  1472,  1479,  1480,  1484,  1486,  1488,
    1493,  1498,  1503,  1508,  1513,  1518,  1520,  1522,  1524,  1526,
    1531,  1536,  1539,  1542,  1545,  1548,  1551,  1553,  1555,  1558,
    1560,  1562,  1564,  1567,  1572,  1579,  1586,  1590,  1596,  1602,
    1606,  1608,  1610,  1614,  1616,  1620,  1621,  1622,  1634,  1635,
    1638,  1639,  1640,  1641,  1651,  1652,  1656,  1657,  1658,  1669,
    1670,  1672,  1673,  1675,  1677,  1680,  1681,  1685,  1686,  1690,
    1691,  1693,  1695,  1698,  1699,  1703,  1704,  1708,  1712,  1714,
    1719,  1723,  1725,  1729,  1731,  1735,  1737,  1741,  1743,  1746,
    1747,  1751,  1752,  1756,  1757,  1762,  1763,  1768,  1769,  1774,
    1777,  1781,  1783,  1787,  1789,  1791,  1793,  1795,  1797,  1799,
    1801,  1805,  1807,  1809,  1814,  1821,  1826,  1830,  1837,  1841,
    1848,  1850,  1852,  1854,  1856,  1858,  1860,  1861,  1864,  1866,
    1868,  1870,  1875,  1877,  1879,  1881,  1886,  1890,  1897,  1901,
    1908,  1910,  1912,  1915,  1918,  1921,  1923,  1927,  1929,  1932,
    1935,  1938,  1943,  1946,  1949,  1954,  1955,  1964,  1965,  1967,
    1969,  1971,  1972,  1974,  1977,  1978,  1980,  1983,  1984,  1986,
    1989,  1990,  1992,  1996,  1997,  2000,  2001,  2002,  2011,  2012,
    2013,  2017,  2018,  2019,  2027,  2033,  2036,  2039,  2040,  2046,
    2051,  2053,  2057,  2061,  2065,  2066,  2069,  2071,  2072,  2074,
    2076,  2079,  2080,  2085,  2086,  2091,  2092,  2096,  2097,  2101,
    2102,  2106,  2107,  2111,  2112,  2116,  2117,  2121,  2122,  2126,
    2127,  2131,  2132,  2136,  2138,  2142,  2144,  2148,  2151,  2156,
    2158,  2160,  2162,  2163,  2168,  2174,  2181,  2182,  2193,  2197,
    2200,  2203,  2205,  2207,  2208,  2211,  2213,  2216,  2220,  2224,
    2228,  2232,  2234,  2236,  2238,  2240,  2241,  2245,  2247,  2248,
    2252,  2255,  2258,  2260,  2264,  2266,  2270,  2272,  2274,  2276,
    2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2294,  2296,
    2298,  2300,  2302,  2304,  2306,  2308,  2310,  2311,  2312,  2320,
    2322,  2324,  2327,  2330,  2333,  2337,  2342,  2343,  2347,  2348,
    2350,  2352,  2355,  2357,  2359,  2361,  2363,  2364,  2366,  2368,
    2371,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,
    2392,  2394,  2396,  2398,  2400,  2401,  2403,  2405,  2407,  2409,
    2411,  2412,  2413,  2414,  2415,  2429,  2431,  2432,  2433,  2440,
    2443,  2445,  2448,  2451,  2454,  2456,  2458,  2461,  2463,  2465,
    2467,  2468,  2472,  2475,  2477,  2478,  2479,  2480,  2495,  2496,
    2502,  2504,  2505,  2509,  2510,  2518,  2519,  2525,  2527,  2530,
    2531,  2533,  2535,  2537,  2538,  2540,  2542,  2545,  2548,  2551,
    2553,  2555,  2557,  2559,  2563,  2565,  2567,  2568,  2569,  2577,
    2579,  2582,  2583,  2587,  2588,  2593,  2596,  2597,  2600,  2602,
    2604,  2606,  2608,  2610,  2612,  2614,  2618,  2619,  2621,  2623,
    2625,  2627,  2630,  2633,  2636,  2642,  2651,  2653,  2655,  2657,
    2662,  2667,  2669,  2671,  2673,  2675,  2678,  2681,  2685,  2692,
    2694,  2698,  2700,  2702,  2704,  2708,  2715,  2725,  2727,  2729,
    2731,  2733,  2736,  2737,  2739,  2741,  2745,  2747,  2751,  2753,
    2757,  2759,  2763,  2765,  2767,  2769,  2771,  2775,  2777,  2781,
    2783,  2787,  2789,  2791,  2793,  2797,  2800,  2801,  2803,  2805,
    2810,  2812,  2816,  2818,  2822,  2830,  2831,  2839,  2840,  2847,
    2851,  2853,  2857,  2859,  2862,  2868,  2869,  2877,  2878,  2881,
    2882,  2884,  2890,  2893,  2899,  2900,  2906,  2913,  2918,  2919,
    2921,  2923,  2928,  2929,  2932,  2933,  2939,  2944,  2947,  2949,
    2953,  2956,  2959,  2962,  2965,  2968,  2971,  2973,  2976,  2979,
    2982,  2985,  2988,  2991,  2994,  2997,  3000,  3002,  3004,  3006,
    3008,  3010,  3012,  3018,  3020,  3022,  3025,  3030,  3033,  3035,
    3036,  3048,  3049,  3052,  3058,  3059,  3061,  3062,  3065,  3067,
    3070,  3071,  3075,  3077,  3078,  3083,  3084,  3087,  3089,  3093,
    3095,  3097,  3101,  3106,  3111,  3114,  3116,  3118,  3120,  3121,
    3123,  3131,  3134,  3137,  3140,  3143,  3146,  3148,  3151,  3152,
    3156,  3157,  3161,  3162,  3166,  3167,  3171,  3172,  3176,  3177,
    3182,  3183,  3188,  3190,  3192,  3194,  3196,  3198,  3200,  3201,
    3206,  3207,  3209,  3210,  3215,  3217,  3220,  3223,  3226,  3227,
    3229,  3231,  3234,  3237,  3238,  3241,  3245,  3249,  3255,  3256,
    3259,  3264,  3266,  3268,  3270,  3272,  3274,  3275,  3277,  3279,
    3283,  3286,  3292,  3295,  3301,  3307,  3313,  3319,  3325,  3331,
    3332,  3335,  3337,  3340,  3343,  3346,  3349,  3352,  3355,  3357,
    3360,  3363,  3366,  3369,  3371,  3374,  3377,  3380,  3383,  3385,
    3387,  3389,  3390,  3393,  3396,  3399,  3402,  3405,  3408,  3411,
    3414,  3417,  3419,  3421,  3423,  3425,  3427,  3429,  3431,  3433,
    3436,  3439,  3442,  3445,  3448,  3450,  3452,  3454,  3455,  3459,
    3462,  3463,  3464,  3465,  3466,  3467,  3468,  3484,  3485,  3488,
    3491,  3492,  3494,  3495,  3496,  3497,  3498,  3499,  3500,  3516,
    3519,  3520,  3521,  3522,  3533,  3534,  3536,  3540,  3544,  3547,
    3552,  3556,  3560,  3564,  3566,  3568,  3570,  3572,  3574,  3576,
    3577,  3578,  3586,  3587,  3588,  3597,  3601,  3604,  3605,  3607,
    3609,  3613,  3616,  3619,  3621,  3623,  3627,  3629,  3631,  3634,
    3636,  3640,  3642,  3646,  3648,  3650,  3652,  3654,  3656,  3658,
    3660,  3663,  3668,  3670,  3674,  3676,  3680,  3683,  3688,  3690,
    3694,  3696,  3699,  3704,  3706,  3710,  3712,  3714,  3716,  3719,
    3722,  3727,  3730,  3735,  3737,  3741,  3743,  3745,  3747,  3750,
    3752,  3754,  3756,  3758,  3760,  3763,  3770,  3777,  3778,  3780,
    3781,  3783,  3786,  3788,  3789,  3795,  3796,  3802,  3804,  3805,
    3809,  3811,  3815,  3817,  3821,  3823,  3825,  3826,  3827,  3833,
    3835,  3838,  3840,  3841,  3842,  3846,  3847,  3848,  3852,  3854,
    3856,  3858,  3860,  3862,  3864,  3867,  3870,  3875,  3879,  3883,
    3885,  3889,  3892,  3894,  3896,  3897,  3899,  3901,  3903,  3905,
    3906,  3908,  3912,  3914,  3918,  3920,  3921,  3925,  3927,  3929,
    3931,  3933,  3935,  3937,  3939,  3941,  3943,  3945,  3947,  3949,
    3957,  3958,  3960,  3962,  3964,  3966,  3970,  3972,  3974,  3976,
    3979,  3980,  3984,  3986,  3990,  3992,  3996,  3998,  4000,  4007,
    4008,  4012,  4014,  4018,  4019,  4021,  4026,  4032,  4035,  4037,
    4039,  4044,  4046,  4050,  4055,  4060,  4062,  4066,  4068,  4070,
    4072,  4075,  4077,  4082,  4083,  4085,  4086,  4088,  4090,  4093,
    4095,  4097,  4099,  4101,  4106,  4110,  4112,  4114,  4116,  4119,
    4121,  4123,  4126,  4129,  4131,  4135,  4138,  4141,  4143,  4147,
    4149,  4152,  4157,  4159,  4162,  4164,  4168,  4173,  4174,  4176,
    4177,  4179,  4180,  4182,  4184,  4188,  4190,  4194,  4196,  4199,
    4201,  4205,  4208,  4211,  4212,  4215,  4217,  4219,  4225,  4229,
    4235,  4239,  4241,  4245,  4247,  4249,  4250,  4252,  4256,  4260,
    4264,  4271,  4276,  4281,  4286,  4291,  4297,  4299,  4301,  4303,
    4305,  4307,  4309,  4311,  4313,  4315,  4317,  4319,  4321,  4322,
    4324,  4326,  4328,  4330,  4332,  4334,  4336,  4341,  4347,  4349,
    4355,  4361,  4363,  4365,  4367,  4372,  4374,  4379,  4381,  4389,
    4391,  4393,  4395,  4400,  4407,  4408,  4411,  4416,  4418,  4420,
    4422,  4424,  4426,  4428,  4430,  4434,  4436,  4438,  4442,  4444,
    4445,  4449,  4455,  4457,  4460,  4463,  4468,  4472,  4474,  4476,
    4478,  4480,  4482,  4484,  4487,  4490,  4491,  4495,  4496,  4500,
    4502,  4504,  4506,  4508,  4510,  4512,  4514,  4519,  4521,  4523,
    4525,  4527,  4529,  4531,  4533,  4538,  4540,  4542,  4544,  4546,
    4548,  4550,  4552,  4554,  4556,  4558,  4560,  4562,  4564,  4566,
    4568,  4572,  4574,  4578,  4579,  4587,  4588,  4597,  4598,  4605,
    4606,  4615,  4616,  4618,  4621,  4623,  4627,  4629,  4633,  4639,
    4641,  4643,  4645,  4647,  4649,  4650,  4651,  4661,  4667,  4669,
    4671,  4678,  4679,  4683,  4685,  4689,  4694,  4696,  4697,  4700,
    4705,  4712,  4713,  4715,  4717,  4719,  4721,  4725,  4727,  4730,
    4732,  4734,  4737,  4740,  4742,  4744,  4746,  4749,  4754,  4758,
    4761,  4765,  4769,  4773,  4775,  4777,  4779,  4781,  4783,  4785,
    4791,  4797,  4803,  4809,  4815,  4820,  4825,  4829,  4834,  4836,
    4840,  4842,  4848,  4856,  4862,  4863,  4866,  4868,  4870,  4871,
    4875,  4877,  4881,  4883,  4885,  4887,  4888,  4892,  4894,  4896,
    4898,  4900,  4905,  4912,  4914,  4916,  4919,  4923,  4925,  4927,
    4929,  4931,  4933,  4935,  4937,  4939,  4945,  4951,  4956,  4957,
    4962,  4964,  4967,  4969,  4971,  4973,  4975,  4977,  4979,  4981,
    4983,  4985,  4987,  4989,  4991,  4993,  4995,  4997,  4999,  5001,
    5003,  5005,  5007,  5009,  5011,  5013,  5015,  5017,  5019,  5021,
    5023,  5025,  5027,  5029,  5031,  5033,  5035,  5037,  5039,  5041,
    5043,  5045,  5047,  5049,  5051,  5053,  5055,  5057,  5059,  5061,
    5063,  5065,  5067,  5069,  5071,  5073,  5075,  5077,  5079,  5081,
    5083,  5085,  5087,  5089,  5091,  5093,  5095,  5097,  5099,  5101,
    5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,  5119,  5121,
    5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,  5139,  5141,
    5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,  5159,  5161,
    5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,  5179,  5181,
    5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,  5199,  5201,
    5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,  5219,  5221,
    5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,  5239,  5241,
    5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,  5259,  5261,
    5263,  5265,  5267,  5269,  5271,  5273,  5275,  5277,  5279,  5281,
    5283,  5285,  5287,  5289,  5291,  5293,  5295,  5297,  5299,  5301,
    5303,  5305,  5307,  5309,  5311,  5313,  5315,  5317,  5319,  5321,
    5323,  5325,  5327,  5329,  5331,  5333,  5335,  5337,  5339,  5341,
    5343,  5345,  5347,  5349,  5351,  5353,  5355,  5357,  5359,  5361,
    5363,  5365,  5367,  5369,  5371,  5373,  5375,  5377,  5379,  5381,
    5383,  5385,  5387,  5389,  5391,  5393,  5395,  5397,  5399,  5401,
    5403,  5405,  5407,  5409,  5411,  5413,  5415,  5417,  5419,  5421,
    5423,  5425,  5427,  5429,  5431,  5433,  5435,  5437,  5439,  5441,
    5443,  5445,  5447,  5449,  5451,  5453,  5455,  5457,  5459,  5461,
    5463,  5465,  5467,  5469,  5471,  5473,  5475,  5477,  5479,  5481,
    5483,  5485,  5487,  5489,  5491,  5493,  5495,  5497,  5499,  5501,
    5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,  5519,  5521,
    5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,  5539,  5541,
    5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,  5559,  5561,
    5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,  5579,  5581,
    5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,  5599,  5601,
    5603,  5605,  5607,  5609,  5611,  5613,  5614,  5618,  5619,  5623,
    5624,  5625,  5632,  5633,  5636,  5639,  5647,  5651,  5655,  5658,
    5661,  5664,  5666,  5670,  5672,  5676,  5678,  5682,  5684,  5688,
    5690,  5692,  5694,  5697,  5700,  5702,  5704,  5707,  5712,  5714,
    5716,  5718,  5720,  5722,  5724,  5728,  5731,  5735,  5739,  5743,
    5749,  5755,  5761,  5767,  5773,  5778,  5783,  5787,  5792,  5794,
    5796,  5800,  5801,  5807,  5809,  5813,  5817,  5821,  5823,  5826,
    5828,  5830,  5832,  5836,  5842,  5844,  5846,  5848,  5850,  5854,
    5857,  5860,  5863,  5865,  5868,  5871,  5873,  5876,  5879,  5882,
    5884,  5888,  5891,  5893,  5896,  5898,  5901,  5903,  5904,  5905,
    5912,  5913,  5916,  5917,  5919,  5921,  5924,  5927,  5929,  5931,
    5936,  5940,  5942,  5946,  5948,  5951,  5957,  5960,  5963,  5969,
    5970,  5973,  5975,  5977,  5980,  5987,  5994,  5996,  5997,  5999,
    6002,  6004,  6007,  6008,  6011,  6013,  6015,  6017,  6019,  6021,
    6023,  6025,  6027,  6029,  6031,  6033,  6035,  6037,  6039,  6041,
    6043,  6045,  6047,  6049,  6051,  6053,  6055,  6057,  6059,  6061,
    6063,  6065,  6067,  6069,  6071,  6073,  6075,  6077,  6079,  6081,
    6083,  6085,  6087,  6089,  6091,  6093,  6095,  6097,  6099,  6101,
    6103,  6105,  6107,  6109,  6111,  6113,  6115,  6117,  6119,  6121,
    6123,  6125,  6127,  6129,  6131,  6133,  6135,  6137,  6139,  6141,
    6143,  6145,  6147,  6149,  6151,  6153,  6155,  6157,  6159,  6161,
    6163,  6165,  6167,  6169,  6171,  6173,  6175,  6177,  6179,  6181,
    6183,  6185,  6187
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1045,     0,    -1,   205,    -1,   202,    -1,   129,   687,   432,
     601,   688,    -1,   143,    -1,  1110,    -1,    26,    -1,   689,
      -1,   688,     5,   689,    -1,   957,    -1,   436,   690,   397,
      -1,   690,   691,   690,    -1,    26,    -1,   692,    26,    -1,
    1110,    -1,   899,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    18,    -1,    19,    -1,    -1,   694,
      -1,    -1,   279,   436,   695,   696,   397,    -1,   574,   436,
      26,     5,    26,   397,    -1,   697,    -1,   696,     5,   697,
      -1,   495,    -1,   536,    -1,   542,    -1,   511,    -1,   415,
      -1,   610,    -1,   533,    -1,   485,    -1,   422,    -1,   496,
      -1,   350,    -1,   537,    -1,   461,    -1,   337,    -1,   599,
      -1,   103,    -1,  1024,    -1,    -1,   699,    -1,    -1,   279,
     436,   700,   701,   397,    -1,   702,    -1,   701,     5,   702,
      -1,   697,    -1,   437,    -1,   608,    25,    -1,   208,   944,
      -1,   334,   944,    -1,   289,   944,    -1,   342,   944,    -1,
     298,   944,    -1,   264,   944,    -1,   539,   704,    -1,   888,
     349,  1110,    -1,    -1,   294,   436,  1505,   397,   349,   705,
    1129,    -1,   109,   436,   957,     5,    25,     5,    25,   397,
      -1,   412,   436,   949,   397,   349,  1110,    -1,  1248,    -1,
     197,   436,   907,   397,   349,  1110,    -1,    -1,    -1,  1110,
     595,   957,   436,   706,   720,   397,   707,   718,    -1,    -1,
      -1,    -1,   957,   436,   708,   720,   709,   397,   710,   718,
      -1,    -1,    -1,   479,  1446,   628,  1446,   436,   711,   720,
     712,   397,   718,    -1,    -1,    -1,   957,   526,   957,   436,
     713,   720,   714,   397,   718,    -1,    -1,    -1,    -1,   370,
     723,   595,   724,   464,   687,   432,   436,   715,   720,   716,
     397,   717,   719,    -1,    -1,   349,  1129,    -1,    -1,   349,
    1129,    -1,   167,    -1,    -1,   721,    -1,   722,    -1,   721,
       5,   722,    -1,   857,    -1,    25,    -1,   957,    -1,   957,
      -1,   957,   625,   957,    -1,    -1,   540,   864,   726,   729,
     733,   730,    -1,    -1,   540,   727,   728,   731,   730,    -1,
     735,    -1,   728,   735,    -1,   737,    -1,   729,   737,    -1,
     365,    -1,    -1,    -1,   344,   732,  1515,    -1,    -1,    -1,
     344,   734,  1515,    -1,    -1,   584,   864,   736,  1515,    -1,
      -1,   584,   864,   738,  1515,    -1,   283,   954,    -1,   207,
     952,    -1,    88,   952,    -1,   173,    -1,   190,  1452,    -1,
     499,   951,    -1,    30,   741,    31,    -1,   742,    -1,   744,
      -1,   743,    -1,   742,   743,    -1,    29,    -1,   745,    -1,
     744,   745,    -1,    28,    -1,   399,    -1,    -1,    -1,   325,
     748,   750,   749,   751,    -1,   390,  1110,   630,   752,   998,
    1023,   693,    -1,  1110,   630,   752,   998,   552,  1505,  1023,
     693,    -1,    -1,   754,   196,    -1,   753,    -1,   752,     5,
     753,    -1,   957,    -1,   957,   625,   957,    -1,   957,   625,
      20,    -1,   755,    -1,   754,   755,    -1,    -1,   275,   761,
     756,  1515,    -1,    -1,   278,   762,   757,  1515,    -1,    -1,
    1026,   758,  1515,    -1,    -1,   171,   759,  1515,    -1,    -1,
     168,   760,  1515,    -1,   961,    -1,   761,     5,   961,    -1,
     961,    -1,   762,     5,   961,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   436,   857,
     765,   397,    -1,    -1,     5,   808,   631,   811,    -1,   160,
      -1,   284,    -1,    -1,   768,    -1,   769,    -1,   768,   769,
      -1,    -1,    -1,   443,   770,   772,   771,  1217,    -1,   821,
      -1,  1495,    -1,   775,    -1,   772,     5,   775,    -1,    -1,
     774,   957,    -1,   358,   773,   820,    25,    -1,   358,   773,
     820,   957,    -1,   358,   773,   820,   963,    -1,   358,   773,
     820,    26,    -1,   779,   797,    -1,    -1,   773,   358,   776,
     777,    -1,    26,    -1,    25,    -1,   963,    -1,    19,    26,
      -1,   773,    -1,   778,    -1,   779,     5,   778,    -1,    -1,
     541,    -1,    -1,   675,    -1,   676,    -1,   677,    -1,    -1,
     492,   464,   789,   432,   783,   629,   797,    -1,    -1,    34,
     781,   784,   629,   797,    -1,    -1,   323,   780,   786,    26,
     787,   307,   464,   788,   432,   785,   629,   797,    -1,   436,
      -1,   463,    -1,   397,    -1,   431,    -1,    26,    -1,   790,
       5,   790,     5,   790,    -1,   790,     5,   790,    -1,   790,
      -1,    26,    -1,    -1,   469,   792,   772,   288,    -1,    -1,
     265,   793,   773,   625,    20,    -1,    -1,   339,   794,   773,
     263,   436,   795,   397,    -1,   796,    -1,   795,     5,   796,
      -1,   773,    -1,   799,    -1,    -1,    63,    -1,    -1,    -1,
     800,   802,   801,   798,    -1,   782,    -1,   791,    -1,   541,
      -1,   541,   436,    26,   397,    -1,   429,   436,    26,   397,
      -1,   429,   436,    26,     5,    26,   397,    -1,   413,    -1,
     622,   773,    -1,   385,    -1,   514,    -1,    94,    -1,   403,
      -1,   403,   436,    26,   397,    -1,   403,   436,    26,     5,
      26,   397,    -1,   517,    -1,   517,   436,    26,   397,    -1,
     517,   436,    26,     5,    26,   397,    -1,   507,    -1,   304,
      -1,   543,    -1,   538,    -1,    84,    -1,    85,    -1,   580,
      -1,   362,   806,    -1,   374,   807,    -1,   803,    -1,    32,
      -1,   562,   804,   625,   805,    -1,   773,    -1,   773,    -1,
      -1,   808,   631,   811,    -1,   816,   631,   819,    -1,    -1,
     809,   810,    -1,   587,    -1,   518,    -1,   596,    -1,   558,
      -1,   459,    -1,   475,    -1,   371,   813,    -1,    -1,   812,
     810,    -1,    -1,   436,   815,   397,    -1,    -1,   436,    26,
     397,    -1,    26,    -1,    -1,   817,   818,   814,    -1,   587,
      -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,
      -1,   371,   813,    -1,   818,    -1,    -1,    14,    -1,    -1,
     241,   957,   822,   622,   823,    -1,   825,    -1,   828,    -1,
     541,    -1,   541,   436,    26,   397,    -1,   429,   436,    26,
     397,    -1,   429,   436,    26,     5,    26,   397,    -1,   413,
      -1,   385,    -1,   514,    -1,   403,    -1,   403,   436,    26,
     397,    -1,   403,   436,    26,     5,    26,   397,    -1,   517,
      -1,   517,   436,    26,   397,    -1,   517,   436,    26,     5,
      26,   397,    -1,   507,    -1,   304,    -1,   543,    -1,   538,
      -1,   580,    -1,   362,   806,    -1,   374,   807,    -1,   824,
      -1,   562,   804,   625,   805,    -1,    -1,   492,   464,   789,
     432,   826,   629,   823,    -1,    -1,   323,   780,   786,    26,
     787,   307,   464,   788,   432,   827,   629,   823,    -1,    -1,
     469,   829,   831,   288,    -1,    -1,   265,   830,   957,   625,
      20,    -1,   832,    -1,   831,     5,   832,    -1,   833,   823,
      -1,   834,    -1,   833,     5,   834,    -1,   957,    -1,    -1,
     623,   948,    -1,    75,   957,    -1,    73,    -1,   631,  1505,
      -1,   631,   514,   957,   664,  1505,    -1,   631,   514,   957,
     395,    -1,    77,   957,    -1,   161,   882,  1129,   843,    -1,
     406,   882,   862,   835,   843,    -1,   214,   954,   843,    -1,
      -1,    -1,   193,   840,  1136,   631,   957,   625,    20,   842,
     693,   841,   844,    -1,    -1,   473,   949,    -1,   693,    -1,
      -1,   845,   243,    -1,   243,    -1,   846,    -1,   845,   846,
      -1,    -1,   356,   847,  1515,    -1,    -1,   352,   848,  1515,
      -1,    -1,  1026,   849,  1515,    -1,    36,  1110,    -1,    37,
    1110,    -1,    35,  1110,    -1,   503,   882,   863,   693,    -1,
     503,   882,   863,   693,    70,    -1,   291,    -1,   290,    -1,
     217,    -1,   369,    -1,   178,    -1,   216,    -1,   333,    -1,
     332,    -1,   248,    -1,   175,    -1,   174,    -1,   149,    -1,
     209,    -1,   132,    -1,   148,    -1,   192,    -1,   158,    -1,
     218,    -1,   218,   864,    -1,   867,    -1,   866,    -1,   871,
      -1,   899,    -1,   857,   858,    -1,   900,    -1,   902,    -1,
     868,    -1,    19,   857,    -1,    18,   857,    -1,   873,    -1,
     881,    -1,   875,    -1,   480,    -1,   763,    -1,   876,    -1,
     877,    -1,   878,    -1,   879,    -1,   880,    -1,    39,   857,
      -1,   882,    -1,   882,   861,    -1,   864,    -1,   488,    -1,
     860,    -1,   861,     5,   860,    -1,   864,    -1,   862,     5,
     864,    -1,   864,    -1,   863,     5,   864,    -1,   857,    -1,
      18,    -1,    19,    -1,     9,   857,    -1,   489,    -1,   433,
      -1,   436,   857,   397,    -1,   448,   436,  1426,   397,    -1,
     299,   436,  1426,   397,    -1,   865,   963,    -1,   865,    26,
      -1,    25,    -1,   963,    -1,    26,    -1,   870,    -1,  1110,
      -1,  1110,   426,  1110,    -1,   869,    -1,   439,   857,    -1,
     398,   857,    -1,  1220,    -1,    -1,   512,   872,  1220,    -1,
       7,   857,    -1,     6,   857,    -1,   857,    -1,   874,     5,
     857,    -1,   628,   436,  1426,   397,    -1,   434,   436,  1426,
     397,    -1,   628,   436,   882,   874,   397,    -1,   434,   436,
     882,   874,   397,    -1,   392,    -1,   254,    -1,    10,   857,
      -1,   257,   857,    -1,    10,   857,   447,    25,    -1,   257,
     857,   447,    25,    -1,   562,   857,    -1,   376,   857,    -1,
     562,   857,   447,    25,    -1,   376,   857,   447,    25,    -1,
     396,    -1,     8,   857,    -1,    18,   857,    -1,    19,   857,
      -1,    20,   857,    -1,    21,   857,    -1,    22,   857,    -1,
      11,   857,    -1,    14,   857,    -1,   462,   857,    -1,    12,
     857,    -1,    13,   857,    -1,    17,   857,    -1,    16,   857,
      -1,    15,   857,    -1,    -1,    -1,    -1,   957,   436,   884,
     720,   885,   397,    -1,    -1,    -1,   957,   526,   957,   436,
     886,   720,   887,   397,    -1,    -1,    -1,   543,   436,   889,
     857,   890,   397,    -1,    -1,    -1,   518,   436,   891,   857,
     892,   397,    -1,    -1,    -1,   596,   436,   893,   857,   894,
     397,    -1,    -1,    -1,   587,   436,   895,   857,   896,   397,
      -1,   374,   436,   903,   397,   898,    -1,   362,   436,    25,
     397,   897,    -1,   362,   436,    26,   397,   897,    -1,   362,
     436,    26,   595,    26,   397,   897,    -1,   680,   436,  1110,
     397,    -1,   681,   436,  1110,     5,    26,   397,    -1,    -1,
    1406,   631,  1407,    -1,   807,    -1,   888,    -1,   294,   436,
    1505,   397,    -1,   104,   436,   949,   397,    -1,    76,   436,
     949,   397,    -1,   412,   436,  1505,   397,    -1,   197,   436,
    1505,   397,    -1,    64,   436,  1505,   397,    -1,   901,    -1,
     883,    -1,  1402,    -1,   543,    -1,   428,   436,   857,   397,
      -1,   327,   436,   857,   397,    -1,   493,   857,    -1,   449,
     764,    -1,   857,   113,    -1,   857,   114,    -1,   857,   115,
      -1,    25,    -1,   904,    -1,    19,   904,    -1,   906,    -1,
     905,    -1,    26,    -1,    26,    26,    -1,    26,    26,   595,
      26,    -1,    26,    26,   595,    26,   595,    26,    -1,    26,
      26,   595,    26,   595,    24,    -1,    26,   595,    26,    -1,
      26,   595,    26,   595,    26,    -1,    26,   595,    26,   595,
      24,    -1,    26,   595,    24,    -1,    24,    -1,    26,    -1,
      26,    19,    26,    -1,   949,    -1,   907,     5,   949,    -1,
      -1,    -1,   601,  1110,    14,   864,   631,   864,   911,   909,
    1515,   910,   246,    -1,    -1,   577,   864,    -1,    -1,    -1,
      -1,   409,   913,   951,   914,   916,  1307,   915,  1515,   245,
      -1,    -1,     8,   882,   862,    -1,    -1,    -1,   643,   957,
     918,   767,   919,  1055,   921,   920,   926,   644,    -1,    -1,
     931,    -1,    -1,   922,    -1,   923,    -1,   922,   923,    -1,
      -1,   645,   924,  1515,    -1,    -1,   646,   925,  1515,    -1,
      -1,   927,    -1,   928,    -1,   927,   928,    -1,    -1,   647,
     929,  1515,    -1,    -1,   648,   930,  1515,    -1,   932,   936,
     329,    -1,    96,    -1,    96,   933,   552,   934,    -1,    96,
     390,   935,    -1,  1110,    -1,   933,     5,  1110,    -1,   957,
      -1,   934,     5,   957,    -1,  1110,    -1,   935,     5,  1110,
      -1,   937,    -1,   936,   937,    -1,    -1,   649,   938,  1515,
      -1,    -1,   650,   939,  1515,    -1,    -1,   669,   934,   940,
    1515,    -1,    -1,   486,   934,   941,  1515,    -1,    -1,   630,
     934,   942,  1515,    -1,   551,   950,    -1,   560,    19,    26,
      -1,   560,    -1,   506,    18,    26,    -1,   506,    -1,    26,
      -1,  1110,    -1,   674,    -1,    25,    -1,   962,    -1,   864,
      -1,   946,     5,   946,    -1,   947,    -1,   957,    -1,   672,
     436,   957,   397,    -1,   957,   625,   672,   436,   957,   397,
      -1,   957,   464,   690,   432,    -1,   957,   625,    20,    -1,
     957,   464,   690,   432,   625,    20,    -1,   957,   625,   957,
      -1,   957,   464,   690,   432,   625,   957,    -1,   958,    -1,
     958,    -1,   958,    -1,   958,    -1,   958,    -1,   958,    -1,
      -1,   556,    26,    -1,  1514,    -1,   959,    -1,  1514,    -1,
     354,   436,   960,   397,    -1,  1113,    -1,    25,    -1,   957,
      -1,   957,   464,   690,   432,    -1,   957,   625,    20,    -1,
     957,   464,   690,   432,   625,    20,    -1,   957,   625,   957,
      -1,   957,   464,   690,   432,   625,   957,    -1,  1110,    -1,
      24,    -1,   625,    26,    -1,   553,  1497,    -1,   657,   966,
      -1,   967,    -1,   966,     5,   967,    -1,   957,    -1,   668,
     966,    -1,   659,   966,    -1,   660,  1505,    -1,   658,   954,
     664,  1505,    -1,   662,   966,    -1,   663,  1505,    -1,   661,
     954,   664,  1505,    -1,    -1,   666,   972,   862,   977,   979,
     981,   973,   975,    -1,    -1,   974,    -1,   654,    -1,   655,
      -1,    -1,   976,    -1,   349,  1110,    -1,    -1,   978,    -1,
     395,   862,    -1,    -1,   980,    -1,   665,    26,    -1,    -1,
     982,    -1,   656,    26,   983,    -1,    -1,   405,    26,    -1,
      -1,    -1,   627,   864,   581,   985,  1515,   986,   987,   446,
      -1,    -1,    -1,   548,   988,  1515,    -1,    -1,    -1,    67,
     989,   864,   581,   990,  1515,   987,    -1,   111,   957,   436,
      26,   397,    -1,    60,   957,    -1,    80,   957,    -1,    -1,
     295,  1141,   994,   631,   488,    -1,   295,  1141,   562,   995,
      -1,   996,    -1,   995,     5,   996,    -1,   804,   625,  1398,
      -1,   804,   625,    20,    -1,    -1,   999,   329,    -1,   329,
      -1,    -1,   155,    -1,  1000,    -1,   999,  1000,    -1,    -1,
     275,  1012,  1001,  1515,    -1,    -1,   278,  1013,  1002,  1515,
      -1,    -1,   356,  1003,  1515,    -1,    -1,   352,  1004,  1515,
      -1,    -1,  1026,  1005,  1515,    -1,    -1,   310,  1006,  1515,
      -1,    -1,   280,  1007,  1515,    -1,    -1,    40,  1008,  1515,
      -1,    -1,    38,  1009,  1515,    -1,    -1,    42,  1010,  1515,
      -1,    -1,    41,  1011,  1515,    -1,   949,    -1,  1012,     5,
     949,    -1,   949,    -1,  1013,     5,   949,    -1,   319,  1016,
      -1,   320,   957,   664,  1016,    -1,   567,    -1,   380,    -1,
     949,    -1,    -1,   670,  1019,  1018,   997,    -1,   390,  1129,
     998,   956,   693,    -1,  1129,   998,   552,  1505,   956,   693,
      -1,    -1,   492,  1136,   998,   552,   957,   625,    20,   956,
    1020,   693,    -1,   474,  1505,  1022,    -1,    86,    26,    -1,
      87,    26,    -1,   632,    -1,   545,    -1,    -1,   556,    26,
      -1,  1025,    -1,    48,    25,    -1,   501,    14,    26,    -1,
     501,    14,  1110,    -1,    49,    14,    26,    -1,    49,    14,
    1110,    -1,    45,    -1,    47,    -1,    44,    -1,    46,    -1,
      -1,   435,  1027,  1032,    -1,   300,    -1,    -1,   602,  1029,
    1032,    -1,   308,  1034,    -1,   602,  1032,    -1,  1034,    -1,
     436,  1033,   397,    -1,  1034,    -1,  1033,     5,  1034,    -1,
    1035,    -1,   600,    -1,   317,    -1,   335,    -1,   309,    -1,
     490,    -1,   447,    -1,   632,    -1,   556,    -1,   545,    -1,
     182,    -1,   444,    -1,   455,    -1,   546,    -1,   561,    -1,
     525,    -1,   315,    -1,   316,    -1,    25,    -1,   515,    -1,
      -1,    -1,   604,  1038,  1134,  1039,    14,   882,  1040,    -1,
     488,    -1,   863,    -1,   224,  1110,    -1,   213,  1110,    -1,
     227,  1110,    -1,   456,  1110,   338,    -1,   456,  1110,   391,
     945,    -1,    -1,  1047,  1046,  1050,    -1,    -1,  1048,    -1,
    1049,    -1,  1048,  1049,    -1,   992,    -1,  1054,    -1,  1070,
      -1,  1056,    -1,    -1,  1051,    -1,  1053,    -1,  1051,  1053,
      -1,    71,   957,    -1,  1058,    -1,  1064,    -1,  1076,    -1,
    1230,    -1,  1240,    -1,  1097,    -1,  1495,    -1,   917,    -1,
     740,    -1,   991,    -1,   746,    -1,   740,    -1,  1495,    -1,
      -1,   740,    -1,  1495,    -1,   768,    -1,   372,    -1,    65,
      -1,    -1,    -1,    -1,    -1,  1057,  1059,   957,   436,  1060,
    1127,   397,  1061,   767,  1062,  1055,  1515,  1063,    -1,   215,
      -1,    -1,    -1,   563,  1065,   767,  1066,  1515,   366,    -1,
     182,   859,    -1,   882,    -1,   882,   862,    -1,   361,  1410,
      -1,   472,  1410,    -1,  1071,    -1,  1072,    -1,  1071,  1072,
      -1,  1073,    -1,  1054,    -1,  1069,    -1,    -1,   411,  1074,
    1075,    -1,   767,   247,    -1,   945,    -1,    -1,    -1,    -1,
     118,   957,   117,   957,   436,  1077,  1127,   397,  1078,   767,
    1079,  1055,  1515,  1063,    -1,    -1,   564,  1081,  1096,  1087,
    1082,    -1,   367,    -1,    -1,   239,  1084,  1515,    -1,    -1,
      23,  1088,  1089,  1090,   956,  1085,  1515,    -1,    -1,    23,
    1088,   956,  1086,  1515,    -1,  1083,    -1,  1087,  1083,    -1,
      -1,  1028,    -1,    25,    -1,  1110,    -1,    -1,  1110,    -1,
      25,    -1,   256,  1094,    -1,   268,  1095,    -1,   251,  1095,
      -1,   591,    -1,    25,    -1,  1110,    -1,  1094,    -1,  1095,
       5,  1094,    -1,  1110,    -1,    25,    -1,    -1,    -1,   651,
     957,  1098,   767,  1099,  1100,   652,    -1,  1101,    -1,  1100,
    1101,    -1,    -1,   653,  1102,  1515,    -1,    -1,   630,   957,
    1103,  1515,    -1,  1107,  1105,    -1,    -1,   694,  1108,    -1,
    1109,    -1,  1106,    -1,   978,    -1,   980,    -1,   982,    -1,
     974,    -1,   976,    -1,   375,   882,   862,    -1,    -1,    70,
      -1,    70,    -1,  1111,    -1,  1113,    -1,   195,  1113,    -1,
    1113,   625,    -1,  1112,  1117,    -1,  1112,   957,   464,  1121,
     432,    -1,  1112,   957,   464,  1121,   432,   464,  1121,   432,
      -1,  1118,    -1,   957,    -1,  1114,    -1,   957,   463,  1116,
     431,    -1,   957,   463,  1116,   431,    -1,  1110,    -1,    25,
      -1,    20,    -1,   957,    -1,   957,  1120,    -1,   957,  1120,
      -1,   464,  1121,   432,    -1,   464,  1121,   432,   464,  1121,
     432,    -1,  1122,    -1,  1121,     5,  1122,    -1,   690,    -1,
    1124,    -1,  1126,    -1,  1124,   625,  1125,    -1,  1124,   625,
     957,   464,  1121,   432,    -1,  1124,   625,   957,   464,  1121,
     432,   464,  1121,   432,    -1,   957,    -1,  1115,    -1,    20,
      -1,   957,    -1,   957,  1120,    -1,    -1,  1128,    -1,  1130,
      -1,  1128,     5,  1130,    -1,  1131,    -1,  1129,     5,  1131,
      -1,   957,    -1,   957,   625,   957,    -1,  1110,    -1,  1110,
     426,  1110,    -1,    25,    -1,   963,    -1,    26,    -1,  1133,
      -1,  1132,     5,  1133,    -1,  1110,    -1,  1110,   426,  1110,
      -1,  1135,    -1,  1134,     5,  1135,    -1,  1123,    -1,  1110,
      -1,  1138,    -1,  1137,     5,  1138,    -1,  1110,  1139,    -1,
      -1,   593,    -1,   544,    -1,   957,   464,  1121,   432,    -1,
    1142,    -1,  1141,     5,  1142,    -1,  1110,    -1,  1110,   426,
    1110,    -1,   259,   953,   623,   947,   585,  1507,   698,    -1,
      -1,   623,   436,   864,     5,   864,   397,  1145,    -1,    -1,
     574,   436,   864,     5,   864,   397,    -1,   260,   957,  1144,
      -1,   957,    -1,   343,   955,  1149,    -1,  1150,    -1,   552,
     864,    -1,  1151,  1152,  1157,     8,  1147,    -1,    -1,   623,
    1153,   436,   864,     5,   864,   397,    -1,    -1,   562,   958,
      -1,    -1,   355,    -1,   222,  1452,   271,  1490,  1156,    -1,
     569,   950,    -1,   569,   950,     8,   882,   862,    -1,    -1,
     622,   582,  1446,   379,  1446,    -1,   622,   582,  1446,     5,
     379,  1446,    -1,   622,  1446,     5,  1446,    -1,    -1,   654,
      -1,   655,    -1,    95,  1490,  1159,  1160,    -1,    -1,   622,
    1490,    -1,    -1,   622,   582,  1446,     8,  1446,    -1,   582,
    1446,     8,  1446,    -1,   417,  1162,    -1,  1163,    -1,  1162,
       5,  1163,    -1,   208,   944,    -1,   289,   944,    -1,   334,
     944,    -1,   342,   944,    -1,   298,   944,    -1,   264,   944,
      -1,  1030,    -1,   444,  1031,    -1,   455,  1031,    -1,   567,
    1031,    -1,   380,  1031,    -1,   556,  1031,    -1,   554,   945,
      -1,   555,   945,    -1,   406,   694,    -1,   670,   694,    -1,
     296,    -1,   200,    -1,   156,    -1,   133,    -1,   151,    -1,
     142,    -1,  1451,   419,  1167,   552,  1165,    -1,  1110,    -1,
      25,    -1,   408,  1167,    -1,   408,  1167,     8,  1129,    -1,
      43,  1165,    -1,   958,    -1,    -1,   467,  1177,   693,   601,
    1172,  1110,  1170,   956,   693,  1169,  1173,    -1,    -1,   673,
      26,    -1,   467,  1177,   693,   349,  1110,    -1,    -1,   541,
      -1,    -1,  1174,   287,    -1,  1175,    -1,  1174,  1175,    -1,
      -1,  1026,  1176,  1515,    -1,   863,    -1,    -1,   609,   950,
    1179,  1180,    -1,    -1,   552,  1181,    -1,  1182,    -1,  1181,
       5,  1182,    -1,  1438,    -1,   488,    -1,   225,  1185,    93,
      -1,   225,  1185,   631,  1184,    -1,   225,  1185,    92,  1184,
      -1,   225,  1185,    -1,    25,    -1,   962,    -1,   957,    -1,
      -1,   484,    -1,   150,  1185,  1186,   436,   882,  1068,   397,
      -1,   198,  1185,    -1,    72,  1185,    -1,  1221,  1229,    -1,
     452,    66,    -1,   452,  1192,    -1,  1193,    -1,  1192,  1193,
      -1,    -1,   138,  1194,  1515,    -1,    -1,   204,  1195,  1515,
      -1,    -1,   233,  1196,  1515,    -1,    -1,   221,  1197,  1515,
      -1,    -1,   258,  1198,  1515,    -1,    -1,   206,  1110,  1199,
    1515,    -1,    -1,   229,  1110,  1200,  1515,    -1,  1211,    -1,
    1213,    -1,  1212,    -1,  1202,    -1,  1238,    -1,  1205,    -1,
      -1,   566,   864,  1203,   487,    -1,    -1,   487,    -1,    -1,
     575,    26,  1206,  1204,    -1,   163,    -1,   634,  1225,    -1,
     166,  1225,    -1,   165,  1225,    -1,    -1,  1208,    -1,  1209,
      -1,  1208,  1209,    -1,  1218,  1210,    -1,    -1,   623,  1225,
      -1,   524,  1207,  1217,    -1,   523,  1446,  1217,    -1,   522,
    1216,  1215,  1214,  1217,    -1,    -1,   157,   857,    -1,   157,
     857,     5,   857,    -1,   618,    -1,   619,    -1,   620,    -1,
     621,    -1,  1110,    -1,    -1,   527,    -1,  1219,    -1,  1218,
       5,  1219,    -1,   864,  1252,    -1,   614,   436,   857,   397,
    1237,    -1,    69,  1237,    -1,   501,   436,    20,   397,  1237,
      -1,   418,   436,    20,   397,  1237,    -1,   393,   436,   857,
     397,  1237,    -1,   594,   436,   857,   397,  1237,    -1,   607,
     436,   857,   397,  1237,    -1,   606,   436,   857,   397,  1237,
      -1,    -1,   466,  1222,    -1,  1223,    -1,  1222,  1223,    -1,
     232,    26,    -1,   223,    26,    -1,   306,    26,    -1,   189,
      26,    -1,   261,    26,    -1,   180,    -1,   348,    25,    -1,
     348,  1110,    -1,   181,    25,    -1,   164,    25,    -1,  1228,
      -1,  1224,  1228,    -1,  1226,   113,    -1,  1226,   115,    -1,
    1226,   114,    -1,  1226,    -1,   963,    -1,    26,    -1,    -1,
     466,  1224,    -1,   232,  1225,    -1,   223,  1225,    -1,   306,
    1225,    -1,   189,  1225,    -1,   261,  1225,    -1,   262,  1225,
      -1,   633,    25,    -1,   634,  1225,    -1,   638,    -1,   635,
      -1,   636,    -1,   637,    -1,   642,    -1,   639,    -1,   640,
      -1,   641,    -1,    81,  1225,    -1,    82,  1225,    -1,    83,
    1225,    -1,   348,    25,    -1,   181,    25,    -1,   405,    -1,
      78,    -1,    79,    -1,    -1,   519,   624,  1137,    -1,   139,
    1137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,  1231,
     957,   436,  1232,  1127,   397,  1233,   767,  1234,  1190,  1235,
    1191,  1236,   244,    -1,    -1,   531,   857,    -1,   521,  1239,
      -1,    -1,  1165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     110,  1241,   957,   436,  1242,  1127,   397,  1243,   767,  1244,
    1247,  1245,  1191,  1246,   244,    -1,  1227,  1229,    -1,    -1,
      -1,    -1,   159,   436,    25,     5,  1249,   720,  1250,   397,
    1251,   718,    -1,    -1,   389,    -1,   389,   223,    26,    -1,
     389,   223,  1110,    -1,   612,   864,    -1,   612,   864,   349,
    1110,    -1,   612,   864,   167,    -1,   612,   864,   583,    -1,
     612,   864,   550,    -1,  1255,    -1,   177,    -1,   328,    -1,
     286,    -1,  1262,    -1,  1257,    -1,    -1,    -1,   211,  1258,
    1395,   436,  1259,  1266,   397,    -1,    -1,    -1,   136,  1260,
    1395,   436,  1261,  1266,   397,  1263,    -1,   108,  1264,   397,
      -1,    59,   958,    -1,    -1,   273,    -1,  1265,    -1,  1264,
       5,  1265,    -1,   957,   593,    -1,   957,   544,    -1,   957,
      -1,  1267,    -1,  1266,     5,  1267,    -1,  1348,    -1,  1346,
      -1,   125,   957,    -1,   184,    -1,    50,   957,  1270,    -1,
    1271,    -1,  1270,     5,  1271,    -1,  1272,    -1,  1275,    -1,
    1278,    -1,  1283,    -1,  1284,    -1,  1282,    -1,  1281,    -1,
     590,  1273,    -1,   590,   436,  1274,   397,    -1,  1267,    -1,
    1267,   669,   957,    -1,  1273,    -1,  1274,     5,  1273,    -1,
     547,  1277,    -1,   547,   436,  1276,   397,    -1,  1277,    -1,
    1276,     5,  1277,    -1,   957,    -1,   460,  1280,    -1,   460,
     436,  1279,   397,    -1,  1280,    -1,  1279,     5,  1280,    -1,
    1267,    -1,    90,    -1,    91,    -1,    89,    26,    -1,    61,
    1352,    -1,    61,   436,  1285,   397,    -1,    62,  1286,    -1,
      62,   436,  1285,   397,    -1,  1352,    -1,  1285,     5,  1352,
      -1,   957,    -1,   270,    -1,   236,    -1,   169,  1289,    -1,
     146,    -1,   134,    -1,   124,    -1,   122,    -1,   126,    -1,
     183,  1452,    -1,   235,  1288,   465,  1446,   631,  1446,    -1,
     303,   950,   465,  1446,   631,  1446,    -1,    -1,  1452,    -1,
      -1,   864,    -1,   528,   864,    -1,   234,    -1,    -1,   253,
    1293,  1395,  1296,  1294,    -1,    -1,   484,  1295,   436,  1298,
     397,    -1,  1432,    -1,    -1,   436,  1297,   397,    -1,  1398,
      -1,  1297,     5,  1398,    -1,  1299,    -1,  1298,     5,  1299,
      -1,  1438,    -1,   488,    -1,    -1,    -1,   505,  1301,  1304,
    1302,  1305,    -1,   958,    -1,  1309,   951,    -1,   951,    -1,
      -1,    -1,   559,  1306,  1132,    -1,    -1,    -1,   559,  1308,
    1132,    -1,   506,    -1,   560,    -1,   567,    -1,   380,    -1,
     346,    -1,   401,    -1,   383,   864,    -1,   355,   864,    -1,
     242,  1395,   154,   951,    -1,   242,  1395,  1368,    -1,   519,
     624,  1313,    -1,  1314,    -1,  1313,     5,  1314,    -1,  1315,
    1316,    -1,    26,    -1,  1398,    -1,    -1,   593,    -1,   544,
      -1,   281,    -1,   314,    -1,    -1,   331,    -1,   361,  1321,
    1319,    -1,  1490,    -1,  1490,   617,   957,    -1,    25,    -1,
      -1,  1451,  1323,  1324,    -1,  1353,    -1,  1357,    -1,  1318,
      -1,  1453,    -1,  1317,    -1,  1310,    -1,  1311,    -1,  1300,
      -1,  1292,    -1,  1291,    -1,  1422,    -1,  1470,    -1,   510,
    1327,   630,  1395,   631,  1332,  1326,    -1,    -1,   145,    -1,
     172,    -1,  1328,    -1,  1329,    -1,  1328,     5,  1329,    -1,
     476,    -1,   455,    -1,   444,    -1,   483,  1330,    -1,    -1,
     436,  1331,   397,    -1,  1398,    -1,  1331,     5,  1398,    -1,
    1333,    -1,  1332,     5,  1333,    -1,   468,    -1,  1396,    -1,
     240,  1395,  1335,   622,  1432,  1337,    -1,    -1,   436,  1336,
     397,    -1,  1398,    -1,  1336,     5,  1398,    -1,    -1,   144,
      -1,   497,   436,  1371,   397,    -1,   250,   436,  1341,   397,
    1340,    -1,   301,  1342,    -1,  1343,    -1,  1395,    -1,  1395,
     436,  1343,   397,    -1,  1398,    -1,  1343,     5,  1398,    -1,
     481,   436,  1345,   397,    -1,   263,   436,  1345,   397,    -1,
    1398,    -1,  1345,     5,  1398,    -1,  1344,    -1,  1339,    -1,
    1338,    -1,   405,  1401,    -1,   212,    -1,   957,  1387,  1349,
    1350,    -1,    -1,  1347,    -1,    -1,  1351,    -1,  1352,    -1,
    1351,  1352,    -1,   378,    -1,   162,    -1,   481,    -1,  1340,
      -1,   497,   436,  1371,   397,    -1,   123,  1354,  1356,    -1,
    1355,    -1,  1396,    -1,  1357,    -1,  1356,  1357,    -1,  1334,
      -1,  1325,    -1,   453,  1371,    -1,   373,  1360,    -1,  1437,
      -1,  1360,     5,  1437,    -1,   531,  1371,    -1,   552,  1363,
      -1,  1364,    -1,  1363,     5,  1364,    -1,  1365,    -1,   520,
    1365,    -1,   520,   436,  1366,   397,    -1,  1395,    -1,  1395,
    1400,    -1,  1364,    -1,  1366,     5,  1364,    -1,  1362,  1368,
    1369,  1370,    -1,    -1,  1361,    -1,    -1,  1359,    -1,    -1,
    1358,    -1,  1372,    -1,  1371,     6,  1372,    -1,  1373,    -1,
    1372,     7,  1373,    -1,  1374,    -1,     9,  1374,    -1,  1385,
      -1,   436,  1371,   397,    -1,   448,  1433,    -1,   299,  1433,
      -1,    -1,   447,  1378,    -1,  1439,    -1,  1442,    -1,  1438,
     628,   436,  1380,   397,    -1,  1438,   628,  1433,    -1,  1438,
     434,   436,  1380,   397,    -1,  1438,   434,  1433,    -1,  1381,
      -1,  1380,     5,  1381,    -1,  1494,    -1,  1401,    -1,    -1,
       9,    -1,  1438,  1382,   392,    -1,  1438,  1382,   254,    -1,
    1438,  1384,  1438,    -1,  1438,  1382,   394,  1438,     7,  1438,
      -1,  1438,   562,  1377,  1376,    -1,  1438,   376,  1377,  1376,
      -1,  1438,   679,  1377,  1376,    -1,  1438,   377,  1377,  1376,
      -1,  1438,  1382,    10,  1377,  1376,    -1,    14,    -1,    17,
      -1,    12,    -1,    13,    -1,   257,    -1,    10,    -1,   678,
      -1,    16,    -1,    15,    -1,  1383,    -1,  1379,    -1,  1375,
      -1,    -1,   591,    -1,   364,    -1,   481,    -1,  1388,    -1,
    1389,    -1,  1391,    -1,   541,    -1,   541,   436,  1392,   397,
      -1,   416,   436,  1393,  1390,   397,    -1,   477,    -1,   403,
     436,  1393,  1390,   397,    -1,   517,   436,  1393,  1390,   397,
      -1,   543,    -1,   413,    -1,   385,    -1,   362,  1408,   631,
    1409,    -1,   362,    -1,   374,  1408,   631,  1409,    -1,   374,
      -1,   374,  1408,   436,    26,   397,   631,  1409,    -1,   580,
      -1,   538,    -1,   429,    -1,   429,   436,    26,   397,    -1,
     429,   436,    26,     5,    26,   397,    -1,    -1,     5,  1394,
      -1,   507,   436,  1393,   397,    -1,   571,    -1,   304,    -1,
     507,    -1,    68,    -1,    26,    -1,    26,    -1,    26,    -1,
      25,   625,   957,    -1,    25,    -1,   957,    -1,   957,   595,
     957,    -1,   957,    -1,    -1,   464,    26,   432,    -1,   464,
      26,     5,    26,   432,    -1,  1399,    -1,   617,  1399,    -1,
     957,  1397,    -1,  1395,   625,   957,  1397,    -1,  1395,   625,
      20,    -1,   957,    -1,    25,    -1,   416,    -1,   963,    -1,
      26,    -1,  1403,    -1,   401,  1405,    -1,   401,  1404,    -1,
      -1,  1408,   631,  1409,    -1,    -1,  1406,   631,  1406,    -1,
     587,    -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,
     475,    -1,   371,    -1,   371,   436,    26,   397,    -1,   587,
      -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,
      -1,   371,    -1,   371,   436,    26,   397,    -1,   587,    -1,
     518,    -1,   596,    -1,   558,    -1,   459,    -1,   475,    -1,
     371,    -1,   587,    -1,   518,    -1,   596,    -1,   558,    -1,
     459,    -1,   475,    -1,   371,    -1,   957,    -1,   957,   617,
     957,    -1,    25,    -1,  1451,   508,   951,    -1,    -1,  1451,
     404,  1303,   442,   601,  1420,  1413,    -1,    -1,  1451,   404,
    1303,   442,   105,   601,  1421,  1414,    -1,    -1,  1451,   404,
    1303,   140,  1421,  1415,    -1,    -1,  1451,   404,  1303,   141,
     105,   601,  1421,  1416,    -1,    -1,   293,    -1,   292,  1418,
      -1,  1419,    -1,  1418,     5,  1419,    -1,   957,    -1,   957,
     625,   957,    -1,    25,   625,   957,   625,   957,    -1,  1421,
      -1,  1292,    -1,  1167,    -1,  1423,    -1,  1423,    -1,    -1,
      -1,   476,  1434,  1424,  1435,  1425,  1431,  1367,  1429,  1417,
      -1,   476,  1434,  1435,  1367,  1429,    -1,  1428,    -1,  1446,
      -1,   476,  1434,  1435,  1431,  1367,  1429,    -1,    -1,   530,
    1386,  1427,    -1,  1312,    -1,   336,  1430,  1263,    -1,  1312,
     336,  1430,  1263,    -1,   957,    -1,    -1,   559,  1132,    -1,
     476,  1434,  1435,  1367,    -1,   436,   476,  1434,  1435,  1367,
     397,    -1,    -1,   591,    -1,   364,    -1,   481,    -1,  1436,
      -1,  1435,     5,  1436,    -1,  1438,    -1,  1438,   957,    -1,
    1438,    -1,  1439,    -1,    19,  1439,    -1,    18,  1439,    -1,
    1440,    -1,  1494,    -1,  1433,    -1,   617,   957,    -1,   617,
     957,   625,   957,    -1,  1439,    21,  1438,    -1,  1439,  1460,
      -1,  1439,    20,  1438,    -1,  1439,    18,  1438,    -1,  1439,
      19,  1438,    -1,  1401,    -1,   489,    -1,   433,    -1,   582,
      -1,    20,    -1,    69,    -1,   594,   436,  1386,  1438,   397,
      -1,   606,   436,  1386,  1438,   397,    -1,   607,   436,  1386,
    1438,   397,    -1,   614,   436,  1386,  1438,   397,    -1,   501,
     436,  1386,  1438,   397,    -1,   957,   436,  1441,   397,    -1,
     543,   436,  1441,   397,    -1,   436,  1438,   397,    -1,   449,
     436,  1461,   397,    -1,  1438,    -1,  1441,     5,  1438,    -1,
    1401,    -1,  1451,   351,  1450,  1445,  1427,    -1,  1451,   340,
    1450,  1445,   253,  1395,  1447,    -1,  1451,   340,  1450,  1445,
    1110,    -1,    -1,   326,  1446,    -1,    25,    -1,  1110,    -1,
      -1,   436,  1448,   397,    -1,  1449,    -1,  1448,     5,  1449,
      -1,   957,    -1,    25,    -1,  1110,    -1,    -1,   272,  1452,
     601,    -1,   958,    -1,  1458,    -1,  1457,    -1,  1454,    -1,
     321,  1455,   631,  1455,    -1,   302,  1455,   625,  1456,   631,
    1456,    -1,   957,    -1,   957,    -1,   226,   804,    -1,   297,
     804,  1459,    -1,   276,    -1,   179,    -1,    97,    -1,    98,
      -1,    99,    -1,   100,    -1,   101,    -1,   102,    -1,   401,
       5,  1408,   631,  1409,    -1,  1494,     5,  1408,   631,  1409,
      -1,   401,  1408,   631,  1409,    -1,    -1,   613,  1463,  1464,
     194,    -1,  1465,    -1,  1464,  1465,    -1,    33,    -1,  1466,
      -1,  1468,    -1,   355,    -1,   309,    -1,   228,    -1,   590,
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
      -1,   485,    -1,    -1,   195,  1467,  1494,    -1,    -1,   559,
    1469,  1132,    -1,    -1,    -1,   483,  1395,  1471,  1474,  1472,
    1473,    -1,    -1,   154,   951,    -1,   531,  1371,    -1,    57,
    1478,   397,    14,   436,  1479,   397,    -1,    53,  1479,   397,
      -1,    54,  1479,   397,    -1,   589,  1475,    -1,    56,  1479,
      -1,    55,  1479,    -1,  1477,    -1,  1475,     5,  1477,    -1,
    1398,    -1,  1476,    14,  1480,    -1,  1476,    -1,  1478,     5,
    1476,    -1,  1480,    -1,  1479,     5,  1480,    -1,   488,    -1,
    1481,    -1,  1482,    -1,    19,  1482,    -1,    18,  1482,    -1,
    1484,    -1,  1433,    -1,   617,   957,    -1,   617,   957,   625,
     957,    -1,  1483,    -1,  1401,    -1,   489,    -1,   433,    -1,
     582,    -1,    69,    -1,  1482,    21,  1481,    -1,  1482,  1460,
      -1,  1482,    20,  1481,    -1,  1482,    18,  1481,    -1,  1482,
      19,  1481,    -1,   594,   436,  1386,  1481,   397,    -1,   606,
     436,  1386,  1481,   397,    -1,   607,   436,  1386,  1481,   397,
      -1,   614,   436,  1386,  1481,   397,    -1,   501,   436,  1386,
    1481,   397,    -1,   957,   436,  1485,   397,    -1,   543,   436,
    1485,   397,    -1,   436,  1481,   397,    -1,   449,   436,  1461,
     397,    -1,  1494,    -1,  1481,    -1,  1485,     5,  1481,    -1,
      -1,   386,  1141,   562,  1487,  1488,    -1,  1489,    -1,  1488,
       5,  1489,    -1,   804,   625,  1398,    -1,   804,   625,    20,
      -1,  1491,    -1,   195,  1492,    -1,  1492,    -1,  1119,    -1,
     957,    -1,  1492,   625,  1493,    -1,    25,   625,  1492,   625,
    1493,    -1,    20,    -1,  1140,    -1,   957,    -1,  1491,    -1,
    1491,   426,  1491,    -1,   131,  1496,    -1,   135,  1496,    -1,
     130,  1496,    -1,    51,    -1,   170,  1496,    -1,   128,  1496,
      -1,    52,    -1,   153,  1496,    -1,   152,  1496,    -1,   127,
    1496,    -1,   360,    -1,   626,   631,  1497,    -1,   553,  1497,
      -1,   578,    -1,   539,  1498,    -1,   957,    -1,   595,   957,
      -1,   957,    -1,    -1,    -1,   532,  1500,   864,  1501,  1515,
     330,    -1,    -1,   664,  1505,    -1,    -1,   667,    -1,   186,
      -1,   282,   952,    -1,    74,   952,    -1,   312,    -1,   311,
      -1,   313,   954,  1502,  1503,    -1,   498,  1505,  1503,    -1,
     949,    -1,  1505,     5,   949,    -1,   107,    -1,   137,   952,
      -1,   864,   572,     5,   864,   398,    -1,   514,   864,    -1,
     269,   952,    -1,   106,  1510,     8,  1511,  1509,    -1,    -1,
     552,   864,    -1,   957,    -1,   957,    -1,   252,   952,    -1,
     255,   952,   631,   864,     5,   864,    -1,   255,   952,   624,
     864,     5,   864,    -1,    27,    -1,    -1,  1517,    -1,  1518,
    1217,    -1,  1516,    -1,  1517,  1516,    -1,    -1,  1519,  1520,
      -1,   683,    -1,   684,    -1,   685,    -1,   686,    -1,   703,
      -1,   725,    -1,   739,    -1,   740,    -1,   746,    -1,   747,
      -1,   766,    -1,   836,    -1,   837,    -1,   838,    -1,   839,
      -1,   850,    -1,   851,    -1,   852,    -1,   853,    -1,   854,
      -1,   855,    -1,   856,    -1,   908,    -1,   912,    -1,   943,
      -1,   964,    -1,   965,    -1,   968,    -1,   969,    -1,   970,
      -1,   971,    -1,   984,    -1,   993,    -1,  1014,    -1,  1015,
      -1,  1017,    -1,  1021,    -1,  1036,    -1,  1037,    -1,  1041,
      -1,  1042,    -1,  1043,    -1,  1044,    -1,  1052,    -1,  1067,
      -1,  1080,    -1,  1091,    -1,  1092,    -1,  1093,    -1,  1104,
      -1,  1143,    -1,  1146,    -1,  1148,    -1,  1154,    -1,  1155,
      -1,  1158,    -1,  1161,    -1,  1164,    -1,  1166,    -1,  1168,
      -1,  1171,    -1,  1178,    -1,  1183,    -1,  1187,    -1,  1188,
      -1,  1189,    -1,  1201,    -1,  1253,    -1,  1254,    -1,  1256,
      -1,  1268,    -1,  1269,    -1,  1287,    -1,  1290,    -1,  1320,
      -1,  1322,    -1,  1411,    -1,  1412,    -1,  1443,    -1,  1444,
      -1,  1462,    -1,  1486,    -1,  1495,    -1,  1499,    -1,  1504,
      -1,  1506,    -1,  1508,    -1,  1512,    -1,  1513,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   945,   945,   948,   951,   957,   963,   970,   974,   974,
     980,  1003,  1004,  1005,  1006,  1007,  1018,  1027,  1028,  1029,
    1030,  1031,  1036,  1037,  1048,  1051,  1054,  1054,  1058,  1061,
    1062,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1087,  1088,
    1091,  1091,  1106,  1107,  1110,  1116,  1118,  1129,  1131,  1133,
    1135,  1139,  1141,  1203,  1207,  1211,  1211,  1221,  1225,  1228,
    1229,  1236,  1242,  1236,  1255,  1260,  1264,  1255,  1276,  1280,
    1276,  1288,  1293,  1288,  1312,  1319,  1323,  1311,  1349,  1349,
    1353,  1354,  1355,  1360,  1363,  1368,  1372,  1380,  1383,  1383,
    1389,  1393,  1408,  1406,  1424,  1424,  1439,  1439,  1442,  1442,
    1446,  1449,  1449,  1449,  1456,  1457,  1456,  1464,  1464,  1475,
    1475,  1494,  1497,  1500,  1503,  1506,  1509,  1522,  1527,  1527,
    1528,  1528,  1531,  1536,  1536,  1540,  1550,  1564,  1568,  1563,
    1578,  1584,  1592,  1593,  1596,  1596,  1599,  1603,  1608,  1615,
    1615,  1619,  1619,  1626,  1626,  1631,  1631,  1636,  1636,  1641,
    1641,  1654,  1655,  1663,  1664,  1681,  1684,  1687,  1690,  1693,
    1696,  1702,  1713,  1718,  1731,  1735,  1750,  1751,  1755,  1755,
    1759,  1759,  1759,  1760,  1761,  1766,  1766,  1769,  1769,  1778,
    1779,  1780,  1783,  1787,  1788,  1788,  1805,  1805,  1805,  1805,
    1809,  1816,  1817,  1820,  1820,  1824,  1825,  1826,  1827,  1832,
    1832,  1838,  1838,  1847,  1844,  1860,  1860,  1862,  1862,  1864,
    1866,  1868,  1870,  1873,  1877,  1877,  1878,  1878,  1882,  1882,
    1894,  1894,  1899,  1903,  1905,  1906,  1909,  1909,  1909,  1913,
    1914,  1915,  1916,  1923,  1924,  1925,  1926,  1929,  1930,  1931,
    1932,  1936,  1941,  1946,  1950,  1953,  1957,  1958,  1959,  1960,
    1961,  1962,  1963,  1964,  1967,  1968,  1969,  2001,  2005,  2007,
    2009,  2009,  2016,  2020,  2020,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2036,  2036,  2039,  2041,  2047,  2049,  2055,  2063,
    2063,  2066,  2067,  2068,  2069,  2070,  2071,  2072,  2078,  2081,
    2081,  2094,  2094,  2101,  2102,  2103,  2105,  2106,  2108,  2110,
    2111,  2112,  2113,  2118,  2124,  2130,  2131,  2133,  2135,  2136,
    2137,  2138,  2139,  2140,  2143,  2144,  2151,  2159,  2159,  2167,
    2164,  2179,  2179,  2181,  2181,  2189,  2189,  2192,  2195,  2196,
    2201,  2213,  2217,  2220,  2223,  2224,  2225,  2226,  2227,  2232,
    2239,  2245,  2250,  2255,  2250,  2266,  2268,  2273,  2278,  2278,
    2278,  2282,  2282,  2285,  2285,  2291,  2291,  2297,  2297,  2307,
    2325,  2331,  2355,  2358,  2372,  2374,  2376,  2378,  2380,  2382,
    2384,  2390,  2392,  2396,  2398,  2400,  2402,  2404,  2406,  2408,
    2414,  2429,  2432,  2445,  2446,  2447,  2448,  2449,  2453,  2454,
    2455,  2459,  2464,  2471,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2480,  2481,  2488,  2488,  2493,  2493,  2496,  2502,
    2510,  2516,  2526,  2527,  2535,  2542,  2546,  2556,  2560,  2565,
    2570,  2572,  2582,  2595,  2603,  2616,  2621,  2627,  2632,  2637,
    2638,  2644,  2715,  2721,  2726,  2734,  2734,  2749,  2753,  2760,
    2763,  2771,  2782,  2792,  2798,  2807,  2812,  2820,  2823,  2826,
    2831,  2838,  2843,  2848,  2853,  2863,  2871,  2879,  2884,  2888,
    2893,  2897,  2901,  2908,  2911,  2914,  2918,  2922,  2926,  2930,
    2938,  2948,  2953,  2946,  2969,  2974,  2969,  2991,  2991,  2991,
    2994,  2994,  2994,  2998,  2998,  2998,  3002,  3002,  3002,  3006,
    3012,  3018,  3024,  3030,  3036,  3046,  3046,  3050,  3054,  3055,
    3066,  3067,  3073,  3083,  3093,  3103,  3104,  3107,  3112,  3118,
    3122,  3126,  3129,  3135,  3138,  3141,  3158,  3161,  3167,  3168,
    3169,  3173,  3174,  3175,  3176,  3177,  3179,  3180,  3181,  3183,
    3184,  3188,  3189,  3194,  3195,  3207,  3211,  3206,  3219,  3222,
    3236,  3240,  3246,  3235,  3259,  3260,  3272,  3278,  3272,  3292,
    3292,  3294,  3295,  3299,  3299,  3303,  3303,  3308,  3308,  3315,
    3316,  3320,  3320,  3324,  3324,  3329,  3329,  3336,  3340,  3341,
    3342,  3347,  3347,  3350,  3350,  3354,  3354,  3358,  3358,  3362,
    3362,  3367,  3367,  3372,  3372,  3377,  3377,  3382,  3382,  3398,
    3415,  3416,  3417,  3418,  3419,  3420,  3421,  3424,  3424,  3427,
    3429,  3432,  3435,  3437,  3438,  3439,  3441,  3443,  3445,  3447,
    3451,  3458,  3460,  3466,  3471,  3476,  3481,  3481,  3484,  3490,
    3495,  3498,  3505,  3505,  3507,  3508,  3510,  3512,  3514,  3516,
    3520,  3529,  3529,  3591,  3603,  3610,  3610,  3614,  3619,  3625,
    3629,  3633,  3639,  3643,  3647,  3653,  3653,  3661,  3662,  3666,
    3666,  3670,  3671,  3674,  3677,  3677,  3680,  3682,  3682,  3685,
    3687,  3687,  3688,  3690,  3690,  3699,  3706,  3697,  3728,  3728,
    3728,  3731,  3733,  3731,  3740,  3743,  3749,  3760,  3760,  3764,
    3770,  3770,  3774,  3775,  3786,  3787,  3788,  3791,  3793,  3798,
    3798,  3802,  3801,  3808,  3807,  3813,  3813,  3818,  3818,  3824,
    3824,  3829,  3829,  3834,  3834,  3839,  3839,  3842,  3842,  3845,
    3845,  3848,  3848,  3890,  3891,  3899,  3900,  3909,  3914,  3919,
    3920,  3921,  3925,  3924,  3935,  3940,  3945,  3945,  3961,  3967,
    3968,  3969,  3970,  3973,  3973,  3976,  3983,  3984,  3985,  3986,
    3987,  3988,  3989,  3990,  3991,  3996,  3996,  3998,  4001,  4001,
    4003,  4007,  4010,  4011,  4014,  4014,  4019,  4022,  4023,  4024,
    4025,  4026,  4027,  4028,  4029,  4030,  4031,  4032,  4033,  4034,
    4035,  4036,  4037,  4038,  4039,  4043,  4061,  4061,  4061,  4088,
    4099,  4106,  4112,  4118,  4124,  4135,  4158,  4157,  4174,  4174,
    4178,  4179,  4187,  4188,  4189,  4190,  4197,  4198,  4200,  4201,
    4205,  4210,  4211,  4212,  4213,  4214,  4215,  4216,  4217,  4218,
    4219,  4220,  4223,  4223,  4225,  4225,  4225,  4227,  4231,  4231,
    4240,  4245,  4261,  4267,  4239,  4281,  4295,  4305,  4294,  4318,
    4325,  4325,  4330,  4336,  4344,  4349,  4350,  4353,  4353,  4353,
    4356,  4356,  4364,  4370,  4384,  4388,  4401,  4383,  4419,  4419,
    4433,  4444,  4443,  4455,  4451,  4468,  4465,  4478,  4478,  4480,
    4481,  4483,  4484,  4487,  4488,  4489,  4491,  4496,  4501,  4507,
    4509,  4510,  4513,  4514,  4517,  4519,  4528,  4534,  4528,  4545,
    4546,  4550,  4550,  4560,  4560,  4572,  4575,  4578,  4581,  4585,
    4589,  4590,  4591,  4592,  4593,  4597,  4602,  4602,  4605,  4631,
    4690,  4690,  4693,  4697,  4701,  4744,  4786,  4787,  4788,  4791,
    4805,  4817,  4817,  4822,  4823,  4829,  4889,  4946,  4951,  4958,
    4963,  4971,  4977,  5011,  5014,  5015,  5056,  5099,  5100,  5104,
    5105,  5109,  5162,  5166,  5169,  5175,  5186,  5193,  5201,  5201,
    5204,  5205,  5206,  5207,  5208,  5211,  5214,  5220,  5223,  5227,
    5231,  5238,  5243,  5250,  5253,  5259,  5261,  5261,  5261,  5265,
    5285,  5292,  5299,  5302,  5316,  5323,  5324,  5327,  5328,  5332,
    5338,  5343,  5349,  5350,  5355,  5359,  5359,  5363,  5364,  5367,
    5368,  5372,  5380,  5383,  5389,  5390,  5392,  5394,  5398,  5398,
    5399,  5404,  5412,  5413,  5418,  5419,  5421,  5434,  5436,  5437,
    5439,  5442,  5445,  5448,  5452,  5455,  5458,  5462,  5466,  5470,
    5473,  5477,  5480,  5481,  5482,  5485,  5488,  5491,  5494,  5497,
    5500,  5503,  5519,  5527,  5527,  5529,  5536,  5540,  5545,  5560,
    5558,  5577,  5578,  5582,  5587,  5588,  5592,  5593,  5595,  5596,
    5598,  5598,  5606,  5615,  5615,  5625,  5626,  5631,  5632,  5635,
    5648,  5662,  5667,  5672,  5677,  5687,  5687,  5691,  5694,  5694,
    5696,  5706,  5715,  5722,  5724,  5728,  5731,  5731,  5735,  5734,
    5742,  5741,  5752,  5751,  5758,  5757,  5761,  5760,  5763,  5763,
    5779,  5778,  5800,  5801,  5802,  5803,  5804,  5805,  5808,  5808,
    5814,  5814,  5817,  5817,  5833,  5834,  5835,  5844,  5856,  5857,
    5860,  5861,  5864,  5867,  5867,  5872,  5892,  5897,  5903,  5904,
    5905,  5909,  5910,  5911,  5912,  5916,  5926,  5928,  5933,  5936,
    5941,  5947,  5954,  5961,  5970,  5977,  5984,  5991,  5998,  6007,
    6007,  6009,  6009,  6012,  6013,  6014,  6015,  6016,  6017,  6018,
    6019,  6020,  6021,  6024,  6024,  6027,  6028,  6029,  6030,  6033,
    6033,  6036,  6036,  6039,  6040,  6041,  6042,  6043,  6044,  6045,
    6046,  6048,  6049,  6050,  6051,  6053,  6054,  6055,  6056,  6058,
    6059,  6060,  6061,  6062,  6063,  6064,  6065,  6069,  6076,  6085,
    6097,  6106,  6117,  6121,  6125,  6131,  6096,  6144,  6147,  6155,
    6167,  6169,  6174,  6182,  6192,  6195,  6199,  6207,  6173,  6216,
    6220,  6224,  6228,  6220,  6238,  6239,  6240,  6241,  6246,  6248,
    6251,  6255,  6258,  6265,  6270,  6271,  6272,  6277,  6278,  6284,
    6284,  6284,  6289,  6289,  6289,  6300,  6301,  6307,  6308,  6320,
    6321,  6326,  6327,  6328,  6332,  6335,  6341,  6344,  6352,  6353,
    6359,  6366,  6369,  6378,  6381,  6384,  6387,  6390,  6393,  6396,
    6403,  6406,  6413,  6416,  6422,  6425,  6432,  6435,  6442,  6443,
    6448,  6452,  6455,  6461,  6464,  6470,  6477,  6478,  6482,  6488,
    6491,  6498,  6499,  6506,  6509,  6514,  6525,  6526,  6527,  6528,
    6529,  6530,  6531,  6532,  6533,  6536,  6539,  6545,  6545,  6551,
    6551,  6562,  6575,  6585,  6585,  6590,  6590,  6594,  6598,  6599,
    6605,  6606,  6611,  6615,  6622,  6625,  6632,  6636,  6631,  6645,
    6649,  6653,  6660,  6664,  6664,  6677,  6681,  6681,  6696,  6698,
    6700,  6702,  6704,  6706,  6708,  6710,  6716,  6726,  6733,  6738,
    6739,  6743,  6746,  6747,  6750,  6751,  6752,  6755,  6760,  6767,
    6768,  6774,  6786,  6787,  6788,  6791,  6791,  6796,  6801,  6806,
    6807,  6810,  6811,  6816,  6821,  6825,  6830,  6831,  6835,  6842,
    6846,  6847,  6852,  6854,  6858,  6859,  6863,  6864,  6865,  6866,
    6870,  6871,  6876,  6877,  6882,  6883,  6888,  6889,  6894,  6899,
    6900,  6905,  6906,  6910,  6911,  6916,  6923,  6928,  6933,  6937,
    6938,  6943,  6944,  6950,  6952,  6957,  6958,  6964,  6967,  6970,
    6977,  6979,  6993,  6998,  6999,  7002,  7004,  7011,  7014,  7020,
    7024,  7028,  7032,  7035,  7042,  7049,  7054,  7058,  7059,  7065,
    7068,  7079,  7086,  7092,  7095,  7102,  7109,  7115,  7116,  7122,
    7123,  7124,  7127,  7128,  7133,  7133,  7137,  7145,  7146,  7149,
    7152,  7157,  7158,  7163,  7166,  7172,  7175,  7181,  7184,  7190,
    7193,  7200,  7201,  7230,  7231,  7236,  7244,  7249,  7252,  7255,
    7258,  7264,  7265,  7269,  7272,  7275,  7276,  7281,  7284,  7287,
    7290,  7293,  7296,  7299,  7302,  7307,  7313,  7314,  7315,  7316,
    7317,  7319,  7320,  7322,  7323,  7328,  7331,  7335,  7341,  7342,
    7343,  7344,  7356,  7357,  7358,  7362,  7363,  7368,  7370,  7371,
    7372,  7374,  7375,  7376,  7377,  7379,  7380,  7382,  7383,  7385,
    7386,  7387,  7388,  7390,  7394,  7395,  7401,  7403,  7404,  7405,
    7406,  7411,  7415,  7419,  7423,  7424,  7428,  7429,  7439,  7448,
    7449,  7450,  7454,  7457,  7462,  7467,  7472,  7480,  7484,  7488,
    7489,  7490,  7495,  7498,  7501,  7515,  7529,  7542,  7543,  7547,
    7547,  7547,  7547,  7547,  7547,  7548,  7551,  7556,  7556,  7556,
    7556,  7556,  7556,  7558,  7561,  7567,  7567,  7567,  7567,  7567,
    7567,  7567,  7568,  7568,  7568,  7568,  7568,  7568,  7568,  7570,
    7571,  7572,  7575,  7584,  7584,  7590,  7590,  7597,  7597,  7603,
    7603,  7611,  7612,  7613,  7616,  7616,  7619,  7620,  7621,  7626,
    7629,  7635,  7640,  7647,  7660,  7661,  7658,  7679,  7689,  7692,
    7697,  7709,  7712,  7716,  7719,  7720,  7726,  7729,  7730,  7739,
    7748,  7753,  7754,  7755,  7756,  7763,  7766,  7772,  7775,  7785,
    7794,  7797,  7800,  7806,  7812,  7815,  7818,  7821,  7827,  7829,
    7831,  7833,  7835,  7837,  7838,  7839,  7840,  7841,  7842,  7843,
    7845,  7847,  7849,  7851,  7853,  7855,  7857,  7858,  7863,  7864,
    7871,  7874,  7883,  7887,  7894,  7894,  7898,  7898,  7903,  7903,
    7907,  7907,  7911,  7917,  7917,  7920,  7920,  7926,  7933,  7934,
    7935,  7939,  7940,  7943,  7944,  7948,  7954,  7964,  7965,  7973,
    7974,  7975,  7976,  7977,  7978,  7982,  7983,  7984,  7988,  7988,
    8000,  8001,  8005,  8006,  8007,  8008,  8009,  8010,  8011,  8012,
    8013,  8014,  8015,  8016,  8017,  8018,  8019,  8020,  8021,  8022,
    8023,  8024,  8025,  8026,  8027,  8028,  8029,  8030,  8031,  8032,
    8033,  8034,  8035,  8036,  8037,  8038,  8039,  8040,  8041,  8042,
    8043,  8044,  8045,  8046,  8047,  8048,  8049,  8050,  8051,  8052,
    8053,  8054,  8055,  8056,  8057,  8058,  8059,  8060,  8061,  8062,
    8063,  8064,  8065,  8066,  8067,  8068,  8069,  8070,  8071,  8072,
    8073,  8074,  8075,  8076,  8077,  8078,  8079,  8080,  8081,  8082,
    8083,  8084,  8085,  8086,  8087,  8088,  8089,  8090,  8091,  8092,
    8093,  8094,  8095,  8096,  8097,  8098,  8099,  8100,  8101,  8102,
    8103,  8104,  8105,  8106,  8107,  8108,  8109,  8110,  8111,  8112,
    8113,  8114,  8115,  8116,  8117,  8118,  8119,  8120,  8121,  8122,
    8123,  8124,  8125,  8126,  8127,  8128,  8129,  8130,  8131,  8132,
    8133,  8134,  8135,  8136,  8137,  8138,  8139,  8140,  8141,  8142,
    8143,  8144,  8145,  8146,  8147,  8148,  8149,  8150,  8151,  8152,
    8153,  8154,  8155,  8156,  8157,  8158,  8159,  8160,  8161,  8162,
    8163,  8164,  8165,  8166,  8167,  8168,  8169,  8170,  8171,  8172,
    8173,  8174,  8175,  8176,  8177,  8178,  8179,  8180,  8181,  8182,
    8183,  8184,  8185,  8186,  8187,  8188,  8189,  8190,  8191,  8192,
    8193,  8194,  8195,  8196,  8197,  8198,  8199,  8200,  8201,  8202,
    8203,  8204,  8205,  8206,  8207,  8208,  8209,  8210,  8211,  8212,
    8213,  8214,  8215,  8216,  8217,  8218,  8219,  8220,  8221,  8222,
    8223,  8224,  8225,  8226,  8227,  8228,  8229,  8230,  8231,  8232,
    8233,  8234,  8235,  8236,  8237,  8238,  8239,  8240,  8241,  8242,
    8243,  8244,  8245,  8246,  8247,  8248,  8249,  8250,  8251,  8252,
    8253,  8254,  8255,  8256,  8257,  8258,  8259,  8260,  8261,  8262,
    8263,  8264,  8265,  8266,  8267,  8268,  8269,  8270,  8271,  8272,
    8273,  8274,  8275,  8276,  8277,  8278,  8279,  8280,  8281,  8282,
    8283,  8284,  8285,  8286,  8287,  8288,  8289,  8290,  8291,  8292,
    8293,  8294,  8295,  8296,  8297,  8298,  8299,  8300,  8301,  8302,
    8303,  8304,  8305,  8306,  8307,  8308,  8309,  8310,  8311,  8312,
    8313,  8314,  8315,  8316,  8317,  8318,  8319,  8320,  8321,  8322,
    8323,  8324,  8325,  8326,  8327,  8335,  8335,  8342,  8342,  8430,
    8434,  8430,  8443,  8447,  8453,  8461,  8471,  8481,  8493,  8496,
    8515,  8541,  8544,  8550,  8553,  8558,  8561,  8569,  8577,  8590,
    8593,  8601,  8604,  8607,  8615,  8619,  8622,  8625,  8628,  8632,
    8633,  8634,  8635,  8636,  8642,  8643,  8644,  8645,  8646,  8647,
    8648,  8649,  8650,  8651,  8652,  8653,  8654,  8655,  8659,  8665,
    8666,  8674,  8674,  8682,  8682,  8686,  8690,  8705,  8726,  8726,
    8730,  8731,  8732,  8733,  8737,  8738,  8739,  8744,  8770,  8835,
    8837,  8839,  8841,  8845,  8850,  8852,  8855,  8857,  8859,  8863,
    8866,  8871,  8876,  8880,  8889,  8890,  8894,  8906,  8909,  8905,
    8928,  8928,  8932,  8933,  8936,  8937,  8938,  8939,  8940,  8941,
    8942,  8947,  8948,  8952,  8955,  8960,  8964,  8969,  8973,  8978,
    8982,  8985,  8989,  8992,  8997,  9001,  9012,  9018,  9018,  9019,
    9020,  9027,  9036,  9036,  9038,  9039,  9040,  9041,  9042,  9043,
    9044,  9045,  9046,  9047,  9048,  9049,  9050,  9051,  9052,  9053,
    9054,  9055,  9056,  9057,  9058,  9059,  9060,  9061,  9062,  9063,
    9064,  9065,  9066,  9067,  9068,  9069,  9070,  9071,  9072,  9073,
    9074,  9075,  9076,  9077,  9078,  9079,  9080,  9081,  9082,  9083,
    9084,  9085,  9086,  9087,  9088,  9089,  9090,  9091,  9092,  9093,
    9094,  9095,  9096,  9097,  9098,  9099,  9100,  9101,  9102,  9103,
    9104,  9105,  9106,  9107,  9108,  9109,  9110,  9111,  9112,  9113,
    9114,  9115,  9116,  9117,  9118,  9119,  9120,  9121,  9122,  9123,
    9124,  9125,  9126
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
  "WITH_3_DIMENSION", "TILDE", "ILIKE", "FGL_ISDYNARR_ALLOCATED", 
  "FGL_DYNARR_EXTENTSIZE", "$accept", "pause_screen_on_cmd", 
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
  "upd_value_expr_list_ss", "validate_cmd", "@175", "validate_tab_list", 
  "validate_tab", "var_ident", "var2", "var3", "aft_dot", 
  "var_ident_ibind_ss", "whenever_cmd", "when_do", "label_goto", 
  "function_name_when", "while_cmd", "@176", "@177", "op_clr_fields", 
  "op_to_defs", "clear_cmd", "fld_list", "current_win_cmd", "window_type", 
  "show_cmd", "op_mnfile", "menu_name", "menu_handler", "hide_cmd", 
  "move_cmd", "NAMED", "commands", "all_commands", "command1", 
  "commands_all", "@178", "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1667,  1668,  1669,  1575,  1615,  1570,  1506,  1590,
    1385,  1492,  1488,  1403,  1565,  1301,  1360,  1434,  1601,  1588,
    1493,  1521,  1589,  1367,  1670,  1671,  1672,  1673,  1674,  1675,
    1676,  1677,  1678,  1679,  1000,  1001,  1002,  1003,  1004,  1005,
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
    1655,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   682,   683,   684,   685,   686,   687,   687,   688,   688,
     689,   690,   690,   690,   690,   690,   690,   691,   691,   691,
     691,   691,   692,   692,   693,   693,   695,   694,   694,   696,
     696,   697,   697,   697,   697,   697,   697,   697,   697,   697,
     697,   697,   697,   697,   697,   697,   697,   697,   698,   698,
     700,   699,   701,   701,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   703,   704,   705,   704,   704,   704,   704,
     704,   706,   707,   704,   708,   709,   710,   704,   711,   712,
     704,   713,   714,   704,   715,   716,   717,   704,   718,   718,
     719,   719,   719,   720,   720,   721,   721,   722,   723,   723,
     724,   724,   726,   725,   727,   725,   728,   728,   729,   729,
     730,   731,   732,   731,   733,   734,   733,   736,   735,   738,
     737,   739,   739,   739,   739,   739,   739,   740,   741,   741,
     742,   742,   743,   744,   744,   745,   746,   748,   749,   747,
     750,   750,   751,   751,   752,   752,   753,   753,   753,   754,
     754,   756,   755,   757,   755,   758,   755,   759,   755,   760,
     755,   761,   761,   762,   762,   763,   763,   763,   763,   763,
     763,   764,   765,   765,   766,   766,   767,   767,   768,   768,
     770,   771,   769,   769,   769,   772,   772,   774,   773,   775,
     775,   775,   775,   775,   776,   775,   777,   777,   777,   777,
     778,   779,   779,   780,   780,   781,   781,   781,   781,   783,
     782,   784,   782,   785,   782,   786,   786,   787,   787,   788,
     789,   789,   789,   790,   792,   791,   793,   791,   794,   791,
     795,   795,   796,   797,   798,   798,   800,   801,   799,   802,
     802,   802,   802,   802,   802,   802,   802,   802,   802,   802,
     802,   802,   802,   802,   802,   802,   802,   802,   802,   802,
     802,   802,   802,   802,   802,   802,   802,   803,   804,   805,
     806,   806,   807,   809,   808,   810,   810,   810,   810,   810,
     810,   810,   812,   811,   813,   813,   814,   814,   815,   817,
     816,   818,   818,   818,   818,   818,   818,   818,   819,   820,
     820,   822,   821,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   824,   826,   825,   827,
     825,   829,   828,   830,   828,   831,   831,   832,   833,   833,
     834,   835,   835,   835,   835,   835,   835,   835,   835,   836,
     837,   838,   840,   841,   839,   842,   842,   843,   844,   844,
     844,   845,   845,   847,   846,   848,   846,   849,   846,   850,
     851,   852,   853,   853,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   855,   855,   855,   855,   855,   855,   855,
     855,   856,   856,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   858,   858,   858,   858,   858,   858,   858,
     858,   858,   858,   858,   859,   859,   860,   860,   861,   861,
     862,   862,   863,   863,   864,   865,   865,   866,   866,   866,
     866,   866,   866,   867,   867,   868,   868,   868,   868,   869,
     869,   870,   871,   871,   871,   872,   871,   873,   873,   874,
     874,   875,   875,   875,   875,   876,   876,   877,   877,   877,
     877,   877,   877,   877,   877,   878,   879,   880,   880,   880,
     880,   880,   880,   881,   881,   881,   881,   881,   881,   881,
     882,   884,   885,   883,   886,   887,   883,   889,   890,   888,
     891,   892,   888,   893,   894,   888,   895,   896,   888,   888,
     888,   888,   888,   888,   888,   897,   897,   898,   899,   899,
     899,   899,   899,   899,   899,   899,   899,   900,   900,   901,
     901,   901,   901,   902,   902,   902,   903,   903,   904,   904,
     904,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,   906,   906,   907,   907,   909,   910,   908,   911,   911,
     913,   914,   915,   912,   916,   916,   918,   919,   917,   920,
     920,   921,   921,   922,   922,   924,   923,   925,   923,   926,
     926,   927,   927,   929,   928,   930,   928,   931,   932,   932,
     932,   933,   933,   934,   934,   935,   935,   936,   936,   938,
     937,   939,   937,   940,   937,   941,   937,   942,   937,   943,
     944,   944,   944,   944,   944,   944,   944,   945,   945,   946,
     947,   948,   949,   949,   949,   949,   949,   949,   949,   949,
     950,   951,   952,   953,   954,   955,   956,   956,   957,   958,
     959,   959,   960,   960,   961,   961,   961,   961,   961,   961,
     962,   963,   963,   964,   965,   966,   966,   967,   968,   969,
     969,   969,   970,   970,   970,   972,   971,   973,   973,   974,
     974,   975,   975,   976,   977,   977,   978,   979,   979,   980,
     981,   981,   982,   983,   983,   985,   986,   984,   987,   988,
     987,   989,   990,   987,   991,   991,   992,   994,   993,   993,
     995,   995,   996,   996,   997,   997,   997,   998,   998,   999,
     999,  1001,  1000,  1002,  1000,  1003,  1000,  1004,  1000,  1005,
    1000,  1006,  1000,  1007,  1000,  1008,  1000,  1009,  1000,  1010,
    1000,  1011,  1000,  1012,  1012,  1013,  1013,  1014,  1015,  1016,
    1016,  1016,  1018,  1017,  1019,  1019,  1020,  1019,  1021,  1022,
    1022,  1022,  1022,  1023,  1023,  1024,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1025,  1025,  1027,  1026,  1026,  1029,  1028,
    1030,  1031,  1032,  1032,  1033,  1033,  1034,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1036,  1038,  1039,  1037,  1040,
    1040,  1041,  1042,  1043,  1044,  1044,  1046,  1045,  1047,  1047,
    1048,  1048,  1049,  1049,  1049,  1049,  1050,  1050,  1051,  1051,
    1052,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,
    1053,  1053,  1054,  1054,  1055,  1055,  1055,  1056,  1057,  1057,
    1059,  1060,  1061,  1062,  1058,  1063,  1065,  1066,  1064,  1067,
    1068,  1068,  1069,  1069,  1070,  1071,  1071,  1072,  1072,  1072,
    1074,  1073,  1075,  1075,  1077,  1078,  1079,  1076,  1081,  1080,
    1082,  1084,  1083,  1085,  1083,  1086,  1083,  1087,  1087,  1088,
    1088,  1089,  1089,  1090,  1090,  1090,  1091,  1092,  1093,  1094,
    1094,  1094,  1095,  1095,  1096,  1096,  1098,  1099,  1097,  1100,
    1100,  1102,  1101,  1103,  1101,  1104,  1105,  1105,  1105,  1105,
    1106,  1106,  1106,  1106,  1106,  1107,  1108,  1108,  1109,  1110,
    1111,  1111,  1112,  1113,  1113,  1113,  1113,  1113,  1113,  1114,
    1115,  1116,  1116,  1117,  1117,  1118,  1119,  1120,  1120,  1121,
    1121,  1122,  1123,  1124,  1124,  1124,  1124,  1124,  1124,  1125,
    1125,  1126,  1127,  1127,  1128,  1128,  1129,  1129,  1130,  1130,
    1131,  1131,  1131,  1131,  1131,  1132,  1132,  1133,  1133,  1134,
    1134,  1135,  1136,  1137,  1137,  1138,  1139,  1139,  1139,  1140,
    1141,  1141,  1142,  1142,  1143,  1144,  1144,  1145,  1145,  1146,
    1147,  1148,  1149,  1149,  1150,  1151,  1151,  1152,  1152,  1153,
    1153,  1154,  1155,  1155,  1156,  1156,  1156,  1156,  1157,  1157,
    1157,  1158,  1159,  1159,  1160,  1160,  1160,  1161,  1162,  1162,
    1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1163,  1163,  1164,  1165,  1165,  1166,  1166,  1166,  1167,  1169,
    1168,  1170,  1170,  1171,  1172,  1172,  1173,  1173,  1174,  1174,
    1176,  1175,  1177,  1179,  1178,  1180,  1180,  1181,  1181,  1182,
    1182,  1183,  1183,  1183,  1183,  1184,  1184,  1185,  1186,  1186,
    1187,  1188,  1189,  1190,  1191,  1191,  1192,  1192,  1194,  1193,
    1195,  1193,  1196,  1193,  1197,  1193,  1198,  1193,  1199,  1193,
    1200,  1193,  1201,  1201,  1201,  1201,  1201,  1201,  1203,  1202,
    1204,  1204,  1206,  1205,  1205,  1205,  1205,  1205,  1207,  1207,
    1208,  1208,  1209,  1210,  1210,  1211,  1212,  1213,  1214,  1214,
    1214,  1215,  1215,  1215,  1215,  1216,  1217,  1217,  1218,  1218,
    1219,  1220,  1220,  1220,  1220,  1220,  1220,  1220,  1220,  1221,
    1221,  1222,  1222,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1223,  1223,  1224,  1224,  1225,  1225,  1225,  1225,  1226,
    1226,  1227,  1227,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1229,  1229,  1229,
    1231,  1232,  1233,  1234,  1235,  1236,  1230,  1237,  1237,  1238,
    1239,  1239,  1241,  1242,  1243,  1244,  1245,  1246,  1240,  1247,
    1249,  1250,  1251,  1248,  1252,  1252,  1252,  1252,  1253,  1253,
    1253,  1253,  1253,  1254,  1255,  1255,  1255,  1256,  1256,  1258,
    1259,  1257,  1260,  1261,  1257,  1262,  1262,  1263,  1263,  1264,
    1264,  1265,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,
    1269,  1270,  1270,  1271,  1271,  1271,  1271,  1271,  1271,  1271,
    1272,  1272,  1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,
    1277,  1278,  1278,  1279,  1279,  1280,  1281,  1281,  1282,  1283,
    1283,  1284,  1284,  1285,  1285,  1286,  1287,  1287,  1287,  1287,
    1287,  1287,  1287,  1287,  1287,  1287,  1287,  1288,  1288,  1289,
    1289,  1290,  1291,  1293,  1292,  1295,  1294,  1294,  1296,  1296,
    1297,  1297,  1298,  1298,  1299,  1299,  1301,  1302,  1300,  1303,
    1304,  1304,  1305,  1306,  1305,  1307,  1308,  1307,  1309,  1309,
    1309,  1309,  1309,  1309,  1309,  1309,  1310,  1311,  1312,  1313,
    1313,  1314,  1315,  1315,  1316,  1316,  1316,  1317,  1318,  1319,
    1319,  1320,  1321,  1321,  1321,  1323,  1322,  1324,  1324,  1324,
    1324,  1324,  1324,  1324,  1324,  1324,  1324,  1324,  1324,  1325,
    1326,  1326,  1327,  1327,  1328,  1328,  1329,  1329,  1329,  1329,
    1330,  1330,  1331,  1331,  1332,  1332,  1333,  1333,  1334,  1335,
    1335,  1336,  1336,  1337,  1337,  1338,  1339,  1340,  1341,  1342,
    1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,  1346,  1346,
    1347,  1347,  1348,  1349,  1349,  1350,  1350,  1351,  1351,  1352,
    1352,  1352,  1352,  1352,  1353,  1354,  1355,  1356,  1356,  1357,
    1357,  1358,  1359,  1360,  1360,  1361,  1362,  1363,  1363,  1364,
    1364,  1364,  1365,  1365,  1366,  1366,  1367,  1368,  1368,  1369,
    1369,  1370,  1370,  1371,  1371,  1372,  1372,  1373,  1373,  1374,
    1374,  1375,  1375,  1376,  1376,  1377,  1378,  1379,  1379,  1379,
    1379,  1380,  1380,  1381,  1381,  1382,  1382,  1383,  1383,  1383,
    1383,  1383,  1383,  1383,  1383,  1383,  1384,  1384,  1384,  1384,
    1384,  1384,  1384,  1384,  1384,  1385,  1385,  1385,  1386,  1386,
    1386,  1386,  1387,  1387,  1387,  1388,  1388,  1389,  1389,  1389,
    1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,
    1389,  1389,  1389,  1389,  1390,  1390,  1391,  1391,  1391,  1391,
    1391,  1392,  1393,  1394,  1395,  1395,  1395,  1395,  1396,  1397,
    1397,  1397,  1398,  1398,  1399,  1399,  1399,  1400,  1401,  1401,
    1401,  1401,  1401,  1402,  1403,  1404,  1404,  1405,  1405,  1406,
    1406,  1406,  1406,  1406,  1406,  1406,  1406,  1407,  1407,  1407,
    1407,  1407,  1407,  1407,  1407,  1408,  1408,  1408,  1408,  1408,
    1408,  1408,  1409,  1409,  1409,  1409,  1409,  1409,  1409,  1410,
    1410,  1410,  1411,  1413,  1412,  1414,  1412,  1415,  1412,  1416,
    1412,  1417,  1417,  1417,  1418,  1418,  1419,  1419,  1419,  1420,
    1420,  1421,  1421,  1422,  1424,  1425,  1423,  1426,  1427,  1427,
    1428,  1429,  1429,  1429,  1429,  1429,  1430,  1431,  1431,  1432,
    1433,  1434,  1434,  1434,  1434,  1435,  1435,  1436,  1436,  1437,
    1438,  1438,  1438,  1439,  1439,  1439,  1439,  1439,  1440,  1440,
    1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,
    1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1441,  1441,
    1442,  1443,  1444,  1444,  1445,  1445,  1446,  1446,  1447,  1447,
    1448,  1448,  1449,  1450,  1450,  1451,  1451,  1452,  1453,  1453,
    1453,  1454,  1454,  1455,  1456,  1457,  1458,  1459,  1459,  1460,
    1460,  1460,  1460,  1460,  1460,  1461,  1461,  1461,  1463,  1462,
    1464,  1464,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1467,  1466,  1469,  1468,  1471,
    1472,  1470,  1473,  1473,  1473,  1474,  1474,  1474,  1474,  1474,
    1474,  1475,  1475,  1476,  1477,  1478,  1478,  1479,  1479,  1480,
    1480,  1481,  1481,  1481,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1483,  1483,  1483,  1483,  1483,  1483,
    1483,  1483,  1483,  1483,  1483,  1483,  1483,  1483,  1484,  1485,
    1485,  1487,  1486,  1488,  1488,  1489,  1489,  1490,  1491,  1491,
    1492,  1492,  1492,  1492,  1493,  1493,  1493,  1494,  1494,  1495,
    1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1495,  1496,
    1496,  1496,  1496,  1496,  1497,  1497,  1498,  1500,  1501,  1499,
    1502,  1502,  1503,  1503,  1504,  1504,  1504,  1504,  1504,  1504,
    1504,  1505,  1505,  1506,  1506,  1507,  1507,  1508,  1508,  1509,
    1509,  1510,  1511,  1512,  1513,  1513,  1514,  1515,  1515,  1516,
    1517,  1517,  1519,  1518,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,  1520,
    1520,  1520,  1520
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
       1,     1,     2,     0,     3,     0,     3,     0,     3,     2,
       2,     2,     4,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     2,     1,     1,
       3,     4,     4,     2,     2,     1,     1,     1,     1,     1,
       3,     1,     2,     2,     1,     0,     3,     2,     2,     1,
       3,     4,     4,     5,     5,     1,     1,     2,     2,     4,
       4,     2,     2,     4,     4,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     0,     0,     6,     0,     0,     8,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     0,     0,     6,     5,
       5,     5,     7,     4,     6,     0,     3,     1,     1,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     4,
       4,     2,     2,     2,     2,     2,     1,     1,     2,     1,
       1,     1,     2,     4,     6,     6,     3,     5,     5,     3,
       1,     1,     3,     1,     3,     0,     0,    11,     0,     2,
       0,     0,     0,     9,     0,     3,     0,     0,    10,     0,
       1,     0,     1,     1,     2,     0,     3,     0,     3,     0,
       1,     1,     2,     0,     3,     0,     3,     3,     1,     4,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     0,
       3,     0,     3,     0,     4,     0,     4,     0,     4,     2,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     6,     4,     3,     6,     3,     6,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     4,     1,     1,     1,     4,     3,     6,     3,     6,
       1,     1,     2,     2,     2,     1,     3,     1,     2,     2,
       2,     4,     2,     2,     4,     0,     8,     0,     1,     1,
       1,     0,     1,     2,     0,     1,     2,     0,     1,     2,
       0,     1,     3,     0,     2,     0,     0,     8,     0,     0,
       3,     0,     0,     7,     5,     2,     2,     0,     5,     4,
       1,     3,     3,     3,     0,     2,     1,     0,     1,     1,
       2,     0,     4,     0,     4,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     1,     3,     1,     3,     2,     4,     1,
       1,     1,     0,     4,     5,     6,     0,    10,     3,     2,
       2,     1,     1,     0,     2,     1,     2,     3,     3,     3,
       3,     1,     1,     1,     1,     0,     3,     1,     0,     3,
       2,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     7,     1,
       1,     2,     2,     2,     3,     4,     0,     3,     0,     1,
       1,     2,     1,     1,     1,     1,     0,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     1,     1,     1,
       0,     0,     0,     0,    13,     1,     0,     0,     6,     2,
       1,     2,     2,     2,     1,     1,     2,     1,     1,     1,
       0,     3,     2,     1,     0,     0,     0,    14,     0,     5,
       1,     0,     3,     0,     7,     0,     5,     1,     2,     0,
       1,     1,     1,     0,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     0,     0,     7,     1,
       2,     0,     3,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     2,     2,     2,     5,     8,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     2,     2,     3,     6,     1,
       3,     1,     1,     1,     3,     6,     9,     1,     1,     1,
       1,     2,     0,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     2,     0,     1,     1,     4,
       1,     3,     1,     3,     7,     0,     7,     0,     6,     3,
       1,     3,     1,     2,     5,     0,     7,     0,     2,     0,
       1,     5,     2,     5,     0,     5,     6,     4,     0,     1,
       1,     4,     0,     2,     0,     5,     4,     2,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     2,     4,     2,     1,     0,
      11,     0,     2,     5,     0,     1,     0,     2,     1,     2,
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
       1,     3,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       0,     1,     1,     1,     1,     3,     1,     1,     1,     2,
       0,     3,     1,     3,     1,     3,     1,     1,     6,     0,
       3,     1,     3,     0,     1,     4,     5,     2,     1,     1,
       4,     1,     3,     4,     4,     1,     3,     1,     1,     1,
       2,     1,     4,     0,     1,     0,     1,     1,     2,     1,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     0,     2,     1,     1,     5,     3,     5,
       3,     1,     3,     1,     1,     0,     1,     3,     3,     3,
       6,     4,     4,     4,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     1,     5,
       5,     1,     1,     1,     4,     1,     4,     1,     7,     1,
       1,     1,     4,     6,     0,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     1,     0,
       3,     5,     1,     2,     2,     4,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     0,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     0,     7,     0,     8,     0,     6,     0,
       8,     0,     1,     2,     1,     3,     1,     3,     5,     1,
       1,     1,     1,     1,     0,     0,     9,     5,     1,     1,
       6,     0,     3,     1,     3,     4,     1,     0,     2,     4,
       6,     0,     1,     1,     1,     1,     3,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     2,     4,     3,     2,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     3,
       1,     5,     7,     5,     0,     2,     1,     1,     0,     3,
       1,     3,     1,     1,     1,     0,     3,     1,     1,     1,
       1,     4,     6,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     4,     0,     4,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     0,     3,     0,     3,     0,
       0,     6,     0,     2,     2,     7,     3,     3,     2,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     2,     2,     1,     1,     2,     4,     1,     1,
       1,     1,     1,     1,     3,     2,     3,     3,     3,     5,
       5,     5,     5,     5,     4,     4,     3,     4,     1,     1,
       3,     0,     5,     1,     3,     3,     3,     1,     2,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     798,     0,  2112,  2115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   850,   180,     0,   822,   827,
     178,   183,   802,     0,   796,   799,   800,   803,   805,   849,
     804,   844,   845,   847,   184,   135,   132,     0,   128,   130,
     129,   133,  2156,   686,   628,  2119,     0,     0,  2122,     0,
    2118,  2114,  2111,  2109,  2110,  2117,  2116,  2113,   301,  1591,
    1589,   842,   176,   187,   843,   179,   184,     1,   806,   801,
     848,   846,   823,   127,   131,   134,  2126,  2123,     0,  2124,
    2121,     0,     0,     0,   607,     0,     0,   177,   853,   917,
     608,   851,   640,   909,     0,   910,   918,   916,   187,   181,
     200,     0,   185,   201,   236,     0,   829,  1202,     0,     0,
     828,   136,  1190,   836,     0,     0,   819,   821,   818,   820,
     797,   807,   808,   830,   811,   812,   813,   816,   814,   815,
     817,  2125,  2120,     0,  1590,   911,   852,     0,     0,   925,
     923,   924,   913,   912,   299,   187,  1126,   194,   188,   187,
     193,   233,     0,   685,     0,     0,     0,     0,   176,   556,
     886,   809,     0,   333,   319,   203,   270,   289,   310,   312,
     309,     0,   331,     0,   318,   311,   315,   321,   305,   320,
     187,   322,   302,   325,   303,   304,   922,   921,     0,    22,
      23,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   931,     0,   516,   508,    16,   515,   917,    15,     0,
     929,     0,   300,     0,   186,  1127,   182,     0,   200,   202,
     266,   205,   260,   261,   249,   226,   257,   203,   228,   270,
     289,   247,   250,   245,     0,   224,     0,   256,   248,   253,
     259,   241,   258,   187,   262,   187,   239,   240,   237,   265,
       0,     0,     0,     0,   837,   176,   176,     0,     0,   204,
       0,   323,     0,     0,   324,     0,     0,     0,     0,     0,
       0,     0,     0,   268,     0,   919,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   522,     0,
       0,     0,   641,   435,   437,  1197,     0,     0,     0,  1557,
       0,   429,     0,     0,     0,   428,     0,   445,   518,     0,
       0,     0,     0,     0,   521,     0,   394,   393,   400,   441,
     438,   395,   396,   398,   399,   436,   439,   444,   517,   490,
     487,   496,   493,     0,     0,    17,    18,    19,    20,    21,
       0,    14,   481,     0,     0,   927,     0,   189,   192,   190,
     191,     0,   197,   196,   195,   198,   206,   207,   208,   211,
     187,     0,   187,   263,   264,     0,     0,   187,     0,     0,
       0,     0,   246,   234,  1203,     0,     0,  1191,  2162,   557,
     887,   831,     0,   215,   216,     0,   282,   284,   279,   280,
     276,   278,   275,   277,   274,     0,   284,   295,   296,   292,
     294,   291,   293,   286,     0,     0,     0,   335,     0,   338,
     340,   223,     0,   222,     0,     0,   187,     0,  2141,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   540,
     526,   531,     0,   527,   530,   529,     0,     0,    11,   172,
     427,   402,   401,     0,  1132,     0,     0,   443,  1565,  1563,
    1564,  1560,  1562,  1559,  1561,  1553,     0,     0,     0,   442,
       0,     0,     0,     0,     0,     0,     0,   642,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   165,   166,   167,   168,   169,
     170,   523,   524,   525,   456,     0,     0,   455,   465,     0,
       0,   406,     0,     0,   407,   397,   403,   405,   408,   409,
     410,   411,   412,   404,   434,   433,     0,     0,     0,     0,
       0,     0,     0,    12,    93,     0,   930,     0,   914,   199,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,   235,   238,   942,   684,   854,   942,     0,  2160,  2162,
    1126,  1685,   824,     0,   942,     0,     0,   271,     0,     0,
     281,   298,   272,   297,     0,   290,     0,   313,     0,   307,
       0,   332,     0,   337,   327,     0,     0,   316,   306,   269,
     326,     0,     0,     0,     0,   514,   511,   510,   513,   509,
     520,   505,   505,     0,   528,     0,   532,     0,   289,   512,
     519,   273,     0,  1198,  1631,     0,     0,     0,     0,     0,
     430,     0,     0,   446,     0,     0,     0,     0,   448,   447,
     466,   457,   472,   475,   476,   473,   479,   478,   477,   467,
     468,   469,   470,   471,   413,   458,   462,   480,   474,   461,
     480,   440,   491,   488,   497,   494,   503,     0,   482,    94,
      95,    97,   484,     0,     0,   236,     0,     0,     0,     0,
     251,     0,   243,   225,   209,     0,   254,   242,   267,   948,
       0,   943,   944,   942,     0,   838,  2161,  2159,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2143,     0,  1292,  1291,     0,  1293,     0,   387,  1290,  1232,
       0,     5,  1289,   388,   385,     0,   390,   174,   480,  1104,
       0,     0,  1299,   124,   384,   383,  1224,   378,   480,     0,
    1249,  2134,     0,   389,   352,     0,     3,     2,     0,   386,
    1229,     0,     0,   379,   376,   391,     0,     0,     0,     0,
    1297,  1287,   382,     0,     0,     0,     0,     0,     0,     0,
       0,  1286,     0,     0,     0,   175,  1226,   375,   374,     0,
       0,  2138,  2137,     0,     0,     0,   137,  1225,   381,   380,
       0,     0,   377,   480,     0,   480,     0,   550,     0,     0,
       0,     0,     0,     0,   480,   785,  1200,     0,     0,  1108,
       0,  2127,     0,   104,     0,     0,   858,     0,     0,     0,
       0,   786,     0,     0,  1708,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   655,     0,     0,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,  2175,  2176,
    2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,  2186,
    2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,  2196,
    2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  2213,   896,  2214,  2215,
    2216,  2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,
    2226,  2227,  2228,  2229,  2230,  1095,  1097,  1092,  1094,  1093,
    1096,  2231,  2232,  1223,  2233,  1228,  1227,  2234,  2235,  2236,
    2237,  2238,  2239,  2240,  2241,  2242,  2243,  1355,  2244,  2245,
    2246,  2247,  2248,  2249,  2250,  2251,  2252,  2163,   825,   561,
     826,     0,   891,     0,   889,     0,   334,   217,   218,     0,
     283,   288,     0,     0,     0,     0,   336,   339,     0,   221,
       0,     0,     0,   616,     0,   618,  2142,   500,     0,   501,
       0,   542,     0,   539,   536,   507,   499,     0,   171,  1633,
    1634,  1632,     0,   432,  1197,     0,  1558,  1197,   431,  1197,
    1197,  1197,  1197,  1197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
     928,     0,   212,   227,     0,   187,     0,     0,     0,     0,
       0,  1204,     0,     0,  1192,   371,   369,   370,  1034,  1033,
    1037,     0,     0,  1236,   629,   630,   810,  1067,  1072,  2136,
     622,   123,     0,     0,  2101,  2100,  1002,  2097,  2099,  2151,
       0,  1243,     0,  1239,  1248,     7,     0,     6,     0,  2144,
    1068,     0,  1160,  1159,  1107,  1158,  1106,   424,  1300,  1288,
     839,   414,  1687,  1294,   125,     0,  1071,   122,     0,   792,
      24,   624,   392,     0,   791,  1064,   793,     0,  1298,   880,
     879,   882,   878,   881,  2153,     0,   876,     0,   623,   975,
     877,  2147,     0,  2135,   121,   972,   687,   970,     0,   620,
    2130,   730,   729,   731,   727,     0,     0,   985,   625,  1354,
    1349,  1352,     0,     0,     0,  1038,  1035,     0,  1029,  1031,
    1030,  1028,  1027,     0,     0,     0,  1026,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1016,  1007,  1008,     0,  1052,   422,    24,     0,  2132,   126,
     621,     0,  1201,  1199,  1125,     0,  1676,  1677,  1126,  1214,
    1126,  1109,  1110,  1113,  1128,  1301,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     0,   917,     0,    69,     0,
     102,   599,   643,     0,  1098,   992,  1102,     0,     0,  1053,
    1218,     0,     0,  1105,   647,   644,   645,     0,   649,   650,
       0,   652,   653,     0,   648,   952,   954,     0,     0,   953,
     732,   950,   697,   946,   908,     0,     0,     0,     0,   659,
     660,     0,     0,   906,   903,   904,   900,   901,   902,   895,
     899,   898,     0,     0,     0,     0,     0,     0,   565,   567,
     559,   562,   563,   893,  2162,   888,   890,   832,     0,   285,
     287,   314,   308,     0,     0,   317,   613,   615,     0,     0,
     505,   533,     0,   282,     0,     0,  1657,  1548,  1551,  1658,
    1555,  1549,  1655,     0,     0,  1654,     0,     0,  1656,     0,
       0,     0,     0,     0,  2101,  1550,  1653,  1552,  1645,     0,
    1635,  1637,  1640,  1643,  2107,  1644,  1135,  1566,  1134,  1133,
    1136,  1138,  1137,  1131,   459,   460,   464,   449,     0,   452,
     463,     0,   451,   492,   489,   498,   495,   504,   483,    96,
     485,   915,     0,   232,     0,   230,   252,   244,   236,   255,
     949,   176,   945,   855,   176,     0,     0,     0,  1276,  1277,
       0,     0,     0,  1250,  1251,  1253,  1254,  1255,  1259,  1258,
    1256,  1257,     0,     0,  2098,   926,     0,  1004,     0,     0,
    1242,  1241,     0,  1235,     0,  1535,  1536,     0,  1069,     0,
      24,  1155,  1157,  1156,   417,   418,   415,   416,   962,     0,
       0,   357,    25,   351,     0,     0,  1061,     0,     0,     0,
       0,     0,     0,     0,   979,  1686,     0,     0,   187,     0,
       0,     0,  2132,     0,     0,   138,     0,     0,   989,   981,
     982,   987,  1350,  1351,     0,   905,   420,  2091,   341,     0,
     551,   604,   603,   601,   606,  1010,   605,  1015,  1011,  1014,
     784,   776,   770,   782,   783,   768,   769,   777,   772,   778,
     771,   781,   775,   779,   774,   780,   767,   773,   760,   766,
    1012,  1013,     0,  1020,  1024,  1017,  1018,  1022,  1023,  1021,
    1019,  1025,     0,   794,     0,     0,     0,     0,     0,   742,
     741,   738,  2133,  2140,    24,  1121,  1122,  1123,  1124,  1118,
    1116,  1215,  1130,  1115,  1111,     0,     0,  1112,  2128,     0,
       0,     0,     0,    98,     0,    99,     0,     0,     0,    74,
       0,     0,     0,   111,   106,     0,   885,     0,   884,     0,
     480,  1100,     0,   937,   938,   961,   932,   933,   787,   959,
    1055,  1220,     0,  1222,  1221,  1765,  1883,  1879,  1885,  1917,
    1897,  1888,  1847,  1809,  1937,  1903,  1911,  1800,  1906,  1766,
    1712,  1898,  1805,  1856,  1991,  1835,  1823,  1836,  1935,  1938,
    1905,  1859,  1941,  1724,  1998,  1934,  1962,  1735,  2035,  1824,
    2007,  1717,  1967,  1733,  1795,  1842,  1862,  1957,  1985,  1990,
    1716,  1914,  1943,  1728,  1730,  1754,  1772,  1793,  1803,  1813,
    1866,  1869,  1928,  1939,  1945,  1946,  1963,  2008,  2019,  1715,
    1746,  1771,  1770,  1773,  1779,  1781,  1789,  1799,  1820,  1838,
    1841,  1867,  1875,  1932,  1942,  1952,  1958,  1959,  1961,  1986,
    2016,  2023,  2028,  1736,  1739,  1750,  1757,  1759,  1764,  1767,
    1769,  1776,  1784,  1786,  1787,  1788,  1798,  1808,  1815,  1831,
    1832,  1843,  1861,  1865,  1878,  1894,  1918,  1926,  1936,  1940,
    1947,  1955,  1964,  1974,  1978,  1995,  2001,  2005,  2013,  2018,
    2021,  1760,  1880,  1923,  1744,  1745,  1763,  1768,  1775,  1777,
    1791,  1792,  1802,  1811,  1816,  1818,  1819,  1825,  1833,  1850,
    1851,  1864,  1892,  1896,  1899,  1904,  1908,  1916,  1924,  1925,
    1930,  1948,  1949,  1954,  1960,  1965,  1971,  1972,  1973,  1975,
    1977,  1979,  1988,  2010,  2011,  2012,  2017,  2034,  1719,  1874,
    1882,  1884,  1981,  1721,  1725,  1729,  1734,  1740,  1741,  1755,
    1756,  1758,  1761,  1774,  1790,  1810,  1812,  1822,  1826,  1828,
    1829,  1837,  1846,  1848,  1849,  1860,  1873,  1891,  1909,  1910,
    1927,  1929,  1933,  1944,  1966,  1976,  1984,  2006,  2009,  2024,
    2025,  2026,  1752,  1722,  1742,  1743,  1749,  1821,  1751,  1753,
    1778,  1780,  1794,  1871,  1996,  1804,  1806,  1814,  1817,  1839,
    1840,  1845,  1852,  1853,  1854,  2037,  1886,  1887,  1890,  1895,
    1900,  1907,  1912,  1913,  1915,  1922,  1951,  1953,  1969,  1980,
    1982,  1983,  1987,  1992,  1993,  1997,  1999,  2000,  2015,  2020,
    2022,  2027,  2029,  2033,  1881,  2032,  1718,  1720,  1723,  1727,
    1737,  1762,  1782,  1783,  1785,  1796,  1827,  1830,  1870,  1876,
    1889,  1893,  2030,  2031,  1931,  1950,  1956,  1968,  1970,  1989,
    1994,  2004,  2014,  1732,  1726,  1731,  1748,  1801,  1844,  1857,
    1858,  1919,  1921,  2003,  1877,  1834,  1901,  1747,  1797,  1807,
    1872,  1855,  1902,  1738,  1863,  1868,  2002,  1920,     0,  1710,
    1713,  1714,   675,     0,     0,     0,   664,   697,   697,   694,
       0,     0,   698,     0,    26,   663,   666,     0,   673,   669,
     907,   897,  1683,  1684,  1674,  1674,  1319,     0,     0,  1592,
       0,   187,  1302,     0,     0,  1303,  1347,   187,     0,  1348,
       0,  1631,     0,  1316,     0,  1366,  1365,  1364,  1362,  1363,
    1361,  1359,  1356,  1430,  1429,  1357,  1358,  1367,  1613,  1360,
    1690,  1689,  1688,  1368,  2162,  2162,   578,   569,   560,     0,
     564,  2162,   892,   176,     0,   328,   220,     0,     0,  1573,
    1571,  1572,  1568,  1570,  1567,  1569,   506,   502,     0,   538,
     537,   173,  1642,  1641,  1581,  1579,  1580,  1576,  1578,  1575,
    1577,  1554,     0,  1631,     0,     0,  1498,     0,  1498,  1498,
    1498,  1498,  1646,     0,     0,     0,  1447,  1621,  1638,     0,
       0,     0,     0,  1699,  1700,  1701,  1702,  1703,  1704,  1649,
       0,     0,   454,   453,     0,     0,   187,   229,   210,  1205,
     176,  1193,  1420,     0,  1419,     0,  1421,     0,  1422,  1279,
       0,  1285,  1281,  1278,     0,     0,     0,     0,     0,     0,
    1275,  1271,  1409,  1408,  1407,  1247,  1246,     0,  1270,  1266,
       0,  1262,  1260,     0,   633,     0,   632,     0,  1003,     0,
       0,  1001,  2104,  2106,  2105,  2102,  2152,  2149,  1240,     0,
       0,     0,  1233,   480,   349,     0,     0,  1230,   994,  1065,
    1066,  1063,  1062,     0,   883,     0,     0,   609,     0,     0,
       0,   973,   971,     0,   689,   690,     0,     0,  2131,  2139,
     728,     0,   142,     0,   983,   990,     0,     0,   998,  1353,
       0,   187,   344,     0,     0,     0,     0,    24,  1036,   554,
       0,     0,     0,   761,   762,  1009,   795,   423,     0,  1044,
     739,   740,   372,     0,  1126,     0,  1129,  1114,  2162,     0,
       0,     0,   543,     0,     0,     0,     0,    64,    93,     0,
       0,   117,   112,     0,   107,     0,   114,   108,   869,   861,
     867,     0,  1099,     0,  1101,  1103,     0,     0,   941,     0,
       0,     0,     0,  1054,  1219,     0,     0,  1709,  1711,  2162,
     646,   651,   654,   667,   665,   626,     0,   717,   715,   721,
     719,     0,     0,   713,   757,   711,   696,   707,   705,   755,
     733,     0,   699,   709,   951,   947,     0,     0,     0,     0,
     672,     0,     0,     0,     0,     0,     0,     0,  1538,     0,
    1425,  1426,  1695,  1389,  1447,     0,     0,  1693,     0,     0,
    1614,  2039,     0,  1372,  1378,  1377,  1376,  1380,     0,  1373,
    1374,   566,   568,     0,     0,   581,   573,   575,     0,   570,
     571,     0,     0,   589,   591,     0,     0,   587,   894,   833,
     219,     0,   617,   619,   614,     0,   535,   534,     0,     0,
    1666,     0,     0,     0,  1500,  1501,  1499,     0,  1668,     0,
       0,     0,     0,     0,     0,     0,  1636,     0,  1436,  1437,
    1439,  1442,     0,  1448,  1449,     0,     0,  1498,  1623,  1617,
    1651,  1652,  1650,  1648,  2108,   450,   486,     0,   231,  1161,
     856,  1139,  1397,  1399,     0,  1283,     0,     0,     0,     0,
       0,  1273,     0,     0,  1530,  1528,  1515,  1517,  1513,     0,
    1512,     0,  1521,  1508,  1529,     0,  1520,  1505,  1511,  1527,
    1519,  1413,  1502,  1503,  1504,     0,  1268,  1264,     0,     0,
    1252,   631,     0,     0,     0,     0,     0,  2148,     4,     8,
      10,  1534,  1537,     0,   480,   419,     0,     0,     0,   991,
       0,     0,     0,     0,     0,     0,     0,   187,   688,     0,
       0,   159,   157,     0,     0,   139,     0,   149,   155,   697,
     144,   146,     0,   988,   999,  1000,     0,   421,     0,  2092,
    2093,   343,   348,   611,   342,     0,   345,   350,   480,  1325,
     602,   600,     0,   764,  1043,  1045,     0,   373,  1119,  1117,
    1216,  1217,     0,     0,  1210,     0,     0,     0,     0,   100,
       0,     0,    75,    81,    71,  2162,  2162,   110,   105,   119,
     115,     0,   109,   758,   870,   626,  2162,   860,   859,   868,
     993,     0,     0,   939,   940,   934,   960,   480,  1060,  1056,
    1057,  1059,  2036,   957,  2038,   955,   676,   670,   668,     0,
      24,     0,  2162,  2162,  2162,  2162,   723,   701,   725,   703,
    2162,  2162,  2162,  2162,     0,   695,   700,  2162,   626,   753,
     751,   754,   752,     0,     0,    46,    44,    41,    35,    39,
      43,    38,    31,    40,     0,    34,    37,    32,    42,    33,
      45,    36,     0,    29,    47,   745,     0,   674,  1675,     0,
    1673,  1631,  1671,  1618,  1619,  1611,  1597,  1612,     0,     0,
       0,  1032,  1424,  1427,     0,     0,     0,  1337,  1308,  1698,
    1697,  1696,     0,     0,     0,     0,  1332,     0,  1331,     0,
    1333,  1328,  1329,  1330,  1321,  1317,     0,     0,  1379,     0,
       0,   580,   585,     0,     0,  2162,  2162,   558,   572,   595,
     583,   597,  2162,  2162,   593,   577,   588,   824,   329,     0,
    1588,  1586,  1587,  1583,  1585,  1582,  1584,  1556,     0,     0,
       0,  1667,     0,     0,     0,  1665,     0,     0,     0,     0,
    1647,  1664,     0,  1440,     0,  1547,  1443,     0,     0,     0,
       0,  1435,  1453,  1455,  1457,  1497,  1496,  1495,  1459,  1475,
       0,  1450,  1451,  1626,  1237,     0,     0,     0,   213,     0,
    1187,  1206,   824,     0,  1194,  1187,     0,     0,  1280,     0,
    1282,     0,  1539,     0,  1398,     0,  1401,  1542,     0,  1405,
       0,  1272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1411,     0,  1414,  1415,     0,  1267,     0,  1261,
    1263,  2103,     0,     0,     0,  2150,     0,     0,  1244,   840,
       0,     0,     0,     0,     0,  1295,  2155,  2154,   610,     0,
       0,    48,     0,   693,   692,   691,  1296,   697,  2162,  2162,
     151,   634,   161,   153,   163,   143,   150,  2162,     0,     0,
       0,     0,     0,     0,   187,     0,     0,  1326,   552,     0,
     763,  1041,     0,  2129,     0,    93,   544,     0,    65,     0,
       0,     0,    78,     0,    93,    93,   118,   113,  2162,  2162,
     103,     0,   871,   865,   873,   872,   862,   548,   920,     0,
       0,     0,     0,     0,   678,   657,   671,   627,   734,     0,
     718,   716,   722,   720,     0,  2162,     0,  2162,   714,   712,
     708,   706,   756,   710,    24,   746,     0,     0,     0,    27,
       0,  1678,     0,  1598,     0,     0,  1610,  1593,  1609,  1428,
       0,  1391,     0,  1336,     0,     0,  1694,     0,  1691,  1615,
       0,     0,     0,     0,     0,     0,  2040,  1335,  1334,  1322,
    1320,     0,  1382,     0,  1375,     0,   582,   579,   574,   576,
       0,  2162,  2162,   590,   592,  2162,  2162,     0,  1574,     0,
       0,     0,     0,  1663,  1669,  1659,  1660,  1661,  1662,  1444,
       0,  1438,  1458,     0,  1462,     0,  1475,  1461,     0,     0,
    1476,  1491,  1488,  1489,  1486,  1494,  1493,  1487,  1490,     0,
       0,     0,     0,     0,  1492,     0,     0,     0,  1432,  1433,
    1639,     0,  1452,  1446,  1238,  1624,  1342,  1338,  1339,  1344,
    1343,  1622,  1237,     0,  1185,  1186,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1184,     0,     0,
    1172,  1173,  1174,  1171,  1176,  1177,  1178,  1175,  1162,  1153,
       0,     0,  1209,     0,  2162,     0,  1148,     0,     0,     0,
       0,     0,     0,     0,  1140,  1141,     0,  1073,     0,  1284,
    1423,  1543,     0,  1544,     0,     0,     0,     0,  1404,  1274,
    1403,  1395,     0,     0,     0,  1532,  1524,  1524,     0,     0,
    1524,  1531,     0,  1548,  1410,  1412,  1416,  1417,  1269,  1265,
    1006,     0,   969,     9,     0,  1237,   841,  1070,   355,  1231,
       0,     0,  2146,     0,     0,   974,    49,     0,   743,   160,
     158,     0,  2162,     0,     0,     0,  2162,   156,   145,     0,
     148,   147,     0,   980,   984,  2096,  2095,  2094,   347,     0,
     555,     0,  2162,   765,     0,   626,  1120,     0,  1211,    70,
       0,     0,   101,    68,    93,    76,    82,     0,   120,   116,
     759,  2162,   875,   626,   874,     0,   545,     0,   789,   790,
     788,  1058,   958,   956,   681,   679,     0,   661,   658,     0,
     724,   702,   726,   704,   735,   749,   750,   747,   748,    30,
      28,     0,  1672,  1627,  1599,  1595,  1594,     0,  1390,  1631,
    1393,     0,  1310,  1305,  1304,  1307,     0,  1627,     0,     0,
    2073,  2071,     0,     0,  2059,  2070,     0,     0,  2072,     0,
       0,     0,     0,     0,  2101,  2069,  2065,     0,  2057,  2060,
    2061,  2068,  2064,  2088,     0,  2050,  2049,  2053,  2055,     0,
    2048,     0,  2051,  2042,  1323,  1318,     0,  1381,     0,   586,
     584,   596,   598,   594,     0,     0,  1630,     0,  1707,     0,
       0,  1441,  1460,  1454,  1456,  1463,  1465,  1463,     0,  1470,
    1463,     0,  1468,  1463,     0,  1478,  1477,     0,  1479,     0,
    1431,     0,  1346,  1345,  1341,  1625,   236,  1179,  1180,  1181,
    1183,  1166,  1164,  1163,  1167,  1168,  1165,  1182,  1169,  1170,
    1154,   966,  1189,   963,     0,     0,  1207,     0,  1152,  1151,
    1146,  1144,  1143,  1147,  1145,  1149,  1150,  1142,  1195,  1400,
       0,  1396,  1402,  1546,  1539,  1406,  1514,     0,  1516,     0,
       0,     0,     0,  1522,  1526,     0,  1506,  1418,  1005,  1245,
    1234,     0,    24,     0,     0,   997,     0,    50,   977,     0,
      24,   162,   152,     0,   636,   638,   164,   154,   743,     0,
     346,  1327,     0,  1042,    24,     0,     0,    66,     0,    79,
      88,     0,    72,   866,   863,   549,  2162,   935,     0,  2162,
     677,   656,   662,   626,  1682,     0,  1680,     0,     0,  1600,
    1596,  1392,     0,  1394,  1388,     0,  1309,     0,  1692,     0,
    2063,  2062,     0,     0,  1498,     0,  1498,  1498,  1498,  1498,
    2066,     0,     0,  2046,     0,     0,     0,     0,  2075,  2047,
       0,     0,     0,     0,     0,     0,  2041,     0,  1383,  1386,
    1370,  1384,  1387,   835,   834,   330,  1705,  1706,  1445,     0,
    1482,  1484,     0,  1471,  1474,  1473,  1481,     0,  1483,  1463,
       0,  1434,  1340,   214,   968,   967,   965,     0,  1188,  1074,
    1078,  1080,     0,  1084,     0,  1082,  1086,  1075,  1076,     0,
     857,     0,     0,  1540,  1545,     0,  1533,  1525,  1509,  1507,
       0,  1510,   356,   353,     0,   995,     0,     0,     0,   976,
     744,   140,   635,    24,   986,   553,  1039,    67,  1212,    84,
       0,     0,    77,    88,    88,  2162,   546,     0,     0,   680,
     736,     0,  1679,  1628,  1621,     0,  1311,     0,  1621,  2086,
       0,     0,  2089,     0,     0,     0,     0,     0,     0,     0,
    2058,  2077,  2078,  2076,  2074,  2056,     0,  2052,  2054,  2043,
    2044,  1324,     0,  1371,  1369,  1464,  1670,  1466,     0,  1469,
    1467,  1485,     0,   964,  2162,  2162,  1088,  2162,  1090,  2162,
    2162,  1077,  1208,  1196,     0,     0,  1523,   358,   996,  2145,
       0,     0,     0,     0,     0,     0,    55,     0,    54,     0,
      52,     0,     0,   141,  1046,    88,    93,    88,    89,    83,
      73,   864,     0,     0,   682,    24,  1681,  1620,  1629,  1315,
       0,  1312,  1314,  1601,  2087,     0,     0,  2085,     0,     0,
       0,     0,  2067,  2084,     0,  1385,  1472,  1480,  1079,  1081,
    2162,  1085,  2162,  1083,  1087,  1541,  1518,   360,   365,   363,
     354,     0,   361,   367,    57,    62,    59,    61,    58,    60,
      56,     0,    51,     0,   637,   639,  1050,  1040,     0,  1048,
    1213,    85,    80,   547,   936,  2162,   737,     0,  1306,     0,
    1602,  1616,  2083,  2090,  2079,  2080,  2081,  2082,     0,  1089,
    1091,  2162,  2162,   359,   362,  2162,    53,     0,  2162,  1047,
    1049,     0,   678,  1313,     0,  1606,  1603,  1604,  2045,   366,
     364,   368,     0,  1051,    86,   683,     0,     0,     0,   978,
      90,     0,  1607,  1605,    92,     0,    87,     0,    91,  1608
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   827,   828,   829,   830,  1046,  2328,  2329,   211,   350,
     212,  1381,  1382,  2177,  2482,  3408,  2945,  2946,  3317,  3409,
    3410,   831,  1174,  2980,  2705,  3334,  2118,  2703,  3200,  2984,
    3330,  2704,  3201,  3416,  3511,  3530,  3332,  3536,   658,   659,
     660,  1494,  2398,   832,  1505,  1179,  1503,  2126,  2408,  2123,
    2406,  2411,  2709,  1504,  2405,  2127,  2708,   833,    18,    37,
      38,    39,    40,    41,   117,   836,  1106,  2072,  1405,  2355,
    2359,  2360,  2356,  2357,  2952,  2956,  2677,  2669,  2668,  2670,
    2673,   514,   298,   612,   837,    86,    87,    20,    63,   146,
      99,   283,   101,   102,   227,   364,   103,   104,   270,   369,
     256,  1008,   540,  2853,   395,   939,  2231,   422,   423,   257,
     377,   370,   372,  1324,  1325,   150,   552,   151,   152,   383,
     258,   259,  2063,   590,   271,   274,   272,   273,   404,   567,
     568,   570,   575,   942,   275,   276,   413,   572,   223,    21,
      82,   182,   183,   184,   948,  2797,   185,   279,   268,   416,
     417,   418,   419,  2087,   838,   839,   840,   841,  1065,  3397,
    3172,  1383,  3460,  3461,  3462,  3502,  3501,  3505,   842,   843,
     844,   845,   846,   847,   848,  1057,   515,  1060,  1375,  1376,
    1415,  1144,  1416,   325,   326,   327,   328,   329,   330,   331,
     472,   516,  1308,   517,   518,   519,   520,   521,   522,   523,
     987,   213,   534,   997,   999,  1984,   214,   528,   993,   527,
     992,   530,   995,   529,   994,   957,   966,   332,   333,   216,
     334,   442,   443,   444,   445,  2111,   849,  3206,  3422,  2996,
     850,  1117,  2089,  2972,  2379,   118,   265,   562,  1917,  1240,
    1241,  1242,  1914,  1915,  2218,  2219,  2220,  2535,  2536,  1918,
    1919,  2214,  2539,  2531,  2226,  2227,  2542,  2543,  2795,  2791,
    2792,   851,  1425,    88,  2058,  2059,  2374,   428,  1098,  1149,
    1029,  1087,  1070,  1107,  2440,   217,  1030,  1024,  2025,  2672,
      90,   335,   852,   853,  1195,  1196,   854,   855,   856,   857,
    1203,  3007,  1224,  3211,  1225,  2153,  1226,  2437,  1227,  2725,
    1228,  2180,   858,  2149,  2724,  3006,  3209,  3208,  3485,   119,
      22,   859,  1399,  2064,  2065,  2170,  1863,  2171,  2172,  2735,
    2737,  2453,  2452,  2457,  2451,  2450,  2443,  2442,  2445,  2444,
    2447,  2449,   860,   861,  1104,   862,  1859,  1210,  3425,   863,
    1471,  3180,  2484,  2485,  2173,  2454,  2414,  2711,  1140,  1453,
    2093,  2382,  2094,  1449,   864,   865,  1188,  2141,  3000,   866,
     867,   868,   869,    23,    68,    24,    25,    26,   120,   121,
     870,   122,    27,   929,    28,   123,   124,   162,   564,  1923,
    2547,  3264,   125,   158,   388,   871,  2650,    29,    30,    31,
      32,    33,    62,    91,   126,   683,  1990,  2602,   872,  1183,
    2418,  2130,  2416,  3335,  2991,  2131,  2415,  2714,  2993,   873,
     874,   875,  1081,  1082,  1507,   127,   266,   563,   933,   934,
    1244,  1921,   876,  1229,  1230,   877,  1871,  1231,   336,    93,
      94,    95,    96,  1514,   188,   142,    97,  1035,   139,   219,
     220,  1515,  1516,  2425,  1517,   680,   681,  1212,   682,  1213,
    2434,  2435,  1518,  1519,  1379,  3132,  3133,  3286,  2034,  1096,
    1097,   878,  1394,  3319,   879,  2964,   880,  1409,  1410,  1411,
    2078,  2076,   881,   882,  2339,  2366,   883,  1357,  2031,   884,
    1141,  1142,   885,  1020,   886,  2495,   887,  3414,  2975,   888,
    2386,  3477,  3478,  3479,  3508,  1146,   889,  1520,  2143,  2429,
    2430,   890,  2051,  1028,  1369,   891,   892,   893,  2604,  3136,
    3297,  3298,  3384,  3385,  3389,  3387,  3390,  3450,  3452,   894,
     895,  1509,  2135,   896,  1511,  1160,  1161,  1162,  1487,   897,
     898,   899,  2104,  1479,  1155,   226,  1163,  1164,   337,  2605,
    2894,  2895,  2878,  1054,  1055,  2600,  2879,  2882,   128,   157,
     556,  1334,  2281,  2896,  3301,   454,   900,  1153,   129,   154,
     553,  1331,  2279,  2883,  3299,  2601,  1178,  2695,  3196,  3415,
    1482,   901,   902,   903,   904,   905,  1068,  2337,  1048,  2333,
     906,  2845,  1042,  1043,  2647,  2010,   907,   908,  1343,  1344,
    1345,  2022,  2318,  1346,  2315,  2019,  1347,  2290,  2011,  1348,
    1349,  1350,  1351,  2284,  2002,   909,  1077,  1059,   910,  1895,
    1896,  2195,  3034,  3227,  2765,  3031,  3430,  3431,  1897,  2202,
    2779,  1877,  2525,  3075,  3257,  2688,  2971,  2526,  1898,  1899,
    2268,  2847,  2848,  2849,  3114,  1900,  1901,  1413,   911,  1110,
     912,  1237,  1902,  1903,  3374,  2208,  2209,  2210,  2528,  2781,
    3260,  3261,  1904,  2505,  2760,  3224,  2012,  2013,  1998,  2613,
    2282,  2614,  2014,  2618,  2015,  2634,  2016,  2635,  2925,  2926,
    2285,  1905,  2189,  2190,  2502,  1906,  2842,  2591,  2838,  2263,
    1966,  2258,  2259,  2260,  2810,  1967,  2264,  2592,  2843,  2581,
    2582,  2583,  2584,  2585,  3270,  3095,  3375,  2586,  3272,  3273,
    2836,  2587,  2837,  2588,  2247,  2311,  2312,  2313,  3160,  2314,
    2922,  2916,  3307,  2615,  3262,  2903,  3067,  2617,  2576,  1286,
     338,  1287,  1951,   465,   958,  1936,  1952,  2557,    61,   913,
     914,  3026,  3220,  2753,  3219,  3491,  3516,  3517,  2757,  2496,
    1907,  2497,  2514,  3037,   615,  2492,  2493,  2269,  2594,  3218,
    3030,  1288,   972,  1289,  1290,  2839,  2589,  1292,  1293,  2249,
    3377,   915,   916,  2182,  2494,  3022,  3215,  3216,  1874,   917,
    1063,  1909,  1910,  2198,  2767,  1911,  1912,  2511,  1979,  2242,
     918,  1191,  1848,  1849,  1850,  2145,  1851,  2146,  1913,  2515,
    3073,  3256,  2776,  3070,  3071,  3072,  3069,  3057,  3058,  3059,
    3060,  3061,  3062,  3353,   919,  2081,  2369,  2370,  1036,  1294,
    1038,  2035,  1295,    66,    50,    80,    77,   921,  1166,  2108,
    1402,  1473,   922,   430,   923,  2661,   924,  2327,  1040,  2037,
     925,   926,    44,   557,   558,   559,   560,   561,   927
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2706
static const short yypact[] =
{
    1943,   923, -2706, -2706,   431,   597,   597,   597,   597,   597,
     597,   597,   597,   431,   295, -2706, -2706,   295, -2706,  3284,
   -2706, -2706, -2706,   426, -2706,  1943, -2706, -2706, -2706, -2706,
   -2706,  1997, -2706, -2706, -2706, -2706, -2706,   495,   881, -2706,
     908, -2706, -2706, -2706, -2706, -2706,   431,   156, -2706,   334,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
     381, -2706,  3041,   679, -2706, -2706, -2706, -2706,  3711, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   431, -2706,
   -2706,   156,   420,   431, -2706,   431,   757,  3284, -2706,   690,
   -2706, -2706, -2706, -2706,  1062,   462, -2706, -2706, -2706,  1092,
     710,   431, -2706, -2706,  1117,   431, -2706, -2706,   431,   431,
   -2706, -2706, -2706, -2706,   431,   431, -2706, -2706, -2706, -2706,
   -2706,  3711, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706,  4016, -2706,   462, -2706,   960,  2771, -2706,
   -2706,   663, -2706, -2706,  1164,   679,   666, -2706, -2706, -2706,
   -2706, -2706,  9266, -2706,   431,   777,  1102,   431,  3284, -2706,
   -2706, -2706,   431, -2706, -2706,   683,   846, -2706, -2706,   798,
   -2706,   809, -2706,   791, -2706, -2706,   831, -2706,   836, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   845, -2706,
   -2706, -2706,   868,   914,   925,   933,   967,   973,   990,   994,
    1007,  1027,  2771,  1041,  4850,  1050,  1070,  1078,  1083,  1090,
    1112,  1766,  1256, -2706, -2706, -2706, -2706,  1038, -2706,   164,
   -2706,  2771, -2706,   177, -2706, -2706, -2706,    99, -2706, -2706,
   -2706,   702, -2706, -2706, -2706, -2706, -2706,   683, -2706,   846,
   -2706, -2706,  1122, -2706,  1126, -2706,   822, -2706, -2706,  1130,
   -2706,  1131, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
    1134,  1286,   431,  1136, -2706,  3284,  3284,  1140,   431, -2706,
     -26, -2706,   708,  1003, -2706,   808,  1203,  1446,  1557,   431,
    1558,  1566,  1580, -2706,   995, -2706,    64,    64,    64,    64,
      64,  4850,  1173,  1292,    64,  4850,   903,  4850, -2706,  4850,
    4850,  4850, -2706, -2706, -2706,  1086,  1183,  1186,  4850,  1275,
    1187, -2706,  4850,  4850,  1191, -2706,  1192, -2706,  1070,  1193,
    1194,  1197,  1205,  1616,  8378,    74, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706,  1218, -2706, -2706, -2706,
   -2706, -2706, -2706,   267,   267, -2706, -2706, -2706, -2706, -2706,
    2771, -2706, -2706,   431,  2771,  1181,   179, -2706, -2706, -2706,
   -2706,  1624, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   -26, -2706, -2706, -2706,  1628,  1629,   679,  1558,  1632,
    1633,  1035, -2706,  1600, -2706,  1268,  1230, -2706,  1305, -2706,
   -2706, -2706,  1051, -2706, -2706,  1649, -2706,  1243, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  1203,  1243, -2706, -2706, -2706,
   -2706, -2706, -2706,  1244,   176,   234,   231, -2706,  2195, -2706,
   -2706, -2706,  1245,  1678,   247,  1289, -2706,  1259, -2706,  -148,
     255,  1295,  1299,   257,   258,  4973,  1300,  -104,  1382, -2706,
   -2706,   146,  1302, -2706, -2706, -2706,   369,  7521, -2706,  3571,
    8718,  1045,  1045,  4850, -2706,  1226,  4850,  8378,  1267, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706,  1073,  1686,  7571,  8378,
    1226,  1687,   479,  4850,  4850,  4850,  4850, -2706,  4850,  4850,
    4850,  4850,  4850,  4850,  4850,  4850,  4850,  4850,  4850,  4850,
    4850,  4850,  4850,  4850,  4850, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  4850,  4850, -2706, -2706,  1273,
    4850, -2706,  4850,  1276, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706,   267,  4850,  4850,  4850,
    4850,  1321,  1712,  1766,  4850,  1288, -2706,  2771,  1263, -2706,
    1113,  1127,  1725,  1490,   371,   372,   269,  1323,   377,  1361,
   -2706, -2706, -2706,   431, -2706, -2706,   431,  1391, -2706,  6656,
     666,  6946,  2092,   409,   431,  1739,   774, -2706,  1003,  1736,
   -2706, -2706, -2706, -2706,  1741, -2706,  1743, -2706,  1744, -2706,
     431, -2706,   431, -2706, -2706,  1558,  1746, -2706, -2706, -2706,
   -2706,   431,  2771,    53,    64, -2706, -2706, -2706, -2706, -2706,
   -2706,  1275,  1275,  1747, -2706,  1754,  1170,  1048, -2706, -2706,
   -2706, -2706,  1385,  8378,   -91,  1399,  7635,  1768,  1275,  1401,
   -2706,  1404,  1407, -2706,  7682,  7746,  7860,  8074,  8527,  8591,
    8718,  1436,  3909,  8783,  8915,  3499,  5074,  9002,  8851,  1045,
    1045,  1538,  1538,  1430,  8378,  8199,  8263,  1226,  8378,  8331,
    1226, -2706,  8378,  8378,  8378,  8378, -2706,  1781, -2706,  1806,
   -2706,  8378, -2706,   190,  2771, -2706,  1793,   774,  1378,  1791,
   -2706,  1794, -2706, -2706, -2706,  1795, -2706, -2706, -2706,  1198,
    1427,  1824, -2706,   431,  1433, -2706, -2706, -2706,   267,   267,
     267,   975,   431,   180,   431,   431,   180,   180,   985,   431,
   -2706,   431, -2706, -2706,   431, -2706,   962, -2706, -2706, -2706,
     180, -2706, -2706, -2706, -2706,   431, -2706, -2706, -2706, -2706,
     110,   110,  4850, -2706, -2706, -2706, -2706, -2706, -2706,   180,
   -2706, -2706,   180, -2706, -2706,   431, -2706, -2706,   180, -2706,
   -2706,   267,   180, -2706, -2706,  4850,   180,   267,   431,   267,
     180, -2706, -2706,   101,   180,   180,   101,   180,   431,   101,
     180, -2706,   180,   180,   180, -2706, -2706, -2706, -2706,   267,
     180, -2706, -2706,   180,    61,   431, -2706, -2706, -2706, -2706,
     180,   992, -2706, -2706,   267, -2706,   180, -2706,  2821,   267,
    4850,    64,    64,   180, -2706, -2706,   975,   267,  1063,  4850,
    4850, -2706,  1129,  4850,   180,   156, -2706,  4850,   180,  1805,
     267, -2706,   180,  4850, -2706,  4850,   110,   431,   180,   431,
      64,   180,   431,    64, -2706,   431,   275, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,   261, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,  1270, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   789,
   -2706,   431, -2706,   584, -2706,  1439, -2706, -2706, -2706,  1531,
   -2706, -2706,  1443,  1444,  1455,  1456, -2706, -2706,  1236,  1850,
    1462,  1471,   830, -2706,  1437, -2706, -2706, -2706,  1235, -2706,
    1472, -2706,  1848, -2706,  1280, -2706, -2706,  1251, -2706, -2706,
   -2706, -2706,  8973, -2706,  1086,  1488, -2706,  1086, -2706,  1086,
    1086,  1086,  1086,  1086,  1862,  1864,  1865,  4850,  1497,  1872,
    4850,  1504,  1505,  1506,  1508,  1509,  1510,  1511,  4850,  4850,
   -2706,   226, -2706, -2706,  1604, -2706,  1522,  1523,  1293,  1524,
     431, -2706,   431,  1527, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   383,  1489, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1301,  1265,  1464, -2706,  1307, -2706,  1306, -2706,
    1924,  -198,   394, -2706, -2706, -2706,  1501, -2706,  1364, -2706,
    1451,   208, -2706, -2706, -2706,  1409, -2706,  8378, -2706, -2706,
   -2706,  4226, -2706, -2706, -2706,   267, -2706, -2706,  1364, -2706,
      68, -2706, -2706,  1665, -2706,   158, -2706,  1474, -2706, -2706,
   -2706, -2706,  1936, -2706, -2706,   609, -2706,  1319, -2706,  1322,
    1936, -2706,  1342, -2706, -2706,  1518,   184, -2706,  1483, -2706,
    1290, -2706, -2706, -2706, -2706,  1294,   632,  -208, -2706,  1301,
    1618,  1333,  4850,   200,  4850, -2706,  1944,   180, -2706, -2706,
   -2706, -2706, -2706,    76,    76,    76, -2706,    76,   795,    76,
      76,  1355,    68,  1355,  1355,  1139,  1139,  1355,  1355,    68,
   -2706,  1957, -2706,   -35,  1958, -2706,    68,    73,    36, -2706,
   -2706,  4850, -2706, -2706, -2706,   993, -2706, -2706,   666,  1575,
     666,  4850, -2706,    91, -2706, -2706,  4850,  1533,  1534,  1535,
    1539,  1395,  1542,  1063, -2706,  1635,  1047,  1386, -2706,  1402,
   -2706, -2706, -2706,  1195, -2706,  1979, -2706,  1974,   431, -2706,
     297,  6061,  1410, -2706, -2706,  1988, -2706,  1332,  1988,  1996,
    1340,  1988,  1996,  4850,  1988, -2706, -2706,   208,   267, -2706,
   -2706,  1577,   284, -2706, -2706,  1571,   267,  4850,  1572, -2706,
   -2706,  1986,  1991,  1949, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1216,  1216,   180,   180,   180,  3917, -2706, -2706,
    1918,   789, -2706, -2706,   723, -2706, -2706, -2706,  1556, -2706,
   -2706, -2706, -2706,  4016,  1558, -2706, -2706,  1396,   431,  1285,
    1275,  1431,  1435, -2706,  3359,  3359, -2706,  1301, -2706, -2706,
    1359, -2706, -2706,  6312,  1586, -2706,  1593,  1595, -2706,  1596,
    1605,  1609,  1611,   431,   543, -2706, -2706, -2706, -2706,   188,
   -2706,   431,  2305, -2706,  1627, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,  8378,   399, -2706,
   -2706,   400, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1592, -2706,   406, -2706, -2706, -2706, -2706, -2706,
   -2706,  3284, -2706, -2706,  3284,   828,   161,  2024, -2706, -2706,
     167,   191,   169,  2054, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1457,  1265,  1306, -2706,   985,  -241,  1264,   431,
   -2706, -2706,   431, -2706,  1459,  1438,  1467,  1630, -2706,  1631,
     104, -2706, -2706, -2706, -2706, -2706,  2067, -2706, -2706,  1445,
    1639, -2706, -2706, -2706,   985,  1241, -2706,  1241,  1063,   101,
    4850,  4850,  4850,  1641, -2706, -2706,   267,   267, -2706,  1452,
    1063,    64,  1417,    61,   267, -2706,  1463,  4850,  1731, -2706,
   -2706,  1536, -2706, -2706,   431,  2094, -2706, -2706,   133,   208,
   -2706, -2706,  2079,  2086, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  3665, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  2821, -2706,  1139,  4850,   -16,  2081,  2097, -2706,
   -2706, -2706, -2706, -2706,   109, -2706, -2706, -2706, -2706,  1969,
   -2706,  1907, -2706, -2706, -2706,  4850,   110, -2706, -2706,   431,
    2106,    64,    64, -2706,  1544, -2706,    64,  1517,   267, -2706,
     431,   431,  4850,     7, -2706,  1553, -2706,   264, -2706,  1659,
   -2706,  1660,  4850,  1026, -2706, -2706,  1526, -2706,  2143, -2706,
    1602, -2706,   267, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,  5391, -2706,
   -2706, -2706, -2706,   431,    64,    64,   287,   284,  2000,  1699,
     267,   208, -2706,  1607, -2706, -2706,  2094,  2130,  1755, -2706,
   -2706, -2706, -2706, -2706,  1835,  1835, -2706,   823,  1612, -2706,
     431, -2706, -2706,  1364,  1364, -2706, -2706, -2706,   431, -2706,
     431,   -91,  1364, -2706,   652, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706,   163,   163,   749,   819, -2706,   546,
   -2706,   723, -2706,  3284,  2137, -2706, -2706,  1281,  1771,  1729,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,  1469, -2706,
   -2706, -2706,  1990,  1990, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1540,   -91,  1772,   882,   -67,  8973,   -67,   -67,
     -67,   -67,  1545,  8973,  8973,   280,  1642,   -96, -2706,  8973,
    8973,  8973,  8973, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
     985,  4850, -2706, -2706,  1777,  2137, -2706, -2706, -2706, -2706,
    3284, -2706, -2706,  1364, -2706,   637, -2706,  1740, -2706, -2706,
     637, -2706, -2706, -2706,  1745,  1749,   282,  1757,  1758,  1320,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,   431, -2706, -2706,
     282,  1521, -2706,   383, -2706,  1778,   462,  1555, -2706,  1063,
    1614, -2706, -2706,  1734, -2706, -2706, -2706,  1647, -2706,   431,
     431,   431, -2706, -2706, -2706,  4226,   431, -2706,  1579, -2706,
   -2706, -2706, -2706,  1582, -2706,  2205,  2209, -2706,  2210,  1643,
    4850, -2706, -2706,  1591,  2219, -2706,  1738,  1598,  1996, -2706,
   -2706,  1603,   716,   431, -2706, -2706,  1796,   180,   885, -2706,
    4850, -2706, -2706,   431,   431,  4850,    55,    68,  2225,  2226,
    2211,  2212,   795, -2706, -2706, -2706, -2706, -2706,   267,  1695,
   -2706, -2706,  2169,  4850,   666,   997, -2706, -2706,  1910,  2237,
    2247,   428, -2706,   441,   431,  1857,  1063, -2706,  4850,  1819,
    1823, -2706, -2706,  1895, -2706,  4850,   588, -2706,  1661, -2706,
   -2706,   781, -2706,  4850, -2706, -2706,  1644,   960, -2706,  1315,
     431,  2263,  4615, -2706, -2706,   985,   267, -2706, -2706,    89,
   -2706,  1996,  1996,  1615, -2706,  1723,  1735, -2706, -2706, -2706,
   -2706,    64,    64, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,  1705, -2706, -2706, -2706, -2706,    64,  4849,  2278,  2260,
   -2706,  1063,   787,   217,   187,  2185,    16,   975, -2706,   -50,
   -2706, -2706, -2706,  1856,   107,  1364,   102, -2706,  1668,  1663,
   -2706, -2706,   548, -2706, -2706, -2706, -2706,  1859,  1666,  2292,
   -2706, -2706, -2706,   267,   207, -2706, -2706, -2706,  1654,   819,
   -2706,   431,   431, -2706, -2706,   431,   552, -2706, -2706, -2706,
   -2706,  1868, -2706, -2706, -2706,  2275, -2706, -2706,  1360,  8973,
   -2706,   387,  1905,  2298, -2706, -2706, -2706,  8973, -2706,   442,
    8973,  8973,  8973,  8973,   431,   443, -2706,   141,  2300, -2706,
   -2706,   431,  8841, -2706,  1940,   431,  1690,   -67,  1980, -2706,
   -2706, -2706, -2706, -2706, -2706,  8378, -2706,  1885, -2706,  1853,
   -2706,  1861, -2706,  1899,   444, -2706,  8841,   456,   112,   112,
     473, -2706,   112,  8841, -2706, -2706,  1359,  1359, -2706,  1901,
   -2706,  1902,  1903, -2706,  1904,  1908, -2706,  1915, -2706, -2706,
   -2706,    79, -2706, -2706, -2706,   476, -2706, -2706,   485,   431,
   -2706, -2706,  1264,  2323,  1063,  2771,  4850, -2706,  2336, -2706,
   -2706, -2706, -2706,   282, -2706, -2706,  1718,   282,   150, -2706,
    1063,  4850,  4850,  4850,  4349,  2347,    92, -2706, -2706,  1063,
     431, -2706, -2706,   431,   431, -2706,   863, -2706, -2706,   850,
   -2706,  1728,  4850, -2706, -2706, -2706,  2348, -2706,  1732,  2355,
   -2706, -2706, -2706, -2706, -2706,   431,  1996, -2706, -2706,  1802,
   -2706, -2706,   499, -2706, -2706, -2706,   267, -2706,  3700, -2706,
   -2706, -2706,  2032,  2338, -2706,    64,  2016,  2020,  1909,  1752,
    2029,  1945, -2706, -2706, -2706,   589,  2015, -2706, -2706, -2706,
   -2706,  1895, -2706, -2706, -2706,   230,   794, -2706, -2706, -2706,
    2094,  4850,  1954, -2706,  1923, -2706, -2706, -2706, -2706,  2383,
   -2706, -2706, -2706,  1964,  2387, -2706, -2706,  1737, -2706,  2368,
      68,   431,  2372,  2372,  2372,  2372, -2706,  2390, -2706,  2391,
    2372,  2372,  2372,  2372,  3665, -2706, -2706,  2372,   152, -2706,
   -2706, -2706, -2706,  2374,  2386, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706,  2395, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,   502, -2706, -2706, -2706,  2394, -2706, -2706,  1364,
   -2706,   -91, -2706, -2706, -2706, -2706, -2706, -2706,  1820,  1822,
     199, -2706,   -50, -2706,   112,  1811,   180, -2706,  1992, -2706,
   -2706, -2706,   431,   431,  8973,   223, -2706,  4850, -2706,  4850,
   -2706, -2706, -2706, -2706, -2706, -2706,   180,   112, -2706,  1364,
    -140,  2422, -2706,   267,   431,   220,   220, -2706, -2706,  2429,
   -2706,  2429,   577,   577,  2429, -2706, -2706,  2092, -2706,  2038,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   188,  1359,
    1807, -2706,  1359,  2039,  8973, -2706,  2042,  2043,  2044,  2045,
   -2706, -2706,   280, -2706,   280, -2706, -2706,  8887,  2009,  8644,
    2009,  2440,  2441, -2706, -2706, -2706, -2706, -2706, -2706,  1036,
    8973, -2706,  1994, -2706,  2176,   136,   217,   431, -2706,  9427,
     114, -2706,  2092,  1468, -2706,   114,   112,   637, -2706,   210,
   -2706,  1364,  -166,  2053,  2447,  1826, -2706, -2706,   504, -2706,
     282, -2706,   507,   260,  1825,  -215,  2427,  2427,  2428,  2427,
    2427,  2431, -2706,   198, -2706,   637,   431, -2706,   282, -2706,
   -2706,  1833,  1063,  2451,   238, -2706,   431,   511, -2706,  4850,
    2064,  2442,   515,  1063,  2458, -2706, -2706, -2706, -2706,  4850,
    1900,  2192,  4850, -2706, -2706, -2706, -2706,   850,   981,   981,
    2468,   -78, -2706,  2470, -2706, -2706, -2706,   981,   431,  1926,
    1339,  2471,   431,    95, -2706,  -125,  4850, -2706, -2706,   795,
   -2706,  1810,  4850, -2706,  2479,  4850, -2706,   267, -2706,   962,
     431,   267, -2706,  2089,  4850,  4850, -2706, -2706,   589,  2015,
   -2706,  3665, -2706, -2706,  1250, -2706, -2706,  1911, -2706,  2771,
    4707,  4615,   267,   267,    65,   892, -2706, -2706, -2706,  1866,
   -2706, -2706, -2706, -2706,    64,  2372,    64,  2372, -2706, -2706,
   -2706, -2706, -2706, -2706,    68, -2706,  1068,  1079,  4849, -2706,
    2095,  2057,  8973, -2706,   187,   187, -2706, -2706, -2706, -2706,
     516, -2706,  2013, -2706,   112,   -56, -2706,  1863, -2706,  2491,
    9040,  9040,  9040,  9040,   112,   112, -2706, -2706, -2706,  1938,
   -2706,   537, -2706,  1867, -2706,   267, -2706,  2429, -2706, -2706,
     431,   577,   577, -2706, -2706,   577,  2287,  1874, -2706,  2107,
    1875,  1360,  1876, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
     545, -2706, -2706,  2035, -2706,   263,   876, -2706,  8841,  8841,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,  3359,
    3359,  2076,  3359,  2077, -2706,  3359,   855,  8973,  2509, -2706,
   -2706,  8841, -2706, -2706, -2706, -2706, -2706,  2510, -2706,  -142,
   -2706, -2706,  2176,  1888, -2706, -2706,   110,   110,   110,  2494,
     110,   110,   110,   110,   110,   110,  2495, -2706,  2496,   110,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,  9427, -2706,
     267,  1912, -2706,  2072,  2287,  2501, -2706,  2502,  2505,  2506,
    2507,  2508,  2515,  1269,  1468, -2706,  2072, -2706,   551, -2706,
   -2706, -2706,  2523, -2706,  2227,   112,  1367,   112, -2706, -2706,
   -2706, -2706,  1360,  2524,  1360, -2706,  2530,  2530,   553,  2154,
    2530, -2706,  2155, -2706, -2706, -2706,   637, -2706, -2706, -2706,
   -2706,  1063, -2706, -2706,   282,  2176,  2094, -2706,  2080, -2706,
     382,  1063, -2706,  2549,  2119, -2706, -2706,  2159,  2003, -2706,
   -2706,   431,   981,  2771,  1387,   431,   981, -2706, -2706,    64,
   -2706, -2706,  4850, -2706, -2706, -2706, -2706, -2706, -2706,    64,
    2094,   267,  2316, -2706,  2536,  1723,  8378,  2538, -2706, -2706,
     208,  2132, -2706, -2706,  4850, -2706, -2706,  2170, -2706, -2706,
   -2706,   794, -2706,  1723, -2706,  4850, -2706,   244, -2706,  1958,
   -2706, -2706, -2706, -2706, -2706, -2706,  2133,  2223, -2706,  2558,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   431, -2706,    94, -2706, -2706, -2706,   112, -2706,   -91,
    2437,   556, -2706, -2706, -2706, -2706,   431,  2026,  2405,  2405,
   -2706, -2706,  4323,  2151, -2706, -2706,  2152,  2153, -2706,  2158,
    2160,  2161,  2163,   431,   780, -2706, -2706,   558, -2706, -2706,
    2446, -2706, -2706, -2706,   561,  2585,  2585, -2706, -2706,   565,
    2590,  2587, -2706,   118, -2706, -2706,   112, -2706,   125, -2706,
   -2706, -2706, -2706, -2706,  2388,  4016, -2706,  1360, -2706,  1360,
     280, -2706, -2706,  2441, -2706,  2157,  2305,  2157,   122, -2706,
    2157,   122, -2706,  2157,  3359, -2706, -2706,  8973, -2706,  8973,
    2440,   136, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   385,  2600, -2706,   267,  1550, -2706,  2388, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
     283, -2706, -2706, -2706,  2142, -2706, -2706,  2213, -2706,  2583,
    2214,  2215,  2588, -2706, -2706,  2216, -2706, -2706, -2706, -2706,
   -2706,    64,    68,  2236,  1063, -2706,  4850, -2706,  2046,  2592,
      68, -2706, -2706,   839, -2706, -2706, -2706, -2706,   204,  2222,
    1996,  2387,  2377, -2706,    68,  2228,  2229,  2225,  2187, -2706,
    2279,  2230, -2706, -2706, -2706, -2706,  2384,  2165,  4850,  2189,
   -2706, -2706, -2706,  1723, -2706,   569, -2706,   267,  2085, -2706,
   -2706, -2706,  8973, -2706, -2706,   112, -2706,  2197, -2706,  2085,
    2019,  2019,  2234,   882,   -67,  9123,   -67,   -67,   -67,   -67,
    2014,  9123,  9040, -2706,  9123,  9123,  9123,  9123, -2706, -2706,
     112,  2626,   112,  9040,   180,  8841, -2706,   267, -2706, -2706,
     391, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   198,
   -2706, -2706,   578, -2706, -2706, -2706, -2706,   595, -2706,  2157,
    2634, -2706, -2706, -2706, -2706, -2706, -2706,   267,  2600, -2706,
   -2706, -2706,   267, -2706,   267, -2706, -2706,  2168, -2706,  2399,
   -2706,  2400,  2619, -2706, -2706,  2017, -2706, -2706, -2706, -2706,
    2249, -2706, -2706, -2706,  1063, -2706,  2253,  9474,  2217, -2706,
   -2706, -2706,  2030,    68, -2706, -2706, -2706, -2706, -2706, -2706,
    2257,   208, -2706,  2279,  2279,   794, -2706,  2771,  2075, -2706,
   -2706,   431, -2706,  2387,   -96,   188, -2706,  6784,   -96, -2706,
    2261,  9123, -2706,   596,  9123,  9123,  9123,  9123,   431,   604,
   -2706, -2706, -2706, -2706, -2706, -2706,  2221, -2706, -2706, -2706,
    2440,  2387,   125, -2706, -2706, -2706, -2706, -2706,   203, -2706,
   -2706, -2706,  8973, -2706,  2126,  2126, -2706,  2126, -2706,  2126,
    2126, -2706, -2706, -2706,  2231,  1360, -2706,    75, -2706, -2706,
      76,    76,    76,    76,    76,    76, -2706,  2635, -2706,   616,
   -2706,  4850,  1397, -2706,   620,  2279,  4850,  2279,  2225, -2706,
   -2706, -2706,  2413,   325, -2706,    68, -2706, -2706, -2706, -2706,
     624, -2706, -2706,  1260, -2706,  2264,  9123, -2706,  2265,  2268,
    2269,  2270, -2706, -2706,  9040, -2706, -2706, -2706, -2706, -2706,
    2126, -2706,  2126, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   951, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,  9474, -2706,  2663, -2706, -2706, -2706, -2706,   783, -2706,
   -2706, -2706, -2706, -2706, -2706,    89, -2706,  6784, -2706,  1473,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   630, -2706,
   -2706,  1046,  1046, -2706, -2706,  1046, -2706,  4850,   910, -2706,
   -2706,  2273,    65, -2706,  2048,  2050,  2666, -2706, -2706, -2706,
   -2706, -2706,  2280, -2706, -2706, -2706,   431,   431,  1473, -2706,
     144,  2055, -2706, -2706, -2706,   208, -2706,   431,  2225, -2706
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2706, -2706, -2706, -2706, -2706,   -18, -2706,    37,  -199, -2706,
   -2706, -1126,   -41, -2706, -2706, -2101, -2706, -2706, -2706, -2706,
    -785, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2387, -2706,  -994, -2706,
    1691, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   279, -2706,
   -2706, -2706, -2706,  1188, -2706,   566, -2706, -2706,   -60, -2706,
   -2706,  2656, -2706,  2659,  2139, -2706, -2706, -2706, -2706, -2706,
     354,    27, -2706,   350, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  -123,   972,   307, -2706, -2706,
    2330,    66, -2706,  2566, -2706, -2706,  2565, -2706,  2483, -2706,
   -2706, -2706, -2706, -2706,  2345,  2056,   736,  2344,  -531, -2706,
   -2706, -2706, -2706, -2706,   739,  -661, -2706, -2706, -2706, -2706,
   -2706, -2706,  -168,  2177,  2487,   -20,  2118, -2706,  2166,  1476,
   -2706,  2325, -2706, -2706, -2706, -2706,  2332, -2706, -2706, -2706,
   -2706,  -416, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
    2171, -2706,  2164, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -1314, -2706, -2706,  -726, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  -121, -2706, -2706,   695, -2706,
   -1090, -1125,   196, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  1751, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
    -612, -2706, -2706, -2706, -2706, -2706,  1948, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  -530, -2706,  -137, -2706, -2706,
   -2706, -2706,  2307, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,  1512, -2706, -2706, -2706, -2706,   533, -2706, -2706, -2706,
   -2706, -2706, -1739, -2706, -2706,   532, -2706, -2706, -2706, -2706,
   -2706, -2706, -1093,  -823,   416,   680, -2706,  -266,  -470, -1101,
     871, -2706,   655, -2706, -2369,    -4,  -178, -2706, -2706, -2213,
     130,  1217, -2706, -2706,   646,   919, -2706, -2706, -2706, -2706,
   -2706, -2706,    48, -2706,  -233, -2706,   920, -2706,   625, -2706,
     340, -2706, -2706, -2706, -2706,  -733, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706,   433, -2706, -1788, -2706,   611, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706,  1380, -2706, -2706, -2706, -2706, -2706,
   -2706,  -404, -2706, -2706, -2032, -2706, -2706, -2706, -2706,   375,
   -2144, -2706, -1111, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,  2760, -2706, -2706,
   -2706,  2667,  2756, -2222, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,  -346, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
    2761, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,   662, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  -685,  2036, -2706, -2706, -2706, -2706, -2706,  1869,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,   979, -2706,
   -2706,   -55, -2706, -2706,   657, -2706, -2706, -2706, -1016,  -214,
    2445, -2706, -2706, -2706, -2706,  -227, -2706, -1040,  1784,   939,
   -2181,    78, -2706,   664,  1597,  -331,  -479, -2706, -2706,  2025,
    1413, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706,  1349, -2706,  -769, -2706,  -641, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706,  -666, -2706, -2706, -2706, -2706, -2706, -2706,
      96, -2706,  1426,   580, -2706, -2706, -2706, -2706, -2706,   -77,
   -2706,  -477, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,  1657, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,  -535, -2706,  1337,  2351, -2706,
   -2706,   -70, -2706,  -591, -2706, -2706,   -51,   224, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706,   865, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2538, -2706,  1470,   493, -1319, -2706, -2706, -2706,   811,
   -2706, -1912, -2706, -2706, -2706, -1955, -2706, -2706, -1943, -2706,
   -2706, -2706, -2706,   842, -2706, -2706, -2706, -2706, -2706, -2706,
     336, -2706, -2706, -2706, -2706, -2706, -2706,  -644, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  -267, -2706, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,   315, -2706, -2706,
   -2706,  -526, -2706, -2706, -2706, -2706, -2706, -2706,   -54, -2706,
   -2706,   242, -2706,   557, -2706, -2706, -2706, -2706, -2706, -2706,
   -1329, -2706, -2706, -2706, -2706, -2034, -2706, -2706, -2706, -2706,
   -2706, -2706, -2318,   594, -2706, -2511,   658, -2706, -2706, -2229,
      35,    38,   285, -2706, -1935, -1895, -2706, -2706,  -245,  -519,
   -2706, -2706, -2706, -2706, -1866, -2706, -2706, -2706, -1557, -2706,
   -2706, -1025, -2706, -1009,   980,  -293, -2051,   253, -2706, -2573,
   -2706, -2706, -2706, -2706,  -124, -2706, -1327, -2647,  2848, -2706,
   -2706, -2706, -2706, -2706, -2706, -2706, -2706,  -662, -2706, -1655,
   -2706,  1634, -2706, -2706,  -151,   271, -2706, -2377,   272,  -169,
     105, -2525, -1846, -2187,   909,  -237,   792, -1250, -2706,   911,
   -2706, -2706, -2706,  1002,  -749, -2706, -2706,  -463,  1650, -2706,
     581, -2706, -2706, -1815,  -156, -2706, -2706, -2706, -2117,  -351,
   -2706, -2706, -2706,  1037, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706, -2706, -2706, -2630,  -368, -2706, -2705, -2150, -2166,
   -1482, -2706, -2706,  -355, -2706, -2706, -2706,   212,  -695,  -650,
    -847,   575,  -354,    19,  2196,   -30, -2706, -2706, -2706, -2706,
   -2706,  1496, -2706,  -261, -2706, -2706, -2706, -2706, -2706, -2706,
   -2706, -2706,  -275,  1200,  2341, -2706, -2706, -2706, -2706
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2159
static const short yytable[] =
{
      43,   215,   583,   296,  1002,  1320,  1999,   356,   116,    58,
      60,  1370,   284,    60,  1942,  1943,  1420,  1448,  1355,    34,
    1466,   431,   432,  2021,  1418,   687,  1474,  1152,   433,   434,
     135,  1427,  1428,   446,  1429,   264,  1450,  1451,   990,  1367,
    2358,   594,    76,    79,    34,  2200,  2713,  2799,  1037,  1158,
      72,   132,  2558,  2814,   949,  2817,  2044,  2609,    89,  1380,
    2924,   116,  2316,  2291,  2623,   215,  3064,  3065,  3066,  2155,
    2156,  1086,   959,   953,   131,  2199,  2483,    79,   594,   134,
      42,    89,    42,   324,   215,   381,  1111,   130,    42,  2744,
     141,    42,  2250,  2251,  2252,  2253,  1485,   148,   302,  1964,
     524,   153,  1421,    42,   155,   156,  1051,  2239,  2317,  1861,
     159,   160,  2663,  1856,  1465,  2965,  1061,  1365,   361,    42,
    1365,  2499,    42,   302,   362,   363,  1079,  1866,    42,   100,
    1056,  1037,  3004,    89,   302,  1879,  1052,  1365,  2080,    42,
     130,  2674,   389,   390,  3068,  1116,   302,  1267,  1268,    42,
     260,   533,    42,   263,  3088,  2503, -2157,   594,   267,  1467,
    1468,  1365,  2846,    42,   144,   605,  1365,  1857,    42,   354,
     435,  1112,   606,  1114,   447,  1156,   449,    42,   450,   451,
     452,   576,  1151,    42,   354,   466,  1354,   457,    42,  1397,
    1883,   468,   469,  1964,    42,   354,    42,  3055,  3055,  3055,
    3055,   302,   357,   358,    42,  1397,  2082,    42,  2083,   594,
    2084,   100,  2533,   215,    42,   228,  2818,   215,    42,   359,
     374,  2913,   302,  2923,  1268,  1193,    42,   302,  1267,  1268,
      42,   354,   302,  1205,  1206,    42,   580,  2616,  2619,   578,
    2265,  2619,  1156,   354,    42,  3056,  3056,  3056,  3056,   354,
    1385,  1386,   586,  2880,  2809,  2712,  2811,    42,   386, -2157,
     594,  2506,   594,   594,   392,  3156,  2818,  3158,  1355,  2818,
    2968,    85,  3254,   969,   145,   420,  2770,  2771,  2772,  2773,
    2774,  2509,   429,   429,   429,   429,   429,  2128,  3302,  1861,
     429,  2632,  2080,   602,    42,  2664,    85,  2244,  2902,   302,
    1205,  1206,    42,  1463,  2204,  1365,  3099,    42,  3102,    42,
    2742,  3534,  1457,  1458,  3115,  2205,   592,  1033,  3457,   621,
      59,   382,    42,   663,  2358,  2796,    65,  2769,   956,   684,
     354,  1214,   613,  2098,  1181,   616,  2206,   935,  1185,    89,
      89,  2029,  1189,  2207,  1407,    85,  1360,  1215,  2102,   535,
    2815,  2122,   624,   625,   626,   627,  1464,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   594,  2164,   669,   671,  2510,  2088,
    2884,  2030,   675,  1215,   645,   646,  2953,  3173,  1215,   648,
     970,   649,  2559,   952,    65,  1361,  3372,  3170,  1033,  1362,
     215,  2596,  3112,    85,  1981,  1981,   652,   653,   654,   655,
     393,  1986,    85,   661,  2245,  1408,  2914,  2004,  1025,  2004,
    3029,  1025,  1025,  2266,  1497,    85,    67,  3458,  3033,  2041,
    2005,  3459,  2005,  2395,  2267,  1025,   541,   394,   543,  1862,
    3266,  1101,  3267,   100,  1335,  1336,   594,  2564,  2564,  2607,
    1001,  3113,  1885,  2761,  1025,   215,  1013,  1025,    42, -1536,
    1894,  2607,    85,  1025,  1521,  3055,  3055,  1025,  2759,  3055,
      85,  1025,  1337,  1338,  1339,  1025,  2782,   593,  2620,  1025,
    1025,  2636,  1025,  2541,  2633,  1025,  2544,  1025,  1025,  1025,
    2638,   603,   589,  3535,   976,  1025,   988,  2138,  1025,   991,
     971,   834,   928,  2129,  2689,  1025,  2027,  2748,  1103,  2907,
    2169,  1025,  2907,  3056,  3056,  1023,  2934,  3056,  1025,   581,
    2934,  3027,    89,  1270,  2246,  3274,    73,   215,  3274,  1025,
    1147,  1148,  2004,  1025,  1022, -2157,  3373,  1025,  1271,  2969,
    1215,  1022,  3076,  1025,  2850,  2005,  1025,  2954,   305,   679,
    3090,  1062,   679,  1022,  1062,  2616,  2905,   673,  3162,  1199,
     679,  3225,  1202,  3242,  1071,  3023,  3242,  2990,  1062,  2375,
    3250,  2679,  1062,   577,  3341,    42,   420,  2572,   420,  1088,
     920,   930,  1422,  3378,  1062,  2099,  1071,   951,   965,   955,
     429,  1502,  1099,  3259,  1878,  1071,   355,  2000,  1953,  1270,
    3378,  3436,  1108,  2006,  1270,  2020,  3194,  2900,  1115,  3436,
    1216,   538,  3110,  3005,  1271,  1150,   589,  2500,  1469,  1271,
    3365,  3471,  1000,  1480,  3204,  1483,  1099,  2017,  1102,  3487,
    1099,   579,  2966,  2881,  1099,  3242,  1423, -2157,  2262,  2053,
    1071,  2096,  1218,  1071,   587,  2752,  1522,  3019,  2007,  3255,
    2007,  2067,   595,  3217,   598,   599,  1217,  2911,  1321,    42,
    3092,  2028,  3055,  1891,  2008,  1207,  2008,  1988,  3055,  3055,
    2932,  3055,  3055,  3055,  3055,  1891,  3207,  2909,  1218,   679,
    3055,  2928,  1217,  1218,    89,    89,    89,    89,  1021,  2048,
    1026,  1027,  1080,  2491,  1034,  1039,  3376,  1041,  2768,   323,
    1044,  2021,    89,  1472,  2054,  1470,  1037,  3344,  2439,  2611,
    3056,  1027,  2611,  3032,  1486,  3303,  3056,  3056,  3348,  3056,
    3056,  3056,  3056,  1926,   323,   954,  2929,   427,  3056,  2611,
    1937,  1027,  2653,   427,  1037,   323,   427,    89,  3181,  3498,
    1965,   607,  3186,    89,  1027,    89,  1398,   323,  3456,    89,
    1424,    78,    89,  2611,  1089,    89,  2085,  3484,  1944,  2534,
    3179,  3174,  1417,  2007,  2086,    89,   609,  1208,   670,   672,
     429,  1105,  3268,  2377,   676,  1182,    42,  1034,  3055,  2008,
      89,  3055,  3055,  3055,  3055,    89,  2439,   429,   429,  1387,
    3191,  1363,    89,    89,    89,  2787,  1982,  1983,  1176,  1992,
    2257,    79,   323,  1987,  2128,  3274,    89, -2157, -2157, -2157,
   -2157, -2157,  2775,  1194,    42,  1194,   429, -2157,  1194,   429,
    1430,  1194,    89,   323,  2203,  2396,  3056,    85,   323,  3056,
    3056,  3056,  3056,   323,  3428,  1218,  1223,  1925,  2397,  2565,
    2571,  2608,  1025,  1340,  3340,  2758,  1945,  1523,   345,   346,
     347,   348,   349,  2610,  3152,  2678,  3155,   345,   346,   347,
     348,   349,  1946,  3055, -2157,  3104,  1307, -2157, -2157,  1307,
    2621,  3055,   307,  2637,  2193,  2194,  3232,   661,   661,  2948,
    1524,  2545,  2639,  2201,  2351,  2820,  2821,  2352,  2822,  2823,
    2824,  2825,  2826,  2827,  2516,  2107,  2690,   310,  2133,  2749,
     323,  2908,  1022,  2517,  2910,  1947, -2157,  1032,  2935,    42,
      36,  3056,  2939,  3028,  2560,  1219,  1220,  1221,  1058,  3056,
    2164,   345,   346,   347,   348,   349,  1222,  1243,  2518,  3284,
    1341,  2519,  2410, -2157,  3077,  3097,    35,  3100,  1993,  1150,
    3103,  1072,  3091,  3248,    85,  1948,  3419,  3420,  3149,  2520,
    3163,    35,    36,  3226, -2157,  3243,  2261,    45,  3249,  1025,
    1025,  1025,  3251,  2184,  2185,    81,  3342,  3427,  1284,  2624,
    2625,  3433,    19,  1342,  1949,  3379,  3221,  1431,  3285,  1963,
     316,  2383,    85,  1950,  2283,   186,  1145,    42,  1045,    42,
    1992,  2353,  3380,  3437,  2354,  1159,  1165,    19,    83,  1180,
    1018,  3443,    42,  1184,   136,  1862,  1330,   138,   679,  1190,
    1032,  1192,    42,  3472,  2648,  1994,  2164,  1109,  2648,    42,
    2129,  3488,  1404,  2390,    42,  3258,  3370,  3518,  3480,  1034,
    3482,  2351,  2221, -2157,  2352,  3345,  3343,    98,  2221,   931,
    2489,    92,   133,  2420,  1366,  2820,  2821,    89,  2822,  2823,
    2824,  2825,  2826,  2827,  2521,  2169,  1876,  1115,  1150,  2675,
    2850,    89,   932, -2157,  1366,   491,   492,   493,   147,  3352,
    3509,  1323,   963,   319,   964,  3352,  3371,  1033,  3361,  3362,
    3363,  3364,   140,  2164,   494,   320,   321,   143,  1156,    42,
      42,  1454,  3360,   322,  3015,    42,  2204,   145,  1461,  3024,
    3025,  2524,    89,  3368,  1432,  3017,    42,  2205,  2522,  3105,
    1433,  1434,  1435,  3248,  3248,  2523,   187,   218,  1996,    89,
      89,    89,   149,    89,  2402,    89,    89,   221,  2206,  1993,
    1436,    89,    89,  2828,  1997,  2207,    46,  1103,  2353,  2213,
    2068,  2354,   495,   496,   497,   498,   499,   500,  2417, -2157,
      47,  2169, -2157,   137,   138,    85,    42,    85,   501,   502,
     503, -2157,  3271,  2164,    84,  3276,    42,  1495,  3278,    89,
      85,   937,  2125, -2157,  3346,    48,  2222, -2157,   222,    89,
    1033,   218,  2222,  3222,  1513,  3435,  2508,  1033,  3438,  3439,
    3440,  3441,    85,   225,  3503,  2223,  2224, -2157,   436,   437,
     218,  2223,  2224,    89,    89,   938,  1994, -2157,  1989,  3279,
   -2157,  1991,    89,   261,   931,  2225,  3241,  -273,  2169,   262,
    1506,  2225,    42,    49,   269,  2112, -2157, -2157,    89,    89,
    2115,  2113,  2800,  1390,   277,  2802,  1245,   932,  1167,  1437,
    1391,  1872,  1438,    42,   138,   278, -2157,  3106,  2261,  3107,
    1439,  2164,  2829,  2830,  1928,   280, -2157,  1377,    85, -2157,
    1284,  1284,  1257,    85,  1995,  2186,  2049,   281,    42,  1284,
    3493,  3322,   282,  2240,    85,  2992,   285,    42,  2899,  1962,
    2323, -2157,   351,  2241,  2032,  1440,   378,  1968,  1168, -2157,
    1032,    42,    42,  2828,  3145,  1050,    42,  2026,  2169,   504,
     448,  2232,   505,  3458,   286,  -273,  2927,  3459,    42,  1996,
    2831,   438,   385,  1064,  2728,  1066,   439,   440,   441,  2021,
    1441,  -273,   531,   532,    85,  1997,  1169,  1073,  1075,   218,
    2274,  1078,  2001,   218,    85,  2423,  2009,  2018,  2009,   396,
    1442,  1443,    42,  1092,  3381, -2157, -2157,  1145,    89,  1034,
     287,  1444,  1034, -2157,  2033,  2036,  1445,  1159,  1041,  2960,
    3161,   288,  1488,  3165,  -273,  3463,    42,  2401,  3351,   289,
    3354,  3355,  3356,  3357,   397, -2157, -2157,   366,   367,   368,
    1034,    89,  3476,    89,    89,    89,  2169,  3153,  2294,  1365,
      85,    42,    89,    89,    42,  1446,    89,   429, -2157,   429,
      89,   438, -2157,   290,  -273,  2763,   439,  3184,   441,   291,
    2079,    85,  2829,  2830,    42,    89, -2157,  3474,  2501,  1094,
    1493,   506,    42,  1170,    42,  2780,   292,  1447,  1100,  3463,
     293,  2334,  2488,  -273,  1238,  1239,    85,   507,  2832,   405,
     360,   508,  -273,   294,   365,    85,  3476,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,  1939,
      89,  1940,   398,   295,    85,  1198,  2216,  2217,  1201,   494,
    2831,  1204,   414,  1197,   352,   494,  1200,   297,   399,   509,
    2751, -2157,  2024,  1499,    42,  2109,   339,   429,   429,  2137,
     138,   198,   429,  2236,    89,  2237,  2119,  2120,  3514,  1171,
      42,   137,   138,   199,  2833,   651,   340,   510,  1455,  1456,
     137,   138,  1459,  1460,   341,  2050,   218,  2050,    89,   342,
    2783,   400,  1371,  1372,  1373,   511,   343,   495,   496,   497,
     498,   499,   500,   495,   496,   497,   498,   499,   500,  2364,
    2365,  1172,   525,   501,   502,   503,  1219,  1220,   344,   501,
     502,   503,  3489,  3490,  2834,  2835,  3230,  3231,   375,  2936,
     493,   401,   376,  2261,   353,  2261,   379,   380,  1031,  2389,
     384,   218,   387,  1500,   406,  2643,   391,   494,  2973,  3096,
    3096,  1049,  3096,   415,   421,  3096,  2055,  2056,  2057,  2654,
     402,  2655,   424,  2151,  2152,  2999,  2970,  3167,  2832,   403,
    2666,  2243,  2917,  2074,  2919,  2920,   425,   512,  1173,  1067,
    1232,  1475,  1476,  1477,  1478,  3169,  3289,   453,  3014,   455,
     426,  1233,   456,   467,  2295,  1084,  1085,   470,   471,   473,
     474,  1091,  2885,   475,  1093,   495,   496,   497,   498,   499,
     500,   476,   477,   218,   526,   537,   458,   205,  2886,  2887,
     539,   501,   502,   503,   544,   545,  1929,  2888,   548,   549,
     550,  2097,   407,   551,  2833,   554,   555,  1015,  1016,  1017,
    1019, -2157,   206,   513,  1234,   566,   565,   584,   408,   569,
     574,  1159,  2296,   585,   504,  1047,   588,   505,  3290,  1235,
     504,  2889,   596,   505,  2297,   591,   597,   601,  2121,   608,
    2890,  2978,   614,   617,   618,  2298,   619,   622,  2136,   647,
    2986,  2987,   650,  2192,  2834,  2835,   207,   657,   656,  2196,
    1069,   409,  2649,  2299,   662,   208,  1074,   664,  1076,  2891,
    1944,  2550,  1083,  2300,   459,  1083,  2301,  2157,  1083,  2158,
    2159,  2160,   665,  2157,  1930,  2158,  2159,  2160,  1095,  2302,
     460,   667,   666,   668,  3291,   674,  3292,   685,   677,   936,
    1931,   410,   941,  1095,  1291,   962,  2686,   943,  1143,   944,
     945,  3293,   950,   960,  2892,  1019,  1154,  1157,  1236,  3294,
     961,  1177,   968,  3295,   345,   346,   347,   348,   349,  1187,
     411,  2432,   504,   461,   975,   505,   973,  2303,   977,   412,
    2229,   978,  1025,  1932,   979,  1211,   506,   996,  3296,   209,
     210,   998,   506,  1003,  1005,  2720,  2893,  1006,  1945,  2551,
    1007,  1009,   507,  1010,  1011,  2376,   508,  2304,   507,  1012,
    1014,  1186,   508,   462,  1946,  2552,  1247,  2305,  1248,  1296,
    1249,  1250,  1298,  1933,  1299,  1300,  1301,  1302,  1303,  1194,
     429,   429,  1251,  1252,  3096,  1254,    89,    89,  2306,  1255,
    2275,  2307,   463,  2308,   509,  1253,  1259,  2280,  1256,  1260,
     509,   464,  1934,  1258,  1261,  1262,  2188,  1947,  2553,  1366,
    1366,  1935,  1263,   984,  2197,  1297,  2197,  1304,  1366,  1305,
    1306,  2309,   510,  2930,  1309,  2446,  2448,  1310,   510,  2363,
    2310,  1312,  1313,  1314,  2940,  1315,  1316,  1317,  1318,  1025,
     511,  1322,    89,  2368,   506,  2458,   511,  1948,  2554,  1326,
    1327,  1329,  1328,  2233,  1333,  1352,  1353,  1025,   138,  1356,
     507,  1358,  1359,  1364,   508,  1368,  1384,  1053,  1053,  1388,
    3197,  1389,  1392,  1395,  1396,  1393,  1949,  2555,  1400,  1412,
    1414,  1034,  1419,  1284,  1401,  1950,  2556,  1452,  1403,  1284,
    1284,  1366,  1462,  1465,  1481,  1284,  1284,  1284,  1284,  1489,
    1490,  1491,   509,     1,  2161,  1492,  1034,  2162,  1496,  2163,
    2161,  1501,  2388,  2162,  1498,  2163,  1502,  1510,  1512,  1366,
    3199,  1852,   512,  1853,     2,     3,  1854,   661,   512,  2164,
     510,   594,  2009,  1860,  1855,  2164,  1115,  1864,  1867,  2165,
    1971,  1972,  1868,  2018,  1916,  2165,  2009,  1869,   511,  1870,
    1924,  1927,  1955,     4,  1150,    89,  1938,     1,  2166,  1956,
    1211,  1957,  1958,  1053,  2455,  2330,  2331,  2332,  1355,  3246,
    3247,  1959,  2336,  1209,  1378,  1960,  3313,  1961,     2,     3,
    2003,  2167,  1323,  1980,  3321,  2168,  1985,  2167,   513,  2023,
    2039,  2168,  2041,  2040,   513,  1954,  2042,  2043,  3326,  2361,
       5,     6,  2045,     7,     8,  2047,  2046,  2060,     9,  2371,
    2372,  2261,   429,  2066,  1472,  1406,  2075,  1973,  1974,  1975,
    1976,  1977,  1978,  2073,    89,    10,    11,  2090,  2077,  2080,
     512,    89,  1426,  1426,  1426,  2091,  1426,  2100,  1426,  1426,
    2399,  2644,    89,    12,    92,    92,  1973,  1974,  1975,  1976,
    1977,  1978,     1,  2101,     5,     6,  2103,     7,     8,  2696,
    2105,  2110,     9,    89,  2169,  2424,  1513,  2125,  1284,  2114,
    2169,  1034,    89,     2,     3,  2116,  2132,  2134,  2140,    10,
      11,  2139,  1157,  3369,  2142,  1862,  2178,   429,   429,  2176,
    2179,  2181,  1508,  2230,  2187,  2235,   513,    12,  2234,  2240,
    2254,  2238,   429,  2262,  2276,  2321,  2286,    89,    89,    89,
    2322,  2288,  3168,    89,    13,  2289,  1211,  1378,   215,  1285,
    2319,  1366,  3175,  2292,  2293,  1865,  2324,  3413,  2325,  2326,
     582,  2338,    51,    52,    53,    54,    55,    56,    57,    89,
    2341,  1873,  1873,  2340,  2342,  2343,  2346,  2540,  2540,     5,
       6,  2540,     7,     8,  2347,  1025,  2348,     9,  2344,  2349,
    1861,  1025,  2362,  2350,  2378,  1284,  2385,  2380,  2381,  2387,
   -2157,  1377,  2393,  1284,    10,    11,  1284,  1284,  1284,  1284,
    2570,  1025,  2394,  1366,  2400,  2403,  2345,  2575,  1284,  2404,
    2407,  2593,    12,  2413, -2157,  3117,  3118,  3119,  1209,  3121,
    3122,  3123,  3124,  3125,  3126,  2421,  2367,  2427,  3129,  2439,
    1222,  2057,  1284,  2486,  2612,  2612,  2487,  2441,  2612,  1284,
    2498,  3418,  2504,  2512,  2513,  2527,  2529,  2530,  2537,  3486,
    2548,  2549,  2561,  2562,    14,  2574,  3290,  3464,  3465,  3466,
    3467,  3468,  3469,  2590,  2595,  2640,  2597,  2598,  2033,  2599,
      89,  2409,  1115,  1969,  1970,  1971,  1972,  2603,  1150,  2009,
   -2157,  2642, -2157,  2009,    89,  2606,    89,  2626,  2627,  2628,
    2629,  2646,  2612,  2651,  2630,    89,  2361, -2157,  1150,  2671,
    2671,  2631,  2662,  2680,    15, -2157,  2682,  2683,    14, -2157,
    2684,  2687,  2693,  2694,    92,  2697,    92,  1157,  1083,  2698,
   -2157,  2685,  3291,  2699,  3292,  2061,  1095,  2700,  2701,  1157,
   -2157,  2702,    89,  2071, -2157,  2718,    16,  2719,  2721,  3293,
    2722,   429,  2723,  1221,  2727,  2734,  2736,  3294,  1211,  2745,
    2746,  3295,  1973,  1974,  1975,  1976,  1977,  1978,    15,  2747,
   -2157,    89, -2157, -2157, -2157,    17,  3063,  3063,  3063,  3063,
    2750,  2754,  3481,  2755,  1209,  3315,  3296,  2785,  2764,   302,
    1267,  1268,    42,  2762,  2790,  2798,  2803,  2729,  2801,  2805,
    2806,  2807,  2808,    92,  1922,  2813,  2818,  2841,  2819,  2844,
    2904,  2906,  2905,  2915,  2918,  3283,  2912,  2921, -2102,  2931,
     163,  2937,  2938,  2941,  3244,  3245,  3246,  3247,  3010,    17,
    3012,  2944,  2943,  2951,  3040,  2955,  2962,  2117,  2959,  1025,
    1025,  1285,  1285,  2974,  2977,  1366,  2985,   928,  2995,  3029,
    1285,  3009,  3020,  3021,  3036,  3538,  1964,  3074,  3078,   164,
    2612,  2144, -2157,  3085,  3086,  2997,  3087,  3089,  2766,  2197,
    1284,  1953,  3098,  3101,  3109,  3111,  2368,  3116,   165,  3120,
    3127,  3128,  2645,  2612,  3135,  1366,  3138,  3139,  1993,    89,
    2540,  3140,  3141,  3142,  3143,  3159,  3134,  2656,  2657,  2057,
    2660,  3144,   928,  1973,  1974,  1975,  1976,  1977,  1978,  3150,
    3157,  3164,  3166,  3171,  3176,  3177,  3178,   166,  2681,  3179,
    1284, -2157,  3193,  3195,  3198,  3398,   930,  3202,  1366,   167,
    1366,  2976,  1216,  1284,   661,  1284,  1115,  1115,  3213,  3210,
     168,  3223,   215,   661,   661,  3217,  1284,  3233,  3234,  3235,
    3242,  2612,    89,  2593,  3236,  3252,  3237,  3238,   169,  3239,
    1033,  3253,  2612,  3263,  3269,  3287,  2902,  2612,   170,  3306,
    3305,  3308,  3309,  3311,  3310,  3314,  2009,  2717,  3320,  3324,
    3318,   930,  3325,  3329,   171,  3327,  3328,  3333,  3331,  3337,
   -2157,  3349,  2018,  3347,  2009, -2157,  1209,  1965,    89,  3358,
    3366,  3382,  2330,  3392,  3393,  3394,  3396, -2157,  3395,    89,
   -2157,  3399, -2157,  3411,  3417,  3412,  3424,  3444,  3434,  3483,
    3470,  3492,  3494,  3455,   172,  3495,  3496,  3497,  3507,  3265,
    3524,  3528, -2157,  3526,  2361,  3527,  2961,  3529,  2963,  2612,
    3537,  2981, -2157,  2933,  3063,  3063,  3506,   173,  3063,  1319,
    2710,  2124,  2412,    89,    74,    89,  2982,    89,  3188,    75,
     835, -2157,   174,  1053,  2667,  2958,  2676,   546,  3190,   175,
      89,   224,   176,  2777,   229,  2778,   542,  1284,    89,    89,
     371,  2277,   547,  1004, -2157,  2278,   373,   678, -2157,   967,
     429,   573,   429,   177,   940,  3504,   178,   571,   179,  1941,
    2335,  1311,    89,    89,  3275,   604,   947,  3275,  1284,  2248,
    1175,   946,  2538,  1920,  3183,  2248,  1291,   180,  2546,  2658,
    2612,  2270,  2271,  2272,  2273,  2373,  3054,  3054,  3054,  3054,
    2612,  2612,  2150,  3008,  3212,   181,  2154,  2726,  2438,  3525,
    2665,    89,  2456,  2070,  3323,    69,  3080,    70,   161,   189,
     190,  3300,    71,  2419,  2422,  1090,  1332,   191,    42,   536,
    2175,  3003,  1246,  3288,  2426,  1858,  1270, -2157,  3383,  1113,
    2062,  2095,  3510,  2052,  1284,  1284,   215,  3001,  1484,  3148,
    3391,  1271,  2106,   623,  3147,  1284,  1284,  3130,  1284,  2897,
    2652,  1284,  2038,  1284,  2320,   192,  2756,  1284,  3041,  2174,
    1211,  3042,  2287,  3513,  3282,  2784,  3445,   193,  2898,  2622,
    3151,  2573,  2507,  3093,  3043,  2942,  3277,  3094,  2947,  3446,
    2191,  3304,  2812,   661,  2901,    64,  3533,  2851,  3229,  2852,
    3035,  1908,  3281,  2256,  2255,   194,    89,  2183,  3426,  2243,
    3228,  3063,  3350,  1875,  3367,  2148,  3359,  3063,  3063,    89,
    3063,  3063,  3063,  3063,  3045,  2215,  2967,  2641,  2069,  3063,
     686,  2612,  3154,  2612,     0,  3312,  3046,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,     0,     0,
    2009,     0,     0,     0,  2431,     0,     0,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2671,  3047,     0,
    3185,  2671,     0,     0,  1118,   429,     0,     0,     0,     0,
       0,     0,     0,  1119,     0,   429,    85,    89,   195,     0,
       0,     0,  1120,     0,     0,     0,    89,  1121,     0,  1025,
       0,     0,     0,     0,     0,     0,     0,  3048,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3063,     0,  3049,
    3063,  3063,  3063,  3063,     0,     0,     0,     0,  1157,     0,
       0,  3050,  3051,     0,     0,     0,     0,  3214,     0,  3052,
       0,  1122,  3053,  2612,  3275,     0,     0,     0,     0,  1123,
     323,  1291,  2766,     0,  3054,  3054,     0,     0,  3054,  2563,
       0,     0,  2566,  2567,  2568,  2569,     0,     0,     0,  3240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,    84,     0,    42,     0,
       0,     0,  2612,     0,  2188,     0,  1150,  2384,  1209,     0,
       0,     0,  3063,     0,  2391,  1124,  1366,     0,     0,     0,
    3063,     0,     2,     3,  1034,  1157,     0,  1034,   197,     0,
    1284,     0,     0,  1284,     0,  1284,     0,  2612,     0,     0,
    1125,     0,     0,     0,  2211,  2212,   187,  1126,     0,  1127,
       0,  2228,     0,  3423,     0,  2433,     0,     0,     0,  1128,
      89,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   199,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1129,     0,     0,  3189,     0,
    1157,  2490,  1157,  1130,     0,     0,  1019,   429,     5,     6,
      89,     7,     8,     0,  1285,     0,     9,     0,     0,     0,
    1285,  1285,     0,   200,     0,     0,  1285,  1285,  1285,  1285,
       0,  3205,  2532,    10,    11,     0,     0,     0,     0,   201,
     215,  1131,     0,     0,     0,     0,     0,   202,     0,     0,
       0,    12,     0,    89,     0,     0,     0,     0,  1284,     0,
     203,  2612,     0,     0,     0,     0,     0,  1132,     0,  1034,
       0,  3054,     0,     0,     0,     0,    85,  3054,  3054,     0,
    3054,  3054,  3054,  3054,     0,     0,  2612,     0,  2612,  3054,
       0,  1284,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,  1133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1134,     0,     0,     0,
       0,     0,    13,    89,     0,     0,     0,     0,    89,   205,
      89,     0,     0,     0,     0,   661,     0,     0,     0,     0,
       0,     0,     0,  1157,   218,     0,  1291,     0,  2392,     0,
      89,     0,     0,     0,   206,     0,     0,  1157,     0,  1157,
       0,     0,     0,     0,     0,     0,     0,    89,  1157,     0,
       0,     0,     0,     0,     0,     2,     3,  3214,     0,     0,
       0,     0,     0,  1284,     0,     0,     0,  3054,     0,  2436,
    3054,  3054,  3054,  3054,  3442,     0,  2804,     0,   207,  1285,
       0,     0,     0,     0,     0,  2691,     0,   208,  2188,     0,
       0,  2816,  3316,     0,  1034,  1135,  1136,  1137,  1284,  1266,
       0,     0,  2840,   302,  1267,  1268,    42,     0,  1138,     0,
       0,     0,     0,     0,  2715,     0,    89,    89,    89,    89,
      89,    89,     0,     0,  3338,     0,     0,     0,  3475,     0,
       0,     5,     6,     0,     7,     8,     0,     0,     0,     9,
       0,     0,     0,     0,     0,     0,     0,     0,  1269,     0,
       0,     0,  3054,     0,     0,     0,    10,    11,     0,     0,
    3054,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,   210,     0,    12,     0,  1285,     0,     0,     0,
       0,     0,     0,     0,  1285,     0,     0,  1285,  1285,  1285,
    1285,     0,     0,     0,     0,     0,     0,     0,     0,  1285,
       0,     0,     0,  1284,    16,  3515,     0,     0,     0,     0,
       0,  1139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1285,     0,     0,     0,     0,     0,     0,
    1285,     0,  2786,  2431,   486,   487,   488,   489,   490,   491,
     492,   493,  3531,  3532,  3515,    13,     0,     0,     0,     0,
       0,    89,     0,  3539,     0,     0,     0,     0,   494,     0,
       0,     0,     0,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,   611,   478,   479,   480,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,     0,     0,   495,   496,   497,   498,
     499,   500,     0,     0,     0,  2706,  2707,  3473,     0,     0,
     494,     0,   501,   502,   503,     0,  2716,     0,     0,     0,
       0,  1157,     0,     0,     0,     0,     0,     0,     0,  3108,
       0,     0,  1157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2730,  2731,  2732,  2733,     0,     0,     0,     0,
    2738,  2739,  2740,  2741,     0,     0,     0,  2743,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,     0,     0,  2979,     0,  1047,     0,
    2983,     0,     0,     0,   501,   502,   503,     0,     0,     0,
    1430,     0,     0,  2994,     0,     0,     0,     0,   218,     0,
       0,  3002,  2433,  3522,     0,  2692,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,  3016,  3018,    16,     0,     0,
       0,  1285,     0,     0,     0,  2788,  2789,     0,     0,   494,
       0,     1,  2793,  2794,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,     0,     0,   505,     0,     0,     0,
    1270,     0,     2,     3,  3079,     0,     0,     0,     0,     0,
       0,   105,     0,     0,     0,  1271,   106,     0,     0,     0,
       0,  1285,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1272,     0,  1285,  1273,  1285,   495,   496,   497,
     498,   499,   500,     0,     0,     0,     0,  1285,  1274,     0,
       0,     0,     0,   501,   502,   503,     0,     0,     0,     0,
       0,   107,   108,     0,     0,   504,     0,     0,   505,   109,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       0,     7,     8,     0,     0,     0,     9,  1431,  1275,     0,
    1285,     0,     0,     0,     0,     0,     0,     0,     0,  3131,
    1276,     0,     0,    10,    11,     0,     0,     0,  2949,  2950,
       0,     0,  3146,     0,     0,   506,     0,  2957,     0,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,   508,     0,     0,     0,  3280,
       0,  2840,  1277,     0,     0,     0,     0,     0,  2988,  2989,
    1157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1157,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   218,   509,     0,  3011,     0,  3013,  1285,     0,
       0,  1278,     0,     0,     0,     0,     0,   506,   494,     0,
    2433,     0,     0,  1279,   504,     0,     0,   505,     0,  1211,
       0,   510,     0,   507,     0,  1280,  1281,   508,     0,  1285,
       0,     0,     0,  1282,  1432,     0,  1283,     0,     0,   511,
    1433,  1434,  1435,     0,   323,     0,     0,  1285,  1285,  1285,
    1285,  3081,  3082,     0,     0,  3083,  3084,     0,     0,     0,
    1436,     0,     0,     0,     0,   509,   495,   496,   497,   498,
     499,   500,     0,     0,  1291,     0,     0,     0,     0,     0,
       0,     0,   501,   502,   503,     0,     0,     0,     0,     0,
       0,     0,     0,   510,     0,  1285,  1285,     0,     0,     0,
    1880,     0,     0,     0,     0,     0,  1285,  1285,     0,  1285,
       0,   511,  1285,     0,  1285,     0,     0,     0,  1285,     0,
       0,   512,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1053,  1053,  1053,   506,  1053,  1053,  1053,
    1053,  1053,  1053,   110,  3137,     0,  1053,     0,     0,     0,
       0,     0,   507,     0,     0,     0,   508,     0,     0,     0,
       0,  2092,     0,     0,     0,     0,     0,     0,     0,  1437,
     111,     0,  1438,  3131,     0,     0,     0,     0,     0,     0,
    1439,     0,     0,     0,     0,     0,     0,   513,     0,     0,
       0,     0,     0,   512,   509,     0,     0,     0,     0,  3432,
       0,     0,     0,  1881,     0,     0,     0,     0,     0,     0,
       0,  1882,  3182,  1157,     0,  1440,  3187,  1883,     0,  1884,
       0,     0,   510,   504,     0,     0,   505,     0,     0,     0,
    1885,     0,  3192,     0,  3447,     0,     0,     0,     0,     0,
     511,   112,     0,     0,     0,     0,     0,     0,     0,     0,
    1441,  3203,     0,     0,     0,     0,  2433,  1209,  1886,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1442,  1443,     0,     0,  1887,     0,     0,     0,     0,  1888,
       0,  1444,     0,     0,     0,     0,  1445,     0,     0,     0,
       0,  1889,     0,     0,     0,   299,  2433,     0,  1890,     0,
       0,     0,     0,     0,   300,   301,     0,     0,     0,     0,
     302,   303,   304,    42,     0,  1285,  1285,     0,     0,  1285,
       0,     0,   512,     0,     0,  1446,  3131,     0,     0,     0,
       0,  3386,     0,  3388,   113,     0,     0,     0,     0,  3432,
       0,   163,     0,     0,     0,   506,     0,     0,     0,     0,
     192,     0,     0,  1157,     0,   305,     0,  1447,     0,     0,
       0,   507,   193,     0,     0,   508,     0,     0,     0,     0,
    1211,     0,     0,     0,     0,  1285,   218,     0,  1285,     0,
     164,  1285,     0,     0,  1285,     0,  1285,     0,   513,     0,
     194,     0,     0,     0,     0,     0,     0,     0,     0,   165,
       0,  3038,  3039,   509,     0,     0,     0,   302,  1267,  1268,
      42,     0,     0,     0,   114,     0,     0,     0,   299,     0,
       0,     0,   115,     0,     0,     0,     0,   300,   301,     0,
       0,   510,     0,   302,   303,   304,    42,     0,   166,  1426,
    1426,  1426,  1426,  1426,  1426,     0,     0,     0,     0,   511,
     167,     0,  3040,  1891,     0,     0,     0,     0,     0,     0,
    1892,   168,     0,     0,     0,     0,  3336,     0,     0,  3339,
       0,     0,     0,   192,     0,     0,     0,     0,   305,   169,
       0,    85,  1893,   195,     0,   193,     0,  1894,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1285,
       0,     0,     0,     0,     0,   171,     0,     0,     0,     0,
       0,     0,  1285,   194,     0,     0,     0,     0,  1285,  1285,
       0,  1285,  1285,  1285,  1285,     0,     0,     0,     0,     0,
    1285,   512,  1285,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,  1285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,     0,
       0,     0,     0,     0,  1211,     0,     0,     0,  1033,     0,
     196,     0,     0,   174,     0,   306,     0,     0,     0,     0,
     175,     0,     0,   176,     0,  3421,     0,   513,     0,     0,
       0,     0,     0,     0,    85,     0,   195,     0,  1209,     0,
       0,     0,     0,   197,   177,     0,     0,   178,     0,   179,
       0,     0,     0,     0,  1285,     0,     0,     0,  1285,     0,
       0,  1285,  1285,  1285,  1285,     0,     0,     0,   180,     0,
       0,     0,     0,     0,  3448,  3449,     0,  3451,   198,  3453,
    3454,     0,     0,     0,     0,  1285,   181,     0,     0,  1285,
     199,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,   308,     0,     0,   309,     0,     0,
       0,     0,     0,  1264,  1265,  1266,     0,     0,   200,   302,
    1267,  1268,    42,   196,   310,     0,     0,     0,   306,     0,
    3499,     0,  3500,  1285,   201,     0,     0,     0,     0,   311,
       0,  1285,   312,     0,     0,   313,     0,     0,     0,     0,
       0,     0,     0,     0,   314,   203,   197,     0,     0,     0,
       0,     0,     0,     0,  1269,  3512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3519,  3520,     0,  1285,  3521,     0,     0,  3523,     0,
       0,   198,     0,     0,  1374,   315,   299,     0,     0,   204,
       0,     0,     0,   199,  1270,   300,   301,   316,     0,     0,
       0,   302,   303,   304,    42,     0,     0,     0,   317,  1271,
       0,     0,   307,     0,   205,     0,     0,   308,     0,     0,
     309,     0,  1209,     0,     0,     0,  3041,     0,     0,  3042,
       0,   200,     0,     0,     0,     0,     0,   310,     0,   318,
       0,   192,  3043,     0,     0,     0,   305,   201,     0,     0,
       0,     0,   311,   193,     0,   312,     0,     0,   313,     0,
       0,     0,     0,     0,     0,     0,     0,   314,   203,  1953,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1033,   194,  3045,   207,     0,     0,     0,     0,     0,     0,
     319,     0,   208,     0,  3046,     0,     0,     0,     0,     0,
       0,     0,   320,   321,     0,     0,     0,     0,   315,     0,
     322,     0,   204,     0,     0,     0,     0,     0,     0,     0,
     316,   323,     0,     0,     0,     0,     0,     0,     0,   299,
       0,   317,     0,  2659,     0,     0,  3047,   205,   300,   301,
       0,     0,     0,     0,   302,   303,   304,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   318,  2459,  2460,  2461,  2462,  2463,  2464,     0,
       0,     0,    85,     0,   195,  3048,   209,   210,     0,     0,
       0,     0,     0,     0,   192,     0,     0,  3049,     0,   305,
       0,     0,     0,     0,     0,     0,   193,     0,     0,  3050,
    3051,     0,     0,     0,     0,     0,   207,  3052,     0,     0,
    3053,     0,     0,   319,     0,   208,     0,     0,   323,     0,
       0,     0,  2465,     0,   194,   320,   321,     0,     0,     0,
       0,     0,     0,   322,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,     0,     0,     0,     0,   478,
     479,   480,     0,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,   494,     0,     0,     0,  1270,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     210,  1271,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,   195,  1272,     0,
       0,  1273,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1274,     0,     0,     0,     0,   198,
     495,   496,   497,   498,   499,   500,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,   501,   502,   503,     0,
     487,   488,   489,   490,   491,   492,   493,     0,     0,     0,
     307,     0,     0,  2428,  1275,   308,     0,     0,   309,     0,
       0,     0,     0,   494,     0,     0,  1276,     0,     0,   200,
       0,     0,     0,     0,     0,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
     311,     0,     0,   312,   196,     0,   313,     0,     0,   306,
       0,     0,     0,     0,     0,   314,   203,     0,  1277,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,   499,   500,   197,     0,     0,
       0,     0,     0,     0,     0,     0,  2466,   501,   502,   503,
       0,     0,     0,     0,     0,  2998,   315,  1278,     0,  2467,
     204,     0,     0,     0,     0,     0,     0,     0,   316,  1279,
       0,     0,   198,     0,     0,     0,     0,     0,     0,   317,
       0,  1280,  1281,     0,   199,   205,     0,   504,     0,  1282,
     505,     0,  1283,     0,     0,     0,     0,     0,     0,     0,
     323,     0,     0,   307,     0,     0,     0,     0,   308,     0,
     318,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,  2468,     0,     0,     0,   310,     0,
       0,  2469,     0,     0,     0,     0,     0,     0,   201,     0,
       0,     0,     0,   311,     0,     0,   312,     0,     0,   313,
       0,     0,     0,     0,   207,     0,     0,     0,   314,   203,
       0,   319,     0,   208,     0,     0,     0,     0,     0,     0,
    2470,     0,     0,   320,   321,     0,     0,     0,     0,     0,
       0,   322,     0,     0,     0,     0,     0,     0,   504,     0,
       0,   505,   323,     0,  2471,     0,     0,     0,     0,   315,
       0,     0,     0,   204,  2472,  2473,     0,     0,     0,   506,
    2474,   316,     0,     0,     0,     0,     0,     0,     0,     0,
    2475,     0,   317,     0,     0,   507,     0,     0,   205,   508,
     600,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2476,     0,     0,  2477,  2478,   209,   210,     0,
       0,  2479,     0,   318,     0,     0,  1525,  1526,  1527,  1528,
    1529,  1530,     0,  1531,  1532,  1533,     0,   509,     0,  1534,
    1535,  1536,  1537,  1538,  1539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   510,     0,   207,     0,     0,
    1541,     0,     0,     0,   319,     0,   208,     0,  2480,     0,
     506,     0,     0,   511,     0,     0,   320,   321,  1542,  2481,
       0,     0,     0,     0,   322,     0,   507,  1543,     0,     0,
     508,     0,     0,     0,     0,   323,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1544,     0,  1545,     0,     0,
       0,     0,     0,     0,     0,  1546,     0,     0,     0,     0,
    1547,  1548,     0,     0,  1549,  1550,  1551,  1552,   509,     0,
    1553,  1554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,   210,     0,     0,     0,   512,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1555,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1556,     0,     0,     0,     0,     0,  1557,
       0,     0,     0,     0,     0,  2147,  1558,     0,  1559,     0,
       0,     0,     0,     0,  1560,     0,     0,     0,     0,     0,
       0,   513,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1561,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   512,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1562,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1563,     0,     0,     0,     0,     0,  1564,     0,     0,     0,
       0,     0,     0,     0,     0,  1565,  1566,     0,     0,     0,
       0,     0,  1567,     0,     0,  1568,  1569,     0,     0,     0,
    1570,     0,   513,     0,     0,     0,  1571,  1572,     0,     0,
       0,     0,     0,  1573,  1574,  1575,  1576,  1577,  1578,     0,
       0,     0,  1579,     0,     0,     0,  1580,     0,  1581,     0,
       0,     0,     0,     0,     0,  1582,  1583,  1584,  1585,     0,
    1586,  1587,     0,     0,     0,  1588,  1589,     0,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,     0,     0,     0,     0,
       0,  1598,  1599,  1600,     0,  1601,  1602,     0,     0,     0,
    1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,     0,
    1612,     0,     0,     0,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,     0,  1651,  1652,     0,     0,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,     0,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,     0,     0,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,     0,  1687,  1688,  1689,  1690,     0,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,     0,  1727,  1728,  1729,
    1730,  1731,  1732,     0,     0,  1733,  1734,     0,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,
    1757,  1758,  1759,  1760,  1761,     0,     0,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,     0,
       0,     0,     0,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1835,     0,     0,     0,     0,     0,
       0,     0,  1836,     0,     0,     0,     0,  1837,     0,     0,
       0,  1838,     0,     0,  1839,  1840,  1841,  1842,     0,     0,
    1843,  1844,     0,  1845,  1846,  1847,  1525,  1526,  1527,  1528,
    1529,  1530,     0,  1531,  1532,  1533,     0,     0,     0,  1534,
    1535,  1536,  1537,  1538,  1539,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1540,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1541,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1542,     0,
       0,     0,     0,     0,     0,     0,     0,  1543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1544,     0,  1545,     0,     0,
       0,     0,     0,     0,     0,  1546,     0,     0,     0,     0,
    1547,  1548,     0,     0,  1549,  1550,  1551,  1552,     0,     0,
    1553,  1554,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1556,     0,     0,     0,     0,     0,  1557,
       0,     0,     0,     0,     0,     0,  1558,     0,  1559,     0,
       0,     0,     0,     0,  1560,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1561,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1562,     0,     0,
    1264,  1265,  1266,     0,     0,     0,   302,  1267,  1268,    42,
    1563,     0,     0,     0,     0,     0,  1564,     0,     0,     0,
       0,     0,     0,     0,     0,  1565,  1566,     0,     0,     0,
       0,     0,  1567,     0,     0,  1568,  1569,     0,     0,     0,
    1570,     0,     0,     0,     0,     0,  1571,  1572,     0,     0,
       0,  1269,     0,  1573,  1574,  1575,  1576,  1577,  1578,     0,
       0,     0,  1579,     0,     0,     0,  1580,     0,  1581,     0,
       0,     0,     0,     0,     0,  1582,  1583,  1584,  1585,     0,
    1586,  1587,     0,     0,     0,  1588,  1589,     0,  1590,  1591,
    1592,  1593,  1594,  1595,  1596,  1597,     0,     0,     0,     0,
       0,  1598,  1599,  1600,     0,  1601,  1602,     0,     0,     0,
    1603,  1604,  1605,  1606,  1607,  1608,  1609,  1610,  1611,     0,
    1612,     0,     0,     0,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,  1644,  1645,  1646,  1647,  1648,
    1649,  1650,     0,  1651,  1652,     0,     0,  1653,  1654,  1655,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1033,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,  1671,  1672,  1673,  1674,
    1675,  1676,  1677,     0,     0,  1678,  1679,  1680,  1681,  1682,
    1683,  1684,  1685,  1686,     0,  1687,  1688,  1689,  1690,     0,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,     0,  1727,  1728,  1729,
    1730,  1731,  1732,     0,     0,  1733,  1734,     0,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,  1756,
    1757,  1758,  1759,  1760,  1761,     0,     0,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823, -2158,
       0,     0,     0,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834, -2158,     0, -2158, -2158, -2158,     0,
       0,     0,     0,     0,  1835,     0,     0,     0,     0,     0,
       0,     0,  1836,  1270,     0,     0,     0,  1837,     0,     0,
       0,  1838,     0, -2158,  1839,  1840,  1841,  1842,  1271,     0,
    1843,  1844,     0,  1845,  1846,  1847,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1272,     0,     0,  1273,     0,
       0,     0, -2158,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1953,     0,
       0,     0,     0,     0, -2158,     0,     0,     0,     0,     0,
       0,  1275,  1264,  1265,  1266,     0,     0,     0,   302,  1267,
    1268,    42,     0,  1276,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -2158,     0,     0, -2158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0, -2158,  1269,     0,  1277,     0,     0,     0,     0,
   -2158,     0, -2158,     0,     0,     0,     0,     0,     0,     0,
       0, -2158,     0,     0,     0,     0,     0, -2158,     0,     0,
       0,     0,     0,     0,     0, -2158,     0,     0,     0, -2158,
       0,     0,     0,     0,  1278, -2158,     0,     0,     0, -2158,
   -2158, -2158, -2158,     0,     0,     0,  1279,     0,     0,     0,
       0,     0,     0,     0, -2158,     0,     0,     0,  1280,  1281,
       0,     0,     0,     0,     0,     0,  1282,     0,     0,  1283,
       0, -2158,     0,     0, -2158,     0, -2158,   323,     0,     0,
       0,     0,     0, -2158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2158,     0,     0,     0,
       0,     0,     0,     0,     0,     0, -2158,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     0,  1033,
       0,   688,   689,   690,     0, -2158, -2158,     0,     0,   691,
       0,     0,     0,     0,     0,     0,   692,     2,     3,     0,
   -2158,     0,     0,     0,     0,   693,     0,     0, -2158,     0,
       0,     0, -2158,     0,     0,     0,     0,   694,   695,     0,
     696, -2158, -2158, -2158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   697,     0,     0,     0,     0,     0,
       0,   698,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   699,   700,   701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   702,     0,
     703,   704,   705,     5,     6,   706,     7,     8,   707,     0,
     708,     9,   709,   710,     0,     0,     0,     0,     0,   711,
       0, -2158,   712,     0,   713,   714,   715,     0,    10,    11,
       0,     0, -2158,     0,   716,     0,   717,   718,     0,   719,
       0,   720,   721,     0,     0,   722,    12,     0,     0,   723,
     724,   725,     0,   726,   727,     0,     0,     0,   728,   729,
     730,     0,   731,     0,     0,     0,   732,     0,   733,   734,
       0,     0, -2158,     0,   735,     0,     0,     0,   736,     0,
       0,   737,     0,   738,     0,   739,     0,   740,     0,   741,
     742,     0,   743,   744,   745,     0,     0,     0,   746,     0,
     747,   748,     0,   749,     0,     0,     0,     0,     0,     0,
       0,   750,   751,     0,     0,  1270,     0,     0,     0,     0,
       0,     0,     0,     0,   752,     0,     0,   753,   754,     0,
    1271,   755,   756,     0, -2158,   757,   758,     0,     0,     0,
       0,     0,     0,     0,   759,   760,   761,  1272,   762,     0,
    1273,     0,     0,     0,     0,     0,     0,     0,   763,   764,
     765,     0,   766,  1274,     0,     0,   767,   768,     0,     0,
   -2158,   769,     0,     0,     0,     0,     0,     0,     0,   770,
       0,     0,     0,     0,     0,     0,     0,   771,   772,   773,
       0,     0,     0,     0,     0,   774,   775,     0,     0,     0,
       0,   776,  3429,  1275,   777,     0,     0,     0,   778,   779,
       0,     0,     0,     0,     0,  1276, -2158,     0,     0,   780,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -2158, -2158, -2158, -2158, -2158, -2158, -2158,   781, -2158, -2158,
       0,     0,     0,     0,     0,   782,     0,     0,     0,     0,
       0,   783,     0,     0,     0, -2158,     0,  1277,     0,     0,
       0,     0,   784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,   785,     0,   786,   787,     0,     0,     0,     0,
       0,     0,     0,   788,     0,     0,  1278,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1280,  1281,     0,     0,     0,     0,     0,     0,  1282,     0,
       0,  1283,   789,     0,     0,     0,     0,     0,     0,   323,
       0,     0,     0,   790,     0,     0,     0,     0,     0,     0,
     791,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   792,   793,     0,     0,     0,   794,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   795,     0,     0,     0,     0,     0,   796,   797,   798,
     799,     0,     0,     0,   800,     0,     0,     0,   801,     0,
       0,     0,     0,     0,     0,   802,   803,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   804,     0,   805,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     806,     0,   807,     0,     0,   808,     0,     0,     0,     0,
       0,   809,     0,     0,     0,     0,     0,   478,   479,   480,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,     0,     0,     0,   810,     0,     0,
     811,     0,     0,     0,     0,   812,     0,     0,   813,   814,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   815,     0,     0,     0,   478,   479,   480,
     816,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   817,   818,   819,   820,   821,   822,   823,
     494,     0,   824,     0,   825,     0,   826,     0,   495,   496,
     497,   498,   499,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,   502,   503,     0,     0,     0,
       0,   478,   479,   480,     0,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,   502,   503,     0,   478,   479,
     480,     0,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   501,   502,
     503,     0,   478,   479,   480,     0,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,     0,
       0,     0,     0,     0,     0,   504,     0,     0,   505,   495,
     496,   497,   498,   499,   500,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   501,   502,   503,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,   505,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   501,
     502,   503,     0,     0,     0,     0,   478,   479,   480,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,     0,     0,     0,     0,     0,     0,   504,
       0,     0,   505,     0,     0,     0,     0,   506,     0,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,   508,   610,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   504,     0,     0,   505,
       0,     0,     0,     0,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,     0,   509,     0,   495,   496,   497,
     498,   499,   500,   507,     0,     0,     0,   508,   620,     0,
       0,     0,     0,   501,   502,   503,     0,     0,     0,     0,
       0,     0,     0,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,   511,     0,   505,     0,   509,     0,     0,     0,     0,
       0,   506,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,     0,
       0,   508,   974,   510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   511,     0,     0,     0,     0,     0,     0,   506,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   509,
       0,     0,     0,     0,   507,     0,     0,     0,   508,   980,
     478,   479,   480,   512,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   494,   504,   511,   509,   505,     0,     0,
       0,     0,   506,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   512,     0,     0,     0,     0,   507,     0,
       0,     0,   508,   981,   510,     0,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   511,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,   499,   500,     0,     0,     0,
     509,     0,     0,     0,     0,     0,     0,   501,   502,   503,
       0,     0,     0,     0,     0,     0,     0,   512,     0,   513,
       0,     0,     0,     0,     0,   478,   479,   480,   510,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   506,     0,   494,     0,
       0,     0,     0,     0,   512,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,   508,   982,     0,     0,
       0,     0,     0,   513,     0,     0,     0,     0,     0,   478,
     479,   480,     0,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,   495,   496,   497,   498,
     499,   500,   494,     0,     0,     0,     0,     0,   512,     0,
     513,     0,   501,   502,   503,     0,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,     0,     0,   504,     0,
       0,   505,     0,     0,     0,     0,     0,   478,   479,   480,
     511,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   499,   500,     0,     0,     0,     0,
     494,     0,     0,     0,   513,     0,   501,   502,   503,     0,
       0,     0,     0,     0,   478,   479,   480,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   494,     0,     0,
       0,     0,   512,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   501,   502,   503,     0,     0,     0,
     506,     0,     0,   504,     0,     0,   505,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   507,     0,     0,     0,
     508,   983,     0,     0,     0,   495,   496,   497,   498,   499,
     500,     0,     0,     0,     0,     0,     0,     0,   513,     0,
       0,   501,   502,   503,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   509,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
     505,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,   480,   510,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   493,
       0,     0,     0,     0,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   494,     0,     0,     0,
       0,     0,     0,     0,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,     0,   505,     0,
       0,   507,     0,     0,     0,   508,     0,     0,     0,   480,
       0,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   499,   500,
     494,     0,   504,   509,     0,   505,   512,     0,     0,   506,
     501,   502,   503,     0,     0,     0,   985,     0,     0,     0,
       0,     0,     0,  2577,     0,   507,     0,     0,     0,   508,
       0,   510,  1264,  1265,  1266,     0,     0,     0,   302,  1267,
    1268,    42,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,     0,     0,     0,   509,     0,     0,
       0,     0,   513,     0,   501,   502,   503,   506,     0,     0,
     986,     0,     0,  1269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,     0,   510,     0,   508,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   506,     0,     0,   494,     0,     0,
       0,   512,     0,     0,     0,   509,     0,     0,     0,     0,
     507,     0,     0,     0,   508,     0,     0,     0,   989,     0,
       0,   504,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,   510,     0,     0,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,     0,     0,     0,     0,
       0,   511,   509,     0,     0,   495,   496,   497,   498,   499,
     500,     0,   494,     0,     0,   512,     0,   513,     0,     0,
       0,   501,   502,   503,     0,     0,     0,     0,     0,  1033,
     510,     0,     0,     0,     0,   504,     0,     0,   505,     0,
    2577,     0,     0,     0,     0,     0,     0,     0,   511,  1264,
    1265,  1266,     0,     0,     0,   302,  1267,  1268,    42,   489,
     490,   491,   492,   493,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   499,   500,     0,     0,     0,     0,
     494,   513,     0,   512,     0,     0,   501,   502,   503,     0,
       0,     0,     0,   506,     0,  1264,  1265,  1266,     0,     0,
    1269,   302,  1267,  1268,    42,     0,     0,     0,     0,   507,
       0,     0,     0,   508,     0,     0,     0,     0,     0,   485,
     486,   487,   488,   489,   490,   491,   492,   493,     0,     0,
     512,     0,     0,  2578,     0,     0,     0,     0,   495,   496,
     497,   498,   499,   500,   494,     0,  1269,     0,     0,   513,
       0,   509,     0,     0,   501,   502,   503,   506,     0,     0,
       0,     0,   504,     0,     0,   505,     0,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,   508,     0,   510,
       0,  1264,  1265,  1266,     0,     0,     0,   302,  1267,  1268,
      42,     0,     0,     0,     0,     0,   513,   511,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,     0,   488,
     489,   490,   491,   492,   493,   509,     0,     0,   501,   502,
     503,     0,     0,     0,     0,     0,  1033,   504,     0,     0,
     505,   494,  1269,     0,     0,  1270,     0,     0,     0,     0,
       0,     0,     0,   510,     0,     0,     0,     0,  3038,  3039,
    1271,     0,     0,     0,   302,  1267,  1268,    42,     0,     0,
       0,   511,     0,     0,     0,     0,     0,  1272,     0,     0,
    2579,     0,  1033,     0,     0,     0,     0,     0,     0,   512,
       0,     0,  2580,  1274,   506,     0,     0,     0,     0,   495,
     496,   497,   498,   499,   500,   504,     0,     0,   505,  3040,
     507,     0,     0,     0,   508,   501,   502,   503,     0,     0,
    1953,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1275,     0,     0,     0,     0,     0,     0,
    2578,  3038,  3039,     0,     0,  1276,     0,   302,  1267,  1268,
      42,     0,   509,   512,     0,   513,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,     0,  1033,   504,
       0,     0,   505,     0,     0,   507,     0,     0,     0,   508,
     510,     0,     0,     0,     0,     0,  2578,  1277,     0,     0,
       0,     0,  3040,     0,     0,     0,     0,     0,   511,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   509,     0,   513,
       0,     0,     0,     0,     0,     0,  1278,   506,     0,     0,
       0,     0,     0,     0,     0,  1033,     0,     0,  1279,     0,
       0,     0,  1270,   507,     0,   510,     0,   508,     0,     0,
    1280,  1281,     0,     0,     0,     0,   504,  1271,  1282,   505,
       0,  1283,     0,   511,     0,     0,     0,     0,     0,   323,
       0,     0,     0,     0,  1272,     0,     0,  2579,     0,     0,
     512,     0,     0,     0,     0,   509,     0,     0,  1270,  2580,
    1274,   506,     0,     0,     0,     0,     0,     0,   230,     0,
     231,     0,     0,  1271,     0,     0,     0,   507,     0,     0,
       0,   508,     0,   510,     0,     0,     0,     0,  1033,     0,
    1272,     0,     0,  2579,     0,     0,     0,     0,     0,     0,
    1275,   511,     0,     0,     0,  2580,  1274,     0,     0,     0,
       0,     0,  1276,     0,     0,   512,   513,     0,     0,   509,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1270,     0,  1275,   510,   506,     0,
       0,     0,     0,     0,  1277,     0,     0,     0,  1276,  1271,
       0,     0,     0,     0,   507,   511,     0,     0,   508,     0,
       0,     0,     0,     0,     0,     0,  1272,     0,     0,  1273,
       0,   513,     0,   512,     0,     0,     0,     0,     0,     0,
       0,     0,  1274,  1278,     0,     0,     0,     0,     0,     0,
    1277,     0,     0,     0,     0,  1279,   509,     0,     0,     0,
       0,  1270,     0,     0,     0,     0,     0,  1280,  1281,     0,
       0,     0,     0,     0,     0,  1282,  1271,     0,  1283,     0,
       0,     0,  1275,     0,   510,     0,   323,     0,     0,  1278,
       0,     0,     0,  3041,  1276,     0,  3042,   512,     0,   513,
       0,  1279,   511,     0,     0,     0,     0,     0,     0,  3043,
       0,     0,     0,  1280,  1281,     0,     0,     0,     0,     0,
       0,  1282,     0,     0,  1283,  2854,  2855,     0,  2856,  2857,
    2858,     0,   323,     0,     0,     0,  1277,     0,  2459,  2460,
    2461,  2462,  2463,  2464,  1270,     0,     0,     0,  3044,  3045,
       0,   235,     0,     0,     0,     0,     0,     0,     0,  1271,
       0,  3046,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1278,  3041,     0,     0,  3042,
       0,     0,     0,     0,   512,     0,     0,  1279,     0,     0,
     236,     0,  3043,     0,     0,     0,     0,  2465,     0,  1280,
    1281,     0,     0,  3047,     0,     0,     0,  1282,     0,   237,
    1283,     0,     0,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,   238,     0,     0,  2859,     0,
       0,     0,  3045,     0,     0,     0,  2860,     0,     0,     0,
       0,     0,  3048,     0,  3046,     0,     0,     0,   239,     0,
     513,     0,     0,     0,  3049,     0,     0,     0,     0,     0,
     240,     0,     0,     0,     0,     0,  3050,  3051,     0,     0,
    2861,   241,     0,     0,  3052,     0,     0,  3053,     0,  2862,
       0,     0,     0,     0,     0,   323,  3047,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   243,
       0,     0,  3400,     0,     0,     0,     0,     0,  2863,  2864,
       0,     0,     0,     0,     0,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3048,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3049,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3050,
    3051,     0,     0,  2865,     0,   245,     0,  3052,  3401,     0,
    3053,     0,     0,     0,     0,     0,     0,     0,   323,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   246,     0,
       0,     0,     0,  3402,     0,     0,     0,     0,     0,     0,
       0,     0,  3403,   247,     0,  2866,     0,     0,     0,     0,
     248,     0,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   250,     0,     0,   251,  3404,   252,
       0,  2466,     0,     0,     0,     0,  3405,     0,     0,     0,
       0,     0,     0,     0,  2467,     0,     0,     0,   253,     0,
       0,     0,  2867,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   255,  2468,
       0,     0,     0,     0,     0,     0,  2469,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3406,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2470,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2472,
    2473,     0,     0,     0,     0,  2474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2475,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2476,     0,     0,
    2477,  2478,     0,     0,     0,     0,  2479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2868,  2869,  2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,
       0,     0,     0,  2480,     0,     0,     0,     0,     0,     0,
       0,     0,  3407,     0,  2481
};

static const short yycheck[] =
{
       4,   138,   418,   202,   665,   999,  1335,   221,    68,    13,
      14,  1051,   180,    17,  1264,  1265,  1117,  1128,  1034,     0,
    1146,   287,   288,  1342,  1114,   560,  1151,   796,   289,   290,
      85,  1124,  1125,   294,  1127,   158,  1129,  1130,   650,  1048,
    2072,     5,    46,    47,    25,  1891,  2415,  2558,   698,   798,
      31,    81,  2239,  2578,   585,  2580,  1370,  2286,    62,  1068,
    2633,   121,  2017,  2006,  2293,   202,  2771,  2772,  2773,  1857,
    1858,   756,   602,    20,    78,  1890,  2177,    81,     5,    83,
      27,    85,    27,   204,   221,   253,   781,    68,    27,  2458,
      94,    27,  1958,  1959,  1960,  1961,     5,   101,    24,     5,
      26,   105,    26,    27,   108,   109,   718,  1953,  2020,     5,
     114,   115,    20,  1203,     5,    20,   728,    25,    19,    27,
      25,   105,    27,    24,    25,    26,    25,  1217,    27,    63,
     721,   781,    67,   137,    24,  1236,    26,    25,     5,    27,
     121,  2354,   265,   266,  2774,   786,    24,    25,    26,    27,
     154,   350,    27,   157,  2801,  2189,    67,     5,   162,    86,
      87,    25,    26,    27,    98,    19,    25,  1207,    27,     5,
     291,   783,    26,   785,   295,    25,   297,    27,   299,   300,
     301,     5,   794,    27,     5,   309,  1033,   308,    27,     5,
     240,   312,   313,     5,    27,     5,    27,  2770,  2771,  2772,
    2773,    24,    25,    26,    27,     5,    73,    27,    75,     5,
      77,   145,     5,   350,    27,   149,     6,   354,    27,   223,
     240,   436,    24,    25,    26,   816,    27,    24,    25,    26,
      27,     5,    24,    25,    26,    27,     5,  2288,  2289,     5,
     336,  2292,    25,     5,    27,  2770,  2771,  2772,  2773,     5,
      92,    93,     5,   139,  2572,    25,  2574,    27,   262,    96,
       5,   154,     5,     5,   268,  2912,     6,  2914,  1284,     6,
     395,   195,   154,   364,     5,   279,    53,    54,    55,    56,
      57,   179,   286,   287,   288,   289,   290,    23,     5,     5,
     294,   212,     5,   397,    27,  2346,   195,   364,   464,    24,
      25,    26,    27,   338,   444,    25,  2831,    27,  2833,    27,
    2454,   167,  1135,  1136,  2852,   455,   464,   195,   243,   470,
      25,   255,    27,   537,  2356,  2547,    19,  2514,   594,   556,
       5,    70,   453,   349,   804,   456,   476,   564,   808,   343,
     344,   582,   812,   483,   552,   195,   544,   279,  1474,   353,
    2579,   344,   473,   474,   475,   476,   391,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,     5,   300,     5,     5,   276,  1419,
    2602,   622,     5,   279,   505,   506,   464,     5,   279,   510,
     481,   512,     5,   592,    87,   593,     5,  2935,   195,     5,
     537,  2267,   544,   195,     5,     5,   527,   528,   529,   530,
     436,     5,   195,   534,   481,   623,   631,   250,   693,   250,
     476,   696,   697,   519,  1173,   195,     0,   352,   484,   595,
     263,   356,   263,     5,   530,   710,   370,   463,   372,   155,
    3087,   380,  3089,   377,    61,    62,     5,     5,     5,     5,
     664,   593,   253,  2504,   729,   592,   683,   732,    27,   625,
     510,     5,   195,   738,   167,  3038,  3039,   742,  2502,  3042,
     195,   746,    89,    90,    91,   750,  2527,   625,     5,   754,
     755,     5,   757,  2222,   405,   760,  2225,   762,   763,   764,
       5,   595,   426,   349,   618,   770,   647,  1513,   773,   650,
     591,   561,   562,   239,     5,   780,  1353,     5,   774,     5,
     435,   786,     5,  3038,  3039,   693,     5,  3042,   793,   288,
       5,     5,   526,   401,   591,  3098,    31,   664,  3101,   804,
     791,   792,   250,   808,   354,   446,   145,   812,   416,   664,
     279,   354,     5,   818,  2595,   263,   821,   625,    69,   553,
       5,   729,   556,   354,   732,  2606,     5,   288,     5,   820,
     564,     5,   823,     5,   742,  2752,     5,  2711,   746,   514,
       5,  2359,   750,   397,     5,    27,   580,   436,   582,   757,
     561,   562,   506,     5,   762,   601,   764,   591,   608,   593,
     594,   584,   770,   468,  1235,   773,   432,   436,   476,   401,
       5,     5,   780,   436,   401,   436,  2975,   397,   786,     5,
     349,   432,  2841,   548,   416,   793,   550,   601,   545,   416,
    3250,     5,   432,  1158,  2993,  1160,   804,   436,   567,     5,
     808,   397,  2683,   519,   812,     5,   560,   548,   531,  1388,
     818,  1464,   574,   821,   397,  2491,   349,  2748,   481,   531,
     481,  1400,   397,   559,   397,   397,   395,   397,   432,    27,
     397,  1356,  3235,   476,   497,   390,   497,  1328,  3241,  3242,
     432,  3244,  3245,  3246,  3247,   476,   432,  2620,   574,   683,
    3253,  2636,   395,   574,   688,   689,   690,   691,   692,  1384,
     694,   695,   591,   476,   698,   699,  3269,   701,  2513,   625,
     704,  2020,   706,   667,  1389,   632,  1356,  3218,   556,   617,
    3235,   715,   617,  2764,   623,   432,  3241,  3242,  3229,  3244,
    3245,  3246,  3247,  1254,   625,   672,  2638,   672,  3253,   617,
    1260,   735,   582,   672,  1384,   625,   672,   741,  2951,  3444,
     552,   595,  2955,   747,   748,   749,   562,   625,  3395,   753,
     674,   595,   756,   617,   758,   759,   623,   432,   371,   552,
     556,   379,   562,   481,   631,   769,   397,   492,   397,   397,
     774,   775,  3090,  2087,   397,   805,    27,   781,  3351,   497,
     784,  3354,  3355,  3356,  3357,   789,   556,   791,   792,   631,
    2971,   397,   796,   797,   798,  2534,   397,   397,   802,   162,
     520,   805,   625,   397,    23,  3378,   810,   644,   645,   646,
     647,   648,   589,   817,    27,   819,   820,    23,   822,   823,
      25,   825,   826,   625,   172,   397,  3351,   195,   625,  3354,
    3355,  3356,  3357,   625,  3345,   574,   877,  1253,   397,   397,
     397,   397,  1117,   460,  3213,  2500,   459,   550,    18,    19,
      20,    21,    22,   397,  2905,     5,  2907,    18,    19,    20,
      21,    22,   475,  3436,   644,    10,   987,   647,   648,   990,
     397,  3444,   393,   397,  1883,  1884,  3042,   998,   999,  2667,
     583,   329,   397,  1892,   168,     9,    10,   171,    12,    13,
      14,    15,    16,    17,   346,  1486,   397,   418,  1510,   397,
     625,   397,   354,   355,   397,   518,   329,    25,   397,    27,
      29,  3436,   397,   397,  2241,   654,   655,   656,   722,  3444,
     300,    18,    19,    20,    21,    22,   665,   931,   380,   544,
     547,   383,   344,   344,   397,  2830,    28,  2832,   301,  1117,
    2835,   745,   397,  3060,   195,   558,  3333,  3334,   397,   401,
     397,    28,    29,   397,   365,   397,  1965,   360,   397,  1234,
    1235,  1236,   397,   140,   141,   631,   397,  3344,   972,  2296,
    2297,  3348,     0,   590,   587,   397,  3027,   182,   593,   436,
     501,  2092,   195,   596,  1993,    25,   790,    27,    26,    27,
     162,   275,   397,   397,   278,   799,   800,    25,   617,   803,
      25,   397,    27,   807,   247,   155,  1010,   464,  1012,   813,
      25,   815,    27,   397,  2333,   378,   300,    25,  2337,    27,
     239,   397,   390,    26,    27,  3076,  3255,   397,  3415,  1033,
    3417,   168,   486,   239,   171,  3222,  3217,   358,   486,   630,
     253,    62,   622,  2133,  1048,     9,    10,  1051,    12,    13,
      14,    15,    16,    17,   506,   435,  1234,  1235,  1236,   196,
    3111,  1065,   653,   486,  1068,    20,    21,    22,   358,  3235,
     287,  1005,    24,   594,    26,  3241,  3257,   195,  3244,  3245,
    3246,  3247,    20,   300,    39,   606,   607,   625,    25,    27,
      27,  1132,  3242,   614,    26,    27,   444,     5,  1139,  2754,
    2755,  2202,  1106,  3253,   309,    26,    27,   455,   560,   254,
     315,   316,   317,  3230,  3231,   567,   137,   138,   481,  1123,
    1124,  1125,     5,  1127,  2118,  1129,  1130,   464,   476,   301,
     335,  1135,  1136,   257,   497,   483,   539,  1403,   275,   390,
    1401,   278,    97,    98,    99,   100,   101,   102,   367,   168,
     553,   435,   171,   463,   464,   195,    27,   195,   113,   114,
     115,   367,  3097,   300,    25,  3100,    27,  1171,  3103,  1173,
     195,   397,   584,   584,  3225,   578,   630,   196,    14,  1183,
     195,   202,   630,  3029,  1188,  3351,  2195,   195,  3354,  3355,
    3356,  3357,   195,   527,   243,   649,   650,   287,    25,    26,
     221,   649,   650,  1207,  1208,   431,   378,   630,  1331,  3104,
     300,  1334,  1216,   436,   630,   669,   436,   371,   435,   117,
      25,   669,    27,   626,   541,  1491,   649,   650,  1232,  1233,
    1496,  1492,  2559,   624,   436,  2562,   652,   653,   109,   444,
     631,    25,   447,    27,   464,   436,   669,   392,  2257,   394,
     455,   300,   376,   377,  1258,   464,   275,  1061,   195,   278,
    1264,  1265,   432,   195,   436,   442,    25,   436,    27,  1273,
    3436,   432,   436,   397,   195,    25,   431,    27,  2607,  1283,
    2029,   300,    26,   401,    20,   490,   464,  1291,   159,   243,
      25,    27,    27,   257,    25,   715,    27,  1352,   435,   254,
     397,    20,   257,   352,   436,   459,  2635,   356,    27,   481,
     434,    19,    26,   732,  2440,   735,    24,    25,    26,  2638,
     525,   475,   343,   344,   195,   497,   197,   746,   748,   350,
    1980,   750,  1336,   354,   195,    20,  1340,  1341,  1342,   631,
     545,   546,    27,   762,  3279,   435,   300,  1151,  1352,  1353,
     436,   556,  1356,   630,  1358,  1359,   561,  1161,  1362,    20,
    2917,   436,  1166,  2920,   518,  3397,    27,  2116,  3234,   436,
    3236,  3237,  3238,  3239,   371,   652,   653,   675,   676,   677,
    1384,  1385,  3414,  1387,  1388,  1389,   435,    20,    68,    25,
     195,    27,  1396,  1397,    27,   600,  1400,  1401,   352,  1403,
    1404,    19,   356,   436,   558,  2506,    24,    20,    26,   436,
    1414,   195,   376,   377,    27,  1419,   435,    20,  2187,   764,
      25,   376,    27,   294,    27,  2526,   436,   632,   773,  3461,
     436,  2043,  2181,   587,   645,   646,   195,   392,   562,   631,
     223,   396,   596,   436,   227,   195,  3478,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    24,
    1464,    26,   459,   436,   195,   819,   647,   648,   822,    39,
     434,   825,    26,   818,   436,    39,   821,   436,   475,   434,
    2489,   435,    25,   436,    27,  1489,   436,  1491,  1492,   463,
     464,   362,  1496,    24,  1498,    26,  1500,  1501,    25,   370,
      27,   463,   464,   374,   628,   526,   436,   462,  1133,  1134,
     463,   464,  1137,  1138,   436,  1385,   537,  1387,  1522,   436,
    2529,   518,   113,   114,   115,   480,   436,    97,    98,    99,
     100,   101,   102,    97,    98,    99,   100,   101,   102,   654,
     655,   412,   325,   113,   114,   115,   654,   655,   436,   113,
     114,   115,   292,   293,   678,   679,  3038,  3039,   436,  2649,
      22,   558,   436,  2572,   526,  2574,   436,   436,   697,  2104,
     436,   592,   436,   526,   371,  2324,   436,    39,  2689,  2829,
    2830,   710,  2832,    26,    26,  2835,  1390,  1391,  1392,  2338,
     587,  2340,    26,  1854,  1855,  2720,  2686,  2926,   562,   596,
    2349,  1955,  2627,  1407,  2629,  2630,    26,   562,   479,   738,
     340,   618,   619,   620,   621,  2934,    66,   531,  2744,   436,
     625,   351,   436,   436,   304,   754,   755,   436,   436,   436,
     436,   760,   164,   436,   763,    97,    98,    99,   100,   101,
     102,   436,    26,   664,   426,   464,   371,   518,   180,   181,
      26,   113,   114,   115,    26,    26,   371,   189,    26,    26,
     625,  1465,   459,    63,   628,   397,   436,   688,   689,   690,
     691,   366,   543,   628,   404,    26,   625,   432,   475,   436,
     436,  1485,   362,     5,   254,   706,   397,   257,   138,   419,
     254,   223,   397,   257,   374,   436,   397,   397,  1502,   397,
     232,  2695,   476,   436,   631,   385,    20,    20,  1512,   436,
    2704,  2705,   436,  1881,   678,   679,   587,     5,   397,  1887,
     741,   518,  2334,   403,   436,   596,   747,   464,   749,   261,
     371,   371,   753,   413,   459,   756,   416,    38,   759,    40,
      41,    42,   629,    38,   459,    40,    41,    42,   769,   429,
     475,    26,   625,   263,   204,   432,   206,   366,   397,    20,
     475,   558,    26,   784,   972,   595,  2378,    26,   789,    26,
      26,   221,    26,    26,   306,   796,   797,   798,   508,   229,
      26,   802,   397,   233,    18,    19,    20,    21,    22,   810,
     587,  2145,   254,   518,    26,   257,   397,   477,   397,   596,
    1923,   397,  2077,   518,   397,   826,   376,    26,   258,   680,
     681,     5,   376,    20,   436,  2427,   348,    26,   459,   459,
      26,    26,   392,   625,   397,  2086,   396,   507,   392,     5,
     397,    26,   396,   558,   475,   475,   397,   517,   307,   974,
     397,   397,   977,   558,   979,   980,   981,   982,   983,  1853,
    1854,  1855,   397,   397,  3104,     5,  1860,  1861,   538,   397,
    1981,   541,   587,   543,   434,   629,   631,  1990,   397,   397,
     434,   596,   587,   436,    26,   595,  1880,   518,   518,  1883,
    1884,   596,   631,   447,  1888,   397,  1890,    25,  1892,    25,
      25,   571,   462,  2642,   397,  2161,  2162,    25,   462,  2077,
     580,   397,   397,   397,  2653,   397,   397,   397,   397,  2184,
     480,   307,  1916,  2081,   376,  2176,   480,   558,   558,   397,
     397,   397,   629,  1927,   397,   436,   625,  2202,   464,   622,
     392,   625,     8,   432,   396,   484,   271,   720,   721,   465,
    2980,     5,   623,   601,   426,   623,   587,   587,   465,   331,
     617,  1955,     8,  1957,   664,   596,   596,   602,   664,  1963,
    1964,  1965,     5,     5,   389,  1969,  1970,  1971,  1972,   436,
     436,   436,   434,    30,   275,   436,  1980,   278,   436,   280,
     275,   595,  2103,   278,   349,   280,   584,     8,    14,  1993,
    2984,   581,   562,     5,    51,    52,   664,  2118,   562,   300,
     462,     5,  2006,   426,   664,   300,  2184,   436,   436,   310,
      20,    21,    26,  2017,    96,   310,  2020,    26,   480,    70,
     464,   625,   436,    80,  2202,  2029,   595,    30,   329,   436,
    1051,   436,   436,   816,   329,  2039,  2040,  2041,  3054,    20,
      21,   436,  2046,   826,  1065,   436,  3172,   436,    51,    52,
      26,   352,  1986,   426,  3180,   356,   464,   352,   628,     5,
     601,   356,   595,   625,   628,  1273,   436,   436,  3194,  2073,
     127,   128,     5,   130,   131,   436,   631,   436,   135,  2083,
    2084,  3090,  2086,   631,   667,  1106,   355,    97,    98,    99,
     100,   101,   102,   630,  2098,   152,   153,    18,   562,     5,
     562,  2105,  1123,  1124,  1125,    19,  1127,    26,  1129,  1130,
    2114,  2325,  2116,   170,  1135,  1136,    97,    98,    99,   100,
     101,   102,    30,    26,   127,   128,   157,   130,   131,  2395,
     223,    25,   135,  2137,   435,  2139,  2140,   584,  2142,   595,
     435,  2145,  2146,    51,    52,   628,   487,   487,     5,   152,
     153,   625,  1173,  3254,   552,   155,    26,  2161,  2162,   552,
     405,   326,  1183,    26,   552,   436,   628,   170,   397,   397,
     625,   631,  2176,   531,   397,   397,   436,  2181,  2182,  2183,
     625,   436,  2931,  2187,   241,   436,  1207,  1208,  2325,   972,
     669,  2195,  2941,   436,   436,  1216,   582,  3323,   464,   552,
       5,   622,     6,     7,     8,     9,    10,    11,    12,  2213,
       5,  1232,  1233,   631,     5,     5,   625,  2221,  2222,   127,
     128,  2225,   130,   131,     5,  2500,   488,   135,   585,   631,
       5,  2506,   436,   630,     8,  2239,   541,    26,    26,    70,
     330,  2045,     5,  2247,   152,   153,  2250,  2251,  2252,  2253,
    2254,  2526,     5,  2257,   397,   436,  2060,  2261,  2262,   436,
     365,  2265,   170,   602,   138,  2856,  2857,  2858,  1051,  2860,
    2861,  2862,  2863,  2864,  2865,   631,  2080,    14,  2869,   556,
     665,  2085,  2286,     5,  2288,  2289,    26,   552,  2292,  2293,
     105,  3331,   436,   625,   631,   436,   630,     5,   644,  3425,
     432,    26,   397,     5,   361,     5,   138,  3400,  3401,  3402,
    3403,  3404,  3405,   373,   624,  2319,   336,   432,  2322,   466,
    2324,  2125,  2500,    18,    19,    20,    21,   466,  2506,  2333,
     204,     8,   206,  2337,  2338,   436,  2340,   436,   436,   436,
     436,     5,  2346,   625,   436,  2349,  2350,   221,  2526,  2353,
    2354,   436,     5,   625,   411,   229,     8,   625,   361,   233,
       5,   559,   330,    25,  1385,   349,  1387,  1388,  1389,   349,
     244,  2375,   204,   464,   206,  1396,  1397,   625,   349,  1400,
     365,   436,  2386,  1404,   258,   431,   443,   464,     5,   221,
     426,  2395,     5,   656,    26,     5,     5,   229,  1419,    25,
      14,   233,    97,    98,    99,   100,   101,   102,   411,    14,
      38,  2415,    40,    41,    42,   472,  2770,  2771,  2772,  2773,
      26,   601,  3416,   601,  1207,  3174,   258,     5,   436,    24,
      25,    26,    27,   622,     5,   397,   397,  2441,   631,   397,
     397,   397,   397,  1464,  1244,   436,     6,   453,     7,   273,
     397,   625,     5,    26,    26,  3116,   631,    26,   625,     8,
     265,   397,    20,     5,    18,    19,    20,    21,  2734,   472,
    2736,   279,   572,     5,    69,     5,     5,  1498,   552,  2754,
    2755,  1264,  1265,   673,     5,  2489,   397,  2547,   577,   476,
    1273,   625,   397,   436,   631,  3535,     5,   559,   631,   304,
    2504,  1522,   215,   629,   397,  2719,   631,   631,  2512,  2513,
    2514,   476,   436,   436,     5,     5,  2684,   629,   323,    25,
      25,    25,  2326,  2527,   452,  2529,    25,    25,   301,  2533,
    2534,    26,    26,    26,    26,     5,   624,  2341,  2342,  2343,
    2344,    26,  2602,    97,    98,    99,   100,   101,   102,    26,
      26,   397,   397,   473,     5,   436,   397,   362,  2362,   556,
    2564,   245,    26,    25,   432,  3314,  2547,   397,  2572,   374,
    2574,  2692,   349,  2577,  2695,  2579,  2754,  2755,    20,   446,
     385,   144,  2719,  2704,  2705,   559,  2590,   436,   436,   436,
       5,  2595,  2596,  2597,   436,     5,   436,   436,   403,   436,
     195,    14,  2606,   215,   447,     5,   464,  2611,   413,    26,
     397,   397,   397,   397,    26,   379,  2620,  2421,    26,   397,
     574,  2602,   245,   436,   429,   397,   397,   397,   349,   464,
     246,   397,  2636,   436,  2638,   446,  1419,   552,  2642,   625,
      14,     7,  2646,   244,   244,    26,   397,   275,   631,  2653,
     278,   398,   280,   436,   397,   625,   581,   436,   397,   246,
      25,   397,   397,   432,   469,   397,   397,   397,     5,  3085,
     397,     5,   300,   625,  2678,   625,  2680,   397,  2682,  2683,
     625,  2699,   310,  2646,  3038,  3039,  3471,   492,  3042,   998,
    2411,  1503,  2126,  2697,    38,  2699,  2700,  2701,  2959,    40,
     561,   329,   507,  1486,  2350,  2678,  2356,   377,  2969,   514,
    2714,   145,   517,  2517,   149,  2519,   371,  2721,  2722,  2723,
     237,  1985,   378,   667,   352,  1986,   239,   550,   356,   611,
    2734,   406,  2736,   538,   568,  3461,   541,   405,   543,  1263,
    2045,   990,  2746,  2747,  3098,   438,   582,  3101,  2752,  1957,
     802,   580,  2219,  1241,  2953,  1963,  1964,   562,  2226,  2343,
    2764,  1969,  1970,  1971,  1972,  2085,  2770,  2771,  2772,  2773,
    2774,  2775,  1853,  2725,  3007,   580,  1856,  2437,  2153,  3512,
    2347,  2785,  2171,  1403,  3188,    25,  2790,    31,   121,    18,
      19,  3137,    31,  2131,  2137,   759,  1012,    26,    27,   354,
    1861,  2723,   933,  3134,  2140,  1208,   401,   435,  3287,   784,
    1397,  1462,  3478,  1387,  2818,  2819,  2953,  2721,  1161,  2896,
    3297,   416,  1485,   472,  2894,  2829,  2830,  2878,  2832,  2605,
    2337,  2835,  1362,  2837,  2023,    64,  2500,  2841,   433,  1860,
    1861,   436,  2000,  3487,  3111,  2530,  3372,    76,  2606,  2292,
    2904,  2257,  2194,  2818,   449,  2659,  3101,  2819,  2662,  3378,
    1880,  3154,  2577,  2984,  2611,    17,  3528,  2596,  3037,  2597,
    2765,  1237,  3109,  1964,  1963,   104,  2880,  1875,  3341,  3233,
    3036,  3235,  3233,  1233,  3252,  1848,  3241,  3241,  3242,  2893,
    3244,  3245,  3246,  3247,   489,  1916,  2684,  2322,  1402,  3253,
     559,  2905,  2906,  2907,    -1,  3171,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2720,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2931,    -1,    -1,
    2934,    -1,    -1,    -1,  2142,    -1,    -1,  2941,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2951,   543,    -1,
    2954,  2955,    -1,    -1,   133,  2959,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,  2969,   195,  2971,   197,    -1,
      -1,    -1,   151,    -1,    -1,    -1,  2980,   156,    -1,  3254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3351,    -1,   594,
    3354,  3355,  3356,  3357,    -1,    -1,    -1,    -1,  2029,    -1,
      -1,   606,   607,    -1,    -1,    -1,    -1,  3021,    -1,   614,
      -1,   200,   617,  3027,  3378,    -1,    -1,    -1,    -1,   208,
     625,  2239,  3036,    -1,  3038,  3039,    -1,    -1,  3042,  2247,
      -1,    -1,  2250,  2251,  2252,  2253,    -1,    -1,    -1,  3053,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,    25,    -1,    27,    -1,
      -1,    -1,  3076,    -1,  3078,    -1,  3254,  2098,  1861,    -1,
      -1,    -1,  3436,    -1,  2105,   264,  3090,    -1,    -1,    -1,
    3444,    -1,    51,    52,  3098,  2116,    -1,  3101,   327,    -1,
    3104,    -1,    -1,  3107,    -1,  3109,    -1,  3111,    -1,    -1,
     289,    -1,    -1,    -1,  1914,  1915,  2137,   296,    -1,   298,
      -1,  1921,    -1,  3337,    -1,  2146,    -1,    -1,    -1,   308,
    3134,    -1,    -1,   362,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   334,    -1,    -1,  2962,    -1,
    2181,  2182,  2183,   342,    -1,    -1,  2187,  3171,   127,   128,
    3174,   130,   131,    -1,  1957,    -1,   135,    -1,    -1,    -1,
    1963,  1964,    -1,   412,    -1,    -1,  1969,  1970,  1971,  1972,
      -1,  2995,  2213,   152,   153,    -1,    -1,    -1,    -1,   428,
    3337,   380,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,   170,    -1,  3217,    -1,    -1,    -1,    -1,  3222,    -1,
     449,  3225,    -1,    -1,    -1,    -1,    -1,   406,    -1,  3233,
      -1,  3235,    -1,    -1,    -1,    -1,   195,  3241,  3242,    -1,
    3244,  3245,  3246,  3247,    -1,    -1,  3250,    -1,  3252,  3253,
      -1,  3255,    -1,  3257,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   493,   444,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,
      -1,    -1,   241,  3287,    -1,    -1,    -1,    -1,  3292,   518,
    3294,    -1,    -1,    -1,    -1,  3416,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2324,  2325,    -1,  2514,    -1,  2108,    -1,
    3314,    -1,    -1,    -1,   543,    -1,    -1,  2338,    -1,  2340,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3331,  2349,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,  3341,    -1,    -1,
      -1,    -1,    -1,  3347,    -1,    -1,    -1,  3351,    -1,  2149,
    3354,  3355,  3356,  3357,  3358,    -1,  2564,    -1,   587,  2142,
      -1,    -1,    -1,    -1,    -1,  2386,    -1,   596,  3372,    -1,
      -1,  2579,  3176,    -1,  3378,   554,   555,   556,  3382,    20,
      -1,    -1,  2590,    24,    25,    26,    27,    -1,   567,    -1,
      -1,    -1,    -1,    -1,  2415,    -1,  3400,  3401,  3402,  3403,
    3404,  3405,    -1,    -1,  3208,    -1,    -1,    -1,  3412,    -1,
      -1,   127,   128,    -1,   130,   131,    -1,    -1,    -1,   135,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,  3436,    -1,    -1,    -1,   152,   153,    -1,    -1,
    3444,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   680,   681,    -1,   170,    -1,  2239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2247,    -1,    -1,  2250,  2251,  2252,
    2253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2262,
      -1,    -1,    -1,  3487,   443,  3489,    -1,    -1,    -1,    -1,
      -1,   670,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2286,    -1,    -1,    -1,    -1,    -1,    -1,
    2293,    -1,  2533,  2721,    15,    16,    17,    18,    19,    20,
      21,    22,  3526,  3527,  3528,   241,    -1,    -1,    -1,    -1,
      -1,  3535,    -1,  3537,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,  2752,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2596,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,  2405,  2406,  3411,    -1,    -1,
      39,    -1,   113,   114,   115,    -1,  2416,    -1,    -1,    -1,
      -1,  2642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2837,
      -1,    -1,  2653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2442,  2443,  2444,  2445,    -1,    -1,    -1,    -1,
    2450,  2451,  2452,  2453,    -1,    -1,    -1,  2457,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,  2697,    -1,  2699,    -1,
    2701,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      25,    -1,    -1,  2714,    -1,    -1,    -1,    -1,  2719,    -1,
      -1,  2722,  2723,  3507,    -1,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,  2746,  2747,   443,    -1,    -1,
      -1,  2514,    -1,    -1,    -1,  2535,  2536,    -1,    -1,    39,
      -1,    30,  2542,  2543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,
     401,    -1,    51,    52,  2785,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,   416,    65,    -1,    -1,    -1,
      -1,  2564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,  2577,   436,  2579,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,  2590,   449,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,   110,   111,    -1,    -1,   254,    -1,    -1,   257,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,   130,   131,    -1,    -1,    -1,   135,   182,   489,    -1,
    2633,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2880,
     501,    -1,    -1,   152,   153,    -1,    -1,    -1,  2668,  2669,
      -1,    -1,  2893,    -1,    -1,   376,    -1,  2677,    -1,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,  3107,
      -1,  3109,   543,    -1,    -1,    -1,    -1,    -1,  2708,  2709,
    2931,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2941,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,  2953,   434,    -1,  2735,    -1,  2737,  2721,    -1,
      -1,   582,    -1,    -1,    -1,    -1,    -1,   376,    39,    -1,
    2971,    -1,    -1,   594,   254,    -1,    -1,   257,    -1,  2980,
      -1,   462,    -1,   392,    -1,   606,   607,   396,    -1,  2752,
      -1,    -1,    -1,   614,   309,    -1,   617,    -1,    -1,   480,
     315,   316,   317,    -1,   625,    -1,    -1,  2770,  2771,  2772,
    2773,  2791,  2792,    -1,    -1,  2795,  2796,    -1,    -1,    -1,
     335,    -1,    -1,    -1,    -1,   434,    97,    98,    99,   100,
     101,   102,    -1,    -1,  3222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,  2818,  2819,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,  2829,  2830,    -1,  2832,
      -1,   480,  2835,    -1,  2837,    -1,    -1,    -1,  2841,    -1,
      -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2856,  2857,  2858,   376,  2860,  2861,  2862,
    2863,  2864,  2865,   372,  2884,    -1,  2869,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     399,    -1,   447,  3134,    -1,    -1,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,
      -1,    -1,    -1,   562,   434,    -1,    -1,    -1,    -1,  3347,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   234,  2952,  3174,    -1,   490,  2956,   240,    -1,   242,
      -1,    -1,   462,   254,    -1,    -1,   257,    -1,    -1,    -1,
     253,    -1,  2972,    -1,  3382,    -1,    -1,    -1,    -1,    -1,
     480,   470,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     525,  2991,    -1,    -1,    -1,    -1,  3217,  2980,   281,   628,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     545,   546,    -1,    -1,   297,    -1,    -1,    -1,    -1,   302,
      -1,   556,    -1,    -1,    -1,    -1,   561,    -1,    -1,    -1,
      -1,   314,    -1,    -1,    -1,     9,  3257,    -1,   321,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,  3038,  3039,    -1,    -1,  3042,
      -1,    -1,   562,    -1,    -1,   600,  3287,    -1,    -1,    -1,
      -1,  3292,    -1,  3294,   563,    -1,    -1,    -1,    -1,  3487,
      -1,   265,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      64,    -1,    -1,  3314,    -1,    69,    -1,   632,    -1,    -1,
      -1,   392,    76,    -1,    -1,   396,    -1,    -1,    -1,    -1,
    3331,    -1,    -1,    -1,    -1,  3098,  3337,    -1,  3101,    -1,
     304,  3104,    -1,    -1,  3107,    -1,  3109,    -1,   628,    -1,
     104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   323,
      -1,    18,    19,   434,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,   643,    -1,    -1,    -1,     9,    -1,
      -1,    -1,   651,    -1,    -1,    -1,    -1,    18,    19,    -1,
      -1,   462,    -1,    24,    25,    26,    27,    -1,   362,  3400,
    3401,  3402,  3403,  3404,  3405,    -1,    -1,    -1,    -1,   480,
     374,    -1,    69,   476,    -1,    -1,    -1,    -1,    -1,    -1,
     483,   385,    -1,    -1,    -1,    -1,  3206,    -1,    -1,  3209,
      -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    69,   403,
      -1,   195,   505,   197,    -1,    76,    -1,   510,    -1,   413,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3222,
      -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,  3235,   104,    -1,    -1,    -1,    -1,  3241,  3242,
      -1,  3244,  3245,  3246,  3247,    -1,    -1,    -1,    -1,    -1,
    3253,   562,  3255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   469,  3269,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,    -1,  3535,    -1,    -1,    -1,   195,    -1,
     294,    -1,    -1,   507,    -1,   299,    -1,    -1,    -1,    -1,
     514,    -1,    -1,   517,    -1,  3335,    -1,   628,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,    -1,  3331,    -1,
      -1,    -1,    -1,   327,   538,    -1,    -1,   541,    -1,   543,
      -1,    -1,    -1,    -1,  3347,    -1,    -1,    -1,  3351,    -1,
      -1,  3354,  3355,  3356,  3357,    -1,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,  3384,  3385,    -1,  3387,   362,  3389,
    3390,    -1,    -1,    -1,    -1,  3378,   580,    -1,    -1,  3382,
     374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,
      -1,    -1,    -1,    -1,   398,    -1,    -1,   401,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    -1,    -1,   412,    24,
      25,    26,    27,   294,   418,    -1,    -1,    -1,   299,    -1,
    3450,    -1,  3452,  3436,   428,    -1,    -1,    -1,    -1,   433,
      -1,  3444,   436,    -1,    -1,   439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   448,   449,   327,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,  3485,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3501,  3502,    -1,  3487,  3505,    -1,    -1,  3508,    -1,
      -1,   362,    -1,    -1,   488,   489,     9,    -1,    -1,   493,
      -1,    -1,    -1,   374,   401,    18,    19,   501,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,    -1,    -1,   512,   416,
      -1,    -1,   393,    -1,   518,    -1,    -1,   398,    -1,    -1,
     401,    -1,  3535,    -1,    -1,    -1,   433,    -1,    -1,   436,
      -1,   412,    -1,    -1,    -1,    -1,    -1,   418,    -1,   543,
      -1,    64,   449,    -1,    -1,    -1,    69,   428,    -1,    -1,
      -1,    -1,   433,    76,    -1,   436,    -1,    -1,   439,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   448,   449,   476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   104,   489,   587,    -1,    -1,    -1,    -1,    -1,    -1,
     594,    -1,   596,    -1,   501,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   606,   607,    -1,    -1,    -1,    -1,   489,    -1,
     614,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     501,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      -1,   512,    -1,   514,    -1,    -1,   543,   518,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,   195,    -1,   197,   582,   680,   681,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    -1,    -1,   594,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,   606,
     607,    -1,    -1,    -1,    -1,    -1,   587,   614,    -1,    -1,
     617,    -1,    -1,   594,    -1,   596,    -1,    -1,   625,    -1,
      -1,    -1,   103,    -1,   104,   606,   607,    -1,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,   294,    -1,    -1,    -1,    -1,   299,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,   401,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   680,
     681,   416,    -1,    -1,   327,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   433,    -1,
      -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,   362,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,   374,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     393,    -1,    -1,   488,   489,   398,    -1,    -1,   401,    -1,
      -1,    -1,    -1,    39,    -1,    -1,   501,    -1,    -1,   412,
      -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,
     433,    -1,    -1,   436,   294,    -1,   439,    -1,    -1,   299,
      -1,    -1,    -1,    -1,    -1,   448,   449,    -1,   543,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   327,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   337,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,   488,   489,   582,    -1,   350,
     493,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   501,   594,
      -1,    -1,   362,    -1,    -1,    -1,    -1,    -1,    -1,   512,
      -1,   606,   607,    -1,   374,   518,    -1,   254,    -1,   614,
     257,    -1,   617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     625,    -1,    -1,   393,    -1,    -1,    -1,    -1,   398,    -1,
     543,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   412,    -1,   415,    -1,    -1,    -1,   418,    -1,
      -1,   422,    -1,    -1,    -1,    -1,    -1,    -1,   428,    -1,
      -1,    -1,    -1,   433,    -1,    -1,   436,    -1,    -1,   439,
      -1,    -1,    -1,    -1,   587,    -1,    -1,    -1,   448,   449,
      -1,   594,    -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,
     461,    -1,    -1,   606,   607,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,   625,    -1,   485,    -1,    -1,    -1,    -1,   489,
      -1,    -1,    -1,   493,   495,   496,    -1,    -1,    -1,   376,
     501,   501,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     511,    -1,   512,    -1,    -1,   392,    -1,    -1,   518,   396,
     397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   533,    -1,    -1,   536,   537,   680,   681,    -1,
      -1,   542,    -1,   543,    -1,    -1,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,   434,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,   587,    -1,    -1,
      49,    -1,    -1,    -1,   594,    -1,   596,    -1,   599,    -1,
     376,    -1,    -1,   480,    -1,    -1,   606,   607,    67,   610,
      -1,    -1,    -1,    -1,   614,    -1,   392,    76,    -1,    -1,
     396,    -1,    -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,    -1,    -1,   113,   114,   115,   116,   434,    -1,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     680,   681,    -1,    -1,    -1,   562,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,   197,    -1,
      -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     279,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,   301,    -1,    -1,   304,   305,    -1,    -1,    -1,
     309,    -1,   628,    -1,    -1,    -1,   315,   316,    -1,    -1,
      -1,    -1,    -1,   322,   323,   324,   325,   326,   327,    -1,
      -1,    -1,   331,    -1,    -1,    -1,   335,    -1,   337,    -1,
      -1,    -1,    -1,    -1,    -1,   344,   345,   346,   347,    -1,
     349,   350,    -1,    -1,    -1,   354,   355,    -1,   357,   358,
     359,   360,   361,   362,   363,   364,    -1,    -1,    -1,    -1,
      -1,   370,   371,   372,    -1,   374,   375,    -1,    -1,    -1,
     379,   380,   381,   382,   383,   384,   385,   386,   387,    -1,
     389,    -1,    -1,    -1,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,    -1,   432,   433,    -1,    -1,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,    -1,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,   472,    -1,   474,   475,   476,   477,    -1,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,    -1,   516,   517,   518,
     519,   520,   521,    -1,    -1,   524,   525,    -1,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,    -1,    -1,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,    -1,
      -1,    -1,    -1,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   651,    -1,    -1,    -1,    -1,   656,    -1,    -1,
      -1,   660,    -1,    -1,   663,   664,   665,   666,    -1,    -1,
     669,   670,    -1,   672,   673,   674,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,
     109,   110,    -1,    -1,   113,   114,   115,   116,    -1,    -1,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,   188,
      -1,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,    -1,
      -1,    -1,    -1,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,    -1,
      18,    19,    20,    -1,    -1,    -1,    24,    25,    26,    27,
     279,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   294,   295,    -1,    -1,    -1,
      -1,    -1,   301,    -1,    -1,   304,   305,    -1,    -1,    -1,
     309,    -1,    -1,    -1,    -1,    -1,   315,   316,    -1,    -1,
      -1,    69,    -1,   322,   323,   324,   325,   326,   327,    -1,
      -1,    -1,   331,    -1,    -1,    -1,   335,    -1,   337,    -1,
      -1,    -1,    -1,    -1,    -1,   344,   345,   346,   347,    -1,
     349,   350,    -1,    -1,    -1,   354,   355,    -1,   357,   358,
     359,   360,   361,   362,   363,   364,    -1,    -1,    -1,    -1,
      -1,   370,   371,   372,    -1,   374,   375,    -1,    -1,    -1,
     379,   380,   381,   382,   383,   384,   385,   386,   387,    -1,
     389,    -1,    -1,    -1,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,    -1,   432,   433,    -1,    -1,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   195,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   464,   465,   466,   467,   468,
     469,   470,   471,   472,    -1,   474,   475,   476,   477,    -1,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,    -1,   516,   517,   518,
     519,   520,   521,    -1,    -1,   524,   525,    -1,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,    -1,    -1,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,    23,
      -1,    -1,    -1,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,   643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   651,   401,    -1,    -1,    -1,   656,    -1,    -1,
      -1,   660,    -1,    67,   663,   664,   665,   666,   416,    -1,
     669,   670,    -1,   672,   673,   674,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,   436,    -1,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,
      -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,    -1,    -1,
      -1,   489,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,   501,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,    -1,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    69,    -1,   543,    -1,    -1,    -1,    -1,
     204,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,    -1,   233,
      -1,    -1,    -1,    -1,   582,   239,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,   594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   258,    -1,    -1,    -1,   606,   607,
      -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,   617,
      -1,   275,    -1,    -1,   278,    -1,   280,   625,    -1,    -1,
      -1,    -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   300,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   310,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,   195,
      -1,    35,    36,    37,    -1,   329,   330,    -1,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    -1,
     344,    -1,    -1,    -1,    -1,    59,    -1,    -1,   352,    -1,
      -1,    -1,   356,    -1,    -1,    -1,    -1,    71,    72,    -1,
      74,   365,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,   132,    -1,
     134,   135,   136,   137,    -1,    -1,    -1,    -1,    -1,   143,
      -1,   435,   146,    -1,   148,   149,   150,    -1,   152,   153,
      -1,    -1,   446,    -1,   158,    -1,   160,   161,    -1,   163,
      -1,   165,   166,    -1,    -1,   169,   170,    -1,    -1,   173,
     174,   175,    -1,   177,   178,    -1,    -1,    -1,   182,   183,
     184,    -1,   186,    -1,    -1,    -1,   190,    -1,   192,   193,
      -1,    -1,   486,    -1,   198,    -1,    -1,    -1,   202,    -1,
      -1,   205,    -1,   207,    -1,   209,    -1,   211,    -1,   213,
     214,    -1,   216,   217,   218,    -1,    -1,    -1,   222,    -1,
     224,   225,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   235,   236,    -1,    -1,   401,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   248,    -1,    -1,   251,   252,    -1,
     416,   255,   256,    -1,   548,   259,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,   269,   270,   433,   272,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,   283,
     284,    -1,   286,   449,    -1,    -1,   290,   291,    -1,    -1,
     584,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   311,   312,   313,
      -1,    -1,    -1,    -1,    -1,   319,   320,    -1,    -1,    -1,
      -1,   325,   488,   489,   328,    -1,    -1,    -1,   332,   333,
      -1,    -1,    -1,    -1,    -1,   501,   630,    -1,    -1,   343,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     644,   645,   646,   647,   648,   649,   650,   361,   652,   653,
      -1,    -1,    -1,    -1,    -1,   369,    -1,    -1,    -1,    -1,
      -1,   375,    -1,    -1,    -1,   669,    -1,   543,    -1,    -1,
      -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   399,    -1,    -1,    -1,    -1,
      -1,    -1,   406,    -1,   408,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   417,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     606,   607,    -1,    -1,    -1,    -1,    -1,    -1,   614,    -1,
      -1,   617,   456,    -1,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,   499,    -1,    -1,    -1,   503,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   515,    -1,    -1,    -1,    -1,    -1,   521,   522,   523,
     524,    -1,    -1,    -1,   528,    -1,    -1,    -1,   532,    -1,
      -1,    -1,    -1,    -1,    -1,   539,   540,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,    -1,   553,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     564,    -1,   566,    -1,    -1,   569,    -1,    -1,    -1,    -1,
      -1,   575,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,   601,    -1,    -1,
     604,    -1,    -1,    -1,    -1,   609,    -1,    -1,   612,   613,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   627,    -1,    -1,    -1,     6,     7,     8,
     634,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   657,   658,   659,   660,   661,   662,   663,
      39,    -1,   666,    -1,   668,    -1,   670,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,     6,     7,
       8,    -1,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    97,
      98,    99,   100,   101,   102,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   257,    -1,    -1,    -1,    -1,   376,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,   396,   397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   434,    -1,    97,    98,    99,
     100,   101,   102,   392,    -1,    -1,    -1,   396,   397,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   480,    -1,   257,    -1,   434,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,   397,   462,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,   397,
       6,     7,     8,   562,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,   462,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,   254,   480,   434,   257,    -1,    -1,
      -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,   392,    -1,
      -1,    -1,   396,   397,   462,    -1,    -1,    -1,    -1,   628,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
     434,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,   628,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,   462,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    39,    -1,
      -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,   396,   397,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    97,    98,    99,   100,
     101,   102,    39,    -1,    -1,    -1,    -1,    -1,   562,    -1,
     628,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,
     480,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,   628,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
     376,    -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
     396,   397,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     7,     8,   462,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,
      -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      39,    -1,   254,   434,    -1,   257,   562,    -1,    -1,   376,
     113,   114,   115,    -1,    -1,    -1,   447,    -1,    -1,    -1,
      -1,    -1,    -1,     9,    -1,   392,    -1,    -1,    -1,   396,
      -1,   462,    18,    19,    20,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   434,    -1,    -1,
      -1,    -1,   628,    -1,   113,   114,   115,   376,    -1,    -1,
     447,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,   462,    -1,   396,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,    39,    -1,    -1,
      -1,   562,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,   396,    -1,    -1,    -1,   447,    -1,
      -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,   480,   434,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    39,    -1,    -1,   562,    -1,   628,    -1,    -1,
      -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,   195,
     462,    -1,    -1,    -1,    -1,   254,    -1,    -1,   257,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    18,
      19,    20,    -1,    -1,    -1,    24,    25,    26,    27,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      39,   628,    -1,   562,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,   376,    -1,    18,    19,    20,    -1,    -1,
      69,    24,    25,    26,    27,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
     562,    -1,    -1,   299,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    39,    -1,    69,    -1,    -1,   628,
      -1,   434,    -1,    -1,   113,   114,   115,   376,    -1,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,    -1,   396,    -1,   462,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,   628,   480,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    17,
      18,    19,    20,    21,    22,   434,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,   195,   254,    -1,    -1,
     257,    39,    69,    -1,    -1,   401,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,    18,    19,
     416,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,
     436,    -1,   195,    -1,    -1,    -1,    -1,    -1,    -1,   562,
      -1,    -1,   448,   449,   376,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   254,    -1,    -1,   257,    69,
     392,    -1,    -1,    -1,   396,   113,   114,   115,    -1,    -1,
     476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   489,    -1,    -1,    -1,    -1,    -1,    -1,
     299,    18,    19,    -1,    -1,   501,    -1,    24,    25,    26,
      27,    -1,   434,   562,    -1,   628,    -1,    -1,    -1,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   254,
      -1,    -1,   257,    -1,    -1,   392,    -1,    -1,    -1,   396,
     462,    -1,    -1,    -1,    -1,    -1,   299,   543,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,   628,
      -1,    -1,    -1,    -1,    -1,    -1,   582,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,    -1,    -1,   594,    -1,
      -1,    -1,   401,   392,    -1,   462,    -1,   396,    -1,    -1,
     606,   607,    -1,    -1,    -1,    -1,   254,   416,   614,   257,
      -1,   617,    -1,   480,    -1,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,    -1,   433,    -1,    -1,   436,    -1,    -1,
     562,    -1,    -1,    -1,    -1,   434,    -1,    -1,   401,   448,
     449,   376,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,    -1,   416,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,    -1,   462,    -1,    -1,    -1,    -1,   195,    -1,
     433,    -1,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
     489,   480,    -1,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,    -1,   501,    -1,    -1,   562,   628,    -1,    -1,   434,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   401,    -1,   489,   462,   376,    -1,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,   501,   416,
      -1,    -1,    -1,    -1,   392,   480,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,   436,
      -1,   628,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,   582,    -1,    -1,    -1,    -1,    -1,    -1,
     543,    -1,    -1,    -1,    -1,   594,   434,    -1,    -1,    -1,
      -1,   401,    -1,    -1,    -1,    -1,    -1,   606,   607,    -1,
      -1,    -1,    -1,    -1,    -1,   614,   416,    -1,   617,    -1,
      -1,    -1,   489,    -1,   462,    -1,   625,    -1,    -1,   582,
      -1,    -1,    -1,   433,   501,    -1,   436,   562,    -1,   628,
      -1,   594,   480,    -1,    -1,    -1,    -1,    -1,    -1,   449,
      -1,    -1,    -1,   606,   607,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,   617,    78,    79,    -1,    81,    82,
      83,    -1,   625,    -1,    -1,    -1,   543,    -1,    44,    45,
      46,    47,    48,    49,   401,    -1,    -1,    -1,   488,   489,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,   501,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,   433,    -1,    -1,   436,
      -1,    -1,    -1,    -1,   562,    -1,    -1,   594,    -1,    -1,
     304,    -1,   449,    -1,    -1,    -1,    -1,   103,    -1,   606,
     607,    -1,    -1,   543,    -1,    -1,    -1,   614,    -1,   323,
     617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,
      -1,    -1,    -1,    -1,    -1,   339,    -1,    -1,   181,    -1,
      -1,    -1,   489,    -1,    -1,    -1,   189,    -1,    -1,    -1,
      -1,    -1,   582,    -1,   501,    -1,    -1,    -1,   362,    -1,
     628,    -1,    -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,
     374,    -1,    -1,    -1,    -1,    -1,   606,   607,    -1,    -1,
     223,   385,    -1,    -1,   614,    -1,    -1,   617,    -1,   232,
      -1,    -1,    -1,    -1,    -1,   625,   543,    -1,    -1,   403,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   413,
      -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,   261,   262,
      -1,    -1,    -1,    -1,    -1,   429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,
     607,    -1,    -1,   306,    -1,   469,    -1,   614,   264,    -1,
     617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,
      -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   298,   507,    -1,   348,    -1,    -1,    -1,    -1,
     514,    -1,    -1,   517,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   538,    -1,    -1,   541,   334,   543,
      -1,   337,    -1,    -1,    -1,    -1,   342,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,   562,    -1,
      -1,    -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   622,   415,
      -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   437,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,
     496,    -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   511,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,
     536,   537,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
      -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   608,    -1,   610
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    51,    52,    80,   127,   128,   130,   131,   135,
     152,   153,   170,   241,   361,   411,   443,   472,   740,   768,
     769,   821,   992,  1045,  1047,  1048,  1049,  1054,  1056,  1069,
    1070,  1071,  1072,  1073,  1495,    28,    29,   741,   742,   743,
     744,   745,    27,   957,  1514,   360,   539,   553,   578,   626,
    1496,  1496,  1496,  1496,  1496,  1496,  1496,  1496,   957,    25,
     957,  1410,  1074,   770,  1410,   769,  1495,     0,  1046,  1049,
    1054,  1072,  1495,    31,   743,   745,   957,  1498,   595,   957,
    1497,   631,   822,   617,    25,   195,   767,   768,   945,   957,
     962,  1075,  1110,  1111,  1112,  1113,  1114,  1118,   358,   772,
     773,   774,   775,   778,   779,    60,    65,   110,   111,   118,
     372,   399,   470,   563,   643,   651,   740,   746,   917,   991,
    1050,  1051,  1053,  1057,  1058,  1064,  1076,  1097,  1230,  1240,
    1495,   957,  1497,   622,   957,  1113,   247,   463,   464,  1120,
      20,   957,  1117,   625,   773,     5,   771,   358,   957,     5,
     797,   799,   800,   957,  1241,   957,   957,  1231,  1065,   957,
     957,  1053,  1059,   265,   304,   323,   362,   374,   385,   403,
     413,   429,   469,   492,   507,   514,   517,   538,   541,   543,
     562,   580,   823,   824,   825,   828,    25,  1110,  1116,    18,
      19,    26,    64,    76,   104,   197,   294,   327,   362,   374,
     412,   428,   436,   449,   493,   518,   543,   587,   596,   680,
     681,   690,   692,   883,   888,   899,   901,   957,  1110,  1121,
    1122,   464,    14,   820,   775,   527,  1217,   776,   773,   778,
      32,    34,    84,    85,    94,   265,   304,   323,   339,   362,
     374,   385,   403,   413,   429,   469,   492,   507,   514,   517,
     538,   541,   543,   562,   580,   622,   782,   791,   802,   803,
     957,   436,   117,   957,   767,   918,  1098,   957,   830,   541,
     780,   806,   808,   809,   807,   816,   817,   436,   436,   829,
     464,   436,   436,   773,   804,   431,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   690,   436,   764,     9,
      18,    19,    24,    25,    26,    69,   299,   393,   398,   401,
     418,   433,   436,   439,   448,   489,   501,   512,   543,   594,
     606,   607,   614,   625,   857,   865,   866,   867,   868,   869,
     870,   871,   899,   900,   902,   963,  1110,  1220,  1402,   436,
     436,   436,   436,   436,   436,    18,    19,    20,    21,    22,
     691,    26,   436,   526,     5,   432,  1121,    25,    26,   957,
     963,    19,    25,    26,   777,   963,   675,   676,   677,   781,
     793,   780,   794,   806,   807,   436,   436,   792,   464,   436,
     436,   804,   773,   801,   436,    26,   957,   436,  1066,   767,
     767,   436,   957,   436,   463,   786,   631,   371,   459,   475,
     518,   558,   587,   596,   810,   631,   371,   459,   475,   518,
     558,   587,   596,   818,    26,    26,   831,   832,   833,   834,
     957,    26,   789,   790,    26,    26,   625,   672,   949,   957,
    1505,   949,   949,  1505,  1505,   857,    25,    26,    19,    24,
      25,    26,   903,   904,   905,   906,  1505,   857,   397,   857,
     857,   857,   857,   531,  1237,   436,   436,   857,   371,   459,
     475,   518,   558,   587,   596,  1405,  1406,   436,   857,   857,
     436,   436,   872,   436,   436,   436,   436,    26,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    39,    97,    98,    99,   100,   101,
     102,   113,   114,   115,   254,   257,   376,   392,   396,   434,
     462,   480,   562,   628,   763,   858,   873,   875,   876,   877,
     878,   879,   880,   881,    26,   963,   426,   891,   889,   895,
     893,  1110,  1110,   690,   884,   957,  1122,   464,   432,    26,
     784,   773,   786,   773,    26,    26,   772,   789,    26,    26,
     625,    63,   798,  1242,   397,   436,  1232,  1515,  1516,  1517,
    1518,  1519,   919,  1099,  1060,   625,    26,   811,   812,   436,
     813,   818,   819,   813,   436,   814,     5,   397,     5,   397,
       5,   288,     5,   823,   432,     5,     5,   397,   397,   773,
     805,   436,   464,   625,     5,   397,   397,   397,   397,   397,
     397,   397,   397,   595,   904,    19,    26,   595,   397,   397,
     397,     5,   765,   857,   476,  1426,   857,   436,   631,    20,
     397,  1426,    20,  1220,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   857,   857,   436,   857,   857,
     436,  1110,   857,   857,   857,   857,   397,     5,   720,   721,
     722,   857,   436,  1121,   464,   629,   625,    26,   263,     5,
     397,     5,   397,   288,   432,     5,   397,   397,   805,   957,
    1127,  1128,  1130,  1077,  1127,   366,  1516,  1217,    35,    36,
      37,    43,    50,    59,    71,    72,    74,    88,    95,   106,
     107,   108,   122,   124,   125,   126,   129,   132,   134,   136,
     137,   143,   146,   148,   149,   150,   158,   160,   161,   163,
     165,   166,   169,   173,   174,   175,   177,   178,   182,   183,
     184,   186,   190,   192,   193,   198,   202,   205,   207,   209,
     211,   213,   214,   216,   217,   218,   222,   224,   225,   227,
     235,   236,   248,   251,   252,   255,   256,   259,   260,   268,
     269,   270,   272,   282,   283,   284,   286,   290,   291,   295,
     303,   311,   312,   313,   319,   320,   325,   328,   332,   333,
     343,   361,   369,   375,   386,   406,   408,   409,   417,   456,
     467,   474,   498,   499,   503,   515,   521,   522,   523,   524,
     528,   532,   539,   540,   551,   553,   564,   566,   569,   575,
     601,   604,   609,   612,   613,   627,   634,   657,   658,   659,
     660,   661,   662,   663,   666,   668,   670,   683,   684,   685,
     686,   703,   725,   739,   740,   746,   747,   766,   836,   837,
     838,   839,   850,   851,   852,   853,   854,   855,   856,   908,
     912,   943,   964,   965,   968,   969,   970,   971,   984,   993,
    1014,  1015,  1017,  1021,  1036,  1037,  1041,  1042,  1043,  1044,
    1052,  1067,  1080,  1091,  1092,  1093,  1104,  1107,  1143,  1146,
    1148,  1154,  1155,  1158,  1161,  1164,  1166,  1168,  1171,  1178,
    1183,  1187,  1188,  1189,  1201,  1202,  1205,  1211,  1212,  1213,
    1238,  1253,  1254,  1255,  1256,  1257,  1262,  1268,  1269,  1287,
    1290,  1320,  1322,  1411,  1412,  1443,  1444,  1451,  1462,  1486,
    1495,  1499,  1504,  1506,  1508,  1512,  1513,  1520,   740,  1055,
    1495,   630,   653,  1100,  1101,  1127,    20,   397,   431,   787,
     810,    26,   815,    26,    26,    26,   832,   834,   826,   790,
      26,   957,   690,    20,   672,   957,   949,   897,  1406,   897,
      26,    26,   595,    24,    26,   807,   898,   808,   397,   364,
     481,   591,  1434,   397,   397,    26,  1406,   397,   397,   397,
     397,   397,   397,   397,   447,   447,   447,   882,  1426,   447,
     882,  1426,   892,   890,   896,   894,    26,   885,     5,   886,
     432,  1121,   797,    20,   787,   436,    26,    26,   783,    26,
     625,   397,     5,  1127,   397,  1110,  1110,  1110,    25,  1110,
    1165,   957,   354,   958,   959,  1514,   957,   957,  1185,   952,
     958,   952,    25,   195,   957,  1119,  1490,  1491,  1492,   957,
    1510,   957,  1264,  1265,   957,    26,   687,  1110,  1260,   952,
    1185,   882,    26,   963,  1225,  1226,  1225,   857,   864,  1289,
     859,   882,   958,  1452,  1452,   840,  1185,   952,  1258,  1110,
     954,   958,   864,  1452,  1110,  1185,  1110,  1288,  1452,    25,
     591,  1094,  1095,  1110,   952,   952,  1094,   953,   958,   957,
    1095,   952,  1452,   952,   954,  1110,  1141,  1142,   950,   958,
     954,   380,   567,   949,  1016,   957,   748,   955,   958,    25,
    1321,  1490,   882,  1141,   882,   958,  1167,   913,   133,   142,
     151,   156,   200,   208,   264,   289,   296,   298,   308,   334,
     342,   380,   406,   444,   455,   554,   555,   556,   567,   670,
    1030,  1162,  1163,  1110,   863,   864,  1177,  1505,  1505,   951,
     958,   882,  1165,  1239,  1110,  1216,    25,  1110,  1446,   864,
    1207,  1208,  1209,  1218,  1219,   864,  1500,   109,   159,   197,
     294,   370,   412,   479,   704,   888,   957,  1110,  1248,   727,
     864,   950,  1497,  1081,   864,   950,    26,  1110,  1038,   950,
     864,  1463,   864,  1225,   957,   966,   967,   954,   966,  1505,
     954,   966,  1505,   972,   966,    25,    26,   390,   492,   963,
    1019,  1110,  1129,  1131,    70,   279,   349,   395,   574,   654,
     655,   656,   665,   694,   974,   976,   978,   980,   982,  1105,
    1106,  1109,   340,   351,   404,   419,   508,  1323,   645,   646,
     921,   922,   923,   957,  1102,   652,  1101,   397,   307,   397,
     397,   397,   397,   629,     5,   397,   397,   432,   436,   631,
     397,    26,   595,   631,    18,    19,    20,    25,    26,    69,
     401,   416,   433,   436,   449,   489,   501,   543,   582,   594,
     606,   607,   614,   617,   957,   963,  1401,  1403,  1433,  1435,
    1436,  1438,  1439,  1440,  1491,  1494,  1237,   397,  1237,  1237,
    1237,  1237,  1237,  1237,    25,    25,    25,   857,   874,   397,
      25,   874,   397,   397,   397,   397,   397,   397,   397,   722,
     720,   432,   307,   773,   795,   796,   397,   397,   629,   397,
     957,  1243,  1130,   397,  1233,    61,    62,    89,    90,    91,
     460,   547,   590,  1270,  1271,  1272,  1275,  1278,  1281,  1282,
    1283,  1284,   436,   625,  1492,  1120,   622,  1159,   625,     8,
     544,   593,     5,   397,   432,    25,   957,  1395,   484,  1186,
    1129,   113,   114,   115,   488,   860,   861,   864,  1110,  1136,
    1395,   693,   694,   843,   271,    92,    93,   631,   465,     5,
     624,   631,   623,   623,  1144,   601,   426,     5,   562,   994,
     465,   664,  1502,   664,   390,   750,  1110,   552,   623,  1149,
    1150,  1151,   331,  1319,   617,   862,   864,   562,   862,     8,
     951,    26,   506,   560,   674,   944,  1110,   944,   944,   944,
      25,   182,   309,   315,   316,   317,   335,   444,   447,   455,
     490,   525,   545,   546,   556,   561,   600,   632,  1034,  1035,
     944,   944,   602,  1031,   694,  1031,  1031,   945,   945,  1031,
    1031,   694,     5,   338,   391,     5,   693,    86,    87,   545,
     632,  1022,   667,  1503,   863,   618,   619,   620,   621,  1215,
    1217,   389,  1252,  1217,  1209,     5,   623,  1210,   864,   436,
     436,   436,   436,    25,   723,   957,   436,  1446,   349,   436,
     526,   595,   584,   728,   735,   726,    25,  1096,  1110,  1203,
       8,  1206,    14,   957,  1115,  1123,  1124,  1126,  1134,  1135,
    1179,   167,   349,   550,   583,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    18,    19,    20,    21,    22,    23,
      33,    49,    67,    76,    94,    96,   104,   109,   110,   113,
     114,   115,   116,   119,   120,   159,   182,   188,   195,   197,
     203,   228,   266,   279,   285,   294,   295,   301,   304,   305,
     309,   315,   316,   322,   323,   324,   325,   326,   327,   331,
     335,   337,   344,   345,   346,   347,   349,   350,   354,   355,
     357,   358,   359,   360,   361,   362,   363,   364,   370,   371,
     372,   374,   375,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   389,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   432,   433,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   474,   475,   476,
     477,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   516,   517,   518,
     519,   520,   521,   524,   525,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   591,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   643,   651,   656,   660,   663,
     664,   665,   666,   669,   670,   672,   673,   674,  1464,  1465,
    1466,  1468,   581,     5,   664,   664,   862,  1129,  1136,  1018,
     426,     5,   155,   998,   436,  1110,   862,   436,    26,    26,
      70,  1108,    25,  1110,  1450,  1450,   958,  1303,  1167,   951,
     123,   226,   234,   240,   242,   253,   281,   297,   302,   314,
     321,   476,   483,   505,   510,  1291,  1292,  1300,  1310,  1311,
    1317,  1318,  1324,  1325,  1334,  1353,  1357,  1422,  1423,  1453,
    1454,  1457,  1458,  1470,   924,   925,    96,   920,   931,   932,
     923,  1103,  1515,  1061,   464,   823,   790,   625,   957,   371,
     459,   475,   518,   558,   587,   596,  1407,   897,   595,    24,
      26,   811,  1439,  1439,   371,   459,   475,   518,   558,   587,
     596,  1404,  1408,   476,  1438,   436,   436,   436,   436,   436,
     436,   436,   957,   436,     5,   552,  1362,  1367,   957,    18,
      19,    20,    21,    97,    98,    99,   100,   101,   102,  1460,
     426,     5,   397,   397,   887,   464,     5,   397,   797,   767,
    1078,   767,   162,   301,   378,   436,   481,   497,  1340,  1352,
     436,   957,  1286,    26,   250,   263,   436,   481,   497,   957,
    1267,  1280,  1338,  1339,  1344,  1346,  1348,   436,   957,  1277,
     436,  1267,  1273,     5,    25,   960,  1113,  1492,  1490,   582,
     622,  1160,    20,   957,  1140,  1493,   957,  1511,  1265,   601,
     625,   595,   436,   436,   843,     5,   631,   436,  1490,    25,
     962,  1184,  1184,  1446,  1094,   864,   864,   864,   946,   947,
     436,  1110,  1142,   804,   995,   996,   631,  1446,  1505,  1503,
    1016,  1110,   749,   630,   864,   355,  1153,   562,  1152,   957,
       5,  1487,    73,    75,    77,   623,   631,   835,  1129,   914,
      18,    19,   436,  1032,  1034,  1163,   945,   864,   349,   601,
      26,    26,   693,   157,  1214,   223,  1219,  1225,  1501,   957,
      25,   907,   949,  1505,   595,   949,   628,  1110,   708,   957,
     957,   864,   344,   731,   735,   584,   729,   737,    23,   239,
    1083,  1087,   487,   882,   487,  1204,   864,   463,  1120,   625,
       5,  1039,   552,  1180,  1110,  1467,  1469,   194,  1465,   985,
     967,  1505,  1505,   977,   978,   998,   998,    38,    40,    41,
      42,   275,   278,   280,   300,   310,   329,   352,   356,   435,
     997,   999,  1000,  1026,  1110,  1131,   552,   695,    26,   405,
     983,   326,  1445,  1445,   140,   141,   442,   552,   957,  1354,
    1355,  1396,   804,  1395,  1395,  1293,   804,   957,  1455,  1455,
    1434,  1395,  1301,   172,   444,   455,   476,   483,  1327,  1328,
    1329,  1515,  1515,   390,   933,  1110,   647,   648,   926,   927,
     928,   486,   630,   649,   650,   669,   936,   937,  1515,   767,
      26,   788,    20,   957,   397,   436,    24,    26,   631,  1434,
     397,   401,  1461,  1494,   364,   481,   591,  1386,  1438,  1441,
    1386,  1386,  1386,  1386,   625,  1441,  1436,   520,  1363,  1364,
    1365,  1395,   531,  1361,  1368,   336,   519,   530,  1312,  1429,
    1438,  1438,  1438,  1438,  1491,   857,   397,   788,   796,  1244,
     767,  1234,  1342,  1395,  1285,  1352,   436,  1285,   436,   436,
    1279,  1280,   436,   436,    68,   304,   362,   374,   385,   403,
     413,   416,   429,   477,   507,   517,   538,   541,   543,   571,
     580,  1387,  1388,  1389,  1391,  1276,  1277,  1273,  1274,   669,
    1271,   397,   625,  1446,   582,   464,   552,  1509,   688,   689,
     957,   957,   957,  1261,   882,   860,   957,  1259,   622,  1156,
     631,     5,     5,     5,   585,   864,   625,     5,   488,   631,
     630,   168,   171,   275,   278,   751,   754,   755,  1026,   752,
     753,   957,   436,   958,   654,   655,  1157,   864,   804,  1488,
    1489,   957,   957,   947,   948,   514,  1505,   843,     8,   916,
      26,    26,  1033,  1034,  1110,   541,  1172,    70,   857,  1217,
      26,  1110,  1515,     5,     5,     5,   397,   397,   724,   957,
     397,  1446,   720,   436,   436,   736,   732,   365,   730,   864,
     344,   733,   737,   602,  1028,  1088,  1084,   367,  1082,  1083,
     862,   631,  1116,    20,   957,  1125,  1135,    14,   488,  1181,
    1182,  1438,  1494,  1110,  1132,  1133,  1515,   979,   980,   556,
     956,   552,  1009,  1008,  1011,  1010,   949,  1012,   949,  1013,
    1007,  1006,  1004,  1003,  1027,   329,  1000,  1005,  1505,    44,
      45,    46,    47,    48,    49,   103,   337,   350,   415,   422,
     461,   485,   495,   496,   501,   511,   533,   536,   537,   542,
     599,   610,   696,   697,  1024,  1025,     5,    26,  1446,   253,
    1110,   476,  1427,  1428,  1446,  1167,  1421,  1423,   105,   105,
     601,  1165,  1356,  1357,   436,  1335,   154,  1368,  1395,   179,
     276,  1459,   625,   631,  1424,  1471,   346,   355,   380,   383,
     401,   506,   560,   567,   951,  1304,  1309,   436,  1330,   630,
       5,   935,  1110,     5,   552,   929,   930,   644,   928,   934,
     957,   934,   938,   939,   934,   329,   937,  1062,   432,    26,
     371,   459,   475,   518,   558,   587,   596,  1409,  1435,     5,
    1408,   397,     5,  1438,     5,   397,  1438,  1438,  1438,  1438,
     957,   397,   436,  1365,     5,   957,  1400,     9,   299,   436,
     448,  1371,  1372,  1373,  1374,  1375,  1379,  1383,  1385,  1438,
     373,  1359,  1369,   957,  1430,   624,  1386,   336,   432,   466,
    1227,  1247,  1079,   466,  1190,  1221,   436,     5,   397,  1371,
     397,   617,   957,  1341,  1343,  1395,  1398,  1399,  1345,  1398,
       5,   397,  1345,  1371,  1408,  1408,   436,   436,   436,   436,
     436,   436,   212,   405,  1347,  1349,     5,   397,     5,   397,
     957,  1493,     8,  1446,  1121,   864,     5,  1266,  1267,   882,
    1068,   625,  1266,   582,  1446,  1446,   864,   864,   946,   514,
     864,  1507,     5,    20,  1398,   996,  1446,   752,   760,   759,
     761,   957,   961,   762,   961,   196,   755,   758,     5,   998,
     625,   864,     8,   625,     5,   957,   882,   559,  1307,     5,
     397,  1110,     5,   330,    25,  1249,   949,   349,   349,   464,
     625,   349,   436,   709,   713,   706,  1515,  1515,   738,   734,
     730,  1029,    25,   956,  1089,  1110,  1515,   864,   431,   464,
     882,     5,   426,     5,   986,   981,   982,    26,   693,   957,
    1515,  1515,  1515,  1515,     5,  1001,     5,  1002,  1515,  1515,
    1515,  1515,  1032,  1515,   956,    25,    14,    14,     5,   397,
      26,  1395,  1434,  1415,   601,   601,  1292,  1420,  1421,  1357,
    1336,  1398,   622,   951,   436,  1296,   957,  1456,  1455,  1435,
      53,    54,    55,    56,    57,   589,  1474,   864,   864,  1302,
     951,  1331,  1398,  1395,  1329,     5,  1110,   934,  1515,  1515,
       5,   941,   942,  1515,  1515,   940,  1055,   827,   397,  1367,
    1408,   631,  1408,   397,  1438,   397,   397,   397,   397,  1364,
    1366,  1364,  1374,   436,  1433,  1371,  1438,  1433,     6,     7,
       9,    10,    12,    13,    14,    15,    16,    17,   257,   376,
     377,   434,   562,   628,   678,   679,  1382,  1384,  1360,  1437,
    1438,   453,  1358,  1370,   273,  1263,    26,  1313,  1314,  1315,
    1398,  1427,  1430,   785,    78,    79,    81,    82,    83,   181,
     189,   223,   232,   261,   262,   306,   348,   405,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,  1224,  1228,
     139,   519,  1229,  1245,  1055,   164,   180,   181,   189,   223,
     232,   261,   306,   348,  1222,  1223,  1235,  1229,  1343,  1352,
     397,  1399,   464,  1397,   397,     5,   625,     5,   397,  1280,
     397,   397,   631,   436,   631,    26,  1393,  1393,    26,  1393,
    1393,    26,  1392,    25,  1401,  1350,  1351,  1352,  1277,  1273,
    1446,     8,   432,   689,     5,   397,   862,   397,    20,   397,
    1446,     5,   864,   572,   279,   698,   699,   864,   998,  1515,
    1515,     5,   756,   464,   625,     5,   757,  1515,   753,   552,
      20,   957,     5,   957,  1147,    20,  1398,  1489,   395,   664,
     862,  1308,   915,  1034,   673,  1170,   857,     5,   720,  1110,
     705,   687,   957,  1110,   711,   397,   720,   720,  1515,  1515,
    1032,  1086,    25,  1090,  1110,   577,   911,  1121,   488,   863,
    1040,  1182,  1110,  1133,    67,   548,   987,   973,   974,   625,
     949,  1515,   949,  1515,   693,    26,  1110,    26,  1110,   697,
     397,   436,  1447,  1435,  1421,  1421,  1413,     5,   397,   476,
    1432,  1297,  1398,   484,  1294,  1432,   631,  1425,    18,    19,
      69,   433,   436,   449,   488,   489,   501,   543,   582,   594,
     606,   607,   614,   617,   957,  1401,  1433,  1479,  1480,  1481,
    1482,  1483,  1484,  1494,  1479,  1479,  1479,  1398,  1476,  1478,
    1475,  1476,  1477,  1472,   559,  1305,     5,   397,   631,  1110,
     957,  1515,  1515,  1515,  1515,   629,   397,   631,  1409,   631,
       5,   397,   397,  1372,  1373,  1377,  1439,  1377,   436,  1433,
    1377,   436,  1433,  1377,    10,   254,   392,   394,  1438,     5,
    1371,     5,   544,   593,  1316,  1263,   629,  1225,  1225,  1225,
      25,  1225,  1225,  1225,  1225,  1225,  1225,    25,    25,  1225,
    1228,  1110,  1137,  1138,   624,   452,  1191,  1515,    25,    25,
      26,    26,    26,    26,    26,    25,  1110,  1223,  1191,   397,
      26,  1340,  1398,    20,   957,  1398,  1409,    26,  1409,     5,
    1390,  1390,     5,   397,   397,  1390,   397,  1352,  1446,  1267,
    1263,   473,   842,     5,   379,  1446,     5,   436,   397,   556,
    1023,   961,  1515,   690,    20,   957,   961,  1515,  1505,   864,
    1505,  1132,  1515,    26,   956,    25,  1250,  1129,   432,   720,
     710,   714,   397,  1515,   956,   864,   909,   432,   989,   988,
     446,   975,   976,    20,   957,  1448,  1449,   559,  1431,  1416,
    1414,  1398,  1434,   144,  1337,     5,   397,  1295,  1456,  1431,
    1482,  1482,  1481,   436,   436,   436,   436,   436,   436,   436,
     957,   436,     5,   397,    18,    19,    20,    21,  1460,   397,
       5,   397,     5,    14,   154,   531,  1473,  1306,  1398,   468,
    1332,  1333,  1396,   215,  1063,   823,  1409,  1409,  1364,   447,
    1376,  1376,  1380,  1381,  1401,  1494,  1376,  1380,  1376,  1377,
    1438,  1437,  1314,   797,   544,   593,  1139,     5,  1137,    66,
     138,   204,   206,   221,   229,   233,   258,  1192,  1193,  1246,
    1063,  1236,     5,   432,  1397,   397,    26,  1394,   397,   397,
      26,   397,   949,   693,   379,  1446,   864,   700,   574,  1145,
      26,   693,   432,  1023,   397,   245,   693,   397,   397,   436,
     712,   349,   718,   397,   707,  1085,  1515,   464,   864,  1515,
     956,     5,   397,  1132,  1367,  1435,  1398,   436,  1367,   397,
    1461,  1386,  1481,  1485,  1386,  1386,  1386,  1386,   625,  1485,
    1480,  1481,  1481,  1481,  1481,  1476,    14,  1477,  1480,   951,
    1371,  1132,     5,   145,  1326,  1378,  1401,  1442,     5,   397,
     397,  1376,     7,  1138,  1194,  1195,  1110,  1197,  1110,  1196,
    1198,  1193,   244,   244,    26,   631,   397,   841,  1446,   398,
     208,   264,   289,   298,   334,   342,   437,   608,   697,   701,
     702,   436,   625,   693,  1169,  1251,   715,   397,  1129,   718,
     718,  1515,   910,  1121,   581,  1020,  1449,  1429,  1367,   488,
    1298,  1299,  1438,  1429,   397,  1481,     5,   397,  1481,  1481,
    1481,  1481,   957,   397,   436,  1333,  1381,  1438,  1515,  1515,
    1199,  1515,  1200,  1515,  1515,   432,  1409,   243,   352,   356,
     844,   845,   846,  1026,   944,   944,   944,   944,   944,   944,
      25,     5,   397,   864,    20,   957,  1026,  1173,  1174,  1175,
     718,   720,   718,   246,   432,   990,   693,     5,   397,   292,
     293,  1417,   397,  1481,   397,   397,   397,   397,  1479,  1515,
    1515,   848,   847,   243,   846,   849,   702,     5,  1176,   287,
    1175,   716,  1515,  1299,    25,   957,  1418,  1419,   397,  1515,
    1515,  1515,   864,  1515,   397,   987,   625,   625,     5,   397,
     717,   957,   957,  1419,   167,   349,   719,   625,  1129,   957
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
#line 945 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 948 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 952 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 958 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 963 "fgl.yacc"
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
#line 975 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 980 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,
		"A4GL_unregister_func(\"%s\",%s%s);\n",
			yyvsp[0].str,
			(char *)get_namespace(yyvsp[0].str),
			yyvsp[0].str
	);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 1004 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 1007 "fgl.yacc"
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
#line 1018 "fgl.yacc"
    {
	struct expr_str *ptr;
	char buff2[1024];
	char buff[1024];
	sprintf(yyval.str,print_arr_expr_fcall(yyvsp[0].ptr));
}
    break;

  case 17:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 18:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 19:
#line 1029 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 20:
#line 1030 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 21:
#line 1031 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 22:
#line 1036 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 23:
#line 1037 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 24:
#line 1048 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 25:
#line 1051 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 26:
#line 1054 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 27:
#line 1054 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 29:
#line 1061 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 30:
#line 1062 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 31:
#line 1068 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 32:
#line 1069 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 33:
#line 1070 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 34:
#line 1071 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 35:
#line 1072 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 36:
#line 1073 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 37:
#line 1074 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 38:
#line 1075 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 39:
#line 1076 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 40:
#line 1077 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 41:
#line 1078 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 42:
#line 1079 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 43:
#line 1080 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 44:
#line 1081 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 45:
#line 1082 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 46:
#line 1083 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 47:
#line 1084 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 50:
#line 1091 "fgl.yacc"
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
#line 1102 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 52:
#line 1106 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 53:
#line 1107 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 54:
#line 1111 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 55:
#line 1117 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 56:
#line 1119 "fgl.yacc"
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
#line 1130 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1132 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 59:
#line 1134 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1136 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 61:
#line 1140 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 62:
#line 1142 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 63:
#line 1203 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 64:
#line 1207 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 65:
#line 1211 "fgl.yacc"
    {
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 66:
#line 1218 "fgl.yacc"
    {
		print_returning();
	}
    break;

  case 67:
#line 1221 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 68:
#line 1225 "fgl.yacc"
    {
		print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 70:
#line 1229 "fgl.yacc"
    { 
        if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) {
                a4gl_yyerror("get_fldbuf can only be used in an input or construct");
                YYERROR;
        }
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 71:
#line 1236 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 72:
#line 1242 "fgl.yacc"
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
#line 1251 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 74:
#line 1255 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 75:
#line 1260 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 76:
#line 1264 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 77:
#line 1272 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 78:
#line 1276 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 79:
#line 1280 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 80:
#line 1282 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 81:
#line 1288 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 82:
#line 1293 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 83:
#line 1296 "fgl.yacc"
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
#line 1312 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 85:
#line 1319 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 86:
#line 1323 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 87:
#line 1327 "fgl.yacc"
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
#line 1349 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1349 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 90:
#line 1353 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 91:
#line 1354 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 92:
#line 1355 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 93:
#line 1360 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 94:
#line 1363 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 95:
#line 1369 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 96:
#line 1372 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 99:
#line 1384 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 100:
#line 1390 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 101:
#line 1393 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 102:
#line 1408 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 103:
#line 1418 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 104:
#line 1424 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 105:
#line 1433 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 110:
#line 1446 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 112:
#line 1449 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 113:
#line 1451 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1457 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 116:
#line 1459 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 117:
#line 1464 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 118:
#line 1469 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1475 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 120:
#line 1479 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 121:
#line 1494 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 122:
#line 1497 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 123:
#line 1500 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 124:
#line 1503 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 125:
#line 1506 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 126:
#line 1509 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 132:
#line 1531 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 135:
#line 1540 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 136:
#line 1550 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 137:
#line 1564 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 138:
#line 1568 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 139:
#line 1571 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 140:
#line 1579 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,0,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_sio[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 141:
#line 1585 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_sio[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 146:
#line 1600 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 147:
#line 1604 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 148:
#line 1609 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 151:
#line 1619 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1622 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 153:
#line 1626 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1628 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 155:
#line 1631 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 156:
#line 1633 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 157:
#line 1636 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 158:
#line 1638 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1641 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 160:
#line 1644 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 161:
#line 1654 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1655 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1663 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 164:
#line 1664 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 165:
#line 1681 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 166:
#line 1684 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 167:
#line 1687 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 168:
#line 1690 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 169:
#line 1693 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 170:
#line 1696 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 171:
#line 1705 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 172:
#line 1713 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 173:
#line 1718 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 174:
#line 1731 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 175:
#line 1735 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 176:
#line 1750 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 177:
#line 1751 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 180:
#line 1759 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 181:
#line 1759 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 187:
#line 1769 "fgl.yacc"
    {in_define=1;}
    break;

  case 188:
#line 1769 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 189:
#line 1778 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 190:
#line 1779 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 191:
#line 1780 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1783 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 194:
#line 1788 "fgl.yacc"
    { }
    break;

  case 195:
#line 1788 "fgl.yacc"
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
#line 1805 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 200:
#line 1809 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 205:
#line 1824 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 206:
#line 1825 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 207:
#line 1826 "fgl.yacc"
    {strcpy(yyval.str,"-2");}
    break;

  case 208:
#line 1827 "fgl.yacc"
    {strcpy(yyval.str,"-3");}
    break;

  case 209:
#line 1832 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 211:
#line 1838 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[0].str);
	push_type(0,0,yyvsp[0].str);
}
    break;

  case 213:
#line 1847 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 214:
#line 1851 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 220:
#line 1867 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 221:
#line 1869 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 222:
#line 1870 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 224:
#line 1877 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 225:
#line 1877 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 226:
#line 1878 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 227:
#line 1879 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 228:
#line 1882 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 229:
#line 1884 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 231:
#line 1894 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 236:
#line 1909 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 237:
#line 1909 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 241:
#line 1915 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 242:
#line 1916 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 243:
#line 1923 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 244:
#line 1924 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 245:
#line 1925 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 246:
#line 1926 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 247:
#line 1929 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 248:
#line 1930 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 249:
#line 1931 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 250:
#line 1932 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 251:
#line 1936 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 252:
#line 1941 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 253:
#line 1946 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 254:
#line 1950 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 255:
#line 1953 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 256:
#line 1957 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 257:
#line 1958 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 258:
#line 1959 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 259:
#line 1960 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 260:
#line 1961 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 261:
#line 1962 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 262:
#line 1963 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 263:
#line 1964 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 264:
#line 1967 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 265:
#line 1968 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 266:
#line 1969 "fgl.yacc"
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
#line 2001 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 268:
#line 2005 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 269:
#line 2007 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 270:
#line 2009 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 271:
#line 2011 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 272:
#line 2016 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 273:
#line 2020 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 274:
#line 2020 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 275:
#line 2024 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 276:
#line 2025 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 277:
#line 2026 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 278:
#line 2027 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 279:
#line 2028 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 280:
#line 2029 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 281:
#line 2031 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 282:
#line 2036 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 283:
#line 2036 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 284:
#line 2039 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 285:
#line 2041 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 286:
#line 2047 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 287:
#line 2049 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 288:
#line 2055 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 289:
#line 2063 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 290:
#line 2063 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 291:
#line 2066 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 292:
#line 2067 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 293:
#line 2068 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 294:
#line 2069 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 295:
#line 2070 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 296:
#line 2071 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 297:
#line 2073 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 301:
#line 2094 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 305:
#line 2103 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 306:
#line 2105 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 307:
#line 2107 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 308:
#line 2109 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 309:
#line 2110 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 310:
#line 2111 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 311:
#line 2112 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 312:
#line 2113 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 313:
#line 2118 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 314:
#line 2125 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 315:
#line 2130 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 316:
#line 2132 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 317:
#line 2134 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 318:
#line 2135 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 319:
#line 2136 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 320:
#line 2137 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 321:
#line 2138 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 322:
#line 2139 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 323:
#line 2140 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 324:
#line 2143 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 325:
#line 2145 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 326:
#line 2151 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 327:
#line 2159 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 329:
#line 2167 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 330:
#line 2171 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 331:
#line 2179 "fgl.yacc"
    {dim_push_record();}
    break;

  case 332:
#line 2180 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 333:
#line 2181 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 334:
#line 2182 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 340:
#line 2201 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 341:
#line 2213 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 342:
#line 2217 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 343:
#line 2220 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 344:
#line 2223 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 345:
#line 2224 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 346:
#line 2225 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 347:
#line 2226 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 348:
#line 2227 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 349:
#line 2233 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 350:
#line 2240 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 351:
#line 2245 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 352:
#line 2250 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		curr_input_array_attribs.curr_row_display=0;
		}
    break;

  case 353:
#line 2255 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,&curr_input_array_attribs);
		}
    break;

  case 354:
#line 2258 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 355:
#line 2266 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 356:
#line 2268 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 357:
#line 2273 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 363:
#line 2285 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 364:
#line 2288 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 365:
#line 2291 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 366:
#line 2294 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 367:
#line 2297 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 368:
#line 2300 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 369:
#line 2307 "fgl.yacc"
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

		print_alloc_arr(buff,s);
	}
    break;

  case 370:
#line 2325 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 371:
#line 2331 "fgl.yacc"
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

  case 372:
#line 2355 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 373:
#line 2358 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 374:
#line 2373 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 375:
#line 2375 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 376:
#line 2377 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 377:
#line 2379 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 378:
#line 2381 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 379:
#line 2383 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 380:
#line 2384 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 381:
#line 2391 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 382:
#line 2393 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 383:
#line 2397 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 384:
#line 2399 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 385:
#line 2401 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 386:
#line 2403 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 387:
#line 2405 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 388:
#line 2407 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 389:
#line 2409 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 390:
#line 2415 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 391:
#line 2429 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 392:
#line 2432 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 397:
#line 2449 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 400:
#line 2455 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 401:
#line 2459 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 402:
#line 2464 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 406:
#line 2474 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 407:
#line 2475 "fgl.yacc"
    {inc_counter();}
    break;

  case 413:
#line 2481 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 414:
#line 2488 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 415:
#line 2488 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 417:
#line 2493 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 418:
#line 2497 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2503 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2511 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2517 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 422:
#line 2526 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 423:
#line 2528 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 424:
#line 2535 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 425:
#line 2543 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 426:
#line 2547 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 427:
#line 2556 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 428:
#line 2561 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 429:
#line 2566 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 430:
#line 2570 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 431:
#line 2572 "fgl.yacc"
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

  case 432:
#line 2582 "fgl.yacc"
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

  case 433:
#line 2596 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 434:
#line 2604 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2616 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2622 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 437:
#line 2628 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 440:
#line 2638 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 441:
#line 2644 "fgl.yacc"
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

  case 442:
#line 2716 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2722 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 444:
#line 2726 "fgl.yacc"
    {
   if (!isin_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 445:
#line 2734 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 446:
#line 2734 "fgl.yacc"
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

  case 447:
#line 2750 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 448:
#line 2754 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 449:
#line 2760 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 450:
#line 2763 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 451:
#line 2771 "fgl.yacc"
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

  case 452:
#line 2782 "fgl.yacc"
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

  case 453:
#line 2792 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 454:
#line 2798 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 455:
#line 2808 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2813 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 457:
#line 2820 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 458:
#line 2823 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 459:
#line 2826 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 460:
#line 2831 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 461:
#line 2838 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2843 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 463:
#line 2848 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2853 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 465:
#line 2864 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 466:
#line 2872 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 467:
#line 2880 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 468:
#line 2885 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 469:
#line 2889 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 470:
#line 2894 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 471:
#line 2898 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 472:
#line 2902 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 473:
#line 2908 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2911 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 475:
#line 2915 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 476:
#line 2919 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 477:
#line 2923 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 478:
#line 2927 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 479:
#line 2931 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 480:
#line 2938 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 481:
#line 2948 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 482:
#line 2953 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 483:
#line 2959 "fgl.yacc"
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

  case 484:
#line 2969 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 485:
#line 2974 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 486:
#line 2977 "fgl.yacc"
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

  case 487:
#line 2991 "fgl.yacc"
    {chk4var=1;}
    break;

  case 488:
#line 2991 "fgl.yacc"
    {chk4var=0;}
    break;

  case 489:
#line 2991 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 490:
#line 2994 "fgl.yacc"
    {chk4var=1;}
    break;

  case 491:
#line 2994 "fgl.yacc"
    {chk4var=0;}
    break;

  case 492:
#line 2994 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 493:
#line 2998 "fgl.yacc"
    {chk4var=1;}
    break;

  case 494:
#line 2998 "fgl.yacc"
    {chk4var=0;}
    break;

  case 495:
#line 2998 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 496:
#line 3002 "fgl.yacc"
    {chk4var=1;}
    break;

  case 497:
#line 3002 "fgl.yacc"
    {chk4var=0;}
    break;

  case 498:
#line 3002 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 499:
#line 3006 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3012 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3018 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3024 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 503:
#line 3030 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3036 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 505:
#line 3046 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 506:
#line 3047 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 509:
#line 3055 "fgl.yacc"
    {
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("get_fldbuf can only be used in an input or construct");
   		YYERROR;
	}
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(_sio,_inp_io_type,%s,0,0);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);	
	inc_counter();

}
    break;

  case 510:
#line 3066 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 511:
#line 3067 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 512:
#line 3073 "fgl.yacc"
    {
/* Informix allows this outside of a input/construct... */
	if (isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	} else {
		sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(0,0,%s,0,0));",yyvsp[-1].str); 
	}
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 513:
#line 3084 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 514:
#line 3094 "fgl.yacc"
    { 
	if (!isin_command("INPUT")&&!isin_command("CONSTRUCT")) { 
   		a4gl_yyerror("field_touched can only be used in an input or construct");
   		YYERROR;
	}
	sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(_sio,_inp_io_type,%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 517:
#line 3107 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 518:
#line 3112 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 519:
#line 3119 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 520:
#line 3123 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 521:
#line 3126 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 522:
#line 3129 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 523:
#line 3135 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3138 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3141 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 526:
#line 3158 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3161 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 528:
#line 3167 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 529:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 530:
#line 3169 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 532:
#line 3174 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 533:
#line 3175 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3177 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3180 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3181 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3183 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 540:
#line 3184 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 542:
#line 3190 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 544:
#line 3195 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 545:
#line 3207 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 546:
#line 3211 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 547:
#line 3212 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 548:
#line 3219 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 550:
#line 3236 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 551:
#line 3240 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 552:
#line 3246 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 553:
#line 3250 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 554:
#line 3259 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 555:
#line 3260 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 556:
#line 3272 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 557:
#line 3278 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 558:
#line 3286 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 565:
#line 3303 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 566:
#line 3305 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 567:
#line 3308 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 568:
#line 3310 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 573:
#line 3324 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 574:
#line 3326 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 575:
#line 3329 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 576:
#line 3331 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 589:
#line 3362 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 590:
#line 3364 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 591:
#line 3367 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 592:
#line 3369 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 593:
#line 3372 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 594:
#line 3374 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 595:
#line 3377 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 596:
#line 3379 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 597:
#line 3382 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 598:
#line 3384 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 599:
#line 3399 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 600:
#line 3415 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 601:
#line 3416 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 602:
#line 3417 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 603:
#line 3418 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 604:
#line 3419 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3420 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 606:
#line 3421 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 610:
#line 3429 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 612:
#line 3435 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 613:
#line 3437 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 614:
#line 3438 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 615:
#line 3440 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 616:
#line 3442 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 617:
#line 3444 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 618:
#line 3446 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 619:
#line 3448 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 620:
#line 3451 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 621:
#line 3458 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 622:
#line 3460 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3466 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3471 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3476 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 626:
#line 3481 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 627:
#line 3481 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 628:
#line 3484 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 629:
#line 3490 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 630:
#line 3495 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 631:
#line 3499 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 634:
#line 3507 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 635:
#line 3509 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 636:
#line 3511 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 637:
#line 3513 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 638:
#line 3515 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 639:
#line 3517 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 640:
#line 3520 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 642:
#line 3529 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 643:
#line 3591 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 644:
#line 3604 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 646:
#line 3611 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 647:
#line 3614 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 648:
#line 3620 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 649:
#line 3626 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 650:
#line 3630 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3634 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 652:
#line 3640 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 653:
#line 3644 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3648 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 655:
#line 3653 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 656:
#line 3658 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 675:
#line 3699 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 676:
#line 3706 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 677:
#line 3709 "fgl.yacc"
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

  case 679:
#line 3728 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 681:
#line 3731 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 682:
#line 3733 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 683:
#line 3736 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 684:
#line 3740 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 685:
#line 3743 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 686:
#line 3749 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 687:
#line 3760 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 688:
#line 3761 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 689:
#line 3764 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 691:
#line 3770 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 692:
#line 3774 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 693:
#line 3775 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 697:
#line 3791 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 698:
#line 3793 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 701:
#line 3802 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 702:
#line 3804 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 703:
#line 3808 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 704:
#line 3810 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 705:
#line 3813 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 706:
#line 3815 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 707:
#line 3818 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 708:
#line 3821 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 709:
#line 3824 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 710:
#line 3826 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 711:
#line 3829 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 712:
#line 3831 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 713:
#line 3834 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 714:
#line 3836 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 715:
#line 3839 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 716:
#line 3841 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 717:
#line 3842 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 718:
#line 3844 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 719:
#line 3845 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 720:
#line 3847 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 721:
#line 3848 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 722:
#line 3850 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 723:
#line 3890 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 724:
#line 3891 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 725:
#line 3899 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 726:
#line 3900 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 727:
#line 3909 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 728:
#line 3914 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 729:
#line 3919 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 730:
#line 3920 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 732:
#line 3925 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 733:
#line 3928 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 734:
#line 3936 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 735:
#line 3941 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 736:
#line 3945 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 737:
#line 3952 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 738:
#line 3961 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 739:
#line 3967 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 740:
#line 3968 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 741:
#line 3969 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 742:
#line 3970 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 743:
#line 3973 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 745:
#line 3976 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 746:
#line 3983 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 747:
#line 3984 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 748:
#line 3985 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 3986 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 750:
#line 3987 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 751:
#line 3988 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 752:
#line 3989 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 753:
#line 3990 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 754:
#line 3991 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 755:
#line 3996 "fgl.yacc"
    {iskey=1;}
    break;

  case 756:
#line 3996 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 757:
#line 3998 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 758:
#line 4001 "fgl.yacc"
    {iskey=1;}
    break;

  case 759:
#line 4001 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 760:
#line 4003 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 761:
#line 4007 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 762:
#line 4010 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 763:
#line 4011 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 765:
#line 4014 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 771:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 772:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 773:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 774:
#line 4029 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 775:
#line 4030 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 776:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 777:
#line 4032 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 778:
#line 4033 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 779:
#line 4034 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 780:
#line 4035 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 781:
#line 4036 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 782:
#line 4037 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 783:
#line 4038 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 784:
#line 4039 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 785:
#line 4043 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 786:
#line 4061 "fgl.yacc"
    {chk4var=1;}
    break;

  case 787:
#line 4061 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 788:
#line 4064 "fgl.yacc"
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

  case 789:
#line 4088 "fgl.yacc"
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

  case 791:
#line 4106 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 792:
#line 4112 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 793:
#line 4118 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 794:
#line 4124 "fgl.yacc"
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

  case 795:
#line 4135 "fgl.yacc"
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

  case 796:
#line 4158 "fgl.yacc"
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

  case 799:
#line 4174 "fgl.yacc"
    {
	}
    break;

  case 806:
#line 4197 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 810:
#line 4205 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 828:
#line 4231 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 829:
#line 4232 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 830:
#line 4240 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 831:
#line 4245 "fgl.yacc"
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

  case 832:
#line 4261 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 833:
#line 4267 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 835:
#line 4282 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 836:
#line 4295 "fgl.yacc"
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

  case 837:
#line 4305 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 838:
#line 4312 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 839:
#line 4319 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 840:
#line 4325 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 841:
#line 4325 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 842:
#line 4330 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 843:
#line 4336 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 844:
#line 4344 "fgl.yacc"
    {
}
    break;

  case 850:
#line 4356 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 852:
#line 4364 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 853:
#line 4370 "fgl.yacc"
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

  case 854:
#line 4384 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 855:
#line 4388 "fgl.yacc"
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

  case 856:
#line 4401 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 858:
#line 4419 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 859:
#line 4427 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 860:
#line 4433 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 861:
#line 4444 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 862:
#line 4448 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 863:
#line 4455 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 864:
#line 4462 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 865:
#line 4468 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 866:
#line 4473 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 869:
#line 4480 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 870:
#line 4481 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 871:
#line 4483 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 872:
#line 4484 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 873:
#line 4487 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 874:
#line 4488 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 875:
#line 4489 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 876:
#line 4491 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 877:
#line 4496 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 878:
#line 4501 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 879:
#line 4508 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 883:
#line 4515 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 884:
#line 4517 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 885:
#line 4519 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 886:
#line 4528 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 887:
#line 4534 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 888:
#line 4538 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 891:
#line 4550 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 892:
#line 4555 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 893:
#line 4560 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 894:
#line 4563 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 896:
#line 4575 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 897:
#line 4578 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 898:
#line 4581 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 905:
#line 4597 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 906:
#line 4602 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 907:
#line 4602 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 908:
#line 4605 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 909:
#line 4632 "fgl.yacc"
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

  case 911:
#line 4690 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 913:
#line 4697 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 914:
#line 4701 "fgl.yacc"
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

  case 915:
#line 4744 "fgl.yacc"
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

  case 919:
#line 4792 "fgl.yacc"
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

  case 920:
#line 4806 "fgl.yacc"
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

  case 925:
#line 4830 "fgl.yacc"
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

  case 926:
#line 4890 "fgl.yacc"
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

  case 927:
#line 4946 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 928:
#line 4951 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 929:
#line 4959 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 930:
#line 4964 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 931:
#line 4972 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 932:
#line 4978 "fgl.yacc"
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

  case 933:
#line 5011 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 934:
#line 5014 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 935:
#line 5016 "fgl.yacc"
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

  case 936:
#line 5057 "fgl.yacc"
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

  case 941:
#line 5110 "fgl.yacc"
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

  case 942:
#line 5162 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 944:
#line 5169 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 945:
#line 5175 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 946:
#line 5186 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5193 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 949:
#line 5201 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 950:
#line 5204 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 951:
#line 5205 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 953:
#line 5207 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 954:
#line 5208 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 955:
#line 5211 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 956:
#line 5214 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 957:
#line 5220 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 958:
#line 5223 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 959:
#line 5227 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 960:
#line 5231 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 961:
#line 5238 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 962:
#line 5243 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 963:
#line 5250 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 964:
#line 5253 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5266 "fgl.yacc"
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

  case 970:
#line 5285 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 971:
#line 5292 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 972:
#line 5299 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 973:
#line 5302 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 974:
#line 5316 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 979:
#line 5333 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 980:
#line 5338 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 981:
#line 5344 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 983:
#line 5351 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 984:
#line 5356 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 985:
#line 5359 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 986:
#line 5360 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 987:
#line 5363 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 988:
#line 5364 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 989:
#line 5367 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 990:
#line 5368 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 991:
#line 5373 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 992:
#line 5380 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 993:
#line 5383 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 994:
#line 5389 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 995:
#line 5391 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5393 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 997:
#line 5395 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 998:
#line 5398 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 999:
#line 5398 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1000:
#line 5399 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1001:
#line 5404 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1002:
#line 5412 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1003:
#line 5413 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1004:
#line 5418 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1005:
#line 5420 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1006:
#line 5422 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1010:
#line 5439 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1011:
#line 5442 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1012:
#line 5445 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1013:
#line 5448 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1014:
#line 5452 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1015:
#line 5455 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1016:
#line 5458 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5462 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1018:
#line 5466 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5470 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1020:
#line 5473 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1021:
#line 5477 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1022:
#line 5480 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1023:
#line 5481 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1024:
#line 5482 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1025:
#line 5485 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1026:
#line 5488 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1027:
#line 5491 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1028:
#line 5494 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1029:
#line 5497 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1030:
#line 5500 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1031:
#line 5503 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1032:
#line 5520 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1035:
#line 5530 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1036:
#line 5536 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1037:
#line 5540 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1039:
#line 5560 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1040:
#line 5565 "fgl.yacc"
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

  case 1041:
#line 5577 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1042:
#line 5578 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1043:
#line 5582 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1044:
#line 5587 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1045:
#line 5588 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1046:
#line 5592 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1050:
#line 5598 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1051:
#line 5600 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1053:
#line 5615 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1054:
#line 5619 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1055:
#line 5625 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1056:
#line 5626 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1057:
#line 5631 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1058:
#line 5632 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1059:
#line 5635 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	A4GL_debug("put buff=%s\n",buff);
	if (buff[0]!='\''&&strncmp(buff,"?",1)!=0&&strncmp(buff," :",2)!=0) {
		A4GL_debug("Got : %s - expecting '..', : or ?",buff);
 		a4gl_yyerror("Put values must be variables, strings or 'NULL'");
		YYERROR;
	}

	A4GL_add_put_string(buff);
	strcpy(yyval.str,buff);

}
    break;

  case 1061:
#line 5663 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1062:
#line 5668 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1063:
#line 5673 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1064:
#line 5678 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1070:
#line 5700 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1071:
#line 5707 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1072:
#line 5716 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1073:
#line 5722 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1074:
#line 5724 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1078:
#line 5735 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1079:
#line 5736 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1080:
#line 5742 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1081:
#line 5746 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1082:
#line 5752 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1083:
#line 5753 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1084:
#line 5758 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1085:
#line 5759 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5761 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1087:
#line 5762 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5763 "fgl.yacc"
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

  case 1089:
#line 5777 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1090:
#line 5779 "fgl.yacc"
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

  case 1091:
#line 5796 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1098:
#line 5808 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1099:
#line 5808 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1100:
#line 5814 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1101:
#line 5814 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1102:
#line 5817 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1103:
#line 5817 "fgl.yacc"
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

  case 1104:
#line 5833 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1105:
#line 5834 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1106:
#line 5835 "fgl.yacc"
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

  case 1107:
#line 5844 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1108:
#line 5856 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1114:
#line 5867 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1115:
#line 5872 "fgl.yacc"
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

  case 1116:
#line 5892 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1117:
#line 5897 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1118:
#line 5903 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1119:
#line 5904 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1120:
#line 5905 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1121:
#line 5909 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1122:
#line 5910 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1123:
#line 5911 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1124:
#line 5912 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1125:
#line 5916 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1126:
#line 5926 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1127:
#line 5928 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1128:
#line 5933 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1129:
#line 5936 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1130:
#line 5941 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1131:
#line 5948 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1132:
#line 5955 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1133:
#line 5962 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1134:
#line 5971 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1135:
#line 5978 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1136:
#line 5985 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1137:
#line 5992 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1138:
#line 5999 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 6012 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 6013 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1145:
#line 6014 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6015 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1147:
#line 6016 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1148:
#line 6017 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1149:
#line 6018 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1150:
#line 6019 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1151:
#line 6020 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1152:
#line 6021 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1155:
#line 6027 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1156:
#line 6028 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1157:
#line 6029 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1158:
#line 6030 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1163:
#line 6039 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1164:
#line 6040 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6041 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6042 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6043 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1168:
#line 6044 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6045 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1170:
#line 6046 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1171:
#line 6048 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1172:
#line 6049 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1173:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1174:
#line 6051 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1175:
#line 6053 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1176:
#line 6054 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1177:
#line 6055 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1178:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1182:
#line 6061 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1183:
#line 6062 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1187:
#line 6069 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1188:
#line 6077 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1189:
#line 6085 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1190:
#line 6097 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1191:
#line 6106 "fgl.yacc"
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

  case 1192:
#line 6117 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1193:
#line 6121 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1194:
#line 6125 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1195:
#line 6131 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1196:
#line 6136 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1197:
#line 6144 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1198:
#line 6147 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1199:
#line 6156 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1200:
#line 6167 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1202:
#line 6174 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1203:
#line 6182 "fgl.yacc"
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

  case 1204:
#line 6192 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1205:
#line 6195 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1206:
#line 6199 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1207:
#line 6207 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1208:
#line 6210 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1209:
#line 6216 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1210:
#line 6220 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1211:
#line 6224 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1212:
#line 6228 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1213:
#line 6232 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1214:
#line 6238 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1215:
#line 6239 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1216:
#line 6240 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1217:
#line 6241 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1218:
#line 6246 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1219:
#line 6248 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1220:
#line 6251 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1221:
#line 6255 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1222:
#line 6258 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1223:
#line 6265 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1224:
#line 6270 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1225:
#line 6271 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1226:
#line 6272 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1227:
#line 6277 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1228:
#line 6278 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1229:
#line 6284 "fgl.yacc"
    {insql=1;}
    break;

  case 1230:
#line 6284 "fgl.yacc"
    {insql=0;}
    break;

  case 1231:
#line 6284 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1232:
#line 6289 "fgl.yacc"
    {insql=1;}
    break;

  case 1233:
#line 6289 "fgl.yacc"
    {insql=0;}
    break;

  case 1234:
#line 6289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1235:
#line 6300 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1236:
#line 6301 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1237:
#line 6307 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1238:
#line 6309 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1240:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1241:
#line 6326 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1242:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1244:
#line 6332 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6335 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1246:
#line 6341 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1247:
#line 6344 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1248:
#line 6352 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1250:
#line 6359 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1251:
#line 6366 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 6369 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1253:
#line 6378 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 6381 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6384 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6387 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1257:
#line 6390 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1258:
#line 6393 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1259:
#line 6396 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1260:
#line 6403 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1261:
#line 6406 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1262:
#line 6413 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6416 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1264:
#line 6422 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1265:
#line 6425 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1266:
#line 6432 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1267:
#line 6435 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1269:
#line 6443 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1271:
#line 6452 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1272:
#line 6455 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1273:
#line 6461 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 6464 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1275:
#line 6470 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1276:
#line 6477 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1277:
#line 6478 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1278:
#line 6482 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1279:
#line 6488 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1280:
#line 6491 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1282:
#line 6499 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1283:
#line 6506 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1284:
#line 6509 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1294:
#line 6533 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1295:
#line 6536 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1296:
#line 6539 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1297:
#line 6545 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1299:
#line 6551 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1301:
#line 6562 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1302:
#line 6576 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1303:
#line 6585 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1304:
#line 6585 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1305:
#line 6590 "fgl.yacc"
    {insql=1;}
    break;

  case 1306:
#line 6590 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1307:
#line 6595 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1308:
#line 6598 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1309:
#line 6600 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1311:
#line 6607 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1312:
#line 6611 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1313:
#line 6615 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1314:
#line 6622 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1315:
#line 6625 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1316:
#line 6632 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1317:
#line 6636 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1318:
#line 6640 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1319:
#line 6645 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1320:
#line 6650 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1321:
#line 6654 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1322:
#line 6660 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1323:
#line 6664 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1324:
#line 6670 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1325:
#line 6677 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1326:
#line 6681 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1327:
#line 6686 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1328:
#line 6696 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1329:
#line 6699 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1330:
#line 6701 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6703 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1332:
#line 6705 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1333:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1334:
#line 6709 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1335:
#line 6711 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1336:
#line 6717 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1337:
#line 6727 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1338:
#line 6734 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6740 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6743 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1344:
#line 6750 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1347:
#line 6755 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1348:
#line 6760 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1349:
#line 6767 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1350:
#line 6768 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1351:
#line 6775 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1352:
#line 6786 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1353:
#line 6787 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1354:
#line 6788 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1355:
#line 6791 "fgl.yacc"
    {insql=1;}
    break;

  case 1356:
#line 6791 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1357:
#line 6796 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1358:
#line 6801 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1360:
#line 6807 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1362:
#line 6811 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1363:
#line 6816 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1364:
#line 6821 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1365:
#line 6825 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1367:
#line 6831 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1368:
#line 6835 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1369:
#line 6843 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6846 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1371:
#line 6848 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1372:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1375:
#line 6860 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1379:
#line 6867 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6870 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1381:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1383:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6884 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1388:
#line 6894 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1389:
#line 6899 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1390:
#line 6901 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1392:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1393:
#line 6910 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1395:
#line 6916 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1396:
#line 6924 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6929 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6939 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1402:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6953 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6959 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1408:
#line 6967 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1409:
#line 6970 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1410:
#line 6978 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6980 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1412:
#line 6993 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1413:
#line 6998 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1415:
#line 7002 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1416:
#line 7004 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1417:
#line 7011 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1418:
#line 7014 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1419:
#line 7020 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1420:
#line 7024 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1421:
#line 7028 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1422:
#line 7032 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1423:
#line 7035 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1424:
#line 7043 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1425:
#line 7050 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1428:
#line 7059 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7065 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1430:
#line 7068 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1431:
#line 7079 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1432:
#line 7086 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7092 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1434:
#line 7095 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1435:
#line 7102 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1436:
#line 7109 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1438:
#line 7116 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1439:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1440:
#line 7123 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1441:
#line 7124 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1443:
#line 7128 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1445:
#line 7133 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1446:
#line 7140 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1447:
#line 7145 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1448:
#line 7146 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1449:
#line 7149 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1450:
#line 7152 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1451:
#line 7157 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1452:
#line 7158 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1453:
#line 7163 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 7166 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1455:
#line 7172 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1456:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 7181 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 7184 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 7190 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 7193 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1461:
#line 7200 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1462:
#line 7201 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1463:
#line 7230 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1464:
#line 7232 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 7236 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1467:
#line 7249 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1468:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1469:
#line 7255 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1470:
#line 7258 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1472:
#line 7266 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1473:
#line 7269 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1475:
#line 7275 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1477:
#line 7281 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1478:
#line 7284 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1479:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 7290 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1483:
#line 7299 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1484:
#line 7302 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 7307 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1487:
#line 7314 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1493:
#line 7322 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1494:
#line 7323 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1495:
#line 7328 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1496:
#line 7331 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1497:
#line 7335 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1498:
#line 7341 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1499:
#line 7342 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1500:
#line 7343 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1501:
#line 7344 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1506:
#line 7364 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1507:
#line 7369 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1508:
#line 7370 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1510:
#line 7373 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1514:
#line 7378 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 7381 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1518:
#line 7384 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 7389 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1523:
#line 7391 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 7394 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1525:
#line 7395 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1526:
#line 7402 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 7407 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1534:
#line 7423 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1535:
#line 7424 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1536:
#line 7428 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1537:
#line 7429 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1539:
#line 7448 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1540:
#line 7449 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1541:
#line 7450 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1542:
#line 7454 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1543:
#line 7457 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1544:
#line 7463 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1545:
#line 7468 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1546:
#line 7473 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1548:
#line 7484 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1553:
#line 7499 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1554:
#line 7502 "fgl.yacc"
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

  case 1555:
#line 7515 "fgl.yacc"
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

  case 1556:
#line 7530 "fgl.yacc"
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

  case 1557:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1558:
#line 7544 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1559:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1560:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1561:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1562:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1563:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1564:
#line 7547 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1565:
#line 7548 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1566:
#line 7551 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1567:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1568:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1569:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1570:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1571:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1572:
#line 7556 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1573:
#line 7558 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1574:
#line 7561 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1589:
#line 7570 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1590:
#line 7571 "fgl.yacc"
    {sprintf(yyval.str,"%s@%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1591:
#line 7572 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1592:
#line 7576 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1593:
#line 7584 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1594:
#line 7584 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1595:
#line 7590 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1596:
#line 7590 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1597:
#line 7597 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1598:
#line 7597 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1599:
#line 7603 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1600:
#line 7603 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1601:
#line 7611 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1602:
#line 7612 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1603:
#line 7613 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1604:
#line 7616 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1605:
#line 7616 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1607:
#line 7620 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1608:
#line 7621 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1609:
#line 7626 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1610:
#line 7629 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1611:
#line 7635 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1612:
#line 7640 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1613:
#line 7648 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1614:
#line 7660 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1615:
#line 7661 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1616:
#line 7664 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-7].str, yyvsp[-5].sql_string," ", yyvsp[-3].sql_string, " ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,yyvsp[0].str,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-5].sql_string);
		free(yyvsp[-3].sql_string);
		free(yyvsp[-2].sql_string);
		free(yyvsp[-1].sql_string);
}
    break;

  case 1617:
#line 7679 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("A4GL_push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1618:
#line 7689 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1619:
#line 7692 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1620:
#line 7700 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1621:
#line 7709 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1622:
#line 7712 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1623:
#line 7716 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1624:
#line 7719 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1625:
#line 7720 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1627:
#line 7729 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1628:
#line 7730 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1629:
#line 7739 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1630:
#line 7748 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1631:
#line 7753 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1632:
#line 7754 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1633:
#line 7755 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1634:
#line 7756 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1635:
#line 7763 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1636:
#line 7766 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1637:
#line 7772 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7775 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1639:
#line 7785 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1640:
#line 7794 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1641:
#line 7797 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1642:
#line 7800 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1643:
#line 7806 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1644:
#line 7812 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1645:
#line 7815 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1646:
#line 7818 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1647:
#line 7821 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1648:
#line 7828 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1649:
#line 7830 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1650:
#line 7832 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1651:
#line 7834 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1652:
#line 7836 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1653:
#line 7837 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1654:
#line 7838 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1655:
#line 7839 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1656:
#line 7840 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1657:
#line 7841 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1658:
#line 7842 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1659:
#line 7844 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7846 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7848 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1663:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1664:
#line 7854 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1665:
#line 7856 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1666:
#line 7857 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1667:
#line 7859 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1668:
#line 7863 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1669:
#line 7864 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1671:
#line 7874 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1672:
#line 7883 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1673:
#line 7887 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1674:
#line 7894 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1675:
#line 7894 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1677:
#line 7898 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1678:
#line 7903 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1679:
#line 7903 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1681:
#line 7907 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1682:
#line 7911 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1685:
#line 7920 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1686:
#line 7920 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1691:
#line 7939 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1692:
#line 7940 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1695:
#line 7948 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1696:
#line 7954 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1699:
#line 7973 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1700:
#line 7974 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1701:
#line 7975 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1702:
#line 7976 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1703:
#line 7977 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1704:
#line 7978 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1705:
#line 7982 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1706:
#line 7983 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1707:
#line 7984 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1708:
#line 7988 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1709:
#line 7992 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1711:
#line 8001 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1713:
#line 8006 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1714:
#line 8007 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2035:
#line 8335 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2036:
#line 8335 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2037:
#line 8342 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2038:
#line 8342 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2039:
#line 8430 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2040:
#line 8434 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2041:
#line 8436 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2042:
#line 8443 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2043:
#line 8447 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2044:
#line 8453 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2045:
#line 8461 "fgl.yacc"
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

  case 2046:
#line 8471 "fgl.yacc"
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

  case 2047:
#line 8481 "fgl.yacc"
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

  case 2048:
#line 8493 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2049:
#line 8496 "fgl.yacc"
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

  case 2050:
#line 8515 "fgl.yacc"
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

  case 2051:
#line 8541 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2052:
#line 8544 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2054:
#line 8553 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2055:
#line 8558 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2056:
#line 8561 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2057:
#line 8569 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2058:
#line 8577 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2059:
#line 8590 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2060:
#line 8593 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2061:
#line 8601 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2062:
#line 8604 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2063:
#line 8607 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2064:
#line 8615 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2065:
#line 8619 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2066:
#line 8622 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2067:
#line 8625 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2068:
#line 8628 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2069:
#line 8632 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2070:
#line 8633 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2071:
#line 8634 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2072:
#line 8635 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2073:
#line 8636 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2074:
#line 8642 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2075:
#line 8643 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2076:
#line 8644 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2077:
#line 8645 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2078:
#line 8646 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2079:
#line 8647 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8648 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8649 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8650 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2083:
#line 8651 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2084:
#line 8652 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2085:
#line 8653 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2086:
#line 8654 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2087:
#line 8655 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2088:
#line 8659 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2089:
#line 8665 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2090:
#line 8666 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2091:
#line 8674 "fgl.yacc"
    {
	clr_validate_list();
}
    break;

  case 2092:
#line 8676 "fgl.yacc"
    {
	print_validate();
}
    break;

  case 2094:
#line 8682 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 2095:
#line 8686 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
		push_validate(yyval.str);
	}
    break;

  case 2096:
#line 8690 "fgl.yacc"
    {
		sprintf(yyval.str,"%s.*",yyvsp[-2].str);
		push_validate(yyval.str);
	}
    break;

  case 2097:
#line 8706 "fgl.yacc"
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

  case 2098:
#line 8726 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2102:
#line 8732 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2103:
#line 8733 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2107:
#line 8745 "fgl.yacc"
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

  case 2108:
#line 8771 "fgl.yacc"
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

  case 2109:
#line 8836 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2110:
#line 8838 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2111:
#line 8840 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2112:
#line 8841 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2113:
#line 8846 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2114:
#line 8851 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2115:
#line 8852 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2116:
#line 8856 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2117:
#line 8858 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2118:
#line 8860 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2119:
#line 8863 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2120:
#line 8867 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2121:
#line 8872 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2122:
#line 8877 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2123:
#line 8881 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2125:
#line 8891 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2127:
#line 8906 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2128:
#line 8909 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2129:
#line 8913 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2132:
#line 8932 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2133:
#line 8933 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2134:
#line 8936 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2135:
#line 8937 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2136:
#line 8938 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2137:
#line 8939 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2138:
#line 8940 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2139:
#line 8941 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2140:
#line 8942 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2141:
#line 8947 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2142:
#line 8948 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2143:
#line 8952 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2144:
#line 8956 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2145:
#line 8960 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2146:
#line 8964 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2147:
#line 8969 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2148:
#line 8973 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2149:
#line 8978 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2151:
#line 8986 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2153:
#line 8992 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2154:
#line 8998 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2155:
#line 9002 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2160:
#line 9020 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2161:
#line 9027 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2162:
#line 9036 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2163:
#line 9036 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18143 "y.tab.c"

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


#line 9135 "fgl.yacc"

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



