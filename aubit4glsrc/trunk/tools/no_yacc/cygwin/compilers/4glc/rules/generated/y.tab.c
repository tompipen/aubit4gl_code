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
     NAME = 1641,
     UMINUS = 1642,
     COMMA = 1557,
     KW_OR = 1597,
     KW_AND = 1552,
     KW_USING = 1488,
     MATCHES = 1366,
     POWER = 1474,
     LESS_THAN = 1470,
     GREATER_THAN = 1384,
     EQUAL = 1547,
     GREATER_THAN_EQ = 1283,
     LESS_THAN_EQ = 1341,
     NOT_EQUAL = 1415,
     PLUS = 1583,
     MINUS = 1570,
     DIVIDE = 1503,
     MULTIPLY = 1475,
     MOD = 1571,
     COMMAND = 1348,
     NUMBER_VALUE = 1643,
     CHAR_VALUE = 1644,
     INT_VALUE = 1645,
     NAMED_GEN = 1646,
     CLINE = 1647,
     SQLLINE = 1648,
     KW_CSTART = 1649,
     KW_CEND = 1650,
     USER_DTYPE = 1651,
     SQL_TEXT = 1652,
     ALTER_TABLE = 1000,
     XSET_MULTIPLY_EQUAL_OPEN_BRACKET = 1001,
     XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET = 1002,
     XSET_ident_DOT_MULTIPLY_EQUAL = 1003,
     XSET_MULTIPLY_EQUAL = 1004,
     XSET_OPEN_BRACKET = 1005,
     NEWFORMATSHARED = 1006,
     CREATE_DATABASE = 1007,
     IMPORT_LEGACY_FUNCTION = 1008,
     ADD_CONSTRAINT = 1009,
     DROP_CONSTRAINT = 1010,
     AS_STATIC = 1011,
     NOT_FIELD_TOUCHED = 1012,
     LOCAL_FUNCTION = 1013,
     EVERY_ROW = 1014,
     ELIF = 1015,
     DOUBLE_PRECISION = 1016,
     COUNT_MULTIPLY = 1017,
     WAIT_FOR_KEY = 1018,
     AT_TERMINATION_CALL = 1019,
     TERMINATE_REPORT = 1020,
     TO_MAIN_CAPTION = 1021,
     CLEARSTAT = 1022,
     TO_MENUITEM = 1023,
     ID_TO_INT = 1024,
     TO_STATUSBOX = 1025,
     ASCII_HEIGHT_ALL = 1026,
     ASCII_WIDTH_ALL = 1027,
     IMPORT_DATATYPE = 1028,
     UP_BY = 1029,
     PAGE_TRAILER_SIZE = 1030,
     PAGE_HEADER_SIZE = 1031,
     FIRST_PAGE_HEADER_SIZE = 1032,
     BYTES_USE_AS_IMAGE = 1033,
     BYTES_USE_AS_ASCII = 1034,
     DOWN_BY = 1035,
     CLOSE_STATUSBOX = 1036,
     MODIFY_NEXT_SIZE = 1037,
     LOCK_MODE_PAGE = 1038,
     LOCK_MODE_ROW = 1039,
     TO_PIPE = 1040,
     TO_PRINTER = 1041,
     STATUSBOX = 1042,
     CONNECT_TO = 1043,
     FORMHANDLER_INPUT = 1044,
     UNITS_YEAR = 1045,
     UNITS_MONTH = 1046,
     UNITS_DAY = 1047,
     UNITS_HOUR = 1048,
     UNITS_MINUTE = 1049,
     UNITS_SECOND = 1050,
     NO_NEW_LINES = 1051,
     FIELDTOWIDGET = 1052,
     WITH_HOLD = 1053,
     SHOW_MENU = 1054,
     CWIS = 1055,
     CREATE_IDX = 1056,
     FORM_IS_COMPILED = 1057,
     PDF_REPORT = 1058,
     IMPORT_FUNCTION = 1059,
     PROMPT_MANY = 1060,
     POINTS = 1061,
     MM = 1062,
     INCHES = 1063,
     PREPEND = 1064,
     MEMBER_OF = 1065,
     MEMBER_FUNCTION = 1066,
     APPEND = 1067,
     TEMPLATE = 1068,
     END_TEMPLATE = 1069,
     SQLSICS = 1070,
     CREATE_SCHEMA = 1071,
     SQLSIRR = 1072,
     UPDATESTATS_T = 1073,
     SQLSICR = 1074,
     WHENEVER_SQLSUCCESS = 1075,
     WHENEVER_SQLWARNING = 1076,
     START_EXTERN = 1077,
     WHENEVER_ANY_ERROR = 1078,
     WHENEVER_NOT_FOUND = 1079,
     CONTINUE_CONSTRUCT = 1080,
     FOUNCONSTR = 1081,
     SQLSIDR = 1082,
     WHENEVER_SQLERROR = 1083,
     CREATE_TEMP_TABLE = 1084,
     CURRENT_WINDOW_IS = 1085,
     FIRST_PAGE_HEADER = 1086,
     ORDER_EXTERNAL_BY = 1087,
     SCROLL_CURSOR_FOR = 1088,
     SCROLL_CURSOR = 1089,
     SQL_INTERRUPT_OFF = 1090,
     STOP_ALL_EXTERNAL = 1091,
     WITH_CHECK_OPTION = 1092,
     WITH_GRANT_OPTION = 1093,
     SQLSLMNW = 1094,
     ADDCONSTUNIQ = 1095,
     CONTINUE_DISPLAY = 1096,
     CONTINUE_FOREACH = 1097,
     OUTPUT_TO_REPORT = 1098,
     SQL_INTERRUPT_ON = 1099,
     WHENEVER_SUCCESS = 1100,
     WHENEVER_WARNING = 1101,
     WHERE_CURRENT_OF = 1102,
     WITHOUT_DEFAULTS = 1103,
     FOCONSTR = 1104,
     SCALED_BY = 1105,
     CONTINUE_PROMPT = 1106,
     PDF_FUNCTION = 1107,
     DEFER_INTERRUPT = 1108,
     DISPLAY_BY_NAME = 1109,
     NOT_NULL_UNIQUE = 1110,
     SKIP_TO_TOP = 1111,
     TOP_OF_PAGE = 1112,
     SKIP_TO = 1113,
     SKIP_BY = 1114,
     WITHOUT_WAITING = 1115,
     BEFCONSTRUCT = 1116,
     SQLSLMW = 1117,
     WHENEVER_ERROR_CONTINUE = 1118,
     WHENEVER_ERROR = 1119,
     AFTCONSTRUCT = 1120,
     ALL_PRIVILEGES = 1121,
     CLOSE_DATABASE = 1122,
     CONTINUE_INPUT = 1123,
     CONTINUE_WHILE = 1124,
     CREATE_SYNONYM = 1125,
     DROP_TABLE = 1126,
     EXIT_CONSTRUCT = 1127,
     INEXCLUSIVE = 1128,
     REPORT_TO_PRINTER = 1129,
     REPORT_TO_PIPE = 1130,
     SET_SESSION_TO = 1131,
     UPDATESTATS = 1132,
     WITHOUT_HEAD = 1133,
     CLEARSCR = 1134,
     WITH_B_LOG = 1135,
     AUTHORIZATION = 1136,
     BOTTOM_MARGIN = 1137,
     CLOSE_SESSION = 1138,
     CONTINUE_CASE = 1139,
     CONTINUE_MENU = 1140,
     DISPLAY_ARRAY = 1141,
     END_SQL = 1142,
     DOLLAR = 1143,
     END_CONSTRUCT = 1144,
     FIELD_TOUCHED = 1145,
     FINISH_REPORT = 1146,
     INFACC = 1147,
     INPUT_NO_WRAP = 1148,
     LOCKMODEPAGE = 1149,
     SETPMOFF = 1150,
     UNCONSTRAINED = 1151,
     PAGE_TRAILER = 1152,
     SETPMON = 1153,
     BEFGROUP = 1154,
     CLOSE_WINDOW = 1155,
     COMMENT_LINE = 1156,
     CONTINUE_FOR = 1157,
     CREATE_DB = 1158,
     CREATE_TABLE = 1159,
     DEFAULT_NULL = 1160,
     DELETE_USING = 1161,
     DISPLAY_FORM = 1162,
     END_FUNCTION = 1163,
     EXIT_DISPLAY = 1164,
     EXIT_FOREACH = 1165,
     EXIT_PROGRAM = 1166,
     INFCOLS = 1167,
     LOCKMODEROW = 1168,
     ON_EVERY_ROW = 1169,
     OPEN_SESSION = 1170,
     RIGHT_MARGIN = 1171,
     SELECT_USING = 1172,
     START_REPORT = 1173,
     UNLOCK_TABLE = 1174,
     UPDATE_USING = 1175,
     ACL_BUILTIN = 1176,
     AFTGROUP = 1177,
     INFIDX = 1178,
     INFSTAT = 1179,
     LEFT_MARGIN = 1180,
     PAGE_HEADER = 1181,
     ROLLBACK_W = 1182,
     SET_SESSION = 1183,
     SQLSEOFF = 1184,
     WITH_A_LOG = 1185,
     BEFDISP = 1186,
     BEFORE_MENU = 1187,
     CREATE_VIEW = 1188,
     DEFINE_TYPE = 1189,
     DELETE_FROM = 1190,
     END_DISPLAY = 1191,
     END_REPORT = 1192,
     END_FOREACH = 1193,
     END_FOR = 1194,
     END_GLOBALS = 1195,
     EXIT_PROMPT = 1196,
     EXTENT_SIZE = 1197,
     FOREIGN_KEY = 1198,
     HIDE_OPTION = 1199,
     HIDE_WINDOW = 1200,
     INSERT_INTO = 1201,
     IS_NOT_NULL = 1202,
     MOVE_WINDOW = 1203,
     NEXT_OPTION = 1204,
     NOT_MATCHES = 1205,
     ON_LAST_ROW = 1206,
     OPEN_WINDOW = 1207,
     OPEN_STATUSBOX = 1208,
     PAGE_LENGTH = 1209,
     PAGE_WIDTH = 1210,
     PRIMARY_KEY = 1211,
     PROMPT_LINE = 1212,
     RECORD_LIKE = 1213,
     ROLLFORWARD = 1214,
     SETBL = 1215,
     SHOW_OPTION = 1216,
     SHOW_WINDOW = 1217,
     SQLSEON = 1218,
     TO_DATABASE = 1219,
     USE_SESSION = 1220,
     WITH_NO_LOG = 1221,
     AFTDISP = 1222,
     BEFFIELD = 1223,
     INSHARE = 1224,
     UNLOCKTAB = 1225,
     AFTFIELD = 1226,
     ATTRIBUTES = 1227,
     BEFINP = 1228,
     BEGIN_WORK = 1229,
     CLEARWIN = 1230,
     CLOSE_FORM = 1231,
     DEFER_QUIT = 1232,
     DESCENDING = 1233,
     DROP_INDEX = 1234,
     END_PROMPT = 1235,
     END_RECORD = 1236,
     ERROR_LINE = 1237,
     EXIT_INPUT = 1238,
     EXIT_WHILE = 1239,
     FOR_UPDATE_OF = 1240,
     FOR_UPDATE = 1241,
     GET_FLDBUF = 1242,
     INITIALIZE = 1243,
     INPUT_WRAP = 1244,
     LOCK_TABLE = 1245,
     MSG_LINE = 1246,
     NOT_EXISTS = 1247,
     ON_ANY_KEY = 1248,
     REFERENCES = 1249,
     RENCOL = 1250,
     SET_CURSOR = 1251,
     SMALLFLOAT = 1252,
     SQLSUCCESS = 1253,
     TOP_MARGIN = 1254,
     WITH_ARRAY = 1255,
     ACCEPTKEY = 1256,
     ACCEPT = 1257,
     AFTINP = 1258,
     CLEARFORMTODEFAULTS = 1259,
     CLEARFORM = 1260,
     CLEAR_X_FORM = 1261,
     COMMIT_W = 1262,
     NEXTPAGE = 1263,
     PREVPAGE = 1264,
     CTRL_KEY = 1265,
     INFTABS = 1266,
     NEXTFIELD = 1267,
     NEXTFORM = 1268,
     RENTAB = 1269,
     ASCENDING = 1270,
     ASSOCIATE = 1271,
     CHARACTER = 1272,
     CONSTRUCT = 1273,
     DELIMITER = 1274,
     DOWNSHIFT = 1275,
     DROP_VIEW = 1276,
     END_INPUT = 1277,
     END_WHILE = 1278,
     EXCLUSIVE = 1279,
     EXIT_CASE = 1280,
     EXIT_MENU = 1281,
     FORM_LINE = 1282,
     INTERRUPT = 1284,
     INTO_TEMP = 1285,
     INVISIBLE = 1286,
     IN_MEMORY = 1287,
     LINKED_TO = 1288,
     LOAD_FROM = 1289,
     LOCKTAB = 1290,
     MENU_LINE = 1291,
     OPEN_FORM = 1292,
     OTHERWISE = 1293,
     PRECISION = 1294,
     PRIOR = 1295,
     PROCEDURE = 1296,
     REPORT_TO = 1297,
     RETURNING = 1298,
     UNDERLINE = 1299,
     UNLOAD_TO = 1300,
     BEFROW = 1301,
     UNLOAD_T = 1302,
     VARIABLE = 1303,
     ABSOLUTE = 1304,
     AFTROW = 1305,
     BUFFERED = 1306,
     CONSTANT = 1307,
     CONST = 1308,
     CONTINUE = 1309,
     DATABASE = 1310,
     DATETIME = 1311,
     DEFAULTS = 1312,
     DISTINCT = 1313,
     END_CASE = 1314,
     END_MAIN = 1315,
     END_MENU = 1316,
     END_TYPE = 1317,
     EXIT_FOR = 1318,
     EXTERNAL = 1319,
     FRACTION = 1320,
     FUNCTION = 1321,
     GROUP_BY = 1322,
     INTERVAL = 1323,
     KWMESSAGE = 1324,
     NOT_LIKE = 1325,
     NOT_NULL = 1326,
     PASSWORD = 1327,
     PREVIOUS = 1328,
     READONLY = 1329,
     REGISTER = 1330,
     RELATIVE = 1331,
     RESOURCE = 1332,
     SMALLINT = 1333,
     VALIDATE = 1334,
     WHENEVER = 1335,
     WITH_LOG = 1336,
     WORDWRAP = 1337,
     BY_NAME = 1338,
     IN_FILE = 1339,
     IS_NULL = 1340,
     AVERAGE = 1342,
     BETWEEN = 1343,
     CAPTION = 1344,
     CLIPPED = 1345,
     CLOSE_BRACKET = 1346,
     COLUMNS = 1347,
     COMMENT = 1349,
     CONNECT = 1350,
     CURRENT = 1351,
     DBYNAME = 1352,
     DECIMAL = 1353,
     DECLARE = 1354,
     DEFAULT = 1355,
     DISPLAY = 1356,
     ENDCODE = 1357,
     EXECUTE = 1358,
     FOREACH = 1359,
     FOREIGN = 1360,
     GLOBALS = 1361,
     INFIELD = 1362,
     INTEGER = 1363,
     KWWINDOW = 1364,
     MAGENTA = 1365,
     NUMERIC = 1367,
     OPTIONS = 1368,
     PERCENT = 1369,
     PREPARE = 1370,
     PROGRAM = 1371,
     RECOVER = 1372,
     REVERSE = 1373,
     SECTION = 1374,
     SESSION = 1375,
     SYNONYM = 1376,
     THRU = 1377,
     TRAILER = 1378,
     UPSHIFT = 1379,
     VARCHAR = 1380,
     WAITING = 1381,
     CLOSE_SHEV = 1382,
     CLOSE_SQUARE = 1383,
     KW_FALSE = 1385,
     NOT_IN = 1386,
     ONKEY = 1387,
     OPEN_BRACKET = 1388,
     BORDER = 1389,
     BOTTOM = 1390,
     COLUMN = 1391,
     COMMIT = 1392,
     CREATE = 1393,
     CURSOR = 1394,
     DEFINE = 1395,
     DELETE = 1396,
     DOUBLE = 1397,
     END_IF = 1398,
     ESCAPE = 1399,
     EXISTS = 1400,
     EXTEND = 1401,
     EXTENT = 1402,
     FINISH = 1403,
     FORMAT = 1404,
     HAVING = 1405,
     HEADER = 1406,
     INSERT = 1407,
     LOCATE = 1408,
     MARGIN = 1409,
     MEMORY = 1410,
     MINUTE = 1411,
     MODIFY = 1412,
     NORMAL = 1413,
     EQUAL_EQUAL = 1414,
     OPEN_SHEV = 1416,
     OPEN_SQUARE = 1417,
     OPTION = 1418,
     OUTPUT = 1419,
     PROMPT = 1420,
     PUBLIC = 1421,
     RECORD = 1422,
     REPORT = 1423,
     RETURN = 1424,
     REVOKE = 1425,
     SCHEMA = 1426,
     SCROLL_USING = 1427,
     SCROLL = 1428,
     SECOND = 1429,
     SELECT = 1430,
     SERIAL = 1431,
     SETL = 1432,
     SHARED = 1433,
     SPACES = 1434,
     UNIQUE = 1435,
     UNLOCK = 1436,
     UPDATE = 1437,
     VALUES = 1438,
     YELLOW = 1439,
     AFTER = 1440,
     KWLINE = 1441,
     KW_NULL = 1442,
     KW_TRUE = 1443,
     SINGLE_KEY = 1444,
     ALTER = 1445,
     ARRAY = 1446,
     ASCII = 1447,
     AUDIT = 1448,
     BLACK = 1449,
     BLINK = 1450,
     CHECK = 1451,
     CLEAR = 1452,
     CLOSE = 1453,
     CODE_C = 1454,
     COUNT = 1455,
     DEFER = 1456,
     ERROR = 1457,
     EVERY = 1458,
     FETCH = 1459,
     FIRST = 1460,
     FLOAT = 1461,
     FLUSH = 1462,
     FOUND = 1463,
     GRANT = 1464,
     GREEN = 1465,
     GROUP = 1466,
     INDEX = 1467,
     KWFORM = 1468,
     LABEL = 1469,
     LOCAL = 1471,
     MONEY = 1472,
     MONTH = 1473,
     ORDER = 1476,
     OUTER = 1477,
     PAUSE = 1478,
     PRINT_IMAGE = 1479,
     PRINT_FILE = 1480,
     PRINT = 1481,
     RIGHT = 1482,
     DOUBLE_COLON = 1483,
     SEMICOLON = 1484,
     SLEEP = 1485,
     TUPLE = 1486,
     UNION = 1487,
     WHERE = 1489,
     WHILE = 1490,
     WHITE = 1491,
     CCODE = 1492,
     ANSI = 1493,
     BLUE = 1494,
     BOLD = 1495,
     BYTE = 1496,
     FCALL = 1497,
     CASE = 1498,
     CHAR = 1499,
     CYAN = 1500,
     DATE = 1501,
     DESC = 1502,
     DOWN = 1504,
     TAB = 1505,
     DROP = 1506,
     ELSE = 1507,
     EXEC = 1508,
     EXIT = 1509,
     FREE = 1510,
     FROM = 1511,
     GOTO = 1512,
     HELP_FILE = 1513,
     LANG_FILE = 1514,
     HELP = 1515,
     HIDE = 1516,
     HOUR = 1517,
     INTO = 1518,
     LAST = 1519,
     LEFT = 1520,
     LIKE = 1521,
     MAIN = 1522,
     MENU = 1523,
     MODE = 1524,
     NEED = 1525,
     NEXT = 1526,
     NOCR = 1527,
     OPEN = 1528,
     QUIT = 1529,
     REAL = 1530,
     ROWS = 1531,
     SHOW = 1532,
     SIZE = 1533,
     SKIP = 1534,
     SOME = 1535,
     STEP = 1536,
     STOP = 1537,
     TEMP = 1538,
     TEXT = 1539,
     THEN = 1540,
     USER = 1541,
     WAIT = 1542,
     WHEN = 1543,
     WITH = 1544,
     WORK = 1545,
     YEAR = 1546,
     KW_IS = 1548,
     XSET = 1549,
     ADD = 1550,
     ALL = 1551,
     ANY = 1553,
     ASC = 1554,
     AVG = 1555,
     COLON = 1556,
     DAY = 1558,
     DBA = 1559,
     DEC = 1560,
     DIM = 1561,
     FKEY = 1562,
     FOR = 1563,
     KEY = 1564,
     KWNO = 1565,
     LET = 1566,
     LOG = 1567,
     XMAX = 1568,
     XMIN = 1569,
     NOT = 1572,
     PAD = 1573,
     PUT = 1574,
     RED = 1575,
     ROW = 1576,
     RUN = 1577,
     SQL = 1578,
     SUM = 1579,
     TOP = 1580,
     USE = 1581,
     ATSIGN = 1582,
     AS_TIFF = 1584,
     AS_GIF = 1585,
     AS_PNG = 1586,
     AS_JPEG = 1587,
     AS = 1588,
     AT = 1589,
     BY = 1590,
     DOT = 1591,
     GO = 1592,
     IF = 1593,
     IN = 1594,
     OF = 1595,
     ON = 1596,
     TO = 1598,
     UP = 1599,
     FONT_NAME = 1600,
     FONT_SIZE = 1601,
     PAPER_SIZE_IS_LETTER = 1602,
     PAPER_SIZE_IS_LEGAL = 1603,
     PAPER_SIZE_IS_A5 = 1604,
     PAPER_SIZE_IS_A4 = 1605,
     PAPER_SIZE_IS_LETTER_L = 1606,
     PAPER_SIZE_IS_LEGAL_L = 1607,
     PAPER_SIZE_IS_A5_L = 1608,
     PAPER_SIZE_IS_A4_L = 1609,
     FORMHANDLER = 1610,
     END_FORMHANDLER = 1611,
     BEFORE_EVENT = 1612,
     BEFORE_OPEN_FORM = 1613,
     AFTER_EVENT = 1614,
     BEFORE_CLOSE_FORM = 1615,
     BEFORE_ANY = 1616,
     AFTER_ANY = 1617,
     MENUHANDLER = 1618,
     END_MENUHANDLER = 1619,
     BEFORE_SHOW_MENU = 1620,
     DISABLE_PROGRAM = 1621,
     DISABLE_ALL = 1622,
     BUTTONS = 1623,
     CHECK_MENUITEM = 1624,
     DISABLE_FORM = 1625,
     DISABLE_MENUITEMS = 1626,
     DISABLE = 1627,
     ENABLE_FORM = 1628,
     ENABLE_MENUITEMS = 1629,
     ENABLE = 1630,
     KWFIELD = 1631,
     ICON = 1632,
     MESSAGEBOX = 1633,
     TO_DEFAULTS = 1634,
     UNCHECK_MENUITEM = 1635,
     BEFORE = 1636,
     INPUT = 1637,
     END = 1638,
     INT_TO_ID = 1639
   };
#endif
#define NAME 1641
#define UMINUS 1642
#define COMMA 1557
#define KW_OR 1597
#define KW_AND 1552
#define KW_USING 1488
#define MATCHES 1366
#define POWER 1474
#define LESS_THAN 1470
#define GREATER_THAN 1384
#define EQUAL 1547
#define GREATER_THAN_EQ 1283
#define LESS_THAN_EQ 1341
#define NOT_EQUAL 1415
#define PLUS 1583
#define MINUS 1570
#define DIVIDE 1503
#define MULTIPLY 1475
#define MOD 1571
#define COMMAND 1348
#define NUMBER_VALUE 1643
#define CHAR_VALUE 1644
#define INT_VALUE 1645
#define NAMED_GEN 1646
#define CLINE 1647
#define SQLLINE 1648
#define KW_CSTART 1649
#define KW_CEND 1650
#define USER_DTYPE 1651
#define SQL_TEXT 1652
#define ALTER_TABLE 1000
#define XSET_MULTIPLY_EQUAL_OPEN_BRACKET 1001
#define XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET 1002
#define XSET_ident_DOT_MULTIPLY_EQUAL 1003
#define XSET_MULTIPLY_EQUAL 1004
#define XSET_OPEN_BRACKET 1005
#define NEWFORMATSHARED 1006
#define CREATE_DATABASE 1007
#define IMPORT_LEGACY_FUNCTION 1008
#define ADD_CONSTRAINT 1009
#define DROP_CONSTRAINT 1010
#define AS_STATIC 1011
#define NOT_FIELD_TOUCHED 1012
#define LOCAL_FUNCTION 1013
#define EVERY_ROW 1014
#define ELIF 1015
#define DOUBLE_PRECISION 1016
#define COUNT_MULTIPLY 1017
#define WAIT_FOR_KEY 1018
#define AT_TERMINATION_CALL 1019
#define TERMINATE_REPORT 1020
#define TO_MAIN_CAPTION 1021
#define CLEARSTAT 1022
#define TO_MENUITEM 1023
#define ID_TO_INT 1024
#define TO_STATUSBOX 1025
#define ASCII_HEIGHT_ALL 1026
#define ASCII_WIDTH_ALL 1027
#define IMPORT_DATATYPE 1028
#define UP_BY 1029
#define PAGE_TRAILER_SIZE 1030
#define PAGE_HEADER_SIZE 1031
#define FIRST_PAGE_HEADER_SIZE 1032
#define BYTES_USE_AS_IMAGE 1033
#define BYTES_USE_AS_ASCII 1034
#define DOWN_BY 1035
#define CLOSE_STATUSBOX 1036
#define MODIFY_NEXT_SIZE 1037
#define LOCK_MODE_PAGE 1038
#define LOCK_MODE_ROW 1039
#define TO_PIPE 1040
#define TO_PRINTER 1041
#define STATUSBOX 1042
#define CONNECT_TO 1043
#define FORMHANDLER_INPUT 1044
#define UNITS_YEAR 1045
#define UNITS_MONTH 1046
#define UNITS_DAY 1047
#define UNITS_HOUR 1048
#define UNITS_MINUTE 1049
#define UNITS_SECOND 1050
#define NO_NEW_LINES 1051
#define FIELDTOWIDGET 1052
#define WITH_HOLD 1053
#define SHOW_MENU 1054
#define CWIS 1055
#define CREATE_IDX 1056
#define FORM_IS_COMPILED 1057
#define PDF_REPORT 1058
#define IMPORT_FUNCTION 1059
#define PROMPT_MANY 1060
#define POINTS 1061
#define MM 1062
#define INCHES 1063
#define PREPEND 1064
#define MEMBER_OF 1065
#define MEMBER_FUNCTION 1066
#define APPEND 1067
#define TEMPLATE 1068
#define END_TEMPLATE 1069
#define SQLSICS 1070
#define CREATE_SCHEMA 1071
#define SQLSIRR 1072
#define UPDATESTATS_T 1073
#define SQLSICR 1074
#define WHENEVER_SQLSUCCESS 1075
#define WHENEVER_SQLWARNING 1076
#define START_EXTERN 1077
#define WHENEVER_ANY_ERROR 1078
#define WHENEVER_NOT_FOUND 1079
#define CONTINUE_CONSTRUCT 1080
#define FOUNCONSTR 1081
#define SQLSIDR 1082
#define WHENEVER_SQLERROR 1083
#define CREATE_TEMP_TABLE 1084
#define CURRENT_WINDOW_IS 1085
#define FIRST_PAGE_HEADER 1086
#define ORDER_EXTERNAL_BY 1087
#define SCROLL_CURSOR_FOR 1088
#define SCROLL_CURSOR 1089
#define SQL_INTERRUPT_OFF 1090
#define STOP_ALL_EXTERNAL 1091
#define WITH_CHECK_OPTION 1092
#define WITH_GRANT_OPTION 1093
#define SQLSLMNW 1094
#define ADDCONSTUNIQ 1095
#define CONTINUE_DISPLAY 1096
#define CONTINUE_FOREACH 1097
#define OUTPUT_TO_REPORT 1098
#define SQL_INTERRUPT_ON 1099
#define WHENEVER_SUCCESS 1100
#define WHENEVER_WARNING 1101
#define WHERE_CURRENT_OF 1102
#define WITHOUT_DEFAULTS 1103
#define FOCONSTR 1104
#define SCALED_BY 1105
#define CONTINUE_PROMPT 1106
#define PDF_FUNCTION 1107
#define DEFER_INTERRUPT 1108
#define DISPLAY_BY_NAME 1109
#define NOT_NULL_UNIQUE 1110
#define SKIP_TO_TOP 1111
#define TOP_OF_PAGE 1112
#define SKIP_TO 1113
#define SKIP_BY 1114
#define WITHOUT_WAITING 1115
#define BEFCONSTRUCT 1116
#define SQLSLMW 1117
#define WHENEVER_ERROR_CONTINUE 1118
#define WHENEVER_ERROR 1119
#define AFTCONSTRUCT 1120
#define ALL_PRIVILEGES 1121
#define CLOSE_DATABASE 1122
#define CONTINUE_INPUT 1123
#define CONTINUE_WHILE 1124
#define CREATE_SYNONYM 1125
#define DROP_TABLE 1126
#define EXIT_CONSTRUCT 1127
#define INEXCLUSIVE 1128
#define REPORT_TO_PRINTER 1129
#define REPORT_TO_PIPE 1130
#define SET_SESSION_TO 1131
#define UPDATESTATS 1132
#define WITHOUT_HEAD 1133
#define CLEARSCR 1134
#define WITH_B_LOG 1135
#define AUTHORIZATION 1136
#define BOTTOM_MARGIN 1137
#define CLOSE_SESSION 1138
#define CONTINUE_CASE 1139
#define CONTINUE_MENU 1140
#define DISPLAY_ARRAY 1141
#define END_SQL 1142
#define DOLLAR 1143
#define END_CONSTRUCT 1144
#define FIELD_TOUCHED 1145
#define FINISH_REPORT 1146
#define INFACC 1147
#define INPUT_NO_WRAP 1148
#define LOCKMODEPAGE 1149
#define SETPMOFF 1150
#define UNCONSTRAINED 1151
#define PAGE_TRAILER 1152
#define SETPMON 1153
#define BEFGROUP 1154
#define CLOSE_WINDOW 1155
#define COMMENT_LINE 1156
#define CONTINUE_FOR 1157
#define CREATE_DB 1158
#define CREATE_TABLE 1159
#define DEFAULT_NULL 1160
#define DELETE_USING 1161
#define DISPLAY_FORM 1162
#define END_FUNCTION 1163
#define EXIT_DISPLAY 1164
#define EXIT_FOREACH 1165
#define EXIT_PROGRAM 1166
#define INFCOLS 1167
#define LOCKMODEROW 1168
#define ON_EVERY_ROW 1169
#define OPEN_SESSION 1170
#define RIGHT_MARGIN 1171
#define SELECT_USING 1172
#define START_REPORT 1173
#define UNLOCK_TABLE 1174
#define UPDATE_USING 1175
#define ACL_BUILTIN 1176
#define AFTGROUP 1177
#define INFIDX 1178
#define INFSTAT 1179
#define LEFT_MARGIN 1180
#define PAGE_HEADER 1181
#define ROLLBACK_W 1182
#define SET_SESSION 1183
#define SQLSEOFF 1184
#define WITH_A_LOG 1185
#define BEFDISP 1186
#define BEFORE_MENU 1187
#define CREATE_VIEW 1188
#define DEFINE_TYPE 1189
#define DELETE_FROM 1190
#define END_DISPLAY 1191
#define END_REPORT 1192
#define END_FOREACH 1193
#define END_FOR 1194
#define END_GLOBALS 1195
#define EXIT_PROMPT 1196
#define EXTENT_SIZE 1197
#define FOREIGN_KEY 1198
#define HIDE_OPTION 1199
#define HIDE_WINDOW 1200
#define INSERT_INTO 1201
#define IS_NOT_NULL 1202
#define MOVE_WINDOW 1203
#define NEXT_OPTION 1204
#define NOT_MATCHES 1205
#define ON_LAST_ROW 1206
#define OPEN_WINDOW 1207
#define OPEN_STATUSBOX 1208
#define PAGE_LENGTH 1209
#define PAGE_WIDTH 1210
#define PRIMARY_KEY 1211
#define PROMPT_LINE 1212
#define RECORD_LIKE 1213
#define ROLLFORWARD 1214
#define SETBL 1215
#define SHOW_OPTION 1216
#define SHOW_WINDOW 1217
#define SQLSEON 1218
#define TO_DATABASE 1219
#define USE_SESSION 1220
#define WITH_NO_LOG 1221
#define AFTDISP 1222
#define BEFFIELD 1223
#define INSHARE 1224
#define UNLOCKTAB 1225
#define AFTFIELD 1226
#define ATTRIBUTES 1227
#define BEFINP 1228
#define BEGIN_WORK 1229
#define CLEARWIN 1230
#define CLOSE_FORM 1231
#define DEFER_QUIT 1232
#define DESCENDING 1233
#define DROP_INDEX 1234
#define END_PROMPT 1235
#define END_RECORD 1236
#define ERROR_LINE 1237
#define EXIT_INPUT 1238
#define EXIT_WHILE 1239
#define FOR_UPDATE_OF 1240
#define FOR_UPDATE 1241
#define GET_FLDBUF 1242
#define INITIALIZE 1243
#define INPUT_WRAP 1244
#define LOCK_TABLE 1245
#define MSG_LINE 1246
#define NOT_EXISTS 1247
#define ON_ANY_KEY 1248
#define REFERENCES 1249
#define RENCOL 1250
#define SET_CURSOR 1251
#define SMALLFLOAT 1252
#define SQLSUCCESS 1253
#define TOP_MARGIN 1254
#define WITH_ARRAY 1255
#define ACCEPTKEY 1256
#define ACCEPT 1257
#define AFTINP 1258
#define CLEARFORMTODEFAULTS 1259
#define CLEARFORM 1260
#define CLEAR_X_FORM 1261
#define COMMIT_W 1262
#define NEXTPAGE 1263
#define PREVPAGE 1264
#define CTRL_KEY 1265
#define INFTABS 1266
#define NEXTFIELD 1267
#define NEXTFORM 1268
#define RENTAB 1269
#define ASCENDING 1270
#define ASSOCIATE 1271
#define CHARACTER 1272
#define CONSTRUCT 1273
#define DELIMITER 1274
#define DOWNSHIFT 1275
#define DROP_VIEW 1276
#define END_INPUT 1277
#define END_WHILE 1278
#define EXCLUSIVE 1279
#define EXIT_CASE 1280
#define EXIT_MENU 1281
#define FORM_LINE 1282
#define INTERRUPT 1284
#define INTO_TEMP 1285
#define INVISIBLE 1286
#define IN_MEMORY 1287
#define LINKED_TO 1288
#define LOAD_FROM 1289
#define LOCKTAB 1290
#define MENU_LINE 1291
#define OPEN_FORM 1292
#define OTHERWISE 1293
#define PRECISION 1294
#define PRIOR 1295
#define PROCEDURE 1296
#define REPORT_TO 1297
#define RETURNING 1298
#define UNDERLINE 1299
#define UNLOAD_TO 1300
#define BEFROW 1301
#define UNLOAD_T 1302
#define VARIABLE 1303
#define ABSOLUTE 1304
#define AFTROW 1305
#define BUFFERED 1306
#define CONSTANT 1307
#define CONST 1308
#define CONTINUE 1309
#define DATABASE 1310
#define DATETIME 1311
#define DEFAULTS 1312
#define DISTINCT 1313
#define END_CASE 1314
#define END_MAIN 1315
#define END_MENU 1316
#define END_TYPE 1317
#define EXIT_FOR 1318
#define EXTERNAL 1319
#define FRACTION 1320
#define FUNCTION 1321
#define GROUP_BY 1322
#define INTERVAL 1323
#define KWMESSAGE 1324
#define NOT_LIKE 1325
#define NOT_NULL 1326
#define PASSWORD 1327
#define PREVIOUS 1328
#define READONLY 1329
#define REGISTER 1330
#define RELATIVE 1331
#define RESOURCE 1332
#define SMALLINT 1333
#define VALIDATE 1334
#define WHENEVER 1335
#define WITH_LOG 1336
#define WORDWRAP 1337
#define BY_NAME 1338
#define IN_FILE 1339
#define IS_NULL 1340
#define AVERAGE 1342
#define BETWEEN 1343
#define CAPTION 1344
#define CLIPPED 1345
#define CLOSE_BRACKET 1346
#define COLUMNS 1347
#define COMMENT 1349
#define CONNECT 1350
#define CURRENT 1351
#define DBYNAME 1352
#define DECIMAL 1353
#define DECLARE 1354
#define DEFAULT 1355
#define DISPLAY 1356
#define ENDCODE 1357
#define EXECUTE 1358
#define FOREACH 1359
#define FOREIGN 1360
#define GLOBALS 1361
#define INFIELD 1362
#define INTEGER 1363
#define KWWINDOW 1364
#define MAGENTA 1365
#define NUMERIC 1367
#define OPTIONS 1368
#define PERCENT 1369
#define PREPARE 1370
#define PROGRAM 1371
#define RECOVER 1372
#define REVERSE 1373
#define SECTION 1374
#define SESSION 1375
#define SYNONYM 1376
#define THRU 1377
#define TRAILER 1378
#define UPSHIFT 1379
#define VARCHAR 1380
#define WAITING 1381
#define CLOSE_SHEV 1382
#define CLOSE_SQUARE 1383
#define KW_FALSE 1385
#define NOT_IN 1386
#define ONKEY 1387
#define OPEN_BRACKET 1388
#define BORDER 1389
#define BOTTOM 1390
#define COLUMN 1391
#define COMMIT 1392
#define CREATE 1393
#define CURSOR 1394
#define DEFINE 1395
#define DELETE 1396
#define DOUBLE 1397
#define END_IF 1398
#define ESCAPE 1399
#define EXISTS 1400
#define EXTEND 1401
#define EXTENT 1402
#define FINISH 1403
#define FORMAT 1404
#define HAVING 1405
#define HEADER 1406
#define INSERT 1407
#define LOCATE 1408
#define MARGIN 1409
#define MEMORY 1410
#define MINUTE 1411
#define MODIFY 1412
#define NORMAL 1413
#define EQUAL_EQUAL 1414
#define OPEN_SHEV 1416
#define OPEN_SQUARE 1417
#define OPTION 1418
#define OUTPUT 1419
#define PROMPT 1420
#define PUBLIC 1421
#define RECORD 1422
#define REPORT 1423
#define RETURN 1424
#define REVOKE 1425
#define SCHEMA 1426
#define SCROLL_USING 1427
#define SCROLL 1428
#define SECOND 1429
#define SELECT 1430
#define SERIAL 1431
#define SETL 1432
#define SHARED 1433
#define SPACES 1434
#define UNIQUE 1435
#define UNLOCK 1436
#define UPDATE 1437
#define VALUES 1438
#define YELLOW 1439
#define AFTER 1440
#define KWLINE 1441
#define KW_NULL 1442
#define KW_TRUE 1443
#define SINGLE_KEY 1444
#define ALTER 1445
#define ARRAY 1446
#define ASCII 1447
#define AUDIT 1448
#define BLACK 1449
#define BLINK 1450
#define CHECK 1451
#define CLEAR 1452
#define CLOSE 1453
#define CODE_C 1454
#define COUNT 1455
#define DEFER 1456
#define ERROR 1457
#define EVERY 1458
#define FETCH 1459
#define FIRST 1460
#define FLOAT 1461
#define FLUSH 1462
#define FOUND 1463
#define GRANT 1464
#define GREEN 1465
#define GROUP 1466
#define INDEX 1467
#define KWFORM 1468
#define LABEL 1469
#define LOCAL 1471
#define MONEY 1472
#define MONTH 1473
#define ORDER 1476
#define OUTER 1477
#define PAUSE 1478
#define PRINT_IMAGE 1479
#define PRINT_FILE 1480
#define PRINT 1481
#define RIGHT 1482
#define DOUBLE_COLON 1483
#define SEMICOLON 1484
#define SLEEP 1485
#define TUPLE 1486
#define UNION 1487
#define WHERE 1489
#define WHILE 1490
#define WHITE 1491
#define CCODE 1492
#define ANSI 1493
#define BLUE 1494
#define BOLD 1495
#define BYTE 1496
#define FCALL 1497
#define CASE 1498
#define CHAR 1499
#define CYAN 1500
#define DATE 1501
#define DESC 1502
#define DOWN 1504
#define TAB 1505
#define DROP 1506
#define ELSE 1507
#define EXEC 1508
#define EXIT 1509
#define FREE 1510
#define FROM 1511
#define GOTO 1512
#define HELP_FILE 1513
#define LANG_FILE 1514
#define HELP 1515
#define HIDE 1516
#define HOUR 1517
#define INTO 1518
#define LAST 1519
#define LEFT 1520
#define LIKE 1521
#define MAIN 1522
#define MENU 1523
#define MODE 1524
#define NEED 1525
#define NEXT 1526
#define NOCR 1527
#define OPEN 1528
#define QUIT 1529
#define REAL 1530
#define ROWS 1531
#define SHOW 1532
#define SIZE 1533
#define SKIP 1534
#define SOME 1535
#define STEP 1536
#define STOP 1537
#define TEMP 1538
#define TEXT 1539
#define THEN 1540
#define USER 1541
#define WAIT 1542
#define WHEN 1543
#define WITH 1544
#define WORK 1545
#define YEAR 1546
#define KW_IS 1548
#define XSET 1549
#define ADD 1550
#define ALL 1551
#define ANY 1553
#define ASC 1554
#define AVG 1555
#define COLON 1556
#define DAY 1558
#define DBA 1559
#define DEC 1560
#define DIM 1561
#define FKEY 1562
#define FOR 1563
#define KEY 1564
#define KWNO 1565
#define LET 1566
#define LOG 1567
#define XMAX 1568
#define XMIN 1569
#define NOT 1572
#define PAD 1573
#define PUT 1574
#define RED 1575
#define ROW 1576
#define RUN 1577
#define SQL 1578
#define SUM 1579
#define TOP 1580
#define USE 1581
#define ATSIGN 1582
#define AS_TIFF 1584
#define AS_GIF 1585
#define AS_PNG 1586
#define AS_JPEG 1587
#define AS 1588
#define AT 1589
#define BY 1590
#define DOT 1591
#define GO 1592
#define IF 1593
#define IN 1594
#define OF 1595
#define ON 1596
#define TO 1598
#define UP 1599
#define FONT_NAME 1600
#define FONT_SIZE 1601
#define PAPER_SIZE_IS_LETTER 1602
#define PAPER_SIZE_IS_LEGAL 1603
#define PAPER_SIZE_IS_A5 1604
#define PAPER_SIZE_IS_A4 1605
#define PAPER_SIZE_IS_LETTER_L 1606
#define PAPER_SIZE_IS_LEGAL_L 1607
#define PAPER_SIZE_IS_A5_L 1608
#define PAPER_SIZE_IS_A4_L 1609
#define FORMHANDLER 1610
#define END_FORMHANDLER 1611
#define BEFORE_EVENT 1612
#define BEFORE_OPEN_FORM 1613
#define AFTER_EVENT 1614
#define BEFORE_CLOSE_FORM 1615
#define BEFORE_ANY 1616
#define AFTER_ANY 1617
#define MENUHANDLER 1618
#define END_MENUHANDLER 1619
#define BEFORE_SHOW_MENU 1620
#define DISABLE_PROGRAM 1621
#define DISABLE_ALL 1622
#define BUTTONS 1623
#define CHECK_MENUITEM 1624
#define DISABLE_FORM 1625
#define DISABLE_MENUITEMS 1626
#define DISABLE 1627
#define ENABLE_FORM 1628
#define ENABLE_MENUITEMS 1629
#define ENABLE 1630
#define KWFIELD 1631
#define ICON 1632
#define MESSAGEBOX 1633
#define TO_DEFAULTS 1634
#define UNCHECK_MENUITEM 1635
#define BEFORE 1636
#define INPUT 1637
#define END 1638
#define INT_TO_ID 1639




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
int 		in_sql=0;
int 		continue_cmd[]={0,1,1,1,1,1,1,1,1,0};
int 		in_cmd[]={0,0,0,0,0,0,0,0,0,0};
int 		fcall_cnt=0;

struct 		rep_structure rep_struct;
struct 		pdf_rep_structure pdf_rep_struct;
struct 		form_attr form_attrib;
char *		make_sql_string(char *first,...);
void copy_gen (int a, int b);
char *get_namespace (char *s);
void set_yytext (char *s);

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
#line 198 "fgl.yacc"
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
#line 1541 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1553 "y.tab.c"

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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8395

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  655
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  828
/* YYNRULES -- Number of rules. */
#define YYNRULES  1928
/* YYNRULES -- Number of states. */
#define YYNSTATES  3180

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1652

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
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    14,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,    15,   373,   374,   375,   376,   377,   378,    22,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,     9,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,    12,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,    16,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
      11,   497,   498,   499,    10,    20,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,     8,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,    19,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,    13,   569,   570,
     571,   572,     7,   573,   574,   575,   576,     5,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
      18,    21,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   598,   599,    17,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,     6,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
       2,     3,     4,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32
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
      99,   101,   103,   105,   107,   109,   111,   112,   114,   115,
     121,   123,   127,   129,   131,   134,   137,   140,   143,   146,
     149,   152,   155,   159,   160,   168,   177,   184,   186,   193,
     194,   195,   205,   206,   207,   208,   217,   218,   219,   230,
     231,   232,   242,   243,   244,   245,   260,   261,   264,   265,
     268,   270,   271,   273,   275,   279,   281,   283,   285,   287,
     291,   292,   299,   300,   306,   308,   311,   313,   316,   318,
     319,   320,   324,   325,   326,   330,   331,   336,   337,   342,
     345,   348,   351,   353,   356,   359,   363,   365,   367,   369,
     372,   374,   376,   379,   381,   383,   384,   385,   391,   399,
     408,   409,   412,   414,   418,   420,   424,   428,   430,   433,
     434,   439,   440,   445,   446,   450,   451,   455,   456,   460,
     462,   466,   468,   472,   474,   476,   478,   480,   482,   484,
     489,   490,   495,   497,   499,   500,   502,   504,   507,   508,
     509,   515,   517,   519,   521,   525,   526,   529,   534,   539,
     544,   549,   552,   553,   558,   560,   562,   564,   567,   569,
     571,   575,   576,   578,   579,   587,   588,   601,   603,   605,
     607,   609,   611,   617,   621,   623,   625,   626,   631,   632,
     638,   639,   647,   649,   653,   655,   657,   658,   660,   661,
     662,   667,   669,   671,   673,   678,   683,   690,   692,   695,
     697,   699,   701,   703,   708,   715,   717,   722,   729,   731,
     733,   735,   737,   739,   741,   743,   746,   749,   751,   753,
     758,   760,   762,   763,   767,   771,   772,   775,   777,   779,
     781,   783,   785,   787,   790,   791,   794,   795,   799,   800,
     804,   806,   807,   811,   813,   815,   817,   819,   821,   823,
     826,   828,   829,   831,   832,   838,   840,   842,   844,   849,
     854,   861,   863,   865,   867,   869,   874,   881,   883,   888,
     895,   897,   899,   901,   903,   905,   908,   911,   913,   918,
     919,   927,   928,   941,   942,   947,   948,   954,   956,   960,
     963,   965,   969,   971,   972,   975,   978,   980,   983,   989,
     994,   997,  1002,  1008,  1012,  1013,  1014,  1026,  1027,  1030,
    1032,  1033,  1036,  1038,  1041,  1042,  1046,  1047,  1051,  1052,
    1056,  1061,  1067,  1069,  1071,  1073,  1075,  1077,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1106,  1108,  1110,  1112,  1114,  1117,  1119,  1121,  1123,
    1126,  1129,  1131,  1133,  1135,  1137,  1139,  1141,  1143,  1145,
    1147,  1149,  1151,  1154,  1156,  1158,  1160,  1164,  1166,  1170,
    1172,  1176,  1178,  1180,  1182,  1185,  1187,  1189,  1193,  1198,
    1203,  1206,  1209,  1211,  1213,  1215,  1217,  1219,  1223,  1225,
    1228,  1231,  1233,  1234,  1238,  1241,  1244,  1246,  1250,  1255,
    1260,  1266,  1272,  1274,  1276,  1279,  1282,  1287,  1292,  1295,
    1298,  1303,  1308,  1310,  1313,  1316,  1319,  1322,  1325,  1328,
    1331,  1334,  1337,  1340,  1343,  1346,  1349,  1352,  1353,  1354,
    1355,  1362,  1363,  1364,  1373,  1374,  1375,  1382,  1383,  1384,
    1391,  1392,  1393,  1400,  1401,  1402,  1409,  1415,  1421,  1427,
    1435,  1436,  1440,  1442,  1444,  1449,  1454,  1459,  1464,  1469,
    1474,  1476,  1478,  1480,  1482,  1487,  1492,  1495,  1498,  1501,
    1504,  1507,  1509,  1511,  1514,  1516,  1518,  1520,  1523,  1528,
    1535,  1542,  1546,  1552,  1558,  1562,  1564,  1566,  1570,  1572,
    1576,  1577,  1578,  1590,  1591,  1594,  1595,  1596,  1597,  1606,
    1607,  1608,  1619,  1620,  1622,  1623,  1625,  1627,  1630,  1631,
    1635,  1636,  1640,  1641,  1643,  1645,  1648,  1649,  1653,  1654,
    1658,  1662,  1664,  1669,  1673,  1675,  1679,  1681,  1685,  1687,
    1691,  1693,  1696,  1697,  1701,  1702,  1706,  1707,  1712,  1713,
    1718,  1719,  1724,  1727,  1731,  1733,  1737,  1739,  1741,  1743,
    1745,  1747,  1749,  1753,  1755,  1757,  1762,  1769,  1774,  1778,
    1785,  1789,  1796,  1798,  1800,  1802,  1804,  1806,  1808,  1809,
    1812,  1814,  1816,  1818,  1823,  1825,  1827,  1829,  1834,  1838,
    1845,  1849,  1856,  1858,  1860,  1863,  1865,  1867,  1869,  1871,
    1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,  1891,
    1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,
    1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,
    1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,  1949,  1952,
    1955,  1957,  1961,  1963,  1966,  1969,  1972,  1977,  1980,  1983,
    1988,  1989,  1998,  1999,  2001,  2003,  2005,  2006,  2008,  2011,
    2012,  2014,  2017,  2018,  2020,  2023,  2024,  2026,  2030,  2031,
    2034,  2035,  2043,  2044,  2045,  2049,  2050,  2051,  2059,  2065,
    2068,  2071,  2072,  2078,  2083,  2085,  2089,  2093,  2097,  2098,
    2101,  2102,  2104,  2106,  2109,  2110,  2115,  2116,  2121,  2122,
    2126,  2127,  2131,  2132,  2136,  2137,  2141,  2142,  2146,  2147,
    2152,  2153,  2158,  2160,  2164,  2166,  2168,  2170,  2174,  2176,
    2178,  2180,  2184,  2186,  2190,  2193,  2198,  2200,  2202,  2204,
    2205,  2210,  2216,  2223,  2224,  2235,  2239,  2241,  2243,  2246,
    2249,  2250,  2253,  2254,  2258,  2260,  2261,  2265,  2268,  2269,
    2273,  2275,  2279,  2281,  2285,  2286,  2289,  2291,  2293,  2295,
    2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,  2315,
    2317,  2319,  2321,  2323,  2325,  2326,  2327,  2335,  2337,  2339,
    2342,  2345,  2348,  2352,  2357,  2358,  2362,  2363,  2365,  2367,
    2370,  2372,  2374,  2376,  2378,  2379,  2381,  2383,  2386,  2389,
    2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,  2409,
    2411,  2413,  2415,  2416,  2418,  2420,  2422,  2424,  2426,  2427,
    2428,  2429,  2430,  2444,  2446,  2447,  2448,  2455,  2458,  2460,
    2463,  2466,  2468,  2470,  2473,  2475,  2477,  2479,  2480,  2484,
    2487,  2489,  2490,  2491,  2492,  2507,  2508,  2514,  2516,  2517,
    2521,  2522,  2530,  2531,  2537,  2539,  2542,  2543,  2545,  2547,
    2549,  2550,  2552,  2554,  2557,  2560,  2563,  2565,  2567,  2569,
    2571,  2575,  2577,  2579,  2580,  2581,  2589,  2591,  2594,  2595,
    2599,  2600,  2605,  2608,  2609,  2612,  2614,  2616,  2618,  2620,
    2622,  2624,  2626,  2627,  2631,  2632,  2634,  2636,  2638,  2640,
    2643,  2646,  2649,  2655,  2657,  2659,  2661,  2666,  2671,  2673,
    2675,  2677,  2679,  2682,  2685,  2689,  2696,  2698,  2702,  2704,
    2706,  2708,  2712,  2719,  2721,  2723,  2725,  2727,  2730,  2731,
    2733,  2735,  2739,  2741,  2745,  2747,  2751,  2753,  2757,  2759,
    2761,  2763,  2765,  2769,  2771,  2775,  2777,  2781,  2783,  2785,
    2787,  2791,  2794,  2795,  2797,  2799,  2804,  2806,  2810,  2812,
    2816,  2824,  2825,  2833,  2834,  2841,  2845,  2847,  2851,  2853,
    2856,  2862,  2863,  2871,  2872,  2875,  2876,  2878,  2884,  2887,
    2893,  2894,  2900,  2907,  2912,  2913,  2915,  2917,  2922,  2923,
    2926,  2927,  2933,  2938,  2941,  2943,  2947,  2950,  2953,  2956,
    2959,  2962,  2965,  2967,  2970,  2973,  2976,  2979,  2982,  2985,
    2988,  2991,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3012,
    3014,  3016,  3019,  3024,  3026,  3027,  3038,  3044,  3045,  3047,
    3048,  3051,  3053,  3056,  3057,  3061,  3063,  3064,  3069,  3070,
    3073,  3075,  3079,  3081,  3083,  3087,  3092,  3097,  3100,  3102,
    3104,  3106,  3107,  3109,  3117,  3120,  3123,  3126,  3129,  3132,
    3134,  3137,  3138,  3142,  3143,  3147,  3148,  3152,  3153,  3157,
    3158,  3162,  3163,  3168,  3169,  3174,  3176,  3178,  3180,  3182,
    3184,  3186,  3187,  3192,  3193,  3195,  3196,  3201,  3203,  3206,
    3209,  3212,  3213,  3215,  3217,  3220,  3223,  3224,  3227,  3231,
    3235,  3241,  3242,  3245,  3250,  3252,  3254,  3256,  3258,  3260,
    3261,  3263,  3265,  3269,  3272,  3278,  3281,  3287,  3293,  3299,
    3305,  3311,  3317,  3318,  3321,  3323,  3326,  3329,  3332,  3335,
    3338,  3341,  3343,  3346,  3349,  3352,  3355,  3357,  3360,  3363,
    3366,  3369,  3371,  3373,  3375,  3376,  3379,  3382,  3385,  3388,
    3391,  3394,  3397,  3400,  3403,  3405,  3407,  3409,  3411,  3413,
    3415,  3417,  3419,  3422,  3425,  3428,  3431,  3434,  3436,  3438,
    3440,  3441,  3445,  3448,  3449,  3450,  3451,  3452,  3453,  3454,
    3470,  3471,  3474,  3477,  3478,  3480,  3481,  3482,  3483,  3484,
    3485,  3486,  3502,  3505,  3506,  3507,  3508,  3519,  3520,  3522,
    3526,  3530,  3533,  3538,  3542,  3546,  3550,  3552,  3554,  3556,
    3558,  3560,  3562,  3563,  3564,  3572,  3573,  3574,  3583,  3587,
    3590,  3591,  3593,  3595,  3599,  3602,  3605,  3607,  3609,  3613,
    3615,  3617,  3620,  3622,  3626,  3628,  3632,  3634,  3636,  3638,
    3640,  3642,  3644,  3646,  3649,  3654,  3656,  3660,  3662,  3666,
    3669,  3674,  3676,  3680,  3682,  3685,  3690,  3692,  3696,  3698,
    3700,  3702,  3705,  3708,  3713,  3716,  3721,  3723,  3727,  3729,
    3731,  3733,  3736,  3738,  3740,  3742,  3744,  3746,  3749,  3756,
    3763,  3764,  3766,  3767,  3769,  3772,  3774,  3775,  3781,  3782,
    3788,  3790,  3791,  3795,  3797,  3801,  3803,  3807,  3809,  3811,
    3812,  3813,  3819,  3822,  3824,  3825,  3826,  3830,  3831,  3832,
    3836,  3838,  3840,  3842,  3844,  3846,  3848,  3851,  3854,  3859,
    3863,  3867,  3869,  3873,  3876,  3878,  3880,  3881,  3883,  3885,
    3887,  3889,  3890,  3892,  3896,  3898,  3900,  3901,  3905,  3907,
    3909,  3911,  3913,  3915,  3917,  3919,  3921,  3923,  3925,  3927,
    3929,  3937,  3938,  3940,  3942,  3944,  3946,  3950,  3952,  3954,
    3956,  3959,  3960,  3964,  3966,  3970,  3972,  3976,  3978,  3980,
    3987,  3988,  3992,  3994,  3998,  3999,  4001,  4006,  4012,  4015,
    4017,  4019,  4024,  4026,  4030,  4035,  4040,  4042,  4046,  4048,
    4050,  4052,  4055,  4057,  4062,  4063,  4065,  4066,  4068,  4070,
    4073,  4075,  4077,  4079,  4084,  4088,  4090,  4092,  4094,  4097,
    4099,  4101,  4104,  4107,  4109,  4113,  4116,  4119,  4121,  4125,
    4127,  4130,  4135,  4137,  4140,  4142,  4146,  4151,  4152,  4154,
    4155,  4157,  4158,  4160,  4162,  4166,  4168,  4172,  4174,  4177,
    4179,  4183,  4186,  4189,  4190,  4193,  4195,  4197,  4199,  4205,
    4209,  4215,  4219,  4221,  4225,  4227,  4229,  4230,  4232,  4236,
    4240,  4244,  4251,  4256,  4261,  4267,  4269,  4271,  4273,  4275,
    4277,  4279,  4281,  4283,  4285,  4287,  4289,  4290,  4292,  4294,
    4296,  4298,  4300,  4302,  4304,  4309,  4315,  4317,  4323,  4329,
    4331,  4333,  4335,  4340,  4342,  4347,  4349,  4357,  4359,  4361,
    4363,  4368,  4375,  4376,  4379,  4384,  4386,  4388,  4390,  4392,
    4394,  4396,  4398,  4402,  4404,  4406,  4410,  4412,  4413,  4417,
    4423,  4425,  4428,  4431,  4436,  4440,  4442,  4444,  4446,  4448,
    4450,  4452,  4455,  4458,  4459,  4463,  4464,  4468,  4470,  4472,
    4474,  4476,  4478,  4480,  4482,  4487,  4489,  4491,  4493,  4495,
    4497,  4499,  4501,  4506,  4508,  4510,  4512,  4514,  4516,  4518,
    4520,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,  4538,
    4542,  4543,  4552,  4553,  4563,  4564,  4572,  4573,  4583,  4584,
    4586,  4589,  4591,  4595,  4597,  4601,  4607,  4609,  4611,  4613,
    4615,  4618,  4619,  4620,  4629,  4635,  4637,  4639,  4646,  4647,
    4651,  4653,  4657,  4662,  4664,  4665,  4668,  4673,  4680,  4681,
    4683,  4685,  4687,  4689,  4693,  4695,  4698,  4701,  4703,  4705,
    4708,  4711,  4713,  4715,  4717,  4720,  4725,  4729,  4732,  4736,
    4740,  4744,  4746,  4748,  4750,  4752,  4754,  4756,  4762,  4768,
    4774,  4780,  4786,  4791,  4796,  4800,  4805,  4807,  4811,  4812,
    4814,  4820,  4828,  4834,  4835,  4838,  4840,  4842,  4843,  4847,
    4849,  4853,  4855,  4857,  4859,  4860,  4864,  4866,  4868,  4870,
    4872,  4877,  4884,  4886,  4888,  4891,  4895,  4897,  4899,  4901,
    4903,  4905,  4907,  4909,  4911,  4917,  4923,  4928,  4929,  4934,
    4936,  4939,  4941,  4943,  4945,  4948,  4951,  4952,  4953,  4960,
    4961,  4964,  4967,  4975,  4979,  4983,  4986,  4989,  4992,  4994,
    4998,  5000,  5004,  5006,  5010,  5012,  5016,  5018,  5020,  5022,
    5025,  5028,  5030,  5032,  5035,  5040,  5042,  5044,  5046,  5048,
    5050,  5052,  5056,  5059,  5063,  5067,  5071,  5077,  5083,  5089,
    5095,  5101,  5106,  5111,  5115,  5120,  5122,  5124,  5128,  5130,
    5133,  5135,  5137,  5139,  5143,  5149,  5151,  5153,  5155,  5157,
    5161,  5164,  5167,  5170,  5172,  5175,  5178,  5181,  5184,  5187,
    5189,  5193,  5196,  5198,  5201,  5203,  5206,  5208,  5209,  5210,
    5217,  5218,  5221,  5222,  5224,  5226,  5229,  5232,  5234,  5236,
    5241,  5245,  5247,  5251,  5253,  5256,  5262,  5265,  5268,  5274,
    5275,  5278,  5280,  5282,  5285,  5292,  5299,  5301,  5302,  5304,
    5307,  5309,  5312,  5313,  5316,  5318,  5320,  5322,  5324,  5326,
    5328,  5330,  5332,  5334,  5336,  5338,  5340,  5342,  5344,  5346,
    5348,  5350,  5352,  5354,  5356,  5358,  5360,  5362,  5364,  5366,
    5368,  5370,  5372,  5374,  5376,  5378,  5380,  5382,  5384,  5386,
    5388,  5390,  5392,  5394,  5396,  5398,  5400,  5402,  5404,  5406,
    5408,  5410,  5412,  5414,  5416,  5418,  5420,  5422,  5424,  5426,
    5428,  5430,  5432,  5434,  5436,  5438,  5440,  5442,  5444,  5446,
    5448,  5450,  5452,  5454,  5456,  5458,  5460,  5462,  5464,  5466,
    5468,  5470,  5472,  5474,  5476,  5478,  5480,  5482,  5484
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1014,     0,    -1,   186,    -1,   183,    -1,   110,   660,   412,
     582,   661,    -1,   124,    -1,  1080,    -1,    25,    -1,   662,
      -1,   661,     5,   662,    -1,   924,    -1,   416,   663,   377,
      -1,   663,   664,   663,    -1,    25,    -1,   665,    25,    -1,
    1080,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   667,    -1,    -1,
     260,   416,   668,   669,   377,    -1,   555,   416,    25,     5,
      25,   377,    -1,   670,    -1,   669,     5,   670,    -1,   476,
      -1,   517,    -1,   523,    -1,   492,    -1,   395,    -1,   592,
      -1,   514,    -1,   466,    -1,   402,    -1,   477,    -1,   331,
      -1,   518,    -1,   441,    -1,   318,    -1,   580,    -1,    84,
      -1,    -1,   672,    -1,    -1,   260,   416,   673,   674,   377,
      -1,   675,    -1,   674,     5,   675,    -1,   670,    -1,   417,
      -1,   590,    24,    -1,   189,   911,    -1,   315,   911,    -1,
     270,   911,    -1,   323,   911,    -1,   279,   911,    -1,   245,
     911,    -1,   520,   677,    -1,   856,   330,  1080,    -1,    -1,
     275,   416,  1467,   377,   330,   678,  1099,    -1,    90,   416,
     924,     5,    24,     5,    24,   377,    -1,   392,   416,   916,
     377,   330,  1080,    -1,  1217,    -1,   178,   416,   875,   377,
     330,  1080,    -1,    -1,    -1,  1080,   576,   924,   416,   679,
     693,   377,   680,   691,    -1,    -1,    -1,    -1,   924,   416,
     681,   693,   682,   377,   683,   691,    -1,    -1,    -1,   460,
    1414,   610,  1414,   416,   684,   693,   685,   377,   691,    -1,
      -1,    -1,   924,   507,   924,   416,   686,   693,   687,   377,
     691,    -1,    -1,    -1,    -1,   351,   696,   576,   697,   444,
     660,   412,   416,   688,   693,   689,   377,   690,   692,    -1,
      -1,   330,  1099,    -1,    -1,   330,  1099,    -1,   148,    -1,
      -1,   694,    -1,   695,    -1,   694,     5,   695,    -1,   825,
      -1,    24,    -1,   924,    -1,   924,    -1,   924,   607,   924,
      -1,    -1,   521,   832,   699,   702,   706,   703,    -1,    -1,
     521,   700,   701,   704,   703,    -1,   708,    -1,   701,   708,
      -1,   710,    -1,   702,   710,    -1,   346,    -1,    -1,    -1,
     325,   705,  1477,    -1,    -1,    -1,   325,   707,  1477,    -1,
      -1,   565,   832,   709,  1477,    -1,    -1,   565,   832,   711,
    1477,    -1,   264,   921,    -1,   188,   919,    -1,    69,   919,
      -1,   155,    -1,   171,  1420,    -1,   480,   918,    -1,    29,
     714,    30,    -1,   715,    -1,   717,    -1,   716,    -1,   715,
     716,    -1,    28,    -1,   718,    -1,   717,   718,    -1,    27,
      -1,   379,    -1,    -1,    -1,   306,   721,   723,   722,   724,
      -1,   370,  1080,   612,   725,   965,   992,   666,    -1,  1080,
     612,   725,   965,   533,  1467,   992,   666,    -1,    -1,   727,
     177,    -1,   726,    -1,   725,     5,   726,    -1,   924,    -1,
     924,   607,   924,    -1,   924,   607,    20,    -1,   728,    -1,
     727,   728,    -1,    -1,   256,   734,   729,  1477,    -1,    -1,
     259,   735,   730,  1477,    -1,    -1,   993,   731,  1477,    -1,
      -1,   153,   732,  1477,    -1,    -1,   149,   733,  1477,    -1,
     928,    -1,   734,     5,   928,    -1,   928,    -1,   735,     5,
     928,    -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,   416,   825,   738,   377,    -1,    -1,
       5,   779,   613,   782,    -1,   141,    -1,   265,    -1,    -1,
     741,    -1,   742,    -1,   741,   742,    -1,    -1,    -1,   423,
     743,   745,   744,  1186,    -1,   792,    -1,  1457,    -1,   748,
      -1,   745,     5,   748,    -1,    -1,   747,   924,    -1,   339,
     746,   791,    24,    -1,   339,   746,   791,   924,    -1,   339,
     746,   791,   930,    -1,   339,   746,   791,    25,    -1,   752,
     768,    -1,    -1,   746,   339,   749,   750,    -1,    25,    -1,
      24,    -1,   930,    -1,    18,    25,    -1,   746,    -1,   751,
      -1,   752,     5,   751,    -1,    -1,   522,    -1,    -1,   473,
     444,   760,   412,   755,   611,   768,    -1,    -1,   304,   753,
     757,    25,   758,   288,   444,   759,   412,   756,   611,   768,
      -1,   416,    -1,   443,    -1,   377,    -1,   411,    -1,    25,
      -1,   761,     5,   761,     5,   761,    -1,   761,     5,   761,
      -1,   761,    -1,    25,    -1,    -1,   449,   763,   745,   269,
      -1,    -1,   246,   764,   746,   607,    20,    -1,    -1,   320,
     765,   746,   244,   416,   766,   377,    -1,   767,    -1,   766,
       5,   767,    -1,   746,    -1,   770,    -1,    -1,    44,    -1,
      -1,    -1,   771,   773,   772,   769,    -1,   754,    -1,   762,
      -1,   522,    -1,   522,   416,    25,   377,    -1,   409,   416,
      25,   377,    -1,   409,   416,    25,     5,    25,   377,    -1,
     393,    -1,   604,   746,    -1,   365,    -1,   495,    -1,    75,
      -1,   383,    -1,   383,   416,    25,   377,    -1,   383,   416,
      25,     5,    25,   377,    -1,   498,    -1,   498,   416,    25,
     377,    -1,   498,   416,    25,     5,    25,   377,    -1,   488,
      -1,   285,    -1,   524,    -1,   519,    -1,    66,    -1,    67,
      -1,   561,    -1,   343,   777,    -1,   355,   778,    -1,   774,
      -1,    31,    -1,   543,   775,   607,   776,    -1,   746,    -1,
     746,    -1,    -1,   779,   613,   782,    -1,   787,   613,   790,
      -1,    -1,   780,   781,    -1,   568,    -1,   499,    -1,   577,
      -1,   539,    -1,   439,    -1,   456,    -1,   352,   784,    -1,
      -1,   783,   781,    -1,    -1,   416,   786,   377,    -1,    -1,
     416,    25,   377,    -1,    25,    -1,    -1,   788,   789,   785,
      -1,   568,    -1,   499,    -1,   577,    -1,   539,    -1,   439,
      -1,   456,    -1,   352,   784,    -1,   789,    -1,    -1,    13,
      -1,    -1,   222,   924,   793,   604,   794,    -1,   796,    -1,
     799,    -1,   522,    -1,   522,   416,    25,   377,    -1,   409,
     416,    25,   377,    -1,   409,   416,    25,     5,    25,   377,
      -1,   393,    -1,   365,    -1,   495,    -1,   383,    -1,   383,
     416,    25,   377,    -1,   383,   416,    25,     5,    25,   377,
      -1,   498,    -1,   498,   416,    25,   377,    -1,   498,   416,
      25,     5,    25,   377,    -1,   488,    -1,   285,    -1,   524,
      -1,   519,    -1,   561,    -1,   343,   777,    -1,   355,   778,
      -1,   795,    -1,   543,   775,   607,   776,    -1,    -1,   473,
     444,   760,   412,   797,   611,   794,    -1,    -1,   304,   753,
     757,    25,   758,   288,   444,   759,   412,   798,   611,   794,
      -1,    -1,   449,   800,   802,   269,    -1,    -1,   246,   801,
     924,   607,    20,    -1,   803,    -1,   802,     5,   803,    -1,
     804,   794,    -1,   805,    -1,   804,     5,   805,    -1,   924,
      -1,    -1,   605,   915,    -1,    56,   924,    -1,    54,    -1,
     613,  1467,    -1,   613,   495,   924,   646,  1467,    -1,   613,
     495,   924,   375,    -1,    58,   924,    -1,   142,   850,  1099,
     814,    -1,   386,   850,   830,   806,   814,    -1,   195,   921,
     814,    -1,    -1,    -1,   174,   811,  1106,   613,   924,   607,
      20,   813,   666,   812,   815,    -1,    -1,   454,   916,    -1,
     666,    -1,    -1,   816,   224,    -1,   817,    -1,   816,   817,
      -1,    -1,   337,   818,  1477,    -1,    -1,   333,   819,  1477,
      -1,    -1,   993,   820,  1477,    -1,   484,   850,   831,   666,
      -1,   484,   850,   831,   666,    51,    -1,   272,    -1,   271,
      -1,   198,    -1,   350,    -1,   160,    -1,   197,    -1,   314,
      -1,   313,    -1,   229,    -1,   157,    -1,   156,    -1,   130,
      -1,   190,    -1,   113,    -1,   129,    -1,   173,    -1,   139,
      -1,   199,    -1,   199,   832,    -1,   835,    -1,   834,    -1,
     839,    -1,   867,    -1,   825,   826,    -1,   868,    -1,   870,
      -1,   836,    -1,    18,   825,    -1,    17,   825,    -1,   841,
      -1,   849,    -1,   843,    -1,   461,    -1,   736,    -1,   844,
      -1,   845,    -1,   846,    -1,   847,    -1,   848,    -1,   850,
      -1,   850,   829,    -1,   832,    -1,   469,    -1,   828,    -1,
     829,     5,   828,    -1,   832,    -1,   830,     5,   832,    -1,
     832,    -1,   831,     5,   832,    -1,   825,    -1,    17,    -1,
      18,    -1,   589,   825,    -1,   470,    -1,   413,    -1,   416,
     825,   377,    -1,   428,   416,  1394,   377,    -1,   280,   416,
    1394,   377,    -1,   833,   930,    -1,   833,    25,    -1,    24,
      -1,   930,    -1,    25,    -1,   838,    -1,  1080,    -1,  1080,
     406,  1080,    -1,   837,    -1,   419,   825,    -1,   378,   825,
      -1,  1189,    -1,    -1,   493,   840,  1189,    -1,     7,   825,
      -1,     6,   825,    -1,   825,    -1,   842,     5,   825,    -1,
     610,   416,  1394,   377,    -1,   414,   416,  1394,   377,    -1,
     610,   416,   850,   842,   377,    -1,   414,   416,   850,   842,
     377,    -1,   372,    -1,   235,    -1,     9,   825,    -1,   238,
     825,    -1,     9,   825,   427,    24,    -1,   238,   825,   427,
      24,    -1,   543,   825,    -1,   357,   825,    -1,   543,   825,
     427,    24,    -1,   357,   825,   427,    24,    -1,   376,    -1,
       8,   825,    -1,    17,   825,    -1,    18,   825,    -1,    20,
     825,    -1,    19,   825,    -1,    21,   825,    -1,    10,   825,
      -1,    13,   825,    -1,   442,   825,    -1,    11,   825,    -1,
      12,   825,    -1,    16,   825,    -1,    15,   825,    -1,    14,
     825,    -1,    -1,    -1,    -1,   924,   416,   852,   693,   853,
     377,    -1,    -1,    -1,   924,   507,   924,   416,   854,   693,
     855,   377,    -1,    -1,    -1,   524,   416,   857,   825,   858,
     377,    -1,    -1,    -1,   499,   416,   859,   825,   860,   377,
      -1,    -1,    -1,   577,   416,   861,   825,   862,   377,    -1,
      -1,    -1,   568,   416,   863,   825,   864,   377,    -1,   355,
     416,   871,   377,   866,    -1,   343,   416,    24,   377,   865,
      -1,   343,   416,    25,   377,   865,    -1,   343,   416,    25,
     576,    25,   377,   865,    -1,    -1,  1374,   613,  1375,    -1,
     778,    -1,   856,    -1,   275,   416,  1467,   377,    -1,    85,
     416,   916,   377,    -1,    57,   416,   916,   377,    -1,   392,
     416,   916,   377,    -1,   178,   416,   875,   377,    -1,    45,
     416,   875,   377,    -1,   869,    -1,   851,    -1,  1370,    -1,
     524,    -1,   408,   416,   825,   377,    -1,   308,   416,   825,
     377,    -1,   474,   825,    -1,   429,   737,    -1,   825,    94,
      -1,   825,    95,    -1,   825,    96,    -1,    24,    -1,   872,
      -1,    18,   872,    -1,   874,    -1,   873,    -1,    25,    -1,
      25,    25,    -1,    25,    25,   576,    25,    -1,    25,    25,
     576,    25,   576,    25,    -1,    25,    25,   576,    25,   576,
      23,    -1,    25,   576,    25,    -1,    25,   576,    25,   576,
      25,    -1,    25,   576,    25,   576,    23,    -1,    25,   576,
      23,    -1,    23,    -1,    25,    -1,    25,    18,    25,    -1,
     916,    -1,   875,     5,   916,    -1,    -1,    -1,   582,  1080,
      13,   832,   613,   832,   879,   877,  1477,   878,   227,    -1,
      -1,   558,   832,    -1,    -1,    -1,    -1,   389,   881,   918,
     882,  1275,   883,  1477,   226,    -1,    -1,    -1,   625,   924,
     885,   740,   886,  1024,   888,   887,   893,   626,    -1,    -1,
     898,    -1,    -1,   889,    -1,   890,    -1,   889,   890,    -1,
      -1,   627,   891,  1477,    -1,    -1,   628,   892,  1477,    -1,
      -1,   894,    -1,   895,    -1,   894,   895,    -1,    -1,   629,
     896,  1477,    -1,    -1,   630,   897,  1477,    -1,   899,   903,
     310,    -1,    77,    -1,    77,   900,   533,   901,    -1,    77,
     370,   902,    -1,  1080,    -1,   900,     5,  1080,    -1,   924,
      -1,   901,     5,   924,    -1,  1080,    -1,   902,     5,  1080,
      -1,   904,    -1,   903,   904,    -1,    -1,   631,   905,  1477,
      -1,    -1,   632,   906,  1477,    -1,    -1,   651,   901,   907,
    1477,    -1,    -1,   467,   901,   908,  1477,    -1,    -1,   612,
     901,   909,  1477,    -1,   532,   917,    -1,   541,    18,    25,
      -1,   541,    -1,   487,    17,    25,    -1,   487,    -1,    25,
      -1,  1080,    -1,    24,    -1,   929,    -1,   832,    -1,   913,
       5,   913,    -1,   914,    -1,   924,    -1,   654,   416,   924,
     377,    -1,   924,   607,   654,   416,   924,   377,    -1,   924,
     444,   663,   412,    -1,   924,   607,    20,    -1,   924,   444,
     663,   412,   607,    20,    -1,   924,   607,   924,    -1,   924,
     444,   663,   412,   607,   924,    -1,   925,    -1,   925,    -1,
     925,    -1,   925,    -1,   925,    -1,   925,    -1,    -1,   537,
      25,    -1,  1476,    -1,   926,    -1,  1476,    -1,   335,   416,
     927,   377,    -1,  1083,    -1,    24,    -1,   924,    -1,   924,
     444,   663,   412,    -1,   924,   607,    20,    -1,   924,   444,
     663,   412,   607,    20,    -1,   924,   607,   924,    -1,   924,
     444,   663,   412,   607,   924,    -1,  1080,    -1,    23,    -1,
     607,    25,    -1,   359,    -1,   478,    -1,   479,    -1,   376,
      -1,   480,    -1,   339,    -1,   306,    -1,   482,    -1,   445,
      -1,   523,    -1,   434,    -1,   578,    -1,   382,    -1,   475,
      -1,   468,    -1,   546,    -1,   385,    -1,   344,    -1,   483,
      -1,   307,    -1,   525,    -1,   266,    -1,   580,    -1,   642,
      -1,   526,    -1,   308,    -1,   528,    -1,   390,    -1,   428,
      -1,   568,    -1,   499,    -1,   577,    -1,   461,    -1,   364,
      -1,   379,    -1,   424,    -1,   366,    -1,   427,    -1,   408,
      -1,   373,    -1,   331,    -1,   545,    -1,   524,    -1,   534,
    1459,    -1,   639,   934,    -1,   935,    -1,   934,     5,   935,
      -1,   924,    -1,   650,   934,    -1,   641,   934,    -1,   642,
    1467,    -1,   640,   921,   646,  1467,    -1,   644,   934,    -1,
     645,  1467,    -1,   643,   921,   646,  1467,    -1,    -1,   648,
     940,   830,   945,   947,   949,   941,   943,    -1,    -1,   942,
      -1,   636,    -1,   637,    -1,    -1,   944,    -1,   330,  1080,
      -1,    -1,   946,    -1,   375,   830,    -1,    -1,   948,    -1,
     647,    25,    -1,    -1,   950,    -1,   638,    25,   951,    -1,
      -1,   385,    25,    -1,    -1,   609,   832,   562,   953,  1477,
     954,   426,    -1,    -1,    -1,   529,   955,  1477,    -1,    -1,
      -1,    48,   956,   832,   562,   957,  1477,   954,    -1,    92,
     924,   416,    25,   377,    -1,    41,   924,    -1,    61,   924,
      -1,    -1,   276,  1111,   961,   613,   469,    -1,   276,  1111,
     543,   962,    -1,   963,    -1,   962,     5,   963,    -1,   775,
     607,  1366,    -1,   775,   607,    20,    -1,    -1,   966,   310,
      -1,    -1,   136,    -1,   967,    -1,   966,   967,    -1,    -1,
     256,   981,   968,  1477,    -1,    -1,   259,   982,   969,  1477,
      -1,    -1,   337,   970,  1477,    -1,    -1,   333,   971,  1477,
      -1,    -1,   993,   972,  1477,    -1,    -1,   291,   973,  1477,
      -1,    -1,   261,   974,  1477,    -1,    -1,   651,   979,   975,
    1477,    -1,    -1,   467,   977,   976,  1477,    -1,   978,    -1,
     977,     5,   978,    -1,   435,    -1,   424,    -1,   980,    -1,
     979,     5,   980,    -1,   435,    -1,   424,    -1,   916,    -1,
     981,     5,   916,    -1,   916,    -1,   982,     5,   916,    -1,
     300,   985,    -1,   301,   924,   646,   985,    -1,   548,    -1,
     360,    -1,   916,    -1,    -1,   652,   988,   987,   964,    -1,
     370,  1099,   965,   923,   666,    -1,  1099,   965,   533,  1467,
     923,   666,    -1,    -1,   473,  1106,   965,   533,   924,   607,
      20,   923,   989,   666,    -1,   455,  1467,   991,    -1,   614,
      -1,   526,    -1,    62,    25,    -1,    68,    25,    -1,    -1,
     537,    25,    -1,    -1,   415,   994,  1000,    -1,   281,    -1,
      -1,   583,   996,  1000,    -1,   289,  1002,    -1,    -1,   583,
     999,  1000,    -1,  1002,    -1,   416,  1001,   377,    -1,  1002,
      -1,  1001,     5,  1002,    -1,    -1,  1003,  1004,    -1,   581,
      -1,   298,    -1,   316,    -1,   290,    -1,   471,    -1,   427,
      -1,   614,    -1,   537,    -1,   526,    -1,   451,    -1,   424,
      -1,   527,    -1,   542,    -1,   506,    -1,   296,    -1,   297,
      -1,    24,    -1,   496,    -1,    -1,    -1,   585,  1007,  1104,
    1008,    13,   850,  1009,    -1,   469,    -1,   831,    -1,   205,
    1080,    -1,   194,  1080,    -1,   208,  1080,    -1,   436,  1080,
     319,    -1,   436,  1080,   371,   912,    -1,    -1,  1016,  1015,
    1019,    -1,    -1,  1017,    -1,  1018,    -1,  1017,  1018,    -1,
     959,    -1,  1023,    -1,  1039,    -1,  1025,    -1,    -1,  1020,
      -1,  1022,    -1,  1020,  1022,    -1,    52,   924,    -1,  1027,
      -1,  1033,    -1,  1045,    -1,  1199,    -1,  1209,    -1,  1066,
      -1,  1457,    -1,   884,    -1,   713,    -1,   958,    -1,   719,
      -1,   713,    -1,  1457,    -1,    -1,   713,    -1,  1457,    -1,
     741,    -1,   353,    -1,    46,    -1,    -1,    -1,    -1,    -1,
    1026,  1028,   924,   416,  1029,  1097,   377,  1030,   740,  1031,
    1024,  1477,  1032,    -1,   196,    -1,    -1,    -1,   544,  1034,
     740,  1035,  1477,   347,    -1,   451,   827,    -1,   850,    -1,
     850,   830,    -1,   342,  1378,    -1,  1040,    -1,  1041,    -1,
    1040,  1041,    -1,  1042,    -1,  1023,    -1,  1038,    -1,    -1,
     391,  1043,  1044,    -1,   740,   228,    -1,   912,    -1,    -1,
      -1,    -1,    99,   924,    98,   924,   416,  1046,  1097,   377,
    1047,   740,  1048,  1024,  1477,  1032,    -1,    -1,   545,  1050,
    1065,  1056,  1051,    -1,   348,    -1,    -1,   220,  1053,  1477,
      -1,    -1,    22,  1057,  1058,  1059,   923,  1054,  1477,    -1,
      -1,    22,  1057,   923,  1055,  1477,    -1,  1052,    -1,  1056,
    1052,    -1,    -1,   995,    -1,    24,    -1,  1080,    -1,    -1,
    1080,    -1,    24,    -1,   237,  1063,    -1,   249,  1064,    -1,
     232,  1064,    -1,   572,    -1,    24,    -1,  1080,    -1,  1063,
      -1,  1064,     5,  1063,    -1,  1080,    -1,    24,    -1,    -1,
      -1,   633,   924,  1067,   740,  1068,  1069,   634,    -1,  1070,
      -1,  1069,  1070,    -1,    -1,   635,  1071,  1477,    -1,    -1,
     612,   924,  1072,  1477,    -1,  1076,  1074,    -1,    -1,   667,
    1078,    -1,  1079,    -1,  1075,    -1,   946,    -1,   948,    -1,
     950,    -1,   942,    -1,   944,    -1,    -1,   356,  1077,   831,
      -1,    -1,    51,    -1,    51,    -1,  1081,    -1,  1083,    -1,
     176,  1083,    -1,  1083,   607,    -1,  1082,  1087,    -1,  1082,
     924,   444,  1091,   412,    -1,  1088,    -1,   924,    -1,  1084,
      -1,   924,   443,  1086,   411,    -1,   924,   443,  1086,   411,
      -1,  1080,    -1,    24,    -1,    20,    -1,   924,    -1,   924,
    1090,    -1,   924,  1090,    -1,   444,  1091,   412,    -1,   444,
    1091,   412,   444,  1091,   412,    -1,  1092,    -1,  1091,     5,
    1092,    -1,   663,    -1,  1094,    -1,  1096,    -1,  1094,   607,
    1095,    -1,  1094,   607,   924,   444,  1091,   412,    -1,   924,
      -1,  1085,    -1,    20,    -1,   924,    -1,   924,  1090,    -1,
      -1,  1098,    -1,  1100,    -1,  1098,     5,  1100,    -1,  1101,
      -1,  1099,     5,  1101,    -1,   924,    -1,   924,   607,   924,
      -1,  1080,    -1,  1080,   406,  1080,    -1,    24,    -1,   930,
      -1,    25,    -1,  1103,    -1,  1102,     5,  1103,    -1,  1080,
      -1,  1080,   406,  1080,    -1,  1105,    -1,  1104,     5,  1105,
      -1,  1093,    -1,  1080,    -1,  1108,    -1,  1107,     5,  1108,
      -1,  1080,  1109,    -1,    -1,   574,    -1,   525,    -1,   924,
     444,  1091,   412,    -1,  1112,    -1,  1111,     5,  1112,    -1,
    1080,    -1,  1080,   406,  1080,    -1,   240,   920,   605,   914,
     566,  1469,   671,    -1,    -1,   605,   416,   832,     5,   832,
     377,  1115,    -1,    -1,   555,   416,   832,     5,   832,   377,
      -1,   241,   924,  1114,    -1,   924,    -1,   324,   922,  1119,
      -1,  1120,    -1,   533,   832,    -1,  1121,  1122,  1127,     8,
    1117,    -1,    -1,   605,  1123,   416,   832,     5,   832,   377,
      -1,    -1,   543,   925,    -1,    -1,   336,    -1,   203,  1420,
     252,  1452,  1126,    -1,   550,   917,    -1,   550,   917,     8,
     850,   830,    -1,    -1,   604,   563,  1414,   359,  1414,    -1,
     604,   563,  1414,     5,   359,  1414,    -1,   604,  1414,     5,
    1414,    -1,    -1,   636,    -1,   637,    -1,    76,  1452,  1129,
    1130,    -1,    -1,   604,  1452,    -1,    -1,   604,   563,  1414,
       8,  1414,    -1,   563,  1414,     8,  1414,    -1,   397,  1132,
      -1,  1133,    -1,  1132,     5,  1133,    -1,   189,   911,    -1,
     270,   911,    -1,   315,   911,    -1,   323,   911,    -1,   279,
     911,    -1,   245,   911,    -1,   997,    -1,   424,   998,    -1,
     435,   998,    -1,   548,   998,    -1,   360,   998,    -1,   537,
     998,    -1,   535,   912,    -1,   536,   912,    -1,   386,   667,
      -1,   652,   667,    -1,   277,    -1,   181,    -1,   137,    -1,
     114,    -1,   132,    -1,   123,    -1,  1419,   399,  1137,   533,
    1135,    -1,  1080,    -1,    24,    -1,   388,  1137,    -1,   388,
    1137,     8,  1099,    -1,   925,    -1,    -1,   447,  1146,   666,
     582,  1141,  1080,   923,   666,  1139,  1142,    -1,   447,  1146,
     666,   330,  1080,    -1,    -1,   522,    -1,    -1,  1143,   268,
      -1,  1144,    -1,  1143,  1144,    -1,    -1,   993,  1145,  1477,
      -1,   831,    -1,    -1,   591,   917,  1148,  1149,    -1,    -1,
     533,  1150,    -1,  1151,    -1,  1150,     5,  1151,    -1,  1406,
      -1,   469,    -1,   206,  1154,    74,    -1,   206,  1154,   613,
    1153,    -1,   206,  1154,    73,  1153,    -1,   206,  1154,    -1,
      24,    -1,   929,    -1,   924,    -1,    -1,   465,    -1,   131,
    1154,  1155,   416,   850,  1037,   377,    -1,   179,  1154,    -1,
      53,  1154,    -1,  1190,  1198,    -1,   432,    47,    -1,   432,
    1161,    -1,  1162,    -1,  1161,  1162,    -1,    -1,   119,  1163,
    1477,    -1,    -1,   185,  1164,  1477,    -1,    -1,   214,  1165,
    1477,    -1,    -1,   202,  1166,  1477,    -1,    -1,   239,  1167,
    1477,    -1,    -1,   187,  1080,  1168,  1477,    -1,    -1,   210,
    1080,  1169,  1477,    -1,  1180,    -1,  1182,    -1,  1181,    -1,
    1171,    -1,  1207,    -1,  1174,    -1,    -1,   547,   832,  1172,
     468,    -1,    -1,   468,    -1,    -1,   556,   832,  1175,  1173,
      -1,   144,    -1,   616,  1194,    -1,   147,  1194,    -1,   146,
    1194,    -1,    -1,  1177,    -1,  1178,    -1,  1177,  1178,    -1,
    1187,  1179,    -1,    -1,   605,  1194,    -1,   505,  1176,  1186,
      -1,   504,  1414,  1186,    -1,   503,  1185,  1184,  1183,  1186,
      -1,    -1,   138,   825,    -1,   138,   825,     5,   825,    -1,
     600,    -1,   601,    -1,   602,    -1,   603,    -1,  1080,    -1,
      -1,   508,    -1,  1188,    -1,  1187,     5,  1188,    -1,   832,
    1221,    -1,   596,   416,   825,   377,  1206,    -1,    50,  1206,
      -1,   482,   416,    20,   377,  1206,    -1,   398,   416,    20,
     377,  1206,    -1,   373,   416,   825,   377,  1206,    -1,   575,
     416,   825,   377,  1206,    -1,   588,   416,   825,   377,  1206,
      -1,   587,   416,   825,   377,  1206,    -1,    -1,   446,  1191,
      -1,  1192,    -1,  1191,  1192,    -1,   213,    25,    -1,   204,
      25,    -1,   287,    25,    -1,   170,    25,    -1,   242,    25,
      -1,   162,    -1,   329,    24,    -1,   329,  1080,    -1,   163,
      24,    -1,   145,    24,    -1,  1197,    -1,  1193,  1197,    -1,
    1195,    94,    -1,  1195,    96,    -1,  1195,    95,    -1,  1195,
      -1,   930,    -1,    25,    -1,    -1,   446,  1193,    -1,   213,
    1194,    -1,   204,  1194,    -1,   287,  1194,    -1,   170,  1194,
      -1,   242,  1194,    -1,   243,  1194,    -1,   615,    24,    -1,
     616,  1194,    -1,   620,    -1,   617,    -1,   618,    -1,   619,
      -1,   624,    -1,   621,    -1,   622,    -1,   623,    -1,    63,
    1194,    -1,    64,  1194,    -1,    65,  1194,    -1,   329,    24,
      -1,   163,    24,    -1,   385,    -1,    59,    -1,    60,    -1,
      -1,   500,   606,  1107,    -1,   120,  1107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   450,  1200,   924,   416,  1201,  1097,
     377,  1202,   740,  1203,  1159,  1204,  1160,  1205,   225,    -1,
      -1,   512,   825,    -1,   502,  1208,    -1,    -1,  1135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    91,  1210,   924,   416,
    1211,  1097,   377,  1212,   740,  1213,  1216,  1214,  1160,  1215,
     225,    -1,  1196,  1198,    -1,    -1,    -1,    -1,   140,   416,
      24,     5,  1218,   693,  1219,   377,  1220,   691,    -1,    -1,
     369,    -1,   369,   204,    25,    -1,   369,   204,  1080,    -1,
     594,   832,    -1,   594,   832,   330,  1080,    -1,   594,   832,
     148,    -1,   594,   832,   564,    -1,   594,   832,   531,    -1,
    1224,    -1,   159,    -1,   309,    -1,   267,    -1,  1231,    -1,
    1226,    -1,    -1,    -1,   192,  1227,  1363,   416,  1228,  1235,
     377,    -1,    -1,    -1,   117,  1229,  1363,   416,  1230,  1235,
     377,  1232,    -1,    89,  1233,   377,    -1,    40,   925,    -1,
      -1,   254,    -1,  1234,    -1,  1233,     5,  1234,    -1,   924,
     574,    -1,   924,   525,    -1,   924,    -1,  1236,    -1,  1235,
       5,  1236,    -1,  1316,    -1,  1314,    -1,   106,   924,    -1,
     165,    -1,    33,   924,  1239,    -1,  1240,    -1,  1239,     5,
    1240,    -1,  1241,    -1,  1244,    -1,  1247,    -1,  1252,    -1,
    1253,    -1,  1251,    -1,  1250,    -1,   571,  1242,    -1,   571,
     416,  1243,   377,    -1,  1236,    -1,  1236,   651,   924,    -1,
    1242,    -1,  1243,     5,  1242,    -1,   528,  1246,    -1,   528,
     416,  1245,   377,    -1,  1246,    -1,  1245,     5,  1246,    -1,
     924,    -1,   440,  1249,    -1,   440,   416,  1248,   377,    -1,
    1249,    -1,  1248,     5,  1249,    -1,  1236,    -1,    71,    -1,
      72,    -1,    70,    25,    -1,    42,  1320,    -1,    42,   416,
    1254,   377,    -1,    43,  1255,    -1,    43,   416,  1254,   377,
      -1,  1320,    -1,  1254,     5,  1320,    -1,   924,    -1,   251,
      -1,   217,    -1,   150,  1258,    -1,   127,    -1,   115,    -1,
     105,    -1,   103,    -1,   107,    -1,   164,  1420,    -1,   216,
    1257,   445,  1414,   613,  1414,    -1,   284,   917,   445,  1414,
     613,  1414,    -1,    -1,  1420,    -1,    -1,   832,    -1,   509,
     832,    -1,   215,    -1,    -1,   234,  1262,  1363,  1265,  1263,
      -1,    -1,   465,  1264,   416,  1267,   377,    -1,  1400,    -1,
      -1,   416,  1266,   377,    -1,  1366,    -1,  1266,     5,  1366,
      -1,  1268,    -1,  1267,     5,  1268,    -1,  1406,    -1,   469,
      -1,    -1,    -1,   486,  1270,  1272,  1271,  1273,    -1,  1277,
     918,    -1,   918,    -1,    -1,    -1,   540,  1274,  1102,    -1,
      -1,    -1,   540,  1276,  1102,    -1,   487,    -1,   541,    -1,
     548,    -1,   360,    -1,   327,    -1,   381,    -1,   363,   832,
      -1,   336,   832,    -1,   223,  1363,   135,   918,    -1,   223,
    1363,  1336,    -1,   500,   606,  1281,    -1,  1282,    -1,  1281,
       5,  1282,    -1,  1283,  1284,    -1,    25,    -1,  1366,    -1,
      -1,   574,    -1,   525,    -1,   262,    -1,   295,    -1,    -1,
     312,    -1,   342,  1289,  1287,    -1,  1452,    -1,    24,    -1,
      -1,  1419,  1291,  1292,    -1,  1321,    -1,  1325,    -1,  1286,
      -1,  1421,    -1,  1285,    -1,  1278,    -1,  1279,    -1,  1269,
      -1,  1261,    -1,  1260,    -1,  1390,    -1,  1436,    -1,   491,
    1295,   612,  1363,   613,  1300,  1294,    -1,    -1,   126,    -1,
     154,    -1,  1296,    -1,  1297,    -1,  1296,     5,  1297,    -1,
     457,    -1,   435,    -1,   424,    -1,   464,  1298,    -1,    -1,
     416,  1299,   377,    -1,  1366,    -1,  1299,     5,  1366,    -1,
    1301,    -1,  1300,     5,  1301,    -1,   448,    -1,  1364,    -1,
     221,  1363,  1303,   604,  1400,  1305,    -1,    -1,   416,  1304,
     377,    -1,  1366,    -1,  1304,     5,  1366,    -1,    -1,   125,
      -1,   478,   416,  1339,   377,    -1,   231,   416,  1309,   377,
    1308,    -1,   282,  1310,    -1,  1311,    -1,  1363,    -1,  1363,
     416,  1311,   377,    -1,  1366,    -1,  1311,     5,  1366,    -1,
     462,   416,  1313,   377,    -1,   244,   416,  1313,   377,    -1,
    1366,    -1,  1313,     5,  1366,    -1,  1312,    -1,  1307,    -1,
    1306,    -1,   385,  1369,    -1,   193,    -1,   924,  1355,  1317,
    1318,    -1,    -1,  1315,    -1,    -1,  1319,    -1,  1320,    -1,
    1319,  1320,    -1,   358,    -1,   143,    -1,  1308,    -1,   478,
     416,  1339,   377,    -1,   104,  1322,  1324,    -1,  1323,    -1,
    1364,    -1,  1325,    -1,  1324,  1325,    -1,  1302,    -1,  1293,
      -1,   433,  1339,    -1,   354,  1328,    -1,  1405,    -1,  1328,
       5,  1405,    -1,   512,  1339,    -1,   533,  1331,    -1,  1332,
      -1,  1331,     5,  1332,    -1,  1333,    -1,   501,  1333,    -1,
     501,   416,  1334,   377,    -1,  1363,    -1,  1363,  1368,    -1,
    1332,    -1,  1334,     5,  1332,    -1,  1330,  1336,  1337,  1338,
      -1,    -1,  1329,    -1,    -1,  1327,    -1,    -1,  1326,    -1,
    1340,    -1,  1339,     6,  1340,    -1,  1341,    -1,  1340,     7,
    1341,    -1,  1342,    -1,   589,  1342,    -1,  1353,    -1,   416,
    1339,   377,    -1,   428,  1401,    -1,   280,  1401,    -1,    -1,
     427,  1346,    -1,  1410,    -1,   924,    -1,  1410,    -1,  1406,
     610,   416,  1348,   377,    -1,  1406,   610,  1401,    -1,  1406,
     414,   416,  1348,   377,    -1,  1406,   414,  1401,    -1,  1349,
      -1,  1348,     5,  1349,    -1,  1456,    -1,  1369,    -1,    -1,
     589,    -1,  1406,  1350,   372,    -1,  1406,  1350,   235,    -1,
    1406,  1352,  1406,    -1,  1406,  1350,   374,  1406,     7,  1406,
      -1,  1406,   543,  1345,  1344,    -1,  1406,   357,  1345,  1344,
      -1,  1406,  1350,     9,  1345,  1344,    -1,    13,    -1,    16,
      -1,    11,    -1,    12,    -1,   238,    -1,     9,    -1,    15,
      -1,    14,    -1,  1351,    -1,  1347,    -1,  1343,    -1,    -1,
     572,    -1,   345,    -1,   462,    -1,  1356,    -1,  1357,    -1,
    1359,    -1,   522,    -1,   522,   416,  1360,   377,    -1,   396,
     416,  1361,  1358,   377,    -1,   458,    -1,   383,   416,  1361,
    1358,   377,    -1,   498,   416,  1361,  1358,   377,    -1,   524,
      -1,   393,    -1,   365,    -1,   343,  1376,   613,  1377,    -1,
     343,    -1,   355,  1376,   613,  1377,    -1,   355,    -1,   355,
    1376,   416,    25,   377,   613,  1377,    -1,   561,    -1,   519,
      -1,   409,    -1,   409,   416,    25,   377,    -1,   409,   416,
      25,     5,    25,   377,    -1,    -1,     5,  1362,    -1,   488,
     416,  1361,   377,    -1,   552,    -1,   285,    -1,   488,    -1,
      49,    -1,    25,    -1,    25,    -1,    25,    -1,    24,   607,
     924,    -1,    24,    -1,   924,    -1,   924,   576,   924,    -1,
     924,    -1,    -1,   444,    25,   412,    -1,   444,    25,     5,
      25,   412,    -1,  1367,    -1,   599,  1367,    -1,   924,  1365,
      -1,  1363,   607,   924,  1365,    -1,  1363,   607,    20,    -1,
     924,    -1,    24,    -1,   396,    -1,   930,    -1,    25,    -1,
    1371,    -1,   381,  1373,    -1,   381,  1372,    -1,    -1,  1376,
     613,  1377,    -1,    -1,  1374,   613,  1374,    -1,   568,    -1,
     499,    -1,   577,    -1,   539,    -1,   439,    -1,   456,    -1,
     352,    -1,   352,   416,    25,   377,    -1,   568,    -1,   499,
      -1,   577,    -1,   539,    -1,   439,    -1,   456,    -1,   352,
      -1,   352,   416,    25,   377,    -1,   568,    -1,   499,    -1,
     577,    -1,   539,    -1,   439,    -1,   456,    -1,   352,    -1,
     568,    -1,   499,    -1,   577,    -1,   539,    -1,   439,    -1,
     456,    -1,   352,    -1,   924,    -1,    24,    -1,  1419,   489,
     918,    -1,    -1,  1419,   384,   918,   422,   582,  1388,  1381,
    1385,    -1,    -1,  1419,   384,   918,   422,    86,   582,  1389,
    1382,  1385,    -1,    -1,  1419,   384,   918,   121,  1389,  1383,
    1385,    -1,    -1,  1419,   384,   918,   122,    86,   582,  1389,
    1384,  1385,    -1,    -1,   274,    -1,   273,  1386,    -1,  1387,
      -1,  1386,     5,  1387,    -1,   924,    -1,   924,   607,   924,
      -1,    24,   607,   924,   607,   924,    -1,  1389,    -1,  1261,
      -1,  1137,    -1,  1391,    -1,  1391,  1385,    -1,    -1,    -1,
     457,  1402,  1392,  1403,  1393,  1399,  1335,  1397,    -1,   457,
    1402,  1403,  1335,  1397,    -1,  1396,    -1,  1414,    -1,   457,
    1402,  1403,  1399,  1335,  1397,    -1,    -1,   511,  1354,  1395,
      -1,  1280,    -1,   317,  1398,  1232,    -1,  1280,   317,  1398,
    1232,    -1,   924,    -1,    -1,   540,  1102,    -1,   457,  1402,
    1403,  1335,    -1,   416,   457,  1402,  1403,  1335,   377,    -1,
      -1,   572,    -1,   345,    -1,   462,    -1,  1404,    -1,  1403,
       5,  1404,    -1,  1406,    -1,  1406,  1476,    -1,  1406,   931,
      -1,  1406,    -1,  1407,    -1,    18,  1407,    -1,    17,  1407,
      -1,  1408,    -1,  1456,    -1,  1401,    -1,   599,   924,    -1,
     599,   924,   607,   924,    -1,  1407,    19,  1406,    -1,  1407,
    1428,    -1,  1407,    20,  1406,    -1,  1407,    17,  1406,    -1,
    1407,    18,  1406,    -1,  1369,    -1,   470,    -1,   413,    -1,
     563,    -1,    20,    -1,    50,    -1,   575,   416,  1354,  1406,
     377,    -1,   587,   416,  1354,  1406,   377,    -1,   588,   416,
    1354,  1406,   377,    -1,   596,   416,  1354,  1406,   377,    -1,
     482,   416,  1354,  1406,   377,    -1,   924,   416,  1409,   377,
      -1,   524,   416,  1409,   377,    -1,   416,  1406,   377,    -1,
     429,   416,  1429,   377,    -1,  1406,    -1,  1409,     5,  1406,
      -1,    -1,  1369,    -1,  1419,   332,  1418,  1413,  1395,    -1,
    1419,   321,  1418,  1413,   234,  1363,  1415,    -1,  1419,   321,
    1418,  1413,  1080,    -1,    -1,   307,  1414,    -1,    24,    -1,
    1080,    -1,    -1,   416,  1416,   377,    -1,  1417,    -1,  1416,
       5,  1417,    -1,   924,    -1,    24,    -1,  1080,    -1,    -1,
     253,  1420,   582,    -1,   925,    -1,  1426,    -1,  1425,    -1,
    1422,    -1,   302,  1423,   613,  1423,    -1,   283,  1423,   607,
    1424,   613,  1424,    -1,   924,    -1,   924,    -1,   207,   775,
      -1,   278,   775,  1427,    -1,   257,    -1,   161,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,   381,     5,  1376,   613,  1377,    -1,  1366,     5,  1376,
     613,  1377,    -1,   381,  1376,   613,  1377,    -1,    -1,   595,
    1431,  1432,   175,    -1,  1433,    -1,  1432,  1433,    -1,    32,
      -1,  1434,    -1,  1435,    -1,   176,  1456,    -1,   540,  1102,
      -1,    -1,    -1,   464,  1363,  1437,  1440,  1438,  1439,    -1,
      -1,   135,   918,    -1,   512,  1339,    -1,    38,  1444,   377,
      13,   416,  1445,   377,    -1,    34,  1445,   377,    -1,    35,
    1445,   377,    -1,   570,  1441,    -1,    37,  1445,    -1,    36,
    1445,    -1,  1443,    -1,  1441,     5,  1443,    -1,  1366,    -1,
    1442,    13,  1446,    -1,  1442,    -1,  1444,     5,  1442,    -1,
    1446,    -1,  1445,     5,  1446,    -1,   469,    -1,  1447,    -1,
    1448,    -1,    18,  1448,    -1,    17,  1448,    -1,  1450,    -1,
    1401,    -1,   599,   924,    -1,   599,   924,   607,   924,    -1,
    1449,    -1,  1369,    -1,   470,    -1,   413,    -1,   563,    -1,
      50,    -1,  1448,    19,  1447,    -1,  1448,  1428,    -1,  1448,
      20,  1447,    -1,  1448,    17,  1447,    -1,  1448,    18,  1447,
      -1,   575,   416,  1354,  1447,   377,    -1,   587,   416,  1354,
    1447,   377,    -1,   588,   416,  1354,  1447,   377,    -1,   596,
     416,  1354,  1447,   377,    -1,   482,   416,  1354,  1447,   377,
      -1,   924,   416,  1451,   377,    -1,   524,   416,  1451,   377,
      -1,   416,  1447,   377,    -1,   429,   416,  1429,   377,    -1,
    1456,    -1,  1447,    -1,  1451,     5,  1447,    -1,  1453,    -1,
     176,  1454,    -1,  1454,    -1,  1089,    -1,   924,    -1,  1454,
     607,  1455,    -1,    24,   607,  1454,   607,  1455,    -1,    20,
      -1,  1110,    -1,   924,    -1,  1453,    -1,  1453,   406,  1453,
      -1,   112,  1458,    -1,   116,  1458,    -1,   111,  1458,    -1,
     151,    -1,   152,  1458,    -1,   109,  1458,    -1,   134,  1458,
      -1,   133,  1458,    -1,   108,  1458,    -1,   341,    -1,   608,
     613,  1459,    -1,   534,  1459,    -1,   559,    -1,   520,  1460,
      -1,   924,    -1,   576,   924,    -1,   924,    -1,    -1,    -1,
     513,  1462,   832,  1463,  1477,   311,    -1,    -1,   646,  1467,
      -1,    -1,   649,    -1,   167,    -1,   263,   919,    -1,    55,
     919,    -1,   293,    -1,   292,    -1,   294,   921,  1464,  1465,
      -1,   479,  1467,  1465,    -1,   916,    -1,  1467,     5,   916,
      -1,    88,    -1,   118,   919,    -1,   832,   553,     5,   832,
     378,    -1,   495,   832,    -1,   250,   919,    -1,    87,  1472,
       8,  1473,  1471,    -1,    -1,   533,   832,    -1,   924,    -1,
     924,    -1,   233,   919,    -1,   236,   919,   613,   832,     5,
     832,    -1,   236,   919,   606,   832,     5,   832,    -1,    26,
      -1,    -1,  1479,    -1,  1480,  1186,    -1,  1478,    -1,  1479,
    1478,    -1,    -1,  1481,  1482,    -1,   656,    -1,   657,    -1,
     658,    -1,   659,    -1,   676,    -1,   698,    -1,   712,    -1,
     713,    -1,   719,    -1,   720,    -1,   739,    -1,   807,    -1,
     808,    -1,   809,    -1,   810,    -1,   821,    -1,   822,    -1,
     823,    -1,   824,    -1,   876,    -1,   880,    -1,   910,    -1,
     932,    -1,   933,    -1,   936,    -1,   937,    -1,   938,    -1,
     939,    -1,   952,    -1,   960,    -1,   983,    -1,   984,    -1,
     986,    -1,   990,    -1,  1005,    -1,  1006,    -1,  1010,    -1,
    1011,    -1,  1012,    -1,  1013,    -1,  1021,    -1,  1036,    -1,
    1049,    -1,  1060,    -1,  1061,    -1,  1062,    -1,  1073,    -1,
    1113,    -1,  1116,    -1,  1118,    -1,  1124,    -1,  1125,    -1,
    1128,    -1,  1131,    -1,  1134,    -1,  1136,    -1,  1138,    -1,
    1140,    -1,  1147,    -1,  1152,    -1,  1156,    -1,  1157,    -1,
    1158,    -1,  1170,    -1,  1222,    -1,  1223,    -1,  1225,    -1,
    1237,    -1,  1238,    -1,  1256,    -1,  1259,    -1,  1288,    -1,
    1290,    -1,  1379,    -1,  1380,    -1,  1411,    -1,  1412,    -1,
    1430,    -1,  1457,    -1,  1461,    -1,  1466,    -1,  1468,    -1,
    1470,    -1,  1474,    -1,  1475,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   906,   906,   909,   912,   918,   924,   931,   935,   935,
     941,   964,   965,   966,   967,   968,   982,   983,   984,   985,
     986,   991,   992,  1003,  1006,  1009,  1009,  1013,  1016,  1017,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1041,  1042,  1045,  1045,
    1053,  1054,  1057,  1063,  1065,  1076,  1078,  1080,  1082,  1086,
    1088,  1150,  1154,  1158,  1158,  1169,  1173,  1177,  1178,  1181,
    1187,  1181,  1200,  1205,  1209,  1200,  1221,  1225,  1221,  1233,
    1238,  1233,  1257,  1264,  1268,  1256,  1294,  1294,  1298,  1299,
    1300,  1305,  1308,  1313,  1317,  1325,  1328,  1328,  1334,  1338,
    1353,  1351,  1369,  1369,  1384,  1384,  1387,  1387,  1391,  1394,
    1394,  1394,  1401,  1402,  1401,  1409,  1409,  1420,  1420,  1439,
    1442,  1445,  1448,  1451,  1454,  1467,  1472,  1472,  1473,  1473,
    1476,  1481,  1481,  1485,  1495,  1509,  1513,  1508,  1523,  1529,
    1537,  1538,  1541,  1541,  1544,  1548,  1553,  1560,  1560,  1564,
    1564,  1571,  1571,  1576,  1576,  1581,  1581,  1586,  1586,  1599,
    1600,  1608,  1609,  1626,  1629,  1632,  1635,  1638,  1641,  1647,
    1658,  1663,  1676,  1680,  1695,  1696,  1700,  1700,  1704,  1704,
    1704,  1705,  1706,  1711,  1711,  1714,  1714,  1723,  1724,  1725,
    1728,  1732,  1733,  1733,  1750,  1750,  1750,  1750,  1754,  1761,
    1762,  1765,  1765,  1768,  1768,  1777,  1774,  1790,  1790,  1792,
    1792,  1794,  1796,  1798,  1800,  1803,  1807,  1807,  1808,  1808,
    1812,  1812,  1824,  1824,  1829,  1833,  1835,  1836,  1839,  1839,
    1839,  1843,  1844,  1845,  1846,  1853,  1854,  1855,  1856,  1859,
    1860,  1861,  1862,  1866,  1871,  1876,  1880,  1883,  1887,  1888,
    1889,  1890,  1891,  1892,  1893,  1894,  1897,  1898,  1899,  1931,
    1935,  1937,  1939,  1939,  1946,  1950,  1950,  1954,  1955,  1956,
    1957,  1958,  1959,  1960,  1966,  1966,  1969,  1971,  1977,  1979,
    1985,  1993,  1993,  1996,  1997,  1998,  1999,  2000,  2001,  2002,
    2008,  2011,  2011,  2024,  2024,  2031,  2032,  2033,  2035,  2036,
    2038,  2040,  2041,  2042,  2043,  2048,  2054,  2060,  2061,  2063,
    2065,  2066,  2067,  2068,  2069,  2070,  2073,  2074,  2081,  2089,
    2089,  2097,  2094,  2109,  2109,  2111,  2111,  2119,  2119,  2122,
    2125,  2126,  2131,  2143,  2147,  2150,  2153,  2154,  2155,  2156,
    2157,  2162,  2169,  2175,  2180,  2184,  2180,  2195,  2197,  2202,
    2207,  2207,  2211,  2211,  2214,  2214,  2220,  2220,  2226,  2226,
    2242,  2245,  2259,  2261,  2263,  2265,  2267,  2269,  2271,  2277,
    2279,  2283,  2285,  2287,  2289,  2291,  2293,  2295,  2301,  2316,
    2319,  2332,  2333,  2334,  2335,  2336,  2340,  2341,  2342,  2346,
    2351,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,  2366,
    2367,  2372,  2372,  2377,  2377,  2380,  2386,  2394,  2400,  2410,
    2411,  2419,  2426,  2430,  2440,  2444,  2449,  2454,  2456,  2466,
    2479,  2487,  2500,  2505,  2511,  2516,  2521,  2522,  2528,  2599,
    2605,  2610,  2618,  2618,  2633,  2637,  2644,  2647,  2655,  2666,
    2676,  2682,  2691,  2696,  2704,  2707,  2710,  2715,  2722,  2727,
    2732,  2737,  2747,  2755,  2763,  2768,  2772,  2777,  2781,  2785,
    2792,  2795,  2798,  2802,  2806,  2810,  2814,  2822,  2832,  2837,
    2830,  2853,  2858,  2853,  2875,  2875,  2875,  2878,  2878,  2878,
    2881,  2881,  2881,  2884,  2884,  2884,  2887,  2893,  2899,  2905,
    2915,  2915,  2919,  2923,  2924,  2930,  2931,  2936,  2939,  2943,
    2947,  2948,  2951,  2956,  2962,  2966,  2970,  2973,  2979,  2982,
    2985,  3000,  3003,  3009,  3010,  3011,  3015,  3016,  3017,  3018,
    3019,  3021,  3022,  3023,  3025,  3026,  3030,  3031,  3036,  3037,
    3049,  3053,  3048,  3061,  3064,  3078,  3082,  3087,  3077,  3107,
    3113,  3107,  3127,  3127,  3129,  3130,  3134,  3134,  3138,  3138,
    3143,  3143,  3150,  3151,  3155,  3155,  3159,  3159,  3164,  3164,
    3171,  3175,  3176,  3177,  3182,  3182,  3185,  3185,  3189,  3189,
    3193,  3193,  3197,  3197,  3202,  3202,  3207,  3207,  3212,  3212,
    3217,  3217,  3233,  3250,  3251,  3252,  3253,  3254,  3255,  3258,
    3258,  3261,  3263,  3266,  3269,  3271,  3272,  3273,  3275,  3277,
    3279,  3281,  3285,  3292,  3294,  3300,  3305,  3310,  3315,  3315,
    3318,  3324,  3329,  3332,  3339,  3339,  3341,  3342,  3344,  3346,
    3348,  3350,  3354,  3363,  3363,  3370,  3371,  3372,  3373,  3374,
    3375,  3376,  3377,  3378,  3379,  3380,  3381,  3382,  3383,  3384,
    3385,  3386,  3387,  3388,  3389,  3390,  3391,  3392,  3393,  3394,
    3395,  3396,  3397,  3398,  3399,  3400,  3401,  3402,  3403,  3404,
    3405,  3406,  3407,  3408,  3409,  3410,  3411,  3412,  3424,  3437,
    3444,  3444,  3448,  3453,  3459,  3463,  3467,  3473,  3477,  3481,
    3487,  3487,  3495,  3496,  3500,  3500,  3504,  3505,  3508,  3511,
    3511,  3514,  3516,  3516,  3519,  3521,  3521,  3522,  3524,  3524,
    3533,  3531,  3543,  3543,  3543,  3546,  3548,  3546,  3555,  3558,
    3564,  3575,  3575,  3579,  3585,  3585,  3589,  3590,  3601,  3602,
    3604,  3606,  3611,  3611,  3615,  3614,  3621,  3620,  3626,  3626,
    3631,  3631,  3637,  3637,  3642,  3642,  3647,  3647,  3652,  3652,
    3657,  3657,  3665,  3666,  3674,  3675,  3680,  3681,  3690,  3691,
    3698,  3699,  3707,  3708,  3717,  3722,  3727,  3728,  3729,  3733,
    3732,  3743,  3748,  3753,  3753,  3764,  3769,  3770,  3771,  3772,
    3775,  3775,  3781,  3781,  3783,  3786,  3786,  3788,  3792,  3792,
    3795,  3796,  3799,  3799,  3804,  3804,  3807,  3808,  3809,  3810,
    3811,  3812,  3813,  3814,  3815,  3816,  3817,  3818,  3819,  3820,
    3821,  3822,  3823,  3827,  3845,  3845,  3845,  3871,  3882,  3889,
    3895,  3901,  3907,  3918,  3941,  3940,  3957,  3957,  3961,  3962,
    3970,  3971,  3972,  3973,  3980,  3981,  3983,  3984,  3988,  3993,
    3994,  3995,  3996,  3997,  3998,  3999,  4000,  4001,  4002,  4003,
    4006,  4006,  4008,  4008,  4008,  4010,  4014,  4014,  4023,  4028,
    4044,  4050,  4022,  4064,  4078,  4088,  4077,  4101,  4108,  4108,
    4113,  4118,  4123,  4124,  4127,  4127,  4127,  4130,  4130,  4138,
    4144,  4158,  4162,  4175,  4157,  4193,  4193,  4206,  4217,  4216,
    4228,  4224,  4241,  4238,  4251,  4251,  4253,  4254,  4256,  4257,
    4260,  4261,  4262,  4264,  4269,  4274,  4280,  4282,  4283,  4286,
    4287,  4290,  4292,  4301,  4307,  4301,  4318,  4319,  4323,  4323,
    4333,  4333,  4345,  4348,  4352,  4356,  4361,  4365,  4366,  4367,
    4368,  4369,  4373,  4373,  4375,  4375,  4378,  4387,  4435,  4435,
    4438,  4442,  4447,  4488,  4489,  4490,  4493,  4507,  4519,  4519,
    4524,  4525,  4531,  4590,  4646,  4651,  4658,  4663,  4671,  4677,
    4706,  4709,  4710,  4751,  4752,  4756,  4757,  4761,  4814,  4818,
    4821,  4827,  4838,  4845,  4853,  4853,  4856,  4857,  4858,  4859,
    4860,  4863,  4866,  4872,  4875,  4879,  4883,  4890,  4895,  4902,
    4905,  4911,  4913,  4913,  4913,  4917,  4937,  4944,  4951,  4954,
    4968,  4975,  4976,  4979,  4980,  4984,  4990,  4995,  5001,  5002,
    5007,  5011,  5011,  5015,  5016,  5019,  5020,  5024,  5032,  5035,
    5041,  5042,  5044,  5046,  5050,  5050,  5051,  5056,  5064,  5065,
    5070,  5071,  5073,  5086,  5088,  5089,  5091,  5094,  5097,  5100,
    5104,  5107,  5110,  5114,  5118,  5122,  5125,  5129,  5132,  5133,
    5134,  5137,  5140,  5143,  5146,  5149,  5152,  5155,  5171,  5179,
    5179,  5181,  5188,  5195,  5210,  5208,  5228,  5233,  5234,  5238,
    5239,  5241,  5242,  5244,  5244,  5252,  5261,  5261,  5271,  5272,
    5275,  5276,  5279,  5283,  5297,  5302,  5307,  5312,  5322,  5322,
    5326,  5329,  5329,  5331,  5341,  5350,  5357,  5359,  5363,  5366,
    5366,  5370,  5369,  5373,  5372,  5376,  5375,  5379,  5378,  5382,
    5381,  5384,  5384,  5400,  5399,  5421,  5422,  5423,  5424,  5425,
    5426,  5429,  5429,  5435,  5435,  5438,  5438,  5448,  5449,  5450,
    5457,  5469,  5470,  5473,  5474,  5477,  5480,  5480,  5485,  5489,
    5494,  5500,  5501,  5502,  5506,  5507,  5508,  5509,  5513,  5523,
    5525,  5530,  5533,  5538,  5544,  5551,  5558,  5567,  5574,  5581,
    5588,  5595,  5604,  5604,  5606,  5606,  5609,  5610,  5611,  5612,
    5613,  5614,  5615,  5616,  5617,  5618,  5621,  5621,  5624,  5625,
    5626,  5627,  5630,  5630,  5633,  5633,  5636,  5637,  5638,  5639,
    5640,  5641,  5642,  5643,  5645,  5646,  5647,  5648,  5650,  5651,
    5652,  5653,  5655,  5656,  5657,  5658,  5659,  5660,  5661,  5662,
    5666,  5672,  5680,  5691,  5700,  5711,  5715,  5719,  5725,  5690,
    5738,  5741,  5749,  5761,  5763,  5768,  5776,  5786,  5789,  5793,
    5801,  5767,  5810,  5814,  5818,  5822,  5814,  5832,  5833,  5834,
    5835,  5840,  5842,  5845,  5849,  5852,  5859,  5864,  5865,  5866,
    5871,  5872,  5878,  5878,  5878,  5883,  5883,  5883,  5894,  5895,
    5901,  5902,  5908,  5909,  5914,  5915,  5916,  5920,  5923,  5929,
    5932,  5940,  5941,  5947,  5954,  5957,  5966,  5969,  5972,  5975,
    5978,  5981,  5984,  5991,  5994,  6001,  6004,  6010,  6013,  6020,
    6023,  6030,  6031,  6036,  6040,  6043,  6049,  6052,  6058,  6065,
    6066,  6070,  6076,  6079,  6086,  6087,  6094,  6097,  6102,  6113,
    6114,  6115,  6116,  6117,  6118,  6119,  6120,  6121,  6124,  6127,
    6133,  6133,  6139,  6139,  6150,  6163,  6173,  6173,  6178,  6178,
    6182,  6186,  6187,  6193,  6194,  6199,  6203,  6210,  6213,  6220,
    6224,  6219,  6236,  6240,  6247,  6251,  6251,  6264,  6268,  6268,
    6283,  6285,  6287,  6289,  6291,  6293,  6295,  6297,  6303,  6313,
    6320,  6325,  6326,  6330,  6332,  6333,  6336,  6337,  6338,  6341,
    6346,  6353,  6354,  6360,  6372,  6373,  6376,  6376,  6381,  6386,
    6391,  6392,  6395,  6396,  6401,  6406,  6410,  6415,  6416,  6420,
    6427,  6431,  6432,  6437,  6439,  6443,  6444,  6448,  6449,  6450,
    6451,  6455,  6456,  6461,  6462,  6467,  6468,  6473,  6474,  6479,
    6484,  6485,  6490,  6491,  6495,  6496,  6501,  6508,  6513,  6518,
    6522,  6523,  6528,  6529,  6535,  6537,  6542,  6543,  6549,  6552,
    6555,  6562,  6564,  6576,  6581,  6582,  6585,  6587,  6594,  6597,
    6603,  6607,  6611,  6614,  6621,  6628,  6633,  6637,  6638,  6644,
    6647,  6658,  6665,  6671,  6674,  6681,  6688,  6694,  6695,  6701,
    6702,  6703,  6706,  6707,  6712,  6712,  6716,  6724,  6725,  6728,
    6731,  6736,  6737,  6742,  6745,  6751,  6754,  6760,  6763,  6769,
    6772,  6779,  6780,  6809,  6810,  6815,  6816,  6820,  6825,  6828,
    6831,  6834,  6840,  6841,  6845,  6848,  6851,  6852,  6857,  6860,
    6863,  6866,  6869,  6872,  6875,  6881,  6882,  6883,  6884,  6885,
    6887,  6889,  6890,  6895,  6898,  6902,  6908,  6909,  6910,  6911,
    6923,  6924,  6925,  6929,  6930,  6935,  6937,  6938,  6939,  6941,
    6942,  6943,  6944,  6946,  6947,  6949,  6950,  6952,  6953,  6954,
    6955,  6957,  6961,  6962,  6968,  6970,  6971,  6972,  6973,  6978,
    6982,  6986,  6990,  6991,  6995,  6996,  7006,  7014,  7015,  7016,
    7020,  7023,  7028,  7033,  7038,  7046,  7050,  7054,  7055,  7056,
    7061,  7064,  7067,  7071,  7072,  7076,  7077,  7081,  7081,  7081,
    7081,  7081,  7081,  7082,  7085,  7090,  7090,  7090,  7090,  7090,
    7090,  7092,  7095,  7101,  7101,  7101,  7101,  7101,  7101,  7101,
    7102,  7102,  7102,  7102,  7102,  7102,  7102,  7104,  7105,  7108,
    7117,  7117,  7122,  7122,  7128,  7128,  7133,  7133,  7140,  7141,
    7142,  7145,  7145,  7148,  7149,  7150,  7155,  7158,  7164,  7167,
    7175,  7188,  7189,  7186,  7207,  7217,  7220,  7225,  7237,  7240,
    7244,  7247,  7248,  7254,  7257,  7258,  7267,  7276,  7281,  7282,
    7283,  7284,  7292,  7295,  7301,  7304,  7307,  7313,  7322,  7325,
    7328,  7334,  7340,  7343,  7346,  7349,  7355,  7357,  7359,  7361,
    7363,  7365,  7366,  7367,  7368,  7369,  7370,  7371,  7373,  7375,
    7377,  7379,  7381,  7383,  7385,  7386,  7391,  7392,  7398,  7399,
    7402,  7411,  7415,  7422,  7422,  7426,  7426,  7431,  7431,  7435,
    7435,  7439,  7445,  7445,  7448,  7448,  7454,  7461,  7462,  7463,
    7467,  7468,  7471,  7472,  7476,  7482,  7492,  7493,  7501,  7502,
    7503,  7504,  7505,  7506,  7510,  7511,  7512,  7516,  7516,  7528,
    7529,  7533,  7534,  7535,  7539,  7545,  7632,  7636,  7632,  7645,
    7649,  7655,  7663,  7673,  7683,  7695,  7698,  7717,  7743,  7746,
    7752,  7755,  7760,  7763,  7771,  7779,  7792,  7795,  7803,  7806,
    7809,  7817,  7821,  7824,  7827,  7830,  7834,  7835,  7836,  7837,
    7838,  7844,  7845,  7846,  7847,  7848,  7849,  7850,  7851,  7852,
    7853,  7854,  7855,  7856,  7857,  7861,  7867,  7868,  7880,  7892,
    7892,  7896,  7897,  7898,  7899,  7903,  7904,  7905,  7910,  7924,
    7975,  7977,  7979,  7981,  7985,  7990,  7992,  7994,  7996,  8000,
    8003,  8008,  8013,  8017,  8026,  8027,  8031,  8043,  8046,  8042,
    8065,  8065,  8069,  8070,  8073,  8074,  8075,  8076,  8077,  8078,
    8079,  8084,  8085,  8089,  8092,  8097,  8101,  8106,  8110,  8115,
    8119,  8122,  8126,  8129,  8134,  8138,  8149,  8155,  8155,  8156,
    8157,  8164,  8173,  8173,  8175,  8176,  8177,  8178,  8179,  8180,
    8181,  8182,  8183,  8184,  8185,  8186,  8187,  8188,  8189,  8190,
    8191,  8192,  8193,  8194,  8195,  8196,  8197,  8198,  8199,  8200,
    8201,  8202,  8203,  8204,  8205,  8206,  8207,  8208,  8209,  8210,
    8211,  8212,  8213,  8214,  8215,  8216,  8217,  8218,  8219,  8220,
    8221,  8222,  8223,  8224,  8225,  8226,  8227,  8228,  8229,  8230,
    8231,  8232,  8233,  8234,  8235,  8236,  8237,  8238,  8239,  8240,
    8241,  8242,  8243,  8244,  8245,  8246,  8247,  8248,  8249,  8250,
    8251,  8252,  8253,  8254,  8255,  8256,  8257,  8258,  8259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "UMINUS", "COMMA", "KW_OR", 
  "KW_AND", "KW_USING", "MATCHES", "POWER", "LESS_THAN", "GREATER_THAN", 
  "EQUAL", "GREATER_THAN_EQ", "LESS_THAN_EQ", "NOT_EQUAL", "PLUS", 
  "MINUS", "DIVIDE", "MULTIPLY", "MOD", "COMMAND", "NUMBER_VALUE", 
  "CHAR_VALUE", "INT_VALUE", "NAMED_GEN", "CLINE", "SQLLINE", "KW_CSTART", 
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "ALTER_TABLE", 
  "XSET_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL_OPEN_BRACKET", 
  "XSET_ident_DOT_MULTIPLY_EQUAL", "XSET_MULTIPLY_EQUAL", 
  "XSET_OPEN_BRACKET", "NEWFORMATSHARED", "CREATE_DATABASE", 
  "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", "DROP_CONSTRAINT", 
  "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", 
  "DOUBLE_PRECISION", "COUNT_MULTIPLY", "WAIT_FOR_KEY", 
  "AT_TERMINATION_CALL", "TERMINATE_REPORT", "TO_MAIN_CAPTION", 
  "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", 
  "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", "UP_BY", 
  "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", 
  "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", "DOWN_BY", 
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
  "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", "WHENEVER_ERROR_CONTINUE", 
  "WHENEVER_ERROR", "AFTCONSTRUCT", "ALL_PRIVILEGES", "CLOSE_DATABASE", 
  "CONTINUE_INPUT", "CONTINUE_WHILE", "CREATE_SYNONYM", "DROP_TABLE", 
  "EXIT_CONSTRUCT", "INEXCLUSIVE", "REPORT_TO_PRINTER", "REPORT_TO_PIPE", 
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
  "PROMPT", "PUBLIC", "RECORD", "REPORT", "RETURN", "REVOKE", "SCHEMA", 
  "SCROLL_USING", "SCROLL", "SECOND", "SELECT", "SERIAL", "SETL", 
  "SHARED", "SPACES", "UNIQUE", "UNLOCK", "UPDATE", "VALUES", "YELLOW", 
  "AFTER", "KWLINE", "KW_NULL", "KW_TRUE", "SINGLE_KEY", "ALTER", "ARRAY", 
  "ASCII", "AUDIT", "BLACK", "BLINK", "CHECK", "CLEAR", "CLOSE", "CODE_C", 
  "COUNT", "DEFER", "ERROR", "EVERY", "FETCH", "FIRST", "FLOAT", "FLUSH", 
  "FOUND", "GRANT", "GREEN", "GROUP", "INDEX", "KWFORM", "LABEL", "LOCAL", 
  "MONEY", "MONTH", "ORDER", "OUTER", "PAUSE", "PRINT_IMAGE", 
  "PRINT_FILE", "PRINT", "RIGHT", "DOUBLE_COLON", "SEMICOLON", "SLEEP", 
  "TUPLE", "UNION", "WHERE", "WHILE", "WHITE", "CCODE", "ANSI", "BLUE", 
  "BOLD", "BYTE", "FCALL", "CASE", "CHAR", "CYAN", "DATE", "DESC", "DOWN", 
  "TAB", "DROP", "ELSE", "EXEC", "EXIT", "FREE", "FROM", "GOTO", 
  "HELP_FILE", "LANG_FILE", "HELP", "HIDE", "HOUR", "INTO", "LAST", 
  "LEFT", "LIKE", "MAIN", "MENU", "MODE", "NEED", "NEXT", "NOCR", "OPEN", 
  "QUIT", "REAL", "ROWS", "SHOW", "SIZE", "SKIP", "SOME", "STEP", "STOP", 
  "TEMP", "TEXT", "THEN", "USER", "WAIT", "WHEN", "WITH", "WORK", "YEAR", 
  "KW_IS", "XSET", "ADD", "ALL", "ANY", "ASC", "AVG", "COLON", "DAY", 
  "DBA", "DEC", "DIM", "FKEY", "FOR", "KEY", "KWNO", "LET", "LOG", "XMAX", 
  "XMIN", "NOT", "PAD", "PUT", "RED", "ROW", "RUN", "SQL", "SUM", "TOP", 
  "USE", "ATSIGN", "AS_TIFF", "AS_GIF", "AS_PNG", "AS_JPEG", "AS", "AT", 
  "BY", "DOT", "GO", "IF", "IN", "OF", "ON", "TO", "UP", "FONT_NAME", 
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
  "formhandler_def", "@71", "@72", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@73", "@74", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@75", "@76", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@77", "@78", "@79", "@80", "@81", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", "field_name", 
  "cursor_name", "fetch_cursor_name", "win_name", "open_win_name", 
  "form_name", "open_form_name", "opt_help_no", "identifier", 
  "ident_or_var", "ident_p2", "var_or_string", "field_name2", "cvariable", 
  "real_number", "reserved_word", "goto_cmd", "check_menu_cmd", 
  "menu_item_list", "menu_item", "uncheck_menu_cmd", "disable_cmd", 
  "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
  "op_returning_msg", "gm_returning_msg", "op_caption", "gm_caption", 
  "op_icon", "gm_icon", "op_buttons", "gm_buttons", "op_def_but", 
  "if_cmd", "@83", "op_else", "@84", "@85", "@86", "import_m", 
  "module_import", "init_cmd", "@87", "init_tab_list", "init_tab", 
  "end_input", "opt_defs", "field_commands", "field_command", "@88", 
  "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", 
  "a_ins_or_delete_row", "a_ins_or_delete", "b_ins_or_delete_row", 
  "b_ins_or_delete", "bef_field_list", "aft_field_list", "next_field_cmd", 
  "next_form_cmd", "next_field", "input_cmd", "@97", "inp_rest", "@98", 
  "scroll_cmd", "up_or_down", "op_help", "on_key_command", "@99", 
  "key_val", "@100", "accept_key", "single_key_val", "@101", "key_do", 
  "key_value_list", "key_value", "@102", "key_value_1", "label_cmd", 
  "let_cmd", "@103", "@104", "op_expr_null", "linked_cmd", 
  "linked_del_cmd", "linked_upd_cmd", "locate_cmd", "module", "@105", 
  "op_module_header", "module_header", "module_entry", "func_main_def", 
  "func_or_main2", "at_term_cmd", "func_or_main", "module_code", 
  "op_code", "module_define_section", "ldeffunction", "func_def", "@106", 
  "@107", "@108", "@109", "end_func_command", "main_def", "@110", "@111", 
  "return_cmd", "op_fgl_expr_list", "db_section", 
  "module_globals_section", "actual_globals_section", "xglobals_entry", 
  "globals_entry", "@112", "glob_section", "mem_func_def", "@113", "@114", 
  "@115", "menu_cmd", "@116", "end_menu_command", "menu_block_command", 
  "@117", "@118", "@119", "menu_commands", "opt_key", "menu_opt_name", 
  "menu_optional_desc", "next_option_cmd", "show_option_cmd", 
  "hide_option_cmd", "opt_name", "opt_name_list", "menu_title", 
  "menu_def", "@120", "@121", "menu_handler_elements", 
  "menu_handler_element", "@122", "@123", "message_cmd", "msg_next", 
  "gui_message", "msg_start", "@124", "op_msg_wait", "msg_wait", 
  "variable", "var_int", "varsetidentdot", "var", "assoc_var_read", 
  "assoc_var_write", "assoc_sub", "dot_part_var", "array_r_variable", 
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
  "gui_prompt_cmd", "opt_char", "prompt_key_sec", "prompt_key_clause", 
  "on_key_command_prompt", "@126", "prompt_title", "put_cmd", "@127", 
  "put_from", "put_val_list", "put_val", "start_cmd", "rout", "rep_name", 
  "op_values", "output_cmd", "finish_cmd", "term_rep_cmd", 
  "report_section", "format_section", "format_actions", "format_action", 
  "@128", "@129", "@130", "@131", "@132", "@133", "@134", "report_cmd", 
  "need_command", "@135", "op_lines", "skip_command", "@136", 
  "opt_rep_expr_list", "xrep_expr_list", "xxrep_expr_list", 
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
  "fetch_statement", "@158", "@159", "fetch_part", "opt_into_fetch_part", 
  "@160", "opt_foreach_into_fetch_part", "@161", "fetch_place", 
  "delete_statement_position", "delete_statement_search_ss", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "var_ident_qchar", "sql_cmd", 
  "@162", "sql_commands", "privilege_definition", "op_with_grant_option", 
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
  "op_escape", "pattern", "escape_character", "in_predicate_ss", 
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
  "units_qual", "extend_qual", "sql_block_cmd", "@169", "sql_block", 
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
       0,   256,  1640,  1641,  1642,  1557,  1597,  1552,  1488,  1366,
    1474,  1470,  1384,  1547,  1283,  1341,  1415,  1583,  1570,  1503,
    1475,  1571,  1348,  1643,  1644,  1645,  1646,  1647,  1648,  1649,
    1650,  1651,  1652,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,
    1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,
    1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1192,  1193,  1194,  1195,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,
    1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1276,
    1277,  1278,  1279,  1280,  1281,  1282,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,  1342,  1343,  1344,  1345,  1346,  1347,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,
    1360,  1361,  1362,  1363,  1364,  1365,  1367,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,  1379,  1380,
    1381,  1382,  1383,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1409,  1410,  1411,
    1412,  1413,  1414,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1463,  1464,  1465,  1466,  1467,  1468,  1469,  1471,  1472,  1473,
    1476,  1477,  1478,  1479,  1480,  1481,  1482,  1483,  1484,  1485,
    1486,  1487,  1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,
    1497,  1498,  1499,  1500,  1501,  1502,  1504,  1505,  1506,  1507,
    1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1541,  1542,  1543,  1544,  1545,  1546,  1548,
    1549,  1550,  1551,  1553,  1554,  1555,  1556,  1558,  1559,  1560,
    1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,  1572,
    1573,  1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,
    1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1596,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633,  1634,
    1635,  1636,  1637,  1638,  1639
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   655,   656,   657,   658,   659,   660,   660,   661,   661,
     662,   663,   663,   663,   663,   663,   664,   664,   664,   664,
     664,   665,   665,   666,   666,   668,   667,   667,   669,   669,
     670,   670,   670,   670,   670,   670,   670,   670,   670,   670,
     670,   670,   670,   670,   670,   670,   671,   671,   673,   672,
     674,   674,   675,   675,   675,   675,   675,   675,   675,   675,
     675,   676,   677,   678,   677,   677,   677,   677,   677,   679,
     680,   677,   681,   682,   683,   677,   684,   685,   677,   686,
     687,   677,   688,   689,   690,   677,   691,   691,   692,   692,
     692,   693,   693,   694,   694,   695,   696,   696,   697,   697,
     699,   698,   700,   698,   701,   701,   702,   702,   703,   704,
     705,   704,   706,   707,   706,   709,   708,   711,   710,   712,
     712,   712,   712,   712,   712,   713,   714,   714,   715,   715,
     716,   717,   717,   718,   719,   721,   722,   720,   723,   723,
     724,   724,   725,   725,   726,   726,   726,   727,   727,   729,
     728,   730,   728,   731,   728,   732,   728,   733,   728,   734,
     734,   735,   735,   736,   736,   736,   736,   736,   736,   737,
     738,   738,   739,   739,   740,   740,   741,   741,   743,   744,
     742,   742,   742,   745,   745,   747,   746,   748,   748,   748,
     748,   748,   749,   748,   750,   750,   750,   750,   751,   752,
     752,   753,   753,   755,   754,   756,   754,   757,   757,   758,
     758,   759,   760,   760,   760,   761,   763,   762,   764,   762,
     765,   762,   766,   766,   767,   768,   769,   769,   771,   772,
     770,   773,   773,   773,   773,   773,   773,   773,   773,   773,
     773,   773,   773,   773,   773,   773,   773,   773,   773,   773,
     773,   773,   773,   773,   773,   773,   773,   773,   773,   774,
     775,   776,   777,   777,   778,   780,   779,   781,   781,   781,
     781,   781,   781,   781,   783,   782,   784,   784,   785,   785,
     786,   788,   787,   789,   789,   789,   789,   789,   789,   789,
     790,   791,   791,   793,   792,   794,   794,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   795,   797,
     796,   798,   796,   800,   799,   801,   799,   802,   802,   803,
     804,   804,   805,   806,   806,   806,   806,   806,   806,   806,
     806,   807,   808,   809,   811,   812,   810,   813,   813,   814,
     815,   815,   816,   816,   818,   817,   819,   817,   820,   817,
     821,   821,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   823,   823,   823,   823,   823,   823,   823,   823,   824,
     824,   825,   825,   825,   825,   825,   825,   825,   825,   825,
     825,   826,   826,   826,   826,   826,   826,   826,   826,   826,
     826,   827,   827,   828,   828,   829,   829,   830,   830,   831,
     831,   832,   833,   833,   834,   834,   834,   834,   834,   834,
     835,   835,   836,   836,   836,   836,   837,   837,   838,   839,
     839,   839,   840,   839,   841,   841,   842,   842,   843,   843,
     843,   843,   844,   844,   845,   845,   845,   845,   845,   845,
     845,   845,   846,   847,   848,   848,   848,   848,   848,   848,
     849,   849,   849,   849,   849,   849,   849,   850,   852,   853,
     851,   854,   855,   851,   857,   858,   856,   859,   860,   856,
     861,   862,   856,   863,   864,   856,   856,   856,   856,   856,
     865,   865,   866,   867,   867,   867,   867,   867,   867,   867,
     867,   867,   868,   868,   869,   869,   869,   869,   870,   870,
     870,   871,   871,   872,   872,   872,   873,   873,   873,   873,
     873,   873,   873,   873,   873,   873,   874,   874,   875,   875,
     877,   878,   876,   879,   879,   881,   882,   883,   880,   885,
     886,   884,   887,   887,   888,   888,   889,   889,   891,   890,
     892,   890,   893,   893,   894,   894,   896,   895,   897,   895,
     898,   899,   899,   899,   900,   900,   901,   901,   902,   902,
     903,   903,   905,   904,   906,   904,   907,   904,   908,   904,
     909,   904,   910,   911,   911,   911,   911,   911,   911,   912,
     912,   913,   914,   915,   916,   916,   916,   916,   916,   916,
     916,   916,   917,   918,   919,   920,   921,   922,   923,   923,
     924,   925,   926,   926,   927,   927,   928,   928,   928,   928,
     928,   928,   929,   930,   930,   931,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   931,   931,
     931,   931,   931,   931,   931,   931,   931,   931,   932,   933,
     934,   934,   935,   936,   937,   937,   937,   938,   938,   938,
     940,   939,   941,   941,   942,   942,   943,   943,   944,   945,
     945,   946,   947,   947,   948,   949,   949,   950,   951,   951,
     953,   952,   954,   955,   954,   956,   957,   954,   958,   958,
     959,   961,   960,   960,   962,   962,   963,   963,   964,   964,
     965,   965,   966,   966,   968,   967,   969,   967,   970,   967,
     971,   967,   972,   967,   973,   967,   974,   967,   975,   967,
     976,   967,   977,   977,   978,   978,   979,   979,   980,   980,
     981,   981,   982,   982,   983,   984,   985,   985,   985,   987,
     986,   988,   988,   989,   988,   990,   991,   991,   991,   991,
     992,   992,   994,   993,   993,   996,   995,   997,   999,   998,
    1000,  1000,  1001,  1001,  1003,  1002,  1004,  1004,  1004,  1004,
    1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,  1004,
    1004,  1004,  1004,  1005,  1007,  1008,  1006,  1009,  1009,  1010,
    1011,  1012,  1013,  1013,  1015,  1014,  1016,  1016,  1017,  1017,
    1018,  1018,  1018,  1018,  1019,  1019,  1020,  1020,  1021,  1022,
    1022,  1022,  1022,  1022,  1022,  1022,  1022,  1022,  1022,  1022,
    1023,  1023,  1024,  1024,  1024,  1025,  1026,  1026,  1028,  1029,
    1030,  1031,  1027,  1032,  1034,  1035,  1033,  1036,  1037,  1037,
    1038,  1039,  1040,  1040,  1041,  1041,  1041,  1043,  1042,  1044,
    1044,  1046,  1047,  1048,  1045,  1050,  1049,  1051,  1053,  1052,
    1054,  1052,  1055,  1052,  1056,  1056,  1057,  1057,  1058,  1058,
    1059,  1059,  1059,  1060,  1061,  1062,  1063,  1063,  1063,  1064,
    1064,  1065,  1065,  1067,  1068,  1066,  1069,  1069,  1071,  1070,
    1072,  1070,  1073,  1074,  1074,  1074,  1074,  1075,  1075,  1075,
    1075,  1075,  1077,  1076,  1078,  1078,  1079,  1080,  1081,  1081,
    1082,  1083,  1083,  1083,  1083,  1083,  1084,  1085,  1086,  1086,
    1087,  1087,  1088,  1089,  1090,  1090,  1091,  1091,  1092,  1093,
    1094,  1094,  1094,  1094,  1094,  1095,  1095,  1096,  1097,  1097,
    1098,  1098,  1099,  1099,  1100,  1100,  1101,  1101,  1101,  1101,
    1101,  1102,  1102,  1103,  1103,  1104,  1104,  1105,  1106,  1107,
    1107,  1108,  1109,  1109,  1109,  1110,  1111,  1111,  1112,  1112,
    1113,  1114,  1114,  1115,  1115,  1116,  1117,  1118,  1119,  1119,
    1120,  1121,  1121,  1122,  1122,  1123,  1123,  1124,  1125,  1125,
    1126,  1126,  1126,  1126,  1127,  1127,  1127,  1128,  1129,  1129,
    1130,  1130,  1130,  1131,  1132,  1132,  1133,  1133,  1133,  1133,
    1133,  1133,  1133,  1133,  1133,  1133,  1133,  1133,  1133,  1133,
    1133,  1133,  1133,  1133,  1133,  1133,  1133,  1133,  1134,  1135,
    1135,  1136,  1136,  1137,  1139,  1138,  1140,  1141,  1141,  1142,
    1142,  1143,  1143,  1145,  1144,  1146,  1148,  1147,  1149,  1149,
    1150,  1150,  1151,  1151,  1152,  1152,  1152,  1152,  1153,  1153,
    1154,  1155,  1155,  1156,  1157,  1158,  1159,  1160,  1160,  1161,
    1161,  1163,  1162,  1164,  1162,  1165,  1162,  1166,  1162,  1167,
    1162,  1168,  1162,  1169,  1162,  1170,  1170,  1170,  1170,  1170,
    1170,  1172,  1171,  1173,  1173,  1175,  1174,  1174,  1174,  1174,
    1174,  1176,  1176,  1177,  1177,  1178,  1179,  1179,  1180,  1181,
    1182,  1183,  1183,  1183,  1184,  1184,  1184,  1184,  1185,  1186,
    1186,  1187,  1187,  1188,  1189,  1189,  1189,  1189,  1189,  1189,
    1189,  1189,  1190,  1190,  1191,  1191,  1192,  1192,  1192,  1192,
    1192,  1192,  1192,  1192,  1192,  1192,  1193,  1193,  1194,  1194,
    1194,  1194,  1195,  1195,  1196,  1196,  1197,  1197,  1197,  1197,
    1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,
    1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,  1197,
    1198,  1198,  1198,  1200,  1201,  1202,  1203,  1204,  1205,  1199,
    1206,  1206,  1207,  1208,  1208,  1210,  1211,  1212,  1213,  1214,
    1215,  1209,  1216,  1218,  1219,  1220,  1217,  1221,  1221,  1221,
    1221,  1222,  1222,  1222,  1222,  1222,  1223,  1224,  1224,  1224,
    1225,  1225,  1227,  1228,  1226,  1229,  1230,  1226,  1231,  1231,
    1232,  1232,  1233,  1233,  1234,  1234,  1234,  1235,  1235,  1236,
    1236,  1237,  1237,  1238,  1239,  1239,  1240,  1240,  1240,  1240,
    1240,  1240,  1240,  1241,  1241,  1242,  1242,  1243,  1243,  1244,
    1244,  1245,  1245,  1246,  1247,  1247,  1248,  1248,  1249,  1250,
    1250,  1251,  1252,  1252,  1253,  1253,  1254,  1254,  1255,  1256,
    1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,  1256,
    1257,  1257,  1258,  1258,  1259,  1260,  1262,  1261,  1264,  1263,
    1263,  1265,  1265,  1266,  1266,  1267,  1267,  1268,  1268,  1270,
    1271,  1269,  1272,  1272,  1273,  1274,  1273,  1275,  1276,  1275,
    1277,  1277,  1277,  1277,  1277,  1277,  1277,  1277,  1278,  1279,
    1280,  1281,  1281,  1282,  1283,  1283,  1284,  1284,  1284,  1285,
    1286,  1287,  1287,  1288,  1289,  1289,  1291,  1290,  1292,  1292,
    1292,  1292,  1292,  1292,  1292,  1292,  1292,  1292,  1292,  1292,
    1293,  1294,  1294,  1295,  1295,  1296,  1296,  1297,  1297,  1297,
    1297,  1298,  1298,  1299,  1299,  1300,  1300,  1301,  1301,  1302,
    1303,  1303,  1304,  1304,  1305,  1305,  1306,  1307,  1308,  1309,
    1310,  1310,  1311,  1311,  1312,  1312,  1313,  1313,  1314,  1314,
    1314,  1315,  1315,  1316,  1317,  1317,  1318,  1318,  1319,  1319,
    1320,  1320,  1320,  1320,  1321,  1322,  1323,  1324,  1324,  1325,
    1325,  1326,  1327,  1328,  1328,  1329,  1330,  1331,  1331,  1332,
    1332,  1332,  1333,  1333,  1334,  1334,  1335,  1336,  1336,  1337,
    1337,  1338,  1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,
    1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,  1347,  1347,
    1347,  1347,  1348,  1348,  1349,  1349,  1350,  1350,  1351,  1351,
    1351,  1351,  1351,  1351,  1351,  1352,  1352,  1352,  1352,  1352,
    1352,  1352,  1352,  1353,  1353,  1353,  1354,  1354,  1354,  1354,
    1355,  1355,  1355,  1356,  1356,  1357,  1357,  1357,  1357,  1357,
    1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,  1357,
    1357,  1357,  1358,  1358,  1359,  1359,  1359,  1359,  1359,  1360,
    1361,  1362,  1363,  1363,  1363,  1363,  1364,  1365,  1365,  1365,
    1366,  1366,  1367,  1367,  1367,  1368,  1369,  1369,  1369,  1369,
    1369,  1370,  1371,  1372,  1372,  1373,  1373,  1374,  1374,  1374,
    1374,  1374,  1374,  1374,  1374,  1375,  1375,  1375,  1375,  1375,
    1375,  1375,  1375,  1376,  1376,  1376,  1376,  1376,  1376,  1376,
    1377,  1377,  1377,  1377,  1377,  1377,  1377,  1378,  1378,  1379,
    1381,  1380,  1382,  1380,  1383,  1380,  1384,  1380,  1385,  1385,
    1385,  1386,  1386,  1387,  1387,  1387,  1388,  1388,  1389,  1389,
    1390,  1392,  1393,  1391,  1394,  1395,  1395,  1396,  1397,  1397,
    1397,  1397,  1397,  1398,  1399,  1399,  1400,  1401,  1402,  1402,
    1402,  1402,  1403,  1403,  1404,  1404,  1404,  1405,  1406,  1406,
    1406,  1407,  1407,  1407,  1407,  1407,  1408,  1408,  1408,  1408,
    1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,
    1408,  1408,  1408,  1408,  1408,  1408,  1409,  1409,  1410,  1410,
    1411,  1412,  1412,  1413,  1413,  1414,  1414,  1415,  1415,  1416,
    1416,  1417,  1418,  1418,  1419,  1419,  1420,  1421,  1421,  1421,
    1422,  1422,  1423,  1424,  1425,  1426,  1427,  1427,  1428,  1428,
    1428,  1428,  1428,  1428,  1429,  1429,  1429,  1431,  1430,  1432,
    1432,  1433,  1433,  1433,  1434,  1435,  1437,  1438,  1436,  1439,
    1439,  1439,  1440,  1440,  1440,  1440,  1440,  1440,  1441,  1441,
    1442,  1443,  1444,  1444,  1445,  1445,  1446,  1446,  1447,  1447,
    1447,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,  1448,
    1448,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1449,
    1449,  1449,  1449,  1449,  1449,  1450,  1451,  1451,  1452,  1453,
    1453,  1454,  1454,  1454,  1454,  1455,  1455,  1455,  1456,  1456,
    1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1457,  1458,
    1458,  1458,  1458,  1458,  1459,  1459,  1460,  1462,  1463,  1461,
    1464,  1464,  1465,  1465,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1467,  1467,  1468,  1468,  1469,  1469,  1470,  1470,  1471,
    1471,  1472,  1473,  1474,  1475,  1475,  1476,  1477,  1477,  1478,
    1479,  1479,  1481,  1480,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,
    1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482,  1482
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     5,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     5,     6,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     5,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     3,     0,     7,     8,     6,     1,     6,     0,
       0,     9,     0,     0,     0,     8,     0,     0,    10,     0,
       0,     9,     0,     0,     0,    14,     0,     2,     0,     2,
       1,     0,     1,     1,     3,     1,     1,     1,     1,     3,
       0,     6,     0,     5,     1,     2,     1,     2,     1,     0,
       0,     3,     0,     0,     3,     0,     4,     0,     4,     2,
       2,     2,     1,     2,     2,     3,     1,     1,     1,     2,
       1,     1,     2,     1,     1,     0,     0,     5,     7,     8,
       0,     2,     1,     3,     1,     3,     3,     1,     2,     0,
       4,     0,     4,     0,     3,     0,     3,     0,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     1,     1,     0,     1,     1,     2,     0,     0,
       5,     1,     1,     1,     3,     0,     2,     4,     4,     4,
       4,     2,     0,     4,     1,     1,     1,     2,     1,     1,
       3,     0,     1,     0,     7,     0,    12,     1,     1,     1,
       1,     1,     5,     3,     1,     1,     0,     4,     0,     5,
       0,     7,     1,     3,     1,     1,     0,     1,     0,     0,
       4,     1,     1,     1,     4,     4,     6,     1,     2,     1,
       1,     1,     1,     4,     6,     1,     4,     6,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     4,
       1,     1,     0,     3,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     2,     0,     2,     0,     3,     0,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     1,     0,     5,     1,     1,     1,     4,     4,
       6,     1,     1,     1,     1,     4,     6,     1,     4,     6,
       1,     1,     1,     1,     1,     2,     2,     1,     4,     0,
       7,     0,    12,     0,     4,     0,     5,     1,     3,     2,
       1,     3,     1,     0,     2,     2,     1,     2,     5,     4,
       2,     4,     5,     3,     0,     0,    11,     0,     2,     1,
       0,     2,     1,     2,     0,     3,     0,     3,     0,     3,
       4,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     1,     1,     3,     4,     4,
       2,     2,     1,     1,     1,     1,     1,     3,     1,     2,
       2,     1,     0,     3,     2,     2,     1,     3,     4,     4,
       5,     5,     1,     1,     2,     2,     4,     4,     2,     2,
       4,     4,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     0,     0,     0,
       6,     0,     0,     8,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     5,     5,     5,     7,
       0,     3,     1,     1,     4,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     4,     4,     2,     2,     2,     2,
       2,     1,     1,     2,     1,     1,     1,     2,     4,     6,
       6,     3,     5,     5,     3,     1,     1,     3,     1,     3,
       0,     0,    11,     0,     2,     0,     0,     0,     8,     0,
       0,    10,     0,     1,     0,     1,     1,     2,     0,     3,
       0,     3,     0,     1,     1,     2,     0,     3,     0,     3,
       3,     1,     4,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     0,     3,     0,     3,     0,     4,     0,     4,
       0,     4,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     4,     6,     4,     3,     6,
       3,     6,     1,     1,     1,     1,     1,     1,     0,     2,
       1,     1,     1,     4,     1,     1,     1,     4,     3,     6,
       3,     6,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     3,     1,     2,     2,     2,     4,     2,     2,     4,
       0,     8,     0,     1,     1,     1,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     0,     1,     3,     0,     2,
       0,     7,     0,     0,     3,     0,     0,     7,     5,     2,
       2,     0,     5,     4,     1,     3,     3,     3,     0,     2,
       0,     1,     1,     2,     0,     4,     0,     4,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     4,
       0,     4,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     3,     2,     4,     1,     1,     1,     0,
       4,     5,     6,     0,    10,     3,     1,     1,     2,     2,
       0,     2,     0,     3,     1,     0,     3,     2,     0,     3,
       1,     3,     1,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     0,     7,     1,     1,     2,
       2,     2,     3,     4,     0,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     0,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     0,     0,
       0,     0,    13,     1,     0,     0,     6,     2,     1,     2,
       2,     1,     1,     2,     1,     1,     1,     0,     3,     2,
       1,     0,     0,     0,    14,     0,     5,     1,     0,     3,
       0,     7,     0,     5,     1,     2,     0,     1,     1,     1,
       0,     1,     1,     2,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     0,     0,     7,     1,     2,     0,     3,
       0,     4,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     3,     0,     1,     1,     1,     1,     2,
       2,     2,     5,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     2,     2,     3,     6,     1,     3,     1,     1,
       1,     3,     6,     1,     1,     1,     1,     2,     0,     1,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     2,     0,     1,     1,     4,     1,     3,     1,     3,
       7,     0,     7,     0,     6,     3,     1,     3,     1,     2,
       5,     0,     7,     0,     2,     0,     1,     5,     2,     5,
       0,     5,     6,     4,     0,     1,     1,     4,     0,     2,
       0,     5,     4,     2,     1,     3,     2,     2,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     2,     4,     1,     0,    10,     5,     0,     1,     0,
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
       0,     5,     2,     1,     0,     0,     3,     0,     0,     3,
       1,     1,     1,     1,     1,     1,     2,     2,     4,     3,
       3,     1,     3,     2,     1,     1,     0,     1,     1,     1,
       1,     0,     1,     3,     1,     1,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     0,     1,     1,     1,     1,     3,     1,     1,     1,
       2,     0,     3,     1,     3,     1,     3,     1,     1,     6,
       0,     3,     1,     3,     0,     1,     4,     5,     2,     1,
       1,     4,     1,     3,     4,     4,     1,     3,     1,     1,
       1,     2,     1,     4,     0,     1,     0,     1,     1,     2,
       1,     1,     1,     4,     3,     1,     1,     1,     2,     1,
       1,     2,     2,     1,     3,     2,     2,     1,     3,     1,
       2,     4,     1,     2,     1,     3,     4,     0,     1,     0,
       1,     0,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     2,     2,     0,     2,     1,     1,     1,     5,     3,
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
       1,     1,     1,     3,     1,     2,     2,     1,     1,     2,
       2,     1,     1,     1,     2,     4,     3,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     3,     0,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     0,     4,     1,
       2,     1,     1,     1,     2,     2,     0,     0,     6,     0,
       2,     2,     7,     3,     3,     2,     2,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     2,
       2,     1,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     3,     3,     5,     5,     5,     5,
       5,     4,     4,     3,     4,     1,     1,     3,     1,     2,
       1,     1,     1,     3,     5,     1,     1,     1,     1,     3,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     1,
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
     816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1793,     0,     0,     0,   867,   178,   840,   845,   176,   181,
     820,     0,   814,   817,   818,   821,   823,   866,   822,   861,
     862,   864,   182,   133,   130,     0,   126,   128,   127,   131,
    1836,   710,   610,  1799,     0,     0,  1802,     0,  1798,  1795,
    1792,  1790,  1791,  1797,  1796,  1794,   293,  1598,  1597,   860,
     174,   185,   177,   182,     1,   824,   819,   865,   863,   841,
     125,   129,   132,  1806,  1803,     0,  1804,  1801,     0,     0,
     589,     0,     0,   175,   870,   934,   590,   868,   622,   927,
       0,   928,   935,   933,   185,   179,   198,     0,   183,   199,
     228,     0,   847,  1215,     0,     0,   846,   134,  1203,   854,
       0,     0,   837,   839,   836,   838,   815,   825,   826,   848,
     829,   830,   831,   834,   832,   833,   835,  1805,  1800,     0,
     929,   869,     0,     0,   942,   940,   941,   931,   930,   291,
     185,  1139,   192,   186,   185,   191,   225,     0,   709,     0,
       0,     0,     0,   174,   539,   903,   827,     0,   325,   311,
     201,   262,   281,   302,   304,   301,     0,   323,     0,   310,
     303,   307,   313,   297,   312,   185,   314,   294,   317,   295,
     296,   939,   938,     0,    21,    22,    13,     0,   948,     0,
      15,     0,   946,     0,   292,     0,   184,  1140,   180,     0,
     198,   200,   258,   252,   253,   241,   218,   249,   201,   220,
     262,   281,   239,   242,   237,     0,   216,     0,   248,   240,
     245,   251,   233,   250,   185,   254,   185,   231,   232,   229,
     257,     0,     0,     0,     0,   855,   174,   174,     0,     0,
     202,     0,   315,     0,     0,   316,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   936,     0,    16,    17,
      19,    18,    20,     0,    14,     0,   944,     0,   623,   187,
     190,     0,   188,   189,     0,   195,   194,   193,   196,   185,
       0,   185,   255,   256,     0,     0,   185,     0,     0,     0,
       0,   238,   226,  1216,     0,     0,  1204,  1842,   540,   904,
     849,     0,   207,   208,     0,   274,   276,   271,   272,   268,
     270,   267,   269,   266,     0,   276,   287,   288,   284,   286,
     283,   285,   278,     0,     0,     0,   327,     0,   330,   332,
     215,     0,   214,     0,     0,   185,    11,    12,   947,     0,
     932,   624,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   227,   230,   958,   708,   871,   958,     0,
    1840,  1842,  1139,  1694,   842,     0,   958,     0,     0,   263,
       0,     0,   273,   290,   264,   289,     0,   282,     0,   305,
       0,   299,     0,   324,     0,   329,   319,     0,     0,   308,
     298,   261,   318,     0,     0,     0,     0,     0,   243,     0,
     235,   217,   203,     0,   246,   234,   259,   964,     0,   959,
     960,   958,     0,   856,  1841,  1839,     0,     0,     0,     0,
       0,     0,     0,     0,  1823,     0,  1305,  1304,     0,  1306,
       0,   375,  1303,  1245,     0,     5,  1302,   376,   373,     0,
     378,   172,   467,  1117,     0,     0,  1312,   122,   372,   371,
    1237,   366,     0,  1262,  1814,     0,   377,   344,     0,     3,
       2,     0,   374,  1242,     0,     0,   367,   364,   379,     0,
       0,     0,     0,  1310,  1300,   370,     0,     0,     0,     0,
       0,     0,     0,     0,  1299,     0,     0,     0,   173,  1239,
     363,   362,     0,     0,  1818,  1817,     0,     0,     0,   135,
    1238,   369,   368,     0,     0,   365,   922,   467,     0,   535,
       0,     0,     0,   467,     0,     0,     0,   467,   803,  1213,
       0,     0,  1121,     0,  1807,     0,   102,     0,     0,   875,
       0,     0,     0,     0,   804,     0,     0,  1717,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   680,     0,     0,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,  1855,  1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,
    1864,  1865,  1866,  1867,  1868,  1869,  1870,  1871,  1872,  1873,
    1874,  1875,  1876,  1877,  1878,  1879,  1880,  1881,  1882,  1883,
    1884,  1885,  1886,  1887,  1888,  1889,  1890,   913,  1891,  1892,
    1893,  1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,
    1903,  1904,  1905,  1906,  1907,  1108,  1110,  1105,  1107,  1106,
    1109,  1908,  1909,  1236,  1910,  1241,  1240,  1911,  1912,  1913,
    1914,  1915,  1916,  1917,  1918,  1919,  1920,  1366,  1921,  1922,
    1923,  1924,  1925,  1926,  1927,  1928,  1843,   843,   544,   844,
       0,   908,     0,   906,     0,   326,   209,   210,     0,   275,
     280,     0,     0,     0,     0,   328,   331,     0,   213,     0,
     945,   219,     0,   185,     0,     0,     0,     0,     0,  1217,
       0,     0,  1205,     0,     0,  1249,   611,   612,   828,  1080,
    1085,  1816,   604,   121,     0,     0,  1782,  1781,  1018,  1778,
    1780,  1831,     0,  1256,     0,  1252,  1261,     7,     0,     6,
       0,  1824,  1081,     0,  1173,  1172,  1120,  1171,  1119,     0,
       0,   422,   424,     0,  1210,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1565,     0,     0,     0,   416,
       0,     0,     0,     0,   415,     0,     0,   432,     0,   503,
       0,     0,     0,     0,     0,     0,     0,   411,  1313,     0,
     382,   381,   388,   428,   425,   383,   501,   493,   384,   386,
     500,   387,   934,   423,   426,   431,  1301,   502,  1696,  1307,
     123,     0,  1084,   120,     0,   810,    23,   606,   380,     0,
     809,  1077,   811,     0,  1311,   897,   896,   899,   895,   898,
    1833,     0,   893,     0,   605,   991,   894,  1827,     0,  1815,
     119,   988,   711,   986,     0,   602,  1810,   757,   756,     0,
     758,   594,   754,     0,     0,  1001,   607,  1365,  1361,  1364,
       0,     0,  1053,  1051,     0,  1045,  1047,  1046,  1044,  1043,
       0,     0,     0,  1042,     0,   784,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1032,  1023,  1024,
       0,  1065,   409,    23,   857,   401,  1821,     0,  1812,   124,
     603,     0,  1050,  1049,  1214,  1212,  1138,     0,  1685,  1686,
    1139,  1227,  1139,  1122,  1123,  1126,  1141,  1314,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,   934,
       0,    67,     0,   100,   582,   668,     0,  1111,  1008,  1115,
       0,     0,  1066,  1231,     0,     0,  1118,   672,   669,   670,
       0,   674,   675,     0,   677,   678,     0,   673,   968,   970,
       0,     0,   969,   759,   966,   720,   962,   926,     0,     0,
       0,     0,   684,   685,     0,     0,   924,   920,   921,   917,
     918,   919,   912,   916,   915,     0,     0,     0,     0,     0,
       0,   548,   550,   542,   545,   546,   910,  1842,   905,   907,
     850,     0,   277,   279,   306,   300,     0,     0,   309,     0,
     224,     0,   222,   244,   236,   228,   247,   965,   174,   961,
     872,   174,     0,     0,     0,  1289,  1290,     0,     0,     0,
    1263,  1264,  1266,  1267,  1268,  1272,  1271,  1269,  1270,     0,
       0,  1779,   943,     0,  1020,     0,     0,  1255,  1254,     0,
    1248,     0,  1543,  1544,     0,  1082,     0,    23,  1168,  1170,
    1169,   390,   389,     0,     0,  1145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   430,  1573,  1571,  1572,  1568,
    1570,  1567,  1569,  1561,     0,     0,     0,     0,     0,   429,
       0,     0,   507,   506,     0,     0,   477,   474,   483,     0,
     480,     0,     0,   414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   163,   164,   165,   166,   167,   168,   508,   509,   510,
     443,     0,     0,   442,   452,     0,     0,   394,     0,     0,
     395,   385,   391,   393,   396,   397,   398,   399,   400,   392,
     421,   420,   468,     0,     0,   978,     0,     0,   349,    24,
     343,     0,     0,  1074,     0,     0,     0,     0,     0,     0,
       0,   995,  1695,     0,     0,   185,     0,     0,     0,  1812,
       0,     0,     0,     0,     0,   136,     0,     0,  1005,   997,
     998,  1003,  1362,  1363,   923,   333,   407,     0,   536,   587,
     586,   584,  1026,   588,  1031,  1027,  1030,   777,     0,  1028,
    1029,   778,  1036,  1040,  1033,  1034,  1038,  1039,  1037,  1035,
    1041,     0,   812,     0,     0,     0,   404,   405,   402,   403,
       0,     0,     0,   767,   766,   765,  1813,  1820,    23,  1134,
    1135,  1136,  1137,  1131,  1129,  1228,  1143,  1128,  1124,     0,
       0,  1125,  1808,     0,     0,     0,     0,    96,     0,    97,
       0,     0,     0,    72,     0,     0,     0,   109,   104,     0,
     902,     0,   901,     0,   467,  1113,     0,   953,   954,   977,
     949,   950,   805,   975,  1068,  1233,     0,  1235,  1234,  1721,
       0,     0,     0,  1719,  1722,  1723,   700,     0,     0,     0,
     689,   720,   720,   718,     0,     0,   721,     0,    25,   688,
     691,     0,   698,   694,   925,   914,  1692,  1693,  1683,  1683,
       0,     0,  1599,     0,   185,  1315,     0,     0,  1316,  1359,
     185,     0,  1360,     0,  1638,     0,  1329,     0,  1377,  1376,
    1375,  1373,  1374,  1372,  1370,  1367,  1440,  1439,  1368,  1369,
    1378,  1608,  1371,  1699,  1698,  1697,  1379,  1842,  1842,   561,
     552,   543,     0,   547,  1842,   909,   174,     0,   320,   212,
       0,   185,   221,   204,  1218,   174,  1206,  1431,     0,  1430,
       0,     0,  1432,  1292,     0,  1298,  1294,  1291,     0,     0,
       0,     0,     0,     0,  1288,  1284,  1420,  1419,  1418,  1260,
    1259,     0,  1283,  1279,     0,  1275,  1273,     0,   615,     0,
     614,     0,  1019,     0,     0,  1017,  1785,  1787,  1786,  1783,
    1832,  1829,  1253,     0,     0,     0,  1246,   467,   341,     0,
     528,  1211,     0,     0,     0,     0,  1638,     0,     0,     0,
       0,     0,   525,   511,   516,     0,   512,   515,   514,     0,
       0,     0,     0,     0,     0,   417,     0,   170,     0,   433,
       0,     0,     0,     0,     0,     0,     0,     0,   435,   434,
     453,   444,   459,   462,   463,   460,   466,   465,   464,   454,
     455,   457,   456,   458,   445,   449,   467,   461,   448,   467,
      91,     0,   427,     0,  1243,  1010,  1078,  1079,  1076,  1075,
       0,   900,     0,     0,   591,     0,     0,     0,   989,   987,
       0,   713,   714,     0,     0,  1811,  1819,     0,     0,   598,
       0,   600,   755,     0,   140,     0,   999,  1006,     0,     0,
    1014,     0,   336,     0,     0,     0,     0,    23,  1052,  1337,
       0,     0,   802,   789,   800,   801,   787,   788,   796,   791,
     795,   790,   799,   794,   797,   793,   798,   786,   792,   785,
     784,  1025,   813,   410,     0,  1057,     0,  1822,   768,   769,
     360,     0,  1139,     0,  1142,  1127,  1842,     0,     0,     0,
       0,     0,     0,     0,    62,    91,     0,     0,   115,   110,
       0,   105,     0,   112,   106,   886,   878,   884,     0,  1112,
       0,  1114,  1116,     0,     0,   957,     0,     0,     0,     0,
    1067,  1232,  1788,  1724,   973,  1725,   971,  1718,  1720,  1842,
     671,   676,   679,   692,   690,   608,     0,     0,     0,   736,
     774,   734,   730,   728,   772,     0,     0,   760,     0,   722,
     732,   967,   963,     0,     0,     0,     0,   697,     0,     0,
       0,     0,     0,     0,     0,  1546,     0,  1435,  1436,  1704,
    1400,  1457,     0,     0,  1702,     0,     0,  1640,  1641,  1639,
    1621,  1726,     0,  1383,  1389,  1388,  1387,  1391,     0,  1384,
    1385,     0,  1609,  1620,   549,   551,     0,     0,   564,   556,
     558,     0,   553,   554,     0,     0,   572,   574,     0,     0,
     570,   911,   851,   211,     0,     0,   223,  1174,   873,  1152,
    1408,  1410,     0,  1296,     0,     0,     0,     0,     0,  1286,
       0,     0,  1538,  1536,  1523,  1525,  1521,     0,  1520,     0,
    1529,  1516,  1537,     0,  1528,  1513,  1519,  1535,  1527,  1424,
    1510,  1511,  1512,     0,  1281,  1277,     0,     0,  1265,   613,
       0,     0,     0,     0,     0,  1828,     4,     8,    10,  1542,
    1545,     0,   467,     0,   499,   496,   495,   498,   494,     0,
     419,   505,   490,   490,     0,   513,     0,   517,     0,   281,
    1210,     0,  1566,   497,  1210,   504,   418,   265,     0,  1210,
     478,   475,   484,  1210,   481,  1210,  1210,  1210,     0,     0,
       0,     0,     0,     0,     0,     0,   469,    92,    93,    95,
     471,     0,     0,     0,  1007,     0,     0,     0,     0,     0,
       0,     0,   185,   712,     0,   595,   597,     0,     0,   157,
     155,     0,     0,   137,     0,   147,   153,   720,   142,   144,
       0,  1004,  1015,  1016,     0,   408,   335,   340,   593,   334,
       0,   337,   342,  1338,   537,   585,   583,   784,   779,   780,
    1056,  1058,     0,   406,   361,  1132,  1130,  1229,  1230,     0,
       0,  1223,     0,     0,     0,    98,     0,     0,    73,    79,
      69,  1842,  1842,   108,   103,   117,   113,     0,   107,   775,
     887,   608,  1842,   877,   876,   885,  1009,     0,     0,   955,
     956,   951,   976,   467,     0,     0,  1665,  1556,  1559,  1666,
    1563,  1557,  1663,     0,     0,  1073,  1662,     0,     0,  1664,
       0,     0,     0,     0,     0,  1782,  1558,  1069,  1070,  1661,
    1560,  1653,  1072,  1648,  1651,  1652,     0,     0,     0,   702,
     695,   693,     0,    23,     0,   750,   724,   752,   726,  1842,
    1842,  1842,  1842,   784,   745,   744,   740,   742,   749,   748,
     738,   746,   719,   723,  1842,   608,    45,    43,    40,    34,
      38,    42,    37,    30,    39,    33,    36,    31,    41,    32,
      44,    35,     0,    28,     0,   699,  1684,     0,  1682,  1638,
    1680,  1625,  1626,  1618,  1604,  1619,     0,     0,     0,  1048,
    1434,  1437,     0,     0,     0,     0,  1458,  1349,  1321,  1707,
    1706,  1705,     0,     0,     0,     0,  1344,     0,  1343,     0,
    1345,  1340,  1341,  1342,  1333,  1330,     0,     0,  1390,     0,
       0,     0,  1613,  1610,  1611,   563,   568,     0,     0,  1842,
    1842,   541,   555,   578,   566,   580,  1842,  1842,   576,   560,
     571,   842,   321,   205,     0,  1200,  1219,   842,     0,  1207,
    1200,     0,     0,  1293,     0,     0,     0,     0,     0,  1463,
    1465,  1467,  1505,  1504,  1503,  1469,  1486,  1295,     0,  1547,
       0,  1409,     0,  1412,  1550,     0,  1416,     0,  1285,     0,
       0,  1589,  1587,  1588,  1584,  1586,  1583,  1585,     0,     0,
       0,     0,     0,     0,     0,     0,  1422,     0,  1425,  1426,
       0,  1280,     0,  1274,  1276,  1784,     0,     0,     0,  1830,
       0,     0,  1257,   858,     0,   529,     0,  1642,  1644,   487,
       0,   488,     0,   527,     0,   524,   521,   492,   486,  1148,
    1574,  1147,     0,   169,  1146,     0,     0,     0,  1149,     0,
    1151,  1150,  1144,   446,   447,   451,   436,     0,   439,   450,
       0,   438,     0,     0,    91,     0,     0,     0,     0,  1308,
    1835,  1834,   592,     0,     0,    46,     0,   717,   716,   715,
    1309,     0,     0,   720,  1842,  1842,   149,   616,   159,   151,
     161,   141,   148,  1842,     0,     0,     0,     0,     0,     0,
       0,  1842,     0,   782,   608,     0,  1809,     0,    91,     0,
      63,     0,     0,     0,    76,     0,    91,    91,   116,   111,
    1842,  1842,   101,   784,   888,   882,   890,   889,   879,   533,
     937,     0,     0,  1650,  1649,  1562,     0,  1638,     0,     0,
    1506,     0,  1506,  1506,  1506,  1506,  1654,     0,     0,     0,
       0,     0,     0,  1708,  1709,  1710,  1711,  1712,  1713,  1657,
    1789,   974,   972,   705,   703,     0,   682,   696,   609,   761,
       0,     0,  1842,     0,  1842,   737,   735,   731,   729,   773,
       0,  1842,     0,  1842,   733,    23,     0,    26,     0,  1687,
       0,  1608,     0,     0,  1617,  1600,  1616,  1438,     0,  1402,
       0,  1348,  1445,     0,     0,  1703,     0,  1700,  1622,     0,
       0,     0,     0,     0,     0,  1727,  1347,  1346,  1334,  1332,
       0,  1393,     0,  1386,     0,     0,     0,     0,   565,   562,
     557,   559,     0,  1842,  1842,   573,   575,  1842,  1842,     0,
       0,  1198,  1199,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1197,     0,     0,  1185,  1186,  1187,
    1184,  1189,  1190,  1191,  1188,  1175,  1166,     0,     0,  1222,
       0,  1842,     0,  1161,     0,     0,     0,     0,     0,     0,
       0,  1153,  1154,     0,  1086,     0,  1297,     0,  1472,     0,
    1486,  1471,  1468,     0,  1433,     0,  1500,  1497,  1498,  1495,
    1502,  1501,  1496,  1499,  1678,     0,  1678,  1487,     0,     0,
       0,  1551,     0,  1552,     0,     0,     0,     0,  1415,  1287,
    1414,  1406,     0,     0,     0,  1540,  1532,  1532,     0,     0,
    1532,  1539,     0,  1556,  1421,  1423,  1427,  1428,  1282,  1278,
    1022,     0,   985,     9,     0,  1250,   859,  1083,     0,     0,
    1457,  1628,   646,   631,   644,   650,   665,   630,   642,   625,
     658,   661,   664,   628,   659,   637,   641,   652,   663,   660,
     662,   653,   635,   633,   657,   639,   638,   626,   627,   629,
     632,   643,   655,   634,   667,   645,   649,   651,   666,   640,
     654,   656,   636,   647,   648,  1646,  1645,     0,   490,   518,
       0,   274,   479,   476,   485,   482,     0,   441,   440,   470,
      94,   472,   347,  1244,     0,     0,  1826,     0,     0,   990,
      47,     0,   599,   601,   596,   770,   158,   156,     0,  1842,
       0,     0,     0,  1842,   154,   143,     0,   146,   145,     0,
     996,  1000,   339,     0,  1339,     0,   784,   781,    23,  1133,
       0,  1224,    68,     0,     0,    99,    66,    91,    74,    80,
       0,   118,   114,   776,  1842,   892,   608,   891,     0,   530,
       0,   807,   808,   806,     0,     0,  1674,     0,     0,     0,
    1508,  1509,  1507,     0,  1676,     0,     0,     0,     0,     0,
       0,     0,  1071,  1659,  1660,  1656,  1658,     0,  1842,   701,
     686,   683,     0,   751,   725,   753,   727,   743,   741,   747,
     739,   762,    29,    27,     0,  1681,  1634,  1605,  1606,  1602,
    1608,     0,  1401,  1638,  1404,     0,  1323,  1318,  1317,  1320,
       0,  1634,     0,     0,  1760,  1758,     0,     0,  1746,  1757,
       0,     0,  1759,     0,     0,     0,     0,     0,  1782,  1756,
    1752,     0,  1744,  1747,  1748,  1755,  1751,  1775,     0,  1737,
    1736,  1740,  1742,     0,  1735,     0,  1738,  1729,  1335,  1331,
       0,  1392,     0,     0,  1614,  1612,   569,   567,   579,   581,
     577,     0,     0,   228,  1192,  1193,  1194,  1196,  1179,  1177,
    1176,  1180,  1181,  1178,  1195,  1182,  1183,  1167,   982,  1202,
     979,     0,     0,  1220,     0,  1165,  1164,  1159,  1157,  1156,
    1160,  1158,  1162,  1163,  1155,  1208,  1411,  1470,  1464,  1466,
    1476,  1473,  1679,  1475,     0,  1481,  1473,     0,  1479,  1678,
    1489,  1488,     0,  1490,     0,  1407,  1413,  1554,  1547,  1417,
    1596,  1594,  1595,  1591,  1593,  1590,  1592,  1522,     0,  1524,
       0,     0,     0,     0,  1530,  1534,     0,  1514,  1429,  1021,
    1258,  1251,  1247,  1643,     0,  1446,  1447,  1449,  1452,  1459,
       0,     0,  1506,  1630,  1624,  1581,  1579,  1580,  1576,  1578,
    1575,  1577,   491,   489,     0,   523,   522,   171,   437,     0,
       0,    23,     0,     0,  1013,     0,    48,   993,     0,    23,
     160,   150,     0,   618,   620,   162,   152,   770,     0,   338,
     538,   783,  1054,     0,     0,    64,     0,    77,    86,     0,
      70,   883,   880,   534,  1842,   952,  1564,     0,     0,     0,
       0,  1675,     0,     0,  1673,     0,     0,     0,     0,  1655,
    1672,     0,   704,   681,   687,   608,  1691,     0,  1689,     0,
       0,  1608,  1608,  1601,  1403,     0,  1405,  1399,     0,  1322,
       0,  1701,     0,  1750,  1749,     0,     0,  1506,     0,  1506,
    1506,  1506,  1506,  1753,     0,     0,  1733,     0,     0,     0,
       0,  1762,  1734,     0,     0,     0,     0,     0,     0,  1728,
       0,  1394,  1397,  1381,  1395,  1398,     0,   853,   852,   322,
     206,   984,   983,   981,     0,  1201,  1087,  1091,  1093,     0,
    1097,     0,  1095,  1099,  1088,  1089,     0,   874,     0,  1678,
    1493,     0,  1482,  1485,  1484,  1492,     0,  1473,     0,     0,
    1548,  1553,     0,  1541,  1533,  1517,  1515,     0,  1518,     0,
    1450,     0,  1555,  1453,     0,  1460,  1461,  1633,  1250,     0,
       0,     0,     0,   520,   519,   473,   348,   345,     0,  1011,
       0,     0,     0,   992,   771,   138,   617,    23,  1002,  1059,
      65,  1225,    82,     0,     0,    75,    86,    86,  1842,   531,
       0,     0,     0,     0,  1671,  1677,  1667,  1668,  1669,  1670,
     706,   763,     0,  1688,  1635,  1628,  1607,  1603,     0,  1324,
       0,  1628,  1773,     0,     0,  1776,     0,     0,     0,     0,
       0,     0,     0,  1745,  1764,  1765,  1761,  1763,  1743,     0,
    1739,  1741,  1730,  1731,  1336,     0,  1382,  1380,  1615,   980,
    1842,  1842,  1101,  1842,  1103,  1842,  1842,  1090,  1221,  1209,
    1474,  1477,     0,  1480,  1478,  1494,     0,     0,     0,  1531,
    1454,     0,  1448,  1442,  1443,  1647,     0,  1462,  1456,  1631,
    1354,  1350,  1351,  1356,  1355,  1629,  1250,     0,   350,  1012,
    1825,     0,     0,     0,     0,     0,     0,    53,     0,    52,
       0,    50,     0,     0,   139,  1063,  1055,     0,  1061,    86,
      91,    86,    87,    81,    71,   881,     0,  1637,     0,  1716,
       0,  1842,    23,  1690,  1627,  1636,  1328,     0,  1325,  1327,
    1623,  1774,     0,     0,  1772,     0,     0,     0,     0,  1754,
    1771,     0,  1396,  1092,  1094,  1842,  1098,  1842,  1096,  1100,
    1483,  1491,  1549,  1526,     0,  1451,     0,  1441,     0,  1358,
    1357,  1353,  1632,  1582,   356,   354,   346,     0,   352,   358,
      55,    60,    57,    59,    56,    58,    54,     0,    49,     0,
     619,   621,  1842,  1060,  1062,  1226,    83,    78,   532,  1714,
    1715,   702,   764,     0,  1319,  1770,  1777,  1766,  1767,  1768,
    1769,     0,  1102,  1104,  1455,  1444,  1352,  1842,  1842,   351,
     353,  1842,    51,     0,  1064,     0,   707,  1326,  1732,   357,
     355,   359,     0,    84,   994,    88,    90,     0,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   550,   551,   552,   553,   708,  1726,  1727,   188,   263,
     189,  1128,  1129,  1614,  1952,  3049,  2489,  2490,  2931,  3050,
    3051,   554,   897,  2523,  2187,  2947,  1555,  2185,  2788,  2527,
    2943,  2186,  2789,  3060,  3165,  3175,  2945,  3178,  1776,  1777,
    1778,  1228,  1844,   555,  1239,   902,  1237,  1563,  1854,  1560,
    1852,  1857,  2191,  1238,  1851,  1564,  2190,   556,    16,    35,
      36,    37,    38,    39,   113,   559,   824,  1494,  1155,  1803,
    1807,  1808,  1804,  1805,  2499,  2503,  2163,  2155,  2154,  2156,
    2159,  1110,  1062,  1758,   560,    82,    83,    18,    61,   141,
      95,   254,    97,    98,   199,   277,    99,   100,   241,   227,
     676,  2310,   304,   658,  1674,   331,   332,   228,   286,   279,
     281,   981,   982,   145,   354,   146,   147,   292,   229,   230,
    1480,   392,   242,   245,   243,   244,   313,   369,   370,   372,
     377,   661,   246,   247,   322,   374,   195,    19,    79,   177,
     178,   179,   667,  2309,   180,   250,   239,   325,   326,   327,
     328,  1507,   561,   562,   563,   564,   781,  3038,  2761,  1130,
    3116,  3117,  3118,  3158,  3157,  3161,   565,   566,   567,   568,
     757,  1111,   864,  1197,  1198,  1165,   861,  1166,   759,   760,
     761,   762,   763,   764,   765,  1065,  1112,  2127,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,   713,   766,  1460,  2132,  2134,
    2759,   767,  1431,  2116,  1430,  2115,  1434,  2119,  1432,  2117,
    2099,  2108,   768,   769,   770,   771,  1415,  1416,  1417,  1418,
    1399,   569,  2794,  3066,  2539,   570,   834,  1509,  2171,   114,
     236,   364,  1330,   963,   964,   965,  1327,  1328,  1661,  1662,
    1663,  2009,  2010,  1331,  1332,  1657,  2013,  2005,  1669,  1670,
    2016,  2017,  2307,  2303,  2304,   571,  1172,    84,  1475,  1476,
    1819,   866,   814,   869,   691,   803,   786,   825,  1913,    85,
     692,   686,  1379,  2158,    86,   773,  2465,   572,   573,   918,
     919,   574,   575,   576,   577,   926,  2570,   947,  2813,   948,
    1593,   949,  1910,   950,  2236,   951,  1617,   578,  1589,  2235,
    2568,  2567,  3071,   115,    20,   579,  1146,  1481,  1482,  1607,
    1277,  1608,  1609,  2242,  2244,  1922,  1921,  1934,  1920,  1919,
    2253,  2251,  1926,  1927,  1930,  1931,  1916,  1918,   580,   581,
     822,   582,  1273,   933,  3072,   583,  1205,  2769,  1610,  1923,
    1860,  2193,   857,  1182,  1530,  1828,  2172,  1829,  1178,  1529,
     584,   585,   911,  1578,  2543,   586,   587,   588,   589,    21,
      65,    22,    23,    24,   116,   117,   590,   118,    25,   648,
      26,   119,   120,   157,   366,  1336,  2021,  2868,   121,   153,
     297,   591,  2094,    27,    28,    29,    30,    31,    60,    87,
     122,   411,  1345,  2027,   592,   906,  1864,  1567,  1862,  2948,
    2534,  1568,  1861,  2196,  2536,   593,   594,   595,   797,   798,
    1241,   123,   237,   365,   652,   653,   967,  1334,   596,   952,
     953,   597,   830,  1285,   954,   774,    89,    90,    91,    92,
    1248,   183,   137,    93,   697,   134,   191,   192,  1249,  1250,
    1871,  1251,   408,   409,   935,   410,   936,  1585,  1586,  1252,
    1253,  1126,  2669,  2670,  2873,  1388,   812,   813,   598,  1141,
    2933,   599,  2511,   600,  1159,  1160,  1161,  1500,  1498,   601,
     602,  1784,  1814,   603,  1014,  1385,   604,   858,   859,   605,
     874,   606,  1963,   607,  2939,   608,  1832,  3056,  3057,  3058,
    3132,   863,   609,  1254,  1580,  1897,  1898,   610,  1468,   690,
    1026,   611,   612,   613,  2029,  2673,  2884,  2885,  3000,  3001,
    3005,  3003,  3006,  3095,  3097,   614,   615,  1243,  1572,   616,
    1245,   882,   883,   884,  1221,   617,   618,   619,  1542,  1213,
     877,   198,   885,   886,   775,  2030,  2351,  2352,  2335,   716,
     717,  2025,  2336,  2339,   124,   152,   358,   991,  1679,  2353,
    2888,  1035,   620,   875,   125,   149,   355,   988,  1677,  2340,
    2886,  2026,   901,  2178,  2784,  3059,  1216,   621,   622,   623,
     624,   625,   784,  1782,   710,  1731,   626,  2732,   704,   705,
    2091,  1364,   627,   628,  1000,  1001,  1002,  1376,  1716,  1003,
    1713,  1373,  1004,  1688,  1365,  1005,  1006,  1007,  1008,  1682,
    1356,   629,   793,   776,   630,  1308,  1309,  1632,  2598,  2830,
    2274,  2595,  3077,  3078,  1310,  1642,  2288,  1995,  2639,  2860,
    1824,  2170,  1996,  1311,  1312,  2743,  3031,  3032,  3033,  3111,
    1313,  1314,  1163,   631,   828,   632,   960,  1315,  1316,  2997,
    1648,  1649,  1650,  1998,  2290,  2863,  2864,  1317,  1973,  2268,
    2827,  1366,  1367,  1352,  2050,  1680,  2051,  1368,  2055,  1369,
    2078,  1370,  2079,  2405,  2406,  1683,  1318,  1626,  1627,  1970,
    1319,  3027,  2915,  3023,  1976,  2420,  2735,  2736,  2737,  3021,
    2421,  1977,  2916,  3028,  2038,  2039,  2040,  2041,  2042,  2890,
    2691,  3010,  2043,  2891,  2892,  2379,  2044,  2380,  2045,  2553,
    1709,  1710,  1711,  2721,  1712,  2402,  2396,  2904,  2052,  2865,
    2383,  2631,  2054,  2913,  1899,   777,  1900,  2205,  1053,  2100,
    2752,  2068,  2717,    59,   633,   634,  2590,  2822,  2261,  2821,
    1653,  2003,  2004,  2265,  1964,  1320,  1965,  1984,  2601,  1407,
    1960,  1961,  2744,  2918,  2820,  2594,  1901,  1640,  2096,  2097,
    3024,  2046,  1903,  1904,  2555,  2693,   635,   636,  1619,  1962,
    2585,  2817,  2818,  1288,   637,   779,  1322,  1323,  1635,  2276,
    1324,  1325,  1981,  2229,  2549,   638,   914,  1262,  1263,  1264,
    1265,  1326,  1985,  2637,  2859,  2285,  2634,  2635,  2636,  2633,
    2621,  2622,  2623,  2624,  2625,  2626,  2976,   698,  1582,   700,
    1389,  1905,    63,    48,    77,    74,   640,   888,  1546,  1149,
    1207,   641,   867,   642,  2145,   643,  1725,   702,  1391,   644,
     645,    42,   359,   360,   361,   362,   363,   646
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2585
static const short yypact[] =
{
    2122,  1141,   369,   611,   611,   611,   611,   611,   611,   611,
   -2585,   611,   369,  1266, -2585, -2585, -2585,  1774, -2585, -2585,
   -2585,   347, -2585,  2122, -2585, -2585, -2585, -2585, -2585,  1737,
   -2585, -2585, -2585, -2585, -2585,   395,   491, -2585,   508, -2585,
   -2585, -2585, -2585, -2585,   369,   108, -2585,   -61, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
    1950,   266, -2585, -2585, -2585,   809, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,   369, -2585, -2585,   108,   160,
   -2585,   369,   623,  1774, -2585,   865, -2585, -2585, -2585, -2585,
     931,   177, -2585, -2585, -2585,   879,   531,   369, -2585, -2585,
     901,   369, -2585, -2585,   369,   369, -2585, -2585, -2585, -2585,
     369,   369, -2585, -2585, -2585, -2585, -2585,   809, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  6489,
     177, -2585,   353,   415, -2585, -2585,   466, -2585, -2585,   902,
     266,   424, -2585, -2585, -2585, -2585, -2585,  6556, -2585,   369,
     523,   850,   369,  1774, -2585, -2585, -2585,   369, -2585, -2585,
     467,   786, -2585, -2585,   599, -2585,   614, -2585,   549, -2585,
   -2585,   622, -2585,   652, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585,   660, -2585, -2585, -2585,   415,  1640,  1069,
   -2585,   201, -2585,   415, -2585,   161, -2585, -2585, -2585,   119,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,   467, -2585,
     786, -2585, -2585,   681, -2585,   718, -2585,   705, -2585, -2585,
     737, -2585,   744, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,   761,  1162,   369,   800, -2585,  1774,  1774,   820,   369,
   -2585,    -9, -2585,   607,   932, -2585,   633,  1030,  1230,  1258,
     369,  1272,  1294,  1298, -2585,   729, -2585,   952, -2585, -2585,
   -2585, -2585, -2585,   415, -2585,   415,   895,   205, -2585, -2585,
   -2585,  1337, -2585, -2585,  1378, -2585, -2585, -2585, -2585, -2585,
      -9, -2585, -2585, -2585,  1387,  1390,   266,  1272,  1393,  1396,
     793, -2585,  1380, -2585,  1059,  1027, -2585,  1104, -2585, -2585,
   -2585,   848, -2585, -2585,  1434, -2585,  1057, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,  1030,  1057, -2585, -2585, -2585, -2585,
   -2585, -2585,  1060,   194,   312,   338, -2585,  3321, -2585, -2585,
   -2585,  1077,  1474,   318,  1117, -2585, -2585,  1640, -2585,   415,
   -2585, -2585, -2585,   904,  1523,  1274,   358,   379,   425,  1144,
     397,  1184, -2585, -2585, -2585,   369, -2585, -2585,   369,  1223,
   -2585,  3883,   424,  4663,  1961,  -193,   369,  1556,    -5, -2585,
     932,  1554, -2585, -2585, -2585, -2585,  1566, -2585,  1569, -2585,
    1574, -2585,   369, -2585,   369, -2585, -2585,  1272,  1578, -2585,
   -2585, -2585, -2585,   206,  1586,    -5,  1202,  1595, -2585,  1601,
   -2585, -2585, -2585,  1611, -2585, -2585, -2585,  1035,  1268,  1659,
   -2585,   369,  1288, -2585, -2585, -2585,   369,   233,   369,   369,
     233,   233,   939,   369, -2585,   369, -2585, -2585,   369, -2585,
     413, -2585, -2585, -2585,   233, -2585, -2585, -2585, -2585,   369,
   -2585, -2585, -2585, -2585,   129,   129,  7323, -2585, -2585, -2585,
   -2585, -2585,   233, -2585, -2585,   233, -2585, -2585,   369, -2585,
   -2585,   233, -2585, -2585,   307,   233, -2585, -2585,  7323,   233,
     307,   369,   307,   233, -2585, -2585,   220,   233,   233,   220,
     233,   369,   220,   233, -2585,   233,   233,   233, -2585, -2585,
   -2585, -2585,   307,   233, -2585, -2585,   233,    90,   369, -2585,
   -2585, -2585, -2585,   233,   957, -2585, -2585, -2585,   233, -2585,
    3751,   307,  7323, -2585,    75,    75,   233, -2585, -2585,   998,
     307,  1020,  7323,  7323, -2585,  2016,  7323,   233,   108, -2585,
    7323,   233,  7323,   307, -2585,   233,  7323, -2585,  7323,   129,
     369,   233,   369,    75,   233,   369,    75, -2585,   369,   190,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,   158, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,   863, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,   750, -2585,
     369, -2585,   393, -2585,  1292, -2585, -2585, -2585,  1382, -2585,
   -2585,  1295,  1299,  1301,  1303, -2585, -2585,  1064,  1663,  1304,
   -2585, -2585,  1395, -2585,  1314,  1317,  1079,  1325,   369, -2585,
     369,  1327, -2585,   265,  1289, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,  1101,  1308,  1267, -2585,  1106, -2585,
    1105, -2585,  1706,  -181,   430, -2585, -2585, -2585,  1305, -2585,
    1385, -2585,  1255,   156, -2585, -2585, -2585,  1412, -2585,  7323,
    7323, -2585, -2585,  1307,  1212,  1310,  1316,  1318,  1322,  1323,
    1329,  1331,  1333,  1335,  7323,  1253,  1338,  1340,  1346, -2585,
    7323,  7323,  1347,  1348, -2585,  7323,  1351, -2585,  1352,  1355,
    1361,  1363,  1365,  1366,  1367,  7323,  1372,  6212, -2585,   134,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585,  1034, -2585,  1324, -2585, -2585, -2585, -2585, -2585,
   -2585,   307, -2585, -2585,  1385, -2585,    15, -2585, -2585,  1481,
   -2585,    62, -2585,  1349, -2585, -2585, -2585, -2585,  1788, -2585,
   -2585,  -235, -2585,  1198, -2585,  1199,  1788, -2585,  1224, -2585,
   -2585,  1399,   166, -2585,  1370, -2585,  1164, -2585, -2585,  1401,
   -2585,  -140, -2585,  1166,   239,  -224, -2585,  1101,  1515, -2585,
    7323,  7323, -2585,  1812,   233, -2585, -2585, -2585, -2585, -2585,
     323,   323,   323, -2585,   323, -2585,   323,   323,  1245,    15,
    1245,  1245,  1021,  1021,  1245,  1245,    15, -2585,  1824, -2585,
      32,  1826, -2585,    15, -2585,  6838, -2585,   105,    81, -2585,
   -2585,  7323, -2585, -2585, -2585, -2585, -2585,   669, -2585, -2585,
     424,  1463,   424,  7323, -2585,   102, -2585, -2585,  7323,  1417,
    1418,  1420,  1423,  1422,  1424,  1020,  1355, -2585,  1511,  1044,
    1262, -2585,  1278, -2585, -2585, -2585,  1024, -2585,  1839, -2585,
    1837,   369, -2585,   250,   211,  1290, -2585, -2585,  1846, -2585,
    1208,  1846,  1850,  1210,  1846,  1850,  7323,  1846, -2585, -2585,
     156,   307, -2585, -2585,  1451,   292, -2585, -2585,  1442,   307,
    7323,  1445, -2585, -2585,  1841,  1842,  1811, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  1067,  1067,   233,   233,   233,
    3366, -2585, -2585,  1791,   750, -2585, -2585,   529, -2585, -2585,
   -2585,  1425, -2585, -2585, -2585, -2585,  6489,  1272, -2585,  1430,
   -2585,   431, -2585, -2585, -2585, -2585, -2585, -2585,  1774, -2585,
   -2585,  1774,   959,   195,  1852, -2585, -2585,   627,   226,   724,
    1870, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  1466,
    1308,  1105, -2585,   939,  -153,   966,   369, -2585, -2585,   369,
   -2585,  1296,  1273,  1315,  1468, -2585,  1480,   113, -2585, -2585,
   -2585,  1232,  1232,    75,  7323, -2585,    75,    75,    75,    75,
    1444,  7323,  1513,  1502,  7323,  6212,  1486, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,  1293,    75,  1859,  7323,  5274,  6212,
    1444,  7323, -2585,  6212,  1883,    95, -2585, -2585, -2585,  7323,
   -2585,  7323,  7323,  6212,  7323,  7323,  7323,  7323,  7323,  7323,
    7323,  7323,  7323,  7323,  7323,  7323,  7323,  7323,  7323,  7323,
    7323, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  7323,  7323, -2585, -2585,  1495,  7323, -2585,  7323,  1498,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585,   369,   307, -2585,  1311,  1500, -2585, -2585,
   -2585,   939,  1088, -2585,  1088,  1020,   220,  7323,  7323,  7323,
    1501, -2585, -2585,   307,   307, -2585,  1326,  1020,    75,  1260,
     369,   415,    86,    90,   307, -2585,  1332,  7323,  1584, -2585,
   -2585,  1398, -2585, -2585,  1826,   110, -2585,   156, -2585, -2585,
    1906,  1920, -2585, -2585, -2585, -2585, -2585, -2585,  1597, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  3751, -2585,  1021,  7323,   -51, -2585, -2585,  1938, -2585,
      75,  1921,  1922, -2585, -2585, -2585, -2585, -2585,   144, -2585,
   -2585, -2585, -2585,  1810, -2585,  1745, -2585, -2585, -2585,  7323,
     129, -2585, -2585,   369,  1926,    75,    75, -2585,  1376, -2585,
      75,  1341,   307, -2585,   369,   369,  7323,   155, -2585,  1388,
   -2585,   352, -2585,  1488, -2585,  1499,  7323,  1123, -2585, -2585,
    1362, -2585,  1949, -2585,  1435, -2585,   307, -2585, -2585, -2585,
     939,   307,   170, -2585, -2585, -2585, -2585,   369,    75,    75,
     252,   292,  1836,   949,   307,   156, -2585,  1446, -2585, -2585,
    1970,  1958,  1599, -2585, -2585, -2585, -2585, -2585,  1679,  1679,
     147,  1455, -2585,   369, -2585, -2585,  1385,  1385, -2585, -2585,
   -2585,   369, -2585,   369,   547,  1385, -2585,   909, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  1313, -2585, -2585, -2585, -2585, -2585,   173,   173,   333,
     980, -2585,   821, -2585,   529, -2585,  1774,  1966, -2585, -2585,
    1966, -2585, -2585, -2585, -2585,  1774, -2585, -2585,  1385, -2585,
     759,  1577, -2585, -2585,   759, -2585, -2585, -2585,  1582,  1583,
     344,  1591,  1594,   818, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,   369, -2585, -2585,   344,  1343, -2585,   265, -2585,  1623,
     177,  1407, -2585,  1020,  1452, -2585, -2585,  1572, -2585, -2585,
   -2585,  1484, -2585,   369,   369,   369, -2585, -2585, -2585,   438,
   -2585,  6212,  1641,  1642,   441,   442,   547,  1645,  5310,  1646,
     -72,  1439, -2585, -2585,   140,  1648, -2585, -2585, -2585,  5365,
    2001,  1253,  1653,  1657,  5401, -2585,  1660,  3419,  1667, -2585,
    7323,  7323,  7323,  5456,  7323,  5510,  5562,  5947,  6232,  6443,
    6177,  6684,  2670,  4529,  6729,  6030,  4560,  6631,  3706,  1232,
    1232,  1402,  2399,  6534,  5976,  6067,  1444,  6212,  6121,  1444,
    7323,  1620, -2585,   369, -2585,  1441, -2585, -2585, -2585, -2585,
    1437, -2585,  2042,  2046, -2585,  2048,  1490,  7323, -2585, -2585,
    1447,  2055, -2585,  1602,  1461,  1850, -2585,  1698,   371, -2585,
    1665, -2585, -2585,  1464,  1375,   369, -2585, -2585,  1666,   233,
     977,  7323, -2585,   369,   369,  7323,    68,    15,  2080,  1547,
    2064,  2065, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
    1677, -2585, -2585, -2585,   307,  1575,  6838, -2585, -2585, -2585,
    2045,  7323,   424,   995, -2585, -2585,  1793,  2094,  2100,   444,
     448,   369,  1730,  1020, -2585,  7323,  1693,  1694, -2585, -2585,
    1762, -2585,  7323,   451, -2585,  1528, -2585, -2585,   242, -2585,
    7323, -2585, -2585,  1503,   353, -2585,  1032,   369,  2101,  7309,
   -2585, -2585,  1709, -2585,  1711,  2113, -2585, -2585, -2585,   150,
   -2585,  1850,  1850,  1472, -2585,  1585,  1587,    75,    75, -2585,
   -2585, -2585, -2585, -2585, -2585,   -24,   566, -2585,  1158, -2585,
   -2585, -2585, -2585,    75,  1284,  2120,  2102, -2585,  1020,   873,
     341,   179,  2043,   106,   998, -2585,   180, -2585, -2585, -2585,
    1717,   142,  1385,   191, -2585,  1529,  1522, -2585, -2585, -2585,
   -2585, -2585,   577, -2585, -2585, -2585, -2585,  1721,  1526,  2135,
   -2585,  1493, -2585, -2585, -2585, -2585,   307,   141, -2585, -2585,
   -2585,  1516,   980, -2585,   369,   369, -2585, -2585,   369,   649,
   -2585, -2585, -2585, -2585,  1731,  1733, -2585,  1702, -2585,  1707,
   -2585,  1736,   458, -2585,  7160,   460,   107,   107,   468, -2585,
     107,  7160, -2585, -2585,  1553,  1553, -2585,  1738, -2585,  1741,
    1743, -2585,  1744,  1747, -2585,  1749, -2585, -2585, -2585,    79,
   -2585, -2585, -2585,   469, -2585, -2585,   471,   369, -2585, -2585,
     966,  2153,  1020,   415,  7323, -2585,  2162, -2585, -2585, -2585,
   -2585,   344, -2585,    75, -2585, -2585, -2585, -2585, -2585,  7589,
   -2585, -2585,  1253,  1253,  2143, -2585,  2145,  1598,  1507, -2585,
    1212,  1794, -2585, -2585,  1212, -2585, -2585, -2585,  1798,  1212,
    6212,  6212,  6212,  1212,  6212,  1212,  1212,  1212,  2157,  2163,
    2164,  7323,  1800,  2165,  7323,  1809, -2585,  2185, -2585,  6212,
   -2585,  1588,   344,   164, -2585,  1020,  7323,  7323,  7323,  6890,
    2191,   225, -2585, -2585,  1020, -2585,  1592,   369,   369, -2585,
   -2585,   369,   369, -2585,   770, -2585, -2585,   334, -2585,  1596,
    7323, -2585, -2585, -2585,  2190, -2585, -2585, -2585, -2585, -2585,
     369,  1850, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585,   307, -2585, -2585,  4553, -2585, -2585, -2585,  1882,
    2177, -2585,  1872,  1874,  1761,  1603,  1884,  1796, -2585, -2585,
   -2585,   629,  1867, -2585, -2585, -2585, -2585,  1762, -2585, -2585,
   -2585,   236,   251, -2585, -2585, -2585,  1970,  7323,  1825, -2585,
    1778, -2585, -2585, -2585,  5314,  5314, -2585,  1101, -2585, -2585,
    1553, -2585, -2585,  7470,  1813, -2585, -2585,  1828,  1831, -2585,
    1833,  1834,  1835,  1843,   369,   -22, -2585,  2235, -2585, -2585,
   -2585, -2585, -2585,  2450, -2585, -2585,   939,   307,   307,   130,
    1604, -2585,  2218,    15,   369, -2585,  2241, -2585,  2248,  1291,
    1291,  1291,  1291,  1677, -2585, -2585,  2256, -2585, -2585, -2585,
    2257, -2585, -2585, -2585,  1291,   135, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585,   476, -2585,  2238, -2585, -2585,  1385, -2585,   547,
   -2585, -2585, -2585, -2585, -2585, -2585,  1683,  1686,   163, -2585,
     180, -2585,   107,  1672,   233,  7160, -2585, -2585,  1854, -2585,
   -2585, -2585,   369,   369,  7589,   256, -2585,  7323, -2585,  7323,
   -2585, -2585, -2585, -2585, -2585, -2585,   233,   107, -2585,  1385,
     666,  1678,  1688,  2279, -2585,  2285, -2585,   307,   369,   768,
     768, -2585, -2585,  2291, -2585,  2291,   690,   690,  2291, -2585,
   -2585,  1961, -2585, -2585,  1342,    87, -2585,  1961,  2417, -2585,
      87,   107,   759, -2585,  1881,  2315,  1881,  7379,   255,  2294,
   -2585, -2585, -2585, -2585, -2585, -2585,   273, -2585,  1385,   373,
    1925,  2298,  1697, -2585, -2585,   477, -2585,   344, -2585,   479,
     348, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  1699,   -98,
    2282,  2282,  2289,  2282,  2282,  2293, -2585,   216, -2585,   759,
     369, -2585,   344, -2585, -2585,  1712,  1020,  2308,   212, -2585,
     369,   480, -2585,  7323,  1945, -2585,   178, -2585,  3953, -2585,
    1710, -2585,  1947, -2585,  2300, -2585,  1751, -2585, -2585, -2585,
   -2585, -2585,  1718, -2585, -2585,  1953,  1957,  1959, -2585,  1960,
   -2585, -2585, -2585, -2585, -2585, -2585,  6212,   482, -2585, -2585,
     484, -2585,  1965,  7323,  7323,  2323,   489,  1020,  2340, -2585,
   -2585, -2585, -2585,  7323,  1799,  2095,  7323, -2585, -2585, -2585,
   -2585,  1040,  1977,   334,  1182,  1182,  2351,   152, -2585,  2352,
   -2585, -2585, -2585,  1182,   369,  1829,  1156,  2353,   369,   -80,
     307,  2134,   495, -2585,  1585,  7323, -2585,  2359,  7323,   307,
   -2585,   413,   369,   307, -2585,  1991,  7323,  7323, -2585, -2585,
     629,  1867, -2585,  1677, -2585, -2585,  1128, -2585, -2585,  1819,
   -2585,   415,  7111,  2268,  2268, -2585,  1757,   547,  1999,   146,
     571,  7589,   571,   571,   571,   571,  1772,  7589,  7309,  7589,
    7589,  7589,  7589, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  1954,   986, -2585, -2585, -2585,
    1783,    75,  1291,    75,  1291, -2585, -2585, -2585, -2585, -2585,
     -24,  1291,   566,  1291, -2585,    15,  1284, -2585,  2020,  1983,
    7589,  1313,   179,   179, -2585, -2585, -2585, -2585,   496, -2585,
    1946, -2585,  2396,   107,   428, -2585,  1792, -2585,  2401,  2932,
    2932,  2932,  2932,   107,   107, -2585, -2585, -2585,  1869, -2585,
     498, -2585,  1797, -2585,   369,   369,  1493,   307, -2585,  2291,
   -2585, -2585,   369,   690,   690, -2585, -2585,   690,  2217,  1803,
    1804, -2585, -2585,   129,   129,   129,  2394,   129,   129,   129,
     129,   129,   129,  2395, -2585,  2397,   129, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  1342, -2585,   307,  1816, -2585,
    1992,  2217,  2402, -2585,  2403,  2400,  2404,  2405,  2408,  2409,
    1167,  2417, -2585,  1992, -2585,   501, -2585,  1979, -2585,   356,
     287, -2585, -2585,  7160, -2585,  7160, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,   204,  2021,   204, -2585,  2026,   752,
    7589, -2585,  2418, -2585,  2170,   107,  1186,   107, -2585, -2585,
   -2585, -2585,  1827,  2430,  1827, -2585,  2451,  2451,   502,  2081,
    2451, -2585,  2082, -2585, -2585, -2585,   759, -2585, -2585, -2585,
   -2585,  1020, -2585, -2585,   344,  2203,  1970, -2585,  7589,   199,
    1948,   628, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,  1830,  1253,  1885,
    1508, -2585, -2585, -2585, -2585, -2585,  7323, -2585, -2585, -2585,
   -2585, -2585,  2008, -2585,   262,  1020, -2585,  2458,  2056, -2585,
   -2585,  2089, -2585, -2585, -2585,  1951, -2585, -2585,   369,  1182,
     415,  1189,   369,  1182, -2585, -2585,    75, -2585, -2585,  7323,
   -2585, -2585, -2585,    75,  2113,  2249, -2585, -2585,    15,  6212,
    2459, -2585, -2585,   156,  2072, -2585, -2585,  7323, -2585, -2585,
    2109, -2585, -2585, -2585,   251, -2585,  1585, -2585,  7323, -2585,
     228, -2585,  1826, -2585,  1827,  7589, -2585,   321,  2482,  2112,
   -2585, -2585, -2585,  7589, -2585,   503,  7589,  7589,  7589,  7589,
     369,   511, -2585, -2585, -2585, -2585, -2585,  7323,  2066, -2585,
    2160, -2585,  2478, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,   369, -2585,   121, -2585, -2585, -2585,
    1313,   107, -2585,   547,  2376,   513, -2585, -2585, -2585, -2585,
     369,  1962,  2015,  2015, -2585, -2585,  7425,  2087, -2585, -2585,
    2090,  2092, -2585,  2093,  2096,  2098,  2103,   369,   568, -2585,
   -2585,   517, -2585, -2585,  2636, -2585, -2585, -2585,   537,  2500,
    2500, -2585, -2585,   553,  2505,  2503, -2585,   143, -2585, -2585,
     107, -2585,   174,  1910, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  2324,  6489, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  -150,  2521,
   -2585,   307,  1534, -2585,  2324, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  2294, -2585,
   -2585,  2107, -2585, -2585,   151, -2585,  2107,   151, -2585,   204,
   -2585, -2585,  7589, -2585,   248, -2585, -2585, -2585,  2091, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  2161, -2585,
    2512,  2169,  2171,  2516, -2585, -2585,  2172, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,   210,  2537, -2585, -2585,   369,  2193,
     369,  1944,   571,  2236, -2585,  2144, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,  1519, -2585, -2585, -2585,  6212,  2182,
      75,    15,  2202,  1020, -2585,  7323, -2585,  2009,  2538,    15,
   -2585, -2585,   440, -2585, -2585, -2585, -2585,   215,  2189,  1850,
   -2585, -2585, -2585,  2192,  2194,  2080,  2151, -2585,  2240,  2195,
   -2585, -2585, -2585, -2585,  2341, -2585, -2585,   178,  1553,  1963,
    1553, -2585,  2196,  7589, -2585,  2197,  2198,  2200,  2204, -2585,
   -2585,  2023, -2585, -2585, -2585,  1585, -2585,   556, -2585,   307,
    2053,  1313,  1313, -2585, -2585,  7589, -2585, -2585,   107, -2585,
    2167, -2585,  2053,  2367,  2367,  2211,   146,   571,  7627,   571,
     571,   571,   571,  1984,  7627,  2932, -2585,  7627,  7627,  7627,
    7627, -2585, -2585,   107,  2579,   107,  2932,   233,  7160, -2585,
     307, -2585, -2585,   301, -2585, -2585,   369, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585,   307,  2521, -2585, -2585, -2585,   307,
   -2585,   307, -2585, -2585,  1818, -2585,  2369, -2585,  2372,   216,
   -2585,   557, -2585, -2585, -2585, -2585,   559,  2107,  2592,  2580,
   -2585, -2585,  1993, -2585, -2585, -2585, -2585,  2230, -2585,   199,
   -2585,   199, -2585, -2585,  7589, -2585,  2175, -2585,  2203,   171,
     341,   369,  2584, -2585, -2585, -2585, -2585, -2585,  1020, -2585,
    2232,  7803,  2201, -2585, -2585, -2585,  2005,    15, -2585,    30,
   -2585, -2585, -2585,  2239,   156, -2585,  2240,  2240,   251, -2585,
    2242,  2000,  1827,  2010, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585,   369, -2585,  2113,   628, -2585, -2585,   178, -2585,
    7540,   628, -2585,  2247,  7627, -2585,   569,  7627,  7627,  7627,
    7627,   369,   573, -2585, -2585, -2585, -2585, -2585, -2585,  2209,
   -2585, -2585, -2585,  2396,  2113,   174, -2585, -2585, -2585, -2585,
    2050,  2050, -2585,  2050, -2585,  2050,  2050, -2585, -2585, -2585,
   -2585, -2585,   296, -2585, -2585, -2585,  7589,  2214,  1827, -2585,
   -2585,   576, -2585,  2623, -2585, -2585,  7160, -2585, -2585, -2585,
   -2585,  2624, -2585,   -35, -2585, -2585,  2203,  2254,  1012, -2585,
   -2585,   323,   323,   323,   323,   323,   323, -2585,  2608, -2585,
     579, -2585,  7323,  1237, -2585, -2585, -2585,   717, -2585,  2240,
    7323,  2240,  2080, -2585, -2585, -2585,  2406, -2585,  1827, -2585,
    1827,   150,    15, -2585, -2585, -2585, -2585,   587, -2585, -2585,
   -2585, -2585,  2259,  7627, -2585,  2262,  2264,  2265,  2266, -2585,
   -2585,  2932, -2585, -2585, -2585,  2050, -2585,  2050, -2585, -2585,
   -2585, -2585, -2585, -2585,   199, -2585,  7589,  2396,   171, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,   641, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,  7803, -2585,  2639,
   -2585, -2585,  1039, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,   130, -2585,  7540, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,   590, -2585, -2585, -2585, -2585, -2585,   923,   923, -2585,
   -2585,   923, -2585,  7323, -2585,  2269, -2585, -2585, -2585, -2585,
   -2585, -2585,  2270, -2585, -2585,   235, -2585,   156, -2585,  2080
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2585, -2585, -2585, -2585, -2585,   464, -2585,   558,  -185, -2585,
   -2585,  -851,   271, -2585, -2585, -1522, -2585, -2585, -2585, -2585,
    -477, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -1672, -2585, -1520, -2585,
     518, -2585, -2585, -2585, -2585, -2585, -2585, -2585,   805, -2585,
   -2585, -2585, -2585,  1426, -2585,  1098, -2585, -2585,   -50, -2585,
   -2585,  2629, -2585,  2628,  2305, -2585, -2585, -2585, -2585, -2585,
     871,   507, -2585,   868, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  -114,   804,   325, -2585, -2585,
    2391,   -23, -2585,  2539, -2585, -2585,  2549, -2585,  2486, -2585,
   -2585, -2585,  2421,  2303,  1383,  2415,  -273, -2585, -2585, -2585,
   -2585, -2585,  1364,  -966, -2585, -2585, -2585, -2585, -2585, -2585,
    -135,  2354,  2493,  -195,   953, -2585,  2342,   249, -2585,  2407,
   -2585, -2585, -2585, -2585,  2410, -2585, -2585, -2585, -2585,  -324,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  2343, -2585,
    2345, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  -805,
   -2585, -2585,  -391, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
    2118, -2585, -2585,  1191, -2585,  -890,  -803,   111, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,   956, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  -453, -2585, -2585, -2585, -2585,
   -2585,  2208, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -1682, -2585, -2585, -2585, -2585, -2585, -2585,  1328, -2585, -2585,
    -728, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  1770, -2585, -2585, -2585, -2585,
    1073, -2585, -2585, -2585, -2585, -2585, -1082, -2585, -2585,  1071,
   -2585, -2585, -2585, -2585, -2585, -2585,  -818,  -361,   954,  1236,
   -2585,  -488,   400,  -830,  1336, -2585,   869, -2585, -1805,    -2,
    -261, -2585, -2585, -1723,   411,  1078, -2585, -2585, -2585,   550,
    1478, -2585, -2585, -2585, -2585, -2585, -2585,   519, -2585,   184,
   -2585,  1477, -2585,  1168, -2585,   847, -2585, -2585, -2585,  -382,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,   968, -2585,
   -1225, -2585,  1159, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585,   524, -2585,   521, -2585, -2585, -2585, -2585,
    1624, -2585, -2585, -2585, -2585, -2585, -2585,    -1, -1474, -2585,
   -2585, -2585, -2585,   708, -2585, -1568, -2585,  -839, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585,  2755, -2585, -2585, -2585,  2662,  2751,  -666,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,   112, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585,  2752, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,  1214, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  -388,  2306,
   -2585, -2585, -2585, -2585, -2585,  2137, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585,  2188, -2585, -2585,   -47, -2585,
   -2585,  1213, -2585, -2585, -2585,  -688,  -188,  2526, -2585, -2585,
   -2585, -2585,     2, -2585,  -712,  2114,  1517, -2105,   885, -2585,
    1218,  1865,   127,   -75, -2585, -2585, -2585,  1656, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,  1612, -2585,
    1178, -2585,  -360, -2585, -2585, -2585, -2585, -2585, -2585,  -253,
   -2585, -2585, -2585, -2585, -2585, -2585,   588, -2585,  1671,   937,
   -2585, -2585, -2585, -2585, -2585,   454, -2585,   -76, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585,  1927, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  -329, -2585,  1590,  1746, -2585, -2585,   461, -2585,  -386,
   -2585, -2585,   481,   784, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  -115, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2584, -2585,  1801,
    1033,  -969, -2585, -2585, -2585,  1448, -2585, -1317, -2585, -2585,
   -2585, -1308, -2585, -2585, -1288, -2585, -2585, -2585, -2585,  1465,
   -2585, -2585, -2585, -2585, -2585, -2585,   853, -2585, -2585, -2585,
   -2585, -2585, -2585,  -325, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585,  -286, -2585, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585, -2585,   824, -2585, -2585, -2585,  -168, -2585, -2585, -2585,
   -2585, -2585, -2585,   445, -2585, -2585,   797, -2585,  1140, -2585,
   -2585, -2585, -2585, -2585, -2585,  -971, -2585, -2585, -2585, -2585,
   -1355, -2585, -2585, -2585, -2585, -2585, -2585, -1932,    97, -2585,
   -2482,   412, -2585, -2585, -1659,   470,   475,   798, -2585, -2420,
   -2095, -2585, -2585,   153,  -163, -2585, -2585, -2585, -2585, -2052,
   -2585, -2585, -2585, -1922, -2585, -2585,  -723, -2585,  -703,  1551,
     149, -1362,   807, -2585,   394, -2585, -2585, -2585, -2585,  -650,
   -2585, -1642, -2290, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2136, -2585,   565, -2585, -1073, -2585,  1902, -2585, -2585,  -702,
     -55, -2585, -1575,   -54,   267,   592,  -456, -1358, -1929,   452,
    -237, -1378,  -242, -2585,   654,   -17, -2585, -2585,  1593,  -496,
   -2585, -2585,   -88,  1919, -2585,   971, -2585, -2585, -1234,   277,
   -2585, -2585, -2585, -1815,    43, -2585, -2585, -2585,  1618, -2585,
   -2585, -2585, -2585, -2585, -2585, -2585, -2585, -2172,    26, -2585,
   -2184, -1791, -1464,  -948, -2585, -2585,    39,  -384,  -385,  -354,
    1165,  -539,    22,  1692,    91, -2585, -2585, -2585, -2585, -2585,
    1735, -2585,  -502, -2585, -2585, -2585, -2585, -2585, -2585, -2585,
   -2585,  -403,  1456,  2525, -2585, -2585, -2585, -2585
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1839
static const short yytable[] =
{
      41,  1027,   257,   385,  1168,   267,  1177,  1024,  1012,   820,
      56,    58,  1195,   868,   687,   112,   283,   687,   687,  1343,
    1806,  1353,    32,  1174,  1175,   880,  1176,  1164,  1179,  1180,
    1375,   687,  2060,   415,   130,  1848,  1270,   699,    96,   235,
     255,   922,    73,    76,   925,    32,  1595,  1596,  1739,   687,
    1280,    69,   687,  2069,   831,  2278,  2195,  1715,   687,   718,
     865,  2101,   687,  1714,   871,  2514,   687,   112,  1208,  1636,
     687,   139,  1689,   127,   687,   687,    76,   687,   337,  2160,
     687,  1127,   687,   687,   687,  1054,  1200,   126,   136,   290,
     687,   802,  1953,   687,    40,   143,  2628,  2629,  2630,   148,
     687,    40,   150,   151,  2719,   687,  1489,  1219,   154,   155,
    1200,  2632,    40,   687,   668,  1501,    40,    96,  1275,   699,
     829,   200,   298,   299,   687,  2587,  2418,  1290,   687,  1292,
    2255,  1022,   687,    40,    40,  1132,  1133,   274,   687,   126,
    1200,   687,   268,   275,   276,   724,  2007,   231,   833,  1194,
     234,   393,   268,   916,   714,   238,   685,   268,  1746,  1120,
    2556,  2557,  2558,  2559,  1502,  1747,  1503,  1201,  1504,   128,
    1022,  1144,    40,  1202,   268,  1877,  1878,    40,  2233,   268,
     928,   929,    40,  2418,   268,   269,   270,    40,   878,    40,
      40,   778,  1967,   272,   778,  1022,  3030,    40, -1837,   378,
      40,  1902,  1259,   291,   787,    40,   265,  2337,   778,   937,
     265,   265,   778,   268,   928,   929,    40,   265,  1271,   804,
    1200,    40,  1398,  1022,   778,    40,   787,   268,  2403,  1878,
      40,   295,   815,   265,  1022,   787,    40,   301,  2206,   268,
    2403,  1878,   826,  1259,   795,  2147,    40,   832,   329,  1022,
   -1837,    40,    40,  2899,  2796,   870,   343,  1501,   345,    40,
    2194,  2363,    40,    96,  1565,    40,   815,  2762,  1621,  1622,
     815,  1971,  2076, -1837,   815,   938,  2895,  1974,  2857,  1534,
     787,  2696,  2366,   787,  2367,  2368,  2369,  2370,  2371,  2372,
    2279,  2280,  2281,  2282,  2283,  2512,  2366,  1275,  2367,  2368,
    2369,  2370,  2371,  2372,  1151,  1743,  2995,   992,   993,  1157,
    1404,  1600,   391,   557,   647,  2950,  2272,   380,  2393,   268,
    1877,  1878,    40,   388,  2053,  2056,  2798,   695,  2056,   391,
    1806,  2586,    81,    40,  3029,   994,   995,   996,  2965,  2164,
      81,  1011,    62,   382,  1017,  1587,  1260,    64,  1169,    40,
    2971,  1192,  1979,   407,  2363,  2249,   407,  1540,  1426,    40,
     412,  2098,  2363,   397,   407,   878,    81,    40,   654,  2518,
      40,  1137,   656,   938,  1565,  2871,  2359,   181,  1138,    40,
     329,  1158,   329,  3176,   399,   639,   649,  1260,   258,   259,
     260,   261,   262,  1018,  2217,    40,    81,  1298,  1255,  1231,
    1924,  1296,   403,  1193,   938,  1375,   657,   302,    62,   407,
    1383,  1925,    81,   681,   683,    81,   688,   689,   938,   650,
     696,   701,   133,   703,  2872,    70,   706,  2996,  1276,  2148,
     140,   687,   184,   185,   303,  1019,  1341,   689,   707,    40,
     186,    40,   651,  1733,   772,  1604,  1733,  1200,  1980,  1733,
     817,  1384,  3112,  1200,  2823,  1508,   689,   258,   259,   260,
     261,   262,  1566,  2032,  2077,  2032,   772,  1152,   733,   689,
    1276, -1837,   695,  2057,  2080,  2722,  2082,  3015,  2726,   805,
    1559,  2256,  2387,    81,  2387,  2414,  3075,  2476,   939,  2476,
    3109,  1186,  1187,   737,  2414,   821,   823,  1549,   684,    81,
    2516,  2591,   696,  2640,  1744,  2208,  2385,  2723,  2803,    81,
     772,  2373,   821,   821,   684,  2394,  2803,    81,  2828,    34,
     772,   772,  2845,   899,   772,  2373,    76,  2547,   772,    81,
     772,  1535,  1880,   940,   772,    33,   772,  1405,   917,  3110,
     917,   821,  2845,   917,   821,  1400,   917,  1881,  1402,  1403,
    1400,  1214,    78,  1217,   687,   687,   687,   758,  2853,  1575,
     930,  2962,  3012,  1820,  3012,  3177,  2513,  1422,   684,  1623,
     941,   379,  1566,   870,  3083,  1358, -1837,   746,  3083,   788,
    1256,  3104,  2165,  2015,  3127,  1880,  2018,  2338,  1359,    81,
    1863,    81,  3143,  1630,  1631,  2845,  2500,  1880,  1291, -1837,
    1881,  2260,  1641,    40,  2897,    94,  2098,   383,  2207,  1154,
    2269,  1354,  1881,   266,  2481,  2267,  2797,   340,   670,   905,
    1304,  2763,  2862,   862,  2412,  2533,  2909,   940,   699,  1382,
    2374,  1203,  2364,   881,   887,  2291,  1304,   903,   818,  1470,
    2795,   907,  1371,   909,  2374,  1681,  1485,   913,   966,   915,
     980,  1484,  1338,    40,  1975,  2858,  1381,  2360,  2521,  2234,
    2900,  2819,  3069,   931,  2546,   820,  2529,  2530,   941,  2053,
     751,  1307,  1912,  2061,  2008,  1134,   987,  1880,   407, -1837,
    1866,  2988,   753,   754,    75,  2966,  2967,  2375,  1968,   381,
    2920,   756,  1881,   696,   401,   389,   870,   832,   870,   941,
    2734,  2375,  1822,  1656,  1339,   997,  2048,  1220,  1023,  1145,
    1261,  2419,  1537,   941,  2964,  1505,  1748,   772,   772,  1204,
    1236,  1583,   819,  1506,  1550,  2391,   271,  2137,  3103,   819,
    1206,  2792,   772,  2687,  2582,   398,   271,  1400,   772,   772,
    1490,   271,  1552,   772,   819,  2048,   699,  1465,  1471,  2277,
      40,  1261,  2768,   772,  1772,  2994,   400,  1775,   271,  2501,
    2062,  2699,  2092,   271,   129,  2409,  1591,  1592,   271,  2389,
    2048,  1752,  2408,  1912,   404,  2770,  1856,  2063,  3139,  2775,
    3140,  1257,  1023,  1796,   138,  2974,  2753,  2977,  2978,  2979,
    2980,  1570,   796,   998,   942,   943,   944,   271,  1959, -1837,
   -1837, -1837, -1837, -1837,    17,   945,  1361,  1020,  1342,  2851,
    1170,   271,  1994,  2092,  1258,  1734,  2376,  2382,  1737,  1738,
    2064,  1842,  1362,   271,  2048,  1843,  2284,    17,   772,   772,
    2376,   187,  1532,  2554,  1545,  2033,   999,  2047,     1,  2554,
    1902,  2563,  2564,  2565,  2566,  2058,  2081,  2548,  2083,  2545,
     101,   131,  2936,  2257,  2388,   102,  2390,  2415,  1358,  2477,
    2065,  2478,  2377,   772,  1171,  3159,  2483,  1692,   946,   772,
     142,  1359,  2517,  2592,  1344,  2641,  2377,  1346,  2686,  2724,
    2804,   772,  2098,  2378,   140,  2593,   772,  1721,  2810,  2066,
    2829,  1229,  1637,  2597,  2846,  2266,  2968,  2378,  2067,    40,
     103,   104,  1347,   271,  1986,  2799,   144,  3151,   105,  1247,
     193,  2596,   684,  1987,  2852,   194,  2550,     3,     4,  1799,
       5,     6,  1600,  1800,   772,     7,  2299,   904,  2495,  1978,
    2854,   908,   197,  2963,  3013,   912,  3014,  1988,   772,   232,
    1989,   862,     8,     9,  1732,  2740,  3084,  2161,   233,  1395,
    3090,   135,    43,  3105, -1837,  1358,  3128,    40,  1990,  2019,
      10,    11,  1380,   694,  3144,    40,  1488,  3168,  1359,   258,
     259,   260,   261,   262,  3114, -1837,  1199,  3020,  3115,  3022,
   -1544,   827,   862,    40,  2844,  3133,  1386,  2700,  2173,   240,
    1928,  1355,    40,   251,   881,  1363,  1372,  1363,  1600,  1222,
   -1837,  1929,  2703,  1771,  1821,   650,  1774,  2787,   696,  1638,
    2961,   696,   133,  1387,  1390,   248,  1562,   703,  2851,  2851,
    1837,    40,   872,  2706,    40,  2709,  1801,   968,   651,  1802,
     249,   821,   772,  2551,   821,   821,   821,   821,   252,   772,
    2098,  1348,   772,  1360,   878,    80,    40,    40,  1240,    81,
      40,  1600,  1869,   821,  2983,   772,  1604,  1847,    40,   772,
    2492,  2356,  2239,  1643,  1991,  2991,    40,   772,   253,   772,
     772,   256,   772,   772,   772,   772,   772,   772,   772,   772,
     772,   772,   772,   772,   772,   772,   772,   772,   772,  1361,
    1644,  1286,   921,    40,   264,   924,   687,   284,   927,   772,
     772,  1645,  1347,  1693,   772,  1362,   772,  1957,  2407,  1915,
    1917,  1935,  1466,  1375,    40,   695,  1664,  1349,  1992,  1639,
    1183,  1461,  1956,  1646,  2701,  1993,  2702,  1190,  2741,   696,
    1647,    44,  1604,   695,   285,   772,   772,   772,  -265,  2742,
    1374, -1837,  2835,  2552,  2271,    45,   821, -1837,  1487,   287,
    1491,   821,  2535,   288,    40,   772,  2951, -1837,  2953,  1629,
     289,  1694,   106, -1837, -1837,  1633,  2289,  2098,    33,    34,
      46,    81,  3154,  1695,    81,  2802,  2507,   293,  2805,  2806,
    2807,  2808,    40,  1696,   955,  1604,  1361,   294,   107,  2588,
    2589,  2682,   772,    40, -1837,   956,    81,    81,   821,  2993,
      81,  1697,  1362,  2416, -1837,  1597,  2707,  1012,  1598,  2773,
    1599,  1698,    40,  1836,  1699,    40,   296,   772,   687,    47,
     305,  1547,  1672,   821,   821,  -265,  2087,  1700,   821,  2824,
    1600,  1678,  1556,  1557,   772,  2825,   300,  1351,  1811,   687,
    1601,  1348,  -265,    81,   772,  2095,   314,   957,  1472,  1473,
    1474,  1088,  1089,  1090,  2259,   323, -1837,  3130,   696,   108,
   -1837,  1665,   958,    40,    81,   917,   821,   821,  1496,  1209,
    1210,  1211,  1212,   273,  3063,  3064,  1701,   278,  2861,  2093,
    1666,  1667,  1602,   324,   306,  -265,  1603,  2138,  1664,  2139,
      57,  1625,    40,  1600,  1023,  1023,  2292,   330,  2150,  1634,
    1668,  1634, -1837,  1023,    81,  1533,  1702, -1837,   132,   133,
    1091,  1092,  1093,  1094,  1095,  1096,  1703,  1349,   980,   333,
   -1837, -1837, -1837,   334,  2898,  -265,  1097,  1098,  1099,   336,
     881, -1837,   694,  1644,    40, -1837,   335,  1704, -1837,   339,
    1705, -1837,  1706,    81,  1645,  3114,  1023,  1558,  2397,  3115,
    2399,  2400,   959,   109,  -265,  2308,   810,  1573,  1363, -1837,
     832,  2341,   341,  -265,  1604,   816,  1646,  3107,  1936,  1372,
    1707,   307,  1363,  1647,  2975,  1350,   712,   961,   962,  1708,
    2975,   870,   315,  2984,  2985,  2986,  2987,  3135,   308,  3137,
    3074,  1728,  1729,  1730, -1837,   782,  3080, -1837, -1837,  2542,
     352,  2311,  2312,   342,  2581,  2313,  2314,  2315,   791,  1022,
     920,    40,   346,   923,  1597,   347,  1605,  1598,   350,  1599,
    2202,   351,  1089,  1090,   353,  2955,   780,  1604,   772,   772,
     772,   309,   772,  1665,   110,  2728,   356,  1351, -1837,  1600,
     789, -1837,   111,   357,   794,  2730,  1227,  2098,    40,  1601,
    1122, -1837,  1666,  1667, -1837,   367,   808,  1411,   772,   368,
    1233,  1781,  1412, -1837,  1414,  3055,  2969,  1100,  1932,   316,
    1101,   310,  1668,   371,  2548,   772,   376,   132,   133,   387,
    1091,  1092,  1093,  1094,  1095,  1096,   317,   132,   133,   386,
    1378,  1602,    40,  1809,   390,  1603,  1097,  1098,  1099,   772,
     311,  1816,  1817,   772,   821,  2316,  1028,  1029,  1030,   312,
    3082,   394,  2317,  3085,  3086,  3087,  3088,  2001,   396,    40,
    1411,  2230,   715,   715,  1799,  1412,  1413,  1414,  1800,   318,
    2105,  2755,  2106,  2756,   772,  2088,  3025,  1409,  1410,   772,
    3136,  1123,  2923,  1467,  2924,  1467,  2318, -1837,   395,  1845,
   -1837,  1234, -1837,   772,  2107,  2319,   402,  3034,  1184,  1185,
     772,   405,  1188,  1189,  3119,   687,  1574,   133,   772,   319,
     413,   687, -1837,  1604,  1870,  1247,   655,  1895,  2358,   660,
    2361,  2876, -1837,  3055,  2320,  2321,  1651,  1652,  1790,  1102,
    2410,   662,  3079,   687,   663,   821,   821, -1837,   320,   664,
    1606, -1837,  1937,   669,  1103,  1046,   671,   321,  1104,  1659,
    1660,   821,  1815,  1812,  1813,  1938,  1474,   715,   673,  3146,
     674,  1512,   942,   943, -1837,  1605,   675,   932, -1837,  2322,
    1023,  1801,  2203,  2204,  1802,  2109,   677,  1100,  3101,  2111,
    1101,  2484,   678,  3119,  2114,   679,  1105,  1199,  2118,  2002,
    2120,  2121,  2122,  2877,  2833,  2834,  1600,   258,   259,   260,
     261,   262,  2014,  2014,   680,   682,  2014,  2782,   977,   970,
     971,  2323,   972,  1855,  1106,   976,   973,  2781,   974,  1939,
     975,   978,  1895,   979,  2049,  2049,  1940,  2870,  2049,  1895,
     985,   983,  1047,  1107,   984,  2466,    49,    50,    51,    52,
      53,    54,   986,    55,   990,  1009, -1837,   832,  1010,  1048,
    1013,   133,  1015,   870,  1016,  2084,  2738,  1021,  1387,  2878,
    1025,  2879,   772,  1033,  1034,  1941,  1036,  2324,  3025,  1363,
    1124,   821,  1037,  1131,  1038,   870,  2880,  1895,  1039,  1040,
    2627,  2627,  2627,  2627,  2881,  1041,  3034,  1042,  2882,  1043,
    1942,  1044,  1049,  2573,  1055,  2575,  1056,   693, -1837,  1102,
    1943,  1944,  1057,  1060,  1061,  3079,     1,  1064,  1066,   772,
     711,  1067,   772,  2883,  1103,  1108,  1945,  1068,  1104,  1069,
    1363,  1070,  1071,  1072,   772,   772,   772,   772,  1074,  2049,
    1604,   932,  1050,  1136,  1135,  2152,  1809,   783,  1946,  2157,
    2157,  1947,  1948,  1139,  1140,  1143,  1142,  1949,   772,  1606,
    1148,  2785,  1153,   800,   801,  1147,  1105,  1150,  2169,   807,
    1167,  1051,   809,  2620,  2620,  2620,  2620,  1162,  1181,  1191,
    1052,  1194,  1215,  1223,  1224,  2089,  1225,  1121,  1235,  1226,
    1230,  1232,  1109,  1236,  1106,     3,     4,  1244,     5,     6,
    1246,  1267,  1266,     7,  1268,  1200,  1269,  1274,  1278,   687,
     687,  1281,  1284,  1107,  1950,   772,  1282,  1283,  1329,  1337,
       8,     9,  1895,  1895,  1340,  1377,  1951,  1357,  1393,  1423,
    1394,  1895,     3,     4,  1396,     5,     6,  1513,    10,    11,
       7,  1395,  2216,  1514,  1515,  1516,  1397,  2140,  2141,  1474,
    2144,  1406,  1420,  1428,   696,  2061,  1421,     8,     9,  1206,
    2927,  1456,  2240,  1517,  1459,  2729,  1464,  1477,  2935,  2695,
    1497,  2167,  2698,  1510,  1463,    10,    11,  2654,  2655,  2656,
    1012,  2658,  2659,  2660,  2661,  2662,  2663,  2877,  1511,  1483,
    2666,  1499, -1837,  1536,  1495,  1108,  1538,  1539,  1541,  1543,
    1548,  1553,  1551,  1562,  1577,  1023,  1569,  2325,  2326,  2327,
    2328,  2329,  2330,  2331,  2332,  2333,  2334,  1571,  1579,  1576,
    2049,   647,  1276,  1895,    80,  1501,    40,   647,  2199,  1613,
    2275,  1634,  1895,  1615,  1616,   772,  1618,   772,  1624,  2764,
       1,  1673,  2062,  1684,  1717,  2049,    12,  1023,  1686,  1687,
    1719,   832,   832,  2878,  2777,  2879,  2014,  1690,   932,  2063,
    1691,  2779,  1109,  2540,  1720,  1722,  1723,  1724,  1735,  1736,
    2880,  1518,  1740,  1742,  1519,  1749,  1751,  2992,  2881,  2049,
    1753,  2738,  2882,  1895,  1754,  1895,  1780,  1756,   268,  1877,
    1878,    40,    40,   649,  1759,  1783,  2049,  1786,  1520,   649,
    1785,  1787,  2064,  1788,  1791,  1363,  1789,  2883,     3,     4,
    1792,     5,     6,  2627,  2627,  2604,     7,  2627,  1521,     3,
       4,  1793,     5,     6,  1794,  1795,  1798,     7,  1372,    13,
    1363,  1797,  1810,     8,     9,  1275,  3054,  1823,  1728,  1825,
    1826,   772,  2065,  1827,     8,     9,  1834,  1831,  2286,  1840,
    2287,    10,    11,  1522, -1837,  1841,   889,  1846,  1853,  1849,
    1850,  1859,    10,    11,  1873,  1906,  1867,  1907,  1908,   945,
    1914,  2066,  1912,  1523,  1524,  1954,    81,  1955,    14,  1966,
    2067,   772,   772,  1972,  1525,  1983,  1982,  1997,  1999,  1526,
    2000,   772,  2011,  2022,   772,  2023,  2620,  2620,  2024,  2493,
    2620,     1,  2031,  2028,  2070,  2894,   890,  2071,  2894,  2072,
    2073,  2086,  1809,  2074,  2508,  2075,  2510,  2090,  2102, -1837,
    2103,  2110,    12,   772,  2104,  2113,   772,  2128,  1527,  2710,
    2525,  2123,  2745,     2,   772,   772,  2131,  2124,  2125,  2129,
    2133,   695,    81,  2176,   891,  2135,  2146,    15,  2168,  2151,
     772,  2177,  2179,  2166,  2180,  2181,  2738,  2049,  2738,  1895,
    2182,  1528,  2184, -1837,  2183,  1895,  1895,  1895,  1895,  1895,
    1895,  3142,  2201,  3120,  3121,  3122,  3123,  3124,  3125,  2209,
       3,     4,  3062,     5,     6, -1837,  2200, -1837,     7,   821,
    2218,   821,   944,  2238,  2210,   932,  2241,  2211,    88,  2212,
    2213,  2214, -1837,  2243,  2486,     8,     9,  2491,  1895,  2215,
   -1837,  2250,  2252,  2258, -1837,  2262,  2711,  2929,  2263,  2746,
    2273,  2049,  2926,    10,    11, -1837,  2270,  2618,  2618,  2618,
    2618,  2049,  2049,  2712,  2296,  2294,  2747,  2221,  2222, -1837,
    2297,   892,  2643,  2644,  2002,  2295,  2302,  2357,   715,  2627,
    2647,  2365,  2384,  2385,  2386,  2627,  2627,  2395,  2627,  2627,
    2627,  2627,  2392,   862,  2398,  2772,  2411,  2627,  2401, -1783,
     182,   190,  2417,  2467,  2468,  2469,  2713,  2470,  2869,  2748,
    2472,  2471,  1874,  1875,  2473,  1876,  2474,  2475,   268,  1877,
    1878,    40,  2479,  2482,    12,  2485,  2223,  2224,  2225,  2226,
    2227,  2228,  2487,   932,  2494,  2488,  2498,  2502,  2509,   731,
   -1837,  1895,  2506,  1895,  2520,  1879,  2714,   893,  2528,  2749,
    2544,   732,  2690,    15,  2690,   190,  2546,  2538,  1895,  2560,
    2569,   190,  2620,  2049,  2708,  2049,  2849,  2850,  2620,  2620,
    2572,  2620,  2620,  2620,  2620,  2715,  1880,  2583,  2750,  2584,
    2620,  2738,  2363,  2593,  2716,  2600,  2418,  2751,   894,  2638,
    2642,  1881,  1363, -1837,  2652,  2653,  1895,  1023,  2657,  2664,
    1090,  2665,  2671,  1335,  2672,  2677,  2675,  2676,  2605,  2678,
    2679,  2606,  3039,  2680,  2681,  2627,  2207,  2694,  2627,  2627,
    2627,  2627,  2697,  2704,  2607,  2223,  2224,  2225,  2226,  2227,
    2228,   190,  1348,   190,   687,  2718,  2720,  2731,  2725,  2727,
    1975,  2754,  2760,  2765,    13,  3179,  2767,  2219,  2220,  2221,
    2222,  2404,  2766,  2894,   772,  2780,   895,  1091,  1092,  1093,
    1094,  1095,  1096,  2783,  2786,  2609,  2790,  2800,  2768,  2801,
     939,   695, -1837,  1097,  1098,  1099,  2157,  2610,  2815,  2774,
    2157,  2826,  2819,  2836,   821,  2845,  2837,   772,  2838,  2839,
    2855,   821,  2840,    14,  2841,   748,  2856,  2866,  2620,  2842,
    2867,  2620,  2620,  2620,  2620,   772,  2874,   190,  2223,  2224,
    2225,  2226,  2227,  2228,  2889,  2382,   772,  2903,  2902,  2611,
     896,  2907,  2911,  1895,  2627,    15,  2905,  2914,  2906,  2908,
    2919,  1895,  2627,  2921,  1895,  1895,  1895,  1895,  2809,  2925,
    2922,  2928,  2342,  2934,  2932,   772,  2938,  2942, -1837,  2940,
    2944,  2941,  2946,  2954,  2956,  2957,  2952,  2958,  2612,  2343,
    2344,  2959,  2816,  2970,   750,  2960,  2419,  2345,  2972,  2049,
    2613,  2981,  2989,   752,  3008,  2034,   870,  3009,  2275,  3016,
    2618,  2618,  2614,  2615,  2618,  3017,  3018,  3019,  3026,  3037,
    3040,  2616,  3053,  3068,  2617,  2843,  3061,  3052,   709,  3067,
    2778,  2346,   271,  3070,  3081,  3091,  3102,  2620,  3106,  3108,
    2347,  3113,  3126,  3138,  1100,  2620,  3145,  1101,  2049,  3147,
    1625,  3148,  3149,  3150,  3163,  2524,  3173,  3174,  2413,  2793,
    3162,  2480,   785,  2847,  2848,  2849,  2850,  1896,   790,  2348,
     792,  1858,  2192,  1561,   799,    71,    72,   799,   558,  2153,
     799,  2505,  2162,  2619,  2619,  2619,  2619,   348,  2811,   196,
     811,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,   696,   201,   280,   696,  1880,  2690,   672,   860,
    1895,   344,   349,   282,  2349,  1676,   406,   873,   876,   879,
    2112,  1881,   659,   900,  2223,  2224,  2225,  2226,  2227,  2228,
    2757,   910,   375,  1675,   373,   665,  3160,  1833,  1882,   666,
    2130,  2035,  1023,   898,  1333,  2012,  2912,   934,  2917,  1745,
    2020,  1818,  2142,  2036,  1884,  1590,  2350,  1594,  1091,  1092,
    1093,  1094,  1095,  1096,  2814,  2571,  1102,  2237,   821,  3166,
    2149,  1911,  1896,   772,  1097,  1098,  1099,  1933,  2692,  1896,
    2692,  1103,  2207,  2579,  2577,  1104,  2937,  1492,    66,   156,
      67,    68,  1865,  1654,  1655,  1886,  2887,  1868,   806,   969,
    1671,   338,  1612,  2232,   989,  1872,  1272,  1887,  2875,  2999,
    1479,  1895,  1969,  1531,  3134,  1469,  2562,  2685,  3007,  1544,
    1218,  1429,  2684,  1105,  2354,  2136,  2667,  1896,  3167,  1685,
    1392,  2264,  3156,  1895,  2293,  1718,  2049,  3092,  2355,  2705,
    2059,  2910,  2739,  2688,  2049,  2362,  2618,  1031,  1032,  1888,
    2689,  1106,  2618,  2618,  1628,  2618,  2618,  2618,  2618,  3100,
    2896,  2049,  1045,  2049,  2618,  2381,  1895,  2901,  1058,  1059,
    1107,  2645,  1321,  1063,  2998,  3035,  2599,  3036,  2832,  3155,
    2733,  2561,  3011,  1073,  3073,  1289,  2930,  2831,  1889,  2973,
    1588,  2990,  1620,  2982,  1486,  2085,   414,     0,     0,     0,
    1890,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   934,  1891,  1892,  2037,  1100,     0,  1023,  1101,  1023,
       0,  1893,  1895,     0,  1894,     0,     0,  2049,     0,  2917,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,  2602,
    2603,     0,  1896,  1896,     0,   268,  1877,  1878,    40,     0,
    2816,  1896,     0,     0,     0,     0,     0,     0,  1895,  1125,
       0,     0,  2618,     0,     0,  2618,  2618,  2618,  2618,  3089,
       0,     0,  2604,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1625,     0,     0,  2619,  2619,     0,     0,
    2619,     0,  1839,     0,     0,     0,     0,     0,     0,  1109,
     696,     0,  1156,     0,  1895,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1895,     0,     0,  1102,  1173,  1173,
    1173,     0,  1173,     0,  1173,  1173,     0,     0,     0,     0,
      88,    88,  1103,     0,     0,  1909,  1104,     0,     0,     0,
     772,  3131,     0,  1896,     0,     0,     0,     0,   772,     0,
       0,     0,  1896,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2618,     0,   879,  1105,     0,     0,     0,  2893,  2618,
       0,  2893,     0,  2692,  1242,     0,     0,     0,     0,     0,
       0,     0,  1023,     0,  1895,     0,  2049,     0,   695,     0,
       0,     0,  1106,  1896,     0,  1896,     0,     0,   934,  1125,
       0,     0,     0,     0,     0,     0,     0,  1279,     0,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1895,     0,  1287,  1287,     0,     0,     0,     0,     0,
       0,     0,  1401,     0,     0,  1896,     0,     0,     0,  1408,
       0,   772,  1419,  3129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1424,     0,     0,     0,  1427,
       0,     0,     0,     0,     0,     0,     0,  1433,     0,  1435,
    1436,     0,  1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,
    1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,  1453,     0,
       0,     0,     0,  1108,     0,     0,     0,     0,     0,  1454,
    1455,     0,     0,     0,  1457,     0,  1458,     0,     0,     0,
       0,     0,  2619,     0,     0,     0,     0,     0,  2619,  2619,
       0,  2619,  2619,  2619,  2619,     0,     0,     0,     0,     0,
    2619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3172,     0,     0,     0,     0,     0,
    1109,     0,     0,  2692,     0,     0,     0,     0,     0,  1896,
       0,     0,     0,     0,     0,  1896,  1896,  1896,  1896,  1896,
    1896,     0,     0,     0,     0,     0,     0,  2188,  2189,     0,
       0,     0,  1462,  1880,     0,     0,     0,     0,  2198,     0,
      88,     0,    88,   879,   799,     0,   384,     0,  1881,     0,
       0,  1478,   811,     0,     0,   879,     0,     0,  1896,   190,
       0,     0,  1493,     0,     0,  2605,     0,     0,  2606,     0,
       0,     0,     0,     0,     0,   934,     0,  1896,  1896,  1896,
    1896,  2607,     0,     0,     0,     0,     0,     0,  2619,     0,
       0,  2619,  2619,  2619,  2619,  2245,  2246,  2247,  2248,     0,
       0,    88,     0,     0,     0,     0,     0,     0,     0,     0,
    2254,   715,   715,   715,     0,   715,   715,   715,   715,   715,
     715,  2608,  2609,     0,   715,     0,  2893,     0,     0,     0,
       0,     0,     0,     0,  2610,     0,     0,     0,     0,     0,
    1554,     0,     0,     0,  1757,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1896,     0,  1896,  1581,     0,     0,     0,     0,  1584,
       0,     0,  1896,     0,  1896,     0,  2611,     0,  1896,     0,
       0,     0,  1611,   934,     0,  2300,  2301,     0,     0,     0,
    1293,     0,  2305,  2306,     0,     0,     0,  2619,     0,     0,
       0,     0,     0,     0,     0,  2619,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2612,  1896,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,     0,     0,  2613,     0,     0,
       0,     0,     0,  1097,  1098,  1099,     0,  1658,     0,  2614,
    2615,     0,     0,     0,     0,     0,     0,     0,  2616,     0,
       0,  2617,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,     0,     0,     0,     0,     0,     0,  1760,  1761,
    1762,     0,  1764,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       0,   879,     0,  1294,     0,     0,     0,     0,  1779,     0,
       0,  1295,     0,     0,     0,     0,     0,  1296,     0,  1297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1298,   932,     0,     0,     0,     0,   159,     0,     0,     0,
    2496,  2497,     0,     0,     0,     0,     0,     0,     0,  2504,
       0,     0,     0,  1896,     0,   160,     0,  2515,  1299,     0,
       0,  1896,     0,     0,  1896,  1896,  1896,  1896,     0,     0,
       0,     0,     0,     0,  1300,     0,  2531,  2532,     0,  1301,
       0,     0,     0,     0,  1100,     0,     0,  1101,     0,  1835,
       0,  1302,     0,     0,   161,     0,     0,     0,  1303,     0,
       0,     0,     0,  1779,     0,     0,   162,     0,     0,     0,
    1896,  1896,     0,     0,  1896,     0,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2574,     0,
    2576,     0,     0,     0,   164,     0,     0,  2578,     0,  2580,
       0,     0,     0,     0,   165,     0,     0,     0,     0,     0,
       0,     0,  1830,  1086,  1087,  1088,  1089,  1090,     0,     0,
     166,  1838,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   879,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2648,
    2649,     0,   182,  2650,  2651,     0,     0,     0,     0,     0,
     167,     0,  1896,     0,     0,  1896,  1102,  1896,     0,     0,
    1896,     0,     0,     0,  1091,  1092,  1093,  1094,  1095,  1096,
       0,  1103,     0,     0,   168,  1104,     0,  2674,     0,     0,
    1097,  1098,  1099,     0,     0,     0,   879,  1958,   879,   169,
       0,     0,   873,     0,     0,     0,   170,     0,     0,   171,
       0,     0,     0,  1304,     0,     0,     0,     0,     0,     0,
    1305,     0,     0,  1105,     0,     0,     0,     0,     0,     0,
     172,     0,     0,   173,  2006,   174,     0,     0,     0,     0,
       0,     0,  1306,     0,     0,     0,     0,  1307,     0,     0,
       0,  1106,     0,     0,   175,   835,     0,     0,     0,     0,
       0,     0,     0,     0,   836,     0,     0,     0,     0,     0,
    1107,  1896,   176,   837,     0,     0,     0,     0,   838,  2126,
       0,     0,  2126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1896,     0, -1838,     0,     0,     0,     0,
     879,   190,     0,     0,     0,     0,  1896,     0,     0,     0,
       0,     0,  1896,  1896,     0,  1896,  1896,  1896,  1896,     0,
       0, -1838,   839,     0,  1896,     0,  1896,     0,     0,     0,
     840,  1100,     0,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2771,     0,     0,     0,  2776,
   -1838,     0,  1108,     0,     0,     0,     0,  1896,     0,     0,
       0,   879,     0,   879,     0,     0,     0,     0,     0,    40,
       0,     0,   879,     0,     0,     0,     0,     0,     0,     0,
    2791,     0,  1896,     0,     0,     0,   841,     0,     0,     0,
       0,     0, -1838,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2174,   842,   932,     0,  2812,     0,     0,     0,   843,  1109,
     844,     0, -1838,     0,     0,     0, -1838,     0,     0,     0,
     845,     0,     0,     0,     0,     0,     0,     0,  1896,  2197,
       0,     0,  1896,     0,     0,  1896,  1896,  1896,  1896,     0,
   -1838,     0,     0,  1102,     0,     0,   846,     0, -1838,     0,
   -1838,     0,     0,     0,   847,     0,     0,     0,  1103, -1838,
       0,     0,  1104,     0,     0, -1838,     0,     0,     0,     0,
    1896,     0,     0, -1838,  1896,  2231,  1584, -1838,     0,     0,
       0,     0,     0, -1838,  1896,     0,     0, -1838, -1838, -1838,
   -1838,   848,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0, -1838,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   849,     0, -1838,
       0,     0, -1838,     0, -1838,     0,     0,     0,  1106,     0,
       0, -1838,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1896,     0,     0, -1838,     0,     0,  1107,     0,  1896,
       0,     0,     0,     0, -1838,   850,     0,     0,     0,     0,
       0,     0,     0,     0,  1896,     0,   851,     0,     0,     0,
       0,     0,     0, -1838, -1838,  2298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1838,     0,
       0,     0,     0,     0,     0,     0, -1838,     0,     0,  2422,
   -1838,  1896,     0,     0,     0,     0,     0,     0,     0, -1838,
   -1838, -1838,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1108,
    2949,  1779,  1779,     0,     0,   932,     0,     0,     0,  2423,
    2424,  2425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   879,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2426,     0,   852,   853,   854,     0,
       0,     0,  2427,  2519,     0,     0,  1779,  2428, -1838,   855,
       0,     0,     0,     0,  1779,  1779,     0,     0,     0, -1838,
       0,     0,  2429,     0,     0,     0,  1109,  2430,     0,  2431,
       0,     0,     0,     0,     0,   879,  2432,     0,     0,  2433,
       0,     0,  2434,     0,     0,  2435,     0,     0,  2436,     0,
       0,     0,     0,  2437,     0,     0,     0,     0,     0,     0,
   -1838,     0,     0,     0,     0,     0,     0,     0,  1584,     0,
       0,  2438,     0,     0,     0,     0,     0,  2522,     0,   709,
       0,  2526,     0,     0,     0,     0,     0,  2439,     0,     0,
    2440,  2441,     0,     0,  2537,     0,     0,  2442,     0,   190,
       0,     0,     0,     0,     0,     0,     0,     0,  2443,     0,
       0,     0,     0,   856,  3065,     0,     0,     0,     0,     0,
       0,     0, -1838,     0,  2444,     0,     0,     0,     0,     0,
       0,  2445,     0,     0,     0,     0,     0,     0,  2446,     0,
       0,  2447,  2448,  2449,     0,  2450,  2451,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0, -1838,     0,
       0,     0,  2452,     0,     0,     0,  3093,  3094,     0,  3096,
       0,  3098,  3099,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2453,  2454,  2455,  2456,
       0,  2457,     0,     0,     0,  2646,     0,     0,     0,     0,
       0,     0,     0,     0,     0, -1838,     0,     0,  2458,  2459,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1838,
   -1838, -1838, -1838, -1838, -1838, -1838,     0, -1838, -1838,     0,
       0,  2460,     0,     0,     0,  2668,     0,  3141,     0,     0,
    2461,  2462,     0,  2463, -1838,     0,     0,     0,  2683,     0,
       0,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  3152,     0,  3153,     0,     0,     0,     0,  2175,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,     0,     0,     0,     0,     0,     0,  3164,     0,
       0,     0,     0,     0,  2758,  2464,     0,     0,     0,   879,
       0,     0,     0,     0,     0,     0,     0,  1091,  1092,  1093,
    1094,  1095,  1096,  3169,  3170,     0,     0,  3171,     0,     0,
       0,     0,     0,  1097,  1098,  1099,     0,     0,     0,     0,
       0,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1091,  1092,
    1093,  1094,  1095,  1096,     0,  1779,     0,  1097,  1098,  1099,
       0,     0,     0,     0,  1097,  1098,  1099,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   879,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   190,     0,
       0,     0,     1,     0,     0,     0,   416,     0,     0,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,     0,
       0,   934,     0,     0,     0,   418,   419,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   421,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,   424,   425,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,   426,  1101,   427,   428,
     429,     3,     4,   430,     5,     6,   431,     0,   432,     7,
     433,   434,     0,     0,     0,     0,     0,   435,  1100,     0,
     436,  1101,   437,   438,   439,  1100,     8,     9,  1101,     0,
       0,     0,   440,     0,   441,   442,     0,   443,     0,   444,
     445,     0,     0,   446,    10,    11,     0,     0,   447,   448,
     449,     0,   450,   451,     0,     0,     0,   452,   453,     0,
     454,     0,     0,     0,   455,     0,   456,   457,     0,     0,
       0,     0,   458,     0,     0,     0,   459,     0,     0,   460,
       0,   461,     0,   462,     0,   463,     0,   464,   465,  2668,
     466,   467,   468,     0,     0,     0,   469,     0,   470,   471,
       0,   472,     0,     0,     0,     0,     0,     0,     0,   473,
     474,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,   475,     0,     0,   476,   477,     0,     0,   478,
     479,  1103,     0,   480,   481,  1104,     0,     0,     0,     0,
    1102,     0,   482,   483,   484,     0,   485,  1102,     0,     0,
       0,     0,     0,     0,     0,  1103,   486,   487,   488,  1104,
     489,     0,  1103,     0,   490,   491,  1104,     0,     0,   492,
       0,     0,     0,  1105,     0,     0,     0,   493,     0,     0,
       0,   879,     0,     0,     0,   494,   495,   496,     0,     0,
       0,     0,     0,   497,   498,     0,     0,  1105,     0,   499,
       0,  1106,   500,     0,  1105,     0,   501,   502,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   503,     0,     0,
    1107,     0,     0,     0,     0,  1106,     0,     0,     0,     0,
       0,     0,  1106,     0,     0,   504,     0,  1584,     0,     0,
       0,     0,     0,   505,  1107,     0,     0,     0,     0,   506,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,     0,     0,     0,  1584,   507,
       0,   508,   509,     0,     0,     0,     0,     0,     0,     0,
     510,     0,  2668,     0,     0,     0,     0,  3002,     0,  3004,
       0,     0,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1108,     0,     0,   511,
       0,     0,     0,  1108,     0,     0,     0,     0,   879,     0,
     512,     0,     0,     0,   513,     0,   879,     0,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   934,     0,     0,     0,     0,     0,     0,  1109,
       0,     0,   515,   516,     0,     0,     0,   517,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   518,
       0,     0,     0,  1109,     0,   519,   520,   521,   522,     0,
    1109,     0,   523,     0,     0,     0,   524,     0,  1779,     0,
       0,     0,     0,   525,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   529,     0,
     530,     0,     0,   531,     0,     0,     0,     0,     0,   532,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1173,
    1173,  1173,  1173,  1173,  1173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   533,     0,     0,   534,     0,
       0,     0,     0,     0,   535,     0,     0,   536,   537,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   538,     0,     0,     0,     0,     0,     0,   539,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,     0,
       0,     0,   540,   541,   542,   543,   544,   545,   546,     0,
       0,   547,     0,   548,     0,   549,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,     0,     0,  1876,     0,     0,   268,  1877,  1878,
      40,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1091,  1092,  1093,  1094,  1095,  1096,     0,     0,
       0,     0,     0,     0,  1879,   934,     0,     0,  1097,  1098,
    1099,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,     0,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1097,  1098,  1099,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1091,  1092,  1093,  1094,  1095,  1096,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1097,
    1098,  1099,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,     0,  1091,
    1092,  1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,
     695,     0,     0,     0,     0,  1097,  1098,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,     0,  1101,     0,     0,     0,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,     0,     0,  1091,  1092,  1093,  1094,  1095,  1096,
       0,     0,     0,     0,     0,  1100,     0,     0,  1101,     0,
    1097,  1098,  1099,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
    1100,     0,     0,  1101,  1097,  1098,  1099,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1102,     0,     0,     0,     0,  1100,     0,     0,  1101,
    1091,  1092,  1093,  1094,  1095,  1096,  1103,     0,     0,     0,
    1104,  1425,     0,     0,     0,     0,  1097,  1098,  1099,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,     0,  1104,  1741,  1105,     0,
       0,  1100,     0,     0,  1101,  1880,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1881,     0,     0,     0,     0,     0,  1106,     0,     0,     0,
       0,     0,  1102,     0,  1105,     0,     0,  1882,     0,     0,
    1883,     0,     0,     0,     0,  1107,     0,  1103,     0,     0,
       0,  1104,  1750,  1884,     0,  1100,     0,     0,  1101,     0,
       0,     0,  1106,     0,     0,     0,     0,     0,  1102,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1107,     0,  1103,     0,     0,     0,  1104,  1755,  1105,
       0,     0,     0,     0,  1886,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1887,  1100,     0,     0,
    1101,     0,     0,     0,     0,     0,     0,  1106,     0,     0,
       0,     0,     0,  1102,     0,  1105,     0,  1108,     0,     0,
       0,     0,     0,     0,     0,     0,  1107,     0,  1103,     0,
       0,     0,  1104,  1763,     0,     0,     0,     0,  1888,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1108,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,     0,  1102,     0,     0,
    1105,     0,     0,     0,     0,     0,     0,  1889,     0,     0,
       0,     0,  1103,     0,  1109,     0,  1104,  1765,     0,  1890,
       0,     0,     0,     0,     0,     0,     0,     0,  1106,     0,
       0,  1891,  1892,     0,     0,     0,     0,     0,  1108,     0,
    1893,     0,     0,  1894,     0,     0,     0,  1107,     0,  1102,
    1109,   271,     0,     0,  1105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,     0,     0,  1104,  1766,
       0,     0,     0,     0,  1108,     0,     0,     0,     0,     0,
       0,     0,  1106,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,     0,
       0,  1107,     0,     0,     0,  1109,  1105,     0,     0,     0,
       0,     0,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,     0,  1108,
       0,     0,     0,     0,  1106,     0,     0,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,     0,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,  1098,  1099,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,     0,  1108,  1091,  1092,  1093,  1094,  1095,  1096,
       0,     0,     0,     0,     0,     0,  1109,     0,     0,     0,
    1097,  1098,  1099,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1108,     0,     0,  1091,  1092,
    1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,  1097,  1098,  1099,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,  1089,  1090,     0,     0,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,  1098,  1099,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,  1101,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,
       0,  1100,     0,     0,  1101,  1097,  1098,  1099,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,     0,     0,     0,     0,     0,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,     0,  1091,  1092,  1093,  1094,  1095,
    1096,     0,     0,     0,     0,  1100,     0,     0,  1101,     0,
       0,  1097,  1098,  1099,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,     0,
       0,     0,  1100,     0,  1102,  1101,  1097,  1098,  1099,     0,
    1091,  1092,  1093,  1094,  1095,  1096,     0,     0,     0,  1103,
       0,     0,     0,  1104,  1767,     0,  1097,  1098,  1099,     0,
       0,     0,     0,  1102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1103,     0,
       0,     0,  1104,     0,     0,     0,  1100,     0,     0,  1101,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,     0,  1106,
    1105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,  1769,     0,     0,  1104,     0,  1107,     0,
       0,     0,  1100,     0,     0,  1101,     0,     0,  1106,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1107,     0,  1103,
       0,     0,     0,  1104,  1105,     0,     0,  1100,     0,     0,
    1101,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,     0,     0,  1100,     0,     0,
    1101,     0,  1106,     0,     0,     0,     0,     0,  1102,     0,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
    1108,  1107,     0,  1103,  1770,     0,     0,  1104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1108,
       0,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1107,     0,
       0,     0,     0,     0,  1102,  1105,     0,  1097,  1098,  1099,
       0,     0,     0,     0,     0,     0,     0,     0,  1773,  1103,
       0,     0,     0,  1104,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,  1108,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,     0,  1103,     0,  1109,   202,  1104,  1102,
       0,  1105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1103,     0,     0,     0,  1104,     0,
    1108,     0,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1106,
       0,     0,   203,   204,     0,     0,  1105,     0,  1097,  1098,
    1099,   205,     0,     0,     0,     0,     0,     0,  1107,     0,
    1109,     0,     0,     0,     0,     0,  1105,  1085,  1086,  1087,
    1088,  1089,  1090,     0,  1106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1108,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,  1106,     0,     0,  1109,  1100,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1107,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,     0,     0,     0,  1091,
    1092,  1093,  1094,  1095,  1096,     0,     0,     0,     0,     0,
    1108,     0,     0,     0,     0,  1097,  1098,  1099,     0,     0,
       0,  1109,     0,     0,     0,   158,     0,     0,     0,     0,
       0,     0,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,     0,     0,     0,     0,  1108,     0,     0,     0,     0,
       0,     0,  1091,  1092,  1093,  1094,  1095,  1096,     0,  1100,
       0,     0,  1101,     0,   159,  1108,     0,     0,  1097,  1098,
    1099,     0,     0,     0,     0,     0,     0,  1109,     0,     0,
       0,     0,     0,   160,     0,     0,     0,     0,     0,     0,
    1102,     0,   206,     0,     0,     0,     0,  1091,  1092,  1093,
    1094,  1095,  1096,     0,     0,  1103,     0,     0,     0,  1104,
       0,     0,  1109,  1097,  1098,  1099,     0,     0,     0,     0,
       0,     0,   161,     0,     0,     0,     0,     0,     0,     0,
       0,   207,  1109,     0,   162,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   163,   719,   720,  1105,     0,     0,
     208,   268,   721,   722,    40,     0,  1100,     0,     0,  1101,
       0,     0,   164,     0,     0,     0,   209,     0,     0,     0,
       0,     0,   165,   723,     0,  1106,     0,     0,   724,     0,
       0,  1102,     0,     0,     0,   725,     0,     0,   166,   210,
       0,     0,     0,     0,  1107,     0,  1103,   719,   720,     0,
    1104,   211,     0,   268,   721,   722,    40,     0,     0,  1100,
       0,   212,  1101,   726,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   723,     0,     0,   167,   213,
     724,     0,     0,     0,     0,     0,     0,   725,  1105,   214,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,     0,  1100,   215,     0,  1101,     0,     0,
       0,     0,     0,     0,     0,   726,  1106,   169,     0,     0,
       0,     0,     0,     0,   170,     0,  1108,   171,  1102,     0,
       0,     0,     0,     0,     0,  1107,     0,     0,     0,     0,
       0,     0,     0,  1103,     0,   216,     0,  1104,   172,     0,
       0,   173,     0,   174,    81,     0,   727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,   175,     0,     0,     0,     0,     0,     0,     0,
       0,  1102,     0,     0,   218,  1105,     0,     0,     0,     0,
     176,   219,     0,  1109,   220,     0,  1103,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,    81,     0,   727,     0,
       0,     0,     0,  1106,     0,   221,     0,  1108,   222,     0,
     223,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,  1107,     0,     0,     0,     0,     0,  1105,   224,
       0,  1103,     0,     0,     0,  1104,     0,     0,     0,     0,
       0,  1768,     0,   728,     0,     0,     0,   225,   729,     0,
       0,     0,     0,     0,     0,     0,  1106,     0,   719,   720,
       0,     0,     0,     0,   268,   721,   722,    40,     0,     0,
       0,     0,     0,  1105,  1109,  1107,   730,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   723,     0,     0,     0,
     226,   724,     0,     0,     0,   728,     0,     0,   725,     0,
     729,  1106,     0,     0,  1108,     0,     0,  1874,  1875,     0,
    1876,   731,     0,   268,  1877,  1878,    40,     0,     0,     0,
    1107,     0,     0,   732,     0,     0,   726,     0,   730,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1879,   733,     0,     0,     0,     0,   734,     0,     0,   735,
       0,     0,     0,     0,     0,     0,     0,  1108,     0,     0,
     736,     0,     0,   731,     0,     0,   737,     0,     0,     0,
       0,  1109,     0,     0,     0,   732,   738,     0,     0,     0,
       0,   739,     0,     0,   740,     0,     0,   741,     0,     0,
       0,     0,     0,   733,     0,     0,   742,   743,   734,     0,
       0,   735,  1108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,     0,     0,     0,    81,   737,   727,
       0,     0,     0,     0,  1109,     0,     0,     0,   738,     0,
       0,     0,     0,   739,     0,     0,   740,  1196,   744,   741,
       0,     0,   745,     0,     0,     0,     0,     0,   742,   743,
     746,     0,     0,     0,     0,     0,  1874,  1875,     0,  1876,
       0,   747,   268,  1877,  1878,    40,   695,   748,     0,  1109,
     719,   720,     0,     0,     0,     0,   268,   721,   722,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1879,
     744,     0,   749,     0,   745,     0,     0,     0,   723,     0,
       0,     0,   746,   724,     0,     0,     0,     0,     0,     0,
     725,     0,     0,   747,     0,  2143,   728,     0,     0,   748,
       0,   729,     0,     0,     0,     0,  1874,  1875,     0,  1876,
       0,     0,   268,  1877,  1878,    40,   750,     0,   726,     0,
       0,     0,     0,   751,   749,   752,     0,     0,     0,   730,
       0,     0,     0,     0,     0,   753,   754,   755,     0,  1879,
       0,     0,     0,     0,   756,     0,     0,     0,     0,     0,
    2034,     0,  2602,  2603,     0,   271,     0,     0,   268,  1877,
    1878,    40,     0,     0,   731,     0,     0,     0,   750,     0,
       0,     0,     0,     0,     0,   751,   732,   752,     0,     0,
       0,     0,     0,     0,     0,  2604,     0,   753,   754,   755,
       0,     0,     0,     0,   733,   695,   756,  1874,  1875,   734,
    1876,     0,   735,   268,  1877,  1878,    40,   271,     0,    81,
       0,   727,     0,   736,     0,     0,     0,     0,     0,   737,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   738,
    1879,     0,     0,     0,   739,     0,     0,   740,     0,     0,
     741,     0,     0,     0,     0,     0,     0,     0,     0,   742,
     743,  1880,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   695,  1881,  1874,  1875,     0,
    1876,     0,     0,   268,  1877,  1878,    40,     0,     0,     0,
       0,     0,     0,  1882,     0,     0,  2035,     0,     0,     0,
    2541,   744,     0,     0,     0,   745,     0,     0,  2036,  1884,
    1879,     0,     0,   746,     0,     0,     0,     0,   728,     0,
       0,   695,     0,   729,   747,     0,  1874,  1875,     0,  1876,
     748,     0,   268,  1877,  1878,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1886,   730,     0,     0,     0,   749,     0,     0,     0,  1879,
       0,     0,  1887,     0,  2602,  2603,   695,     0,     0,     0,
     268,  1877,  1878,    40,     0,     0,     0,     0,     0,  2034,
       0,     0,     0,     0,     0,     0,   731,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2604,   732,   750,
       0,     0,     0,     0,  1888,     0,   751,     0,   752,     0,
    1880,     0,     0,     0,     0,     0,   733,     0,   753,   754,
     755,   734,     0,     0,   735,  1881,     0,   756,     0,     0,
       0,     0,     0,     0,     0,   736,   695,     0,   271,     0,
       0,   737,  1882,  1889,     0,  1883,     0,     0,     0,     0,
       0,   738,     0,     0,     0,  1890,   739,     0,  1884,   740,
       0,     0,   741,     0,     0,     0,     0,  1891,  1892,  2037,
       0,   742,   743,     0,     0,     0,  1893,     0,     0,  1894,
    1880,     0,     0,     0,     0,   695,     0,   271,     0,     0,
       0,     0,     0,     0,     0,  1881,     0,     0,  1885,  1886,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1887,  1882,   744,     0,  2035,     0,   745,     0,     0,
       0,     0,     0,   695,     0,   746,  1880,  2036,  1884,     0,
       0,     0,     0,     0,     0,     0,   747,     0,     0,     0,
       0,  1881,   748,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1888,     0,     0,     0,     0,  2605,     0,
       0,  2606,     0,     0,     0,     0,     0,   749,     0,  1886,
       0,  1880,     0,     0,  2607,     0,     0,     0,     0,     0,
       0,  1887,     0,     0,     0,     0,  1881,     0,     0,     0,
       0,     0,  1889,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2207,  1882,  1890,     0,  1883,  1936,     0,     0,
       0,   750,     0,     0,     0,  2609,  1891,  1892,   751,  1884,
     752,     0,     0,  1888,     0,  1893,     0,  2610,  1894,     0,
     753,   754,   755,     0,     0,     0,   271,     0,     0,   756,
       0,  1880,     0,     0,     0,     0,     0,  2207,     0,     0,
     271,     0,     0,     0,     0,     0,  1881,     0,     0,     0,
    1886,     0,  1889,     0,     0,     0,     0,     0,     0,  2611,
       0,     0,  1887,  1882,  1890,     0,  1883,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,  1892,     0,  1884,
    1880,     0,     0,     0,     0,  1893,     0,     0,  1894,     0,
       0,     0,     0,     0,     0,  1881,   271,     0,  2612,     0,
       0,     0,  3041,     0,  1888,     0,     0,     0,     0,     0,
    2613,     0,  1882,     0,     0,  1883,     0,     0,  1880,  3076,
    1886,     0,  2614,  2615,     0,     0,     0,     0,  1884,     0,
       0,  2616,  1887,  1881,  2617,     0,     0,     0,     0,     0,
       0,     0,   271,  1889,     0,     0,     0,     0,     0,     0,
    2605,     0,     0,  2606,     0,  1890,     0,     0,  3042,     0,
       0,     0,     0,     0,     0,     0,  2607,  1891,  1892,  1886,
       0,     0,     0,     0,  1888,     0,  1893,     0,     0,  1894,
       0,  1887,     0,  3043,     0,     0,     0,   271,     0,     0,
       0,     0,  3044,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2609,     0,     0,
       0,     0,     0,  1889,     0,     0,     0,     0,     0,  2610,
       0,     0,     0,  1888,     0,  1890,     0,     0,  3045,     0,
       0,  1937,     0,     0,     0,     0,  3046,  1891,  1892,     0,
       0,     0,     0,     0,  1938,     0,  1893,     0,     0,  1894,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,  2611,  1889,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1890,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,  1892,     0,     0,
       0,     0,     0,     0,     0,  1893,     0,     0,  1894,     0,
    2612,     0,     0,     0,     0,     0,   271,     0,  1939,     0,
       0,     0,  2613,     0,     0,  1940,     0,     0,     0,     0,
       0,     0,     0,     0,  2614,  2615,     0,     0,     0,     0,
    3047,     0,     0,  2616,     0,     0,  2617,     0,     0,     0,
       0,     0,     0,     0,   271,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1941,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1942,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1943,
    1944,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1945,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1946,     0,     0,
    1947,  1948,     0,     0,     0,     0,  1949,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1950,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3048,     0,  1951
};

static const short yycheck[] =
{
       2,   713,   187,   327,   834,   193,   845,   710,   696,   497,
      12,    13,   863,   515,   417,    65,   211,   420,   421,   985,
    1494,   992,     0,   841,   842,   521,   844,   830,   846,   847,
     999,   434,  1691,   362,    81,  1555,   926,   422,    61,   153,
     175,   543,    44,    45,   546,    23,  1271,  1272,  1406,   452,
     940,    29,   455,  1695,   507,  1984,  1861,  1374,   461,   445,
     513,  1743,   465,  1371,   517,  2170,   469,   117,   871,  1303,
     473,    94,  1360,    75,   477,   478,    78,   480,   263,  1802,
     483,   784,   485,   486,   487,   735,     5,    65,    90,   224,
     493,   479,  1614,   496,    26,    97,  2280,  2281,  2282,   101,
     503,    26,   104,   105,  2394,   508,    20,     5,   110,   111,
       5,  2283,    26,   516,   387,     5,    26,   140,     5,   504,
     504,   144,   236,   237,   527,  2261,     5,   957,   531,   959,
    1935,    24,   535,    26,    26,    73,    74,    18,   541,   117,
       5,   544,    23,    24,    25,    50,     5,   149,   508,     5,
     152,   339,    23,   539,    25,   157,   417,    23,    18,    25,
    2212,  2213,  2214,  2215,    54,    25,    56,    62,    58,    78,
      24,     5,    26,    68,    23,    24,    25,    26,    48,    23,
      24,    25,    26,     5,    23,    24,    25,    26,    24,    26,
      26,   452,    86,   195,   455,    24,    25,    26,    48,     5,
      26,  1579,    32,   226,   465,    26,     5,   120,   469,    51,
       5,     5,   473,    23,    24,    25,    26,     5,   930,   480,
       5,    26,  1027,    24,   485,    26,   487,    23,    24,    25,
      26,   233,   493,     5,    24,   496,    26,   239,  1880,    23,
      24,    25,   503,    32,    24,    20,    26,   508,   250,    24,
      77,    26,    26,     5,  2544,   516,   279,     5,   281,    26,
      24,     6,    26,   286,    22,    26,   527,     5,   121,   122,
     531,  1626,   193,    22,   535,   260,  2696,   135,   135,   330,
     541,  2376,     9,   544,    11,    12,    13,    14,    15,    16,
      34,    35,    36,    37,    38,   375,     9,     5,    11,    12,
      13,    14,    15,    16,   444,   377,     5,    42,    43,   533,
    1038,   281,   335,   363,   364,  2797,  1975,     5,   416,    23,
      24,    25,    26,     5,  1686,  1687,     5,   176,  1690,   352,
    1804,  2260,   176,    26,  2918,    70,    71,    72,  2820,     5,
     176,   695,    17,     5,   525,   175,   176,     0,    25,    26,
    2832,   319,   161,   355,     6,  1923,   358,  1208,  1060,    26,
     358,  1739,     6,     5,   366,    24,   176,    26,   366,  2174,
      26,   606,   377,   260,    22,   525,  2035,    24,   613,    26,
     382,   605,   384,   148,     5,   363,   364,   176,    17,    18,
      19,    20,    21,   574,   416,    26,   176,   234,   148,   895,
     424,   221,     5,   371,   260,  1374,   411,   416,    83,   411,
     563,   435,   176,   411,   416,   176,   418,   419,   260,   612,
     422,   423,   444,   425,   574,    30,   428,   126,   136,  1791,
       5,   834,    17,    18,   443,     5,     5,   439,    25,    26,
      25,    26,   635,     5,   446,   415,     5,     5,   257,     5,
     360,   604,  3036,     5,  2590,  1167,   458,    17,    18,    19,
      20,    21,   220,     5,   385,     5,   468,   607,   373,   471,
     136,   220,   176,     5,     5,  2397,     5,  2897,  2400,   481,
     325,     5,     5,   176,     5,     5,  2968,     5,   330,     5,
     525,   852,   853,   398,     5,   497,   498,  1225,   335,   176,
       5,     5,   504,     5,   576,  1883,     5,     5,     5,   176,
     512,   238,   514,   515,   335,   613,     5,   176,     5,    28,
     522,   523,     5,   525,   526,   238,   528,   381,   530,   176,
     532,   582,   381,   375,   536,    27,   538,  1039,   540,   574,
     542,   543,     5,   545,   546,  1033,   548,   396,  1036,  1037,
    1038,   880,   613,   882,   957,   958,   959,   446,     5,  1247,
     370,     5,     5,   495,     5,   330,   646,  1055,   335,   422,
     555,   377,   220,   834,     5,   231,   426,   482,     5,   468,
     330,     5,  1807,  1665,     5,   381,  1668,   500,   244,   176,
     348,   176,     5,  1296,  1297,     5,   444,   381,   958,   348,
     396,  1959,  1305,    26,  2699,   339,  1984,   269,   457,   370,
    1972,   416,   396,   412,  2134,  1970,  2545,   412,   412,   528,
     457,   359,   448,   512,   412,  2193,   416,   375,  1013,  1013,
     357,   526,   377,   522,   523,  1997,   457,   526,   548,  1135,
     412,   530,   416,   532,   357,  1348,  1148,   536,   650,   538,
     673,  1147,   976,    26,   512,   512,  1010,  2035,  2178,   529,
     412,   540,  2952,   473,   377,  1153,  2186,  2187,   555,  2031,
     575,   491,   537,   352,   533,   613,   678,   381,   680,   529,
    1570,  2853,   587,   588,   576,  2821,  2822,   414,   582,   377,
    2742,   596,   396,   695,   269,   377,   957,   958,   959,   555,
     501,   414,  1507,   370,   977,   440,   599,   605,   710,   543,
     540,   533,  1200,   555,  2819,   605,   576,   719,   720,   614,
     565,  1260,   654,   613,  1226,   377,   607,   563,  3018,   654,
     649,  2536,   734,   377,  2256,   377,   607,  1225,   740,   741,
     654,   607,  1230,   745,   654,   599,  1131,  1131,  1136,  1983,
      26,   540,   537,   755,  1456,  2860,   377,  1459,   607,   607,
     439,     9,  1731,   607,   604,  2082,  1268,  1269,   607,  2057,
     599,  1421,  2080,   537,   377,  2498,   325,   456,  3068,  2502,
    3070,   531,   784,   412,   607,  2837,  2468,  2839,  2840,  2841,
    2842,  1244,   572,   528,   636,   637,   638,   607,   457,   626,
     627,   628,   629,   630,     0,   647,   462,   377,   377,  2624,
     487,   607,  1642,  1782,   564,   377,   543,   444,   377,   377,
     499,   377,   478,   607,   599,   377,   570,    23,   830,   831,
     543,   416,  1193,  2211,  1220,   377,   571,   377,    29,  2217,
    2218,  2219,  2220,  2221,  2222,   377,   377,  2209,   377,  2207,
      41,   228,   412,   377,   377,    46,   377,   377,   231,   377,
     539,   377,   589,   865,   541,   224,   377,    49,   597,   871,
     339,   244,   377,   377,   988,   377,   589,   991,   377,   377,
     377,   883,  2260,   610,     5,   457,   888,  1383,   377,   568,
     377,   893,   345,   465,   377,  1968,  2825,   610,   577,    26,
      91,    92,   143,   607,   327,  2547,     5,  3091,    99,   911,
     444,  2273,   335,   336,   377,    13,   345,   108,   109,   149,
     111,   112,   281,   153,   926,   116,  2008,   527,  2153,  1632,
     377,   531,   508,   377,   377,   535,   377,   360,   940,   416,
     363,   830,   133,   134,  1397,   317,   377,   177,    98,   576,
     377,    20,   341,   377,   325,   231,   377,    26,   381,   310,
     151,   152,  1009,    24,   377,    26,  1151,   377,   244,    17,
      18,    19,    20,    21,   333,   346,   865,  2909,   337,  2911,
     607,    24,   871,    26,   416,   268,    20,   235,  1827,   522,
     424,   993,    26,   444,   883,   997,   998,   999,   281,   888,
     310,   435,  2380,  1456,  1506,   612,  1459,  2527,  1010,   462,
    2815,  1013,   444,  1015,  1016,   416,   565,  1019,  2833,  2834,
      25,    26,    24,  2385,    26,  2387,   256,   634,   635,   259,
     416,  1033,  1034,   462,  1036,  1037,  1038,  1039,   416,  1041,
    2418,   282,  1044,   416,    24,    24,    26,    26,    24,   176,
      26,   281,    20,  1055,  2845,  1057,   415,  1553,    26,  1061,
      20,  2032,  1913,   154,   487,  2856,    26,  1069,   416,  1071,
    1072,   411,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,   462,
     424,    24,   542,    26,    25,   545,  1499,   416,   548,  1101,
    1102,   435,   143,   285,  1106,   478,  1108,   234,  2079,  1597,
    1598,  1613,    24,  2082,    26,   176,   467,   358,   541,   572,
     849,  1123,  1618,   457,   372,   548,   374,   856,   500,  1131,
     464,   520,   415,   176,   416,  1137,  1138,  1139,   352,   511,
     416,   612,  2606,   572,  1974,   534,  1148,   224,  1150,   444,
    1152,  1153,    24,   416,    26,  1157,  2798,   467,  2800,  1294,
     416,   343,   353,   634,   635,  1300,  1996,  2545,    27,    28,
     559,   176,  3104,   355,   176,  2553,    20,   416,  2556,  2557,
    2558,  2559,    26,   365,   321,   415,   462,    25,   379,  2262,
    2263,    24,  1194,    26,   565,   332,   176,   176,  1200,  2858,
     176,   383,   478,  2093,   281,   256,    20,  1895,   259,    20,
     261,   393,    26,  1542,   396,    26,   416,  1219,  1621,   608,
     613,  1223,  1336,  1225,  1226,   439,  1722,   409,  1230,  2591,
     281,  1345,  1234,  1235,  1236,  2593,   416,   478,  1499,  1642,
     291,   282,   456,   176,  1246,  1733,   613,   384,  1137,  1138,
    1139,    19,    20,    21,  1957,    25,   333,    20,  1260,   450,
     337,   612,   399,    26,   176,  1267,  1268,  1269,  1157,   600,
     601,   602,   603,   195,  2946,  2947,   458,   199,  2640,  1732,
     631,   632,   333,    25,   352,   499,   337,  1783,   467,  1785,
      24,  1293,    26,   281,  1296,  1297,  1999,    25,  1794,  1301,
     651,  1303,   612,  1305,   176,  1194,   488,   268,   443,   444,
      78,    79,    80,    81,    82,    83,   498,   358,  1341,    25,
     281,   631,   632,    25,  2702,   539,    94,    95,    96,   377,
    1219,   149,    24,   424,    26,   153,   607,   519,   415,   444,
     522,   651,   524,   176,   435,   333,  1348,  1236,  2071,   337,
    2073,  2074,   489,   544,   568,  2021,   487,  1246,  1360,   177,
    1621,  2027,    25,   577,   415,   496,   457,  3026,    84,  1371,
     552,   439,  1374,   464,  2838,   416,   439,   627,   628,   561,
    2844,  1642,   352,  2847,  2848,  2849,  2850,  3059,   456,  3061,
    2965,  1393,  1394,  1395,   626,   458,  2971,   629,   630,  2202,
     607,    59,    60,    25,  2255,    63,    64,    65,   471,    24,
     541,    26,    25,   544,   256,    25,   467,   259,    25,   261,
    1873,    25,    20,    21,    44,  2803,   455,   415,  1430,  1431,
    1432,   499,  1434,   612,   625,  2406,   377,   478,   256,   281,
     469,   259,   633,   416,   473,  2414,    24,  2825,    26,   291,
     416,   347,   631,   632,   415,   607,   485,    18,  1460,    25,
     416,  1463,    23,   281,    25,  2939,  2828,   235,   310,   439,
     238,   539,   651,   416,  2836,  1477,   416,   443,   444,     5,
      78,    79,    80,    81,    82,    83,   456,   443,   444,   412,
      24,   333,    26,  1495,   377,   337,    94,    95,    96,  1501,
     568,  1503,  1504,  1505,  1506,   163,    94,    95,    96,   577,
    2974,   607,   170,  2977,  2978,  2979,  2980,    24,   244,    26,
      18,  1906,   444,   445,   149,    23,    24,    25,   153,   499,
      23,    23,    25,    25,  1536,  1723,  2914,    24,    25,  1541,
    3060,   507,    23,  1132,    25,  1134,   204,   256,    25,  1551,
     259,   507,   261,  1555,  1749,   213,   412,  2919,   850,   851,
    1562,   377,   854,   855,  3038,  1968,   443,   444,  1570,   539,
     347,  1974,   281,   415,  1576,  1577,    20,  1579,  2034,    25,
    2036,    47,   291,  3057,   242,   243,   273,   274,  1477,   357,
    2086,    25,  2970,  1996,    25,  1597,  1598,   415,   568,    25,
     651,   310,   318,    25,   372,   352,    20,   577,   376,   629,
     630,  1613,  1501,   636,   637,   331,  1505,   539,   416,  3083,
      25,    24,   636,   637,   333,   467,    25,   549,   337,   287,
    1632,   256,  1874,  1875,   259,  1750,    25,   235,  3016,  1754,
     238,  2137,   607,  3117,  1759,   377,   414,  1536,  1763,  1651,
    1765,  1766,  1767,   119,  2602,  2603,   281,    17,    18,    19,
      20,    21,  1664,  1665,     5,   377,  1668,  2518,     5,   377,
     288,   329,   377,  1562,   442,   611,   377,  2516,   377,   395,
     377,   377,  1684,   288,  1686,  1687,   402,  2653,  1690,  1691,
     611,   377,   439,   461,   377,  2098,     4,     5,     6,     7,
       8,     9,   377,    11,   377,   416,   415,  1968,   607,   456,
     604,   444,   607,  1974,     8,  1717,  2419,   412,  1720,   185,
     465,   187,  1724,   416,   512,   441,   416,   385,  3106,  1731,
     406,  1733,   416,   252,   416,  1996,   202,  1739,   416,   416,
    2279,  2280,  2281,  2282,   210,   416,  3108,   416,   214,   416,
     466,   416,   499,  2241,   416,  2243,   416,   421,   467,   357,
     476,   477,   416,   416,   416,  3143,    29,   416,   416,  1771,
     434,   416,  1774,   239,   372,   543,   492,   416,   376,   416,
    1782,   416,   416,   416,  1786,  1787,  1788,  1789,   416,  1791,
     415,   713,   539,     5,   445,  1797,  1798,   461,   514,  1801,
    1802,   517,   518,   605,   605,   406,   582,   523,  1810,   651,
     646,  2523,   646,   477,   478,   445,   414,   416,  1820,   483,
       8,   568,   486,  2279,  2280,  2281,  2282,   312,   583,     5,
     577,     5,   369,   416,   416,  1724,   416,   759,   576,   416,
     416,   330,   610,   565,   442,   108,   109,     8,   111,   112,
      13,     5,   562,   116,   646,     5,   646,   406,   416,  2262,
    2263,   416,    51,   461,   580,  1867,    25,    25,    77,   444,
     133,   134,  1874,  1875,   444,     5,   592,    25,   582,    20,
     607,  1883,   108,   109,   416,   111,   112,   290,   151,   152,
     116,   576,  1894,   296,   297,   298,   416,  1786,  1787,  1788,
    1789,   457,   416,    20,  1906,   352,   613,   133,   134,   649,
    2761,   416,  1914,   316,   416,  2411,   416,   416,  2769,  2375,
     336,  1810,  2378,    17,   613,   151,   152,  2313,  2314,  2315,
    2618,  2317,  2318,  2319,  2320,  2321,  2322,   119,    18,   613,
    2326,   543,   651,     5,   612,   543,    25,    25,   138,   204,
      24,   610,   576,   565,     5,  1957,   468,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   624,   468,   533,   607,
    1972,  2021,   136,  1975,    24,     5,    26,  2027,  1867,   533,
    1982,  1983,  1984,    25,   385,  1987,   307,  1989,   533,  2485,
      29,    25,   439,   416,   651,  1997,   222,  1999,   416,   416,
     377,  2262,  2263,   185,  2506,   187,  2008,   416,   930,   456,
     416,  2513,   610,  2201,   607,   563,   444,   533,   377,   377,
     202,   424,   377,   377,   427,   377,    25,  2857,   210,  2031,
     377,  2734,   214,  2035,   377,  2037,   416,   377,    23,    24,
      25,    26,    26,  2021,   377,   604,  2048,     5,   451,  2027,
     613,     5,   499,     5,   607,  2057,   566,   239,   108,   109,
       5,   111,   112,  2602,  2603,    50,   116,  2606,   471,   108,
     109,   469,   111,   112,   613,   377,   612,   116,  2080,   342,
    2082,   416,   416,   133,   134,     5,  2937,   540,  2090,    25,
      25,  2093,   539,   416,   133,   134,    51,   522,  1987,     5,
    1989,   151,   152,   506,   311,     5,    90,   377,   346,   416,
     416,   583,   151,   152,    13,   406,   613,   406,     5,   647,
     533,   568,   537,   526,   527,     5,   176,    25,   391,    86,
     577,  2133,  2134,   416,   537,   613,   607,   416,   612,   542,
       5,  2143,   626,   412,  2146,   412,  2602,  2603,   446,  2151,
    2606,    29,   416,   446,   416,  2694,   140,   416,  2697,   416,
     416,     8,  2164,   416,  2166,   416,  2168,     5,    25,   119,
      25,   377,   222,  2175,   576,   377,  2178,   377,   581,   352,
    2182,    24,   352,    61,  2186,  2187,   377,    24,    24,    24,
       5,   176,   176,   311,   178,   607,     5,   423,     8,   607,
    2202,    24,   330,   607,   330,   444,  2909,  2209,  2911,  2211,
     607,   614,   416,   346,   330,  2217,  2218,  2219,  2220,  2221,
    2222,  3072,   444,  3041,  3042,  3043,  3044,  3045,  3046,   416,
     108,   109,  2944,   111,   112,   185,   411,   187,   116,  2241,
       5,  2243,   638,    25,   416,  1167,     5,   416,    60,   416,
     416,   416,   202,     5,  2143,   133,   134,  2146,  2260,   416,
     210,     5,     5,    25,   214,   582,   439,  2763,   582,   439,
     416,  2273,  2760,   151,   152,   225,   604,  2279,  2280,  2281,
    2282,  2283,  2284,   456,     5,   607,   456,    19,    20,   239,
       5,   275,  2294,  2295,  2296,   607,     5,   416,  1220,  2838,
    2302,     7,   377,     5,   607,  2844,  2845,    25,  2847,  2848,
    2849,  2850,   613,  2202,    25,  2500,     8,  2856,    25,   607,
     132,   133,   377,   613,   377,    25,   499,   576,  2652,   499,
     377,   613,    17,    18,   377,    20,   377,   377,    23,    24,
      25,    26,   377,    20,   222,     5,    78,    79,    80,    81,
      82,    83,   553,  1275,   377,   260,     5,     5,     5,   343,
     226,  2363,   533,  2365,     5,    50,   539,   351,   377,   539,
     613,   355,  2374,   423,  2376,   187,   377,   558,  2380,   607,
     426,   193,  2838,  2385,  2386,  2387,    19,    20,  2844,  2845,
     607,  2847,  2848,  2849,  2850,   568,   381,   377,   568,   416,
    2856,  3104,     6,   457,   577,   613,     5,   577,   392,   540,
     613,   396,  2414,   196,   611,   611,  2418,  2419,    24,    24,
      21,    24,   606,   967,   432,    25,    24,    24,   413,    25,
      25,   416,  2928,    25,    25,  2974,   457,   416,  2977,  2978,
    2979,  2980,   416,    25,   429,    78,    79,    80,    81,    82,
      83,   263,   282,   265,  2857,    25,     5,   254,   377,   377,
     512,   576,   454,     5,   342,  3177,   377,    17,    18,    19,
      20,  2077,   416,  3012,  2476,   226,   460,    78,    79,    80,
      81,    82,    83,    24,   412,   470,   377,     5,   537,   377,
     330,   176,   426,    94,    95,    96,  2498,   482,    20,  2501,
    2502,   125,   540,   416,  2506,     5,   416,  2509,   416,   416,
       5,  2513,   416,   391,   416,   499,    13,   607,  2974,   416,
     196,  2977,  2978,  2979,  2980,  2527,     5,   339,    78,    79,
      80,    81,    82,    83,   427,   444,  2538,    25,   377,   524,
     524,    25,     5,  2545,  3083,   423,   377,   354,   377,   377,
     606,  2553,  3091,   317,  2556,  2557,  2558,  2559,  2560,   377,
     416,   359,   145,    25,   555,  2567,   377,   416,   227,   377,
     330,   377,   377,   377,   377,   377,   613,   377,   563,   162,
     163,   377,  2584,   416,   568,   562,   533,   170,   377,  2591,
     575,   607,    13,   577,   225,   280,  2857,   225,  2600,     7,
    2602,  2603,   587,   588,  2606,    25,   613,   377,   433,    25,
     378,   596,   607,   613,   599,  2617,   377,   416,   430,   377,
    2509,   204,   607,   613,   377,   416,   412,  3083,     5,     5,
     213,   377,    24,   227,   235,  3091,   377,   238,  2640,   377,
    2642,   377,   377,   377,     5,  2181,   377,   377,  2090,  2538,
    3127,  2133,   464,    17,    18,    19,    20,  1579,   470,   242,
     472,  1563,  1857,  1237,   476,    36,    38,   479,   363,  1798,
     482,  2164,  1804,  2279,  2280,  2281,  2282,   286,  2567,   140,
     492,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,  2694,   144,   208,  2697,   381,  2699,   395,   511,
    2702,   280,   287,   210,   287,  1341,   352,   519,   520,   521,
    1757,   396,   370,   525,    78,    79,    80,    81,    82,    83,
    2471,   533,   315,  1340,   314,   382,  3117,  1536,   413,   384,
    1774,   416,  2734,   525,   964,  1662,  2738,   549,  2740,  1411,
    1669,  1505,  1788,   428,   429,  1267,   329,  1270,    78,    79,
      80,    81,    82,    83,  2570,  2236,   357,  1910,  2760,  3141,
    1792,  1593,  1684,  2765,    94,    95,    96,  1608,  2374,  1691,
    2376,   372,   457,  2252,  2250,   376,  2777,  1153,    23,   117,
      29,    29,  1568,  1327,  1328,   470,  2674,  1574,   482,   652,
    1334,   265,  1275,  1908,   680,  1577,   931,   482,  2671,  2874,
    1144,  2803,  1624,  1191,  3057,  1134,  2218,  2353,  2884,  1219,
     883,  1065,  2351,   414,  2030,  1782,  2335,  1739,  3143,  1354,
    1019,  1968,  3108,  2825,  2000,  1377,  2828,  2995,  2031,  2384,
    1690,  2734,  2420,  2363,  2836,  2037,  2838,   719,   720,   524,
    2365,   442,  2844,  2845,  1293,  2847,  2848,  2849,  2850,  3012,
    2697,  2853,   734,  2855,  2856,  2048,  2858,  2708,   740,   741,
     461,  2296,   960,   745,  2866,  2920,  2274,  2921,  2601,  3106,
    2418,  2217,  2889,   755,  2962,   956,  2765,  2600,   563,  2836,
    1262,  2855,  1289,  2844,  1149,  1720,   361,    -1,    -1,    -1,
     575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   713,   587,   588,   589,   235,    -1,  2909,   238,  2911,
      -1,   596,  2914,    -1,   599,    -1,    -1,  2919,    -1,  2921,
      -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,  1874,  1875,    -1,    23,    24,    25,    26,    -1,
    2962,  1883,    -1,    -1,    -1,    -1,    -1,    -1,  2970,   781,
      -1,    -1,  2974,    -1,    -1,  2977,  2978,  2979,  2980,  2981,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2995,    -1,    -1,  2602,  2603,    -1,    -1,
    2606,    -1,  1546,    -1,    -1,    -1,    -1,    -1,    -1,   610,
    3012,    -1,   824,    -1,  3016,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3026,    -1,    -1,   357,   840,   841,
     842,    -1,   844,    -1,   846,   847,    -1,    -1,    -1,    -1,
     852,   853,   372,    -1,    -1,  1589,   376,    -1,    -1,    -1,
    3052,  3053,    -1,  1975,    -1,    -1,    -1,    -1,  3060,    -1,
      -1,    -1,  1984,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3083,    -1,   895,   414,    -1,    -1,    -1,  2694,  3091,
      -1,  2697,    -1,  2699,   906,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3104,    -1,  3106,    -1,  3108,    -1,   176,    -1,
      -1,    -1,   442,  2035,    -1,  2037,    -1,    -1,   930,   931,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   939,    -1,    -1,
      -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3143,    -1,   955,   956,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1034,    -1,    -1,  2077,    -1,    -1,    -1,  1041,
      -1,  3163,  1044,  3052,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1057,    -1,    -1,    -1,  1061,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1069,    -1,  1071,
    1072,    -1,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,  1101,
    1102,    -1,    -1,    -1,  1106,    -1,  1108,    -1,    -1,    -1,
      -1,    -1,  2838,    -1,    -1,    -1,    -1,    -1,  2844,  2845,
      -1,  2847,  2848,  2849,  2850,    -1,    -1,    -1,    -1,    -1,
    2856,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3163,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,  2889,    -1,    -1,    -1,    -1,    -1,  2211,
      -1,    -1,    -1,    -1,    -1,  2217,  2218,  2219,  2220,  2221,
    2222,    -1,    -1,    -1,    -1,    -1,    -1,  1851,  1852,    -1,
      -1,    -1,  1124,   381,    -1,    -1,    -1,    -1,  1862,    -1,
    1132,    -1,  1134,  1135,  1136,    -1,     5,    -1,   396,    -1,
      -1,  1143,  1144,    -1,    -1,  1147,    -1,    -1,  2260,  1151,
      -1,    -1,  1154,    -1,    -1,   413,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,  1167,    -1,  2279,  2280,  2281,
    2282,   429,    -1,    -1,    -1,    -1,    -1,    -1,  2974,    -1,
      -1,  2977,  2978,  2979,  2980,  1919,  1920,  1921,  1922,    -1,
      -1,  1193,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1934,  2313,  2314,  2315,    -1,  2317,  2318,  2319,  2320,  2321,
    2322,   469,   470,    -1,  2326,    -1,  3012,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,    -1,
    1232,    -1,    -1,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,  2363,    -1,  2365,  1256,    -1,    -1,    -1,    -1,  1261,
      -1,    -1,  2374,    -1,  2376,    -1,   524,    -1,  2380,    -1,
      -1,    -1,  1274,  1275,    -1,  2009,  2010,    -1,    -1,    -1,
     104,    -1,  2016,  2017,    -1,    -1,    -1,  3083,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3091,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   563,  2418,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,   575,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    -1,  1329,    -1,   587,
     588,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   596,    -1,
      -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1430,  1431,
    1432,    -1,  1434,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,    -1,    -1,
      -1,  1383,    -1,   207,    -1,    -1,    -1,    -1,  1460,    -1,
      -1,   215,    -1,    -1,    -1,    -1,    -1,   221,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     234,  2523,    -1,    -1,    -1,    -1,   285,    -1,    -1,    -1,
    2154,  2155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2163,
      -1,    -1,    -1,  2545,    -1,   304,    -1,  2171,   262,    -1,
      -1,  2553,    -1,    -1,  2556,  2557,  2558,  2559,    -1,    -1,
      -1,    -1,    -1,    -1,   278,    -1,  2190,  2191,    -1,   283,
      -1,    -1,    -1,    -1,   235,    -1,    -1,   238,    -1,  1541,
      -1,   295,    -1,    -1,   343,    -1,    -1,    -1,   302,    -1,
      -1,    -1,    -1,  1555,    -1,    -1,   355,    -1,    -1,    -1,
    2602,  2603,    -1,    -1,  2606,    -1,   365,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2242,    -1,
    2244,    -1,    -1,    -1,   383,    -1,    -1,  2251,    -1,  2253,
      -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1534,    17,    18,    19,    20,    21,    -1,    -1,
     409,  1543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2303,
    2304,    -1,  1574,  2307,  2308,    -1,    -1,    -1,    -1,    -1,
     449,    -1,  2694,    -1,    -1,  2697,   357,  2699,    -1,    -1,
    2702,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,   372,    -1,    -1,   473,   376,    -1,  2341,    -1,    -1,
      94,    95,    96,    -1,    -1,    -1,  1618,  1619,  1620,   488,
      -1,    -1,  1624,    -1,    -1,    -1,   495,    -1,    -1,   498,
      -1,    -1,    -1,   457,    -1,    -1,    -1,    -1,    -1,    -1,
     464,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,
     519,    -1,    -1,   522,  1656,   524,    -1,    -1,    -1,    -1,
      -1,    -1,   486,    -1,    -1,    -1,    -1,   491,    -1,    -1,
      -1,   442,    -1,    -1,   543,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
     461,  2803,   561,   132,    -1,    -1,    -1,    -1,   137,  1771,
      -1,    -1,  1774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2825,    -1,    22,    -1,    -1,    -1,    -1,
    1722,  1723,    -1,    -1,    -1,    -1,  2838,    -1,    -1,    -1,
      -1,    -1,  2844,  2845,    -1,  2847,  2848,  2849,  2850,    -1,
      -1,    48,   181,    -1,  2856,    -1,  2858,    -1,    -1,    -1,
     189,   235,    -1,    -1,   238,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2499,    -1,    -1,    -1,  2503,
      77,    -1,   543,    -1,    -1,    -1,    -1,  2889,    -1,    -1,
      -1,  1783,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    26,
      -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2534,    -1,  2914,    -1,    -1,    -1,   245,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1832,   270,  2944,    -1,  2568,    -1,    -1,    -1,   277,   610,
     279,    -1,   149,    -1,    -1,    -1,   153,    -1,    -1,    -1,
     289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2970,  1861,
      -1,    -1,  2974,    -1,    -1,  2977,  2978,  2979,  2980,    -1,
     177,    -1,    -1,   357,    -1,    -1,   315,    -1,   185,    -1,
     187,    -1,    -1,    -1,   323,    -1,    -1,    -1,   372,   196,
      -1,    -1,   376,    -1,    -1,   202,    -1,    -1,    -1,    -1,
    3012,    -1,    -1,   210,  3016,  1907,  1908,   214,    -1,    -1,
      -1,    -1,    -1,   220,  3026,    -1,    -1,   224,   225,   226,
     227,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     414,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   386,    -1,   256,
      -1,    -1,   259,    -1,   261,    -1,    -1,    -1,   442,    -1,
      -1,   268,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3083,    -1,    -1,   281,    -1,    -1,   461,    -1,  3091,
      -1,    -1,    -1,    -1,   291,   424,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3106,    -1,   435,    -1,    -1,    -1,
      -1,    -1,    -1,   310,   311,  2007,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   333,    -1,    -1,   266,
     337,  3143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   346,
     347,   348,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,
    2794,  2133,  2134,    -1,    -1,  3177,    -1,    -1,    -1,   306,
     307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2086,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   331,    -1,   535,   536,   537,    -1,
      -1,    -1,   339,  2175,    -1,    -1,  2178,   344,   415,   548,
      -1,    -1,    -1,    -1,  2186,  2187,    -1,    -1,    -1,   426,
      -1,    -1,   359,    -1,    -1,    -1,   610,   364,    -1,   366,
      -1,    -1,    -1,    -1,    -1,  2137,   373,    -1,    -1,   376,
      -1,    -1,   379,    -1,    -1,   382,    -1,    -1,   385,    -1,
      -1,    -1,    -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,
     467,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2170,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    -1,  2179,    -1,  2181,
      -1,  2183,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,
     427,   428,    -1,    -1,  2196,    -1,    -1,   434,    -1,  2201,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   445,    -1,
      -1,    -1,    -1,   652,  2948,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,    -1,   461,    -1,    -1,    -1,    -1,    -1,
      -1,   468,    -1,    -1,    -1,    -1,    -1,    -1,   475,    -1,
      -1,   478,   479,   480,    -1,   482,   483,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   565,    -1,
      -1,    -1,   499,    -1,    -1,    -1,  3000,  3001,    -1,  3003,
      -1,  3005,  3006,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   523,   524,   525,   526,
      -1,   528,    -1,    -1,    -1,  2297,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   612,    -1,    -1,   545,   546,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,
     627,   628,   629,   630,   631,   632,    -1,   634,   635,    -1,
      -1,   568,    -1,    -1,    -1,  2337,    -1,  3071,    -1,    -1,
     577,   578,    -1,   580,   651,    -1,    -1,    -1,  2350,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,  3095,    -1,  3097,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,  3132,    -1,
      -1,    -1,    -1,    -1,  2476,   642,    -1,    -1,    -1,  2411,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,  3157,  3158,    -1,    -1,  3161,    -1,    -1,
      -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    78,    79,
      80,    81,    82,    83,    -1,  2527,    -1,    94,    95,    96,
      -1,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2500,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2523,    -1,    -1,    -1,    52,    53,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   235,    -1,   103,   238,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    -1,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,   124,   235,    -1,
     127,   238,   129,   130,   131,   235,   133,   134,   238,    -1,
      -1,    -1,   139,    -1,   141,   142,    -1,   144,    -1,   146,
     147,    -1,    -1,   150,   151,   152,    -1,    -1,   155,   156,
     157,    -1,   159,   160,    -1,    -1,    -1,   164,   165,    -1,
     167,    -1,    -1,    -1,   171,    -1,   173,   174,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,   183,    -1,    -1,   186,
      -1,   188,    -1,   190,    -1,   192,    -1,   194,   195,  2671,
     197,   198,   199,    -1,    -1,    -1,   203,    -1,   205,   206,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   216,
     217,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,   232,   233,    -1,    -1,   236,
     237,   372,    -1,   240,   241,   376,    -1,    -1,    -1,    -1,
     357,    -1,   249,   250,   251,    -1,   253,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   372,   263,   264,   265,   376,
     267,    -1,   372,    -1,   271,   272,   376,    -1,    -1,   276,
      -1,    -1,    -1,   414,    -1,    -1,    -1,   284,    -1,    -1,
      -1,  2763,    -1,    -1,    -1,   292,   293,   294,    -1,    -1,
      -1,    -1,    -1,   300,   301,    -1,    -1,   414,    -1,   306,
      -1,   442,   309,    -1,   414,    -1,   313,   314,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,
     461,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,
      -1,    -1,   442,    -1,    -1,   342,    -1,  2819,    -1,    -1,
      -1,    -1,    -1,   350,   461,    -1,    -1,    -1,    -1,   356,
      -1,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,    -1,  2860,   386,
      -1,   388,   389,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     397,    -1,  2874,    -1,    -1,    -1,    -1,  2879,    -1,  2881,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,   436,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,  2920,    -1,
     447,    -1,    -1,    -1,   451,    -1,  2928,    -1,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2944,    -1,    -1,    -1,    -1,    -1,    -1,   610,
      -1,    -1,   479,   480,    -1,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   496,
      -1,    -1,    -1,   610,    -1,   502,   503,   504,   505,    -1,
     610,    -1,   509,    -1,    -1,    -1,   513,    -1,  3060,    -1,
      -1,    -1,    -1,   520,   521,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   532,    -1,   534,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   545,    -1,
     547,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,   556,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3041,
    3042,  3043,  3044,  3045,  3046,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,   585,    -1,
      -1,    -1,    -1,    -1,   591,    -1,    -1,   594,   595,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   609,    -1,    -1,    -1,    -1,    -1,    -1,   616,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,   639,   640,   641,   642,   643,   644,   645,    -1,
      -1,   648,    -1,   650,    -1,   652,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    50,  3177,    -1,    -1,    94,    95,
      96,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    95,    96,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      95,    96,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,
      -1,    -1,   238,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,   235,    -1,    -1,   238,    -1,
      94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
     235,    -1,    -1,   238,    94,    95,    96,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,    -1,    -1,    -1,   235,    -1,    -1,   238,
      78,    79,    80,    81,    82,    83,   372,    -1,    -1,    -1,
     376,   377,    -1,    -1,    -1,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,    -1,    -1,   376,   377,   414,    -1,
      -1,   235,    -1,    -1,   238,   381,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     396,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,
      -1,    -1,   357,    -1,   414,    -1,    -1,   413,    -1,    -1,
     416,    -1,    -1,    -1,    -1,   461,    -1,   372,    -1,    -1,
      -1,   376,   377,   429,    -1,   235,    -1,    -1,   238,    -1,
      -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   461,    -1,   372,    -1,    -1,    -1,   376,   377,   414,
      -1,    -1,    -1,    -1,   470,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   482,   235,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    -1,
      -1,    -1,    -1,   357,    -1,   414,    -1,   543,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,   372,    -1,
      -1,    -1,   376,   377,    -1,    -1,    -1,    -1,   524,    -1,
      -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,    -1,    -1,    -1,    -1,   357,    -1,    -1,
     414,    -1,    -1,    -1,    -1,    -1,    -1,   563,    -1,    -1,
      -1,    -1,   372,    -1,   610,    -1,   376,   377,    -1,   575,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,
      -1,   587,   588,    -1,    -1,    -1,    -1,    -1,   543,    -1,
     596,    -1,    -1,   599,    -1,    -1,    -1,   461,    -1,   357,
     610,   607,    -1,    -1,   414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,   377,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   442,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,   461,    -1,    -1,    -1,   610,   414,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,   543,
      -1,    -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   461,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   543,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,
      94,    95,    96,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
     610,    -1,    -1,    -1,    94,    95,    96,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,    -1,   238,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,   238,    94,    95,    96,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,   235,    -1,    -1,   238,    -1,
      -1,    94,    95,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,   357,   238,    94,    95,    96,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,   372,
      -1,    -1,    -1,   376,   377,    -1,    94,    95,    96,    -1,
      -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,    -1,
      -1,    -1,   376,    -1,    -1,    -1,   235,    -1,    -1,   238,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   357,    -1,   442,
     414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   372,   427,    -1,    -1,   376,    -1,   461,    -1,
      -1,    -1,   235,    -1,    -1,   238,    -1,    -1,   442,    -1,
      -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,   372,
      -1,    -1,    -1,   376,   414,    -1,    -1,   235,    -1,    -1,
     238,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,   235,    -1,    -1,
     238,    -1,   442,    -1,    -1,    -1,    -1,    -1,   357,    -1,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     543,   461,    -1,   372,   427,    -1,    -1,   376,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,
      -1,    78,    79,    80,    81,    82,    83,    -1,   461,    -1,
      -1,    -1,    -1,    -1,   357,   414,    -1,    94,    95,    96,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   427,   372,
      -1,    -1,    -1,   376,    -1,    -1,    -1,   610,    -1,    -1,
      -1,    -1,    -1,   442,    -1,    -1,    -1,    -1,    -1,   357,
      -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   461,    -1,   372,    -1,   610,    31,   376,   357,
      -1,   414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,    -1,    -1,    -1,   376,    -1,
     543,    -1,    78,    79,    80,    81,    82,    83,    -1,   442,
      -1,    -1,    66,    67,    -1,    -1,   414,    -1,    94,    95,
      96,    75,    -1,    -1,    -1,    -1,    -1,    -1,   461,    -1,
     610,    -1,    -1,    -1,    -1,    -1,   414,    16,    17,    18,
      19,    20,    21,    -1,   442,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   461,   442,    -1,    -1,   610,   235,    -1,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   461,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
     543,    -1,    -1,    -1,    -1,    94,    95,    96,    -1,    -1,
      -1,   610,    -1,    -1,    -1,   246,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,   543,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,   235,
      -1,    -1,   238,    -1,   285,   543,    -1,    -1,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,
      -1,    -1,    -1,   304,    -1,    -1,    -1,    -1,    -1,    -1,
     357,    -1,   246,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,   372,    -1,    -1,    -1,   376,
      -1,    -1,   610,    94,    95,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   343,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   285,   610,    -1,   355,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   365,    17,    18,   414,    -1,    -1,
     304,    23,    24,    25,    26,    -1,   235,    -1,    -1,   238,
      -1,    -1,   383,    -1,    -1,    -1,   320,    -1,    -1,    -1,
      -1,    -1,   393,    45,    -1,   442,    -1,    -1,    50,    -1,
      -1,   357,    -1,    -1,    -1,    57,    -1,    -1,   409,   343,
      -1,    -1,    -1,    -1,   461,    -1,   372,    17,    18,    -1,
     376,   355,    -1,    23,    24,    25,    26,    -1,    -1,   235,
      -1,   365,   238,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,   449,   383,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    57,   414,   393,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   473,    -1,   235,   409,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,   442,   488,    -1,    -1,
      -1,    -1,    -1,    -1,   495,    -1,   543,   498,   357,    -1,
      -1,    -1,    -1,    -1,    -1,   461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   372,    -1,   449,    -1,   376,   519,    -1,
      -1,   522,    -1,   524,   176,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,
      -1,    -1,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   357,    -1,    -1,   488,   414,    -1,    -1,    -1,    -1,
     561,   495,    -1,   610,   498,    -1,   372,    -1,    -1,    -1,
     376,    -1,    -1,    -1,    -1,    -1,   176,    -1,   178,    -1,
      -1,    -1,    -1,   442,    -1,   519,    -1,   543,   522,    -1,
     524,    -1,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
      -1,    -1,   461,    -1,    -1,    -1,    -1,    -1,   414,   543,
      -1,   372,    -1,    -1,    -1,   376,    -1,    -1,    -1,    -1,
      -1,   427,    -1,   275,    -1,    -1,    -1,   561,   280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,    -1,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,   414,   610,   461,   308,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
     604,    50,    -1,    -1,    -1,   275,    -1,    -1,    57,    -1,
     280,   442,    -1,    -1,   543,    -1,    -1,    17,    18,    -1,
      20,   343,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
     461,    -1,    -1,   355,    -1,    -1,    85,    -1,   308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      50,   373,    -1,    -1,    -1,    -1,   378,    -1,    -1,   381,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   543,    -1,    -1,
     392,    -1,    -1,   343,    -1,    -1,   398,    -1,    -1,    -1,
      -1,   610,    -1,    -1,    -1,   355,   408,    -1,    -1,    -1,
      -1,   413,    -1,    -1,   416,    -1,    -1,   419,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,   428,   429,   378,    -1,
      -1,   381,   543,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,    -1,   176,   398,   178,
      -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,   408,    -1,
      -1,    -1,    -1,   413,    -1,    -1,   416,   469,   470,   419,
      -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,   428,   429,
     482,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,   493,    23,    24,    25,    26,   176,   499,    -1,   610,
      17,    18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
     470,    -1,   524,    -1,   474,    -1,    -1,    -1,    45,    -1,
      -1,    -1,   482,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,   493,    -1,   495,   275,    -1,    -1,   499,
      -1,   280,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    26,   568,    -1,    85,    -1,
      -1,    -1,    -1,   575,   524,   577,    -1,    -1,    -1,   308,
      -1,    -1,    -1,    -1,    -1,   587,   588,   589,    -1,    50,
      -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,    -1,    -1,
     280,    -1,    17,    18,    -1,   607,    -1,    -1,    23,    24,
      25,    26,    -1,    -1,   343,    -1,    -1,    -1,   568,    -1,
      -1,    -1,    -1,    -1,    -1,   575,   355,   577,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,   587,   588,   589,
      -1,    -1,    -1,    -1,   373,   176,   596,    17,    18,   378,
      20,    -1,   381,    23,    24,    25,    26,   607,    -1,   176,
      -1,   178,    -1,   392,    -1,    -1,    -1,    -1,    -1,   398,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      50,    -1,    -1,    -1,   413,    -1,    -1,   416,    -1,    -1,
     419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   428,
     429,   381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   396,    17,    18,    -1,
      20,    -1,    -1,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,   413,    -1,    -1,   416,    -1,    -1,    -1,
     469,   470,    -1,    -1,    -1,   474,    -1,    -1,   428,   429,
      50,    -1,    -1,   482,    -1,    -1,    -1,    -1,   275,    -1,
      -1,   176,    -1,   280,   493,    -1,    17,    18,    -1,    20,
     499,    -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     470,   308,    -1,    -1,    -1,   524,    -1,    -1,    -1,    50,
      -1,    -1,   482,    -1,    17,    18,   176,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,   280,
      -1,    -1,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,   355,   568,
      -1,    -1,    -1,    -1,   524,    -1,   575,    -1,   577,    -1,
     381,    -1,    -1,    -1,    -1,    -1,   373,    -1,   587,   588,
     589,   378,    -1,    -1,   381,   396,    -1,   596,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   392,   176,    -1,   607,    -1,
      -1,   398,   413,   563,    -1,   416,    -1,    -1,    -1,    -1,
      -1,   408,    -1,    -1,    -1,   575,   413,    -1,   429,   416,
      -1,    -1,   419,    -1,    -1,    -1,    -1,   587,   588,   589,
      -1,   428,   429,    -1,    -1,    -1,   596,    -1,    -1,   599,
     381,    -1,    -1,    -1,    -1,   176,    -1,   607,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,   469,   470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   482,   413,   470,    -1,   416,    -1,   474,    -1,    -1,
      -1,    -1,    -1,   176,    -1,   482,   381,   428,   429,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,
      -1,   396,   499,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   524,    -1,    -1,    -1,    -1,   413,    -1,
      -1,   416,    -1,    -1,    -1,    -1,    -1,   524,    -1,   470,
      -1,   381,    -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,
      -1,   482,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
      -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   457,   413,   575,    -1,   416,    84,    -1,    -1,
      -1,   568,    -1,    -1,    -1,   470,   587,   588,   575,   429,
     577,    -1,    -1,   524,    -1,   596,    -1,   482,   599,    -1,
     587,   588,   589,    -1,    -1,    -1,   607,    -1,    -1,   596,
      -1,   381,    -1,    -1,    -1,    -1,    -1,   457,    -1,    -1,
     607,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,    -1,
     470,    -1,   563,    -1,    -1,    -1,    -1,    -1,    -1,   524,
      -1,    -1,   482,   413,   575,    -1,   416,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   587,   588,    -1,   429,
     381,    -1,    -1,    -1,    -1,   596,    -1,    -1,   599,    -1,
      -1,    -1,    -1,    -1,    -1,   396,   607,    -1,   563,    -1,
      -1,    -1,   189,    -1,   524,    -1,    -1,    -1,    -1,    -1,
     575,    -1,   413,    -1,    -1,   416,    -1,    -1,   381,   469,
     470,    -1,   587,   588,    -1,    -1,    -1,    -1,   429,    -1,
      -1,   596,   482,   396,   599,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   607,   563,    -1,    -1,    -1,    -1,    -1,    -1,
     413,    -1,    -1,   416,    -1,   575,    -1,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   587,   588,   470,
      -1,    -1,    -1,    -1,   524,    -1,   596,    -1,    -1,   599,
      -1,   482,    -1,   270,    -1,    -1,    -1,   607,    -1,    -1,
      -1,    -1,   279,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   470,    -1,    -1,
      -1,    -1,    -1,   563,    -1,    -1,    -1,    -1,    -1,   482,
      -1,    -1,    -1,   524,    -1,   575,    -1,    -1,   315,    -1,
      -1,   318,    -1,    -1,    -1,    -1,   323,   587,   588,    -1,
      -1,    -1,    -1,    -1,   331,    -1,   596,    -1,    -1,   599,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   607,    -1,    -1,
      -1,   524,   563,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   587,   588,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   596,    -1,    -1,   599,    -1,
     563,    -1,    -1,    -1,    -1,    -1,   607,    -1,   395,    -1,
      -1,    -1,   575,    -1,    -1,   402,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   587,   588,    -1,    -1,    -1,    -1,
     417,    -1,    -1,   596,    -1,    -1,   599,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   466,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,
     477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   514,    -1,    -1,
     517,   518,    -1,    -1,    -1,    -1,   523,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   590,    -1,   592
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    61,   108,   109,   111,   112,   116,   133,   134,
     151,   152,   222,   342,   391,   423,   713,   741,   742,   792,
     959,  1014,  1016,  1017,  1018,  1023,  1025,  1038,  1039,  1040,
    1041,  1042,  1457,    27,    28,   714,   715,   716,   717,   718,
      26,   924,  1476,   341,   520,   534,   559,   608,  1458,  1458,
    1458,  1458,  1458,  1458,  1458,  1458,   924,    24,   924,  1378,
    1043,   743,   742,  1457,     0,  1015,  1018,  1023,  1041,  1457,
      30,   716,   718,   924,  1460,   576,   924,  1459,   613,   793,
      24,   176,   740,   741,   912,   924,   929,  1044,  1080,  1081,
    1082,  1083,  1084,  1088,   339,   745,   746,   747,   748,   751,
     752,    41,    46,    91,    92,    99,   353,   379,   450,   544,
     625,   633,   713,   719,   884,   958,  1019,  1020,  1022,  1026,
    1027,  1033,  1045,  1066,  1199,  1209,  1457,   924,  1459,   604,
    1083,   228,   443,   444,  1090,    20,   924,  1087,   607,   746,
       5,   744,   339,   924,     5,   768,   770,   771,   924,  1210,
     924,   924,  1200,  1034,   924,   924,  1022,  1028,   246,   285,
     304,   343,   355,   365,   383,   393,   409,   449,   473,   488,
     495,   498,   519,   522,   524,   543,   561,   794,   795,   796,
     799,    24,  1080,  1086,    17,    18,    25,   416,   663,   665,
    1080,  1091,  1092,   444,    13,   791,   748,   508,  1186,   749,
     746,   751,    31,    66,    67,    75,   246,   285,   304,   320,
     343,   355,   365,   383,   393,   409,   449,   473,   488,   495,
     498,   519,   522,   524,   543,   561,   604,   754,   762,   773,
     774,   924,   416,    98,   924,   740,   885,  1067,   924,   801,
     522,   753,   777,   779,   780,   778,   787,   788,   416,   416,
     800,   444,   416,   416,   746,   775,   411,   663,    17,    18,
      19,    20,    21,   664,    25,     5,   412,  1091,    23,    24,
      25,   607,   924,   930,    18,    24,    25,   750,   930,   764,
     753,   765,   777,   778,   416,   416,   763,   444,   416,   416,
     775,   746,   772,   416,    25,   924,   416,  1035,   740,   740,
     416,   924,   416,   443,   757,   613,   352,   439,   456,   499,
     539,   568,   577,   781,   613,   352,   439,   456,   499,   539,
     568,   577,   789,    25,    25,   802,   803,   804,   805,   924,
      25,   760,   761,    25,    25,   607,   377,   663,  1092,   444,
     412,    25,    25,   746,   757,   746,    25,    25,   745,   760,
      25,    25,   607,    44,   769,  1211,   377,   416,  1201,  1477,
    1478,  1479,  1480,  1481,   886,  1068,  1029,   607,    25,   782,
     783,   416,   784,   789,   790,   784,   416,   785,     5,   377,
       5,   377,     5,   269,     5,   794,   412,     5,     5,   377,
     377,   746,   776,  1091,   607,    25,   244,     5,   377,     5,
     377,   269,   412,     5,   377,   377,   776,   924,  1097,  1098,
    1100,  1046,  1097,   347,  1478,  1186,    33,    40,    52,    53,
      55,    69,    76,    87,    88,    89,   103,   105,   106,   107,
     110,   113,   115,   117,   118,   124,   127,   129,   130,   131,
     139,   141,   142,   144,   146,   147,   150,   155,   156,   157,
     159,   160,   164,   165,   167,   171,   173,   174,   179,   183,
     186,   188,   190,   192,   194,   195,   197,   198,   199,   203,
     205,   206,   208,   216,   217,   229,   232,   233,   236,   237,
     240,   241,   249,   250,   251,   253,   263,   264,   265,   267,
     271,   272,   276,   284,   292,   293,   294,   300,   301,   306,
     309,   313,   314,   324,   342,   350,   356,   386,   388,   389,
     397,   436,   447,   451,   455,   479,   480,   484,   496,   502,
     503,   504,   505,   509,   513,   520,   521,   532,   534,   545,
     547,   550,   556,   582,   585,   591,   594,   595,   609,   616,
     639,   640,   641,   642,   643,   644,   645,   648,   650,   652,
     656,   657,   658,   659,   676,   698,   712,   713,   719,   720,
     739,   807,   808,   809,   810,   821,   822,   823,   824,   876,
     880,   910,   932,   933,   936,   937,   938,   939,   952,   960,
     983,   984,   986,   990,  1005,  1006,  1010,  1011,  1012,  1013,
    1021,  1036,  1049,  1060,  1061,  1062,  1073,  1076,  1113,  1116,
    1118,  1124,  1125,  1128,  1131,  1134,  1136,  1138,  1140,  1147,
    1152,  1156,  1157,  1158,  1170,  1171,  1174,  1180,  1181,  1182,
    1207,  1222,  1223,  1224,  1225,  1226,  1231,  1237,  1238,  1256,
    1259,  1288,  1290,  1379,  1380,  1411,  1412,  1419,  1430,  1457,
    1461,  1466,  1468,  1470,  1474,  1475,  1482,   713,  1024,  1457,
     612,   635,  1069,  1070,  1097,    20,   377,   411,   758,   781,
      25,   786,    25,    25,    25,   803,   805,   797,   761,    25,
     412,    20,   758,   416,    25,    25,   755,    25,   607,   377,
       5,  1097,   377,   924,   335,   925,   926,  1476,   924,   924,
    1154,   919,   925,   919,    24,   176,   924,  1089,  1452,  1453,
    1454,   924,  1472,   924,  1233,  1234,   924,    25,   660,  1080,
    1229,   919,  1154,   850,    25,   930,  1194,  1195,  1194,    17,
      18,    24,    25,    45,    50,    57,    85,   178,   275,   280,
     308,   343,   355,   373,   378,   381,   392,   398,   408,   413,
     416,   419,   428,   429,   470,   474,   482,   493,   499,   524,
     568,   575,   577,   587,   588,   589,   596,   825,   832,   833,
     834,   835,   836,   837,   838,   839,   851,   856,   867,   868,
     869,   870,   924,   930,  1080,  1189,  1258,  1370,   925,  1420,
    1420,   811,  1154,   919,  1227,  1080,   921,   925,   832,  1420,
    1080,  1154,  1080,  1257,  1420,    24,   572,  1063,  1064,  1080,
     919,   919,  1063,   920,   925,   924,  1064,   919,  1420,   919,
     921,  1080,  1111,  1112,   917,   925,   921,   360,   548,   654,
     916,   924,   985,   924,   721,   922,   925,    24,  1289,  1452,
    1077,   850,   925,  1137,   881,   114,   123,   132,   137,   181,
     189,   245,   270,   277,   279,   289,   315,   323,   360,   386,
     424,   435,   535,   536,   537,   548,   652,   997,  1132,  1133,
    1080,   831,   832,  1146,   827,   850,   916,  1467,  1467,   918,
     925,   850,    24,  1080,  1135,  1208,  1080,  1185,    24,  1080,
    1414,   832,  1176,  1177,  1178,  1187,  1188,   832,  1462,    90,
     140,   178,   275,   351,   392,   460,   524,   677,   856,   924,
    1080,  1217,   700,   832,   917,  1459,  1050,   832,   917,   832,
    1080,  1007,   917,   832,  1431,   832,  1194,   924,   934,   935,
     921,   934,  1467,   921,   934,  1467,   940,   934,    24,    25,
     370,   473,   930,   988,  1080,  1099,  1101,    51,   260,   330,
     375,   555,   636,   637,   638,   647,   667,   942,   944,   946,
     948,   950,  1074,  1075,  1079,   321,   332,   384,   399,   489,
    1291,   627,   628,   888,   889,   890,   924,  1071,   634,  1070,
     377,   288,   377,   377,   377,   377,   611,     5,   377,   288,
     746,   766,   767,   377,   377,   611,   377,   924,  1212,  1100,
     377,  1202,    42,    43,    70,    71,    72,   440,   528,   571,
    1239,  1240,  1241,  1244,  1247,  1250,  1251,  1252,  1253,   416,
     607,  1454,  1090,   604,  1129,   607,     8,   525,   574,     5,
     377,   412,    24,   924,  1363,   465,  1155,  1099,    94,    95,
      96,   825,   825,   416,   512,  1206,   416,   416,   416,   416,
     416,   416,   416,   416,   416,   825,   352,   439,   456,   499,
     539,   568,   577,  1373,  1374,   416,   416,   416,   825,   825,
     416,   416,   737,   825,   416,   840,   416,   416,   416,   416,
     416,   416,   416,   825,   416,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    78,    79,    80,    81,    82,    83,    94,    95,    96,
     235,   238,   357,   372,   376,   414,   442,   461,   543,   610,
     736,   826,   841,   843,   844,   845,   846,   847,   848,   849,
      25,   930,   416,   507,   406,  1080,  1106,  1363,   666,   667,
     814,   252,    73,    74,   613,   445,     5,   606,   613,   605,
     605,  1114,   582,   406,     5,   543,   961,   445,   646,  1464,
     416,   444,   607,   646,   370,   723,  1080,   533,   605,  1119,
    1120,  1121,   312,  1287,   831,   830,   832,     8,   918,    25,
     487,   541,   911,  1080,   911,   911,   911,  1002,  1003,   911,
     911,   583,   998,   667,   998,   998,   912,   912,   998,   998,
     667,     5,   319,   371,     5,   666,   469,   828,   829,   832,
       5,    62,    68,   526,   614,   991,   649,  1465,   831,   600,
     601,   602,   603,  1184,  1186,   369,  1221,  1186,  1178,     5,
     605,  1179,   832,   416,   416,   416,   416,    24,   696,   924,
     416,  1414,   330,   416,   507,   576,   565,   701,   708,   699,
      24,  1065,  1080,  1172,     8,  1175,    13,   924,  1085,  1093,
    1094,  1096,  1104,  1105,  1148,   148,   330,   531,   564,    32,
     176,   540,  1432,  1433,  1434,  1435,   562,     5,   646,   646,
     830,  1099,  1106,   987,   406,     5,   136,   965,   416,  1080,
     830,   416,    25,    25,    51,  1078,    24,  1080,  1418,  1418,
     918,  1137,   918,   104,   207,   215,   221,   223,   234,   262,
     278,   283,   295,   302,   457,   464,   486,   491,  1260,  1261,
    1269,  1278,  1279,  1285,  1286,  1292,  1293,  1302,  1321,  1325,
    1390,  1391,  1421,  1422,  1425,  1426,  1436,   891,   892,    77,
     887,   898,   899,   890,  1072,  1477,  1030,   444,   794,   761,
     444,     5,   377,   768,   740,  1047,   740,   143,   282,   358,
     416,   478,  1308,  1320,   416,   924,  1255,    25,   231,   244,
     416,   462,   478,   924,  1236,  1249,  1306,  1307,  1312,  1314,
    1316,   416,   924,  1246,   416,  1236,  1242,     5,    24,   927,
    1083,  1454,  1452,   563,   604,  1130,    20,   924,  1110,  1455,
     924,  1473,  1234,   582,   607,   576,   416,   416,   814,   875,
     916,   825,   916,   916,   875,  1467,   457,  1394,   825,    24,
      25,    18,    23,    24,    25,   871,   872,   873,   874,   825,
     416,   613,   916,    20,   825,   377,  1394,   825,    20,  1189,
     859,   857,   863,   825,   861,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   416,   825,   825,   416,
     852,   924,  1080,   613,   416,  1452,    24,   929,  1153,  1153,
    1414,  1063,   832,   832,   832,   913,   914,   416,  1080,  1112,
     775,   962,   963,   613,  1414,  1467,  1465,   924,   663,    20,
     654,   924,   985,  1080,   722,   612,   832,   336,  1123,   543,
    1122,     5,    54,    56,    58,   605,   613,   806,  1099,   882,
      17,    18,    24,   290,   296,   297,   298,   316,   424,   427,
     451,   471,   506,   526,   527,   537,   542,   581,   614,  1004,
     999,  1133,   912,   832,   330,   582,     5,   916,    25,    25,
     666,   138,  1183,   204,  1188,  1194,  1463,   924,    24,   875,
    1467,   576,   916,   610,  1080,   681,   924,   924,   832,   325,
     704,   708,   565,   702,   710,    22,   220,  1052,  1056,   468,
     850,   468,  1173,   832,   443,  1090,   607,     5,  1008,   533,
    1149,  1080,  1453,  1456,  1080,  1102,  1103,   175,  1433,   953,
     935,  1467,  1467,   945,   946,   965,   965,   256,   259,   261,
     281,   291,   333,   337,   415,   467,   651,   964,   966,   967,
     993,  1080,  1101,   533,   668,    25,   385,   951,   307,  1413,
    1413,   121,   122,   422,   533,   924,  1322,  1323,  1364,   775,
    1363,  1363,  1262,   775,   924,  1423,  1423,   345,   462,   572,
    1402,  1363,  1270,   154,   424,   435,   457,   464,  1295,  1296,
    1297,   273,   274,  1385,  1477,  1477,   370,   900,  1080,   629,
     630,   893,   894,   895,   467,   612,   631,   632,   651,   903,
     904,  1477,   740,    25,   759,   759,   767,  1213,   740,  1203,
    1310,  1363,  1254,  1320,   416,  1254,   416,   416,  1248,  1249,
     416,   416,    49,   285,   343,   355,   365,   383,   393,   396,
     409,   458,   488,   498,   519,   522,   524,   552,   561,  1355,
    1356,  1357,  1359,  1245,  1246,  1242,  1243,   651,  1240,   377,
     607,  1414,   563,   444,   533,  1471,   661,   662,   924,   924,
     924,  1230,   850,     5,   377,   377,   377,   377,   377,  1402,
     377,   377,   377,   377,   576,   872,    18,    25,   576,   377,
     377,    25,  1374,   377,   377,   377,   377,     5,   738,   377,
     825,   825,   825,   377,   825,   377,   377,   377,   427,   427,
     427,   850,  1394,   427,   850,  1394,   693,   694,   695,   825,
     416,   924,  1228,   604,  1126,   613,     5,     5,     5,   566,
     832,   607,     5,   469,   613,   377,   412,   416,   612,   149,
     153,   256,   259,   724,   727,   728,   993,   725,   726,   924,
     416,   925,   636,   637,  1127,   832,   924,   924,   914,   915,
     495,  1467,   814,   540,  1275,    25,    25,   416,  1000,  1002,
    1080,   522,  1141,   828,    51,   825,  1186,    25,  1080,  1477,
       5,     5,   377,   377,   697,   924,   377,  1414,   693,   416,
     416,   709,   705,   346,   703,   832,   325,   706,   710,   583,
     995,  1057,  1053,   348,  1051,  1052,   830,   613,  1086,    20,
     924,  1095,  1105,    13,    17,    18,    20,    24,    25,    50,
     381,   396,   413,   416,   429,   469,   470,   482,   524,   563,
     575,   587,   588,   596,   599,   924,   930,  1150,  1151,  1369,
    1371,  1401,  1406,  1407,  1408,  1456,   406,   406,     5,  1477,
     947,   948,   537,   923,   533,   916,   981,   916,   982,   974,
     973,   971,   970,   994,   424,   435,   977,   978,   424,   435,
     979,   980,   310,   967,   972,  1467,    84,   318,   331,   395,
     402,   441,   466,   476,   477,   492,   514,   517,   518,   523,
     580,   592,   669,   670,     5,    25,  1414,   234,  1080,   457,
    1395,  1396,  1414,  1137,  1389,  1391,    86,    86,   582,  1135,
    1324,  1325,   416,  1303,   135,   512,  1329,  1336,  1363,   161,
     257,  1427,   607,   613,  1392,  1437,   327,   336,   360,   363,
     381,   487,   541,   548,   918,  1272,  1277,   416,  1298,   612,
       5,    24,   924,  1386,  1387,   902,  1080,     5,   533,   896,
     897,   626,   895,   901,   924,   901,   905,   906,   901,   310,
     904,  1031,   412,   412,   446,  1196,  1216,  1048,   446,  1159,
    1190,   416,     5,   377,   280,   416,   428,   589,  1339,  1340,
    1341,  1342,  1343,  1347,  1351,  1353,  1406,   377,   599,   924,
    1309,  1311,  1363,  1366,  1367,  1313,  1366,     5,   377,  1313,
    1339,   352,   439,   456,   499,   539,   568,   577,  1376,  1376,
     416,   416,   416,   416,   416,   416,   193,   385,  1315,  1317,
       5,   377,     5,   377,   924,  1455,     8,  1414,  1091,   832,
       5,  1235,  1236,   850,  1037,   916,  1403,  1404,  1406,   865,
    1374,   865,    25,    25,   576,    23,    25,   778,   866,  1206,
     377,  1206,   779,   377,  1206,   860,   858,   864,  1206,   862,
    1206,  1206,  1206,    24,    24,    24,   825,   842,   377,    24,
     842,   377,   853,     5,   854,   607,  1235,   563,  1414,  1414,
     832,   832,   913,   495,   832,  1469,     5,    20,  1366,   963,
    1414,   607,   924,   725,   733,   732,   734,   924,   928,   735,
     928,   177,   728,   731,     5,   965,   607,   832,     8,   924,
    1276,   883,  1001,  1002,  1080,     5,   311,    24,  1218,   330,
     330,   444,   607,   330,   416,   682,   686,   679,  1477,  1477,
     711,   707,   703,   996,    24,   923,  1058,  1080,  1477,   832,
     411,   444,   850,  1407,  1407,  1372,  1376,   457,  1406,   416,
     416,   416,   416,   416,   416,   416,   924,   416,     5,    17,
      18,    19,    20,    78,    79,    80,    81,    82,    83,  1428,
    1453,  1080,  1103,    48,   529,   954,   949,   950,    25,   666,
     924,     5,   968,     5,   969,  1477,  1477,  1477,  1477,  1000,
       5,   976,     5,   975,  1477,   923,     5,   377,    25,  1363,
    1402,  1383,   582,   582,  1261,  1388,  1389,  1325,  1304,  1366,
     604,   918,  1339,   416,  1265,   924,  1424,  1423,  1403,    34,
      35,    36,    37,    38,   570,  1440,   832,   832,  1271,   918,
    1299,  1366,  1363,  1297,   607,   607,     5,     5,  1080,   901,
    1477,  1477,     5,   908,   909,  1477,  1477,   907,  1024,   798,
     756,    59,    60,    63,    64,    65,   163,   170,   204,   213,
     242,   243,   287,   329,   385,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,  1193,  1197,   120,   500,  1198,
    1214,  1024,   145,   162,   163,   170,   204,   213,   242,   287,
     329,  1191,  1192,  1204,  1198,  1311,  1320,   416,  1401,  1339,
    1406,  1401,  1342,     6,   377,     7,     9,    11,    12,    13,
      14,    15,    16,   238,   357,   414,   543,   589,   610,  1350,
    1352,  1367,   444,  1365,   377,     5,   607,     5,   377,  1249,
     377,   377,   613,   416,   613,    25,  1361,  1361,    25,  1361,
    1361,    25,  1360,    24,  1369,  1318,  1319,  1320,  1246,  1242,
    1414,     8,   412,   662,     5,   377,   830,   377,     5,   533,
    1330,  1335,   266,   306,   307,   308,   331,   339,   344,   359,
     364,   366,   373,   376,   379,   382,   385,   390,   408,   424,
     427,   428,   434,   445,   461,   468,   475,   478,   479,   480,
     482,   483,   499,   523,   524,   525,   526,   528,   545,   546,
     568,   577,   578,   580,   642,   931,  1476,   613,   377,    25,
     576,   613,   377,   377,   377,   377,     5,   377,   377,   377,
     695,   693,    20,   377,  1414,     5,   832,   553,   260,   671,
     672,   832,    20,   924,   377,   965,  1477,  1477,     5,   729,
     444,   607,     5,   730,  1477,   726,   533,    20,   924,     5,
     924,  1117,   375,   646,  1102,  1477,     5,   377,   923,   825,
       5,   693,  1080,   678,   660,   924,  1080,   684,   377,   693,
     693,  1477,  1477,  1000,  1055,    24,  1059,  1080,   558,   879,
    1091,   469,   831,  1009,   613,  1402,   377,   381,  1366,  1429,
     345,   462,   572,  1354,  1406,  1409,  1354,  1354,  1354,  1354,
     607,  1409,  1151,  1406,  1406,  1406,  1406,   956,   955,   426,
     941,   942,   607,   916,  1477,   916,  1477,   978,  1477,   980,
    1477,   666,   670,   377,   416,  1415,  1403,  1385,  1389,  1389,
    1381,     5,   377,   457,  1400,  1266,  1366,   465,  1263,  1400,
     613,  1393,    17,    18,    50,   413,   416,   429,   469,   470,
     482,   524,   563,   575,   587,   588,   596,   599,   924,  1369,
    1401,  1445,  1446,  1447,  1448,  1449,  1450,  1456,  1445,  1445,
    1445,  1366,  1442,  1444,  1441,  1442,  1443,  1438,   540,  1273,
       5,   377,   613,   924,   924,  1387,  1080,   924,  1477,  1477,
    1477,  1477,   611,   611,  1194,  1194,  1194,    24,  1194,  1194,
    1194,  1194,  1194,  1194,    24,    24,  1194,  1197,  1080,  1107,
    1108,   606,   432,  1160,  1477,    24,    24,    25,    25,    25,
      25,    25,    24,  1080,  1192,  1160,   377,   377,  1340,  1341,
     924,  1345,  1369,  1410,   416,  1401,  1345,   416,  1401,     9,
     235,   372,   374,  1406,    25,  1308,  1366,    20,   924,  1366,
     352,   439,   456,   499,   539,   568,   577,  1377,    25,  1377,
       5,  1358,  1358,     5,   377,   377,  1358,   377,  1320,  1414,
    1236,   254,  1232,  1404,   501,  1331,  1332,  1333,  1363,  1336,
     317,   500,   511,  1280,  1397,   352,   439,   456,   499,   539,
     568,   577,  1375,   865,   576,    23,    25,   782,   825,   855,
     454,   813,     5,   359,  1414,     5,   416,   377,   537,   992,
     928,  1477,   663,    20,   924,   928,  1477,  1467,   832,  1467,
     226,  1002,   666,    24,  1219,  1099,   412,   693,   683,   687,
     377,  1477,   923,   832,   877,   412,  1377,  1403,     5,  1376,
       5,   377,  1406,     5,   377,  1406,  1406,  1406,  1406,   924,
     377,   832,  1477,   943,   944,    20,   924,  1416,  1417,   540,
    1399,  1384,  1382,  1385,  1366,  1402,   125,  1305,     5,   377,
    1264,  1424,  1399,  1448,  1448,  1447,   416,   416,   416,   416,
     416,   416,   416,   924,   416,     5,   377,    17,    18,    19,
      20,  1428,   377,     5,   377,     5,    13,   135,   512,  1439,
    1274,  1366,   448,  1300,  1301,  1364,   607,   196,  1032,   794,
     768,   525,   574,  1109,     5,  1107,    47,   119,   185,   187,
     202,   210,   214,   239,  1161,  1162,  1215,  1032,  1205,   427,
    1344,  1348,  1349,  1369,  1456,  1344,  1348,  1345,  1406,     5,
     412,  1365,   377,    25,  1362,   377,   377,    25,   377,   416,
    1333,     5,   924,  1368,   354,  1327,  1337,   924,  1398,   606,
    1354,   317,   416,    23,    25,   377,   916,   666,   359,  1414,
     832,   673,   555,  1115,    25,   666,   412,   992,   377,  1139,
     377,   377,   416,   685,   330,   691,   377,   680,  1054,  1477,
    1335,  1376,   613,  1376,   377,  1406,   377,   377,   377,   377,
     562,   923,     5,   377,  1102,  1335,  1385,  1385,  1403,  1366,
     416,  1335,   377,  1429,  1354,  1447,  1451,  1354,  1354,  1354,
    1354,   607,  1451,  1446,  1447,  1447,  1447,  1447,  1442,    13,
    1443,  1446,   918,  1339,  1102,     5,   126,  1294,   924,  1108,
    1163,  1164,  1080,  1166,  1080,  1165,  1167,  1162,   225,   225,
    1346,  1410,     5,   377,   377,  1344,     7,    25,   613,   377,
    1332,  1334,  1332,  1328,  1405,  1406,   433,  1326,  1338,  1232,
      25,  1281,  1282,  1283,  1366,  1395,  1398,    25,   812,  1414,
     378,   189,   245,   270,   279,   315,   323,   417,   590,   670,
     674,   675,   416,   607,   666,   993,  1142,  1143,  1144,  1220,
     688,   377,  1099,   691,   691,  1477,   878,   377,   613,  1377,
     613,   957,   989,  1417,  1397,  1335,   469,  1267,  1268,  1406,
    1397,   377,  1447,     5,   377,  1447,  1447,  1447,  1447,   924,
     377,   416,  1301,  1477,  1477,  1168,  1477,  1169,  1477,  1477,
    1349,  1406,   412,  1377,     5,   377,     5,  1339,     5,   525,
     574,  1284,  1232,   377,   333,   337,   815,   816,   817,   993,
     911,   911,   911,   911,   911,   911,    24,     5,   377,   832,
      20,   924,  1145,   268,  1144,   691,   693,   691,   227,  1377,
    1377,  1477,   666,     5,   377,   377,  1447,   377,   377,   377,
     377,  1445,  1477,  1477,  1332,  1405,  1282,   819,   818,   224,
     817,   820,   675,     5,  1477,   689,   954,  1268,   377,  1477,
    1477,  1477,   832,   377,   377,   690,   148,   330,   692,  1099
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
#line 906 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 909 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 913 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 919 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 924 "fgl.yacc"
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
#line 936 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 941 "fgl.yacc"
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
#line 964 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 965 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 966 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 967 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 968 "fgl.yacc"
    {
  int a;
  a=scan_variable(yyvsp[0].str)&15;
  if (a!=1&&a!=2) {
    
    a4gl_yyerror("Only INTEGER/SMALLINT variables may be used as subscripts");
    YYERROR;
    /* error processing */;
  }
  sprintf(yyval.str,"%s",yyvsp[0].str);
}
    break;

  case 16:
#line 982 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 983 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 984 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 985 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 986 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 991 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 992 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 1003 "fgl.yacc"
    {
	 A4GL_debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 1006 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 1009 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 1009 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
A4GL_debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 1016 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 1017 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 1023 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 1024 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1025 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1026 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1027 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1028 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1029 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1030 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1031 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1032 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1033 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1034 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1035 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1036 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1037 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1038 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1045 "fgl.yacc"
    {
A4GL_debug("win_attributes_def");
start_state("attribute",1);
A4GL_debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1049 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1053 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1054 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1058 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1064 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1066 "fgl.yacc"
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

  case 55:
#line 1077 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1079 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1081 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1083 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
A4GL_debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1087 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1089 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1150 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1154 "fgl.yacc"
    { A4GL_debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1158 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1161 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1169 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 66:
#line 1174 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1178 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1181 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1187 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
 A4GL_debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 71:
#line 1196 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1200 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1205 "fgl.yacc"
    {
 A4GL_debug("Got args");
   }
    break;

  case 74:
#line 1209 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1217 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1221 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1225 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1227 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1233 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1238 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1241 "fgl.yacc"
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

  case 82:
#line 1257 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1264 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1268 "fgl.yacc"
    {
	 A4GL_debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1272 "fgl.yacc"
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

  case 86:
#line 1294 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1294 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1298 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1299 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1300 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1305 "fgl.yacc"
    {
			yyval.ptr=A4GL_new_expr("");
		}
    break;

  case 92:
#line 1308 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1314 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1317 "fgl.yacc"
    {
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1329 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1335 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1338 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1353 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
A4GL_incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1363 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1369 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
A4GL_incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1378 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1391 "fgl.yacc"
    {setinc(-1);A4GL_incprint();}
    break;

  case 110:
#line 1394 "fgl.yacc"
    {
A4GL_incprint();
}
    break;

  case 111:
#line 1396 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1402 "fgl.yacc"
    {A4GL_incprint();}
    break;

  case 114:
#line 1404 "fgl.yacc"
    {A4GL_incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1409 "fgl.yacc"
    {
print_when(0);

A4GL_incprint();
}
    break;

  case 116:
#line 1414 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1420 "fgl.yacc"
    {
A4GL_incprint();
print_when(1);
}
    break;

  case 118:
#line 1424 "fgl.yacc"
    {A4GL_incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1439 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1442 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1445 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1448 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1451 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1454 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1476 "fgl.yacc"
    {
			A4GL_lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1485 "fgl.yacc"
    {
			A4GL_lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1495 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	A4GL_lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1509 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1513 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1516 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1524 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1530 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"A4GL_form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1545 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1549 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1554 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1564 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1567 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1571 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1573 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1576 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1578 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1581 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1583 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1586 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1589 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1599 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1600 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1608 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1609 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1626 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1629 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1632 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1635 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1638 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1641 "fgl.yacc"
    {
        	yyval.ptr=A4GL_new_expr("A4GL_pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1650 "fgl.yacc"
    {
			yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1658 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(19*16)+10); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 171:
#line 1663 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"A4GL_push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=A4GL_new_expr(buff);
}
    break;

  case 172:
#line 1676 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1680 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1695 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1696 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1704 "fgl.yacc"
    {dtypelist[0]=0;A4GL_lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1704 "fgl.yacc"
    {A4GL_lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1714 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1714 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (A4GL_bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1723 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1724 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1725 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1728 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1733 "fgl.yacc"
    { }
    break;

  case 193:
#line 1733 "fgl.yacc"
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

  case 197:
#line 1750 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1754 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1768 "fgl.yacc"
    {
 A4GL_debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1777 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1781 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1797 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); A4GL_debug("Triplet");}
    break;

  case 213:
#line 1799 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); A4GL_debug("double");}
    break;

  case 214:
#line 1800 "fgl.yacc"
    {A4GL_debug("Single");}
    break;

  case 216:
#line 1807 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1807 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1808 "fgl.yacc"
    {in_record++;push_record();A4GL_debug("Like\n");}
    break;

  case 219:
#line 1809 "fgl.yacc"
    {A4GL_debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1812 "fgl.yacc"
    {
		push_record();A4GL_debug("Like\n");}
    break;

  case 221:
#line 1814 "fgl.yacc"
    {
		  A4GL_debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          A4GL_debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1824 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1839 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1839 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1845 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1846 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1853 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1854 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1855 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1856 "fgl.yacc"
    {
A4GL_debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1859 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1860 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1861 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1862 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1866 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1871 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1876 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1880 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1883 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1887 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1888 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1889 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1890 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1891 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1892 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1893 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1894 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1897 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1898 "fgl.yacc"
    {push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1899 "fgl.yacc"
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

  case 259:
#line 1931 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1935 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1937 "fgl.yacc"
    {A4GL_debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1939 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1941 "fgl.yacc"
    {
A4GL_debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1946 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 265:
#line 1950 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1950 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1954 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1955 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1956 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1957 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1958 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1959 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1961 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1966 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1966 "fgl.yacc"
    { A4GL_debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1969 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1971 "fgl.yacc"
    {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1977 "fgl.yacc"
    {
A4GL_debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1979 "fgl.yacc"
    {
A4GL_debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1985 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1993 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1993 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1996 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1997 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1998 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1999 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 2000 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 2001 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 2003 "fgl.yacc"
    {
A4GL_debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 2024 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 2033 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2035 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2037 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2039 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2040 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2041 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2042 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2043 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2048 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2055 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2060 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2062 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2064 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2065 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2066 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2067 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2068 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2069 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2070 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2073 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2075 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);A4GL_lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2081 "fgl.yacc"
    {
A4GL_lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; A4GL_lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2089 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2097 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2101 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2109 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2110 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2111 "fgl.yacc"
    {dim_push_record();A4GL_debug("Like\n");}
    break;

  case 326:
#line 2112 "fgl.yacc"
    {A4GL_debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2131 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2143 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,A4GL_get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2147 "fgl.yacc"
    {
		strcpy(yyval.str,A4GL_get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2150 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2153 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(4,0,0)); }
    break;

  case 337:
#line 2154 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2155 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2156 "fgl.yacc"
    { strcpy(yyval.str, A4GL_get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2157 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2163 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2170 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2175 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2180 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2184 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2187 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2195 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2197 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2202 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2214 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2217 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2220 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2223 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2226 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2229 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2242 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2245 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2260 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 363:
#line 2262 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 364:
#line 2264 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 365:
#line 2266 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 366:
#line 2268 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 367:
#line 2270 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 368:
#line 2271 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* A4GL_lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 369:
#line 2278 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 370:
#line 2280 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 371:
#line 2284 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 372:
#line 2286 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 373:
#line 2288 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 374:
#line 2290 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 375:
#line 2292 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 376:
#line 2294 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 377:
#line 2296 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 378:
#line 2302 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 379:
#line 2316 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2319 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2336 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=A4GL_append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2342 "fgl.yacc"
    {
	A4GL_debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2346 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
	yyval.ptr=A4GL_append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 390:
#line 2351 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2361 "fgl.yacc"
    { yyval.ptr=A4GL_new_expr("A4GL_add_spaces();"); }
    break;

  case 401:
#line 2372 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2372 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2377 "fgl.yacc"
    {yyval.ptr=A4GL_new_expr("A4GL_push_null()");}
    break;

  case 405:
#line 2381 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2387 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2395 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2401 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	A4GL_lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2410 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2412 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2419 "fgl.yacc"
    {
	A4GL_debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2427 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2431 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2440 "fgl.yacc"
    {
	
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT);");
}
    break;

  case 415:
#line 2445 "fgl.yacc"
    {
	yyval.ptr=A4GL_new_expr("A4GL_push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2450 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=A4GL_new_expr("A4GL_push_int(0);");
}
    break;

  case 417:
#line 2454 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2456 "fgl.yacc"
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

  case 419:
#line 2466 "fgl.yacc"
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

  case 420:
#line 2480 "fgl.yacc"
    {
	A4GL_debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2488 "fgl.yacc"
    {
	A4GL_debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyval.str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2500 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('S',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2506 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('D',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2512 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",A4GL_get_push_literal('L',yyvsp[0].str));
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2522 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2528 "fgl.yacc"
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

  case 429:
#line 2600 "fgl.yacc"
    {
	sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2606 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_%sset_column(&rep);",ispdf());
yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2610 "fgl.yacc"
    {
   if (!in_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=A4GL_new_expr(yyvsp[0].str);
}
    break;

  case 432:
#line 2618 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2618 "fgl.yacc"
    {
	char buff[256];
      if (!in_command("REPORT")) {
        a4gl_yyerror("This can only be done in a report!");YYERROR;
      } insql=0; 
	A4GL_lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        strcpy(buff,yyvsp[0].str);
	A4GL_debug("report aggregate :  %s",buff);
	yyval.ptr=A4GL_new_expr(buff);
      }
    break;

  case 434:
#line 2634 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_AND);");
}
    break;

  case 435:
#line 2638 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_OR);");
}
    break;

  case 436:
#line 2644 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 437:
#line 2647 "fgl.yacc"
    {
		A4GL_debug("Adding to list...");
		yyval.ptr=A4GL_append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 438:
#line 2655 "fgl.yacc"
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

  case 439:
#line 2666 "fgl.yacc"
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

  case 440:
#line 2676 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_IN);");
}
    break;

  case 441:
#line 2682 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"A4GL_push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,buff);
	A4GL_append_expr(yyval.ptr,"A4GL_pushop(OP_NOTIN);");
}
    break;

  case 442:
#line 2692 "fgl.yacc"
    { 
	strcpy(yyval.str,"A4GL_pushop(OP_ISNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 443:
#line 2697 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_ISNOTNULL);");
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 444:
#line 2704 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);");
 }
    break;

  case 445:
#line 2707 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);");
}
    break;

  case 446:
#line 2710 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 447:
#line 2715 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_MATCHES);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 448:
#line 2722 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 449:
#line 2727 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(\"\\\\\");A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);");
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 450:
#line 2732 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 451:
#line 2737 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"A4GL_push_char(%s);A4GL_pushop(OP_LIKE);A4GL_pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 452:
#line 2748 "fgl.yacc"
    {
	strcpy(yyval.str,"A4GL_pushop(OP_CLIP);");
	yyval.ptr=A4GL_new_expr(yyval.str);
	inc_counter();
}
    break;

  case 453:
#line 2756 "fgl.yacc"
    {
	sprintf(yyval.str,"%s A4GL_pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_USING);");
}
    break;

  case 454:
#line 2764 "fgl.yacc"
    {
	A4GL_debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_ADD);");
}
    break;

  case 455:
#line 2769 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_SUB);");
}
    break;

  case 456:
#line 2773 "fgl.yacc"
    {
      sprintf(yyval.str,"%s A4GL_A4GL_pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MULT);");
}
    break;

  case 457:
#line 2778 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_DIV);");
}
    break;

  case 458:
#line 2782 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_MOD);");
}
    break;

  case 459:
#line 2786 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_POWER);");
}
    break;

  case 460:
#line 2792 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 461:
#line 2795 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_EQUAL);");
}
    break;

  case 462:
#line 2799 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN);");
}
    break;

  case 463:
#line 2803 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN);");
}
    break;

  case 464:
#line 2807 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_NOT_EQUAL);");
}
    break;

  case 465:
#line 2811 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 466:
#line 2815 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 467:
#line 2822 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 468:
#line 2832 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 469:
#line 2837 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		A4GL_lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 470:
#line 2843 "fgl.yacc"
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

  case 471:
#line 2853 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GL_debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 472:
#line 2858 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 473:
#line 2861 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");A4GL_pop_args(_retvars);A4GL_push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 474:
#line 2875 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 475:
#line 2875 "fgl.yacc"
    {chk4var=0;}
    break;

  case 476:
#line 2875 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 477:
#line 2878 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 478:
#line 2878 "fgl.yacc"
    {chk4var=0;}
    break;

  case 479:
#line 2878 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 480:
#line 2881 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 481:
#line 2881 "fgl.yacc"
    {chk4var=0;}
    break;

  case 482:
#line 2881 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 483:
#line 2884 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 484:
#line 2884 "fgl.yacc"
    {chk4var=0;}
    break;

  case 485:
#line 2884 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 486:
#line 2887 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 487:
#line 2893 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 488:
#line 2899 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2905 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=A4GL_new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2915 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 491:
#line 2916 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)*16+atoi(yyvsp[0].str));}
    break;

  case 494:
#line 2924 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=A4GL_fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);A4GL_chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=A4GL_new_expr(yyval.str);

}
    break;

  case 495:
#line 2930 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); }
    break;

  case 496:
#line 2931 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=A4GL_new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 497:
#line 2936 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 498:
#line 2940 "fgl.yacc"
    { sprintf(yyval.str,"A4GL_push_int(A4GL_fgl_fieldtouched(%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 499:
#line 2944 "fgl.yacc"
    { sprintf(yyval.str,"A4GL_push_int(!A4GL_fgl_fieldtouched(%s,0,0));",yyvsp[-1].str); 
	yyval.ptr=A4GL_new_expr(yyval.str);
}
    break;

  case 502:
#line 2951 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"A4GL_push_current(%s);",yyvsp[0].str);
		yyval.ptr=A4GL_new_expr(yyval.str);
          	}
    break;

  case 503:
#line 2956 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"A4GL_push_today();");
		yyval.ptr=A4GL_new_expr(yyval.str);
		}
    break;

  case 504:
#line 2963 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_upshift_stk();");
}
    break;

  case 505:
#line 2967 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_downshift_stk();");
}
    break;

  case 506:
#line 2970 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"A4GL_push_ascii();");
}
    break;

  case 507:
#line 2973 "fgl.yacc"
    { 
	yyval.ptr=A4GL_append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 508:
#line 2979 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-1);A4GL_pushop(OP_MULT);");
}
    break;

  case 509:
#line 2982 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-28.3465);A4GL_pushop(OP_MULT);");
}
    break;

  case 510:
#line 2985 "fgl.yacc"
    {
	yyval.ptr=A4GL_append_expr(yyvsp[-1].ptr,"A4GL_push_double(-72.0);A4GL_pushop(OP_MULT);");
}
    break;

  case 511:
#line 3000 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 512:
#line 3003 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 513:
#line 3009 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 514:
#line 3010 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 515:
#line 3011 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 3016 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 518:
#line 3017 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 519:
#line 3018 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 3019 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 3021 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 3022 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 3023 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3025 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3026 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 527:
#line 3032 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 529:
#line 3037 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 530:
#line 3049 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 531:
#line 3053 "fgl.yacc"
    {A4GL_debug("For_cmds\n");}
    break;

  case 532:
#line 3054 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
A4GL_lex_printcomment(" /*END FOR*/\n");}
    break;

  case 533:
#line 3061 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 535:
#line 3078 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 536:
#line 3082 "fgl.yacc"
    {
print_foreach_start();
A4GL_lex_printcomment(" /* foreach */\n");
}
    break;

  case 537:
#line 3087 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 538:
#line 3091 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 539:
#line 3107 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 540:
#line 3113 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 541:
#line 3121 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 548:
#line 3138 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 549:
#line 3140 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 550:
#line 3143 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 551:
#line 3145 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 556:
#line 3159 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 557:
#line 3161 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 558:
#line 3164 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 559:
#line 3166 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 572:
#line 3197 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 573:
#line 3199 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 574:
#line 3202 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 575:
#line 3204 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3207 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 577:
#line 3209 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3212 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 579:
#line 3214 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3217 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 581:
#line 3219 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 582:
#line 3234 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		A4GL_lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 583:
#line 3250 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 584:
#line 3251 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 585:
#line 3252 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 586:
#line 3253 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 587:
#line 3254 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 588:
#line 3255 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 592:
#line 3263 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 594:
#line 3269 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 595:
#line 3271 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 596:
#line 3272 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 597:
#line 3274 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 598:
#line 3276 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 599:
#line 3278 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 600:
#line 3280 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 601:
#line 3282 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 602:
#line 3285 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 603:
#line 3292 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 604:
#line 3294 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 605:
#line 3300 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 606:
#line 3305 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 607:
#line 3310 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 608:
#line 3315 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 609:
#line 3315 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 610:
#line 3318 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 611:
#line 3324 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[0].str) ;
			}
    break;

  case 612:
#line 3329 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 613:
#line 3333 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 616:
#line 3341 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 617:
#line 3343 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 618:
#line 3345 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 619:
#line 3347 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 620:
#line 3349 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 621:
#line 3351 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 622:
#line 3354 "fgl.yacc"
    {
A4GL_debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 624:
#line 3363 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 668:
#line 3424 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 669:
#line 3438 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 671:
#line 3445 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 672:
#line 3448 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 673:
#line 3454 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 674:
#line 3460 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 675:
#line 3464 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 676:
#line 3468 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 677:
#line 3474 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 678:
#line 3478 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 679:
#line 3482 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 680:
#line 3487 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 681:
#line 3492 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 700:
#line 3533 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 701:
#line 3538 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 703:
#line 3543 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 705:
#line 3546 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 706:
#line 3548 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 707:
#line 3551 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 708:
#line 3555 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 709:
#line 3558 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 710:
#line 3564 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 711:
#line 3575 "fgl.yacc"
    {A4GL_debug("init to\n");}
    break;

  case 712:
#line 3576 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 713:
#line 3579 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 715:
#line 3585 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 716:
#line 3589 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 717:
#line 3590 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 720:
#line 3604 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 721:
#line 3606 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 724:
#line 3615 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 725:
#line 3617 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 726:
#line 3621 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 727:
#line 3623 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 728:
#line 3626 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 729:
#line 3628 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 730:
#line 3631 "fgl.yacc"
    {
		A4GL_lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 731:
#line 3634 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 732:
#line 3637 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 733:
#line 3639 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 734:
#line 3642 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 735:
#line 3644 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 3647 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 737:
#line 3649 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 738:
#line 3652 "fgl.yacc"
    {A4GL_lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 739:
#line 3654 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 740:
#line 3657 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 741:
#line 3659 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 742:
#line 3665 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 743:
#line 3666 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 744:
#line 3674 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 745:
#line 3675 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 746:
#line 3680 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 747:
#line 3681 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		A4GL_generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 748:
#line 3690 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 749:
#line 3691 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 750:
#line 3698 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 751:
#line 3699 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 752:
#line 3707 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 753:
#line 3708 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	A4GL_generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 754:
#line 3717 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 755:
#line 3722 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 756:
#line 3727 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 757:
#line 3728 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 759:
#line 3733 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 760:
#line 3736 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 761:
#line 3744 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 762:
#line 3749 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,A4GL_get_formloop_str(0));
}
    break;

  case 763:
#line 3753 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 764:
#line 3755 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 765:
#line 3764 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 766:
#line 3769 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 767:
#line 3770 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 768:
#line 3771 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 769:
#line 3772 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 770:
#line 3775 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 772:
#line 3781 "fgl.yacc"
    {iskey=1;}
    break;

  case 773:
#line 3781 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 774:
#line 3783 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 775:
#line 3786 "fgl.yacc"
    {iskey=1;}
    break;

  case 776:
#line 3786 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 3788 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 778:
#line 3792 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 779:
#line 3792 "fgl.yacc"
    {sprintf(yyval.str,"A4GL_key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 780:
#line 3795 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 781:
#line 3796 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 783:
#line 3799 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 784:
#line 3804 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 785:
#line 3804 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 790:
#line 3811 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 791:
#line 3812 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 792:
#line 3813 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 793:
#line 3814 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 794:
#line 3815 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 795:
#line 3816 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 796:
#line 3817 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 797:
#line 3818 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 798:
#line 3819 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 799:
#line 3820 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 800:
#line 3821 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 801:
#line 3822 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 802:
#line 3823 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 803:
#line 3827 "fgl.yacc"
    {
char buff[256];
A4GL_debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
A4GL_convlower(buff);
print_label(buff);
}
    break;

  case 804:
#line 3845 "fgl.yacc"
    {chk4var=1;}
    break;

  case 805:
#line 3845 "fgl.yacc"
    {chk4var=0;
expand_obind();
A4GL_lex_printcomment("/*let3*/\n");}
    break;

  case 806:
#line 3848 "fgl.yacc"
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
	}

}
    break;

  case 807:
#line 3871 "fgl.yacc"
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

  case 809:
#line 3889 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 810:
#line 3895 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 811:
#line 3901 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 812:
#line 3907 "fgl.yacc"
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

  case 813:
#line 3918 "fgl.yacc"
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

  case 814:
#line 3941 "fgl.yacc"
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

  case 817:
#line 3957 "fgl.yacc"
    {
	}
    break;

  case 824:
#line 3980 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 828:
#line 3988 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 846:
#line 4014 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 847:
#line 4015 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 848:
#line 4023 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 849:
#line 4028 "fgl.yacc"
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

  case 850:
#line 4044 "fgl.yacc"
    {
  A4GL_lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  A4GL_lex_printcomment("/* define section */\n");
}
    break;

  case 851:
#line 4050 "fgl.yacc"
    {
  int c;
  A4GL_lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 853:
#line 4065 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    A4GL_lex_printcomment("/*end function*/\n");
  }
    break;

  case 854:
#line 4078 "fgl.yacc"
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

  case 855:
#line 4088 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 856:
#line 4095 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
A4GL_lex_printcomment("/*end main */\n");}
    break;

  case 857:
#line 4102 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 858:
#line 4108 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 859:
#line 4108 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 860:
#line 4113 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 861:
#line 4118 "fgl.yacc"
    {
}
    break;

  case 867:
#line 4130 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
A4GL_lex_printcomment("/* start of globals */\n");
}
    break;

  case 869:
#line 4138 "fgl.yacc"
    {
 A4GL_lex_printcomment("/* end of globals */");
	A4GL_debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 870:
#line 4144 "fgl.yacc"
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

  case 871:
#line 4158 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 872:
#line 4162 "fgl.yacc"
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

  case 873:
#line 4175 "fgl.yacc"
    {
	print_variables();
  A4GL_lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 875:
#line 4193 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 876:
#line 4200 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 877:
#line 4206 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 878:
#line 4217 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 879:
#line 4221 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 880:
#line 4228 "fgl.yacc"
    {
A4GL_debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	 A4GL_lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 881:
#line 4235 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 882:
#line 4241 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 883:
#line 4246 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 886:
#line 4253 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 887:
#line 4254 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 888:
#line 4256 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 889:
#line 4257 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 890:
#line 4260 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 891:
#line 4261 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 892:
#line 4262 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 893:
#line 4264 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 894:
#line 4269 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 895:
#line 4274 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 896:
#line 4281 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 900:
#line 4288 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 901:
#line 4290 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 902:
#line 4292 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 903:
#line 4301 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 904:
#line 4307 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 905:
#line 4311 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 908:
#line 4323 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 909:
#line 4328 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 910:
#line 4333 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 911:
#line 4336 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 912:
#line 4345 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 913:
#line 4348 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 914:
#line 4352 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 915:
#line 4356 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 922:
#line 4373 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 924:
#line 4375 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 925:
#line 4375 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 926:
#line 4378 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 927:
#line 4388 "fgl.yacc"
    {
char buff[256];
char buff2[256];
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
n=scan_variable(buff);

  A4GL_debug("scan variable returns -> %d\n",n);

  if (n == -1&&buff[0]!=' ') {
           sprintf(buff2,"'%s' does not represent a defined variable (1)",buff);
           a4gl_yyerror(buff2);
           exit (0);
  }
  if (strstr(buff,".*") && n!=-2) {
		char *ptr;
		printf("WARNING : Using a .* on a non-record - %s\n",yyvsp[0].str);
		ptr=strstr(buff,".*");
		*ptr=0;
		strcpy(yyval.str,buff);
  }
 
  mcnt = 0;
}
    break;

  case 929:
#line 4435 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 931:
#line 4442 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         A4GL_lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 932:
#line 4447 "fgl.yacc"
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
             sprintf (yyval.str, " a4gl_substr(%s , %d , %s , 0 ) /*1*/", buff,
                      (int)scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 936:
#line 4494 "fgl.yacc"
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

  case 937:
#line 4508 "fgl.yacc"
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

  case 942:
#line 4532 "fgl.yacc"
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
        sprintf (yyval.str, " a4gl_substr(%s,%d,%s,0) /*2*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
      sprintf (yyval.str, " a4gl_substr(%s,0x%x,%s,0)/*3*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 943:
#line 4591 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char buff2[256];
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
        sprintf (yyval.str, " a4gl_substr(%s,%d,%s,0) /*2*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
 
  if (((type & 0xffff) != 0) || (arrsize>0))
    {
      A4GL_lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      A4GL_lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " a4gl_substr(%s,0x%x,%s,0)/*3*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
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

  case 944:
#line 4646 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 945:
#line 4651 "fgl.yacc"
    {
	 A4GL_debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 946:
#line 4659 "fgl.yacc"
    {
A4GL_debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 947:
#line 4664 "fgl.yacc"
    {
A4GL_debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str); 
}
    break;

  case 948:
#line 4672 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 949:
#line 4678 "fgl.yacc"
    {
char buff[256];
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

  mcnt = 0;
}
    break;

  case 950:
#line 4706 "fgl.yacc"
    {
	 A4GL_debug("Array..");
}
    break;

  case 951:
#line 4709 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 952:
#line 4711 "fgl.yacc"
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      A4GL_lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 957:
#line 4762 "fgl.yacc"
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
        sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
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
      sprintf (yyval.str, " a4gl_let_substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      A4GL_debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 958:
#line 4814 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 960:
#line 4821 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 961:
#line 4827 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 962:
#line 4838 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 963:
#line 4845 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 965:
#line 4853 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 966:
#line 4856 "fgl.yacc"
    {A4GL_lex_printcomment("/* Variable */\n");}
    break;

  case 967:
#line 4857 "fgl.yacc"
    { A4GL_debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 969:
#line 4859 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 970:
#line 4860 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 971:
#line 4863 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 972:
#line 4866 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 973:
#line 4872 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 974:
#line 4875 "fgl.yacc"
    { A4GL_debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 975:
#line 4879 "fgl.yacc"
    {
A4GL_lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 976:
#line 4883 "fgl.yacc"
    {
A4GL_lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 977:
#line 4890 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 978:
#line 4895 "fgl.yacc"
    {
    A4GL_lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    A4GL_lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 979:
#line 4902 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 980:
#line 4905 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 985:
#line 4918 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  A4GL_lex_printcomment("/*..array_r_varid..*/");

printf("Got array %s %s\n",yyvsp[-3].str,yyvsp[-1].str);
if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
	// Its a variable
	//printf("gvd = true\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
	// Its an sql identifier or similar
	//printf("gvd = false\n");
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
printf("All done - ARRAY (array_r_varid) : %s\n",yyval.str);
}
    break;

  case 986:
#line 4937 "fgl.yacc"
    {
A4GL_lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
A4GL_lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 987:
#line 4944 "fgl.yacc"
    {
A4GL_lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 988:
#line 4951 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 989:
#line 4954 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 990:
#line 4968 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 995:
#line 4985 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 996:
#line 4990 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 997:
#line 4996 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 999:
#line 5003 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"A4GL_open_form(%s);"); }
    break;

  case 1000:
#line 5008 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1001:
#line 5011 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1002:
#line 5012 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1003:
#line 5015 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1004:
#line 5016 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1005:
#line 5019 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1006:
#line 5020 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1007:
#line 5025 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1008:
#line 5032 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1009:
#line 5035 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1010:
#line 5041 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1011:
#line 5043 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1012:
#line 5045 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1013:
#line 5047 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1014:
#line 5050 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1015:
#line 5050 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1016:
#line 5051 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1017:
#line 5056 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1018:
#line 5064 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1019:
#line 5065 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1020:
#line 5070 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1021:
#line 5072 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1022:
#line 5074 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1026:
#line 5091 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1027:
#line 5094 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1028:
#line 5097 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1029:
#line 5100 "fgl.yacc"
    {
//A4GL_lex_printc("A4GL_set_option_value('M',%s);\n",$<str>2);
print_options('M',yyvsp[0].str);
}
    break;

  case 1030:
#line 5104 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1031:
#line 5107 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1032:
#line 5110 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1033:
#line 5114 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1034:
#line 5118 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1035:
#line 5122 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1036:
#line 5125 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1037:
#line 5129 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1038:
#line 5132 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1039:
#line 5133 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1040:
#line 5134 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1041:
#line 5137 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1042:
#line 5140 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1043:
#line 5143 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1044:
#line 5146 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1045:
#line 5149 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1046:
#line 5152 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1047:
#line 5155 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1048:
#line 5172 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1051:
#line 5182 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1052:
#line 5189 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1054:
#line 5210 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1055:
#line 5215 "fgl.yacc"
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

  case 1056:
#line 5228 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1057:
#line 5233 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1058:
#line 5234 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1059:
#line 5238 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1063:
#line 5244 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1064:
#line 5246 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1066:
#line 5261 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1067:
#line 5265 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1068:
#line 5271 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1069:
#line 5272 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1070:
#line 5275 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1071:
#line 5276 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1072:
#line 5279 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1074:
#line 5298 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1075:
#line 5303 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1076:
#line 5308 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1077:
#line 5313 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1083:
#line 5335 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1084:
#line 5342 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1085:
#line 5351 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_terminate_report(yyvsp[0].str);
}
    break;

  case 1086:
#line 5357 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1087:
#line 5359 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1091:
#line 5370 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1092:
#line 5371 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5373 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1094:
#line 5374 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1095:
#line 5376 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1096:
#line 5377 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1097:
#line 5379 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1098:
#line 5380 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1099:
#line 5382 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1100:
#line 5383 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1101:
#line 5384 "fgl.yacc"
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

  case 1102:
#line 5398 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1103:
#line 5400 "fgl.yacc"
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

  case 1104:
#line 5417 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1111:
#line 5429 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1112:
#line 5429 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1113:
#line 5435 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1114:
#line 5435 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1115:
#line 5438 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1116:
#line 5438 "fgl.yacc"
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

  case 1117:
#line 5448 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1118:
#line 5449 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1119:
#line 5450 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1120:
#line 5457 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1121:
#line 5469 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1127:
#line 5480 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1128:
#line 5485 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1129:
#line 5489 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1130:
#line 5494 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1131:
#line 5500 "fgl.yacc"
    { strcpy(yyval.str,A4GL_get_default_scaling());}
    break;

  case 1132:
#line 5501 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1133:
#line 5502 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1134:
#line 5506 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1135:
#line 5507 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1136:
#line 5508 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1137:
#line 5509 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1138:
#line 5513 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1139:
#line 5523 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1140:
#line 5525 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1141:
#line 5530 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1142:
#line 5533 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1143:
#line 5538 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1144:
#line 5545 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1145:
#line 5552 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1146:
#line 5559 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1147:
#line 5568 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1148:
#line 5575 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1149:
#line 5582 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1150:
#line 5589 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1151:
#line 5596 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"A4GL_push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1156:
#line 5609 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1157:
#line 5610 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1158:
#line 5611 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1159:
#line 5612 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1160:
#line 5613 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1161:
#line 5614 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1162:
#line 5615 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1163:
#line 5616 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1164:
#line 5617 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1165:
#line 5618 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1168:
#line 5624 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1169:
#line 5625 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1170:
#line 5626 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1171:
#line 5627 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1176:
#line 5636 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);A4GL_debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1177:
#line 5637 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1178:
#line 5638 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1179:
#line 5639 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1180:
#line 5640 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1181:
#line 5641 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1182:
#line 5642 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1183:
#line 5643 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1184:
#line 5645 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1185:
#line 5646 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1186:
#line 5647 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1187:
#line 5648 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1188:
#line 5650 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1189:
#line 5651 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1190:
#line 5652 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1191:
#line 5653 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1195:
#line 5658 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 5659 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1200:
#line 5666 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1201:
#line 5673 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1202:
#line 5680 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
A4GL_debug("Order by Gives :%d\n",a);
}
    break;

  case 1203:
#line 5691 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1204:
#line 5700 "fgl.yacc"
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

  case 1205:
#line 5711 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1206:
#line 5715 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1207:
#line 5719 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
	 A4GL_debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1208:
#line 5725 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1209:
#line 5730 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1210:
#line 5738 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1211:
#line 5741 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1212:
#line 5750 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1213:
#line 5761 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1215:
#line 5768 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1216:
#line 5776 "fgl.yacc"
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

  case 1217:
#line 5786 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1218:
#line 5789 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1219:
#line 5793 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
A4GL_debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1220:
#line 5801 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1221:
#line 5804 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1222:
#line 5810 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1223:
#line 5814 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1224:
#line 5818 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1225:
#line 5822 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1226:
#line 5826 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1227:
#line 5832 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1228:
#line 5833 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1229:
#line 5834 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1230:
#line 5835 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1231:
#line 5840 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1232:
#line 5842 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1233:
#line 5845 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1234:
#line 5849 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1235:
#line 5852 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1236:
#line 5859 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1237:
#line 5864 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1238:
#line 5865 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1239:
#line 5866 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1240:
#line 5871 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1241:
#line 5872 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1242:
#line 5878 "fgl.yacc"
    {insql=1;}
    break;

  case 1243:
#line 5878 "fgl.yacc"
    {insql=0;}
    break;

  case 1244:
#line 5878 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1245:
#line 5883 "fgl.yacc"
    {insql=1;}
    break;

  case 1246:
#line 5883 "fgl.yacc"
    {insql=0;}
    break;

  case 1247:
#line 5883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1248:
#line 5894 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1249:
#line 5895 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1250:
#line 5901 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1251:
#line 5903 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1253:
#line 5910 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1254:
#line 5914 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1255:
#line 5915 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1257:
#line 5920 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 5923 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1259:
#line 5929 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1260:
#line 5932 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 5940 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1263:
#line 5947 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1264:
#line 5954 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1265:
#line 5957 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1266:
#line 5966 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1267:
#line 5969 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1268:
#line 5972 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1269:
#line 5975 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1270:
#line 5978 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1271:
#line 5981 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1272:
#line 5984 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1273:
#line 5991 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1274:
#line 5994 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1275:
#line 6001 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1276:
#line 6004 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1277:
#line 6010 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1278:
#line 6013 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1279:
#line 6020 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1280:
#line 6023 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1282:
#line 6031 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1284:
#line 6040 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1285:
#line 6043 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1286:
#line 6049 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1287:
#line 6052 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1288:
#line 6058 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1289:
#line 6065 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1290:
#line 6066 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1291:
#line 6070 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1292:
#line 6076 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1293:
#line 6079 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1295:
#line 6087 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1296:
#line 6094 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1297:
#line 6097 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1301:
#line 6115 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1307:
#line 6121 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1308:
#line 6124 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1309:
#line 6127 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1310:
#line 6133 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1312:
#line 6139 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1314:
#line 6150 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1315:
#line 6164 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1316:
#line 6173 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1317:
#line 6173 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1318:
#line 6178 "fgl.yacc"
    {insql=1;}
    break;

  case 1319:
#line 6178 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1320:
#line 6183 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1321:
#line 6186 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1322:
#line 6188 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1324:
#line 6195 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1325:
#line 6199 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1326:
#line 6203 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1327:
#line 6210 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1328:
#line 6213 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1329:
#line 6220 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1330:
#line 6224 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1331:
#line 6228 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1332:
#line 6237 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1333:
#line 6241 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1334:
#line 6247 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1335:
#line 6251 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1336:
#line 6257 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1337:
#line 6264 "fgl.yacc"
    {
A4GL_debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1338:
#line 6268 "fgl.yacc"
    {
 A4GL_debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1339:
#line 6273 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1340:
#line 6283 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1341:
#line 6286 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1342:
#line 6288 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1343:
#line 6290 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1344:
#line 6292 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1345:
#line 6294 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1346:
#line 6296 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_RELATIVE);}
    break;

  case 1347:
#line 6298 "fgl.yacc"
    {sprintf(yyval.str,"%d,A4GL_pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1348:
#line 6304 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1349:
#line 6314 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1350:
#line 6321 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1352:
#line 6327 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1356:
#line 6336 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1359:
#line 6341 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1360:
#line 6346 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1361:
#line 6353 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1362:
#line 6354 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1363:
#line 6361 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1364:
#line 6372 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1365:
#line 6373 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1366:
#line 6376 "fgl.yacc"
    {insql=1;}
    break;

  case 1367:
#line 6376 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1368:
#line 6381 "fgl.yacc"
    {
		 A4GL_lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1369:
#line 6386 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1371:
#line 6392 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1373:
#line 6396 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1374:
#line 6401 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1375:
#line 6406 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
	 A4GL_lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1376:
#line 6410 "fgl.yacc"
    {
	 A4GL_lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1378:
#line 6416 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1379:
#line 6420 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1380:
#line 6428 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1381:
#line 6431 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1382:
#line 6433 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1383:
#line 6438 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1386:
#line 6445 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1390:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1391:
#line 6455 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1392:
#line 6457 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1394:
#line 6463 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6469 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1399:
#line 6479 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1400:
#line 6484 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1401:
#line 6486 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1403:
#line 6492 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6495 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1406:
#line 6501 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1407:
#line 6509 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6514 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6524 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1413:
#line 6530 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1414:
#line 6536 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6538 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6544 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6549 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1419:
#line 6552 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1420:
#line 6555 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1421:
#line 6563 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6565 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1423:
#line 6576 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1424:
#line 6581 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1426:
#line 6585 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1427:
#line 6587 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1428:
#line 6594 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1429:
#line 6597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1430:
#line 6603 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1431:
#line 6607 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1432:
#line 6611 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1433:
#line 6614 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1434:
#line 6622 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1435:
#line 6629 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1438:
#line 6638 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1439:
#line 6644 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1440:
#line 6647 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1441:
#line 6658 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1442:
#line 6665 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1443:
#line 6671 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1444:
#line 6674 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1445:
#line 6681 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1446:
#line 6688 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1448:
#line 6695 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1449:
#line 6701 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1450:
#line 6702 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1451:
#line 6703 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1453:
#line 6707 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1455:
#line 6712 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1456:
#line 6719 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 6724 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1458:
#line 6725 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1459:
#line 6728 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1460:
#line 6731 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1461:
#line 6736 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1462:
#line 6737 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1463:
#line 6742 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1464:
#line 6745 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1465:
#line 6751 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1466:
#line 6754 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1467:
#line 6760 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1468:
#line 6763 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1469:
#line 6769 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1470:
#line 6772 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1471:
#line 6779 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1472:
#line 6780 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1473:
#line 6809 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1474:
#line 6811 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1478:
#line 6825 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1479:
#line 6828 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 6831 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1481:
#line 6834 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1483:
#line 6842 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1484:
#line 6845 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1486:
#line 6851 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1488:
#line 6857 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1489:
#line 6860 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1490:
#line 6863 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1491:
#line 6866 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1492:
#line 6869 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1493:
#line 6872 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1494:
#line 6875 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1496:
#line 6882 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1501:
#line 6889 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1502:
#line 6890 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1503:
#line 6895 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1504:
#line 6898 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1505:
#line 6902 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1506:
#line 6908 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1507:
#line 6909 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1508:
#line 6910 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1509:
#line 6911 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1514:
#line 6931 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1515:
#line 6936 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1516:
#line 6937 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1518:
#line 6940 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1522:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1524:
#line 6948 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1526:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 6956 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1531:
#line 6958 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 6961 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1533:
#line 6962 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1534:
#line 6969 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1538:
#line 6974 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1542:
#line 6990 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s", A4GL_strip_quotes (yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1543:
#line 6991 "fgl.yacc"
    {
		sprintf(yyval.str," %s", A4GL_strip_quotes (yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1544:
#line 6995 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1545:
#line 6996 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1547:
#line 7014 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1548:
#line 7015 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1549:
#line 7016 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1550:
#line 7020 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1551:
#line 7023 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1552:
#line 7029 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1553:
#line 7034 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1554:
#line 7039 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1556:
#line 7050 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
 A4GL_debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1561:
#line 7065 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1562:
#line 7068 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1563:
#line 7071 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1564:
#line 7073 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1565:
#line 7076 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1566:
#line 7078 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1567:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1568:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1569:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1570:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1571:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1572:
#line 7081 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1573:
#line 7082 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1574:
#line 7085 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1575:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1576:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1577:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1578:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1579:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1580:
#line 7090 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1581:
#line 7092 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1582:
#line 7095 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1597:
#line 7104 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1598:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str, A4GL_strip_quotes (yyvsp[0].str));}
    break;

  case 1599:
#line 7109 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1600:
#line 7117 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1601:
#line 7117 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1602:
#line 7122 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1603:
#line 7122 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1604:
#line 7128 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1605:
#line 7128 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1606:
#line 7133 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1607:
#line 7133 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1608:
#line 7140 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1609:
#line 7141 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1610:
#line 7142 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1614:
#line 7149 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1615:
#line 7150 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1616:
#line 7155 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1617:
#line 7158 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1618:
#line 7164 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1619:
#line 7167 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1620:
#line 7176 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1621:
#line 7188 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1622:
#line 7189 "fgl.yacc"
    {A4GL_debug("Got select list...\n");}
    break;

  case 1623:
#line 7192 "fgl.yacc"
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

  case 1624:
#line 7207 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1625:
#line 7217 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1626:
#line 7220 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1627:
#line 7228 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1628:
#line 7237 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1629:
#line 7240 "fgl.yacc"
    {
       A4GL_lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1630:
#line 7244 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1631:
#line 7247 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1632:
#line 7248 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1634:
#line 7257 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1635:
#line 7258 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(A4GL_get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1636:
#line 7267 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1637:
#line 7276 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1638:
#line 7281 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1639:
#line 7282 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1640:
#line 7283 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1641:
#line 7284 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1642:
#line 7292 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1643:
#line 7295 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1644:
#line 7301 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1645:
#line 7304 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1646:
#line 7307 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1647:
#line 7313 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1648:
#line 7322 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1649:
#line 7325 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
	}
    break;

  case 1650:
#line 7328 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
	}
    break;

  case 1651:
#line 7334 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1652:
#line 7340 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1653:
#line 7343 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1654:
#line 7346 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1655:
#line 7349 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1656:
#line 7356 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1657:
#line 7358 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1658:
#line 7360 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1659:
#line 7362 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1660:
#line 7364 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1661:
#line 7365 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1662:
#line 7366 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1663:
#line 7367 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1664:
#line 7368 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1665:
#line 7369 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1666:
#line 7370 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1667:
#line 7372 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1668:
#line 7374 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1669:
#line 7376 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1670:
#line 7378 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1671:
#line 7380 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1672:
#line 7382 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1673:
#line 7384 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1674:
#line 7385 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1675:
#line 7387 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1676:
#line 7391 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1677:
#line 7392 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1680:
#line 7402 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1681:
#line 7411 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1682:
#line 7415 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1683:
#line 7422 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1684:
#line 7422 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1686:
#line 7426 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1687:
#line 7431 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1688:
#line 7431 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1690:
#line 7435 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1691:
#line 7439 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1694:
#line 7448 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1695:
#line 7448 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,A4GL_get_undo_use());
}
    break;

  case 1700:
#line 7467 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1701:
#line 7468 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1704:
#line 7476 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1705:
#line 7482 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1708:
#line 7501 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1709:
#line 7502 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1710:
#line 7503 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1711:
#line 7504 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1712:
#line 7505 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1713:
#line 7506 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1714:
#line 7510 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1715:
#line 7511 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1716:
#line 7512 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1717:
#line 7516 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1718:
#line 7520 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1720:
#line 7529 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1722:
#line 7534 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1723:
#line 7535 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1724:
#line 7539 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1725:
#line 7545 "fgl.yacc"
    {
 		strcpy(yyval.str,A4GL_get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1726:
#line 7632 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1727:
#line 7636 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1728:
#line 7638 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1729:
#line 7645 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1730:
#line 7649 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1731:
#line 7655 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!"); pop_all_gen(UPDVAL2,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1732:
#line 7663 "fgl.yacc"
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

  case 1733:
#line 7673 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1734:
#line 7683 "fgl.yacc"
    {	
		yyval.sql_string=make_sql_string("SET *=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1735:
#line 7695 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("SET ",yyvsp[0].sql_string,0);
    }
    break;

  case 1736:
#line 7698 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1737:
#line 7717 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string("SET *= ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string("SET *=(",yyvsp[0].sql_string,")",0);
		}

		if (A4GL_isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1738:
#line 7743 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1739:
#line 7746 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1741:
#line 7755 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1742:
#line 7760 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);
		}
    break;

  case 1743:
#line 7763 "fgl.yacc"
    {
			push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 1744:
#line 7771 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
	}
    break;

  case 1745:
#line 7779 "fgl.yacc"
    { 
		if (gen_cnt(UPDVAL2)) {
			copy_gen(UPDVAL,UPDVAL2);
		} else {
                	push_gen(UPDVAL,yyvsp[0].sql_string);
		}
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0); 
	}
    break;

  case 1746:
#line 7792 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1747:
#line 7795 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1748:
#line 7803 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1749:
#line 7806 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("-",yyvsp[0].sql_string,0);
        }
    break;

  case 1750:
#line 7809 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string("+",yyvsp[0].sql_string,0);
        }
    break;

  case 1751:
#line 7817 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;

        }
    break;

  case 1752:
#line 7821 "fgl.yacc"
    {
                yyval.sql_string=yyvsp[0].sql_string;
        }
    break;

  case 1753:
#line 7824 "fgl.yacc"
    {
                yyval.sql_string=strdup(yyvsp[0].str);
        }
    break;

  case 1754:
#line 7827 "fgl.yacc"
    {
                yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
        }
    break;

  case 1755:
#line 7830 "fgl.yacc"
    { 
		yyval.sql_string=yyvsp[0].sql_string; 
		pop_all_gen(UPDVAL2,"!");
	}
    break;

  case 1756:
#line 7834 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1757:
#line 7835 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1758:
#line 7836 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1759:
#line 7837 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1760:
#line 7838 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1761:
#line 7844 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1762:
#line 7845 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1763:
#line 7846 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1764:
#line 7847 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1765:
#line 7848 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1766:
#line 7849 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1767:
#line 7850 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C7\n");}
    break;

  case 1768:
#line 7851 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C8\n");}
    break;

  case 1769:
#line 7852 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C9\n");}
    break;

  case 1770:
#line 7853 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);printf("C10\n");}
    break;

  case 1771:
#line 7854 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);printf("C11\n");}
    break;

  case 1772:
#line 7855 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);printf("C12\n");}
    break;

  case 1773:
#line 7856 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);printf("C13\n");}
    break;

  case 1774:
#line 7857 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);printf("C14\n");}
    break;

  case 1775:
#line 7861 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1776:
#line 7867 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1777:
#line 7868 "fgl.yacc"
    {
        yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1778:
#line 7881 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1779:
#line 7892 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1783:
#line 7898 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1784:
#line 7899 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s", A4GL_strip_quotes (yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1788:
#line 7911 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);
		z-=a;
		yyval.sql_string=strdup(A4GL_set_var_sql(z));

	} else {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
}
    break;

  case 1789:
#line 7925 "fgl.yacc"
    {
char r1[256];
char r2[256];
char buff[256];
char was_str[40000];
char *ptr1;
char *ptr2;
int aa;
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

  case 1790:
#line 7976 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1791:
#line 7978 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1792:
#line 7980 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1793:
#line 7981 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1794:
#line 7986 "fgl.yacc"
    {
A4GL_debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1795:
#line 7991 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1796:
#line 7993 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1797:
#line 7995 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1798:
#line 7997 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1799:
#line 8000 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1800:
#line 8004 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1801:
#line 8009 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1802:
#line 8014 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1803:
#line 8018 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1805:
#line 8028 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1807:
#line 8043 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1808:
#line 8046 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1809:
#line 8050 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1812:
#line 8069 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1813:
#line 8070 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1814:
#line 8073 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1815:
#line 8074 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1816:
#line 8075 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1817:
#line 8076 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1818:
#line 8077 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1819:
#line 8078 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1820:
#line 8079 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1821:
#line 8084 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1822:
#line 8085 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1823:
#line 8089 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1824:
#line 8093 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1825:
#line 8097 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1826:
#line 8101 "fgl.yacc"
    {
sprintf(yyval.str,"A4GL_cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1827:
#line 8106 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1828:
#line 8110 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1829:
#line 8115 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1831:
#line 8123 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1833:
#line 8129 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1834:
#line 8135 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1835:
#line 8139 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1840:
#line 8157 "fgl.yacc"
    {
chk4var=0;A4GL_lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	A4GL_prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1841:
#line 8164 "fgl.yacc"
    {
A4GL_lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
A4GL_lex_printc("{A4GL_debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (A4GL_aubit_strcasecmp(yyval.str,"whenever")!=0) A4GL_prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1842:
#line 8173 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1843:
#line 8173 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16810 "y.tab.c"

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


#line 8268 "fgl.yacc"

/* programmer routines */
/*
# include "lex.yy.c"
# include "lexify.c"
*/

void
set_clobber(char *c)
{
	char *ptr;
	char *ptr2;
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



