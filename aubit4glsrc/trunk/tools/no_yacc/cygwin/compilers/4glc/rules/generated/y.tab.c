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
#define YYLAST   10366

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  682
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  835
/* YYNRULES -- Number of rules. */
#define YYNRULES  2241
/* YYNRULES -- Number of states. */
#define YYNSTATES  3521

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
    1451,  1457,  1465,  1470,  1477,  1478,  1482,  1484,  1486,  1491,
    1496,  1501,  1506,  1511,  1516,  1518,  1520,  1522,  1524,  1529,
    1534,  1537,  1540,  1543,  1546,  1549,  1551,  1553,  1556,  1558,
    1560,  1562,  1565,  1570,  1577,  1584,  1588,  1594,  1600,  1604,
    1606,  1608,  1612,  1614,  1618,  1619,  1620,  1632,  1633,  1636,
    1637,  1638,  1639,  1649,  1650,  1654,  1655,  1656,  1667,  1668,
    1670,  1671,  1673,  1675,  1678,  1679,  1683,  1684,  1688,  1689,
    1691,  1693,  1696,  1697,  1701,  1702,  1706,  1710,  1712,  1717,
    1721,  1723,  1727,  1729,  1733,  1735,  1739,  1741,  1744,  1745,
    1749,  1750,  1754,  1755,  1760,  1761,  1766,  1767,  1772,  1775,
    1779,  1781,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,
    1803,  1805,  1807,  1812,  1819,  1824,  1828,  1835,  1839,  1846,
    1848,  1850,  1852,  1854,  1856,  1858,  1859,  1862,  1864,  1866,
    1868,  1873,  1875,  1877,  1879,  1884,  1888,  1895,  1899,  1906,
    1908,  1910,  1913,  1916,  1919,  1921,  1925,  1927,  1930,  1933,
    1936,  1941,  1944,  1947,  1952,  1953,  1962,  1963,  1965,  1967,
    1969,  1970,  1972,  1975,  1976,  1978,  1981,  1982,  1984,  1987,
    1988,  1990,  1994,  1995,  1998,  1999,  2000,  2009,  2010,  2011,
    2015,  2016,  2017,  2025,  2031,  2034,  2037,  2038,  2044,  2049,
    2051,  2055,  2059,  2063,  2064,  2067,  2068,  2070,  2072,  2075,
    2076,  2081,  2082,  2087,  2088,  2092,  2093,  2097,  2098,  2102,
    2103,  2107,  2108,  2112,  2113,  2117,  2118,  2122,  2123,  2127,
    2128,  2132,  2134,  2138,  2140,  2144,  2147,  2152,  2154,  2156,
    2158,  2159,  2164,  2170,  2177,  2178,  2189,  2193,  2196,  2199,
    2201,  2203,  2204,  2207,  2209,  2212,  2216,  2220,  2224,  2228,
    2230,  2232,  2234,  2236,  2237,  2241,  2243,  2244,  2248,  2251,
    2254,  2256,  2260,  2262,  2266,  2268,  2270,  2272,  2274,  2276,
    2278,  2280,  2282,  2284,  2286,  2288,  2290,  2292,  2294,  2296,
    2298,  2300,  2302,  2304,  2306,  2307,  2308,  2316,  2318,  2320,
    2323,  2326,  2329,  2333,  2338,  2339,  2343,  2344,  2346,  2348,
    2351,  2353,  2355,  2357,  2359,  2360,  2362,  2364,  2367,  2370,
    2372,  2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,
    2392,  2394,  2396,  2397,  2399,  2401,  2403,  2405,  2407,  2408,
    2409,  2410,  2411,  2425,  2427,  2428,  2429,  2436,  2439,  2441,
    2444,  2447,  2450,  2452,  2454,  2457,  2459,  2461,  2463,  2464,
    2468,  2471,  2473,  2474,  2475,  2476,  2491,  2492,  2498,  2500,
    2501,  2505,  2506,  2514,  2515,  2521,  2523,  2526,  2527,  2529,
    2531,  2533,  2534,  2536,  2538,  2541,  2544,  2547,  2549,  2551,
    2553,  2555,  2559,  2561,  2563,  2564,  2565,  2573,  2575,  2578,
    2579,  2583,  2584,  2589,  2592,  2593,  2596,  2598,  2600,  2602,
    2604,  2606,  2608,  2610,  2614,  2615,  2617,  2619,  2621,  2623,
    2626,  2629,  2632,  2638,  2647,  2649,  2651,  2653,  2658,  2663,
    2665,  2667,  2669,  2671,  2674,  2677,  2681,  2688,  2690,  2694,
    2696,  2698,  2700,  2704,  2711,  2721,  2723,  2725,  2727,  2729,
    2732,  2733,  2735,  2737,  2741,  2743,  2747,  2749,  2753,  2755,
    2759,  2761,  2763,  2765,  2767,  2771,  2773,  2777,  2779,  2783,
    2785,  2787,  2789,  2793,  2796,  2797,  2799,  2801,  2806,  2808,
    2812,  2814,  2818,  2826,  2827,  2835,  2836,  2843,  2847,  2849,
    2853,  2855,  2858,  2864,  2865,  2873,  2874,  2877,  2878,  2880,
    2886,  2889,  2895,  2896,  2902,  2909,  2914,  2915,  2917,  2919,
    2924,  2925,  2928,  2929,  2935,  2940,  2943,  2945,  2949,  2952,
    2955,  2958,  2961,  2964,  2967,  2969,  2972,  2975,  2978,  2981,
    2984,  2987,  2990,  2993,  2996,  2998,  3000,  3002,  3004,  3006,
    3008,  3014,  3016,  3018,  3021,  3026,  3029,  3031,  3032,  3044,
    3045,  3048,  3054,  3055,  3057,  3058,  3061,  3063,  3066,  3067,
    3071,  3073,  3074,  3079,  3080,  3083,  3085,  3089,  3091,  3093,
    3097,  3102,  3107,  3110,  3112,  3114,  3116,  3117,  3119,  3127,
    3130,  3133,  3136,  3139,  3142,  3144,  3147,  3148,  3152,  3153,
    3157,  3158,  3162,  3163,  3167,  3168,  3172,  3173,  3178,  3179,
    3184,  3186,  3188,  3190,  3192,  3194,  3196,  3197,  3202,  3203,
    3205,  3206,  3211,  3213,  3216,  3219,  3222,  3223,  3225,  3227,
    3230,  3233,  3234,  3237,  3241,  3245,  3251,  3252,  3255,  3260,
    3262,  3264,  3266,  3268,  3270,  3271,  3273,  3275,  3279,  3282,
    3288,  3291,  3297,  3303,  3309,  3315,  3321,  3327,  3328,  3331,
    3333,  3336,  3339,  3342,  3345,  3348,  3351,  3353,  3356,  3359,
    3362,  3365,  3367,  3370,  3373,  3376,  3379,  3381,  3383,  3385,
    3386,  3389,  3392,  3395,  3398,  3401,  3404,  3407,  3410,  3413,
    3415,  3417,  3419,  3421,  3423,  3425,  3427,  3429,  3432,  3435,
    3438,  3441,  3444,  3446,  3448,  3450,  3451,  3455,  3458,  3459,
    3460,  3461,  3462,  3463,  3464,  3480,  3481,  3484,  3487,  3488,
    3490,  3491,  3492,  3493,  3494,  3495,  3496,  3512,  3515,  3516,
    3517,  3518,  3529,  3530,  3532,  3536,  3540,  3543,  3548,  3552,
    3556,  3560,  3562,  3564,  3566,  3568,  3570,  3572,  3573,  3574,
    3582,  3583,  3584,  3593,  3597,  3600,  3601,  3603,  3605,  3609,
    3612,  3615,  3617,  3619,  3623,  3625,  3627,  3630,  3632,  3636,
    3638,  3642,  3644,  3646,  3648,  3650,  3652,  3654,  3656,  3659,
    3664,  3666,  3670,  3672,  3676,  3679,  3684,  3686,  3690,  3692,
    3695,  3700,  3702,  3706,  3708,  3710,  3712,  3715,  3718,  3723,
    3726,  3731,  3733,  3737,  3739,  3741,  3743,  3746,  3748,  3750,
    3752,  3754,  3756,  3759,  3766,  3773,  3774,  3776,  3777,  3779,
    3782,  3784,  3785,  3791,  3792,  3798,  3800,  3801,  3805,  3807,
    3811,  3813,  3817,  3819,  3821,  3822,  3823,  3829,  3831,  3834,
    3836,  3837,  3838,  3842,  3843,  3844,  3848,  3850,  3852,  3854,
    3856,  3858,  3860,  3863,  3866,  3871,  3875,  3879,  3881,  3885,
    3888,  3890,  3892,  3893,  3895,  3897,  3899,  3901,  3902,  3904,
    3908,  3910,  3912,  3913,  3917,  3919,  3921,  3923,  3925,  3927,
    3929,  3931,  3933,  3935,  3937,  3939,  3941,  3949,  3950,  3952,
    3954,  3956,  3958,  3962,  3964,  3966,  3968,  3971,  3972,  3976,
    3978,  3982,  3984,  3988,  3990,  3992,  3999,  4000,  4004,  4006,
    4010,  4011,  4013,  4018,  4024,  4027,  4029,  4031,  4036,  4038,
    4042,  4047,  4052,  4054,  4058,  4060,  4062,  4064,  4067,  4069,
    4074,  4075,  4077,  4078,  4080,  4082,  4085,  4087,  4089,  4091,
    4093,  4098,  4102,  4104,  4106,  4108,  4111,  4113,  4115,  4118,
    4121,  4123,  4127,  4130,  4133,  4135,  4139,  4141,  4144,  4149,
    4151,  4154,  4156,  4160,  4165,  4166,  4168,  4169,  4171,  4172,
    4174,  4176,  4180,  4182,  4186,  4188,  4191,  4193,  4197,  4200,
    4203,  4204,  4207,  4209,  4211,  4217,  4221,  4227,  4231,  4233,
    4237,  4239,  4241,  4242,  4244,  4248,  4252,  4256,  4263,  4268,
    4273,  4278,  4283,  4289,  4291,  4293,  4295,  4297,  4299,  4301,
    4303,  4305,  4307,  4309,  4311,  4313,  4314,  4316,  4318,  4320,
    4322,  4324,  4326,  4328,  4333,  4339,  4341,  4347,  4353,  4355,
    4357,  4359,  4364,  4366,  4371,  4373,  4381,  4383,  4385,  4387,
    4392,  4399,  4400,  4403,  4408,  4410,  4412,  4414,  4416,  4418,
    4420,  4422,  4426,  4428,  4430,  4434,  4436,  4437,  4441,  4447,
    4449,  4452,  4455,  4460,  4464,  4466,  4468,  4470,  4472,  4474,
    4476,  4479,  4482,  4483,  4487,  4488,  4492,  4494,  4496,  4498,
    4500,  4502,  4504,  4506,  4511,  4513,  4515,  4517,  4519,  4521,
    4523,  4525,  4530,  4532,  4534,  4536,  4538,  4540,  4542,  4544,
    4546,  4548,  4550,  4552,  4554,  4556,  4558,  4560,  4562,  4566,
    4567,  4575,  4576,  4585,  4586,  4593,  4594,  4603,  4604,  4606,
    4609,  4611,  4615,  4617,  4621,  4627,  4629,  4631,  4633,  4635,
    4637,  4638,  4639,  4649,  4655,  4657,  4659,  4666,  4667,  4671,
    4673,  4677,  4682,  4684,  4685,  4688,  4693,  4700,  4701,  4703,
    4705,  4707,  4709,  4713,  4715,  4718,  4720,  4722,  4725,  4728,
    4730,  4732,  4734,  4737,  4742,  4746,  4749,  4753,  4757,  4761,
    4763,  4765,  4767,  4769,  4771,  4773,  4779,  4785,  4791,  4797,
    4803,  4808,  4813,  4817,  4822,  4824,  4828,  4830,  4836,  4844,
    4850,  4851,  4854,  4856,  4858,  4859,  4863,  4865,  4869,  4871,
    4873,  4875,  4876,  4880,  4882,  4884,  4886,  4888,  4893,  4900,
    4902,  4904,  4907,  4911,  4913,  4915,  4917,  4919,  4921,  4923,
    4925,  4927,  4933,  4939,  4944,  4945,  4950,  4952,  4955,  4957,
    4959,  4961,  4963,  4965,  4967,  4969,  4971,  4973,  4975,  4977,
    4979,  4981,  4983,  4985,  4987,  4989,  4991,  4993,  4995,  4997,
    4999,  5001,  5003,  5005,  5007,  5009,  5011,  5013,  5015,  5017,
    5019,  5021,  5023,  5025,  5027,  5029,  5031,  5033,  5035,  5037,
    5039,  5041,  5043,  5045,  5047,  5049,  5051,  5053,  5055,  5057,
    5059,  5061,  5063,  5065,  5067,  5069,  5071,  5073,  5075,  5077,
    5079,  5081,  5083,  5085,  5087,  5089,  5091,  5093,  5095,  5097,
    5099,  5101,  5103,  5105,  5107,  5109,  5111,  5113,  5115,  5117,
    5119,  5121,  5123,  5125,  5127,  5129,  5131,  5133,  5135,  5137,
    5139,  5141,  5143,  5145,  5147,  5149,  5151,  5153,  5155,  5157,
    5159,  5161,  5163,  5165,  5167,  5169,  5171,  5173,  5175,  5177,
    5179,  5181,  5183,  5185,  5187,  5189,  5191,  5193,  5195,  5197,
    5199,  5201,  5203,  5205,  5207,  5209,  5211,  5213,  5215,  5217,
    5219,  5221,  5223,  5225,  5227,  5229,  5231,  5233,  5235,  5237,
    5239,  5241,  5243,  5245,  5247,  5249,  5251,  5253,  5255,  5257,
    5259,  5261,  5263,  5265,  5267,  5269,  5271,  5273,  5275,  5277,
    5279,  5281,  5283,  5285,  5287,  5289,  5291,  5293,  5295,  5297,
    5299,  5301,  5303,  5305,  5307,  5309,  5311,  5313,  5315,  5317,
    5319,  5321,  5323,  5325,  5327,  5329,  5331,  5333,  5335,  5337,
    5339,  5341,  5343,  5345,  5347,  5349,  5351,  5353,  5355,  5357,
    5359,  5361,  5363,  5365,  5367,  5369,  5371,  5373,  5375,  5377,
    5379,  5381,  5383,  5385,  5387,  5389,  5391,  5393,  5395,  5397,
    5399,  5401,  5403,  5405,  5407,  5409,  5411,  5413,  5415,  5417,
    5419,  5421,  5423,  5425,  5427,  5429,  5431,  5433,  5435,  5437,
    5439,  5441,  5443,  5445,  5447,  5449,  5451,  5453,  5455,  5457,
    5459,  5461,  5463,  5465,  5467,  5469,  5471,  5473,  5475,  5477,
    5479,  5481,  5483,  5485,  5487,  5489,  5491,  5493,  5495,  5497,
    5499,  5501,  5503,  5505,  5507,  5509,  5511,  5513,  5515,  5517,
    5519,  5521,  5523,  5525,  5527,  5529,  5531,  5533,  5535,  5537,
    5539,  5541,  5543,  5545,  5547,  5549,  5551,  5553,  5555,  5557,
    5559,  5561,  5563,  5565,  5567,  5569,  5571,  5573,  5575,  5577,
    5579,  5581,  5583,  5585,  5587,  5589,  5591,  5593,  5595,  5597,
    5599,  5601,  5602,  5606,  5607,  5611,  5612,  5613,  5620,  5621,
    5624,  5627,  5635,  5639,  5643,  5646,  5649,  5652,  5654,  5658,
    5660,  5664,  5666,  5670,  5672,  5676,  5678,  5680,  5682,  5685,
    5688,  5690,  5692,  5695,  5700,  5702,  5704,  5706,  5708,  5710,
    5712,  5716,  5719,  5723,  5727,  5731,  5737,  5743,  5749,  5755,
    5761,  5766,  5771,  5775,  5780,  5782,  5784,  5788,  5790,  5793,
    5795,  5797,  5799,  5803,  5809,  5811,  5813,  5815,  5817,  5821,
    5824,  5827,  5830,  5832,  5835,  5838,  5840,  5843,  5846,  5849,
    5851,  5855,  5858,  5860,  5863,  5865,  5868,  5870,  5871,  5872,
    5879,  5880,  5883,  5884,  5886,  5888,  5891,  5894,  5896,  5898,
    5903,  5907,  5909,  5913,  5915,  5918,  5924,  5927,  5930,  5936,
    5937,  5940,  5942,  5944,  5947,  5954,  5961,  5963,  5964,  5966,
    5969,  5971,  5974,  5975,  5978,  5980,  5982,  5984,  5986,  5988,
    5990,  5992,  5994,  5996,  5998,  6000,  6002,  6004,  6006,  6008,
    6010,  6012,  6014,  6016,  6018,  6020,  6022,  6024,  6026,  6028,
    6030,  6032,  6034,  6036,  6038,  6040,  6042,  6044,  6046,  6048,
    6050,  6052,  6054,  6056,  6058,  6060,  6062,  6064,  6066,  6068,
    6070,  6072,  6074,  6076,  6078,  6080,  6082,  6084,  6086,  6088,
    6090,  6092,  6094,  6096,  6098,  6100,  6102,  6104,  6106,  6108,
    6110,  6112,  6114,  6116,  6118,  6120,  6122,  6124,  6126,  6128,
    6130,  6132,  6134,  6136,  6138,  6140,  6142,  6144,  6146,  6148,
    6150,  6152
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
     349,  1110,    -1,    -1,   294,   436,  1501,   397,   349,   705,
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
     365,    -1,    -1,    -1,   344,   732,  1511,    -1,    -1,    -1,
     344,   734,  1511,    -1,    -1,   584,   864,   736,  1511,    -1,
      -1,   584,   864,   738,  1511,    -1,   283,   954,    -1,   207,
     952,    -1,    88,   952,    -1,   173,    -1,   190,  1452,    -1,
     499,   951,    -1,    30,   741,    31,    -1,   742,    -1,   744,
      -1,   743,    -1,   742,   743,    -1,    29,    -1,   745,    -1,
     744,   745,    -1,    28,    -1,   399,    -1,    -1,    -1,   325,
     748,   750,   749,   751,    -1,   390,  1110,   630,   752,   998,
    1023,   693,    -1,  1110,   630,   752,   998,   552,  1501,  1023,
     693,    -1,    -1,   754,   196,    -1,   753,    -1,   752,     5,
     753,    -1,   957,    -1,   957,   625,   957,    -1,   957,   625,
      20,    -1,   755,    -1,   754,   755,    -1,    -1,   275,   761,
     756,  1511,    -1,    -1,   278,   762,   757,  1511,    -1,    -1,
    1026,   758,  1511,    -1,    -1,   171,   759,  1511,    -1,    -1,
     168,   760,  1511,    -1,   961,    -1,   761,     5,   961,    -1,
     961,    -1,   762,     5,   961,    -1,    97,    -1,    98,    -1,
      99,    -1,   100,    -1,   101,    -1,   102,    -1,   436,   857,
     765,   397,    -1,    -1,     5,   808,   631,   811,    -1,   160,
      -1,   284,    -1,    -1,   768,    -1,   769,    -1,   768,   769,
      -1,    -1,    -1,   443,   770,   772,   771,  1217,    -1,   821,
      -1,  1491,    -1,   775,    -1,   772,     5,   775,    -1,    -1,
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
     623,   948,    -1,    75,   957,    -1,    73,    -1,   631,  1501,
      -1,   631,   514,   957,   664,  1501,    -1,   631,   514,   957,
     395,    -1,    77,   957,    -1,   161,   882,  1129,   843,    -1,
     406,   882,   862,   835,   843,    -1,   214,   954,   843,    -1,
      -1,    -1,   193,   840,  1136,   631,   957,   625,    20,   842,
     693,   841,   844,    -1,    -1,   473,   949,    -1,   693,    -1,
      -1,   845,   243,    -1,   846,    -1,   845,   846,    -1,    -1,
     356,   847,  1511,    -1,    -1,   352,   848,  1511,    -1,    -1,
    1026,   849,  1511,    -1,    36,  1110,    -1,    37,  1110,    -1,
      35,  1110,    -1,   503,   882,   863,   693,    -1,   503,   882,
     863,   693,    70,    -1,   291,    -1,   290,    -1,   217,    -1,
     369,    -1,   178,    -1,   216,    -1,   333,    -1,   332,    -1,
     248,    -1,   175,    -1,   174,    -1,   149,    -1,   209,    -1,
     132,    -1,   148,    -1,   192,    -1,   158,    -1,   218,    -1,
     218,   864,    -1,   867,    -1,   866,    -1,   871,    -1,   899,
      -1,   857,   858,    -1,   900,    -1,   902,    -1,   868,    -1,
      19,   857,    -1,    18,   857,    -1,   873,    -1,   881,    -1,
     875,    -1,   480,    -1,   763,    -1,   876,    -1,   877,    -1,
     878,    -1,   879,    -1,   880,    -1,    39,   857,    -1,   882,
      -1,   882,   861,    -1,   864,    -1,   488,    -1,   860,    -1,
     861,     5,   860,    -1,   864,    -1,   862,     5,   864,    -1,
     864,    -1,   863,     5,   864,    -1,   857,    -1,    18,    -1,
      19,    -1,     9,   857,    -1,   489,    -1,   433,    -1,   436,
     857,   397,    -1,   448,   436,  1426,   397,    -1,   299,   436,
    1426,   397,    -1,   865,   963,    -1,   865,    26,    -1,    25,
      -1,   963,    -1,    26,    -1,   870,    -1,  1110,    -1,  1110,
     426,  1110,    -1,   869,    -1,   439,   857,    -1,   398,   857,
      -1,  1220,    -1,    -1,   512,   872,  1220,    -1,     7,   857,
      -1,     6,   857,    -1,   857,    -1,   874,     5,   857,    -1,
     628,   436,  1426,   397,    -1,   434,   436,  1426,   397,    -1,
     628,   436,   882,   874,   397,    -1,   434,   436,   882,   874,
     397,    -1,   392,    -1,   254,    -1,    10,   857,    -1,   257,
     857,    -1,    10,   857,   447,    25,    -1,   257,   857,   447,
      25,    -1,   562,   857,    -1,   376,   857,    -1,   562,   857,
     447,    25,    -1,   376,   857,   447,    25,    -1,   396,    -1,
       8,   857,    -1,    18,   857,    -1,    19,   857,    -1,    20,
     857,    -1,    21,   857,    -1,    22,   857,    -1,    11,   857,
      -1,    14,   857,    -1,   462,   857,    -1,    12,   857,    -1,
      13,   857,    -1,    17,   857,    -1,    16,   857,    -1,    15,
     857,    -1,    -1,    -1,    -1,   957,   436,   884,   720,   885,
     397,    -1,    -1,    -1,   957,   526,   957,   436,   886,   720,
     887,   397,    -1,    -1,    -1,   543,   436,   889,   857,   890,
     397,    -1,    -1,    -1,   518,   436,   891,   857,   892,   397,
      -1,    -1,    -1,   596,   436,   893,   857,   894,   397,    -1,
      -1,    -1,   587,   436,   895,   857,   896,   397,    -1,   374,
     436,   903,   397,   898,    -1,   362,   436,    25,   397,   897,
      -1,   362,   436,    26,   397,   897,    -1,   362,   436,    26,
     595,    26,   397,   897,    -1,   680,   436,  1110,   397,    -1,
     681,   436,  1110,     5,    26,   397,    -1,    -1,  1406,   631,
    1407,    -1,   807,    -1,   888,    -1,   294,   436,  1501,   397,
      -1,   104,   436,   949,   397,    -1,    76,   436,   949,   397,
      -1,   412,   436,  1501,   397,    -1,   197,   436,  1501,   397,
      -1,    64,   436,  1501,   397,    -1,   901,    -1,   883,    -1,
    1402,    -1,   543,    -1,   428,   436,   857,   397,    -1,   327,
     436,   857,   397,    -1,   493,   857,    -1,   449,   764,    -1,
     857,   113,    -1,   857,   114,    -1,   857,   115,    -1,    25,
      -1,   904,    -1,    19,   904,    -1,   906,    -1,   905,    -1,
      26,    -1,    26,    26,    -1,    26,    26,   595,    26,    -1,
      26,    26,   595,    26,   595,    26,    -1,    26,    26,   595,
      26,   595,    24,    -1,    26,   595,    26,    -1,    26,   595,
      26,   595,    26,    -1,    26,   595,    26,   595,    24,    -1,
      26,   595,    24,    -1,    24,    -1,    26,    -1,    26,    19,
      26,    -1,   949,    -1,   907,     5,   949,    -1,    -1,    -1,
     601,  1110,    14,   864,   631,   864,   911,   909,  1511,   910,
     246,    -1,    -1,   577,   864,    -1,    -1,    -1,    -1,   409,
     913,   951,   914,   916,  1307,   915,  1511,   245,    -1,    -1,
       8,   882,   862,    -1,    -1,    -1,   643,   957,   918,   767,
     919,  1055,   921,   920,   926,   644,    -1,    -1,   931,    -1,
      -1,   922,    -1,   923,    -1,   922,   923,    -1,    -1,   645,
     924,  1511,    -1,    -1,   646,   925,  1511,    -1,    -1,   927,
      -1,   928,    -1,   927,   928,    -1,    -1,   647,   929,  1511,
      -1,    -1,   648,   930,  1511,    -1,   932,   936,   329,    -1,
      96,    -1,    96,   933,   552,   934,    -1,    96,   390,   935,
      -1,  1110,    -1,   933,     5,  1110,    -1,   957,    -1,   934,
       5,   957,    -1,  1110,    -1,   935,     5,  1110,    -1,   937,
      -1,   936,   937,    -1,    -1,   649,   938,  1511,    -1,    -1,
     650,   939,  1511,    -1,    -1,   669,   934,   940,  1511,    -1,
      -1,   486,   934,   941,  1511,    -1,    -1,   630,   934,   942,
    1511,    -1,   551,   950,    -1,   560,    19,    26,    -1,   560,
      -1,   506,    18,    26,    -1,   506,    -1,    26,    -1,  1110,
      -1,   674,    -1,    25,    -1,   962,    -1,   864,    -1,   946,
       5,   946,    -1,   947,    -1,   957,    -1,   672,   436,   957,
     397,    -1,   957,   625,   672,   436,   957,   397,    -1,   957,
     464,   690,   432,    -1,   957,   625,    20,    -1,   957,   464,
     690,   432,   625,    20,    -1,   957,   625,   957,    -1,   957,
     464,   690,   432,   625,   957,    -1,   958,    -1,   958,    -1,
     958,    -1,   958,    -1,   958,    -1,   958,    -1,    -1,   556,
      26,    -1,  1510,    -1,   959,    -1,  1510,    -1,   354,   436,
     960,   397,    -1,  1113,    -1,    25,    -1,   957,    -1,   957,
     464,   690,   432,    -1,   957,   625,    20,    -1,   957,   464,
     690,   432,   625,    20,    -1,   957,   625,   957,    -1,   957,
     464,   690,   432,   625,   957,    -1,  1110,    -1,    24,    -1,
     625,    26,    -1,   553,  1493,    -1,   657,   966,    -1,   967,
      -1,   966,     5,   967,    -1,   957,    -1,   668,   966,    -1,
     659,   966,    -1,   660,  1501,    -1,   658,   954,   664,  1501,
      -1,   662,   966,    -1,   663,  1501,    -1,   661,   954,   664,
    1501,    -1,    -1,   666,   972,   862,   977,   979,   981,   973,
     975,    -1,    -1,   974,    -1,   654,    -1,   655,    -1,    -1,
     976,    -1,   349,  1110,    -1,    -1,   978,    -1,   395,   862,
      -1,    -1,   980,    -1,   665,    26,    -1,    -1,   982,    -1,
     656,    26,   983,    -1,    -1,   405,    26,    -1,    -1,    -1,
     627,   864,   581,   985,  1511,   986,   987,   446,    -1,    -1,
      -1,   548,   988,  1511,    -1,    -1,    -1,    67,   989,   864,
     581,   990,  1511,   987,    -1,   111,   957,   436,    26,   397,
      -1,    60,   957,    -1,    80,   957,    -1,    -1,   295,  1141,
     994,   631,   488,    -1,   295,  1141,   562,   995,    -1,   996,
      -1,   995,     5,   996,    -1,   804,   625,  1398,    -1,   804,
     625,    20,    -1,    -1,   999,   329,    -1,    -1,   155,    -1,
    1000,    -1,   999,  1000,    -1,    -1,   275,  1012,  1001,  1511,
      -1,    -1,   278,  1013,  1002,  1511,    -1,    -1,   356,  1003,
    1511,    -1,    -1,   352,  1004,  1511,    -1,    -1,  1026,  1005,
    1511,    -1,    -1,   310,  1006,  1511,    -1,    -1,   280,  1007,
    1511,    -1,    -1,    40,  1008,  1511,    -1,    -1,    38,  1009,
    1511,    -1,    -1,    42,  1010,  1511,    -1,    -1,    41,  1011,
    1511,    -1,   949,    -1,  1012,     5,   949,    -1,   949,    -1,
    1013,     5,   949,    -1,   319,  1016,    -1,   320,   957,   664,
    1016,    -1,   567,    -1,   380,    -1,   949,    -1,    -1,   670,
    1019,  1018,   997,    -1,   390,  1129,   998,   956,   693,    -1,
    1129,   998,   552,  1501,   956,   693,    -1,    -1,   492,  1136,
     998,   552,   957,   625,    20,   956,  1020,   693,    -1,   474,
    1501,  1022,    -1,    86,    26,    -1,    87,    26,    -1,   632,
      -1,   545,    -1,    -1,   556,    26,    -1,  1025,    -1,    48,
      25,    -1,   501,    14,    26,    -1,   501,    14,  1110,    -1,
      49,    14,    26,    -1,    49,    14,  1110,    -1,    45,    -1,
      47,    -1,    44,    -1,    46,    -1,    -1,   435,  1027,  1032,
      -1,   300,    -1,    -1,   602,  1029,  1032,    -1,   308,  1034,
      -1,   602,  1032,    -1,  1034,    -1,   436,  1033,   397,    -1,
    1034,    -1,  1033,     5,  1034,    -1,  1035,    -1,   600,    -1,
     317,    -1,   335,    -1,   309,    -1,   490,    -1,   447,    -1,
     632,    -1,   556,    -1,   545,    -1,   182,    -1,   444,    -1,
     455,    -1,   546,    -1,   561,    -1,   525,    -1,   315,    -1,
     316,    -1,    25,    -1,   515,    -1,    -1,    -1,   604,  1038,
    1134,  1039,    14,   882,  1040,    -1,   488,    -1,   863,    -1,
     224,  1110,    -1,   213,  1110,    -1,   227,  1110,    -1,   456,
    1110,   338,    -1,   456,  1110,   391,   945,    -1,    -1,  1047,
    1046,  1050,    -1,    -1,  1048,    -1,  1049,    -1,  1048,  1049,
      -1,   992,    -1,  1054,    -1,  1070,    -1,  1056,    -1,    -1,
    1051,    -1,  1053,    -1,  1051,  1053,    -1,    71,   957,    -1,
    1058,    -1,  1064,    -1,  1076,    -1,  1230,    -1,  1240,    -1,
    1097,    -1,  1491,    -1,   917,    -1,   740,    -1,   991,    -1,
     746,    -1,   740,    -1,  1491,    -1,    -1,   740,    -1,  1491,
      -1,   768,    -1,   372,    -1,    65,    -1,    -1,    -1,    -1,
      -1,  1057,  1059,   957,   436,  1060,  1127,   397,  1061,   767,
    1062,  1055,  1511,  1063,    -1,   215,    -1,    -1,    -1,   563,
    1065,   767,  1066,  1511,   366,    -1,   182,   859,    -1,   882,
      -1,   882,   862,    -1,   361,  1410,    -1,   472,  1410,    -1,
    1071,    -1,  1072,    -1,  1071,  1072,    -1,  1073,    -1,  1054,
      -1,  1069,    -1,    -1,   411,  1074,  1075,    -1,   767,   247,
      -1,   945,    -1,    -1,    -1,    -1,   118,   957,   117,   957,
     436,  1077,  1127,   397,  1078,   767,  1079,  1055,  1511,  1063,
      -1,    -1,   564,  1081,  1096,  1087,  1082,    -1,   367,    -1,
      -1,   239,  1084,  1511,    -1,    -1,    23,  1088,  1089,  1090,
     956,  1085,  1511,    -1,    -1,    23,  1088,   956,  1086,  1511,
      -1,  1083,    -1,  1087,  1083,    -1,    -1,  1028,    -1,    25,
      -1,  1110,    -1,    -1,  1110,    -1,    25,    -1,   256,  1094,
      -1,   268,  1095,    -1,   251,  1095,    -1,   591,    -1,    25,
      -1,  1110,    -1,  1094,    -1,  1095,     5,  1094,    -1,  1110,
      -1,    25,    -1,    -1,    -1,   651,   957,  1098,   767,  1099,
    1100,   652,    -1,  1101,    -1,  1100,  1101,    -1,    -1,   653,
    1102,  1511,    -1,    -1,   630,   957,  1103,  1511,    -1,  1107,
    1105,    -1,    -1,   694,  1108,    -1,  1109,    -1,  1106,    -1,
     978,    -1,   980,    -1,   982,    -1,   974,    -1,   976,    -1,
     375,   882,   862,    -1,    -1,    70,    -1,    70,    -1,  1111,
      -1,  1113,    -1,   195,  1113,    -1,  1113,   625,    -1,  1112,
    1117,    -1,  1112,   957,   464,  1121,   432,    -1,  1112,   957,
     464,  1121,   432,   464,  1121,   432,    -1,  1118,    -1,   957,
      -1,  1114,    -1,   957,   463,  1116,   431,    -1,   957,   463,
    1116,   431,    -1,  1110,    -1,    25,    -1,    20,    -1,   957,
      -1,   957,  1120,    -1,   957,  1120,    -1,   464,  1121,   432,
      -1,   464,  1121,   432,   464,  1121,   432,    -1,  1122,    -1,
    1121,     5,  1122,    -1,   690,    -1,  1124,    -1,  1126,    -1,
    1124,   625,  1125,    -1,  1124,   625,   957,   464,  1121,   432,
      -1,  1124,   625,   957,   464,  1121,   432,   464,  1121,   432,
      -1,   957,    -1,  1115,    -1,    20,    -1,   957,    -1,   957,
    1120,    -1,    -1,  1128,    -1,  1130,    -1,  1128,     5,  1130,
      -1,  1131,    -1,  1129,     5,  1131,    -1,   957,    -1,   957,
     625,   957,    -1,  1110,    -1,  1110,   426,  1110,    -1,    25,
      -1,   963,    -1,    26,    -1,  1133,    -1,  1132,     5,  1133,
      -1,  1110,    -1,  1110,   426,  1110,    -1,  1135,    -1,  1134,
       5,  1135,    -1,  1123,    -1,  1110,    -1,  1138,    -1,  1137,
       5,  1138,    -1,  1110,  1139,    -1,    -1,   593,    -1,   544,
      -1,   957,   464,  1121,   432,    -1,  1142,    -1,  1141,     5,
    1142,    -1,  1110,    -1,  1110,   426,  1110,    -1,   259,   953,
     623,   947,   585,  1503,   698,    -1,    -1,   623,   436,   864,
       5,   864,   397,  1145,    -1,    -1,   574,   436,   864,     5,
     864,   397,    -1,   260,   957,  1144,    -1,   957,    -1,   343,
     955,  1149,    -1,  1150,    -1,   552,   864,    -1,  1151,  1152,
    1157,     8,  1147,    -1,    -1,   623,  1153,   436,   864,     5,
     864,   397,    -1,    -1,   562,   958,    -1,    -1,   355,    -1,
     222,  1452,   271,  1486,  1156,    -1,   569,   950,    -1,   569,
     950,     8,   882,   862,    -1,    -1,   622,   582,  1446,   379,
    1446,    -1,   622,   582,  1446,     5,   379,  1446,    -1,   622,
    1446,     5,  1446,    -1,    -1,   654,    -1,   655,    -1,    95,
    1486,  1159,  1160,    -1,    -1,   622,  1486,    -1,    -1,   622,
     582,  1446,     8,  1446,    -1,   582,  1446,     8,  1446,    -1,
     417,  1162,    -1,  1163,    -1,  1162,     5,  1163,    -1,   208,
     944,    -1,   289,   944,    -1,   334,   944,    -1,   342,   944,
      -1,   298,   944,    -1,   264,   944,    -1,  1030,    -1,   444,
    1031,    -1,   455,  1031,    -1,   567,  1031,    -1,   380,  1031,
      -1,   556,  1031,    -1,   554,   945,    -1,   555,   945,    -1,
     406,   694,    -1,   670,   694,    -1,   296,    -1,   200,    -1,
     156,    -1,   133,    -1,   151,    -1,   142,    -1,  1451,   419,
    1167,   552,  1165,    -1,  1110,    -1,    25,    -1,   408,  1167,
      -1,   408,  1167,     8,  1129,    -1,    43,  1165,    -1,   958,
      -1,    -1,   467,  1177,   693,   601,  1172,  1110,  1170,   956,
     693,  1169,  1173,    -1,    -1,   673,    26,    -1,   467,  1177,
     693,   349,  1110,    -1,    -1,   541,    -1,    -1,  1174,   287,
      -1,  1175,    -1,  1174,  1175,    -1,    -1,  1026,  1176,  1511,
      -1,   863,    -1,    -1,   609,   950,  1179,  1180,    -1,    -1,
     552,  1181,    -1,  1182,    -1,  1181,     5,  1182,    -1,  1438,
      -1,   488,    -1,   225,  1185,    93,    -1,   225,  1185,   631,
    1184,    -1,   225,  1185,    92,  1184,    -1,   225,  1185,    -1,
      25,    -1,   962,    -1,   957,    -1,    -1,   484,    -1,   150,
    1185,  1186,   436,   882,  1068,   397,    -1,   198,  1185,    -1,
      72,  1185,    -1,  1221,  1229,    -1,   452,    66,    -1,   452,
    1192,    -1,  1193,    -1,  1192,  1193,    -1,    -1,   138,  1194,
    1511,    -1,    -1,   204,  1195,  1511,    -1,    -1,   233,  1196,
    1511,    -1,    -1,   221,  1197,  1511,    -1,    -1,   258,  1198,
    1511,    -1,    -1,   206,  1110,  1199,  1511,    -1,    -1,   229,
    1110,  1200,  1511,    -1,  1211,    -1,  1213,    -1,  1212,    -1,
    1202,    -1,  1238,    -1,  1205,    -1,    -1,   566,   864,  1203,
     487,    -1,    -1,   487,    -1,    -1,   575,    26,  1206,  1204,
      -1,   163,    -1,   634,  1225,    -1,   166,  1225,    -1,   165,
    1225,    -1,    -1,  1208,    -1,  1209,    -1,  1208,  1209,    -1,
    1218,  1210,    -1,    -1,   623,  1225,    -1,   524,  1207,  1217,
      -1,   523,  1446,  1217,    -1,   522,  1216,  1215,  1214,  1217,
      -1,    -1,   157,   857,    -1,   157,   857,     5,   857,    -1,
     618,    -1,   619,    -1,   620,    -1,   621,    -1,  1110,    -1,
      -1,   527,    -1,  1219,    -1,  1218,     5,  1219,    -1,   864,
    1252,    -1,   614,   436,   857,   397,  1237,    -1,    69,  1237,
      -1,   501,   436,    20,   397,  1237,    -1,   418,   436,    20,
     397,  1237,    -1,   393,   436,   857,   397,  1237,    -1,   594,
     436,   857,   397,  1237,    -1,   607,   436,   857,   397,  1237,
      -1,   606,   436,   857,   397,  1237,    -1,    -1,   466,  1222,
      -1,  1223,    -1,  1222,  1223,    -1,   232,    26,    -1,   223,
      26,    -1,   306,    26,    -1,   189,    26,    -1,   261,    26,
      -1,   180,    -1,   348,    25,    -1,   348,  1110,    -1,   181,
      25,    -1,   164,    25,    -1,  1228,    -1,  1224,  1228,    -1,
    1226,   113,    -1,  1226,   115,    -1,  1226,   114,    -1,  1226,
      -1,   963,    -1,    26,    -1,    -1,   466,  1224,    -1,   232,
    1225,    -1,   223,  1225,    -1,   306,  1225,    -1,   189,  1225,
      -1,   261,  1225,    -1,   262,  1225,    -1,   633,    25,    -1,
     634,  1225,    -1,   638,    -1,   635,    -1,   636,    -1,   637,
      -1,   642,    -1,   639,    -1,   640,    -1,   641,    -1,    81,
    1225,    -1,    82,  1225,    -1,    83,  1225,    -1,   348,    25,
      -1,   181,    25,    -1,   405,    -1,    78,    -1,    79,    -1,
      -1,   519,   624,  1137,    -1,   139,  1137,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   470,  1231,   957,   436,  1232,  1127,
     397,  1233,   767,  1234,  1190,  1235,  1191,  1236,   244,    -1,
      -1,   531,   857,    -1,   521,  1239,    -1,    -1,  1165,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   110,  1241,   957,   436,
    1242,  1127,   397,  1243,   767,  1244,  1247,  1245,  1191,  1246,
     244,    -1,  1227,  1229,    -1,    -1,    -1,    -1,   159,   436,
      25,     5,  1249,   720,  1250,   397,  1251,   718,    -1,    -1,
     389,    -1,   389,   223,    26,    -1,   389,   223,  1110,    -1,
     612,   864,    -1,   612,   864,   349,  1110,    -1,   612,   864,
     167,    -1,   612,   864,   583,    -1,   612,   864,   550,    -1,
    1255,    -1,   177,    -1,   328,    -1,   286,    -1,  1262,    -1,
    1257,    -1,    -1,    -1,   211,  1258,  1395,   436,  1259,  1266,
     397,    -1,    -1,    -1,   136,  1260,  1395,   436,  1261,  1266,
     397,  1263,    -1,   108,  1264,   397,    -1,    59,   958,    -1,
      -1,   273,    -1,  1265,    -1,  1264,     5,  1265,    -1,   957,
     593,    -1,   957,   544,    -1,   957,    -1,  1267,    -1,  1266,
       5,  1267,    -1,  1348,    -1,  1346,    -1,   125,   957,    -1,
     184,    -1,    50,   957,  1270,    -1,  1271,    -1,  1270,     5,
    1271,    -1,  1272,    -1,  1275,    -1,  1278,    -1,  1283,    -1,
    1284,    -1,  1282,    -1,  1281,    -1,   590,  1273,    -1,   590,
     436,  1274,   397,    -1,  1267,    -1,  1267,   669,   957,    -1,
    1273,    -1,  1274,     5,  1273,    -1,   547,  1277,    -1,   547,
     436,  1276,   397,    -1,  1277,    -1,  1276,     5,  1277,    -1,
     957,    -1,   460,  1280,    -1,   460,   436,  1279,   397,    -1,
    1280,    -1,  1279,     5,  1280,    -1,  1267,    -1,    90,    -1,
      91,    -1,    89,    26,    -1,    61,  1352,    -1,    61,   436,
    1285,   397,    -1,    62,  1286,    -1,    62,   436,  1285,   397,
      -1,  1352,    -1,  1285,     5,  1352,    -1,   957,    -1,   270,
      -1,   236,    -1,   169,  1289,    -1,   146,    -1,   134,    -1,
     124,    -1,   122,    -1,   126,    -1,   183,  1452,    -1,   235,
    1288,   465,  1446,   631,  1446,    -1,   303,   950,   465,  1446,
     631,  1446,    -1,    -1,  1452,    -1,    -1,   864,    -1,   528,
     864,    -1,   234,    -1,    -1,   253,  1293,  1395,  1296,  1294,
      -1,    -1,   484,  1295,   436,  1298,   397,    -1,  1432,    -1,
      -1,   436,  1297,   397,    -1,  1398,    -1,  1297,     5,  1398,
      -1,  1299,    -1,  1298,     5,  1299,    -1,  1438,    -1,   488,
      -1,    -1,    -1,   505,  1301,  1304,  1302,  1305,    -1,   958,
      -1,  1309,   951,    -1,   951,    -1,    -1,    -1,   559,  1306,
    1132,    -1,    -1,    -1,   559,  1308,  1132,    -1,   506,    -1,
     560,    -1,   567,    -1,   380,    -1,   346,    -1,   401,    -1,
     383,   864,    -1,   355,   864,    -1,   242,  1395,   154,   951,
      -1,   242,  1395,  1368,    -1,   519,   624,  1313,    -1,  1314,
      -1,  1313,     5,  1314,    -1,  1315,  1316,    -1,    26,    -1,
    1398,    -1,    -1,   593,    -1,   544,    -1,   281,    -1,   314,
      -1,    -1,   331,    -1,   361,  1321,  1319,    -1,  1486,    -1,
      25,    -1,    -1,  1451,  1323,  1324,    -1,  1353,    -1,  1357,
      -1,  1318,    -1,  1453,    -1,  1317,    -1,  1310,    -1,  1311,
      -1,  1300,    -1,  1292,    -1,  1291,    -1,  1422,    -1,  1470,
      -1,   510,  1327,   630,  1395,   631,  1332,  1326,    -1,    -1,
     145,    -1,   172,    -1,  1328,    -1,  1329,    -1,  1328,     5,
    1329,    -1,   476,    -1,   455,    -1,   444,    -1,   483,  1330,
      -1,    -1,   436,  1331,   397,    -1,  1398,    -1,  1331,     5,
    1398,    -1,  1333,    -1,  1332,     5,  1333,    -1,   468,    -1,
    1396,    -1,   240,  1395,  1335,   622,  1432,  1337,    -1,    -1,
     436,  1336,   397,    -1,  1398,    -1,  1336,     5,  1398,    -1,
      -1,   144,    -1,   497,   436,  1371,   397,    -1,   250,   436,
    1341,   397,  1340,    -1,   301,  1342,    -1,  1343,    -1,  1395,
      -1,  1395,   436,  1343,   397,    -1,  1398,    -1,  1343,     5,
    1398,    -1,   481,   436,  1345,   397,    -1,   263,   436,  1345,
     397,    -1,  1398,    -1,  1345,     5,  1398,    -1,  1344,    -1,
    1339,    -1,  1338,    -1,   405,  1401,    -1,   212,    -1,   957,
    1387,  1349,  1350,    -1,    -1,  1347,    -1,    -1,  1351,    -1,
    1352,    -1,  1351,  1352,    -1,   378,    -1,   162,    -1,   481,
      -1,  1340,    -1,   497,   436,  1371,   397,    -1,   123,  1354,
    1356,    -1,  1355,    -1,  1396,    -1,  1357,    -1,  1356,  1357,
      -1,  1334,    -1,  1325,    -1,   453,  1371,    -1,   373,  1360,
      -1,  1437,    -1,  1360,     5,  1437,    -1,   531,  1371,    -1,
     552,  1363,    -1,  1364,    -1,  1363,     5,  1364,    -1,  1365,
      -1,   520,  1365,    -1,   520,   436,  1366,   397,    -1,  1395,
      -1,  1395,  1400,    -1,  1364,    -1,  1366,     5,  1364,    -1,
    1362,  1368,  1369,  1370,    -1,    -1,  1361,    -1,    -1,  1359,
      -1,    -1,  1358,    -1,  1372,    -1,  1371,     6,  1372,    -1,
    1373,    -1,  1372,     7,  1373,    -1,  1374,    -1,     9,  1374,
      -1,  1385,    -1,   436,  1371,   397,    -1,   448,  1433,    -1,
     299,  1433,    -1,    -1,   447,  1378,    -1,  1439,    -1,  1442,
      -1,  1438,   628,   436,  1380,   397,    -1,  1438,   628,  1433,
      -1,  1438,   434,   436,  1380,   397,    -1,  1438,   434,  1433,
      -1,  1381,    -1,  1380,     5,  1381,    -1,  1490,    -1,  1401,
      -1,    -1,     9,    -1,  1438,  1382,   392,    -1,  1438,  1382,
     254,    -1,  1438,  1384,  1438,    -1,  1438,  1382,   394,  1438,
       7,  1438,    -1,  1438,   562,  1377,  1376,    -1,  1438,   376,
    1377,  1376,    -1,  1438,   679,  1377,  1376,    -1,  1438,   377,
    1377,  1376,    -1,  1438,  1382,    10,  1377,  1376,    -1,    14,
      -1,    17,    -1,    12,    -1,    13,    -1,   257,    -1,    10,
      -1,   678,    -1,    16,    -1,    15,    -1,  1383,    -1,  1379,
      -1,  1375,    -1,    -1,   591,    -1,   364,    -1,   481,    -1,
    1388,    -1,  1389,    -1,  1391,    -1,   541,    -1,   541,   436,
    1392,   397,    -1,   416,   436,  1393,  1390,   397,    -1,   477,
      -1,   403,   436,  1393,  1390,   397,    -1,   517,   436,  1393,
    1390,   397,    -1,   543,    -1,   413,    -1,   385,    -1,   362,
    1408,   631,  1409,    -1,   362,    -1,   374,  1408,   631,  1409,
      -1,   374,    -1,   374,  1408,   436,    26,   397,   631,  1409,
      -1,   580,    -1,   538,    -1,   429,    -1,   429,   436,    26,
     397,    -1,   429,   436,    26,     5,    26,   397,    -1,    -1,
       5,  1394,    -1,   507,   436,  1393,   397,    -1,   571,    -1,
     304,    -1,   507,    -1,    68,    -1,    26,    -1,    26,    -1,
      26,    -1,    25,   625,   957,    -1,    25,    -1,   957,    -1,
     957,   595,   957,    -1,   957,    -1,    -1,   464,    26,   432,
      -1,   464,    26,     5,    26,   432,    -1,  1399,    -1,   617,
    1399,    -1,   957,  1397,    -1,  1395,   625,   957,  1397,    -1,
    1395,   625,    20,    -1,   957,    -1,    25,    -1,   416,    -1,
     963,    -1,    26,    -1,  1403,    -1,   401,  1405,    -1,   401,
    1404,    -1,    -1,  1408,   631,  1409,    -1,    -1,  1406,   631,
    1406,    -1,   587,    -1,   518,    -1,   596,    -1,   558,    -1,
     459,    -1,   475,    -1,   371,    -1,   371,   436,    26,   397,
      -1,   587,    -1,   518,    -1,   596,    -1,   558,    -1,   459,
      -1,   475,    -1,   371,    -1,   371,   436,    26,   397,    -1,
     587,    -1,   518,    -1,   596,    -1,   558,    -1,   459,    -1,
     475,    -1,   371,    -1,   587,    -1,   518,    -1,   596,    -1,
     558,    -1,   459,    -1,   475,    -1,   371,    -1,   957,    -1,
      25,    -1,  1451,   508,   951,    -1,    -1,  1451,   404,  1303,
     442,   601,  1420,  1413,    -1,    -1,  1451,   404,  1303,   442,
     105,   601,  1421,  1414,    -1,    -1,  1451,   404,  1303,   140,
    1421,  1415,    -1,    -1,  1451,   404,  1303,   141,   105,   601,
    1421,  1416,    -1,    -1,   293,    -1,   292,  1418,    -1,  1419,
      -1,  1418,     5,  1419,    -1,   957,    -1,   957,   625,   957,
      -1,    25,   625,   957,   625,   957,    -1,  1421,    -1,  1292,
      -1,  1167,    -1,  1423,    -1,  1423,    -1,    -1,    -1,   476,
    1434,  1424,  1435,  1425,  1431,  1367,  1429,  1417,    -1,   476,
    1434,  1435,  1367,  1429,    -1,  1428,    -1,  1446,    -1,   476,
    1434,  1435,  1431,  1367,  1429,    -1,    -1,   530,  1386,  1427,
      -1,  1312,    -1,   336,  1430,  1263,    -1,  1312,   336,  1430,
    1263,    -1,   957,    -1,    -1,   559,  1132,    -1,   476,  1434,
    1435,  1367,    -1,   436,   476,  1434,  1435,  1367,   397,    -1,
      -1,   591,    -1,   364,    -1,   481,    -1,  1436,    -1,  1435,
       5,  1436,    -1,  1438,    -1,  1438,   957,    -1,  1438,    -1,
    1439,    -1,    19,  1439,    -1,    18,  1439,    -1,  1440,    -1,
    1490,    -1,  1433,    -1,   617,   957,    -1,   617,   957,   625,
     957,    -1,  1439,    21,  1438,    -1,  1439,  1460,    -1,  1439,
      20,  1438,    -1,  1439,    18,  1438,    -1,  1439,    19,  1438,
      -1,  1401,    -1,   489,    -1,   433,    -1,   582,    -1,    20,
      -1,    69,    -1,   594,   436,  1386,  1438,   397,    -1,   606,
     436,  1386,  1438,   397,    -1,   607,   436,  1386,  1438,   397,
      -1,   614,   436,  1386,  1438,   397,    -1,   501,   436,  1386,
    1438,   397,    -1,   957,   436,  1441,   397,    -1,   543,   436,
    1441,   397,    -1,   436,  1438,   397,    -1,   449,   436,  1461,
     397,    -1,  1438,    -1,  1441,     5,  1438,    -1,  1401,    -1,
    1451,   351,  1450,  1445,  1427,    -1,  1451,   340,  1450,  1445,
     253,  1395,  1447,    -1,  1451,   340,  1450,  1445,  1110,    -1,
      -1,   326,  1446,    -1,    25,    -1,  1110,    -1,    -1,   436,
    1448,   397,    -1,  1449,    -1,  1448,     5,  1449,    -1,   957,
      -1,    25,    -1,  1110,    -1,    -1,   272,  1452,   601,    -1,
     958,    -1,  1458,    -1,  1457,    -1,  1454,    -1,   321,  1455,
     631,  1455,    -1,   302,  1455,   625,  1456,   631,  1456,    -1,
     957,    -1,   957,    -1,   226,   804,    -1,   297,   804,  1459,
      -1,   276,    -1,   179,    -1,    97,    -1,    98,    -1,    99,
      -1,   100,    -1,   101,    -1,   102,    -1,   401,     5,  1408,
     631,  1409,    -1,  1490,     5,  1408,   631,  1409,    -1,   401,
    1408,   631,  1409,    -1,    -1,   613,  1463,  1464,   194,    -1,
    1465,    -1,  1464,  1465,    -1,    33,    -1,  1466,    -1,  1468,
      -1,   355,    -1,   309,    -1,   228,    -1,   590,    -1,   486,
      -1,   591,    -1,   491,    -1,   535,    -1,   592,    -1,   119,
      -1,   492,    -1,   622,    -1,   593,    -1,   322,    -1,   493,
      -1,   323,    -1,   623,    -1,   617,    -1,   279,    -1,   494,
      -1,   188,    -1,   393,    -1,   594,    -1,   669,    -1,   394,
      -1,   495,    -1,   496,    -1,   536,    -1,   537,    -1,   437,
      -1,   438,    -1,   357,    -1,   656,    -1,   624,    -1,   538,
      -1,   395,    -1,   540,    -1,   534,    -1,   541,    -1,   324,
      -1,   497,    -1,   498,    -1,   396,    -1,   499,    -1,   397,
      -1,   432,    -1,   500,    -1,   595,    -1,   439,    -1,   398,
      -1,     5,    -1,    23,    -1,   399,    -1,   440,    -1,   400,
      -1,   359,    -1,   358,    -1,   325,    -1,   360,    -1,   501,
      -1,   441,    -1,   401,    -1,   442,    -1,   542,    -1,   361,
      -1,   543,    -1,   362,    -1,   596,    -1,   597,    -1,   402,
      -1,   598,    -1,   403,    -1,   404,    -1,   405,    -1,   363,
      -1,   502,    -1,   443,    -1,   444,    -1,   326,    -1,   544,
      -1,   285,    -1,   599,    -1,   660,    -1,   406,    -1,   364,
      -1,    21,    -1,   625,    -1,   445,    -1,   327,    -1,   547,
      -1,    67,    -1,   548,    -1,   663,    -1,   407,    -1,    14,
      -1,   503,    -1,   447,    -1,   504,    -1,   331,    -1,   549,
      -1,   408,    -1,   448,    -1,   550,    -1,   449,    -1,   450,
      -1,   370,    -1,   539,    -1,   505,    -1,   104,    -1,   197,
      -1,   451,    -1,   506,    -1,   600,    -1,   507,    -1,   508,
      -1,   601,    -1,   409,    -1,   410,    -1,   452,    -1,   643,
      -1,    96,    -1,   109,    -1,   509,    -1,   371,    -1,   551,
      -1,   552,    -1,   372,    -1,   294,    -1,   411,    -1,   626,
      -1,   553,    -1,   510,    -1,    13,    -1,   511,    -1,   512,
      -1,   453,    -1,   454,    -1,   556,    -1,   557,    -1,   558,
      -1,   665,    -1,    76,    -1,   627,    -1,   628,    -1,   115,
      -1,   513,    -1,   412,    -1,   295,    -1,   670,    -1,   455,
      -1,   413,    -1,   335,    -1,   374,    -1,   672,    -1,   337,
      -1,   602,    -1,   545,    -1,   664,    -1,   514,    -1,   487,
      -1,   375,    -1,   603,    -1,   632,    -1,   414,    -1,     7,
      -1,   433,    -1,   588,    -1,   488,    -1,     6,    -1,   489,
      -1,     8,    -1,   560,    -1,   561,    -1,    12,    -1,   604,
      -1,   562,    -1,   516,    -1,   456,    -1,   605,    -1,   415,
      -1,   563,    -1,   457,    -1,    10,    -1,    49,    -1,   458,
      -1,   564,    -1,   651,    -1,   666,    -1,    19,    -1,   459,
      -1,   114,    -1,    22,    -1,   565,    -1,   460,    -1,   517,
      -1,   518,    -1,    20,    -1,   566,    -1,   567,    -1,   315,
      -1,   568,    -1,   461,    -1,     9,    -1,   416,    -1,   629,
      -1,   674,    -1,   630,    -1,   569,    -1,   436,    -1,   464,
      -1,   465,    -1,   417,    -1,   519,    -1,   344,    -1,   520,
      -1,   466,    -1,   608,    -1,   379,    -1,   521,    -1,   159,
      -1,   110,    -1,   418,    -1,    18,    -1,   113,    -1,   345,
      -1,   419,    -1,   116,    -1,   380,    -1,   316,    -1,   524,
      -1,   346,    -1,   347,    -1,   420,    -1,   467,    -1,   468,
      -1,   609,    -1,   570,    -1,   381,    -1,   571,    -1,   469,
      -1,   421,    -1,   610,    -1,   301,    -1,   382,    -1,   383,
      -1,   470,    -1,   384,    -1,   182,    -1,   349,    -1,   422,
      -1,   471,    -1,   525,    -1,   266,    -1,   611,    -1,   572,
      -1,   612,    -1,   472,    -1,   474,    -1,   475,    -1,   423,
      -1,   476,    -1,   527,    -1,   477,    -1,   424,    -1,   479,
      -1,   573,    -1,   490,    -1,   574,    -1,   575,    -1,   528,
      -1,   304,    -1,   385,    -1,   576,    -1,   480,    -1,   613,
      -1,   305,    -1,    94,    -1,   577,    -1,   578,    -1,   614,
      -1,   425,    -1,   546,    -1,   579,    -1,   120,    -1,   580,
      -1,   581,    -1,   426,    -1,   673,    -1,   631,    -1,   615,
      -1,   427,    -1,   529,    -1,   203,    -1,   350,    -1,   530,
      -1,   481,    -1,   482,    -1,   483,    -1,   428,    -1,   616,
      -1,   582,    -1,   386,    -1,   484,    -1,   429,    -1,   354,
      -1,   583,    -1,   430,    -1,   584,    -1,   387,    -1,   531,
      -1,   532,    -1,   533,    -1,   585,    -1,   389,    -1,   586,
      -1,   606,    -1,   607,    -1,   589,    -1,   587,    -1,   485,
      -1,    -1,   195,  1467,  1490,    -1,    -1,   559,  1469,  1132,
      -1,    -1,    -1,   483,  1395,  1471,  1474,  1472,  1473,    -1,
      -1,   154,   951,    -1,   531,  1371,    -1,    57,  1478,   397,
      14,   436,  1479,   397,    -1,    53,  1479,   397,    -1,    54,
    1479,   397,    -1,   589,  1475,    -1,    56,  1479,    -1,    55,
    1479,    -1,  1477,    -1,  1475,     5,  1477,    -1,  1398,    -1,
    1476,    14,  1480,    -1,  1476,    -1,  1478,     5,  1476,    -1,
    1480,    -1,  1479,     5,  1480,    -1,   488,    -1,  1481,    -1,
    1482,    -1,    19,  1482,    -1,    18,  1482,    -1,  1484,    -1,
    1433,    -1,   617,   957,    -1,   617,   957,   625,   957,    -1,
    1483,    -1,  1401,    -1,   489,    -1,   433,    -1,   582,    -1,
      69,    -1,  1482,    21,  1481,    -1,  1482,  1460,    -1,  1482,
      20,  1481,    -1,  1482,    18,  1481,    -1,  1482,    19,  1481,
      -1,   594,   436,  1386,  1481,   397,    -1,   606,   436,  1386,
    1481,   397,    -1,   607,   436,  1386,  1481,   397,    -1,   614,
     436,  1386,  1481,   397,    -1,   501,   436,  1386,  1481,   397,
      -1,   957,   436,  1485,   397,    -1,   543,   436,  1485,   397,
      -1,   436,  1481,   397,    -1,   449,   436,  1461,   397,    -1,
    1490,    -1,  1481,    -1,  1485,     5,  1481,    -1,  1487,    -1,
     195,  1488,    -1,  1488,    -1,  1119,    -1,   957,    -1,  1488,
     625,  1489,    -1,    25,   625,  1488,   625,  1489,    -1,    20,
      -1,  1140,    -1,   957,    -1,  1487,    -1,  1487,   426,  1487,
      -1,   131,  1492,    -1,   135,  1492,    -1,   130,  1492,    -1,
      51,    -1,   170,  1492,    -1,   128,  1492,    -1,    52,    -1,
     153,  1492,    -1,   152,  1492,    -1,   127,  1492,    -1,   360,
      -1,   626,   631,  1493,    -1,   553,  1493,    -1,   578,    -1,
     539,  1494,    -1,   957,    -1,   595,   957,    -1,   957,    -1,
      -1,    -1,   532,  1496,   864,  1497,  1511,   330,    -1,    -1,
     664,  1501,    -1,    -1,   667,    -1,   186,    -1,   282,   952,
      -1,    74,   952,    -1,   312,    -1,   311,    -1,   313,   954,
    1498,  1499,    -1,   498,  1501,  1499,    -1,   949,    -1,  1501,
       5,   949,    -1,   107,    -1,   137,   952,    -1,   864,   572,
       5,   864,   398,    -1,   514,   864,    -1,   269,   952,    -1,
     106,  1506,     8,  1507,  1505,    -1,    -1,   552,   864,    -1,
     957,    -1,   957,    -1,   252,   952,    -1,   255,   952,   631,
     864,     5,   864,    -1,   255,   952,   624,   864,     5,   864,
      -1,    27,    -1,    -1,  1513,    -1,  1514,  1217,    -1,  1512,
      -1,  1513,  1512,    -1,    -1,  1515,  1516,    -1,   683,    -1,
     684,    -1,   685,    -1,   686,    -1,   703,    -1,   725,    -1,
     739,    -1,   740,    -1,   746,    -1,   747,    -1,   766,    -1,
     836,    -1,   837,    -1,   838,    -1,   839,    -1,   850,    -1,
     851,    -1,   852,    -1,   853,    -1,   854,    -1,   855,    -1,
     856,    -1,   908,    -1,   912,    -1,   943,    -1,   964,    -1,
     965,    -1,   968,    -1,   969,    -1,   970,    -1,   971,    -1,
     984,    -1,   993,    -1,  1014,    -1,  1015,    -1,  1017,    -1,
    1021,    -1,  1036,    -1,  1037,    -1,  1041,    -1,  1042,    -1,
    1043,    -1,  1044,    -1,  1052,    -1,  1067,    -1,  1080,    -1,
    1091,    -1,  1092,    -1,  1093,    -1,  1104,    -1,  1143,    -1,
    1146,    -1,  1148,    -1,  1154,    -1,  1155,    -1,  1158,    -1,
    1161,    -1,  1164,    -1,  1166,    -1,  1168,    -1,  1171,    -1,
    1178,    -1,  1183,    -1,  1187,    -1,  1188,    -1,  1189,    -1,
    1201,    -1,  1253,    -1,  1254,    -1,  1256,    -1,  1268,    -1,
    1269,    -1,  1287,    -1,  1290,    -1,  1320,    -1,  1322,    -1,
    1411,    -1,  1412,    -1,  1443,    -1,  1444,    -1,  1462,    -1,
    1491,    -1,  1495,    -1,  1500,    -1,  1502,    -1,  1504,    -1,
    1508,    -1,  1509,    -1
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
    2239,  2245,  2250,  2254,  2250,  2265,  2267,  2272,  2277,  2277,
    2281,  2281,  2284,  2284,  2290,  2290,  2296,  2296,  2306,  2324,
    2330,  2354,  2357,  2371,  2373,  2375,  2377,  2379,  2381,  2383,
    2389,  2391,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2413,
    2428,  2431,  2444,  2445,  2446,  2447,  2448,  2452,  2453,  2454,
    2458,  2463,  2470,  2471,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2480,  2487,  2487,  2492,  2492,  2495,  2501,  2509,
    2515,  2525,  2526,  2534,  2541,  2545,  2555,  2559,  2564,  2569,
    2571,  2581,  2594,  2602,  2615,  2620,  2626,  2631,  2636,  2637,
    2643,  2714,  2720,  2725,  2733,  2733,  2748,  2752,  2759,  2762,
    2770,  2781,  2791,  2797,  2806,  2811,  2819,  2822,  2825,  2830,
    2837,  2842,  2847,  2852,  2862,  2870,  2878,  2883,  2887,  2892,
    2896,  2900,  2907,  2910,  2913,  2917,  2921,  2925,  2929,  2937,
    2947,  2952,  2945,  2968,  2973,  2968,  2990,  2990,  2990,  2993,
    2993,  2993,  2997,  2997,  2997,  3001,  3001,  3001,  3005,  3011,
    3017,  3023,  3029,  3035,  3045,  3045,  3049,  3053,  3054,  3065,
    3066,  3072,  3082,  3092,  3102,  3103,  3106,  3111,  3117,  3121,
    3125,  3128,  3134,  3137,  3140,  3157,  3160,  3166,  3167,  3168,
    3172,  3173,  3174,  3175,  3176,  3178,  3179,  3180,  3182,  3183,
    3187,  3188,  3193,  3194,  3206,  3210,  3205,  3218,  3221,  3235,
    3239,  3245,  3234,  3258,  3259,  3271,  3277,  3271,  3291,  3291,
    3293,  3294,  3298,  3298,  3302,  3302,  3307,  3307,  3314,  3315,
    3319,  3319,  3323,  3323,  3328,  3328,  3335,  3339,  3340,  3341,
    3346,  3346,  3349,  3349,  3353,  3353,  3357,  3357,  3361,  3361,
    3366,  3366,  3371,  3371,  3376,  3376,  3381,  3381,  3397,  3414,
    3415,  3416,  3417,  3418,  3419,  3420,  3423,  3423,  3426,  3428,
    3431,  3434,  3436,  3437,  3438,  3440,  3442,  3444,  3446,  3450,
    3457,  3459,  3465,  3470,  3475,  3480,  3480,  3483,  3489,  3494,
    3497,  3504,  3504,  3506,  3507,  3509,  3511,  3513,  3515,  3519,
    3528,  3528,  3590,  3602,  3609,  3609,  3613,  3618,  3624,  3628,
    3632,  3638,  3642,  3646,  3652,  3652,  3660,  3661,  3665,  3665,
    3669,  3670,  3673,  3676,  3676,  3679,  3681,  3681,  3684,  3686,
    3686,  3687,  3689,  3689,  3698,  3705,  3696,  3727,  3727,  3727,
    3730,  3732,  3730,  3739,  3742,  3748,  3759,  3759,  3763,  3769,
    3769,  3773,  3774,  3785,  3786,  3788,  3790,  3795,  3795,  3799,
    3798,  3805,  3804,  3810,  3810,  3815,  3815,  3821,  3821,  3826,
    3826,  3831,  3831,  3836,  3836,  3839,  3839,  3842,  3842,  3845,
    3845,  3887,  3888,  3896,  3897,  3906,  3911,  3916,  3917,  3918,
    3922,  3921,  3932,  3937,  3942,  3942,  3958,  3964,  3965,  3966,
    3967,  3970,  3970,  3973,  3980,  3981,  3982,  3983,  3984,  3985,
    3986,  3987,  3988,  3993,  3993,  3995,  3998,  3998,  4000,  4004,
    4007,  4008,  4011,  4011,  4016,  4019,  4020,  4021,  4022,  4023,
    4024,  4025,  4026,  4027,  4028,  4029,  4030,  4031,  4032,  4033,
    4034,  4035,  4036,  4040,  4058,  4058,  4058,  4085,  4096,  4103,
    4109,  4115,  4121,  4132,  4155,  4154,  4171,  4171,  4175,  4176,
    4184,  4185,  4186,  4187,  4194,  4195,  4197,  4198,  4202,  4207,
    4208,  4209,  4210,  4211,  4212,  4213,  4214,  4215,  4216,  4217,
    4220,  4220,  4222,  4222,  4222,  4224,  4228,  4228,  4237,  4242,
    4258,  4264,  4236,  4278,  4292,  4302,  4291,  4315,  4322,  4322,
    4327,  4333,  4341,  4346,  4347,  4350,  4350,  4350,  4353,  4353,
    4361,  4367,  4381,  4385,  4398,  4380,  4416,  4416,  4430,  4441,
    4440,  4452,  4448,  4465,  4462,  4475,  4475,  4477,  4478,  4480,
    4481,  4484,  4485,  4486,  4488,  4493,  4498,  4504,  4506,  4507,
    4510,  4511,  4514,  4516,  4525,  4531,  4525,  4542,  4543,  4547,
    4547,  4557,  4557,  4569,  4572,  4575,  4578,  4582,  4586,  4587,
    4588,  4589,  4590,  4594,  4599,  4599,  4602,  4628,  4687,  4687,
    4690,  4694,  4698,  4741,  4783,  4784,  4785,  4788,  4802,  4814,
    4814,  4819,  4820,  4826,  4886,  4943,  4948,  4955,  4960,  4968,
    4974,  5008,  5011,  5012,  5053,  5096,  5097,  5101,  5102,  5106,
    5159,  5163,  5166,  5172,  5183,  5190,  5198,  5198,  5201,  5202,
    5203,  5204,  5205,  5208,  5211,  5217,  5220,  5224,  5228,  5235,
    5240,  5247,  5250,  5256,  5258,  5258,  5258,  5262,  5282,  5289,
    5296,  5299,  5313,  5320,  5321,  5324,  5325,  5329,  5335,  5340,
    5346,  5347,  5352,  5356,  5356,  5360,  5361,  5364,  5365,  5369,
    5377,  5380,  5386,  5387,  5389,  5391,  5395,  5395,  5396,  5401,
    5409,  5410,  5415,  5416,  5418,  5431,  5433,  5434,  5436,  5439,
    5442,  5445,  5449,  5452,  5455,  5459,  5463,  5467,  5470,  5474,
    5477,  5478,  5479,  5482,  5485,  5488,  5491,  5494,  5497,  5500,
    5516,  5524,  5524,  5526,  5533,  5537,  5542,  5557,  5555,  5574,
    5575,  5579,  5584,  5585,  5589,  5590,  5592,  5593,  5595,  5595,
    5603,  5612,  5612,  5622,  5623,  5628,  5629,  5632,  5643,  5657,
    5662,  5667,  5672,  5682,  5682,  5686,  5689,  5689,  5691,  5701,
    5710,  5717,  5719,  5723,  5726,  5726,  5730,  5729,  5737,  5736,
    5747,  5746,  5753,  5752,  5756,  5755,  5758,  5758,  5774,  5773,
    5795,  5796,  5797,  5798,  5799,  5800,  5803,  5803,  5809,  5809,
    5812,  5812,  5828,  5829,  5830,  5839,  5851,  5852,  5855,  5856,
    5859,  5862,  5862,  5867,  5887,  5892,  5898,  5899,  5900,  5904,
    5905,  5906,  5907,  5911,  5921,  5923,  5928,  5931,  5936,  5942,
    5949,  5956,  5965,  5972,  5979,  5986,  5993,  6002,  6002,  6004,
    6004,  6007,  6008,  6009,  6010,  6011,  6012,  6013,  6014,  6015,
    6016,  6019,  6019,  6022,  6023,  6024,  6025,  6028,  6028,  6031,
    6031,  6034,  6035,  6036,  6037,  6038,  6039,  6040,  6041,  6043,
    6044,  6045,  6046,  6048,  6049,  6050,  6051,  6053,  6054,  6055,
    6056,  6057,  6058,  6059,  6060,  6064,  6071,  6080,  6092,  6101,
    6112,  6116,  6120,  6126,  6091,  6139,  6142,  6150,  6162,  6164,
    6169,  6177,  6187,  6190,  6194,  6202,  6168,  6211,  6215,  6219,
    6223,  6215,  6233,  6234,  6235,  6236,  6241,  6243,  6246,  6250,
    6253,  6260,  6265,  6266,  6267,  6272,  6273,  6279,  6279,  6279,
    6284,  6284,  6284,  6295,  6296,  6302,  6303,  6315,  6316,  6321,
    6322,  6323,  6327,  6330,  6336,  6339,  6347,  6348,  6354,  6361,
    6364,  6373,  6376,  6379,  6382,  6385,  6388,  6391,  6398,  6401,
    6408,  6411,  6417,  6420,  6427,  6430,  6437,  6438,  6443,  6447,
    6450,  6456,  6459,  6465,  6472,  6473,  6477,  6483,  6486,  6493,
    6494,  6501,  6504,  6509,  6520,  6521,  6522,  6523,  6524,  6525,
    6526,  6527,  6528,  6531,  6534,  6540,  6540,  6546,  6546,  6557,
    6570,  6580,  6580,  6585,  6585,  6589,  6593,  6594,  6600,  6601,
    6606,  6610,  6617,  6620,  6627,  6631,  6626,  6640,  6644,  6648,
    6655,  6659,  6659,  6672,  6676,  6676,  6691,  6693,  6695,  6697,
    6699,  6701,  6703,  6705,  6711,  6721,  6728,  6733,  6734,  6738,
    6741,  6742,  6745,  6746,  6747,  6750,  6755,  6762,  6763,  6769,
    6781,  6782,  6785,  6785,  6790,  6795,  6800,  6801,  6804,  6805,
    6810,  6815,  6819,  6824,  6825,  6829,  6836,  6840,  6841,  6846,
    6848,  6852,  6853,  6857,  6858,  6859,  6860,  6864,  6865,  6870,
    6871,  6876,  6877,  6882,  6883,  6888,  6893,  6894,  6899,  6900,
    6904,  6905,  6910,  6917,  6922,  6927,  6931,  6932,  6937,  6938,
    6944,  6946,  6951,  6952,  6958,  6961,  6964,  6971,  6973,  6987,
    6992,  6993,  6996,  6998,  7005,  7008,  7014,  7018,  7022,  7026,
    7029,  7036,  7043,  7048,  7052,  7053,  7059,  7062,  7073,  7080,
    7086,  7089,  7096,  7103,  7109,  7110,  7116,  7117,  7118,  7121,
    7122,  7127,  7127,  7131,  7139,  7140,  7143,  7146,  7151,  7152,
    7157,  7160,  7166,  7169,  7175,  7178,  7184,  7187,  7194,  7195,
    7224,  7225,  7230,  7238,  7243,  7246,  7249,  7252,  7258,  7259,
    7263,  7266,  7269,  7270,  7275,  7278,  7281,  7284,  7287,  7290,
    7293,  7296,  7301,  7307,  7308,  7309,  7310,  7311,  7313,  7314,
    7316,  7317,  7322,  7325,  7329,  7335,  7336,  7337,  7338,  7350,
    7351,  7352,  7356,  7357,  7362,  7364,  7365,  7366,  7368,  7369,
    7370,  7371,  7373,  7374,  7376,  7377,  7379,  7380,  7381,  7382,
    7384,  7388,  7389,  7395,  7397,  7398,  7399,  7400,  7405,  7409,
    7413,  7417,  7418,  7422,  7423,  7433,  7442,  7443,  7444,  7448,
    7451,  7456,  7461,  7466,  7474,  7478,  7482,  7483,  7484,  7489,
    7492,  7495,  7509,  7523,  7536,  7537,  7541,  7541,  7541,  7541,
    7541,  7541,  7542,  7545,  7550,  7550,  7550,  7550,  7550,  7550,
    7552,  7555,  7561,  7561,  7561,  7561,  7561,  7561,  7561,  7562,
    7562,  7562,  7562,  7562,  7562,  7562,  7564,  7565,  7568,  7577,
    7577,  7583,  7583,  7590,  7590,  7596,  7596,  7604,  7605,  7606,
    7609,  7609,  7612,  7613,  7614,  7619,  7622,  7628,  7633,  7640,
    7653,  7654,  7651,  7672,  7682,  7685,  7690,  7702,  7705,  7709,
    7712,  7713,  7719,  7722,  7723,  7732,  7741,  7746,  7747,  7748,
    7749,  7756,  7759,  7765,  7768,  7778,  7787,  7790,  7793,  7799,
    7805,  7808,  7811,  7814,  7820,  7822,  7824,  7826,  7828,  7830,
    7831,  7832,  7833,  7834,  7835,  7836,  7838,  7840,  7842,  7844,
    7846,  7848,  7850,  7851,  7856,  7857,  7864,  7867,  7876,  7880,
    7887,  7887,  7891,  7891,  7896,  7896,  7900,  7900,  7904,  7910,
    7910,  7913,  7913,  7919,  7926,  7927,  7928,  7932,  7933,  7936,
    7937,  7941,  7947,  7957,  7958,  7966,  7967,  7968,  7969,  7970,
    7971,  7975,  7976,  7977,  7981,  7981,  7993,  7994,  7998,  7999,
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
    8290,  8291,  8292,  8293,  8294,  8295,  8296,  8297,  8298,  8299,
    8300,  8301,  8302,  8303,  8304,  8305,  8306,  8307,  8308,  8309,
    8310,  8311,  8312,  8313,  8314,  8315,  8316,  8317,  8318,  8319,
    8320,  8328,  8328,  8335,  8335,  8423,  8427,  8423,  8436,  8440,
    8446,  8454,  8464,  8474,  8486,  8489,  8508,  8534,  8537,  8543,
    8546,  8551,  8554,  8562,  8570,  8583,  8586,  8594,  8597,  8600,
    8608,  8612,  8615,  8618,  8621,  8625,  8626,  8627,  8628,  8629,
    8635,  8636,  8637,  8638,  8639,  8640,  8641,  8642,  8643,  8644,
    8645,  8646,  8647,  8648,  8652,  8658,  8659,  8671,  8692,  8692,
    8696,  8697,  8698,  8699,  8703,  8704,  8705,  8710,  8736,  8801,
    8803,  8805,  8807,  8811,  8816,  8818,  8821,  8823,  8825,  8829,
    8832,  8837,  8842,  8846,  8855,  8856,  8860,  8872,  8875,  8871,
    8894,  8894,  8898,  8899,  8902,  8903,  8904,  8905,  8906,  8907,
    8908,  8913,  8914,  8918,  8921,  8926,  8930,  8935,  8939,  8944,
    8948,  8951,  8955,  8958,  8963,  8967,  8978,  8984,  8984,  8985,
    8986,  8993,  9002,  9002,  9004,  9005,  9006,  9007,  9008,  9009,
    9010,  9011,  9012,  9013,  9014,  9015,  9016,  9017,  9018,  9019,
    9020,  9021,  9022,  9023,  9024,  9025,  9026,  9027,  9028,  9029,
    9030,  9031,  9032,  9033,  9034,  9035,  9036,  9037,  9038,  9039,
    9040,  9041,  9042,  9043,  9044,  9045,  9046,  9047,  9048,  9049,
    9050,  9051,  9052,  9053,  9054,  9055,  9056,  9057,  9058,  9059,
    9060,  9061,  9062,  9063,  9064,  9065,  9066,  9067,  9068,  9069,
    9070,  9071,  9072,  9073,  9074,  9075,  9076,  9077,  9078,  9079,
    9080,  9081,  9082,  9083,  9084,  9085,  9086,  9087,  9088,  9089,
    9090,  9091
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
     845,   845,   847,   846,   848,   846,   849,   846,   850,   851,
     852,   853,   853,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   855,   855,   855,   855,   855,   855,   855,   855,
     856,   856,   857,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   858,   858,   858,   858,   858,   858,   858,   858,
     858,   858,   858,   859,   859,   860,   860,   861,   861,   862,
     862,   863,   863,   864,   865,   865,   866,   866,   866,   866,
     866,   866,   867,   867,   868,   868,   868,   868,   869,   869,
     870,   871,   871,   871,   872,   871,   873,   873,   874,   874,
     875,   875,   875,   875,   876,   876,   877,   877,   877,   877,
     877,   877,   877,   877,   878,   879,   880,   880,   880,   880,
     880,   880,   881,   881,   881,   881,   881,   881,   881,   882,
     884,   885,   883,   886,   887,   883,   889,   890,   888,   891,
     892,   888,   893,   894,   888,   895,   896,   888,   888,   888,
     888,   888,   888,   888,   897,   897,   898,   899,   899,   899,
     899,   899,   899,   899,   899,   899,   900,   900,   901,   901,
     901,   901,   902,   902,   902,   903,   903,   904,   904,   904,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     906,   906,   907,   907,   909,   910,   908,   911,   911,   913,
     914,   915,   912,   916,   916,   918,   919,   917,   920,   920,
     921,   921,   922,   922,   924,   923,   925,   923,   926,   926,
     927,   927,   929,   928,   930,   928,   931,   932,   932,   932,
     933,   933,   934,   934,   935,   935,   936,   936,   938,   937,
     939,   937,   940,   937,   941,   937,   942,   937,   943,   944,
     944,   944,   944,   944,   944,   944,   945,   945,   946,   947,
     948,   949,   949,   949,   949,   949,   949,   949,   949,   950,
     951,   952,   953,   954,   955,   956,   956,   957,   958,   959,
     959,   960,   960,   961,   961,   961,   961,   961,   961,   962,
     963,   963,   964,   965,   966,   966,   967,   968,   969,   969,
     969,   970,   970,   970,   972,   971,   973,   973,   974,   974,
     975,   975,   976,   977,   977,   978,   979,   979,   980,   981,
     981,   982,   983,   983,   985,   986,   984,   987,   988,   987,
     989,   990,   987,   991,   991,   992,   994,   993,   993,   995,
     995,   996,   996,   997,   997,   998,   998,   999,   999,  1001,
    1000,  1002,  1000,  1003,  1000,  1004,  1000,  1005,  1000,  1006,
    1000,  1007,  1000,  1008,  1000,  1009,  1000,  1010,  1000,  1011,
    1000,  1012,  1012,  1013,  1013,  1014,  1015,  1016,  1016,  1016,
    1018,  1017,  1019,  1019,  1020,  1019,  1021,  1022,  1022,  1022,
    1022,  1023,  1023,  1024,  1025,  1025,  1025,  1025,  1025,  1025,
    1025,  1025,  1025,  1027,  1026,  1026,  1029,  1028,  1030,  1031,
    1032,  1032,  1033,  1033,  1034,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,  1035,
    1035,  1035,  1035,  1036,  1038,  1039,  1037,  1040,  1040,  1041,
    1042,  1043,  1044,  1044,  1046,  1045,  1047,  1047,  1048,  1048,
    1049,  1049,  1049,  1049,  1050,  1050,  1051,  1051,  1052,  1053,
    1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,  1053,
    1054,  1054,  1055,  1055,  1055,  1056,  1057,  1057,  1059,  1060,
    1061,  1062,  1058,  1063,  1065,  1066,  1064,  1067,  1068,  1068,
    1069,  1069,  1070,  1071,  1071,  1072,  1072,  1072,  1074,  1073,
    1075,  1075,  1077,  1078,  1079,  1076,  1081,  1080,  1082,  1084,
    1083,  1085,  1083,  1086,  1083,  1087,  1087,  1088,  1088,  1089,
    1089,  1090,  1090,  1090,  1091,  1092,  1093,  1094,  1094,  1094,
    1095,  1095,  1096,  1096,  1098,  1099,  1097,  1100,  1100,  1102,
    1101,  1103,  1101,  1104,  1105,  1105,  1105,  1105,  1106,  1106,
    1106,  1106,  1106,  1107,  1108,  1108,  1109,  1110,  1111,  1111,
    1112,  1113,  1113,  1113,  1113,  1113,  1113,  1114,  1115,  1116,
    1116,  1117,  1117,  1118,  1119,  1120,  1120,  1121,  1121,  1122,
    1123,  1124,  1124,  1124,  1124,  1124,  1124,  1125,  1125,  1126,
    1127,  1127,  1128,  1128,  1129,  1129,  1130,  1130,  1131,  1131,
    1131,  1131,  1131,  1132,  1132,  1133,  1133,  1134,  1134,  1135,
    1136,  1137,  1137,  1138,  1139,  1139,  1139,  1140,  1141,  1141,
    1142,  1142,  1143,  1144,  1144,  1145,  1145,  1146,  1147,  1148,
    1149,  1149,  1150,  1151,  1151,  1152,  1152,  1153,  1153,  1154,
    1155,  1155,  1156,  1156,  1156,  1156,  1157,  1157,  1157,  1158,
    1159,  1159,  1160,  1160,  1160,  1161,  1162,  1162,  1163,  1163,
    1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,  1163,
    1164,  1165,  1165,  1166,  1166,  1166,  1167,  1169,  1168,  1170,
    1170,  1171,  1172,  1172,  1173,  1173,  1174,  1174,  1176,  1175,
    1177,  1179,  1178,  1180,  1180,  1181,  1181,  1182,  1182,  1183,
    1183,  1183,  1183,  1184,  1184,  1185,  1186,  1186,  1187,  1188,
    1189,  1190,  1191,  1191,  1192,  1192,  1194,  1193,  1195,  1193,
    1196,  1193,  1197,  1193,  1198,  1193,  1199,  1193,  1200,  1193,
    1201,  1201,  1201,  1201,  1201,  1201,  1203,  1202,  1204,  1204,
    1206,  1205,  1205,  1205,  1205,  1205,  1207,  1207,  1208,  1208,
    1209,  1210,  1210,  1211,  1212,  1213,  1214,  1214,  1214,  1215,
    1215,  1215,  1215,  1216,  1217,  1217,  1218,  1218,  1219,  1220,
    1220,  1220,  1220,  1220,  1220,  1220,  1220,  1221,  1221,  1222,
    1222,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,  1223,
    1223,  1224,  1224,  1225,  1225,  1225,  1225,  1226,  1226,  1227,
    1227,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,  1228,
    1228,  1228,  1228,  1228,  1228,  1229,  1229,  1229,  1231,  1232,
    1233,  1234,  1235,  1236,  1230,  1237,  1237,  1238,  1239,  1239,
    1241,  1242,  1243,  1244,  1245,  1246,  1240,  1247,  1249,  1250,
    1251,  1248,  1252,  1252,  1252,  1252,  1253,  1253,  1253,  1253,
    1253,  1254,  1255,  1255,  1255,  1256,  1256,  1258,  1259,  1257,
    1260,  1261,  1257,  1262,  1262,  1263,  1263,  1264,  1264,  1265,
    1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1269,  1270,
    1270,  1271,  1271,  1271,  1271,  1271,  1271,  1271,  1272,  1272,
    1273,  1273,  1274,  1274,  1275,  1275,  1276,  1276,  1277,  1278,
    1278,  1279,  1279,  1280,  1281,  1281,  1282,  1283,  1283,  1284,
    1284,  1285,  1285,  1286,  1287,  1287,  1287,  1287,  1287,  1287,
    1287,  1287,  1287,  1287,  1287,  1288,  1288,  1289,  1289,  1290,
    1291,  1293,  1292,  1295,  1294,  1294,  1296,  1296,  1297,  1297,
    1298,  1298,  1299,  1299,  1301,  1302,  1300,  1303,  1304,  1304,
    1305,  1306,  1305,  1307,  1308,  1307,  1309,  1309,  1309,  1309,
    1309,  1309,  1309,  1309,  1310,  1311,  1312,  1313,  1313,  1314,
    1315,  1315,  1316,  1316,  1316,  1317,  1318,  1319,  1319,  1320,
    1321,  1321,  1323,  1322,  1324,  1324,  1324,  1324,  1324,  1324,
    1324,  1324,  1324,  1324,  1324,  1324,  1325,  1326,  1326,  1327,
    1327,  1328,  1328,  1329,  1329,  1329,  1329,  1330,  1330,  1331,
    1331,  1332,  1332,  1333,  1333,  1334,  1335,  1335,  1336,  1336,
    1337,  1337,  1338,  1339,  1340,  1341,  1342,  1342,  1343,  1343,
    1344,  1344,  1345,  1345,  1346,  1346,  1346,  1347,  1347,  1348,
    1349,  1349,  1350,  1350,  1351,  1351,  1352,  1352,  1352,  1352,
    1352,  1353,  1354,  1355,  1356,  1356,  1357,  1357,  1358,  1359,
    1360,  1360,  1361,  1362,  1363,  1363,  1364,  1364,  1364,  1365,
    1365,  1366,  1366,  1367,  1368,  1368,  1369,  1369,  1370,  1370,
    1371,  1371,  1372,  1372,  1373,  1373,  1374,  1374,  1375,  1375,
    1376,  1376,  1377,  1378,  1379,  1379,  1379,  1379,  1380,  1380,
    1381,  1381,  1382,  1382,  1383,  1383,  1383,  1383,  1383,  1383,
    1383,  1383,  1383,  1384,  1384,  1384,  1384,  1384,  1384,  1384,
    1384,  1384,  1385,  1385,  1385,  1386,  1386,  1386,  1386,  1387,
    1387,  1387,  1388,  1388,  1389,  1389,  1389,  1389,  1389,  1389,
    1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,  1389,
    1389,  1390,  1390,  1391,  1391,  1391,  1391,  1391,  1392,  1393,
    1394,  1395,  1395,  1395,  1395,  1396,  1397,  1397,  1397,  1398,
    1398,  1399,  1399,  1399,  1400,  1401,  1401,  1401,  1401,  1401,
    1402,  1403,  1404,  1404,  1405,  1405,  1406,  1406,  1406,  1406,
    1406,  1406,  1406,  1406,  1407,  1407,  1407,  1407,  1407,  1407,
    1407,  1407,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1409,
    1409,  1409,  1409,  1409,  1409,  1409,  1410,  1410,  1411,  1413,
    1412,  1414,  1412,  1415,  1412,  1416,  1412,  1417,  1417,  1417,
    1418,  1418,  1419,  1419,  1419,  1420,  1420,  1421,  1421,  1422,
    1424,  1425,  1423,  1426,  1427,  1427,  1428,  1429,  1429,  1429,
    1429,  1429,  1430,  1431,  1431,  1432,  1433,  1434,  1434,  1434,
    1434,  1435,  1435,  1436,  1436,  1437,  1438,  1438,  1438,  1439,
    1439,  1439,  1439,  1439,  1440,  1440,  1440,  1440,  1440,  1440,
    1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,  1440,
    1440,  1440,  1440,  1440,  1441,  1441,  1442,  1443,  1444,  1444,
    1445,  1445,  1446,  1446,  1447,  1447,  1448,  1448,  1449,  1450,
    1450,  1451,  1451,  1452,  1453,  1453,  1453,  1454,  1454,  1455,
    1456,  1457,  1458,  1459,  1459,  1460,  1460,  1460,  1460,  1460,
    1460,  1461,  1461,  1461,  1463,  1462,  1464,  1464,  1465,  1465,
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
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1467,  1466,  1469,  1468,  1471,  1472,  1470,  1473,  1473,
    1473,  1474,  1474,  1474,  1474,  1474,  1474,  1475,  1475,  1476,
    1477,  1478,  1478,  1479,  1479,  1480,  1480,  1481,  1481,  1481,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1483,  1483,  1483,  1483,  1483,  1483,  1483,  1483,  1483,  1483,
    1483,  1483,  1483,  1483,  1484,  1485,  1485,  1486,  1487,  1487,
    1488,  1488,  1488,  1488,  1489,  1489,  1489,  1490,  1490,  1491,
    1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1491,  1492,
    1492,  1492,  1492,  1492,  1493,  1493,  1494,  1496,  1497,  1495,
    1498,  1498,  1499,  1499,  1500,  1500,  1500,  1500,  1500,  1500,
    1500,  1501,  1501,  1502,  1502,  1503,  1503,  1504,  1504,  1505,
    1505,  1506,  1507,  1508,  1509,  1509,  1510,  1511,  1511,  1512,
    1513,  1513,  1515,  1514,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,  1516,
    1516,  1516
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
       5,     7,     4,     6,     0,     3,     1,     1,     4,     4,
       4,     4,     4,     4,     1,     1,     1,     1,     4,     4,
       2,     2,     2,     2,     2,     1,     1,     2,     1,     1,
       1,     2,     4,     6,     6,     3,     5,     5,     3,     1,
       1,     3,     1,     3,     0,     0,    11,     0,     2,     0,
       0,     0,     9,     0,     3,     0,     0,    10,     0,     1,
       0,     1,     1,     2,     0,     3,     0,     3,     0,     1,
       1,     2,     0,     3,     0,     3,     3,     1,     4,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     0,     3,
       0,     3,     0,     4,     0,     4,     0,     4,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     4,     6,     4,     3,     6,     3,     6,     1,
       1,     1,     1,     1,     1,     0,     2,     1,     1,     1,
       4,     1,     1,     1,     4,     3,     6,     3,     6,     1,
       1,     2,     2,     2,     1,     3,     1,     2,     2,     2,
       4,     2,     2,     4,     0,     8,     0,     1,     1,     1,
       0,     1,     2,     0,     1,     2,     0,     1,     2,     0,
       1,     3,     0,     2,     0,     0,     8,     0,     0,     3,
       0,     0,     7,     5,     2,     2,     0,     5,     4,     1,
       3,     3,     3,     0,     2,     0,     1,     1,     2,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       3,     1,     3,     1,     3,     2,     4,     1,     1,     1,
       0,     4,     5,     6,     0,    10,     3,     2,     2,     1,
       1,     0,     2,     1,     2,     3,     3,     3,     3,     1,
       1,     1,     1,     0,     3,     1,     0,     3,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     7,     1,     1,     2,
       2,     2,     3,     4,     0,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     0,     0,
       0,     0,    13,     1,     0,     0,     6,     2,     1,     2,
       2,     2,     1,     1,     2,     1,     1,     1,     0,     3,
       2,     1,     0,     0,     0,    14,     0,     5,     1,     0,
       3,     0,     7,     0,     5,     1,     2,     0,     1,     1,
       1,     0,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     3,     1,     1,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     2,
       2,     2,     5,     8,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     2,     2,     3,     6,     1,     3,     1,
       1,     1,     3,     6,     9,     1,     1,     1,     1,     2,
       0,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     2,     0,     1,     1,     4,     1,     3,
       1,     3,     7,     0,     7,     0,     6,     3,     1,     3,
       1,     2,     5,     0,     7,     0,     2,     0,     1,     5,
       2,     5,     0,     5,     6,     4,     0,     1,     1,     4,
       0,     2,     0,     5,     4,     2,     1,     3,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     2,     4,     2,     1,     0,    11,     0,
       2,     5,     0,     1,     0,     2,     1,     2,     0,     3,
       1,     0,     4,     0,     2,     1,     3,     1,     1,     3,
       4,     4,     2,     1,     1,     1,     0,     1,     7,     2,
       2,     2,     2,     2,     1,     2,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     1,
       0,     4,     1,     2,     2,     2,     0,     1,     1,     2,
       2,     0,     2,     3,     3,     5,     0,     2,     4,     1,
       1,     1,     1,     1,     0,     1,     1,     3,     2,     5,
       2,     5,     5,     5,     5,     5,     5,     0,     2,     1,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     0,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     1,     1,     1,     0,     3,     2,     0,     0,
       0,     0,     0,     0,    15,     0,     2,     2,     0,     1,
       0,     0,     0,     0,     0,     0,    15,     2,     0,     0,
       0,    10,     0,     1,     3,     3,     2,     4,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     0,     0,     7,
       0,     0,     8,     3,     2,     0,     1,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     3,     1,     3,     2,     4,     1,     3,     1,     2,
       4,     1,     3,     1,     1,     1,     2,     2,     4,     2,
       4,     1,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     6,     6,     0,     1,     0,     1,     2,
       1,     0,     5,     0,     5,     1,     0,     3,     1,     3,
       1,     3,     1,     1,     0,     0,     5,     1,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       1,     1,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     4,
       0,     1,     0,     1,     1,     2,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     2,     1,     1,     2,     2,
       1,     3,     2,     2,     1,     3,     1,     2,     4,     1,
       2,     1,     3,     4,     0,     1,     0,     1,     0,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     2,     2,
       0,     2,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     0,     1,     3,     3,     3,     6,     4,     4,
       4,     4,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     1,     5,     5,     1,     1,
       1,     4,     1,     4,     1,     7,     1,     1,     1,     4,
       6,     0,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     3,     1,     0,     3,     5,     1,
       2,     2,     4,     3,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     3,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       7,     0,     8,     0,     6,     0,     8,     0,     1,     2,
       1,     3,     1,     3,     5,     1,     1,     1,     1,     1,
       0,     0,     9,     5,     1,     1,     6,     0,     3,     1,
       3,     4,     1,     0,     2,     4,     6,     0,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     2,     4,     3,     2,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     5,     5,     5,     5,     5,
       4,     4,     3,     4,     1,     3,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     0,     4,     1,     2,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     3,     0,     0,     6,     0,     2,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     796,     0,  2102,  2105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   848,   180,     0,   820,   825,
     178,   183,   800,     0,   794,   797,   798,   801,   803,   847,
     802,   842,   843,   845,   184,   135,   132,     0,   128,   130,
     129,   133,  2146,   685,   627,  2109,     0,     0,  2112,     0,
    2108,  2104,  2101,  2099,  2100,  2107,  2106,  2103,   301,  1587,
    1586,   840,   176,   187,   841,   179,   184,     1,   804,   799,
     846,   844,   821,   127,   131,   134,  2116,  2113,     0,  2114,
    2111,     0,     0,   606,     0,     0,   177,   851,   915,   607,
     849,   639,   907,     0,   908,   916,   914,   187,   181,   200,
       0,   185,   201,   236,     0,   827,  1200,     0,     0,   826,
     136,  1188,   834,     0,     0,   817,   819,   816,   818,   795,
     805,   806,   828,   809,   810,   811,   814,   812,   813,   815,
    2115,  2110,     0,   909,   850,     0,     0,   923,   921,   922,
     911,   910,   299,   187,  1124,   194,   188,   187,   193,   233,
       0,   684,     0,     0,     0,     0,   176,   555,   884,   807,
       0,   333,   319,   203,   270,   289,   310,   312,   309,     0,
     331,     0,   318,   311,   315,   321,   305,   320,   187,   322,
     302,   325,   303,   304,   920,   919,     0,    22,    23,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   929,
       0,   515,   507,    16,   514,   915,    15,     0,   927,     0,
     300,     0,   186,  1125,   182,     0,   200,   202,   266,   205,
     260,   261,   249,   226,   257,   203,   228,   270,   289,   247,
     250,   245,     0,   224,     0,   256,   248,   253,   259,   241,
     258,   187,   262,   187,   239,   240,   237,   265,     0,     0,
       0,     0,   835,   176,   176,     0,     0,   204,     0,   323,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,   268,     0,   917,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,     0,     0,     0,
     640,   434,   436,  1195,     0,     0,     0,  1554,     0,   428,
       0,     0,     0,   427,     0,   444,   517,     0,     0,     0,
       0,     0,   520,     0,   393,   392,   399,   440,   437,   394,
     395,   397,   398,   435,   438,   443,   516,   489,   486,   495,
     492,     0,     0,    17,    18,    19,    20,    21,     0,    14,
     480,     0,     0,   925,     0,   189,   192,   190,   191,     0,
     197,   196,   195,   198,   206,   207,   208,   211,   187,     0,
     187,   263,   264,     0,     0,   187,     0,     0,     0,     0,
     246,   234,  1201,     0,     0,  1189,  2152,   556,   885,   829,
       0,   215,   216,     0,   282,   284,   279,   280,   276,   278,
     275,   277,   274,     0,   284,   295,   296,   292,   294,   291,
     293,   286,     0,     0,     0,   335,     0,   338,   340,   223,
       0,   222,     0,     0,   187,     0,  2131,   611,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,   525,   530,
       0,   526,   529,   528,     0,     0,    11,   172,   426,   401,
     400,     0,  1130,     0,     0,   442,  1562,  1560,  1561,  1557,
    1559,  1556,  1558,  1550,     0,     0,     0,   441,     0,     0,
       0,     0,     0,     0,     0,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,   168,   169,   170,   522,
     523,   524,   455,     0,     0,   454,   464,     0,     0,   405,
       0,     0,   406,   396,   402,   404,   407,   408,   409,   410,
     411,   403,   433,   432,     0,     0,     0,     0,     0,     0,
       0,    12,    93,     0,   928,     0,   912,   199,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   187,   235,
     238,   940,   683,   852,   940,     0,  2150,  2152,  1124,  1681,
     822,     0,   940,     0,     0,   271,     0,     0,   281,   298,
     272,   297,     0,   290,     0,   313,     0,   307,     0,   332,
       0,   337,   327,     0,     0,   316,   306,   269,   326,     0,
       0,     0,     0,   513,   510,   509,   512,   508,   519,   504,
     504,     0,   527,     0,   531,     0,   289,   511,   518,   273,
       0,  1196,  1627,     0,     0,     0,     0,     0,   429,     0,
       0,   445,     0,     0,     0,     0,   447,   446,   465,   456,
     471,   474,   475,   472,   478,   477,   476,   466,   467,   468,
     469,   470,   412,   457,   461,   479,   473,   460,   479,   439,
     490,   487,   496,   493,   502,     0,   481,    94,    95,    97,
     483,     0,     0,   236,     0,     0,     0,     0,   251,     0,
     243,   225,   209,     0,   254,   242,   267,   946,     0,   941,
     942,   940,     0,   836,  2151,  2149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2133,     0,
    1290,  1289,     0,  1291,     0,   386,  1288,  1230,     0,     5,
    1287,   387,   384,     0,   389,   174,   479,  1102,     0,     0,
    1297,   124,   383,   382,  1222,   377,   479,     0,  1247,  2124,
       0,   388,   352,     0,     3,     2,     0,   385,  1227,     0,
       0,   378,   375,   390,     0,     0,     0,     0,  1295,  1285,
     381,     0,     0,     0,     0,     0,     0,     0,     0,  1284,
       0,     0,     0,   175,  1224,   374,   373,     0,     0,  2128,
    2127,     0,     0,     0,   137,  1223,   380,   379,     0,     0,
     376,   479,   479,     0,   549,     0,     0,     0,     0,     0,
       0,   479,   783,  1198,     0,     0,  1106,     0,  2117,     0,
     104,     0,     0,   856,     0,     0,     0,     0,   784,     0,
       0,  1704,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   654,     0,     0,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,  2171,  2172,  2173,  2174,  2175,  2176,  2177,  2178,  2179,
    2180,  2181,  2182,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2190,  2191,  2192,  2193,  2194,  2195,  2196,  2197,  2198,  2199,
    2200,  2201,  2202,  2203,   894,  2204,  2205,  2206,  2207,  2208,
    2209,  2210,  2211,  2212,  2213,  2214,  2215,  2216,  2217,  2218,
    2219,  2220,  1093,  1095,  1090,  1092,  1091,  1094,  2221,  2222,
    1221,  2223,  1226,  1225,  2224,  2225,  2226,  2227,  2228,  2229,
    2230,  2231,  2232,  2233,  1352,  2234,  2235,  2236,  2237,  2238,
    2239,  2240,  2241,  2153,   823,   560,   824,     0,   889,     0,
     887,     0,   334,   217,   218,     0,   283,   288,     0,     0,
       0,     0,   336,   339,     0,   221,     0,     0,     0,   615,
       0,   617,  2132,   499,     0,   500,     0,   541,     0,   538,
     535,   506,   498,     0,   171,  1629,  1630,  1628,     0,   431,
    1195,     0,  1555,  1195,   430,  1195,  1195,  1195,  1195,  1195,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,   926,     0,   212,   227,
       0,   187,     0,     0,     0,     0,     0,  1202,     0,     0,
    1190,   370,   368,   369,  1032,  1031,  1035,     0,     0,  1234,
     628,   629,   808,  1065,  1070,  2126,   621,   123,     0,     0,
    2091,  2090,  1000,  2087,  2089,  2141,     0,  1241,     0,  1237,
    1246,     7,     0,     6,     0,  2134,  1066,     0,  1158,  1157,
    1105,  1156,  1104,   423,  1298,  1286,   837,   413,  1683,  1292,
     125,     0,  1069,   122,     0,   790,    24,   623,   391,     0,
     789,  1062,   791,     0,  1296,   878,   877,   880,   876,   879,
    2143,     0,   874,     0,   622,   973,   875,  2137,     0,  2125,
     121,   970,   686,   968,     0,   619,  2120,   728,   727,   729,
     725,     0,     0,   983,   624,  1351,  1347,  1350,     0,     0,
    1036,  1033,     0,  1027,  1029,  1028,  1026,  1025,     0,     0,
       0,  1024,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1014,  1005,  1006,     0,  1050,
     421,    24,     0,  2122,   126,   620,     0,  1199,  1197,  1123,
       0,  1672,  1673,  1124,  1212,  1124,  1107,  1108,  1111,  1126,
    1299,     0,     0,     0,     0,     0,     0,     0,     0,    63,
       0,   915,     0,    69,     0,   102,   598,   642,     0,  1096,
     990,  1100,     0,     0,  1051,  1216,     0,     0,  1103,   646,
     643,   644,     0,   648,   649,     0,   651,   652,     0,   647,
     950,   952,     0,     0,   951,   730,   948,   695,   944,   906,
       0,     0,     0,     0,   658,   659,     0,     0,   904,   901,
     902,   898,   899,   900,   893,   897,   896,     0,     0,     0,
       0,     0,     0,   564,   566,   558,   561,   562,   891,  2152,
     886,   888,   830,     0,   285,   287,   314,   308,     0,     0,
     317,   612,   614,     0,     0,   504,   532,     0,   282,     0,
       0,  1653,  1545,  1548,  1654,  1552,  1546,  1651,     0,     0,
    1650,     0,     0,  1652,     0,     0,     0,     0,     0,  2091,
    1547,  1649,  1549,  1641,     0,  1631,  1633,  1636,  1639,  2097,
    1640,  1133,  1563,  1132,  1131,  1134,  1136,  1135,  1129,   458,
     459,   463,   448,     0,   451,   462,     0,   450,   491,   488,
     497,   494,   503,   482,    96,   484,   913,     0,   232,     0,
     230,   252,   244,   236,   255,   947,   176,   943,   853,   176,
       0,     0,     0,  1274,  1275,     0,     0,     0,  1248,  1249,
    1251,  1252,  1253,  1257,  1256,  1254,  1255,     0,     0,  2088,
     924,     0,  1002,     0,     0,  1240,  1239,     0,  1233,     0,
    1532,  1533,     0,  1067,     0,    24,  1153,  1155,  1154,   416,
     417,   414,   415,   960,     0,     0,   357,    25,   351,     0,
       0,  1059,     0,     0,     0,     0,     0,     0,     0,   977,
    1682,     0,     0,   187,     0,     0,     0,  2122,     0,     0,
     138,     0,     0,   987,   979,   980,   985,  1348,  1349,   903,
     419,   341,     0,   550,   603,   602,   600,   605,  1008,   604,
    1013,  1009,  1012,   782,   774,   768,   780,   781,   766,   767,
     775,   770,   776,   769,   779,   773,   777,   772,   778,   765,
     771,   758,   764,  1010,  1011,     0,  1018,  1022,  1015,  1016,
    1020,  1021,  1019,  1017,  1023,     0,   792,     0,     0,     0,
       0,     0,   740,   739,   736,  2123,  2130,    24,  1119,  1120,
    1121,  1122,  1116,  1114,  1213,  1128,  1113,  1109,     0,     0,
    1110,  2118,     0,     0,     0,     0,    98,     0,    99,     0,
       0,     0,    74,     0,     0,     0,   111,   106,     0,   883,
       0,   882,     0,   479,  1098,     0,   935,   936,   959,   930,
     931,   785,   957,  1053,  1218,     0,  1220,  1219,  1761,  1879,
    1875,  1881,  1913,  1893,  1884,  1843,  1805,  1933,  1899,  1907,
    1796,  1902,  1762,  1708,  1894,  1801,  1852,  1987,  1831,  1819,
    1832,  1931,  1934,  1901,  1855,  1937,  1720,  1994,  1930,  1958,
    1731,  2031,  1820,  2003,  1713,  1963,  1729,  1791,  1838,  1858,
    1953,  1981,  1986,  1712,  1910,  1939,  1724,  1726,  1750,  1768,
    1789,  1799,  1809,  1862,  1865,  1924,  1935,  1941,  1942,  1959,
    2004,  2015,  1711,  1742,  1767,  1766,  1769,  1775,  1777,  1785,
    1795,  1816,  1834,  1837,  1863,  1871,  1928,  1938,  1948,  1954,
    1955,  1957,  1982,  2012,  2019,  2024,  1732,  1735,  1746,  1753,
    1755,  1760,  1763,  1765,  1772,  1780,  1782,  1783,  1784,  1794,
    1804,  1811,  1827,  1828,  1839,  1857,  1861,  1874,  1890,  1914,
    1922,  1932,  1936,  1943,  1951,  1960,  1970,  1974,  1991,  1997,
    2001,  2009,  2014,  2017,  1756,  1876,  1919,  1740,  1741,  1759,
    1764,  1771,  1773,  1787,  1788,  1798,  1807,  1812,  1814,  1815,
    1821,  1829,  1846,  1847,  1860,  1888,  1892,  1895,  1900,  1904,
    1912,  1920,  1921,  1926,  1944,  1945,  1950,  1956,  1961,  1967,
    1968,  1969,  1971,  1973,  1975,  1984,  2006,  2007,  2008,  2013,
    2030,  1715,  1870,  1878,  1880,  1977,  1717,  1721,  1725,  1730,
    1736,  1737,  1751,  1752,  1754,  1757,  1770,  1786,  1806,  1808,
    1818,  1822,  1824,  1825,  1833,  1842,  1844,  1845,  1856,  1869,
    1887,  1905,  1906,  1923,  1925,  1929,  1940,  1962,  1972,  1980,
    2002,  2005,  2020,  2021,  2022,  1748,  1718,  1738,  1739,  1745,
    1817,  1747,  1749,  1774,  1776,  1790,  1867,  1992,  1800,  1802,
    1810,  1813,  1835,  1836,  1841,  1848,  1849,  1850,  2033,  1882,
    1883,  1886,  1891,  1896,  1903,  1908,  1909,  1911,  1918,  1947,
    1949,  1965,  1976,  1978,  1979,  1983,  1988,  1989,  1993,  1995,
    1996,  2011,  2016,  2018,  2023,  2025,  2029,  1877,  2028,  1714,
    1716,  1719,  1723,  1733,  1758,  1778,  1779,  1781,  1792,  1823,
    1826,  1866,  1872,  1885,  1889,  2026,  2027,  1927,  1946,  1952,
    1964,  1966,  1985,  1990,  2000,  2010,  1728,  1722,  1727,  1744,
    1797,  1840,  1853,  1854,  1915,  1917,  1999,  1873,  1830,  1897,
    1743,  1793,  1803,  1868,  1851,  1898,  1734,  1859,  1864,  1998,
    1916,     0,  1706,  1709,  1710,   674,     0,     0,     0,   663,
     695,   695,   693,     0,     0,   696,     0,    26,   662,   665,
       0,   672,   668,   905,   895,  1679,  1680,  1670,  1670,  1317,
       0,     0,  1588,     0,   187,  1300,     0,     0,  1301,  1345,
     187,     0,  1346,     0,  1627,     0,  1314,     0,  1363,  1362,
    1361,  1359,  1360,  1358,  1356,  1353,  1427,  1426,  1354,  1355,
    1364,  1609,  1357,  1686,  1685,  1684,  1365,  2152,  2152,   577,
     568,   559,     0,   563,  2152,   890,   176,     0,   328,   220,
       0,     0,  1570,  1568,  1569,  1565,  1567,  1564,  1566,   505,
     501,     0,   537,   536,   173,  1638,  1637,  1578,  1576,  1577,
    1573,  1575,  1572,  1574,  1551,     0,  1627,     0,     0,  1495,
       0,  1495,  1495,  1495,  1495,  1642,     0,     0,     0,  1444,
    1617,  1634,     0,     0,     0,     0,  1695,  1696,  1697,  1698,
    1699,  1700,  1645,     0,     0,   453,   452,     0,     0,   187,
     229,   210,  1203,   176,  1191,  1417,     0,  1416,     0,  1418,
       0,  1419,  1277,     0,  1283,  1279,  1276,     0,     0,     0,
       0,     0,     0,  1273,  1269,  1406,  1405,  1404,  1245,  1244,
       0,  1268,  1264,     0,  1260,  1258,     0,   632,     0,   631,
       0,  1001,     0,     0,   999,  2094,  2096,  2095,  2092,  2142,
    2139,  1238,     0,     0,     0,  1231,   479,   349,     0,     0,
    1228,   992,  1063,  1064,  1061,  1060,     0,   881,     0,     0,
     608,     0,     0,     0,   971,   969,     0,   688,   689,     0,
       0,  2121,  2129,   726,     0,   142,     0,   981,   988,     0,
       0,   996,     0,   344,     0,     0,     0,     0,    24,  1034,
     553,     0,     0,     0,   759,   760,  1007,   793,   422,     0,
    1042,   737,   738,   371,     0,  1124,     0,  1127,  1112,  2152,
       0,     0,     0,   542,     0,     0,     0,     0,    64,    93,
       0,     0,   117,   112,     0,   107,     0,   114,   108,   867,
     859,   865,     0,  1097,     0,  1099,  1101,     0,     0,   939,
       0,     0,     0,     0,  1052,  1217,     0,     0,  1705,  1707,
    2152,   645,   650,   653,   666,   664,   625,     0,   715,   713,
     719,   717,     0,     0,   711,   755,   709,   705,   703,   753,
     731,     0,   697,   707,   949,   945,     0,     0,     0,     0,
     671,     0,     0,     0,     0,     0,     0,     0,  1535,     0,
    1422,  1423,  1691,  1386,  1444,     0,     0,  1689,     0,     0,
    1610,  2035,     0,  1369,  1375,  1374,  1373,  1377,     0,  1370,
    1371,   565,   567,     0,     0,   580,   572,   574,     0,   569,
     570,     0,     0,   588,   590,     0,     0,   586,   892,   831,
     219,     0,   616,   618,   613,     0,   534,   533,     0,     0,
    1662,     0,     0,     0,  1497,  1498,  1496,     0,  1664,     0,
       0,     0,     0,     0,     0,     0,  1632,     0,  1433,  1434,
    1436,  1439,     0,  1445,  1446,     0,     0,  1495,  1619,  1613,
    1647,  1648,  1646,  1644,  2098,   449,   485,     0,   231,  1159,
     854,  1137,  1394,  1396,     0,  1281,     0,     0,     0,     0,
       0,  1271,     0,     0,  1527,  1525,  1512,  1514,  1510,     0,
    1509,     0,  1518,  1505,  1526,     0,  1517,  1502,  1508,  1524,
    1516,  1410,  1499,  1500,  1501,     0,  1266,  1262,     0,     0,
    1250,   630,     0,     0,     0,     0,     0,  2138,     4,     8,
      10,  1531,  1534,     0,   479,   418,     0,     0,     0,   989,
       0,     0,     0,     0,     0,     0,     0,   187,   687,     0,
       0,   159,   157,     0,     0,   139,     0,   149,   155,   695,
     144,   146,     0,   986,   997,   998,     0,   420,   343,   348,
     610,   342,     0,   345,   350,   479,  1323,   601,   599,     0,
     762,  1041,  1043,     0,   372,  1117,  1115,  1214,  1215,     0,
       0,  1208,     0,     0,     0,     0,   100,     0,     0,    75,
      81,    71,  2152,  2152,   110,   105,   119,   115,     0,   109,
     756,   868,   625,  2152,   858,   857,   866,   991,     0,     0,
     937,   938,   932,   958,   479,  1058,  1054,  1055,  1057,  2032,
     955,  2034,   953,   675,   669,   667,     0,    24,     0,  2152,
    2152,  2152,  2152,   721,   699,   723,   701,  2152,  2152,  2152,
    2152,     0,   694,   698,  2152,   625,   751,   749,   752,   750,
       0,     0,    46,    44,    41,    35,    39,    43,    38,    31,
      40,     0,    34,    37,    32,    42,    33,    45,    36,     0,
      29,    47,   743,     0,   673,  1671,     0,  1669,  1627,  1667,
    1614,  1615,  1607,  1593,  1608,     0,     0,     0,  1030,  1421,
    1424,     0,     0,     0,  1335,  1306,  1694,  1693,  1692,     0,
       0,     0,     0,  1330,     0,  1329,     0,  1331,  1326,  1327,
    1328,  1319,  1315,     0,     0,  1376,     0,     0,   579,   584,
       0,     0,  2152,  2152,   557,   571,   594,   582,   596,  2152,
    2152,   592,   576,   587,   822,   329,     0,  1585,  1583,  1584,
    1580,  1582,  1579,  1581,  1553,     0,     0,     0,  1663,     0,
       0,     0,  1661,     0,     0,     0,     0,  1643,  1660,     0,
    1437,     0,  1544,  1440,     0,     0,     0,     0,  1432,  1450,
    1452,  1454,  1494,  1493,  1492,  1456,  1472,     0,  1447,  1448,
    1622,  1235,     0,     0,     0,   213,     0,  1185,  1204,   822,
       0,  1192,  1185,     0,     0,  1278,     0,  1280,     0,  1536,
       0,  1395,     0,  1398,  1539,     0,  1402,     0,  1270,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1408,
       0,  1411,  1412,     0,  1265,     0,  1259,  1261,  2093,     0,
       0,     0,  2140,     0,     0,  1242,   838,     0,     0,     0,
       0,     0,  1293,  2145,  2144,   609,     0,     0,    48,     0,
     692,   691,   690,  1294,   695,  2152,  2152,   151,   633,   161,
     153,   163,   143,   150,  2152,     0,     0,     0,     0,     0,
       0,     0,  1324,   551,     0,   761,  1039,     0,  2119,     0,
      93,   543,     0,    65,     0,     0,     0,    78,     0,    93,
      93,   118,   113,  2152,  2152,   103,     0,   869,   863,   871,
     870,   860,   547,   918,     0,     0,     0,     0,     0,   677,
     656,   670,   626,   732,     0,   716,   714,   720,   718,     0,
    2152,     0,  2152,   712,   710,   706,   704,   754,   708,    24,
     744,     0,     0,     0,    27,     0,  1674,     0,  1594,     0,
       0,  1606,  1589,  1605,  1425,     0,  1388,     0,  1334,     0,
       0,  1690,     0,  1687,  1611,     0,     0,     0,     0,     0,
       0,  2036,  1333,  1332,  1320,  1318,     0,  1379,     0,  1372,
       0,   581,   578,   573,   575,     0,  2152,  2152,   589,   591,
    2152,  2152,     0,  1571,     0,     0,     0,     0,  1659,  1665,
    1655,  1656,  1657,  1658,  1441,     0,  1435,  1455,     0,  1459,
       0,  1472,  1458,     0,     0,  1473,  1488,  1485,  1486,  1483,
    1491,  1490,  1484,  1487,     0,     0,     0,     0,     0,  1489,
       0,     0,     0,  1429,  1430,  1635,     0,  1449,  1443,  1236,
    1620,  1340,  1336,  1337,  1342,  1341,  1618,  1235,     0,  1183,
    1184,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1182,     0,     0,  1170,  1171,  1172,  1169,  1174,
    1175,  1176,  1173,  1160,  1151,     0,     0,  1207,     0,  2152,
       0,  1146,     0,     0,     0,     0,     0,     0,     0,  1138,
    1139,     0,  1071,     0,  1282,  1420,  1540,     0,  1541,     0,
       0,     0,     0,  1401,  1272,  1400,  1392,     0,     0,     0,
    1529,  1521,  1521,     0,     0,  1521,  1528,     0,  1545,  1407,
    1409,  1413,  1414,  1267,  1263,  1004,     0,   967,     9,     0,
    1235,   839,  1068,   355,  1229,     0,     0,  2136,     0,     0,
     972,    49,     0,   741,   160,   158,     0,  2152,     0,     0,
       0,  2152,   156,   145,     0,   148,   147,     0,   978,   982,
     347,     0,   554,     0,  2152,   763,     0,   625,  1118,     0,
    1209,    70,     0,     0,   101,    68,    93,    76,    82,     0,
     120,   116,   757,  2152,   873,   625,   872,     0,   544,     0,
     787,   788,   786,  1056,   956,   954,   680,   678,     0,   660,
     657,     0,   722,   700,   724,   702,   733,   747,   748,   745,
     746,    30,    28,     0,  1668,  1623,  1595,  1591,  1590,     0,
    1387,  1627,  1390,     0,  1308,  1303,  1302,  1305,     0,  1623,
       0,     0,  2069,  2067,     0,     0,  2055,  2066,     0,     0,
    2068,     0,     0,     0,     0,     0,  2091,  2065,  2061,     0,
    2053,  2056,  2057,  2064,  2060,  2084,     0,  2046,  2045,  2049,
    2051,     0,  2044,     0,  2047,  2038,  1321,  1316,     0,  1378,
       0,   585,   583,   595,   597,   593,     0,     0,  1626,     0,
    1703,     0,     0,  1438,  1457,  1451,  1453,  1460,  1462,  1460,
       0,  1467,  1460,     0,  1465,  1460,     0,  1475,  1474,     0,
    1476,     0,  1428,     0,  1344,  1343,  1339,  1621,   236,  1177,
    1178,  1179,  1181,  1164,  1162,  1161,  1165,  1166,  1163,  1180,
    1167,  1168,  1152,   964,  1187,   961,     0,     0,  1205,     0,
    1150,  1149,  1144,  1142,  1141,  1145,  1143,  1147,  1148,  1140,
    1193,  1397,     0,  1393,  1399,  1543,  1536,  1403,  1511,     0,
    1513,     0,     0,     0,     0,  1519,  1523,     0,  1503,  1415,
    1003,  1243,  1232,     0,    24,     0,     0,   995,     0,    50,
     975,     0,    24,   162,   152,     0,   635,   637,   164,   154,
     741,     0,   346,  1325,     0,  1040,    24,     0,     0,    66,
       0,    79,    88,     0,    72,   864,   861,   548,  2152,   933,
       0,  2152,   676,   655,   661,   625,  1678,     0,  1676,     0,
       0,  1596,  1592,  1389,     0,  1391,  1385,     0,  1307,     0,
    1688,     0,  2059,  2058,     0,     0,  1495,     0,  1495,  1495,
    1495,  1495,  2062,     0,     0,  2042,     0,     0,     0,     0,
    2071,  2043,     0,     0,     0,     0,     0,     0,  2037,     0,
    1380,  1383,  1367,  1381,  1384,   833,   832,   330,  1701,  1702,
    1442,     0,  1479,  1481,     0,  1468,  1471,  1470,  1478,     0,
    1480,  1460,     0,  1431,  1338,   214,   966,   965,   963,     0,
    1186,  1072,  1076,  1078,     0,  1082,     0,  1080,  1084,  1073,
    1074,     0,   855,     0,     0,  1537,  1542,     0,  1530,  1522,
    1506,  1504,     0,  1507,   356,   353,     0,   993,     0,     0,
       0,   974,   742,   140,   634,    24,   984,   552,  1037,    67,
    1210,    84,     0,     0,    77,    88,    88,  2152,   545,     0,
       0,   679,   734,     0,  1675,  1624,  1617,     0,  1309,     0,
    1617,  2082,     0,     0,  2085,     0,     0,     0,     0,     0,
       0,     0,  2054,  2073,  2074,  2072,  2070,  2052,     0,  2048,
    2050,  2039,  2040,  1322,     0,  1368,  1366,  1461,  1666,  1463,
       0,  1466,  1464,  1482,     0,   962,  2152,  2152,  1086,  2152,
    1088,  2152,  2152,  1075,  1206,  1194,     0,     0,  1520,   358,
     994,  2135,     0,     0,     0,     0,     0,     0,    55,     0,
      54,     0,    52,     0,     0,   141,  1044,    88,    93,    88,
      89,    83,    73,   862,     0,     0,   681,    24,  1677,  1616,
    1625,  1313,     0,  1310,  1312,  1597,  2083,     0,     0,  2081,
       0,     0,     0,     0,  2063,  2080,     0,  1382,  1469,  1477,
    1077,  1079,  2152,  1083,  2152,  1081,  1085,  1538,  1515,   364,
     362,   354,     0,   360,   366,    57,    62,    59,    61,    58,
      60,    56,     0,    51,     0,   636,   638,  1048,  1038,     0,
    1046,  1211,    85,    80,   546,   934,  2152,   735,     0,  1304,
       0,  1598,  1612,  2079,  2086,  2075,  2076,  2077,  2078,     0,
    1087,  1089,  2152,  2152,   359,   361,  2152,    53,     0,  2152,
    1045,  1047,     0,   677,  1311,     0,  1602,  1599,  1600,  2041,
     365,   363,   367,     0,  1049,    86,   682,     0,     0,     0,
     976,    90,     0,  1603,  1601,    92,     0,    87,     0,    91,
    1604
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   824,   825,   826,   827,  1042,  2318,  2319,   209,   348,
     210,  1376,  1377,  2167,  2469,  3390,  2930,  2931,  3299,  3391,
    3392,   828,  1169,  2962,  2690,  3316,  2109,  2688,  3182,  2966,
    3312,  2689,  3183,  3398,  3492,  3511,  3314,  3517,   656,   657,
     658,  1487,  2385,   829,  1498,  1174,  1496,  2117,  2395,  2114,
    2393,  2398,  2694,  1497,  2392,  2118,  2693,   830,    18,    37,
      38,    39,    40,    41,   116,   833,  1102,  2065,  1400,  2345,
    2349,  2350,  2346,  2347,  2937,  2941,  2664,  2656,  2655,  2657,
    2660,   512,   296,   610,   834,    85,    86,    20,    63,   144,
      98,   281,   100,   101,   225,   362,   102,   103,   268,   367,
     254,  1004,   538,  2838,   393,   935,  2221,   420,   421,   255,
     375,   368,   370,  1319,  1320,   148,   550,   149,   150,   381,
     256,   257,  2056,   588,   269,   272,   270,   271,   402,   565,
     566,   568,   573,   938,   273,   274,   411,   570,   221,    21,
      82,   180,   181,   182,   944,  2782,   183,   277,   266,   414,
     415,   416,   417,  2078,   835,   836,   837,   838,  1061,  3379,
    3154,  1378,  3441,  3442,  3443,  3483,  3482,  3486,   839,   840,
     841,   842,   843,   844,   845,  1053,   513,  1056,  1370,  1371,
    1409,  1139,  1410,   323,   324,   325,   326,   327,   328,   329,
     470,   514,  1303,   515,   516,   517,   518,   519,   520,   521,
     983,   211,   532,   993,   995,  1977,   212,   526,   989,   525,
     988,   528,   991,   527,   990,   953,   962,   330,   331,   214,
     332,   440,   441,   442,   443,  2102,   846,  3188,  3404,  2978,
     847,  1112,  2080,  2954,  2366,   117,   263,   560,  1910,  1235,
    1236,  1237,  1907,  1908,  2208,  2209,  2210,  2522,  2523,  1911,
    1912,  2204,  2526,  2518,  2216,  2217,  2529,  2530,  2780,  2776,
    2777,   848,  1418,    87,  2051,  2052,  2361,   426,  1094,  1144,
    1025,  1083,  1066,  1103,  2427,   215,  1026,  1020,  2018,  2659,
      89,   333,   849,   850,  1190,  1191,   851,   852,   853,   854,
    1198,  2989,  1219,  3193,  1220,  2144,  1221,  2424,  1222,  2710,
    1223,  2170,   855,  2140,  2709,  2988,  3191,  3190,  3466,   118,
      22,   856,  1394,  2057,  2058,  2160,  1856,  2161,  2162,  2720,
    2722,  2440,  2439,  2444,  2438,  2437,  2430,  2429,  2432,  2431,
    2434,  2436,   857,   858,  1100,   859,  1852,  1205,  3407,   860,
    1464,  3162,  2471,  2472,  2163,  2441,  2401,  2696,  1135,  1446,
    2084,  2369,  2085,  1442,   861,   862,  1183,  2132,  2982,   863,
     864,   865,   866,    23,    68,    24,    25,    26,   119,   120,
     867,   121,    27,   925,    28,   122,   123,   160,   562,  1916,
    2534,  3246,   124,   156,   386,   868,  2637,    29,    30,    31,
      32,    33,    62,    90,   125,   681,  1983,  2589,   869,  1178,
    2405,  2121,  2403,  3317,  2973,  2122,  2402,  2699,  2975,   870,
     871,   872,  1077,  1078,  1500,   126,   264,   561,   929,   930,
    1239,  1914,   873,  1224,  1225,   874,  1864,  1226,   334,    92,
      93,    94,    95,  1507,   186,   140,    96,  1031,   137,   217,
     218,  1508,  1509,  2412,  1510,   678,   679,  1207,   680,  1208,
    2421,  2422,  1511,  1512,  1374,  3114,  3115,  3268,  2027,  1092,
    1093,   875,  1389,  3301,   876,  2949,   877,  1404,  1405,  1406,
    2071,  2069,   878,   879,  2329,  2356,   880,  1352,  2024,   881,
    1136,  1137,   882,  1016,   883,  2482,   884,  3396,  2957,   885,
    2373,  3458,  3459,  3460,  3489,  1141,   886,  1513,  2134,  2416,
    2417,   887,  2044,  1024,  1364,   888,   889,   890,  2591,  3118,
    3279,  3280,  3366,  3367,  3371,  3369,  3372,  3432,  3434,   891,
     892,  1502,  2126,   893,  1504,  1155,  1156,  1157,  1480,   894,
     895,   896,  2095,  1472,  1150,   224,  1158,  1159,   335,  2592,
    2879,  2880,  2863,  1050,  1051,  2587,  2864,  2867,   127,   155,
     554,  1329,  2271,  2881,  3283,   452,   897,  1148,   128,   152,
     551,  1326,  2269,  2868,  3281,  2588,  1173,  2680,  3178,  3397,
    1475,   898,   899,   900,   901,   902,  1064,  2327,  1044,  2323,
     903,  2830,  1038,  1039,  2634,  2003,   904,   905,  1338,  1339,
    1340,  2015,  2308,  1341,  2305,  2012,  1342,  2280,  2004,  1343,
    1344,  1345,  1346,  2274,  1995,   906,  1073,  1055,   907,  1888,
    1889,  2185,  3016,  3209,  2750,  3013,  3412,  3413,  1890,  2192,
    2764,  1870,  2512,  3057,  3239,  2673,  2953,  2513,  1891,  1892,
    2258,  2832,  2833,  2834,  3096,  1893,  1894,  1408,   908,  1106,
     909,  1232,  1895,  1896,  3356,  2198,  2199,  2200,  2515,  2766,
    3242,  3243,  1897,  2492,  2745,  3206,  2005,  2006,  1991,  2600,
    2272,  2601,  2007,  2605,  2008,  2621,  2009,  2622,  2910,  2911,
    2275,  1898,  2179,  2180,  2489,  1899,  2827,  2578,  2823,  2253,
    1959,  2248,  2249,  2250,  2795,  1960,  2254,  2579,  2828,  2568,
    2569,  2570,  2571,  2572,  3252,  3077,  3357,  2573,  3254,  3255,
    2821,  2574,  2822,  2575,  2237,  2301,  2302,  2303,  3142,  2304,
    2907,  2901,  3289,  2602,  3244,  2888,  3049,  2604,  2563,  1281,
     336,  1282,  1944,   463,   954,  1929,  1945,  2544,    61,   910,
     911,  3008,  3202,  2738,  3201,  3472,  3497,  3498,  2742,  2483,
    1900,  2484,  2501,  3019,   613,  2479,  2480,  2259,  2581,  3200,
    3012,  1283,   968,  1284,  1285,  2824,  2576,  1287,  1288,  2239,
    3359,   912,   913,  2172,  2481,  3004,  3197,  3198,  1867,   914,
    1059,  1902,  1903,  2188,  2752,  1904,  1905,  2498,  1972,  2232,
     915,  1186,  1841,  1842,  1843,  2136,  1844,  2137,  1906,  2502,
    3055,  3238,  2761,  3052,  3053,  3054,  3051,  3039,  3040,  3041,
    3042,  3043,  3044,  3335,  1032,  1289,  1034,  2028,  1290,    66,
      50,    80,    77,   917,  1161,  2099,  1397,  1466,   918,   428,
     919,  2648,   920,  2317,  1036,  2030,   921,   922,    44,   555,
     556,   557,   558,   559,   923
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2807
static const short yypact[] =
{
    2667,   802, -2807, -2807,   291,   552,   552,   552,   552,   552,
     552,   552,   552,   291,  1250, -2807, -2807,  1250, -2807,  2025,
   -2807, -2807, -2807,   327, -2807,  2667, -2807, -2807, -2807, -2807,
   -2807,  1382, -2807, -2807, -2807, -2807, -2807,   317,   391, -2807,
     436, -2807, -2807, -2807, -2807, -2807,   291,    56, -2807,  -157,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  1017,   402, -2807, -2807, -2807, -2807,  1669, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,   291, -2807,
   -2807,    56,   228, -2807,   291,   622,  2025, -2807,   695, -2807,
   -2807, -2807, -2807,   997,   304, -2807, -2807, -2807,   933,   617,
     291, -2807, -2807,   988,   291, -2807, -2807,   291,   291, -2807,
   -2807, -2807, -2807,   291,   291, -2807, -2807, -2807, -2807, -2807,
    1669, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  5854,   304, -2807,   348,  1429, -2807, -2807,   539,
   -2807, -2807,  1042,   402,   546, -2807, -2807, -2807, -2807, -2807,
    4999, -2807,   291,   626,   968,   291,  2025, -2807, -2807, -2807,
     291, -2807, -2807,   547,   650, -2807, -2807,   745, -2807,   759,
   -2807,   655, -2807, -2807,   791, -2807,   840, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807,   787, -2807, -2807, -2807,
     853,   866,   871,   889,   893,   898,   909,   915,   921,   941,
    1429,   980,  4535,   999,  1004,  1008,  1029,  1033,  1041,  1806,
    1213, -2807, -2807, -2807, -2807,   702, -2807,   165, -2807,  1429,
   -2807,   119, -2807, -2807, -2807,   113, -2807, -2807, -2807,   849,
   -2807, -2807, -2807, -2807, -2807,   547, -2807,   650, -2807, -2807,
    1052, -2807,  1055, -2807,   783, -2807, -2807,  1061, -2807,  1071,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1079,  1259,
     291,  1092, -2807,  2025,  2025,  1121,   291, -2807,   366, -2807,
     766,   896, -2807,   793,  1115,  1506,  1527,   291,  1536,  1545,
    1550, -2807,   952, -2807,    46,    46,    46,    46,    46,  4535,
    1292,  1682,    46,  4535,  1028,  4535, -2807,  4535,  4535,  4535,
   -2807, -2807, -2807,  1057,  1158,  1165,  4535,  1173,  1168, -2807,
    4535,  4535,  1176, -2807,  1177, -2807,  1004,  1178,  1183,  1185,
    1186,  1583,  8306,    66, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,  1205, -2807, -2807, -2807, -2807, -2807,
   -2807,   452,   452, -2807, -2807, -2807, -2807, -2807,  1429, -2807,
   -2807,   291,  1429,  1171,   174, -2807, -2807, -2807, -2807,  1613,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,   366,
   -2807, -2807, -2807,  1614,  1618,   402,  1536,  1620,  1624,  1027,
   -2807,  1590, -2807,  1257,  1221, -2807,  1295, -2807, -2807, -2807,
    1037, -2807, -2807,  1632, -2807,  1227, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,  1115,  1227, -2807, -2807, -2807, -2807, -2807,
   -2807,  1233,   249,   256,   265, -2807,  2044, -2807, -2807, -2807,
    1244,  1673,   259,  1283, -2807,  1247, -2807,  -179,   262,  1287,
    1289,   263,   267,  3615,  1297,  -110,  1344, -2807, -2807,    75,
    1298, -2807, -2807, -2807,   274,  4778, -2807,  3901,  8555,  1865,
    1865,  4535, -2807,  1214,  4535,  8306,  1256, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,  1066,  1680,  5089,  8306,  1214,  1684,
     355,  4535,  4535,  4535,  4535, -2807,  4535,  4535,  4535,  4535,
    4535,  4535,  4535,  4535,  4535,  4535,  4535,  4535,  4535,  4535,
    4535,  4535,  4535, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,  4535,  4535, -2807, -2807,  1273,  4535, -2807,
    4535,  1279, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,   452,  4535,  4535,  4535,  4535,  1320,
    1719,  1806,  4535,  1290, -2807,  1429,  1263, -2807,  1099,  1107,
    1707,  1472,   281,   331,   289,  1304,   334,  1340, -2807, -2807,
   -2807,   291, -2807, -2807,   291,  1373, -2807,  6699,   546,  6989,
    1768,   449,   291,  1720,   582, -2807,   896,  1715, -2807, -2807,
   -2807, -2807,  1716, -2807,  1718, -2807,  1722, -2807,   291, -2807,
     291, -2807, -2807,  1536,  1724, -2807, -2807, -2807, -2807,   291,
    1429,    48,    46, -2807, -2807, -2807, -2807, -2807, -2807,  1173,
    1173,  1725, -2807,  1729,  1150,  1322, -2807, -2807, -2807, -2807,
    1360,  8306,   -47,  1362,  7564,  1739,  1173,  1374, -2807,  1380,
    1387, -2807,  7614,  7678,  7725,  7789,  8374,  8421,  8555,  8594,
    8628,  8743,  8810,  4786,  8858,  9060,  9050,  1865,  1865,  9280,
    9280,  9287,  8306,  7903,  8117,  1214,  8306,  8242,  1214, -2807,
    8306,  8306,  8306,  8306, -2807,  1744, -2807,  1781, -2807,  8306,
   -2807,   193,  1429, -2807,  1770,   582,  1366,  1769, -2807,  1779,
   -2807, -2807, -2807,  1782, -2807, -2807, -2807,  1182,  1413,  1809,
   -2807,   291,  1419, -2807, -2807, -2807,   452,   452,   452,   353,
     291,   269,   291,   291,   269,   269,   891,   291, -2807,   291,
   -2807, -2807,   291, -2807,   752, -2807, -2807, -2807,   269, -2807,
   -2807, -2807, -2807,   291, -2807, -2807, -2807, -2807,   147,   147,
    4535, -2807, -2807, -2807, -2807, -2807, -2807,   269, -2807, -2807,
     269, -2807, -2807,   291, -2807, -2807,   269, -2807, -2807,   452,
     269, -2807, -2807,  4535,   269,   452,   291,   452,   269, -2807,
   -2807,   189,   269,   269,   189,   269,   291,   189,   269, -2807,
     269,   269,   269, -2807, -2807, -2807, -2807,   452,   269, -2807,
   -2807,   269,    35,   291, -2807, -2807, -2807, -2807,   269,  1005,
   -2807, -2807, -2807,   269, -2807,  5017,   452,  4535,    46,    46,
     269, -2807, -2807,   353,   452,  1006,  4535,  4535, -2807,  1102,
    4535,   269,    56, -2807,  4535,   269,  1791,   452, -2807,   269,
    4535, -2807,  4535,   147,   291,   269,   291,    46,   269,   291,
      46, -2807,   291,   140, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,   222, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,  1117, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,   720, -2807,   291, -2807,   642,
   -2807,  1421, -2807, -2807, -2807,  1523, -2807, -2807,  1434,  1435,
    1436,  1438, -2807, -2807,  1207,  1832,  1443,  1448,   417, -2807,
    1410, -2807, -2807, -2807,  1224, -2807,  1455, -2807,  1830, -2807,
    1264, -2807, -2807,  1230, -2807, -2807, -2807, -2807,  9169, -2807,
    1057,  1465, -2807,  1057, -2807,  1057,  1057,  1057,  1057,  1057,
    1838,  1839,  1841,  4535,  1471,  1845,  4535,  1477,  1478,  1487,
    1493,  1494,  1500,  1503,  4535,  4535, -2807,   213, -2807, -2807,
    1581, -2807,  1505,  1509,  1278,  1511,   291, -2807,   291,  1512,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,   332,  1475, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1268,  1457,
    1449, -2807,  1296, -2807,  1294, -2807,  1904,  -148,   337, -2807,
   -2807, -2807,  1482, -2807,  1479, -2807,  1431,   186, -2807, -2807,
   -2807,  1425, -2807,  8306, -2807, -2807, -2807,  1167, -2807, -2807,
   -2807,   452, -2807, -2807,  1479, -2807,   -79, -2807, -2807,  1646,
   -2807,    32, -2807,  1458, -2807, -2807, -2807, -2807,  1919, -2807,
   -2807,   480, -2807,  1303, -2807,  1306,  1919, -2807,  1326, -2807,
   -2807,  1504,   164, -2807,  1467, -2807,  1269, -2807, -2807, -2807,
   -2807,  1270,   264,  -231, -2807,  1268,  1605, -2807,  4535,  4535,
   -2807,  1929,   269, -2807, -2807, -2807, -2807, -2807,    58,    58,
      58, -2807,    58,  1900,    58,    58,  1337,   -79,  1337,  1337,
    1034,  1034,  1337,  1337,   -79, -2807,  1936, -2807,   559,  1937,
   -2807,   -79,    74,    54, -2807, -2807,  4535, -2807, -2807, -2807,
     881, -2807, -2807,   546,  1554,   546,  4535, -2807,    73, -2807,
   -2807,  4535,  1513,  1514,  1515,  1519,  1491,  1520,  1006, -2807,
    1596,   936,  1353, -2807,  1386, -2807, -2807, -2807,  1038, -2807,
    1949, -2807,  1957,   291, -2807,   231,  6104,  1393, -2807, -2807,
    1971, -2807,  1313,  1971,  1976,  1319,  1971,  1976,  4535,  1971,
   -2807, -2807,   186,   452, -2807, -2807,  1558,   295, -2807, -2807,
    1549,   452,  4535,  1551, -2807, -2807,  1960,  1964,  1921, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1068,  1068,   269,
     269,   269,  2375, -2807, -2807,  1896,   720, -2807, -2807,   731,
   -2807, -2807, -2807,  1529, -2807, -2807, -2807, -2807,  5854,  1536,
   -2807, -2807,  1369,   291,  1271,  1173,  1401,  1496, -2807,  9391,
    9391, -2807,  1268, -2807, -2807,  1293, -2807, -2807,  6355,  1562,
   -2807,  1564,  1565, -2807,  1566,  1567,  1569,  1571,   291,     6,
   -2807, -2807, -2807, -2807,   117, -2807,   291,  2365, -2807,  1582,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  8306,   349, -2807, -2807,   367, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1546, -2807,   369,
   -2807, -2807, -2807, -2807, -2807, -2807,  2025, -2807, -2807,  2025,
     806,   148,  1985, -2807, -2807,   370,   157,   399,  2010, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1524,  1457,  1294,
   -2807,   891,   -50,  1097,   291, -2807, -2807,   291, -2807,  1416,
    1394,  1426,  1584, -2807,  1588,   100, -2807, -2807, -2807, -2807,
   -2807,  2022, -2807, -2807,  1400,  1597, -2807, -2807, -2807,   891,
    1074, -2807,  1074,  1006,   189,  4535,  4535,  4535,  1598, -2807,
   -2807,   452,   452, -2807,  1405,  1006,    46,  1371,    35,   452,
   -2807,  1409,  4535,  1687, -2807, -2807,  1481, -2807, -2807,  2039,
   -2807,   128,   186, -2807, -2807,  2027,  2029, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  2582, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  5017, -2807,  1034,  4535,   406,
    2020,  2024, -2807, -2807, -2807, -2807, -2807,   107, -2807, -2807,
   -2807, -2807,  1895, -2807,  1833, -2807, -2807, -2807,  4535,   147,
   -2807, -2807,   291,  2028,    46,    46, -2807,  1460, -2807,    46,
    1432,   452, -2807,   291,   291,  4535,   442, -2807,  1473, -2807,
     276, -2807,  1585, -2807,  1587,  4535,   918, -2807, -2807,  1444,
   -2807,  2070, -2807,  1526, -2807,   452, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  5434, -2807, -2807, -2807, -2807,   291,    46,    46,   217,
     295,  1924,   970,   452,   186, -2807,  1528, -2807, -2807,  2039,
    2055,  1678, -2807, -2807, -2807, -2807, -2807,  1758,  1758, -2807,
     616,  1534, -2807,   291, -2807, -2807,  1479,  1479, -2807, -2807,
   -2807,   291, -2807,   291,   -47,  1479, -2807,   118, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,   199,   199,   446,
     782, -2807,   425, -2807,   731, -2807,  2025,  2061, -2807, -2807,
    1113,  1691,  1653, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  1530, -2807, -2807, -2807,  2543,  2543, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  1459,   -47,  1694,   856,   491,
    9169,   491,   491,   491,   491,  1480,  9169,  9169,   177,  1573,
      -8, -2807,  9169,  9169,  9169,  9169, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,   891,  4535, -2807, -2807,  1705,  2061, -2807,
   -2807, -2807, -2807,  2025, -2807, -2807,  1479, -2807,   771, -2807,
    1670, -2807, -2807,   771, -2807, -2807, -2807,  1671,  1672,   307,
    1675,  1677,  1134, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
     291, -2807, -2807,   307,  1445, -2807,   332, -2807,  1721,   304,
    1490, -2807,  1006,  1535, -2807, -2807,  1652, -2807, -2807, -2807,
    1568, -2807,   291,   291,   291, -2807, -2807, -2807,  1167,   291,
   -2807,  1499, -2807, -2807, -2807, -2807,  1492, -2807,  2120,  2123,
   -2807,  2125,  1552,  4535, -2807, -2807,  1510,  2126, -2807,  1648,
    1507,  1976, -2807, -2807,  1516,   803,   291, -2807, -2807,  1698,
     269,   804,  4535, -2807,   291,   291,  4535,    55,   -79,  2135,
    2134,  2117,  2118,  1900, -2807, -2807, -2807, -2807, -2807,   452,
    1604, -2807, -2807,  2080,  4535,   546,   917, -2807, -2807,  1821,
    2149,  2153,   390, -2807,   396,   291,  1767,  1006, -2807,  4535,
    1730,  1734, -2807, -2807,  1800, -2807,  4535,   455, -2807,  1572,
   -2807, -2807,   523, -2807,  4535, -2807, -2807,  1540,   348, -2807,
    1130,   291,  2165,  6827, -2807, -2807,   891,   452, -2807, -2807,
     191, -2807,  1976,  1976,  1531, -2807,  1641,  1628, -2807, -2807,
   -2807, -2807,    46,    46, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,   861, -2807, -2807, -2807, -2807,    46,  9733,  2183,  2174,
   -2807,  1006,   811,   298,   132,  2096,    29,   353, -2807,   145,
   -2807, -2807, -2807,  1774,    34,  1479,   290, -2807,  1578,  1574,
   -2807, -2807,   600, -2807, -2807, -2807, -2807,  1776,  1576,  2199,
   -2807, -2807, -2807,   452,   142, -2807, -2807, -2807,  1570,   782,
   -2807,   291,   291, -2807, -2807,   291,   610, -2807, -2807, -2807,
   -2807,  1787, -2807, -2807, -2807,  2187, -2807, -2807,  1417,  9169,
   -2807,   302,  1823,  2216, -2807, -2807, -2807,  9169, -2807,   403,
    9169,  9169,  9169,  9169,   291,   404, -2807,   169,  2217, -2807,
   -2807,   291,  4813, -2807,  1851,   291,  1602,   491,  1892, -2807,
   -2807, -2807, -2807, -2807, -2807,  8306, -2807,  1798, -2807,  1765,
   -2807,  1778, -2807,  1810,   408, -2807,  4813,   411,    96,    96,
     412, -2807,    96,  4813, -2807, -2807,  1293,  1293, -2807,  1816,
   -2807,  1817,  1818, -2807,  1819,  1822, -2807,  1826, -2807, -2807,
   -2807,   131, -2807, -2807, -2807,   420, -2807, -2807,   435,   291,
   -2807, -2807,  1097,  2226,  1006,  1429,  4535, -2807,  2237, -2807,
   -2807, -2807, -2807,   307, -2807, -2807,  1638,   307,   215, -2807,
    1006,  4535,  4535,  4535,  3868,  2240,    86, -2807, -2807,  1006,
     291, -2807, -2807,   291,   291, -2807,  1327, -2807, -2807,   305,
   -2807,  1639,  4535, -2807, -2807, -2807,  2257, -2807, -2807, -2807,
   -2807, -2807,   291,  1976, -2807, -2807,  1708, -2807, -2807,   443,
   -2807, -2807, -2807,   452, -2807,  4025, -2807, -2807, -2807,  1939,
    2245, -2807,    46,  1922,  1928,  1820,  1655,  1932,  1837, -2807,
   -2807, -2807,   550,  1917, -2807, -2807, -2807, -2807,  1800, -2807,
   -2807, -2807,   238,   619, -2807, -2807, -2807,  2039,  4535,  1852,
   -2807,  1824, -2807, -2807, -2807, -2807,  2281, -2807, -2807, -2807,
    1861,  2284, -2807, -2807,  1634, -2807,  2272,   -79,   291,  1318,
    1318,  1318,  1318, -2807,  2295, -2807,  2297,  1318,  1318,  1318,
    1318,  2582, -2807, -2807,  1318,   111, -2807, -2807, -2807, -2807,
    2278,  2290, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  2292, -2807, -2807, -2807, -2807, -2807, -2807, -2807,   456,
   -2807, -2807, -2807,  2285, -2807, -2807,  1479, -2807,   -47, -2807,
   -2807, -2807, -2807, -2807, -2807,  1706,  1712,   123, -2807,   145,
   -2807,    96,  1692,   269, -2807,  1879, -2807, -2807, -2807,   291,
     291,  9169,   194, -2807,  4535, -2807,  4535, -2807, -2807, -2807,
   -2807, -2807, -2807,   269,    96, -2807,  1479,  1153,  2311, -2807,
     452,   291,   823,   823, -2807, -2807,  2312, -2807,  2312,   724,
     724,  2312, -2807, -2807,  1768, -2807,  1925, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,   117,  1293,  1690, -2807,  1293,
    1931,  9169, -2807,  1933,  1934,  1940,  1941, -2807, -2807,   177,
   -2807,   177, -2807, -2807,  9034,  1889,  3957,  1889,  2323,  2327,
   -2807, -2807, -2807, -2807, -2807, -2807,   299,  9169, -2807,  1888,
   -2807,  2069,    93,   298,   291, -2807,  3318,    60, -2807,  1768,
    1995, -2807,    60,    96,   771, -2807,   246, -2807,  1479,   488,
    1952,  2341,  1726, -2807, -2807,   457, -2807,   307, -2807,   460,
     253,  1728,  -131,  2324,  2324,  2331,  2324,  2324,  2335, -2807,
     212, -2807,   771,   291, -2807,   307, -2807, -2807,  1737,  1006,
    2345,   220, -2807,   291,   462, -2807,  4535,  1966,  2344,   473,
    1006,  2360, -2807, -2807, -2807, -2807,  4535,  1794,  2091,  4535,
   -2807, -2807, -2807, -2807,   305,  1359,  1359,  2366,   -76, -2807,
    2368, -2807, -2807, -2807,  1359,   291,  1825,  1162,  2369,   291,
     -64,  4535, -2807, -2807,  1900, -2807,  1702,  4535, -2807,  2371,
    4535, -2807,   452, -2807,   752,   291,   452, -2807,  1982,  4535,
    4535, -2807, -2807,   550,  1917, -2807,  2582, -2807, -2807,  1083,
   -2807, -2807,  1803, -2807,  1429,  4323,  6827,   452,   452,    68,
     819, -2807, -2807, -2807,  1756, -2807, -2807, -2807, -2807,    46,
    1318,    46,  1318, -2807, -2807, -2807, -2807, -2807, -2807,   -79,
   -2807,   961,  1096,  9733, -2807,  1991,  1946,  9169, -2807,   132,
     132, -2807, -2807, -2807, -2807,   478, -2807,  1913, -2807,    96,
     155, -2807,  1760, -2807,  2387,  9244,  9244,  9244,  9244,    96,
      96, -2807, -2807, -2807,  1834, -2807,   485, -2807,  1763, -2807,
     452, -2807,  2312, -2807, -2807,   291,   724,   724, -2807, -2807,
     724,  2180,  1771, -2807,  2000,  1777,  1417,  1780, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,   487, -2807, -2807,  1923, -2807,
     260,   214, -2807,  4813,  4813, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,  9391,  9391,  1973,  9391,  1974, -2807,
    9391,   812,  9169,  2402, -2807, -2807,  4813, -2807, -2807, -2807,
   -2807, -2807,  2408, -2807,  -144, -2807, -2807,  2069,  1785, -2807,
   -2807,   147,   147,   147,  2390,   147,   147,   147,   147,   147,
     147,  2391, -2807,  2392,   147, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,  3318, -2807,   452,  1795, -2807,  1968,  2180,
    2397, -2807,  2398,  2400,  2404,  2405,  2406,  2407,  1126,  1995,
   -2807,  1968, -2807,   494, -2807, -2807, -2807,  2409, -2807,  2127,
      96,  1189,    96, -2807, -2807, -2807, -2807,  1417,  2411,  1417,
   -2807,  2429,  2429,   498,  2041,  2429, -2807,  2042, -2807, -2807,
   -2807,   771, -2807, -2807, -2807, -2807,  1006, -2807, -2807,   307,
    2069,  2039, -2807,  1970, -2807,   216,  1006, -2807,  2439,  2014,
   -2807, -2807,  2056,  1898, -2807, -2807,   291,  1359,  1429,  1266,
     291,  1359, -2807, -2807,    46, -2807, -2807,  4535, -2807, -2807,
   -2807,    46,  2039,   452,  2207, -2807,  2432,  1641,  8306,  2430,
   -2807, -2807,   186,  2037, -2807, -2807,  4535, -2807, -2807,  2062,
   -2807, -2807, -2807,   619, -2807,  1641, -2807,  4535, -2807,   234,
   -2807,  1937, -2807, -2807, -2807, -2807, -2807, -2807,  2031,  2111,
   -2807,  2450, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,   291, -2807,   181, -2807, -2807, -2807,    96,
   -2807,   -47,  2330,   508, -2807, -2807, -2807, -2807,   291,  1912,
    9474,  9474, -2807, -2807,  9270,  2052, -2807, -2807,  2054,  2063,
   -2807,  2065,  2066,  2067,  2068,   291,    95, -2807, -2807,   511,
   -2807, -2807,  2384, -2807, -2807, -2807,   512,  2473,  2473, -2807,
   -2807,   516,  2486,  2478, -2807,   103, -2807, -2807,    96, -2807,
     154, -2807, -2807, -2807, -2807, -2807,  2293,  5854, -2807,  1417,
   -2807,  1417,   177, -2807, -2807,  2327, -2807,  2058,  2365,  2058,
     182, -2807,  2058,   182, -2807,  2058,  9391, -2807, -2807,  9169,
   -2807,  9169,  2323,    93, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,   416,  2502, -2807,   452,  1077, -2807,  2293,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,   236, -2807, -2807, -2807,  2045, -2807, -2807,  2114,
   -2807,  2488,  2121,  2122,  2489, -2807, -2807,  2124, -2807, -2807,
   -2807, -2807, -2807,    46,   -79,  2141,  1006, -2807,  4535, -2807,
    1948,  2497,   -79, -2807, -2807,   434, -2807, -2807, -2807, -2807,
     124,  2129,  1976,  2284,  2279, -2807,   -79,  2131,  2132,  2135,
    2094, -2807,  2182,  2136, -2807, -2807, -2807, -2807,  2288,  2073,
    4535,  2092, -2807, -2807, -2807,  1641, -2807,   520, -2807,   452,
    1987, -2807, -2807, -2807,  9169, -2807, -2807,    96, -2807,  2105,
   -2807,  1987,  2610,  2610,  2146,   856,   491,  9336,   491,   491,
     491,   491,  1920,  9336,  9244, -2807,  9336,  9336,  9336,  9336,
   -2807, -2807,    96,  2530,    96,  9244,   269,  4813, -2807,   452,
   -2807, -2807,   336, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,   212, -2807, -2807,   522, -2807, -2807, -2807, -2807,   528,
   -2807,  2058,  2539, -2807, -2807, -2807, -2807, -2807, -2807,   452,
    2502, -2807, -2807, -2807,   452, -2807,   452, -2807, -2807,  1543,
   -2807,  2304, -2807,  2305,  2524, -2807, -2807,  1935, -2807, -2807,
   -2807, -2807,  2155, -2807, -2807, -2807,  1006, -2807,  2156,  9756,
    2138, -2807, -2807, -2807,  1942,   -79, -2807, -2807, -2807, -2807,
   -2807, -2807,  2168,   186, -2807,  2182,  2182,   619, -2807,  1429,
    1972, -2807, -2807,   291, -2807,  2284,    -8,   117, -2807,  9103,
      -8, -2807,  2173,  9336, -2807,   529,  9336,  9336,  9336,  9336,
     291,   533, -2807, -2807, -2807, -2807, -2807, -2807,  2139, -2807,
   -2807, -2807,  2323,  2284,   154, -2807, -2807, -2807, -2807, -2807,
     208, -2807, -2807, -2807,  9169, -2807,  1793,  1793, -2807,  1793,
   -2807,  1793,  1793, -2807, -2807, -2807,  2140,  1417, -2807,  1123,
   -2807, -2807,    58,    58,    58,    58,    58,    58, -2807,  2551,
   -2807,   534, -2807,  4535,  1284, -2807,    -7,  2182,  4535,  2182,
    2135, -2807, -2807, -2807,  2337,   255, -2807,   -79, -2807, -2807,
   -2807, -2807,   535, -2807, -2807,  1299, -2807,  2184,  9336, -2807,
    2189,  2191,  2193,  2194, -2807, -2807,  9244, -2807, -2807, -2807,
   -2807, -2807,  1793, -2807,  1793, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,   585, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  9756, -2807,  2572, -2807, -2807, -2807, -2807,   800,
   -2807, -2807, -2807, -2807, -2807, -2807,   191, -2807,  9103, -2807,
    1559, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,   537,
   -2807, -2807,   932,   932, -2807, -2807,   932, -2807,  4535,   855,
   -2807, -2807,  2195,    68, -2807,  1959,  1975,  2588, -2807, -2807,
   -2807, -2807, -2807,  2198, -2807, -2807, -2807,   291,   291,  1559,
   -2807,   179,  1977, -2807, -2807, -2807,   186, -2807,   291,  2135,
   -2807
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2807, -2807, -2807, -2807, -2807,   -86, -2807,   -34,  -199, -2807,
   -2807, -1122,  -137, -2807, -2807, -2072, -2807, -2807, -2807, -2807,
    -848, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -1996, -2807,  -977, -2807,
    1611, -2807, -2807, -2807, -2807, -2807, -2807, -2807,   210, -2807,
   -2807, -2807, -2807,  1114, -2807,   499, -2807, -2807,   -54, -2807,
   -2807,  2580, -2807,  2583,  2074, -2807, -2807, -2807, -2807, -2807,
     282,   -38, -2807,   288, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  -149,   957,   432, -2807, -2807,
    2251,    44, -2807,  2477, -2807, -2807,  2490, -2807,  2403, -2807,
   -2807, -2807, -2807, -2807,  2266,  1981,   661,  2273,  -527, -2807,
   -2807, -2807, -2807, -2807,   671,  -658, -2807, -2807, -2807, -2807,
   -2807, -2807,  -158,  2103,  2415,   -45,  2046, -2807,  2093,  1399,
   -2807,  2256, -2807, -2807, -2807, -2807,  2259, -2807, -2807, -2807,
   -2807,  -414, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
    2086, -2807,  2088, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -1308, -2807, -2807,  -776, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  -121, -2807, -2807,   631, -2807,
   -1072, -1125,   280, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  1685, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
    -599, -2807, -2807, -2807, -2807, -2807,  1871, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  -531, -2807,  -133, -2807, -2807,
   -2807, -2807,  2238, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  1439, -2807, -2807, -2807, -2807,   467, -2807, -2807, -2807,
   -2807, -2807, -1914, -2807, -2807,   468, -2807, -2807, -2807, -2807,
   -2807, -2807, -1090,  -828,   350,   609, -2807,  -270,   421, -1095,
     935, -2807,   426, -2807, -2354,    -4,   180, -2807, -2807, -2182,
     207,  1000, -2807, -2807,   623,   841, -2807, -2807, -2807, -2807,
   -2807, -2807,   -20, -2807,  -298, -2807,   843, -2807,   554, -2807,
     270, -2807, -2807, -2807, -2807,  -794, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,   363, -2807, -1786, -2807,   540, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807,  1307, -2807, -2807, -2807, -2807, -2807,
   -2807,  -464, -2807, -2807, -2027, -2807, -2807, -2807, -2807,   257,
   -2221, -2807, -1099, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  2688, -2807, -2807,
   -2807,  2594,  2685, -1613, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  -399, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
    2690, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,   601, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  -694,  1965, -2807, -2807, -2807, -2807, -2807,  1796,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,  2306, -2807,
   -2807,   -39, -2807, -2807,   596, -2807, -2807, -2807, -1024,  -215,
    2374, -2807, -2807, -2807, -2807,   592, -2807, -1022,  1723,   875,
   -2664,    22, -2807,   603,  1532,  -384,  -533, -2807, -2807, -2807,
    1345, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807,  1285, -2807,  -749, -2807,  -620, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807,  -721, -2807, -2807, -2807, -2807, -2807, -2807,
      36, -2807,  1361,   450, -2807, -2807, -2807, -2807, -2807,  -140,
   -2807,  -535, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  1592, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  -517, -2807,  1272,  2276, -2807,
   -2807,  -130, -2807,  -656, -2807, -2807,  -106,   166, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807,  1088, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2488, -2807,  1402,   433, -1309, -2807, -2807, -2807,   746,
   -2807, -1926, -2807, -2807, -2807, -1922, -2807, -2807, -1928, -2807,
   -2807, -2807, -2807,   768, -2807, -2807, -2807, -2807, -2807, -2807,
     278, -2807, -2807, -2807, -2807, -2807, -2807,  -705, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807,  -326, -2807, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,   251, -2807, -2807,
   -2807,  -585, -2807, -2807, -2807, -2807, -2807, -2807,  -119, -2807,
   -2807,   183, -2807,   490, -2807, -2807, -2807, -2807, -2807, -2807,
   -1294, -2807, -2807, -2807, -2807, -1903, -2807, -2807, -2807, -2807,
   -2807, -2807, -2364,   526, -2807, -2475,   590, -2807, -2807, -2222,
     -28,   -27,   218, -2807, -2126, -1821, -2807, -2807,  -305,  -581,
   -2807, -2807, -2807, -2807, -1799, -2807, -2807, -2807, -1864, -2807,
   -2807, -1210, -2807, -1013,   907,  -355, -2004,   185, -2807,   441,
   -2807, -2807, -2807, -2807,    19, -2807, -1295, -2628,  2768, -2807,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807,  -722, -2807, -2158,
   -2807,  1556, -2807, -2807,   371,   206, -2807, -2064,   209,  -229,
      41, -2512, -1838, -2177,   835,  -295,  -928, -1248, -2807,   845,
   -2807, -2807, -2807,   938,  -769, -2807, -2807,  -520,  1579, -2807,
     683, -2807, -2807, -1781,  -214, -2807, -2807, -2807, -2142,  -407,
   -2807, -2807, -2807,   971, -2807, -2807, -2807, -2807, -2807, -2807,
   -2807, -2807, -2807, -2807, -2617,  -425, -2807, -2659, -2806, -1887,
   -1478, -2807, -2807,  -409,  -707,  -649,  -752,   503,   224,     8,
    2087,   -31, -2807, -2807, -2807, -2807, -2807,  1420, -2807,  -265,
   -2807, -2807, -2807, -2807, -2807, -2807, -2807, -2807,  -264,  1209,
    2264, -2807, -2807, -2807, -2807
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -2149
static const short yytable[] =
{
      43,   294,   581,   213,   354,   998,  1350,   262,    34,    58,
      60,  1935,  1936,    60,   115,   429,   430,  1413,  1315,  1459,
     282,  1467,   431,   432,  1441,  1365,  1153,   444,  2014,  1420,
    1421,  1362,  1422,    34,  1443,  1444,  1992,  1411,  2348,    72,
    1286,   685,    76,    79,  1147,   133,  2190,  1033,  2698,   986,
     131,  1375,  2545,  2799,  2596,  2802,   945,  2037,    88,   592,
    1082,  2610,    42,  1052,  2146,  2147,   115,   213,   949,   955,
    2784,  2281,  1107,    42,   130,    42,   129,    79,  1478,   592,
      88,   322,    42,    42,  1414,    42,   213,  2307,  2306,   139,
     300,  2729,   522,   379,   603,  2470,   146,  3046,  3047,  3048,
     151,   604,  2189,   153,   154,  1854,  2650,    99,  2229,   157,
     158,  1360,  1458,    42,   387,   388,   592,  1047,  1360,  2831,
      42,  1360,  1957,    42,  1380,  1381,  1849,  1057,   129,   592,
    1033,    88,   359,  2072,  2486,  2986,  1872,   300,   360,   361,
    1859,   142,  3050,   300,   355,   356,    42,  2520,   258,   531,
      42,   261,  2240,  2241,  2242,  2243,   265,  1188,  3070,    42,
    1460,  1461,  2661,  1111,   300,  1200,  1201,    42,   433,  1392,
     352,   300,   445,  1048,   447,    42,   448,   449,   450,   352,
    1850,    42,  1108,  1109,    42,   455,  1957,    99,  2493,   466,
     467,   226,  1146,   372,  1360,  2794,    42,  2796,   352,  2865,
    1210,  2073,  1360,  2074,    42,  2075,   300,  1262,  1263,    42,
     300,  1200,  1201,    42,  1075,   213,    42,   357,   352,   213,
    2727,  3155,  2072,  2805,  2806,   352,  2807,  2808,  2809,  2810,
    2811,  2812,   300,  1262,  1263,    42,   300,  2908,  1263,   352,
    1151,  3284,    42,  3038,  3038,  3038,  3038,  2755,  2756,  2757,
    2758,  2759,  2803,    84,   574,  1350,   384,  3236, -2147,  2803,
     352,   576,   390,  2697,   584,    42,  2803,   592,   592,  3138,
     578,  3140,   592,   418,  2603,  2606,  2490,  1349,  2606,   592,
     427,   427,   427,   427,   427,   590,   667,   600,   427,  3173,
    2193,    42,  1209,  2155,   143, -2147,    42,   380,  2528,  2119,
    1854,  2531,  1450,  1451,  3081,  2898,  3084,  2546,  2805,  2806,
    2665,  2807,  2808,  2809,  2810,  2811,  2812,   965,    42,  2348,
     661,  1402,   952,  1151,  2754,    42,   464,    67,  2255,  2743,
     611,  2950,  2651,   614,    42,    84,   669,    88,    88,   673,
    1947,  3354,  1357,  2619,  2800,  2093,  3515,   533,    73,  3097,
     622,   623,   624,   625,  1974,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,  1974,   184,  1979,    42,  1878,  1029,  1014,  1210,
      42,    84,   643,   644,    84,  1876,  1210,   646,  2938,   647,
    2079,   948,  1403,  1330,  1331,  2382,  1355,    42,  1514,  1490,
    3094,   592,   213,  1029,   650,   651,   652,   653,  2551,  2551,
      84,   659,   539,  2594,   541,  1097,  2594,  2607,  3342,    99,
      36,  1332,  1333,  1334,   303,  2623,    42,  1021,  2159,  3350,
    1021,  1021,  3152,    84,   966,   343,   344,   345,   346,   347,
    2625,  3248,  1956,  3249,  1021,  1356,   591,   997,  2674,  3095,
    1855,    65,   343,   344,   345,   346,   347,   213,  2583,    84,
    1855,  2733,  2892,  1021,    35,  2892,  1021,  2919,   587,  2496,
     136,  2813,  1021,    42,    81,  2972,  1021,  1018,  2919,    42,
    1021,  3355,  2129,  3009,  1021,   601,  1018,  2746,  1021,  1021,
    3058,  1021,  3072,    84,  1021,  1213,  1021,  1021,  1021,  2890,
    2899,  1210,  1099,  3144,  1021,   831,   924,  1021,  3038,  3038,
    2767,  2256,  3038,  3207,  1021,  2120,  3224,  3224,    65,  1021,
      88,  3232,  2257,  1142,  1143,  3323,  1021,  3360,  3516,   213,
    1202,  3223,  2022,  3360,  3418,  3325,  2620,  1021,  3418,  3452,
    3468,  1021,  3224,    84,   967,  1021,  2119,   677,    84,  2939,
     677,  1021,  1194,   579,  1021,  1197,  2813,  1997,   677,   136,
    3005,   961,  2194,  2666,  1415,  2252,  2497,   916,   926,  2362,
    1998,  1211,  2023,  2195,   418,  3353,   418,   671,  2835,  2866,
    1515,  3006,  3007,  1265,  1993,   947,  2744,   951,   427,  2603,
    2814,  2815,   587,  2010,  2196,  3156,  2020,   353,  1266,  1884,
    2951,  2197,  1098,  3176,  3092,  2559,   536,  2772,  1884,  1265,
    1871,  2230,  1212,  1265,  2046,  3347,  2987,  1212,  1416,  1462,
    1997,  3186,  3241,  1018,  1266,   996,  2060,    42,  1266,  2087,
    2487,  3011,  1203,  1998,  3237,   972,  1473, -2147,  1476,  3015,
    2737,    84, -2147,  2885,  2021,  1316,   575,    84,  2816,  1997,
    2896,    78,  2917,   577,  1399,  1887,   585,  3074,  1946,   593,
     596,  3001,  1998,  1382,   597,  1981,  3189,  2426,  3285,  1958,
     605,   607,  2041,  1937,  1213,  2814,  2815,   677,   668,  2894,
    3161,  1213,    88,    88,    88,    88,  1017,  3465,  1022,  1023,
    2047,   321,  1030,  1035,  2521,  1037,  1479,  2247,  1040,  2914,
      88,  2913,  1033,  2598,  2014,  3038,  1463,   425,  3250,  1023,
    2598,  3038,  3038,  2598,  3038,  3038,  3038,  3038,   425,  2753,
     950,  1465,  1919,  3038,  1930,  3326,  1393,   425,   670,  1023,
    1033,   674,  1417,  2816,  1358,    88,  3330,  1218,   321, -2147,
    3199,    88,  1023,    88,   321,  3014,  1975,    88,   305,  3438,
      88,  2076,  1085,    88,  3163,  2089,  2174,  2175,  3168,  2077,
      97,  1938,  2120,    88,  1976,   321,  1980,  3479,   427,  1101,
    2364,  1177,   321,   308,  2478,  1030,  2817,  1939,  1041,    42,
    1076,  1516,    88,  2760,   427,   427,  2113,  2383,  2000,    88,
      88,    88,  1335,  2384,  2426,  1171,  1213,  2640,    79,  2397,
    2552,  2558,   391,    88,  2001,  2595,  1999,   321,  2597,  2608,
    1189,   321,  1189,   427,  1517,  1189,   427,  2624,  1189,    88,
    1940,  3038,  3086,  2098,  3038,  3038,  3038,  3038,  3484,   392,
      35,    36,  2626,   321,  1918,  2013,  2203,   321,    42,   619,
    2675,  3322,  2818, -2147, -2147, -2147, -2147, -2147,  1021,  1252,
     132,  2000,  3410,  2734,  2893,  2234,   314,  2895, -2147,  2920,
    1941,  2817,  1302,  2183,  2184,  1302,  3304,  2001,  2933,   134,
    2924,  1019,  2191,   659,   659,  3010,  1214,  1215,  1216,  1336,
    2000,  1028,  3059,    42,  3073,  2155,  3134,  1217,  3137,  1942,
    2404,  3131,  2819,  2820, -2147,  3145,  2001,  1456,  1943,  2148,
    3230,  2149,  2150,  2151,  2124,  3208,  3038,  1058,  3225,  3231,
    1058,  2211,    45,  3233,  3038, -2147,  1028,  3324,    42,  3361,
    1067,  2781,  1337,  1238,  1058,  3362,  3419,  2818,  1058,   141,
    3425,  3453,  3469,  1985,  3499,  1084,  2547,  3439,   143,  2532,
    1058,  3440,  1067,  2377,    42,  2251,  2503,    84,  1095,   317,
    1457,  1067,  2887,  3253,  1018,  2504,  3258,    19,  1104,  3260,
    3266,   318,   319,  1110,  1279,  1021,  1021,  1021,  1985,   320,
    1145,  2341,  2235,  2273,  2342,   145,  2869,  2819,  2820,   933,
    2505,  1095,    19,  2506,  2370,  1095, -2147,  2997,    42,  1095,
    1447,  2611,  2612,   147,  3079,  1067,  3082,  1454,  1067,  3085,
    1054,  2507,  1325,   219,   677,  3203,    84,  2090,  2148,  3267,
    2149,  2150,  2151,   934,  2635,  3352,   984,   138,  2635,   987,
    2159,  -273,  2238,  1068,    42,  1030,  1495,  3327,  2238,  1286,
    1105,  1151,    42,    42,  2260,  2261,  2262,  2263,  3143,  2116,
    1361,  3147,    83,    88,    42,  1318,   343,   344,   345,   346,
     347,  1029,  2407, -2147,  3240,  2212,   220,    88,  2176,    83,
    1361,    42,   259,  1499,  2476,    42,  3087,  1140,     2,     3,
    3230,  3230,  1986,   223,  2213,  2214,  1154,  1160,  2343,   927,
    1175,  2344,  2236,  2034,  1179,   260,  1029,  3490,   267,  2835,
    1185,    46,  1187,  1865,  2215,    42,  2211,  2511,    88,  2042,
    2155,    42,   928,  2155,  1385,    47,  2508,  1986,  2974,  -273,
      42,  1386,    84, -1533,    88,    88,    88,  2025,    88,   278,
      88,    88,  2999,    42,    42,  -273,    88,    88,  1099,    42,
      48,  2061,  2389,  2222, -2147,  3363,  2152,  3214,   350,  2153,
      42,  2154, -2147,  3271,     5,     6,   682,     7,     8,  1987,
    2410,  3127,     9,    42,   931, -2147,    84,    42,   135,   136,
    2509,  2155,  1488,  1046,    88,   135,   136,  2510,  -273,    10,
      11,  2156,  2495,  3204,    88, -2147,   297,  1982,    49,  1506,
    1984,   275,  2945,  1062,  1987,   298,   299,    12,  1090,    42,
    2442,   300,   301,   302,    42,   276,  1071,  1096,    88,    88,
    1029,    84,  2284,  3328,  3088,  2418,  3089,    88,  -273,  3135,
   -2147,  1162,    84,  2157,  2103,  3272,    42,  2158,   283,  2106,
    2104,   358,  1176,    88,    88,   363,  1180,   279,   351,    84,
    1184,   190, -2147,    84,  2251,  2159,   303,  -273,  2159,   349,
    2212,  1192,  1988,   191,  1195,  2152,  -273,   376,  2153,  1921,
    2154,  2785,  1989,  2313,  2787,  1279,  1279,  2231,    13,  2213,
    2214,  1163,  3409,    84,  1279,  3261,  3415,   395,  1990,    84,
    2155,   192,   927,  1009,  1955,    59,   280,    42,    84,  2215,
    2156,  3273,  1961,  3274, -2147,   383,  3166,  1989, -2147,   284,
   -2147,    84,  1145,    42,  1240,   928,  2159,    84,  3275,  1164,
    2884,  1286,   285,  1990,  3455,  2713,  3276,   286,  2019,  2550,
    3277,    42,  2553,  2554,  2555,  2556,  2014,   434,   435,  3401,
    3402,    84,  2157,   523,  2264,   287,  2158,  1994,  2912,   288,
    3334,  2002,  2011,  2002,   289,  3278,  3334,  1372,  2388,  3343,
    3344,  3345,  3346,    88,  1030,   290,   959,  1030,   960,  2026,
    2029,   291,  3444,  1037, -2147,   396, -2147,   292, -2147, -2147,
   -2147, -2147,    84,   436,   193,  1233,  1234, -2147,   437,  3457,
     439,   397,  1492, -2147, -2147,  1030,    88,   293,    88,    88,
      88,  2128,   136, -2147, -2147,  1448,  1449,    88,    88,  1452,
    1453,    88,   427, -2147,   427,    88,  1165,   394,  2748,   135,
     136,  3461,  2475,  3463,  2902,  2159,  2904,  2905,    88,  1869,
    1110,  1145,     1,  1060,   398,  3444,   295,  3333,  2765,  3336,
    3337,  3338,  3339,  2155,   403,   446,  1140,  1069,  2488,  2206,
    2207,  1074,  3457,     2,     3,   337,  1154,  2324,  2285,  1193,
     338,  1481,  1196,  1088,   339,  1199,  3417,   187,   188,  3420,
    3421,  3422,  3423,    88,   399,   189,    42,  1227,  2354,  2355,
      16,   194,  1493,  2736,   196,   340,   304, -2147,  1228,   341,
   -2147, -2147,  1166,  1214,  1215,  3439,   197,   342,  2100,  3440,
     427,   427,  1028,   400,    42,   427,   404,    88,   373,  2110,
    2111,   374,   401,   190,   195,  2341,  2286,   377,  2342,  1468,
    1469,  1470,  1471,  2768,  1360,   191,    42,   378,  2287,     5,
       6,    88,     7,     8,  1167,   382,  1486,     9,    42,  2288,
    1932,  1229,  1933,  2662,   364,   365,   366, -2147,   385,   196,
   -2147,  3474,   412,   192,    10,    11,  1230,  2289,  1366,  1367,
    1368,   197,  3212,  3213,   456,  2630,  2251,  2290,  2251,  2017,
    2291,    42,    12,   413,  2226, -2147,  2227,   389,  2159,  2641,
     305,  2642,   419,  2292,  2921,   306,  3078,  3078,   307,  3078,
    2653,   422,  3078,  1286,   405,  2955,   423,   424,  2376,   198,
    2981,  1168,  2142,  2143,  3495,   308,    42,  2043,   451,  2043,
     406,  3470,  3471, -2147,   453,   199, -2147,  2194, -2147,  2952,
     309,   454,  2343,   310,   465,  2344,   311,  2996,  2195,   475,
    3151,  2293,   468,   469,   471,   312,   201,  3149, -2147,   472,
     203,   473,   474,  2789,    84,  1231,   193,  2155, -2147,  2196,
    1027,   524,   457,   407, -2147,   535,  2197, -2147,  2801,   537,
     542,  2294,  1922,  1045,   543,   204,   546, -2147,   458,  2825,
     547,  2295,   548,   549,   552,  1369,   313,   553,   564, -2147,
     202, -2147,   563,   567,  1937,  2048,  2049,  2050,   314,   572,
   -2147,  1063,  2296,   408, -2147,  2297,   582,  2298,   583,   315,
     586,  3272,  2067,   589,   594,   203,   595,  1080,  1081,   205,
     612,   459,   615,  1087,   599,   606,  1089,   616,   206,     1,
     617,   436,   409,  2960,   620,  2299,   437,   438,   439,   645,
     316,   410,  2968,  2969,  2300,   648,  2182,   654,  1049,  1049,
       2,     3,  2186,   194,   655,  2636,   660,   662,   663,   104,
    1923,   460,   664,   665,   105,   666,   672,   675,  2088,   683,
     932,   937,   939,    14,   940,   958,  1924,  3273,   941,  3274,
     946,   956,  1938, -2147,   205,   957,   195,   964,  1154,   969,
     461,   317,  2159,   206,  3275,   971,  2671,  2219,  1939,   462,
     992,   973,  3276,   318,   319,  2112,  3277,   974,  2418,   106,
     107,   320,   207,   208,   975,  2127,   994,   108,  2537,  1925,
     999,   196,   321,    15, -2147,  1002,     5,     6,     1,     7,
       8,  3278,  1001,   197,     9,  1003,  1021,  1006,  1005,  1286,
    1007,  1940,  2363,  1049,  1008,  2705,  1010,  1181,  1242,     2,
       3,    10,    11,  1204,   343,   344,   345,   346,   347,  1926,
    1243,  1244,  1245,  1246,  2270,  1247,  1248,  1249,  3078,    12,
    1250,   198,  1189,   427,   427,  1251,  1253,   207,   208,    88,
      88,  1941,  1255,  2265,    17,  1254,  1256,   199,  1927,  1257,
    2915,  1258,  1292,  1299,  1300,   200,  1301,  1928,  1304,  2178,
    1305,  2925,  1361,  1361,  1307,  1308,  2538,  2187,   201,  2187,
    1942,  1361,  2433,  2435,  1309,   489,   490,   491,  1317,  1943,
    1310,  1311,  2539,  1348,  3090,     5,     6,  1312,     7,     8,
    1313,  2445,  1321,     9,   492,    88,  1322,  1323,  1324,  1328,
    1021,  1347,  1354,   136,  1359,  1363,  2223,  1379,  1351,  1353,
      10,    11,   202,  1383,  1384,  1423,  1387,  1390,  1021,  1388,
    1391, -2147,  1395,  1396,  1398,  2540,  1407,  1412,    12,  1445,
    3179,  1455,  1458,  1474,  1030,  1491,  1279,   203,  1494,  1482,
    1483,  1484,  1279,  1279,  1361,  1485,  1489,  1503,  1279,  1279,
    1279,  1279,   493,   494,   495,   496,   497,   498,  1280,  1030,
    1495,  1505,   204,  2375,  1845,  2541,  1846,  1847,   499,   500,
     501,   592,  1361,  1848,  1853,  1857,  1861,  1860,   659,  3181,
    1862,  1863,  1909,  1917,  1920,  2002,  1931, -2147,  1948, -2147,
    1949,  1950,  1951,  1952,  2542,  1953,  2011,  1954,  1973,  2002,
    1978,  1996,  1350,  2543, -2147,  2016,   205,  2032,    88,  2033,
    2035,  2034, -2147,  1318,  2036,   206, -2147,  2038,  2320,  2321,
    2322,  2039,  3295,  2040,  2053,  2326,  2059, -2147,  1465,  2066,
    3303,   109,  2068,  2070,  2072,  2081,  2091,  1204,  2082,   580,
    2092, -2147,  2094,  2101,  3308,  2105,  2096,  2116,  1291,  2251,
    2107,  1293,  2351,  1294,  1295,  1296,  1297,  1298,   110,  2130,
    2358,  2359,  2123,   427,  2125,  2131,     2,     3,  2133,  1855,
    2166,  2168,  1424,  2169,  2171,    88,  2177,  2220,  2224,  2225,
    2228,  2230,    88,    51,    52,    53,    54,    55,    56,    57,
    2631,  2386,  2266,    88,  2252,  2244,  2276,  2278,  2279,   207,
     208,  2282,  2681,  2283,  2309,  2312,  2315,  2314,  2311,   502,
    2316,  2328,   503,  2330,    88,  2331,  2411,  1506,  2332,  1279,
    2333,  2337,  1030,    88,  2352,  2336,  2338,  2334,  2339,   111,
    1854,  3351,  2365,  2367,  2368,  2372,  2340,  3150,   427,   427,
    2374, -2147,     5,     6,  2380,     7,     8,  3157,  2381,  2870,
       9,  3262,   427,  2825,  2387,  2394,  2390,    88,    88,    88,
    2391,  2408,  2233,    88,  2400,  2871,  2872,    10,    11,  2414,
    2428,  1361,   213,  3395,  2873,  3099,  3100,  3101,  2473,  3103,
    3104,  3105,  3106,  3107,  3108,    12,  1217,  2426,  3111,    88,
    2474,  2485,  1204,  2499,  2517,  2500,  2516,  2527,  2527,  1425,
    2491,  2527,  2514,  2536,  2524,  1426,  1427,  1428,  2874,  2535,
    2548,  2549,  2561,  1021,  2577,  1279,  2582,  2875,  2584,  1021,
    2585,  2586,   112,  1279,  2629,  1429,  1279,  1279,  1279,  1279,
    2557,   504,  2633,  1361,  2590,  2649,  2593,  2562,  1279,  1021,
    2353,  2580,  2613,  2614,  2615,  2616,  2876,   505,  2617,  1280,
    1280,   506,  2618,  2638,  2667,  2669,    13,  2672,  1280,  2678,
    2679,  2682,  1279,  2687,  2599,  2599,  1286,  2683,  2599,  1279,
    2685,  2686, -2147,  2703,  2684,  3467,  2706,  2707,  2704,  2708,
    1216,  3400,  3445,  3446,  3447,  3448,  3449,  3450,  2712,   507,
    2719,  2877,  2721,  2730,  2731,  2627,  2732,  2739,  2026,   161,
      88,  2735,   113,  2740,  2747,  2749,  2770,  2775,  1372,  2002,
     114,  2786,  2783,  2002,    88,  2798,    88,   508,  2788,  2803,
    2790,  2791,  2599,  2335,  2804,    88,  2351,  2792,  2793,  2658,
    2658,  2826,  2829,  2878,  1430,   509,  2890,  1431,   162,  2889,
    2900,  2891,  2357,  2916,  1110,  1432,  2050,  2903,  2670,  2897,
    2419,  2906, -2092,  2922,  2923,  2926,  2928,   163,    91,    88,
    2929,  2936,  1145,  2940,  2947,  2956,  2959,  2944,   427,  2967,
    2977,  2991,  3003,  1962,  1963,  1964,  1965,  3297,  3002,  3011,
    1433,  3018,  1957,  3056,  3060, -2147,  2396,  3068,    88,  1946,
    3067,  3414,  3226,  3227,  3228,  3229,   164,  3091,  3069,  3080,
    3083,  3071,  1204,  3093,  3098,  3102,  3109,  3110,   165,  3116,
    3117,  3462,  3120,  3121,  2714,  1434,  3122,   510,  1986,   166,
    3123,  3124,  3125,  3126,  3141,  3132,  3429,  3139,  3146,  3148,
    3265,   185,   216,  3153,  3158,  1435,  1436,   167,  1915,  2992,
    3159,  2994, -2147,  3160,  3161,  3177,  1437,   168,  3175,  3184,
    1211,  1438,  1966,  1967,  1968,  1969,  1970,  1971,    16,  3180,
    3195,  3199,  1361,   169,  3205,  1021,  1021,  3192,  3224,  1049,
     924,  1966,  1967,  1968,  1969,  1970,  1971,  2599,  3215,  2979,
    3216,  3234,  3235,   511,  3519,  2751,  2187,  1279,  1873,  3217,
    1439,  3218,  3219,  3220,  3221,  3251,   216,  3269,  3245,  2887,
    2599,  3287,  1361,   170,  3288,  3292,    88,  2527,  3290,  3291,
    3296,  3293,  3300,  3302,  3307,   216,  3306,  3380,  3309,  3310,
    3311,  3313,  1440,  3315, -2147,   924,   171,  3319, -2147,  1958,
    3414,  3329,   926,  3331,  3348,  3340,  3364,  1279,  3374,  3375,
    3376,   172,  3378,  3406,  3381,  1361,  2958,  1361,   173,   659,
    1279,   174,  1279,  1964,  1965,  3399,  3377,  3394,   659,   659,
    3416,   213,  3437,  1279,  3393,  3426,  3451,  3488,  2599,    88,
    2580,  3473,   175,  3464,  3507,   176,  3475,   177,  3476,  2599,
    3477,  3478,  3505,  3509,  2599,  3510,  2632,   926,  2963,  2918,
    3508,  1874,  3518,  2002,  3487,  1314,   178,  1423,  2695,  1875,
    2115,  2643,  2644,  2050,  2647,  1876,  2399,  1877,    74,  2011,
     222,  2002,  2654,    75,   179,    88,   544,  2943,  1878,  2320,
    3228,  3229,  2668,   832,  2663,   540,    88,   227,   369,  2267,
    1966,  1967,  1968,  1969,  1970,  1971,  1000,   529,   530,   545,
    2268,   676,   371,  3247,   216,   963,  1879,  1934,   216,   936,
     571,  2351,   569,  2946,   942,  2948,  3485,  1110,   943,  2325,
    1170,  1306,  1880,  1145,   602,  1913,  2525,  1881,    88,  3170,
      88,  2964,    88,  2645,  2533,  2360,  3172,  2141,  2702,  1882,
    2990,  3194,  2145,  1145,  2711,    88,  1883,     1,  2425,  3506,
    2652,  2443,  1279,    88,    88,  2063,  3305,  1966,  1967,  1968,
    1969,  1970,  1971,    69,   159,   427,    70,   427,     2,     3,
    3282,    71,  1086,  2406,  2409,  1241,   534,    88,    88,  2165,
    2985,  1327,  3270,  1279,  2413,  1851,  3365,  2055,  3491,  3165,
    2086,  3130,  2983,  2045,  3373,  2599,   621,     4,  1477,  3129,
    2097,  3036,  3036,  3036,  3036,  2599,  2599,  3112,  2882,  2031,
    2639,  2277,  2310,  3494,  1424,  2741,    88,  3264,  2769,  3427,
    3133,  3062,  2609,  2560,  2494,  3075,  2883,  3076,  3259,  3428,
    2181,  3286,  2797,  2886,  2762,    64,  2763,  3514,  1901,  2836,
    3211,  3017,  2246,  2837,     5,     6,  3263,     7,     8,  1279,
    1279,  2245,     9,  3408,  3210,   213,  2173,  1868,  3332,  3349,
    1279,  1279,  2139,  1279,  3341,  2628,  1279,  2062,  1279,    10,
      11,   684,  1279,     0,     0,     0,     0,     0,     0,     0,
     649,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,   216,     0,     0,     0,   659,     0,     0,     0,     0,
       0,  1884,     0,     0,  1204,     0,     0,     0,  1885,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    88,     0,     0,     0,     0,     0,
    1886,     0,     0,  3294,     0,  1887,  2599,  3136,  2599,     0,
       0,  1425,     0,     0,     0,     0,   216,  1426,  1427,  1428,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,    88,     0,     0,  2002,     0,  1429,     0,  1110,
    1110,     0,    88,     0,     0,     0,  2927,     0,     0,  2932,
       0,     0,  2658,     0,     0,  3167,  2658,     0,     0,     0,
     427,     0,     0,     0,     0,     0,     0,   427,     0,    88,
    1280,     0,     0,     0,     0,     0,  1280,  1280,    88,     0,
       0,     0,  1280,  1280,  1280,  1280,     0,     0,   216,     0,
       0,     0,  1021,     0,     0,     0,     0,     0,     0,  3045,
    3045,  3045,  3045,     0,     0,  1140,     0,     0,     0,     0,
       0,     0,  1011,  1012,  1013,  1015,     0,     0,     0,  3196,
       0,     0,     0,     0,     0,  2599,     0,     0,     0,     0,
    1043,     0,     0,     0,  2751,     0,  3036,  3036,  2083,     0,
    3036,     0,     0,     0,     0,     0,  1430,     0,    14,  1431,
       0,  3222,     0,     0,     0,     0,     0,  1432,     0,     0,
       0,     0,     0,     0,     0,  1065,     0,     0,     0,     0,
       0,  1070,     0,  1072,  2599,     0,  2178,  1079,     0,     0,
    1079,  2909,     0,  1079,     0,     0,     0,     0,  1361,     0,
       0,     0,  1433,  1091,     0,     0,  1030,     0,    15,  1030,
       0,     0,  1279,     0,     0,  1279,     0,  1279,     0,  2599,
       0,     0,  1138,     0,     0,     0,     0,     0,     0,  1015,
    1149,  1152,     0,     0,  3405,  1172,     0,  1434,     0,     0,
      16,     0,    88,  1182,     0,     0,  2201,  2202,     0,     0,
       0,     0,     0,  2218,     0,     0,     0,  1435,  1436,  1206,
       0,     0,     0,  1280,     0,     0,     0,     0,  1437,    17,
       0,     0,     0,  1438,     0,     0,     0,     0,     0,   427,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1439,     0,     0,     0,   213,     0,     0,     0,
       0,     0,     0,     0,     0,    88,  3037,  3037,  3037,  3037,
    1279,     0,     0,  2599,     0,     0,     0,     0,     0,     0,
       0,  1030,     0,  3036,  1440,     0,     0,     0,     0,  3036,
    3036,     0,  3036,  3036,  3036,  3036,     0,  3171,  2599,  1280,
    2599,  3036,     0,  1279,     0,    88,     0,  1280,     0,     0,
    1280,  1280,  1280,  1280,  3045,  3045,     0,     0,  3045,     0,
       0,     0,  1280,     0,     0,     0,     0,  3187,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
      88,     0,    88,     0,     0,     0,  1280,   659,     0,     0,
       0,     0,     0,  1280,     0,     0,     0,     0,     0,     0,
       0,     0,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3257,     0,     0,  3257,  2379,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3196,
       0,     0,     0,     0,     0,  1279,     0,     0,     0,  3036,
       0,     0,  3036,  3036,  3036,  3036,  3424,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2423,
    2178,     0,     0,  1206,     0,     0,  1030,     0,     0,     0,
    1279,     0,     0,     0,     0,     0,     0,  1373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    88,
      88,    88,    88,    88,     0,     0,     0,     0,     0,     0,
    3456,     0,     0,     0,     0,     0,  2839,  2840,     0,  2841,
    2842,  2843,     0,     0,     0,     0,     0,     0,  1401,     0,
       0,     0,     0,     0,  3036,     0,  1145,     0,     0,     0,
       0,     0,  3036,     0,  1419,  1419,  1419,     0,  1419,     0,
    1419,  1419,     0,     0,     0,     0,    91,    91,  3298,  2233,
       0,  3045,     0,     0,     0,     0,     0,  3045,  3045,     0,
    3045,  3045,  3045,  3045,     0,     0,     0,     0,     0,  3045,
       0,  3037,  3037,     0,  1279,  3037,  3496,     0,     0,     0,
    3320,     0,     0,     0,  1152,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1501,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2844,
       0,  1280,     0,  3512,  3513,  3496,     0,  2845,  1206,  1373,
       0,     0,    88,     0,  3520,     0,     0,  1858,     0,     0,
       0,  3256,     0,     0,  3256,     0,     0,     0,     0,     0,
       0,     0,     0,  1866,  1866,     0,     0,     0,     0,     0,
       0,  2846,     0,     0,     0,     0,     0,     0,     0,     0,
    2847,  1280,     0,     0,     0,     0,     0,  3045,     0,     0,
    3045,  3045,  3045,  3045,  1280,     0,  1280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1280,     0,  2848,
    2849,     0,     0,     0,  3257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2691,  2692,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2701,     0,     0,     0,     0,     0,     0,     0,
    1280,   476,   477,   478,  2850,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,  2715,  2716,
    2717,  2718,  3045,     0,     0,     0,  2723,  2724,  2725,  2726,
    3045,     0,     0,  2728,   492,     0,     0,     0,  3037,     0,
       0,     0,     0,     0,  3037,  3037,  2851,  3037,  3037,  3037,
    3037,     0,     0,  3454,     0,     0,  3037,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,    91,  1152,
    1079,     0,  3358,     0,     0,     0,     0,  2054,  1091,     0,
       0,  1152,     0,     0,     0,  2064,  1280,     0,     0,     0,
       0,     0,   493,   494,   495,   496,   497,   498,  1206,     0,
       0,     0,     0,  2852,     0,     0,     0,     0,   499,   500,
     501,  2773,  2774,     0,     0,     0,     0,  1280,  2778,  2779,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1280,  1280,  1280,  1280,     0,
       0,     0,     0,    91,     0,     0,     0,     0,  3503,     0,
       0,     0,     0,     0,  3037,     0,     0,  3037,  3037,  3037,
    3037,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2108,     0,     0,
       0,  3256,     0,  1280,  1280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1280,  1280,     0,  1280,     0,     0,
    1280,  2135,  1280,     0,     0,     0,  1280,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1049,  1049,  1049,     0,  1049,  1049,  1049,  1049,  1049,
    1049,     0,     0,     0,  1049,     0,     0,     0,     0,  3037,
       0,     0,     0,     0,  2934,  2935,     0,  3037,     0,   502,
       0,     0,   503,  2942,     0,     0,     0,   297,     0,     0,
       0,     0,     0,     0,     0,     0,   298,   299,     0,     0,
       0,     0,   300,   301,   302,    42,     0,     0,     0,     0,
       0,     0,  2970,  2971,     0,     0,   609,   476,   477,   478,
       0,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,     0,  2993,
       0,  2995,   190,     0,     0,     0,     0,   303,     0,     0,
     492,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,  2853,  2854,  2855,  2856,  2857,  2858,  2859,  2860,  2861,
    2862,     0,  1204,     0,     0,     0,  2564,     0,     0,     0,
       0,     0,   192,     0,     0,  1259,  1260,  1261,     0,     0,
       0,   300,  1262,  1263,    42,  3063,  3064,     0,     0,  3065,
    3066,   504,     0,     0,     0,     0,     0,     0,   493,   494,
     495,   496,   497,   498,     0,     0,     0,   505,     0,     0,
       0,   506,   598,     0,   499,   500,   501,     0,     0,     0,
    1280,  1280,     0,     0,  1280,     0,  1264,     0,     0,     0,
    2677,   476,   477,   478,     0,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,   507,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    84,   492,   193,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,  3119,     0,
    1280,     0,     0,  1280,     0,     0,  1280,     0,     0,  1280,
       0,  1280,     0,     0,     0,   509,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   493,   494,   495,   496,   497,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,   500,
     501,     0,     0,     0,     0,     0,  3164,     0,     0,     0,
    3169,     0,  1029,     0,     0,   502,     0,     0,   503,  2164,
    1206,     0,   194,  3174,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,  3185,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   195,     0,     0,     0,     0,
       0,     0,     0,     0,  1280,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2205,     0,  1280,     0,     0,
       0,     0,     0,  1280,  1280,     0,  1280,  1280,  1280,  1280,
     196,     0,     0,     0,     0,  1280,     0,  1280,     0,     0,
       0,     0,   197,   511,     0,     0,     0,     0,     0,     0,
       0,  1280,     0,     0,     0,     0,  2565,     0,     0,     0,
       0,   305,     0,     0,     0,     0,   306,     0,     0,   307,
       0,     0,     0,     0,     0,     0,     0,   504,     0,   502,
     198,     0,   503,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,   505,     0,     0,   199,   506,     0,     0,
       0,   309,     0,     0,   310,     0,     0,   311,     0,     0,
       0,     0,     0,  1204,     0,     0,   312,   201,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1152,  1280,
       0,     0,   297,  1280,     0,   507,  1280,  1280,  1280,  1280,
       0,   298,   299,     0,     0,     0,     0,   300,   301,   302,
      42,     0,     0,     0,     0,     0,     0,   313,  1265,     0,
    1280,   202,     0,   508,  1280,     0,     0,     0,     0,   314,
       0,     0,     0,  1266,     0,     0,     0,     0,     0,     0,
     315,   509,  2646,     0,     0,     0,   203,   190,     0,     0,
    1267,     0,   303,  2566,     0,  2371,     0,  3318,     0,   191,
    3321,   504,  2378,     0,     0,  2567,  1269,     0,     0,     0,
       0,   316,     0,  1152,     0,     0,     0,   505,  1280,     0,
       0,   506,     0,     0,     0,     0,  1280,   192,     0,     0,
       0,     0,     0,  1946,   185,     0,     0,     0,     0,     0,
       0,     0,     0,  2420,     0,     0,  1270,     0,     0,     0,
       0,     0,     0,     0,     0,   205,     0,     0,  1271,   507,
       0,     0,   317,   510,   206,     0,     0,     0,  1280,     0,
       0,     0,     0,     0,   318,   319,     0,  1152,  2477,  1152,
       0,     0,   320,  1015,     0,     0,     0,   508,     0,     0,
       0,     0,     0,   321,     0,     0,     0,     0,     0,     0,
    1272,     0,     0,     0,     0,   509,     0,     0,     0,  2519,
       0,     0,     0,     0,     0,     0,  1204,     0,    84,     0,
     193,     0,     0,     0,     0,     0,  3403,     0,     0,   511,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1273,
       0,     0,     0,     0,   297,     0,     0,     0,   207,   208,
       0,  1274,     0,   298,   299,     0,     0,     0,     0,   300,
     301,   302,    42,  1275,  1276,     0,     0,     0,     0,     0,
       0,  1277,     0,     0,  1278,  3430,  3431,     0,  3433,     0,
    3435,  3436,   321,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   190,
       0,     0,     0,     0,   303,     0,     0,     0,     0,     0,
       0,   191,     0,     0,     0,     0,     0,   194,     0,     0,
    1152,   216,   304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1152,     0,  1152,     0,     0,   192,
       0,  3480,     0,  3481,     0,  1152,     0,     0,     0,     0,
     195,     0,     0,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3493,     0,     0,     0,  2676,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,  3500,  3501,     0,     0,  3502,     0,   197,  3504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2700,     0,
       0,     0,     0,     0,     0,     0,   305,     0,     0,     0,
       0,   306,     0,     0,   307,     0,     0,     0,     0,     0,
      84,     0,   193,     0,     0,   198,     0,     0,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   199,     0,     0,     0,     0,   309,     0,     0,   310,
       0,     0,   311,     0,     0,     0,     0,     0,     0,     0,
       0,   312,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   476,   477,   478,     0,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,  2980,   313,     0,     0,     0,   202,   492,     0,     0,
       0,     0,  2564,     0,   314,   492,  2771,     0,     0,   194,
       0,  1259,  1260,  1261,   304,   315,     0,   300,  1262,  1263,
      42,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   195,     0,     0,     0,   316,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,     0,  1264,   493,   494,   495,   496,   497,   498,  1152,
       0,   499,   500,   501,     0,     0,     0,   196,     0,   499,
     500,   501,     0,     0,     0,     0,     0,     0,     0,   197,
     205,     0,     0,     0,     0,     0,     0,   317,     0,   206,
       0,     0,     0,     0,     0,     0,     0,     0,   305,   318,
     319,     0,     0,   306,     0,  1152,   307,   320,     0,     0,
       0,     0,     0,     0,     0,     0,  1152,   198,   321,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,   309,     0,
       0,   310,     0,     0,   311,     0,     0,     0,     0,     0,
       0,     0,     0,   312,   201,     0,     0,     0,  2961,     0,
    1043,     0,  2965,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   207,   208,  2976,     0,     0,  1029,     0,
     216,     0,     0,  2984,  2420,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,     0,     0,   202,     0,
       0,   228,   502,   229,     0,   503,   314,  2998,  3000,     0,
     502,     0,     0,   503,     0,     0,     0,   315,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3061,     0,   316,     0,
       0,     0,     0,   230,   231,     0,     0,     0,     0,     0,
       0,     0,     0,   232,     0,   476,   477,   478,     0,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,  2565,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,     0,   492,   317,
       0,   206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   318,   319,     0,     0,     0,     0,     0,     0,   320,
    1113,     0,     0,     0,   504,     0,     0,     0,     0,  1114,
     321,     0,   504,     0,     0,     0,     0,     0,  1115,     0,
     505,  3113,     0,  1116,   506,   608,     0,     0,   505,     0,
       0,     0,   506,     0,  3128,     0,   493,   494,   495,   496,
     497,   498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   499,   500,   501,     0,     0,     0,     0,     0,
       0,     0,   507,     0,  1265,   207,   208,  1117,     0,     0,
     507,     0,  1152,     0,     0,  1118,     0,     0,     0,  1266,
       0,     0,  1152,     0,     0,     0,     0,     0,     0,     0,
     508,     0,     0,     0,   216,     0,  1267,     0,   508,  2566,
       0,     0,     0,     0,     0,     0,     0,     0,   509,  2420,
       0,  2567,  1269,     0,   233,     0,   509,     0,  1206,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1270,   234,     0,     0,  1120,     0,     0,     0,
       0,     0,     0,  1121,  1271,  1122,     0,     0,     0,     0,
       0,     0,   235,     0,     0,  1123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
     510,     0,     0,   502,     0,     0,   503,     0,   510,     0,
       0,  1124,     0,     0,     0,     0,  1272,     0,     0,  1125,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   238,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1273,     0,  1126,     0,     0,
       0,     0,   240,     0,     0,     0,   511,  1274,     0,     0,
       0,     0,   241,     0,   511,     0,     0,     0,     0,  1275,
    1276,     0,  3113,  1127,     0,     0,     0,  1277,   242,     0,
    1278,     0,     0,     0,     0,     0,     0,     0,   321,  1518,
    1519,  1520,  1521,  1522,  1523,     0,  1524,  1525,  1526,     0,
       0,     0,  1527,  1528,  1529,  1530,  1531,  1532,     0,     0,
       0,  1128,  1152,     0,     0,   504,     0,  1533,   243,     0,
       0,     0,  1129,     0,     0,     0,     0,     0,     0,     0,
       0,   505,     0,  1534,     0,   506,   618,     0,     0,     0,
       0,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1535,     0,     0,     0,  2420,   245,     0,     0,     0,
    1536,     0,     0,   246,     0,     0,   247,     0,     0,     0,
       0,     0,     0,   507,     0,     0,     0,     0,  1537,     0,
    1538,     0,     0,     0,     0,     0,     0,   248,  1539,     0,
     249,     0,   250,  1540,  1541,  2420,     0,  1542,  1543,  1544,
    1545,   508,     0,  1546,  1547,     0,     0,     0,     0,     0,
       0,   251,     0,     0,     0,     0,     0,     0,     0,   509,
       0,  1130,  1131,  1132,     0,  3113,     0,     0,     0,   252,
    3368,     0,  3370,     0,  1133,     0,     0,     0,     0,     0,
       0,     0,     0,  1548,     0,     0,     0,     0,     0,     0,
       0,     0,  1152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1549,     0,     0,  1206,
       0,   253,  1550,     0,     0,   216,     0,     0,  2138,  1551,
       0,  1552,     0,     0,     0,     0,     0,  1553,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   510,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1134,  1419,  1419,
    1419,  1419,  1419,  1419,     0,     0,     0,     0,     0,     0,
    1555,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1556,     0,     0,     0,   511,     0,  1557,
       0,     0,     0,     0,     0,     0,     0,     0,  1558,  1559,
       0,     0,     0,     0,     0,  1560,     0,     0,  1561,  1562,
       0,     0,     0,  1563,     0,     0,     0,     0,     0,  1564,
    1565,     0,     0,     0,     0,     0,  1566,  1567,  1568,  1569,
    1570,  1571,     0,     0,     0,  1572,     0,     0,     0,  1573,
       0,  1574,     0,     0,     0,     0,     0,     0,  1575,  1576,
    1577,  1578,     0,  1579,  1580,     0,     0,     0,  1581,  1582,
       0,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,     0,
       0,     0,     0,     0,  1591,  1592,  1593,     0,  1594,  1595,
       0,     0,     0,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1603,  1604,  1206,  1605,     0,     0,     0,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,     0,  1644,  1645,     0,     0,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
       0,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,     0,     0,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,     0,  1680,  1681,
    1682,  1683,     0,  1684,  1685,  1686,  1687,  1688,  1689,  1690,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,     0,
    1720,  1721,  1722,  1723,  1724,  1725,     0,     0,  1726,  1727,
       0,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,     0,     0,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816,     0,     0,     0,     0,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1828,     0,     0,
       0,     0,     0,     0,     0,  1829,     0,     0,     0,     0,
    1830,     0,     0,     0,  1831,     0,     0,  1832,  1833,  1834,
    1835,     0,     0,  1836,  1837,     0,  1838,  1839,  1840,  1518,
    1519,  1520,  1521,  1522,  1523,     0,  1524,  1525,  1526,   161,
       0,     0,  1527,  1528,  1529,  1530,  1531,  1532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1533,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1534,     0,     0,     0,     0,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1535,     0,     0,     0,     0,     0,   163,     0,     0,
    1536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1537,     0,
    1538,     0,     0,     0,     0,     0,     0,     0,  1539,     0,
       0,     0,     0,  1540,  1541,     0,   164,  1542,  1543,  1544,
    1545,     0,     0,  1546,  1547,     0,     0,     0,   165,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,     0,     0,
       0,     0,     0,  1548,     0,     0,     0,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,     0,     0,  1549,     0,     0,     0,
       0,     0,  1550,     0,     0,     0,     0,     0,     0,  1551,
       0,  1552,     0,     0,     0,     0,     0,  1553,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,  1554,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,   173,     0,
    1555,   174,     0,  1259,  1260,  1261,     0,     0,     0,   300,
    1262,  1263,    42,  1556,     0,     0,     0,     0,     0,  1557,
       0,     0,   175,     0,     0,   176,     0,   177,  1558,  1559,
       0,     0,     0,     0,     0,  1560,     0,     0,  1561,  1562,
       0,     0,     0,  1563,     0,     0,   178,     0,     0,  1564,
    1565,     0,     0,     0,  1264,     0,  1566,  1567,  1568,  1569,
    1570,  1571,     0,     0,   179,  1572,     0,     0,     0,  1573,
       0,  1574,     0,     0,     0,     0,     0,     0,  1575,  1576,
    1577,  1578,     0,  1579,  1580,     0,     0,     0,  1581,  1582,
       0,  1583,  1584,  1585,  1586,  1587,  1588,  1589,  1590,     0,
       0,     0,     0,     0,  1591,  1592,  1593,     0,  1594,  1595,
       0,     0,     0,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1603,  1604,     0,  1605,     0,     0,     0,  1606,  1607,  1608,
    1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,  1618,
    1619,  1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1633,  1634,  1635,  1636,  1637,  1638,
    1639,  1640,  1641,  1642,  1643,     0,  1644,  1645,     0,     0,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1655,
    1029,  1656,  1657,  1658,  1659,  1660,  1661,  1662,  1663,  1664,
    1665,  1666,  1667,  1668,  1669,  1670,     0,     0,  1671,  1672,
    1673,  1674,  1675,  1676,  1677,  1678,  1679,     0,  1680,  1681,
    1682,  1683,     0,  1684,  1685,  1686,  1687,  1688,  1689,  1690,
    1691,  1692,  1693,  1694,  1695,  1696,  1697,  1698,  1699,  1700,
    1701,  1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,     0,
    1720,  1721,  1722,  1723,  1724,  1725,     0,     0,  1726,  1727,
       0,  1728,  1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,
    1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,  1746,
    1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,     0,     0,
    1755,  1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,
    1765,  1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,
    1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,
    1785,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,
    1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,
    1805,  1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,
    1815,  1816, -2148,     0,     0,     0,  1817,  1818,  1819,  1820,
    1821,  1822,  1823,  1824,  1825,  1826,  1827, -2148,     0, -2148,
   -2148, -2148,     0,     0,     0,     0,     0,  1828,     0,     0,
       0,     0,     0,     0,     0,  1829,  1265,     0,     0,     0,
    1830,     0,     0,     0,  1831,     0, -2148,  1832,  1833,  1834,
    1835,  1266,     0,  1836,  1837,     0,  1838,  1839,  1840,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1267,     0,
       0,  1268,     0,     0,     0, -2148,     0,     0,     0,     0,
       0,     0,     0,     0,  1269,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1946,     0,     0,     0,     0,     0, -2148,     0,     0,
       0,     0,     0,     0,  1270,  1259,  1260,  1261,     0,     0,
       0,   300,  1262,  1263,    42,     0,  1271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -2148,     0,     0,
   -2148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -2148,  1264,     0,  1272,     0,
       0,     0,     0, -2148,     0, -2148,     0,     0,     0,     0,
       0,     0,     0,     0, -2148,     0,     0,     0,     0,     0,
   -2148,     0,     0,     0,     0,     0,     0,     0, -2148,     0,
       0,     0, -2148,     0,     0,     0,     0,  1273, -2148,     0,
       0,     0, -2148, -2148, -2148, -2148,     0,     0,     0,  1274,
       0,     0,     0,     0,     0,     0,     0, -2148,     0,     0,
       0,  1275,  1276,     0,     0,     0,     0,     0,     0,  1277,
       0,     0,  1278,     0, -2148,     0,     0, -2148,     0, -2148,
     321,     0,     0,     0,     0,     0, -2148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2148,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -2148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,  1029,     0,   686,   687,   688,     0, -2148, -2148,
       0,     0,   689,     0,     0,     0,     0,     0,     0,   690,
       2,     3,     0, -2148,     0,     0,     0,     0,   691,     0,
       0, -2148,     0,     0,     0, -2148,     0,     0,     0,     0,
     692,   693,     0,   694, -2148, -2148, -2148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   695,     0,     0,
       0,     0,     0,     0,   696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   697,   698,   699,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   700,     0,   701,   702,   703,     5,     6,   704,     7,
       8,   705,     0,   706,     9,   707,   708,     0,     0,     0,
       0,     0,   709,     0, -2148,   710,     0,   711,   712,   713,
       0,    10,    11,     0,     0, -2148,     0,   714,     0,   715,
     716,     0,   717,     0,   718,   719,     0,     0,   720,    12,
       0,     0,   721,   722,   723,     0,   724,   725,     0,     0,
       0,   726,   727,   728,     0,   729,     0,     0,     0,   730,
       0,   731,   732,     0,     0, -2148,     0,   733,     0,     0,
       0,   734,     0,     0,   735,     0,   736,     0,   737,     0,
     738,     0,   739,   740,     0,   741,   742,   743,     0,     0,
       0,   744,     0,   745,   746,     0,   747,     0,     0,     0,
       0,     0,     0,     0,   748,   749,     0,     0,  1265,     0,
       0,     0,     0,     0,     0,     0,     0,   750,     0,     0,
     751,   752,     0,  1266,   753,   754,     0, -2148,   755,   756,
       0,     0,     0,     0,     0,     0,     0,   757,   758,   759,
    1267,   760,     0,  1268,     0,     0,     0,     0,     0,     0,
       0,   761,   762,   763,     0,   764,  1269,     0,     0,   765,
     766,     0,     0, -2148,   767,     0,     0,     0,     0,     0,
       0,     0,   768,     0,     0,     0,     0,     0,     0,     0,
     769,   770,   771,     0,     0,     0,     0,     0,   772,   773,
       0,     0,     0,     0,   774,  2415,  1270,   775,     0,     0,
       0,   776,   777,     0,     0,     0,     0,     0,  1271, -2148,
       0,     0,   778,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -2148, -2148, -2148, -2148, -2148, -2148, -2148,
     779, -2148, -2148,     0,     0,     0,     0,     0,   780,     0,
       0,     0,     0,     0,   781,     0,     0,     0, -2148,     0,
    1272,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,     0,   782,     0,   783,   784,     0,
       0,     0,     0,     0,     0,     0,   785,     0,     0,  1273,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1275,  1276,     0,     0,     0,     0,     0,
       0,  1277,     0,     0,  1278,   786,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,   787,     0,     0,     0,
       0,     0,     0,   788,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   789,   790,     0,
       0,     0,   791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   792,     0,     0,     0,     0,     0,
     793,   794,   795,   796,     0,     0,     0,   797,     0,     0,
       0,   798,     0,     0,     0,     0,     0,     0,   799,   800,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     801,     0,   802,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   803,     0,   804,     0,     0,   805,     0,
       0,     0,     0,     0,   806,     0,     0,     0,     0,     0,
     476,   477,   478,     0,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
     807,     0,     0,   808,     0,     0,     0,     0,   809,     0,
       0,   810,   811,   492,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   812,     0,     0,     0,
     476,   477,   478,   813,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   814,   815,   816,   817,
     818,   819,   820,   492,     0,   821,     0,   822,     0,   823,
       0,   493,   494,   495,   496,   497,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,     0,     0,   476,   477,   478,     0,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   493,   494,   495,   496,   497,   498,   492,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,   476,   477,   478,     0,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   493,   494,   495,   496,   497,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   499,   500,   501,     0,   476,   477,   478,     0,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,     0,     0,     0,     0,     0,     0,   502,     0,
       0,   503,   493,   494,   495,   496,   497,   498,   492,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   499,   500,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,     0,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   493,   494,   495,   496,
     497,   498,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   499,   500,   501,     0,     0,     0,     0,   476,
     477,   478,     0,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,     0,     0,     0,     0,
       0,     0,   502,     0,     0,   503,     0,     0,     0,     0,
     504,     0,   492,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   505,     0,     0,     0,
     506,   970,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   502,
       0,     0,   503,     0,     0,     0,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,     0,     0,   507,     0,
     493,   494,   495,   496,   497,   498,   505,     0,     0,     0,
     506,   976,     0,     0,     0,     0,   499,   500,   501,     0,
       0,     0,     0,     0,     0,     0,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   502,   509,     0,   503,     0,   507,     0,
       0,     0,     0,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     505,     0,     0,     0,   506,   977,   508,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   509,     0,     0,     0,     0,     0,
       0,   504,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   507,     0,     0,     0,     0,   505,     0,     0,
       0,   506,   978,   476,   477,   478,   510,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     508,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   492,   502,   509,   507,
     503,     0,     0,     0,     0,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   510,     0,     0,     0,
       0,   505,     0,     0,     0,   506,   979,   508,     0,     0,
       0,     0,   511,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   509,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   494,   495,   496,   497,   498,
       0,     0,     0,   507,     0,     0,     0,     0,     0,     0,
     499,   500,   501,     0,     0,     0,     0,     0,     0,     0,
     510,     0,   511,     0,     0,     0,     0,     0,   476,   477,
     478,   508,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,     0,     0,     0,     0,   509,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   504,
       0,   492,     0,     0,     0,     0,     0,   510,     0,     0,
       0,     0,     0,     0,     0,   505,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,   511,     0,     0,     0,
       0,     0,   476,   477,   478,     0,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,     0,
       0,     0,     0,     0,     0,     0,     0,   507,     0,   493,
     494,   495,   496,   497,   498,   492,     0,     0,     0,     0,
     981,   510,     0,   511,     0,   499,   500,   501,     0,     0,
       0,     0,     0,     0,     0,   508,     0,     0,     0,     0,
       0,   502,     0,     0,   503,     0,     0,     0,     0,     0,
       0,   477,   478,   509,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,     0,     0,
       0,     0,     0,   493,   494,   495,   496,   497,   498,     0,
       0,     0,     0,   492,     0,     0,     0,   511,     0,   499,
     500,   501,     0,     0,     0,     0,     0,     0,     0,   478,
       0,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     492,     0,     0,     0,     0,   510,     0,     0,     0,     0,
       0,   493,   494,   495,   496,   497,   498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,   500,   501,
       0,     0,     0,   504,     0,     0,   502,     0,     0,   503,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   505,
       0,     0,     0,   506,     0,     0,     0,     0,   493,   494,
     495,   496,   497,   498,     0,     0,     0,     0,     0,     0,
       0,   511,     0,     0,   499,   500,   501,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,     0,     0,     0,
     502,     0,     0,   503,   982,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,     0,   508,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   492,     0,     0,   509,     0,     0,
       0,     0,     0,     0,     0,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,     0,   504,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   502,     0,
       0,   503,     0,   492,   505,     0,     0,     0,   506,     0,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,     0,   493,   494,   495,   496,   497,   498,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,   499,   500,
     501,     0,     0,     0,     0,   502,   507,     0,   503,   510,
       0,     0,   504,     0,     0,     0,     0,     0,     0,   985,
       0,   493,   494,   495,   496,   497,   498,     0,   505,     0,
       0,     0,   506,     0,   508,     0,     0,   499,   500,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   509,     0,     0,   493,   494,   495,   496,   497,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     507,   499,   500,   501,     0,   511,     0,     0,     0,     0,
     504,     0,     0,     0,     0,     0,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   505,     0,   508,     0,
     506,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,   509,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   504,     0,     0,
       0,     0,     0,     0,   510,     0,     0,     0,   507,   502,
       0,     0,   503,   505,     0,     0,     0,   506,     0,     0,
       0,     0,     0,     0,   483,   484,   485,   486,   487,   488,
     489,   490,   491,     0,     0,     0,   508,     0,     0,     0,
     493,   494,   495,   496,   497,   498,     0,     0,   502,   492,
       0,   503,     0,     0,   509,   507,   499,   500,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   510,     0,
     511,     0,     0,     0,   485,   486,   487,   488,   489,   490,
     491,     0,   502,   508,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   492,     0,     0,
       0,   509,     0,     0,     0,     0,     0,   493,   494,   495,
     496,   497,   498,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   499,   500,   501,     0,     0,     0,     0,
       0,   504,     0,     0,   511,     0,   510,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   505,     0,     0,
       0,   506,     0,     0,     0,   493,   494,   495,   496,   497,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     504,   499,   500,   501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   510,     0,     0,   505,     0,     0,   507,
     506,     0,     0,     0,     0,     0,     0,   502,     0,     0,
     503,     0,   511,     0,   504,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,     0,     0,
     505,     0,     0,     0,   506,     0,     0,     0,   507,     0,
       0,     0,     0,     0,     0,   509,     0,     0,     0,     0,
       0,   980,     0,     0,     0,     0,     0,     0,     0,   511,
       0,     0,  1259,  1260,  1261,     0,   508,     0,   300,  1262,
    1263,    42,   507,     0,   502,     0,     0,   503,   487,   488,
     489,   490,   491,     0,   509,     0,     0,   486,   487,   488,
     489,   490,   491,     0,     0,     0,     0,     0,     0,   492,
     508,     0,     0,     0,     0,     0,     0,     0,     0,   492,
       0,     0,     0,  1264,     0,     0,     0,     0,   509,     0,
       0,     0,   502,     0,     0,   503,     0,   510,     0,   504,
       0,  1259,  1260,  1261,     0,     0,     0,   300,  1262,  1263,
      42,     0,     0,     0,     0,   505,     0,     0,     0,   506,
       0,     0,     0,     0,     0,     0,     0,   493,   494,   495,
     496,   497,   498,     0,     0,     0,   510,   493,   494,   495,
     496,   497,   498,   499,   500,   501,     0,     0,     0,     0,
       0,     0,  1264,   499,   500,   501,     0,   507,     0,     0,
       0,     0,     0,   511,     0,     0,   504,  1259,  1260,  1261,
     510,     0,     0,   300,  1262,  1263,    42,     0,     0,     0,
       0,     0,   505,     0,     0,   508,   506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   511,   509,     0,     0,     0,     0,     0,  1029,
       0,     0,     0,     0,   504,     0,     0,     0,  1264,     0,
       0,     0,     0,     0,   507,     0,     0,     0,     0,     0,
     505,     0,     0,     0,   506,     0,   511,     0,     0,     0,
       0,     0,  3020,  3021,     0,     0,     0,     0,   300,  1262,
    1263,    42,   508,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3020,  3021,
     509,     0,   507,     0,   300,  1262,  1263,    42,  1029,     0,
       0,     0,   491,     0,   502,   510,     0,   503,     0,     0,
       0,     0,     0,  3022,   502,     0,     0,   503,     0,   492,
     508,     0,     0,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,  2565,     0,     0,     0,     0,   509,  3022,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3020,  3021,     0,     0,     0,     0,
     300,  1262,  1263,    42,  1029,     0,     0,     0,     0,     0,
       0,   511,   510,     0,     0,     0,     0,   493,   494,   495,
     496,   497,   498,     0,   493,   494,   495,   496,   497,   498,
       0,     0,     0,   499,   500,   501,     0,     0,     0,     0,
     499,   500,   501,     0,     0,  3022,     0,     0,     0,     0,
       0,  1261,     0,     0,     0,   300,  1262,  1263,    42,     0,
     510,     0,     0,     0,     0,     0,   504,     0,     0,     0,
       0,     0,     0,     0,     0,  1265,   504,     0,   511,  1029,
       0,     0,   505,     0,     0,     0,   506,     0,     0,     0,
    1266,     0,   505,     0,     0,     0,   506,     0,     0,     0,
    1264,     0,     0,     0,     0,  1029,     0,  1267,     0,     0,
    2566,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2567,  1269,   507,     0,   511,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,     0,   300,  1262,
    1263,    42,     0,     0,  1265,     0,     0,     0,     0,     0,
       0,     0,   508,     0,     0,     0,     0,     0,     0,  1266,
       0,     0,   508,  1270,     0,     0,     0,     0,     0,     0,
     509,  1029,     0,     0,   502,  1271,  1267,   503,     0,  1268,
     509,   502,     0,  3022,   503,     0,     0,     0,     0,     0,
       0,     0,  1269,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1265,     0,     0,     0,     0,     0,     0,  1272,     0,     0,
       0,     0,     0,     0,     0,  1266,  1029,     0,     0,     0,
       0,  3411,  1270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1267,     0,  1271,  1268,     0,     0,     0,     0,
       0,     0,   510,     0,     0,     0,  1273,     0,  1269,     0,
       0,     0,   510,     0,     0,     0,     0,     0,  1274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1275,  1276,     0,     0,     0,  1265,  1272,     0,  1277,     0,
       0,  1278,     0,     0,     0,     0,   504,     0,  1270,   321,
    1266,     0,     0,   504,     0,     0,     0,     0,     0,  1029,
    1271,  1265,   505,     0,     0,     0,   506,  3023,   511,   505,
    3024,     0,     0,   506,     0,  1273,  1266,     0,   511,     0,
       0,     0,     0,  3025,     0,     0,     0,  1274,     0,     0,
       0,     0,     0,  3023,     0,     0,  3024,     0,     0,  1275,
    1276,     0,  1272,     0,   507,     0,     0,  1277,     0,  3025,
    1278,   507,     0,     0,     0,     0,     0,     0,   321,     0,
       0,     0,  3026,  3027,     0,     0,     0,  1265,     0,     0,
       0,     0,   508,     0,     0,  3028,  1946,     0,     0,   508,
       0,  1273,  1266,     0,     0,     0,     0,     0,     0,  3027,
     509,     0,     0,  1274,     0,     0,     0,   509,     0,  3023,
       0,  3028,  3024,     0,     0,  1275,  1276,  2446,  2447,  2448,
    2449,  2450,  2451,  1277,     0,  3025,  1278,  3029,     0,     0,
       0,     0,  1265,     0,   321,     0,     0,     0,     0,     0,
    2446,  2447,  2448,  2449,  2450,  2451,     0,  1266,     0,     0,
       0,     0,     0,  3029,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1267,  3027,  3030,  1268,     0,     0,
       0,     0,     0,     0,     0,     0,  2452,  3028,  3031,     0,
    1269,     0,   510,     0,     0,     0,     0,     0,     0,   510,
    3032,  3033,  3030,     0,     0,     0,     0,     0,  3034,  2452,
       0,  3035,     0,     0,  3031,     0,     0,     0,     0,   321,
       0,     0,     0,     0,     0,  1265,  3032,  3033,     0,  3029,
    1270,     0,     0,     0,  3034,     0,     0,  3035,     0,     0,
    1266,     0,  1271,     0,     0,   321,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3023,   511,     0,
    3024,     0,     0,     0,     0,   511,     0,     0,  3030,     0,
       0,     0,     0,  3025,     0,     0,     0,     0,     0,     0,
    3031,     0,     0,     0,  1272,     0,     0,     0,     0,     0,
       0,     0,  3032,  3033,     0,     0,     0,     0,     0,     0,
    3034,     0,     0,  3035,     0,     0,     0,     0,     0,     0,
       0,   321,     0,  3027,  3382,     0,     0,     0,     0,     0,
       0,     0,     0,  1273,     0,  3028,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1275,  1276,     0,
       0,     0,     0,     0,     0,  1277,     0,     0,  1278,     0,
       0,     0,     0,     0,     0,     0,   321,  3029,     0,     0,
    3383,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3384,     0,     0,     0,     0,
       0,     0,     0,     0,  3385,     0,  3030,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3031,     0,
    2453,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3032,  3033,     0,  2454,     0,     0,     0,     0,  3034,     0,
    3386,  3035,     0,  2453,     0,     0,     0,     0,  3387,   321,
       0,     0,     0,     0,     0,     0,  2454,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2455,     0,
       0,     0,     0,     0,     0,  2456,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2455,     0,     0,     0,     0,     0,     0,  2456,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3388,  2457,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2457,  2458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2459,  2460,
       0,     0,     0,     0,  2461,     0,     0,     0,     0,     0,
       0,  2458,     0,     0,  2462,     0,     0,     0,     0,     0,
       0,  2459,  2460,     0,     0,     0,     0,  2461,     0,     0,
       0,     0,     0,     0,     0,     0,  2463,  2462,     0,  2464,
    2465,     0,     0,     0,     0,  2466,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2463,
       0,     0,  2464,  2465,     0,     0,     0,     0,  2466,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2467,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2468,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2467,     0,     0,     0,     0,
       0,     0,     0,     0,  3389,     0,  2468
};

static const short yycheck[] =
{
       4,   200,   416,   136,   219,   663,  1030,   156,     0,    13,
      14,  1259,  1260,    17,    68,   285,   286,  1112,   995,  1141,
     178,  1146,   287,   288,  1123,  1047,   795,   292,  1337,  1119,
    1120,  1044,  1122,    25,  1124,  1125,  1330,  1109,  2065,    31,
     968,   558,    46,    47,   793,    84,  1884,   696,  2402,   648,
      81,  1064,  2229,  2565,  2276,  2567,   583,  1365,    62,     5,
     754,  2283,    27,   719,  1850,  1851,   120,   200,    20,   600,
    2545,  1999,   779,    27,    78,    27,    68,    81,     5,     5,
      84,   202,    27,    27,    26,    27,   219,  2013,  2010,    93,
      24,  2445,    26,   251,    19,  2167,   100,  2756,  2757,  2758,
     104,    26,  1883,   107,   108,     5,    20,    63,  1946,   113,
     114,    25,     5,    27,   263,   264,     5,   716,    25,    26,
      27,    25,     5,    27,    92,    93,  1198,   726,   120,     5,
     779,   135,    19,     5,   105,    67,  1231,    24,    25,    26,
    1212,    97,  2759,    24,    25,    26,    27,     5,   152,   348,
      27,   155,  1951,  1952,  1953,  1954,   160,   813,  2786,    27,
      86,    87,  2344,   783,    24,    25,    26,    27,   289,     5,
       5,    24,   293,    26,   295,    27,   297,   298,   299,     5,
    1202,    27,   781,   782,    27,   306,     5,   143,   154,   310,
     311,   147,   791,   238,    25,  2559,    27,  2561,     5,   139,
     279,    73,    25,    75,    27,    77,    24,    25,    26,    27,
      24,    25,    26,    27,    25,   348,    27,   221,     5,   352,
    2441,     5,     5,     9,    10,     5,    12,    13,    14,    15,
      16,    17,    24,    25,    26,    27,    24,    25,    26,     5,
      25,     5,    27,  2755,  2756,  2757,  2758,    53,    54,    55,
      56,    57,     6,   195,     5,  1279,   260,   154,    67,     6,
       5,     5,   266,    25,     5,    27,     6,     5,     5,  2897,
       5,  2899,     5,   277,  2278,  2279,  2179,  1029,  2282,     5,
     284,   285,   286,   287,   288,   464,     5,   397,   292,  2953,
     172,    27,    70,   300,     5,    96,    27,   253,  2212,    23,
       5,  2215,  1130,  1131,  2816,   436,  2818,     5,     9,    10,
       5,    12,    13,    14,    15,    16,    17,   364,    27,  2346,
     535,   552,   592,    25,  2501,    27,   307,     0,   336,  2487,
     451,   395,  2336,   454,    27,   195,     5,   341,   342,     5,
    1268,     5,     5,   212,  2566,  1467,   167,   351,    31,  2837,
     471,   472,   473,   474,     5,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,     5,    25,     5,    27,   253,   195,    25,   279,
      27,   195,   503,   504,   195,   240,   279,   508,   464,   510,
    1412,   590,   623,    61,    62,     5,   544,    27,   167,  1168,
     544,     5,   535,   195,   525,   526,   527,   528,     5,     5,
     195,   532,   368,     5,   370,   380,     5,     5,  3224,   375,
      29,    89,    90,    91,    69,     5,    27,   691,   435,  3235,
     694,   695,  2920,   195,   481,    18,    19,    20,    21,    22,
       5,  3069,   436,  3071,   708,   593,   625,   662,     5,   593,
     155,    19,    18,    19,    20,    21,    22,   590,  2257,   195,
     155,     5,     5,   727,    28,     5,   730,     5,   424,   179,
     464,   257,   736,    27,   631,  2696,   740,   354,     5,    27,
     744,   145,  1506,     5,   748,   595,   354,  2491,   752,   753,
       5,   755,     5,   195,   758,   574,   760,   761,   762,     5,
     631,   279,   772,     5,   768,   559,   560,   771,  3020,  3021,
    2514,   519,  3024,     5,   778,   239,     5,     5,    86,   783,
     524,     5,   530,   788,   789,     5,   790,     5,   349,   662,
     390,   436,   582,     5,     5,  3199,   405,   801,     5,     5,
       5,   805,     5,   195,   591,   809,    23,   551,   195,   625,
     554,   815,   817,   288,   818,   820,   257,   250,   562,   464,
    2737,   606,   444,  2349,   506,   531,   276,   559,   560,   514,
     263,   349,   622,   455,   578,  3239,   580,   288,  2582,   519,
     349,  2739,  2740,   401,   436,   589,  2489,   591,   592,  2593,
     376,   377,   548,   436,   476,   379,  1348,   432,   416,   476,
     664,   483,   567,  2957,  2826,   436,   432,  2521,   476,   401,
    1230,   397,   395,   401,  1383,  3232,   548,   395,   560,   545,
     250,  2975,   468,   354,   416,   432,  1395,    27,   416,  1457,
     601,   476,   492,   263,   531,   616,  1153,   446,  1155,   484,
    2478,   195,    23,   397,  1351,   432,   397,   195,   434,   250,
     397,   595,   432,   397,   390,   510,   397,   397,   476,   397,
     397,  2733,   263,   631,   397,  1323,   432,   556,   432,   552,
     595,   397,  1379,   371,   574,   376,   377,   681,   397,  2607,
     556,   574,   686,   687,   688,   689,   690,   432,   692,   693,
    1384,   625,   696,   697,   552,   699,   623,   520,   702,  2625,
     704,  2623,  1351,   617,  2013,  3217,   632,   672,  3072,   713,
     617,  3223,  3224,   617,  3226,  3227,  3228,  3229,   672,  2500,
     672,   667,  1249,  3235,  1255,  3200,   562,   672,   397,   733,
    1379,   397,   674,   434,   397,   739,  3211,   874,   625,   548,
     559,   745,   746,   747,   625,  2749,   397,   751,   393,  3377,
     754,   623,   756,   757,  2936,   349,   140,   141,  2940,   631,
     358,   459,   239,   767,   397,   625,   397,  3426,   772,   773,
    2078,   802,   625,   418,   476,   779,   562,   475,    26,    27,
     591,   550,   786,   589,   788,   789,   344,   397,   481,   793,
     794,   795,   460,   397,   556,   799,   574,   582,   802,   344,
     397,   397,   436,   807,   497,   397,   436,   625,   397,   397,
     814,   625,   816,   817,   583,   819,   820,   397,   822,   823,
     518,  3333,    10,  1479,  3336,  3337,  3338,  3339,   243,   463,
      28,    29,   397,   625,  1248,   436,   390,   625,    27,   468,
     397,  3195,   628,   644,   645,   646,   647,   648,  1112,   432,
     622,   481,  3327,   397,   397,   364,   501,   397,   239,   397,
     558,   562,   983,  1876,  1877,   986,   432,   497,  2654,   247,
     397,   691,  1885,   994,   995,   397,   654,   655,   656,   547,
     481,    25,   397,    27,   397,   300,  2890,   665,  2892,   587,
     367,   397,   678,   679,   344,   397,   497,   338,   596,    38,
    3042,    40,    41,    42,  1503,   397,  3418,   727,   397,   397,
     730,   486,   360,   397,  3426,   365,    25,   397,    27,   397,
     740,  2534,   590,   927,   744,   397,   397,   628,   748,   625,
     397,   397,   397,   162,   397,   755,  2231,   352,     5,   329,
     760,   356,   762,    26,    27,  1958,   346,   195,   768,   594,
     391,   771,   464,  3079,   354,   355,  3082,     0,   778,  3085,
     544,   606,   607,   783,   968,  1229,  1230,  1231,   162,   614,
     790,   168,   481,  1986,   171,   358,  2589,   678,   679,   397,
     380,   801,    25,   383,  2083,   805,   367,    26,    27,   809,
    1127,  2286,  2287,     5,  2815,   815,  2817,  1134,   818,  2820,
     720,   401,  1006,   464,  1008,  3009,   195,   601,    38,   593,
      40,    41,    42,   431,  2323,  3237,   645,    20,  2327,   648,
     435,   371,  1950,   743,    27,  1029,   584,  3204,  1956,  1957,
      25,    25,    27,    27,  1962,  1963,  1964,  1965,  2902,   584,
    1044,  2905,    25,  1047,    27,  1001,    18,    19,    20,    21,
      22,   195,  2124,   329,  3058,   630,    14,  1061,   442,    25,
    1064,    27,   436,    25,   253,    27,   254,   787,    51,    52,
    3212,  3213,   301,   527,   649,   650,   796,   797,   275,   630,
     800,   278,   591,   595,   804,   117,   195,   287,   541,  3093,
     810,   539,   812,    25,   669,    27,   486,  2192,  1102,    25,
     300,    27,   653,   300,   624,   553,   506,   301,    25,   459,
      27,   631,   195,   625,  1118,  1119,  1120,    20,  1122,   464,
    1124,  1125,    26,    27,    27,   475,  1130,  1131,  1398,    27,
     578,  1396,  2109,    20,   584,  3261,   275,  3024,   436,   278,
      27,   280,   287,    66,   127,   128,   554,   130,   131,   378,
      20,    25,   135,    27,   562,   300,   195,    27,   463,   464,
     560,   300,  1166,   713,  1168,   463,   464,   567,   518,   152,
     153,   310,  2185,  3011,  1178,   243,     9,  1326,   626,  1183,
    1329,   436,    20,   733,   378,    18,    19,   170,   762,    27,
     329,    24,    25,    26,    27,   436,   746,   771,  1202,  1203,
     195,   195,    68,  3207,   392,  2133,   394,  1211,   558,    20,
     486,   109,   195,   352,  1484,   138,    27,   356,   431,  1489,
    1485,   221,   801,  1227,  1228,   225,   805,   436,   526,   195,
     809,    64,   300,   195,  2247,   435,    69,   587,   435,    26,
     630,   815,   436,    76,   818,   275,   596,   464,   278,  1253,
     280,  2546,   481,  2022,  2549,  1259,  1260,   401,   241,   649,
     650,   159,  3326,   195,  1268,  3086,  3330,   371,   497,   195,
     300,   104,   630,   681,  1278,    25,   436,    27,   195,   669,
     310,   204,  1286,   206,   352,    26,    20,   481,   356,   436,
     435,   195,  1112,    27,   652,   653,   435,   195,   221,   197,
    2594,  2229,   436,   497,    20,  2427,   229,   436,  1347,  2237,
     233,    27,  2240,  2241,  2242,  2243,  2625,    25,    26,  3315,
    3316,   195,   352,   323,  1973,   436,   356,  1331,  2622,   436,
    3217,  1335,  1336,  1337,   436,   258,  3223,  1057,  2107,  3226,
    3227,  3228,  3229,  1347,  1348,   436,    24,  1351,    26,  1353,
    1354,   436,  3379,  1357,   630,   459,    38,   436,    40,    41,
      42,   630,   195,    19,   197,   645,   646,   435,    24,  3396,
      26,   475,   436,   649,   650,  1379,  1380,   436,  1382,  1383,
    1384,   463,   464,   652,   653,  1128,  1129,  1391,  1392,  1132,
    1133,  1395,  1396,   669,  1398,  1399,   294,   631,  2493,   463,
     464,  3397,  2171,  3399,  2614,   435,  2616,  2617,  1412,  1229,
    1230,  1231,    30,   730,   518,  3442,   436,  3216,  2513,  3218,
    3219,  3220,  3221,   300,   631,   397,  1146,   744,  2177,   647,
     648,   748,  3459,    51,    52,   436,  1156,  2036,   304,   816,
     436,  1161,   819,   760,   436,   822,  3333,    18,    19,  3336,
    3337,  3338,  3339,  1457,   558,    26,    27,   340,   654,   655,
     443,   294,   526,  2476,   362,   436,   299,   644,   351,   436,
     647,   648,   370,   654,   655,   352,   374,   436,  1482,   356,
    1484,  1485,    25,   587,    27,  1489,   371,  1491,   436,  1493,
    1494,   436,   596,    64,   327,   168,   362,   436,   171,   618,
     619,   620,   621,  2516,    25,    76,    27,   436,   374,   127,
     128,  1515,   130,   131,   412,   436,    25,   135,    27,   385,
      24,   404,    26,   196,   675,   676,   677,   168,   436,   362,
     171,  3418,    26,   104,   152,   153,   419,   403,   113,   114,
     115,   374,  3020,  3021,   371,  2314,  2559,   413,  2561,    25,
     416,    27,   170,    26,    24,   196,    26,   436,   435,  2328,
     393,  2330,    26,   429,  2636,   398,  2814,  2815,   401,  2817,
    2339,    26,  2820,  2501,   459,  2674,    26,   625,  2095,   412,
    2705,   479,  1847,  1848,    25,   418,    27,  1380,   531,  1382,
     475,   292,   293,   275,   436,   428,   278,   444,   280,  2671,
     433,   436,   275,   436,   436,   278,   439,  2729,   455,    26,
    2919,   477,   436,   436,   436,   448,   449,  2911,   300,   436,
     518,   436,   436,  2551,   195,   508,   197,   300,   310,   476,
     695,   426,   459,   518,   275,   464,   483,   278,  2566,    26,
      26,   507,   371,   708,    26,   543,    26,   329,   475,  2577,
      26,   517,   625,    63,   397,   488,   489,   436,    26,   300,
     493,   366,   625,   436,   371,  1385,  1386,  1387,   501,   436,
     352,   736,   538,   558,   356,   541,   432,   543,     5,   512,
     397,   138,  1402,   436,   397,   518,   397,   752,   753,   587,
     476,   518,   436,   758,   397,   397,   761,   631,   596,    30,
      20,    19,   587,  2680,    20,   571,    24,    25,    26,   436,
     543,   596,  2689,  2690,   580,   436,  1874,   397,   718,   719,
      51,    52,  1880,   294,     5,  2324,   436,   464,   629,    60,
     459,   558,   625,    26,    65,   263,   432,   397,  1458,   366,
      20,    26,    26,   361,    26,   595,   475,   204,    26,   206,
      26,    26,   459,   435,   587,    26,   327,   397,  1478,   397,
     587,   594,   435,   596,   221,    26,  2365,  1916,   475,   596,
      26,   397,   229,   606,   607,  1495,   233,   397,  2706,   110,
     111,   614,   680,   681,   397,  1505,     5,   118,   371,   518,
      20,   362,   625,   411,   435,    26,   127,   128,    30,   130,
     131,   258,   436,   374,   135,    26,  2070,   625,    26,  2737,
     397,   518,  2077,   813,     5,  2414,   397,    26,   397,    51,
      52,   152,   153,   823,    18,    19,    20,    21,    22,   558,
     307,   397,   397,   397,  1983,   397,   629,     5,  3086,   170,
     397,   412,  1846,  1847,  1848,   397,   436,   680,   681,  1853,
    1854,   558,   397,  1974,   472,   631,    26,   428,   587,   595,
    2629,   631,   397,    25,    25,   436,    25,   596,   397,  1873,
      25,  2640,  1876,  1877,   397,   397,   459,  1881,   449,  1883,
     587,  1885,  2152,  2153,   397,    20,    21,    22,   307,   596,
     397,   397,   475,   625,  2822,   127,   128,   397,   130,   131,
     397,  2166,   397,   135,    39,  1909,   397,   629,   397,   397,
    2174,   436,     8,   464,   432,   484,  1920,   271,   622,   625,
     152,   153,   493,   465,     5,    25,   623,   601,  2192,   623,
     426,   138,   465,   664,   664,   518,   331,     8,   170,   602,
    2962,     5,     5,   389,  1948,   349,  1950,   518,   595,   436,
     436,   436,  1956,  1957,  1958,   436,   436,     8,  1962,  1963,
    1964,  1965,    97,    98,    99,   100,   101,   102,   968,  1973,
     584,    14,   543,  2094,   581,   558,     5,   664,   113,   114,
     115,     5,  1986,   664,   426,   436,    26,   436,  2109,  2966,
      26,    70,    96,   464,   625,  1999,   595,   204,   436,   206,
     436,   436,   436,   436,   587,   436,  2010,   436,   426,  2013,
     464,    26,  3036,   596,   221,     5,   587,   601,  2022,   625,
     436,   595,   229,  1979,   436,   596,   233,     5,  2032,  2033,
    2034,   631,  3154,   436,   436,  2039,   631,   244,   667,   630,
    3162,   372,   355,   562,     5,    18,    26,  1047,    19,     5,
      26,   258,   157,    25,  3176,   595,   223,   584,   970,  3072,
     628,   973,  2066,   975,   976,   977,   978,   979,   399,   625,
    2074,  2075,   487,  2077,   487,     5,    51,    52,   552,   155,
     552,    26,   182,   405,   326,  2089,   552,    26,   397,   436,
     631,   397,  2096,     6,     7,     8,     9,    10,    11,    12,
    2315,  2105,   397,  2107,   531,   625,   436,   436,   436,   680,
     681,   436,  2382,   436,   669,   625,   464,   582,   397,   254,
     552,   622,   257,   631,  2128,     5,  2130,  2131,     5,  2133,
       5,     5,  2136,  2137,   436,   625,   488,   585,   631,   470,
       5,  3236,     8,    26,    26,   541,   630,  2916,  2152,  2153,
      70,   330,   127,   128,     5,   130,   131,  2926,     5,   164,
     135,  3089,  2166,  3091,   397,   365,   436,  2171,  2172,  2173,
     436,   631,  1948,  2177,   602,   180,   181,   152,   153,    14,
     552,  2185,  2315,  3305,   189,  2841,  2842,  2843,     5,  2845,
    2846,  2847,  2848,  2849,  2850,   170,   665,   556,  2854,  2203,
      26,   105,  1202,   625,     5,   631,   630,  2211,  2212,   309,
     436,  2215,   436,    26,   644,   315,   316,   317,   223,   432,
     397,     5,     5,  2487,   373,  2229,   624,   232,   336,  2493,
     432,   466,   563,  2237,     8,   335,  2240,  2241,  2242,  2243,
    2244,   376,     5,  2247,   466,     5,   436,  2251,  2252,  2513,
    2070,  2255,   436,   436,   436,   436,   261,   392,   436,  1259,
    1260,   396,   436,   625,   625,     8,   241,   559,  1268,   330,
      25,   349,  2276,   436,  2278,  2279,  3204,   349,  2282,  2283,
     625,   349,   365,   431,   464,  3407,     5,   426,   464,     5,
     656,  3313,  3382,  3383,  3384,  3385,  3386,  3387,    26,   434,
       5,   306,     5,    25,    14,  2309,    14,   601,  2312,   265,
    2314,    26,   643,   601,   622,   436,     5,     5,  2038,  2323,
     651,   631,   397,  2327,  2328,   436,  2330,   462,   397,     6,
     397,   397,  2336,  2053,     7,  2339,  2340,   397,   397,  2343,
    2344,   453,   273,   348,   444,   480,     5,   447,   304,   397,
      26,   625,  2072,     8,  2174,   455,  2076,    26,  2362,   631,
    2136,    26,   625,   397,    20,     5,   572,   323,    62,  2373,
     279,     5,  2192,     5,     5,   673,     5,   552,  2382,   397,
     577,   625,   436,    18,    19,    20,    21,  3156,   397,   476,
     490,   631,     5,   559,   631,   215,  2116,   397,  2402,   476,
     629,  3329,    18,    19,    20,    21,   362,     5,   631,   436,
     436,   631,  1412,     5,   629,    25,    25,    25,   374,   624,
     452,  3398,    25,    25,  2428,   525,    26,   562,   301,   385,
      26,    26,    26,    26,     5,    26,  3364,    26,   397,   397,
    3098,   135,   136,   473,     5,   545,   546,   403,  1239,  2719,
     436,  2721,   245,   397,   556,    25,   556,   413,    26,   397,
     349,   561,    97,    98,    99,   100,   101,   102,   443,   432,
      20,   559,  2476,   429,   144,  2739,  2740,   446,     5,  1479,
    2534,    97,    98,    99,   100,   101,   102,  2491,   436,  2704,
     436,     5,    14,   628,  3516,  2499,  2500,  2501,   123,   436,
     600,   436,   436,   436,   436,   447,   200,     5,   215,   464,
    2514,   397,  2516,   469,    26,    26,  2520,  2521,   397,   397,
     379,   397,   574,    26,   245,   219,   397,  3296,   397,   397,
     436,   349,   632,   397,   246,  2589,   492,   464,   446,   552,
    3468,   436,  2534,   397,    14,   625,     7,  2551,   244,   244,
      26,   507,   397,   581,   398,  2559,  2677,  2561,   514,  2680,
    2564,   517,  2566,    20,    21,   397,   631,   625,  2689,  2690,
     397,  2704,   432,  2577,   436,   436,    25,     5,  2582,  2583,
    2584,   397,   538,   246,   625,   541,   397,   543,   397,  2593,
     397,   397,   397,     5,  2598,   397,  2316,  2589,  2684,  2633,
     625,   226,   625,  2607,  3452,   994,   562,    25,  2398,   234,
    1496,  2331,  2332,  2333,  2334,   240,  2117,   242,    38,  2623,
     143,  2625,  2340,    40,   580,  2629,   375,  2665,   253,  2633,
      20,    21,  2352,   559,  2346,   369,  2640,   147,   235,  1978,
      97,    98,    99,   100,   101,   102,   665,   341,   342,   376,
    1979,   548,   237,  3067,   348,   609,   281,  1258,   352,   566,
     404,  2665,   403,  2667,   578,  2669,  3442,  2487,   580,  2038,
     799,   986,   297,  2493,   436,  1236,  2209,   302,  2682,  2944,
    2684,  2685,  2686,  2333,  2216,  2076,  2951,  1846,  2408,   314,
    2710,  2989,  1849,  2513,  2424,  2699,   321,    30,  2144,  3493,
    2337,  2161,  2706,  2707,  2708,  1398,  3170,    97,    98,    99,
     100,   101,   102,    25,   120,  2719,    31,  2721,    51,    52,
    3119,    31,   757,  2122,  2128,   929,   352,  2731,  2732,  1854,
    2708,  1008,  3116,  2737,  2131,  1203,  3269,  1392,  3459,  2938,
    1455,  2881,  2706,  1382,  3279,  2749,   470,    80,  1156,  2879,
    1478,  2755,  2756,  2757,  2758,  2759,  2760,  2863,  2592,  1357,
    2327,  1993,  2016,  3468,   182,  2487,  2770,  3093,  2517,  3354,
    2889,  2775,  2282,  2247,  2184,  2803,  2593,  2804,  3083,  3360,
    1873,  3136,  2564,  2598,  2504,    17,  2506,  3509,  1232,  2583,
    3019,  2750,  1957,  2584,   127,   128,  3091,   130,   131,  2803,
    2804,  1956,   135,  3323,  3018,  2938,  1868,  1228,  3215,  3234,
    2814,  2815,  1841,  2817,  3223,  2312,  2820,  1397,  2822,   152,
     153,   557,  2826,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     524,    -1,    -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,
      -1,   535,    -1,    -1,    -1,  2966,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,  1854,    -1,    -1,    -1,   483,    -1,
      -1,  2865,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2878,    -1,    -1,    -1,    -1,    -1,
     505,    -1,    -1,  3153,    -1,   510,  2890,  2891,  2892,    -1,
      -1,   309,    -1,    -1,    -1,    -1,   590,   315,   316,   317,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,    -1,
      -1,    -1,  2916,    -1,    -1,  2919,    -1,   335,    -1,  2739,
    2740,    -1,  2926,    -1,    -1,    -1,  2646,    -1,    -1,  2649,
      -1,    -1,  2936,    -1,    -1,  2939,  2940,    -1,    -1,    -1,
    2944,    -1,    -1,    -1,    -1,    -1,    -1,  2951,    -1,  2953,
    1950,    -1,    -1,    -1,    -1,    -1,  1956,  1957,  2962,    -1,
      -1,    -1,  1962,  1963,  1964,  1965,    -1,    -1,   662,    -1,
      -1,    -1,  3236,    -1,    -1,    -1,    -1,    -1,    -1,  2755,
    2756,  2757,  2758,    -1,    -1,  2705,    -1,    -1,    -1,    -1,
      -1,    -1,   686,   687,   688,   689,    -1,    -1,    -1,  3003,
      -1,    -1,    -1,    -1,    -1,  3009,    -1,    -1,    -1,    -1,
     704,    -1,    -1,    -1,  3018,    -1,  3020,  3021,   436,    -1,
    3024,    -1,    -1,    -1,    -1,    -1,   444,    -1,   361,   447,
      -1,  3035,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   739,    -1,    -1,    -1,    -1,
      -1,   745,    -1,   747,  3058,    -1,  3060,   751,    -1,    -1,
     754,  2620,    -1,   757,    -1,    -1,    -1,    -1,  3072,    -1,
      -1,    -1,   490,   767,    -1,    -1,  3080,    -1,   411,  3083,
      -1,    -1,  3086,    -1,    -1,  3089,    -1,  3091,    -1,  3093,
      -1,    -1,   786,    -1,    -1,    -1,    -1,    -1,    -1,   793,
     794,   795,    -1,    -1,  3319,   799,    -1,   525,    -1,    -1,
     443,    -1,  3116,   807,    -1,    -1,  1907,  1908,    -1,    -1,
      -1,    -1,    -1,  1914,    -1,    -1,    -1,   545,   546,   823,
      -1,    -1,    -1,  2133,    -1,    -1,    -1,    -1,   556,   472,
      -1,    -1,    -1,   561,    -1,    -1,    -1,    -1,    -1,  3153,
      -1,    -1,  3156,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   600,    -1,    -1,    -1,  3319,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3199,  2755,  2756,  2757,  2758,
    3204,    -1,    -1,  3207,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3215,    -1,  3217,   632,    -1,    -1,    -1,    -1,  3223,
    3224,    -1,  3226,  3227,  3228,  3229,    -1,  2947,  3232,  2229,
    3234,  3235,    -1,  3237,    -1,  3239,    -1,  2237,    -1,    -1,
    2240,  2241,  2242,  2243,  3020,  3021,    -1,    -1,  3024,    -1,
      -1,    -1,  2252,    -1,    -1,    -1,    -1,  2977,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3269,    -1,    -1,    -1,    -1,
    3274,    -1,  3276,    -1,    -1,    -1,  2276,  3398,    -1,    -1,
      -1,    -1,    -1,  2283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3080,    -1,    -1,  3083,  2099,  3313,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3323,
      -1,    -1,    -1,    -1,    -1,  3329,    -1,    -1,    -1,  3333,
      -1,    -1,  3336,  3337,  3338,  3339,  3340,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2140,
    3354,    -1,    -1,  1047,    -1,    -1,  3360,    -1,    -1,    -1,
    3364,    -1,    -1,    -1,    -1,    -1,    -1,  1061,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3382,  3383,
    3384,  3385,  3386,  3387,    -1,    -1,    -1,    -1,    -1,    -1,
    3394,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,  1102,    -1,
      -1,    -1,    -1,    -1,  3418,    -1,  3236,    -1,    -1,    -1,
      -1,    -1,  3426,    -1,  1118,  1119,  1120,    -1,  1122,    -1,
    1124,  1125,    -1,    -1,    -1,    -1,  1130,  1131,  3158,  3215,
      -1,  3217,    -1,    -1,    -1,    -1,    -1,  3223,  3224,    -1,
    3226,  3227,  3228,  3229,    -1,    -1,    -1,    -1,    -1,  3235,
      -1,  3020,  3021,    -1,  3468,  3024,  3470,    -1,    -1,    -1,
    3190,    -1,    -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      -1,  2501,    -1,  3507,  3508,  3509,    -1,   189,  1202,  1203,
      -1,    -1,  3516,    -1,  3518,    -1,    -1,  1211,    -1,    -1,
      -1,  3080,    -1,    -1,  3083,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1227,  1228,    -1,    -1,    -1,    -1,    -1,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,  2551,    -1,    -1,    -1,    -1,    -1,  3333,    -1,    -1,
    3336,  3337,  3338,  3339,  2564,    -1,  2566,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2577,    -1,   261,
     262,    -1,    -1,    -1,  3360,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2392,  2393,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2403,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2620,     6,     7,     8,   306,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,  2429,  2430,
    2431,  2432,  3418,    -1,    -1,    -1,  2437,  2438,  2439,  2440,
    3426,    -1,    -1,  2444,    39,    -1,    -1,    -1,  3217,    -1,
      -1,    -1,    -1,    -1,  3223,  3224,   348,  3226,  3227,  3228,
    3229,    -1,    -1,  3393,    -1,    -1,  3235,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1380,    -1,  1382,  1383,
    1384,    -1,  3251,    -1,    -1,    -1,    -1,  1391,  1392,    -1,
      -1,  1395,    -1,    -1,    -1,  1399,  2706,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,  1412,    -1,
      -1,    -1,    -1,   405,    -1,    -1,    -1,    -1,   113,   114,
     115,  2522,  2523,    -1,    -1,    -1,    -1,  2737,  2529,  2530,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2755,  2756,  2757,  2758,    -1,
      -1,    -1,    -1,  1457,    -1,    -1,    -1,    -1,  3488,    -1,
      -1,    -1,    -1,    -1,  3333,    -1,    -1,  3336,  3337,  3338,
    3339,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1491,    -1,    -1,
      -1,  3360,    -1,  2803,  2804,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2814,  2815,    -1,  2817,    -1,    -1,
    2820,  1515,  2822,    -1,    -1,    -1,  2826,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2841,  2842,  2843,    -1,  2845,  2846,  2847,  2848,  2849,
    2850,    -1,    -1,    -1,  2854,    -1,    -1,    -1,    -1,  3418,
      -1,    -1,    -1,    -1,  2655,  2656,    -1,  3426,    -1,   254,
      -1,    -1,   257,  2664,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,  2693,  2694,    -1,    -1,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,  2720,
      -1,  2722,    64,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      39,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,    -1,  2962,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    -1,   104,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,  2776,  2777,    -1,    -1,  2780,
    2781,   376,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,   397,    -1,   113,   114,   115,    -1,    -1,    -1,
    3020,  3021,    -1,    -1,  3024,    -1,    69,    -1,    -1,    -1,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   434,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,    39,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,  2869,    -1,
    3080,    -1,    -1,  3083,    -1,    -1,  3086,    -1,    -1,  3089,
      -1,  3091,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,  2937,    -1,    -1,    -1,
    2941,    -1,   195,    -1,    -1,   254,    -1,    -1,   257,  1853,
    1854,    -1,   294,  2954,    -1,    -1,    -1,   299,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,
      -1,    -1,  2973,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3204,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1909,    -1,  3217,    -1,    -1,
      -1,    -1,    -1,  3223,  3224,    -1,  3226,  3227,  3228,  3229,
     362,    -1,    -1,    -1,    -1,  3235,    -1,  3237,    -1,    -1,
      -1,    -1,   374,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3251,    -1,    -1,    -1,    -1,   299,    -1,    -1,    -1,
      -1,   393,    -1,    -1,    -1,    -1,   398,    -1,    -1,   401,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,   254,
     412,    -1,   257,    -1,    -1,    -1,   418,    -1,    -1,    -1,
      -1,    -1,    -1,   392,    -1,    -1,   428,   396,    -1,    -1,
      -1,   433,    -1,    -1,   436,    -1,    -1,   439,    -1,    -1,
      -1,    -1,    -1,  3313,    -1,    -1,   448,   449,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2022,  3329,
      -1,    -1,     9,  3333,    -1,   434,  3336,  3337,  3338,  3339,
      -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,   489,   401,    -1,
    3360,   493,    -1,   462,  3364,    -1,    -1,    -1,    -1,   501,
      -1,    -1,    -1,   416,    -1,    -1,    -1,    -1,    -1,    -1,
     512,   480,   514,    -1,    -1,    -1,   518,    64,    -1,    -1,
     433,    -1,    69,   436,    -1,  2089,    -1,  3188,    -1,    76,
    3191,   376,  2096,    -1,    -1,   448,   449,    -1,    -1,    -1,
      -1,   543,    -1,  2107,    -1,    -1,    -1,   392,  3418,    -1,
      -1,   396,    -1,    -1,    -1,    -1,  3426,   104,    -1,    -1,
      -1,    -1,    -1,   476,  2128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2137,    -1,    -1,   489,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   587,    -1,    -1,   501,   434,
      -1,    -1,   594,   562,   596,    -1,    -1,    -1,  3468,    -1,
      -1,    -1,    -1,    -1,   606,   607,    -1,  2171,  2172,  2173,
      -1,    -1,   614,  2177,    -1,    -1,    -1,   462,    -1,    -1,
      -1,    -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,
     543,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,  2203,
      -1,    -1,    -1,    -1,    -1,    -1,  3516,    -1,   195,    -1,
     197,    -1,    -1,    -1,    -1,    -1,  3317,    -1,    -1,   628,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,   680,   681,
      -1,   594,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,   606,   607,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,   617,  3366,  3367,    -1,  3369,    -1,
    3371,  3372,   625,    -1,    -1,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,   294,    -1,    -1,
    2314,  2315,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2328,    -1,  2330,    -1,    -1,   104,
      -1,  3432,    -1,  3434,    -1,  2339,    -1,    -1,    -1,    -1,
     327,    -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3466,    -1,    -1,    -1,  2373,
      -1,    -1,    -1,    -1,    -1,   362,    -1,    -1,    -1,    -1,
      -1,  3482,  3483,    -1,    -1,  3486,    -1,   374,  3489,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2402,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,   398,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
     195,    -1,   197,    -1,    -1,   412,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   428,    -1,    -1,    -1,    -1,   433,    -1,    -1,   436,
      -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,   488,   489,    -1,    -1,    -1,   493,    39,    -1,    -1,
      -1,    -1,     9,    -1,   501,    39,  2520,    -1,    -1,   294,
      -1,    18,    19,    20,   299,   512,    -1,    24,    25,    26,
      27,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   327,    -1,    -1,    -1,   543,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    69,    97,    98,    99,   100,   101,   102,  2583,
      -1,   113,   114,   115,    -1,    -1,    -1,   362,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   374,
     587,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,   596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   393,   606,
     607,    -1,    -1,   398,    -1,  2629,   401,   614,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2640,   412,   625,    -1,
      -1,    -1,    -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   428,    -1,    -1,    -1,    -1,   433,    -1,
      -1,   436,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   448,   449,    -1,    -1,    -1,  2682,    -1,
    2684,    -1,  2686,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   680,   681,  2699,    -1,    -1,   195,    -1,
    2704,    -1,    -1,  2707,  2708,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   489,    -1,    -1,    -1,   493,    -1,
      -1,    32,   254,    34,    -1,   257,   501,  2731,  2732,    -1,
     254,    -1,    -1,   257,    -1,    -1,    -1,   512,    -1,    -1,
      -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2770,    -1,   543,    -1,
      -1,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   299,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   587,    -1,    -1,    -1,    -1,    -1,    39,   594,
      -1,   596,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   606,   607,    -1,    -1,    -1,    -1,    -1,    -1,   614,
     133,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,   142,
     625,    -1,   376,    -1,    -1,    -1,    -1,    -1,   151,    -1,
     392,  2865,    -1,   156,   396,   397,    -1,    -1,   392,    -1,
      -1,    -1,   396,    -1,  2878,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,    -1,   401,   680,   681,   200,    -1,    -1,
     434,    -1,  2916,    -1,    -1,   208,    -1,    -1,    -1,   416,
      -1,    -1,  2926,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     462,    -1,    -1,    -1,  2938,    -1,   433,    -1,   462,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,  2953,
      -1,   448,   449,    -1,   265,    -1,   480,    -1,  2962,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   489,   304,    -1,    -1,   289,    -1,    -1,    -1,
      -1,    -1,    -1,   296,   501,   298,    -1,    -1,    -1,    -1,
      -1,    -1,   323,    -1,    -1,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   339,    -1,
     562,    -1,    -1,   254,    -1,    -1,   257,    -1,   562,    -1,
      -1,   334,    -1,    -1,    -1,    -1,   543,    -1,    -1,   342,
      -1,   362,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   374,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,   380,    -1,    -1,
      -1,    -1,   403,    -1,    -1,    -1,   628,   594,    -1,    -1,
      -1,    -1,   413,    -1,   628,    -1,    -1,    -1,    -1,   606,
     607,    -1,  3116,   406,    -1,    -1,    -1,   614,   429,    -1,
     617,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,   444,  3156,    -1,    -1,   376,    -1,    33,   469,    -1,
      -1,    -1,   455,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   392,    -1,    49,    -1,   396,   397,    -1,    -1,    -1,
      -1,   492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,  3199,   507,    -1,    -1,    -1,
      76,    -1,    -1,   514,    -1,    -1,   517,    -1,    -1,    -1,
      -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   538,   104,    -1,
     541,    -1,   543,   109,   110,  3239,    -1,   113,   114,   115,
     116,   462,    -1,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,
      -1,   554,   555,   556,    -1,  3269,    -1,    -1,    -1,   580,
    3274,    -1,  3276,    -1,   567,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,    -1,    -1,  3313,
      -1,   622,   188,    -1,    -1,  3319,    -1,    -1,   194,   195,
      -1,   197,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   670,  3382,  3383,
    3384,  3385,  3386,  3387,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   279,    -1,    -1,    -1,   628,    -1,   285,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   294,   295,
      -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,   304,   305,
      -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,    -1,   315,
     316,    -1,    -1,    -1,    -1,    -1,   322,   323,   324,   325,
     326,   327,    -1,    -1,    -1,   331,    -1,    -1,    -1,   335,
      -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,
     346,   347,    -1,   349,   350,    -1,    -1,    -1,   354,   355,
      -1,   357,   358,   359,   360,   361,   362,   363,   364,    -1,
      -1,    -1,    -1,    -1,   370,   371,   372,    -1,   374,   375,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,   387,  3516,   389,    -1,    -1,    -1,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,    -1,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
      -1,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,   471,   472,    -1,   474,   475,
     476,   477,    -1,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,    -1,
     516,   517,   518,   519,   520,   521,    -1,    -1,   524,   525,
      -1,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,    -1,    -1,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,    -1,    -1,    -1,    -1,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   651,    -1,    -1,    -1,    -1,
     656,    -1,    -1,    -1,   660,    -1,    -1,   663,   664,   665,
     666,    -1,    -1,   669,   670,    -1,   672,   673,   674,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    14,   265,
      -1,    -1,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,   323,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,    -1,
      -1,    -1,    -1,   109,   110,    -1,   362,   113,   114,   115,
     116,    -1,    -1,   119,   120,    -1,    -1,    -1,   374,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,   413,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   429,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,   188,    -1,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,    -1,    -1,    -1,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   469,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,
     266,   517,    -1,    18,    19,    20,    -1,    -1,    -1,    24,
      25,    26,    27,   279,    -1,    -1,    -1,    -1,    -1,   285,
      -1,    -1,   538,    -1,    -1,   541,    -1,   543,   294,   295,
      -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,   304,   305,
      -1,    -1,    -1,   309,    -1,    -1,   562,    -1,    -1,   315,
     316,    -1,    -1,    -1,    69,    -1,   322,   323,   324,   325,
     326,   327,    -1,    -1,   580,   331,    -1,    -1,    -1,   335,
      -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,   344,   345,
     346,   347,    -1,   349,   350,    -1,    -1,    -1,   354,   355,
      -1,   357,   358,   359,   360,   361,   362,   363,   364,    -1,
      -1,    -1,    -1,    -1,   370,   371,   372,    -1,   374,   375,
      -1,    -1,    -1,   379,   380,   381,   382,   383,   384,   385,
     386,   387,    -1,   389,    -1,    -1,    -1,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,    -1,   432,   433,    -1,    -1,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     195,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,   464,   465,
     466,   467,   468,   469,   470,   471,   472,    -1,   474,   475,
     476,   477,    -1,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,    -1,
     516,   517,   518,   519,   520,   521,    -1,    -1,   524,   525,
      -1,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,    -1,    -1,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,    23,    -1,    -1,    -1,   622,   623,   624,   625,
     626,   627,   628,   629,   630,   631,   632,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,   643,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   651,   401,    -1,    -1,    -1,
     656,    -1,    -1,    -1,   660,    -1,    67,   663,   664,   665,
     666,   416,    -1,   669,   670,    -1,   672,   673,   674,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,
      -1,   436,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   476,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,
      -1,    -1,    -1,    -1,   489,    18,    19,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    -1,   501,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,    -1,    -1,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    69,    -1,   543,    -1,
      -1,    -1,    -1,   204,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,    -1,   233,    -1,    -1,    -1,    -1,   582,   239,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,   594,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,    -1,    -1,
      -1,   606,   607,    -1,    -1,    -1,    -1,    -1,    -1,   614,
      -1,    -1,   617,    -1,   275,    -1,    -1,   278,    -1,   280,
     625,    -1,    -1,    -1,    -1,    -1,   287,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   310,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,   195,    -1,    35,    36,    37,    -1,   329,   330,
      -1,    -1,    43,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      51,    52,    -1,   344,    -1,    -1,    -1,    -1,    59,    -1,
      -1,   352,    -1,    -1,    -1,   356,    -1,    -1,    -1,    -1,
      71,    72,    -1,    74,   365,   366,   367,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    -1,   134,   135,   136,   137,    -1,    -1,    -1,
      -1,    -1,   143,    -1,   435,   146,    -1,   148,   149,   150,
      -1,   152,   153,    -1,    -1,   446,    -1,   158,    -1,   160,
     161,    -1,   163,    -1,   165,   166,    -1,    -1,   169,   170,
      -1,    -1,   173,   174,   175,    -1,   177,   178,    -1,    -1,
      -1,   182,   183,   184,    -1,   186,    -1,    -1,    -1,   190,
      -1,   192,   193,    -1,    -1,   486,    -1,   198,    -1,    -1,
      -1,   202,    -1,    -1,   205,    -1,   207,    -1,   209,    -1,
     211,    -1,   213,   214,    -1,   216,   217,   218,    -1,    -1,
      -1,   222,    -1,   224,   225,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,   236,    -1,    -1,   401,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   248,    -1,    -1,
     251,   252,    -1,   416,   255,   256,    -1,   548,   259,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,   269,   270,
     433,   272,    -1,   436,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   282,   283,   284,    -1,   286,   449,    -1,    -1,   290,
     291,    -1,    -1,   584,   295,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   303,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     311,   312,   313,    -1,    -1,    -1,    -1,    -1,   319,   320,
      -1,    -1,    -1,    -1,   325,   488,   489,   328,    -1,    -1,
      -1,   332,   333,    -1,    -1,    -1,    -1,    -1,   501,   630,
      -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   644,   645,   646,   647,   648,   649,   650,
     361,   652,   653,    -1,    -1,    -1,    -1,    -1,   369,    -1,
      -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,   669,    -1,
     543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   399,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,   408,   409,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,   582,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   594,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,   607,    -1,    -1,    -1,    -1,    -1,
      -1,   614,    -1,    -1,   617,   456,    -1,    -1,    -1,    -1,
      -1,    -1,   625,    -1,    -1,    -1,   467,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   498,   499,    -1,
      -1,    -1,   503,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,
     521,   522,   523,   524,    -1,    -1,    -1,   528,    -1,    -1,
      -1,   532,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     551,    -1,   553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   564,    -1,   566,    -1,    -1,   569,    -1,
      -1,    -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,    -1,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
     601,    -1,    -1,   604,    -1,    -1,    -1,    -1,   609,    -1,
      -1,   612,   613,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   627,    -1,    -1,    -1,
       6,     7,     8,   634,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   657,   658,   659,   660,
     661,   662,   663,    39,    -1,   666,    -1,   668,    -1,   670,
      -1,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,    -1,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
      -1,     6,     7,     8,    -1,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,   114,   115,    -1,     6,     7,     8,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    97,    98,    99,   100,   101,   102,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,
     376,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,
     396,   397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,
      97,    98,    99,   100,   101,   102,   392,    -1,    -1,    -1,
     396,   397,    -1,    -1,    -1,    -1,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   480,    -1,   257,    -1,   434,    -1,
      -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,   396,   397,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   434,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,   397,     6,     7,     8,   562,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
     462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,   254,   480,   434,
     257,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,
      -1,   392,    -1,    -1,    -1,   396,   397,   462,    -1,    -1,
      -1,    -1,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     562,    -1,   628,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,   462,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,   480,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,
      -1,    39,    -1,    -1,    -1,    -1,    -1,   562,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,   628,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    97,
      98,    99,   100,   101,   102,    39,    -1,    -1,    -1,    -1,
     447,   562,    -1,   628,    -1,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,    -1,    -1,
      -1,   254,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,     7,     8,   480,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,   628,    -1,   113,
     114,   115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,   376,    -1,    -1,   254,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,
      -1,    -1,    -1,   396,    -1,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   628,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,    -1,    -1,   257,   447,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,   480,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,   376,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,
      -1,   257,    -1,    39,   392,    -1,    -1,    -1,   396,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,   113,   114,
     115,    -1,    -1,    -1,    -1,   254,   434,    -1,   257,   562,
      -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,    -1,   447,
      -1,    97,    98,    99,   100,   101,   102,    -1,   392,    -1,
      -1,    -1,   396,    -1,   462,    -1,    -1,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   480,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   113,   114,   115,    -1,   628,    -1,    -1,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,   392,    -1,   462,    -1,
     396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,   480,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,   562,    -1,    -1,    -1,   434,   254,
      -1,    -1,   257,   392,    -1,    -1,    -1,   396,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,   462,    -1,    -1,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,   254,    39,
      -1,   257,    -1,    -1,   480,   434,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   562,    -1,
     628,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,   254,   462,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,   480,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,   376,    -1,    -1,   628,    -1,   562,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   392,    -1,    -1,
      -1,   396,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     376,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   562,    -1,    -1,   392,    -1,    -1,   434,
     396,    -1,    -1,    -1,    -1,    -1,    -1,   254,    -1,    -1,
     257,    -1,   628,    -1,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,    -1,
     392,    -1,    -1,    -1,   396,    -1,    -1,    -1,   434,    -1,
      -1,    -1,    -1,    -1,    -1,   480,    -1,    -1,    -1,    -1,
      -1,   447,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   628,
      -1,    -1,    18,    19,    20,    -1,   462,    -1,    24,    25,
      26,    27,   434,    -1,   254,    -1,    -1,   257,    18,    19,
      20,    21,    22,    -1,   480,    -1,    -1,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    39,
     462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,   254,    -1,    -1,   257,    -1,   562,    -1,   376,
      -1,    18,    19,    20,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,   392,    -1,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,   562,    97,    98,    99,
     100,   101,   102,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,    -1,    69,   113,   114,   115,    -1,   434,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,   376,    18,    19,    20,
     562,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,   462,   396,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   628,   480,    -1,    -1,    -1,    -1,    -1,   195,
      -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,   396,    -1,   628,    -1,    -1,    -1,
      -1,    -1,    18,    19,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,
     480,    -1,   434,    -1,    24,    25,    26,    27,   195,    -1,
      -1,    -1,    22,    -1,   254,   562,    -1,   257,    -1,    -1,
      -1,    -1,    -1,    69,   254,    -1,    -1,   257,    -1,    39,
     462,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,   299,    -1,    -1,    -1,    -1,   480,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,   195,    -1,    -1,    -1,    -1,    -1,
      -1,   628,   562,    -1,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,    -1,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,   113,   114,   115,    -1,    -1,    -1,    -1,
     113,   114,   115,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
     562,    -1,    -1,    -1,    -1,    -1,   376,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   401,   376,    -1,   628,   195,
      -1,    -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,
     416,    -1,   392,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      69,    -1,    -1,    -1,    -1,   195,    -1,   433,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   448,   449,   434,    -1,   628,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,   401,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   462,    -1,    -1,    -1,    -1,    -1,    -1,   416,
      -1,    -1,   462,   489,    -1,    -1,    -1,    -1,    -1,    -1,
     480,   195,    -1,    -1,   254,   501,   433,   257,    -1,   436,
     480,   254,    -1,    69,   257,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     401,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   416,   195,    -1,    -1,    -1,
      -1,   488,   489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   433,    -1,   501,   436,    -1,    -1,    -1,    -1,
      -1,    -1,   562,    -1,    -1,    -1,   582,    -1,   449,    -1,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,   594,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     606,   607,    -1,    -1,    -1,   401,   543,    -1,   614,    -1,
      -1,   617,    -1,    -1,    -1,    -1,   376,    -1,   489,   625,
     416,    -1,    -1,   376,    -1,    -1,    -1,    -1,    -1,   195,
     501,   401,   392,    -1,    -1,    -1,   396,   433,   628,   392,
     436,    -1,    -1,   396,    -1,   582,   416,    -1,   628,    -1,
      -1,    -1,    -1,   449,    -1,    -1,    -1,   594,    -1,    -1,
      -1,    -1,    -1,   433,    -1,    -1,   436,    -1,    -1,   606,
     607,    -1,   543,    -1,   434,    -1,    -1,   614,    -1,   449,
     617,   434,    -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,
      -1,    -1,   488,   489,    -1,    -1,    -1,   401,    -1,    -1,
      -1,    -1,   462,    -1,    -1,   501,   476,    -1,    -1,   462,
      -1,   582,   416,    -1,    -1,    -1,    -1,    -1,    -1,   489,
     480,    -1,    -1,   594,    -1,    -1,    -1,   480,    -1,   433,
      -1,   501,   436,    -1,    -1,   606,   607,    44,    45,    46,
      47,    48,    49,   614,    -1,   449,   617,   543,    -1,    -1,
      -1,    -1,   401,    -1,   625,    -1,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    48,    49,    -1,   416,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   433,   489,   582,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   103,   501,   594,    -1,
     449,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   562,
     606,   607,   582,    -1,    -1,    -1,    -1,    -1,   614,   103,
      -1,   617,    -1,    -1,   594,    -1,    -1,    -1,    -1,   625,
      -1,    -1,    -1,    -1,    -1,   401,   606,   607,    -1,   543,
     489,    -1,    -1,    -1,   614,    -1,    -1,   617,    -1,    -1,
     416,    -1,   501,    -1,    -1,   625,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   433,   628,    -1,
     436,    -1,    -1,    -1,    -1,   628,    -1,    -1,   582,    -1,
      -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,
     594,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   606,   607,    -1,    -1,    -1,    -1,    -1,    -1,
     614,    -1,    -1,   617,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   625,    -1,   489,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   582,    -1,   501,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   606,   607,    -1,
      -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,   617,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   625,   543,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   298,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   594,    -1,
     337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     606,   607,    -1,   350,    -1,    -1,    -1,    -1,   614,    -1,
     334,   617,    -1,   337,    -1,    -1,    -1,    -1,   342,   625,
      -1,    -1,    -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   415,    -1,
      -1,    -1,    -1,    -1,    -1,   422,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   415,    -1,    -1,    -1,    -1,    -1,    -1,   422,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   437,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   495,   496,
      -1,    -1,    -1,    -1,   501,    -1,    -1,    -1,    -1,    -1,
      -1,   485,    -1,    -1,   511,    -1,    -1,    -1,    -1,    -1,
      -1,   495,   496,    -1,    -1,    -1,    -1,   501,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   533,   511,    -1,   536,
     537,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,   536,   537,    -1,    -1,    -1,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   599,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   608,    -1,   610
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    30,    51,    52,    80,   127,   128,   130,   131,   135,
     152,   153,   170,   241,   361,   411,   443,   472,   740,   768,
     769,   821,   992,  1045,  1047,  1048,  1049,  1054,  1056,  1069,
    1070,  1071,  1072,  1073,  1491,    28,    29,   741,   742,   743,
     744,   745,    27,   957,  1510,   360,   539,   553,   578,   626,
    1492,  1492,  1492,  1492,  1492,  1492,  1492,  1492,   957,    25,
     957,  1410,  1074,   770,  1410,   769,  1491,     0,  1046,  1049,
    1054,  1072,  1491,    31,   743,   745,   957,  1494,   595,   957,
    1493,   631,   822,    25,   195,   767,   768,   945,   957,   962,
    1075,  1110,  1111,  1112,  1113,  1114,  1118,   358,   772,   773,
     774,   775,   778,   779,    60,    65,   110,   111,   118,   372,
     399,   470,   563,   643,   651,   740,   746,   917,   991,  1050,
    1051,  1053,  1057,  1058,  1064,  1076,  1097,  1230,  1240,  1491,
     957,  1493,   622,  1113,   247,   463,   464,  1120,    20,   957,
    1117,   625,   773,     5,   771,   358,   957,     5,   797,   799,
     800,   957,  1241,   957,   957,  1231,  1065,   957,   957,  1053,
    1059,   265,   304,   323,   362,   374,   385,   403,   413,   429,
     469,   492,   507,   514,   517,   538,   541,   543,   562,   580,
     823,   824,   825,   828,    25,  1110,  1116,    18,    19,    26,
      64,    76,   104,   197,   294,   327,   362,   374,   412,   428,
     436,   449,   493,   518,   543,   587,   596,   680,   681,   690,
     692,   883,   888,   899,   901,   957,  1110,  1121,  1122,   464,
      14,   820,   775,   527,  1217,   776,   773,   778,    32,    34,
      84,    85,    94,   265,   304,   323,   339,   362,   374,   385,
     403,   413,   429,   469,   492,   507,   514,   517,   538,   541,
     543,   562,   580,   622,   782,   791,   802,   803,   957,   436,
     117,   957,   767,   918,  1098,   957,   830,   541,   780,   806,
     808,   809,   807,   816,   817,   436,   436,   829,   464,   436,
     436,   773,   804,   431,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   690,   436,   764,     9,    18,    19,
      24,    25,    26,    69,   299,   393,   398,   401,   418,   433,
     436,   439,   448,   489,   501,   512,   543,   594,   606,   607,
     614,   625,   857,   865,   866,   867,   868,   869,   870,   871,
     899,   900,   902,   963,  1110,  1220,  1402,   436,   436,   436,
     436,   436,   436,    18,    19,    20,    21,    22,   691,    26,
     436,   526,     5,   432,  1121,    25,    26,   957,   963,    19,
      25,    26,   777,   963,   675,   676,   677,   781,   793,   780,
     794,   806,   807,   436,   436,   792,   464,   436,   436,   804,
     773,   801,   436,    26,   957,   436,  1066,   767,   767,   436,
     957,   436,   463,   786,   631,   371,   459,   475,   518,   558,
     587,   596,   810,   631,   371,   459,   475,   518,   558,   587,
     596,   818,    26,    26,   831,   832,   833,   834,   957,    26,
     789,   790,    26,    26,   625,   672,   949,   957,  1501,   949,
     949,  1501,  1501,   857,    25,    26,    19,    24,    25,    26,
     903,   904,   905,   906,  1501,   857,   397,   857,   857,   857,
     857,   531,  1237,   436,   436,   857,   371,   459,   475,   518,
     558,   587,   596,  1405,  1406,   436,   857,   857,   436,   436,
     872,   436,   436,   436,   436,    26,     6,     7,     8,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    39,    97,    98,    99,   100,   101,   102,   113,
     114,   115,   254,   257,   376,   392,   396,   434,   462,   480,
     562,   628,   763,   858,   873,   875,   876,   877,   878,   879,
     880,   881,    26,   963,   426,   891,   889,   895,   893,  1110,
    1110,   690,   884,   957,  1122,   464,   432,    26,   784,   773,
     786,   773,    26,    26,   772,   789,    26,    26,   625,    63,
     798,  1242,   397,   436,  1232,  1511,  1512,  1513,  1514,  1515,
     919,  1099,  1060,   625,    26,   811,   812,   436,   813,   818,
     819,   813,   436,   814,     5,   397,     5,   397,     5,   288,
       5,   823,   432,     5,     5,   397,   397,   773,   805,   436,
     464,   625,     5,   397,   397,   397,   397,   397,   397,   397,
     397,   595,   904,    19,    26,   595,   397,   397,   397,     5,
     765,   857,   476,  1426,   857,   436,   631,    20,   397,  1426,
      20,  1220,   857,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   857,   857,   857,   857,   857,
     857,   857,   857,   857,   857,   436,   857,   857,   436,  1110,
     857,   857,   857,   857,   397,     5,   720,   721,   722,   857,
     436,  1121,   464,   629,   625,    26,   263,     5,   397,     5,
     397,   288,   432,     5,   397,   397,   805,   957,  1127,  1128,
    1130,  1077,  1127,   366,  1512,  1217,    35,    36,    37,    43,
      50,    59,    71,    72,    74,    88,    95,   106,   107,   108,
     122,   124,   125,   126,   129,   132,   134,   136,   137,   143,
     146,   148,   149,   150,   158,   160,   161,   163,   165,   166,
     169,   173,   174,   175,   177,   178,   182,   183,   184,   186,
     190,   192,   193,   198,   202,   205,   207,   209,   211,   213,
     214,   216,   217,   218,   222,   224,   225,   227,   235,   236,
     248,   251,   252,   255,   256,   259,   260,   268,   269,   270,
     272,   282,   283,   284,   286,   290,   291,   295,   303,   311,
     312,   313,   319,   320,   325,   328,   332,   333,   343,   361,
     369,   375,   406,   408,   409,   417,   456,   467,   474,   498,
     499,   503,   515,   521,   522,   523,   524,   528,   532,   539,
     540,   551,   553,   564,   566,   569,   575,   601,   604,   609,
     612,   613,   627,   634,   657,   658,   659,   660,   661,   662,
     663,   666,   668,   670,   683,   684,   685,   686,   703,   725,
     739,   740,   746,   747,   766,   836,   837,   838,   839,   850,
     851,   852,   853,   854,   855,   856,   908,   912,   943,   964,
     965,   968,   969,   970,   971,   984,   993,  1014,  1015,  1017,
    1021,  1036,  1037,  1041,  1042,  1043,  1044,  1052,  1067,  1080,
    1091,  1092,  1093,  1104,  1107,  1143,  1146,  1148,  1154,  1155,
    1158,  1161,  1164,  1166,  1168,  1171,  1178,  1183,  1187,  1188,
    1189,  1201,  1202,  1205,  1211,  1212,  1213,  1238,  1253,  1254,
    1255,  1256,  1257,  1262,  1268,  1269,  1287,  1290,  1320,  1322,
    1411,  1412,  1443,  1444,  1451,  1462,  1491,  1495,  1500,  1502,
    1504,  1508,  1509,  1516,   740,  1055,  1491,   630,   653,  1100,
    1101,  1127,    20,   397,   431,   787,   810,    26,   815,    26,
      26,    26,   832,   834,   826,   790,    26,   957,   690,    20,
     672,   957,   949,   897,  1406,   897,    26,    26,   595,    24,
      26,   807,   898,   808,   397,   364,   481,   591,  1434,   397,
     397,    26,  1406,   397,   397,   397,   397,   397,   397,   397,
     447,   447,   447,   882,  1426,   447,   882,  1426,   892,   890,
     896,   894,    26,   885,     5,   886,   432,  1121,   797,    20,
     787,   436,    26,    26,   783,    26,   625,   397,     5,  1127,
     397,  1110,  1110,  1110,    25,  1110,  1165,   957,   354,   958,
     959,  1510,   957,   957,  1185,   952,   958,   952,    25,   195,
     957,  1119,  1486,  1487,  1488,   957,  1506,   957,  1264,  1265,
     957,    26,   687,  1110,  1260,   952,  1185,   882,    26,   963,
    1225,  1226,  1225,   857,   864,  1289,   859,   882,   958,  1452,
    1452,   840,  1185,   952,  1258,  1110,   954,   958,   864,  1452,
    1110,  1185,  1110,  1288,  1452,    25,   591,  1094,  1095,  1110,
     952,   952,  1094,   953,   958,   957,  1095,   952,  1452,   952,
     954,  1110,  1141,  1142,   950,   958,   954,   380,   567,   949,
    1016,   957,   748,   955,   958,    25,  1321,  1486,   882,   882,
     958,  1167,   913,   133,   142,   151,   156,   200,   208,   264,
     289,   296,   298,   308,   334,   342,   380,   406,   444,   455,
     554,   555,   556,   567,   670,  1030,  1162,  1163,  1110,   863,
     864,  1177,  1501,  1501,   951,   958,   882,  1165,  1239,  1110,
    1216,    25,  1110,  1446,   864,  1207,  1208,  1209,  1218,  1219,
     864,  1496,   109,   159,   197,   294,   370,   412,   479,   704,
     888,   957,  1110,  1248,   727,   864,   950,  1493,  1081,   864,
     950,    26,  1110,  1038,   950,   864,  1463,   864,  1225,   957,
     966,   967,   954,   966,  1501,   954,   966,  1501,   972,   966,
      25,    26,   390,   492,   963,  1019,  1110,  1129,  1131,    70,
     279,   349,   395,   574,   654,   655,   656,   665,   694,   974,
     976,   978,   980,   982,  1105,  1106,  1109,   340,   351,   404,
     419,   508,  1323,   645,   646,   921,   922,   923,   957,  1102,
     652,  1101,   397,   307,   397,   397,   397,   397,   629,     5,
     397,   397,   432,   436,   631,   397,    26,   595,   631,    18,
      19,    20,    25,    26,    69,   401,   416,   433,   436,   449,
     489,   501,   543,   582,   594,   606,   607,   614,   617,   957,
     963,  1401,  1403,  1433,  1435,  1436,  1438,  1439,  1440,  1487,
    1490,  1237,   397,  1237,  1237,  1237,  1237,  1237,  1237,    25,
      25,    25,   857,   874,   397,    25,   874,   397,   397,   397,
     397,   397,   397,   397,   722,   720,   432,   307,   773,   795,
     796,   397,   397,   629,   397,   957,  1243,  1130,   397,  1233,
      61,    62,    89,    90,    91,   460,   547,   590,  1270,  1271,
    1272,  1275,  1278,  1281,  1282,  1283,  1284,   436,   625,  1488,
    1120,   622,  1159,   625,     8,   544,   593,     5,   397,   432,
      25,   957,  1395,   484,  1186,  1129,   113,   114,   115,   488,
     860,   861,   864,  1110,  1136,  1395,   693,   694,   843,   271,
      92,    93,   631,   465,     5,   624,   631,   623,   623,  1144,
     601,   426,     5,   562,   994,   465,   664,  1498,   664,   390,
     750,  1110,   552,   623,  1149,  1150,  1151,   331,  1319,   862,
     864,   862,     8,   951,    26,   506,   560,   674,   944,  1110,
     944,   944,   944,    25,   182,   309,   315,   316,   317,   335,
     444,   447,   455,   490,   525,   545,   546,   556,   561,   600,
     632,  1034,  1035,   944,   944,   602,  1031,   694,  1031,  1031,
     945,   945,  1031,  1031,   694,     5,   338,   391,     5,   693,
      86,    87,   545,   632,  1022,   667,  1499,   863,   618,   619,
     620,   621,  1215,  1217,   389,  1252,  1217,  1209,     5,   623,
    1210,   864,   436,   436,   436,   436,    25,   723,   957,   436,
    1446,   349,   436,   526,   595,   584,   728,   735,   726,    25,
    1096,  1110,  1203,     8,  1206,    14,   957,  1115,  1123,  1124,
    1126,  1134,  1135,  1179,   167,   349,   550,   583,     5,     6,
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
     674,  1464,  1465,  1466,  1468,   581,     5,   664,   664,   862,
    1129,  1136,  1018,   426,     5,   155,   998,   436,  1110,   862,
     436,    26,    26,    70,  1108,    25,  1110,  1450,  1450,   958,
    1303,  1167,   951,   123,   226,   234,   240,   242,   253,   281,
     297,   302,   314,   321,   476,   483,   505,   510,  1291,  1292,
    1300,  1310,  1311,  1317,  1318,  1324,  1325,  1334,  1353,  1357,
    1422,  1423,  1453,  1454,  1457,  1458,  1470,   924,   925,    96,
     920,   931,   932,   923,  1103,  1511,  1061,   464,   823,   790,
     625,   957,   371,   459,   475,   518,   558,   587,   596,  1407,
     897,   595,    24,    26,   811,  1439,  1439,   371,   459,   475,
     518,   558,   587,   596,  1404,  1408,   476,  1438,   436,   436,
     436,   436,   436,   436,   436,   957,   436,     5,   552,  1362,
    1367,   957,    18,    19,    20,    21,    97,    98,    99,   100,
     101,   102,  1460,   426,     5,   397,   397,   887,   464,     5,
     397,   797,   767,  1078,   767,   162,   301,   378,   436,   481,
     497,  1340,  1352,   436,   957,  1286,    26,   250,   263,   436,
     481,   497,   957,  1267,  1280,  1338,  1339,  1344,  1346,  1348,
     436,   957,  1277,   436,  1267,  1273,     5,    25,   960,  1113,
    1488,  1486,   582,   622,  1160,    20,   957,  1140,  1489,   957,
    1507,  1265,   601,   625,   595,   436,   436,   843,     5,   631,
     436,  1486,    25,   962,  1184,  1184,  1446,  1094,   864,   864,
     864,   946,   947,   436,  1110,  1142,   804,   995,   996,   631,
    1446,  1501,  1499,  1016,  1110,   749,   630,   864,   355,  1153,
     562,  1152,     5,    73,    75,    77,   623,   631,   835,  1129,
     914,    18,    19,   436,  1032,  1034,  1163,   945,   864,   349,
     601,    26,    26,   693,   157,  1214,   223,  1219,  1225,  1497,
     957,    25,   907,   949,  1501,   595,   949,   628,  1110,   708,
     957,   957,   864,   344,   731,   735,   584,   729,   737,    23,
     239,  1083,  1087,   487,   882,   487,  1204,   864,   463,  1120,
     625,     5,  1039,   552,  1180,  1110,  1467,  1469,   194,  1465,
     985,   967,  1501,  1501,   977,   978,   998,   998,    38,    40,
      41,    42,   275,   278,   280,   300,   310,   352,   356,   435,
     997,   999,  1000,  1026,  1110,  1131,   552,   695,    26,   405,
     983,   326,  1445,  1445,   140,   141,   442,   552,   957,  1354,
    1355,  1396,   804,  1395,  1395,  1293,   804,   957,  1455,  1455,
    1434,  1395,  1301,   172,   444,   455,   476,   483,  1327,  1328,
    1329,  1511,  1511,   390,   933,  1110,   647,   648,   926,   927,
     928,   486,   630,   649,   650,   669,   936,   937,  1511,   767,
      26,   788,    20,   957,   397,   436,    24,    26,   631,  1434,
     397,   401,  1461,  1490,   364,   481,   591,  1386,  1438,  1441,
    1386,  1386,  1386,  1386,   625,  1441,  1436,   520,  1363,  1364,
    1365,  1395,   531,  1361,  1368,   336,   519,   530,  1312,  1429,
    1438,  1438,  1438,  1438,  1487,   857,   397,   788,   796,  1244,
     767,  1234,  1342,  1395,  1285,  1352,   436,  1285,   436,   436,
    1279,  1280,   436,   436,    68,   304,   362,   374,   385,   403,
     413,   416,   429,   477,   507,   517,   538,   541,   543,   571,
     580,  1387,  1388,  1389,  1391,  1276,  1277,  1273,  1274,   669,
    1271,   397,   625,  1446,   582,   464,   552,  1505,   688,   689,
     957,   957,   957,  1261,   882,   860,   957,  1259,   622,  1156,
     631,     5,     5,     5,   585,   864,   625,     5,   488,   631,
     630,   168,   171,   275,   278,   751,   754,   755,  1026,   752,
     753,   957,   436,   958,   654,   655,  1157,   864,   957,   957,
     947,   948,   514,  1501,   843,     8,   916,    26,    26,  1033,
    1034,  1110,   541,  1172,    70,   857,  1217,    26,  1110,  1511,
       5,     5,     5,   397,   397,   724,   957,   397,  1446,   720,
     436,   436,   736,   732,   365,   730,   864,   344,   733,   737,
     602,  1028,  1088,  1084,   367,  1082,  1083,   862,   631,  1116,
      20,   957,  1125,  1135,    14,   488,  1181,  1182,  1438,  1490,
    1110,  1132,  1133,  1511,   979,   980,   556,   956,   552,  1009,
    1008,  1011,  1010,   949,  1012,   949,  1013,  1007,  1006,  1004,
    1003,  1027,   329,  1000,  1005,  1501,    44,    45,    46,    47,
      48,    49,   103,   337,   350,   415,   422,   461,   485,   495,
     496,   501,   511,   533,   536,   537,   542,   599,   610,   696,
     697,  1024,  1025,     5,    26,  1446,   253,  1110,   476,  1427,
    1428,  1446,  1167,  1421,  1423,   105,   105,   601,  1165,  1356,
    1357,   436,  1335,   154,  1368,  1395,   179,   276,  1459,   625,
     631,  1424,  1471,   346,   355,   380,   383,   401,   506,   560,
     567,   951,  1304,  1309,   436,  1330,   630,     5,   935,  1110,
       5,   552,   929,   930,   644,   928,   934,   957,   934,   938,
     939,   934,   329,   937,  1062,   432,    26,   371,   459,   475,
     518,   558,   587,   596,  1409,  1435,     5,  1408,   397,     5,
    1438,     5,   397,  1438,  1438,  1438,  1438,   957,   397,   436,
    1365,     5,   957,  1400,     9,   299,   436,   448,  1371,  1372,
    1373,  1374,  1375,  1379,  1383,  1385,  1438,   373,  1359,  1369,
     957,  1430,   624,  1386,   336,   432,   466,  1227,  1247,  1079,
     466,  1190,  1221,   436,     5,   397,  1371,   397,   617,   957,
    1341,  1343,  1395,  1398,  1399,  1345,  1398,     5,   397,  1345,
    1371,  1408,  1408,   436,   436,   436,   436,   436,   436,   212,
     405,  1347,  1349,     5,   397,     5,   397,   957,  1489,     8,
    1446,  1121,   864,     5,  1266,  1267,   882,  1068,   625,  1266,
     582,  1446,  1446,   864,   864,   946,   514,   864,  1503,     5,
      20,  1398,   996,  1446,   752,   760,   759,   761,   957,   961,
     762,   961,   196,   755,   758,     5,   998,   625,   864,     8,
     957,   882,   559,  1307,     5,   397,  1110,     5,   330,    25,
    1249,   949,   349,   349,   464,   625,   349,   436,   709,   713,
     706,  1511,  1511,   738,   734,   730,  1029,    25,   956,  1089,
    1110,  1511,   864,   431,   464,   882,     5,   426,     5,   986,
     981,   982,    26,   693,   957,  1511,  1511,  1511,  1511,     5,
    1001,     5,  1002,  1511,  1511,  1511,  1511,  1032,  1511,   956,
      25,    14,    14,     5,   397,    26,  1395,  1434,  1415,   601,
     601,  1292,  1420,  1421,  1357,  1336,  1398,   622,   951,   436,
    1296,   957,  1456,  1455,  1435,    53,    54,    55,    56,    57,
     589,  1474,   864,   864,  1302,   951,  1331,  1398,  1395,  1329,
       5,  1110,   934,  1511,  1511,     5,   941,   942,  1511,  1511,
     940,  1055,   827,   397,  1367,  1408,   631,  1408,   397,  1438,
     397,   397,   397,   397,  1364,  1366,  1364,  1374,   436,  1433,
    1371,  1438,  1433,     6,     7,     9,    10,    12,    13,    14,
      15,    16,    17,   257,   376,   377,   434,   562,   628,   678,
     679,  1382,  1384,  1360,  1437,  1438,   453,  1358,  1370,   273,
    1263,    26,  1313,  1314,  1315,  1398,  1427,  1430,   785,    78,
      79,    81,    82,    83,   181,   189,   223,   232,   261,   262,
     306,   348,   405,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,  1224,  1228,   139,   519,  1229,  1245,  1055,
     164,   180,   181,   189,   223,   232,   261,   306,   348,  1222,
    1223,  1235,  1229,  1343,  1352,   397,  1399,   464,  1397,   397,
       5,   625,     5,   397,  1280,   397,   397,   631,   436,   631,
      26,  1393,  1393,    26,  1393,  1393,    26,  1392,    25,  1401,
    1350,  1351,  1352,  1277,  1273,  1446,     8,   432,   689,     5,
     397,   862,   397,    20,   397,  1446,     5,   864,   572,   279,
     698,   699,   864,   998,  1511,  1511,     5,   756,   464,   625,
       5,   757,  1511,   753,   552,    20,   957,     5,   957,  1147,
     395,   664,   862,  1308,   915,  1034,   673,  1170,   857,     5,
     720,  1110,   705,   687,   957,  1110,   711,   397,   720,   720,
    1511,  1511,  1032,  1086,    25,  1090,  1110,   577,   911,  1121,
     488,   863,  1040,  1182,  1110,  1133,    67,   548,   987,   973,
     974,   625,   949,  1511,   949,  1511,   693,    26,  1110,    26,
    1110,   697,   397,   436,  1447,  1435,  1421,  1421,  1413,     5,
     397,   476,  1432,  1297,  1398,   484,  1294,  1432,   631,  1425,
      18,    19,    69,   433,   436,   449,   488,   489,   501,   543,
     582,   594,   606,   607,   614,   617,   957,  1401,  1433,  1479,
    1480,  1481,  1482,  1483,  1484,  1490,  1479,  1479,  1479,  1398,
    1476,  1478,  1475,  1476,  1477,  1472,   559,  1305,     5,   397,
     631,  1110,   957,  1511,  1511,  1511,  1511,   629,   397,   631,
    1409,   631,     5,   397,   397,  1372,  1373,  1377,  1439,  1377,
     436,  1433,  1377,   436,  1433,  1377,    10,   254,   392,   394,
    1438,     5,  1371,     5,   544,   593,  1316,  1263,   629,  1225,
    1225,  1225,    25,  1225,  1225,  1225,  1225,  1225,  1225,    25,
      25,  1225,  1228,  1110,  1137,  1138,   624,   452,  1191,  1511,
      25,    25,    26,    26,    26,    26,    26,    25,  1110,  1223,
    1191,   397,    26,  1340,  1398,    20,   957,  1398,  1409,    26,
    1409,     5,  1390,  1390,     5,   397,   397,  1390,   397,  1352,
    1446,  1267,  1263,   473,   842,     5,   379,  1446,     5,   436,
     397,   556,  1023,   961,  1511,   690,    20,   957,   961,  1511,
    1501,   864,  1501,  1132,  1511,    26,   956,    25,  1250,  1129,
     432,   720,   710,   714,   397,  1511,   956,   864,   909,   432,
     989,   988,   446,   975,   976,    20,   957,  1448,  1449,   559,
    1431,  1416,  1414,  1398,  1434,   144,  1337,     5,   397,  1295,
    1456,  1431,  1482,  1482,  1481,   436,   436,   436,   436,   436,
     436,   436,   957,   436,     5,   397,    18,    19,    20,    21,
    1460,   397,     5,   397,     5,    14,   154,   531,  1473,  1306,
    1398,   468,  1332,  1333,  1396,   215,  1063,   823,  1409,  1409,
    1364,   447,  1376,  1376,  1380,  1381,  1401,  1490,  1376,  1380,
    1376,  1377,  1438,  1437,  1314,   797,   544,   593,  1139,     5,
    1137,    66,   138,   204,   206,   221,   229,   233,   258,  1192,
    1193,  1246,  1063,  1236,     5,   432,  1397,   397,    26,  1394,
     397,   397,    26,   397,   949,   693,   379,  1446,   864,   700,
     574,  1145,    26,   693,   432,  1023,   397,   245,   693,   397,
     397,   436,   712,   349,   718,   397,   707,  1085,  1511,   464,
     864,  1511,   956,     5,   397,  1132,  1367,  1435,  1398,   436,
    1367,   397,  1461,  1386,  1481,  1485,  1386,  1386,  1386,  1386,
     625,  1485,  1480,  1481,  1481,  1481,  1481,  1476,    14,  1477,
    1480,   951,  1371,  1132,     5,   145,  1326,  1378,  1401,  1442,
       5,   397,   397,  1376,     7,  1138,  1194,  1195,  1110,  1197,
    1110,  1196,  1198,  1193,   244,   244,    26,   631,   397,   841,
    1446,   398,   208,   264,   289,   298,   334,   342,   437,   608,
     697,   701,   702,   436,   625,   693,  1169,  1251,   715,   397,
    1129,   718,   718,  1511,   910,  1121,   581,  1020,  1449,  1429,
    1367,   488,  1298,  1299,  1438,  1429,   397,  1481,     5,   397,
    1481,  1481,  1481,  1481,   957,   397,   436,  1333,  1381,  1438,
    1511,  1511,  1199,  1511,  1200,  1511,  1511,   432,  1409,   352,
     356,   844,   845,   846,  1026,   944,   944,   944,   944,   944,
     944,    25,     5,   397,   864,    20,   957,  1026,  1173,  1174,
    1175,   718,   720,   718,   246,   432,   990,   693,     5,   397,
     292,   293,  1417,   397,  1481,   397,   397,   397,   397,  1479,
    1511,  1511,   848,   847,   243,   846,   849,   702,     5,  1176,
     287,  1175,   716,  1511,  1299,    25,   957,  1418,  1419,   397,
    1511,  1511,  1511,   864,  1511,   397,   987,   625,   625,     5,
     397,   717,   957,   957,  1419,   167,   349,   719,   625,  1129,
     957
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
		"unregister_func(\"%s\",%s%s);\n",
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
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
	reset_constr();
}
    break;

  case 141:
#line 1585 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[-2].str,yyvsp[0].str,atoi(yyvsp[0].str));
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0],_forminit)"); /* FIXME */
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
		}
    break;

  case 353:
#line 2254 "fgl.yacc"
    {
		print_display_array_p1(fgl_add_scope(yyvsp[-6].str,0),yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 354:
#line 2257 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 355:
#line 2265 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 356:
#line 2267 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 357:
#line 2272 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 362:
#line 2284 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 363:
#line 2287 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 364:
#line 2290 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 365:
#line 2293 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 366:
#line 2296 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 367:
#line 2299 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 368:
#line 2306 "fgl.yacc"
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

  case 369:
#line 2324 "fgl.yacc"
    {
		print_dealloc_arr(yyvsp[0].str);
	}
    break;

  case 370:
#line 2330 "fgl.yacc"
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
#line 2354 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 372:
#line 2357 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 373:
#line 2372 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 374:
#line 2374 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2376 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 376:
#line 2378 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2380 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2382 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2383 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 380:
#line 2390 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 381:
#line 2392 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 382:
#line 2396 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 383:
#line 2398 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 384:
#line 2400 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 385:
#line 2402 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 386:
#line 2404 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 387:
#line 2406 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 388:
#line 2408 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 389:
#line 2414 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 390:
#line 2428 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 391:
#line 2431 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 396:
#line 2448 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 399:
#line 2454 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 400:
#line 2458 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 401:
#line 2463 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 405:
#line 2473 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 406:
#line 2474 "fgl.yacc"
    {inc_counter();}
    break;

  case 412:
#line 2480 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_CONCAT);");
}
    break;

  case 413:
#line 2487 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 414:
#line 2487 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 416:
#line 2492 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null(2,0)");}
    break;

  case 417:
#line 2496 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 418:
#line 2502 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 419:
#line 2510 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 420:
#line 2516 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 421:
#line 2525 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 422:
#line 2527 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 423:
#line 2534 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 424:
#line 2542 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 425:
#line 2546 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 426:
#line 2555 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 427:
#line 2560 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 428:
#line 2565 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 429:
#line 2569 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 430:
#line 2571 "fgl.yacc"
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
#line 2581 "fgl.yacc"
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
#line 2595 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 433:
#line 2603 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 434:
#line 2615 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 435:
#line 2621 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 436:
#line 2627 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 439:
#line 2637 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 440:
#line 2643 "fgl.yacc"
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
#line 2715 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 442:
#line 2721 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 443:
#line 2725 "fgl.yacc"
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
#line 2733 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 445:
#line 2733 "fgl.yacc"
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
#line 2749 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 447:
#line 2753 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 448:
#line 2759 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 449:
#line 2762 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 450:
#line 2770 "fgl.yacc"
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
#line 2781 "fgl.yacc"
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
#line 2791 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 453:
#line 2797 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 454:
#line 2807 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 455:
#line 2812 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 456:
#line 2819 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 457:
#line 2822 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 458:
#line 2825 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 459:
#line 2830 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 460:
#line 2837 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 461:
#line 2842 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 462:
#line 2847 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 463:
#line 2852 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 464:
#line 2863 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 465:
#line 2871 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 466:
#line 2879 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 467:
#line 2884 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 468:
#line 2888 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 469:
#line 2893 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 470:
#line 2897 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 471:
#line 2901 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 472:
#line 2907 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 473:
#line 2910 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 474:
#line 2914 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 475:
#line 2918 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 476:
#line 2922 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 477:
#line 2926 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 478:
#line 2930 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 479:
#line 2937 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 480:
#line 2947 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 481:
#line 2952 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 482:
#line 2958 "fgl.yacc"
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
#line 2968 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 484:
#line 2973 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 485:
#line 2976 "fgl.yacc"
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
#line 2990 "fgl.yacc"
    {chk4var=1;}
    break;

  case 487:
#line 2990 "fgl.yacc"
    {chk4var=0;}
    break;

  case 488:
#line 2990 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
}
    break;

  case 489:
#line 2993 "fgl.yacc"
    {chk4var=1;}
    break;

  case 490:
#line 2993 "fgl.yacc"
    {chk4var=0;}
    break;

  case 491:
#line 2993 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 492:
#line 2997 "fgl.yacc"
    {chk4var=1;}
    break;

  case 493:
#line 2997 "fgl.yacc"
    {chk4var=0;}
    break;

  case 494:
#line 2997 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 495:
#line 3001 "fgl.yacc"
    {chk4var=1;}
    break;

  case 496:
#line 3001 "fgl.yacc"
    {chk4var=0;}
    break;

  case 497:
#line 3001 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
	/* consumes and replaces a fgl_expr_c - so we don't need to dec or inc_counter */
}
    break;

  case 498:
#line 3005 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 499:
#line 3011 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 500:
#line 3017 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 501:
#line 3023 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 502:
#line 3029 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_isdynarr_allocated(&%s);",yyvsp[-1].str);
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 503:
#line 3035 "fgl.yacc"
    { 
        char buff[256];
        sprintf(buff,"A4GL_dynarr_extent(&%s,%d);",yyvsp[-3].str,atoi(yyvsp[-1].str));
        yyval.ptr=A4GL_new_expr(buff);
        inc_counter();
}
    break;

  case 504:
#line 3045 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 505:
#line 3046 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 508:
#line 3054 "fgl.yacc"
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

  case 509:
#line 3065 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 510:
#line 3066 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
	inc_counter();
}
    break;

  case 511:
#line 3072 "fgl.yacc"
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

  case 512:
#line 3083 "fgl.yacc"
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

  case 513:
#line 3093 "fgl.yacc"
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

  case 516:
#line 3106 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 517:
#line 3111 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 518:
#line 3118 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 519:
#line 3122 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 520:
#line 3125 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 521:
#line 3128 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 522:
#line 3134 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 523:
#line 3137 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 524:
#line 3140 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 525:
#line 3157 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 526:
#line 3160 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 527:
#line 3166 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 528:
#line 3167 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 529:
#line 3168 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 531:
#line 3173 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 532:
#line 3174 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 533:
#line 3175 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 534:
#line 3176 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 535:
#line 3178 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 536:
#line 3179 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 537:
#line 3180 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 538:
#line 3182 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 539:
#line 3183 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 541:
#line 3189 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 543:
#line 3194 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 544:
#line 3206 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 545:
#line 3210 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 546:
#line 3211 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 547:
#line 3218 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 549:
#line 3235 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 550:
#line 3239 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 551:
#line 3245 "fgl.yacc"
    {
print_foreach_next(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 552:
#line 3249 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end(yyvsp[-6].str);
pop_blockcommand("FOREACH"); 
print_foreach_close(yyvsp[-6].str);
}
    break;

  case 553:
#line 3258 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 554:
#line 3259 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 555:
#line 3271 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 556:
#line 3277 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 557:
#line 3285 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 564:
#line 3302 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 565:
#line 3304 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 566:
#line 3307 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 567:
#line 3309 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3323 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 573:
#line 3325 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 574:
#line 3328 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 575:
#line 3330 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 588:
#line 3361 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 589:
#line 3363 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 590:
#line 3366 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 591:
#line 3368 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 592:
#line 3371 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 593:
#line 3373 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 594:
#line 3376 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 595:
#line 3378 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 596:
#line 3381 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 597:
#line 3383 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 598:
#line 3398 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 599:
#line 3414 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 600:
#line 3415 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 601:
#line 3416 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 602:
#line 3417 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 603:
#line 3418 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 604:
#line 3419 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 605:
#line 3420 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 609:
#line 3428 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 611:
#line 3434 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 612:
#line 3436 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 613:
#line 3437 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 614:
#line 3439 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 615:
#line 3441 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 616:
#line 3443 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 617:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 618:
#line 3447 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 619:
#line 3450 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 620:
#line 3457 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 621:
#line 3459 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 622:
#line 3465 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 623:
#line 3470 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 624:
#line 3475 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 625:
#line 3480 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 626:
#line 3480 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 627:
#line 3483 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 628:
#line 3489 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",downshift(yyvsp[0].str)) ;
			}
    break;

  case 629:
#line 3494 "fgl.yacc"
    {
	strcpy(yyval.str,do_clobbering(clobber,downshift(yyvsp[0].str))) ;
	strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 630:
#line 3498 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 633:
#line 3506 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 634:
#line 3508 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 635:
#line 3510 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 636:
#line 3512 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 637:
#line 3514 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 638:
#line 3516 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 639:
#line 3519 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 641:
#line 3528 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 642:
#line 3590 "fgl.yacc"
    {
	print_goto(yyvsp[0].str);
}
    break;

  case 643:
#line 3603 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 645:
#line 3610 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 646:
#line 3613 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 647:
#line 3619 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 648:
#line 3625 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 649:
#line 3629 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 650:
#line 3633 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 651:
#line 3639 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 652:
#line 3643 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 653:
#line 3647 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 654:
#line 3652 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 655:
#line 3657 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 674:
#line 3698 "fgl.yacc"
    {
		if_print_stack_cnt++;
		if_print_stack[if_print_stack_cnt][0]=0;
		if_print_stack[if_print_stack_cnt][1]=0;
		if_print_section[if_print_stack_cnt]=0;
		print_if_start();
	}
    break;

  case 675:
#line 3705 "fgl.yacc"
    {
		int a;
		if_print_section[if_print_stack_cnt]=1;
	}
    break;

  case 676:
#line 3708 "fgl.yacc"
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

  case 678:
#line 3727 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 680:
#line 3730 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 681:
#line 3732 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 682:
#line 3735 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 683:
#line 3739 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 684:
#line 3742 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 685:
#line 3748 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 686:
#line 3759 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 687:
#line 3760 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 688:
#line 3763 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 690:
#line 3769 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 691:
#line 3773 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 692:
#line 3774 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 695:
#line 3788 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 696:
#line 3790 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 699:
#line 3799 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 700:
#line 3801 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 701:
#line 3805 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 702:
#line 3807 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 703:
#line 3810 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 704:
#line 3812 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 705:
#line 3815 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 706:
#line 3818 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 707:
#line 3821 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 708:
#line 3823 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 709:
#line 3826 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 710:
#line 3828 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 711:
#line 3831 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 712:
#line 3833 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 713:
#line 3836 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_DELETE");
	}
    break;

  case 714:
#line 3838 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 715:
#line 3839 "fgl.yacc"
    {
		print_befaft_field_1("DO_BEFORE_INSERT");
	}
    break;

  case 716:
#line 3841 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 717:
#line 3842 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_DELETE");
	}
    break;

  case 718:
#line 3844 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 719:
#line 3845 "fgl.yacc"
    {
		print_befaft_field_1("DO_AFTER_INSERT");
	}
    break;

  case 720:
#line 3847 "fgl.yacc"
    { print_befaft_field_2(); }
    break;

  case 721:
#line 3887 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 722:
#line 3888 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 723:
#line 3896 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 724:
#line 3897 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 725:
#line 3906 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 726:
#line 3911 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 727:
#line 3916 "fgl.yacc"
    {sprintf(yyval.str,"\"+\"");}
    break;

  case 728:
#line 3917 "fgl.yacc"
    {sprintf(yyval.str,"\"-\"");}
    break;

  case 730:
#line 3922 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 731:
#line 3925 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 732:
#line 3933 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 733:
#line 3938 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str,atoi(yyvsp[0].str));
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 734:
#line 3942 "fgl.yacc"
    {
curr_input_array_attribs.maxcount=0;
curr_input_array_attribs.count=0;
curr_input_array_attribs.allow_insert=1;
curr_input_array_attribs.allow_delete=1;
curr_input_array_attribs.curr_row_display=0;
inp_flags=0;}
    break;

  case 735:
#line 3949 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(fgl_add_scope(yyvsp[-8].str,0),yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str,&curr_input_array_attribs));
}
    break;

  case 736:
#line 3958 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 737:
#line 3964 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 738:
#line 3965 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 739:
#line 3966 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 740:
#line 3967 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 741:
#line 3970 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 743:
#line 3973 "fgl.yacc"
    {
	strcpy(yyval.str,"");
}
    break;

  case 744:
#line 3980 "fgl.yacc"
    { curr_input_array_attribs.curr_row_display=strdup(yyvsp[0].str); }
    break;

  case 745:
#line 3981 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 746:
#line 3982 "fgl.yacc"
    { curr_input_array_attribs.count=strdup(yyvsp[0].str); }
    break;

  case 747:
#line 3983 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 748:
#line 3984 "fgl.yacc"
    { curr_input_array_attribs.maxcount=strdup(yyvsp[0].str); }
    break;

  case 749:
#line 3985 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=1; }
    break;

  case 750:
#line 3986 "fgl.yacc"
    { curr_input_array_attribs.allow_insert=0; }
    break;

  case 751:
#line 3987 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=1; }
    break;

  case 752:
#line 3988 "fgl.yacc"
    { curr_input_array_attribs.allow_delete=0; }
    break;

  case 753:
#line 3993 "fgl.yacc"
    {iskey=1;}
    break;

  case 754:
#line 3993 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 755:
#line 3995 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 756:
#line 3998 "fgl.yacc"
    {iskey=1;}
    break;

  case 757:
#line 3998 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 758:
#line 4000 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 759:
#line 4004 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 760:
#line 4007 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 761:
#line 4008 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 763:
#line 4011 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 769:
#line 4023 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 770:
#line 4024 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 771:
#line 4025 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 772:
#line 4026 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 773:
#line 4027 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 774:
#line 4028 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 775:
#line 4029 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 776:
#line 4030 "fgl.yacc"
    {strcpy(yyval.str,"insert");}
    break;

  case 777:
#line 4031 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 778:
#line 4032 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 779:
#line 4033 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 780:
#line 4034 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 781:
#line 4035 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 782:
#line 4036 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 783:
#line 4040 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 784:
#line 4058 "fgl.yacc"
    {chk4var=1;}
    break;

  case 785:
#line 4058 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 786:
#line 4061 "fgl.yacc"
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

  case 787:
#line 4085 "fgl.yacc"
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

  case 789:
#line 4103 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 790:
#line 4109 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 791:
#line 4115 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 792:
#line 4121 "fgl.yacc"
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

  case 793:
#line 4132 "fgl.yacc"
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

  case 794:
#line 4155 "fgl.yacc"
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

  case 797:
#line 4171 "fgl.yacc"
    {
	}
    break;

  case 804:
#line 4194 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 808:
#line 4202 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 826:
#line 4228 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 827:
#line 4229 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 828:
#line 4237 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 829:
#line 4242 "fgl.yacc"
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

  case 830:
#line 4258 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 831:
#line 4264 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 833:
#line 4279 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 834:
#line 4292 "fgl.yacc"
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

  case 835:
#line 4302 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 836:
#line 4309 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 837:
#line 4316 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 838:
#line 4322 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 839:
#line 4322 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 840:
#line 4327 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=0;
			}
    break;

  case 841:
#line 4333 "fgl.yacc"
    {
					open_db(yyvsp[0].str);
					strcpy(hdr_dbname,yyvsp[0].str);
					lastlineno=yylineno;
					is_schema=1;
			}
    break;

  case 842:
#line 4341 "fgl.yacc"
    {
}
    break;

  case 848:
#line 4353 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 850:
#line 4361 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 851:
#line 4367 "fgl.yacc"
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

  case 852:
#line 4381 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 853:
#line 4385 "fgl.yacc"
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

  case 854:
#line 4398 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 856:
#line 4416 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
        menu_blk[menu_cnt]=get_blk_no();
	do_print_menu_1();
	}
    break;

  case 857:
#line 4424 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 858:
#line 4430 "fgl.yacc"
    {
   print_end_menu_1(menu_blk[menu_cnt]);
   add_continue_blockcommand ("MENU");
print_end_menu_2(menu_blk[menu_cnt]);
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 859:
#line 4441 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(menu_blk[menu_cnt],-2) ;
                  }
    break;

  case 860:
#line 4445 "fgl.yacc"
    {
		do_print_menu_block_end();
	}
    break;

  case 861:
#line 4452 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 862:
#line 4459 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 863:
#line 4465 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_blk[menu_cnt],menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 864:
#line 4470 "fgl.yacc"
    {
		do_print_menu_block_end();
}
    break;

  case 867:
#line 4477 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 868:
#line 4478 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 869:
#line 4480 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 870:
#line 4481 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 871:
#line 4484 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 872:
#line 4485 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 873:
#line 4486 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 874:
#line 4488 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 875:
#line 4493 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 876:
#line 4498 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str,menu_blk[menu_cnt]);
}
    break;

  case 877:
#line 4505 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 881:
#line 4512 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 882:
#line 4514 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 883:
#line 4516 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 884:
#line 4525 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 885:
#line 4531 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 886:
#line 4535 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 889:
#line 4547 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 890:
#line 4552 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 891:
#line 4557 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 892:
#line 4560 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 894:
#line 4572 "fgl.yacc"
    {
		print_message(0,"0",0,message_cnt);
	   }
    break;

  case 895:
#line 4575 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 896:
#line 4578 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str),message_cnt);
	  }
    break;

  case 903:
#line 4594 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
		message_cnt=atoi(yyvsp[0].str);
		}
    break;

  case 904:
#line 4599 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 905:
#line 4599 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 906:
#line 4602 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 907:
#line 4629 "fgl.yacc"
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

  case 909:
#line 4687 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 911:
#line 4694 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 912:
#line 4698 "fgl.yacc"
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

  case 913:
#line 4741 "fgl.yacc"
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

  case 917:
#line 4789 "fgl.yacc"
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

  case 918:
#line 4803 "fgl.yacc"
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

  case 923:
#line 4827 "fgl.yacc"
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

  case 924:
#line 4887 "fgl.yacc"
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

  case 925:
#line 4943 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 926:
#line 4948 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 927:
#line 4956 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 928:
#line 4961 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 929:
#line 4969 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 930:
#line 4975 "fgl.yacc"
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

  case 931:
#line 5008 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 932:
#line 5011 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 933:
#line 5013 "fgl.yacc"
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

  case 934:
#line 5054 "fgl.yacc"
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

  case 939:
#line 5107 "fgl.yacc"
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

  case 940:
#line 5159 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 942:
#line 5166 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 943:
#line 5172 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 944:
#line 5183 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 945:
#line 5190 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 947:
#line 5198 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 948:
#line 5201 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 949:
#line 5202 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 951:
#line 5204 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 952:
#line 5205 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 953:
#line 5208 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 954:
#line 5211 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 955:
#line 5217 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 956:
#line 5220 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 957:
#line 5224 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 958:
#line 5228 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 959:
#line 5235 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 960:
#line 5240 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 961:
#line 5247 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 962:
#line 5250 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 967:
#line 5263 "fgl.yacc"
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

  case 968:
#line 5282 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 969:
#line 5289 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 5296 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 971:
#line 5299 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 972:
#line 5313 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 977:
#line 5330 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 978:
#line 5335 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 979:
#line 5341 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 981:
#line 5348 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 982:
#line 5353 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 983:
#line 5356 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 984:
#line 5357 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 985:
#line 5360 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 986:
#line 5361 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 987:
#line 5364 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 988:
#line 5365 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 989:
#line 5370 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 990:
#line 5377 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 991:
#line 5380 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 992:
#line 5386 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 993:
#line 5388 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 994:
#line 5390 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 995:
#line 5392 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 996:
#line 5395 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 997:
#line 5395 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 998:
#line 5396 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 999:
#line 5401 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1000:
#line 5409 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1001:
#line 5410 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1002:
#line 5415 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1003:
#line 5417 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1004:
#line 5419 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1008:
#line 5436 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1009:
#line 5439 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1010:
#line 5442 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1011:
#line 5445 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1012:
#line 5449 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1013:
#line 5452 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1014:
#line 5455 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1015:
#line 5459 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1016:
#line 5463 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1017:
#line 5467 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1018:
#line 5470 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1019:
#line 5474 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1020:
#line 5477 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1021:
#line 5478 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1022:
#line 5479 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1023:
#line 5482 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1024:
#line 5485 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1025:
#line 5488 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1026:
#line 5491 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1027:
#line 5494 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1028:
#line 5497 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1029:
#line 5500 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1030:
#line 5517 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1033:
#line 5527 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1034:
#line 5533 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
	}
    break;

  case 1035:
#line 5537 "fgl.yacc"
    {
		print_execute_immediate(yyvsp[0].str);
	}
    break;

  case 1037:
#line 5557 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str,atoi(yyvsp[-2].str)) ;
}
    break;

  case 1038:
#line 5562 "fgl.yacc"
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

  case 1039:
#line 5574 "fgl.yacc"
    {sprintf(yyval.str,"0");}
    break;

  case 1040:
#line 5575 "fgl.yacc"
    {sprintf(yyval.str,yyvsp[0].str);}
    break;

  case 1041:
#line 5579 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1042:
#line 5584 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1043:
#line 5585 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1044:
#line 5589 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1048:
#line 5595 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1049:
#line 5597 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1051:
#line 5612 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1052:
#line 5616 "fgl.yacc"
    {
		print_put(yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1053:
#line 5622 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1054:
#line 5623 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);
A4GL_debug("putlist = %s\n",yyval.str);
}
    break;

  case 1055:
#line 5628 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1056:
#line 5629 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1057:
#line 5632 "fgl.yacc"
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

  case 1059:
#line 5658 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","acl_getenv(\"DBPRINT\")",yyvsp[-1].str);
}
    break;

  case 1060:
#line 5663 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1061:
#line 5668 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1062:
#line 5673 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1068:
#line 5695 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1069:
#line 5702 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1070:
#line 5711 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1071:
#line 5717 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1072:
#line 5719 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1076:
#line 5730 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1077:
#line 5731 "fgl.yacc"
    {
rep_struct.lines_in_first_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_first_header=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1078:
#line 5737 "fgl.yacc"
    { push_report_block("TRAILER",'T');
if_print_stack[0][0]=0;
if_print_stack[0][1]=0;
}
    break;

  case 1079:
#line 5741 "fgl.yacc"
    {
rep_struct.lines_in_trailer=if_print_stack[0][0];
pdf_rep_struct.lines_in_trailer=if_print_stack[0][0];
print_rep_ret(0);
}
    break;

  case 1080:
#line 5747 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1081:
#line 5748 "fgl.yacc"
    {
rep_struct.lines_in_header=if_print_stack[0][0];
pdf_rep_struct.lines_in_header=if_print_stack[0][0];
print_rep_ret(0);}
    break;

  case 1082:
#line 5753 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1083:
#line 5754 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1084:
#line 5756 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1085:
#line 5757 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1086:
#line 5758 "fgl.yacc"
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

  case 1087:
#line 5772 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1088:
#line 5774 "fgl.yacc"
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

  case 1089:
#line 5791 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1096:
#line 5803 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1097:
#line 5803 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1098:
#line 5809 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1099:
#line 5809 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1100:
#line 5812 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1101:
#line 5812 "fgl.yacc"
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

  case 1102:
#line 5828 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1103:
#line 5829 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1104:
#line 5830 "fgl.yacc"
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

  case 1105:
#line 5839 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1106:
#line 5851 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1112:
#line 5862 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1113:
#line 5867 "fgl.yacc"
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

  case 1114:
#line 5887 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1115:
#line 5892 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1116:
#line 5898 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1117:
#line 5899 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1118:
#line 5900 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1119:
#line 5904 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1120:
#line 5905 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1121:
#line 5906 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1122:
#line 5907 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1123:
#line 5911 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1124:
#line 5921 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1125:
#line 5923 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1126:
#line 5928 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1127:
#line 5931 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1128:
#line 5936 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1129:
#line 5943 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1130:
#line 5950 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1131:
#line 5957 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1132:
#line 5966 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1133:
#line 5973 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1134:
#line 5980 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1135:
#line 5987 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1136:
#line 5994 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1141:
#line 6007 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1142:
#line 6008 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1143:
#line 6009 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1144:
#line 6010 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1145:
#line 6011 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1146:
#line 6012 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"acl_getenv(\"DBPRINT\")");}
    break;

  case 1147:
#line 6013 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1148:
#line 6014 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1149:
#line 6015 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1150:
#line 6016 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1153:
#line 6022 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1154:
#line 6023 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1155:
#line 6024 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1156:
#line 6025 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1161:
#line 6034 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1162:
#line 6035 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1163:
#line 6036 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1164:
#line 6037 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1165:
#line 6038 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1166:
#line 6039 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1167:
#line 6040 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1168:
#line 6041 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1169:
#line 6043 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1170:
#line 6044 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1171:
#line 6045 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1172:
#line 6046 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1173:
#line 6048 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1174:
#line 6049 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1175:
#line 6050 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1176:
#line 6051 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1180:
#line 6056 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1181:
#line 6057 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1185:
#line 6064 "fgl.yacc"
    {
int a;
set_rep_no_orderby(1);
a=print_bind('O');
print_order_by_type(2,-1);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1186:
#line 6072 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(1,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1187:
#line 6080 "fgl.yacc"
    {
int a;
set_rep_no_orderby(0);
a=print_bind('O');
print_order_by_type(2,a);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1188:
#line 6092 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1189:
#line 6101 "fgl.yacc"
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

  case 1190:
#line 6112 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1191:
#line 6116 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1192:
#line 6120 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1193:
#line 6126 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1194:
#line 6131 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1195:
#line 6139 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1196:
#line 6142 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1197:
#line 6151 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1198:
#line 6162 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1200:
#line 6169 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1201:
#line 6177 "fgl.yacc"
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

  case 1202:
#line 6187 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1203:
#line 6190 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1204:
#line 6194 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1205:
#line 6202 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1206:
#line 6205 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1207:
#line 6211 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1208:
#line 6215 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1209:
#line 6219 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1210:
#line 6223 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1211:
#line 6227 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1212:
#line 6233 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1213:
#line 6234 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1214:
#line 6235 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1215:
#line 6236 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1216:
#line 6241 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1217:
#line 6243 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1218:
#line 6246 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1219:
#line 6250 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1220:
#line 6253 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1221:
#line 6260 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1222:
#line 6265 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1223:
#line 6266 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1224:
#line 6267 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1225:
#line 6272 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1226:
#line 6273 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1227:
#line 6279 "fgl.yacc"
    {insql=1;}
    break;

  case 1228:
#line 6279 "fgl.yacc"
    {insql=0;}
    break;

  case 1229:
#line 6279 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1230:
#line 6284 "fgl.yacc"
    {insql=1;}
    break;

  case 1231:
#line 6284 "fgl.yacc"
    {insql=0;}
    break;

  case 1232:
#line 6284 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1233:
#line 6295 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1234:
#line 6296 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1235:
#line 6302 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1236:
#line 6304 "fgl.yacc"
    {
if (A4GL_isyes(acl_getenv("A4GL_OMIT_NO_LOG"))) {
	strcpy(yyval.str,"");
} else {
	sprintf(yyval.str," %s ",yyvsp[0].str);
}
}
    break;

  case 1238:
#line 6317 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1239:
#line 6321 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1240:
#line 6322 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1242:
#line 6327 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1243:
#line 6330 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1244:
#line 6336 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1245:
#line 6339 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1246:
#line 6347 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1248:
#line 6354 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1249:
#line 6361 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1250:
#line 6364 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1251:
#line 6373 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1252:
#line 6376 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1253:
#line 6379 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1254:
#line 6382 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1255:
#line 6385 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1256:
#line 6388 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1257:
#line 6391 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1258:
#line 6398 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1259:
#line 6401 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1260:
#line 6408 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 6411 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1262:
#line 6417 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 6420 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1264:
#line 6427 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1265:
#line 6430 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1267:
#line 6438 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1269:
#line 6447 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1270:
#line 6450 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1271:
#line 6456 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1272:
#line 6459 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1273:
#line 6465 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 6472 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1275:
#line 6473 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1276:
#line 6477 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1277:
#line 6483 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1278:
#line 6486 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1280:
#line 6494 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1281:
#line 6501 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1282:
#line 6504 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1286:
#line 6522 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1292:
#line 6528 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1293:
#line 6531 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1294:
#line 6534 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1295:
#line 6540 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1297:
#line 6546 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1299:
#line 6557 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1300:
#line 6571 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1301:
#line 6580 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1302:
#line 6580 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1303:
#line 6585 "fgl.yacc"
    {insql=1;}
    break;

  case 1304:
#line 6585 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1305:
#line 6590 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1306:
#line 6593 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1307:
#line 6595 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1309:
#line 6602 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1310:
#line 6606 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1311:
#line 6610 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1312:
#line 6617 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1313:
#line 6620 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1314:
#line 6627 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1315:
#line 6631 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1316:
#line 6635 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1317:
#line 6640 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);doing_declare=1;}
    break;

  case 1318:
#line 6645 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1319:
#line 6649 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1320:
#line 6655 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1321:
#line 6659 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1322:
#line 6665 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1323:
#line 6672 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1324:
#line 6676 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1325:
#line 6681 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1326:
#line 6691 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1327:
#line 6694 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1328:
#line 6696 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1329:
#line 6698 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1330:
#line 6700 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1331:
#line 6702 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1332:
#line 6704 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1333:
#line 6706 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1334:
#line 6712 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1335:
#line 6722 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1336:
#line 6729 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1338:
#line 6735 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1339:
#line 6738 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6745 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1345:
#line 6750 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1346:
#line 6755 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1347:
#line 6762 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1348:
#line 6763 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1349:
#line 6770 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1350:
#line 6781 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1351:
#line 6782 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1352:
#line 6785 "fgl.yacc"
    {insql=1;}
    break;

  case 1353:
#line 6785 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1354:
#line 6790 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1355:
#line 6795 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1357:
#line 6801 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1359:
#line 6805 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1360:
#line 6810 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1361:
#line 6815 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1362:
#line 6819 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1364:
#line 6825 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1365:
#line 6829 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1366:
#line 6837 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1367:
#line 6840 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1368:
#line 6842 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1369:
#line 6847 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1372:
#line 6854 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1376:
#line 6861 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1377:
#line 6864 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6866 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1380:
#line 6872 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1382:
#line 6878 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1385:
#line 6888 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1386:
#line 6893 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1387:
#line 6895 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1389:
#line 6901 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6904 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1392:
#line 6910 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1393:
#line 6918 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6923 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6933 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6939 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1400:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1401:
#line 6947 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6953 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6958 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1405:
#line 6961 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1406:
#line 6964 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1407:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6974 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1409:
#line 6987 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1410:
#line 6992 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1412:
#line 6996 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1413:
#line 6998 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1414:
#line 7005 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1415:
#line 7008 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1416:
#line 7014 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1417:
#line 7018 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1418:
#line 7022 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1419:
#line 7026 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1420:
#line 7029 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1421:
#line 7037 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1422:
#line 7044 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1425:
#line 7053 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1426:
#line 7059 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1427:
#line 7062 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1428:
#line 7073 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1429:
#line 7080 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 7086 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1431:
#line 7089 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1432:
#line 7096 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1433:
#line 7103 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1435:
#line 7110 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1436:
#line 7116 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1437:
#line 7117 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 7118 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1440:
#line 7122 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1442:
#line 7127 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1443:
#line 7134 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1444:
#line 7139 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1445:
#line 7140 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1446:
#line 7143 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1447:
#line 7146 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1448:
#line 7151 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1449:
#line 7152 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1450:
#line 7157 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1451:
#line 7160 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1452:
#line 7166 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1453:
#line 7169 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1455:
#line 7178 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1456:
#line 7184 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1457:
#line 7187 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1458:
#line 7194 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1459:
#line 7195 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1460:
#line 7224 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1461:
#line 7226 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1462:
#line 7230 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1464:
#line 7243 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1465:
#line 7246 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1466:
#line 7249 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1467:
#line 7252 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1469:
#line 7260 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 7263 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1472:
#line 7269 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 7275 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1475:
#line 7278 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1476:
#line 7281 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1477:
#line 7284 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string," ",yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1478:
#line 7287 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1479:
#line 7290 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1480:
#line 7293 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1481:
#line 7296 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1482:
#line 7301 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," ",yyvsp[-3].str," MATCHES ",yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1484:
#line 7308 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1490:
#line 7316 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1491:
#line 7317 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1492:
#line 7322 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1493:
#line 7325 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1494:
#line 7329 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1495:
#line 7335 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1496:
#line 7336 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1497:
#line 7337 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1498:
#line 7338 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1503:
#line 7358 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1504:
#line 7363 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1505:
#line 7364 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1507:
#line 7367 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1511:
#line 7372 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1513:
#line 7375 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 7378 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1519:
#line 7383 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1520:
#line 7385 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1521:
#line 7388 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1522:
#line 7389 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1523:
#line 7396 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1527:
#line 7401 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1531:
#line 7417 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1532:
#line 7418 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1533:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1534:
#line 7423 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1536:
#line 7442 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1537:
#line 7443 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1538:
#line 7444 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1539:
#line 7448 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1540:
#line 7451 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1541:
#line 7457 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1542:
#line 7462 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1543:
#line 7467 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1545:
#line 7478 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1550:
#line 7493 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1551:
#line 7496 "fgl.yacc"
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

  case 1552:
#line 7509 "fgl.yacc"
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

  case 1553:
#line 7524 "fgl.yacc"
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

  case 1554:
#line 7536 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1555:
#line 7538 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1556:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1557:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1558:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1559:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1560:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1561:
#line 7541 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1562:
#line 7542 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1563:
#line 7545 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1564:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1565:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1566:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1567:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1568:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1569:
#line 7550 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1570:
#line 7552 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1571:
#line 7555 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1586:
#line 7564 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1587:
#line 7565 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1588:
#line 7569 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1589:
#line 7577 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1590:
#line 7577 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-4].str,0,0);
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
		doing_declare=0;
	}
    break;

  case 1591:
#line 7583 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1592:
#line 7583 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,0); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1593:
#line 7590 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1594:
#line 7590 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-3].str,0,1); 
		addmap("Declare Cursor",yyvsp[-3].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-5].str);
		doing_declare=0;
	}
    break;

  case 1595:
#line 7596 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1596:
#line 7596 "fgl.yacc"
    {
		print_declare("",yyvsp[-1].sql_string,yyvsp[-5].str,2,1); 
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
		doing_declare=0;
	}
    break;

  case 1597:
#line 7604 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1598:
#line 7605 "fgl.yacc"
    {strcpy(yyval.str," FOR UPDATE");}
    break;

  case 1599:
#line 7606 "fgl.yacc"
    {sprintf(yyval.str," FOR UPDATE OF %s",yyvsp[0].str);}
    break;

  case 1600:
#line 7609 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1601:
#line 7609 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1603:
#line 7613 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1604:
#line 7614 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1605:
#line 7619 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1606:
#line 7622 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1607:
#line 7628 "fgl.yacc"
    {
		start_bind('i',0);
		start_bind('o',0);
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1608:
#line 7633 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1609:
#line 7641 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
	if (strstr(yyvsp[0].str,"FOR UPDATE")) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1610:
#line 7653 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1611:
#line 7654 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1612:
#line 7657 "fgl.yacc"
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

  case 1613:
#line 7672 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("A4GL_push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1614:
#line 7682 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1615:
#line 7685 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1616:
#line 7693 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1617:
#line 7702 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1618:
#line 7705 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1619:
#line 7709 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1620:
#line 7712 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1621:
#line 7713 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1623:
#line 7722 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1624:
#line 7723 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(doing_declare,get_bind_cnt('o')),0 ); 

	}
    break;

  case 1625:
#line 7732 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		//free($<sql_string>4);

	}
    break;

  case 1626:
#line 7741 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1627:
#line 7746 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1628:
#line 7747 "fgl.yacc"
    {strcpy(yyval.str,"ALL ");}
    break;

  case 1629:
#line 7748 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1630:
#line 7749 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
}
    break;

  case 1631:
#line 7756 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1632:
#line 7759 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1633:
#line 7765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1634:
#line 7768 "fgl.yacc"
    {
		if (A4GL_isyes(acl_getenv("A4GL_USE_ALIAS_AS"))) {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," AS ",yyvsp[0].str,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);
		}
	}
    break;

  case 1635:
#line 7778 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1636:
#line 7787 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7790 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1638:
#line 7793 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1639:
#line 7799 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7805 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1641:
#line 7808 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1642:
#line 7811 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1643:
#line 7814 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1644:
#line 7821 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1645:
#line 7823 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].str,0);}
    break;

  case 1646:
#line 7825 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1647:
#line 7827 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1648:
#line 7829 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1649:
#line 7830 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1650:
#line 7831 "fgl.yacc"
    {yyval.sql_string=make_sql_string("1",0);}
    break;

  case 1651:
#line 7832 "fgl.yacc"
    {yyval.sql_string=make_sql_string("0",0);}
    break;

  case 1652:
#line 7833 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1653:
#line 7834 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1654:
#line 7835 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1655:
#line 7837 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVG(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1656:
#line 7839 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1657:
#line 7841 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1658:
#line 7843 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1659:
#line 7845 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1660:
#line 7847 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1661:
#line 7849 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1662:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1663:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1664:
#line 7856 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1665:
#line 7857 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1667:
#line 7867 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1668:
#line 7876 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1669:
#line 7880 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1670:
#line 7887 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1671:
#line 7887 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1673:
#line 7891 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1674:
#line 7896 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1675:
#line 7896 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1677:
#line 7900 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1678:
#line 7904 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1681:
#line 7913 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1682:
#line 7913 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1687:
#line 7932 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1688:
#line 7933 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1691:
#line 7941 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1692:
#line 7947 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1695:
#line 7966 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1696:
#line 7967 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1697:
#line 7968 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1698:
#line 7969 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1699:
#line 7970 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1700:
#line 7971 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1701:
#line 7975 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1702:
#line 7976 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1703:
#line 7977 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);}
    break;

  case 1704:
#line 7981 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1705:
#line 7985 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1707:
#line 7994 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1709:
#line 7999 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1710:
#line 8000 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2031:
#line 8328 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2032:
#line 8328 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
		sql_mode=1;
	}
    break;

  case 2033:
#line 8335 "fgl.yacc"
    {sql_mode=0;}
    break;

  case 2034:
#line 8335 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(doing_declare,get_bind_cnt('o')));
		sql_mode=1;
	}
    break;

  case 2035:
#line 8423 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2036:
#line 8427 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 2037:
#line 8429 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 2038:
#line 8436 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 2039:
#line 8440 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 2040:
#line 8446 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 2041:
#line 8454 "fgl.yacc"
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

  case 2042:
#line 8464 "fgl.yacc"
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

  case 2043:
#line 8474 "fgl.yacc"
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

  case 2044:
#line 8486 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 2045:
#line 8489 "fgl.yacc"
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

  case 2046:
#line 8508 "fgl.yacc"
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

  case 2047:
#line 8534 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2048:
#line 8537 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 2050:
#line 8546 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 2051:
#line 8551 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 2052:
#line 8554 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 2053:
#line 8562 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 2054:
#line 8570 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 2055:
#line 8583 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 2056:
#line 8586 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 2057:
#line 8594 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2058:
#line 8597 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 2059:
#line 8600 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 2060:
#line 8608 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 2061:
#line 8612 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 2062:
#line 8615 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 2063:
#line 8618 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 2064:
#line 8621 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 2065:
#line 8625 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 2066:
#line 8626 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 2067:
#line 8627 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 2068:
#line 8628 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 2069:
#line 8629 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 2070:
#line 8635 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 2071:
#line 8636 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 2072:
#line 8637 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 2073:
#line 8638 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 2074:
#line 8639 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 2075:
#line 8640 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2076:
#line 8641 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2077:
#line 8642 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2078:
#line 8643 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2079:
#line 8644 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 2080:
#line 8645 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2081:
#line 8646 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2082:
#line 8647 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2083:
#line 8648 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].sql_string,")",0);}
    break;

  case 2084:
#line 8652 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 2085:
#line 8658 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 2086:
#line 8659 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 2087:
#line 8672 "fgl.yacc"
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

  case 2088:
#line 8692 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 2092:
#line 8698 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2093:
#line 8699 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2097:
#line 8711 "fgl.yacc"
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

  case 2098:
#line 8737 "fgl.yacc"
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

  case 2099:
#line 8802 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 2100:
#line 8804 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2101:
#line 8806 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 2102:
#line 8807 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 2103:
#line 8812 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 2104:
#line 8817 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2105:
#line 8818 "fgl.yacc"
    {
set_whenever(WHEN_WARNING+WHEN_CONTINUE,0);
}
    break;

  case 2106:
#line 8822 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 2107:
#line 8824 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2108:
#line 8826 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 2109:
#line 8829 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 2110:
#line 8833 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 2111:
#line 8838 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 2112:
#line 8843 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 2113:
#line 8847 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 2115:
#line 8857 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2117:
#line 8872 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 2118:
#line 8875 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 2119:
#line 8879 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 2122:
#line 8898 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 2123:
#line 8899 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 2124:
#line 8902 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 2125:
#line 8903 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2126:
#line 8904 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 2127:
#line 8905 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 2128:
#line 8906 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 2129:
#line 8907 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 2130:
#line 8908 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 2131:
#line 8913 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 2132:
#line 8914 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 2133:
#line 8918 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 2134:
#line 8922 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 2135:
#line 8926 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 2136:
#line 8930 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 2137:
#line 8935 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 2138:
#line 8939 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 2139:
#line 8944 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 2141:
#line 8952 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 2143:
#line 8958 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 2144:
#line 8964 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 2145:
#line 8968 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 2150:
#line 8986 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 2151:
#line 8993 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (A4GL_isyes(acl_getenv("INCLINES")))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 2152:
#line 9002 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 2153:
#line 9002 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 18139 "y.tab.c"

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


#line 9100 "fgl.yacc"

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



