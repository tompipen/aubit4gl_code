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
     NAME = 1635,
     UMINUS = 1636,
     COMMA = 1551,
     KW_OR = 1591,
     KW_AND = 1546,
     KW_USING = 1482,
     MATCHES = 1360,
     POWER = 1468,
     LESS_THAN = 1464,
     GREATER_THAN = 1378,
     EQUAL = 1541,
     GREATER_THAN_EQ = 1277,
     LESS_THAN_EQ = 1335,
     NOT_EQUAL = 1409,
     PLUS = 1577,
     MINUS = 1564,
     DIVIDE = 1497,
     MULTIPLY = 1469,
     MOD = 1565,
     COMMAND = 1342,
     NUMBER_VALUE = 1637,
     CHAR_VALUE = 1638,
     INT_VALUE = 1639,
     NAMED_GEN = 1640,
     CLINE = 1641,
     SQLLINE = 1642,
     KW_CSTART = 1643,
     KW_CEND = 1644,
     USER_DTYPE = 1645,
     SQL_TEXT = 1646,
     ALTER_TABLE = 1000,
     NEWFORMATSHARED = 1001,
     CREATE_DATABASE = 1002,
     IMPORT_LEGACY_FUNCTION = 1003,
     ADD_CONSTRAINT = 1004,
     DROP_CONSTRAINT = 1005,
     AS_STATIC = 1006,
     NOT_FIELD_TOUCHED = 1007,
     LOCAL_FUNCTION = 1008,
     EVERY_ROW = 1009,
     ELIF = 1010,
     DOUBLE_PRECISION = 1011,
     COUNT_MULTIPLY = 1012,
     WAIT_FOR_KEY = 1013,
     AT_TERMINATION_CALL = 1014,
     TO_MAIN_CAPTION = 1015,
     CLEARSTAT = 1016,
     TO_MENUITEM = 1017,
     ID_TO_INT = 1018,
     TO_STATUSBOX = 1019,
     ASCII_HEIGHT_ALL = 1020,
     ASCII_WIDTH_ALL = 1021,
     IMPORT_DATATYPE = 1022,
     UP_BY = 1023,
     PAGE_TRAILER_SIZE = 1024,
     PAGE_HEADER_SIZE = 1025,
     FIRST_PAGE_HEADER_SIZE = 1026,
     BYTES_USE_AS_IMAGE = 1027,
     BYTES_USE_AS_ASCII = 1028,
     DOWN_BY = 1029,
     CLOSE_STATUSBOX = 1030,
     MODIFY_NEXT_SIZE = 1031,
     LOCK_MODE_PAGE = 1032,
     LOCK_MODE_ROW = 1033,
     TO_PIPE = 1034,
     TO_PRINTER = 1035,
     STATUSBOX = 1036,
     CONNECT_TO = 1037,
     FORMHANDLER_INPUT = 1038,
     UNITS_YEAR = 1039,
     UNITS_MONTH = 1040,
     UNITS_DAY = 1041,
     UNITS_HOUR = 1042,
     UNITS_MINUTE = 1043,
     UNITS_SECOND = 1044,
     NO_NEW_LINES = 1045,
     FIELDTOWIDGET = 1046,
     WITH_HOLD = 1047,
     SHOW_MENU = 1048,
     CWIS = 1049,
     CREATE_IDX = 1050,
     FORM_IS_COMPILED = 1051,
     PDF_REPORT = 1052,
     IMPORT_FUNCTION = 1053,
     PROMPT_MANY = 1054,
     POINTS = 1055,
     MM = 1056,
     INCHES = 1057,
     PREPEND = 1058,
     MEMBER_OF = 1059,
     MEMBER_FUNCTION = 1060,
     APPEND = 1061,
     TEMPLATE = 1062,
     END_TEMPLATE = 1063,
     SQLSICS = 1064,
     CREATE_SCHEMA = 1065,
     SQLSIRR = 1066,
     UPDATESTATS_T = 1067,
     SQLSICR = 1068,
     WHENEVER_SQLSUCCESS = 1069,
     WHENEVER_SQLWARNING = 1070,
     START_EXTERN = 1071,
     WHENEVER_ANY_ERROR = 1072,
     WHENEVER_NOT_FOUND = 1073,
     CONTINUE_CONSTRUCT = 1074,
     FOUNCONSTR = 1075,
     SQLSIDR = 1076,
     WHENEVER_SQLERROR = 1077,
     CREATE_TEMP_TABLE = 1078,
     CURRENT_WINDOW_IS = 1079,
     FIRST_PAGE_HEADER = 1080,
     ORDER_EXTERNAL_BY = 1081,
     SCROLL_CURSOR_FOR = 1082,
     SCROLL_CURSOR = 1083,
     SQL_INTERRUPT_OFF = 1084,
     STOP_ALL_EXTERNAL = 1085,
     WITH_CHECK_OPTION = 1086,
     WITH_GRANT_OPTION = 1087,
     SQLSLMNW = 1088,
     ADDCONSTUNIQ = 1089,
     CONTINUE_DISPLAY = 1090,
     CONTINUE_FOREACH = 1091,
     OUTPUT_TO_REPORT = 1092,
     SQL_INTERRUPT_ON = 1093,
     WHENEVER_SUCCESS = 1094,
     WHENEVER_WARNING = 1095,
     WHERE_CURRENT_OF = 1096,
     WITHOUT_DEFAULTS = 1097,
     FOCONSTR = 1098,
     SCALED_BY = 1099,
     CONTINUE_PROMPT = 1100,
     PDF_FUNCTION = 1101,
     DEFER_INTERRUPT = 1102,
     DISPLAY_BY_NAME = 1103,
     NOT_NULL_UNIQUE = 1104,
     SKIP_TO_TOP = 1105,
     TOP_OF_PAGE = 1106,
     SKIP_TO = 1107,
     SKIP_BY = 1108,
     WITHOUT_WAITING = 1109,
     BEFCONSTRUCT = 1110,
     SQLSLMW = 1111,
     WHENEVER_ERROR_CONTINUE = 1112,
     WHENEVER_ERROR = 1113,
     AFTCONSTRUCT = 1114,
     ALL_PRIVILEGES = 1115,
     CLOSE_DATABASE = 1116,
     CONTINUE_INPUT = 1117,
     CONTINUE_WHILE = 1118,
     CREATE_SYNONYM = 1119,
     DROP_TABLE = 1120,
     EXIT_CONSTRUCT = 1121,
     INEXCLUSIVE = 1122,
     REPORT_TO_PRINTER = 1123,
     REPORT_TO_PIPE = 1124,
     SET_SESSION_TO = 1125,
     UPDATESTATS = 1126,
     WITHOUT_HEAD = 1127,
     CLEARSCR = 1128,
     WITH_B_LOG = 1129,
     AUTHORIZATION = 1130,
     BOTTOM_MARGIN = 1131,
     CLOSE_SESSION = 1132,
     CONTINUE_CASE = 1133,
     CONTINUE_MENU = 1134,
     DISPLAY_ARRAY = 1135,
     END_SQL = 1136,
     DOLLAR = 1137,
     END_CONSTRUCT = 1138,
     FIELD_TOUCHED = 1139,
     FINISH_REPORT = 1140,
     INFACC = 1141,
     INPUT_NO_WRAP = 1142,
     LOCKMODEPAGE = 1143,
     SETPMOFF = 1144,
     UNCONSTRAINED = 1145,
     PAGE_TRAILER = 1146,
     SETPMON = 1147,
     BEFGROUP = 1148,
     CLOSE_WINDOW = 1149,
     COMMENT_LINE = 1150,
     CONTINUE_FOR = 1151,
     CREATE_DB = 1152,
     CREATE_TABLE = 1153,
     DEFAULT_NULL = 1154,
     DELETE_USING = 1155,
     DISPLAY_FORM = 1156,
     END_FUNCTION = 1157,
     EXIT_DISPLAY = 1158,
     EXIT_FOREACH = 1159,
     EXIT_PROGRAM = 1160,
     INFCOLS = 1161,
     LOCKMODEROW = 1162,
     ON_EVERY_ROW = 1163,
     OPEN_SESSION = 1164,
     RIGHT_MARGIN = 1165,
     SELECT_USING = 1166,
     START_REPORT = 1167,
     UNLOCK_TABLE = 1168,
     UPDATE_USING = 1169,
     ACL_BUILTIN = 1170,
     AFTGROUP = 1171,
     INFIDX = 1172,
     INFSTAT = 1173,
     LEFT_MARGIN = 1174,
     PAGE_HEADER = 1175,
     ROLLBACK_W = 1176,
     SET_SESSION = 1177,
     SQLSEOFF = 1178,
     WITH_A_LOG = 1179,
     BEFDISP = 1180,
     BEFORE_MENU = 1181,
     CREATE_VIEW = 1182,
     DEFINE_TYPE = 1183,
     DELETE_FROM = 1184,
     END_DISPLAY = 1185,
     END_REPORT = 1186,
     END_FOREACH = 1187,
     END_FOR = 1188,
     END_GLOBALS = 1189,
     EXIT_PROMPT = 1190,
     EXTENT_SIZE = 1191,
     FOREIGN_KEY = 1192,
     HIDE_OPTION = 1193,
     HIDE_WINDOW = 1194,
     INSERT_INTO = 1195,
     IS_NOT_NULL = 1196,
     MOVE_WINDOW = 1197,
     NEXT_OPTION = 1198,
     NOT_MATCHES = 1199,
     ON_LAST_ROW = 1200,
     OPEN_WINDOW = 1201,
     OPEN_STATUSBOX = 1202,
     PAGE_LENGTH = 1203,
     PAGE_WIDTH = 1204,
     PRIMARY_KEY = 1205,
     PROMPT_LINE = 1206,
     RECORD_LIKE = 1207,
     ROLLFORWARD = 1208,
     SETBL = 1209,
     SHOW_OPTION = 1210,
     SHOW_WINDOW = 1211,
     SQLSEON = 1212,
     TO_DATABASE = 1213,
     USE_SESSION = 1214,
     WITH_NO_LOG = 1215,
     AFTDISP = 1216,
     BEFFIELD = 1217,
     INSHARE = 1218,
     UNLOCKTAB = 1219,
     AFTFIELD = 1220,
     ATTRIBUTES = 1221,
     BEFINP = 1222,
     BEGIN_WORK = 1223,
     CLEARWIN = 1224,
     CLOSE_FORM = 1225,
     DEFER_QUIT = 1226,
     DESCENDING = 1227,
     DROP_INDEX = 1228,
     END_PROMPT = 1229,
     END_RECORD = 1230,
     ERROR_LINE = 1231,
     EXIT_INPUT = 1232,
     EXIT_WHILE = 1233,
     FOR_UPDATE_OF = 1234,
     FOR_UPDATE = 1235,
     GET_FLDBUF = 1236,
     INITIALIZE = 1237,
     INPUT_WRAP = 1238,
     LOCK_TABLE = 1239,
     MSG_LINE = 1240,
     NOT_EXISTS = 1241,
     ON_ANY_KEY = 1242,
     REFERENCES = 1243,
     RENCOL = 1244,
     SET_CURSOR = 1245,
     SMALLFLOAT = 1246,
     SQLSUCCESS = 1247,
     TOP_MARGIN = 1248,
     WITH_ARRAY = 1249,
     ACCEPTKEY = 1250,
     ACCEPT = 1251,
     AFTINP = 1252,
     CLEARFORMTODEFAULTS = 1253,
     CLEARFORM = 1254,
     CLEAR_X_FORM = 1255,
     COMMIT_W = 1256,
     NEXTPAGE = 1257,
     PREVPAGE = 1258,
     CTRL_KEY = 1259,
     INFTABS = 1260,
     NEXTFIELD = 1261,
     NEXTFORM = 1262,
     RENTAB = 1263,
     ASCENDING = 1264,
     ASSOCIATE = 1265,
     CHARACTER = 1266,
     CONSTRUCT = 1267,
     DELIMITER = 1268,
     DOWNSHIFT = 1269,
     DROP_VIEW = 1270,
     END_INPUT = 1271,
     END_WHILE = 1272,
     EXCLUSIVE = 1273,
     EXIT_CASE = 1274,
     EXIT_MENU = 1275,
     FORM_LINE = 1276,
     INTERRUPT = 1278,
     INTO_TEMP = 1279,
     INVISIBLE = 1280,
     IN_MEMORY = 1281,
     LINKED_TO = 1282,
     LOAD_FROM = 1283,
     LOCKTAB = 1284,
     MENU_LINE = 1285,
     OPEN_FORM = 1286,
     OTHERWISE = 1287,
     PRECISION = 1288,
     PRIOR = 1289,
     PROCEDURE = 1290,
     REPORT_TO = 1291,
     RETURNING = 1292,
     UNDERLINE = 1293,
     UNLOAD_TO = 1294,
     BEFROW = 1295,
     UNLOAD_T = 1296,
     VARIABLE = 1297,
     ABSOLUTE = 1298,
     AFTROW = 1299,
     BUFFERED = 1300,
     CONSTANT = 1301,
     CONST = 1302,
     CONTINUE = 1303,
     DATABASE = 1304,
     DATETIME = 1305,
     DEFAULTS = 1306,
     DISTINCT = 1307,
     END_CASE = 1308,
     END_MAIN = 1309,
     END_MENU = 1310,
     END_TYPE = 1311,
     EXIT_FOR = 1312,
     EXTERNAL = 1313,
     FRACTION = 1314,
     FUNCTION = 1315,
     GROUP_BY = 1316,
     INTERVAL = 1317,
     KWMESSAGE = 1318,
     NOT_LIKE = 1319,
     NOT_NULL = 1320,
     PASSWORD = 1321,
     PREVIOUS = 1322,
     READONLY = 1323,
     REGISTER = 1324,
     RELATIVE = 1325,
     RESOURCE = 1326,
     SMALLINT = 1327,
     VALIDATE = 1328,
     WHENEVER = 1329,
     WITH_LOG = 1330,
     WORDWRAP = 1331,
     BY_NAME = 1332,
     IN_FILE = 1333,
     IS_NULL = 1334,
     AVERAGE = 1336,
     BETWEEN = 1337,
     CAPTION = 1338,
     CLIPPED = 1339,
     CLOSE_BRACKET = 1340,
     COLUMNS = 1341,
     COMMENT = 1343,
     CONNECT = 1344,
     CURRENT = 1345,
     DBYNAME = 1346,
     DECIMAL = 1347,
     DECLARE = 1348,
     DEFAULT = 1349,
     DISPLAY = 1350,
     ENDCODE = 1351,
     EXECUTE = 1352,
     FOREACH = 1353,
     FOREIGN = 1354,
     GLOBALS = 1355,
     INFIELD = 1356,
     INTEGER = 1357,
     KWWINDOW = 1358,
     MAGENTA = 1359,
     NUMERIC = 1361,
     OPTIONS = 1362,
     PERCENT = 1363,
     PREPARE = 1364,
     PROGRAM = 1365,
     RECOVER = 1366,
     REVERSE = 1367,
     SECTION = 1368,
     SESSION = 1369,
     SYNONYM = 1370,
     THRU = 1371,
     TRAILER = 1372,
     UPSHIFT = 1373,
     VARCHAR = 1374,
     WAITING = 1375,
     CLOSE_SHEV = 1376,
     CLOSE_SQUARE = 1377,
     KW_FALSE = 1379,
     NOT_IN = 1380,
     ONKEY = 1381,
     OPEN_BRACKET = 1382,
     BORDER = 1383,
     BOTTOM = 1384,
     COLUMN = 1385,
     COMMIT = 1386,
     CREATE = 1387,
     CURSOR = 1388,
     DEFINE = 1389,
     DELETE = 1390,
     DOUBLE = 1391,
     END_IF = 1392,
     ESCAPE = 1393,
     EXISTS = 1394,
     EXTEND = 1395,
     EXTENT = 1396,
     FINISH = 1397,
     FORMAT = 1398,
     HAVING = 1399,
     HEADER = 1400,
     INSERT = 1401,
     LOCATE = 1402,
     MARGIN = 1403,
     MEMORY = 1404,
     MINUTE = 1405,
     MODIFY = 1406,
     NORMAL = 1407,
     EQUAL_EQUAL = 1408,
     OPEN_SHEV = 1410,
     OPEN_SQUARE = 1411,
     OPTION = 1412,
     OUTPUT = 1413,
     PROMPT = 1414,
     PUBLIC = 1415,
     RECORD = 1416,
     REPORT = 1417,
     RETURN = 1418,
     REVOKE = 1419,
     SCHEMA = 1420,
     SCROLL_USING = 1421,
     SCROLL = 1422,
     SECOND = 1423,
     SELECT = 1424,
     SERIAL = 1425,
     SETL = 1426,
     SHARED = 1427,
     SPACES = 1428,
     UNIQUE = 1429,
     UNLOCK = 1430,
     UPDATE = 1431,
     VALUES = 1432,
     YELLOW = 1433,
     AFTER = 1434,
     KWLINE = 1435,
     KW_NULL = 1436,
     KW_TRUE = 1437,
     SINGLE_KEY = 1438,
     ALTER = 1439,
     ARRAY = 1440,
     ASCII = 1441,
     AUDIT = 1442,
     BLACK = 1443,
     BLINK = 1444,
     CHECK = 1445,
     CLEAR = 1446,
     CLOSE = 1447,
     CODE_C = 1448,
     COUNT = 1449,
     DEFER = 1450,
     ERROR = 1451,
     EVERY = 1452,
     FETCH = 1453,
     FIRST = 1454,
     FLOAT = 1455,
     FLUSH = 1456,
     FOUND = 1457,
     GRANT = 1458,
     GREEN = 1459,
     GROUP = 1460,
     INDEX = 1461,
     KWFORM = 1462,
     LABEL = 1463,
     LOCAL = 1465,
     MONEY = 1466,
     MONTH = 1467,
     ORDER = 1470,
     OUTER = 1471,
     PAUSE = 1472,
     PRINT_IMAGE = 1473,
     PRINT_FILE = 1474,
     PRINT = 1475,
     RIGHT = 1476,
     DOUBLE_COLON = 1477,
     SEMICOLON = 1478,
     SLEEP = 1479,
     TUPLE = 1480,
     UNION = 1481,
     WHERE = 1483,
     WHILE = 1484,
     WHITE = 1485,
     CCODE = 1486,
     ANSI = 1487,
     BLUE = 1488,
     BOLD = 1489,
     BYTE = 1490,
     FCALL = 1491,
     CASE = 1492,
     CHAR = 1493,
     CYAN = 1494,
     DATE = 1495,
     DESC = 1496,
     DOWN = 1498,
     TAB = 1499,
     DROP = 1500,
     ELSE = 1501,
     EXEC = 1502,
     EXIT = 1503,
     FREE = 1504,
     FROM = 1505,
     GOTO = 1506,
     HELP_FILE = 1507,
     LANG_FILE = 1508,
     HELP = 1509,
     HIDE = 1510,
     HOUR = 1511,
     INTO = 1512,
     LAST = 1513,
     LEFT = 1514,
     LIKE = 1515,
     MAIN = 1516,
     MENU = 1517,
     MODE = 1518,
     NEED = 1519,
     NEXT = 1520,
     NOCR = 1521,
     OPEN = 1522,
     QUIT = 1523,
     REAL = 1524,
     ROWS = 1525,
     SHOW = 1526,
     SIZE = 1527,
     SKIP = 1528,
     SOME = 1529,
     STEP = 1530,
     STOP = 1531,
     TEMP = 1532,
     TEXT = 1533,
     THEN = 1534,
     USER = 1535,
     WAIT = 1536,
     WHEN = 1537,
     WITH = 1538,
     WORK = 1539,
     YEAR = 1540,
     KW_IS = 1542,
     XSET = 1543,
     ADD = 1544,
     ALL = 1545,
     ANY = 1547,
     ASC = 1548,
     AVG = 1549,
     COLON = 1550,
     DAY = 1552,
     DBA = 1553,
     DEC = 1554,
     DIM = 1555,
     FKEY = 1556,
     FOR = 1557,
     KEY = 1558,
     KWNO = 1559,
     LET = 1560,
     LOG = 1561,
     XMAX = 1562,
     XMIN = 1563,
     NOT = 1566,
     PAD = 1567,
     PUT = 1568,
     RED = 1569,
     ROW = 1570,
     RUN = 1571,
     SQL = 1572,
     SUM = 1573,
     TOP = 1574,
     USE = 1575,
     ATSIGN = 1576,
     AS_TIFF = 1578,
     AS_GIF = 1579,
     AS_PNG = 1580,
     AS_JPEG = 1581,
     AS = 1582,
     AT = 1583,
     BY = 1584,
     DOT = 1585,
     GO = 1586,
     IF = 1587,
     IN = 1588,
     OF = 1589,
     ON = 1590,
     TO = 1592,
     UP = 1593,
     FONT_NAME = 1594,
     FONT_SIZE = 1595,
     PAPER_SIZE_IS_LETTER = 1596,
     PAPER_SIZE_IS_LEGAL = 1597,
     PAPER_SIZE_IS_A5 = 1598,
     PAPER_SIZE_IS_A4 = 1599,
     PAPER_SIZE_IS_LETTER_L = 1600,
     PAPER_SIZE_IS_LEGAL_L = 1601,
     PAPER_SIZE_IS_A5_L = 1602,
     PAPER_SIZE_IS_A4_L = 1603,
     FORMHANDLER = 1604,
     END_FORMHANDLER = 1605,
     BEFORE_EVENT = 1606,
     BEFORE_OPEN_FORM = 1607,
     AFTER_EVENT = 1608,
     BEFORE_CLOSE_FORM = 1609,
     BEFORE_ANY = 1610,
     AFTER_ANY = 1611,
     MENUHANDLER = 1612,
     END_MENUHANDLER = 1613,
     BEFORE_SHOW_MENU = 1614,
     DISABLE_PROGRAM = 1615,
     DISABLE_ALL = 1616,
     BUTTONS = 1617,
     CHECK_MENUITEM = 1618,
     DISABLE_FORM = 1619,
     DISABLE_MENUITEMS = 1620,
     DISABLE = 1621,
     ENABLE_FORM = 1622,
     ENABLE_MENUITEMS = 1623,
     ENABLE = 1624,
     KWFIELD = 1625,
     ICON = 1626,
     MESSAGEBOX = 1627,
     TO_DEFAULTS = 1628,
     UNCHECK_MENUITEM = 1629,
     BEFORE = 1630,
     INPUT = 1631,
     END = 1632,
     INT_TO_ID = 1633
   };
#endif
#define NAME 1635
#define UMINUS 1636
#define COMMA 1551
#define KW_OR 1591
#define KW_AND 1546
#define KW_USING 1482
#define MATCHES 1360
#define POWER 1468
#define LESS_THAN 1464
#define GREATER_THAN 1378
#define EQUAL 1541
#define GREATER_THAN_EQ 1277
#define LESS_THAN_EQ 1335
#define NOT_EQUAL 1409
#define PLUS 1577
#define MINUS 1564
#define DIVIDE 1497
#define MULTIPLY 1469
#define MOD 1565
#define COMMAND 1342
#define NUMBER_VALUE 1637
#define CHAR_VALUE 1638
#define INT_VALUE 1639
#define NAMED_GEN 1640
#define CLINE 1641
#define SQLLINE 1642
#define KW_CSTART 1643
#define KW_CEND 1644
#define USER_DTYPE 1645
#define SQL_TEXT 1646
#define ALTER_TABLE 1000
#define NEWFORMATSHARED 1001
#define CREATE_DATABASE 1002
#define IMPORT_LEGACY_FUNCTION 1003
#define ADD_CONSTRAINT 1004
#define DROP_CONSTRAINT 1005
#define AS_STATIC 1006
#define NOT_FIELD_TOUCHED 1007
#define LOCAL_FUNCTION 1008
#define EVERY_ROW 1009
#define ELIF 1010
#define DOUBLE_PRECISION 1011
#define COUNT_MULTIPLY 1012
#define WAIT_FOR_KEY 1013
#define AT_TERMINATION_CALL 1014
#define TO_MAIN_CAPTION 1015
#define CLEARSTAT 1016
#define TO_MENUITEM 1017
#define ID_TO_INT 1018
#define TO_STATUSBOX 1019
#define ASCII_HEIGHT_ALL 1020
#define ASCII_WIDTH_ALL 1021
#define IMPORT_DATATYPE 1022
#define UP_BY 1023
#define PAGE_TRAILER_SIZE 1024
#define PAGE_HEADER_SIZE 1025
#define FIRST_PAGE_HEADER_SIZE 1026
#define BYTES_USE_AS_IMAGE 1027
#define BYTES_USE_AS_ASCII 1028
#define DOWN_BY 1029
#define CLOSE_STATUSBOX 1030
#define MODIFY_NEXT_SIZE 1031
#define LOCK_MODE_PAGE 1032
#define LOCK_MODE_ROW 1033
#define TO_PIPE 1034
#define TO_PRINTER 1035
#define STATUSBOX 1036
#define CONNECT_TO 1037
#define FORMHANDLER_INPUT 1038
#define UNITS_YEAR 1039
#define UNITS_MONTH 1040
#define UNITS_DAY 1041
#define UNITS_HOUR 1042
#define UNITS_MINUTE 1043
#define UNITS_SECOND 1044
#define NO_NEW_LINES 1045
#define FIELDTOWIDGET 1046
#define WITH_HOLD 1047
#define SHOW_MENU 1048
#define CWIS 1049
#define CREATE_IDX 1050
#define FORM_IS_COMPILED 1051
#define PDF_REPORT 1052
#define IMPORT_FUNCTION 1053
#define PROMPT_MANY 1054
#define POINTS 1055
#define MM 1056
#define INCHES 1057
#define PREPEND 1058
#define MEMBER_OF 1059
#define MEMBER_FUNCTION 1060
#define APPEND 1061
#define TEMPLATE 1062
#define END_TEMPLATE 1063
#define SQLSICS 1064
#define CREATE_SCHEMA 1065
#define SQLSIRR 1066
#define UPDATESTATS_T 1067
#define SQLSICR 1068
#define WHENEVER_SQLSUCCESS 1069
#define WHENEVER_SQLWARNING 1070
#define START_EXTERN 1071
#define WHENEVER_ANY_ERROR 1072
#define WHENEVER_NOT_FOUND 1073
#define CONTINUE_CONSTRUCT 1074
#define FOUNCONSTR 1075
#define SQLSIDR 1076
#define WHENEVER_SQLERROR 1077
#define CREATE_TEMP_TABLE 1078
#define CURRENT_WINDOW_IS 1079
#define FIRST_PAGE_HEADER 1080
#define ORDER_EXTERNAL_BY 1081
#define SCROLL_CURSOR_FOR 1082
#define SCROLL_CURSOR 1083
#define SQL_INTERRUPT_OFF 1084
#define STOP_ALL_EXTERNAL 1085
#define WITH_CHECK_OPTION 1086
#define WITH_GRANT_OPTION 1087
#define SQLSLMNW 1088
#define ADDCONSTUNIQ 1089
#define CONTINUE_DISPLAY 1090
#define CONTINUE_FOREACH 1091
#define OUTPUT_TO_REPORT 1092
#define SQL_INTERRUPT_ON 1093
#define WHENEVER_SUCCESS 1094
#define WHENEVER_WARNING 1095
#define WHERE_CURRENT_OF 1096
#define WITHOUT_DEFAULTS 1097
#define FOCONSTR 1098
#define SCALED_BY 1099
#define CONTINUE_PROMPT 1100
#define PDF_FUNCTION 1101
#define DEFER_INTERRUPT 1102
#define DISPLAY_BY_NAME 1103
#define NOT_NULL_UNIQUE 1104
#define SKIP_TO_TOP 1105
#define TOP_OF_PAGE 1106
#define SKIP_TO 1107
#define SKIP_BY 1108
#define WITHOUT_WAITING 1109
#define BEFCONSTRUCT 1110
#define SQLSLMW 1111
#define WHENEVER_ERROR_CONTINUE 1112
#define WHENEVER_ERROR 1113
#define AFTCONSTRUCT 1114
#define ALL_PRIVILEGES 1115
#define CLOSE_DATABASE 1116
#define CONTINUE_INPUT 1117
#define CONTINUE_WHILE 1118
#define CREATE_SYNONYM 1119
#define DROP_TABLE 1120
#define EXIT_CONSTRUCT 1121
#define INEXCLUSIVE 1122
#define REPORT_TO_PRINTER 1123
#define REPORT_TO_PIPE 1124
#define SET_SESSION_TO 1125
#define UPDATESTATS 1126
#define WITHOUT_HEAD 1127
#define CLEARSCR 1128
#define WITH_B_LOG 1129
#define AUTHORIZATION 1130
#define BOTTOM_MARGIN 1131
#define CLOSE_SESSION 1132
#define CONTINUE_CASE 1133
#define CONTINUE_MENU 1134
#define DISPLAY_ARRAY 1135
#define END_SQL 1136
#define DOLLAR 1137
#define END_CONSTRUCT 1138
#define FIELD_TOUCHED 1139
#define FINISH_REPORT 1140
#define INFACC 1141
#define INPUT_NO_WRAP 1142
#define LOCKMODEPAGE 1143
#define SETPMOFF 1144
#define UNCONSTRAINED 1145
#define PAGE_TRAILER 1146
#define SETPMON 1147
#define BEFGROUP 1148
#define CLOSE_WINDOW 1149
#define COMMENT_LINE 1150
#define CONTINUE_FOR 1151
#define CREATE_DB 1152
#define CREATE_TABLE 1153
#define DEFAULT_NULL 1154
#define DELETE_USING 1155
#define DISPLAY_FORM 1156
#define END_FUNCTION 1157
#define EXIT_DISPLAY 1158
#define EXIT_FOREACH 1159
#define EXIT_PROGRAM 1160
#define INFCOLS 1161
#define LOCKMODEROW 1162
#define ON_EVERY_ROW 1163
#define OPEN_SESSION 1164
#define RIGHT_MARGIN 1165
#define SELECT_USING 1166
#define START_REPORT 1167
#define UNLOCK_TABLE 1168
#define UPDATE_USING 1169
#define ACL_BUILTIN 1170
#define AFTGROUP 1171
#define INFIDX 1172
#define INFSTAT 1173
#define LEFT_MARGIN 1174
#define PAGE_HEADER 1175
#define ROLLBACK_W 1176
#define SET_SESSION 1177
#define SQLSEOFF 1178
#define WITH_A_LOG 1179
#define BEFDISP 1180
#define BEFORE_MENU 1181
#define CREATE_VIEW 1182
#define DEFINE_TYPE 1183
#define DELETE_FROM 1184
#define END_DISPLAY 1185
#define END_REPORT 1186
#define END_FOREACH 1187
#define END_FOR 1188
#define END_GLOBALS 1189
#define EXIT_PROMPT 1190
#define EXTENT_SIZE 1191
#define FOREIGN_KEY 1192
#define HIDE_OPTION 1193
#define HIDE_WINDOW 1194
#define INSERT_INTO 1195
#define IS_NOT_NULL 1196
#define MOVE_WINDOW 1197
#define NEXT_OPTION 1198
#define NOT_MATCHES 1199
#define ON_LAST_ROW 1200
#define OPEN_WINDOW 1201
#define OPEN_STATUSBOX 1202
#define PAGE_LENGTH 1203
#define PAGE_WIDTH 1204
#define PRIMARY_KEY 1205
#define PROMPT_LINE 1206
#define RECORD_LIKE 1207
#define ROLLFORWARD 1208
#define SETBL 1209
#define SHOW_OPTION 1210
#define SHOW_WINDOW 1211
#define SQLSEON 1212
#define TO_DATABASE 1213
#define USE_SESSION 1214
#define WITH_NO_LOG 1215
#define AFTDISP 1216
#define BEFFIELD 1217
#define INSHARE 1218
#define UNLOCKTAB 1219
#define AFTFIELD 1220
#define ATTRIBUTES 1221
#define BEFINP 1222
#define BEGIN_WORK 1223
#define CLEARWIN 1224
#define CLOSE_FORM 1225
#define DEFER_QUIT 1226
#define DESCENDING 1227
#define DROP_INDEX 1228
#define END_PROMPT 1229
#define END_RECORD 1230
#define ERROR_LINE 1231
#define EXIT_INPUT 1232
#define EXIT_WHILE 1233
#define FOR_UPDATE_OF 1234
#define FOR_UPDATE 1235
#define GET_FLDBUF 1236
#define INITIALIZE 1237
#define INPUT_WRAP 1238
#define LOCK_TABLE 1239
#define MSG_LINE 1240
#define NOT_EXISTS 1241
#define ON_ANY_KEY 1242
#define REFERENCES 1243
#define RENCOL 1244
#define SET_CURSOR 1245
#define SMALLFLOAT 1246
#define SQLSUCCESS 1247
#define TOP_MARGIN 1248
#define WITH_ARRAY 1249
#define ACCEPTKEY 1250
#define ACCEPT 1251
#define AFTINP 1252
#define CLEARFORMTODEFAULTS 1253
#define CLEARFORM 1254
#define CLEAR_X_FORM 1255
#define COMMIT_W 1256
#define NEXTPAGE 1257
#define PREVPAGE 1258
#define CTRL_KEY 1259
#define INFTABS 1260
#define NEXTFIELD 1261
#define NEXTFORM 1262
#define RENTAB 1263
#define ASCENDING 1264
#define ASSOCIATE 1265
#define CHARACTER 1266
#define CONSTRUCT 1267
#define DELIMITER 1268
#define DOWNSHIFT 1269
#define DROP_VIEW 1270
#define END_INPUT 1271
#define END_WHILE 1272
#define EXCLUSIVE 1273
#define EXIT_CASE 1274
#define EXIT_MENU 1275
#define FORM_LINE 1276
#define INTERRUPT 1278
#define INTO_TEMP 1279
#define INVISIBLE 1280
#define IN_MEMORY 1281
#define LINKED_TO 1282
#define LOAD_FROM 1283
#define LOCKTAB 1284
#define MENU_LINE 1285
#define OPEN_FORM 1286
#define OTHERWISE 1287
#define PRECISION 1288
#define PRIOR 1289
#define PROCEDURE 1290
#define REPORT_TO 1291
#define RETURNING 1292
#define UNDERLINE 1293
#define UNLOAD_TO 1294
#define BEFROW 1295
#define UNLOAD_T 1296
#define VARIABLE 1297
#define ABSOLUTE 1298
#define AFTROW 1299
#define BUFFERED 1300
#define CONSTANT 1301
#define CONST 1302
#define CONTINUE 1303
#define DATABASE 1304
#define DATETIME 1305
#define DEFAULTS 1306
#define DISTINCT 1307
#define END_CASE 1308
#define END_MAIN 1309
#define END_MENU 1310
#define END_TYPE 1311
#define EXIT_FOR 1312
#define EXTERNAL 1313
#define FRACTION 1314
#define FUNCTION 1315
#define GROUP_BY 1316
#define INTERVAL 1317
#define KWMESSAGE 1318
#define NOT_LIKE 1319
#define NOT_NULL 1320
#define PASSWORD 1321
#define PREVIOUS 1322
#define READONLY 1323
#define REGISTER 1324
#define RELATIVE 1325
#define RESOURCE 1326
#define SMALLINT 1327
#define VALIDATE 1328
#define WHENEVER 1329
#define WITH_LOG 1330
#define WORDWRAP 1331
#define BY_NAME 1332
#define IN_FILE 1333
#define IS_NULL 1334
#define AVERAGE 1336
#define BETWEEN 1337
#define CAPTION 1338
#define CLIPPED 1339
#define CLOSE_BRACKET 1340
#define COLUMNS 1341
#define COMMENT 1343
#define CONNECT 1344
#define CURRENT 1345
#define DBYNAME 1346
#define DECIMAL 1347
#define DECLARE 1348
#define DEFAULT 1349
#define DISPLAY 1350
#define ENDCODE 1351
#define EXECUTE 1352
#define FOREACH 1353
#define FOREIGN 1354
#define GLOBALS 1355
#define INFIELD 1356
#define INTEGER 1357
#define KWWINDOW 1358
#define MAGENTA 1359
#define NUMERIC 1361
#define OPTIONS 1362
#define PERCENT 1363
#define PREPARE 1364
#define PROGRAM 1365
#define RECOVER 1366
#define REVERSE 1367
#define SECTION 1368
#define SESSION 1369
#define SYNONYM 1370
#define THRU 1371
#define TRAILER 1372
#define UPSHIFT 1373
#define VARCHAR 1374
#define WAITING 1375
#define CLOSE_SHEV 1376
#define CLOSE_SQUARE 1377
#define KW_FALSE 1379
#define NOT_IN 1380
#define ONKEY 1381
#define OPEN_BRACKET 1382
#define BORDER 1383
#define BOTTOM 1384
#define COLUMN 1385
#define COMMIT 1386
#define CREATE 1387
#define CURSOR 1388
#define DEFINE 1389
#define DELETE 1390
#define DOUBLE 1391
#define END_IF 1392
#define ESCAPE 1393
#define EXISTS 1394
#define EXTEND 1395
#define EXTENT 1396
#define FINISH 1397
#define FORMAT 1398
#define HAVING 1399
#define HEADER 1400
#define INSERT 1401
#define LOCATE 1402
#define MARGIN 1403
#define MEMORY 1404
#define MINUTE 1405
#define MODIFY 1406
#define NORMAL 1407
#define EQUAL_EQUAL 1408
#define OPEN_SHEV 1410
#define OPEN_SQUARE 1411
#define OPTION 1412
#define OUTPUT 1413
#define PROMPT 1414
#define PUBLIC 1415
#define RECORD 1416
#define REPORT 1417
#define RETURN 1418
#define REVOKE 1419
#define SCHEMA 1420
#define SCROLL_USING 1421
#define SCROLL 1422
#define SECOND 1423
#define SELECT 1424
#define SERIAL 1425
#define SETL 1426
#define SHARED 1427
#define SPACES 1428
#define UNIQUE 1429
#define UNLOCK 1430
#define UPDATE 1431
#define VALUES 1432
#define YELLOW 1433
#define AFTER 1434
#define KWLINE 1435
#define KW_NULL 1436
#define KW_TRUE 1437
#define SINGLE_KEY 1438
#define ALTER 1439
#define ARRAY 1440
#define ASCII 1441
#define AUDIT 1442
#define BLACK 1443
#define BLINK 1444
#define CHECK 1445
#define CLEAR 1446
#define CLOSE 1447
#define CODE_C 1448
#define COUNT 1449
#define DEFER 1450
#define ERROR 1451
#define EVERY 1452
#define FETCH 1453
#define FIRST 1454
#define FLOAT 1455
#define FLUSH 1456
#define FOUND 1457
#define GRANT 1458
#define GREEN 1459
#define GROUP 1460
#define INDEX 1461
#define KWFORM 1462
#define LABEL 1463
#define LOCAL 1465
#define MONEY 1466
#define MONTH 1467
#define ORDER 1470
#define OUTER 1471
#define PAUSE 1472
#define PRINT_IMAGE 1473
#define PRINT_FILE 1474
#define PRINT 1475
#define RIGHT 1476
#define DOUBLE_COLON 1477
#define SEMICOLON 1478
#define SLEEP 1479
#define TUPLE 1480
#define UNION 1481
#define WHERE 1483
#define WHILE 1484
#define WHITE 1485
#define CCODE 1486
#define ANSI 1487
#define BLUE 1488
#define BOLD 1489
#define BYTE 1490
#define FCALL 1491
#define CASE 1492
#define CHAR 1493
#define CYAN 1494
#define DATE 1495
#define DESC 1496
#define DOWN 1498
#define TAB 1499
#define DROP 1500
#define ELSE 1501
#define EXEC 1502
#define EXIT 1503
#define FREE 1504
#define FROM 1505
#define GOTO 1506
#define HELP_FILE 1507
#define LANG_FILE 1508
#define HELP 1509
#define HIDE 1510
#define HOUR 1511
#define INTO 1512
#define LAST 1513
#define LEFT 1514
#define LIKE 1515
#define MAIN 1516
#define MENU 1517
#define MODE 1518
#define NEED 1519
#define NEXT 1520
#define NOCR 1521
#define OPEN 1522
#define QUIT 1523
#define REAL 1524
#define ROWS 1525
#define SHOW 1526
#define SIZE 1527
#define SKIP 1528
#define SOME 1529
#define STEP 1530
#define STOP 1531
#define TEMP 1532
#define TEXT 1533
#define THEN 1534
#define USER 1535
#define WAIT 1536
#define WHEN 1537
#define WITH 1538
#define WORK 1539
#define YEAR 1540
#define KW_IS 1542
#define XSET 1543
#define ADD 1544
#define ALL 1545
#define ANY 1547
#define ASC 1548
#define AVG 1549
#define COLON 1550
#define DAY 1552
#define DBA 1553
#define DEC 1554
#define DIM 1555
#define FKEY 1556
#define FOR 1557
#define KEY 1558
#define KWNO 1559
#define LET 1560
#define LOG 1561
#define XMAX 1562
#define XMIN 1563
#define NOT 1566
#define PAD 1567
#define PUT 1568
#define RED 1569
#define ROW 1570
#define RUN 1571
#define SQL 1572
#define SUM 1573
#define TOP 1574
#define USE 1575
#define ATSIGN 1576
#define AS_TIFF 1578
#define AS_GIF 1579
#define AS_PNG 1580
#define AS_JPEG 1581
#define AS 1582
#define AT 1583
#define BY 1584
#define DOT 1585
#define GO 1586
#define IF 1587
#define IN 1588
#define OF 1589
#define ON 1590
#define TO 1592
#define UP 1593
#define FONT_NAME 1594
#define FONT_SIZE 1595
#define PAPER_SIZE_IS_LETTER 1596
#define PAPER_SIZE_IS_LEGAL 1597
#define PAPER_SIZE_IS_A5 1598
#define PAPER_SIZE_IS_A4 1599
#define PAPER_SIZE_IS_LETTER_L 1600
#define PAPER_SIZE_IS_LEGAL_L 1601
#define PAPER_SIZE_IS_A5_L 1602
#define PAPER_SIZE_IS_A4_L 1603
#define FORMHANDLER 1604
#define END_FORMHANDLER 1605
#define BEFORE_EVENT 1606
#define BEFORE_OPEN_FORM 1607
#define AFTER_EVENT 1608
#define BEFORE_CLOSE_FORM 1609
#define BEFORE_ANY 1610
#define AFTER_ANY 1611
#define MENUHANDLER 1612
#define END_MENUHANDLER 1613
#define BEFORE_SHOW_MENU 1614
#define DISABLE_PROGRAM 1615
#define DISABLE_ALL 1616
#define BUTTONS 1617
#define CHECK_MENUITEM 1618
#define DISABLE_FORM 1619
#define DISABLE_MENUITEMS 1620
#define DISABLE 1621
#define ENABLE_FORM 1622
#define ENABLE_MENUITEMS 1623
#define ENABLE 1624
#define KWFIELD 1625
#define ICON 1626
#define MESSAGEBOX 1627
#define TO_DEFAULTS 1628
#define UNCHECK_MENUITEM 1629
#define BEFORE 1630
#define INPUT 1631
#define END 1632
#define INT_TO_ID 1633




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
#line 1514 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1526 "y.tab.c"

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
#define YYLAST   8839

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  649
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  820
/* YYNRULES -- Number of rules. */
#define YYNRULES  1892
/* YYNRULES -- Number of states. */
#define YYNSTATES  3105

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   1646

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
     303,   304,   305,   306,   307,   308,   309,    14,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,    15,   367,   368,   369,   370,
     371,   372,    22,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
       9,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,    12,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,    16,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,    11,   491,   492,   493,    10,    20,
     494,   495,   496,   497,   498,   499,   500,   501,   502,   503,
     504,   505,     8,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,    19,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,    13,   563,   564,   565,   566,     7,   567,   568,   569,
     570,     5,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,    18,    21,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   593,    17,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,     6,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   646,   647,   648,     2,     3,     4,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32
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
    1052,  1057,  1063,  1065,  1067,  1069,  1071,  1073,  1075,  1077,
    1079,  1081,  1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,
    1099,  1102,  1104,  1106,  1108,  1110,  1113,  1115,  1117,  1119,
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
    1568,  1580,  1581,  1584,  1585,  1586,  1587,  1596,  1597,  1598,
    1609,  1610,  1612,  1613,  1615,  1617,  1620,  1621,  1625,  1626,
    1630,  1631,  1633,  1635,  1638,  1639,  1643,  1644,  1648,  1652,
    1654,  1659,  1663,  1665,  1669,  1671,  1675,  1677,  1681,  1683,
    1686,  1687,  1691,  1692,  1696,  1697,  1702,  1703,  1708,  1709,
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
    2064,  2067,  2068,  2074,  2079,  2081,  2085,  2089,  2093,  2094,
    2097,  2098,  2100,  2102,  2105,  2106,  2111,  2112,  2117,  2118,
    2122,  2123,  2127,  2128,  2132,  2133,  2137,  2138,  2142,  2143,
    2148,  2149,  2154,  2156,  2160,  2162,  2164,  2166,  2170,  2172,
    2174,  2176,  2180,  2182,  2186,  2189,  2194,  2196,  2198,  2200,
    2201,  2206,  2212,  2219,  2220,  2231,  2235,  2237,  2239,  2242,
    2245,  2246,  2249,  2250,  2254,  2256,  2257,  2261,  2264,  2265,
    2269,  2271,  2275,  2277,  2281,  2282,  2285,  2287,  2289,  2291,
    2293,  2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,
    2313,  2315,  2317,  2319,  2321,  2322,  2323,  2331,  2333,  2335,
    2338,  2341,  2344,  2348,  2353,  2354,  2358,  2359,  2361,  2363,
    2366,  2368,  2370,  2372,  2374,  2375,  2377,  2379,  2382,  2385,
    2387,  2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,
    2407,  2409,  2411,  2412,  2414,  2416,  2418,  2420,  2422,  2423,
    2424,  2425,  2426,  2440,  2442,  2443,  2444,  2451,  2454,  2456,
    2459,  2462,  2464,  2466,  2469,  2471,  2473,  2475,  2476,  2480,
    2483,  2485,  2486,  2487,  2488,  2503,  2504,  2510,  2512,  2513,
    2517,  2518,  2526,  2527,  2533,  2535,  2538,  2539,  2541,  2543,
    2545,  2546,  2548,  2550,  2553,  2556,  2559,  2561,  2563,  2565,
    2567,  2571,  2573,  2575,  2576,  2577,  2585,  2587,  2590,  2591,
    2595,  2596,  2601,  2604,  2605,  2608,  2610,  2612,  2614,  2616,
    2618,  2620,  2622,  2623,  2627,  2628,  2630,  2632,  2634,  2636,
    2639,  2643,  2646,  2652,  2654,  2656,  2658,  2663,  2668,  2670,
    2672,  2674,  2676,  2679,  2683,  2690,  2692,  2696,  2698,  2700,
    2702,  2707,  2715,  2717,  2719,  2721,  2723,  2726,  2727,  2729,
    2731,  2735,  2737,  2741,  2743,  2747,  2749,  2753,  2755,  2757,
    2759,  2761,  2765,  2767,  2771,  2773,  2777,  2779,  2781,  2783,
    2787,  2790,  2791,  2793,  2795,  2800,  2802,  2806,  2808,  2812,
    2820,  2821,  2829,  2830,  2837,  2841,  2843,  2847,  2849,  2852,
    2858,  2859,  2867,  2868,  2871,  2872,  2874,  2880,  2883,  2889,
    2890,  2896,  2903,  2908,  2909,  2911,  2913,  2918,  2919,  2922,
    2923,  2929,  2934,  2937,  2939,  2943,  2946,  2949,  2952,  2955,
    2958,  2961,  2963,  2966,  2969,  2972,  2975,  2978,  2981,  2984,
    2987,  2990,  2992,  2994,  2996,  2998,  3000,  3002,  3008,  3010,
    3012,  3015,  3020,  3022,  3023,  3034,  3040,  3041,  3043,  3044,
    3047,  3049,  3052,  3053,  3057,  3059,  3060,  3065,  3066,  3069,
    3071,  3075,  3077,  3079,  3083,  3088,  3093,  3096,  3098,  3100,
    3102,  3103,  3105,  3113,  3116,  3119,  3122,  3125,  3127,  3130,
    3131,  3135,  3136,  3140,  3141,  3145,  3146,  3150,  3151,  3155,
    3156,  3161,  3162,  3167,  3169,  3171,  3173,  3175,  3177,  3179,
    3180,  3185,  3186,  3188,  3189,  3194,  3196,  3199,  3202,  3205,
    3206,  3208,  3210,  3213,  3216,  3217,  3220,  3224,  3228,  3234,
    3235,  3238,  3243,  3245,  3247,  3249,  3251,  3253,  3254,  3256,
    3258,  3262,  3265,  3271,  3274,  3280,  3286,  3292,  3298,  3304,
    3310,  3311,  3314,  3316,  3319,  3322,  3325,  3328,  3331,  3334,
    3336,  3339,  3342,  3345,  3348,  3350,  3353,  3356,  3359,  3362,
    3364,  3366,  3368,  3369,  3372,  3375,  3378,  3381,  3384,  3387,
    3390,  3393,  3396,  3398,  3400,  3402,  3404,  3406,  3408,  3410,
    3412,  3415,  3418,  3421,  3424,  3427,  3429,  3431,  3433,  3434,
    3438,  3441,  3442,  3443,  3444,  3445,  3446,  3447,  3463,  3464,
    3467,  3470,  3471,  3473,  3474,  3475,  3476,  3477,  3478,  3479,
    3495,  3498,  3499,  3500,  3501,  3512,  3513,  3515,  3519,  3523,
    3526,  3531,  3535,  3539,  3543,  3545,  3547,  3549,  3551,  3553,
    3555,  3556,  3557,  3565,  3566,  3567,  3576,  3580,  3583,  3584,
    3586,  3588,  3592,  3595,  3598,  3600,  3602,  3606,  3608,  3610,
    3613,  3615,  3619,  3621,  3625,  3627,  3629,  3631,  3633,  3635,
    3637,  3639,  3642,  3647,  3649,  3653,  3655,  3659,  3662,  3667,
    3669,  3673,  3675,  3678,  3683,  3685,  3689,  3691,  3693,  3695,
    3698,  3701,  3706,  3709,  3714,  3716,  3720,  3722,  3724,  3726,
    3729,  3731,  3733,  3735,  3737,  3739,  3742,  3749,  3756,  3757,
    3759,  3760,  3762,  3765,  3766,  3767,  3775,  3776,  3779,  3782,
    3790,  3792,  3798,  3802,  3804,  3808,  3810,  3814,  3816,  3820,
    3822,  3826,  3828,  3830,  3832,  3833,  3839,  3840,  3846,  3848,
    3849,  3853,  3855,  3859,  3861,  3865,  3867,  3869,  3870,  3871,
    3877,  3880,  3882,  3883,  3884,  3888,  3889,  3890,  3894,  3896,
    3898,  3900,  3902,  3904,  3906,  3909,  3912,  3917,  3921,  3925,
    3927,  3931,  3934,  3936,  3938,  3939,  3941,  3943,  3945,  3947,
    3948,  3950,  3954,  3955,  3959,  3961,  3963,  3965,  3967,  3969,
    3971,  3973,  3975,  3977,  3979,  3981,  3983,  3991,  3992,  3994,
    3996,  3998,  4000,  4004,  4006,  4008,  4010,  4013,  4014,  4018,
    4020,  4024,  4026,  4030,  4032,  4034,  4041,  4042,  4046,  4048,
    4052,  4053,  4055,  4060,  4066,  4069,  4071,  4073,  4078,  4080,
    4084,  4089,  4094,  4096,  4100,  4102,  4104,  4106,  4109,  4111,
    4116,  4117,  4119,  4120,  4122,  4124,  4127,  4129,  4131,  4133,
    4138,  4142,  4144,  4146,  4148,  4151,  4153,  4155,  4158,  4161,
    4163,  4167,  4170,  4173,  4175,  4179,  4181,  4184,  4189,  4191,
    4194,  4196,  4200,  4205,  4206,  4208,  4209,  4211,  4212,  4214,
    4216,  4220,  4222,  4226,  4228,  4231,  4233,  4237,  4240,  4243,
    4244,  4247,  4249,  4251,  4253,  4259,  4263,  4269,  4273,  4275,
    4279,  4281,  4283,  4284,  4286,  4290,  4294,  4298,  4305,  4310,
    4315,  4321,  4323,  4325,  4327,  4329,  4331,  4333,  4335,  4337,
    4339,  4341,  4343,  4344,  4346,  4348,  4350,  4352,  4354,  4356,
    4358,  4363,  4369,  4371,  4377,  4383,  4385,  4387,  4389,  4394,
    4396,  4401,  4403,  4411,  4413,  4415,  4417,  4422,  4429,  4430,
    4433,  4438,  4440,  4442,  4444,  4446,  4448,  4450,  4452,  4456,
    4458,  4460,  4464,  4466,  4467,  4471,  4477,  4479,  4482,  4485,
    4491,  4496,  4498,  4500,  4502,  4504,  4506,  4509,  4512,  4515,
    4518,  4520,  4523,  4526,  4527,  4531,  4532,  4536,  4538,  4540,
    4542,  4544,  4546,  4548,  4550,  4555,  4557,  4559,  4561,  4563,
    4565,  4567,  4569,  4574,  4576,  4578,  4580,  4582,  4584,  4586,
    4588,  4590,  4592,  4594,  4596,  4598,  4600,  4602,  4604,  4606,
    4610,  4611,  4620,  4621,  4631,  4632,  4640,  4641,  4651,  4652,
    4654,  4657,  4659,  4663,  4665,  4669,  4675,  4677,  4679,  4681,
    4683,  4686,  4687,  4688,  4697,  4703,  4705,  4707,  4715,  4716,
    4720,  4722,  4726,  4731,  4733,  4734,  4737,  4743,  4751,  4752,
    4754,  4756,  4758,  4760,  4764,  4766,  4769,  4772,  4774,  4776,
    4778,  4780,  4783,  4788,  4792,  4795,  4799,  4803,  4807,  4809,
    4811,  4813,  4815,  4817,  4819,  4825,  4831,  4837,  4843,  4849,
    4854,  4859,  4863,  4868,  4870,  4874,  4875,  4877,  4883,  4891,
    4897,  4898,  4901,  4903,  4905,  4906,  4910,  4912,  4916,  4918,
    4920,  4922,  4923,  4927,  4929,  4931,  4933,  4935,  4940,  4947,
    4949,  4951,  4954,  4958,  4960,  4962,  4964,  4966,  4968,  4970,
    4972,  4974,  4980,  4986,  4991,  4992,  4997,  4999,  5002,  5004,
    5006,  5008,  5011,  5014,  5016,  5019,  5021,  5023,  5025,  5029,
    5035,  5037,  5039,  5041,  5043,  5047,  5050,  5053,  5056,  5058,
    5061,  5064,  5067,  5070,  5073,  5075,  5079,  5082,  5084,  5087,
    5089,  5092,  5094,  5095,  5096,  5103,  5104,  5107,  5108,  5110,
    5112,  5115,  5118,  5120,  5122,  5127,  5131,  5133,  5137,  5139,
    5142,  5148,  5151,  5154,  5160,  5161,  5164,  5166,  5168,  5171,
    5178,  5185,  5187,  5188,  5190,  5193,  5195,  5198,  5199,  5202,
    5204,  5206,  5208,  5210,  5212,  5214,  5216,  5218,  5220,  5222,
    5224,  5226,  5228,  5230,  5232,  5234,  5236,  5238,  5240,  5242,
    5244,  5246,  5248,  5250,  5252,  5254,  5256,  5258,  5260,  5262,
    5264,  5266,  5268,  5270,  5272,  5274,  5276,  5278,  5280,  5282,
    5284,  5286,  5288,  5290,  5292,  5294,  5296,  5298,  5300,  5302,
    5304,  5306,  5308,  5310,  5312,  5314,  5316,  5318,  5320,  5322,
    5324,  5326,  5328,  5330,  5332,  5334,  5336,  5338,  5340,  5342,
    5344,  5346,  5348,  5350,  5352,  5354,  5356,  5358,  5360,  5362,
    5364,  5366,  5368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1009,     0,    -1,   180,    -1,   177,    -1,   104,   654,   406,
     576,   655,    -1,   118,    -1,  1075,    -1,    25,    -1,   656,
      -1,   655,     5,   656,    -1,   917,    -1,   410,   657,   371,
      -1,   657,   658,   657,    -1,    25,    -1,   659,    25,    -1,
    1075,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
      21,    -1,    17,    -1,    18,    -1,    -1,   661,    -1,    -1,
     254,   410,   662,   663,   371,    -1,   549,   410,    25,     5,
      25,   371,    -1,   664,    -1,   663,     5,   664,    -1,   470,
      -1,   511,    -1,   517,    -1,   486,    -1,   389,    -1,   586,
      -1,   508,    -1,   460,    -1,   396,    -1,   471,    -1,   325,
      -1,   512,    -1,   435,    -1,   312,    -1,   574,    -1,    78,
      -1,    -1,   666,    -1,    -1,   254,   410,   667,   668,   371,
      -1,   669,    -1,   668,     5,   669,    -1,   664,    -1,   411,
      -1,   584,    24,    -1,   183,   904,    -1,   309,   904,    -1,
     264,   904,    -1,   317,   904,    -1,   273,   904,    -1,   239,
     904,    -1,   514,   671,    -1,   850,   324,  1075,    -1,    -1,
     269,   410,  1453,   371,   324,   672,  1093,    -1,    84,   410,
     917,   371,    -1,   386,   410,   909,   371,   324,  1075,    -1,
    1210,    -1,   172,   410,   909,   371,   324,  1075,    -1,    -1,
      -1,  1075,   570,   917,   410,   673,   687,   371,   674,   685,
      -1,    -1,    -1,    -1,   917,   410,   675,   687,   676,   371,
     677,   685,    -1,    -1,    -1,   454,  1416,   604,  1416,   410,
     678,   687,   679,   371,   685,    -1,    -1,    -1,   917,   501,
     917,   410,   680,   687,   681,   371,   685,    -1,    -1,    -1,
      -1,   345,   690,   570,   691,   438,   654,   406,   410,   682,
     687,   683,   371,   684,   686,    -1,    -1,   324,  1093,    -1,
      -1,   324,  1093,    -1,   142,    -1,    -1,   688,    -1,   689,
      -1,   688,     5,   689,    -1,   819,    -1,    24,    -1,   917,
      -1,   917,    -1,   917,   601,   917,    -1,    -1,   515,   826,
     693,   696,   700,   697,    -1,    -1,   515,   694,   695,   698,
     697,    -1,   702,    -1,   695,   702,    -1,   704,    -1,   696,
     704,    -1,   340,    -1,    -1,    -1,   319,   699,  1463,    -1,
      -1,    -1,   319,   701,  1463,    -1,    -1,   559,   826,   703,
    1463,    -1,    -1,   559,   826,   705,  1463,    -1,   258,   914,
      -1,   182,   912,    -1,    63,   912,    -1,   149,    -1,   165,
    1422,    -1,   474,   911,    -1,    29,   708,    30,    -1,   709,
      -1,   711,    -1,   710,    -1,   709,   710,    -1,    28,    -1,
     712,    -1,   711,   712,    -1,    27,    -1,   373,    -1,    -1,
      -1,   300,   715,   717,   716,   718,    -1,   364,  1075,   606,
     719,   960,   987,   660,    -1,  1075,   606,   719,   960,   527,
    1453,   987,   660,    -1,    -1,   721,   171,    -1,   720,    -1,
     719,     5,   720,    -1,   917,    -1,   917,   601,   917,    -1,
     917,   601,    20,    -1,   722,    -1,   721,   722,    -1,    -1,
     250,   728,   723,  1463,    -1,    -1,   253,   729,   724,  1463,
      -1,    -1,   988,   725,  1463,    -1,    -1,   147,   726,  1463,
      -1,    -1,   143,   727,  1463,    -1,   923,    -1,   728,     5,
     923,    -1,   923,    -1,   729,     5,   923,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    77,    -1,
     410,   819,   732,   371,    -1,    -1,     5,   773,   607,   776,
      -1,   135,    -1,   259,    -1,    -1,   735,    -1,   736,    -1,
     735,   736,    -1,    -1,    -1,   417,   737,   739,   738,  1179,
      -1,   786,    -1,  1443,    -1,   742,    -1,   739,     5,   742,
      -1,    -1,   741,   917,    -1,   333,   740,   785,    24,    -1,
     333,   740,   785,   917,    -1,   333,   740,   785,   925,    -1,
     333,   740,   785,    25,    -1,   746,   762,    -1,    -1,   740,
     333,   743,   744,    -1,    25,    -1,    24,    -1,   925,    -1,
      18,    25,    -1,   740,    -1,   745,    -1,   746,     5,   745,
      -1,    -1,   516,    -1,    -1,   467,   438,   754,   406,   749,
     605,   762,    -1,    -1,   298,   747,   751,    25,   752,   282,
     438,   753,   406,   750,   605,   762,    -1,   410,    -1,   437,
      -1,   371,    -1,   405,    -1,    25,    -1,   755,     5,   755,
       5,   755,    -1,   755,     5,   755,    -1,   755,    -1,    25,
      -1,    -1,   443,   757,   739,   263,    -1,    -1,   240,   758,
     740,   601,    20,    -1,    -1,   314,   759,   740,   238,   410,
     760,   371,    -1,   761,    -1,   760,     5,   761,    -1,   740,
      -1,   764,    -1,    -1,    39,    -1,    -1,    -1,   765,   767,
     766,   763,    -1,   748,    -1,   756,    -1,   516,    -1,   516,
     410,    25,   371,    -1,   403,   410,    25,   371,    -1,   403,
     410,    25,     5,    25,   371,    -1,   387,    -1,   598,   740,
      -1,   359,    -1,   489,    -1,    69,    -1,   377,    -1,   377,
     410,    25,   371,    -1,   377,   410,    25,     5,    25,   371,
      -1,   492,    -1,   492,   410,    25,   371,    -1,   492,   410,
      25,     5,    25,   371,    -1,   482,    -1,   279,    -1,   518,
      -1,   513,    -1,    60,    -1,    61,    -1,   555,    -1,   337,
     771,    -1,   349,   772,    -1,   768,    -1,    31,    -1,   537,
     769,   601,   770,    -1,   740,    -1,   740,    -1,    -1,   773,
     607,   776,    -1,   781,   607,   784,    -1,    -1,   774,   775,
      -1,   562,    -1,   493,    -1,   571,    -1,   533,    -1,   433,
      -1,   450,    -1,   346,   778,    -1,    -1,   777,   775,    -1,
      -1,   410,   780,   371,    -1,    -1,   410,    25,   371,    -1,
      25,    -1,    -1,   782,   783,   779,    -1,   562,    -1,   493,
      -1,   571,    -1,   533,    -1,   433,    -1,   450,    -1,   346,
     778,    -1,   783,    -1,    -1,    13,    -1,    -1,   216,   917,
     787,   598,   788,    -1,   790,    -1,   793,    -1,   516,    -1,
     516,   410,    25,   371,    -1,   403,   410,    25,   371,    -1,
     403,   410,    25,     5,    25,   371,    -1,   387,    -1,   359,
      -1,   489,    -1,   377,    -1,   377,   410,    25,   371,    -1,
     377,   410,    25,     5,    25,   371,    -1,   492,    -1,   492,
     410,    25,   371,    -1,   492,   410,    25,     5,    25,   371,
      -1,   482,    -1,   279,    -1,   518,    -1,   513,    -1,   555,
      -1,   337,   771,    -1,   349,   772,    -1,   789,    -1,   537,
     769,   601,   770,    -1,    -1,   467,   438,   754,   406,   791,
     605,   788,    -1,    -1,   298,   747,   751,    25,   752,   282,
     438,   753,   406,   792,   605,   788,    -1,    -1,   443,   794,
     796,   263,    -1,    -1,   240,   795,   917,   601,    20,    -1,
     797,    -1,   796,     5,   797,    -1,   798,   788,    -1,   799,
      -1,   798,     5,   799,    -1,   917,    -1,    -1,   599,   908,
      -1,    50,   917,    -1,    48,    -1,   607,  1453,    -1,   607,
     489,   917,   640,  1453,    -1,   607,   489,   917,   369,    -1,
      52,   917,    -1,   136,   844,  1093,   808,    -1,   380,   844,
     824,   800,   808,    -1,   189,   914,   808,    -1,    -1,    -1,
     168,   805,  1100,   607,   917,   601,    20,   807,   660,   806,
     809,    -1,    -1,   448,   909,    -1,   660,    -1,    -1,   810,
     218,    -1,   811,    -1,   810,   811,    -1,    -1,   331,   812,
    1463,    -1,    -1,   327,   813,  1463,    -1,    -1,   988,   814,
    1463,    -1,   478,   844,   825,   660,    -1,   478,   844,   825,
     660,    46,    -1,   266,    -1,   265,    -1,   192,    -1,   344,
      -1,   154,    -1,   191,    -1,   308,    -1,   307,    -1,   223,
      -1,   151,    -1,   150,    -1,   124,    -1,   184,    -1,   107,
      -1,   123,    -1,   167,    -1,   133,    -1,   193,    -1,   193,
     826,    -1,   829,    -1,   828,    -1,   833,    -1,   861,    -1,
     819,   820,    -1,   862,    -1,   864,    -1,   830,    -1,    18,
     819,    -1,    17,   819,    -1,   835,    -1,   843,    -1,   837,
      -1,   455,    -1,   730,    -1,   838,    -1,   839,    -1,   840,
      -1,   841,    -1,   842,    -1,   844,    -1,   844,   823,    -1,
     826,    -1,   463,    -1,   822,    -1,   823,     5,   822,    -1,
     826,    -1,   824,     5,   826,    -1,   826,    -1,   825,     5,
     826,    -1,   819,    -1,    17,    -1,    18,    -1,   583,   819,
      -1,   464,    -1,   407,    -1,   410,   819,   371,    -1,   422,
     410,  1397,   371,    -1,   274,   410,  1397,   371,    -1,   827,
     925,    -1,   827,    25,    -1,    24,    -1,   925,    -1,    25,
      -1,   832,    -1,  1075,    -1,  1075,   400,  1075,    -1,   831,
      -1,   413,   819,    -1,   372,   819,    -1,  1182,    -1,    -1,
     487,   834,  1182,    -1,     7,   819,    -1,     6,   819,    -1,
     819,    -1,   836,     5,   819,    -1,   604,   410,  1397,   371,
      -1,   408,   410,  1397,   371,    -1,   604,   410,   844,   836,
     371,    -1,   408,   410,   844,   836,   371,    -1,   366,    -1,
     229,    -1,     9,   819,    -1,   232,   819,    -1,     9,   819,
     421,    24,    -1,   232,   819,   421,    24,    -1,   537,   819,
      -1,   351,   819,    -1,   537,   819,   421,    24,    -1,   351,
     819,   421,    24,    -1,   370,    -1,     8,   819,    -1,    17,
     819,    -1,    18,   819,    -1,    20,   819,    -1,    19,   819,
      -1,    21,   819,    -1,    10,   819,    -1,    13,   819,    -1,
     436,   819,    -1,    11,   819,    -1,    12,   819,    -1,    16,
     819,    -1,    15,   819,    -1,    14,   819,    -1,    -1,    -1,
      -1,   917,   410,   846,   687,   847,   371,    -1,    -1,    -1,
     917,   501,   917,   410,   848,   687,   849,   371,    -1,    -1,
      -1,   518,   410,   851,   819,   852,   371,    -1,    -1,    -1,
     493,   410,   853,   819,   854,   371,    -1,    -1,    -1,   571,
     410,   855,   819,   856,   371,    -1,    -1,    -1,   562,   410,
     857,   819,   858,   371,    -1,   349,   410,   865,   371,   860,
      -1,   337,   410,    24,   371,   859,    -1,   337,   410,    25,
     371,   859,    -1,   337,   410,    25,   570,    25,   371,   859,
      -1,    -1,  1377,   607,  1378,    -1,   772,    -1,   850,    -1,
     269,   410,  1453,   371,    -1,    79,   410,   909,   371,    -1,
      51,   410,   909,   371,    -1,   386,   410,   909,   371,    -1,
     172,   410,   909,   371,    -1,    40,   410,   909,   371,    -1,
     863,    -1,   845,    -1,  1373,    -1,   518,    -1,   402,   410,
     819,   371,    -1,   302,   410,   819,   371,    -1,   468,   819,
      -1,   423,   731,    -1,   819,    88,    -1,   819,    89,    -1,
     819,    90,    -1,    24,    -1,   866,    -1,    18,   866,    -1,
     868,    -1,   867,    -1,    25,    -1,    25,    25,    -1,    25,
      25,   570,    25,    -1,    25,    25,   570,    25,   570,    25,
      -1,    25,    25,   570,    25,   570,    23,    -1,    25,   570,
      25,    -1,    25,   570,    25,   570,    25,    -1,    25,   570,
      25,   570,    23,    -1,    25,   570,    23,    -1,    23,    -1,
      25,    -1,    25,    18,    25,    -1,    -1,    -1,   576,  1075,
      13,   826,   607,   826,   872,   870,  1463,   871,   221,    -1,
      -1,   552,   826,    -1,    -1,    -1,    -1,   383,   874,   911,
     875,  1279,   876,  1463,   220,    -1,    -1,    -1,   619,   917,
     878,   734,   879,  1019,   881,   880,   886,   620,    -1,    -1,
     891,    -1,    -1,   882,    -1,   883,    -1,   882,   883,    -1,
      -1,   621,   884,  1463,    -1,    -1,   622,   885,  1463,    -1,
      -1,   887,    -1,   888,    -1,   887,   888,    -1,    -1,   623,
     889,  1463,    -1,    -1,   624,   890,  1463,    -1,   892,   896,
     304,    -1,    71,    -1,    71,   893,   527,   894,    -1,    71,
     364,   895,    -1,  1075,    -1,   893,     5,  1075,    -1,   917,
      -1,   894,     5,   917,    -1,  1075,    -1,   895,     5,  1075,
      -1,   897,    -1,   896,   897,    -1,    -1,   625,   898,  1463,
      -1,    -1,   626,   899,  1463,    -1,    -1,   645,   894,   900,
    1463,    -1,    -1,   461,   894,   901,  1463,    -1,    -1,   606,
     894,   902,  1463,    -1,   526,   910,    -1,   535,    18,    25,
      -1,   535,    -1,   481,    17,    25,    -1,   481,    -1,    25,
      -1,  1075,    -1,    24,    -1,   924,    -1,   826,    -1,   906,
       5,   906,    -1,   907,    -1,   917,    -1,   648,   410,   917,
     371,    -1,   917,   601,   648,   410,   917,   371,    -1,   917,
     438,   657,   406,    -1,   917,   601,    20,    -1,   917,   438,
     657,   406,   601,    20,    -1,   917,   601,   917,    -1,   917,
     438,   657,   406,   601,   917,    -1,   918,    -1,   918,    -1,
     918,    -1,   918,    -1,   918,    -1,   918,    -1,    -1,   531,
      25,    -1,   921,  1462,   922,    -1,   921,   919,   922,    -1,
    1462,    -1,   329,   410,   920,   371,    -1,  1078,    -1,    24,
      -1,    -1,    -1,   917,    -1,   917,   438,   657,   406,    -1,
     917,   601,    20,    -1,   917,   438,   657,   406,   601,    20,
      -1,   917,   601,   917,    -1,   917,   438,   657,   406,   601,
     917,    -1,  1075,    -1,    23,    -1,   601,    25,    -1,   353,
      -1,   472,    -1,   473,    -1,   370,    -1,   474,    -1,   333,
      -1,   300,    -1,   476,    -1,   439,    -1,   517,    -1,   428,
      -1,   572,    -1,   376,    -1,   469,    -1,   462,    -1,   540,
      -1,   379,    -1,   338,    -1,   477,    -1,   301,    -1,   519,
      -1,   260,    -1,   574,    -1,   636,    -1,   520,    -1,   302,
      -1,   522,    -1,   384,    -1,   422,    -1,   562,    -1,   493,
      -1,   571,    -1,   455,    -1,   358,    -1,   373,    -1,   418,
      -1,   360,    -1,   421,    -1,   402,    -1,   367,    -1,   325,
      -1,   539,    -1,   518,    -1,   528,  1445,    -1,   633,   929,
      -1,   930,    -1,   929,     5,   930,    -1,   917,    -1,   644,
     929,    -1,   635,   929,    -1,   636,  1453,    -1,   634,   914,
     640,  1453,    -1,   638,   929,    -1,   639,  1453,    -1,   637,
     914,   640,  1453,    -1,    -1,   642,   935,   824,   940,   942,
     944,   936,   938,    -1,    -1,   937,    -1,   630,    -1,   631,
      -1,    -1,   939,    -1,   324,  1075,    -1,    -1,   941,    -1,
     369,   824,    -1,    -1,   943,    -1,   641,    25,    -1,    -1,
     945,    -1,   632,    25,   946,    -1,    -1,   379,    25,    -1,
      -1,   603,   826,   556,   948,  1463,   949,   420,    -1,    -1,
      -1,   523,   950,  1463,    -1,    -1,    -1,    43,   951,   826,
     556,   952,  1463,   949,    -1,    86,   917,   410,    25,   371,
      -1,    36,   917,    -1,    55,   917,    -1,    -1,   270,  1105,
     956,   607,   463,    -1,   270,  1105,   537,   957,    -1,   958,
      -1,   957,     5,   958,    -1,   769,   601,  1369,    -1,   769,
     601,    20,    -1,    -1,   961,   304,    -1,    -1,   130,    -1,
     962,    -1,   961,   962,    -1,    -1,   250,   976,   963,  1463,
      -1,    -1,   253,   977,   964,  1463,    -1,    -1,   331,   965,
    1463,    -1,    -1,   327,   966,  1463,    -1,    -1,   988,   967,
    1463,    -1,    -1,   285,   968,  1463,    -1,    -1,   255,   969,
    1463,    -1,    -1,   645,   974,   970,  1463,    -1,    -1,   461,
     972,   971,  1463,    -1,   973,    -1,   972,     5,   973,    -1,
     429,    -1,   418,    -1,   975,    -1,   974,     5,   975,    -1,
     429,    -1,   418,    -1,   909,    -1,   976,     5,   909,    -1,
     909,    -1,   977,     5,   909,    -1,   294,   980,    -1,   295,
     917,   640,   980,    -1,   542,    -1,   354,    -1,   909,    -1,
      -1,   646,   983,   982,   959,    -1,   364,  1093,   960,   916,
     660,    -1,  1093,   960,   527,  1453,   916,   660,    -1,    -1,
     467,  1100,   960,   527,   917,   601,    20,   916,   984,   660,
      -1,   449,  1453,   986,    -1,   608,    -1,   520,    -1,    56,
      25,    -1,    62,    25,    -1,    -1,   531,    25,    -1,    -1,
     409,   989,   995,    -1,   275,    -1,    -1,   577,   991,   995,
      -1,   283,   997,    -1,    -1,   577,   994,   995,    -1,   997,
      -1,   410,   996,   371,    -1,   997,    -1,   996,     5,   997,
      -1,    -1,   998,   999,    -1,   575,    -1,   292,    -1,   310,
      -1,   284,    -1,   465,    -1,   421,    -1,   608,    -1,   531,
      -1,   520,    -1,   445,    -1,   418,    -1,   521,    -1,   536,
      -1,   500,    -1,   290,    -1,   291,    -1,    24,    -1,   490,
      -1,    -1,    -1,   579,  1002,  1098,  1003,    13,   844,  1004,
      -1,   463,    -1,   825,    -1,   199,  1075,    -1,   188,  1075,
      -1,   202,  1075,    -1,   430,  1075,   313,    -1,   430,  1075,
     365,   905,    -1,    -1,  1011,  1010,  1014,    -1,    -1,  1012,
      -1,  1013,    -1,  1012,  1013,    -1,   954,    -1,  1018,    -1,
    1034,    -1,  1020,    -1,    -1,  1015,    -1,  1017,    -1,  1015,
    1017,    -1,    47,   917,    -1,  1022,    -1,  1028,    -1,  1040,
      -1,  1192,    -1,  1202,    -1,  1061,    -1,  1443,    -1,   877,
      -1,   707,    -1,   953,    -1,   713,    -1,   707,    -1,  1443,
      -1,    -1,   707,    -1,  1443,    -1,   735,    -1,   347,    -1,
      41,    -1,    -1,    -1,    -1,    -1,  1021,  1023,   917,   410,
    1024,  1091,   371,  1025,   734,  1026,  1019,  1463,  1027,    -1,
     190,    -1,    -1,    -1,   538,  1029,   734,  1030,  1463,   341,
      -1,   445,   821,    -1,   844,    -1,   844,   824,    -1,   336,
    1381,    -1,  1035,    -1,  1036,    -1,  1035,  1036,    -1,  1037,
      -1,  1018,    -1,  1033,    -1,    -1,   385,  1038,  1039,    -1,
     734,   222,    -1,   905,    -1,    -1,    -1,    -1,    93,   917,
      92,   917,   410,  1041,  1091,   371,  1042,   734,  1043,  1019,
    1463,  1027,    -1,    -1,   539,  1045,  1060,  1051,  1046,    -1,
     342,    -1,    -1,   214,  1048,  1463,    -1,    -1,    22,  1052,
    1053,  1054,   916,  1049,  1463,    -1,    -1,    22,  1052,   916,
    1050,  1463,    -1,  1047,    -1,  1051,  1047,    -1,    -1,   990,
      -1,    24,    -1,  1075,    -1,    -1,  1075,    -1,    24,    -1,
     231,  1058,    -1,   243,  1059,    -1,   226,  1059,    -1,   566,
      -1,    24,    -1,  1075,    -1,  1058,    -1,  1059,     5,  1058,
      -1,  1075,    -1,    24,    -1,    -1,    -1,   627,   917,  1062,
     734,  1063,  1064,   628,    -1,  1065,    -1,  1064,  1065,    -1,
      -1,   629,  1066,  1463,    -1,    -1,   606,   917,  1067,  1463,
      -1,  1071,  1069,    -1,    -1,   661,  1073,    -1,  1074,    -1,
    1070,    -1,   941,    -1,   943,    -1,   945,    -1,   937,    -1,
     939,    -1,    -1,   350,  1072,   825,    -1,    -1,    46,    -1,
      46,    -1,  1076,    -1,  1078,    -1,   170,  1078,    -1,  1078,
     921,   601,    -1,  1077,  1082,    -1,  1077,   917,   438,  1085,
     406,    -1,  1083,    -1,   917,    -1,  1079,    -1,   917,   437,
    1081,   405,    -1,   917,   437,  1081,   405,    -1,  1075,    -1,
      24,    -1,    20,    -1,   917,    -1,   917,  1084,    -1,   438,
    1085,   406,    -1,   438,  1085,   406,   438,  1085,   406,    -1,
    1086,    -1,  1085,     5,  1086,    -1,   657,    -1,  1088,    -1,
    1090,    -1,  1088,   921,   601,  1089,    -1,  1088,   921,   601,
     917,   438,  1085,   406,    -1,   917,    -1,  1080,    -1,    20,
      -1,   917,    -1,   917,  1084,    -1,    -1,  1092,    -1,  1094,
      -1,  1092,     5,  1094,    -1,  1095,    -1,  1093,     5,  1095,
      -1,   917,    -1,   917,   601,   917,    -1,  1075,    -1,  1075,
     400,  1075,    -1,    24,    -1,   925,    -1,    25,    -1,  1097,
      -1,  1096,     5,  1097,    -1,  1075,    -1,  1075,   400,  1075,
      -1,  1099,    -1,  1098,     5,  1099,    -1,  1087,    -1,  1075,
      -1,  1102,    -1,  1101,     5,  1102,    -1,  1075,  1103,    -1,
      -1,   568,    -1,   519,    -1,   917,   438,  1085,   406,    -1,
    1106,    -1,  1105,     5,  1106,    -1,  1075,    -1,  1075,   400,
    1075,    -1,   234,   913,   599,   907,   560,  1455,   665,    -1,
      -1,   599,   410,   826,     5,   826,   371,  1109,    -1,    -1,
     549,   410,   826,     5,   826,   371,    -1,   235,   917,  1108,
      -1,   917,    -1,   318,   915,  1113,    -1,  1114,    -1,   527,
     826,    -1,  1115,  1116,  1121,     8,  1111,    -1,    -1,   599,
    1117,   410,   826,     5,   826,   371,    -1,    -1,   537,   918,
      -1,    -1,   330,    -1,   197,  1422,   246,  1438,  1120,    -1,
     544,   910,    -1,   544,   910,     8,   844,   824,    -1,    -1,
     598,   557,  1416,   353,  1416,    -1,   598,   557,  1416,     5,
     353,  1416,    -1,   598,  1416,     5,  1416,    -1,    -1,   630,
      -1,   631,    -1,    70,  1438,  1123,  1124,    -1,    -1,   598,
    1438,    -1,    -1,   598,   557,  1416,     8,  1416,    -1,   557,
    1416,     8,  1416,    -1,   391,  1126,    -1,  1127,    -1,  1126,
       5,  1127,    -1,   183,   904,    -1,   264,   904,    -1,   309,
     904,    -1,   317,   904,    -1,   273,   904,    -1,   239,   904,
      -1,   992,    -1,   418,   993,    -1,   429,   993,    -1,   542,
     993,    -1,   354,   993,    -1,   531,   993,    -1,   529,   905,
      -1,   530,   905,    -1,   380,   661,    -1,   646,   661,    -1,
     271,    -1,   175,    -1,   131,    -1,   108,    -1,   126,    -1,
     117,    -1,  1421,   393,  1131,   527,  1129,    -1,  1075,    -1,
      24,    -1,   382,  1131,    -1,   382,  1131,     8,  1093,    -1,
     918,    -1,    -1,   441,  1140,   660,   576,  1135,  1075,   916,
     660,  1133,  1136,    -1,   441,  1140,   660,   324,  1075,    -1,
      -1,   516,    -1,    -1,  1137,   262,    -1,  1138,    -1,  1137,
    1138,    -1,    -1,   988,  1139,  1463,    -1,   825,    -1,    -1,
     585,   910,  1142,  1143,    -1,    -1,   527,  1144,    -1,  1145,
      -1,  1144,     5,  1145,    -1,  1409,    -1,   463,    -1,   200,
    1148,    68,    -1,   200,  1148,   607,  1147,    -1,   200,  1148,
      67,  1147,    -1,   200,  1148,    -1,    24,    -1,   924,    -1,
     917,    -1,    -1,   459,    -1,   125,  1148,  1149,   410,   844,
    1032,   371,    -1,   173,  1148,    -1,  1183,  1191,    -1,   426,
      42,    -1,   426,  1154,    -1,  1155,    -1,  1154,  1155,    -1,
      -1,   113,  1156,  1463,    -1,    -1,   179,  1157,  1463,    -1,
      -1,   208,  1158,  1463,    -1,    -1,   196,  1159,  1463,    -1,
      -1,   233,  1160,  1463,    -1,    -1,   181,  1075,  1161,  1463,
      -1,    -1,   204,  1075,  1162,  1463,    -1,  1173,    -1,  1175,
      -1,  1174,    -1,  1164,    -1,  1200,    -1,  1167,    -1,    -1,
     541,   826,  1165,   462,    -1,    -1,   462,    -1,    -1,   550,
     826,  1168,  1166,    -1,   138,    -1,   610,  1187,    -1,   141,
    1187,    -1,   140,  1187,    -1,    -1,  1170,    -1,  1171,    -1,
    1170,  1171,    -1,  1180,  1172,    -1,    -1,   599,  1187,    -1,
     499,  1169,  1179,    -1,   498,  1416,  1179,    -1,   497,  1178,
    1177,  1176,  1179,    -1,    -1,   132,   819,    -1,   132,   819,
       5,   819,    -1,   594,    -1,   595,    -1,   596,    -1,   597,
      -1,  1075,    -1,    -1,   502,    -1,  1181,    -1,  1180,     5,
    1181,    -1,   826,  1214,    -1,   590,   410,   819,   371,  1199,
      -1,    45,  1199,    -1,   476,   410,    20,   371,  1199,    -1,
     392,   410,    20,   371,  1199,    -1,   367,   410,   819,   371,
    1199,    -1,   569,   410,   819,   371,  1199,    -1,   582,   410,
     819,   371,  1199,    -1,   581,   410,   819,   371,  1199,    -1,
      -1,   440,  1184,    -1,  1185,    -1,  1184,  1185,    -1,   207,
      25,    -1,   198,    25,    -1,   281,    25,    -1,   164,    25,
      -1,   236,    25,    -1,   156,    -1,   323,    24,    -1,   323,
    1075,    -1,   157,    24,    -1,   139,    24,    -1,  1190,    -1,
    1186,  1190,    -1,  1188,    88,    -1,  1188,    90,    -1,  1188,
      89,    -1,  1188,    -1,   925,    -1,    25,    -1,    -1,   440,
    1186,    -1,   207,  1187,    -1,   198,  1187,    -1,   281,  1187,
      -1,   164,  1187,    -1,   236,  1187,    -1,   237,  1187,    -1,
     609,    24,    -1,   610,  1187,    -1,   614,    -1,   611,    -1,
     612,    -1,   613,    -1,   618,    -1,   615,    -1,   616,    -1,
     617,    -1,    57,  1187,    -1,    58,  1187,    -1,    59,  1187,
      -1,   323,    24,    -1,   157,    24,    -1,   379,    -1,    53,
      -1,    54,    -1,    -1,   494,   600,  1101,    -1,   114,  1101,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,  1193,   917,
     410,  1194,  1091,   371,  1195,   734,  1196,  1152,  1197,  1153,
    1198,   219,    -1,    -1,   506,   819,    -1,   496,  1201,    -1,
      -1,  1129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
    1203,   917,   410,  1204,  1091,   371,  1205,   734,  1206,  1209,
    1207,  1153,  1208,   219,    -1,  1189,  1191,    -1,    -1,    -1,
      -1,   134,   410,    24,     5,  1211,   687,  1212,   371,  1213,
     685,    -1,    -1,   363,    -1,   363,   198,    25,    -1,   363,
     198,  1075,    -1,   588,   826,    -1,   588,   826,   324,  1075,
      -1,   588,   826,   142,    -1,   588,   826,   558,    -1,   588,
     826,   525,    -1,  1217,    -1,   153,    -1,   303,    -1,   261,
      -1,  1224,    -1,  1219,    -1,    -1,    -1,   186,  1220,  1366,
     410,  1221,  1228,   371,    -1,    -1,    -1,   111,  1222,  1366,
     410,  1223,  1228,   371,  1225,    -1,    83,  1226,   371,    -1,
      35,   918,    -1,    -1,   248,    -1,  1227,    -1,  1226,     5,
    1227,    -1,   917,   568,    -1,   917,   519,    -1,   917,    -1,
    1229,    -1,  1228,     5,  1229,    -1,  1319,    -1,  1317,    -1,
     100,   917,    -1,   159,    -1,    33,   917,  1232,    -1,  1233,
      -1,  1232,     5,  1233,    -1,  1234,    -1,  1237,    -1,  1240,
      -1,  1245,    -1,  1246,    -1,  1244,    -1,  1243,    -1,   565,
    1235,    -1,   565,   410,  1236,   371,    -1,  1229,    -1,  1229,
     645,   917,    -1,  1235,    -1,  1236,     5,  1235,    -1,   522,
    1239,    -1,   522,   410,  1238,   371,    -1,  1239,    -1,  1238,
       5,  1239,    -1,   917,    -1,   434,  1242,    -1,   434,   410,
    1241,   371,    -1,  1242,    -1,  1241,     5,  1242,    -1,  1229,
      -1,    65,    -1,    66,    -1,    64,    25,    -1,    37,  1323,
      -1,    37,   410,  1247,   371,    -1,    38,  1248,    -1,    38,
     410,  1247,   371,    -1,  1323,    -1,  1247,     5,  1323,    -1,
     917,    -1,   245,    -1,   211,    -1,   144,  1251,    -1,   121,
      -1,   109,    -1,    99,    -1,    97,    -1,   101,    -1,   158,
    1422,    -1,   210,  1250,   439,  1416,   607,  1416,    -1,   278,
     910,   439,  1416,   607,  1416,    -1,    -1,  1422,    -1,    -1,
     826,    -1,   503,   826,    -1,    -1,    -1,   458,  1366,  1254,
     564,  1257,  1255,  1256,    -1,    -1,   129,   911,    -1,   506,
    1342,    -1,   410,  1261,   371,    13,   410,  1262,   371,    -1,
    1258,    -1,    20,    13,   410,  1262,   371,    -1,    20,    13,
    1262,    -1,  1260,    -1,  1258,     5,  1260,    -1,  1369,    -1,
    1259,    13,  1263,    -1,  1259,    -1,  1261,     5,  1259,    -1,
    1263,    -1,  1262,     5,  1263,    -1,   463,    -1,  1409,    -1,
     209,    -1,    -1,   228,  1266,  1366,  1269,  1267,    -1,    -1,
     459,  1268,   410,  1271,   371,    -1,  1403,    -1,    -1,   410,
    1270,   371,    -1,  1369,    -1,  1270,     5,  1369,    -1,  1272,
      -1,  1271,     5,  1272,    -1,  1409,    -1,   463,    -1,    -1,
      -1,   480,  1274,  1276,  1275,  1277,    -1,  1281,   911,    -1,
     911,    -1,    -1,    -1,   534,  1278,  1096,    -1,    -1,    -1,
     534,  1280,  1096,    -1,   481,    -1,   535,    -1,   542,    -1,
     354,    -1,   321,    -1,   375,    -1,   357,   826,    -1,   330,
     826,    -1,   217,  1366,   129,   911,    -1,   217,  1366,  1339,
      -1,   494,   600,  1285,    -1,  1286,    -1,  1285,     5,  1286,
      -1,  1287,  1288,    -1,    25,    -1,  1369,    -1,    -1,   568,
      -1,   519,    -1,   256,    -1,   289,    -1,    -1,   306,    -1,
     336,  1438,  1291,    -1,    -1,  1421,  1294,  1295,    -1,  1324,
      -1,  1328,    -1,  1290,    -1,  1423,    -1,  1289,    -1,  1282,
      -1,  1283,    -1,  1273,    -1,  1265,    -1,  1264,    -1,  1393,
      -1,  1253,    -1,   485,  1298,   606,  1366,   607,  1303,  1297,
      -1,    -1,   120,    -1,   148,    -1,  1299,    -1,  1300,    -1,
    1299,     5,  1300,    -1,   451,    -1,   429,    -1,   418,    -1,
     458,  1301,    -1,    -1,   410,  1302,   371,    -1,  1369,    -1,
    1302,     5,  1369,    -1,  1304,    -1,  1303,     5,  1304,    -1,
     442,    -1,  1367,    -1,   215,  1366,  1306,   598,  1403,  1308,
      -1,    -1,   410,  1307,   371,    -1,  1369,    -1,  1307,     5,
    1369,    -1,    -1,   119,    -1,   472,   410,  1342,   371,    -1,
     225,   410,  1312,   371,  1311,    -1,   276,  1313,    -1,  1314,
      -1,  1366,    -1,  1366,   410,  1314,   371,    -1,  1369,    -1,
    1314,     5,  1369,    -1,   456,   410,  1316,   371,    -1,   238,
     410,  1316,   371,    -1,  1369,    -1,  1316,     5,  1369,    -1,
    1315,    -1,  1310,    -1,  1309,    -1,   379,  1372,    -1,   187,
      -1,   917,  1358,  1320,  1321,    -1,    -1,  1318,    -1,    -1,
    1322,    -1,  1323,    -1,  1322,  1323,    -1,   352,    -1,   137,
      -1,  1311,    -1,   472,   410,  1342,   371,    -1,    98,  1325,
    1327,    -1,  1326,    -1,  1367,    -1,  1328,    -1,  1327,  1328,
      -1,  1305,    -1,  1296,    -1,   427,  1342,    -1,   348,  1331,
      -1,  1408,    -1,  1331,     5,  1408,    -1,   506,  1342,    -1,
     527,  1334,    -1,  1335,    -1,  1334,     5,  1335,    -1,  1336,
      -1,   495,  1336,    -1,   495,   410,  1337,   371,    -1,  1366,
      -1,  1366,  1371,    -1,  1335,    -1,  1337,     5,  1335,    -1,
    1333,  1339,  1340,  1341,    -1,    -1,  1332,    -1,    -1,  1330,
      -1,    -1,  1329,    -1,  1343,    -1,  1342,     6,  1343,    -1,
    1344,    -1,  1343,     7,  1344,    -1,  1345,    -1,   583,  1345,
      -1,  1356,    -1,   410,  1342,   371,    -1,   422,  1404,    -1,
     274,  1404,    -1,    -1,   421,  1349,    -1,  1412,    -1,   917,
      -1,  1412,    -1,  1409,   604,   410,  1351,   371,    -1,  1409,
     604,  1404,    -1,  1409,   408,   410,  1351,   371,    -1,  1409,
     408,  1404,    -1,  1352,    -1,  1351,     5,  1352,    -1,  1442,
      -1,  1372,    -1,    -1,   583,    -1,  1409,  1353,   366,    -1,
    1409,  1353,   229,    -1,  1409,  1355,  1409,    -1,  1409,  1353,
     368,  1409,     7,  1409,    -1,  1409,   537,  1348,  1347,    -1,
    1409,   351,  1348,  1347,    -1,  1409,  1353,     9,  1348,  1347,
      -1,    13,    -1,    16,    -1,    11,    -1,    12,    -1,   232,
      -1,     9,    -1,    15,    -1,    14,    -1,  1354,    -1,  1350,
      -1,  1346,    -1,    -1,   566,    -1,   339,    -1,   456,    -1,
    1359,    -1,  1360,    -1,  1362,    -1,   516,    -1,   516,   410,
    1363,   371,    -1,   390,   410,  1364,  1361,   371,    -1,   452,
      -1,   377,   410,  1364,  1361,   371,    -1,   492,   410,  1364,
    1361,   371,    -1,   518,    -1,   387,    -1,   359,    -1,   337,
    1379,   607,  1380,    -1,   337,    -1,   349,  1379,   607,  1380,
      -1,   349,    -1,   349,  1379,   410,    25,   371,   607,  1380,
      -1,   555,    -1,   513,    -1,   403,    -1,   403,   410,    25,
     371,    -1,   403,   410,    25,     5,    25,   371,    -1,    -1,
       5,  1365,    -1,   482,   410,  1364,   371,    -1,   546,    -1,
     279,    -1,   482,    -1,    44,    -1,    25,    -1,    25,    -1,
      25,    -1,    24,   601,   917,    -1,    24,    -1,   917,    -1,
     917,   570,   917,    -1,   917,    -1,    -1,   438,    25,   406,
      -1,   438,    25,     5,    25,   406,    -1,  1370,    -1,   593,
    1370,    -1,   917,  1368,    -1,  1366,   921,   601,   917,  1368,
      -1,  1366,   921,   601,    20,    -1,   917,    -1,    24,    -1,
     390,    -1,   925,    -1,    25,    -1,    17,   925,    -1,    17,
      25,    -1,    18,   925,    -1,    18,    25,    -1,  1374,    -1,
     375,  1376,    -1,   375,  1375,    -1,    -1,  1379,   607,  1380,
      -1,    -1,  1377,   607,  1377,    -1,   562,    -1,   493,    -1,
     571,    -1,   533,    -1,   433,    -1,   450,    -1,   346,    -1,
     346,   410,    25,   371,    -1,   562,    -1,   493,    -1,   571,
      -1,   533,    -1,   433,    -1,   450,    -1,   346,    -1,   346,
     410,    25,   371,    -1,   562,    -1,   493,    -1,   571,    -1,
     533,    -1,   433,    -1,   450,    -1,   346,    -1,   562,    -1,
     493,    -1,   571,    -1,   533,    -1,   433,    -1,   450,    -1,
     346,    -1,   917,    -1,    24,    -1,  1421,   483,   911,    -1,
      -1,  1421,   378,   911,   416,   576,  1391,  1384,  1388,    -1,
      -1,  1421,   378,   911,   416,    80,   576,  1392,  1385,  1388,
      -1,    -1,  1421,   378,   911,   115,  1392,  1386,  1388,    -1,
      -1,  1421,   378,   911,   116,    80,   576,  1392,  1387,  1388,
      -1,    -1,   268,    -1,   267,  1389,    -1,  1390,    -1,  1389,
       5,  1390,    -1,   917,    -1,   917,   601,   917,    -1,    24,
     601,   917,   601,   917,    -1,  1392,    -1,  1265,    -1,  1131,
      -1,  1394,    -1,  1394,  1388,    -1,    -1,    -1,   451,  1405,
    1406,  1395,  1402,  1396,  1338,  1400,    -1,   451,  1405,  1406,
    1338,  1400,    -1,  1399,    -1,  1416,    -1,   451,   921,  1405,
    1406,  1402,  1338,  1400,    -1,    -1,   505,  1357,  1398,    -1,
    1284,    -1,   311,  1401,  1225,    -1,  1284,   311,  1401,  1225,
      -1,   917,    -1,    -1,   534,  1096,    -1,   451,   921,  1405,
    1406,  1338,    -1,   410,   451,   921,  1405,  1406,  1338,   371,
      -1,    -1,   566,    -1,   339,    -1,   456,    -1,  1407,    -1,
    1406,     5,  1407,    -1,  1409,    -1,  1409,  1462,    -1,  1409,
     926,    -1,  1409,    -1,  1410,    -1,  1442,    -1,  1404,    -1,
     593,   917,    -1,   593,   917,   601,   917,    -1,  1409,    19,
    1409,    -1,  1409,  1430,    -1,  1409,    20,  1409,    -1,  1409,
      17,  1409,    -1,  1409,    18,  1409,    -1,  1372,    -1,   464,
      -1,   407,    -1,   557,    -1,    20,    -1,    45,    -1,   569,
     410,  1357,  1409,   371,    -1,   581,   410,  1357,  1409,   371,
      -1,   582,   410,  1357,  1409,   371,    -1,   590,   410,  1357,
    1409,   371,    -1,   476,   410,  1357,  1409,   371,    -1,   917,
     410,  1411,   371,    -1,   518,   410,  1411,   371,    -1,   410,
    1409,   371,    -1,   423,   410,  1431,   371,    -1,  1409,    -1,
    1411,     5,  1409,    -1,    -1,  1372,    -1,  1421,   326,  1420,
    1415,  1398,    -1,  1421,   315,  1420,  1415,   228,  1366,  1417,
      -1,  1421,   315,  1420,  1415,  1075,    -1,    -1,   301,  1416,
      -1,    24,    -1,  1075,    -1,    -1,   410,  1418,   371,    -1,
    1419,    -1,  1418,     5,  1419,    -1,   917,    -1,    24,    -1,
    1075,    -1,    -1,   247,  1422,   576,    -1,   918,    -1,  1428,
      -1,  1427,    -1,  1424,    -1,   296,  1425,   607,  1425,    -1,
     277,  1425,   601,  1426,   607,  1426,    -1,   917,    -1,   917,
      -1,   201,   769,    -1,   272,   769,  1429,    -1,   251,    -1,
     155,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,   375,     5,  1379,   607,  1380,    -1,
    1369,     5,  1379,   607,  1380,    -1,   375,  1379,   607,  1380,
      -1,    -1,   589,  1433,  1434,   169,    -1,  1435,    -1,  1434,
    1435,    -1,    32,    -1,  1436,    -1,  1437,    -1,   170,  1442,
      -1,   534,  1096,    -1,  1439,    -1,   170,  1440,    -1,  1440,
      -1,  1104,    -1,   917,    -1,  1440,   601,  1441,    -1,    24,
     601,  1440,   601,  1441,    -1,    20,    -1,  1104,    -1,   917,
      -1,  1439,    -1,  1439,   400,  1439,    -1,   106,  1444,    -1,
     110,  1444,    -1,   105,  1444,    -1,   145,    -1,   146,  1444,
      -1,   103,  1444,    -1,   128,  1444,    -1,   127,  1444,    -1,
     102,  1444,    -1,   335,    -1,   602,   607,  1445,    -1,   528,
    1445,    -1,   553,    -1,   514,  1446,    -1,   917,    -1,   570,
     917,    -1,   917,    -1,    -1,    -1,   507,  1448,   826,  1449,
    1463,   305,    -1,    -1,   640,  1453,    -1,    -1,   643,    -1,
     161,    -1,   257,   912,    -1,    49,   912,    -1,   287,    -1,
     286,    -1,   288,   914,  1450,  1451,    -1,   473,  1453,  1451,
      -1,   909,    -1,  1453,     5,   909,    -1,    82,    -1,   112,
     912,    -1,   826,   547,     5,   826,   372,    -1,   489,   826,
      -1,   244,   912,    -1,    81,  1458,     8,  1459,  1457,    -1,
      -1,   527,   826,    -1,   917,    -1,   917,    -1,   227,   912,
      -1,   230,   912,   607,   826,     5,   826,    -1,   230,   912,
     600,   826,     5,   826,    -1,    26,    -1,    -1,  1465,    -1,
    1466,  1179,    -1,  1464,    -1,  1465,  1464,    -1,    -1,  1467,
    1468,    -1,   650,    -1,   651,    -1,   652,    -1,   653,    -1,
     670,    -1,   692,    -1,   706,    -1,   707,    -1,   713,    -1,
     714,    -1,   733,    -1,   801,    -1,   802,    -1,   803,    -1,
     804,    -1,   815,    -1,   816,    -1,   817,    -1,   818,    -1,
     869,    -1,   873,    -1,   903,    -1,   927,    -1,   928,    -1,
     931,    -1,   932,    -1,   933,    -1,   934,    -1,   947,    -1,
     955,    -1,   978,    -1,   979,    -1,   981,    -1,   985,    -1,
    1000,    -1,  1001,    -1,  1005,    -1,  1006,    -1,  1007,    -1,
    1008,    -1,  1016,    -1,  1031,    -1,  1044,    -1,  1055,    -1,
    1056,    -1,  1057,    -1,  1068,    -1,  1107,    -1,  1110,    -1,
    1112,    -1,  1118,    -1,  1119,    -1,  1122,    -1,  1125,    -1,
    1128,    -1,  1130,    -1,  1132,    -1,  1134,    -1,  1141,    -1,
    1146,    -1,  1150,    -1,  1151,    -1,  1163,    -1,  1215,    -1,
    1216,    -1,  1218,    -1,  1230,    -1,  1231,    -1,  1249,    -1,
    1252,    -1,  1292,    -1,  1293,    -1,  1382,    -1,  1383,    -1,
    1413,    -1,  1414,    -1,  1432,    -1,  1443,    -1,  1447,    -1,
    1452,    -1,  1454,    -1,  1456,    -1,  1460,    -1,  1461,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   885,   885,   888,   891,   897,   903,   910,   914,   914,
     920,   938,   939,   940,   941,   942,   956,   957,   958,   959,
     960,   965,   966,   977,   980,   983,   983,   987,   990,   991,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1015,  1016,  1019,  1019,
    1027,  1028,  1031,  1037,  1039,  1050,  1052,  1054,  1056,  1060,
    1062,  1124,  1128,  1132,  1132,  1139,  1142,  1146,  1147,  1150,
    1156,  1150,  1169,  1174,  1178,  1169,  1190,  1194,  1190,  1202,
    1207,  1202,  1226,  1233,  1237,  1225,  1263,  1263,  1267,  1268,
    1269,  1274,  1277,  1282,  1286,  1294,  1297,  1297,  1303,  1307,
    1322,  1320,  1338,  1338,  1353,  1353,  1356,  1356,  1360,  1363,
    1363,  1363,  1370,  1371,  1370,  1378,  1378,  1389,  1389,  1408,
    1411,  1414,  1417,  1420,  1423,  1436,  1441,  1441,  1442,  1442,
    1445,  1450,  1450,  1454,  1464,  1478,  1482,  1477,  1492,  1498,
    1506,  1507,  1510,  1510,  1513,  1517,  1522,  1529,  1529,  1533,
    1533,  1540,  1540,  1545,  1545,  1550,  1550,  1555,  1555,  1568,
    1569,  1577,  1578,  1595,  1598,  1601,  1604,  1607,  1610,  1616,
    1627,  1632,  1645,  1649,  1664,  1665,  1669,  1669,  1673,  1673,
    1673,  1674,  1675,  1680,  1680,  1683,  1683,  1692,  1693,  1694,
    1697,  1701,  1702,  1702,  1719,  1719,  1719,  1719,  1723,  1730,
    1731,  1734,  1734,  1737,  1737,  1746,  1743,  1759,  1759,  1761,
    1761,  1763,  1765,  1767,  1769,  1772,  1776,  1776,  1777,  1777,
    1781,  1781,  1793,  1793,  1798,  1802,  1804,  1805,  1808,  1808,
    1808,  1812,  1813,  1814,  1815,  1822,  1823,  1824,  1825,  1828,
    1829,  1830,  1831,  1835,  1840,  1845,  1849,  1852,  1856,  1857,
    1858,  1859,  1860,  1861,  1862,  1863,  1866,  1867,  1868,  1900,
    1904,  1906,  1908,  1908,  1915,  1919,  1919,  1923,  1924,  1925,
    1926,  1927,  1928,  1929,  1935,  1935,  1938,  1940,  1946,  1948,
    1954,  1962,  1962,  1965,  1966,  1967,  1968,  1969,  1970,  1971,
    1977,  1980,  1980,  1993,  1993,  2000,  2001,  2002,  2004,  2005,
    2007,  2009,  2010,  2011,  2012,  2017,  2023,  2029,  2030,  2032,
    2034,  2035,  2036,  2037,  2038,  2039,  2042,  2043,  2050,  2058,
    2058,  2066,  2063,  2078,  2078,  2080,  2080,  2088,  2088,  2091,
    2094,  2095,  2100,  2112,  2116,  2119,  2122,  2123,  2124,  2125,
    2126,  2131,  2138,  2144,  2149,  2153,  2149,  2164,  2166,  2171,
    2176,  2176,  2180,  2180,  2183,  2183,  2189,  2189,  2195,  2195,
    2211,  2214,  2228,  2230,  2232,  2234,  2236,  2238,  2240,  2246,
    2248,  2252,  2254,  2256,  2258,  2260,  2262,  2264,  2270,  2285,
    2288,  2301,  2302,  2303,  2304,  2305,  2309,  2310,  2311,  2315,
    2320,  2327,  2328,  2329,  2330,  2331,  2332,  2333,  2334,  2335,
    2336,  2341,  2341,  2346,  2346,  2349,  2355,  2363,  2369,  2379,
    2380,  2388,  2395,  2399,  2409,  2413,  2418,  2423,  2425,  2435,
    2448,  2456,  2469,  2474,  2480,  2485,  2490,  2491,  2497,  2568,
    2574,  2579,  2587,  2587,  2602,  2606,  2613,  2616,  2624,  2635,
    2645,  2651,  2660,  2665,  2673,  2676,  2679,  2684,  2691,  2696,
    2701,  2706,  2716,  2724,  2732,  2737,  2741,  2746,  2750,  2754,
    2761,  2764,  2767,  2771,  2775,  2779,  2783,  2791,  2801,  2806,
    2799,  2821,  2826,  2821,  2843,  2843,  2843,  2846,  2846,  2846,
    2849,  2849,  2849,  2852,  2852,  2852,  2855,  2861,  2867,  2873,
    2883,  2883,  2887,  2891,  2892,  2898,  2899,  2904,  2907,  2911,
    2915,  2916,  2919,  2924,  2930,  2934,  2938,  2941,  2947,  2950,
    2953,  2968,  2971,  2977,  2978,  2979,  2983,  2984,  2985,  2986,
    2987,  2989,  2990,  2991,  2993,  2994,  2998,  2999,  3013,  3017,
    3012,  3025,  3028,  3042,  3046,  3051,  3041,  3071,  3077,  3071,
    3091,  3091,  3093,  3094,  3098,  3098,  3102,  3102,  3107,  3107,
    3114,  3115,  3119,  3119,  3123,  3123,  3128,  3128,  3135,  3139,
    3140,  3141,  3146,  3146,  3149,  3149,  3153,  3153,  3157,  3157,
    3161,  3161,  3166,  3166,  3171,  3171,  3176,  3176,  3181,  3181,
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
    3507,  3505,  3517,  3517,  3517,  3520,  3522,  3520,  3529,  3532,
    3538,  3549,  3549,  3553,  3559,  3559,  3563,  3564,  3575,  3576,
    3578,  3580,  3585,  3585,  3589,  3588,  3595,  3594,  3600,  3600,
    3605,  3605,  3611,  3611,  3616,  3616,  3621,  3621,  3626,  3626,
    3631,  3631,  3639,  3640,  3648,  3649,  3654,  3655,  3664,  3665,
    3672,  3673,  3681,  3682,  3691,  3696,  3701,  3702,  3703,  3707,
    3706,  3717,  3722,  3727,  3727,  3738,  3743,  3744,  3745,  3746,
    3749,  3749,  3755,  3755,  3757,  3760,  3760,  3762,  3766,  3766,
    3769,  3770,  3773,  3773,  3778,  3778,  3781,  3782,  3783,  3784,
    3785,  3786,  3787,  3788,  3789,  3790,  3791,  3792,  3793,  3794,
    3795,  3796,  3797,  3801,  3819,  3819,  3819,  3845,  3856,  3863,
    3869,  3875,  3881,  3892,  3915,  3914,  3931,  3931,  3935,  3936,
    3944,  3945,  3946,  3947,  3954,  3955,  3957,  3958,  3962,  3967,
    3968,  3969,  3970,  3971,  3972,  3973,  3974,  3975,  3976,  3977,
    3980,  3980,  3982,  3982,  3982,  3984,  3988,  3988,  3997,  4002,
    4018,  4024,  3996,  4038,  4052,  4062,  4051,  4075,  4082,  4082,
    4087,  4092,  4097,  4098,  4101,  4101,  4101,  4104,  4104,  4112,
    4118,  4132,  4136,  4149,  4131,  4167,  4167,  4180,  4191,  4190,
    4202,  4198,  4215,  4212,  4225,  4225,  4227,  4228,  4230,  4231,
    4234,  4235,  4236,  4238,  4243,  4248,  4254,  4256,  4257,  4260,
    4261,  4264,  4266,  4275,  4281,  4275,  4292,  4293,  4297,  4297,
    4307,  4307,  4319,  4322,  4326,  4330,  4335,  4339,  4340,  4341,
    4342,  4343,  4347,  4347,  4349,  4349,  4352,  4361,  4409,  4409,
    4412,  4416,  4421,  4462,  4463,  4464,  4467,  4481,  4493,  4493,
    4498,  4499,  4505,  4560,  4565,  4572,  4577,  4585,  4591,  4620,
    4623,  4624,  4665,  4666,  4670,  4671,  4675,  4728,  4732,  4735,
    4741,  4752,  4759,  4767,  4767,  4770,  4771,  4772,  4773,  4774,
    4777,  4780,  4786,  4789,  4793,  4797,  4804,  4809,  4816,  4819,
    4825,  4827,  4827,  4827,  4831,  4845,  4852,  4859,  4862,  4876,
    4883,  4884,  4887,  4888,  4892,  4898,  4903,  4909,  4910,  4915,
    4919,  4919,  4923,  4924,  4927,  4928,  4932,  4940,  4943,  4949,
    4950,  4952,  4954,  4958,  4958,  4959,  4964,  4972,  4973,  4978,
    4979,  4981,  4994,  4996,  4997,  4999,  5002,  5005,  5008,  5011,
    5014,  5017,  5021,  5025,  5029,  5032,  5036,  5039,  5040,  5041,
    5044,  5047,  5050,  5053,  5056,  5059,  5062,  5078,  5086,  5086,
    5088,  5095,  5102,  5117,  5115,  5135,  5140,  5141,  5145,  5146,
    5148,  5149,  5151,  5151,  5159,  5168,  5168,  5178,  5179,  5182,
    5183,  5186,  5190,  5204,  5209,  5214,  5219,  5229,  5229,  5233,
    5236,  5236,  5238,  5248,  5255,  5257,  5261,  5264,  5264,  5268,
    5267,  5271,  5270,  5274,  5273,  5277,  5276,  5280,  5279,  5282,
    5282,  5298,  5297,  5319,  5320,  5321,  5322,  5323,  5324,  5327,
    5327,  5333,  5333,  5336,  5336,  5346,  5347,  5348,  5355,  5367,
    5368,  5371,  5372,  5375,  5378,  5378,  5383,  5387,  5392,  5398,
    5399,  5400,  5404,  5405,  5406,  5407,  5411,  5421,  5423,  5428,
    5431,  5436,  5442,  5449,  5456,  5465,  5472,  5479,  5486,  5493,
    5502,  5502,  5504,  5504,  5507,  5508,  5509,  5510,  5511,  5512,
    5513,  5514,  5515,  5516,  5519,  5519,  5522,  5523,  5524,  5525,
    5528,  5528,  5531,  5531,  5534,  5535,  5536,  5537,  5538,  5539,
    5540,  5541,  5543,  5544,  5545,  5546,  5548,  5549,  5550,  5551,
    5553,  5554,  5555,  5556,  5557,  5558,  5559,  5560,  5564,  5570,
    5578,  5589,  5598,  5609,  5613,  5617,  5623,  5588,  5636,  5639,
    5647,  5659,  5661,  5666,  5674,  5684,  5687,  5691,  5699,  5665,
    5708,  5712,  5716,  5720,  5712,  5730,  5731,  5732,  5733,  5738,
    5740,  5743,  5747,  5750,  5757,  5762,  5763,  5764,  5769,  5770,
    5776,  5776,  5776,  5781,  5781,  5781,  5792,  5793,  5799,  5800,
    5806,  5807,  5812,  5813,  5814,  5818,  5821,  5827,  5830,  5838,
    5839,  5845,  5852,  5855,  5864,  5867,  5870,  5873,  5876,  5879,
    5882,  5889,  5892,  5899,  5902,  5908,  5911,  5918,  5921,  5928,
    5929,  5934,  5938,  5941,  5947,  5950,  5956,  5963,  5964,  5968,
    5974,  5977,  5984,  5985,  5992,  5995,  6000,  6011,  6012,  6013,
    6014,  6015,  6016,  6017,  6018,  6019,  6022,  6025,  6031,  6031,
    6037,  6037,  6048,  6062,  6064,  6062,  6071,  6075,  6081,  6089,
    6099,  6102,  6112,  6134,  6137,  6143,  6146,  6151,  6152,  6158,
    6161,  6170,  6174,  6180,  6190,  6190,  6195,  6195,  6199,  6203,
    6204,  6210,  6211,  6216,  6220,  6227,  6230,  6237,  6241,  6236,
    6253,  6257,  6264,  6268,  6268,  6281,  6285,  6285,  6300,  6302,
    6304,  6306,  6308,  6310,  6312,  6314,  6320,  6330,  6337,  6342,
    6343,  6347,  6349,  6350,  6353,  6354,  6355,  6358,  6363,  6370,
    6371,  6377,  6390,  6390,  6395,  6400,  6405,  6406,  6409,  6410,
    6415,  6420,  6424,  6429,  6430,  6434,  6441,  6445,  6446,  6451,
    6453,  6457,  6458,  6462,  6463,  6464,  6465,  6469,  6470,  6475,
    6476,  6481,  6482,  6487,  6488,  6493,  6498,  6499,  6504,  6505,
    6509,  6510,  6515,  6522,  6527,  6532,  6536,  6537,  6542,  6543,
    6549,  6551,  6556,  6557,  6563,  6566,  6569,  6576,  6578,  6590,
    6595,  6596,  6599,  6601,  6608,  6611,  6617,  6621,  6625,  6628,
    6635,  6642,  6647,  6651,  6652,  6658,  6661,  6672,  6679,  6685,
    6688,  6695,  6702,  6708,  6709,  6715,  6716,  6717,  6720,  6721,
    6726,  6726,  6730,  6738,  6739,  6742,  6745,  6750,  6751,  6756,
    6759,  6765,  6768,  6774,  6777,  6783,  6786,  6793,  6794,  6823,
    6824,  6829,  6830,  6834,  6839,  6842,  6845,  6848,  6854,  6855,
    6859,  6862,  6865,  6866,  6871,  6874,  6877,  6880,  6883,  6886,
    6889,  6895,  6896,  6897,  6898,  6899,  6901,  6903,  6904,  6909,
    6912,  6916,  6922,  6923,  6924,  6925,  6937,  6938,  6939,  6943,
    6944,  6949,  6951,  6952,  6953,  6955,  6956,  6957,  6958,  6960,
    6961,  6963,  6964,  6966,  6967,  6968,  6969,  6971,  6975,  6976,
    6982,  6984,  6985,  6986,  6987,  6992,  6996,  7000,  7004,  7005,
    7009,  7010,  7020,  7028,  7029,  7030,  7034,  7037,  7042,  7047,
    7052,  7060,  7064,  7068,  7069,  7070,  7071,  7073,  7075,  7077,
    7079,  7082,  7085,  7089,  7090,  7094,  7095,  7099,  7099,  7099,
    7099,  7099,  7099,  7100,  7103,  7108,  7108,  7108,  7108,  7108,
    7108,  7110,  7113,  7119,  7119,  7119,  7119,  7119,  7119,  7119,
    7120,  7120,  7120,  7120,  7120,  7120,  7120,  7122,  7123,  7126,
    7135,  7135,  7140,  7140,  7146,  7146,  7151,  7151,  7158,  7159,
    7160,  7163,  7163,  7166,  7167,  7168,  7173,  7176,  7182,  7185,
    7193,  7206,  7207,  7204,  7223,  7233,  7236,  7241,  7253,  7256,
    7260,  7263,  7264,  7270,  7273,  7274,  7283,  7292,  7297,  7298,
    7299,  7300,  7308,  7311,  7317,  7320,  7323,  7329,  7338,  7344,
    7347,  7350,  7353,  7359,  7361,  7363,  7365,  7367,  7369,  7371,
    7373,  7375,  7377,  7379,  7381,  7383,  7385,  7387,  7389,  7391,
    7393,  7395,  7397,  7402,  7403,  7409,  7410,  7413,  7422,  7426,
    7433,  7433,  7437,  7437,  7442,  7442,  7446,  7446,  7450,  7456,
    7456,  7459,  7459,  7465,  7472,  7473,  7474,  7478,  7479,  7482,
    7483,  7487,  7493,  7503,  7504,  7512,  7513,  7514,  7515,  7516,
    7517,  7521,  7522,  7523,  7527,  7527,  7539,  7540,  7544,  7545,
    7546,  7550,  7556,  7641,  7653,  7653,  7657,  7658,  7659,  7660,
    7664,  7665,  7666,  7669,  7682,  7732,  7734,  7736,  7738,  7742,
    7747,  7749,  7751,  7753,  7757,  7760,  7765,  7770,  7774,  7783,
    7784,  7788,  7800,  7803,  7799,  7822,  7822,  7826,  7827,  7830,
    7831,  7832,  7833,  7834,  7835,  7836,  7841,  7842,  7846,  7849,
    7854,  7858,  7863,  7867,  7872,  7876,  7879,  7883,  7886,  7891,
    7895,  7906,  7912,  7912,  7913,  7914,  7921,  7930,  7930,  7932,
    7933,  7934,  7935,  7936,  7937,  7938,  7939,  7940,  7941,  7942,
    7943,  7944,  7945,  7946,  7947,  7948,  7949,  7950,  7951,  7952,
    7953,  7954,  7955,  7956,  7957,  7958,  7959,  7960,  7961,  7962,
    7963,  7964,  7965,  7966,  7967,  7968,  7969,  7970,  7971,  7972,
    7973,  7974,  7975,  7976,  7977,  7978,  7979,  7980,  7981,  7982,
    7983,  7984,  7985,  7986,  7987,  7988,  7989,  7990,  7991,  7992,
    7993,  7994,  7995,  7996,  7997,  7998,  7999,  8000,  8001,  8002,
    8003,  8004,  8005,  8006,  8007,  8008,  8009,  8010,  8011,  8012,
    8013,  8014,  8015
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
  "KW_CEND", "USER_DTYPE", "SQL_TEXT", "ALTER_TABLE", "NEWFORMATSHARED", 
  "CREATE_DATABASE", "IMPORT_LEGACY_FUNCTION", "ADD_CONSTRAINT", 
  "DROP_CONSTRAINT", "AS_STATIC", "NOT_FIELD_TOUCHED", "LOCAL_FUNCTION", 
  "EVERY_ROW", "ELIF", "DOUBLE_PRECISION", "COUNT_MULTIPLY", 
  "WAIT_FOR_KEY", "AT_TERMINATION_CALL", "TO_MAIN_CAPTION", "CLEARSTAT", 
  "TO_MENUITEM", "ID_TO_INT", "TO_STATUSBOX", "ASCII_HEIGHT_ALL", 
  "ASCII_WIDTH_ALL", "IMPORT_DATATYPE", "UP_BY", "PAGE_TRAILER_SIZE", 
  "PAGE_HEADER_SIZE", "FIRST_PAGE_HEADER_SIZE", "BYTES_USE_AS_IMAGE", 
  "BYTES_USE_AS_ASCII", "DOWN_BY", "CLOSE_STATUSBOX", "MODIFY_NEXT_SIZE", 
  "LOCK_MODE_PAGE", "LOCK_MODE_ROW", "TO_PIPE", "TO_PRINTER", "STATUSBOX", 
  "CONNECT_TO", "FORMHANDLER_INPUT", "UNITS_YEAR", "UNITS_MONTH", 
  "UNITS_DAY", "UNITS_HOUR", "UNITS_MINUTE", "UNITS_SECOND", 
  "NO_NEW_LINES", "FIELDTOWIDGET", "WITH_HOLD", "SHOW_MENU", "CWIS", 
  "CREATE_IDX", "FORM_IS_COMPILED", "PDF_REPORT", "IMPORT_FUNCTION", 
  "PROMPT_MANY", "POINTS", "MM", "INCHES", "PREPEND", "MEMBER_OF", 
  "MEMBER_FUNCTION", "APPEND", "TEMPLATE", "END_TEMPLATE", "SQLSICS", 
  "CREATE_SCHEMA", "SQLSIRR", "UPDATESTATS_T", "SQLSICR", 
  "WHENEVER_SQLSUCCESS", "WHENEVER_SQLWARNING", "START_EXTERN", 
  "WHENEVER_ANY_ERROR", "WHENEVER_NOT_FOUND", "CONTINUE_CONSTRUCT", 
  "FOUNCONSTR", "SQLSIDR", "WHENEVER_SQLERROR", "CREATE_TEMP_TABLE", 
  "CURRENT_WINDOW_IS", "FIRST_PAGE_HEADER", "ORDER_EXTERNAL_BY", 
  "SCROLL_CURSOR_FOR", "SCROLL_CURSOR", "SQL_INTERRUPT_OFF", 
  "STOP_ALL_EXTERNAL", "WITH_CHECK_OPTION", "WITH_GRANT_OPTION", 
  "SQLSLMNW", "ADDCONSTUNIQ", "CONTINUE_DISPLAY", "CONTINUE_FOREACH", 
  "OUTPUT_TO_REPORT", "SQL_INTERRUPT_ON", "WHENEVER_SUCCESS", 
  "WHENEVER_WARNING", "WHERE_CURRENT_OF", "WITHOUT_DEFAULTS", "FOCONSTR", 
  "SCALED_BY", "CONTINUE_PROMPT", "PDF_FUNCTION", "DEFER_INTERRUPT", 
  "DISPLAY_BY_NAME", "NOT_NULL_UNIQUE", "SKIP_TO_TOP", "TOP_OF_PAGE", 
  "SKIP_TO", "SKIP_BY", "WITHOUT_WAITING", "BEFCONSTRUCT", "SQLSLMW", 
  "WHENEVER_ERROR_CONTINUE", "WHENEVER_ERROR", "AFTCONSTRUCT", 
  "ALL_PRIVILEGES", "CLOSE_DATABASE", "CONTINUE_INPUT", "CONTINUE_WHILE", 
  "CREATE_SYNONYM", "DROP_TABLE", "EXIT_CONSTRUCT", "INEXCLUSIVE", 
  "REPORT_TO_PRINTER", "REPORT_TO_PIPE", "SET_SESSION_TO", "UPDATESTATS", 
  "WITHOUT_HEAD", "CLEARSCR", "WITH_B_LOG", "AUTHORIZATION", 
  "BOTTOM_MARGIN", "CLOSE_SESSION", "CONTINUE_CASE", "CONTINUE_MENU", 
  "DISPLAY_ARRAY", "END_SQL", "DOLLAR", "END_CONSTRUCT", "FIELD_TOUCHED", 
  "FINISH_REPORT", "INFACC", "INPUT_NO_WRAP", "LOCKMODEPAGE", "SETPMOFF", 
  "UNCONSTRAINED", "PAGE_TRAILER", "SETPMON", "BEFGROUP", "CLOSE_WINDOW", 
  "COMMENT_LINE", "CONTINUE_FOR", "CREATE_DB", "CREATE_TABLE", 
  "DEFAULT_NULL", "DELETE_USING", "DISPLAY_FORM", "END_FUNCTION", 
  "EXIT_DISPLAY", "EXIT_FOREACH", "EXIT_PROGRAM", "INFCOLS", 
  "LOCKMODEROW", "ON_EVERY_ROW", "OPEN_SESSION", "RIGHT_MARGIN", 
  "SELECT_USING", "START_REPORT", "UNLOCK_TABLE", "UPDATE_USING", 
  "ACL_BUILTIN", "AFTGROUP", "INFIDX", "INFSTAT", "LEFT_MARGIN", 
  "PAGE_HEADER", "ROLLBACK_W", "SET_SESSION", "SQLSEOFF", "WITH_A_LOG", 
  "BEFDISP", "BEFORE_MENU", "CREATE_VIEW", "DEFINE_TYPE", "DELETE_FROM", 
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
  "numeric_time_unit_small", "numeric_time_unit_big", "for_cmd", "@66", 
  "@67", "for_step", "foreach_cmd", "@68", "@69", "@70", 
  "formhandler_def", "@71", "@72", "op_input_section", "op_bef_ev_list", 
  "bef_ev_list", "bef_ev", "@73", "@74", "op_aft_ev_list", "aft_ev_list", 
  "aft_ev", "@75", "@76", "input_section", "input_sub_section", 
  "in_variable_list", "in_id_list", "in_bn_variable_list", "field_ops", 
  "field_op", "@77", "@78", "@79", "@80", "@81", "free_cmd", "line_no", 
  "file_name", "a_number", "coords", "display_coords", "field_name", 
  "cursor_name", "fetch_cursor_name", "win_name", "open_win_name", 
  "form_name", "open_form_name", "opt_help_no", "identifier", 
  "ident_or_var", "ident_p2", "var_or_string", "setident", "unsetident", 
  "field_name2", "cvariable", "real_number", "reserved_word", "goto_cmd", 
  "check_menu_cmd", "menu_item_list", "menu_item", "uncheck_menu_cmd", 
  "disable_cmd", "enable_cmd", "msg_box_cmd", "@82", "op_disable_msg", 
  "gm_disable_msg", "op_returning_msg", "gm_returning_msg", "op_caption", 
  "gm_caption", "op_icon", "gm_icon", "op_buttons", "gm_buttons", 
  "op_def_but", "if_cmd", "@83", "op_else", "@84", "@85", "@86", 
  "import_m", "module_import", "init_cmd", "@87", "init_tab_list", 
  "init_tab", "end_input", "opt_defs", "field_commands", "field_command", 
  "@88", "@89", "@90", "@91", "@92", "@93", "@94", "@95", "@96", 
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
  "arr_subscripts", "num_list", "num_list_element", "let_variable", 
  "let_var", "let_var_dot", "let_array_r_variable", "op_param_var_list", 
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
  "column_name_specific", "correlation_name", "literal", "curr_v_clause", 
  "curr_clause", "cur_part", "cur_v_part", "s_curr_v", "e_curr_v", 
  "s_curr", "e_curr", "dbase_name", "flush_cmd", "declare_cmd", "@165", 
  "@166", "@167", "@168", "curs_forupdate", "cur_update_list", "colident", 
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
  "var_ident", "var2", "var3", "aft_dot", "var_ident_ibind_ss", 
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
       0,   256,  1634,  1635,  1636,  1551,  1591,  1546,  1482,  1360,
    1468,  1464,  1378,  1541,  1277,  1335,  1409,  1577,  1564,  1497,
    1469,  1565,  1342,  1637,  1638,  1639,  1640,  1641,  1642,  1643,
    1644,  1645,  1646,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
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
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  1285,  1286,  1287,
    1288,  1289,  1290,  1291,  1292,  1293,  1294,  1295,  1296,  1297,
    1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,
    1328,  1329,  1330,  1331,  1332,  1333,  1334,  1336,  1337,  1338,
    1339,  1340,  1341,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,  1358,  1359,
    1361,  1362,  1363,  1364,  1365,  1366,  1367,  1368,  1369,  1370,
    1371,  1372,  1373,  1374,  1375,  1376,  1377,  1379,  1380,  1381,
    1382,  1383,  1384,  1385,  1386,  1387,  1388,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1400,  1401,
    1402,  1403,  1404,  1405,  1406,  1407,  1408,  1410,  1411,  1412,
    1413,  1414,  1415,  1416,  1417,  1418,  1419,  1420,  1421,  1422,
    1423,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,  1432,
    1433,  1434,  1435,  1436,  1437,  1438,  1439,  1440,  1441,  1442,
    1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,  1460,  1461,  1462,
    1463,  1465,  1466,  1467,  1470,  1471,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1479,  1480,  1481,  1483,  1484,  1485,  1486,
    1487,  1488,  1489,  1490,  1491,  1492,  1493,  1494,  1495,  1496,
    1498,  1499,  1500,  1501,  1502,  1503,  1504,  1505,  1506,  1507,
    1508,  1509,  1510,  1511,  1512,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1526,  1527,
    1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,  1537,
    1538,  1539,  1540,  1542,  1543,  1544,  1545,  1547,  1548,  1549,
    1550,  1552,  1553,  1554,  1555,  1556,  1557,  1558,  1559,  1560,
    1561,  1562,  1563,  1566,  1567,  1568,  1569,  1570,  1571,  1572,
    1573,  1574,  1575,  1576,  1578,  1579,  1580,  1581,  1582,  1583,
    1584,  1585,  1586,  1587,  1588,  1589,  1590,  1592,  1593,  1594,
    1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,  1603,  1604,
    1605,  1606,  1607,  1608,  1609,  1610,  1611,  1612,  1613,  1614,
    1615,  1616,  1617,  1618,  1619,  1620,  1621,  1622,  1623,  1624,
    1625,  1626,  1627,  1628,  1629,  1630,  1631,  1632,  1633
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short yyr1[] =
{
       0,   649,   650,   651,   652,   653,   654,   654,   655,   655,
     656,   657,   657,   657,   657,   657,   658,   658,   658,   658,
     658,   659,   659,   660,   660,   662,   661,   661,   663,   663,
     664,   664,   664,   664,   664,   664,   664,   664,   664,   664,
     664,   664,   664,   664,   664,   664,   665,   665,   667,   666,
     668,   668,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   670,   671,   672,   671,   671,   671,   671,   671,   673,
     674,   671,   675,   676,   677,   671,   678,   679,   671,   680,
     681,   671,   682,   683,   684,   671,   685,   685,   686,   686,
     686,   687,   687,   688,   688,   689,   690,   690,   691,   691,
     693,   692,   694,   692,   695,   695,   696,   696,   697,   698,
     699,   698,   700,   701,   700,   703,   702,   705,   704,   706,
     706,   706,   706,   706,   706,   707,   708,   708,   709,   709,
     710,   711,   711,   712,   713,   715,   716,   714,   717,   717,
     718,   718,   719,   719,   720,   720,   720,   721,   721,   723,
     722,   724,   722,   725,   722,   726,   722,   727,   722,   728,
     728,   729,   729,   730,   730,   730,   730,   730,   730,   731,
     732,   732,   733,   733,   734,   734,   735,   735,   737,   738,
     736,   736,   736,   739,   739,   741,   740,   742,   742,   742,
     742,   742,   743,   742,   744,   744,   744,   744,   745,   746,
     746,   747,   747,   749,   748,   750,   748,   751,   751,   752,
     752,   753,   754,   754,   754,   755,   757,   756,   758,   756,
     759,   756,   760,   760,   761,   762,   763,   763,   765,   766,
     764,   767,   767,   767,   767,   767,   767,   767,   767,   767,
     767,   767,   767,   767,   767,   767,   767,   767,   767,   767,
     767,   767,   767,   767,   767,   767,   767,   767,   767,   768,
     769,   770,   771,   771,   772,   774,   773,   775,   775,   775,
     775,   775,   775,   775,   777,   776,   778,   778,   779,   779,
     780,   782,   781,   783,   783,   783,   783,   783,   783,   783,
     784,   785,   785,   787,   786,   788,   788,   788,   788,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   789,   791,
     790,   792,   790,   794,   793,   795,   793,   796,   796,   797,
     798,   798,   799,   800,   800,   800,   800,   800,   800,   800,
     800,   801,   802,   803,   805,   806,   804,   807,   807,   808,
     809,   809,   810,   810,   812,   811,   813,   811,   814,   811,
     815,   815,   816,   816,   816,   816,   816,   816,   816,   816,
     816,   817,   817,   817,   817,   817,   817,   817,   817,   818,
     818,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   820,   820,   820,   820,   820,   820,   820,   820,   820,
     820,   821,   821,   822,   822,   823,   823,   824,   824,   825,
     825,   826,   827,   827,   828,   828,   828,   828,   828,   828,
     829,   829,   830,   830,   830,   830,   831,   831,   832,   833,
     833,   833,   834,   833,   835,   835,   836,   836,   837,   837,
     837,   837,   838,   838,   839,   839,   839,   839,   839,   839,
     839,   839,   840,   841,   842,   842,   842,   842,   842,   842,
     843,   843,   843,   843,   843,   843,   843,   844,   846,   847,
     845,   848,   849,   845,   851,   852,   850,   853,   854,   850,
     855,   856,   850,   857,   858,   850,   850,   850,   850,   850,
     859,   859,   860,   861,   861,   861,   861,   861,   861,   861,
     861,   861,   862,   862,   863,   863,   863,   863,   864,   864,
     864,   865,   865,   866,   866,   866,   867,   867,   867,   867,
     867,   867,   867,   867,   867,   867,   868,   868,   870,   871,
     869,   872,   872,   874,   875,   876,   873,   878,   879,   877,
     880,   880,   881,   881,   882,   882,   884,   883,   885,   883,
     886,   886,   887,   887,   889,   888,   890,   888,   891,   892,
     892,   892,   893,   893,   894,   894,   895,   895,   896,   896,
     898,   897,   899,   897,   900,   897,   901,   897,   902,   897,
     903,   904,   904,   904,   904,   904,   904,   905,   905,   906,
     907,   908,   909,   909,   909,   909,   909,   909,   909,   909,
     910,   911,   912,   913,   914,   915,   916,   916,   917,   918,
     919,   919,   920,   920,   921,   922,   923,   923,   923,   923,
     923,   923,   924,   925,   925,   926,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   926,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   926,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   926,   926,   926,   926,   926,
     926,   926,   926,   926,   926,   926,   926,   926,   927,   928,
     929,   929,   930,   931,   932,   932,   932,   933,   933,   933,
     935,   934,   936,   936,   937,   937,   938,   938,   939,   940,
     940,   941,   942,   942,   943,   944,   944,   945,   946,   946,
     948,   947,   949,   950,   949,   951,   952,   949,   953,   953,
     954,   956,   955,   955,   957,   957,   958,   958,   959,   959,
     960,   960,   961,   961,   963,   962,   964,   962,   965,   962,
     966,   962,   967,   962,   968,   962,   969,   962,   970,   962,
     971,   962,   972,   972,   973,   973,   974,   974,   975,   975,
     976,   976,   977,   977,   978,   979,   980,   980,   980,   982,
     981,   983,   983,   984,   983,   985,   986,   986,   986,   986,
     987,   987,   989,   988,   988,   991,   990,   992,   994,   993,
     995,   995,   996,   996,   998,   997,   999,   999,   999,   999,
     999,   999,   999,   999,   999,   999,   999,   999,   999,   999,
     999,   999,   999,  1000,  1002,  1003,  1001,  1004,  1004,  1005,
    1006,  1007,  1008,  1008,  1010,  1009,  1011,  1011,  1012,  1012,
    1013,  1013,  1013,  1013,  1014,  1014,  1015,  1015,  1016,  1017,
    1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,  1017,
    1018,  1018,  1019,  1019,  1019,  1020,  1021,  1021,  1023,  1024,
    1025,  1026,  1022,  1027,  1029,  1030,  1028,  1031,  1032,  1032,
    1033,  1034,  1035,  1035,  1036,  1036,  1036,  1038,  1037,  1039,
    1039,  1041,  1042,  1043,  1040,  1045,  1044,  1046,  1048,  1047,
    1049,  1047,  1050,  1047,  1051,  1051,  1052,  1052,  1053,  1053,
    1054,  1054,  1054,  1055,  1056,  1057,  1058,  1058,  1058,  1059,
    1059,  1060,  1060,  1062,  1063,  1061,  1064,  1064,  1066,  1065,
    1067,  1065,  1068,  1069,  1069,  1069,  1069,  1070,  1070,  1070,
    1070,  1070,  1072,  1071,  1073,  1073,  1074,  1075,  1076,  1076,
    1077,  1078,  1078,  1078,  1078,  1078,  1079,  1080,  1081,  1081,
    1082,  1082,  1083,  1084,  1084,  1085,  1085,  1086,  1087,  1088,
    1088,  1088,  1088,  1088,  1089,  1089,  1090,  1091,  1091,  1092,
    1092,  1093,  1093,  1094,  1094,  1095,  1095,  1095,  1095,  1095,
    1096,  1096,  1097,  1097,  1098,  1098,  1099,  1100,  1101,  1101,
    1102,  1103,  1103,  1103,  1104,  1105,  1105,  1106,  1106,  1107,
    1108,  1108,  1109,  1109,  1110,  1111,  1112,  1113,  1113,  1114,
    1115,  1115,  1116,  1116,  1117,  1117,  1118,  1119,  1119,  1120,
    1120,  1120,  1120,  1121,  1121,  1121,  1122,  1123,  1123,  1124,
    1124,  1124,  1125,  1126,  1126,  1127,  1127,  1127,  1127,  1127,
    1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,  1127,
    1127,  1127,  1127,  1127,  1127,  1127,  1127,  1128,  1129,  1129,
    1130,  1130,  1131,  1133,  1132,  1134,  1135,  1135,  1136,  1136,
    1137,  1137,  1139,  1138,  1140,  1142,  1141,  1143,  1143,  1144,
    1144,  1145,  1145,  1146,  1146,  1146,  1146,  1147,  1147,  1148,
    1149,  1149,  1150,  1151,  1152,  1153,  1153,  1154,  1154,  1156,
    1155,  1157,  1155,  1158,  1155,  1159,  1155,  1160,  1155,  1161,
    1155,  1162,  1155,  1163,  1163,  1163,  1163,  1163,  1163,  1165,
    1164,  1166,  1166,  1168,  1167,  1167,  1167,  1167,  1167,  1169,
    1169,  1170,  1170,  1171,  1172,  1172,  1173,  1174,  1175,  1176,
    1176,  1176,  1177,  1177,  1177,  1177,  1178,  1179,  1179,  1180,
    1180,  1181,  1182,  1182,  1182,  1182,  1182,  1182,  1182,  1182,
    1183,  1183,  1184,  1184,  1185,  1185,  1185,  1185,  1185,  1185,
    1185,  1185,  1185,  1185,  1186,  1186,  1187,  1187,  1187,  1187,
    1188,  1188,  1189,  1189,  1190,  1190,  1190,  1190,  1190,  1190,
    1190,  1190,  1190,  1190,  1190,  1190,  1190,  1190,  1190,  1190,
    1190,  1190,  1190,  1190,  1190,  1190,  1190,  1190,  1191,  1191,
    1191,  1193,  1194,  1195,  1196,  1197,  1198,  1192,  1199,  1199,
    1200,  1201,  1201,  1203,  1204,  1205,  1206,  1207,  1208,  1202,
    1209,  1211,  1212,  1213,  1210,  1214,  1214,  1214,  1214,  1215,
    1215,  1215,  1215,  1215,  1216,  1217,  1217,  1217,  1218,  1218,
    1220,  1221,  1219,  1222,  1223,  1219,  1224,  1224,  1225,  1225,
    1226,  1226,  1227,  1227,  1227,  1228,  1228,  1229,  1229,  1230,
    1230,  1231,  1232,  1232,  1233,  1233,  1233,  1233,  1233,  1233,
    1233,  1234,  1234,  1235,  1235,  1236,  1236,  1237,  1237,  1238,
    1238,  1239,  1240,  1240,  1241,  1241,  1242,  1243,  1243,  1244,
    1245,  1245,  1246,  1246,  1247,  1247,  1248,  1249,  1249,  1249,
    1249,  1249,  1249,  1249,  1249,  1249,  1249,  1249,  1250,  1250,
    1251,  1251,  1252,  1254,  1255,  1253,  1256,  1256,  1256,  1257,
    1257,  1257,  1257,  1258,  1258,  1259,  1260,  1261,  1261,  1262,
    1262,  1263,  1263,  1264,  1266,  1265,  1268,  1267,  1267,  1269,
    1269,  1270,  1270,  1271,  1271,  1272,  1272,  1274,  1275,  1273,
    1276,  1276,  1277,  1278,  1277,  1279,  1280,  1279,  1281,  1281,
    1281,  1281,  1281,  1281,  1281,  1281,  1282,  1283,  1284,  1285,
    1285,  1286,  1287,  1287,  1288,  1288,  1288,  1289,  1290,  1291,
    1291,  1292,  1294,  1293,  1295,  1295,  1295,  1295,  1295,  1295,
    1295,  1295,  1295,  1295,  1295,  1295,  1296,  1297,  1297,  1298,
    1298,  1299,  1299,  1300,  1300,  1300,  1300,  1301,  1301,  1302,
    1302,  1303,  1303,  1304,  1304,  1305,  1306,  1306,  1307,  1307,
    1308,  1308,  1309,  1310,  1311,  1312,  1313,  1313,  1314,  1314,
    1315,  1315,  1316,  1316,  1317,  1317,  1317,  1318,  1318,  1319,
    1320,  1320,  1321,  1321,  1322,  1322,  1323,  1323,  1323,  1323,
    1324,  1325,  1326,  1327,  1327,  1328,  1328,  1329,  1330,  1331,
    1331,  1332,  1333,  1334,  1334,  1335,  1335,  1335,  1336,  1336,
    1337,  1337,  1338,  1339,  1339,  1340,  1340,  1341,  1341,  1342,
    1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,  1346,  1347,
    1347,  1348,  1348,  1349,  1350,  1350,  1350,  1350,  1351,  1351,
    1352,  1352,  1353,  1353,  1354,  1354,  1354,  1354,  1354,  1354,
    1354,  1355,  1355,  1355,  1355,  1355,  1355,  1355,  1355,  1356,
    1356,  1356,  1357,  1357,  1357,  1357,  1358,  1358,  1358,  1359,
    1359,  1360,  1360,  1360,  1360,  1360,  1360,  1360,  1360,  1360,
    1360,  1360,  1360,  1360,  1360,  1360,  1360,  1360,  1361,  1361,
    1362,  1362,  1362,  1362,  1362,  1363,  1364,  1365,  1366,  1366,
    1366,  1366,  1367,  1368,  1368,  1368,  1369,  1369,  1370,  1370,
    1370,  1371,  1372,  1372,  1372,  1372,  1372,  1372,  1372,  1372,
    1372,  1373,  1374,  1375,  1375,  1376,  1376,  1377,  1377,  1377,
    1377,  1377,  1377,  1377,  1377,  1378,  1378,  1378,  1378,  1378,
    1378,  1378,  1378,  1379,  1379,  1379,  1379,  1379,  1379,  1379,
    1380,  1380,  1380,  1380,  1380,  1380,  1380,  1381,  1381,  1382,
    1384,  1383,  1385,  1383,  1386,  1383,  1387,  1383,  1388,  1388,
    1388,  1389,  1389,  1390,  1390,  1390,  1391,  1391,  1392,  1392,
    1393,  1395,  1396,  1394,  1397,  1398,  1398,  1399,  1400,  1400,
    1400,  1400,  1400,  1401,  1402,  1402,  1403,  1404,  1405,  1405,
    1405,  1405,  1406,  1406,  1407,  1407,  1407,  1408,  1409,  1409,
    1409,  1409,  1409,  1410,  1410,  1410,  1410,  1410,  1410,  1410,
    1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,  1410,
    1410,  1410,  1410,  1411,  1411,  1412,  1412,  1413,  1414,  1414,
    1415,  1415,  1416,  1416,  1417,  1417,  1418,  1418,  1419,  1420,
    1420,  1421,  1421,  1422,  1423,  1423,  1423,  1424,  1424,  1425,
    1426,  1427,  1428,  1429,  1429,  1430,  1430,  1430,  1430,  1430,
    1430,  1431,  1431,  1431,  1433,  1432,  1434,  1434,  1435,  1435,
    1435,  1436,  1437,  1438,  1439,  1439,  1440,  1440,  1440,  1440,
    1441,  1441,  1441,  1442,  1442,  1443,  1443,  1443,  1443,  1443,
    1443,  1443,  1443,  1443,  1444,  1444,  1444,  1444,  1444,  1445,
    1445,  1446,  1448,  1449,  1447,  1450,  1450,  1451,  1451,  1452,
    1452,  1452,  1452,  1452,  1452,  1452,  1453,  1453,  1454,  1454,
    1455,  1455,  1456,  1456,  1457,  1457,  1458,  1459,  1460,  1461,
    1461,  1462,  1463,  1463,  1464,  1465,  1465,  1467,  1466,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,  1468,
    1468,  1468,  1468
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
       6,     3,     5,     5,     3,     1,     1,     3,     0,     0,
      11,     0,     2,     0,     0,     0,     8,     0,     0,    10,
       0,     1,     0,     1,     1,     2,     0,     3,     0,     3,
       0,     1,     1,     2,     0,     3,     0,     3,     3,     1,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       0,     3,     0,     3,     0,     4,     0,     4,     0,     4,
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
       3,     2,     5,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     2,     3,     6,     1,     3,     1,     1,     1,
       4,     7,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       2,     0,     1,     1,     4,     1,     3,     1,     3,     7,
       0,     7,     0,     6,     3,     1,     3,     1,     2,     5,
       0,     7,     0,     2,     0,     1,     5,     2,     5,     0,
       5,     6,     4,     0,     1,     1,     4,     0,     2,     0,
       5,     4,     2,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     5,     1,     1,
       2,     4,     1,     0,    10,     5,     0,     1,     0,     2,
       1,     2,     0,     3,     1,     0,     4,     0,     2,     1,
       3,     1,     1,     3,     4,     4,     2,     1,     1,     1,
       0,     1,     7,     2,     2,     2,     2,     1,     2,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     3,     0,
       4,     0,     4,     1,     1,     1,     1,     1,     1,     0,
       4,     0,     1,     0,     4,     1,     2,     2,     2,     0,
       1,     1,     2,     2,     0,     2,     3,     3,     5,     0,
       2,     4,     1,     1,     1,     1,     1,     0,     1,     1,
       3,     2,     5,     2,     5,     5,     5,     5,     5,     5,
       0,     2,     1,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       1,     1,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     0,     3,
       2,     0,     0,     0,     0,     0,     0,    15,     0,     2,
       2,     0,     1,     0,     0,     0,     0,     0,     0,    15,
       2,     0,     0,     0,    10,     0,     1,     3,     3,     2,
       4,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       0,     0,     7,     0,     0,     8,     3,     2,     0,     1,
       1,     3,     2,     2,     1,     1,     3,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     1,     3,     1,     3,     2,     4,     1,
       3,     1,     2,     4,     1,     3,     1,     1,     1,     2,
       2,     4,     2,     4,     1,     3,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     6,     6,     0,     1,
       0,     1,     2,     0,     0,     7,     0,     2,     2,     7,
       1,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     0,     5,     0,     5,     1,     0,
       3,     1,     3,     1,     3,     1,     1,     0,     0,     5,
       2,     1,     0,     0,     3,     0,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     3,     3,     1,
       3,     2,     1,     1,     0,     1,     1,     1,     1,     0,
       1,     3,     0,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     0,     1,     1,
       1,     1,     3,     1,     1,     1,     2,     0,     3,     1,
       3,     1,     3,     1,     1,     6,     0,     3,     1,     3,
       0,     1,     4,     5,     2,     1,     1,     4,     1,     3,
       4,     4,     1,     3,     1,     1,     1,     2,     1,     4,
       0,     1,     0,     1,     1,     2,     1,     1,     1,     4,
       3,     1,     1,     1,     2,     1,     1,     2,     2,     1,
       3,     2,     2,     1,     3,     1,     2,     4,     1,     2,
       1,     3,     4,     0,     1,     0,     1,     0,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     2,     2,     0,
       2,     1,     1,     1,     5,     3,     5,     3,     1,     3,
       1,     1,     0,     1,     3,     3,     3,     6,     4,     4,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     1,     5,     5,     1,     1,     1,     4,     1,
       4,     1,     7,     1,     1,     1,     4,     6,     0,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     0,     3,     5,     1,     2,     2,     5,
       4,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       1,     2,     2,     0,     3,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     8,     0,     9,     0,     7,     0,     9,     0,     1,
       2,     1,     3,     1,     3,     5,     1,     1,     1,     1,
       2,     0,     0,     8,     5,     1,     1,     7,     0,     3,
       1,     3,     4,     1,     0,     2,     5,     7,     0,     1,
       1,     1,     1,     3,     1,     2,     2,     1,     1,     1,
       1,     2,     4,     3,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     5,     5,     5,     5,     5,     4,
       4,     3,     4,     1,     3,     0,     1,     5,     7,     5,
       0,     2,     1,     1,     0,     3,     1,     3,     1,     1,
       1,     0,     3,     1,     1,     1,     1,     4,     6,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     0,     4,     1,     2,     1,     1,
       1,     2,     2,     1,     2,     1,     1,     1,     3,     5,
       1,     1,     1,     1,     3,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     1,     3,     2,     1,     2,     1,
       2,     1,     0,     0,     6,     0,     2,     0,     1,     1,
       2,     2,     1,     1,     4,     3,     1,     3,     1,     2,
       5,     2,     2,     5,     0,     2,     1,     1,     2,     6,
       6,     1,     0,     1,     2,     1,     2,     0,     2,     1,
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
     816,     0,   614,     0,     0,     0,     0,     0,     0,     0,
    1758,     0,   614,   614,   867,   178,   840,   845,   176,   181,
     820,     0,   814,   817,   818,   821,   823,   866,   822,   861,
     862,   864,   182,   133,   130,     0,   126,   128,   127,   131,
     710,     0,  1764,   614,   614,  1767,     0,  1763,  1760,  1757,
    1755,  1756,  1762,  1761,  1759,   293,  1618,  1617,   860,   174,
     185,   177,   182,     1,   824,   819,   865,   863,   841,   125,
     129,   132,  1801,   615,  1771,  1768,   614,  1769,  1766,   614,
       0,   587,   614,     0,   175,   870,   934,   588,   868,   622,
     927,   614,   928,   935,   933,   185,   179,   198,   614,   183,
     199,   228,   614,   847,  1213,   614,   614,   846,   134,  1201,
     854,   614,   614,   837,   839,   836,   838,   815,   825,   826,
     848,   829,   830,   831,   834,   832,   833,   835,   608,  1770,
    1765,     0,   929,   869,   614,   614,   942,   940,   941,   931,
       0,   291,   185,  1137,   192,   186,   185,   191,   225,     0,
     709,   614,     0,     0,   614,   174,   537,   903,   827,   614,
     325,   311,   201,   262,   281,   302,   304,   301,     0,   323,
       0,   310,   303,   307,   313,   297,   312,   185,   314,   294,
     317,   295,   296,   939,   938,     0,    21,    22,    13,   614,
     947,     0,    15,     0,   945,   614,   930,   292,   614,   184,
    1138,   180,     0,   198,   200,   258,   252,   253,   241,   218,
     249,   201,   220,   262,   281,   239,   242,   237,     0,   216,
       0,   248,   240,   245,   251,   233,   250,   185,   254,   185,
     231,   232,   229,   257,     0,     0,   614,     0,   855,   174,
     174,     0,   614,   202,     0,   315,     0,     0,   316,     0,
       0,     0,     0,   614,     0,     0,     0,   260,     0,   936,
       0,    16,    17,    19,    18,    20,   614,    14,   614,   943,
       0,   623,   187,   190,     0,   188,   189,     0,   195,   194,
     193,   196,   185,     0,   185,   255,   256,     0,     0,   185,
       0,     0,     0,     0,   238,   226,  1214,     0,     0,  1202,
    1807,   538,   904,   849,     0,   207,   208,     0,   274,   276,
     271,   272,   268,   270,   267,   269,   266,     0,   276,   287,
     288,   284,   286,   283,   285,   278,     0,     0,     0,   327,
       0,   330,   332,   215,     0,   214,     0,     0,   185,    11,
      12,   946,   614,   932,   624,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   185,   227,   230,   614,   708,
     871,   614,     0,  1805,  1807,  1137,  1711,   842,     0,   614,
       0,     0,   263,     0,     0,   273,   290,   264,   289,     0,
     282,     0,   305,     0,   299,   614,   324,   614,   329,   319,
       0,     0,   308,   298,   261,   318,     0,     0,     0,     0,
       0,   243,     0,   235,   217,   203,     0,   246,   234,   259,
     963,     0,   958,   959,   614,     0,   856,  1806,  1804,   614,
     614,   614,   614,   614,   614,   614,  1788,   614,  1303,  1302,
     614,  1304,   614,   375,  1301,  1243,   614,     5,  1300,   376,
     373,   614,   378,   172,   467,  1115,     0,     0,  1310,   122,
     372,   371,  1235,   366,   614,  1260,  1779,   614,   377,   344,
     614,     3,     2,   614,   374,  1240,   614,   614,   367,   364,
     379,   614,   614,   614,   614,   614,  1298,   370,   614,   614,
     614,   614,   614,   614,   614,   614,  1297,   614,   614,   614,
     173,  1237,   363,   362,   614,   614,  1783,  1782,   614,   614,
     614,   135,  1236,   369,   368,   614,   614,   365,   922,   467,
     614,   533,     0,   614,   614,   467,   614,   614,   614,   467,
     803,  1211,   614,   614,  1119,   614,  1772,   614,   102,   614,
     614,   875,   614,   614,   614,   614,   804,   614,   614,  1734,
     614,     0,   614,   614,   614,   614,   614,   614,   614,   680,
     614,   614,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,
    1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,   913,
    1856,  1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,
    1866,  1867,  1868,  1869,  1870,  1871,  1106,  1108,  1103,  1105,
    1104,  1107,  1872,  1873,  1234,  1874,  1239,  1238,  1875,  1876,
    1877,  1878,  1879,  1880,  1881,  1882,  1883,  1884,  1382,  1885,
    1886,  1887,  1888,  1889,  1890,  1891,  1892,  1808,   843,   542,
     844,   614,   908,     0,   906,     0,   326,   209,   210,     0,
     275,   280,     0,     0,     0,     0,   328,   331,     0,   213,
       0,   944,   219,     0,   185,     0,     0,     0,     0,   614,
    1215,   614,     0,  1203,     0,  1247,     0,   828,  1781,   602,
     121,     0,   614,  1747,  1746,  1017,  1743,  1745,  1796,     0,
    1254,     0,  1250,  1259,     7,     0,     6,   614,  1789,  1079,
    1080,   614,  1171,  1170,  1118,  1169,  1117,   614,   614,   422,
     424,     0,  1208,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,  1585,     0,     0,     0,   416,   614,   614,
       0,     0,   415,   614,     0,   432,     0,   503,     0,     0,
       0,     0,     0,   614,     0,   411,  1311,     0,   382,   381,
     388,   428,   425,   383,   501,   493,   384,   386,   500,   387,
     934,   423,   426,   431,  1299,   502,  1713,  1305,   123,   614,
    1083,   120,   614,   810,    23,   604,   380,     0,   809,  1076,
     811,     0,  1309,   897,   896,   899,   895,   898,  1798,     0,
     893,     0,   603,   990,   894,  1792,     0,  1780,   119,   987,
     711,   985,     0,   600,  1775,   757,   756,     0,   758,   592,
     754,     0,   614,  1000,   605,  1379,   614,   614,  1052,  1050,
     614,  1044,  1046,  1045,  1043,  1042,   614,   614,   614,  1041,
     614,   784,   614,   614,     0,     0,     0,     0,   614,   614,
       0,     0,     0,  1031,  1022,  1023,     0,  1064,   409,    23,
     857,   401,  1786,     0,  1777,   124,   601,   614,  1049,  1048,
    1212,  1210,  1136,     0,  1702,  1703,  1137,  1225,  1137,  1120,
    1121,  1124,  1139,  1312,   614,     0,     0,     0,     0,   614,
       0,   614,     0,    61,     0,   934,     0,    67,     0,   100,
     580,   668,   614,  1109,  1007,  1113,     0,   614,  1065,  1229,
       0,     0,  1116,   672,   669,   670,     0,   674,   675,     0,
     677,   678,   614,   673,   967,   969,   614,   614,   968,   759,
     965,   720,   961,   926,     0,   614,   614,     0,   684,   685,
       0,     0,   924,   920,   921,   917,   918,   919,   912,   916,
     915,   614,   614,   614,   614,   614,     0,   546,   548,   540,
     543,   544,   910,  1807,   905,   907,   850,     0,   277,   279,
     306,   300,     0,     0,   309,     0,   224,     0,   222,   244,
     236,   228,   247,   964,   174,   960,   872,   174,     0,   614,
       0,  1287,  1288,   614,   614,   614,  1261,  1262,  1264,  1265,
    1266,  1270,  1269,  1267,  1268,     0,   615,   610,   614,  1744,
     614,   614,  1019,   614,   614,  1253,  1252,   614,  1246,     0,
    1559,  1560,     0,  1081,     0,    23,  1166,  1168,  1167,   390,
     389,   614,   614,  1143,   614,   614,   614,   614,     0,   614,
       0,     0,   614,   430,  1593,  1591,  1592,  1588,  1590,  1587,
    1589,  1581,     0,   614,     0,   614,     0,   429,     0,   614,
     507,   506,     0,     0,   477,   474,   483,   614,   480,   614,
     614,   414,   614,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   614,   614,   614,   614,   163,
     164,   165,   166,   167,   168,   508,   509,   510,   443,   614,
     614,   442,   452,     0,   614,   394,   614,     0,   395,   385,
     391,   393,   396,   397,   398,   399,   400,   392,   421,   420,
     468,   614,   614,   977,     0,     0,   349,    24,   343,   614,
     614,  1073,   614,   614,   614,   614,   614,   614,     0,   994,
    1712,   614,   614,   185,     0,   614,   614,  1777,   614,   614,
     614,   614,   614,   136,     0,   614,  1004,   996,   997,  1002,
    1380,  1381,   923,   333,   407,   614,   534,   585,   584,   582,
    1025,   586,  1030,  1026,  1029,   777,     0,  1027,  1028,   778,
    1035,  1039,  1032,  1033,  1037,  1038,  1036,  1034,  1040,     0,
     812,   614,   614,     0,   404,   405,   402,   403,   614,     0,
       0,   767,   766,   765,  1778,  1785,    23,  1132,  1133,  1134,
    1135,  1129,  1127,  1226,  1141,  1126,  1122,   614,     0,  1123,
    1773,   614,     0,   614,   614,    96,     0,    97,   614,     0,
     614,    72,   614,   614,   614,   109,   104,     0,   902,     0,
     901,     0,   467,  1111,   614,   952,   953,   976,   948,   949,
     805,   974,  1067,  1231,   614,  1233,  1232,  1738,   614,   614,
       0,  1736,  1739,  1740,   700,   614,   614,   614,   689,   720,
     720,   718,   614,   614,   721,     0,    25,   688,   691,     0,
     698,   694,   925,   914,  1709,  1710,  1700,  1700,     0,     0,
    1619,   614,   185,  1333,   614,   614,  1334,  1377,   185,   614,
    1378,   614,  1658,   614,  1347,     0,  1395,  1393,  1392,  1391,
    1389,  1390,  1388,  1386,  1383,  1456,  1455,  1384,  1385,  1394,
    1628,  1387,  1716,  1715,  1714,  1807,  1807,   559,   550,   541,
       0,   545,  1807,   909,   174,     0,   320,   212,     0,   185,
     221,   204,  1216,   174,  1204,  1447,   614,  1446,     0,     0,
    1448,  1290,     0,  1296,  1292,  1289,     0,     0,   614,     0,
       0,     0,  1286,  1282,  1436,  1435,  1434,  1258,  1257,   614,
    1281,  1277,   614,  1273,  1271,     0,   614,   609,     0,     0,
    1018,   614,     0,  1016,  1750,  1752,  1751,  1748,  1797,  1794,
    1251,   614,   614,   614,  1244,   467,   341,     0,  1209,     0,
       0,     0,     0,  1658,     0,     0,     0,     0,     0,   525,
     511,   516,     0,   512,   515,   514,     0,     0,     0,     0,
       0,     0,   417,     0,   170,     0,   433,   614,   614,   614,
       0,   614,     0,     0,     0,   435,   434,   453,   444,   459,
     462,   463,   460,   466,   465,   464,   454,   455,   457,   456,
     458,   445,   449,   467,   461,   448,   467,    91,     0,   427,
     614,  1241,  1009,  1077,  1078,  1075,  1074,     0,   900,     0,
       0,   589,     0,     0,   614,   988,   986,     0,   713,   714,
       0,     0,  1776,  1784,     0,     0,   596,     0,   598,   755,
       0,   140,   614,   998,  1005,     0,   614,  1013,   614,   336,
     614,   614,   614,   614,    23,  1051,  1355,     0,     0,   802,
     789,   800,   801,   787,   788,   796,   791,   795,   790,   799,
     794,   797,   793,   798,   786,   792,   785,   784,  1024,   813,
     410,   614,  1056,   614,  1787,   768,   769,   360,   614,  1137,
     614,  1140,  1125,  1807,     0,     0,     0,     0,   614,     0,
     614,    62,    91,     0,     0,   115,   110,     0,   105,   614,
     112,   106,   886,   878,   884,     0,  1110,   614,  1112,  1114,
       0,   614,   956,     0,   614,     0,   614,  1066,  1230,  1753,
    1741,   972,  1742,   970,  1735,  1737,  1807,   671,   676,   679,
     692,   690,   606,     0,   614,   614,   736,   774,   734,   730,
     728,   772,     0,     0,   760,     0,   722,   732,   966,   962,
     614,     0,     0,     0,   697,   614,   614,   614,   614,     0,
       0,   614,  1562,     0,  1451,  1452,  1721,  1416,  1473,   614,
       0,  1719,     0,     0,  1660,  1661,  1659,   614,  1313,   614,
    1399,  1405,  1404,  1403,  1407,     0,  1400,  1401,   614,  1629,
    1640,   547,   549,   614,     0,   562,   554,   556,     0,   551,
     552,   614,   614,   570,   572,   614,     0,   568,   911,   851,
     211,     0,     0,   223,  1172,   873,  1150,  1424,  1426,     0,
    1294,   614,     0,   614,   614,     0,  1284,   614,   614,  1554,
    1552,  1539,  1541,  1537,     0,  1536,     0,  1545,  1532,  1553,
       0,  1544,  1529,  1535,  1551,  1543,  1440,  1526,  1527,  1528,
       0,  1279,  1275,     0,   614,  1263,   613,     0,   612,   614,
     984,     0,   614,   614,  1793,     4,     8,    10,  1558,  1561,
     614,   467,   499,   496,   495,   498,   494,   614,   419,   505,
     490,   490,     0,   513,     0,   517,     0,   281,  1208,     0,
    1586,   497,  1208,   504,   418,   265,     0,  1208,   478,   475,
     484,  1208,   481,  1208,  1208,  1208,     0,     0,     0,   614,
       0,     0,   614,     0,   469,    92,    93,    95,   471,     0,
     614,   614,  1006,   614,   614,   614,   614,   614,     0,   614,
     185,   712,   614,   593,   595,   614,   614,   157,   155,   614,
     614,   137,     0,   147,   153,   720,   142,   144,   614,  1003,
    1014,  1015,     0,   408,   335,   340,   591,   334,   614,   337,
     342,  1356,   535,   583,   581,   784,   779,   780,  1055,  1057,
     614,   406,   361,  1130,  1128,  1227,  1228,     0,    65,  1221,
       0,     0,     0,    98,     0,     0,    73,    79,    69,  1807,
    1807,   108,   103,   117,   113,     0,   107,   775,   887,   606,
    1807,   877,   876,   885,  1008,   614,     0,   614,   975,   467,
       0,     0,  1682,  1572,  1575,  1683,  1583,  1573,  1680,   614,
       0,  1072,  1679,     0,     0,  1681,     0,     0,     0,     0,
     614,  1747,  1574,  1068,  1069,  1678,  1580,  1670,  1071,  1668,
    1669,   614,   614,   614,   702,   695,   693,     0,    23,   614,
     750,   724,   752,   726,  1807,  1807,  1807,  1807,   784,   745,
     744,   740,   742,   749,   748,   738,   746,   719,   723,  1807,
     606,    45,    43,    40,    34,    38,    42,    37,    30,    39,
      33,    36,    31,    41,    32,    44,    35,     0,    28,     0,
     699,  1701,   614,  1699,   614,  1697,  1645,  1646,  1638,  1624,
    1639,     0,     0,   614,  1047,  1450,  1453,   614,     0,   614,
     614,  1474,  1367,  1339,  1724,  1723,  1722,   614,   614,  1641,
    1662,  1664,     0,  1362,   614,  1361,   614,  1363,  1358,  1359,
    1360,  1351,  1348,   614,   614,  1406,   614,     0,     0,  1633,
    1630,  1631,   561,   566,   614,   614,  1807,  1807,   539,   553,
     576,   564,   578,  1807,  1807,   574,   558,   569,   842,   321,
     205,     0,  1198,  1217,   842,     0,  1205,  1198,   614,     0,
    1291,     0,   614,     0,   614,     0,  1479,  1481,  1483,  1521,
    1520,  1519,  1485,  1502,  1293,   614,  1563,     0,  1425,   614,
    1428,  1566,     0,  1432,   614,  1283,     0,     0,  1609,  1607,
    1608,  1604,  1606,  1603,  1605,     0,     0,     0,     0,     0,
       0,     0,     0,  1438,     0,  1441,  1442,   614,  1278,   614,
    1272,  1274,   611,  1749,   614,     0,  1795,   614,     0,  1255,
     614,     0,     0,   487,     0,   488,     0,   527,     0,   524,
     521,   492,   486,  1146,  1594,  1145,     0,   169,  1144,     0,
       0,     0,  1147,     0,  1149,  1148,  1142,   446,   447,   451,
     436,     0,   439,   450,     0,   438,     0,   614,    91,     0,
       0,   614,     0,  1306,  1800,  1799,   590,   614,     0,    46,
     614,   717,   716,   715,  1307,   614,     0,   720,  1807,  1807,
     149,   616,   159,   151,   161,   141,   148,  1807,   614,     0,
     614,     0,   614,     0,   614,  1807,     0,   782,   606,   614,
    1774,    91,   614,    63,   614,   614,   614,    76,     0,    91,
      91,   116,   111,  1807,  1807,   101,   784,   888,   882,   890,
     889,   879,   531,   937,   954,   955,   950,   614,  1577,  1576,
    1579,  1578,  1582,     0,   614,     0,   614,  1522,   614,  1522,
    1522,  1522,  1522,  1671,   614,   614,   614,   614,   614,   614,
    1725,  1726,  1727,  1728,  1729,  1730,  1674,  1754,   973,   971,
     705,   703,     0,   682,   696,   607,   761,     0,   614,  1807,
     614,  1807,   737,   735,   731,   729,   773,     0,  1807,     0,
    1807,   733,    23,     0,    26,     0,  1704,  1658,  1628,   614,
     614,  1637,  1620,  1636,  1454,     0,  1418,     0,  1366,  1461,
     614,     0,  1720,     0,  1717,   614,  1654,   646,   631,   644,
     650,   665,   630,   642,   625,   658,   661,   664,   628,   659,
     637,   641,   652,   663,   660,   662,   653,   635,   633,   657,
     639,   638,   626,   627,   629,   632,   643,   655,   634,   667,
     645,   649,   651,   666,   640,   654,   656,   636,   647,   648,
    1666,  1665,   614,  1365,  1364,  1352,  1350,     0,  1409,     0,
    1402,   614,   614,   614,   614,   563,   560,   555,   557,   614,
    1807,  1807,   571,   573,  1807,  1807,     0,     0,  1196,  1197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1195,     0,     0,  1183,  1184,  1185,  1182,  1187,  1188,
    1189,  1186,  1173,  1164,   614,     0,  1220,     0,  1807,     0,
    1159,     0,     0,     0,     0,     0,     0,   614,  1151,  1152,
       0,  1084,     0,  1295,     0,  1488,     0,  1502,  1487,  1484,
     614,  1449,   614,  1516,  1513,  1514,  1511,  1518,  1517,  1512,
    1515,  1695,     0,  1695,  1503,     0,     0,   614,  1567,     0,
    1568,     0,   614,     0,   614,  1431,  1285,  1430,  1422,     0,
       0,     0,  1556,  1548,  1548,     0,     0,  1548,  1555,     0,
    1572,  1437,  1439,  1443,  1444,  1280,  1276,  1021,   614,     9,
     614,  1248,   859,  1082,   614,  1473,  1648,     0,   490,   518,
       0,   274,   479,   476,   485,   482,   614,   441,   440,   470,
      94,   472,   347,  1242,     0,   614,  1791,     0,     0,   989,
      47,     0,   597,   599,   594,   770,   158,   156,   614,  1807,
     614,   614,   614,  1807,   154,   143,   614,   146,   145,   614,
     995,   999,   339,   614,  1357,     0,   784,   781,    23,  1131,
    1222,    68,   614,     0,    99,    66,    91,    74,    80,     0,
     118,   114,   776,  1807,   892,   606,   891,   614,   528,   614,
     807,   808,   806,     0,  1658,  1691,     0,     0,     0,  1524,
    1525,  1523,   614,  1693,     0,   614,   614,   614,   614,   614,
       0,  1070,  1676,  1677,  1673,  1675,   614,  1807,   701,   686,
     683,     0,   751,   725,   753,   727,   743,   741,   747,   739,
     762,    29,    27,   614,  1698,   614,  1625,  1626,  1622,  1628,
     614,  1417,   614,  1420,     0,  1341,  1336,  1335,  1338,   614,
    1663,   614,  1642,     0,   614,  1314,  1320,     0,  1323,  1325,
    1353,  1349,   614,  1408,   614,     0,  1634,  1632,   567,   565,
     577,   579,   575,     0,     0,   228,  1190,  1191,  1192,  1194,
    1177,  1175,  1174,  1178,  1179,  1176,  1193,  1180,  1181,  1165,
     981,  1200,   978,   614,     0,  1218,     0,  1163,  1162,  1157,
    1155,  1154,  1158,  1156,  1160,  1161,  1153,  1206,  1427,  1486,
    1480,  1482,  1492,  1489,  1696,  1491,   614,  1497,  1489,   614,
    1495,  1695,  1505,  1504,   614,  1506,     0,  1423,  1429,   614,
    1433,  1616,  1614,  1615,  1611,  1613,  1610,  1612,  1538,     0,
    1540,     0,     0,     0,     0,  1546,  1550,     0,  1530,  1445,
    1020,  1256,  1249,  1245,   614,  1462,  1463,  1465,  1468,  1475,
     614,     0,  1522,  1650,  1644,  1601,  1599,  1600,  1596,  1598,
    1595,  1597,   491,   489,     0,   523,   522,   171,   437,     0,
     614,    23,     0,   614,  1012,   614,    48,   992,     0,    23,
     160,   150,     0,   618,   620,   162,   152,   770,     0,   338,
     536,   783,  1053,     0,    64,     0,    77,    86,     0,    70,
     883,   880,   532,  1807,     0,  1584,   614,     0,     0,     0,
    1692,     0,   614,  1690,     0,     0,     0,     0,  1672,  1689,
       0,   704,   681,   687,   606,  1708,     0,  1706,  1654,  1628,
    1628,  1621,  1419,  1658,  1421,  1415,   614,  1340,     0,  1718,
    1655,     0,   614,  1327,     0,  1316,   614,   614,   614,  1410,
    1413,  1397,  1411,  1414,   614,   853,   852,   322,   206,   983,
     982,   980,   614,  1199,  1085,  1089,  1091,   614,  1095,   614,
    1093,  1097,  1086,  1087,     0,   874,     0,  1695,  1509,     0,
    1498,  1501,  1500,  1508,     0,  1489,     0,     0,  1564,  1570,
    1563,     0,  1557,  1549,  1533,  1531,     0,  1534,   614,  1466,
     614,  1571,  1469,   614,  1476,  1477,  1653,  1248,   614,   614,
     614,     0,   520,   519,   473,   348,   345,   614,  1010,     0,
       0,     0,   991,   771,   138,   617,    23,  1001,  1058,  1223,
      82,     0,   614,    75,    86,    86,  1807,   529,   951,     0,
       0,     0,     0,  1688,  1694,  1684,  1685,  1686,  1687,   706,
     763,   614,  1705,     0,  1627,  1623,   614,  1342,   614,  1648,
     614,  1331,  1322,  1329,  1332,   614,     0,   614,   614,  1315,
    1324,  1326,  1354,   614,  1398,  1396,  1635,   979,  1807,  1807,
    1099,  1807,  1101,  1807,  1807,  1088,  1219,  1207,  1490,  1493,
     614,  1496,  1494,  1510,   614,     0,  1569,     0,  1547,  1470,
       0,  1464,  1458,  1459,  1667,   614,  1478,  1472,  1651,  1372,
    1368,  1369,  1374,  1373,  1649,  1248,     0,   350,  1011,  1790,
     614,   614,   614,   614,   614,   614,    53,     0,    52,     0,
      50,   614,   614,   139,  1062,  1054,     0,  1060,    86,    91,
      86,    87,    81,    71,   881,     0,     0,     0,  1733,     0,
    1807,    23,  1707,  1648,     0,  1346,     0,  1343,  1345,  1643,
       0,  1332,   614,  1328,     0,  1317,  1318,  1412,  1090,  1092,
    1807,  1096,  1807,  1094,  1098,  1499,  1507,  1565,  1542,   614,
    1467,   614,  1457,   614,  1376,  1375,  1371,  1652,  1602,   356,
     354,   346,     0,   352,   358,    55,    60,    57,    59,    56,
      58,    54,     0,    49,     0,   619,   621,  1807,  1059,  1061,
    1224,    83,    78,   530,  1657,  1731,  1732,   702,   764,  1647,
    1656,   614,  1337,  1321,  1330,   614,  1100,  1102,  1471,  1460,
    1370,  1807,  1807,   351,   353,  1807,    51,   614,  1063,     0,
     707,  1344,     0,   357,   355,   359,     0,    84,  1319,   993,
      88,    90,   614,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   552,   553,   554,   555,   705,  1725,  1726,   190,   266,
     191,  1126,  1127,  1611,  1947,  2978,  2479,  2480,  2870,  2979,
    2980,   556,   893,  2512,  2180,  2885,  1552,  2178,  2747,  2516,
    2881,  2179,  2748,  2989,  3089,  3100,  2883,  3103,  1774,  1775,
    1776,  1226,  1842,   557,  1237,   898,  1235,  1560,  1852,  1557,
    1850,  1855,  2184,  1236,  1849,  1561,  2183,   558,    16,    35,
      36,    37,    38,    39,   114,   561,   822,  1491,  1153,  1801,
    1805,  1806,  1802,  1803,  2489,  2493,  2157,  2149,  2148,  2150,
    2153,  1108,  1060,  1756,   562,    83,    84,    18,    60,   143,
      96,   257,    98,    99,   202,   280,   100,   101,   244,   230,
     677,  2347,   307,   659,  1671,   334,   335,   231,   289,   282,
     284,   977,   978,   147,   357,   148,   149,   295,   232,   233,
    1477,   395,   245,   248,   246,   247,   316,   372,   373,   375,
     380,   662,   249,   250,   325,   377,   198,    19,    80,   179,
     180,   181,   668,  2346,   182,   253,   242,   328,   329,   330,
     331,  1504,   563,   564,   565,   566,   779,  2967,  2721,  1128,
    3041,  3042,  3043,  3082,  3081,  3085,   567,   568,   569,   570,
     755,  1109,   860,  1195,  1196,  1163,   857,  1164,   757,   758,
     759,   760,   761,   762,   763,  1063,  1110,  2121,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,   711,   764,  1457,  2126,  2128,
    2719,   765,  1428,  2110,  1427,  2109,  1431,  2113,  1429,  2111,
    2093,  2102,   766,   767,   768,   769,  1412,  1413,  1414,  1415,
     571,  2753,  2995,  2528,   572,   830,  1506,  2165,   115,   239,
     367,  1328,   959,   960,   961,  1325,  1326,  1658,  1659,  1660,
    2006,  2007,  1329,  1330,  1654,  2010,  2002,  1666,  1667,  2013,
    2014,  2344,  2340,  2341,   573,  1170,    85,  1472,  1473,  1817,
     862,   812,   865,   688,   801,   784,   823,  1908,    86,   689,
    1006,  1717,    41,   128,  2152,    87,   771,  2320,   574,   575,
     914,   915,   576,   577,   578,   579,   922,  2559,   943,  2772,
     944,  1590,   945,  1905,   946,  2233,   947,  1614,   580,  1586,
    2232,  2557,  2556,  3000,   116,    20,   581,  1144,  1478,  1479,
    1604,  1275,  1605,  1606,  2239,  2241,  1917,  1916,  1929,  1915,
    1914,  2250,  2248,  1921,  1922,  1925,  1926,  1911,  1913,   582,
     583,   820,   584,  1271,   929,  3001,   585,  1203,  2729,  1607,
    1918,  1858,  2186,   853,  1180,  1527,  1826,  2166,  1827,  1176,
    1526,   586,   587,   907,  1575,  2532,   588,   589,   590,   591,
      21,    64,    22,    23,    24,   117,   118,   592,   119,    25,
     649,    26,   120,   121,   159,   369,  1334,  2018,  2806,   122,
     155,   300,   593,  2091,    27,    28,    29,    30,    31,    59,
      88,   123,   414,  1343,  2024,   594,   902,  1862,  1564,  1860,
    2886,  2523,  1565,  1859,  2189,  2525,   595,   596,   597,   795,
     796,  1239,   124,   240,   368,   653,   654,   963,  1332,   598,
     948,   949,   599,   826,  1283,   950,   772,    90,    91,    92,
      93,  1246,   185,   139,    94,   136,   193,   194,  1247,  1248,
    2196,  1249,   411,   412,   931,   413,   932,  1582,  1583,  1250,
    1251,  1124,  2631,  2632,  2811,   694,   810,   811,   600,  1139,
    2872,   601,  2501,   602,  1157,  1158,  1159,  1497,  1495,   603,
     604,  1782,  1812,   605,  1012,  1383,   606,   854,   855,   607,
     870,   608,  1958,   609,  2878,   610,  1830,  2985,  2986,  2987,
    3057,   859,   611,  1252,  1577,  1893,  1894,   612,  1465,   710,
    1024,   613,   614,  2026,  2635,  2822,  2823,  2928,  2929,  2933,
    2931,  2934,  3020,  3022,   615,   616,  1241,  1569,   617,  1243,
     878,   879,   880,  1219,   618,   619,   620,  1539,  1211,   873,
     201,   881,   882,   773,  2027,  2388,  2389,  2372,   714,   715,
    2022,  2373,  2376,   125,   154,   361,   987,  1676,  2390,  2826,
    1033,   621,   871,   126,   151,   358,   984,  1674,  2377,  2824,
    2023,   897,  2171,  2743,  2988,  1214,   622,   623,   624,   625,
     626,   782,  1780,   707,  1730,   627,  2693,   701,   702,  2088,
    1362,   628,   629,   996,   997,   998,  1374,  1713,   999,  1710,
    1371,  1000,  1685,  1363,  1001,  1002,  1003,  1004,  1679,  1354,
     630,   791,   774,   631,  1306,  1982,  2795,  2919,  2595,  2596,
    2597,  2598,  2794,  2912,  2913,  1307,  1308,  1629,  2587,  2788,
    2271,  2584,  3006,  3007,  1309,  1639,  2325,  1992,  2601,  2798,
    1822,  2164,  1993,  1310,  1311,  2703,  2960,  2961,  2962,  3036,
    1312,  1313,  1161,   632,   633,   956,  1314,  1315,  2925,  1645,
    1646,  1647,  1995,  2327,  2801,  2802,  1316,  1968,  2265,  2785,
    1364,  1365,  1350,  2047,  1677,  2048,  1366,  2052,  1367,  2075,
    1368,  2076,  2442,  2443,  1680,  1317,  1623,  1624,  1965,  1318,
    2956,  2854,  2952,  1971,  2455,  2695,  2696,  2697,  2950,  2456,
    1972,  2855,  2957,  2035,  2036,  2037,  2038,  2039,  2828,  2653,
    2938,  2040,  2829,  2830,  2416,  2041,  2417,  2042,  2542,  1706,
    1707,  1708,  2682,  1709,  2439,  2433,  2843,  2049,  2803,  2420,
    2599,  2051,  2852,  1895,   775,  1896,  2202,  1051,  2094,  2712,
    2065,  2678,    58,   634,   635,  2579,  2780,  2258,  2779,  1650,
    2000,  2001,  2262,  1959,  1319,  1960,  2276,  2791,  1404,  1955,
    1956,  2704,  2857,  2592,  2583,  1897,  1637,  1979,  1980,  2953,
    2043,  1899,  2544,  2655,   636,   637,  1616,  1957,  2574,  2776,
    2777,  1286,   638,   777,  1321,  1322,  1632,  2273,  1323,  1324,
    1976,  2226,  2538,   639,   910,  1260,  1261,  1262,  1263,   695,
    1579,   697,  1387,  1900,    62,    47,    78,    75,   641,   884,
    1543,  1147,  1205,   642,   863,   643,  2139,   644,  1724,   699,
    1389,   645,   646,    73,   362,   363,   364,   365,   366,   647
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2578
static const short yypact[] =
{
    3360,  1035, -2578,   603,   603,   603,   603,   603,   603,   603,
   -2578,   603, -2578,   383, -2578, -2578, -2578,   812, -2578, -2578,
   -2578,   379, -2578,  3360, -2578, -2578, -2578, -2578, -2578,  1493,
   -2578, -2578, -2578, -2578, -2578,   384,   536, -2578,   675, -2578,
   -2578,   828, -2578, -2578,   337, -2578,   305, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   389,
     583, -2578, -2578, -2578,   136, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   337,
     350, -2578, -2578,   764,   812, -2578,   713, -2578, -2578, -2578,
   -2578,   969,   448, -2578, -2578, -2578,   989,   684, -2578, -2578,
   -2578,  1026, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   136, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,  6618,   448, -2578,   685,   219, -2578, -2578,   628, -2578,
     486,  1087,   583,   608, -2578, -2578, -2578, -2578, -2578,  7768,
   -2578, -2578,   695,  1020, -2578,   812, -2578, -2578, -2578, -2578,
   -2578, -2578,   600,   981, -2578, -2578,   720, -2578,   727, -2578,
     703, -2578, -2578,   737, -2578,   744, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,   718, -2578, -2578, -2578,   219,
    1468,  1156, -2578,   154, -2578,   219, -2578, -2578,   122, -2578,
   -2578, -2578,    83, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,   600, -2578,   981, -2578, -2578,   773, -2578,   775, -2578,
     750, -2578, -2578,   784, -2578,   791, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,   808,  1195, -2578,   834, -2578,   812,
     812,   858, -2578, -2578,    -6, -2578,   646,  1327, -2578,   655,
    1408,  1248,  1250, -2578,  1261,  1269,  1277, -2578,   708, -2578,
     375, -2578, -2578, -2578, -2578, -2578,   219, -2578,   219,   866,
     179, -2578, -2578, -2578,  1288, -2578, -2578,  1290, -2578, -2578,
   -2578, -2578, -2578,    -6, -2578, -2578, -2578,  1295,  1297,   583,
    1261,  1303,  1318,   723, -2578,  1307, -2578,   979,   956, -2578,
    1027, -2578, -2578, -2578,   776, -2578, -2578,  1355, -2578,   976,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,  1408,   976, -2578,
   -2578, -2578, -2578, -2578, -2578,   978,   148,   220,   238, -2578,
    1958, -2578, -2578, -2578,   986,  1393,   247,  1030, -2578, -2578,
    1468, -2578,   219, -2578, -2578, -2578,   811,  1390,  1184,   265,
     290,   255,  1018,   294,  1059, -2578, -2578, -2578,  1067, -2578,
   -2578,  1067,  1100, -2578,  3704,   608,  4917,  2083,  -162,  1067,
    1423,   519, -2578,  1327,  1419, -2578, -2578, -2578, -2578,  1420,
   -2578,  1422, -2578,  1424, -2578, -2578, -2578, -2578, -2578, -2578,
    1261,  1428, -2578, -2578, -2578, -2578,   189,  1434,   519,  1046,
    1432, -2578,  1452, -2578, -2578, -2578,  1454, -2578, -2578, -2578,
     875,  1110,  1477, -2578,  1067,  1112, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,   757, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,   264, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578,    69,    69,  6830, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578,  1321, -2578, -2578, -2578,
    6830, -2578,  1321, -2578,  1321,  1054, -2578, -2578,   168, -2578,
   -2578,   168, -2578, -2578,   168, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,  1321, -2578, -2578, -2578, -2578,  -124,
   -2578, -2578, -2578, -2578, -2578, -2578,   757, -2578, -2578, -2578,
   -2578, -2578,  8193,  1321,  7578, -2578,   846,   846, -2578, -2578,
   -2578,   338,  1321,   781,  6830,  7578, -2578,   888,  6830, -2578,
     337, -2578,  7578, -2578,  7578,  1321, -2578, -2578,  7578, -2578,
    7578,    69, -2578, -2578, -2578,   846, -2578, -2578,   846, -2578,
   -2578,    96, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   117,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   928, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   543,
   -2578, -2578, -2578,   303, -2578,  1132, -2578, -2578, -2578,  1224,
   -2578, -2578,  1136,  1138,  1140,  1141, -2578, -2578,   908,  1510,
    1145, -2578, -2578,  1236, -2578,  1148,  1162,   930,  1171, -2578,
   -2578, -2578,  1174, -2578,   335, -2578,   192, -2578, -2578, -2578,
   -2578,   947,  1525,  1115, -2578,   957, -2578,   962, -2578,  1550,
      25,   339, -2578, -2578, -2578,  1161, -2578,  1544, -2578, -2578,
    1119,    61, -2578, -2578, -2578,  1121, -2578,  7578,  7578, -2578,
   -2578,  1169,  1065,  1177,  1178,  1179,  1180,  1181,  1187,  1190,
    1192,  1194,  7578,  1429,  1201,  1205,  1206, -2578,  7578,  7578,
    1209,  1213, -2578,  7578,  1218, -2578,  1220,  1222,  1227,  1230,
    1231,  1234,  1235,  7578,  1237,  6133, -2578,   131, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
     515, -2578,  1185, -2578, -2578, -2578, -2578, -2578, -2578,  1321,
   -2578, -2578,  1544, -2578,    32, -2578, -2578,  1335, -2578,   112,
   -2578,  1155, -2578, -2578, -2578, -2578,  1579, -2578, -2578,  -274,
   -2578,  1006, -2578,  1058,  1579, -2578,  1085, -2578, -2578,  1265,
     100, -2578,  1228, -2578,   994, -2578, -2578,  1258, -2578,  -140,
   -2578,  1029,   208,  -215, -2578,  1366,  7578,  7578, -2578,  1672,
   -2578, -2578, -2578, -2578, -2578, -2578,   161,   161,   161, -2578,
     161, -2578,   161,   161,  1107,    32,  1107,  1107,   844,   844,
    1107,  1107,    32, -2578,  1682, -2578,    44,  1689, -2578,    32,
   -2578,  6696, -2578,    67,    58, -2578, -2578,  7578, -2578, -2578,
   -2578, -2578, -2578,   652, -2578, -2578,   608,  1333,   608,  6830,
   -2578,    68, -2578, -2578,  7578,  1287,  1291,  1293,  1294,  1674,
    1298,   781,  1222, -2578,  1376,   525,  1135, -2578,  1150, -2578,
   -2578, -2578,   851, -2578,  1703, -2578,  1700, -2578, -2578,    -5,
     180,  1159, -2578, -2578,  1714, -2578,  1080,  1714,  1731,  1097,
    1714,  1731,  7578,  1714, -2578, -2578,    61,  1321, -2578, -2578,
    1338,   306, -2578, -2578,  1329,  1321,  7578,  1331, -2578, -2578,
    1717,  1718,  1698, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,   873,   873, -2578, -2578, -2578,  1841, -2578, -2578,  1680,
     543, -2578, -2578,   532, -2578, -2578, -2578,  1324, -2578, -2578,
   -2578, -2578,  6618,  1261, -2578,  1325, -2578,   342, -2578, -2578,
   -2578, -2578, -2578, -2578,   812, -2578, -2578,   812,   762,  1349,
    1739, -2578, -2578,   712,  1356,   735,  1760, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,  1362, -2578, -2578,  1525,   962,
     219,   757,  -232,  1753, -2578, -2578, -2578, -2578, -2578,  1200,
    1191,  1211,  1369, -2578,  1385,    76, -2578, -2578, -2578,  4228,
    4228,   846,  7578, -2578,   846,   846,   846,   846,  1345,  7578,
    1199,  1175,  7578,  6133,  1391, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1196,   846,  1766,  7578,  4164,  6133,  1345,  7578,
   -2578,  6133,  1784,   246, -2578, -2578, -2578,  7578, -2578,  7578,
    7578,  6133,  7578,  7578,  7578,  7578,  7578,  7578,  7578,  7578,
    7578,  7578,  7578,  7578,  7578,  7578,  7578,  7578,  7578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  7578,
    7578, -2578, -2578,  1395,  7578, -2578,  7578,  1398, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1321, -2578,  1210,  1409, -2578, -2578, -2578,   757,
     874, -2578,   874,   781,   168,  7578,  7578,  7578,  1411, -2578,
   -2578,  1321,  1321, -2578,  1216,   781,   846,  1182, -2578,   219,
      60,  -124,  1321, -2578,  1212,  7578,  1494, -2578, -2578,  1289,
   -2578, -2578,  1689,    86, -2578,    61, -2578, -2578,  1823,  1824,
   -2578, -2578, -2578, -2578, -2578, -2578,  1962, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  8193,
   -2578,   844,  7578,   -69, -2578, -2578,  1845, -2578,   846,  1826,
    1827, -2578, -2578, -2578, -2578, -2578,    92, -2578, -2578, -2578,
   -2578,  1722, -2578,  1658, -2578, -2578, -2578,  7578,    69, -2578,
   -2578, -2578,  1831,   846,   846, -2578,  1296, -2578,   846,  1253,
    1321, -2578, -2578, -2578,  7578,   -57, -2578,  1302, -2578,   268,
   -2578,  1402, -2578,  1418,  7578,   802, -2578, -2578,   448, -2578,
    1877, -2578,  1357, -2578,  1321, -2578, -2578, -2578,   757,  1321,
     153, -2578, -2578, -2578, -2578, -2578,   846,   846,   209,   306,
    1755,  1279,  1321,    61, -2578,  1360, -2578, -2578,  1878,  1865,
    1518, -2578, -2578, -2578, -2578, -2578,  1601,  1601,   172,  1377,
   -2578, -2578, -2578, -2578,  1544,  1544, -2578, -2578, -2578, -2578,
   -2578, -2578,   429,  1544, -2578,   678, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    1040, -2578, -2578, -2578, -2578,   162,   162,   147,   731, -2578,
     645, -2578,   532, -2578,   812,  1880, -2578, -2578,  1880, -2578,
   -2578, -2578, -2578,   812, -2578, -2578,  1544, -2578,   742,  1501,
   -2578, -2578,   742, -2578, -2578, -2578,  1508,  1509,   569,  1513,
    1515,  3279, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,   569,  1292, -2578,   335,  1879, -2578,  1334,   193,
   -2578,   781,  1381, -2578, -2578,  1115, -2578, -2578, -2578,  1413,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,  1575,  6133,  1578,
    1580,  1584,   347,   429,  1585,  4264,  1593,   -91,   960, -2578,
   -2578,   106,  1600, -2578, -2578, -2578,  4722,  1948,  1429,  1603,
    1607,  5230, -2578,  1609,  3123,  1612, -2578,  7578,  7578,  7578,
    5262,  7578,  5361,  5633,  5729,  6231,  6330,  6416,  6436,  6456,
    3438,  1344,  6533,  1854,  1263,  6617,  4228,  4228,  2521,  2554,
    4114,  5764,  5861,  1345,  6133,  5961,  1345,  6830,  1577, -2578,
   -2578, -2578,  1387, -2578, -2578, -2578, -2578,  1382, -2578,  1985,
    1990, -2578,  1992,  1438,  7578, -2578, -2578,  1400,  1994, -2578,
    1539,  1401,  1731, -2578,  1634,   254, -2578,  1599, -2578, -2578,
    1412,   985, -2578, -2578, -2578,  1610, -2578,   754,  7578, -2578,
   -2578, -2578,  7578,  -168,    32,  2014,  1506,  2002,  2016, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,  1636, -2578, -2578,
   -2578,  1321,  1532,  6897, -2578, -2578, -2578,  2003,  7578,   608,
     837, -2578, -2578,  1749,  1686,  2054,  1690,   349, -2578,  1691,
     781, -2578,  6830,  1653,  1654, -2578, -2578,  1720, -2578,  7578,
     -26, -2578,  1491, -2578, -2578,   270, -2578,  7578, -2578, -2578,
    1464,   685, -2578,  1472, -2578,  2063,  6239, -2578, -2578,  1678,
   -2578,  1679,  2075, -2578, -2578, -2578,    73, -2578,  1731,  1731,
    1440, -2578,  1551,  1557,   846,   846, -2578, -2578, -2578, -2578,
   -2578, -2578,   -13,   465, -2578,   547, -2578, -2578, -2578, -2578,
     846,  3444,  2086,  2067, -2578,   781,   159,   181,  1643,  2020,
      18,   884, -2578,     5, -2578, -2578, -2578,  1692,    35,  1544,
     679, -2578,  1500,  1496, -2578, -2578, -2578,  7899, -2578,  1226,
   -2578, -2578, -2578, -2578,  1695,  1502,  2101, -2578,  2087, -2578,
   -2578, -2578, -2578,  1321,   107, -2578, -2578, -2578,  1495,   731,
   -2578, -2578, -2578, -2578, -2578, -2578,   514, -2578, -2578, -2578,
   -2578,  1708,  1710, -2578,  1677, -2578,  1681, -2578,  1713,   353,
   -2578,  7031,   355,    64,    64,   364, -2578,    64,  7031, -2578,
   -2578,  1503,  1503, -2578,  1719, -2578,  1723,  1724, -2578,  1729,
    1730, -2578,  1734, -2578, -2578, -2578,   224, -2578, -2578, -2578,
     386, -2578, -2578,   393, -2578, -2578, -2578,  1756,   448,  1753,
   -2578,  2112,   781,  7578, -2578,  2127, -2578, -2578, -2578, -2578,
     569, -2578, -2578, -2578, -2578, -2578, -2578,  7899, -2578, -2578,
    1429,  1429,  2116, -2578,  2121,  1587,   363, -2578,  1065,  1776,
   -2578, -2578,  1065, -2578, -2578, -2578,  1788,  1065,  6133,  6133,
    6133,  1065,  6133,  1065,  1065,  1065,  2131,  2137,  2138,  7578,
    1792,  2140,  7578,  1794, -2578,  2161, -2578,  6133, -2578,  1567,
     569,   150, -2578,   781,  7578,  7578,  7578,  7098,  2170,   146,
   -2578, -2578,   781, -2578,  1581, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1129, -2578, -2578,   323, -2578,  1582,  7578, -2578,
   -2578, -2578,  2168, -2578, -2578, -2578, -2578, -2578, -2578,  1731,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    1321, -2578, -2578,  4062, -2578, -2578, -2578,  1875, -2578, -2578,
    1857,  1863,  1752,  1590,  1868,  1786, -2578, -2578, -2578,   497,
    1859, -2578, -2578, -2578, -2578,  1720, -2578, -2578, -2578,   200,
     766, -2578, -2578, -2578,  1878,  7578,  1789,  2177, -2578, -2578,
     144,   170, -2578,   947, -2578, -2578,  1503, -2578, -2578,  2443,
    1790, -2578, -2578,  1797,  1798, -2578,  1808,  1809,  1813,  1815,
   -2578,   -62, -2578,  2197, -2578, -2578, -2578, -2578,  2293, -2578,
   -2578,   757,  1321,  1321,    74,  1598, -2578,  2206,    32, -2578,
   -2578,  2228, -2578,  2229,  1255,  1255,  1255,  1255,  1636, -2578,
   -2578,  2230, -2578, -2578, -2578,  2234, -2578, -2578, -2578,  1255,
      77, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,   401, -2578,  2215,
   -2578, -2578,  1544, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,  1665,  1666,    37, -2578,     5, -2578,    64,  1646, -2578,
    7031, -2578, -2578,  1833, -2578, -2578, -2578, -2578, -2578,  2240,
   -2578,  4085,  1683, -2578,  7578, -2578,  7578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,    64, -2578,  1544,   799,  1647,  1648,
    2245, -2578,  2250, -2578,  1321, -2578,   400,   400, -2578, -2578,
    2252, -2578,  2252,   537,   537,  2252, -2578, -2578,  2083, -2578,
   -2578,  3008,   -19, -2578,  2083,  1239, -2578,   -19,    64,   742,
   -2578,  1848,  2246,  1848,  7628,   197,  2253, -2578, -2578, -2578,
   -2578, -2578, -2578,  1819, -2578,  1544,   426,  1888,  2256, -2578,
   -2578, -2578,   416, -2578,   569, -2578,   424,   202, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,  1660,  -141,  2255,  2255,  2257,
    2255,  2255,  2258, -2578,   283, -2578,   742, -2578, -2578,   569,
   -2578, -2578, -2578,  1664,   781,  2273, -2578, -2578,   427, -2578,
    7291,  1913,   156, -2578,  1687, -2578,  1914, -2578,  2262, -2578,
    1726, -2578, -2578, -2578, -2578, -2578,  1693, -2578, -2578,  1917,
    1918,  1922, -2578,  1926, -2578, -2578, -2578, -2578, -2578, -2578,
    6133,   428, -2578, -2578,   430, -2578,  1927,  7578,  6830,  2281,
     432,   781,  2299, -2578, -2578, -2578, -2578,  7578,  1759,  2060,
    7578, -2578, -2578, -2578, -2578,  2288,  1944,   323,  1198,  1198,
    2311,   358, -2578,  2313, -2578, -2578, -2578,  1198, -2578,  1800,
    2304,  2314, -2578,  -134,  1321,  2105,   433, -2578,  1551,  7578,
   -2578,  6830,  1321, -2578,   264, -2578,  1321, -2578,  1957,  6830,
    6830, -2578, -2578,   497,  1859, -2578,  1636, -2578, -2578,   877,
   -2578, -2578,  1780, -2578, -2578,  1895, -2578,  7519, -2578, -2578,
   -2578, -2578, -2578,  1727, -2578,   927,    98,   439,  7899,   439,
     439,   439,   439,  1735,  7899,  6239,  7899,  7899,  7899,  7899,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1920,   779, -2578, -2578, -2578,  1740,   846,  1255,
     846,  1255, -2578, -2578, -2578, -2578, -2578,   -13,  1255,   465,
    1255, -2578,    32,  3444, -2578,  1971,  1933,   429,  1040,  1643,
    1643, -2578, -2578, -2578, -2578,   440, -2578,  1893, -2578,  2340,
      64,   518, -2578,  1741, -2578,  7899,  1816, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,   119, -2578, -2578,  1817, -2578,   442, -2578,  1742,
   -2578, -2578, -2578,  2087,  1321, -2578,  2252, -2578, -2578, -2578,
     537,   537, -2578, -2578,   537,  2157,  1747,  1750, -2578, -2578,
      69,    69,    69,  2330,    69,    69,    69,    69,    69,    69,
    2333, -2578,  2335,    69, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  3008, -2578,  1321,  1762, -2578,  1934,  2157,  2339,
   -2578,  2347,  2348,  2349,  2350,  2352,  2353,   889,  1239, -2578,
    1934, -2578,   443, -2578,  1921, -2578,   211,  1451, -2578, -2578,
    7031, -2578,  7031, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,   164,  1974,   164, -2578,  1975,   504,  7899, -2578,  2361,
   -2578,  2111,    64,  1787,    64, -2578, -2578, -2578, -2578,  1560,
    2364,  1560, -2578,  2385,  2385,   446,  2021,  2385, -2578,  2022,
   -2578, -2578, -2578,   742, -2578, -2578, -2578, -2578,   781, -2578,
     569,  2148,  1878, -2578,   126,  1897,   -35,  1574,  1429,  1834,
     462, -2578, -2578, -2578, -2578, -2578,  7578, -2578, -2578, -2578,
   -2578, -2578,  1949, -2578,   194,   781, -2578,  2400,  1996, -2578,
   -2578,  2039, -2578, -2578, -2578,  1881, -2578, -2578, -2578,  1198,
     219,  2388, -2578,  1198, -2578, -2578,   846, -2578, -2578,  7578,
   -2578, -2578, -2578,   846,  2075,  2193, -2578, -2578,    32,  6133,
   -2578, -2578,    61,  2008, -2578, -2578,  6830, -2578, -2578,  2046,
   -2578, -2578, -2578,   766, -2578,  1551, -2578,  7578, -2578,   219,
   -2578,  1689, -2578,  1560,   429, -2578,   340,  2413,  2048, -2578,
   -2578, -2578,  7899,  2293,   449,  7899,  7899,  7899,  7899, -2578,
     450, -2578,  2202,  2202,  1257,  1650,  7578,  2001, -2578,  2100,
   -2578,  2406, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,  7899, -2578, -2578, -2578,  1040,
      64, -2578, -2578,  2309,   452, -2578, -2578, -2578, -2578, -2578,
   -2578,  1321, -2578,  2416,    64, -2578,  2425,  2418, -2578, -2578,
   -2578, -2578,    64, -2578,  1991,  1835, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578,  2242,  6618, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
     374,  2429, -2578,  1321,  1008, -2578,  2242, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    2253, -2578, -2578,  2017, -2578, -2578,   260, -2578,  2017,   260,
   -2578,   164, -2578, -2578,  7899,  2293,   195, -2578, -2578,  2415,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  2066,
   -2578,  2414,  2070,  2071,  2419, -2578, -2578,  2072, -2578, -2578,
   -2578, -2578, -2578, -2578,   173,  2440, -2578, -2578,  2420,  2103,
   -2578,  1849,   439,  2142, -2578,  2044, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,   951, -2578, -2578, -2578,  6133,  2084,
     846,    32,  2104,   781, -2578,  7578, -2578,  1907,  2434,    32,
   -2578, -2578,   322, -2578, -2578, -2578, -2578,    78,  2094,  1731,
   -2578, -2578, -2578,  2099,  2014,  2062, -2578,  2149,  2107, -2578,
   -2578, -2578, -2578,  2254,   210, -2578,  7899,  1503,  1872,  1503,
   -2578,  1299,  7899, -2578,  1657,  1673,  1738,  1771, -2578, -2578,
    1924, -2578, -2578, -2578,  1551, -2578,   458, -2578,    70,  1040,
    1040, -2578, -2578,   429, -2578, -2578,    64, -2578,  2074, -2578,
    2075,  1954,  7701, -2578,   459,    84,    64,  7777,  1321, -2578,
   -2578,   300, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1321,  2429, -2578, -2578, -2578,  1321, -2578,  1321,
   -2578, -2578,  1773, -2578,  2266, -2578,  2268,   283, -2578,   460,
   -2578, -2578, -2578, -2578,   464,  2017,  1940,  2466, -2578, -2578,
    2058,  1885, -2578, -2578, -2578, -2578,  2128, -2578,   126, -2578,
     126, -2578, -2578,  7899, -2578,  2073, -2578,  2148,   151,   181,
   -2578,  2477, -2578, -2578, -2578, -2578, -2578,   781, -2578,  2132,
    4373,  2095, -2578, -2578, -2578,  1905,    32, -2578,    80, -2578,
   -2578,  2136,    61, -2578,  2149,  2149,   766, -2578, -2578,   156,
    1901,  1560,  1903, -2578,  2293, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578,  1954, -2578, -2578,  7899, -2578,  7889,   -35,
    3128, -2578,  2507, -2578,  2293,    64,  2503, -2578,  7031, -2578,
   -2578, -2578,  2075,  1991, -2578, -2578, -2578, -2578,  1891,  1891,
   -2578,  1891, -2578,  1891,  1891, -2578, -2578, -2578, -2578, -2578,
     279, -2578, -2578, -2578,  7899,  2113, -2578,  1560, -2578, -2578,
     467, -2578,  2512, -2578,  2293,  7031, -2578, -2578, -2578, -2578,
    2517, -2578,   402, -2578, -2578,  2148,  2152,    34, -2578, -2578,
     161,   161,   161,   161,   161,   161, -2578,  2500, -2578,   469,
   -2578,  7578,  2506, -2578, -2578, -2578,   128, -2578,  2149,  6830,
    2149,  2014, -2578, -2578, -2578,  2306,  2158,  1560, -2578,  1560,
      73,    32, -2578,   -35,   156, -2578,   471, -2578,  2293, -2578,
     472,   927,  7777, -2578,  2118, -2578,  2340, -2578, -2578, -2578,
    1891, -2578,  1891, -2578, -2578, -2578,  2293, -2578, -2578,   126,
   -2578,  7899,  2340,   151, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,   715, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  4373, -2578,  2525, -2578, -2578,   601, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,    74, -2578, -2578,
   -2578,  7889, -2578, -2578, -2578,  7777, -2578, -2578, -2578, -2578,
   -2578,   843,   843, -2578, -2578,   843, -2578,  7578, -2578,  2162,
   -2578, -2578,   473, -2578, -2578, -2578,  2163, -2578, -2578, -2578,
     116, -2578,    61, -2578,  2014
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2578, -2578, -2578, -2578, -2578,   361, -2578,   445,  -188, -2578,
   -2578,  -853,  -275, -2578, -2578, -1549, -2578, -2578, -2578, -2578,
    -516, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -1793, -2578, -1528, -2578,
     412, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   693, -2578,
   -2578, -2578, -2578,  1314, -2578,   991, -2578, -2578,   -52, -2578,
   -2578,  2516, -2578,  2515,  2189, -2578, -2578, -2578, -2578, -2578,
     760,   399, -2578,   759, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,   -98,   943,   852, -2578, -2578,
    2274,   -28, -2578,  2423, -2578, -2578,  2421, -2578,  2351, -2578,
   -2578, -2578,  2283,  2171,  1238,  2278,  -314, -2578, -2578, -2578,
   -2578, -2578,  1240,  -967, -2578, -2578, -2578, -2578, -2578, -2578,
    -112,  2219,  2367,  -196,   822, -2578,  2208,   123, -2578,  2265,
   -2578, -2578, -2578, -2578,  2269, -2578, -2578, -2578, -2578,  -328,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  2200, -2578,
    2204, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  -893,
   -2578, -2578,  -443, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    2321, -2578, -2578,  1068, -2578,  -887,  -797,  1497, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,   831, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578,  -472, -2578, -2578, -2578, -2578,
   -2578,  2077, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -1696, -2578, -2578, -2578, -2578, -2578, -2578,  1197, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,  1652, -2578, -2578, -2578, -2578,   948,
   -2578, -2578, -2578, -2578, -2578, -1238, -2578, -2578,   940, -2578,
   -2578, -2578, -2578, -2578, -2578,  -821,  -474,   829,  1106, -2578,
    -469,   638,  -827,  1081, -2578,   421, -2578, -1819,    -2,  -327,
   -2578, -2578,   135,  1608, -1736,   -37,   901, -2578, -2578, -2578,
     711,  1351, -2578, -2578, -2578, -2578, -2578, -2578,   385, -2578,
      63, -2578,  1352, -2578,  1033, -2578,   714, -2578, -2578, -2578,
    -450, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,   835,
   -2578, -1219, -2578,  1019, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,   388, -2578,   390, -2578, -2578, -2578,
   -2578,  1486, -2578, -2578, -2578, -2578, -2578, -2578,   -97, -1465,
   -2578, -2578, -2578, -2578,   589, -2578, -1659, -2578,  -828, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578,  2618, -2578, -2578, -2578,  2527,  2617,
   -1005, -2578, -2578, -2578, -2578, -2578, -2578, -2578,    11, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,  2619, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  1084, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  -413,
    2166, -2578, -2578, -2578, -2578, -2578,  1998, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578,  2037, -2578, -2578,   -51,
   -2578, -2578,  1089, -2578, -2578,  1410,  -191,  2390, -2578, -2578,
   -2578, -2578,   527, -2578,  -703,  1980,  1392, -2095,   761, -2578,
    1092,  1736,    38,  -142, -2578,  -958, -2578,  1530, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,  1484, -2578,
    1053, -2578,  -385, -2578, -2578, -2578, -2578, -2578, -2578,  -311,
   -2578, -2578, -2578, -2578, -2578, -2578,   461, -2578,  1545,   431,
   -2578, -2578, -2578, -2578,   288, -2578,  -143, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578,  1801, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    -326, -2578,  1465,  1618, -2578, -2578,   295, -2578,  -442, -2578,
   -2578,   314,   660, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
    -139, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2523, -2578,  1671,   910,
    -970, -2578, -2578, -2578,  1319, -2578, -1326, -2578, -2578, -2578,
   -1335, -2578, -2578, -1304, -2578, -2578, -2578, -2578,  1341, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2366,  -101, -2578, -2575, -2481, -2578,   736, -2578, -2578, -2578,
   -2578, -2578, -2578,  -371, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578,  -332, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2578,
   -2578,   705, -2578, -2578, -2578,  -220, -2578, -2578, -2578, -2578,
   -2578, -2578,   284, -2578, -2578,   676, -2578,  1021, -2578, -2578,
   -2578, -2578, -2578, -2578,  -965, -2578, -2578, -2578, -2578, -1414,
   -2578, -2578, -2578, -2578, -2578, -2578, -1990,    12, -2578, -1935,
     252, -2578, -2578, -1652,   309,   310,   677, -2578, -2379, -2156,
   -2578, -2578,    54,  -225, -2578, -2578, -2578, -2578, -1962, -2578,
   -2578, -2578, -1508, -2578, -2578,  -783, -2578,  -647,  1425,  -121,
   -1631,   680, -2578, -1961, -2578, -2578, -2578, -2578,  -675, -2578,
   -1644, -2220, -2578, -2578, -2578, -2578, -2578, -2578, -2578, -2005,
   -2578,   387, -2578, -1407, -2578,  1765, -2578, -2578,  -764,  -135,
   -2578, -2577,  -133,   -50,   455, -1623, -1376, -1704,   454,  -301,
   -1369, -2578,   520,   -95, -2578, -2578,  1446,  -514, -2578, -2578,
    -166,  1785, -2578,   839, -2578, -2578, -1240,   149, -2578, -2578,
   -2578, -2578, -2578, -2578, -2578, -2578,  1476, -2578, -2578,  -435,
    -404,  -447,  1023, -1251,    15,  1645,   125, -2578, -2578, -2578,
   -2578, -2578,  1592, -2578,  -458, -2578, -2578, -2578, -2578, -2578,
   -2578, -2578, -2578,  -658,  1359,  2376, -2578, -2578, -2578, -2578
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1804
static const short yytable[] =
{
      40,   260,   388,  1166,   270,   716,  1193,  1580,  1025,   876,
      55,    57,   113,  1175,  1341,    32,  1172,  1173,   286,  1174,
     696,  1177,  1178,  1351,  1846,  1373,  1804,  1737,  1007,  1162,
     818,   132,    97,  2092,  1711,  1268,  2057,   827,    32,   418,
    2188,    74,    77,   861,    68,  2095,  1712,   867,  2066,  1278,
    1592,  1593,  2050,  2053,  1686,  1386,  2053,   238,  1052,   864,
    1022,  1633,  1948,  1198,  2154,   258,   113,   141,   800,  2504,
    1206,   825,  1198,  1217,   129,  2275,   669,    77,   340,   127,
    1486,  1273,  1198,  1198,   271,   924,   925,   918,  1020,   138,
     921,  1498,   271,   685,   712,  2374,   145,  1192,  1962,   912,
     150,   277,   696,   152,   153,  1142,   271,   278,   279,   156,
     157,  2252,  2004,  2441,    97,   293, -1802,  2230,   203,   271,
     924,   925,  1020,  1199,  1744,   829,  1288,   776,  1290,  1200,
     776,  1745,  1396,   127,  1499,  1125,  1500,  1253,  1501,  2593,
     785,   301,   302,  1020,   776,   271,   272,   273,   776,   234,
    1020,   396,   237,   381,   271,   802,  1118,   241,  2142,   268,
     776,  2275,   785,   933,  1969,     1,  2141,   271,   813,  2198,
    1020,   785,   102,  -614,   874,  1020,  2959,   103,   824,  1130,
    1131,  1870,  1871,   828,   268,  1257,  1167,   271,  2440,  1874,
    -614,   866,   793,   271,   268,  2200,   275,  1020,   268,  2722,
    2837,   294,   813,  2400,   130,   874,   813,  1898,  2400,  1966,
     813,  2680,  1257,  2917,  1498,   268,   785,  2400,    72,   785,
    1294,   104,   105,  1269,  2187,   383,  -614,   140,  2793,   106,
     815,    82,  2203, -1802,   298,  2502,   186,   187,     3,     4,
     304,     5,     6,   385,   188,  1009,     7,  2545,  2546,  2547,
    2548,   332,   391,  2576,   346,  1531,   348,  2658,  3101,  2246,
     142,    97,  1556,     8,     9,  1296,    82,   140,  1981,  2430,
     400,   261,   262,   263,   264,   265,  2700,  1870,  1871,  2833,
    1741,    10,    11,   271,  1873,  1874,   934,  1618,  1619,   704,
    1562,   722,  1562,  1854,  1423,   402,  1870,  1871,  1149,   406,
    1870,  1871,   271,  1873,  1874,  2923,   271,  2440,  1874,  1597,
     394,  1273,  1155,  2755,   559,   648,  2921,    82,  2269,  1254,
      82,  1818,  1584,  1258,   942,  1381,  1135,   394,  2158,    82,
     934,    82,  3009,  1136,  2958,  3010,  2266,  1804,    82,   261,
     262,   263,   264,   265,  1017,  2757,   934,  1339,  2214,  2508,
    1258,    82,  1198,  1537,  1198,  1597,   410,  1190,  2029,   410,
    2029,  3039,   868,  2328,  -614,  3040,  1382,   410,  1981,  2054,
      82,   934,   988,   989,  1184,  1185,  1010,  1229,    82,    63,
    2396,   640,   650,   332,  1156,   332,  2099,  1952,  2100,    82,
    3058,  2077,   261,   262,   263,   264,   265,  2050,  2079,   990,
     991,   992,  1373,  1597,   305,  1919,  2253,    56,  2395,  1191,
    2398,  2073,   410,    81,    69,  -614,  1920,   684,   816,   687,
    2924,  2424,   693,   698,  2012,   700,  3069,  2015,   703,  2424,
     692,   306,  2450,  2466,    82,  2466,  1274,  2450,  2506,   709,
    3102,   935,  3037,  1601,   651,  2580,   770,  2602,  2422,   692,
    2654,  2684,  2654,  1274,  2762,  2762,  2943,  2786,   709,  2701,
     926,  1150,  1505,  2901,  2915,  2940,  2431,   652,   770,  2940,
    2702,   709,  3029,  2536,  3052,  2375,  3071,  3012,  3012,  1742,
     817,   803,  1563,   107,  1563,  2715,   936,  2716,  1302,  1601,
    1305,     3,     4, -1802,     5,     6,  2790,   819,   821,     7,
    3092,   386,  1234,   866,   693,  2835,  2503,  1532,    82,   108,
    2205,  1653,   770,  2661,   819,   819,     8,     9,   404,   382,
    1255,  1005,   770,   770,   817,   895,   770,  2522,    77,  2594,
     770,  3074,   770,  1559,    10,    11,   770,  1601,   770,  1876,
     913,  1970,   913,   819,  1015,   913,   819,  2723,   913,  3013,
    1212,  2264,  1215,  1256,  1877,   686,  2263,   686,   686,    82,
     269,  1378,  1397,   927,    34,  1399,  1400,  1401,  2401,  1289,
    1181,   686,  1152,  2428,  2781,  2537,  1380,  1188,   936,  1402,
     109,   937,  2649,  2848,  1419,   343,  2159,  1201,  1620,   686,
    2918,   384,   686,  1016,  1963,   671, -1802,  2231,   686,  1720,
    2471,  2838,   686,  2074,  2591,    12,   686,   696,  1907,  2728,
     686,  1820,  1861,   731,   686,   686,  2888,   686,   392,  1467,
     686,  2694,   686,   686,   686,   937,   866,   828,   866,   189,
     686,  1481,  1954,   686,  2005,  1876,   401,  1143,   735,  2585,
     686,   937,  1168,  2510,  1336,   686,   976,  1627,  1628,   962,
    1877,  2518,  2519,   686,  1876,   901,  1638,  2045,  1876,  1337,
    1794,   403,   274,  2397,   686,   407,   937,  1218,   686,  1877,
     274,  2998,   686,  1877,   110,  1202,  1746,   983,   686,   410,
    1864,   686,   818,  2454,   274,  1502,  2058,  1259,  1482,  1770,
     693,  2045,  1773,  1503,  1462,  2831,  1169,   274,  2831,  1678,
    2654,  1204,    33,  2922,  2571,  1021,  2751,  2131,  1487,   183,
    1018,  2204,  2045,  1340,  1259,   770,   770,  1529,  1736,  1132,
    1841,  1468,   744,   274,  2030,   696,  2044,  3028,  2875,  1534,
     770,  1907,   274,  2662,   794,  2055,   770,   770,  2274,  2045,
    2859,   770,  2445,  1750,  2045,   274,   339,   938,   939,   940,
    2426,   770,  2730,  2446,  1546,   111,  2735,  2078,   941,  1549,
    2089,  1386,  2713,   112,  2080,   274,  1547,  2336,  1634,   993,
    1567,   274,  2254,  2059,  2904,  2905,  1542,  3065,  2539,  3066,
    1021,   691, -1802, -1802, -1802, -1802, -1802,  2425, -1802,  2657,
    2060,  2668,  2660,  2670,  1356,  2427,  2490,  1594,  2451,  2467,
    1595,  2468,  1596,  2473,  2507,   874,    15,  1357,  1588,  1589,
    2089,  2581,  1991,  2603,  2648,   749, -1802,  2685,  2016,  1379,
    2763,  2769,  1597,  2787,   770,   770,  1640,   751,   752,  2902,
    2916,  2941,  1598,  2061,  1974,  2942,   754, -1802,  3030,  2543,
    3053, -1802,  3072,  3073,  3098,  2543,  1898,  2552,  2553,  2554,
    2555,  1927,  2577,  2578,    72,    82,  2909,   994,  2949,   770,
    2951,   274,  1835, -1802,  2419,   770,  2654,  1721,    81,    61,
    2663,  2778,  2664,  2062,  1599,  1238, -1802,   770,  1600,  1345,
     274,  2575,   770,  1923,   274,  1635,  1342,  1227,   415,  1344,
     657,   780,  2758,  2809,  1924,  2540,   655,  1284,  1463,  1345,
     995,  2524,  2063,  -614,   789,  1245,  1981,    76,   868,   651,
     808,  2064,    79,  2644,     3,     4,    95,     5,     6,   814,
     770,  3034,     7,  1731,   658,  1120,  2683,   692,  2485,  2687,
    1975,   964,   652,  3083,   770,  1231,    61,  1356,    42,     8,
       9,   682,  2810,    17,  2216,  2217,  2218,  2219,   131,  2782,
    1357,    82,   134,   135,  2996,  2900,  1601,    10,    11,  2491,
    1356,  1485,   134,   135,   916,   686,    17,   919,  3003,  2582,
    3035,  2799,   885,  1357,  2862,  1661,  2863,  2586,  1408,  2831,
   -1802,  1769,  1973,  1409,  1772,  1411,   133,  1353,  2746,   137,
    1597,  1361,  1370,  1361,   142,  1636,  1393,  2167, -1802,  2220,
    2221,  2222,  2223,  2224,  2225,  2541,   693,    82,  1602,   693,
   -1802,  1385,  1388,  2345,    82,   700,  1121,   144,  1346,  2378,
   -1802,    82,   886, -1802, -1802,  1359,  1232, -1560,    12,   819,
     770,   146,   819,   819,   819,   819,  1845,   770,  1346,  3078,
     770,  1360,  3039,    82,    82,  1819,  3040,    82,  2665,  -614,
    2814,   819,  2889,   770,    82,  2236, -1802,   770,    82,    82,
     887, -1802,    33,    34,  2393,   770,   195,   770,   770,  3070,
     770,   770,   770,   770,   770,   770,   770,   770,   770,   770,
     770,   770,   770,   770,   770,   770,   770,   196,   686,   686,
     686,  2992,  2993,  1464,  1347,  1464,  1641,   770,   770,   276,
     197,  1951,   770,   281,   770,   235,  1661,  1642, -1802,  1373,
     200,  2444,   236,  2890,  1347,  2892,   243,    43, -1802,  1458,
    1662,  2815,  1358,   259,  1601,  1910,  1912,   693,  1797,  1643,
     251,    44,  1798,   770,   770,   770,  1644,   252, -1802,  1663,
    1664,   254,  2268, -1802,   819,  1372,  1484,   255,  1488,   819,
     134,   135,  1930,   770,   256,  2907,    45,   888,  2756,  1665,
   -1802, -1802, -1802, -1802,   957,   958,  2326,   900,  1359,  1809,
   -1802,   904,  1348,  2761, -1802,   908,  2764,  2765,  2766,  2767,
    1626,   267, -1802,   287,  1360,   288,  1630,  2816,   290,  2817,
     770,  1359,  1603,  1408,   291,  3060,   819,  3062,  1409,  1410,
    1411,   292,  3004,  2452,  2818,    46,  1981,  1360,  2085,  1026,
    1027,  1028,  2819,  1834,  1349,   770,  2820,  1641,   296,  1544,
     297,   819,   819,  1406,  1407,   729,   819,  2963,  1642,    15,
    1553,  1554,   770,   889,  1349,  1799,  1669,   730,  1800,  1571,
     135,  2821,   770,   951,   299,  1675,  1207,  1208,  1209,  1210,
    1643,  1662, -1802,   308,   952,   917,   693,  1644,   920,  2090,
    1597,   923,   317,   913,   819,   819,  3016,  2132,   303,  2133,
    1663,  1664,  1797,   326,   890,   327,  1798,  2219,  2144,  1083,
    1084,  1085,  1086,  1087,  1088,  2434,   333,  2436,  2437,  1622,
    1665,   828,  1021,  1021,   336,  2836,   778,  1631,  2535,  1631,
    2155,  1021,   337,  3032,   342,  2256,   953,  1648,  1649,   338,
     787,   976,   866,   344,   792,   345,  2216,  2217,  2218,  2219,
     349,   954,   350,  2321,   355,  1718,   806,  -265,   353,  2220,
    2221,  2222,  2223,  2224,  2225,  1089,  1090,  1091,  1092,  1093,
    1094, -1802,   891,   354,  1021, -1802,   356,   713,   713,  2329,
     359,  1095,  1096,  1097,  1656,  1657,  1361,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,   360,  1370, -1802, -1802,
    1361,  2220,  2221,  2222,  2223,  2224,  2225,   370,  2379,  1799,
     371,   746,  1800,  1573,  1810,  1811,   374,  1981,   379,  1727,
    1728,  1729,   389,  2894,  1601,  2380,  2381,  2197,   390,  2570,
    2531,   393,  2963,  2382,  1597,  2832,   892,  2906,  2832,   938,
     939,   955,   397,  2984,  -265,   398,  1089,  1090,  1091,  1092,
    1093,  1094,   399,  2914,   405,   770,   770,   770,  2914,   770,
     408,  -265,  1095,  1096,  1097,  1182,  1183,  2383,  -957,  1186,
    1187,   416,   713,   656,   661,   663,  2384,   664, -1802,   665,
     748, -1802,   928,   670,   672,   770,   674,   675,  1779,   750,
    2403,  3061,  2404,  2405,  2406,  2407,  2408,  2409,  2216,  2217,
    2218,  2219,   770, -1802,  -265,  2385,   679,   676,  2689,   678,
    2691,   680,   681,   683,  2954,   261,   262,   263,   264,   265,
    1807,    82,  1098, -1308,   817,  1099,   770,  2227,  1814,  1815,
     770,   819,  3044,   966,   690, -1802,   967,   968, -1802,   969,
   -1802,   970,   971,   972,  -265,   973,   974,   708,   975,   979,
    2386,  2984,     1,  2220,  2221,  2222,  2223,  2224,  2225,  1594,
   -1802,   770,  1595,   980,  1596,   981,   770,  1981,  1601,  3008,
   -1802,  3011,   982,  -265,   781,   986,  1843,  1983,  1008,   691,
     770,  2101,  -265,  1010,  1597,  1011,  1984,   770,  1014, -1802,
     798,   799,  2387,  1013,  1598,   770,   805,  1019,  1020,   807,
    2447,  1032,  1245,  1098,  1891,  3026,  1099,  3044,  1023,  1031,
    1985,  1129, -1802,  1986,  1134,  1122, -1802,  1034,  1035,  1036,
    1037,  1038,   819,   819,  1133,     3,     4,  1039,     5,     6,
    1040,  1987,  1041,     7,  1042,  1137,  1599, -1802,   819,  2103,
    1600,  1053,   928,  2105,  1100,  1054,  1055,  2474,  2108,  1058,
       8,     9,  2112,  1059,  2114,  2115,  2116,  1021,  1062,  1101,
    1064,   686,  1065,  1102,  1146,  1891,   828,  1066,    10,    11,
    1067,  1068,   866,  2914,  1069,  1070,  1999,  1072,  2808,    48,
      49,    50,    51,    52,    53,  2742,    54,  1138,  1119,  2011,
    2011,  1140,  2954,  2011, -1802,  1141,   866,  1145,  1148,  1151,
    2893,  1103,  1160,   309,  2216,  2217,  2218,  2219,  2741,  1891,
    1165,  2046,  2046,  2410,  1179,  2046,  1891,  1189,  1601,  2832,
    2216,  2217,  2218,  2219,  1192,  1100,  1213,  1221,  1225,  1104,
    1230,  1222,  3008,  1223,  1224,  1233,  2914,  1988,  1228,  1234,
    1101,  1242,  2081,  1244,  1102,  1264, -1802,  1385,  1105,  1265,
    1266,   770,  2220,  2221,  2222,  2223,  2224,  2225,  1361,  2220,
    2221,  2222,  2223,  2224,  2225,  1891,  1198,  1267,  1272,  1276,
    1602,  1279,  1280,  1281,  1282,  2220,  2221,  2222,  2223,  2224,
    2225,  1327,  1103,   686,   318,  2216,  2217,  2218,  2219,  1352,
     310,  1989,  1335,  1338,  1355,  1375,  1369,   770,  1990,  2562,
     770,  2564,  1376,  1384,   686,  1044,  1391,   311,  1361,  1394,
    1104,  1393,   770,   770,   770,   770,  1420,  2046,  2216,  2217,
    2218,  2219,  1392,  2146,  1807,  1395,  1403,  2151,  2151,  1105,
    1106,  1417,  2411,  1418,  1425,  1453,   770,  2698,  1456,  2744,
    2220,  2221,  2222,  2223,  2224,  2225,  2163,  1460,  1492,  1461,
     312,  1474,  2535,  1480,  1494,  1204,  1496,   928,  2403,    13,
    2404,  2405,  2406,  2407,  2408,  2409,  2216,  2217,  2218,  2219,
    1507,   319,  1508,  2220,  2221,  2222,  2223,  2224,  2225,  2058,
    1533,  1535,  1536,   140,  1538,  1545,  1540,  1550,   320,  2412,
     313,  1559,  1045,   770,  1566,  2195,  1548,  1107,  2866,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  2874,  1891,    14,  1046,
    1568,  1106,  1574,  1498,  1576,  1274,  2815,  1610,  2213,   314,
    1612,  2220,  2221,  2222,  2223,  2224,  2225,  1613,   315,   693,
   -1802,   321,  1615,  1716,  1621,  1670,  2671,  2237,  2616,  2617,
    2618,  1681,  2620,  2621,  2622,  2623,  2624,  2625,  1683,  1684,
    2705,  2628,  1047,  1687,  1603,  1688,  1089,  1090,  1091,  1092,
    1093,  1094,   828,   828,  2690,  1719,  2059,  1714,  1722,  1291,
    1723,   322,  1095,  1096,  1097,   756,  1732,  2944,  1107,  1733,
    1021,  1734,  2816,  2060,  2817,  1735,  1738,  2216,  2217,  2218,
    2219,  2724,  1048,   387,  1740,  2046,   648,   786,  1891,  2818,
     323,  1747,   648,  1749,  1751,  2272,  1631,  2819,  1752,   324,
    1754,  2820,   770,  1757,   770,  1781,  1509,  1778,  2413,  1783,
    1784,  1049,  2046,  2672,  1021,  1785,  2061,  1786,  1787,  1790,
    1050,  1789,  1791,  2011, -1802,  1793,  2821,  2706,  1792,  1795,
    2673,   858,  2220,  2221,  2222,  2223,  2224,  2225,  1796,  1273,
    1808,   877,   883,  2983,  2707,   899,  2046,  1823,  2895,   903,
    1891,   905,  1891,   650,  2414,   909,  2062,   911,  2737,   650,
    1821,  1824,  1292,  2046,  2896,  2739,  1825,  2698,  1829,  1832,
    1293,  2410,  1361,  2674, -1802,  2415,  1294,  1838,  1295,  1839,
    1851,  1840,  1844,  1847,  1848,  2063,   928,  2708,  1857,  1296,
   -1802,  1865, -1802,  1867,  2064,  1370,  1869,  1361,  1901,  1902,
    1903,   941,  1907,  1098,  1909,  1727,  1099, -1802,   770,  2257,
    3015,  1949,  1950,  2675,  1302, -1802,    89,  1297,   686, -1802,
    1961,  1977,  1967,  1978,   686,  1994,  1997,  2709,  1996,  2897,
   -1802,  1998,     1,  1298,  2019,  2008,  2020,  2021,  1299,   713,
    2084,  2025,  2676,  2028, -1802,   770,   770,  2082,   686,  2067,
    1300,  2677,  2087,  2068,  2069,   770,  2710,  1301,   770,  2070,
    2071,  2096,  2898,  2483,  2072,  2711,  2097,  2104,  3068,  3045,
    3046,  3047,  3048,  3049,  3050,  2117,  1807,  2098,  2498,  2107,
    2500,  2118,  2119,  2122,  2123,  2125,  2127,   770,  2129,   770,
    2411,   184,   192,  2514,   928,  2140,  2162,   770,   770,  2991,
    2170,  2172,  2145,  2160,  2423,     3,     4,  2173,     5,     6,
    2174,  2175,  2176,     7,  2193,   770,  2177,  2194,   160, -1802,
    2206,  2698,  2215,  2698,  2046,  1100,  1891,  2207,  2208,  2868,
       8,     9,  1891,  1891,  1891,  1891,  1891,  1891,  2209,  2210,
    1101,  2218,  2219,  2211,  1102,  2212,   192,  2412,    10,    11,
     940,  2235,   192,  2238,  2240,  2247,   819,   161,   819,  2249,
    2255,  2259,  2260,  2270,  2267,  2275,  1510,  2322,  2331,  2332,
    2333,  2865,  1511,  1512,  1513,  2334,   162,  2339,  2394,  2421,
    2402,  2422,  1103,  1870,  1871, -1748,  1872,  2429,  2046,   271,
    1873,  1874,  1514,  1891,  2220,  2221,  2222,  2223,  2224,  2225,
    2432,  2448,  2435,  2438,  2453,  2458,  2807,  2459,  2462,  2463,
    1104,  1875,  1302,  2464,  2457,   163,  2460,  2465,  2469,  1303,
    2461,  2472,  2732,   192,  2475,   192,  2477,   164,  2482,  1105,
    2216,  2217,  2218,  2219,  2478,  2484,  2488,   165,  2492,  2499,
    2046,  1304,  1333,   858,  2497, -1802,  1305,  2496,  2517,  2605,
    2606,  1999,  2527,  2529,  2533,   166,  2549,  2609,  2754,  2534,
    2558,  2561,  2572,  2573,  2582,   167,  2400, -1802,  2589,  2604,
    2591,  2600,  2614,  2968,  2619,  2615,  2413,  2626,  1197,  2627,
    2634,   168,  2633,  2637,   858,  2220,  2221,  2222,  2223,  2224,
    2225,  2638,  2204,  2639,  2640,  2641,   877,  2642,  2643,   192,
    1515,  1220,  2698,  1516,  2656,  2659,  2666,  1346,  2669,  2679,
    2681,  1106,  2686,  2688,   686,   686,  2692,  2720,  1891,  3104,
    1891,   169,  2414,  1970,  2714,  2725,  2726,  1517,  2733,  2652,
    2727,  2652,  2728,  2740,  2745,  1891,   692,  2749,  2759,  2760,
    2046, -1802,  2046,  2415,   935,   170,  2774,  1518,  2784,  2792,
    2796,  2797,  2805,  2800,  2812,  2839,  2804,  2841,  2827,  2842,
     171,  2844,  2845,  2847,  2846,  2850,  -614,   172,  1361,  2858,
     173,  2853,  1021,  2860,  2861,  2864,  2871,  2867,  1107,  2873,
    1870,  1871,  1519,  1872,   770,  2877,   271,  1873,  1874,   706,
    2879,   174,  2880,  2882,   175, -1802,   176,  1892,  2884,  2891,
    2899,  2454,  1520,  1521,  2908,  2936,  2151,  2937,  1875,  2734,
    2151,  2945,  2947,  1522,   819,   177,  2419,   770,  1523,  2948,
    2955,   819,  2966,   783,  2969,  2981,  2982,  2990,  2997,   788,
    2999,   790,  3012,   178,   770,   797,  3014,  3031,   797,  3027,
    2031,   797,  3033,  3038,  3051,   770,  3055,  3063,  3075,  3064,
    3087,   809,  2449,  3097,  3099,  2513,  3086,  1524,  1892,  2470,
    1891,  1087,  1088,  1891,  1891,  1891,  1891,  2768,  2185,  1558,
     856,  1856,    70,    71,   770,   560,  2147,  2495,   869,   872,
     875,  2156,   283,   351,   896,   199,   347,   204,   352,   673,
    1525,  2775,   906,  1891,   409,  1088,  1672,  2106,  2046,  1673,
     285,   660,  1892,   378,  2717,   666,   376,  2272,   930,  1892,
     866,   667,  2046,  1089,  1090,  1091,  1092,  1093,  1094,  3084,
    2046,  1831,  1622,  2124,   894,  1743,  2017,  2009,  1816,  1095,
    1096,  1097,  1331,   692,  1377,  2136,  1587,  3090,  2560,  2234,
    1591,  1876,  2773,  1906,  1928,  2143,  1089,  1090,  1091,  1092,
    1093,  1094,  1469,  1470,  1471,  2566,  1877,  1489,  1892,  2568,
    2876,    65,  1095,  1096,  1097,   158,    66,  2825,    67,  1863,
     804,   965,  1493,  1878,   693,  1572,  2032,   693,   341,  2652,
    1866,   985,  1891,  1270,  2229,  1609,  1868,  2840,  2033,  1880,
    2927,  2813,  1476,  1528,  1964,  3059,  2551,  1466,  2647,  2935,
    1216,  1426,  1541,  2646,  1651,  1652,  2629,  2391,  1390,  1530,
    2130,  1668,  1021,  1682,  1715,  2920,  2851,  2204,  2856,  2261,
    3091,  3080,  2330,  3017,  2392,  2667,  2849,  2699,  2056,  2650,
    1882,  2399,  2651,  2834,   877,  3025,  1625,  2783,   819,  2946,
    2607,  1320,  1883,   770,  2964,  2418,  2588,  2965,  2903,  2590,
    3079,  1555,  2939,  1617,  2550,  3002,  1585,  1287,  2789,  1483,
     417,  1570,  2083,     0,     0,     0,     0,     0,   930,     0,
    1098,     0,     0,  1099,  1891,     0,     0,     0,     0,     0,
    1891,     0,     0,     0,  1884,     0,     0,     0,     0,     0,
       0,  2199,  2201,     0,     0,     0,     0,     0,     0,     0,
    1892,     0,     0,  1098,  2046,     0,  1099,     0,     0,     0,
    1891,     0,     0,     0,  2046,  1891,     0,     0,     0,     0,
       0,     0,  2926,  1885,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1886,  1123,     0,  1876,     0,
       0,     0,     0,     0,     0,     0,     0,  1887,  1888,  2034,
       0,     0,     0,  1877,     0,     0,  1889,     0,     0,  1890,
       0,     0,     0,     0,     0,     0,  1021,   274,  1021,     0,
    1878,  1891,     0,  1879,     0,     0,  2046,     0,  2856,  1154,
       0,     0,     0,     0,     0,     0,  1880,     0,     0,     0,
       0,  1892,  1100,  1171,  1171,  1171,     0,  1171,     0,  1171,
    1171,     0,     0,     0,     0,    89,    89,  1101,     0,     0,
       0,  1102,     0,     0,  2204,     0,     0,     0,     0,  2775,
       0,     0,  1837,     0,  1891,  1100,  1891,  1882,  1891,     0,
       0,     0,     0,  2046,     0,     0,  1891,     0,     0,  1883,
    1101,  1622,     0,     0,  1102,     0,     0,     0,   875,  1103,
       0,     0,     0,  1892,     0,  1892,     0,     0,   693,  1240,
       0,     0,  1891,     0,     0,  1904,     0,     0,     0,     0,
       0,     0,     0,  1891,     0,     0,     0,  1104,     0,     0,
       0,  1884,  1103,   930,  1123,     0,     0,     0,     0,     0,
       0,  1788,  1277,     0,     0,  1892,  1105,     0,     0,   770,
    3056,     0,     0,     0,     0,     0,     0,   770,  1285,  1285,
    1104,     0,     0,     0,     0,  1813,     0,     0,     0,  1471,
    1885,     0,     0,     0,     0,     0,     0,     0,     0,  1105,
    1891,     0,  1886,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1887,  1888,     0,  1021,     0,  1891,
    1197,  2046,     0,  1889,     0,     0,  1890,     0,  1029,  1030,
       0,     0,     0,     0,   274,     0,     0,   192,     0,     0,
       0,     0,   686,  1043,     0,     0,  1853,     0,  1106,  1056,
    1057,  2348,  2349,     0,  1061,  2350,  2351,  2352,     0,  1891,
       0,     0,     0,  1891,  1071,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   770,     0,     0,     0,     0,
       0,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1892,
       0,     0,     0,     0,     0,  1892,  1892,  1892,  1892,  1892,
    1892,     0,     0,     0,     0,  1107,     0,     0,  1755,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1870,  1871,     0,  1872,     0,
       0,   271,  1873,  1874,     0,     0,     0,     0,  1107,  1459,
       0,     0,     0,     0,     0,  2353,     0,    89,     0,    89,
     875,   797,  2354,  1875,     0,     0,  1892,     0,  1475,   809,
       0,     0,   875,     0,     0,     0,   192,     0,     0,  1490,
       0,     0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,
    1094,     0,   930,     0,     0,     0,  2355,     0,  2181,  2182,
       0,  1095,  1096,  1097,     0,  2356,     0,     0,     0,  2191,
    2086,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2357,  2358,     0,     0,     0,     0,
       0,   713,   713,   713,     0,   713,   713,   713,   713,   713,
     713,     0,     0,     0,   713,     0,     0,  1551,     0,     0,
       0,     0,     0,  2242,  2243,  2244,  2245,     0,     0,     0,
       0,  2134,  2135,  1471,  2138,     0,     0,     0,  2251,  2359,
       0,  1578,     0,     0,     0,     0,  1581,     0,   692,     0,
       0,  1892,     0,  1892,     0,  2161,     0,     0,     0,  1608,
     930,     0,  1892,     0,  1892,     0,     0,     0,  1892,     0,
       0,     0,     0,  1689,     0,     0,     0,     0,     0,     0,
       0,  2360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,  1398,     0,  1099,     0,     0,     0,     0,
    1405,     0,  2192,  1416,  1655,  2337,  2338,     0,     0,     0,
       0,     0,  2342,  2343,     0,     0,  1421,     0,     0,     0,
    1424,     0,     0,     0,     0,     0,     0,  2361,  1430,     1,
    1432,  1433,     0,  1434,  1435,  1436,  1437,  1438,  1439,  1440,
    1441,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,
       0,     0,     0,   928,     0,     2,     0,     0,   875,     0,
    1451,  1452,     0,     0,     0,  1454,     0,  1455,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1892,     0,     0,  1892,  1892,  1892,  1892,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
       0,     0,     3,     4,     0,     5,     6,     0,     0,     0,
       7,     0,     0,     0,  1100,     0,  1892,     0,     0,     0,
       0,  2323,     0,  2324,     0,     0,     0,     8,     9,  1101,
       0,     0,     0,  1102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1876,     0,    10,    11,  2486,  2487,     0,
    1089,  1090,  1091,  1092,  1093,  1094,  2494,     0,  1877,     0,
       0,     0,  1931,     0,  2505,     0,  1095,  1096,  1097,     0,
       0,  1103,     0,     0,     0,  1878,     0,     0,  1879,     0,
       0,     0,  2520,  2521,     0,     0,     0,     0,     0,     0,
       0,  1880,     0,     0,     0,     0,     0,  1892,  1690,  1104,
    1892,     0,  1892,     0,     0,  1892,     0,     0,  1828,     0,
       0,     0,     0,     0,     0,     0,    12,  1836,  1105,  2204,
       0,     0,     0,     0,     0,     0,     0,   875,     0,     0,
       0,  2911,  1882,     0,     0,     0,     0,     0,  2563,     0,
    2565,     0,     0,     0,  1883,     0,     0,  2567,   184,  2569,
       0,     0,     0,     0,     0,     0,  1691,  2362,  2363,  2364,
    2365,  2366,  2367,  2368,  2369,  2370,  2371,     0,  1692,     0,
       0,     0,     0,     0,  2476,     0,     0,  2481,  1693,     0,
       0,     0,     0,     0,     0,     0,  1884,     0,     0,     0,
       0,     0,   875,  1953,   875,     0,  1694,  1892,   869,     0,
    1106,     0,     0,  1892,     0,     0,  1695,  1098,     0,  1696,
    1099,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1697,     0,     0,  1885,     0,     0,     0,     0,
    2003,     0,     0,  1892,   858,     0,    13,  1886,  1892,  2610,
    2611,     0,     0,  2612,  2613,     0,     0,     0,     0,  1887,
    1888,     0,     0,     0,     0,     0,     0,     0,  1889,     0,
       0,  1890,     0,     0,     0,     0, -1803,  1107,  1892,   274,
       0,  1698,     0,     0,     0,     0,     0,  2636,     0,     0,
       0,     0,     0,     0,     0,    14,     0, -1803,  1758,  1759,
    1760,     0,  1762,     0,  1892,     0,  1932,     0,     0,   875,
       0,  1699,     0,     0,     0,     0,     0,     0,     0,  1933,
       0,  1700,     0,     0,     0, -1803,     0,    15,  1777,     0,
       0,     0,     0,   928,     0,     0,     0,     0,     0,  1100,
       0,     0,  1701,     0,     0,  1702,     0,  1703,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,  1892,  1102,  1892,
       0,  1892,     0,     0,     0,     0,     0, -1803,   875,  1892,
     875,     0,     0,     0,     0,  1704,     0,     0,     0,   875,
       0,     0,     0,  1934,  1705,     0,     0,     0,     0,     0,
    1935,  1892,     0,     0,     0,  1892,  1103, -1803,  2731,     0,
       0, -1803,  2736,     0,     0,     0,  1892,     0,     0,  1833,
       0,     0,     0,     0,     0,     0,     0,  2168,     0,     0,
       0,     0,     0,  1777,  1104, -1803,     0,     0,     0,  1936,
       0,     0,  2750, -1803,     0, -1803,     0,     0,     0,     0,
       0,     0,     0,  1105, -1803,     0,  2190,     0,     0,     0,
   -1803,     0,     0,     0,  1937,     0,     0,     0, -1803,     0,
       0,     0, -1803,  1892,  1938,  1939,  2771,     0, -1803,     0,
       0,     0, -1803, -1803, -1803, -1803,     0,     0,     0,     0,
    1940,     0,  1892,     0,     0,     0,     0, -1803,     0,  2228,
    1581,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1941,     0, -1803,  1942,  1943, -1803,     0, -1803,
       0,  1944,     0,     0,     0,     0, -1803,     0,     0,     0,
       0,     0,  1892,     0,     0,  1106,  1892,     0,     0, -1803,
       0,     0,     0,     0,     0,     0,     0,     0,     0, -1803,
       0,     0,     0,     0,     0,     0,  2738,     0,     0,     0,
       0,     0,     0,   928,     0,     0,     0,     0, -1803, -1803,
       0,     0,     0,     0,     0,     0,     0,     0,  1945,     0,
       0,     0,     0, -1803,  2752,     0,     0,     0,     0,     0,
    1946, -1803,     0,     0,     0, -1803,     0,     0,     0,     0,
       0,  2335,  1107,     0, -1803, -1803, -1803,     0,     0,     0,
       0,     0,     0,  2770,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2169,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,     0,     0,     0,     0,     0,     0,
    2120,     0,     0,  2120,     0,     0,     0,     0,     0,     0,
       0,     0,  2216,  2217,  2218,  2219,     0,     0,     0,     0,
       0,    72,  2887, -1803,     0,     0,     0,     0,     0,     0,
       0,   875,     0,     0, -1803,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,  1096,  1097,     0,     0,     0,     0,  2220,  2221,  2222,
    2223,  2224,  2225,     0,     0, -1803,     0,     0,   875,     0,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1581,  1095,  1096,  1097,     0,     0,     0,     0,  2511,
       0,   706,     0,  2515,     0,     0,     0,     0,     0,     0,
       0,     0,  2869,     0,     0,     0,  2526, -1803,     0,     0,
       0,     0,     0,     0,     0,     0,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,     0,  2994,     0,  1086,  1087,  1088,
       0,     0,  1095,  1096,  1097,     0,     0,     0,     0,     0,
       0,     0,     0, -1803,     0,     0,     0,     0,     0,     0,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,     0,  3018,  3019,     0,
    3021,  1098,  3023,  3024,  1099,     0,     0,     0,     0,     0,
    1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,     0,
   -1803,     0,     0,     0,     0,     0,  1095,  1096,  1097,     0,
       0,     0,     0,     0, -1803, -1803, -1803, -1803, -1803, -1803,
   -1803,     0, -1803, -1803,     0,     0,  1089,  1090,  1091,  1092,
    1093,  1094,     0,  1098,     0,  2277,  1099,     0,     0, -1803,
       0,     0,  1095,  1096,  1097,     0,     0,     0,     0,  3067,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2608,     0,     0,     0,     0,     0,     0,     0,  3076,
       0,  3077,     0,     0,     0,  2278,  2279,  2280,     0,     0,
       0,     0,     0,  1098,     0,     0,  1099,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2281,  2630,     0,  1100,     0,     0,  3088,     0,  2282,     0,
       0,     0,     0,  2283,  2645,     0,     0,     0,  1101,     0,
       0,     0,  1102,     0,     0,     0,     0,     0,  2284,     0,
    3093,  3094,     0,  2285,  3095,  2286,     0,     0,  1777,  1777,
       0,  1931,  2287,     0,     0,  2288,     0,  1098,  2289,     0,
    1099,  2290,     0,     0,  2291,  1100,     0,     0,     0,  2292,
    1103,     0,     0,     0,     0,     0,     0,     0,  3054,     0,
    1101,     0,     0,     0,  1102,   875,     0,  2293,     0,     0,
    2509,     0,  1777,  1098,     0,     0,  1099,     0,  1104,     0,
    1777,  1777,     0,  2294,     0,     0,  2295,  2296,     0,     0,
       0,     0,   875,  2297,     0,  1100,     0,  1105,     0,     0,
       0,     0,  1103,     0,  2298,     0,     0,   192,     0,     0,
    1101,     0,     0,     0,  1102,  1422,     0,     0,     0,     0,
    2299,     0,     0,     0,     0,     0,     0,  2300,     0,   930,
    1104,     0,     0,     0,  2301,     0,  2970,  2302,  2303,  2304,
       0,  2305,  2306,     0,     0,     0,   192,     0,     0,  1105,
       0,     0,  1103,     0,     0,     0,     0,     0,  2307,  1100,
       0,     0,     0,     0,  3096,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1101,     0,     0,     0,  1102,  1106,
    1104,     0,  2308,  2309,  2310,  2311,     0,  2312,     0,     0,
       0,     0,  2971,     0,     0,  1100,     0,     0,     0,  1105,
       0,     0,     0,     0,  2313,  2314,     0,     0,  1581,     0,
    1101,     0,     0,     0,  1102,  1739,  1103,  2972,     0,     0,
       0,     0,     0,     0,     0,     0,  2973,  2315,     0,     0,
       0,  1106,     0,     0,     0,     0,  2316,  2317,     0,  2318,
       0,     0,     0,     0,  1104,     0,  1107,     0,     0,     0,
    2630,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2974,  1105,     0,  1932,     0,     0,     0,     0,
    2975,     0,     0,     0,     0,     0,     0,     0,  1933,     0,
    1104,  1106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,  1105,
       0,  2319,     0,     0,     0,     0,     0,     0,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     875,     0,  1934,     0,     0,  1106,     0,     0,  1107,  1935,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2976,     0,     0,  2718,     0,     0,
       0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,
       0,  1106,     0,     0,     0,     0,     0,     0,  1936,     0,
    1095,  1096,  1097,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1107,  1937,     0,  1581,     0,  1777,     0,     0,
       0,     0,     0,  1938,  1939,     0,     0,     0,     0,  2630,
       0,     0,     0,     0,  2930,     0,  2932,     0,     0,  1940,
       0,     0,     0,     0,     0,     0,     0,     0,  1107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1941,     0,     0,  1942,  1943,     0,     0,     0,     0,
    1944,     0,     0,     0,     0,     0,   875,     0,     0,     0,
       0,     0,     0,     0,   875,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   930,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,  1945,     0,     0,
     419,  1098,   420,     0,  1099,     0,     0,  2977,     0,  1946,
       0,     0,     0,     0,   421,     0,   422,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     423,     0,     0,     0,     0,     0,     0,   424,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   425,   426,
     427,     0,     0,     0,     0,     0,     0,  1171,  1171,  1171,
    1171,  1171,  1171,     0,   428,     0,   429,   430,   431,     3,
       4,   432,     5,     6,   433,     0,   434,     7,   435,   436,
       0,     0,     0,     0,     0,   437,     0,     0,   438,     0,
     439,   440,   441,     0,     8,     9,     0,     0,     0,     0,
     442,     0,   443,   444,     0,   445,     0,   446,   447,     0,
       0,   448,    10,    11,     0,     0,   449,   450,   451,     0,
     452,   453,     0,  1100,     0,   454,   455,     0,   456,     0,
       0,     0,   457,     0,   458,   459,     0,     0,  1101,     0,
     460,     0,  1102,  1748,   461,     0,     0,   462,     0,   463,
       0,   464,     0,   465,     0,   466,   467,     0,   468,   469,
     470,     0,     0,     0,   471,     0,   472,   473,     0,   474,
       0,     0,     0,     0,     0,     0,     0,   475,   476,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,   930,
     477,     0,     0,   478,   479,     0,     0,   480,   481,     0,
       0,   482,   483,     0,     0,     0,     0,     0,  1104,     0,
     484,   485,   486,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   488,   489,   490,  1105,   491,     0,
       0,     0,   492,   493,     0,     0,     0,   494,     0,     0,
       0,     0,     0,     0,     0,   495,     0,     0,     0,     0,
       0,     0,     0,   496,   497,   498,     0,     0,     0,     0,
       0,   499,   500,     0,     0,     0,     0,   501,     0,     0,
     502,     0,     0,     0,   503,   504,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   505,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,     0,   506,     0,     0,     0,     0,     0,  1106,
       0,   507,     0,     0,     0,     0,     0,   508,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,     0,     0,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,   509,     0,   510,
     511,     0,  1089,  1090,  1091,  1092,  1093,  1094,   512,     0,
    1777,     0,     0,     0,     0,     0,     0,     0,  1095,  1096,
    1097,     0,     0,     0,     0,     0,  1107,     0,     0,     0,
       0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,
       0,     0,     0,     0,     0,     0,     0,   513,     0,     0,
    1095,  1096,  1097,     0,     0,     0,     0,     0,   514,     0,
       0,     0,   515,     0,     0,     0,   516,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,     0,     0,     0,     0,     0,     0,     0,
     517,   518,     0,     0,     0,   519,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   520,     0,     0,
       0,     0,     0,   521,   522,   523,   524,     0,     0,     0,
     525,     0,     0,     0,   526,     0,     0,     0,     0,     0,
       0,   527,   528,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,     0,   529,     0,   530,     0,     0,     0,  1095,
    1096,  1097,     0,     0,     0,     0,   531,     0,   532,  1098,
       0,   533,  1099,     0,     0,     0,     0,   534,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1098,     0,   535,  1099,     0,   536,     0,     0,     0,
       0,     0,   537,     0,     0,   538,   539,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     540,     0,     0,     0,     0,     0,     0,   541,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   543,   544,   545,   546,   547,   548,     0,     0,   549,
       0,   550,     0,   551,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,     0,     0,     0,     0,     0,     0,     0,     0,
    1098,     0,     0,  1099,     0,     0,  1101,     0,     0,     0,
    1102,  1753,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1101,     0,
       0,     0,  1102,  1761,     0,     0,     0,     0,  1103,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1104,     0,     0,     0,
    1103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1104,     0,
       0,     0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,
    1094,     0,  1100,     0,     0,     0,     0,  1105,     0,     0,
       0,  1095,  1096,  1097,     0,     0,     0,  1101,     0,     0,
       0,  1102,  1763,     0,     0,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1088,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1106,     0,  1103,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,  1086,  1087,  1088,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,     0,  1106,
       0,  1089,  1090,  1091,  1092,  1093,  1094,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1105,  1095,  1096,  1097,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,  1089,  1090,  1091,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1095,  1096,  1097,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,  1099,  1107,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1106,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
    1096,  1097,     0,     0,     0,     0,     0,     0,  1098,     0,
       0,  1099,     0,     0,     0,  1107,     0,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,     0,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,  1098,     0,     0,  1099,     0,     0,  1101,
       0,     0,     0,  1102,  1764,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,  1103,     0,     0,     0,     0,     0,     0,     0,  1095,
    1096,  1097,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,     0,     0,  1105,     0,
    1098,     0,     0,  1099,     0,  1101,     0,     0,     0,  1102,
    1765,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1101,     0,     0,     0,  1102,     0,     0,  1103,     0,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1104,     0,     0,     0,     0,
    1106,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1105,  1767,     0,     0,     0,     0,
    1098,     0,     0,  1099,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,
    1094,     0,  1100,     0,     0,     0,     0,     0,     0,  1105,
       0,  1095,  1096,  1097,     0,     0,     0,  1101,     0,     0,
       0,  1102,     0,     0,     0,     0,     0,  1107,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,     0,     0,     0,  1870,  1871,     0,  1872,
       0,     0,   271,  1873,  1874,     0,  1106,     0,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1768,     0,  1875,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,     0,     0,
       0,  1106,     0,  1089,  1090,  1091,  1092,  1093,  1094,     0,
       0,     0,  1100,     0,     0,     0,  1105,     0,     0,  1095,
    1096,  1097,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,  1102,     0,  1107,     0,     0,     0,     0,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1098,     0,     0,  1099,     0,     0,  1107,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1771,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1104,  1106,     0,
       0,     0,  1089,  1090,  1091,  1092,  1093,  1094,     0,   692,
       0,     0,     0,     0,     0,     0,  1105,     0,  1095,  1096,
    1097,     0,     0,     0,     0,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,     0,     0,
       0,     0,     0,     0,     0,     0,  1077,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,     0,     0,
    1098,     0,     0,  1099,     0,  1107,     0,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,     0,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,  1106,  1101,
       0,     0,     0,  1102,  1095,  1096,  1097,     0,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1095,  1096,  1097,     0,  1089,  1090,
    1091,  1092,  1093,  1094,     0,     0,     0,     0,     0,     0,
       0,  1103,     0,     0,  1095,  1096,  1097,  1081,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,     0,     0,     0,     0,  1098,
       0,     0,  1099,     0,     0,  1107,     0,     0,     0,  1104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1100,     0,     0,     0,     0,     0,  1105,     0,
       0,     0,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,  1102,     0,     0,     0,  1089,  1090,  1091,  1092,  1093,
    1094,     0,     0,     0,  1876,     0,     0,     0,     0,     0,
       0,  1095,  1096,  1097,     0,     0,     0,     0,     0,  1877,
       0,     0,     0,     0,  1084,  1085,  1086,  1087,  1088,  1103,
       0,     0,     0,     0,     0,  1098,  1878,     0,  1099,  1879,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1880,     0,     0,  1098,     0,  1104,  1099,     0,
    1106,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1100,     0,     0,     0,  1098,  1105,     0,  1099,  1089,
    1090,  1091,  1092,  1093,  1094,     0,  1101,     0,     0,     0,
    1102,     0,  1881,  1882,     0,  1095,  1096,  1097,     0,     0,
       0,     0,     0,   717,   718,  1883,     0,     0,     0,   271,
     719,   720,  -614,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   721,  1107,  1103,     0,
       0,   722,     0,     0,     0,     0,     0,   723,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1884,     0,     0,
       0,     0,  1098,     0,     0,  1099,  1104,  1100,  1106,     0,
       0,     0,     0,     0,     0,   724,     0,     0,     0,     0,
       0,     0,  1101,     0,     0,  1105,  1102,  1100,     0,     0,
       0,     0,     0,     0,     0,     0,  1885,     0,     0,     0,
       0,     0,  1101,     0,     0,     0,  1102,  1100,  1886,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1887,  1888,  1101,     0,  1103,     0,  1102,     0,     0,  1889,
       0,     0,  1890,     0,     0,  1107,     0,     0,     0,     0,
     274,     0,     0,     0,  1103,     0,  1098,   717,   718,  1099,
       0,     0,  1104,   271,   719,   720,  -614,  1766,   160,     0,
       0,     0,     0,     0,  1103,     0,    82,  1106,   725,     0,
     721,  1105,  1104,     0,     0,   722,     0,     0,     0,     0,
       0,   723,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,  1105,  1104,     0,     0,     0,     0,   161,     0,  1101,
       0,     0,     0,  1102,     0,     0,     0,     0,     0,   724,
       0,  1105,     0,     0,   717,   718,   162,     0,     0,     0,
     271,   719,   720,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1107,     0,     0,   721,     0,     0,
       0,  1103,   722,     0,     0,     0,     0,     0,   723,     0,
       0,     0,     0,  1106,     0,   163,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   726,     0,   164,  1100,  1104,
     727,     0,     0,  1106,     0,     0,   724,   165,     0,     0,
       0,     0,     0,  1101,     0,     0,     0,  1102,  1105,     0,
       0,     0,     0,  1106,     0,   166,     0,     0,   728,     0,
      82,     0,   725,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1107,   168,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,   729,     0,     0,     0,     0,     0,     0,
    1107,     0,     0,     0,     0,   730,     0,     0,  1870,  1871,
       0,  1872,     0,  1104,   271,  1873,  1874,     0,     0,     0,
    1107,   169,     0,   731,     0,     0,     0,    82,   732,   725,
    1106,   733,  1105,     0,     0,     0,  1875,     0,     0,     0,
       0,     0,   734,     0,     0,   170,     0,     0,   735,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   736,   726,
     171,     0,     0,   737,   727,     0,   738,   172,     0,   739,
     173,     0,     0,     0,     0,   717,   718,     0,   740,   741,
       0,   271,   719,   720,     0,     0,     0,     0,     0,     0,
       0,   174,   728,     0,   175,     0,   176,  1107,   721,     0,
       0,     0,     0,   722,     0,     0,     0,     0,     0,   723,
       0,     0,     0,     0,  1106,   177,     0,     0,     0,  1194,
     742,     0,     0,     0,   743,     0,   726,   729,     0,     0,
       0,   727,   744,   178,     0,     0,     0,   724,     0,   730,
       0,     0,     0,   745,     0,     0,     0,     0,     0,   746,
       0,     0,     0,     0,     0,     0,     0,   731,     0,   728,
       0,   692,   732,     0,     0,   733,     0,     0,     0,     0,
       0,     0,     0,     0,   747,     0,   734,     0,     0,     0,
       0,  1107,   735,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   736,     0,   729,     0,     0,   737,     0,     0,
     738,     0,     0,   739,     0,     0,   730,     0,     0,     0,
       0,     0,   740,   741,     0,     0,     0,     0,   748,     0,
       0,     0,     0,     0,   731,   749,     0,   750,    82,   732,
     725,     0,   733,     0,     0,     0,     0,   751,   752,   753,
       0,     0,     0,   734,     0,     0,   754,     0,     0,   735,
       0,     0,     0,     0,   742,     0,     0,   274,   743,   736,
       0,     0,     0,     0,   737,  2031,   744,   738,   717,   718,
     739,     0,     0,     0,   271,   719,   720,   745,     0,   740,
     741,     0,     0,   746,     0,     0,     0,     0,     0,     0,
       0,   721,     0,     0,     0,     0,   722,     0,     0,     0,
       0,     0,   723,     0,     0,     0,     0,     0,   747,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1194,   742,     0,     0,     0,   743,     0,   726,     0,     0,
     724,     0,   727,   744,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   745,     0,     0,     0,     0,     0,
     746,     0,   748,     0,     0,     0,     0,     0,     0,   749,
     728,   750,     0,     0,     0,     0,  1876,     0,     0,     0,
       0,   751,   752,   753,     0,   747,     0,     0,     0,     0,
     754,  1877,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   274,     0,     0,     0,   729,     0,     0,  1878,     0,
       0,  2032,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,     0,  2033,  1880,     0,     0,     0,     0,   748,
       0,    82,     0,   725,     0,   731,   749,     0,   750,     0,
     732,     0,     0,   733,     0,     0,     0,     0,   751,   752,
     753,     0,     0,     0,   734,     0,     0,   754,     0,     0,
     735,     0,     0,     0,     0,  1882,     0,     0,   274,     0,
     736,     0,     0,     0,     0,   737,     0,  1883,   738,     0,
       0,   739,     0,     0,     0,     0,     0,     0,     0,     0,
     740,   741,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   717,   718,     0,     0,
       0,     0,   271,   719,   720,     0,     0,     0,     0,  1884,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   721,
     726,     0,   742,     0,   722,   727,   743,     0,     0,     0,
     723,     0,     0,     0,   744,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   745,     0,  2137,  1885,     0,
       0,   746,     0,   728,     0,   717,   718,     0,   724,     0,
    1886,   271,   719,   720,     0,     0,     0,     0,     0,     0,
       0,     0,  1887,  1888,  2034,     0,   747,     0,   721,     0,
       0,  1889,     0,   722,  1890,     0,     0,     0,   729,   723,
       0,     0,   274,     0,     0,     0,     0,     0,     0,     0,
     730,     0,     0,     0,     0,  1870,  1871,     0,  1872,     0,
       0,   271,  1873,  1874,     0,     0,     0,   724,   731,     0,
     748,     0,  -858,   732,     0,     0,   733,   749,     0,   750,
       0,     0,     0,  1875,     0,     0,     0,   734,     0,   751,
     752,   753,     0,   735,     0,     0,     0,     0,   754,    82,
       0,   725,     0,   736,     0,     0,     0,     0,   737,   274,
       0,   738,     0,     0,   739,     0,     0,     0,     0,     0,
       0,     0,     0,   740,   741,     0,     0,     0,  1870,  1871,
       0,  1872,     0,     0,   271,  1873,  1874,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1875,     0,    82,     0,
     725,     0,     0,     0,     0,   742,     0,     0,     0,   743,
       0,     0,     0,     0,     0,     0,     0,   744,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   745,     0,
       0,     0,     0,     0,   746,     0,     0,     0,   726,     0,
       0,     0,     0,   727,  1870,  1871,     0,  1872,   692,   205,
     271,  1873,  1874,     0,     0,     0,     0,     0,     0,   747,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   728,  1875,     0,     0,     0,     0,     0,   206,   207,
       0,     0,     0,     0,     0,     0,     0,   208,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   726,     0,     0,
       0,     0,   727,   748,     0,     0,   729,     0,     0,     0,
     749,     0,   750,     0,     0,     0,     0,     0,   730,     0,
       0,   692,   751,   752,   753,     0,     0,     0,     0,     0,
     728,   754,     0,     0,     0,     0,   731,     0,     0,     0,
       0,   732,   274,     0,   733,     0,     0,     0,     0,     0,
       0,     0,  2031,     0,     0,   734,  1870,  1871,     0,  1872,
       0,   735,   271,  1873,  1874,   729,  1870,  1871,     0,  1872,
       0,   736,   271,  1873,  1874,     0,   737,   730,     0,   738,
       0,     0,   739,     0,  1875,     0,     0,     0,     0,     0,
       0,   740,   741,     0,  1875,   731,     0,   692,     0,     0,
     732,     0,     0,   733,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   734,     0,     0,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     736,     0,  2530,   742,     0,   737,     0,   743,   738,     0,
       0,   739,     0,     0,     0,   744,     0,     0,     0,     0,
     740,   741,     0,  1876,     0,     0,   745,     0,   209,     0,
       0,     0,   746,     0,     0,     0,     0,     0,  1877,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1878,     0,   747,  2032,     0,
       0,     0,   742,     0,     0,     0,   743,   210,     0,     0,
    2033,  1880,     0,     0,   744,     0,     0,     0,     0,   692,
       0,     0,     0,     0,     0,   745,   211,     0,     0,   692,
       0,   746,     0,     0,     0,     0,  1876,     0,     0,     0,
       0,   748,   212,     0,     0,     0,     0,     0,   749,     0,
     750,  1877,  1882,     0,     0,     0,   747,     0,     0,     0,
     751,   752,   753,     0,  1883,   213,     0,     0,  1878,   754,
       0,  2910,     0,     0,     0,     0,     0,   214,     0,     0,
     274,     0,     0,     0,  1880,     0,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     748,     0,     0,     0,     0,   216,  1884,   749,     0,   750,
       0,     0,  1876,     0,     0,   217,     0,     0,     0,   751,
     752,   753,     0,     0,  2911,  1882,     0,  1877,   754,     0,
       0,   218,     0,     0,     0,     0,     0,  1883,     0,   274,
       0,     0,     0,     0,  1878,  1885,     0,  1879,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1886,     0,     0,
    1880,     0,     0,     0,     0,     0,     0,     0,     0,  1887,
    1888,   219,     0,     0,     0,     0,     0,     0,  1889,  1884,
       0,  1890,     0,     0,     0,     0,     0,     0,     0,   274,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
    2911,  1882,     0,     0,     0,     0,     0,     0,     0,     0,
     221,     0,     0,  1883,     0,     0,     0,   222,  1885,     0,
     223,     0,     0,     0,  1876,     0,     0,     0,     0,     0,
    1886,     0,     0,     0,  1876,     0,     0,     0,     0,  1877,
       0,   224,  1887,  1888,   225,     0,   226,     0,     0,  1877,
       0,  1889,     0,     0,  1890,  1884,  1878,     0,     0,  1879,
       0,   831,   274,     0,     0,   227,  1878,     0,     0,  1879,
     832,     0,  1880,     0,     0,     0,     0,     0,     0,   833,
       0,     0,  1880,   228,   834,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1885,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1886,     0,     0,     0,
       0,     0,  3005,  1882,     0,     0,     0,     0,  1887,  1888,
       0,     0,     0,  1882,     0,  1883,   229,  1889,   835,     0,
    1890,     0,     0,     0,     0,  1883,   836,     0,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1884,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1884,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   837,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1885,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1885,   838,  1886,     0,
       0,     0,     0,     0,   839,     0,   840,     0,  1886,     0,
    1887,  1888,     0,     0,     0,     0,   841,     0,     0,  1889,
    1887,  1888,  1890,     0,     0,     0,     0,     0,     0,  1889,
     274,     0,  1890,     0,     0,     0,     0,     0,     0,     0,
     274,     0,   842,     0,     0,     0,     0,     0,     0,     0,
     843,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   844,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   845,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   846,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   847,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   848,   849,   850,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   851,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   852
};

static const short yycheck[] =
{
       2,   189,   330,   830,   195,   447,   859,  1258,   711,   523,
      12,    13,    64,   841,   981,     0,   837,   838,   214,   840,
     424,   842,   843,   988,  1552,   995,  1491,  1403,   686,   826,
     499,    82,    60,  1737,  1369,   922,  1688,   509,    23,   365,
    1859,    43,    44,   515,    29,  1741,  1372,   519,  1692,   936,
    1269,  1270,  1683,  1684,  1358,  1013,  1687,   155,   733,   517,
     707,  1301,  1611,     5,  1800,   177,   118,    95,   481,  2164,
     867,   506,     5,     5,    76,     5,   390,    79,   266,    64,
      20,     5,     5,     5,    23,    24,    25,   545,    24,    91,
     548,     5,    23,   420,    25,   114,    98,     5,    80,   541,
     102,    18,   506,   105,   106,     5,    23,    24,    25,   111,
     112,  1930,     5,  2074,   142,   227,    43,    43,   146,    23,
      24,    25,    24,    56,    18,   510,   953,   454,   955,    62,
     457,    25,  1025,   118,    48,   782,    50,   142,    52,    20,
     467,   239,   240,    24,   471,    23,    24,    25,   475,   151,
      24,   342,   154,     5,    23,   482,    25,   159,  1789,     5,
     487,     5,   489,    46,   129,    29,    20,    23,   495,    25,
      24,   498,    36,    26,    24,    24,    25,    41,   505,    67,
      68,    17,    18,   510,     5,    32,    25,    23,    24,    25,
      26,   518,    24,    23,     5,    25,   198,    24,     5,     5,
       5,   229,   529,     6,    79,    24,   533,  1576,     6,  1623,
     537,  2431,    32,   129,     5,     5,   543,     6,    26,   546,
     215,    85,    86,   926,    24,     5,    26,    92,  2594,    93,
     354,   170,  1876,    71,   236,   369,    17,    18,   102,   103,
     242,   105,   106,     5,    25,   692,   110,  2209,  2210,  2211,
    2212,   253,     5,  2258,   282,   324,   284,  2413,   142,  1918,
       5,   289,   319,   127,   128,   228,   170,   132,  1637,   410,
       5,    17,    18,    19,    20,    21,   311,    17,    18,  2658,
     371,   145,   146,    23,    24,    25,   254,   115,   116,    25,
      22,    45,    22,   319,  1058,     5,    17,    18,   438,     5,
      17,    18,    23,    24,    25,     5,    23,    24,    25,   275,
     338,     5,   527,  2533,   366,   367,  2797,   170,  1970,   324,
     170,   489,   169,   170,   599,   557,   600,   355,     5,   170,
     254,   170,  2909,   607,  2857,  2910,  1967,  1802,   170,    17,
      18,    19,    20,    21,     5,     5,   254,     5,   410,  2168,
     170,   170,     5,  1206,     5,   275,   358,   313,     5,   361,
       5,   327,    24,  1994,    26,   331,   598,   369,  1737,     5,
     170,   254,    37,    38,   848,   849,   438,   891,   170,     0,
    2032,   366,   367,   385,   599,   387,    23,   228,    25,   170,
     262,     5,    17,    18,    19,    20,    21,  2028,     5,    64,
      65,    66,  1372,   275,   410,   418,     5,    24,  2031,   365,
    2033,   187,   414,    24,    30,    26,   429,   419,   542,   421,
     120,     5,   424,   425,  1662,   427,  3003,  1665,   430,     5,
     170,   437,     5,     5,   170,     5,   130,     5,     5,   441,
     324,   324,  2965,   409,   606,     5,   448,     5,     5,   170,
    2411,     5,  2413,   130,     5,     5,  2835,     5,   460,   494,
     364,   601,  1165,     5,     5,     5,   607,   629,   470,     5,
     505,   473,     5,   375,     5,   494,     5,     5,     5,   570,
     648,   483,   214,   347,   214,    23,   369,    25,   451,   409,
     485,   102,   103,   420,   105,   106,  2591,   499,   500,   110,
    3075,   263,   559,   830,   506,  2661,   640,   576,   170,   373,
    1879,   364,   514,     9,   516,   517,   127,   128,   263,   371,
     525,   329,   524,   525,   648,   527,   528,  2186,   530,   410,
     532,  3012,   534,   559,   145,   146,   538,   409,   540,   375,
     542,   506,   544,   545,   519,   547,   548,   353,   550,  2915,
     876,  1965,   878,   558,   390,   420,  1963,   422,   423,   170,
     406,  1008,  1031,   467,    28,  1034,  1035,  1036,   371,   954,
     845,   436,   364,   371,  2579,  2206,  1011,   852,   369,  1037,
     444,   549,   371,   410,  1053,   406,  1805,   520,   416,   454,
     506,   371,   457,   568,   576,   406,   523,   523,   463,   406,
    2128,   406,   467,   379,   534,   216,   471,  1011,   531,   531,
     475,  1504,   342,   367,   479,   480,   406,   482,   371,  1133,
     485,   495,   487,   488,   489,   549,   953,   954,   955,   410,
     495,  1145,   451,   498,   527,   375,   371,   537,   392,  2270,
     505,   549,   481,  2171,   972,   510,   674,  1294,  1295,   651,
     390,  2179,  2180,   518,   375,   530,  1303,   593,   375,   973,
     406,   371,   601,  2032,   529,   371,   549,   599,   533,   390,
     601,  2891,   537,   390,   538,   608,   570,   679,   543,   681,
    1567,   546,  1151,   527,   601,   599,   346,   534,  1146,  1453,
     692,   593,  1456,   607,  1129,  2656,   535,   601,  2659,  1346,
    2661,   643,    27,  2798,  2253,   707,  2525,   557,   648,    24,
     371,   451,   593,   371,   534,   717,   718,  1191,   371,   607,
     371,  1134,   476,   601,   371,  1129,   371,  2947,   406,  1198,
     732,   531,   601,   229,   566,   371,   738,   739,  1978,   593,
    2702,   743,  2077,  1418,   593,   601,   371,   630,   631,   632,
    2054,   753,  2488,  2079,  1223,   619,  2492,   371,   641,  1228,
    1730,  1719,  2458,   627,   371,   601,  1224,  2005,   339,   434,
    1242,   601,   371,   433,  2779,  2780,  1218,  2997,   339,  2999,
     782,    24,   620,   621,   622,   623,   624,   371,    22,  2412,
     450,  2422,  2415,  2424,   225,   371,   438,   250,   371,   371,
     253,   371,   255,   371,   371,    24,   417,   238,  1266,  1267,
    1780,   371,  1639,   371,   371,   569,   319,   371,   304,  1010,
     371,   371,   275,   371,   826,   827,   148,   581,   582,   371,
     371,   371,   285,   493,   155,   371,   590,   340,   371,  2208,
     371,   304,   371,   371,   371,  2214,  2215,  2216,  2217,  2218,
    2219,   304,  2259,  2260,    26,   170,  2791,   522,  2848,   861,
    2850,   601,    25,   262,   438,   867,  2827,  1381,    24,    17,
     366,  2575,   368,   533,   327,    24,   275,   879,   331,   137,
     601,  2257,   884,   418,   601,   456,   984,   889,   361,   987,
     371,   460,  2536,   519,   429,   456,   369,    24,    24,   137,
     565,    24,   562,    26,   473,   907,  2275,   570,    24,   606,
     489,   571,   607,    24,   102,   103,   333,   105,   106,   498,
     922,   519,   110,  1395,   405,   410,  2434,   170,  2147,  2437,
     251,   628,   629,   218,   936,   410,    84,   225,   335,   127,
     128,   414,   568,     0,    17,    18,    19,    20,   598,  2580,
     238,   170,   437,   438,  2889,  2774,   409,   145,   146,   601,
     225,  1149,   437,   438,   543,   830,    23,   546,  2903,   451,
     568,  2602,    84,   238,    23,   461,    25,   459,    18,  2940,
     214,  1453,  1629,    23,  1456,    25,   222,   989,  2516,    20,
     275,   993,   994,   995,     5,   566,   570,  1825,   461,    72,
      73,    74,    75,    76,    77,   566,  1008,   170,   461,  1011,
     409,  1013,  1014,  2018,   170,  1017,   501,   333,   276,  2024,
     620,   170,   134,   623,   624,   456,   501,   601,   216,  1031,
    1032,     5,  1034,  1035,  1036,  1037,  1550,  1039,   276,  3029,
    1042,   472,   327,   170,   170,  1503,   331,   170,  2417,   601,
      42,  1053,  2756,  1055,   170,  1908,   559,  1059,   170,   170,
     172,   218,    27,    28,  2029,  1067,   438,  1069,  1070,  3004,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,   601,   953,   954,
     955,  2884,  2885,  1130,   352,  1132,   418,  1099,  1100,   198,
      13,  1615,  1104,   202,  1106,   410,   461,   429,   342,  2079,
     502,  2076,    92,  2757,   352,  2759,   516,   514,   275,  1121,
     606,   113,   410,   405,   409,  1594,  1595,  1129,   143,   451,
     410,   528,   147,  1135,  1136,  1137,   458,   410,   606,   625,
     626,   438,  1969,   606,  1146,   410,  1148,   410,  1150,  1151,
     437,   438,  1610,  1155,   410,  2786,   553,   269,  2534,   645,
     628,   629,   625,   626,   621,   622,  1993,   529,   456,  1496,
     327,   533,   410,  2542,   331,   537,  2545,  2546,  2547,  2548,
    1292,    25,   645,   410,   472,   410,  1298,   179,   438,   181,
    1192,   456,   645,    18,   410,  2988,  1198,  2990,    23,    24,
      25,   410,  2906,  2090,   196,   602,  2575,   472,  1722,    88,
      89,    90,   204,  1539,   472,  1217,   208,   418,   410,  1221,
      25,  1223,  1224,    24,    25,   337,  1228,  2858,   429,   417,
    1232,  1233,  1234,   345,   472,   250,  1334,   349,   253,   437,
     438,   233,  1244,   315,   410,  1343,   594,   595,   596,   597,
     451,   606,   409,   607,   326,   544,  1258,   458,   547,  1731,
     275,   550,   607,  1265,  1266,  1267,  2918,  1781,   410,  1783,
     625,   626,   143,    25,   386,    25,   147,    20,  1792,    16,
      17,    18,    19,    20,    21,  2068,    25,  2070,  2071,  1291,
     645,  1618,  1294,  1295,    25,  2664,   457,  1299,   371,  1301,
     171,  1303,    25,  2955,   438,  1952,   378,   267,   268,   601,
     471,  1339,  1639,    25,   475,    25,    17,    18,    19,    20,
      25,   393,    25,  1981,   601,  1376,   487,   346,    25,    72,
      73,    74,    75,    76,    77,    72,    73,    74,    75,    76,
      77,   143,   454,    25,  1346,   147,    39,   446,   447,  1996,
     371,    88,    89,    90,   623,   624,  1358,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   410,  1369,   341,   171,
    1372,    72,    73,    74,    75,    76,    77,   601,   139,   250,
      25,   493,   253,  1248,   630,   631,   410,  2756,   410,  1391,
    1392,  1393,   406,  2762,   409,   156,   157,  1869,     5,  2252,
    2197,   371,  3033,   164,   275,  2656,   518,  2783,  2659,   630,
     631,   483,   601,  2878,   433,    25,    72,    73,    74,    75,
      76,    77,   238,  2792,   406,  1427,  1428,  1429,  2797,  1431,
     371,   450,    88,    89,    90,   846,   847,   198,   371,   850,
     851,   341,   541,    20,    25,    25,   207,    25,   250,    25,
     562,   253,   551,    25,    20,  1457,   410,    25,  1460,   571,
       9,  2989,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,  1474,   275,   493,   236,   601,    25,  2443,    25,
    2450,   371,     5,   371,  2853,    17,    18,    19,    20,    21,
    1492,   170,   229,   439,   648,   232,  1498,  1901,  1500,  1501,
    1502,  1503,  2967,   371,   423,   250,   282,   371,   253,   371,
     255,   371,   371,   605,   533,     5,   371,   436,   282,   371,
     281,  2986,    29,    72,    73,    74,    75,    76,    77,   250,
     275,  1533,   253,   371,   255,   605,  1538,  2906,   409,  2908,
     285,  2910,   371,   562,   463,   371,  1548,   321,   601,    24,
    1552,  1747,   571,   438,   275,   598,   330,  1559,     8,   304,
     479,   480,   323,   601,   285,  1567,   485,   406,    24,   488,
    2084,   506,  1574,   229,  1576,  2944,   232,  3042,   459,   410,
     354,   246,   327,   357,     5,   400,   331,   410,   410,   410,
     410,   410,  1594,  1595,   439,   102,   103,   410,   105,   106,
     410,   375,   410,   110,   410,   599,   327,   409,  1610,  1748,
     331,   410,   711,  1752,   351,   410,   410,  2131,  1757,   410,
     127,   128,  1761,   410,  1763,  1764,  1765,  1629,   410,   366,
     410,  1496,   410,   370,   640,  1637,  1963,   410,   145,   146,
     410,   410,  1969,  3012,   410,   410,  1648,   410,  2615,     4,
       5,     6,     7,     8,     9,  2508,    11,   599,   757,  1661,
    1662,   576,  3031,  1665,   409,   400,  1993,   439,   410,   640,
     371,   408,   306,   346,    17,    18,    19,    20,  2506,  1681,
       8,  1683,  1684,   232,   577,  1687,  1688,     5,   409,  2940,
      17,    18,    19,    20,     5,   351,   363,   410,    24,   436,
     324,   410,  3071,   410,   410,   570,  3075,   481,   410,   559,
     366,     8,  1714,    13,   370,   556,   461,  1719,   455,     5,
     640,  1723,    72,    73,    74,    75,    76,    77,  1730,    72,
      73,    74,    75,    76,    77,  1737,     5,   640,   400,   410,
     461,   410,    25,    25,    46,    72,    73,    74,    75,    76,
      77,    71,   408,  1618,   346,    17,    18,    19,    20,   410,
     433,   535,   438,   438,    25,     5,   410,  1769,   542,  2238,
    1772,  2240,   410,    20,  1639,   346,   576,   450,  1780,   410,
     436,   570,  1784,  1785,  1786,  1787,    20,  1789,    17,    18,
      19,    20,   601,  1795,  1796,   410,   451,  1799,  1800,   455,
     537,   410,   351,   607,    20,   410,  1808,  2454,   410,  2512,
      72,    73,    74,    75,    76,    77,  1818,   607,   606,   410,
     493,   410,   371,   607,   330,   643,   537,   926,     9,   336,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      17,   433,    18,    72,    73,    74,    75,    76,    77,   346,
       5,    25,    25,  1718,   132,    24,   198,   604,   450,   408,
     533,   559,   433,  1865,   462,  1867,   570,   604,  2721,    15,
      16,    17,    18,    19,    20,    21,  2729,  1879,   385,   450,
     462,   537,     5,     5,   527,   130,   113,   527,  1890,   562,
      25,    72,    73,    74,    75,    76,    77,   379,   571,  1901,
     645,   493,   301,    24,   527,    25,   346,  1909,  2350,  2351,
    2352,   410,  2354,  2355,  2356,  2357,  2358,  2359,   410,   410,
     346,  2363,   493,   410,   645,   410,    72,    73,    74,    75,
      76,    77,  2259,  2260,  2448,   601,   433,   645,   557,    98,
     527,   533,    88,    89,    90,   448,   371,     7,   604,   371,
    1952,   371,   179,   450,   181,   371,   371,    17,    18,    19,
      20,  2475,   533,     5,   371,  1967,  2018,   470,  1970,   196,
     562,   371,  2024,    25,   371,  1977,  1978,   204,   371,   571,
     371,   208,  1984,   371,  1986,   598,    24,   410,   537,   607,
       5,   562,  1994,   433,  1996,     5,   493,     5,   560,     5,
     571,   601,   463,  2005,   113,   371,   233,   433,   607,   410,
     450,   514,    72,    73,    74,    75,    76,    77,   606,     5,
     410,   524,   525,  2876,   450,   528,  2028,    25,   371,   532,
    2032,   534,  2034,  2018,   583,   538,   533,   540,  2496,  2024,
     534,    25,   201,  2045,   371,  2503,   410,  2694,   516,    46,
     209,   232,  2054,   493,   305,   604,   215,   371,   217,     5,
     340,   371,   371,   410,   410,   562,  1165,   493,   577,   228,
     179,   607,   181,   601,   571,  2077,    13,  2079,   400,   400,
       5,   641,   531,   229,   527,  2087,   232,   196,  2090,  1954,
    2917,     5,    25,   533,   451,   204,    59,   256,  1963,   208,
      80,   601,   410,   607,  1969,   410,     5,   533,   606,   371,
     219,    24,    29,   272,   406,   620,   406,   440,   277,  1218,
       8,   440,   562,   410,   233,  2127,  2128,   371,  1993,   410,
     289,   571,     5,   410,   410,  2137,   562,   296,  2140,   410,
     410,    25,   371,  2145,   410,   571,    25,   371,  3001,  2970,
    2971,  2972,  2973,  2974,  2975,    24,  2158,   570,  2160,   371,
    2162,    24,    24,   371,    24,   371,     5,  2169,   601,  2171,
     351,   134,   135,  2175,  1273,     5,     8,  2179,  2180,  2882,
     305,   324,   601,   601,  2049,   102,   103,   324,   105,   106,
     438,   601,   324,   110,   405,  2197,   410,    20,   240,   340,
     410,  2848,     5,  2850,  2206,   351,  2208,   410,   410,  2723,
     127,   128,  2214,  2215,  2216,  2217,  2218,  2219,   410,   410,
     366,    19,    20,   410,   370,   410,   189,   408,   145,   146,
     632,    25,   195,     5,     5,     5,  2238,   279,  2240,     5,
      25,   576,   576,   410,   598,     5,   284,   564,   601,   601,
       5,  2720,   290,   291,   292,     5,   298,     5,   410,   371,
       7,     5,   408,    17,    18,   601,    20,   607,  2270,    23,
      24,    25,   310,  2275,    72,    73,    74,    75,    76,    77,
      25,     8,    25,    25,   371,   371,  2614,    25,   371,   371,
     436,    45,   451,   371,   607,   337,   570,   371,   371,   458,
     607,    20,  2490,   266,     5,   268,   547,   349,    20,   455,
      17,    18,    19,    20,   254,   371,     5,   359,     5,     5,
    2322,   480,   963,   826,    20,   220,   485,   527,   371,  2331,
    2332,  2333,   552,   438,   607,   377,   601,  2339,  2529,  2204,
     420,   601,   371,   410,   451,   387,     6,   190,   607,   607,
     534,   534,   605,  2867,    24,   605,   537,    24,   861,    24,
     426,   403,   600,    24,   867,    72,    73,    74,    75,    76,
      77,    24,   451,    25,    25,    25,   879,    25,    25,   342,
     418,   884,  3029,   421,   410,   410,    25,   276,   601,    25,
       5,   537,   371,   371,  2259,  2260,   248,   448,  2400,  3102,
    2402,   443,   583,   506,   570,     5,   410,   445,    20,  2411,
     371,  2413,   531,   220,   406,  2417,   170,   371,     5,   371,
    2422,   420,  2424,   604,   324,   467,    20,   465,   119,    13,
       5,    13,   190,   442,     5,    20,   601,   371,   421,    25,
     482,   371,   371,   371,    25,     5,    26,   489,  2450,   600,
     492,   348,  2454,   311,   410,   371,   549,   353,   604,    25,
      17,    18,   500,    20,  2466,   371,    23,    24,    25,   432,
     371,   513,   410,   324,   516,   221,   518,  1576,   371,   607,
     556,   527,   520,   521,   410,   219,  2488,   219,    45,  2491,
    2492,    25,   607,   531,  2496,   537,   438,  2499,   536,   371,
     427,  2503,    25,   466,   372,   410,   601,   371,   607,   472,
     607,   474,     5,   555,  2516,   478,    13,     5,   481,   406,
     274,   484,     5,   371,    24,  2527,    20,   221,   410,   371,
       5,   494,  2087,   371,   371,  2174,  3052,   575,  1637,  2127,
    2542,    20,    21,  2545,  2546,  2547,  2548,  2549,  1855,  1235,
     513,  1560,    36,    38,  2556,   366,  1796,  2158,   521,   522,
     523,  1802,   211,   289,   527,   142,   283,   146,   290,   398,
     608,  2573,   535,  2575,   355,    21,  1338,  1755,  2580,  1339,
     213,   373,  1681,   318,  2461,   385,   317,  2589,   551,  1688,
    2917,   387,  2594,    72,    73,    74,    75,    76,    77,  3042,
    2602,  1533,  2604,  1772,   527,  1408,  1666,  1659,  1502,    88,
      89,    90,   960,   170,  1006,  1786,  1265,  3067,  2233,  1905,
    1268,   375,  2559,  1590,  1605,  1790,    72,    73,    74,    75,
      76,    77,  1135,  1136,  1137,  2247,   390,  1151,  1737,  2249,
    2737,    23,    88,    89,    90,   118,    29,  2636,    29,  1565,
     484,   653,  1155,   407,  2656,  1245,   410,  2659,   268,  2661,
    1571,   681,  2664,   927,  1903,  1273,  1574,  2669,   422,   423,
    2812,  2633,  1142,  1189,  1621,  2986,  2215,  1132,  2390,  2822,
     879,  1063,  1217,  2388,  1325,  1326,  2372,  2027,  1017,  1192,
    1780,  1332,  2694,  1352,  1375,  2796,  2698,   451,  2700,  1963,
    3071,  3033,  1997,  2923,  2028,  2421,  2694,  2455,  1687,  2400,
     464,  2034,  2402,  2659,  1217,  2940,  1291,  2582,  2720,  2840,
    2333,   956,   476,  2725,  2859,  2045,  2271,  2860,  2778,  2275,
    3031,  1234,  2827,  1287,  2214,  2901,  1260,   952,  2589,  1147,
     364,  1244,  1719,    -1,    -1,    -1,    -1,    -1,   711,    -1,
     229,    -1,    -1,   232,  2756,    -1,    -1,    -1,    -1,    -1,
    2762,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,    -1,
      -1,  1870,  1871,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1879,    -1,    -1,   229,  2786,    -1,   232,    -1,    -1,    -1,
    2792,    -1,    -1,    -1,  2796,  2797,    -1,    -1,    -1,    -1,
      -1,    -1,  2804,   557,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   569,   779,    -1,   375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,   583,
      -1,    -1,    -1,   390,    -1,    -1,   590,    -1,    -1,   593,
      -1,    -1,    -1,    -1,    -1,    -1,  2848,   601,  2850,    -1,
     407,  2853,    -1,   410,    -1,    -1,  2858,    -1,  2860,   822,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
      -1,  1970,   351,   836,   837,   838,    -1,   840,    -1,   842,
     843,    -1,    -1,    -1,    -1,   848,   849,   366,    -1,    -1,
      -1,   370,    -1,    -1,   451,    -1,    -1,    -1,    -1,  2901,
      -1,    -1,  1543,    -1,  2906,   351,  2908,   464,  2910,    -1,
      -1,    -1,    -1,  2915,    -1,    -1,  2918,    -1,    -1,   476,
     366,  2923,    -1,    -1,   370,    -1,    -1,    -1,   891,   408,
      -1,    -1,    -1,  2032,    -1,  2034,    -1,    -1,  2940,   902,
      -1,    -1,  2944,    -1,    -1,  1586,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2955,    -1,    -1,    -1,   436,    -1,    -1,
      -1,   518,   408,   926,   927,    -1,    -1,    -1,    -1,    -1,
      -1,  1474,   935,    -1,    -1,  2074,   455,    -1,    -1,  2981,
    2982,    -1,    -1,    -1,    -1,    -1,    -1,  2989,   951,   952,
     436,    -1,    -1,    -1,    -1,  1498,    -1,    -1,    -1,  1502,
     557,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,
    3012,    -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,   582,    -1,  3029,    -1,  3031,
    1533,  3033,    -1,   590,    -1,    -1,   593,    -1,   717,   718,
      -1,    -1,    -1,    -1,   601,    -1,    -1,  1010,    -1,    -1,
      -1,    -1,  2917,   732,    -1,    -1,  1559,    -1,   537,   738,
     739,    53,    54,    -1,   743,    57,    58,    59,    -1,  3071,
      -1,    -1,    -1,  3075,   753,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3087,    -1,    -1,    -1,    -1,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2208,
      -1,    -1,    -1,    -1,    -1,  2214,  2215,  2216,  2217,  2218,
    2219,    -1,    -1,    -1,    -1,   604,    -1,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,   604,  1122,
      -1,    -1,    -1,    -1,    -1,   157,    -1,  1130,    -1,  1132,
    1133,  1134,   164,    45,    -1,    -1,  2275,    -1,  1141,  1142,
      -1,    -1,  1145,    -1,    -1,    -1,  1149,    -1,    -1,  1152,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,  1165,    -1,    -1,    -1,   198,    -1,  1849,  1850,
      -1,    88,    89,    90,    -1,   207,    -1,    -1,    -1,  1860,
    1723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,    -1,    -1,    -1,    -1,
      -1,  2350,  2351,  2352,    -1,  2354,  2355,  2356,  2357,  2358,
    2359,    -1,    -1,    -1,  2363,    -1,    -1,  1230,    -1,    -1,
      -1,    -1,    -1,  1914,  1915,  1916,  1917,    -1,    -1,    -1,
      -1,  1784,  1785,  1786,  1787,    -1,    -1,    -1,  1929,   281,
      -1,  1254,    -1,    -1,    -1,    -1,  1259,    -1,   170,    -1,
      -1,  2400,    -1,  2402,    -1,  1808,    -1,    -1,    -1,  1272,
    1273,    -1,  2411,    -1,  2413,    -1,    -1,    -1,  2417,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   323,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,  1032,    -1,   232,    -1,    -1,    -1,    -1,
    1039,    -1,  1865,  1042,  1327,  2006,  2007,    -1,    -1,    -1,
      -1,    -1,  2013,  2014,    -1,    -1,  1055,    -1,    -1,    -1,
    1059,    -1,    -1,    -1,    -1,    -1,    -1,   379,  1067,    29,
    1069,  1070,    -1,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
      -1,    -1,    -1,  2512,    -1,    55,    -1,    -1,  1381,    -1,
    1099,  1100,    -1,    -1,    -1,  1104,    -1,  1106,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2542,    -1,    -1,  2545,  2546,  2547,  2548,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,   102,   103,    -1,   105,   106,    -1,    -1,    -1,
     110,    -1,    -1,    -1,   351,    -1,  2575,    -1,    -1,    -1,
      -1,  1984,    -1,  1986,    -1,    -1,    -1,   127,   128,   366,
      -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   375,    -1,   145,   146,  2148,  2149,    -1,
      72,    73,    74,    75,    76,    77,  2157,    -1,   390,    -1,
      -1,    -1,    78,    -1,  2165,    -1,    88,    89,    90,    -1,
      -1,   408,    -1,    -1,    -1,   407,    -1,    -1,   410,    -1,
      -1,    -1,  2183,  2184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,    -1,    -1,  2656,   279,   436,
    2659,    -1,  2661,    -1,    -1,  2664,    -1,    -1,  1531,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   216,  1540,   455,   451,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1550,    -1,    -1,
      -1,   463,   464,    -1,    -1,    -1,    -1,    -1,  2239,    -1,
    2241,    -1,    -1,    -1,   476,    -1,    -1,  2248,  1571,  2250,
      -1,    -1,    -1,    -1,    -1,    -1,   337,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,    -1,   349,    -1,
      -1,    -1,    -1,    -1,  2137,    -1,    -1,  2140,   359,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,
      -1,    -1,  1615,  1616,  1617,    -1,   377,  2756,  1621,    -1,
     537,    -1,    -1,  2762,    -1,    -1,   387,   229,    -1,   390,
     232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   403,    -1,    -1,   557,    -1,    -1,    -1,    -1,
    1653,    -1,    -1,  2792,  2197,    -1,   336,   569,  2797,  2340,
    2341,    -1,    -1,  2344,  2345,    -1,    -1,    -1,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,    -1,
      -1,   593,    -1,    -1,    -1,    -1,    22,   604,  2827,   601,
      -1,   452,    -1,    -1,    -1,    -1,    -1,  2378,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   385,    -1,    43,  1427,  1428,
    1429,    -1,  1431,    -1,  2853,    -1,   312,    -1,    -1,  1722,
      -1,   482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,
      -1,   492,    -1,    -1,    -1,    71,    -1,   417,  1457,    -1,
      -1,    -1,    -1,  2882,    -1,    -1,    -1,    -1,    -1,   351,
      -1,    -1,   513,    -1,    -1,   516,    -1,   518,    -1,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,  2906,   370,  2908,
      -1,  2910,    -1,    -1,    -1,    -1,    -1,   113,  1781,  2918,
    1783,    -1,    -1,    -1,    -1,   546,    -1,    -1,    -1,  1792,
      -1,    -1,    -1,   389,   555,    -1,    -1,    -1,    -1,    -1,
     396,  2940,    -1,    -1,    -1,  2944,   408,   143,  2489,    -1,
      -1,   147,  2493,    -1,    -1,    -1,  2955,    -1,    -1,  1538,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1830,    -1,    -1,
      -1,    -1,    -1,  1552,   436,   171,    -1,    -1,    -1,   435,
      -1,    -1,  2523,   179,    -1,   181,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,   190,    -1,  1859,    -1,    -1,    -1,
     196,    -1,    -1,    -1,   460,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,  3012,   470,   471,  2557,    -1,   214,    -1,
      -1,    -1,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     486,    -1,  3031,    -1,    -1,    -1,    -1,   233,    -1,  1902,
    1903,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   508,    -1,   250,   511,   512,   253,    -1,   255,
      -1,   517,    -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,  3071,    -1,    -1,   537,  3075,    -1,    -1,   275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,
      -1,    -1,    -1,    -1,    -1,    -1,  2499,    -1,    -1,    -1,
      -1,    -1,    -1,  3102,    -1,    -1,    -1,    -1,   304,   305,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,
      -1,    -1,    -1,   319,  2527,    -1,    -1,    -1,    -1,    -1,
     586,   327,    -1,    -1,    -1,   331,    -1,    -1,    -1,    -1,
      -1,  2004,   604,    -1,   340,   341,   342,    -1,    -1,    -1,
      -1,    -1,    -1,  2556,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
    1769,    -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,  2753,   409,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2084,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,   461,    -1,    -1,  2131,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2164,    88,    89,    90,    -1,    -1,    -1,    -1,  2172,
      -1,  2174,    -1,  2176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2725,    -1,    -1,    -1,  2189,   523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,  2886,    -1,    19,    20,    21,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,    -1,    -1,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,  2928,  2929,    -1,
    2931,   229,  2933,  2934,   232,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     606,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,   620,   621,   622,   623,   624,   625,
     626,    -1,   628,   629,    -1,    -1,    72,    73,    74,    75,
      76,    77,    -1,   229,    -1,   260,   232,    -1,    -1,   645,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,  3000,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2334,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3020,
      -1,  3022,    -1,    -1,    -1,   300,   301,   302,    -1,    -1,
      -1,    -1,    -1,   229,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     325,  2374,    -1,   351,    -1,    -1,  3057,    -1,   333,    -1,
      -1,    -1,    -1,   338,  2387,    -1,    -1,    -1,   366,    -1,
      -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,   353,    -1,
    3081,  3082,    -1,   358,  3085,   360,    -1,    -1,  2127,  2128,
      -1,    78,   367,    -1,    -1,   370,    -1,   229,   373,    -1,
     232,   376,    -1,    -1,   379,   351,    -1,    -1,    -1,   384,
     408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2981,    -1,
     366,    -1,    -1,    -1,   370,  2448,    -1,   402,    -1,    -1,
    2169,    -1,  2171,   229,    -1,    -1,   232,    -1,   436,    -1,
    2179,  2180,    -1,   418,    -1,    -1,   421,   422,    -1,    -1,
      -1,    -1,  2475,   428,    -1,   351,    -1,   455,    -1,    -1,
      -1,    -1,   408,    -1,   439,    -1,    -1,  2490,    -1,    -1,
     366,    -1,    -1,    -1,   370,   371,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,    -1,    -1,    -1,   462,    -1,  2512,
     436,    -1,    -1,    -1,   469,    -1,   183,   472,   473,   474,
      -1,   476,   477,    -1,    -1,    -1,  2529,    -1,    -1,   455,
      -1,    -1,   408,    -1,    -1,    -1,    -1,    -1,   493,   351,
      -1,    -1,    -1,    -1,  3087,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,   370,   537,
     436,    -1,   517,   518,   519,   520,    -1,   522,    -1,    -1,
      -1,    -1,   239,    -1,    -1,   351,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,   539,   540,    -1,    -1,  2591,    -1,
     366,    -1,    -1,    -1,   370,   371,   408,   264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   273,   562,    -1,    -1,
      -1,   537,    -1,    -1,    -1,    -1,   571,   572,    -1,   574,
      -1,    -1,    -1,    -1,   436,    -1,   604,    -1,    -1,    -1,
    2633,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   309,   455,    -1,   312,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   325,    -1,
     436,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,   455,
      -1,   636,    -1,    -1,    -1,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2723,    -1,   389,    -1,    -1,   537,    -1,    -1,   604,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   411,    -1,    -1,  2466,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,   435,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   604,   460,    -1,  2798,    -1,  2516,    -1,    -1,
      -1,    -1,    -1,   470,   471,    -1,    -1,    -1,    -1,  2812,
      -1,    -1,    -1,    -1,  2817,    -1,  2819,    -1,    -1,   486,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   508,    -1,    -1,   511,   512,    -1,    -1,    -1,    -1,
     517,    -1,    -1,    -1,    -1,    -1,  2859,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2867,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2882,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,   574,    -1,    -1,
      33,   229,    35,    -1,   232,    -1,    -1,   584,    -1,   586,
      -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,  2970,  2971,  2972,
    2973,  2974,  2975,    -1,    97,    -1,    99,   100,   101,   102,
     103,   104,   105,   106,   107,    -1,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,   121,    -1,
     123,   124,   125,    -1,   127,   128,    -1,    -1,    -1,    -1,
     133,    -1,   135,   136,    -1,   138,    -1,   140,   141,    -1,
      -1,   144,   145,   146,    -1,    -1,   149,   150,   151,    -1,
     153,   154,    -1,   351,    -1,   158,   159,    -1,   161,    -1,
      -1,    -1,   165,    -1,   167,   168,    -1,    -1,   366,    -1,
     173,    -1,   370,   371,   177,    -1,    -1,   180,    -1,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,   197,    -1,   199,   200,    -1,   202,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,   211,    -1,
     408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3102,
     223,    -1,    -1,   226,   227,    -1,    -1,   230,   231,    -1,
      -1,   234,   235,    -1,    -1,    -1,    -1,    -1,   436,    -1,
     243,   244,   245,    -1,   247,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   455,   261,    -1,
      -1,    -1,   265,   266,    -1,    -1,    -1,   270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   278,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   287,   288,    -1,    -1,    -1,    -1,
      -1,   294,   295,    -1,    -1,    -1,    -1,   300,    -1,    -1,
     303,    -1,    -1,    -1,   307,   308,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   318,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   336,    -1,    -1,    -1,    -1,    -1,   537,
      -1,   344,    -1,    -1,    -1,    -1,    -1,   350,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
     373,    -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,   382,
     383,    -1,    72,    73,    74,    75,    76,    77,   391,    -1,
    2989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   430,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,    -1,    -1,   441,    -1,
      -1,    -1,   445,    -1,    -1,    -1,   449,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     473,   474,    -1,    -1,    -1,   478,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,    -1,    -1,
      -1,    -1,    -1,   496,   497,   498,   499,    -1,    -1,    -1,
     503,    -1,    -1,    -1,   507,    -1,    -1,    -1,    -1,    -1,
      -1,   514,   515,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   526,    -1,   528,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,   539,    -1,   541,   229,
      -1,   544,   232,    -1,    -1,    -1,    -1,   550,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,    -1,   576,   232,    -1,   579,    -1,    -1,    -1,
      -1,    -1,   585,    -1,    -1,   588,   589,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     603,    -1,    -1,    -1,    -1,    -1,    -1,   610,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,   634,   635,   636,   637,   638,   639,    -1,    -1,   642,
      -1,   644,    -1,   646,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    -1,    -1,   366,    -1,    -1,    -1,
     370,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,   370,   371,    -1,    -1,    -1,    -1,   408,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,
     408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,   351,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,   371,    -1,    -1,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   408,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,   537,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   604,    -1,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,   232,   604,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,   232,    -1,    -1,    -1,   604,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   229,    -1,    -1,   232,    -1,    -1,   366,
      -1,    -1,    -1,   370,   371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,
     229,    -1,    -1,   232,    -1,   366,    -1,    -1,    -1,   370,
     371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     366,    -1,    -1,    -1,   370,    -1,    -1,   408,    -1,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
     537,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   455,   421,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
     436,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    88,    89,    90,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,   604,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    17,    18,    -1,    20,
      -1,    -1,    23,    24,    25,    -1,   537,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,   537,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   351,    -1,    -1,    -1,   455,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,    -1,   604,    -1,    -1,    -1,    -1,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   229,    -1,    -1,   232,    -1,    -1,   604,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,   537,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,   170,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
     229,    -1,    -1,   232,    -1,   604,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   537,   366,
      -1,    -1,    -1,   370,    88,    89,    90,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    88,    89,    90,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   408,    -1,    -1,    88,    89,    90,    14,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,   229,
      -1,    -1,   232,    -1,    -1,   604,    -1,    -1,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,   390,
      -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,   408,
      -1,    -1,    -1,    -1,    -1,   229,   407,    -1,   232,   410,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   423,    -1,    -1,   229,    -1,   436,   232,    -1,
     537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,    -1,   229,   455,    -1,   232,    72,
      73,    74,    75,    76,    77,    -1,   366,    -1,    -1,    -1,
     370,    -1,   463,   464,    -1,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    17,    18,   476,    -1,    -1,    -1,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,   604,   408,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,   229,    -1,    -1,   232,   436,   351,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,
      -1,    -1,   366,    -1,    -1,   455,   370,   351,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,
      -1,    -1,   366,    -1,    -1,    -1,   370,   351,   569,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,   582,   366,    -1,   408,    -1,   370,    -1,    -1,   590,
      -1,    -1,   593,    -1,    -1,   604,    -1,    -1,    -1,    -1,
     601,    -1,    -1,    -1,   408,    -1,   229,    17,    18,   232,
      -1,    -1,   436,    23,    24,    25,    26,   421,   240,    -1,
      -1,    -1,    -1,    -1,   408,    -1,   170,   537,   172,    -1,
      40,   455,   436,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    51,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,
      -1,   455,   436,    -1,    -1,    -1,    -1,   279,    -1,   366,
      -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,    -1,    79,
      -1,   455,    -1,    -1,    17,    18,   298,    -1,    -1,    -1,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   604,    -1,    -1,    40,    -1,    -1,
      -1,   408,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,    -1,   537,    -1,   337,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   269,    -1,   349,   351,   436,
     274,    -1,    -1,   537,    -1,    -1,    79,   359,    -1,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,   370,   455,    -1,
      -1,    -1,    -1,   537,    -1,   377,    -1,    -1,   302,    -1,
     170,    -1,   172,    -1,    -1,   387,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     604,   403,    -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
     604,    -1,    -1,    -1,    -1,   349,    -1,    -1,    17,    18,
      -1,    20,    -1,   436,    23,    24,    25,    -1,    -1,    -1,
     604,   443,    -1,   367,    -1,    -1,    -1,   170,   372,   172,
     537,   375,   455,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,   386,    -1,    -1,   467,    -1,    -1,   392,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,   269,
     482,    -1,    -1,   407,   274,    -1,   410,   489,    -1,   413,
     492,    -1,    -1,    -1,    -1,    17,    18,    -1,   422,   423,
      -1,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   513,   302,    -1,   516,    -1,   518,   604,    40,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,   537,   537,    -1,    -1,    -1,   463,
     464,    -1,    -1,    -1,   468,    -1,   269,   337,    -1,    -1,
      -1,   274,   476,   555,    -1,    -1,    -1,    79,    -1,   349,
      -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,   493,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,   302,
      -1,   170,   372,    -1,    -1,   375,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   518,    -1,   386,    -1,    -1,    -1,
      -1,   604,   392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   402,    -1,   337,    -1,    -1,   407,    -1,    -1,
     410,    -1,    -1,   413,    -1,    -1,   349,    -1,    -1,    -1,
      -1,    -1,   422,   423,    -1,    -1,    -1,    -1,   562,    -1,
      -1,    -1,    -1,    -1,   367,   569,    -1,   571,   170,   372,
     172,    -1,   375,    -1,    -1,    -1,    -1,   581,   582,   583,
      -1,    -1,    -1,   386,    -1,    -1,   590,    -1,    -1,   392,
      -1,    -1,    -1,    -1,   464,    -1,    -1,   601,   468,   402,
      -1,    -1,    -1,    -1,   407,   274,   476,   410,    17,    18,
     413,    -1,    -1,    -1,    23,    24,    25,   487,    -1,   422,
     423,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     463,   464,    -1,    -1,    -1,   468,    -1,   269,    -1,    -1,
      79,    -1,   274,   476,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   487,    -1,    -1,    -1,    -1,    -1,
     493,    -1,   562,    -1,    -1,    -1,    -1,    -1,    -1,   569,
     302,   571,    -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,
      -1,   581,   582,   583,    -1,   518,    -1,    -1,    -1,    -1,
     590,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   601,    -1,    -1,    -1,   337,    -1,    -1,   407,    -1,
      -1,   410,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,
      -1,    -1,    -1,   422,   423,    -1,    -1,    -1,    -1,   562,
      -1,   170,    -1,   172,    -1,   367,   569,    -1,   571,    -1,
     372,    -1,    -1,   375,    -1,    -1,    -1,    -1,   581,   582,
     583,    -1,    -1,    -1,   386,    -1,    -1,   590,    -1,    -1,
     392,    -1,    -1,    -1,    -1,   464,    -1,    -1,   601,    -1,
     402,    -1,    -1,    -1,    -1,   407,    -1,   476,   410,    -1,
      -1,   413,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,
      -1,    -1,    23,    24,    25,    -1,    -1,    -1,    -1,   518,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
     269,    -1,   464,    -1,    45,   274,   468,    -1,    -1,    -1,
      51,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   487,    -1,   489,   557,    -1,
      -1,   493,    -1,   302,    -1,    17,    18,    -1,    79,    -1,
     569,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,   582,   583,    -1,   518,    -1,    40,    -1,
      -1,   590,    -1,    45,   593,    -1,    -1,    -1,   337,    51,
      -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     349,    -1,    -1,    -1,    -1,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    -1,    -1,    79,   367,    -1,
     562,    -1,   371,   372,    -1,    -1,   375,   569,    -1,   571,
      -1,    -1,    -1,    45,    -1,    -1,    -1,   386,    -1,   581,
     582,   583,    -1,   392,    -1,    -1,    -1,    -1,   590,   170,
      -1,   172,    -1,   402,    -1,    -1,    -1,    -1,   407,   601,
      -1,   410,    -1,    -1,   413,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   422,   423,    -1,    -1,    -1,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,   170,    -1,
     172,    -1,    -1,    -1,    -1,   464,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,   274,    17,    18,    -1,    20,   170,    31,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,   518,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   302,    45,    -1,    -1,    -1,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,   274,   562,    -1,    -1,   337,    -1,    -1,    -1,
     569,    -1,   571,    -1,    -1,    -1,    -1,    -1,   349,    -1,
      -1,   170,   581,   582,   583,    -1,    -1,    -1,    -1,    -1,
     302,   590,    -1,    -1,    -1,    -1,   367,    -1,    -1,    -1,
      -1,   372,   601,    -1,   375,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   274,    -1,    -1,   386,    17,    18,    -1,    20,
      -1,   392,    23,    24,    25,   337,    17,    18,    -1,    20,
      -1,   402,    23,    24,    25,    -1,   407,   349,    -1,   410,
      -1,    -1,   413,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,   422,   423,    -1,    45,   367,    -1,   170,    -1,    -1,
     372,    -1,    -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   386,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     402,    -1,   463,   464,    -1,   407,    -1,   468,   410,    -1,
      -1,   413,    -1,    -1,    -1,   476,    -1,    -1,    -1,    -1,
     422,   423,    -1,   375,    -1,    -1,   487,    -1,   240,    -1,
      -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   407,    -1,   518,   410,    -1,
      -1,    -1,   464,    -1,    -1,    -1,   468,   279,    -1,    -1,
     422,   423,    -1,    -1,   476,    -1,    -1,    -1,    -1,   170,
      -1,    -1,    -1,    -1,    -1,   487,   298,    -1,    -1,   170,
      -1,   493,    -1,    -1,    -1,    -1,   375,    -1,    -1,    -1,
      -1,   562,   314,    -1,    -1,    -1,    -1,    -1,   569,    -1,
     571,   390,   464,    -1,    -1,    -1,   518,    -1,    -1,    -1,
     581,   582,   583,    -1,   476,   337,    -1,    -1,   407,   590,
      -1,   410,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,
     601,    -1,    -1,    -1,   423,    -1,    -1,   359,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     562,    -1,    -1,    -1,    -1,   377,   518,   569,    -1,   571,
      -1,    -1,   375,    -1,    -1,   387,    -1,    -1,    -1,   581,
     582,   583,    -1,    -1,   463,   464,    -1,   390,   590,    -1,
      -1,   403,    -1,    -1,    -1,    -1,    -1,   476,    -1,   601,
      -1,    -1,    -1,    -1,   407,   557,    -1,   410,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     582,   443,    -1,    -1,    -1,    -1,    -1,    -1,   590,   518,
      -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,
      -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,    -1,    -1,
     463,   464,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     482,    -1,    -1,   476,    -1,    -1,    -1,   489,   557,    -1,
     492,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,    -1,
     569,    -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,   390,
      -1,   513,   581,   582,   516,    -1,   518,    -1,    -1,   390,
      -1,   590,    -1,    -1,   593,   518,   407,    -1,    -1,   410,
      -1,   108,   601,    -1,    -1,   537,   407,    -1,    -1,   410,
     117,    -1,   423,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,   423,   555,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,    -1,    -1,
      -1,    -1,   463,   464,    -1,    -1,    -1,    -1,   581,   582,
      -1,    -1,    -1,   464,    -1,   476,   598,   590,   175,    -1,
     593,    -1,    -1,    -1,    -1,   476,   183,    -1,   601,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   557,   264,   569,    -1,
      -1,    -1,    -1,    -1,   271,    -1,   273,    -1,   569,    -1,
     581,   582,    -1,    -1,    -1,    -1,   283,    -1,    -1,   590,
     581,   582,   593,    -1,    -1,    -1,    -1,    -1,    -1,   590,
     601,    -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     601,    -1,   309,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   429,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   529,   530,   531,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   646
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    55,   102,   103,   105,   106,   110,   127,   128,
     145,   146,   216,   336,   385,   417,   707,   735,   736,   786,
     954,  1009,  1011,  1012,  1013,  1018,  1020,  1033,  1034,  1035,
    1036,  1037,  1443,    27,    28,   708,   709,   710,   711,   712,
     917,   921,   335,   514,   528,   553,   602,  1444,  1444,  1444,
    1444,  1444,  1444,  1444,  1444,   917,    24,   917,  1381,  1038,
     737,   736,  1443,     0,  1010,  1013,  1018,  1036,  1443,    30,
     710,   712,    26,  1462,   917,  1446,   570,   917,  1445,   607,
     787,    24,   170,   734,   735,   905,   917,   924,  1039,  1075,
    1076,  1077,  1078,  1079,  1083,   333,   739,   740,   741,   742,
     745,   746,    36,    41,    85,    86,    93,   347,   373,   444,
     538,   619,   627,   707,   713,   877,   953,  1014,  1015,  1017,
    1021,  1022,  1028,  1040,  1061,  1192,  1202,  1443,   922,   917,
    1445,   598,  1078,   222,   437,   438,  1084,    20,   917,  1082,
     921,   740,     5,   738,   333,   917,     5,   762,   764,   765,
     917,  1203,   917,   917,  1193,  1029,   917,   917,  1017,  1023,
     240,   279,   298,   337,   349,   359,   377,   387,   403,   443,
     467,   482,   489,   492,   513,   516,   518,   537,   555,   788,
     789,   790,   793,    24,  1075,  1081,    17,    18,    25,   410,
     657,   659,  1075,  1085,  1086,   438,   601,    13,   785,   742,
     502,  1179,   743,   740,   745,    31,    60,    61,    69,   240,
     279,   298,   314,   337,   349,   359,   377,   387,   403,   443,
     467,   482,   489,   492,   513,   516,   518,   537,   555,   598,
     748,   756,   767,   768,   917,   410,    92,   917,   734,   878,
    1062,   917,   795,   516,   747,   771,   773,   774,   772,   781,
     782,   410,   410,   794,   438,   410,   410,   740,   769,   405,
     657,    17,    18,    19,    20,    21,   658,    25,     5,   406,
    1085,    23,    24,    25,   601,   917,   925,    18,    24,    25,
     744,   925,   758,   747,   759,   771,   772,   410,   410,   757,
     438,   410,   410,   769,   740,   766,   410,    25,   917,   410,
    1030,   734,   734,   410,   917,   410,   437,   751,   607,   346,
     433,   450,   493,   533,   562,   571,   775,   607,   346,   433,
     450,   493,   533,   562,   571,   783,    25,    25,   796,   797,
     798,   799,   917,    25,   754,   755,    25,    25,   601,   371,
     657,  1086,   438,   406,    25,    25,   740,   751,   740,    25,
      25,   739,   754,    25,    25,   601,    39,   763,  1204,   371,
     410,  1194,  1463,  1464,  1465,  1466,  1467,   879,  1063,  1024,
     601,    25,   776,   777,   410,   778,   783,   784,   778,   410,
     779,     5,   371,     5,   371,     5,   263,     5,   788,   406,
       5,     5,   371,   371,   740,   770,  1085,   601,    25,   238,
       5,   371,     5,   371,   263,   406,     5,   371,   371,   770,
     917,  1091,  1092,  1094,  1041,  1091,   341,  1464,  1179,    33,
      35,    47,    49,    63,    70,    81,    82,    83,    97,    99,
     100,   101,   104,   107,   109,   111,   112,   118,   121,   123,
     124,   125,   133,   135,   136,   138,   140,   141,   144,   149,
     150,   151,   153,   154,   158,   159,   161,   165,   167,   168,
     173,   177,   180,   182,   184,   186,   188,   189,   191,   192,
     193,   197,   199,   200,   202,   210,   211,   223,   226,   227,
     230,   231,   234,   235,   243,   244,   245,   247,   257,   258,
     259,   261,   265,   266,   270,   278,   286,   287,   288,   294,
     295,   300,   303,   307,   308,   318,   336,   344,   350,   380,
     382,   383,   391,   430,   441,   445,   449,   473,   474,   478,
     490,   496,   497,   498,   499,   503,   507,   514,   515,   526,
     528,   539,   541,   544,   550,   576,   579,   585,   588,   589,
     603,   610,   633,   634,   635,   636,   637,   638,   639,   642,
     644,   646,   650,   651,   652,   653,   670,   692,   706,   707,
     713,   714,   733,   801,   802,   803,   804,   815,   816,   817,
     818,   869,   873,   903,   927,   928,   931,   932,   933,   934,
     947,   955,   978,   979,   981,   985,  1000,  1001,  1005,  1006,
    1007,  1008,  1016,  1031,  1044,  1055,  1056,  1057,  1068,  1071,
    1107,  1110,  1112,  1118,  1119,  1122,  1125,  1128,  1130,  1132,
    1134,  1141,  1146,  1150,  1151,  1163,  1164,  1167,  1173,  1174,
    1175,  1200,  1215,  1216,  1217,  1218,  1219,  1224,  1230,  1231,
    1249,  1252,  1292,  1293,  1382,  1383,  1413,  1414,  1421,  1432,
    1443,  1447,  1452,  1454,  1456,  1460,  1461,  1468,   707,  1019,
    1443,   606,   629,  1064,  1065,  1091,    20,   371,   405,   752,
     775,    25,   780,    25,    25,    25,   797,   799,   791,   755,
      25,   406,    20,   752,   410,    25,    25,   749,    25,   601,
     371,     5,  1091,   371,   917,   918,   921,   917,   912,   918,
     912,    24,   170,   917,  1104,  1438,  1439,  1440,   917,  1458,
     917,  1226,  1227,   917,    25,   654,  1075,  1222,   912,   917,
    1148,   844,    25,   925,  1187,  1188,  1187,    17,    18,    24,
      25,    40,    45,    51,    79,   172,   269,   274,   302,   337,
     349,   367,   372,   375,   386,   392,   402,   407,   410,   413,
     422,   423,   464,   468,   476,   487,   493,   518,   562,   569,
     571,   581,   582,   583,   590,   819,   826,   827,   828,   829,
     830,   831,   832,   833,   845,   850,   861,   862,   863,   864,
     917,   925,  1075,  1182,  1251,  1373,   918,  1422,  1422,   805,
    1148,   912,  1220,  1075,   914,   918,   826,  1422,  1075,  1148,
    1075,  1250,  1422,    24,   566,  1058,  1059,  1075,   912,   912,
    1058,   913,   918,   917,  1059,   912,  1422,   912,   914,  1075,
    1105,  1106,   910,   918,   914,   354,   542,   648,   909,   917,
     980,   917,   715,   915,   918,  1438,  1072,   844,   918,  1131,
     874,   108,   117,   126,   131,   175,   183,   239,   264,   271,
     273,   283,   309,   317,   354,   380,   418,   429,   529,   530,
     531,   542,   646,   992,  1126,  1127,  1075,   825,   826,  1140,
     821,   844,   909,  1453,  1453,   911,   918,   844,    24,  1075,
    1129,  1201,  1075,  1178,    24,  1075,  1416,   826,  1169,  1170,
    1171,  1180,  1181,   826,  1448,    84,   134,   172,   269,   345,
     386,   454,   518,   671,   850,   917,  1075,  1210,   694,   826,
     910,  1445,  1045,   826,   910,   826,  1075,  1002,   910,   826,
    1433,   826,  1187,   917,   929,   930,   914,   929,  1453,   914,
     929,  1453,   935,   929,    24,    25,   364,   467,   925,   983,
    1075,  1093,  1095,    46,   254,   324,   369,   549,   630,   631,
     632,   641,   661,   937,   939,   941,   943,   945,  1069,  1070,
    1074,   315,   326,   378,   393,   483,  1294,   621,   622,   881,
     882,   883,   917,  1066,   628,  1065,   371,   282,   371,   371,
     371,   371,   605,     5,   371,   282,   740,   760,   761,   371,
     371,   605,   371,   917,  1205,  1094,   371,  1195,    37,    38,
      64,    65,    66,   434,   522,   565,  1232,  1233,  1234,  1237,
    1240,  1243,  1244,  1245,  1246,   329,   919,  1462,   601,  1440,
     438,   598,  1123,   601,     8,   519,   568,     5,   371,   406,
      24,   917,  1366,   459,  1149,  1093,    88,    89,    90,   819,
     819,   410,   506,  1199,   410,   410,   410,   410,   410,   410,
     410,   410,   410,   819,   346,   433,   450,   493,   533,   562,
     571,  1376,  1377,   410,   410,   410,   819,   819,   410,   410,
     731,   819,   410,   834,   410,   410,   410,   410,   410,   410,
     410,   819,   410,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    72,
      73,    74,    75,    76,    77,    88,    89,    90,   229,   232,
     351,   366,   370,   408,   436,   455,   537,   604,   730,   820,
     835,   837,   838,   839,   840,   841,   842,   843,    25,   925,
     410,   501,   400,  1075,  1100,  1366,   660,   661,   808,   246,
      67,    68,   607,   439,     5,   600,   607,   599,   599,  1108,
     576,   400,     5,   537,   956,   439,   640,  1450,   410,   438,
     601,   640,   364,   717,  1075,   527,   599,  1113,  1114,  1115,
     306,  1291,   825,   824,   826,     8,   911,    25,   481,   535,
     904,  1075,   904,   904,   904,   997,   998,   904,   904,   577,
     993,   661,   993,   993,   905,   905,   993,   993,   661,     5,
     313,   365,     5,   660,   463,   822,   823,   826,     5,    56,
      62,   520,   608,   986,   643,  1451,   825,   594,   595,   596,
     597,  1177,  1179,   363,  1214,  1179,  1171,     5,   599,  1172,
     826,   410,   410,   410,   410,    24,   690,   917,   410,  1416,
     324,   410,   501,   570,   559,   695,   702,   693,    24,  1060,
    1075,  1165,     8,  1168,    13,   917,  1080,  1087,  1088,  1090,
    1098,  1099,  1142,   142,   324,   525,   558,    32,   170,   534,
    1434,  1435,  1436,  1437,   556,     5,   640,   640,   824,  1093,
    1100,   982,   400,     5,   130,   960,   410,  1075,   824,   410,
      25,    25,    46,  1073,    24,  1075,  1420,  1420,   911,  1131,
     911,    98,   201,   209,   215,   217,   228,   256,   272,   277,
     289,   296,   451,   458,   480,   485,  1253,  1264,  1265,  1273,
    1282,  1283,  1289,  1290,  1295,  1296,  1305,  1324,  1328,  1393,
    1394,  1423,  1424,  1427,  1428,   884,   885,    71,   880,   891,
     892,   883,  1067,  1463,  1025,   438,   788,   755,   438,     5,
     371,   762,   734,  1042,   734,   137,   276,   352,   410,   472,
    1311,  1323,   410,   917,  1248,    25,   225,   238,   410,   456,
     472,   917,  1229,  1242,  1309,  1310,  1315,  1317,  1319,   410,
     917,  1239,   410,  1229,  1235,     5,   410,   922,  1440,  1085,
    1438,   557,   598,  1124,    20,   917,  1104,  1441,   917,  1459,
    1227,   576,   601,   570,   410,   410,   808,   909,   819,   909,
     909,   909,  1453,   451,  1397,   819,    24,    25,    18,    23,
      24,    25,   865,   866,   867,   868,   819,   410,   607,   909,
      20,   819,   371,  1397,   819,    20,  1182,   853,   851,   857,
     819,   855,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   410,   819,   819,   410,   846,   917,  1075,
     607,   410,  1438,    24,   924,  1147,  1147,  1416,  1058,   826,
     826,   826,   906,   907,   410,  1075,  1106,   769,   957,   958,
     607,  1416,  1453,  1451,   917,   657,    20,   648,   917,   980,
    1075,   716,   606,   826,   330,  1117,   537,  1116,     5,    48,
      50,    52,   599,   607,   800,  1093,   875,    17,    18,    24,
     284,   290,   291,   292,   310,   418,   421,   445,   465,   500,
     520,   521,   531,   536,   575,   608,   999,   994,  1127,   905,
     826,   324,   576,     5,   909,    25,    25,   660,   132,  1176,
     198,  1181,  1187,  1449,   917,    24,   909,  1453,   570,   909,
     604,  1075,   675,   917,   917,   826,   319,   698,   702,   559,
     696,   704,    22,   214,  1047,  1051,   462,   844,   462,  1166,
     826,   437,  1084,   921,     5,  1003,   527,  1143,  1075,  1439,
    1442,  1075,  1096,  1097,   169,  1435,   948,   930,  1453,  1453,
     940,   941,   960,   960,   250,   253,   255,   275,   285,   327,
     331,   409,   461,   645,   959,   961,   962,   988,  1075,  1095,
     527,   662,    25,   379,   946,   301,  1415,  1415,   115,   116,
     416,   527,   917,  1325,  1326,  1367,   769,  1366,  1366,  1266,
     769,   917,  1425,  1425,   339,   456,   566,  1405,  1366,  1274,
     148,   418,   429,   451,   458,  1298,  1299,  1300,   267,   268,
    1388,  1463,  1463,   364,   893,  1075,   623,   624,   886,   887,
     888,   461,   606,   625,   626,   645,   896,   897,  1463,   734,
      25,   753,   753,   761,  1206,   734,  1196,  1313,  1366,  1247,
    1323,   410,  1247,   410,   410,  1241,  1242,   410,   410,    44,
     279,   337,   349,   359,   377,   387,   390,   403,   452,   482,
     492,   513,   516,   518,   546,   555,  1358,  1359,  1360,  1362,
    1238,  1239,  1235,  1236,   645,  1233,    24,   920,  1078,   601,
     406,  1416,   557,   527,  1457,   655,   656,   917,   917,   917,
    1223,   844,   371,   371,   371,   371,   371,  1405,   371,   371,
     371,   371,   570,   866,    18,    25,   570,   371,   371,    25,
    1377,   371,   371,   371,   371,     5,   732,   371,   819,   819,
     819,   371,   819,   371,   371,   371,   421,   421,   421,   844,
    1397,   421,   844,  1397,   687,   688,   689,   819,   410,   917,
    1221,   598,  1120,   607,     5,     5,     5,   560,   826,   601,
       5,   463,   607,   371,   406,   410,   606,   143,   147,   250,
     253,   718,   721,   722,   988,   719,   720,   917,   410,   918,
     630,   631,  1121,   826,   917,   917,   907,   908,   489,  1453,
     808,   534,  1279,    25,    25,   410,   995,   997,  1075,   516,
    1135,   822,    46,   819,  1179,    25,  1075,  1463,   371,     5,
     371,   371,   691,   917,   371,  1416,   687,   410,   410,   703,
     699,   340,   697,   826,   319,   700,   704,   577,   990,  1052,
    1048,   342,  1046,  1047,   824,   607,  1081,   601,  1099,    13,
      17,    18,    20,    24,    25,    45,   375,   390,   407,   410,
     423,   463,   464,   476,   518,   557,   569,   581,   582,   590,
     593,   917,   925,  1144,  1145,  1372,  1374,  1404,  1409,  1410,
    1442,   400,   400,     5,  1463,   942,   943,   531,   916,   527,
     909,   976,   909,   977,   969,   968,   966,   965,   989,   418,
     429,   972,   973,   418,   429,   974,   975,   304,   962,   967,
    1453,    78,   312,   325,   389,   396,   435,   460,   470,   471,
     486,   508,   511,   512,   517,   574,   586,   663,   664,     5,
      25,  1416,   228,  1075,   451,  1398,  1399,  1416,  1131,  1392,
    1394,    80,    80,   576,  1129,  1327,  1328,   410,  1306,   129,
     506,  1332,  1339,  1366,   155,   251,  1429,   601,   607,  1406,
    1407,  1409,  1254,   321,   330,   354,   357,   375,   481,   535,
     542,   911,  1276,  1281,   410,  1301,   606,     5,    24,   917,
    1389,  1390,   895,  1075,     5,   527,   889,   890,   620,   888,
     894,   917,   894,   898,   899,   894,   304,   897,  1026,   406,
     406,   440,  1189,  1209,  1043,   440,  1152,  1183,   410,     5,
     371,   274,   410,   422,   583,  1342,  1343,  1344,  1345,  1346,
    1350,  1354,  1356,  1409,   371,   593,   917,  1312,  1314,  1366,
    1369,  1370,  1316,  1369,     5,   371,  1316,  1342,   346,   433,
     450,   493,   533,   562,   571,  1379,  1379,   410,   410,   410,
     410,   410,   410,   187,   379,  1318,  1320,     5,   371,     5,
     371,   917,   371,  1441,     8,  1416,   826,     5,  1228,  1229,
     844,  1032,  1406,   859,  1377,   859,    25,    25,   570,    23,
      25,   772,   860,  1199,   371,  1199,   773,   371,  1199,   854,
     852,   858,  1199,   856,  1199,  1199,  1199,    24,    24,    24,
     819,   836,   371,    24,   836,   371,   847,     5,   848,   601,
    1228,   557,  1416,  1416,   826,   826,   906,   489,   826,  1455,
       5,    20,  1369,   958,  1416,   601,   917,   719,   727,   726,
     728,   917,   923,   729,   923,   171,   722,   725,     5,   960,
     601,   826,     8,   917,  1280,   876,   996,   997,  1075,     5,
     305,  1211,   324,   324,   438,   601,   324,   410,   676,   680,
     673,  1463,  1463,   705,   701,   697,   991,    24,   916,  1053,
    1075,  1463,   826,   405,    20,   917,  1089,   844,    25,   925,
      25,   925,  1375,  1379,   451,  1409,   410,   410,   410,   410,
     410,   410,   410,   917,   410,     5,    17,    18,    19,    20,
      72,    73,    74,    75,    76,    77,  1430,  1439,  1075,  1097,
      43,   523,   949,   944,   945,    25,   660,   917,     5,   963,
       5,   964,  1463,  1463,  1463,  1463,   995,     5,   971,     5,
     970,  1463,   916,     5,   371,    25,  1366,   921,  1386,   576,
     576,  1265,  1391,  1392,  1328,  1307,  1369,   598,   911,  1342,
     410,  1269,   917,  1426,  1425,     5,  1395,   260,   300,   301,
     302,   325,   333,   338,   353,   358,   360,   367,   370,   373,
     376,   379,   384,   402,   418,   421,   422,   428,   439,   455,
     462,   469,   472,   473,   474,   476,   477,   493,   517,   518,
     519,   520,   522,   539,   540,   562,   571,   572,   574,   636,
     926,  1462,   564,   826,   826,  1275,   911,  1302,  1369,  1366,
    1300,   601,   601,     5,     5,  1075,   894,  1463,  1463,     5,
     901,   902,  1463,  1463,   900,  1019,   792,   750,    53,    54,
      57,    58,    59,   157,   164,   198,   207,   236,   237,   281,
     323,   379,   609,   610,   611,   612,   613,   614,   615,   616,
     617,   618,  1186,  1190,   114,   494,  1191,  1207,  1019,   139,
     156,   157,   164,   198,   207,   236,   281,   323,  1184,  1185,
    1197,  1191,  1314,  1323,   410,  1404,  1342,  1409,  1404,  1345,
       6,   371,     7,     9,    11,    12,    13,    14,    15,    16,
     232,   351,   408,   537,   583,   604,  1353,  1355,  1370,   438,
    1368,   371,     5,   921,     5,   371,  1242,   371,   371,   607,
     410,   607,    25,  1364,  1364,    25,  1364,  1364,    25,  1363,
      24,  1372,  1321,  1322,  1323,  1239,  1235,  1416,     8,   656,
       5,   371,   824,   371,   527,  1333,  1338,   607,   371,    25,
     570,   607,   371,   371,   371,   371,     5,   371,   371,   371,
     689,   687,    20,   371,  1416,     5,   826,   547,   254,   665,
     666,   826,    20,   917,   371,   960,  1463,  1463,     5,   723,
     438,   601,     5,   724,  1463,   720,   527,    20,   917,     5,
     917,  1111,   369,   640,  1096,  1463,     5,   371,   916,   819,
     687,  1075,   672,   654,   917,  1075,   678,   371,   687,   687,
    1463,  1463,   995,  1050,    24,  1054,  1075,   552,   872,   438,
     463,   825,  1004,   607,   921,   371,   375,  1369,  1431,   339,
     456,   566,  1357,  1409,  1411,  1357,  1357,  1357,  1357,   601,
    1411,  1145,  1409,  1409,  1409,  1409,   951,   950,   420,   936,
     937,   601,   909,  1463,   909,  1463,   973,  1463,   975,  1463,
     660,   664,   371,   410,  1417,  1405,  1388,  1392,  1392,  1384,
       5,   371,   451,  1403,  1270,  1369,   459,  1267,  1403,   607,
    1407,   534,  1402,    20,   410,  1257,  1258,  1259,  1260,  1369,
     534,  1277,     5,   371,   607,   917,   917,  1390,  1075,   917,
    1463,  1463,  1463,  1463,   605,   605,  1187,  1187,  1187,    24,
    1187,  1187,  1187,  1187,  1187,  1187,    24,    24,  1187,  1190,
    1075,  1101,  1102,   600,   426,  1153,  1463,    24,    24,    25,
      25,    25,    25,    25,    24,  1075,  1185,  1153,   371,   371,
    1343,  1344,   917,  1348,  1372,  1412,   410,  1404,  1348,   410,
    1404,     9,   229,   366,   368,  1409,    25,  1311,  1369,   601,
    1369,   346,   433,   450,   493,   533,   562,   571,  1380,    25,
    1380,     5,  1361,  1361,     5,   371,   371,  1361,   371,  1323,
    1416,  1229,   248,  1225,   495,  1334,  1335,  1336,  1366,  1339,
     311,   494,   505,  1284,  1400,   346,   433,   450,   493,   533,
     562,   571,  1378,   859,   570,    23,    25,   776,   819,   849,
     448,   807,     5,   353,  1416,     5,   410,   371,   531,   987,
     923,  1463,   657,    20,   917,   923,  1463,  1453,   826,  1453,
     220,   997,   660,  1212,  1093,   406,   687,   677,   681,   371,
    1463,   916,   826,   870,  1085,  1380,  1405,     5,  1379,     5,
     371,  1409,     5,   371,  1409,  1409,  1409,  1409,   917,   371,
     826,  1463,   938,   939,    20,   917,  1418,  1419,  1406,  1387,
    1385,  1388,  1369,   921,   119,  1308,     5,   371,  1268,  1426,
    1096,  1396,    13,  1259,  1261,  1255,     5,    13,  1278,  1369,
     442,  1303,  1304,  1367,   601,   190,  1027,   788,   762,   519,
     568,  1103,     5,  1101,    42,   113,   179,   181,   196,   204,
     208,   233,  1154,  1155,  1208,  1027,  1198,   421,  1347,  1351,
    1352,  1372,  1442,  1347,  1351,  1348,  1409,     5,   406,    20,
     917,   371,    25,  1365,   371,   371,    25,   371,   410,  1336,
       5,   917,  1371,   348,  1330,  1340,   917,  1401,   600,  1357,
     311,   410,    23,    25,   371,   909,   660,   353,  1416,   826,
     667,   549,  1109,    25,   660,   406,   987,   371,  1133,   371,
     410,   679,   324,   685,   371,   674,  1049,  1463,   406,  1406,
    1379,   607,  1379,   371,  1409,   371,   371,   371,   371,   556,
     916,     5,   371,  1402,  1388,  1388,  1405,  1369,   410,  1338,
     410,   463,  1262,  1263,  1409,     5,   371,   129,   506,  1256,
    1260,  1263,  1096,     5,   120,  1297,   917,  1102,  1156,  1157,
    1075,  1159,  1075,  1158,  1160,  1155,   219,   219,  1349,  1412,
       5,   371,   371,  1347,     7,    25,  1368,   607,   371,  1335,
    1337,  1335,  1331,  1408,  1409,   427,  1329,  1341,  1225,    25,
    1285,  1286,  1287,  1369,  1398,  1401,    25,   806,  1416,   372,
     183,   239,   264,   273,   309,   317,   411,   584,   664,   668,
     669,   410,   601,   660,   988,  1136,  1137,  1138,  1213,   682,
     371,  1093,   685,   685,  1463,   871,  1338,   607,  1380,   607,
     952,   984,  1419,  1338,  1406,   463,  1271,  1272,  1409,  1400,
    1262,  1409,     5,  1259,    13,   911,  1342,  1304,  1463,  1463,
    1161,  1463,  1162,  1463,  1463,  1352,  1409,   406,  1380,     5,
     371,     5,  1342,     5,   519,   568,  1288,  1225,   371,   327,
     331,   809,   810,   811,   988,   904,   904,   904,   904,   904,
     904,    24,     5,   371,   826,    20,   917,  1139,   262,  1138,
     685,   687,   685,   221,   371,  1380,  1380,  1463,   660,  1400,
    1338,     5,   371,   371,  1263,   410,  1463,  1463,  1335,  1408,
    1286,   813,   812,   218,   811,   814,   669,     5,  1463,   683,
     949,  1272,  1262,  1463,  1463,  1463,   826,   371,   371,   371,
     684,   142,   324,   686,  1093
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
#line 885 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 888 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 892 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 898 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 903 "fgl.yacc"
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
#line 915 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 920 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",%s%s);\n",yyvsp[0].str,get_namespace(yyvsp[0].str),yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 938 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 939 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 940 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 941 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 942 "fgl.yacc"
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
#line 956 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 957 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 958 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 959 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 960 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 965 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 966 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 977 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 980 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 983 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 983 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 990 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 991 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 997 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1007 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1008 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1009 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1010 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1011 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1012 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1019 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1023 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1027 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1028 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1032 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1038 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1040 "fgl.yacc"
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
#line 1051 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1053 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1055 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1057 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1061 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1063 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1124 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1128 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1132 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1135 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1139 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-1].str);
	}
    break;

  case 66:
#line 1143 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1147 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1150 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1156 "fgl.yacc"
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
#line 1165 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1169 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1174 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1178 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1186 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1190 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1194 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1196 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1202 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1207 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1210 "fgl.yacc"
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
#line 1226 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1233 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1237 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1241 "fgl.yacc"
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
#line 1263 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1263 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1267 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1268 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1269 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1274 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1277 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1283 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1286 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1298 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1304 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1307 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1322 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1332 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1338 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1347 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1360 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1363 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1365 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1371 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1373 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1378 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1383 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1389 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1393 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1408 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1411 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1414 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1417 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1420 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1423 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1445 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1454 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1464 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1478 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1482 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1485 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1493 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1499 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io)"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1514 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1518 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1523 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1533 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1536 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1540 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1542 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1545 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1547 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1550 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1552 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1555 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1558 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1568 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1569 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1577 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1578 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1595 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1598 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1601 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1604 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1607 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1610 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1619 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1627 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1632 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1645 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1649 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1664 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1665 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1673 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1673 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1683 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1683 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1692 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1693 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1694 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1697 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1702 "fgl.yacc"
    { }
    break;

  case 193:
#line 1702 "fgl.yacc"
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
#line 1719 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1723 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1737 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1746 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1750 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1766 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1768 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1769 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1776 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1776 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1777 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1778 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1781 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1783 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1793 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1808 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1808 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1814 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1815 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1822 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1823 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1824 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1825 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1828 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1829 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1830 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1831 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1835 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1840 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1845 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1849 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1852 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1856 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1857 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1858 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1859 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1860 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1861 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1862 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1863 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1866 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1867 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1868 "fgl.yacc"
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
#line 1900 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1904 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1906 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1908 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1910 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1915 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 265:
#line 1919 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1919 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1923 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1924 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1925 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1926 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1927 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1928 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1930 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1935 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1935 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1938 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1940 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1946 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1948 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1954 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1962 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1962 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1965 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1966 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1967 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1968 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 1969 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 1970 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 1972 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 1993 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 2002 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2004 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2006 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2008 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2009 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2010 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2011 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2012 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2017 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2024 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2029 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2031 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2033 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2034 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2035 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2036 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2037 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2038 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2039 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2042 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2044 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2050 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2058 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2066 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2070 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2078 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2079 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2080 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 326:
#line 2081 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2100 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2112 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2116 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2119 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2122 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 337:
#line 2123 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2124 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2125 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2126 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2132 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2139 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2144 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2149 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2153 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2156 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2164 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2166 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2171 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2183 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2186 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2189 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2192 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2195 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2198 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2211 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2214 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2229 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 363:
#line 2231 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 364:
#line 2233 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 365:
#line 2235 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 366:
#line 2237 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 367:
#line 2239 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 368:
#line 2240 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 369:
#line 2247 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 370:
#line 2249 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 371:
#line 2253 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 372:
#line 2255 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 373:
#line 2257 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 374:
#line 2259 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 375:
#line 2261 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 376:
#line 2263 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 377:
#line 2265 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 378:
#line 2271 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 379:
#line 2285 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2288 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2305 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2311 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2315 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 390:
#line 2320 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2330 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 401:
#line 2341 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2341 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2346 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 405:
#line 2350 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2356 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2364 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2370 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2379 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2381 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2388 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2396 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2400 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2409 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 415:
#line 2414 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2419 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 417:
#line 2423 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2425 "fgl.yacc"
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
#line 2435 "fgl.yacc"
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
#line 2449 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2457 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2469 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2475 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2481 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2491 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2497 "fgl.yacc"
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
#line 2569 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2575 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2579 "fgl.yacc"
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
#line 2587 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2587 "fgl.yacc"
    {
	char buff[256];
      if (!in_command("REPORT")) {
        a4gl_yyerror("This can only be done in a report!");YYERROR;
      } insql=0; 
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
		sprintf(yyval.str,"{int _retvars;\n_retvars=%s%s(%s); {\nif (_retvars!= 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n}\n", get_namespace(yyvsp[-5].str),yyvsp[-5].str,yyvsp[-1].str, lastlineno,infilename);
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
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 529:
#line 3017 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 530:
#line 3018 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 531:
#line 3025 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 533:
#line 3042 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 534:
#line 3046 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 535:
#line 3051 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 536:
#line 3055 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 537:
#line 3071 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 538:
#line 3077 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 539:
#line 3085 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 546:
#line 3102 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 547:
#line 3104 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 548:
#line 3107 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 549:
#line 3109 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3123 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 555:
#line 3125 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 556:
#line 3128 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 557:
#line 3130 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 570:
#line 3161 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 571:
#line 3163 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 572:
#line 3166 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 573:
#line 3168 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 574:
#line 3171 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 575:
#line 3173 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3176 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 577:
#line 3178 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3181 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 579:
#line 3183 "fgl.yacc"
    { 
			print_gtk_field_2();
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
#line 3529 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 709:
#line 3532 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 710:
#line 3538 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 711:
#line 3549 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 712:
#line 3550 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 713:
#line 3553 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 715:
#line 3559 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 716:
#line 3563 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 717:
#line 3564 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 720:
#line 3578 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 721:
#line 3580 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 724:
#line 3589 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 725:
#line 3591 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 726:
#line 3595 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 727:
#line 3597 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 728:
#line 3600 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 729:
#line 3602 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 730:
#line 3605 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 731:
#line 3608 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 732:
#line 3611 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 733:
#line 3613 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 734:
#line 3616 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 735:
#line 3618 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 3621 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 737:
#line 3623 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 738:
#line 3626 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 739:
#line 3628 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 740:
#line 3631 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 741:
#line 3633 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 742:
#line 3639 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 743:
#line 3640 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 744:
#line 3648 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 745:
#line 3649 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 746:
#line 3654 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 747:
#line 3655 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 748:
#line 3664 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 749:
#line 3665 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 750:
#line 3672 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 751:
#line 3673 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 752:
#line 3681 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 753:
#line 3682 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 754:
#line 3691 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 755:
#line 3696 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 756:
#line 3701 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 757:
#line 3702 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 759:
#line 3707 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 760:
#line 3710 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 761:
#line 3718 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 762:
#line 3723 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 763:
#line 3727 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 764:
#line 3729 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 765:
#line 3738 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 766:
#line 3743 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 767:
#line 3744 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 768:
#line 3745 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 769:
#line 3746 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 770:
#line 3749 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 772:
#line 3755 "fgl.yacc"
    {iskey=1;}
    break;

  case 773:
#line 3755 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 774:
#line 3757 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 775:
#line 3760 "fgl.yacc"
    {iskey=1;}
    break;

  case 776:
#line 3760 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 777:
#line 3762 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 778:
#line 3766 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 779:
#line 3766 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 780:
#line 3769 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 781:
#line 3770 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 783:
#line 3773 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 784:
#line 3778 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 785:
#line 3778 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 790:
#line 3785 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 791:
#line 3786 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 792:
#line 3787 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 793:
#line 3788 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 794:
#line 3789 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 795:
#line 3790 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 796:
#line 3791 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 797:
#line 3792 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 798:
#line 3793 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 799:
#line 3794 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 800:
#line 3795 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 801:
#line 3796 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 802:
#line 3797 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 803:
#line 3801 "fgl.yacc"
    {
char buff[256];
debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 804:
#line 3819 "fgl.yacc"
    {chk4var=1;}
    break;

  case 805:
#line 3819 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 806:
#line 3822 "fgl.yacc"
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

  case 807:
#line 3845 "fgl.yacc"
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
#line 3863 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 810:
#line 3869 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 811:
#line 3875 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 812:
#line 3881 "fgl.yacc"
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
#line 3892 "fgl.yacc"
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
#line 3915 "fgl.yacc"
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

  case 817:
#line 3931 "fgl.yacc"
    {
	}
    break;

  case 824:
#line 3954 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 828:
#line 3962 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 846:
#line 3988 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 847:
#line 3989 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 848:
#line 3997 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 849:
#line 4002 "fgl.yacc"
    { 
if (is_builtin_func(yyvsp[-1].str)) {
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
#line 4018 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 851:
#line 4024 "fgl.yacc"
    {
  int c;
  lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 853:
#line 4039 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;

  case 854:
#line 4052 "fgl.yacc"
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
#line 4062 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 856:
#line 4069 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 857:
#line 4076 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 858:
#line 4082 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 859:
#line 4082 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 860:
#line 4087 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 861:
#line 4092 "fgl.yacc"
    {
}
    break;

  case 867:
#line 4104 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 869:
#line 4112 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 870:
#line 4118 "fgl.yacc"
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

  case 871:
#line 4132 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 872:
#line 4136 "fgl.yacc"
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

  case 873:
#line 4149 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 875:
#line 4167 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 876:
#line 4174 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 877:
#line 4180 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 878:
#line 4191 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 879:
#line 4195 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 880:
#line 4202 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 881:
#line 4209 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 882:
#line 4215 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 883:
#line 4220 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 886:
#line 4227 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 887:
#line 4228 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 888:
#line 4230 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 889:
#line 4231 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 890:
#line 4234 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 891:
#line 4235 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 892:
#line 4236 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 893:
#line 4238 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 894:
#line 4243 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 895:
#line 4248 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 896:
#line 4255 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 900:
#line 4262 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 901:
#line 4264 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 902:
#line 4266 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 903:
#line 4275 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 904:
#line 4281 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 905:
#line 4285 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 908:
#line 4297 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 909:
#line 4302 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 910:
#line 4307 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 911:
#line 4310 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 912:
#line 4319 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 913:
#line 4322 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 914:
#line 4326 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 915:
#line 4330 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 922:
#line 4347 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 924:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 925:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 926:
#line 4352 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 927:
#line 4362 "fgl.yacc"
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

  case 929:
#line 4409 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 931:
#line 4416 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 932:
#line 4421 "fgl.yacc"
    {

         int type,arrsize,size,level;
         char buff[256];
         char buff2[256];
         char arrbuff[256];

         lex_printcomment("/* OPEN_SQUARE.. */\n");

	if (strcmp(yyvsp[-4].str,"sqlca")==0) {
		strcpy(yyvsp[-4].str,"a4gl_sqlca");
	}
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

  case 936:
#line 4468 "fgl.yacc"
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

  case 937:
#line 4482 "fgl.yacc"
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

  case 942:
#line 4506 "fgl.yacc"
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

  case 943:
#line 4560 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 944:
#line 4565 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 945:
#line 4573 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 946:
#line 4578 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 947:
#line 4586 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 948:
#line 4592 "fgl.yacc"
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

  case 949:
#line 4620 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 950:
#line 4623 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-3].str, yyvsp[0].str); }
    break;

  case 951:
#line 4625 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  lex_printcomment("/*array variable .let. */");
  if (strcmp(yyvsp[-6].str,"status")==0) { strcpy(yyvsp[-6].str,"a4gl_status"); }
  if (strcmp(yyvsp[-6].str,"sqlca")==0) {
        strcpy(yyvsp[-6].str,"a4gl_sqlca");
  }
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

  case 956:
#line 4676 "fgl.yacc"
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

  case 957:
#line 4728 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 959:
#line 4735 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 960:
#line 4741 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 961:
#line 4752 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 962:
#line 4759 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 964:
#line 4767 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 965:
#line 4770 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 966:
#line 4771 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 968:
#line 4773 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 969:
#line 4774 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 970:
#line 4777 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 971:
#line 4780 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 972:
#line 4786 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 973:
#line 4789 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 974:
#line 4793 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 975:
#line 4797 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 976:
#line 4804 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 977:
#line 4809 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 978:
#line 4816 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 979:
#line 4819 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 984:
#line 4832 "fgl.yacc"
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

  case 985:
#line 4845 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 986:
#line 4852 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 987:
#line 4859 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 988:
#line 4862 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 989:
#line 4876 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 994:
#line 4893 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 995:
#line 4898 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 996:
#line 4904 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 998:
#line 4911 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 999:
#line 4916 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 1000:
#line 4919 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 1001:
#line 4920 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1002:
#line 4923 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1003:
#line 4924 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1004:
#line 4927 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1005:
#line 4928 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1006:
#line 4933 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1007:
#line 4940 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1008:
#line 4943 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1009:
#line 4949 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1010:
#line 4951 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1011:
#line 4953 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1012:
#line 4955 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1013:
#line 4958 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1014:
#line 4958 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1015:
#line 4959 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1016:
#line 4964 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1017:
#line 4972 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1018:
#line 4973 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1019:
#line 4978 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1020:
#line 4980 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1021:
#line 4982 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1025:
#line 4999 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1026:
#line 5002 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1027:
#line 5005 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1028:
#line 5008 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1029:
#line 5011 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1030:
#line 5014 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1031:
#line 5017 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1032:
#line 5021 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1033:
#line 5025 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1034:
#line 5029 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1035:
#line 5032 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1036:
#line 5036 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1037:
#line 5039 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1038:
#line 5040 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1039:
#line 5041 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1040:
#line 5044 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1041:
#line 5047 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1042:
#line 5050 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1043:
#line 5053 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1044:
#line 5056 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1045:
#line 5059 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1046:
#line 5062 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1047:
#line 5079 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1050:
#line 5089 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1051:
#line 5096 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1053:
#line 5117 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1054:
#line 5122 "fgl.yacc"
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

  case 1055:
#line 5135 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1056:
#line 5140 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1057:
#line 5141 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1058:
#line 5145 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1062:
#line 5151 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1063:
#line 5153 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1065:
#line 5168 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1066:
#line 5172 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1067:
#line 5178 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1068:
#line 5179 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1069:
#line 5182 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1070:
#line 5183 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1071:
#line 5186 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1073:
#line 5205 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1074:
#line 5210 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1075:
#line 5215 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1076:
#line 5220 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1082:
#line 5242 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1083:
#line 5249 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1084:
#line 5255 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1085:
#line 5257 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1089:
#line 5268 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1090:
#line 5269 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1091:
#line 5271 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1092:
#line 5272 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5274 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1094:
#line 5275 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1095:
#line 5277 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1096:
#line 5278 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1097:
#line 5280 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1098:
#line 5281 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1099:
#line 5282 "fgl.yacc"
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

  case 1100:
#line 5296 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1101:
#line 5298 "fgl.yacc"
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

  case 1102:
#line 5315 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1109:
#line 5327 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1110:
#line 5327 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1111:
#line 5333 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1112:
#line 5333 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1113:
#line 5336 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1114:
#line 5336 "fgl.yacc"
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

  case 1115:
#line 5346 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1116:
#line 5347 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1117:
#line 5348 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1118:
#line 5355 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1119:
#line 5367 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1125:
#line 5378 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1126:
#line 5383 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1127:
#line 5387 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1128:
#line 5392 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1129:
#line 5398 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1130:
#line 5399 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1131:
#line 5400 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1132:
#line 5404 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1133:
#line 5405 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1134:
#line 5406 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1135:
#line 5407 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1136:
#line 5411 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1137:
#line 5421 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1138:
#line 5423 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1139:
#line 5428 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1140:
#line 5431 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1141:
#line 5436 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1142:
#line 5443 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 5450 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1144:
#line 5457 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1145:
#line 5466 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1146:
#line 5473 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1147:
#line 5480 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1148:
#line 5487 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1149:
#line 5494 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1154:
#line 5507 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1155:
#line 5508 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1156:
#line 5509 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1157:
#line 5510 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1158:
#line 5511 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1159:
#line 5512 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1160:
#line 5513 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1161:
#line 5514 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1162:
#line 5515 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1163:
#line 5516 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1166:
#line 5522 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1167:
#line 5523 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1168:
#line 5524 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1169:
#line 5525 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1174:
#line 5534 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1175:
#line 5535 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1176:
#line 5536 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1177:
#line 5537 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1178:
#line 5538 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1179:
#line 5539 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1180:
#line 5540 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1181:
#line 5541 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1182:
#line 5543 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1183:
#line 5544 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1184:
#line 5545 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1185:
#line 5546 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1186:
#line 5548 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1187:
#line 5549 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1188:
#line 5550 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1189:
#line 5551 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1193:
#line 5556 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1194:
#line 5557 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1198:
#line 5564 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1199:
#line 5571 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1200:
#line 5578 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1201:
#line 5589 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1202:
#line 5598 "fgl.yacc"
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

  case 1203:
#line 5609 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1204:
#line 5613 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1205:
#line 5617 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1206:
#line 5623 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1207:
#line 5628 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1208:
#line 5636 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1209:
#line 5639 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1210:
#line 5648 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1211:
#line 5659 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1213:
#line 5666 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1214:
#line 5674 "fgl.yacc"
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

  case 1215:
#line 5684 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1216:
#line 5687 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1217:
#line 5691 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1218:
#line 5699 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1219:
#line 5702 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1220:
#line 5708 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1221:
#line 5712 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1222:
#line 5716 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1223:
#line 5720 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1224:
#line 5724 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1225:
#line 5730 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1226:
#line 5731 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1227:
#line 5732 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1228:
#line 5733 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1229:
#line 5738 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1230:
#line 5740 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1231:
#line 5743 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1232:
#line 5747 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1233:
#line 5750 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1234:
#line 5757 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1235:
#line 5762 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1236:
#line 5763 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1237:
#line 5764 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1238:
#line 5769 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1239:
#line 5770 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1240:
#line 5776 "fgl.yacc"
    {insql=1;}
    break;

  case 1241:
#line 5776 "fgl.yacc"
    {insql=0;}
    break;

  case 1242:
#line 5776 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1243:
#line 5781 "fgl.yacc"
    {insql=1;}
    break;

  case 1244:
#line 5781 "fgl.yacc"
    {insql=0;}
    break;

  case 1245:
#line 5781 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1246:
#line 5792 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1247:
#line 5793 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1248:
#line 5799 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1249:
#line 5801 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1251:
#line 5808 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1252:
#line 5812 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1253:
#line 5813 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1255:
#line 5818 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 5821 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1257:
#line 5827 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1258:
#line 5830 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1259:
#line 5838 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1261:
#line 5845 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1262:
#line 5852 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 5855 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1264:
#line 5864 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1265:
#line 5867 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1266:
#line 5870 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1267:
#line 5873 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1268:
#line 5876 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1269:
#line 5879 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1270:
#line 5882 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1271:
#line 5889 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1272:
#line 5892 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1273:
#line 5899 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 5902 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1275:
#line 5908 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1276:
#line 5911 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1277:
#line 5918 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1278:
#line 5921 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1280:
#line 5929 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1282:
#line 5938 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1283:
#line 5941 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1284:
#line 5947 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1285:
#line 5950 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1286:
#line 5956 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1287:
#line 5963 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1288:
#line 5964 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1289:
#line 5968 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1290:
#line 5974 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1291:
#line 5977 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1293:
#line 5985 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1294:
#line 5992 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1295:
#line 5995 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1299:
#line 6013 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1305:
#line 6019 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1306:
#line 6022 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1307:
#line 6025 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1308:
#line 6031 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1310:
#line 6037 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1312:
#line 6048 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1313:
#line 6062 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1314:
#line 6064 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1315:
#line 6066 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1316:
#line 6071 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1317:
#line 6075 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1318:
#line 6081 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1319:
#line 6089 "fgl.yacc"
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

  case 1320:
#line 6099 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
    }
    break;

  case 1321:
#line 6102 "fgl.yacc"
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

  case 1322:
#line 6112 "fgl.yacc"
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

  case 1323:
#line 6134 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1324:
#line 6137 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1326:
#line 6146 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1327:
#line 6151 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1328:
#line 6152 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1329:
#line 6158 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1330:
#line 6161 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1331:
#line 6170 "fgl.yacc"
    {
		push_gen(UPDVAL,"NULL");
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1332:
#line 6174 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1333:
#line 6181 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1334:
#line 6190 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1335:
#line 6190 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1336:
#line 6195 "fgl.yacc"
    {insql=1;}
    break;

  case 1337:
#line 6195 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1338:
#line 6200 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1339:
#line 6203 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1340:
#line 6205 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1342:
#line 6212 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1343:
#line 6216 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1344:
#line 6220 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1345:
#line 6227 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1346:
#line 6230 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1347:
#line 6237 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1348:
#line 6241 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1349:
#line 6245 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1350:
#line 6254 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1351:
#line 6258 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1352:
#line 6264 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1353:
#line 6268 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1354:
#line 6274 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1355:
#line 6281 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1356:
#line 6285 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1357:
#line 6290 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1358:
#line 6300 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1359:
#line 6303 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1360:
#line 6305 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1361:
#line 6307 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1362:
#line 6309 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1363:
#line 6311 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1364:
#line 6313 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1365:
#line 6315 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1366:
#line 6321 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1367:
#line 6331 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1368:
#line 6338 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1370:
#line 6344 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1374:
#line 6353 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1377:
#line 6358 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1378:
#line 6363 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1379:
#line 6370 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1380:
#line 6371 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1381:
#line 6378 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1382:
#line 6390 "fgl.yacc"
    {insql=1;}
    break;

  case 1383:
#line 6390 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1384:
#line 6395 "fgl.yacc"
    {
			lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1385:
#line 6400 "fgl.yacc"
    {
		lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1387:
#line 6406 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1389:
#line 6410 "fgl.yacc"
    {
		lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1390:
#line 6415 "fgl.yacc"
    {
		lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1391:
#line 6420 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
		lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1392:
#line 6424 "fgl.yacc"
    {
		lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1394:
#line 6430 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1395:
#line 6434 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1396:
#line 6442 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1397:
#line 6445 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1398:
#line 6447 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1399:
#line 6452 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1402:
#line 6459 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1406:
#line 6466 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1407:
#line 6469 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1408:
#line 6471 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6477 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1412:
#line 6483 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1415:
#line 6493 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1416:
#line 6498 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1417:
#line 6500 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1419:
#line 6506 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1420:
#line 6509 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1422:
#line 6515 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1423:
#line 6523 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1424:
#line 6528 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6538 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6544 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1430:
#line 6550 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6552 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1433:
#line 6558 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1434:
#line 6563 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1435:
#line 6566 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1436:
#line 6569 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1437:
#line 6577 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1438:
#line 6579 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1439:
#line 6590 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1440:
#line 6595 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1442:
#line 6599 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1443:
#line 6601 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1444:
#line 6608 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1445:
#line 6611 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1446:
#line 6617 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1447:
#line 6621 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1448:
#line 6625 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1449:
#line 6628 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1450:
#line 6636 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1451:
#line 6643 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1454:
#line 6652 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1455:
#line 6658 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1456:
#line 6661 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1457:
#line 6672 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1458:
#line 6679 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 6685 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1460:
#line 6688 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1461:
#line 6695 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1462:
#line 6702 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1464:
#line 6709 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1465:
#line 6715 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1466:
#line 6716 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1467:
#line 6717 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1469:
#line 6721 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1471:
#line 6726 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1472:
#line 6733 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1473:
#line 6738 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1474:
#line 6739 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1475:
#line 6742 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1476:
#line 6745 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1477:
#line 6750 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1478:
#line 6751 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1479:
#line 6756 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1480:
#line 6759 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 6765 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1482:
#line 6768 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1483:
#line 6774 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1484:
#line 6777 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1485:
#line 6783 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1486:
#line 6786 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1487:
#line 6793 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1488:
#line 6794 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1489:
#line 6823 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1490:
#line 6825 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1494:
#line 6839 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1495:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1496:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1497:
#line 6848 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1499:
#line 6856 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1500:
#line 6859 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1502:
#line 6865 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1504:
#line 6871 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1505:
#line 6874 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1506:
#line 6877 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1507:
#line 6880 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1508:
#line 6883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1509:
#line 6886 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1510:
#line 6889 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1512:
#line 6896 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1517:
#line 6903 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1518:
#line 6904 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1519:
#line 6909 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1520:
#line 6912 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1521:
#line 6916 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1522:
#line 6922 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1523:
#line 6923 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1524:
#line 6924 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1525:
#line 6925 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1530:
#line 6945 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1531:
#line 6950 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1532:
#line 6951 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1534:
#line 6954 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1538:
#line 6959 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1540:
#line 6962 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1542:
#line 6965 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1546:
#line 6970 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1547:
#line 6972 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1548:
#line 6975 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1549:
#line 6976 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1550:
#line 6983 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1554:
#line 6988 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1558:
#line 7004 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1559:
#line 7005 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1560:
#line 7009 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1561:
#line 7010 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1563:
#line 7028 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1564:
#line 7029 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1565:
#line 7030 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1566:
#line 7034 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1567:
#line 7037 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1568:
#line 7043 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1569:
#line 7048 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1570:
#line 7053 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-3].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1572:
#line 7064 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1576:
#line 7072 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1577:
#line 7074 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1578:
#line 7076 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 7078 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1581:
#line 7083 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1582:
#line 7086 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7089 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1584:
#line 7091 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1585:
#line 7094 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1586:
#line 7096 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1587:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1588:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1589:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1590:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1591:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1592:
#line 7099 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1593:
#line 7100 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1594:
#line 7103 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1595:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1596:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1597:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1598:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1599:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1600:
#line 7108 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1601:
#line 7110 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1602:
#line 7113 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1617:
#line 7122 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1618:
#line 7123 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1619:
#line 7127 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1620:
#line 7135 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1621:
#line 7135 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1622:
#line 7140 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1623:
#line 7140 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1624:
#line 7146 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1625:
#line 7146 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1626:
#line 7151 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1627:
#line 7151 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1628:
#line 7158 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1629:
#line 7159 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1630:
#line 7160 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1634:
#line 7167 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1635:
#line 7168 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1636:
#line 7173 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1637:
#line 7176 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1638:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1639:
#line 7185 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1640:
#line 7194 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1641:
#line 7206 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1642:
#line 7207 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1643:
#line 7209 "fgl.yacc"
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

  case 1644:
#line 7223 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1645:
#line 7233 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1646:
#line 7236 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1647:
#line 7244 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-6].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1648:
#line 7253 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1649:
#line 7256 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1650:
#line 7260 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1651:
#line 7263 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1652:
#line 7264 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1654:
#line 7273 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1655:
#line 7274 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1656:
#line 7283 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1657:
#line 7292 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1658:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1659:
#line 7298 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1660:
#line 7299 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1661:
#line 7300 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1662:
#line 7308 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1663:
#line 7311 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1664:
#line 7317 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1665:
#line 7320 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1666:
#line 7323 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1667:
#line 7329 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1668:
#line 7338 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1669:
#line 7344 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1670:
#line 7347 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1671:
#line 7350 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1672:
#line 7353 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1673:
#line 7360 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1674:
#line 7362 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1675:
#line 7364 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1676:
#line 7366 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1677:
#line 7368 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1678:
#line 7370 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1679:
#line 7372 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1680:
#line 7374 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1681:
#line 7376 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1682:
#line 7378 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1683:
#line 7380 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1684:
#line 7382 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1685:
#line 7384 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1686:
#line 7386 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1687:
#line 7388 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1688:
#line 7390 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1689:
#line 7392 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1690:
#line 7394 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1691:
#line 7396 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1692:
#line 7398 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1693:
#line 7402 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1694:
#line 7403 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1697:
#line 7413 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1698:
#line 7422 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1699:
#line 7426 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1700:
#line 7433 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1701:
#line 7433 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1703:
#line 7437 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1704:
#line 7442 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1705:
#line 7442 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1707:
#line 7446 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1708:
#line 7450 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1711:
#line 7459 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1712:
#line 7459 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1717:
#line 7478 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1718:
#line 7479 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1721:
#line 7487 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1722:
#line 7493 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1725:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1726:
#line 7513 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1727:
#line 7514 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1728:
#line 7515 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1729:
#line 7516 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1730:
#line 7517 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1731:
#line 7521 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1732:
#line 7522 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1733:
#line 7523 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1734:
#line 7527 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1735:
#line 7531 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1737:
#line 7540 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1739:
#line 7545 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1740:
#line 7546 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1741:
#line 7550 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1742:
#line 7556 "fgl.yacc"
    {
 		strcpy(yyval.str,get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1743:
#line 7642 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1744:
#line 7653 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1748:
#line 7659 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1749:
#line 7660 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1753:
#line 7670 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1&&(!system_var(yyvsp[0].str)))
	{
		int z = 0,a = 0;
		a=get_bind_cnt('i');
		z=add_bind('i',yyvsp[0].str);
		z-=a;
		yyval.sql_string=strdup(set_var_sql(z));
	} else {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
}
    break;

  case 1754:
#line 7683 "fgl.yacc"
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

  case 1755:
#line 7733 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 7735 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1757:
#line 7737 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1758:
#line 7738 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1759:
#line 7743 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1760:
#line 7748 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 7750 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 7752 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1763:
#line 7754 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1764:
#line 7757 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1765:
#line 7761 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1766:
#line 7766 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1767:
#line 7771 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1768:
#line 7775 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1770:
#line 7785 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1772:
#line 7800 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1773:
#line 7803 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1774:
#line 7807 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1777:
#line 7826 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1778:
#line 7827 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1779:
#line 7830 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1780:
#line 7831 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1781:
#line 7832 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1782:
#line 7833 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1783:
#line 7834 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1784:
#line 7835 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1785:
#line 7836 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1786:
#line 7841 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1787:
#line 7842 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1788:
#line 7846 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1789:
#line 7850 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1790:
#line 7854 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1791:
#line 7858 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1792:
#line 7863 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1793:
#line 7867 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1794:
#line 7872 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1796:
#line 7880 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1798:
#line 7886 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1799:
#line 7892 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1800:
#line 7896 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1805:
#line 7914 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1806:
#line 7921 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1807:
#line 7930 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1808:
#line 7930 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16511 "y.tab.c"

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


#line 8024 "fgl.yacc"

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



