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
     NAME = 1633,
     UMINUS = 1634,
     COMMA = 1549,
     KW_OR = 1589,
     KW_AND = 1544,
     KW_USING = 1480,
     MATCHES = 1358,
     POWER = 1466,
     LESS_THAN = 1462,
     GREATER_THAN = 1376,
     EQUAL = 1539,
     GREATER_THAN_EQ = 1275,
     LESS_THAN_EQ = 1333,
     NOT_EQUAL = 1407,
     PLUS = 1575,
     MINUS = 1562,
     DIVIDE = 1495,
     MULTIPLY = 1467,
     MOD = 1563,
     COMMAND = 1340,
     NUMBER_VALUE = 1635,
     CHAR_VALUE = 1636,
     INT_VALUE = 1637,
     NAMED_GEN = 1638,
     CLINE = 1639,
     SQLLINE = 1640,
     KW_CSTART = 1641,
     KW_CEND = 1642,
     USER_DTYPE = 1643,
     SQL_TEXT = 1644,
     ALTER_TABLE = 1000,
     CREATE_DATABASE = 1001,
     ADD_CONSTRAINT = 1002,
     DROP_CONSTRAINT = 1003,
     AS_STATIC = 1004,
     NOT_FIELD_TOUCHED = 1005,
     LOCAL_FUNCTION = 1006,
     EVERY_ROW = 1007,
     ELIF = 1008,
     DOUBLE_PRECISION = 1009,
     COUNT_MULTIPLY = 1010,
     WAIT_FOR_KEY = 1011,
     AT_TERMINATION_CALL = 1012,
     TO_MAIN_CAPTION = 1013,
     CLEARSTAT = 1014,
     TO_MENUITEM = 1015,
     ID_TO_INT = 1016,
     TO_STATUSBOX = 1017,
     ASCII_HEIGHT_ALL = 1018,
     ASCII_WIDTH_ALL = 1019,
     IMPORT_DATATYPE = 1020,
     UP_BY = 1021,
     PAGE_TRAILER_SIZE = 1022,
     PAGE_HEADER_SIZE = 1023,
     FIRST_PAGE_HEADER_SIZE = 1024,
     BYTES_USE_AS_IMAGE = 1025,
     BYTES_USE_AS_ASCII = 1026,
     DOWN_BY = 1027,
     CLOSE_STATUSBOX = 1028,
     MODIFY_NEXT_SIZE = 1029,
     LOCK_MODE_PAGE = 1030,
     LOCK_MODE_ROW = 1031,
     TO_PIPE = 1032,
     TO_PRINTER = 1033,
     STATUSBOX = 1034,
     CONNECT_TO = 1035,
     FORMHANDLER_INPUT = 1036,
     UNITS_YEAR = 1037,
     UNITS_MONTH = 1038,
     UNITS_DAY = 1039,
     UNITS_HOUR = 1040,
     UNITS_MINUTE = 1041,
     UNITS_SECOND = 1042,
     NO_NEW_LINES = 1043,
     FIELDTOWIDGET = 1044,
     WITH_HOLD = 1045,
     SHOW_MENU = 1046,
     CWIS = 1047,
     CREATE_IDX = 1048,
     FORM_IS_COMPILED = 1049,
     PDF_REPORT = 1050,
     IMPORT_FUNCTION = 1051,
     PROMPT_MANY = 1052,
     POINTS = 1053,
     MM = 1054,
     INCHES = 1055,
     PREPEND = 1056,
     MEMBER_OF = 1057,
     MEMBER_FUNCTION = 1058,
     APPEND = 1059,
     TEMPLATE = 1060,
     END_TEMPLATE = 1061,
     SQLSICS = 1062,
     CREATE_SCHEMA = 1063,
     SQLSIRR = 1064,
     UPDATESTATS_T = 1065,
     SQLSICR = 1066,
     WHENEVER_SQLSUCCESS = 1067,
     WHENEVER_SQLWARNING = 1068,
     START_EXTERN = 1069,
     WHENEVER_ANY_ERROR = 1070,
     WHENEVER_NOT_FOUND = 1071,
     CONTINUE_CONSTRUCT = 1072,
     FOUNCONSTR = 1073,
     SQLSIDR = 1074,
     WHENEVER_SQLERROR = 1075,
     CREATE_TEMP_TABLE = 1076,
     CURRENT_WINDOW_IS = 1077,
     FIRST_PAGE_HEADER = 1078,
     ORDER_EXTERNAL_BY = 1079,
     SCROLL_CURSOR_FOR = 1080,
     SCROLL_CURSOR = 1081,
     SQL_INTERRUPT_OFF = 1082,
     STOP_ALL_EXTERNAL = 1083,
     WITH_CHECK_OPTION = 1084,
     WITH_GRANT_OPTION = 1085,
     SQLSLMNW = 1086,
     ADDCONSTUNIQ = 1087,
     CONTINUE_DISPLAY = 1088,
     CONTINUE_FOREACH = 1089,
     OUTPUT_TO_REPORT = 1090,
     SQL_INTERRUPT_ON = 1091,
     WHENEVER_SUCCESS = 1092,
     WHENEVER_WARNING = 1093,
     WHERE_CURRENT_OF = 1094,
     WITHOUT_DEFAULTS = 1095,
     FOCONSTR = 1096,
     SCALED_BY = 1097,
     CONTINUE_PROMPT = 1098,
     PDF_FUNCTION = 1099,
     DEFER_INTERRUPT = 1100,
     DISPLAY_BY_NAME = 1101,
     NOT_NULL_UNIQUE = 1102,
     SKIP_TO_TOP = 1103,
     TOP_OF_PAGE = 1104,
     SKIP_TO = 1105,
     SKIP_BY = 1106,
     WITHOUT_WAITING = 1107,
     BEFCONSTRUCT = 1108,
     SQLSLMW = 1109,
     WHENEVER_ERROR_CONTINUE = 1110,
     WHENEVER_ERROR = 1111,
     AFTCONSTRUCT = 1112,
     ALL_PRIVILEGES = 1113,
     CLOSE_DATABASE = 1114,
     CONTINUE_INPUT = 1115,
     CONTINUE_WHILE = 1116,
     CREATE_SYNONYM = 1117,
     DROP_TABLE = 1118,
     EXIT_CONSTRUCT = 1119,
     INEXCLUSIVE = 1120,
     REPORT_TO_PRINTER = 1121,
     REPORT_TO_PIPE = 1122,
     SET_SESSION_TO = 1123,
     UPDATESTATS = 1124,
     WITHOUT_HEAD = 1125,
     CLEARSCR = 1126,
     WITH_B_LOG = 1127,
     AUTHORIZATION = 1128,
     BOTTOM_MARGIN = 1129,
     CLOSE_SESSION = 1130,
     CONTINUE_CASE = 1131,
     CONTINUE_MENU = 1132,
     DISPLAY_ARRAY = 1133,
     END_SQL = 1134,
     DOLLAR = 1135,
     END_CONSTRUCT = 1136,
     FIELD_TOUCHED = 1137,
     FINISH_REPORT = 1138,
     INFACC = 1139,
     INPUT_NO_WRAP = 1140,
     LOCKMODEPAGE = 1141,
     SETPMOFF = 1142,
     UNCONSTRAINED = 1143,
     PAGE_TRAILER = 1144,
     SETPMON = 1145,
     BEFGROUP = 1146,
     CLOSE_WINDOW = 1147,
     COMMENT_LINE = 1148,
     CONTINUE_FOR = 1149,
     CREATE_DB = 1150,
     CREATE_TABLE = 1151,
     DEFAULT_NULL = 1152,
     DELETE_USING = 1153,
     DISPLAY_FORM = 1154,
     END_FUNCTION = 1155,
     EXIT_DISPLAY = 1156,
     EXIT_FOREACH = 1157,
     EXIT_PROGRAM = 1158,
     INFCOLS = 1159,
     LOCKMODEROW = 1160,
     ON_EVERY_ROW = 1161,
     OPEN_SESSION = 1162,
     RIGHT_MARGIN = 1163,
     SELECT_USING = 1164,
     START_REPORT = 1165,
     UNLOCK_TABLE = 1166,
     UPDATE_USING = 1167,
     ACL_BUILTIN = 1168,
     AFTGROUP = 1169,
     INFIDX = 1170,
     INFSTAT = 1171,
     LEFT_MARGIN = 1172,
     PAGE_HEADER = 1173,
     ROLLBACK_W = 1174,
     SET_SESSION = 1175,
     SQLSEOFF = 1176,
     WITH_A_LOG = 1177,
     BEFDISP = 1178,
     BEFORE_MENU = 1179,
     CREATE_VIEW = 1180,
     DEFINE_TYPE = 1181,
     DELETE_FROM = 1182,
     END_DISPLAY = 1183,
     END_REPORT = 1184,
     END_FOREACH = 1185,
     END_FOR = 1186,
     END_GLOBALS = 1187,
     EXIT_PROMPT = 1188,
     EXTENT_SIZE = 1189,
     FOREIGN_KEY = 1190,
     HIDE_OPTION = 1191,
     HIDE_WINDOW = 1192,
     INSERT_INTO = 1193,
     IS_NOT_NULL = 1194,
     MOVE_WINDOW = 1195,
     NEXT_OPTION = 1196,
     NOT_MATCHES = 1197,
     ON_LAST_ROW = 1198,
     OPEN_WINDOW = 1199,
     OPEN_STATUSBOX = 1200,
     PAGE_LENGTH = 1201,
     PAGE_WIDTH = 1202,
     PRIMARY_KEY = 1203,
     PROMPT_LINE = 1204,
     RECORD_LIKE = 1205,
     ROLLFORWARD = 1206,
     SETBL = 1207,
     SHOW_OPTION = 1208,
     SHOW_WINDOW = 1209,
     SQLSEON = 1210,
     TO_DATABASE = 1211,
     USE_SESSION = 1212,
     WITH_NO_LOG = 1213,
     AFTDISP = 1214,
     BEFFIELD = 1215,
     INSHARE = 1216,
     UNLOCKTAB = 1217,
     AFTFIELD = 1218,
     ATTRIBUTES = 1219,
     BEFINP = 1220,
     BEGIN_WORK = 1221,
     CLEARWIN = 1222,
     CLOSE_FORM = 1223,
     DEFER_QUIT = 1224,
     DESCENDING = 1225,
     DROP_INDEX = 1226,
     END_PROMPT = 1227,
     END_RECORD = 1228,
     ERROR_LINE = 1229,
     EXIT_INPUT = 1230,
     EXIT_WHILE = 1231,
     FOR_UPDATE_OF = 1232,
     FOR_UPDATE = 1233,
     GET_FLDBUF = 1234,
     INITIALIZE = 1235,
     INPUT_WRAP = 1236,
     LOCK_TABLE = 1237,
     MSG_LINE = 1238,
     NOT_EXISTS = 1239,
     ON_ANY_KEY = 1240,
     REFERENCES = 1241,
     RENCOL = 1242,
     SET_CURSOR = 1243,
     SMALLFLOAT = 1244,
     SQLSUCCESS = 1245,
     TOP_MARGIN = 1246,
     WITH_ARRAY = 1247,
     ACCEPTKEY = 1248,
     ACCEPT = 1249,
     AFTINP = 1250,
     CLEARFORMTODEFAULTS = 1251,
     CLEARFORM = 1252,
     CLEAR_X_FORM = 1253,
     COMMIT_W = 1254,
     NEXTPAGE = 1255,
     PREVPAGE = 1256,
     CTRL_KEY = 1257,
     INFTABS = 1258,
     NEXTFIELD = 1259,
     NEXTFORM = 1260,
     RENTAB = 1261,
     ASCENDING = 1262,
     ASSOCIATE = 1263,
     CHARACTER = 1264,
     CONSTRUCT = 1265,
     DELIMITER = 1266,
     DOWNSHIFT = 1267,
     DROP_VIEW = 1268,
     END_INPUT = 1269,
     END_WHILE = 1270,
     EXCLUSIVE = 1271,
     EXIT_CASE = 1272,
     EXIT_MENU = 1273,
     FORM_LINE = 1274,
     INTERRUPT = 1276,
     INTO_TEMP = 1277,
     INVISIBLE = 1278,
     IN_MEMORY = 1279,
     LINKED_TO = 1280,
     LOAD_FROM = 1281,
     LOCKTAB = 1282,
     MENU_LINE = 1283,
     OPEN_FORM = 1284,
     OTHERWISE = 1285,
     PRECISION = 1286,
     PRIOR = 1287,
     PROCEDURE = 1288,
     REPORT_TO = 1289,
     RETURNING = 1290,
     UNDERLINE = 1291,
     UNLOAD_TO = 1292,
     BEFROW = 1293,
     UNLOAD_T = 1294,
     VARIABLE = 1295,
     ABSOLUTE = 1296,
     AFTROW = 1297,
     BUFFERED = 1298,
     CONSTANT = 1299,
     CONST = 1300,
     CONTINUE = 1301,
     DATABASE = 1302,
     DATETIME = 1303,
     DEFAULTS = 1304,
     DISTINCT = 1305,
     END_CASE = 1306,
     END_MAIN = 1307,
     END_MENU = 1308,
     END_TYPE = 1309,
     EXIT_FOR = 1310,
     EXTERNAL = 1311,
     FRACTION = 1312,
     FUNCTION = 1313,
     GROUP_BY = 1314,
     INTERVAL = 1315,
     KWMESSAGE = 1316,
     NOT_LIKE = 1317,
     NOT_NULL = 1318,
     PASSWORD = 1319,
     PREVIOUS = 1320,
     READONLY = 1321,
     REGISTER = 1322,
     RELATIVE = 1323,
     RESOURCE = 1324,
     SMALLINT = 1325,
     VALIDATE = 1326,
     WHENEVER = 1327,
     WITH_LOG = 1328,
     WORDWRAP = 1329,
     BY_NAME = 1330,
     IN_FILE = 1331,
     IS_NULL = 1332,
     AVERAGE = 1334,
     BETWEEN = 1335,
     CAPTION = 1336,
     CLIPPED = 1337,
     CLOSE_BRACKET = 1338,
     COLUMNS = 1339,
     COMMENT = 1341,
     CONNECT = 1342,
     CURRENT = 1343,
     DBYNAME = 1344,
     DECIMAL = 1345,
     DECLARE = 1346,
     DEFAULT = 1347,
     DISPLAY = 1348,
     ENDCODE = 1349,
     EXECUTE = 1350,
     FOREACH = 1351,
     FOREIGN = 1352,
     GLOBALS = 1353,
     INFIELD = 1354,
     INTEGER = 1355,
     KWWINDOW = 1356,
     MAGENTA = 1357,
     NUMERIC = 1359,
     OPTIONS = 1360,
     PERCENT = 1361,
     PREPARE = 1362,
     PROGRAM = 1363,
     RECOVER = 1364,
     REVERSE = 1365,
     SECTION = 1366,
     SESSION = 1367,
     SYNONYM = 1368,
     THRU = 1369,
     TRAILER = 1370,
     UPSHIFT = 1371,
     VARCHAR = 1372,
     WAITING = 1373,
     CLOSE_SHEV = 1374,
     CLOSE_SQUARE = 1375,
     KW_FALSE = 1377,
     NOT_IN = 1378,
     ONKEY = 1379,
     OPEN_BRACKET = 1380,
     BORDER = 1381,
     BOTTOM = 1382,
     COLUMN = 1383,
     COMMIT = 1384,
     CREATE = 1385,
     CURSOR = 1386,
     DEFINE = 1387,
     DELETE = 1388,
     DOUBLE = 1389,
     END_IF = 1390,
     ESCAPE = 1391,
     EXISTS = 1392,
     EXTEND = 1393,
     EXTENT = 1394,
     FINISH = 1395,
     FORMAT = 1396,
     HAVING = 1397,
     HEADER = 1398,
     INSERT = 1399,
     LOCATE = 1400,
     MARGIN = 1401,
     MEMORY = 1402,
     MINUTE = 1403,
     MODIFY = 1404,
     NORMAL = 1405,
     EQUAL_EQUAL = 1406,
     OPEN_SHEV = 1408,
     OPEN_SQUARE = 1409,
     OPTION = 1410,
     OUTPUT = 1411,
     PROMPT = 1412,
     PUBLIC = 1413,
     RECORD = 1414,
     REPORT = 1415,
     RETURN = 1416,
     REVOKE = 1417,
     SCHEMA = 1418,
     SCROLL_USING = 1419,
     SCROLL = 1420,
     SECOND = 1421,
     SELECT = 1422,
     SERIAL = 1423,
     SETL = 1424,
     SHARED = 1425,
     SPACES = 1426,
     UNIQUE = 1427,
     UNLOCK = 1428,
     UPDATE = 1429,
     VALUES = 1430,
     YELLOW = 1431,
     AFTER = 1432,
     KWLINE = 1433,
     KW_NULL = 1434,
     KW_TRUE = 1435,
     SINGLE_KEY = 1436,
     ALTER = 1437,
     ARRAY = 1438,
     ASCII = 1439,
     AUDIT = 1440,
     BLACK = 1441,
     BLINK = 1442,
     CHECK = 1443,
     CLEAR = 1444,
     CLOSE = 1445,
     CODE_C = 1446,
     COUNT = 1447,
     DEFER = 1448,
     ERROR = 1449,
     EVERY = 1450,
     FETCH = 1451,
     FIRST = 1452,
     FLOAT = 1453,
     FLUSH = 1454,
     FOUND = 1455,
     GRANT = 1456,
     GREEN = 1457,
     GROUP = 1458,
     INDEX = 1459,
     KWFORM = 1460,
     LABEL = 1461,
     LOCAL = 1463,
     MONEY = 1464,
     MONTH = 1465,
     ORDER = 1468,
     OUTER = 1469,
     PAUSE = 1470,
     PRINT_IMAGE = 1471,
     PRINT_FILE = 1472,
     PRINT = 1473,
     RIGHT = 1474,
     DOUBLE_COLON = 1475,
     SEMICOLON = 1476,
     SLEEP = 1477,
     TUPLE = 1478,
     UNION = 1479,
     WHERE = 1481,
     WHILE = 1482,
     WHITE = 1483,
     CCODE = 1484,
     ANSI = 1485,
     BLUE = 1486,
     BOLD = 1487,
     BYTE = 1488,
     FCALL = 1489,
     CASE = 1490,
     CHAR = 1491,
     CYAN = 1492,
     DATE = 1493,
     DESC = 1494,
     DOWN = 1496,
     TAB = 1497,
     DROP = 1498,
     ELSE = 1499,
     EXEC = 1500,
     EXIT = 1501,
     FREE = 1502,
     FROM = 1503,
     GOTO = 1504,
     HELP_FILE = 1505,
     LANG_FILE = 1506,
     HELP = 1507,
     HIDE = 1508,
     HOUR = 1509,
     INTO = 1510,
     LAST = 1511,
     LEFT = 1512,
     LIKE = 1513,
     MAIN = 1514,
     MENU = 1515,
     MODE = 1516,
     NEED = 1517,
     NEXT = 1518,
     NOCR = 1519,
     OPEN = 1520,
     QUIT = 1521,
     REAL = 1522,
     ROWS = 1523,
     SHOW = 1524,
     SIZE = 1525,
     SKIP = 1526,
     SOME = 1527,
     STEP = 1528,
     STOP = 1529,
     TEMP = 1530,
     TEXT = 1531,
     THEN = 1532,
     USER = 1533,
     WAIT = 1534,
     WHEN = 1535,
     WITH = 1536,
     WORK = 1537,
     YEAR = 1538,
     KW_IS = 1540,
     XSET = 1541,
     ADD = 1542,
     ALL = 1543,
     ANY = 1545,
     ASC = 1546,
     AVG = 1547,
     COLON = 1548,
     DAY = 1550,
     DBA = 1551,
     DEC = 1552,
     DIM = 1553,
     FKEY = 1554,
     FOR = 1555,
     KEY = 1556,
     KWNO = 1557,
     LET = 1558,
     LOG = 1559,
     XMAX = 1560,
     XMIN = 1561,
     NOT = 1564,
     PAD = 1565,
     PUT = 1566,
     RED = 1567,
     ROW = 1568,
     RUN = 1569,
     SQL = 1570,
     SUM = 1571,
     TOP = 1572,
     USE = 1573,
     ATSIGN = 1574,
     AS_TIFF = 1576,
     AS_GIF = 1577,
     AS_PNG = 1578,
     AS_JPEG = 1579,
     AS = 1580,
     AT = 1581,
     BY = 1582,
     DOT = 1583,
     GO = 1584,
     IF = 1585,
     IN = 1586,
     OF = 1587,
     ON = 1588,
     TO = 1590,
     UP = 1591,
     FONT_NAME = 1592,
     FONT_SIZE = 1593,
     PAPER_SIZE_IS_LETTER = 1594,
     PAPER_SIZE_IS_LEGAL = 1595,
     PAPER_SIZE_IS_A5 = 1596,
     PAPER_SIZE_IS_A4 = 1597,
     PAPER_SIZE_IS_LETTER_L = 1598,
     PAPER_SIZE_IS_LEGAL_L = 1599,
     PAPER_SIZE_IS_A5_L = 1600,
     PAPER_SIZE_IS_A4_L = 1601,
     FORMHANDLER = 1602,
     END_FORMHANDLER = 1603,
     BEFORE_EVENT = 1604,
     BEFORE_OPEN_FORM = 1605,
     AFTER_EVENT = 1606,
     BEFORE_CLOSE_FORM = 1607,
     BEFORE_ANY = 1608,
     AFTER_ANY = 1609,
     MENUHANDLER = 1610,
     END_MENUHANDLER = 1611,
     BEFORE_SHOW_MENU = 1612,
     DISABLE_PROGRAM = 1613,
     DISABLE_ALL = 1614,
     BUTTONS = 1615,
     CHECK_MENUITEM = 1616,
     DISABLE_FORM = 1617,
     DISABLE_MENUITEMS = 1618,
     DISABLE = 1619,
     ENABLE_FORM = 1620,
     ENABLE_MENUITEMS = 1621,
     ENABLE = 1622,
     KWFIELD = 1623,
     ICON = 1624,
     MESSAGEBOX = 1625,
     TO_DEFAULTS = 1626,
     UNCHECK_MENUITEM = 1627,
     BEFORE = 1628,
     INPUT = 1629,
     END = 1630,
     INT_TO_ID = 1631
   };
#endif
#define NAME 1633
#define UMINUS 1634
#define COMMA 1549
#define KW_OR 1589
#define KW_AND 1544
#define KW_USING 1480
#define MATCHES 1358
#define POWER 1466
#define LESS_THAN 1462
#define GREATER_THAN 1376
#define EQUAL 1539
#define GREATER_THAN_EQ 1275
#define LESS_THAN_EQ 1333
#define NOT_EQUAL 1407
#define PLUS 1575
#define MINUS 1562
#define DIVIDE 1495
#define MULTIPLY 1467
#define MOD 1563
#define COMMAND 1340
#define NUMBER_VALUE 1635
#define CHAR_VALUE 1636
#define INT_VALUE 1637
#define NAMED_GEN 1638
#define CLINE 1639
#define SQLLINE 1640
#define KW_CSTART 1641
#define KW_CEND 1642
#define USER_DTYPE 1643
#define SQL_TEXT 1644
#define ALTER_TABLE 1000
#define CREATE_DATABASE 1001
#define ADD_CONSTRAINT 1002
#define DROP_CONSTRAINT 1003
#define AS_STATIC 1004
#define NOT_FIELD_TOUCHED 1005
#define LOCAL_FUNCTION 1006
#define EVERY_ROW 1007
#define ELIF 1008
#define DOUBLE_PRECISION 1009
#define COUNT_MULTIPLY 1010
#define WAIT_FOR_KEY 1011
#define AT_TERMINATION_CALL 1012
#define TO_MAIN_CAPTION 1013
#define CLEARSTAT 1014
#define TO_MENUITEM 1015
#define ID_TO_INT 1016
#define TO_STATUSBOX 1017
#define ASCII_HEIGHT_ALL 1018
#define ASCII_WIDTH_ALL 1019
#define IMPORT_DATATYPE 1020
#define UP_BY 1021
#define PAGE_TRAILER_SIZE 1022
#define PAGE_HEADER_SIZE 1023
#define FIRST_PAGE_HEADER_SIZE 1024
#define BYTES_USE_AS_IMAGE 1025
#define BYTES_USE_AS_ASCII 1026
#define DOWN_BY 1027
#define CLOSE_STATUSBOX 1028
#define MODIFY_NEXT_SIZE 1029
#define LOCK_MODE_PAGE 1030
#define LOCK_MODE_ROW 1031
#define TO_PIPE 1032
#define TO_PRINTER 1033
#define STATUSBOX 1034
#define CONNECT_TO 1035
#define FORMHANDLER_INPUT 1036
#define UNITS_YEAR 1037
#define UNITS_MONTH 1038
#define UNITS_DAY 1039
#define UNITS_HOUR 1040
#define UNITS_MINUTE 1041
#define UNITS_SECOND 1042
#define NO_NEW_LINES 1043
#define FIELDTOWIDGET 1044
#define WITH_HOLD 1045
#define SHOW_MENU 1046
#define CWIS 1047
#define CREATE_IDX 1048
#define FORM_IS_COMPILED 1049
#define PDF_REPORT 1050
#define IMPORT_FUNCTION 1051
#define PROMPT_MANY 1052
#define POINTS 1053
#define MM 1054
#define INCHES 1055
#define PREPEND 1056
#define MEMBER_OF 1057
#define MEMBER_FUNCTION 1058
#define APPEND 1059
#define TEMPLATE 1060
#define END_TEMPLATE 1061
#define SQLSICS 1062
#define CREATE_SCHEMA 1063
#define SQLSIRR 1064
#define UPDATESTATS_T 1065
#define SQLSICR 1066
#define WHENEVER_SQLSUCCESS 1067
#define WHENEVER_SQLWARNING 1068
#define START_EXTERN 1069
#define WHENEVER_ANY_ERROR 1070
#define WHENEVER_NOT_FOUND 1071
#define CONTINUE_CONSTRUCT 1072
#define FOUNCONSTR 1073
#define SQLSIDR 1074
#define WHENEVER_SQLERROR 1075
#define CREATE_TEMP_TABLE 1076
#define CURRENT_WINDOW_IS 1077
#define FIRST_PAGE_HEADER 1078
#define ORDER_EXTERNAL_BY 1079
#define SCROLL_CURSOR_FOR 1080
#define SCROLL_CURSOR 1081
#define SQL_INTERRUPT_OFF 1082
#define STOP_ALL_EXTERNAL 1083
#define WITH_CHECK_OPTION 1084
#define WITH_GRANT_OPTION 1085
#define SQLSLMNW 1086
#define ADDCONSTUNIQ 1087
#define CONTINUE_DISPLAY 1088
#define CONTINUE_FOREACH 1089
#define OUTPUT_TO_REPORT 1090
#define SQL_INTERRUPT_ON 1091
#define WHENEVER_SUCCESS 1092
#define WHENEVER_WARNING 1093
#define WHERE_CURRENT_OF 1094
#define WITHOUT_DEFAULTS 1095
#define FOCONSTR 1096
#define SCALED_BY 1097
#define CONTINUE_PROMPT 1098
#define PDF_FUNCTION 1099
#define DEFER_INTERRUPT 1100
#define DISPLAY_BY_NAME 1101
#define NOT_NULL_UNIQUE 1102
#define SKIP_TO_TOP 1103
#define TOP_OF_PAGE 1104
#define SKIP_TO 1105
#define SKIP_BY 1106
#define WITHOUT_WAITING 1107
#define BEFCONSTRUCT 1108
#define SQLSLMW 1109
#define WHENEVER_ERROR_CONTINUE 1110
#define WHENEVER_ERROR 1111
#define AFTCONSTRUCT 1112
#define ALL_PRIVILEGES 1113
#define CLOSE_DATABASE 1114
#define CONTINUE_INPUT 1115
#define CONTINUE_WHILE 1116
#define CREATE_SYNONYM 1117
#define DROP_TABLE 1118
#define EXIT_CONSTRUCT 1119
#define INEXCLUSIVE 1120
#define REPORT_TO_PRINTER 1121
#define REPORT_TO_PIPE 1122
#define SET_SESSION_TO 1123
#define UPDATESTATS 1124
#define WITHOUT_HEAD 1125
#define CLEARSCR 1126
#define WITH_B_LOG 1127
#define AUTHORIZATION 1128
#define BOTTOM_MARGIN 1129
#define CLOSE_SESSION 1130
#define CONTINUE_CASE 1131
#define CONTINUE_MENU 1132
#define DISPLAY_ARRAY 1133
#define END_SQL 1134
#define DOLLAR 1135
#define END_CONSTRUCT 1136
#define FIELD_TOUCHED 1137
#define FINISH_REPORT 1138
#define INFACC 1139
#define INPUT_NO_WRAP 1140
#define LOCKMODEPAGE 1141
#define SETPMOFF 1142
#define UNCONSTRAINED 1143
#define PAGE_TRAILER 1144
#define SETPMON 1145
#define BEFGROUP 1146
#define CLOSE_WINDOW 1147
#define COMMENT_LINE 1148
#define CONTINUE_FOR 1149
#define CREATE_DB 1150
#define CREATE_TABLE 1151
#define DEFAULT_NULL 1152
#define DELETE_USING 1153
#define DISPLAY_FORM 1154
#define END_FUNCTION 1155
#define EXIT_DISPLAY 1156
#define EXIT_FOREACH 1157
#define EXIT_PROGRAM 1158
#define INFCOLS 1159
#define LOCKMODEROW 1160
#define ON_EVERY_ROW 1161
#define OPEN_SESSION 1162
#define RIGHT_MARGIN 1163
#define SELECT_USING 1164
#define START_REPORT 1165
#define UNLOCK_TABLE 1166
#define UPDATE_USING 1167
#define ACL_BUILTIN 1168
#define AFTGROUP 1169
#define INFIDX 1170
#define INFSTAT 1171
#define LEFT_MARGIN 1172
#define PAGE_HEADER 1173
#define ROLLBACK_W 1174
#define SET_SESSION 1175
#define SQLSEOFF 1176
#define WITH_A_LOG 1177
#define BEFDISP 1178
#define BEFORE_MENU 1179
#define CREATE_VIEW 1180
#define DEFINE_TYPE 1181
#define DELETE_FROM 1182
#define END_DISPLAY 1183
#define END_REPORT 1184
#define END_FOREACH 1185
#define END_FOR 1186
#define END_GLOBALS 1187
#define EXIT_PROMPT 1188
#define EXTENT_SIZE 1189
#define FOREIGN_KEY 1190
#define HIDE_OPTION 1191
#define HIDE_WINDOW 1192
#define INSERT_INTO 1193
#define IS_NOT_NULL 1194
#define MOVE_WINDOW 1195
#define NEXT_OPTION 1196
#define NOT_MATCHES 1197
#define ON_LAST_ROW 1198
#define OPEN_WINDOW 1199
#define OPEN_STATUSBOX 1200
#define PAGE_LENGTH 1201
#define PAGE_WIDTH 1202
#define PRIMARY_KEY 1203
#define PROMPT_LINE 1204
#define RECORD_LIKE 1205
#define ROLLFORWARD 1206
#define SETBL 1207
#define SHOW_OPTION 1208
#define SHOW_WINDOW 1209
#define SQLSEON 1210
#define TO_DATABASE 1211
#define USE_SESSION 1212
#define WITH_NO_LOG 1213
#define AFTDISP 1214
#define BEFFIELD 1215
#define INSHARE 1216
#define UNLOCKTAB 1217
#define AFTFIELD 1218
#define ATTRIBUTES 1219
#define BEFINP 1220
#define BEGIN_WORK 1221
#define CLEARWIN 1222
#define CLOSE_FORM 1223
#define DEFER_QUIT 1224
#define DESCENDING 1225
#define DROP_INDEX 1226
#define END_PROMPT 1227
#define END_RECORD 1228
#define ERROR_LINE 1229
#define EXIT_INPUT 1230
#define EXIT_WHILE 1231
#define FOR_UPDATE_OF 1232
#define FOR_UPDATE 1233
#define GET_FLDBUF 1234
#define INITIALIZE 1235
#define INPUT_WRAP 1236
#define LOCK_TABLE 1237
#define MSG_LINE 1238
#define NOT_EXISTS 1239
#define ON_ANY_KEY 1240
#define REFERENCES 1241
#define RENCOL 1242
#define SET_CURSOR 1243
#define SMALLFLOAT 1244
#define SQLSUCCESS 1245
#define TOP_MARGIN 1246
#define WITH_ARRAY 1247
#define ACCEPTKEY 1248
#define ACCEPT 1249
#define AFTINP 1250
#define CLEARFORMTODEFAULTS 1251
#define CLEARFORM 1252
#define CLEAR_X_FORM 1253
#define COMMIT_W 1254
#define NEXTPAGE 1255
#define PREVPAGE 1256
#define CTRL_KEY 1257
#define INFTABS 1258
#define NEXTFIELD 1259
#define NEXTFORM 1260
#define RENTAB 1261
#define ASCENDING 1262
#define ASSOCIATE 1263
#define CHARACTER 1264
#define CONSTRUCT 1265
#define DELIMITER 1266
#define DOWNSHIFT 1267
#define DROP_VIEW 1268
#define END_INPUT 1269
#define END_WHILE 1270
#define EXCLUSIVE 1271
#define EXIT_CASE 1272
#define EXIT_MENU 1273
#define FORM_LINE 1274
#define INTERRUPT 1276
#define INTO_TEMP 1277
#define INVISIBLE 1278
#define IN_MEMORY 1279
#define LINKED_TO 1280
#define LOAD_FROM 1281
#define LOCKTAB 1282
#define MENU_LINE 1283
#define OPEN_FORM 1284
#define OTHERWISE 1285
#define PRECISION 1286
#define PRIOR 1287
#define PROCEDURE 1288
#define REPORT_TO 1289
#define RETURNING 1290
#define UNDERLINE 1291
#define UNLOAD_TO 1292
#define BEFROW 1293
#define UNLOAD_T 1294
#define VARIABLE 1295
#define ABSOLUTE 1296
#define AFTROW 1297
#define BUFFERED 1298
#define CONSTANT 1299
#define CONST 1300
#define CONTINUE 1301
#define DATABASE 1302
#define DATETIME 1303
#define DEFAULTS 1304
#define DISTINCT 1305
#define END_CASE 1306
#define END_MAIN 1307
#define END_MENU 1308
#define END_TYPE 1309
#define EXIT_FOR 1310
#define EXTERNAL 1311
#define FRACTION 1312
#define FUNCTION 1313
#define GROUP_BY 1314
#define INTERVAL 1315
#define KWMESSAGE 1316
#define NOT_LIKE 1317
#define NOT_NULL 1318
#define PASSWORD 1319
#define PREVIOUS 1320
#define READONLY 1321
#define REGISTER 1322
#define RELATIVE 1323
#define RESOURCE 1324
#define SMALLINT 1325
#define VALIDATE 1326
#define WHENEVER 1327
#define WITH_LOG 1328
#define WORDWRAP 1329
#define BY_NAME 1330
#define IN_FILE 1331
#define IS_NULL 1332
#define AVERAGE 1334
#define BETWEEN 1335
#define CAPTION 1336
#define CLIPPED 1337
#define CLOSE_BRACKET 1338
#define COLUMNS 1339
#define COMMENT 1341
#define CONNECT 1342
#define CURRENT 1343
#define DBYNAME 1344
#define DECIMAL 1345
#define DECLARE 1346
#define DEFAULT 1347
#define DISPLAY 1348
#define ENDCODE 1349
#define EXECUTE 1350
#define FOREACH 1351
#define FOREIGN 1352
#define GLOBALS 1353
#define INFIELD 1354
#define INTEGER 1355
#define KWWINDOW 1356
#define MAGENTA 1357
#define NUMERIC 1359
#define OPTIONS 1360
#define PERCENT 1361
#define PREPARE 1362
#define PROGRAM 1363
#define RECOVER 1364
#define REVERSE 1365
#define SECTION 1366
#define SESSION 1367
#define SYNONYM 1368
#define THRU 1369
#define TRAILER 1370
#define UPSHIFT 1371
#define VARCHAR 1372
#define WAITING 1373
#define CLOSE_SHEV 1374
#define CLOSE_SQUARE 1375
#define KW_FALSE 1377
#define NOT_IN 1378
#define ONKEY 1379
#define OPEN_BRACKET 1380
#define BORDER 1381
#define BOTTOM 1382
#define COLUMN 1383
#define COMMIT 1384
#define CREATE 1385
#define CURSOR 1386
#define DEFINE 1387
#define DELETE 1388
#define DOUBLE 1389
#define END_IF 1390
#define ESCAPE 1391
#define EXISTS 1392
#define EXTEND 1393
#define EXTENT 1394
#define FINISH 1395
#define FORMAT 1396
#define HAVING 1397
#define HEADER 1398
#define INSERT 1399
#define LOCATE 1400
#define MARGIN 1401
#define MEMORY 1402
#define MINUTE 1403
#define MODIFY 1404
#define NORMAL 1405
#define EQUAL_EQUAL 1406
#define OPEN_SHEV 1408
#define OPEN_SQUARE 1409
#define OPTION 1410
#define OUTPUT 1411
#define PROMPT 1412
#define PUBLIC 1413
#define RECORD 1414
#define REPORT 1415
#define RETURN 1416
#define REVOKE 1417
#define SCHEMA 1418
#define SCROLL_USING 1419
#define SCROLL 1420
#define SECOND 1421
#define SELECT 1422
#define SERIAL 1423
#define SETL 1424
#define SHARED 1425
#define SPACES 1426
#define UNIQUE 1427
#define UNLOCK 1428
#define UPDATE 1429
#define VALUES 1430
#define YELLOW 1431
#define AFTER 1432
#define KWLINE 1433
#define KW_NULL 1434
#define KW_TRUE 1435
#define SINGLE_KEY 1436
#define ALTER 1437
#define ARRAY 1438
#define ASCII 1439
#define AUDIT 1440
#define BLACK 1441
#define BLINK 1442
#define CHECK 1443
#define CLEAR 1444
#define CLOSE 1445
#define CODE_C 1446
#define COUNT 1447
#define DEFER 1448
#define ERROR 1449
#define EVERY 1450
#define FETCH 1451
#define FIRST 1452
#define FLOAT 1453
#define FLUSH 1454
#define FOUND 1455
#define GRANT 1456
#define GREEN 1457
#define GROUP 1458
#define INDEX 1459
#define KWFORM 1460
#define LABEL 1461
#define LOCAL 1463
#define MONEY 1464
#define MONTH 1465
#define ORDER 1468
#define OUTER 1469
#define PAUSE 1470
#define PRINT_IMAGE 1471
#define PRINT_FILE 1472
#define PRINT 1473
#define RIGHT 1474
#define DOUBLE_COLON 1475
#define SEMICOLON 1476
#define SLEEP 1477
#define TUPLE 1478
#define UNION 1479
#define WHERE 1481
#define WHILE 1482
#define WHITE 1483
#define CCODE 1484
#define ANSI 1485
#define BLUE 1486
#define BOLD 1487
#define BYTE 1488
#define FCALL 1489
#define CASE 1490
#define CHAR 1491
#define CYAN 1492
#define DATE 1493
#define DESC 1494
#define DOWN 1496
#define TAB 1497
#define DROP 1498
#define ELSE 1499
#define EXEC 1500
#define EXIT 1501
#define FREE 1502
#define FROM 1503
#define GOTO 1504
#define HELP_FILE 1505
#define LANG_FILE 1506
#define HELP 1507
#define HIDE 1508
#define HOUR 1509
#define INTO 1510
#define LAST 1511
#define LEFT 1512
#define LIKE 1513
#define MAIN 1514
#define MENU 1515
#define MODE 1516
#define NEED 1517
#define NEXT 1518
#define NOCR 1519
#define OPEN 1520
#define QUIT 1521
#define REAL 1522
#define ROWS 1523
#define SHOW 1524
#define SIZE 1525
#define SKIP 1526
#define SOME 1527
#define STEP 1528
#define STOP 1529
#define TEMP 1530
#define TEXT 1531
#define THEN 1532
#define USER 1533
#define WAIT 1534
#define WHEN 1535
#define WITH 1536
#define WORK 1537
#define YEAR 1538
#define KW_IS 1540
#define XSET 1541
#define ADD 1542
#define ALL 1543
#define ANY 1545
#define ASC 1546
#define AVG 1547
#define COLON 1548
#define DAY 1550
#define DBA 1551
#define DEC 1552
#define DIM 1553
#define FKEY 1554
#define FOR 1555
#define KEY 1556
#define KWNO 1557
#define LET 1558
#define LOG 1559
#define XMAX 1560
#define XMIN 1561
#define NOT 1564
#define PAD 1565
#define PUT 1566
#define RED 1567
#define ROW 1568
#define RUN 1569
#define SQL 1570
#define SUM 1571
#define TOP 1572
#define USE 1573
#define ATSIGN 1574
#define AS_TIFF 1576
#define AS_GIF 1577
#define AS_PNG 1578
#define AS_JPEG 1579
#define AS 1580
#define AT 1581
#define BY 1582
#define DOT 1583
#define GO 1584
#define IF 1585
#define IN 1586
#define OF 1587
#define ON 1588
#define TO 1590
#define UP 1591
#define FONT_NAME 1592
#define FONT_SIZE 1593
#define PAPER_SIZE_IS_LETTER 1594
#define PAPER_SIZE_IS_LEGAL 1595
#define PAPER_SIZE_IS_A5 1596
#define PAPER_SIZE_IS_A4 1597
#define PAPER_SIZE_IS_LETTER_L 1598
#define PAPER_SIZE_IS_LEGAL_L 1599
#define PAPER_SIZE_IS_A5_L 1600
#define PAPER_SIZE_IS_A4_L 1601
#define FORMHANDLER 1602
#define END_FORMHANDLER 1603
#define BEFORE_EVENT 1604
#define BEFORE_OPEN_FORM 1605
#define AFTER_EVENT 1606
#define BEFORE_CLOSE_FORM 1607
#define BEFORE_ANY 1608
#define AFTER_ANY 1609
#define MENUHANDLER 1610
#define END_MENUHANDLER 1611
#define BEFORE_SHOW_MENU 1612
#define DISABLE_PROGRAM 1613
#define DISABLE_ALL 1614
#define BUTTONS 1615
#define CHECK_MENUITEM 1616
#define DISABLE_FORM 1617
#define DISABLE_MENUITEMS 1618
#define DISABLE 1619
#define ENABLE_FORM 1620
#define ENABLE_MENUITEMS 1621
#define ENABLE 1622
#define KWFIELD 1623
#define ICON 1624
#define MESSAGEBOX 1625
#define TO_DEFAULTS 1626
#define UNCHECK_MENUITEM 1627
#define BEFORE 1628
#define INPUT 1629
#define END 1630
#define INT_TO_ID 1631




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
#line 189 "fgl.yacc"
typedef union YYSTYPE {



	//char	str[3100];  /* This would core dump in CygWin on call to */
	char	str[1024];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1510 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1522 "y.tab.c"

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   8564

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  647
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  819
/* YYNRULES -- Number of rules. */
#define YYNRULES  1885
/* YYNRULES -- Number of states. */
#define YYNSTATES  3092

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1644

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
     303,   304,   305,   306,   307,    14,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,    15,   365,   366,   367,   368,   369,   370,
      22,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,     9,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,    12,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,    16,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,    11,   489,   490,   491,    10,    20,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
       8,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,    19,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,    13,
     561,   562,   563,   564,     7,   565,   566,   567,   568,     5,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,    18,    21,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,    17,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,     6,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,     2,     3,     4,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32
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
     149,   152,   155,   159,   160,   168,   173,   180,   182,   189,
     190,   191,   201,   202,   203,   204,   213,   214,   215,   226,
     227,   228,   238,   239,   240,   241,   256,   257,   260,   261,
     264,   266,   267,   269,   271,   275,   277,   279,   281,   283,
     287,   288,   295,   296,   302,   304,   307,   309,   312,   314,
     315,   316,   320,   321,   322,   326,   327,   332,   333,   338,
     341,   344,   347,   349,   352,   355,   359,   361,   363,   365,
     368,   370,   372,   375,   377,   379,   380,   381,   387,   395,
     404,   405,   408,   410,   414,   416,   420,   424,   426,   429,
     430,   435,   436,   441,   442,   446,   447,   451,   452,   456,
     458,   462,   464,   468,   470,   472,   474,   476,   478,   480,
     485,   486,   491,   493,   495,   496,   498,   500,   503,   504,
     505,   511,   513,   515,   517,   521,   522,   525,   530,   535,
     540,   545,   548,   549,   554,   556,   558,   560,   563,   565,
     567,   571,   572,   574,   575,   583,   584,   597,   599,   601,
     603,   605,   607,   613,   617,   619,   621,   622,   627,   628,
     634,   635,   643,   645,   649,   651,   653,   654,   656,   657,
     658,   663,   665,   667,   669,   674,   679,   686,   688,   691,
     693,   695,   697,   699,   704,   711,   713,   718,   725,   727,
     729,   731,   733,   735,   737,   739,   742,   745,   747,   749,
     754,   756,   758,   759,   763,   767,   768,   771,   773,   775,
     777,   779,   781,   783,   786,   787,   790,   791,   795,   796,
     800,   802,   803,   807,   809,   811,   813,   815,   817,   819,
     822,   824,   825,   827,   828,   834,   836,   838,   840,   845,
     850,   857,   859,   861,   863,   865,   870,   877,   879,   884,
     891,   893,   895,   897,   899,   901,   904,   907,   909,   914,
     915,   923,   924,   937,   938,   943,   944,   950,   952,   956,
     959,   961,   965,   967,   968,   971,   974,   976,   979,   985,
     990,   993,   998,  1004,  1008,  1009,  1010,  1022,  1023,  1026,
    1028,  1029,  1032,  1034,  1037,  1038,  1042,  1043,  1047,  1048,
    1052,  1057,  1063,  1065,  1068,  1070,  1072,  1074,  1076,  1078,
    1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,  1098,
    1100,  1102,  1104,  1106,  1108,  1110,  1113,  1115,  1117,  1119,
    1122,  1125,  1127,  1129,  1131,  1133,  1135,  1137,  1139,  1141,
    1143,  1145,  1147,  1150,  1152,  1154,  1156,  1160,  1162,  1166,
    1168,  1172,  1174,  1176,  1178,  1181,  1183,  1185,  1189,  1194,
    1199,  1202,  1205,  1207,  1209,  1211,  1213,  1215,  1219,  1221,
    1224,  1227,  1229,  1230,  1234,  1237,  1240,  1242,  1246,  1251,
    1256,  1262,  1268,  1270,  1272,  1275,  1278,  1283,  1288,  1291,
    1294,  1299,  1304,  1306,  1309,  1312,  1315,  1318,  1321,  1324,
    1327,  1330,  1333,  1336,  1339,  1342,  1345,  1348,  1349,  1350,
    1351,  1358,  1359,  1360,  1369,  1370,  1371,  1378,  1379,  1380,
    1387,  1388,  1389,  1396,  1397,  1398,  1405,  1411,  1417,  1423,
    1431,  1432,  1436,  1438,  1440,  1445,  1450,  1455,  1460,  1465,
    1470,  1472,  1474,  1476,  1478,  1483,  1488,  1491,  1494,  1497,
    1500,  1503,  1505,  1507,  1510,  1512,  1514,  1516,  1519,  1524,
    1531,  1538,  1542,  1548,  1554,  1558,  1560,  1562,  1566,  1567,
    1568,  1569,  1578,  1579,  1580,  1591,  1592,  1594,  1595,  1597,
    1599,  1602,  1603,  1607,  1608,  1612,  1613,  1615,  1617,  1620,
    1621,  1625,  1626,  1630,  1634,  1636,  1641,  1645,  1647,  1651,
    1653,  1657,  1659,  1663,  1665,  1668,  1669,  1673,  1674,  1678,
    1679,  1684,  1685,  1690,  1691,  1696,  1697,  1698,  1710,  1711,
    1714,  1717,  1721,  1723,  1727,  1729,  1731,  1733,  1735,  1737,
    1739,  1743,  1745,  1747,  1752,  1759,  1764,  1768,  1775,  1779,
    1786,  1788,  1790,  1792,  1794,  1796,  1798,  1799,  1802,  1806,
    1810,  1812,  1817,  1819,  1821,  1822,  1823,  1825,  1830,  1834,
    1841,  1845,  1852,  1854,  1856,  1859,  1861,  1863,  1865,  1867,
    1869,  1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,
    1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,
    1909,  1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,
    1929,  1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1948,
    1951,  1953,  1957,  1959,  1962,  1965,  1968,  1973,  1976,  1979,
    1984,  1985,  1994,  1995,  1997,  1999,  2001,  2002,  2004,  2007,
    2008,  2010,  2013,  2014,  2016,  2019,  2020,  2022,  2026,  2027,
    2030,  2031,  2039,  2040,  2041,  2045,  2046,  2047,  2055,  2061,
    2064,  2065,  2071,  2076,  2078,  2082,  2086,  2090,  2091,  2094,
    2095,  2097,  2099,  2102,  2103,  2108,  2109,  2114,  2115,  2119,
    2120,  2124,  2125,  2129,  2130,  2134,  2135,  2139,  2140,  2145,
    2146,  2151,  2153,  2157,  2159,  2161,  2163,  2167,  2169,  2171,
    2173,  2177,  2179,  2183,  2186,  2191,  2193,  2195,  2197,  2198,
    2203,  2209,  2216,  2217,  2228,  2232,  2234,  2236,  2239,  2242,
    2243,  2246,  2247,  2251,  2253,  2254,  2258,  2261,  2262,  2266,
    2268,  2272,  2274,  2278,  2279,  2282,  2284,  2286,  2288,  2290,
    2292,  2294,  2296,  2298,  2300,  2302,  2304,  2306,  2308,  2310,
    2312,  2314,  2316,  2318,  2319,  2320,  2328,  2330,  2332,  2335,
    2338,  2341,  2345,  2350,  2351,  2355,  2356,  2358,  2360,  2363,
    2365,  2367,  2369,  2371,  2372,  2374,  2376,  2379,  2382,  2384,
    2386,  2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,  2404,
    2406,  2408,  2409,  2411,  2413,  2415,  2417,  2419,  2420,  2421,
    2422,  2423,  2437,  2439,  2440,  2441,  2448,  2451,  2453,  2456,
    2459,  2461,  2463,  2466,  2468,  2470,  2472,  2473,  2477,  2480,
    2482,  2483,  2484,  2485,  2500,  2501,  2502,  2510,  2512,  2515,
    2516,  2520,  2521,  2526,  2527,  2533,  2535,  2536,  2540,  2541,
    2549,  2550,  2556,  2558,  2561,  2562,  2564,  2566,  2568,  2569,
    2571,  2573,  2576,  2579,  2582,  2584,  2586,  2588,  2590,  2594,
    2596,  2598,  2601,  2602,  2605,  2607,  2609,  2611,  2613,  2615,
    2617,  2619,  2620,  2624,  2625,  2627,  2629,  2631,  2633,  2636,
    2640,  2643,  2649,  2651,  2653,  2655,  2660,  2665,  2667,  2669,
    2671,  2673,  2676,  2680,  2687,  2689,  2693,  2695,  2697,  2699,
    2704,  2712,  2714,  2716,  2718,  2720,  2723,  2724,  2726,  2728,
    2732,  2734,  2738,  2740,  2744,  2746,  2750,  2752,  2754,  2756,
    2758,  2762,  2764,  2768,  2770,  2774,  2776,  2778,  2780,  2784,
    2787,  2788,  2790,  2792,  2797,  2799,  2803,  2805,  2809,  2817,
    2818,  2826,  2827,  2834,  2838,  2840,  2844,  2846,  2849,  2855,
    2856,  2864,  2865,  2868,  2869,  2871,  2877,  2880,  2886,  2887,
    2893,  2900,  2905,  2906,  2908,  2910,  2915,  2916,  2919,  2920,
    2926,  2931,  2934,  2936,  2940,  2943,  2946,  2949,  2952,  2955,
    2958,  2960,  2963,  2966,  2969,  2972,  2975,  2978,  2981,  2984,
    2987,  2989,  2991,  2993,  2995,  2997,  2999,  3005,  3007,  3009,
    3012,  3017,  3019,  3020,  3031,  3037,  3038,  3040,  3041,  3044,
    3046,  3049,  3050,  3054,  3056,  3057,  3062,  3063,  3066,  3068,
    3072,  3074,  3076,  3080,  3085,  3090,  3093,  3095,  3097,  3099,
    3100,  3102,  3110,  3113,  3116,  3119,  3122,  3124,  3127,  3128,
    3132,  3133,  3137,  3138,  3142,  3143,  3147,  3148,  3152,  3153,
    3158,  3159,  3164,  3166,  3168,  3170,  3172,  3174,  3176,  3177,
    3182,  3183,  3185,  3186,  3191,  3193,  3196,  3199,  3202,  3203,
    3205,  3207,  3210,  3213,  3214,  3217,  3221,  3225,  3231,  3232,
    3235,  3240,  3242,  3244,  3246,  3248,  3250,  3251,  3253,  3255,
    3259,  3262,  3268,  3271,  3277,  3283,  3289,  3295,  3301,  3307,
    3308,  3311,  3313,  3316,  3319,  3322,  3325,  3328,  3331,  3333,
    3336,  3339,  3342,  3345,  3347,  3350,  3353,  3356,  3359,  3361,
    3363,  3365,  3366,  3369,  3372,  3375,  3378,  3381,  3384,  3387,
    3390,  3393,  3395,  3397,  3399,  3401,  3403,  3405,  3407,  3409,
    3412,  3415,  3418,  3421,  3424,  3426,  3428,  3430,  3431,  3435,
    3438,  3439,  3440,  3441,  3442,  3443,  3444,  3460,  3461,  3464,
    3467,  3468,  3470,  3471,  3472,  3473,  3474,  3475,  3476,  3492,
    3495,  3496,  3497,  3498,  3509,  3510,  3512,  3516,  3520,  3523,
    3528,  3532,  3536,  3540,  3542,  3544,  3546,  3548,  3550,  3552,
    3553,  3554,  3562,  3563,  3564,  3573,  3577,  3580,  3581,  3583,
    3585,  3589,  3592,  3595,  3597,  3599,  3603,  3605,  3607,  3610,
    3612,  3616,  3618,  3622,  3624,  3626,  3628,  3630,  3632,  3634,
    3636,  3639,  3644,  3646,  3650,  3652,  3656,  3659,  3664,  3666,
    3670,  3672,  3675,  3680,  3682,  3686,  3688,  3690,  3692,  3695,
    3698,  3703,  3706,  3711,  3713,  3717,  3719,  3721,  3723,  3726,
    3728,  3730,  3732,  3734,  3736,  3739,  3746,  3753,  3754,  3756,
    3757,  3759,  3762,  3763,  3764,  3772,  3773,  3776,  3779,  3787,
    3789,  3795,  3799,  3801,  3805,  3807,  3811,  3813,  3817,  3819,
    3823,  3825,  3827,  3829,  3830,  3836,  3837,  3843,  3845,  3846,
    3850,  3852,  3856,  3858,  3862,  3864,  3866,  3867,  3868,  3874,
    3877,  3879,  3880,  3881,  3885,  3886,  3887,  3891,  3893,  3895,
    3897,  3899,  3901,  3903,  3906,  3909,  3914,  3918,  3922,  3924,
    3928,  3931,  3933,  3935,  3936,  3938,  3940,  3942,  3944,  3945,
    3947,  3951,  3952,  3956,  3958,  3960,  3962,  3964,  3966,  3968,
    3970,  3972,  3974,  3976,  3978,  3980,  3988,  3989,  3991,  3993,
    3995,  3997,  4001,  4003,  4005,  4007,  4010,  4011,  4015,  4017,
    4021,  4023,  4027,  4029,  4031,  4038,  4039,  4043,  4045,  4049,
    4050,  4052,  4057,  4063,  4066,  4068,  4070,  4075,  4077,  4081,
    4086,  4091,  4093,  4097,  4099,  4101,  4103,  4106,  4108,  4113,
    4114,  4116,  4117,  4119,  4121,  4124,  4126,  4128,  4130,  4135,
    4139,  4141,  4143,  4145,  4148,  4150,  4152,  4155,  4158,  4160,
    4164,  4167,  4170,  4172,  4176,  4178,  4181,  4186,  4188,  4191,
    4193,  4197,  4202,  4203,  4205,  4206,  4208,  4209,  4211,  4213,
    4217,  4219,  4223,  4225,  4228,  4230,  4234,  4237,  4240,  4241,
    4244,  4246,  4248,  4254,  4258,  4264,  4268,  4270,  4274,  4276,
    4278,  4279,  4281,  4285,  4289,  4293,  4300,  4306,  4312,  4314,
    4316,  4318,  4320,  4322,  4324,  4326,  4328,  4330,  4332,  4334,
    4335,  4337,  4339,  4341,  4343,  4345,  4347,  4349,  4354,  4360,
    4362,  4368,  4374,  4376,  4378,  4380,  4385,  4387,  4392,  4394,
    4402,  4404,  4406,  4408,  4413,  4420,  4421,  4424,  4429,  4431,
    4433,  4435,  4437,  4439,  4441,  4443,  4447,  4449,  4451,  4455,
    4457,  4458,  4462,  4468,  4471,  4477,  4482,  4484,  4486,  4488,
    4490,  4492,  4495,  4498,  4501,  4504,  4506,  4509,  4512,  4513,
    4517,  4518,  4522,  4524,  4526,  4528,  4530,  4532,  4534,  4536,
    4541,  4543,  4545,  4547,  4549,  4551,  4553,  4555,  4560,  4562,
    4564,  4566,  4568,  4570,  4572,  4574,  4576,  4578,  4580,  4582,
    4584,  4586,  4588,  4590,  4592,  4596,  4597,  4606,  4607,  4617,
    4618,  4626,  4627,  4637,  4638,  4640,  4643,  4645,  4649,  4651,
    4655,  4661,  4663,  4665,  4667,  4669,  4672,  4673,  4674,  4683,
    4689,  4691,  4693,  4701,  4702,  4706,  4708,  4712,  4717,  4719,
    4720,  4723,  4729,  4737,  4738,  4740,  4742,  4744,  4746,  4750,
    4752,  4755,  4758,  4760,  4762,  4764,  4766,  4770,  4773,  4777,
    4781,  4785,  4787,  4789,  4791,  4793,  4795,  4797,  4803,  4809,
    4815,  4821,  4827,  4832,  4837,  4841,  4846,  4848,  4852,  4853,
    4855,  4861,  4869,  4875,  4876,  4879,  4881,  4883,  4884,  4888,
    4890,  4894,  4896,  4898,  4900,  4901,  4905,  4907,  4909,  4911,
    4913,  4918,  4925,  4927,  4929,  4932,  4936,  4938,  4940,  4942,
    4944,  4946,  4948,  4950,  4952,  4958,  4964,  4969,  4970,  4975,
    4977,  4980,  4982,  4984,  4986,  4989,  4992,  4994,  4997,  4999,
    5001,  5003,  5007,  5013,  5015,  5017,  5019,  5021,  5025,  5028,
    5031,  5034,  5036,  5039,  5042,  5045,  5048,  5051,  5053,  5057,
    5060,  5062,  5065,  5067,  5070,  5072,  5073,  5074,  5081,  5082,
    5085,  5086,  5088,  5090,  5093,  5096,  5098,  5100,  5105,  5109,
    5111,  5115,  5117,  5120,  5126,  5129,  5132,  5138,  5139,  5142,
    5144,  5146,  5149,  5156,  5163,  5165,  5166,  5168,  5171,  5173,
    5176,  5177,  5180,  5182,  5184,  5186,  5188,  5190,  5192,  5194,
    5196,  5198,  5200,  5202,  5204,  5206,  5208,  5210,  5212,  5214,
    5216,  5218,  5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,
    5236,  5238,  5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,
    5256,  5258,  5260,  5262,  5264,  5266,  5268,  5270,  5272,  5274,
    5276,  5278,  5280,  5282,  5284,  5286,  5288,  5290,  5292,  5294,
    5296,  5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,  5314,
    5316,  5318,  5320,  5322,  5324,  5326,  5328,  5330,  5332,  5334,
    5336,  5338,  5340,  5342,  5344,  5346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1007,     0,    -1,   178,    -1,   175,    -1,   102,   652,   404,
     574,   653,    -1,   116,    -1,  1073,    -1,    25,    -1,   654,
      -1,   653,     5,   654,    -1,   915,    -1,   408,   655,   369,
      -1,   655,   656,   655,    -1,    25,    -1,   657,    25,    -1,
    1073,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   659,    -1,    -1,
     252,   408,   660,   661,   369,    -1,   547,   408,    25,     5,
      25,   369,    -1,   662,    -1,   661,     5,   662,    -1,   468,
      -1,   509,    -1,   515,    -1,   484,    -1,   387,    -1,   584,
      -1,   506,    -1,   458,    -1,   394,    -1,   469,    -1,   323,
      -1,   510,    -1,   433,    -1,   310,    -1,   572,    -1,    76,
      -1,    -1,   664,    -1,    -1,   252,   408,   665,   666,   369,
      -1,   667,    -1,   666,     5,   667,    -1,   662,    -1,   409,
      -1,   582,    24,    -1,   181,   902,    -1,   307,   902,    -1,
     262,   902,    -1,   315,   902,    -1,   271,   902,    -1,   237,
     902,    -1,   512,   669,    -1,   848,   322,  1073,    -1,    -1,
     267,   408,  1450,   369,   322,   670,  1091,    -1,    82,   408,
     915,   369,    -1,   384,   408,   907,   369,   322,  1073,    -1,
    1208,    -1,   170,   408,   907,   369,   322,  1073,    -1,    -1,
      -1,  1073,   568,   915,   408,   671,   685,   369,   672,   683,
      -1,    -1,    -1,    -1,   915,   408,   673,   685,   674,   369,
     675,   683,    -1,    -1,    -1,   452,  1413,   602,  1413,   408,
     676,   685,   677,   369,   683,    -1,    -1,    -1,   915,   499,
     915,   408,   678,   685,   679,   369,   683,    -1,    -1,    -1,
      -1,   343,   688,   568,   689,   436,   652,   404,   408,   680,
     685,   681,   369,   682,   684,    -1,    -1,   322,  1091,    -1,
      -1,   322,  1091,    -1,   140,    -1,    -1,   686,    -1,   687,
      -1,   686,     5,   687,    -1,   817,    -1,    24,    -1,   915,
      -1,   915,    -1,   915,   599,   915,    -1,    -1,   513,   824,
     691,   694,   698,   695,    -1,    -1,   513,   692,   693,   696,
     695,    -1,   700,    -1,   693,   700,    -1,   702,    -1,   694,
     702,    -1,   338,    -1,    -1,    -1,   317,   697,  1460,    -1,
      -1,    -1,   317,   699,  1460,    -1,    -1,   557,   824,   701,
    1460,    -1,    -1,   557,   824,   703,  1460,    -1,   256,   912,
      -1,   180,   910,    -1,    61,   910,    -1,   147,    -1,   163,
    1419,    -1,   472,   909,    -1,    29,   706,    30,    -1,   707,
      -1,   709,    -1,   708,    -1,   707,   708,    -1,    28,    -1,
     710,    -1,   709,   710,    -1,    27,    -1,   371,    -1,    -1,
      -1,   298,   713,   715,   714,   716,    -1,   362,  1073,   604,
     717,   958,   985,   658,    -1,  1073,   604,   717,   958,   525,
    1450,   985,   658,    -1,    -1,   719,   169,    -1,   718,    -1,
     717,     5,   718,    -1,   915,    -1,   915,   599,   915,    -1,
     915,   599,    20,    -1,   720,    -1,   719,   720,    -1,    -1,
     248,   726,   721,  1460,    -1,    -1,   251,   727,   722,  1460,
      -1,    -1,   986,   723,  1460,    -1,    -1,   145,   724,  1460,
      -1,    -1,   141,   725,  1460,    -1,   921,    -1,   726,     5,
     921,    -1,   921,    -1,   727,     5,   921,    -1,    70,    -1,
      71,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
     408,   817,   730,   369,    -1,    -1,     5,   771,   605,   774,
      -1,   133,    -1,   257,    -1,    -1,   733,    -1,   734,    -1,
     733,   734,    -1,    -1,    -1,   415,   735,   737,   736,  1177,
      -1,   784,    -1,  1440,    -1,   740,    -1,   737,     5,   740,
      -1,    -1,   739,   915,    -1,   331,   738,   783,    24,    -1,
     331,   738,   783,   915,    -1,   331,   738,   783,   923,    -1,
     331,   738,   783,    25,    -1,   744,   760,    -1,    -1,   738,
     331,   741,   742,    -1,    25,    -1,    24,    -1,   923,    -1,
      18,    25,    -1,   738,    -1,   743,    -1,   744,     5,   743,
      -1,    -1,   514,    -1,    -1,   465,   436,   752,   404,   747,
     603,   760,    -1,    -1,   296,   745,   749,    25,   750,   280,
     436,   751,   404,   748,   603,   760,    -1,   408,    -1,   435,
      -1,   369,    -1,   403,    -1,    25,    -1,   753,     5,   753,
       5,   753,    -1,   753,     5,   753,    -1,   753,    -1,    25,
      -1,    -1,   441,   755,   737,   261,    -1,    -1,   238,   756,
     738,   599,    20,    -1,    -1,   312,   757,   738,   236,   408,
     758,   369,    -1,   759,    -1,   758,     5,   759,    -1,   738,
      -1,   762,    -1,    -1,    37,    -1,    -1,    -1,   763,   765,
     764,   761,    -1,   746,    -1,   754,    -1,   514,    -1,   514,
     408,    25,   369,    -1,   401,   408,    25,   369,    -1,   401,
     408,    25,     5,    25,   369,    -1,   385,    -1,   596,   738,
      -1,   357,    -1,   487,    -1,    67,    -1,   375,    -1,   375,
     408,    25,   369,    -1,   375,   408,    25,     5,    25,   369,
      -1,   490,    -1,   490,   408,    25,   369,    -1,   490,   408,
      25,     5,    25,   369,    -1,   480,    -1,   277,    -1,   516,
      -1,   511,    -1,    58,    -1,    59,    -1,   553,    -1,   335,
     769,    -1,   347,   770,    -1,   766,    -1,    31,    -1,   535,
     767,   599,   768,    -1,   738,    -1,   738,    -1,    -1,   771,
     605,   774,    -1,   779,   605,   782,    -1,    -1,   772,   773,
      -1,   560,    -1,   491,    -1,   569,    -1,   531,    -1,   431,
      -1,   448,    -1,   344,   776,    -1,    -1,   775,   773,    -1,
      -1,   408,   778,   369,    -1,    -1,   408,    25,   369,    -1,
      25,    -1,    -1,   780,   781,   777,    -1,   560,    -1,   491,
      -1,   569,    -1,   531,    -1,   431,    -1,   448,    -1,   344,
     776,    -1,   781,    -1,    -1,    13,    -1,    -1,   214,   915,
     785,   596,   786,    -1,   788,    -1,   791,    -1,   514,    -1,
     514,   408,    25,   369,    -1,   401,   408,    25,   369,    -1,
     401,   408,    25,     5,    25,   369,    -1,   385,    -1,   357,
      -1,   487,    -1,   375,    -1,   375,   408,    25,   369,    -1,
     375,   408,    25,     5,    25,   369,    -1,   490,    -1,   490,
     408,    25,   369,    -1,   490,   408,    25,     5,    25,   369,
      -1,   480,    -1,   277,    -1,   516,    -1,   511,    -1,   553,
      -1,   335,   769,    -1,   347,   770,    -1,   787,    -1,   535,
     767,   599,   768,    -1,    -1,   465,   436,   752,   404,   789,
     603,   786,    -1,    -1,   296,   745,   749,    25,   750,   280,
     436,   751,   404,   790,   603,   786,    -1,    -1,   441,   792,
     794,   261,    -1,    -1,   238,   793,   915,   599,    20,    -1,
     795,    -1,   794,     5,   795,    -1,   796,   786,    -1,   797,
      -1,   796,     5,   797,    -1,   915,    -1,    -1,   597,   906,
      -1,    48,   915,    -1,    46,    -1,   605,  1450,    -1,   605,
     487,   915,   638,  1450,    -1,   605,   487,   915,   367,    -1,
      50,   915,    -1,   134,   842,  1091,   806,    -1,   378,   842,
     822,   798,   806,    -1,   187,   912,   806,    -1,    -1,    -1,
     166,   803,  1098,   605,   915,   599,    20,   805,   658,   804,
     807,    -1,    -1,   446,   907,    -1,   658,    -1,    -1,   808,
     216,    -1,   809,    -1,   808,   809,    -1,    -1,   329,   810,
    1460,    -1,    -1,   325,   811,  1460,    -1,    -1,   986,   812,
    1460,    -1,   476,   842,   823,   658,    -1,   476,   842,   823,
     658,    44,    -1,   191,    -1,   191,   824,    -1,   264,    -1,
     263,    -1,   190,    -1,   342,    -1,   152,    -1,   189,    -1,
     306,    -1,   305,    -1,   221,    -1,   149,    -1,   148,    -1,
     122,    -1,   182,    -1,   105,    -1,   121,    -1,   165,    -1,
     131,    -1,   827,    -1,   826,    -1,   831,    -1,   859,    -1,
     817,   818,    -1,   860,    -1,   862,    -1,   828,    -1,    18,
     817,    -1,    17,   817,    -1,   833,    -1,   841,    -1,   835,
      -1,   453,    -1,   728,    -1,   836,    -1,   837,    -1,   838,
      -1,   839,    -1,   840,    -1,   842,    -1,   842,   821,    -1,
     824,    -1,   461,    -1,   820,    -1,   821,     5,   820,    -1,
     824,    -1,   822,     5,   824,    -1,   824,    -1,   823,     5,
     824,    -1,   817,    -1,    17,    -1,    18,    -1,   581,   817,
      -1,   462,    -1,   405,    -1,   408,   817,   369,    -1,   420,
     408,  1394,   369,    -1,   272,   408,  1394,   369,    -1,   825,
     923,    -1,   825,    25,    -1,    24,    -1,   923,    -1,    25,
      -1,   830,    -1,  1073,    -1,  1073,   398,  1073,    -1,   829,
      -1,   411,   817,    -1,   370,   817,    -1,  1180,    -1,    -1,
     485,   832,  1180,    -1,     7,   817,    -1,     6,   817,    -1,
     817,    -1,   834,     5,   817,    -1,   602,   408,  1394,   369,
      -1,   406,   408,  1394,   369,    -1,   602,   408,   842,   834,
     369,    -1,   406,   408,   842,   834,   369,    -1,   364,    -1,
     227,    -1,     9,   817,    -1,   230,   817,    -1,     9,   817,
     419,    24,    -1,   230,   817,   419,    24,    -1,   535,   817,
      -1,   349,   817,    -1,   535,   817,   419,    24,    -1,   349,
     817,   419,    24,    -1,   368,    -1,     8,   817,    -1,    17,
     817,    -1,    18,   817,    -1,    20,   817,    -1,    19,   817,
      -1,    21,   817,    -1,    10,   817,    -1,    13,   817,    -1,
     434,   817,    -1,    11,   817,    -1,    12,   817,    -1,    16,
     817,    -1,    15,   817,    -1,    14,   817,    -1,    -1,    -1,
      -1,   915,   408,   844,   685,   845,   369,    -1,    -1,    -1,
     915,   499,   915,   408,   846,   685,   847,   369,    -1,    -1,
      -1,   516,   408,   849,   817,   850,   369,    -1,    -1,    -1,
     491,   408,   851,   817,   852,   369,    -1,    -1,    -1,   569,
     408,   853,   817,   854,   369,    -1,    -1,    -1,   560,   408,
     855,   817,   856,   369,    -1,   347,   408,   863,   369,   858,
      -1,   335,   408,    24,   369,   857,    -1,   335,   408,    25,
     369,   857,    -1,   335,   408,    25,   568,    25,   369,   857,
      -1,    -1,  1374,   605,  1375,    -1,   770,    -1,   848,    -1,
     267,   408,  1450,   369,    -1,    77,   408,   907,   369,    -1,
      49,   408,   907,   369,    -1,   384,   408,   907,   369,    -1,
     170,   408,   907,   369,    -1,    38,   408,   907,   369,    -1,
     861,    -1,   843,    -1,  1370,    -1,   516,    -1,   400,   408,
     817,   369,    -1,   300,   408,   817,   369,    -1,   466,   817,
      -1,   421,   729,    -1,   817,    86,    -1,   817,    87,    -1,
     817,    88,    -1,    24,    -1,   864,    -1,    18,   864,    -1,
     866,    -1,   865,    -1,    25,    -1,    25,    25,    -1,    25,
      25,   568,    25,    -1,    25,    25,   568,    25,   568,    25,
      -1,    25,    25,   568,    25,   568,    23,    -1,    25,   568,
      25,    -1,    25,   568,    25,   568,    25,    -1,    25,   568,
      25,   568,    23,    -1,    25,   568,    23,    -1,    23,    -1,
      25,    -1,    25,    18,    25,    -1,    -1,    -1,    -1,   381,
     868,   909,   869,  1277,   870,  1460,   218,    -1,    -1,    -1,
     617,   915,   872,   732,   873,  1017,   875,   874,   880,   618,
      -1,    -1,   885,    -1,    -1,   876,    -1,   877,    -1,   876,
     877,    -1,    -1,   619,   878,  1460,    -1,    -1,   620,   879,
    1460,    -1,    -1,   881,    -1,   882,    -1,   881,   882,    -1,
      -1,   621,   883,  1460,    -1,    -1,   622,   884,  1460,    -1,
     886,   890,   302,    -1,    69,    -1,    69,   887,   525,   888,
      -1,    69,   362,   889,    -1,  1073,    -1,   887,     5,  1073,
      -1,   915,    -1,   888,     5,   915,    -1,  1073,    -1,   889,
       5,  1073,    -1,   891,    -1,   890,   891,    -1,    -1,   623,
     892,  1460,    -1,    -1,   624,   893,  1460,    -1,    -1,   643,
     888,   894,  1460,    -1,    -1,   459,   888,   895,  1460,    -1,
      -1,   604,   888,   896,  1460,    -1,    -1,    -1,   574,  1073,
      13,   824,   605,   824,   900,   898,  1460,   899,   219,    -1,
      -1,   550,   824,    -1,   524,   908,    -1,   533,    18,    25,
      -1,   533,    -1,   479,    17,    25,    -1,   479,    -1,    25,
      -1,  1073,    -1,    24,    -1,   922,    -1,   824,    -1,   904,
       5,   904,    -1,   905,    -1,   915,    -1,   646,   408,   915,
     369,    -1,   915,   599,   646,   408,   915,   369,    -1,   915,
     436,   655,   404,    -1,   915,   599,    20,    -1,   915,   436,
     655,   404,   599,    20,    -1,   915,   599,   915,    -1,   915,
     436,   655,   404,   599,   915,    -1,   916,    -1,   916,    -1,
     916,    -1,   916,    -1,   916,    -1,   916,    -1,    -1,   529,
      25,    -1,   919,  1459,   920,    -1,   919,   917,   920,    -1,
    1459,    -1,   327,   408,   918,   369,    -1,  1076,    -1,    24,
      -1,    -1,    -1,   915,    -1,   915,   436,   655,   404,    -1,
     915,   599,    20,    -1,   915,   436,   655,   404,   599,    20,
      -1,   915,   599,   915,    -1,   915,   436,   655,   404,   599,
     915,    -1,  1073,    -1,    23,    -1,   599,    25,    -1,   351,
      -1,   470,    -1,   471,    -1,   368,    -1,   472,    -1,   331,
      -1,   298,    -1,   474,    -1,   437,    -1,   515,    -1,   426,
      -1,   570,    -1,   374,    -1,   467,    -1,   460,    -1,   538,
      -1,   377,    -1,   336,    -1,   475,    -1,   299,    -1,   517,
      -1,   258,    -1,   572,    -1,   634,    -1,   518,    -1,   300,
      -1,   520,    -1,   382,    -1,   420,    -1,   560,    -1,   491,
      -1,   569,    -1,   453,    -1,   356,    -1,   371,    -1,   416,
      -1,   358,    -1,   419,    -1,   400,    -1,   365,    -1,   323,
      -1,   537,    -1,   516,    -1,   526,  1442,    -1,   631,   927,
      -1,   928,    -1,   927,     5,   928,    -1,   915,    -1,   642,
     927,    -1,   633,   927,    -1,   634,  1450,    -1,   632,   912,
     638,  1450,    -1,   636,   927,    -1,   637,  1450,    -1,   635,
     912,   638,  1450,    -1,    -1,   640,   933,   822,   938,   940,
     942,   934,   936,    -1,    -1,   935,    -1,   628,    -1,   629,
      -1,    -1,   937,    -1,   322,  1073,    -1,    -1,   939,    -1,
     367,   822,    -1,    -1,   941,    -1,   639,    25,    -1,    -1,
     943,    -1,   630,    25,   944,    -1,    -1,   377,    25,    -1,
      -1,   601,   824,   554,   946,  1460,   947,   418,    -1,    -1,
      -1,   521,   948,  1460,    -1,    -1,    -1,    41,   949,   824,
     554,   950,  1460,   947,    -1,    84,   915,   408,    25,   369,
      -1,    53,   915,    -1,    -1,   268,  1103,   954,   605,   461,
      -1,   268,  1103,   535,   955,    -1,   956,    -1,   955,     5,
     956,    -1,   767,   599,  1367,    -1,   767,   599,    20,    -1,
      -1,   959,   302,    -1,    -1,   128,    -1,   960,    -1,   959,
     960,    -1,    -1,   248,   974,   961,  1460,    -1,    -1,   251,
     975,   962,  1460,    -1,    -1,   329,   963,  1460,    -1,    -1,
     325,   964,  1460,    -1,    -1,   986,   965,  1460,    -1,    -1,
     283,   966,  1460,    -1,    -1,   253,   967,  1460,    -1,    -1,
     643,   972,   968,  1460,    -1,    -1,   459,   970,   969,  1460,
      -1,   971,    -1,   970,     5,   971,    -1,   427,    -1,   416,
      -1,   973,    -1,   972,     5,   973,    -1,   427,    -1,   416,
      -1,   907,    -1,   974,     5,   907,    -1,   907,    -1,   975,
       5,   907,    -1,   292,   978,    -1,   293,   915,   638,   978,
      -1,   540,    -1,   352,    -1,   907,    -1,    -1,   644,   981,
     980,   957,    -1,   362,  1091,   958,   914,   658,    -1,  1091,
     958,   525,  1450,   914,   658,    -1,    -1,   465,  1098,   958,
     525,   915,   599,    20,   914,   982,   658,    -1,   447,  1450,
     984,    -1,   606,    -1,   518,    -1,    54,    25,    -1,    60,
      25,    -1,    -1,   529,    25,    -1,    -1,   407,   987,   993,
      -1,   273,    -1,    -1,   575,   989,   993,    -1,   281,   995,
      -1,    -1,   575,   992,   993,    -1,   995,    -1,   408,   994,
     369,    -1,   995,    -1,   994,     5,   995,    -1,    -1,   996,
     997,    -1,   573,    -1,   290,    -1,   308,    -1,   282,    -1,
     463,    -1,   419,    -1,   606,    -1,   529,    -1,   518,    -1,
     443,    -1,   416,    -1,   519,    -1,   534,    -1,   498,    -1,
     288,    -1,   289,    -1,    24,    -1,   488,    -1,    -1,    -1,
     577,  1000,  1096,  1001,    13,   842,  1002,    -1,   461,    -1,
     823,    -1,   197,  1073,    -1,   186,  1073,    -1,   200,  1073,
      -1,   428,  1073,   311,    -1,   428,  1073,   363,   903,    -1,
      -1,  1009,  1008,  1012,    -1,    -1,  1010,    -1,  1011,    -1,
    1010,  1011,    -1,   952,    -1,  1016,    -1,  1032,    -1,  1018,
      -1,    -1,  1013,    -1,  1015,    -1,  1013,  1015,    -1,    45,
     915,    -1,  1020,    -1,  1026,    -1,  1038,    -1,  1190,    -1,
    1200,    -1,  1042,    -1,  1440,    -1,   871,    -1,   705,    -1,
     951,    -1,   711,    -1,   705,    -1,  1440,    -1,    -1,   705,
      -1,  1440,    -1,   733,    -1,   345,    -1,    39,    -1,    -1,
      -1,    -1,    -1,  1019,  1021,   915,   408,  1022,  1089,   369,
    1023,   732,  1024,  1017,  1460,  1025,    -1,   188,    -1,    -1,
      -1,   536,  1027,   732,  1028,  1460,   339,    -1,   443,   819,
      -1,   842,    -1,   842,   822,    -1,   334,  1378,    -1,  1033,
      -1,  1034,    -1,  1033,  1034,    -1,  1035,    -1,  1016,    -1,
    1031,    -1,    -1,   383,  1036,  1037,    -1,   732,   220,    -1,
     903,    -1,    -1,    -1,    -1,    91,   915,    90,   915,   408,
    1039,  1089,   369,  1040,   732,  1041,  1017,  1460,  1025,    -1,
      -1,    -1,   625,   915,  1043,   732,  1044,  1045,   626,    -1,
    1046,    -1,  1045,  1046,    -1,    -1,   627,  1047,  1460,    -1,
      -1,   604,   915,  1048,  1460,    -1,    -1,   537,  1050,  1065,
    1056,  1051,    -1,   340,    -1,    -1,   212,  1053,  1460,    -1,
      -1,    22,  1057,  1058,  1059,   914,  1054,  1460,    -1,    -1,
      22,  1057,   914,  1055,  1460,    -1,  1052,    -1,  1056,  1052,
      -1,    -1,   988,    -1,    24,    -1,  1073,    -1,    -1,  1073,
      -1,    24,    -1,   229,  1063,    -1,   241,  1064,    -1,   224,
    1064,    -1,   564,    -1,    24,    -1,  1073,    -1,  1063,    -1,
    1064,     5,  1063,    -1,  1073,    -1,    24,    -1,  1069,  1067,
      -1,    -1,   659,  1071,    -1,  1072,    -1,  1068,    -1,   939,
      -1,   941,    -1,   943,    -1,   935,    -1,   937,    -1,    -1,
     348,  1070,   823,    -1,    -1,    44,    -1,    44,    -1,  1074,
      -1,  1076,    -1,   591,  1076,    -1,  1076,   919,   599,    -1,
    1075,  1080,    -1,  1075,   915,   436,  1083,   404,    -1,  1081,
      -1,   915,    -1,  1077,    -1,   915,   435,  1079,   403,    -1,
     915,   435,  1079,   403,    -1,  1073,    -1,    24,    -1,    20,
      -1,   915,    -1,   915,  1082,    -1,   436,  1083,   404,    -1,
     436,  1083,   404,   436,  1083,   404,    -1,  1084,    -1,  1083,
       5,  1084,    -1,   655,    -1,  1086,    -1,  1088,    -1,  1086,
     919,   599,  1087,    -1,  1086,   919,   599,   915,   436,  1083,
     404,    -1,   915,    -1,  1078,    -1,    20,    -1,   915,    -1,
     915,  1082,    -1,    -1,  1090,    -1,  1092,    -1,  1090,     5,
    1092,    -1,  1093,    -1,  1091,     5,  1093,    -1,   915,    -1,
     915,   599,   915,    -1,  1073,    -1,  1073,   398,  1073,    -1,
      24,    -1,   923,    -1,    25,    -1,  1095,    -1,  1094,     5,
    1095,    -1,  1073,    -1,  1073,   398,  1073,    -1,  1097,    -1,
    1096,     5,  1097,    -1,  1085,    -1,  1073,    -1,  1100,    -1,
    1099,     5,  1100,    -1,  1073,  1101,    -1,    -1,   566,    -1,
     517,    -1,   915,   436,  1083,   404,    -1,  1104,    -1,  1103,
       5,  1104,    -1,  1073,    -1,  1073,   398,  1073,    -1,   232,
     911,   597,   905,   558,  1452,   663,    -1,    -1,   597,   408,
     824,     5,   824,   369,  1107,    -1,    -1,   547,   408,   824,
       5,   824,   369,    -1,   233,   915,  1106,    -1,   915,    -1,
     316,   913,  1111,    -1,  1112,    -1,   525,   824,    -1,  1113,
    1114,  1119,     8,  1109,    -1,    -1,   597,  1115,   408,   824,
       5,   824,   369,    -1,    -1,   535,   916,    -1,    -1,   328,
      -1,   195,  1419,   244,  1435,  1118,    -1,   542,   908,    -1,
     542,   908,     8,   842,   822,    -1,    -1,   596,   555,  1413,
     351,  1413,    -1,   596,   555,  1413,     5,   351,  1413,    -1,
     596,  1413,     5,  1413,    -1,    -1,   628,    -1,   629,    -1,
      68,  1435,  1121,  1122,    -1,    -1,   596,  1435,    -1,    -1,
     596,   555,  1413,     8,  1413,    -1,   555,  1413,     8,  1413,
      -1,   389,  1124,    -1,  1125,    -1,  1124,     5,  1125,    -1,
     181,   902,    -1,   262,   902,    -1,   307,   902,    -1,   315,
     902,    -1,   271,   902,    -1,   237,   902,    -1,   990,    -1,
     416,   991,    -1,   427,   991,    -1,   540,   991,    -1,   352,
     991,    -1,   529,   991,    -1,   527,   903,    -1,   528,   903,
      -1,   378,   659,    -1,   644,   659,    -1,   269,    -1,   173,
      -1,   129,    -1,   106,    -1,   124,    -1,   115,    -1,  1418,
     391,  1129,   525,  1127,    -1,  1073,    -1,    24,    -1,   380,
    1129,    -1,   380,  1129,     8,  1091,    -1,   916,    -1,    -1,
     439,  1138,   658,   574,  1133,  1073,   914,   658,  1131,  1134,
      -1,   439,  1138,   658,   322,  1073,    -1,    -1,   514,    -1,
      -1,  1135,   260,    -1,  1136,    -1,  1135,  1136,    -1,    -1,
     986,  1137,  1460,    -1,   823,    -1,    -1,   583,   908,  1140,
    1141,    -1,    -1,   525,  1142,    -1,  1143,    -1,  1142,     5,
    1143,    -1,  1406,    -1,   461,    -1,   198,  1146,    66,    -1,
     198,  1146,   605,  1145,    -1,   198,  1146,    65,  1145,    -1,
     198,  1146,    -1,    24,    -1,   922,    -1,   915,    -1,    -1,
     457,    -1,   123,  1146,  1147,   408,   842,  1030,   369,    -1,
     171,  1146,    -1,  1181,  1189,    -1,   424,    40,    -1,   424,
    1152,    -1,  1153,    -1,  1152,  1153,    -1,    -1,   111,  1154,
    1460,    -1,    -1,   177,  1155,  1460,    -1,    -1,   206,  1156,
    1460,    -1,    -1,   194,  1157,  1460,    -1,    -1,   231,  1158,
    1460,    -1,    -1,   179,  1073,  1159,  1460,    -1,    -1,   202,
    1073,  1160,  1460,    -1,  1171,    -1,  1173,    -1,  1172,    -1,
    1162,    -1,  1198,    -1,  1165,    -1,    -1,   539,   824,  1163,
     460,    -1,    -1,   460,    -1,    -1,   548,   824,  1166,  1164,
      -1,   136,    -1,   608,  1185,    -1,   139,  1185,    -1,   138,
    1185,    -1,    -1,  1168,    -1,  1169,    -1,  1168,  1169,    -1,
    1178,  1170,    -1,    -1,   597,  1185,    -1,   497,  1167,  1177,
      -1,   496,  1413,  1177,    -1,   495,  1176,  1175,  1174,  1177,
      -1,    -1,   130,   817,    -1,   130,   817,     5,   817,    -1,
     592,    -1,   593,    -1,   594,    -1,   595,    -1,  1073,    -1,
      -1,   500,    -1,  1179,    -1,  1178,     5,  1179,    -1,   824,
    1212,    -1,   588,   408,   817,   369,  1197,    -1,    43,  1197,
      -1,   474,   408,    20,   369,  1197,    -1,   390,   408,    20,
     369,  1197,    -1,   365,   408,   817,   369,  1197,    -1,   567,
     408,   817,   369,  1197,    -1,   580,   408,   817,   369,  1197,
      -1,   579,   408,   817,   369,  1197,    -1,    -1,   438,  1182,
      -1,  1183,    -1,  1182,  1183,    -1,   205,    25,    -1,   196,
      25,    -1,   279,    25,    -1,   162,    25,    -1,   234,    25,
      -1,   154,    -1,   321,    24,    -1,   321,  1073,    -1,   155,
      24,    -1,   137,    24,    -1,  1188,    -1,  1184,  1188,    -1,
    1186,    86,    -1,  1186,    88,    -1,  1186,    87,    -1,  1186,
      -1,   923,    -1,    25,    -1,    -1,   438,  1184,    -1,   205,
    1185,    -1,   196,  1185,    -1,   279,  1185,    -1,   162,  1185,
      -1,   234,  1185,    -1,   235,  1185,    -1,   607,    24,    -1,
     608,  1185,    -1,   612,    -1,   609,    -1,   610,    -1,   611,
      -1,   616,    -1,   613,    -1,   614,    -1,   615,    -1,    55,
    1185,    -1,    56,  1185,    -1,    57,  1185,    -1,   321,    24,
      -1,   155,    24,    -1,   377,    -1,    51,    -1,    52,    -1,
      -1,   492,   598,  1099,    -1,   112,  1099,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,  1191,   915,   408,  1192,  1089,
     369,  1193,   732,  1194,  1150,  1195,  1151,  1196,   217,    -1,
      -1,   504,   817,    -1,   494,  1199,    -1,    -1,  1127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    83,  1201,   915,   408,
    1202,  1089,   369,  1203,   732,  1204,  1207,  1205,  1151,  1206,
     217,    -1,  1187,  1189,    -1,    -1,    -1,    -1,   132,   408,
      24,     5,  1209,   685,  1210,   369,  1211,   683,    -1,    -1,
     361,    -1,   361,   196,    25,    -1,   361,   196,  1073,    -1,
     586,   824,    -1,   586,   824,   322,  1073,    -1,   586,   824,
     140,    -1,   586,   824,   556,    -1,   586,   824,   523,    -1,
    1215,    -1,   151,    -1,   301,    -1,   259,    -1,  1222,    -1,
    1217,    -1,    -1,    -1,   184,  1218,  1364,   408,  1219,  1226,
     369,    -1,    -1,    -1,   109,  1220,  1364,   408,  1221,  1226,
     369,  1223,    -1,    81,  1224,   369,    -1,    34,   916,    -1,
      -1,   246,    -1,  1225,    -1,  1224,     5,  1225,    -1,   915,
     566,    -1,   915,   517,    -1,   915,    -1,  1227,    -1,  1226,
       5,  1227,    -1,  1317,    -1,  1315,    -1,    98,   915,    -1,
     157,    -1,    33,   915,  1230,    -1,  1231,    -1,  1230,     5,
    1231,    -1,  1232,    -1,  1235,    -1,  1238,    -1,  1243,    -1,
    1244,    -1,  1242,    -1,  1241,    -1,   563,  1233,    -1,   563,
     408,  1234,   369,    -1,  1227,    -1,  1227,   643,   915,    -1,
    1233,    -1,  1234,     5,  1233,    -1,   520,  1237,    -1,   520,
     408,  1236,   369,    -1,  1237,    -1,  1236,     5,  1237,    -1,
     915,    -1,   432,  1240,    -1,   432,   408,  1239,   369,    -1,
    1240,    -1,  1239,     5,  1240,    -1,  1227,    -1,    63,    -1,
      64,    -1,    62,    25,    -1,    35,  1321,    -1,    35,   408,
    1245,   369,    -1,    36,  1246,    -1,    36,   408,  1245,   369,
      -1,  1321,    -1,  1245,     5,  1321,    -1,   915,    -1,   243,
      -1,   209,    -1,   142,  1249,    -1,   119,    -1,   107,    -1,
      97,    -1,    95,    -1,    99,    -1,   156,  1419,    -1,   208,
    1248,   437,  1413,   605,  1413,    -1,   276,   908,   437,  1413,
     605,  1413,    -1,    -1,  1419,    -1,    -1,   824,    -1,   501,
     824,    -1,    -1,    -1,   456,  1364,  1252,   562,  1255,  1253,
    1254,    -1,    -1,   127,   909,    -1,   504,  1340,    -1,   408,
    1259,   369,    13,   408,  1260,   369,    -1,  1256,    -1,    20,
      13,   408,  1260,   369,    -1,    20,    13,  1260,    -1,  1258,
      -1,  1256,     5,  1258,    -1,  1367,    -1,  1257,    13,  1261,
      -1,  1257,    -1,  1259,     5,  1257,    -1,  1261,    -1,  1260,
       5,  1261,    -1,   461,    -1,  1406,    -1,   207,    -1,    -1,
     226,  1264,  1364,  1267,  1265,    -1,    -1,   457,  1266,   408,
    1269,   369,    -1,  1400,    -1,    -1,   408,  1268,   369,    -1,
    1367,    -1,  1268,     5,  1367,    -1,  1270,    -1,  1269,     5,
    1270,    -1,  1406,    -1,   461,    -1,    -1,    -1,   478,  1272,
    1274,  1273,  1275,    -1,  1279,   909,    -1,   909,    -1,    -1,
      -1,   532,  1276,  1094,    -1,    -1,    -1,   532,  1278,  1094,
      -1,   479,    -1,   533,    -1,   540,    -1,   352,    -1,   319,
      -1,   373,    -1,   355,   824,    -1,   328,   824,    -1,   215,
    1364,   127,   909,    -1,   215,  1364,  1337,    -1,   492,   598,
    1283,    -1,  1284,    -1,  1283,     5,  1284,    -1,  1285,  1286,
      -1,    25,    -1,  1367,    -1,    -1,   566,    -1,   517,    -1,
     254,    -1,   287,    -1,    -1,   304,    -1,   334,  1435,  1289,
      -1,    -1,  1418,  1292,  1293,    -1,  1322,    -1,  1326,    -1,
    1288,    -1,  1420,    -1,  1287,    -1,  1280,    -1,  1281,    -1,
    1271,    -1,  1263,    -1,  1262,    -1,  1390,    -1,  1251,    -1,
     483,  1296,   604,  1364,   605,  1301,  1295,    -1,    -1,   118,
      -1,   146,    -1,  1297,    -1,  1298,    -1,  1297,     5,  1298,
      -1,   449,    -1,   427,    -1,   416,    -1,   456,  1299,    -1,
      -1,   408,  1300,   369,    -1,  1367,    -1,  1300,     5,  1367,
      -1,  1302,    -1,  1301,     5,  1302,    -1,   440,    -1,  1365,
      -1,   213,  1364,  1304,   596,  1400,  1306,    -1,    -1,   408,
    1305,   369,    -1,  1367,    -1,  1305,     5,  1367,    -1,    -1,
     117,    -1,   470,   408,  1340,   369,    -1,   223,   408,  1310,
     369,  1309,    -1,   274,  1311,    -1,  1312,    -1,  1364,    -1,
    1364,   408,  1312,   369,    -1,  1367,    -1,  1312,     5,  1367,
      -1,   454,   408,  1314,   369,    -1,   236,   408,  1314,   369,
      -1,  1367,    -1,  1314,     5,  1367,    -1,  1313,    -1,  1308,
      -1,  1307,    -1,   377,  1369,    -1,   185,    -1,   915,  1356,
    1318,  1319,    -1,    -1,  1316,    -1,    -1,  1320,    -1,  1321,
      -1,  1320,  1321,    -1,   350,    -1,   135,    -1,  1309,    -1,
     470,   408,  1340,   369,    -1,    96,  1323,  1325,    -1,  1324,
      -1,  1365,    -1,  1326,    -1,  1325,  1326,    -1,  1303,    -1,
    1294,    -1,   425,  1340,    -1,   346,  1329,    -1,  1405,    -1,
    1329,     5,  1405,    -1,   504,  1340,    -1,   525,  1332,    -1,
    1333,    -1,  1332,     5,  1333,    -1,  1334,    -1,   493,  1334,
      -1,   493,   408,  1335,   369,    -1,  1364,    -1,  1364,  1368,
      -1,  1333,    -1,  1335,     5,  1333,    -1,  1331,  1337,  1338,
    1339,    -1,    -1,  1330,    -1,    -1,  1328,    -1,    -1,  1327,
      -1,  1341,    -1,  1340,     6,  1341,    -1,  1342,    -1,  1341,
       7,  1342,    -1,  1343,    -1,   581,  1343,    -1,  1354,    -1,
     408,  1340,   369,    -1,   420,  1401,    -1,   272,  1401,    -1,
      -1,   419,  1347,    -1,  1409,    -1,  1409,    -1,  1406,   602,
     408,  1349,   369,    -1,  1406,   602,  1401,    -1,  1406,   406,
     408,  1349,   369,    -1,  1406,   406,  1401,    -1,  1350,    -1,
    1349,     5,  1350,    -1,  1439,    -1,  1369,    -1,    -1,   581,
      -1,  1406,  1351,   364,    -1,  1406,  1351,   227,    -1,  1406,
    1353,  1406,    -1,  1406,  1351,   366,  1406,     7,  1406,    -1,
    1406,  1351,   535,  1346,  1345,    -1,  1406,  1351,     9,  1346,
    1345,    -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,
     230,    -1,     9,    -1,    15,    -1,    14,    -1,  1352,    -1,
    1348,    -1,  1344,    -1,    -1,   564,    -1,   337,    -1,   454,
      -1,  1357,    -1,  1358,    -1,  1360,    -1,   514,    -1,   514,
     408,  1361,   369,    -1,   388,   408,  1362,  1359,   369,    -1,
     450,    -1,   375,   408,  1362,  1359,   369,    -1,   490,   408,
    1362,  1359,   369,    -1,   516,    -1,   385,    -1,   357,    -1,
     335,  1376,   605,  1377,    -1,   335,    -1,   347,  1376,   605,
    1377,    -1,   347,    -1,   347,  1376,   408,    25,   369,   605,
    1377,    -1,   553,    -1,   511,    -1,   401,    -1,   401,   408,
      25,   369,    -1,   401,   408,    25,     5,    25,   369,    -1,
      -1,     5,  1363,    -1,   480,   408,  1362,   369,    -1,   544,
      -1,   277,    -1,   480,    -1,    42,    -1,    25,    -1,    25,
      -1,    25,    -1,    24,   599,   915,    -1,    24,    -1,   915,
      -1,   915,   568,   915,    -1,   915,    -1,    -1,   436,    25,
     404,    -1,   436,    25,     5,    25,   404,    -1,   915,  1366,
      -1,  1364,   919,   599,   915,  1366,    -1,  1364,   919,   599,
      20,    -1,   915,    -1,    24,    -1,   388,    -1,   923,    -1,
      25,    -1,    17,   923,    -1,    17,    25,    -1,    18,   923,
      -1,    18,    25,    -1,  1371,    -1,   373,  1373,    -1,   373,
    1372,    -1,    -1,  1376,   605,  1377,    -1,    -1,  1374,   605,
    1374,    -1,   560,    -1,   491,    -1,   569,    -1,   531,    -1,
     431,    -1,   448,    -1,   344,    -1,   344,   408,    25,   369,
      -1,   560,    -1,   491,    -1,   569,    -1,   531,    -1,   431,
      -1,   448,    -1,   344,    -1,   344,   408,    25,   369,    -1,
     560,    -1,   491,    -1,   569,    -1,   531,    -1,   431,    -1,
     448,    -1,   344,    -1,   560,    -1,   491,    -1,   569,    -1,
     531,    -1,   431,    -1,   448,    -1,   344,    -1,   915,    -1,
      24,    -1,  1418,   481,   909,    -1,    -1,  1418,   376,   909,
     414,   574,  1388,  1381,  1385,    -1,    -1,  1418,   376,   909,
     414,    78,   574,  1389,  1382,  1385,    -1,    -1,  1418,   376,
     909,   113,  1389,  1383,  1385,    -1,    -1,  1418,   376,   909,
     114,    78,   574,  1389,  1384,  1385,    -1,    -1,   266,    -1,
     265,  1386,    -1,  1387,    -1,  1386,     5,  1387,    -1,   915,
      -1,   915,   599,   915,    -1,    24,   599,   915,   599,   915,
      -1,  1389,    -1,  1263,    -1,  1129,    -1,  1391,    -1,  1391,
    1385,    -1,    -1,    -1,   449,  1402,  1403,  1392,  1399,  1393,
    1336,  1397,    -1,   449,  1402,  1403,  1336,  1397,    -1,  1396,
      -1,  1413,    -1,   449,   919,  1402,  1403,  1399,  1336,  1397,
      -1,    -1,   503,  1355,  1395,    -1,  1282,    -1,   309,  1398,
    1223,    -1,  1282,   309,  1398,  1223,    -1,   915,    -1,    -1,
     532,  1094,    -1,   449,   919,  1402,  1403,  1336,    -1,   408,
     449,   919,  1402,  1403,  1336,   369,    -1,    -1,   564,    -1,
     337,    -1,   454,    -1,  1404,    -1,  1403,     5,  1404,    -1,
    1406,    -1,  1406,  1459,    -1,  1406,   924,    -1,  1406,    -1,
    1407,    -1,  1439,    -1,  1401,    -1,  1406,    19,  1406,    -1,
    1406,  1427,    -1,  1406,    20,  1406,    -1,  1406,    17,  1406,
      -1,  1406,    18,  1406,    -1,  1369,    -1,   462,    -1,   405,
      -1,   555,    -1,    20,    -1,    43,    -1,   567,   408,  1355,
    1406,   369,    -1,   579,   408,  1355,  1406,   369,    -1,   580,
     408,  1355,  1406,   369,    -1,   588,   408,  1355,  1406,   369,
      -1,   474,   408,  1355,  1406,   369,    -1,   915,   408,  1408,
     369,    -1,   516,   408,  1408,   369,    -1,   408,  1406,   369,
      -1,   421,   408,  1428,   369,    -1,  1406,    -1,  1408,     5,
    1406,    -1,    -1,  1369,    -1,  1418,   324,  1417,  1412,  1395,
      -1,  1418,   313,  1417,  1412,   226,  1364,  1414,    -1,  1418,
     313,  1417,  1412,  1073,    -1,    -1,   299,  1413,    -1,    24,
      -1,  1073,    -1,    -1,   408,  1415,   369,    -1,  1416,    -1,
    1415,     5,  1416,    -1,   915,    -1,    24,    -1,  1073,    -1,
      -1,   245,  1419,   574,    -1,   916,    -1,  1425,    -1,  1424,
      -1,  1421,    -1,   294,  1422,   605,  1422,    -1,   275,  1422,
     599,  1423,   605,  1423,    -1,   915,    -1,   915,    -1,   199,
     767,    -1,   270,   767,  1426,    -1,   249,    -1,   153,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,   373,     5,  1376,   605,  1377,    -1,  1367,     5,
    1376,   605,  1377,    -1,   373,  1376,   605,  1377,    -1,    -1,
     587,  1430,  1431,   167,    -1,  1432,    -1,  1431,  1432,    -1,
      32,    -1,  1433,    -1,  1434,    -1,   168,  1439,    -1,   532,
    1094,    -1,  1436,    -1,   591,  1437,    -1,  1437,    -1,  1102,
      -1,   915,    -1,  1437,   599,  1438,    -1,    24,   599,  1437,
     599,  1438,    -1,    20,    -1,  1102,    -1,   915,    -1,  1436,
      -1,  1436,   398,  1436,    -1,   104,  1441,    -1,   108,  1441,
      -1,   103,  1441,    -1,   143,    -1,   144,  1441,    -1,   101,
    1441,    -1,   126,  1441,    -1,   125,  1441,    -1,   100,  1441,
      -1,   333,    -1,   600,   605,  1442,    -1,   526,  1442,    -1,
     551,    -1,   512,  1443,    -1,   915,    -1,   568,   915,    -1,
     915,    -1,    -1,    -1,   505,  1445,   824,  1446,  1460,   303,
      -1,    -1,   638,  1450,    -1,    -1,   641,    -1,   159,    -1,
     255,   910,    -1,    47,   910,    -1,   285,    -1,   284,    -1,
     286,   912,  1447,  1448,    -1,   471,  1450,  1448,    -1,   907,
      -1,  1450,     5,   907,    -1,    80,    -1,   110,   910,    -1,
     824,   545,     5,   824,   370,    -1,   487,   824,    -1,   242,
     910,    -1,    79,  1455,     8,  1456,  1454,    -1,    -1,   525,
     824,    -1,   915,    -1,   915,    -1,   225,   910,    -1,   228,
     910,   605,   824,     5,   824,    -1,   228,   910,   598,   824,
       5,   824,    -1,    26,    -1,    -1,  1462,    -1,  1463,  1177,
      -1,  1461,    -1,  1462,  1461,    -1,    -1,  1464,  1465,    -1,
     648,    -1,   649,    -1,   650,    -1,   651,    -1,   668,    -1,
     690,    -1,   704,    -1,   705,    -1,   711,    -1,   712,    -1,
     731,    -1,   799,    -1,   800,    -1,   801,    -1,   802,    -1,
     813,    -1,   814,    -1,   815,    -1,   816,    -1,   867,    -1,
     897,    -1,   901,    -1,   925,    -1,   926,    -1,   929,    -1,
     930,    -1,   931,    -1,   932,    -1,   945,    -1,   953,    -1,
     976,    -1,   977,    -1,   979,    -1,   983,    -1,   998,    -1,
     999,    -1,  1003,    -1,  1004,    -1,  1005,    -1,  1006,    -1,
    1014,    -1,  1029,    -1,  1049,    -1,  1060,    -1,  1061,    -1,
    1062,    -1,  1066,    -1,  1105,    -1,  1108,    -1,  1110,    -1,
    1116,    -1,  1117,    -1,  1120,    -1,  1123,    -1,  1126,    -1,
    1128,    -1,  1130,    -1,  1132,    -1,  1139,    -1,  1144,    -1,
    1148,    -1,  1149,    -1,  1161,    -1,  1213,    -1,  1214,    -1,
    1216,    -1,  1228,    -1,  1229,    -1,  1247,    -1,  1250,    -1,
    1290,    -1,  1291,    -1,  1379,    -1,  1380,    -1,  1410,    -1,
    1411,    -1,  1429,    -1,  1440,    -1,  1444,    -1,  1449,    -1,
    1451,    -1,  1453,    -1,  1457,    -1,  1458,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   883,   883,   886,   889,   895,   901,   908,   912,   912,
     918,   936,   937,   938,   939,   940,   954,   955,   956,   957,
     958,   963,   964,   975,   978,   981,   981,   985,   988,   989,
     995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1013,  1014,  1017,  1017,
    1025,  1026,  1029,  1035,  1037,  1048,  1050,  1052,  1054,  1058,
    1060,  1122,  1126,  1130,  1130,  1137,  1140,  1144,  1145,  1148,
    1154,  1148,  1167,  1172,  1176,  1167,  1188,  1192,  1188,  1201,
    1206,  1201,  1225,  1232,  1236,  1224,  1262,  1262,  1266,  1267,
    1268,  1273,  1276,  1281,  1285,  1293,  1296,  1296,  1302,  1306,
    1321,  1319,  1337,  1337,  1352,  1352,  1355,  1355,  1359,  1362,
    1362,  1362,  1369,  1370,  1369,  1377,  1377,  1388,  1388,  1407,
    1410,  1413,  1416,  1419,  1422,  1435,  1440,  1440,  1441,  1441,
    1444,  1449,  1449,  1453,  1463,  1477,  1481,  1476,  1491,  1497,
    1505,  1506,  1509,  1509,  1512,  1516,  1521,  1528,  1528,  1532,
    1532,  1539,  1539,  1544,  1544,  1549,  1549,  1554,  1554,  1567,
    1568,  1576,  1577,  1594,  1597,  1600,  1603,  1606,  1609,  1615,
    1626,  1631,  1644,  1648,  1663,  1664,  1668,  1668,  1672,  1672,
    1672,  1673,  1674,  1679,  1679,  1682,  1682,  1691,  1692,  1693,
    1696,  1700,  1701,  1701,  1718,  1718,  1718,  1718,  1722,  1729,
    1730,  1733,  1733,  1736,  1736,  1745,  1742,  1758,  1758,  1760,
    1760,  1762,  1764,  1766,  1768,  1771,  1775,  1775,  1776,  1776,
    1780,  1780,  1792,  1792,  1797,  1801,  1803,  1804,  1807,  1807,
    1807,  1811,  1812,  1813,  1814,  1821,  1822,  1823,  1824,  1827,
    1828,  1829,  1830,  1834,  1839,  1844,  1848,  1851,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1865,  1866,  1867,  1899,
    1903,  1905,  1907,  1907,  1914,  1918,  1918,  1922,  1923,  1924,
    1925,  1926,  1927,  1928,  1934,  1934,  1937,  1939,  1945,  1947,
    1953,  1961,  1961,  1964,  1965,  1966,  1967,  1968,  1969,  1970,
    1976,  1979,  1979,  1992,  1992,  1999,  2000,  2001,  2003,  2004,
    2006,  2008,  2009,  2010,  2011,  2016,  2022,  2028,  2029,  2031,
    2033,  2034,  2035,  2036,  2037,  2038,  2041,  2042,  2049,  2057,
    2057,  2065,  2062,  2077,  2077,  2079,  2079,  2087,  2087,  2090,
    2093,  2094,  2099,  2111,  2115,  2118,  2121,  2122,  2123,  2124,
    2125,  2130,  2137,  2143,  2148,  2152,  2148,  2163,  2165,  2170,
    2175,  2175,  2179,  2179,  2182,  2182,  2188,  2188,  2194,  2194,
    2210,  2213,  2228,  2231,  2244,  2246,  2248,  2250,  2252,  2254,
    2256,  2262,  2264,  2268,  2270,  2272,  2274,  2276,  2278,  2280,
    2286,  2300,  2301,  2302,  2303,  2304,  2308,  2309,  2310,  2314,
    2319,  2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,  2334,
    2335,  2340,  2340,  2345,  2345,  2348,  2354,  2362,  2368,  2378,
    2379,  2387,  2394,  2398,  2408,  2412,  2417,  2422,  2424,  2434,
    2447,  2455,  2468,  2473,  2479,  2484,  2489,  2490,  2496,  2567,
    2573,  2578,  2586,  2586,  2602,  2606,  2613,  2616,  2624,  2635,
    2645,  2651,  2660,  2665,  2673,  2676,  2679,  2684,  2691,  2696,
    2701,  2706,  2716,  2724,  2732,  2737,  2741,  2746,  2750,  2754,
    2761,  2764,  2767,  2771,  2775,  2779,  2783,  2791,  2801,  2806,
    2799,  2821,  2826,  2821,  2843,  2843,  2843,  2846,  2846,  2846,
    2849,  2849,  2849,  2852,  2852,  2852,  2855,  2861,  2867,  2873,
    2883,  2883,  2887,  2891,  2892,  2898,  2899,  2904,  2907,  2911,
    2915,  2916,  2919,  2924,  2930,  2934,  2938,  2941,  2947,  2950,
    2953,  2968,  2971,  2977,  2978,  2979,  2983,  2984,  2985,  2986,
    2987,  2989,  2990,  2991,  2993,  2994,  2998,  2999,  3013,  3017,
    3022,  3012,  3042,  3048,  3042,  3062,  3062,  3064,  3065,  3069,
    3069,  3073,  3073,  3078,  3078,  3085,  3086,  3090,  3090,  3094,
    3094,  3099,  3099,  3106,  3110,  3111,  3112,  3117,  3117,  3120,
    3120,  3124,  3124,  3128,  3128,  3132,  3132,  3137,  3137,  3142,
    3142,  3147,  3147,  3152,  3152,  3168,  3172,  3167,  3180,  3183,
    3197,  3214,  3215,  3216,  3217,  3218,  3219,  3222,  3222,  3225,
    3227,  3230,  3233,  3235,  3236,  3237,  3239,  3241,  3243,  3245,
    3249,  3256,  3258,  3264,  3269,  3274,  3279,  3279,  3282,  3288,
    3293,  3296,  3303,  3303,  3305,  3311,  3315,  3316,  3318,  3320,
    3322,  3324,  3328,  3337,  3337,  3344,  3345,  3346,  3347,  3348,
    3349,  3350,  3351,  3352,  3353,  3354,  3355,  3356,  3357,  3358,
    3359,  3360,  3361,  3362,  3363,  3364,  3365,  3366,  3367,  3368,
    3369,  3370,  3371,  3372,  3373,  3374,  3375,  3376,  3377,  3378,
    3379,  3380,  3381,  3382,  3383,  3384,  3385,  3386,  3398,  3411,
    3418,  3418,  3422,  3427,  3433,  3437,  3441,  3447,  3451,  3455,
    3461,  3461,  3469,  3470,  3474,  3474,  3478,  3479,  3482,  3485,
    3485,  3488,  3490,  3490,  3493,  3495,  3495,  3496,  3498,  3498,
    3507,  3505,  3517,  3517,  3517,  3520,  3522,  3520,  3529,  3535,
    3545,  3545,  3549,  3555,  3555,  3559,  3560,  3571,  3572,  3574,
    3576,  3581,  3581,  3585,  3584,  3591,  3590,  3596,  3596,  3601,
    3601,  3607,  3607,  3612,  3612,  3617,  3617,  3622,  3622,  3627,
    3627,  3635,  3636,  3644,  3645,  3650,  3651,  3660,  3661,  3668,
    3669,  3677,  3678,  3687,  3692,  3697,  3698,  3699,  3703,  3702,
    3713,  3718,  3723,  3723,  3734,  3739,  3740,  3741,  3742,  3745,
    3745,  3751,  3751,  3753,  3756,  3756,  3758,  3762,  3762,  3765,
    3766,  3769,  3769,  3774,  3774,  3777,  3778,  3779,  3780,  3781,
    3782,  3783,  3784,  3785,  3786,  3787,  3788,  3789,  3790,  3791,
    3792,  3793,  3797,  3815,  3815,  3815,  3841,  3852,  3859,  3865,
    3871,  3877,  3888,  3911,  3910,  3927,  3927,  3931,  3932,  3940,
    3941,  3942,  3943,  3950,  3951,  3953,  3954,  3958,  3963,  3964,
    3965,  3966,  3967,  3968,  3969,  3970,  3971,  3972,  3973,  3976,
    3976,  3978,  3978,  3978,  3980,  3984,  3984,  3993,  3998,  4011,
    4017,  3992,  4031,  4045,  4055,  4044,  4068,  4075,  4075,  4080,
    4085,  4090,  4091,  4094,  4094,  4094,  4097,  4097,  4105,  4111,
    4125,  4129,  4142,  4124,  4156,  4162,  4156,  4173,  4174,  4178,
    4178,  4188,  4188,  4206,  4206,  4219,  4230,  4229,  4241,  4237,
    4254,  4251,  4264,  4264,  4266,  4267,  4269,  4270,  4273,  4274,
    4275,  4277,  4282,  4287,  4293,  4295,  4296,  4299,  4300,  4303,
    4305,  4312,  4315,  4319,  4323,  4328,  4332,  4333,  4334,  4335,
    4336,  4340,  4340,  4342,  4342,  4345,  4354,  4392,  4392,  4395,
    4399,  4404,  4442,  4443,  4444,  4447,  4461,  4473,  4473,  4478,
    4479,  4485,  4540,  4545,  4552,  4557,  4565,  4571,  4592,  4595,
    4596,  4634,  4635,  4639,  4640,  4644,  4697,  4701,  4704,  4710,
    4721,  4728,  4736,  4736,  4739,  4740,  4741,  4742,  4743,  4746,
    4749,  4755,  4758,  4762,  4766,  4773,  4778,  4785,  4788,  4794,
    4796,  4796,  4796,  4800,  4814,  4821,  4828,  4831,  4845,  4852,
    4853,  4856,  4857,  4861,  4867,  4872,  4878,  4879,  4884,  4888,
    4888,  4892,  4893,  4896,  4897,  4901,  4909,  4912,  4918,  4919,
    4921,  4923,  4927,  4927,  4928,  4933,  4941,  4942,  4947,  4948,
    4950,  4963,  4965,  4966,  4968,  4971,  4974,  4977,  4980,  4983,
    4986,  4990,  4994,  4998,  5001,  5005,  5008,  5009,  5010,  5013,
    5016,  5019,  5022,  5025,  5028,  5031,  5047,  5055,  5055,  5057,
    5064,  5071,  5086,  5084,  5104,  5109,  5110,  5114,  5115,  5117,
    5118,  5120,  5120,  5128,  5137,  5137,  5147,  5148,  5151,  5152,
    5155,  5159,  5173,  5178,  5183,  5188,  5198,  5198,  5202,  5205,
    5205,  5207,  5217,  5224,  5226,  5230,  5233,  5233,  5237,  5236,
    5240,  5239,  5243,  5242,  5246,  5245,  5249,  5248,  5251,  5251,
    5267,  5266,  5288,  5289,  5290,  5291,  5292,  5293,  5296,  5296,
    5302,  5302,  5305,  5305,  5315,  5316,  5317,  5324,  5336,  5337,
    5340,  5341,  5344,  5347,  5347,  5352,  5356,  5361,  5367,  5368,
    5369,  5373,  5374,  5375,  5376,  5380,  5390,  5392,  5397,  5400,
    5405,  5411,  5418,  5425,  5434,  5441,  5448,  5455,  5462,  5471,
    5471,  5473,  5473,  5476,  5477,  5478,  5479,  5480,  5481,  5482,
    5483,  5484,  5485,  5488,  5488,  5491,  5492,  5493,  5494,  5497,
    5497,  5500,  5500,  5503,  5504,  5505,  5506,  5507,  5508,  5509,
    5510,  5512,  5513,  5514,  5515,  5517,  5518,  5519,  5520,  5522,
    5523,  5524,  5525,  5526,  5527,  5528,  5529,  5533,  5539,  5547,
    5558,  5567,  5578,  5582,  5586,  5592,  5557,  5605,  5608,  5616,
    5628,  5630,  5635,  5643,  5653,  5656,  5660,  5668,  5634,  5677,
    5681,  5685,  5689,  5681,  5699,  5700,  5701,  5702,  5707,  5709,
    5712,  5716,  5719,  5726,  5731,  5732,  5733,  5738,  5739,  5745,
    5745,  5745,  5750,  5750,  5750,  5761,  5762,  5768,  5769,  5775,
    5776,  5781,  5782,  5783,  5787,  5790,  5796,  5799,  5807,  5808,
    5814,  5821,  5824,  5833,  5836,  5839,  5842,  5845,  5848,  5851,
    5858,  5861,  5868,  5871,  5877,  5880,  5887,  5890,  5897,  5898,
    5903,  5907,  5910,  5916,  5919,  5925,  5932,  5933,  5937,  5943,
    5946,  5953,  5954,  5961,  5964,  5969,  5980,  5981,  5982,  5983,
    5984,  5985,  5986,  5987,  5988,  5991,  5994,  6000,  6000,  6006,
    6006,  6017,  6031,  6033,  6031,  6040,  6044,  6050,  6058,  6068,
    6071,  6081,  6103,  6106,  6112,  6115,  6120,  6121,  6127,  6130,
    6139,  6143,  6149,  6159,  6159,  6164,  6164,  6168,  6172,  6173,
    6179,  6180,  6185,  6189,  6196,  6199,  6206,  6210,  6205,  6222,
    6226,  6233,  6237,  6237,  6250,  6254,  6254,  6269,  6271,  6273,
    6275,  6277,  6279,  6281,  6283,  6289,  6299,  6306,  6311,  6312,
    6316,  6318,  6319,  6322,  6323,  6324,  6327,  6332,  6339,  6340,
    6346,  6359,  6359,  6364,  6369,  6374,  6375,  6378,  6379,  6384,
    6389,  6393,  6398,  6399,  6403,  6410,  6414,  6415,  6420,  6422,
    6426,  6427,  6431,  6432,  6433,  6434,  6438,  6439,  6444,  6445,
    6450,  6451,  6456,  6457,  6462,  6467,  6468,  6473,  6474,  6478,
    6479,  6484,  6491,  6496,  6501,  6505,  6506,  6511,  6512,  6518,
    6520,  6525,  6526,  6532,  6535,  6538,  6545,  6547,  6559,  6564,
    6565,  6568,  6570,  6577,  6580,  6586,  6590,  6594,  6597,  6604,
    6611,  6616,  6620,  6621,  6627,  6630,  6641,  6648,  6654,  6657,
    6664,  6671,  6677,  6678,  6684,  6685,  6686,  6689,  6690,  6695,
    6695,  6699,  6707,  6708,  6711,  6714,  6719,  6720,  6725,  6728,
    6734,  6737,  6743,  6746,  6752,  6755,  6762,  6763,  6792,  6793,
    6798,  6802,  6807,  6810,  6813,  6816,  6822,  6823,  6827,  6827,
    6830,  6831,  6836,  6839,  6842,  6845,  6848,  6851,  6857,  6858,
    6859,  6860,  6861,  6863,  6865,  6866,  6871,  6874,  6878,  6884,
    6885,  6886,  6887,  6899,  6900,  6901,  6905,  6906,  6911,  6913,
    6914,  6915,  6917,  6918,  6919,  6920,  6922,  6923,  6925,  6926,
    6928,  6929,  6930,  6931,  6933,  6937,  6938,  6944,  6946,  6947,
    6948,  6949,  6954,  6958,  6962,  6966,  6967,  6971,  6972,  6979,
    6987,  6988,  6989,  6992,  6997,  7002,  7012,  7016,  7020,  7021,
    7022,  7023,  7025,  7027,  7029,  7031,  7034,  7037,  7041,  7042,
    7046,  7047,  7051,  7051,  7051,  7051,  7051,  7051,  7052,  7055,
    7060,  7060,  7060,  7060,  7060,  7060,  7062,  7065,  7071,  7071,
    7071,  7071,  7071,  7071,  7071,  7072,  7072,  7072,  7072,  7072,
    7072,  7072,  7074,  7075,  7078,  7087,  7087,  7092,  7092,  7098,
    7098,  7103,  7103,  7110,  7111,  7112,  7115,  7115,  7118,  7119,
    7120,  7125,  7128,  7134,  7137,  7145,  7158,  7159,  7156,  7175,
    7185,  7188,  7193,  7205,  7208,  7212,  7215,  7216,  7222,  7225,
    7226,  7235,  7244,  7249,  7250,  7251,  7252,  7260,  7263,  7269,
    7272,  7275,  7281,  7290,  7296,  7299,  7305,  7307,  7309,  7311,
    7313,  7315,  7317,  7319,  7321,  7323,  7325,  7327,  7329,  7331,
    7333,  7335,  7337,  7339,  7341,  7343,  7348,  7349,  7355,  7356,
    7359,  7368,  7372,  7379,  7379,  7383,  7383,  7388,  7388,  7392,
    7392,  7396,  7402,  7402,  7405,  7405,  7411,  7418,  7419,  7420,
    7424,  7425,  7428,  7429,  7433,  7439,  7449,  7450,  7458,  7459,
    7460,  7461,  7462,  7463,  7467,  7468,  7469,  7473,  7473,  7485,
    7486,  7490,  7491,  7492,  7496,  7503,  7588,  7600,  7600,  7604,
    7605,  7606,  7607,  7611,  7612,  7613,  7616,  7628,  7726,  7728,
    7730,  7732,  7736,  7741,  7743,  7745,  7747,  7751,  7754,  7759,
    7764,  7768,  7777,  7778,  7782,  7794,  7797,  7793,  7816,  7816,
    7820,  7821,  7824,  7825,  7826,  7827,  7828,  7829,  7830,  7835,
    7836,  7840,  7843,  7848,  7852,  7857,  7861,  7866,  7870,  7873,
    7877,  7880,  7885,  7889,  7900,  7906,  7906,  7907,  7908,  7915,
    7924,  7924,  7926,  7927,  7928,  7929,  7930,  7931,  7932,  7933,
    7934,  7935,  7936,  7937,  7938,  7939,  7940,  7941,  7942,  7943,
    7944,  7945,  7946,  7947,  7948,  7949,  7950,  7951,  7952,  7953,
    7954,  7955,  7956,  7957,  7958,  7959,  7960,  7961,  7962,  7963,
    7964,  7965,  7966,  7967,  7968,  7969,  7970,  7971,  7972,  7973,
    7974,  7975,  7976,  7977,  7978,  7979,  7980,  7981,  7982,  7983,
    7984,  7985,  7986,  7987,  7988,  7989,  7990,  7991,  7992,  7993,
    7994,  7995,  7996,  7997,  7998,  7999,  8000,  8001,  8002,  8003,
    8004,  8005,  8006,  8007,  8008,  8009
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "ALTER_TABLE", "CREATE_DATABASE", 
  "ADD_CONSTRAINT", "DROP_CONSTRAINT", "AS_STATIC", "NOT_FIELD_TOUCHED", 
  "LOCAL_FUNCTION", "EVERY_ROW", "ELIF", "DOUBLE_PRECISION", 
  "COUNT_MULTIPLY", "WAIT_FOR_KEY", "AT_TERMINATION_CALL", 
  "TO_MAIN_CAPTION", "CLEARSTAT", "TO_MENUITEM", "ID_TO_INT", 
  "TO_STATUSBOX", "ASCII_HEIGHT_ALL", "ASCII_WIDTH_ALL", 
  "IMPORT_DATATYPE", "UP_BY", "PAGE_TRAILER_SIZE", "PAGE_HEADER_SIZE", 
  "FIRST_PAGE_HEADER_SIZE", "BYTES_USE_AS_IMAGE", "BYTES_USE_AS_ASCII", 
  "DOWN_BY", "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", "LOCK_MODE_PAGE", 
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
  "disp_field_command", "@50", "@51", "@52", "error_cmd", "exit_prog_cmd", 
  "ext_cmd", "continue_cmd", "fgl_expr_c", "fgl_next", 
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
  "numeric_time_unit_small", "numeric_time_unit_big", "foreach_cmd", 
  "@66", "@67", "@68", "formhandler_def", "@69", "@70", 
  "op_input_section", "op_bef_ev_list", "bef_ev_list", "bef_ev", "@71", 
  "@72", "op_aft_ev_list", "aft_ev_list", "aft_ev", "@73", "@74", 
  "input_section", "input_sub_section", "in_variable_list", "in_id_list", 
  "in_bn_variable_list", "field_ops", "field_op", "@75", "@76", "@77", 
  "@78", "@79", "for_cmd", "@80", "@81", "for_step", "free_cmd", 
  "line_no", "file_name", "a_number", "coords", "display_coords", 
  "field_name", "cursor_name", "fetch_cursor_name", "win_name", 
  "open_win_name", "form_name", "open_form_name", "opt_help_no", 
  "identifier", "ident_or_var", "ident_p2", "var_or_string", "setident", 
  "unsetident", "field_name2", "cvariable", "real_number", 
  "reserved_word", "goto_cmd", "check_menu_cmd", "menu_item_list", 
  "menu_item", "uncheck_menu_cmd", "disable_cmd", "enable_cmd", 
  "msg_box_cmd", "@82", "op_disable_msg", "gm_disable_msg", 
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
  "@115", "menu_def", "@116", "@117", "menu_handler_elements", 
  "menu_handler_element", "@118", "@119", "menu_cmd", "@120", 
  "end_menu_command", "menu_block_command", "@121", "@122", "@123", 
  "menu_commands", "opt_key", "menu_opt_name", "menu_optional_desc", 
  "next_option_cmd", "show_option_cmd", "hide_option_cmd", "opt_name", 
  "opt_name_list", "menu_title", "message_cmd", "msg_next", "gui_message", 
  "msg_start", "@124", "op_msg_wait", "msg_wait", "variable", "var_int", 
  "varsetidentdot", "var", "assoc_var_read", "assoc_var_write", 
  "assoc_sub", "dot_part_var", "array_r_variable", "arr_subscripts", 
  "num_list", "num_list_element", "let_variable", "let_var", 
  "let_var_dot", "let_array_r_variable", "op_param_var_list", 
  "fparam_var_list", "ibind_var_list", "func_def_var", "ibind_var", 
  "obind_var_list", "obind_var", "obind_var_let_list", "obind_let_var", 
  "use_arr_var", "obind_var_list_ord", "obind_var_ord", 
  "optional_asc_desc", "array_r_varid", "init_bind_var_list", 
  "init_bind_var", "open_window_cmd", "op_at_statusbox", 
  "op_size_statusbox", "open_statusbox_cmd", "formhandler_name", 
  "open_form_cmd", "open_form_rest", "open_form_gui", "op_at_gui", 
  "op_like_gui", "op_absolute", "open_session_cmd", "open_cursor_cmd", 
  "user_details", "op_disable", "connect_cmd", "op_connect_as", 
  "con_user_details", "options_cmd", "opt_options", "opt_allopts", 
  "prepare_cmd", "var_or_char", "execute_cmd", "stmt_id", "prompt_cmd", 
  "@125", "gui_prompt_cmd", "opt_char", "prompt_key_sec", 
  "prompt_key_clause", "on_key_command_prompt", "@126", "prompt_title", 
  "put_cmd", "@127", "put_from", "put_val_list", "put_val", "start_cmd", 
  "rout", "rep_name", "op_values", "output_cmd", "finish_cmd", 
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
  "op_fgl_expr", "sleep_cmd", "update_statement_ss", "@156", "@157", 
  "where_upd_ss", "set_clause_list_ss", "upd_columns_ss", 
  "upd_column_name", "col_1_ss", "upd_col_list", "upd_val_list_ss", 
  "upd_val_ss", "rollback_statement", "insert_statement_ss", "@158", 
  "ins_2_ss", "@159", "op_insert_column_list", "insert_column_list", 
  "insert_value_list_ss", "insert_value_ss", "fetch_statement", "@160", 
  "@161", "fetch_part", "opt_into_fetch_part", "@162", 
  "opt_foreach_into_fetch_part", "@163", "fetch_place", 
  "delete_statement_position", "delete_statement_search_ss", 
  "order_by_clause", "sort_specification_list", "sort_specification", 
  "sort_spec", "op_asc_desc", "begin_statement", "commit_statement", 
  "op_exclusive", "set_database_cmd", "sql_cmd", "@164", "sql_commands", 
  "privilege_definition", "op_with_grant_option", "privileges", 
  "action_list", "action", "op_grant_column_list", "grant_column_list", 
  "grantee_list", "grantee", "view_definition_ss", "op_view_column_list", 
  "view_column_list", "op_with_check_option", 
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
  "correlation_name", "literal", "curr_v_clause", "curr_clause", 
  "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", "s_curr", "e_curr", 
  "dbase_name", "flush_cmd", "declare_cmd", "@165", "@166", "@167", 
  "@168", "curs_forupdate", "cur_update_list", "colident", 
  "cursor_specification_all_ss", "cursor_specification_sel_ss", 
  "select_statement_full_ss", "select_statement_ss", "@169", "@170", 
  "in_select_statement_ss", "select_statement2_ss", 
  "select_statement21_ss", "sel_p2_ss", "tmp_tabname", "opt_into_sel_ss", 
  "query_specification_ss", "subquery_ss", "op_ad", "select_list_ss", 
  "value_expression_pls_ss", "column_specification_ss", 
  "value_expression_ss", "value_expression_complex_ss", 
  "value_expr_list_ss", "value_specification", "unload_cmd", "load_cmd", 
  "opt_delim", "char_or_var", "opt_col_list", "col_list", 
  "simple_column_name", "ufile", "opt_use", "conn_id", "misc_sql", 
  "rename_stmt", "rentabname", "rencolname", "unlock_stmt", "lock_stmt", 
  "share_or_exclusive", "units_qual", "extend_qual", "sql_block_cmd", 
  "@171", "sql_block", "sql_block_entry", "in_var", "sql_block_into", 
  "var_ident", "var2", "var3", "aft_dot", "var_ident_ibind", 
  "whenever_cmd", "when_do", "label_goto", "function_name_when", 
  "while_cmd", "@172", "@173", "op_clr_fields", "op_to_defs", "clear_cmd", 
  "fld_list", "current_win_cmd", "window_type", "show_cmd", "op_mnfile", 
  "menu_name", "menu_handler", "hide_cmd", "move_cmd", "NAMED", 
  "commands", "all_commands", "command1", "commands_all", "@174", 
  "commands_all1", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,  1632,  1633,  1634,  1549,  1589,  1544,  1480,  1358,
    1466,  1462,  1376,  1539,  1275,  1333,  1407,  1575,  1562,  1495,
    1467,  1563,  1340,  1635,  1636,  1637,  1638,  1639,  1640,  1641,
    1642,  1643,  1644,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
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
    1267,  1268,  1269,  1270,  1271,  1272,  1273,  1274,  1276,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1334,  1335,  1336,  1337,  1338,
    1339,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1359,  1360,
    1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1375,  1377,  1378,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1408,  1409,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1463,
    1464,  1465,  1468,  1469,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1481,  1482,  1483,  1484,  1485,  1486,
    1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1496,  1497,
    1498,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,
    1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1540,  1541,  1542,  1543,  1545,  1546,  1547,  1548,  1550,
    1551,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,
    1561,  1564,  1565,  1566,  1567,  1568,  1569,  1570,  1571,  1572,
    1573,  1574,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1585,  1586,  1587,  1588,  1590,  1591,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   647,   648,   649,   650,   651,   652,   652,   653,   653,
     654,   655,   655,   655,   655,   655,   656,   656,   656,   656,
     656,   657,   657,   658,   658,   660,   659,   659,   661,   661,
     662,   662,   662,   662,   662,   662,   662,   662,   662,   662,
     662,   662,   662,   662,   662,   662,   663,   663,   665,   664,
     666,   666,   667,   667,   667,   667,   667,   667,   667,   667,
     667,   668,   669,   670,   669,   669,   669,   669,   669,   671,
     672,   669,   673,   674,   675,   669,   676,   677,   669,   678,
     679,   669,   680,   681,   682,   669,   683,   683,   684,   684,
     684,   685,   685,   686,   686,   687,   688,   688,   689,   689,
     691,   690,   692,   690,   693,   693,   694,   694,   695,   696,
     697,   696,   698,   699,   698,   701,   700,   703,   702,   704,
     704,   704,   704,   704,   704,   705,   706,   706,   707,   707,
     708,   709,   709,   710,   711,   713,   714,   712,   715,   715,
     716,   716,   717,   717,   718,   718,   718,   719,   719,   721,
     720,   722,   720,   723,   720,   724,   720,   725,   720,   726,
     726,   727,   727,   728,   728,   728,   728,   728,   728,   729,
     730,   730,   731,   731,   732,   732,   733,   733,   735,   736,
     734,   734,   734,   737,   737,   739,   738,   740,   740,   740,
     740,   740,   741,   740,   742,   742,   742,   742,   743,   744,
     744,   745,   745,   747,   746,   748,   746,   749,   749,   750,
     750,   751,   752,   752,   752,   753,   755,   754,   756,   754,
     757,   754,   758,   758,   759,   760,   761,   761,   763,   764,
     762,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   766,
     767,   768,   769,   769,   770,   772,   771,   773,   773,   773,
     773,   773,   773,   773,   775,   774,   776,   776,   777,   777,
     778,   780,   779,   781,   781,   781,   781,   781,   781,   781,
     782,   783,   783,   785,   784,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   787,   789,
     788,   790,   788,   792,   791,   793,   791,   794,   794,   795,
     796,   796,   797,   798,   798,   798,   798,   798,   798,   798,
     798,   799,   800,   801,   803,   804,   802,   805,   805,   806,
     807,   807,   808,   808,   810,   809,   811,   809,   812,   809,
     813,   813,   814,   814,   815,   815,   815,   815,   815,   815,
     815,   815,   815,   816,   816,   816,   816,   816,   816,   816,
     816,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   818,   818,   818,   818,   818,   818,   818,   818,   818,
     818,   819,   819,   820,   820,   821,   821,   822,   822,   823,
     823,   824,   825,   825,   826,   826,   826,   826,   826,   826,
     827,   827,   828,   828,   828,   828,   829,   829,   830,   831,
     831,   831,   832,   831,   833,   833,   834,   834,   835,   835,
     835,   835,   836,   836,   837,   837,   837,   837,   837,   837,
     837,   837,   838,   839,   840,   840,   840,   840,   840,   840,
     841,   841,   841,   841,   841,   841,   841,   842,   844,   845,
     843,   846,   847,   843,   849,   850,   848,   851,   852,   848,
     853,   854,   848,   855,   856,   848,   848,   848,   848,   848,
     857,   857,   858,   859,   859,   859,   859,   859,   859,   859,
     859,   859,   860,   860,   861,   861,   861,   861,   862,   862,
     862,   863,   863,   864,   864,   864,   865,   865,   865,   865,
     865,   865,   865,   865,   865,   865,   866,   866,   868,   869,
     870,   867,   872,   873,   871,   874,   874,   875,   875,   876,
     876,   878,   877,   879,   877,   880,   880,   881,   881,   883,
     882,   884,   882,   885,   886,   886,   886,   887,   887,   888,
     888,   889,   889,   890,   890,   892,   891,   893,   891,   894,
     891,   895,   891,   896,   891,   898,   899,   897,   900,   900,
     901,   902,   902,   902,   902,   902,   902,   903,   903,   904,
     905,   906,   907,   907,   907,   907,   907,   907,   907,   907,
     908,   909,   910,   911,   912,   913,   914,   914,   915,   916,
     917,   917,   918,   918,   919,   920,   921,   921,   921,   921,
     921,   921,   922,   923,   923,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   925,   926,
     927,   927,   928,   929,   930,   930,   930,   931,   931,   931,
     933,   932,   934,   934,   935,   935,   936,   936,   937,   938,
     938,   939,   940,   940,   941,   942,   942,   943,   944,   944,
     946,   945,   947,   948,   947,   949,   950,   947,   951,   952,
     954,   953,   953,   955,   955,   956,   956,   957,   957,   958,
     958,   959,   959,   961,   960,   962,   960,   963,   960,   964,
     960,   965,   960,   966,   960,   967,   960,   968,   960,   969,
     960,   970,   970,   971,   971,   972,   972,   973,   973,   974,
     974,   975,   975,   976,   977,   978,   978,   978,   980,   979,
     981,   981,   982,   981,   983,   984,   984,   984,   984,   985,
     985,   987,   986,   986,   989,   988,   990,   992,   991,   993,
     993,   994,   994,   996,   995,   997,   997,   997,   997,   997,
     997,   997,   997,   997,   997,   997,   997,   997,   997,   997,
     997,   997,   998,  1000,  1001,   999,  1002,  1002,  1003,  1004,
    1005,  1006,  1006,  1008,  1007,  1009,  1009,  1010,  1010,  1011,
    1011,  1011,  1011,  1012,  1012,  1013,  1013,  1014,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1016,
    1016,  1017,  1017,  1017,  1018,  1019,  1019,  1021,  1022,  1023,
    1024,  1020,  1025,  1027,  1028,  1026,  1029,  1030,  1030,  1031,
    1032,  1033,  1033,  1034,  1034,  1034,  1036,  1035,  1037,  1037,
    1039,  1040,  1041,  1038,  1043,  1044,  1042,  1045,  1045,  1047,
    1046,  1048,  1046,  1050,  1049,  1051,  1053,  1052,  1054,  1052,
    1055,  1052,  1056,  1056,  1057,  1057,  1058,  1058,  1059,  1059,
    1059,  1060,  1061,  1062,  1063,  1063,  1063,  1064,  1064,  1065,
    1065,  1066,  1067,  1067,  1067,  1067,  1068,  1068,  1068,  1068,
    1068,  1070,  1069,  1071,  1071,  1072,  1073,  1074,  1074,  1075,
    1076,  1076,  1076,  1076,  1076,  1077,  1078,  1079,  1079,  1080,
    1080,  1081,  1082,  1082,  1083,  1083,  1084,  1085,  1086,  1086,
    1086,  1086,  1086,  1087,  1087,  1088,  1089,  1089,  1090,  1090,
    1091,  1091,  1092,  1092,  1093,  1093,  1093,  1093,  1093,  1094,
    1094,  1095,  1095,  1096,  1096,  1097,  1098,  1099,  1099,  1100,
    1101,  1101,  1101,  1102,  1103,  1103,  1104,  1104,  1105,  1106,
    1106,  1107,  1107,  1108,  1109,  1110,  1111,  1111,  1112,  1113,
    1113,  1114,  1114,  1115,  1115,  1116,  1117,  1117,  1118,  1118,
    1118,  1118,  1119,  1119,  1119,  1120,  1121,  1121,  1122,  1122,
    1122,  1123,  1124,  1124,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1125,  1125,  1125,  1125,  1125,  1126,  1127,  1127,  1128,
    1128,  1129,  1131,  1130,  1132,  1133,  1133,  1134,  1134,  1135,
    1135,  1137,  1136,  1138,  1140,  1139,  1141,  1141,  1142,  1142,
    1143,  1143,  1144,  1144,  1144,  1144,  1145,  1145,  1146,  1147,
    1147,  1148,  1149,  1150,  1151,  1151,  1152,  1152,  1154,  1153,
    1155,  1153,  1156,  1153,  1157,  1153,  1158,  1153,  1159,  1153,
    1160,  1153,  1161,  1161,  1161,  1161,  1161,  1161,  1163,  1162,
    1164,  1164,  1166,  1165,  1165,  1165,  1165,  1165,  1167,  1167,
    1168,  1168,  1169,  1170,  1170,  1171,  1172,  1173,  1174,  1174,
    1174,  1175,  1175,  1175,  1175,  1176,  1177,  1177,  1178,  1178,
    1179,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1181,
    1181,  1182,  1182,  1183,  1183,  1183,  1183,  1183,  1183,  1183,
    1183,  1183,  1183,  1184,  1184,  1185,  1185,  1185,  1185,  1186,
    1186,  1187,  1187,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1189,  1189,  1189,
    1191,  1192,  1193,  1194,  1195,  1196,  1190,  1197,  1197,  1198,
    1199,  1199,  1201,  1202,  1203,  1204,  1205,  1206,  1200,  1207,
    1209,  1210,  1211,  1208,  1212,  1212,  1212,  1212,  1213,  1213,
    1213,  1213,  1213,  1214,  1215,  1215,  1215,  1216,  1216,  1218,
    1219,  1217,  1220,  1221,  1217,  1222,  1222,  1223,  1223,  1224,
    1224,  1225,  1225,  1225,  1226,  1226,  1227,  1227,  1228,  1228,
    1229,  1230,  1230,  1231,  1231,  1231,  1231,  1231,  1231,  1231,
    1232,  1232,  1233,  1233,  1234,  1234,  1235,  1235,  1236,  1236,
    1237,  1238,  1238,  1239,  1239,  1240,  1241,  1241,  1242,  1243,
    1243,  1244,  1244,  1245,  1245,  1246,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1247,  1248,  1248,  1249,
    1249,  1250,  1252,  1253,  1251,  1254,  1254,  1254,  1255,  1255,
    1255,  1255,  1256,  1256,  1257,  1258,  1259,  1259,  1260,  1260,
    1261,  1261,  1262,  1264,  1263,  1266,  1265,  1265,  1267,  1267,
    1268,  1268,  1269,  1269,  1270,  1270,  1272,  1273,  1271,  1274,
    1274,  1275,  1276,  1275,  1277,  1278,  1277,  1279,  1279,  1279,
    1279,  1279,  1279,  1279,  1279,  1280,  1281,  1282,  1283,  1283,
    1284,  1285,  1285,  1286,  1286,  1286,  1287,  1288,  1289,  1289,
    1290,  1292,  1291,  1293,  1293,  1293,  1293,  1293,  1293,  1293,
    1293,  1293,  1293,  1293,  1293,  1294,  1295,  1295,  1296,  1296,
    1297,  1297,  1298,  1298,  1298,  1298,  1299,  1299,  1300,  1300,
    1301,  1301,  1302,  1302,  1303,  1304,  1304,  1305,  1305,  1306,
    1306,  1307,  1308,  1309,  1310,  1311,  1311,  1312,  1312,  1313,
    1313,  1314,  1314,  1315,  1315,  1315,  1316,  1316,  1317,  1318,
    1318,  1319,  1319,  1320,  1320,  1321,  1321,  1321,  1321,  1322,
    1323,  1324,  1325,  1325,  1326,  1326,  1327,  1328,  1329,  1329,
    1330,  1331,  1332,  1332,  1333,  1333,  1333,  1334,  1334,  1335,
    1335,  1336,  1337,  1337,  1338,  1338,  1339,  1339,  1340,  1340,
    1341,  1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,
    1346,  1347,  1348,  1348,  1348,  1348,  1349,  1349,  1350,  1350,
    1351,  1351,  1352,  1352,  1352,  1352,  1352,  1352,  1353,  1353,
    1353,  1353,  1353,  1353,  1353,  1353,  1354,  1354,  1354,  1355,
    1355,  1355,  1355,  1356,  1356,  1356,  1357,  1357,  1358,  1358,
    1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,
    1358,  1358,  1358,  1358,  1358,  1359,  1359,  1360,  1360,  1360,
    1360,  1360,  1361,  1362,  1363,  1364,  1364,  1364,  1364,  1365,
    1366,  1366,  1366,  1367,  1367,  1367,  1368,  1369,  1369,  1369,
    1369,  1369,  1369,  1369,  1369,  1369,  1370,  1371,  1372,  1372,
    1373,  1373,  1374,  1374,  1374,  1374,  1374,  1374,  1374,  1374,
    1375,  1375,  1375,  1375,  1375,  1375,  1375,  1375,  1376,  1376,
    1376,  1376,  1376,  1376,  1376,  1377,  1377,  1377,  1377,  1377,
    1377,  1377,  1378,  1378,  1379,  1381,  1380,  1382,  1380,  1383,
    1380,  1384,  1380,  1385,  1385,  1385,  1386,  1386,  1387,  1387,
    1387,  1388,  1388,  1389,  1389,  1390,  1392,  1393,  1391,  1394,
    1395,  1395,  1396,  1397,  1397,  1397,  1397,  1397,  1398,  1399,
    1399,  1400,  1401,  1402,  1402,  1402,  1402,  1403,  1403,  1404,
    1404,  1404,  1405,  1406,  1406,  1406,  1407,  1407,  1407,  1407,
    1407,  1407,  1407,  1407,  1407,  1407,  1407,  1407,  1407,  1407,
    1407,  1407,  1407,  1407,  1407,  1407,  1408,  1408,  1409,  1409,
    1410,  1411,  1411,  1412,  1412,  1413,  1413,  1414,  1414,  1415,
    1415,  1416,  1417,  1417,  1418,  1418,  1419,  1420,  1420,  1420,
    1421,  1421,  1422,  1423,  1424,  1425,  1426,  1426,  1427,  1427,
    1427,  1427,  1427,  1427,  1428,  1428,  1428,  1430,  1429,  1431,
    1431,  1432,  1432,  1432,  1433,  1434,  1435,  1436,  1436,  1437,
    1437,  1437,  1437,  1438,  1438,  1438,  1439,  1439,  1440,  1440,
    1440,  1440,  1440,  1440,  1440,  1440,  1440,  1441,  1441,  1441,
    1441,  1441,  1442,  1442,  1443,  1445,  1446,  1444,  1447,  1447,
    1448,  1448,  1449,  1449,  1449,  1449,  1449,  1449,  1449,  1450,
    1450,  1451,  1451,  1452,  1452,  1453,  1453,  1454,  1454,  1455,
    1456,  1457,  1458,  1458,  1459,  1460,  1460,  1461,  1462,  1462,
    1464,  1463,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,  1465,
    1465,  1465,  1465,  1465,  1465,  1465
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
       2,     2,     3,     0,     7,     4,     6,     1,     6,     0,
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
       4,     5,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
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
       6,     3,     5,     5,     3,     1,     1,     3,     0,     0,
       0,     8,     0,     0,    10,     0,     1,     0,     1,     1,
       2,     0,     3,     0,     3,     0,     1,     1,     2,     0,
       3,     0,     3,     3,     1,     4,     3,     1,     3,     1,
       3,     1,     3,     1,     2,     0,     3,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     0,    11,     0,     2,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     6,     4,     3,     6,     3,     6,
       1,     1,     1,     1,     1,     1,     0,     2,     3,     3,
       1,     4,     1,     1,     0,     0,     1,     4,     3,     6,
       3,     6,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     3,     1,     2,     2,     2,     4,     2,     2,     4,
       0,     8,     0,     1,     1,     1,     0,     1,     2,     0,
       1,     2,     0,     1,     2,     0,     1,     3,     0,     2,
       0,     7,     0,     0,     3,     0,     0,     7,     5,     2,
       0,     5,     4,     1,     3,     3,     3,     0,     2,     0,
       1,     1,     2,     0,     4,     0,     4,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     3,     2,     4,     1,     1,     1,     0,     4,
       5,     6,     0,    10,     3,     1,     1,     2,     2,     0,
       2,     0,     3,     1,     0,     3,     2,     0,     3,     1,
       3,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     0,     7,     1,     1,     2,     2,
       2,     3,     4,     0,     3,     0,     1,     1,     2,     1,
       1,     1,     1,     0,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     1,     1,     1,     1,     0,     0,     0,
       0,    13,     1,     0,     0,     6,     2,     1,     2,     2,
       1,     1,     2,     1,     1,     1,     0,     3,     2,     1,
       0,     0,     0,    14,     0,     0,     7,     1,     2,     0,
       3,     0,     4,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     1,     1,     1,     1,     2,     3,
       2,     5,     1,     1,     1,     4,     4,     1,     1,     1,
       1,     2,     3,     6,     1,     3,     1,     1,     1,     4,
       7,     1,     1,     1,     1,     2,     0,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     2,
       0,     1,     1,     4,     1,     3,     1,     3,     7,     0,
       7,     0,     6,     3,     1,     3,     1,     2,     5,     0,
       7,     0,     2,     0,     1,     5,     2,     5,     0,     5,
       6,     4,     0,     1,     1,     4,     0,     2,     0,     5,
       4,     2,     1,     3,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     5,     1,     1,     2,
       4,     1,     0,    10,     5,     0,     1,     0,     2,     1,
       2,     0,     3,     1,     0,     4,     0,     2,     1,     3,
       1,     1,     3,     4,     4,     2,     1,     1,     1,     0,
       1,     7,     2,     2,     2,     2,     1,     2,     0,     3,
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
       1,     2,     0,     0,     7,     0,     2,     2,     7,     1,
       5,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     0,     5,     0,     5,     1,     0,     3,
       1,     3,     1,     3,     1,     1,     0,     0,     5,     2,
       1,     0,     0,     3,     0,     0,     3,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     3,     3,     1,     3,
       2,     1,     1,     0,     1,     1,     1,     1,     0,     1,
       3,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     0,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     0,     3,     1,     3,
       1,     3,     1,     1,     6,     0,     3,     1,     3,     0,
       1,     4,     5,     2,     1,     1,     4,     1,     3,     4,
       4,     1,     3,     1,     1,     1,     2,     1,     4,     0,
       1,     0,     1,     1,     2,     1,     1,     1,     4,     3,
       1,     1,     1,     2,     1,     1,     2,     2,     1,     3,
       2,     2,     1,     3,     1,     2,     4,     1,     2,     1,
       3,     4,     0,     1,     0,     1,     0,     1,     1,     3,
       1,     3,     1,     2,     1,     3,     2,     2,     0,     2,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       0,     1,     3,     3,     3,     6,     5,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     4,     5,     1,
       5,     5,     1,     1,     1,     4,     1,     4,     1,     7,
       1,     1,     1,     4,     6,     0,     2,     4,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     3,     1,
       0,     3,     5,     2,     5,     4,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     0,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     8,     0,     9,     0,
       7,     0,     9,     0,     1,     2,     1,     3,     1,     3,
       5,     1,     1,     1,     1,     2,     0,     0,     8,     5,
       1,     1,     7,     0,     3,     1,     3,     4,     1,     0,
       2,     5,     7,     0,     1,     1,     1,     1,     3,     1,
       2,     2,     1,     1,     1,     1,     3,     2,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     5,     5,     5,
       5,     5,     4,     4,     3,     4,     1,     3,     0,     1,
       5,     7,     5,     0,     2,     1,     1,     0,     3,     1,
       3,     1,     1,     1,     0,     3,     1,     1,     1,     1,
       4,     6,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     4,     0,     4,     1,
       2,     1,     1,     1,     2,     2,     1,     2,     1,     1,
       1,     3,     5,     1,     1,     1,     1,     3,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     1,     3,     2,
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
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     815,     0,   614,     0,     0,     0,     0,     0,     0,     0,
    1751,     0,   614,   614,   866,   178,   839,   844,   176,   181,
     819,     0,   813,   816,   817,   820,   822,   865,   821,   860,
     861,   863,   182,   133,   130,     0,   126,   128,   127,   131,
     709,     0,  1757,   614,   614,  1760,     0,  1756,  1753,  1750,
    1748,  1749,  1755,  1754,  1752,   293,  1613,  1612,   859,   174,
     185,   177,   182,     1,   823,   818,   864,   862,   840,   125,
     129,   132,  1794,   615,  1764,  1761,   614,  1762,  1759,   614,
       0,   587,   614,     0,   175,   869,   933,   588,   867,   622,
     926,   614,   927,   934,   932,   185,   179,   198,   614,   183,
     199,   228,   846,  1212,   614,   614,   845,   134,  1200,   853,
     614,   614,   836,   838,   835,   837,   814,   824,   825,   847,
     828,   829,   830,   833,   831,   832,   834,   608,  1763,  1758,
       0,   928,   868,   614,   614,   941,   939,   940,   930,     0,
     291,   185,  1136,   192,   186,   185,   191,   225,     0,   614,
       0,     0,   614,   174,   532,   874,   826,   614,   325,   311,
     201,   262,   281,   302,   304,   301,     0,   323,     0,   310,
     303,   307,   313,   297,   312,   185,   314,   294,   317,   295,
     296,   938,   937,     0,    21,    22,    13,   614,   946,     0,
      15,     0,   944,   614,   929,   292,   614,   184,  1137,   180,
       0,   198,   200,   258,   252,   253,   241,   218,   249,   201,
     220,   262,   281,   239,   242,   237,     0,   216,     0,   248,
     240,   245,   251,   233,   250,   185,   254,   185,   231,   232,
     229,   257,     0,     0,   614,     0,   854,   174,   174,     0,
     614,   202,     0,   315,     0,     0,   316,     0,     0,     0,
       0,   614,     0,     0,     0,   260,     0,   935,     0,    16,
      17,    19,    18,    20,   614,    14,   614,   942,     0,   623,
     187,   190,     0,   188,   189,     0,   195,   194,   193,   196,
     185,     0,   185,   255,   256,     0,     0,   185,     0,     0,
       0,     0,   238,   226,  1213,     0,     0,  1201,  1800,   533,
     875,   848,     0,   207,   208,     0,   274,   276,   271,   272,
     268,   270,   267,   269,   266,     0,   276,   287,   288,   284,
     286,   283,   285,   278,     0,     0,     0,   327,     0,   330,
     332,   215,     0,   214,     0,     0,   185,    11,    12,   945,
     614,   931,   624,   197,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   185,   227,   230,   614,   708,   870,   614,
       0,  1798,  1800,  1136,  1704,   841,     0,   614,     0,     0,
     263,     0,     0,   273,   290,   264,   289,     0,   282,     0,
     305,     0,   299,   614,   324,   614,   329,   319,     0,     0,
     308,   298,   261,   318,     0,     0,     0,     0,     0,   243,
       0,   235,   217,   203,     0,   246,   234,   259,   962,     0,
     957,   958,   614,     0,   855,  1799,  1797,   614,   614,   614,
     614,   614,   614,   614,  1781,   614,  1302,  1301,   614,  1303,
     614,   377,  1300,  1242,   614,     5,  1299,   378,   375,   614,
     380,   172,   467,  1114,     0,     0,  1309,   122,   374,   373,
    1234,   368,   614,  1259,  1772,   614,   379,   344,   614,     3,
       2,   614,   376,  1239,   614,   614,   369,   366,   362,   614,
     614,   614,   614,   614,  1297,   372,   614,   614,   614,   614,
     614,   614,   614,   614,  1296,   614,   614,   614,   173,  1236,
     365,   364,   614,   614,  1776,  1775,   614,   614,   614,   135,
    1235,   371,   370,   614,   614,   367,   921,   467,   614,   528,
       0,   614,   614,   467,   614,   614,   614,   467,   802,  1210,
     614,   614,  1118,   614,  1765,   614,   102,   614,   614,   883,
     614,   614,   614,   614,   803,   614,   614,  1727,   614,     0,
     614,   614,   614,   614,   614,   614,   614,   680,   614,   614,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,   912,  1849,  1850,
    1851,  1852,  1853,  1854,  1855,  1856,  1857,  1858,  1859,  1860,
    1861,  1862,  1863,  1864,  1105,  1107,  1102,  1104,  1103,  1106,
    1865,  1866,  1233,  1867,  1238,  1237,  1868,  1869,  1870,  1871,
    1872,  1873,  1874,  1875,  1876,  1877,  1381,  1878,  1879,  1880,
    1881,  1882,  1883,  1884,  1885,  1801,   842,   537,   843,   614,
     879,     0,   877,     0,   326,   209,   210,     0,   275,   280,
       0,     0,     0,     0,   328,   331,     0,   213,     0,   943,
     219,     0,   185,     0,     0,     0,     0,   614,  1214,   614,
       0,  1202,     0,  1246,     0,   827,  1774,   602,   121,     0,
     614,  1740,  1739,  1016,  1736,  1738,  1789,     0,  1253,     0,
    1249,  1258,     7,     0,     6,   614,  1782,  1078,  1079,   614,
    1170,  1169,  1117,  1168,  1116,   614,   614,   422,   424,     0,
    1207,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,  1580,     0,     0,     0,   416,   614,   614,     0,     0,
     415,   614,     0,   432,     0,   503,     0,     0,     0,     0,
       0,   614,     0,   411,  1310,     0,   382,   381,   388,   428,
     425,   383,   501,   493,   384,   386,   500,   387,   933,   423,
     426,   431,  1298,   502,  1706,  1304,   123,   614,  1082,   120,
     614,   809,    23,   604,   363,     0,   808,  1075,   810,     0,
    1308,   905,   904,   907,   903,   906,  1791,     0,   901,     0,
     603,   989,   902,  1785,     0,  1773,   119,   986,   710,   984,
       0,   600,  1768,   756,   755,     0,   757,   592,   753,     0,
     614,   999,   605,  1378,   614,   614,  1051,  1049,   614,  1043,
    1045,  1044,  1042,  1041,   614,   614,   614,  1040,   614,   783,
     614,   614,     0,     0,     0,     0,   614,   614,     0,     0,
       0,  1030,  1021,  1022,     0,  1063,   409,    23,   856,   401,
    1779,     0,  1770,   124,   601,   614,  1048,  1047,  1211,  1209,
    1135,     0,  1695,  1696,  1136,  1224,  1136,  1119,  1120,  1123,
    1138,  1311,   614,     0,     0,     0,     0,   614,     0,   614,
       0,    61,     0,   933,     0,    67,     0,   100,   580,   668,
     614,  1108,  1006,  1112,     0,   614,  1064,  1228,     0,     0,
    1115,   672,   669,   670,     0,   674,   675,     0,   677,   678,
     614,   673,   966,   968,   614,   614,   967,   758,   964,   719,
     960,   925,     0,   614,   614,     0,   684,   685,     0,     0,
     923,   919,   920,   916,   917,   918,   911,   915,   914,   614,
     614,   614,   614,   614,     0,   541,   543,   535,   538,   539,
     881,  1800,   876,   878,   849,     0,   277,   279,   306,   300,
       0,     0,   309,     0,   224,     0,   222,   244,   236,   228,
     247,   963,   174,   959,   871,   174,     0,   614,     0,  1286,
    1287,   614,   614,   614,  1260,  1261,  1263,  1264,  1265,  1269,
    1268,  1266,  1267,     0,   615,   610,   614,  1737,   614,   614,
    1018,   614,   614,  1252,  1251,   614,  1245,     0,  1556,  1557,
       0,  1080,     0,    23,  1165,  1167,  1166,   390,   389,   614,
     614,  1142,   614,   614,   614,   614,     0,   614,     0,     0,
     614,   430,  1588,  1586,  1587,  1583,  1585,  1582,  1584,  1576,
       0,   614,     0,   614,     0,   429,     0,   614,   507,   506,
       0,     0,   477,   474,   483,   614,   480,   614,   614,   414,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   163,   164,   165,
     166,   167,   168,   508,   509,   510,   443,   614,   614,   442,
     452,     0,   614,   394,   614,     0,   395,   385,   391,   393,
     396,   397,   398,   399,   400,   392,   421,   420,   468,   614,
     614,   976,     0,     0,   349,    24,   343,   614,   614,  1072,
     614,   614,   614,   614,   614,   614,     0,   993,  1705,   614,
     614,   185,     0,   614,   614,  1770,   614,   614,   614,   614,
     614,   136,     0,   614,  1003,   995,   996,  1001,  1379,  1380,
     922,   333,   407,   614,   529,   585,   584,   582,  1024,   586,
    1029,  1025,  1028,   776,     0,  1026,  1027,   777,  1034,  1038,
    1031,  1032,  1036,  1037,  1035,  1033,  1039,     0,   811,   614,
     614,     0,   404,   405,   402,   403,   614,     0,     0,   766,
     765,   764,  1771,  1778,    23,  1131,  1132,  1133,  1134,  1128,
    1126,  1225,  1140,  1125,  1121,   614,     0,  1122,  1766,   614,
       0,   614,   614,    96,     0,    97,   614,     0,   614,    72,
     614,   614,   614,   109,   104,     0,   910,     0,   909,     0,
     467,  1110,   614,   951,   952,   975,   947,   948,   804,   973,
    1066,  1230,   614,  1232,  1231,  1731,   614,   614,     0,  1729,
    1732,  1733,   700,   614,   614,   614,   689,   719,   719,   717,
     614,   614,   720,     0,    25,   688,   691,     0,   698,   694,
     924,   913,  1702,  1703,  1693,  1693,     0,     0,  1614,   614,
     185,  1332,   614,   614,  1333,  1376,   185,   614,  1377,   614,
    1653,   614,  1346,     0,  1394,  1392,  1391,  1390,  1388,  1389,
    1387,  1385,  1382,  1455,  1454,  1383,  1384,  1393,  1623,  1386,
    1709,  1708,  1707,  1800,  1800,   554,   545,   536,     0,   540,
    1800,   880,   174,     0,   320,   212,     0,   185,   221,   204,
    1215,   174,  1203,  1446,   614,  1445,     0,     0,  1447,  1289,
       0,  1295,  1291,  1288,     0,     0,   614,     0,     0,     0,
    1285,  1281,  1435,  1434,  1433,  1257,  1256,   614,  1280,  1276,
     614,  1272,  1270,     0,   614,   609,     0,     0,  1017,   614,
       0,  1015,  1743,  1745,  1744,  1741,  1790,  1787,  1250,   614,
     614,   614,  1243,   467,   341,     0,  1208,     0,     0,     0,
       0,  1653,     0,     0,     0,     0,     0,   525,   511,   516,
       0,   512,   515,   514,     0,     0,     0,     0,     0,     0,
     417,     0,   170,     0,   433,   614,   614,   614,     0,   614,
       0,     0,     0,   435,   434,   453,   444,   459,   462,   463,
     460,   466,   465,   464,   454,   455,   457,   456,   458,   445,
     449,   467,   461,   448,   467,    91,     0,   427,   614,  1240,
    1008,  1076,  1077,  1074,  1073,     0,   908,     0,     0,   589,
       0,     0,   614,   987,   985,     0,   712,   713,     0,     0,
    1769,  1777,     0,     0,   596,     0,   598,   754,     0,   140,
     614,   997,  1004,     0,   614,  1012,   614,   336,   614,   614,
     614,   614,    23,  1050,  1354,     0,     0,   801,   788,   799,
     800,   786,   787,   795,   790,   794,   789,   798,   793,   796,
     792,   797,   785,   791,   784,   783,  1023,   812,   410,   614,
    1055,   614,  1780,   767,   768,   360,   614,  1136,   614,  1139,
    1124,  1800,     0,     0,     0,     0,   614,     0,   614,    62,
      91,     0,     0,   115,   110,     0,   105,   614,   112,   106,
     894,   886,   892,     0,  1109,   614,  1111,  1113,     0,   614,
     955,     0,   614,     0,   614,  1065,  1229,  1746,  1734,   971,
    1735,   969,  1728,  1730,  1800,   671,   676,   679,   692,   690,
     606,     0,   614,   614,   735,   773,   733,   729,   727,   771,
       0,     0,   759,     0,   721,   731,   965,   961,   614,     0,
       0,     0,   697,   614,   614,   614,   614,     0,     0,   614,
    1559,     0,  1450,  1451,  1714,  1415,  1472,   614,     0,  1712,
       0,     0,  1655,  1656,  1654,   614,  1312,   614,  1398,  1404,
    1403,  1402,  1406,     0,  1399,  1400,   614,  1624,  1635,   542,
     544,   614,     0,   557,   549,   551,     0,   546,   547,   614,
     614,   565,   567,   614,     0,   563,   882,   850,   211,     0,
       0,   223,  1171,   872,  1149,  1423,  1425,     0,  1293,   614,
       0,   614,   614,     0,  1283,   614,   614,  1551,  1549,  1536,
    1538,  1534,     0,  1533,     0,  1542,  1529,  1550,     0,  1541,
    1526,  1532,  1548,  1540,  1439,  1523,  1524,  1525,     0,  1278,
    1274,     0,   614,  1262,   613,     0,   612,   614,   983,     0,
     614,   614,  1786,     4,     8,    10,  1555,  1558,   614,   467,
     499,   496,   495,   498,   494,   614,   419,   505,   490,   490,
       0,   513,     0,   517,     0,   281,  1207,     0,  1581,   497,
    1207,   504,   418,   265,     0,  1207,   478,   475,   484,  1207,
     481,  1207,  1207,  1207,     0,     0,     0,   614,     0,     0,
     614,     0,   469,    92,    93,    95,   471,     0,   614,   614,
    1005,   614,   614,   614,   614,   614,     0,   614,   185,   711,
     614,   593,   595,   614,   614,   157,   155,   614,   614,   137,
       0,   147,   153,   719,   142,   144,   614,  1002,  1013,  1014,
       0,   408,   335,   340,   591,   334,   614,   337,   342,  1355,
     530,   583,   581,   783,   778,   779,  1054,  1056,   614,   406,
     361,  1129,  1127,  1226,  1227,     0,    65,  1220,     0,     0,
       0,    98,     0,     0,    73,    79,    69,  1800,  1800,   108,
     103,   117,   113,     0,   107,   774,   895,   606,  1800,   885,
     884,   893,  1007,   614,     0,   614,   974,   467,     0,     0,
    1675,  1567,  1570,  1676,  1578,  1568,  1673,   614,     0,  1071,
    1672,     0,     0,  1674,     0,     0,     0,     0,  1740,  1569,
    1067,  1068,  1671,  1575,  1665,  1070,  1663,  1664,   614,   614,
     614,   702,   695,   693,     0,    23,   614,   749,   723,   751,
     725,  1800,  1800,  1800,  1800,   783,   744,   743,   739,   741,
     748,   747,   737,   745,   718,   722,  1800,   606,    45,    43,
      40,    34,    38,    42,    37,    30,    39,    33,    36,    31,
      41,    32,    44,    35,     0,    28,     0,   699,  1694,   614,
    1692,   614,  1690,  1640,  1641,  1633,  1619,  1634,     0,     0,
     614,  1046,  1449,  1452,   614,     0,   614,   614,  1473,  1366,
    1338,  1717,  1716,  1715,   614,   614,  1636,  1657,  1659,     0,
    1361,   614,  1360,   614,  1362,  1357,  1358,  1359,  1350,  1347,
     614,   614,  1405,   614,     0,     0,  1628,  1625,  1626,   556,
     561,   614,   614,  1800,  1800,   534,   548,   571,   559,   573,
    1800,  1800,   569,   553,   564,   841,   321,   205,     0,  1197,
    1216,   841,     0,  1204,  1197,   614,     0,  1290,     0,   614,
       0,   614,     0,  1478,  1480,  1482,  1518,  1517,  1516,  1484,
    1500,  1292,  1560,     0,  1424,   614,  1427,     0,  1431,   614,
    1282,     0,     0,  1604,  1602,  1603,  1599,  1601,  1598,  1600,
       0,     0,     0,     0,     0,     0,     0,     0,  1437,     0,
    1440,  1441,   614,  1277,   614,  1271,  1273,   611,  1742,   614,
       0,  1788,   614,     0,  1254,   614,     0,     0,   487,     0,
     488,     0,   527,     0,   524,   521,   492,   486,  1145,  1589,
    1144,     0,   169,  1143,     0,     0,     0,  1146,     0,  1148,
    1147,  1141,   446,   447,   451,   436,     0,   439,   450,     0,
     438,     0,   614,    91,     0,     0,   614,     0,  1305,  1793,
    1792,   590,   614,     0,    46,   614,   716,   715,   714,  1306,
     614,     0,   719,  1800,  1800,   149,   616,   159,   151,   161,
     141,   148,  1800,   614,     0,   614,     0,   614,     0,   614,
    1800,     0,   781,   606,   614,  1767,    91,   614,    63,   614,
     614,   614,    76,     0,    91,    91,   116,   111,  1800,  1800,
     101,   783,   896,   890,   898,   897,   887,   578,   936,   953,
     954,   949,   614,  1572,  1571,  1574,  1573,  1577,     0,   614,
       0,   614,  1519,   614,  1519,  1519,  1519,  1519,   614,   614,
     614,   614,   614,   614,  1718,  1719,  1720,  1721,  1722,  1723,
    1667,  1747,   972,   970,   705,   703,     0,   682,   696,   607,
     760,     0,   614,  1800,   614,  1800,   736,   734,   730,   728,
     772,     0,  1800,     0,  1800,   732,    23,     0,    26,     0,
    1697,  1653,  1623,   614,   614,  1632,  1615,  1631,  1453,     0,
    1417,     0,  1365,  1460,   614,     0,  1713,     0,  1710,   614,
    1649,   646,   631,   644,   650,   665,   630,   642,   625,   658,
     661,   664,   628,   659,   637,   641,   652,   663,   660,   662,
     653,   635,   633,   657,   639,   638,   626,   627,   629,   632,
     643,   655,   634,   667,   645,   649,   651,   666,   640,   654,
     656,   636,   647,   648,  1661,  1660,   614,  1364,  1363,  1351,
    1349,     0,  1408,     0,  1401,   614,   614,   614,   614,   558,
     555,   550,   552,   614,  1800,  1800,   566,   568,  1800,  1800,
       0,     0,  1195,  1196,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1194,     0,     0,  1182,  1183,
    1184,  1181,  1186,  1187,  1188,  1185,  1172,  1163,   614,     0,
    1219,     0,  1800,     0,  1158,     0,     0,     0,     0,     0,
       0,   614,  1150,  1151,     0,  1083,     0,  1294,     0,  1487,
       0,  1500,  1486,  1483,   614,  1448,   614,  1513,  1510,  1511,
    1508,  1515,  1514,  1509,  1512,     0,  1501,     0,     0,   614,
       0,  1563,     0,   614,     0,   614,  1430,  1284,  1429,  1421,
       0,     0,     0,  1553,  1545,  1545,     0,     0,  1545,  1552,
       0,  1567,  1436,  1438,  1442,  1443,  1279,  1275,  1020,   614,
       9,   614,  1247,   858,  1081,   614,  1472,  1643,     0,   490,
     518,     0,   274,   479,   476,   485,   482,   614,   441,   440,
     470,    94,   472,   347,  1241,     0,   614,  1784,     0,     0,
     988,    47,     0,   597,   599,   594,   769,   158,   156,   614,
    1800,   614,   614,   614,  1800,   154,   143,   614,   146,   145,
     614,   994,   998,   339,   614,  1356,     0,   783,   780,    23,
    1130,  1221,    68,   614,     0,    99,    66,    91,    74,    80,
       0,   118,   114,   775,  1800,   900,   606,   899,   614,   575,
     614,   806,   807,   805,     0,  1653,  1684,     0,     0,     0,
    1521,  1522,  1520,   614,  1686,     0,   614,   614,   614,   614,
       0,  1069,  1669,  1670,  1666,  1668,   614,  1800,   701,   686,
     683,     0,   750,   724,   752,   726,   742,   740,   746,   738,
     761,    29,    27,   614,  1691,   614,  1620,  1621,  1617,  1623,
     614,  1416,   614,  1419,     0,  1340,  1335,  1334,  1337,   614,
    1658,   614,  1637,     0,   614,  1313,  1319,     0,  1322,  1324,
    1352,  1348,   614,  1407,   614,     0,  1629,  1627,   562,   560,
     572,   574,   570,     0,     0,   228,  1189,  1190,  1191,  1193,
    1176,  1174,  1173,  1177,  1178,  1175,  1192,  1179,  1180,  1164,
     980,  1199,   977,   614,     0,  1217,     0,  1162,  1161,  1156,
    1154,  1153,  1157,  1155,  1159,  1160,  1152,  1205,  1426,  1485,
    1479,  1481,   614,  1495,   614,  1493,  1688,  1503,  1502,   614,
    1688,  1504,     0,  1422,  1428,   614,  1432,  1611,  1609,  1610,
    1606,  1608,  1605,  1607,  1535,     0,  1537,     0,     0,     0,
       0,  1543,  1547,     0,  1527,  1444,  1019,  1255,  1248,  1244,
     614,  1461,  1462,  1464,  1467,  1474,   614,     0,  1519,  1645,
    1639,  1596,  1594,  1595,  1591,  1593,  1590,  1592,   491,   489,
       0,   523,   522,   171,   437,     0,   614,    23,     0,   614,
    1011,   614,    48,   991,     0,    23,   160,   150,     0,   618,
     620,   162,   152,   769,     0,   338,   531,   782,  1052,     0,
      64,     0,    77,    86,     0,    70,   891,   888,   579,  1800,
       0,  1579,   614,     0,     0,     0,  1685,     0,   614,  1683,
       0,     0,     0,     0,  1682,     0,   704,   681,   687,   606,
    1701,     0,  1699,  1649,  1623,  1623,  1616,  1418,  1653,  1420,
    1414,   614,  1339,     0,  1711,  1650,     0,   614,  1326,     0,
    1315,   614,   614,   614,  1409,  1412,  1396,  1410,  1413,   614,
     852,   851,   322,   206,   982,   981,   979,   614,  1198,  1084,
    1088,  1090,   614,  1094,   614,  1092,  1096,  1085,  1086,     0,
     873,     0,     0,  1496,  1499,  1498,     0,  1488,  1689,  1490,
       0,  1488,     0,  1561,  1565,  1560,     0,  1554,  1546,  1530,
    1528,     0,  1531,   614,  1465,   614,  1566,  1468,   614,  1475,
    1476,  1648,  1247,   614,   614,   614,     0,   520,   519,   473,
     348,   345,   614,  1009,     0,     0,     0,   990,   770,   138,
     617,    23,  1000,  1057,  1222,    82,     0,   614,    75,    86,
      86,  1800,   576,   950,     0,     0,     0,     0,  1681,  1687,
    1677,  1678,  1679,  1680,   706,   762,   614,  1698,     0,  1622,
    1618,   614,  1341,   614,  1643,   614,  1330,  1321,  1328,  1331,
     614,     0,   614,   614,  1314,  1323,  1325,  1353,   614,  1397,
    1395,  1630,   978,  1800,  1800,  1098,  1800,  1100,  1800,  1800,
    1087,  1218,  1206,   614,  1494,  1492,  1688,  1507,   614,  1506,
       0,  1564,     0,  1544,  1469,     0,  1463,  1457,  1458,  1662,
     614,  1477,  1471,  1646,  1371,  1367,  1368,  1373,  1372,  1644,
    1247,     0,   350,  1010,  1783,   614,   614,   614,   614,   614,
     614,    53,     0,    52,     0,    50,   614,   614,   139,  1061,
    1053,     0,  1059,    86,    91,    86,    87,    81,    71,   889,
       0,     0,     0,  1726,     0,  1800,    23,  1700,  1643,     0,
    1345,     0,  1342,  1344,  1638,     0,  1331,   614,  1327,     0,
    1316,  1317,  1411,  1089,  1091,  1800,  1095,  1800,  1093,  1097,
    1497,  1489,  1491,  1505,  1562,  1539,   614,  1466,   614,  1456,
     614,  1375,  1374,  1370,  1647,  1597,   356,   354,   346,     0,
     352,   358,    55,    60,    57,    59,    56,    58,    54,     0,
      49,     0,   619,   621,  1800,  1058,  1060,  1223,    83,    78,
     577,  1652,  1724,  1725,   702,   763,  1642,  1651,   614,  1336,
    1320,  1329,   614,  1099,  1101,  1470,  1459,  1369,  1800,  1800,
     351,   353,  1800,    51,   614,  1062,     0,   707,  1343,     0,
     357,   355,   359,     0,    84,  1318,   992,    88,    90,   614,
      85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   550,   551,   552,   553,   703,  1723,  1724,   188,   264,
     189,  1124,  1125,  1609,  1944,  2963,  2470,  2471,  2855,  2964,
    2965,   554,   891,  2503,  2175,  2870,  1550,  2173,  2733,  2507,
    2866,  2174,  2734,  2974,  3076,  3087,  2868,  3090,  1772,  1773,
    1774,  1224,  1840,   555,  1235,   896,  1233,  1558,  1850,  1555,
    1848,  1853,  2179,  1234,  1847,  1559,  2178,   556,    16,    35,
      36,    37,    38,    39,   113,   559,   820,  1489,  1151,  1799,
    1803,  1804,  1800,  1801,  2480,  2484,  2152,  2144,  2143,  2145,
    2148,  1106,  1058,  1754,   560,    83,    84,    18,    60,   142,
      96,   255,    98,    99,   200,   278,   100,   101,   242,   228,
     675,  2341,   305,   657,  1669,   332,   333,   229,   287,   280,
     282,   975,   976,   146,   355,   147,   148,   293,   230,   231,
    1475,   393,   243,   246,   244,   245,   314,   370,   371,   373,
     378,   660,   247,   248,   323,   375,   196,    19,    80,   177,
     178,   179,   666,  2340,   180,   251,   240,   326,   327,   328,
     329,  1502,   561,   562,   563,   564,   777,  2952,  2707,  1126,
    3028,  3029,  3030,  3069,  3068,  3072,   565,   566,   567,   568,
     753,  1107,   858,  1193,  1194,  1161,   855,  1162,   755,   756,
     757,   758,   759,   760,   761,  1061,  1108,  2116,  1109,  1110,
    1111,  1112,  1113,  1114,  1115,   709,   762,  1455,  2121,  2123,
    2705,   763,  1426,  2105,  1425,  2104,  1429,  2108,  1427,  2106,
    2088,  2097,   764,   765,   766,   767,  1410,  1411,  1412,  1413,
     569,   828,  1504,  2160,   114,   237,   365,  1326,   957,   958,
     959,  1323,  1324,  1656,  1657,  1658,  2003,  2004,  1327,  1328,
    1652,  2007,  1999,  1664,  1665,  2010,  2011,  2338,  2334,  2335,
     570,  2739,  2980,  2519,   571,  1168,    85,  1470,  1471,  1815,
     860,   810,   863,   686,   799,   782,   821,  1905,    86,   687,
    1004,  1715,    41,   127,  2147,    87,   769,  2314,   572,   573,
     912,   913,   574,   575,   576,   577,   920,  2549,   941,  2757,
     942,  1588,   943,  1902,   944,  2227,   945,  1612,   578,  1584,
    2226,  2547,  2546,  2985,   115,    20,   579,  1142,  1476,  1477,
    1602,  1273,  1603,  1604,  2233,  2235,  1914,  1913,  1926,  1912,
    1911,  2244,  2242,  1918,  1919,  1922,  1923,  1908,  1910,   580,
     581,   818,   582,  1269,   927,  2986,   583,  1201,  2715,  1605,
    1915,  1856,  2181,   851,  1178,  1525,  1824,  2161,  1825,  1174,
    1524,   584,   585,   905,  1573,  2523,   586,   587,   588,   589,
      21,    64,    22,    23,    24,   116,   117,   590,   118,    25,
     647,    26,   119,   120,   157,   367,  1332,  2015,  2791,   121,
     153,   298,   591,  2086,    27,    28,    29,    30,    31,    59,
      88,   122,   412,  1341,  2021,   123,   238,   366,   651,   652,
     961,  1330,   592,   900,  1860,  1562,  1858,  2871,  2514,  1563,
    1857,  2184,  2516,   593,   594,   595,   793,   794,  1237,   596,
     946,   947,   597,   824,  1281,   948,   770,    90,    91,    92,
      93,  1244,   183,   138,    94,   135,   191,   192,  1245,  1246,
    2191,  1247,   409,   410,   929,   411,   930,  1580,  1581,  1248,
    1249,  1122,  2621,  2622,  2796,   692,   808,   809,   598,  1137,
    2857,   599,  2492,   600,  1155,  1156,  1157,  1495,  1493,   601,
     602,  1780,  1810,   603,  1010,  1381,   604,   852,   853,   605,
     868,   606,  1955,   607,  2863,   608,  1828,  2970,  2971,  2972,
    3044,   857,   609,  1250,  1575,  1890,  1891,   610,  1463,   708,
    1022,   611,   612,  2023,  2625,  2807,  2808,  2913,  2914,  2918,
    2916,  2919,  3005,  3007,   613,   614,  1239,  1567,   615,  1241,
     876,   877,   878,  1217,   616,   617,   618,  1537,  1209,   871,
     199,   879,   880,   771,  2024,  2382,  2383,  2366,   712,   713,
    2019,  2367,  2370,   124,   152,   359,   985,  1674,  2384,  2811,
    1031,   619,   869,   125,   149,   356,   982,  1672,  2371,  2809,
    2020,   895,  2166,  2729,  2973,  1212,   620,   621,   622,   623,
     624,   780,  1778,   705,  1728,   625,  2679,   699,   700,  2083,
    1360,   626,   627,   994,   995,   996,  1372,  1711,   997,  1708,
    1369,   998,  1683,  1361,   999,  1000,  1001,  1002,  1677,  1352,
     628,   789,   772,   629,  1304,  1979,  2780,  2904,  2585,  2586,
    2587,  2588,  2779,  2897,  2898,  1305,  1306,  1627,  2577,  2773,
    2265,  2574,  2991,  2992,  1307,  1637,  2319,  1989,  2591,  2783,
    1820,  2159,  1990,  1308,  1309,  2689,  2945,  2946,  2947,  3023,
    1310,  1311,  1159,   630,   631,   954,  1312,  1313,  2910,  1643,
    1644,  1645,  1992,  2321,  2786,  2787,  1314,  1965,  2259,  2770,
    1362,  1363,  1348,  2043,  1675,  2044,  1364,  2047,  1365,  2070,
    1366,  2071,  2433,  2434,  1678,  1315,  1621,  1622,  1962,  1316,
    2941,  2839,  2937,  1968,  2446,  2681,  2682,  2683,  2935,  2447,
    1969,  2840,  2942,  2032,  2033,  2034,  2035,  2036,  2927,  2817,
    3011,  2037,  2812,  2813,  2408,  2038,  2409,  2039,  2533,  1704,
    1705,  1706,  2668,  1707,  2430,  2424,  2828,  2045,  2788,  2411,
    2589,  2837,  1892,   773,  1893,  2197,  1049,  2089,  2698,  2060,
    2664,    58,   632,   633,  2569,  2765,  2252,  2764,  1648,  1997,
    1998,  2256,  1956,  1317,  1957,  2270,  2776,  1402,  1952,  1953,
    2690,  2842,  2582,  2573,  1894,  1635,  1976,  1977,  2938,  2040,
    1896,  2535,  2819,   634,   635,  1614,  1954,  2564,  2761,  2762,
    1284,   636,   775,  1319,  1320,  1630,  2267,  1321,  1322,  1973,
    2220,  2529,   637,   908,  1258,  1259,  1260,  1261,   693,  1577,
     695,  1385,  1897,    62,    47,    78,    75,   639,   882,  1541,
    1145,  1203,   640,   861,   641,  2134,   642,  1722,   697,  1387,
     643,   644,    73,   360,   361,   362,   363,   364,   645
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2590
static const short yypact[] =
{
    2395,   869, -2590,   664,   664,   664,   664,   664,   664,   664,
   -2590,   664, -2590,   324, -2590, -2590, -2590,  1037, -2590, -2590,
   -2590,   425, -2590,  2395, -2590, -2590, -2590, -2590, -2590,  1742,
   -2590, -2590, -2590, -2590, -2590,   400,   418, -2590,   453, -2590,
   -2590,   483, -2590, -2590,   -21, -2590,   -72, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   874,
     314, -2590, -2590, -2590,   143, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   -21,
      24, -2590, -2590,   498,  1037, -2590,   845, -2590, -2590, -2590,
   -2590,   726,   171, -2590, -2590, -2590,   774,   459, -2590, -2590,
   -2590,   820, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   143, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    7857,   171, -2590,    71,   173, -2590, -2590,   398, -2590,   253,
     898,   314,   414, -2590, -2590, -2590, -2590, -2590,  7968, -2590,
     538,   853, -2590,  1037, -2590, -2590, -2590, -2590, -2590, -2590,
     438,   888, -2590, -2590,   551, -2590,   585, -2590,   576, -2590,
   -2590,   618, -2590,   629, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,   645, -2590, -2590, -2590,   173,  1397,  1032,
   -2590,   187, -2590,   173, -2590, -2590,   160, -2590, -2590, -2590,
     146, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   438,
   -2590,   888, -2590, -2590,   651, -2590,   659, -2590,   649, -2590,
   -2590,   679, -2590,   683, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,   695,  1086, -2590,   712, -2590,  1037,  1037,   716,
   -2590, -2590,   -82, -2590,   524,  1015, -2590,   529,  1180,  1111,
    1123, -2590,  1125,  1129,  1135, -2590,   569, -2590,   543, -2590,
   -2590, -2590, -2590, -2590,   173, -2590,   173,   746,   188, -2590,
   -2590, -2590,  1159, -2590, -2590,  1164, -2590, -2590, -2590, -2590,
   -2590,   -82, -2590, -2590, -2590,  1166,  1168,   314,  1125,  1177,
    1184,   601, -2590,  1174, -2590,   864,   828, -2590,   899, -2590,
   -2590, -2590,   644, -2590, -2590,  1223, -2590,   842, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1180,   842, -2590, -2590, -2590,
   -2590, -2590, -2590,   860,   210,   235,   307, -2590,  7590, -2590,
   -2590, -2590,   868,  1278,   298,   923, -2590, -2590,  1397, -2590,
     173, -2590, -2590, -2590,   699,  1269,  1066,   353,   363,   334,
     901,   382,   949, -2590, -2590, -2590,   952, -2590, -2590,   952,
     985, -2590,  3986,   414,  4888,  1959,   233,   952,  1308,    16,
   -2590,  1015,  1305, -2590, -2590, -2590, -2590,  1309, -2590,  1316,
   -2590,  1318, -2590, -2590, -2590, -2590, -2590, -2590,  1125,  1321,
   -2590, -2590, -2590, -2590,   197,  1330,    16,   944,  1337, -2590,
    1341, -2590, -2590, -2590,  1345, -2590, -2590, -2590,   778,   986,
    1368, -2590,   952,  1027, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,    91, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
      69, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   126,   126,  6899, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   807, -2590, -2590, -2590,  6899, -2590,
     807, -2590,   807,   969, -2590, -2590,    52, -2590, -2590,    52,
   -2590, -2590,    52, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,   807, -2590, -2590, -2590, -2590,   -24, -2590, -2590,
   -2590, -2590, -2590, -2590,    91, -2590, -2590, -2590, -2590, -2590,
    6682,   807,  7815, -2590,   765,   765, -2590, -2590, -2590,   136,
     807,    96,  6899,  7815, -2590,  1175,  6899, -2590,   -21, -2590,
    7815, -2590,  7815,   807, -2590, -2590,  7815, -2590,  7815,   126,
   -2590, -2590, -2590,   765, -2590, -2590,   765, -2590, -2590,   108,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,    67, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,   962, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   404, -2590, -2590,
   -2590,  -145, -2590,  1043, -2590, -2590, -2590,  1140, -2590, -2590,
    1052,  1060,  1061,  1062, -2590, -2590,   831,  1431,  1072, -2590,
   -2590,  1167, -2590,  1075,  1080,   848,  1085, -2590, -2590, -2590,
    1091, -2590,   287, -2590,   263, -2590, -2590, -2590, -2590,   856,
    1448,  1038, -2590,   887, -2590,   891, -2590,  1476,  -123,   393,
   -2590, -2590, -2590,  1088, -2590,  1463, -2590, -2590,  1036,    81,
   -2590, -2590, -2590,  1172, -2590,  7815,  7815, -2590, -2590,  1093,
    1000,  1099,  1100,  1101,  1104,  1107,  1108,  1119,  1130,  1131,
    7815,  1233,  1133,  1134,  1137, -2590,  7815,  7815,  1141,  1143,
   -2590,  7815,  1144, -2590,  1145,  1148,  1149,  1152,  1153,  1156,
    1160,  7815,  1161,  6345, -2590,   131, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   750, -2590,
    1173, -2590, -2590, -2590, -2590, -2590, -2590,   807, -2590, -2590,
    1463, -2590,   -10, -2590, -2590,  1273, -2590,    47, -2590,  1139,
   -2590, -2590, -2590, -2590,  1573, -2590, -2590,  -210, -2590,   936,
   -2590,   984,  1573, -2590,  1008, -2590, -2590,  1185,   134, -2590,
    1170, -2590,   948, -2590, -2590,  1181, -2590,   321, -2590,   965,
     -92,  -200, -2590,  1300,  7815,  7815, -2590,  1597, -2590, -2590,
   -2590, -2590, -2590, -2590,    50,    50,    50, -2590,    50, -2590,
      50,    50,  1033,   -10,  1033,  1033,   118,   118,  1033,  1033,
     -10, -2590,  1608, -2590,    79,  1610, -2590,   -10, -2590,  6742,
   -2590,    80,    63, -2590, -2590,  7815, -2590, -2590, -2590, -2590,
   -2590,   885, -2590, -2590,   414,  1255,   414,  6899, -2590,    66,
   -2590, -2590,  7815,  1209,  1211,  1212,  1214,  1599,  1216,    96,
    1148, -2590,  1304,   817,  1063, -2590,  1089, -2590, -2590, -2590,
     119, -2590,  1621, -2590,  1628, -2590, -2590,   200,   199,  1106,
   -2590, -2590,  1638, -2590,  1007,  1638,  1660,  1034,  1638,  1660,
    7815,  1638, -2590, -2590,    81,   807, -2590, -2590,  1275,   387,
   -2590, -2590,  1267,   807,  7815,  1268, -2590, -2590,  1653,  1661,
    1643, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   129,
     129, -2590, -2590, -2590,  1260, -2590, -2590,  1623,   404, -2590,
   -2590,   354, -2590, -2590, -2590,  1259, -2590, -2590, -2590, -2590,
    7857,  1125, -2590,  1261, -2590,   396, -2590, -2590, -2590, -2590,
   -2590, -2590,  1037, -2590, -2590,  1037,   656,  1288,  1673, -2590,
   -2590,   863,  1291,   956,  1701, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  1306, -2590, -2590,  1448,   891,   173,    91,
    -164,  1688, -2590, -2590, -2590, -2590, -2590,  1138,  1114,  1150,
    1312, -2590,  1317,   109, -2590, -2590, -2590,   867,   867,   765,
    7815, -2590,   765,   765,   765,   765,  1279,  7815,  1289,   946,
    7815,  6345,  1323, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    1112,   765,  1709,  7815,  4369,  6345,  1279,  7815, -2590,  6345,
    1712,   441, -2590, -2590, -2590,  7815, -2590,  7815,  7815,  6345,
    7815,  7815,  7815,  7815,  7815,  7815,  7815,  7815,  7815,  7815,
    7815,  7815,  7815,  7815,  7815,  7815,  7815, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  7815,  7815, -2590,
   -2590,  1328,  7815, -2590,  7815,  1329, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     807, -2590,  1136,  1331, -2590, -2590, -2590,    91,   142, -2590,
     142,    96,    52,  7815,  7815,  7815,  1339, -2590, -2590,   807,
     807, -2590,  1147,    96,   765,  1120, -2590,   173,    46,   -24,
     807, -2590,  1163,  7815,  1414, -2590, -2590,  1225, -2590, -2590,
    1610,    73, -2590,    81, -2590, -2590,  1752,  1754, -2590, -2590,
   -2590, -2590, -2590, -2590,   350, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  6682, -2590,   118,
    7815,   -20, -2590, -2590,  1765, -2590,   765,  1748,  1749, -2590,
   -2590, -2590, -2590, -2590,   124, -2590, -2590, -2590, -2590,  1645,
   -2590,  1582, -2590, -2590, -2590,  7815,   126, -2590, -2590, -2590,
    1753,   765,   765, -2590,  1218, -2590,   765,  1182,   807, -2590,
   -2590, -2590,  7815,    13, -2590,  1222, -2590,   289, -2590,  1327,
   -2590,  1338,  7815,   904, -2590, -2590,   171, -2590,  1785, -2590,
    1274, -2590,   807, -2590, -2590, -2590,    91,   807,   141, -2590,
   -2590, -2590, -2590, -2590,   765,   765,   219,   387,  1666,   715,
     807,    81, -2590,  1276, -2590, -2590,  1795,  1781,  1430, -2590,
   -2590, -2590, -2590, -2590,  1510,  1510,   250,  1287, -2590, -2590,
   -2590, -2590,  1463,  1463, -2590, -2590, -2590, -2590, -2590, -2590,
      10,  1463, -2590,   443, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1083, -2590,
   -2590, -2590, -2590,   164,   164,    99,   754, -2590,   680, -2590,
     354, -2590,  1037,  1793, -2590, -2590,  1793, -2590, -2590, -2590,
   -2590,  1037, -2590, -2590,  1463, -2590,   769,  1411, -2590, -2590,
     769, -2590, -2590, -2590,  1413,  1418,   591,  1421,  1422,  3653,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     591,  1188, -2590,   287,  1809, -2590,  1235,   204, -2590,    96,
    1286, -2590, -2590,  1038, -2590, -2590, -2590,  1322, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1483,  6345,  1484,  1485,  1487,
     411,    10,  1490,  5231,  1491,   -65,  1029, -2590, -2590,   149,
    1493, -2590, -2590, -2590,  5275,  1840,  1233,  1500,  1502,  5531,
   -2590,  1504,  2348,  1509, -2590,  7815,  7815,  7815,  5643,  7815,
    5682,  5726,  5770,  6367,  6450,  3886,  6480,  1581,  2036,  4819,
    3696,  2300,  6252,  6652,   867,   867,  7165,  7558,  2201,  5915,
    6179,  1279,  6345,  6222,  1279,  6899,  1471, -2590, -2590, -2590,
    1285, -2590, -2590, -2590, -2590,  1277, -2590,  1878,  1882, -2590,
    1892,  1342,  7815, -2590, -2590,  1302,  1898, -2590,  1444,  1313,
    1660, -2590,  1538,   280, -2590,  1503, -2590, -2590,  1325,   768,
   -2590, -2590, -2590,  1524, -2590,   756,  7815, -2590, -2590, -2590,
    7815,  -107,   -10,  1928,  1402,  1910,  1913, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1532, -2590, -2590, -2590,   807,
    1427,  7111, -2590, -2590, -2590,  1899,  7815,   414,   103, -2590,
   -2590,  1641,  1577,  1945,  1583,   419, -2590,  1589,    96, -2590,
    6899,  1543,  1551, -2590, -2590,  1622, -2590,  7815,   128, -2590,
    1386, -2590, -2590,   753, -2590,  7815, -2590, -2590,  1359,    71,
   -2590,  1367, -2590,  1954,  3891, -2590, -2590,  1570, -2590,  1571,
    1969, -2590, -2590, -2590,   179, -2590,  1660,  1660,  1336, -2590,
    1447,  1452,   765,   765, -2590, -2590, -2590, -2590, -2590, -2590,
     450,   508, -2590,  1078, -2590, -2590, -2590, -2590,   765,  1179,
    1973,  1955, -2590,    96,   -25,    57,  1534,  1906,   147,   181,
   -2590,    22, -2590, -2590, -2590,  1578,    31,  1463,   218, -2590,
    1391,  1380, -2590, -2590, -2590,  7708, -2590,  1109, -2590, -2590,
   -2590, -2590,  1584,  1389,  1993, -2590,  1975, -2590, -2590, -2590,
   -2590,   807,    77, -2590, -2590, -2590,  1383,   754, -2590, -2590,
   -2590, -2590, -2590, -2590,   599, -2590, -2590, -2590, -2590,  1598,
    1600, -2590,  1567, -2590,  1569, -2590,  1601,   423, -2590,  4076,
     426,  1463,  1463,   428, -2590,  1463,  4076, -2590, -2590,  1379,
    1379, -2590,  1603, -2590,  1605,  1609, -2590,  1611,  1613, -2590,
    1614, -2590, -2590, -2590,   217, -2590, -2590, -2590,   430, -2590,
   -2590,   433, -2590, -2590, -2590,  1639,   171,  1688, -2590,  2008,
      96,  7815, -2590,  2013, -2590, -2590, -2590, -2590,   591, -2590,
   -2590, -2590, -2590, -2590, -2590,  7708, -2590, -2590,  1233,  1233,
    1999, -2590,  2000,  1460,   437, -2590,  1000,  1662, -2590, -2590,
    1000, -2590, -2590, -2590,  1664,  1000,  6345,  6345,  6345,  1000,
    6345,  1000,  1000,  1000,  2006,  2011,  2014,  7815,  1668,  2016,
    7815,  1672, -2590,  2037, -2590,  6345, -2590,  1462,   591,    62,
   -2590,    96,  7815,  7815,  7815,  7339,  2061,   613, -2590, -2590,
      96, -2590,  1469, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     870, -2590, -2590,   403, -2590,  1470,  7815, -2590, -2590, -2590,
    2063, -2590, -2590, -2590, -2590, -2590, -2590,  1660, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   807, -2590,
   -2590,  3427, -2590, -2590, -2590,  1770, -2590, -2590,  1755,  1756,
    1646,  1480,  1759,  1679, -2590, -2590, -2590,   578,  1750, -2590,
   -2590, -2590, -2590,  1622, -2590, -2590, -2590,   182,   790, -2590,
   -2590, -2590,  1795,  7815,  1686,  2066, -2590, -2590,   156,   172,
   -2590,   856, -2590, -2590,  1379, -2590, -2590,  5493,  1684, -2590,
   -2590,  1685,  1696, -2590,  1697,  1704,  1705,  1707,   -29, -2590,
    2086, -2590, -2590, -2590, -2590,  2807, -2590, -2590,    91,   807,
     807,   155,  1464, -2590,  2092,   -10, -2590, -2590,  2114, -2590,
    2121,  1084,  1084,  1084,  1084,  1532, -2590, -2590,  2123, -2590,
   -2590, -2590,  2124, -2590, -2590, -2590,  1084,   130, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   434, -2590,  2106, -2590, -2590,  1463,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1558,  1560,
      59, -2590,    22, -2590,  1463,  1539, -2590,  4076, -2590, -2590,
    1728, -2590, -2590, -2590, -2590, -2590,  2134, -2590,  4340,  1579,
   -2590,  7815, -2590,  7815, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,  1463, -2590,  1463,   501,  1541,  1557,  2137, -2590,  2152,
   -2590,   807, -2590,   690,   690, -2590, -2590,  2155, -2590,  2155,
     603,   603,  2155, -2590, -2590,  1959, -2590, -2590,  3128,    92,
   -2590,  1959,  1425, -2590,    92,  1463,   769, -2590,  1751,  2707,
    1751,  2789,   213,  2156, -2590, -2590, -2590, -2590, -2590, -2590,
     262, -2590,   454,  1798,  2164, -2590, -2590,   436, -2590,   591,
   -2590,   442,   242, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    1572,   -33,  2150,  2150,  2153,  2150,  2150,  2157, -2590,    75,
   -2590,   769, -2590, -2590,   591, -2590, -2590, -2590,  1585,    96,
    2172, -2590, -2590,   460, -2590,  7531,  1812,   158, -2590,  1580,
   -2590,  1817, -2590,  2163, -2590,  1634, -2590, -2590, -2590, -2590,
   -2590,  1590, -2590, -2590,  1834,  1835,  1836, -2590,  1843, -2590,
   -2590, -2590, -2590, -2590, -2590,  6345,   463, -2590, -2590,   466,
   -2590,  1844,  7815,  6899,  2195,   467,    96,  2226, -2590, -2590,
   -2590, -2590,  7815,  1689,  1984,  7815, -2590, -2590, -2590, -2590,
    2222,  1874,   403,  1096,  1096,  2245,   362, -2590,  2246, -2590,
   -2590, -2590,  1096, -2590,  1727,  2235,  2251, -2590,   -73,   807,
    2039,   469, -2590,  1447,  7815, -2590,  6899,   807, -2590,    69,
   -2590,   807, -2590,  1890,  6899,  6899, -2590, -2590,   578,  1750,
   -2590,  1532, -2590, -2590,   152, -2590, -2590,  1710, -2590, -2590,
    1825, -2590,  7598, -2590, -2590, -2590, -2590, -2590,  1659, -2590,
    1820,   271,   588,  7708,   588,   588,   588,   588,  7708,  3891,
    7708,  7708,  7708,  7708, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,  1847,   762, -2590, -2590,
   -2590,  1669,   765,  1084,   765,  1084, -2590, -2590, -2590, -2590,
   -2590,   450,  1084,   508,  1084, -2590,   -10,  1179, -2590,  1900,
    1862,    10,  1083,  1534,  1534, -2590, -2590, -2590, -2590,   470,
   -2590,  1828, -2590,  2272,  1463,   -35, -2590,  1674, -2590,  7708,
    1769, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,   221, -2590, -2590,  1771,
   -2590,   471, -2590,  1692, -2590, -2590, -2590,  1975,   807, -2590,
    2155, -2590, -2590, -2590,   603,   603, -2590, -2590,   603,  2125,
    1699,  1708, -2590, -2590,   126,   126,   126,  2298,   126,   126,
     126,   126,   126,   126,  2303, -2590,  2305,   126, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,  3128, -2590,   807,  1734,
   -2590,  1914,  2125,  2310, -2590,  2313,  2319,  2320,  2321,  2322,
    2323,   186,  1425, -2590,  1914, -2590,   472, -2590,  1901, -2590,
     258,   243, -2590, -2590,  4076, -2590,  4076, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1941, -2590,  1943,   191,  7708,
    2327, -2590,  2102,  1463,  1778,  1463, -2590, -2590, -2590, -2590,
    1505,  2353,  1505, -2590,  2374,  2374,   473,  2012,  2374, -2590,
    2015, -2590, -2590, -2590,   769, -2590, -2590, -2590, -2590,    96,
   -2590,   591,  2136,  1795, -2590,   114,  1876,     1,  1627,  1233,
    1821,   906, -2590, -2590, -2590, -2590, -2590,  7815, -2590, -2590,
   -2590, -2590, -2590,  1944, -2590,   245,    96, -2590,  2386,  1985,
   -2590, -2590,  2032, -2590, -2590, -2590,  1873, -2590, -2590, -2590,
    1096,   173,  2383, -2590,  1096, -2590, -2590,   765, -2590, -2590,
    7815, -2590, -2590, -2590,   765,  1969,  2188, -2590, -2590,   -10,
    6345, -2590, -2590,    81,  2004, -2590, -2590,  6899, -2590, -2590,
    2040, -2590, -2590, -2590,   790, -2590,  1447, -2590,  7815, -2590,
     173, -2590,  1610, -2590,  1505,    10, -2590,   445,  2405,  2043,
   -2590, -2590, -2590,  7708,  2807,   478,  7708,  7708,  7708,  7708,
     480, -2590,  2146,  2146,  2154,  2211,  7815,  1996, -2590,  2093,
   -2590,  2396, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  7708, -2590, -2590, -2590,  1083,
    1463, -2590, -2590,  2308,   482, -2590, -2590, -2590, -2590, -2590,
   -2590,   807, -2590,  2404,  1463, -2590,  2421,  2414, -2590, -2590,
   -2590, -2590,  1463, -2590,  1989,  1831, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590,  2244,  7857, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    -114,  2428, -2590,   807,  1334, -2590,  2244, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    2156, -2590,   205, -2590,   205, -2590,    75, -2590, -2590,  7708,
      75,  2807,   209, -2590, -2590,  2417, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  2069, -2590,  2415,  2072,  2075,
    2420, -2590, -2590,  2077, -2590, -2590, -2590, -2590, -2590, -2590,
     163,  2442, -2590, -2590,  2430,  2111, -2590,  1860,   588,  2151,
   -2590,  2051, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     961, -2590, -2590, -2590,  6345,  2094,   765,   -10,  2110,    96,
   -2590,  7815, -2590,  1915,  2440,   -10, -2590, -2590,   325, -2590,
   -2590, -2590, -2590,   234,  2098,  1660, -2590, -2590, -2590,  2099,
    1928,  2064, -2590,  2147,  2104, -2590, -2590, -2590, -2590,  2252,
     232, -2590,  7708,  1379,  1869,  1379, -2590,  2026,  7708, -2590,
    2174,  2220,  2379,  2528, -2590,  1922, -2590, -2590, -2590,  1447,
   -2590,   485, -2590,    68,  1083,  1083, -2590, -2590,    10, -2590,
   -2590,  1463, -2590,  2070, -2590,  1969,  1957,  5573, -2590,   486,
      84,  1463,  6404,   807, -2590, -2590,   336, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   807,  2428, -2590,
   -2590, -2590,   807, -2590,   807, -2590, -2590,  1678, -2590,  2262,
   -2590,  2266,   489, -2590, -2590, -2590,   492,  2065, -2590, -2590,
    1683,  2065,  2461, -2590, -2590,  2054,  1886, -2590, -2590, -2590,
   -2590,  2118, -2590,   114, -2590,   114, -2590, -2590,  7708, -2590,
    2068, -2590,  2136,  1357,    57, -2590,  2469, -2590, -2590, -2590,
   -2590, -2590,    96, -2590,  2127,  7947,  2096, -2590, -2590, -2590,
    1903,   -10, -2590,    51, -2590, -2590,  2131,    81, -2590,  2147,
    2147,   790, -2590, -2590,   158,  1902,  1505,  1907, -2590,  2807,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1957, -2590,
   -2590,  7708, -2590,  6488,     1,  1415, -2590,  2501, -2590,  2807,
    1463,  2495, -2590,  4076, -2590, -2590, -2590,  1969,  1989, -2590,
   -2590, -2590, -2590,  1528,  1528, -2590,  1528, -2590,  1528,  1528,
   -2590, -2590, -2590,   388, -2590, -2590,    75, -2590,  7708, -2590,
    2113, -2590,  1505, -2590, -2590,   502, -2590,  2509, -2590,  2807,
    4076, -2590, -2590, -2590, -2590,  2510, -2590,  -113, -2590, -2590,
    2136,  2149,   840, -2590, -2590,    50,    50,    50,    50,    50,
      50, -2590,  2498, -2590,   512, -2590,  7815,  2499, -2590, -2590,
   -2590,   560, -2590,  2147,  6899,  2147,  1928, -2590, -2590, -2590,
    2304,  2159,  1505, -2590,  1505,   179,   -10, -2590,     1,   158,
   -2590,   514, -2590,  2807, -2590,   520,  1820,  6404, -2590,  2116,
   -2590,  2272, -2590, -2590, -2590,  1528, -2590,  1528, -2590, -2590,
   -2590, -2590, -2590,  2807, -2590, -2590,   114, -2590,  7708,  2272,
    1357, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   111,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  7947,
   -2590,  2520, -2590, -2590,   700, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   155, -2590, -2590, -2590,  6488, -2590,
   -2590, -2590,  6404, -2590, -2590, -2590, -2590, -2590,   971,   971,
   -2590, -2590,   971, -2590,  7815, -2590,  2171, -2590, -2590,   522,
   -2590, -2590, -2590,  2180, -2590, -2590, -2590,   220, -2590,    81,
   -2590,  1928
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2590, -2590, -2590, -2590, -2590,   357, -2590,   451,  -185, -2590,
   -2590,  -849,  -142, -2590, -2590, -1545, -2590, -2590, -2590, -2590,
    -507, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -1699, -2590, -1524, -2590,
     429, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   688, -2590,
   -2590, -2590, -2590,  1319, -2590,   995, -2590, -2590,   -58, -2590,
   -2590,  2518, -2590,  2517,  2192, -2590, -2590, -2590, -2590, -2590,
     763,   405, -2590,   759, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  -120,   922,   345, -2590, -2590,
    2273,   -15, -2590,  2423, -2590, -2590,  2422, -2590,  2361, -2590,
   -2590, -2590,  2291,  2177,  1240,  2292,  -316, -2590, -2590, -2590,
   -2590, -2590,  1242,  -965, -2590, -2590, -2590, -2590, -2590, -2590,
    -118,  2228,  2372,  -195,   833, -2590,  2216,   144, -2590,  2277,
   -2590, -2590, -2590, -2590,  2279, -2590, -2590, -2590, -2590,  -324,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  2205, -2590,
    2210, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  -887,
   -2590, -2590,  -432, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    2513, -2590, -2590,  1073, -2590,  -884,  -809,  1376, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,   835, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  -459, -2590, -2590, -2590, -2590,
   -2590,  2085, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -1701, -2590, -2590, -2590, -2590, -2590, -2590,  1205, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    1654, -2590, -2590, -2590, -2590,   957, -2590, -2590, -2590, -2590,
   -2590, -1304, -2590, -2590,   951, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  -811,  -474,   832,  1117, -2590,
    -484,   579,  -807,  1693, -2590,   819, -2590, -1811,    -2,  -328,
   -2590, -2590,  2542,  1615, -1743,  -127,   927, -2590, -2590, -2590,
     737,  1358, -2590, -2590, -2590, -2590, -2590, -2590,   395, -2590,
      74, -2590,  1354, -2590,  1039, -2590,   722, -2590, -2590, -2590,
    -428, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,   837,
   -2590, -1216, -2590,  1025, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,   389, -2590,   386, -2590, -2590, -2590,
   -2590,  1482, -2590, -2590, -2590, -2590, -2590, -2590,   -91, -1471,
   -2590, -2590, -2590, -2590,   556, -2590, -1649, -2590,  -827, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590,  2610, -2590, -2590, -2590,  2519,  2608,
   -1094, -2590, -2590, -2590, -2590, -2590, -2590, -2590,    15, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  2614, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1988,
   -2590, -2590, -2590, -2590, -2590,  1081, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,  -416,  2166, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590,   685, -2590, -2590,   -47,
   -2590, -2590,  1076, -2590, -2590,  1403,  -192,  2384, -2590, -2590,
   -2590, -2590,   535, -2590,  -706,  1972,  1381, -2092,   755, -2590,
    1087,  1731,    34,  -139, -2590,  -967, -2590,  1520, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,  1474, -2590,
    1044, -2590,  -331, -2590, -2590, -2590, -2590, -2590, -2590,  -306,
   -2590, -2590, -2590, -2590, -2590, -2590,   457, -2590,  1537,   -62,
   -2590, -2590, -2590, -2590,   285, -2590,  -137, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,  1794, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
    -323, -2590,  1457,  1616, -2590, -2590,   292, -2590,  -429, -2590,
   -2590,   309,   652, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
     580, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2464, -2590,  1665,   903,
    -970, -2590, -2590, -2590,  1310, -2590, -1321, -2590, -2590, -2590,
   -1320, -2590, -2590, -1295, -2590, -2590, -2590, -2590,  1335, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2348,  -102, -2590, -2564, -2486, -2590,   727, -2590, -2590, -2590,
   -2590, -2590, -2590,  -370, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590,  -330, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590,   697, -2590, -2590, -2590,  -219, -2590, -2590, -2590, -2590,
   -2590, -2590,   281, -2590, -2590,   667, -2590,  1009, -2590, -2590,
   -2590, -2590, -2590, -2590,  -966, -2590, -2590, -2590, -2590, -1404,
   -2590, -2590, -2590, -2590, -2590, -2590, -1927,    18, -2590, -1955,
     249, -2590, -2590, -1647,   302,   303,   669, -2590,  -119,    53,
   -2590, -2590,    61,  -222, -2590, -2590, -2590, -2590, -1914, -2590,
   -2590, -2590, -1572, -2590, -2590,  -868, -2590,  -683,  1419,  -115,
   -1598, -2590, -2016, -2590, -2590, -2590, -2590,  -669, -2590, -1653,
   -2138, -2590, -2590, -2590, -2590, -2590, -2590, -2590, -1964, -2590,
     380, -2590, -1677, -2590,  1757, -2590, -2590,  -895,  -131, -2590,
   -2589,  -130,   -49,   452, -1579, -1369, -1692,   449,  -299,  1193,
   -2590,   513,  -206, -2590, -2590,  1437,  -512, -2590, -2590,  -163,
    1783, -2590,   643, -2590, -2590, -1234,   159, -2590, -2590, -2590,
   -2590, -2590, -2590, -2590, -2590,  1468, -2590, -2590,  -434,  -403,
    -437,  1011, -1249,     5,  2301,   107, -2590, -2590, -2590, -2590,
   -2590,  1594, -2590,  -455, -2590, -2590, -2590, -2590, -2590, -2590,
   -2590, -2590,  -653,  1776,  2373, -2590, -2590, -2590, -2590
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1797
static const short yytable[] =
{
      40,   268,   258,  1023,   386,    32,   112,  1578,  1191,   874,
      55,    57,  1173,   816,  1339,  1160,   714,   284,  1802,   694,
    1349,  1164,  1020,  1371,  1170,  1171,  1844,  1172,    32,  1175,
    1176,  1005,  1735,   236,    68,   131,  1266,  2061,  2090,  2052,
     416,    74,    77,  2087,  1384,    97,  2183,  1709,   825,  1710,
    1276,  1590,  1591,  2432,   859,  2149,  1204,   256,   865,   112,
     862,  1684,  1050,   798,  1945,  1631,  1484,  2495,  1196,   126,
     823,  1215,   667,  2269,   128,  1165,   791,    77,  1496,   338,
     140,   872,  2001,  2046,  2048,  1196,   872,  2048,   916,   137,
     683,   919,  1868,  1869,   702,   181,   144,  1123,   269,  2431,
    1872,   694,   150,   151,   269,   922,   923,   291,   154,   155,
     910,   931,  1128,  1129,  1271,   689,  2246,   299,   300,  1497,
     872,  1498,   126,  1499,   774,  -614,    97,   774,  1833,  1190,
     201,   269,   922,   923,  1197,  1196,  1394,   783,  1018,  1140,
    1198,   774,    81,  1236,  1286,   774,  1288,   232,   394,   269,
     235,   710,   800,  1282,   269,   239,  1116,   774,  1966,   783,
     866,  1421,  -614,  2269,   275,   811,  1461,  1742,   783,   269,
     276,   277,     1,  1255,  1743,   822,  2515,   827,  -614,   269,
     826,  2193,   102,   269,   270,   271,   129,  1018,   864,  2137,
     184,   185,   266,   266,   273,   269,  2224,  2195,   186,   811,
    2646,  1949,   266,   811,  2368,   866,  2182,   811,  -614,   266,
    2634,  2902,   292,   783,  2822,   379,   783,  1963,  1267,  2394,
   -1795,  2198,  1868,  1869,  1496,  1959,   103,   104,   269,  1871,
    1872,  1255,   296, -1795,   105,  1292,  2778,   266,   302,  1196,
     381,  2583,   932,     3,     4,  1018,     5,     6,  2394,   330,
    2708,     7,  2397,  1007,  2398,  2399,  2400,  2401,  2402,  2403,
    2210,  2211,  2212,  2213,  2394,   344,  2240,   346,     8,     9,
    1150,  2397,    97,  2398,  2399,  2400,  2401,  2402,  2403,  2210,
    2211,  2212,  2213,  2257,  2666,  1294,    10,    11,  2566,    72,
    2536,  2537,  2538,  2539,  2493,  1018,  2906,   259,   260,   261,
     262,   263,  1529,   389,  1739,  2994,   557,   646,  1582,  1256,
    2686,  1560,   383,  2214,  2215,  2216,  2217,  2218,  2219,   932,
    2263,   392,   986,   987,  1595,  1153,   303,  3070,   813,  1802,
    1554,  2995,  2214,  2215,  2216,  2217,  2218,  2219,   392,   141,
    1251,  2908,   259,   260,   261,   262,   263,  1632,    56,   988,
     989,   990,  2499,   304,   408,  1535,  2009,   408,   398,  2012,
    3088,   932,    61,  1616,  1617,   408,  2260,  1256,   400,   638,
     648,  1971,  1182,  1183,  1507,  2421,   932,  1227,  2943,  2208,
    1816,   330,  2390,   330,  1595,   655,  2741,   404,  1133,   933,
    1188,  1379,  1271,  2322,  1013,  1134,   778,  1154,  1015,  3056,
    1371,  1337,  2068,  2794,  3021,  1868,  1869,  1008,  2153,   787,
     408,   269,  1871,  1872,  2572,   682,  1196,   685,  2647,   656,
     691,   696,  2576,   698,  1196,    63,   701,  2046,  2026,    61,
      69,  2026,  1380,  2049,   934,  2072,  3026,   707,  2074,  2247,
    3027,  2415,  1189,  1014,   768,  1852,    34,  2415,  1874,  2389,
    2743,  2392,  2795,  3022,  2909,   940,   707,  1503,  1599,   649,
    2094,  1651,  2095,  1875,  1633,  2441,   768,  1972,  2457,   707,
     924,  2457,  2441,  2404,  2497,  2570,  2592,  2413,  2670,   801,
      33,   962,   650,  2748,   720,  2748,  3024,  2771,   106,  2775,
    2886,  2900,  2404,  2687,  2923,   817,   819,  2923,  3079,    82,
     864,  1561,   691,  1740,  2688,  1303,  1951,  3016,  1300,    72,
     768,  3061,   817,   817,   107,  1272,   814,  3039,  1599,  3058,
     768,   768,  1252,   893,   768,  2997,    77,  2997,   768,  1166,
     768,  1272,  2513,    79,   768,  1967,   768,   935,   911,   815,
     911,   817,  3089,   911,   817,  1395,   911,    76,  1397,  1398,
    1399,  1210,  2998,  1213,  1530,  2648,  1768,  2649,  2258,  1771,
     259,   260,   261,   262,   263,  2494,    82,  1417,   384,  1376,
    1232,  2833,  2422,   925,  1634,  1378,  2567,  2568,  1874,   380,
    1400,   187,  2395,  1167,  2369,   108,   934,  2154,  2903,  1638,
    1003,   267,   341,  1875,  2069,   402,  2709, -1795,  1199,  2462,
    2581,   669,  2002,  2528,   382,  2766,   694,  2680,  1718,  1625,
    1626,  2419,  2526,  2823,   935,  1818,   792,  2126,  1636,  1465,
     130,  1287,   815,   864,   826,   864,  2814,  2639,  2814,  2584,
    2818,  1479,  1508,  2136,  2818,   899,  2873,  1018,  1509,  1510,
    1511,    82,  2501,    82,  2527,    95,  1334,   960,    82,  2405,
    2509,  2510,  1130,    82,  2199,  1335,   935,   974,  1512,  1904,
      82,  1676,    82,  1216,  1618,   816,  2575,   390,  2405,  1141,
    1500,   935,    82,  1257,   272,   981,  2225,   408,  1501,   109,
     272,  1862,   690,  2445,  1792,  1557,  1200,    82,   691,  1480,
      82,  2907,  1485,  1460,    82,   936,   937,   938,  2330,    82,
   -1795,  1179,  2561,  1019,  1202,  2737,   939,   272,  1186,    82,
      82,  1904,  1532,   768,   768,  1527,  1466,  1744,   132,   991,
      82,  1960,   399,  1253,   694,   272,  2650,    82,   768,  2860,
     272,  1257,   401,    82,   768,   768,  2716,  1544,  2983,   768,
    2721,  2268,  1547,    82,    89,   272,   136,  1748,  2699,   768,
    1384,   405,  2436,  2437,  2417,   272,  1254,  1147,  2084,   272,
     110,  1874,  1016,  2714,    82,  1338,  1513,  1545,   111,  1514,
    -614,   272,    82,    82,  2844,  1560,  1875,    82,  1019,   141,
    1734,  1565, -1795, -1795, -1795, -1795, -1795,  1540,  1839,  2053,
     143,  1343,  2027,  1515,  3015,  2041,   690,  2050,  2481,  2073,
    2889,  2890,  2075,  2248,   272,  2416,   729,   992,  2084,  1586,
    1587,  2418, -1795,  1516,  1354,  2654,  1377,  2656,   182,   190,
    3045,  2894,   768,   768,  2406,   145,  2643,  1355,  2645,  2442,
    1988,   733,  2458,  1595,   193,  2459,  2464,   649,  2498,  2571,
    2593,  2638,  2671,  2406,  3052,  2407,  3053,  2749,  1517,  2754,
     993,  2772,   194,  2669,  2887,  2901,  2673,   768,  2924,  1639,
     650,  2925,  1340,   768,  2407,  1342,  1916,  1719,  1518,  1519,
    1640,  3017,   190,  2763,  2744,   768,  2054,  1917,   190,  1520,
     768,  3040,  2565,  3059,  1521,  1225,  1084,  1085,  1086,  3060,
    2410,  3085,  1641,  2055,   413, -1795,    33,    34,    81,  1642,
    -614,  2013,   653,  1243,  1343, -1795,  2934,  2814,  2936,  1795,
    2818,   195,   337,  1796,   198,   742, -1795,  1639,   768,  2981,
    1148,  2339,    17,  1522,  1920,  2530,  2476,  2372,  1640,  2701,
    1344,  2702,   768,  2988,  1729,  1921,  2056,  1087,  1088,  1089,
    1090,  1091,  1092,   234,  1970,    17,   233,   680,  2885,   190,
    1641,   190,   241,  1093,  1094,  1095,  1523,  1642, -1795,   249,
   -1795,  2482,  1483,  1592,  1406,  1561,  1593,  1599,  1594,  1407,
    1408,  1409,  2767, -1795,     3,     4,  2057,     5,     6,   690,
   -1795, -1795,     7,  2732,  2847,  1351,  2848,   272,  1595,  1359,
    1368,  1359,  1767,   250,  2784,  1770,  2162,    42,  1596,     8,
       9,  1462, -1795,  1462,   691,  2058,  1345,   691,   747,  1383,
    1386,  1795,   252,   698,  2059,  1796,  1797,    10,    11,  1798,
     749,   750,  1391,   955,   956,   190,   253,   817,   768,   752,
     817,   817,   817,   817,  3057,   768,  1843,   254,   768,  2150,
    1597,  1595,  2531,  1344,  1598,  1357,  1817,  1406,   257,   817,
    2874,   768,  1407, -1557,  1409,   768,  2230,   265,  1659,   285,
    2387,  1358, -1795,   768,  1346,   768,   768,   286,   768,   768,
     768,   768,   768,   768,   768,   768,   768,   768,   768,   768,
     768,   768,   768,   768,   768,   288,  1354,   289,    12,  3065,
    2875,   290,  2877,  1859,  1096,   768,   768,  1097,   776,  1355,
     768,  1948,   768,   294,  1371,  2435,   898, -1795,  1907,  1909,
     902,   295,   785,  1595,   906,   704,   790,  1456,  1797,  1345,
     297,  1798,  1599,   274,   301,   691,  1347,   279,   804,   306,
   -1795,   768,   768,   768,   315, -1795,   324,     3,     4,  1659,
       5,     6,   817,  1595,  1482,     7,  1486,   817,   325,   781,
     331,   768,  2532,  1927,   334,   786,  2742,   788,  1118,  2262,
     335,   795,     8,     9,   795,  3026,  1807,   795,   336,  3027,
    2977,  2978,  1624,  2892,  1600,  1599,    43,   807,  1628,  1354,
      10,    11,   340,  2320,   342,   133,   134, -1795,   768,   343,
      44,   347,  1355,   348,   817,  2425,   854,  2427,  2428,  2989,
     353,  2443,   351,  1660,   867,   870,   873, -1795,  2080,   352,
     894,   354,  1667,   768,  1832,    45,  1098,  1542,   904,   817,
     817,  1673,  1661,  1662,   817,  1229, -1795, -1795,  1551,  1552,
     768,  1099,  -265,   357,   928,  1100,   358, -1795, -1795,  1347,
     768, -1795,  1663,   368, -1795,  2948, -1795,  1599,   369,  1119,
     372,    12,   133,   134,   691,  1928,  3001,   883,  1024,  1025,
    1026,   911,   817,   817,    46, -1795,  2250,  2127,   377,  2128,
    2085,  1356,   387,  1101,  3047,   949,  3049,  1599,  2139,   915,
     133,   134,   918,   388,  1660,   921,   950,  1620,   826,    15,
    1019,  1019,   391,  3019,   396,  1629, -1795,  1629,   395,  1019,
   -1795,  1102,   397,  1661,  1662,   403,   806,   884, -1795,   864,
    2323, -1795, -1795,  1404,  1405,   812,  1230,  1357,   406,  -265,
    1103,  -956,   974,  1663,   414,  2315,  1592,  1716,   654,  1593,
     659,  1594, -1795,  1358,   661, -1795,  -265, -1795,   951,  1569,
     134,   662,  1019,   663, -1795,   885,   668, -1795,  1646,  1647,
     670,  1595,   672,   952,  1359,   678,  1289, -1795,  1601,   307,
     914,  1596,   673,   917,  1370,  1368,   674, -1795,  1359, -1795,
     676,   711,   711,   679,  2799,  1654,  1655,   677, -1795,  -265,
    1924,  1018,  2944,  2522,  1808,  1809, -1795,  1725,  1726,  1727,
     936,   937,  2969,  2815,   928,  2815,   681,  2560,    82,  2891,
    1180,  1181,  1104,  1597,  1184,  1185, -1307,  1598,  2192, -1795,
    1357,   815,   964, -1795,   259,   260,   261,   262,   263,  -265,
     965,   966,  2948,   768,   768,   768,  1358,   768,  1980,   967,
     968,   969,  1868,  1869,   970,  1870,   971,  1981,   269,  1871,
    1872,   972,   886,   953,   977,  2800,   308,   973,  -265,   978,
    3048,   979,    15,   768,   980,  1006,  1777,  -265,  1873,  1290,
     984,  1982,  1121,   309,  1983,    82,   711,  1291,  2675,  1105,
     768,  2677,   689,  1292,  1008,  1293,   926,  1205,  1206,  1207,
    1208,  3031,  1984,  1009,  1012,  1599,  1294,  1018,  1805,  1929,
    1011, -1795,  1017,  1021,   768,  2221,  1812,  1813,   768,   817,
    2969,  1029,  1930, -1795,  1030,  1152,   310,  1032,  1033,  1034,
     727,  2801,  1035,  2802,  1295,  1036,  1037,  1127,   887,  1169,
    1169,  1169,   728,  1169,   316,  1169,  1169,  1038,  2803,   768,
    1296,    89,    89,  1135,   768,  1297,  2804,  1600,  1039,  1040,
    2805,  1051,  1052, -1795,  1841,  1053,   311,  1298,   768,  1056,
    2096,  1057,  1060,  1062,  1299,   768,  1063,  1064,  3031,   888,
    1065,  1066,  2373,   768,  1067,  2806,  1931,  2438,  1068,  1070,
    1243,  1120,  1888,  1932,   873,   312,  1131,  1042,  1132,  2374,
    2375,  1136,  1138,  1139,   313,  1238,  1144,  2376,  1985,  1146,
     817,   817,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1149,  1158,  1163,   817,  1143,  1177,   928,
    1121,   317,  1933,  1187,  2465,  1190,  1211,  1219,  1275,  1220,
    1221,  2377,  1222,  1223,  1226,  1019,  1228,   889,   318,  1240,
    2378,  1231,   826,  1888,  1283,  1283,   926,  1934,   864, -1795,
    2793,  1242,  1986,  1263,  1996,  1264,  1232,  1935,  1936,  1987,
    2728,  1087,  1088,  1089,  1090,  1091,  1092,  2008,  2008,  2379,
    1262,  2008,   864,  1937,  1043,  1196,   744,  1093,  1094,  1095,
    2727,   319,  1265,  1270,  2815,  1274,  1277,  1888,  1278,  2042,
    2042,  1044,  1117,  2042,  1888,  1938,  1279,  1280,  1939,  1940,
    2928,   890,  1325,   190,  1941,  1333,  1350,  1336,  1353,  1367,
    2210,  2211,  2212,  2213,  2380, -1795,  1373, -1795,  1382,  1300,
    2076,   320,  1389,  1390,  1374,  1383,  1301,  1416,  1391,   768,
    1392,  1601, -1795,  2053,  1045,  1393,  1359, -1795,  1401,  1418,
   -1795,  1415,  1423,  1888, -1795,   746,  1451,  1454,  1302,  1459,
     321,  1458,  1492,  1303,   748, -1795,  2381,  1472,  2552,   322,
    2554,  1942,  1478,  2214,  2215,  2216,  2217,  2218,  2219, -1795,
    1494,  1202,  2684,  1943,  1046,   768,    82,  1490,   768,  1505,
    1531,     1,  1506,  1533,  1534,  1536,  1359,  1543,  1538,  1557,
     768,   768,   768,   768,  1548,  2042,  1546,  1564,  1874,  2800,
    1572,  2141,  1805,  1047,  1272,  2146,  2146,  2730,  1566,  1574,
    1496,  1608,  1048,  1875,   768,  1457,  1610,  1611,  1096,  1613,
    2054,  1097,  1619,    89,  2158,    89,   873,   795,  1668,  1679,
    1876,  1681,   754,  1877,  1473,   807,  1682,  2055,   873,  1685,
    1686,  1712,   190,  1714,  1717,  1488,  1878,  2210,  2211,  2212,
    2213,  1720,     3,     4,   784,     5,     6,  1721,   928,  2657,
       7,   926,  1730,  1731,  1732,  2801,  1733,  2802,  2851,  1736,
    1738,   768,  1745,  2190,  2199,  1747,  2859,     8,     9,  1749,
    2056,  1750,  2803,  1752,    89,  1888,  2896,  1880,  1755,  1776,
    2804,  1779,  1781,  1782,  2805,    10,    11,  1783,   856,  1881,
    2214,  2215,  2216,  2217,  2218,  2219,   691,  1784,   875,   881,
    1785,  1787,   897,  1788,  2231,  1789,   901,  1791,   903,  2806,
    2057,  1793,   907,  1549,   909,  2606,  2607,  2608,  1790,  2610,
    2611,  2612,  2613,  2614,  2615,   826,   826,  2676,  2618,  1794,
    1098,  1882,  1806,  1271,  1819,  1821,  2658,  1576,  1822,  2058,
    1823,  1827,  1579,  1830, -1795,  1099,  1836,  1019,  2059,  1100,
    1837,  1845,  1838,  2659,  2710,  1606,   928,   646,  1842,  1846,
    1849,  1855,  2042,   646,  1863,  1888,  1865,  1867,  1898,  1899,
    1883,  2691,  2266,  1629,  1900,   939,  1904,  1906,  1946,   768,
    1947,   768,  1884,  1300,  1958,  1975,  1964,  1101,     1,  2042,
    1974,  1019,  1991,  1993,  1885,  1886,  2660,  2684,  1994,  1995,
    2008,  2005,  2016,  1887,  2017,  2018,   690,  2022,  2077,  2025,
    1653,  2062,  2968,  2063,   272,  1102,  2079,  2064,  2082,  2065,
     648,  2066,  2067,  2042,  2091,  2092,   648,  1888,  2093,  1888,
    2112,  2099,  2723,  2102,  1103,  2113,  2661,  2117,  2114,  2725,
    2118,  2120,  2122,  2210,  2211,  2212,  2213,  1359,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  2692,     3,
       4,  2124,     5,     6,   873,  2662,  2135,     7,  2140,  2155,
    1368,  2157,  1359,  2165,  2663,  2693,    13,  2167,  2168,  2170,
    1725,  2171,  2169,   768,     8,     9,  2189,  2172, -1795,  2188,
     926,  2209,  2201,  2202,   938,  3000,  2214,  2215,  2216,  2217,
    2218,  2219,    10,    11,  2203,  2204,  1087,  1088,  1089,  1090,
    1091,  1092,  2205,  2206,   688,  2207,  1104,  2229,  2694,  2232,
     768,   768,  1093,  1094,  1095,    14,  2234,   706,  2241,  2243,
     768,  2249,  2253,   768,  2254,  2261,  2264,  3055,  2474,  2269,
    2325,  2316,  2327,   711,  3032,  3033,  3034,  3035,  3036,  3037,
    2684,  1805,  2684,  2489,   779,  2491,  2326,  2328,  2695,  2388,
    2333,  2976,   768,  2396,   768,  2212,  2213,  2412,  2505,  2413,
     796,   797,   768,   768,  2213,  2423,   803,  2420,  2426,   805,
    2439,  2444,  2429,  1105, -1741,  2448,  2449,  2696,  2450,  2526,
     768,  2210,  2211,  2212,  2213,  2452,  2697,  2853,   926,  2042,
     856,  1888,  2451,  2453,  2454,  2455,  1888,  1888,  1888,  1888,
    1888,  1888,  2456,  2460,  1826,  2463,  2214,  2215,  2216,  2217,
    2218,  2219,  2850,  1834,  2214,  2215,  2216,  2217,  2218,  2219,
     817,  2466,   817,   873,  2468,  1195,  2469,  2210,  2211,  2212,
    2213,   856,  2473,  2475,  2214,  2215,  2216,  2217,  2218,  2219,
    2479,  2483,  2487,   875,   182,  2488,  2490, -1795,  1218,  2508,
    2518,  2520,  2042,  1096,  2524,  2548,  1097,  1888,  2551,  2562,
    2563,  1087,  1088,  1089,  1090,  1091,  1092,  2572,  2394,  2579,
    2792,  2214,  2215,  2216,  2217,  2218,  2219,  1093,  1094,  1095,
    2214,  2215,  2216,  2217,  2218,  2219,  2718,  2594,   873,  1950,
     873,  2581,  2604,  2590,   867,    48,    49,    50,    51,    52,
      53,  2605,    54, -1795,  2042,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  2609,  2595,  2596,  1996,  2098,  2616,  2740,  2617,
    2100,  2599,  2623,  2684,  2627,  2103,  2000,  2628,  2624,  2107,
    2953,  2109,  2110,  2111,  2629,  2630,  2631,  2632,  2633,  2642,
    2199,  2644,  2652,  1753,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1344,  2655,  2665,  2667,
    1967,  2672,  2678,  3091,  2674,  1098,  1093,  1094,  1095,  2700,
    2706,  2711,  1888,  2712,  1888,  2878,  2210,  2211,  2212,  2213,
    1099,  2713,  2714,  2719,  1100,   873,  2726,  1888,  2731,  2735,
    2745,  2042,  2746,  2042, -1795,   933,  2759,  2777,  1087,  1088,
    1089,  1090,  1091,  1092,     1,  2769,  2781,  2782,  1096,  2785,
    2789,  1097,  2790,  2797,  1093,  1094,  1095,  2824,  2826,  1359,
    2827,  2829,  1101,  1019,  2830,  2831,  2832,  2835,     2,  2214,
    2215,  2216,  2217,  2218,  2219,   768,  -614,  2838,  2843,  2846,
    2845,  2852,  2856,  2849,   873,  2858,   873,  2862,  2864,  2867,
    1102, -1795,  2865,  2869,  2876,   873,  2884,  2146,  2893,  2921,
    2720,  2146,  2445,  2922,  2926,   817,  2930,  2933,   768,  1103,
    2410,  2932,   817,  2940,  2951,     3,     4,  2954,     5,     6,
    2975,  1889,  2967,     7,  2966,   768,  2997,  2982,  2999,  1467,
    1468,  1469,  2984,  2163,  3018,  3020,   768,  3014,  3025,  3042,
       8,     9,  3038,  3050,  3062,  3074,  2504,  1096,  3051,  1491,
    1097,  1888,  3073,  2440,  1888,  1888,  1888,  1888,    10,    11,
    3084,  2180,  2185,  2880,   768,  2210,  2211,  2212,  2213,  3086,
    1098,  2461,  1556,  1854,    70,    71,   558,  2142,  2486,  2151,
     349,  2760,  1889,  1888,   197,  1099,  1528,   202,  2042,  1100,
     281,  1104,   345,   671,   864,  1096,  1670,  2266,  1097,  1671,
     350,   407,  2042,   283,  2222,  1579,  2101,   658,   664,  2881,
    2042,   875,  1620,   376,   374,   665,  2703,  3071,  2214,  2215,
    2216,  2217,  2218,  2219,  1829,  2119,  1889,  1101,  1553,    12,
     892,  1741,  1329,  1889,  2006,  2014,  2131,  1814,  1568,  1375,
    1589,  1585,  2550,  2758,  2228,  2138,  3077,  1903,  1925,  2558,
    2556,  1487,  2861,    65,   139,  1102,   156,    66,  1105,   963,
     691,  2810,   691,    67,  1861,  1864,  1570,  1888,   802,  1098,
     339,   983,  1607,  2825,  1103,  2223,  1268,  2798,  2912,  1866,
    1474,  1526,  1889,  1961,  1099,  3046,  2541,  1464,  1100,  2637,
    2920,  1214,  1539,   139,  2636,  2619,  2385,  1424,  1019,  2905,
    1388,  2125,  2836,  1713,  2841,  1680,  2329,  2255,  3078,  3002,
    3067,  2324,  2386,  2653,  2051,  2685,  2640,  1098,  2834,  2641,
    2393,  3010,  2929,  2821,   817,  2816,  1101,  2597,  1623,   768,
    2931,  1318,  1099,  2949,  2888,  2950,  1100,  2578,  2580,  3066,
    3012,  2540,  1615,  2987,  1868,  1869,  1583,  1870,  2078,    13,
     269,  1871,  1872,  1285,  1102,   415,  1104,  1331,  2774,  1481,
    1888,     0,     0,     0,     0,     0,  1888,     0,  2882,     0,
    1873,     0,     0,  1103,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   873,     0,     0,  1895,     0,  2042,
       0,     0,     0,     0,     0,  1888,     0,     0,    14,  2042,
    1888,     0,  1102,     0,     0,     0,     0,  2911,     0,     0,
       0,     0,     0,     0,     0,  2194,  2196,     0,     0,     0,
       0,  1103,     0,  1105,  1889,     0,  1868,  1869,     0,  1870,
      15,   873,   269,  1871,  1872,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2210,  2211,  2212,  2213,  1978,     0,
       0,  1019,  1873,  1019,     0,  1104,  1888,     0,     0,     0,
       0,  2042,     0,  2841,  1579,     0,     0,     0,  1786,     0,
       0,     0,  2502,     0,   704,     0,  2506,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2517,
       0,     0,  1811,     0,     0,     0,  1469,  2214,  2215,  2216,
    2217,  2218,  2219,  1104,  2760,     0,     0,     0,     0,  1888,
       0,  1888,     0,  1888,  1889,     0,     0,  2883,  2042,     0,
       0,  1888,  1105,     0,     0,     0,  1620,  1195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   691,     0,     0,     0,     0,  1888,     0,  1978,     0,
       0,     0,     0,  1851,     0,     0,     0,     0,  1888,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1105,     0,     0,     0,     0,     0,  1889,     0,  1889,     0,
     684,     0,   684,   684,   768,  3043,     0,     0,     0,     0,
       0,     0,   768,     0,     0,     0,   684,     0,     0,  2028,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   684,  1888,  1889,   684,     0,     0,
       0,     0,     0,   684,     0,     0,     0,   684,     0,     0,
       0,   684,     0,  2598,  1019,   684,  1888,     0,  2042,   684,
     684,     0,   684,     0,     0,   684,     0,   684,   684,   684,
       0,     0,     0,     0,     0,   684,     0,     0,   684,     0,
       0,     0,     0,     0,     0,   684,     0,     0,     0,     0,
     684,     0,     0,  2620,     0,     0,  1888,     0,   684,     0,
    1888,  2028,     0,     0,     0,     0,  2635,     0,     0,   684,
    2200,     0,   768,   684,     0,     0,     0,   684,     0,     0,
    1874,     0,     0,   684,     0,     0,   684,     0,     0,     0,
       0,     0,     0,     0,     0,  1875,     0,  2081,     0,  1649,
    1650,     0,     0,     0,     0,     0,  1666,     0,     0,     0,
       0,     0,  1876,     0,     0,  2029,     0,     0,     0,     0,
       0,     0,     0,     0,   873,     0,     0,  2030,  1878,     0,
    1889,     0,     0,     0,     0,  1889,  1889,  1889,  1889,  1889,
    1889,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   873,     0,     0,     0,     0,  2199,     0,  2129,  2130,
    1469,  2133,  1874,     0,     0,     0,   190,     0,     0,  1880,
       0,     0,     0,     0,     0,     0,     0,  1875,     0,  2342,
    2343,  1881,  2156,  2344,  2345,  2346,     0,     0,   928,     0,
       0,     0,     0,     0,  1876,     0,  1889,  2029,     0,     0,
       0,     0,     0,     0,     0,   190,     0,     0,     0,  2030,
    1878,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2391,  1882,     0,     0,     0,     0,  1027,  1028,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2187,
       0,     0,     0,  1041,     0,     0,     0,     0,     0,  1054,
    1055,  1880,     0,     0,  1059,     0,     0,     0,     0,     0,
       0,     0,  1883,  1881,  1069,     0,  1579,     0,     0,     0,
       0,   711,   711,   711,  1884,   711,   711,   711,   711,   711,
     711,     0,     0,  2347,   711,     0,  1885,  1886,  2031,     0,
    2348,     0,     0,     0,     0,  1887,     0,     0,   690,     0,
       0,     0,     0,     0,     0,  1882,   272,     0,  2620,     0,
       0,     0,     0,     0,     0,     0,     0,  1835,     0,     0,
       0,  1889,     0,  1889,  2349,     0,     0,     0,     0,     0,
       0,     0,     0,  2350,     0,     0,  1889,     0,     0,     0,
       0,     0,     0,     0,  1883,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1884,  2317,     0,  2318,
    1901,     0,  2351,  2352,     0,     0,     0,     0,  1885,  1886,
     684,     0,     0,     0,     0,     0,     0,  1887,     0,     0,
     690,     0,     0,     0,     0,     0,     0,     0,   272,     0,
       0,     0,     0,     0,   873,     0,  2534,     0,     0,     0,
       0,  2534,  1895,  2542,  2543,  2544,  2545,  2353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     926,     0,  2164,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  2354,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,  1978,  1889,  1889,  1889,  1889,     0,  1579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2620,     0,     0,     0,     0,  2915,     0,  2917,
       0,     0,  1889,   684,   684,   684,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,     0,  2355,     0,     0,  2467,     0,
       0,  2472,     0,  1093,  1094,  1095,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   873,
       0,     0,     0,     0,     0,     0,     0,   873,     0,     0,
       0,     0,     0,  1396,     0,     0,     0,     0,     0,     0,
    1403,     0,   928,  1414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1419,     0,   856,  1889,
    1422,  1889,     0,  1889,     0,     0,  1889,  1889,  1428,     0,
    1430,  1431,     0,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,
       0,     0,  2651,     0,     0,     0,     0,     0,     0,     0,
    1449,  1450,     0,     0,     0,  1452,     0,  1453,     0,     0,
       0,     0,     0,  2176,  2177,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2186,     0,     0,     0,     0,     0,
    1169,  1169,  1169,  1169,  1169,  1169,     0,     0,     0,     0,
       0,     0,     0,     0,  1096,     0,     0,  1097,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1889,
       0,     0,     0,     0,     0,  1889,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2236,  2237,  2238,
    2239,     0,     0,     0,     0,  1687,     0,     0,     0,     0,
       0,     0,  2245,     0,  1889,     0,     0,     0,     0,  1889,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,     0,     0,     0,     0,     0,  2747,     0,     0,  2750,
    2751,  2752,  2753,     0,     0,  2356,  2357,  2358,  2359,  2360,
    2361,  2362,  2363,  2364,  2365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1978,     0,
       0,     0,     0,     0,     0,  1889,  1087,  1088,  1089,  1090,
    1091,  1092,     0,     0,   928,     0,  1098,     0,     0,  2331,
    2332,     0,  1093,  1094,  1095,     0,  2336,  2337,  1571,     0,
       0,  1099,     0,     0,   926,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1889,     0,
    1889,     0,  1889,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,     0,  1101,     0,     0,     0,     0,     0,     0,
       0,     0,  2820,     0,     0,     0,     0,     0,     0,     0,
    1889,     0,     0,  1889,     0,  1889,     0,     0,     0,     0,
       0,  1102,     0,     0,     0,     0,  2724,  1889,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2738,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1868,  1869,
       0,  1870,     0,     0,   269,  1871,  1872,     0,     0,  2477,
    2478,     0,  2755,  1096,  1889,     0,  1097,     0,  2485,     0,
    1688,     0,     0,     0,  1873,  1978,  2496,     0,  1756,  1757,
    1758,  2879,  1760,     0,     0,  1889,     0,     0,     0,     0,
       0,     0,     0,     0,  2511,  2512,  1087,  1088,  1089,  1090,
    1091,  1092,  1104,     0,     0,     0,     0,     0,  1775,     0,
    2899,     0,  1093,  1094,  1095,  2899,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1889,     0,     0,  1689,  1889,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1690,     0,     0,     0,     0,     0,     0,     0, -1796,  2553,
    1691,  2555,     0,     0,     0,     0,   926,     0,  2557,     0,
    2559,     0,     0,     0,     0,     0,     0, -1796,  1692,  1105,
       0,  2939,     0,     0,     0,     0,   684,     0,  1693,     0,
       0,  1694,     0,     0,     0,  1098,     0,     0,     0,  1831,
       0,     0,     0,     0,  1695, -1796,     0,     0,     0,     0,
    1099,     0,     0,  1775,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1978,     0,  2993,  2854,  2996,     0,
       0,     0,     0,  1868,  1869,     0,  1870, -1796,     0,   269,
    1871,  1872,  1101,  1696,     0,     0,     0,     0,     0,     0,
    2600,  2601,     0,  1096,  2602,  2603,  1097,     0,     0,  1873,
       0,  3013,     0,     0,     0,     0,     0, -1796,     0,     0,
    1102, -1796,     0,  1697,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1698,     0,     0,     0,     0,  2626,  1103,
       0,     0,     0,     0,     0, -1796,     0,     0,   684,     0,
       0,     0,     0, -1796,  1699, -1796,     0,  1700,     0,  1701,
       0,     0,     0,     0, -1796,     0,     0,     0,     0,   684,
   -1796,     0,     0,     0,     0,     0,     0,     0, -1796,     0,
    2899,     0, -1796,     0,     0,     0,     0,  1702, -1796,     0,
       0,     0, -1796, -1796, -1796, -1796,  1703,     0,     0,     0,
       0,  2939,     0,     0,     0,     0,     0, -1796,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1104,     0,     0, -1796,  1098,     0, -1796,     0, -1796,
       0,     0,     0,     0,     0,     0, -1796,     0,     0,     0,
    1099,  2993,     0,     0,  1100,  2899,  2717,     0,   139, -1796,
    2722,     0,     0,     0,  1874,     0,     0,     0,     0, -1796,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1875,
    2115,     0,     0,  2115,     0,     0,     0,     0, -1796, -1796,
    2736,     0,  1101,     0,     0,     0,  1876,     0,  1105,  1877,
       0,     0,     0, -1796,     0,     0,     0,     0,     0,     0,
       0, -1796,  1878,     0,     0, -1796,     0,     0,     0,     0,
    1102,     0,     0,  2756, -1796, -1796, -1796,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1103,
       0,     0,  3041,     0,     0,     0,     0,     0,  2028,     0,
       0,     0,  1879,  1880,     0,     0,     0,  2210,  2211,  2212,
    2213,     0,     0,     0,     0,  1881,    72,     0,     0,     0,
       0,     0,     0,     0,     0,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,     0,     0, -1796,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0, -1796,     0,     0,  1882,     0,     0,
    2214,  2215,  2216,  2217,  2218,  2219,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092, -1796,  1883,     0,     0,  1874,
    3083,     0,     0,     0,     0,  1093,  1094,  1095,  1884,     0,
       0,     0,     0,     0,  1875,     0,     0,     0,     0,     0,
    1885,  1886,     0,     0,     0,     0,     0,     0,     0,  1887,
       0,  1876,   690,     0,  2029,     0,     0,     0,  1105,     0,
     272,     0,     0,  2251,     0,     0,  2030,  1878,     0,     0,
       0,     0,   684,     0,     0,     0,     0, -1796,   684,     0,
       0,     0,     0,     0,     0,  2872,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   684,     0,     0,     0,     0,     0,  1880,     0,
       0,     0,     0, -1796,     0,     0,     0,     0,     0,     0,
    1881,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2414,     0,     0,
   -1796,     0,  1882,     0,     0,     0,  1096,     0,  2271,  1097,
       0,     0,     0,     0, -1796, -1796, -1796, -1796, -1796, -1796,
   -1796,     0, -1796, -1796,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1796,
       0,  1883,     0,     0,     0,  1775,  1775,     0,  2272,  2273,
    2274,     0,     0,  1884,     0,     0,     0,  2979,     0,     0,
       0,     0,     0,     0,     0,  1885,  1886,  2031,     0,     0,
       0,     0,     0,  2275,  1887,     0,     0,   690,     0,     0,
       0,  2276,     0,     0,     0,   272,  2277,  2500,     0,  1775,
       0,     0,     0,     0,     0,     0,     0,  1775,  1775,  3003,
    3004,  2278,  3006,     0,  3008,  3009,  2279,     0,  2280,     0,
       0,     0,     0,     0,     0,  2281,     0,     0,  2282,     0,
       0,  2283,     0,     0,  2284,     0,     0,  2285,  1098,     0,
       0,     0,  2286,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1099,     0,     0,     0,  1100,  1420,     0,
    2287,  2525,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2288,     0,     0,  2289,
    2290,  3054,     0,     0,     0,     0,  2291,     0,     0,     0,
       0,     0,     0,     0,     0,  1101,     0,  2292,     0,     0,
       0,  3063,     0,  3064,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2293,     0,   684,   684,     0,     0,     0,
    2294,     0,     0,  1102,     0,     0,     0,  2295,     0,     0,
    2296,  2297,  2298,     0,  2299,  2300,     0,     0,     0,     0,
    3075,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,  2301,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,     0,     0,     0,  3080,  3081,     0,     0,  3082,     0,
       0,     0,     0,     0,     0,  2302,  2303,  2304,  2305,     0,
    2306,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2307,  2308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,     0,
    2309,     0,     0,     0,  1104,  1093,  1094,  1095,     0,  2310,
    2311,     0,  2312,     0,     0,     0,     0,     1,     0,     0,
       0,   417,   418,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   419,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,     0,     0,     0,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   423,   424,   425,
    2704,  1105,     0,     0,  2313,     0,     0,     0,     0,     0,
       0,     0,     0,   426,     0,   427,   428,   429,     3,     4,
     430,     5,     6,   431,     0,   432,     7,   433,   434,     0,
       0,     0,     0,     0,   435,     0,     0,   436,     0,   437,
     438,   439,     0,     8,     9,     0,     0,     0,     0,   440,
    1775,   441,   442,     0,   443,     0,   444,   445,     0,     0,
     446,    10,    11,     0,     0,   447,   448,   449,     0,   450,
     451,     0,     0,     0,   452,   453,  1096,   454,     0,  1097,
       0,   455,     0,   456,   457,     0,     0,     0,     0,   458,
       0,     0,     0,   459,     0,     0,   460,     0,   461,     0,
     462,     0,   463,     0,   464,   465,     0,   466,   467,   468,
       0,     0,     0,   469,     0,   470,   471,     0,   472,     0,
       0,     0,     0,     0,     0,     0,   473,   474,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   475,
       0,     0,   476,   477,  2768,     0,   478,   479,     0,     0,
     480,   481,     0,     0,     0,     0,     0,     0,     0,   482,
     483,   484,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   486,   487,   488,     0,   489,     0,     0,
       0,   490,   491,     0,     0,     0,   492,     0,     0,     0,
       0,     0,     0,     0,   493,     0,     0,     0,  1098,     0,
       0,     0,   494,   495,   496,     0,     0,     0,     0,     0,
     497,   498,     0,  1099,     0,     0,   499,  1100,     0,   500,
       0,     0,     0,   501,   502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   503,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   504,     0,     0,  1101,     0,     0,     0,     0,
     505,     0,     0,     0,     0,     0,   506,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1102,     0,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,     0,   507,     0,   508,   509,
       0,     0,  1103,     0,     0,     0,     0,   510,     0,     0,
       0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,     0,
       0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   511,  1093,  1094,  1095,
       0,     0,     0,     0,     0,     0,     0,   512,     0,     0,
       0,   513,     0,     0,     0,   514,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,     0,     0,     0,  1104,     0,     0,     0,     0,   515,
     516,  1093,  1094,  1095,   517,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   518,     0,     0,     0,
       0,     0,   519,   520,   521,   522,     0,     0,     0,   523,
       0,     0,     0,   524,     0,     0,     0,     0,     0,     0,
     525,   526,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,   528,     0,     0,     0,     0,     0,
       0,  1105,     0,     0,     0,   529,     0,   530,     0,     0,
     531,     0,     0,     0,     0,     0,   532,     0,     0,     0,
       0,     0,     0,     0,   684,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1096,     0,
       0,  1097,   533,     0,     0,   534,     0,     0,     0,     0,
       0,   535,     0,     0,   536,   537,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1775,     0,   538,
       0,     0,     0,     0,     0,     0,   539,     0,     0,     0,
       0,     0,  1096,     0,     0,  1097,     0,     0,     0,     0,
    1868,  1869,     0,  1870,     0,     0,   269,  1871,  1872,   540,
     541,   542,   543,   544,   545,   546,     0,     0,   547,     0,
     548,     0,   549,     0,     0,     0,  1873,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1868,  1869,     0,  1870,     0,  1099,   269,  1871,  1872,  1100,
    1737,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1873,  1093,  1094,  1095,
       0,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1101,     0,  1099,
       0,     0,     0,  1100,  1746,     0,     0,     0,     0,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,  1103,     0,     0,     0,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1103,  1093,
    1094,  1095,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,  1096,     0,
       0,  1097,     0,     0,     0,     0,  1104,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,  1087,  1088,  1089,  1090,
    1091,  1092,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,  1093,  1094,  1095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,     0,     0,     0,     0,     0,
    1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1093,  1094,  1095,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,     0,     0,
    1096,     0,     0,  1097,     0,     0,     0,  1105,     0,     0,
    1098,  1875,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1099,     0,     0,  1876,  1100,
    1751,  1877,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,  1097,     0,  1878,     0,     0,     0,     0,     0,
       0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1101,     0,     0,
       0,     0,  2199,     0,     0,     0,  1874,     0,     0,     0,
       0,     0,     0,  1096,     0,  1880,  1097,     0,     0,     0,
       0,  1875,     0,     0,     0,  1102,     0,  1881,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1876,     0,
       0,  2895,     0,     0,  1103,  1087,  1088,  1089,  1090,  1091,
    1092,     0,  1098,     0,  1878,     0,     0,  1096,     0,     0,
    1097,  1093,  1094,  1095,     0,     0,     0,  1099,     0,  1882,
       0,  1100,  1759,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1098,     0,     0,  2896,  1880,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1099,  1881,  1883,  1101,
    1100,  1761,     0,     0,     0,     0,     0,     0,     0,     0,
    1884,     0,     0,     0,     0,     0,  1104,     0,     0,     0,
       0,     0,  1885,  1886,     0,  1098,     0,  1102,     0,     0,
       0,  1887,     0,     0,   690,     0,     0,     0,  1101,  1882,
    1099,     0,   272,     0,  1100,  1762,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,  1883,     0,
       0,     0,  1101,  1105,  1099,  1103,     0,     0,  1100,  1763,
    1884,     0,  1096,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,  1885,  1886,     0,     0,     0,     0,     0,     0,
    1102,  1887,     0,     0,   690,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,  1101,     0,  1104,  1103,
       0,     0,     0,     0,     0,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,     0,     0,     0,  1102,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,     0,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,     0,  1105,     0,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,  1098,  1093,  1094,  1095,  1081,  1082,
    1083,  1084,  1085,  1086,     0,     0,     0,     0,     0,  1099,
       0,     0,     0,  1100,  1105,     0,     0,     0,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,     0,     0,     0,     0,  1104,     0,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,  1087,  1088,  1089,  1090,  1091,  1092,  1105,     0,
       0,     0,     0,     0,  1765,     0,     0,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,  1102,
       0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,  1103,     0,
       0,     0,  1105,     0,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1096,     0,     0,  1097,
       0,     0,     0,     0,     0,  1087,  1088,  1089,  1090,  1091,
    1092,  1868,  1869,     0,  1870,     0,     0,   269,  1871,  1872,
       0,  1093,  1094,  1095,     0,     0,     0,  1087,  1088,  1089,
    1090,  1091,  1092,     0,     0,     0,     0,  1873,     0,  1096,
    1104,     0,  1097,  1093,  1094,  1095,     0,     0,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,     0,     0,     0,     0,  1096,
       0,     0,  1097,     0,     0,     0,     0,     0,     0,     0,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,     0,     0,     0,  1868,  1869,     0,  1870,     0,
       0,   269,  1871,  1872,     0,     0,     0,  1105,     0,     0,
    1087,  1088,  1089,  1090,  1091,  1092,     0,     0,  1098,     0,
       0,  1873,     0,     0,     0,     0,  1093,  1094,  1095,     0,
       0,     0,     0,  1099,     0,     0,     0,  1100,     0,     0,
    1087,  1088,  1089,  1090,  1091,  1092,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1093,  1094,  1095,     0,
       0,  1098,  1096,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1101,  1099,     0,     0,     0,
    1100,     0,     0,     0,  1096,     0,     0,  1097,  1766,     0,
       0,  1098,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,     0,     0,  1099,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,  1769,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,  1101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1082,
    1083,  1084,  1085,  1086,     0,  1103,     0,  1096,     0,     0,
    1097,     0,     0,     0,     0,     0,  1102,     0,     0,     0,
       0,     0,     0,     0,  1098,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,     0,  1096,     0,  1099,
    1097,     0,     0,  1100,  1104,     0,  1098,     0,     0,     0,
       0,     0,  1087,  1088,  1089,  1090,  1091,  1092,     0,     0,
       0,  1099,     0,     0,     0,  1100,     0,     0,  1093,  1094,
    1095,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,  1104,     0,   715,
     716,     0,     0,     0,     0,   269,   717,   718,  -614,     0,
       0,     0,     0,  1101,     0,     0,     0,  1874,     0,  1102,
     719,  1105,     0,     0,     0,   720,     0,  1104,   829,     0,
       0,   721,  1875,     0,     0,     0,     0,   830,  1103,  1098,
       0,  1102,     0,     0,     0,     0,   831,     0,     0,  1876,
       0,   832,  1877,     0,  1099,     0,     0,     0,  1100,   722,
    1103,     0,     0,     0,  1105,  1878,     0,     0,     0,  1098,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1099,     0,     0,     0,  1100,     0,
       0,     0,     0,     0,  1105,   833,  1101,     0,     0,     0,
       0,  1874,     0,   834,     0,  2896,  1880,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1875,     0,  1881,  1096,
    1104,     0,  1097,     0,  1102,     0,  1101,     0,     0,     0,
       0,     0,     0,  1876,     0,     0,  1877,     0,     0,  1764,
       0,     0,  1104,  1103,     0,     0,     0,     0,     0,  1878,
       0,     0,   723,     0,  1102,     0,   715,   716,     0,   835,
    1882,     0,   269,   717,   718,  -614,     0,     0,     0,     0,
       0,     0,     0,  1103,     0,     0,     0,   719,     0,     0,
       0,     0,   720,     0,   836,     0,     0,  1105,   721,  2990,
    1880,   837,     0,   838,     0,     0,     0,     0,     0,  1883,
       0,     0,  1881,   839,     0,     0,     0,     0,     0,  1105,
       0,  1884,     0,     0,     0,     0,   722,     0,     0,     0,
       0,     0,     0,  1885,  1886,  1104,     0,     0,     0,   840,
       0,     0,  1887,     0,     0,   690,     0,   841,     0,     0,
       0,  1098,     0,   272,  1882,     0,     0,     0,     0,   724,
       0,     0,     0,     0,   725,  1104,  1099,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   842,     0,     0,     0,     0,     0,
       0,     0,   726,  1883,     0,     0,     0,     0,     0,     0,
       0,     0,  1105,     0,     0,  1884,     0,     0,  1101,     0,
     843,     0,     0,     0,     0,     0,     0,  1885,  1886,   723,
       0,     0,     0,     0,     0,     0,  1887,   727,     0,   690,
       0,     0,  1105,     0,     0,     0,  1102,   272,     0,   728,
       0,     0,     0,     0,     0,     0,     0,     0,   844,     0,
       0,     0,     0,     0,     0,  1103,     0,   729,     0,   845,
       0,     0,   730,     0,     0,   731,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   732,     0,   715,   716,
       0,     0,   733,     0,   269,   717,   718,     0,     0,     0,
       0,     0,   734,     0,     0,     0,     0,   735,     0,   719,
     736,     0,     0,   737,   720,     0,     0,     0,     0,     0,
     721,     0,   738,   739,     0,     0,   724,     0,     0,     0,
       0,   725,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1085,  1086,  1104,   722,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   726,
       0,     0,     0,  1192,   740,     0,     0,     0,   741,   846,
     847,   848,     0,     0,     0,     0,   742,     0,     0,     0,
       0,     0,   849,     0,     0,     0,     0,   743,     0,     0,
       0,     0,     0,   744,   727,  1087,  1088,  1089,  1090,  1091,
    1092,     0,     0,     0,     0,     0,   728,     0,     0,     0,
       0,  1093,  1094,  1095,  1105,     0,     0,     0,   745,     0,
       0,     0,     0,     0,   729,     0,     0,     0,     0,   730,
       0,     0,   731,     0,     0,     0,     0,     0,     0,     0,
       0,   723,     0,   732,     0,     0,     0,     0,     0,   733,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   734,
       0,     0,   746,     0,   735,     0,     0,   736,     0,   747,
     737,   748,     0,     0,     0,     0,     0,     0,     0,   738,
     739,   749,   750,   751,     0,     0,   850,     0,     0,     0,
     752,     0,     0,    82,     0,     0,     0,     0,     0,     0,
       0,   272,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   715,   716,     0,     0,
       0,   740,   269,   717,   718,   741,     0,     0,     0,     0,
       0,     0,     0,   742,     0,     0,     0,   719,   724,     0,
       0,     0,   720,   725,   743,     0,     0,     0,   721,     0,
     744,     0,  1096,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   726,     0,     0,     0,   745,   722,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   727,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   728,   746,
       0,     0,     0,     0,     0,     0,   747,     0,   748,     0,
       0,     0,     0,     0,     0,     0,   729,     0,   749,   750,
     751,   730,     0,     0,   731,     0,     0,   752,     0,     0,
      82,     0,     0,     0,     0,   732,     0,     0,   272,     0,
       0,   733,     0,     0,     0,     0,     0,     0,     0,   723,
       0,   734,     0,     0,  1098,     0,   735,     0,     0,   736,
       0,     0,   737,     0,     0,     0,     0,     0,     0,  1099,
       0,   738,   739,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   715,   716,
       0,     0,     0,     0,   269,   717,   718,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   719,
       0,  1101,  1192,   740,   720,     0,     0,   741,     0,  1086,
     721,     0,     0,     0,     0,   742,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   385,   743,     0,     0,  1102,
       0,     0,   744,     0,     0,     0,   724,     0,   722,     0,
       0,   725,     0,     0,     0,   715,   716,     0,  1103,     0,
       0,   269,   717,   718,     0,     0,     0,   745,  1087,  1088,
    1089,  1090,  1091,  1092,     0,     0,   719,     0,     0,   726,
       0,   720,     0,     0,  1093,  1094,  1095,   721,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   746,     0,     0,   727,   722,     0,     0,   747,     0,
     748,     0,     0,     0,     0,     0,   728,     0,     0,     0,
     749,   750,   751,     0,     0,     0,     0,     0,     0,   752,
    1104,   723,    82,     0,   729,     0,     0,     0,     0,   730,
     272,     0,   731,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   732,     0,  1868,  1869,     0,  1870,   733,
       0,   269,  1871,  1872,     0,     0,     0,     0,     0,   734,
       0,     0,     0,     0,   735,     0,     0,   736,     0,     0,
     737,  1873,     0,     0,     0,     0,     0,     0,     0,   738,
     739,     0,     0,     0,     0,     0,     0,  1105,   723,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1096,     0,     0,  1097,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   724,     0,
       0,   740,     0,   725,     0,   741,     0,     0,     0,     0,
       0,     0,     0,   742,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   743,     0,  2132,     0,   158,     0,
     744,   726,   715,   716,     0,     0,     0,     0,   269,   717,
     718,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   719,     0,   745,     0,     0,   720,     0,
       0,     0,     0,     0,   721,   724,   727,   159,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,   728,     0,
       0,     0,     0,     0,     0,     0,   160,     0,     0,     0,
       0,     0,   722,     0,     0,     0,   729,     0,   726,   746,
    -857,   730,     0,     0,   731,     0,   747,  1098,   748,     0,
       0,     0,     0,     0,     0,   732,     0,     0,   749,   750,
     751,   733,  1099,     0,     0,   161,  1100,   752,     0,     0,
      82,   734,     0,   727,     0,     0,   735,   162,   272,   736,
       0,     0,   737,     0,     0,   728,     0,   163,     0,     0,
       0,   738,   739,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   729,  1101,   164,     0,     0,   730,     0,
       0,   731,     0,     0,     0,   165,     0,     0,     0,     0,
       0,     0,   732,     0,     0,   723,     0,     0,   733,     0,
       0,   166,  1102,   740,     0,     0,     0,   741,   734,   203,
       0,     0,     0,   735,     0,   742,   736,     0,     0,   737,
       0,  1103,     0,     0,     0,     0,   743,     0,   738,   739,
       0,     0,   744,  1928,     0,     0,   204,   205,     0,     0,
       0,   167,     0,     0,     0,   206,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   745,     0,     0,
       0,     0,     0,     0,     0,   168,     0,     0,     0,  2521,
     740,     0,     0,     0,   741,     0,     0,     0,     0,     0,
     169,     0,   742,     0,     0,     0,     0,   170,     0,     0,
     171,  1874,   724,   743,     0,     0,     0,   725,     0,   744,
       0,   746,     0,  1104,     0,   158,  1875,     0,   747,     0,
     748,   172,     0,     0,   173,     0,   174,     0,     0,     0,
     749,   750,   751,  1876,   745,   726,  1877,     0,     0,   752,
       0,     0,    82,     0,     0,   175,     0,     0,  2955,  1878,
     272,     0,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,     0,     0,     0,
     727,     0,     0,   160,     0,     0,     0,     0,   746,     0,
    1105,     0,   728,     0,     0,   747,     0,   748,     0,     0,
    1880,     0,     0,     0,     0,     0,     0,   749,   750,   751,
     729,     0,  1881,     0,  2956,   730,   752,     0,   731,    82,
       0,     0,   161,     0,     0,     0,     0,   272,     0,   732,
       0,     0,     0,     0,   162,   733,   207,     0,     0,  2957,
       0,     0,     0,     0,   163,   734,     0,     0,  2958,     0,
     735,     0,     0,   736,  1882,     0,   737,     0,     0,     0,
       0,     0,   164,     0,     0,   738,   739,     0,     0,     0,
       0,     0,   165,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,  2959,     0,     0,  1929,   166,     0,
       0,     0,  2960,  1883,   209,     0,     0,     0,     0,     0,
    1930,     0,     0,     0,     0,  1884,     0,   740,     0,     0,
     210,   741,     0,     0,     0,     0,     0,  1885,  1886,   742,
       0,     0,     0,     0,     0,     0,  1887,     0,   167,   690,
     743,     0,     0,   211,     0,     0,   744,   272,     0,     0,
       0,     0,     0,     0,     0,   212,     0,     0,     0,     0,
       0,     0,   168,     0,     0,   213,     0,     0,     0,     0,
       0,   745,     0,     0,  1931,     0,     0,   169,     0,     0,
       0,  1932,     0,   214,   170,     0,     0,   171,     0,     0,
       0,     0,     0,   215,     0,     0,  2961,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   216,
       0,   173,     0,   174,     0,   746,     0,     0,     0,     0,
    1933,     0,   747,     0,   748,     0,     0,     0,     0,     0,
       0,     0,   175,     0,   749,   750,   751,     0,     0,     0,
       0,     0,     0,   752,     0,  1934,    82,     0,     0,   217,
     176,     0,     0,     0,   272,  1935,  1936,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1937,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,  1938,     0,   220,  1939,  1940,   221,     0,
       0,     0,  1941,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   222,
       0,     0,   223,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1942,
       0,   226,     0,     0,     0,     0,     0,     0,     0,  2962,
       0,  1943,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   227
};

static const short yycheck[] =
{
       2,   193,   187,   709,   328,     0,    64,  1256,   857,   521,
      12,    13,   839,   497,   979,   824,   445,   212,  1489,   422,
     986,   828,   705,   993,   835,   836,  1550,   838,    23,   840,
     841,   684,  1401,   153,    29,    82,   920,  1690,  1739,  1686,
     363,    43,    44,  1735,  1011,    60,  1857,  1367,   507,  1370,
     934,  1267,  1268,  2069,   513,  1798,   865,   175,   517,   117,
     515,  1356,   731,   479,  1609,  1299,    20,  2159,     5,    64,
     504,     5,   388,     5,    76,    25,    24,    79,     5,   264,
      95,    24,     5,  1681,  1682,     5,    24,  1685,   543,    91,
     418,   546,    17,    18,    25,    24,    98,   780,    23,    24,
      25,   504,   104,   105,    23,    24,    25,   225,   110,   111,
     539,    44,    65,    66,     5,    24,  1927,   237,   238,    46,
      24,    48,   117,    50,   452,    26,   141,   455,    25,     5,
     145,    23,    24,    25,    54,     5,  1023,   465,    24,     5,
      60,   469,    24,    24,   951,   473,   953,   149,   340,    23,
     152,    25,   480,    24,    23,   157,    25,   485,   127,   487,
      24,  1056,    26,     5,    18,   493,    24,    18,   496,    23,
      24,    25,    29,    32,    25,   503,    24,   508,    26,    23,
     508,    25,    39,    23,    24,    25,    79,    24,   516,  1787,
      17,    18,     5,     5,   196,    23,    41,    25,    25,   527,
       9,   226,     5,   531,   112,    24,    24,   535,    26,     5,
      24,   127,   227,   541,     5,     5,   544,  1621,   924,     6,
      41,  1874,    17,    18,     5,    78,    83,    84,    23,    24,
      25,    32,   234,    69,    91,   213,  2584,     5,   240,     5,
       5,    20,   252,   100,   101,    24,   103,   104,     6,   251,
       5,   108,     9,   690,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     6,   280,  1915,   282,   125,   126,
     362,     9,   287,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,  1960,  2422,   226,   143,   144,  2252,    26,
    2204,  2205,  2206,  2207,   367,    24,  2782,    17,    18,    19,
      20,    21,   322,     5,   369,  2894,   364,   365,   167,   168,
     309,    22,     5,    70,    71,    72,    73,    74,    75,   252,
    1967,   336,    35,    36,   273,   525,   408,   216,   352,  1800,
     317,  2895,    70,    71,    72,    73,    74,    75,   353,     5,
     140,     5,    17,    18,    19,    20,    21,   337,    24,    62,
      63,    64,  2163,   435,   356,  1204,  1660,   359,     5,  1663,
     140,   252,    17,   113,   114,   367,  1964,   168,     5,   364,
     365,   153,   846,   847,    24,   408,   252,   889,  2842,   408,
     487,   383,  2029,   385,   273,   369,  2524,     5,   598,   322,
     311,   555,     5,  1991,   517,   605,   458,   597,     5,  2988,
    1370,     5,   185,   517,   517,    17,    18,   436,     5,   471,
     412,    23,    24,    25,   449,   417,     5,   419,   227,   403,
     422,   423,   457,   425,     5,     0,   428,  2025,     5,    84,
      30,     5,   596,     5,   367,     5,   325,   439,     5,     5,
     329,     5,   363,   566,   446,   317,    28,     5,   373,  2028,
       5,  2030,   566,   566,   118,   597,   458,  1163,   407,   604,
      23,   362,    25,   388,   454,     5,   468,   249,     5,   471,
     362,     5,     5,   230,     5,     5,     5,     5,     5,   481,
      27,   626,   627,     5,    43,     5,  2950,     5,   345,  2581,
       5,     5,   230,   492,     5,   497,   498,     5,  3062,   591,
     828,   212,   504,   568,   503,   483,   449,     5,   449,    26,
     512,  2997,   514,   515,   371,   128,   540,     5,   407,     5,
     522,   523,   322,   525,   526,     5,   528,     5,   530,   479,
     532,   128,  2181,   605,   536,   504,   538,   547,   540,   646,
     542,   543,   322,   545,   546,  1029,   548,   568,  1032,  1033,
    1034,   874,  2900,   876,   574,   364,  1451,   366,  1962,  1454,
      17,    18,    19,    20,    21,   638,   591,  1051,   261,  1006,
     557,   408,   605,   465,   564,  1009,  2253,  2254,   373,   369,
    1035,   408,   369,   533,   492,   442,   367,  1803,   504,   146,
     327,   404,   404,   388,   377,   261,   351,   418,   518,  2123,
     532,   404,   525,  2201,   369,  2569,  1009,   493,   404,  1292,
    1293,   369,   369,   404,   547,  1502,   564,   555,  1301,  1131,
     596,   952,   646,   951,   952,   953,  2642,   369,  2644,   408,
    2646,  1143,   282,    20,  2650,   528,   404,    24,   288,   289,
     290,   591,  2166,   591,   373,   331,   970,   649,   591,   406,
    2174,  2175,   605,   591,   449,   971,   547,   672,   308,   529,
     591,  1344,   591,   597,   414,  1149,  2264,   369,   406,   535,
     597,   547,   591,   532,   599,   677,   521,   679,   605,   536,
     599,  1565,   591,   525,   404,   557,   606,   591,   690,  1144,
     591,  2783,   646,  1127,   591,   628,   629,   630,  2002,   591,
     521,   843,  2247,   705,   641,  2516,   639,   599,   850,   591,
     591,   529,  1196,   715,   716,  1189,  1132,   568,   220,   432,
     591,   574,   369,   523,  1127,   599,   535,   591,   730,   404,
     599,   532,   369,   591,   736,   737,  2479,  1221,  2876,   741,
    2483,  1975,  1226,   591,    59,   599,    20,  1416,  2449,   751,
    1717,   369,  2072,  2074,  2049,   599,   556,   436,  1728,   599,
     617,   373,   369,   529,   591,   369,   416,  1222,   625,   419,
     599,   599,   591,   591,  2688,    22,   388,   591,   780,     5,
     369,  1240,   618,   619,   620,   621,   622,  1216,   369,   344,
     331,   135,   369,   443,  2932,   369,   591,   369,   436,   369,
    2764,  2765,   369,   369,   599,   369,   365,   520,  1778,  1264,
    1265,   369,    22,   463,   223,  2413,  1008,  2415,   133,   134,
     260,  2776,   824,   825,   581,     5,  2405,   236,  2407,   369,
    1637,   390,   369,   273,   436,   369,   369,   604,   369,   369,
     369,   369,   369,   581,  2982,   602,  2984,   369,   498,   369,
     563,   369,   599,  2425,   369,   369,  2428,   859,   369,   416,
     627,   369,   982,   865,   602,   985,   416,  1379,   518,   519,
     427,   369,   187,  2565,  2527,   877,   431,   427,   193,   529,
     882,   369,  2251,   369,   534,   887,    19,    20,    21,   369,
     436,   369,   449,   448,   359,   317,    27,    28,    24,   456,
      26,   302,   367,   905,   135,   302,  2833,  2923,  2835,   141,
    2926,    13,   369,   145,   500,   474,   338,   416,   920,  2874,
     599,  2015,     0,   573,   416,   337,  2142,  2021,   427,    23,
     274,    25,   934,  2888,  1393,   427,   491,    70,    71,    72,
      73,    74,    75,    90,  1627,    23,   408,   412,  2759,   264,
     449,   266,   514,    86,    87,    88,   606,   456,   604,   408,
     260,   599,  1147,   248,    18,   212,   251,   407,   253,    23,
      24,    25,  2570,   273,   100,   101,   531,   103,   104,   591,
     626,   627,   108,  2507,    23,   987,    25,   599,   273,   991,
     992,   993,  1451,   408,  2592,  1454,  1823,   333,   283,   125,
     126,  1128,   212,  1130,  1006,   560,   350,  1009,   567,  1011,
    1012,   141,   436,  1015,   569,   145,   248,   143,   144,   251,
     579,   580,   568,   619,   620,   340,   408,  1029,  1030,   588,
    1032,  1033,  1034,  1035,  2989,  1037,  1548,   408,  1040,   169,
     325,   273,   454,   274,   329,   454,  1501,    18,   403,  1051,
    2742,  1053,    23,   599,    25,  1057,  1905,    25,   459,   408,
    2026,   470,   459,  1065,   408,  1067,  1068,   408,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,   436,   223,   408,   214,  3016,
    2743,   408,  2745,   340,   227,  1097,  1098,   230,   455,   236,
    1102,  1613,  1104,   408,  2074,  2071,   527,   407,  1592,  1593,
     531,    25,   469,   273,   535,   430,   473,  1119,   248,   350,
     408,   251,   407,   196,   408,  1127,   470,   200,   485,   605,
     340,  1133,  1134,  1135,   605,   557,    25,   100,   101,   459,
     103,   104,  1144,   273,  1146,   108,  1148,  1149,    25,   464,
      25,  1153,   564,  1608,    25,   470,  2525,   472,   408,  1966,
      25,   476,   125,   126,   479,   325,  1494,   482,   599,   329,
    2869,  2870,  1290,  2771,   459,   407,   512,   492,  1296,   223,
     143,   144,   436,  1990,    25,   435,   436,   216,  1190,    25,
     526,    25,   236,    25,  1196,  2063,   511,  2065,  2066,  2891,
     599,  2085,    25,   604,   519,   520,   521,   604,  1720,    25,
     525,    37,  1332,  1215,  1537,   551,   349,  1219,   533,  1221,
    1222,  1341,   623,   624,  1226,   408,   623,   624,  1230,  1231,
    1232,   364,   344,   369,   549,   368,   408,   141,   339,   470,
    1242,   145,   643,   599,   273,  2843,   643,   407,    25,   499,
     408,   214,   435,   436,  1256,    76,  2903,    82,    86,    87,
      88,  1263,  1264,  1265,   600,   169,  1949,  1779,   408,  1781,
    1729,   408,   404,   406,  2973,   313,  2975,   407,  1790,   542,
     435,   436,   545,     5,   604,   548,   324,  1289,  1616,   415,
    1292,  1293,   369,  2940,    25,  1297,   325,  1299,   599,  1301,
     329,   434,   236,   623,   624,   404,   487,   132,   618,  1637,
    1993,   621,   622,    24,    25,   496,   499,   454,   369,   431,
     453,   369,  1337,   643,   339,  1978,   248,  1374,    20,   251,
      25,   253,   248,   470,    25,   251,   448,   253,   376,   435,
     436,    25,  1344,    25,   248,   170,    25,   251,   265,   266,
      20,   273,   408,   391,  1356,   369,    96,   273,   643,   344,
     541,   283,    25,   544,   408,  1367,    25,   283,  1370,   273,
      25,   444,   445,     5,    40,   621,   622,   599,   407,   491,
     302,    24,    25,  2192,   628,   629,   302,  1389,  1390,  1391,
     628,   629,  2863,  2642,   709,  2644,   369,  2246,   591,  2768,
     844,   845,   535,   325,   848,   849,   437,   329,  1867,   325,
     454,   646,   369,   329,    17,    18,    19,    20,    21,   531,
     280,   369,  3020,  1425,  1426,  1427,   470,  1429,   319,   369,
     369,   369,    17,    18,   603,    20,     5,   328,    23,    24,
      25,   369,   267,   481,   369,   111,   431,   280,   560,   369,
    2974,   603,   415,  1455,   369,   599,  1458,   569,    43,   199,
     369,   352,   777,   448,   355,   591,   539,   207,  2434,   602,
    1472,  2441,    24,   213,   436,   215,   549,   592,   593,   594,
     595,  2952,   373,   596,     8,   407,   226,    24,  1490,   310,
     599,   407,   404,   457,  1496,  1898,  1498,  1499,  1500,  1501,
    2971,   408,   323,   407,   504,   820,   491,   408,   408,   408,
     335,   177,   408,   179,   254,   408,   408,   244,   343,   834,
     835,   836,   347,   838,   344,   840,   841,   408,   194,  1531,
     270,   846,   847,   597,  1536,   275,   202,   459,   408,   408,
     206,   408,   408,   459,  1546,   408,   531,   287,  1550,   408,
    1745,   408,   408,   408,   294,  1557,   408,   408,  3029,   384,
     408,   408,   137,  1565,   408,   231,   387,  2079,   408,   408,
    1572,   398,  1574,   394,   889,   560,   437,   344,     5,   154,
     155,   597,   574,   398,   569,   900,   638,   162,   479,   408,
    1592,  1593,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   638,   304,     8,  1608,   437,   575,   924,
     925,   431,   433,     5,  2126,     5,   361,   408,   933,   408,
     408,   196,   408,    24,   408,  1627,   322,   452,   448,     8,
     205,   568,  1960,  1635,   949,   950,   709,   458,  1966,   111,
    2605,    13,   533,     5,  1646,   638,   557,   468,   469,   540,
    2499,    70,    71,    72,    73,    74,    75,  1659,  1660,   234,
     554,  1663,  1990,   484,   431,     5,   491,    86,    87,    88,
    2497,   491,   638,   398,  2923,   408,   408,  1679,    25,  1681,
    1682,   448,   755,  1685,  1686,   506,    25,    44,   509,   510,
       7,   516,    69,  1008,   515,   436,   408,   436,    25,   408,
      17,    18,    19,    20,   279,   177,     5,   179,    20,   449,
    1712,   531,   574,   599,   408,  1717,   456,   605,   568,  1721,
     408,   643,   194,   344,   491,   408,  1728,   643,   449,    20,
     202,   408,    20,  1735,   206,   560,   408,   408,   478,   408,
     560,   605,   328,   483,   569,   217,   321,   408,  2232,   569,
    2234,   572,   605,    70,    71,    72,    73,    74,    75,   231,
     535,   641,  2445,   584,   531,  1767,   591,   604,  1770,    17,
       5,    29,    18,    25,    25,   130,  1778,    24,   196,   557,
    1782,  1783,  1784,  1785,   602,  1787,   568,   460,   373,   111,
       5,  1793,  1794,   560,   128,  1797,  1798,  2503,   460,   525,
       5,   525,   569,   388,  1806,  1120,    25,   377,   227,   299,
     431,   230,   525,  1128,  1816,  1130,  1131,  1132,    25,   408,
     405,   408,   446,   408,  1139,  1140,   408,   448,  1143,   408,
     408,   643,  1147,    24,   599,  1150,   421,    17,    18,    19,
      20,   555,   100,   101,   468,   103,   104,   525,  1163,   344,
     108,   924,   369,   369,   369,   177,   369,   179,  2707,   369,
     369,  1863,   369,  1865,   449,    25,  2715,   125,   126,   369,
     491,   369,   194,   369,  1189,  1877,   461,   462,   369,   408,
     202,   596,   605,     5,   206,   143,   144,     5,   512,   474,
      70,    71,    72,    73,    74,    75,  1898,     5,   522,   523,
     558,   599,   526,     5,  1906,   461,   530,   369,   532,   231,
     531,   408,   536,  1228,   538,  2344,  2345,  2346,   605,  2348,
    2349,  2350,  2351,  2352,  2353,  2253,  2254,  2439,  2357,   604,
     349,   516,   408,     5,   532,    25,   431,  1252,    25,   560,
     408,   514,  1257,    44,   303,   364,   369,  1949,   569,   368,
       5,   408,   369,   448,  2466,  1270,  1271,  2015,   369,   408,
     338,   575,  1964,  2021,   605,  1967,   599,    13,   398,   398,
     555,   344,  1974,  1975,     5,   639,   529,   525,     5,  1981,
      25,  1983,   567,   449,    78,   605,   408,   406,    29,  1991,
     599,  1993,   408,   604,   579,   580,   491,  2680,     5,    24,
    2002,   618,   404,   588,   404,   438,   591,   438,   369,   408,
    1325,   408,  2861,   408,   599,   434,     8,   408,     5,   408,
    2015,   408,   408,  2025,    25,    25,  2021,  2029,   568,  2031,
      24,   369,  2487,   369,   453,    24,   531,   369,    24,  2494,
      24,   369,     5,    17,    18,    19,    20,  2049,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   431,   100,
     101,   599,   103,   104,  1379,   560,     5,   108,   599,   599,
    2072,     8,  2074,   303,   569,   448,   334,   322,   322,   599,
    2082,   322,   436,  2085,   125,   126,    20,   408,   338,   403,
    1163,     5,   408,   408,   630,  2902,    70,    71,    72,    73,
      74,    75,   143,   144,   408,   408,    70,    71,    72,    73,
      74,    75,   408,   408,   421,   408,   535,    25,   491,     5,
    2122,  2123,    86,    87,    88,   383,     5,   434,     5,     5,
    2132,    25,   574,  2135,   574,   596,   408,  2986,  2140,     5,
     599,   562,     5,  1216,  2955,  2956,  2957,  2958,  2959,  2960,
    2833,  2153,  2835,  2155,   461,  2157,   599,     5,   531,   408,
       5,  2867,  2164,     7,  2166,    19,    20,   369,  2170,     5,
     477,   478,  2174,  2175,    20,    25,   483,   605,    25,   486,
       8,   369,    25,   602,   599,   605,   369,   560,    25,   369,
    2192,    17,    18,    19,    20,   605,   569,  2709,  1271,  2201,
     824,  2203,   568,   369,   369,   369,  2208,  2209,  2210,  2211,
    2212,  2213,   369,   369,  1529,    20,    70,    71,    72,    73,
      74,    75,  2706,  1538,    70,    71,    72,    73,    74,    75,
    2232,     5,  2234,  1548,   545,   859,   252,    17,    18,    19,
      20,   865,    20,   369,    70,    71,    72,    73,    74,    75,
       5,     5,   525,   877,  1569,    20,     5,   218,   882,   369,
     550,   436,  2264,   227,   605,   418,   230,  2269,   599,   369,
     408,    70,    71,    72,    73,    74,    75,   449,     6,   605,
    2604,    70,    71,    72,    73,    74,    75,    86,    87,    88,
      70,    71,    72,    73,    74,    75,  2481,   605,  1613,  1614,
    1615,   532,   603,   532,  1619,     4,     5,     6,     7,     8,
       9,   603,    11,   188,  2316,    15,    16,    17,    18,    19,
      20,    21,    24,  2325,  2326,  2327,  1746,    24,  2520,    24,
    1750,  2333,   598,  3016,    24,  1755,  1651,    24,   424,  1759,
    2852,  1761,  1762,  1763,    25,    25,    25,    25,    25,   408,
     449,   408,    25,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      70,    71,    72,    73,    74,    75,   274,   599,    25,     5,
     504,   369,   246,  3089,   369,   349,    86,    87,    88,   568,
     446,     5,  2394,   408,  2396,   369,    17,    18,    19,    20,
     364,   369,   529,    20,   368,  1720,   218,  2409,   404,   369,
       5,  2413,   369,  2415,   418,   322,    20,    13,    70,    71,
      72,    73,    74,    75,    29,   117,     5,    13,   227,   440,
     599,   230,   188,     5,    86,    87,    88,    20,   369,  2441,
      25,   369,   406,  2445,   369,    25,   369,     5,    53,    70,
      71,    72,    73,    74,    75,  2457,    26,   346,   598,   408,
     309,   351,   547,   369,  1779,    25,  1781,   369,   369,   322,
     434,   219,   408,   369,   605,  1790,   554,  2479,   408,   217,
    2482,  2483,   525,   217,   419,  2487,    25,   369,  2490,   453,
     436,   605,  2494,   425,    25,   100,   101,   370,   103,   104,
     369,  1574,   599,   108,   408,  2507,     5,   605,    13,  1133,
    1134,  1135,   605,  1828,     5,     5,  2518,   404,   369,    20,
     125,   126,    24,   219,   408,     5,  2169,   227,   369,  1153,
     230,  2533,  3039,  2082,  2536,  2537,  2538,  2539,   143,   144,
     369,  1853,  1857,   369,  2546,    17,    18,    19,    20,   369,
     349,  2122,  1233,  1558,    36,    38,   364,  1794,  2153,  1800,
     287,  2563,  1635,  2565,   141,   364,  1190,   145,  2570,   368,
     209,   535,   281,   396,  2902,   227,  1336,  2579,   230,  1337,
     288,   353,  2584,   211,  1899,  1900,  1753,   371,   383,   369,
    2592,  1215,  2594,   316,   315,   385,  2452,  3029,    70,    71,
      72,    73,    74,    75,  1531,  1770,  1679,   406,  1232,   214,
     525,  1406,   958,  1686,  1657,  1664,  1784,  1500,  1242,  1004,
    1266,  1263,  2227,  2549,  1902,  1788,  3054,  1588,  1603,  2243,
    2241,  1149,  2723,    23,    92,   434,   117,    29,   602,   651,
    2642,  2626,  2644,    29,  1563,  1569,  1243,  2649,   482,   349,
     266,   679,  1271,  2655,   453,  1900,   925,  2623,  2797,  1572,
    1140,  1187,  1735,  1619,   364,  2971,  2209,  1130,   368,  2384,
    2807,   877,  1215,   131,  2382,  2366,  2024,  1061,  2680,  2781,
    1015,  1778,  2684,  1373,  2686,  1350,  2001,  1960,  3058,  2908,
    3020,  1994,  2025,  2412,  1685,  2446,  2394,   349,  2680,  2396,
    2031,  2923,  2821,  2650,  2706,  2644,   406,  2327,  1289,  2711,
    2825,   954,   364,  2844,  2763,  2845,   368,  2265,  2269,  3018,
    2926,  2208,  1285,  2886,    17,    18,  1258,    20,  1717,   334,
      23,    24,    25,   950,   434,   362,   535,   961,  2579,  1145,
    2742,    -1,    -1,    -1,    -1,    -1,  2748,    -1,   369,    -1,
      43,    -1,    -1,   453,   406,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2079,    -1,    -1,  1574,    -1,  2771,
      -1,    -1,    -1,    -1,    -1,  2777,    -1,    -1,   383,  2781,
    2782,    -1,   434,    -1,    -1,    -1,    -1,  2789,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1868,  1869,    -1,    -1,    -1,
      -1,   453,    -1,   602,  1877,    -1,    17,    18,    -1,    20,
     415,  2126,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,  1635,    -1,
      -1,  2833,    43,  2835,    -1,   535,  2838,    -1,    -1,    -1,
      -1,  2843,    -1,  2845,  2159,    -1,    -1,    -1,  1472,    -1,
      -1,    -1,  2167,    -1,  2169,    -1,  2171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2184,
      -1,    -1,  1496,    -1,    -1,    -1,  1500,    70,    71,    72,
      73,    74,    75,   535,  2886,    -1,    -1,    -1,    -1,  2891,
      -1,  2893,    -1,  2895,  1967,    -1,    -1,   369,  2900,    -1,
      -1,  2903,   602,    -1,    -1,    -1,  2908,  1531,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2923,    -1,    -1,    -1,    -1,  2928,    -1,  1735,    -1,
      -1,    -1,    -1,  1557,    -1,    -1,    -1,    -1,  2940,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     602,    -1,    -1,    -1,    -1,    -1,  2029,    -1,  2031,    -1,
     418,    -1,   420,   421,  2966,  2967,    -1,    -1,    -1,    -1,
      -1,    -1,  2974,    -1,    -1,    -1,   434,    -1,    -1,   272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   452,  2997,  2069,   455,    -1,    -1,
      -1,    -1,    -1,   461,    -1,    -1,    -1,   465,    -1,    -1,
      -1,   469,    -1,  2328,  3016,   473,  3018,    -1,  3020,   477,
     478,    -1,   480,    -1,    -1,   483,    -1,   485,   486,   487,
      -1,    -1,    -1,    -1,    -1,   493,    -1,    -1,   496,    -1,
      -1,    -1,    -1,    -1,    -1,   503,    -1,    -1,    -1,    -1,
     508,    -1,    -1,  2368,    -1,    -1,  3058,    -1,   516,    -1,
    3062,   272,    -1,    -1,    -1,    -1,  2381,    -1,    -1,   527,
    1877,    -1,  3074,   531,    -1,    -1,    -1,   535,    -1,    -1,
     373,    -1,    -1,   541,    -1,    -1,   544,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   388,    -1,  1721,    -1,  1323,
    1324,    -1,    -1,    -1,    -1,    -1,  1330,    -1,    -1,    -1,
      -1,    -1,   405,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2439,    -1,    -1,   420,   421,    -1,
    2203,    -1,    -1,    -1,    -1,  2208,  2209,  2210,  2211,  2212,
    2213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2466,    -1,    -1,    -1,    -1,   449,    -1,  1782,  1783,
    1784,  1785,   373,    -1,    -1,    -1,  2481,    -1,    -1,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,    51,
      52,   474,  1806,    55,    56,    57,    -1,    -1,  2503,    -1,
      -1,    -1,    -1,    -1,   405,    -1,  2269,   408,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2520,    -1,    -1,    -1,   420,
     421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2029,   516,    -1,    -1,    -1,    -1,   715,   716,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1863,
      -1,    -1,    -1,   730,    -1,    -1,    -1,    -1,    -1,   736,
     737,   462,    -1,    -1,   741,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,   474,   751,    -1,  2581,    -1,    -1,    -1,
      -1,  2344,  2345,  2346,   567,  2348,  2349,  2350,  2351,  2352,
    2353,    -1,    -1,   155,  2357,    -1,   579,   580,   581,    -1,
     162,    -1,    -1,    -1,    -1,   588,    -1,    -1,   591,    -1,
      -1,    -1,    -1,    -1,    -1,   516,   599,    -1,  2623,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1541,    -1,    -1,
      -1,  2394,    -1,  2396,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,    -1,    -1,  2409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   567,  1981,    -1,  1983,
    1584,    -1,   234,   235,    -1,    -1,    -1,    -1,   579,   580,
     828,    -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,    -1,
     591,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   599,    -1,
      -1,    -1,    -1,    -1,  2709,    -1,  2203,    -1,    -1,    -1,
      -1,  2208,  2209,  2210,  2211,  2212,  2213,   279,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2503,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   321,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2533,    -1,  2269,  2536,  2537,  2538,  2539,    -1,  2783,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2797,    -1,    -1,    -1,    -1,  2802,    -1,  2804,
      -1,    -1,  2565,   951,   952,   953,    -1,    70,    71,    72,
      73,    74,    75,    -1,    -1,   377,    -1,    -1,  2132,    -1,
      -1,  2135,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2844,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2852,    -1,    -1,
      -1,    -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,
    1037,    -1,  2867,  1040,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1053,    -1,  2192,  2642,
    1057,  2644,    -1,  2646,    -1,    -1,  2649,  2650,  1065,    -1,
    1067,  1068,    -1,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
      -1,    -1,  2409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1097,  1098,    -1,    -1,    -1,  1102,    -1,  1104,    -1,    -1,
      -1,    -1,    -1,  1847,  1848,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1858,    -1,    -1,    -1,    -1,    -1,
    2955,  2956,  2957,  2958,  2959,  2960,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2742,
      -1,    -1,    -1,    -1,    -1,  2748,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1911,  1912,  1913,
    1914,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      -1,    -1,  1926,    -1,  2777,    -1,    -1,    -1,    -1,  2782,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2533,    -1,    -1,  2536,
    2537,  2538,  2539,    -1,    -1,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2565,    -1,
      -1,    -1,    -1,    -1,    -1,  2838,    70,    71,    72,    73,
      74,    75,    -1,    -1,  3089,    -1,   349,    -1,    -1,  2003,
    2004,    -1,    86,    87,    88,    -1,  2010,  2011,  1246,    -1,
      -1,   364,    -1,    -1,  2867,   368,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2891,    -1,
    2893,    -1,  2895,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2903,    -1,    -1,   406,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2649,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2923,    -1,    -1,  2926,    -1,  2928,    -1,    -1,    -1,    -1,
      -1,   434,    -1,    -1,    -1,    -1,  2490,  2940,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2518,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,  2143,
    2144,    -1,  2546,   227,  2997,    -1,   230,    -1,  2152,    -1,
     277,    -1,    -1,    -1,    43,  2742,  2160,    -1,  1425,  1426,
    1427,  2748,  1429,    -1,    -1,  3018,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2178,  2179,    70,    71,    72,    73,
      74,    75,   535,    -1,    -1,    -1,    -1,    -1,  1455,    -1,
    2777,    -1,    86,    87,    88,  2782,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3058,    -1,    -1,   335,  3062,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,  2233,
     357,  2235,    -1,    -1,    -1,    -1,  3089,    -1,  2242,    -1,
    2244,    -1,    -1,    -1,    -1,    -1,    -1,    41,   375,   602,
      -1,  2838,    -1,    -1,    -1,    -1,  1494,    -1,   385,    -1,
      -1,   388,    -1,    -1,    -1,   349,    -1,    -1,    -1,  1536,
      -1,    -1,    -1,    -1,   401,    69,    -1,    -1,    -1,    -1,
     364,    -1,    -1,  1550,   368,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2891,    -1,  2893,  2711,  2895,    -1,
      -1,    -1,    -1,    17,    18,    -1,    20,   111,    -1,    23,
      24,    25,   406,   450,    -1,    -1,    -1,    -1,    -1,    -1,
    2334,  2335,    -1,   227,  2338,  2339,   230,    -1,    -1,    43,
      -1,  2928,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
     434,   145,    -1,   480,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   490,    -1,    -1,    -1,    -1,  2372,   453,
      -1,    -1,    -1,    -1,    -1,   169,    -1,    -1,  1616,    -1,
      -1,    -1,    -1,   177,   511,   179,    -1,   514,    -1,   516,
      -1,    -1,    -1,    -1,   188,    -1,    -1,    -1,    -1,  1637,
     194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,
    2997,    -1,   206,    -1,    -1,    -1,    -1,   544,   212,    -1,
      -1,    -1,   216,   217,   218,   219,   553,    -1,    -1,    -1,
      -1,  3018,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   535,    -1,    -1,   248,   349,    -1,   251,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,   260,    -1,    -1,    -1,
     364,  3058,    -1,    -1,   368,  3062,  2480,    -1,  1716,   273,
    2484,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,   283,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   388,
    1767,    -1,    -1,  1770,    -1,    -1,    -1,    -1,   302,   303,
    2514,    -1,   406,    -1,    -1,    -1,   405,    -1,   602,   408,
      -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   325,   421,    -1,    -1,   329,    -1,    -1,    -1,    -1,
     434,    -1,    -1,  2547,   338,   339,   340,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,
      -1,    -1,  2966,    -1,    -1,    -1,    -1,    -1,   272,    -1,
      -1,    -1,   461,   462,    -1,    -1,    -1,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,   474,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,   407,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   418,    -1,    -1,   516,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,   459,   555,    -1,    -1,   373,
    3074,    -1,    -1,    -1,    -1,    86,    87,    88,   567,    -1,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,
     579,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   588,
      -1,   405,   591,    -1,   408,    -1,    -1,    -1,   602,    -1,
     599,    -1,    -1,  1951,    -1,    -1,   420,   421,    -1,    -1,
      -1,    -1,  1960,    -1,    -1,    -1,    -1,   521,  1966,    -1,
      -1,    -1,    -1,    -1,    -1,  2739,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1990,    -1,    -1,    -1,    -1,    -1,   462,    -1,
      -1,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,    -1,
     474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2045,    -1,    -1,
     604,    -1,   516,    -1,    -1,    -1,   227,    -1,   258,   230,
      -1,    -1,    -1,    -1,   618,   619,   620,   621,   622,   623,
     624,    -1,   626,   627,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   643,
      -1,   555,    -1,    -1,    -1,  2122,  2123,    -1,   298,   299,
     300,    -1,    -1,   567,    -1,    -1,    -1,  2871,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   580,   581,    -1,    -1,
      -1,    -1,    -1,   323,   588,    -1,    -1,   591,    -1,    -1,
      -1,   331,    -1,    -1,    -1,   599,   336,  2164,    -1,  2166,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2174,  2175,  2913,
    2914,   351,  2916,    -1,  2918,  2919,   356,    -1,   358,    -1,
      -1,    -1,    -1,    -1,    -1,   365,    -1,    -1,   368,    -1,
      -1,   371,    -1,    -1,   374,    -1,    -1,   377,   349,    -1,
      -1,    -1,   382,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   364,    -1,    -1,    -1,   368,   369,    -1,
     400,  2199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,    -1,   419,
     420,  2985,    -1,    -1,    -1,    -1,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,    -1,   437,    -1,    -1,
      -1,  3005,    -1,  3007,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   453,    -1,  2253,  2254,    -1,    -1,    -1,
     460,    -1,    -1,   434,    -1,    -1,    -1,   467,    -1,    -1,
     470,   471,   472,    -1,   474,   475,    -1,    -1,    -1,    -1,
    3044,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   491,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,  3068,  3069,    -1,    -1,  3072,    -1,
      -1,    -1,    -1,    -1,    -1,   515,   516,   517,   518,    -1,
     520,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,   538,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
     560,    -1,    -1,    -1,   535,    86,    87,    88,    -1,   569,
     570,    -1,   572,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    80,    81,
    2457,   602,    -1,    -1,   634,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    -1,   107,   108,   109,   110,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,   119,    -1,   121,
     122,   123,    -1,   125,   126,    -1,    -1,    -1,    -1,   131,
    2507,   133,   134,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,   143,   144,    -1,    -1,   147,   148,   149,    -1,   151,
     152,    -1,    -1,    -1,   156,   157,   227,   159,    -1,   230,
      -1,   163,    -1,   165,   166,    -1,    -1,    -1,    -1,   171,
      -1,    -1,    -1,   175,    -1,    -1,   178,    -1,   180,    -1,
     182,    -1,   184,    -1,   186,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,   195,    -1,   197,   198,    -1,   200,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,
      -1,    -1,   224,   225,  2572,    -1,   228,   229,    -1,    -1,
     232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,
     242,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   255,   256,   257,    -1,   259,    -1,    -1,
      -1,   263,   264,    -1,    -1,    -1,   268,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   276,    -1,    -1,    -1,   349,    -1,
      -1,    -1,   284,   285,   286,    -1,    -1,    -1,    -1,    -1,
     292,   293,    -1,   364,    -1,    -1,   298,   368,    -1,   301,
      -1,    -1,    -1,   305,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   316,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   334,    -1,    -1,   406,    -1,    -1,    -1,    -1,
     342,    -1,    -1,    -1,    -1,    -1,   348,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   434,    -1,    -1,    -1,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,    -1,   378,    -1,   380,   381,
      -1,    -1,   453,    -1,    -1,    -1,    -1,   389,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   428,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,    -1,
      -1,   443,    -1,    -1,    -1,   447,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,   471,
     472,    86,    87,    88,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   488,    -1,    -1,    -1,
      -1,    -1,   494,   495,   496,   497,    -1,    -1,    -1,   501,
      -1,    -1,    -1,   505,    -1,    -1,    -1,    -1,    -1,    -1,
     512,   513,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   524,    -1,   526,    -1,    -1,    -1,    -1,    -1,
      -1,   602,    -1,    -1,    -1,   537,    -1,   539,    -1,    -1,
     542,    -1,    -1,    -1,    -1,    -1,   548,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2902,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   230,   574,    -1,    -1,   577,    -1,    -1,    -1,    -1,
      -1,   583,    -1,    -1,   586,   587,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2974,    -1,   601,
      -1,    -1,    -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    25,   631,
     632,   633,   634,   635,   636,   637,    -1,    -1,   640,    -1,
     642,    -1,   644,    -1,    -1,    -1,    43,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,   364,    23,    24,    25,   368,
     369,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    86,    87,    88,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,   364,
      -1,    -1,    -1,   368,   369,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   434,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,   453,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,   434,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,    86,
      87,    88,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,   227,    -1,
      -1,   230,    -1,    -1,    -1,    -1,   535,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     535,    -1,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   602,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,
     227,    -1,    -1,   230,    -1,    -1,    -1,   602,    -1,    -1,
     349,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   364,    -1,    -1,   405,   368,
     369,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,   230,    -1,   421,    -1,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   406,    -1,    -1,
      -1,    -1,   449,    -1,    -1,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,   227,    -1,   462,   230,    -1,    -1,    -1,
      -1,   388,    -1,    -1,    -1,   434,    -1,   474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   405,    -1,
      -1,   408,    -1,    -1,   453,    70,    71,    72,    73,    74,
      75,    -1,   349,    -1,   421,    -1,    -1,   227,    -1,    -1,
     230,    86,    87,    88,    -1,    -1,    -1,   364,    -1,   516,
      -1,   368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   349,    -1,    -1,   461,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   364,   474,   555,   406,
     368,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     567,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    -1,
      -1,    -1,   579,   580,    -1,   349,    -1,   434,    -1,    -1,
      -1,   588,    -1,    -1,   591,    -1,    -1,    -1,   406,   516,
     364,    -1,   599,    -1,   368,   369,   453,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,   349,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   555,    -1,
      -1,    -1,   406,   602,   364,   453,    -1,    -1,   368,   369,
     567,    -1,   227,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   580,    -1,    -1,    -1,    -1,    -1,    -1,
     434,   588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   599,    -1,    -1,    -1,   406,    -1,   535,   453,
      -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,   434,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,   602,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,   535,    -1,    -1,   349,    86,    87,    88,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,   364,
      -1,    -1,    -1,   368,   602,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   535,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    70,    71,    72,    73,    74,    75,   602,    -1,
      -1,    -1,    -1,    -1,   419,    -1,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   434,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,   453,    -1,
      -1,    -1,   602,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    17,    18,    -1,    20,    -1,    -1,    23,    24,    25,
      -1,    86,    87,    88,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    -1,    43,    -1,   227,
     535,    -1,   230,    86,    87,    88,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,
      -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,   602,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    -1,   349,    -1,
      -1,    43,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,    -1,    -1,   364,    -1,    -1,    -1,   368,    -1,    -1,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,
      -1,   349,   227,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   406,   364,    -1,    -1,    -1,
     368,    -1,    -1,    -1,   227,    -1,    -1,   230,   419,    -1,
      -1,   349,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   434,    -1,    -1,   364,    -1,    -1,    -1,
     368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   406,    -1,
      -1,    -1,   453,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   434,    -1,   406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    20,    21,    -1,   453,    -1,   227,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,   434,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   453,    -1,   227,    -1,   364,
     230,    -1,    -1,   368,   535,    -1,   349,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,   364,    -1,    -1,    -1,   368,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   406,    -1,    -1,    -1,    -1,    -1,   535,    -1,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,   406,    -1,    -1,    -1,   373,    -1,   434,
      38,   602,    -1,    -1,    -1,    43,    -1,   535,   106,    -1,
      -1,    49,   388,    -1,    -1,    -1,    -1,   115,   453,   349,
      -1,   434,    -1,    -1,    -1,    -1,   124,    -1,    -1,   405,
      -1,   129,   408,    -1,   364,    -1,    -1,    -1,   368,    77,
     453,    -1,    -1,    -1,   602,   421,    -1,    -1,    -1,   349,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   364,    -1,    -1,    -1,   368,    -1,
      -1,    -1,    -1,    -1,   602,   173,   406,    -1,    -1,    -1,
      -1,   373,    -1,   181,    -1,   461,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,   474,   227,
     535,    -1,   230,    -1,   434,    -1,   406,    -1,    -1,    -1,
      -1,    -1,    -1,   405,    -1,    -1,   408,    -1,    -1,   419,
      -1,    -1,   535,   453,    -1,    -1,    -1,    -1,    -1,   421,
      -1,    -1,   170,    -1,   434,    -1,    17,    18,    -1,   237,
     516,    -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   453,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    43,    -1,   262,    -1,    -1,   602,    49,   461,
     462,   269,    -1,   271,    -1,    -1,    -1,    -1,    -1,   555,
      -1,    -1,   474,   281,    -1,    -1,    -1,    -1,    -1,   602,
      -1,   567,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   579,   580,   535,    -1,    -1,    -1,   307,
      -1,    -1,   588,    -1,    -1,   591,    -1,   315,    -1,    -1,
      -1,   349,    -1,   599,   516,    -1,    -1,    -1,    -1,   267,
      -1,    -1,    -1,    -1,   272,   535,   364,    -1,    -1,    -1,
     368,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   352,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   300,   555,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   602,    -1,    -1,   567,    -1,    -1,   406,    -1,
     378,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   588,   335,    -1,   591,
      -1,    -1,   602,    -1,    -1,    -1,   434,   599,    -1,   347,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   416,    -1,
      -1,    -1,    -1,    -1,    -1,   453,    -1,   365,    -1,   427,
      -1,    -1,   370,    -1,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   384,    -1,    17,    18,
      -1,    -1,   390,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,   400,    -1,    -1,    -1,    -1,   405,    -1,    38,
     408,    -1,    -1,   411,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,   420,   421,    -1,    -1,   267,    -1,    -1,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,   535,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   300,
      -1,    -1,    -1,   461,   462,    -1,    -1,    -1,   466,   527,
     528,   529,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,
      -1,    -1,   540,    -1,    -1,    -1,    -1,   485,    -1,    -1,
      -1,    -1,    -1,   491,   335,    70,    71,    72,    73,    74,
      75,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,
      -1,    86,    87,    88,   602,    -1,    -1,    -1,   516,    -1,
      -1,    -1,    -1,    -1,   365,    -1,    -1,    -1,    -1,   370,
      -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   170,    -1,   384,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,   560,    -1,   405,    -1,    -1,   408,    -1,   567,
     411,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
     421,   579,   580,   581,    -1,    -1,   644,    -1,    -1,    -1,
     588,    -1,    -1,   591,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,   462,    23,    24,    25,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    38,   267,    -1,
      -1,    -1,    43,   272,   485,    -1,    -1,    -1,    49,    -1,
     491,    -1,   227,    -1,    -1,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   300,    -1,    -1,    -1,   516,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,   560,
      -1,    -1,    -1,    -1,    -1,    -1,   567,    -1,   569,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   365,    -1,   579,   580,
     581,   370,    -1,    -1,   373,    -1,    -1,   588,    -1,    -1,
     591,    -1,    -1,    -1,    -1,   384,    -1,    -1,   599,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,
      -1,   400,    -1,    -1,   349,    -1,   405,    -1,    -1,   408,
      -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,    -1,   364,
      -1,   420,   421,   368,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,   406,   461,   462,    43,    -1,    -1,   466,    -1,    21,
      49,    -1,    -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,   485,    -1,    -1,   434,
      -1,    -1,   491,    -1,    -1,    -1,   267,    -1,    77,    -1,
      -1,   272,    -1,    -1,    -1,    17,    18,    -1,   453,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,   516,    70,    71,
      72,    73,    74,    75,    -1,    -1,    38,    -1,    -1,   300,
      -1,    43,    -1,    -1,    86,    87,    88,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   560,    -1,    -1,   335,    77,    -1,    -1,   567,    -1,
     569,    -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,
     579,   580,   581,    -1,    -1,    -1,    -1,    -1,    -1,   588,
     535,   170,   591,    -1,   365,    -1,    -1,    -1,    -1,   370,
     599,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   384,    -1,    17,    18,    -1,    20,   390,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,   400,
      -1,    -1,    -1,    -1,   405,    -1,    -1,   408,    -1,    -1,
     411,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   420,
     421,    -1,    -1,    -1,    -1,    -1,    -1,   602,   170,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,    -1,
      -1,   462,    -1,   272,    -1,   466,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   474,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   485,    -1,   487,    -1,   238,    -1,
     491,   300,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,   516,    -1,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,   267,   335,   277,    -1,    -1,
     272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   296,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    -1,    -1,   365,    -1,   300,   560,
     369,   370,    -1,    -1,   373,    -1,   567,   349,   569,    -1,
      -1,    -1,    -1,    -1,    -1,   384,    -1,    -1,   579,   580,
     581,   390,   364,    -1,    -1,   335,   368,   588,    -1,    -1,
     591,   400,    -1,   335,    -1,    -1,   405,   347,   599,   408,
      -1,    -1,   411,    -1,    -1,   347,    -1,   357,    -1,    -1,
      -1,   420,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   365,   406,   375,    -1,    -1,   370,    -1,
      -1,   373,    -1,    -1,    -1,   385,    -1,    -1,    -1,    -1,
      -1,    -1,   384,    -1,    -1,   170,    -1,    -1,   390,    -1,
      -1,   401,   434,   462,    -1,    -1,    -1,   466,   400,    31,
      -1,    -1,    -1,   405,    -1,   474,   408,    -1,    -1,   411,
      -1,   453,    -1,    -1,    -1,    -1,   485,    -1,   420,   421,
      -1,    -1,   491,    76,    -1,    -1,    58,    59,    -1,    -1,
      -1,   441,    -1,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   516,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   465,    -1,    -1,    -1,   461,
     462,    -1,    -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,
     480,    -1,   474,    -1,    -1,    -1,    -1,   487,    -1,    -1,
     490,   373,   267,   485,    -1,    -1,    -1,   272,    -1,   491,
      -1,   560,    -1,   535,    -1,   238,   388,    -1,   567,    -1,
     569,   511,    -1,    -1,   514,    -1,   516,    -1,    -1,    -1,
     579,   580,   581,   405,   516,   300,   408,    -1,    -1,   588,
      -1,    -1,   591,    -1,    -1,   535,    -1,    -1,   181,   421,
     599,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   553,    -1,    -1,    -1,    -1,    -1,    -1,
     335,    -1,    -1,   296,    -1,    -1,    -1,    -1,   560,    -1,
     602,    -1,   347,    -1,    -1,   567,    -1,   569,    -1,    -1,
     462,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,   581,
     365,    -1,   474,    -1,   237,   370,   588,    -1,   373,   591,
      -1,    -1,   335,    -1,    -1,    -1,    -1,   599,    -1,   384,
      -1,    -1,    -1,    -1,   347,   390,   238,    -1,    -1,   262,
      -1,    -1,    -1,    -1,   357,   400,    -1,    -1,   271,    -1,
     405,    -1,    -1,   408,   516,    -1,   411,    -1,    -1,    -1,
      -1,    -1,   375,    -1,    -1,   420,   421,    -1,    -1,    -1,
      -1,    -1,   385,    -1,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   307,    -1,    -1,   310,   401,    -1,
      -1,    -1,   315,   555,   296,    -1,    -1,    -1,    -1,    -1,
     323,    -1,    -1,    -1,    -1,   567,    -1,   462,    -1,    -1,
     312,   466,    -1,    -1,    -1,    -1,    -1,   579,   580,   474,
      -1,    -1,    -1,    -1,    -1,    -1,   588,    -1,   441,   591,
     485,    -1,    -1,   335,    -1,    -1,   491,   599,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   347,    -1,    -1,    -1,    -1,
      -1,    -1,   465,    -1,    -1,   357,    -1,    -1,    -1,    -1,
      -1,   516,    -1,    -1,   387,    -1,    -1,   480,    -1,    -1,
      -1,   394,    -1,   375,   487,    -1,    -1,   490,    -1,    -1,
      -1,    -1,    -1,   385,    -1,    -1,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,   401,
      -1,   514,    -1,   516,    -1,   560,    -1,    -1,    -1,    -1,
     433,    -1,   567,    -1,   569,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   535,    -1,   579,   580,   581,    -1,    -1,    -1,
      -1,    -1,    -1,   588,    -1,   458,   591,    -1,    -1,   441,
     553,    -1,    -1,    -1,   599,   468,   469,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   484,    -1,   465,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   480,    -1,
      -1,    -1,    -1,   506,    -1,   487,   509,   510,   490,    -1,
      -1,    -1,   515,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   511,
      -1,    -1,   514,    -1,   516,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   535,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,
      -1,   553,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   596
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    53,   100,   101,   103,   104,   108,   125,   126,
     143,   144,   214,   334,   383,   415,   705,   733,   734,   784,
     952,  1007,  1009,  1010,  1011,  1016,  1018,  1031,  1032,  1033,
    1034,  1035,  1440,    27,    28,   706,   707,   708,   709,   710,
     915,   919,   333,   512,   526,   551,   600,  1441,  1441,  1441,
    1441,  1441,  1441,  1441,  1441,   915,    24,   915,  1378,  1036,
     735,   734,  1440,     0,  1008,  1011,  1016,  1034,  1440,    30,
     708,   710,    26,  1459,   915,  1443,   568,   915,  1442,   605,
     785,    24,   591,   732,   733,   903,   915,   922,  1037,  1073,
    1074,  1075,  1076,  1077,  1081,   331,   737,   738,   739,   740,
     743,   744,    39,    83,    84,    91,   345,   371,   442,   536,
     617,   625,   705,   711,   871,   951,  1012,  1013,  1015,  1019,
    1020,  1026,  1038,  1042,  1190,  1200,  1440,   920,   915,  1442,
     596,  1076,   220,   435,   436,  1082,    20,   915,  1080,   919,
     738,     5,   736,   331,   915,     5,   760,   762,   763,  1201,
     915,   915,  1191,  1027,   915,   915,  1015,  1021,   238,   277,
     296,   335,   347,   357,   375,   385,   401,   441,   465,   480,
     487,   490,   511,   514,   516,   535,   553,   786,   787,   788,
     791,    24,  1073,  1079,    17,    18,    25,   408,   655,   657,
    1073,  1083,  1084,   436,   599,    13,   783,   740,   500,  1177,
     741,   738,   743,    31,    58,    59,    67,   238,   277,   296,
     312,   335,   347,   357,   375,   385,   401,   441,   465,   480,
     487,   490,   511,   514,   516,   535,   553,   596,   746,   754,
     765,   766,   915,   408,    90,   915,   732,   872,  1043,   915,
     793,   514,   745,   769,   771,   772,   770,   779,   780,   408,
     408,   792,   436,   408,   408,   738,   767,   403,   655,    17,
      18,    19,    20,    21,   656,    25,     5,   404,  1083,    23,
      24,    25,   599,   915,   923,    18,    24,    25,   742,   923,
     756,   745,   757,   769,   770,   408,   408,   755,   436,   408,
     408,   767,   738,   764,   408,    25,   915,   408,  1028,   732,
     732,   408,   915,   408,   435,   749,   605,   344,   431,   448,
     491,   531,   560,   569,   773,   605,   344,   431,   448,   491,
     531,   560,   569,   781,    25,    25,   794,   795,   796,   797,
     915,    25,   752,   753,    25,    25,   599,   369,   655,  1084,
     436,   404,    25,    25,   738,   749,   738,    25,    25,   737,
     752,    25,    25,   599,    37,   761,  1202,   369,   408,  1192,
    1460,  1461,  1462,  1463,  1464,   873,  1044,  1022,   599,    25,
     774,   775,   408,   776,   781,   782,   776,   408,   777,     5,
     369,     5,   369,     5,   261,     5,   786,   404,     5,     5,
     369,   369,   738,   768,  1083,   599,    25,   236,     5,   369,
       5,   369,   261,   404,     5,   369,   369,   768,   915,  1089,
    1090,  1092,  1039,  1089,   339,  1461,  1177,    33,    34,    45,
      47,    61,    68,    79,    80,    81,    95,    97,    98,    99,
     102,   105,   107,   109,   110,   116,   119,   121,   122,   123,
     131,   133,   134,   136,   138,   139,   142,   147,   148,   149,
     151,   152,   156,   157,   159,   163,   165,   166,   171,   175,
     178,   180,   182,   184,   186,   187,   189,   190,   191,   195,
     197,   198,   200,   208,   209,   221,   224,   225,   228,   229,
     232,   233,   241,   242,   243,   245,   255,   256,   257,   259,
     263,   264,   268,   276,   284,   285,   286,   292,   293,   298,
     301,   305,   306,   316,   334,   342,   348,   378,   380,   381,
     389,   428,   439,   443,   447,   471,   472,   476,   488,   494,
     495,   496,   497,   501,   505,   512,   513,   524,   526,   537,
     539,   542,   548,   574,   577,   583,   586,   587,   601,   608,
     631,   632,   633,   634,   635,   636,   637,   640,   642,   644,
     648,   649,   650,   651,   668,   690,   704,   705,   711,   712,
     731,   799,   800,   801,   802,   813,   814,   815,   816,   867,
     897,   901,   925,   926,   929,   930,   931,   932,   945,   953,
     976,   977,   979,   983,   998,   999,  1003,  1004,  1005,  1006,
    1014,  1029,  1049,  1060,  1061,  1062,  1066,  1069,  1105,  1108,
    1110,  1116,  1117,  1120,  1123,  1126,  1128,  1130,  1132,  1139,
    1144,  1148,  1149,  1161,  1162,  1165,  1171,  1172,  1173,  1198,
    1213,  1214,  1215,  1216,  1217,  1222,  1228,  1229,  1247,  1250,
    1290,  1291,  1379,  1380,  1410,  1411,  1418,  1429,  1440,  1444,
    1449,  1451,  1453,  1457,  1458,  1465,   705,  1017,  1440,   604,
     627,  1045,  1046,  1089,    20,   369,   403,   750,   773,    25,
     778,    25,    25,    25,   795,   797,   789,   753,    25,   404,
      20,   750,   408,    25,    25,   747,    25,   599,   369,     5,
    1089,   369,   915,   916,   919,   915,   910,   916,   910,    24,
     591,   915,  1102,  1435,  1436,  1437,   915,  1455,   915,  1224,
    1225,   915,    25,   652,  1073,  1220,   910,   915,  1146,   842,
      25,   923,  1185,  1186,  1185,    17,    18,    24,    25,    38,
      43,    49,    77,   170,   267,   272,   300,   335,   347,   365,
     370,   373,   384,   390,   400,   405,   408,   411,   420,   421,
     462,   466,   474,   485,   491,   516,   560,   567,   569,   579,
     580,   581,   588,   817,   824,   825,   826,   827,   828,   829,
     830,   831,   843,   848,   859,   860,   861,   862,   915,   923,
    1073,  1180,  1249,  1370,   916,  1419,  1419,   803,  1146,   910,
    1218,  1073,   912,   916,   824,  1419,  1073,  1146,  1073,  1248,
    1419,    24,   564,  1063,  1064,  1073,   910,   910,  1063,   911,
     916,   915,  1064,   910,  1419,   910,   912,  1073,  1103,  1104,
     908,   916,   912,   352,   540,   646,   907,   915,   978,   915,
     713,   913,   916,  1435,  1070,   842,   916,  1129,   868,   106,
     115,   124,   129,   173,   181,   237,   262,   269,   271,   281,
     307,   315,   352,   378,   416,   427,   527,   528,   529,   540,
     644,   990,  1124,  1125,  1073,   823,   824,  1138,   819,   842,
     907,  1450,  1450,   909,   916,   842,    24,  1073,  1127,  1199,
    1073,  1176,    24,  1073,  1413,   824,  1167,  1168,  1169,  1178,
    1179,   824,  1445,    82,   132,   170,   267,   343,   384,   452,
     516,   669,   848,   915,  1073,  1208,   692,   824,   908,  1442,
    1050,   824,   908,   824,  1073,  1000,   908,   824,  1430,   824,
    1185,   915,   927,   928,   912,   927,  1450,   912,   927,  1450,
     933,   927,    24,    25,   362,   465,   923,   981,  1073,  1091,
    1093,    44,   252,   322,   367,   547,   628,   629,   630,   639,
     659,   935,   937,   939,   941,   943,  1067,  1068,  1072,   313,
     324,   376,   391,   481,  1292,   619,   620,   875,   876,   877,
     915,  1047,   626,  1046,   369,   280,   369,   369,   369,   369,
     603,     5,   369,   280,   738,   758,   759,   369,   369,   603,
     369,   915,  1203,  1092,   369,  1193,    35,    36,    62,    63,
      64,   432,   520,   563,  1230,  1231,  1232,  1235,  1238,  1241,
    1242,  1243,  1244,   327,   917,  1459,   599,  1437,   436,   596,
    1121,   599,     8,   517,   566,     5,   369,   404,    24,   915,
    1364,   457,  1147,  1091,    86,    87,    88,   817,   817,   408,
     504,  1197,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   817,   344,   431,   448,   491,   531,   560,   569,  1373,
    1374,   408,   408,   408,   817,   817,   408,   408,   729,   817,
     408,   832,   408,   408,   408,   408,   408,   408,   408,   817,
     408,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    70,    71,    72,
      73,    74,    75,    86,    87,    88,   227,   230,   349,   364,
     368,   406,   434,   453,   535,   602,   728,   818,   833,   835,
     836,   837,   838,   839,   840,   841,    25,   923,   408,   499,
     398,  1073,  1098,  1364,   658,   659,   806,   244,    65,    66,
     605,   437,     5,   598,   605,   597,   597,  1106,   574,   398,
       5,   535,   954,   437,   638,  1447,   408,   436,   599,   638,
     362,   715,  1073,   525,   597,  1111,  1112,  1113,   304,  1289,
     823,   822,   824,     8,   909,    25,   479,   533,   902,  1073,
     902,   902,   902,   995,   996,   902,   902,   575,   991,   659,
     991,   991,   903,   903,   991,   991,   659,     5,   311,   363,
       5,   658,   461,   820,   821,   824,     5,    54,    60,   518,
     606,   984,   641,  1448,   823,   592,   593,   594,   595,  1175,
    1177,   361,  1212,  1177,  1169,     5,   597,  1170,   824,   408,
     408,   408,   408,    24,   688,   915,   408,  1413,   322,   408,
     499,   568,   557,   693,   700,   691,    24,  1065,  1073,  1163,
       8,  1166,    13,   915,  1078,  1085,  1086,  1088,  1096,  1097,
    1140,   140,   322,   523,   556,    32,   168,   532,  1431,  1432,
    1433,  1434,   554,     5,   638,   638,   822,  1091,  1098,   980,
     398,     5,   128,   958,   408,  1073,   822,   408,    25,    25,
      44,  1071,    24,  1073,  1417,  1417,   909,  1129,   909,    96,
     199,   207,   213,   215,   226,   254,   270,   275,   287,   294,
     449,   456,   478,   483,  1251,  1262,  1263,  1271,  1280,  1281,
    1287,  1288,  1293,  1294,  1303,  1322,  1326,  1390,  1391,  1420,
    1421,  1424,  1425,   878,   879,    69,   874,   885,   886,   877,
    1048,  1460,  1023,   436,   786,   753,   436,     5,   369,   760,
     732,  1040,   732,   135,   274,   350,   408,   470,  1309,  1321,
     408,   915,  1246,    25,   223,   236,   408,   454,   470,   915,
    1227,  1240,  1307,  1308,  1313,  1315,  1317,   408,   915,  1237,
     408,  1227,  1233,     5,   408,   920,  1437,  1083,  1435,   555,
     596,  1122,    20,   915,  1102,  1438,   915,  1456,  1225,   574,
     599,   568,   408,   408,   806,   907,   817,   907,   907,   907,
    1450,   449,  1394,   817,    24,    25,    18,    23,    24,    25,
     863,   864,   865,   866,   817,   408,   605,   907,    20,   817,
     369,  1394,   817,    20,  1180,   851,   849,   855,   817,   853,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   817,   817,   817,   817,   817,   817,   817,   817,   817,
     817,   408,   817,   817,   408,   844,   915,  1073,   605,   408,
    1435,    24,   922,  1145,  1145,  1413,  1063,   824,   824,   824,
     904,   905,   408,  1073,  1104,   767,   955,   956,   605,  1413,
    1450,  1448,   915,   655,    20,   646,   915,   978,  1073,   714,
     604,   824,   328,  1115,   535,  1114,     5,    46,    48,    50,
     597,   605,   798,  1091,   869,    17,    18,    24,   282,   288,
     289,   290,   308,   416,   419,   443,   463,   498,   518,   519,
     529,   534,   573,   606,   997,   992,  1125,   903,   824,   322,
     574,     5,   907,    25,    25,   658,   130,  1174,   196,  1179,
    1185,  1446,   915,    24,   907,  1450,   568,   907,   602,  1073,
     673,   915,   915,   824,   317,   696,   700,   557,   694,   702,
      22,   212,  1052,  1056,   460,   842,   460,  1164,   824,   435,
    1082,   919,     5,  1001,   525,  1141,  1073,  1436,  1439,  1073,
    1094,  1095,   167,  1432,   946,   928,  1450,  1450,   938,   939,
     958,   958,   248,   251,   253,   273,   283,   325,   329,   407,
     459,   643,   957,   959,   960,   986,  1073,  1093,   525,   660,
      25,   377,   944,   299,  1412,  1412,   113,   114,   414,   525,
     915,  1323,  1324,  1365,   767,  1364,  1364,  1264,   767,   915,
    1422,  1422,   337,   454,   564,  1402,  1364,  1272,   146,   416,
     427,   449,   456,  1296,  1297,  1298,   265,   266,  1385,  1460,
    1460,   362,   887,  1073,   621,   622,   880,   881,   882,   459,
     604,   623,   624,   643,   890,   891,  1460,   732,    25,   751,
     751,   759,  1204,   732,  1194,  1311,  1364,  1245,  1321,   408,
    1245,   408,   408,  1239,  1240,   408,   408,    42,   277,   335,
     347,   357,   375,   385,   388,   401,   450,   480,   490,   511,
     514,   516,   544,   553,  1356,  1357,  1358,  1360,  1236,  1237,
    1233,  1234,   643,  1231,    24,   918,  1076,   599,   404,  1413,
     555,   525,  1454,   653,   654,   915,   915,   915,  1221,   842,
     369,   369,   369,   369,   369,  1402,   369,   369,   369,   369,
     568,   864,    18,    25,   568,   369,   369,    25,  1374,   369,
     369,   369,   369,     5,   730,   369,   817,   817,   817,   369,
     817,   369,   369,   369,   419,   419,   419,   842,  1394,   419,
     842,  1394,   685,   686,   687,   817,   408,   915,  1219,   596,
    1118,   605,     5,     5,     5,   558,   824,   599,     5,   461,
     605,   369,   404,   408,   604,   141,   145,   248,   251,   716,
     719,   720,   986,   717,   718,   915,   408,   916,   628,   629,
    1119,   824,   915,   915,   905,   906,   487,  1450,   806,   532,
    1277,    25,    25,   408,   993,   995,  1073,   514,  1133,   820,
      44,   817,  1177,    25,  1073,  1460,   369,     5,   369,   369,
     689,   915,   369,  1413,   685,   408,   408,   701,   697,   338,
     695,   824,   317,   698,   702,   575,   988,  1057,  1053,   340,
    1051,  1052,   822,   605,  1079,   599,  1097,    13,    17,    18,
      20,    24,    25,    43,   373,   388,   405,   408,   421,   461,
     462,   474,   516,   555,   567,   579,   580,   588,   915,   923,
    1142,  1143,  1369,  1371,  1401,  1406,  1407,  1439,   398,   398,
       5,  1460,   940,   941,   529,   914,   525,   907,   974,   907,
     975,   967,   966,   964,   963,   987,   416,   427,   970,   971,
     416,   427,   972,   973,   302,   960,   965,  1450,    76,   310,
     323,   387,   394,   433,   458,   468,   469,   484,   506,   509,
     510,   515,   572,   584,   661,   662,     5,    25,  1413,   226,
    1073,   449,  1395,  1396,  1413,  1129,  1389,  1391,    78,    78,
     574,  1127,  1325,  1326,   408,  1304,   127,   504,  1330,  1337,
    1364,   153,   249,  1426,   599,   605,  1403,  1404,  1406,  1252,
     319,   328,   352,   355,   373,   479,   533,   540,   909,  1274,
    1279,   408,  1299,   604,     5,    24,   915,  1386,  1387,   889,
    1073,     5,   525,   883,   884,   618,   882,   888,   915,   888,
     892,   893,   888,   302,   891,  1024,   404,   404,   438,  1187,
    1207,  1041,   438,  1150,  1181,   408,     5,   369,   272,   408,
     420,   581,  1340,  1341,  1342,  1343,  1344,  1348,  1352,  1354,
    1406,   369,   915,  1310,  1312,  1364,  1367,  1314,  1367,     5,
     369,  1314,  1340,   344,   431,   448,   491,   531,   560,   569,
    1376,  1376,   408,   408,   408,   408,   408,   408,   185,   377,
    1316,  1318,     5,   369,     5,   369,   915,   369,  1438,     8,
    1413,   824,     5,  1226,  1227,   842,  1030,  1403,   857,  1374,
     857,    25,    25,   568,    23,    25,   770,   858,  1197,   369,
    1197,   771,   369,  1197,   852,   850,   856,  1197,   854,  1197,
    1197,  1197,    24,    24,    24,   817,   834,   369,    24,   834,
     369,   845,     5,   846,   599,  1226,   555,  1413,  1413,   824,
     824,   904,   487,   824,  1452,     5,    20,  1367,   956,  1413,
     599,   915,   717,   725,   724,   726,   915,   921,   727,   921,
     169,   720,   723,     5,   958,   599,   824,     8,   915,  1278,
     870,   994,   995,  1073,     5,   303,  1209,   322,   322,   436,
     599,   322,   408,   674,   678,   671,  1460,  1460,   703,   699,
     695,   989,    24,   914,  1058,  1073,  1460,   824,   403,    20,
     915,  1087,   842,    25,   923,    25,   923,  1372,  1376,   449,
    1406,   408,   408,   408,   408,   408,   408,   408,   408,     5,
      17,    18,    19,    20,    70,    71,    72,    73,    74,    75,
    1427,  1436,  1073,  1095,    41,   521,   947,   942,   943,    25,
     658,   915,     5,   961,     5,   962,  1460,  1460,  1460,  1460,
     993,     5,   969,     5,   968,  1460,   914,     5,   369,    25,
    1364,   919,  1383,   574,   574,  1263,  1388,  1389,  1326,  1305,
    1367,   596,   909,  1340,   408,  1267,   915,  1423,  1422,     5,
    1392,   258,   298,   299,   300,   323,   331,   336,   351,   356,
     358,   365,   368,   371,   374,   377,   382,   400,   416,   419,
     420,   426,   437,   453,   460,   467,   470,   471,   472,   474,
     475,   491,   515,   516,   517,   518,   520,   537,   538,   560,
     569,   570,   572,   634,   924,  1459,   562,   824,   824,  1273,
     909,  1300,  1367,  1364,  1298,   599,   599,     5,     5,  1073,
     888,  1460,  1460,     5,   895,   896,  1460,  1460,   894,  1017,
     790,   748,    51,    52,    55,    56,    57,   155,   162,   196,
     205,   234,   235,   279,   321,   377,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,  1184,  1188,   112,   492,
    1189,  1205,  1017,   137,   154,   155,   162,   196,   205,   234,
     279,   321,  1182,  1183,  1195,  1189,  1312,  1321,   408,  1401,
    1340,  1406,  1401,  1343,     6,   369,     7,     9,    11,    12,
      13,    14,    15,    16,   230,   406,   581,   602,  1351,  1353,
     436,  1366,   369,     5,   919,     5,   369,  1240,   369,   369,
     605,   408,   605,    25,  1362,  1362,    25,  1362,  1362,    25,
    1361,    24,  1369,  1319,  1320,  1321,  1237,  1233,  1413,     8,
     654,     5,   369,   822,   369,   525,  1331,  1336,   605,   369,
      25,   568,   605,   369,   369,   369,   369,     5,   369,   369,
     369,   687,   685,    20,   369,  1413,     5,   824,   545,   252,
     663,   664,   824,    20,   915,   369,   958,  1460,  1460,     5,
     721,   436,   599,     5,   722,  1460,   718,   525,    20,   915,
       5,   915,  1109,   367,   638,  1094,  1460,     5,   369,   914,
     817,   685,  1073,   670,   652,   915,  1073,   676,   369,   685,
     685,  1460,  1460,   993,  1055,    24,  1059,  1073,   550,   900,
     436,   461,   823,  1002,   605,   919,   369,   373,  1367,  1428,
     337,   454,   564,  1355,  1406,  1408,  1355,  1355,  1355,  1355,
    1408,  1143,  1406,  1406,  1406,  1406,   949,   948,   418,   934,
     935,   599,   907,  1460,   907,  1460,   971,  1460,   973,  1460,
     658,   662,   369,   408,  1414,  1402,  1385,  1389,  1389,  1381,
       5,   369,   449,  1400,  1268,  1367,   457,  1265,  1400,   605,
    1404,   532,  1399,    20,   408,  1255,  1256,  1257,  1258,  1367,
     532,  1275,     5,   369,   605,   915,   915,  1387,  1073,   915,
    1460,  1460,  1460,  1460,   603,   603,  1185,  1185,  1185,    24,
    1185,  1185,  1185,  1185,  1185,  1185,    24,    24,  1185,  1188,
    1073,  1099,  1100,   598,   424,  1151,  1460,    24,    24,    25,
      25,    25,    25,    25,    24,  1073,  1183,  1151,   369,   369,
    1341,  1342,   408,  1401,   408,  1401,     9,   227,   364,   366,
     535,  1406,    25,  1309,  1367,   599,  1367,   344,   431,   448,
     491,   531,   560,   569,  1377,    25,  1377,     5,  1359,  1359,
       5,   369,   369,  1359,   369,  1321,  1413,  1227,   246,  1223,
     493,  1332,  1333,  1334,  1364,  1337,   309,   492,   503,  1282,
    1397,   344,   431,   448,   491,   531,   560,   569,  1375,   857,
     568,    23,    25,   774,   817,   847,   446,   805,     5,   351,
    1413,     5,   408,   369,   529,   985,   921,  1460,   655,    20,
     915,   921,  1460,  1450,   824,  1450,   218,   995,   658,  1210,
    1091,   404,   685,   675,   679,   369,  1460,   914,   824,   898,
    1083,  1377,  1402,     5,  1376,     5,   369,  1406,     5,   369,
    1406,  1406,  1406,  1406,   369,   824,  1460,   936,   937,    20,
     915,  1415,  1416,  1403,  1384,  1382,  1385,  1367,   919,   117,
    1306,     5,   369,  1266,  1423,  1094,  1393,    13,  1257,  1259,
    1253,     5,    13,  1276,  1367,   440,  1301,  1302,  1365,   599,
     188,  1025,   786,   760,   517,   566,  1101,     5,  1099,    40,
     111,   177,   179,   194,   202,   206,   231,  1152,  1153,  1206,
    1025,  1196,  1349,  1350,  1369,  1439,  1349,  1346,  1369,  1409,
    1406,  1346,     5,   404,    20,   915,   369,    25,  1363,   369,
     369,    25,   369,   408,  1334,     5,   915,  1368,   346,  1328,
    1338,   915,  1398,   598,  1355,   309,   408,    23,    25,   369,
     907,   658,   351,  1413,   824,   665,   547,  1107,    25,   658,
     404,   985,   369,  1131,   369,   408,   677,   322,   683,   369,
     672,  1054,  1460,   404,  1403,  1376,   605,  1376,   369,  1406,
     369,   369,   369,   369,   554,   914,     5,   369,  1399,  1385,
    1385,  1402,  1367,   408,  1336,   408,   461,  1260,  1261,  1406,
       5,   369,   127,   504,  1254,  1258,  1261,  1094,     5,   118,
    1295,   915,  1100,  1154,  1155,  1073,  1157,  1073,  1156,  1158,
    1153,   217,   217,     5,   369,   369,   419,  1345,     7,  1345,
      25,  1366,   605,   369,  1333,  1335,  1333,  1329,  1405,  1406,
     425,  1327,  1339,  1223,    25,  1283,  1284,  1285,  1367,  1395,
    1398,    25,   804,  1413,   370,   181,   237,   262,   271,   307,
     315,   409,   582,   662,   666,   667,   408,   599,   658,   986,
    1134,  1135,  1136,  1211,   680,   369,  1091,   683,   683,  1460,
     899,  1336,   605,  1377,   605,   950,   982,  1416,  1336,  1403,
     461,  1269,  1270,  1406,  1397,  1260,  1406,     5,  1257,    13,
     909,  1340,  1302,  1460,  1460,  1159,  1460,  1160,  1460,  1460,
    1350,  1347,  1409,  1406,   404,  1377,     5,   369,     5,  1340,
       5,   517,   566,  1286,  1223,   369,   325,   329,   807,   808,
     809,   986,   902,   902,   902,   902,   902,   902,    24,     5,
     369,   824,    20,   915,  1137,   260,  1136,   683,   685,   683,
     219,   369,  1377,  1377,  1460,   658,  1397,  1336,     5,   369,
     369,  1261,   408,  1460,  1460,  1333,  1405,  1284,   811,   810,
     216,   809,   812,   667,     5,  1460,   681,   947,  1270,  1260,
    1460,  1460,  1460,   824,   369,   369,   369,   682,   140,   322,
     684,  1091
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
#line 883 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 886 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 890 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 896 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 901 "fgl.yacc"
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
#line 913 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 918 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",aclfgl_%s);\n",yyvsp[0].str,yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 936 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 937 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 938 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 939 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 940 "fgl.yacc"
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
#line 954 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 955 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 956 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 957 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 958 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 963 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 964 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 975 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 978 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 981 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 981 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 988 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 989 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 995 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 996 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1007 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1008 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1009 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1010 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1017 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1021 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1025 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1026 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1030 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1036 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1038 "fgl.yacc"
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
#line 1049 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1051 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1053 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1055 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1059 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1061 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1122 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1126 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1130 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1133 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1137 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1141 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1145 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1148 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1154 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-1].ptr);
	a=get_counter_val();
	drop_counter();
	debug("Printing call_func_call...");
  	print_class_func_call(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].ptr,a);
   }
    break;

  case 71:
#line 1163 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1167 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1172 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1176 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1184 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1188 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1192 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1195 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1201 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1206 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1209 "fgl.yacc"
    {
	char buff[256];
	char *ptr;
	debug("STR6 = %s",yyvsp[-4].str);
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
#line 1225 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1232 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1236 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1240 "fgl.yacc"
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
#line 1262 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1262 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1266 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1267 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1268 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1273 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1276 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1282 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1285 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1297 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1303 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1306 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1321 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1331 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1337 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1346 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1359 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1362 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1364 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1370 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1372 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1377 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1382 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1388 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1392 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1407 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1410 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1413 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1416 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1419 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1422 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1444 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1453 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1463 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1477 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1481 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1484 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1492 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1498 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1513 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1517 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1522 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1532 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1535 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1539 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1541 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1544 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1546 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1549 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1551 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1554 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1557 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1567 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1568 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1576 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1577 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1594 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1597 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1600 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1603 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1606 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1609 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1618 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1626 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1631 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1644 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1648 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1663 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1664 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1672 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1672 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1682 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1682 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1691 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1692 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1693 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1696 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1701 "fgl.yacc"
    { }
    break;

  case 193:
#line 1701 "fgl.yacc"
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
#line 1718 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1722 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1736 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1745 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1749 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1765 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1767 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1768 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1775 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1775 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1776 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1777 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1780 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1782 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1792 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1807 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1807 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1813 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1814 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1821 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1822 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1823 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1824 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1827 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1828 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1829 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1830 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1834 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1839 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1844 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1848 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1851 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1855 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1856 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1857 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1858 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1859 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1860 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1861 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1862 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1865 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1866 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1867 "fgl.yacc"
    {
			char buff[256];
			strcpy(buff,yyvsp[0].str);
			debug("Got a rogue datatype");

			if (find_datatype(upshift(buff))) 
			{
				char *(*function) (void);
				debug("Checking ...");
				function=get_datatype_function_n(upshift(buff),"OUTPUT");
				debug("Got function as %p",function);

                /*  warning: comparison between pointer and integer */
				if ((int)function != -1 && (int)function != 0)
				{
					debug("call returns %s\n",function());
					strcpy(buff,function());
					debug("Set up buff as %s");
					push_type(function(),0,0);
					debug("Pushed type : %s\n",function());
				}
			} else {
				/* yyerror("Unknown datatype : %s",$<str>1); */
                a4gl_yyerror("Unknown datatype.");
			}
		}
    break;

  case 259:
#line 1899 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1903 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1905 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1907 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1909 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1914 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 265:
#line 1918 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1918 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1922 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1923 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1924 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1925 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1926 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1927 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1929 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1934 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1934 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1937 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1939 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1945 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1947 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1953 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1961 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1961 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1964 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1965 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1966 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1967 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 1968 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 1969 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 1971 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 1992 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 2001 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2003 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2005 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2007 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2008 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2009 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2010 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2011 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2016 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2023 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2028 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2030 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2032 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2033 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2034 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2035 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2036 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2037 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2038 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2041 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2043 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2049 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2057 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2065 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2069 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2077 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2078 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2079 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 326:
#line 2080 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2099 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2111 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2115 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2118 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2121 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 337:
#line 2122 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2123 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2124 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2125 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2131 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2138 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2143 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2148 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2152 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2155 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2163 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2165 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2170 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2182 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2185 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2188 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2191 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2194 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2197 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2210 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2213 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2228 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 363:
#line 2231 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 364:
#line 2245 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 365:
#line 2247 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 366:
#line 2249 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 367:
#line 2251 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 368:
#line 2253 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 369:
#line 2255 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 370:
#line 2256 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 371:
#line 2263 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 372:
#line 2265 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 373:
#line 2269 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 374:
#line 2271 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 375:
#line 2273 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 376:
#line 2275 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 377:
#line 2277 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 378:
#line 2279 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 379:
#line 2281 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 380:
#line 2287 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 385:
#line 2304 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2310 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2314 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 390:
#line 2319 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2329 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 401:
#line 2340 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2340 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2345 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 405:
#line 2349 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2355 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2363 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2369 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2378 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2380 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2387 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2395 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2399 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2408 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 415:
#line 2413 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2418 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 417:
#line 2422 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2424 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_EXISTS);");
}
    break;

  case 419:
#line 2434 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTEXISTS);");
}
    break;

  case 420:
#line 2448 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2456 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2468 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2474 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2480 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2490 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2496 "fgl.yacc"
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
          		if (aubit_strcasecmp(yyvsp[0].str,"today")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_today();");
          		}
		
          		if (aubit_strcasecmp(yyvsp[0].str,"time")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_time();");
          		}
		
          		if (aubit_strcasecmp(yyvsp[0].str,"pageno")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_variable(&rep.page_no,2);");
                  		}
          		if (aubit_strcasecmp(yyvsp[0].str,"lineno")==0) {
               		flg=1;
               		strcpy(yyval.str,"push_variable(&rep.line_no,2);");
          		}

         		if (flg==0) {
         				sprintf(yyval.str,"push_variable(&%s,0x%x);",yyvsp[0].str,(int)scan_variable(yyvsp[0].str));
         		}
      			p1=new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
   		}



        	if (a==-1)
        	{
                	sprintf(yyval.str,"push_char(%s);",yyvsp[0].str);inc_counter();
      			p1=new_expr(yyval.str);
       			yyval.ptr=p1;
			inc_counter();
        	}


        	if (a==-2)
        	{
			p1=new_expr("");
	        	incvcnt=print_push_rec(yyvsp[0].str,&p1);
	        	inc_counter_by(incvcnt);
			yyval.ptr=p1;
        	}




	}
    break;

  case 429:
#line 2568 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2574 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2578 "fgl.yacc"
    {
   if (!in_command("REPORT")) {
   a4gl_yyerror("This can only be done in a report!");
   YYERROR;
} 
insql=0;
	yyval.ptr=new_expr(yyvsp[0].str);
}
    break;

  case 432:
#line 2586 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2586 "fgl.yacc"
    {
	char buff[256];
      if (!in_command("REPORT")) {
        a4gl_yyerror("This can only be done in a report!");YYERROR;
      } 
      insql=0; 
	lex_printcomment("/* rep_Agg = %s\n*/",yyvsp[0].str);
        strcpy(buff,yyvsp[0].str);
	debug("report aggregate :  %s",buff);
	yyval.ptr=new_expr(buff);
      }
    break;

  case 434:
#line 2603 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 435:
#line 2607 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 436:
#line 2613 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 437:
#line 2616 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 438:
#line 2624 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN_SELECT);");
}
    break;

  case 439:
#line 2635 "fgl.yacc"
    {
	char buff[256];
	int n;
	yyval.ptr=new_expr(yyvsp[-1].sql_string);
	append_expr(yyval.ptr,"{");
	n=print_bind_expr(yyval.ptr,'i');
	sprintf(buff,"push_binding(ibind,%d);}",n);
	append_expr(yyval.ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN_SELECT);");
}
    break;

  case 440:
#line 2645 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 441:
#line 2651 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 442:
#line 2661 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 443:
#line 2666 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 444:
#line 2673 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_char(\"\\\\\");pushop(OP_MATCHES);");
 }
    break;

  case 445:
#line 2676 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_char(\"\\\\\");pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 446:
#line 2679 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 447:
#line 2684 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_MATCHES);pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 448:
#line 2691 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(\"\\\\\");pushop(OP_LIKE);");
	yyval.ptr=append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 449:
#line 2696 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(\"\\\\\");pushop(OP_LIKE);pushop(OP_NOT);");
	yyval.ptr=append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 450:
#line 2701 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 451:
#line 2706 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_LIKE);pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 452:
#line 2717 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 453:
#line 2725 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 454:
#line 2733 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 455:
#line 2738 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 456:
#line 2742 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 457:
#line 2747 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 458:
#line 2751 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 459:
#line 2755 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 460:
#line 2761 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 461:
#line 2764 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 462:
#line 2768 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 463:
#line 2772 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 464:
#line 2776 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 465:
#line 2780 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 466:
#line 2784 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 467:
#line 2791 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 468:
#line 2801 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 469:
#line 2806 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 470:
#line 2812 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		debug("Print expr (1)");
		/* print_expr($<ptr>4); */
		sprintf(yyval.str,"{int _retvars;\n_retvars=aclfgl_%s(%s); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n}\n", yyvsp[-5].str,yyvsp[-1].str, lastlineno,infilename);
		yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 471:
#line 2821 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 472:
#line 2826 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 473:
#line 2829 "fgl.yacc"
    {
	char buff[256];
        char *ptr;
        strcpy(buff,yyvsp[-3].str);
        ptr=strchr(buff,',');
        *ptr=0;
        ptr++;
	sprintf(yyval.str,"{int _retvars;\n_retvars=call_4gl_dll(%s,%s,%d); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");pop_args(_retvars);push_null();}\n}\n}\n", buff,ptr,atoi(yyvsp[-1].str), lastlineno,infilename);
	yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
}
    break;

  case 474:
#line 2843 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 475:
#line 2843 "fgl.yacc"
    {chk4var=0;}
    break;

  case 476:
#line 2843 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 477:
#line 2846 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 478:
#line 2846 "fgl.yacc"
    {chk4var=0;}
    break;

  case 479:
#line 2846 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 480:
#line 2849 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 481:
#line 2849 "fgl.yacc"
    {chk4var=0;}
    break;

  case 482:
#line 2849 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 483:
#line 2852 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 484:
#line 2852 "fgl.yacc"
    {chk4var=0;}
    break;

  case 485:
#line 2852 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 486:
#line 2855 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 487:
#line 2861 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 488:
#line 2867 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2873 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2883 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 491:
#line 2884 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 494:
#line 2892 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 495:
#line 2898 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 496:
#line 2899 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 497:
#line 2904 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 498:
#line 2908 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 499:
#line 2912 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 502:
#line 2919 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 503:
#line 2924 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 504:
#line 2931 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 505:
#line 2935 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 506:
#line 2938 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 507:
#line 2941 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 508:
#line 2947 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 509:
#line 2950 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 510:
#line 2953 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 511:
#line 2968 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 512:
#line 2971 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 513:
#line 2977 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 514:
#line 2978 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 515:
#line 2979 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 2984 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 518:
#line 2985 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 519:
#line 2986 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 2987 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 2989 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 2990 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 2991 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 2993 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 2994 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 527:
#line 3000 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 528:
#line 3013 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 529:
#line 3017 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 530:
#line 3022 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 531:
#line 3026 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 532:
#line 3042 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 533:
#line 3048 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 534:
#line 3056 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 541:
#line 3073 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 542:
#line 3075 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 543:
#line 3078 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 544:
#line 3080 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 549:
#line 3094 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 550:
#line 3096 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 551:
#line 3099 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 552:
#line 3101 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 565:
#line 3132 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 566:
#line 3134 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 567:
#line 3137 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 568:
#line 3139 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 569:
#line 3142 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 570:
#line 3144 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 571:
#line 3147 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 572:
#line 3149 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 573:
#line 3152 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 574:
#line 3154 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 575:
#line 3168 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 576:
#line 3172 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 577:
#line 3173 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 578:
#line 3180 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 580:
#line 3198 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 581:
#line 3214 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 582:
#line 3215 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 583:
#line 3216 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 584:
#line 3217 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 585:
#line 3218 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 586:
#line 3219 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 590:
#line 3227 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 592:
#line 3233 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 593:
#line 3235 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 594:
#line 3236 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 595:
#line 3238 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 596:
#line 3240 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 597:
#line 3242 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 598:
#line 3244 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 599:
#line 3246 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 600:
#line 3249 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 601:
#line 3256 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 602:
#line 3258 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 603:
#line 3264 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 604:
#line 3269 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 605:
#line 3274 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 606:
#line 3279 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 607:
#line 3279 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 608:
#line 3282 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[-1].str)) ;
}
    break;

  case 609:
#line 3288 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[-1].str) ;
			}
    break;

  case 610:
#line 3293 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 611:
#line 3297 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 614:
#line 3305 "fgl.yacc"
    {
		debug("Setident\n");
		/* chk4var=1; */
	strcpy(yyval.str,"");
	   }
    break;

  case 615:
#line 3311 "fgl.yacc"
    {
		debug("Unsetident\n");
		chk4var=0;
		}
    break;

  case 616:
#line 3315 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 617:
#line 3317 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 618:
#line 3319 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 619:
#line 3321 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 620:
#line 3323 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 621:
#line 3325 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 622:
#line 3328 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 624:
#line 3337 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 668:
#line 3398 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 669:
#line 3412 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 671:
#line 3419 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 672:
#line 3422 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 673:
#line 3428 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 674:
#line 3434 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 675:
#line 3438 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 676:
#line 3442 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 677:
#line 3448 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 678:
#line 3452 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 679:
#line 3456 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 680:
#line 3461 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 681:
#line 3466 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 700:
#line 3507 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 701:
#line 3512 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 703:
#line 3517 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 705:
#line 3520 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 706:
#line 3522 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 707:
#line 3525 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 708:
#line 3530 "fgl.yacc"
    {
	print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
}
    break;

  case 709:
#line 3535 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 710:
#line 3545 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 711:
#line 3546 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 712:
#line 3549 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 714:
#line 3555 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 715:
#line 3559 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 716:
#line 3560 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 719:
#line 3574 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 720:
#line 3576 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 723:
#line 3585 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 724:
#line 3587 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 725:
#line 3591 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 726:
#line 3593 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 727:
#line 3596 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 728:
#line 3598 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 729:
#line 3601 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 730:
#line 3604 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 731:
#line 3607 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 732:
#line 3609 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 733:
#line 3612 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 734:
#line 3614 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 735:
#line 3617 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 736:
#line 3619 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 737:
#line 3622 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 738:
#line 3624 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 739:
#line 3627 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 740:
#line 3629 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 741:
#line 3635 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 742:
#line 3636 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 743:
#line 3644 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 744:
#line 3645 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 745:
#line 3650 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 746:
#line 3651 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 747:
#line 3660 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 748:
#line 3661 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 749:
#line 3668 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 750:
#line 3669 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 751:
#line 3677 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 752:
#line 3678 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 753:
#line 3687 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 754:
#line 3692 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 755:
#line 3697 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 756:
#line 3698 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 758:
#line 3703 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 759:
#line 3706 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 760:
#line 3714 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 761:
#line 3719 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 762:
#line 3723 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 763:
#line 3725 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 764:
#line 3734 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 765:
#line 3739 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 766:
#line 3740 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 767:
#line 3741 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 768:
#line 3742 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 769:
#line 3745 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 771:
#line 3751 "fgl.yacc"
    {iskey=1;}
    break;

  case 772:
#line 3751 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 773:
#line 3753 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 774:
#line 3756 "fgl.yacc"
    {iskey=1;}
    break;

  case 775:
#line 3756 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 776:
#line 3758 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 3762 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 778:
#line 3762 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 779:
#line 3765 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 780:
#line 3766 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 782:
#line 3769 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 783:
#line 3774 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 784:
#line 3774 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 789:
#line 3781 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 790:
#line 3782 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 791:
#line 3783 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 792:
#line 3784 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 793:
#line 3785 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 794:
#line 3786 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 795:
#line 3787 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 796:
#line 3788 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 797:
#line 3789 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 798:
#line 3790 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 799:
#line 3791 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 800:
#line 3792 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 801:
#line 3793 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 802:
#line 3797 "fgl.yacc"
    {
char buff[256];
debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 803:
#line 3815 "fgl.yacc"
    {chk4var=1;}
    break;

  case 804:
#line 3815 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 805:
#line 3818 "fgl.yacc"
    {
int to_vars;
	
	debug("/*processing let*/\n");
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

  case 806:
#line 3841 "fgl.yacc"
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

  case 808:
#line 3859 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 809:
#line 3865 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 810:
#line 3871 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 811:
#line 3877 "fgl.yacc"
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

  case 812:
#line 3888 "fgl.yacc"
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

  case 813:
#line 3911 "fgl.yacc"
    {
		if (glob_only==1) {
       			debug("Read globals section so Im done\n");
       			YYACCEPT;
		}
	
		set_4gl_vars();

		set_current_variable_scope('g'); print_variables (); set_current_variable_scope('G'); print_variables (); set_current_variable_scope('m'); print_variables ();
print_module_variable_init();
		set_current_variable_scope('m');
	}
    break;

  case 816:
#line 3927 "fgl.yacc"
    {
	}
    break;

  case 823:
#line 3950 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 827:
#line 3958 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 845:
#line 3984 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 846:
#line 3985 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 847:
#line 3993 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 848:
#line 3998 "fgl.yacc"
    { 

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

  case 849:
#line 4011 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 850:
#line 4017 "fgl.yacc"
    {
  int c;
  lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 852:
#line 4032 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;

  case 853:
#line 4045 "fgl.yacc"
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

  case 854:
#line 4055 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 855:
#line 4062 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 856:
#line 4069 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 857:
#line 4075 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 858:
#line 4075 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 859:
#line 4080 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 860:
#line 4085 "fgl.yacc"
    {
}
    break;

  case 866:
#line 4097 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 868:
#line 4105 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 869:
#line 4111 "fgl.yacc"
    {
char b[256];
	lastlineno=yylineno;
	strcpy(b,yyvsp[0].str);
	set_current_variable_scope('G');
	tr_glob_fname(b);
	debug("Reading globals file %s\n",b);
	rm_quote(b);
	read_glob(b);
	set_current_variable_scope('m');
}
    break;

  case 870:
#line 4125 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 871:
#line 4129 "fgl.yacc"
    {
  char buff[80];
  sprintf(buff,"%s_%s_%d",yyvsp[-4].str,yyvsp[-6].str,atoi(yyvsp[-1].str));
  sprintf(curr_func,"%s",buff);
  print_func_start("",buff,1);
  printDeclareFunctionStack(buff);

  cnt=0;
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 872:
#line 4142 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 874:
#line 4156 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 875:
#line 4162 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 876:
#line 4166 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 879:
#line 4178 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 880:
#line 4183 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 881:
#line 4188 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 882:
#line 4191 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 883:
#line 4206 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 884:
#line 4213 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 885:
#line 4219 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 886:
#line 4230 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 887:
#line 4234 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 888:
#line 4241 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 889:
#line 4248 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 890:
#line 4254 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 891:
#line 4259 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 894:
#line 4266 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 895:
#line 4267 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 896:
#line 4269 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 897:
#line 4270 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 898:
#line 4273 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 899:
#line 4274 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 900:
#line 4275 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 901:
#line 4277 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 902:
#line 4282 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 903:
#line 4287 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 904:
#line 4294 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 908:
#line 4301 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 909:
#line 4303 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 910:
#line 4305 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 911:
#line 4312 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 912:
#line 4315 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 913:
#line 4319 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 914:
#line 4323 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 921:
#line 4340 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 923:
#line 4342 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 924:
#line 4342 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 925:
#line 4345 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 926:
#line 4355 "fgl.yacc"
    {
char buff[256];
char buff2[256];
int n;
strcpy(buff,yyvsp[0].str);
lex_printcomment("/* .. var %s*/",buff);
if (buff[0]!=' ') addmap("Use Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
	convlower(buff);
}

strcpy(yyval.str,buff);
debug("Checking variable '%s'",buff);
n=scan_variable(buff);

  debug("scan variable returns -> %d\n",n);

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

  case 928:
#line 4392 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 930:
#line 4399 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 931:
#line 4404 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         lex_printcomment("/* OPEN_SQUARE.. */\n");

         sprintf(buff,"%s.%s",yyvsp[-4].str,yyvsp[-3].str);
         if (scan_variable(buff)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (2)",buff);
           a4gl_yyerror(buff2);
           YYERROR;
         }

         lex_printcomment("/*variable with [...]*/");
         get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
         lex_printcomment("/* Arrsize = %d size = %d*/",arrsize,size);
	 
         if (arrsize>0)
         {
             debug("Is array...");
             sprintf (yyval.str, "%s[%s]", buff, change_arr_elem(yyvsp[-1].str));
             lex_printcomment ("/* array variable %s num_arr_elem=%d arrbuff=%d*/\n", yyval.str,num_arr_elem(yyvsp[-1].str),num_arr_elem(arrbuff));
         }
         else
         {
             debug ("Is string...");
             sprintf (yyval.str, " substr(%s , %d , %s , 0 ) /*1*/", buff,
                      (int)scan_variable (buff), yyvsp[-1].str);

             addmap("Use Variable",buff,curr_func,yylineno,infilename);
             lex_printcomment ("/*character variable %s*/\n", yyval.str);
         }

         mcnt++;
}
    break;

  case 935:
#line 4448 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (3)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,1)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 936:
#line 4462 "fgl.yacc"
    {
char buff2[256];
         if (scan_variable(yyvsp[-3].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (4)",yyvsp[-3].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }
lex_printcomment("/*Associative Variable : %s*/\n",yyvsp[-1].str);
sprintf(yyval.str," ASSOCIATE_%s(%s,0)",upshift(yyvsp[-3].str),yyvsp[-1].str);
}
    break;

  case 941:
#line 4486 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char buff2[256];
  char arrbuff[256];
  lex_printcomment("/*array variable nnn */");
  get_variable_dets (yyvsp[-1].str,&type,&arrsize,&size,&level,arrbuff);
  lex_printcomment("/*here %s %x */",yyvsp[-1].str,type);
  if (scan_variable(yyvsp[-1].str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (7)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;

	}


  debug("Type=%d (%d) arrsize=%d",type,type&0xffff,arrsize);

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
        sprintf (yyval.str, " substr(%s,%d,%s,0) /*2*/", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
 
  if ((type & (0xffff != 0)) || (arrsize>0))
    {
      lex_printcomment("/* changing optbase for array: %s */\n",yyvsp[0].str);
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, change_arr_elem(yyvsp[0].str));
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " substr(%s,0x%x,%s,0)/*3*/", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);
             addmap("Use Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
      	dec_counter();
      	mcnt--;
    }
}

  mcnt++;
}
    break;

  case 942:
#line 4540 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 943:
#line 4545 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 944:
#line 4553 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 945:
#line 4558 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 946:
#line 4566 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 947:
#line 4572 "fgl.yacc"
    {
char buff[256];
strcpy(buff,yyvsp[0].str);
addmap("Let Variable",buff,curr_func,yylineno,infilename);

if (strncmp(buff," ASSOCIATE_",11)!=0) {
convlower(buff);
}
strcpy(yyval.str,buff);
lex_printcomment("/* %s */\n",yyvsp[0].str);
  if (scan_variable (buff) == -1&&buff[0]!=' ')
    {
      lex_printcomment ("/*NOt a variable*/");
      sprintf(buff,"%s is not a variable",yyvsp[0].str);
      a4gl_yyerror(buff);
    }

  mcnt = 0;
}
    break;

  case 948:
#line 4592 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 949:
#line 4595 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 950:
#line 4597 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  lex_printcomment("/*array variable .let. */");

  sprintf(yyval.str,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);

         if (scan_variable(yyval.str)==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (5)",yyval.str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }

  debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-6].str, yyvsp[-3].str,yyvsp[-1].str);
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-6].str,yyvsp[-3].str);
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 955:
#line 4645 "fgl.yacc"
    {
/*OPEN_SQUARE num_list CLOSE_SQUARE*/
  int a;
  int b;
  char buff2[256];
  lex_printcomment("/*.let. array variable */");

  debug("?2 arrvar=%s",yyvsp[-1].str);
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
        sprintf (yyval.str, " let_substr(%s,%d,%s,0)", tmpbuff, (int)scan_variable (tmpbuff), rbuff);
  } else {
  	b = isarrvariable (yyvsp[-1].str);
  	a = scan_variable (yyvsp[-1].str);

         if (a==-1) {
           sprintf(buff2,"'%s' does not represent a defined variable (6)",yyvsp[-1].str);
           a4gl_yyerror(buff2); 
           YYERROR;
         }


  debug("/*a=%d b=%d*/\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s[%s]", yyvsp[-1].str, decode_array_string(yyvsp[0].str));
      debug ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", yyvsp[-1].str, (int)scan_variable (yyvsp[-1].str), yyvsp[0].str);

      addmap("Let Variable",yyvsp[-1].str,curr_func,yylineno,infilename);
      debug ("/*character variable %s*/\n", yyval.str);
    }
 }
  mcnt++;

}
    break;

  case 956:
#line 4697 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 958:
#line 4704 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 959:
#line 4710 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 960:
#line 4721 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 961:
#line 4728 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 963:
#line 4736 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 964:
#line 4739 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 965:
#line 4740 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 967:
#line 4742 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 968:
#line 4743 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 969:
#line 4746 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 970:
#line 4749 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 971:
#line 4755 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 972:
#line 4758 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 973:
#line 4762 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 974:
#line 4766 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 975:
#line 4773 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 976:
#line 4778 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 977:
#line 4785 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 978:
#line 4788 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 983:
#line 4801 "fgl.yacc"
    {
  int type,arrsize,size,level;
  char arrbuff[256];
  lex_printcomment("/*..array_r_varid..*/");

if (get_variable_dets (yyvsp[-3].str,&type,&arrsize,&size,&level,arrbuff)>=0) {
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,subtract_one(yyvsp[-1].str));
} else {
  sprintf(yyval.str,"%s[%s]",yyvsp[-3].str,yyvsp[-1].str);
}
}
    break;

  case 984:
#line 4814 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 985:
#line 4821 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 986:
#line 4828 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 987:
#line 4831 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 988:
#line 4845 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 993:
#line 4862 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 994:
#line 4867 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 995:
#line 4873 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 997:
#line 4880 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 998:
#line 4885 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 999:
#line 4888 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1000:
#line 4889 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1001:
#line 4892 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1002:
#line 4893 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1003:
#line 4896 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1004:
#line 4897 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1005:
#line 4902 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1006:
#line 4909 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1007:
#line 4912 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1008:
#line 4918 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1009:
#line 4920 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1010:
#line 4922 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1011:
#line 4924 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1012:
#line 4927 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1013:
#line 4927 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1014:
#line 4928 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1015:
#line 4933 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1016:
#line 4941 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1017:
#line 4942 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1018:
#line 4947 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1019:
#line 4949 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1020:
#line 4951 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1024:
#line 4968 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1025:
#line 4971 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1026:
#line 4974 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1027:
#line 4977 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1028:
#line 4980 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1029:
#line 4983 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1030:
#line 4986 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1031:
#line 4990 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1032:
#line 4994 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1033:
#line 4998 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1034:
#line 5001 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1035:
#line 5005 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1036:
#line 5008 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1037:
#line 5009 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1038:
#line 5010 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1039:
#line 5013 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1040:
#line 5016 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1041:
#line 5019 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1042:
#line 5022 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1043:
#line 5025 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1044:
#line 5028 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1045:
#line 5031 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1046:
#line 5048 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1049:
#line 5058 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1050:
#line 5065 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1052:
#line 5086 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1053:
#line 5091 "fgl.yacc"
    {
		if (strcmp(yyvsp[-5].str,"1")==0) {
			print_prompt_forchar();
                }
		add_continue_blockcommand ("PROMPT");
		print_prompt_end(yyvsp[-4].str);
                pop_blockcommand("PROMPT");
                lex_printcomment("/* END OF PROMPT */");
                }
    break;

  case 1054:
#line 5104 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1055:
#line 5109 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1056:
#line 5110 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1057:
#line 5114 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1061:
#line 5120 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1062:
#line 5122 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1064:
#line 5137 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1065:
#line 5141 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1066:
#line 5147 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1067:
#line 5148 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1068:
#line 5151 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1069:
#line 5152 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1070:
#line 5155 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1072:
#line 5174 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1073:
#line 5179 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1074:
#line 5184 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1075:
#line 5189 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1081:
#line 5211 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1082:
#line 5218 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1083:
#line 5224 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1084:
#line 5226 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1088:
#line 5237 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1089:
#line 5238 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1090:
#line 5240 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1091:
#line 5241 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1092:
#line 5243 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1093:
#line 5244 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1094:
#line 5246 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1095:
#line 5247 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1096:
#line 5249 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1097:
#line 5250 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1098:
#line 5251 "fgl.yacc"
    {
int a;
char buff[80];
debug("rordcnt=%d",rordcnt);
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

  case 1099:
#line 5265 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1100:
#line 5267 "fgl.yacc"
    { 
int a;
char buff[80];

debug("rordcnt=%d",rordcnt);
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

  case 1101:
#line 5284 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1108:
#line 5296 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1109:
#line 5296 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1110:
#line 5302 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1111:
#line 5302 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1112:
#line 5305 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1113:
#line 5305 "fgl.yacc"
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

  case 1114:
#line 5315 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1115:
#line 5316 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1116:
#line 5317 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1117:
#line 5324 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1118:
#line 5336 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1124:
#line 5347 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1125:
#line 5352 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1126:
#line 5356 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1127:
#line 5361 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1128:
#line 5367 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1129:
#line 5368 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1130:
#line 5369 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1131:
#line 5373 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1132:
#line 5374 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1133:
#line 5375 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1134:
#line 5376 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1135:
#line 5380 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1136:
#line 5390 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1137:
#line 5392 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1138:
#line 5397 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1139:
#line 5400 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1140:
#line 5405 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1141:
#line 5412 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1142:
#line 5419 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 5426 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1144:
#line 5435 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1145:
#line 5442 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1146:
#line 5449 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1147:
#line 5456 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1148:
#line 5463 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1153:
#line 5476 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1154:
#line 5477 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1155:
#line 5478 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1156:
#line 5479 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1157:
#line 5480 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1158:
#line 5481 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1159:
#line 5482 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1160:
#line 5483 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1161:
#line 5484 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5485 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1165:
#line 5491 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1166:
#line 5492 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1167:
#line 5493 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1168:
#line 5494 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1173:
#line 5503 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1174:
#line 5504 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1175:
#line 5505 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1176:
#line 5506 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1177:
#line 5507 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1178:
#line 5508 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1179:
#line 5509 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1180:
#line 5510 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1181:
#line 5512 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1182:
#line 5513 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1183:
#line 5514 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1184:
#line 5515 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1185:
#line 5517 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1186:
#line 5518 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1187:
#line 5519 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1188:
#line 5520 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1192:
#line 5525 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1193:
#line 5526 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1197:
#line 5533 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1198:
#line 5540 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1199:
#line 5547 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1200:
#line 5558 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1201:
#line 5567 "fgl.yacc"
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

  case 1202:
#line 5578 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1203:
#line 5582 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1204:
#line 5586 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1205:
#line 5592 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1206:
#line 5597 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1207:
#line 5605 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1208:
#line 5608 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1209:
#line 5617 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1210:
#line 5628 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1212:
#line 5635 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1213:
#line 5643 "fgl.yacc"
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

  case 1214:
#line 5653 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1215:
#line 5656 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1216:
#line 5660 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1217:
#line 5668 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1218:
#line 5671 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1219:
#line 5677 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1220:
#line 5681 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1221:
#line 5685 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1222:
#line 5689 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1223:
#line 5693 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1224:
#line 5699 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1225:
#line 5700 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1226:
#line 5701 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1227:
#line 5702 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1228:
#line 5707 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1229:
#line 5709 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1230:
#line 5712 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1231:
#line 5716 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1232:
#line 5719 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1233:
#line 5726 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1234:
#line 5731 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1235:
#line 5732 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1236:
#line 5733 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1237:
#line 5738 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1238:
#line 5739 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1239:
#line 5745 "fgl.yacc"
    {insql=1;}
    break;

  case 1240:
#line 5745 "fgl.yacc"
    {insql=0;}
    break;

  case 1241:
#line 5745 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1242:
#line 5750 "fgl.yacc"
    {insql=1;}
    break;

  case 1243:
#line 5750 "fgl.yacc"
    {insql=0;}
    break;

  case 1244:
#line 5750 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1245:
#line 5761 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1246:
#line 5762 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1247:
#line 5768 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1248:
#line 5770 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1250:
#line 5777 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1251:
#line 5781 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1252:
#line 5782 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1254:
#line 5787 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1255:
#line 5790 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1256:
#line 5796 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1257:
#line 5799 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 5807 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1260:
#line 5814 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1261:
#line 5821 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1262:
#line 5824 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1263:
#line 5833 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1264:
#line 5836 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1265:
#line 5839 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1266:
#line 5842 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1267:
#line 5845 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1268:
#line 5848 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1269:
#line 5851 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1270:
#line 5858 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1271:
#line 5861 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1272:
#line 5868 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1273:
#line 5871 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1274:
#line 5877 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1275:
#line 5880 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1276:
#line 5887 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1277:
#line 5890 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1279:
#line 5898 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1281:
#line 5907 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1282:
#line 5910 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1283:
#line 5916 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1284:
#line 5919 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1285:
#line 5925 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1286:
#line 5932 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1287:
#line 5933 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1288:
#line 5937 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1289:
#line 5943 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1290:
#line 5946 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1292:
#line 5954 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1293:
#line 5961 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1294:
#line 5964 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1298:
#line 5982 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1304:
#line 5988 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1305:
#line 5991 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1306:
#line 5994 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1307:
#line 6000 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1309:
#line 6006 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1311:
#line 6017 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1312:
#line 6031 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1313:
#line 6033 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1314:
#line 6035 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1315:
#line 6040 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1316:
#line 6044 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1317:
#line 6050 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1318:
#line 6058 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-5].str,")=(",yyvsp[-1].sql_string,")",0);

		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(0)); 
			ansi_violation("Update (..)=(..)",0);
		}  else {
			ansi_violation("Update (..)=(..)",1);
		}
    }
    break;

  case 1319:
#line 6068 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
    }
    break;

  case 1320:
#line 6071 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("*=(",yyvsp[-1].sql_string,")",0);
		push_gen(UPDCOL,"*");
		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
}
    break;

  case 1321:
#line 6081 "fgl.yacc"
    {
		char *ptr;

		ptr=yyvsp[0].sql_string;
		push_gen(UPDCOL,"*");

		if (ptr[0]=='(') {
			yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		} else {
			yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].str,"(",yyvsp[0].sql_string,")",0);
		}

		if (isyes(acl_getenv("FIXUPDATE"))) { 
			yyval.sql_string=strdup(fix_update_expr(1));
			ansi_violation("Update (..)=(..)",0);
		} else {
			ansi_violation("Update (..)=(..)",1);
		}
	}
    break;

  case 1322:
#line 6103 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1323:
#line 6106 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6115 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1326:
#line 6120 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1327:
#line 6121 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1328:
#line 6127 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1329:
#line 6130 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1330:
#line 6139 "fgl.yacc"
    {
		push_gen(UPDVAL,"NULL");
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1331:
#line 6143 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1332:
#line 6150 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1333:
#line 6159 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1334:
#line 6159 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1335:
#line 6164 "fgl.yacc"
    {insql=1;}
    break;

  case 1336:
#line 6164 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1337:
#line 6169 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1338:
#line 6172 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1339:
#line 6174 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6181 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6185 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1343:
#line 6189 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1344:
#line 6196 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1345:
#line 6199 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1346:
#line 6206 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1347:
#line 6210 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1348:
#line 6214 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1349:
#line 6223 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1350:
#line 6227 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1351:
#line 6233 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1352:
#line 6237 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1353:
#line 6243 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1354:
#line 6250 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1355:
#line 6254 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1356:
#line 6259 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1357:
#line 6269 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1358:
#line 6272 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1359:
#line 6274 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1360:
#line 6276 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1361:
#line 6278 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1362:
#line 6280 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1363:
#line 6282 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1364:
#line 6284 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1365:
#line 6290 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1366:
#line 6300 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1367:
#line 6307 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1369:
#line 6313 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1373:
#line 6322 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1376:
#line 6327 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1377:
#line 6332 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1378:
#line 6339 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1379:
#line 6340 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1380:
#line 6347 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1381:
#line 6359 "fgl.yacc"
    {insql=1;}
    break;

  case 1382:
#line 6359 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1383:
#line 6364 "fgl.yacc"
    {
			lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1384:
#line 6369 "fgl.yacc"
    {
		lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1386:
#line 6375 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1388:
#line 6379 "fgl.yacc"
    {
		lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1389:
#line 6384 "fgl.yacc"
    {
		lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1390:
#line 6389 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
		lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1391:
#line 6393 "fgl.yacc"
    {
		lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1393:
#line 6399 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1394:
#line 6403 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1395:
#line 6411 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1396:
#line 6414 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1397:
#line 6416 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1398:
#line 6421 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1401:
#line 6428 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6435 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6438 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1407:
#line 6440 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1409:
#line 6446 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1411:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1414:
#line 6462 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1415:
#line 6467 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1416:
#line 6469 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6475 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6478 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1421:
#line 6484 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1422:
#line 6492 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1423:
#line 6497 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1426:
#line 6507 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6513 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6519 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1430:
#line 6521 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1432:
#line 6527 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6532 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1434:
#line 6535 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1435:
#line 6538 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1436:
#line 6546 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1437:
#line 6548 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1438:
#line 6559 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1439:
#line 6564 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1441:
#line 6568 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1442:
#line 6570 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1443:
#line 6577 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1444:
#line 6580 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1445:
#line 6586 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1446:
#line 6590 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1447:
#line 6594 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1448:
#line 6597 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1449:
#line 6605 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1450:
#line 6612 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1453:
#line 6621 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1454:
#line 6627 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1455:
#line 6630 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1456:
#line 6641 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 6648 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 6654 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1459:
#line 6657 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1460:
#line 6664 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1461:
#line 6671 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1463:
#line 6678 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1464:
#line 6684 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1465:
#line 6685 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1466:
#line 6686 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1468:
#line 6690 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1470:
#line 6695 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1471:
#line 6702 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1472:
#line 6707 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1473:
#line 6708 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1474:
#line 6711 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1475:
#line 6714 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1476:
#line 6719 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1477:
#line 6720 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1478:
#line 6725 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1479:
#line 6728 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1480:
#line 6734 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1481:
#line 6737 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1482:
#line 6743 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1483:
#line 6746 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1484:
#line 6752 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1485:
#line 6755 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1486:
#line 6762 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1487:
#line 6763 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1488:
#line 6792 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1489:
#line 6794 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 6807 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1493:
#line 6810 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1494:
#line 6813 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1495:
#line 6816 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1497:
#line 6824 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 6830 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1502:
#line 6836 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1503:
#line 6839 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1504:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str,yyvsp[0].sql_string,0);
	}
    break;

  case 1505:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1506:
#line 6848 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," LIKE ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1507:
#line 6851 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1509:
#line 6858 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1514:
#line 6865 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1515:
#line 6866 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1516:
#line 6871 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1517:
#line 6874 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1518:
#line 6878 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 6884 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1520:
#line 6885 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1521:
#line 6886 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1522:
#line 6887 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1527:
#line 6907 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1528:
#line 6912 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1529:
#line 6913 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1531:
#line 6916 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1535:
#line 6921 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1537:
#line 6924 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1539:
#line 6927 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1543:
#line 6932 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 6934 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1545:
#line 6937 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1546:
#line 6938 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1547:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1551:
#line 6950 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1555:
#line 6966 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1556:
#line 6967 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1557:
#line 6971 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1558:
#line 6972 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1560:
#line 6987 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1561:
#line 6988 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1562:
#line 6989 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1563:
#line 6993 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1564:
#line 6998 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1565:
#line 7003 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1567:
#line 7016 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1571:
#line 7024 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1572:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1573:
#line 7028 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1574:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1576:
#line 7035 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1577:
#line 7038 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1578:
#line 7041 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1579:
#line 7043 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1580:
#line 7046 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1581:
#line 7048 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1582:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1583:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1584:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1585:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1586:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1587:
#line 7051 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1588:
#line 7052 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1589:
#line 7055 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1590:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1591:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1592:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1593:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1594:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1595:
#line 7060 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1596:
#line 7062 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1597:
#line 7065 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1612:
#line 7074 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1613:
#line 7075 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1614:
#line 7079 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1615:
#line 7087 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1616:
#line 7087 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1617:
#line 7092 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1618:
#line 7092 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1619:
#line 7098 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1620:
#line 7098 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1621:
#line 7103 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1622:
#line 7103 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1623:
#line 7110 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1624:
#line 7111 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1625:
#line 7112 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1629:
#line 7119 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1630:
#line 7120 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1631:
#line 7125 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1632:
#line 7128 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1633:
#line 7134 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1634:
#line 7137 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1635:
#line 7146 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1636:
#line 7158 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1637:
#line 7159 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1638:
#line 7161 "fgl.yacc"
    {
		char *ptr;
                ptr=make_sql_string("SELECT ",yyvsp[-6].str, yyvsp[-5].sql_string," ", yyvsp[-3].sql_string, " ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);

		yyval.sql_string=strdup(print_select_all(ptr));
		free(ptr);
		free(yyvsp[-5].sql_string);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);
}
    break;

  case 1639:
#line 7175 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1640:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1641:
#line 7188 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1642:
#line 7196 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-6].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1643:
#line 7205 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1644:
#line 7208 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1645:
#line 7212 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1646:
#line 7215 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1647:
#line 7216 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1649:
#line 7225 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1650:
#line 7226 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1651:
#line 7235 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1652:
#line 7244 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1653:
#line 7249 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1654:
#line 7250 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1655:
#line 7251 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1656:
#line 7252 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1657:
#line 7260 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1658:
#line 7263 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1659:
#line 7269 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1660:
#line 7272 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1661:
#line 7275 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1662:
#line 7281 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1663:
#line 7290 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1664:
#line 7296 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1665:
#line 7299 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1666:
#line 7306 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1667:
#line 7308 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1668:
#line 7310 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1669:
#line 7312 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1670:
#line 7314 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1671:
#line 7316 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1672:
#line 7318 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1673:
#line 7320 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1674:
#line 7322 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1675:
#line 7324 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1676:
#line 7326 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1677:
#line 7328 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1678:
#line 7330 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1679:
#line 7332 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1680:
#line 7334 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1681:
#line 7336 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1682:
#line 7338 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1683:
#line 7340 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1684:
#line 7342 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1685:
#line 7344 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1686:
#line 7348 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1687:
#line 7349 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1690:
#line 7359 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1691:
#line 7368 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1692:
#line 7372 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1693:
#line 7379 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1694:
#line 7379 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1696:
#line 7383 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1697:
#line 7388 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1698:
#line 7388 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1700:
#line 7392 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1701:
#line 7396 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1704:
#line 7405 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1705:
#line 7405 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1710:
#line 7424 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1711:
#line 7425 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1714:
#line 7433 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1715:
#line 7439 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1718:
#line 7458 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1719:
#line 7459 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1720:
#line 7460 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1721:
#line 7461 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1722:
#line 7462 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1723:
#line 7463 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1724:
#line 7467 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1725:
#line 7468 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1726:
#line 7469 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1727:
#line 7473 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1728:
#line 7477 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1730:
#line 7486 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1732:
#line 7491 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1733:
#line 7492 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1734:
#line 7496 "fgl.yacc"
    {
		printf("---> %s\n",yyvsp[0].str);
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1735:
#line 7503 "fgl.yacc"
    {
 		strcpy(yyval.str,get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1736:
#line 7589 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1737:
#line 7600 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1741:
#line 7606 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1742:
#line 7607 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1746:
#line 7617 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);

		z-=a;
		strcpy(yyval.str,set_var_sql(z));
	}
}
    break;

  case 1747:
#line 7629 "fgl.yacc"
    {
char r1[256];
char r2[256];
char buff[256];
char kp[40000];
char *ptr1;
char *ptr2;
/*
int v1;
int v2 = 0;
*/
int aa;
int z = 0,a = 0;
struct variable *v_r;
struct variable *v_1;
struct variable *v_2;
struct variable *v_loop;

 /*
        strcpy(r1,$<str>1);
        ptr1=strrchr(r1,'.');
        if (ptr1==0) {
                a4gl_yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr1=0;
        ptr1++;

        strcpy(r2,$<str>3);
        debug("r2=%s",r2);

        ptr2=strrchr(r2,'.');

        if (ptr2==0) {
                a4gl_yyerror("Must have a . in a thru");YYERROR;
        }
        *ptr2=0;

        debug("Checking portions %s %s\n",r1,r2);

        if (strcmp(r1,r2)!=0) {
                a4gl_yyerror("Records for thru look different...");YYERROR;
        }

        debug("Checking variables");
        v1=scan_variable($<str>1);

        if (v2==-1) {
                debug("Variable not found..");
                a4gl_yyerror("Variable not found (first entry in thru)");YYERROR;
        }
        v1=last_var_found;
        debug("v1=%d",v1);

        v2=scan_variable($<str>3);
        if (v2==-1) {
                debug("Variable not found..");
                a4gl_yyerror("Variable not found (second entry in thru)");
        }
        v2=last_var_found;
        debug("v2=%d",v2);

*/
        strcpy(yyval.str,"");


	split_record(yyvsp[0].str,&v_r,&v_1,&v_2);

	v_loop=v_1;

	while (1) {
                strcpy(kp,yyval.str);
                sprintf(buff,"%s.%s",r1,v_loop->names.name);

		if (scan_variable(buff)!=-1&&(!system_var(buff))) {
			a=get_bind_cnt('i');
			z=add_bind('i',buff);
			z-=a;
        	}

		for (a=0;a<z;a++)  {
			if (strlen(yyval.str)) {strcat(yyval.str,",");}
         		strcat(yyval.str,"?");
		}
		v_loop=get_next_variable(v_r,v_loop,v_2);
	}
}
    break;

  case 1748:
#line 7727 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1749:
#line 7729 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1750:
#line 7731 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1751:
#line 7732 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1752:
#line 7737 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1753:
#line 7742 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1754:
#line 7744 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1755:
#line 7746 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 7748 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 7751 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1758:
#line 7755 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1759:
#line 7760 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1760:
#line 7765 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1761:
#line 7769 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1763:
#line 7779 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1765:
#line 7794 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1766:
#line 7797 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1767:
#line 7801 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1770:
#line 7820 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1771:
#line 7821 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1772:
#line 7824 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1773:
#line 7825 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1774:
#line 7826 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1775:
#line 7827 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1776:
#line 7828 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1777:
#line 7829 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1778:
#line 7830 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1779:
#line 7835 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1780:
#line 7836 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1781:
#line 7840 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1782:
#line 7844 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1783:
#line 7848 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1784:
#line 7852 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1785:
#line 7857 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1786:
#line 7861 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1787:
#line 7866 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1789:
#line 7874 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1791:
#line 7880 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1792:
#line 7886 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1793:
#line 7890 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1798:
#line 7908 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1799:
#line 7915 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1800:
#line 7924 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1801:
#line 7924 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16418 "y.tab.c"

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


#line 8018 "fgl.yacc"

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



