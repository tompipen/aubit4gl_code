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
#line 190 "fgl.yacc"
typedef union YYSTYPE {



	//char	str[3100];  /* This would core dump in CygWin on call to */
	char	str[1024];  /* This would core dump in CygWin on call to */
						/* yyparse in y.tab.c - 3100 in maximum. */
						/* Was: char	str[20000]; */

	struct expr_str *ptr;
	char *sql_string;

	} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 1515 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 1527 "y.tab.c"

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
#define YYLAST   8433

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  649
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  818
/* YYNRULES -- Number of rules. */
#define YYNRULES  1890
/* YYNRULES -- Number of states. */
#define YYNSTATES  3099

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
    1535,  1542,  1546,  1552,  1558,  1562,  1564,  1566,  1570,  1571,
    1572,  1584,  1585,  1588,  1589,  1590,  1591,  1600,  1601,  1602,
    1613,  1614,  1616,  1617,  1619,  1621,  1624,  1625,  1629,  1630,
    1634,  1635,  1637,  1639,  1642,  1643,  1647,  1648,  1652,  1656,
    1658,  1663,  1667,  1669,  1673,  1675,  1679,  1681,  1685,  1687,
    1690,  1691,  1695,  1696,  1700,  1701,  1706,  1707,  1712,  1713,
    1718,  1721,  1725,  1727,  1731,  1733,  1735,  1737,  1739,  1741,
    1743,  1747,  1749,  1751,  1756,  1763,  1768,  1772,  1779,  1783,
    1790,  1792,  1794,  1796,  1798,  1800,  1802,  1803,  1806,  1808,
    1810,  1812,  1817,  1819,  1821,  1823,  1828,  1832,  1839,  1843,
    1850,  1852,  1854,  1857,  1859,  1861,  1863,  1865,  1867,  1869,
    1871,  1873,  1875,  1877,  1879,  1881,  1883,  1885,  1887,  1889,
    1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,  1907,  1909,
    1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,
    1931,  1933,  1935,  1937,  1939,  1941,  1943,  1946,  1949,  1951,
    1955,  1957,  1960,  1963,  1966,  1971,  1974,  1977,  1982,  1983,
    1992,  1993,  1995,  1997,  1999,  2000,  2002,  2005,  2006,  2008,
    2011,  2012,  2014,  2017,  2018,  2020,  2024,  2025,  2028,  2029,
    2037,  2038,  2039,  2043,  2044,  2045,  2053,  2059,  2062,  2065,
    2066,  2072,  2077,  2079,  2083,  2087,  2091,  2092,  2095,  2096,
    2098,  2100,  2103,  2104,  2109,  2110,  2115,  2116,  2120,  2121,
    2125,  2126,  2130,  2131,  2135,  2136,  2140,  2141,  2146,  2147,
    2152,  2154,  2158,  2160,  2162,  2164,  2168,  2170,  2172,  2174,
    2178,  2180,  2184,  2187,  2192,  2194,  2196,  2198,  2199,  2204,
    2210,  2217,  2218,  2229,  2233,  2235,  2237,  2240,  2243,  2244,
    2247,  2248,  2252,  2254,  2255,  2259,  2262,  2263,  2267,  2269,
    2273,  2275,  2279,  2280,  2283,  2285,  2287,  2289,  2291,  2293,
    2295,  2297,  2299,  2301,  2303,  2305,  2307,  2309,  2311,  2313,
    2315,  2317,  2319,  2320,  2321,  2329,  2331,  2333,  2336,  2339,
    2342,  2346,  2351,  2352,  2356,  2357,  2359,  2361,  2364,  2366,
    2368,  2370,  2372,  2373,  2375,  2377,  2380,  2383,  2385,  2387,
    2389,  2391,  2393,  2395,  2397,  2399,  2401,  2403,  2405,  2407,
    2409,  2410,  2412,  2414,  2416,  2418,  2420,  2421,  2422,  2423,
    2424,  2438,  2440,  2441,  2442,  2449,  2452,  2454,  2457,  2460,
    2462,  2464,  2467,  2469,  2471,  2473,  2474,  2478,  2481,  2483,
    2484,  2485,  2486,  2501,  2502,  2508,  2510,  2511,  2515,  2516,
    2524,  2525,  2531,  2533,  2536,  2537,  2539,  2541,  2543,  2544,
    2546,  2548,  2551,  2554,  2557,  2559,  2561,  2563,  2565,  2569,
    2571,  2573,  2574,  2575,  2583,  2585,  2588,  2589,  2593,  2594,
    2599,  2602,  2603,  2606,  2608,  2610,  2612,  2614,  2616,  2618,
    2620,  2621,  2625,  2626,  2628,  2630,  2632,  2634,  2637,  2640,
    2643,  2649,  2651,  2653,  2655,  2660,  2665,  2667,  2669,  2671,
    2673,  2676,  2680,  2687,  2689,  2693,  2695,  2697,  2699,  2703,
    2710,  2712,  2714,  2716,  2718,  2721,  2722,  2724,  2726,  2730,
    2732,  2736,  2738,  2742,  2744,  2748,  2750,  2752,  2754,  2756,
    2760,  2762,  2766,  2768,  2772,  2774,  2776,  2778,  2782,  2785,
    2786,  2788,  2790,  2795,  2797,  2801,  2803,  2807,  2815,  2816,
    2824,  2825,  2832,  2836,  2838,  2842,  2844,  2847,  2853,  2854,
    2862,  2863,  2866,  2867,  2869,  2875,  2878,  2884,  2885,  2891,
    2898,  2903,  2904,  2906,  2908,  2913,  2914,  2917,  2918,  2924,
    2929,  2932,  2934,  2938,  2941,  2944,  2947,  2950,  2953,  2956,
    2958,  2961,  2964,  2967,  2970,  2973,  2976,  2979,  2982,  2985,
    2987,  2989,  2991,  2993,  2995,  2997,  3003,  3005,  3007,  3010,
    3015,  3017,  3018,  3029,  3035,  3036,  3038,  3039,  3042,  3044,
    3047,  3048,  3052,  3054,  3055,  3060,  3061,  3064,  3066,  3070,
    3072,  3074,  3078,  3083,  3088,  3091,  3093,  3095,  3097,  3098,
    3100,  3108,  3111,  3114,  3117,  3120,  3122,  3125,  3126,  3130,
    3131,  3135,  3136,  3140,  3141,  3145,  3146,  3150,  3151,  3156,
    3157,  3162,  3164,  3166,  3168,  3170,  3172,  3174,  3175,  3180,
    3181,  3183,  3184,  3189,  3191,  3194,  3197,  3200,  3201,  3203,
    3205,  3208,  3211,  3212,  3215,  3219,  3223,  3229,  3230,  3233,
    3238,  3240,  3242,  3244,  3246,  3248,  3249,  3251,  3253,  3257,
    3260,  3266,  3269,  3275,  3281,  3287,  3293,  3299,  3305,  3306,
    3309,  3311,  3314,  3317,  3320,  3323,  3326,  3329,  3331,  3334,
    3337,  3340,  3343,  3345,  3348,  3351,  3354,  3357,  3359,  3361,
    3363,  3364,  3367,  3370,  3373,  3376,  3379,  3382,  3385,  3388,
    3391,  3393,  3395,  3397,  3399,  3401,  3403,  3405,  3407,  3410,
    3413,  3416,  3419,  3422,  3424,  3426,  3428,  3429,  3433,  3436,
    3437,  3438,  3439,  3440,  3441,  3442,  3458,  3459,  3462,  3465,
    3466,  3468,  3469,  3470,  3471,  3472,  3473,  3474,  3490,  3493,
    3494,  3495,  3496,  3507,  3508,  3510,  3514,  3518,  3521,  3526,
    3530,  3534,  3538,  3540,  3542,  3544,  3546,  3548,  3550,  3551,
    3552,  3560,  3561,  3562,  3571,  3575,  3578,  3579,  3581,  3583,
    3587,  3590,  3593,  3595,  3597,  3601,  3603,  3605,  3608,  3610,
    3614,  3616,  3620,  3622,  3624,  3626,  3628,  3630,  3632,  3634,
    3637,  3642,  3644,  3648,  3650,  3654,  3657,  3662,  3664,  3668,
    3670,  3673,  3678,  3680,  3684,  3686,  3688,  3690,  3693,  3696,
    3701,  3704,  3709,  3711,  3715,  3717,  3719,  3721,  3724,  3726,
    3728,  3730,  3732,  3734,  3737,  3744,  3751,  3752,  3754,  3755,
    3757,  3760,  3761,  3762,  3770,  3771,  3774,  3777,  3785,  3787,
    3793,  3797,  3799,  3803,  3805,  3809,  3811,  3815,  3817,  3821,
    3823,  3825,  3827,  3828,  3834,  3835,  3841,  3843,  3844,  3848,
    3850,  3854,  3856,  3860,  3862,  3864,  3865,  3866,  3872,  3875,
    3877,  3878,  3879,  3883,  3884,  3885,  3889,  3891,  3893,  3895,
    3897,  3899,  3901,  3904,  3907,  3912,  3916,  3920,  3922,  3926,
    3929,  3931,  3933,  3934,  3936,  3938,  3940,  3942,  3943,  3945,
    3949,  3950,  3954,  3956,  3958,  3960,  3962,  3964,  3966,  3968,
    3970,  3972,  3974,  3976,  3978,  3986,  3987,  3989,  3991,  3993,
    3995,  3999,  4001,  4003,  4005,  4008,  4009,  4013,  4015,  4019,
    4021,  4025,  4027,  4029,  4036,  4037,  4041,  4043,  4047,  4048,
    4050,  4055,  4061,  4064,  4066,  4068,  4073,  4075,  4079,  4084,
    4089,  4091,  4095,  4097,  4099,  4101,  4104,  4106,  4111,  4112,
    4114,  4115,  4117,  4119,  4122,  4124,  4126,  4128,  4133,  4137,
    4139,  4141,  4143,  4146,  4148,  4150,  4153,  4156,  4158,  4162,
    4165,  4168,  4170,  4174,  4176,  4179,  4184,  4186,  4189,  4191,
    4195,  4200,  4201,  4203,  4204,  4206,  4207,  4209,  4211,  4215,
    4217,  4221,  4223,  4226,  4228,  4232,  4235,  4238,  4239,  4242,
    4244,  4246,  4248,  4254,  4258,  4264,  4268,  4270,  4274,  4276,
    4278,  4279,  4281,  4285,  4289,  4293,  4300,  4305,  4310,  4316,
    4318,  4320,  4322,  4324,  4326,  4328,  4330,  4332,  4334,  4336,
    4338,  4339,  4341,  4343,  4345,  4347,  4349,  4351,  4353,  4358,
    4364,  4366,  4372,  4378,  4380,  4382,  4384,  4389,  4391,  4396,
    4398,  4406,  4408,  4410,  4412,  4417,  4424,  4425,  4428,  4433,
    4435,  4437,  4439,  4441,  4443,  4445,  4447,  4451,  4453,  4455,
    4459,  4461,  4462,  4466,  4472,  4474,  4477,  4480,  4485,  4489,
    4491,  4493,  4495,  4497,  4499,  4502,  4505,  4508,  4511,  4513,
    4516,  4519,  4520,  4524,  4525,  4529,  4531,  4533,  4535,  4537,
    4539,  4541,  4543,  4548,  4550,  4552,  4554,  4556,  4558,  4560,
    4562,  4567,  4569,  4571,  4573,  4575,  4577,  4579,  4581,  4583,
    4585,  4587,  4589,  4591,  4593,  4595,  4597,  4599,  4603,  4604,
    4613,  4614,  4624,  4625,  4633,  4634,  4644,  4645,  4647,  4650,
    4652,  4656,  4658,  4662,  4668,  4670,  4672,  4674,  4676,  4679,
    4680,  4681,  4690,  4696,  4698,  4700,  4707,  4708,  4712,  4714,
    4718,  4723,  4725,  4726,  4729,  4734,  4741,  4742,  4744,  4746,
    4748,  4750,  4754,  4756,  4759,  4762,  4764,  4766,  4768,  4770,
    4773,  4778,  4782,  4785,  4789,  4793,  4797,  4799,  4801,  4803,
    4805,  4807,  4809,  4815,  4821,  4827,  4833,  4839,  4844,  4849,
    4853,  4858,  4860,  4864,  4865,  4867,  4873,  4881,  4887,  4888,
    4891,  4893,  4895,  4896,  4900,  4902,  4906,  4908,  4910,  4912,
    4913,  4917,  4919,  4921,  4923,  4925,  4930,  4937,  4939,  4941,
    4944,  4948,  4950,  4952,  4954,  4956,  4958,  4960,  4962,  4964,
    4970,  4976,  4981,  4982,  4987,  4989,  4992,  4994,  4996,  4998,
    5001,  5004,  5006,  5009,  5011,  5013,  5015,  5019,  5025,  5027,
    5029,  5031,  5033,  5037,  5040,  5043,  5046,  5048,  5051,  5054,
    5057,  5060,  5063,  5065,  5069,  5072,  5074,  5077,  5079,  5082,
    5084,  5085,  5086,  5093,  5094,  5097,  5098,  5100,  5102,  5105,
    5108,  5110,  5112,  5117,  5121,  5123,  5127,  5129,  5132,  5138,
    5141,  5144,  5150,  5151,  5154,  5156,  5158,  5161,  5168,  5175,
    5177,  5178,  5180,  5183,  5185,  5188,  5189,  5192,  5194,  5196,
    5198,  5200,  5202,  5204,  5206,  5208,  5210,  5212,  5214,  5216,
    5218,  5220,  5222,  5224,  5226,  5228,  5230,  5232,  5234,  5236,
    5238,  5240,  5242,  5244,  5246,  5248,  5250,  5252,  5254,  5256,
    5258,  5260,  5262,  5264,  5266,  5268,  5270,  5272,  5274,  5276,
    5278,  5280,  5282,  5284,  5286,  5288,  5290,  5292,  5294,  5296,
    5298,  5300,  5302,  5304,  5306,  5308,  5310,  5312,  5314,  5316,
    5318,  5320,  5322,  5324,  5326,  5328,  5330,  5332,  5334,  5336,
    5338,  5340,  5342,  5344,  5346,  5348,  5350,  5352,  5354,  5356,
    5358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
    1007,     0,    -1,   180,    -1,   177,    -1,   104,   654,   406,
     576,   655,    -1,   118,    -1,  1073,    -1,    25,    -1,   656,
      -1,   655,     5,   656,    -1,   917,    -1,   410,   657,   371,
      -1,   657,   658,   657,    -1,    25,    -1,   659,    25,    -1,
    1073,    -1,    17,    -1,    18,    -1,    20,    -1,    19,    -1,
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
     904,    -1,   514,   671,    -1,   850,   324,  1073,    -1,    -1,
     269,   410,  1451,   371,   324,   672,  1091,    -1,    84,   410,
     917,     5,    24,     5,    24,   371,    -1,   386,   410,   909,
     371,   324,  1073,    -1,  1208,    -1,   172,   410,   909,   371,
     324,  1073,    -1,    -1,    -1,  1073,   570,   917,   410,   673,
     687,   371,   674,   685,    -1,    -1,    -1,    -1,   917,   410,
     675,   687,   676,   371,   677,   685,    -1,    -1,    -1,   454,
    1414,   604,  1414,   410,   678,   687,   679,   371,   685,    -1,
      -1,    -1,   917,   501,   917,   410,   680,   687,   681,   371,
     685,    -1,    -1,    -1,    -1,   345,   690,   570,   691,   438,
     654,   406,   410,   682,   687,   683,   371,   684,   686,    -1,
      -1,   324,  1091,    -1,    -1,   324,  1091,    -1,   142,    -1,
      -1,   688,    -1,   689,    -1,   688,     5,   689,    -1,   819,
      -1,    24,    -1,   917,    -1,   917,    -1,   917,   601,   917,
      -1,    -1,   515,   826,   693,   696,   700,   697,    -1,    -1,
     515,   694,   695,   698,   697,    -1,   702,    -1,   695,   702,
      -1,   704,    -1,   696,   704,    -1,   340,    -1,    -1,    -1,
     319,   699,  1461,    -1,    -1,    -1,   319,   701,  1461,    -1,
      -1,   559,   826,   703,  1461,    -1,    -1,   559,   826,   705,
    1461,    -1,   258,   914,    -1,   182,   912,    -1,    63,   912,
      -1,   149,    -1,   165,  1420,    -1,   474,   911,    -1,    29,
     708,    30,    -1,   709,    -1,   711,    -1,   710,    -1,   709,
     710,    -1,    28,    -1,   712,    -1,   711,   712,    -1,    27,
      -1,   373,    -1,    -1,    -1,   300,   715,   717,   716,   718,
      -1,   364,  1073,   606,   719,   958,   985,   660,    -1,  1073,
     606,   719,   958,   527,  1451,   985,   660,    -1,    -1,   721,
     171,    -1,   720,    -1,   719,     5,   720,    -1,   917,    -1,
     917,   601,   917,    -1,   917,   601,    20,    -1,   722,    -1,
     721,   722,    -1,    -1,   250,   728,   723,  1461,    -1,    -1,
     253,   729,   724,  1461,    -1,    -1,   986,   725,  1461,    -1,
      -1,   147,   726,  1461,    -1,    -1,   143,   727,  1461,    -1,
     921,    -1,   728,     5,   921,    -1,   921,    -1,   729,     5,
     921,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,   410,   819,   732,   371,    -1,    -1,
       5,   773,   607,   776,    -1,   135,    -1,   259,    -1,    -1,
     735,    -1,   736,    -1,   735,   736,    -1,    -1,    -1,   417,
     737,   739,   738,  1177,    -1,   786,    -1,  1441,    -1,   742,
      -1,   739,     5,   742,    -1,    -1,   741,   917,    -1,   333,
     740,   785,    24,    -1,   333,   740,   785,   917,    -1,   333,
     740,   785,   923,    -1,   333,   740,   785,    25,    -1,   746,
     762,    -1,    -1,   740,   333,   743,   744,    -1,    25,    -1,
      24,    -1,   923,    -1,    18,    25,    -1,   740,    -1,   745,
      -1,   746,     5,   745,    -1,    -1,   516,    -1,    -1,   467,
     438,   754,   406,   749,   605,   762,    -1,    -1,   298,   747,
     751,    25,   752,   282,   438,   753,   406,   750,   605,   762,
      -1,   410,    -1,   437,    -1,   371,    -1,   405,    -1,    25,
      -1,   755,     5,   755,     5,   755,    -1,   755,     5,   755,
      -1,   755,    -1,    25,    -1,    -1,   443,   757,   739,   263,
      -1,    -1,   240,   758,   740,   601,    20,    -1,    -1,   314,
     759,   740,   238,   410,   760,   371,    -1,   761,    -1,   760,
       5,   761,    -1,   740,    -1,   764,    -1,    -1,    39,    -1,
      -1,    -1,   765,   767,   766,   763,    -1,   748,    -1,   756,
      -1,   516,    -1,   516,   410,    25,   371,    -1,   403,   410,
      25,   371,    -1,   403,   410,    25,     5,    25,   371,    -1,
     387,    -1,   598,   740,    -1,   359,    -1,   489,    -1,    69,
      -1,   377,    -1,   377,   410,    25,   371,    -1,   377,   410,
      25,     5,    25,   371,    -1,   492,    -1,   492,   410,    25,
     371,    -1,   492,   410,    25,     5,    25,   371,    -1,   482,
      -1,   279,    -1,   518,    -1,   513,    -1,    60,    -1,    61,
      -1,   555,    -1,   337,   771,    -1,   349,   772,    -1,   768,
      -1,    31,    -1,   537,   769,   601,   770,    -1,   740,    -1,
     740,    -1,    -1,   773,   607,   776,    -1,   781,   607,   784,
      -1,    -1,   774,   775,    -1,   562,    -1,   493,    -1,   571,
      -1,   533,    -1,   433,    -1,   450,    -1,   346,   778,    -1,
      -1,   777,   775,    -1,    -1,   410,   780,   371,    -1,    -1,
     410,    25,   371,    -1,    25,    -1,    -1,   782,   783,   779,
      -1,   562,    -1,   493,    -1,   571,    -1,   533,    -1,   433,
      -1,   450,    -1,   346,   778,    -1,   783,    -1,    -1,    13,
      -1,    -1,   216,   917,   787,   598,   788,    -1,   790,    -1,
     793,    -1,   516,    -1,   516,   410,    25,   371,    -1,   403,
     410,    25,   371,    -1,   403,   410,    25,     5,    25,   371,
      -1,   387,    -1,   359,    -1,   489,    -1,   377,    -1,   377,
     410,    25,   371,    -1,   377,   410,    25,     5,    25,   371,
      -1,   492,    -1,   492,   410,    25,   371,    -1,   492,   410,
      25,     5,    25,   371,    -1,   482,    -1,   279,    -1,   518,
      -1,   513,    -1,   555,    -1,   337,   771,    -1,   349,   772,
      -1,   789,    -1,   537,   769,   601,   770,    -1,    -1,   467,
     438,   754,   406,   791,   605,   788,    -1,    -1,   298,   747,
     751,    25,   752,   282,   438,   753,   406,   792,   605,   788,
      -1,    -1,   443,   794,   796,   263,    -1,    -1,   240,   795,
     917,   601,    20,    -1,   797,    -1,   796,     5,   797,    -1,
     798,   788,    -1,   799,    -1,   798,     5,   799,    -1,   917,
      -1,    -1,   599,   908,    -1,    50,   917,    -1,    48,    -1,
     607,  1451,    -1,   607,   489,   917,   640,  1451,    -1,   607,
     489,   917,   369,    -1,    52,   917,    -1,   136,   844,  1091,
     808,    -1,   380,   844,   824,   800,   808,    -1,   189,   914,
     808,    -1,    -1,    -1,   168,   805,  1098,   607,   917,   601,
      20,   807,   660,   806,   809,    -1,    -1,   448,   909,    -1,
     660,    -1,    -1,   810,   218,    -1,   811,    -1,   810,   811,
      -1,    -1,   331,   812,  1461,    -1,    -1,   327,   813,  1461,
      -1,    -1,   986,   814,  1461,    -1,   478,   844,   825,   660,
      -1,   478,   844,   825,   660,    46,    -1,   266,    -1,   265,
      -1,   192,    -1,   344,    -1,   154,    -1,   191,    -1,   308,
      -1,   307,    -1,   223,    -1,   151,    -1,   150,    -1,   124,
      -1,   184,    -1,   107,    -1,   123,    -1,   167,    -1,   133,
      -1,   193,    -1,   193,   826,    -1,   829,    -1,   828,    -1,
     833,    -1,   861,    -1,   819,   820,    -1,   862,    -1,   864,
      -1,   830,    -1,    18,   819,    -1,    17,   819,    -1,   835,
      -1,   843,    -1,   837,    -1,   455,    -1,   730,    -1,   838,
      -1,   839,    -1,   840,    -1,   841,    -1,   842,    -1,   844,
      -1,   844,   823,    -1,   826,    -1,   463,    -1,   822,    -1,
     823,     5,   822,    -1,   826,    -1,   824,     5,   826,    -1,
     826,    -1,   825,     5,   826,    -1,   819,    -1,    17,    -1,
      18,    -1,   583,   819,    -1,   464,    -1,   407,    -1,   410,
     819,   371,    -1,   422,   410,  1395,   371,    -1,   274,   410,
    1395,   371,    -1,   827,   923,    -1,   827,    25,    -1,    24,
      -1,   923,    -1,    25,    -1,   832,    -1,  1073,    -1,  1073,
     400,  1073,    -1,   831,    -1,   413,   819,    -1,   372,   819,
      -1,  1180,    -1,    -1,   487,   834,  1180,    -1,     7,   819,
      -1,     6,   819,    -1,   819,    -1,   836,     5,   819,    -1,
     604,   410,  1395,   371,    -1,   408,   410,  1395,   371,    -1,
     604,   410,   844,   836,   371,    -1,   408,   410,   844,   836,
     371,    -1,   366,    -1,   229,    -1,     9,   819,    -1,   232,
     819,    -1,     9,   819,   421,    24,    -1,   232,   819,   421,
      24,    -1,   537,   819,    -1,   351,   819,    -1,   537,   819,
     421,    24,    -1,   351,   819,   421,    24,    -1,   370,    -1,
       8,   819,    -1,    17,   819,    -1,    18,   819,    -1,    20,
     819,    -1,    19,   819,    -1,    21,   819,    -1,    10,   819,
      -1,    13,   819,    -1,   436,   819,    -1,    11,   819,    -1,
      12,   819,    -1,    16,   819,    -1,    15,   819,    -1,    14,
     819,    -1,    -1,    -1,    -1,   917,   410,   846,   687,   847,
     371,    -1,    -1,    -1,   917,   501,   917,   410,   848,   687,
     849,   371,    -1,    -1,    -1,   518,   410,   851,   819,   852,
     371,    -1,    -1,    -1,   493,   410,   853,   819,   854,   371,
      -1,    -1,    -1,   571,   410,   855,   819,   856,   371,    -1,
      -1,    -1,   562,   410,   857,   819,   858,   371,    -1,   349,
     410,   865,   371,   860,    -1,   337,   410,    24,   371,   859,
      -1,   337,   410,    25,   371,   859,    -1,   337,   410,    25,
     570,    25,   371,   859,    -1,    -1,  1375,   607,  1376,    -1,
     772,    -1,   850,    -1,   269,   410,  1451,   371,    -1,    79,
     410,   909,   371,    -1,    51,   410,   909,   371,    -1,   386,
     410,   909,   371,    -1,   172,   410,   909,   371,    -1,    40,
     410,   909,   371,    -1,   863,    -1,   845,    -1,  1371,    -1,
     518,    -1,   402,   410,   819,   371,    -1,   302,   410,   819,
     371,    -1,   468,   819,    -1,   423,   731,    -1,   819,    88,
      -1,   819,    89,    -1,   819,    90,    -1,    24,    -1,   866,
      -1,    18,   866,    -1,   868,    -1,   867,    -1,    25,    -1,
      25,    25,    -1,    25,    25,   570,    25,    -1,    25,    25,
     570,    25,   570,    25,    -1,    25,    25,   570,    25,   570,
      23,    -1,    25,   570,    25,    -1,    25,   570,    25,   570,
      25,    -1,    25,   570,    25,   570,    23,    -1,    25,   570,
      23,    -1,    23,    -1,    25,    -1,    25,    18,    25,    -1,
      -1,    -1,   576,  1073,    13,   826,   607,   826,   872,   870,
    1461,   871,   221,    -1,    -1,   552,   826,    -1,    -1,    -1,
      -1,   383,   874,   911,   875,  1277,   876,  1461,   220,    -1,
      -1,    -1,   619,   917,   878,   734,   879,  1017,   881,   880,
     886,   620,    -1,    -1,   891,    -1,    -1,   882,    -1,   883,
      -1,   882,   883,    -1,    -1,   621,   884,  1461,    -1,    -1,
     622,   885,  1461,    -1,    -1,   887,    -1,   888,    -1,   887,
     888,    -1,    -1,   623,   889,  1461,    -1,    -1,   624,   890,
    1461,    -1,   892,   896,   304,    -1,    71,    -1,    71,   893,
     527,   894,    -1,    71,   364,   895,    -1,  1073,    -1,   893,
       5,  1073,    -1,   917,    -1,   894,     5,   917,    -1,  1073,
      -1,   895,     5,  1073,    -1,   897,    -1,   896,   897,    -1,
      -1,   625,   898,  1461,    -1,    -1,   626,   899,  1461,    -1,
      -1,   645,   894,   900,  1461,    -1,    -1,   461,   894,   901,
    1461,    -1,    -1,   606,   894,   902,  1461,    -1,   526,   910,
      -1,   535,    18,    25,    -1,   535,    -1,   481,    17,    25,
      -1,   481,    -1,    25,    -1,  1073,    -1,    24,    -1,   922,
      -1,   826,    -1,   906,     5,   906,    -1,   907,    -1,   917,
      -1,   648,   410,   917,   371,    -1,   917,   601,   648,   410,
     917,   371,    -1,   917,   438,   657,   406,    -1,   917,   601,
      20,    -1,   917,   438,   657,   406,   601,    20,    -1,   917,
     601,   917,    -1,   917,   438,   657,   406,   601,   917,    -1,
     918,    -1,   918,    -1,   918,    -1,   918,    -1,   918,    -1,
     918,    -1,    -1,   531,    25,    -1,  1460,    -1,   919,    -1,
    1460,    -1,   329,   410,   920,   371,    -1,  1076,    -1,    24,
      -1,   917,    -1,   917,   438,   657,   406,    -1,   917,   601,
      20,    -1,   917,   438,   657,   406,   601,    20,    -1,   917,
     601,   917,    -1,   917,   438,   657,   406,   601,   917,    -1,
    1073,    -1,    23,    -1,   601,    25,    -1,   353,    -1,   472,
      -1,   473,    -1,   370,    -1,   474,    -1,   333,    -1,   300,
      -1,   476,    -1,   439,    -1,   517,    -1,   428,    -1,   572,
      -1,   376,    -1,   469,    -1,   462,    -1,   540,    -1,   379,
      -1,   338,    -1,   477,    -1,   301,    -1,   519,    -1,   260,
      -1,   574,    -1,   636,    -1,   520,    -1,   302,    -1,   522,
      -1,   384,    -1,   422,    -1,   562,    -1,   493,    -1,   571,
      -1,   455,    -1,   358,    -1,   373,    -1,   418,    -1,   360,
      -1,   421,    -1,   402,    -1,   367,    -1,   325,    -1,   539,
      -1,   518,    -1,   528,  1443,    -1,   633,   927,    -1,   928,
      -1,   927,     5,   928,    -1,   917,    -1,   644,   927,    -1,
     635,   927,    -1,   636,  1451,    -1,   634,   914,   640,  1451,
      -1,   638,   927,    -1,   639,  1451,    -1,   637,   914,   640,
    1451,    -1,    -1,   642,   933,   824,   938,   940,   942,   934,
     936,    -1,    -1,   935,    -1,   630,    -1,   631,    -1,    -1,
     937,    -1,   324,  1073,    -1,    -1,   939,    -1,   369,   824,
      -1,    -1,   941,    -1,   641,    25,    -1,    -1,   943,    -1,
     632,    25,   944,    -1,    -1,   379,    25,    -1,    -1,   603,
     826,   556,   946,  1461,   947,   420,    -1,    -1,    -1,   523,
     948,  1461,    -1,    -1,    -1,    43,   949,   826,   556,   950,
    1461,   947,    -1,    86,   917,   410,    25,   371,    -1,    36,
     917,    -1,    55,   917,    -1,    -1,   270,  1103,   954,   607,
     463,    -1,   270,  1103,   537,   955,    -1,   956,    -1,   955,
       5,   956,    -1,   769,   601,  1367,    -1,   769,   601,    20,
      -1,    -1,   959,   304,    -1,    -1,   130,    -1,   960,    -1,
     959,   960,    -1,    -1,   250,   974,   961,  1461,    -1,    -1,
     253,   975,   962,  1461,    -1,    -1,   331,   963,  1461,    -1,
      -1,   327,   964,  1461,    -1,    -1,   986,   965,  1461,    -1,
      -1,   285,   966,  1461,    -1,    -1,   255,   967,  1461,    -1,
      -1,   645,   972,   968,  1461,    -1,    -1,   461,   970,   969,
    1461,    -1,   971,    -1,   970,     5,   971,    -1,   429,    -1,
     418,    -1,   973,    -1,   972,     5,   973,    -1,   429,    -1,
     418,    -1,   909,    -1,   974,     5,   909,    -1,   909,    -1,
     975,     5,   909,    -1,   294,   978,    -1,   295,   917,   640,
     978,    -1,   542,    -1,   354,    -1,   909,    -1,    -1,   646,
     981,   980,   957,    -1,   364,  1091,   958,   916,   660,    -1,
    1091,   958,   527,  1451,   916,   660,    -1,    -1,   467,  1098,
     958,   527,   917,   601,    20,   916,   982,   660,    -1,   449,
    1451,   984,    -1,   608,    -1,   520,    -1,    56,    25,    -1,
      62,    25,    -1,    -1,   531,    25,    -1,    -1,   409,   987,
     993,    -1,   275,    -1,    -1,   577,   989,   993,    -1,   283,
     995,    -1,    -1,   577,   992,   993,    -1,   995,    -1,   410,
     994,   371,    -1,   995,    -1,   994,     5,   995,    -1,    -1,
     996,   997,    -1,   575,    -1,   292,    -1,   310,    -1,   284,
      -1,   465,    -1,   421,    -1,   608,    -1,   531,    -1,   520,
      -1,   445,    -1,   418,    -1,   521,    -1,   536,    -1,   500,
      -1,   290,    -1,   291,    -1,    24,    -1,   490,    -1,    -1,
      -1,   579,  1000,  1096,  1001,    13,   844,  1002,    -1,   463,
      -1,   825,    -1,   199,  1073,    -1,   188,  1073,    -1,   202,
    1073,    -1,   430,  1073,   313,    -1,   430,  1073,   365,   905,
      -1,    -1,  1009,  1008,  1012,    -1,    -1,  1010,    -1,  1011,
      -1,  1010,  1011,    -1,   952,    -1,  1016,    -1,  1032,    -1,
    1018,    -1,    -1,  1013,    -1,  1015,    -1,  1013,  1015,    -1,
      47,   917,    -1,  1020,    -1,  1026,    -1,  1038,    -1,  1190,
      -1,  1200,    -1,  1059,    -1,  1441,    -1,   877,    -1,   707,
      -1,   951,    -1,   713,    -1,   707,    -1,  1441,    -1,    -1,
     707,    -1,  1441,    -1,   735,    -1,   347,    -1,    41,    -1,
      -1,    -1,    -1,    -1,  1019,  1021,   917,   410,  1022,  1089,
     371,  1023,   734,  1024,  1017,  1461,  1025,    -1,   190,    -1,
      -1,    -1,   538,  1027,   734,  1028,  1461,   341,    -1,   445,
     821,    -1,   844,    -1,   844,   824,    -1,   336,  1379,    -1,
    1033,    -1,  1034,    -1,  1033,  1034,    -1,  1035,    -1,  1016,
      -1,  1031,    -1,    -1,   385,  1036,  1037,    -1,   734,   222,
      -1,   905,    -1,    -1,    -1,    -1,    93,   917,    92,   917,
     410,  1039,  1089,   371,  1040,   734,  1041,  1017,  1461,  1025,
      -1,    -1,   539,  1043,  1058,  1049,  1044,    -1,   342,    -1,
      -1,   214,  1046,  1461,    -1,    -1,    22,  1050,  1051,  1052,
     916,  1047,  1461,    -1,    -1,    22,  1050,   916,  1048,  1461,
      -1,  1045,    -1,  1049,  1045,    -1,    -1,   988,    -1,    24,
      -1,  1073,    -1,    -1,  1073,    -1,    24,    -1,   231,  1056,
      -1,   243,  1057,    -1,   226,  1057,    -1,   566,    -1,    24,
      -1,  1073,    -1,  1056,    -1,  1057,     5,  1056,    -1,  1073,
      -1,    24,    -1,    -1,    -1,   627,   917,  1060,   734,  1061,
    1062,   628,    -1,  1063,    -1,  1062,  1063,    -1,    -1,   629,
    1064,  1461,    -1,    -1,   606,   917,  1065,  1461,    -1,  1069,
    1067,    -1,    -1,   661,  1071,    -1,  1072,    -1,  1068,    -1,
     939,    -1,   941,    -1,   943,    -1,   935,    -1,   937,    -1,
      -1,   350,  1070,   825,    -1,    -1,    46,    -1,    46,    -1,
    1074,    -1,  1076,    -1,   170,  1076,    -1,  1076,   601,    -1,
    1075,  1080,    -1,  1075,   917,   438,  1083,   406,    -1,  1081,
      -1,   917,    -1,  1077,    -1,   917,   437,  1079,   405,    -1,
     917,   437,  1079,   405,    -1,  1073,    -1,    24,    -1,    20,
      -1,   917,    -1,   917,  1082,    -1,   438,  1083,   406,    -1,
     438,  1083,   406,   438,  1083,   406,    -1,  1084,    -1,  1083,
       5,  1084,    -1,   657,    -1,  1086,    -1,  1088,    -1,  1086,
     601,  1087,    -1,  1086,   601,   917,   438,  1083,   406,    -1,
     917,    -1,  1078,    -1,    20,    -1,   917,    -1,   917,  1082,
      -1,    -1,  1090,    -1,  1092,    -1,  1090,     5,  1092,    -1,
    1093,    -1,  1091,     5,  1093,    -1,   917,    -1,   917,   601,
     917,    -1,  1073,    -1,  1073,   400,  1073,    -1,    24,    -1,
     923,    -1,    25,    -1,  1095,    -1,  1094,     5,  1095,    -1,
    1073,    -1,  1073,   400,  1073,    -1,  1097,    -1,  1096,     5,
    1097,    -1,  1085,    -1,  1073,    -1,  1100,    -1,  1099,     5,
    1100,    -1,  1073,  1101,    -1,    -1,   568,    -1,   519,    -1,
     917,   438,  1083,   406,    -1,  1104,    -1,  1103,     5,  1104,
      -1,  1073,    -1,  1073,   400,  1073,    -1,   234,   913,   599,
     907,   560,  1453,   665,    -1,    -1,   599,   410,   826,     5,
     826,   371,  1107,    -1,    -1,   549,   410,   826,     5,   826,
     371,    -1,   235,   917,  1106,    -1,   917,    -1,   318,   915,
    1111,    -1,  1112,    -1,   527,   826,    -1,  1113,  1114,  1119,
       8,  1109,    -1,    -1,   599,  1115,   410,   826,     5,   826,
     371,    -1,    -1,   537,   918,    -1,    -1,   330,    -1,   197,
    1420,   246,  1436,  1118,    -1,   544,   910,    -1,   544,   910,
       8,   844,   824,    -1,    -1,   598,   557,  1414,   353,  1414,
      -1,   598,   557,  1414,     5,   353,  1414,    -1,   598,  1414,
       5,  1414,    -1,    -1,   630,    -1,   631,    -1,    70,  1436,
    1121,  1122,    -1,    -1,   598,  1436,    -1,    -1,   598,   557,
    1414,     8,  1414,    -1,   557,  1414,     8,  1414,    -1,   391,
    1124,    -1,  1125,    -1,  1124,     5,  1125,    -1,   183,   904,
      -1,   264,   904,    -1,   309,   904,    -1,   317,   904,    -1,
     273,   904,    -1,   239,   904,    -1,   990,    -1,   418,   991,
      -1,   429,   991,    -1,   542,   991,    -1,   354,   991,    -1,
     531,   991,    -1,   529,   905,    -1,   530,   905,    -1,   380,
     661,    -1,   646,   661,    -1,   271,    -1,   175,    -1,   131,
      -1,   108,    -1,   126,    -1,   117,    -1,  1419,   393,  1129,
     527,  1127,    -1,  1073,    -1,    24,    -1,   382,  1129,    -1,
     382,  1129,     8,  1091,    -1,   918,    -1,    -1,   441,  1138,
     660,   576,  1133,  1073,   916,   660,  1131,  1134,    -1,   441,
    1138,   660,   324,  1073,    -1,    -1,   516,    -1,    -1,  1135,
     262,    -1,  1136,    -1,  1135,  1136,    -1,    -1,   986,  1137,
    1461,    -1,   825,    -1,    -1,   585,   910,  1140,  1141,    -1,
      -1,   527,  1142,    -1,  1143,    -1,  1142,     5,  1143,    -1,
    1407,    -1,   463,    -1,   200,  1146,    68,    -1,   200,  1146,
     607,  1145,    -1,   200,  1146,    67,  1145,    -1,   200,  1146,
      -1,    24,    -1,   922,    -1,   917,    -1,    -1,   459,    -1,
     125,  1146,  1147,   410,   844,  1030,   371,    -1,   173,  1146,
      -1,  1181,  1189,    -1,   426,    42,    -1,   426,  1152,    -1,
    1153,    -1,  1152,  1153,    -1,    -1,   113,  1154,  1461,    -1,
      -1,   179,  1155,  1461,    -1,    -1,   208,  1156,  1461,    -1,
      -1,   196,  1157,  1461,    -1,    -1,   233,  1158,  1461,    -1,
      -1,   181,  1073,  1159,  1461,    -1,    -1,   204,  1073,  1160,
    1461,    -1,  1171,    -1,  1173,    -1,  1172,    -1,  1162,    -1,
    1198,    -1,  1165,    -1,    -1,   541,   826,  1163,   462,    -1,
      -1,   462,    -1,    -1,   550,   826,  1166,  1164,    -1,   138,
      -1,   610,  1185,    -1,   141,  1185,    -1,   140,  1185,    -1,
      -1,  1168,    -1,  1169,    -1,  1168,  1169,    -1,  1178,  1170,
      -1,    -1,   599,  1185,    -1,   499,  1167,  1177,    -1,   498,
    1414,  1177,    -1,   497,  1176,  1175,  1174,  1177,    -1,    -1,
     132,   819,    -1,   132,   819,     5,   819,    -1,   594,    -1,
     595,    -1,   596,    -1,   597,    -1,  1073,    -1,    -1,   502,
      -1,  1179,    -1,  1178,     5,  1179,    -1,   826,  1212,    -1,
     590,   410,   819,   371,  1197,    -1,    45,  1197,    -1,   476,
     410,    20,   371,  1197,    -1,   392,   410,    20,   371,  1197,
      -1,   367,   410,   819,   371,  1197,    -1,   569,   410,   819,
     371,  1197,    -1,   582,   410,   819,   371,  1197,    -1,   581,
     410,   819,   371,  1197,    -1,    -1,   440,  1182,    -1,  1183,
      -1,  1182,  1183,    -1,   207,    25,    -1,   198,    25,    -1,
     281,    25,    -1,   164,    25,    -1,   236,    25,    -1,   156,
      -1,   323,    24,    -1,   323,  1073,    -1,   157,    24,    -1,
     139,    24,    -1,  1188,    -1,  1184,  1188,    -1,  1186,    88,
      -1,  1186,    90,    -1,  1186,    89,    -1,  1186,    -1,   923,
      -1,    25,    -1,    -1,   440,  1184,    -1,   207,  1185,    -1,
     198,  1185,    -1,   281,  1185,    -1,   164,  1185,    -1,   236,
    1185,    -1,   237,  1185,    -1,   609,    24,    -1,   610,  1185,
      -1,   614,    -1,   611,    -1,   612,    -1,   613,    -1,   618,
      -1,   615,    -1,   616,    -1,   617,    -1,    57,  1185,    -1,
      58,  1185,    -1,    59,  1185,    -1,   323,    24,    -1,   157,
      24,    -1,   379,    -1,    53,    -1,    54,    -1,    -1,   494,
     600,  1099,    -1,   114,  1099,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   444,  1191,   917,   410,  1192,  1089,   371,  1193,
     734,  1194,  1150,  1195,  1151,  1196,   219,    -1,    -1,   506,
     819,    -1,   496,  1199,    -1,    -1,  1127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,  1201,   917,   410,  1202,  1089,
     371,  1203,   734,  1204,  1207,  1205,  1151,  1206,   219,    -1,
    1187,  1189,    -1,    -1,    -1,    -1,   134,   410,    24,     5,
    1209,   687,  1210,   371,  1211,   685,    -1,    -1,   363,    -1,
     363,   198,    25,    -1,   363,   198,  1073,    -1,   588,   826,
      -1,   588,   826,   324,  1073,    -1,   588,   826,   142,    -1,
     588,   826,   558,    -1,   588,   826,   525,    -1,  1215,    -1,
     153,    -1,   303,    -1,   261,    -1,  1222,    -1,  1217,    -1,
      -1,    -1,   186,  1218,  1364,   410,  1219,  1226,   371,    -1,
      -1,    -1,   111,  1220,  1364,   410,  1221,  1226,   371,  1223,
      -1,    83,  1224,   371,    -1,    35,   918,    -1,    -1,   248,
      -1,  1225,    -1,  1224,     5,  1225,    -1,   917,   568,    -1,
     917,   519,    -1,   917,    -1,  1227,    -1,  1226,     5,  1227,
      -1,  1317,    -1,  1315,    -1,   100,   917,    -1,   159,    -1,
      33,   917,  1230,    -1,  1231,    -1,  1230,     5,  1231,    -1,
    1232,    -1,  1235,    -1,  1238,    -1,  1243,    -1,  1244,    -1,
    1242,    -1,  1241,    -1,   565,  1233,    -1,   565,   410,  1234,
     371,    -1,  1227,    -1,  1227,   645,   917,    -1,  1233,    -1,
    1234,     5,  1233,    -1,   522,  1237,    -1,   522,   410,  1236,
     371,    -1,  1237,    -1,  1236,     5,  1237,    -1,   917,    -1,
     434,  1240,    -1,   434,   410,  1239,   371,    -1,  1240,    -1,
    1239,     5,  1240,    -1,  1227,    -1,    65,    -1,    66,    -1,
      64,    25,    -1,    37,  1321,    -1,    37,   410,  1245,   371,
      -1,    38,  1246,    -1,    38,   410,  1245,   371,    -1,  1321,
      -1,  1245,     5,  1321,    -1,   917,    -1,   245,    -1,   211,
      -1,   144,  1249,    -1,   121,    -1,   109,    -1,    99,    -1,
      97,    -1,   101,    -1,   158,  1420,    -1,   210,  1248,   439,
    1414,   607,  1414,    -1,   278,   910,   439,  1414,   607,  1414,
      -1,    -1,  1420,    -1,    -1,   826,    -1,   503,   826,    -1,
      -1,    -1,   458,  1364,  1252,   564,  1255,  1253,  1254,    -1,
      -1,   129,   911,    -1,   506,  1340,    -1,   410,  1259,   371,
      13,   410,  1260,   371,    -1,  1256,    -1,    20,    13,   410,
    1260,   371,    -1,    20,    13,  1260,    -1,  1258,    -1,  1256,
       5,  1258,    -1,  1367,    -1,  1257,    13,  1261,    -1,  1257,
      -1,  1259,     5,  1257,    -1,  1261,    -1,  1260,     5,  1261,
      -1,   463,    -1,  1407,    -1,   209,    -1,    -1,   228,  1264,
    1364,  1267,  1265,    -1,    -1,   459,  1266,   410,  1269,   371,
      -1,  1401,    -1,    -1,   410,  1268,   371,    -1,  1367,    -1,
    1268,     5,  1367,    -1,  1270,    -1,  1269,     5,  1270,    -1,
    1407,    -1,   463,    -1,    -1,    -1,   480,  1272,  1274,  1273,
    1275,    -1,  1279,   911,    -1,   911,    -1,    -1,    -1,   534,
    1276,  1094,    -1,    -1,    -1,   534,  1278,  1094,    -1,   481,
      -1,   535,    -1,   542,    -1,   354,    -1,   321,    -1,   375,
      -1,   357,   826,    -1,   330,   826,    -1,   217,  1364,   129,
     911,    -1,   217,  1364,  1337,    -1,   494,   600,  1283,    -1,
    1284,    -1,  1283,     5,  1284,    -1,  1285,  1286,    -1,    25,
      -1,  1367,    -1,    -1,   568,    -1,   519,    -1,   256,    -1,
     289,    -1,    -1,   306,    -1,   336,  1436,  1289,    -1,    -1,
    1419,  1292,  1293,    -1,  1322,    -1,  1326,    -1,  1288,    -1,
    1421,    -1,  1287,    -1,  1280,    -1,  1281,    -1,  1271,    -1,
    1263,    -1,  1262,    -1,  1391,    -1,  1251,    -1,   485,  1296,
     606,  1364,   607,  1301,  1295,    -1,    -1,   120,    -1,   148,
      -1,  1297,    -1,  1298,    -1,  1297,     5,  1298,    -1,   451,
      -1,   429,    -1,   418,    -1,   458,  1299,    -1,    -1,   410,
    1300,   371,    -1,  1367,    -1,  1300,     5,  1367,    -1,  1302,
      -1,  1301,     5,  1302,    -1,   442,    -1,  1365,    -1,   215,
    1364,  1304,   598,  1401,  1306,    -1,    -1,   410,  1305,   371,
      -1,  1367,    -1,  1305,     5,  1367,    -1,    -1,   119,    -1,
     472,   410,  1340,   371,    -1,   225,   410,  1310,   371,  1309,
      -1,   276,  1311,    -1,  1312,    -1,  1364,    -1,  1364,   410,
    1312,   371,    -1,  1367,    -1,  1312,     5,  1367,    -1,   456,
     410,  1314,   371,    -1,   238,   410,  1314,   371,    -1,  1367,
      -1,  1314,     5,  1367,    -1,  1313,    -1,  1308,    -1,  1307,
      -1,   379,  1370,    -1,   187,    -1,   917,  1356,  1318,  1319,
      -1,    -1,  1316,    -1,    -1,  1320,    -1,  1321,    -1,  1320,
    1321,    -1,   352,    -1,   137,    -1,  1309,    -1,   472,   410,
    1340,   371,    -1,    98,  1323,  1325,    -1,  1324,    -1,  1365,
      -1,  1326,    -1,  1325,  1326,    -1,  1303,    -1,  1294,    -1,
     427,  1340,    -1,   348,  1329,    -1,  1406,    -1,  1329,     5,
    1406,    -1,   506,  1340,    -1,   527,  1332,    -1,  1333,    -1,
    1332,     5,  1333,    -1,  1334,    -1,   495,  1334,    -1,   495,
     410,  1335,   371,    -1,  1364,    -1,  1364,  1369,    -1,  1333,
      -1,  1335,     5,  1333,    -1,  1331,  1337,  1338,  1339,    -1,
      -1,  1330,    -1,    -1,  1328,    -1,    -1,  1327,    -1,  1341,
      -1,  1340,     6,  1341,    -1,  1342,    -1,  1341,     7,  1342,
      -1,  1343,    -1,   583,  1343,    -1,  1354,    -1,   410,  1340,
     371,    -1,   422,  1402,    -1,   274,  1402,    -1,    -1,   421,
    1347,    -1,  1410,    -1,   917,    -1,  1410,    -1,  1407,   604,
     410,  1349,   371,    -1,  1407,   604,  1402,    -1,  1407,   408,
     410,  1349,   371,    -1,  1407,   408,  1402,    -1,  1350,    -1,
    1349,     5,  1350,    -1,  1440,    -1,  1370,    -1,    -1,   583,
      -1,  1407,  1351,   366,    -1,  1407,  1351,   229,    -1,  1407,
    1353,  1407,    -1,  1407,  1351,   368,  1407,     7,  1407,    -1,
    1407,   537,  1346,  1345,    -1,  1407,   351,  1346,  1345,    -1,
    1407,  1351,     9,  1346,  1345,    -1,    13,    -1,    16,    -1,
      11,    -1,    12,    -1,   232,    -1,     9,    -1,    15,    -1,
      14,    -1,  1352,    -1,  1348,    -1,  1344,    -1,    -1,   566,
      -1,   339,    -1,   456,    -1,  1357,    -1,  1358,    -1,  1360,
      -1,   516,    -1,   516,   410,  1361,   371,    -1,   390,   410,
    1362,  1359,   371,    -1,   452,    -1,   377,   410,  1362,  1359,
     371,    -1,   492,   410,  1362,  1359,   371,    -1,   518,    -1,
     387,    -1,   359,    -1,   337,  1377,   607,  1378,    -1,   337,
      -1,   349,  1377,   607,  1378,    -1,   349,    -1,   349,  1377,
     410,    25,   371,   607,  1378,    -1,   555,    -1,   513,    -1,
     403,    -1,   403,   410,    25,   371,    -1,   403,   410,    25,
       5,    25,   371,    -1,    -1,     5,  1363,    -1,   482,   410,
    1362,   371,    -1,   546,    -1,   279,    -1,   482,    -1,    44,
      -1,    25,    -1,    25,    -1,    25,    -1,    24,   601,   917,
      -1,    24,    -1,   917,    -1,   917,   570,   917,    -1,   917,
      -1,    -1,   438,    25,   406,    -1,   438,    25,     5,    25,
     406,    -1,  1368,    -1,   593,  1368,    -1,   917,  1366,    -1,
    1364,   601,   917,  1366,    -1,  1364,   601,    20,    -1,   917,
      -1,    24,    -1,   390,    -1,   923,    -1,    25,    -1,    17,
     923,    -1,    17,    25,    -1,    18,   923,    -1,    18,    25,
      -1,  1372,    -1,   375,  1374,    -1,   375,  1373,    -1,    -1,
    1377,   607,  1378,    -1,    -1,  1375,   607,  1375,    -1,   562,
      -1,   493,    -1,   571,    -1,   533,    -1,   433,    -1,   450,
      -1,   346,    -1,   346,   410,    25,   371,    -1,   562,    -1,
     493,    -1,   571,    -1,   533,    -1,   433,    -1,   450,    -1,
     346,    -1,   346,   410,    25,   371,    -1,   562,    -1,   493,
      -1,   571,    -1,   533,    -1,   433,    -1,   450,    -1,   346,
      -1,   562,    -1,   493,    -1,   571,    -1,   533,    -1,   433,
      -1,   450,    -1,   346,    -1,   917,    -1,    24,    -1,  1419,
     483,   911,    -1,    -1,  1419,   378,   911,   416,   576,  1389,
    1382,  1386,    -1,    -1,  1419,   378,   911,   416,    80,   576,
    1390,  1383,  1386,    -1,    -1,  1419,   378,   911,   115,  1390,
    1384,  1386,    -1,    -1,  1419,   378,   911,   116,    80,   576,
    1390,  1385,  1386,    -1,    -1,   268,    -1,   267,  1387,    -1,
    1388,    -1,  1387,     5,  1388,    -1,   917,    -1,   917,   601,
     917,    -1,    24,   601,   917,   601,   917,    -1,  1390,    -1,
    1263,    -1,  1129,    -1,  1392,    -1,  1392,  1386,    -1,    -1,
      -1,   451,  1403,  1404,  1393,  1400,  1394,  1336,  1398,    -1,
     451,  1403,  1404,  1336,  1398,    -1,  1397,    -1,  1414,    -1,
     451,  1403,  1404,  1400,  1336,  1398,    -1,    -1,   505,  1355,
    1396,    -1,  1282,    -1,   311,  1399,  1223,    -1,  1282,   311,
    1399,  1223,    -1,   917,    -1,    -1,   534,  1094,    -1,   451,
    1403,  1404,  1336,    -1,   410,   451,  1403,  1404,  1336,   371,
      -1,    -1,   566,    -1,   339,    -1,   456,    -1,  1405,    -1,
    1404,     5,  1405,    -1,  1407,    -1,  1407,  1460,    -1,  1407,
     924,    -1,  1407,    -1,  1408,    -1,  1440,    -1,  1402,    -1,
     593,   917,    -1,   593,   917,   601,   917,    -1,  1407,    19,
    1407,    -1,  1407,  1428,    -1,  1407,    20,  1407,    -1,  1407,
      17,  1407,    -1,  1407,    18,  1407,    -1,  1370,    -1,   464,
      -1,   407,    -1,   557,    -1,    20,    -1,    45,    -1,   569,
     410,  1355,  1407,   371,    -1,   581,   410,  1355,  1407,   371,
      -1,   582,   410,  1355,  1407,   371,    -1,   590,   410,  1355,
    1407,   371,    -1,   476,   410,  1355,  1407,   371,    -1,   917,
     410,  1409,   371,    -1,   518,   410,  1409,   371,    -1,   410,
    1407,   371,    -1,   423,   410,  1429,   371,    -1,  1407,    -1,
    1409,     5,  1407,    -1,    -1,  1370,    -1,  1419,   326,  1418,
    1413,  1396,    -1,  1419,   315,  1418,  1413,   228,  1364,  1415,
      -1,  1419,   315,  1418,  1413,  1073,    -1,    -1,   301,  1414,
      -1,    24,    -1,  1073,    -1,    -1,   410,  1416,   371,    -1,
    1417,    -1,  1416,     5,  1417,    -1,   917,    -1,    24,    -1,
    1073,    -1,    -1,   247,  1420,   576,    -1,   918,    -1,  1426,
      -1,  1425,    -1,  1422,    -1,   296,  1423,   607,  1423,    -1,
     277,  1423,   601,  1424,   607,  1424,    -1,   917,    -1,   917,
      -1,   201,   769,    -1,   272,   769,  1427,    -1,   251,    -1,
     155,    -1,    72,    -1,    73,    -1,    74,    -1,    75,    -1,
      76,    -1,    77,    -1,   375,     5,  1377,   607,  1378,    -1,
    1367,     5,  1377,   607,  1378,    -1,   375,  1377,   607,  1378,
      -1,    -1,   589,  1431,  1432,   169,    -1,  1433,    -1,  1432,
    1433,    -1,    32,    -1,  1434,    -1,  1435,    -1,   170,  1440,
      -1,   534,  1094,    -1,  1437,    -1,   170,  1438,    -1,  1438,
      -1,  1102,    -1,   917,    -1,  1438,   601,  1439,    -1,    24,
     601,  1438,   601,  1439,    -1,    20,    -1,  1102,    -1,   917,
      -1,  1437,    -1,  1437,   400,  1437,    -1,   106,  1442,    -1,
     110,  1442,    -1,   105,  1442,    -1,   145,    -1,   146,  1442,
      -1,   103,  1442,    -1,   128,  1442,    -1,   127,  1442,    -1,
     102,  1442,    -1,   335,    -1,   602,   607,  1443,    -1,   528,
    1443,    -1,   553,    -1,   514,  1444,    -1,   917,    -1,   570,
     917,    -1,   917,    -1,    -1,    -1,   507,  1446,   826,  1447,
    1461,   305,    -1,    -1,   640,  1451,    -1,    -1,   643,    -1,
     161,    -1,   257,   912,    -1,    49,   912,    -1,   287,    -1,
     286,    -1,   288,   914,  1448,  1449,    -1,   473,  1451,  1449,
      -1,   909,    -1,  1451,     5,   909,    -1,    82,    -1,   112,
     912,    -1,   826,   547,     5,   826,   372,    -1,   489,   826,
      -1,   244,   912,    -1,    81,  1456,     8,  1457,  1455,    -1,
      -1,   527,   826,    -1,   917,    -1,   917,    -1,   227,   912,
      -1,   230,   912,   607,   826,     5,   826,    -1,   230,   912,
     600,   826,     5,   826,    -1,    26,    -1,    -1,  1463,    -1,
    1464,  1177,    -1,  1462,    -1,  1463,  1462,    -1,    -1,  1465,
    1466,    -1,   650,    -1,   651,    -1,   652,    -1,   653,    -1,
     670,    -1,   692,    -1,   706,    -1,   707,    -1,   713,    -1,
     714,    -1,   733,    -1,   801,    -1,   802,    -1,   803,    -1,
     804,    -1,   815,    -1,   816,    -1,   817,    -1,   818,    -1,
     869,    -1,   873,    -1,   903,    -1,   925,    -1,   926,    -1,
     929,    -1,   930,    -1,   931,    -1,   932,    -1,   945,    -1,
     953,    -1,   976,    -1,   977,    -1,   979,    -1,   983,    -1,
     998,    -1,   999,    -1,  1003,    -1,  1004,    -1,  1005,    -1,
    1006,    -1,  1014,    -1,  1029,    -1,  1042,    -1,  1053,    -1,
    1054,    -1,  1055,    -1,  1066,    -1,  1105,    -1,  1108,    -1,
    1110,    -1,  1116,    -1,  1117,    -1,  1120,    -1,  1123,    -1,
    1126,    -1,  1128,    -1,  1130,    -1,  1132,    -1,  1139,    -1,
    1144,    -1,  1148,    -1,  1149,    -1,  1161,    -1,  1213,    -1,
    1214,    -1,  1216,    -1,  1228,    -1,  1229,    -1,  1247,    -1,
    1250,    -1,  1290,    -1,  1291,    -1,  1380,    -1,  1381,    -1,
    1411,    -1,  1412,    -1,  1430,    -1,  1441,    -1,  1445,    -1,
    1450,    -1,  1452,    -1,  1454,    -1,  1458,    -1,  1459,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   886,   886,   889,   892,   898,   904,   911,   915,   915,
     921,   939,   940,   941,   942,   943,   957,   958,   959,   960,
     961,   966,   967,   978,   981,   984,   984,   988,   991,   992,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1016,  1017,  1020,  1020,
    1028,  1029,  1032,  1038,  1040,  1051,  1053,  1055,  1057,  1061,
    1063,  1125,  1129,  1133,  1133,  1144,  1148,  1152,  1153,  1156,
    1162,  1156,  1175,  1180,  1184,  1175,  1196,  1200,  1196,  1208,
    1213,  1208,  1232,  1239,  1243,  1231,  1269,  1269,  1273,  1274,
    1275,  1280,  1283,  1288,  1292,  1300,  1303,  1303,  1309,  1313,
    1328,  1326,  1344,  1344,  1359,  1359,  1362,  1362,  1366,  1369,
    1369,  1369,  1376,  1377,  1376,  1384,  1384,  1395,  1395,  1414,
    1417,  1420,  1423,  1426,  1429,  1442,  1447,  1447,  1448,  1448,
    1451,  1456,  1456,  1460,  1470,  1484,  1488,  1483,  1498,  1504,
    1512,  1513,  1516,  1516,  1519,  1523,  1528,  1535,  1535,  1539,
    1539,  1546,  1546,  1551,  1551,  1556,  1556,  1561,  1561,  1574,
    1575,  1583,  1584,  1601,  1604,  1607,  1610,  1613,  1616,  1622,
    1633,  1638,  1651,  1655,  1670,  1671,  1675,  1675,  1679,  1679,
    1679,  1680,  1681,  1686,  1686,  1689,  1689,  1698,  1699,  1700,
    1703,  1707,  1708,  1708,  1725,  1725,  1725,  1725,  1729,  1736,
    1737,  1740,  1740,  1743,  1743,  1752,  1749,  1765,  1765,  1767,
    1767,  1769,  1771,  1773,  1775,  1778,  1782,  1782,  1783,  1783,
    1787,  1787,  1799,  1799,  1804,  1808,  1810,  1811,  1814,  1814,
    1814,  1818,  1819,  1820,  1821,  1828,  1829,  1830,  1831,  1834,
    1835,  1836,  1837,  1841,  1846,  1851,  1855,  1858,  1862,  1863,
    1864,  1865,  1866,  1867,  1868,  1869,  1872,  1873,  1874,  1906,
    1910,  1912,  1914,  1914,  1921,  1925,  1925,  1929,  1930,  1931,
    1932,  1933,  1934,  1935,  1941,  1941,  1944,  1946,  1952,  1954,
    1960,  1968,  1968,  1971,  1972,  1973,  1974,  1975,  1976,  1977,
    1983,  1986,  1986,  1999,  1999,  2006,  2007,  2008,  2010,  2011,
    2013,  2015,  2016,  2017,  2018,  2023,  2029,  2035,  2036,  2038,
    2040,  2041,  2042,  2043,  2044,  2045,  2048,  2049,  2056,  2064,
    2064,  2072,  2069,  2084,  2084,  2086,  2086,  2094,  2094,  2097,
    2100,  2101,  2106,  2118,  2122,  2125,  2128,  2129,  2130,  2131,
    2132,  2137,  2144,  2150,  2155,  2159,  2155,  2170,  2172,  2177,
    2182,  2182,  2186,  2186,  2189,  2189,  2195,  2195,  2201,  2201,
    2217,  2220,  2234,  2236,  2238,  2240,  2242,  2244,  2246,  2252,
    2254,  2258,  2260,  2262,  2264,  2266,  2268,  2270,  2276,  2291,
    2294,  2307,  2308,  2309,  2310,  2311,  2315,  2316,  2317,  2321,
    2326,  2333,  2334,  2335,  2336,  2337,  2338,  2339,  2340,  2341,
    2342,  2347,  2347,  2352,  2352,  2355,  2361,  2369,  2375,  2385,
    2386,  2394,  2401,  2405,  2415,  2419,  2424,  2429,  2431,  2441,
    2454,  2462,  2475,  2480,  2486,  2491,  2496,  2497,  2503,  2574,
    2580,  2585,  2593,  2593,  2608,  2612,  2619,  2622,  2630,  2641,
    2651,  2657,  2666,  2671,  2679,  2682,  2685,  2690,  2697,  2702,
    2707,  2712,  2722,  2730,  2738,  2743,  2747,  2752,  2756,  2760,
    2767,  2770,  2773,  2777,  2781,  2785,  2789,  2797,  2807,  2812,
    2805,  2828,  2833,  2828,  2850,  2850,  2850,  2853,  2853,  2853,
    2856,  2856,  2856,  2859,  2859,  2859,  2862,  2868,  2874,  2880,
    2890,  2890,  2894,  2898,  2899,  2905,  2906,  2911,  2914,  2918,
    2922,  2923,  2926,  2931,  2937,  2941,  2945,  2948,  2954,  2957,
    2960,  2975,  2978,  2984,  2985,  2986,  2990,  2991,  2992,  2993,
    2994,  2996,  2997,  2998,  3000,  3001,  3005,  3006,  3020,  3024,
    3019,  3032,  3035,  3049,  3053,  3058,  3048,  3078,  3084,  3078,
    3098,  3098,  3100,  3101,  3105,  3105,  3109,  3109,  3114,  3114,
    3121,  3122,  3126,  3126,  3130,  3130,  3135,  3135,  3142,  3146,
    3147,  3148,  3153,  3153,  3156,  3156,  3160,  3160,  3164,  3164,
    3168,  3168,  3173,  3173,  3178,  3178,  3183,  3183,  3188,  3188,
    3204,  3221,  3222,  3223,  3224,  3225,  3226,  3229,  3229,  3232,
    3234,  3237,  3240,  3242,  3243,  3244,  3246,  3248,  3250,  3252,
    3256,  3263,  3265,  3271,  3276,  3281,  3286,  3286,  3289,  3295,
    3300,  3303,  3310,  3310,  3312,  3313,  3315,  3317,  3319,  3321,
    3325,  3334,  3334,  3341,  3342,  3343,  3344,  3345,  3346,  3347,
    3348,  3349,  3350,  3351,  3352,  3353,  3354,  3355,  3356,  3357,
    3358,  3359,  3360,  3361,  3362,  3363,  3364,  3365,  3366,  3367,
    3368,  3369,  3370,  3371,  3372,  3373,  3374,  3375,  3376,  3377,
    3378,  3379,  3380,  3381,  3382,  3383,  3395,  3408,  3415,  3415,
    3419,  3424,  3430,  3434,  3438,  3444,  3448,  3452,  3458,  3458,
    3466,  3467,  3471,  3471,  3475,  3476,  3479,  3482,  3482,  3485,
    3487,  3487,  3490,  3492,  3492,  3493,  3495,  3495,  3504,  3502,
    3514,  3514,  3514,  3517,  3519,  3517,  3526,  3529,  3535,  3546,
    3546,  3550,  3556,  3556,  3560,  3561,  3572,  3573,  3575,  3577,
    3582,  3582,  3586,  3585,  3592,  3591,  3597,  3597,  3602,  3602,
    3608,  3608,  3613,  3613,  3618,  3618,  3623,  3623,  3628,  3628,
    3636,  3637,  3645,  3646,  3651,  3652,  3661,  3662,  3669,  3670,
    3678,  3679,  3688,  3693,  3698,  3699,  3700,  3704,  3703,  3714,
    3719,  3724,  3724,  3735,  3740,  3741,  3742,  3743,  3746,  3746,
    3752,  3752,  3754,  3757,  3757,  3759,  3763,  3763,  3766,  3767,
    3770,  3770,  3775,  3775,  3778,  3779,  3780,  3781,  3782,  3783,
    3784,  3785,  3786,  3787,  3788,  3789,  3790,  3791,  3792,  3793,
    3794,  3798,  3816,  3816,  3816,  3842,  3853,  3860,  3866,  3872,
    3878,  3889,  3912,  3911,  3928,  3928,  3932,  3933,  3941,  3942,
    3943,  3944,  3951,  3952,  3954,  3955,  3959,  3964,  3965,  3966,
    3967,  3968,  3969,  3970,  3971,  3972,  3973,  3974,  3977,  3977,
    3979,  3979,  3979,  3981,  3985,  3985,  3994,  3999,  4015,  4021,
    3993,  4035,  4049,  4059,  4048,  4072,  4079,  4079,  4084,  4089,
    4094,  4095,  4098,  4098,  4098,  4101,  4101,  4109,  4115,  4129,
    4133,  4146,  4128,  4164,  4164,  4177,  4188,  4187,  4199,  4195,
    4212,  4209,  4222,  4222,  4224,  4225,  4227,  4228,  4231,  4232,
    4233,  4235,  4240,  4245,  4251,  4253,  4254,  4257,  4258,  4261,
    4263,  4272,  4278,  4272,  4289,  4290,  4294,  4294,  4304,  4304,
    4316,  4319,  4323,  4327,  4332,  4336,  4337,  4338,  4339,  4340,
    4344,  4344,  4346,  4346,  4349,  4358,  4406,  4406,  4409,  4413,
    4418,  4459,  4460,  4461,  4464,  4478,  4490,  4490,  4495,  4496,
    4502,  4557,  4562,  4569,  4574,  4582,  4588,  4617,  4620,  4621,
    4662,  4663,  4667,  4668,  4672,  4725,  4729,  4732,  4738,  4749,
    4756,  4764,  4764,  4767,  4768,  4769,  4770,  4771,  4774,  4777,
    4783,  4786,  4790,  4794,  4801,  4806,  4813,  4816,  4822,  4824,
    4824,  4824,  4828,  4842,  4849,  4856,  4859,  4873,  4880,  4881,
    4884,  4885,  4889,  4895,  4900,  4906,  4907,  4912,  4916,  4916,
    4920,  4921,  4924,  4925,  4929,  4937,  4940,  4946,  4947,  4949,
    4951,  4955,  4955,  4956,  4961,  4969,  4970,  4975,  4976,  4978,
    4991,  4993,  4994,  4996,  4999,  5002,  5005,  5008,  5011,  5014,
    5018,  5022,  5026,  5029,  5033,  5036,  5037,  5038,  5041,  5044,
    5047,  5050,  5053,  5056,  5059,  5075,  5083,  5083,  5085,  5092,
    5099,  5114,  5112,  5132,  5137,  5138,  5142,  5143,  5145,  5146,
    5148,  5148,  5156,  5165,  5165,  5175,  5176,  5179,  5180,  5183,
    5187,  5201,  5206,  5211,  5216,  5226,  5226,  5230,  5233,  5233,
    5235,  5245,  5252,  5254,  5258,  5261,  5261,  5265,  5264,  5268,
    5267,  5271,  5270,  5274,  5273,  5277,  5276,  5279,  5279,  5295,
    5294,  5316,  5317,  5318,  5319,  5320,  5321,  5324,  5324,  5330,
    5330,  5333,  5333,  5343,  5344,  5345,  5352,  5364,  5365,  5368,
    5369,  5372,  5375,  5375,  5380,  5384,  5389,  5395,  5396,  5397,
    5401,  5402,  5403,  5404,  5408,  5418,  5420,  5425,  5428,  5433,
    5439,  5446,  5453,  5462,  5469,  5476,  5483,  5490,  5499,  5499,
    5501,  5501,  5504,  5505,  5506,  5507,  5508,  5509,  5510,  5511,
    5512,  5513,  5516,  5516,  5519,  5520,  5521,  5522,  5525,  5525,
    5528,  5528,  5531,  5532,  5533,  5534,  5535,  5536,  5537,  5538,
    5540,  5541,  5542,  5543,  5545,  5546,  5547,  5548,  5550,  5551,
    5552,  5553,  5554,  5555,  5556,  5557,  5561,  5567,  5575,  5586,
    5595,  5606,  5610,  5614,  5620,  5585,  5633,  5636,  5644,  5656,
    5658,  5663,  5671,  5681,  5684,  5688,  5696,  5662,  5705,  5709,
    5713,  5717,  5709,  5727,  5728,  5729,  5730,  5735,  5737,  5740,
    5744,  5747,  5754,  5759,  5760,  5761,  5766,  5767,  5773,  5773,
    5773,  5778,  5778,  5778,  5789,  5790,  5796,  5797,  5803,  5804,
    5809,  5810,  5811,  5815,  5818,  5824,  5827,  5835,  5836,  5842,
    5849,  5852,  5861,  5864,  5867,  5870,  5873,  5876,  5879,  5886,
    5889,  5896,  5899,  5905,  5908,  5915,  5918,  5925,  5926,  5931,
    5935,  5938,  5944,  5947,  5953,  5960,  5961,  5965,  5971,  5974,
    5981,  5982,  5989,  5992,  5997,  6008,  6009,  6010,  6011,  6012,
    6013,  6014,  6015,  6016,  6019,  6022,  6028,  6028,  6034,  6034,
    6045,  6059,  6061,  6059,  6068,  6072,  6078,  6086,  6096,  6099,
    6109,  6131,  6134,  6140,  6143,  6148,  6149,  6155,  6158,  6167,
    6171,  6177,  6187,  6187,  6192,  6192,  6196,  6200,  6201,  6207,
    6208,  6213,  6217,  6224,  6227,  6234,  6238,  6233,  6250,  6254,
    6261,  6265,  6265,  6278,  6282,  6282,  6297,  6299,  6301,  6303,
    6305,  6307,  6309,  6311,  6317,  6327,  6334,  6339,  6340,  6344,
    6346,  6347,  6350,  6351,  6352,  6355,  6360,  6367,  6368,  6374,
    6387,  6387,  6392,  6397,  6402,  6403,  6406,  6407,  6412,  6417,
    6421,  6426,  6427,  6431,  6438,  6442,  6443,  6448,  6450,  6454,
    6455,  6459,  6460,  6461,  6462,  6466,  6467,  6472,  6473,  6478,
    6479,  6484,  6485,  6490,  6495,  6496,  6501,  6502,  6506,  6507,
    6512,  6519,  6524,  6529,  6533,  6534,  6539,  6540,  6546,  6548,
    6553,  6554,  6560,  6563,  6566,  6573,  6575,  6587,  6592,  6593,
    6596,  6598,  6605,  6608,  6614,  6618,  6622,  6625,  6632,  6639,
    6644,  6648,  6649,  6655,  6658,  6669,  6676,  6682,  6685,  6692,
    6699,  6705,  6706,  6712,  6713,  6714,  6717,  6718,  6723,  6723,
    6727,  6735,  6736,  6739,  6742,  6747,  6748,  6753,  6756,  6762,
    6765,  6771,  6774,  6780,  6783,  6790,  6791,  6820,  6821,  6826,
    6827,  6831,  6836,  6839,  6842,  6845,  6851,  6852,  6856,  6859,
    6862,  6863,  6868,  6871,  6874,  6877,  6880,  6883,  6886,  6892,
    6893,  6894,  6895,  6896,  6898,  6900,  6901,  6906,  6909,  6913,
    6919,  6920,  6921,  6922,  6934,  6935,  6936,  6940,  6941,  6946,
    6948,  6949,  6950,  6952,  6953,  6954,  6955,  6957,  6958,  6960,
    6961,  6963,  6964,  6965,  6966,  6968,  6972,  6973,  6979,  6981,
    6982,  6983,  6984,  6989,  6993,  6997,  7001,  7002,  7006,  7007,
    7017,  7025,  7026,  7027,  7031,  7034,  7039,  7044,  7049,  7057,
    7061,  7065,  7066,  7067,  7068,  7070,  7072,  7074,  7076,  7079,
    7082,  7086,  7087,  7091,  7092,  7096,  7096,  7096,  7096,  7096,
    7096,  7097,  7100,  7105,  7105,  7105,  7105,  7105,  7105,  7107,
    7110,  7116,  7116,  7116,  7116,  7116,  7116,  7116,  7117,  7117,
    7117,  7117,  7117,  7117,  7117,  7119,  7120,  7123,  7132,  7132,
    7137,  7137,  7143,  7143,  7148,  7148,  7155,  7156,  7157,  7160,
    7160,  7163,  7164,  7165,  7170,  7173,  7179,  7182,  7190,  7203,
    7204,  7201,  7220,  7230,  7233,  7238,  7250,  7253,  7257,  7260,
    7261,  7267,  7270,  7271,  7280,  7289,  7294,  7295,  7296,  7297,
    7305,  7308,  7314,  7317,  7320,  7326,  7335,  7341,  7344,  7347,
    7350,  7356,  7358,  7360,  7362,  7364,  7366,  7368,  7370,  7372,
    7374,  7376,  7378,  7380,  7382,  7384,  7386,  7388,  7390,  7392,
    7394,  7399,  7400,  7406,  7407,  7410,  7419,  7423,  7430,  7430,
    7434,  7434,  7439,  7439,  7443,  7443,  7447,  7453,  7453,  7456,
    7456,  7462,  7469,  7470,  7471,  7475,  7476,  7479,  7480,  7484,
    7490,  7500,  7501,  7509,  7510,  7511,  7512,  7513,  7514,  7518,
    7519,  7520,  7524,  7524,  7536,  7537,  7541,  7542,  7543,  7547,
    7553,  7638,  7650,  7650,  7654,  7655,  7656,  7657,  7661,  7662,
    7663,  7666,  7679,  7729,  7731,  7733,  7735,  7739,  7744,  7746,
    7748,  7750,  7754,  7757,  7762,  7767,  7771,  7780,  7781,  7785,
    7797,  7800,  7796,  7819,  7819,  7823,  7824,  7827,  7828,  7829,
    7830,  7831,  7832,  7833,  7838,  7839,  7843,  7846,  7851,  7855,
    7860,  7864,  7869,  7873,  7876,  7880,  7883,  7888,  7892,  7903,
    7909,  7909,  7910,  7911,  7918,  7927,  7927,  7929,  7930,  7931,
    7932,  7933,  7934,  7935,  7936,  7937,  7938,  7939,  7940,  7941,
    7942,  7943,  7944,  7945,  7946,  7947,  7948,  7949,  7950,  7951,
    7952,  7953,  7954,  7955,  7956,  7957,  7958,  7959,  7960,  7961,
    7962,  7963,  7964,  7965,  7966,  7967,  7968,  7969,  7970,  7971,
    7972,  7973,  7974,  7975,  7976,  7977,  7978,  7979,  7980,  7981,
    7982,  7983,  7984,  7985,  7986,  7987,  7988,  7989,  7990,  7991,
    7992,  7993,  7994,  7995,  7996,  7997,  7998,  7999,  8000,  8001,
    8002,  8003,  8004,  8005,  8006,  8007,  8008,  8009,  8010,  8011,
    8012
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
     919,   919,   920,   920,   921,   921,   921,   921,   921,   921,
     922,   923,   923,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   924,   924,   924,   924,
     924,   924,   924,   924,   924,   924,   925,   926,   927,   927,
     928,   929,   930,   930,   930,   931,   931,   931,   933,   932,
     934,   934,   935,   935,   936,   936,   937,   938,   938,   939,
     940,   940,   941,   942,   942,   943,   944,   944,   946,   945,
     947,   948,   947,   949,   950,   947,   951,   951,   952,   954,
     953,   953,   955,   955,   956,   956,   957,   957,   958,   958,
     959,   959,   961,   960,   962,   960,   963,   960,   964,   960,
     965,   960,   966,   960,   967,   960,   968,   960,   969,   960,
     970,   970,   971,   971,   972,   972,   973,   973,   974,   974,
     975,   975,   976,   977,   978,   978,   978,   980,   979,   981,
     981,   982,   981,   983,   984,   984,   984,   984,   985,   985,
     987,   986,   986,   989,   988,   990,   992,   991,   993,   993,
     994,   994,   996,   995,   997,   997,   997,   997,   997,   997,
     997,   997,   997,   997,   997,   997,   997,   997,   997,   997,
     997,   998,  1000,  1001,   999,  1002,  1002,  1003,  1004,  1005,
    1006,  1006,  1008,  1007,  1009,  1009,  1010,  1010,  1011,  1011,
    1011,  1011,  1012,  1012,  1013,  1013,  1014,  1015,  1015,  1015,
    1015,  1015,  1015,  1015,  1015,  1015,  1015,  1015,  1016,  1016,
    1017,  1017,  1017,  1018,  1019,  1019,  1021,  1022,  1023,  1024,
    1020,  1025,  1027,  1028,  1026,  1029,  1030,  1030,  1031,  1032,
    1033,  1033,  1034,  1034,  1034,  1036,  1035,  1037,  1037,  1039,
    1040,  1041,  1038,  1043,  1042,  1044,  1046,  1045,  1047,  1045,
    1048,  1045,  1049,  1049,  1050,  1050,  1051,  1051,  1052,  1052,
    1052,  1053,  1054,  1055,  1056,  1056,  1056,  1057,  1057,  1058,
    1058,  1060,  1061,  1059,  1062,  1062,  1064,  1063,  1065,  1063,
    1066,  1067,  1067,  1067,  1067,  1068,  1068,  1068,  1068,  1068,
    1070,  1069,  1071,  1071,  1072,  1073,  1074,  1074,  1075,  1076,
    1076,  1076,  1076,  1076,  1077,  1078,  1079,  1079,  1080,  1080,
    1081,  1082,  1082,  1083,  1083,  1084,  1085,  1086,  1086,  1086,
    1086,  1086,  1087,  1087,  1088,  1089,  1089,  1090,  1090,  1091,
    1091,  1092,  1092,  1093,  1093,  1093,  1093,  1093,  1094,  1094,
    1095,  1095,  1096,  1096,  1097,  1098,  1099,  1099,  1100,  1101,
    1101,  1101,  1102,  1103,  1103,  1104,  1104,  1105,  1106,  1106,
    1107,  1107,  1108,  1109,  1110,  1111,  1111,  1112,  1113,  1113,
    1114,  1114,  1115,  1115,  1116,  1117,  1117,  1118,  1118,  1118,
    1118,  1119,  1119,  1119,  1120,  1121,  1121,  1122,  1122,  1122,
    1123,  1124,  1124,  1125,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,  1125,
    1125,  1125,  1125,  1125,  1125,  1126,  1127,  1127,  1128,  1128,
    1129,  1131,  1130,  1132,  1133,  1133,  1134,  1134,  1135,  1135,
    1137,  1136,  1138,  1140,  1139,  1141,  1141,  1142,  1142,  1143,
    1143,  1144,  1144,  1144,  1144,  1145,  1145,  1146,  1147,  1147,
    1148,  1149,  1150,  1151,  1151,  1152,  1152,  1154,  1153,  1155,
    1153,  1156,  1153,  1157,  1153,  1158,  1153,  1159,  1153,  1160,
    1153,  1161,  1161,  1161,  1161,  1161,  1161,  1163,  1162,  1164,
    1164,  1166,  1165,  1165,  1165,  1165,  1165,  1167,  1167,  1168,
    1168,  1169,  1170,  1170,  1171,  1172,  1173,  1174,  1174,  1174,
    1175,  1175,  1175,  1175,  1176,  1177,  1177,  1178,  1178,  1179,
    1180,  1180,  1180,  1180,  1180,  1180,  1180,  1180,  1181,  1181,
    1182,  1182,  1183,  1183,  1183,  1183,  1183,  1183,  1183,  1183,
    1183,  1183,  1184,  1184,  1185,  1185,  1185,  1185,  1186,  1186,
    1187,  1187,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,  1188,
    1188,  1188,  1188,  1188,  1188,  1188,  1189,  1189,  1189,  1191,
    1192,  1193,  1194,  1195,  1196,  1190,  1197,  1197,  1198,  1199,
    1199,  1201,  1202,  1203,  1204,  1205,  1206,  1200,  1207,  1209,
    1210,  1211,  1208,  1212,  1212,  1212,  1212,  1213,  1213,  1213,
    1213,  1213,  1214,  1215,  1215,  1215,  1216,  1216,  1218,  1219,
    1217,  1220,  1221,  1217,  1222,  1222,  1223,  1223,  1224,  1224,
    1225,  1225,  1225,  1226,  1226,  1227,  1227,  1228,  1228,  1229,
    1230,  1230,  1231,  1231,  1231,  1231,  1231,  1231,  1231,  1232,
    1232,  1233,  1233,  1234,  1234,  1235,  1235,  1236,  1236,  1237,
    1238,  1238,  1239,  1239,  1240,  1241,  1241,  1242,  1243,  1243,
    1244,  1244,  1245,  1245,  1246,  1247,  1247,  1247,  1247,  1247,
    1247,  1247,  1247,  1247,  1247,  1247,  1248,  1248,  1249,  1249,
    1250,  1252,  1253,  1251,  1254,  1254,  1254,  1255,  1255,  1255,
    1255,  1256,  1256,  1257,  1258,  1259,  1259,  1260,  1260,  1261,
    1261,  1262,  1264,  1263,  1266,  1265,  1265,  1267,  1267,  1268,
    1268,  1269,  1269,  1270,  1270,  1272,  1273,  1271,  1274,  1274,
    1275,  1276,  1275,  1277,  1278,  1277,  1279,  1279,  1279,  1279,
    1279,  1279,  1279,  1279,  1280,  1281,  1282,  1283,  1283,  1284,
    1285,  1285,  1286,  1286,  1286,  1287,  1288,  1289,  1289,  1290,
    1292,  1291,  1293,  1293,  1293,  1293,  1293,  1293,  1293,  1293,
    1293,  1293,  1293,  1293,  1294,  1295,  1295,  1296,  1296,  1297,
    1297,  1298,  1298,  1298,  1298,  1299,  1299,  1300,  1300,  1301,
    1301,  1302,  1302,  1303,  1304,  1304,  1305,  1305,  1306,  1306,
    1307,  1308,  1309,  1310,  1311,  1311,  1312,  1312,  1313,  1313,
    1314,  1314,  1315,  1315,  1315,  1316,  1316,  1317,  1318,  1318,
    1319,  1319,  1320,  1320,  1321,  1321,  1321,  1321,  1322,  1323,
    1324,  1325,  1325,  1326,  1326,  1327,  1328,  1329,  1329,  1330,
    1331,  1332,  1332,  1333,  1333,  1333,  1334,  1334,  1335,  1335,
    1336,  1337,  1337,  1338,  1338,  1339,  1339,  1340,  1340,  1341,
    1341,  1342,  1342,  1343,  1343,  1344,  1344,  1345,  1345,  1346,
    1346,  1347,  1348,  1348,  1348,  1348,  1349,  1349,  1350,  1350,
    1351,  1351,  1352,  1352,  1352,  1352,  1352,  1352,  1352,  1353,
    1353,  1353,  1353,  1353,  1353,  1353,  1353,  1354,  1354,  1354,
    1355,  1355,  1355,  1355,  1356,  1356,  1356,  1357,  1357,  1358,
    1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,  1358,
    1358,  1358,  1358,  1358,  1358,  1358,  1359,  1359,  1360,  1360,
    1360,  1360,  1360,  1361,  1362,  1363,  1364,  1364,  1364,  1364,
    1365,  1366,  1366,  1366,  1367,  1367,  1368,  1368,  1368,  1369,
    1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1370,  1371,
    1372,  1373,  1373,  1374,  1374,  1375,  1375,  1375,  1375,  1375,
    1375,  1375,  1375,  1376,  1376,  1376,  1376,  1376,  1376,  1376,
    1376,  1377,  1377,  1377,  1377,  1377,  1377,  1377,  1378,  1378,
    1378,  1378,  1378,  1378,  1378,  1379,  1379,  1380,  1382,  1381,
    1383,  1381,  1384,  1381,  1385,  1381,  1386,  1386,  1386,  1387,
    1387,  1388,  1388,  1388,  1389,  1389,  1390,  1390,  1391,  1393,
    1394,  1392,  1395,  1396,  1396,  1397,  1398,  1398,  1398,  1398,
    1398,  1399,  1400,  1400,  1401,  1402,  1403,  1403,  1403,  1403,
    1404,  1404,  1405,  1405,  1405,  1406,  1407,  1407,  1407,  1407,
    1407,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,
    1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,  1408,
    1408,  1409,  1409,  1410,  1410,  1411,  1412,  1412,  1413,  1413,
    1414,  1414,  1415,  1415,  1416,  1416,  1417,  1418,  1418,  1419,
    1419,  1420,  1421,  1421,  1421,  1422,  1422,  1423,  1424,  1425,
    1426,  1427,  1427,  1428,  1428,  1428,  1428,  1428,  1428,  1429,
    1429,  1429,  1431,  1430,  1432,  1432,  1433,  1433,  1433,  1434,
    1435,  1436,  1437,  1437,  1438,  1438,  1438,  1438,  1439,  1439,
    1439,  1440,  1440,  1441,  1441,  1441,  1441,  1441,  1441,  1441,
    1441,  1441,  1442,  1442,  1442,  1442,  1442,  1443,  1443,  1444,
    1446,  1447,  1445,  1448,  1448,  1449,  1449,  1450,  1450,  1450,
    1450,  1450,  1450,  1450,  1451,  1451,  1452,  1452,  1453,  1453,
    1454,  1454,  1455,  1455,  1456,  1457,  1458,  1459,  1459,  1460,
    1461,  1461,  1462,  1463,  1463,  1465,  1464,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,  1466,
    1466
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
       6,     3,     5,     5,     3,     1,     1,     3,     0,     0,
      11,     0,     2,     0,     0,     0,     8,     0,     0,    10,
       0,     1,     0,     1,     1,     2,     0,     3,     0,     3,
       0,     1,     1,     2,     0,     3,     0,     3,     3,     1,
       4,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       0,     3,     0,     3,     0,     4,     0,     4,     0,     4,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     4,     6,     4,     3,     6,     3,     6,
       1,     1,     1,     1,     1,     1,     0,     2,     1,     1,
       1,     4,     1,     1,     1,     4,     3,     6,     3,     6,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     3,
       1,     2,     2,     2,     4,     2,     2,     4,     0,     8,
       0,     1,     1,     1,     0,     1,     2,     0,     1,     2,
       0,     1,     2,     0,     1,     3,     0,     2,     0,     7,
       0,     0,     3,     0,     0,     7,     5,     2,     2,     0,
       5,     4,     1,     3,     3,     3,     0,     2,     0,     1,
       1,     2,     0,     4,     0,     4,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     4,     0,     4,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     3,     2,     4,     1,     1,     1,     0,     4,     5,
       6,     0,    10,     3,     1,     1,     2,     2,     0,     2,
       0,     3,     1,     0,     3,     2,     0,     3,     1,     3,
       1,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     0,     7,     1,     1,     2,     2,     2,
       3,     4,     0,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     0,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     0,     0,     0,     0,
      13,     1,     0,     0,     6,     2,     1,     2,     2,     1,
       1,     2,     1,     1,     1,     0,     3,     2,     1,     0,
       0,     0,    14,     0,     5,     1,     0,     3,     0,     7,
       0,     5,     1,     2,     0,     1,     1,     1,     0,     1,
       1,     2,     2,     2,     1,     1,     1,     1,     3,     1,
       1,     0,     0,     7,     1,     2,     0,     3,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     0,     1,     1,     1,     1,     2,     2,     2,
       5,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       2,     3,     6,     1,     3,     1,     1,     1,     3,     6,
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
       7,     2,     2,     2,     2,     1,     2,     0,     3,     0,
       3,     0,     3,     0,     3,     0,     3,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       1,     0,     4,     1,     2,     2,     2,     0,     1,     1,
       2,     2,     0,     2,     3,     3,     5,     0,     2,     4,
       1,     1,     1,     1,     1,     0,     1,     1,     3,     2,
       5,     2,     5,     5,     5,     5,     5,     5,     0,     2,
       1,     2,     2,     2,     2,     2,     2,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     1,     1,
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     0,     3,     2,     0,
       0,     0,     0,     0,     0,    15,     0,     2,     2,     0,
       1,     0,     0,     0,     0,     0,     0,    15,     2,     0,
       0,     0,    10,     0,     1,     3,     3,     2,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     0,     0,
       7,     0,     0,     8,     3,     2,     0,     1,     1,     3,
       2,     2,     1,     1,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     1,     3,     2,     4,     1,     3,     1,
       2,     4,     1,     3,     1,     1,     1,     2,     2,     4,
       2,     4,     1,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     6,     6,     0,     1,     0,     1,
       2,     0,     0,     7,     0,     2,     2,     7,     1,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     0,     5,     0,     5,     1,     0,     3,     1,
       3,     1,     3,     1,     1,     0,     0,     5,     2,     1,
       0,     0,     3,     0,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     3,     3,     1,     3,     2,
       1,     1,     0,     1,     1,     1,     1,     0,     1,     3,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     7,     0,     1,     1,     1,     1,
       3,     1,     1,     1,     2,     0,     3,     1,     3,     1,
       3,     1,     1,     6,     0,     3,     1,     3,     0,     1,
       4,     5,     2,     1,     1,     4,     1,     3,     4,     4,
       1,     3,     1,     1,     1,     2,     1,     4,     0,     1,
       0,     1,     1,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     2,     1,     1,     2,     2,     1,     3,     2,
       2,     1,     3,     1,     2,     4,     1,     2,     1,     3,
       4,     0,     1,     0,     1,     0,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     2,     2,     0,     2,     1,
       1,     1,     5,     3,     5,     3,     1,     3,     1,     1,
       0,     1,     3,     3,     3,     6,     4,     4,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     4,     5,
       1,     5,     5,     1,     1,     1,     4,     1,     4,     1,
       7,     1,     1,     1,     4,     6,     0,     2,     4,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     3,
       1,     0,     3,     5,     1,     2,     2,     4,     3,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     8,
       0,     9,     0,     7,     0,     9,     0,     1,     2,     1,
       3,     1,     3,     5,     1,     1,     1,     1,     2,     0,
       0,     8,     5,     1,     1,     6,     0,     3,     1,     3,
       4,     1,     0,     2,     4,     6,     0,     1,     1,     1,
       1,     3,     1,     2,     2,     1,     1,     1,     1,     2,
       4,     3,     2,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     5,     5,     5,     5,     5,     4,     4,     3,
       4,     1,     3,     0,     1,     5,     7,     5,     0,     2,
       1,     1,     0,     3,     1,     3,     1,     1,     1,     0,
       3,     1,     1,     1,     1,     4,     6,     1,     1,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     4,     0,     4,     1,     2,     1,     1,     1,     2,
       2,     1,     2,     1,     1,     1,     3,     5,     1,     1,
       1,     1,     3,     2,     2,     2,     1,     2,     2,     2,
       2,     2,     1,     3,     2,     1,     2,     1,     2,     1,
       0,     0,     6,     0,     2,     0,     1,     1,     2,     2,
       1,     1,     4,     3,     1,     3,     1,     2,     5,     2,
       2,     5,     0,     2,     1,     1,     2,     6,     6,     1,
       0,     1,     2,     1,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
     814,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1756,     0,     0,     0,   865,   178,   838,   843,   176,   181,
     818,     0,   812,   815,   816,   819,   821,   864,   820,   859,
     860,   862,   182,   133,   130,     0,   126,   128,   127,   131,
    1799,   708,   608,  1762,     0,     0,  1765,     0,  1761,  1758,
    1755,  1753,  1754,  1760,  1759,  1757,   293,  1616,  1615,   858,
     174,   185,   177,   182,     1,   822,   817,   863,   861,   839,
     125,   129,   132,  1769,  1766,     0,  1767,  1764,     0,     0,
     587,     0,     0,   175,   868,   932,   588,   866,   620,   925,
       0,   926,   933,   931,   185,   179,   198,     0,   183,   199,
     228,     0,   845,  1211,     0,     0,   844,   134,  1199,   852,
       0,     0,   835,   837,   834,   836,   813,   823,   824,   846,
     827,   828,   829,   832,   830,   831,   833,  1768,  1763,     0,
     927,   867,     0,     0,   940,   938,   939,   929,   928,   291,
     185,  1135,   192,   186,   185,   191,   225,     0,   707,     0,
       0,     0,     0,   174,   537,   901,   825,     0,   325,   311,
     201,   262,   281,   302,   304,   301,     0,   323,     0,   310,
     303,   307,   313,   297,   312,   185,   314,   294,   317,   295,
     296,   937,   936,     0,    21,    22,    13,     0,   945,     0,
      15,     0,   943,     0,   292,     0,   184,  1136,   180,     0,
     198,   200,   258,   252,   253,   241,   218,   249,   201,   220,
     262,   281,   239,   242,   237,     0,   216,     0,   248,   240,
     245,   251,   233,   250,   185,   254,   185,   231,   232,   229,
     257,     0,     0,     0,     0,   853,   174,   174,     0,     0,
     202,     0,   315,     0,     0,   316,     0,     0,     0,     0,
       0,     0,     0,     0,   260,     0,   934,     0,    16,    17,
      19,    18,    20,     0,    14,     0,   941,     0,   621,   187,
     190,     0,   188,   189,     0,   195,   194,   193,   196,   185,
       0,   185,   255,   256,     0,     0,   185,     0,     0,     0,
       0,   238,   226,  1212,     0,     0,  1200,  1805,   538,   902,
     847,     0,   207,   208,     0,   274,   276,   271,   272,   268,
     270,   267,   269,   266,     0,   276,   287,   288,   284,   286,
     283,   285,   278,     0,     0,     0,   327,     0,   330,   332,
     215,     0,   214,     0,     0,   185,    11,    12,   944,     0,
     930,   622,   197,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   185,   227,   230,   955,   706,   869,   955,     0,
    1803,  1805,  1135,  1709,   840,     0,   955,     0,     0,   263,
       0,     0,   273,   290,   264,   289,     0,   282,     0,   305,
       0,   299,     0,   324,     0,   329,   319,     0,     0,   308,
     298,   261,   318,     0,     0,     0,     0,     0,   243,     0,
     235,   217,   203,     0,   246,   234,   259,   961,     0,   956,
     957,   955,     0,   854,  1804,  1802,     0,     0,     0,     0,
       0,     0,     0,  1786,     0,  1301,  1300,     0,  1302,     0,
     375,  1299,  1241,     0,     5,  1298,   376,   373,     0,   378,
     172,   467,  1113,     0,     0,  1308,   122,   372,   371,  1233,
     366,     0,  1258,  1777,     0,   377,   344,     0,     3,     2,
       0,   374,  1238,     0,     0,   367,   364,   379,     0,     0,
       0,     0,  1306,  1296,   370,     0,     0,     0,     0,     0,
       0,     0,     0,  1295,     0,     0,     0,   173,  1235,   363,
     362,     0,     0,  1781,  1780,     0,     0,     0,   135,  1234,
     369,   368,     0,     0,   365,   920,   467,     0,   533,     0,
       0,     0,   467,     0,     0,     0,   467,   801,  1209,     0,
       0,  1117,     0,  1770,     0,   102,     0,     0,   873,     0,
       0,     0,     0,   802,     0,     0,  1732,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   678,     0,     0,  1807,
    1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,
    1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,
    1838,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,   911,  1854,  1855,  1856,
    1857,  1858,  1859,  1860,  1861,  1862,  1863,  1864,  1865,  1866,
    1867,  1868,  1869,  1104,  1106,  1101,  1103,  1102,  1105,  1870,
    1871,  1232,  1872,  1237,  1236,  1873,  1874,  1875,  1876,  1877,
    1878,  1879,  1880,  1881,  1882,  1380,  1883,  1884,  1885,  1886,
    1887,  1888,  1889,  1890,  1806,   841,   542,   842,     0,   906,
       0,   904,     0,   326,   209,   210,     0,   275,   280,     0,
       0,     0,     0,   328,   331,     0,   213,     0,   942,   219,
       0,   185,     0,     0,     0,     0,     0,  1213,     0,     0,
    1201,     0,     0,  1245,   609,   610,   826,  1779,   602,   121,
       0,     0,  1745,  1744,  1015,  1741,  1743,  1794,     0,  1252,
       0,  1248,  1257,     7,     0,     6,     0,  1787,  1077,  1078,
       0,  1169,  1168,  1116,  1167,  1115,     0,     0,   422,   424,
       0,  1206,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1583,     0,     0,     0,   416,     0,     0,     0,
       0,   415,     0,     0,   432,     0,   503,     0,     0,     0,
       0,     0,     0,     0,   411,  1309,     0,   382,   381,   388,
     428,   425,   383,   501,   493,   384,   386,   500,   387,   932,
     423,   426,   431,  1297,   502,  1711,  1303,   123,     0,  1081,
     120,     0,   808,    23,   604,   380,     0,   807,  1074,   809,
       0,  1307,   895,   894,   897,   893,   896,  1796,     0,   891,
       0,   603,   988,   892,  1790,     0,  1778,   119,   985,   709,
     983,     0,   600,  1773,   755,   754,     0,   756,   592,   752,
       0,     0,   998,   605,  1377,     0,     0,  1050,  1048,     0,
    1042,  1044,  1043,  1041,  1040,     0,     0,     0,  1039,     0,
     782,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1029,  1020,  1021,     0,  1062,   409,    23,   855,
     401,  1784,     0,  1775,   124,   601,     0,  1047,  1046,  1210,
    1208,  1134,     0,  1700,  1701,  1135,  1223,  1135,  1118,  1119,
    1122,  1137,  1310,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,   932,     0,    67,     0,   100,   580,
     666,     0,  1107,  1005,  1111,     0,     0,  1063,  1227,     0,
       0,  1114,   670,   667,   668,     0,   672,   673,     0,   675,
     676,     0,   671,   965,   967,     0,     0,   966,   757,   963,
     718,   959,   924,     0,     0,     0,     0,   682,   683,     0,
       0,   922,   918,   919,   915,   916,   917,   910,   914,   913,
       0,     0,     0,     0,     0,     0,   546,   548,   540,   543,
     544,   908,  1805,   903,   905,   848,     0,   277,   279,   306,
     300,     0,     0,   309,     0,   224,     0,   222,   244,   236,
     228,   247,   962,   174,   958,   870,   174,     0,     0,     0,
    1285,  1286,     0,     0,     0,  1259,  1260,  1262,  1263,  1264,
    1268,  1267,  1265,  1266,     0,     0,  1742,     0,     0,  1017,
       0,     0,  1251,  1250,     0,  1244,     0,  1557,  1558,     0,
    1079,     0,    23,  1164,  1166,  1165,   390,   389,     0,     0,
    1141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,  1591,  1589,  1590,  1586,  1588,  1585,  1587,  1579,     0,
       0,     0,     0,     0,   429,     0,     0,   507,   506,     0,
       0,   477,   474,   483,     0,   480,     0,     0,   414,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,   164,   165,   166,
     167,   168,   508,   509,   510,   443,     0,     0,   442,   452,
       0,     0,   394,     0,     0,   395,   385,   391,   393,   396,
     397,   398,   399,   400,   392,   421,   420,   468,     0,     0,
     975,     0,     0,   349,    24,   343,     0,     0,  1071,     0,
       0,     0,     0,     0,     0,     0,   992,  1710,     0,     0,
     185,     0,     0,     0,  1775,     0,     0,     0,     0,     0,
     136,     0,     0,  1002,   994,   995,  1000,  1378,  1379,   921,
     333,   407,     0,   534,   585,   584,   582,  1023,   586,  1028,
    1024,  1027,   775,     0,  1025,  1026,   776,  1033,  1037,  1030,
    1031,  1035,  1036,  1034,  1032,  1038,     0,   810,     0,     0,
       0,   404,   405,   402,   403,     0,     0,     0,   765,   764,
     763,  1776,  1783,    23,  1130,  1131,  1132,  1133,  1127,  1125,
    1224,  1139,  1124,  1120,     0,     0,  1121,  1771,     0,     0,
       0,     0,    96,     0,    97,     0,     0,     0,    72,     0,
       0,     0,   109,   104,     0,   900,     0,   899,     0,   467,
    1109,     0,   950,   951,   974,   946,   947,   803,   972,  1065,
    1229,     0,  1231,  1230,  1736,     0,     0,     0,  1734,  1737,
    1738,   698,     0,     0,     0,   687,   718,   718,   716,     0,
       0,   719,     0,    25,   686,   689,     0,   696,   692,   923,
     912,  1707,  1708,  1698,  1698,     0,     0,  1617,     0,   185,
    1331,     0,     0,  1332,  1375,   185,     0,  1376,     0,  1656,
       0,  1345,     0,  1393,  1391,  1390,  1389,  1387,  1388,  1386,
    1384,  1381,  1454,  1453,  1382,  1383,  1392,  1626,  1385,  1714,
    1713,  1712,  1805,  1805,   559,   550,   541,     0,   545,  1805,
     907,   174,     0,   320,   212,     0,   185,   221,   204,  1214,
     174,  1202,  1445,     0,  1444,     0,     0,  1446,  1288,     0,
    1294,  1290,  1287,     0,     0,     0,     0,     0,     0,  1284,
    1280,  1434,  1433,  1432,  1256,  1255,     0,  1279,  1275,     0,
    1271,  1269,     0,   613,     0,   612,     0,     0,  1016,     0,
       0,  1014,  1748,  1750,  1749,  1746,  1795,  1792,  1249,     0,
       0,     0,  1242,   467,   341,     0,  1207,     0,     0,     0,
       0,  1656,     0,     0,     0,     0,     0,   525,   511,   516,
       0,   512,   515,   514,     0,     0,     0,     0,     0,     0,
     417,     0,   170,     0,   433,     0,     0,     0,     0,     0,
       0,     0,     0,   435,   434,   453,   444,   459,   462,   463,
     460,   466,   465,   464,   454,   455,   457,   456,   458,   445,
     449,   467,   461,   448,   467,    91,     0,   427,     0,  1239,
    1007,  1075,  1076,  1073,  1072,     0,   898,     0,     0,   589,
       0,     0,     0,   986,   984,     0,   711,   712,     0,     0,
    1774,  1782,     0,     0,   596,     0,   598,   753,     0,   140,
       0,   996,  1003,     0,     0,  1011,     0,   336,     0,     0,
       0,     0,    23,  1049,  1353,     0,     0,   800,   787,   798,
     799,   785,   786,   794,   789,   793,   788,   797,   792,   795,
     791,   796,   784,   790,   783,   782,  1022,   811,   410,     0,
    1054,     0,  1785,   766,   767,   360,     0,  1135,     0,  1138,
    1123,  1805,     0,     0,     0,     0,     0,     0,     0,    62,
      91,     0,     0,   115,   110,     0,   105,     0,   112,   106,
     884,   876,   882,     0,  1108,     0,  1110,  1112,     0,     0,
     954,     0,     0,     0,     0,  1064,  1228,  1751,  1739,   970,
    1740,   968,  1733,  1735,  1805,   669,   674,   677,   690,   688,
     606,     0,     0,     0,   734,   772,   732,   728,   726,   770,
       0,     0,   758,     0,   720,   730,   964,   960,     0,     0,
       0,     0,   695,     0,     0,     0,     0,     0,     0,     0,
    1560,     0,  1449,  1450,  1719,  1414,  1471,     0,     0,  1717,
       0,     0,  1658,  1659,  1657,     0,  1311,     0,  1397,  1403,
    1402,  1401,  1405,     0,  1398,  1399,     0,  1627,  1638,   547,
     549,     0,     0,   562,   554,   556,     0,   551,   552,     0,
       0,   570,   572,     0,     0,   568,   909,   849,   211,     0,
       0,   223,  1170,   871,  1148,  1422,  1424,     0,  1292,     0,
       0,     0,     0,     0,  1282,     0,     0,  1552,  1550,  1537,
    1539,  1535,     0,  1534,     0,  1543,  1530,  1551,     0,  1542,
    1527,  1533,  1549,  1541,  1438,  1524,  1525,  1526,     0,  1277,
    1273,     0,     0,  1261,   611,     0,   982,     0,     0,     0,
    1791,     4,     8,    10,  1556,  1559,     0,   467,   499,   496,
     495,   498,   494,     0,   419,   505,   490,   490,     0,   513,
       0,   517,     0,   281,  1206,     0,  1584,   497,  1206,   504,
     418,   265,     0,  1206,   478,   475,   484,  1206,   481,  1206,
    1206,  1206,     0,     0,     0,     0,     0,     0,     0,     0,
     469,    92,    93,    95,   471,     0,     0,     0,  1004,     0,
       0,     0,     0,     0,     0,     0,   185,   710,     0,   593,
     595,     0,     0,   157,   155,     0,     0,   137,     0,   147,
     153,   718,   142,   144,     0,  1001,  1012,  1013,     0,   408,
     335,   340,   591,   334,     0,   337,   342,  1354,   535,   583,
     581,   782,   777,   778,  1053,  1055,     0,   406,   361,  1128,
    1126,  1225,  1226,     0,     0,  1219,     0,     0,     0,    98,
       0,     0,    73,    79,    69,  1805,  1805,   108,   103,   117,
     113,     0,   107,   773,   885,   606,  1805,   875,   874,   883,
    1006,     0,     0,   952,   953,   948,   973,   467,     0,     0,
    1680,  1570,  1573,  1681,  1581,  1571,  1678,     0,     0,  1070,
    1677,     0,     0,  1679,     0,     0,     0,     0,     0,  1745,
    1572,  1066,  1067,  1676,  1578,  1668,  1069,  1666,  1667,     0,
       0,     0,   700,   693,   691,     0,    23,     0,   748,   722,
     750,   724,  1805,  1805,  1805,  1805,   782,   743,   742,   738,
     740,   747,   746,   736,   744,   717,   721,  1805,   606,    45,
      43,    40,    34,    38,    42,    37,    30,    39,    33,    36,
      31,    41,    32,    44,    35,     0,    28,     0,   697,  1699,
       0,  1697,  1656,  1695,  1643,  1644,  1636,  1622,  1637,     0,
       0,     0,  1045,  1448,  1451,     0,     0,     0,     0,  1472,
    1365,  1337,  1722,  1721,  1720,     0,     0,  1639,  1660,  1662,
       0,  1360,     0,  1359,     0,  1361,  1356,  1357,  1358,  1349,
    1346,     0,     0,  1404,     0,     0,     0,  1631,  1628,  1629,
     561,   566,     0,     0,  1805,  1805,   539,   553,   576,   564,
     578,  1805,  1805,   574,   558,   569,   840,   321,   205,     0,
    1196,  1215,   840,     0,  1203,  1196,     0,     0,  1289,     0,
       0,     0,     0,     0,  1477,  1479,  1481,  1519,  1518,  1517,
    1483,  1500,  1291,     0,  1561,     0,  1423,     0,  1426,  1564,
       0,  1430,     0,  1281,     0,     0,  1607,  1605,  1606,  1602,
    1604,  1601,  1603,     0,     0,     0,     0,     0,     0,     0,
       0,  1436,     0,  1439,  1440,     0,  1276,     0,  1270,  1272,
    1747,     0,     0,  1793,     0,     0,  1253,   856,     0,     0,
     487,     0,   488,     0,   527,     0,   524,   521,   492,   486,
    1144,  1592,  1143,     0,   169,  1142,     0,     0,     0,  1145,
       0,  1147,  1146,  1140,   446,   447,   451,   436,     0,   439,
     450,     0,   438,     0,     0,    91,     0,     0,     0,     0,
    1304,  1798,  1797,   590,     0,     0,    46,     0,   715,   714,
     713,  1305,     0,     0,   718,  1805,  1805,   149,   614,   159,
     151,   161,   141,   148,  1805,     0,     0,     0,     0,     0,
       0,     0,  1805,     0,   780,   606,     0,  1772,     0,    91,
       0,    63,     0,     0,     0,    76,     0,    91,    91,   116,
     111,  1805,  1805,   101,   782,   886,   880,   888,   887,   877,
     531,   935,     0,     0,  1575,  1574,  1577,  1576,  1580,     0,
    1656,     0,     0,  1520,     0,  1520,  1520,  1520,  1520,  1669,
       0,     0,     0,     0,     0,     0,  1723,  1724,  1725,  1726,
    1727,  1728,  1672,  1752,   971,   969,   703,   701,     0,   680,
     694,   607,   759,     0,     0,  1805,     0,  1805,   735,   733,
     729,   727,   771,     0,  1805,     0,  1805,   731,    23,     0,
      26,     0,  1702,     0,  1626,     0,     0,  1635,  1618,  1634,
    1452,     0,  1416,     0,  1364,  1459,     0,     0,  1718,     0,
    1715,     0,  1652,   644,   629,   642,   648,   663,   628,   640,
     623,   656,   659,   662,   626,   657,   635,   639,   650,   661,
     658,   660,   651,   633,   631,   655,   637,   636,   624,   625,
     627,   630,   641,   653,   632,   665,   643,   647,   649,   664,
     638,   652,   654,   634,   645,   646,  1664,  1663,     0,  1363,
    1362,  1350,  1348,     0,  1407,     0,  1400,     0,     0,     0,
       0,   563,   560,   555,   557,     0,  1805,  1805,   571,   573,
    1805,  1805,     0,     0,  1194,  1195,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1193,     0,     0,
    1181,  1182,  1183,  1180,  1185,  1186,  1187,  1184,  1171,  1162,
       0,     0,  1218,     0,  1805,     0,  1157,     0,     0,     0,
       0,     0,     0,     0,  1149,  1150,     0,  1082,     0,  1293,
       0,  1486,     0,  1500,  1485,  1482,     0,  1447,     0,  1514,
    1511,  1512,  1509,  1516,  1515,  1510,  1513,  1693,     0,  1693,
    1501,     0,     0,     0,  1565,     0,  1566,     0,     0,     0,
       0,  1429,  1283,  1428,  1420,     0,     0,     0,  1554,  1546,
    1546,     0,     0,  1546,  1553,     0,  1570,  1435,  1437,  1441,
    1442,  1278,  1274,  1019,     0,     9,     0,  1246,   857,  1080,
       0,  1471,  1646,     0,   490,   518,     0,   274,   479,   476,
     485,   482,     0,   441,   440,   470,    94,   472,   347,  1240,
       0,     0,  1789,     0,     0,   987,    47,     0,   597,   599,
     594,   768,   158,   156,     0,  1805,     0,     0,     0,  1805,
     154,   143,     0,   146,   145,     0,   993,   997,   339,     0,
    1355,     0,   782,   779,    23,  1129,     0,  1220,    68,     0,
       0,    99,    66,    91,    74,    80,     0,   118,   114,   774,
    1805,   890,   606,   889,     0,   528,     0,   805,   806,   804,
       0,     0,  1689,     0,     0,     0,  1522,  1523,  1521,     0,
    1691,     0,     0,     0,     0,     0,     0,     0,  1068,  1674,
    1675,  1671,  1673,     0,  1805,   699,   684,   681,     0,   749,
     723,   751,   725,   741,   739,   745,   737,   760,    29,    27,
       0,  1696,  1652,  1623,  1624,  1620,  1626,     0,  1415,  1656,
    1418,     0,  1339,  1334,  1333,  1336,     0,  1661,     0,  1640,
       0,     0,  1312,  1318,     0,  1321,  1323,  1351,  1347,     0,
    1406,     0,     0,  1632,  1630,   567,   565,   577,   579,   575,
       0,     0,   228,  1188,  1189,  1190,  1192,  1175,  1173,  1172,
    1176,  1177,  1174,  1191,  1178,  1179,  1163,   979,  1198,   976,
       0,     0,  1216,     0,  1161,  1160,  1155,  1153,  1152,  1156,
    1154,  1158,  1159,  1151,  1204,  1425,  1484,  1478,  1480,  1490,
    1487,  1694,  1489,     0,  1495,  1487,     0,  1493,  1693,  1503,
    1502,     0,  1504,     0,  1421,  1427,  1568,  1561,  1431,  1614,
    1612,  1613,  1609,  1611,  1608,  1610,  1536,     0,  1538,     0,
       0,     0,     0,  1544,  1548,     0,  1528,  1443,  1018,  1254,
    1247,  1243,     0,  1460,  1461,  1463,  1466,  1473,     0,     0,
    1520,  1648,  1642,  1599,  1597,  1598,  1594,  1596,  1593,  1595,
     491,   489,     0,   523,   522,   171,   437,     0,     0,    23,
       0,     0,  1010,     0,    48,   990,     0,    23,   160,   150,
       0,   616,   618,   162,   152,   768,     0,   338,   536,   781,
    1051,     0,     0,    64,     0,    77,    86,     0,    70,   881,
     878,   532,  1805,   949,  1582,     0,     0,     0,     0,  1690,
       0,     0,  1688,     0,     0,     0,     0,  1670,  1687,     0,
     702,   679,   685,   606,  1706,     0,  1704,     0,  1626,  1626,
    1619,  1417,     0,  1419,  1413,     0,  1338,     0,  1716,  1653,
       0,     0,  1325,     0,  1314,     0,     0,     0,  1408,  1411,
    1395,  1409,  1412,     0,   851,   850,   322,   206,   981,   980,
     978,     0,  1197,  1083,  1087,  1089,     0,  1093,     0,  1091,
    1095,  1084,  1085,     0,   872,     0,  1693,  1507,     0,  1496,
    1499,  1498,  1506,     0,  1487,     0,     0,  1562,  1567,     0,
    1555,  1547,  1531,  1529,     0,  1532,     0,  1464,     0,  1569,
    1467,     0,  1474,  1475,  1651,  1246,     0,     0,     0,     0,
     520,   519,   473,   348,   345,     0,  1008,     0,     0,     0,
     989,   769,   138,   615,    23,   999,  1056,    65,  1221,    82,
       0,     0,    75,    86,    86,  1805,   529,     0,     0,     0,
       0,  1686,  1692,  1682,  1683,  1684,  1685,   704,   761,     0,
    1703,  1646,  1625,  1621,     0,  1340,     0,  1646,     0,  1329,
    1320,  1327,  1330,     0,     0,     0,     0,  1313,  1322,  1324,
    1352,     0,  1396,  1394,  1633,   977,  1805,  1805,  1097,  1805,
    1099,  1805,  1805,  1086,  1217,  1205,  1488,  1491,     0,  1494,
    1492,  1508,     0,     0,     0,  1545,  1468,     0,  1462,  1456,
    1457,  1665,     0,  1476,  1470,  1649,  1370,  1366,  1367,  1372,
    1371,  1647,  1246,     0,   350,  1009,  1788,     0,     0,     0,
       0,     0,     0,    53,     0,    52,     0,    50,     0,     0,
     139,  1060,  1052,     0,  1058,    86,    91,    86,    87,    81,
      71,   879,     0,  1655,     0,  1731,     0,  1805,    23,  1705,
    1645,  1654,  1344,     0,  1341,  1343,  1641,     0,  1330,     0,
    1326,     0,  1315,  1316,  1410,  1088,  1090,  1805,  1094,  1805,
    1092,  1096,  1497,  1505,  1563,  1540,     0,  1465,     0,  1455,
       0,  1374,  1373,  1369,  1650,  1600,   356,   354,   346,     0,
     352,   358,    55,    60,    57,    59,    56,    58,    54,     0,
      49,     0,   617,   619,  1805,  1057,  1059,  1222,    83,    78,
     530,  1729,  1730,   700,   762,     0,  1335,  1319,  1328,     0,
    1098,  1100,  1469,  1458,  1368,  1805,  1805,   351,   353,  1805,
      51,     0,  1061,     0,   705,  1342,     0,   357,   355,   359,
       0,    84,  1317,   991,    88,    90,     0,    85,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,   549,   550,   551,   552,   704,  1721,  1722,   188,   263,
     189,  1123,  1124,  1609,  1945,  2975,  2475,  2476,  2868,  2976,
    2977,   553,   892,  2509,  2178,  2884,  1550,  2176,  2746,  2513,
    2880,  2177,  2747,  2986,  3083,  3094,  2882,  3097,  1770,  1771,
    1772,  1223,  1838,   554,  1234,   897,  1232,  1558,  1848,  1555,
    1846,  1851,  2182,  1233,  1845,  1559,  2181,   555,    16,    35,
      36,    37,    38,    39,   113,   558,   821,  1489,  1150,  1797,
    1801,  1802,  1798,  1799,  2485,  2489,  2154,  2146,  2145,  2147,
    2150,  1105,  1057,  1752,   559,    82,    83,    18,    61,   141,
      95,   254,    97,    98,   199,   277,    99,   100,   241,   227,
     674,  2343,   304,   656,  1669,   331,   332,   228,   286,   279,
     281,   976,   977,   145,   354,   146,   147,   292,   229,   230,
    1475,   392,   242,   245,   243,   244,   313,   369,   370,   372,
     377,   659,   246,   247,   322,   374,   195,    19,    79,   177,
     178,   179,   665,  2342,   180,   250,   239,   325,   326,   327,
     328,  1502,   560,   561,   562,   563,   778,  2964,  2719,  1125,
    3038,  3039,  3040,  3076,  3075,  3079,   564,   565,   566,   567,
     754,  1106,   859,  1192,  1193,  1160,   856,  1161,   756,   757,
     758,   759,   760,   761,   762,  1060,  1107,  2118,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,   710,   763,  1455,  2123,  2125,
    2717,   764,  1426,  2107,  1425,  2106,  1429,  2110,  1427,  2108,
    2090,  2099,   765,   766,   767,   768,  1410,  1411,  1412,  1413,
     568,  2752,  2992,  2525,   569,   829,  1504,  2162,   114,   236,
     364,  1325,   958,   959,   960,  1322,  1323,  1656,  1657,  1658,
    2004,  2005,  1326,  1327,  1652,  2008,  2000,  1664,  1665,  2011,
    2012,  2340,  2336,  2337,   570,  1167,    84,  1470,  1471,  1813,
     861,   811,   864,   687,   800,   783,   822,  1906,    85,   688,
     684,  1374,  2149,    86,   770,  2316,   571,   572,   913,   914,
     573,   574,   575,   576,   921,  2556,   942,  2771,   943,  1588,
     944,  1903,   945,  2229,   946,  1612,   577,  1584,  2228,  2554,
    2553,  2997,   115,    20,   578,  1141,  1476,  1477,  1602,  1272,
    1603,  1604,  2235,  2237,  1915,  1914,  1927,  1913,  1912,  2246,
    2244,  1919,  1920,  1923,  1924,  1909,  1911,   579,   580,   819,
     581,  1268,   928,  2998,   582,  1200,  2727,  1605,  1916,  1854,
    2184,   852,  1177,  1525,  1822,  2163,  1823,  1173,  1524,   583,
     584,   906,  1573,  2529,   585,   586,   587,   588,    21,    65,
      22,    23,    24,   116,   117,   589,   118,    25,   646,    26,
     119,   120,   157,   366,  1331,  2016,  2805,   121,   153,   297,
     590,  2088,    27,    28,    29,    30,    31,    60,    87,   122,
     411,  1340,  2022,   591,   901,  1858,  1562,  1856,  2885,  2520,
    1563,  1855,  2187,  2522,   592,   593,   594,   794,   795,  1236,
     123,   237,   365,   650,   651,   962,  1329,   595,   947,   948,
     596,   825,  1280,   949,   771,    89,    90,    91,    92,  1243,
     183,   137,    93,   134,   191,   192,  1244,  1245,  1865,  1246,
     408,   409,   930,   410,   931,  1580,  1581,  1247,  1248,  1121,
    2628,  2629,  2810,   693,   809,   810,   597,  1136,  2870,   598,
    2497,   599,  1154,  1155,  1156,  1495,  1493,   600,   601,  1778,
    1808,   602,  1009,  1381,   603,   853,   854,   604,   869,   605,
    1956,   606,  2876,   607,  1826,  2982,  2983,  2984,  3054,   858,
     608,  1249,  1575,  1891,  1892,   609,  1463,   709,  1021,   610,
     611,  2024,  2632,  2821,  2822,  2926,  2927,  2931,  2929,  2932,
    3017,  3019,   612,   613,  1238,  1567,   614,  1240,   877,   878,
     879,  1216,   615,   616,   617,  1537,  1208,   872,   198,   880,
     881,   772,  2025,  2384,  2385,  2368,   713,   714,  2020,  2369,
    2372,   124,   152,   358,   986,  1674,  2386,  2825,  1030,   618,
     870,   125,   149,   355,   983,  1672,  2373,  2823,  2021,   896,
    2169,  2742,  2985,  1211,   619,   620,   621,   622,   623,   781,
    1776,   706,  1726,   624,  2691,   700,   701,  2085,  1359,   625,
     626,   995,   996,   997,  1371,  1711,   998,  1708,  1368,   999,
    1683,  1360,  1000,  1001,  1002,  1003,  1677,  1351,   627,   790,
     773,   628,  1303,  1980,  2794,  2917,  2592,  2593,  2594,  2595,
    2793,  2910,  2911,  1304,  1305,  1627,  2584,  2787,  2267,  2581,
    3003,  3004,  1306,  1637,  2321,  1990,  2598,  2797,  1818,  2161,
    1991,  1307,  1308,  2701,  2957,  2958,  2959,  3033,  1309,  1310,
    1158,   629,   630,   955,  1311,  1312,  2923,  1643,  1644,  1645,
    1993,  2323,  2800,  2801,  1313,  1966,  2261,  2784,  1361,  1362,
    1347,  2045,  1675,  2046,  1363,  2050,  1364,  2073,  1365,  2074,
    2438,  2439,  1678,  1314,  1621,  1622,  1963,  1315,  2953,  2852,
    2949,  1969,  2451,  2693,  2694,  2695,  2947,  2452,  1970,  2853,
    2954,  2033,  2034,  2035,  2036,  2037,  2827,  2650,  2936,  2038,
    2828,  2829,  2412,  2039,  2413,  2040,  2539,  1704,  1705,  1706,
    2680,  1707,  2435,  2429,  2841,  2047,  2802,  2416,  2596,  2049,
    2850,  1893,   774,  1894,  2198,  1048,  2091,  2710,  2063,  2676,
      59,   631,   632,  2576,  2779,  2254,  2778,  1648,  1998,  1999,
    2258,  1957,  1316,  1958,  2272,  2790,  1402,  1953,  1954,  2702,
    2855,  2589,  2580,  1895,  1635,  1977,  1978,  2950,  2041,  1897,
    2541,  2652,   633,   634,  1614,  1955,  2571,  2775,  2776,  1283,
     635,   776,  1318,  1319,  1630,  2269,  1320,  1321,  1974,  2222,
    2535,   636,   909,  1257,  1258,  1259,  1260,   694,  1577,   696,
    1385,  1898,    63,    48,    77,    74,   638,   883,  1541,  1144,
    1202,   639,   862,   640,  2136,   641,  1720,   698,  1387,   642,
     643,    42,   359,   360,   361,   362,   363,   644
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -2579
static const short yypact[] =
{
    3919,   385,   276,   667,   667,   667,   667,   667,   667,   667,
   -2579,   667,   276,   886, -2579, -2579, -2579,  1518, -2579, -2579,
   -2579,   345, -2579,  3919, -2579, -2579, -2579, -2579, -2579,  1330,
   -2579, -2579, -2579, -2579, -2579,   319,   335, -2579,   403, -2579,
   -2579, -2579, -2579, -2579,   276,    88, -2579,  -168, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1032,   111, -2579, -2579, -2579,   361, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,   276, -2579, -2579,    88,    26,
   -2579,   276,   700,  1518, -2579,   684, -2579, -2579, -2579, -2579,
     901,  -109, -2579, -2579, -2579,   937,   613,   276, -2579, -2579,
     970,   276, -2579, -2579,   276,   276, -2579, -2579, -2579, -2579,
     276,   276, -2579, -2579, -2579, -2579, -2579,   361, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  6564,
    -109, -2579,   793,   270, -2579, -2579,   549, -2579, -2579,  1003,
     111,   551, -2579, -2579, -2579, -2579, -2579,  3473, -2579,   276,
     611,   933,   276,  1518, -2579, -2579, -2579,   276, -2579, -2579,
     517,   981, -2579, -2579,   650, -2579,   729, -2579,   668, -2579,
   -2579,   762, -2579,   788, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,   821, -2579, -2579, -2579,   270,  1682,  1221,
   -2579,   170, -2579,   270, -2579,   255, -2579, -2579, -2579,   136,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   517, -2579,
     981, -2579, -2579,   865, -2579,   874, -2579,   862, -2579, -2579,
     921, -2579,   926, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   932,  1333,   276,   986, -2579,  1518,  1518,   995,   276,
   -2579,   -44, -2579,   806,  1034, -2579,   810,  1161,  1429,  1436,
     276,  1444,  1461,  1462, -2579,   894, -2579,   964, -2579, -2579,
   -2579, -2579, -2579,   270, -2579,   270,  1066,   219, -2579, -2579,
   -2579,  1487, -2579, -2579,  1500, -2579, -2579, -2579, -2579, -2579,
     -44, -2579, -2579, -2579,  1512,  1514,   111,  1444,  1517,  1522,
     952, -2579,  1515, -2579,  1186,  1151, -2579,  1223, -2579, -2579,
   -2579,   965, -2579, -2579,  1537, -2579,  1158, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  1161,  1158, -2579, -2579, -2579, -2579,
   -2579, -2579,  1165,   271,   289,   673, -2579,  1908, -2579, -2579,
   -2579,  1170,  1566,   311,  1208, -2579, -2579,  1682, -2579,   270,
   -2579, -2579, -2579,   982,  1560,  1349,   338,   383,   775,  1187,
     387,  1224, -2579, -2579, -2579,   276, -2579, -2579,   276,  1251,
   -2579,  3837,   551,  4914,  2006,  -201,   276,  1579,   -14, -2579,
    1034,  1575, -2579, -2579, -2579, -2579,  1576, -2579,  1577, -2579,
    1582, -2579,   276, -2579,   276, -2579, -2579,  1444,  1585, -2579,
   -2579, -2579, -2579,   222,  1584,   -14,  1205,  1592, -2579,  1593,
   -2579, -2579, -2579,  1594, -2579, -2579, -2579,  1026,  1261,  1629,
   -2579,   276,  1266, -2579, -2579, -2579,   276,   332,   276,   332,
     332,   881,   276, -2579,   276, -2579, -2579,   276, -2579,   985,
   -2579, -2579, -2579,   332, -2579, -2579, -2579, -2579,   276, -2579,
   -2579, -2579, -2579,    97,    97,  7321, -2579, -2579, -2579, -2579,
   -2579,   332, -2579, -2579,   332, -2579, -2579,   276, -2579, -2579,
     332, -2579, -2579,   808,   332, -2579, -2579,  7321,   332,   808,
     276,   808,   332, -2579, -2579,   119,   332,   332,   119,   332,
     276,   119,   332, -2579,   332,   332,   332, -2579, -2579, -2579,
   -2579,   808,   332, -2579, -2579,   332,    70,   276, -2579, -2579,
   -2579, -2579,   332,   881, -2579, -2579, -2579,   332, -2579,  5841,
     808,  7321, -2579,    72,    72,   332, -2579, -2579,   947,   808,
     974,  7321,  7321, -2579,   522,  7321,   332,    88, -2579,  7321,
     332,  7321,   808, -2579,   332,  7321, -2579,  7321,    97,   276,
     332,   276,    72,   332,   276,    72, -2579,   276,   288, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,   163, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,   864, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,   744, -2579,   276, -2579,
     716, -2579,  1268, -2579, -2579, -2579,  1358, -2579, -2579,  1271,
    1272,  1277,  1278, -2579, -2579,  1046,  1647,  1284, -2579, -2579,
    1380, -2579,  1294,  1303,  1070,  1310,   276, -2579,   276,  1311,
   -2579,   369,  1280, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1091,  1322,  1257, -2579,  1107, -2579,  1096, -2579,  1699,  -172,
     396, -2579, -2579, -2579,  1302, -2579,  1375, -2579, -2579,  1252,
     228, -2579, -2579, -2579,  1304, -2579,  7321,  7321, -2579, -2579,
    1306,  1206,  1309,  1325,  1326,  1327,  1335,  1336,  1338,  1339,
    1340,  7321,  1458,  1341,  1347,  1350, -2579,  7321,  7321,  1352,
    1354, -2579,  7321,  1355, -2579,  1357,  1359,  1363,  1367,  1377,
    1381,  1382,  7321,  1386,  6391, -2579,   140, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1083,
   -2579,  1314, -2579, -2579, -2579, -2579, -2579, -2579,   808, -2579,
   -2579,  1375, -2579,   346, -2579, -2579,  1475, -2579,   155, -2579,
    1329, -2579, -2579, -2579, -2579,  1780, -2579, -2579,   354, -2579,
    1198, -2579,  1204,  1780, -2579,  1238, -2579, -2579,  1415,   144,
   -2579,  1379, -2579,  1176, -2579, -2579,  1419, -2579,   435, -2579,
    1196,   489,  -220, -2579,  1532,  7321,  7321, -2579,  1832,   332,
   -2579, -2579, -2579, -2579, -2579,   181,   181,   181, -2579,   181,
   -2579,   181,   181,  1264,   346,  1264,  1264,   993,   993,  1264,
    1264,   346, -2579,  1837, -2579,    58,  1843, -2579,   346, -2579,
    6730, -2579,   116,    87, -2579, -2579,  7321, -2579, -2579, -2579,
   -2579, -2579,   895, -2579, -2579,   551,  1486,   551,  7321, -2579,
     102, -2579, -2579,  7321,  1440,  1441,  1442,  1445,  1392,  1446,
     974,  1359, -2579,  1533,  1113,  1290, -2579,  1305, -2579, -2579,
   -2579,  1149, -2579,  1853, -2579,  1849,   276, -2579,    49,   134,
    1307, -2579, -2579,  1862, -2579,  1231,  1862,  1864,  1237,  1862,
    1864,  7321,  1862, -2579, -2579,   228,   808, -2579, -2579,  1472,
     961, -2579, -2579,  1468,   808,  7321,  1482, -2579, -2579,  1868,
    1869,  1850, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1173,  1173,   332,   332,   332,  1123, -2579, -2579,  1828,   744,
   -2579, -2579,   733, -2579, -2579, -2579,  1463, -2579, -2579, -2579,
   -2579,  6564,  1444, -2579,  1464, -2579,   410, -2579, -2579, -2579,
   -2579, -2579, -2579,  1518, -2579, -2579,  1518,   738,   184,  1882,
   -2579, -2579,   587,   223,   647,  1912, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  1413,  1322,  1096,   270,   881,  -233,
    1136,   276, -2579, -2579,   276, -2579,  1348,  1324,  1356,  1520,
   -2579,  1523,   114, -2579, -2579, -2579,  1666,  1666,    72,  7321,
   -2579,    72,    72,    72,    72,  1477,  7321,   980,  1256,  7321,
    6391,  1526, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1343,
      72,  1917,  7321,  4302,  6391,  1477,  7321, -2579,  6391,  1932,
     106, -2579, -2579, -2579,  7321, -2579,  7321,  7321,  6391,  7321,
    7321,  7321,  7321,  7321,  7321,  7321,  7321,  7321,  7321,  7321,
    7321,  7321,  7321,  7321,  7321,  7321, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  7321,  7321, -2579, -2579,
    1543,  7321, -2579,  7321,  1544, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   276,   808,
   -2579,  1351,  1545, -2579, -2579, -2579,   881,  1180, -2579,  1180,
     974,   119,  7321,  7321,  7321,  1546, -2579, -2579,   808,   808,
   -2579,  1353,   974,    72,  1316,   276,   270,    90,    70,   808,
   -2579,  1361,  7321,  1632, -2579, -2579,  1427, -2579, -2579,  1843,
      92, -2579,   228, -2579, -2579,  1948,  1950, -2579, -2579, -2579,
   -2579, -2579, -2579,  1834, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  5841, -2579,   993,  7321,
     -58, -2579, -2579,  1964, -2579,    72,  1945,  1947, -2579, -2579,
   -2579, -2579, -2579,   121, -2579, -2579, -2579, -2579,  1844, -2579,
    1777, -2579, -2579, -2579,  7321,    97, -2579, -2579,   276,  1954,
      72,    72, -2579,  1409, -2579,    72,  1383,   808, -2579,   276,
     276,  7321,   480, -2579,  1422, -2579,   263, -2579,  1521, -2579,
    1538,  7321,   715, -2579, -2579,  1387, -2579,  1979, -2579,  1479,
   -2579,   808, -2579, -2579, -2579,   881,   808,   130, -2579, -2579,
   -2579, -2579,   276,    72,    72,   452,   961,  1877,   229,   808,
     228, -2579,  1481, -2579, -2579,  1994,  1984,  1635, -2579, -2579,
   -2579, -2579, -2579,  1714,  1714,   415,  1491, -2579,   276, -2579,
   -2579,  1375,  1375, -2579, -2579, -2579,   276, -2579,   276,   567,
    1375, -2579,   707, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   997, -2579, -2579,
   -2579, -2579,   165,   165,   783,   759, -2579,   840, -2579,   733,
   -2579,  1518,  1991, -2579, -2579,  1991, -2579, -2579, -2579, -2579,
    1518, -2579, -2579,  1375, -2579,   766,  1609, -2579, -2579,   766,
   -2579, -2579, -2579,  1611,  1612,   334,  1615,  1616,  1319, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,   276, -2579, -2579,   334,
    1389, -2579,   369, -2579,  1660,  -109,  1426,   225, -2579,   974,
    1480, -2579, -2579,  1257, -2579, -2579, -2579,  1511, -2579,   276,
     276,   276, -2579, -2579, -2579,  1668,  6391,  1671,  1672,  1673,
     421,   567,  1674,  4799,  1677,   -80,  1279, -2579, -2579,   162,
    1678, -2579, -2579, -2579,  5301,  2028,  1458,  1680,  1683,  5555,
   -2579,  1684,  2609,  1686, -2579,  7321,  7321,  7321,  5585,  7321,
    5671,  5705,  5791,  6416,  6537,  6504,  3388,  4700,  6640,  2364,
    6820,  3535,  1094,  4329,  1666,  1666,  2819,  3062,  3159,  5840,
    6161,  1477,  6391,  6271,  1477,  7321,  1649, -2579,   276, -2579,
    1473, -2579, -2579, -2579, -2579,  1453, -2579,  2067,  2072, -2579,
    2074,  1524,  7321, -2579, -2579,  1485,  2075, -2579,  1618,  1476,
    1864, -2579,  1716,   431, -2579,  1681, -2579, -2579,  1488,   813,
     276, -2579, -2579,  1685,   332,   811,  7321, -2579,   276,   276,
    7321,    65,   346,  2087,  1562,  2073,  2078, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  1689, -2579, -2579, -2579,   808,
    1588,  6730, -2579, -2579, -2579,  2054,  7321,   551,  1071, -2579,
   -2579,  1805,  2108,  2109,  1744,   427,   276,  1746,   974, -2579,
    7321,  1709,  1717, -2579, -2579,  1788, -2579,  7321,   541, -2579,
    1552, -2579, -2579,   279, -2579,  7321, -2579, -2579,  1529,   793,
   -2579,  1160,   276,  2118,  7461, -2579, -2579,  1738, -2579,  1739,
    2141, -2579, -2579, -2579,   124, -2579,  1864,  1864,  1519, -2579,
    1623,  1631,    72,    72, -2579, -2579, -2579, -2579, -2579, -2579,
     -48,    -8, -2579,   643, -2579, -2579, -2579, -2579,    72,  3711,
    2151,  2136, -2579,   974,   248,   202,   188,  2082,    35,   947,
   -2579,   107, -2579, -2579, -2579,  1755,   131,  1375,   178, -2579,
    1565,  1556, -2579, -2579, -2579,  7832, -2579,   297, -2579, -2579,
   -2579, -2579,  1758,  1567,  2169, -2579,  1489, -2579, -2579, -2579,
   -2579,   808,   196, -2579, -2579, -2579,  1557,   759, -2579,   276,
     276, -2579, -2579,   276,   625, -2579, -2579, -2579, -2579,  1772,
    1773, -2579,  1748, -2579,  1752, -2579,  1783,   437, -2579,  7158,
     440,   113,   113,   451, -2579,   113,  7158, -2579, -2579,  1656,
    1656, -2579,  1791, -2579,  1794,  1795, -2579,  1797,  1804, -2579,
    1807, -2579, -2579, -2579,   216, -2579, -2579, -2579,   456, -2579,
   -2579,   457,   276, -2579, -2579,  1136, -2579,  2207,   974,  7321,
   -2579,  2216, -2579, -2579, -2579, -2579,   334, -2579, -2579, -2579,
   -2579, -2579, -2579,  7832, -2579, -2579,  1458,  1458,  2197, -2579,
    2198,  1655,  1501, -2579,  1206,  1855, -2579, -2579,  1206, -2579,
   -2579, -2579,  1858,  1206,  6391,  6391,  6391,  1206,  6391,  1206,
    1206,  1206,  2209,  2219,  2220,  7321,  1875,  2223,  7321,  1885,
   -2579,  2243, -2579,  6391, -2579,  1652,   334,   122, -2579,   974,
    7321,  7321,  7321,  6957,  2254,   109, -2579, -2579,   974, -2579,
    1662,   276,   276, -2579, -2579,   276,   276, -2579,  1042, -2579,
   -2579,   996, -2579,  1664,  7321, -2579, -2579, -2579,  2258, -2579,
   -2579, -2579, -2579, -2579,   276,  1864, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,   808, -2579, -2579,  3307,
   -2579, -2579, -2579,  1963,  2247, -2579,  1949,  1951,  1836,  1676,
    1956,  1871, -2579, -2579, -2579,   590,  1938, -2579, -2579, -2579,
   -2579,  1788, -2579, -2579, -2579,   176,   785, -2579, -2579, -2579,
    1994,  7321,  1867, -2579,  1845, -2579, -2579, -2579,   148,   169,
   -2579,  1091, -2579, -2579,  1656, -2579, -2579,  7491,  1872, -2579,
   -2579,  1874,  1876, -2579,  1880,  1881,  1884,  1887,   276,   -60,
   -2579,  2282, -2579, -2579, -2579, -2579,  2928, -2579, -2579,   881,
     808,   808,   127,  1669, -2579,  2273,   346,   276, -2579,  2300,
   -2579,  2301,  1099,  1099,  1099,  1099,  1689, -2579, -2579,  2302,
   -2579, -2579, -2579,  2305, -2579, -2579, -2579,  1099,   118, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,   464, -2579,  2287, -2579, -2579,
    1375, -2579,   567, -2579, -2579, -2579, -2579, -2579, -2579,  1737,
    1754,   242, -2579,   107, -2579,   113,  1726,   332,  7158, -2579,
   -2579,  1904, -2579, -2579, -2579,   276,   276,  2310, -2579,  4168,
    1764, -2579,  7321, -2579,  7321, -2579, -2579, -2579, -2579, -2579,
   -2579,   332,   113, -2579,  1375,   815,  1728,  1730,  2327, -2579,
    2330, -2579,   808,   276,   857,   857, -2579, -2579,  2331, -2579,
    2331,   731,   731,  2331, -2579, -2579,  2006, -2579, -2579,  1452,
     183, -2579,  2006,  1265, -2579,   183,   113,   766, -2579,  1928,
    5563,  1928,  7431,   237,  2332, -2579, -2579, -2579, -2579, -2579,
   -2579,  1808, -2579,  1375,   423,  1969,  2336,  1741, -2579, -2579,
     475, -2579,   334, -2579,   476,   329, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,  1736,   -26,  2319,  2319,  2321,  2319,  2319,
    2322, -2579,   215, -2579,   766,   276, -2579,   334, -2579, -2579,
    1747,   974,  2344, -2579,   276,   478, -2579,  7321,  1982,   199,
   -2579,  1749, -2579,  1986, -2579,  2334, -2579,  1790, -2579, -2579,
   -2579, -2579, -2579,  1756, -2579, -2579,  1990,  1993,  1995, -2579,
    1996, -2579, -2579, -2579, -2579, -2579, -2579,  6391,   481, -2579,
   -2579,   491, -2579,  1997,  7321,  7321,  2349,   492,   974,  2366,
   -2579, -2579, -2579, -2579,  7321,  1825,  2119,  7321, -2579, -2579,
   -2579, -2579,  1168,  2003,   996,  1053,  1053,  2381,   445, -2579,
    2383, -2579, -2579, -2579,  1053,   276,  1865,  1181,  2384,   276,
     -37,   808,  2173,   494, -2579,  1623,  7321, -2579,  2390,  7321,
     808, -2579,   985,   276,   808, -2579,  2027,  7321,  7321, -2579,
   -2579,   590,  1938, -2579,  1689, -2579, -2579,  1228, -2579, -2579,
    1847, -2579,   270,  7067, -2579, -2579, -2579, -2579, -2579,  1796,
     567,  1870,   110,   705,  7832,   705,   705,   705,   705,  1800,
    7832,  7461,  7832,  7832,  7832,  7832, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1988,   852,
   -2579, -2579, -2579,  1801,    72,  1099,    72,  1099, -2579, -2579,
   -2579, -2579, -2579,   -48,  1099,    -8,  1099, -2579,   346,  3711,
   -2579,  2039,  2004,  7832,   997,   188,   188, -2579, -2579, -2579,
   -2579,   495, -2579,  1962, -2579,  2409,   113,   569, -2579,  1812,
   -2579,  7832,  1888, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   191, -2579,
   -2579,  1889, -2579,   508, -2579,  1813, -2579,   276,   276,  1489,
     808, -2579,  2331, -2579, -2579,   276,   731,   731, -2579, -2579,
     731,  2235,  1822,  1823, -2579, -2579,    97,    97,    97,  2405,
      97,    97,    97,    97,    97,    97,  2406, -2579,  2407,    97,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1452, -2579,
     808,  1833, -2579,  2008,  2235,  2408, -2579,  2411,  2421,  2422,
    2424,  2425,  2426,  1232,  1265, -2579,  2008, -2579,   511, -2579,
    2005, -2579,   368,  1296, -2579, -2579,  7158, -2579,  7158, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   195,  2047,   195,
   -2579,  2048,   589,  7832, -2579,  2436, -2579,  2186,   113,  1183,
     113, -2579, -2579, -2579, -2579,  1657,  2439,  1657, -2579,  2460,
    2460,   516,  2098,  2460, -2579,  2099, -2579, -2579, -2579,   766,
   -2579, -2579, -2579, -2579,   974, -2579,   334,  2224,  1994, -2579,
     258,  1965,   502,  1687,  1458,  1903,  1510, -2579, -2579, -2579,
   -2579, -2579,  7321, -2579, -2579, -2579, -2579, -2579,  2029, -2579,
     264,   974, -2579,  2469,  2065, -2579, -2579,  2107, -2579, -2579,
   -2579,  1952, -2579, -2579,   276,  1053,   270,  1191,   276,  1053,
   -2579, -2579,    72, -2579, -2579,  7321, -2579, -2579, -2579,    72,
    2141,  2260, -2579, -2579,   346,  6391,  2457, -2579, -2579,   228,
    2083, -2579, -2579,  7321, -2579, -2579,  2113, -2579, -2579, -2579,
     785, -2579,  1623, -2579,  7321, -2579,   251, -2579,  1843, -2579,
    1657,  7832, -2579,   364,  2483,  2120, -2579, -2579, -2579,  7832,
    2928,   519,  7832,  7832,  7832,  7832,   276,   521, -2579,  2122,
    2122,  1733,  2245,  7321,  2076, -2579,  2168, -2579,  2474, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
     276, -2579,   194, -2579, -2579, -2579,   997,   113, -2579,   567,
    2376,   523, -2579, -2579, -2579, -2579,   276, -2579,   808, -2579,
    2485,   113, -2579,  2494,  2488, -2579, -2579, -2579, -2579,   113,
   -2579,   203,  1901, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    2313,  6564, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -164,  2499, -2579,
     808,  1753, -2579,  2313, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2332, -2579, -2579,
    2084, -2579, -2579,   159, -2579,  2084,   159, -2579,   195, -2579,
   -2579,  7832,  2928,   259, -2579, -2579, -2579,  2069, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2138, -2579,  2489,
    2139,  2145,  2492, -2579, -2579,  2148, -2579, -2579, -2579, -2579,
   -2579, -2579,   220,  2515, -2579, -2579,   276,  2175,   276,  1924,
     705,  2210, -2579,  2115, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  1513, -2579, -2579, -2579,  6391,  2155,    72,   346,
    2174,   974, -2579,  7321, -2579,  1981,  2506,   346, -2579, -2579,
     824, -2579, -2579, -2579, -2579,   174,  2161,  1864, -2579, -2579,
   -2579,  2162,  2163,  2087,  2125, -2579,  2212,  2167, -2579, -2579,
   -2579, -2579,  2318, -2579, -2579,   199,  1656,  1939,  1656, -2579,
    1921,  7832, -2579,  2628,  2787,  2794,  2963, -2579, -2579,  1989,
   -2579, -2579, -2579,  1623, -2579,   531, -2579,  2021,   997,   997,
   -2579, -2579,  7832, -2579, -2579,   113, -2579,  2140, -2579,  2141,
    2021,  7582, -2579,   560,   180,   113,  7738,   808, -2579, -2579,
     267, -2579, -2579,   276, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,   808,  2499, -2579, -2579, -2579,   808, -2579,   808, -2579,
   -2579,  1897, -2579,  2333, -2579,  2335,   215, -2579,   561, -2579,
   -2579, -2579, -2579,   568,  2084,  1653,  2524, -2579, -2579,  1946,
   -2579, -2579, -2579, -2579,  2187, -2579,   258, -2579,   258, -2579,
   -2579,  7832, -2579,  2132, -2579,  2224,   132,   202,   276,  2535,
   -2579, -2579, -2579, -2579, -2579,   974, -2579,  2190,  7792,  2153,
   -2579, -2579, -2579,  1966,   346, -2579,   640, -2579, -2579, -2579,
    2193,   228, -2579,  2212,  2212,   785, -2579,  2194,  1959,  1657,
    1967, -2579,  2928, -2579, -2579, -2579, -2579, -2579, -2579,   276,
   -2579,   502, -2579, -2579,   199, -2579,  7748,   502,  1886, -2579,
    2565, -2579,  2928,   113,  2558,   332,  7158, -2579, -2579, -2579,
    2141,   203, -2579, -2579, -2579, -2579,  1580,  1580, -2579,  1580,
   -2579,  1580,  1580, -2579, -2579, -2579, -2579, -2579,   172, -2579,
   -2579, -2579,  7832,  2166,  1657, -2579, -2579,   570, -2579,  2568,
   -2579,  2928,  7158, -2579, -2579, -2579, -2579,  2571, -2579,  -157,
   -2579, -2579,  2224,  2206,   714, -2579, -2579,   181,   181,   181,
     181,   181,   181, -2579,  2555, -2579,   572, -2579,  7321,  1229,
   -2579, -2579, -2579,   638, -2579,  2212,  7321,  2212,  2087, -2579,
   -2579, -2579,  2359, -2579,  1657, -2579,  1657,   124,   346, -2579,
   -2579, -2579, -2579,   574, -2579,  2928, -2579,   578,  1870,  7738,
   -2579,  2171, -2579,  2409, -2579, -2579, -2579,  1580, -2579,  1580,
   -2579, -2579, -2579,  2928, -2579, -2579,   258, -2579,  7832,  2409,
     132, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  1050,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  7792,
   -2579,  2577, -2579, -2579,   676, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579,   127, -2579,  7748, -2579, -2579, -2579,  7738,
   -2579, -2579, -2579, -2579, -2579,  1059,  1059, -2579, -2579,  1059,
   -2579,  7321, -2579,  2215, -2579, -2579,   588, -2579, -2579, -2579,
    2217, -2579, -2579, -2579,   186, -2579,   228, -2579,  2087
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
   -2579, -2579, -2579, -2579, -2579,   411, -2579,   503,  -182, -2579,
   -2579,  -851,   254, -2579, -2579, -1530, -2579, -2579, -2579, -2579,
    -458, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -1405, -2579, -1534, -2579,
     466, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   741, -2579,
   -2579, -2579, -2579,  1362, -2579,  1037, -2579, -2579,   -45, -2579,
   -2579,  2562, -2579,  2563,  2237, -2579, -2579, -2579, -2579, -2579,
     812,   447, -2579,   805, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  -106,   878,   303, -2579, -2579,
    2320,    24, -2579,  2465, -2579, -2579,  2463, -2579,  2400, -2579,
   -2579, -2579,  2329,  2218,  1275,  2324,  -275, -2579, -2579, -2579,
   -2579, -2579,  1276,  -971, -2579, -2579, -2579, -2579, -2579, -2579,
    -138,  2279,  2423,  -198,   883, -2579,  2262,   179, -2579,  2323,
   -2579, -2579, -2579, -2579,  2326, -2579, -2579, -2579, -2579,  -323,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  2253, -2579,
    2257, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -836,
   -2579, -2579,  -397, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    2026, -2579, -2579,  1106, -2579,  -896,  -802,  -264, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   875, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  -482, -2579, -2579, -2579, -2579,
   -2579,  2126, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -1702, -2579, -2579, -2579, -2579, -2579, -2579,  1243, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  1693, -2579, -2579, -2579, -2579,   987,
   -2579, -2579, -2579, -2579, -2579, -1155, -2579, -2579,   989, -2579,
   -2579, -2579, -2579, -2579, -2579,  -786,  -388,   873,  1157, -2579,
    -464,   414,  -827,  1153, -2579,   835, -2579, -1811,    -2,  -209,
   -2579, -2579, -1725,   429,  1088, -2579, -2579, -2579,   696,  1396,
   -2579, -2579, -2579, -2579, -2579, -2579,   432, -2579,   104, -2579,
    1398, -2579,  1076, -2579,   763, -2579, -2579, -2579,  -398, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,   884, -2579, -1221,
   -2579,  1064, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,   428, -2579,   433, -2579, -2579, -2579, -2579,  1525,
   -2579, -2579, -2579, -2579, -2579, -2579,   -63, -1461, -2579, -2579,
   -2579, -2579,   598, -2579, -1682, -2579,  -826, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579,  2651, -2579, -2579, -2579,  2559,  2648,  -744, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,    46, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  2658, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  1117, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -389,  2208, -2579,
   -2579, -2579, -2579, -2579,  2038, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  2037, -2579, -2579,   -52, -2579, -2579,
    1122, -2579, -2579,  1450,  -187,  2428, -2579, -2579, -2579, -2579,
     -22, -2579,  -709,  2017,  1437, -2050,   807, -2579,  1137,  1784,
      81,   -99, -2579,  -947, -2579,  1574, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579,  1531, -2579,  1100, -2579,
    -338, -2579, -2579, -2579, -2579, -2579, -2579,  -265, -2579, -2579,
   -2579, -2579, -2579, -2579,   509, -2579,  1595,   -62, -2579, -2579,
   -2579, -2579,   336, -2579,   -96, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
    1848, -2579, -2579, -2579, -2579, -2579, -2579, -2579,  -322, -2579,
    1527,  1667, -2579, -2579,   344, -2579,  -432, -2579, -2579,   363,
     704, -2579, -2579, -2579, -2579, -2579, -2579, -2579,    86, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2025, -2579,  1718,   957,  -975, -2579,
   -2579, -2579,  1364, -2579, -1300, -2579, -2579, -2579, -1306, -2579,
   -2579, -1288, -2579, -2579, -2579, -2579,  1390, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2356,   -57,
   -2579, -2578, -2506, -2579,   774, -2579, -2579, -2579, -2579, -2579,
   -2579,  -325, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579,  -286, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2579,   750,
   -2579, -2579, -2579,  -175, -2579, -2579, -2579, -2579, -2579, -2579,
     331, -2579, -2579,   723, -2579,  1065, -2579, -2579, -2579, -2579,
   -2579, -2579,  -966, -2579, -2579, -2579, -2579, -1359, -2579, -2579,
   -2579, -2579, -2579, -2579, -2008,    59, -2579, -2429,   301, -2579,
   -2579, -1653,   357,   356,   724, -2579, -1840, -2042, -2579, -2579,
      99,  -180, -2579, -2579, -2579, -2579, -1867, -2579, -2579, -2579,
   -1465, -2579, -2579,  -658, -2579,  -703,  1474,    93, -1244,   718,
   -2579, -2024, -2579, -2579, -2579, -2579,  -645, -2579, -1649, -2222,
   -2579, -2579, -2579, -2579, -2579, -2579, -2579, -2013, -2579,   436,
   -2579, -1339, -2579,  1811, -2579, -2579,  -867,   -88, -2579, -1625,
     -87,   198,   506, -1557, -1374, -1695,   504,  -252,  1004, -2579,
     571,   -49, -2579, -2579,  1495,  -459, -2579, -2579,  -117,  1835,
   -2579,   966, -2579, -2579, -1230,   201, -2579, -2579, -2579, -2579,
   -2579, -2579, -2579, -2579,  1528, -2579, -2579,  -409,  -399,  -364,
    1069, -1247,    36,  2231,    96, -2579, -2579, -2579, -2579, -2579,
    1644, -2579,  -488, -2579, -2579, -2579, -2579, -2579, -2579, -2579,
   -2579,  -402,  1346,  2429, -2579, -2579, -2579, -2579
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1802
static const short yytable[] =
{
      41,  1022,  1163,  1019,   385,   257,   267,  1190,  1578,  1338,
      56,    58,   715,   283,  1172,   685,  1842,   685,   685,  1370,
     112,  1348,   695,  1159,   826,  1265,   863,  1733,  1800,   130,
     860,   685,   817,  2055,   866,  2092,    32,   255,  2089,  1275,
     415,  2064,    73,    76,  2186,  1590,  1591,   235,  2437,   685,
    1169,  1170,   685,  1171,   917,  1174,  1175,   920,   685,    32,
    1709,   875,   685,  1384,  1203,    69,   685,  1684,  1631,  1710,
     685,  2151,   112,   127,   685,   685,    76,   685,  1122,  1946,
     685,   337,   685,   685,   685,    96,   290,  1049,   136,   799,
     685,    40,  1195,   685,   824,   143,    40,  1496,    40,   148,
     685,   126,   150,   151,   695,   685,   911,  1214,   154,   155,
    1484,  2500,   666,   685,    40,  1960,    40,  2248,   139,  1270,
     268,  1195,   711,  1195,   685,  1285,  1189,  1287,   685,  2138,
     298,   299,   685,  1017,  1017,    40,    40,  1017,   685,    40,
    1497,   685,  1498,   792,  1499,    40,   873,   231,    40,  1139,
     234,   721,   393,   126,   274,   238,  1017,  2956,    40,   268,
     275,   276,  1254,   268,    96,  1115,  1254, -1800,   200,   828,
    2226,   268,  1196,  2194,   128,   265,  1868,  1869,  1197,  1195,
    1740,   755,   268,  1871,  1872,    40,  1394,  1741,  1421,  1868,
    1869,  1250,   268,   272,  2196,   268,  1871,  1872,    40,  2271,
    2185,  2002,    40,   785,  2271,  2678,  1164,    40,   683,   932,
      40,  2590,  1868,  1869,    40,  1017,  1266,    40,   268,  2436,
    1872,    40,  1127,  1128,   265,  2199,   873,   265,    40,    40,
     265,   295,  1868,  1869,  2242,  2792, -1800,   301,   268,  2436,
    1872,  2573,   775,  2396,  1017,   775,    40,   857,   329,    40,
     291,   268,   923,   924,    40,   784,   265,   876,   882,   775,
    1967,   898,  1964,   775,  2836,   902,  1529,   904,    40,  2720,
     801,   908,  2921,   910,    40,   775,   378,   784,   268,   269,
     270,    40,  1017,   812,    40,  1560,   784,   184,   185,    81,
    2919,  1737,    81,   823,   380,   186,    40,  2370,   827,  1582,
    1255,  1560,    40,   343,  1255,   345,   865,  1152,  2754,  2915,
      96,   268,   923,   924,    40,  2265,   388,   812,   556,   645,
      62,   812,  1291,    40,  1379,   812,  2887,  1006,  3095,   691,
    3007,   784,  2498,  1972,   784,  2396,   412,  1800,  2542,  2543,
    2544,  2545,   691,   397,   652,    64,    81,  1012,  2901,    70,
    2210,    81,  1535,   407,  2504,  2808,   407,   654,    40,   391,
      40,  2907,  3031,    34,   407,  1380,   302,  2655,   933,  2756,
    1917,  1187,    81,  1251,  2396,   933,   391,  2392,  1007,  1153,
     329,  1918,   329,  2651,  2426,  2651,    62,  2922,   399,   679,
       1,   655,   403,   303,  1370,   779,  1013,   101,    81,   637,
     647,  1014,   102,  2071,  2809,   648,   987,   988,   788,   407,
    1921,  3032,    33,    34,   681,  1336,   686,   933,    81,   692,
     697,  1922,   699,  1188,   814,   702,  1195,   685,   649,  1973,
      33,  1226,  1195,   989,   990,   991,   708,  2048,  2051,    78,
      81,  2051,  2027,   769,    94,  2027,   103,   104,   258,   259,
     260,   261,   262,  1503,   105,   708,  2052,  1496,    81,  1181,
    1182,  2075,  2077,     3,     4,   769,     5,     6,   708,  2249,
    1293,     7,  2391,   730,  2394,  3001,  1950,  1561,   802,  1592,
    2420,  2420,  1593,  2446,  1594,  2533,  2462,   934,     8,     9,
    1738,  3086,   138,  1561,   818,   820,  2462,  2446,   734,  2502,
    2577,   692,  2519,  3068,  1595,  2010,    10,    11,  2013,   769,
    3096,   818,   818,  2599,  1596,    40,  2418,   682,  1530,   769,
     769,  2682,   894,   769,  2761,    76,  2761,   769,  2785,   769,
    1616,  1617,   935,   769,  1874,   769,  2899,   912,  2789,   912,
     818,  2139,   912,   818, -1800,   912,  1400,  1874,    40,  1875,
     685,   685,   685,  1209,  1814,  1212,  1597,  3010,  2572,  1353,
    1598,   857,  1875,  2780,  1395,  2913,  2938,  1397,  1398,  1399,
    1874,   682,  1354,  2938,  1252,  3026,   266,  3049,  2253,  3065,
    2156,  2427,   743,  3009,  1766,  1875,  1417,  1769,  1625,  1626,
    1874,  2467,  1302,  3009,  1349,  2072,  1194,  1636,  2658,  1378,
     933,  2591,   857,  2499,  2260,  1875,   884,  1253,  2397,   695,
    2200,  1961,   815,    40,   876,  1286,  2834,  2721,  1981,  1217,
     865,  1857,  2259,   900,   129,   340,   682,  1982,   668,  2830,
    2846,  1716,  2830,  1366,  2651,  2507,  1198,  1968,  1599,  1299,
    1676,  1376,   379,  2515,  2516,  2799,   961, -1800,  1333,  1905,
    2227,  1983,   925,  1952,  1984,  1480,   885,  2753,    75,    81,
     381,   682,  1165,   936,  1256,  2837,  1816,  2995,  1256,  1860,
     936,  1465,  1985,    40,   982,   748,   407,  2371,   382,  2128,
     187,  1140,   389,  1479,   817,   793,  2916,   750,   751,   692,
    1600,  1500,    81,  1299,   886,   975,   753,  1334,   271,  1501,
    2424,  1215,  2043,  2043,  1018,  2726,  2043,  1905,   106,   398,
    2056,  2750,   936,   816,   769,   769,  1166,  1460,   816,  2568,
     816,  2262,  3025,  2003,  1199,  2043,  2450,   695,  2588,   769,
    1201,  1532,  1742,  1545,   107,   769,   769,   271,  1485,  2646,
     769,   271,  1466,   865,   827,   865,  2270,  2920,  2324,   271,
     769,  2086,  2711,  2692,   400,   926,  1544,  1565,   404,  2728,
     271,  1547,  1129,  2733,  2422,  2902,  2903,  1015,  1384,  2441,
     271,  1746,  3061,   271,  3062,  1586,  1587,  2442,  1986,  1018,
     140,  1337,  2048,  1540,  2043, -1800, -1800, -1800, -1800, -1800,
    1356,   887,  1732,   937,   938,   939,   271,  2057,  1837,  1554,
    1527,  2086,  2651,   992,   940,   108,  1357, -1800,  2028,    40,
    1989,  2042,  1353,  2698,  2058,  2832,   271,   181,  2659,    40,
    1377,   935,  2053,   769,   769,  1354,  2531,  2076,  2078,   271,
    2955,  1618,  1987,  2857,    40,  2250,  2755,  1790,  2946,  1988,
    2948,   258,   259,   260,   261,   262,  2421,  2423,  2332,  2447,
     941,  2654,  2463,  1149,  2657,  1638,   271,  2059,   769,   728,
    1850,  2415,  2464,  2469,   769,  2503,  2578,   888,  1467,  1468,
    1469,   729,  1353,  1146,  1601,  1342,   769,  1339,    17,  2600,
    1341,   769,  2645,  2486,  2757,  1354,  1224,  2683,  1491,   271,
    2762,   993,  2768,  1592,  2786,   936,  1593,  2060,  1594,   109,
    3055,    17,  2900,  1342,  1242,   690,  1632,    40,   889, -1800,
      57,  1727,    40,  1595,  2830,  1595,  2574,  2575,  1595,   769,
    1717,   135,   131,  2481,  1971,  1528,  2061,    40,  1596,  2014,
   -1800,  2914,  2939,   769,   994,  2062,   383,  3034, -1800,  2940,
     899,  3027,   140,  3050,   903,  3066,   142,  1925,   907,  3067,
     876, -1800,  1375,    81,  1132,  2660,  1793,  2661,  2534,  3092,
    1794,  1133,  2898,    81,  1483,  2681,  1270,  1553,  2685,  1765,
    1597,   867,  1768,    40,  1598,   144,   890,  1568,    81,  2745,
     110,   258,   259,   260,   261,   262,  1350,   193,   111,  1595,
    1358,  1367,  1358,  1391,  2941,  2164,  2699,  1355,   873, -1800,
      40,  2155,    43,   692,  1404,  1405,   692,  2700,  1383,  1386,
     703,    40,   699,  1815,  1343,   745,   194,    80,  3072,    40,
    2579,   232,  2582,  1633, -1558,   233,   818,   769,  2583,   818,
     818,   818,   818,   240,   769, -1800,  1147,   769,   401,  1231,
     891,  3036,  1343,  1356,  2536,  3037,  2487,  1599,   818,  1599,
     769,   691,  1599,   197,   769,  2232,    80,  1369,    40,  1357,
     248,  2389,   769,  1795,   769,   769,  1796,   769,   769,   769,
     769,   769,   769,   769,   769,   769,   769,   769,   769,   769,
     769,   769,   769,   769,   747, -1800,  1659,  2904,  1595,  1841,
    1344,  1271,   685,   749,   769,   769,  1831,    40,  1178,   769,
    1557,   769,  1370,  1356,  1600,  1185,   251,  2888,  2440,  2890,
    1080,  1081,  1082,  1083,  1084,  1085,  1456,    81,  1344,  1357,
    1928,   132,   133,  1599,   692,  1639,  1271, -1800,  1908,  1910,
     769,   769,   769,  1634,     3,     4,  1640,     5,     6,   249,
    2264,   818,     7,  1482,    81,  1486,   818,  1651,  1345, -1800,
     769,  1624,  1569,   133,  1949,    81,  1382,  1628,  1641,     8,
       9,  2537,    40,    81,  2322,  1642,  1086,  1087,  1088,  1089,
    1090,  1091,   252,  1235,  2665,    40,  2668,    10,    11,   950,
    1863,    44,  1092,  1093,  1094,  1793,    40,   769,  2478,  1794,
     951,  2448, -1800,   818,    40,    45, -1800,  1281,   253,    40,
   -1800,  2493,    81,  2666,  1461,  2782,    40,    40,  1784,    40,
    1346,  2731,   769,  2152,   685,  1830,  1542,    40,   818,   818,
      46,  1288,  1599,   818, -1800,  1667,   256,  1551,  1552,   769,
    2873,  1660,  1809,  1639,  1673,   685,  1469,   916,  1346,   769,
     919,    81,   952,   922,  1640,  2087,   264,  2252,    12,  3052,
    1661,  1662,  2521,   692,    40,    40,  2641,   953,    40,  2082,
     912,   818,   818,  3013,  1646,  1647,  1641,  1194,  3077,    47,
    1663,  2538,  2341,  1642,  1406,   284,  3000, -1800,  2374,  1407,
    1408,  1409,  3006,   273,   285,  1805,  1620,   278,  1601,  1018,
    1018,  2325,  1795,  1849,  1629,  1796,  1629,  1406,  1018,  3029,
     287,  1659,  1407, -1800,  1409,  2399, -1800,  2400,  2401,  2402,
    2403,  2404,  2405,  2212,  2213,  2214,  2215,  1595,  2129,    81,
    2130,   807,   648,  1095,  1289,  1595,  1096,  -265, -1800,  2141,
     813,   288,  1290,  2781, -1800,   336,   289, -1800,  1291, -1800,
    1292,  1018,   293,    81,   963,   649,   690,   954,    40, -1800,
      81,  1293, -1800,  1358, -1800,  2798, -1800, -1800,   294,     1,
     975, -1800, -1800,  1687,  1367,   956,   957,  1358,  2216,  2217,
    2218,  2219,  2220,  2221, -1800,   915, -1800,  3036,   918,  1294,
     306,  3037,  1654,  1655, -1800,  2193, -1800,  1723,  1724,  1725,
   -1800,  2528,  1023,  1024,  1025,  1295,   296,  2567,    81,  1017,
    1296,    40,    81, -1800,  2375,   300,  2831,   827,  2430,  2831,
    2432,  2433,  1297,   305,  -265,  2981,  1222,   314,    40,  1298,
     777,  2376,  2377,   769,   769,   769, -1800,   769,   865,  2378,
   -1800,  -265,     3,     4,   786,     5,     6,  1373,   791,    40,
       7,  1806,  1807,  1179,  1180,  1097,  1660,  1183,  1184,    15,
     805,  1599,  3058,   769,   323,  2083,  1775,     8,     9,  1599,
    1098,   324, -1800,  2379,  1099,  1661,  1662,   307, -1800,   330,
     769,  2689,  2380,  2687,  -265,    10,    11, -1800,  2989,  2990,
   -1800, -1800,   937,   938,   308,  1663,   333,   334,  1803,  1204,
    1205,  1206,  1207,  1117,   769,   335,  1810,  1811,   769,   818,
    2223,  2381,  1100,  3041,   339,  2344,  2345,   315, -1800,  2346,
    2347,  2348,   341,  1996,  -265,    40,  2131,  2132,  1469,  2135,
     132,   133,  2981,  1228,  2096,   342,  2097,   309,  2406,   769,
    1101,   712,   712,  2713,   769,  2714,  2860,   346,  2861,   347,
    2158,  2905,   350,  -265,  1839,  2098,  2382,   351,   769,  1102,
     132,   133,  -265,   352,   353,   769,  1462,   356,  1462,   685,
   -1800,   357,   368,   769, -1800,   685,   367,   310,   371,  1864,
    1242,   387,  1889,   689,  1299,   376,   386,  2317,  3041,   390,
    3057,  1300,  3059,   394,  1118,   395,   707,   396,  2383,   685,
     818,   818,   413,   402,   316,   405,   311,  2190,  1688,   653,
     658,   660,   661,  1301,   669,   312,   818,   662,  1302,  2349,
     667,   317,  2960,   780,  1229,   671,  2350,   672,   673,   675,
       3,     4,  2443,     5,     6,  1018,   712,   676,     7,   797,
     798,  1103,   677,  1889,   678,   804,   927,   680,   806,   965,
     966,  2807,   967,   968,  1997,     8,     9,  2407,   969,   970,
    2351,   971,   972,  2740,   318,   973,  1689,  2009,  2009,  2352,
    2942,  2009,   974,    10,    11,   978,    13,  2532,  1690,  2470,
    2212,  2213,  2214,  2215,   979,   980,  2739,  1889,  1691,  2044,
    2044,   981,   985,  2044,  1889,  1083,  1084,  1085,  2353,  2354,
    1004,  2831,  1005, -1800,   319,  1007,  1692,  1010,  1104,   258,
     259,   260,   261,   262,  2408,  1008,  1693,  1011,  1016,  1694,
    2079,  1020,  1029,  1383,  1119,    14,  1028,   769,  2319,  1031,
    2320,  1126,  1695,   320,  1358,  2216,  2217,  2218,  2219,  2220,
    2221,  1889,   321,  2355,    12,  1032,  1033,  1034,  1086,  1087,
    1088,  1089,  1090,  1091, -1800,  1035,  1036,  2696,  1037,  1038,
    1039,  1050,   827,  2215,  1092,  1093,  1094,  1051,   865, -1800,
    1052, -1800,  1055,   769,  1056,  1059,   769,  1061,  1130,  1062,
    2559,  1696,  2561,  1063,  1358,  2356, -1800,  1064,   769,   769,
     769,   769,   865,  2044, -1800,  1131,  2960,  1065, -1800,  2143,
    1803,  1066,  1067,  2148,  2148,  2813,  1069,  1134,   927, -1800,
    2743,  1697,   769,  1135,  1041,  2216,  2217,  2218,  2219,  2220,
    2221,  1698,  2160, -1800,  1137,  1138,  1143,  2399,  1142,  2400,
    2401,  2402,  2403,  2404,  2405,  2212,  2213,  2214,  2215,  1145,
    2100,  2357,  1699,  2409,  2102,  1700,  1148,  1701,  1157,  2105,
    1162,  1176,  1186,  2109,  1116,  2111,  2112,  2113,  1189,  1210,
    1218,  1219,  1220,   685,   685,  1221,  1225,  1227,  1507,   769,
    1230,  1239,  1241,  1261,  1231,  1702,  2814,  1262,  2864,  1195,
    2472,  1263,  1269,  2477,  1703,  1889,  2872,  1264,  1273,  2410,
    2216,  2217,  2218,  2219,  2220,  2221,  2209,  2212,  2213,  2214,
    2215,  1042,  1276,  1277,  1278,  1095,  1279,   692,  1096,  1324,
    2411,  1332,  1335,  1868,  1869,  2233,  1870,  1352,  1043,   268,
    1871,  1872,    40,   384,  2613,  2614,  2615,  1372,  2617,  2618,
    2619,  2620,  2621,  2622,  1389,  1390,  1391,  2625,  1401,   857,
    1392,  1873,  2815,  1393,  2816,    15,  1415,  1418,  2212,  2213,
    2214,  2215,  2216,  2217,  2218,  2219,  2220,  2221,  1018,  2817,
    1416,  1044,  1423,  1451,  1454,  1459,  1472,  2818,  1458,  1201,
    1478,  2819,  1492,  2044,  1494,  1505,  1889,  1490,  1506,  1531,
    1533,   645,  1534,  2268,  1629,  1538,  1536,   645,  1543,  1546,
     769,  1557,   769,  1564,  1572,  2688,  2820,  1548,  1571,  2696,
    2044,  1045,  1018,  2216,  2217,  2218,  2219,  2220,  2221,  1496,
    1566,  2009,  2056,  2669,  2735,  2526,  1574,  1271,  1608,  1610,
    2814,  2737,  2722,   927,  1611,  1613,  1668,  1097,  1619,  1679,
    1046,  1681,  1682,  2980,  2044,  1685,  1686,  1715,  1889,  1047,
    1889,  1714,  1098,  2703,  1712,     1,  1099,  1718,  1719,  1728,
    2406,  2044,  1729,  1730,  1731,  1734,   827,   827,  1736,  1743,
    1358,  1747,   647,  1745,  1748,  1750,   691,  1753,   647,  1774,
    1779,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,  2366,
    2367,  1777,  1780,  1367,  1100,  1358,  2815,  1781,  2816,  1782,
    1786,  1787,  1723,  1788,  1783,   769,  1785,  1789,  3012,  2057,
    2670,  1791,  1270,  2817,  1792,  1804,  1817,    88,  1819,  1821,
    1828,  2818,  1101,  1820,  1825,  2819,  2058,  2671,     3,     4,
   -1800,     5,     6,  1834,  1835,  1836,     7,  1840,  1508,  1843,
    2704,  1102,   769,   769,  1509,  1510,  1511,  1844,  1847,  1853,
    2820,  1867,   769,     8,     9,   769,  1861,  2705,  1899,  1900,
    2479,  2214,  2215,  2696,  1512,  2696,  1901,  3064,   158,  2059,
    2672,    10,    11,  1803,  1905,  2494,  1947,  2496,  1907,  2407,
     940,  1948,  1959,  1976,   769,  1965,  1975,   769,  1992,   182,
     190,  2511,  2988,  1994,  1995,   769,   769,  2006,  2017,  2018,
    2706,  3042,  3043,  3044,  3045,  3046,  3047,   159,  2019,  2060,
    2673,   769,  2023,  2026,  2216,  2217,  2218,  2219,  2220,  2221,
    2044,  2065,  1889,  1103,  2066,  2067,   160,  2068,  1889,  1889,
    1889,  1889,  1889,  1889,  2069,  2081,  2408,  2070,  2061,  2674,
    2707,  2084,  2093,  2094,   190,  2095,  2101,  2062,  2675,  2104,
     190,  2736,   818,  2114,   818,    49,    50,    51,    52,    53,
      54,  2532,    55,  2115,  2116,   161,  2119,  2120,  2124,  2708,
     927,  1889,  1513,  2126,  2863,  1514,  2122,   162,  2709,  2137,
    2751,  1874,  2866,  2142,  2044,  2157,  2159,   163,  2167,  1889,
    1104,  2168,  2191,  2170,  2172,  2171,  1875,  2173, -1800,  1515,
    2174,  2175,  2202,  2192,  2203,   164,  2204,  2211,  2806,  2769,
    2205,  2206,  2891,  1876,  2207,   165,  1877,  2208,  2231,  1516,
     190,   939,   190,   712,  2730,  2234,  2236,  2243,  1330,  1878,
    2245,   166,  2251,  2255,  2266,  2271,  2044,  2216,  2217,  2218,
    2219,  2220,  2221,  2696,  2263,  2602,  2603,  1997,  2318,  2327,
    2256,  2328,  2329,  2606,  1517,  2330,  2335,  2200,  2390,  2398,
    2417,  2418,  2419,  2425,  2428,  2409,  2431,  2434, -1746,  2909,
    1880,   167,  2444,  2449,  1518,  1519,  2453,  2454,   927,  2455,
    2456,  2458,  1881,  2457,  2459,  1520,  2460,  2461,  2465,  2468,
    1521,  2471,  2473,  2474,  2480,   168,   190,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  2484,  3098,  2488,  2495,
     169,  2410,  2492, -1800,  1889,  2506,  1889,   170,  2514,  2524,
     171,  2546,  2558,  2530,  1882,  2649,  2965,  2649,  2555,  1522,
    2569,  1889,  2411,  2579,  2570,  2396,  2044,  2667,  2044,  2586,
    2601,   172,  2588,  2597,   173, -1800,   174,  2611,  2612,  2616,
    2623,  2624,  2634,  2630,  2631,  2635,  1086,  1087,  1088,  1089,
    1090,  1091,  1523,  1883,  1358,   175,  2636,  2637,  1018,  2638,
    2639,  2640,  1092,  1093,  1094,  1884,  2200,  2653,  2656,  2867,
     769,  2663,  1343,   176,  2677,  2679,   705,  1885,  1886,  2684,
    2686,  1968,  2690,  2712,  2723,  2724,  1887,  2718,  2725,  1888,
    2738,  2741,  2148,  2726,  2748,  2732,  2148,   271,  2758,  2744,
     818,  2759,   934,   769,  2773,  2783, -1800,   818,  2791,  2795,
     782,  2796,  2803,  2804,  2811,  2826,   787,  2415,   789,  2839,
    2842,   769,   796,   685,  2840,   796,  2843,  2844,   796,  2845,
    2848,  2858,   769,  2851,  2856,  2859,  2862,  2865,   808,  1889,
    2869,  2871,  2875,  2877,  2878,  2879,  2881,  1889,  2883, -1800,
    1889,  1889,  1889,  1889,  2767,  2897,  2889,   855,  2450,  2943,
    2906,   769,  2934,  2944,  2935,   868,   871,   874,  2945,  2952,
    2963,   895,  2966,  2978,  2987,  2993,  2994,  2979,  2774,   905,
    3009,  3011,  3024,  3028,  2996,  2044,  3030,  3035,  1896,  3048,
    3060,  3069,  3081,  2510,  2268,   929,  3091,  2445,  3093,  2044,
    2466,  3080,  2183,  1095,  1556,  1852,  1096,  2044,    71,  1620,
     557,    72,  2491,  2153,  2144,   196,   348,   201,   280,   344,
    1670,   349,  1671,   670,  1751,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,   406,   657,   282,  2103,   663,  2715,  1827,   375,  1979,
     373,   664,  3078,  2121,  2007,  2212,  2213,  2214,  2215,  1739,
     893,   692,  1328,  2015,   692,  2133,  2649,  1812,  1585,  1889,
    2772,  2557,  1890,  1589,  1904,  3084,  2230,  1926,  1649,  1650,
    2140,  2563,  2874,  1487,    66,  1666,   156,    67,  2565,  2824,
    1859,  1086,  1087,  1088,  1089,  1090,  1091,    68,   964,   803,
    1018,  1862,  1570,   338,  2849,   984,  2854,  1092,  1093,  1094,
    2216,  2217,  2218,  2219,  2220,  2221,   865,  1607,  2225,  1866,
    1267,  2812,  2925,  1474,  3051,  1097,   818,  1526,  3056,  1962,
    2548,   769,  2644,  1890,  1464,  2933,  1213,  1424,  2643,  2387,
    1098,  2626,  1388,  2127,  1099,  2257,  1713,  1979,  2918,  1680,
    3085,  1539,  1026,  1027,  3074,  2326,  3014,   929,  2664,  2388,
    2054,  2847,  2697,  2647,  2648,  2833,  2395,  1040,  3022,  1889,
    2838,  2414,  1623,  1053,  1054,  2604,  1317,  1890,  1058,  2961,
    2777,  2962,  1100,  2585,  1890,  2587,  3073,  2937,  1068,  1615,
    1889,  2547,  2999,  2044,  2080,  1583,  1284,  2788,  1481,  1889,
     414,     0,     0,  2044,  1889,     0,     0,     0,     0,     0,
    1101,  2924,     0,     0,  2212,  2213,  2214,  2215,     0,     0,
       0,  2212,  2213,  2214,  2215,  1120,     0,  3090,     0,  1102,
       0,  1890,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1095,  1084,
    1085,  1096,     0,     0,  1018,     0,  1018,     0,     0,  1889,
       0,     0,     0,     0,  2044,     0,  2854,     0,  1151,  2216,
    2217,  2218,  2219,  2220,  2221,     0,  2216,  2217,  2218,  2219,
    2220,  2221,  1168,  1168,  1168,     0,  1168,     0,  1168,  1168,
       0,  2201,     0,     0,    88,    88,     0,  1833,     0,     0,
       0,  1086,  1087,  1088,  1089,  1090,  1091,  2774,     0,     0,
       0,  1103,     0,     0,  1889,     0,  1889,  1092,  1093,  1094,
       0,  2044,     0,     0,  1889,     0,     0,     0,     0,  1620,
       0,     0,     0,     0,     0,     0,     0,   874,     0,     0,
    1902,     0,     0,     0,     0,     0,   692,     0,  1237,     0,
    1889,     0,     0,     0,     0,  2212,  2213,  2214,  2215,     0,
    1889,     0,     0,     0,     0,     0,  2195,  2197,     0,     0,
    1097,     0,   929,  1120,     0,  1890,     0,     0,  1104,     0,
       0,  1274,     0,     0,     0,  1098,   769,  3053,     0,  1099,
    2212,  2213,  2214,  2215,   769,     0,     0,  1282,  1282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2893,
    2216,  2217,  2218,  2219,  2220,  2221,     0,  1889,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1100,     0,     0,
       0,     0,     0,     0,  1018,     0,  1889,     0,  2044,     0,
       0,     0,     0,     0,  2393,  2216,  2217,  2218,  2219,  2220,
    2221,     0,     0,     0,   190,  1101,     0,     0,  1095,     0,
       0,  1096,     0,     0,     0,  1396,  1890,     0,     0,     0,
       0,     0,  1403,  1889,  1102,  1414,     0,  1889,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1419,   769,
       0,     0,  1422,  1085,     0,     0,     0,     0,     0,     0,
    1428,     0,  1430,  1431,     0,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1448,     0,     0,     0,     0,     0,     0,  1890,     0,
    1890,     0,  1449,  1450,     0,     0,     0,  1452,     0,  1453,
       0,     0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
    1092,  1093,  1094,     0,     0,     0,  1457,     0,  2894,     0,
    1890,     0,     0,     0,    88,  2895,    88,   874,   796,     0,
    1097,     0,     0,     0,     0,  1473,   808,     0,     0,   874,
       0,     0,     0,   190,     0,  1098,  1488,     0,     0,  1099,
       0,  2179,  2180,     0,     0,     0,     0,     0,     0,   929,
       0,     0,  2189,     0,     0,     0,     0,     0,  2540,     0,
       0,     0,     0,  1104,  2540,  1896,  2549,  2550,  2551,  2552,
       0,     0,     0,     0,     0,    88,     0,  1100,     0,     0,
       0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1092,  1093,  1094,
       0,     0,     0,     0,     0,  1101,     0,  1979,  2238,  2239,
    2240,  2241,     0,     0,  1549,     0,     0,     0,     0,     0,
       0,     0,     0,  2247,  1102,  1979,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1576,     0,
       0,  1095,  1890,  1579,  1096,     0,     0,     0,  1890,  1890,
    1890,  1890,  1890,  1890,     0,     0,  1606,   929,     0,     0,
       0,     0,  2166,  1070,  1071,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,
       0,     0,     0,     0,  2896,     0,     0,     0,     0,     0,
       0,  1890,     0,     0,     0,     0,     0,     0,     0,     0,
    2333,  2334,     0,     0,     0,     0,  1103,  2338,  2339,  1890,
       0,  1653,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1086,
    1087,  1088,  1089,  1090,  1091,     0,     0,     0,  1095,     0,
       0,  1096,     0,     0,     0,  1092,  1093,  1094,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,
       0,     0,     0,  1097,     0,     0,   874,  2662,     0,     0,
       0,     0,     0,  1104,     0,     0,     0,     0,  1098,     0,
       0,     0,  1099,     0,   712,   712,   712,     0,   712,   712,
     712,   712,   712,   712,     0,     0,     0,   712,     0,     0,
       0,  1754,  1755,  1756,     0,  1758,     0,     0,     0,     0,
    1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,     0,
    1100,     0,     0,     0,     0,     0,  1092,  1093,  1094,     0,
       0,  1773,     0,     0,  1890,     0,  1890,     0,     0,     0,
       0,  2482,  2483,     0,     0,  1890,     0,  1890,  1101,     0,
    2490,  1890,     0,     0,   202,     0,     0,     0,  2501,     0,
    1097,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
       0,     0,     0,     0,     0,  1098,     0,  2517,  2518,  1099,
       0,     0,     0,   203,   204,  1979,  1095,     0,     0,  1096,
       0,     0,   205,  2760,     0,     0,  2763,  2764,  2765,  2766,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,     0,     0,
       0,     0,  1829,     0,     0,     0,  1824,  1100,     0,     0,
       0,     0,     0,     0,     0,  1832,  1773,     0,     0,     0,
       0,  2560,     0,  2562,     0,   874,     0,     0,     0,     0,
    2564,     0,  2566,     0,     0,  1101,     0,   927,     0,  1103,
       0,     0,     0,     0,     0,     0,   182,  1086,  1087,  1088,
    1089,  1090,  1091,     0,  1102,     0,     0,  1095,     0,  1890,
    1096,     0,     0,  1092,  1093,  1094,     0,  1890,     0,     0,
    1890,  1890,  1890,  1890,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     874,  1951,   874,     0,     0,     0,   868,     0,  1097,     0,
       0,     0,     0,     0,     0,  2835,  1104,     0,     0,     0,
       0,     0,     0,  1098,     0,     0,     0,  1099,     0,     0,
       0,     0,  2607,  2608,     0,     0,  2609,  2610,  2001,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   206,     0,  1100,     0,     0,     0,     0,
    2633,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1097,
       0,  1890,     0,  1101,  1890,     0,  1890,     0,     0,  1890,
       0,     0,   207,     0,  1098,   874,     0,     0,  1099,     0,
       0,     0,  1102,  1104,  1095,  2892,     0,  1096,     0,     0,
       0,   208,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1979,   209,     0,  1929,
       0,  2117,     0,     0,  2117,  2912,  1100,     0,     0,     0,
    2912,     0,     0,     0,     0,     0,     0,     0,     0,  1762,
     210,     0,     0,     0,   874,     0,   874,     0,     0,     0,
       0,     0,   211,     0,  1101,   874,     0,     0,     0,     0,
       0,  2729,   212,     0,     0,  2734,     0,     0,     0,     0,
       0,     0,     0,  1102,  1103,     0,     0,     0,     0,  1890,
     213,     0,     0,     0,     0,  2951,     0,     0,     0, -1801,
     214,     0,     0,  2165,     0,     0,  2749,     0,     0,     0,
    1890,     0,     0,     0,     0,     0,   215,     0,     0,  1890,
   -1801,     0,     0,     0,  1890,     0,  1097,     0,     0,     0,
       0,     0,  2188,     0,     0,     0,     0,     0,     0,     0,
    2770,  1098,     0,     0,     0,  1099,     0,     0, -1801,     0,
    3005,  1104,  3008,     0,  1890,     0,   216,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2224,  1579,  1890,
     217,     0,     0,  1100,     0,     0,  3023,     0,     1,     0,
   -1801,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     0,   219,     0,     0,   220,     0,     0,     0,   927,
       0,  1101,     0,     0,     2,     0,     0,     0,     0,     0,
   -1801,     0,     0,     0, -1801,     0,   221,     0,     0,   222,
    1102,   223,  1104,     0,  1890,     0,  1890,     0,     0,     0,
       0,     0,     0,     0,  1890,     0,     0,     0, -1801,     0,
     224,     0,     0,  2912,     0,     0, -1801,     0, -1801,     0,
       0,     3,     4,  1930,     5,     6,  1890, -1801,   225,     7,
    1890,     0,  2951, -1801,     0,     0,  1931,     0,     0,  2331,
    1890, -1801,     0,     0,     0, -1801,     8,     9,     0,     0,
       0, -1801,     0,     0,     0, -1801, -1801, -1801, -1801,     0,
       0,     0,     0,     0,    10,    11,     0,     0,     0,  3005,
   -1801,   226,  1103,  2912,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1801,     0,     0,
   -1801,     0, -1801,     0,     0,     0,     0,  1890,  2886, -1801,
    1932,     0,     0,     0,     0,     0,     0,  1933,     0,     0,
       0,     0, -1801,     0,     0,     0,  1890,     0,   874,     0,
       0,     0, -1801,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,  1104,
       0, -1801, -1801,     0,     0,     0,  1934,     0,     0,     0,
    1773,  1773,     0,  1890,     0,     0, -1801,  1890,     0,     0,
       0,     0,     0,     0, -1801,   874,     0,     0, -1801,     0,
       0,  1935,     0,     0,     0,     0,     0, -1801, -1801, -1801,
       0,  1936,  1937,     0,   927,  2212,  2213,  2214,  2215,     0,
       0,     0,  2505,     0,    40,  1773,     0,  1938,  1579,     0,
       0,     0,     0,  1773,  1773,     0,     0,  2508,     0,   705,
       0,  2512,     0,     0,     0,     0,     0,     0,     0,  1939,
       0,     0,  1940,  1941,  2523,     0,     0,     0,  1942,   190,
       0,  2991,     0,     0,     0,     0,     0,     0,     0,     0,
    2216,  2217,  2218,  2219,  2220,  2221, -1801,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0, -1801,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3015,  3016,     0,  3018,     0,  3020,  3021,     0,
       0,     0,     0,     0,     0,  1943,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1944, -1801,     0,
       0,     0,     0,     0,    14,     0,     0,     0,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,     0,  3063,     0,     0,  1081,  1082,  1083,  1084,
    1085,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   -1801,     0,     0,  3070,     0,  3071,     0,  2605,     0,     0,
       0,     0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1092,  1093,  1094,     0,     0,     0, -1801,     0,     0,     0,
    3082,  1086,  1087,  1088,  1089,  1090,  1091,  2627,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1092,  1093,  1094,
    2642,  3087,  3088,     0,     0,  3089,     0,     0,  2273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0, -1801,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0, -1801, -1801, -1801,
   -1801, -1801, -1801, -1801,     0, -1801, -1801,     0,  2274,  2275,
    2276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   874, -1801,     0,     0,     0,     0,     0,  2716,     0,
       0,     0,     0,  2277,     0,     0,     0,     0,     0,     0,
       0,  2278,     0,     0,     0,     0,  2279,     0,   874,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2280,     0,   190,     0,     0,  2281,     0,  2282,     0,
       0,  1095,     0,     0,  1096,  2283,     0,     0,  2284,  1773,
       0,  2285,     0,     0,  2286,     0,   929,  2287,     0,     0,
       0,     0,  2288,     0,     0,     0,     0,     0,  1095,     0,
       0,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
    2289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2290,     0,     0,  2291,
    2292,     0,     0,     0,     0,     0,  2293,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2294,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2295,     0,  1579,     0,     0,     0,     0,
    2296,     0,     0,     0,     0,     0,     0,  2297,     0,     0,
    2298,  2299,  2300,     0,  2301,  2302,     0,     0,     0,     0,
       0,     0,     0,  1097,     0,     0,     0,     0,     0,     0,
       0,  2303,     0,     0,     0,     0,     0,  2627,  1098,     0,
       0,     0,  1099,  1420,     0,     0,     0,     0,     0,     0,
    1097,     0,     0,     0,     0,  2304,  2305,  2306,  2307,     0,
    2308,     0,     0,     0,     0,  1098,     0,     0,     0,  1099,
       0,     0,     0,     0,     0,     0,     0,  2309,  2310,     0,
    1100,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,     0,     0,     0,     0,     0,     0,     0,     0,
    2311,     0,     0,     0,     0,     0,     0,  1100,  1101,  2312,
    2313,     0,  2314,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1102,   874,     0,
       0,     0,     0,     0,     0,  1101,     0,     0,     0,     0,
       0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,  1092,  1093,
    1094,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2315,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1579,     0,     0,     0,     0,  1103,
       0,     0,     0,     0,     0,     0,     0,     0,  2627,     0,
       0,     0,     0,  2928,     0,  2930,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1092,  1093,  1094,
       0,     0,     0,     0,   874,     0,     0,     0,     0,     0,
       0,     0,   874,     0,     0,     0,  1104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   929,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
       0,     0,  1096,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,   416,     0,   417,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   418,     0,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   420,     0,     0,
       0,     0,     0,     0,   421,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   422,   423,   424,     0,     0,
       0,     0,     0,     0,  1168,  1168,  1168,  1168,  1168,  1168,
       0,   425,  1773,   426,   427,   428,     3,     4,   429,     5,
       6,   430,     0,   431,     7,   432,   433,     0,  1095,     0,
       0,  1096,   434,     0,     0,   435,     0,   436,   437,   438,
       0,     8,     9,     0,     0,     0,     0,   439,     0,   440,
     441,  1097,   442,     0,   443,   444,     0,     0,   445,    10,
      11,     0,     0,   446,   447,   448,  1098,   449,   450,     0,
    1099,     0,   451,   452,     0,   453,     0,     0,     0,   454,
       0,   455,   456,     0,     0,     0,     0,   457,     0,     0,
       0,   458,     0,     0,   459,     0,   460,     0,   461,     0,
     462,     0,   463,   464,     0,   465,   466,   467,  1100,     0,
       0,   468,     0,   469,   470,     0,   471,     0,     0,     0,
       0,     0,     0,     0,   472,   473,     0,     0,     0,     0,
       0,     0,     0,   929,     0,     0,  1101,   474,     0,     0,
     475,   476,     0,     0,   477,   478,     0,     0,   479,   480,
    1097,     0,     0,     0,     0,  1102,     0,   481,   482,   483,
       0,   484,     0,     0,     0,  1098,     0,     0,     0,  1099,
    1735,   485,   486,   487,     0,   488,     0,     0,     0,   489,
     490,     0,     0,     0,   491,     0,     0,     0,     0,     0,
       0,     0,   492,     0,     0,     0,     0,     0,     0,     0,
     493,   494,   495,     0,     0,     0,     0,  1100,   496,   497,
       0,     0,     0,     0,   498,     0,     0,   499,     0,     0,
       0,   500,   501,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   502,     0,     0,  1101,     0,  1103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     503,     0,     0,     0,  1102,     0,     0,     0,   504,     0,
       0,     0,     0,     0,   505,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
       0,     0,     0,     0,   506,     0,   507,   508,     0,     0,
       0,     0,     0,     0,  1104,   509,     0,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1103,     0,     0,     0,
       0,     0,     0,     0,   510,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   511,     0,     0,     0,   512,
       0,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,   514,   515,  1092,
    1093,  1094,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1104,   517,     0,     0,     0,     0,     0,
     518,   519,   520,   521,     0,     0,     0,   522,     0,     0,
       0,   523,     0,     0,     0,     0,     0,     0,   524,   525,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     526,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,   529,     0,     0,   530,     0,
       0,     0,     0,     0,   531,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     532,     0,     0,   533,     0,     0,     0,     0,     0,   534,
       0,     0,   535,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,     0,     0,
       0,     0,     0,     0,   538,     0,     0,     0,     0,     0,
    1095,     0,     0,  1096,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,   540,   541,
     542,   543,   544,   545,     0,     0,   546,     0,   547,     0,
     548,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,     0,     0,
    1868,  1869,     0,  1870,     0,     0,   268,  1871,  1872,    40,
       0,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,  1873,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1086,  1087,  1088,
    1089,  1090,  1091,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1092,  1093,  1094,     0,     0,     0,     0,
       0,     0,  1097,     0,     0,     0,     0,  1086,  1087,  1088,
    1089,  1090,  1091,     0,     0,     0,     0,  1098,     0,     0,
       0,  1099,  1744,  1092,  1093,  1094,     0,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,     0,     0,
       0,     0,     0,   691,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,     0,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1086,  1087,  1088,
    1089,  1090,  1091,     0,  1095,     0,     0,  1096,     0,     0,
       0,     0,     0,  1092,  1093,  1094,     0,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,  1095,     0,     0,  1096,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2029,  1103,     0,
       0,     0,     0,     0,     0,     0,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,  1096,     0,  1104,  1097,     0,     0,     0,
       0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
       0,  1098,     0,     0,     0,  1099,  1749,     0,  1092,  1093,
    1094,     0,     0,     0,  1095,     0,  1097,  1096,  1874,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   830,
       0,  1098,     0,  1875,     0,  1099,  1757,     0,   831,     0,
       0,     0,     0,  1100,     0,     0,     0,   832,     0,     0,
    1876,     0,   833,  2030,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2031,  1878,     0,     0,     0,
       0,  1101,     0,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1102,     0,     0,     0,  2200,     0,   834,     0,     0,     0,
    1095,  1101,  1097,  1096,   835,     0,     0,  1880,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,     0,  1881,
    1102,  1099,  1759,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1097,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1095,
       0,  1098,  1096,     0,     0,  1099,  1760,     0,     0,  1100,
     836,  1882,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1103,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   837,     0,  1101,     0,     0,
       0,     0,   838,  1100,   839,     0,     0,     0,     0,     0,
    1883,     0,  1103,     0,   840,     0,  1102,     0,     0,     0,
       0,     0,  1884,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,  1097,     0,  1885,  1886,  2032,     0,     0,     0,
     841,     0,     0,  1887,     0,     0,  1888,  1098,   842,  1104,
    1102,  1099,  1761,     0,   271,     0,     0,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,     0,     0,     0,     0,     0,  1104,
       0,  1097,     0,     0,     0,   843,     0,     0,     0,  1100,
       0,     0,     0,     0,     0,     0,  1098,     0,  1103,     0,
    1099,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   844,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,  1103,     0,     0,     0,  1102,     0,  1100,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,   845,
       0,  1763,     0,     0,     0,     0,     0,     0,     0,     0,
     846,     0,     0,     0,     0,  1104,  1101,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,     0,  1102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1092,
    1093,  1094,     0,     0,     0,     0,     0,     0,     0,     0,
     847,   848,   849,     0,     0,     0,     0,  1103,     0,     0,
       0,     0,     0,   850,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,  1096,     0,  1104,     0,  1070,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1083,  1084,  1085,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,     0,
       0,     0,     0,     0,  1104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1092,
    1093,  1094,     0,     0,     0,     0,     0,   851,  1086,  1087,
    1088,  1089,  1090,  1091,     0,     0,     0,     0,     0,     0,
    1095,     0,     0,  1096,  1092,  1093,  1094,     0,     0,     0,
       0,     0,  1097,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,     0,  1098,     0,     0,
       0,  1099,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1085,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,     0,     0,     0,     0,     0,  1086,  1087,  1088,  1089,
    1090,  1091,  1764,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1092,  1093,  1094,     0,     0,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1086,
    1087,  1088,  1089,  1090,  1091,     0,  1102,     0,     0,     0,
    1095,     0,  1097,  1096,     0,  1092,  1093,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1098,     0,     0,
       0,  1099,     0,     0,     0,  1095,     0,     0,  1096,     0,
       0,     0,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1767,     0,     0,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,  1101,     0,     0,
       0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
       0,     0,     0,     0,     0,     0,  1102,     0,  1092,  1093,
    1094,     0,     0,  1095,     0,     0,  1096,     0,     0,     0,
       0,     0,  1097,     0,     0,     0,     0,   716,   717,     0,
       0,     0,     0,   268,   718,   719,    40,  1098,     0,     0,
       0,  1099,     0,     0,     0,  1104,  1095,  1097,     0,  1096,
     720,     0,     0,     0,     0,   721,     0,     0,     0,     0,
       0,   722,  1098,     0,     0,     0,  1099,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1100,
       0,     0,     0,     0,   158,     0,     0,     0,  1103,   723,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1100,     0,     0,  1101,     0,     0,
       0,     0,     0,     0,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,     0,   159,     0,     0,  1102,     0,     0,     0,
       0,     0,  1101,     0,     0,  1097,     0,     0,     0,     0,
       0,     0,   160,     0,     0,     0,     0,     0,     0,  1095,
    1098,  1102,  1096,     0,  1099,  1104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1097,     0,
       0,     0,  1086,  1087,  1088,  1089,  1090,  1091,     0,     0,
      81,   161,   724,  1098,     0,     0,     0,  1099,  1092,  1093,
    1094,     0,  1100,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     0,     0,     0,     0,  1103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1101,   164,     0,     0,     0,  1100,     0,     0,     0,     0,
       0,   165,     0,  1103,     0,     0,     0,     0,     0,  1102,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
       0,     0,     0,  1101,   716,   717,     0,     0,     0,     0,
     268,   718,   719,    40,     0,     0,     0,     0,     0,     0,
       0,  1097,  1102,     0,     0,  1104,     0,   720,     0,   725,
       0,     0,   721,     0,   726,     0,  1098,   167,   722,     0,
    1099,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1104,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   168,   727,     0,     0,     0,   723,     0,     0,     0,
       0,  1103,     0,     0,     0,     0,   169,     0,  1100,  1095,
       0,     0,  1096,   170,     0,     0,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   728,     0,     0,
       0,     0,     0,     0,  1103,     0,  1101,   172,     0,   729,
     173,     0,   174,     0,   716,   717,     0,     0,     0,     0,
     268,   718,   719,    40,     0,  1102,     0,   730,     0,     0,
       0,   175,   731,     0,     0,   732,     0,   720,  1104,     0,
       0,     0,   721,     0,     0,     0,   733,     0,   722,   176,
       0,     0,   734,     0,     0,     0,     0,    81,     0,   724,
       0,     0,   735,     0,     0,     0,     0,   736,     0,     0,
     737,  1104,     0,   738,     0,     0,   723,     0,     0,     0,
       0,     0,   739,   740,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1097,     0,     0,     0,  1868,  1869,  1103,  1870,     0,
       0,   268,  1871,  1872,    40,     0,  1098,     0,     0,     0,
    1099,     0,     0,  1191,   741,     0,     0,     0,   742,     0,
       0,     0,     0,  1873,     0,     0,   743,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   744,     0,     0,
       0,     0,     0,   745,     0,     0,   725,     0,  1100,     0,
       0,   726,     0,     0,     0,     0,     0,    81,     0,   724,
       0,     0,     0,     0,  1104,     0,     0,     0,   746,     0,
       0,     0,     0,     0,     0,     0,  1101,     0,     0,   727,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   747,     0,   728,     0,     0,     0,     0,   748,
       0,   749,     0,     0,     0,     0,   729,     0,     0,     0,
       0,   750,   751,   752,     0,     0,     0,     0,     0,     0,
     753,     0,     0,     0,   730,     0,     0,     0,   691,   731,
       0,   271,   732,     0,     0,     0,   725,     0,   716,   717,
       0,   726,     0,   733,   268,   718,   719,    40,     0,   734,
       0,     0,     0,     0,     0,     0,     0,  1103,     0,   735,
       0,   720,     0,     0,   736,     0,   721,   737,     0,   727,
     738,     0,   722,     0,     0,     0,     0,     0,     0,   739,
     740,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     723,     0,     0,     0,   728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   729,     0,     0,     0,
       0,   741,     0,     0,  1104,   742,     0,     0,     0,     0,
       0,     0,  2029,   743,   730,     0,     0,     0,     0,   731,
       0,     0,   732,     0,   744,     0,  2134,     0,  1868,  1869,
     745,  1870,     0,   733,   268,  1871,  1872,    40,     0,   734,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   735,
       0,     0,     0,     0,   736,   746,  1873,   737,  1868,  1869,
     738,  1870,     0,     0,   268,  1871,  1872,    40,     0,   739,
     740,    81,     0,   724,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1873,     0,  1868,  1869,
       0,  1870,     0,     0,   268,  1871,  1872,    40,     0,   747,
       0,     0,     0,     0,     0,     0,   748,     0,   749,     0,
    2527,   741,     0,  1874,     0,   742,  1873,     0,   750,   751,
     752,     0,     0,   743,     0,     0,     0,   753,  1875,     0,
       0,     0,     0,     0,   744,     0,     0,     0,   271,     0,
     745,     0,     0,     0,     0,  1876,     0,     0,  2030,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2031,  1878,     0,     0,     0,   746,     0,     0,     0,     0,
     725,     0,     0,     0,     0,   726,     0,     0,     0,  1868,
    1869,   691,  1870,     0,     0,   268,  1871,  1872,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1880,   727,     0,     0,     0,  1873,     0,   747,
       0,   691,     0,     0,  1881,     0,   748,     0,   749,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   750,   751,
     752,     0,     0,     0,     0,     0,     0,   753,   728,     0,
       0,   691,     0,     0,     0,     0,     0,     0,   271,     0,
     729,     0,     0,     0,     0,     0,  1882,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   730,     0,
       0,     0,     0,   731,     0,     0,   732,     0,     0,     0,
       0,     0,     0,     0,     0,  2029,     0,   733,     0,     0,
       0,     0,     0,   734,     0,  1883,     0,     0,     0,     0,
       0,     0,     0,   735,     0,     0,     0,  1884,   736,     0,
       0,   737,     0,     0,   738,     0,     0,     0,     0,  1885,
    1886,  2032,     0,   739,   740,     0,     0,     0,  1887,     0,
       0,  1888,   691,     0,     0,  1868,  1869,     0,  1870,   271,
       0,   268,  1871,  1872,    40,  1868,  1869,     0,  1870,     0,
       0,   268,  1871,  1872,    40,     0,     0,     0,     0,     0,
       0,     0,     0,  1873,     0,   741,     0,     0,     0,   742,
       0,     0,     0,  1873,     0,     0,     0,   743,     0,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,   744,     0,
       0,     0,     0,     0,   745,     0,     0,     0,     0,     0,
       0,  1875,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,  1876,   746,
       0,  2030,     0,     0,     0,     0,     0,     0,     0,  1868,
    1869,  1875,  1870,  2031,  1878,   268,  1871,  1872,    40,     0,
       0,     0,     0,     0,     0,     0,  1874,     0,  1876,     0,
    1929,  1877,     0,     0,     0,     0,     0,  1873,     0,     0,
       0,  1875,     0,   747,  1878,     0,     0,     0,     0,     0,
     748,     0,   749,     0,     0,  1880,     0,     0,  1876,     0,
       0,  1877,   750,   751,   752,     0,     0,  1881,   691,     0,
       0,   753,     0,     0,  1878,     0,     0,     0,   691,     0,
       0,     0,   271,     0,  1879,  1880,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1881,     0,     0,
       0,     0,  2200,     0,     0,     0,     0,     0,     0,  1882,
       0,     0,     0,     0,     0,  1880,     0,  1874,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1881,     0,     0,
       0,     0,  1875,     0,     0,  2967,     0,     0,     0,  1882,
       0,     0,     0,     0,     0,     0,     0,     0,  1883,  1876,
       0,     0,  2908,     0,     0,     0,     0,     0,     0,     0,
    1884,     0,   691,     0,     0,  1878,     0,     0,     0,  1882,
       0,     0,  1885,  1886,     0,     0,     0,     0,  1883,     0,
       0,  1887,     0,     0,  1888,     0,     0,     0,     0,     0,
    1884,  2968,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1885,  1886,     0,  2909,  1880,     0,  1883,     0,
       0,  1887,     0,     0,  1888,     0,  2969,     0,  1881,     0,
    1884,     0,   271,     0,     0,  2970,     0,     0,     0,     0,
       0,     0,  1885,  1886,     0,     0,     0,     0,     0,     0,
       0,  1887,     0,     0,  1888,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
    1882,  2971,     0,     0,  1930,     0,     0,     0,     0,  2972,
       0,     0,     0,  1874,     0,     0,     0,  1931,     0,     0,
       0,     0,     0,  1874,     0,     0,     0,     0,  1875,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1875,  1883,
       0,     0,     0,     0,     0,  1876,     0,     0,  1877,     0,
       0,  1884,     0,     0,     0,  1876,     0,     0,  1877,     0,
       0,  1878,     0,  1885,  1886,     0,     0,     0,     0,     0,
       0,  1878,  1887,     0,     0,  1888,     0,     0,     0,     0,
       0,  1932,     0,   271,     0,     0,     0,     0,  1933,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2909,  1880,  2973,     0,     0,     0,  1874,     0,     0,
       0,  3002,  1880,     0,  1881,     0,     0,     0,     0,     0,
       0,     0,  1875,     0,  1881,     0,     0,  1934,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1876,
       0,     0,  1877,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1935,     0,     0,  1878,  1882,     0,     0,     0,
       0,     0,  1936,  1937,     0,     0,  1882,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1938,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1883,  1880,     0,     0,     0,
    1939,     0,     0,  1940,  1941,  1883,     0,  1884,  1881,  1942,
       0,     0,     0,     0,     0,     0,     0,  1884,     0,  1885,
    1886,     0,     0,     0,     0,     0,     0,     0,  1887,  1885,
    1886,  1888,     0,     0,     0,     0,     0,     0,  1887,   271,
       0,  1888,     0,     0,     0,     0,     0,     0,     0,   271,
    1882,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1943,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2974,     0,  1944,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1883,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1884,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1885,  1886,     0,     0,     0,     0,     0,
       0,     0,  1887,     0,     0,  1888,     0,     0,     0,     0,
       0,     0,     0,   271
};

static const short yycheck[] =
{
       2,   710,   829,   706,   327,   187,   193,   858,  1255,   980,
      12,    13,   444,   211,   840,   417,  1550,   419,   420,   994,
      65,   987,   421,   825,   506,   921,   514,  1401,  1489,    81,
     512,   433,   496,  1686,   516,  1737,     0,   175,  1733,   935,
     362,  1690,    44,    45,  1855,  1266,  1267,   153,  2072,   451,
     836,   837,   454,   839,   542,   841,   842,   545,   460,    23,
    1366,   520,   464,  1010,   866,    29,   468,  1355,  1298,  1369,
     472,  1796,   117,    75,   476,   477,    78,   479,   781,  1609,
     482,   263,   484,   485,   486,    61,   224,   732,    90,   478,
     492,    26,     5,   495,   503,    97,    26,     5,    26,   101,
     502,    65,   104,   105,   503,   507,   538,     5,   110,   111,
      20,  2161,   387,   515,    26,    80,    26,  1928,    94,     5,
      23,     5,    25,     5,   526,   952,     5,   954,   530,    20,
     236,   237,   534,    24,    24,    26,    26,    24,   540,    26,
      48,   543,    50,    24,    52,    26,    24,   149,    26,     5,
     152,    45,   339,   117,    18,   157,    24,    25,    26,    23,
      24,    25,    32,    23,   140,    25,    32,    43,   144,   507,
      43,    23,    56,    25,    78,     5,    17,    18,    62,     5,
      18,   445,    23,    24,    25,    26,  1022,    25,  1055,    17,
      18,   142,    23,   195,    25,    23,    24,    25,    26,     5,
      24,     5,    26,   467,     5,  2427,    25,    26,   417,    46,
      26,    20,    17,    18,    26,    24,   925,    26,    23,    24,
      25,    26,    67,    68,     5,  1874,    24,     5,    26,    26,
       5,   233,    17,    18,  1916,  2591,    71,   239,    23,    24,
      25,  2254,   451,     6,    24,   454,    26,   511,   250,    26,
     226,    23,    24,    25,    26,   464,     5,   521,   522,   468,
     129,   525,  1621,   472,     5,   529,   324,   531,    26,     5,
     479,   535,     5,   537,    26,   484,     5,   486,    23,    24,
      25,    26,    24,   492,    26,    22,   495,    17,    18,   170,
    2796,   371,   170,   502,     5,    25,    26,   114,   507,   169,
     170,    22,    26,   279,   170,   281,   515,   527,  2530,   129,
     286,    23,    24,    25,    26,  1968,     5,   526,   363,   364,
      17,   530,   215,    26,   557,   534,  2755,   691,   142,   170,
    2908,   540,   369,   155,   543,     6,   358,  1798,  2205,  2206,
    2207,  2208,   170,     5,   366,     0,   170,   519,  2777,    30,
     410,   170,  1203,   355,  2165,   519,   358,   371,    26,   335,
      26,  2790,   519,    28,   366,   598,   410,  2409,   254,     5,
     418,   313,   170,   324,     6,   254,   352,  2030,   438,   599,
     382,   429,   384,  2407,   410,  2409,    83,   120,     5,   411,
      29,   405,     5,   437,  1369,   457,   568,    36,   170,   363,
     364,     5,    41,   187,   568,   606,    37,    38,   470,   411,
     418,   568,    27,    28,   416,     5,   418,   254,   170,   421,
     422,   429,   424,   365,   354,   427,     5,   829,   629,   251,
      27,   890,     5,    64,    65,    66,   438,  1681,  1682,   607,
     170,  1685,     5,   445,   333,     5,    85,    86,    17,    18,
      19,    20,    21,  1162,    93,   457,     5,     5,   170,   847,
     848,     5,     5,   102,   103,   467,   105,   106,   470,     5,
     228,   110,  2029,   367,  2031,  2904,   228,   214,   480,   250,
       5,     5,   253,     5,   255,   375,     5,   324,   127,   128,
     570,  3069,   601,   214,   496,   497,     5,     5,   392,     5,
       5,   503,  2184,  3009,   275,  1660,   145,   146,  1663,   511,
     324,   513,   514,     5,   285,    26,     5,   329,   576,   521,
     522,     5,   524,   525,     5,   527,     5,   529,     5,   531,
     115,   116,   369,   535,   375,   537,     5,   539,  2588,   541,
     542,  1785,   544,   545,   420,   547,  1034,   375,    26,   390,
     952,   953,   954,   875,   489,   877,   327,  2913,  2253,   225,
     331,   825,   390,  2576,  1028,     5,     5,  1031,  1032,  1033,
     375,   329,   238,     5,   525,     5,   406,     5,  1952,     5,
    1801,   607,   476,     5,  1451,   390,  1050,  1454,  1291,  1292,
     375,  2125,   485,     5,   410,   379,   860,  1300,     9,  1008,
     254,   410,   866,   640,  1963,   390,    84,   558,   371,  1008,
     451,   576,   542,    26,   878,   953,  2658,   353,   321,   883,
     829,   342,  1961,   527,   598,   406,   329,   330,   406,  2653,
     410,   406,  2656,   410,  2658,  2169,   520,   506,   409,   451,
    1343,  1005,   371,  2177,  2178,   442,   648,   523,   971,   531,
     523,   354,   364,   451,   357,  1143,   134,   406,   570,   170,
     371,   329,   481,   549,   534,   406,  1502,  2889,   534,  1565,
     549,  1130,   375,    26,   676,   569,   678,   494,     5,   557,
     410,   537,   371,  1142,  1148,   566,   506,   581,   582,   691,
     461,   599,   170,   451,   172,   671,   590,   972,   601,   607,
     371,   599,   593,   593,   706,   531,   593,   531,   347,   371,
     346,  2522,   549,   648,   716,   717,   535,  1126,   648,  2249,
     648,  1965,  2944,   527,   608,   593,   527,  1126,   534,   731,
     643,  1195,   570,  1221,   373,   737,   738,   601,   648,   371,
     742,   601,  1131,   952,   953,   954,  1976,  2797,  1992,   601,
     752,  1726,  2454,   495,   371,   467,  1220,  1239,   371,  2484,
     601,  1225,   607,  2488,  2052,  2778,  2779,   371,  1715,  2075,
     601,  1416,  2994,   601,  2996,  1263,  1264,  2077,   481,   781,
       5,   371,  2026,  1215,   593,   620,   621,   622,   623,   624,
     456,   269,   371,   630,   631,   632,   601,   433,   371,   319,
    1188,  1776,  2826,   434,   641,   444,   472,    22,   371,    26,
    1637,   371,   225,   311,   450,  2655,   601,    24,   229,    26,
    1007,   369,   371,   825,   826,   238,  2200,   371,   371,   601,
    2855,   416,   535,  2700,    26,   371,  2531,   406,  2846,   542,
    2848,    17,    18,    19,    20,    21,   371,   371,  2003,   371,
     596,  2408,   371,   364,  2411,   148,   601,   493,   860,   337,
     319,   438,   371,   371,   866,   371,   371,   345,  1132,  1133,
    1134,   349,   225,   438,   645,   137,   878,   983,     0,   371,
     986,   883,   371,   438,  2533,   238,   888,   371,  1152,   601,
     371,   522,   371,   250,   371,   549,   253,   533,   255,   538,
     262,    23,   371,   137,   906,    24,   339,    26,   386,   319,
      24,  1393,    26,   275,  2938,   275,  2255,  2256,   275,   921,
    1379,    20,   222,  2144,  1627,  1189,   562,    26,   285,   304,
     340,   371,   371,   935,   565,   571,   263,  2962,   262,   371,
     526,   371,     5,   371,   530,   371,   333,   304,   534,   371,
    1214,   275,  1004,   170,   600,   366,   143,   368,  2202,   371,
     147,   607,  2773,   170,  1146,  2430,     5,  1231,  2433,  1451,
     327,    24,  1454,    26,   331,     5,   454,  1241,   170,  2513,
     619,    17,    18,    19,    20,    21,   988,   438,   627,   275,
     992,   993,   994,   570,  2834,  1821,   494,   410,    24,   214,
      26,     5,   335,  1005,    24,    25,  1008,   505,  1010,  1011,
      25,    26,  1014,  1501,   276,   493,    13,    24,  3026,    26,
     451,   410,  2266,   456,   601,    92,  1028,  1029,   459,  1031,
    1032,  1033,  1034,   516,  1036,   304,   601,  1039,   263,   559,
     518,   327,   276,   456,   339,   331,   601,   409,  1050,   409,
    1052,   170,   409,   502,  1056,  1906,    24,   410,    26,   472,
     410,  2027,  1064,   250,  1066,  1067,   253,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,   562,   409,   461,  2782,   275,  1548,
     352,   130,  1494,   571,  1096,  1097,    25,    26,   844,  1101,
     559,  1103,  2077,   456,   461,   851,   438,  2756,  2074,  2758,
      16,    17,    18,    19,    20,    21,  1118,   170,   352,   472,
    1608,   437,   438,   409,  1126,   418,   130,   342,  1592,  1593,
    1132,  1133,  1134,   566,   102,   103,   429,   105,   106,   410,
    1967,  1143,   110,  1145,   170,  1147,  1148,   364,   410,   559,
    1152,  1289,   437,   438,  1613,   170,    20,  1295,   451,   127,
     128,   456,    26,   170,  1991,   458,    72,    73,    74,    75,
      76,    77,   410,    24,  2418,    26,  2420,   145,   146,   315,
      20,   514,    88,    89,    90,   143,    26,  1189,    20,   147,
     326,  2087,   461,  1195,    26,   528,   143,    24,   410,    26,
     147,    20,   170,    20,    24,  2579,    26,    26,  1472,    26,
     472,    20,  1214,   171,  1616,  1537,  1218,    26,  1220,  1221,
     553,    98,   409,  1225,   171,  1331,   405,  1229,  1230,  1231,
     406,   606,  1496,   418,  1340,  1637,  1500,   541,   472,  1241,
     544,   170,   378,   547,   429,  1727,    25,  1950,   216,    20,
     625,   626,    24,  1255,    26,    26,    24,   393,    26,  1718,
    1262,  1263,  1264,  2916,   267,   268,   451,  1531,   218,   602,
     645,   566,  2016,   458,    18,   410,  2901,   218,  2022,    23,
      24,    25,  2907,   195,   410,  1494,  1288,   199,   645,  1291,
    1292,  1994,   250,  1557,  1296,   253,  1298,    18,  1300,  2952,
     438,   461,    23,   250,    25,     9,   253,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   275,  1777,   170,
    1779,   486,   606,   229,   201,   275,   232,   346,   275,  1788,
     495,   410,   209,  2577,   275,   371,   410,   606,   215,   606,
     217,  1343,   410,   170,   628,   629,    24,   483,    26,   250,
     170,   228,   253,  1355,   255,  2599,   625,   626,    25,    29,
    1336,   628,   629,    44,  1366,   621,   622,  1369,    72,    73,
      74,    75,    76,    77,   275,   540,   645,   327,   543,   256,
     346,   331,   623,   624,   285,  1867,   327,  1389,  1390,  1391,
     331,  2193,    88,    89,    90,   272,   410,  2248,   170,    24,
     277,    26,   170,   304,   139,   410,  2653,  1616,  2066,  2656,
    2068,  2069,   289,   607,   433,  2876,    24,   607,    26,   296,
     454,   156,   157,  1425,  1426,  1427,   327,  1429,  1637,   164,
     331,   450,   102,   103,   468,   105,   106,    24,   472,    26,
     110,   630,   631,   845,   846,   351,   606,   849,   850,   417,
     484,   409,  2986,  1455,    25,  1719,  1458,   127,   128,   409,
     366,    25,   409,   198,   370,   625,   626,   433,   409,    25,
    1472,  2446,   207,  2439,   493,   145,   146,   620,  2883,  2884,
     623,   624,   630,   631,   450,   645,    25,    25,  1490,   594,
     595,   596,   597,   410,  1496,   601,  1498,  1499,  1500,  1501,
    1899,   236,   408,  2964,   438,    53,    54,   346,   409,    57,
      58,    59,    25,    24,   533,    26,  1780,  1781,  1782,  1783,
     437,   438,  2983,   410,    23,    25,    25,   493,   232,  1531,
     436,   443,   444,    23,  1536,    25,    23,    25,    25,    25,
    1804,  2785,    25,   562,  1546,  1743,   281,    25,  1550,   455,
     437,   438,   571,   601,    39,  1557,  1127,   371,  1129,  1961,
     461,   410,    25,  1565,   341,  1967,   601,   533,   410,  1571,
    1572,     5,  1574,   420,   451,   410,   406,  1979,  3039,   371,
    2985,   458,  2987,   601,   501,    25,   433,   238,   323,  1991,
    1592,  1593,   341,   406,   433,   371,   562,  1861,   279,    20,
      25,    25,    25,   480,    20,   571,  1608,    25,   485,   157,
      25,   450,  2856,   460,   501,   410,   164,    25,    25,    25,
     102,   103,  2081,   105,   106,  1627,   538,   601,   110,   476,
     477,   537,   371,  1635,     5,   482,   548,   371,   485,   371,
     282,  2612,   371,   371,  1646,   127,   128,   351,   371,   371,
     198,   605,     5,  2504,   493,   371,   337,  1659,  1660,   207,
       7,  1663,   282,   145,   146,   371,   336,   371,   349,  2128,
      17,    18,    19,    20,   371,   605,  2502,  1679,   359,  1681,
    1682,   371,   371,  1685,  1686,    19,    20,    21,   236,   237,
     410,  2938,   601,   113,   533,   438,   377,   601,   604,    17,
      18,    19,    20,    21,   408,   598,   387,     8,   406,   390,
    1712,   459,   506,  1715,   400,   385,   410,  1719,  1982,   410,
    1984,   246,   403,   562,  1726,    72,    73,    74,    75,    76,
      77,  1733,   571,   281,   216,   410,   410,   410,    72,    73,
      74,    75,    76,    77,   645,   410,   410,  2450,   410,   410,
     410,   410,  1961,    20,    88,    89,    90,   410,  1967,   179,
     410,   181,   410,  1765,   410,   410,  1768,   410,   439,   410,
    2234,   452,  2236,   410,  1776,   323,   196,   410,  1780,  1781,
    1782,  1783,  1991,  1785,   204,     5,  3030,   410,   208,  1791,
    1792,   410,   410,  1795,  1796,    42,   410,   599,   710,   219,
    2509,   482,  1804,   599,   346,    72,    73,    74,    75,    76,
      77,   492,  1814,   233,   576,   400,   640,     9,   439,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   410,
    1744,   379,   513,   537,  1748,   516,   640,   518,   306,  1753,
       8,   577,     5,  1757,   756,  1759,  1760,  1761,     5,   363,
     410,   410,   410,  2255,  2256,   410,   410,   324,    24,  1861,
     570,     8,    13,   556,   559,   546,   113,     5,  2719,     5,
    2134,   640,   400,  2137,   555,  1877,  2727,   640,   410,   583,
      72,    73,    74,    75,    76,    77,  1888,    17,    18,    19,
      20,   433,   410,    25,    25,   229,    46,  1899,   232,    71,
     604,   438,   438,    17,    18,  1907,    20,    25,   450,    23,
      24,    25,    26,     5,  2346,  2347,  2348,     5,  2350,  2351,
    2352,  2353,  2354,  2355,   576,   601,   570,  2359,   451,  2193,
     410,    45,   179,   410,   181,   417,   410,    20,    17,    18,
      19,    20,    72,    73,    74,    75,    76,    77,  1950,   196,
     607,   493,    20,   410,   410,   410,   410,   204,   607,   643,
     607,   208,   330,  1965,   537,    17,  1968,   606,    18,     5,
      25,  2016,    25,  1975,  1976,   198,   132,  2022,    24,   570,
    1982,   559,  1984,   462,     5,  2444,   233,   604,   601,  2692,
    1992,   533,  1994,    72,    73,    74,    75,    76,    77,     5,
     462,  2003,   346,   346,  2492,  2192,   527,   130,   527,    25,
     113,  2499,  2471,   925,   379,   301,    25,   351,   527,   410,
     562,   410,   410,  2874,  2026,   410,   410,   601,  2030,   571,
    2032,   371,   366,   346,   645,    29,   370,   557,   527,   371,
     232,  2043,   371,   371,   371,   371,  2255,  2256,   371,   371,
    2052,   371,  2016,    25,   371,   371,   170,   371,  2022,   410,
     607,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   598,     5,  2075,   408,  2077,   179,     5,   181,     5,
       5,   463,  2084,   607,   560,  2087,   601,   371,  2915,   433,
     433,   410,     5,   196,   606,   410,   534,    60,    25,   410,
      46,   204,   436,    25,   516,   208,   450,   450,   102,   103,
     305,   105,   106,     5,     5,   371,   110,   371,   284,   410,
     433,   455,  2124,  2125,   290,   291,   292,   410,   340,   577,
     233,    13,  2134,   127,   128,  2137,   607,   450,   400,   400,
    2142,    19,    20,  2846,   310,  2848,     5,  2998,   240,   493,
     493,   145,   146,  2155,   531,  2157,     5,  2159,   527,   351,
     641,    25,    80,   607,  2166,   410,   601,  2169,   410,   132,
     133,  2173,  2881,   606,     5,  2177,  2178,   620,   406,   406,
     493,  2967,  2968,  2969,  2970,  2971,  2972,   279,   440,   533,
     533,  2193,   440,   410,    72,    73,    74,    75,    76,    77,
    2202,   410,  2204,   537,   410,   410,   298,   410,  2210,  2211,
    2212,  2213,  2214,  2215,   410,     8,   408,   410,   562,   562,
     533,     5,    25,    25,   187,   570,   371,   571,   571,   371,
     193,  2495,  2234,    24,  2236,     4,     5,     6,     7,     8,
       9,   371,    11,    24,    24,   337,   371,    24,     5,   562,
    1162,  2253,   418,   601,  2718,   421,   371,   349,   571,     5,
    2524,   375,  2721,   601,  2266,   601,     8,   359,   305,  2271,
     604,    24,   405,   324,   438,   324,   390,   601,   340,   445,
     324,   410,   410,   438,   410,   377,   410,     5,  2611,  2553,
     410,   410,   371,   407,   410,   387,   410,   410,    25,   465,
     263,   632,   265,  1215,  2486,     5,     5,     5,   962,   423,
       5,   403,    25,   576,   410,     5,  2318,    72,    73,    74,
      75,    76,    77,  3026,   598,  2327,  2328,  2329,   564,   601,
     576,   601,     5,  2335,   500,     5,     5,   451,   410,     7,
     371,     5,   601,   607,    25,   537,    25,    25,   601,   463,
     464,   443,     8,   371,   520,   521,   607,   371,  1270,    25,
     570,   371,   476,   607,   371,   531,   371,   371,   371,    20,
     536,     5,   547,   254,   371,   467,   339,    13,    14,    15,
      16,    17,    18,    19,    20,    21,     5,  3096,     5,     5,
     482,   583,   527,   220,  2396,     5,  2398,   489,   371,   552,
     492,   601,   601,   607,   518,  2407,  2865,  2409,   420,   575,
     371,  2413,   604,   451,   410,     6,  2418,  2419,  2420,   607,
     607,   513,   534,   534,   516,   190,   518,   605,   605,    24,
      24,    24,    24,   600,   426,    24,    72,    73,    74,    75,
      76,    77,   608,   557,  2446,   537,    25,    25,  2450,    25,
      25,    25,    88,    89,    90,   569,   451,   410,   410,  2723,
    2462,    25,   276,   555,    25,     5,   429,   581,   582,   371,
     371,   506,   248,   570,     5,   410,   590,   448,   371,   593,
     220,    24,  2484,   531,   371,  2487,  2488,   601,     5,   406,
    2492,   371,   324,  2495,    20,   119,   420,  2499,    13,     5,
     463,    13,   601,   190,     5,   421,   469,   438,   471,   371,
     371,  2513,   475,  2915,    25,   478,   371,    25,   481,   371,
       5,   311,  2524,   348,   600,   410,   371,   353,   491,  2531,
     549,    25,   371,   371,   371,   410,   324,  2539,   371,   221,
    2542,  2543,  2544,  2545,  2546,   556,   607,   510,   527,    25,
     410,  2553,   219,   607,   219,   518,   519,   520,   371,   427,
      25,   524,   372,   410,   371,   371,   607,   601,  2570,   532,
       5,    13,   406,     5,   607,  2577,     5,   371,  1574,    24,
     221,   410,     5,  2172,  2586,   548,   371,  2084,   371,  2591,
    2124,  3049,  1851,   229,  1232,  1558,   232,  2599,    36,  2601,
     363,    38,  2155,  1798,  1792,   140,   286,   144,   208,   280,
    1335,   287,  1336,   395,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   352,   370,   210,  1751,   382,  2457,  1531,   315,  1635,
     314,   384,  3039,  1768,  1657,    17,    18,    19,    20,  1406,
     524,  2653,   959,  1664,  2656,  1782,  2658,  1500,  1262,  2661,
    2556,  2229,  1574,  1265,  1588,  3063,  1903,  1603,  1322,  1323,
    1786,  2243,  2735,  1148,    23,  1329,   117,    29,  2245,  2633,
    1563,    72,    73,    74,    75,    76,    77,    29,   650,   481,
    2692,  1569,  1242,   265,  2696,   678,  2698,    88,    89,    90,
      72,    73,    74,    75,    76,    77,  2915,  1270,  1901,  1572,
     926,  2630,  2811,  1139,  2978,   351,  2718,  1186,  2983,  1619,
    2211,  2723,  2386,  1635,  1129,  2821,   878,  1060,  2384,  2025,
     366,  2368,  1014,  1776,   370,  1961,  1372,  1733,  2795,  1349,
    3065,  1214,   716,   717,  3030,  1995,  2921,   710,  2417,  2026,
    1685,  2692,  2451,  2396,  2398,  2656,  2032,   731,  2938,  2761,
    2667,  2043,  1288,   737,   738,  2329,   955,  1679,   742,  2857,
    2572,  2858,   408,  2267,  1686,  2271,  3028,  2826,   752,  1284,
    2782,  2210,  2899,  2785,  1715,  1257,   951,  2586,  1144,  2791,
     361,    -1,    -1,  2795,  2796,    -1,    -1,    -1,    -1,    -1,
     436,  2803,    -1,    -1,    17,    18,    19,    20,    -1,    -1,
      -1,    17,    18,    19,    20,   778,    -1,  3081,    -1,   455,
      -1,  1733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    20,
      21,   232,    -1,    -1,  2846,    -1,  2848,    -1,    -1,  2851,
      -1,    -1,    -1,    -1,  2856,    -1,  2858,    -1,   821,    72,
      73,    74,    75,    76,    77,    -1,    72,    73,    74,    75,
      76,    77,   835,   836,   837,    -1,   839,    -1,   841,   842,
      -1,  1877,    -1,    -1,   847,   848,    -1,  1541,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,  2899,    -1,    -1,
      -1,   537,    -1,    -1,  2906,    -1,  2908,    88,    89,    90,
      -1,  2913,    -1,    -1,  2916,    -1,    -1,    -1,    -1,  2921,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   890,    -1,    -1,
    1584,    -1,    -1,    -1,    -1,    -1,  2938,    -1,   901,    -1,
    2942,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    -1,
    2952,    -1,    -1,    -1,    -1,    -1,  1868,  1869,    -1,    -1,
     351,    -1,   925,   926,    -1,  1877,    -1,    -1,   604,    -1,
      -1,   934,    -1,    -1,    -1,   366,  2978,  2979,    -1,   370,
      17,    18,    19,    20,  2986,    -1,    -1,   950,   951,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   371,
      72,    73,    74,    75,    76,    77,    -1,  3009,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,    -1,    -1,
      -1,    -1,    -1,    -1,  3026,    -1,  3028,    -1,  3030,    -1,
      -1,    -1,    -1,    -1,  2030,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,  1007,   436,    -1,    -1,   229,    -1,
      -1,   232,    -1,    -1,    -1,  1029,  1968,    -1,    -1,    -1,
      -1,    -1,  1036,  3065,   455,  1039,    -1,  3069,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,  3081,
      -1,    -1,  1056,    21,    -1,    -1,    -1,    -1,    -1,    -1,
    1064,    -1,  1066,  1067,    -1,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,
    1084,  1085,    -1,    -1,    -1,    -1,    -1,    -1,  2030,    -1,
    2032,    -1,  1096,  1097,    -1,    -1,    -1,  1101,    -1,  1103,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,  1119,    -1,   371,    -1,
    2072,    -1,    -1,    -1,  1127,   371,  1129,  1130,  1131,    -1,
     351,    -1,    -1,    -1,    -1,  1138,  1139,    -1,    -1,  1142,
      -1,    -1,    -1,  1146,    -1,   366,  1149,    -1,    -1,   370,
      -1,  1845,  1846,    -1,    -1,    -1,    -1,    -1,    -1,  1162,
      -1,    -1,  1856,    -1,    -1,    -1,    -1,    -1,  2204,    -1,
      -1,    -1,    -1,   604,  2210,  2211,  2212,  2213,  2214,  2215,
      -1,    -1,    -1,    -1,    -1,  1188,    -1,   408,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,    -1,   436,    -1,  2253,  1912,  1913,
    1914,  1915,    -1,    -1,  1227,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1927,   455,  2271,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1251,    -1,
      -1,   229,  2204,  1256,   232,    -1,    -1,    -1,  2210,  2211,
    2212,  2213,  2214,  2215,    -1,    -1,  1269,  1270,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,   371,    -1,    -1,    -1,    -1,    -1,
      -1,  2253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2004,  2005,    -1,    -1,    -1,    -1,   537,  2011,  2012,  2271,
      -1,  1324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   229,    -1,
      -1,   232,    -1,    -1,    -1,    88,    89,    90,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,   351,    -1,    -1,  1379,  2413,    -1,    -1,
      -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,   366,    -1,
      -1,    -1,   370,    -1,  2346,  2347,  2348,    -1,  2350,  2351,
    2352,  2353,  2354,  2355,    -1,    -1,    -1,  2359,    -1,    -1,
      -1,  1425,  1426,  1427,    -1,  1429,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     408,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,  1455,    -1,    -1,  2396,    -1,  2398,    -1,    -1,    -1,
      -1,  2145,  2146,    -1,    -1,  2407,    -1,  2409,   436,    -1,
    2154,  2413,    -1,    -1,    31,    -1,    -1,    -1,  2162,    -1,
     351,    -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   366,    -1,  2181,  2182,   370,
      -1,    -1,    -1,    60,    61,  2531,   229,    -1,    -1,   232,
      -1,    -1,    69,  2539,    -1,    -1,  2542,  2543,  2544,  2545,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,  1536,    -1,    -1,    -1,  1529,   408,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1538,  1550,    -1,    -1,    -1,
      -1,  2235,    -1,  2237,    -1,  1548,    -1,    -1,    -1,    -1,
    2244,    -1,  2246,    -1,    -1,   436,    -1,  2509,    -1,   537,
      -1,    -1,    -1,    -1,    -1,    -1,  1569,    72,    73,    74,
      75,    76,    77,    -1,   455,    -1,    -1,   229,    -1,  2531,
     232,    -1,    -1,    88,    89,    90,    -1,  2539,    -1,    -1,
    2542,  2543,  2544,  2545,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1613,  1614,  1615,    -1,    -1,    -1,  1619,    -1,   351,    -1,
      -1,    -1,    -1,    -1,    -1,  2661,   604,    -1,    -1,    -1,
      -1,    -1,    -1,   366,    -1,    -1,    -1,   370,    -1,    -1,
      -1,    -1,  2336,  2337,    -1,    -1,  2340,  2341,  1651,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   240,    -1,   408,    -1,    -1,    -1,    -1,
    2374,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,
      -1,  2653,    -1,   436,  2656,    -1,  2658,    -1,    -1,  2661,
      -1,    -1,   279,    -1,   366,  1718,    -1,    -1,   370,    -1,
      -1,    -1,   455,   604,   229,  2761,    -1,   232,    -1,    -1,
      -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2782,   314,    -1,    78,
      -1,  1765,    -1,    -1,  1768,  2791,   408,    -1,    -1,    -1,
    2796,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   421,
     337,    -1,    -1,    -1,  1777,    -1,  1779,    -1,    -1,    -1,
      -1,    -1,   349,    -1,   436,  1788,    -1,    -1,    -1,    -1,
      -1,  2485,   359,    -1,    -1,  2489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,   537,    -1,    -1,    -1,    -1,  2761,
     377,    -1,    -1,    -1,    -1,  2851,    -1,    -1,    -1,    22,
     387,    -1,    -1,  1826,    -1,    -1,  2520,    -1,    -1,    -1,
    2782,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,  2791,
      43,    -1,    -1,    -1,  2796,    -1,   351,    -1,    -1,    -1,
      -1,    -1,  1855,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2554,   366,    -1,    -1,    -1,   370,    -1,    -1,    71,    -1,
    2906,   604,  2908,    -1,  2826,    -1,   443,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1900,  1901,  2851,
     467,    -1,    -1,   408,    -1,    -1,  2942,    -1,    29,    -1,
     113,    -1,    -1,    -1,    -1,   482,    -1,    -1,    -1,    -1,
      -1,    -1,   489,    -1,    -1,   492,    -1,    -1,    -1,  2881,
      -1,   436,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,   147,    -1,   513,    -1,    -1,   516,
     455,   518,   604,    -1,  2906,    -1,  2908,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2916,    -1,    -1,    -1,   171,    -1,
     537,    -1,    -1,  3009,    -1,    -1,   179,    -1,   181,    -1,
      -1,   102,   103,   312,   105,   106,  2938,   190,   555,   110,
    2942,    -1,  3028,   196,    -1,    -1,   325,    -1,    -1,  2002,
    2952,   204,    -1,    -1,    -1,   208,   127,   128,    -1,    -1,
      -1,   214,    -1,    -1,    -1,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,   145,   146,    -1,    -1,    -1,  3065,
     233,   598,   537,  3069,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,    -1,
     253,    -1,   255,    -1,    -1,    -1,    -1,  3009,  2752,   262,
     389,    -1,    -1,    -1,    -1,    -1,    -1,   396,    -1,    -1,
      -1,    -1,   275,    -1,    -1,    -1,  3028,    -1,  2081,    -1,
      -1,    -1,   285,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,    -1,   604,
      -1,   304,   305,    -1,    -1,    -1,   435,    -1,    -1,    -1,
    2124,  2125,    -1,  3065,    -1,    -1,   319,  3069,    -1,    -1,
      -1,    -1,    -1,    -1,   327,  2128,    -1,    -1,   331,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   340,   341,   342,
      -1,   470,   471,    -1,  3096,    17,    18,    19,    20,    -1,
      -1,    -1,  2166,    -1,    26,  2169,    -1,   486,  2161,    -1,
      -1,    -1,    -1,  2177,  2178,    -1,    -1,  2170,    -1,  2172,
      -1,  2174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,
      -1,    -1,   511,   512,  2187,    -1,    -1,    -1,   517,  2192,
      -1,  2885,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,   409,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   336,    -1,   420,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2926,  2927,    -1,  2929,    -1,  2931,  2932,    -1,
      -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   586,   461,    -1,
      -1,    -1,    -1,    -1,   385,    -1,    -1,    -1,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   417,    -1,    -1,    -1,
      -1,    -1,    -1,  2997,    -1,    -1,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     523,    -1,    -1,  3017,    -1,  3019,    -1,  2330,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      88,    89,    90,    -1,    -1,    -1,   559,    -1,    -1,    -1,
    3054,    72,    73,    74,    75,    76,    77,  2370,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
    2383,  3075,  3076,    -1,    -1,  3079,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   606,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   620,   621,   622,
     623,   624,   625,   626,    -1,   628,   629,    -1,   300,   301,
     302,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2444,   645,    -1,    -1,    -1,    -1,    -1,  2462,    -1,
      -1,    -1,    -1,   325,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   333,    -1,    -1,    -1,    -1,   338,    -1,  2471,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,  2486,    -1,    -1,   358,    -1,   360,    -1,
      -1,   229,    -1,    -1,   232,   367,    -1,    -1,   370,  2513,
      -1,   373,    -1,    -1,   376,    -1,  2509,   379,    -1,    -1,
      -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,   229,    -1,
      -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   418,    -1,    -1,   421,
     422,    -1,    -1,    -1,    -1,    -1,   428,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   439,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   455,    -1,  2588,    -1,    -1,    -1,    -1,
     462,    -1,    -1,    -1,    -1,    -1,    -1,   469,    -1,    -1,
     472,   473,   474,    -1,   476,   477,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   351,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   493,    -1,    -1,    -1,    -1,    -1,  2630,   366,    -1,
      -1,    -1,   370,   371,    -1,    -1,    -1,    -1,    -1,    -1,
     351,    -1,    -1,    -1,    -1,   517,   518,   519,   520,    -1,
     522,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,   370,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,   540,    -1,
     408,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     562,    -1,    -1,    -1,    -1,    -1,    -1,   408,   436,   571,
     572,    -1,   574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   455,  2721,    -1,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    88,    89,
      90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   636,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2797,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2811,    -1,
      -1,    -1,    -1,  2816,    -1,  2818,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    89,    90,
      -1,    -1,    -1,    -1,  2857,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2865,    -1,    -1,    -1,   604,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2881,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,    -1,   232,   604,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    -1,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,  2967,  2968,  2969,  2970,  2971,  2972,
      -1,    97,  2986,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    -1,   109,   110,   111,   112,    -1,   229,    -1,
      -1,   232,   118,    -1,    -1,   121,    -1,   123,   124,   125,
      -1,   127,   128,    -1,    -1,    -1,    -1,   133,    -1,   135,
     136,   351,   138,    -1,   140,   141,    -1,    -1,   144,   145,
     146,    -1,    -1,   149,   150,   151,   366,   153,   154,    -1,
     370,    -1,   158,   159,    -1,   161,    -1,    -1,    -1,   165,
      -1,   167,   168,    -1,    -1,    -1,    -1,   173,    -1,    -1,
      -1,   177,    -1,    -1,   180,    -1,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,   193,   408,    -1,
      -1,   197,    -1,   199,   200,    -1,   202,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3096,    -1,    -1,   436,   223,    -1,    -1,
     226,   227,    -1,    -1,   230,   231,    -1,    -1,   234,   235,
     351,    -1,    -1,    -1,    -1,   455,    -1,   243,   244,   245,
      -1,   247,    -1,    -1,    -1,   366,    -1,    -1,    -1,   370,
     371,   257,   258,   259,    -1,   261,    -1,    -1,    -1,   265,
     266,    -1,    -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   278,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     286,   287,   288,    -1,    -1,    -1,    -1,   408,   294,   295,
      -1,    -1,    -1,    -1,   300,    -1,    -1,   303,    -1,    -1,
      -1,   307,   308,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   318,    -1,    -1,   436,    -1,   537,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336,    -1,    -1,    -1,   455,    -1,    -1,    -1,   344,    -1,
      -1,    -1,    -1,    -1,   350,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,
      -1,    -1,    -1,    -1,   380,    -1,   382,   383,    -1,    -1,
      -1,    -1,    -1,    -1,   604,   391,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   441,    -1,    -1,    -1,   445,
      -1,    -1,    -1,   449,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   473,   474,    88,
      89,    90,   478,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   604,   490,    -1,    -1,    -1,    -1,    -1,
     496,   497,   498,   499,    -1,    -1,    -1,   503,    -1,    -1,
      -1,   507,    -1,    -1,    -1,    -1,    -1,    -1,   514,   515,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     526,    -1,   528,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,   541,    -1,    -1,   544,    -1,
      -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     576,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,   585,
      -1,    -1,   588,   589,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   603,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   633,   634,   635,
     636,   637,   638,   639,    -1,    -1,   642,    -1,   644,    -1,
     646,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      17,    18,    -1,    20,    -1,    -1,    23,    24,    25,    26,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,   371,    88,    89,    90,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,   229,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    88,    89,    90,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,   229,    -1,    -1,   232,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   274,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    -1,   604,   351,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,   366,    -1,    -1,    -1,   370,   371,    -1,    88,    89,
      90,    -1,    -1,    -1,   229,    -1,   351,   232,   375,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      -1,   366,    -1,   390,    -1,   370,   371,    -1,   117,    -1,
      -1,    -1,    -1,   408,    -1,    -1,    -1,   126,    -1,    -1,
     407,    -1,   131,   410,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   422,   423,    -1,    -1,    -1,
      -1,   436,    -1,   408,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     455,    -1,    -1,    -1,   451,    -1,   175,    -1,    -1,    -1,
     229,   436,   351,   232,   183,    -1,    -1,   464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,   476,
     455,   370,   371,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,
      -1,   366,   232,    -1,    -1,   370,   371,    -1,    -1,   408,
     239,   518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   264,    -1,   436,    -1,    -1,
      -1,    -1,   271,   408,   273,    -1,    -1,    -1,    -1,    -1,
     557,    -1,   537,    -1,   283,    -1,   455,    -1,    -1,    -1,
      -1,    -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   436,   351,    -1,   581,   582,   583,    -1,    -1,    -1,
     309,    -1,    -1,   590,    -1,    -1,   593,   366,   317,   604,
     455,   370,   371,    -1,   601,    -1,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,   604,
      -1,   351,    -1,    -1,    -1,   354,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,   537,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   380,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   537,    -1,    -1,    -1,   455,    -1,   408,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   418,
      -1,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     429,    -1,    -1,    -1,    -1,   604,   436,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     529,   530,   531,    -1,    -1,    -1,    -1,   537,    -1,    -1,
      -1,    -1,    -1,   542,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    -1,   604,    -1,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    -1,    -1,    -1,    -1,    -1,   646,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,   232,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,   351,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    -1,   366,    -1,    -1,
      -1,   370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,   421,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    89,    90,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,   455,    -1,    -1,    -1,
     229,    -1,   351,   232,    -1,    88,    89,    90,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   366,    -1,    -1,
      -1,   370,    -1,    -1,    -1,   229,    -1,    -1,   232,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   421,    -1,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   455,    -1,    88,    89,
      90,    -1,    -1,   229,    -1,    -1,   232,    -1,    -1,    -1,
      -1,    -1,   351,    -1,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,   366,    -1,    -1,
      -1,   370,    -1,    -1,    -1,   604,   229,   351,    -1,   232,
      40,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    51,   366,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   408,
      -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,   537,    79,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   408,    -1,    -1,   436,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    -1,   279,    -1,    -1,   455,    -1,    -1,    -1,
      -1,    -1,   436,    -1,    -1,   351,    -1,    -1,    -1,    -1,
      -1,    -1,   298,    -1,    -1,    -1,    -1,    -1,    -1,   229,
     366,   455,   232,    -1,   370,   604,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
     170,   337,   172,   366,    -1,    -1,    -1,   370,    88,    89,
      90,    -1,   408,   349,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   359,    -1,    -1,    -1,    -1,   537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     436,   377,    -1,    -1,    -1,   408,    -1,    -1,    -1,    -1,
      -1,   387,    -1,   537,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,
      -1,    -1,    -1,   436,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,   455,    -1,    -1,   604,    -1,    40,    -1,   269,
      -1,    -1,    45,    -1,   274,    -1,   366,   443,    51,    -1,
     370,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   467,   302,    -1,    -1,    -1,    79,    -1,    -1,    -1,
      -1,   537,    -1,    -1,    -1,    -1,   482,    -1,   408,   229,
      -1,    -1,   232,   489,    -1,    -1,   492,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,   537,    -1,   436,   513,    -1,   349,
     516,    -1,   518,    -1,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    -1,   455,    -1,   367,    -1,    -1,
      -1,   537,   372,    -1,    -1,   375,    -1,    40,   604,    -1,
      -1,    -1,    45,    -1,    -1,    -1,   386,    -1,    51,   555,
      -1,    -1,   392,    -1,    -1,    -1,    -1,   170,    -1,   172,
      -1,    -1,   402,    -1,    -1,    -1,    -1,   407,    -1,    -1,
     410,   604,    -1,   413,    -1,    -1,    79,    -1,    -1,    -1,
      -1,    -1,   422,   423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   351,    -1,    -1,    -1,    17,    18,   537,    20,    -1,
      -1,    23,    24,    25,    26,    -1,   366,    -1,    -1,    -1,
     370,    -1,    -1,   463,   464,    -1,    -1,    -1,   468,    -1,
      -1,    -1,    -1,    45,    -1,    -1,   476,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,    -1,   493,    -1,    -1,   269,    -1,   408,    -1,
      -1,   274,    -1,    -1,    -1,    -1,    -1,   170,    -1,   172,
      -1,    -1,    -1,    -1,   604,    -1,    -1,    -1,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,   302,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   455,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   562,    -1,   337,    -1,    -1,    -1,    -1,   569,
      -1,   571,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,
      -1,   581,   582,   583,    -1,    -1,    -1,    -1,    -1,    -1,
     590,    -1,    -1,    -1,   367,    -1,    -1,    -1,   170,   372,
      -1,   601,   375,    -1,    -1,    -1,   269,    -1,    17,    18,
      -1,   274,    -1,   386,    23,    24,    25,    26,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   537,    -1,   402,
      -1,    40,    -1,    -1,   407,    -1,    45,   410,    -1,   302,
     413,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,   422,
     423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      79,    -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,
      -1,   464,    -1,    -1,   604,   468,    -1,    -1,    -1,    -1,
      -1,    -1,   274,   476,   367,    -1,    -1,    -1,    -1,   372,
      -1,    -1,   375,    -1,   487,    -1,   489,    -1,    17,    18,
     493,    20,    -1,   386,    23,    24,    25,    26,    -1,   392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   402,
      -1,    -1,    -1,    -1,   407,   518,    45,   410,    17,    18,
     413,    20,    -1,    -1,    23,    24,    25,    26,    -1,   422,
     423,   170,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    17,    18,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    -1,   562,
      -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,   571,    -1,
     463,   464,    -1,   375,    -1,   468,    45,    -1,   581,   582,
     583,    -1,    -1,   476,    -1,    -1,    -1,   590,   390,    -1,
      -1,    -1,    -1,    -1,   487,    -1,    -1,    -1,   601,    -1,
     493,    -1,    -1,    -1,    -1,   407,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     422,   423,    -1,    -1,    -1,   518,    -1,    -1,    -1,    -1,
     269,    -1,    -1,    -1,    -1,   274,    -1,    -1,    -1,    17,
      18,   170,    20,    -1,    -1,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   464,   302,    -1,    -1,    -1,    45,    -1,   562,
      -1,   170,    -1,    -1,   476,    -1,   569,    -1,   571,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,
     583,    -1,    -1,    -1,    -1,    -1,    -1,   590,   337,    -1,
      -1,   170,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,
     349,    -1,    -1,    -1,    -1,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,
      -1,    -1,    -1,   372,    -1,    -1,   375,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   274,    -1,   386,    -1,    -1,
      -1,    -1,    -1,   392,    -1,   557,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   402,    -1,    -1,    -1,   569,   407,    -1,
      -1,   410,    -1,    -1,   413,    -1,    -1,    -1,    -1,   581,
     582,   583,    -1,   422,   423,    -1,    -1,    -1,   590,    -1,
      -1,   593,   170,    -1,    -1,    17,    18,    -1,    20,   601,
      -1,    23,    24,    25,    26,    17,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,   464,    -1,    -1,    -1,   468,
      -1,    -1,    -1,    45,    -1,    -1,    -1,   476,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,   487,    -1,
      -1,    -1,    -1,    -1,   493,    -1,    -1,    -1,    -1,    -1,
      -1,   390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,   407,   518,
      -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,   390,    20,   422,   423,    23,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   375,    -1,   407,    -1,
      78,   410,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,   390,    -1,   562,   423,    -1,    -1,    -1,    -1,    -1,
     569,    -1,   571,    -1,    -1,   464,    -1,    -1,   407,    -1,
      -1,   410,   581,   582,   583,    -1,    -1,   476,   170,    -1,
      -1,   590,    -1,    -1,   423,    -1,    -1,    -1,   170,    -1,
      -1,    -1,   601,    -1,   463,   464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,    -1,   451,    -1,    -1,    -1,    -1,    -1,    -1,   518,
      -1,    -1,    -1,    -1,    -1,   464,    -1,   375,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   476,    -1,    -1,
      -1,    -1,   390,    -1,    -1,   183,    -1,    -1,    -1,   518,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,   407,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     569,    -1,   170,    -1,    -1,   423,    -1,    -1,    -1,   518,
      -1,    -1,   581,   582,    -1,    -1,    -1,    -1,   557,    -1,
      -1,   590,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,
     569,   239,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,   582,    -1,   463,   464,    -1,   557,    -1,
      -1,   590,    -1,    -1,   593,    -1,   264,    -1,   476,    -1,
     569,    -1,   601,    -1,    -1,   273,    -1,    -1,    -1,    -1,
      -1,    -1,   581,   582,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   590,    -1,    -1,   593,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   601,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     518,   309,    -1,    -1,   312,    -1,    -1,    -1,    -1,   317,
      -1,    -1,    -1,   375,    -1,    -1,    -1,   325,    -1,    -1,
      -1,    -1,    -1,   375,    -1,    -1,    -1,    -1,   390,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   557,
      -1,    -1,    -1,    -1,    -1,   407,    -1,    -1,   410,    -1,
      -1,   569,    -1,    -1,    -1,   407,    -1,    -1,   410,    -1,
      -1,   423,    -1,   581,   582,    -1,    -1,    -1,    -1,    -1,
      -1,   423,   590,    -1,    -1,   593,    -1,    -1,    -1,    -1,
      -1,   389,    -1,   601,    -1,    -1,    -1,    -1,   396,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   463,   464,   411,    -1,    -1,    -1,   375,    -1,    -1,
      -1,   463,   464,    -1,   476,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,   476,    -1,    -1,   435,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   407,
      -1,    -1,   410,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   460,    -1,    -1,   423,   518,    -1,    -1,    -1,
      -1,    -1,   470,   471,    -1,    -1,   518,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   486,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   557,   464,    -1,    -1,    -1,
     508,    -1,    -1,   511,   512,   557,    -1,   569,   476,   517,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   569,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   590,   581,
     582,   593,    -1,    -1,    -1,    -1,    -1,    -1,   590,   601,
      -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,
     518,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   574,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   584,    -1,   586,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   557,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   569,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,   582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   590,    -1,    -1,   593,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   601
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short yystos[] =
{
       0,    29,    55,   102,   103,   105,   106,   110,   127,   128,
     145,   146,   216,   336,   385,   417,   707,   735,   736,   786,
     952,  1007,  1009,  1010,  1011,  1016,  1018,  1031,  1032,  1033,
    1034,  1035,  1441,    27,    28,   708,   709,   710,   711,   712,
      26,   917,  1460,   335,   514,   528,   553,   602,  1442,  1442,
    1442,  1442,  1442,  1442,  1442,  1442,   917,    24,   917,  1379,
    1036,   737,   736,  1441,     0,  1008,  1011,  1016,  1034,  1441,
      30,   710,   712,   917,  1444,   570,   917,  1443,   607,   787,
      24,   170,   734,   735,   905,   917,   922,  1037,  1073,  1074,
    1075,  1076,  1077,  1081,   333,   739,   740,   741,   742,   745,
     746,    36,    41,    85,    86,    93,   347,   373,   444,   538,
     619,   627,   707,   713,   877,   951,  1012,  1013,  1015,  1019,
    1020,  1026,  1038,  1059,  1190,  1200,  1441,   917,  1443,   598,
    1076,   222,   437,   438,  1082,    20,   917,  1080,   601,   740,
       5,   738,   333,   917,     5,   762,   764,   765,   917,  1201,
     917,   917,  1191,  1027,   917,   917,  1015,  1021,   240,   279,
     298,   337,   349,   359,   377,   387,   403,   443,   467,   482,
     489,   492,   513,   516,   518,   537,   555,   788,   789,   790,
     793,    24,  1073,  1079,    17,    18,    25,   410,   657,   659,
    1073,  1083,  1084,   438,    13,   785,   742,   502,  1177,   743,
     740,   745,    31,    60,    61,    69,   240,   279,   298,   314,
     337,   349,   359,   377,   387,   403,   443,   467,   482,   489,
     492,   513,   516,   518,   537,   555,   598,   748,   756,   767,
     768,   917,   410,    92,   917,   734,   878,  1060,   917,   795,
     516,   747,   771,   773,   774,   772,   781,   782,   410,   410,
     794,   438,   410,   410,   740,   769,   405,   657,    17,    18,
      19,    20,    21,   658,    25,     5,   406,  1083,    23,    24,
      25,   601,   917,   923,    18,    24,    25,   744,   923,   758,
     747,   759,   771,   772,   410,   410,   757,   438,   410,   410,
     769,   740,   766,   410,    25,   917,   410,  1028,   734,   734,
     410,   917,   410,   437,   751,   607,   346,   433,   450,   493,
     533,   562,   571,   775,   607,   346,   433,   450,   493,   533,
     562,   571,   783,    25,    25,   796,   797,   798,   799,   917,
      25,   754,   755,    25,    25,   601,   371,   657,  1084,   438,
     406,    25,    25,   740,   751,   740,    25,    25,   739,   754,
      25,    25,   601,    39,   763,  1202,   371,   410,  1192,  1461,
    1462,  1463,  1464,  1465,   879,  1061,  1022,   601,    25,   776,
     777,   410,   778,   783,   784,   778,   410,   779,     5,   371,
       5,   371,     5,   263,     5,   788,   406,     5,     5,   371,
     371,   740,   770,  1083,   601,    25,   238,     5,   371,     5,
     371,   263,   406,     5,   371,   371,   770,   917,  1089,  1090,
    1092,  1039,  1089,   341,  1462,  1177,    33,    35,    47,    49,
      63,    70,    81,    82,    83,    97,    99,   100,   101,   104,
     107,   109,   111,   112,   118,   121,   123,   124,   125,   133,
     135,   136,   138,   140,   141,   144,   149,   150,   151,   153,
     154,   158,   159,   161,   165,   167,   168,   173,   177,   180,
     182,   184,   186,   188,   189,   191,   192,   193,   197,   199,
     200,   202,   210,   211,   223,   226,   227,   230,   231,   234,
     235,   243,   244,   245,   247,   257,   258,   259,   261,   265,
     266,   270,   278,   286,   287,   288,   294,   295,   300,   303,
     307,   308,   318,   336,   344,   350,   380,   382,   383,   391,
     430,   441,   445,   449,   473,   474,   478,   490,   496,   497,
     498,   499,   503,   507,   514,   515,   526,   528,   539,   541,
     544,   550,   576,   579,   585,   588,   589,   603,   610,   633,
     634,   635,   636,   637,   638,   639,   642,   644,   646,   650,
     651,   652,   653,   670,   692,   706,   707,   713,   714,   733,
     801,   802,   803,   804,   815,   816,   817,   818,   869,   873,
     903,   925,   926,   929,   930,   931,   932,   945,   953,   976,
     977,   979,   983,   998,   999,  1003,  1004,  1005,  1006,  1014,
    1029,  1042,  1053,  1054,  1055,  1066,  1069,  1105,  1108,  1110,
    1116,  1117,  1120,  1123,  1126,  1128,  1130,  1132,  1139,  1144,
    1148,  1149,  1161,  1162,  1165,  1171,  1172,  1173,  1198,  1213,
    1214,  1215,  1216,  1217,  1222,  1228,  1229,  1247,  1250,  1290,
    1291,  1380,  1381,  1411,  1412,  1419,  1430,  1441,  1445,  1450,
    1452,  1454,  1458,  1459,  1466,   707,  1017,  1441,   606,   629,
    1062,  1063,  1089,    20,   371,   405,   752,   775,    25,   780,
      25,    25,    25,   797,   799,   791,   755,    25,   406,    20,
     752,   410,    25,    25,   749,    25,   601,   371,     5,  1089,
     371,   917,   329,   918,   919,  1460,   917,   912,   918,   912,
      24,   170,   917,  1102,  1436,  1437,  1438,   917,  1456,   917,
    1224,  1225,   917,    25,   654,  1073,  1220,   912,   917,  1146,
     844,    25,   923,  1185,  1186,  1185,    17,    18,    24,    25,
      40,    45,    51,    79,   172,   269,   274,   302,   337,   349,
     367,   372,   375,   386,   392,   402,   407,   410,   413,   422,
     423,   464,   468,   476,   487,   493,   518,   562,   569,   571,
     581,   582,   583,   590,   819,   826,   827,   828,   829,   830,
     831,   832,   833,   845,   850,   861,   862,   863,   864,   917,
     923,  1073,  1180,  1249,  1371,   918,  1420,  1420,   805,  1146,
     912,  1218,  1073,   914,   918,   826,  1420,  1073,  1146,  1073,
    1248,  1420,    24,   566,  1056,  1057,  1073,   912,   912,  1056,
     913,   918,   917,  1057,   912,  1420,   912,   914,  1073,  1103,
    1104,   910,   918,   914,   354,   542,   648,   909,   917,   978,
     917,   715,   915,   918,  1436,  1070,   844,   918,  1129,   874,
     108,   117,   126,   131,   175,   183,   239,   264,   271,   273,
     283,   309,   317,   354,   380,   418,   429,   529,   530,   531,
     542,   646,   990,  1124,  1125,  1073,   825,   826,  1138,   821,
     844,   909,  1451,  1451,   911,   918,   844,    24,  1073,  1127,
    1199,  1073,  1176,    24,  1073,  1414,   826,  1167,  1168,  1169,
    1178,  1179,   826,  1446,    84,   134,   172,   269,   345,   386,
     454,   518,   671,   850,   917,  1073,  1208,   694,   826,   910,
    1443,  1043,   826,   910,   826,  1073,  1000,   910,   826,  1431,
     826,  1185,   917,   927,   928,   914,   927,  1451,   914,   927,
    1451,   933,   927,    24,    25,   364,   467,   923,   981,  1073,
    1091,  1093,    46,   254,   324,   369,   549,   630,   631,   632,
     641,   661,   935,   937,   939,   941,   943,  1067,  1068,  1072,
     315,   326,   378,   393,   483,  1292,   621,   622,   881,   882,
     883,   917,  1064,   628,  1063,   371,   282,   371,   371,   371,
     371,   605,     5,   371,   282,   740,   760,   761,   371,   371,
     605,   371,   917,  1203,  1092,   371,  1193,    37,    38,    64,
      65,    66,   434,   522,   565,  1230,  1231,  1232,  1235,  1238,
    1241,  1242,  1243,  1244,   410,   601,  1438,   438,   598,  1121,
     601,     8,   519,   568,     5,   371,   406,    24,   917,  1364,
     459,  1147,  1091,    88,    89,    90,   819,   819,   410,   506,
    1197,   410,   410,   410,   410,   410,   410,   410,   410,   410,
     819,   346,   433,   450,   493,   533,   562,   571,  1374,  1375,
     410,   410,   410,   819,   819,   410,   410,   731,   819,   410,
     834,   410,   410,   410,   410,   410,   410,   410,   819,   410,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    72,    73,    74,    75,
      76,    77,    88,    89,    90,   229,   232,   351,   366,   370,
     408,   436,   455,   537,   604,   730,   820,   835,   837,   838,
     839,   840,   841,   842,   843,    25,   923,   410,   501,   400,
    1073,  1098,  1364,   660,   661,   808,   246,    67,    68,   607,
     439,     5,   600,   607,   599,   599,  1106,   576,   400,     5,
     537,   954,   439,   640,  1448,   410,   438,   601,   640,   364,
     717,  1073,   527,   599,  1111,  1112,  1113,   306,  1289,   825,
     824,   826,     8,   911,    25,   481,   535,   904,  1073,   904,
     904,   904,   995,   996,   904,   904,   577,   991,   661,   991,
     991,   905,   905,   991,   991,   661,     5,   313,   365,     5,
     660,   463,   822,   823,   826,     5,    56,    62,   520,   608,
     984,   643,  1449,   825,   594,   595,   596,   597,  1175,  1177,
     363,  1212,  1177,  1169,     5,   599,  1170,   826,   410,   410,
     410,   410,    24,   690,   917,   410,  1414,   324,   410,   501,
     570,   559,   695,   702,   693,    24,  1058,  1073,  1163,     8,
    1166,    13,   917,  1078,  1085,  1086,  1088,  1096,  1097,  1140,
     142,   324,   525,   558,    32,   170,   534,  1432,  1433,  1434,
    1435,   556,     5,   640,   640,   824,  1091,  1098,   980,   400,
       5,   130,   958,   410,  1073,   824,   410,    25,    25,    46,
    1071,    24,  1073,  1418,  1418,   911,  1129,   911,    98,   201,
     209,   215,   217,   228,   256,   272,   277,   289,   296,   451,
     458,   480,   485,  1251,  1262,  1263,  1271,  1280,  1281,  1287,
    1288,  1293,  1294,  1303,  1322,  1326,  1391,  1392,  1421,  1422,
    1425,  1426,   884,   885,    71,   880,   891,   892,   883,  1065,
    1461,  1023,   438,   788,   755,   438,     5,   371,   762,   734,
    1040,   734,   137,   276,   352,   410,   472,  1309,  1321,   410,
     917,  1246,    25,   225,   238,   410,   456,   472,   917,  1227,
    1240,  1307,  1308,  1313,  1315,  1317,   410,   917,  1237,   410,
    1227,  1233,     5,    24,   920,  1076,  1438,  1083,  1436,   557,
     598,  1122,    20,   917,  1102,  1439,   917,  1457,  1225,   576,
     601,   570,   410,   410,   808,   909,   819,   909,   909,   909,
    1451,   451,  1395,   819,    24,    25,    18,    23,    24,    25,
     865,   866,   867,   868,   819,   410,   607,   909,    20,   819,
     371,  1395,   819,    20,  1180,   853,   851,   857,   819,   855,
     819,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   819,   819,   819,   819,   819,   819,   819,   819,   819,
     819,   410,   819,   819,   410,   846,   917,  1073,   607,   410,
    1436,    24,   922,  1145,  1145,  1414,  1056,   826,   826,   826,
     906,   907,   410,  1073,  1104,   769,   955,   956,   607,  1414,
    1451,  1449,   917,   657,    20,   648,   917,   978,  1073,   716,
     606,   826,   330,  1115,   537,  1114,     5,    48,    50,    52,
     599,   607,   800,  1091,   875,    17,    18,    24,   284,   290,
     291,   292,   310,   418,   421,   445,   465,   500,   520,   521,
     531,   536,   575,   608,   997,   992,  1125,   905,   826,   324,
     576,     5,   909,    25,    25,   660,   132,  1174,   198,  1179,
    1185,  1447,   917,    24,   909,  1451,   570,   909,   604,  1073,
     675,   917,   917,   826,   319,   698,   702,   559,   696,   704,
      22,   214,  1045,  1049,   462,   844,   462,  1164,   826,   437,
    1082,   601,     5,  1001,   527,  1141,  1073,  1437,  1440,  1073,
    1094,  1095,   169,  1433,   946,   928,  1451,  1451,   938,   939,
     958,   958,   250,   253,   255,   275,   285,   327,   331,   409,
     461,   645,   957,   959,   960,   986,  1073,  1093,   527,   662,
      25,   379,   944,   301,  1413,  1413,   115,   116,   416,   527,
     917,  1323,  1324,  1365,   769,  1364,  1364,  1264,   769,   917,
    1423,  1423,   339,   456,   566,  1403,  1364,  1272,   148,   418,
     429,   451,   458,  1296,  1297,  1298,   267,   268,  1386,  1461,
    1461,   364,   893,  1073,   623,   624,   886,   887,   888,   461,
     606,   625,   626,   645,   896,   897,  1461,   734,    25,   753,
     753,   761,  1204,   734,  1194,  1311,  1364,  1245,  1321,   410,
    1245,   410,   410,  1239,  1240,   410,   410,    44,   279,   337,
     349,   359,   377,   387,   390,   403,   452,   482,   492,   513,
     516,   518,   546,   555,  1356,  1357,  1358,  1360,  1236,  1237,
    1233,  1234,   645,  1231,   371,   601,   406,  1414,   557,   527,
    1455,   655,   656,   917,   917,   917,  1221,   844,   371,   371,
     371,   371,   371,  1403,   371,   371,   371,   371,   570,   866,
      18,    25,   570,   371,   371,    25,  1375,   371,   371,   371,
     371,     5,   732,   371,   819,   819,   819,   371,   819,   371,
     371,   371,   421,   421,   421,   844,  1395,   421,   844,  1395,
     687,   688,   689,   819,   410,   917,  1219,   598,  1118,   607,
       5,     5,     5,   560,   826,   601,     5,   463,   607,   371,
     406,   410,   606,   143,   147,   250,   253,   718,   721,   722,
     986,   719,   720,   917,   410,   918,   630,   631,  1119,   826,
     917,   917,   907,   908,   489,  1451,   808,   534,  1277,    25,
      25,   410,   993,   995,  1073,   516,  1133,   822,    46,   819,
    1177,    25,  1073,  1461,     5,     5,   371,   371,   691,   917,
     371,  1414,   687,   410,   410,   703,   699,   340,   697,   826,
     319,   700,   704,   577,   988,  1050,  1046,   342,  1044,  1045,
     824,   607,  1079,    20,   917,  1087,  1097,    13,    17,    18,
      20,    24,    25,    45,   375,   390,   407,   410,   423,   463,
     464,   476,   518,   557,   569,   581,   582,   590,   593,   917,
     923,  1142,  1143,  1370,  1372,  1402,  1407,  1408,  1440,   400,
     400,     5,  1461,   940,   941,   531,   916,   527,   909,   974,
     909,   975,   967,   966,   964,   963,   987,   418,   429,   970,
     971,   418,   429,   972,   973,   304,   960,   965,  1451,    78,
     312,   325,   389,   396,   435,   460,   470,   471,   486,   508,
     511,   512,   517,   574,   586,   663,   664,     5,    25,  1414,
     228,  1073,   451,  1396,  1397,  1414,  1129,  1390,  1392,    80,
      80,   576,  1127,  1325,  1326,   410,  1304,   129,   506,  1330,
    1337,  1364,   155,   251,  1427,   601,   607,  1404,  1405,  1407,
    1252,   321,   330,   354,   357,   375,   481,   535,   542,   911,
    1274,  1279,   410,  1299,   606,     5,    24,   917,  1387,  1388,
     895,  1073,     5,   527,   889,   890,   620,   888,   894,   917,
     894,   898,   899,   894,   304,   897,  1024,   406,   406,   440,
    1187,  1207,  1041,   440,  1150,  1181,   410,     5,   371,   274,
     410,   422,   583,  1340,  1341,  1342,  1343,  1344,  1348,  1352,
    1354,  1407,   371,   593,   917,  1310,  1312,  1364,  1367,  1368,
    1314,  1367,     5,   371,  1314,  1340,   346,   433,   450,   493,
     533,   562,   571,  1377,  1377,   410,   410,   410,   410,   410,
     410,   187,   379,  1316,  1318,     5,   371,     5,   371,   917,
    1439,     8,  1414,   826,     5,  1226,  1227,   844,  1030,  1404,
     859,  1375,   859,    25,    25,   570,    23,    25,   772,   860,
    1197,   371,  1197,   773,   371,  1197,   854,   852,   858,  1197,
     856,  1197,  1197,  1197,    24,    24,    24,   819,   836,   371,
      24,   836,   371,   847,     5,   848,   601,  1226,   557,  1414,
    1414,   826,   826,   906,   489,   826,  1453,     5,    20,  1367,
     956,  1414,   601,   917,   719,   727,   726,   728,   917,   921,
     729,   921,   171,   722,   725,     5,   958,   601,   826,     8,
     917,  1278,   876,   994,   995,  1073,     5,   305,    24,  1209,
     324,   324,   438,   601,   324,   410,   676,   680,   673,  1461,
    1461,   705,   701,   697,   989,    24,   916,  1051,  1073,  1461,
     826,   405,   438,   844,    25,   923,    25,   923,  1373,  1377,
     451,  1407,   410,   410,   410,   410,   410,   410,   410,   917,
     410,     5,    17,    18,    19,    20,    72,    73,    74,    75,
      76,    77,  1428,  1437,  1073,  1095,    43,   523,   947,   942,
     943,    25,   660,   917,     5,   961,     5,   962,  1461,  1461,
    1461,  1461,   993,     5,   969,     5,   968,  1461,   916,     5,
     371,    25,  1364,  1403,  1384,   576,   576,  1263,  1389,  1390,
    1326,  1305,  1367,   598,   911,  1340,   410,  1267,   917,  1424,
    1423,     5,  1393,   260,   300,   301,   302,   325,   333,   338,
     353,   358,   360,   367,   370,   373,   376,   379,   384,   402,
     418,   421,   422,   428,   439,   455,   462,   469,   472,   473,
     474,   476,   477,   493,   517,   518,   519,   520,   522,   539,
     540,   562,   571,   572,   574,   636,   924,  1460,   564,   826,
     826,  1273,   911,  1300,  1367,  1364,  1298,   601,   601,     5,
       5,  1073,   894,  1461,  1461,     5,   901,   902,  1461,  1461,
     900,  1017,   792,   750,    53,    54,    57,    58,    59,   157,
     164,   198,   207,   236,   237,   281,   323,   379,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,  1184,  1188,
     114,   494,  1189,  1205,  1017,   139,   156,   157,   164,   198,
     207,   236,   281,   323,  1182,  1183,  1195,  1189,  1312,  1321,
     410,  1402,  1340,  1407,  1402,  1343,     6,   371,     7,     9,
      11,    12,    13,    14,    15,    16,   232,   351,   408,   537,
     583,   604,  1351,  1353,  1368,   438,  1366,   371,     5,   601,
       5,   371,  1240,   371,   371,   607,   410,   607,    25,  1362,
    1362,    25,  1362,  1362,    25,  1361,    24,  1370,  1319,  1320,
    1321,  1237,  1233,  1414,     8,   656,     5,   371,   824,   371,
     527,  1331,  1336,   607,   371,    25,   570,   607,   371,   371,
     371,   371,     5,   371,   371,   371,   689,   687,    20,   371,
    1414,     5,   826,   547,   254,   665,   666,   826,    20,   917,
     371,   958,  1461,  1461,     5,   723,   438,   601,     5,   724,
    1461,   720,   527,    20,   917,     5,   917,  1109,   369,   640,
    1094,  1461,     5,   371,   916,   819,     5,   687,  1073,   672,
     654,   917,  1073,   678,   371,   687,   687,  1461,  1461,   993,
    1048,    24,  1052,  1073,   552,   872,  1083,   463,   825,  1002,
     607,  1403,   371,   375,  1367,  1429,   339,   456,   566,  1355,
    1407,  1409,  1355,  1355,  1355,  1355,   601,  1409,  1143,  1407,
    1407,  1407,  1407,   949,   948,   420,   934,   935,   601,   909,
    1461,   909,  1461,   971,  1461,   973,  1461,   660,   664,   371,
     410,  1415,  1404,  1386,  1390,  1390,  1382,     5,   371,   451,
    1401,  1268,  1367,   459,  1265,  1401,   607,  1405,   534,  1400,
      20,   410,  1255,  1256,  1257,  1258,  1367,   534,  1275,     5,
     371,   607,   917,   917,  1388,  1073,   917,  1461,  1461,  1461,
    1461,   605,   605,  1185,  1185,  1185,    24,  1185,  1185,  1185,
    1185,  1185,  1185,    24,    24,  1185,  1188,  1073,  1099,  1100,
     600,   426,  1151,  1461,    24,    24,    25,    25,    25,    25,
      25,    24,  1073,  1183,  1151,   371,   371,  1341,  1342,   917,
    1346,  1370,  1410,   410,  1402,  1346,   410,  1402,     9,   229,
     366,   368,  1407,    25,  1309,  1367,    20,   917,  1367,   346,
     433,   450,   493,   533,   562,   571,  1378,    25,  1378,     5,
    1359,  1359,     5,   371,   371,  1359,   371,  1321,  1414,  1227,
     248,  1223,   495,  1332,  1333,  1334,  1364,  1337,   311,   494,
     505,  1282,  1398,   346,   433,   450,   493,   533,   562,   571,
    1376,   859,   570,    23,    25,   776,   819,   849,   448,   807,
       5,   353,  1414,     5,   410,   371,   531,   985,   921,  1461,
     657,    20,   917,   921,  1461,  1451,   826,  1451,   220,   995,
     660,    24,  1210,  1091,   406,   687,   677,   681,   371,  1461,
     916,   826,   870,   406,  1378,  1404,     5,  1377,     5,   371,
    1407,     5,   371,  1407,  1407,  1407,  1407,   917,   371,   826,
    1461,   936,   937,    20,   917,  1416,  1417,  1400,  1385,  1383,
    1386,  1367,  1403,   119,  1306,     5,   371,  1266,  1424,  1094,
    1394,    13,  1257,  1259,  1253,     5,    13,  1276,  1367,   442,
    1301,  1302,  1365,   601,   190,  1025,   788,   762,   519,   568,
    1101,     5,  1099,    42,   113,   179,   181,   196,   204,   208,
     233,  1152,  1153,  1206,  1025,  1196,   421,  1345,  1349,  1350,
    1370,  1440,  1345,  1349,  1346,  1407,     5,   406,  1366,   371,
      25,  1363,   371,   371,    25,   371,   410,  1334,     5,   917,
    1369,   348,  1328,  1338,   917,  1399,   600,  1355,   311,   410,
      23,    25,   371,   909,   660,   353,  1414,   826,   667,   549,
    1107,    25,   660,   406,   985,   371,  1131,   371,   371,   410,
     679,   324,   685,   371,   674,  1047,  1461,  1336,  1377,   607,
    1377,   371,  1407,   371,   371,   371,   371,   556,   916,     5,
     371,  1336,  1386,  1386,  1404,  1367,   410,  1336,   410,   463,
    1260,  1261,  1407,     5,   371,   129,   506,  1254,  1258,  1261,
    1094,     5,   120,  1295,   917,  1100,  1154,  1155,  1073,  1157,
    1073,  1156,  1158,  1153,   219,   219,  1347,  1410,     5,   371,
     371,  1345,     7,    25,   607,   371,  1333,  1335,  1333,  1329,
    1406,  1407,   427,  1327,  1339,  1223,    25,  1283,  1284,  1285,
    1367,  1396,  1399,    25,   806,  1414,   372,   183,   239,   264,
     273,   309,   317,   411,   584,   664,   668,   669,   410,   601,
     660,   986,  1134,  1135,  1136,  1211,   682,   371,  1091,   685,
     685,  1461,   871,   371,   607,  1378,   607,   950,   982,  1417,
    1398,  1336,   463,  1269,  1270,  1407,  1398,  1260,  1407,     5,
    1257,    13,   911,  1340,  1302,  1461,  1461,  1159,  1461,  1160,
    1461,  1461,  1350,  1407,   406,  1378,     5,   371,     5,  1340,
       5,   519,   568,  1286,  1223,   371,   327,   331,   809,   810,
     811,   986,   904,   904,   904,   904,   904,   904,    24,     5,
     371,   826,    20,   917,  1137,   262,  1136,   685,   687,   685,
     221,  1378,  1378,  1461,   660,     5,   371,   371,  1261,   410,
    1461,  1461,  1333,  1406,  1284,   813,   812,   218,   811,   814,
     669,     5,  1461,   683,   947,  1270,  1260,  1461,  1461,  1461,
     826,   371,   371,   371,   684,   142,   324,   686,  1091
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
#line 886 "fgl.yacc"
    { print_screen_mode(0);}
    break;

  case 3:
#line 889 "fgl.yacc"
    { print_screen_mode(1);}
    break;

  case 4:
#line 893 "fgl.yacc"
    {
		print_start_server(yyvsp[-3].str,yyvsp[0].str);
	}
    break;

  case 5:
#line 899 "fgl.yacc"
    {
	print_stop_external();
	}
    break;

  case 6:
#line 904 "fgl.yacc"
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
#line 916 "fgl.yacc"
    {
	sprintf(yyval.str,"%s%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 10:
#line 921 "fgl.yacc"
    {
	print_remote_func(yyvsp[0].str);
	sprintf(yyval.str,"unregister_func(\"%s\",%s%s);\n",yyvsp[0].str,(char *)get_namespace(yyvsp[0].str),yyvsp[0].str);
	addmap("Call Remote",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 11:
#line 939 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[-1].str);}
    break;

  case 12:
#line 940 "fgl.yacc"
    { sprintf(yyval.str,"%s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 13:
#line 941 "fgl.yacc"
    {sprintf(yyval.str,"%d",atoi(yyvsp[0].str));}
    break;

  case 14:
#line 942 "fgl.yacc"
    {sprintf(yyval.str,"(%s%s)",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 15:
#line 943 "fgl.yacc"
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
#line 957 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 17:
#line 958 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 18:
#line 959 "fgl.yacc"
    {strcpy(yyval.str,"*");}
    break;

  case 19:
#line 960 "fgl.yacc"
    {strcpy(yyval.str,"/");}
    break;

  case 20:
#line 961 "fgl.yacc"
    {strcpy(yyval.str,"%");}
    break;

  case 21:
#line 966 "fgl.yacc"
    {strcpy(yyval.str,"+");}
    break;

  case 22:
#line 967 "fgl.yacc"
    {strcpy(yyval.str,"-");}
    break;

  case 23:
#line 978 "fgl.yacc"
    {
		debug("Using default attribute of WHITE");
		sprintf(yyval.str,"%d",0);}
    break;

  case 24:
#line 981 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 25:
#line 984 "fgl.yacc"
    {start_state("attribute",1);}
    break;

  case 26:
#line 984 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);
debug("Got Attributes : %s",yyvsp[-1].str);
start_state("attribute",0);
}
    break;

  case 28:
#line 991 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 29:
#line 992 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-2].str)|atoi(yyvsp[0].str));
}
    break;

  case 30:
#line 998 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLACK"));}
    break;

  case 31:
#line 999 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLUE"));}
    break;

  case 32:
#line 1000 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("CYAN"));}
    break;

  case 33:
#line 1001 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("GREEN"));}
    break;

  case 34:
#line 1002 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("MAGENTA"));}
    break;

  case 35:
#line 1003 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("RED"));}
    break;

  case 36:
#line 1004 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("WHITE"));}
    break;

  case 37:
#line 1005 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("YELLOW"));}
    break;

  case 38:
#line 1006 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("REVERSE"));}
    break;

  case 39:
#line 1007 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BLINK"));}
    break;

  case 40:
#line 1008 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("UNDERLINE"));}
    break;

  case 41:
#line 1009 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("BOLD"));}
    break;

  case 42:
#line 1010 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("NORMAL"));}
    break;

  case 43:
#line 1011 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("INVISIBLE"));}
    break;

  case 44:
#line 1012 "fgl.yacc"
    {sprintf(yyval.str,"%d",attr_code("DIM"));}
    break;

  case 45:
#line 1013 "fgl.yacc"
    {inp_flags=inp_flags | 0x1; strcpy(yyval.str,"0");}
    break;

  case 48:
#line 1020 "fgl.yacc"
    {
debug("win_attributes_def");
start_state("attribute",1);
debug("Started states");
form_attrib.attrib=0;}
    break;

  case 49:
#line 1024 "fgl.yacc"
    {start_state("attribute",0);strcpy(yyval.str,"");
}
    break;

  case 50:
#line 1028 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 51:
#line 1029 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 52:
#line 1033 "fgl.yacc"
    { 
/*printf("Window attribute = %s\n",$<str>1);*/
form_attrib.attrib      =form_attrib.attrib|atoi(yyvsp[0].str);
/*printf("Window attribute = %d\n",form_attrib.attrib);*/
}
    break;

  case 53:
#line 1039 "fgl.yacc"
    { form_attrib.border      =1;}
    break;

  case 54:
#line 1041 "fgl.yacc"
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
#line 1052 "fgl.yacc"
    { form_attrib.comment_line=atoi(yyvsp[0].str); }
    break;

  case 56:
#line 1054 "fgl.yacc"
    { form_attrib.form_line   =atoi(yyvsp[0].str); }
    break;

  case 57:
#line 1056 "fgl.yacc"
    { form_attrib.error_line  =atoi(yyvsp[0].str); }
    break;

  case 58:
#line 1058 "fgl.yacc"
    { form_attrib.menu_line   =atoi(yyvsp[0].str); 
debug("Set menu line to %s",yyvsp[0].str);
}
    break;

  case 59:
#line 1062 "fgl.yacc"
    { form_attrib.message_line=atoi(yyvsp[0].str); }
    break;

  case 60:
#line 1064 "fgl.yacc"
    { form_attrib.prompt_line =atoi(yyvsp[0].str); }
    break;

  case 61:
#line 1125 "fgl.yacc"
    {strcpy(yyval.str,"CALL");}
    break;

  case 62:
#line 1129 "fgl.yacc"
    { debug("print_expr (3)"); 
		print_expr(yyvsp[-2].ptr);
		print_pop_variable(yyvsp[0].str);
	}
    break;

  case 63:
#line 1133 "fgl.yacc"
    {
	print_getfldbuf(yyvsp[-2].str);
	}
    break;

  case 64:
#line 1136 "fgl.yacc"
    {
	print_returning();
}
    break;

  case 65:
#line 1144 "fgl.yacc"
    {
	print_form_is_compiled(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str);
	}
    break;

  case 66:
#line 1149 "fgl.yacc"
    {
	print_field_func('I',yyvsp[-3].str,yyvsp[0].str);
   }
    break;

  case 68:
#line 1153 "fgl.yacc"
    { 
	print_field_func('T',yyvsp[-3].str,yyvsp[0].str);
     }
    break;

  case 69:
#line 1156 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-3].str,curr_func,yylineno,infilename);
   }
    break;

  case 70:
#line 1162 "fgl.yacc"
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
#line 1171 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-4].str); /* ? */
   }
    break;

  case 72:
#line 1175 "fgl.yacc"
    {
	new_counter();
   	addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
   }
    break;

  case 73:
#line 1180 "fgl.yacc"
    {
	debug("Got args");
   }
    break;

  case 74:
#line 1184 "fgl.yacc"
    {
	int a;
	dump_expr(yyvsp[-2].ptr);
	a=get_counter_val();
	drop_counter();
  	print_func_call(yyvsp[-5].str,yyvsp[-2].ptr,a);
   }
    break;

  case 75:
#line 1192 "fgl.yacc"
    {
	print_returning();
	strcpy(yyval.str,yyvsp[-3].str); /* ? */
   }
    break;

  case 76:
#line 1196 "fgl.yacc"
    {
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 77:
#line 1200 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 78:
#line 1202 "fgl.yacc"
    {
        print_expr ((struct expr_str *)yyvsp[-3].ptr);  
	print_call_shared(yyvsp[-6].str,yyvsp[-8].str,atoi(yyvsp[-2].str));
	print_returning();
	print_end_call_shared();
}
    break;

  case 79:
#line 1208 "fgl.yacc"
    {
	sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	A4GLSQL_set_status(0,0);
	new_counter();
	}
    break;

  case 80:
#line 1213 "fgl.yacc"
    {
   	sprintf(yyval.str,"%d",get_counter_val());drop_counter();
}
    break;

  case 81:
#line 1216 "fgl.yacc"
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
#line 1232 "fgl.yacc"
    {
   char buff[256];
   new_counter();
   sprintf(buff,"%s:%s(%p)",yyvsp[-6].str,yyvsp[-4].str,yyvsp[-2].str);
   addmap("External",buff,curr_func,yylineno,infilename);
   }
    break;

  case 83:
#line 1239 "fgl.yacc"
    {
   sprintf(yyval.str,"%d",get_counter_val());drop_counter();
   }
    break;

  case 84:
#line 1243 "fgl.yacc"
    {
	 debug("print_expr (6)");print_expr(yyvsp[-2].ptr);
   }
    break;

  case 85:
#line 1247 "fgl.yacc"
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
#line 1269 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 87:
#line 1269 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 88:
#line 1273 "fgl.yacc"
    {start_bind('i',0);strcpy(yyval.str,"0");}
    break;

  case 89:
#line 1274 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 90:
#line 1275 "fgl.yacc"
    {strcpy(yyval.str,"WITHOUT WAITING"); }
    break;

  case 91:
#line 1280 "fgl.yacc"
    {
			yyval.ptr=new_expr("");
		}
    break;

  case 92:
#line 1283 "fgl.yacc"
    {
			yyval.ptr=yyvsp[0].ptr;
		}
    break;

  case 93:
#line 1289 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 94:
#line 1292 "fgl.yacc"
    {
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
}
    break;

  case 97:
#line 1304 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 98:
#line 1310 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 99:
#line 1313 "fgl.yacc"
    { sprintf(yyval.str,"\"%s.%s\"",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 100:
#line 1328 "fgl.yacc"
    {
push_blockcommand("CASE");
setinc(1);
incprint();
print_case(1);
setinc(1);
}
    break;

  case 101:
#line 1338 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 102:
#line 1344 "fgl.yacc"
    {  push_blockcommand("CASE"); 
setinc(1);
incprint(); 
print_case(0);
setinc(1);
}
    break;

  case 103:
#line 1353 "fgl.yacc"
    {
print_after_when(0);
pop_blockcommand("CASE");
}
    break;

  case 108:
#line 1366 "fgl.yacc"
    {setinc(-1);incprint();}
    break;

  case 110:
#line 1369 "fgl.yacc"
    {
incprint();
}
    break;

  case 111:
#line 1371 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 113:
#line 1377 "fgl.yacc"
    {incprint();}
    break;

  case 114:
#line 1379 "fgl.yacc"
    {incprint();
print_after_when(0);
}
    break;

  case 115:
#line 1384 "fgl.yacc"
    {
print_when(0);

incprint();
}
    break;

  case 116:
#line 1389 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 117:
#line 1395 "fgl.yacc"
    {
incprint();
print_when(1);
}
    break;

  case 118:
#line 1399 "fgl.yacc"
    {incprint();
print_after_when(1);
setinc(-1);}
    break;

  case 119:
#line 1414 "fgl.yacc"
    {
  print_close('F',yyvsp[0].str);
 }
    break;

  case 120:
#line 1417 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 121:
#line 1420 "fgl.yacc"
    {
  print_close('W',yyvsp[0].str);
}
    break;

  case 122:
#line 1423 "fgl.yacc"
    {
  print_close('D',0);
}
    break;

  case 123:
#line 1426 "fgl.yacc"
    {
  print_close('S',yyvsp[0].str);
}
    break;

  case 124:
#line 1429 "fgl.yacc"
    {
  print_close('C',yyvsp[0].str);
}
    break;

  case 130:
#line 1451 "fgl.yacc"
    {
			lex_printc("%s",yyvsp[0].str);
}
    break;

  case 133:
#line 1460 "fgl.yacc"
    {
			lex_printc("%s\n",yyvsp[0].str);
}
    break;

  case 134:
#line 1470 "fgl.yacc"
    {
/* This aint used - its filtered by the lexer first... */
	lex_printc("FIXME : Comment : %s\n");
}
    break;

  case 135:
#line 1484 "fgl.yacc"
    {
push_blockcommand("CONSTRUCT");
}
    break;

  case 136:
#line 1488 "fgl.yacc"
    {
	print_construct_1();
}
    break;

  case 137:
#line 1491 "fgl.yacc"
    {
	print_construct_2(yyvsp[-2].str);
}
    break;

  case 138:
#line 1499 "fgl.yacc"
    {
	print_construct_3(1,yyvsp[-5].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 139:
#line 1505 "fgl.yacc"
    {
	print_construct_3(0,yyvsp[-7].str,yyvsp[0].str);
	strcpy(yyval.str,"form_loop(&_inp_io[0])"); /* FIXME */
	reset_constr();
}
    break;

  case 144:
#line 1520 "fgl.yacc"
    {
                push_construct("",yyval.str);
             }
    break;

  case 145:
#line 1524 "fgl.yacc"
    {
                sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
                push_construct(yyvsp[-2].str,yyvsp[0].str); 
             }
    break;

  case 146:
#line 1529 "fgl.yacc"
    {
                push_construct(yyvsp[-2].str,"*");
             }
    break;

  case 149:
#line 1539 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 150:
#line 1542 "fgl.yacc"
    {
		print_befaft_field_2();

	}
    break;

  case 151:
#line 1546 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
	}
    break;

  case 152:
#line 1548 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 153:
#line 1551 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
	}
    break;

  case 154:
#line 1553 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 155:
#line 1556 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
	}
    break;

  case 156:
#line 1558 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 157:
#line 1561 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
		}
    break;

  case 158:
#line 1564 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 159:
#line 1574 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 160:
#line 1575 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 161:
#line 1583 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 162:
#line 1584 "fgl.yacc"
    {
	  char buff[80];
	  sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	  generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 163:
#line 1601 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_YEAR);");
	}
    break;

  case 164:
#line 1604 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MONTH);");
	}
    break;

  case 165:
#line 1607 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_DAY);");
	}
    break;

  case 166:
#line 1610 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_HOUR);");
	}
    break;

  case 167:
#line 1613 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_MINUTE);");
	}
    break;

  case 168:
#line 1616 "fgl.yacc"
    {
        	yyval.ptr=new_expr("pushop(OP_SECOND);");
	}
    break;

  case 169:
#line 1625 "fgl.yacc"
    {
			yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[-1].ptr);
		}
    break;

  case 170:
#line 1633 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(19*16)+10); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 171:
#line 1638 "fgl.yacc"
    { 
	char buff[50];
	sprintf(buff,"push_int(%d);",(atoi(yyvsp[-2].str)*16) +atoi(yyvsp[0].str)  ); 
	yyval.ptr=new_expr(buff);
}
    break;

  case 172:
#line 1651 "fgl.yacc"
    {
				print_defer(0);
			}
    break;

  case 173:
#line 1655 "fgl.yacc"
    {
				print_defer(1);
			}
    break;

  case 174:
#line 1670 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 175:
#line 1671 "fgl.yacc"
    {strcpy(yyval.str,"");lastlineno=yylineno;}
    break;

  case 178:
#line 1679 "fgl.yacc"
    {dtypelist[0]=0;lex_printcomment("/* define */\n");}
    break;

  case 179:
#line 1679 "fgl.yacc"
    {lex_printcomment("/*end def */\n");}
    break;

  case 185:
#line 1689 "fgl.yacc"
    {in_define=1;}
    break;

  case 186:
#line 1689 "fgl.yacc"
    {in_define=0;strcpy(yyval.str,yyvsp[0].str);
                        set_yytext(yyval.str);
                        if (bad_identifiers(yyval.str)) {
                                a4gl_yyerror("You can't use this identifier as it is a reserved word in the target language");
                        }
}
    break;

  case 187:
#line 1698 "fgl.yacc"
    { add_constant('c',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 188:
#line 1699 "fgl.yacc"
    { add_constant('C',yyvsp[0].str,yyvsp[-2].str); addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename); }
    break;

  case 189:
#line 1700 "fgl.yacc"
    { add_constant('f',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 190:
#line 1703 "fgl.yacc"
    { 
add_constant('i',yyvsp[0].str,yyvsp[-2].str);
addmap("Constant",yyvsp[-2].str,curr_func,yylineno,infilename);
 }
    break;

  case 192:
#line 1708 "fgl.yacc"
    { }
    break;

  case 193:
#line 1708 "fgl.yacc"
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
#line 1725 "fgl.yacc"
    {
		sprintf(yyval.str,"-%p",yyvsp[0].str);}
    break;

  case 198:
#line 1729 "fgl.yacc"
    {
/*AF CygWin FIX */
push_name(yyval.str,0);
addmap("Define",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 203:
#line 1743 "fgl.yacc"
    {
	debug("defines array %s",yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 205:
#line 1752 "fgl.yacc"
    {
	push_associate(yyvsp[-5].str,yyvsp[-1].str);
	push_type(0,0,yyvsp[-1].str);
}
    break;

  case 206:
#line 1756 "fgl.yacc"
    {
    /* void pop_associate (char *a); */
	pop_associate(0);

}
    break;

  case 212:
#line 1772 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s][%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str); debug("Triplet");}
    break;

  case 213:
#line 1774 "fgl.yacc"
    {sprintf(yyval.str,"%s][%s",yyvsp[-2].str,yyvsp[0].str); debug("double");}
    break;

  case 214:
#line 1775 "fgl.yacc"
    {debug("Single");}
    break;

  case 216:
#line 1782 "fgl.yacc"
    {push_record();in_record++;}
    break;

  case 217:
#line 1782 "fgl.yacc"
    {pop_record();in_record--;}
    break;

  case 218:
#line 1783 "fgl.yacc"
    {in_record++;push_record();debug("Like\n");}
    break;

  case 219:
#line 1784 "fgl.yacc"
    {debug("Link Table : %s\n",yyvsp[-2].str);
                  push_rectab(yyvsp[-2].str);
                  pop_record();in_record--;}
    break;

  case 220:
#line 1787 "fgl.yacc"
    {
		push_record();debug("Like\n");}
    break;

  case 221:
#line 1789 "fgl.yacc"
    {
		  debug("Table:%s\n",yyvsp[-4].str);
		  add_link_to(yyvsp[-4].str,yyvsp[-1].str);
	          debug("Push record...\n");
                  push_rectab(yyvsp[-4].str);
                  pop_record();
}
    break;

  case 223:
#line 1799 "fgl.yacc"
    {
	sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 228:
#line 1814 "fgl.yacc"
    {start_state("dtype",1);}
    break;

  case 229:
#line 1814 "fgl.yacc"
    {start_state("dtype",0);}
    break;

  case 233:
#line 1820 "fgl.yacc"
    {push_type("char","1",0);}
    break;

  case 234:
#line 1821 "fgl.yacc"
    {
/* char buff[80]; */
if (atoi(yyvsp[-1].str)==4) {
	addmap("size=4","----",curr_func,yylineno,infilename);
}
push_type("char",yyvsp[-1].str,0);
}
    break;

  case 235:
#line 1828 "fgl.yacc"
    {push_type("char",yyvsp[-1].str,0);}
    break;

  case 236:
#line 1829 "fgl.yacc"
    {push_type("char",yyvsp[-3].str,0);}
    break;

  case 237:
#line 1830 "fgl.yacc"
    {push_type("long",0,0);}
    break;

  case 238:
#line 1831 "fgl.yacc"
    {
debug("Using specified type...");
push_dim(yyvsp[0].str);}
    break;

  case 239:
#line 1834 "fgl.yacc"
    {push_type("int",0,0);}
    break;

  case 240:
#line 1835 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 241:
#line 1836 "fgl.yacc"
    {push_type("form",0,0);}
    break;

  case 242:
#line 1837 "fgl.yacc"
    { char buff[256];
				sprintf(buff,"%d",16*256+2);
				push_type("fgldecimal",buff,0);
				}
    break;

  case 243:
#line 1841 "fgl.yacc"
    {
				char buff[256];
				sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
				push_type("fgldecimal",buff,0);
}
    break;

  case 244:
#line 1846 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fgldecimal",buff,0);
}
    break;

  case 245:
#line 1851 "fgl.yacc"
    {
			char buff[256];
			sprintf(buff,"%d",16*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 246:
#line 1855 "fgl.yacc"
    {
		char buff[256];sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
			push_type("fglmoney",buff,0);}
    break;

  case 247:
#line 1858 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
push_type("fglmoney",buff,0);}
    break;

  case 248:
#line 1862 "fgl.yacc"
    {push_type("double",0,0);}
    break;

  case 249:
#line 1863 "fgl.yacc"
    {push_type("float",0,0);}
    break;

  case 250:
#line 1864 "fgl.yacc"
    {push_type("fgldate",0,0);}
    break;

  case 251:
#line 1865 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 252:
#line 1866 "fgl.yacc"
    {push_type("fglbyte",0,0);}
    break;

  case 253:
#line 1867 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 254:
#line 1868 "fgl.yacc"
    {push_type("fgltext",0,0);}
    break;

  case 255:
#line 1869 "fgl.yacc"
    {
push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 256:
#line 1872 "fgl.yacc"
    {push_type("struct_ival",yyvsp[0].str,0);}
    break;

  case 257:
#line 1873 "fgl.yacc"
    {push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 258:
#line 1874 "fgl.yacc"
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
#line 1906 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/"); sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str); lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 260:
#line 1910 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 261:
#line 1912 "fgl.yacc"
    {debug("--->%s\n",yyvsp[0].str);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 262:
#line 1914 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 263:
#line 1916 "fgl.yacc"
    {
debug("Real datetime %s to %s\n",yyvsp[-2].str,yyvsp[0].str);
sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); }
    break;

  case 264:
#line 1921 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",(atoi(yyvsp[-2].str)*16)+atoi(yyvsp[0].str)); 
}
    break;

  case 265:
#line 1925 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 266:
#line 1925 "fgl.yacc"
    {start_state("dtime_val",0); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 267:
#line 1929 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 268:
#line 1930 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 269:
#line 1931 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 270:
#line 1932 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 271:
#line 1933 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 272:
#line 1934 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 273:
#line 1936 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 274:
#line 1941 "fgl.yacc"
    {start_state("dtime_val",1);}
    break;

  case 275:
#line 1941 "fgl.yacc"
    { debug ("Got end");start_state("dtime_val",0);  strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 276:
#line 1944 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 277:
#line 1946 "fgl.yacc"
    {
debug("Read fraction .. ");
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 278:
#line 1952 "fgl.yacc"
    {
debug("Nothing in fraction - assume 2");
strcpy(yyval.str,"2");}
    break;

  case 279:
#line 1954 "fgl.yacc"
    {
debug("    %s",yyvsp[-1].str);
strcpy(yyval.str,yyvsp[-1].str);
}
    break;

  case 280:
#line 1960 "fgl.yacc"
    {
if (atoi(yyvsp[0].str)>5) {
a4gl_yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
    break;

  case 281:
#line 1968 "fgl.yacc"
    {start_state("interval_val",1);}
    break;

  case 282:
#line 1968 "fgl.yacc"
    {start_state("interval_val",0); sprintf(yyval.str,"%d",atoi(yyvsp[0].str)*16+atoi(yyvsp[-1].str));}
    break;

  case 283:
#line 1971 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 284:
#line 1972 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 285:
#line 1973 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 286:
#line 1974 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 287:
#line 1975 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 288:
#line 1976 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 289:
#line 1978 "fgl.yacc"
    {
debug("opt_frac returns %s",yyvsp[0].str);
sprintf(yyval.str,"%d",atoi(yyvsp[0].str)+6); }
    break;

  case 293:
#line 1999 "fgl.yacc"
    {
              	dim_set_name(yyvsp[0].str);
              }
    break;

  case 297:
#line 2008 "fgl.yacc"
    {dim_push_type("char","1",0);}
    break;

  case 298:
#line 2010 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 299:
#line 2012 "fgl.yacc"
    {dim_push_type("char",yyvsp[-1].str,0);}
    break;

  case 300:
#line 2014 "fgl.yacc"
    {dim_push_type("char",yyvsp[-3].str,0);}
    break;

  case 301:
#line 2015 "fgl.yacc"
    {dim_push_type("long",0,0);}
    break;

  case 302:
#line 2016 "fgl.yacc"
    {dim_push_type("integer",0,0);}
    break;

  case 303:
#line 2017 "fgl.yacc"
    {dim_push_type("FORM",0,0);}
    break;

  case 304:
#line 2018 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",16*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 305:
#line 2023 "fgl.yacc"
    {

char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-1].str)*256+2);
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 306:
#line 2030 "fgl.yacc"
    {
char buff[256];
sprintf(buff,"%d",atoi(yyvsp[-3].str)*256+atoi(yyvsp[-1].str));
dim_push_type("fgldecimal",buff,0);
}
    break;

  case 307:
#line 2035 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 308:
#line 2037 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 309:
#line 2039 "fgl.yacc"
    {dim_push_type("fglmoney",0,0);}
    break;

  case 310:
#line 2040 "fgl.yacc"
    {dim_push_type("double",0,0);}
    break;

  case 311:
#line 2041 "fgl.yacc"
    {dim_push_type("float",0,0);}
    break;

  case 312:
#line 2042 "fgl.yacc"
    {dim_push_type("fgldate",0,0);}
    break;

  case 313:
#line 2043 "fgl.yacc"
    {dim_push_type("fglbyte",0,0);}
    break;

  case 314:
#line 2044 "fgl.yacc"
    {dim_push_type("fgltext",0,0);}
    break;

  case 315:
#line 2045 "fgl.yacc"
    {
dim_push_type("struct_dtime",yyvsp[0].str,0);
}
    break;

  case 316:
#line 2048 "fgl.yacc"
    {dim_push_type("struct_ival",0,0);}
    break;

  case 317:
#line 2050 "fgl.yacc"
    {dim_push_like(yyvsp[0].str);lex_printcomment("/*added(XXXXX)\n */");}
    break;

  case 318:
#line 2056 "fgl.yacc"
    {
lex_printcomment("/*column like(ZZZ)\n*/");
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str)
; lex_printcomment ("/*set col...(ZZZ)\n*/");}
    break;

  case 319:
#line 2064 "fgl.yacc"
    {
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 321:
#line 2072 "fgl.yacc"
    {
dim_push_associate(yyvsp[-5].str,yyvsp[-1].str);
dim_push_type(0,0,yyvsp[-1].str);
}
    break;

  case 322:
#line 2076 "fgl.yacc"
    {
	/* void dim_pop_associate (char *a); */
	dim_pop_associate(0);
}
    break;

  case 323:
#line 2084 "fgl.yacc"
    {dim_push_record();}
    break;

  case 324:
#line 2085 "fgl.yacc"
    {dim_pop_record();}
    break;

  case 325:
#line 2086 "fgl.yacc"
    {dim_push_record();debug("Like\n");}
    break;

  case 326:
#line 2087 "fgl.yacc"
    {debug("Table:%s\n",yyvsp[-2].str);
                                  dim_push_rectab(yyvsp[-2].str);
                                  dim_pop_record();}
    break;

  case 332:
#line 2106 "fgl.yacc"
    { dim_push_name(yyval.str,0); }
    break;

  case 333:
#line 2118 "fgl.yacc"
    {
	print_display_line();
		strcpy(yyval.str,get_display_str(0,0,0));
	}
    break;

  case 334:
#line 2122 "fgl.yacc"
    {
		strcpy(yyval.str,get_display_str(1,0,0)); /* FIXME */
	}
    break;

  case 335:
#line 2125 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
	}
    break;

  case 336:
#line 2128 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(4,0,0)); }
    break;

  case 337:
#line 2129 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(2,yyvsp[0].str,0)); }
    break;

  case 338:
#line 2130 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(3,yyvsp[0].str,yyvsp[-2].str)); }
    break;

  case 339:
#line 2131 "fgl.yacc"
    { strcpy(yyval.str, get_display_str(5,yyvsp[-1].str,0)); }
    break;

  case 340:
#line 2132 "fgl.yacc"
    { 
	strcpy(yyval.str,"#error not implemented yet");
 }
    break;

  case 341:
#line 2138 "fgl.yacc"
    {
		print_display_by_name(yyvsp[0].str);
                }
    break;

  case 342:
#line 2145 "fgl.yacc"
    { 
				print_display(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 343:
#line 2150 "fgl.yacc"
    {
		print_display_form(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 344:
#line 2155 "fgl.yacc"
    {
		push_blockcommand("DISPLAY");
		}
    break;

  case 345:
#line 2159 "fgl.yacc"
    {
		print_display_array_p1(yyvsp[-6].str,yyvsp[-4].str,yyvsp[-1].str,yyvsp[0].str);
		}
    break;

  case 346:
#line 2162 "fgl.yacc"
    {
		add_continue_blockcommand ("DISPLAY");  
		print_display_array_p2();
		pop_blockcommand("DISPLAY");
}
    break;

  case 347:
#line 2170 "fgl.yacc"
    {
strcpy(yyval.str,"0,0");
}
    break;

  case 348:
#line 2172 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 349:
#line 2177 "fgl.yacc"
    {
				sprintf(yyval.str,"0x%lx",atol(yyvsp[0].str));
			}
    break;

  case 354:
#line 2189 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
		}
    break;

  case 355:
#line 2192 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 356:
#line 2195 "fgl.yacc"
    {
		print_befaft_field_1("BEF_ROW");
		}
    break;

  case 357:
#line 2198 "fgl.yacc"
    {
		print_befaft_field_2();
	}
    break;

  case 358:
#line 2201 "fgl.yacc"
    {
		print_onkey_1(yyvsp[0].str);
		}
    break;

  case 359:
#line 2204 "fgl.yacc"
    {
		print_onkey_2();
	}
    break;

  case 360:
#line 2217 "fgl.yacc"
    {
			print_error(yyvsp[0].str,0);
		}
    break;

  case 361:
#line 2220 "fgl.yacc"
    { 
			print_error(yyvsp[-1].str,1);
	}
    break;

  case 362:
#line 2235 "fgl.yacc"
    { if (in_command("WHILE")) { exit_loop("WHILE"); } else { YYERROR;} }
    break;

  case 363:
#line 2237 "fgl.yacc"
    { if (in_command("INPUT")) { exit_loop("INPUT"); } else { YYERROR;} }
    break;

  case 364:
#line 2239 "fgl.yacc"
    { if (in_command("FOREACH")) { exit_loop("FOREACH"); } else { YYERROR;} }
    break;

  case 365:
#line 2241 "fgl.yacc"
    { if (in_command("FOR")) { exit_loop("FOR"); } else { YYERROR;} }
    break;

  case 366:
#line 2243 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { exit_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 367:
#line 2245 "fgl.yacc"
    { if (in_command("DISPLAY")) { exit_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 368:
#line 2246 "fgl.yacc"
    {
	if (in_command("MENU")) {
		exit_loop("MENU");
		/* lex_printc("cmd_no=-3;continue;\n"); */
	} 
              else YYERROR;}
    break;

  case 369:
#line 2253 "fgl.yacc"
    { if (in_command("CASE")) { exit_loop("CASE"); } else { YYERROR;} }
    break;

  case 370:
#line 2255 "fgl.yacc"
    { if (in_command("PROMPT")) { exit_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 371:
#line 2259 "fgl.yacc"
    { if (in_command("WHILE")) { continue_loop("WHILE");  } else { YYERROR;} }
    break;

  case 372:
#line 2261 "fgl.yacc"
    { if (in_command("INPUT")) { continue_loop("INPUT"); } else { YYERROR;} }
    break;

  case 373:
#line 2263 "fgl.yacc"
    { if (in_command("FOREACH")) { continue_loop("FOREACH");} else { YYERROR;} }
    break;

  case 374:
#line 2265 "fgl.yacc"
    { if (in_command("FOR")) { continue_loop("FOR"); } else { YYERROR;} }
    break;

  case 375:
#line 2267 "fgl.yacc"
    { if (in_command("CONSTRUCT")) { continue_loop("CONSTRUCT"); } else { YYERROR;} }
    break;

  case 376:
#line 2269 "fgl.yacc"
    { if (in_command("DISPLAY")) { continue_loop("DISPLAY"); } else { YYERROR;} }
    break;

  case 377:
#line 2271 "fgl.yacc"
    { if (in_command("MENU")) {  continue_loop("MENU");  } else { YYERROR;} }
    break;

  case 378:
#line 2277 "fgl.yacc"
    { if (in_command("PROMPT")) { continue_loop("PROMPT"); } else { YYERROR;} }
    break;

  case 379:
#line 2291 "fgl.yacc"
    {
	print_exit_program(0);
}
    break;

  case 380:
#line 2294 "fgl.yacc"
    {
	print_exit_program(1);
}
    break;

  case 385:
#line 2311 "fgl.yacc"
    {
	dec_counter();
	yyval.ptr=append_expr_expr(yyvsp[-1].ptr,yyvsp[0].ptr);
}
    break;

  case 388:
#line 2317 "fgl.yacc"
    {
	debug("Got literal ptr=%p",yyvsp[0].ptr);
}
    break;

  case 389:
#line 2321 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(0);");
	yyval.ptr=append_expr_expr(yyval.ptr,yyvsp[0].ptr);
	yyval.ptr=append_expr(yyval.ptr,"pushop(OP_SUB);");
}
    break;

  case 390:
#line 2326 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
}
    break;

  case 394:
#line 2336 "fgl.yacc"
    { yyval.ptr=new_expr("add_spaces();"); }
    break;

  case 401:
#line 2347 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 402:
#line 2347 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 404:
#line 2352 "fgl.yacc"
    {yyval.ptr=new_expr("push_null()");}
    break;

  case 405:
#line 2356 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 406:
#line 2362 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 407:
#line 2370 "fgl.yacc"
    {
	/*set_counter(0);*/
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L1 %s*/\n",yyval.str);
}
    break;

  case 408:
#line 2376 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());
	lex_printcomment("/*L2 %s*/\n",yyval.str);
}
    break;

  case 409:
#line 2385 "fgl.yacc"
    {sprintf(yyval.str,"%d",get_counter_val());}
    break;

  case 410:
#line 2387 "fgl.yacc"
    {
	print_op("OP_CONCAT");
	dec_counter();sprintf(yyval.str,"%d",get_counter_val());
}
    break;

  case 411:
#line 2394 "fgl.yacc"
    {
	debug("Print expr (2)");
	print_expr(yyvsp[0].ptr);
}
    break;

  case 412:
#line 2402 "fgl.yacc"
    {
	strcpy(yyval.str,"+");
}
    break;

  case 413:
#line 2406 "fgl.yacc"
    {
	strcpy(yyval.str,"-");
}
    break;

  case 414:
#line 2415 "fgl.yacc"
    {
	
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT);");
}
    break;

  case 415:
#line 2420 "fgl.yacc"
    {
	yyval.ptr=new_expr("push_int(1);");
        inc_counter();
}
    break;

  case 416:
#line 2425 "fgl.yacc"
    {
	inc_counter();
	yyval.ptr=new_expr("push_int(0);");
}
    break;

  case 417:
#line 2429 "fgl.yacc"
    { yyval.ptr=yyvsp[-1].ptr; }
    break;

  case 418:
#line 2431 "fgl.yacc"
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
#line 2441 "fgl.yacc"
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
#line 2455 "fgl.yacc"
    {
	debug("init expr %s %s",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('D',yyval.str));
	yyval.ptr=new_expr(yyval.str);
        inc_counter();
}
    break;

  case 421:
#line 2463 "fgl.yacc"
    {
	debug("init expr int %s %d",yyvsp[-1].str,atoi(yyvsp[0].str));
	sprintf(yyval.str,"%s%p",yyvsp[-1].str,yyvsp[0].str);
	sprintf(yyval.str,"%s",get_push_literal('L',yyval.str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 422:
#line 2475 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('S',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 423:
#line 2481 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('D',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 424:
#line 2487 "fgl.yacc"
    {
	sprintf(yyval.str,"%s",get_push_literal('L',yyvsp[0].str));
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 427:
#line 2497 "fgl.yacc"
    {
		sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 428:
#line 2503 "fgl.yacc"
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
#line 2575 "fgl.yacc"
    {
	sprintf(yyval.str,"%sset_column(&rep);",ispdf());
	yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 430:
#line 2581 "fgl.yacc"
    {
sprintf(yyval.str,"%sset_column(&rep);",ispdf());
yyval.ptr=append_expr(yyvsp[0].ptr,yyval.str);
}
    break;

  case 431:
#line 2585 "fgl.yacc"
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
#line 2593 "fgl.yacc"
    {insql=1;set_ingroup();}
    break;

  case 433:
#line 2593 "fgl.yacc"
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
#line 2609 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_AND);");
}
    break;

  case 435:
#line 2613 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_OR);");
}
    break;

  case 436:
#line 2619 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
	}
    break;

  case 437:
#line 2622 "fgl.yacc"
    {
		debug("Adding to list...");
		yyval.ptr=append_expr_expr(yyvsp[-2].ptr,yyvsp[0].ptr);
	}
    break;

  case 438:
#line 2630 "fgl.yacc"
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
#line 2641 "fgl.yacc"
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
#line 2651 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_IN);");
}
    break;

  case 441:
#line 2657 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"push_int(%d);",length_expr(yyvsp[-1].ptr));
	yyval.ptr=append_expr(yyvsp[-1].ptr,buff);
	append_expr(yyval.ptr,"pushop(OP_NOTIN);");
}
    break;

  case 442:
#line 2667 "fgl.yacc"
    { 
	strcpy(yyval.str,"pushop(OP_ISNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 443:
#line 2672 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_ISNOTNULL);");
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 444:
#line 2679 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_char(\"\\\\\");pushop(OP_MATCHES);");
 }
    break;

  case 445:
#line 2682 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_char(\"\\\\\");pushop(OP_MATCHES);pushop(OP_NOT);");
}
    break;

  case 446:
#line 2685 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_MATCHES);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
 }
    break;

  case 447:
#line 2690 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_MATCHES);pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 448:
#line 2697 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(\"\\\\\");pushop(OP_LIKE);");
	yyval.ptr=append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 449:
#line 2702 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(\"\\\\\");pushop(OP_LIKE);pushop(OP_NOT);");
	yyval.ptr=append_expr(yyvsp[0].ptr,buff);
}
    break;

  case 450:
#line 2707 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_LIKE);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 451:
#line 2712 "fgl.yacc"
    {
	char buff[40];
	sprintf(buff,"push_char(%s);pushop(OP_LIKE);pushop(OP_NOT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[-2].ptr,buff);
}
    break;

  case 452:
#line 2723 "fgl.yacc"
    {
	strcpy(yyval.str,"pushop(OP_CLIP);");
	yyval.ptr=new_expr(yyval.str);
	inc_counter();
}
    break;

  case 453:
#line 2731 "fgl.yacc"
    {
	sprintf(yyval.str,"%s pushop(OP_USING);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_USING);");
}
    break;

  case 454:
#line 2739 "fgl.yacc"
    {
	debug("PLUS in math_expr $<ptr>2 = %p",yyvsp[0].ptr);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_ADD);");
}
    break;

  case 455:
#line 2744 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_SUB);");
}
    break;

  case 456:
#line 2748 "fgl.yacc"
    {
      sprintf(yyval.str,"%s pushop(OP_MULT);",yyvsp[0].str);
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MULT);");
}
    break;

  case 457:
#line 2753 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_DIV);");
}
    break;

  case 458:
#line 2757 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_MOD);");
}
    break;

  case 459:
#line 2761 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_POWER);");
}
    break;

  case 460:
#line 2767 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 461:
#line 2770 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_EQUAL);");
}
    break;

  case 462:
#line 2774 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN);");
}
    break;

  case 463:
#line 2778 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN);");
}
    break;

  case 464:
#line 2782 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_NOT_EQUAL);");
}
    break;

  case 465:
#line 2786 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_LESS_THAN_EQ);");
}
    break;

  case 466:
#line 2790 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[0].ptr,"pushop(OP_GREATER_THAN_EQ);");
}
    break;

  case 467:
#line 2797 "fgl.yacc"
    {
	reset_counter();
}
    break;

  case 468:
#line 2807 "fgl.yacc"
    { 
		addmap("Call",yyvsp[-1].str,curr_func,yylineno,infilename);
		new_counter(); 
		}
    break;

  case 469:
#line 2812 "fgl.yacc"
    { 
		sprintf(yyval.str,"%d",get_counter_val()); 
		lex_printcomment("/*function_call_expr2 %s*/\n",yyval.str);
		drop_counter(); 
		}
    break;

  case 470:
#line 2818 "fgl.yacc"
    {
		int cnt;
		cnt=1;
		debug("Print expr (1)");
		/* print_expr($<ptr>4); */

		strcpy(yyval.str,expr_for_call(yyvsp[-5].str,yyvsp[-1].str,lastlineno,infilename));
		yyval.ptr=append_expr(yyvsp[-2].ptr,yyval.str);
		inc_counter();
		}
    break;

  case 471:
#line 2828 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\",\"%s\"",yyvsp[-3].str,yyvsp[-1].str);
	debug("NEWFORMAT : %s\n",yyval.str);
        A4GLSQL_set_status(0,0);
        new_counter();
}
    break;

  case 472:
#line 2833 "fgl.yacc"
    {
	sprintf(yyval.str,"%d",get_counter_val());  
	drop_counter();
}
    break;

  case 473:
#line 2836 "fgl.yacc"
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
#line 2850 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 475:
#line 2850 "fgl.yacc"
    {chk4var=0;}
    break;

  case 476:
#line 2850 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_date(1);");
inc_counter();}
    break;

  case 477:
#line 2853 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 478:
#line 2853 "fgl.yacc"
    {chk4var=0;}
    break;

  case 479:
#line 2853 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_month(1);");
inc_counter();}
    break;

  case 480:
#line 2856 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 481:
#line 2856 "fgl.yacc"
    {chk4var=0;}
    break;

  case 482:
#line 2856 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_day(1);");
inc_counter();}
    break;

  case 483:
#line 2859 "fgl.yacc"
    {inc_counter();chk4var=1;}
    break;

  case 484:
#line 2859 "fgl.yacc"
    {chk4var=0;}
    break;

  case 485:
#line 2859 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-2].ptr,"aclfgl_year(1);");
inc_counter();}
    break;

  case 486:
#line 2862 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_interval(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 487:
#line 2868 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(%s,%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 488:
#line 2874 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s\",%s);",yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 489:
#line 2880 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"acli_datetime(\"%s:%s\",%s);",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
	yyval.ptr=new_expr(buff);
	inc_counter();
}
    break;

  case 490:
#line 2890 "fgl.yacc"
    {strcpy(yyval.str,"-1,-1");}
    break;

  case 491:
#line 2891 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 494:
#line 2899 "fgl.yacc"
    {
sprintf(yyval.str,"{int _retvars;\n_retvars=fgl_getfldbuf(%s);\nif (_retvars != 1 ) {A4GLSQL_set_status(-3001,0);chk_err(%d,\"%s\");}\n}\n",
	yyvsp[-1].str, lastlineno,infilename); 
	yyval.ptr=new_expr(yyval.str);

}
    break;

  case 495:
#line 2905 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); }
    break;

  case 496:
#line 2906 "fgl.yacc"
    {
sprintf(yyval.str,"push_int(fgl_fieldnametoid(\"\",%s));",yyvsp[-1].str); yyval.ptr=new_expr(yyval.str); 
addmap("Get Field",yyvsp[-1].str,curr_func,yylineno,infilename);
}
    break;

  case 497:
#line 2911 "fgl.yacc"
    {sprintf(yyval.str,"push_int(fgl_infield(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 498:
#line 2915 "fgl.yacc"
    { sprintf(yyval.str,"push_int(fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 499:
#line 2919 "fgl.yacc"
    { sprintf(yyval.str,"push_int(!fgl_fieldtouched(%s));",yyvsp[-1].str); 
	yyval.ptr=new_expr(yyval.str);
}
    break;

  case 502:
#line 2926 "fgl.yacc"
    {
		inc_counter();
               sprintf(yyval.str,"push_current(%s);",yyvsp[0].str);
		yyval.ptr=new_expr(yyval.str);
          	}
    break;

  case 503:
#line 2931 "fgl.yacc"
    { inc_counter(); strcpy(yyval.str,"push_today();");
		yyval.ptr=new_expr(yyval.str);
		}
    break;

  case 504:
#line 2938 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"upshift_stk();");
}
    break;

  case 505:
#line 2942 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[-1].ptr,"downshift_stk();");
}
    break;

  case 506:
#line 2945 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"push_ascii();");
}
    break;

  case 507:
#line 2948 "fgl.yacc"
    { 
	yyval.ptr=append_expr(yyvsp[0].ptr,"aclfgli_extend();"); }
    break;

  case 508:
#line 2954 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-1);pushop(OP_MULT);");
}
    break;

  case 509:
#line 2957 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-28.3465);pushop(OP_MULT);");
}
    break;

  case 510:
#line 2960 "fgl.yacc"
    {
	yyval.ptr=append_expr(yyvsp[-1].ptr,"push_double(-72.0);pushop(OP_MULT);");
}
    break;

  case 511:
#line 2975 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 512:
#line 2978 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 513:
#line 2984 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 514:
#line 2985 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 515:
#line 2986 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 517:
#line 2991 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 518:
#line 2992 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 519:
#line 2993 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 520:
#line 2994 "fgl.yacc"
    {sprintf(yyval.str,"%s %s:%s:%s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 521:
#line 2996 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 522:
#line 2997 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 523:
#line 2998 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s:%s",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 524:
#line 3000 "fgl.yacc"
    {sprintf(yyval.str,"%s:%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 525:
#line 3001 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 527:
#line 3007 "fgl.yacc"
    {sprintf(yyval.str,"%s-%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 528:
#line 3020 "fgl.yacc"
    {
print_for_start(yyvsp[-5].str);
push_blockcommand("FOR");
}
    break;

  case 529:
#line 3024 "fgl.yacc"
    {debug("For_cmds\n");}
    break;

  case 530:
#line 3025 "fgl.yacc"
    {

pop_blockcommand("FOR");
print_for_end();
lex_printcomment(" /*END FOR*/\n");}
    break;

  case 531:
#line 3032 "fgl.yacc"
    {
		print_for_default_step();
	}
    break;

  case 533:
#line 3049 "fgl.yacc"
    {
push_blockcommand("FOREACH");
}
    break;

  case 534:
#line 3053 "fgl.yacc"
    {
print_foreach_start();
lex_printcomment(" /* foreach */\n");
}
    break;

  case 535:
#line 3058 "fgl.yacc"
    {
print_foreach_next(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 536:
#line 3062 "fgl.yacc"
    {
add_continue_blockcommand ("FOREACH");
print_foreach_end();
pop_blockcommand("FOREACH");
}
    break;

  case 537:
#line 3078 "fgl.yacc"
    {
		sprintf(curr_func,"%s",yyvsp[0].str); 
		print_formhandler(yyvsp[0].str);
		start_state("formhandler",1);
	push_blockcommand("FORMHANDLER");
        }
    break;

  case 538:
#line 3084 "fgl.yacc"
    {
		print_variables();
		print_getwin();
	}
    break;

  case 539:
#line 3092 "fgl.yacc"
    {
pop_blockcommand("FORMHANDLER");
print_end_formhandler(); 
start_state("formhandler",0);}
    break;

  case 546:
#line 3109 "fgl.yacc"
    {
		print_event('B');
        }
    break;

  case 547:
#line 3111 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 548:
#line 3114 "fgl.yacc"
    {
		print_event('b');
        }
    break;

  case 549:
#line 3116 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 554:
#line 3130 "fgl.yacc"
    {
		print_event('A');
        }
    break;

  case 555:
#line 3132 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 556:
#line 3135 "fgl.yacc"
    {
		print_event('a');
        }
    break;

  case 557:
#line 3137 "fgl.yacc"
    {
		print_event_2();
        }
    break;

  case 570:
#line 3168 "fgl.yacc"
    { 
			print_gtk_field('B',0);
		}
    break;

  case 571:
#line 3170 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 572:
#line 3173 "fgl.yacc"
    { 
			print_gtk_field('A',0);
		}
    break;

  case 573:
#line 3175 "fgl.yacc"
    {
			print_gtk_field_2();
		}
    break;

  case 574:
#line 3178 "fgl.yacc"
    {
			print_gtk_field('b',yyvsp[0].str);
		}
    break;

  case 575:
#line 3180 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 576:
#line 3183 "fgl.yacc"
    {
			print_gtk_field('a',yyvsp[0].str);
		}
    break;

  case 577:
#line 3185 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 578:
#line 3188 "fgl.yacc"
    { 
			print_gtk_field('o',yyvsp[0].str);
		}
    break;

  case 579:
#line 3190 "fgl.yacc"
    { 
			print_gtk_field_2();
		}
    break;

  case 580:
#line 3205 "fgl.yacc"
    {
		//print_niy("Free Cursor");
		lex_printcomment(" /* FIXME: Not implemented: Free Cursor */\n");;

		strcpy(yyval.str,"");
		}
    break;

  case 581:
#line 3221 "fgl.yacc"
    {sprintf(yyval.str,"%d",-1-(atoi(yyvsp[0].str)));}
    break;

  case 582:
#line 3222 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 583:
#line 3223 "fgl.yacc"
    {sprintf (yyval.str,"%d",atoi(yyvsp[0].str)+1);}
    break;

  case 584:
#line 3224 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 585:
#line 3225 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 586:
#line 3226 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 590:
#line 3234 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 592:
#line 3240 "fgl.yacc"
    {
			sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 593:
#line 3242 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s)",yyvsp[-1].str); }
    break;

  case 594:
#line 3243 "fgl.yacc"
    { sprintf(yyval.str,"int_to_id(%s.%s)",yyvsp[-5].str,yyvsp[-1].str); }
    break;

  case 595:
#line 3245 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 596:
#line 3247 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 597:
#line 3249 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 598:
#line 3251 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 599:
#line 3253 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 600:
#line 3256 "fgl.yacc"
    {
				print_pushchar(yyvsp[0].str);
				addmap("Cursor",last_var,curr_func,yylineno,infilename);
			}
    break;

  case 601:
#line 3263 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 602:
#line 3265 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 603:
#line 3271 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Window",last_var,curr_func,yylineno,infilename);
}
    break;

  case 604:
#line 3276 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 605:
#line 3281 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);
addmap("Open Form",last_var,curr_func,yylineno,infilename);
}
    break;

  case 606:
#line 3286 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 607:
#line 3286 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 608:
#line 3289 "fgl.yacc"
    { 
			strcpy(yyval.str,downshift(yyvsp[0].str)) ;
}
    break;

  case 609:
#line 3295 "fgl.yacc"
    {
			sprintf(yyval.str,"%s",yyvsp[0].str) ;
			}
    break;

  case 610:
#line 3300 "fgl.yacc"
    {
sprintf(yyval.str,"\"%s_%s\"",clobber,downshift(yyvsp[0].str)) ;
strcpy(last_var,downshift(yyvsp[0].str));
}
    break;

  case 611:
#line 3304 "fgl.yacc"
    {
		sprintf(yyval.str,"aclfgli_str_to_id(%s)",yyvsp[-1].str);
		sprintf(last_var,"->%s",yyvsp[-1].str);
	}
    break;

  case 614:
#line 3312 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",1",yyvsp[0].str);}
    break;

  case 615:
#line 3314 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\",%s",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 616:
#line 3316 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",1",yyvsp[-2].str);}
    break;

  case 617:
#line 3318 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.*\",%s",yyvsp[-5].str,yyvsp[-3].str);}
    break;

  case 618:
#line 3320 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",1",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 619:
#line 3322 "fgl.yacc"
    {sprintf(yyval.str,"\"%s.%s\",%s",yyvsp[-5].str,yyvsp[0].str,yyvsp[-3].str);}
    break;

  case 620:
#line 3325 "fgl.yacc"
    {
debug("Scanvar=%d",scan_variable(yyvsp[0].str)&15);
if ((scan_variable(yyvsp[0].str)&15)!=0) {
a4gl_yyerror("Only a character variable can be used for this");
YYERROR;
}
}
    break;

  case 622:
#line 3334 "fgl.yacc"
    {
		sprintf(yyval.str,".%s",yyvsp[0].str);
}
    break;

  case 666:
#line 3395 "fgl.yacc"
    {
	char buff[256];
	print_goto(yyvsp[0].str);
}
    break;

  case 667:
#line 3409 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'C');
}
    break;

  case 669:
#line 3416 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 670:
#line 3419 "fgl.yacc"
    {
        sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 671:
#line 3425 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'U');
}
    break;

  case 672:
#line 3431 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'D');
}
    break;

  case 673:
#line 3435 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'D');
}
    break;

  case 674:
#line 3439 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'D');
}
    break;

  case 675:
#line 3445 "fgl.yacc"
    {
print_gui_do_menuitems(yyvsp[0].str,'E');
}
    break;

  case 676:
#line 3449 "fgl.yacc"
    {
print_gui_do_fields(yyvsp[0].str,'E');
}
    break;

  case 677:
#line 3453 "fgl.yacc"
    {
print_gui_do_form(yyvsp[-2].str,yyvsp[0].str,'E');
}
    break;

  case 678:
#line 3458 "fgl.yacc"
    {start_state("messagebox",1);}
    break;

  case 679:
#line 3463 "fgl.yacc"
    {start_state("messagebox",0);}
    break;

  case 698:
#line 3504 "fgl.yacc"
    {
		print_if_start();
	}
    break;

  case 699:
#line 3509 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 701:
#line 3514 "fgl.yacc"
    {
		print_if_else();
	}
    break;

  case 703:
#line 3517 "fgl.yacc"
    {
		print_if_else();
		}
    break;

  case 704:
#line 3519 "fgl.yacc"
    {

		print_if_start();
	}
    break;

  case 705:
#line 3522 "fgl.yacc"
    {
		print_if_end();
	}
    break;

  case 706:
#line 3526 "fgl.yacc"
    {
		print_import(yyvsp[-3].str,atoi(yyvsp[-1].str));
	}
    break;

  case 707:
#line 3529 "fgl.yacc"
    {
		print_import_legacy(yyvsp[0].str);
	}
    break;

  case 708:
#line 3535 "fgl.yacc"
    { add_ex_dtype(yyvsp[0].str); }
    break;

  case 709:
#line 3546 "fgl.yacc"
    {debug("init to\n");}
    break;

  case 710:
#line 3547 "fgl.yacc"
    {
	print_init();
 }
    break;

  case 711:
#line 3550 "fgl.yacc"
    {
	print_init_table(yyvsp[0].str);
}
    break;

  case 713:
#line 3556 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 714:
#line 3560 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 715:
#line 3561 "fgl.yacc"
    {setrecord(yyval.str,yyvsp[-2].str,0);}
    break;

  case 718:
#line 3575 "fgl.yacc"
    {
sprintf(yyval.str,"0");
}
    break;

  case 719:
#line 3577 "fgl.yacc"
    {
sprintf(yyval.str,"1");
}
    break;

  case 722:
#line 3586 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 723:
#line 3588 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 724:
#line 3592 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 725:
#line 3594 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 726:
#line 3597 "fgl.yacc"
    {
		print_befaft_field_1("AFT_ROW");
}
    break;

  case 727:
#line 3599 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 728:
#line 3602 "fgl.yacc"
    {
		lex_printcomment("/* before row */ \n");
		print_befaft_field_1("BEF_ROW");
}
    break;

  case 729:
#line 3605 "fgl.yacc"
    {
	print_befaft_field_2();
		}
    break;

  case 730:
#line 3608 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 731:
#line 3610 "fgl.yacc"
    {
	print_onkey_2();
}
    break;

  case 732:
#line 3613 "fgl.yacc"
    {
		print_befaft_field_1("AFTER_INP");
}
    break;

  case 733:
#line 3615 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 734:
#line 3618 "fgl.yacc"
    {
		print_befaft_field_1("BEFORE_INP");
}
    break;

  case 735:
#line 3620 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 736:
#line 3623 "fgl.yacc"
    {lex_printcomment("/* before insert/delete */ \n");
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 737:
#line 3625 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 738:
#line 3628 "fgl.yacc"
    {
		print_befaft_field_1(yyvsp[0].str);
}
    break;

  case 739:
#line 3630 "fgl.yacc"
    {
	print_befaft_field_2();
}
    break;

  case 740:
#line 3636 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 741:
#line 3637 "fgl.yacc"
    {
	char buff[256];
	sprintf(buff,"(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 742:
#line 3645 "fgl.yacc"
    {strcpy(yyval.str,"AFT_INSERT");}
    break;

  case 743:
#line 3646 "fgl.yacc"
    {strcpy(yyval.str,"AFT_DELETE");}
    break;

  case 744:
#line 3651 "fgl.yacc"
    {sprintf(yyval.str,"(%s)",yyvsp[0].str);}
    break;

  case 745:
#line 3652 "fgl.yacc"
    {
	char buff[80];
		sprintf(buff,"(%s)",yyvsp[0].str);
		generate_or(yyval.str,yyvsp[-2].str,yyvsp[0].str);
 }
    break;

  case 746:
#line 3661 "fgl.yacc"
    {strcpy(yyval.str,"BEF_INSERT");}
    break;

  case 747:
#line 3662 "fgl.yacc"
    {strcpy(yyval.str,"BEF_DELETE");}
    break;

  case 748:
#line 3669 "fgl.yacc"
    {sprintf(yyval.str,"BEF_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 749:
#line 3670 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"BEF_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 750:
#line 3678 "fgl.yacc"
    {sprintf(yyval.str,"AFT_FIELD_CHK(%s)",yyvsp[0].str);}
    break;

  case 751:
#line 3679 "fgl.yacc"
    {
	char buff[80];
	sprintf(buff,"AFT_FIELD_CHK(%s)",yyvsp[0].str);
	generate_or(yyval.str,yyvsp[-2].str,buff);
	}
    break;

  case 752:
#line 3688 "fgl.yacc"
    {
print_next_field(yyvsp[0].str);
}
    break;

  case 753:
#line 3693 "fgl.yacc"
    {
print_next_form_field(yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 754:
#line 3698 "fgl.yacc"
    {sprintf(yyval.str,"\"+\",0");}
    break;

  case 755:
#line 3699 "fgl.yacc"
    {sprintf(yyval.str,"\"-\",0");}
    break;

  case 757:
#line 3704 "fgl.yacc"
    {
print_input_1();
}
    break;

  case 758:
#line 3707 "fgl.yacc"
    {
print_input_2(yyvsp[-2].str);
}
    break;

  case 759:
#line 3715 "fgl.yacc"
    {
print_input(1,yyvsp[-2].str,yyvsp[-1].str,0);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 760:
#line 3720 "fgl.yacc"
    {
print_input(0,yyvsp[-4].str,yyvsp[-1].str,yyvsp[-2].str);
strcpy(yyval.str,get_formloop_str(0));
}
    break;

  case 761:
#line 3724 "fgl.yacc"
    {
inp_flags=0;}
    break;

  case 762:
#line 3726 "fgl.yacc"
    {
strcpy(yyval.str,print_input_array(yyvsp[-8].str,yyvsp[-2].str,yyvsp[-7].str,yyvsp[-5].str,yyvsp[0].str));
}
    break;

  case 763:
#line 3735 "fgl.yacc"
    {
		print_scroll(yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 764:
#line 3740 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 765:
#line 3741 "fgl.yacc"
    {strcpy(yyval.str,"-1");}
    break;

  case 766:
#line 3742 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 767:
#line 3743 "fgl.yacc"
    {sprintf(yyval.str,"-%s",yyvsp[0].str);}
    break;

  case 768:
#line 3746 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 770:
#line 3752 "fgl.yacc"
    {iskey=1;}
    break;

  case 771:
#line 3752 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 772:
#line 3754 "fgl.yacc"
    {strcpy(yyval.str,"->ANY");}
    break;

  case 773:
#line 3757 "fgl.yacc"
    {iskey=1;}
    break;

  case 774:
#line 3757 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);iskey=0;}
    break;

  case 775:
#line 3759 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;}
    break;

  case 776:
#line 3763 "fgl.yacc"
    {start_state("keymode",1);iskey=1;}
    break;

  case 777:
#line 3763 "fgl.yacc"
    {sprintf(yyval.str,"key_val(\"%s\")",yyvsp[0].str);iskey=0;start_state("keymode",0);}
    break;

  case 778:
#line 3766 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 779:
#line 3767 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[-1].str);}
    break;

  case 781:
#line 3770 "fgl.yacc"
    {
	sprintf(yyval.str,"%s||%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 782:
#line 3775 "fgl.yacc"
    {start_state("keymode",1);}
    break;

  case 783:
#line 3775 "fgl.yacc"
    {start_state("keymode",0);strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 788:
#line 3782 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 789:
#line 3783 "fgl.yacc"
    {strcpy(yyval.str,"escape");}
    break;

  case 790:
#line 3784 "fgl.yacc"
    {strcpy(yyval.str,"up");}
    break;

  case 791:
#line 3785 "fgl.yacc"
    {strcpy(yyval.str,"help");}
    break;

  case 792:
#line 3786 "fgl.yacc"
    {strcpy(yyval.str,"down");}
    break;

  case 793:
#line 3787 "fgl.yacc"
    {strcpy(yyval.str,"return");}
    break;

  case 794:
#line 3788 "fgl.yacc"
    {strcpy(yyval.str,"delete");}
    break;

  case 795:
#line 3789 "fgl.yacc"
    {strcpy(yyval.str,"tab");}
    break;

  case 796:
#line 3790 "fgl.yacc"
    {strcpy(yyval.str,"left");}
    break;

  case 797:
#line 3791 "fgl.yacc"
    {strcpy(yyval.str,"right");}
    break;

  case 798:
#line 3792 "fgl.yacc"
    {strcpy(yyval.str,"nextpage");}
    break;

  case 799:
#line 3793 "fgl.yacc"
    {strcpy(yyval.str,"prevpage");}
    break;

  case 800:
#line 3794 "fgl.yacc"
    { rm_quotes(yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 801:
#line 3798 "fgl.yacc"
    {
char buff[256];
debug("Label : %s\n",get_idents(0));
strcpy(buff,get_idents(0));
convlower(buff);
print_label(buff);
}
    break;

  case 802:
#line 3816 "fgl.yacc"
    {chk4var=1;}
    break;

  case 803:
#line 3816 "fgl.yacc"
    {chk4var=0;
expand_obind();
lex_printcomment("/*let3*/\n");}
    break;

  case 804:
#line 3819 "fgl.yacc"
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

  case 805:
#line 3842 "fgl.yacc"
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

  case 807:
#line 3860 "fgl.yacc"
    {
		if (!print_linked_cmd('S',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 808:
#line 3866 "fgl.yacc"
    {
		 if (!print_linked_cmd('D',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
	}
    break;

  case 809:
#line 3872 "fgl.yacc"
    {
		 if (!print_linked_cmd('U',yyvsp[0].str)) a4gl_yyerror("Not a linked variable");
}
    break;

  case 810:
#line 3878 "fgl.yacc"
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

  case 811:
#line 3889 "fgl.yacc"
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

  case 812:
#line 3912 "fgl.yacc"
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

  case 815:
#line 3928 "fgl.yacc"
    {
	}
    break;

  case 822:
#line 3951 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 826:
#line 3959 "fgl.yacc"
    {
		print_at_termination(yyvsp[0].str);
	}
    break;

  case 844:
#line 3985 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 845:
#line 3986 "fgl.yacc"
    {
strcpy(yyval.str,"static ");
}
    break;

  case 846:
#line 3994 "fgl.yacc"
    {
  clr_variable(); lastlineno=yylineno;
  clr_function_constants (); 
}
    break;

  case 847:
#line 3999 "fgl.yacc"
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

  case 848:
#line 4015 "fgl.yacc"
    {
  lex_printcomment("/* new function %s parameters*/\n",yyvsp[-1].str);
  push_blockcommand("FUNC");
  lex_printcomment("/* define section */\n");
}
    break;

  case 849:
#line 4021 "fgl.yacc"
    {
  int c;
  lex_printcomment("/*end of define section */\n");
	print_variables();
  c=print_param('f');
  printPushFunction();
  print_func_args(c);
}
    break;

  case 851:
#line 4036 "fgl.yacc"
    {
    printPopFunction();
    print_func_defret0();
    pop_blockcommand("FUNC");
    print_func_end();
    clr_function_constants ();
    lex_printcomment("/*end function*/\n");
  }
    break;

  case 852:
#line 4049 "fgl.yacc"
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

  case 853:
#line 4059 "fgl.yacc"
    {
	print_variables();
    printDeclareFunctionStack("MAIN");
    print_fgllib_start(hdr_dbname);
    printInitFunctionStack();
    printPushFunction();
  }
    break;

  case 854:
#line 4066 "fgl.yacc"
    {
pop_blockcommand("MAIN");
print_main_end();
lex_printcomment("/*end main */\n");}
    break;

  case 855:
#line 4073 "fgl.yacc"
    {
    printPopFunction();
    print_return(atoi(yyvsp[0].str));
  }
    break;

  case 856:
#line 4079 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 857:
#line 4079 "fgl.yacc"
    {
lex_printcomment("/* Got expr list */");
sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 858:
#line 4084 "fgl.yacc"
    {open_db(yyvsp[0].str);
			strcpy(hdr_dbname,yyvsp[0].str);
			lastlineno=yylineno;}
    break;

  case 859:
#line 4089 "fgl.yacc"
    {
}
    break;

  case 865:
#line 4101 "fgl.yacc"
    {
strcpy(curr_func,"[Globals]");
set_current_variable_scope('g');
lex_printcomment("/* start of globals */\n");
}
    break;

  case 867:
#line 4109 "fgl.yacc"
    {
	lex_printcomment("/* end of globals */");
	debug("end of globals\n");
	lastlineno=yylineno;
	set_current_variable_scope('m');
}
    break;

  case 868:
#line 4115 "fgl.yacc"
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

  case 869:
#line 4129 "fgl.yacc"
    {
  addmap("Define Member Function",curr_func,"MODULE",yylineno,infilename);
}
    break;

  case 870:
#line 4133 "fgl.yacc"
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

  case 871:
#line 4146 "fgl.yacc"
    {
	print_variables();
  lex_printcomment("/*end of define section */\n");
  print_param('f');
  printPushFunction();
  print_func_args(atoi(yyvsp[-3].str));
}
    break;

  case 873:
#line 4164 "fgl.yacc"
    {
	start_state("menu",1);
   	menu_cnt=npush_menu();
   	menu_cmd_cnt[menu_cnt]=1;
   	push_blockcommand("MENU");
	print_menu_1();
	}
    break;

  case 874:
#line 4171 "fgl.yacc"
    {
	start_state("menu",0);
	}
    break;

  case 875:
#line 4177 "fgl.yacc"
    {
   print_end_menu_1();
   add_continue_blockcommand ("MENU");
print_end_menu_2();
   pop_blockcommand("MENU");
   pop_menu();
}
    break;

  case 876:
#line 4188 "fgl.yacc"
    {
	 lex_printcomment("/* Block%d_m2 (Before menu) */",menu_cnt);
		print_menu_block(-2) ;
                  }
    break;

  case 877:
#line 4192 "fgl.yacc"
    {
		print_menu_block_end();
	}
    break;

  case 878:
#line 4199 "fgl.yacc"
    {
debug("Menu=%d menu cnt=%d",menu_cnt,menu_cmd_cnt[menu_cnt]);
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
		lex_printcomment("/* Block%d_%d */",menu_cnt,menu_cmd_cnt[menu_cnt]-1);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 879:
#line 4206 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 880:
#line 4212 "fgl.yacc"
    {
		push_command(menu_cnt,menu_cmd_cnt[menu_cnt],yyvsp[-1].str,"\"\"","\"\"",0);
		print_menu_block(menu_cmd_cnt[menu_cnt]-1);
		menu_cmd_cnt[menu_cnt]++;
		}
    break;

  case 881:
#line 4217 "fgl.yacc"
    {
		print_menu_block_end();
}
    break;

  case 884:
#line 4224 "fgl.yacc"
    {strcpy(yyval.str,"\"EMPTY\"");}
    break;

  case 885:
#line 4225 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 886:
#line 4227 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 887:
#line 4228 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 888:
#line 4231 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 889:
#line 4232 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 890:
#line 4233 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 891:
#line 4235 "fgl.yacc"
    {
	print_option_op('N',yyvsp[0].str);
}
    break;

  case 892:
#line 4240 "fgl.yacc"
    {
	print_option_op('S',yyvsp[0].str);
}
    break;

  case 893:
#line 4245 "fgl.yacc"
    {
	print_option_op('H',yyvsp[0].str);
}
    break;

  case 894:
#line 4252 "fgl.yacc"
    {sprintf(yyval.str,"MENU_ALL");}
    break;

  case 898:
#line 4259 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 899:
#line 4261 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);  
push_menu_title(yyval.str);}
    break;

  case 900:
#line 4263 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); 
push_menu_title(yyval.str);}
    break;

  case 901:
#line 4272 "fgl.yacc"
    {
                strcpy(menuhandler,yyvsp[0].str);
	sprintf(curr_func,"%s",yyvsp[0].str); 
	print_gtk_menuhandler_1(yyvsp[0].str);
                push_blockcommand("MENUH");
}
    break;

  case 902:
#line 4278 "fgl.yacc"
    {
		print_variables();
        }
    break;

  case 903:
#line 4282 "fgl.yacc"
    {
                        pop_blockcommand("MENUH");
			print_gtk_menuhandler_end();
                }
    break;

  case 906:
#line 4294 "fgl.yacc"
    {

		print_gtk_menuhandler_bsm();

                push_blockcommand("BSM");
        }
    break;

  case 907:
#line 4299 "fgl.yacc"
    {
                pop_blockcommand("BSM");
		print_gtk_menuhandler_bsm_end();

        }
    break;

  case 908:
#line 4304 "fgl.yacc"
    {
print_gtk_menuhandler_on(yyvsp[0].str);
                push_blockcommand("ON");
        }
    break;

  case 909:
#line 4307 "fgl.yacc"
    {
                pop_blockcommand("ON");
		print_gtk_menuhandler_on_end();
}
    break;

  case 910:
#line 4316 "fgl.yacc"
    {start_state("message",0);}
    break;

  case 911:
#line 4319 "fgl.yacc"
    {
		print_message(0,"0",0);
		start_state("message",0);
	   }
    break;

  case 912:
#line 4323 "fgl.yacc"
    { 
		print_message(0,yyvsp[-1].str,atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 913:
#line 4327 "fgl.yacc"
    { 
		print_message(0,"0",atoi(yyvsp[0].str));
		start_state("message",0);
	  }
    break;

  case 920:
#line 4344 "fgl.yacc"
    {start_state("message",1);}
    break;

  case 922:
#line 4346 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 923:
#line 4346 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 924:
#line 4349 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 925:
#line 4359 "fgl.yacc"
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

  case 927:
#line 4406 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 929:
#line 4413 "fgl.yacc"
    { 
         sprintf (yyval.str, "%s.%s", yyvsp[-1].str, yyvsp[0].str); 
         lex_printcomment("/* record building -> %s */\n",yyval.str);
         }
    break;

  case 930:
#line 4418 "fgl.yacc"
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

  case 934:
#line 4465 "fgl.yacc"
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

  case 935:
#line 4479 "fgl.yacc"
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

  case 940:
#line 4503 "fgl.yacc"
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

  case 941:
#line 4557 "fgl.yacc"
    {
		debug("---> Subscript or substring");
		strcpy(yyval.str,yyvsp[-1].str);
	}
    break;

  case 942:
#line 4562 "fgl.yacc"
    {
		debug("---> Subscript & substring");
		sprintf(yyval.str,"%s:%s",yyvsp[-4].str,yyvsp[-1].str);
	}
    break;

  case 943:
#line 4570 "fgl.yacc"
    {
debug("List element");
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 944:
#line 4575 "fgl.yacc"
    {
debug("List element continues");
  sprintf (yyval.str, "%s,%s", yyvsp[-2].str, yyvsp[0].str);
}
    break;

  case 945:
#line 4583 "fgl.yacc"
    {
  sprintf (yyval.str, "%s", yyvsp[0].str);
}
    break;

  case 946:
#line 4589 "fgl.yacc"
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

  case 947:
#line 4617 "fgl.yacc"
    {
		debug("Array..");
}
    break;

  case 948:
#line 4620 "fgl.yacc"
    { sprintf (yyval.str, "%s.%s", yyvsp[-2].str, yyvsp[0].str); }
    break;

  case 949:
#line 4622 "fgl.yacc"
    {
  int a;
  int b;
  char buff[256];
  char buff2[256];
  lex_printcomment("/*array variable .let. */");
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

  debug("?1arrvar=%s",yyval.str);
  b = isarrvariable (yyval.str);
  a = scan_variable (yyval.str);

  lex_printcomment("/*a=%x b=%x */\n",a,b);

  if (b != 0)
    {
      sprintf (yyval.str, "%s.%s[%s-1] ", yyvsp[-5].str, yyvsp[-3].str,yyvsp[-1].str);
      lex_printcomment ("/* array variable %s*/\n", yyval.str);
    }
  else
    {
      sprintf(buff,"%s.%s",yyvsp[-5].str,yyvsp[-3].str);
      sprintf (yyval.str, " let_substr(%s,%d,%s,0)", buff, a, yyvsp[-1].str);
      addmap("Let Variable",buff,curr_func,yylineno,infilename);
      lex_printcomment ("/*character variable %s*/\n", yyval.str);
    }

  mcnt++;

}
    break;

  case 954:
#line 4673 "fgl.yacc"
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

  case 955:
#line 4725 "fgl.yacc"
    {
start_bind('f',0);
start_bind('O',0);
strcpy(yyval.str,"0");}
    break;

  case 957:
#line 4732 "fgl.yacc"
    {
start_bind('f',yyvsp[0].str);
start_bind('O',yyvsp[0].str);
sprintf(yyval.str,"1");
}
    break;

  case 958:
#line 4738 "fgl.yacc"
    {
int c;
c=add_bind('f',yyvsp[0].str);
c=add_bind('O',yyvsp[0].str);
sprintf(yyval.str,"%d",c); 
}
    break;

  case 959:
#line 4749 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('i',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 960:
#line 4756 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('i',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 962:
#line 4764 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[-1].str);}
    break;

  case 963:
#line 4767 "fgl.yacc"
    {lex_printcomment("/* Variable */\n");}
    break;

  case 964:
#line 4768 "fgl.yacc"
    { debug("Got an ibind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 966:
#line 4770 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 967:
#line 4771 "fgl.yacc"
    {sprintf(yyval.str,"\"%s\"",yyvsp[0].str);}
    break;

  case 968:
#line 4774 "fgl.yacc"
    {
start_bind('o',yyvsp[0].str);
}
    break;

  case 969:
#line 4777 "fgl.yacc"
    {
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 970:
#line 4783 "fgl.yacc"
    {
	addmap("OBIND",yyvsp[0].str,curr_func,yylineno,infilename);
	}
    break;

  case 971:
#line 4786 "fgl.yacc"
    { debug("Got an obind thru..."); sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str); }
    break;

  case 972:
#line 4790 "fgl.yacc"
    {
lex_printcomment("/* start obind with  %s*/\n",yyvsp[0].str);
start_bind('o',yyvsp[0].str);
}
    break;

  case 973:
#line 4794 "fgl.yacc"
    {
lex_printcomment("/* add to obind %s */\n",yyvsp[0].str);
add_bind('o',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 974:
#line 4801 "fgl.yacc"
    {
lex_printcomment("/* Read variable %s*/\n",yyvsp[0].str);
}
    break;

  case 975:
#line 4806 "fgl.yacc"
    {
    lex_printcomment("/* use_arr_var */\n");
    start_arr_bind('o',yyvsp[0].str);
    lex_printcomment("/* use_arr_var complete */\n");
}
    break;

  case 976:
#line 4813 "fgl.yacc"
    {
start_bind('O',yyvsp[0].str);
}
    break;

  case 977:
#line 4816 "fgl.yacc"
    {
               add_bind('O',yyvsp[0].str);
               strcpy(yyval.str,"");
}
    break;

  case 982:
#line 4829 "fgl.yacc"
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

  case 983:
#line 4842 "fgl.yacc"
    {
lex_printcomment("/*STarted bind %s*/\n",yyvsp[0].str);
start_bind('N',yyvsp[0].str);
lex_printcomment("/*STarted bind 2*/\n");
strcpy(yyval.str,"");
}
    break;

  case 984:
#line 4849 "fgl.yacc"
    {
lex_printcomment("/* Added */\n");
add_bind('N',yyvsp[0].str);
strcpy(yyval.str,"");
}
    break;

  case 985:
#line 4856 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 986:
#line 4859 "fgl.yacc"
    {
			sprintf(yyval.str,"%s\n%s",yyvsp[-2].str,yyvsp[0].str);
		}
    break;

  case 987:
#line 4873 "fgl.yacc"
    {
form_attrib.iswindow=1;
print_open_window(yyvsp[-5].str,yyvsp[-1].str);
sprintf(yyval.str,"open window");
}
    break;

  case 992:
#line 4890 "fgl.yacc"
    {
	print_niy("OPEN_STATUSBOX");
}
    break;

  case 993:
#line 4895 "fgl.yacc"
    {
addmap("Call Formhandler",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 994:
#line 4901 "fgl.yacc"
    {
		print_open_form(yyvsp[0].str,yyvsp[-1].str,yyvsp[-1].str);
		}
    break;

  case 996:
#line 4908 "fgl.yacc"
    { form_attrib.iswindow=0;strcpy(yyval.str,"open_form(%s);"); }
    break;

  case 997:
#line 4913 "fgl.yacc"
    {sprintf(yyval.str,"open_gui_form(%%s,%s,%s,%s,hnd_e_%s,hnd_c_%s);",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str,yyvsp[0].str);}
    break;

  case 998:
#line 4916 "fgl.yacc"
    {strcpy(yyval.str,"0,0");}
    break;

  case 999:
#line 4917 "fgl.yacc"
    {sprintf(yyval.str,"%s,2",yyvsp[-5].str);}
    break;

  case 1000:
#line 4920 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1001:
#line 4921 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1002:
#line 4924 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1003:
#line 4925 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1004:
#line 4930 "fgl.yacc"
    {
print_open_session(yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);

}
    break;

  case 1005:
#line 4937 "fgl.yacc"
    {
	print_open_cursor(yyvsp[0].str,"0");
}
    break;

  case 1006:
#line 4940 "fgl.yacc"
    {
	print_open_cursor(yyvsp[-3].str,yyvsp[0].str); /* CHANGED from $<str>4 */
}
    break;

  case 1007:
#line 4946 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1008:
#line 4948 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1009:
#line 4950 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-3].str,yyvsp[0].str);}
    break;

  case 1010:
#line 4952 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1011:
#line 4955 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1012:
#line 4955 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1013:
#line 4956 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1014:
#line 4961 "fgl.yacc"
    {
	print_open_session(yyvsp[-1].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1015:
#line 4969 "fgl.yacc"
    {strcpy(yyval.str,"\"default_conn\"");}
    break;

  case 1016:
#line 4970 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1017:
#line 4975 "fgl.yacc"
    {sprintf(yyval.str,"0,0");}
    break;

  case 1018:
#line 4977 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1019:
#line 4979 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1023:
#line 4996 "fgl.yacc"
    {
print_options('C',yyvsp[0].str);
}
    break;

  case 1024:
#line 4999 "fgl.yacc"
    {
print_options('E',yyvsp[0].str);
}
    break;

  case 1025:
#line 5002 "fgl.yacc"
    {
print_options('F',yyvsp[0].str);
}
    break;

  case 1026:
#line 5005 "fgl.yacc"
    {
lex_printc("set_option_value('M',%s);\n",yyvsp[0].str);
}
    break;

  case 1027:
#line 5008 "fgl.yacc"
    {
print_options('m',yyvsp[0].str);
}
    break;

  case 1028:
#line 5011 "fgl.yacc"
    {
print_options('P',yyvsp[0].str);
}
    break;

  case 1029:
#line 5014 "fgl.yacc"
    {
print_options('A',yyvsp[0].str);
iskey=0;
}
    break;

  case 1030:
#line 5018 "fgl.yacc"
    {
print_options('D',yyvsp[0].str);
iskey=0;
}
    break;

  case 1031:
#line 5022 "fgl.yacc"
    {
print_options('I',yyvsp[0].str);
iskey=0;
}
    break;

  case 1032:
#line 5026 "fgl.yacc"
    {
print_options('N',yyvsp[0].str);
}
    break;

  case 1033:
#line 5029 "fgl.yacc"
    {
print_options('p',yyvsp[0].str);
iskey=0;
}
    break;

  case 1034:
#line 5033 "fgl.yacc"
    {
print_options('H',yyvsp[0].str);
}
    break;

  case 1035:
#line 5036 "fgl.yacc"
    { print_set_helpfile(yyvsp[0].str); }
    break;

  case 1036:
#line 5037 "fgl.yacc"
    { print_set_langfile(yyvsp[0].str); }
    break;

  case 1037:
#line 5038 "fgl.yacc"
    {
print_options('d',yyvsp[0].str);
}
    break;

  case 1038:
#line 5041 "fgl.yacc"
    {
print_options('i',yyvsp[0].str);
}
    break;

  case 1039:
#line 5044 "fgl.yacc"
    {
print_options('W',"1");
}
    break;

  case 1040:
#line 5047 "fgl.yacc"
    {
print_options('W',"0");
}
    break;

  case 1041:
#line 5050 "fgl.yacc"
    {
print_options('f',"1");
}
    break;

  case 1042:
#line 5053 "fgl.yacc"
    {
print_options('f',"0");
}
    break;

  case 1043:
#line 5056 "fgl.yacc"
    {
print_options('S',"1");
}
    break;

  case 1044:
#line 5059 "fgl.yacc"
    {
print_options('S',"0");
}
    break;

  case 1045:
#line 5076 "fgl.yacc"
    {
	print_prepare(yyvsp[-2].str,yyvsp[0].str);
	addmap("Prepare",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_undo_use(yyvsp[-4].str);
}
    break;

  case 1048:
#line 5086 "fgl.yacc"
    {

print_execute(yyvsp[0].str,0);

addmap("Execute",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1049:
#line 5093 "fgl.yacc"
    {
	addmap("Execute",yyvsp[-2].str,curr_func,yylineno,infilename);
	print_execute(yyvsp[-2].str,1);
}
    break;

  case 1051:
#line 5114 "fgl.yacc"
    {
                push_blockcommand("PROMPT");

	print_prompt_1(yyvsp[-5].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str) ;
}
    break;

  case 1052:
#line 5119 "fgl.yacc"
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

  case 1053:
#line 5132 "fgl.yacc"
    {
		print_niy("GUI PROMPT");
	}
    break;

  case 1054:
#line 5137 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1055:
#line 5138 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1056:
#line 5142 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1060:
#line 5148 "fgl.yacc"
    {
	print_onkey_1(yyvsp[0].str);
}
    break;

  case 1061:
#line 5150 "fgl.yacc"
    {
	print_onkey_2_prompt();
}
    break;

  case 1063:
#line 5165 "fgl.yacc"
    {
		start_bind('i',0);
		}
    break;

  case 1064:
#line 5169 "fgl.yacc"
    {
		print_put(yyvsp[-2].str);
	}
    break;

  case 1065:
#line 5175 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1066:
#line 5176 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1067:
#line 5179 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str);}
    break;

  case 1068:
#line 5180 "fgl.yacc"
    {push_gen(PUTVAL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1069:
#line 5183 "fgl.yacc"
    {
	char buff[256];	
	strcpy(buff,yyvsp[0].sql_string);
	strcpy(yyval.str,buff);
}
    break;

  case 1071:
#line 5202 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-1].str,curr_func,yylineno,infilename);
print_start_report("P","\"lp\"",yyvsp[-1].str);
}
    break;

  case 1072:
#line 5207 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("F",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1073:
#line 5212 "fgl.yacc"
    {
addmap("Start Report",yyvsp[-2].str,curr_func,yylineno,infilename);
print_start_report("P",yyvsp[0].str,yyvsp[-2].str);
}
    break;

  case 1074:
#line 5217 "fgl.yacc"
    {
addmap("Start Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_start_report("","\"\"",yyvsp[0].str);
}
    break;

  case 1080:
#line 5239 "fgl.yacc"
    {
addmap("Output to report",yyvsp[-5].str,curr_func,yylineno,infilename);
print_output_to_report(yyvsp[-5].str,yyvsp[-1].str); 
}
    break;

  case 1081:
#line 5246 "fgl.yacc"
    {
addmap("Finish Report",yyvsp[0].str,curr_func,yylineno,infilename);
print_finish_report(yyvsp[0].str);
}
    break;

  case 1082:
#line 5252 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1083:
#line 5254 "fgl.yacc"
    {
	print_format_every_row();
}
    break;

  case 1087:
#line 5265 "fgl.yacc"
    { push_report_block("FIRST",'P');}
    break;

  case 1088:
#line 5266 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1089:
#line 5268 "fgl.yacc"
    { push_report_block("TRAILER",'T');}
    break;

  case 1090:
#line 5269 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1091:
#line 5271 "fgl.yacc"
    { push_report_block("HEADER",'p');}
    break;

  case 1092:
#line 5272 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1093:
#line 5274 "fgl.yacc"
    { push_report_block("EVERY",'E');}
    break;

  case 1094:
#line 5275 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1095:
#line 5277 "fgl.yacc"
    { push_report_block("LAST",'L');}
    break;

  case 1096:
#line 5278 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1097:
#line 5279 "fgl.yacc"
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

  case 1098:
#line 5293 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1099:
#line 5295 "fgl.yacc"
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

  case 1100:
#line 5312 "fgl.yacc"
    {print_rep_ret(0);}
    break;

  case 1107:
#line 5324 "fgl.yacc"
    {start_state("skip",1);}
    break;

  case 1108:
#line 5324 "fgl.yacc"
    {
	print_need_lines();
	start_state("skip",0);
}
    break;

  case 1109:
#line 5330 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1110:
#line 5330 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1111:
#line 5333 "fgl.yacc"
    {start_state("KWLINE",1);}
    break;

  case 1112:
#line 5333 "fgl.yacc"
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

  case 1113:
#line 5343 "fgl.yacc"
    { print_skip_top(); }
    break;

  case 1114:
#line 5344 "fgl.yacc"
    { print_niy("FONT SIZE"); }
    break;

  case 1115:
#line 5345 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP BY is only in PDF reports");
				YYERROR;
			}
			print_skip_by(yyvsp[0].str);
		}
    break;

  case 1116:
#line 5352 "fgl.yacc"
    {
			if (rep_type!=REP_TYPE_PDF) {
				a4gl_yyerror("SKIP TO is only in PDF reports");
				YYERROR;
			}
			print_skip_to(yyvsp[0].str);
		}
    break;

  case 1117:
#line 5364 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1123:
#line 5375 "fgl.yacc"
    {
	print_niy("PRINT AT...");
}
    break;

  case 1124:
#line 5380 "fgl.yacc"
    {
	print_report_print(0,yyvsp[0].str,0);
}
    break;

  case 1125:
#line 5384 "fgl.yacc"
    { 
	print_report_print_file(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1126:
#line 5389 "fgl.yacc"
    { 
	print_report_print_img(yyvsp[-1].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1127:
#line 5395 "fgl.yacc"
    { strcpy(yyval.str,get_default_scaling());}
    break;

  case 1128:
#line 5396 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); strcat(yyval.str,yyvsp[0].str); }
    break;

  case 1129:
#line 5397 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1130:
#line 5401 "fgl.yacc"
    {strcpy(yyval.str,"tiff");}
    break;

  case 1131:
#line 5402 "fgl.yacc"
    {strcpy(yyval.str,"gif");}
    break;

  case 1132:
#line 5403 "fgl.yacc"
    {strcpy(yyval.str,"png");}
    break;

  case 1133:
#line 5404 "fgl.yacc"
    {strcpy(yyval.str,"jpeg");}
    break;

  case 1134:
#line 5408 "fgl.yacc"
    {
	int vtype;
	vtype=scan_variable(yyvsp[0].str);
	if (vtype!=11&&vtype!=12) {
	a4gl_yyerror("Only Blobs may be printed...");
	YYERROR;
	}
}
    break;

  case 1135:
#line 5418 "fgl.yacc"
    {
strcpy(yyval.str,"0");
}
    break;

  case 1136:
#line 5420 "fgl.yacc"
    {
strcpy(yyval.str,"1");
}
    break;

  case 1137:
#line 5425 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str);
	}
    break;

  case 1138:
#line 5428 "fgl.yacc"
    {
	print_report_print(1,0,yyvsp[0].str); /* changed from $<str>1 */
}
    break;

  case 1139:
#line 5433 "fgl.yacc"
    {
	strcpy(yyval.str,yyvsp[0].str); 
	}
    break;

  case 1140:
#line 5440 "fgl.yacc"
    {
int a;
a=add_report_agg('S',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1141:
#line 5447 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1142:
#line 5454 "fgl.yacc"
    {
int a;
a=add_report_agg('C',0,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_int(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1143:
#line 5463 "fgl.yacc"
    {
int a;
a=add_report_agg('P',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double((double)_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1144:
#line 5470 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/(double)_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1145:
#line 5477 "fgl.yacc"
    {
int a;
a=add_report_agg('A',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d/_g%d);\n",racnt,racnt+1);
racnt+=a;
}
    break;

  case 1146:
#line 5484 "fgl.yacc"
    {
int a;
a=add_report_agg('N',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1147:
#line 5491 "fgl.yacc"
    {
int a;
a=add_report_agg('X',yyvsp[-2].ptr,yyvsp[0].ptr,racnt);
sprintf(yyval.str,"push_double(_g%d);\n",racnt);
racnt+=a;
}
    break;

  case 1152:
#line 5504 "fgl.yacc"
    {rep_struct.left_margin=atoi(yyvsp[0].str);}
    break;

  case 1153:
#line 5505 "fgl.yacc"
    {rep_struct.right_margin=atoi(yyvsp[0].str);}
    break;

  case 1154:
#line 5506 "fgl.yacc"
    {rep_struct.top_margin=atoi(yyvsp[0].str);}
    break;

  case 1155:
#line 5507 "fgl.yacc"
    {rep_struct.bottom_margin=atoi(yyvsp[0].str);}
    break;

  case 1156:
#line 5508 "fgl.yacc"
    {rep_struct.page_length=atoi(yyvsp[0].str);}
    break;

  case 1157:
#line 5509 "fgl.yacc"
    { rep_struct.output_mode='P';strcpy(rep_struct.output_loc,"\"lp\"");}
    break;

  case 1158:
#line 5510 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1159:
#line 5511 "fgl.yacc"
    {rep_struct.output_mode='F';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1160:
#line 5512 "fgl.yacc"
    {rep_struct.output_mode='P';strcpy(rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1161:
#line 5513 "fgl.yacc"
    {strcpy(rep_struct.top_of_page,yyvsp[0].str);}
    break;

  case 1164:
#line 5519 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str));}
    break;

  case 1165:
#line 5520 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*72.0); }
    break;

  case 1166:
#line 5521 "fgl.yacc"
    {sprintf(yyval.str,"-%f",atof(yyvsp[-1].str)*2.83465);}
    break;

  case 1167:
#line 5522 "fgl.yacc"
    {sprintf(yyval.str,"%f",atof(yyvsp[0].str));}
    break;

  case 1172:
#line 5531 "fgl.yacc"
    {pdf_rep_struct.left_margin=atof(yyvsp[0].str);debug("Left margin=%s\n",yyvsp[0].str);}
    break;

  case 1173:
#line 5532 "fgl.yacc"
    {pdf_rep_struct.right_margin=atof(yyvsp[0].str);}
    break;

  case 1174:
#line 5533 "fgl.yacc"
    {pdf_rep_struct.top_margin=atof(yyvsp[0].str);}
    break;

  case 1175:
#line 5534 "fgl.yacc"
    {pdf_rep_struct.bottom_margin=atof(yyvsp[0].str);}
    break;

  case 1176:
#line 5535 "fgl.yacc"
    {pdf_rep_struct.page_length=atof(yyvsp[0].str);}
    break;

  case 1177:
#line 5536 "fgl.yacc"
    {pdf_rep_struct.page_width=atof(yyvsp[0].str);}
    break;

  case 1178:
#line 5537 "fgl.yacc"
    {strcpy(pdf_rep_struct.font_name,yyvsp[0].str);}
    break;

  case 1179:
#line 5538 "fgl.yacc"
    {pdf_rep_struct.font_size=atof(yyvsp[0].str);}
    break;

  case 1180:
#line 5540 "fgl.yacc"
    {pdf_rep_struct.paper_size=1;}
    break;

  case 1181:
#line 5541 "fgl.yacc"
    {pdf_rep_struct.paper_size=2;}
    break;

  case 1182:
#line 5542 "fgl.yacc"
    {pdf_rep_struct.paper_size=3;}
    break;

  case 1183:
#line 5543 "fgl.yacc"
    {pdf_rep_struct.paper_size=5;}
    break;

  case 1184:
#line 5545 "fgl.yacc"
    {pdf_rep_struct.paper_size=-1;}
    break;

  case 1185:
#line 5546 "fgl.yacc"
    {pdf_rep_struct.paper_size=-2;}
    break;

  case 1186:
#line 5547 "fgl.yacc"
    {pdf_rep_struct.paper_size=-3;}
    break;

  case 1187:
#line 5548 "fgl.yacc"
    {pdf_rep_struct.paper_size=-5;}
    break;

  case 1191:
#line 5553 "fgl.yacc"
    {pdf_rep_struct.output_mode='F';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1192:
#line 5554 "fgl.yacc"
    {pdf_rep_struct.output_mode='P';strcpy(pdf_rep_struct.output_loc,yyvsp[0].str);}
    break;

  case 1196:
#line 5561 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
}
    break;

  case 1197:
#line 5568 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(1);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1198:
#line 5575 "fgl.yacc"
    {
int a;
a=print_bind('O');
print_order_by_type(2);
sprintf(yyval.str,"%d",a);
debug("Order by Gives :%d\n",a);
}
    break;

  case 1199:
#line 5586 "fgl.yacc"
    { 
		rep_type=REP_TYPE_NORMAL; 
		clr_function_constants (); 
		clr_variable(); 
		lastlineno=yylineno; 
		init_report_structure(&rep_struct); 
		}
    break;

  case 1200:
#line 5595 "fgl.yacc"
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

  case 1201:
#line 5606 "fgl.yacc"
    {
		lastlineno=yylineno;
		}
    break;

  case 1202:
#line 5610 "fgl.yacc"
    {
		print_variables();
		}
    break;

  case 1203:
#line 5614 "fgl.yacc"
    {
		print_report_2(0,yyvsp[0].str);
		rordcnt=atoi(yyvsp[0].str);
		debug("SET rordcnt=%d %s",rordcnt,yyvsp[0].str);
		}
    break;

  case 1204:
#line 5620 "fgl.yacc"
    {
		print_report_ctrl();
		}
    break;

  case 1205:
#line 5625 "fgl.yacc"
    {
		pop_blockcommand("REPORT");
		print_report_end() ;
		}
    break;

  case 1206:
#line 5633 "fgl.yacc"
    { strcpy(yyval.str,"");
	yyval.ptr=0;
}
    break;

  case 1207:
#line 5636 "fgl.yacc"
    {
	yyval.ptr=yyvsp[0].ptr;
//sprintf($<str>$,"%s", $<str>2);
}
    break;

  case 1208:
#line 5645 "fgl.yacc"
    {
if (!in_command("REPORT")) {
	a4gl_yyerror("PAUSE can only be used in reportes");
	YYERROR;
        }

print_pause(yyvsp[0].str) ;
}
    break;

  case 1209:
#line 5656 "fgl.yacc"
    {strcpy(yyval.str,"\"\"");}
    break;

  case 1211:
#line 5663 "fgl.yacc"
    {
rep_type=REP_TYPE_PDF;
clr_function_constants();
clr_variable(); 
lastlineno=yylineno; 
pdf_init_report_structure(&pdf_rep_struct);
}
    break;

  case 1212:
#line 5671 "fgl.yacc"
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

  case 1213:
#line 5681 "fgl.yacc"
    {
lastlineno=yylineno;
}
    break;

  case 1214:
#line 5684 "fgl.yacc"
    {
	print_variables();
}
    break;

  case 1215:
#line 5688 "fgl.yacc"
    {
//print_variables();
resize_paper(&pdf_rep_struct);
	print_report_2(1,yyvsp[0].str);
debug("SET rordcnt=%d (%s)",rordcnt,yyvsp[0].str);
	rordcnt=atoi(yyvsp[0].str);
}
    break;

  case 1216:
#line 5696 "fgl.yacc"
    {
print_report_ctrl();
}
    break;

  case 1217:
#line 5699 "fgl.yacc"
    {
	pop_blockcommand("REPORT");
	print_report_end();
}
    break;

  case 1218:
#line 5705 "fgl.yacc"
    { strcpy(yyval.str,yyvsp[0].str); }
    break;

  case 1219:
#line 5709 "fgl.yacc"
    {new_counter();
   		addmap("CALL",yyvsp[-1].str,curr_func,yylineno,infilename);
   		}
    break;

  case 1220:
#line 5713 "fgl.yacc"
    {
		sprintf(yyval.str,"%d",get_counter_val());drop_counter();
		}
    break;

  case 1221:
#line 5717 "fgl.yacc"
    {
		print_pdf_call(yyvsp[-5].str,yyvsp[-2].ptr,yyvsp[-1].str);
   		}
    break;

  case 1222:
#line 5721 "fgl.yacc"
    {
	print_returning();
   }
    break;

  case 1223:
#line 5727 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1224:
#line 5728 "fgl.yacc"
    { strcpy(yyval.str,"rep.right_margin"); }
    break;

  case 1225:
#line 5729 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1226:
#line 5730 "fgl.yacc"
    { sprintf(yyval.str,"%s",yyvsp[0].str); }
    break;

  case 1227:
#line 5735 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1228:
#line 5737 "fgl.yacc"
    {
print_system_run(1,yyvsp[0].str);
}
    break;

  case 1229:
#line 5740 "fgl.yacc"
    {
print_system_run(2,0);
}
    break;

  case 1230:
#line 5744 "fgl.yacc"
    {
print_system_run(0,0);
}
    break;

  case 1231:
#line 5747 "fgl.yacc"
    {
print_system_run(0,0);
/* FIXME */
}
    break;

  case 1232:
#line 5754 "fgl.yacc"
    {
	print_exec_sql(yyvsp[0].str);
}
    break;

  case 1233:
#line 5759 "fgl.yacc"
    {sprintf(yyval.str, "%s",yyvsp[0].str);}
    break;

  case 1234:
#line 5760 "fgl.yacc"
    {sprintf(yyval.str,  "%s",yyvsp[0].str);}
    break;

  case 1235:
#line 5761 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1236:
#line 5766 "fgl.yacc"
    { print_exec_sql(yyvsp[0].str); }
    break;

  case 1237:
#line 5767 "fgl.yacc"
    { print_exec_sql(yyvsp[0].sql_string); 
	free(yyvsp[0].sql_string);
}
    break;

  case 1238:
#line 5773 "fgl.yacc"
    {insql=1;}
    break;

  case 1239:
#line 5773 "fgl.yacc"
    {insql=0;}
    break;

  case 1240:
#line 5773 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-4].str," ",yyvsp[-3].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
		free(yyvsp[-1].sql_string);
	}
    break;

  case 1241:
#line 5778 "fgl.yacc"
    {insql=1;}
    break;

  case 1242:
#line 5778 "fgl.yacc"
    {insql=0;}
    break;

  case 1243:
#line 5778 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-7].str," ",yyvsp[-5].str," ",yyvsp[-4].str,yyvsp[-2].sql_string,yyvsp[-1].str, " ",yyvsp[0].str,0);
		free(yyvsp[-2].sql_string);

}
    break;

  case 1244:
#line 5789 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1245:
#line 5790 "fgl.yacc"
    {
		a4gl_yyerror("You cannot create a database from within Aubit4gl....");
	}
    break;

  case 1246:
#line 5796 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1247:
#line 5798 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1249:
#line 5805 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1250:
#line 5809 "fgl.yacc"
    {sprintf(yyval.str,"%s ASC",yyvsp[-1].str);}
    break;

  case 1251:
#line 5810 "fgl.yacc"
    {sprintf(yyval.str,"%s DESC",yyvsp[-1].str);}
    break;

  case 1253:
#line 5815 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1254:
#line 5818 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1255:
#line 5824 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1256:
#line 5827 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1257:
#line 5835 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1259:
#line 5842 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	print_exec_sql(yyval.sql_string); 
}
    break;

  case 1260:
#line 5849 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1261:
#line 5852 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1262:
#line 5861 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1263:
#line 5864 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1264:
#line 5867 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1265:
#line 5870 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1266:
#line 5873 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1267:
#line 5876 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1268:
#line 5879 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1269:
#line 5886 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD ",yyvsp[0].sql_string,0);
	}
    break;

  case 1270:
#line 5889 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("ADD (",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1271:
#line 5896 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1272:
#line 5899 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," BEFORE ",yyvsp[0].str,0);
	}
    break;

  case 1273:
#line 5905 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1274:
#line 5908 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1275:
#line 5915 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP %s",yyvsp[0].str);
	}
    break;

  case 1276:
#line 5918 "fgl.yacc"
    {
		sprintf(yyval.str,"DROP (%s)",yyvsp[-1].str);
	}
    break;

  case 1278:
#line 5926 "fgl.yacc"
    {
		sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
	}
    break;

  case 1280:
#line 5935 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY %s",yyvsp[0].sql_string);
	}
    break;

  case 1281:
#line 5938 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFY (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1282:
#line 5944 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1283:
#line 5947 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1284:
#line 5953 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1285:
#line 5960 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE PAGE");}
    break;

  case 1286:
#line 5961 "fgl.yacc"
    {strcpy(yyval.str,"LOCK MODE ROW");}
    break;

  case 1287:
#line 5965 "fgl.yacc"
    {
		sprintf(yyval.str,"MODIFT NEXT SIZE %d",atoi(yyvsp[0].str));
	}
    break;

  case 1288:
#line 5971 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT %s",yyvsp[0].sql_string);
	}
    break;

  case 1289:
#line 5974 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1291:
#line 5982 "fgl.yacc"
    {
		sprintf(yyval.str,"ADD CONSTRAINT (%s)",yyvsp[-1].sql_string);
	}
    break;

  case 1292:
#line 5989 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1293:
#line 5992 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1297:
#line 6010 "fgl.yacc"
    {sprintf(yyval.str,"%s %s /*FIXME */",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1303:
#line 6016 "fgl.yacc"
    { 
	print_set_conn(yyvsp[0].str);
}
    break;

  case 1304:
#line 6019 "fgl.yacc"
    {
	print_set_options("conn",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1305:
#line 6022 "fgl.yacc"
    {
	print_set_options("stmt",yyvsp[-4].str,yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1306:
#line 6028 "fgl.yacc"
    {strcpy(yyval.str,"\"default\"");}
    break;

  case 1308:
#line 6034 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1310:
#line 6045 "fgl.yacc"
    {
		print_sleep();
	}
    break;

  case 1311:
#line 6059 "fgl.yacc"
    {
		strcpy(current_upd_table,yyvsp[0].str);
	}
    break;

  case 1312:
#line 6061 "fgl.yacc"
    {
		strcpy(current_upd_table,"");
	}
    break;

  case 1313:
#line 6063 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-6].str," ",yyvsp[-5].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1314:
#line 6068 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=strdup("");
	}
    break;

  case 1315:
#line 6072 "fgl.yacc"
    { 
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		rm_quotes(yyvsp[0].str);
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
		yyval.sql_string=make_sql_string(yyval.str,0);
	}
    break;

  case 1316:
#line 6078 "fgl.yacc"
    {
		pop_all_gen(UPDCOL,"!"); pop_all_gen(UPDVAL,"!");
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1317:
#line 6086 "fgl.yacc"
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

  case 1318:
#line 6096 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
    }
    break;

  case 1319:
#line 6099 "fgl.yacc"
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

  case 1320:
#line 6109 "fgl.yacc"
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

  case 1321:
#line 6131 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1322:
#line 6134 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1324:
#line 6143 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,"=",yyvsp[0].sql_string,0);
	}
    break;

  case 1325:
#line 6148 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1326:
#line 6149 "fgl.yacc"
    {push_gen(UPDCOL,yyvsp[0].str); sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1327:
#line 6155 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1328:
#line 6158 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1329:
#line 6167 "fgl.yacc"
    {
		push_gen(UPDVAL,"NULL");
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1330:
#line 6171 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1331:
#line 6178 "fgl.yacc"
    {
		print_sql_commit(0);
		}
    break;

  case 1332:
#line 6187 "fgl.yacc"
    { insql=1;start_bind('i',0);}
    break;

  case 1333:
#line 6187 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-4].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
}
    break;

  case 1334:
#line 6192 "fgl.yacc"
    {insql=1;}
    break;

  case 1335:
#line 6192 "fgl.yacc"
    {
insql=0;
	//printf("Value = %s\n",$<sql_string>4);
yyval.sql_string=make_sql_string(yyvsp[-4].str," (",yyvsp[-1].sql_string,")",0);}
    break;

  case 1336:
#line 6197 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1337:
#line 6200 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1338:
#line 6202 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1340:
#line 6209 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1341:
#line 6213 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	//printf(" 1. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1342:
#line 6217 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",", yyvsp[0].sql_string,0);
	//printf(" 2. Value = %s\n",$<sql_string>$);
	}
    break;

  case 1343:
#line 6224 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1344:
#line 6227 "fgl.yacc"
    {
		yyval.sql_string=strdup("NULL");
	}
    break;

  case 1345:
#line 6234 "fgl.yacc"
    {
      print_fetch_1();
    }
    break;

  case 1346:
#line 6238 "fgl.yacc"
    {
      print_fetch_2();
    }
    break;

  case 1347:
#line 6242 "fgl.yacc"
    {
      print_fetch_3(yyvsp[-2].str,yyvsp[0].str);
    }
    break;

  case 1348:
#line 6251 "fgl.yacc"
    {sprintf(yyval.str,"%s, %s",yyvsp[0].str,yyvsp[-1].str);
addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1349:
#line 6255 "fgl.yacc"
    {sprintf(yyval.str,"%s, %d, 1",yyvsp[0].str,FETCH_RELATIVE);

addmap("Fetch Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
}
    break;

  case 1350:
#line 6261 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1351:
#line 6265 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1352:
#line 6271 "fgl.yacc"
    {
	int no;
	no=print_bind('o');
	sprintf(yyval.str,"%d,obind",no);
}
    break;

  case 1353:
#line 6278 "fgl.yacc"
    {
debug("no into\n");
strcpy(yyval.str,"0,0");
}
    break;

  case 1354:
#line 6282 "fgl.yacc"
    {
	debug("FETCH INTO  ...");
	/* start_bind('i',0,-1); */
    start_bind('o',0);
}
    break;

  case 1355:
#line 6287 "fgl.yacc"
    {
/*
int ni;
ni=print_bind('i');
sprintf($<str>$,"%d,ibind",ni);
*/
}
    break;

  case 1356:
#line 6297 "fgl.yacc"
    {
		sprintf(yyval.str,"%d,1",FETCH_ABSOLUTE);}
    break;

  case 1357:
#line 6300 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_ABSOLUTE);}
    break;

  case 1358:
#line 6302 "fgl.yacc"
    {sprintf(yyval.str,"%d,1",FETCH_RELATIVE);}
    break;

  case 1359:
#line 6304 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1360:
#line 6306 "fgl.yacc"
    {sprintf(yyval.str,"%d,-1",FETCH_RELATIVE);}
    break;

  case 1361:
#line 6308 "fgl.yacc"
    {sprintf(yyval.str,"%d,0",FETCH_RELATIVE);}
    break;

  case 1362:
#line 6310 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_RELATIVE);}
    break;

  case 1363:
#line 6312 "fgl.yacc"
    {sprintf(yyval.str,"%d,pop_int()",FETCH_ABSOLUTE);}
    break;

  case 1364:
#line 6318 "fgl.yacc"
    {
 
rm_quotes(yyvsp[0].str);
sprintf(yyval.str," %s %s %s %s ",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str
);}
    break;

  case 1365:
#line 6328 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
		}
    break;

  case 1366:
#line 6335 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1368:
#line 6341 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1372:
#line 6350 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1375:
#line 6355 "fgl.yacc"
    {
print_sql_commit(-1);
}
    break;

  case 1376:
#line 6360 "fgl.yacc"
    {
		print_sql_commit(1);
	}
    break;

  case 1377:
#line 6367 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1378:
#line 6368 "fgl.yacc"
    {
		strcpy(yyval.str,"EXCLUSIVE");
	}
    break;

  case 1379:
#line 6375 "fgl.yacc"
    {
if (strcmp(yyvsp[-1].str,"?")==0) {
	print_init_conn(0);
} else {
	print_init_conn(yyvsp[-1].str);
}
}
    break;

  case 1380:
#line 6387 "fgl.yacc"
    {insql=1;}
    break;

  case 1381:
#line 6387 "fgl.yacc"
    {
print_undo_use(yyvsp[-2].str);
insql=0;strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1382:
#line 6392 "fgl.yacc"
    {
			lex_printcomment("/*  schema */\n");
			print_exec_sql(yyvsp[0].sql_string);
			strcpy(yyval.str,"Schema");
	}
    break;

  case 1383:
#line 6397 "fgl.yacc"
    {
		lex_printcomment("/*  schema  2*/\n");
		print_exec_sql(yyvsp[0].sql_string);
		strcpy(yyval.str,"Schema Element");
	}
    break;

  case 1385:
#line 6403 "fgl.yacc"
    {
		print_exec_sql(yyvsp[0].str);
 	}
    break;

  case 1387:
#line 6407 "fgl.yacc"
    {
		lex_printcomment("/*  delete 1 */\n");
		print_exec_sql_bound(yyvsp[0].str);
		strcpy(yyval.str,"Delete where current...");
	}
    break;

  case 1388:
#line 6412 "fgl.yacc"
    {
		lex_printcomment("/*  delete 2 */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"Delete where ...");
	}
    break;

  case 1389:
#line 6417 "fgl.yacc"
    {
		strcpy(yyval.str,"Fetch");
		lex_printcomment("/*  fetch */\n");
	}
    break;

  case 1390:
#line 6421 "fgl.yacc"
    {
		lex_printcomment("/*  insert */\n");
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"insert");
	}
    break;

  case 1392:
#line 6427 "fgl.yacc"
    {
		print_do_select(yyvsp[0].sql_string);
		strcpy(yyval.str,"select");
	}
    break;

  case 1393:
#line 6431 "fgl.yacc"
    {
		print_exec_sql_bound(yyvsp[0].sql_string);
		strcpy(yyval.str,"update");
	}
    break;

  case 1394:
#line 6439 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1395:
#line 6442 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1396:
#line 6444 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1397:
#line 6449 "fgl.yacc"
    {sprintf(yyval.str," %s ",yyvsp[0].str);}
    break;

  case 1400:
#line 6456 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1404:
#line 6463 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1405:
#line 6466 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1406:
#line 6468 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1408:
#line 6474 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1410:
#line 6480 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1413:
#line 6490 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-5].str," ",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
}
    break;

  case 1414:
#line 6495 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1415:
#line 6497 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1417:
#line 6503 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1418:
#line 6506 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1420:
#line 6512 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("CHECK(",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1421:
#line 6520 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1422:
#line 6525 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1425:
#line 6535 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1427:
#line 6541 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1428:
#line 6547 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1429:
#line 6549 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1431:
#line 6555 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1432:
#line 6560 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1433:
#line 6563 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1434:
#line 6566 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1435:
#line 6574 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1436:
#line 6576 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1437:
#line 6587 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1438:
#line 6592 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1440:
#line 6596 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
	}
    break;

  case 1441:
#line 6598 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1442:
#line 6605 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1443:
#line 6608 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].sql_string,0);
	}
    break;

  case 1444:
#line 6614 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1445:
#line 6618 "fgl.yacc"
    {
		sprintf(yyval.str," %s ",yyvsp[0].str);
		yyval.sql_string=strdup(yyval.str);
	}
    break;

  case 1446:
#line 6622 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1447:
#line 6625 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].sql_string," ",yyvsp[0].str,0);
	}
    break;

  case 1448:
#line 6633 "fgl.yacc"
    {
yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1449:
#line 6640 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1452:
#line 6649 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1453:
#line 6655 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1454:
#line 6658 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1455:
#line 6669 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1456:
#line 6676 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("GROUP BY ",yyvsp[0].sql_string,0);
	}
    break;

  case 1457:
#line 6682 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1458:
#line 6685 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1459:
#line 6692 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("WHERE ",yyvsp[0].sql_string,0);
	}
    break;

  case 1460:
#line 6699 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1462:
#line 6706 "fgl.yacc"
    {
		sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1463:
#line 6712 "fgl.yacc"
    {sprintf(yyval.str," %s ", yyvsp[0].str);}
    break;

  case 1464:
#line 6713 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1465:
#line 6714 "fgl.yacc"
    {sprintf(yyval.str," %s (%s) ",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1467:
#line 6718 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1469:
#line 6723 "fgl.yacc"
    { sprintf(yyval.str," %s,%s ",yyvsp[-2].str,yyvsp[0].str);  }
    break;

  case 1470:
#line 6730 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1471:
#line 6735 "fgl.yacc"
    { yyval.sql_string=strdup("");}
    break;

  case 1472:
#line 6736 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1473:
#line 6739 "fgl.yacc"
    {
	yyval.sql_string=strdup("");
}
    break;

  case 1474:
#line 6742 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1475:
#line 6747 "fgl.yacc"
    {yyval.sql_string=strdup("");}
    break;

  case 1476:
#line 6748 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1477:
#line 6753 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1478:
#line 6756 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," OR ",yyvsp[0].sql_string,0);
	}
    break;

  case 1479:
#line 6762 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1480:
#line 6765 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1481:
#line 6771 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1482:
#line 6774 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1483:
#line 6780 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1484:
#line 6783 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1485:
#line 6790 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1486:
#line 6791 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].str," ",yyvsp[0].sql_string,0);}
    break;

  case 1487:
#line 6820 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1488:
#line 6822 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1492:
#line 6836 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1493:
#line 6839 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1494:
#line 6842 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string," NOT IN (",yyvsp[-1].str,")",0);
	}
    break;

  case 1495:
#line 6845 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1497:
#line 6853 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1498:
#line 6856 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1500:
#line 6862 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1502:
#line 6868 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NULL",0);
	}
    break;

  case 1503:
#line 6871 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,yyvsp[-1].str," IS NOT NULL",0);
	}
    break;

  case 1504:
#line 6874 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
	}
    break;

  case 1505:
#line 6877 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-5].sql_string,yyvsp[-4].str," BETWEEN ",yyvsp[-2].sql_string," AND ",yyvsp[0].sql_string,0);
	}
    break;

  case 1506:
#line 6880 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1507:
#line 6883 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].sql_string," ",yyvsp[-2].str," ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1508:
#line 6886 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-4].sql_string,yyvsp[-3].str," MATCHES ",yyvsp[-1].str,yyvsp[0].str,0);
	}
    break;

  case 1510:
#line 6893 "fgl.yacc"
    {strcpy(yyval.str,"!=");}
    break;

  case 1515:
#line 6900 "fgl.yacc"
    {strcpy(yyval.str,"<=");}
    break;

  case 1516:
#line 6901 "fgl.yacc"
    {strcpy(yyval.str,">=");}
    break;

  case 1517:
#line 6906 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1518:
#line 6909 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1519:
#line 6913 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1520:
#line 6919 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1521:
#line 6920 "fgl.yacc"
    {strcpy(yyval.str," ALL ");}
    break;

  case 1522:
#line 6921 "fgl.yacc"
    {strcpy(yyval.str," DISTINCT ");}
    break;

  case 1523:
#line 6922 "fgl.yacc"
    {
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str," DISTINCT ");
	}
    break;

  case 1528:
#line 6942 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1529:
#line 6947 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1530:
#line 6948 "fgl.yacc"
    {strcpy(yyval.str,"SERIAL");}
    break;

  case 1532:
#line 6951 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1536:
#line 6956 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1538:
#line 6959 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1540:
#line 6962 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s %s",yyvsp[-6].str,yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1544:
#line 6967 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1545:
#line 6969 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1546:
#line 6972 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1547:
#line 6973 "fgl.yacc"
    {
		sprintf(yyval.str,",%s",yyvsp[0].str);
}
    break;

  case 1548:
#line 6980 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1552:
#line 6985 "fgl.yacc"
    {sprintf(yyval.str," %s",yyvsp[0].str);}
    break;

  case 1556:
#line 7001 "fgl.yacc"
    { sprintf(yyval.str,"\\\"%s\\\"%s%s",strip_quotes(yyvsp[-2].str),yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1557:
#line 7002 "fgl.yacc"
    {
		sprintf(yyval.str," %s",strip_quotes(yyvsp[0].str));
		addmap("Use Table",yyval.str,curr_func,yylineno,infilename);
	}
    break;

  case 1558:
#line 7006 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str); addmap("Use Table",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1559:
#line 7007 "fgl.yacc"
    { sprintf(yyval.str," %s%s%s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); addmap("Use Table",yyval.str,curr_func,yylineno,infilename); }
    break;

  case 1561:
#line 7025 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1562:
#line 7026 "fgl.yacc"
    {sprintf(yyval.str,"[%s]",yyvsp[-1].str);}
    break;

  case 1563:
#line 7027 "fgl.yacc"
    {sprintf(yyval.str,"[%s,%s]",yyvsp[-3].str,yyvsp[-1].str);}
    break;

  case 1564:
#line 7031 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1565:
#line 7034 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].str);
	}
    break;

  case 1566:
#line 7040 "fgl.yacc"
    { 
addmap("Use Column",yyvsp[-1].str,curr_func,yylineno,infilename);
sprintf(yyval.str,"%s%s",yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1567:
#line 7045 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s%s",yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1568:
#line 7050 "fgl.yacc"
    {
sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);
addmap("Use Column",yyval.str,curr_func,yylineno,infilename);
}
    break;

  case 1570:
#line 7061 "fgl.yacc"
    {
	strcpy(yyval.str,convstrsql(yyvsp[0].str));
	debug("Set $<str>$ to %s\n",yyval.str);
}
    break;

  case 1574:
#line 7069 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1575:
#line 7071 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1576:
#line 7073 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1577:
#line 7075 "fgl.yacc"
    {sprintf(yyval.str," %s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1579:
#line 7080 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1580:
#line 7083 "fgl.yacc"
    {sprintf(yyval.str," %s %s ",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1581:
#line 7086 "fgl.yacc"
    {strcpy(yyval.str," YEAR TO SECOND ");}
    break;

  case 1582:
#line 7088 "fgl.yacc"
    {sprintf(yyval.str," %s %s %s",yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1583:
#line 7091 "fgl.yacc"
    {strcpy(yyval.str,"1,10");}
    break;

  case 1584:
#line 7093 "fgl.yacc"
    {sprintf(yyval.str," %s ,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1585:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1586:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"2");}
    break;

  case 1587:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"3");}
    break;

  case 1588:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1589:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"5");}
    break;

  case 1590:
#line 7096 "fgl.yacc"
    {strcpy(yyval.str,"6");}
    break;

  case 1591:
#line 7097 "fgl.yacc"
    {
sprintf(yyval.str,"%d",6+2);
}
    break;

  case 1592:
#line 7100 "fgl.yacc"
    {
sprintf(yyval.str,"%d",atoi(yyvsp[-1].str)+6);
}
    break;

  case 1593:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"4");}
    break;

  case 1594:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"7");}
    break;

  case 1595:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"10");}
    break;

  case 1596:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"13");}
    break;

  case 1597:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"16");}
    break;

  case 1598:
#line 7105 "fgl.yacc"
    {strcpy(yyval.str,"19");}
    break;

  case 1599:
#line 7107 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1600:
#line 7110 "fgl.yacc"
    {
strcpy(yyval.str,"25");
}
    break;

  case 1615:
#line 7119 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1616:
#line 7120 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1617:
#line 7124 "fgl.yacc"
    {
	print_flush_cursor(yyvsp[0].str);
		addmap("Flush Cursor",yyvsp[0].str,curr_func,yylineno,infilename);
print_undo_use(yyvsp[-2].str);
		}
    break;

  case 1618:
#line 7132 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1619:
#line 7132 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-5].str,0,0);
		addmap("Declare Cursor",yyvsp[-5].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-7].str);
	}
    break;

  case 1620:
#line 7137 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1621:
#line 7137 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,0); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1622:
#line 7143 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1623:
#line 7143 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-4].str,0,1); 
		addmap("Declare Cursor",yyvsp[-4].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-6].str);
	}
    break;

  case 1624:
#line 7148 "fgl.yacc"
    {insql=0;chk4var=0;}
    break;

  case 1625:
#line 7148 "fgl.yacc"
    {
		print_declare(yyvsp[0].str,yyvsp[-2].sql_string,yyvsp[-6].str,2,1); 
		addmap("Declare Cursor",yyvsp[-6].str,curr_func,yylineno,infilename);
		print_undo_use(yyvsp[-8].str);
	}
    break;

  case 1626:
#line 7155 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1627:
#line 7156 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1628:
#line 7157 "fgl.yacc"
    {strcpy(yyval.str,"1");}
    break;

  case 1632:
#line 7164 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1633:
#line 7165 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1634:
#line 7170 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1635:
#line 7173 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(print_curr_spec(1,yyvsp[0].sql_string),0);
	}
    break;

  case 1636:
#line 7179 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(print_curr_spec(2,yyvsp[0].str) ,0);
	}
    break;

  case 1637:
#line 7182 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1638:
#line 7191 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[-1].sql_string;
	if (atoi(yyvsp[0].str)) {
		printf("Warning SELECT ... FOR UPDATE when not declaring a cursor currently has no locking effect\n");
	}
}
    break;

  case 1639:
#line 7203 "fgl.yacc"
    {debug("Got select list...\n");}
    break;

  case 1640:
#line 7204 "fgl.yacc"
    { start_bind('i',0); }
    break;

  case 1641:
#line 7206 "fgl.yacc"
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

  case 1642:
#line 7220 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("push_char(\"", yyvsp[-4].str, " ",yyvsp[-3].str," ", yyvsp[-2].sql_string, " ",yyvsp[-1].sql_string, " ",yyvsp[0].sql_string, "\");",0);
	free(yyvsp[-2].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1643:
#line 7230 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	 }
    break;

  case 1644:
#line 7233 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1645:
#line 7241 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-5].str, " ",yyvsp[-4].str," ",yyvsp[-3].sql_string," ", yyvsp[-2].sql_string," ", yyvsp[-1].sql_string, " ",yyvsp[0].sql_string,0);
	free(yyvsp[-3].sql_string);
	free(yyvsp[-1].sql_string);
	free(yyvsp[0].sql_string);
}
    break;

  case 1646:
#line 7250 "fgl.yacc"
    {
		yyval.sql_string=strdup("");
		}
    break;

  case 1647:
#line 7253 "fgl.yacc"
    {
       lex_printcomment("/* UNION */");
	yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].sql_string,0);
       }
    break;

  case 1648:
#line 7257 "fgl.yacc"
    {
	yyval.sql_string=strdup(yyvsp[0].str);
}
    break;

  case 1649:
#line 7260 "fgl.yacc"
    { yyval.sql_string=make_sql_string(yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0); }
    break;

  case 1650:
#line 7261 "fgl.yacc"
    { 
	yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ",yyvsp[-1].str," ",yyvsp[0].str,0);
}
    break;

  case 1652:
#line 7270 "fgl.yacc"
    { start_bind('o',0);yyval.sql_string=make_sql_string("",0); }
    break;

  case 1653:
#line 7271 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(get_into_part(get_bind_cnt('o')),0 ); 

	}
    break;

  case 1654:
#line 7280 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-3].str," ",yyvsp[-2].str," ", yyvsp[-1].sql_string," ",yyvsp[0].sql_string,0);
		free(yyvsp[-1].sql_string);
		free(yyvsp[0].sql_string);

	}
    break;

  case 1655:
#line 7289 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string("(",yyvsp[-4].str," ",yyvsp[-3].str," ",yyvsp[-2].sql_string," ",yyvsp[-1].sql_string,")",0);
	}
    break;

  case 1656:
#line 7294 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1657:
#line 7295 "fgl.yacc"
    {strcpy(yyval.str,"ALL");}
    break;

  case 1658:
#line 7296 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");}
    break;

  case 1659:
#line 7297 "fgl.yacc"
    {strcpy(yyval.str,"DISTINCT");
		ansi_violation("Use DISTINCT not UNIQUE",0);
		strcpy(yyval.str,"DISTINCT ");

}
    break;

  case 1660:
#line 7305 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1661:
#line 7308 "fgl.yacc"
    { 
		yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
	}
    break;

  case 1662:
#line 7314 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1663:
#line 7317 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1664:
#line 7320 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);
	}
    break;

  case 1665:
#line 7326 "fgl.yacc"
    {
	yyval.sql_string=yyvsp[0].sql_string;
}
    break;

  case 1666:
#line 7335 "fgl.yacc"
    {
			if (strlen(current_upd_table)) {
				push_gen(UPDVAL,yyvsp[0].sql_string);
			}
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1667:
#line 7341 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1668:
#line 7344 "fgl.yacc"
    {
		yyval.sql_string=yyvsp[0].sql_string;
	}
    break;

  case 1669:
#line 7347 "fgl.yacc"
    {
		yyval.sql_string=strdup(yyvsp[0].str);
	}
    break;

  case 1670:
#line 7350 "fgl.yacc"
    {
		yyval.sql_string=make_sql_string(yyvsp[-2].str,".",yyvsp[0].str);
	}
    break;

  case 1671:
#line 7357 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"/",yyvsp[0].sql_string,0);}
    break;

  case 1672:
#line 7359 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-1].sql_string,yyvsp[0].str,0);}
    break;

  case 1673:
#line 7361 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"*",yyvsp[0].sql_string,0);}
    break;

  case 1674:
#line 7363 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"+",yyvsp[0].sql_string,0);}
    break;

  case 1675:
#line 7365 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,"-",yyvsp[0].sql_string,0);}
    break;

  case 1676:
#line 7367 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[0].str,0);}
    break;

  case 1677:
#line 7369 "fgl.yacc"
    {yyval.sql_string=make_sql_string("TRUE",0);}
    break;

  case 1678:
#line 7371 "fgl.yacc"
    {yyval.sql_string=make_sql_string("FALSE",0);}
    break;

  case 1679:
#line 7373 "fgl.yacc"
    {yyval.sql_string=make_sql_string("USER",0);}
    break;

  case 1680:
#line 7375 "fgl.yacc"
    {yyval.sql_string=make_sql_string("*",0);}
    break;

  case 1681:
#line 7377 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(*)",0);}
    break;

  case 1682:
#line 7379 "fgl.yacc"
    {yyval.sql_string=make_sql_string("AVERAGE(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1683:
#line 7381 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MAX(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1684:
#line 7383 "fgl.yacc"
    {yyval.sql_string=make_sql_string("MIN(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1685:
#line 7385 "fgl.yacc"
    {yyval.sql_string=make_sql_string("SUM(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1686:
#line 7387 "fgl.yacc"
    {yyval.sql_string=make_sql_string("COUNT(",yyvsp[-2].str,yyvsp[-1].sql_string,")",0);}
    break;

  case 1687:
#line 7389 "fgl.yacc"
    {yyval.sql_string=make_sql_string(yyvsp[-3].str,"(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1688:
#line 7391 "fgl.yacc"
    {yyval.sql_string=make_sql_string("DATE(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1689:
#line 7393 "fgl.yacc"
    {yyval.sql_string=make_sql_string("(",yyvsp[-1].sql_string,")",0);}
    break;

  case 1690:
#line 7395 "fgl.yacc"
    {yyval.sql_string=make_sql_string("EXTEND(",yyvsp[-1].str,")",0);}
    break;

  case 1691:
#line 7399 "fgl.yacc"
    {yyval.sql_string=yyvsp[0].sql_string;}
    break;

  case 1692:
#line 7400 "fgl.yacc"
    {
	yyval.sql_string=make_sql_string(yyvsp[-2].sql_string,",",yyvsp[0].sql_string,0);
}
    break;

  case 1695:
#line 7410 "fgl.yacc"
    {

print_unload(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].sql_string);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1696:
#line 7419 "fgl.yacc"
    {
print_load(yyvsp[-4].str,yyvsp[-3].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-6].str);
}
    break;

  case 1697:
#line 7423 "fgl.yacc"
    {
print_load_str(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);
print_undo_use(yyvsp[-4].str);
}
    break;

  case 1698:
#line 7430 "fgl.yacc"
    {strcpy(yyval.str,"\"|\"");}
    break;

  case 1699:
#line 7430 "fgl.yacc"
    {
strcpy(yyval.str,yyvsp[0].str);
}
    break;

  case 1701:
#line 7434 "fgl.yacc"
    {
if ((scan_variable(yyvsp[0].str)&15)!=0) {a4gl_yyerror("Variable must be of type char for a delimiter..");YYERROR;}
}
    break;

  case 1702:
#line 7439 "fgl.yacc"
    {strcpy(yyval.str,"0");}
    break;

  case 1703:
#line 7439 "fgl.yacc"
    {
sprintf(yyval.str,"%s,0",yyvsp[-1].str);
}
    break;

  case 1705:
#line 7443 "fgl.yacc"
    {
    sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);
}
    break;

  case 1706:
#line 7447 "fgl.yacc"
    {
     sprintf(yyval.str,"\"%s\"",yyvsp[0].str);
}
    break;

  case 1709:
#line 7456 "fgl.yacc"
    {strcpy(yyval.str,"");}
    break;

  case 1710:
#line 7456 "fgl.yacc"
    {
print_use_session(yyvsp[0].str);
strcpy(yyval.str,get_undo_use());
}
    break;

  case 1715:
#line 7475 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1716:
#line 7476 "fgl.yacc"
    { sprintf(yyval.str,"%s %s %s %s",yyvsp[-5].str,yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str); }
    break;

  case 1719:
#line 7484 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);
	}
    break;

  case 1720:
#line 7490 "fgl.yacc"
    {
		sprintf(yyval.str,"%s %s %s",
					yyvsp[-2].str,
					yyvsp[-1].str,
					yyvsp[0].str
					);
		}
    break;

  case 1723:
#line 7509 "fgl.yacc"
    {strcpy(yyval.str,"UNITS YEAR");}
    break;

  case 1724:
#line 7510 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MONTH"); }
    break;

  case 1725:
#line 7511 "fgl.yacc"
    {strcpy(yyval.str,"UNITS DAY"); }
    break;

  case 1726:
#line 7512 "fgl.yacc"
    {strcpy(yyval.str,"UNITS HOUR"); }
    break;

  case 1727:
#line 7513 "fgl.yacc"
    {strcpy(yyval.str,"UNITS MINUTE"); }
    break;

  case 1728:
#line 7514 "fgl.yacc"
    {strcpy(yyval.str,"UNITS SECOND"); }
    break;

  case 1729:
#line 7518 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1730:
#line 7519 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s %s",yyvsp[-4].str,yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1731:
#line 7520 "fgl.yacc"
    {sprintf(yyval.str,"%s %s %s %s",yyvsp[-3].str,yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1732:
#line 7524 "fgl.yacc"
    {
		sql_mode=1;
		start_bind('i',0);
		start_bind('o',0);
	}
    break;

  case 1733:
#line 7528 "fgl.yacc"
    {
			sql_mode=0;
			print_sql_block_cmd(yyvsp[-1].str);
	}
    break;

  case 1735:
#line 7537 "fgl.yacc"
    {sprintf(yyval.str,"%s %s",yyvsp[-1].str,yyvsp[0].str);}
    break;

  case 1737:
#line 7542 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1738:
#line 7543 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1739:
#line 7547 "fgl.yacc"
    {
		strcpy(yyval.str,yyvsp[0].sql_string);
	}
    break;

  case 1740:
#line 7553 "fgl.yacc"
    {
 		strcpy(yyval.str,get_into_part(get_bind_cnt('o')));
	}
    break;

  case 1741:
#line 7639 "fgl.yacc"
    {
	if (scan_variable(yyvsp[0].str)!=-1)
	{
		print_push_variable(yyvsp[0].str);
		strcpy(yyval.str,"?");
	}
}
    break;

  case 1742:
#line 7650 "fgl.yacc"
    {strcpy(yyval.str,yyvsp[0].str);}
    break;

  case 1746:
#line 7656 "fgl.yacc"
    {sprintf(yyval.str,"%s.%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1747:
#line 7657 "fgl.yacc"
    {sprintf(yyval.str,"\\\"%s\\\".%s.%s",strip_quotes(yyvsp[-4].str),yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1751:
#line 7667 "fgl.yacc"
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

  case 1752:
#line 7680 "fgl.yacc"
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

  case 1753:
#line 7730 "fgl.yacc"
    {set_whenever(WHEN_NOTFOUND|atoi(yyvsp[0].str),0);}
    break;

  case 1754:
#line 7732 "fgl.yacc"
    {set_whenever(WHEN_SQLERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1755:
#line 7734 "fgl.yacc"
    {set_whenever(WHEN_ANYERROR|atoi(yyvsp[0].str),0);}
    break;

  case 1756:
#line 7735 "fgl.yacc"
    {
 		set_whento("");
		set_whenever(WHEN_ERROR+WHEN_CONTINUE,0);
}
    break;

  case 1757:
#line 7740 "fgl.yacc"
    {
debug("Whenever error...%d %d",WHEN_ERROR,atoi(yyvsp[0].str));
set_whenever(WHEN_ERROR+atoi(yyvsp[0].str),0);
}
    break;

  case 1758:
#line 7745 "fgl.yacc"
    {set_whenever(WHEN_SQLWARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1759:
#line 7747 "fgl.yacc"
    {set_whenever(WHEN_WARNING|atoi(yyvsp[0].str),0);}
    break;

  case 1760:
#line 7749 "fgl.yacc"
    {set_whenever(WHEN_SUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1761:
#line 7751 "fgl.yacc"
    {set_whenever(WHEN_SQLSUCCESS|atoi(yyvsp[0].str),0);}
    break;

  case 1762:
#line 7754 "fgl.yacc"
    {
 set_whento("");
			sprintf(yyval.str,"%d",WHEN_CONTINUE); }
    break;

  case 1763:
#line 7758 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_GOTO);
 }
    break;

  case 1764:
#line 7763 "fgl.yacc"
    {
set_whento(yyvsp[0].str); 
sprintf(yyval.str,"%d",WHEN_GOTO);
}
    break;

  case 1765:
#line 7768 "fgl.yacc"
    { set_whento(""); 
sprintf(yyval.str,"%d",WHEN_STOP);
}
    break;

  case 1766:
#line 7772 "fgl.yacc"
    {
set_whento(yyvsp[0].str);
sprintf(yyval.str,"%d",WHEN_CALL);
}
    break;

  case 1768:
#line 7782 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1770:
#line 7797 "fgl.yacc"
    {
print_while_1();
push_blockcommand("WHILE");
}
    break;

  case 1771:
#line 7800 "fgl.yacc"
    {
print_while_2();
}
    break;

  case 1772:
#line 7804 "fgl.yacc"
    {
print_while_3();
pop_blockcommand("WHILE");
}
    break;

  case 1775:
#line 7823 "fgl.yacc"
    { strcpy(yyval.str,"0"); }
    break;

  case 1776:
#line 7824 "fgl.yacc"
    { strcpy(yyval.str,"1"); }
    break;

  case 1777:
#line 7827 "fgl.yacc"
    { print_clr_window("\"screen\""); }
    break;

  case 1778:
#line 7828 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1779:
#line 7829 "fgl.yacc"
    { print_clr_window(yyvsp[0].str); }
    break;

  case 1780:
#line 7830 "fgl.yacc"
    { print_clr_form(0,0,"0"); }
    break;

  case 1781:
#line 7831 "fgl.yacc"
    { print_clr_form(0,0,"1"); }
    break;

  case 1782:
#line 7832 "fgl.yacc"
    { print_clr_form(yyvsp[-2].str,yyvsp[-1].str,yyvsp[0].str); }
    break;

  case 1783:
#line 7833 "fgl.yacc"
    {
	print_clr_fields(yyvsp[-1].str,yyvsp[0].str);
}
    break;

  case 1784:
#line 7838 "fgl.yacc"
    {sprintf(yyval.str,"%s",yyvsp[0].str);}
    break;

  case 1785:
#line 7839 "fgl.yacc"
    {sprintf(yyval.str,"%s,%s",yyvsp[-2].str,yyvsp[0].str);}
    break;

  case 1786:
#line 7843 "fgl.yacc"
    {
	print_current_window("\"screen\"");
}
    break;

  case 1787:
#line 7847 "fgl.yacc"
    {
	print_current_window(yyvsp[0].str);
}
    break;

  case 1788:
#line 7851 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window");
reset_attrib(&form_attrib);
}
    break;

  case 1789:
#line 7855 "fgl.yacc"
    {
sprintf(yyval.str,"cr_window_form");
reset_attrib(&form_attrib);
}
    break;

  case 1790:
#line 7860 "fgl.yacc"
    {
	print_show_window(yyvsp[0].str);
	addmap("Show Window",yyvsp[0].str,curr_func,yylineno,infilename); 
}
    break;

  case 1791:
#line 7864 "fgl.yacc"
    {
	print_show_menu(yyvsp[-3].str,yyvsp[-1].str);
	addmap("Call Menuhandler",yyvsp[-1].str,curr_func,yylineno,infilename); 
}
    break;

  case 1792:
#line 7869 "fgl.yacc"
    {

print_def_mn_file();

}
    break;

  case 1794:
#line 7877 "fgl.yacc"
    {addmap("Use Menu",yyvsp[0].str,curr_func,yylineno,infilename); }
    break;

  case 1796:
#line 7883 "fgl.yacc"
    {
	print_hide_window(yyvsp[0].str);
}
    break;

  case 1797:
#line 7889 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,0);
}
    break;

  case 1798:
#line 7893 "fgl.yacc"
    {
print_move_window(yyvsp[-4].str,1);
}
    break;

  case 1803:
#line 7911 "fgl.yacc"
    {
chk4var=0;lex_printcomment("/* [Comm:%s] */\n",yyval.str);
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
	prchkerr(lastlineno,infilename);
	lastlineno=yylineno;
}
    break;

  case 1804:
#line 7918 "fgl.yacc"
    {
lex_printcomment("/* [COMM:%s] */\n",yyvsp[0].str);chk4var=0;
if (acl_getenv("INCLINES"))
lex_printc("{debug(\"Line %d %s:%s\");}",lastlineno,infilename,convstrsql(larr));
if (aubit_strcasecmp(yyval.str,"whenever")!=0) prchkerr(lastlineno,infilename);
lastlineno=yylineno;
}
    break;

  case 1805:
#line 7927 "fgl.yacc"
    {print_cmd_start();}
    break;

  case 1806:
#line 7927 "fgl.yacc"
    {print_cmd_end();}
    break;


    }

/* Line 991 of yacc.c.  */
#line 16412 "y.tab.c"

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


#line 8021 "fgl.yacc"

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



